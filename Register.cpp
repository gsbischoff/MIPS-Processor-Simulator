#include <"Register.h">

Register::Register(std::vector<s32> reg)
{
  registers = reg;
}

Register::~Register() {}

void Register::print_out()
{
  std::cout << " -------------- " << std::endl;
  std::cout << "| Register File |" << std::endl;
  std::cout << " -------------- " << std::endl;
  //std::cout << "Input A: " << in_a << std::endl;
  //std::cout << "Input B: " << in_b << std::endl;
  //std::cout << "Selector: " << selectorBit << std::endl;
  //std::cout << "Output: " << output << std::endl;

}
