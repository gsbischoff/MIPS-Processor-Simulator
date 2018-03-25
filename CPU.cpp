#include "ALU.h"
#include "Multiplex.h"

CPU::CPU(std::vector<int> inst, std::vector<int> data, int[] reg)
{
    instruction_memory = inst;
    data_memory = data;
    register_file = reg;

    alu1 = new ALU();
    alu2 = new ALU();
    alu3 = new ALU();

    multiplex1 = new Multiplexor();
    multiplex2 = new Multiplexor();
    multiplex3 = new Multiplexor();
    multiplex4 = new Multiplexor();
    multiplex5 = new Multiplexor();

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

void CPU::execute(std::string instruction)
{
    control_unit.set_datapath(instruction);
}

int CPU::shift_left(int a)
{
    return a << 2;
}

int CPU::sign_extend(int a)
{
    return std::static_cast<int32_t>(a);
}
