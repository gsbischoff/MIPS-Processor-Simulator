#include "Parser.h"

using namespace std;
Parser::Parser(string filename)
{
	read_config_file(filename);
}

Parser::~Parser()
{
}
/*
u32
Parser::parse_line(string line)
{
	return(0);
}*/

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

			int size = line.size();

			char *buf = strdup(line.c_str());
			char *buf_s = buf; 	// Actual string start so we can free

			// Cut off any comments
			for(int i = 0; i < size; ++i)
				if(buf[i] == '#')
					buf[i] = '\0';

			// Strip any leading whitespace
			while(buf[0] != '\0' && (buf[0] == ' ' || buf[0] == '\t'))
				buf++;

			int end = strlen(buf) - 1;

			// If nothing remains, ignore the line
			if(end < 0)
				continue;	

			// Strip any trailing whitespace
			while(end != 0 && buf[end] != '\0' 
					&& (buf[end] == ' ' || buf[end] == '\t'))
			{
				buf[end] = '\0';
				end--;
			}
			
			// Store the line in the instruction vector
			string instr = buf;
			string_instructions.push_back(instr);

			printf("\'%s\'\n", buf);

			// Free all of the allocated memory from the original start
			free(buf_s);
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
