#ifndef PARSER_H
#define PARSER_H

#include "stdHeader.h"

class Parser
{
	public:
		Parser(std::string filename);
		~Parser();
		void read_config_file(std::string filename);

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
