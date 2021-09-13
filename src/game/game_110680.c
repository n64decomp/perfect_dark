#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/game_110680.h"
#include "game/bg.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_0bfb0.h"
#include "lib/snd.h"
#include "lib/lib_126b0.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

u32 var800a22d0;
u32 var800a22d4;
u32 var800a22d8;
u32 var800a22dc;
u32 var800a22e0;
u32 var800a22e4;
u32 var800a22e8;
u32 var800a22ec;
u32 var800a22f0;
u32 var800a22f4;
u32 var800a22f8;
u32 var800a22fc;
u32 var800a2300;
u32 var800a2304;
u32 var800a2308;
u32 var800a230c;
u32 var800a2310;
u32 var800a2314;
u32 var800a2318;
u32 var800a231c;
u32 var800a2320;
u32 var800a2324;
u8 var800a2328;
u8 var800a2329;
u8 var800a232a;
s8 g_SoloCompleted;
u8 g_AltTitle;
s32 var800a2330[1];
u32 var800a2334;
u32 var800a2338;
u32 var800a233c;
u32 var800a2340;
u32 var800a2344;
u32 var800a2348;
u32 var800a234c;

struct filelist *g_FileLists[] = { NULL, NULL, NULL, NULL };
bool var80075bd0[] = { true, true, true, true };

u32 var80075be0 = 0;
u32 var80075be4 = 0;
u32 var80075be8 = 0;
u32 var80075bec = 0;
u32 var80075bf0 = 0;
u32 var80075bf4 = 0;
u32 var80075bf8 = 0;
u32 var80075bfc = 0;

void func0f110680(void)
{
	mpsetupfileLoadDefaults();
}

void func0f1106a0(void)
{
	mpsetupfileLoadDefaults();
	mpsetupfileSave();
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f1106c8
/*  f111198:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f11119c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1111a0:	0fc444ba */ 	jal	mpsetupfileLoad
/*  f1111a4:	00000000 */ 	nop
/*  f1111a8:	3c04800a */ 	lui	$a0,0x800a
/*  f1111ac:	0fc5bdd7 */ 	jal	func0f16f75c
/*  f1111b0:	9484a992 */ 	lhu	$a0,-0x566e($a0)
/*  f1111b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1111b8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1111bc:	24020001 */ 	li	$v0,0x1
/*  f1111c0:	03e00008 */ 	jr	$ra
/*  f1111c4:	00000000 */ 	nop
);
#else
bool func0f1106c8(void)
{
	mpsetupfileLoad();
	return true;
}
#endif

void func0f1106ec(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f1106f4
/*  f1106f4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1106f8:	00802825 */ 	or	$a1,$a0,$zero
/*  f1106fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f110700:	3c04800a */ 	lui	$a0,%hi(var800a22d0)
/*  f110704:	248422d0 */ 	addiu	$a0,$a0,%lo(var800a22d0)
/*  f110708:	0c012c5c */ 	jal	bcopy
/*  f11070c:	2406005b */ 	addiu	$a2,$zero,0x5b
/*  f110710:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f110714:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f110718:	03e00008 */ 	jr	$ra
/*  f11071c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f110720
/*  f110720:	27bdf7b0 */ 	addiu	$sp,$sp,-2128
/*  f110724:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f110728:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11072c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f110730:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110734:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f110738:	27a6003c */ 	addiu	$a2,$sp,0x3c
/*  f11073c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f110740:	0fc459ec */ 	jal	func0f1167b0
/*  f110744:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f110748:	14400029 */ 	bnez	$v0,.L0f1107f0
/*  f11074c:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f110750:	11c00013 */ 	beqz	$t6,.L0f1107a0
/*  f110754:	00008825 */ 	or	$s1,$zero,$zero
/*  f110758:	27b0003c */ 	addiu	$s0,$sp,0x3c
/*  f11075c:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f110760:	27b20840 */ 	addiu	$s2,$sp,0x840
/*  f110764:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f110768:
/*  f110768:	0fc464da */ 	jal	func0f119368
/*  f11076c:	02403025 */ 	or	$a2,$s2,$zero
/*  f110770:	8fb8084c */ 	lw	$t8,0x84c($sp)
/*  f110774:	00184740 */ 	sll	$t0,$t8,0x1d
/*  f110778:	05020005 */ 	bltzl	$t0,.L0f110790
/*  f11077c:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f110780:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f110784:	10000006 */ 	b	.L0f1107a0
/*  f110788:	afa90038 */ 	sw	$t1,0x38($sp)
/*  f11078c:	8e050004 */ 	lw	$a1,0x4($s0)
.L0f110790:
/*  f110790:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f110794:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110798:	54a0fff3 */ 	bnezl	$a1,.L0f110768
/*  f11079c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f1107a0:
/*  f1107a0:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f1107a4:	27b20840 */ 	addiu	$s2,$sp,0x840
/*  f1107a8:	27b0003c */ 	addiu	$s0,$sp,0x3c
/*  f1107ac:	51400011 */ 	beqzl	$t2,.L0f1107f4
/*  f1107b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1107b4:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f1107b8:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f1107bc:
/*  f1107bc:	0fc464da */ 	jal	func0f119368
/*  f1107c0:	02403025 */ 	or	$a2,$s2,$zero
/*  f1107c4:	8fac084c */ 	lw	$t4,0x84c($sp)
/*  f1107c8:	000c7740 */ 	sll	$t6,$t4,0x1d
/*  f1107cc:	05c30005 */ 	bgezl	$t6,.L0f1107e4
/*  f1107d0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1107d4:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1107d8:	10000005 */ 	b	.L0f1107f0
/*  f1107dc:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f1107e0:	8e050004 */ 	lw	$a1,0x4($s0)
.L0f1107e4:
/*  f1107e4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1107e8:	54a0fff4 */ 	bnezl	$a1,.L0f1107bc
/*  f1107ec:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f1107f0:
/*  f1107f0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1107f4:
/*  f1107f4:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f1107f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1107fc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f110800:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f110804:	03e00008 */ 	jr	$ra
/*  f110808:	27bd0850 */ 	addiu	$sp,$sp,0x850
);

void mpsetupfileLoad(void)
{
	bool sp124 = false;
	struct savebuffer buffer;
	s32 i;
	s32 tmp;
	struct maybesavelocation_2d8 thing;

	tmp = func0f110720();

	if (tmp == 0) {
		sp124 = true;
	} else {
		savebufferClear(&buffer);

		if (func0f116800(4, tmp, buffer.bytes, 0)) {
			sp124 = true;
		}
	}

	if (!sp124) {
		u8 tracknum;

		func0f0d579c(&buffer, &thing);

		g_Vars.unk00047c = thing.unk00;
		g_Vars.unk000480 = thing.unk04;

		g_MpSetupFile.unk89 = savebufferReadBits(&buffer, 1);

		g_Vars.unk000482 = savebufferReadBits(&buffer, 4);

		for (i = 0; i < 8; i++) {
			savebufferReadString(&buffer, g_MpSetupFile.teamnames[i], 1);
		}

		tracknum = savebufferReadBits(&buffer, 8);

		if (tracknum == 0xff) {
			g_MpSetupFile.tracknum = -1;
		} else {
			g_MpSetupFile.tracknum = tracknum;
		}

		for (i = 0; i < 6; i++) {
			g_MpSetupFile.multipletracknums[i] = savebufferReadBits(&buffer, 8);
		}

		g_MpSetupFile.usingmultipletunes = savebufferReadBits(&buffer, 1);
		g_SoloCompleted = savebufferReadBits(&buffer, 1);
		g_AltTitle = savebufferReadBits(&buffer, 1);

		func0f0d54c4(&buffer);
	}

	if (sp124) {
		mpsetupfileLoadDefaults();
		mpsetupfileSave();
	}
}

void mpsetupfileSave(void)
{
	volatile bool sp12c = false;
	struct savebuffer buffer;
	struct maybesavelocation_2d8 thing;
	u32 stack;
	s32 i;
	s32 tmp;

	savebufferClear(&buffer);

	thing.unk00 = g_Vars.unk00047c;
	thing.unk04 = g_Vars.unk000480;

	func0f0d575c(&buffer, &thing);

	savebufferOr(&buffer, g_MpSetupFile.unk89, 1);
	savebufferOr(&buffer, g_Vars.unk000482, 4);

	for (i = 0; i < 8; i++) {
		func0f0d55a4(&buffer, g_MpSetupFile.teamnames[i]);
	}

	if (g_MpSetupFile.tracknum == -1) {
		savebufferOr(&buffer, 0xff, 8);
	} else {
		savebufferOr(&buffer, g_MpSetupFile.tracknum, 8);
	}

	for (i = 0; i < 6; i++) {
		savebufferOr(&buffer, g_MpSetupFile.multipletracknums[i], 8);
	}

	savebufferOr(&buffer, g_MpSetupFile.usingmultipletunes, 1);
	savebufferOr(&buffer, (u8)g_SoloCompleted, 1);
	savebufferOr(&buffer, g_AltTitle, 1);

	func0f0d54c4(&buffer);

	tmp = func0f110720();

	if (tmp == 0) {
		func0000bfd0("fileGuid", "bossfile.c", PAL ? 377 : 375);
	}

	if (func0f116828(4, tmp, 0x10, buffer.bytes, NULL, 0)) {
		sp12c = true;
	}
}

void mpsetupfileLoadDefaults(void)
{
	g_MpSetupFile.teamnames[0][0] = '\0';
	g_MpSetupFile.teamnames[1][0] = '\0';
	g_MpSetupFile.teamnames[2][0] = '\0';
	g_MpSetupFile.teamnames[3][0] = '\0';
	g_MpSetupFile.teamnames[4][0] = '\0';
	g_MpSetupFile.teamnames[5][0] = '\0';
	g_MpSetupFile.teamnames[6][0] = '\0';
	g_MpSetupFile.teamnames[7][0] = '\0';

	g_MpSetupFile.tracknum = -1;
	mpEnableAllMultiTracks();
	g_MpSetupFile.usingmultipletunes = false;
	g_MpSetupFile.unk89 = 0;
	g_MpSetupFile.locktype = MPLOCKTYPE_NONE;
	g_Vars.unk00047c = 0;
	g_Vars.unk000480 = 0;
	g_Vars.unk000482 = (PAL ? 7 : 0);
	g_SoloCompleted = 0;
	g_AltTitle = false;

	mpsetupfileSave();
}

void func0f110bf0(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f110bf8
/*  f110bf8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f110bfc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f110c00:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f110c04:	3c108007 */ 	lui	$s0,%hi(g_FileLists)
/*  f110c08:	3c118007 */ 	lui	$s1,%hi(g_FileLists+0x10)
/*  f110c0c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f110c10:	26315bd0 */ 	addiu	$s1,$s1,%lo(g_FileLists+0x10)
/*  f110c14:	26105bc0 */ 	addiu	$s0,$s0,%lo(g_FileLists)
/*  f110c18:	8e0e0000 */ 	lw	$t6,0x0($s0)
.L0f110c1c:
/*  f110c1c:	51c00008 */ 	beqzl	$t6,.L0f110c40
/*  f110c20:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110c24:	0fc5db69 */ 	jal	align16
/*  f110c28:	24040310 */ 	addiu	$a0,$zero,0x310
/*  f110c2c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110c30:	0c004b2d */ 	jal	func00012cb4
/*  f110c34:	00402825 */ 	or	$a1,$v0,$zero
/*  f110c38:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f110c3c:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f110c40:
/*  f110c40:	5611fff6 */ 	bnel	$s0,$s1,.L0f110c1c
/*  f110c44:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f110c48:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f110c4c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f110c50:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f110c54:	03e00008 */ 	jr	$ra
/*  f110c58:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

/**
 * Allocate and build a file list.
 */
void func0f110c5c(s32 listnum, u8 filetype)
{
	if (g_FileLists[listnum] == NULL) {
		func0f15e5b8(align16(sizeof(struct filelist)), 1);
		g_FileLists[listnum] = func00012ab0(align16(sizeof(struct filelist)));
	}

	g_FileLists[listnum]->outdated = true;
	g_FileLists[listnum]->filetype = filetype;

	if (var80062944 == 0) {
		joy0001398c(3);
	}

	var80062944 = 1;
}

GLOBAL_ASM(
glabel func0f110cf8
/*  f110cf8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f110cfc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110d00:	309000ff */ 	andi	$s0,$a0,0xff
/*  f110d04:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f110d08:	3c058007 */ 	lui	$a1,%hi(g_FileLists)
/*  f110d0c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f110d10:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f110d14:	24a55bc0 */ 	addiu	$a1,$a1,%lo(g_FileLists)
/*  f110d18:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f110d1c:	00001825 */ 	or	$v1,$zero,$zero
/*  f110d20:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f110d24:
/*  f110d24:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f110d28:	10400006 */ 	beqz	$v0,.L0f110d44
/*  f110d2c:	00000000 */ 	nop
/*  f110d30:	904e030b */ 	lbu	$t6,0x30b($v0)
/*  f110d34:	560e0007 */ 	bnel	$s0,$t6,.L0f110d54
/*  f110d38:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f110d3c:	1000000f */ 	b	.L0f110d7c
/*  f110d40:	00601025 */ 	or	$v0,$v1,$zero
.L0f110d44:
/*  f110d44:	54c70003 */ 	bnel	$a2,$a3,.L0f110d54
/*  f110d48:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f110d4c:	00603025 */ 	or	$a2,$v1,$zero
/*  f110d50:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f110d54:
/*  f110d54:	1464fff3 */ 	bne	$v1,$a0,.L0f110d24
/*  f110d58:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f110d5c:	04c00007 */ 	bltz	$a2,.L0f110d7c
/*  f110d60:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f110d64:	00c02025 */ 	or	$a0,$a2,$zero
/*  f110d68:	320500ff */ 	andi	$a1,$s0,0xff
/*  f110d6c:	0fc44317 */ 	jal	func0f110c5c
/*  f110d70:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f110d74:	10000001 */ 	b	.L0f110d7c
/*  f110d78:	8fa20024 */ 	lw	$v0,0x24($sp)
.L0f110d7c:
/*  f110d7c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f110d80:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f110d84:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f110d88:	03e00008 */ 	jr	$ra
/*  f110d8c:	00000000 */ 	nop
);

#if VERSION >= VERSION_NTSC_1_0
void func0f110d90(s32 index)
{
	var800a2330[index] = -1;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f110da8
/*  f110da8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f110dac:	3c0e8007 */ 	lui	$t6,%hi(var80075bf4)
/*  f110db0:	8dce5bf4 */ 	lw	$t6,%lo(var80075bf4)($t6)
/*  f110db4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f110db8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f110dbc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f110dc0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f110dc4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f110dc8:	15c0000c */ 	bnez	$t6,.L0f110dfc
/*  f110dcc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110dd0:	3c10800a */ 	lui	$s0,%hi(var800a2330)
/*  f110dd4:	3c03800a */ 	lui	$v1,%hi(var800a2344)
/*  f110dd8:	24632344 */ 	addiu	$v1,$v1,%lo(var800a2344)
/*  f110ddc:	26102330 */ 	addiu	$s0,$s0,%lo(var800a2330)
/*  f110de0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f110de4:
/*  f110de4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110de8:	1603fffe */ 	bne	$s0,$v1,.L0f110de4
/*  f110dec:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*  f110df0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f110df4:	3c018007 */ 	lui	$at,%hi(var80075bf4)
/*  f110df8:	ac2f5bf4 */ 	sw	$t7,%lo(var80075bf4)($at)
.L0f110dfc:
/*  f110dfc:	00009025 */ 	or	$s2,$zero,$zero
/*  f110e00:	00009825 */ 	or	$s3,$zero,$zero
/*  f110e04:	00128e00 */ 	sll	$s1,$s2,0x18
.L0f110e08:
/*  f110e08:	0011c603 */ 	sra	$t8,$s1,0x18
/*  f110e0c:	00182600 */ 	sll	$a0,$t8,0x18
/*  f110e10:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f110e14:	03202025 */ 	or	$a0,$t9,$zero
/*  f110e18:	0fc459f6 */ 	jal	func0f1167d8
/*  f110e1c:	03008825 */ 	or	$s1,$t8,$zero
/*  f110e20:	10400010 */ 	beqz	$v0,.L0f110e64
/*  f110e24:	00112600 */ 	sll	$a0,$s1,0x18
/*  f110e28:	3c0a800a */ 	lui	$t2,%hi(var800a2330)
/*  f110e2c:	254a2330 */ 	addiu	$t2,$t2,%lo(var800a2330)
/*  f110e30:	00044603 */ 	sra	$t0,$a0,0x18
/*  f110e34:	00124880 */ 	sll	$t1,$s2,0x2
/*  f110e38:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f110e3c:	0fc45c0b */ 	jal	func0f11702c
/*  f110e40:	01002025 */ 	or	$a0,$t0,$zero
/*  f110e44:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f110e48:	00112600 */ 	sll	$a0,$s1,0x18
/*  f110e4c:	00046603 */ 	sra	$t4,$a0,0x18
/*  f110e50:	104b0004 */ 	beq	$v0,$t3,.L0f110e64
/*  f110e54:	01802025 */ 	or	$a0,$t4,$zero
/*  f110e58:	0fc45c0b */ 	jal	func0f11702c
/*  f110e5c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f110e60:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f110e64:
/*  f110e64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f110e68:	2a410005 */ 	slti	$at,$s2,0x5
/*  f110e6c:	5420ffe6 */ 	bnezl	$at,.L0f110e08
/*  f110e70:	00128e00 */ 	sll	$s1,$s2,0x18
/*  f110e74:	3c108007 */ 	lui	$s0,%hi(g_FileLists)
/*  f110e78:	3c148007 */ 	lui	$s4,%hi(g_FileLists+0x10)
/*  f110e7c:	3c118007 */ 	lui	$s1,%hi(g_FileLists+0x10)
/*  f110e80:	26315bd0 */ 	addiu	$s1,$s1,%lo(g_FileLists+0x10)
/*  f110e84:	26945bd0 */ 	addiu	$s4,$s4,%lo(g_FileLists+0x10)
/*  f110e88:	26105bc0 */ 	addiu	$s0,$s0,%lo(g_FileLists)
/*  f110e8c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f110e90:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f110e94:
/*  f110e94:	5080001b */ 	beqzl	$a0,.L0f110f04
/*  f110e98:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110e9c:	a080030e */ 	sb	$zero,0x30e($a0)
/*  f110ea0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110ea4:	02601825 */ 	or	$v1,$s3,$zero
/*  f110ea8:	9082030c */ 	lbu	$v0,0x30c($a0)
/*  f110eac:	18400007 */ 	blez	$v0,.L0f110ecc
/*  f110eb0:	244dffff */ 	addiu	$t5,$v0,-1
/*  f110eb4:	a08d030c */ 	sb	$t5,0x30c($a0)
/*  f110eb8:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110ebc:	908e030c */ 	lbu	$t6,0x30c($a0)
/*  f110ec0:	55c00003 */ 	bnezl	$t6,.L0f110ed0
/*  f110ec4:	908f030b */ 	lbu	$t7,0x30b($a0)
/*  f110ec8:	02401825 */ 	or	$v1,$s2,$zero
.L0f110ecc:
/*  f110ecc:	908f030b */ 	lbu	$t7,0x30b($a0)
.L0f110ed0:
/*  f110ed0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f110ed4:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f110ed8:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f110edc:	11000002 */ 	beqz	$t0,.L0f110ee8
/*  f110ee0:	00000000 */ 	nop
/*  f110ee4:	02401825 */ 	or	$v1,$s2,$zero
.L0f110ee8:
/*  f110ee8:	50600006 */ 	beqzl	$v1,.L0f110f04
/*  f110eec:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110ef0:	0fc443d3 */ 	jal	func0f110f4c
/*  f110ef4:	00000000 */ 	nop
/*  f110ef8:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f110efc:	a132030e */ 	sb	$s2,0x30e($t1)
/*  f110f00:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f110f04:
/*  f110f04:	0214082b */ 	sltu	$at,$s0,$s4
/*  f110f08:	5420ffe2 */ 	bnezl	$at,.L0f110e94
/*  f110f0c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110f10:	3c028007 */ 	lui	$v0,%hi(g_FileLists+0x10)
/*  f110f14:	3c038007 */ 	lui	$v1,%hi(var80075be0)
/*  f110f18:	24635be0 */ 	addiu	$v1,$v1,%lo(var80075be0)
/*  f110f1c:	24425bd0 */ 	addiu	$v0,$v0,%lo(g_FileLists+0x10)
.L0f110f20:
/*  f110f20:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f110f24:	1443fffe */ 	bne	$v0,$v1,.L0f110f20
/*  f110f28:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f110f2c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f110f30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f110f34:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f110f38:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f110f3c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f110f40:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f110f44:	03e00008 */ 	jr	$ra
/*  f110f48:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#else
GLOBAL_ASM(
glabel func0f110da8
/*  f10b200:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f10b204:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10b208:	8dce7f94 */ 	lw	$t6,0x7f94($t6)
/*  f10b20c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f10b210:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f10b214:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f10b218:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f10b21c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f10b220:	15c0000c */ 	bnez	$t6,.NB0f10b254
/*  f10b224:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10b228:	3c10800a */ 	lui	$s0,0x800a
/*  f10b22c:	3c03800a */ 	lui	$v1,0x800a
/*  f10b230:	24636834 */ 	addiu	$v1,$v1,0x6834
/*  f10b234:	26106820 */ 	addiu	$s0,$s0,0x6820
/*  f10b238:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f10b23c:
/*  f10b23c:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10b240:	1603fffe */ 	bne	$s0,$v1,.NB0f10b23c
/*  f10b244:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*  f10b248:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10b24c:	3c018007 */ 	lui	$at,0x8007
/*  f10b250:	ac2f7f94 */ 	sw	$t7,0x7f94($at)
.NB0f10b254:
/*  f10b254:	3c10800a */ 	lui	$s0,0x800a
/*  f10b258:	26106820 */ 	addiu	$s0,$s0,0x6820
/*  f10b25c:	00009825 */ 	or	$s3,$zero,$zero
/*  f10b260:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f10b264:
/*  f10b264:	00138e00 */ 	sll	$s1,$s3,0x18
/*  f10b268:	0011c603 */ 	sra	$t8,$s1,0x18
/*  f10b26c:	00182600 */ 	sll	$a0,$t8,0x18
/*  f10b270:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f10b274:	03202025 */ 	or	$a0,$t9,$zero
/*  f10b278:	0fc444e1 */ 	jal	func0f11702c
/*  f10b27c:	03008825 */ 	or	$s1,$t8,$zero
/*  f10b280:	00112600 */ 	sll	$a0,$s1,0x18
/*  f10b284:	00044603 */ 	sra	$t0,$a0,0x18
/*  f10b288:	00409025 */ 	or	$s2,$v0,$zero
/*  f10b28c:	0fc44354 */ 	jal	func0f11698c
/*  f10b290:	01002025 */ 	or	$a0,$t0,$zero
/*  f10b294:	00112600 */ 	sll	$a0,$s1,0x18
/*  f10b298:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f10b29c:	0fc442e7 */ 	jal	func0f1167d8
/*  f10b2a0:	01202025 */ 	or	$a0,$t1,$zero
/*  f10b2a4:	10400002 */ 	beqz	$v0,.NB0f10b2b0
/*  f10b2a8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f10b2ac:	00009025 */ 	or	$s2,$zero,$zero
.NB0f10b2b0:
/*  f10b2b0:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f10b2b4:	2a610005 */ 	slti	$at,$s3,0x5
/*  f10b2b8:	124a0003 */ 	beq	$s2,$t2,.NB0f10b2c8
/*  f10b2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10b2c0:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f10b2c4:	ae120000 */ 	sw	$s2,0x0($s0)
.NB0f10b2c8:
/*  f10b2c8:	1420ffe6 */ 	bnez	$at,.NB0f10b264
/*  f10b2cc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10b2d0:	3c108007 */ 	lui	$s0,0x8007
/*  f10b2d4:	3c138007 */ 	lui	$s3,0x8007
/*  f10b2d8:	3c118007 */ 	lui	$s1,0x8007
/*  f10b2dc:	26317f70 */ 	addiu	$s1,$s1,0x7f70
/*  f10b2e0:	26737f70 */ 	addiu	$s3,$s3,0x7f70
/*  f10b2e4:	26107f60 */ 	addiu	$s0,$s0,0x7f60
/*  f10b2e8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f10b2ec:	8e040000 */ 	lw	$a0,0x0($s0)
.NB0f10b2f0:
/*  f10b2f0:	5080001b */ 	beqzl	$a0,.NB0f10b360
/*  f10b2f4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10b2f8:	a080030e */ 	sb	$zero,0x30e($a0)
/*  f10b2fc:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f10b300:	02801825 */ 	or	$v1,$s4,$zero
/*  f10b304:	9082030c */ 	lbu	$v0,0x30c($a0)
/*  f10b308:	18400007 */ 	blez	$v0,.NB0f10b328
/*  f10b30c:	244bffff */ 	addiu	$t3,$v0,-1
/*  f10b310:	a08b030c */ 	sb	$t3,0x30c($a0)
/*  f10b314:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f10b318:	908c030c */ 	lbu	$t4,0x30c($a0)
/*  f10b31c:	55800003 */ 	bnezl	$t4,.NB0f10b32c
/*  f10b320:	908d030b */ 	lbu	$t5,0x30b($a0)
/*  f10b324:	02401825 */ 	or	$v1,$s2,$zero
.NB0f10b328:
/*  f10b328:	908d030b */ 	lbu	$t5,0x30b($a0)
.NB0f10b32c:
/*  f10b32c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f10b330:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f10b334:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f10b338:	13000002 */ 	beqz	$t8,.NB0f10b344
/*  f10b33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10b340:	02401825 */ 	or	$v1,$s2,$zero
.NB0f10b344:
/*  f10b344:	50600006 */ 	beqzl	$v1,.NB0f10b360
/*  f10b348:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10b34c:	0fc42cea */ 	jal	func0f110f4c
/*  f10b350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10b354:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f10b358:	a332030e */ 	sb	$s2,0x30e($t9)
/*  f10b35c:	26100004 */ 	addiu	$s0,$s0,0x4
.NB0f10b360:
/*  f10b360:	0213082b */ 	sltu	$at,$s0,$s3
/*  f10b364:	5420ffe2 */ 	bnezl	$at,.NB0f10b2f0
/*  f10b368:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f10b36c:	3c028007 */ 	lui	$v0,0x8007
/*  f10b370:	3c038007 */ 	lui	$v1,0x8007
/*  f10b374:	24637f80 */ 	addiu	$v1,$v1,0x7f80
/*  f10b378:	24427f70 */ 	addiu	$v0,$v0,0x7f70
.NB0f10b37c:
/*  f10b37c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f10b380:	1443fffe */ 	bne	$v0,$v1,.NB0f10b37c
/*  f10b384:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f10b388:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f10b38c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10b390:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f10b394:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f10b398:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f10b39c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f10b3a0:	03e00008 */ 	jr	$ra
/*  f10b3a4:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#endif

const char var7f1b39c8[] = "";
const char var7f1b39cc[] = "";
const char var7f1b39d0[] = "Rebuilding pakWad %d:\n";

const u32 var7f1b39e8[] = {0x00000080};
const u32 var7f1b39ec[] = {0x00000040};
const u32 var7f1b39f0[] = {0x00000020};
const u32 var7f1b39f4[] = {0x00000008};
const u32 var7f1b39f8[] = {0x04000102};
const u32 var7f1b39fc[] = {0x03000000};
const u32 var7f1b3a00[] = {0x01020304};
const u32 var7f1b3a04[] = {0x00000000};

const char var7f1b3a08[] = "tc != NULL";
const char var7f1b3a14[] = "gamefile.c";

GLOBAL_ASM(
glabel func0f110f4c
/*  f110f4c:	27bdc568 */ 	addiu	$sp,$sp,-15000
/*  f110f50:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b39e8)
/*  f110f54:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f110f58:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f110f5c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f110f60:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f110f64:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f110f68:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f110f6c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f110f70:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f110f74:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f110f78:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110f7c:	25ce39e8 */ 	addiu	$t6,$t6,%lo(var7f1b39e8)
/*  f110f80:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f110f84:	27b43a88 */ 	addiu	$s4,$sp,0x3a88
/*  f110f88:	3c097f1b */ 	lui	$t1,%hi(var7f1b39f8)
/*  f110f8c:	ae810000 */ 	sw	$at,0x0($s4)
/*  f110f90:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f110f94:	252939f8 */ 	addiu	$t1,$t1,%lo(var7f1b39f8)
/*  f110f98:	27a80070 */ 	addiu	$t0,$sp,0x70
/*  f110f9c:	ae990004 */ 	sw	$t9,0x4($s4)
/*  f110fa0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f110fa4:	3c0d7f1b */ 	lui	$t5,%hi(var7f1b3a00)
/*  f110fa8:	25ad3a00 */ 	addiu	$t5,$t5,%lo(var7f1b3a00)
/*  f110fac:	ae810008 */ 	sw	$at,0x8($s4)
/*  f110fb0:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f110fb4:	27b70068 */ 	addiu	$s7,$sp,0x68
/*  f110fb8:	00809025 */ 	or	$s2,$a0,$zero
/*  f110fbc:	ae99000c */ 	sw	$t9,0xc($s4)
/*  f110fc0:	8d210000 */ 	lw	$at,0x0($t1)
/*  f110fc4:	27b00070 */ 	addiu	$s0,$sp,0x70
/*  f110fc8:	00008825 */ 	or	$s1,$zero,$zero
/*  f110fcc:	ad010000 */ 	sw	$at,0x0($t0)
/*  f110fd0:	91210004 */ 	lbu	$at,0x4($t1)
/*  f110fd4:	00809825 */ 	or	$s3,$a0,$zero
/*  f110fd8:	27b50a88 */ 	addiu	$s5,$sp,0xa88
/*  f110fdc:	a1010004 */ 	sb	$at,0x4($t0)
/*  f110fe0:	8da10000 */ 	lw	$at,0x0($t5)
/*  f110fe4:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f110fe8:	241e0003 */ 	addiu	$s8,$zero,0x3
/*  f110fec:	aee10000 */ 	sw	$at,0x0($s7)
/*  f110ff0:	91a10004 */ 	lbu	$at,0x4($t5)
/*  f110ff4:	a2e10004 */ 	sb	$at,0x4($s7)
/*  f110ff8:	a080030a */ 	sb	$zero,0x30a($a0)
.L0f110ffc:
/*  f110ffc:	82190000 */ 	lb	$t9,0x0($s0)
/*  f111000:	02a03025 */ 	or	$a2,$s5,$zero
/*  f111004:	02595821 */ 	addu	$t3,$s2,$t9
/*  f111008:	a1600305 */ 	sb	$zero,0x305($t3)
/*  f11100c:	a2760300 */ 	sb	$s6,0x300($s3)
/*  f111010:	924a030b */ 	lbu	$t2,0x30b($s2)
/*  f111014:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111018:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f11101c:	02884821 */ 	addu	$t1,$s4,$t0
/*  f111020:	0fc459ec */ 	jal	func0f1167b0
/*  f111024:	8d250000 */ 	lw	$a1,0x0($t1)
/*  f111028:	14400028 */ 	bnez	$v0,.L0f1110cc
/*  f11102c:	8fac0a88 */ 	lw	$t4,0xa88($sp)
/*  f111030:	11800010 */ 	beqz	$t4,.L0f111074
/*  f111034:	00117880 */ 	sll	$t7,$s1,0x2
/*  f111038:	27b81288 */ 	addiu	$t8,$sp,0x1288
/*  f11103c:	27a30a88 */ 	addiu	$v1,$sp,0xa88
/*  f111040:	27ae0088 */ 	addiu	$t6,$sp,0x88
/*  f111044:	022e2821 */ 	addu	$a1,$s1,$t6
/*  f111048:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f11104c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f111050:	82060000 */ 	lb	$a2,0x0($s0)
.L0f111054:
/*  f111054:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f111058:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f11105c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f111060:	a0a60000 */ 	sb	$a2,0x0($a1)
/*  f111064:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f111068:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f11106c:	1480fff9 */ 	bnez	$a0,.L0f111054
/*  f111070:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f111074:
/*  f111074:	82190000 */ 	lb	$t9,0x0($s0)
/*  f111078:	02595821 */ 	addu	$t3,$s2,$t9
/*  f11107c:	a16002d2 */ 	sb	$zero,0x2d2($t3)
/*  f111080:	924a030b */ 	lbu	$t2,0x30b($s2)
/*  f111084:	57ca0007 */ 	bnel	$s8,$t2,.L0f1110a4
/*  f111088:	820c0000 */ 	lb	$t4,0x0($s0)
/*  f11108c:	0fc46052 */ 	jal	func0f118148
/*  f111090:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111094:	82080000 */ 	lb	$t0,0x0($s0)
/*  f111098:	02484821 */ 	addu	$t1,$s2,$t0
/*  f11109c:	a12202d2 */ 	sb	$v0,0x2d2($t1)
/*  f1110a0:	820c0000 */ 	lb	$t4,0x0($s0)
.L0f1110a4:
/*  f1110a4:	000c78c0 */ 	sll	$t7,$t4,0x3
/*  f1110a8:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f1110ac:	af0002d8 */ 	sw	$zero,0x2d8($t8)
/*  f1110b0:	0fc45a4f */ 	jal	func0f11693c
/*  f1110b4:	82040000 */ 	lb	$a0,0x0($s0)
/*  f1110b8:	820d0000 */ 	lb	$t5,0x0($s0)
/*  f1110bc:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1110c0:	024ec821 */ 	addu	$t9,$s2,$t6
/*  f1110c4:	10000008 */ 	b	.L0f1110e8
/*  f1110c8:	a72202dc */ 	sh	$v0,0x2dc($t9)
.L0f1110cc:
/*  f1110cc:	820b0000 */ 	lb	$t3,0x0($s0)
/*  f1110d0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f1110d4:	24080005 */ 	addiu	$t0,$zero,0x5
/*  f1110d8:	024b5021 */ 	addu	$t2,$s2,$t3
/*  f1110dc:	14410002 */ 	bne	$v0,$at,.L0f1110e8
/*  f1110e0:	a15602d2 */ 	sb	$s6,0x2d2($t2)
/*  f1110e4:	a248030c */ 	sb	$t0,0x30c($s2)
.L0f1110e8:
/*  f1110e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1110ec:	27a90075 */ 	addiu	$t1,$sp,0x75
/*  f1110f0:	0209082b */ 	sltu	$at,$s0,$t1
/*  f1110f4:	1420ffc1 */ 	bnez	$at,.L0f110ffc
/*  f1110f8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1110fc:	a64002d0 */ 	sh	$zero,0x2d0($s2)
/*  f111100:	1a20004b */ 	blez	$s1,.L0f111230
/*  f111104:	0000a825 */ 	or	$s5,$zero,$zero
/*  f111108:	27b00088 */ 	addiu	$s0,$sp,0x88
/*  f11110c:	27b41288 */ 	addiu	$s4,$sp,0x1288
/*  f111110:	241e0018 */ 	addiu	$s8,$zero,0x18
.L0f111114:
/*  f111114:	864c02d0 */ 	lh	$t4,0x2d0($s2)
/*  f111118:	82040000 */ 	lb	$a0,0x0($s0)
/*  f11111c:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f111120:	019e0019 */ 	multu	$t4,$s8
/*  f111124:	24070010 */ 	addiu	$a3,$zero,0x10
/*  f111128:	00007812 */ 	mflo	$t7
/*  f11112c:	024f9821 */ 	addu	$s3,$s2,$t7
/*  f111130:	0fc45a00 */ 	jal	func0f116800
/*  f111134:	26660006 */ 	addiu	$a2,$s3,0x6
/*  f111138:	1440001b */ 	bnez	$v0,.L0f1111a8
/*  f11113c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f111140:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111144:	02e4c021 */ 	addu	$t8,$s7,$a0
/*  f111148:	830d0000 */ 	lb	$t5,0x0($t8)
/*  f11114c:	024d7021 */ 	addu	$t6,$s2,$t5
/*  f111150:	81d90300 */ 	lb	$t9,0x300($t6)
/*  f111154:	16d9000b */ 	bne	$s6,$t9,.L0f111184
/*  f111158:	00000000 */ 	nop
/*  f11115c:	924b030a */ 	lbu	$t3,0x30a($s2)
/*  f111160:	864802d0 */ 	lh	$t0,0x2d0($s2)
/*  f111164:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f111168:	a24a030a */ 	sb	$t2,0x30a($s2)
/*  f11116c:	82090000 */ 	lb	$t1,0x0($s0)
/*  f111170:	02e96021 */ 	addu	$t4,$s7,$t1
/*  f111174:	818f0000 */ 	lb	$t7,0x0($t4)
/*  f111178:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f11117c:	a3080300 */ 	sb	$t0,0x300($t8)
/*  f111180:	82040000 */ 	lb	$a0,0x0($s0)
.L0f111184:
/*  f111184:	0fc45a4f */ 	jal	func0f11693c
/*  f111188:	00000000 */ 	nop
/*  f11118c:	a6620004 */ 	sh	$v0,0x4($s3)
/*  f111190:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f111194:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f111198:	864e02d0 */ 	lh	$t6,0x2d0($s2)
/*  f11119c:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f1111a0:	1000001f */ 	b	.L0f111220
/*  f1111a4:	a65902d0 */ 	sh	$t9,0x2d0($s2)
.L0f1111a8:
/*  f1111a8:	5441001e */ 	bnel	$v0,$at,.L0f111224
/*  f1111ac:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1111b0:	820b0000 */ 	lb	$t3,0x0($s0)
/*  f1111b4:	024b1021 */ 	addu	$v0,$s2,$t3
/*  f1111b8:	804a0305 */ 	lb	$t2,0x305($v0)
/*  f1111bc:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f1111c0:	a0490305 */ 	sb	$t1,0x305($v0)
/*  f1111c4:	820c0000 */ 	lb	$t4,0x0($s0)
/*  f1111c8:	024c1021 */ 	addu	$v0,$s2,$t4
/*  f1111cc:	804f0305 */ 	lb	$t7,0x305($v0)
/*  f1111d0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f1111d4:	54200013 */ 	bnezl	$at,.L0f111224
/*  f1111d8:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1111dc:	804802d2 */ 	lb	$t0,0x2d2($v0)
/*  f1111e0:	25180001 */ 	addiu	$t8,$t0,0x1
/*  f1111e4:	a05802d2 */ 	sb	$t8,0x2d2($v0)
/*  f1111e8:	820d0000 */ 	lb	$t5,0x0($s0)
/*  f1111ec:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1111f0:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f1111f4:	8c7902d8 */ 	lw	$t9,0x2d8($v1)
/*  f1111f8:	5720000a */ 	bnezl	$t9,.L0f111224
/*  f1111fc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f111200:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f111204:	ac6b02d8 */ 	sw	$t3,0x2d8($v1)
/*  f111208:	0fc45a4f */ 	jal	func0f11693c
/*  f11120c:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111210:	820a0000 */ 	lb	$t2,0x0($s0)
/*  f111214:	000a48c0 */ 	sll	$t1,$t2,0x3
/*  f111218:	02496021 */ 	addu	$t4,$s2,$t1
/*  f11121c:	a58202dc */ 	sh	$v0,0x2dc($t4)
.L0f111220:
/*  f111220:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f111224:
/*  f111224:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f111228:	16b1ffba */ 	bne	$s5,$s1,.L0f111114
/*  f11122c:	26940004 */ 	addiu	$s4,$s4,0x4
.L0f111230:
/*  f111230:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f111234:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f111238:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11123c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f111240:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f111244:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f111248:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f11124c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f111250:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f111254:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f111258:	03e00008 */ 	jr	$ra
/*  f11125c:	27bd3a98 */ 	addiu	$sp,$sp,0x3a98
/*  f111260:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f111264:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f111268:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11126c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f111270:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f111274:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f111278:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11127c:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f111280:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f111284:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f111288:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f11128c:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f111290:	8e030e68 */ 	lw	$v1,0xe68($s0)
/*  f111294:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f111298:	14600017 */ 	bnez	$v1,.L0f1112f8
/*  f11129c:	00000000 */ 	nop
/*  f1112a0:	54a00011 */ 	bnezl	$a1,.L0f1112e8
/*  f1112a4:	92090e40 */ 	lbu	$t1,0xe40($s0)
/*  f1112a8:	92190e40 */ 	lbu	$t9,0xe40($s0)
/*  f1112ac:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f1112b0:	37280040 */ 	ori	$t0,$t9,0x40
/*  f1112b4:	0fc5db69 */ 	jal	align16
/*  f1112b8:	a2080e40 */ 	sb	$t0,0xe40($s0)
/*  f1112bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1112c0:	0fc5796e */ 	jal	func0f15e5b8
/*  f1112c4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1112c8:	0fc5db69 */ 	jal	align16
/*  f1112cc:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f1112d0:	0c004aac */ 	jal	func00012ab0
/*  f1112d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1112d8:	ae020e68 */ 	sw	$v0,0xe68($s0)
/*  f1112dc:	10000006 */ 	b	.L0f1112f8
/*  f1112e0:	00401825 */ 	or	$v1,$v0,$zero
/*  f1112e4:	92090e40 */ 	lbu	$t1,0xe40($s0)
.L0f1112e8:
/*  f1112e8:	ae050e68 */ 	sw	$a1,0xe68($s0)
/*  f1112ec:	00a01825 */ 	or	$v1,$a1,$zero
/*  f1112f0:	312affbf */ 	andi	$t2,$t1,0xffbf
/*  f1112f4:	a20a0e40 */ 	sb	$t2,0xe40($s0)
.L0f1112f8:
/*  f1112f8:	14600006 */ 	bnez	$v1,.L0f111314
/*  f1112fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b3a08)
/*  f111300:	3c057f1b */ 	lui	$a1,%hi(var7f1b3a14)
/*  f111304:	24a53a14 */ 	addiu	$a1,$a1,%lo(var7f1b3a14)
/*  f111308:	24843a08 */ 	addiu	$a0,$a0,%lo(var7f1b3a08)
/*  f11130c:	0c002ff4 */ 	jal	func0000bfd0
/*  f111310:	240601ca */ 	addiu	$a2,$zero,0x1ca
.L0f111314:
/*  f111314:	00001025 */ 	or	$v0,$zero,$zero
/*  f111318:	24030080 */ 	addiu	$v1,$zero,0x80
.L0f11131c:
/*  f11131c:	8e0b0e68 */ 	lw	$t3,0xe68($s0)
/*  f111320:	01626021 */ 	addu	$t4,$t3,$v0
/*  f111324:	ad800800 */ 	sw	$zero,0x800($t4)
/*  f111328:	8e0d0e68 */ 	lw	$t5,0xe68($s0)
/*  f11132c:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f111330:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f111334:	1443fff9 */ 	bne	$v0,$v1,.L0f11131c
/*  f111338:	a5c00804 */ 	sh	$zero,0x804($t6)
/*  f11133c:	8e0f0e68 */ 	lw	$t7,0xe68($s0)
/*  f111340:	24020010 */ 	addiu	$v0,$zero,0x10
/*  f111344:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f111348:	ade00880 */ 	sw	$zero,0x880($t7)
/*  f11134c:	8e180e68 */ 	lw	$t8,0xe68($s0)
/*  f111350:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f111354:	00001825 */ 	or	$v1,$zero,$zero
/*  f111358:	a3020888 */ 	sb	$v0,0x888($t8)
/*  f11135c:	8e190e68 */ 	lw	$t9,0xe68($s0)
/*  f111360:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f111364:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f111368:	a3220889 */ 	sb	$v0,0x889($t9)
/*  f11136c:	8e080e68 */ 	lw	$t0,0xe68($s0)
/*  f111370:	a100088a */ 	sb	$zero,0x88a($t0)
/*  f111374:	8e0a0e68 */ 	lw	$t2,0xe68($s0)
/*  f111378:	a149088b */ 	sb	$t1,0x88b($t2)
/*  f11137c:	8e0b0e68 */ 	lw	$t3,0xe68($s0)
/*  f111380:	a160088c */ 	sb	$zero,0x88c($t3)
/*  f111384:	8e0c0e68 */ 	lw	$t4,0xe68($s0)
/*  f111388:	a180088d */ 	sb	$zero,0x88d($t4)
/*  f11138c:	8e0e0e68 */ 	lw	$t6,0xe68($s0)
/*  f111390:	a1cd088e */ 	sb	$t5,0x88e($t6)
/*  f111394:	8e0f0e68 */ 	lw	$t7,0xe68($s0)
/*  f111398:	a1e0088f */ 	sb	$zero,0x88f($t7)
/*  f11139c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1113a0:
/*  f1113a0:	8e190e68 */ 	lw	$t9,0xe68($s0)
/*  f1113a4:	000341c0 */ 	sll	$t0,$v1,0x7
/*  f1113a8:	0040c025 */ 	or	$t8,$v0,$zero
/*  f1113ac:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1113b0:	01225021 */ 	addu	$t2,$t1,$v0
/*  f1113b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1113b8:	1444fff9 */ 	bne	$v0,$a0,.L0f1113a0
/*  f1113bc:	a1580000 */ 	sb	$t8,0x0($t2)
/*  f1113c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1113c4:	5465fff6 */ 	bnel	$v1,$a1,.L0f1113a0
/*  f1113c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1113cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1113d0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1113d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1113d8:	03e00008 */ 	jr	$ra
/*  f1113dc:	00000000 */ 	nop
/*  f1113e0:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f1113e4:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f1113e8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1113ec:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f1113f0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f1113f4:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f1113f8:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f1113fc:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f111400:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f111404:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f111408:	8c780e68 */ 	lw	$t8,0xe68($v1)
/*  f11140c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f111410:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f111414:	5300000f */ 	beqzl	$t8,.L0f111454
/*  f111418:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11141c:	8c790e40 */ 	lw	$t9,0xe40($v1)
/*  f111420:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f111424:	00194840 */ 	sll	$t1,$t9,0x1
/*  f111428:	05230009 */ 	bgezl	$t1,.L0f111450
/*  f11142c:	ac600e68 */ 	sw	$zero,0xe68($v1)
/*  f111430:	0fc5db69 */ 	jal	align16
/*  f111434:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f111438:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f11143c:	00402825 */ 	or	$a1,$v0,$zero
/*  f111440:	0c004b2d */ 	jal	func00012cb4
/*  f111444:	8c640e68 */ 	lw	$a0,0xe68($v1)
/*  f111448:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f11144c:	ac600e68 */ 	sw	$zero,0xe68($v1)
.L0f111450:
/*  f111450:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f111454:
/*  f111454:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f111458:	03e00008 */ 	jr	$ra
/*  f11145c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f111460
/*  f111460:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f111464:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f111468:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11146c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f111470:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f111474:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f111478:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11147c:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f111480:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f111484:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f111488:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11148c:	01cf5021 */ 	addu	$t2,$t6,$t7
/*  f111490:	30d0ffff */ 	andi	$s0,$a2,0xffff
/*  f111494:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f111498:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f11149c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f1114a0:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1114a4:	8d420e68 */ 	lw	$v0,0xe68($t2)
/*  f1114a8:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f1114ac:	00003825 */ 	or	$a3,$zero,$zero
.L0f1114b0:
/*  f1114b0:	8c430800 */ 	lw	$v1,0x800($v0)
/*  f1114b4:	14a30006 */ 	bne	$a1,$v1,.L0f1114d0
/*  f1114b8:	00000000 */ 	nop
/*  f1114bc:	94580804 */ 	lhu	$t8,0x804($v0)
/*  f1114c0:	16180003 */ 	bne	$s0,$t8,.L0f1114d0
/*  f1114c4:	00000000 */ 	nop
/*  f1114c8:	1000000a */ 	b	.L0f1114f4
/*  f1114cc:	00e04825 */ 	or	$t1,$a3,$zero
.L0f1114d0:
/*  f1114d0:	54600006 */ 	bnezl	$v1,.L0f1114ec
/*  f1114d4:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1114d8:	94590804 */ 	lhu	$t9,0x804($v0)
/*  f1114dc:	57200003 */ 	bnezl	$t9,.L0f1114ec
/*  f1114e0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1114e4:	00e04025 */ 	or	$t0,$a3,$zero
/*  f1114e8:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f1114ec:
/*  f1114ec:	14e4fff0 */ 	bne	$a3,$a0,.L0f1114b0
/*  f1114f0:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f1114f4:
/*  f1114f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1114f8:	1521002f */ 	bne	$t1,$at,.L0f1115b8
/*  f1114fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f111500:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f111504:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f111508:	0fc479ac */ 	jal	pakSearch
/*  f11150c:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f111510:	00022600 */ 	sll	$a0,$v0,0x18
/*  f111514:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f111518:	01602025 */ 	or	$a0,$t3,$zero
/*  f11151c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f111520:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f111524:	04410003 */ 	bgez	$v0,.L0f111534
/*  f111528:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f11152c:	1000002d */ 	b	.L0f1115e4
/*  f111530:	00001025 */ 	or	$v0,$zero,$zero
.L0f111534:
/*  f111534:	2401ffff */ 	addiu	$at,$zero,-1
/*  f111538:	55010004 */ 	bnel	$t0,$at,.L0f11154c
/*  f11153c:	8d430e68 */ 	lw	$v1,0xe68($t2)
/*  f111540:	10000028 */ 	b	.L0f1115e4
/*  f111544:	00001025 */ 	or	$v0,$zero,$zero
/*  f111548:	8d430e68 */ 	lw	$v1,0xe68($t2)
.L0f11154c:
/*  f11154c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x58)
/*  f111550:	8c42a018 */ 	lw	$v0,%lo(g_Vars+0x58)($v0)
/*  f111554:	8c6c0880 */ 	lw	$t4,0x880($v1)
/*  f111558:	000879c0 */ 	sll	$t7,$t0,0x7
/*  f11155c:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f111560:	29a10014 */ 	slti	$at,$t5,0x14
/*  f111564:	50200004 */ 	beqzl	$at,.L0f111578
/*  f111568:	ac620880 */ 	sw	$v0,0x880($v1)
/*  f11156c:	1000001d */ 	b	.L0f1115e4
/*  f111570:	00001025 */ 	or	$v0,$zero,$zero
/*  f111574:	ac620880 */ 	sw	$v0,0x880($v1)
.L0f111578:
/*  f111578:	8d4e0e68 */ 	lw	$t6,0xe68($t2)
/*  f11157c:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f111580:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f111584:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f111588:	0fc54057 */ 	jal	func0f15015c
/*  f11158c:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f111590:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f111594:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f111598:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f11159c:	8d580e68 */ 	lw	$t8,0xe68($t2)
/*  f1115a0:	000918c0 */ 	sll	$v1,$t1,0x3
/*  f1115a4:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f1115a8:	af250800 */ 	sw	$a1,0x800($t9)
/*  f1115ac:	8d4b0e68 */ 	lw	$t3,0xe68($t2)
/*  f1115b0:	01636021 */ 	addu	$t4,$t3,$v1
/*  f1115b4:	a5900804 */ 	sh	$s0,0x804($t4)
.L0f1115b8:
/*  f1115b8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1115bc:	55210004 */ 	bnel	$t1,$at,.L0f1115d0
/*  f1115c0:	8d430e68 */ 	lw	$v1,0xe68($t2)
/*  f1115c4:	10000007 */ 	b	.L0f1115e4
/*  f1115c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1115cc:	8d430e68 */ 	lw	$v1,0xe68($t2)
.L0f1115d0:
/*  f1115d0:	000969c0 */ 	sll	$t5,$t1,0x7
/*  f1115d4:	006d7021 */ 	addu	$t6,$v1,$t5
/*  f1115d8:	ac6e0884 */ 	sw	$t6,0x884($v1)
/*  f1115dc:	8d420e68 */ 	lw	$v0,0xe68($t2)
/*  f1115e0:	24420884 */ 	addiu	$v0,$v0,2180
.L0f1115e4:
/*  f1115e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1115e8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1115ec:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1115f0:	03e00008 */ 	jr	$ra
/*  f1115f4:	00000000 */ 	nop
);
