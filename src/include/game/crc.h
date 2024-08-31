#ifndef IN_GAME_CRC_H
#define IN_GAME_CRC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void crc_calculate_u16_pair(u8 *start, u8 *end, u16 *checksum);

#endif
