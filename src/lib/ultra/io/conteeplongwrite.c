#include <libultra_internal.h>
#include "bss.h"
#include "data.h"

s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int length)
{
	s32 ret;
	ret = 0;

	while (length > 0) {
		ERRCK(osEepromWrite(mq, address, buffer));
		length -= EEPROM_BLOCK_SIZE;
		address++;
		buffer += EEPROM_BLOCK_SIZE;
		osSetTimer(&__osEepromTimer, 562500, 0, &__osEepromTimerQ, &__osEepromTimerMsg);
		osRecvMesg(&__osEepromTimerQ, NULL, OS_MESG_BLOCK);
	}

	return ret;
}
