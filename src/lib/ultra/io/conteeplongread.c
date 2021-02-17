#include <libultra_internal.h>
#include "data.h"

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int length)
{
	s32 ret;
	ret = 0;

	while (length > 0) {
		ERRCK(osEepromRead(mq, address, buffer));
		length -= EEPROM_BLOCK_SIZE;
		address++;
		buffer += EEPROM_BLOCK_SIZE;
	}

	return ret;
}
