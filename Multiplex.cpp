#include "Multiplex.h"
#include "stdHeader.h"

Multiplex::Multiplex()
{

}

Multiplex::~Multiplex()
{

}

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
  std::cout << " -------------- " << std::endl;
  std::cout << "|   Multiplex  |" << std::endl;
  std::cout << " -------------- " << std::endl;
  std::cout << "Input A: " << in_a << std::endl;
  std::cout << "Input B: " << in_b << std::endl;
  std::cout << "Selector: " << selector_bit << std::endl;
  std::cout << "Output: " << output << std::endl;

}
