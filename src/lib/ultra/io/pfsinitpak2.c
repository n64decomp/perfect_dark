#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 __osPfsCheckRamArea2(OSPfs* pfs);

s32 osPfsInitPak2(OSMesgQueue *queue, OSPfs *pfs, s32 channel)
{
	s32 ret;
	u16 csum;
	u16 icsum;
	__OSPackId oldid;
	__OSPackId *id;
	__OSPackId newid;

	__osSiGetAccess();
	ret = __osPfsGetStatus(queue, channel);
	__osSiRelAccess();

	if (ret != 0) {
		return ret;
	}

	pfs->queue = queue;
	pfs->channel = channel;
	pfs->status = 0;

	ret = __osPfsCheckRamArea2(pfs);

	if (ret != 0) {
		return ret;
	}

	ret = __osPfsSelectBank(pfs, 0);

	if (ret != 0) {
		return ret;
	}

	ret = __osContRamRead(pfs->queue, pfs->channel, 1, (u8 *)&oldid);

	if (ret != 0) {
		return ret;
	}

	__osIdCheckSum((u16 *)&oldid, &csum, &icsum);

	id = &oldid;

	if ((oldid.checksum != csum || oldid.inverted_checksum != icsum)) {
		ret = __osCheckPackId(pfs, &oldid);

		if (ret != 0) {
			pfs->status |= PFS_ID_BROKEN;
			return ret;
		}
	}

	if ((oldid.deviceid & 1) == 0) {
		ret = __osRepairPackId(pfs, &oldid, &newid);

		if (ret != 0) {
			if (ret == PFS_ERR_ID_FATAL) {
				pfs->status |= PFS_ID_BROKEN;
			}

			return ret;
		}

		id = &newid;

		if ((newid.deviceid & 1) == 0) {
			return PFS_ERR_DEVICE;
		}
	}

	bcopy(id, pfs->id, sizeof(*id));

	pfs->version = id->version;
	pfs->banks = id->banks;
	pfs->inode_start_page = pfs->banks * 2 + 3;
	pfs->dir_size = 16;
	pfs->inode_table = 8;
	pfs->minode_table = pfs->banks * PFS_ONE_PAGE + 8;
	pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;

	ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);

	if (ret != 0) {
		return ret;
	}

	ret = osPfsChecker(pfs);
	pfs->status |= PFS_INITIALIZED;

	return ret;
}

s32 __osPfsCheckRamArea2(OSPfs* pfs)
{
	s32 i = 0;
	s32 ret = 0;
	u8 temp1[BLOCKSIZE];
	u8 temp2[BLOCKSIZE];
	u8 saveReg[BLOCKSIZE];

	if ((ret = __osPfsSelectBank(pfs, 0)) != 0) {
		return ret;
	}

	if ((ret = __osContRamRead(pfs->queue, pfs->channel, 0, saveReg)) != 0) {
		return ret;
	}

	for (i = 0; i < BLOCKSIZE; i++) {
		temp1[i] = i;
	}

	if ((ret = __osContRamWrite(pfs->queue, pfs->channel, 0, temp1, 0)) != 0) {
		return ret;
	}

	if ((ret = __osContRamRead(pfs->queue, pfs->channel, 0, temp2)) != 0) {
		return ret;
	}

	if (bcmp(temp1, temp2, BLOCKSIZE) != 0) {
		return PFS_ERR_DEVICE;
	}

	return __osContRamWrite(pfs->queue, pfs->channel, 0, saveReg, 0);
}
