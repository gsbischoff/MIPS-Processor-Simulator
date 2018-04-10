#ifndef STDHEADER_H
#define STDHEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdint.h>
#include <vector>

#define u32 uint32_t
#define s32 int32_t

#define u16 uint16_t
#define s16 int16_t

#define u8 uint8_t
#define s8 int8_t

#define MASK_31_26 0xFC000000
#define MASK_25_21 0x03E00000
#define MASK_20_16 0x001F0000
#define MASK_15_11 0x0000F800
#define MASK_15_0 0x0000FFFF
#define MASK_5_0 0x0000003F
#define MASK_31_28 0xF0000000
#define MASK_25_0 0x03FFFFFF

#endif
