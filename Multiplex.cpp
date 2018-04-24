#include "Multiplex.h"
#include "stdHeader.h"

Multiplex::Multiplex(int n)
{
  number = n;
}

Multiplex::~Multiplex() {}

Multiplex::Multiplex() {}

void Multiplex::set_selector(int s)
{
	selector_bit = s;
}

void Multiplex::set_output()
{
	if(selector_bit == 0)
		output = in_a;
	else
		output = in_b;
}

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
