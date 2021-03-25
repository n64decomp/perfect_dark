#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

OSPifRam osPifBuffers[MAXCONTROLLERS];

s32 osMotorAccess(OSPfs *pfs, u32 vibrate)
{
	s32 i;
	s32 ret;
	u8* buf = (u8*)&osPifBuffers[pfs->channel];

	if (!(pfs->status & 8)) {
		return 5;
	}

	__osSiGetAccess();
	osPifBuffers[pfs->channel].pifstatus = 1;
	buf += pfs->channel;

	for (i = 0; i < BLOCKSIZE; i++) {
		((__OSContRamReadFormat*)buf)->data[i] = vibrate;
	}

	__osContLastCmd = CONT_CMD_END;
	__osSiRawStartDma(OS_WRITE, &osPifBuffers[pfs->channel]);
	osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
	__osSiRawStartDma(OS_READ, &osPifBuffers[pfs->channel]);
	osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);

	ret = ((__OSContRamReadFormat*)buf)->rxsize & 0xc0;

	if (!ret) {
		if (!vibrate) {
			if (((__OSContRamReadFormat*)buf)->datacrc != 0) {
				ret = PFS_ERR_CONTRFAIL;
			}
		} else {
			if (((__OSContRamReadFormat*)buf)->datacrc != 0xeb) {
				ret = PFS_ERR_CONTRFAIL;
			}
		}
	}

	__osSiRelAccess();

	return ret;
}

void osSetUpMempakWrite(s32 channel, OSPifRam* buf)
{
	u8* bufptr = (u8*)buf;
	__OSContRamReadFormat mempakwr;
	s32 i;

	mempakwr.dummy = 0xff;
	mempakwr.txsize = 0x23;
	mempakwr.rxsize = 1;
	mempakwr.cmd = 3;
	mempakwr.hi = 0x600 >> 3;
	mempakwr.lo = (u8)(__osContAddressCrc(0x600) | (0x600 << 5));

	if (channel != 0) {
		for (i = 0; i < channel; ++i) {
			*bufptr++ = 0;
		}
	}

	*(__OSContRamReadFormat*)bufptr = mempakwr;
	bufptr += sizeof(mempakwr);
	*bufptr = 0xfe;
}

s32 osMotorProbe(OSMesgQueue* ctrlrqueue, OSPfs* pfs, s32 channel)
{
	s32 ret;
	u8 sp24[BLOCKSIZE];

	pfs->queue = ctrlrqueue;
	pfs->channel = channel;
	pfs->activebank = 0xff;
	pfs->status = 0;

	ret = __osPfsSelectBank(pfs, 0xfe);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = __osPfsSelectBank(pfs, 0x80);
	}

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(ctrlrqueue, channel, 0x400, sp24);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	if (sp24[BLOCKSIZE - 1] == 0xfe) {
		return PFS_ERR_DEVICE;
	}

	ret = __osPfsSelectBank(pfs, 0x80);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(ctrlrqueue, channel, 0x400, sp24);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = PFS_ERR_CONTRFAIL;
	}

	if (ret != 0) {
		return ret;
	}

	if (sp24[BLOCKSIZE - 1] != 0x80) {
		return PFS_ERR_DEVICE;
	}

	if ((pfs->status & PFS_MOTOR_INITIALIZED) == 0) {
		osSetUpMempakWrite(channel, &osPifBuffers[channel]);
	}

	pfs->status = PFS_MOTOR_INITIALIZED;

	return 0;
}
