#include "Parser.h"

int
main(int argc, char **argv)
{
	std::string filename;

	if(argc == 2)
	{
		//filename = 
		printf("Reading config ...\n");
		Parser parser = Parser("test.txt");

		parser.register_file_input = argv[1];
		printf("Reading reg file ...\n");
		parser.read_register_file();

		//parser.register_file_input = argv[1];

		printf("Source read!\n");
	}	
}