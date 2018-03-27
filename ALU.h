#ifndef __ALU_H__
#define __ALU_H__

class ALU
{

    public:

        bool zero_flag;
        int result;
        int in_a;
        int in_b;
        int control;

        ALU()
        ~ALU();

        void print_out();           //print the instance variable values
        void add();                 //add the two values on the input lines. set result variable.
        void subtract();            //subtract the two values on the input lines. set result variable
        bool and();                 //logical and of the two inputs
        bool or();                  //logical or of the two input lines
        int  slt();                 //set a flag if in_a < in_b
        void div();
        void mult();


};
#endif
