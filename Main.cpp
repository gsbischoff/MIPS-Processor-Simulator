#include "CPU.h"
#include "Parser.cpp"

int main()
{
    //parser object
    Parser p = new Parser();

    //parameters to be read by the config file parser
    std::string program_input;
    std::string memory_contents_input;
    std::string register_file_input;
    std::string output_mode;
    std::string debug_mode;
    std::string print_memory_contents;
    std::string output_file;

    //read config file...the Parser object will have instance variables that are populated.
    p.readConfig(argv[1]);

    program_input;
    memory_contents_input;
    register_file_input;
    output_mode;
    debug_mode;
    print_memory_contents;
    output_file;

}
