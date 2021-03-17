#include <libultra_internal.h>
#include "bss.h"
#include "data.h"

OSPifRam __osEepPifRam;

#if VERSION >= VERSION_PAL_FINAL
u32 var8009d010pf[4];
#endif

void *var8009cac0;
void *var8009cac4;

void __osPackEepReadData(u8 address);

s32 osEepromRead(OSMesgQueue *mq, u8 address, u8 *buffer)
{
	s32 ret;
	int i;
	u16 type;
	u8 *ptr;
	OSContStatus sdata;
	__OSContEepromFormat eepromformat;
	ret = 0;
	i = 0;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	__osSiGetAccess();
	ret = __osEepStatus(mq, &sdata);

	if (ret == 0) {
		type = sdata.type & (CONT_EEPROM | CONT_EEP16K);

		switch (type) {
		case CONT_EEPROM:
			// @bug: Should be > EEPROM_MAXBLOCKS
			if (address >= EEPROM_MAXBLOCKS) {
				ret = -1;
			}
			break;
		case CONT_EEPROM | CONT_EEP16K:
			// @bug: Should be > EEP16K_MAXBLOCKS
			if (address >= EEP16K_MAXBLOCKS) {
				ret = -1;
			}
			break;
		default:
			if (1);
			ret = CONT_NO_RESPONSE_ERROR;
			break;
		}
	}

	if (ret != 0) {
		__osSiRelAccess();
		return ret;
	}

	while (sdata.status & CONT_EEPROM_BUSY) {
		__osEepStatus(mq, &sdata);
	}

	__osPackEepReadData(address);

	ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
	__osContLastCmd = CONT_CMD_READ_EEPROM;
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	for (i = 0; i < 4; i++) {
		ptr++;
	}

	eepromformat = *(__OSContEepromFormat *)ptr;

	ret = CHNL_ERR(eepromformat);

	if (ret == 0) {
		for (i = 0; i < ARRLEN(eepromformat.data); i++) {
			*buffer++ = eepromformat.data[i];
		}
	}

	__osSiRelAccess();

	return ret;
}

void __osPackEepReadData(u8 address)
{
	u8 *ptr;
	__OSContEepromFormat eepromformat;
	int i;
	ptr = (u8 *)&__osEepPifRam.ramarray;

	__osEepPifRam.pifstatus = CONT_CMD_EXE;

	eepromformat.txsize = CONT_CMD_READ_EEPROM_TX;
	eepromformat.rxsize = CONT_CMD_READ_EEPROM_RX;
	eepromformat.cmd = CONT_CMD_READ_EEPROM;
	eepromformat.address = address;

	for (i = 0; i < 4; i++) {
		*ptr++ = 0;
	}

	*(__OSContEepromFormat *)(ptr) = eepromformat;
	ptr += sizeof(__OSContEepromFormat);
	ptr[0] = CONT_CMD_END;
}
