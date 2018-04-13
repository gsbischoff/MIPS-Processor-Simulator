#include "ALUControlUnit.h"
#include <iostream>

ALUControlUnit::ALUControlUnit()
{

}

ALUControlUnit::~ALUControlUnit()
{

}

void ALUControlUnit::set_control_out()
{
    if(ALU_op_in == 0) //ALUOp = 00
    {
        control_out = 2; //add, 0010
    }
    else if ((ALU_op_in & 0x1) == 1) //ALUop = 01
    {
        control_out = 6; //subtract, 0110
    }
    else //ALUOp = 10
    {
        if((func_field_in & 0xF ) == 0x0)
            control_out = 2;     //add, 0010
        else if((func_field_in & 0xF) == 0x2)
            control_out = 6;    //subtract, 0110
        else if((func_field_in & 0xF) == 0x4)
            control_out = 0;    //AND, 0000
        else if((func_field_in & 0xF) == 0x5)
            control_out = 1;    //OR, 0001
        else
            control_out = 7;    //set on less than, 0111
    }
}
void ALUControlUnit::print_out()
{
  std::cout << " ----------------" << std::endl;
  std::cout << "| ALUControlUnit |" << std::endl;
  std::cout << " ----------------" << std::endl;
  std::cout << "Output: " << control_out << std::endl;
  std::cout << "Function Field: " << func_field_in << std::endl;
  std::cout << "ALU Operation Line: " << ALU_op_in << std::endl;


}
