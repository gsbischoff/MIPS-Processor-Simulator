#ifndef __ALUCONTROLUNIT_H__
#define __ALUCONTROLUNIT_H__

class ALUControlUnit
{

    public:

        int control_out;    //4-bit signal that directly contrls the ALU, one of the 4-bit combinations in table p. 259
        int func_field_in;  //function field of the instruction
        int ALU_op_in;

        ALUControlUnit();
        ~ALUControlUnit();

        void set_control_out();     //sets the control output data line.



};
#endif
