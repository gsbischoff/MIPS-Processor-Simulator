#include "ALUControlUnit.h"

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
    else if (ALU_op_in == 1) //ALUop = 01
    {
        control_out = 6; //subtract, 0110
    }
    else //ALUOp = 10
    {
        if(func_field_in == 32) //function code = 100000
            control_out = 2;     //add, 0010
        else if(func_field_in == 34)  //function code = 100010
            control_out = 6;    //subtract, 0110
        else if(func_field_in == 36)  //function code = 100100
            control_out = 0;    //AND, 0000
        else if(func_field_in == 37)  //function code = 100101
            control_out = 1;    //OR, 0001
        else
            control_out = 7;    //set on less than, 0111
    }
}

void print_out(){
    
}