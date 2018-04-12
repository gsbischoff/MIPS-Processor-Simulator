#include "Parser.h"

using namespace std;
Parser::Parser(string filename)
{
	read_config_file(filename);
}

Parser::~Parser()
{
}

// 6 bit opcode field and 6 bit func field set
enum Opcode
{
	UNDEF = 0,
	ADD = 	(0x00 << 26) | (32),
	SUB = 	(0x00 << 26) | (34),
	ADDI = 	(0x08 << 26) | (0),
	SLT = 	(0x02 << 26) | (42),
	LW = 	(0x23 << 26) | (0),
	SW = 	(0x2b << 26) | (0),
	BEQ =	(0x04 << 26) | (0),
	J = 	(0x02 << 26) | (0)
};

u32 get_register(char *f)
{
	for(int i = 0; i < strlen(f); ++i)
		if(f[i] == '$')
			return strtoul(f + 1, NULL, 10);

	return strtoul(f, NULL, 16);
}

u32 handle_RType(char *fields)
{
	// Have comma-seperated registers
	char *buf_s = fields;

	char *rd, *rs, *rt;
	int rd_n, rs_n, rt_n;

	// Check if we have the immediate field 2nd (true) or 3rd (false)
	int commas = 0;
	for(int i = 0; i < strlen(fields); ++i)
		if(fields[i] == ',')
			commas++;

	// All R-Type instructions we are handling will have 3 register fields
	if((rd = strtok(fields, ",")) == NULL)
		return(0);

	if((rs = strtok(NULL, ",")) == NULL)
		return(0);

	if((rt = strtok(NULL, ",")) == NULL)
		return(0);

	
}
u32 handle_IType(char *fields)
{
	char *rs, *rt, *imm;
	bool offset = true;

	int rs_n, rt_n, imm_n;

	// Check if we have the immediate field 2nd (true) or 3rd (false)
	int commas = 0;
	for(int i = 0; i < strlen(fields); ++i)
		if(fields[i] == ',')
			commas++;

	if(commas == 2)
		offset = false;

	if((rt = strtok(fields, ",")) == NULL)
		return(0);

	rt_n = get_register(rt);

	if(!offset)	// $rt, $rs, imm	
	{
		if((rs = strtok(NULL, ",")) == NULL)
			return(0);

		if((imm = strtok(NULL, ",")) == NULL)
			return(0);

		rs_n = get_register(rs);

		imm_n = strtoul(imm, NULL, 16);
	}
	else	// $rt, imm($rs) -> $rt
	{
		char *temp;

		if((imm = strtok(NULL, ",()")) == NULL)	// imm($rs) -> imm
			return(0);

		if((rs = strtok(NULL, ",()")) == NULL)	// $rs) -> $rs
			return(0);

		rs_n = get_register(rs);

		imm_n = strtoul(imm, NULL, 16);		
	}
	
	return (rs_n << 21)
		 | (rt_n << 16)
		 | (imm_n);
}

u32 handle_JType(char *fields)
{
	// Fill last 26 bits with value
	return 0x03FFFFFF & strtoul(fields, NULL, 16);
}


bool match_case(const char *a, char *b)
{
	printf("Words \'%s\' \'%s\'\n", a, b);
	int a_len = strlen(a);

	bool result = true;

	for(int i = 0; i < a_len; ++i)
		result &= (a[i] - b[i] == 0 
				|| a[i] - b[i] == ('a' - 'A')
				|| a[i] - b[i] == ('A' - 'a'));

	return result;
}

// -----
//  translate_to_machine
//	  Translates each of the MIPS instruction lines in
// 	  the instruction vector field string_instructions
//	  		into 32-bit machine code
void Parser::translate_to_machine()
{
	u32 instruction;

	// Take a line
	std::string line = string_instructions[1];

	char *buf = strdup(line.c_str());
	char *buf_s = buf; 	// Actual string start so we can free

	// Replace tabs with spaces to make parsing easier
	for(int i = 0; i < strlen(buf); ++i)
		if(buf[i] == '\t')
			buf[i] = ' ';

	/*
		ADD
		SUB
		ADDI
		SLT
		LW
		SW
		BEQ
		J
	*/
	// Get Opcode
	char *opcode = strtok(buf, " ");
	char *fields = strtok(NULL, " ");

	Opcode op = UNDEF;

	if(match_case("add", opcode))	op = ADD;
	if(match_case("sub", opcode))	op = SUB;
	if(match_case("addi", opcode))	op = ADDI;
	if(match_case("slt", opcode))	op = SLT;
	if(match_case("lw", opcode))	op = LW;
	if(match_case("sw", opcode))	op = SW;
	if(match_case("beq", opcode))	op = BEQ;
	if(match_case("j", opcode))		op = J;

	switch(op)
	{
		case ADD:
			instruction |= ADD;
			instruction |= handle_RType(fields);
			break;
		case SUB:
			instruction |= SUB;
			instruction |= handle_RType(fields);
			break;
		case ADDI:
			instruction |= ADDI;
			instruction |= handle_IType(fields);
			break;
		case SLT:
			instruction |= SLT;
			instruction |= handle_RType(fields);
			break;
		case LW:
			instruction |= LW;
			instruction |= handle_IType(fields);
			break;
		case SW:
			instruction |= SW;
			instruction |= handle_IType(fields);
			break;
		case BEQ:
			instruction |= BEQ;
			instruction |= handle_IType(fields);
			break;
		case J:
			instruction |= J;
			instruction |= handle_JType(fields);
			break;
		default:
			free(buf_s);
			return;
	}
	



	

	free(buf_s);	
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
