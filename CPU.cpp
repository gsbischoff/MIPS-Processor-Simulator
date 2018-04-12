#include "ALU.h"
#include "CPU.h"
#include "Multiplex.h"
#include "ControlUnit.h"

CPU::CPU(std::vector<u32> inst, std::vector<int> data, std::vector<s32> reg)
{
    instruction_memory = inst;
    data_memory = data;

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
    alu1.print_out();
    alu2.print_out();
    alu3.print_out();

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

}

void CPU::execute(int PC)
{
    //get instruction from memory
    int instruction;

    //EXTRACT THE OPCODE TO THEN SET DATA PATH. The control unit only needs opcode (bits 31-26) to properly set entire datapath.
    //Then shift opcode right 26 bits
    int opcode = instruction & MASK_31_26;
    opcode = opcode >> 26;

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

    int inst_15_0 = instruction & MASK_15_0;        //Instruction [15-0] needed for sign extend
    //NEED TO SIGN EXTEND THIS
    //inst_15_0 = inst_15_0.sign_extend();

    //set alu control unit lines
    alu_control_unit.ALU_op_in = control_unit.ALUOp0 + control_unit.ALUOp1;
    alu_control_unit.func_field_in = func_field;
    alu_control_unit.set_control_out();

    //set up multiplex1
    multiplex1.set_selector(control_unit.RegDst);
    multiplex1.in_a = r2;
    multiplex1.in_b = mux1_b;        //this atctually gets Instruction [15-11]
    multiplex1.set_output();

    //set up Register file
    reg_file.reg1 = reg_file.registers.get(r1);         //read data 1
    reg_file.reg2 = reg_file.registers.get(r2);         //read data 2

    //set up multiplex2
    multiplex2.set_selector(control_unit.ALUSrc);
    multiplex2.in_a = 1;        //this atctually gets Read data 2 from register file
    multiplex2.in_b = 2;        //this atctually gets Sign Extended Instruction [5-0]
    multiplex2.set_output();

    //set up multiplex3
    multiplex3.set_selector(control_unit.MemToReg);
    multiplex3.in_a = 1;        //this atctually gets Data Memory Read-Data
    multiplex3.in_b = 2;        //this atctually gets main ALU result
    multiplex3.set_output();

    //set up multiplex4
    multiplex4.set_selector(1); //this actually gets the result of ANDing the Zero flag of main ALU and Branch line from control unit
    multiplex4.in_a = 1;        //this actually gets ... look at the picture
    multiplex4.in_b = 2;        //this actually gets ... look at the picture
    multiplex4.set_output();


    //increment PC



}

int CPU::sign_extend(int a)
{
//    return static_cast<int32_t>(a);
}

vector<int> CPU::instruction_convert()
{
}

