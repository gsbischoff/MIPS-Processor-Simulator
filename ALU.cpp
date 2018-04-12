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
    //print out everything
}

//set the output variable to the sum of A + B
void ALU::execute()
{
    if(control == 0)
    {
        //AND
        result = in_a & in_b;
    }
    else if(control == 1)
    {
        //OR
        result = in_a | in_b;
    }

    else if(control == 2)  //add
    {
        result = in_a + in_b;
        if (result == 0)
            zero_flag = true;
    }
    else if(control == 6)  //subtract
    {
        result = in_a - in_b;
        if(result == 0)
            zero_flag = true;
    }
    else
    {
        //SET ON LESS THAN
    }


}
