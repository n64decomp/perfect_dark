#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4e090.h"
#include "data.h"
#include "types.h"

s32 g_PfsPrevChannel = -1;
u8 g_PfsPrevBank = 250;

u16 __osSumCalc(u8 *ptr, int length)
{
	int i;
	u32 sum;
	u8 *tmp;

	sum = 0;
	tmp = ptr;

	for (i = 0; i < length; i++) {
		sum += *tmp++;
	}

	return sum & 0xffff;
}

s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum)
{
	u16 data = 0;
	u32 i;

	*csum = *icsum = 0;

	for (i = 0; i < ((sizeof(__OSPackId) - sizeof(u32)) / sizeof(u8)); i += 2) {
		data = *(u16 *)((u32)ptr + i);
		*csum += data;
		*icsum += ~data;
	}

	return 0;
}

s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid)
{
	s32 ret;
	u8 temp[32];
	u8 comp[32];
	u8 mask;
	int i;
	int j;
	u16 index[4];

	ret = 0;
	mask = 0;
	j = 0;

	newid->repaired = -1;
	newid->random = osGetCount();
	newid->serial_mid = badid->serial_mid;
	newid->serial_low = badid->serial_low;

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	do {
		ERRCK(__osPfsSelectBank(pfs, j));

		ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)&temp));

		temp[0] = j | 0x80;

		for (i = 1; i < ARRLEN(temp); i++) {
			temp[i] = ~temp[i];
		}

		ERRCK(__osContRamWrite(pfs->queue, pfs->channel, 0, (u8*)temp, FALSE));
		ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)&comp));

		for (i = 0; i < ARRLEN(temp); i++) {
			if (comp[i] != temp[i]) {
				break;
			}
		}

		if (i != ARRLEN(temp)) {
			break;
		}

		if (j > 0) {
			ERRCK(__osPfsSelectBank(pfs, 0));

			ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)temp));

			if (temp[0] != 128) {
				break;
			}
		}

		j++;
	} while (j < PFS_MAX_BANKS);

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	if (j > 0) {
		mask = 1;
	} else {
		mask = 0;
	}

	newid->deviceid = (badid->deviceid & (u16)~1) | mask;
	newid->banks = j;
	newid->version = badid->version;

	__osIdCheckSum((u16*)newid, &newid->checksum, &newid->inverted_checksum);

	index[0] = 1;
	index[1] = 3;
	index[2] = 4;
	index[3] = 6;

	for (i = 0; i < ARRLEN(index); i++) {
		ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[i], (u8*)newid, TRUE));
	}

	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));

	for (i = 0; i < ARRLEN(temp); i++) {
		if (temp[i] != ((u8 *)newid)[i]) {
			return PFS_ERR_DEVICE;
		}
	}

	return 0;
}

s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp)
{
	u16 index[4];
	s32 ret;
	u16 sum;
	u16 isum;
	int i;
	int j;

	ret = 0;

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	index[0] = 1;
	index[1] = 3;
	index[2] = 4;
	index[3] = 6;

	for (i = 1; i < ARRLEN(index); i++) {
		ERRCK(__osContRamRead(pfs->queue, pfs->channel, index[i], (u8*)temp));
		__osIdCheckSum((u16 *)temp, &sum, &isum);

		if (temp->checksum == sum && temp->inverted_checksum == isum) {
			break;
		}
	}

	if (i == ARRLEN(index)) {
		return PFS_ERR_ID_FATAL;
	}

	for (j = 0; j < ARRLEN(index); j++) {
		if (j != i) {
			ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[j], (u8*)temp, TRUE));
		}
	}

	return 0;
}

s32 __osGetId(OSPfs *pfs)
{
	u16 sum;
	u16 isum;
	u8 temp[32];
	__OSPackId newid;
	s32 ret;
	__OSPackId *id;

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0))
	}

	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));

	__osIdCheckSum((u16*)temp, &sum, &isum);

	id = (__OSPackId*)temp;

	if (id->checksum != sum || id->inverted_checksum != isum) {
		ret = __osCheckPackId(pfs, id);

		if (ret == PFS_ERR_ID_FATAL) {
			ERRCK(__osRepairPackId(pfs, id, &newid));
			id = &newid;
		} else if (ret != 0) {
			return ret;
		}
	}

	if ((id->deviceid & 1) == 0) {
		ERRCK(__osRepairPackId(pfs, id, &newid));
		id = &newid;

		if ((id->deviceid & 1) == 0) {
			return PFS_ERR_DEVICE;
		}
	}

	bcopy(id, pfs->id, 0x20);

	pfs->version = id->version;
	pfs->banks = id->banks;
	pfs->inode_start_page = pfs->banks * 2 + 3;
	pfs->dir_size = 16;
	pfs->inode_table = 8;
	pfs->minode_table = pfs->banks * PFS_ONE_PAGE + 8;
	pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;

	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 7, pfs->label));

	return 0;
}

s32 __osCheckId(OSPfs *pfs)
{
	u8 temp[32];
	s32 ret;

	if (pfs->activebank != 0) {
		ret = __osPfsSelectBank(pfs, 0);

		if (ret == PFS_ERR_NEW_PACK) {
			ret = __osPfsSelectBank(pfs, 0);
		}

		if (ret != 0) {
			return ret;
		}
	}

	ret = __osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp);

	if (ret != 0) {
		if (ret != PFS_ERR_NEW_PACK) {
			return ret;
		}

		ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
	}

	if (bcmp(pfs->id, temp, 0x20) != 0) {
		return PFS_ERR_NEW_PACK;
	}

	return 0;
}

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank)
{
	u8 sum;
	int j;
	s32 ret;
	int offset;
	u8 *addr;
	static __OSInode prevnode;

	if (flag == 0 && bank == g_PfsPrevBank && pfs->channel == g_PfsPrevChannel) {
		bcopy(&prevnode, inode, sizeof(__OSInode));
		return 0;
	}

	if (pfs->activebank != 0) {
		ERRCK(__osPfsSelectBank(pfs, 0));
	}

	offset = (bank > 0) ? 1 : pfs->inode_start_page;

	if (flag == PFS_WRITE) {
		inode->inode_page[0].inode_t.page = __osSumCalc((u8*)&inode->inode_page[offset], (-offset) * 2 + 256);
	}

	for (j = 0; j < 8; j++) {
		addr = ((u8 *)inode->inode_page + j * 32);

		if (flag == PFS_WRITE) {
			ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, FALSE);
			ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, FALSE);
		} else {
			ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr);
		}

		if (ret != 0) {
			return ret;
		}
	}

	if (flag == PFS_READ) {
		sum = __osSumCalc((u8*)&inode->inode_page[offset], (-offset) * 2 + 256);

		if (sum != inode->inode_page[0].inode_t.page) {
			for (j = 0; j < PFS_ONE_PAGE; j++) {
				addr = ((u8 *)inode->inode_page + j * 32);
				ret = __osContRamRead(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr);
			}

			sum = __osSumCalc((u8*)&inode->inode_page[offset], (-offset) * 2 + 256);

			if (sum != inode->inode_page[0].inode_t.page) {
				return PFS_ERR_INCONSISTENT;
			}

			for (j = 0; j < PFS_ONE_PAGE; j++) {
				addr = ((u8 *)inode->inode_page + j * 32);
				ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
			}
		}
	}

	g_PfsPrevBank = bank;
	bcopy(inode, &prevnode, sizeof(__OSInode));
	g_PfsPrevChannel = pfs->channel;

	return 0;
}
