#include "Multiplex.h"
#include "stdHeader.h"


///////////////////////////////////
//
//  Multiplex constructor. Input n
//  is just a label for a specific
//  mux object.
//
//////////////////////////////////
Multiplex::Multiplex(int n)
{
  number = n;
}

///////////////////////////////////
//  Default constructor.
//////////////////////////////////
Multiplex::~Multiplex() {}

///////////////////////////////////
//  Default destructor.
//////////////////////////////////
Multiplex::Multiplex() {}

/////////////////////////////////////
// Setter method for the selector bit
// of multiplex.
/////////////////////////////////////
void Multiplex::set_selector(int s)
{
	selector_bit = s;
}

/////////////////////////////////////
// Sets the output of the multiplex
// based on the selector bit.
/////////////////////////////////////
void Multiplex::set_output()
{
	if(selector_bit == 0)
		output = in_a;
	else
		output = in_b;
}

///////////////////////////////////
//
//  Print out all the control lines
//  and the opcode.
//
//////////////////////////////////
void Multiplex::print_out()
{
  std::cout << " ------------- " << std::endl;
  std::cout << "| Multiplex " << number << " |" << std::endl;
  std::cout << " ------------- " << std::endl;
  std::cout << "Input A: 0x" << in_a << std::endl;
  std::cout << "Input B: 0x" << in_b << std::endl;
  std::cout << "Selector: 0x" << selector_bit << std::endl;
  printf("Output: 0x%x\n\n", output);

}
