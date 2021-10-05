#include "versions.h"
#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 __osPfsCheckRamArea(OSPfs* pfs);
s32 func00007084(OSPfs *pfs);

#if VERSION >= VERSION_NTSC_1_0
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, s32 channel, s32 *arg3)
#else
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, s32 channel)
#endif
{
	s32 ret;
	u16 sum;
	u16 isum;
	u8 temp[32];
	__OSPackId *id;
	__OSPackId newid;

	ret = 0;

	__osSiGetAccess();
	ret = __osPfsGetStatus(queue, channel);
	__osSiRelAccess();

	if (ret != 0) {
		return ret;
	}

	pfs->queue = queue;
	pfs->channel = channel;
	pfs->status = 0;

	ERRCK(__osPfsCheckRamArea(pfs));
	ERRCK(__osPfsSelectBank(pfs, 0));
	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
	__osIdCheckSum((u16*)temp, &sum, &isum);

	id = (__OSPackId *)temp;

	if (id->checksum != sum || id->inverted_checksum != isum) {
		ret = __osCheckPackId(pfs, id);

		if (ret != 0) {
			pfs->status |= 4;
			return ret;
		}
	}

	if ((id->deviceid & 1) == 0) {
		ret = __osRepairPackId(pfs, id, &newid);

		if (ret != 0) {
			if (ret == 10) {
				pfs->status |= 4;
			}

			return ret;
		}

		id = &newid;

		if ((id->deviceid & 1) == 0) {
			return PFS_ERR_DEVICE;
		}
	}

	bcopy(id, pfs->id, 0x20);

	pfs->version = id->version;
	pfs->banks = id->banks;
	pfs->inode_start_page = pfs->banks * 2 + 3;
	pfs->dir_size = 0x10;
	pfs->inode_table = 8;
	pfs->minode_table = pfs->banks * PFS_ONE_PAGE + 8;
	pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;

#if VERSION >= VERSION_NTSC_1_0
	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 7, pfs->label));
	ret = osPfsChecker(pfs);
	pfs->status |= PFS_INITIALIZED;

	if (arg3 != NULL) {
		*arg3 = func00007084(pfs);
	}
#else

	ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);

	if (ret != 0) {
		return ret;
	}

	crashPrint("pfsinitpak.c -> ret = %d\n", ret);
	ret = osPfsChecker(pfs);
	pfs->status |= PFS_INITIALIZED;
#endif

	return ret;
}

s32 __osPfsCheckRamArea(OSPfs* pfs)
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

#if VERSION >= VERSION_NTSC_1_0
s32 func00007084(OSPfs *pfs)
{
	s32 ret;
	u32 buffer[7];

	ret = __osContRamRead(pfs->queue, pfs->channel, 1, (u8 *) buffer);

	if (ret != 0) {
		return 0;
	}

	return buffer[1];
}
#else
GLOBAL_ASM(
glabel func00007084
/*     71a0:	03e00008 */ 	jr	$ra
/*     71a4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
