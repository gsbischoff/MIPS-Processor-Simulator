#include "Parser.h"

int
main(int argc, char **argv)
{
	std::string filename;

	//if(argc == 2)
	{
		//filename = 
		printf("Reading config ...\n");
		Parser parser = Parser("input.config");

	/*	parser.register_file_input = argv[1];
		printf("Reading reg file ...\n");
		parser.read_register_file();

		//parser.register_file_input = argv[1];
		char c[20] = "$1, $2, 0xf";
		char w[20] = "$1, $2, $5";
		char d[20] = "$1, 0xf($2)";
		u32 h = handle_RType(w);
		printf("ITYPE: %x\n", h);*/

		printf("Source read!\n");
	}	
}