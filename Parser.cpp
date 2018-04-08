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

			// Ignore empty lines
			if(size == 0)	
				continue;

			char *buf = strdup(line.c_str());

			for(int i = 0; buf[i] == ' ' || buf[i] == '\t' || i < size; ++i)
				
			// cut off any comments
			for(int i = 0; i < size; ++i)
				if(buf[i] == '#')
					buf[i] = '\0';

			int cutLen = strlen(buf);

			if(cutLen == 0)
				continue;

			bool isSpacedout = true;

			for(int i = 0; i < cutLen; ++i)
				isSpacedout &= (buf[i] == ' ');

			if(isSpacedout)
				continue; 
			
			char *bufStart = buf;
/*
			if((buf = strtok(buf,"#")) == NULL)
			{
				printf("Malformed input on line %d!\n", lineNum);
				free(bufStart);
				break;
			}
			else
			{*/
				if(strlen(buf) == 0)
					continue;

				string instr = buf;
				string_instructions.push_back(instr);
				printf("\'%s\'\n", bufStart);
				free(bufStart);

				continue;
			//}
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
