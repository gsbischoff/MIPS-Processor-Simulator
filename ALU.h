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

        void print_out();
        void add();
        void subtract();
        bool and();
        bool or();
        int  slt();
        void div();
        void mult();


};
#endif
