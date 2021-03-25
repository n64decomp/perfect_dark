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

GLOBAL_ASM(
glabel corrupted_init
/*    4dc28:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*    4dc2c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4dc30:	00809825 */ 	or	$s3,$a0,$zero
/*    4dc34:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4dc38:	00a0a025 */ 	or	$s4,$a1,$zero
/*    4dc3c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4dc40:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    4dc44:	afb70034 */ 	sw	$s7,0x34($sp)
/*    4dc48:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4dc4c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4dc50:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4dc54:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4dc58:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4dc5c:	24040100 */ 	addiu	$a0,$zero,0x100
/*    4dc60:	00001025 */ 	or	$v0,$zero,$zero
/*    4dc64:	00a01825 */ 	or	$v1,$a1,$zero
.L0004dc68:
/*    4dc68:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4dc6c:	a0600102 */ 	sb	$zero,0x102($v1)
/*    4dc70:	a0600103 */ 	sb	$zero,0x103($v1)
/*    4dc74:	a0600104 */ 	sb	$zero,0x104($v1)
/*    4dc78:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4dc7c:	1444fffa */ 	bne	$v0,$a0,.L0004dc68
/*    4dc80:	a06000fd */ 	sb	$zero,0xfd($v1)
/*    4dc84:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    4dc88:	a28e0100 */ 	sb	$t6,0x100($s4)
/*    4dc8c:	926f0064 */ 	lbu	$t7,0x64($s3)
/*    4dc90:	0000b825 */ 	or	$s7,$zero,$zero
/*    4dc94:	00008025 */ 	or	$s0,$zero,$zero
/*    4dc98:	19e00089 */ 	blez	$t7,.L0004dec0
/*    4dc9c:	241e0080 */ 	addiu	$s8,$zero,0x80
/*    4dca0:	27b6015a */ 	addiu	$s6,$sp,0x15a
/*    4dca4:	27b50058 */ 	addiu	$s5,$sp,0x58
/*    4dca8:	27b20158 */ 	addiu	$s2,$sp,0x158
.L0004dcac:
/*    4dcac:	1a000003 */ 	blez	$s0,.L0004dcbc
/*    4dcb0:	02602025 */ 	or	$a0,$s3,$zero
/*    4dcb4:	10000002 */ 	b	.L0004dcc0
/*    4dcb8:	24110001 */ 	addiu	$s1,$zero,0x1
.L0004dcbc:
/*    4dcbc:	8e710060 */ 	lw	$s1,0x60($s3)
.L0004dcc0:
/*    4dcc0:	02a02825 */ 	or	$a1,$s5,$zero
/*    4dcc4:	00003025 */ 	or	$a2,$zero,$zero
/*    4dcc8:	0c01324d */ 	jal	__osPfsRWInode
/*    4dccc:	32e700ff */ 	andi	$a3,$s7,0xff
/*    4dcd0:	10400005 */ 	beqz	$v0,.L0004dce8
/*    4dcd4:	24010003 */ 	addiu	$at,$zero,0x3
/*    4dcd8:	50410004 */ 	beql	$v0,$at,.L0004dcec
/*    4dcdc:	2a210080 */ 	slti	$at,$s1,0x80
/*    4dce0:	10000079 */ 	b	.L0004dec8
/*    4dce4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004dce8:
/*    4dce8:	2a210080 */ 	slti	$at,$s1,0x80
.L0004dcec:
/*    4dcec:	1020006e */ 	beqz	$at,.L0004dea8
/*    4dcf0:	02201025 */ 	or	$v0,$s1,$zero
/*    4dcf4:	03d11823 */ 	subu	$v1,$s8,$s1
/*    4dcf8:	30780001 */ 	andi	$t8,$v1,0x1
/*    4dcfc:	13000024 */ 	beqz	$t8,.L0004dd90
/*    4dd00:	0011c840 */ 	sll	$t9,$s1,0x1
/*    4dd04:	02b94021 */ 	addu	$t0,$s5,$t9
/*    4dd08:	95010000 */ 	lhu	$at,0x0($t0)
/*    4dd0c:	a6410000 */ 	sh	$at,0x0($s2)
/*    4dd10:	8e6c0060 */ 	lw	$t4,0x60($s3)
/*    4dd14:	97ab0158 */ 	lhu	$t3,0x158($sp)
/*    4dd18:	93ad0158 */ 	lbu	$t5,0x158($sp)
/*    4dd1c:	016c082a */ 	slt	$at,$t3,$t4
/*    4dd20:	5420001a */ 	bnezl	$at,.L0004dd8c
/*    4dd24:	26220001 */ 	addiu	$v0,$s1,0x1
/*    4dd28:	120d0017 */ 	beq	$s0,$t5,.L0004dd88
/*    4dd2c:	93ae0159 */ 	lbu	$t6,0x159($sp)
/*    4dd30:	05c10003 */ 	bgez	$t6,.L0004dd40
/*    4dd34:	000e7883 */ 	sra	$t7,$t6,0x2
/*    4dd38:	25c10003 */ 	addiu	$at,$t6,0x3
/*    4dd3c:	00017883 */ 	sra	$t7,$at,0x2
.L0004dd40:
/*    4dd40:	05a10004 */ 	bgez	$t5,.L0004dd54
/*    4dd44:	31b80007 */ 	andi	$t8,$t5,0x7
/*    4dd48:	13000002 */ 	beqz	$t8,.L0004dd54
/*    4dd4c:	00000000 */ 	nop
/*    4dd50:	2718fff8 */ 	addiu	$t8,$t8,-8
.L0004dd54:
/*    4dd54:	0018c940 */ 	sll	$t9,$t8,0x5
/*    4dd58:	01f91821 */ 	addu	$v1,$t7,$t9
/*    4dd5c:	02831021 */ 	addu	$v0,$s4,$v1
/*    4dd60:	90490101 */ 	lbu	$t1,0x101($v0)
/*    4dd64:	06010004 */ 	bgez	$s0,.L0004dd78
/*    4dd68:	32080007 */ 	andi	$t0,$s0,0x7
/*    4dd6c:	11000002 */ 	beqz	$t0,.L0004dd78
/*    4dd70:	00000000 */ 	nop
/*    4dd74:	2508fff8 */ 	addiu	$t0,$t0,-8
.L0004dd78:
/*    4dd78:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4dd7c:	010a5804 */ 	sllv	$t3,$t2,$t0
/*    4dd80:	012b6025 */ 	or	$t4,$t1,$t3
/*    4dd84:	a04c0101 */ 	sb	$t4,0x101($v0)
.L0004dd88:
/*    4dd88:	26220001 */ 	addiu	$v0,$s1,0x1
.L0004dd8c:
/*    4dd8c:	105e0046 */ 	beq	$v0,$s8,.L0004dea8
.L0004dd90:
/*    4dd90:	00027040 */ 	sll	$t6,$v0,0x1
/*    4dd94:	02ae2821 */ 	addu	$a1,$s5,$t6
/*    4dd98:	24a40002 */ 	addiu	$a0,$a1,0x2
.L0004dd9c:
/*    4dd9c:	94a10000 */ 	lhu	$at,0x0($a1)
/*    4dda0:	a6410000 */ 	sh	$at,0x0($s2)
/*    4dda4:	8e790060 */ 	lw	$t9,0x60($s3)
/*    4dda8:	97af0158 */ 	lhu	$t7,0x158($sp)
/*    4ddac:	93aa0158 */ 	lbu	$t2,0x158($sp)
/*    4ddb0:	01f9082a */ 	slt	$at,$t7,$t9
/*    4ddb4:	5420001a */ 	bnezl	$at,.L0004de20
/*    4ddb8:	94810000 */ 	lhu	$at,0x0($a0)
/*    4ddbc:	120a0017 */ 	beq	$s0,$t2,.L0004de1c
/*    4ddc0:	93a80159 */ 	lbu	$t0,0x159($sp)
/*    4ddc4:	05010003 */ 	bgez	$t0,.L0004ddd4
/*    4ddc8:	00084883 */ 	sra	$t1,$t0,0x2
/*    4ddcc:	25010003 */ 	addiu	$at,$t0,0x3
/*    4ddd0:	00014883 */ 	sra	$t1,$at,0x2
.L0004ddd4:
/*    4ddd4:	05410004 */ 	bgez	$t2,.L0004dde8
/*    4ddd8:	314b0007 */ 	andi	$t3,$t2,0x7
/*    4dddc:	11600002 */ 	beqz	$t3,.L0004dde8
/*    4dde0:	00000000 */ 	nop
/*    4dde4:	256bfff8 */ 	addiu	$t3,$t3,-8
.L0004dde8:
/*    4dde8:	000b6140 */ 	sll	$t4,$t3,0x5
/*    4ddec:	012c1821 */ 	addu	$v1,$t1,$t4
/*    4ddf0:	02831021 */ 	addu	$v0,$s4,$v1
/*    4ddf4:	904e0101 */ 	lbu	$t6,0x101($v0)
/*    4ddf8:	06010004 */ 	bgez	$s0,.L0004de0c
/*    4ddfc:	320d0007 */ 	andi	$t5,$s0,0x7
/*    4de00:	11a00002 */ 	beqz	$t5,.L0004de0c
/*    4de04:	00000000 */ 	nop
/*    4de08:	25adfff8 */ 	addiu	$t5,$t5,-8
.L0004de0c:
/*    4de0c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4de10:	01b87804 */ 	sllv	$t7,$t8,$t5
/*    4de14:	01cfc825 */ 	or	$t9,$t6,$t7
/*    4de18:	a0590101 */ 	sb	$t9,0x101($v0)
.L0004de1c:
/*    4de1c:	94810000 */ 	lhu	$at,0x0($a0)
.L0004de20:
/*    4de20:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4de24:	a6410000 */ 	sh	$at,0x0($s2)
/*    4de28:	8e690060 */ 	lw	$t1,0x60($s3)
/*    4de2c:	97ab0158 */ 	lhu	$t3,0x158($sp)
/*    4de30:	93ac0158 */ 	lbu	$t4,0x158($sp)
/*    4de34:	0169082a */ 	slt	$at,$t3,$t1
/*    4de38:	14200019 */ 	bnez	$at,.L0004dea0
/*    4de3c:	00000000 */ 	nop
/*    4de40:	120c0017 */ 	beq	$s0,$t4,.L0004dea0
/*    4de44:	93b80159 */ 	lbu	$t8,0x159($sp)
/*    4de48:	07010003 */ 	bgez	$t8,.L0004de58
/*    4de4c:	00186883 */ 	sra	$t5,$t8,0x2
/*    4de50:	27010003 */ 	addiu	$at,$t8,0x3
/*    4de54:	00016883 */ 	sra	$t5,$at,0x2
.L0004de58:
/*    4de58:	05810004 */ 	bgez	$t4,.L0004de6c
/*    4de5c:	318e0007 */ 	andi	$t6,$t4,0x7
/*    4de60:	11c00002 */ 	beqz	$t6,.L0004de6c
/*    4de64:	00000000 */ 	nop
/*    4de68:	25cefff8 */ 	addiu	$t6,$t6,-8
.L0004de6c:
/*    4de6c:	000e7940 */ 	sll	$t7,$t6,0x5
/*    4de70:	01af1821 */ 	addu	$v1,$t5,$t7
/*    4de74:	02831021 */ 	addu	$v0,$s4,$v1
/*    4de78:	90590101 */ 	lbu	$t9,0x101($v0)
/*    4de7c:	06010004 */ 	bgez	$s0,.L0004de90
/*    4de80:	32080007 */ 	andi	$t0,$s0,0x7
/*    4de84:	11000002 */ 	beqz	$t0,.L0004de90
/*    4de88:	00000000 */ 	nop
/*    4de8c:	2508fff8 */ 	addiu	$t0,$t0,-8
.L0004de90:
/*    4de90:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4de94:	010a5804 */ 	sllv	$t3,$t2,$t0
/*    4de98:	032b4825 */ 	or	$t1,$t9,$t3
/*    4de9c:	a0490101 */ 	sb	$t1,0x101($v0)
.L0004dea0:
/*    4dea0:	1496ffbe */ 	bne	$a0,$s6,.L0004dd9c
/*    4dea4:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0004dea8:
/*    4dea8:	926c0064 */ 	lbu	$t4,0x64($s3)
/*    4deac:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    4deb0:	32f000ff */ 	andi	$s0,$s7,0xff
/*    4deb4:	020c082a */ 	slt	$at,$s0,$t4
/*    4deb8:	1420ff7c */ 	bnez	$at,.L0004dcac
/*    4debc:	0200b825 */ 	or	$s7,$s0,$zero
.L0004dec0:
/*    4dec0:	00001025 */ 	or	$v0,$zero,$zero
/*    4dec4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004dec8:
/*    4dec8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4decc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4ded0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4ded4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4ded8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4dedc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4dee0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4dee4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    4dee8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    4deec:	03e00008 */ 	jr	$ra
/*    4def0:	27bd0168 */ 	addiu	$sp,$sp,0x168
);

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
