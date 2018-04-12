#include <"DataMemory.h">

DataMemory::DataMemory(std::vector<int> data_m)
{
  data = data_m;
}

DataMemory::~DataMemory() {}

void DataMemory::print_out()
{
  std::cout << " ------------- " << std::endl;
  std::cout << "| Data Memory |" << std::endl;
  std::cout << " ------------- " << std::endl;
  //std::cout << "Input A: " << in_a << std::endl;
  //std::cout << "Input B: " << in_b << std::endl;
  //std::cout << "Selector: " << selectorBit << std::endl;
  //std::cout << "Output: " << output << std::endl;

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
