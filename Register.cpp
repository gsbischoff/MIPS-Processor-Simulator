#include "Register.h"
#include "stdHeader.h"

Register::Register(std::vector<u32> reg)
{
  registers = reg;
}

Register::~Register() {}
Register::Register() {}



void Register::write()
{
  registers[write_reg] = write_data;
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
  std::cout << "Register Contents..." << std::endl;
  for(int i; i < 32; i++)
  {
    std::cout << i << ": 0x" << std::hex << registers.at(i) << std::endl;
  }

}