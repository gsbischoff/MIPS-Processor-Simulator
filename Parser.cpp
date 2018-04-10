#include "Parser.h"

using namespace std;
Parser::Parser(string filename)
{
	read_config_file(filename);
}

Parser::~Parser()
{
}

std::string stripLine(string line)
{
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
		return "";

	// Strip any trailing whitespace
	while(end != 0 && buf[end] != '\0' 
			&& (buf[end] == ' ' || buf[end] == '\t'))
	{
		buf[end] = '\0';
		end--;
	}
	
	// Store the line
	string temp = buf;

	// Free all of the allocated memory from the original start
	free(buf_s);

	return temp;
}

void Parser::read_register_file()
{
	ifstream input;

	input.open(register_file_input.c_str());

	if(input.bad())
	{
		printf("Could not open file \"%s\"!\n", register_file_input.c_str());
	}
	else
	{
		string line;
		int lineNum = 0;

		while(getline(input, line))
		{
			lineNum++;

			string str = stripLine(line);

			if(str.size() == 0)
				continue;

			char *buf = strdup(str.c_str());
			char *buf_s = buf;

			char *reg;
			char *value;

			reg = strtok(buf, ":");

			if((value = strtok(NULL,":")) == NULL)
			{
				printf("Malformed input on line %d!\n", lineNum);
				free(buf_s);
				break;
			}
			else
			{
				// take chars and convert each into its int value
				// decimal for register number and hex for the value
				u32 r = std::strtoul(reg, NULL, 10);
				u32 val = std::strtoul(value, NULL, 16);

				printf("Val on line %d:%x\n", r, val);

				// Ignore invalid-valued registers
				if(r > 31)
					continue;

				register_file[r] = val;
			}

			free(buf_s);
		}
	}
}

void Parser::read_memory_contents()
{
	ifstream input;

	input.open(memory_contents_input.c_str());

	if(input.bad())
	{
		printf("Could not open file \"%s\"!\n", memory_contents_input.c_str());
	}
	else
	{
		string line;
		int lineNum = 0;

		while(getline(input, line))
		{
			lineNum++;

			string str = stripLine(line);

			if(str.size() == 0)
				continue;

			char *buf = strdup(str.c_str());
			char *buf_s = buf;

			char *offset;
			char *value;

			offset = strtok(buf, ":");

			if((value = strtok(NULL,":")) == NULL)
			{
				printf("Malformed input on line %d!\n", lineNum);
				free(buf_s);
				break;
			}
			else
			{
				// take chars and convert each hex digit to its corresponding bits
				u32 val = std::strtoul(value, NULL, 16);

				instruction_memory.push_back(val);
			}

			free(buf_s);
		}
	}
}

void Parser::read_program() //string filename)
{
	ifstream input;

	input.open(program_input.c_str());

	if(input.bad())
	{
		printf("Could not open file \"%s\"!\n", program_input.c_str());
	}
	else
	{
		string line;
		int lineNum = 0;

		while(getline(input, line))
		{
			lineNum++;

			string str = stripLine(line);

			if(str.size() == 0)
				continue;
			
			// Store the line in the instruction vector
			string_instructions.push_back(str);
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

			string str = stripLine(line);

			if(str.size() == 0)
				continue;

			char *buf = strdup(str.c_str());
			char *buf_s = buf;

			char *parameter;
			char *value;

			parameter = strtok(buf, "=");

			if((value = strtok(NULL,"=")) == NULL)
			{
				printf("Malformed input on line %d!\n", lineNum);
				free(buf_s);
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
					free(buf_s);
					break;
				}
			}

			free(buf_s);
		}
	}
}
