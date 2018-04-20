#ifndef __CPU_H__
#define __CPU_H__

#include "ALU.h"
#include "Multiplex.h"
#include "Register.h"
#include "ControlUnit.h"
#include "ALUControlUnit.h"
#include "DataMemory.h"
#include "stdHeader.h"

class CPU
{

    public:

        int PC;

        std::vector<std::string> string_instructions;
        std::vector<u32> instruction_memory;

        DataMemory data_memory;

        Register reg_file;

        ALU alu1;
        ALU alu2;
        ALU alu3;

        Multiplex multiplex1;
        Multiplex multiplex2;
        Multiplex multiplex3;
        Multiplex multiplex4;
        Multiplex multiplex5;

        ControlUnit control_unit;
        ALUControlUnit alu_control_unit;

        CPU(std::vector<u32> inst, std::map<u32, u32> data, std::vector<u32> reg);
        ~CPU();

        void print_out();                       //prints out all of the values on the CPU components
        int shift_left(int a);                  //shifts the input left two bits
        int sign_extend(int a);                 //sign extends to 32 bits the input
        int execute(int PC, int exit);              //takes the PC and exectues the corresponding instruction stored in that memory
	    std::vector<int> instruction_convert();		//Takes the instruction memory vector and converts it to a binary vector

};
#endif
