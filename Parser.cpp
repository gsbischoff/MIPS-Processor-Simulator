#include "Parser.h"

using namespace std;
Parser::Parser(string filename)
{
	read_config_file(filename);
}

Parser::~Parser()
{
}

void Parser::read_source(string filename)
{
	ifstream input;

	input.open(filename.c_str());

	if(input.bad())
	{
		printf("Could not open file \"%s\"!\n", filename.c_str());
	}
	else
	{
		string line;
		int lineNum = 0;

		while(getline(input, line))
		{
			lineNum++;

			// Ignore empty lines
			if(line.size() == 0)	
				continue;

			char *buf = strdup(line.c_str());

			if((value = strtok(line_c,"#")) == NULL)
			{
				printf("Malformed input on line %d!\n", lineNum);
				free(buf);
				break;
			}
			else
			{
				string instr = buf;
				string_instructions.emplace_back(instr);
				printf("Got line: %s\n", buf);
				free(buf);

				continue;
			}
		}
	}
}

void Parser::read_config_file(string filename)
{
	ifstream input;

	input.open(filename.c_str());

	if(input.bad())
	{
		printf("Could not open file \"%s\"!\n", filename.c_str());
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

			char *buf = strdup(line.c_str());

			char *parameter;
			char *value;

			parameter = strtok(buf, "=");

			if((value = strtok(NULL,"=")) == NULL)
			{
				printf("Malformed input on line %d!\n", lineNum);
				free(buf);
				break;
			}
			else
			{
				if (!strcmp(parameter, "program_input"))
					program_input = value;
				else if (!strcmp(parameter, "memory_contents_input"))
					memory_contents_input = value;
				else if (!strcmp(parameter, "register_file_input"))
					register_file_input = value;
				else if (!strcmp(parameter, "output_mode"))
					output_mode = value;
				else if (!strcmp(parameter, "debug_mode"))
					debug_mode = value;
				else if (!strcmp(parameter, "print_memory_contents"))
					print_memory_contents = value;
				else if (!strcmp(parameter, "output_file"))
					output_file = value;
				else if (!strcmp(parameter, "write_to_file"))
					write_to_file = value;
				else
				{
					printf("Malformed input on line %d!\n", lineNum);
					free(buf);
					break;
				}
			}

			free(buf);
		}
	}
}
