//#include "CPU.h"
#include "Parser.h"

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
    //CPU cpu = CPU(read_inst_file(program_input), read_mem_file(memory_contents_input), read_reg_file(register_file_input));

    /** What is our roadmap from here??
    *
    *   Perhaps for each line in the instruction file..execute instruction. So CPU needs an "execute instruction"
    *   method.  WHich would call control_unit.set_datapath().
    *
    *   for(int i=0; i<cpu.instruction_memory.size(); i++)
    *       cpu.execute(cpu.intruction_memory.get(i));
    *
    */

    //test that we got the config files
    std::cout << "Input File: " << program_input << std::endl;
    std::cout << "Memory Contents File: " << memory_contents_input << std::endl;
    std::cout << "Register File: " << register_file_input << std::endl;
    std::cout << "Output Mode: " << output_mode << std::endl;
    std::cout << "Debug Mode: " << debug_mode << std::endl;
    std::cout << "Print Memory Contents: " << print_memory_contents << std::endl;
    std::cout << "Output File: " << output_file << std::endl;
    std::cout << "Write to File: " << write_to_file << std::endl;

}

/*
std::vector<int> read_mem_file(std::string filename)
{
    std::vector<int> memory;

    return memory;
}
*/

/*
std::vector<int> read_inst_file(std::string filename)
{
    std::vector<int> instructions;

    return instructions;
}
*/

/*
//method to read the register file...it will return a vector so that we can directly put it into the CPU constructor.
int[] read_reg_file(std::string filename)
{
    ifstream input;
    int[] reg_vals;

    input.open(filename.c_str());

    if(input.bad())
    {
        printf("Got \"bad\" input\n");
    }
    else
    {
        string line;
        int lineNum = 0;

        while(getline(input, line))
        {
            lineNum++;

            if(strlen(line.c_str()) == 0)
                continue;

            if((char) *(line.c_str()) == '#')
                continue;

        }

    }

    return reg_vals;
}

*/
