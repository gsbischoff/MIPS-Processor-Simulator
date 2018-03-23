//ALU constructor
#include "ALU.h"

ALU::ALU()
{
    zero_flag = false;
    result = 0;
    in_a = 0;
    in_b = 0;
    control = 0;

}

void ALU::print_out()
{

}

//set the output variable to the sum of A + B
void ALU::add()
{
    this.result = in_a + in_b;
    if (result == 0)
        zero_flag = true;
}

void ALU::subtract()
{
    this.result = in_a - in_b;
    if(result == 0)
        zero_flag = true;
}

bool ALU::or()
{
    return false;
}
