#include "ALU.h"
#include "CPU.h"
#include "Multiplex.h"
#include "ControlUnit.h"

CPU::CPU(std::vector<int> inst, std::vector<int> data, int reg[])
{
    instruction_memory = inst;
    data_memory = data;

    //copy over the register file
    for(int i=0; i<32; i++)
    {
        register_file[i] = reg[i];
    }

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

    //EXTRACT THE OPCODE TO THEN SET DATA PATH. The control unit only needs opcode (bits 31-26) to properly set entire datapath.
    std::string opcode;

    //set Control UNit datapath lines
    control_unit.set_datapath(opcode);

    //set alu control unit lines
    alu_control_unit.ALU_op_in = control_unit.ALUOp0 + control_unit.ALUOp1;
    alu_control_unit.func_field_in = 1; // This needs to get the integer representation of the instruction's function field ****
    alu_control_unit.set_control_out();

    //set up multiplex1
    multiplex1.set_selector(control_unit.RegDst);
    multiplex1.in_a = 1;        //this atctually gets Instruction [20-16]
    multiplex1.in_b = 2;        //this atctually gets Instruction [15-11]
    multiplex1.set_output();

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

int CPU::shift_left(int a)
{
    return a << 2;
}

int CPU::sign_extend(int a)
{
    return static_cast<int32_t>(a);
}
