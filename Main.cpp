#include "CPU.h"
#include "Parser.h"
#include "stdHeader.h"

// -----
//  MIPS Processor Simulator
//	  Simulates a a 5-stage, nonpipelined, MIPS processor. Can
//	  read and write the contents of data and instruction
//			memory as well as a register file input
int main(int argc, char* argv[])
{
    // Creates a Parser object
    // Reads the config file...the Parser object will have instance variables that are populated.
    Parser p = Parser(argv[1]);

    // Retrieving the config file input given by Parser object
    std::string program_input = p.program_input;
    std::string memory_contents_input = p.memory_contents_input;
    std::string register_file_input = p.register_file_input;
    std::string output_mode = p.output_mode;
    std::string debug_mode = p.debug_mode;
    std::string print_memory_contents = p.print_memory_contents;
    std::string output_file = p.output_file;
    std::string write_to_file = p.write_to_file;

    // CPU object instantiated. takes the return values of our ** read file methods ** (TODO Implement these)
    CPU cpu = CPU(p.instruction_memory, p.memory_module, p.register_file, p.string_instructions);

    // Execute based on mode specified in input file
    if(output_mode == "batch")
    {
		// Batch mode
		//	Executes all instructions and prints memory contents at the end
        while(cpu.execute(p.instruction_mem_size))
            ;   // nop

        if(debug_mode == "true") cpu.print_out(); // Print everything out
        if(print_memory_contents == "true")
        {
            cpu.data_memory.print_out();	// Print data memory
            cpu.reg_file.print_out();		// Print out register file
        }
        cpu.print_out();
    }
    else
    {
		// Single-step mode
		//	Executes instructions one-by-one, printing memory contents at each step
        std::cout << "Press a key to begin execution:" << std::endl;
        std::cin.get();
        while(cpu.execute(p.instruction_mem_size))
        {
            cpu.print_out();
            std::cout << "Press enter to continue." << std::endl;
            std::cin.get();
        }
        cpu.print_out();
    }

    // Write to file if specified in input file
	if(write_to_file == "true")	// 100% pwoper booleans
	{
		std::ofstream outfile;

		outfile.open(output_file.c_str());

		if(outfile.is_open())
        {
    		for(auto iter = cpu.data_memory.data.begin(); iter != cpu.data_memory.data.end(); ++iter)
    		{
    			outfile << "0x" << std::hex << iter->first << ":" << iter->second << std::endl;
    		}

    		for(int i=0; i < 32; i++)
    		{
    			outfile << i;
    			outfile << ":0x" << std::hex << cpu.reg_file.registers[i] << std::endl;
    		}
    		outfile.close();
        }
	}

}

