#include "ALU.h"
#include "CPU.h"
#include "Multiplex.h"
#include "ControlUnit.h"

CPU::CPU(std::vector<int> inst, std::vector<int> data, int[] reg)
{
    instruction_memory = inst;
    data_memory = data;
    register_file = reg;

    alu1 = new ALU();
    alu2 = new ALU();
    alu3 = new ALU();

    multiplex1 = new Multiplex();
    multiplex2 = new Multiplex();
    multiplex3 = new Multiplex();
    multiplex4 = new Multiplex();
    multiplex5 = new Multiplex();

    control_unit = new ControlUnit();

    alu_control_unit = new ALUControlUnit();
}

CPU::~CPU()
{
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
}

void CPU::print_out(){

    //print out ALUs
    alu1.print_out();
    alu2.print_out();
    alu3.print_out();

    //print out Multiplexors
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

void CPU::execute(std::string instruction)
{

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
    return std::static_cast<int32_t>(a);
}
