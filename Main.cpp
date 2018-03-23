//#include "CPU.h"
#include "Parser.h"

int main(int argc, char* argv[])
{
    //parser object
    //read config file...the Parser object will have instance variables that are populated.
    Parser p = new Parser(argv[1]);

    //retrieving the config file input given by Parser object

    std::string program_input = p.program_input;
    std::string memory_contents_input = p.memory_contents_input;
    std::string register_file_input = p.register_file_input;
    std::string output_mode = p.output_mode;
    std::string debug_mode = p.debug_mode;
    std::string print_memory_contents = p.print_memory_contents;
    std::string output_file = p.output_file;

    std::cout << program_input << std::endl;
    std::cout << memory_contents_input << std::endl;
    std::cout << register_file_input << std::endl;
    std::cout << output_mode << std::endl;
    std::cout << debug_mode << std::endl;
    std::cout << print_memory_contents << std::endl;
    std::cout << output_file << std::endl;

}
