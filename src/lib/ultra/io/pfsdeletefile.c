#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

s32 osPfsDeleteFile(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	s32 file_no;
	s32 ret;
	__OSInode inode;
	__OSDir dir;
	__OSInodeUnit last_page;
	u8 startpage;
	u8 bank;

	if (company_code == 0 || game_code == 0) {
		return PFS_ERR_INVALID;
	}

	if ((ret = osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, &file_no)) != 0) {
		return ret;
	}

	if (pfs->activebank != 0 && (ret = __osPfsSelectBank(pfs, 0)) != 0) {
		return ret;
	}

	if ((ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + file_no, (u8*)&dir)) != 0) {
		return ret;
	}

	startpage = dir.start_page.inode_t.page;

	for (bank = dir.start_page.inode_t.bank; bank < pfs->banks;) {
		if ((ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank)) != 0) {
			return ret;
		}

		if ((ret = __osPfsReleasePages(pfs, &inode, startpage, bank, &last_page)) != 0) {
			return ret;
		}

		if ((ret = __osPfsRWInode(pfs, &inode, PFS_WRITE, bank)) != 0) {
			return ret;
		}

		if (last_page.ipage == 1) {
			break;
		}

		bank = last_page.inode_t.bank;
		startpage = last_page.inode_t.page;
	}

	if (bank >= pfs->banks) {
		return PFS_ERR_INCONSISTENT;
	}

	bzero(&dir, sizeof(__OSDir));

	ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + file_no, (u8*)&dir, 0);

	return ret;
}

s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 initial_page, u8 bank, __OSInodeUnit *final_page)
{
	__OSInodeUnit next;
	__OSInodeUnit prev;
	s32 ret = 0;

	next.ipage = (u16)((bank << 8) + initial_page);

	do {
		prev = next;
		next = inode->inode_page[next.inode_t.page];
		inode->inode_page[prev.inode_t.page].ipage = PFS_PAGE_NOT_USED;
	} while (next.ipage >= pfs->inode_start_page && next.inode_t.bank == bank);

	*final_page = next;

	return ret;
}
