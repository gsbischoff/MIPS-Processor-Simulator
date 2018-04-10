#ifndef __REGISTER_H__
#define __REGISTER_H__

class Register
{

    public:

        std::vector<s32> registers;

        int reg1;
        int reg2;

        int result;
        int in_a;
        int in_b;
        int control;

        ALU();
        ~ALU();

        void execute();             //looks at control line and decides whether to add, subtract, AND, OR, or SLT based on the input lines.
        void print_out();           //print the instance variable values

};
#endif
