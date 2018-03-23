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

int CPU::shift_left(int a)
{
    return a << 2;
}

int CPU::sign_extend(int a)
{
    return std::static_cast<int32_t>(a);
}
