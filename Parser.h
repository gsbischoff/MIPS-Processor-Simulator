#ifndef PARSER_H
#define PARSER_H

#include "stdHeader.h"

class Parser
{
	public:

        std::vector<int> instruction_memory;    		   // instructions in their machine code form.
        std::vector<std::string> string_instructions;      //instructions in string format.

		Parser(std::string filename);
		~Parser();

		void read_config_file(std::string filename);
        void translate_to_machine(std::string filename);   //translate string instructions to machine code. from lab 5

		std::string program_input;
		std::string memory_contents_input;
		std::string register_file_input;
		std::string output_mode;
		std::string debug_mode;
		std::string print_memory_contents;
		std::string output_file;
		std::string write_to_file;
};
#endif
