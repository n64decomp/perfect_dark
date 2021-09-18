#ifndef IN_GAME_CRC_H
#define IN_GAME_CRC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void crcCalculateU32Pair(u8 *start, u8 *end, u32 *checksum);
void crcCalculateU16Pair(u8 *start, u8 *end, u16 *checksum);

#endif
