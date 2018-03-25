#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

class ControlUnit
{
    public:

        //all the control lines
        int RegDst;
        int RegWrite;
        int ALUSrc;
        int ALUOp;
        int PCSrc;
        int MemRead;
        int MemWrite;
        int MemToReg;
        int Branch;

        ControlUnit();
        ~ControlUnit();

        void set_datapath(); //update all the instance variables to set the data path... will be called once per instruction.
};
#endif
