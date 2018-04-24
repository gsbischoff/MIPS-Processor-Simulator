#include "ALU.h"
#include "stdHeader.h"

//////////////////////////////////////////////////////////
//ALU constructor with int n (which is the ALU number) passed in
//sets the instance variables to default state
//////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////
//ALU destructor
//////////////////////////////////////////////////////////

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
    //////////////////////////////////////////////////////////
    //Prints the inputs and outputs in hexadecimal
    //////////////////////////////////////////////////////////
    printf("Input A: 0x%x\n", in_a);
    printf("Input B: 0x%x\n", in_b);
    printf("Control code: 0x%x\n", in_b);
    printf("Result: 0x%x\n", result);
    printf("Zero flag: 0x%x\n\n", in_b);
}


//////////////////////////////////////////////////////////
//Depending on the value of the control code, will perform specificed operations
//////////////////////////////////////////////////////////

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
        //ADD
        result = in_a + in_b;
        if (result == 0)
            zero_flag = true;
    }
    else if(control == 6)
    {
		// SUBTRACTION, set the zero flag if 0
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
