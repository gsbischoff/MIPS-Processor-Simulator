//ALU constructor
#include "ALU.h"
#include "stdHeader.h"

// -----
//  ALU::ALU
//	  Constructs an instance of an ALU and
//		initialized its control lines
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

// -----
//  ALU::print_out
//	  Prints out the input lines and output
//		lines to an ALU instance in hex
void ALU::print_out()
{
    std::cout << " ------------- " << std::endl;
    std::cout << "|    ALU " << number << "    |" << std::endl;
    std::cout << " ------------- " << std::endl;
    printf("Input A: 0x%x\n", in_a);
    printf("Input B: 0x%x\n", in_b);
    printf("Control code: 0x%x\n", in_b);
    printf("Result: 0x%x\n", result);
    printf("Zero flag: 0x%x\n\n", in_b);
}

// -----
//  ALU::execute
//	  Sets the output line, result, to the result of the arithmetic
//		operation based on the control line value
void ALU::execute()
{
    if(control == 0)
    {
        // Bitwise AND operation
        result = in_a & in_b;
    }
    else if(control == 1)
    {
        // Bitwise OR
        result = in_a | in_b;
    }

    else if(control == 2)
    {
		// Arithmetic add
        result = in_a + in_b;
        if (result == 0)
            zero_flag = true;
    }
    else if(control == 6)
    {
		// Subtraction, set the zero flag if 0
        result = in_a - in_b;
        if(result == 0)
            zero_flag = true;
    }
    else
    {
        // SET ON LESS THAN
        result = in_a < in_b;
    }
}
