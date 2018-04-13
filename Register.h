#ifndef __REGISTER_H__
#define __REGISTER_H__

#include "stdHeader.h"

class Register
{

    public:

        std::vector<u32> registers;

        int reg1;
        int reg2;

        int write_reg;
        int write_data;

        int control_write;

        Register();
        Register(std::vector<u32> reg);
        ~Register();

        void write();
        void print_out();

};
#endif
