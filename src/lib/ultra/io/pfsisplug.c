#include <libultra_internal.h>
#include "bss.h"
#include "data.h"

OSPifRam __osPfsPifRam;

void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8 *pattern, OSContStatus *data);

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern)
{
	s32 ret;
	OSMesg dummy;
	u8 bitpattern;
	OSContStatus data[MAXCONTROLLERS];
	int channel;
	u8 bits;
	int crc_error_cnt;
	ret = 0;
	bits = 0;
	crc_error_cnt = 1;

	__osSiGetAccess();

	while (TRUE) {
		__osPfsRequestData(CONT_CMD_REQUEST_STATUS);

		ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
		osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

		ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
		osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

		__osPfsGetInitData(&bitpattern, data);

		if (bitpattern);

		for (channel = 0; channel < __osMaxControllers; channel++) {
			if ((data[channel].status & CONT_ADDR_CRC_ER) == 0) {
				crc_error_cnt--;
				break;
			}
		}

		if (__osMaxControllers == channel) {
			crc_error_cnt = 0;
		}

		if (crc_error_cnt < 1) {
			for (channel = 0; channel < __osMaxControllers; channel++) {
				if (data[channel].errno == 0 && (data[channel].status & CONT_CARD_ON) != 0) {
					bits |= 1 << channel;
				}
			}

			__osSiRelAccess();
			*pattern = bits;
			return ret;
		}
	}
}

void __osPfsRequestData(u8 cmd)
{
	u8 *ptr;
	__OSContRequestFormat requestformat;
	int i;
	ptr = (u8 *)&__osPfsPifRam;
	__osContLastCmd = cmd;
	__osPfsPifRam.pifstatus = CONT_CMD_EXE;

	requestformat.dummy = CONT_CMD_NOP;
	requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
	requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
	requestformat.cmd = cmd;
	requestformat.typeh = CONT_CMD_NOP;
	requestformat.typel = CONT_CMD_NOP;
	requestformat.status = CONT_CMD_NOP;
	requestformat.dummy1 = CONT_CMD_NOP;

	for (i = 0; i < __osMaxControllers; i++) {
		*(__OSContRequestFormat *)ptr = requestformat;
		ptr += sizeof(__OSContRequestFormat);
	}

	*ptr = CONT_CMD_END;
}

void __osPfsGetInitData(u8 *pattern, OSContStatus *data)
{
	u8 *ptr;
	__OSContRequestFormat requestformat;
	int i;
	u8 bits;
	bits = 0;
	ptr = (u8 *)&__osPfsPifRam;

	for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(__OSContRequestFormat)) {
		requestformat = *(__OSContRequestFormat *)ptr;
		data->errno = CHNL_ERR(requestformat);

		if (data->errno == 0) {
			data->type = (requestformat.typel << 8) | (requestformat.typeh);
			data->status = requestformat.status;
			bits |= 1 << i;
		}

		data++;
	}

	*pattern = bits;
}
