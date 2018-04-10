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
    /*
    delete alu1;
    delete alu2;
    delete alu3;

    delete multiplex1;
    delete multiplex2;
    delete multiplex3;
    delete multiplex4;
    delete multiplex5;

    delete control_unit;

    delete alu_control_unit;
    */
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
    control_unit.set_datapath(opcode);

    //increment PC



}

int CPU::shift_left(int a)
{
    return a << 2;
}

int CPU::sign_extend(int a)
{
//    return static_cast<int32_t>(a);
}

vector<int> CPU::instruction_convert()
{
}

