#include <os_internal.h>
#include "controller.h"
#include "siint.h"

s32 osPfsReSizeFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, int length)
{
	s32 startpage;
	s32 prevbankfinalpage;
	s32 numpagestoallocate;
	__OSInode inode;
	__OSInode previnode;
	__OSDir dir;
	s32 file_no;
	s32 oldsizeinpages;
	__OSInodeUnit sp98;
	__OSInodeUnit page;
	s32 remaining;
	s32 bytes_not_used;
	u8 bank;
	s32 ret;
	s32 decleared;
	s32 numbanksprocessed;
	s32 numbanksadded;
	s32 minpage;
	__OSInodeUnit lastpage;
	s32 finalpage;
	s32 i;
	u8 prevbank;
	u8 origlastbank;
	s32 numbankchanges;
	__OSInodeUnit sp5c;
	s32 newsizeinpages;

	numbanksprocessed = 0;
	numbanksadded = 0;
	numbankchanges = 0;

	if (company_code == 0 || game_code == 0) {
		return PFS_ERR_INVALID;
	}

	newsizeinpages = (length + (PFS_ONE_PAGE * BLOCKSIZE - 1)) / (PFS_ONE_PAGE * BLOCKSIZE);

	if ((pfs->status & PFS_INITIALIZED) == 0) {
		return PFS_ERR_INVALID;
	}

	if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) {
		return PFS_ERR_NEW_PACK;
	}

	ret = osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, &file_no);

	if (ret != 0 && ret != PFS_ERR_INVALID) {
		return ret;
	}

	if (file_no == -1) {
		return PFS_ERR_INVALID;
	}

	if (newsizeinpages != 0) {
		// Switch to bank 0 and load the directory for the file
		if (pfs->activebank != 0) {
			pfs->activebank = 0;

			ERRCK(__osPfsSelectBank(pfs, 0));
		}

		ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + file_no, (u8 *)&dir));

		if (dir.start_page.ipage < pfs->inode_start_page) {
			return PFS_ERR_INCONSISTENT;
		}

		// Count the current number of pages,
		// and note the first and last page of the final bank
		oldsizeinpages = 0;
		prevbankfinalpage = startpage = dir.start_page.inode_t.page;

		for (bank = dir.start_page.inode_t.bank; bank < pfs->banks;) {
			ERRCK(__osPfsRWInode(pfs, &inode, PFS_READ, bank));

			page = inode.inode_page[startpage];

			while (page.ipage >= pfs->inode_start_page) {
				oldsizeinpages++;
				prevbankfinalpage = page.inode_t.page;
				page = inode.inode_page[page.inode_t.page];

				if (page.inode_t.bank != bank) {
					bank = page.inode_t.bank;
					prevbankfinalpage = startpage = page.inode_t.page;
					break;
				}
			}

			// If this is the terminating ipage
			if (page.ipage == 0x0001) {
				oldsizeinpages++;
				break;
			}
		}

		origlastbank = bank;

		if (bank >= pfs->banks) {
			return PFS_ERR_INCONSISTENT;
		}

		// Handle increasing size
		if (newsizeinpages > oldsizeinpages) {
			remaining = newsizeinpages - oldsizeinpages;

			osPfsFreeBlocks(pfs, &bytes_not_used);

			if (bytes_not_used / (PFS_ONE_PAGE * BLOCKSIZE) < remaining) {
				return PFS_DATA_FULL;
			}

			// Retain a copy of this bank and inode so the tail page of
			// this list can be linked to the first page in the next inode
			prevbank = bank;

			for (i = 0; i < ARRLEN(inode.inode_page); i++) {
				previnode.inode_page[i].ipage = inode.inode_page[i].ipage;
			}

			// Iterate banks and allocate pages
			for (bank = 0; bank < pfs->banks; bank++) {
				// Load this bank's inodes
				ERRCK(__osPfsRWInode(pfs, &inode, PFS_READ, bank));

				// Allocate pages
				ERRCK(__osPfsDeclearPage(pfs, &inode, remaining, &startpage, bank, &decleared, &finalpage));

				// If some allocations were made (ie. the bank was not full)
				if (startpage != -1) {
					if (numbanksprocessed == 0 && origlastbank == bank) {
						// do nothing
					} else {
						// Link the final page of the previous inode to the new inode's first page
						numbanksadded++;

						previnode.inode_page[prevbankfinalpage].inode_t.bank = bank;
						previnode.inode_page[prevbankfinalpage].inode_t.page = startpage;

						ERRCK(__osPfsRWInode(pfs, &previnode, PFS_WRITE, prevbank));
					}

					// Copy inode to previnode
					for (i = 0; i < ARRLEN(inode.inode_page); i++) {
						previnode.inode_page[i].ipage = inode.inode_page[i].ipage;
					}

					if (decleared < remaining) {
						// Couldn't do all the allocations in the current bank,
						// so move on to the next bank
						remaining -= decleared;
					} else {
						// Finished allocations
						remaining = 0;
						prevbank = bank;
						break;
					}

					prevbankfinalpage = finalpage;
					prevbank = bank;
					numbanksprocessed++;
				}
			}

			if (remaining > 0 || startpage == -1) {
				return PFS_ERR_INCONSISTENT;
			}

			if (numbanksadded == 0) {
				previnode.inode_page[prevbankfinalpage].inode_t.bank = bank;
				previnode.inode_page[prevbankfinalpage].inode_t.page = startpage;
			}

			ERRCK(__osPfsRWInode(pfs, &previnode, PFS_WRITE, prevbank));
		} else if (newsizeinpages < oldsizeinpages) {
			// Handle decreasing size

			// Iterate past the pages that will be retained
			sp5c = dir.start_page;

			for (bank = dir.start_page.inode_t.bank; bank < pfs->banks;) {
				ERRCK(__osPfsRWInode(pfs, &inode, PFS_READ, bank));

				newsizeinpages--;
				sp98 = sp5c;
				page = inode.inode_page[sp5c.inode_t.page];
				minpage = bank > 0 ? 1 : pfs->inode_start_page;

				if (page.inode_t.page < minpage && page.ipage != 0x0001) {
					return PFS_ERR_INCONSISTENT;
				}

				while (newsizeinpages > 0 && page.ipage >= pfs->inode_start_page) {
					newsizeinpages--;
					sp98 = page;
					page = inode.inode_page[page.inode_t.page];

					if (page.inode_t.bank != bank) {
						if (newsizeinpages == 1) {
							inode.inode_page[sp98.inode_t.page].ipage = 0x0001;

							ERRCK(__osPfsRWInode(pfs, &inode, PFS_WRITE, bank));
						}

						numbankchanges++;
						sp5c = page;
						bank = page.inode_t.bank;

						ERRCK(__osPfsRWInode(pfs, &inode, PFS_READ, bank));
						break;
					}
				}

				if (newsizeinpages == 0) {
					break;
				}
			}

			if (bank >= pfs->banks) {
				return PFS_ERR_INCONSISTENT;
			}

			// Write the terminator inode unit
			if (numbankchanges == 0) {
				inode.inode_page[sp98.inode_t.page].ipage = 0x0001;
			} else {
				inode.inode_page[page.inode_t.page].ipage = 0x0001;
			}

			if (page.ipage == 0x0001) {
				// Mark page as free
				inode.inode_page[sp98.inode_t.page].ipage = 0x0003;

				ERRCK(__osPfsRWInode(pfs, &inode, PFS_WRITE, bank));
			} else {
				// Release pages
				sp5c = page;

				for (bank = page.inode_t.bank; bank < pfs->banks;) {
					ERRCK(__osPfsReleasePages(pfs, &inode, sp5c.inode_t.page, bank, &lastpage));
					ERRCK(__osPfsRWInode(pfs, &inode, PFS_WRITE, bank));

					if (lastpage.ipage == 0x0001) {
						break;
					}

					bank = lastpage.inode_t.bank;
					sp5c = lastpage;

					ERRCK(__osPfsRWInode(pfs, &inode, PFS_READ, bank));
				}

				if (bank >= pfs->banks) {
					return PFS_ERR_INCONSISTENT;
				}
			}

			dir.data_sum = dir.data_sum > 0 ? dir.data_sum : -dir.data_sum;

			ERRCK(__osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + file_no, (u8 *)&dir, 0));
		}

		return ret;
	}

	return PFS_ERR_INVALID;
}
