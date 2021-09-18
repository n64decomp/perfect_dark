#ifndef IN_GAME_GAME_128F30_H
#define IN_GAME_GAME_128F30_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void crcCalculateU32Pair(u8 *start, u8 *end, u32 *checksum);
void crcCalculateU16Pair(u8 *start, u8 *end, u16 *checksum);
u32 func0f1291b0(void);
u32 func0f1291f8(void);

#endif
