#ifndef STDHEADER_H
#define STDHEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdint.h>
#include <string>
#include <vector>
#include <map>

// Example of using bitfields and unions to extract
// fields from an instruction as member vars.
union Formated
{
	struct	// R-Type
	{
		u32 funct	: 6;
		u32 shamt	: 5;
		u32 rd		: 5;
		u32 rt		: 5;
		u32 rs		: 5;
		u32 opcode	: 6;
	};
	struct	// I-Type
	{
		u32 imm		: 16;
		// u32 rt		: 5;
		// u32 rs		: 5;
		// u32 opcode	: 6;
	};
	struct	// J-Type
	{
		u32 addr	: 26;
		// u32 opcode	: 6;
	};
	u32 u;	// The whole instruction
};

typedef uint32_t	u32;
typedef int32_t		s32;

typedef uint16_t	u16;
typedef int16_t		s16;

typedef uint8_t		u8;
typedef int8_t		s8;

#define MASK_31_26	0xFC000000
#define MASK_25_21	0x03E00000
#define MASK_20_16	0x001F0000
#define MASK_15_11	0x0000F800
#define MASK_15_0	0x0000FFFF
#define MASK_5_0	0x0000003F
#define MASK_31_28	0xF0000000
#define MASK_25_0	0x03FFFFFF

#endif
