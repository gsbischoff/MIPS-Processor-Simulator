#include "CPU.h"
#include "Parser.h"
#include "stdHeader.h"

int main(int argc, char* argv[])
{
    //parser object
    //read config file...the Parser object will have instance variables that are populated.
    Parser p = Parser(argv[1]);

    //retrieving the config file input given by Parser object
    std::string program_input = p.program_input;
    std::string memory_contents_input = p.memory_contents_input;
    std::string register_file_input = p.register_file_input;
    std::string output_mode = p.output_mode;
    std::string debug_mode = p.debug_mode;
    std::string print_memory_contents = p.print_memory_contents;
    std::string output_file = p.output_file;
    std::string write_to_file = p.write_to_file;

    //CPU object instantiated. takes the return values of our ** read file methods ** (TODO Implement these)
    CPU cpu = CPU(p.instruction_memory, p.memory_module, p.register_file);

    std::cout << std::hex << cpu.instruction_memory[0] << std::endl;
    cpu.execute(cpu.PC);
    cpu.print_out();

    /**
    *
    *
    *   if(output_mode = "batch")
    *   {
    *       while(cpu.PC != exit)
    *           cpu.execute(cpu.PC);
    *
    *   }
    *   else{
    *       //make it single step...
    *   }
    */

    /*test that we got the config files
    std::cout << "Input File: " << program_input << std::endl;
    std::cout << "Memory Contents File: " << memory_contents_input << std::endl;
    std::cout << "Register File: " << register_file_input << std::endl;
    std::cout << "Output Mode: " << output_mode << std::endl;
    std::cout << "Debug Mode: " << debug_mode << std::endl;
    std::cout << "Print Memory Contents: " << print_memory_contents << std::endl;
    std::cout << "Output File: " << output_file << std::endl;
    std::cout << "Write to File: " << write_to_file << std::endl;

    */

}

