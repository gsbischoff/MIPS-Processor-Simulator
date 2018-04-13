#include "ALU.h"
#include "CPU.h"
#include "Multiplex.h"
#include "ControlUnit.h"
#include "Register.h"
#include "DataMemory.h"
#include "stdHeader.h"
#include "Parser.h"

CPU::CPU(std::vector<u32> inst, std::map<u32, u32> data_m, std::vector<u32> reg)
{
    PC = 0x400000;

    instruction_memory = inst;

    data_memory = DataMemory(data_m);

    reg_file = Register(reg);

    alu1 = ALU();
    alu2 = ALU();
    alu3 = ALU();

    multiplex1 = Multiplex();
    multiplex2 = Multiplex();
    multiplex3 = Multiplex();
    multiplex4 = Multiplex();
    multiplex5 = Multiplex();

    control_unit = ControlUnit();

    alu_control_unit = ALUControlUnit();
}

CPU::~CPU()
{

}

void CPU::print_out(){

    //print out ALUs
    alu1.print_out();       //main one
    alu2.print_out();       //branch
    alu3.print_out();       //add only for PC

    //print out Multiplexers
    multiplex1.print_out();
    multiplex2.print_out();
    multiplex3.print_out();
    multiplex4.print_out();
    multiplex5.print_out();

    //print out Control Unit
    control_unit.print_out();

    //print out ALU control unit
    alu_control_unit.print_out();

    //print Registers
    reg_file.print_out();

    //print data memory
    data_memory.print_out();

}

void CPU::execute(int PC)
{
    //get instruction from memory
    u32 instruction = 0;
    s32 temp = PC-0x400000;
    temp = temp >> 2;
    instruction = instruction_memory[temp];

    //increment PC
    alu3.in_a = PC;
    alu3.in_b = 4;
    alu3.control = 2;
    alu3.execute();


    //EXTRACT THE OPCODE TO THEN SET DATA PATH. The control unit only needs opcode (bits 31-26) to properly set entire datapath.
    //Then shift opcode right 26 bits
    int opcode = instruction & MASK_31_26;
    opcode = (opcode >> 26) & 0x3f;
    std::cout << "OPCODE: " << opcode << std::endl;
    //set Control UNit datapath lines
    control_unit.set_datapath(opcode);

    //** Properly grab bits of instruction **/
    int r1 = instruction & MASK_25_21;              //Instruction [25-21] for register 1
    r1 = r1 >> 21;
    int r2 = instruction & MASK_20_16;              //Instruction [20-16] for register 2
    r2 = r2 >> 16;

    int mux1_b = instruction & MASK_15_11;          //Instruction [20-16] for B input of mux1
    mux1_b = mux1_b >> 11;

    int func_field = instruction & MASK_5_0;        //integer representation of the instruction's function field..  for ALU control Unit ****

    int inst_25_0 = instruction & MASK_25_0;        //Instruction [25-0] needed for jumps
    inst_25_0 = inst_25_0 << 2;

    int PC_4_31_28 = alu3.result & MASK_31_28;        //get high order 4 bits from ALU 3 result

    int inst_15_0 = instruction & MASK_15_0;        //Instruction [15-0] needed for sign extend
    s32 inst_15_0_s_e = sign_extend(inst_15_0);     //sign extended version

    //shift left inst_25_0 and concatenate PC + 4 [31-28] to front
    inst_25_0 = inst_25_0 << 2;
    int jump_address = PC_4_31_28 | inst_25_0;

    //set alu control unit lines
    alu_control_unit.ALU_op_in = control_unit.ALUOp0 | (control_unit.ALUOp1 << 1);
    alu_control_unit.func_field_in = func_field;
    alu_control_unit.set_control_out();
    std::cout << "ALU OP IN: " << alu_control_unit.ALU_op_in << std::endl;
    std::cout << "ALU CONTROL UNIT OUTPUT: " << alu_control_unit.control_out << std::endl;
    std::cout << "FUNC FIELS: " << alu_control_unit.func_field_in << std::endl;
    //set up multiplex1
    //std::cout << "THIS IS THE CONTROL UNIT SELCTOR:::" << control_unit.RegDst<<std::endl;
    multiplex1.set_selector(control_unit.RegDst);
    multiplex1.in_a = r2;
    //std::cout << "THIS IS MUX1 A:::" << multiplex1.in_a <<std::endl;
    multiplex1.in_b = mux1_b;        //this atctually gets Instruction [15-11]
    //std::cout << "THIS IS MUX1 B:::" << multiplex1.in_b <<std::endl;
    multiplex1.set_output();
    //std::cout << "THIS IS MUX1 output:::" << multiplex1.output <<std::endl;

    //set up Register file
    reg_file.reg1 = reg_file.registers.at(r1);         //read data 1
    reg_file.reg2 = reg_file.registers.at(r2);         //read data 2
    reg_file.write_reg = multiplex1.output;             //write register set
    reg_file.control_write = control_unit.RegWrite;     //RegWrite

    //set up multiplex2
    multiplex2.set_selector(control_unit.ALUSrc);
    multiplex2.in_a = reg_file.reg2;                    //gets Read data 2 from register file
    multiplex2.in_b = inst_15_0_s_e;                    //gets Sign Extended Instruction [15-0]
    multiplex2.set_output();

    //set up ALU
    //std::cout << "ALU CONTROL LINE: " << alu_control_unit.control_out << std::endl;
    alu1.control = alu_control_unit.control_out;
    alu1.in_a = reg_file.reg1;
    //std::cout << "ALU A:" << alu1.in_a << std::endl;
    alu1.in_b = multiplex2.output;
    //std::cout << "ALU B:" << alu1.in_b << std::endl;
    alu1.execute();
    //std::cout << "RESULT: " << std::hex << alu1.result << std::endl;

    //set up ALU 2
    alu2.control = 2;
    alu2.in_a = alu3.result;
    alu2.in_b = inst_15_0_s_e << 2;
    alu2.execute();

    //set up Mulitplexor 5
    multiplex5.in_a = alu3.result;
    multiplex5.in_b = alu2.result;
    if(control_unit.Branch && alu1.zero_flag)
        multiplex5.set_selector(1);
    else
        multiplex5.set_selector(0);
    multiplex5.set_output();

    //set up multiplex 4
    multiplex4.in_a = multiplex5.output;
    multiplex4.in_b = jump_address;
    multiplex4.set_selector(control_unit.Jump);
    multiplex4.set_output();

    //set up data memory
    if(opcode == 35 || opcode == 43)         //if this is LW or SW
    {
        data_memory.control_write = control_unit.MemWrite;
        data_memory.control_read = control_unit.MemRead;
        data_memory.address = alu1.result;
        data_memory.write_data = reg_file.reg2;
        data_memory.execute();
        //std::cout << "read data expected 63322818::::" << data_memory.read_data << std::endl;
    }

    //set up multiplex3
    //std::cout << "MEMTO REG: " << control_unit.MemToReg << std::endl;
    multiplex3.set_selector(control_unit.MemToReg);
    multiplex3.in_a = alu1.result;                  //gets main ALU result
    multiplex3.in_b = data_memory.read_data;        //gets Data Memory Read-Data
    multiplex3.set_output();
    //std::cout << "Expected: 63322818 ::::" << data_memory.data[0x10000004+24] << std::endl;
    //std::cout << "MUX 3 output: " << multiplex3.output << std::endl;

    //handle Write Back if Necassary
    reg_file.write_data = multiplex3.output;
    if(reg_file.control_write == 1)
        reg_file.write();

    //increment PC
    PC = multiplex4.output;


}

s32 CPU::sign_extend(int a)
{
    s32 sign_extended = a;
    return sign_extended;
}

std::vector<int> CPU::instruction_convert()
{
    std::vector<int> v;
    return v;
}

