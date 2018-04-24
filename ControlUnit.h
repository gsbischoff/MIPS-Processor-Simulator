#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__
#include <string>

class ControlUnit
{
    public:

        //all the control lines
        int RegDst;
        int RegWrite;
        int ALUSrc;
        int ALUOp0;
        int ALUOp1;
        int MemRead;
        int MemWrite;
        int MemToReg;
        int Branch;
        int Jump;

        int opcode;

        ControlUnit();
        ~ControlUnit();

        void print_out();           //print out all the values in the unit
        void set_datapath();        //update all the instance variables to set the data path
};
#endif
