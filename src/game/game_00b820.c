#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chrai.h"
#include "game/game_00b820.h"
#include "game/playerreset.h"
#include "game/body.h"
#include "game/setuputils.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct prop *g_DangerousProps[MAX_DANGEROUSPROPS];

void resetSomeStageThings(void)
{
	s32 i;

	for (i = 0; i != MAX_DANGEROUSPROPS; i++) {
		g_DangerousProps[i] = NULL;
	}

	g_StageFlags = 0;

	g_EnemyAccuracyScale = 1;
	g_DamageReceivedScale = 1;
	g_DamageDealtScale = 1;
	g_AttackWalkDurationMultiplier = 1;

	var80062cbc = 0;
}

void stageAllocateBgChrs(void)
{
	bool modified;
	struct chrdata tmp;
	s32 i;

	g_BgChrs = NULL;
	g_BgChrnums = 0;
	g_NumBgChrs = 0;

	if (!g_StageSetup.ailists) {
		return;
	}

	// Count the number of background AI lists
	i = 0;

	while (g_StageSetup.ailists[i].list) {
		if (g_StageSetup.ailists[i].id >= 0x1000) {
			g_NumBgChrs++;
		}

		i++;
	}

	// Add one for cutscene
	g_NumBgChrs++;

	if (g_NumBgChrs > 0) {
		s32 count = 0;
		struct chrdata blankchr = {0};

		// Allocate BG chrs
		g_BgChrs = mempAlloc(ALIGN16(g_NumBgChrs * sizeof(struct chrdata)), MEMPOOL_STAGE);
		g_BgChrnums = mempAlloc(ALIGN16(g_NumBgChrs * sizeof(s16)), MEMPOOL_STAGE);

		// Initialise BG chrs
		i = 0;

		while (g_StageSetup.ailists[i].list) {
			if (g_StageSetup.ailists[i].id >= 0x1000) {
				g_BgChrs[count] = blankchr;

				if (g_StageSetup.ailists[i].id >= 0x1400) {
					g_BgChrs[count].chrnum = g_StageSetup.ailists[i].id - 0x460; // 4000+
					g_BgChrs[count].hidden2 |= CHRH2FLAG_TICKDURINGAUTOCUT;
				} else {
					g_BgChrs[count].chrnum = g_StageSetup.ailists[i].id - 0x60; // 4000+
				}

				g_BgChrs[count].ailist = g_StageSetup.ailists[i].list;
				g_BgChrs[count].aioffset = 0;
				g_BgChrs[count].aireturnlist = -1;
				g_BgChrs[count].actiontype = ACT_NULL;
				count++;
			}

			i++;
		}

		// The final BG chr is for cutscene use
		g_BgChrs[count] = blankchr;
		g_BgChrs[count].chrnum = 4900;
		g_BgChrs[count].ailist = NULL;
		g_BgChrs[count].aioffset = 0;
		g_BgChrs[count].aireturnlist = -1;
		g_BgChrs[count].actiontype = ACT_NULL;
		g_BgChrs[count].hidden2 |= CHRH2FLAG_TICKDURINGAUTOCUT;
		count++;

		// Sort them
		do {
			modified = false;

			for (i = 0; i < count - 1; i++) {
				if (g_BgChrs[i + 1].chrnum < g_BgChrs[i].chrnum) {
					tmp = g_BgChrs[i];
					g_BgChrs[i] = g_BgChrs[i + 1];
					g_BgChrs[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Populate chr numbers
		for (i = 0; i < count; i++) {
			g_BgChrnums[i] = g_BgChrs[i].chrnum;
		}
	}

	g_TeamList = mempAlloc(0x210, MEMPOOL_STAGE);
	g_SquadronList = mempAlloc(0x220, MEMPOOL_STAGE);
}

GLOBAL_ASM(
glabel debugLoadAllAilistModels
/*  f00c07c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00c080:	3c0e800a */ 	lui	$t6,%hi(g_StageSetup+0x18)
/*  f00c084:	8dced048 */ 	lw	$t6,%lo(g_StageSetup+0x18)($t6)
/*  f00c088:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00c08c:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f00c090:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f00c094:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f00c098:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f00c09c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f00c0a0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f00c0a4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00c0a8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00c0ac:	8dd00000 */ 	lw	$s0,0x0($t6)
/*  f00c0b0:	241500c8 */ 	addiu	$s5,$zero,0xc8
/*  f00c0b4:	241600c9 */ 	addiu	$s6,$zero,0xc9
/*  f00c0b8:	12000052 */ 	beqz	$s0,.L0f00c204
/*  f00c0bc:	0000b825 */ 	or	$s7,$zero,$zero
/*  f00c0c0:	241400c7 */ 	addiu	$s4,$zero,0xc7
/*  f00c0c4:	241300c6 */ 	addiu	$s3,$zero,0xc6
/*  f00c0c8:	2412001c */ 	addiu	$s2,$zero,0x1c
/*  f00c0cc:	24110004 */ 	addiu	$s1,$zero,0x4
.L0f00c0d0:
/*  f00c0d0:	92030000 */ 	lbu	$v1,0x0($s0)
.L0f00c0d4:
/*  f00c0d4:	3c0f800a */ 	lui	$t7,%hi(g_StageSetup+0x18)
/*  f00c0d8:	16230004 */ 	bne	$s1,$v1,.L0f00c0ec
/*  f00c0dc:	00000000 */ 	nop
/*  f00c0e0:	8defd048 */ 	lw	$t7,%lo(g_StageSetup+0x18)($t7)
/*  f00c0e4:	10000042 */ 	b	.L0f00c1f0
/*  f00c0e8:	01f71021 */ 	addu	$v0,$t7,$s7
.L0f00c0ec:
/*  f00c0ec:	5072000c */ 	beql	$v1,$s2,.L0f00c120
/*  f00c0f0:	92180002 */ 	lbu	$t8,0x2($s0)
/*  f00c0f4:	10730013 */ 	beq	$v1,$s3,.L0f00c144
/*  f00c0f8:	00000000 */ 	nop
/*  f00c0fc:	1074001c */ 	beq	$v1,$s4,.L0f00c170
/*  f00c100:	00000000 */ 	nop
/*  f00c104:	50750026 */ 	beql	$v1,$s5,.L0f00c1a0
/*  f00c108:	920a0002 */ 	lbu	$t2,0x2($s0)
/*  f00c10c:	5076002f */ 	beql	$v1,$s6,.L0f00c1cc
/*  f00c110:	920d0002 */ 	lbu	$t5,0x2($s0)
/*  f00c114:	10000032 */ 	b	.L0f00c1e0
/*  f00c118:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c11c:	92180002 */ 	lbu	$t8,0x2($s0)
.L0f00c120:
/*  f00c120:	92080003 */ 	lbu	$t0,0x3($s0)
/*  f00c124:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f00c128:	03281025 */ 	or	$v0,$t9,$t0
/*  f00c12c:	0fc2486d */ 	jal	setupLoadModeldef
/*  f00c130:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f00c134:	5040002a */ 	beqzl	$v0,.L0f00c1e0
/*  f00c138:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c13c:	10000028 */ 	b	.L0f00c1e0
/*  f00c140:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c144:
/*  f00c144:	0fc0b38c */ 	jal	bodyLoad
/*  f00c148:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f00c14c:	82040003 */ 	lb	$a0,0x3($s0)
/*  f00c150:	04820023 */ 	bltzl	$a0,.L0f00c1e0
/*  f00c154:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c158:	0fc0b38c */ 	jal	bodyLoad
/*  f00c15c:	00000000 */ 	nop
/*  f00c160:	5040001f */ 	beqzl	$v0,.L0f00c1e0
/*  f00c164:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c168:	1000001d */ 	b	.L0f00c1e0
/*  f00c16c:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c170:
/*  f00c170:	0fc0b38c */ 	jal	bodyLoad
/*  f00c174:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f00c178:	82040003 */ 	lb	$a0,0x3($s0)
/*  f00c17c:	04820018 */ 	bltzl	$a0,.L0f00c1e0
/*  f00c180:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c184:	0fc0b38c */ 	jal	bodyLoad
/*  f00c188:	00000000 */ 	nop
/*  f00c18c:	50400014 */ 	beqzl	$v0,.L0f00c1e0
/*  f00c190:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c194:	10000012 */ 	b	.L0f00c1e0
/*  f00c198:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c19c:	920a0002 */ 	lbu	$t2,0x2($s0)
.L0f00c1a0:
/*  f00c1a0:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f00c1a4:	000a5a00 */ 	sll	$t3,$t2,0x8
/*  f00c1a8:	0fc2486d */ 	jal	setupLoadModeldef
/*  f00c1ac:	016c2025 */ 	or	$a0,$t3,$t4
/*  f00c1b0:	0fc04558 */ 	jal	weaponLoadProjectileModels
/*  f00c1b4:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f00c1b8:	50400009 */ 	beqzl	$v0,.L0f00c1e0
/*  f00c1bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c1c0:	10000007 */ 	b	.L0f00c1e0
/*  f00c1c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00c1c8:	920d0002 */ 	lbu	$t5,0x2($s0)
.L0f00c1cc:
/*  f00c1cc:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f00c1d0:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f00c1d4:	0fc2486d */ 	jal	setupLoadModeldef
/*  f00c1d8:	01cf2025 */ 	or	$a0,$t6,$t7
/*  f00c1dc:	02002025 */ 	or	$a0,$s0,$zero
.L0f00c1e0:
/*  f00c1e0:	0fc136d0 */ 	jal	chraiGetCommandLength
/*  f00c1e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f00c1e8:	1000ffb9 */ 	b	.L0f00c0d0
/*  f00c1ec:	02028021 */ 	addu	$s0,$s0,$v0
.L0f00c1f0:
/*  f00c1f0:	8c500008 */ 	lw	$s0,0x8($v0)
/*  f00c1f4:	26f70008 */ 	addiu	$s7,$s7,0x8
/*  f00c1f8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f00c1fc:	5600ffb5 */ 	bnezl	$s0,.L0f00c0d4
/*  f00c200:	92030000 */ 	lbu	$v1,0x0($s0)
.L0f00c204:
/*  f00c204:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00c208:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00c20c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00c210:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f00c214:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f00c218:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f00c21c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f00c220:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f00c224:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f00c228:	03e00008 */ 	jr	$ra
/*  f00c22c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

// Mismatch: regalloc near 19c
//void debugLoadAllAilistModels(void)
//{
//	u8 *cmd = g_StageSetup.ailists[0].list;
//	s32 i = 0;
//	s32 id;
//
//	if (!cmd) {
//		return;
//	}
//
//	do {
//		while (true) {
//			if (cmd[0] == AICMD_END) {
//				break;
//			}
//
//			switch (cmd[0]) {
//			case AICMD_DROPITEM: // 120
//				id = cmd[3] | (cmd[2] << 8);
//
//				if (setupLoadModeldef(id & 0xffff)) {
//					// empty
//				}
//				break;
//			case AICMD_SPAWNCHRATPAD: // 144
//				if (bodyLoad(cmd[2])) {
//					// empty
//				}
//				if ((s8)cmd[3] >= 0 && bodyLoad((s8)cmd[3])) {
//					// empty
//				}
//				break;
//			case AICMD_SPAWNCHRATCHR: // 170
//				if (bodyLoad(cmd[2])) {
//					// empty
//				}
//				if ((s8)cmd[3] >= 0 && bodyLoad((s8)cmd[3])) {
//					// empty
//				}
//				break;
//			case AICMD_EQUIPWEAPON: // 19c
//				if (setupLoadModeldef(cmd[3] | (cmd[2] << 8))) {
//					// empty
//				}
//				if (weaponLoadProjectileModels(cmd[4])) {
//					// empty
//				}
//				break;
//			case AICMD_EQUIPHAT: // 1c8
//				if (setupLoadModeldef(cmd[3] | (cmd[2] << 8))) {
//					// empty
//				}
//				break;
//			}
//
//			cmd += chraiGetCommandLength(cmd, 0);
//		}
//
//		i++;
//		cmd = g_StageSetup.ailists[i].list;
//	} while (cmd);
//}

void func0f00c230(void)
{
	// empty
}
