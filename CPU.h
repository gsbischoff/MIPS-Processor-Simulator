#ifndef __CPU_H__
#define __CPU_H__

#include "ALU.h"
#include "Multiplexor.h"
#include "ControlUnit.h"
#include "ALUControlUnit.h"

class CPU
{

    public:

        int[] register_file;
        int PC;
        std::vector<int> instruction_memory;
        std::vector<int> data_memory;

        ALU alu1;
        ALU alu2;
        ALU alu3;

        Multiplexor multiplex1;
        Multiplexor multiplex2;
        Multiplexor multiplex3;
        Multiplexor multiplex4;
        Multiplexor multiplex5;

        ControlUnit control_unit;
        ALUControlUnit alu_control_unit;

        CPU(std::vector<int> inst, std::vector<int> data, int[] reg);
        ~CPU();

        void shift_left(int a);
        void sign_extend(int a);

}
#endif
