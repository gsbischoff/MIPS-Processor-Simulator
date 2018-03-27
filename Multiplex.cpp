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