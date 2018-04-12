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

        int control_write;

        Register(std::vector<s32> reg);
        ~Register();

        void write();
        void print_out();

};
#endif
