#include <os_internal.h>
#include "controller.h"

static s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int fileSizeInPages, int *startPage, u8 bank, int *decleared, int *finalPage);

s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, int num_bytes, s32 *file_no)
{
	int startPage;
	int decleared;
	int prevPage;
	s32 oldPrevPage = 0;
	s32 ret = 0;
	s32 fileSizeInPages;
	__OSInode inode;
	__OSInode backupInode;
	__OSDir dir;
	u8 bank;
	u8 prevBank = 0;
	s32 firsttime = 0;
	s32 bytes;
	__OSInodeUnit fpage;

	if (company_code == 0 || game_code == 0) {
		return PFS_ERR_INVALID;
	}

	fileSizeInPages = (num_bytes + 255) / (BLOCKSIZE * PFS_ONE_PAGE);

	if ((ret = osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, file_no)) != 0
			&& ret != PFS_ERR_INVALID) {
		return ret;
	}

	if (*file_no != -1) {
		return PFS_ERR_EXIST;
	}

	ret = osPfsFreeBlocks(pfs, &bytes);

	if (num_bytes > bytes) {
		return PFS_DATA_FULL;
	}

	if (fileSizeInPages == 0) {
		return (PFS_ERR_INVALID);
	}

	if ((ret = osPfsFindFile(pfs, 0, 0, 0, 0, file_no)) != 0 && ret != PFS_ERR_INVALID) {
		return ret;
	}

	if (*file_no == -1) {
		return PFS_DIR_FULL;
	}

	for (bank = 0; bank < pfs->banks; bank++) {
		if ((ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank)) != 0) {
			return ret;
		}

		ret = __osPfsDeclearPage(pfs, &inode, fileSizeInPages, &startPage, bank, &decleared, &prevPage);

		if (ret) {
			return ret;
		}

		if (startPage != -1) { /* There is free space */
			if (firsttime == 0) {
				fpage.inode_t.page = (u8)startPage;
				fpage.inode_t.bank = bank;
			} else { /* Writing previous bank inode */
				backupInode.inode_page[oldPrevPage].inode_t.bank = bank;
				backupInode.inode_page[oldPrevPage].inode_t.page = (u8)startPage;

				if ((ret = __osPfsRWInode(pfs, &backupInode, PFS_WRITE, prevBank)) != 0) {
					return ret;
				}
			}

			if (fileSizeInPages > decleared) {
				bcopy(&inode, &backupInode, sizeof(__OSInode));
				oldPrevPage = prevPage;
				prevBank = bank;
				fileSizeInPages -= decleared;
				firsttime++;
			} else {
				fileSizeInPages = 0;

				if ((ret = __osPfsRWInode(pfs, &inode, PFS_WRITE, bank)) != 0) {
					return ret;
				}

				break;
			}
		}
	}

	if (fileSizeInPages > 0 || startPage == -1) {
		return PFS_ERR_INCONSISTENT;
	}

	dir.start_page = fpage;
	dir.company_code = company_code;
	dir.game_code = game_code;
	dir.data_sum = 0;

	bcopy(game_name, dir.game_name, PFS_FILE_NAME_LEN);
	bcopy(ext_name, dir.ext_name, PFS_FILE_EXT_LEN);

	return __osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + *file_no, (u8*)&dir, 0);
}

static s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int fileSizeInPages, int *startPage, u8 bank, int *decleared, int *finalPage)
{
	s32 j;
	s32 spage, prevPage;
	s32 ret = 0;
	s32 offset = (bank > 0) ? 1 : pfs->inode_start_page;

	for (j = offset; j < ARRLEN(inode->inode_page); j++) {
		if (inode->inode_page[j].ipage == 3) {
			break;
		}
	}

	if (j == ARRLEN(inode->inode_page)) {
		*startPage = -1;
		return ret;
	}

	spage = j;
	*decleared = 1;
	prevPage = j;
	j++;

	while (fileSizeInPages > *decleared && j < ARRLEN(inode->inode_page)) {
		if (inode->inode_page[j].ipage == 3) {
			inode->inode_page[prevPage].inode_t.bank = (u8)bank;
			inode->inode_page[prevPage].inode_t.page = (u8)j;
			prevPage = j;
			(*decleared)++;
		}

		j++;
	}

	*startPage = spage;

	if (j == ARRLEN(inode->inode_page) && fileSizeInPages > *decleared) {
		*finalPage = prevPage;
	} else {
		inode->inode_page[prevPage].ipage = 1;
		*finalPage = 0;
	}

	return ret;
}
