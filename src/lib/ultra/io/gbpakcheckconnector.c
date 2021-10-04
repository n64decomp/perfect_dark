#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

/**
 * The internal operations performed by the osGbpakCheckConnector function are
 * as follows.
 *
 * - Checks the ROM area addresses of the Game Boy Game Pak and performs the
 *   following processing for 0x0000, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800,
 *   0x1000, 0x2000, and 0x4000.
 *
 *   1. Compares data starting at the above addresses with neighboring data in
 *      32-byte units.
 *   2. If the data are identical, compares the next 32 bytes, and if this is
 *      also the same, compares the next 32 bytes. Up to 4 comparisons (ie, 128
 *      bytes) are performed. If all data are identical, the address line is
 *      considered insecurely connected and an error is returned. If different
 *      data are detected even once, it is determined that the data are being
 *      read properly and the function advances.
 *   3. Data at each of the above addresses are compared with the data starting
 *      at 0x0000 in 32-byte units.
 *   4. As in 2., up to 4 comparisons (128 bytes) are made. If all the data are
 *      identical, an error is returned. If different data are detected even
 *      once, it is determined that the data are being read properly and the
 *      function advances.
 *
 * - If a RAM area exists, the function checks the address of the Game Boy Game
 *   Pak RAM area and performs the following processing for 0x2000 and 0xa000.
 *
 *   1. Compares the data starting at the above addresses in 32-byte units.
 *   2. If the data are identical, compares the next 32 bytes, and if this is
 *      also the same, compares the next 32 bytes. Up to 4 comparisons (ie, 128
 *      bytes) are performed. If all the data are the same, the address line is
 *      evaluated to be insecurely connected and an error is returned. If
 *      different data are detected even once, it is determined that the data
 *      are being read properly and the function advances.
 */
s32 osGbpakCheckConnector(OSPfs *pfs, u8 *status)
{
	s32 ret;
	s32 thisslot = 1;
	s32 prevslot = 0;
	u16 thischunkaddr;
	u16 prevchunkaddr = 0;
	u16 offset;
	u16 blocknum;
	u8 blocks[3][4][0x20];
	u8 blocksloaded[3][4];
	bool stilllooking;

	ret = osGbpakGetStatus(pfs, status);

	if (ret == PFS_ERR_NEW_GBCART) {
		ret = osGbpakGetStatus(pfs, status);
	}

	if (ret == PFS_ERR_NEW_GBCART) {
		return PFS_ERR_CONTRFAIL;
	}

	if (ret == 0) {
		if ((*status & OS_GBPAK_POWER) == 0) {
			ret = osGbpakPower(pfs, OS_GBPAK_POWER_ON);

			if (ret != 0) {
				return ret;
			}
		}

		bzero(blocksloaded, 12);

		for (thischunkaddr = 0x80; thischunkaddr <= 0x4000; thischunkaddr *= 2) {
			blocknum = 0;
			offset = 0;

			do {
				// Load the current block
				ret = osGbpakReadWrite(pfs, PFS_READ, thischunkaddr + offset, blocks[thisslot][blocknum], 32);

				if (ret != 0) {
					return ret;
				}

				blocksloaded[thisslot][blocknum] = 1;

				// Load the same block from the previous chunk if not already loaded
				// (This only applies for the 0x0000 chunk)
				if (blocksloaded[prevslot][blocknum] == 0) {
					ret = osGbpakReadWrite(pfs, PFS_READ, prevchunkaddr + offset, blocks[prevslot][blocknum], 32);

					if (ret != 0) {
						return ret;
					}

					blocksloaded[prevslot][blocknum] = 1;
				}

				// Compare them and bail out if different
				if (bcmp(blocks[thisslot][blocknum], blocks[prevslot][blocknum], 32) != 0) {
					blocknum = 0;
					break;
				}

				stilllooking = blocknum < 3;
				offset += 0x20; blocknum++;
			} while (stilllooking);

			if (blocknum);
			if (blocknum);
			if (blocknum);
			if (blocknum);
			if (blocknum);
			if (blocknum);

			stilllooking = blocknum;

			if (stilllooking) {
				return PFS_ERR_CONTRFAIL;
			}

			// Now compare each block in this chunk with each block in the
			// 0x0000 chunk
			blocknum = 0;
			offset = 0;

			if (prevslot != 0) {
				do {
					// Make sure the current block is loaded
					if (blocksloaded[thisslot][blocknum] == 0) {
						ret = osGbpakReadWrite(pfs, PFS_READ, thischunkaddr + offset, blocks[thisslot][blocknum], 32);

						if (ret != 0) {
							return ret;
						}

						blocksloaded[thisslot][blocknum] = 1;
					}

					// Make sure this block in chunk 0x0000 is loaded
					if (blocksloaded[0][blocknum] == 0) {
						ret = osGbpakReadWrite(pfs, PFS_READ, offset, blocks[0][blocknum], 32);

						if (ret != 0) {
							return ret;
						}

						blocksloaded[0][blocknum] = 1;
					}

					// Compare them and bail out if different
					if (bcmp(blocks[thisslot][blocknum], blocks[0][blocknum], 32) != 0) {
						stilllooking = false;
						goto end;
					}

					stilllooking = blocknum < 3;
					offset += 0x20; blocknum++;
				} while (stilllooking);

				stilllooking = blocknum;
			}

end:
			if (stilllooking) {
				return PFS_ERR_CONTRFAIL;
			}

			if (prevslot != 0) {
				bzero(&blocksloaded[prevslot][0], 4);
			}

			prevchunkaddr = thischunkaddr;
			prevslot = thisslot;
			thisslot ^= 3; // toggle between 1 and 2
		}

		// Check RAM if present
		if (pfs->dir_size >= 2 || pfs->version == 2) {
			blocknum = 0;
			offset = 0;

			do {
				ret = osGbpakReadWrite(pfs, PFS_READ, 0xa000 + offset, blocks[thisslot][blocknum], 32);

				if (ret != 0) {
					return ret;
				}

				ret = osGbpakReadWrite(pfs, PFS_READ, 0x2000 + offset, blocks[prevslot][blocknum], 32);

				if (ret != 0) {
					return ret;
				}

				if (bcmp(blocks[thisslot][blocknum], blocks[prevslot][blocknum], 32) != 0) {
					blocknum = 0;
					break;
				}

				stilllooking = blocknum < 3;
				offset += 0x20; blocknum++;
			} while (stilllooking);

			stilllooking = blocknum;

			if (stilllooking) {
				return PFS_ERR_CONTRFAIL;
			}
		}

		ret = osGbpakGetStatus(pfs, status);

		if (ret == PFS_ERR_NEW_GBCART) {
			ret = PFS_ERR_CONTRFAIL;
		}
	}

	return ret;
}
