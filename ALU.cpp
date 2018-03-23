//ALU constructor
#include "ALU.h"

ALU::ALU()
{
    zero_flag = false;
    result = 0;
    in_a = 0;
    in_b = 0;
    control = 0;
//needs to take an opcode
    //adding does not necassarily just add
}

void ALU::print_out()
{

}

//set the output variable to the sum of A + B
void ALU::add()
{
    result = in_a + in_b;
    if (result == 0)
        zero_flag = true;
}

void ALU::subtract()
{
    result = in_a - in_b;
    if(result == 0)
        zero_flag = true;
}

bool ALU::or()
{
    return false;
}
