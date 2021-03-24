#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/chr/chr.h"
#include "game/ceil.h"
#include "game/game_0b0fd0.h"
#include "game/game_127910.h"
#include "game/mplayer/setup.h"
#include "game/game_190260.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "game/mplayer/mplayer.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

f32 var80087e50[][3] = {
	{ 0,    120,  10000 },
	{ 300,  450,  4500  },
	{ 300,  600,  4500  },
	{ 600,  1200, 4500  },
	{ 150,  250,  4500  },
	{ 1000, 2000, 3000  },
	{ 0,    250,  10000 },
	{ 450,  700,  4500  },
};

#if VERSION >= VERSION_NTSC_1_0
void func0f197600(struct chrdata *chr)
{
	s32 index;
	f32 *limits;
	f32 distance;
	u8 new074;
	struct aibot *aibot = chr->aibot;
	s32 prev074 = aibot->unk074;
	struct prop *prop = NULL;
	s32 somevalue = 0;
	f32 limit1;
	f32 limit2;
	f32 limit3;
	u32 stack;

	if (aibot->simulant->base.simtype == SIMTYPE_KAZE) {
		index = 4;
	} else {
		index = func0f198e38(aibot->weaponnum, aibot->gunfunc);
	}

	if (chr->myaction == MA_AIBOTFOLLOW && aibot->followingplayernum >= 0) {
		limits = var80087e50[6];
		prop = g_MpPlayerChrs[aibot->followingplayernum]->prop;
		somevalue = aibot->unk16c[aibot->followingplayernum];

		if (chr->target != -1 && (index == 0 || index == 4)) {
			struct prop *target = chrGetTargetProp(chr);
			f32 xdiff = prop->pos.x - target->pos.x;
			f32 ydiff = prop->pos.y - target->pos.y;
			f32 zdiff = prop->pos.z - target->pos.z;

			if (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff < 500 * 500) {
				limits = var80087e50[index];
				prop = target;
				somevalue = aibot->unk128;
			}
		}
	} else {
		limits = var80087e50[index];

		if (chr->myaction == MA_AIBOTATTACK && aibot->attackingplayernum >= 0) {
			prop = g_MpPlayerChrs[aibot->attackingplayernum]->prop;
			somevalue = aibot->unk16c[aibot->attackingplayernum];
		} else if (chr->target != -1) {
			prop = chrGetTargetProp(chr);
			somevalue = aibot->unk128;
		}
	}

	if (prop == NULL) {
		return;
	}

	if (!chrHasGround(prop->chr)) {
		return;
	}

	distance = chrGetDistanceToCoord(chr, &prop->pos);
	limit1 = limits[0];
	limit2 = limits[1];
	limit3 = limits[2];

	if (chr->aibot->simulant->difficulty == SIMDIFF_MEAT) {
		limit1 *= 0.35f;
	} else if (chr->aibot->simulant->difficulty == SIMDIFF_EASY) {
		limit1 *= 0.5f;
	}

	if (aibot->unk074 == 1) {
		limit1 += 25.0f;
	} else if (aibot->unk074 == 3 || aibot->unk074 == 4) {
		limit2 -= 25.0f;
	}

	if (distance < limit1) {
		new074 = 1;
	} else if (distance >= limit1 && distance < limit2) {
		new074 = 2;
	} else if (distance >= limit2 && distance < limit3) {
		new074 = 3;
	} else {
		new074 = 4;
	}

	if (new074 != 1 || somevalue == 0 || aibot->unk050 != prop) {
		aibot->unk050 = NULL;
		aibot->unk09d = 0;
	}

	if (new074 == 2) {
		if (somevalue == 0) {
			new074 = 3;
		}
	} else if (new074 == 1) {
		if (somevalue == 0) {
			new074 = 3;
			aibot->unk050 = prop;
			aibot->unk09d = PALDOWN(20) + (random() % PALDOWN(120));
		} else if (aibot->unk050) {
			if (aibot->unk09d > g_Vars.lvupdate240_60) {
				aibot->unk09d -= g_Vars.lvupdate240_60;
				new074 = 2;
			} else {
				aibot->unk050 = NULL;
				aibot->unk09d = 0;
			}
		}
	}

	aibot->unk074 = new074;

	if (aibot->unk0d0 >= 0) {
		aibot->unk0d0 -= g_Vars.lvupdate240_60;
	}

	if (new074 != prev074 || (new074 != 2 && (chr->actiontype == ACT_STAND || aibot->unk0d0 <= 0))) {
		switch (new074) {
		case 1:
			chrRunFromPos(chr, SPEED_RUN, 10000, &prop->pos);
			break;
		case 2:
			chrTryStop(chr);
			break;
		case 3:
			chrGoToProp(chr, prop, SPEED_RUN);
			break;
		case 4:
			chrGoToProp(chr, prop, SPEED_RUN);
			break;
		}

		aibot->unk0d0 = PALDOWN(60);
	}
}
#else
GLOBAL_ASM(
glabel func0f197600
.late_rodata
glabel var7f1b35b0
.word 0x48742400
glabel var7f1b35b4
.word 0x3eb33333
.text
/*  f191680:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f191684:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f191688:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f19168c:	8c8802d4 */ 	lw	$t0,0x2d4($a0)
/*  f191690:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191694:	00003825 */ 	or	$a3,$zero,$zero
/*  f191698:	810f0074 */ 	lb	$t7,0x74($t0)
/*  f19169c:	00004825 */ 	or	$t1,$zero,$zero
/*  f1916a0:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f1916a4:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f1916a8:	93190047 */ 	lbu	$t9,0x47($t8)
/*  f1916ac:	57210004 */ 	bnel	$t9,$at,.NB0f1916c0
/*  f1916b0:	8d05004c */ 	lw	$a1,0x4c($t0)
/*  f1916b4:	1000000d */ 	beqz	$zero,.NB0f1916ec
/*  f1916b8:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f1916bc:	8d05004c */ 	lw	$a1,0x4c($t0)
.NB0f1916c0:
/*  f1916c0:	8d040020 */ 	lw	$a0,0x20($t0)
/*  f1916c4:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f1916c8:	00055080 */ 	sll	$t2,$a1,0x2
/*  f1916cc:	000a2fc2 */ 	srl	$a1,$t2,0x1f
/*  f1916d0:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f1916d4:	0fc64b86 */ 	jal	func0f198e38
/*  f1916d8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f1916dc:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1916e0:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f1916e4:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f1916e8:	00401825 */ 	or	$v1,$v0,$zero
.NB0f1916ec:
/*  f1916ec:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f1916f0:	00035880 */ 	sll	$t3,$v1,0x2
/*  f1916f4:	24010032 */ 	addiu	$at,$zero,0x32
/*  f1916f8:	918402a0 */ 	lbu	$a0,0x2a0($t4)
/*  f1916fc:	01635823 */ 	subu	$t3,$t3,$v1
/*  f191700:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f191704:	1481003c */ 	bne	$a0,$at,.NB0f1917f8
/*  f191708:	3c0d8009 */ 	lui	$t5,0x8009
/*  f19170c:	8502000a */ 	lh	$v0,0xa($t0)
/*  f191710:	3c068009 */ 	lui	$a2,0x8009
/*  f191714:	24c6a618 */ 	addiu	$a2,$a2,-23016
/*  f191718:	04400037 */ 	bltz	$v0,.NB0f1917f8
/*  f19171c:	3c0e800b */ 	lui	$t6,0x800b
/*  f191720:	00026880 */ 	sll	$t5,$v0,0x2
/*  f191724:	8598017e */ 	lh	$t8,0x17e($t4)
/*  f191728:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f19172c:	8dce0d80 */ 	lw	$t6,0xd80($t6)
/*  f191730:	01027821 */ 	addu	$t7,$t0,$v0
/*  f191734:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191738:	91e9016c */ 	lbu	$t1,0x16c($t7)
/*  f19173c:	13010049 */ 	beq	$t8,$at,.NB0f191864
/*  f191740:	8dc7001c */ 	lw	$a3,0x1c($t6)
/*  f191744:	10600003 */ 	beqz	$v1,.NB0f191754
/*  f191748:	24010004 */ 	addiu	$at,$zero,0x4
/*  f19174c:	14610045 */ 	bne	$v1,$at,.NB0f191864
/*  f191750:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f191754:
/*  f191754:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191758:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f19175c:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f191760:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f191764:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191768:	0fc0a08c */ 	jal	chrGetTargetProp
/*  f19176c:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f191770:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f191774:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f191778:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f19177c:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f191780:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f191784:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f191788:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f19178c:	c4f00010 */ 	lwc1	$f16,0x10($a3)
/*  f191790:	3c017f1b */ 	lui	$at,0x7f1b
/*  f191794:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f191798:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f19179c:	8fa30064 */ 	lw	$v1,0x64($sp)
/*  f1917a0:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f1917a4:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f1917a8:	c43235b0 */ 	lwc1	$f18,0x35b0($at)
/*  f1917ac:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1917b0:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f1917b4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f1917b8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1917bc:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f1917c0:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f1917c4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1917c8:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f1917cc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1917d0:	254aa5d0 */ 	addiu	$t2,$t2,-23088
/*  f1917d4:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f1917d8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f1917dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1917e0:	45000020 */ 	bc1f	.NB0f191864
/*  f1917e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1917e8:	032a3021 */ 	addu	$a2,$t9,$t2
/*  f1917ec:	00403825 */ 	or	$a3,$v0,$zero
/*  f1917f0:	1000001c */ 	beqz	$zero,.NB0f191864
/*  f1917f4:	8d090128 */ 	lw	$t1,0x128($t0)
.NB0f1917f8:
/*  f1917f8:	25ada5d0 */ 	addiu	$t5,$t5,-23088
/*  f1917fc:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f191800:	1481000b */ 	bne	$a0,$at,.NB0f191830
/*  f191804:	016d3021 */ 	addu	$a2,$t3,$t5
/*  f191808:	85020008 */ 	lh	$v0,0x8($t0)
/*  f19180c:	3c0f800b */ 	lui	$t7,0x800b
/*  f191810:	04400007 */ 	bltz	$v0,.NB0f191830
/*  f191814:	00027080 */ 	sll	$t6,$v0,0x2
/*  f191818:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f19181c:	8def0d80 */ 	lw	$t7,0xd80($t7)
/*  f191820:	01026021 */ 	addu	$t4,$t0,$v0
/*  f191824:	9189016c */ 	lbu	$t1,0x16c($t4)
/*  f191828:	1000000e */ 	beqz	$zero,.NB0f191864
/*  f19182c:	8de7001c */ 	lw	$a3,0x1c($t7)
.NB0f191830:
/*  f191830:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f191834:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191838:	8719017e */ 	lh	$t9,0x17e($t8)
/*  f19183c:	03002025 */ 	or	$a0,$t8,$zero
/*  f191840:	13210008 */ 	beq	$t9,$at,.NB0f191864
/*  f191844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191848:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f19184c:	0fc0a08c */ 	jal	chrGetTargetProp
/*  f191850:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191854:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f191858:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f19185c:	00403825 */ 	or	$a3,$v0,$zero
/*  f191860:	8d090128 */ 	lw	$t1,0x128($t0)
.NB0f191864:
/*  f191864:	50e00095 */ 	beqzl	$a3,.NB0f191abc
/*  f191868:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19186c:	8ce40004 */ 	lw	$a0,0x4($a3)
/*  f191870:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f191874:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191878:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f19187c:	0fc632b2 */ 	jal	chrHasGround
/*  f191880:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f191884:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f191888:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f19188c:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f191890:	10400089 */ 	beqz	$v0,.NB0f191ab8
/*  f191894:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f191898:	24e50008 */ 	addiu	$a1,$a3,0x8
/*  f19189c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1918a0:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f1918a4:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f1918a8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f1918ac:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f1918b0:	0fc1221c */ 	jal	chrGetDistanceToCoord
/*  f1918b4:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f1918b8:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f1918bc:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f1918c0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f1918c4:	8d4b02d4 */ 	lw	$t3,0x2d4($t2)
/*  f1918c8:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f1918cc:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f1918d0:	8d6d0004 */ 	lw	$t5,0x4($t3)
/*  f1918d4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1918d8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1918dc:	91a20048 */ 	lbu	$v0,0x48($t5)
/*  f1918e0:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f1918e4:	c4cc0004 */ 	lwc1	$f12,0x4($a2)
/*  f1918e8:	14400007 */ 	bnez	$v0,.NB0f191908
/*  f1918ec:	c4ce0008 */ 	lwc1	$f14,0x8($a2)
/*  f1918f0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1918f4:	c42435b4 */ 	lwc1	$f4,0x35b4($at)
/*  f1918f8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1918fc:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f191900:	10000008 */ 	beqz	$zero,.NB0f191924
/*  f191904:	81020074 */ 	lb	$v0,0x74($t0)
.NB0f191908:
/*  f191908:	14a20005 */ 	bne	$a1,$v0,.NB0f191920
/*  f19190c:	3c013f00 */ 	lui	$at,0x3f00
/*  f191910:	44813000 */ 	mtc1	$at,$f6
/*  f191914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191918:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f19191c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f191920:
/*  f191920:	81020074 */ 	lb	$v0,0x74($t0)
.NB0f191924:
/*  f191924:	24010003 */ 	addiu	$at,$zero,0x3
/*  f191928:	3c0e800a */ 	lui	$t6,0x800a
/*  f19192c:	14a20005 */ 	bne	$a1,$v0,.NB0f191944
/*  f191930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191934:	3c0141c8 */ 	lui	$at,0x41c8
/*  f191938:	44814000 */ 	mtc1	$at,$f8
/*  f19193c:	10000008 */ 	beqz	$zero,.NB0f191960
/*  f191940:	46081080 */ 	add.s	$f2,$f2,$f8
.NB0f191944:
/*  f191944:	10410002 */ 	beq	$v0,$at,.NB0f191950
/*  f191948:	24010004 */ 	addiu	$at,$zero,0x4
/*  f19194c:	14410004 */ 	bne	$v0,$at,.NB0f191960
.NB0f191950:
/*  f191950:	3c0141c8 */ 	lui	$at,0x41c8
/*  f191954:	44815000 */ 	mtc1	$at,$f10
/*  f191958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19195c:	460a6301 */ 	sub.s	$f12,$f12,$f10
.NB0f191960:
/*  f191960:	4602003c */ 	c.lt.s	$f0,$f2
/*  f191964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191968:	45020004 */ 	bc1fl	.NB0f19197c
/*  f19196c:	4600103e */ 	c.le.s	$f2,$f0
/*  f191970:	10000015 */ 	beqz	$zero,.NB0f1919c8
/*  f191974:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f191978:	4600103e */ 	c.le.s	$f2,$f0
.NB0f19197c:
/*  f19197c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191980:	45020008 */ 	bc1fl	.NB0f1919a4
/*  f191984:	4600603e */ 	c.le.s	$f12,$f0
/*  f191988:	460c003c */ 	c.lt.s	$f0,$f12
/*  f19198c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191990:	45020004 */ 	bc1fl	.NB0f1919a4
/*  f191994:	4600603e */ 	c.le.s	$f12,$f0
/*  f191998:	1000000b */ 	beqz	$zero,.NB0f1919c8
/*  f19199c:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1919a0:	4600603e */ 	c.le.s	$f12,$f0
.NB0f1919a4:
/*  f1919a4:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f1919a8:	45000007 */ 	bc1f	.NB0f1919c8
/*  f1919ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1919b0:	460e003c */ 	c.lt.s	$f0,$f14
/*  f1919b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1919b8:	45000003 */ 	bc1f	.NB0f1919c8
/*  f1919bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1919c0:	10000001 */ 	beqz	$zero,.NB0f1919c8
/*  f1919c4:	24020003 */ 	addiu	$v0,$zero,0x3
.NB0f1919c8:
/*  f1919c8:	14820004 */ 	bne	$a0,$v0,.NB0f1919dc
/*  f1919cc:	00401825 */ 	or	$v1,$v0,$zero
/*  f1919d0:	55200003 */ 	bnezl	$t1,.NB0f1919e0
/*  f1919d4:	8d0200d0 */ 	lw	$v0,0xd0($t0)
/*  f1919d8:	24030003 */ 	addiu	$v1,$zero,0x3
.NB0f1919dc:
/*  f1919dc:	8d0200d0 */ 	lw	$v0,0xd0($t0)
.NB0f1919e0:
/*  f1919e0:	a1030074 */ 	sb	$v1,0x74($t0)
/*  f1919e4:	04420005 */ 	bltzl	$v0,.NB0f1919fc
/*  f1919e8:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f1919ec:	8dcee6f8 */ 	lw	$t6,-0x1908($t6)
/*  f1919f0:	004e7823 */ 	subu	$t7,$v0,$t6
/*  f1919f4:	ad0f00d0 */ 	sw	$t7,0xd0($t0)
/*  f1919f8:	8fac0050 */ 	lw	$t4,0x50($sp)
.NB0f1919fc:
/*  f1919fc:	15830009 */ 	bne	$t4,$v1,.NB0f191a24
/*  f191a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191a04:	1083002c */ 	beq	$a0,$v1,.NB0f191ab8
/*  f191a08:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f191a0c:	83380007 */ 	lb	$t8,0x7($t9)
/*  f191a10:	10b80004 */ 	beq	$a1,$t8,.NB0f191a24
/*  f191a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191a18:	8d0a00d0 */ 	lw	$t2,0xd0($t0)
/*  f191a1c:	5d400027 */ 	bgtzl	$t2,.NB0f191abc
/*  f191a20:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f191a24:
/*  f191a24:	10a3000a */ 	beq	$a1,$v1,.NB0f191a50
/*  f191a28:	3c06461c */ 	lui	$a2,0x461c
/*  f191a2c:	10640010 */ 	beq	$v1,$a0,.NB0f191a70
/*  f191a30:	24010003 */ 	addiu	$at,$zero,0x3
/*  f191a34:	10610013 */ 	beq	$v1,$at,.NB0f191a84
/*  f191a38:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191a3c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191a40:	10610016 */ 	beq	$v1,$at,.NB0f191a9c
/*  f191a44:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191a48:	1000001a */ 	beqz	$zero,.NB0f191ab4
/*  f191a4c:	240b003c */ 	addiu	$t3,$zero,0x3c
.NB0f191a50:
/*  f191a50:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191a54:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f191a58:	34c64000 */ 	ori	$a2,$a2,0x4000
/*  f191a5c:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f191a60:	0fc12d53 */ 	jal	chrRunFromPos
/*  f191a64:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191a68:	10000011 */ 	beqz	$zero,.NB0f191ab0
/*  f191a6c:	8fa80054 */ 	lw	$t0,0x54($sp)
.NB0f191a70:
/*  f191a70:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191a74:	0fc0e985 */ 	jal	chrTryStop
/*  f191a78:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191a7c:	1000000c */ 	beqz	$zero,.NB0f191ab0
/*  f191a80:	8fa80054 */ 	lw	$t0,0x54($sp)
.NB0f191a84:
/*  f191a84:	00e02825 */ 	or	$a1,$a3,$zero
/*  f191a88:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f191a8c:	0fc0e907 */ 	jal	chrGoToProp
/*  f191a90:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191a94:	10000006 */ 	beqz	$zero,.NB0f191ab0
/*  f191a98:	8fa80054 */ 	lw	$t0,0x54($sp)
.NB0f191a9c:
/*  f191a9c:	00e02825 */ 	or	$a1,$a3,$zero
/*  f191aa0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f191aa4:	0fc0e907 */ 	jal	chrGoToProp
/*  f191aa8:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f191aac:	8fa80054 */ 	lw	$t0,0x54($sp)
.NB0f191ab0:
/*  f191ab0:	240b003c */ 	addiu	$t3,$zero,0x3c
.NB0f191ab4:
/*  f191ab4:	ad0b00d0 */ 	sw	$t3,0xd0($t0)
.NB0f191ab8:
/*  f191ab8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f191abc:
/*  f191abc:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f191ac0:	03e00008 */ 	jr	$ra
/*  f191ac4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void mpAibotApplyCommand(struct chrdata *chr, u32 command)
{
	f32 value;

	switch (command) {
	case AIBOTCMD_ATTACK:
		amOpenPickTarget();
		break;
	case AIBOTCMD_FOLLOW:
		mpAibotApplyFollow(chr, g_Vars.currentplayer->prop);
		break;
	case AIBOTCMD_PROTECT:
		mpAibotApplyProtect(chr, g_Vars.currentplayer->prop);
		break;
	case AIBOTCMD_DEFEND:
		value = chrGetInverseTheta(g_Vars.currentplayer->prop->chr);
		mpAibotApplyDefend(chr, &g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, value);
		break;
	case AIBOTCMD_HOLD:
		value = chrGetInverseTheta(g_Vars.currentplayer->prop->chr);
		mpAibotApplyHold(chr, &g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, value);
		break;
	default:
		mpAibotApplyScenarioCommand(chr, command);
		break;
	}
}
