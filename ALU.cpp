//ALU constructor
#include "ALU.h"
#include "stdHeader.h"

ALU::ALU(int n)
{
    zero_flag = false;
    result = 0;
    in_a = 0;
    in_b = 0;
    control = 0;
    number = n;
}

ALU::ALU() {}

ALU::~ALU() {}

void ALU::print_out()
{
    //print out everything
    std::cout << " ------------- " << std::endl;
    std::cout << "|    ALU " << number << "    |" << std::endl;
    std::cout << " ------------- " << std::endl;
    std::cout << "Input A: " << in_a << std::endl;
    std::cout << "Input B: " << in_b << std::endl;
    std::cout << "Control Code: " << control << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero_flag << std::endl;
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
        result = in_a < in_b;
    }


}
