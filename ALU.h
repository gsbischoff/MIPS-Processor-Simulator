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

        void execute();             //looks at control line and decides whether to add, subtract, AND, OR, or SLT based on the input lines.
        void print_out();           //print the instance variable values

};
#endif
