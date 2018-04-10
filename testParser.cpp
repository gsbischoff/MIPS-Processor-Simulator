#include "Parser.h"

int
main(int argc, char **argv)
{
	std::string filename;

	if(argc == 2)
	{
		filename = argv[1];
		printf("Reading config ...\n");
		Parser parser = Parser("test.txt");

		printf("Reading source ...\n");
		parser.read_source(filename);

		printf("Source read!\n");
	}	
}