#include "DataMemory.h"
#include "stdHeader.h"

DataMemory::DataMemory(std::vector<u32> data_m)
{
  data = data_m;
}

DataMemory::~DataMemory() {}
DataMemory::DataMemory() {}

void DataMemory::print_out()
{
  std::cout << " ------------- " << std::endl;
  std::cout << "| Data Memory |" << std::endl;
  std::cout << " ------------- " << std::endl;
  std::cout << "Address: " << address << std::endl;
  std::cout << "Read Data: " << read_data << std::endl;
  std::cout << "Write Data: " << write_data << std::endl;
  std::cout << "Control Line - MemRead: " << control_read << std::endl;
  std::cout << "Control Line - MemWrite: " << control_write << std::endl;
  std::cout << "Memory Contents..." << std::endl;
  for(int i; i < data.size(); i++)
  {
    std::cout << "0x" << std::hex << data.at(i) << std::endl;
  }

}

void DataMemory::execute()
{
    if(control_read == 1)
    {
        //this is a data read
        //retrieve data at this->address
        //set it to this->read_data
    }
    else if(control_write == 1)
    {
        //this is a data write
        //write the data at this->address with this->write_data
    }
}
