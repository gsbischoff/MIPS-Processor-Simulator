#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream input;
	string filename = "test.txt";

	input.open(filename.c_str());

	string program_input;
	string memory_contents_input;
	string register_file_input;
	string output_mode;
	string debug_mode;
	string print_memory_contents;
	string output_file;

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
				else
				{
					printf("Malformed input on line %d!\n", lineNum);
					free(buf);
					break;
				}
			}

			//printf("Read in [   %s   =   %s   ]\n", parameter, value);

			free(buf);
		}
	}


	printf("%s\n", program_input.c_str());
	printf("%s\n", memory_contents_input.c_str());
	printf("%s\n", register_file_input.c_str());
	printf("%s\n", output_mode.c_str());
	printf("%s\n", debug_mode.c_str());
	printf("%s\n", print_memory_contents.c_str());
	printf("%s\n", output_file.c_str());

	return 0;
}