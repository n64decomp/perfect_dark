#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/libc/ll.h"
#include "lib/lib_4d480.h"
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

GLOBAL_ASM(
glabel __osPfsReleasePages
/*    4d658:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4d65c:	30e200ff */ 	andi	$v0,$a3,0xff
/*    4d660:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    4d664:	0002c200 */ 	sll	$t8,$v0,0x8
/*    4d668:	afa60018 */ 	sw	$a2,0x18($sp)
/*    4d66c:	afa7001c */ 	sw	$a3,0x1c($sp)
/*    4d670:	030ec821 */ 	addu	$t9,$t8,$t6
/*    4d674:	a7b9000c */ 	sh	$t9,0xc($sp)
/*    4d678:	24070003 */ 	addiu	$a3,$zero,0x3
/*    4d67c:	27a6000c */ 	addiu	$a2,$sp,0xc
/*    4d680:	27a30008 */ 	addiu	$v1,$sp,0x8
/*    4d684:	94c10000 */ 	lhu	$at,0x0($a2)
.L0004d688:
/*    4d688:	a4610000 */ 	sh	$at,0x0($v1)
/*    4d68c:	93ab000d */ 	lbu	$t3,0xd($sp)
/*    4d690:	000b6040 */ 	sll	$t4,$t3,0x1
/*    4d694:	00ac6821 */ 	addu	$t5,$a1,$t4
/*    4d698:	95a10000 */ 	lhu	$at,0x0($t5)
/*    4d69c:	a4c10000 */ 	sh	$at,0x0($a2)
/*    4d6a0:	93b90009 */ 	lbu	$t9,0x9($sp)
/*    4d6a4:	00194840 */ 	sll	$t1,$t9,0x1
/*    4d6a8:	00a94021 */ 	addu	$t0,$a1,$t1
/*    4d6ac:	a5070000 */ 	sh	$a3,0x0($t0)
/*    4d6b0:	8c8b0060 */ 	lw	$t3,0x60($a0)
/*    4d6b4:	97aa000c */ 	lhu	$t2,0xc($sp)
/*    4d6b8:	93ac000c */ 	lbu	$t4,0xc($sp)
/*    4d6bc:	014b082a */ 	slt	$at,$t2,$t3
/*    4d6c0:	54200004 */ 	bnezl	$at,.L0004d6d4
/*    4d6c4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    4d6c8:	504cffef */ 	beql	$v0,$t4,.L0004d688
/*    4d6cc:	94c10000 */ 	lhu	$at,0x0($a2)
/*    4d6d0:	8faf0020 */ 	lw	$t7,0x20($sp)
.L0004d6d4:
/*    4d6d4:	94c10000 */ 	lhu	$at,0x0($a2)
/*    4d6d8:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*    4d6dc:	00001025 */ 	or	$v0,$zero,$zero
/*    4d6e0:	03e00008 */ 	jr	$ra
/*    4d6e4:	a5e10000 */ 	sh	$at,0x0($t7)
);
