#ifndef __REGISTER_H__
#define __REGISTER_H__

class Register
{

    public:

        std::vector<s32> registers;

        int reg1;
        int reg2;

        int write_reg;
        int write_data;

        int result;
        int in_a;
        int in_b;
        int control;

        Register(std::vector<s32> reg);
        ~Register();

        void write();

};
#endif
