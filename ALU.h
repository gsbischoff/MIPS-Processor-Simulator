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
        void add(int a, int b);
        void subtract(int a, int b);
        bool and(int a, int b);
        bool or(int a, int b);
        int slt(int a, int b);


}
#endif
