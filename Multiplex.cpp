#include <"Multiplex.h">

Multiplex::Multiplex()
{

}

Multiplex::~Multiplex()
{

}

void Multiplex::setSelector(int s)
{
	selectorBit = s;
}

void Multiplex::setOutput()
{
	if(selectorBit == 0)
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
  std::cout << "Selector: " << selectorBit << std::endl;
  std::cout << "Output: " << output << std::endl;

}
