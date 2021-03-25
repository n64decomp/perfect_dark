#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4cc10.h"
#include "lib/lib_4d000.h"
#include "data.h"
#include "types.h"

s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 num_bytes, s32 *file_no)
{
	s32 startPage;
	s32 decleared;
	s32 prevPage;
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

	fileSizeInPages = (num_bytes + PFS_PAGE_SIZE - 1) / PFS_PAGE_SIZE;

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

GLOBAL_ASM(
glabel __osPfsDeclearPage
/*    4d334:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4d338:	afb00008 */ 	sw	$s0,0x8($sp)
/*    4d33c:	93b00023 */ 	lbu	$s0,0x23($sp)
/*    4d340:	afb1000c */ 	sw	$s1,0xc($sp)
/*    4d344:	00c08825 */ 	or	$s1,$a2,$zero
/*    4d348:	1a000003 */ 	blez	$s0,.L0004d358
/*    4d34c:	240b0080 */ 	addiu	$t3,$zero,0x80
/*    4d350:	10000002 */ 	b	.L0004d35c
/*    4d354:	24020001 */ 	addiu	$v0,$zero,0x1
.L0004d358:
/*    4d358:	8c820060 */ 	lw	$v0,0x60($a0)
.L0004d35c:
/*    4d35c:	28410080 */ 	slti	$at,$v0,0x80
/*    4d360:	1020000a */ 	beqz	$at,.L0004d38c
/*    4d364:	00401825 */ 	or	$v1,$v0,$zero
/*    4d368:	00027040 */ 	sll	$t6,$v0,0x1
/*    4d36c:	00ae1021 */ 	addu	$v0,$a1,$t6
/*    4d370:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0004d374:
/*    4d374:	944f0000 */ 	lhu	$t7,0x0($v0)
/*    4d378:	514f0005 */ 	beql	$t2,$t7,.L0004d390
/*    4d37c:	240b0080 */ 	addiu	$t3,$zero,0x80
/*    4d380:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4d384:	146bfffb */ 	bne	$v1,$t3,.L0004d374
/*    4d388:	24420002 */ 	addiu	$v0,$v0,0x2
.L0004d38c:
/*    4d38c:	240b0080 */ 	addiu	$t3,$zero,0x80
.L0004d390:
/*    4d390:	146b0005 */ 	bne	$v1,$t3,.L0004d3a8
/*    4d394:	240a0003 */ 	addiu	$t2,$zero,0x3
/*    4d398:	2418ffff */ 	addiu	$t8,$zero,-1
/*    4d39c:	acf80000 */ 	sw	$t8,0x0($a3)
/*    4d3a0:	10000030 */ 	b	.L0004d464
/*    4d3a4:	00001025 */ 	or	$v0,$zero,$zero
.L0004d3a8:
/*    4d3a8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    4d3ac:	00602025 */ 	or	$a0,$v1,$zero
/*    4d3b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*    4d3b4:	00604025 */ 	or	$t0,$v1,$zero
/*    4d3b8:	2a210002 */ 	slti	$at,$s1,0x2
/*    4d3bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4d3c0:	14200018 */ 	bnez	$at,.L0004d424
/*    4d3c4:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4d3c8:	28610080 */ 	slti	$at,$v1,0x80
/*    4d3cc:	10200015 */ 	beqz	$at,.L0004d424
/*    4d3d0:	00036040 */ 	sll	$t4,$v1,0x1
/*    4d3d4:	00ac1021 */ 	addu	$v0,$a1,$t4
/*    4d3d8:	944d0000 */ 	lhu	$t5,0x0($v0)
.L0004d3dc:
/*    4d3dc:	00087040 */ 	sll	$t6,$t0,0x1
/*    4d3e0:	00ae4821 */ 	addu	$t1,$a1,$t6
/*    4d3e4:	554d0008 */ 	bnel	$t2,$t5,.L0004d408
/*    4d3e8:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    4d3ec:	a1300000 */ 	sb	$s0,0x0($t1)
/*    4d3f0:	a1230001 */ 	sb	$v1,0x1($t1)
/*    4d3f4:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*    4d3f8:	00604025 */ 	or	$t0,$v1,$zero
/*    4d3fc:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    4d400:	acd80000 */ 	sw	$t8,0x0($a2)
/*    4d404:	8cd90000 */ 	lw	$t9,0x0($a2)
.L0004d408:
/*    4d408:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4d40c:	24420002 */ 	addiu	$v0,$v0,0x2
/*    4d410:	0331082a */ 	slt	$at,$t9,$s1
/*    4d414:	10200003 */ 	beqz	$at,.L0004d424
/*    4d418:	28610080 */ 	slti	$at,$v1,0x80
/*    4d41c:	5420ffef */ 	bnezl	$at,.L0004d3dc
/*    4d420:	944d0000 */ 	lhu	$t5,0x0($v0)
.L0004d424:
/*    4d424:	146b0008 */ 	bne	$v1,$t3,.L0004d448
/*    4d428:	ace40000 */ 	sw	$a0,0x0($a3)
/*    4d42c:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*    4d430:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    4d434:	0191082a */ 	slt	$at,$t4,$s1
/*    4d438:	50200004 */ 	beqzl	$at,.L0004d44c
/*    4d43c:	00087840 */ 	sll	$t7,$t0,0x1
/*    4d440:	10000007 */ 	b	.L0004d460
/*    4d444:	ada80000 */ 	sw	$t0,0x0($t5)
.L0004d448:
/*    4d448:	00087840 */ 	sll	$t7,$t0,0x1
.L0004d44c:
/*    4d44c:	00afc021 */ 	addu	$t8,$a1,$t7
/*    4d450:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4d454:	a70e0000 */ 	sh	$t6,0x0($t8)
/*    4d458:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    4d45c:	af200000 */ 	sw	$zero,0x0($t9)
.L0004d460:
/*    4d460:	00001025 */ 	or	$v0,$zero,$zero
.L0004d464:
/*    4d464:	8fb00008 */ 	lw	$s0,0x8($sp)
/*    4d468:	8fb1000c */ 	lw	$s1,0xc($sp)
/*    4d46c:	03e00008 */ 	jr	$ra
/*    4d470:	27bd0010 */ 	addiu	$sp,$sp,0x10
);
