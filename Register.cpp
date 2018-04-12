#include <"Register.h">

Register::Register(std::vector<s32> reg)
{
  registers = reg;
}

Register::~Register() {}



void Register::write()
{
  registers[write_register] = write_data;
}




void Register::print_out()
{
  std::cout << " -------------- " << std::endl;
  std::cout << "| Register File |" << std::endl;
  std::cout << " -------------- " << std::endl;
  std::cout << "Register 1: " << reg1 << std::endl;
  std::cout << "Register 2: " << reg1 << std::endl;
  std::cout << "Write Register: " << write_reg << std::endl;
  std::cout << "Write Data: " << write_data << std::endl;

}
