#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache);
s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);

s32 osPfsChecker(OSPfs *pfs)
{
	int j;
	s32 ret;
	__OSInodeUnit next_page;
	__OSInode checked_inode;
	__OSInode tmp_inode;
	__OSDir tmp_dir;
	__OSInodeUnit file_next_node[16];
	__OSInodeCache cache;
	int fixed;
	u8 bank;
	s32 cc;
	s32 cl;
	int offset;
	u8 prevbank;

	fixed = 0;
	prevbank = 254;

	ret = __osCheckId(pfs);

	if (ret == PFS_ERR_NEW_PACK) {
		ret = __osGetId(pfs);
	}

	if (ret != 0) {
		return ret;
	}

	ERRCK(corrupted_init(pfs, &cache));

	for (j = 0; j < pfs->dir_size; j++) {
		ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir));

		if (tmp_dir.company_code != 0 || tmp_dir.game_code != 0) {
			if (tmp_dir.company_code == 0 || tmp_dir.game_code == 0) {
				cc = -1;
			} else {
				next_page = tmp_dir.start_page;
				cc = 0;
				cl = 0;
				bank = 255;

				while (next_page.ipage >= pfs->inode_start_page
						&& next_page.inode_t.bank < pfs->banks
						&& next_page.inode_t.page > 0
						&& next_page.inode_t.page < 128) {
					if (bank != next_page.inode_t.bank) {
						bank = next_page.inode_t.bank;

						if (prevbank != bank) {
							ret = __osPfsRWInode(pfs, &tmp_inode, OS_READ, bank);
							prevbank = bank;
						}

						if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
							return ret;
						}
					}

					cc = corrupted(pfs, next_page, &cache) - cl;

					if (cc != 0) {
						break;
					}

					cl = 1;
					next_page = tmp_inode.inode_page[next_page.inode_t.page];
				}
			}

			if (cc != 0 || next_page.ipage != 1) {
				bzero(&tmp_dir, sizeof(__OSDir));

				if (pfs->activebank != 0) {
					ERRCK(__osPfsSelectBank(pfs, 0));
				}

				ERRCK(__osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir, FALSE));

				fixed++;
			}
		}
	}

	for (j = 0; j < pfs->dir_size; j++) {
		ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir));

		if (tmp_dir.company_code != 0
				&& tmp_dir.game_code != 0
				&& tmp_dir.start_page.ipage >= ((__OSInodeUnit *)&(pfs->inode_start_page) + 1)->ipage) {
			file_next_node[j].ipage = tmp_dir.start_page.ipage;
		} else {
			file_next_node[j].ipage = 0;
		}
	}

	for (bank = 0; bank < pfs->banks; bank++) {
		ret = __osPfsRWInode(pfs, &tmp_inode, 0, bank);

		if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
			return ret;
		}

		if (bank > 0) {
			offset = 1;
		} else {
			offset = pfs->inode_start_page;
		}

		for (j = 0; j < offset; j++) {
			checked_inode.inode_page[j].ipage = tmp_inode.inode_page[j].ipage;
		}

		for (; j < 128; j++) {
			checked_inode.inode_page[j].ipage = 3;
		}

		for (j = 0; j < pfs->dir_size; j++) {
			while (file_next_node[j].inode_t.bank == bank && file_next_node[j].ipage >= ((__OSInodeUnit *)&(pfs->inode_start_page) + 1)->ipage) {
				u8 pp = file_next_node[j].inode_t.page;
				file_next_node[j] = checked_inode.inode_page[pp] = tmp_inode.inode_page[pp];
			}
		}

		ERRCK(__osPfsRWInode(pfs, &checked_inode, OS_WRITE, bank));
	}

	if (fixed) {
		pfs->status |= PFS_CORRUPTED;
	} else {
		pfs->status &= ~PFS_CORRUPTED;
	}

	return 0;
}

s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache)
{
	int i;
	int n;
	int offset;
	u8 bank;
	__OSInodeUnit tpage;
	__OSInode tmp_inode;
	s32 ret;

	for (i = 0; i < ARRLEN(cache->map); i++) {
		cache->map[i] = 0;
	}

	cache->bank = -1;

	for (bank = 0; bank < pfs->banks; bank++) {
		if (bank > 0) {
			offset = 1;
		} else {
			offset = pfs->inode_start_page;
		}

		ret = __osPfsRWInode(pfs, &tmp_inode, OS_READ, bank);

		if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
			return ret;
		}

		for (i = offset; i < ARRLEN(tmp_inode.inode_page); i++) {
			tpage = tmp_inode.inode_page[i];

			if (tpage.ipage >= pfs->inode_start_page && tpage.inode_t.bank != bank) {
				n = (tpage.inode_t.page / 4) + ((tpage.inode_t.bank % PFS_ONE_PAGE) * BLOCKSIZE);
				cache->map[n] |= 1 << (bank % PFS_ONE_PAGE);
			}
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel corrupted
/*    4def4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    4def8:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    4defc:	93b8003c */ 	lbu	$t8,0x3c($sp)
/*    4df00:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4df04:	93ae003d */ 	lbu	$t6,0x3d($sp)
/*    4df08:	0080a025 */ 	or	$s4,$a0,$zero
/*    4df0c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    4df10:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4df14:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4df18:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4df1c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4df20:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4df24:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4df28:	92890064 */ 	lbu	$t1,0x64($s4)
/*    4df2c:	00c09825 */ 	or	$s3,$a2,$zero
/*    4df30:	00008025 */ 	or	$s0,$zero,$zero
/*    4df34:	05c10003 */ 	bgez	$t6,.L0004df44
/*    4df38:	000e7883 */ 	sra	$t7,$t6,0x2
/*    4df3c:	25c10003 */ 	addiu	$at,$t6,0x3
/*    4df40:	00017883 */ 	sra	$t7,$at,0x2
.L0004df44:
/*    4df44:	07010004 */ 	bgez	$t8,.L0004df58
/*    4df48:	33190007 */ 	andi	$t9,$t8,0x7
/*    4df4c:	13200002 */ 	beqz	$t9,.L0004df58
/*    4df50:	00000000 */ 	nop
/*    4df54:	2739fff8 */ 	addiu	$t9,$t9,-8
.L0004df58:
/*    4df58:	00194140 */ 	sll	$t0,$t9,0x5
/*    4df5c:	01e8b021 */ 	addu	$s6,$t7,$t0
/*    4df60:	19200040 */ 	blez	$t1,.L0004e064
/*    4df64:	00009025 */ 	or	$s2,$zero,$zero
/*    4df68:	00001025 */ 	or	$v0,$zero,$zero
/*    4df6c:	24150003 */ 	addiu	$s5,$zero,0x3
.L0004df70:
/*    4df70:	18400003 */ 	blez	$v0,.L0004df80
/*    4df74:	93aa003c */ 	lbu	$t2,0x3c($sp)
/*    4df78:	10000002 */ 	b	.L0004df84
/*    4df7c:	24110001 */ 	addiu	$s1,$zero,0x1
.L0004df80:
/*    4df80:	8e910060 */ 	lw	$s1,0x60($s4)
.L0004df84:
/*    4df84:	1142000c */ 	beq	$t2,$v0,.L0004dfb8
/*    4df88:	02765821 */ 	addu	$t3,$s3,$s6
/*    4df8c:	916c0101 */ 	lbu	$t4,0x101($t3)
/*    4df90:	04410004 */ 	bgez	$v0,.L0004dfa4
/*    4df94:	304d0007 */ 	andi	$t5,$v0,0x7
/*    4df98:	11a00002 */ 	beqz	$t5,.L0004dfa4
/*    4df9c:	00000000 */ 	nop
/*    4dfa0:	25adfff8 */ 	addiu	$t5,$t5,-8
.L0004dfa4:
/*    4dfa4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4dfa8:	01aec004 */ 	sllv	$t8,$t6,$t5
/*    4dfac:	0198c824 */ 	and	$t9,$t4,$t8
/*    4dfb0:	53200027 */ 	beqzl	$t9,.L0004e050
/*    4dfb4:	928b0064 */ 	lbu	$t3,0x64($s4)
.L0004dfb8:
/*    4dfb8:	926f0100 */ 	lbu	$t7,0x100($s3)
/*    4dfbc:	02802025 */ 	or	$a0,$s4,$zero
/*    4dfc0:	02602825 */ 	or	$a1,$s3,$zero
/*    4dfc4:	11e2000a */ 	beq	$t7,$v0,.L0004dff0
/*    4dfc8:	00003025 */ 	or	$a2,$zero,$zero
/*    4dfcc:	0c01324d */ 	jal	__osPfsRWInode
/*    4dfd0:	324700ff */ 	andi	$a3,$s2,0xff
/*    4dfd4:	50400006 */ 	beqzl	$v0,.L0004dff0
/*    4dfd8:	a2720100 */ 	sb	$s2,0x100($s3)
/*    4dfdc:	50550004 */ 	beql	$v0,$s5,.L0004dff0
/*    4dfe0:	a2720100 */ 	sb	$s2,0x100($s3)
/*    4dfe4:	10000021 */ 	b	.L0004e06c
/*    4dfe8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    4dfec:	a2720100 */ 	sb	$s2,0x100($s3)
.L0004dff0:
/*    4dff0:	2a010002 */ 	slti	$at,$s0,0x2
/*    4dff4:	10200010 */ 	beqz	$at,.L0004e038
/*    4dff8:	2a210080 */ 	slti	$at,$s1,0x80
/*    4dffc:	1020000e */ 	beqz	$at,.L0004e038
/*    4e000:	00111040 */ 	sll	$v0,$s1,0x1
/*    4e004:	02621821 */ 	addu	$v1,$s3,$v0
/*    4e008:	97a8003c */ 	lhu	$t0,0x3c($sp)
.L0004e00c:
/*    4e00c:	94690000 */ 	lhu	$t1,0x0($v1)
/*    4e010:	24420002 */ 	addiu	$v0,$v0,0x2
/*    4e014:	55090003 */ 	bnel	$t0,$t1,.L0004e024
/*    4e018:	2a010002 */ 	slti	$at,$s0,0x2
/*    4e01c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4e020:	2a010002 */ 	slti	$at,$s0,0x2
.L0004e024:
/*    4e024:	10200004 */ 	beqz	$at,.L0004e038
/*    4e028:	24630002 */ 	addiu	$v1,$v1,0x2
/*    4e02c:	28410100 */ 	slti	$at,$v0,0x100
/*    4e030:	5420fff6 */ 	bnezl	$at,.L0004e00c
/*    4e034:	97a8003c */ 	lhu	$t0,0x3c($sp)
.L0004e038:
/*    4e038:	2a010002 */ 	slti	$at,$s0,0x2
/*    4e03c:	54200004 */ 	bnezl	$at,.L0004e050
/*    4e040:	928b0064 */ 	lbu	$t3,0x64($s4)
/*    4e044:	10000008 */ 	b	.L0004e068
/*    4e048:	24020002 */ 	addiu	$v0,$zero,0x2
/*    4e04c:	928b0064 */ 	lbu	$t3,0x64($s4)
.L0004e050:
/*    4e050:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4e054:	324200ff */ 	andi	$v0,$s2,0xff
/*    4e058:	004b082a */ 	slt	$at,$v0,$t3
/*    4e05c:	1420ffc4 */ 	bnez	$at,.L0004df70
/*    4e060:	00409025 */ 	or	$s2,$v0,$zero
.L0004e064:
/*    4e064:	02001025 */ 	or	$v0,$s0,$zero
.L0004e068:
/*    4e068:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004e06c:
/*    4e06c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4e070:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4e074:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4e078:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4e07c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4e080:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4e084:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4e088:	03e00008 */ 	jr	$ra
/*    4e08c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
