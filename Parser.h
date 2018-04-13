#ifndef PARSER_H
#define PARSER_H

#include "stdHeader.h"

class Parser
{
	public:
		std::vector<u32> register_file;
		//u32 register_file[32];
		std::vector<u32> memory_module;
        std::vector<u32> instruction_memory;    		   // instructions in their machine code form.
        std::vector<std::string> string_instructions;      // instructions in string format.

		Parser(std::string filename);
		~Parser();

		void read_config_file(std::string filename);

		void read_memory_contents();
		void read_register_file();
		void read_program();

        u32 translate_to_machine(std::string line);   //translate string instructions to machine code. from lab 5

		std::string program_input;
		std::string memory_contents_input;
		std::string register_file_input;
		std::string output_mode;
		std::string debug_mode;
		std::string print_memory_contents;
		std::string output_file;
		std::string write_to_file;
};

bool match_case(const char *a, char *b);
u32 handle_RType(char *fields);
u32 handle_IType(char *fields);
u32 handle_JType(char *fields);

#endif
