#include <libultra_internal.h>
#include "bss.h"
#include "data.h"

void __osPackEepWriteData(u8 address, u8 *buffer);

s32 osEepromWrite(OSMesgQueue *mq, u8 address, u8 *buffer)
{
	s32 ret;
	u16 type;
	u8 *ptr;
	__OSContEepromFormat eepromformat;
	OSContStatus sdata;

	ret = 0;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	__osSiGetAccess();
	ret = __osEepStatus(mq, &sdata);

	type = sdata.type & (CONT_EEPROM | CONT_EEP16K);

	if (ret == 0) {
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

	__osPackEepWriteData(address, buffer);

	ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
	__osContLastCmd = CONT_CMD_WRITE_EEPROM;
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	ptr += 4;

	eepromformat = *(__OSContEepromFormat *)ptr;

	ret = CHNL_ERR(eepromformat);

	__osSiRelAccess();
	return ret;
}

void __osPackEepWriteData(u8 address, u8 *buffer)
{
	u8 *ptr;
	__OSContEepromFormat eepromformat;
	int i;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	__osEepPifRam.pifstatus = CONT_CMD_EXE;

	eepromformat.txsize = CONT_CMD_WRITE_EEPROM_TX;
	eepromformat.rxsize = CONT_CMD_WRITE_EEPROM_RX;
	eepromformat.cmd = CONT_CMD_WRITE_EEPROM;
	eepromformat.address = address;

	for (i = 0; i < ARRLEN(eepromformat.data); i++) {
		eepromformat.data[i] = *buffer++;
	}

	for (i = 0; i < 4; i++) {
		*ptr++ = 0;
	}

	*(__OSContEepromFormat *)(ptr) = eepromformat;
	ptr += sizeof(__OSContEepromFormat);
	ptr[0] = CONT_CMD_END;
}

s32 __osEepStatus(OSMesgQueue *mq, OSContStatus *data)
{
	s32 ret;
	int i;
	u8 *ptr;
	__OSContRequestFormat requestformat;

	ret = 0;
	ptr = (u8 *)__osEepPifRam.ramarray;

	for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) {
		__osEepPifRam.ramarray[i] = 0;
	}

	__osEepPifRam.pifstatus = CONT_CMD_EXE;
	ptr = (u8 *)__osEepPifRam.ramarray;

	for (i = 0; i < 4; i++) {
		*ptr++ = 0;
	}

	requestformat.dummy = CONT_CMD_NOP;
	requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
	requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
	requestformat.cmd = CONT_CMD_REQUEST_STATUS;
	requestformat.typeh = CONT_CMD_NOP;
	requestformat.typel = CONT_CMD_NOP;
	requestformat.status = CONT_CMD_NOP;
	requestformat.dummy1 = CONT_CMD_NOP;
	*(__OSContRequestFormat *)ptr = requestformat;
	ptr += sizeof(__OSContRequestFormat);
	*ptr = CONT_CMD_END;

	ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	__osContLastCmd = CONT_CMD_END;
	ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);

	if (ret != 0) {
		return ret;
	}

	ptr = (u8 *)&__osEepPifRam;

	for (i = 0; i < 4; i++) {
		*ptr++ = 0;
	}

	requestformat = *(__OSContRequestFormat *)ptr;
	data->errno = CHNL_ERR(requestformat);
	data->type = (requestformat.typel << 8) | requestformat.typeh;
	data->status = requestformat.status;

	if (data->errno != 0) {
		return data->errno;
	}

	return 0;
}
