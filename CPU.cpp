#include "ALU.h"
#include "CPU.h"
#include "Multiplex.h"
#include "ControlUnit.h"
#include "Register.h"
#include "DataMemory.h"
#include "stdHeader.h"
#include "Parser.h"

// -----
//  CPU::CPU
//	  Constructs an instance of a CPU with its components,
//		memory, and initializes the PC
CPU::CPU(std::vector<u32> inst, 
		 std::map<u32, u32> data_m, 
		 std::vector<u32> reg, 
		 std::vector<std::string> str)
{
    PC = 0x400000;	// PC starts at this value

	// Set data and instruction memory fields to input
    instruction_memory = inst;
    string_instructions = str;
    data_memory = DataMemory(data_m);

    reg_file = Register(reg);

    alu1 = ALU(1);
    alu2 = ALU(2);
    alu3 = ALU(3);

    multiplex1 = Multiplex(1);
    multiplex2 = Multiplex(2);
    multiplex3 = Multiplex(3);
    multiplex4 = Multiplex(4);
    multiplex5 = Multiplex(5);

    control_unit = ControlUnit();

    alu_control_unit = ALUControlUnit();
}

CPU::~CPU() {}

// -----
//  CPU::print_out
//	  Prints out the values from the control lines to all of the components 
//		and contents of the data and instruction memory and register file
void CPU::print_out()
{
    // Print out ALUs
    alu1.print_out();       //main one
    alu2.print_out();       //branch
    alu3.print_out();       //add only for PC

    // Print out Multiplexers
    multiplex1.print_out();
    multiplex2.print_out();
    multiplex3.print_out();
    multiplex4.print_out();
    multiplex5.print_out();

    // Print out Control Unit
    control_unit.print_out();

    // Print out ALU control unit
    alu_control_unit.print_out();

    // Print Registers
    reg_file.print_out();

    // Print data memory
    data_memory.print_out();

    // Print instruction memory
    std::cout << " -------------------- " << std::endl;
    std::cout << "| Instruction Memory |" << std::endl;
    std::cout << " -------------------- " << std::endl;
    for(unsigned int i = 0; i < instruction_memory.size(); ++i)
        printf("0x%08x: %s\n", (i * 4) + 0x400000, string_instructions[i].c_str());

    std::cout << "\n\n";
}

// -----
//  CPU::execute
//	  Executes the instruction at the current PC
//		and increments the PC
int CPU::execute(int exit)
{
    // Get the instruction from memory at PC (turn int oarray index)
    u32 instruction = 0;
    s32 temp = PC - 0x400000;
    temp = temp >> 2;

    // If there is no instruction left, end execution
    if(temp >= exit)
        return(0);

    instruction = instruction_memory[temp];
    printf("PC: 0x%08x\t", PC);
	std::cout << "Instruction: " << string_instructions[temp] << std::endl;

    // Increment PC
    alu3.in_a = PC;
    alu3.in_b = 4;
    alu3.control = 2;
    alu3.execute();

    // EXTRACT THE OPCODE TO THEN SET DATA PATH. 
	//	The control unit only needs opcode (bits 31-26)
	//	to properly set entire datapath. Then shift
	//			opcode right 26 bits.
    int opcode = instruction & MASK_31_26;
    opcode = (opcode >> 26) & 0x3f;
    control_unit.opcode = opcode;

    // Set Control Unit's datapath lines
    control_unit.set_datapath();

    // Grab the bits of the instruction
    int r1 = instruction & MASK_25_21;              //Instruction [25-21] for register 1
    r1 = r1 >> 21;
    int r2 = instruction & MASK_20_16;	//Instruction [20-16] for register 2
    r2 = r2 >> 16;

/*	Formated instr = { .u = instruction };
	control_unit.set_datapath(instr.opcode);
	r1 = instr.rs;
	r2 = instr.rt;*/

	// Instruction [20-16] for B input of mux1
    int mux1_b = instruction & MASK_15_11;          
    mux1_b = mux1_b >> 11;

	// Integer representation of the instruction's function field..  for ALU control Unit
    int func_field = instruction & MASK_5_0;        
    int inst_25_0 = instruction & MASK_25_0;	//Instruction [25-0] needed for jumps

	// Get high order 4 bits from ALU 3 result
    int PC_4_31_28 = alu3.result & MASK_31_28;

    s16 inst_15_0 = instruction & MASK_15_0;	// Instruction [15-0] needed for sign extend
    s32 inst_15_0_s_e = sign_extend(inst_15_0);	// Sign extend version

    // Shift left inst_25_0 and concatenate PC + 4 [31-28] to front
    inst_25_0 = inst_25_0 << 2;
    int jump_address = PC_4_31_28 | inst_25_0;

    // Set alu control unit lines
    alu_control_unit.ALU_op_in = control_unit.ALUOp0 | (control_unit.ALUOp1 << 1);
    alu_control_unit.func_field_in = func_field;
    alu_control_unit.set_control_out();

    // Set up multiplex1
    multiplex1.set_selector(control_unit.RegDst);
    multiplex1.in_a = r2;
	
    multiplex1.in_b = mux1_b;        // This gets the Write Register [15-11]
	
    multiplex1.set_output();

    // Set up Register file
    reg_file.reg1 = reg_file.registers.at(r1);		// Read data 1
    reg_file.reg2 = reg_file.registers.at(r2);		// Read data 2
    reg_file.write_reg = multiplex1.output;			// Write register set
    reg_file.control_write = control_unit.RegWrite;	// RegWrite

    // Set up multiplex2
    multiplex2.set_selector(control_unit.ALUSrc);
    multiplex2.in_a = reg_file.reg2;		// Gets Read data 2 from register file
    multiplex2.in_b = inst_15_0_s_e;		// Gets Sign Extended Instruction [15-0]
    multiplex2.set_output();

    // Set up ALU
    alu1.control = alu_control_unit.control_out;
    alu1.in_a = reg_file.reg1;
    alu1.in_b = multiplex2.output;
    alu1.execute();

    // Set up ALU 2
    alu2.control = 2;
    alu2.in_a = alu3.result;
    alu2.in_b = inst_15_0_s_e << 2;
    alu2.execute();

    // Set up mulitplex 5
    multiplex5.in_a = alu3.result;
    multiplex5.in_b = alu2.result;
    if(control_unit.Branch && alu1.zero_flag)
        multiplex5.set_selector(1);
    else
        multiplex5.set_selector(0);
    multiplex5.set_output();

    // Set up multiplex 4
    multiplex4.in_a = multiplex5.output;
    multiplex4.in_b = jump_address;
    multiplex4.set_selector(control_unit.Jump);
    multiplex4.set_output();

    // Set up data memory
    if(opcode == 35 || opcode == 43)	// If instruction is LW or SW
    {
        data_memory.control_write = control_unit.MemWrite;
        data_memory.control_read = control_unit.MemRead;
        data_memory.address = alu1.result;
        data_memory.write_data = reg_file.reg2;
        data_memory.execute();
    }

    // Set up multiplex3
    multiplex3.set_selector(control_unit.MemToReg);
    multiplex3.in_a = alu1.result;                  // Gets main ALU result
    multiplex3.in_b = data_memory.read_data;        // Gets Data Memory Read-Data
    multiplex3.set_output();

    // Handle Write Back if necessary
    reg_file.write_data = multiplex3.output;
    if(reg_file.control_write == 1)
    {
        reg_file.write();
    }

    // Increment PC
    PC = multiplex4.output;

    // Reset zero flag
    alu1.zero_flag = 0;

    return 1;
}

s32 CPU::sign_extend(s16 a)
{
    s32 sign_extended = ((s32)a);
    return sign_extended;
}

std::vector<int> CPU::instruction_convert()
{
    std::vector<int> v;
    return v;
}

