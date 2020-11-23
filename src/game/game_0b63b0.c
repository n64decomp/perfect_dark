#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_006bd0.h"
#include "game/title.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/game_0601b0.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096750.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0abe70.h"
#include "game/game_0b0420.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_0d5a90.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/explosion.h"
#include "game/game_141820.h"
#include "game/game_1531a0.h"
#include "game/game_157db0.h"
#include "game/game_1655c0.h"
#include "game/game_165670.h"
#include "game/game_1668e0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/music.h"
#include "game/game_16e810.h"
#include "game/game_177e00.h"
#include "game/game_17f930.h"
#include "game/game_18e5a0.h"
#include "game/training.h"
#include "game/game_1a3340.h"
#include "game/mplayer.h"
#include "game/pad.h"
#include "game/pak/pak.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "gvars/gvars.h"
#include "lib/lib_04320.h"
#include "lib/lib_04840.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13900.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1ad160[] = "ACOUSTIC -> Allocating %d bytes for %d portal AV structures\n";
const char var7f1ad1a0[] = "ACOUSTIC -> DGD WARNING: portalAVInit no portals!\n";
const char var7f1ad1d4[] = "ACOUSTIC -> portalAVReset: checking propobj type %d\n";
const char var7f1ad20c[] = "ACOUSTIC -> portalAVReset: found PROPDEF_WINDOWFADE for portal %d\n";
const char var7f1ad250[] = "ACOUSTIC -> portalAVReset: found PROPDEF_WINDOW for portal %d\n";
const char var7f1ad290[] = "ACOUSTIC -> Portal %3d - A=%.2f, V=%.2f\n";
const char var7f1ad2bc[] = "ACOUSTIC -> DGD WARNING: portalAVReset no portals!\n";
const char var7f1ad2f0[] = "Acoustic Reset -> Allocating %d bytes for %d roomacousticdata structures\n";
const char var7f1ad33c[] = "ACOUSTIC ->    room %d bb %f %f\n";
const char var7f1ad360[] = "ACOUSTIC -> DGD: acousticReset room %d does not have a 3D bounding box => radata[room].roomvolume is bodged!\n";
const char var7f1ad3d0[] = "%s%sL2 -> Surface area bodged for room %d - using %f\n";
const u32 var7f1ad408[] = {0x00000000};
const u32 var7f1ad40c[] = {0x00000000};

const u32 var7f1ad410[] = {0x3b808081};
const u32 var7f1ad414[] = {0x3d888889};
const u32 var7f1ad418[] = {0x4b989680};
const u32 var7f1ad41c[] = {0x00000000};

const char var7f1ad420[] = "Gunmem: 0x%08x\n";
const char var7f1ad430[] = "Gunmem: bondsub 0x%08x\n";
const char var7f1ad448[] = "Gunmem: bondsub->anim 0x%08x\n";
const char var7f1ad468[] = "Gunmem: savedata 0x%08x\n";
const char var7f1ad484[] = "Gunmem: wo 0x%08x\n";
const char var7f1ad498[] = "Jo using %d bytes gunmem (gunmemsize %d)\n";
const char var7f1ad4c4[] = "Gunmem: bondmeml 0x%08x size 0x%08x\n";
const char var7f1ad4ec[] = "Gunmem: tex block free 0x%08x\n";
const char var7f1ad50c[] = "Gunmem: Free at end %d\n";

u32 var80070780 = 0x00000000;
u32 var80070784 = 0x00000000;
u32 var80070788 = 0x00000000;
u32 var8007078c = 0x01000008;
u32 var80070790 = 0x00f5ffff;
u32 var80070794 = 0x00004000;
u32 var80070798 = 0x00000000;
u32 var8007079c = 0x00000000;
u32 var800707a0 = 0x00000000;
u32 var800707a4 = 0x00000000;
u32 var800707a8 = 0x3f800000;
u32 var800707ac = 0x00000000;
u32 var800707b0 = 0x00000000;
u32 var800707b4 = 0x00000000;
u32 var800707b8 = 0x3f800000;
u32 var800707bc = 0x00000000;
u32 var800707c0 = 0x00000000;
u32 var800707c4 = 0x00000000;
u32 var800707c8 = 0x3f800000;
u32 var800707cc = 0x00000000;
u32 var800707d0 = 0x00000000;
u32 var800707d4 = 0x00000000;
u32 var800707d8 = 0x000003e8;
u32 var800707dc = 0xffffff00;
u32 var800707e0 = 0xffffff00;
u32 var800707e4 = 0x0fff0000;
u32 var800707e8 = 0x02000000;
u32 var800707ec = 0x00ffffff;
u32 var800707f0 = 0x00000000;
u32 var800707f4 = 0x00000000;
u32 var800707f8 = 0x00000000;
u32 var800707fc = 0x00000000;
u32 var80070800 = 0x00000000;
u32 var80070804 = 0x00000000;
u32 var80070808 = 0x3f800000;
u32 var8007080c = 0x00000000;
u32 var80070810 = 0x3f800000;
u32 var80070814 = 0x00000000;
u32 var80070818 = 0x00000000;
u32 var8007081c = 0x00000000;
u32 var80070820 = 0x00000000;
u32 var80070824 = 0x00000000;
u32 var80070828 = 0x00000000;
u32 var8007082c = 0x3f800000;
u32 var80070830 = 0x00000000;
u32 var80070834 = 0x3f800000;
u32 var80070838 = 0x00000000;
u32 var8007083c = 0x00000000;
u32 g_PauseMode = 0x00000000;
u32 var80070844 = 0x00000000;
u32 var80070848 = 0x40a00000;
u32 var8007084c = 0x42200000;
u32 var80070850 = 0x3f333333;
u32 var80070854 = 0x00000096;
u32 var80070858 = 0x00000000;
u32 var8007085c = 0x00000000;
u32 var80070860 = 0x00000000;
u32 var80070864 = 0x40a00000;
u32 var80070868 = 0x42200000;
u32 var8007086c = 0x3f333333;
u32 var80070870 = 0x00000096;
u32 var80070874 = 0x00000000;
u32 var80070878 = 0x00000000;
u32 var8007087c = 0x00000000;
u32 var80070880 = 0x40a00000;
u32 var80070884 = 0x41f00000;
u32 var80070888 = 0x3f266666;
u32 var8007088c = 0x00000096;
u32 var80070890 = 0x00000000;
u32 var80070894 = 0x00000000;
u32 var80070898 = 0x00000000;
u32 var8007089c = 0x40a00000;
u32 var800708a0 = 0x41c80000;
u32 var800708a4 = 0x3f19999a;
u32 var800708a8 = 0x00000096;
u32 var800708ac = 0x00000000;
u32 var800708b0 = 0x00000000;
u32 var800708b4 = 0x00000000;
u32 var800708b8 = 0x40a00000;
u32 var800708bc = 0x41b00000;
u32 var800708c0 = 0x3f0ccccd;
u32 var800708c4 = 0x00000096;
u32 var800708c8 = 0x00000000;
u32 var800708cc = 0x00000000;
u32 var800708d0 = 0x00000000;
u32 var800708d4 = 0x40a00000;
u32 var800708d8 = 0x41980000;
u32 var800708dc = 0x3f000000;
u32 var800708e0 = 0x00000096;
u32 var800708e4 = 0x00000000;
u32 var800708e8 = 0x00000000;
u32 var800708ec = 0x00000000;
u32 var800708f0 = 0x40a00000;
u32 var800708f4 = 0x41880000;
u32 var800708f8 = 0x3ee66666;
u32 var800708fc = 0x00000096;
u32 var80070900 = 0x00000000;
u32 var80070904 = 0x00000000;
u32 var80070908 = 0x00000000;
u32 var8007090c = 0x40a00000;
u32 var80070910 = 0x41700000;
u32 var80070914 = 0x3ecccccd;
u32 var80070918 = 0x00000096;
u32 var8007091c = 0x00000000;
u32 var80070920 = 0x00000000;

struct healthdamagetype g_HealthDamageTypes[] = {
	// openduration
	// |  unk04
	// |  |   unk08
	// |  |   |   unk0c
	// |  |   |   |    unk10
	// |  |   |   |    |
	{ 20, 34, 46, 270, 285 },
	{ 20, 37, 52, 250, 265 },
	{ 20, 40, 58, 230, 245 },
	{ 20, 43, 64, 210, 225 },
	{ 20, 46, 70, 190, 205 },
	{ 20, 49, 76, 170, 185 },
	{ 20, 52, 82, 150, 165 },
	{ 20, 55, 88, 130, 145 },
};

u32 var800709c4 = 0x00000000;
u32 var800709c8 = 0x00000000;
u32 var800709cc = 0x00000000;

GLOBAL_ASM(
glabel func0f0b63b0
/*  f0b63b0:	44856000 */ 	mtc1	$a1,$f12
/*  f0b63b4:	0480002c */ 	bltz	$a0,.L0f0b6468
/*  f0b63b8:	3c01437f */ 	lui	$at,0x437f
/*  f0b63bc:	44812000 */ 	mtc1	$at,$f4
/*  f0b63c0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0b63c4:	3c0e800a */ 	lui	$t6,%hi(var8009ddc8)
/*  f0b63c8:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0b63cc:	8dceddc8 */ 	lw	$t6,%lo(var8009ddc8)($t6)
/*  f0b63d0:	00047840 */ 	sll	$t7,$a0,0x1
/*  f0b63d4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0b63d8:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0b63dc:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f0b63e0:	4448f800 */ 	cfc1	$t0,$31
/*  f0b63e4:	44c9f800 */ 	ctc1	$t1,$31
/*  f0b63e8:	3319ff00 */ 	andi	$t9,$t8,0xff00
/*  f0b63ec:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0b63f0:	4449f800 */ 	cfc1	$t1,$31
/*  f0b63f4:	00000000 */ 	nop
/*  f0b63f8:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0b63fc:	51200013 */ 	beqzl	$t1,.L0f0b644c
/*  f0b6400:	44094000 */ 	mfc1	$t1,$f8
/*  f0b6404:	44814000 */ 	mtc1	$at,$f8
/*  f0b6408:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0b640c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0b6410:	44c9f800 */ 	ctc1	$t1,$31
/*  f0b6414:	00000000 */ 	nop
/*  f0b6418:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0b641c:	4449f800 */ 	cfc1	$t1,$31
/*  f0b6420:	00000000 */ 	nop
/*  f0b6424:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0b6428:	15200005 */ 	bnez	$t1,.L0f0b6440
/*  f0b642c:	00000000 */ 	nop
/*  f0b6430:	44094000 */ 	mfc1	$t1,$f8
/*  f0b6434:	3c018000 */ 	lui	$at,0x8000
/*  f0b6438:	10000007 */ 	b	.L0f0b6458
/*  f0b643c:	01214825 */ 	or	$t1,$t1,$at
.L0f0b6440:
/*  f0b6440:	10000005 */ 	b	.L0f0b6458
/*  f0b6444:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0b6448:	44094000 */ 	mfc1	$t1,$f8
.L0f0b644c:
/*  f0b644c:	00000000 */ 	nop
/*  f0b6450:	0520fffb */ 	bltz	$t1,.L0f0b6440
/*  f0b6454:	00000000 */ 	nop
.L0f0b6458:
/*  f0b6458:	312b00ff */ 	andi	$t3,$t1,0xff
/*  f0b645c:	44c8f800 */ 	ctc1	$t0,$31
/*  f0b6460:	032b6025 */ 	or	$t4,$t9,$t3
/*  f0b6464:	a44c0000 */ 	sh	$t4,0x0($v0)
.L0f0b6468:
/*  f0b6468:	03e00008 */ 	jr	$ra
/*  f0b646c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b6470
/*  f0b6470:	44856000 */ 	mtc1	$a1,$f12
/*  f0b6474:	0480002d */ 	bltz	$a0,.L0f0b652c
/*  f0b6478:	3c014170 */ 	lui	$at,0x4170
/*  f0b647c:	44812000 */ 	mtc1	$at,$f4
/*  f0b6480:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0b6484:	3c0e800a */ 	lui	$t6,%hi(var8009ddc8)
/*  f0b6488:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0b648c:	8dceddc8 */ 	lw	$t6,%lo(var8009ddc8)($t6)
/*  f0b6490:	00047840 */ 	sll	$t7,$a0,0x1
/*  f0b6494:	3c014f00 */ 	lui	$at,0x4f00
/*  f0b6498:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0b649c:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f0b64a0:	4448f800 */ 	cfc1	$t0,$31
/*  f0b64a4:	44c9f800 */ 	ctc1	$t1,$31
/*  f0b64a8:	3319f0ff */ 	andi	$t9,$t8,0xf0ff
/*  f0b64ac:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0b64b0:	4449f800 */ 	cfc1	$t1,$31
/*  f0b64b4:	00000000 */ 	nop
/*  f0b64b8:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0b64bc:	51200013 */ 	beqzl	$t1,.L0f0b650c
/*  f0b64c0:	44094000 */ 	mfc1	$t1,$f8
/*  f0b64c4:	44814000 */ 	mtc1	$at,$f8
/*  f0b64c8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0b64cc:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0b64d0:	44c9f800 */ 	ctc1	$t1,$31
/*  f0b64d4:	00000000 */ 	nop
/*  f0b64d8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0b64dc:	4449f800 */ 	cfc1	$t1,$31
/*  f0b64e0:	00000000 */ 	nop
/*  f0b64e4:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0b64e8:	15200005 */ 	bnez	$t1,.L0f0b6500
/*  f0b64ec:	00000000 */ 	nop
/*  f0b64f0:	44094000 */ 	mfc1	$t1,$f8
/*  f0b64f4:	3c018000 */ 	lui	$at,0x8000
/*  f0b64f8:	10000007 */ 	b	.L0f0b6518
/*  f0b64fc:	01214825 */ 	or	$t1,$t1,$at
.L0f0b6500:
/*  f0b6500:	10000005 */ 	b	.L0f0b6518
/*  f0b6504:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0b6508:	44094000 */ 	mfc1	$t1,$f8
.L0f0b650c:
/*  f0b650c:	00000000 */ 	nop
/*  f0b6510:	0520fffb */ 	bltz	$t1,.L0f0b6500
/*  f0b6514:	00000000 */ 	nop
.L0f0b6518:
/*  f0b6518:	312b000f */ 	andi	$t3,$t1,0xf
/*  f0b651c:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f0b6520:	44c8f800 */ 	ctc1	$t0,$31
/*  f0b6524:	032c6825 */ 	or	$t5,$t9,$t4
/*  f0b6528:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f0b652c:
/*  f0b652c:	03e00008 */ 	jr	$ra
/*  f0b6530:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b6534
/*  f0b6534:	3c0e800a */ 	lui	$t6,%hi(var8009ddc8)
/*  f0b6538:	8dceddc8 */ 	lw	$t6,%lo(var8009ddc8)($t6)
/*  f0b653c:	00047840 */ 	sll	$t7,$a0,0x1
/*  f0b6540:	3c017f1b */ 	lui	$at,%hi(var7f1ad410)
/*  f0b6544:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b6548:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f0b654c:	c428d410 */ 	lwc1	$f8,%lo(var7f1ad410)($at)
/*  f0b6550:	332800ff */ 	andi	$t0,$t9,0xff
/*  f0b6554:	44882000 */ 	mtc1	$t0,$f4
/*  f0b6558:	00000000 */ 	nop
/*  f0b655c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0b6560:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f0b6564:	03e00008 */ 	jr	$ra
/*  f0b6568:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f0b656c
/*  f0b656c:	3c0e800a */ 	lui	$t6,%hi(var8009ddc8)
/*  f0b6570:	8dceddc8 */ 	lw	$t6,%lo(var8009ddc8)($t6)
/*  f0b6574:	00047840 */ 	sll	$t7,$a0,0x1
/*  f0b6578:	3c017f1b */ 	lui	$at,%hi(var7f1ad414)
/*  f0b657c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b6580:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f0b6584:	c428d414 */ 	lwc1	$f8,%lo(var7f1ad414)($at)
/*  f0b6588:	33280f00 */ 	andi	$t0,$t9,0xf00
/*  f0b658c:	00084a03 */ 	sra	$t1,$t0,0x8
/*  f0b6590:	44892000 */ 	mtc1	$t1,$f4
/*  f0b6594:	00000000 */ 	nop
/*  f0b6598:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0b659c:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f0b65a0:	03e00008 */ 	jr	$ra
/*  f0b65a4:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f0b65a8
/*  f0b65a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b65ac:	1880000c */ 	blez	$a0,.L0f0b65e0
/*  f0b65b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b65b4:	3c01800a */ 	lui	$at,%hi(var8009ddcc)
/*  f0b65b8:	ac24ddcc */ 	sw	$a0,%lo(var8009ddcc)($at)
/*  f0b65bc:	00042040 */ 	sll	$a0,$a0,0x1
/*  f0b65c0:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f0b65c4:	348e000f */ 	ori	$t6,$a0,0xf
/*  f0b65c8:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f0b65cc:	0c0048f2 */ 	jal	malloc
/*  f0b65d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b65d4:	3c01800a */ 	lui	$at,%hi(var8009ddc8)
/*  f0b65d8:	10000003 */ 	b	.L0f0b65e8
/*  f0b65dc:	ac22ddc8 */ 	sw	$v0,%lo(var8009ddc8)($at)
.L0f0b65e0:
/*  f0b65e0:	3c01800a */ 	lui	$at,%hi(var8009ddc8)
/*  f0b65e4:	ac20ddc8 */ 	sw	$zero,%lo(var8009ddc8)($at)
.L0f0b65e8:
/*  f0b65e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b65ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b65f0:	03e00008 */ 	jr	$ra
/*  f0b65f4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b65f8
/*  f0b65f8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0b65fc:	3c0e800a */ 	lui	$t6,%hi(var8009ddc8)
/*  f0b6600:	8dceddc8 */ 	lw	$t6,%lo(var8009ddc8)($t6)
/*  f0b6604:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0b6608:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0b660c:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0b6610:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0b6614:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0b6618:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0b661c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0b6620:	11c00046 */ 	beqz	$t6,.L0f0b673c
/*  f0b6624:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0b6628:	3c12800a */ 	lui	$s2,%hi(var8009ddcc)
/*  f0b662c:	2652ddcc */ 	addiu	$s2,$s2,%lo(var8009ddcc)
/*  f0b6630:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f0b6634:	00008025 */ 	or	$s0,$zero,$zero
/*  f0b6638:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b663c:	1840000f */ 	blez	$v0,.L0f0b667c
/*  f0b6640:	00000000 */ 	nop
/*  f0b6644:	4481a000 */ 	mtc1	$at,$f20
/*  f0b6648:	00000000 */ 	nop
/*  f0b664c:	4405a000 */ 	mfc1	$a1,$f20
.L0f0b6650:
/*  f0b6650:	0fc2d91c */ 	jal	func0f0b6470
/*  f0b6654:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b6658:	4405a000 */ 	mfc1	$a1,$f20
/*  f0b665c:	0fc2d8ec */ 	jal	func0f0b63b0
/*  f0b6660:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b6664:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f0b6668:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0b666c:	0202082a */ 	slt	$at,$s0,$v0
/*  f0b6670:	5420fff7 */ 	bnezl	$at,.L0f0b6650
/*  f0b6674:	4405a000 */ 	mfc1	$a1,$f20
/*  f0b6678:	00008025 */ 	or	$s0,$zero,$zero
.L0f0b667c:
/*  f0b667c:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x33c)
/*  f0b6680:	8e31a2fc */ 	lw	$s1,%lo(g_Vars+0x33c)($s1)
/*  f0b6684:	2415002a */ 	addiu	$s5,$zero,0x2a
/*  f0b6688:	2414002f */ 	addiu	$s4,$zero,0x2f
/*  f0b668c:	12200020 */ 	beqz	$s1,.L0f0b6710
/*  f0b6690:	00000000 */ 	nop
/*  f0b6694:	4480a000 */ 	mtc1	$zero,$f20
/*  f0b6698:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f0b669c:	922f0000 */ 	lbu	$t7,0x0($s1)
.L0f0b66a0:
/*  f0b66a0:	566f0018 */ 	bnel	$s3,$t7,.L0f0b6704
/*  f0b66a4:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f0b66a8:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f0b66ac:	50400015 */ 	beqzl	$v0,.L0f0b6704
/*  f0b66b0:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f0b66b4:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f0b66b8:	16830009 */ 	bne	$s4,$v1,.L0f0b66e0
/*  f0b66bc:	00000000 */ 	nop
/*  f0b66c0:	84440062 */ 	lh	$a0,0x62($v0)
/*  f0b66c4:	0482000f */ 	bltzl	$a0,.L0f0b6704
/*  f0b66c8:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f0b66cc:	4405a000 */ 	mfc1	$a1,$f20
/*  f0b66d0:	0fc2d91c */ 	jal	func0f0b6470
/*  f0b66d4:	00000000 */ 	nop
/*  f0b66d8:	1000000a */ 	b	.L0f0b6704
/*  f0b66dc:	8e310020 */ 	lw	$s1,0x20($s1)
.L0f0b66e0:
/*  f0b66e0:	56a30008 */ 	bnel	$s5,$v1,.L0f0b6704
/*  f0b66e4:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f0b66e8:	8444005c */ 	lh	$a0,0x5c($v0)
/*  f0b66ec:	04820005 */ 	bltzl	$a0,.L0f0b6704
/*  f0b66f0:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f0b66f4:	4405a000 */ 	mfc1	$a1,$f20
/*  f0b66f8:	0fc2d91c */ 	jal	func0f0b6470
/*  f0b66fc:	00000000 */ 	nop
/*  f0b6700:	8e310020 */ 	lw	$s1,0x20($s1)
.L0f0b6704:
/*  f0b6704:	5620ffe6 */ 	bnezl	$s1,.L0f0b66a0
/*  f0b6708:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f0b670c:	8e420000 */ 	lw	$v0,0x0($s2)
.L0f0b6710:
/*  f0b6710:	5840000b */ 	blezl	$v0,.L0f0b6740
/*  f0b6714:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0b6718:
/*  f0b6718:	0fc2d95b */ 	jal	func0f0b656c
/*  f0b671c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b6720:	0fc2d94d */ 	jal	func0f0b6534
/*  f0b6724:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b6728:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0b672c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0b6730:	0218082a */ 	slt	$at,$s0,$t8
/*  f0b6734:	1420fff8 */ 	bnez	$at,.L0f0b6718
/*  f0b6738:	00000000 */ 	nop
.L0f0b673c:
/*  f0b673c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0b6740:
/*  f0b6740:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0b6744:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0b6748:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0b674c:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0b6750:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0b6754:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0b6758:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0b675c:	03e00008 */ 	jr	$ra
/*  f0b6760:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f0b6764
/*  f0b6764:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0b6768:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0b676c:	8d6402bc */ 	lw	$a0,0x2bc($t3)
/*  f0b6770:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0b6774:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b6778:	00047100 */ 	sll	$t6,$a0,0x4
/*  f0b677c:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f0b6780:	348f000f */ 	ori	$t7,$a0,0xf
/*  f0b6784:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0b6788:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0b678c:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0b6790:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f0b6794:	0c0048f2 */ 	jal	malloc
/*  f0b6798:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0b679c:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0b67a0:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0b67a4:	8d6302bc */ 	lw	$v1,0x2bc($t3)
/*  f0b67a8:	3c07800a */ 	lui	$a3,%hi(var8009dd70)
/*  f0b67ac:	24e7dd70 */ 	addiu	$a3,$a3,%lo(var8009dd70)
/*  f0b67b0:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f0b67b4:	18600066 */ 	blez	$v1,.L0f0b6950
/*  f0b67b8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b67bc:	3c017f1b */ 	lui	$at,%hi(var7f1ad418)
/*  f0b67c0:	c438d418 */ 	lwc1	$f24,%lo(var7f1ad418)($at)
/*  f0b67c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b67c8:	4481b000 */ 	mtc1	$at,$f22
/*  f0b67cc:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0b67d0:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f0b67d4:	44817000 */ 	mtc1	$at,$f14
/*  f0b67d8:	44808000 */ 	mtc1	$zero,$f16
/*  f0b67dc:	25294928 */ 	addiu	$t1,$t1,%lo(g_Rooms)
/*  f0b67e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b67e4:	240c008c */ 	addiu	$t4,$zero,0x8c
/*  f0b67e8:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f0b67ec:	8cf90000 */ 	lw	$t9,0x0($a3)
.L0f0b67f0:
/*  f0b67f0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b67f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b67f8:	03256821 */ 	addu	$t5,$t9,$a1
/*  f0b67fc:	e5b6000c */ 	swc1	$f22,0xc($t5)
/*  f0b6800:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0b6804:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0b6808:	e5f60000 */ 	swc1	$f22,0x0($t7)
/*  f0b680c:	0006c8c0 */ 	sll	$t9,$a2,0x3
.L0f0b6810:
/*  f0b6810:	0326c821 */ 	addu	$t9,$t9,$a2
/*  f0b6814:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f0b6818:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0b681c:	0326c823 */ 	subu	$t9,$t9,$a2
/*  f0b6820:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0b6824:	03196821 */ 	addu	$t5,$t8,$t9
/*  f0b6828:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f0b682c:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f0b6830:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f0b6834:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0b6838:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0b683c:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0b6840:	00000000 */ 	nop
/*  f0b6844:	45020009 */ 	bc1fl	.L0f0b686c
/*  f0b6848:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b684c:	460e1283 */ 	div.s	$f10,$f2,$f14
/*  f0b6850:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0b6854:	01c51021 */ 	addu	$v0,$t6,$a1
/*  f0b6858:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0b685c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0b6860:	10000002 */ 	b	.L0f0b686c
/*  f0b6864:	e444000c */ 	swc1	$f4,0xc($v0)
/*  f0b6868:	00002025 */ 	or	$a0,$zero,$zero
.L0f0b686c:
/*  f0b686c:	546affe8 */ 	bnel	$v1,$t2,.L0f0b6810
/*  f0b6870:	0006c8c0 */ 	sll	$t9,$a2,0x3
/*  f0b6874:	5080002e */ 	beqzl	$a0,.L0f0b6930
/*  f0b6878:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0b687c:	00cc0019 */ 	multu	$a2,$t4
/*  f0b6880:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f0b6884:	0000c012 */ 	mflo	$t8
/*  f0b6888:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0b688c:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f0b6890:	c4420024 */ 	lwc1	$f2,0x24($v0)
/*  f0b6894:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0b6898:	00000000 */ 	nop
/*  f0b689c:	45020004 */ 	bc1fl	.L0f0b68b0
/*  f0b68a0:	46001481 */ 	sub.s	$f18,$f2,$f0
/*  f0b68a4:	10000003 */ 	b	.L0f0b68b4
/*  f0b68a8:	46001481 */ 	sub.s	$f18,$f2,$f0
/*  f0b68ac:	46001481 */ 	sub.s	$f18,$f2,$f0
.L0f0b68b0:
/*  f0b68b0:	46009487 */ 	neg.s	$f18,$f18
.L0f0b68b4:
/*  f0b68b4:	c440001c */ 	lwc1	$f0,0x1c($v0)
/*  f0b68b8:	c4420028 */ 	lwc1	$f2,0x28($v0)
/*  f0b68bc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0b68c0:	00000000 */ 	nop
/*  f0b68c4:	45020004 */ 	bc1fl	.L0f0b68d8
/*  f0b68c8:	46001501 */ 	sub.s	$f20,$f2,$f0
/*  f0b68cc:	10000003 */ 	b	.L0f0b68dc
/*  f0b68d0:	46001501 */ 	sub.s	$f20,$f2,$f0
/*  f0b68d4:	46001501 */ 	sub.s	$f20,$f2,$f0
.L0f0b68d8:
/*  f0b68d8:	4600a507 */ 	neg.s	$f20,$f20
.L0f0b68dc:
/*  f0b68dc:	c4400020 */ 	lwc1	$f0,0x20($v0)
/*  f0b68e0:	c442002c */ 	lwc1	$f2,0x2c($v0)
/*  f0b68e4:	46149182 */ 	mul.s	$f6,$f18,$f20
/*  f0b68e8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0b68ec:	00000000 */ 	nop
/*  f0b68f0:	45020004 */ 	bc1fl	.L0f0b6904
/*  f0b68f4:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0b68f8:	10000003 */ 	b	.L0f0b6908
/*  f0b68fc:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0b6900:	46001301 */ 	sub.s	$f12,$f2,$f0
.L0f0b6904:
/*  f0b6904:	46006307 */ 	neg.s	$f12,$f12
.L0f0b6908:
/*  f0b6908:	460c9202 */ 	mul.s	$f8,$f18,$f12
/*  f0b690c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0b6910:	460ca102 */ 	mul.s	$f4,$f20,$f12
/*  f0b6914:	03256821 */ 	addu	$t5,$t9,$a1
/*  f0b6918:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0b691c:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0b6920:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f0b6924:	10000004 */ 	b	.L0f0b6938
/*  f0b6928:	e5a60000 */ 	swc1	$f6,0x0($t5)
/*  f0b692c:	8cee0000 */ 	lw	$t6,0x0($a3)
.L0f0b6930:
/*  f0b6930:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0b6934:	e5f80000 */ 	swc1	$f24,0x0($t7)
.L0f0b6938:
/*  f0b6938:	8d6302bc */ 	lw	$v1,0x2bc($t3)
/*  f0b693c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0b6940:	24a50010 */ 	addiu	$a1,$a1,0x10
/*  f0b6944:	00c3082a */ 	slt	$at,$a2,$v1
/*  f0b6948:	5420ffa9 */ 	bnezl	$at,.L0f0b67f0
/*  f0b694c:	8cf90000 */ 	lw	$t9,0x0($a3)
.L0f0b6950:
/*  f0b6950:	44808000 */ 	mtc1	$zero,$f16
/*  f0b6954:	1860000f */ 	blez	$v1,.L0f0b6994
/*  f0b6958:	00004025 */ 	or	$t0,$zero,$zero
/*  f0b695c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b6960:	8cf80000 */ 	lw	$t8,0x0($a3)
.L0f0b6964:
/*  f0b6964:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0b6968:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0b696c:	e7300008 */ 	swc1	$f16,0x8($t9)
/*  f0b6970:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0b6974:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f0b6978:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b697c:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f0b6980:	e4480004 */ 	swc1	$f8,0x4($v0)
/*  f0b6984:	8d6e02bc */ 	lw	$t6,0x2bc($t3)
/*  f0b6988:	010e082a */ 	slt	$at,$t0,$t6
/*  f0b698c:	5420fff5 */ 	bnezl	$at,.L0f0b6964
/*  f0b6990:	8cf80000 */ 	lw	$t8,0x0($a3)
.L0f0b6994:
/*  f0b6994:	3c02800a */ 	lui	$v0,%hi(var8009dd78)
/*  f0b6998:	3c04800a */ 	lui	$a0,%hi(var8009ddc8)
/*  f0b699c:	2484ddc8 */ 	addiu	$a0,$a0,%lo(var8009ddc8)
/*  f0b69a0:	2442dd78 */ 	addiu	$v0,$v0,%lo(var8009dd78)
/*  f0b69a4:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f0b69a8:
/*  f0b69a8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0b69ac:	a443fff8 */ 	sh	$v1,-0x8($v0)
/*  f0b69b0:	1444fffd */ 	bne	$v0,$a0,.L0f0b69a8
/*  f0b69b4:	e450fffc */ 	swc1	$f16,-0x4($v0)
/*  f0b69b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b69bc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0b69c0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0b69c4:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f0b69c8:	03e00008 */ 	jr	$ra
/*  f0b69cc:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0b69d0
/*  f0b69d0:	27bdfd78 */ 	addiu	$sp,$sp,-648
/*  f0b69d4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0b69d8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0b69dc:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f0b69e0:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0b69e4:	00e09025 */ 	or	$s2,$a3,$zero
/*  f0b69e8:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0b69ec:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0b69f0:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0b69f4:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0b69f8:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0b69fc:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0b6a00:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0b6a04:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0b6a08:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0b6a0c:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0b6a10:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0b6a14:	e7ac0288 */ 	swc1	$f12,0x288($sp)
/*  f0b6a18:	afa5028c */ 	sw	$a1,0x28c($sp)
/*  f0b6a1c:	afa60290 */ 	sw	$a2,0x290($sp)
/*  f0b6a20:	11c00003 */ 	beqz	$t6,.L0f0b6a30
/*  f0b6a24:	afa00144 */ 	sw	$zero,0x144($sp)
/*  f0b6a28:	10000002 */ 	b	.L0f0b6a34
/*  f0b6a2c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b6a30:
/*  f0b6a30:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b6a34:
/*  f0b6a34:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f0b6a38:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b6a3c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0b6a40:	11e00003 */ 	beqz	$t7,.L0f0b6a50
/*  f0b6a44:	00000000 */ 	nop
/*  f0b6a48:	10000001 */ 	b	.L0f0b6a50
/*  f0b6a4c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b6a50:
/*  f0b6a50:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f0b6a54:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b6a58:	13000003 */ 	beqz	$t8,.L0f0b6a68
/*  f0b6a5c:	00000000 */ 	nop
/*  f0b6a60:	10000001 */ 	b	.L0f0b6a68
/*  f0b6a64:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b6a68:
/*  f0b6a68:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f0b6a6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b6a70:	3c014f80 */ 	lui	$at,0x4f80
/*  f0b6a74:	13200003 */ 	beqz	$t9,.L0f0b6a84
/*  f0b6a78:	00000000 */ 	nop
/*  f0b6a7c:	10000001 */ 	b	.L0f0b6a84
/*  f0b6a80:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b6a84:
/*  f0b6a84:	8faa029c */ 	lw	$t2,0x29c($sp)
/*  f0b6a88:	00444021 */ 	addu	$t0,$v0,$a0
/*  f0b6a8c:	01034821 */ 	addu	$t1,$t0,$v1
/*  f0b6a90:	01253821 */ 	addu	$a3,$t1,$a1
/*  f0b6a94:	194000a0 */ 	blez	$t2,.L0f0b6d18
/*  f0b6a98:	afa70138 */ 	sw	$a3,0x138($sp)
/*  f0b6a9c:	8fa20298 */ 	lw	$v0,0x298($sp)
/*  f0b6aa0:	4481b000 */ 	mtc1	$at,$f22
/*  f0b6aa4:	27b30270 */ 	addiu	$s3,$sp,0x270
/*  f0b6aa8:	27b70258 */ 	addiu	$s7,$sp,0x258
/*  f0b6aac:	27b601f8 */ 	addiu	$s6,$sp,0x1f8
/*  f0b6ab0:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f0b6ab4:	27be0098 */ 	addiu	$s8,$sp,0x98
/*  f0b6ab8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0b6abc:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0b6ac0:
/*  f0b6ac0:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f0b6ac4:	4600b506 */ 	mov.s	$f20,$f22
/*  f0b6ac8:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b6acc:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0b6ad0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b6ad4:	0fc456ac */ 	jal	padUnpack
/*  f0b6ad8:	84440000 */ 	lh	$a0,0x0($v0)
/*  f0b6adc:	a2600000 */ 	sb	$zero,0x0($s3)
/*  f0b6ae0:	a2e00000 */ 	sb	$zero,0x0($s7)
/*  f0b6ae4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0b6ae8:	5960003b */ 	blezl	$t3,.L0f0b6bd8
/*  f0b6aec:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f0b6af0:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b6af4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b6af8:	8e0c0064 */ 	lw	$t4,0x64($s0)
.L0f0b6afc:
/*  f0b6afc:	8d8200bc */ 	lw	$v0,0xbc($t4)
/*  f0b6b00:	5040002f */ 	beqzl	$v0,.L0f0b6bc0
/*  f0b6b04:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0b6b08:	5242002d */ 	beql	$s2,$v0,.L0f0b6bc0
/*  f0b6b0c:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0b6b10:	12400008 */ 	beqz	$s2,.L0f0b6b34
/*  f0b6b14:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0b6b18:	8e440004 */ 	lw	$a0,0x4($s2)
/*  f0b6b1c:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f0b6b20:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f0b6b24:	50400026 */ 	beqzl	$v0,.L0f0b6bc0
/*  f0b6b28:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0b6b2c:	8e0d0064 */ 	lw	$t5,0x64($s0)
/*  f0b6b30:	8da200bc */ 	lw	$v0,0xbc($t5)
.L0f0b6b34:
/*  f0b6b34:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0b6b38:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f0b6b3c:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0b6b40:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0b6b44:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0b6b48:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*  f0b6b4c:	c7b200d8 */ 	lwc1	$f18,0xd8($sp)
/*  f0b6b50:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f0b6b54:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0b6b58:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f0b6b5c:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f0b6b60:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0b6b64:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b6b68:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f0b6b6c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b6b70:	460a4380 */ 	add.s	$f14,$f8,$f10
/*  f0b6b74:	4614703c */ 	c.lt.s	$f14,$f20
/*  f0b6b78:	00000000 */ 	nop
/*  f0b6b7c:	45000002 */ 	bc1f	.L0f0b6b88
/*  f0b6b80:	00000000 */ 	nop
/*  f0b6b84:	46007506 */ 	mov.s	$f20,$f14
.L0f0b6b88:
/*  f0b6b88:	0fc575e8 */ 	jal	roomIsVisibleByPlayer
/*  f0b6b8c:	00000000 */ 	nop
/*  f0b6b90:	10400002 */ 	beqz	$v0,.L0f0b6b9c
/*  f0b6b94:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b6b98:	a2740000 */ 	sb	$s4,0x0($s3)
.L0f0b6b9c:
/*  f0b6b9c:	926e0000 */ 	lbu	$t6,0x0($s3)
/*  f0b6ba0:	55c00006 */ 	bnezl	$t6,.L0f0b6bbc
/*  f0b6ba4:	a2f40000 */ 	sb	$s4,0x0($s7)
/*  f0b6ba8:	0fc57602 */ 	jal	roomIsVisibleByAibot
/*  f0b6bac:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f0b6bb0:	50400003 */ 	beqzl	$v0,.L0f0b6bc0
/*  f0b6bb4:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0b6bb8:	a2f40000 */ 	sb	$s4,0x0($s7)
.L0f0b6bbc:
/*  f0b6bbc:	8faf0138 */ 	lw	$t7,0x138($sp)
.L0f0b6bc0:
/*  f0b6bc0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b6bc4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0b6bc8:	562fffcc */ 	bnel	$s1,$t7,.L0f0b6afc
/*  f0b6bcc:	8e0c0064 */ 	lw	$t4,0x64($s0)
/*  f0b6bd0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b6bd4:	8fa40118 */ 	lw	$a0,0x118($sp)
.L0f0b6bd8:
/*  f0b6bd8:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0b6bdc:	a7b800c6 */ 	sh	$t8,0xc6($sp)
/*  f0b6be0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0b6be4:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0b6be8:	0fc5916a */ 	jal	func0f1645a8
/*  f0b6bec:	a7a400c4 */ 	sh	$a0,0xc4($sp)
/*  f0b6bf0:	3c198008 */ 	lui	$t9,%hi(g_NumMpSimulantChrs)
/*  f0b6bf4:	93397d10 */ 	lbu	$t9,%lo(g_NumMpSimulantChrs)($t9)
/*  f0b6bf8:	5b20003e */ 	blezl	$t9,.L0f0b6cf4
/*  f0b6bfc:	e6d40000 */ 	swc1	$f20,0x0($s6)
/*  f0b6c00:	3c10800b */ 	lui	$s0,%hi(g_MpSimulantChrs)
/*  f0b6c04:	2610cc80 */ 	addiu	$s0,$s0,%lo(g_MpSimulantChrs)
/*  f0b6c08:	8e050000 */ 	lw	$a1,0x0($s0)
.L0f0b6c0c:
/*  f0b6c0c:	8ca2001c */ 	lw	$v0,0x1c($a1)
/*  f0b6c10:	10400030 */ 	beqz	$v0,.L0f0b6cd4
/*  f0b6c14:	00000000 */ 	nop
/*  f0b6c18:	1242002e */ 	beq	$s2,$v0,.L0f0b6cd4
/*  f0b6c1c:	00000000 */ 	nop
/*  f0b6c20:	12400007 */ 	beqz	$s2,.L0f0b6c40
/*  f0b6c24:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0b6c28:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f0b6c2c:	8e440004 */ 	lw	$a0,0x4($s2)
/*  f0b6c30:	10400028 */ 	beqz	$v0,.L0f0b6cd4
/*  f0b6c34:	00000000 */ 	nop
/*  f0b6c38:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f0b6c3c:	8d02001c */ 	lw	$v0,0x1c($t0)
.L0f0b6c40:
/*  f0b6c40:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f0b6c44:	c7b200d0 */ 	lwc1	$f18,0xd0($sp)
/*  f0b6c48:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f0b6c4c:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0b6c50:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f0b6c54:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0b6c58:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*  f0b6c5c:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0b6c60:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f0b6c64:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0b6c68:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f0b6c6c:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f0b6c70:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0b6c74:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f0b6c78:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0b6c7c:	46062380 */ 	add.s	$f14,$f4,$f6
/*  f0b6c80:	4614703c */ 	c.lt.s	$f14,$f20
/*  f0b6c84:	00000000 */ 	nop
/*  f0b6c88:	45000002 */ 	bc1f	.L0f0b6c94
/*  f0b6c8c:	00000000 */ 	nop
/*  f0b6c90:	46007506 */ 	mov.s	$f20,$f14
.L0f0b6c94:
/*  f0b6c94:	0fc19620 */ 	jal	arrayIntersects
/*  f0b6c98:	00000000 */ 	nop
/*  f0b6c9c:	50400003 */ 	beqzl	$v0,.L0f0b6cac
/*  f0b6ca0:	92690000 */ 	lbu	$t1,0x0($s3)
/*  f0b6ca4:	a2740000 */ 	sb	$s4,0x0($s3)
/*  f0b6ca8:	92690000 */ 	lbu	$t1,0x0($s3)
.L0f0b6cac:
/*  f0b6cac:	55200009 */ 	bnezl	$t1,.L0f0b6cd4
/*  f0b6cb0:	a2f40000 */ 	sb	$s4,0x0($s7)
/*  f0b6cb4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0b6cb8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0b6cbc:	8d45001c */ 	lw	$a1,0x1c($t2)
/*  f0b6cc0:	0fc19620 */ 	jal	arrayIntersects
/*  f0b6cc4:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0b6cc8:	10400002 */ 	beqz	$v0,.L0f0b6cd4
/*  f0b6ccc:	00000000 */ 	nop
/*  f0b6cd0:	a2f40000 */ 	sb	$s4,0x0($s7)
.L0f0b6cd4:
/*  f0b6cd4:	3c0b8008 */ 	lui	$t3,%hi(g_NumMpSimulantChrs)
/*  f0b6cd8:	916b7d10 */ 	lbu	$t3,%lo(g_NumMpSimulantChrs)($t3)
/*  f0b6cdc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b6ce0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0b6ce4:	022b082a */ 	slt	$at,$s1,$t3
/*  f0b6ce8:	5420ffc8 */ 	bnezl	$at,.L0f0b6c0c
/*  f0b6cec:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f0b6cf0:	e6d40000 */ 	swc1	$f20,0x0($s6)
.L0f0b6cf4:
/*  f0b6cf4:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0b6cf8:	8fae029c */ 	lw	$t6,0x29c($sp)
/*  f0b6cfc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b6d00:	258d0002 */ 	addiu	$t5,$t4,0x2
/*  f0b6d04:	afad0080 */ 	sw	$t5,0x80($sp)
/*  f0b6d08:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0b6d0c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f0b6d10:	16aeff6b */ 	bne	$s5,$t6,.L0f0b6ac0
/*  f0b6d14:	26d60004 */ 	addiu	$s6,$s6,0x4
.L0f0b6d18:
/*  f0b6d18:	0c004b70 */ 	jal	random
/*  f0b6d1c:	00000000 */ 	nop
/*  f0b6d20:	8faf029c */ 	lw	$t7,0x29c($sp)
/*  f0b6d24:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0b6d28:	4481b000 */ 	mtc1	$at,$f22
/*  f0b6d2c:	004f001b */ 	divu	$zero,$v0,$t7
/*  f0b6d30:	00002010 */ 	mfhi	$a0
/*  f0b6d34:	3c017f1b */ 	lui	$at,%hi(var7f1ad528)
/*  f0b6d38:	00808825 */ 	or	$s1,$a0,$zero
/*  f0b6d3c:	c434d528 */ 	lwc1	$f20,%lo(var7f1ad528)($at)
/*  f0b6d40:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0b6d44:	27be01c8 */ 	addiu	$s8,$sp,0x1c8
/*  f0b6d48:	27b701f8 */ 	addiu	$s7,$sp,0x1f8
/*  f0b6d4c:	27b40258 */ 	addiu	$s4,$sp,0x258
/*  f0b6d50:	15e00002 */ 	bnez	$t7,.L0f0b6d5c
/*  f0b6d54:	00000000 */ 	nop
/*  f0b6d58:	0007000d */ 	break	0x7
.L0f0b6d5c:
/*  f0b6d5c:	0015c080 */ 	sll	$t8,$s5,0x2
.L0f0b6d60:
/*  f0b6d60:	02f8b021 */ 	addu	$s6,$s7,$t8
/*  f0b6d64:	c6c80000 */ 	lwc1	$f8,0x0($s6)
/*  f0b6d68:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f0b6d6c:	00000000 */ 	nop
/*  f0b6d70:	45020039 */ 	bc1fl	.L0f0b6e58
/*  f0b6d74:	26ae0001 */ 	addiu	$t6,$s5,0x1
/*  f0b6d78:	0295c821 */ 	addu	$t9,$s4,$s5
/*  f0b6d7c:	93280000 */ 	lbu	$t0,0x0($t9)
/*  f0b6d80:	27af0198 */ 	addiu	$t7,$sp,0x198
/*  f0b6d84:	55000034 */ 	bnezl	$t0,.L0f0b6e58
/*  f0b6d88:	26ae0001 */ 	addiu	$t6,$s5,0x1
/*  f0b6d8c:	8fa20144 */ 	lw	$v0,0x144($sp)
/*  f0b6d90:	8fa90298 */ 	lw	$t1,0x298($sp)
/*  f0b6d94:	00155040 */ 	sll	$t2,$s5,0x1
/*  f0b6d98:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0b6d9c:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0b6da0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0b6da4:	27ad0158 */ 	addiu	$t5,$sp,0x158
/*  f0b6da8:	27b90148 */ 	addiu	$t9,$sp,0x148
/*  f0b6dac:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0b6db0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0b6db4:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0b6db8:	85640000 */ 	lh	$a0,0x0($t3)
/*  f0b6dbc:	03199821 */ 	addu	$s3,$t8,$t9
/*  f0b6dc0:	018d9021 */ 	addu	$s2,$t4,$t5
/*  f0b6dc4:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f0b6dc8:	24050046 */ 	addiu	$a1,$zero,0x46
/*  f0b6dcc:	0fc456ac */ 	jal	padUnpack
/*  f0b6dd0:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0b6dd4:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f0b6dd8:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0b6ddc:	a6480002 */ 	sh	$t0,0x2($s2)
/*  f0b6de0:	a6440000 */ 	sh	$a0,0x0($s2)
/*  f0b6de4:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f0b6de8:	e60a0000 */ 	swc1	$f10,0x0($s0)
/*  f0b6dec:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
/*  f0b6df0:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f0b6df4:	c7b200d8 */ 	lwc1	$f18,0xd8($sp)
/*  f0b6df8:	e6120008 */ 	swc1	$f18,0x8($s0)
/*  f0b6dfc:	c7ae00e4 */ 	lwc1	$f14,0xe4($sp)
/*  f0b6e00:	0fc259d4 */ 	jal	func0f096750
/*  f0b6e04:	c7ac00dc */ 	lwc1	$f12,0xdc($sp)
/*  f0b6e08:	e6600000 */ 	swc1	$f0,0x0($s3)
/*  f0b6e0c:	44070000 */ 	mfc1	$a3,$f0
/*  f0b6e10:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0b6e14:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0b6e18:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0b6e1c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0b6e20:	c7ac0288 */ 	lwc1	$f12,0x288($sp)
/*  f0b6e24:	02002825 */ 	or	$a1,$s0,$zero
/*  f0b6e28:	0fc12be1 */ 	jal	func0f04af84
/*  f0b6e2c:	02403025 */ 	or	$a2,$s2,$zero
/*  f0b6e30:	50400008 */ 	beqzl	$v0,.L0f0b6e54
/*  f0b6e34:	e6d60000 */ 	swc1	$f22,0x0($s6)
/*  f0b6e38:	8faa0144 */ 	lw	$t2,0x144($sp)
/*  f0b6e3c:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f0b6e40:	03cb6021 */ 	addu	$t4,$s8,$t3
/*  f0b6e44:	a5950000 */ 	sh	$s5,0x0($t4)
/*  f0b6e48:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f0b6e4c:	afad0144 */ 	sw	$t5,0x144($sp)
/*  f0b6e50:	e6d60000 */ 	swc1	$f22,0x0($s6)
.L0f0b6e54:
/*  f0b6e54:	26ae0001 */ 	addiu	$t6,$s5,0x1
.L0f0b6e58:
/*  f0b6e58:	8faf029c */ 	lw	$t7,0x29c($sp)
/*  f0b6e5c:	8fb80144 */ 	lw	$t8,0x144($sp)
/*  f0b6e60:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0b6e64:	15e00002 */ 	bnez	$t7,.L0f0b6e70
/*  f0b6e68:	00000000 */ 	nop
/*  f0b6e6c:	0007000d */ 	break	0x7
.L0f0b6e70:
/*  f0b6e70:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b6e74:	15e10004 */ 	bne	$t7,$at,.L0f0b6e88
/*  f0b6e78:	3c018000 */ 	lui	$at,0x8000
/*  f0b6e7c:	15c10002 */ 	bne	$t6,$at,.L0f0b6e88
/*  f0b6e80:	00000000 */ 	nop
/*  f0b6e84:	0006000d */ 	break	0x6
.L0f0b6e88:
/*  f0b6e88:	0000a810 */ 	mfhi	$s5
/*  f0b6e8c:	2b010004 */ 	slti	$at,$t8,0x4
/*  f0b6e90:	12b10003 */ 	beq	$s5,$s1,.L0f0b6ea0
/*  f0b6e94:	00000000 */ 	nop
/*  f0b6e98:	5420ffb1 */ 	bnezl	$at,.L0f0b6d60
/*  f0b6e9c:	0015c080 */ 	sll	$t8,$s5,0x2
.L0f0b6ea0:
/*  f0b6ea0:	3c017f1b */ 	lui	$at,%hi(var7f1ad52c)
/*  f0b6ea4:	c434d52c */ 	lwc1	$f20,%lo(var7f1ad52c)($at)
/*  f0b6ea8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0b6eac:	4481b000 */ 	mtc1	$at,$f22
/*  f0b6eb0:	27b701f8 */ 	addiu	$s7,$sp,0x1f8
/*  f0b6eb4:	0c004b70 */ 	jal	random
/*  f0b6eb8:	27be01c8 */ 	addiu	$s8,$sp,0x1c8
/*  f0b6ebc:	8fa3029c */ 	lw	$v1,0x29c($sp)
/*  f0b6ec0:	8fa70144 */ 	lw	$a3,0x144($sp)
/*  f0b6ec4:	0043001b */ 	divu	$zero,$v0,$v1
/*  f0b6ec8:	00002010 */ 	mfhi	$a0
/*  f0b6ecc:	28e10004 */ 	slti	$at,$a3,0x4
/*  f0b6ed0:	14600002 */ 	bnez	$v1,.L0f0b6edc
/*  f0b6ed4:	00000000 */ 	nop
/*  f0b6ed8:	0007000d */ 	break	0x7
.L0f0b6edc:
/*  f0b6edc:	00808825 */ 	or	$s1,$a0,$zero
/*  f0b6ee0:	10200051 */ 	beqz	$at,.L0f0b7028
/*  f0b6ee4:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0b6ee8:	27b40270 */ 	addiu	$s4,$sp,0x270
/*  f0b6eec:	0015c880 */ 	sll	$t9,$s5,0x2
.L0f0b6ef0:
/*  f0b6ef0:	02f9b021 */ 	addu	$s6,$s7,$t9
/*  f0b6ef4:	c6c40000 */ 	lwc1	$f4,0x0($s6)
/*  f0b6ef8:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0b6efc:	00000000 */ 	nop
/*  f0b6f00:	45020039 */ 	bc1fl	.L0f0b6fe8
/*  f0b6f04:	26af0001 */ 	addiu	$t7,$s5,0x1
/*  f0b6f08:	02954021 */ 	addu	$t0,$s4,$s5
/*  f0b6f0c:	91090000 */ 	lbu	$t1,0x0($t0)
/*  f0b6f10:	00077880 */ 	sll	$t7,$a3,0x2
/*  f0b6f14:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f0b6f18:	15200032 */ 	bnez	$t1,.L0f0b6fe4
/*  f0b6f1c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b6f20:	8fab0298 */ 	lw	$t3,0x298($sp)
/*  f0b6f24:	00156040 */ 	sll	$t4,$s5,0x1
/*  f0b6f28:	00076900 */ 	sll	$t5,$a3,0x4
/*  f0b6f2c:	27ae0158 */ 	addiu	$t6,$sp,0x158
/*  f0b6f30:	27b80198 */ 	addiu	$t8,$sp,0x198
/*  f0b6f34:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f0b6f38:	27a80148 */ 	addiu	$t0,$sp,0x148
/*  f0b6f3c:	016c5021 */ 	addu	$t2,$t3,$t4
/*  f0b6f40:	85440000 */ 	lh	$a0,0x0($t2)
/*  f0b6f44:	03289821 */ 	addu	$s3,$t9,$t0
/*  f0b6f48:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f0b6f4c:	01ae9021 */ 	addu	$s2,$t5,$t6
/*  f0b6f50:	24050046 */ 	addiu	$a1,$zero,0x46
/*  f0b6f54:	0fc456ac */ 	jal	padUnpack
/*  f0b6f58:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0b6f5c:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f0b6f60:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0b6f64:	a6490002 */ 	sh	$t1,0x2($s2)
/*  f0b6f68:	a6440000 */ 	sh	$a0,0x0($s2)
/*  f0b6f6c:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f0b6f70:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f0b6f74:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0b6f78:	e6080004 */ 	swc1	$f8,0x4($s0)
/*  f0b6f7c:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*  f0b6f80:	e60a0008 */ 	swc1	$f10,0x8($s0)
/*  f0b6f84:	c7ae00e4 */ 	lwc1	$f14,0xe4($sp)
/*  f0b6f88:	0fc259d4 */ 	jal	func0f096750
/*  f0b6f8c:	c7ac00dc */ 	lwc1	$f12,0xdc($sp)
/*  f0b6f90:	e6600000 */ 	swc1	$f0,0x0($s3)
/*  f0b6f94:	44070000 */ 	mfc1	$a3,$f0
/*  f0b6f98:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0b6f9c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0b6fa0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0b6fa4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0b6fa8:	c7ac0288 */ 	lwc1	$f12,0x288($sp)
/*  f0b6fac:	02002825 */ 	or	$a1,$s0,$zero
/*  f0b6fb0:	0fc12be1 */ 	jal	func0f04af84
/*  f0b6fb4:	02403025 */ 	or	$a2,$s2,$zero
/*  f0b6fb8:	50400008 */ 	beqzl	$v0,.L0f0b6fdc
/*  f0b6fbc:	e6d60000 */ 	swc1	$f22,0x0($s6)
/*  f0b6fc0:	8fac0144 */ 	lw	$t4,0x144($sp)
/*  f0b6fc4:	000c5040 */ 	sll	$t2,$t4,0x1
/*  f0b6fc8:	03ca6821 */ 	addu	$t5,$s8,$t2
/*  f0b6fcc:	a5b50000 */ 	sh	$s5,0x0($t5)
/*  f0b6fd0:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f0b6fd4:	afae0144 */ 	sw	$t6,0x144($sp)
/*  f0b6fd8:	e6d60000 */ 	swc1	$f22,0x0($s6)
.L0f0b6fdc:
/*  f0b6fdc:	8fa3029c */ 	lw	$v1,0x29c($sp)
/*  f0b6fe0:	8fa70144 */ 	lw	$a3,0x144($sp)
.L0f0b6fe4:
/*  f0b6fe4:	26af0001 */ 	addiu	$t7,$s5,0x1
.L0f0b6fe8:
/*  f0b6fe8:	01e3001a */ 	div	$zero,$t7,$v1
/*  f0b6fec:	14600002 */ 	bnez	$v1,.L0f0b6ff8
/*  f0b6ff0:	00000000 */ 	nop
/*  f0b6ff4:	0007000d */ 	break	0x7
.L0f0b6ff8:
/*  f0b6ff8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b6ffc:	14610004 */ 	bne	$v1,$at,.L0f0b7010
/*  f0b7000:	3c018000 */ 	lui	$at,0x8000
/*  f0b7004:	15e10002 */ 	bne	$t7,$at,.L0f0b7010
/*  f0b7008:	00000000 */ 	nop
/*  f0b700c:	0006000d */ 	break	0x6
.L0f0b7010:
/*  f0b7010:	0000a810 */ 	mfhi	$s5
/*  f0b7014:	28e10004 */ 	slti	$at,$a3,0x4
/*  f0b7018:	52b10004 */ 	beql	$s5,$s1,.L0f0b702c
/*  f0b701c:	28e10004 */ 	slti	$at,$a3,0x4
/*  f0b7020:	5420ffb3 */ 	bnezl	$at,.L0f0b6ef0
/*  f0b7024:	0015c880 */ 	sll	$t9,$s5,0x2
.L0f0b7028:
/*  f0b7028:	28e10004 */ 	slti	$at,$a3,0x4
.L0f0b702c:
/*  f0b702c:	10200050 */ 	beqz	$at,.L0f0b7170
/*  f0b7030:	00000000 */ 	nop
/*  f0b7034:	8fa3029c */ 	lw	$v1,0x29c($sp)
.L0f0b7038:
/*  f0b7038:	8fa70144 */ 	lw	$a3,0x144($sp)
/*  f0b703c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f0b7040:	4600b506 */ 	mov.s	$f20,$f22
/*  f0b7044:	1860000c */ 	blez	$v1,.L0f0b7078
/*  f0b7048:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0b704c:	27b601f8 */ 	addiu	$s6,$sp,0x1f8
.L0f0b7050:
/*  f0b7050:	c6c00000 */ 	lwc1	$f0,0x0($s6)
/*  f0b7054:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0b7058:	00000000 */ 	nop
/*  f0b705c:	45020004 */ 	bc1fl	.L0f0b7070
/*  f0b7060:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b7064:	46000506 */ 	mov.s	$f20,$f0
/*  f0b7068:	02a08825 */ 	or	$s1,$s5,$zero
/*  f0b706c:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f0b7070:
/*  f0b7070:	16a3fff7 */ 	bne	$s5,$v1,.L0f0b7050
/*  f0b7074:	26d60004 */ 	addiu	$s6,$s6,0x4
.L0f0b7078:
/*  f0b7078:	0620003d */ 	bltz	$s1,.L0f0b7170
/*  f0b707c:	3c017f1b */ 	lui	$at,%hi(var7f1ad530)
/*  f0b7080:	c430d530 */ 	lwc1	$f16,%lo(var7f1ad530)($at)
/*  f0b7084:	8fb80298 */ 	lw	$t8,0x298($sp)
/*  f0b7088:	0011c840 */ 	sll	$t9,$s1,0x1
/*  f0b708c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0b7090:	24050046 */ 	addiu	$a1,$zero,0x46
/*  f0b7094:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0b7098:	00074900 */ 	sll	$t1,$a3,0x4
/*  f0b709c:	45010002 */ 	bc1t	.L0f0b70a8
/*  f0b70a0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0b70a4:	14e00032 */ 	bnez	$a3,.L0f0b7170
.L0f0b70a8:
/*  f0b70a8:	00075080 */ 	sll	$t2,$a3,0x2
/*  f0b70ac:	01475023 */ 	subu	$t2,$t2,$a3
/*  f0b70b0:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b70b4:	27ab0158 */ 	addiu	$t3,$sp,0x158
/*  f0b70b8:	27ad0198 */ 	addiu	$t5,$sp,0x198
/*  f0b70bc:	00076080 */ 	sll	$t4,$a3,0x2
/*  f0b70c0:	27ae0148 */ 	addiu	$t6,$sp,0x148
/*  f0b70c4:	018e9821 */ 	addu	$s3,$t4,$t6
/*  f0b70c8:	014d8021 */ 	addu	$s0,$t2,$t5
/*  f0b70cc:	012b9021 */ 	addu	$s2,$t1,$t3
/*  f0b70d0:	0fc456ac */ 	jal	padUnpack
/*  f0b70d4:	85040000 */ 	lh	$a0,0x0($t0)
/*  f0b70d8:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f0b70dc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0b70e0:	a64f0002 */ 	sh	$t7,0x2($s2)
/*  f0b70e4:	a6440000 */ 	sh	$a0,0x0($s2)
/*  f0b70e8:	c7b200d0 */ 	lwc1	$f18,0xd0($sp)
/*  f0b70ec:	e6120000 */ 	swc1	$f18,0x0($s0)
/*  f0b70f0:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0b70f4:	e6040004 */ 	swc1	$f4,0x4($s0)
/*  f0b70f8:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f0b70fc:	e6060008 */ 	swc1	$f6,0x8($s0)
/*  f0b7100:	c7ae00e4 */ 	lwc1	$f14,0xe4($sp)
/*  f0b7104:	0fc259d4 */ 	jal	func0f096750
/*  f0b7108:	c7ac00dc */ 	lwc1	$f12,0xdc($sp)
/*  f0b710c:	e6600000 */ 	swc1	$f0,0x0($s3)
/*  f0b7110:	44070000 */ 	mfc1	$a3,$f0
/*  f0b7114:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0b7118:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0b711c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0b7120:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0b7124:	c7ac0288 */ 	lwc1	$f12,0x288($sp)
/*  f0b7128:	02002825 */ 	or	$a1,$s0,$zero
/*  f0b712c:	0fc12be1 */ 	jal	func0f04af84
/*  f0b7130:	02403025 */ 	or	$a2,$s2,$zero
/*  f0b7134:	10400007 */ 	beqz	$v0,.L0f0b7154
/*  f0b7138:	00115080 */ 	sll	$t2,$s1,0x2
/*  f0b713c:	8fb90144 */ 	lw	$t9,0x144($sp)
/*  f0b7140:	00194040 */ 	sll	$t0,$t9,0x1
/*  f0b7144:	03c84821 */ 	addu	$t1,$s8,$t0
/*  f0b7148:	a5310000 */ 	sh	$s1,0x0($t1)
/*  f0b714c:	272b0001 */ 	addiu	$t3,$t9,0x1
/*  f0b7150:	afab0144 */ 	sw	$t3,0x144($sp)
.L0f0b7154:
/*  f0b7154:	02ea6821 */ 	addu	$t5,$s7,$t2
/*  f0b7158:	e5b60000 */ 	swc1	$f22,0x0($t5)
/*  f0b715c:	8fac0144 */ 	lw	$t4,0x144($sp)
/*  f0b7160:	29810004 */ 	slti	$at,$t4,0x4
/*  f0b7164:	5420ffb4 */ 	bnezl	$at,.L0f0b7038
/*  f0b7168:	8fa3029c */ 	lw	$v1,0x29c($sp)
/*  f0b716c:	01803825 */ 	or	$a3,$t4,$zero
.L0f0b7170:
/*  f0b7170:	18e0001f */ 	blez	$a3,.L0f0b71f0
/*  f0b7174:	00000000 */ 	nop
/*  f0b7178:	0c004b70 */ 	jal	random
/*  f0b717c:	00000000 */ 	nop
/*  f0b7180:	8fae0144 */ 	lw	$t6,0x144($sp)
/*  f0b7184:	27b80198 */ 	addiu	$t8,$sp,0x198
/*  f0b7188:	8fa8028c */ 	lw	$t0,0x28c($sp)
/*  f0b718c:	004e001b */ 	divu	$zero,$v0,$t6
/*  f0b7190:	00001810 */ 	mfhi	$v1
/*  f0b7194:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0b7198:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0b719c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b71a0:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f0b71a4:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*  f0b71a8:	00034900 */ 	sll	$t1,$v1,0x4
/*  f0b71ac:	27b90158 */ 	addiu	$t9,$sp,0x158
/*  f0b71b0:	e5080000 */ 	swc1	$f8,0x0($t0)
/*  f0b71b4:	c4ca0004 */ 	lwc1	$f10,0x4($a2)
/*  f0b71b8:	15c00002 */ 	bnez	$t6,.L0f0b71c4
/*  f0b71bc:	00000000 */ 	nop
/*  f0b71c0:	0007000d */ 	break	0x7
.L0f0b71c4:
/*  f0b71c4:	e50a0004 */ 	swc1	$f10,0x4($t0)
/*  f0b71c8:	c4d00008 */ 	lwc1	$f16,0x8($a2)
/*  f0b71cc:	0060a825 */ 	or	$s5,$v1,$zero
/*  f0b71d0:	01392021 */ 	addu	$a0,$t1,$t9
/*  f0b71d4:	e5100008 */ 	swc1	$f16,0x8($t0)
/*  f0b71d8:	0fc195e9 */ 	jal	roomsCopy
/*  f0b71dc:	8fa50290 */ 	lw	$a1,0x290($sp)
/*  f0b71e0:	00155880 */ 	sll	$t3,$s5,0x2
/*  f0b71e4:	03ab5021 */ 	addu	$t2,$sp,$t3
/*  f0b71e8:	10000020 */ 	b	.L0f0b726c
/*  f0b71ec:	c5420148 */ 	lwc1	$f2,0x148($t2)
.L0f0b71f0:
/*  f0b71f0:	0c004b70 */ 	jal	random
/*  f0b71f4:	00000000 */ 	nop
/*  f0b71f8:	8fac029c */ 	lw	$t4,0x29c($sp)
/*  f0b71fc:	8fad0298 */ 	lw	$t5,0x298($sp)
/*  f0b7200:	24050046 */ 	addiu	$a1,$zero,0x46
/*  f0b7204:	004c001b */ 	divu	$zero,$v0,$t4
/*  f0b7208:	00007010 */ 	mfhi	$t6
/*  f0b720c:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0b7210:	15800002 */ 	bnez	$t4,.L0f0b721c
/*  f0b7214:	00000000 */ 	nop
/*  f0b7218:	0007000d */ 	break	0x7
.L0f0b721c:
/*  f0b721c:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0b7220:	87040000 */ 	lh	$a0,0x0($t8)
/*  f0b7224:	0fc456ac */ 	jal	padUnpack
/*  f0b7228:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0b722c:	8fa90290 */ 	lw	$t1,0x290($sp)
/*  f0b7230:	8fa80118 */ 	lw	$t0,0x118($sp)
/*  f0b7234:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0b7238:	a5390002 */ 	sh	$t9,0x2($t1)
/*  f0b723c:	a5280000 */ 	sh	$t0,0x0($t1)
/*  f0b7240:	8fab028c */ 	lw	$t3,0x28c($sp)
/*  f0b7244:	c7b200d0 */ 	lwc1	$f18,0xd0($sp)
/*  f0b7248:	e5720000 */ 	swc1	$f18,0x0($t3)
/*  f0b724c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0b7250:	e5640004 */ 	swc1	$f4,0x4($t3)
/*  f0b7254:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f0b7258:	e5660008 */ 	swc1	$f6,0x8($t3)
/*  f0b725c:	c7ae00e4 */ 	lwc1	$f14,0xe4($sp)
/*  f0b7260:	0fc259d4 */ 	jal	func0f096750
/*  f0b7264:	c7ac00dc */ 	lwc1	$f12,0xdc($sp)
/*  f0b7268:	46000086 */ 	mov.s	$f2,$f0
.L0f0b726c:
/*  f0b726c:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0b7270:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0b7274:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0b7278:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0b727c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0b7280:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0b7284:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0b7288:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0b728c:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0b7290:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0b7294:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0b7298:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0b729c:	27bd0288 */ 	addiu	$sp,$sp,0x288
/*  f0b72a0:	03e00008 */ 	jr	$ra
/*  f0b72a4:	46001006 */ 	mov.s	$f0,$f2
);

f32 func0f0b72a8(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop)
{
	return func0f0b69d0(arg0, pos, rooms, prop, g_SpawnPoints, g_NumSpawnPoints);
}

GLOBAL_ASM(
glabel func0f0b72dc
.late_rodata
glabel var7f1ad53c
.word func0f0b72dc+0x374 # f0b7650
glabel var7f1ad540
.word func0f0b72dc+0x38c # f0b7668
glabel var7f1ad544
.word func0f0b72dc+0x3c4 # f0b76a0
glabel var7f1ad548
.word func0f0b72dc+0x3e4 # f0b76c0
glabel var7f1ad54c
.word func0f0b72dc+0x3ec # f0b76c8
glabel var7f1ad550
.word func0f0b72dc+0x3f4 # f0b76d0
glabel var7f1ad554
.word func0f0b72dc+0x3fc # f0b76d8
glabel var7f1ad558
.word func0f0b72dc+0x404 # f0b76e0
glabel var7f1ad55c
.word func0f0b72dc+0x404 # f0b76e0
glabel var7f1ad560
.word func0f0b72dc+0x37c # f0b7658
glabel var7f1ad564
.word func0f0b72dc+0x37c # f0b7658
glabel var7f1ad568
.word func0f0b72dc+0x384 # f0b7660
.text
/*  f0b72dc:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0b72e0:	3c0f8007 */ 	lui	$t7,%hi(var80070780)
/*  f0b72e4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0b72e8:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0b72ec:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f0b72f0:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0b72f4:	25ef0780 */ 	addiu	$t7,$t7,%lo(var80070780)
/*  f0b72f8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0b72fc:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f0b7300:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0b7304:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0b7308:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0b730c:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0b7310:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0b7314:	3c11800a */ 	lui	$s1,%hi(g_StageSetup+0xc)
/*  f0b7318:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0b731c:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0b7320:	8e31d03c */ 	lw	$s1,%lo(g_StageSetup+0xc)($s1)
/*  f0b7324:	0fc47788 */ 	jal	func0f11de20
/*  f0b7328:	8244028f */ 	lb	$a0,0x28f($s2)
/*  f0b732c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0b7330:	a12019b3 */ 	sb	$zero,0x19b3($t1)
/*  f0b7334:	8e4a0298 */ 	lw	$t2,0x298($s2)
/*  f0b7338:	05430010 */ 	bgezl	$t2,.L0f0b737c
/*  f0b733c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0b7340:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0b7344:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0b7348:	8d82001c */ 	lw	$v0,0x1c($t4)
/*  f0b734c:	5040000b */ 	beqzl	$v0,.L0f0b737c
/*  f0b7350:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0b7354:	8c430004 */ 	lw	$v1,0x4($v0)
.L0f0b7358:
/*  f0b7358:	50600005 */ 	beqzl	$v1,.L0f0b7370
/*  f0b735c:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f0b7360:	8c6d0040 */ 	lw	$t5,0x40($v1)
/*  f0b7364:	35b90004 */ 	ori	$t9,$t5,0x4
/*  f0b7368:	ac790040 */ 	sw	$t9,0x40($v1)
/*  f0b736c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f0b7370:
/*  f0b7370:	5440fff9 */ 	bnezl	$v0,.L0f0b7358
/*  f0b7374:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0b7378:	8e580284 */ 	lw	$t8,0x284($s2)
.L0f0b737c:
/*  f0b737c:	8f0e00bc */ 	lw	$t6,0xbc($t8)
/*  f0b7380:	0fc52719 */ 	jal	chrInitSplats
/*  f0b7384:	8dc40004 */ 	lw	$a0,0x4($t6)
/*  f0b7388:	0fc2ddf3 */ 	jal	func0f0b77cc
/*  f0b738c:	00000000 */ 	nop
/*  f0b7390:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0b7394:	24020007 */ 	addiu	$v0,$zero,0x7
/*  f0b7398:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f0b739c:	ade000d8 */ 	sw	$zero,0xd8($t7)
/*  f0b73a0:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0b73a4:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0b73a8:	ad021924 */ 	sw	$v0,0x1924($t0)
/*  f0b73ac:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0b73b0:	ad22193c */ 	sw	$v0,0x193c($t1)
/*  f0b73b4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0b73b8:	ad4016d8 */ 	sw	$zero,0x16d8($t2)
/*  f0b73bc:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0b73c0:	0fc37e87 */ 	jal	currentPlayerUnsetFlag
/*  f0b73c4:	ad8b17a4 */ 	sw	$t3,0x17a4($t4)
/*  f0b73c8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0b73cc:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0b73d0:	44816000 */ 	mtc1	$at,$f12
/*  f0b73d4:	27a5010c */ 	addiu	$a1,$sp,0x10c
/*  f0b73d8:	27a600fc */ 	addiu	$a2,$sp,0xfc
/*  f0b73dc:	0fc6185f */ 	jal	scenarioCallback2c
/*  f0b73e0:	8da700bc */ 	lw	$a3,0xbc($t5)
/*  f0b73e4:	3c017f1b */ 	lui	$at,%hi(var7f1ad534)
/*  f0b73e8:	c424d534 */ 	lwc1	$f4,%lo(var7f1ad534)($at)
/*  f0b73ec:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f0b73f0:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0b73f4:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0b73f8:	2619161e */ 	addiu	$t9,$s0,0x161e
/*  f0b73fc:	2618161c */ 	addiu	$t8,$s0,0x161c
/*  f0b7400:	260e19b0 */ 	addiu	$t6,$s0,0x19b0
/*  f0b7404:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f0b7408:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0b740c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0b7410:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0b7414:	3c0541f0 */ 	lui	$a1,0x41f0
/*  f0b7418:	27a600fc */ 	addiu	$a2,$sp,0xfc
/*  f0b741c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0b7420:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0b7424:	0c00a86c */ 	jal	coordFindGroundY
/*  f0b7428:	2607161a */ 	addiu	$a3,$s0,0x161a
/*  f0b742c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f0b7430:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0b7434:	44819000 */ 	mtc1	$at,$f18
/*  f0b7438:	c60819c4 */ 	lwc1	$f8,0x19c4($s0)
/*  f0b743c:	3c017f1b */ 	lui	$at,%hi(var7f1ad538)
/*  f0b7440:	27a5010c */ 	addiu	$a1,$sp,0x10c
/*  f0b7444:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0b7448:	e7aa0110 */ 	swc1	$f10,0x110($sp)
/*  f0b744c:	e6000074 */ 	swc1	$f0,0x74($s0)
/*  f0b7450:	c7b000f8 */ 	lwc1	$f16,0xf8($sp)
/*  f0b7454:	c426d538 */ 	lwc1	$f6,%lo(var7f1ad538)($at)
/*  f0b7458:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0b745c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0b7460:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0b7464:	e5e80144 */ 	swc1	$f8,0x144($t7)
/*  f0b7468:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0b746c:	e5000078 */ 	swc1	$f0,0x78($t0)
/*  f0b7470:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f0b7474:	0fc2e168 */ 	jal	func0f0b85a0
/*  f0b7478:	2484036c */ 	addiu	$a0,$a0,0x36c
/*  f0b747c:	0c0068f7 */ 	jal	sinf
/*  f0b7480:	c7ac00f8 */ 	lwc1	$f12,0xf8($sp)
/*  f0b7484:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0b7488:	46000287 */ 	neg.s	$f10,$f0
/*  f0b748c:	44808000 */ 	mtc1	$zero,$f16
/*  f0b7490:	e52a036c */ 	swc1	$f10,0x36c($t1)
/*  f0b7494:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0b7498:	e5500370 */ 	swc1	$f16,0x370($t2)
/*  f0b749c:	0c0068f4 */ 	jal	cosf
/*  f0b74a0:	c7ac00f8 */ 	lwc1	$f12,0xf8($sp)
/*  f0b74a4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0b74a8:	e5600374 */ 	swc1	$f0,0x374($t3)
/*  f0b74ac:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0b74b0:	c7a2010c */ 	lwc1	$f2,0x10c($sp)
/*  f0b74b4:	e5820310 */ 	swc1	$f2,0x310($t4)
/*  f0b74b8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0b74bc:	8db900bc */ 	lw	$t9,0xbc($t5)
/*  f0b74c0:	e7220008 */ 	swc1	$f2,0x8($t9)
/*  f0b74c4:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0b74c8:	c7a20110 */ 	lwc1	$f2,0x110($sp)
/*  f0b74cc:	e7020314 */ 	swc1	$f2,0x314($t8)
/*  f0b74d0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0b74d4:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0b74d8:	e5e2000c */ 	swc1	$f2,0xc($t7)
/*  f0b74dc:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0b74e0:	c7a20114 */ 	lwc1	$f2,0x114($sp)
/*  f0b74e4:	e5020318 */ 	swc1	$f2,0x318($t0)
/*  f0b74e8:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0b74ec:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0b74f0:	e5420010 */ 	swc1	$f2,0x10($t2)
/*  f0b74f4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0b74f8:	0fc19711 */ 	jal	func0f065c44
/*  f0b74fc:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f0b7500:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0b7504:	87ac00fc */ 	lh	$t4,0xfc($sp)
/*  f0b7508:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0b750c:	8db900bc */ 	lw	$t9,0xbc($t5)
/*  f0b7510:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0b7514:	a72c0028 */ 	sh	$t4,0x28($t9)
/*  f0b7518:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0b751c:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0b7520:	a5f8002a */ 	sh	$t8,0x2a($t7)
/*  f0b7524:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f0b7528:	87a700fc */ 	lh	$a3,0xfc($sp)
/*  f0b752c:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0b7530:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0b7534:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0b7538:	8e480298 */ 	lw	$t0,0x298($s2)
/*  f0b753c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*  f0b7540:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f0b7544:	05000023 */ 	bltz	$t0,.L0f0b75d4
.L0f0b7548:
/*  f0b7548:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0b754c:	1443fffe */ 	bne	$v0,$v1,.L0f0b7548
/*  f0b7550:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f0b7554:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0b7558:
/*  f0b7558:	0fc446b5 */ 	jal	func0f111ad4
/*  f0b755c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b7560:	1040000a */ 	beqz	$v0,.L0f0b758c
/*  f0b7564:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b7568:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f0b756c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b7570:	04400006 */ 	bltz	$v0,.L0f0b758c
/*  f0b7574:	28410021 */ 	slti	$at,$v0,0x21
/*  f0b7578:	10200004 */ 	beqz	$at,.L0f0b758c
/*  f0b757c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0b7580:	00025080 */ 	sll	$t2,$v0,0x2
/*  f0b7584:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f0b7588:	ad69005c */ 	sw	$t1,0x5c($t3)
.L0f0b758c:
/*  f0b758c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0b7590:	2401005e */ 	addiu	$at,$zero,0x5e
/*  f0b7594:	1601fff0 */ 	bne	$s0,$at,.L0f0b7558
/*  f0b7598:	00000000 */ 	nop
/*  f0b759c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b75a0:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*  f0b75a4:	27a400e0 */ 	addiu	$a0,$sp,0xe0
.L0f0b75a8:
/*  f0b75a8:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f0b75ac:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0b75b0:	15a00004 */ 	bnez	$t5,.L0f0b75c4
/*  f0b75b4:	00000000 */ 	nop
/*  f0b75b8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0b75bc:	0183c821 */ 	addu	$t9,$t4,$v1
/*  f0b75c0:	af2017a8 */ 	sw	$zero,0x17a8($t9)
.L0f0b75c4:
/*  f0b75c4:	1444fff8 */ 	bne	$v0,$a0,.L0f0b75a8
/*  f0b75c8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0b75cc:	1000000a */ 	b	.L0f0b75f8
/*  f0b75d0:	00000000 */ 	nop
.L0f0b75d4:
/*  f0b75d4:	0fc44580 */ 	jal	currentPlayerClearInventory
/*  f0b75d8:	00000000 */ 	nop
/*  f0b75dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b75e0:	24020084 */ 	addiu	$v0,$zero,0x84
.L0f0b75e4:
/*  f0b75e4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0b75e8:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f0b75ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0b75f0:	1462fffc */ 	bne	$v1,$v0,.L0f0b75e4
/*  f0b75f4:	af0017a8 */ 	sw	$zero,0x17a8($t8)
.L0f0b75f8:
/*  f0b75f8:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b75fc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b7600:	5220003c */ 	beqzl	$s1,.L0f0b76f4
/*  f0b7604:	8e4c0298 */ 	lw	$t4,0x298($s2)
/*  f0b7608:	8e4f029c */ 	lw	$t7,0x29c($s2)
/*  f0b760c:	05e20006 */ 	bltzl	$t7,.L0f0b7628
/*  f0b7610:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f0b7614:	8e4802a8 */ 	lw	$t0,0x2a8($s2)
/*  f0b7618:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0b761c:	51090035 */ 	beql	$t0,$t1,.L0f0b76f4
/*  f0b7620:	8e4c0298 */ 	lw	$t4,0x298($s2)
/*  f0b7624:	8e220000 */ 	lw	$v0,0x0($s1)
.L0f0b7628:
/*  f0b7628:	2410000c */ 	addiu	$s0,$zero,0xc
/*  f0b762c:	12020030 */ 	beq	$s0,$v0,.L0f0b76f0
/*  f0b7630:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f0b7634:
/*  f0b7634:	1020002a */ 	beqz	$at,.L0f0b76e0
/*  f0b7638:	00025080 */ 	sll	$t2,$v0,0x2
/*  f0b763c:	3c017f1b */ 	lui	$at,%hi(var7f1ad53c)
/*  f0b7640:	002a0821 */ 	addu	$at,$at,$t2
/*  f0b7644:	8c2ad53c */ 	lw	$t2,%lo(var7f1ad53c)($at)
/*  f0b7648:	01400008 */ 	jr	$t2
/*  f0b764c:	00000000 */ 	nop
/*  f0b7650:	10000024 */ 	b	.L0f0b76e4
/*  f0b7654:	2631000c */ 	addiu	$s1,$s1,12
/*  f0b7658:	10000022 */ 	b	.L0f0b76e4
/*  f0b765c:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0b7660:	10000020 */ 	b	.L0f0b76e4
/*  f0b7664:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0b7668:	8e2b000c */ 	lw	$t3,0xc($s1)
/*  f0b766c:	1560000a */ 	bnez	$t3,.L0f0b7698
/*  f0b7670:	00000000 */ 	nop
/*  f0b7674:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0b7678:	04a00005 */ 	bltz	$a1,.L0f0b7690
/*  f0b767c:	00000000 */ 	nop
/*  f0b7680:	0fc4478a */ 	jal	currentPlayerGiveWeaponWithArgument
/*  f0b7684:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f0b7688:	10000016 */ 	b	.L0f0b76e4
/*  f0b768c:	26310010 */ 	addiu	$s1,$s1,0x10
.L0f0b7690:
/*  f0b7690:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7694:	8e240004 */ 	lw	$a0,0x4($s1)
.L0f0b7698:
/*  f0b7698:	10000012 */ 	b	.L0f0b76e4
/*  f0b769c:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f0b76a0:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f0b76a4:	15a00004 */ 	bnez	$t5,.L0f0b76b8
/*  f0b76a8:	00000000 */ 	nop
/*  f0b76ac:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f0b76b0:	0fc2a58a */ 	jal	currentPlayerSetAmmoQuantity
/*  f0b76b4:	8e250008 */ 	lw	$a1,0x8($s1)
.L0f0b76b8:
/*  f0b76b8:	1000000a */ 	b	.L0f0b76e4
/*  f0b76bc:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f0b76c0:	10000008 */ 	b	.L0f0b76e4
/*  f0b76c4:	26310020 */ 	addiu	$s1,$s1,0x20
/*  f0b76c8:	10000006 */ 	b	.L0f0b76e4
/*  f0b76cc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0b76d0:	10000004 */ 	b	.L0f0b76e4
/*  f0b76d4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0b76d8:	10000002 */ 	b	.L0f0b76e4
/*  f0b76dc:	26310028 */ 	addiu	$s1,$s1,0x28
.L0f0b76e0:
/*  f0b76e0:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f0b76e4:
/*  f0b76e4:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f0b76e8:	5602ffd2 */ 	bnel	$s0,$v0,.L0f0b7634
/*  f0b76ec:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f0b76f0:
/*  f0b76f0:	8e4c0298 */ 	lw	$t4,0x298($s2)
.L0f0b76f4:
/*  f0b76f4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f0b76f8:	05800011 */ 	bltz	$t4,.L0f0b7740
/*  f0b76fc:	00000000 */ 	nop
/*  f0b7700:	44801000 */ 	mtc1	$zero,$f2
/*  f0b7704:	c6001c5c */ 	lwc1	$f0,0x1c5c($s0)
/*  f0b7708:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0b770c:	00000000 */ 	nop
/*  f0b7710:	4500000b */ 	bc1f	.L0f0b7740
/*  f0b7714:	00000000 */ 	nop
/*  f0b7718:	e60000dc */ 	swc1	$f0,0xdc($s0)
/*  f0b771c:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0b7720:	e72200e4 */ 	swc1	$f2,0xe4($t9)
/*  f0b7724:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0b7728:	e5c200e8 */ 	swc1	$f2,0xe8($t6)
/*  f0b772c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0b7730:	e70200ec */ 	swc1	$f2,0xec($t8)
/*  f0b7734:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0b7738:	e5e200f0 */ 	swc1	$f2,0xf0($t7)
/*  f0b773c:	8e500284 */ 	lw	$s0,0x284($s2)
.L0f0b7740:
/*  f0b7740:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f0b7744:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b7748:	0fc2e00b */ 	jal	func0f0b802c
/*  f0b774c:	00000000 */ 	nop
/*  f0b7750:	8e480318 */ 	lw	$t0,0x318($s2)
/*  f0b7754:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b7758:	5100000a */ 	beqzl	$t0,.L0f0b7784
/*  f0b775c:	44806000 */ 	mtc1	$zero,$f12
/*  f0b7760:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0b7764:	44816000 */ 	mtc1	$at,$f12
/*  f0b7768:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b776c:	44817000 */ 	mtc1	$at,$f14
/*  f0b7770:	0fc2ed5f */ 	jal	currentPlayerStartChrFade
/*  f0b7774:	00000000 */ 	nop
/*  f0b7778:	10000006 */ 	b	.L0f0b7794
/*  f0b777c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0b7780:	44806000 */ 	mtc1	$zero,$f12
.L0f0b7784:
/*  f0b7784:	44817000 */ 	mtc1	$at,$f14
/*  f0b7788:	0fc2ed5f */ 	jal	currentPlayerStartChrFade
/*  f0b778c:	00000000 */ 	nop
/*  f0b7790:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0b7794:
/*  f0b7794:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0b7798:	8d420004 */ 	lw	$v0,0x4($t2)
/*  f0b779c:	50400006 */ 	beqzl	$v0,.L0f0b77b8
/*  f0b77a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0b77a4:	8c4b0018 */ 	lw	$t3,0x18($v0)
/*  f0b77a8:	2401fbff */ 	addiu	$at,$zero,-1025
/*  f0b77ac:	01616824 */ 	and	$t5,$t3,$at
/*  f0b77b0:	ac4d0018 */ 	sw	$t5,0x18($v0)
/*  f0b77b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0b77b8:
/*  f0b77b8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0b77bc:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f0b77c0:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f0b77c4:	03e00008 */ 	jr	$ra
/*  f0b77c8:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

GLOBAL_ASM(
glabel func0f0b77cc
.late_rodata
glabel var7f1ad56c
.word 0x3c23d70a
glabel var7f1ad570
.word 0x3f7a9fbe
.text
/*  f0b77cc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0b77d0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0b77d4:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b77d8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b77dc:	8e0e0314 */ 	lw	$t6,0x314($s0)
/*  f0b77e0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0b77e4:	4480a000 */ 	mtc1	$zero,$f20
/*  f0b77e8:	11c00004 */ 	beqz	$t6,.L0f0b77fc
/*  f0b77ec:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0b77f0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b77f4:	8c6f00d4 */ 	lw	$t7,0xd4($v1)
/*  f0b77f8:	15e00009 */ 	bnez	$t7,.L0f0b7820
.L0f0b77fc:
/*  f0b77fc:	3c01431f */ 	lui	$at,0x431f
/*  f0b7800:	44812000 */ 	mtc1	$at,$f4
/*  f0b7804:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7808:	3c01432c */ 	lui	$at,0x432c
/*  f0b780c:	44813000 */ 	mtc1	$at,$f6
/*  f0b7810:	e70419c4 */ 	swc1	$f4,0x19c4($t8)
/*  f0b7814:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7818:	e72619c0 */ 	swc1	$f6,0x19c0($t9)
/*  f0b781c:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b7820:
/*  f0b7820:	e4740038 */ 	swc1	$f20,0x38($v1)
/*  f0b7824:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7828:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0b782c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7830:	e514003c */ 	swc1	$f20,0x3c($t0)
/*  f0b7834:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7838:	e5340040 */ 	swc1	$f20,0x40($t1)
/*  f0b783c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7840:	e5540044 */ 	swc1	$f20,0x44($t2)
/*  f0b7844:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7848:	e5740048 */ 	swc1	$f20,0x48($t3)
/*  f0b784c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7850:	e594004c */ 	swc1	$f20,0x4c($t4)
/*  f0b7854:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7858:	e5b40050 */ 	swc1	$f20,0x50($t5)
/*  f0b785c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7860:	e5d40054 */ 	swc1	$f20,0x54($t6)
/*  f0b7864:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7868:	e5f40058 */ 	swc1	$f20,0x58($t7)
/*  f0b786c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7870:	af000000 */ 	sw	$zero,0x0($t8)
/*  f0b7874:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7878:	e7340004 */ 	swc1	$f20,0x4($t9)
/*  f0b787c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7880:	e5140008 */ 	swc1	$f20,0x8($t0)
/*  f0b7884:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7888:	e534000c */ 	swc1	$f20,0xc($t1)
/*  f0b788c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7890:	ad420014 */ 	sw	$v0,0x14($t2)
/*  f0b7894:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7898:	ad6201b0 */ 	sw	$v0,0x1b0($t3)
/*  f0b789c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b78a0:	0fc31f4c */ 	jal	currentPlayerSetMoveMode
/*  f0b78a4:	ad801af8 */ 	sw	$zero,0x1af8($t4)
/*  f0b78a8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b78ac:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b78b0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0b78b4:	ada500c0 */ 	sw	$a1,0xc0($t5)
/*  f0b78b8:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b78bc:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0b78c0:	a1ee19cc */ 	sb	$t6,0x19cc($t7)
/*  f0b78c4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b78c8:	a73819ce */ 	sh	$t8,0x19ce($t9)
/*  f0b78cc:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b78d0:	e51419d0 */ 	swc1	$f20,0x19d0($t0)
/*  f0b78d4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b78d8:	e53419d4 */ 	swc1	$f20,0x19d4($t1)
/*  f0b78dc:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b78e0:	e55419d8 */ 	swc1	$f20,0x19d8($t2)
/*  f0b78e4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b78e8:	e57419dc */ 	swc1	$f20,0x19dc($t3)
/*  f0b78ec:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b78f0:	e59419e0 */ 	swc1	$f20,0x19e0($t4)
/*  f0b78f4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b78f8:	ada000d0 */ 	sw	$zero,0xd0($t5)
/*  f0b78fc:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7900:	adc000d8 */ 	sw	$zero,0xd8($t6)
/*  f0b7904:	0fc59585 */ 	jal	stageGetIndex
/*  f0b7908:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0b790c:	24010027 */ 	addiu	$at,$zero,0x27
/*  f0b7910:	14410008 */ 	bne	$v0,$at,.L0f0b7934
/*  f0b7914:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b7918:	3c017f1b */ 	lui	$at,%hi(var7f1ad56c)
/*  f0b791c:	c428d56c */ 	lwc1	$f8,%lo(var7f1ad56c)($at)
/*  f0b7920:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7924:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b7928:	44816000 */ 	mtc1	$at,$f12
/*  f0b792c:	10000010 */ 	b	.L0f0b7970
/*  f0b7930:	e5e800dc */ 	swc1	$f8,0xdc($t7)
.L0f0b7934:
/*  f0b7934:	0fc59585 */ 	jal	stageGetIndex
/*  f0b7938:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0b793c:	14400008 */ 	bnez	$v0,.L0f0b7960
/*  f0b7940:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b7944:	3c013f00 */ 	lui	$at,0x3f00
/*  f0b7948:	44815000 */ 	mtc1	$at,$f10
/*  f0b794c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7950:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b7954:	44816000 */ 	mtc1	$at,$f12
/*  f0b7958:	10000005 */ 	b	.L0f0b7970
/*  f0b795c:	e70a00dc */ 	swc1	$f10,0xdc($t8)
.L0f0b7960:
/*  f0b7960:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b7964:	44816000 */ 	mtc1	$at,$f12
/*  f0b7968:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b796c:	e72c00dc */ 	swc1	$f12,0xdc($t9)
.L0f0b7970:
/*  f0b7970:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7974:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0b7978:	44810000 */ 	mtc1	$at,$f0
/*  f0b797c:	e50c00e4 */ 	swc1	$f12,0xe4($t0)
/*  f0b7980:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7984:	3c01c080 */ 	lui	$at,0xc080
/*  f0b7988:	44818000 */ 	mtc1	$at,$f16
/*  f0b798c:	e53400e8 */ 	swc1	$f20,0xe8($t1)
/*  f0b7990:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7994:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0b7998:	e54c00ec */ 	swc1	$f12,0xec($t2)
/*  f0b799c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b79a0:	e57400f0 */ 	swc1	$f20,0xf0($t3)
/*  f0b79a4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b79a8:	e58000f4 */ 	swc1	$f0,0xf4($t4)
/*  f0b79ac:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b79b0:	e5a000f8 */ 	swc1	$f0,0xf8($t5)
/*  f0b79b4:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b79b8:	e5c00280 */ 	swc1	$f0,0x280($t6)
/*  f0b79bc:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b79c0:	ade000fc */ 	sw	$zero,0xfc($t7)
/*  f0b79c4:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b79c8:	e7140198 */ 	swc1	$f20,0x198($t8)
/*  f0b79cc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b79d0:	e7340148 */ 	swc1	$f20,0x148($t9)
/*  f0b79d4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b79d8:	e5141b9c */ 	swc1	$f20,0x1b9c($t0)
/*  f0b79dc:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b79e0:	e52c014c */ 	swc1	$f12,0x14c($t1)
/*  f0b79e4:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b79e8:	e5540150 */ 	swc1	$f20,0x150($t2)
/*  f0b79ec:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b79f0:	e5700154 */ 	swc1	$f16,0x154($t3)
/*  f0b79f4:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b79f8:	c4720154 */ 	lwc1	$f18,0x154($v1)
/*  f0b79fc:	e4720158 */ 	swc1	$f18,0x158($v1)
/*  f0b7a00:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b7a04:	c4620158 */ 	lwc1	$f2,0x158($v1)
/*  f0b7a08:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0b7a0c:	00000000 */ 	nop
/*  f0b7a10:	45020007 */ 	bc1fl	.L0f0b7a30
/*  f0b7a14:	e474015c */ 	swc1	$f20,0x15c($v1)
/*  f0b7a18:	44812000 */ 	mtc1	$at,$f4
/*  f0b7a1c:	00000000 */ 	nop
/*  f0b7a20:	46041180 */ 	add.s	$f6,$f2,$f4
/*  f0b7a24:	e4660158 */ 	swc1	$f6,0x158($v1)
/*  f0b7a28:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b7a2c:	e474015c */ 	swc1	$f20,0x15c($v1)
.L0f0b7a30:
/*  f0b7a30:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7a34:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0b7a38:	3c017f1b */ 	lui	$at,%hi(var7f1ad570)
/*  f0b7a3c:	e58c0160 */ 	swc1	$f12,0x160($t4)
/*  f0b7a40:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7a44:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0b7a48:	e5b40164 */ 	swc1	$f20,0x164($t5)
/*  f0b7a4c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7a50:	e5d4017c */ 	swc1	$f20,0x17c($t6)
/*  f0b7a54:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7a58:	e5f40180 */ 	swc1	$f20,0x180($t7)
/*  f0b7a5c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7a60:	e7140184 */ 	swc1	$f20,0x184($t8)
/*  f0b7a64:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7a68:	af200100 */ 	sw	$zero,0x100($t9)
/*  f0b7a6c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7a70:	ad000104 */ 	sw	$zero,0x104($t0)
/*  f0b7a74:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7a78:	ad200108 */ 	sw	$zero,0x108($t1)
/*  f0b7a7c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7a80:	ad40010c */ 	sw	$zero,0x10c($t2)
/*  f0b7a84:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7a88:	ad650110 */ 	sw	$a1,0x110($t3)
/*  f0b7a8c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7a90:	ad850114 */ 	sw	$a1,0x114($t4)
/*  f0b7a94:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7a98:	ada00118 */ 	sw	$zero,0x118($t5)
/*  f0b7a9c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7aa0:	adc5011c */ 	sw	$a1,0x11c($t6)
/*  f0b7aa4:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7aa8:	ade00120 */ 	sw	$zero,0x120($t7)
/*  f0b7aac:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7ab0:	af050124 */ 	sw	$a1,0x124($t8)
/*  f0b7ab4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7ab8:	e7340128 */ 	swc1	$f20,0x128($t9)
/*  f0b7abc:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7ac0:	ad00012c */ 	sw	$zero,0x12c($t0)
/*  f0b7ac4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7ac8:	ad240130 */ 	sw	$a0,0x130($t1)
/*  f0b7acc:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7ad0:	ad450134 */ 	sw	$a1,0x134($t2)
/*  f0b7ad4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7ad8:	e5740138 */ 	swc1	$f20,0x138($t3)
/*  f0b7adc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7ae0:	ad80013c */ 	sw	$zero,0x13c($t4)
/*  f0b7ae4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7ae8:	ada40140 */ 	sw	$a0,0x140($t5)
/*  f0b7aec:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7af0:	c428d570 */ 	lwc1	$f8,%lo(var7f1ad570)($at)
/*  f0b7af4:	3c014170 */ 	lui	$at,0x4170
/*  f0b7af8:	44815000 */ 	mtc1	$at,$f10
/*  f0b7afc:	e5c81b68 */ 	swc1	$f8,0x1b68($t6)
/*  f0b7b00:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7b04:	ade202d8 */ 	sw	$v0,0x2d8($t7)
/*  f0b7b08:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7b0c:	af0202dc */ 	sw	$v0,0x2dc($t8)
/*  f0b7b10:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7b14:	af2202e0 */ 	sw	$v0,0x2e0($t9)
/*  f0b7b18:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7b1c:	e51402e4 */ 	swc1	$f20,0x2e4($t0)
/*  f0b7b20:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7b24:	e52002e8 */ 	swc1	$f0,0x2e8($t1)
/*  f0b7b28:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7b2c:	e54002ec */ 	swc1	$f0,0x2ec($t2)
/*  f0b7b30:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7b34:	ad6202f0 */ 	sw	$v0,0x2f0($t3)
/*  f0b7b38:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7b3c:	ad8202f4 */ 	sw	$v0,0x2f4($t4)
/*  f0b7b40:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7b44:	ada202f8 */ 	sw	$v0,0x2f8($t5)
/*  f0b7b48:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7b4c:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0b7b50:	adc202fc */ 	sw	$v0,0x2fc($t6)
/*  f0b7b54:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7b58:	ade20300 */ 	sw	$v0,0x300($t7)
/*  f0b7b5c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7b60:	af020304 */ 	sw	$v0,0x304($t8)
/*  f0b7b64:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7b68:	e7340308 */ 	swc1	$f20,0x308($t9)
/*  f0b7b6c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7b70:	e514030c */ 	swc1	$f20,0x30c($t0)
/*  f0b7b74:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7b78:	e5200188 */ 	swc1	$f0,0x188($t1)
/*  f0b7b7c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7b80:	e540018c */ 	swc1	$f0,0x18c($t2)
/*  f0b7b84:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7b88:	e5740190 */ 	swc1	$f20,0x190($t3)
/*  f0b7b8c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7b90:	e5940194 */ 	swc1	$f20,0x194($t4)
/*  f0b7b94:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7b98:	adcd0334 */ 	sw	$t5,0x334($t6)
/*  f0b7b9c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7ba0:	e5ea1928 */ 	swc1	$f10,0x1928($t7)
/*  f0b7ba4:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7ba8:	e714196c */ 	swc1	$f20,0x196c($t8)
/*  f0b7bac:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7bb0:	e7341970 */ 	swc1	$f20,0x1970($t9)
/*  f0b7bb4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7bb8:	ad0002b0 */ 	sw	$zero,0x2b0($t0)
/*  f0b7bbc:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7bc0:	ad200298 */ 	sw	$zero,0x298($t1)
/*  f0b7bc4:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7bc8:	ad4002ac */ 	sw	$zero,0x2ac($t2)
/*  f0b7bcc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7bd0:	ad600268 */ 	sw	$zero,0x268($t3)
/*  f0b7bd4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7bd8:	e594026c */ 	swc1	$f20,0x26c($t4)
/*  f0b7bdc:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7be0:	ada00274 */ 	sw	$zero,0x274($t5)
/*  f0b7be4:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7be8:	adc000c4 */ 	sw	$zero,0xc4($t6)
/*  f0b7bec:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7bf0:	ade01c04 */ 	sw	$zero,0x1c04($t7)
/*  f0b7bf4:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7bf8:	af041c0c */ 	sw	$a0,0x1c0c($t8)
/*  f0b7bfc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b7c00:	af201c10 */ 	sw	$zero,0x1c10($t9)
/*  f0b7c04:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b7c08:	ad001c1c */ 	sw	$zero,0x1c1c($t0)
/*  f0b7c0c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0b7c10:	ad201c20 */ 	sw	$zero,0x1c20($t1)
/*  f0b7c14:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0b7c18:	ad401c24 */ 	sw	$zero,0x1c24($t2)
/*  f0b7c1c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0b7c20:	ad601c28 */ 	sw	$zero,0x1c28($t3)
/*  f0b7c24:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b7c28:	ad801c2c */ 	sw	$zero,0x1c2c($t4)
/*  f0b7c2c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b7c30:	ada01c30 */ 	sw	$zero,0x1c30($t5)
/*  f0b7c34:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b7c38:	adc01c34 */ 	sw	$zero,0x1c34($t6)
/*  f0b7c3c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b7c40:	ade01c38 */ 	sw	$zero,0x1c38($t7)
/*  f0b7c44:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b7c48:	af001c3c */ 	sw	$zero,0x1c3c($t8)
/*  f0b7c4c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0b7c50:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0b7c54:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0b7c58:	03e00008 */ 	jr	$ra
/*  f0b7c5c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0b7c60
/*  f0b7c60:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0b7c64:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b7c68:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b7c6c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0b7c70:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0b7c74:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0b7c78:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0b7c7c:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f0b7c80:	3c010001 */ 	lui	$at,0x1
/*  f0b7c84:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f0b7c88:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0b7c8c:	8c990018 */ 	lw	$t9,0x18($a0)
/*  f0b7c90:	00808025 */ 	or	$s0,$a0,$zero
/*  f0b7c94:	03214025 */ 	or	$t0,$t9,$at
/*  f0b7c98:	ac880018 */ 	sw	$t0,0x18($a0)
/*  f0b7c9c:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f0b7ca0:	3c010010 */ 	lui	$at,0x10
/*  f0b7ca4:	01215025 */ 	or	$t2,$t1,$at
/*  f0b7ca8:	ac4a0014 */ 	sw	$t2,0x14($v0)
/*  f0b7cac:	c4840024 */ 	lwc1	$f4,0x24($a0)
/*  f0b7cb0:	e4440024 */ 	swc1	$f4,0x24($v0)
/*  f0b7cb4:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f0b7cb8:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0b7cbc:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f0b7cc0:	44070000 */ 	mfc1	$a3,$f0
/*  f0b7cc4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0b7cc8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0b7ccc:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0b7cd0:	0fc12dd2 */ 	jal	chrMoveToPos
/*  f0b7cd4:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f0b7cd8:	14400003 */ 	bnez	$v0,.L0f0b7ce8
/*  f0b7cdc:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f0b7ce0:	116000c8 */ 	beqz	$t3,.L0f0b8004
/*  f0b7ce4:	3c01fffe */ 	lui	$at,0xfffe
.L0f0b7ce8:
/*  f0b7ce8:	8e020170 */ 	lw	$v0,0x170($s0)
/*  f0b7cec:	10400016 */ 	beqz	$v0,.L0f0b7d48
/*  f0b7cf0:	00000000 */ 	nop
/*  f0b7cf4:	8e0c0174 */ 	lw	$t4,0x174($s0)
/*  f0b7cf8:	11800013 */ 	beqz	$t4,.L0f0b7d48
/*  f0b7cfc:	00000000 */ 	nop
/*  f0b7d00:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0b7d04:	9064005c */ 	lbu	$a0,0x5c($v1)
/*  f0b7d08:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7d0c:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0b7d10:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f0b7d14:	91a4005c */ 	lbu	$a0,0x5c($t5)
/*  f0b7d18:	0fc4478a */ 	jal	currentPlayerGiveWeaponWithArgument
/*  f0b7d1c:	00802825 */ 	or	$a1,$a0,$zero
/*  f0b7d20:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f0b7d24:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7d28:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7d2c:	91c5005c */ 	lbu	$a1,0x5c($t6)
/*  f0b7d30:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f0b7d34:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b7d38:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7d3c:	91e5005c */ 	lbu	$a1,0x5c($t7)
/*  f0b7d40:	10000033 */ 	b	.L0f0b7e10
/*  f0b7d44:	00000000 */ 	nop
.L0f0b7d48:
/*  f0b7d48:	50400016 */ 	beqzl	$v0,.L0f0b7da4
/*  f0b7d4c:	8e020174 */ 	lw	$v0,0x174($s0)
/*  f0b7d50:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0b7d54:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0b7d58:	9064005c */ 	lbu	$a0,0x5c($v1)
/*  f0b7d5c:	14810008 */ 	bne	$a0,$at,.L0f0b7d80
/*  f0b7d60:	00000000 */ 	nop
/*  f0b7d64:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7d68:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f0b7d6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7d70:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7d74:	2405000f */ 	addiu	$a1,$zero,0xf
/*  f0b7d78:	10000025 */ 	b	.L0f0b7e10
/*  f0b7d7c:	00000000 */ 	nop
.L0f0b7d80:
/*  f0b7d80:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7d84:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0b7d88:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f0b7d8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7d90:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7d94:	9065005c */ 	lbu	$a1,0x5c($v1)
/*  f0b7d98:	1000001d */ 	b	.L0f0b7e10
/*  f0b7d9c:	00000000 */ 	nop
/*  f0b7da0:	8e020174 */ 	lw	$v0,0x174($s0)
.L0f0b7da4:
/*  f0b7da4:	10400015 */ 	beqz	$v0,.L0f0b7dfc
/*  f0b7da8:	00000000 */ 	nop
/*  f0b7dac:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0b7db0:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0b7db4:	9064005c */ 	lbu	$a0,0x5c($v1)
/*  f0b7db8:	14810008 */ 	bne	$a0,$at,.L0f0b7ddc
/*  f0b7dbc:	00000000 */ 	nop
/*  f0b7dc0:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7dc4:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f0b7dc8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7dcc:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7dd0:	2405000f */ 	addiu	$a1,$zero,0xf
/*  f0b7dd4:	1000000e */ 	b	.L0f0b7e10
/*  f0b7dd8:	00000000 */ 	nop
.L0f0b7ddc:
/*  f0b7ddc:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7de0:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f0b7de4:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f0b7de8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7dec:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7df0:	9065005c */ 	lbu	$a1,0x5c($v1)
/*  f0b7df4:	10000006 */ 	b	.L0f0b7e10
/*  f0b7df8:	00000000 */ 	nop
.L0f0b7dfc:
/*  f0b7dfc:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b7e00:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b7e04:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b7e08:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b7e0c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b7e10:
/*  f0b7e10:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b7e14:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b7e18:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f0b7e1c:	2402ffd8 */ 	addiu	$v0,$zero,-40
/*  f0b7e20:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b7e24:	a702024c */ 	sh	$v0,0x24c($t8)
/*  f0b7e28:	8c790284 */ 	lw	$t9,0x284($v1)
/*  f0b7e2c:	0fc2a660 */ 	jal	currentPlayerGiveUnlimitedAmmo
/*  f0b7e30:	a722024e */ 	sh	$v0,0x24e($t9)
/*  f0b7e34:	0fc08169 */ 	jal	chrGetMaxDamage
/*  f0b7e38:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b7e3c:	c6060100 */ 	lwc1	$f6,0x100($s0)
/*  f0b7e40:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b7e44:	44811000 */ 	mtc1	$at,$f2
/*  f0b7e48:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0b7e4c:	3c013e00 */ 	lui	$at,0x3e00
/*  f0b7e50:	44815000 */ 	mtc1	$at,$f10
/*  f0b7e54:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b7e58:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b7e5c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0b7e60:	8c680284 */ 	lw	$t0,0x284($v1)
/*  f0b7e64:	e51000dc */ 	swc1	$f16,0xdc($t0)
/*  f0b7e68:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0b7e6c:	c45200dc */ 	lwc1	$f18,0xdc($v0)
/*  f0b7e70:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0b7e74:	00000000 */ 	nop
/*  f0b7e78:	45000002 */ 	bc1f	.L0f0b7e84
/*  f0b7e7c:	00000000 */ 	nop
/*  f0b7e80:	e44200dc */ 	swc1	$f2,0xdc($v0)
.L0f0b7e84:
/*  f0b7e84:	0fc0cfe8 */ 	jal	chrGetShield
/*  f0b7e88:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b7e8c:	44050000 */ 	mfc1	$a1,$f0
/*  f0b7e90:	0fc0cfea */ 	jal	chrSetShield
/*  f0b7e94:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0b7e98:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0b7e9c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0b7ea0:	8c490284 */ 	lw	$t1,0x284($v0)
/*  f0b7ea4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b7ea8:	ad2019c8 */ 	sw	$zero,0x19c8($t1)
/*  f0b7eac:	8c4a0284 */ 	lw	$t2,0x284($v0)
/*  f0b7eb0:	ad4000d4 */ 	sw	$zero,0xd4($t2)
/*  f0b7eb4:	8c4b0284 */ 	lw	$t3,0x284($v0)
/*  f0b7eb8:	0fc08351 */ 	jal	func0f020d44
/*  f0b7ebc:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f0b7ec0:	860c0010 */ 	lh	$t4,0x10($s0)
/*  f0b7ec4:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f0b7ec8:	15810007 */ 	bne	$t4,$at,.L0f0b7ee8
/*  f0b7ecc:	240d0008 */ 	addiu	$t5,$zero,0x8
/*  f0b7ed0:	3c01800a */ 	lui	$at,%hi(g_Vars+0x440)
/*  f0b7ed4:	ac2da400 */ 	sw	$t5,%lo(g_Vars+0x440)($at)
/*  f0b7ed8:	3c01800a */ 	lui	$at,%hi(g_Vars+0x444)
/*  f0b7edc:	240e005b */ 	addiu	$t6,$zero,0x5b
/*  f0b7ee0:	10000007 */ 	b	.L0f0b7f00
/*  f0b7ee4:	ac2ea404 */ 	sw	$t6,%lo(g_Vars+0x444)($at)
.L0f0b7ee8:
/*  f0b7ee8:	820f0006 */ 	lb	$t7,0x6($s0)
/*  f0b7eec:	3c01800a */ 	lui	$at,%hi(g_Vars+0x440)
/*  f0b7ef0:	ac2fa400 */ 	sw	$t7,%lo(g_Vars+0x440)($at)
/*  f0b7ef4:	86180010 */ 	lh	$t8,0x10($s0)
/*  f0b7ef8:	3c01800a */ 	lui	$at,%hi(g_Vars+0x444)
/*  f0b7efc:	ac38a404 */ 	sw	$t8,%lo(g_Vars+0x444)($at)
.L0f0b7f00:
/*  f0b7f00:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0b7f04:	00000000 */ 	nop
/*  f0b7f08:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f0b7f0c:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0b7f10:	0c007764 */ 	jal	modelCopyAnimData
/*  f0b7f14:	8f250020 */ 	lw	$a1,0x20($t9)
/*  f0b7f18:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0b7f1c:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f0b7f20:	3c054140 */ 	lui	$a1,0x4140
/*  f0b7f24:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0b7f28:	8c880008 */ 	lw	$t0,0x8($a0)
/*  f0b7f2c:	0c006a87 */ 	jal	modelGetNodeData
/*  f0b7f30:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f0b7f34:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f0b7f38:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0b7f3c:	8d240020 */ 	lw	$a0,0x20($t1)
/*  f0b7f40:	8c8a0008 */ 	lw	$t2,0x8($a0)
/*  f0b7f44:	0c006a87 */ 	jal	modelGetNodeData
/*  f0b7f48:	8d450000 */ 	lw	$a1,0x0($t2)
/*  f0b7f4c:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0b7f50:	3c014120 */ 	lui	$at,0x4120
/*  f0b7f54:	44810000 */ 	mtc1	$at,$f0
/*  f0b7f58:	00407825 */ 	or	$t7,$v0,$zero
/*  f0b7f5c:	256e0060 */ 	addiu	$t6,$t3,0x60
.L0f0b7f60:
/*  f0b7f60:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0b7f64:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f0b7f68:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0b7f6c:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f0b7f70:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f0b7f74:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f0b7f78:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f0b7f7c:	156efff8 */ 	bne	$t3,$t6,.L0f0b7f60
/*  f0b7f80:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f0b7f84:	c4440038 */ 	lwc1	$f4,0x38($v0)
/*  f0b7f88:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0b7f8c:	00000000 */ 	nop
/*  f0b7f90:	45020003 */ 	bc1fl	.L0f0b7fa0
/*  f0b7f94:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f0b7f98:	e4400038 */ 	swc1	$f0,0x38($v0)
/*  f0b7f9c:	c4460028 */ 	lwc1	$f6,0x28($v0)
.L0f0b7fa0:
/*  f0b7fa0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0b7fa4:	00000000 */ 	nop
/*  f0b7fa8:	45020003 */ 	bc1fl	.L0f0b7fb8
/*  f0b7fac:	c6080024 */ 	lwc1	$f8,0x24($s0)
/*  f0b7fb0:	e4400028 */ 	swc1	$f0,0x28($v0)
/*  f0b7fb4:	c6080024 */ 	lwc1	$f8,0x24($s0)
.L0f0b7fb8:
/*  f0b7fb8:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0b7fbc:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0b7fc0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b7fc4:	e7080024 */ 	swc1	$f8,0x24($t8)
/*  f0b7fc8:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0b7fcc:	c60a0024 */ 	lwc1	$f10,0x24($s0)
/*  f0b7fd0:	e72a0378 */ 	swc1	$f10,0x378($t9)
/*  f0b7fd4:	0fc08351 */ 	jal	func0f020d44
/*  f0b7fd8:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0b7fdc:	0fc19711 */ 	jal	func0f065c44
/*  f0b7fe0:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0b7fe4:	0fc18171 */ 	jal	func0f0605c4
/*  f0b7fe8:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0b7fec:	0fc180c0 */ 	jal	propHide
/*  f0b7ff0:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0b7ff4:	0fc1810e */ 	jal	propFree
/*  f0b7ff8:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0b7ffc:	10000006 */ 	b	.L0f0b8018
/*  f0b8000:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b8004:
/*  f0b8004:	8e080018 */ 	lw	$t0,0x18($s0)
/*  f0b8008:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0b800c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b8010:	01014824 */ 	and	$t1,$t0,$at
/*  f0b8014:	ae090018 */ 	sw	$t1,0x18($s0)
.L0f0b8018:
/*  f0b8018:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0b801c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0b8020:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0b8024:	03e00008 */ 	jr	$ra
/*  f0b8028:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b802c
.late_rodata
glabel var7f1ad574
.word 0x49742400
.text
/*  f0b802c:	27bdfee0 */ 	addiu	$sp,$sp,-288
/*  f0b8030:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0b8034:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f0b8038:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f0b803c:	8eee0284 */ 	lw	$t6,0x284($s7)
/*  f0b8040:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0b8044:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0b8048:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0b804c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0b8050:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0b8054:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0b8058:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0b805c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0b8060:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0b8064:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0b8068:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0b806c:	adc00330 */ 	sw	$zero,0x330($t6)
/*  f0b8070:	8eef0284 */ 	lw	$t7,0x284($s7)
/*  f0b8074:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0b8078:	ade0032c */ 	sw	$zero,0x32c($t7)
/*  f0b807c:	8ef80284 */ 	lw	$t8,0x284($s7)
/*  f0b8080:	af110328 */ 	sw	$s1,0x328($t8)
/*  f0b8084:	8ef90284 */ 	lw	$t9,0x284($s7)
/*  f0b8088:	0fc3089f */ 	jal	getMissionTime
/*  f0b808c:	af201960 */ 	sw	$zero,0x1960($t9)
/*  f0b8090:	8ee90284 */ 	lw	$t1,0x284($s7)
/*  f0b8094:	02202025 */ 	or	$a0,$s1,$zero
/*  f0b8098:	ad22195c */ 	sw	$v0,0x195c($t1)
/*  f0b809c:	8eea0284 */ 	lw	$t2,0x284($s7)
/*  f0b80a0:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b80a4:	ad401964 */ 	sw	$zero,0x1964($t2)
/*  f0b80a8:	44806000 */ 	mtc1	$zero,$f12
/*  f0b80ac:	0fc30884 */ 	jal	currentPlayerSetShieldFrac
/*  f0b80b0:	00000000 */ 	nop
/*  f0b80b4:	0fc41b99 */ 	jal	cheatIsActive
/*  f0b80b8:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0b80bc:	10400004 */ 	beqz	$v0,.L0f0b80d0
/*  f0b80c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b80c4:	44816000 */ 	mtc1	$at,$f12
/*  f0b80c8:	0fc30884 */ 	jal	currentPlayerSetShieldFrac
/*  f0b80cc:	00000000 */ 	nop
.L0f0b80d0:
/*  f0b80d0:	0fc41b99 */ 	jal	cheatIsActive
/*  f0b80d4:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f0b80d8:	10400008 */ 	beqz	$v0,.L0f0b80fc
/*  f0b80dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b80e0:	44816000 */ 	mtc1	$at,$f12
/*  f0b80e4:	0fc30884 */ 	jal	currentPlayerSetShieldFrac
/*  f0b80e8:	00000000 */ 	nop
/*  f0b80ec:	3c014000 */ 	lui	$at,0x4000
/*  f0b80f0:	44812000 */ 	mtc1	$at,$f4
/*  f0b80f4:	8eeb0284 */ 	lw	$t3,0x284($s7)
/*  f0b80f8:	e56419a0 */ 	swc1	$f4,0x19a0($t3)
.L0f0b80fc:
/*  f0b80fc:	8eec0314 */ 	lw	$t4,0x314($s7)
/*  f0b8100:	11800117 */ 	beqz	$t4,.L0f0b8560
/*  f0b8104:	00000000 */ 	nop
/*  f0b8108:	8eed029c */ 	lw	$t5,0x29c($s7)
/*  f0b810c:	3c10800a */ 	lui	$s0,%hi(g_DefaultWeapon)
/*  f0b8110:	2610ddd0 */ 	addiu	$s0,$s0,%lo(g_DefaultWeapon)
/*  f0b8114:	05a000f9 */ 	bltz	$t5,.L0f0b84fc
/*  f0b8118:	02202025 */ 	or	$a0,$s1,$zero
/*  f0b811c:	8eee02a8 */ 	lw	$t6,0x2a8($s7)
/*  f0b8120:	8eef0284 */ 	lw	$t7,0x284($s7)
/*  f0b8124:	00009025 */ 	or	$s2,$zero,$zero
/*  f0b8128:	15cf00f4 */ 	bne	$t6,$t7,.L0f0b84fc
/*  f0b812c:	00000000 */ 	nop
/*  f0b8130:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0b8134:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f0b8138:	2404005d */ 	addiu	$a0,$zero,0x5d
/*  f0b813c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b8140:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b8144:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b8148:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b814c:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b8150:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b8154:	8ef8000c */ 	lw	$t8,0xc($s7)
/*  f0b8158:	5b000018 */ 	blezl	$t8,.L0f0b81bc
/*  f0b815c:	8ef90284 */ 	lw	$t9,0x284($s7)
/*  f0b8160:	8ef0028c */ 	lw	$s0,0x28c($s7)
/*  f0b8164:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b8168:	8ee40294 */ 	lw	$a0,0x294($s7)
/*  f0b816c:	27b10084 */ 	addiu	$s1,$sp,0x84
/*  f0b8170:	27b3009c */ 	addiu	$s3,$sp,0x9c
/*  f0b8174:	02602825 */ 	or	$a1,$s3,$zero
/*  f0b8178:	0fc28302 */ 	jal	func0f0a0c08
/*  f0b817c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0b8180:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f0b8184:	00000000 */ 	nop
/*  f0b8188:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b818c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0b8190:	0c0056c5 */ 	jal	func00015b14
/*  f0b8194:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0b8198:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f0b819c:	00000000 */ 	nop
/*  f0b81a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b81a4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0b81a8:	0c0056da */ 	jal	func00015b68
/*  f0b81ac:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0b81b0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b81b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0b81b8:	8ef90284 */ 	lw	$t9,0x284($s7)
.L0f0b81bc:
/*  f0b81bc:	8f2900d4 */ 	lw	$t1,0xd4($t9)
/*  f0b81c0:	15200003 */ 	bnez	$t1,.L0f0b81d0
/*  f0b81c4:	00000000 */ 	nop
/*  f0b81c8:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0b81cc:	00000000 */ 	nop
.L0f0b81d0:
/*  f0b81d0:	0fc07934 */ 	jal	getNumChrs
/*  f0b81d4:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0b81d8:	1840008f */ 	blez	$v0,.L0f0b8418
/*  f0b81dc:	0015a0c0 */ 	sll	$s4,$s5,0x3
/*  f0b81e0:	0295a023 */ 	subu	$s4,$s4,$s5
/*  f0b81e4:	0014a080 */ 	sll	$s4,$s4,0x2
/*  f0b81e8:	0295a023 */ 	subu	$s4,$s4,$s5
/*  f0b81ec:	0014a080 */ 	sll	$s4,$s4,0x2
/*  f0b81f0:	0295a021 */ 	addu	$s4,$s4,$s5
/*  f0b81f4:	3c168006 */ 	lui	$s6,%hi(g_ChrsA)
/*  f0b81f8:	26d62988 */ 	addiu	$s6,$s6,%lo(g_ChrsA)
/*  f0b81fc:	0014a0c0 */ 	sll	$s4,$s4,0x3
/*  f0b8200:	27b300e8 */ 	addiu	$s3,$sp,0xe8
/*  f0b8204:	27b100c0 */ 	addiu	$s1,$sp,0xc0
/*  f0b8208:	8ec70000 */ 	lw	$a3,0x0($s6)
.L0f0b820c:
/*  f0b820c:	00f42821 */ 	addu	$a1,$a3,$s4
/*  f0b8210:	8caa0020 */ 	lw	$t2,0x20($a1)
/*  f0b8214:	5140007a */ 	beqzl	$t2,.L0f0b8400
/*  f0b8218:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b821c:	8ca3001c */ 	lw	$v1,0x1c($a1)
/*  f0b8220:	50600077 */ 	beqzl	$v1,.L0f0b8400
/*  f0b8224:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b8228:	8cab0014 */ 	lw	$t3,0x14($a1)
/*  f0b822c:	000b6240 */ 	sll	$t4,$t3,0x9
/*  f0b8230:	05830073 */ 	bgezl	$t4,.L0f0b8400
/*  f0b8234:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b8238:	8cad0018 */ 	lw	$t5,0x18($a1)
/*  f0b823c:	31ae0400 */ 	andi	$t6,$t5,0x400
/*  f0b8240:	55c0006f */ 	bnezl	$t6,.L0f0b8400
/*  f0b8244:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b8248:	906f0000 */ 	lbu	$t7,0x0($v1)
/*  f0b824c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b8250:	55e1006b */ 	bnel	$t7,$at,.L0f0b8400
/*  f0b8254:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b8258:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0b825c:	02872021 */ 	addu	$a0,$s4,$a3
/*  f0b8260:	54400067 */ 	bnezl	$v0,.L0f0b8400
/*  f0b8264:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b8268:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f0b826c:	03142821 */ 	addu	$a1,$t8,$s4
/*  f0b8270:	8ca3001c */ 	lw	$v1,0x1c($a1)
/*  f0b8274:	90790001 */ 	lbu	$t9,0x1($v1)
/*  f0b8278:	33290004 */ 	andi	$t1,$t9,0x4
/*  f0b827c:	51200060 */ 	beqzl	$t1,.L0f0b8400
/*  f0b8280:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0b8284:	8eea02a0 */ 	lw	$t2,0x2a0($s7)
/*  f0b8288:	00008025 */ 	or	$s0,$zero,$zero
/*  f0b828c:	8d4200bc */ 	lw	$v0,0xbc($t2)
/*  f0b8290:	5040000c */ 	beqzl	$v0,.L0f0b82c4
/*  f0b8294:	8eeb0284 */ 	lw	$t3,0x284($s7)
/*  f0b8298:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0b829c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b82a0:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0b82a4:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f0b82a8:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f0b82ac:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0b82b0:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0b82b4:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f0b82b8:	1000000c */ 	b	.L0f0b82ec
/*  f0b82bc:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f0b82c0:	8eeb0284 */ 	lw	$t3,0x284($s7)
.L0f0b82c4:
/*  f0b82c4:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0b82c8:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0b82cc:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f0b82d0:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f0b82d4:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0b82d8:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f0b82dc:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0b82e0:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0b82e4:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f0b82e8:	46049301 */ 	sub.s	$f12,$f18,$f4
.L0f0b82ec:
/*  f0b82ec:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0b82f0:	8eec000c */ 	lw	$t4,0xc($s7)
/*  f0b82f4:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0b82f8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0b82fc:	460c6402 */ 	mul.s	$f16,$f12,$f12
/*  f0b8300:	46105580 */ 	add.s	$f22,$f10,$f16
/*  f0b8304:	19800018 */ 	blez	$t4,.L0f0b8368
/*  f0b8308:	4600b506 */ 	mov.s	$f20,$f22
/*  f0b830c:	8cad0014 */ 	lw	$t5,0x14($a1)
/*  f0b8310:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f0b8314:	05c10014 */ 	bgez	$t6,.L0f0b8368
/*  f0b8318:	00000000 */ 	nop
/*  f0b831c:	0c006be0 */ 	jal	func0001af80
/*  f0b8320:	8ca40020 */ 	lw	$a0,0x20($a1)
/*  f0b8324:	8ecf0000 */ 	lw	$t7,0x0($s6)
/*  f0b8328:	44070000 */ 	mfc1	$a3,$f0
/*  f0b832c:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0b8330:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f0b8334:	8f06001c */ 	lw	$a2,0x1c($t8)
/*  f0b8338:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0b833c:	0fc1ace7 */ 	jal	func0f06b39c
/*  f0b8340:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0b8344:	10400008 */ 	beqz	$v0,.L0f0b8368
/*  f0b8348:	00000000 */ 	nop
/*  f0b834c:	0c004b70 */ 	jal	random
/*  f0b8350:	00000000 */ 	nop
/*  f0b8354:	30590007 */ 	andi	$t9,$v0,0x7
/*  f0b8358:	13200003 */ 	beqz	$t9,.L0f0b8368
/*  f0b835c:	3c017f1b */ 	lui	$at,%hi(var7f1ad574)
/*  f0b8360:	c432d574 */ 	lwc1	$f18,%lo(var7f1ad574)($at)
/*  f0b8364:	4612b500 */ 	add.s	$f20,$f22,$f18
.L0f0b8368:
/*  f0b8368:	1a400009 */ 	blez	$s2,.L0f0b8390
/*  f0b836c:	27a600c0 */ 	addiu	$a2,$sp,0xc0
.L0f0b8370:
/*  f0b8370:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0b8374:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0b8378:	00000000 */ 	nop
/*  f0b837c:	45030005 */ 	bc1tl	.L0f0b8394
/*  f0b8380:	2a01000a */ 	slti	$at,$s0,0xa
/*  f0b8384:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0b8388:	1612fff9 */ 	bne	$s0,$s2,.L0f0b8370
/*  f0b838c:	24c60004 */ 	addiu	$a2,$a2,0x4
.L0f0b8390:
/*  f0b8390:	2a01000a */ 	slti	$at,$s0,0xa
.L0f0b8394:
/*  f0b8394:	10200019 */ 	beqz	$at,.L0f0b83fc
/*  f0b8398:	02402825 */ 	or	$a1,$s2,$zero
/*  f0b839c:	00104080 */ 	sll	$t0,$s0,0x2
/*  f0b83a0:	0212082a */ 	slt	$at,$s0,$s2
/*  f0b83a4:	02283021 */ 	addu	$a2,$s1,$t0
/*  f0b83a8:	1020000d */ 	beqz	$at,.L0f0b83e0
/*  f0b83ac:	8ec70000 */ 	lw	$a3,0x0($s6)
/*  f0b83b0:	28a1000a */ 	slti	$at,$a1,0xa
.L0f0b83b4:
/*  f0b83b4:	10200007 */ 	beqz	$at,.L0f0b83d4
/*  f0b83b8:	00051080 */ 	sll	$v0,$a1,0x2
/*  f0b83bc:	02621821 */ 	addu	$v1,$s3,$v0
/*  f0b83c0:	02222021 */ 	addu	$a0,$s1,$v0
/*  f0b83c4:	8c69fffc */ 	lw	$t1,-0x4($v1)
/*  f0b83c8:	c486fffc */ 	lwc1	$f6,-0x4($a0)
/*  f0b83cc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0b83d0:	e4860000 */ 	swc1	$f6,0x0($a0)
.L0f0b83d4:
/*  f0b83d4:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f0b83d8:	5605fff6 */ 	bnel	$s0,$a1,.L0f0b83b4
/*  f0b83dc:	28a1000a */ 	slti	$at,$a1,0xa
.L0f0b83e0:
/*  f0b83e0:	02875021 */ 	addu	$t2,$s4,$a3
/*  f0b83e4:	02685821 */ 	addu	$t3,$s3,$t0
/*  f0b83e8:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f0b83ec:	2a410009 */ 	slti	$at,$s2,0x9
/*  f0b83f0:	10200002 */ 	beqz	$at,.L0f0b83fc
/*  f0b83f4:	e4d40000 */ 	swc1	$f20,0x0($a2)
/*  f0b83f8:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0b83fc:
/*  f0b83fc:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f0b8400:
/*  f0b8400:	0fc07934 */ 	jal	getNumChrs
/*  f0b8404:	26940368 */ 	addiu	$s4,$s4,0x368
/*  f0b8408:	02a2082a */ 	slt	$at,$s5,$v0
/*  f0b840c:	5420ff7f */ 	bnezl	$at,.L0f0b820c
/*  f0b8410:	8ec70000 */ 	lw	$a3,0x0($s6)
/*  f0b8414:	0000a825 */ 	or	$s5,$zero,$zero
.L0f0b8418:
/*  f0b8418:	2a410002 */ 	slti	$at,$s2,0x2
/*  f0b841c:	1420000d */ 	bnez	$at,.L0f0b8454
/*  f0b8420:	27b300e8 */ 	addiu	$s3,$sp,0xe8
/*  f0b8424:	0c004b70 */ 	jal	random
/*  f0b8428:	00000000 */ 	nop
/*  f0b842c:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f0b8430:	15800008 */ 	bnez	$t4,.L0f0b8454
/*  f0b8434:	8fa200e8 */ 	lw	$v0,0xe8($sp)
/*  f0b8438:	c7b400c0 */ 	lwc1	$f20,0xc0($sp)
/*  f0b843c:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0b8440:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f0b8444:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0b8448:	e7b400c4 */ 	swc1	$f20,0xc4($sp)
/*  f0b844c:	afad00e8 */ 	sw	$t5,0xe8($sp)
/*  f0b8450:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
.L0f0b8454:
/*  f0b8454:	2a410003 */ 	slti	$at,$s2,0x3
/*  f0b8458:	1420000d */ 	bnez	$at,.L0f0b8490
/*  f0b845c:	00000000 */ 	nop
/*  f0b8460:	0c004b70 */ 	jal	random
/*  f0b8464:	00000000 */ 	nop
/*  f0b8468:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f0b846c:	15c00008 */ 	bnez	$t6,.L0f0b8490
/*  f0b8470:	8fa200e8 */ 	lw	$v0,0xe8($sp)
/*  f0b8474:	c7b400c0 */ 	lwc1	$f20,0xc0($sp)
/*  f0b8478:	8faf00f0 */ 	lw	$t7,0xf0($sp)
/*  f0b847c:	c7aa00c8 */ 	lwc1	$f10,0xc8($sp)
/*  f0b8480:	afa200f0 */ 	sw	$v0,0xf0($sp)
/*  f0b8484:	e7b400c8 */ 	swc1	$f20,0xc8($sp)
/*  f0b8488:	afaf00e8 */ 	sw	$t7,0xe8($sp)
/*  f0b848c:	e7aa00c0 */ 	swc1	$f10,0xc0($sp)
.L0f0b8490:
/*  f0b8490:	1a40000f */ 	blez	$s2,.L0f0b84d0
.L0f0b8494:
/*  f0b8494:	0015c080 */ 	sll	$t8,$s5,0x2
/*  f0b8498:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f0b849c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0b84a0:	0fc2df18 */ 	jal	func0f0b7c60
/*  f0b84a4:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0b84a8:	14400009 */ 	bnez	$v0,.L0f0b84d0
/*  f0b84ac:	26a20001 */ 	addiu	$v0,$s5,0x1
/*  f0b84b0:	56420005 */ 	bnel	$s2,$v0,.L0f0b84c8
/*  f0b84b4:	0052082a */ 	slt	$at,$v0,$s2
/*  f0b84b8:	17c00005 */ 	bnez	$s8,.L0f0b84d0
/*  f0b84bc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0b84c0:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f0b84c4:	0052082a */ 	slt	$at,$v0,$s2
.L0f0b84c8:
/*  f0b84c8:	1420fff2 */ 	bnez	$at,.L0f0b8494
/*  f0b84cc:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0b84d0:
/*  f0b84d0:	8ee90284 */ 	lw	$t1,0x284($s7)
/*  f0b84d4:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0b84d8:	8d420004 */ 	lw	$v0,0x4($t2)
/*  f0b84dc:	10400020 */ 	beqz	$v0,.L0f0b8560
/*  f0b84e0:	00000000 */ 	nop
/*  f0b84e4:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f0b84e8:	8eeb0284 */ 	lw	$t3,0x284($s7)
/*  f0b84ec:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0b84f0:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f0b84f4:	1000001a */ 	b	.L0f0b8560
/*  f0b84f8:	a1a002ff */ 	sb	$zero,0x2ff($t5)
.L0f0b84fc:
/*  f0b84fc:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b8500:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0b8504:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b8508:	0fc28824 */ 	jal	currentPlayerEquipWeaponWrapper
/*  f0b850c:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f0b8510:	8eee0284 */ 	lw	$t6,0x284($s7)
/*  f0b8514:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f0b8518:	8dcf00d4 */ 	lw	$t7,0xd4($t6)
/*  f0b851c:	15e00010 */ 	bnez	$t7,.L0f0b8560
/*  f0b8520:	00000000 */ 	nop
/*  f0b8524:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f0b8528:	1638000b */ 	bne	$s1,$t8,.L0f0b8558
/*  f0b852c:	00000000 */ 	nop
/*  f0b8530:	92f904e0 */ 	lbu	$t9,0x4e0($s7)
/*  f0b8534:	17200008 */ 	bnez	$t9,.L0f0b8558
/*  f0b8538:	00000000 */ 	nop
/*  f0b853c:	8ee9028c */ 	lw	$t1,0x28c($s7)
/*  f0b8540:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayerChrs)
/*  f0b8544:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0b8548:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0b854c:	8d6bc4d0 */ 	lw	$t3,%lo(g_MpPlayerChrs)($t3)
/*  f0b8550:	15600003 */ 	bnez	$t3,.L0f0b8560
/*  f0b8554:	00000000 */ 	nop
.L0f0b8558:
/*  f0b8558:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0b855c:	00000000 */ 	nop
.L0f0b8560:
/*  f0b8560:	0fc307fd */ 	jal	func0f0c1ff4
/*  f0b8564:	00000000 */ 	nop
/*  f0b8568:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0b856c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0b8570:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f0b8574:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0b8578:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0b857c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0b8580:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0b8584:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0b8588:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0b858c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0b8590:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0b8594:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0b8598:	03e00008 */ 	jr	$ra
/*  f0b859c:	27bd0120 */ 	addiu	$sp,$sp,0x120
);

void func0f0b85a0(f32 *floats, struct coord *pos)
{
	floats[4] = pos->x;
	floats[5] = pos->y;
	floats[6] = pos->z;
	floats[7] = 1;
	floats[8] = 0;
	floats[9] = 0;
	floats[10] = 0;
	floats[11] = 1;
	floats[12] = 0;

	floats[0] = 0;
	floats[1] = 0;
	floats[2] = 1;
	floats[3] = 30;
}

GLOBAL_ASM(
glabel func0f0b85f8
/*  f0b85f8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0b85fc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0b8600:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b8604:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b8608:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0b860c:	8e0e028c */ 	lw	$t6,0x28c($s0)
/*  f0b8610:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0b8614:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0b8618:	00008825 */ 	or	$s1,$zero,$zero
/*  f0b861c:	11e00003 */ 	beqz	$t7,.L0f0b862c
/*  f0b8620:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0b8624:	10000002 */ 	b	.L0f0b8630
/*  f0b8628:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b862c:
/*  f0b862c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b8630:
/*  f0b8630:	8e180068 */ 	lw	$t8,0x68($s0)
/*  f0b8634:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b8638:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b863c:	13000003 */ 	beqz	$t8,.L0f0b864c
/*  f0b8640:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b8644:	10000001 */ 	b	.L0f0b864c
/*  f0b8648:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b864c:
/*  f0b864c:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f0b8650:	13200003 */ 	beqz	$t9,.L0f0b8660
/*  f0b8654:	00000000 */ 	nop
/*  f0b8658:	10000001 */ 	b	.L0f0b8660
/*  f0b865c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b8660:
/*  f0b8660:	8e080070 */ 	lw	$t0,0x70($s0)
/*  f0b8664:	11000003 */ 	beqz	$t0,.L0f0b8674
/*  f0b8668:	00000000 */ 	nop
/*  f0b866c:	10000001 */ 	b	.L0f0b8674
/*  f0b8670:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b8674:
/*  f0b8674:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0b8678:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0b867c:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0b8680:	19600023 */ 	blez	$t3,.L0f0b8710
/*  f0b8684:	00000000 */ 	nop
.L0f0b8688:
/*  f0b8688:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b868c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0b8690:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0b8694:	00000000 */ 	nop
/*  f0b8698:	8e0c006c */ 	lw	$t4,0x6c($s0)
/*  f0b869c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0b86a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b86a4:	11800003 */ 	beqz	$t4,.L0f0b86b4
/*  f0b86a8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b86ac:	10000001 */ 	b	.L0f0b86b4
/*  f0b86b0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b86b4:
/*  f0b86b4:	8e0d0068 */ 	lw	$t5,0x68($s0)
/*  f0b86b8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b86bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b86c0:	11a00003 */ 	beqz	$t5,.L0f0b86d0
/*  f0b86c4:	00000000 */ 	nop
/*  f0b86c8:	10000001 */ 	b	.L0f0b86d0
/*  f0b86cc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b86d0:
/*  f0b86d0:	8e0e0064 */ 	lw	$t6,0x64($s0)
/*  f0b86d4:	11c00003 */ 	beqz	$t6,.L0f0b86e4
/*  f0b86d8:	00000000 */ 	nop
/*  f0b86dc:	10000001 */ 	b	.L0f0b86e4
/*  f0b86e0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b86e4:
/*  f0b86e4:	8e0f0070 */ 	lw	$t7,0x70($s0)
/*  f0b86e8:	11e00003 */ 	beqz	$t7,.L0f0b86f8
/*  f0b86ec:	00000000 */ 	nop
/*  f0b86f0:	10000001 */ 	b	.L0f0b86f8
/*  f0b86f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b86f8:
/*  f0b86f8:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0b86fc:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0b8700:	03254021 */ 	addu	$t0,$t9,$a1
/*  f0b8704:	0228082a */ 	slt	$at,$s1,$t0
/*  f0b8708:	1420ffdf */ 	bnez	$at,.L0f0b8688
/*  f0b870c:	00000000 */ 	nop
.L0f0b8710:
/*  f0b8710:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b8714:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f0b8718:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0b871c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0b8720:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0b8724:	03e00008 */ 	jr	$ra
/*  f0b8728:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0b872c
.late_rodata
glabel var7f1ad578
.word func0f0b872c+0x24c # f0b8978
glabel var7f1ad57c
.word func0f0b872c+0x270 # f0b899c
glabel var7f1ad580
.word func0f0b872c+0x294 # f0b89c0
glabel var7f1ad584
.word func0f0b872c+0x2b8 # f0b89e4
glabel var7f1ad588
.word func0f0b872c+0x2dc # f0b8a08
glabel var7f1ad58c
.word func0f0b872c+0x300 # f0b8a2c
glabel var7f1ad590
.word func0f0b872c+0x324 # f0b8a50
glabel var7f1ad594
.word func0f0b872c+0x348 # f0b8a74
glabel var7f1ad598
.word func0f0b872c+0x36c # f0b8a98
glabel var7f1ad59c
.word func0f0b872c+0x390 # f0b8abc
glabel var7f1ad5a0
.word func0f0b872c+0x3b4 # f0b8ae0
glabel var7f1ad5a4
.word func0f0b872c+0x3d8 # f0b8b04
glabel var7f1ad5a8
.word func0f0b872c+0x420 # f0b8b4c
glabel var7f1ad5ac
.word func0f0b872c+0x444 # f0b8b70
glabel var7f1ad5b0
.word func0f0b872c+0x3fc # f0b8b28
.text
/*  f0b872c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b8730:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b8734:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f0b8738:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b873c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b8740:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0b8744:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f0b8748:	05c00010 */ 	bltz	$t6,.L0f0b878c
/*  f0b874c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f0b8750:	8c6f02a8 */ 	lw	$t7,0x2a8($v1)
/*  f0b8754:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f0b8758:	55f8000d */ 	bnel	$t7,$t8,.L0f0b8790
/*  f0b875c:	8c6b0318 */ 	lw	$t3,0x318($v1)
/*  f0b8760:	8c620440 */ 	lw	$v0,0x440($v1)
/*  f0b8764:	0442000a */ 	bltzl	$v0,.L0f0b8790
/*  f0b8768:	8c6b0318 */ 	lw	$t3,0x318($v1)
/*  f0b876c:	8c790444 */ 	lw	$t9,0x444($v1)
/*  f0b8770:	07220007 */ 	bltzl	$t9,.L0f0b8790
/*  f0b8774:	8c6b0318 */ 	lw	$t3,0x318($v1)
/*  f0b8778:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f0b877c:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f0b8780:	8c690444 */ 	lw	$t1,0x444($v1)
/*  f0b8784:	10000102 */ 	b	.L0f0b8b90
/*  f0b8788:	ad490000 */ 	sw	$t1,0x0($t2)
.L0f0b878c:
/*  f0b878c:	8c6b0318 */ 	lw	$t3,0x318($v1)
.L0f0b8790:
/*  f0b8790:	51600038 */ 	beqzl	$t3,.L0f0b8874
/*  f0b8794:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f0b8798:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0b879c:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0b87a0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b87a4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b87a8:	8c6c0288 */ 	lw	$t4,0x288($v1)
/*  f0b87ac:	3c04800b */ 	lui	$a0,%hi(g_MpPlayers+0xf)
/*  f0b87b0:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0b87b4:	8d8d0070 */ 	lw	$t5,0x70($t4)
/*  f0b87b8:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0b87bc:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0b87c0:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f0b87c4:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f0b87c8:	9084c7c7 */ 	lbu	$a0,%lo(g_MpPlayers+0xf)($a0)
/*  f0b87cc:	0082082a */ 	slt	$at,$a0,$v0
/*  f0b87d0:	10200008 */ 	beqz	$at,.L0f0b87f4
/*  f0b87d4:	00000000 */ 	nop
/*  f0b87d8:	0fc62ecb */ 	jal	mpGetHeadId
/*  f0b87dc:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0b87e0:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0b87e4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b87e8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b87ec:	10000014 */ 	b	.L0f0b8840
/*  f0b87f0:	ace20000 */ 	sw	$v0,0x0($a3)
.L0f0b87f4:
/*  f0b87f4:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0b87f8:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0b87fc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b8800:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b8804:	8c6f0288 */ 	lw	$t7,0x288($v1)
/*  f0b8808:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers+0xf)
/*  f0b880c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0b8810:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f0b8814:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0b8818:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0b881c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0b8820:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0b8824:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0b8828:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0b882c:	9129c7c7 */ 	lbu	$t1,%lo(g_MpPlayers+0xf)($t1)
/*  f0b8830:	01225023 */ 	subu	$t2,$t1,$v0
/*  f0b8834:	10800002 */ 	beqz	$a0,.L0f0b8840
/*  f0b8838:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f0b883c:	ac8b0000 */ 	sw	$t3,0x0($a0)
.L0f0b8840:
/*  f0b8840:	8c6c0288 */ 	lw	$t4,0x288($v1)
/*  f0b8844:	3c04800b */ 	lui	$a0,%hi(g_MpPlayers+0x10)
/*  f0b8848:	8d8d0070 */ 	lw	$t5,0x70($t4)
/*  f0b884c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0b8850:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0b8854:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f0b8858:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f0b885c:	0fc62ee4 */ 	jal	mpGetBodyId
/*  f0b8860:	9084c7c8 */ 	lbu	$a0,%lo(g_MpPlayers+0x10)($a0)
/*  f0b8864:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0b8868:	100000c9 */ 	b	.L0f0b8b90
/*  f0b886c:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f0b8870:	8c620298 */ 	lw	$v0,0x298($v1)
.L0f0b8874:
/*  f0b8874:	8c640284 */ 	lw	$a0,0x284($v1)
/*  f0b8878:	284f0000 */ 	slti	$t7,$v0,0x0
/*  f0b887c:	39ef0001 */ 	xori	$t7,$t7,0x1
/*  f0b8880:	2de20001 */ 	sltiu	$v0,$t7,0x1
/*  f0b8884:	14400004 */ 	bnez	$v0,.L0f0b8898
/*  f0b8888:	8c880324 */ 	lw	$t0,0x324($a0)
/*  f0b888c:	8c7802a4 */ 	lw	$t8,0x2a4($v1)
/*  f0b8890:	03041026 */ 	xor	$v0,$t8,$a0
/*  f0b8894:	0002102b */ 	sltu	$v0,$zero,$v0
.L0f0b8898:
/*  f0b8898:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f0b889c:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0b88a0:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0b88a4:	0fc41b99 */ 	jal	cheatIsActive
/*  f0b88a8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0b88ac:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b88b0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b88b4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0b88b8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0b88bc:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0b88c0:	10400006 */ 	beqz	$v0,.L0f0b88dc
/*  f0b88c4:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f0b88c8:	24190067 */ 	addiu	$t9,$zero,0x67
/*  f0b88cc:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f0b88d0:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f0b88d4:	100000ae */ 	b	.L0f0b8b90
/*  f0b88d8:	ace90000 */ 	sw	$t1,0x0($a3)
.L0f0b88dc:
/*  f0b88dc:	8c6a04b4 */ 	lw	$t2,0x4b4($v1)
/*  f0b88e0:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f0b88e4:	5541000f */ 	bnel	$t2,$at,.L0f0b8924
/*  f0b88e8:	8c6b0284 */ 	lw	$t3,0x284($v1)
/*  f0b88ec:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f0b88f0:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0b88f4:	0fc5b367 */ 	jal	getDifficulty
/*  f0b88f8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0b88fc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b8900:	28410002 */ 	slti	$at,$v0,0x2
/*  f0b8904:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b8908:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0b890c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0b8910:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0b8914:	14200002 */ 	bnez	$at,.L0f0b8920
/*  f0b8918:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f0b891c:	2408000e */ 	addiu	$t0,$zero,0xe
.L0f0b8920:
/*  f0b8920:	8c6b0284 */ 	lw	$t3,0x284($v1)
.L0f0b8924:
/*  f0b8924:	8d6c1c50 */ 	lw	$t4,0x1c50($t3)
/*  f0b8928:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f0b892c:	05c3000b */ 	bgezl	$t6,.L0f0b895c
/*  f0b8930:	2d01000f */ 	sltiu	$at,$t0,0xf
/*  f0b8934:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f0b8938:	24010027 */ 	addiu	$at,$zero,0x27
/*  f0b893c:	10410005 */ 	beq	$v0,$at,.L0f0b8954
/*  f0b8940:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0b8944:	54410005 */ 	bnel	$v0,$at,.L0f0b895c
/*  f0b8948:	2d01000f */ 	sltiu	$at,$t0,0xf
/*  f0b894c:	10000002 */ 	b	.L0f0b8958
/*  f0b8950:	2408000a */ 	addiu	$t0,$zero,0xa
.L0f0b8954:
/*  f0b8954:	2408000b */ 	addiu	$t0,$zero,0xb
.L0f0b8958:
/*  f0b8958:	2d01000f */ 	sltiu	$at,$t0,0xf
.L0f0b895c:
/*  f0b895c:	10200006 */ 	beqz	$at,.L0f0b8978
/*  f0b8960:	00087880 */ 	sll	$t7,$t0,0x2
/*  f0b8964:	3c017f1b */ 	lui	$at,%hi(var7f1ad578)
/*  f0b8968:	002f0821 */ 	addu	$at,$at,$t7
/*  f0b896c:	8c2fd578 */ 	lw	$t7,%lo(var7f1ad578)($at)
/*  f0b8970:	01e00008 */ 	jr	$t7
/*  f0b8974:	00000000 */ 	nop
.L0f0b8978:
/*  f0b8978:	24180056 */ 	addiu	$t8,$zero,0x56
/*  f0b897c:	10a00004 */ 	beqz	$a1,.L0f0b8990
/*  f0b8980:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0b8984:	24190004 */ 	addiu	$t9,$zero,0x4
/*  f0b8988:	10000081 */ 	b	.L0f0b8b90
/*  f0b898c:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0b8990:
/*  f0b8990:	2409003e */ 	addiu	$t1,$zero,0x3e
/*  f0b8994:	1000007e */ 	b	.L0f0b8b90
/*  f0b8998:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f0b899c:	240a0067 */ 	addiu	$t2,$zero,0x67
/*  f0b89a0:	10a00004 */ 	beqz	$a1,.L0f0b89b4
/*  f0b89a4:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f0b89a8:	240b0005 */ 	addiu	$t3,$zero,0x5
/*  f0b89ac:	10000078 */ 	b	.L0f0b8b90
/*  f0b89b0:	aceb0000 */ 	sw	$t3,0x0($a3)
.L0f0b89b4:
/*  f0b89b4:	240c0005 */ 	addiu	$t4,$zero,0x5
/*  f0b89b8:	10000075 */ 	b	.L0f0b8b90
/*  f0b89bc:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f0b89c0:	240d005d */ 	addiu	$t5,$zero,0x5d
/*  f0b89c4:	10a00004 */ 	beqz	$a1,.L0f0b89d8
/*  f0b89c8:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f0b89cc:	240e0009 */ 	addiu	$t6,$zero,0x9
/*  f0b89d0:	1000006f */ 	b	.L0f0b8b90
/*  f0b89d4:	acee0000 */ 	sw	$t6,0x0($a3)
.L0f0b89d8:
/*  f0b89d8:	240f0009 */ 	addiu	$t7,$zero,0x9
/*  f0b89dc:	1000006c */ 	b	.L0f0b8b90
/*  f0b89e0:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f0b89e4:	24180062 */ 	addiu	$t8,$zero,0x62
/*  f0b89e8:	10a00004 */ 	beqz	$a1,.L0f0b89fc
/*  f0b89ec:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0b89f0:	24190004 */ 	addiu	$t9,$zero,0x4
/*  f0b89f4:	10000066 */ 	b	.L0f0b8b90
/*  f0b89f8:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0b89fc:
/*  f0b89fc:	2409003e */ 	addiu	$t1,$zero,0x3e
/*  f0b8a00:	10000063 */ 	b	.L0f0b8b90
/*  f0b8a04:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f0b8a08:	240a006d */ 	addiu	$t2,$zero,0x6d
/*  f0b8a0c:	10a00004 */ 	beqz	$a1,.L0f0b8a20
/*  f0b8a10:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f0b8a14:	240b000c */ 	addiu	$t3,$zero,0xc
/*  f0b8a18:	1000005d */ 	b	.L0f0b8b90
/*  f0b8a1c:	aceb0000 */ 	sw	$t3,0x0($a3)
.L0f0b8a20:
/*  f0b8a20:	240c003e */ 	addiu	$t4,$zero,0x3e
/*  f0b8a24:	1000005a */ 	b	.L0f0b8b90
/*  f0b8a28:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f0b8a2c:	240d0061 */ 	addiu	$t5,$zero,0x61
/*  f0b8a30:	10a00004 */ 	beqz	$a1,.L0f0b8a44
/*  f0b8a34:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f0b8a38:	240e000c */ 	addiu	$t6,$zero,0xc
/*  f0b8a3c:	10000054 */ 	b	.L0f0b8b90
/*  f0b8a40:	acee0000 */ 	sw	$t6,0x0($a3)
.L0f0b8a44:
/*  f0b8a44:	240f003e */ 	addiu	$t7,$zero,0x3e
/*  f0b8a48:	10000051 */ 	b	.L0f0b8b90
/*  f0b8a4c:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f0b8a50:	24180095 */ 	addiu	$t8,$zero,0x95
/*  f0b8a54:	10a00004 */ 	beqz	$a1,.L0f0b8a68
/*  f0b8a58:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0b8a5c:	24190004 */ 	addiu	$t9,$zero,0x4
/*  f0b8a60:	1000004b */ 	b	.L0f0b8b90
/*  f0b8a64:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0b8a68:
/*  f0b8a68:	2409003e */ 	addiu	$t1,$zero,0x3e
/*  f0b8a6c:	10000048 */ 	b	.L0f0b8b90
/*  f0b8a70:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f0b8a74:	240a0087 */ 	addiu	$t2,$zero,0x87
/*  f0b8a78:	10a00004 */ 	beqz	$a1,.L0f0b8a8c
/*  f0b8a7c:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f0b8a80:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f0b8a84:	10000042 */ 	b	.L0f0b8b90
/*  f0b8a88:	aceb0000 */ 	sw	$t3,0x0($a3)
.L0f0b8a8c:
/*  f0b8a8c:	240c003e */ 	addiu	$t4,$zero,0x3e
/*  f0b8a90:	1000003f */ 	b	.L0f0b8b90
/*  f0b8a94:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f0b8a98:	240d0088 */ 	addiu	$t5,$zero,0x88
/*  f0b8a9c:	10a00004 */ 	beqz	$a1,.L0f0b8ab0
/*  f0b8aa0:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f0b8aa4:	240e002f */ 	addiu	$t6,$zero,0x2f
/*  f0b8aa8:	10000039 */ 	b	.L0f0b8b90
/*  f0b8aac:	acee0000 */ 	sw	$t6,0x0($a3)
.L0f0b8ab0:
/*  f0b8ab0:	240f003e */ 	addiu	$t7,$zero,0x3e
/*  f0b8ab4:	10000036 */ 	b	.L0f0b8b90
/*  f0b8ab8:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f0b8abc:	24180089 */ 	addiu	$t8,$zero,0x89
/*  f0b8ac0:	10a00004 */ 	beqz	$a1,.L0f0b8ad4
/*  f0b8ac4:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0b8ac8:	2419003c */ 	addiu	$t9,$zero,0x3c
/*  f0b8acc:	10000030 */ 	b	.L0f0b8b90
/*  f0b8ad0:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0b8ad4:
/*  f0b8ad4:	2409003e */ 	addiu	$t1,$zero,0x3e
/*  f0b8ad8:	1000002d */ 	b	.L0f0b8b90
/*  f0b8adc:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f0b8ae0:	240a008a */ 	addiu	$t2,$zero,0x8a
/*  f0b8ae4:	10a00004 */ 	beqz	$a1,.L0f0b8af8
/*  f0b8ae8:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f0b8aec:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f0b8af0:	10000027 */ 	b	.L0f0b8b90
/*  f0b8af4:	aceb0000 */ 	sw	$t3,0x0($a3)
.L0f0b8af8:
/*  f0b8af8:	240c003e */ 	addiu	$t4,$zero,0x3e
/*  f0b8afc:	10000024 */ 	b	.L0f0b8b90
/*  f0b8b00:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f0b8b04:	240d0086 */ 	addiu	$t5,$zero,0x86
/*  f0b8b08:	10a00004 */ 	beqz	$a1,.L0f0b8b1c
/*  f0b8b0c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f0b8b10:	240e000c */ 	addiu	$t6,$zero,0xc
/*  f0b8b14:	1000001e */ 	b	.L0f0b8b90
/*  f0b8b18:	acee0000 */ 	sw	$t6,0x0($a3)
.L0f0b8b1c:
/*  f0b8b1c:	240f003e */ 	addiu	$t7,$zero,0x3e
/*  f0b8b20:	1000001b */ 	b	.L0f0b8b90
/*  f0b8b24:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f0b8b28:	24180096 */ 	addiu	$t8,$zero,0x96
/*  f0b8b2c:	10a00004 */ 	beqz	$a1,.L0f0b8b40
/*  f0b8b30:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0b8b34:	2419000c */ 	addiu	$t9,$zero,0xc
/*  f0b8b38:	10000015 */ 	b	.L0f0b8b90
/*  f0b8b3c:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0b8b40:
/*  f0b8b40:	2409003e */ 	addiu	$t1,$zero,0x3e
/*  f0b8b44:	10000012 */ 	b	.L0f0b8b90
/*  f0b8b48:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f0b8b4c:	240a005b */ 	addiu	$t2,$zero,0x5b
/*  f0b8b50:	10a00004 */ 	beqz	$a1,.L0f0b8b64
/*  f0b8b54:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f0b8b58:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0b8b5c:	1000000c */ 	b	.L0f0b8b90
/*  f0b8b60:	aceb0000 */ 	sw	$t3,0x0($a3)
.L0f0b8b64:
/*  f0b8b64:	240c0008 */ 	addiu	$t4,$zero,0x8
/*  f0b8b68:	10000009 */ 	b	.L0f0b8b90
/*  f0b8b6c:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f0b8b70:	240d0057 */ 	addiu	$t5,$zero,0x57
/*  f0b8b74:	10a00004 */ 	beqz	$a1,.L0f0b8b88
/*  f0b8b78:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f0b8b7c:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f0b8b80:	10000003 */ 	b	.L0f0b8b90
/*  f0b8b84:	acee0000 */ 	sw	$t6,0x0($a3)
.L0f0b8b88:
/*  f0b8b88:	240f0029 */ 	addiu	$t7,$zero,0x29
/*  f0b8b8c:	acef0000 */ 	sw	$t7,0x0($a3)
.L0f0b8b90:
/*  f0b8b90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b8b94:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b8b98:	03e00008 */ 	jr	$ra
/*  f0b8b9c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0b8ba0
.late_rodata
glabel var7f1ad5b4
.word 0x40c907a9
.text
/*  f0b8ba0:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0b8ba4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0b8ba8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b8bac:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b8bb0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b8bb4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b8bb8:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0b8bbc:	44810000 */ 	mtc1	$at,$f0
/*  f0b8bc0:	c4640144 */ 	lwc1	$f4,0x144($v1)
/*  f0b8bc4:	3c017f1b */ 	lui	$at,%hi(var7f1ad5b4)
/*  f0b8bc8:	c428d5b4 */ 	lwc1	$f8,%lo(var7f1ad5b4)($at)
/*  f0b8bcc:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0b8bd0:	3c188007 */ 	lui	$t8,%hi(var8007078c)
/*  f0b8bd4:	2718078c */ 	addiu	$t8,$t8,%lo(var8007078c)
/*  f0b8bd8:	27090060 */ 	addiu	$t1,$t8,0x60
/*  f0b8bdc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0b8be0:	27af0074 */ 	addiu	$t7,$sp,0x74
/*  f0b8be4:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0b8be8:	e7b00114 */ 	swc1	$f16,0x114($sp)
/*  f0b8bec:	8c6e19c8 */ 	lw	$t6,0x19c8($v1)
/*  f0b8bf0:	55c00236 */ 	bnezl	$t6,.L0f0b94cc
/*  f0b8bf4:	8c6a00bc */ 	lw	$t2,0xbc($v1)
/*  f0b8bf8:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0b8bfc:	afa000f0 */ 	sw	$zero,0xf0($sp)
.L0f0b8c00:
/*  f0b8c00:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b8c04:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0b8c08:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0b8c0c:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f0b8c10:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f0b8c14:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f0b8c18:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f0b8c1c:	1709fff8 */ 	bne	$t8,$t1,.L0f0b8c00
/*  f0b8c20:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f0b8c24:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b8c28:	8f090004 */ 	lw	$t1,0x4($t8)
/*  f0b8c2c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b8c30:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0b8c34:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b8c38:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0b8c3c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b8c40:	240a0056 */ 	addiu	$t2,$zero,0x56
/*  f0b8c44:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f0b8c48:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0b8c4c:	afaa0068 */ 	sw	$t2,0x68($sp)
/*  f0b8c50:	afab0064 */ 	sw	$t3,0x64($sp)
/*  f0b8c54:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0b8c58:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f0b8c5c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0b8c60:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0b8c64:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0b8c68:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0b8c6c:	0fc2e1cb */ 	jal	func0f0b872c
/*  f0b8c70:	adac19c8 */ 	sw	$t4,0x19c8($t5)
/*  f0b8c74:	8e0e02ac */ 	lw	$t6,0x2ac($s0)
/*  f0b8c78:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b8c7c:	3c08800a */ 	lui	$t0,%hi(g_DefaultWeapon)
/*  f0b8c80:	15c10003 */ 	bne	$t6,$at,.L0f0b8c90
/*  f0b8c84:	00000000 */ 	nop
/*  f0b8c88:	8d08ddd0 */ 	lw	$t0,%lo(g_DefaultWeapon)($t0)
/*  f0b8c8c:	afa8006c */ 	sw	$t0,0x6c($sp)
.L0f0b8c90:
/*  f0b8c90:	0fc4a2bd */ 	jal	weaponGetModel
/*  f0b8c94:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f0b8c98:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f0b8c9c:	90630af0 */ 	lbu	$v1,%lo(g_Is4Mb)($v1)
/*  f0b8ca0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b8ca4:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0b8ca8:	14c30004 */ 	bne	$a2,$v1,.L0f0b8cbc
/*  f0b8cac:	24190056 */ 	addiu	$t9,$zero,0x56
/*  f0b8cb0:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0b8cb4:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0b8cb8:	afa90064 */ 	sw	$t1,0x64($sp)
.L0f0b8cbc:
/*  f0b8cbc:	8e180314 */ 	lw	$t8,0x314($s0)
/*  f0b8cc0:	53000020 */ 	beqzl	$t8,.L0f0b8d44
/*  f0b8cc4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b8cc8:	14c300e0 */ 	bne	$a2,$v1,.L0f0b904c
/*  f0b8ccc:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f0b8cd0:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0b8cd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b8cd8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b8cdc:	11e00003 */ 	beqz	$t7,.L0f0b8cec
/*  f0b8ce0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b8ce4:	10000001 */ 	b	.L0f0b8cec
/*  f0b8ce8:	00c02825 */ 	or	$a1,$a2,$zero
.L0f0b8cec:
/*  f0b8cec:	8e0a0068 */ 	lw	$t2,0x68($s0)
/*  f0b8cf0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b8cf4:	11400003 */ 	beqz	$t2,.L0f0b8d04
/*  f0b8cf8:	00000000 */ 	nop
/*  f0b8cfc:	10000001 */ 	b	.L0f0b8d04
/*  f0b8d00:	00c01825 */ 	or	$v1,$a2,$zero
.L0f0b8d04:
/*  f0b8d04:	8e0b0064 */ 	lw	$t3,0x64($s0)
/*  f0b8d08:	11600003 */ 	beqz	$t3,.L0f0b8d18
/*  f0b8d0c:	00000000 */ 	nop
/*  f0b8d10:	10000001 */ 	b	.L0f0b8d18
/*  f0b8d14:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0b8d18:
/*  f0b8d18:	8e0c0070 */ 	lw	$t4,0x70($s0)
/*  f0b8d1c:	11800003 */ 	beqz	$t4,.L0f0b8d2c
/*  f0b8d20:	00000000 */ 	nop
/*  f0b8d24:	10000001 */ 	b	.L0f0b8d2c
/*  f0b8d28:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0b8d2c:
/*  f0b8d2c:	00446821 */ 	addu	$t5,$v0,$a0
/*  f0b8d30:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f0b8d34:	01c54021 */ 	addu	$t0,$t6,$a1
/*  f0b8d38:	54c800c5 */ 	bnel	$a2,$t0,.L0f0b9050
/*  f0b8d3c:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0b8d40:	8e190284 */ 	lw	$t9,0x284($s0)
.L0f0b8d44:
/*  f0b8d44:	3c05800a */ 	lui	$a1,%hi(var8009dfc0)
/*  f0b8d48:	24a5dfc0 */ 	addiu	$a1,$a1,%lo(var8009dfc0)
/*  f0b8d4c:	8f291bd4 */ 	lw	$t1,0x1bd4($t9)
/*  f0b8d50:	55200017 */ 	bnezl	$t1,.L0f0b8db0
/*  f0b8d54:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0b8d58:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0b8d5c:	5700000d */ 	bnezl	$t8,.L0f0b8d94
/*  f0b8d60:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b8d64:	0fc27801 */ 	jal	func0f09e004
/*  f0b8d68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0b8d6c:	3c05800a */ 	lui	$a1,%hi(var8009dfc0)
/*  f0b8d70:	24a5dfc0 */ 	addiu	$a1,$a1,%lo(var8009dfc0)
/*  f0b8d74:	10400006 */ 	beqz	$v0,.L0f0b8d90
/*  f0b8d78:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b8d7c:	0fc2777b */ 	jal	func0f09ddec
/*  f0b8d80:	00000000 */ 	nop
/*  f0b8d84:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b8d88:	10000008 */ 	b	.L0f0b8dac
/*  f0b8d8c:	ade21bd4 */ 	sw	$v0,0x1bd4($t7)
.L0f0b8d90:
/*  f0b8d90:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b8d94:
/*  f0b8d94:	ac6019c8 */ 	sw	$zero,0x19c8($v1)
/*  f0b8d98:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f0b8d9c:	554001e2 */ 	bnezl	$t2,.L0f0b9528
/*  f0b8da0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b8da4:	100001df */ 	b	.L0f0b9524
/*  f0b8da8:	ae060320 */ 	sw	$a2,0x320($s0)
.L0f0b8dac:
/*  f0b8dac:	240b0008 */ 	addiu	$t3,$zero,0x8
.L0f0b8db0:
/*  f0b8db0:	3c018008 */ 	lui	$at,%hi(var8007fc0c)
/*  f0b8db4:	0fc2777b */ 	jal	func0f09ddec
/*  f0b8db8:	a42bfc0c */ 	sh	$t3,%lo(var8007fc0c)($at)
/*  f0b8dbc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b8dc0:	24030040 */ 	addiu	$v1,$zero,0x40
/*  f0b8dc4:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b8dc8:	8d851bd4 */ 	lw	$a1,0x1bd4($t4)
/*  f0b8dcc:	00a36821 */ 	addu	$t5,$a1,$v1
/*  f0b8dd0:	246300cb */ 	addiu	$v1,$v1,0xcb
/*  f0b8dd4:	346e003f */ 	ori	$t6,$v1,0x3f
/*  f0b8dd8:	acad0020 */ 	sw	$t5,0x20($a1)
/*  f0b8ddc:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0b8de0:	39c8003f */ 	xori	$t0,$t6,0x3f
/*  f0b8de4:	2503043f */ 	addiu	$v1,$t0,0x43f
/*  f0b8de8:	3469003f */ 	ori	$t1,$v1,0x3f
/*  f0b8dec:	3938003f */ 	xori	$t8,$t1,0x3f
/*  f0b8df0:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b8df4:	270300a7 */ 	addiu	$v1,$t8,0xa7
/*  f0b8df8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b8dfc:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f0b8e00:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b8e04:	394b003f */ 	xori	$t3,$t2,0x3f
/*  f0b8e08:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b8e0c:	00a8c821 */ 	addu	$t9,$a1,$t0
/*  f0b8e10:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f0b8e14:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0b8e18:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f0b8e1c:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b8e20:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0b8e24:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0b8e28:	0fc59c15 */ 	jal	func0f167054
/*  f0b8e2c:	afa500ec */ 	sw	$a1,0xec($sp)
/*  f0b8e30:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*  f0b8e34:	244e003f */ 	addiu	$t6,$v0,0x3f
/*  f0b8e38:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f0b8e3c:	35c8003f */ 	ori	$t0,$t6,0x3f
/*  f0b8e40:	3919003f */ 	xori	$t9,$t0,0x3f
/*  f0b8e44:	0329c021 */ 	addu	$t8,$t9,$t1
/*  f0b8e48:	05e0000e */ 	bltz	$t7,.L0f0b8e84
/*  f0b8e4c:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f0b8e50:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f0b8e54:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f0b8e58:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b8e5c:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b8e60:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0b8e64:	0fc59c15 */ 	jal	func0f167054
/*  f0b8e68:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b8e6c:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b8e70:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0b8e74:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0b8e78:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0b8e7c:	016e4021 */ 	addu	$t0,$t3,$t6
/*  f0b8e80:	afa800e4 */ 	sw	$t0,0xe4($sp)
.L0f0b8e84:
/*  f0b8e84:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0b8e88:	0720000b */ 	bltz	$t9,.L0f0b8eb8
/*  f0b8e8c:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f0b8e90:	3c048008 */ 	lui	$a0,%hi(g_Props+0x4)
/*  f0b8e94:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0b8e98:	0fc59c15 */ 	jal	func0f167054
/*  f0b8e9c:	9484b070 */ 	lhu	$a0,%lo(g_Props+0x4)($a0)
/*  f0b8ea0:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0b8ea4:	244f003f */ 	addiu	$t7,$v0,0x3f
/*  f0b8ea8:	35ea003f */ 	ori	$t2,$t7,0x3f
/*  f0b8eac:	394c003f */ 	xori	$t4,$t2,0x3f
/*  f0b8eb0:	030c6821 */ 	addu	$t5,$t8,$t4
/*  f0b8eb4:	afad00e4 */ 	sw	$t5,0xe4($sp)
.L0f0b8eb8:
/*  f0b8eb8:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b8ebc:	256e4000 */ 	addiu	$t6,$t3,0x4000
/*  f0b8ec0:	0fc2777f */ 	jal	func0f09ddfc
/*  f0b8ec4:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0b8ec8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b8ecc:	8fa900e4 */ 	lw	$t1,0xe4($sp)
/*  f0b8ed0:	8d191bd4 */ 	lw	$t9,0x1bd4($t0)
/*  f0b8ed4:	03297821 */ 	addu	$t7,$t9,$t1
/*  f0b8ed8:	0fc2777f */ 	jal	func0f09ddfc
/*  f0b8edc:	afaf00e8 */ 	sw	$t7,0xe8($sp)
/*  f0b8ee0:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f0b8ee4:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b8ee8:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0b8eec:	0fc5cb9c */ 	jal	func0f172e70
/*  f0b8ef0:	004a3023 */ 	subu	$a2,$v0,$t2
/*  f0b8ef4:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0b8ef8:	8fa200f0 */ 	lw	$v0,0xf0($sp)
/*  f0b8efc:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0b8f00:	00186080 */ 	sll	$t4,$t8,0x2
/*  f0b8f04:	01986021 */ 	addu	$t4,$t4,$t8
/*  f0b8f08:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b8f0c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b8f10:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b8f14:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0b8f18:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b8f1c:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b8f20:	01a22821 */ 	addu	$a1,$t5,$v0
/*  f0b8f24:	0fc69de5 */ 	jal	func0f1a7794
/*  f0b8f28:	01623023 */ 	subu	$a2,$t3,$v0
/*  f0b8f2c:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0b8f30:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b8f34:	afa200fc */ 	sw	$v0,0xfc($sp)
/*  f0b8f38:	000e4080 */ 	sll	$t0,$t6,0x2
/*  f0b8f3c:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f0b8f40:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0b8f44:	00882021 */ 	addu	$a0,$a0,$t0
/*  f0b8f48:	0fc59ca0 */ 	jal	fileGetSize
/*  f0b8f4c:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b8f50:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f0b8f54:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b8f58:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b8f5c:	00594821 */ 	addu	$t1,$v0,$t9
/*  f0b8f60:	252f003f */ 	addiu	$t7,$t1,0x3f
/*  f0b8f64:	35ea003f */ 	ori	$t2,$t7,0x3f
/*  f0b8f68:	3958003f */ 	xori	$t8,$t2,0x3f
/*  f0b8f6c:	0580001b */ 	bltz	$t4,.L0f0b8fdc
/*  f0b8f70:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f0b8f74:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b8f78:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b8f7c:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f0b8f80:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f0b8f84:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b8f88:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b8f8c:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b8f90:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b8f94:	01782821 */ 	addu	$a1,$t3,$t8
/*  f0b8f98:	0fc69de5 */ 	jal	func0f1a7794
/*  f0b8f9c:	01183023 */ 	subu	$a2,$t0,$t8
/*  f0b8fa0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0b8fa4:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b8fa8:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0b8fac:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0b8fb0:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0b8fb4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0b8fb8:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0b8fbc:	0fc59ca0 */ 	jal	fileGetSize
/*  f0b8fc0:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b8fc4:	8faf00f0 */ 	lw	$t7,0xf0($sp)
/*  f0b8fc8:	004f5021 */ 	addu	$t2,$v0,$t7
/*  f0b8fcc:	254c003f */ 	addiu	$t4,$t2,0x3f
/*  f0b8fd0:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0b8fd4:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0b8fd8:	afab00f0 */ 	sw	$t3,0xf0($sp)
.L0f0b8fdc:
/*  f0b8fdc:	0c008b49 */ 	jal	func00022d24
/*  f0b8fe0:	8fa400fc */ 	lw	$a0,0xfc($sp)
/*  f0b8fe4:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f0b8fe8:	51c00004 */ 	beqzl	$t6,.L0f0b8ffc
/*  f0b8fec:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0b8ff0:	0c008b49 */ 	jal	func00022d24
/*  f0b8ff4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0b8ff8:	8fa4005c */ 	lw	$a0,0x5c($sp)
.L0f0b8ffc:
/*  f0b8ffc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f0b9000:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0b9004:	0c008be9 */ 	jal	func00022fa4
/*  f0b9008:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b900c:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0b9010:	0c008c28 */ 	jal	animInitialise
/*  f0b9014:	8d040020 */ 	lw	$a0,0x20($t0)
/*  f0b9018:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0b901c:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0b9020:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b9024:	0fc5cbd5 */ 	jal	func0f172f54
/*  f0b9028:	a7380002 */ 	sh	$t8,0x2($t9)
/*  f0b902c:	0fc2777b */ 	jal	func0f09ddec
/*  f0b9030:	00000000 */ 	nop
/*  f0b9034:	0fc2777f */ 	jal	func0f09ddfc
/*  f0b9038:	00000000 */ 	nop
/*  f0b903c:	0fc5cbd5 */ 	jal	func0f172f54
/*  f0b9040:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b9044:	1000005d */ 	b	.L0f0b91bc
/*  f0b9048:	8fae005c */ 	lw	$t6,0x5c($sp)
.L0f0b904c:
/*  f0b904c:	00097880 */ 	sll	$t7,$t1,0x2
.L0f0b9050:
/*  f0b9050:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f0b9054:	3c0a8008 */ 	lui	$t2,%hi(g_Bodies)
/*  f0b9058:	254acf04 */ 	addiu	$t2,$t2,%lo(g_Bodies)
/*  f0b905c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b9060:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0b9064:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f0b9068:	5480000e */ 	bnezl	$a0,.L0f0b90a4
/*  f0b906c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0b9070:	0fc69e11 */ 	jal	fileLoad
/*  f0b9074:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f0b9078:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0b907c:	3c0b8008 */ 	lui	$t3,%hi(g_Bodies)
/*  f0b9080:	256bcf04 */ 	addiu	$t3,$t3,%lo(g_Bodies)
/*  f0b9084:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b9088:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b908c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b9090:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b9094:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b9098:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b909c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b90a0:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f0b90a4:
/*  f0b90a4:	afa400fc */ 	sw	$a0,0xfc($sp)
/*  f0b90a8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0b90ac:	000ec040 */ 	sll	$t8,$t6,0x1
/*  f0b90b0:	07010003 */ 	bgez	$t8,.L0f0b90c0
/*  f0b90b4:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0b90b8:	1000003f */ 	b	.L0f0b91b8
/*  f0b90bc:	afb90064 */ 	sw	$t9,0x64($sp)
.L0f0b90c0:
/*  f0b90c0:	11200005 */ 	beqz	$t1,.L0f0b90d8
/*  f0b90c4:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0b90c8:	0fc6395f */ 	jal	func0f18e57c
/*  f0b90cc:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0b90d0:	10000039 */ 	b	.L0f0b91b8
/*  f0b90d4:	afa200f8 */ 	sw	$v0,0xf8($sp)
.L0f0b90d8:
/*  f0b90d8:	8e0f0318 */ 	lw	$t7,0x318($s0)
/*  f0b90dc:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0b90e0:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f0b90e4:	51e00020 */ 	beqzl	$t7,.L0f0b9168
/*  f0b90e8:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0b90ec:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0b90f0:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b90f4:	3c048008 */ 	lui	$a0,%hi(g_Bodies+0x2)
/*  f0b90f8:	10ca001a */ 	beq	$a2,$t2,.L0f0b9164
/*  f0b90fc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b9100:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b9104:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b9108:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b910c:	0fc69e11 */ 	jal	fileLoad
/*  f0b9110:	9484cf06 */ 	lhu	$a0,%lo(g_Bodies+0x2)($a0)
/*  f0b9114:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0b9118:	3c088008 */ 	lui	$t0,%hi(g_Bodies)
/*  f0b911c:	2508cf04 */ 	addiu	$t0,$t0,%lo(g_Bodies)
/*  f0b9120:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0b9124:	01cb7021 */ 	addu	$t6,$t6,$t3
/*  f0b9128:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0b912c:	01c81821 */ 	addu	$v1,$t6,$t0
/*  f0b9130:	94780002 */ 	lhu	$t8,0x2($v1)
/*  f0b9134:	3c01800a */ 	lui	$at,%hi(g_FileInfo)
/*  f0b9138:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b913c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0b9140:	00390821 */ 	addu	$at,$at,$t9
/*  f0b9144:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0b9148:	ac206680 */ 	sw	$zero,%lo(g_FileInfo)($at)
/*  f0b914c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b9150:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0b9154:	0fc0b76f */ 	jal	func0f02ddbc
/*  f0b9158:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f0b915c:	10000017 */ 	b	.L0f0b91bc
/*  f0b9160:	8fae005c */ 	lw	$t6,0x5c($sp)
.L0f0b9164:
/*  f0b9164:	00097880 */ 	sll	$t7,$t1,0x2
.L0f0b9168:
/*  f0b9168:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f0b916c:	3c0a8008 */ 	lui	$t2,%hi(g_Bodies)
/*  f0b9170:	254acf04 */ 	addiu	$t2,$t2,%lo(g_Bodies)
/*  f0b9174:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b9178:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0b917c:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f0b9180:	5480000d */ 	bnezl	$a0,.L0f0b91b8
/*  f0b9184:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f0b9188:	0fc69e11 */ 	jal	fileLoad
/*  f0b918c:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f0b9190:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b9194:	3c0b8008 */ 	lui	$t3,%hi(g_Bodies)
/*  f0b9198:	256bcf04 */ 	addiu	$t3,$t3,%lo(g_Bodies)
/*  f0b919c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b91a0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b91a4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b91a8:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b91ac:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b91b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b91b4:	afa400f8 */ 	sw	$a0,0xf8($sp)
.L0f0b91b8:
/*  f0b91b8:	8fae005c */ 	lw	$t6,0x5c($sp)
.L0f0b91bc:
/*  f0b91bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b91c0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0b91c4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0b91c8:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0b91cc:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f0b91d0:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0b91d4:	8fa600fc */ 	lw	$a2,0xfc($sp)
/*  f0b91d8:	8fa700f8 */ 	lw	$a3,0xf8($sp)
/*  f0b91dc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0b91e0:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f0b91e4:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0b91e8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b91ec:	af2200d4 */ 	sw	$v0,0xd4($t9)
/*  f0b91f0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b91f4:	c7b20114 */ 	lwc1	$f18,0x114($sp)
/*  f0b91f8:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0b91fc:	8c6500d4 */ 	lw	$a1,0xd4($v1)
/*  f0b9200:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0b9204:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0b9208:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f0b920c:	0fc082c5 */ 	jal	func0f020b14
/*  f0b9210:	24870028 */ 	addiu	$a3,$a0,0x28
/*  f0b9214:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b9218:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f0b921c:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f0b9220:	a1490000 */ 	sb	$t1,0x0($t2)
/*  f0b9224:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b9228:	8e0b0314 */ 	lw	$t3,0x314($s0)
/*  f0b922c:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f0b9230:	11600011 */ 	beqz	$t3,.L0f0b9278
/*  f0b9234:	8da60004 */ 	lw	$a2,0x4($t5)
/*  f0b9238:	8e02028c */ 	lw	$v0,0x28c($s0)
/*  f0b923c:	3c01800b */ 	lui	$at,%hi(g_MpPlayerChrs)
/*  f0b9240:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f0b9244:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0b9248:	002e0821 */ 	addu	$at,$at,$t6
/*  f0b924c:	ac26c4d0 */ 	sw	$a2,%lo(g_MpPlayerChrs)($at)
/*  f0b9250:	8e080288 */ 	lw	$t0,0x288($s0)
/*  f0b9254:	3c01800b */ 	lui	$at,%hi(var800ac500)
/*  f0b9258:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f0b925c:	8d180070 */ 	lw	$t8,0x70($t0)
/*  f0b9260:	002e0821 */ 	addu	$at,$at,$t6
/*  f0b9264:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0b9268:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0b926c:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0b9270:	032f4821 */ 	addu	$t1,$t9,$t7
/*  f0b9274:	ac29c500 */ 	sw	$t1,%lo(var800ac500)($at)
.L0f0b9278:
/*  f0b9278:	8cca0018 */ 	lw	$t2,0x18($a2)
/*  f0b927c:	354c0001 */ 	ori	$t4,$t2,0x1
/*  f0b9280:	accc0018 */ 	sw	$t4,0x18($a2)
/*  f0b9284:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9288:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0b928c:	8c6400d4 */ 	lw	$a0,0xd4($v1)
/*  f0b9290:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f0b9294:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0b9298:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b929c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b92a0:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0b92a4:	8dab00bc */ 	lw	$t3,0xbc($t5)
/*  f0b92a8:	0fc0f94e */ 	jal	func0f03e538
/*  f0b92ac:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f0b92b0:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f0b92b4:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0b92b8:	a04e0006 */ 	sb	$t6,0x6($v0)
/*  f0b92bc:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f0b92c0:	a4480010 */ 	sh	$t0,0x10($v0)
/*  f0b92c4:	0fc0b378 */ 	jal	bodyGetRace
/*  f0b92c8:	84440010 */ 	lh	$a0,0x10($v0)
/*  f0b92cc:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f0b92d0:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f0b92d4:	3c048008 */ 	lui	$a0,%hi(g_Bodies)
/*  f0b92d8:	a30202fe */ 	sb	$v0,0x2fe($t8)
/*  f0b92dc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b92e0:	2484cf04 */ 	addiu	$a0,$a0,%lo(g_Bodies)
/*  f0b92e4:	c7240378 */ 	lwc1	$f4,0x378($t9)
/*  f0b92e8:	e7040024 */ 	swc1	$f4,0x24($t8)
/*  f0b92ec:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0b92f0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b92f4:	01e50019 */ 	multu	$t7,$a1
/*  f0b92f8:	00004812 */ 	mflo	$t1
/*  f0b92fc:	00895021 */ 	addu	$t2,$a0,$t1
/*  f0b9300:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*  f0b9304:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0b9308:	000d5e02 */ 	srl	$t3,$t5,0x18
/*  f0b930c:	448b3000 */ 	mtc1	$t3,$f6
/*  f0b9310:	00000000 */ 	nop
/*  f0b9314:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0b9318:	e5c819c4 */ 	swc1	$f8,0x19c4($t6)
/*  f0b931c:	8e08029c */ 	lw	$t0,0x29c($s0)
/*  f0b9320:	0502000e */ 	bltzl	$t0,.L0f0b935c
/*  f0b9324:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9328:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b932c:	8e1902a8 */ 	lw	$t9,0x2a8($s0)
/*  f0b9330:	3c01431f */ 	lui	$at,0x431f
/*  f0b9334:	57230009 */ 	bnel	$t9,$v1,.L0f0b935c
/*  f0b9338:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b933c:	44810000 */ 	mtc1	$at,$f0
/*  f0b9340:	c46a19c4 */ 	lwc1	$f10,0x19c4($v1)
/*  f0b9344:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0b9348:	00000000 */ 	nop
/*  f0b934c:	45020003 */ 	bc1fl	.L0f0b935c
/*  f0b9350:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9354:	e46019c4 */ 	swc1	$f0,0x19c4($v1)
/*  f0b9358:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b935c:
/*  f0b935c:	c47019c4 */ 	lwc1	$f16,0x19c4($v1)
/*  f0b9360:	e47019c0 */ 	swc1	$f16,0x19c0($v1)
/*  f0b9364:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0b9368:	07020010 */ 	bltzl	$t8,.L0f0b93ac
/*  f0b936c:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9370:	03050019 */ 	multu	$t8,$a1
/*  f0b9374:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9378:	c47219c0 */ 	lwc1	$f18,0x19c0($v1)
/*  f0b937c:	00007812 */ 	mflo	$t7
/*  f0b9380:	008f4821 */ 	addu	$t1,$a0,$t7
/*  f0b9384:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f0b9388:	000a6180 */ 	sll	$t4,$t2,0x6
/*  f0b938c:	000c6e02 */ 	srl	$t5,$t4,0x18
/*  f0b9390:	448d2000 */ 	mtc1	$t5,$f4
/*  f0b9394:	00000000 */ 	nop
/*  f0b9398:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0b939c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f0b93a0:	10000007 */ 	b	.L0f0b93c0
/*  f0b93a4:	e46819c0 */ 	swc1	$f8,0x19c0($v1)
/*  f0b93a8:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b93ac:
/*  f0b93ac:	3c014150 */ 	lui	$at,0x4150
/*  f0b93b0:	44818000 */ 	mtc1	$at,$f16
/*  f0b93b4:	c46a19c0 */ 	lwc1	$f10,0x19c0($v1)
/*  f0b93b8:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f0b93bc:	e46419c0 */ 	swc1	$f4,0x19c0($v1)
.L0f0b93c0:
/*  f0b93c0:	8c8b00a0 */ 	lw	$t3,0xa0($a0)
/*  f0b93c4:	8c99071c */ 	lw	$t9,0x71c($a0)
/*  f0b93c8:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b93cc:	000b7180 */ 	sll	$t6,$t3,0x6
/*  f0b93d0:	0019c180 */ 	sll	$t8,$t9,0x6
/*  f0b93d4:	00187e02 */ 	srl	$t7,$t8,0x18
/*  f0b93d8:	000e4602 */ 	srl	$t0,$t6,0x18
/*  f0b93dc:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0b93e0:	44899000 */ 	mtc1	$t1,$f18
/*  f0b93e4:	c46619c0 */ 	lwc1	$f6,0x19c0($v1)
/*  f0b93e8:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0b93ec:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0b93f0:	00000000 */ 	nop
/*  f0b93f4:	45020004 */ 	bc1fl	.L0f0b9408
/*  f0b93f8:	c46819c4 */ 	lwc1	$f8,0x19c4($v1)
/*  f0b93fc:	e46019c0 */ 	swc1	$f0,0x19c0($v1)
/*  f0b9400:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9404:	c46819c4 */ 	lwc1	$f8,0x19c4($v1)
.L0f0b9408:
/*  f0b9408:	e46819bc */ 	swc1	$f8,0x19bc($v1)
/*  f0b940c:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0b9410:	05400023 */ 	bltz	$t2,.L0f0b94a0
/*  f0b9414:	00000000 */ 	nop
/*  f0b9418:	8e0c0314 */ 	lw	$t4,0x314($s0)
/*  f0b941c:	3c0b8008 */ 	lui	$t3,%hi(g_Props)
/*  f0b9420:	256bb06c */ 	addiu	$t3,$t3,%lo(g_Props)
/*  f0b9424:	15800013 */ 	bnez	$t4,.L0f0b9474
/*  f0b9428:	000a68c0 */ 	sll	$t5,$t2,0x3
/*  f0b942c:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f0b9430:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0b9434:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0b9438:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b943c:	94640004 */ 	lhu	$a0,0x4($v1)
/*  f0b9440:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f0b9444:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b9448:	01d92821 */ 	addu	$a1,$t6,$t9
/*  f0b944c:	0fc69de5 */ 	jal	func0f1a7794
/*  f0b9450:	03193023 */ 	subu	$a2,$t8,$t9
/*  f0b9454:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0b9458:	afa200f4 */ 	sw	$v0,0xf4($sp)
/*  f0b945c:	0fc59ca0 */ 	jal	fileGetSize
/*  f0b9460:	94640004 */ 	lhu	$a0,0x4($v1)
/*  f0b9464:	0c008b49 */ 	jal	func00022d24
/*  f0b9468:	8fa400f4 */ 	lw	$a0,0xf4($sp)
/*  f0b946c:	10000004 */ 	b	.L0f0b9480
/*  f0b9470:	8faf00dc */ 	lw	$t7,0xdc($sp)
.L0f0b9474:
/*  f0b9474:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f0b9478:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f0b947c:	8faf00dc */ 	lw	$t7,0xdc($sp)
.L0f0b9480:
/*  f0b9480:	8fa900f4 */ 	lw	$t1,0xf4($sp)
/*  f0b9484:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0b9488:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0b948c:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0b9490:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b9494:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0b9498:	0fc22e3a */ 	jal	func0f08b8e8
/*  f0b949c:	afa90014 */ 	sw	$t1,0x14($sp)
.L0f0b94a0:
/*  f0b94a0:	0fc29c3e */ 	jal	func0f0a70f8
/*  f0b94a4:	00000000 */ 	nop
/*  f0b94a8:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0b94ac:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0b94b0:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f0b94b4:	a082017c */ 	sb	$v0,0x17c($a0)
/*  f0b94b8:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f0b94bc:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0b94c0:	10000019 */ 	b	.L0f0b9528
/*  f0b94c4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b94c8:	8c6a00bc */ 	lw	$t2,0xbc($v1)
.L0f0b94cc:
/*  f0b94cc:	8d440004 */ 	lw	$a0,0x4($t2)
/*  f0b94d0:	8c8d0020 */ 	lw	$t5,0x20($a0)
/*  f0b94d4:	8dab0020 */ 	lw	$t3,0x20($t5)
/*  f0b94d8:	55600013 */ 	bnezl	$t3,.L0f0b9528
/*  f0b94dc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b94e0:	8c8e0018 */ 	lw	$t6,0x18($a0)
/*  f0b94e4:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0b94e8:	35d90001 */ 	ori	$t9,$t6,0x1
/*  f0b94ec:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f0b94f0:	ac990018 */ 	sw	$t9,0x18($a0)
/*  f0b94f4:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b94f8:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0b94fc:	8c6400d4 */ 	lw	$a0,0xd4($v1)
/*  f0b9500:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0b9504:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b9508:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b950c:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0b9510:	8f0800bc */ 	lw	$t0,0xbc($t8)
/*  f0b9514:	0fc0f94e */ 	jal	func0f03e538
/*  f0b9518:	8d040004 */ 	lw	$a0,0x4($t0)
/*  f0b951c:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f0b9520:	8e040284 */ 	lw	$a0,0x284($s0)
.L0f0b9524:
/*  f0b9524:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b9528:
/*  f0b9528:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0b952c:	27bd0118 */ 	addiu	$sp,$sp,0x118
/*  f0b9530:	03e00008 */ 	jr	$ra
/*  f0b9534:	00000000 */ 	nop
);

void func0f0b9538(void)
{
	if (g_Vars.currentplayer->haschrbody) {
		if (!g_Vars.mplayerisrunning || (IS4MB() && PLAYERCOUNT() == 1)) {
			g_Vars.currentplayer->haschrbody = false;
			func0f020d44(g_Vars.currentplayer->prop, false);
			g_Vars.currentplayer->unk00d4 = 0;
			func0f0cb8c4(g_Vars.currentplayer);
			func0f09df50();
			g_Vars.currentplayer->unk1bd4 = 0;
		}
	}
}

void setTickMode(s32 tickmode)
{
	g_Vars.tickmode = tickmode;
	g_Vars.in_cutscene = false;
}

void func0f0b9650(void)
{
	setTickMode(TICKMODE_0);
	var80070744 = 0;
}

void func0f0b9674(void)
{
	setTickMode(TICKMODE_4);
	var80070744 = 0;
	currentPlayerSetMoveMode(MOVEMODE_WALK);
	var8009ddd8 = 0;
	var8009dddc = -90;
	var8009dde0 = 0;
	var8009dde4 = 80;

	func0f165eec(mainGetStageNum(), 0);
}

GLOBAL_ASM(
glabel func0f0b96e8
.late_rodata
glabel var7f1ad5b8
.word 0x3c75c28f
glabel var7f1ad5bc
.word 0x43338000
glabel var7f1ad5c0
.word 0x3dcccccd
glabel var7f1ad5c4
.word 0x40490fdb
glabel var7f1ad5c8
.word 0x3da3d70a
.text
/*  f0b96e8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0b96ec:	3c0f8007 */ 	lui	$t7,%hi(var800707f4)
/*  f0b96f0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0b96f4:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f0b96f8:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f0b96fc:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f0b9700:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f0b9704:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0b9708:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0b970c:	25ef07f4 */ 	addiu	$t7,$t7,%lo(var800707f4)
/*  f0b9710:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0b9714:	27ae0080 */ 	addiu	$t6,$sp,0x80
/*  f0b9718:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0b971c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0b9720:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0b9724:	3c0b8007 */ 	lui	$t3,%hi(var80070800)
/*  f0b9728:	256b0800 */ 	addiu	$t3,$t3,%lo(var80070800)
/*  f0b972c:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0b9730:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0b9734:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0b9738:	27aa0074 */ 	addiu	$t2,$sp,0x74
/*  f0b973c:	8d790004 */ 	lw	$t9,0x4($t3)
/*  f0b9740:	ad410000 */ 	sw	$at,0x0($t2)
/*  f0b9744:	8d610008 */ 	lw	$at,0x8($t3)
/*  f0b9748:	3c0e8007 */ 	lui	$t6,%hi(var8007080c)
/*  f0b974c:	25ce080c */ 	addiu	$t6,$t6,%lo(var8007080c)
/*  f0b9750:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0b9754:	ad410008 */ 	sw	$at,0x8($t2)
/*  f0b9758:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0b975c:	27b80068 */ 	addiu	$t8,$sp,0x68
/*  f0b9760:	8dcd0004 */ 	lw	$t5,0x4($t6)
/*  f0b9764:	af010000 */ 	sw	$at,0x0($t8)
/*  f0b9768:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0b976c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b9770:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f0b9774:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0b9778:	af010008 */ 	sw	$at,0x8($t8)
/*  f0b977c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b9780:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b9784:	8d0c0290 */ 	lw	$t4,0x290($t0)
/*  f0b9788:	55800057 */ 	bnezl	$t4,.L0f0b98e8
/*  f0b978c:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0b9790:	8d070038 */ 	lw	$a3,0x38($t0)
/*  f0b9794:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b9798:	3c01800a */ 	lui	$at,%hi(var8009dddc)
/*  f0b979c:	18e00051 */ 	blez	$a3,.L0f0b98e4
/*  f0b97a0:	3c06800a */ 	lui	$a2,%hi(var8009dddc)
/*  f0b97a4:	c42cdddc */ 	lwc1	$f12,%lo(var8009dddc)($at)
/*  f0b97a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad5b8)
/*  f0b97ac:	c43ed5b8 */ 	lwc1	$f30,%lo(var7f1ad5b8)($at)
/*  f0b97b0:	3c014270 */ 	lui	$at,0x4270
/*  f0b97b4:	4481e000 */ 	mtc1	$at,$f28
/*  f0b97b8:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0b97bc:	4481d000 */ 	mtc1	$at,$f26
/*  f0b97c0:	3c014334 */ 	lui	$at,0x4334
/*  f0b97c4:	4481c000 */ 	mtc1	$at,$f24
/*  f0b97c8:	3c0142dc */ 	lui	$at,0x42dc
/*  f0b97cc:	4481b000 */ 	mtc1	$at,$f22
/*  f0b97d0:	3c01c1a0 */ 	lui	$at,0xc1a0
/*  f0b97d4:	4481a000 */ 	mtc1	$at,$f20
/*  f0b97d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b97dc:	44819000 */ 	mtc1	$at,$f18
/*  f0b97e0:	3c017f1b */ 	lui	$at,%hi(var7f1ad5bc)
/*  f0b97e4:	c430d5bc */ 	lwc1	$f16,%lo(var7f1ad5bc)($at)
/*  f0b97e8:	3c017f1b */ 	lui	$at,%hi(var7f1ad5c0)
/*  f0b97ec:	3c05800a */ 	lui	$a1,%hi(var8009ddd8)
/*  f0b97f0:	3c04800a */ 	lui	$a0,%hi(var8009dde0)
/*  f0b97f4:	3c02800a */ 	lui	$v0,%hi(var8009dde4)
/*  f0b97f8:	2442dde4 */ 	addiu	$v0,$v0,%lo(var8009dde4)
/*  f0b97fc:	2484dde0 */ 	addiu	$a0,$a0,%lo(var8009dde0)
/*  f0b9800:	24a5ddd8 */ 	addiu	$a1,$a1,%lo(var8009ddd8)
/*  f0b9804:	c42ed5c0 */ 	lwc1	$f14,%lo(var7f1ad5c0)($at)
/*  f0b9808:	24c6dddc */ 	addiu	$a2,$a2,%lo(var8009dddc)
/*  f0b980c:	4610603c */ 	c.lt.s	$f12,$f16
.L0f0b9810:
/*  f0b9810:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0b9814:	0067082a */ 	slt	$at,$v1,$a3
/*  f0b9818:	45020013 */ 	bc1fl	.L0f0b9868
/*  f0b981c:	460c803e */ 	c.le.s	$f16,$f12
/*  f0b9820:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0b9824:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0b9828:	45020005 */ 	bc1fl	.L0f0b9840
/*  f0b982c:	460cb03c */ 	c.lt.s	$f22,$f12
/*  f0b9830:	460e0100 */ 	add.s	$f4,$f0,$f14
/*  f0b9834:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f0b9838:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0b983c:	460cb03c */ 	c.lt.s	$f22,$f12
.L0f0b9840:
/*  f0b9840:	00000000 */ 	nop
/*  f0b9844:	45020005 */ 	bc1fl	.L0f0b985c
/*  f0b9848:	46006200 */ 	add.s	$f8,$f12,$f0
/*  f0b984c:	460e0181 */ 	sub.s	$f6,$f0,$f14
/*  f0b9850:	e4a60000 */ 	swc1	$f6,0x0($a1)
/*  f0b9854:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0b9858:	46006200 */ 	add.s	$f8,$f12,$f0
.L0f0b985c:
/*  f0b985c:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f0b9860:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f0b9864:	460c803e */ 	c.le.s	$f16,$f12
.L0f0b9868:
/*  f0b9868:	00000000 */ 	nop
/*  f0b986c:	45020004 */ 	bc1fl	.L0f0b9880
/*  f0b9870:	460cd03c */ 	c.lt.s	$f26,$f12
/*  f0b9874:	e4d80000 */ 	swc1	$f24,0x0($a2)
/*  f0b9878:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f0b987c:	460cd03c */ 	c.lt.s	$f26,$f12
.L0f0b9880:
/*  f0b9880:	00000000 */ 	nop
/*  f0b9884:	45000015 */ 	bc1f	.L0f0b98dc
/*  f0b9888:	00000000 */ 	nop
/*  f0b988c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f0b9890:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f0b9894:	4602e03c */ 	c.lt.s	$f28,$f2
/*  f0b9898:	00000000 */ 	nop
/*  f0b989c:	45020005 */ 	bc1fl	.L0f0b98b4
/*  f0b98a0:	461e0100 */ 	add.s	$f4,$f0,$f30
/*  f0b98a4:	460e0281 */ 	sub.s	$f10,$f0,$f14
/*  f0b98a8:	10000003 */ 	b	.L0f0b98b8
/*  f0b98ac:	e48a0000 */ 	swc1	$f10,0x0($a0)
/*  f0b98b0:	461e0100 */ 	add.s	$f4,$f0,$f30
.L0f0b98b4:
/*  f0b98b4:	e4840000 */ 	swc1	$f4,0x0($a0)
.L0f0b98b8:
/*  f0b98b8:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f0b98bc:	46061200 */ 	add.s	$f8,$f2,$f6
/*  f0b98c0:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f0b98c4:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0b98c8:	4612503c */ 	c.lt.s	$f10,$f18
/*  f0b98cc:	00000000 */ 	nop
/*  f0b98d0:	45000002 */ 	bc1f	.L0f0b98dc
/*  f0b98d4:	00000000 */ 	nop
/*  f0b98d8:	e4520000 */ 	swc1	$f18,0x0($v0)
.L0f0b98dc:
/*  f0b98dc:	5420ffcc */ 	bnezl	$at,.L0f0b9810
/*  f0b98e0:	4610603c */ 	c.lt.s	$f12,$f16
.L0f0b98e4:
/*  f0b98e4:	8d0a0284 */ 	lw	$t2,0x284($t0)
.L0f0b98e8:
/*  f0b98e8:	3c06800a */ 	lui	$a2,%hi(var8009dddc)
/*  f0b98ec:	24c6dddc */ 	addiu	$a2,$a2,%lo(var8009dddc)
/*  f0b98f0:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0b98f4:	c5460144 */ 	lwc1	$f6,0x144($t2)
/*  f0b98f8:	3c014334 */ 	lui	$at,0x4334
/*  f0b98fc:	4481c000 */ 	mtc1	$at,$f24
/*  f0b9900:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0b9904:	3c017f1b */ 	lui	$at,%hi(var7f1ad5c4)
/*  f0b9908:	c42ad5c4 */ 	lwc1	$f10,%lo(var7f1ad5c4)($at)
/*  f0b990c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0b9910:	46182503 */ 	div.s	$f20,$f4,$f24
/*  f0b9914:	0c0068f7 */ 	jal	sinf
/*  f0b9918:	4600a306 */ 	mov.s	$f12,$f20
/*  f0b991c:	3c02800a */ 	lui	$v0,%hi(var8009dde4)
/*  f0b9920:	2442dde4 */ 	addiu	$v0,$v0,%lo(var8009dde4)
/*  f0b9924:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f0b9928:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f0b992c:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f0b9930:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f0b9934:	3c017f1b */ 	lui	$at,%hi(var7f1ad5c8)
/*  f0b9938:	c468037c */ 	lwc1	$f8,0x37c($v1)
/*  f0b993c:	4600a306 */ 	mov.s	$f12,$f20
/*  f0b9940:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0b9944:	c426d5c8 */ 	lwc1	$f6,%lo(var7f1ad5c8)($at)
/*  f0b9948:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0b994c:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f0b9950:	c4640380 */ 	lwc1	$f4,0x380($v1)
/*  f0b9954:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0b9958:	0c0068f4 */ 	jal	cosf
/*  f0b995c:	e7aa0084 */ 	swc1	$f10,0x84($sp)
/*  f0b9960:	3c02800a */ 	lui	$v0,%hi(var8009dde4)
/*  f0b9964:	2442dde4 */ 	addiu	$v0,$v0,%lo(var8009dde4)
/*  f0b9968:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f0b996c:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f0b9970:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f0b9974:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0b9978:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f0b997c:	c4680384 */ 	lwc1	$f8,0x384($v1)
/*  f0b9980:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0b9984:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0b9988:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0b998c:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0b9990:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0b9994:	c466037c */ 	lwc1	$f6,0x37c($v1)
/*  f0b9998:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f0b999c:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f0b99a0:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0b99a4:	c4660380 */ 	lwc1	$f6,0x380($v1)
/*  f0b99a8:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f0b99ac:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f0b99b0:	c4660384 */ 	lwc1	$f6,0x384($v1)
/*  f0b99b4:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f0b99b8:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0b99bc:	8c6800bc */ 	lw	$t0,0xbc($v1)
/*  f0b99c0:	250b0028 */ 	addiu	$t3,$t0,0x28
/*  f0b99c4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0b99c8:	0fc30610 */ 	jal	func0f0c1840
/*  f0b99cc:	25070008 */ 	addiu	$a3,$t0,0x8
/*  f0b99d0:	3c02800a */ 	lui	$v0,%hi(var8009dde4)
/*  f0b99d4:	2442dde4 */ 	addiu	$v0,$v0,%lo(var8009dde4)
/*  f0b99d8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0b99dc:	44813000 */ 	mtc1	$at,$f6
/*  f0b99e0:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0b99e4:	4606403c */ 	c.lt.s	$f8,$f6
/*  f0b99e8:	00000000 */ 	nop
/*  f0b99ec:	45020004 */ 	bc1fl	.L0f0b9a00
/*  f0b99f0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0b99f4:	0fc2e6bf */ 	jal	func0f0b9afc
/*  f0b99f8:	00000000 */ 	nop
/*  f0b99fc:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0b9a00:
/*  f0b9a00:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0b9a04:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f0b9a08:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f0b9a0c:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f0b9a10:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f0b9a14:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f0b9a18:	03e00008 */ 	jr	$ra
/*  f0b9a1c:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

void func0f0b9a20(void)
{
	setTickMode(TICKMODE_1);
	var80070744 = 0;
	currentPlayerSetMoveMode(MOVEMODE_WALK);

	if (mainGetStageNum() == STAGE_TEST_LEN) {
		currentPlayerSetFadeColour(0, 0, 0, 1);
		currentPlayerSetFadeFrac(0, 1);
	} else if (var80070748 != 0) {
		currentPlayerSetFadeColour(0, 0, 0, 1);
		currentPlayerSetFadeFrac(60, 0);
	}

	func0f165eec(mainGetStageNum(), 0);
	currentPlayerEquipWeaponWrapper(1, g_DefaultWeaponArgument);
	currentPlayerEquipWeaponWrapper(0, g_DefaultWeapon);
	var8007074c = 0;
}

void func0f0b9afc(void)
{
	if (var800624a4) {
		mainSetStageNum(STAGE_TITLE);
	} else if (g_Vars.unk0004d3) {
		g_Vars.unk0004d6 = 1;
	} else {
		setTickMode(TICKMODE_1);
		var80070744 = 0;
		setMoveModeForAllPlayers(MOVEMODE_WALK);
	}
}

void warpBondToPad(s16 pad)
{
	setTickMode(TICKMODE_3);
	var80070744 = 0;
	setMoveModeForAllPlayers(MOVEMODE_CUTSCENE);
	func0f0c1d20();
	g_WarpPadId = pad;
}

void func0f0b9bac(u32 *cmd, s32 arg1, s32 arg2)
{
	setTickMode(TICKMODE_3);
	var80070744 = 0;
	setMoveModeForAllPlayers(MOVEMODE_CUTSCENE);
	func0f0c1d20();
	g_WarpPadId = -1;
	var8009ddec = cmd;
	var8009de08 = arg1;
	var8009de0c = arg2;
}

void func0f0b9c1c(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5)
{
	setTickMode(TICKMODE_3);
	var80070744 = 0;
	setMoveModeForAllPlayers(MOVEMODE_CUTSCENE);
	func0f0c1d20();
	g_WarpPadId = -1;
	var8009ddec = NULL;
	var8009ddf0 = arg0;
	var8009ddf4 = arg1;
	var8009ddf8 = arg2;
	var8009ddfc = arg3;
	var8009de00 = arg4;
	var8009de04 = arg5;
}

GLOBAL_ASM(
glabel func0f0b9cbc
.late_rodata
glabel var7f1ad5cc
.word 0x40c907a9
.text
/*  f0b9cbc:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0b9cc0:	3c0f8007 */ 	lui	$t7,%hi(var80070818)
/*  f0b9cc4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0b9cc8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0b9ccc:	25ef0818 */ 	addiu	$t7,$t7,%lo(var80070818)
/*  f0b9cd0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0b9cd4:	27ae0058 */ 	addiu	$t6,$sp,0x58
/*  f0b9cd8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0b9cdc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0b9ce0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0b9ce4:	3c0a8007 */ 	lui	$t2,%hi(var80070824)
/*  f0b9ce8:	254a0824 */ 	addiu	$t2,$t2,%lo(var80070824)
/*  f0b9cec:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0b9cf0:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0b9cf4:	8d410000 */ 	lw	$at,0x0($t2)
/*  f0b9cf8:	27a9004c */ 	addiu	$t1,$sp,0x4c
/*  f0b9cfc:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f0b9d00:	ad210000 */ 	sw	$at,0x0($t1)
/*  f0b9d04:	8d410008 */ 	lw	$at,0x8($t2)
/*  f0b9d08:	3c188007 */ 	lui	$t8,%hi(var80070830)
/*  f0b9d0c:	27180830 */ 	addiu	$t8,$t8,%lo(var80070830)
/*  f0b9d10:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f0b9d14:	ad210008 */ 	sw	$at,0x8($t1)
/*  f0b9d18:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b9d1c:	27b90040 */ 	addiu	$t9,$sp,0x40
/*  f0b9d20:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f0b9d24:	af210000 */ 	sw	$at,0x0($t9)
/*  f0b9d28:	8f010008 */ 	lw	$at,0x8($t8)
/*  f0b9d2c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b9d30:	af280004 */ 	sw	$t0,0x4($t9)
/*  f0b9d34:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0b9d38:	af210008 */ 	sw	$at,0x8($t9)
/*  f0b9d3c:	3c04800a */ 	lui	$a0,%hi(g_WarpPadId)
/*  f0b9d40:	8484dde8 */ 	lh	$a0,%lo(g_WarpPadId)($a0)
/*  f0b9d44:	3c10800a */ 	lui	$s0,%hi(var8009ddec)
/*  f0b9d48:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b9d4c:	0480000f */ 	bltz	$a0,.L0f0b9d8c
/*  f0b9d50:	2610ddec */ 	addiu	$s0,$s0,%lo(var8009ddec)
/*  f0b9d54:	0fc456ac */ 	jal	padUnpack
/*  f0b9d58:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0b9d5c:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f0b9d60:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f0b9d64:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0b9d68:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f0b9d6c:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f0b9d70:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0b9d74:	e7ae005c */ 	swc1	$f14,0x5c($sp)
/*  f0b9d78:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f0b9d7c:	e7b00060 */ 	swc1	$f16,0x60($sp)
/*  f0b9d80:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0b9d84:	10000096 */ 	b	.L0f0b9fe0
/*  f0b9d88:	afac003c */ 	sw	$t4,0x3c($sp)
.L0f0b9d8c:
/*  f0b9d8c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f0b9d90:	3c04800a */ 	lui	$a0,%hi(var8009de04)
/*  f0b9d94:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b9d98:	10400030 */ 	beqz	$v0,.L0f0b9e5c
/*  f0b9d9c:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0b9da0:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0b9da4:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b9da8:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0b9dac:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0b9db0:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0b9db4:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f0b9db8:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0b9dbc:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f0b9dc0:	0fc456ac */ 	jal	padUnpack
/*  f0b9dc4:	8c440018 */ 	lw	$a0,0x18($v0)
/*  f0b9dc8:	3c09800a */ 	lui	$t1,%hi(var8009de08)
/*  f0b9dcc:	8d29de08 */ 	lw	$t1,%lo(var8009de08)($t1)
/*  f0b9dd0:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0b9dd4:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f0b9dd8:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f0b9ddc:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0b9de0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b9de4:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f0b9de8:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0b9dec:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f0b9df0:	1121007b */ 	beq	$t1,$at,.L0f0b9fe0
/*  f0b9df4:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0b9df8:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0b9dfc:	0c0068f4 */ 	jal	cosf
/*  f0b9e00:	c54c0014 */ 	lwc1	$f12,0x14($t2)
/*  f0b9e04:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f0b9e08:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9e0c:	0c0068f7 */ 	jal	sinf
/*  f0b9e10:	c5ac0010 */ 	lwc1	$f12,0x10($t5)
/*  f0b9e14:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f0b9e18:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0b9e1c:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f0b9e20:	e7b2004c */ 	swc1	$f18,0x4c($sp)
/*  f0b9e24:	0c0068f7 */ 	jal	sinf
/*  f0b9e28:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*  f0b9e2c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0b9e30:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0b9e34:	0c0068f4 */ 	jal	cosf
/*  f0b9e38:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f0b9e3c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0b9e40:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9e44:	0c0068f4 */ 	jal	cosf
/*  f0b9e48:	c72c0010 */ 	lwc1	$f12,0x10($t9)
/*  f0b9e4c:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0b9e50:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0b9e54:	10000062 */ 	b	.L0f0b9fe0
/*  f0b9e58:	e7a60054 */ 	swc1	$f6,0x54($sp)
.L0f0b9e5c:
/*  f0b9e5c:	0fc456ac */ 	jal	padUnpack
/*  f0b9e60:	8c84de04 */ 	lw	$a0,%lo(var8009de04)($a0)
/*  f0b9e64:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f0b9e68:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f0b9e6c:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f0b9e70:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0b9e74:	3c10800a */ 	lui	$s0,%hi(var8009ddf0)
/*  f0b9e78:	2610ddf0 */ 	addiu	$s0,$s0,%lo(var8009ddf0)
/*  f0b9e7c:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9e80:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f0b9e84:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0b9e88:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f0b9e8c:	0c0068f7 */ 	jal	sinf
/*  f0b9e90:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0b9e94:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9e98:	0c0068f4 */ 	jal	cosf
/*  f0b9e9c:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9ea0:	3c01800a */ 	lui	$at,%hi(var8009ddf8)
/*  f0b9ea4:	c42addf8 */ 	lwc1	$f10,%lo(var8009ddf8)($at)
/*  f0b9ea8:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f0b9eac:	3c01800a */ 	lui	$at,%hi(var8009de00)
/*  f0b9eb0:	c7ae0034 */ 	lwc1	$f14,0x34($sp)
/*  f0b9eb4:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0b9eb8:	c426de00 */ 	lwc1	$f6,%lo(var8009de00)($at)
/*  f0b9ebc:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0b9ec0:	3c01800a */ 	lui	$at,%hi(var8009ddfc)
/*  f0b9ec4:	c42addfc */ 	lwc1	$f10,%lo(var8009ddfc)($at)
/*  f0b9ec8:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f0b9ecc:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9ed0:	46121100 */ 	add.s	$f4,$f2,$f18
/*  f0b9ed4:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0b9ed8:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0b9edc:	0c0068f4 */ 	jal	cosf
/*  f0b9ee0:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f0b9ee4:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9ee8:	0c0068f7 */ 	jal	sinf
/*  f0b9eec:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9ef0:	3c01800a */ 	lui	$at,%hi(var8009ddf8)
/*  f0b9ef4:	c426ddf8 */ 	lwc1	$f6,%lo(var8009ddf8)($at)
/*  f0b9ef8:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0b9efc:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0b9f00:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9f04:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0b9f08:	46088280 */ 	add.s	$f10,$f16,$f8
/*  f0b9f0c:	0c0068f4 */ 	jal	cosf
/*  f0b9f10:	e7aa0060 */ 	swc1	$f10,0x60($sp)
/*  f0b9f14:	3c01800a */ 	lui	$at,%hi(var8009de00)
/*  f0b9f18:	c7ae0034 */ 	lwc1	$f14,0x34($sp)
/*  f0b9f1c:	c426de00 */ 	lwc1	$f6,%lo(var8009de00)($at)
/*  f0b9f20:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0b9f24:	c7b20058 */ 	lwc1	$f18,0x58($sp)
/*  f0b9f28:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f0b9f2c:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f0b9f30:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9f34:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f0b9f38:	460a4481 */ 	sub.s	$f18,$f8,$f10
/*  f0b9f3c:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f0b9f40:	0c0068f7 */ 	jal	sinf
/*  f0b9f44:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*  f0b9f48:	3c017f1b */ 	lui	$at,%hi(var7f1ad5cc)
/*  f0b9f4c:	c42cd5cc */ 	lwc1	$f12,%lo(var7f1ad5cc)($at)
/*  f0b9f50:	3c01800a */ 	lui	$at,%hi(var8009ddf4)
/*  f0b9f54:	c428ddf4 */ 	lwc1	$f8,%lo(var8009ddf4)($at)
/*  f0b9f58:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f0b9f5c:	c42aa00c */ 	lwc1	$f10,%lo(g_Vars+0x4c)($at)
/*  f0b9f60:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0b9f64:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f0b9f68:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0b9f6c:	44800000 */ 	mtc1	$zero,$f0
/*  f0b9f70:	46048181 */ 	sub.s	$f6,$f16,$f4
/*  f0b9f74:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f0b9f78:	e7a60054 */ 	swc1	$f6,0x54($sp)
/*  f0b9f7c:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f0b9f80:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f0b9f84:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f0b9f88:	4602603e */ 	c.le.s	$f12,$f2
/*  f0b9f8c:	00000000 */ 	nop
/*  f0b9f90:	45020009 */ 	bc1fl	.L0f0b9fb8
/*  f0b9f94:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0b9f98:	460c1201 */ 	sub.s	$f8,$f2,$f12
.L0f0b9f9c:
/*  f0b9f9c:	e6080000 */ 	swc1	$f8,0x0($s0)
/*  f0b9fa0:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f0b9fa4:	4602603e */ 	c.le.s	$f12,$f2
/*  f0b9fa8:	00000000 */ 	nop
/*  f0b9fac:	4503fffb */ 	bc1tl	.L0f0b9f9c
/*  f0b9fb0:	460c1201 */ 	sub.s	$f8,$f2,$f12
/*  f0b9fb4:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0b9fb8:
/*  f0b9fb8:	00000000 */ 	nop
/*  f0b9fbc:	45020009 */ 	bc1fl	.L0f0b9fe4
/*  f0b9fc0:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0b9fc4:	460c1280 */ 	add.s	$f10,$f2,$f12
.L0f0b9fc8:
/*  f0b9fc8:	e60a0000 */ 	swc1	$f10,0x0($s0)
/*  f0b9fcc:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f0b9fd0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0b9fd4:	00000000 */ 	nop
/*  f0b9fd8:	4503fffb */ 	bc1tl	.L0f0b9fc8
/*  f0b9fdc:	460c1280 */ 	add.s	$f10,$f2,$f12
.L0f0b9fe0:
/*  f0b9fe0:	8fa8003c */ 	lw	$t0,0x3c($sp)
.L0f0b9fe4:
/*  f0b9fe4:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0b9fe8:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f0b9fec:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f0b9ff0:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f0b9ff4:	0fc306e9 */ 	jal	func0f0c1ba4
/*  f0b9ff8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0b9ffc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ba000:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0ba004:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0ba008:	03e00008 */ 	jr	$ra
/*  f0ba00c:	00000000 */ 	nop
);

void func0f0ba010(void)
{
	setTickMode(TICKMODE_CUTSCENE);
	var80070744 = 0;
	setMoveModeForAllPlayers(MOVEMODE_CUTSCENE);
	func0f0c1d20();
	var8009de14 = var8009de20;
	var8009de10 = var8009de20 >> 2;
	var8009de1c = 0;
	var8009de2c = -1;
	var80070764 = 1;
	func0f11dcb0(1);
	g_Vars.in_cutscene = g_Vars.tickmode == TICKMODE_CUTSCENE && var8009de10 < animGetNumFrames(g_CameraAnimNum) - 1;
	g_Vars.unk0004e2 = 0;
}

void cameraDoAnimation(s16 animnum)
{
	if ((!var800624a4 && g_Vars.unk0004d3 == 0)
			|| g_Vars.in_cutscene == 0
			|| var8009de24 == 0) {
		contDisableTemporarily();

		if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
			var8009de24 = 0;
			var8009de28 = 0;
		}

		if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
			func0f0b85f8();
		}

		g_CameraAnimNum = animnum;

		if (g_Vars.currentplayer->haschrbody) {
			func0f0ba010();
		}
	}
}

GLOBAL_ASM(
glabel func0f0ba190
.late_rodata
glabel var7f1ad5d0
.word 0x40c907a9
glabel var7f1ad5d4
.word 0x42653838
glabel var7f1ad5d8
.word 0x3c8ef461
.text
/*  f0ba190:	3c01800a */ 	lui	$at,%hi(var8009de2c)
/*  f0ba194:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0ba198:	ac24de2c */ 	sw	$a0,%lo(var8009de2c)($at)
/*  f0ba19c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ba1a0:	3c04800a */ 	lui	$a0,%hi(g_CameraAnimNum)
/*  f0ba1a4:	0c008dda */ 	jal	animGetNumFrames
/*  f0ba1a8:	8484de18 */ 	lh	$a0,%lo(g_CameraAnimNum)($a0)
/*  f0ba1ac:	244effff */ 	addiu	$t6,$v0,-1
/*  f0ba1b0:	3c04800a */ 	lui	$a0,%hi(g_CameraAnimNum)
/*  f0ba1b4:	afae0034 */ 	sw	$t6,0x34($sp)
/*  f0ba1b8:	0c008f4e */ 	jal	func00023d38
/*  f0ba1bc:	8484de18 */ 	lh	$a0,%lo(g_CameraAnimNum)($a0)
/*  f0ba1c0:	3c04800a */ 	lui	$a0,%hi(g_CameraAnimNum)
/*  f0ba1c4:	8484de18 */ 	lh	$a0,%lo(g_CameraAnimNum)($a0)
/*  f0ba1c8:	0c008eac */ 	jal	func00023ab0
/*  f0ba1cc:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0ba1d0:	0c008f43 */ 	jal	func00023d0c
/*  f0ba1d4:	a3a2007b */ 	sb	$v0,0x7b($sp)
/*  f0ba1d8:	93af007b */ 	lbu	$t7,0x7b($sp)
/*  f0ba1dc:	3c068008 */ 	lui	$a2,%hi(stagethinglist_221b4)
/*  f0ba1e0:	3c07800a */ 	lui	$a3,%hi(g_CameraAnimNum)
/*  f0ba1e4:	27b80094 */ 	addiu	$t8,$sp,0x94
/*  f0ba1e8:	27b90088 */ 	addiu	$t9,$sp,0x88
/*  f0ba1ec:	27a8007c */ 	addiu	$t0,$sp,0x7c
/*  f0ba1f0:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ba1f4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ba1f8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ba1fc:	84e7de18 */ 	lh	$a3,%lo(g_CameraAnimNum)($a3)
/*  f0ba200:	24c6c194 */ 	addiu	$a2,$a2,%lo(stagethinglist_221b4)
/*  f0ba204:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ba208:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ba20c:	0c009014 */ 	jal	func00024050
/*  f0ba210:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ba214:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0ba218:	0c005923 */ 	jal	func0001648c
/*  f0ba21c:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f0ba220:	c7ac0058 */ 	lwc1	$f12,0x58($sp)
/*  f0ba224:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0ba228:	46006307 */ 	neg.s	$f12,$f12
/*  f0ba22c:	0fc259d4 */ 	jal	func0f096750
/*  f0ba230:	46007387 */ 	neg.s	$f14,$f14
/*  f0ba234:	3c017f1b */ 	lui	$at,%hi(var7f1ad5d0)
/*  f0ba238:	c424d5d0 */ 	lwc1	$f4,%lo(var7f1ad5d0)($at)
/*  f0ba23c:	3c017f1b */ 	lui	$at,%hi(var7f1ad5d4)
/*  f0ba240:	c428d5d4 */ 	lwc1	$f8,%lo(var7f1ad5d4)($at)
/*  f0ba244:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0ba248:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ba24c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ba250:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0ba254:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f0ba258:	8c4902a0 */ 	lw	$t1,0x2a0($v0)
/*  f0ba25c:	44815000 */ 	mtc1	$at,$f10
/*  f0ba260:	3c017f1b */ 	lui	$at,%hi(var7f1ad5d8)
/*  f0ba264:	46025401 */ 	sub.s	$f16,$f10,$f2
/*  f0ba268:	e5220144 */ 	swc1	$f2,0x144($t1)
/*  f0ba26c:	c432d5d8 */ 	lwc1	$f18,%lo(var7f1ad5d8)($at)
/*  f0ba270:	8c4a02a0 */ 	lw	$t2,0x2a0($v0)
/*  f0ba274:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0ba278:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0ba27c:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f0ba280:	44052000 */ 	mfc1	$a1,$f4
/*  f0ba284:	0fc0f94e */ 	jal	func0f03e538
/*  f0ba288:	00000000 */ 	nop
/*  f0ba28c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ba290:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f0ba294:	03e00008 */ 	jr	$ra
/*  f0ba298:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0ba29c
.late_rodata
glabel var7f1ad5dc
.word 0x3fc907a9
.text
/*  f0ba29c:	27bdfe58 */ 	addiu	$sp,$sp,-424
/*  f0ba2a0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ba2a4:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f0ba2a8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0ba2ac:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f0ba2b0:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f0ba2b4:	0fc57222 */ 	jal	func0f15c888
/*  f0ba2b8:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f0ba2bc:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f0ba2c0:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f0ba2c4:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f0ba2c8:	e7a00118 */ 	swc1	$f0,0x118($sp)
/*  f0ba2cc:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0ba2d0:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0ba2d4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0ba2d8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0ba2dc:	12000005 */ 	beqz	$s0,.L0f0ba2f4
/*  f0ba2e0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0ba2e4:	0c0053d8 */ 	jal	contGetButtons
/*  f0ba2e8:	3405ffff */ 	dli	$a1,0xffff
/*  f0ba2ec:	10000002 */ 	b	.L0f0ba2f8
/*  f0ba2f0:	a7a2010c */ 	sh	$v0,0x10c($sp)
.L0f0ba2f4:
/*  f0ba2f4:	a7a0010c */ 	sh	$zero,0x10c($sp)
.L0f0ba2f8:
/*  f0ba2f8:	3c12800a */ 	lui	$s2,%hi(g_CameraAnimNum)
/*  f0ba2fc:	2652de18 */ 	addiu	$s2,$s2,%lo(g_CameraAnimNum)
/*  f0ba300:	0c008f4e */ 	jal	func00023d38
/*  f0ba304:	86440000 */ 	lh	$a0,0x0($s2)
/*  f0ba308:	0c008dda */ 	jal	animGetNumFrames
/*  f0ba30c:	86440000 */ 	lh	$a0,0x0($s2)
/*  f0ba310:	8e780290 */ 	lw	$t8,0x290($s3)
/*  f0ba314:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f0ba318:	00808825 */ 	or	$s1,$a0,$zero
/*  f0ba31c:	17000040 */ 	bnez	$t8,.L0f0ba420
/*  f0ba320:	3c10800a */ 	lui	$s0,%hi(var8009de10)
/*  f0ba324:	2610de10 */ 	addiu	$s0,$s0,%lo(var8009de10)
/*  f0ba328:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0ba32c:	3c03800a */ 	lui	$v1,%hi(var8009de14)
/*  f0ba330:	a26004e2 */ 	sb	$zero,0x4e2($s3)
/*  f0ba334:	0324082a */ 	slt	$at,$t9,$a0
/*  f0ba338:	10200039 */ 	beqz	$at,.L0f0ba420
/*  f0ba33c:	2463de14 */ 	addiu	$v1,$v1,%lo(var8009de14)
/*  f0ba340:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f0ba344:	8e690034 */ 	lw	$t1,0x34($s3)
/*  f0ba348:	86460000 */ 	lh	$a2,0x0($s2)
/*  f0ba34c:	3c0d8006 */ 	lui	$t5,%hi(g_Anims)
/*  f0ba350:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0ba354:	000a6083 */ 	sra	$t4,$t2,0x2
/*  f0ba358:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0ba35c:	ae0c0000 */ 	sw	$t4,0x0($s0)
/*  f0ba360:	8dadf00c */ 	lw	$t5,%lo(g_Anims)($t5)
/*  f0ba364:	00067080 */ 	sll	$t6,$a2,0x2
/*  f0ba368:	01c67023 */ 	subu	$t6,$t6,$a2
/*  f0ba36c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0ba370:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0ba374:	91f8000b */ 	lbu	$t8,0xb($t7)
/*  f0ba378:	0184082a */ 	slt	$at,$t4,$a0
/*  f0ba37c:	33190008 */ 	andi	$t9,$t8,0x8
/*  f0ba380:	5320001b */ 	beqzl	$t9,.L0f0ba3f0
/*  f0ba384:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f0ba388:	10200018 */ 	beqz	$at,.L0f0ba3ec
/*  f0ba38c:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ba390:	00062400 */ 	sll	$a0,$a2,0x10
/*  f0ba394:	00044403 */ 	sra	$t0,$a0,0x10
/*  f0ba398:	0c008e78 */ 	jal	func000239e0
/*  f0ba39c:	01002025 */ 	or	$a0,$t0,$zero
/*  f0ba3a0:	3c03800a */ 	lui	$v1,%hi(var8009de14)
/*  f0ba3a4:	10400011 */ 	beqz	$v0,.L0f0ba3ec
/*  f0ba3a8:	2463de14 */ 	addiu	$v1,$v1,%lo(var8009de14)
.L0f0ba3ac:
/*  f0ba3ac:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f0ba3b0:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0ba3b4:	926d04e2 */ 	lbu	$t5,0x4e2($s3)
/*  f0ba3b8:	25250001 */ 	addiu	$a1,$t1,0x1
/*  f0ba3bc:	00b1082a */ 	slt	$at,$a1,$s1
/*  f0ba3c0:	256c0004 */ 	addiu	$t4,$t3,0x4
/*  f0ba3c4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0ba3c8:	ae050000 */ 	sw	$a1,0x0($s0)
/*  f0ba3cc:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0ba3d0:	10200006 */ 	beqz	$at,.L0f0ba3ec
/*  f0ba3d4:	a26e04e2 */ 	sb	$t6,0x4e2($s3)
/*  f0ba3d8:	0c008e78 */ 	jal	func000239e0
/*  f0ba3dc:	86440000 */ 	lh	$a0,0x0($s2)
/*  f0ba3e0:	3c03800a */ 	lui	$v1,%hi(var8009de14)
/*  f0ba3e4:	1440fff1 */ 	bnez	$v0,.L0f0ba3ac
/*  f0ba3e8:	2463de14 */ 	addiu	$v1,$v1,%lo(var8009de14)
.L0f0ba3ec:
/*  f0ba3ec:	8e050000 */ 	lw	$a1,0x0($s0)
.L0f0ba3f0:
/*  f0ba3f0:	00b1082a */ 	slt	$at,$a1,$s1
/*  f0ba3f4:	54200007 */ 	bnezl	$at,.L0f0ba414
/*  f0ba3f8:	0225082a */ 	slt	$at,$s1,$a1
/*  f0ba3fc:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0ba400:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f0ba404:	3c01800a */ 	lui	$at,%hi(var8009de20)
/*  f0ba408:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f0ba40c:	ac39de20 */ 	sw	$t9,%lo(var8009de20)($at)
/*  f0ba410:	0225082a */ 	slt	$at,$s1,$a1
.L0f0ba414:
/*  f0ba414:	50200003 */ 	beqzl	$at,.L0f0ba424
/*  f0ba418:	8e6202ac */ 	lw	$v0,0x2ac($s3)
/*  f0ba41c:	ae110000 */ 	sw	$s1,0x0($s0)
.L0f0ba420:
/*  f0ba420:	8e6202ac */ 	lw	$v0,0x2ac($s3)
.L0f0ba424:
/*  f0ba424:	3c10800a */ 	lui	$s0,%hi(var8009de10)
/*  f0ba428:	2610de10 */ 	addiu	$s0,$s0,%lo(var8009de10)
/*  f0ba42c:	38480006 */ 	xori	$t0,$v0,0x6
/*  f0ba430:	2d020001 */ 	sltiu	$v0,$t0,0x1
/*  f0ba434:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f0ba438:	10400002 */ 	beqz	$v0,.L0f0ba444
/*  f0ba43c:	86460000 */ 	lh	$a2,0x0($s2)
/*  f0ba440:	00b1102a */ 	slt	$v0,$a1,$s1
.L0f0ba444:
/*  f0ba444:	00062400 */ 	sll	$a0,$a2,0x10
/*  f0ba448:	00044c03 */ 	sra	$t1,$a0,0x10
/*  f0ba44c:	ae6204cc */ 	sw	$v0,0x4cc($s3)
/*  f0ba450:	0c008eac */ 	jal	func00023ab0
/*  f0ba454:	01202025 */ 	or	$a0,$t1,$zero
/*  f0ba458:	0c008f43 */ 	jal	func00023d0c
/*  f0ba45c:	a3a2015f */ 	sb	$v0,0x15f($sp)
/*  f0ba460:	93aa015f */ 	lbu	$t2,0x15f($sp)
/*  f0ba464:	3c068008 */ 	lui	$a2,%hi(stagethinglist_221b4)
/*  f0ba468:	27ab0178 */ 	addiu	$t3,$sp,0x178
/*  f0ba46c:	27ac016c */ 	addiu	$t4,$sp,0x16c
/*  f0ba470:	27ad0160 */ 	addiu	$t5,$sp,0x160
/*  f0ba474:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0ba478:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0ba47c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0ba480:	24c6c194 */ 	addiu	$a2,$a2,%lo(stagethinglist_221b4)
/*  f0ba484:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ba488:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ba48c:	86470000 */ 	lh	$a3,0x0($s2)
/*  f0ba490:	0c009014 */ 	jal	func00024050
/*  f0ba494:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ba498:	c7a00118 */ 	lwc1	$f0,0x118($sp)
/*  f0ba49c:	c7a4016c */ 	lwc1	$f4,0x16c($sp)
/*  f0ba4a0:	c7a80170 */ 	lwc1	$f8,0x170($sp)
/*  f0ba4a4:	c7b00174 */ 	lwc1	$f16,0x174($sp)
/*  f0ba4a8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0ba4ac:	27a40178 */ 	addiu	$a0,$sp,0x178
/*  f0ba4b0:	27a5011c */ 	addiu	$a1,$sp,0x11c
/*  f0ba4b4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ba4b8:	00000000 */ 	nop
/*  f0ba4bc:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0ba4c0:	e7a6019c */ 	swc1	$f6,0x19c($sp)
/*  f0ba4c4:	e7aa01a0 */ 	swc1	$f10,0x1a0($sp)
/*  f0ba4c8:	0c005923 */ 	jal	func0001648c
/*  f0ba4cc:	e7b201a4 */ 	swc1	$f18,0x1a4($sp)
/*  f0ba4d0:	c7a60130 */ 	lwc1	$f6,0x130($sp)
/*  f0ba4d4:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f0ba4d8:	c7a80134 */ 	lwc1	$f8,0x134($sp)
/*  f0ba4dc:	e7a60194 */ 	swc1	$f6,0x194($sp)
/*  f0ba4e0:	c7aa013c */ 	lwc1	$f10,0x13c($sp)
/*  f0ba4e4:	c7b20140 */ 	lwc1	$f18,0x140($sp)
/*  f0ba4e8:	c7a60144 */ 	lwc1	$f6,0x144($sp)
/*  f0ba4ec:	e7a40190 */ 	swc1	$f4,0x190($sp)
/*  f0ba4f0:	e7a80198 */ 	swc1	$f8,0x198($sp)
/*  f0ba4f4:	46005407 */ 	neg.s	$f16,$f10
/*  f0ba4f8:	46009107 */ 	neg.s	$f4,$f18
/*  f0ba4fc:	46003207 */ 	neg.s	$f8,$f6
/*  f0ba500:	e7b00184 */ 	swc1	$f16,0x184($sp)
/*  f0ba504:	e7a40188 */ 	swc1	$f4,0x188($sp)
/*  f0ba508:	e7a8018c */ 	swc1	$f8,0x18c($sp)
/*  f0ba50c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ba510:	86450000 */ 	lh	$a1,0x0($s2)
/*  f0ba514:	0c009305 */ 	jal	func00024c14
/*  f0ba518:	93a6015f */ 	lbu	$a2,0x15f($sp)
/*  f0ba51c:	e7a00114 */ 	swc1	$f0,0x114($sp)
/*  f0ba520:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ba524:	86450000 */ 	lh	$a1,0x0($s2)
/*  f0ba528:	0c009305 */ 	jal	func00024c14
/*  f0ba52c:	93a6015f */ 	lbu	$a2,0x15f($sp)
/*  f0ba530:	44805000 */ 	mtc1	$zero,$f10
/*  f0ba534:	3c04800a */ 	lui	$a0,%hi(var8009de30)
/*  f0ba538:	3c12800a */ 	lui	$s2,%hi(var8009de1c)
/*  f0ba53c:	2652de1c */ 	addiu	$s2,$s2,%lo(var8009de1c)
/*  f0ba540:	2484de30 */ 	addiu	$a0,$a0,%lo(var8009de30)
/*  f0ba544:	e6400000 */ 	swc1	$f0,0x0($s2)
/*  f0ba548:	3c02800a */ 	lui	$v0,%hi(var8009de2c)
/*  f0ba54c:	e48a0000 */ 	swc1	$f10,0x0($a0)
/*  f0ba550:	8c42de2c */ 	lw	$v0,%lo(var8009de2c)($v0)
/*  f0ba554:	18400088 */ 	blez	$v0,.L0f0ba778
/*  f0ba558:	00000000 */ 	nop
/*  f0ba55c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0ba560:	022e1823 */ 	subu	$v1,$s1,$t6
/*  f0ba564:	0043082a */ 	slt	$at,$v0,$v1
/*  f0ba568:	14200083 */ 	bnez	$at,.L0f0ba778
/*  f0ba56c:	00000000 */ 	nop
/*  f0ba570:	44838000 */ 	mtc1	$v1,$f16
/*  f0ba574:	44822000 */ 	mtc1	$v0,$f4
/*  f0ba578:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ba57c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ba580:	44815000 */ 	mtc1	$at,$f10
/*  f0ba584:	3c017f1b */ 	lui	$at,%hi(var7f1ad5dc)
/*  f0ba588:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ba58c:	46069203 */ 	div.s	$f8,$f18,$f6
/*  f0ba590:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f0ba594:	e4800000 */ 	swc1	$f0,0x0($a0)
/*  f0ba598:	c430d5dc */ 	lwc1	$f16,%lo(var7f1ad5dc)($at)
/*  f0ba59c:	e7a00108 */ 	swc1	$f0,0x108($sp)
/*  f0ba5a0:	46008302 */ 	mul.s	$f12,$f16,$f0
/*  f0ba5a4:	0c0068f4 */ 	jal	cosf
/*  f0ba5a8:	00000000 */ 	nop
/*  f0ba5ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ba5b0:	44812000 */ 	mtc1	$at,$f4
/*  f0ba5b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ba5b8:	46002481 */ 	sub.s	$f18,$f4,$f0
/*  f0ba5bc:	0fc31f4c */ 	jal	currentPlayerSetMoveMode
/*  f0ba5c0:	e7b20104 */ 	swc1	$f18,0x104($sp)
/*  f0ba5c4:	8e6202a0 */ 	lw	$v0,0x2a0($s3)
/*  f0ba5c8:	c7aa019c */ 	lwc1	$f10,0x19c($sp)
/*  f0ba5cc:	c7a20104 */ 	lwc1	$f2,0x104($sp)
/*  f0ba5d0:	c446037c */ 	lwc1	$f6,0x37c($v0)
/*  f0ba5d4:	44800000 */ 	mtc1	$zero,$f0
/*  f0ba5d8:	27b100c4 */ 	addiu	$s1,$sp,0xc4
/*  f0ba5dc:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0ba5e0:	c7a601a0 */ 	lwc1	$f6,0x1a0($sp)
/*  f0ba5e4:	44050000 */ 	mfc1	$a1,$f0
/*  f0ba5e8:	44060000 */ 	mfc1	$a2,$f0
/*  f0ba5ec:	46081402 */ 	mul.s	$f16,$f2,$f8
/*  f0ba5f0:	44070000 */ 	mfc1	$a3,$f0
/*  f0ba5f4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ba5f8:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f0ba5fc:	e7a4019c */ 	swc1	$f4,0x19c($sp)
/*  f0ba600:	c4520380 */ 	lwc1	$f18,0x380($v0)
/*  f0ba604:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f0ba608:	c7b201a4 */ 	lwc1	$f18,0x1a4($sp)
/*  f0ba60c:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0ba610:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0ba614:	e7b001a0 */ 	swc1	$f16,0x1a0($sp)
/*  f0ba618:	c4440384 */ 	lwc1	$f4,0x384($v0)
/*  f0ba61c:	c7b00184 */ 	lwc1	$f16,0x184($sp)
/*  f0ba620:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f0ba624:	46008107 */ 	neg.s	$f4,$f16
/*  f0ba628:	46081182 */ 	mul.s	$f6,$f2,$f8
/*  f0ba62c:	c7a80188 */ 	lwc1	$f8,0x188($sp)
/*  f0ba630:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0ba634:	c7a40194 */ 	lwc1	$f4,0x194($sp)
/*  f0ba638:	c7b00190 */ 	lwc1	$f16,0x190($sp)
/*  f0ba63c:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0ba640:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0ba644:	c7a6018c */ 	lwc1	$f6,0x18c($sp)
/*  f0ba648:	e7b0001c */ 	swc1	$f16,0x1c($sp)
/*  f0ba64c:	46004487 */ 	neg.s	$f18,$f8
/*  f0ba650:	c7a80198 */ 	lwc1	$f8,0x198($sp)
/*  f0ba654:	e7aa01a4 */ 	swc1	$f10,0x1a4($sp)
/*  f0ba658:	46003287 */ 	neg.s	$f10,$f6
/*  f0ba65c:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0ba660:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0ba664:	0c005b56 */ 	jal	func00016d58
/*  f0ba668:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0ba66c:	8e6202a0 */ 	lw	$v0,0x2a0($s3)
/*  f0ba670:	44800000 */ 	mtc1	$zero,$f0
/*  f0ba674:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0ba678:	c4520388 */ 	lwc1	$f18,0x388($v0)
/*  f0ba67c:	44050000 */ 	mfc1	$a1,$f0
/*  f0ba680:	44060000 */ 	mfc1	$a2,$f0
/*  f0ba684:	46009187 */ 	neg.s	$f6,$f18
/*  f0ba688:	44070000 */ 	mfc1	$a3,$f0
/*  f0ba68c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0ba690:	c44a038c */ 	lwc1	$f10,0x38c($v0)
/*  f0ba694:	46005407 */ 	neg.s	$f16,$f10
/*  f0ba698:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0ba69c:	c4440390 */ 	lwc1	$f4,0x390($v0)
/*  f0ba6a0:	46002207 */ 	neg.s	$f8,$f4
/*  f0ba6a4:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0ba6a8:	c4520394 */ 	lwc1	$f18,0x394($v0)
/*  f0ba6ac:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f0ba6b0:	c4460398 */ 	lwc1	$f6,0x398($v0)
/*  f0ba6b4:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0ba6b8:	c44a039c */ 	lwc1	$f10,0x39c($v0)
/*  f0ba6bc:	0c005b56 */ 	jal	func00016d58
/*  f0ba6c0:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f0ba6c4:	27b00074 */ 	addiu	$s0,$sp,0x74
/*  f0ba6c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0ba6cc:	0fc25c11 */ 	jal	func0f097044
/*  f0ba6d0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ba6d4:	27b10064 */ 	addiu	$s1,$sp,0x64
/*  f0ba6d8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0ba6dc:	0fc25c11 */ 	jal	func0f097044
/*  f0ba6e0:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0ba6e4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ba6e8:	0fc25db0 */ 	jal	func0f0976c0
/*  f0ba6ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f0ba6f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ba6f4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0ba6f8:	8fa60104 */ 	lw	$a2,0x104($sp)
/*  f0ba6fc:	0fc25cae */ 	jal	func0f0972b8
/*  f0ba700:	27a70054 */ 	addiu	$a3,$sp,0x54
/*  f0ba704:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f0ba708:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0ba70c:	27a5011c */ 	addiu	$a1,$sp,0x11c
/*  f0ba710:	c7b0012c */ 	lwc1	$f16,0x12c($sp)
/*  f0ba714:	c7a40130 */ 	lwc1	$f4,0x130($sp)
/*  f0ba718:	c7a60140 */ 	lwc1	$f6,0x140($sp)
/*  f0ba71c:	c7aa0144 */ 	lwc1	$f10,0x144($sp)
/*  f0ba720:	e7b00190 */ 	swc1	$f16,0x190($sp)
/*  f0ba724:	44808000 */ 	mtc1	$zero,$f16
/*  f0ba728:	c6400000 */ 	lwc1	$f0,0x0($s2)
/*  f0ba72c:	3c014270 */ 	lui	$at,0x4270
/*  f0ba730:	e7a40194 */ 	swc1	$f4,0x194($sp)
/*  f0ba734:	e7a60188 */ 	swc1	$f6,0x188($sp)
/*  f0ba738:	e7aa018c */ 	swc1	$f10,0x18c($sp)
/*  f0ba73c:	46008101 */ 	sub.s	$f4,$f16,$f0
/*  f0ba740:	c7a80134 */ 	lwc1	$f8,0x134($sp)
/*  f0ba744:	c7aa0114 */ 	lwc1	$f10,0x114($sp)
/*  f0ba748:	44813000 */ 	mtc1	$at,$f6
/*  f0ba74c:	c7a20108 */ 	lwc1	$f2,0x108($sp)
/*  f0ba750:	e7a80198 */ 	swc1	$f8,0x198($sp)
/*  f0ba754:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f0ba758:	46041202 */ 	mul.s	$f8,$f2,$f4
/*  f0ba75c:	c7b2013c */ 	lwc1	$f18,0x13c($sp)
/*  f0ba760:	46101102 */ 	mul.s	$f4,$f2,$f16
/*  f0ba764:	e7b20184 */ 	swc1	$f18,0x184($sp)
/*  f0ba768:	46080480 */ 	add.s	$f18,$f0,$f8
/*  f0ba76c:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0ba770:	e6520000 */ 	swc1	$f18,0x0($s2)
/*  f0ba774:	e7a80114 */ 	swc1	$f8,0x114($sp)
.L0f0ba778:
/*  f0ba778:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0ba77c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ba780:	27a4019c */ 	addiu	$a0,$sp,0x19c
/*  f0ba784:	27a50190 */ 	addiu	$a1,$sp,0x190
/*  f0ba788:	0fc306f6 */ 	jal	func0f0c1bd8
/*  f0ba78c:	27a60184 */ 	addiu	$a2,$sp,0x184
/*  f0ba790:	0fc4a2b5 */ 	jal	currentPlayerSetFovY
/*  f0ba794:	c7ac0114 */ 	lwc1	$f12,0x114($sp)
/*  f0ba798:	0c002f4c */ 	jal	viSetFovY
/*  f0ba79c:	c7ac0114 */ 	lwc1	$f12,0x114($sp)
/*  f0ba7a0:	8e6f0290 */ 	lw	$t7,0x290($s3)
/*  f0ba7a4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0ba7a8:	44815000 */ 	mtc1	$at,$f10
/*  f0ba7ac:	15e00006 */ 	bnez	$t7,.L0f0ba7c8
/*  f0ba7b0:	3c02800a */ 	lui	$v0,%hi(var8009de28)
/*  f0ba7b4:	2442de28 */ 	addiu	$v0,$v0,%lo(var8009de28)
/*  f0ba7b8:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f0ba7bc:	c666004c */ 	lwc1	$f6,0x4c($s3)
/*  f0ba7c0:	46069400 */ 	add.s	$f16,$f18,$f6
/*  f0ba7c4:	e4500000 */ 	swc1	$f16,0x0($v0)
.L0f0ba7c8:
/*  f0ba7c8:	3c02800a */ 	lui	$v0,%hi(var8009de28)
/*  f0ba7cc:	2442de28 */ 	addiu	$v0,$v0,%lo(var8009de28)
/*  f0ba7d0:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f0ba7d4:	97a2010c */ 	lhu	$v0,0x10c($sp)
/*  f0ba7d8:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0ba7dc:	00000000 */ 	nop
/*  f0ba7e0:	4502000f */ 	bc1fl	.L0f0ba820
/*  f0ba7e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ba7e8:	1040000c */ 	beqz	$v0,.L0f0ba81c
/*  f0ba7ec:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0ba7f0:	3c01800a */ 	lui	$at,%hi(var8009de24)
/*  f0ba7f4:	ac23de24 */ 	sw	$v1,%lo(var8009de24)($at)
/*  f0ba7f8:	827904d3 */ 	lb	$t9,0x4d3($s3)
/*  f0ba7fc:	30485000 */ 	andi	$t0,$v0,0x5000
/*  f0ba800:	53200007 */ 	beqzl	$t9,.L0f0ba820
/*  f0ba804:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ba808:	51000004 */ 	beqzl	$t0,.L0f0ba81c
/*  f0ba80c:	a26304d6 */ 	sb	$v1,0x4d6($s3)
/*  f0ba810:	10000002 */ 	b	.L0f0ba81c
/*  f0ba814:	a26304d7 */ 	sb	$v1,0x4d7($s3)
/*  f0ba818:	a26304d6 */ 	sb	$v1,0x4d6($s3)
.L0f0ba81c:
/*  f0ba81c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0ba820:
/*  f0ba820:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0ba824:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0ba828:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f0ba82c:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f0ba830:	03e00008 */ 	jr	$ra
/*  f0ba834:	27bd01a8 */ 	addiu	$sp,$sp,0x1a8
);

f32 getVar8009de1c(void)
{
	return var8009de1c;
}

void currentPlayerSetZoomFovY(f32 fovy, f32 timemax)
{
	g_Vars.currentplayer->zoomintime = 0;
	g_Vars.currentplayer->zoomintimemax = timemax;
	g_Vars.currentplayer->zoominfovyold = g_Vars.currentplayer->zoominfovy;
	g_Vars.currentplayer->zoominfovynew = fovy;
}

f32 currentPlayerGetZoomFovY(void)
{
	if (g_Vars.currentplayer->zoomintimemax > g_Vars.currentplayer->zoomintime) {
		return g_Vars.currentplayer->zoominfovynew;
	}

	return g_Vars.currentplayer->zoominfovy;
}

void func0f0ba8b0(f32 fovy)
{
	if (currentPlayerGetZoomFovY() != fovy) {
		if (fovy < g_Vars.currentplayer->zoominfovy) {
			currentPlayerSetZoomFovY(fovy, (g_Vars.currentplayer->zoominfovy - fovy) * 15.0f / 30.0f);
		} else {
			currentPlayerSetZoomFovY(fovy, (fovy - g_Vars.currentplayer->zoominfovy) * 15.0f / 30.0f);
		}
	}
}

GLOBAL_ASM(
glabel currentPlayerGetTeleportFovY
.late_rodata
glabel var7f1ad5e0
.word 0x40490fdb
.text
/*  f0ba948:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0ba94c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0ba950:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ba954:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ba958:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
/*  f0ba95c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ba960:	14610004 */ 	bne	$v1,$at,.L0f0ba974
/*  f0ba964:	3c014270 */ 	lui	$at,0x4270
/*  f0ba968:	44810000 */ 	mtc1	$at,$f0
/*  f0ba96c:	10000051 */ 	b	.L0f0baab4
/*  f0ba970:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ba974:
/*  f0ba974:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0ba978:	54610008 */ 	bnel	$v1,$at,.L0f0ba99c
/*  f0ba97c:	90591bfd */ 	lbu	$t9,0x1bfd($v0)
/*  f0ba980:	904e1bfd */ 	lbu	$t6,0x1bfd($v0)
/*  f0ba984:	240f002f */ 	addiu	$t7,$zero,0x2f
/*  f0ba988:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f0ba98c:	44982000 */ 	mtc1	$t8,$f4
/*  f0ba990:	10000009 */ 	b	.L0f0ba9b8
/*  f0ba994:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0ba998:	90591bfd */ 	lbu	$t9,0x1bfd($v0)
.L0f0ba99c:
/*  f0ba99c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0ba9a0:	44993000 */ 	mtc1	$t9,$f6
/*  f0ba9a4:	07210004 */ 	bgez	$t9,.L0f0ba9b8
/*  f0ba9a8:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0ba9ac:	44814000 */ 	mtc1	$at,$f8
/*  f0ba9b0:	00000000 */ 	nop
/*  f0ba9b4:	46080000 */ 	add.s	$f0,$f0,$f8
.L0f0ba9b8:
/*  f0ba9b8:	3c014240 */ 	lui	$at,0x4240
/*  f0ba9bc:	44815000 */ 	mtc1	$at,$f10
/*  f0ba9c0:	3c017f1b */ 	lui	$at,%hi(var7f1ad5e0)
/*  f0ba9c4:	c430d5e0 */ 	lwc1	$f16,%lo(var7f1ad5e0)($at)
/*  f0ba9c8:	460a0003 */ 	div.s	$f0,$f0,$f10
/*  f0ba9cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ba9d0:	44812000 */ 	mtc1	$at,$f4
/*  f0ba9d4:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0ba9d8:	00000000 */ 	nop
/*  f0ba9dc:	46049302 */ 	mul.s	$f12,$f18,$f4
/*  f0ba9e0:	0c0068f4 */ 	jal	cosf
/*  f0ba9e4:	00000000 */ 	nop
/*  f0ba9e8:	3c0142ea */ 	lui	$at,0x42ea
/*  f0ba9ec:	44813000 */ 	mtc1	$at,$f6
/*  f0ba9f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ba9f4:	44814000 */ 	mtc1	$at,$f8
/*  f0ba9f8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0ba9fc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0baa00:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f0baa04:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0baa08:	4448f800 */ 	cfc1	$t0,$31
/*  f0baa0c:	44c9f800 */ 	ctc1	$t1,$31
/*  f0baa10:	00000000 */ 	nop
/*  f0baa14:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0baa18:	4449f800 */ 	cfc1	$t1,$31
/*  f0baa1c:	00000000 */ 	nop
/*  f0baa20:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0baa24:	51200013 */ 	beqzl	$t1,.L0f0baa74
/*  f0baa28:	44099000 */ 	mfc1	$t1,$f18
/*  f0baa2c:	44819000 */ 	mtc1	$at,$f18
/*  f0baa30:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0baa34:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0baa38:	44c9f800 */ 	ctc1	$t1,$31
/*  f0baa3c:	00000000 */ 	nop
/*  f0baa40:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0baa44:	4449f800 */ 	cfc1	$t1,$31
/*  f0baa48:	00000000 */ 	nop
/*  f0baa4c:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0baa50:	15200005 */ 	bnez	$t1,.L0f0baa68
/*  f0baa54:	00000000 */ 	nop
/*  f0baa58:	44099000 */ 	mfc1	$t1,$f18
/*  f0baa5c:	3c018000 */ 	lui	$at,0x8000
/*  f0baa60:	10000007 */ 	b	.L0f0baa80
/*  f0baa64:	01214825 */ 	or	$t1,$t1,$at
.L0f0baa68:
/*  f0baa68:	10000005 */ 	b	.L0f0baa80
/*  f0baa6c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0baa70:	44099000 */ 	mfc1	$t1,$f18
.L0f0baa74:
/*  f0baa74:	00000000 */ 	nop
/*  f0baa78:	0520fffb */ 	bltz	$t1,.L0f0baa68
/*  f0baa7c:	00000000 */ 	nop
.L0f0baa80:
/*  f0baa80:	44c8f800 */ 	ctc1	$t0,$31
/*  f0baa84:	44892000 */ 	mtc1	$t1,$f4
/*  f0baa88:	3c014f80 */ 	lui	$at,0x4f80
/*  f0baa8c:	05210004 */ 	bgez	$t1,.L0f0baaa0
/*  f0baa90:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0baa94:	44813000 */ 	mtc1	$at,$f6
/*  f0baa98:	00000000 */ 	nop
/*  f0baa9c:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f0baaa0:
/*  f0baaa0:	3c014270 */ 	lui	$at,0x4270
/*  f0baaa4:	44815000 */ 	mtc1	$at,$f10
/*  f0baaa8:	00000000 */ 	nop
/*  f0baaac:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f0baab0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0baab4:
/*  f0baab4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0baab8:	03e00008 */ 	jr	$ra
/*  f0baabc:	00000000 */ 	nop
);

void currentPlayerUpdateZoom(void)
{
	f32 scale;
	f32 fovy;
	struct stagetableentry *stage;

	if (g_Vars.currentplayer->zoomintime < g_Vars.currentplayer->zoomintimemax) {
		g_Vars.currentplayer->zoomintime += g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->zoomintime > g_Vars.currentplayer->zoomintimemax) {
			g_Vars.currentplayer->zoomintime = g_Vars.currentplayer->zoomintimemax;
		}

		g_Vars.currentplayer->zoominfovy = g_Vars.currentplayer->zoominfovyold +
			(g_Vars.currentplayer->zoomintime *
			 (g_Vars.currentplayer->zoominfovynew - g_Vars.currentplayer->zoominfovyold))
			/ g_Vars.currentplayer->zoomintimemax;
	} else {
		g_Vars.currentplayer->zoomintime = g_Vars.currentplayer->zoomintimemax;
		g_Vars.currentplayer->zoominfovy = g_Vars.currentplayer->zoominfovynew;
	}

	currentPlayerSetFovY(g_Vars.currentplayer->zoominfovy);
	viSetFovY(g_Vars.currentplayer->zoominfovy);

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_0) {
		fovy = currentPlayerGetTeleportFovY();
		currentPlayerSetFovY(fovy);
		viSetFovY(fovy);
	}

	if (g_Vars.currentplayer->zoominfovy >= 15) {
		scale = 1;
	} else if (g_Vars.currentplayer->zoominfovy >= 7) {
		scale = (g_Vars.currentplayer->zoominfovy - 7) * 0.0875f + 0.3f;
	} else if (g_Vars.currentplayer->zoominfovy >= 4) {
		scale = (g_Vars.currentplayer->zoominfovy - 4) * (1.0f / 30.0f) + 0.2f;
	} else if (g_Vars.currentplayer->zoominfovy >= 2) {
		scale = (g_Vars.currentplayer->zoominfovy - 2) * (1.0f / 20.0f) + 0.1f;
	} else {
		scale = 0.1;
	}

	stage = stageGetCurrent();
	currentPlayerSetScaleBg2Gfx((1 - (1 - stage->unk34) * (1 - scale) * (10.f / 9.0f)) * scale);
}

GLOBAL_ASM(
glabel func0f0bace0
/*  f0bace0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0bace4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0bace8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0bacec:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0bacf0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0bacf4:	0fc240f5 */ 	jal	func0f0903d4
/*  f0bacf8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0bacfc:	0fc24138 */ 	jal	func0f0904e0
/*  f0bad00:	00000000 */ 	nop
/*  f0bad04:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0bad08:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0bad0c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0bad10:	24130f48 */ 	addiu	$s3,$zero,0xf48
/*  f0bad14:	8e4e0284 */ 	lw	$t6,0x284($s2)
.L0f0bad18:
/*  f0bad18:	01d18021 */ 	addu	$s0,$t6,$s1
/*  f0bad1c:	8e040804 */ 	lw	$a0,0x804($s0)
/*  f0bad20:	26100638 */ 	addiu	$s0,$s0,0x638
/*  f0bad24:	50800008 */ 	beqzl	$a0,.L0f0bad48
/*  f0bad28:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0bad2c:	0c00cdfc */ 	jal	func000337f0
/*  f0bad30:	00000000 */ 	nop
/*  f0bad34:	50400004 */ 	beqzl	$v0,.L0f0bad48
/*  f0bad38:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f0bad3c:	0c00cec9 */ 	jal	audioStop
/*  f0bad40:	8e0401cc */ 	lw	$a0,0x1cc($s0)
/*  f0bad44:	263107a4 */ 	addiu	$s1,$s1,0x7a4
.L0f0bad48:
/*  f0bad48:	5633fff3 */ 	bnel	$s1,$s3,.L0f0bad18
/*  f0bad4c:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0bad50:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0bad54:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0bad58:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0bad5c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0bad60:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0bad64:	03e00008 */ 	jr	$ra
/*  f0bad68:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0bad6c
.late_rodata
glabel var7f1ad604
.word func0f0bad6c+0x74 # f0bade0
glabel var7f1ad608
.word func0f0bad6c+0x94 # f0bae00
glabel var7f1ad60c
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad610
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad614
.word func0f0bad6c+0x84 # f0badf0
glabel var7f1ad618
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad61c
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad620
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad624
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad628
.word func0f0bad6c+0x94 # f0bae00
glabel var7f1ad62c
.word func0f0bad6c+0x98 # f0bae04
glabel var7f1ad630
.word func0f0bad6c+0x74 # f0bade0
.text
/*  f0bad6c:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0bad70:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0bad74:	8ca30284 */ 	lw	$v1,0x284($a1)
/*  f0bad78:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0bad7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bad80:	8c621a24 */ 	lw	$v0,0x1a24($v1)
/*  f0bad84:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bad88:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bad8c:	5040005c */ 	beqzl	$v0,.L0f0baf00
/*  f0bad90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bad94:	10410008 */ 	beq	$v0,$at,.L0f0badb8
/*  f0bad98:	3c0e8007 */ 	lui	$t6,%hi(g_PauseMode)
/*  f0bad9c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0bada0:	10410056 */ 	beq	$v0,$at,.L0f0baefc
/*  f0bada4:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0bada8:	50410045 */ 	beql	$v0,$at,.L0f0baec0
/*  f0badac:	8c6d1a28 */ 	lw	$t5,0x1a28($v1)
/*  f0badb0:	10000053 */ 	b	.L0f0baf00
/*  f0badb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0badb8:
/*  f0badb8:	8dce0840 */ 	lw	$t6,%lo(g_PauseMode)($t6)
/*  f0badbc:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f0badc0:	2de1000c */ 	sltiu	$at,$t7,0xc
/*  f0badc4:	1020000f */ 	beqz	$at,.L0f0bae04
/*  f0badc8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0badcc:	3c017f1b */ 	lui	$at,%hi(var7f1ad604)
/*  f0badd0:	002f0821 */ 	addu	$at,$at,$t7
/*  f0badd4:	8c2fd604 */ 	lw	$t7,%lo(var7f1ad604)($at)
/*  f0badd8:	01e00008 */ 	jr	$t7
/*  f0baddc:	00000000 */ 	nop
/*  f0bade0:	0fc41ac8 */ 	jal	soloChoosePauseDialog
/*  f0bade4:	00000000 */ 	nop
/*  f0bade8:	10000006 */ 	b	.L0f0bae04
/*  f0badec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0badf0:	0fc43240 */ 	jal	filemgrConsiderPushingFileSelectDialog
/*  f0badf4:	00000000 */ 	nop
/*  f0badf8:	10000002 */ 	b	.L0f0bae04
/*  f0badfc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bae00:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bae04:
/*  f0bae04:	5080003e */ 	beqzl	$a0,.L0f0baf00
/*  f0bae08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bae0c:	0fc68606 */ 	jal	dtGetData
/*  f0bae10:	00000000 */ 	nop
/*  f0bae14:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0bae18:	0fc5b350 */ 	jal	soloSetPaused
/*  f0bae1c:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0bae20:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0bae24:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0bae28:	8cb90284 */ 	lw	$t9,0x284($a1)
/*  f0bae2c:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0bae30:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f0bae34:	3c028007 */ 	lui	$v0,%hi(g_PauseMode)
/*  f0bae38:	af381a24 */ 	sw	$t8,0x1a24($t9)
/*  f0bae3c:	8c420840 */ 	lw	$v0,%lo(g_PauseMode)($v0)
/*  f0bae40:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bae44:	10410003 */ 	beq	$v0,$at,.L0f0bae54
/*  f0bae48:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0bae4c:	14410017 */ 	bne	$v0,$at,.L0f0baeac
/*  f0bae50:	00000000 */ 	nop
.L0f0bae54:
/*  f0bae54:	8ca804b4 */ 	lw	$t0,0x4b4($a1)
/*  f0bae58:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0bae5c:	15010013 */ 	bne	$t0,$at,.L0f0baeac
/*  f0bae60:	00000000 */ 	nop
/*  f0bae64:	8ca90284 */ 	lw	$t1,0x284($a1)
/*  f0bae68:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0bae6c:	85420028 */ 	lh	$v0,0x28($t2)
/*  f0bae70:	28410016 */ 	slti	$at,$v0,0x16
/*  f0bae74:	14200002 */ 	bnez	$at,.L0f0bae80
/*  f0bae78:	2841001a */ 	slti	$at,$v0,0x1a
/*  f0bae7c:	1420001f */ 	bnez	$at,.L0f0baefc
.L0f0bae80:
/*  f0bae80:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0bae84:	1041001d */ 	beq	$v0,$at,.L0f0baefc
/*  f0bae88:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0bae8c:	5041001c */ 	beql	$v0,$at,.L0f0baf00
/*  f0bae90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bae94:	10600005 */ 	beqz	$v1,.L0f0baeac
/*  f0bae98:	00000000 */ 	nop
/*  f0bae9c:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0baea0:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f0baea4:	55800016 */ 	bnezl	$t4,.L0f0baf00
/*  f0baea8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0baeac:
/*  f0baeac:	0fc5b6c5 */ 	jal	musicStartForMenu
/*  f0baeb0:	00000000 */ 	nop
/*  f0baeb4:	10000012 */ 	b	.L0f0baf00
/*  f0baeb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0baebc:	8c6d1a28 */ 	lw	$t5,0x1a28($v1)
.L0f0baec0:
/*  f0baec0:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f0baec4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0baec8:	ac6f1a28 */ 	sw	$t7,0x1a28($v1)
/*  f0baecc:	8cb80284 */ 	lw	$t8,0x284($a1)
/*  f0baed0:	8f191a28 */ 	lw	$t9,0x1a28($t8)
/*  f0baed4:	2b210014 */ 	slti	$at,$t9,0x14
/*  f0baed8:	54200009 */ 	bnezl	$at,.L0f0baf00
/*  f0baedc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0baee0:	0fc5b350 */ 	jal	soloSetPaused
/*  f0baee4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0baee8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0baeec:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0baef0:	8ca80284 */ 	lw	$t0,0x284($a1)
/*  f0baef4:	0fc5b6cf */ 	jal	func0f16db3c
/*  f0baef8:	ad001a24 */ 	sw	$zero,0x1a24($t0)
.L0f0baefc:
/*  f0baefc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0baf00:
/*  f0baf00:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0baf04:	03e00008 */ 	jr	$ra
/*  f0baf08:	00000000 */ 	nop
);

void currentPlayerPause(s32 mode)
{
	g_PauseMode = mode;

	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
		g_Vars.currentplayer->pausemode = PAUSEMODE_1;
	}
}

void func0f0baf38(void)
{
	if (g_Vars.currentplayer->pausemode == PAUSEMODE_3) {
		soloSetPaused(0);
		func0f16db3c();
		g_Vars.currentplayer->pausemode = PAUSEMODE_UNPAUSED;
	}
}

GLOBAL_ASM(
glabel func0f0baf84
/*  f0baf84:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0baf88:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0baf8c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0baf90:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0baf94:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0baf98:	8dcf1a24 */ 	lw	$t7,0x1a24($t6)
/*  f0baf9c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0bafa0:	51e00026 */ 	beqzl	$t7,.L0f0bb03c
/*  f0bafa4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0bafa8:	0fc59e66 */ 	jal	func0f167998
/*  f0bafac:	00000000 */ 	nop
/*  f0bafb0:	3c014120 */ 	lui	$at,0x4120
/*  f0bafb4:	44812000 */ 	mtc1	$at,$f4
/*  f0bafb8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0bafbc:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0bafc0:	3c014396 */ 	lui	$at,0x4396
/*  f0bafc4:	44813000 */ 	mtc1	$at,$f6
/*  f0bafc8:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0bafcc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bafd0:	44814000 */ 	mtc1	$at,$f8
/*  f0bafd4:	8f061848 */ 	lw	$a2,0x1848($t8)
/*  f0bafd8:	3c073fba */ 	lui	$a3,0x3fba
/*  f0bafdc:	34e72e8c */ 	ori	$a3,$a3,0x2e8c
/*  f0bafe0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bafe4:	27a5003a */ 	addiu	$a1,$sp,0x3a
/*  f0bafe8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0bafec:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0baff0:	0c001289 */ 	jal	func00004a24
/*  f0baff4:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0baff8:	3c190103 */ 	lui	$t9,0x103
/*  f0baffc:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0bb000:	02001025 */ 	or	$v0,$s0,$zero
/*  f0bb004:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0bb008:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0bb00c:	3c018000 */ 	lui	$at,0x8000
/*  f0bb010:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb014:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f0bb018:	01014821 */ 	addu	$t1,$t0,$at
/*  f0bb01c:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0bb020:	354a000e */ 	ori	$t2,$t2,0xe
/*  f0bb024:	02001825 */ 	or	$v1,$s0,$zero
/*  f0bb028:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0bb02c:	97ab003a */ 	lhu	$t3,0x3a($sp)
/*  f0bb030:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb034:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0bb038:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0bb03c:
/*  f0bb03c:	02001025 */ 	or	$v0,$s0,$zero
/*  f0bb040:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0bb044:	03e00008 */ 	jr	$ra
/*  f0bb048:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel fadeDraw
/*  f0bb04c:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0bb050:	c7ac0080 */ 	lwc1	$f12,0x80($sp)
/*  f0bb054:	44802000 */ 	mtc1	$zero,$f4
/*  f0bb058:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0bb05c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0bb060:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0bb064:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0bb068:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f0bb06c:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f0bb070:	45000098 */ 	bc1f	.L0f0bb2d4
/*  f0bb074:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0bb078:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f0bb07c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0bb080:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0bb084:	02001825 */ 	or	$v1,$s0,$zero
/*  f0bb088:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb08c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0bb090:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f0bb094:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bb098:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0bb09c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0bb0a0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0bb0a4:	37180602 */ 	ori	$t8,$t8,0x602
/*  f0bb0a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb0ac:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f0bb0b0:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f0bb0b4:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0bb0b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0bb0bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb0c0:	3c08ba00 */ 	lui	$t0,0xba00
/*  f0bb0c4:	35081301 */ 	ori	$t0,$t0,0x1301
/*  f0bb0c8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bb0cc:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f0bb0d0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f0bb0d4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb0d8:	3c09b900 */ 	lui	$t1,0xb900
/*  f0bb0dc:	35290002 */ 	ori	$t1,$t1,0x2
/*  f0bb0e0:	02001025 */ 	or	$v0,$s0,$zero
/*  f0bb0e4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f0bb0e8:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f0bb0ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb0f0:	3c0aba00 */ 	lui	$t2,0xba00
/*  f0bb0f4:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f0bb0f8:	02001825 */ 	or	$v1,$s0,$zero
/*  f0bb0fc:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f0bb100:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0bb104:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0bb108:	356b0c02 */ 	ori	$t3,$t3,0xc02
/*  f0bb10c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb110:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*  f0bb114:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f0bb118:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0bb11c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bb120:	3c01437f */ 	lui	$at,0x437f
/*  f0bb124:	44813000 */ 	mtc1	$at,$f6
/*  f0bb128:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb12c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0bb130:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f0bb134:	240e0c00 */ 	addiu	$t6,$zero,0xc00
/*  f0bb138:	02002825 */ 	or	$a1,$s0,$zero
/*  f0bb13c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f0bb140:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0bb144:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb148:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0bb14c:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f0bb150:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f0bb154:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bb158:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0bb15c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f0bb160:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb164:	3c18b900 */ 	lui	$t8,0xb900
/*  f0bb168:	3c190050 */ 	lui	$t9,0x50
/*  f0bb16c:	37394340 */ 	ori	$t9,$t9,0x4340
/*  f0bb170:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0bb174:	02001025 */ 	or	$v0,$s0,$zero
/*  f0bb178:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0bb17c:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f0bb180:	3c09fffd */ 	lui	$t1,0xfffd
/*  f0bb184:	3c08fcff */ 	lui	$t0,0xfcff
/*  f0bb188:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f0bb18c:	3529f6fb */ 	ori	$t1,$t1,0xf6fb
/*  f0bb190:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb194:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0bb198:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f0bb19c:	02001825 */ 	or	$v1,$s0,$zero
/*  f0bb1a0:	3c0afa00 */ 	lui	$t2,0xfa00
/*  f0bb1a4:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0bb1a8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0bb1ac:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f0bb1b0:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f0bb1b4:	30e800ff */ 	andi	$t0,$a3,0xff
/*  f0bb1b8:	000c6e00 */ 	sll	$t5,$t4,0x18
/*  f0bb1bc:	440c5000 */ 	mfc1	$t4,$f10
/*  f0bb1c0:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0bb1c4:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f0bb1c8:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f0bb1cc:	00084a00 */ 	sll	$t1,$t0,0x8
/*  f0bb1d0:	03295025 */ 	or	$t2,$t9,$t1
/*  f0bb1d4:	318e00ff */ 	andi	$t6,$t4,0xff
/*  f0bb1d8:	014e7825 */ 	or	$t7,$t2,$t6
/*  f0bb1dc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0bb1e0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb1e4:	afb0003c */ 	sw	$s0,0x3c($sp)
/*  f0bb1e8:	0c002f22 */ 	jal	viGetViewX
/*  f0bb1ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb1f0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0bb1f4:	a7a20026 */ 	sh	$v0,0x26($sp)
/*  f0bb1f8:	0c002f44 */ 	jal	viGetViewTop
/*  f0bb1fc:	a7a20028 */ 	sh	$v0,0x28($sp)
/*  f0bb200:	0c002f26 */ 	jal	viGetViewY
/*  f0bb204:	a7a2002a */ 	sh	$v0,0x2a($sp)
/*  f0bb208:	87ab002a */ 	lh	$t3,0x2a($sp)
/*  f0bb20c:	87ad0028 */ 	lh	$t5,0x28($sp)
/*  f0bb210:	87b80026 */ 	lh	$t8,0x26($sp)
/*  f0bb214:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f0bb218:	318a03ff */ 	andi	$t2,$t4,0x3ff
/*  f0bb21c:	01b84021 */ 	addu	$t0,$t5,$t8
/*  f0bb220:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f0bb224:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f0bb228:	3c01f600 */ 	lui	$at,0xf600
/*  f0bb22c:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0bb230:	01c17825 */ 	or	$t7,$t6,$at
/*  f0bb234:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f0bb238:	01e96825 */ 	or	$t5,$t7,$t1
/*  f0bb23c:	0c002f40 */ 	jal	viGetViewLeft
/*  f0bb240:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0bb244:	0c002f44 */ 	jal	viGetViewTop
/*  f0bb248:	a7a2002a */ 	sh	$v0,0x2a($sp)
/*  f0bb24c:	87ab002a */ 	lh	$t3,0x2a($sp)
/*  f0bb250:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f0bb254:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f0bb258:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f0bb25c:	000c5380 */ 	sll	$t2,$t4,0xe
/*  f0bb260:	0008c880 */ 	sll	$t9,$t0,0x2
/*  f0bb264:	032a7025 */ 	or	$t6,$t9,$t2
/*  f0bb268:	02001825 */ 	or	$v1,$s0,$zero
/*  f0bb26c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb270:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0bb274:	3c09e700 */ 	lui	$t1,0xe700
/*  f0bb278:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bb27c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0bb280:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0bb284:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb288:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0bb28c:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f0bb290:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f0bb294:	02002825 */ 	or	$a1,$s0,$zero
/*  f0bb298:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0bb29c:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0bb2a0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bb2a4:	3c08ba00 */ 	lui	$t0,0xba00
/*  f0bb2a8:	35081301 */ 	ori	$t0,$t0,0x1301
/*  f0bb2ac:	3c0b0008 */ 	lui	$t3,0x8
/*  f0bb2b0:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bb2b4:	acab0004 */ 	sw	$t3,0x4($a1)
/*  f0bb2b8:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f0bb2bc:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0bb2c0:	358c1001 */ 	ori	$t4,$t4,0x1001
/*  f0bb2c4:	3c190001 */ 	lui	$t9,0x1
/*  f0bb2c8:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f0bb2cc:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f0bb2d0:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f0bb2d4:
/*  f0bb2d4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0bb2d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f0bb2dc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0bb2e0:	03e00008 */ 	jr	$ra
/*  f0bb2e4:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

Gfx *currentPlayerDrawFade(Gfx *gdl)
{
	return fadeDraw(gdl,
			g_Vars.currentplayer->colourscreenred,
			g_Vars.currentplayer->colourscreengreen,
			g_Vars.currentplayer->colourscreenblue,
			g_Vars.currentplayer->colourscreenfrac);
}

void currentPlayerSetFadeColour(s32 r, s32 g, s32 b, f32 frac)
{
	g_Vars.currentplayer->colourscreenred = r;
	g_Vars.currentplayer->colourscreengreen = g;
	g_Vars.currentplayer->colourscreenblue = b;
	g_Vars.currentplayer->colourscreenfrac = frac;
}

void currentPlayerAdjustFade(f32 maxfadetime, s32 r, s32 g, s32 b, f32 frac)
{
	g_Vars.currentplayer->colourfadetime60 = 0;
	g_Vars.currentplayer->colourfadetimemax60 = maxfadetime;
	g_Vars.currentplayer->colourfaderedold = g_Vars.currentplayer->colourscreenred;
	g_Vars.currentplayer->colourfaderednew = r;
	g_Vars.currentplayer->colourfadegreenold = g_Vars.currentplayer->colourscreengreen;
	g_Vars.currentplayer->colourfadegreennew = g;
	g_Vars.currentplayer->colourfadeblueold = g_Vars.currentplayer->colourscreenblue;
	g_Vars.currentplayer->colourfadebluenew = b;
	g_Vars.currentplayer->colourfadefracold = g_Vars.currentplayer->colourscreenfrac;
	g_Vars.currentplayer->colourfadefracnew = frac;
}

void currentPlayerSetFadeFrac(f32 maxfadetime, f32 frac)
{
	currentPlayerAdjustFade(maxfadetime,
			g_Vars.currentplayer->colourscreenred,
			g_Vars.currentplayer->colourscreengreen,
			g_Vars.currentplayer->colourscreenblue,
			frac);
}

bool currentPlayerIsFadeComplete(void)
{
	return g_Vars.currentplayer->colourfadetimemax60 < 0;
}

GLOBAL_ASM(
glabel func0f0bb42c
/*  f0bb42c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bb430:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bb434:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb438:	44803000 */ 	mtc1	$zero,$f6
/*  f0bb43c:	c44402ec */ 	lwc1	$f4,0x2ec($v0)
/*  f0bb440:	4604303e */ 	c.le.s	$f6,$f4
/*  f0bb444:	00000000 */ 	nop
/*  f0bb448:	4500004a */ 	bc1f	.L0f0bb574
/*  f0bb44c:	00000000 */ 	nop
/*  f0bb450:	c44802e8 */ 	lwc1	$f8,0x2e8($v0)
/*  f0bb454:	c4ca004c */ 	lwc1	$f10,0x4c($a2)
/*  f0bb458:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f0bb45c:	e45002e8 */ 	swc1	$f16,0x2e8($v0)
/*  f0bb460:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb464:	c44202e8 */ 	lwc1	$f2,0x2e8($v0)
/*  f0bb468:	c44002ec */ 	lwc1	$f0,0x2ec($v0)
/*  f0bb46c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0bb470:	00000000 */ 	nop
/*  f0bb474:	45020031 */ 	bc1fl	.L0f0bb53c
/*  f0bb478:	c44a030c */ 	lwc1	$f10,0x30c($v0)
/*  f0bb47c:	46001303 */ 	div.s	$f12,$f2,$f0
/*  f0bb480:	c44e0308 */ 	lwc1	$f14,0x308($v0)
/*  f0bb484:	c452030c */ 	lwc1	$f18,0x30c($v0)
/*  f0bb488:	460e9101 */ 	sub.s	$f4,$f18,$f14
/*  f0bb48c:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0bb490:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f0bb494:	e44802e4 */ 	swc1	$f8,0x2e4($v0)
/*  f0bb498:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb49c:	8c4302f0 */ 	lw	$v1,0x2f0($v0)
/*  f0bb4a0:	8c4e02f4 */ 	lw	$t6,0x2f4($v0)
/*  f0bb4a4:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f0bb4a8:	448f5000 */ 	mtc1	$t7,$f10
/*  f0bb4ac:	00000000 */ 	nop
/*  f0bb4b0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0bb4b4:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*  f0bb4b8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0bb4bc:	44192000 */ 	mfc1	$t9,$f4
/*  f0bb4c0:	00000000 */ 	nop
/*  f0bb4c4:	00794021 */ 	addu	$t0,$v1,$t9
/*  f0bb4c8:	ac4802d8 */ 	sw	$t0,0x2d8($v0)
/*  f0bb4cc:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb4d0:	8c4402f8 */ 	lw	$a0,0x2f8($v0)
/*  f0bb4d4:	8c4902fc */ 	lw	$t1,0x2fc($v0)
/*  f0bb4d8:	01245023 */ 	subu	$t2,$t1,$a0
/*  f0bb4dc:	448a3000 */ 	mtc1	$t2,$f6
/*  f0bb4e0:	00000000 */ 	nop
/*  f0bb4e4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0bb4e8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0bb4ec:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0bb4f0:	440c8000 */ 	mfc1	$t4,$f16
/*  f0bb4f4:	00000000 */ 	nop
/*  f0bb4f8:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f0bb4fc:	ac4d02dc */ 	sw	$t5,0x2dc($v0)
/*  f0bb500:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb504:	8c450300 */ 	lw	$a1,0x300($v0)
/*  f0bb508:	8c4e0304 */ 	lw	$t6,0x304($v0)
/*  f0bb50c:	01c57823 */ 	subu	$t7,$t6,$a1
/*  f0bb510:	448f9000 */ 	mtc1	$t7,$f18
/*  f0bb514:	00000000 */ 	nop
/*  f0bb518:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0bb51c:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0bb520:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0bb524:	44194000 */ 	mfc1	$t9,$f8
/*  f0bb528:	00000000 */ 	nop
/*  f0bb52c:	00b94021 */ 	addu	$t0,$a1,$t9
/*  f0bb530:	03e00008 */ 	jr	$ra
/*  f0bb534:	ac4802e0 */ 	sw	$t0,0x2e0($v0)
/*  f0bb538:	c44a030c */ 	lwc1	$f10,0x30c($v0)
.L0f0bb53c:
/*  f0bb53c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bb540:	44818000 */ 	mtc1	$at,$f16
/*  f0bb544:	e44a02e4 */ 	swc1	$f10,0x2e4($v0)
/*  f0bb548:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb54c:	8c4902f4 */ 	lw	$t1,0x2f4($v0)
/*  f0bb550:	ac4902d8 */ 	sw	$t1,0x2d8($v0)
/*  f0bb554:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb558:	8c4a02fc */ 	lw	$t2,0x2fc($v0)
/*  f0bb55c:	ac4a02dc */ 	sw	$t2,0x2dc($v0)
/*  f0bb560:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bb564:	8c4b0304 */ 	lw	$t3,0x304($v0)
/*  f0bb568:	ac4b02e0 */ 	sw	$t3,0x2e0($v0)
/*  f0bb56c:	8ccc0284 */ 	lw	$t4,0x284($a2)
/*  f0bb570:	e59002ec */ 	swc1	$f16,0x2ec($t4)
.L0f0bb574:
/*  f0bb574:	03e00008 */ 	jr	$ra
/*  f0bb578:	00000000 */ 	nop
);

void currentPlayerStartChrFade(f32 duration60, f32 targetfrac)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;

	if (chr) {
		g_Vars.currentplayer->bondfadetime60 = 0;
		g_Vars.currentplayer->bondfadetimemax60 = duration60;
		g_Vars.currentplayer->bondfadefracold = chr->fadealpha / 255.0f;
		g_Vars.currentplayer->bondfadefracnew = targetfrac;
	}
}

void currentPlayerTickChrFade(void)
{
	if (g_Vars.currentplayer->bondfadetimemax60 >= 0) {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;
		f32 frac;

		g_Vars.currentplayer->bondfadetime60 += g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->bondfadetime60 < g_Vars.currentplayer->bondfadetimemax60) {
			frac = g_Vars.currentplayer->bondfadefracold
				+ (g_Vars.currentplayer->bondfadefracnew - g_Vars.currentplayer->bondfadefracold)
				* g_Vars.currentplayer->bondfadetime60
				/ g_Vars.currentplayer->bondfadetimemax60;
		} else {
			frac = g_Vars.currentplayer->bondfadefracnew;
			g_Vars.currentplayer->bondfadetimemax60 = -1;
		}

		if (chr) {
			chr->fadealpha = (s8)(frac * 255);
		}
	}
}

void func0f0bb69c(void)
{
	switch (g_Vars.currentplayer->healthshowmode) {
	case HEALTHSHOWMODE_HIDDEN:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->bondhealth;
		g_Vars.currentplayer->oldarmour = func0f0c21a4();
		break;
	case HEALTHSHOWMODE_OPENING:
	case HEALTHSHOWMODE_PREVIOUS:
		break;
	case HEALTHSHOWMODE_UPDATING:
	case HEALTHSHOWMODE_CURRENT:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->apparenthealth;
		g_Vars.currentplayer->oldarmour = g_Vars.currentplayer->apparentarmour;
		break;
	case HEALTHSHOWMODE_CLOSING:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->bondhealth;
		g_Vars.currentplayer->oldarmour = func0f0c21a4();
		break;
	}

	switch (g_Vars.currentplayer->healthshowmode) {
	case HEALTHSHOWMODE_HIDDEN:
		g_Vars.currentplayer->healthshowtime = 0;
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_OPENING;
		break;
	case HEALTHSHOWMODE_OPENING:
	case HEALTHSHOWMODE_PREVIOUS:
		break;
	case HEALTHSHOWMODE_UPDATING:
	case HEALTHSHOWMODE_CURRENT:
		g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].unk04;
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_UPDATING;
		break;
	case HEALTHSHOWMODE_CLOSING:
		g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].openduration * currentPlayerGetHealthBarHeightFrac();
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_OPENING;
		break;
	}
}

GLOBAL_ASM(
glabel func0f0bb814
.late_rodata
glabel var7f1ad664
.word func0f0bb814+0x2dc # f0bbaf0
glabel var7f1ad668
.word func0f0bb814+0x350 # f0bbb64
glabel var7f1ad66c
.word func0f0bb814+0x3e0 # f0bbbf4
glabel var7f1ad670
.word func0f0bb814+0x53c # f0bbd50
glabel var7f1ad674
.word func0f0bb814+0x640 # f0bbe54
.text
/*  f0bb814:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bb818:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bb81c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bb820:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0bb824:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bb828:	44802000 */ 	mtc1	$zero,$f4
/*  f0bb82c:	c44000f4 */ 	lwc1	$f0,0xf4($v0)
/*  f0bb830:	4600203e */ 	c.le.s	$f4,$f0
/*  f0bb834:	00000000 */ 	nop
/*  f0bb838:	45000078 */ 	bc1f	.L0f0bba1c
/*  f0bb83c:	00000000 */ 	nop
/*  f0bb840:	44803000 */ 	mtc1	$zero,$f6
/*  f0bb844:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f0bb848:	46003032 */ 	c.eq.s	$f6,$f0
/*  f0bb84c:	00000000 */ 	nop
/*  f0bb850:	4502001d */ 	bc1fl	.L0f0bb8c8
/*  f0bb854:	8c4900d8 */ 	lw	$t1,0xd8($v0)
/*  f0bb858:	0fc2af1d */ 	jal	currentPlayerSetGunSightVisible
/*  f0bb85c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bb860:	0fc30865 */ 	jal	currentPlayerGetHealth
/*  f0bb864:	00000000 */ 	nop
/*  f0bb868:	3c014100 */ 	lui	$at,0x4100
/*  f0bb86c:	44814000 */ 	mtc1	$at,$f8
/*  f0bb870:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bb874:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bb878:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0bb87c:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0bb880:	24190007 */ 	addiu	$t9,$zero,0x7
/*  f0bb884:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0bb888:	440f2000 */ 	mfc1	$t7,$f4
/*  f0bb88c:	00000000 */ 	nop
/*  f0bb890:	af0f193c */ 	sw	$t7,0x193c($t8)
/*  f0bb894:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bb898:	8c43193c */ 	lw	$v1,0x193c($v0)
/*  f0bb89c:	28610008 */ 	slti	$at,$v1,0x8
/*  f0bb8a0:	14200004 */ 	bnez	$at,.L0f0bb8b4
/*  f0bb8a4:	00000000 */ 	nop
/*  f0bb8a8:	ac59193c */ 	sw	$t9,0x193c($v0)
/*  f0bb8ac:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bb8b0:	8c43193c */ 	lw	$v1,0x193c($v0)
.L0f0bb8b4:
/*  f0bb8b4:	04630004 */ 	bgezl	$v1,.L0f0bb8c8
/*  f0bb8b8:	8c4900d8 */ 	lw	$t1,0xd8($v0)
/*  f0bb8bc:	ac40193c */ 	sw	$zero,0x193c($v0)
/*  f0bb8c0:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bb8c4:	8c4900d8 */ 	lw	$t1,0xd8($v0)
.L0f0bb8c8:
/*  f0bb8c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bb8cc:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f0bb8d0:	15200044 */ 	bnez	$t1,.L0f0bb9e4
/*  f0bb8d4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0bb8d8:	8c4a193c */ 	lw	$t2,0x193c($v0)
/*  f0bb8dc:	2405001c */ 	addiu	$a1,$zero,0x1c
/*  f0bb8e0:	3c048007 */ 	lui	$a0,%hi(var80070844)
/*  f0bb8e4:	01450019 */ 	multu	$t2,$a1
/*  f0bb8e8:	24840844 */ 	addiu	$a0,$a0,%lo(var80070844)
/*  f0bb8ec:	c44000f4 */ 	lwc1	$f0,0xf4($v0)
/*  f0bb8f0:	00005812 */ 	mflo	$t3
/*  f0bb8f4:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f0bb8f8:	c5860008 */ 	lwc1	$f6,0x8($t4)
/*  f0bb8fc:	4606003e */ 	c.le.s	$f0,$f6
/*  f0bb900:	00000000 */ 	nop
/*  f0bb904:	45020038 */ 	bc1fl	.L0f0bb9e8
/*  f0bb908:	44813000 */ 	mtc1	$at,$f6
/*  f0bb90c:	8c4d1a24 */ 	lw	$t5,0x1a24($v0)
/*  f0bb910:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0bb914:	44816000 */ 	mtc1	$at,$f12
/*  f0bb918:	55a00004 */ 	bnezl	$t5,.L0f0bb92c
/*  f0bb91c:	c502005c */ 	lwc1	$f2,0x5c($t0)
/*  f0bb920:	10000002 */ 	b	.L0f0bb92c
/*  f0bb924:	c502004c */ 	lwc1	$f2,0x4c($t0)
/*  f0bb928:	c502005c */ 	lwc1	$f2,0x5c($t0)
.L0f0bb92c:
/*  f0bb92c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0bb930:	00000000 */ 	nop
/*  f0bb934:	45020003 */ 	bc1fl	.L0f0bb944
/*  f0bb938:	46020200 */ 	add.s	$f8,$f0,$f2
/*  f0bb93c:	46006086 */ 	mov.s	$f2,$f12
/*  f0bb940:	46020200 */ 	add.s	$f8,$f0,$f2
.L0f0bb944:
/*  f0bb944:	e44800f4 */ 	swc1	$f8,0xf4($v0)
/*  f0bb948:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bb94c:	8c4e193c */ 	lw	$t6,0x193c($v0)
/*  f0bb950:	c44000f4 */ 	lwc1	$f0,0xf4($v0)
/*  f0bb954:	01c50019 */ 	multu	$t6,$a1
/*  f0bb958:	00007812 */ 	mflo	$t7
/*  f0bb95c:	008f1821 */ 	addu	$v1,$a0,$t7
/*  f0bb960:	c46c0000 */ 	lwc1	$f12,0x0($v1)
/*  f0bb964:	4600603e */ 	c.le.s	$f12,$f0
/*  f0bb968:	00000000 */ 	nop
/*  f0bb96c:	4500002b */ 	bc1f	.L0f0bba1c
/*  f0bb970:	00000000 */ 	nop
/*  f0bb974:	c4700008 */ 	lwc1	$f16,0x8($v1)
/*  f0bb978:	4610003e */ 	c.le.s	$f0,$f16
/*  f0bb97c:	00000000 */ 	nop
/*  f0bb980:	45000026 */ 	bc1f	.L0f0bba1c
/*  f0bb984:	00000000 */ 	nop
/*  f0bb988:	460c0081 */ 	sub.s	$f2,$f0,$f12
/*  f0bb98c:	c46e0004 */ 	lwc1	$f14,0x4($v1)
/*  f0bb990:	460c8481 */ 	sub.s	$f18,$f16,$f12
/*  f0bb994:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0bb998:	00000000 */ 	nop
/*  f0bb99c:	45020006 */ 	bc1fl	.L0f0bb9b8
/*  f0bb9a0:	46029201 */ 	sub.s	$f8,$f18,$f2
/*  f0bb9a4:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0bb9a8:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f0bb9ac:	10000006 */ 	b	.L0f0bb9c8
/*  f0bb9b0:	460e2003 */ 	div.s	$f0,$f4,$f14
/*  f0bb9b4:	46029201 */ 	sub.s	$f8,$f18,$f2
.L0f0bb9b8:
/*  f0bb9b8:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f0bb9bc:	460e9101 */ 	sub.s	$f4,$f18,$f14
/*  f0bb9c0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0bb9c4:	46045003 */ 	div.s	$f0,$f10,$f4
.L0f0bb9c8:
/*  f0bb9c8:	44070000 */ 	mfc1	$a3,$f0
/*  f0bb9cc:	8c640010 */ 	lw	$a0,0x10($v1)
/*  f0bb9d0:	8c650014 */ 	lw	$a1,0x14($v1)
/*  f0bb9d4:	0fc2ecc8 */ 	jal	currentPlayerSetFadeColour
/*  f0bb9d8:	8c660018 */ 	lw	$a2,0x18($v1)
/*  f0bb9dc:	1000000f */ 	b	.L0f0bba1c
/*  f0bb9e0:	00000000 */ 	nop
.L0f0bb9e4:
/*  f0bb9e4:	44813000 */ 	mtc1	$at,$f6
.L0f0bb9e8:
/*  f0bb9e8:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f0bb9ec:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0bb9f0:	0fc2ecc8 */ 	jal	currentPlayerSetFadeColour
/*  f0bb9f4:	e44600f4 */ 	swc1	$f6,0xf4($v0)
/*  f0bb9f8:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bb9fc:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bba00:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0bba04:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f0bba08:	8f1900d8 */ 	lw	$t9,0xd8($t8)
/*  f0bba0c:	17200003 */ 	bnez	$t9,.L0f0bba1c
/*  f0bba10:	00000000 */ 	nop
/*  f0bba14:	0fc2af1d */ 	jal	currentPlayerSetGunSightVisible
/*  f0bba18:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bba1c:
/*  f0bba1c:	0fc305f3 */ 	jal	currentPlayerIsHealthVisible
/*  f0bba20:	00000000 */ 	nop
/*  f0bba24:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bba28:	1040012a */ 	beqz	$v0,.L0f0bbed4
/*  f0bba2c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bba30:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bba34:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bba38:	8c4900fc */ 	lw	$t1,0xfc($v0)
/*  f0bba3c:	5521001f */ 	bnel	$t1,$at,.L0f0bbabc
/*  f0bba40:	8c4e00d8 */ 	lw	$t6,0xd8($v0)
/*  f0bba44:	0fc30865 */ 	jal	currentPlayerGetHealth
/*  f0bba48:	00000000 */ 	nop
/*  f0bba4c:	0fc30869 */ 	jal	func0f0c21a4
/*  f0bba50:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0bba54:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*  f0bba58:	3c014100 */ 	lui	$at,0x4100
/*  f0bba5c:	44812000 */ 	mtc1	$at,$f4
/*  f0bba60:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0bba64:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bba68:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bba6c:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0bba70:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0bba74:	240d0007 */ 	addiu	$t5,$zero,0x7
/*  f0bba78:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0bba7c:	440b4000 */ 	mfc1	$t3,$f8
/*  f0bba80:	00000000 */ 	nop
/*  f0bba84:	ad8b1924 */ 	sw	$t3,0x1924($t4)
/*  f0bba88:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bba8c:	8c431924 */ 	lw	$v1,0x1924($v0)
/*  f0bba90:	28610008 */ 	slti	$at,$v1,0x8
/*  f0bba94:	14200004 */ 	bnez	$at,.L0f0bbaa8
/*  f0bba98:	00000000 */ 	nop
/*  f0bba9c:	ac4d1924 */ 	sw	$t5,0x1924($v0)
/*  f0bbaa0:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbaa4:	8c431924 */ 	lw	$v1,0x1924($v0)
.L0f0bbaa8:
/*  f0bbaa8:	04630004 */ 	bgezl	$v1,.L0f0bbabc
/*  f0bbaac:	8c4e00d8 */ 	lw	$t6,0xd8($v0)
/*  f0bbab0:	ac401924 */ 	sw	$zero,0x1924($v0)
/*  f0bbab4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbab8:	8c4e00d8 */ 	lw	$t6,0xd8($v0)
.L0f0bbabc:
/*  f0bbabc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bbac0:	55c00100 */ 	bnezl	$t6,.L0f0bbec4
/*  f0bbac4:	44814000 */ 	mtc1	$at,$f8
/*  f0bbac8:	8c4f00fc */ 	lw	$t7,0xfc($v0)
/*  f0bbacc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0bbad0:	2f010005 */ 	sltiu	$at,$t8,0x5
/*  f0bbad4:	102000ff */ 	beqz	$at,.L0f0bbed4
/*  f0bbad8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bbadc:	3c017f1b */ 	lui	$at,%hi(var7f1ad664)
/*  f0bbae0:	00380821 */ 	addu	$at,$at,$t8
/*  f0bbae4:	8c38d664 */ 	lw	$t8,%lo(var7f1ad664)($at)
/*  f0bbae8:	03000008 */ 	jr	$t8
/*  f0bbaec:	00000000 */ 	nop
/*  f0bbaf0:	c44a00e4 */ 	lwc1	$f10,0xe4($v0)
/*  f0bbaf4:	3c0a8007 */ 	lui	$t2,%hi(g_HealthDamageTypes)
/*  f0bbaf8:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f0bbafc:	e44a00ec */ 	swc1	$f10,0xec($v0)
/*  f0bbb00:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbb04:	c44400e8 */ 	lwc1	$f4,0xe8($v0)
/*  f0bbb08:	e44400f0 */ 	swc1	$f4,0xf0($v0)
/*  f0bbb0c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbb10:	c5080010 */ 	lwc1	$f8,0x10($t0)
/*  f0bbb14:	c44600f8 */ 	lwc1	$f6,0xf8($v0)
/*  f0bbb18:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0bbb1c:	e44a00f8 */ 	swc1	$f10,0xf8($v0)
/*  f0bbb20:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbb24:	8c591924 */ 	lw	$t9,0x1924($v0)
/*  f0bbb28:	c44400f8 */ 	lwc1	$f4,0xf8($v0)
/*  f0bbb2c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0bbb30:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0bbb34:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0bbb38:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0bbb3c:	8d4a0924 */ 	lw	$t2,%lo(g_HealthDamageTypes)($t2)
/*  f0bbb40:	448a3000 */ 	mtc1	$t2,$f6
/*  f0bbb44:	00000000 */ 	nop
/*  f0bbb48:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0bbb4c:	4604403e */ 	c.le.s	$f8,$f4
/*  f0bbb50:	00000000 */ 	nop
/*  f0bbb54:	450200e0 */ 	bc1fl	.L0f0bbed8
/*  f0bbb58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bbb5c:	100000dd */ 	b	.L0f0bbed4
/*  f0bbb60:	ac4b00fc */ 	sw	$t3,0xfc($v0)
/*  f0bbb64:	c44a00e4 */ 	lwc1	$f10,0xe4($v0)
/*  f0bbb68:	e44a00ec */ 	swc1	$f10,0xec($v0)
/*  f0bbb6c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbb70:	c44600e8 */ 	lwc1	$f6,0xe8($v0)
/*  f0bbb74:	e44600f0 */ 	swc1	$f6,0xf0($v0)
/*  f0bbb78:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbb7c:	c5080010 */ 	lwc1	$f8,0x10($t0)
/*  f0bbb80:	c44400f8 */ 	lwc1	$f4,0xf8($v0)
/*  f0bbb84:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0bbb88:	0fc3c2fb */ 	jal	currentPlayerIsMenuOpenInSoloOrMp
/*  f0bbb8c:	e44a00f8 */ 	swc1	$f10,0xf8($v0)
/*  f0bbb90:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bbb94:	10400004 */ 	beqz	$v0,.L0f0bbba8
/*  f0bbb98:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bbb9c:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0bbba0:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0bbba4:	adac00fc */ 	sw	$t4,0xfc($t5)
.L0f0bbba8:
/*  f0bbba8:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbbac:	3c188007 */ 	lui	$t8,%hi(g_HealthDamageTypes+0x4)
/*  f0bbbb0:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0bbbb4:	8c4e1924 */ 	lw	$t6,0x1924($v0)
/*  f0bbbb8:	c44600f8 */ 	lwc1	$f6,0xf8($v0)
/*  f0bbbbc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0bbbc0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0bbbc4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bbbc8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0bbbcc:	8f180928 */ 	lw	$t8,%lo(g_HealthDamageTypes+0x4)($t8)
/*  f0bbbd0:	44982000 */ 	mtc1	$t8,$f4
/*  f0bbbd4:	00000000 */ 	nop
/*  f0bbbd8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0bbbdc:	4606403e */ 	c.le.s	$f8,$f6
/*  f0bbbe0:	00000000 */ 	nop
/*  f0bbbe4:	450200bc */ 	bc1fl	.L0f0bbed8
/*  f0bbbe8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bbbec:	100000b9 */ 	b	.L0f0bbed4
/*  f0bbbf0:	ac5900fc */ 	sw	$t9,0xfc($v0)
/*  f0bbbf4:	c44a00f8 */ 	lwc1	$f10,0xf8($v0)
/*  f0bbbf8:	c5040010 */ 	lwc1	$f4,0x10($t0)
/*  f0bbbfc:	3c0b8007 */ 	lui	$t3,%hi(g_HealthDamageTypes)
/*  f0bbc00:	256b0924 */ 	addiu	$t3,$t3,%lo(g_HealthDamageTypes)
/*  f0bbc04:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0bbc08:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bbc0c:	e44600f8 */ 	swc1	$f6,0xf8($v0)
/*  f0bbc10:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbc14:	8c491924 */ 	lw	$t1,0x1924($v0)
/*  f0bbc18:	c44a00f8 */ 	lwc1	$f10,0xf8($v0)
/*  f0bbc1c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0bbc20:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0bbc24:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bbc28:	014b1821 */ 	addu	$v1,$t2,$t3
/*  f0bbc2c:	8c6c0004 */ 	lw	$t4,0x4($v1)
/*  f0bbc30:	8c6d0008 */ 	lw	$t5,0x8($v1)
/*  f0bbc34:	448c4000 */ 	mtc1	$t4,$f8
/*  f0bbc38:	448d2000 */ 	mtc1	$t5,$f4
/*  f0bbc3c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f0bbc40:	44804000 */ 	mtc1	$zero,$f8
/*  f0bbc44:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0bbc48:	46005301 */ 	sub.s	$f12,$f10,$f0
/*  f0bbc4c:	46003381 */ 	sub.s	$f14,$f6,$f0
/*  f0bbc50:	44810000 */ 	mtc1	$at,$f0
/*  f0bbc54:	460e6403 */ 	div.s	$f16,$f12,$f14
/*  f0bbc58:	4608803c */ 	c.lt.s	$f16,$f8
/*  f0bbc5c:	00000000 */ 	nop
/*  f0bbc60:	45020004 */ 	bc1fl	.L0f0bbc74
/*  f0bbc64:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0bbc68:	44808000 */ 	mtc1	$zero,$f16
/*  f0bbc6c:	00000000 */ 	nop
/*  f0bbc70:	4610003c */ 	c.lt.s	$f0,$f16
.L0f0bbc74:
/*  f0bbc74:	00000000 */ 	nop
/*  f0bbc78:	45000002 */ 	bc1f	.L0f0bbc84
/*  f0bbc7c:	00000000 */ 	nop
/*  f0bbc80:	46000406 */ 	mov.s	$f16,$f0
.L0f0bbc84:
/*  f0bbc84:	0fc3c2fb */ 	jal	currentPlayerIsMenuOpenInSoloOrMp
/*  f0bbc88:	e7b00028 */ 	swc1	$f16,0x28($sp)
/*  f0bbc8c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bbc90:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bbc94:	10400004 */ 	beqz	$v0,.L0f0bbca8
/*  f0bbc98:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f0bbc9c:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0bbca0:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f0bbca4:	adee00fc */ 	sw	$t6,0xfc($t7)
.L0f0bbca8:
/*  f0bbca8:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbcac:	c44a00e4 */ 	lwc1	$f10,0xe4($v0)
/*  f0bbcb0:	c44400dc */ 	lwc1	$f4,0xdc($v0)
/*  f0bbcb4:	e7b00028 */ 	swc1	$f16,0x28($sp)
/*  f0bbcb8:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0bbcbc:	0fc30869 */ 	jal	func0f0c21a4
/*  f0bbcc0:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0bbcc4:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f0bbcc8:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f0bbccc:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bbcd0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bbcd4:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0bbcd8:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbcdc:	3c098007 */ 	lui	$t1,%hi(g_HealthDamageTypes+0x8)
/*  f0bbce0:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f0bbce4:	c44800e8 */ 	lwc1	$f8,0xe8($v0)
/*  f0bbce8:	c44a00e4 */ 	lwc1	$f10,0xe4($v0)
/*  f0bbcec:	46004081 */ 	sub.s	$f2,$f8,$f0
/*  f0bbcf0:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0bbcf4:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f0bbcf8:	e44800ec */ 	swc1	$f8,0xec($v0)
/*  f0bbcfc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbd00:	c44400e8 */ 	lwc1	$f4,0xe8($v0)
/*  f0bbd04:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0bbd08:	e44600f0 */ 	swc1	$f6,0xf0($v0)
/*  f0bbd0c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbd10:	8c581924 */ 	lw	$t8,0x1924($v0)
/*  f0bbd14:	c44800f8 */ 	lwc1	$f8,0xf8($v0)
/*  f0bbd18:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0bbd1c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0bbd20:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bbd24:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0bbd28:	8d29092c */ 	lw	$t1,%lo(g_HealthDamageTypes+0x8)($t1)
/*  f0bbd2c:	44892000 */ 	mtc1	$t1,$f4
/*  f0bbd30:	00000000 */ 	nop
/*  f0bbd34:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0bbd38:	4608503e */ 	c.le.s	$f10,$f8
/*  f0bbd3c:	00000000 */ 	nop
/*  f0bbd40:	45020065 */ 	bc1fl	.L0f0bbed8
/*  f0bbd44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bbd48:	10000062 */ 	b	.L0f0bbed4
/*  f0bbd4c:	ac4a00fc */ 	sw	$t2,0xfc($v0)
/*  f0bbd50:	c44600dc */ 	lwc1	$f6,0xdc($v0)
/*  f0bbd54:	0fc30869 */ 	jal	func0f0c21a4
/*  f0bbd58:	e44600ec */ 	swc1	$f6,0xec($v0)
/*  f0bbd5c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bbd60:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bbd64:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0bbd68:	e56000f0 */ 	swc1	$f0,0xf0($t3)
/*  f0bbd6c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbd70:	c5080010 */ 	lwc1	$f8,0x10($t0)
/*  f0bbd74:	c44400f8 */ 	lwc1	$f4,0xf8($v0)
/*  f0bbd78:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0bbd7c:	0fc3c2fb */ 	jal	currentPlayerIsMenuOpenInSoloOrMp
/*  f0bbd80:	e44a00f8 */ 	swc1	$f10,0xf8($v0)
/*  f0bbd84:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bbd88:	1040000d */ 	beqz	$v0,.L0f0bbdc0
/*  f0bbd8c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bbd90:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbd94:	3c0e8007 */ 	lui	$t6,%hi(g_HealthDamageTypes+0xc)
/*  f0bbd98:	8c4c1924 */ 	lw	$t4,0x1924($v0)
/*  f0bbd9c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bbda0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0bbda4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bbda8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0bbdac:	8dce0930 */ 	lw	$t6,%lo(g_HealthDamageTypes+0xc)($t6)
/*  f0bbdb0:	448e3000 */ 	mtc1	$t6,$f6
/*  f0bbdb4:	00000000 */ 	nop
/*  f0bbdb8:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0bbdbc:	e44400f8 */ 	swc1	$f4,0xf8($v0)
.L0f0bbdc0:
/*  f0bbdc0:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbdc4:	3c198007 */ 	lui	$t9,%hi(g_HealthDamageTypes+0xc)
/*  f0bbdc8:	8c4f1924 */ 	lw	$t7,0x1924($v0)
/*  f0bbdcc:	c44800f8 */ 	lwc1	$f8,0xf8($v0)
/*  f0bbdd0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bbdd4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0bbdd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bbddc:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0bbde0:	8f390930 */ 	lw	$t9,%lo(g_HealthDamageTypes+0xc)($t9)
/*  f0bbde4:	44995000 */ 	mtc1	$t9,$f10
/*  f0bbde8:	00000000 */ 	nop
/*  f0bbdec:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0bbdf0:	4608303e */ 	c.le.s	$f6,$f8
/*  f0bbdf4:	00000000 */ 	nop
/*  f0bbdf8:	45020037 */ 	bc1fl	.L0f0bbed8
/*  f0bbdfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bbe00:	0fc3c2fb */ 	jal	currentPlayerIsMenuOpenInSoloOrMp
/*  f0bbe04:	00000000 */ 	nop
/*  f0bbe08:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0bbe0c:	14400031 */ 	bnez	$v0,.L0f0bbed4
/*  f0bbe10:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0bbe14:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0bbe18:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f0bbe1c:	3c0d8007 */ 	lui	$t5,%hi(g_HealthDamageTypes+0xc)
/*  f0bbe20:	ad4900fc */ 	sw	$t1,0xfc($t2)
/*  f0bbe24:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbe28:	8c4b1924 */ 	lw	$t3,0x1924($v0)
/*  f0bbe2c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0bbe30:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0bbe34:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bbe38:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0bbe3c:	8dad0930 */ 	lw	$t5,%lo(g_HealthDamageTypes+0xc)($t5)
/*  f0bbe40:	448d2000 */ 	mtc1	$t5,$f4
/*  f0bbe44:	00000000 */ 	nop
/*  f0bbe48:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0bbe4c:	10000021 */ 	b	.L0f0bbed4
/*  f0bbe50:	e44a00f8 */ 	swc1	$f10,0xf8($v0)
/*  f0bbe54:	c44800f8 */ 	lwc1	$f8,0xf8($v0)
/*  f0bbe58:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f0bbe5c:	3c188007 */ 	lui	$t8,%hi(g_HealthDamageTypes+0x10)
/*  f0bbe60:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bbe64:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0bbe68:	e44400f8 */ 	swc1	$f4,0xf8($v0)
/*  f0bbe6c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0bbe70:	8c4e1924 */ 	lw	$t6,0x1924($v0)
/*  f0bbe74:	c44a00f8 */ 	lwc1	$f10,0xf8($v0)
/*  f0bbe78:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0bbe7c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0bbe80:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bbe84:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0bbe88:	8f180934 */ 	lw	$t8,%lo(g_HealthDamageTypes+0x10)($t8)
/*  f0bbe8c:	44984000 */ 	mtc1	$t8,$f8
/*  f0bbe90:	00000000 */ 	nop
/*  f0bbe94:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0bbe98:	460a303e */ 	c.le.s	$f6,$f10
/*  f0bbe9c:	00000000 */ 	nop
/*  f0bbea0:	4502000d */ 	bc1fl	.L0f0bbed8
/*  f0bbea4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bbea8:	44812000 */ 	mtc1	$at,$f4
/*  f0bbeac:	00000000 */ 	nop
/*  f0bbeb0:	e44400f8 */ 	swc1	$f4,0xf8($v0)
/*  f0bbeb4:	8d190284 */ 	lw	$t9,0x284($t0)
/*  f0bbeb8:	10000006 */ 	b	.L0f0bbed4
/*  f0bbebc:	af2000fc */ 	sw	$zero,0xfc($t9)
/*  f0bbec0:	44814000 */ 	mtc1	$at,$f8
.L0f0bbec4:
/*  f0bbec4:	00000000 */ 	nop
/*  f0bbec8:	e44800f8 */ 	swc1	$f8,0xf8($v0)
/*  f0bbecc:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0bbed0:	ad2000fc */ 	sw	$zero,0xfc($t1)
.L0f0bbed4:
/*  f0bbed4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0bbed8:
/*  f0bbed8:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0bbedc:	03e00008 */ 	jr	$ra
/*  f0bbee0:	00000000 */ 	nop
/*  f0bbee4:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0bbee8:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0bbeec:	44803000 */ 	mtc1	$zero,$f6
/*  f0bbef0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bbef4:	c5c400f4 */ 	lwc1	$f4,0xf4($t6)
/*  f0bbef8:	4604303e */ 	c.le.s	$f6,$f4
/*  f0bbefc:	00000000 */ 	nop
/*  f0bbf00:	45000002 */ 	bc1f	.L0f0bbf0c
/*  f0bbf04:	00000000 */ 	nop
/*  f0bbf08:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bbf0c:
/*  f0bbf0c:	03e00008 */ 	jr	$ra
/*  f0bbf10:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bbf14
/*  f0bbf14:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0bbf18:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0bbf1c:	3c018007 */ 	lui	$at,%hi(var80070848)
/*  f0bbf20:	8c4e1924 */ 	lw	$t6,0x1924($v0)
/*  f0bbf24:	c44000f4 */ 	lwc1	$f0,0xf4($v0)
/*  f0bbf28:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0bbf2c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bbf30:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bbf34:	002f0821 */ 	addu	$at,$at,$t7
/*  f0bbf38:	c4220848 */ 	lwc1	$f2,%lo(var80070848)($at)
/*  f0bbf3c:	4600103e */ 	c.le.s	$f2,$f0
/*  f0bbf40:	00000000 */ 	nop
/*  f0bbf44:	45020004 */ 	bc1fl	.L0f0bbf58
/*  f0bbf48:	44801000 */ 	mtc1	$zero,$f2
/*  f0bbf4c:	03e00008 */ 	jr	$ra
/*  f0bbf50:	e44200f4 */ 	swc1	$f2,0xf4($v0)
/*  f0bbf54:	44801000 */ 	mtc1	$zero,$f2
.L0f0bbf58:
/*  f0bbf58:	00000000 */ 	nop
/*  f0bbf5c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0bbf60:	00000000 */ 	nop
/*  f0bbf64:	45000002 */ 	bc1f	.L0f0bbf70
/*  f0bbf68:	00000000 */ 	nop
/*  f0bbf6c:	e44200f4 */ 	swc1	$f2,0xf4($v0)
.L0f0bbf70:
/*  f0bbf70:	03e00008 */ 	jr	$ra
/*  f0bbf74:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel hudRenderHealthBar
/*  f0bbf78:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0bbf7c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0bbf80:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0bbf84:	0fc59e66 */ 	jal	func0f167998
/*  f0bbf88:	00808025 */ 	or	$s0,$a0,$zero
/*  f0bbf8c:	44800000 */ 	mtc1	$zero,$f0
/*  f0bbf90:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bbf94:	44812000 */ 	mtc1	$at,$f4
/*  f0bbf98:	44050000 */ 	mfc1	$a1,$f0
/*  f0bbf9c:	44070000 */ 	mfc1	$a3,$f0
/*  f0bbfa0:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0bbfa4:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0bbfa8:	3c0643b9 */ 	lui	$a2,0x43b9
/*  f0bbfac:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f0bbfb0:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f0bbfb4:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f0bbfb8:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0bbfbc:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f0bbfc0:	0c005ab9 */ 	jal	func00016ae4
/*  f0bbfc4:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0bbfc8:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0bbfcc:	0c005815 */ 	jal	func00016054
/*  f0bbfd0:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0bbfd4:	3c0e0102 */ 	lui	$t6,0x102
/*  f0bbfd8:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0bbfdc:	02003825 */ 	or	$a3,$s0,$zero
/*  f0bbfe0:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0bbfe4:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0bbfe8:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0bbfec:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0bbff0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0bbff4:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0bbff8:	02001825 */ 	or	$v1,$s0,$zero
/*  f0bbffc:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0bc000:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f0bc004:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0bc008:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0bc00c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0bc010:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0bc014:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0bc018:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0bc01c:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f0bc020:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0bc024:	3c19b900 */ 	lui	$t9,0xb900
/*  f0bc028:	3c090050 */ 	lui	$t1,0x50
/*  f0bc02c:	35294240 */ 	ori	$t1,$t1,0x4240
/*  f0bc030:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0bc034:	24b00008 */ 	addiu	$s0,$a1,0x8
/*  f0bc038:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0bc03c:	aca90004 */ 	sw	$t1,0x4($a1)
/*  f0bc040:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bc044:	3c0ab900 */ 	lui	$t2,0xb900
/*  f0bc048:	354a0002 */ 	ori	$t2,$t2,0x2
/*  f0bc04c:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f0bc050:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f0bc054:	26080008 */ 	addiu	$t0,$s0,0x8
/*  f0bc058:	3c0bfcff */ 	lui	$t3,0xfcff
/*  f0bc05c:	3c0cfffe */ 	lui	$t4,0xfffe
/*  f0bc060:	44800000 */ 	mtc1	$zero,$f0
/*  f0bc064:	358c793c */ 	ori	$t4,$t4,0x793c
/*  f0bc068:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f0bc06c:	25020008 */ 	addiu	$v0,$t0,0x8
/*  f0bc070:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f0bc074:	ad0c0004 */ 	sw	$t4,0x4($t0)
/*  f0bc078:	3c0ee6e6 */ 	lui	$t6,0xe6e6
/*  f0bc07c:	35cee600 */ 	ori	$t6,$t6,0xe600
/*  f0bc080:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f0bc084:	3c0dfa00 */ 	lui	$t5,0xfa00
/*  f0bc088:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0bc08c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0bc090:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f0bc094:	3c0fb600 */ 	lui	$t7,0xb600
/*  f0bc098:	44070000 */ 	mfc1	$a3,$f0
/*  f0bc09c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0bc0a0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0bc0a4:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0bc0a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bc0ac:	0fc35763 */ 	jal	func0f0d5d8c
/*  f0bc0b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bc0b4:	3c190103 */ 	lui	$t9,0x103
/*  f0bc0b8:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0bc0bc:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0bc0c0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0bc0c4:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f0bc0c8:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0bc0cc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0bc0d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bc0d4:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f0bc0d8:	ad220004 */ 	sw	$v0,0x4($t1)
/*  f0bc0dc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0bc0e0:	02001025 */ 	or	$v0,$s0,$zero
/*  f0bc0e4:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0bc0e8:	03e00008 */ 	jr	$ra
/*  f0bc0ec:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void currentPlayerSurroundWithExplosions(s32 arg0)
{
	g_Vars.currentplayer->bondexploding = true;
	g_Vars.currentplayer->bondnextexplode = arg0 + g_Vars.lvframe60;
	g_Vars.currentplayer->bondcurexplode = 0;
}

GLOBAL_ASM(
glabel func0f0bc120
/*  f0bc120:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0bc124:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0bc128:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0bc12c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0bc130:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0bc134:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0bc138:	3c198007 */ 	lui	$t9,%hi(g_PlayerInvincible)
/*  f0bc13c:	8c4e1bf8 */ 	lw	$t6,0x1bf8($v0)
/*  f0bc140:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0bc144:	ac4f1bf8 */ 	sw	$t7,0x1bf8($v0)
/*  f0bc148:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0bc14c:	8c581bf0 */ 	lw	$t8,0x1bf0($v0)
/*  f0bc150:	530000a3 */ 	beqzl	$t8,.L0f0bc3e0
/*  f0bc154:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0bc158:	8f390760 */ 	lw	$t9,%lo(g_PlayerInvincible)($t9)
/*  f0bc15c:	572000a0 */ 	bnezl	$t9,.L0f0bc3e0
/*  f0bc160:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0bc164:	8c481bf4 */ 	lw	$t0,0x1bf4($v0)
/*  f0bc168:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f0bc16c:	0109082a */ 	slt	$at,$t0,$t1
/*  f0bc170:	5020009b */ 	beqzl	$at,.L0f0bc3e0
/*  f0bc174:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0bc178:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0bc17c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bc180:	c5440008 */ 	lwc1	$f4,0x8($t2)
/*  f0bc184:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f0bc188:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f0bc18c:	c566000c */ 	lwc1	$f6,0xc($t3)
/*  f0bc190:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f0bc194:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f0bc198:	c5880010 */ 	lwc1	$f8,0x10($t4)
/*  f0bc19c:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f0bc1a0:	8c431bf8 */ 	lw	$v1,0x1bf8($v0)
/*  f0bc1a4:	04610004 */ 	bgez	$v1,.L0f0bc1b8
/*  f0bc1a8:	306d0003 */ 	andi	$t5,$v1,0x3
/*  f0bc1ac:	11a00002 */ 	beqz	$t5,.L0f0bc1b8
/*  f0bc1b0:	00000000 */ 	nop
/*  f0bc1b4:	25adfffc */ 	addiu	$t5,$t5,-4
.L0f0bc1b8:
/*  f0bc1b8:	11a00009 */ 	beqz	$t5,.L0f0bc1e0
/*  f0bc1bc:	00000000 */ 	nop
/*  f0bc1c0:	11a1001d */ 	beq	$t5,$at,.L0f0bc238
/*  f0bc1c4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bc1c8:	11a10031 */ 	beq	$t5,$at,.L0f0bc290
/*  f0bc1cc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0bc1d0:	11a10045 */ 	beq	$t5,$at,.L0f0bc2e8
/*  f0bc1d4:	00000000 */ 	nop
/*  f0bc1d8:	10000058 */ 	b	.L0f0bc33c
/*  f0bc1dc:	00000000 */ 	nop
.L0f0bc1e0:
/*  f0bc1e0:	0c004b70 */ 	jal	random
/*  f0bc1e4:	00000000 */ 	nop
/*  f0bc1e8:	44825000 */ 	mtc1	$v0,$f10
/*  f0bc1ec:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bc1f0:	04410004 */ 	bgez	$v0,.L0f0bc204
/*  f0bc1f4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0bc1f8:	44819000 */ 	mtc1	$at,$f18
/*  f0bc1fc:	00000000 */ 	nop
/*  f0bc200:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0bc204:
/*  f0bc204:	3c012f80 */ 	lui	$at,0x2f80
/*  f0bc208:	44812000 */ 	mtc1	$at,$f4
/*  f0bc20c:	3c014316 */ 	lui	$at,0x4316
/*  f0bc210:	44814000 */ 	mtc1	$at,$f8
/*  f0bc214:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0bc218:	3c01437a */ 	lui	$at,0x437a
/*  f0bc21c:	44819000 */ 	mtc1	$at,$f18
/*  f0bc220:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f0bc224:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0bc228:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0bc22c:	46102200 */ 	add.s	$f8,$f4,$f16
/*  f0bc230:	10000042 */ 	b	.L0f0bc33c
/*  f0bc234:	e7a80034 */ 	swc1	$f8,0x34($sp)
.L0f0bc238:
/*  f0bc238:	0c004b70 */ 	jal	random
/*  f0bc23c:	00000000 */ 	nop
/*  f0bc240:	44823000 */ 	mtc1	$v0,$f6
/*  f0bc244:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bc248:	04410004 */ 	bgez	$v0,.L0f0bc25c
/*  f0bc24c:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0bc250:	44815000 */ 	mtc1	$at,$f10
/*  f0bc254:	00000000 */ 	nop
/*  f0bc258:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f0bc25c:
/*  f0bc25c:	3c012f80 */ 	lui	$at,0x2f80
/*  f0bc260:	44812000 */ 	mtc1	$at,$f4
/*  f0bc264:	3c014316 */ 	lui	$at,0x4316
/*  f0bc268:	44814000 */ 	mtc1	$at,$f8
/*  f0bc26c:	46049402 */ 	mul.s	$f16,$f18,$f4
/*  f0bc270:	3c01437a */ 	lui	$at,0x437a
/*  f0bc274:	44815000 */ 	mtc1	$at,$f10
/*  f0bc278:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f0bc27c:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f0bc280:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0bc284:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f0bc288:	1000002c */ 	b	.L0f0bc33c
/*  f0bc28c:	e7a80034 */ 	swc1	$f8,0x34($sp)
.L0f0bc290:
/*  f0bc290:	0c004b70 */ 	jal	random
/*  f0bc294:	00000000 */ 	nop
/*  f0bc298:	44828000 */ 	mtc1	$v0,$f16
/*  f0bc29c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bc2a0:	04410004 */ 	bgez	$v0,.L0f0bc2b4
/*  f0bc2a4:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f0bc2a8:	44813000 */ 	mtc1	$at,$f6
/*  f0bc2ac:	00000000 */ 	nop
/*  f0bc2b0:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f0bc2b4:
/*  f0bc2b4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0bc2b8:	44812000 */ 	mtc1	$at,$f4
/*  f0bc2bc:	3c014316 */ 	lui	$at,0x4316
/*  f0bc2c0:	44814000 */ 	mtc1	$at,$f8
/*  f0bc2c4:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f0bc2c8:	3c01437a */ 	lui	$at,0x437a
/*  f0bc2cc:	44813000 */ 	mtc1	$at,$f6
/*  f0bc2d0:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f0bc2d4:	46124402 */ 	mul.s	$f16,$f8,$f18
/*  f0bc2d8:	46103280 */ 	add.s	$f10,$f6,$f16
/*  f0bc2dc:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0bc2e0:	10000016 */ 	b	.L0f0bc33c
/*  f0bc2e4:	e7a8003c */ 	swc1	$f8,0x3c($sp)
.L0f0bc2e8:
/*  f0bc2e8:	0c004b70 */ 	jal	random
/*  f0bc2ec:	00000000 */ 	nop
/*  f0bc2f0:	44829000 */ 	mtc1	$v0,$f18
/*  f0bc2f4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bc2f8:	04410004 */ 	bgez	$v0,.L0f0bc30c
/*  f0bc2fc:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f0bc300:	44818000 */ 	mtc1	$at,$f16
/*  f0bc304:	00000000 */ 	nop
/*  f0bc308:	46103180 */ 	add.s	$f6,$f6,$f16
.L0f0bc30c:
/*  f0bc30c:	3c012f80 */ 	lui	$at,0x2f80
/*  f0bc310:	44812000 */ 	mtc1	$at,$f4
/*  f0bc314:	3c014316 */ 	lui	$at,0x4316
/*  f0bc318:	44814000 */ 	mtc1	$at,$f8
/*  f0bc31c:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0bc320:	3c01437a */ 	lui	$at,0x437a
/*  f0bc324:	44818000 */ 	mtc1	$at,$f16
/*  f0bc328:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f0bc32c:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0bc330:	46128180 */ 	add.s	$f6,$f16,$f18
/*  f0bc334:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0bc338:	e7a8003c */ 	swc1	$f8,0x3c($sp)
.L0f0bc33c:
/*  f0bc33c:	0c004b70 */ 	jal	random
/*  f0bc340:	00000000 */ 	nop
/*  f0bc344:	44825000 */ 	mtc1	$v0,$f10
/*  f0bc348:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bc34c:	04410004 */ 	bgez	$v0,.L0f0bc360
/*  f0bc350:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0bc354:	44819000 */ 	mtc1	$at,$f18
/*  f0bc358:	00000000 */ 	nop
/*  f0bc35c:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0bc360:
/*  f0bc360:	3c012f80 */ 	lui	$at,0x2f80
/*  f0bc364:	44812000 */ 	mtc1	$at,$f4
/*  f0bc368:	3c014348 */ 	lui	$at,0x4348
/*  f0bc36c:	44814000 */ 	mtc1	$at,$f8
/*  f0bc370:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0bc374:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0bc378:	44819000 */ 	mtc1	$at,$f18
/*  f0bc37c:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f0bc380:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0bc384:	8e0f028c */ 	lw	$t7,0x28c($s0)
/*  f0bc388:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bc38c:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0bc390:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0bc394:	24070012 */ 	addiu	$a3,$zero,0x12
/*  f0bc398:	46125401 */ 	sub.s	$f16,$f10,$f18
/*  f0bc39c:	46102200 */ 	add.s	$f8,$f4,$f16
/*  f0bc3a0:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f0bc3a4:	8dc600bc */ 	lw	$a2,0xbc($t6)
/*  f0bc3a8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0bc3ac:	0fc4a640 */ 	jal	explosionCreateSimple
/*  f0bc3b0:	24c60028 */ 	addiu	$a2,$a2,0x28
/*  f0bc3b4:	0c004b70 */ 	jal	random
/*  f0bc3b8:	00000000 */ 	nop
/*  f0bc3bc:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0bc3c0:	0041001b */ 	divu	$zero,$v0,$at
/*  f0bc3c4:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0bc3c8:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0bc3cc:	0000c010 */ 	mfhi	$t8
/*  f0bc3d0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0bc3d4:	2509000f */ 	addiu	$t1,$t0,0xf
/*  f0bc3d8:	ad491bf4 */ 	sw	$t1,0x1bf4($t2)
/*  f0bc3dc:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0bc3e0:
/*  f0bc3e0:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0bc3e4:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0bc3e8:	03e00008 */ 	jr	$ra
/*  f0bc3ec:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bc3f0
/*  f0bc3f0:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f0bc3f4:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f0bc3f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bc3fc:	3c028007 */ 	lui	$v0,%hi(var800705c0)
/*  f0bc400:	15c1000d */ 	bne	$t6,$at,.L0f0bc438
/*  f0bc404:	244205c0 */ 	addiu	$v0,$v0,%lo(var800705c0)
/*  f0bc408:	240300dc */ 	addiu	$v1,$zero,0xdc
/*  f0bc40c:	240f00b4 */ 	addiu	$t7,$zero,0xb4
/*  f0bc410:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0bc414:	24190088 */ 	addiu	$t9,$zero,0x88
/*  f0bc418:	2408002a */ 	addiu	$t0,$zero,0x2a
/*  f0bc41c:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f0bc420:	ac400018 */ 	sw	$zero,0x18($v0)
/*  f0bc424:	ac430014 */ 	sw	$v1,0x14($v0)
/*  f0bc428:	ac4f001c */ 	sw	$t7,0x1c($v0)
/*  f0bc42c:	ac580020 */ 	sw	$t8,0x20($v0)
/*  f0bc430:	ac590024 */ 	sw	$t9,0x24($v0)
/*  f0bc434:	ac480028 */ 	sw	$t0,0x28($v0)
.L0f0bc438:
/*  f0bc438:	03e00008 */ 	jr	$ra
/*  f0bc43c:	00000000 */ 	nop
);

void optionsSetHiRes(bool enable)
{
	g_HiResEnabled = enable;
}

s16 func0f0bc44c(void)
{
	s16 value = var800705c0[g_HiResActive].unk02;
	return value;
}

s16 func0f0bc478(void)
{
	s16 value = var800705c0[g_HiResActive].unk06;

	if (g_Vars.unk0004e0) {
		value = value >> 1;
	}

	return value;
}

GLOBAL_ASM(
glabel func0f0bc4c0
/*  f0bc4c0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0bc4c4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0bc4c8:	8c4e0298 */ 	lw	$t6,0x298($v0)
/*  f0bc4cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0bc4d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bc4d4:	05c10004 */ 	bgez	$t6,.L0f0bc4e8
/*  f0bc4d8:	00000000 */ 	nop
/*  f0bc4dc:	8c4f029c */ 	lw	$t7,0x29c($v0)
/*  f0bc4e0:	05e0000b */ 	bltz	$t7,.L0f0bc510
/*  f0bc4e4:	00000000 */ 	nop
.L0f0bc4e8:
/*  f0bc4e8:	0fc3f303 */ 	jal	menuGetRoot
/*  f0bc4ec:	00000000 */ 	nop
/*  f0bc4f0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0bc4f4:	14410006 */ 	bne	$v0,$at,.L0f0bc510
/*  f0bc4f8:	3c18800a */ 	lui	$t8,%hi(var8009dfc0)
/*  f0bc4fc:	8f18dfc0 */ 	lw	$t8,%lo(var8009dfc0)($t8)
/*  f0bc500:	17000003 */ 	bnez	$t8,.L0f0bc510
/*  f0bc504:	00000000 */ 	nop
/*  f0bc508:	1000000e */ 	b	.L0f0bc544
/*  f0bc50c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bc510:
/*  f0bc510:	3c028007 */ 	lui	$v0,%hi(var80070764)
/*  f0bc514:	8c420764 */ 	lw	$v0,%lo(var80070764)($v0)
/*  f0bc518:	0002c82b */ 	sltu	$t9,$zero,$v0
/*  f0bc51c:	13200005 */ 	beqz	$t9,.L0f0bc534
/*  f0bc520:	3c028006 */ 	lui	$v0,%hi(var8005d9d0)
/*  f0bc524:	8c42d9d0 */ 	lw	$v0,%lo(var8005d9d0)($v0)
/*  f0bc528:	2c480001 */ 	sltiu	$t0,$v0,0x1
/*  f0bc52c:	15000005 */ 	bnez	$t0,.L0f0bc544
/*  f0bc530:	01001025 */ 	or	$v0,$t0,$zero
.L0f0bc534:
/*  f0bc534:	0fc3f303 */ 	jal	menuGetRoot
/*  f0bc538:	00000000 */ 	nop
/*  f0bc53c:	38490009 */ 	xori	$t1,$v0,0x9
/*  f0bc540:	2d220001 */ 	sltiu	$v0,$t1,0x1
.L0f0bc544:
/*  f0bc544:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bc548:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0bc54c:	03e00008 */ 	jr	$ra
/*  f0bc550:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bc554
/*  f0bc554:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0bc558:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bc55c:	0fc2f130 */ 	jal	func0f0bc4c0
/*  f0bc560:	00000000 */ 	nop
/*  f0bc564:	14400083 */ 	bnez	$v0,.L0f0bc774
/*  f0bc568:	3c0c8007 */ 	lui	$t4,%hi(g_HiResActive)
/*  f0bc56c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bc570:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bc574:	8cc7006c */ 	lw	$a3,0x6c($a2)
/*  f0bc578:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bc57c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bc580:	10e00003 */ 	beqz	$a3,.L0f0bc590
/*  f0bc584:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bc588:	10000001 */ 	b	.L0f0bc590
/*  f0bc58c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bc590:
/*  f0bc590:	8cc80068 */ 	lw	$t0,0x68($a2)
/*  f0bc594:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bc598:	11000003 */ 	beqz	$t0,.L0f0bc5a8
/*  f0bc59c:	00000000 */ 	nop
/*  f0bc5a0:	10000001 */ 	b	.L0f0bc5a8
/*  f0bc5a4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bc5a8:
/*  f0bc5a8:	8cc90064 */ 	lw	$t1,0x64($a2)
/*  f0bc5ac:	11200003 */ 	beqz	$t1,.L0f0bc5bc
/*  f0bc5b0:	00000000 */ 	nop
/*  f0bc5b4:	10000001 */ 	b	.L0f0bc5bc
/*  f0bc5b8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0bc5bc:
/*  f0bc5bc:	8cca0070 */ 	lw	$t2,0x70($a2)
/*  f0bc5c0:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bc5c4:	11400003 */ 	beqz	$t2,.L0f0bc5d4
/*  f0bc5c8:	00000000 */ 	nop
/*  f0bc5cc:	10000001 */ 	b	.L0f0bc5d4
/*  f0bc5d0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bc5d4:
/*  f0bc5d4:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0bc5d8:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f0bc5dc:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f0bc5e0:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0bc5e4:	14200019 */ 	bnez	$at,.L0f0bc64c
/*  f0bc5e8:	00000000 */ 	nop
/*  f0bc5ec:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bc5f0:	3c038007 */ 	lui	$v1,%hi(var800705c0+0x8)
/*  f0bc5f4:	8cc2028c */ 	lw	$v0,0x28c($a2)
/*  f0bc5f8:	00195880 */ 	sll	$t3,$t9,0x2
/*  f0bc5fc:	01795823 */ 	subu	$t3,$t3,$t9
/*  f0bc600:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0bc604:	01795823 */ 	subu	$t3,$t3,$t9
/*  f0bc608:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0bc60c:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f0bc610:	8c6305c8 */ 	lw	$v1,%lo(var800705c0+0x8)($v1)
/*  f0bc614:	04610003 */ 	bgez	$v1,.L0f0bc624
/*  f0bc618:	00036043 */ 	sra	$t4,$v1,0x1
/*  f0bc61c:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0bc620:	00016043 */ 	sra	$t4,$at,0x1
.L0f0bc624:
/*  f0bc624:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f0bc628:	10400004 */ 	beqz	$v0,.L0f0bc63c
/*  f0bc62c:	000d1c03 */ 	sra	$v1,$t5,0x10
/*  f0bc630:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bc634:	54410059 */ 	bnel	$v0,$at,.L0f0bc79c
/*  f0bc638:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0bc63c:
/*  f0bc63c:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0bc640:	00037c00 */ 	sll	$t7,$v1,0x10
/*  f0bc644:	10000054 */ 	b	.L0f0bc798
/*  f0bc648:	000f1c03 */ 	sra	$v1,$t7,0x10
.L0f0bc64c:
/*  f0bc64c:	10e00003 */ 	beqz	$a3,.L0f0bc65c
/*  f0bc650:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bc654:	10000002 */ 	b	.L0f0bc660
/*  f0bc658:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bc65c:
/*  f0bc65c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0bc660:
/*  f0bc660:	11000003 */ 	beqz	$t0,.L0f0bc670
/*  f0bc664:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bc668:	10000001 */ 	b	.L0f0bc670
/*  f0bc66c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bc670:
/*  f0bc670:	11200003 */ 	beqz	$t1,.L0f0bc680
/*  f0bc674:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bc678:	10000001 */ 	b	.L0f0bc680
/*  f0bc67c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0bc680:
/*  f0bc680:	11400003 */ 	beqz	$t2,.L0f0bc690
/*  f0bc684:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bc688:	10000001 */ 	b	.L0f0bc690
/*  f0bc68c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bc690:
/*  f0bc690:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0bc694:	03245821 */ 	addu	$t3,$t9,$a0
/*  f0bc698:	01656021 */ 	addu	$t4,$t3,$a1
/*  f0bc69c:	1581002b */ 	bne	$t4,$at,.L0f0bc74c
/*  f0bc6a0:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bc6a4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0bc6a8:	00000000 */ 	nop
/*  f0bc6ac:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bc6b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bc6b4:	10410004 */ 	beq	$v0,$at,.L0f0bc6c8
/*  f0bc6b8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bc6bc:	90cd04e0 */ 	lbu	$t5,0x4e0($a2)
/*  f0bc6c0:	3c0f8007 */ 	lui	$t7,%hi(g_HiResActive)
/*  f0bc6c4:	11a00017 */ 	beqz	$t5,.L0f0bc724
.L0f0bc6c8:
/*  f0bc6c8:	3c0e8007 */ 	lui	$t6,%hi(g_HiResActive)
/*  f0bc6cc:	8dce06c8 */ 	lw	$t6,%lo(g_HiResActive)($t6)
/*  f0bc6d0:	3c038007 */ 	lui	$v1,%hi(var800705c0+0x8)
/*  f0bc6d4:	8ccc028c */ 	lw	$t4,0x28c($a2)
/*  f0bc6d8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0bc6dc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bc6e0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bc6e4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bc6e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bc6ec:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0bc6f0:	8c6305c8 */ 	lw	$v1,%lo(var800705c0+0x8)($v1)
/*  f0bc6f4:	04610003 */ 	bgez	$v1,.L0f0bc704
/*  f0bc6f8:	0003c043 */ 	sra	$t8,$v1,0x1
/*  f0bc6fc:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0bc700:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0bc704:
/*  f0bc704:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f0bc708:	00195c03 */ 	sra	$t3,$t9,0x10
/*  f0bc70c:	15800022 */ 	bnez	$t4,.L0f0bc798
/*  f0bc710:	01601825 */ 	or	$v1,$t3,$zero
/*  f0bc714:	2563ffff */ 	addiu	$v1,$t3,-1
/*  f0bc718:	00036c00 */ 	sll	$t5,$v1,0x10
/*  f0bc71c:	1000001e */ 	b	.L0f0bc798
/*  f0bc720:	000d1c03 */ 	sra	$v1,$t5,0x10
.L0f0bc724:
/*  f0bc724:	8def06c8 */ 	lw	$t7,%lo(g_HiResActive)($t7)
/*  f0bc728:	3c038007 */ 	lui	$v1,%hi(var800705c0+0xa)
/*  f0bc72c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bc730:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bc734:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bc738:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bc73c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bc740:	00781821 */ 	addu	$v1,$v1,$t8
/*  f0bc744:	10000014 */ 	b	.L0f0bc798
/*  f0bc748:	846305ca */ 	lh	$v1,%lo(var800705c0+0xa)($v1)
.L0f0bc74c:
/*  f0bc74c:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bc750:	3c038007 */ 	lui	$v1,%hi(var800705c0+0xa)
/*  f0bc754:	00195880 */ 	sll	$t3,$t9,0x2
/*  f0bc758:	01795823 */ 	subu	$t3,$t3,$t9
/*  f0bc75c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0bc760:	01795823 */ 	subu	$t3,$t3,$t9
/*  f0bc764:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0bc768:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f0bc76c:	1000000a */ 	b	.L0f0bc798
/*  f0bc770:	846305ca */ 	lh	$v1,%lo(var800705c0+0xa)($v1)
.L0f0bc774:
/*  f0bc774:	8d8c06c8 */ 	lw	$t4,%lo(g_HiResActive)($t4)
/*  f0bc778:	3c038007 */ 	lui	$v1,%hi(var800705c0+0xa)
/*  f0bc77c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bc780:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bc784:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bc788:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bc78c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bc790:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f0bc794:	846305ca */ 	lh	$v1,%lo(var800705c0+0xa)($v1)
.L0f0bc798:
/*  f0bc798:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0bc79c:
/*  f0bc79c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0bc7a0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0bc7a4:	03e00008 */ 	jr	$ra
/*  f0bc7a8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bc7ac
/*  f0bc7ac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0bc7b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bc7b4:	0fc2f130 */ 	jal	func0f0bc4c0
/*  f0bc7b8:	00000000 */ 	nop
/*  f0bc7bc:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0bc7c0:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0bc7c4:	8d67006c */ 	lw	$a3,0x6c($t3)
/*  f0bc7c8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bc7cc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bc7d0:	10e00003 */ 	beqz	$a3,.L0f0bc7e0
/*  f0bc7d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bc7d8:	10000001 */ 	b	.L0f0bc7e0
/*  f0bc7dc:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0bc7e0:
/*  f0bc7e0:	8d680068 */ 	lw	$t0,0x68($t3)
/*  f0bc7e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bc7e8:	2c590001 */ 	sltiu	$t9,$v0,0x1
/*  f0bc7ec:	11000003 */ 	beqz	$t0,.L0f0bc7fc
/*  f0bc7f0:	00000000 */ 	nop
/*  f0bc7f4:	10000001 */ 	b	.L0f0bc7fc
/*  f0bc7f8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bc7fc:
/*  f0bc7fc:	8d690064 */ 	lw	$t1,0x64($t3)
/*  f0bc800:	11200003 */ 	beqz	$t1,.L0f0bc810
/*  f0bc804:	00000000 */ 	nop
/*  f0bc808:	10000001 */ 	b	.L0f0bc810
/*  f0bc80c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bc810:
/*  f0bc810:	8d6a0070 */ 	lw	$t2,0x70($t3)
/*  f0bc814:	11400003 */ 	beqz	$t2,.L0f0bc824
/*  f0bc818:	00000000 */ 	nop
/*  f0bc81c:	10000001 */ 	b	.L0f0bc824
/*  f0bc820:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0bc824:
/*  f0bc824:	00647021 */ 	addu	$t6,$v1,$a0
/*  f0bc828:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0bc82c:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f0bc830:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0bc834:	1420002d */ 	bnez	$at,.L0f0bc8ec
/*  f0bc838:	00000000 */ 	nop
/*  f0bc83c:	1320002b */ 	beqz	$t9,.L0f0bc8ec
/*  f0bc840:	00000000 */ 	nop
/*  f0bc844:	8d62028c */ 	lw	$v0,0x28c($t3)
/*  f0bc848:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0bc84c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0bc850:	10620003 */ 	beq	$v1,$v0,.L0f0bc860
/*  f0bc854:	3c0c8007 */ 	lui	$t4,%hi(g_HiResActive)
/*  f0bc858:	14410015 */ 	bne	$v0,$at,.L0f0bc8b0
/*  f0bc85c:	3c0e8007 */ 	lui	$t6,%hi(g_HiResActive)
.L0f0bc860:
/*  f0bc860:	8d8c06c8 */ 	lw	$t4,%lo(g_HiResActive)($t4)
/*  f0bc864:	3c0e8007 */ 	lui	$t6,%hi(var800705c0)
/*  f0bc868:	25ce05c0 */ 	addiu	$t6,$t6,%lo(var800705c0)
/*  f0bc86c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bc870:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bc874:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bc878:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bc87c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bc880:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f0bc884:	8c430008 */ 	lw	$v1,0x8($v0)
/*  f0bc888:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0bc88c:	04610003 */ 	bgez	$v1,.L0f0bc89c
/*  f0bc890:	00037843 */ 	sra	$t7,$v1,0x1
/*  f0bc894:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0bc898:	00017843 */ 	sra	$t7,$at,0x1
.L0f0bc89c:
/*  f0bc89c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0bc8a0:	03232023 */ 	subu	$a0,$t9,$v1
/*  f0bc8a4:	00046400 */ 	sll	$t4,$a0,0x10
/*  f0bc8a8:	10000078 */ 	b	.L0f0bca8c
/*  f0bc8ac:	000c2403 */ 	sra	$a0,$t4,0x10
.L0f0bc8b0:
/*  f0bc8b0:	8dce06c8 */ 	lw	$t6,%lo(g_HiResActive)($t6)
/*  f0bc8b4:	3c188007 */ 	lui	$t8,%hi(var800705c0)
/*  f0bc8b8:	271805c0 */ 	addiu	$t8,$t8,%lo(var800705c0)
/*  f0bc8bc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0bc8c0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bc8c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bc8c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bc8cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bc8d0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0bc8d4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0bc8d8:	8c4c0008 */ 	lw	$t4,0x8($v0)
/*  f0bc8dc:	032c2023 */ 	subu	$a0,$t9,$t4
/*  f0bc8e0:	00046c00 */ 	sll	$t5,$a0,0x10
/*  f0bc8e4:	10000069 */ 	b	.L0f0bca8c
/*  f0bc8e8:	000d2403 */ 	sra	$a0,$t5,0x10
.L0f0bc8ec:
/*  f0bc8ec:	10e00003 */ 	beqz	$a3,.L0f0bc8fc
/*  f0bc8f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bc8f4:	10000002 */ 	b	.L0f0bc900
/*  f0bc8f8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0bc8fc:
/*  f0bc8fc:	00003025 */ 	or	$a2,$zero,$zero
.L0f0bc900:
/*  f0bc900:	11000003 */ 	beqz	$t0,.L0f0bc910
/*  f0bc904:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bc908:	10000001 */ 	b	.L0f0bc910
/*  f0bc90c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bc910:
/*  f0bc910:	11200003 */ 	beqz	$t1,.L0f0bc920
/*  f0bc914:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bc918:	10000001 */ 	b	.L0f0bc920
/*  f0bc91c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bc920:
/*  f0bc920:	11400003 */ 	beqz	$t2,.L0f0bc930
/*  f0bc924:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bc928:	10000001 */ 	b	.L0f0bc930
/*  f0bc92c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0bc930:
/*  f0bc930:	00647821 */ 	addu	$t7,$v1,$a0
/*  f0bc934:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f0bc938:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0bc93c:	17210044 */ 	bne	$t9,$at,.L0f0bca50
/*  f0bc940:	2c4c0001 */ 	sltiu	$t4,$v0,0x1
/*  f0bc944:	11800042 */ 	beqz	$t4,.L0f0bca50
/*  f0bc948:	00000000 */ 	nop
/*  f0bc94c:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0bc950:	00000000 */ 	nop
/*  f0bc954:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0bc958:	3c0b800a */ 	lui	$t3,%hi(g_Vars)
/*  f0bc95c:	10620005 */ 	beq	$v1,$v0,.L0f0bc974
/*  f0bc960:	256b9fc0 */ 	addiu	$t3,$t3,%lo(g_Vars)
/*  f0bc964:	916d04e0 */ 	lbu	$t5,0x4e0($t3)
/*  f0bc968:	3c0c8007 */ 	lui	$t4,%hi(g_HiResActive)
/*  f0bc96c:	11a00029 */ 	beqz	$t5,.L0f0bca14
/*  f0bc970:	00000000 */ 	nop
.L0f0bc974:
/*  f0bc974:	8d6e028c */ 	lw	$t6,0x28c($t3)
/*  f0bc978:	3c0f8007 */ 	lui	$t7,%hi(g_HiResActive)
/*  f0bc97c:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bc980:	146e0015 */ 	bne	$v1,$t6,.L0f0bc9d8
/*  f0bc984:	00000000 */ 	nop
/*  f0bc988:	8def06c8 */ 	lw	$t7,%lo(g_HiResActive)($t7)
/*  f0bc98c:	3c198007 */ 	lui	$t9,%hi(var800705c0)
/*  f0bc990:	273905c0 */ 	addiu	$t9,$t9,%lo(var800705c0)
/*  f0bc994:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bc998:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bc99c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bc9a0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bc9a4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bc9a8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0bc9ac:	8c430008 */ 	lw	$v1,0x8($v0)
/*  f0bc9b0:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f0bc9b4:	04610003 */ 	bgez	$v1,.L0f0bc9c4
/*  f0bc9b8:	00036043 */ 	sra	$t4,$v1,0x1
/*  f0bc9bc:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0bc9c0:	00016043 */ 	sra	$t4,$at,0x1
.L0f0bc9c4:
/*  f0bc9c4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0bc9c8:	01c32023 */ 	subu	$a0,$t6,$v1
/*  f0bc9cc:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f0bc9d0:	1000002e */ 	b	.L0f0bca8c
/*  f0bc9d4:	000f2403 */ 	sra	$a0,$t7,0x10
.L0f0bc9d8:
/*  f0bc9d8:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bc9dc:	3c0d8007 */ 	lui	$t5,%hi(var800705c0)
/*  f0bc9e0:	25ad05c0 */ 	addiu	$t5,$t5,%lo(var800705c0)
/*  f0bc9e4:	00196080 */ 	sll	$t4,$t9,0x2
/*  f0bc9e8:	01996023 */ 	subu	$t4,$t4,$t9
/*  f0bc9ec:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bc9f0:	01996023 */ 	subu	$t4,$t4,$t9
/*  f0bc9f4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bc9f8:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0bc9fc:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0bca00:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*  f0bca04:	01cf2023 */ 	subu	$a0,$t6,$t7
/*  f0bca08:	0004c400 */ 	sll	$t8,$a0,0x10
/*  f0bca0c:	1000001f */ 	b	.L0f0bca8c
/*  f0bca10:	00182403 */ 	sra	$a0,$t8,0x10
.L0f0bca14:
/*  f0bca14:	8d8c06c8 */ 	lw	$t4,%lo(g_HiResActive)($t4)
/*  f0bca18:	3c0e8007 */ 	lui	$t6,%hi(var800705c0)
/*  f0bca1c:	25ce05c0 */ 	addiu	$t6,$t6,%lo(var800705c0)
/*  f0bca20:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bca24:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bca28:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bca2c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bca30:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bca34:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f0bca38:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0bca3c:	8c580008 */ 	lw	$t8,0x8($v0)
/*  f0bca40:	01f82023 */ 	subu	$a0,$t7,$t8
/*  f0bca44:	0004cc00 */ 	sll	$t9,$a0,0x10
/*  f0bca48:	10000010 */ 	b	.L0f0bca8c
/*  f0bca4c:	00192403 */ 	sra	$a0,$t9,0x10
.L0f0bca50:
/*  f0bca50:	3c0d8007 */ 	lui	$t5,%hi(g_HiResActive)
/*  f0bca54:	8dad06c8 */ 	lw	$t5,%lo(g_HiResActive)($t5)
/*  f0bca58:	3c0f8007 */ 	lui	$t7,%hi(var800705c0)
/*  f0bca5c:	25ef05c0 */ 	addiu	$t7,$t7,%lo(var800705c0)
/*  f0bca60:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0bca64:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0bca68:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0bca6c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0bca70:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0bca74:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0bca78:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0bca7c:	8c590008 */ 	lw	$t9,0x8($v0)
/*  f0bca80:	03192023 */ 	subu	$a0,$t8,$t9
/*  f0bca84:	00046400 */ 	sll	$t4,$a0,0x10
/*  f0bca88:	000c2403 */ 	sra	$a0,$t4,0x10
.L0f0bca8c:
/*  f0bca8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bca90:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0bca94:	00801025 */ 	or	$v0,$a0,$zero
/*  f0bca98:	03e00008 */ 	jr	$ra
/*  f0bca9c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bcaa0
/*  f0bcaa0:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bcaa4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bcaa8:	8cce006c */ 	lw	$t6,0x6c($a2)
/*  f0bcaac:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0bcab0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bcab4:	11c00003 */ 	beqz	$t6,.L0f0bcac4
/*  f0bcab8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0bcabc:	10000001 */ 	b	.L0f0bcac4
/*  f0bcac0:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0bcac4:
/*  f0bcac4:	8ccf0068 */ 	lw	$t7,0x68($a2)
/*  f0bcac8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bcacc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bcad0:	11e00003 */ 	beqz	$t7,.L0f0bcae0
/*  f0bcad4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bcad8:	10000001 */ 	b	.L0f0bcae0
/*  f0bcadc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bcae0:
/*  f0bcae0:	8cd80064 */ 	lw	$t8,0x64($a2)
/*  f0bcae4:	13000003 */ 	beqz	$t8,.L0f0bcaf4
/*  f0bcae8:	00000000 */ 	nop
/*  f0bcaec:	10000001 */ 	b	.L0f0bcaf4
/*  f0bcaf0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0bcaf4:
/*  f0bcaf4:	8cd90070 */ 	lw	$t9,0x70($a2)
/*  f0bcaf8:	13200003 */ 	beqz	$t9,.L0f0bcb08
/*  f0bcafc:	00000000 */ 	nop
/*  f0bcb00:	10000001 */ 	b	.L0f0bcb08
/*  f0bcb04:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bcb08:
/*  f0bcb08:	00435021 */ 	addu	$t2,$v0,$v1
/*  f0bcb0c:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0bcb10:	01676021 */ 	addu	$t4,$t3,$a3
/*  f0bcb14:	29810002 */ 	slti	$at,$t4,0x2
/*  f0bcb18:	1420005f */ 	bnez	$at,.L0f0bcc98
/*  f0bcb1c:	00000000 */ 	nop
/*  f0bcb20:	0fc2f130 */ 	jal	func0f0bc4c0
/*  f0bcb24:	00000000 */ 	nop
/*  f0bcb28:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bcb2c:	1440005a */ 	bnez	$v0,.L0f0bcc98
/*  f0bcb30:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bcb34:	3c0d8007 */ 	lui	$t5,%hi(g_HiResActive)
/*  f0bcb38:	8dad06c8 */ 	lw	$t5,%lo(g_HiResActive)($t5)
/*  f0bcb3c:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f0bcb40:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f0bcb44:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0bcb48:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0bcb4c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0bcb50:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0bcb54:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0bcb58:	3c088007 */ 	lui	$t0,%hi(var800705c0+0x16)
/*  f0bcb5c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bcb60:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f0bcb64:	152f0008 */ 	bne	$t1,$t7,.L0f0bcb88
/*  f0bcb68:	850805d6 */ 	lh	$t0,%lo(var800705c0+0x16)($t0)
/*  f0bcb6c:	90d804e0 */ 	lbu	$t8,0x4e0($a2)
/*  f0bcb70:	00082400 */ 	sll	$a0,$t0,0x10
/*  f0bcb74:	0004cc03 */ 	sra	$t9,$a0,0x10
/*  f0bcb78:	17000003 */ 	bnez	$t8,.L0f0bcb88
/*  f0bcb7c:	00000000 */ 	nop
/*  f0bcb80:	10000007 */ 	b	.L0f0bcba0
/*  f0bcb84:	03202025 */ 	or	$a0,$t9,$zero
.L0f0bcb88:
/*  f0bcb88:	05010003 */ 	bgez	$t0,.L0f0bcb98
/*  f0bcb8c:	00082043 */ 	sra	$a0,$t0,0x1
/*  f0bcb90:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0bcb94:	00012043 */ 	sra	$a0,$at,0x1
.L0f0bcb98:
/*  f0bcb98:	00045400 */ 	sll	$t2,$a0,0x10
/*  f0bcb9c:	000a2403 */ 	sra	$a0,$t2,0x10
.L0f0bcba0:
/*  f0bcba0:	8ccc006c */ 	lw	$t4,0x6c($a2)
/*  f0bcba4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bcba8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0bcbac:	11800003 */ 	beqz	$t4,.L0f0bcbbc
/*  f0bcbb0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bcbb4:	10000001 */ 	b	.L0f0bcbbc
/*  f0bcbb8:	01203825 */ 	or	$a3,$t1,$zero
.L0f0bcbbc:
/*  f0bcbbc:	8ccd0068 */ 	lw	$t5,0x68($a2)
/*  f0bcbc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bcbc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bcbc8:	11a00003 */ 	beqz	$t5,.L0f0bcbd8
/*  f0bcbcc:	00000000 */ 	nop
/*  f0bcbd0:	10000001 */ 	b	.L0f0bcbd8
/*  f0bcbd4:	01202825 */ 	or	$a1,$t1,$zero
.L0f0bcbd8:
/*  f0bcbd8:	8cce0064 */ 	lw	$t6,0x64($a2)
/*  f0bcbdc:	11c00003 */ 	beqz	$t6,.L0f0bcbec
/*  f0bcbe0:	00000000 */ 	nop
/*  f0bcbe4:	10000001 */ 	b	.L0f0bcbec
/*  f0bcbe8:	01201825 */ 	or	$v1,$t1,$zero
.L0f0bcbec:
/*  f0bcbec:	8ccf0070 */ 	lw	$t7,0x70($a2)
/*  f0bcbf0:	11e00003 */ 	beqz	$t7,.L0f0bcc00
/*  f0bcbf4:	00000000 */ 	nop
/*  f0bcbf8:	10000001 */ 	b	.L0f0bcc00
/*  f0bcbfc:	01201025 */ 	or	$v0,$t1,$zero
.L0f0bcc00:
/*  f0bcc00:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0bcc04:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0bcc08:	03275021 */ 	addu	$t2,$t9,$a3
/*  f0bcc0c:	5541001a */ 	bnel	$t2,$at,.L0f0bcc78
/*  f0bcc10:	8cc2028c */ 	lw	$v0,0x28c($a2)
/*  f0bcc14:	a7a4001e */ 	sh	$a0,0x1e($sp)
/*  f0bcc18:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0bcc1c:	a7a8001c */ 	sh	$t0,0x1c($sp)
/*  f0bcc20:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bcc24:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bcc28:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bcc2c:	87a4001e */ 	lh	$a0,0x1e($sp)
/*  f0bcc30:	15220005 */ 	bne	$t1,$v0,.L0f0bcc48
/*  f0bcc34:	87a8001c */ 	lh	$t0,0x1c($sp)
/*  f0bcc38:	00082400 */ 	sll	$a0,$t0,0x10
/*  f0bcc3c:	00045c03 */ 	sra	$t3,$a0,0x10
/*  f0bcc40:	10000073 */ 	b	.L0f0bce10
/*  f0bcc44:	01602025 */ 	or	$a0,$t3,$zero
.L0f0bcc48:
/*  f0bcc48:	8ccc028c */ 	lw	$t4,0x28c($a2)
/*  f0bcc4c:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f0bcc50:	55800070 */ 	bnezl	$t4,.L0f0bce14
/*  f0bcc54:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bcc58:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f0bcc5c:	512d006d */ 	beql	$t1,$t5,.L0f0bce14
/*  f0bcc60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bcc64:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f0bcc68:	00047400 */ 	sll	$t6,$a0,0x10
/*  f0bcc6c:	10000068 */ 	b	.L0f0bce10
/*  f0bcc70:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f0bcc74:	8cc2028c */ 	lw	$v0,0x28c($a2)
.L0f0bcc78:
/*  f0bcc78:	50400004 */ 	beqzl	$v0,.L0f0bcc8c
/*  f0bcc7c:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f0bcc80:	55220064 */ 	bnel	$t1,$v0,.L0f0bce14
/*  f0bcc84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bcc88:	2484ffff */ 	addiu	$a0,$a0,-1
.L0f0bcc8c:
/*  f0bcc8c:	0004c400 */ 	sll	$t8,$a0,0x10
/*  f0bcc90:	1000005f */ 	b	.L0f0bce10
/*  f0bcc94:	00182403 */ 	sra	$a0,$t8,0x10
.L0f0bcc98:
/*  f0bcc98:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0bcc9c:	00000000 */ 	nop
/*  f0bcca0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bcca4:	1449000b */ 	bne	$v0,$t1,.L0f0bccd4
/*  f0bcca8:	3c0a8007 */ 	lui	$t2,%hi(g_HiResActive)
/*  f0bccac:	8d4a06c8 */ 	lw	$t2,%lo(g_HiResActive)($t2)
/*  f0bccb0:	3c048007 */ 	lui	$a0,%hi(var800705c0+0x1e)
/*  f0bccb4:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0bccb8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0bccbc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0bccc0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0bccc4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0bccc8:	008b2021 */ 	addu	$a0,$a0,$t3
/*  f0bcccc:	10000050 */ 	b	.L0f0bce10
/*  f0bccd0:	848405de */ 	lh	$a0,%lo(var800705c0+0x1e)($a0)
.L0f0bccd4:
/*  f0bccd4:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0bccd8:	00000000 */ 	nop
/*  f0bccdc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bcce0:	1441000c */ 	bne	$v0,$at,.L0f0bcd14
/*  f0bcce4:	3c0e8007 */ 	lui	$t6,%hi(var80070764)
/*  f0bcce8:	3c0c8007 */ 	lui	$t4,%hi(g_HiResActive)
/*  f0bccec:	8d8c06c8 */ 	lw	$t4,%lo(g_HiResActive)($t4)
/*  f0bccf0:	3c048007 */ 	lui	$a0,%hi(var800705c0+0x26)
/*  f0bccf4:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bccf8:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bccfc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bcd00:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bcd04:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bcd08:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0bcd0c:	10000040 */ 	b	.L0f0bce10
/*  f0bcd10:	848405e6 */ 	lh	$a0,%lo(var800705c0+0x26)($a0)
.L0f0bcd14:
/*  f0bcd14:	8dce0764 */ 	lw	$t6,%lo(var80070764)($t6)
/*  f0bcd18:	3c0f800a */ 	lui	$t7,%hi(var8009dfc0)
/*  f0bcd1c:	3c0b8007 */ 	lui	$t3,%hi(g_HiResActive)
/*  f0bcd20:	11c00032 */ 	beqz	$t6,.L0f0bcdec
/*  f0bcd24:	00000000 */ 	nop
/*  f0bcd28:	8defdfc0 */ 	lw	$t7,%lo(var8009dfc0)($t7)
/*  f0bcd2c:	3c18800a */ 	lui	$t8,%hi(var8009de2c)
/*  f0bcd30:	15e0002e */ 	bnez	$t7,.L0f0bcdec
/*  f0bcd34:	00000000 */ 	nop
/*  f0bcd38:	8f18de2c */ 	lw	$t8,%lo(var8009de2c)($t8)
/*  f0bcd3c:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bcd40:	3c0b8007 */ 	lui	$t3,%hi(var800705c0)
/*  f0bcd44:	1b00001e */ 	blez	$t8,.L0f0bcdc0
/*  f0bcd48:	00000000 */ 	nop
/*  f0bcd4c:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bcd50:	256b05c0 */ 	addiu	$t3,$t3,%lo(var800705c0)
/*  f0bcd54:	3c01800a */ 	lui	$at,%hi(var8009de30)
/*  f0bcd58:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0bcd5c:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bcd60:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bcd64:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bcd68:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bcd6c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0bcd70:	8c4c001c */ 	lw	$t4,0x1c($v0)
/*  f0bcd74:	8c4d0014 */ 	lw	$t5,0x14($v0)
/*  f0bcd78:	c42cde30 */ 	lwc1	$f12,%lo(var8009de30)($at)
/*  f0bcd7c:	448c2000 */ 	mtc1	$t4,$f4
/*  f0bcd80:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bcd84:	44814000 */ 	mtc1	$at,$f8
/*  f0bcd88:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0bcd8c:	448d3000 */ 	mtc1	$t5,$f6
/*  f0bcd90:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f0bcd94:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0bcd98:	46005002 */ 	mul.s	$f0,$f10,$f0
/*  f0bcd9c:	00000000 */ 	nop
/*  f0bcda0:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0bcda4:	46020400 */ 	add.s	$f16,$f0,$f2
/*  f0bcda8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0bcdac:	44049000 */ 	mfc1	$a0,$f18
/*  f0bcdb0:	00000000 */ 	nop
/*  f0bcdb4:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f0bcdb8:	10000015 */ 	b	.L0f0bce10
/*  f0bcdbc:	000f2403 */ 	sra	$a0,$t7,0x10
.L0f0bcdc0:
/*  f0bcdc0:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bcdc4:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bcdc8:	3c048007 */ 	lui	$a0,%hi(var800705c0+0x1e)
/*  f0bcdcc:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0bcdd0:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bcdd4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bcdd8:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bcddc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bcde0:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0bcde4:	1000000a */ 	b	.L0f0bce10
/*  f0bcde8:	848405de */ 	lh	$a0,%lo(var800705c0+0x1e)($a0)
.L0f0bcdec:
/*  f0bcdec:	8d6b06c8 */ 	lw	$t3,%lo(g_HiResActive)($t3)
/*  f0bcdf0:	3c048007 */ 	lui	$a0,%hi(var800705c0+0x16)
/*  f0bcdf4:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0bcdf8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bcdfc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bce00:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bce04:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bce08:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0bce0c:	848405d6 */ 	lh	$a0,%lo(var800705c0+0x16)($a0)
.L0f0bce10:
/*  f0bce10:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0bce14:
/*  f0bce14:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0bce18:	00801025 */ 	or	$v0,$a0,$zero
/*  f0bce1c:	03e00008 */ 	jr	$ra
/*  f0bce20:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bce24
/*  f0bce24:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0bce28:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0bce2c:	8cee006c */ 	lw	$t6,0x6c($a3)
/*  f0bce30:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0bce34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bce38:	11c00003 */ 	beqz	$t6,.L0f0bce48
/*  f0bce3c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bce40:	10000001 */ 	b	.L0f0bce48
/*  f0bce44:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bce48:
/*  f0bce48:	8cef0068 */ 	lw	$t7,0x68($a3)
/*  f0bce4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bce50:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bce54:	11e00003 */ 	beqz	$t7,.L0f0bce64
/*  f0bce58:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bce5c:	10000001 */ 	b	.L0f0bce64
/*  f0bce60:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bce64:
/*  f0bce64:	8cf80064 */ 	lw	$t8,0x64($a3)
/*  f0bce68:	13000003 */ 	beqz	$t8,.L0f0bce78
/*  f0bce6c:	00000000 */ 	nop
/*  f0bce70:	10000001 */ 	b	.L0f0bce78
/*  f0bce74:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0bce78:
/*  f0bce78:	8cf90070 */ 	lw	$t9,0x70($a3)
/*  f0bce7c:	13200003 */ 	beqz	$t9,.L0f0bce8c
/*  f0bce80:	00000000 */ 	nop
/*  f0bce84:	10000001 */ 	b	.L0f0bce8c
/*  f0bce88:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bce8c:
/*  f0bce8c:	00435021 */ 	addu	$t2,$v0,$v1
/*  f0bce90:	01445821 */ 	addu	$t3,$t2,$a0
/*  f0bce94:	01656021 */ 	addu	$t4,$t3,$a1
/*  f0bce98:	29810002 */ 	slti	$at,$t4,0x2
/*  f0bce9c:	14200087 */ 	bnez	$at,.L0f0bd0bc
/*  f0bcea0:	00000000 */ 	nop
/*  f0bcea4:	0fc2f130 */ 	jal	func0f0bc4c0
/*  f0bcea8:	00000000 */ 	nop
/*  f0bceac:	14400083 */ 	bnez	$v0,.L0f0bd0bc
/*  f0bceb0:	3c0d8007 */ 	lui	$t5,%hi(g_HiResActive)
/*  f0bceb4:	8dad06c8 */ 	lw	$t5,%lo(g_HiResActive)($t5)
/*  f0bceb8:	3c068007 */ 	lui	$a2,%hi(var800705c0+0x1a)
/*  f0bcebc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0bcec0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0bcec4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0bcec8:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0bcecc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0bced0:	00ce3021 */ 	addu	$a2,$a2,$t6
/*  f0bced4:	84c605da */ 	lh	$a2,%lo(var800705c0+0x1a)($a2)
/*  f0bced8:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0bcedc:	a7a6001e */ 	sh	$a2,0x1e($sp)
/*  f0bcee0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0bcee4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bcee8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0bceec:	1522001e */ 	bne	$t1,$v0,.L0f0bcf68
/*  f0bcef0:	87a6001e */ 	lh	$a2,0x1e($sp)
/*  f0bcef4:	8cef006c */ 	lw	$t7,0x6c($a3)
/*  f0bcef8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bcefc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bcf00:	11e00003 */ 	beqz	$t7,.L0f0bcf10
/*  f0bcf04:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bcf08:	10000001 */ 	b	.L0f0bcf10
/*  f0bcf0c:	01202825 */ 	or	$a1,$t1,$zero
.L0f0bcf10:
/*  f0bcf10:	8cf80068 */ 	lw	$t8,0x68($a3)
/*  f0bcf14:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bcf18:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bcf1c:	13000003 */ 	beqz	$t8,.L0f0bcf2c
/*  f0bcf20:	00000000 */ 	nop
/*  f0bcf24:	10000001 */ 	b	.L0f0bcf2c
/*  f0bcf28:	01202025 */ 	or	$a0,$t1,$zero
.L0f0bcf2c:
/*  f0bcf2c:	8cf90064 */ 	lw	$t9,0x64($a3)
/*  f0bcf30:	13200003 */ 	beqz	$t9,.L0f0bcf40
/*  f0bcf34:	00000000 */ 	nop
/*  f0bcf38:	10000001 */ 	b	.L0f0bcf40
/*  f0bcf3c:	01201825 */ 	or	$v1,$t1,$zero
.L0f0bcf40:
/*  f0bcf40:	8cea0070 */ 	lw	$t2,0x70($a3)
/*  f0bcf44:	11400003 */ 	beqz	$t2,.L0f0bcf54
/*  f0bcf48:	00000000 */ 	nop
/*  f0bcf4c:	10000001 */ 	b	.L0f0bcf54
/*  f0bcf50:	01201025 */ 	or	$v0,$t1,$zero
.L0f0bcf54:
/*  f0bcf54:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0bcf58:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0bcf5c:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0bcf60:	51a100f9 */ 	beql	$t5,$at,.L0f0bd348
/*  f0bcf64:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0bcf68:
/*  f0bcf68:	8cee006c */ 	lw	$t6,0x6c($a3)
/*  f0bcf6c:	8ce20068 */ 	lw	$v0,0x68($a3)
/*  f0bcf70:	8ce30064 */ 	lw	$v1,0x64($a3)
/*  f0bcf74:	11c00003 */ 	beqz	$t6,.L0f0bcf84
/*  f0bcf78:	8ce80070 */ 	lw	$t0,0x70($a3)
/*  f0bcf7c:	10000002 */ 	b	.L0f0bcf88
/*  f0bcf80:	01202825 */ 	or	$a1,$t1,$zero
.L0f0bcf84:
/*  f0bcf84:	00002825 */ 	or	$a1,$zero,$zero
.L0f0bcf88:
/*  f0bcf88:	10400003 */ 	beqz	$v0,.L0f0bcf98
/*  f0bcf8c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bcf90:	10000002 */ 	b	.L0f0bcf9c
/*  f0bcf94:	01202025 */ 	or	$a0,$t1,$zero
.L0f0bcf98:
/*  f0bcf98:	00002025 */ 	or	$a0,$zero,$zero
.L0f0bcf9c:
/*  f0bcf9c:	10600003 */ 	beqz	$v1,.L0f0bcfac
/*  f0bcfa0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bcfa4:	10000002 */ 	b	.L0f0bcfb0
/*  f0bcfa8:	01201825 */ 	or	$v1,$t1,$zero
.L0f0bcfac:
/*  f0bcfac:	00001825 */ 	or	$v1,$zero,$zero
.L0f0bcfb0:
/*  f0bcfb0:	11000003 */ 	beqz	$t0,.L0f0bcfc0
/*  f0bcfb4:	00000000 */ 	nop
/*  f0bcfb8:	10000001 */ 	b	.L0f0bcfc0
/*  f0bcfbc:	01201025 */ 	or	$v0,$t1,$zero
.L0f0bcfc0:
/*  f0bcfc0:	00437821 */ 	addu	$t7,$v0,$v1
/*  f0bcfc4:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0bcfc8:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0bcfcc:	57210023 */ 	bnel	$t9,$at,.L0f0bd05c
/*  f0bcfd0:	8ce2028c */ 	lw	$v0,0x28c($a3)
/*  f0bcfd4:	8cea028c */ 	lw	$t2,0x28c($a3)
/*  f0bcfd8:	552a0020 */ 	bnel	$t1,$t2,.L0f0bd05c
/*  f0bcfdc:	8ce2028c */ 	lw	$v0,0x28c($a3)
/*  f0bcfe0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0bcfe4:	a7a6001e */ 	sh	$a2,0x1e($sp)
/*  f0bcfe8:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0bcfec:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bcff0:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0bcff4:	11220018 */ 	beq	$t1,$v0,.L0f0bd058
/*  f0bcff8:	87a6001e */ 	lh	$a2,0x1e($sp)
/*  f0bcffc:	90eb04e0 */ 	lbu	$t3,0x4e0($a3)
/*  f0bd000:	3c0c8007 */ 	lui	$t4,%hi(g_HiResActive)
/*  f0bd004:	55600015 */ 	bnezl	$t3,.L0f0bd05c
/*  f0bd008:	8ce2028c */ 	lw	$v0,0x28c($a3)
/*  f0bd00c:	8d8c06c8 */ 	lw	$t4,%lo(g_HiResActive)($t4)
/*  f0bd010:	3c0e8007 */ 	lui	$t6,%hi(var800705c0)
/*  f0bd014:	25ce05c0 */ 	addiu	$t6,$t6,%lo(var800705c0)
/*  f0bd018:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bd01c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bd020:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bd024:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bd028:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bd02c:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f0bd030:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f0bd034:	8c590018 */ 	lw	$t9,0x18($v0)
/*  f0bd038:	05e10003 */ 	bgez	$t7,.L0f0bd048
/*  f0bd03c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0bd040:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0bd044:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0bd048:
/*  f0bd048:	03193021 */ 	addu	$a2,$t8,$t9
/*  f0bd04c:	00065400 */ 	sll	$t2,$a2,0x10
/*  f0bd050:	100000bc */ 	b	.L0f0bd344
/*  f0bd054:	000a3403 */ 	sra	$a2,$t2,0x10
.L0f0bd058:
/*  f0bd058:	8ce2028c */ 	lw	$v0,0x28c($a3)
.L0f0bd05c:
/*  f0bd05c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bd060:	10410002 */ 	beq	$v0,$at,.L0f0bd06c
/*  f0bd064:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0bd068:	144100b6 */ 	bne	$v0,$at,.L0f0bd344
.L0f0bd06c:
/*  f0bd06c:	3c0c8007 */ 	lui	$t4,%hi(g_HiResActive)
/*  f0bd070:	8d8c06c8 */ 	lw	$t4,%lo(g_HiResActive)($t4)
/*  f0bd074:	3c0e8007 */ 	lui	$t6,%hi(var800705c0)
/*  f0bd078:	25ce05c0 */ 	addiu	$t6,$t6,%lo(var800705c0)
/*  f0bd07c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0bd080:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bd084:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bd088:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0bd08c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0bd090:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f0bd094:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f0bd098:	8c590018 */ 	lw	$t9,0x18($v0)
/*  f0bd09c:	05e10003 */ 	bgez	$t7,.L0f0bd0ac
/*  f0bd0a0:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0bd0a4:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0bd0a8:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0bd0ac:
/*  f0bd0ac:	03193021 */ 	addu	$a2,$t8,$t9
/*  f0bd0b0:	00065400 */ 	sll	$t2,$a2,0x10
/*  f0bd0b4:	100000a3 */ 	b	.L0f0bd344
/*  f0bd0b8:	000a3403 */ 	sra	$a2,$t2,0x10
.L0f0bd0bc:
/*  f0bd0bc:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0bd0c0:	00000000 */ 	nop
/*  f0bd0c4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bd0c8:	14490046 */ 	bne	$v0,$t1,.L0f0bd1e4
/*  f0bd0cc:	3c0c8007 */ 	lui	$t4,%hi(var80070764)
/*  f0bd0d0:	8d8c0764 */ 	lw	$t4,%lo(var80070764)($t4)
/*  f0bd0d4:	11800038 */ 	beqz	$t4,.L0f0bd1b8
/*  f0bd0d8:	00000000 */ 	nop
/*  f0bd0dc:	0fc54a46 */ 	jal	optionsGetCutsceneSubtitles
/*  f0bd0e0:	00000000 */ 	nop
/*  f0bd0e4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0bd0e8:	10400033 */ 	beqz	$v0,.L0f0bd1b8
/*  f0bd0ec:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0bd0f0:	8ced04b4 */ 	lw	$t5,0x4b4($a3)
/*  f0bd0f4:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0bd0f8:	3c0e800a */ 	lui	$t6,%hi(var8009de2c)
/*  f0bd0fc:	11a1002e */ 	beq	$t5,$at,.L0f0bd1b8
/*  f0bd100:	00000000 */ 	nop
/*  f0bd104:	8dcede2c */ 	lw	$t6,%lo(var8009de2c)($t6)
/*  f0bd108:	3c0f8007 */ 	lui	$t7,%hi(g_HiResActive)
/*  f0bd10c:	3c198007 */ 	lui	$t9,%hi(var800705c0)
/*  f0bd110:	19c0001e */ 	blez	$t6,.L0f0bd18c
/*  f0bd114:	00000000 */ 	nop
/*  f0bd118:	8def06c8 */ 	lw	$t7,%lo(g_HiResActive)($t7)
/*  f0bd11c:	273905c0 */ 	addiu	$t9,$t9,%lo(var800705c0)
/*  f0bd120:	3c01800a */ 	lui	$at,%hi(var8009de30)
/*  f0bd124:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bd128:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bd12c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bd130:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bd134:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bd138:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0bd13c:	8c4a0018 */ 	lw	$t2,0x18($v0)
/*  f0bd140:	8c4b0020 */ 	lw	$t3,0x20($v0)
/*  f0bd144:	c42cde30 */ 	lwc1	$f12,%lo(var8009de30)($at)
/*  f0bd148:	448a2000 */ 	mtc1	$t2,$f4
/*  f0bd14c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bd150:	44814000 */ 	mtc1	$at,$f8
/*  f0bd154:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0bd158:	448b3000 */ 	mtc1	$t3,$f6
/*  f0bd15c:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f0bd160:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0bd164:	46005002 */ 	mul.s	$f0,$f10,$f0
/*  f0bd168:	00000000 */ 	nop
/*  f0bd16c:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0bd170:	46020400 */ 	add.s	$f16,$f0,$f2
/*  f0bd174:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0bd178:	44069000 */ 	mfc1	$a2,$f18
/*  f0bd17c:	00000000 */ 	nop
/*  f0bd180:	00066c00 */ 	sll	$t5,$a2,0x10
/*  f0bd184:	1000006f */ 	b	.L0f0bd344
/*  f0bd188:	000d3403 */ 	sra	$a2,$t5,0x10
.L0f0bd18c:
/*  f0bd18c:	3c0f8007 */ 	lui	$t7,%hi(g_HiResActive)
/*  f0bd190:	8def06c8 */ 	lw	$t7,%lo(g_HiResActive)($t7)
/*  f0bd194:	3c068007 */ 	lui	$a2,%hi(var800705c0+0x1a)
/*  f0bd198:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bd19c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bd1a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bd1a4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bd1a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bd1ac:	00d83021 */ 	addu	$a2,$a2,$t8
/*  f0bd1b0:	10000064 */ 	b	.L0f0bd344
/*  f0bd1b4:	84c605da */ 	lh	$a2,%lo(var800705c0+0x1a)($a2)
.L0f0bd1b8:
/*  f0bd1b8:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bd1bc:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bd1c0:	3c068007 */ 	lui	$a2,%hi(var800705c0+0x22)
/*  f0bd1c4:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0bd1c8:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bd1cc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bd1d0:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bd1d4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bd1d8:	00ca3021 */ 	addu	$a2,$a2,$t2
/*  f0bd1dc:	10000059 */ 	b	.L0f0bd344
/*  f0bd1e0:	84c605e2 */ 	lh	$a2,%lo(var800705c0+0x22)($a2)
.L0f0bd1e4:
/*  f0bd1e4:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0bd1e8:	00000000 */ 	nop
/*  f0bd1ec:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bd1f0:	1441000c */ 	bne	$v0,$at,.L0f0bd224
/*  f0bd1f4:	3c0d8007 */ 	lui	$t5,%hi(var80070764)
/*  f0bd1f8:	3c0b8007 */ 	lui	$t3,%hi(g_HiResActive)
/*  f0bd1fc:	8d6b06c8 */ 	lw	$t3,%lo(g_HiResActive)($t3)
/*  f0bd200:	3c068007 */ 	lui	$a2,%hi(var800705c0+0x2a)
/*  f0bd204:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0bd208:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bd20c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bd210:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bd214:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bd218:	00cc3021 */ 	addu	$a2,$a2,$t4
/*  f0bd21c:	10000049 */ 	b	.L0f0bd344
/*  f0bd220:	84c605ea */ 	lh	$a2,%lo(var800705c0+0x2a)($a2)
.L0f0bd224:
/*  f0bd224:	8dad0764 */ 	lw	$t5,%lo(var80070764)($t5)
/*  f0bd228:	3c0e800a */ 	lui	$t6,%hi(var8009dfc0)
/*  f0bd22c:	11a0003a */ 	beqz	$t5,.L0f0bd318
/*  f0bd230:	00000000 */ 	nop
/*  f0bd234:	8dcedfc0 */ 	lw	$t6,%lo(var8009dfc0)($t6)
/*  f0bd238:	15c00037 */ 	bnez	$t6,.L0f0bd318
/*  f0bd23c:	00000000 */ 	nop
/*  f0bd240:	0fc54a46 */ 	jal	optionsGetCutsceneSubtitles
/*  f0bd244:	00000000 */ 	nop
/*  f0bd248:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0bd24c:	10400004 */ 	beqz	$v0,.L0f0bd260
/*  f0bd250:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0bd254:	8cef04b4 */ 	lw	$t7,0x4b4($a3)
/*  f0bd258:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0bd25c:	15e1002e */ 	bne	$t7,$at,.L0f0bd318
.L0f0bd260:
/*  f0bd260:	3c18800a */ 	lui	$t8,%hi(var8009de2c)
/*  f0bd264:	8f18de2c */ 	lw	$t8,%lo(var8009de2c)($t8)
/*  f0bd268:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bd26c:	3c0b8007 */ 	lui	$t3,%hi(var800705c0)
/*  f0bd270:	1b00001e */ 	blez	$t8,.L0f0bd2ec
/*  f0bd274:	00000000 */ 	nop
/*  f0bd278:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bd27c:	256b05c0 */ 	addiu	$t3,$t3,%lo(var800705c0)
/*  f0bd280:	3c01800a */ 	lui	$at,%hi(var8009de30)
/*  f0bd284:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0bd288:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bd28c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bd290:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bd294:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bd298:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0bd29c:	8c4c0020 */ 	lw	$t4,0x20($v0)
/*  f0bd2a0:	8c4d0018 */ 	lw	$t5,0x18($v0)
/*  f0bd2a4:	c42cde30 */ 	lwc1	$f12,%lo(var8009de30)($at)
/*  f0bd2a8:	448c2000 */ 	mtc1	$t4,$f4
/*  f0bd2ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bd2b0:	44814000 */ 	mtc1	$at,$f8
/*  f0bd2b4:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0bd2b8:	448d3000 */ 	mtc1	$t5,$f6
/*  f0bd2bc:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f0bd2c0:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0bd2c4:	46005002 */ 	mul.s	$f0,$f10,$f0
/*  f0bd2c8:	00000000 */ 	nop
/*  f0bd2cc:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0bd2d0:	46020400 */ 	add.s	$f16,$f0,$f2
/*  f0bd2d4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0bd2d8:	44069000 */ 	mfc1	$a2,$f18
/*  f0bd2dc:	00000000 */ 	nop
/*  f0bd2e0:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0bd2e4:	10000017 */ 	b	.L0f0bd344
/*  f0bd2e8:	000f3403 */ 	sra	$a2,$t7,0x10
.L0f0bd2ec:
/*  f0bd2ec:	3c198007 */ 	lui	$t9,%hi(g_HiResActive)
/*  f0bd2f0:	8f3906c8 */ 	lw	$t9,%lo(g_HiResActive)($t9)
/*  f0bd2f4:	3c068007 */ 	lui	$a2,%hi(var800705c0+0x22)
/*  f0bd2f8:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0bd2fc:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bd300:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bd304:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0bd308:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bd30c:	00ca3021 */ 	addu	$a2,$a2,$t2
/*  f0bd310:	1000000c */ 	b	.L0f0bd344
/*  f0bd314:	84c605e2 */ 	lh	$a2,%lo(var800705c0+0x22)($a2)
.L0f0bd318:
/*  f0bd318:	3c0b8007 */ 	lui	$t3,%hi(g_HiResActive)
/*  f0bd31c:	8d6b06c8 */ 	lw	$t3,%lo(g_HiResActive)($t3)
/*  f0bd320:	3c028007 */ 	lui	$v0,%hi(var800705c0+0x1a)
/*  f0bd324:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0bd328:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bd32c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bd330:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bd334:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bd338:	004c1021 */ 	addu	$v0,$v0,$t4
/*  f0bd33c:	10000002 */ 	b	.L0f0bd348
/*  f0bd340:	844205da */ 	lh	$v0,%lo(var800705c0+0x1a)($v0)
.L0f0bd344:
/*  f0bd344:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0bd348:
/*  f0bd348:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bd34c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0bd350:	03e00008 */ 	jr	$ra
/*  f0bd354:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bd358
/*  f0bd358:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0bd35c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bd360:	0fc2f2a8 */ 	jal	func0f0bcaa0
/*  f0bd364:	00000000 */ 	nop
/*  f0bd368:	0fc2f155 */ 	jal	func0f0bc554
/*  f0bd36c:	a7a20018 */ 	sh	$v0,0x18($sp)
/*  f0bd370:	87ae0018 */ 	lh	$t6,0x18($sp)
/*  f0bd374:	44822000 */ 	mtc1	$v0,$f4
/*  f0bd378:	3c0f8007 */ 	lui	$t7,%hi(g_HiResActive)
/*  f0bd37c:	448e4000 */ 	mtc1	$t6,$f8
/*  f0bd380:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0bd384:	8def06c8 */ 	lw	$t7,%lo(g_HiResActive)($t7)
/*  f0bd388:	3c018007 */ 	lui	$at,%hi(var800705c0+0xc)
/*  f0bd38c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bd390:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bd394:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0bd398:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bd39c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bd3a0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bd3a4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bd3a8:	00380821 */ 	addu	$at,$at,$t8
/*  f0bd3ac:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f0bd3b0:	c43205cc */ 	lwc1	$f18,%lo(var800705c0+0xc)($at)
/*  f0bd3b4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0bd3b8:	46109082 */ 	mul.s	$f2,$f18,$f16
/*  f0bd3bc:	03e00008 */ 	jr	$ra
/*  f0bd3c0:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f0bd3c4
/*  f0bd3c4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0bd3c8:	3c0e8007 */ 	lui	$t6,%hi(var800709c4)
/*  f0bd3cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bd3d0:	25ce09c4 */ 	addiu	$t6,$t6,%lo(var800709c4)
/*  f0bd3d4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0bd3d8:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f0bd3dc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0bd3e0:	acc10000 */ 	sw	$at,0x0($a2)
/*  f0bd3e4:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0bd3e8:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f0bd3ec:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0bd3f0:	acc10008 */ 	sw	$at,0x8($a2)
/*  f0bd3f4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0bd3f8:	8c4800d8 */ 	lw	$t0,0xd8($v0)
/*  f0bd3fc:	2444037c */ 	addiu	$a0,$v0,0x37c
/*  f0bd400:	55000006 */ 	bnezl	$t0,.L0f0bd41c
/*  f0bd404:	44806000 */ 	mtc1	$zero,$f12
/*  f0bd408:	0fc4ab3b */ 	jal	func0f12acec
/*  f0bd40c:	24450388 */ 	addiu	$a1,$v0,0x388
/*  f0bd410:	10000005 */ 	b	.L0f0bd428
/*  f0bd414:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bd418:	44806000 */ 	mtc1	$zero,$f12
.L0f0bd41c:
/*  f0bd41c:	0c002a94 */ 	jal	func0000aa50
/*  f0bd420:	00000000 */ 	nop
/*  f0bd424:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0bd428:
/*  f0bd428:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0bd42c:	03e00008 */ 	jr	$ra
/*  f0bd430:	00000000 */ 	nop
);

void currentPlayerAutoWalk(s16 aimpad, u8 walkspeed, u8 turnspeed, u8 lookup, u8 dist)
{
	setTickMode(TICKMODE_AUTOWALK);
	g_Vars.currentplayer->autocontrol_aimpad = aimpad;
	g_Vars.currentplayer->autocontrol_walkspeed = walkspeed;
	g_Vars.currentplayer->autocontrol_turnspeed = turnspeed;
	g_Vars.currentplayer->autocontrol_lookup = lookup;
	g_Vars.currentplayer->autocontrol_dist = dist;
}

void currentPlayerLaunchSlayerRocket(struct weaponobj *rocket)
{
	g_Vars.currentplayer->slayerrocket = rocket;
	g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKET;
	g_Vars.currentplayer->itemswitch &= ~0x0000000f;
	g_Vars.currentplayer->badrockettime = 0;
}

GLOBAL_ASM(
glabel func0f0bd4e4
.late_rodata
glabel var7f1ad678
.word 0x40490fdb
glabel var7f1ad67c
.word 0x40490fdb
.text
/*  f0bd4e4:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bd4e8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bd4ec:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bd4f0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0bd4f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bd4f8:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
/*  f0bd4fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bd500:	00803825 */ 	or	$a3,$a0,$zero
/*  f0bd504:	54610012 */ 	bnel	$v1,$at,.L0f0bd550
/*  f0bd508:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bd50c:	904e1bfd */ 	lbu	$t6,0x1bfd($v0)
/*  f0bd510:	8ccf0038 */ 	lw	$t7,0x38($a2)
/*  f0bd514:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f0bd518:	2c810018 */ 	sltiu	$at,$a0,0x18
/*  f0bd51c:	54200009 */ 	bnezl	$at,.L0f0bd544
/*  f0bd520:	a0441bfd */ 	sb	$a0,0x1bfd($v0)
/*  f0bd524:	a0401bfd */ 	sb	$zero,0x1bfd($v0)
/*  f0bd528:	8cd90284 */ 	lw	$t9,0x284($a2)
/*  f0bd52c:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0bd530:	a3381bfc */ 	sb	$t8,0x1bfc($t9)
/*  f0bd534:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bd538:	10000004 */ 	b	.L0f0bd54c
/*  f0bd53c:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
/*  f0bd540:	a0441bfd */ 	sb	$a0,0x1bfd($v0)
.L0f0bd544:
/*  f0bd544:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bd548:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
.L0f0bd54c:
/*  f0bd54c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0bd550:
/*  f0bd550:	5461003d */ 	bnel	$v1,$at,.L0f0bd648
/*  f0bd554:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0bd558:	90431bfd */ 	lbu	$v1,0x1bfd($v0)
/*  f0bd55c:	8cc80038 */ 	lw	$t0,0x38($a2)
/*  f0bd560:	24010030 */ 	addiu	$at,$zero,0x30
/*  f0bd564:	14610008 */ 	bne	$v1,$at,.L0f0bd588
/*  f0bd568:	00682021 */ 	addu	$a0,$v1,$t0
/*  f0bd56c:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f0bd570:	a0491bfc */ 	sb	$t1,0x1bfc($v0)
/*  f0bd574:	8cca0284 */ 	lw	$t2,0x284($a2)
/*  f0bd578:	a1401bfd */ 	sb	$zero,0x1bfd($t2)
/*  f0bd57c:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bd580:	10000030 */ 	b	.L0f0bd644
/*  f0bd584:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
.L0f0bd588:
/*  f0bd588:	2c810030 */ 	sltiu	$at,$a0,0x30
/*  f0bd58c:	14200005 */ 	bnez	$at,.L0f0bd5a4
/*  f0bd590:	240b0030 */ 	addiu	$t3,$zero,0x30
/*  f0bd594:	a04b1bfd */ 	sb	$t3,0x1bfd($v0)
/*  f0bd598:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bd59c:	10000029 */ 	b	.L0f0bd644
/*  f0bd5a0:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
.L0f0bd5a4:
/*  f0bd5a4:	44842000 */ 	mtc1	$a0,$f4
/*  f0bd5a8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bd5ac:	04810004 */ 	bgez	$a0,.L0f0bd5c0
/*  f0bd5b0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0bd5b4:	44814000 */ 	mtc1	$at,$f8
/*  f0bd5b8:	00000000 */ 	nop
/*  f0bd5bc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0bd5c0:
/*  f0bd5c0:	3c014240 */ 	lui	$at,0x4240
/*  f0bd5c4:	44815000 */ 	mtc1	$at,$f10
/*  f0bd5c8:	3c017f1b */ 	lui	$at,%hi(var7f1ad678)
/*  f0bd5cc:	c432d678 */ 	lwc1	$f18,%lo(var7f1ad678)($at)
/*  f0bd5d0:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f0bd5d4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0bd5d8:	44814000 */ 	mtc1	$at,$f8
/*  f0bd5dc:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0bd5e0:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0bd5e4:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0bd5e8:	00000000 */ 	nop
/*  f0bd5ec:	46082302 */ 	mul.s	$f12,$f4,$f8
/*  f0bd5f0:	0c0068f4 */ 	jal	cosf
/*  f0bd5f4:	00000000 */ 	nop
/*  f0bd5f8:	3c014080 */ 	lui	$at,0x4080
/*  f0bd5fc:	44813000 */ 	mtc1	$at,$f6
/*  f0bd600:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bd604:	44815000 */ 	mtc1	$at,$f10
/*  f0bd608:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bd60c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bd610:	46005401 */ 	sub.s	$f16,$f10,$f0
/*  f0bd614:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0bd618:	8ccc0284 */ 	lw	$t4,0x284($a2)
/*  f0bd61c:	44812000 */ 	mtc1	$at,$f4
/*  f0bd620:	46103482 */ 	mul.s	$f18,$f6,$f16
/*  f0bd624:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0bd628:	a1841bfd */ 	sb	$a0,0x1bfd($t4)
/*  f0bd62c:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f0bd630:	46122200 */ 	add.s	$f8,$f4,$f18
/*  f0bd634:	46085183 */ 	div.s	$f6,$f10,$f8
/*  f0bd638:	e4e60000 */ 	swc1	$f6,0x0($a3)
/*  f0bd63c:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f0bd640:	90431bfc */ 	lbu	$v1,0x1bfc($v0)
.L0f0bd644:
/*  f0bd644:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0bd648:
/*  f0bd648:	14610039 */ 	bne	$v1,$at,.L0f0bd730
/*  f0bd64c:	00000000 */ 	nop
/*  f0bd650:	90431bfd */ 	lbu	$v1,0x1bfd($v0)
/*  f0bd654:	8ccd0038 */ 	lw	$t5,0x38($a2)
/*  f0bd658:	2418002f */ 	addiu	$t8,$zero,0x2f
/*  f0bd65c:	28610007 */ 	slti	$at,$v1,0x7
/*  f0bd660:	10200002 */ 	beqz	$at,.L0f0bd66c
/*  f0bd664:	006d2021 */ 	addu	$a0,$v1,$t5
/*  f0bd668:	24640001 */ 	addiu	$a0,$v1,0x1
.L0f0bd66c:
/*  f0bd66c:	2c810030 */ 	sltiu	$at,$a0,0x30
/*  f0bd670:	14200007 */ 	bnez	$at,.L0f0bd690
/*  f0bd674:	0304c823 */ 	subu	$t9,$t8,$a0
/*  f0bd678:	a0401bfd */ 	sb	$zero,0x1bfd($v0)
/*  f0bd67c:	8cce0284 */ 	lw	$t6,0x284($a2)
/*  f0bd680:	a1c01bfc */ 	sb	$zero,0x1bfc($t6)
/*  f0bd684:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f0bd688:	10000029 */ 	b	.L0f0bd730
/*  f0bd68c:	91e31bfc */ 	lbu	$v1,0x1bfc($t7)
.L0f0bd690:
/*  f0bd690:	44998000 */ 	mtc1	$t9,$f16
/*  f0bd694:	3c014f80 */ 	lui	$at,0x4f80
/*  f0bd698:	07210004 */ 	bgez	$t9,.L0f0bd6ac
/*  f0bd69c:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f0bd6a0:	44819000 */ 	mtc1	$at,$f18
/*  f0bd6a4:	00000000 */ 	nop
/*  f0bd6a8:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f0bd6ac:
/*  f0bd6ac:	3c014240 */ 	lui	$at,0x4240
/*  f0bd6b0:	44815000 */ 	mtc1	$at,$f10
/*  f0bd6b4:	3c017f1b */ 	lui	$at,%hi(var7f1ad67c)
/*  f0bd6b8:	c426d67c */ 	lwc1	$f6,%lo(var7f1ad67c)($at)
/*  f0bd6bc:	460a2203 */ 	div.s	$f8,$f4,$f10
/*  f0bd6c0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0bd6c4:	44819000 */ 	mtc1	$at,$f18
/*  f0bd6c8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0bd6cc:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0bd6d0:	46064402 */ 	mul.s	$f16,$f8,$f6
/*  f0bd6d4:	00000000 */ 	nop
/*  f0bd6d8:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0bd6dc:	0c0068f4 */ 	jal	cosf
/*  f0bd6e0:	00000000 */ 	nop
/*  f0bd6e4:	3c014080 */ 	lui	$at,0x4080
/*  f0bd6e8:	44812000 */ 	mtc1	$at,$f4
/*  f0bd6ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bd6f0:	44815000 */ 	mtc1	$at,$f10
/*  f0bd6f4:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0bd6f8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0bd6fc:	46005201 */ 	sub.s	$f8,$f10,$f0
/*  f0bd700:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0bd704:	8cc80284 */ 	lw	$t0,0x284($a2)
/*  f0bd708:	44818000 */ 	mtc1	$at,$f16
/*  f0bd70c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0bd710:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0bd714:	a1041bfd */ 	sb	$a0,0x1bfd($t0)
/*  f0bd718:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f0bd71c:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f0bd720:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0bd724:	e4e40000 */ 	swc1	$f4,0x0($a3)
/*  f0bd728:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0bd72c:	91231bfc */ 	lbu	$v1,0x1bfc($t1)
.L0f0bd730:
/*  f0bd730:	50600009 */ 	beqzl	$v1,.L0f0bd758
/*  f0bd734:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bd738:	0fc2ea52 */ 	jal	currentPlayerGetTeleportFovY
/*  f0bd73c:	00000000 */ 	nop
/*  f0bd740:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f0bd744:	0fc4a2b5 */ 	jal	currentPlayerSetFovY
/*  f0bd748:	46000306 */ 	mov.s	$f12,$f0
/*  f0bd74c:	0c002f4c */ 	jal	viSetFovY
/*  f0bd750:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0bd754:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0bd758:
/*  f0bd758:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0bd75c:	03e00008 */ 	jr	$ra
/*  f0bd760:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0bd764
/*  f0bd764:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0bd768:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0bd76c:	0fc2f4d6 */ 	jal	func0f0bd358
/*  f0bd770:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0bd774:	3c018007 */ 	lui	$at,%hi(g_HiResActive)
/*  f0bd778:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0bd77c:	ac2006c8 */ 	sw	$zero,%lo(g_HiResActive)($at)
/*  f0bd780:	0fc54c77 */ 	jal	func0f1531dc
/*  f0bd784:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bd788:	3c014270 */ 	lui	$at,0x4270
/*  f0bd78c:	44816000 */ 	mtc1	$at,$f12
/*  f0bd790:	0fc4a2b5 */ 	jal	currentPlayerSetFovY
/*  f0bd794:	00000000 */ 	nop
/*  f0bd798:	0fc4a2b9 */ 	jal	currentPlayerSetAspectRatio
/*  f0bd79c:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0bd7a0:	0fc2f155 */ 	jal	func0f0bc554
/*  f0bd7a4:	00000000 */ 	nop
/*  f0bd7a8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bd7ac:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0bd7b0:	0fc2f2a8 */ 	jal	func0f0bcaa0
/*  f0bd7b4:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0bd7b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bd7bc:	0fc4a2a7 */ 	jal	currentPlayerSetViewSize
/*  f0bd7c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0bd7c4:	0fc2f1eb */ 	jal	func0f0bc7ac
/*  f0bd7c8:	00000000 */ 	nop
/*  f0bd7cc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bd7d0:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0bd7d4:	0fc2f389 */ 	jal	func0f0bce24
/*  f0bd7d8:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0bd7dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bd7e0:	0fc4a2ae */ 	jal	currentPlayerSetViewPosition
/*  f0bd7e4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0bd7e8:	3c188007 */ 	lui	$t8,%hi(g_HiResActive)
/*  f0bd7ec:	8f1806c8 */ 	lw	$t8,%lo(g_HiResActive)($t8)
/*  f0bd7f0:	3c048007 */ 	lui	$a0,%hi(var800705c0+0x10)
/*  f0bd7f4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0bd7f8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0bd7fc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bd800:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0bd804:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bd808:	00992021 */ 	addu	$a0,$a0,$t9
/*  f0bd80c:	0c002aac */ 	jal	func0000aab0
/*  f0bd810:	8c8405d0 */ 	lw	$a0,%lo(var800705c0+0x10)($a0)
/*  f0bd814:	0fc2f155 */ 	jal	func0f0bc554
/*  f0bd818:	00000000 */ 	nop
/*  f0bd81c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bd820:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0bd824:	0fc2f2a8 */ 	jal	func0f0bcaa0
/*  f0bd828:	01008025 */ 	or	$s0,$t0,$zero
/*  f0bd82c:	3c014270 */ 	lui	$at,0x4270
/*  f0bd830:	00103400 */ 	sll	$a2,$s0,0x10
/*  f0bd834:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0bd838:	00075403 */ 	sra	$t2,$a3,0x10
/*  f0bd83c:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f0bd840:	44816000 */ 	mtc1	$at,$f12
/*  f0bd844:	01203025 */ 	or	$a2,$t1,$zero
/*  f0bd848:	01403825 */ 	or	$a3,$t2,$zero
/*  f0bd84c:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f0bd850:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*  f0bd854:	0fc2f1eb */ 	jal	func0f0bc7ac
/*  f0bd858:	00000000 */ 	nop
/*  f0bd85c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bd860:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0bd864:	0fc2f389 */ 	jal	func0f0bce24
/*  f0bd868:	01608025 */ 	or	$s0,$t3,$zero
/*  f0bd86c:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bd870:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bd874:	00056c03 */ 	sra	$t5,$a1,0x10
/*  f0bd878:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0bd87c:	01802025 */ 	or	$a0,$t4,$zero
/*  f0bd880:	0c002f2a */ 	jal	viSetViewPosition
/*  f0bd884:	01a02825 */ 	or	$a1,$t5,$zero
/*  f0bd888:	0fc2f113 */ 	jal	func0f0bc44c
/*  f0bd88c:	00000000 */ 	nop
/*  f0bd890:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bd894:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0bd898:	0fc2f11e */ 	jal	func0f0bc478
/*  f0bd89c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0bd8a0:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bd8a4:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bd8a8:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0bd8ac:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f0bd8b0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0bd8b4:	0c002ef9 */ 	jal	viSetXY
/*  f0bd8b8:	03002825 */ 	or	$a1,$t8,$zero
/*  f0bd8bc:	0fc2f113 */ 	jal	func0f0bc44c
/*  f0bd8c0:	00000000 */ 	nop
/*  f0bd8c4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bd8c8:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0bd8cc:	0fc2f11e */ 	jal	func0f0bc478
/*  f0bd8d0:	03208025 */ 	or	$s0,$t9,$zero
/*  f0bd8d4:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bd8d8:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bd8dc:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f0bd8e0:	00044403 */ 	sra	$t0,$a0,0x10
/*  f0bd8e4:	01002025 */ 	or	$a0,$t0,$zero
/*  f0bd8e8:	0c002ee8 */ 	jal	viSetBuf
/*  f0bd8ec:	01202825 */ 	or	$a1,$t1,$zero
/*  f0bd8f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0bd8f4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0bd8f8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0bd8fc:	03e00008 */ 	jr	$ra
/*  f0bd900:	00000000 */ 	nop
);

const char var7f1ad524[] = "tps";

u32 var800709d0 = 0x00000000;
u32 var800709d4 = 0x00000000;
u32 var800709d8 = 0x00000000;
u32 var800709dc = 0x00000000;
u32 var800709e0 = 0x00000000;
u32 var800709e4 = 0x3f800000;
u32 var800709e8 = 0x00000000;
u32 var800709ec = 0x3f800000;
u32 var800709f0 = 0x00000000;

GLOBAL_ASM(
glabel func0f0bd904
.late_rodata
glabel var7f1ad680
.word 0x3faaaaab
glabel var7f1ad684
.word 0x3983126f
glabel var7f1ad688
.word 0x3d4ccccd
glabel var7f1ad68c
.word 0x3d4ccccd
glabel var7f1ad690
.word 0x3c8ef461
glabel var7f1ad694
.word 0x40c907a9
glabel var7f1ad698
.word 0x40490fdb
glabel var7f1ad69c
.word 0xc0490fdb
glabel var7f1ad6a0
.word 0xbdb851ec
glabel var7f1ad6a4
.word 0x3db851ec
glabel var7f1ad6a8
.word 0xbe4ccccd
glabel var7f1ad6ac
.word 0x3e4ccccd
.text
/*  f0bd904:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f0bd908:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0bd90c:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f0bd910:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f0bd914:	8e6f0298 */ 	lw	$t7,0x298($s3)
/*  f0bd918:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0bd91c:	3c0e8007 */ 	lui	$t6,%hi(g_HiResEnabled)
/*  f0bd920:	8dce06cc */ 	lw	$t6,%lo(g_HiResEnabled)($t6)
/*  f0bd924:	3c118007 */ 	lui	$s1,%hi(g_HiResActive)
/*  f0bd928:	263106c8 */ 	addiu	$s1,$s1,%lo(g_HiResActive)
/*  f0bd92c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0bd930:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0bd934:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0bd938:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0bd93c:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0bd940:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0bd944:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0bd948:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f0bd94c:	05e10004 */ 	bgez	$t7,.L0f0bd960
/*  f0bd950:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0bd954:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f0bd958:	07020020 */ 	bltzl	$t8,.L0f0bd9dc
/*  f0bd95c:	8e2f0000 */ 	lw	$t7,0x0($s1)
.L0f0bd960:
/*  f0bd960:	8e79006c */ 	lw	$t9,0x6c($s3)
/*  f0bd964:	00003825 */ 	or	$a3,$zero,$zero
/*  f0bd968:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bd96c:	13200003 */ 	beqz	$t9,.L0f0bd97c
/*  f0bd970:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bd974:	10000001 */ 	b	.L0f0bd97c
/*  f0bd978:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0bd97c:
/*  f0bd97c:	8e690068 */ 	lw	$t1,0x68($s3)
/*  f0bd980:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bd984:	11200003 */ 	beqz	$t1,.L0f0bd994
/*  f0bd988:	00000000 */ 	nop
/*  f0bd98c:	10000001 */ 	b	.L0f0bd994
/*  f0bd990:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bd994:
/*  f0bd994:	8e6a0064 */ 	lw	$t2,0x64($s3)
/*  f0bd998:	11400003 */ 	beqz	$t2,.L0f0bd9a8
/*  f0bd99c:	00000000 */ 	nop
/*  f0bd9a0:	10000001 */ 	b	.L0f0bd9a8
/*  f0bd9a4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0bd9a8:
/*  f0bd9a8:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f0bd9ac:	11600003 */ 	beqz	$t3,.L0f0bd9bc
/*  f0bd9b0:	00000000 */ 	nop
/*  f0bd9b4:	10000001 */ 	b	.L0f0bd9bc
/*  f0bd9b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0bd9bc:
/*  f0bd9bc:	00446021 */ 	addu	$t4,$v0,$a0
/*  f0bd9c0:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0bd9c4:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f0bd9c8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0bd9cc:	54200003 */ 	bnezl	$at,.L0f0bd9dc
/*  f0bd9d0:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bd9d4:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0bd9d8:	8e2f0000 */ 	lw	$t7,0x0($s1)
.L0f0bd9dc:
/*  f0bd9dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bd9e0:	15e10005 */ 	bne	$t7,$at,.L0f0bd9f8
/*  f0bd9e4:	00000000 */ 	nop
/*  f0bd9e8:	0fc54c77 */ 	jal	func0f1531dc
/*  f0bd9ec:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0bd9f0:	10000003 */ 	b	.L0f0bda00
/*  f0bd9f4:	00000000 */ 	nop
.L0f0bd9f8:
/*  f0bd9f8:	0fc54c77 */ 	jal	func0f1531dc
/*  f0bd9fc:	00002025 */ 	or	$a0,$zero,$zero
.L0f0bda00:
/*  f0bda00:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f0bda04:	00000000 */ 	nop
/*  f0bda08:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bda0c:	14410008 */ 	bne	$v0,$at,.L0f0bda30
/*  f0bda10:	00000000 */ 	nop
/*  f0bda14:	0fc2f4d6 */ 	jal	func0f0bd358
/*  f0bda18:	00000000 */ 	nop
/*  f0bda1c:	3c017f1b */ 	lui	$at,%hi(var7f1ad680)
/*  f0bda20:	c424d680 */ 	lwc1	$f4,%lo(var7f1ad680)($at)
/*  f0bda24:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0bda28:	10000004 */ 	b	.L0f0bda3c
/*  f0bda2c:	e7a6032c */ 	swc1	$f6,0x32c($sp)
.L0f0bda30:
/*  f0bda30:	0fc2f4d6 */ 	jal	func0f0bd358
/*  f0bda34:	00000000 */ 	nop
/*  f0bda38:	e7a0032c */ 	swc1	$f0,0x32c($sp)
.L0f0bda3c:
/*  f0bda3c:	3c108007 */ 	lui	$s0,%hi(var8007083c)
/*  f0bda40:	2610083c */ 	addiu	$s0,$s0,%lo(var8007083c)
/*  f0bda44:	3c047f1b */ 	lui	$a0,%hi(var7f1ad524)
/*  f0bda48:	2484d524 */ 	addiu	$a0,$a0,%lo(var7f1ad524)
/*  f0bda4c:	0c0036cc */ 	jal	func0000db30
/*  f0bda50:	02002825 */ 	or	$a1,$s0,$zero
/*  f0bda54:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0bda58:	53000008 */ 	beqzl	$t8,.L0f0bda7c
/*  f0bda5c:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0bda60:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0bda64:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f0bda68:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0bda6c:	a3201bfd */ 	sb	$zero,0x1bfd($t9)
/*  f0bda70:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0bda74:	a1351bfc */ 	sb	$s5,0x1bfc($t1)
/*  f0bda78:	8e6a0284 */ 	lw	$t2,0x284($s3)
.L0f0bda7c:
/*  f0bda7c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0bda80:	914b1bfc */ 	lbu	$t3,0x1bfc($t2)
/*  f0bda84:	51600004 */ 	beqzl	$t3,.L0f0bda98
/*  f0bda88:	8e6c04b4 */ 	lw	$t4,0x4b4($s3)
/*  f0bda8c:	0fc2f539 */ 	jal	func0f0bd4e4
/*  f0bda90:	27a4032c */ 	addiu	$a0,$sp,0x32c
/*  f0bda94:	8e6c04b4 */ 	lw	$t4,0x4b4($s3)
.L0f0bda98:
/*  f0bda98:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f0bda9c:	5581000a */ 	bnel	$t4,$at,.L0f0bdac8
/*  f0bdaa0:	3c014270 */ 	lui	$at,0x4270
/*  f0bdaa4:	0fc06b57 */ 	jal	func0f01ad5c
/*  f0bdaa8:	00000000 */ 	nop
/*  f0bdaac:	50400006 */ 	beqzl	$v0,.L0f0bdac8
/*  f0bdab0:	3c014270 */ 	lui	$at,0x4270
/*  f0bdab4:	0fc06b6e */ 	jal	func0f01adb8
/*  f0bdab8:	00000000 */ 	nop
/*  f0bdabc:	10000834 */ 	b	.L0f0bfb90
/*  f0bdac0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0bdac4:	3c014270 */ 	lui	$at,0x4270
.L0f0bdac8:
/*  f0bdac8:	44816000 */ 	mtc1	$at,$f12
/*  f0bdacc:	0fc4a2b5 */ 	jal	currentPlayerSetFovY
/*  f0bdad0:	00000000 */ 	nop
/*  f0bdad4:	0fc4a2b9 */ 	jal	currentPlayerSetAspectRatio
/*  f0bdad8:	c7ac032c */ 	lwc1	$f12,0x32c($sp)
/*  f0bdadc:	0fc2f155 */ 	jal	func0f0bc554
/*  f0bdae0:	00000000 */ 	nop
/*  f0bdae4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdae8:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0bdaec:	0fc2f2a8 */ 	jal	func0f0bcaa0
/*  f0bdaf0:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0bdaf4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bdaf8:	0fc4a2a7 */ 	jal	currentPlayerSetViewSize
/*  f0bdafc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0bdb00:	0fc2f1eb */ 	jal	func0f0bc7ac
/*  f0bdb04:	00000000 */ 	nop
/*  f0bdb08:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdb0c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0bdb10:	0fc2f389 */ 	jal	func0f0bce24
/*  f0bdb14:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0bdb18:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bdb1c:	0fc4a2ae */ 	jal	currentPlayerSetViewPosition
/*  f0bdb20:	00402825 */ 	or	$a1,$v0,$zero
/*  f0bdb24:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bdb28:	3c048007 */ 	lui	$a0,%hi(var800705c0+0x10)
/*  f0bdb2c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bdb30:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bdb34:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bdb38:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bdb3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bdb40:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0bdb44:	0c002aac */ 	jal	func0000aab0
/*  f0bdb48:	8c8405d0 */ 	lw	$a0,%lo(var800705c0+0x10)($a0)
/*  f0bdb4c:	0fc2f155 */ 	jal	func0f0bc554
/*  f0bdb50:	00000000 */ 	nop
/*  f0bdb54:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdb58:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0bdb5c:	0fc2f2a8 */ 	jal	func0f0bcaa0
/*  f0bdb60:	03208025 */ 	or	$s0,$t9,$zero
/*  f0bdb64:	3c014270 */ 	lui	$at,0x4270
/*  f0bdb68:	00103400 */ 	sll	$a2,$s0,0x10
/*  f0bdb6c:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0bdb70:	00075403 */ 	sra	$t2,$a3,0x10
/*  f0bdb74:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f0bdb78:	44816000 */ 	mtc1	$at,$f12
/*  f0bdb7c:	01203025 */ 	or	$a2,$t1,$zero
/*  f0bdb80:	01403825 */ 	or	$a3,$t2,$zero
/*  f0bdb84:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f0bdb88:	c7ae032c */ 	lwc1	$f14,0x32c($sp)
/*  f0bdb8c:	0fc2f1eb */ 	jal	func0f0bc7ac
/*  f0bdb90:	00000000 */ 	nop
/*  f0bdb94:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdb98:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0bdb9c:	0fc2f389 */ 	jal	func0f0bce24
/*  f0bdba0:	01608025 */ 	or	$s0,$t3,$zero
/*  f0bdba4:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bdba8:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bdbac:	00056c03 */ 	sra	$t5,$a1,0x10
/*  f0bdbb0:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0bdbb4:	01802025 */ 	or	$a0,$t4,$zero
/*  f0bdbb8:	0c002f2a */ 	jal	viSetViewPosition
/*  f0bdbbc:	01a02825 */ 	or	$a1,$t5,$zero
/*  f0bdbc0:	0fc2f113 */ 	jal	func0f0bc44c
/*  f0bdbc4:	00000000 */ 	nop
/*  f0bdbc8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdbcc:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0bdbd0:	0fc2f11e */ 	jal	func0f0bc478
/*  f0bdbd4:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0bdbd8:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bdbdc:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bdbe0:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0bdbe4:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f0bdbe8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0bdbec:	0c002ef9 */ 	jal	viSetXY
/*  f0bdbf0:	03002825 */ 	or	$a1,$t8,$zero
/*  f0bdbf4:	0fc2f113 */ 	jal	func0f0bc44c
/*  f0bdbf8:	00000000 */ 	nop
/*  f0bdbfc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdc00:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0bdc04:	0fc2f11e */ 	jal	func0f0bc478
/*  f0bdc08:	03208025 */ 	or	$s0,$t9,$zero
/*  f0bdc0c:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bdc10:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bdc14:	00055403 */ 	sra	$t2,$a1,0x10
/*  f0bdc18:	00044c03 */ 	sra	$t1,$a0,0x10
/*  f0bdc1c:	01202025 */ 	or	$a0,$t1,$zero
/*  f0bdc20:	0c002ee8 */ 	jal	viSetBuf
/*  f0bdc24:	01402825 */ 	or	$a1,$t2,$zero
/*  f0bdc28:	0fc2ed0b */ 	jal	func0f0bb42c
/*  f0bdc2c:	00000000 */ 	nop
/*  f0bdc30:	0fc2ed7b */ 	jal	currentPlayerTickChrFade
/*  f0bdc34:	00000000 */ 	nop
/*  f0bdc38:	8e6b0288 */ 	lw	$t3,0x288($s3)
/*  f0bdc3c:	0fc549e9 */ 	jal	optionsGetAutoAim
/*  f0bdc40:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0bdc44:	0fc31e88 */ 	jal	currentPlayerSetAutoAimY
/*  f0bdc48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bdc4c:	8e6c0288 */ 	lw	$t4,0x288($s3)
/*  f0bdc50:	0fc549e9 */ 	jal	optionsGetAutoAim
/*  f0bdc54:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0bdc58:	0fc31ed9 */ 	jal	currentPlayerSetAutoAimX
/*  f0bdc5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bdc60:	8e6d0288 */ 	lw	$t5,0x288($s3)
/*  f0bdc64:	0fc549f2 */ 	jal	optionsGetLookAhead
/*  f0bdc68:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0bdc6c:	0fc31e80 */ 	jal	currentPlayerSetAutoMoveCentreEnabled
/*  f0bdc70:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bdc74:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f0bdc78:	0fc54a0d */ 	jal	optionsGetAmmoOnScreen
/*  f0bdc7c:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0bdc80:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0bdc84:	0fc2a57b */ 	jal	func0f0a95ec
/*  f0bdc88:	00402825 */ 	or	$a1,$v0,$zero
/*  f0bdc8c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0bdc90:	0fc2af1d */ 	jal	currentPlayerSetGunSightVisible
/*  f0bdc94:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0bdc98:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0bdc9c:	10600002 */ 	beqz	$v1,.L0f0bdca8
/*  f0bdca0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0bdca4:	1461000d */ 	bne	$v1,$at,.L0f0bdcdc
.L0f0bdca8:
/*  f0bdca8:	3c0f8007 */ 	lui	$t7,%hi(var80070764)
/*  f0bdcac:	8def0764 */ 	lw	$t7,%lo(var80070764)($t7)
/*  f0bdcb0:	3c188006 */ 	lui	$t8,%hi(var8005d9d0)
/*  f0bdcb4:	55e0000a */ 	bnezl	$t7,.L0f0bdce0
/*  f0bdcb8:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0bdcbc:	8f18d9d0 */ 	lw	$t8,%lo(var8005d9d0)($t8)
/*  f0bdcc0:	57000007 */ 	bnezl	$t8,.L0f0bdce0
/*  f0bdcc4:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0bdcc8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdccc:	8e690038 */ 	lw	$t1,0x38($s3)
/*  f0bdcd0:	8e191b7c */ 	lw	$t9,0x1b7c($s0)
/*  f0bdcd4:	03295021 */ 	addu	$t2,$t9,$t1
/*  f0bdcd8:	ae0a1b7c */ 	sw	$t2,0x1b7c($s0)
.L0f0bdcdc:
/*  f0bdcdc:	8e6b0284 */ 	lw	$t3,0x284($s3)
.L0f0bdce0:
/*  f0bdce0:	8d6c00c4 */ 	lw	$t4,0xc4($t3)
/*  f0bdce4:	318d0020 */ 	andi	$t5,$t4,0x20
/*  f0bdce8:	11a00004 */ 	beqz	$t5,.L0f0bdcfc
/*  f0bdcec:	00000000 */ 	nop
/*  f0bdcf0:	8e64028c */ 	lw	$a0,0x28c($s3)
/*  f0bdcf4:	0fc30501 */ 	jal	currentPlayerDieByShooter
/*  f0bdcf8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0bdcfc:
/*  f0bdcfc:	0fc2ee05 */ 	jal	func0f0bb814
/*  f0bdd00:	00000000 */ 	nop
/*  f0bdd04:	0fc2f048 */ 	jal	func0f0bc120
/*  f0bdd08:	00000000 */ 	nop
/*  f0bdd0c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdd10:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f0bdd14:	1040008c */ 	beqz	$v0,.L0f0bdf48
/*  f0bdd18:	00000000 */ 	nop
/*  f0bdd1c:	8e6e02ac */ 	lw	$t6,0x2ac($s3)
/*  f0bdd20:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0bdd24:	00409025 */ 	or	$s2,$v0,$zero
/*  f0bdd28:	15c10014 */ 	bne	$t6,$at,.L0f0bdd7c
/*  f0bdd2c:	8e71028c */ 	lw	$s1,0x28c($s3)
/*  f0bdd30:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0bdd34:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0bdd38:	3406ffff */ 	dli	$a2,0xffff
/*  f0bdd3c:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f0bdd40:	a2400035 */ 	sb	$zero,0x35($s2)
/*  f0bdd44:	a2550034 */ 	sb	$s5,0x34($s2)
/*  f0bdd48:	0fc249af */ 	jal	func0f0926bc
/*  f0bdd4c:	a2400037 */ 	sb	$zero,0x37($s2)
/*  f0bdd50:	8e2f0018 */ 	lw	$t7,0x18($s1)
/*  f0bdd54:	2401fffb */ 	addiu	$at,$zero,-5
/*  f0bdd58:	35f80400 */ 	ori	$t8,$t7,0x400
/*  f0bdd5c:	ae380018 */ 	sw	$t8,0x18($s1)
/*  f0bdd60:	37090010 */ 	ori	$t1,$t8,0x10
/*  f0bdd64:	ae290018 */ 	sw	$t1,0x18($s1)
/*  f0bdd68:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdd6c:	8e0a00c4 */ 	lw	$t2,0xc4($s0)
/*  f0bdd70:	01415824 */ 	and	$t3,$t2,$at
/*  f0bdd74:	10000074 */ 	b	.L0f0bdf48
/*  f0bdd78:	ae0b00c4 */ 	sw	$t3,0xc4($s0)
.L0f0bdd7c:
/*  f0bdd7c:	924c0034 */ 	lbu	$t4,0x34($s2)
/*  f0bdd80:	5580002c */ 	bnezl	$t4,.L0f0bde34
/*  f0bdd84:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
/*  f0bdd88:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0bdd8c:	51a00022 */ 	beqzl	$t5,.L0f0bde18
/*  f0bdd90:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bdd94:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f0bdd98:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0bdd9c:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0bdda0:	8fb80330 */ 	lw	$t8,0x330($sp)
/*  f0bdda4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0bdda8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0bddac:	13000005 */ 	beqz	$t8,.L0f0bddc4
/*  f0bddb0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0bddb4:	0c0053d8 */ 	jal	contGetButtons
/*  f0bddb8:	3405ffff */ 	dli	$a1,0xffff
/*  f0bddbc:	10000002 */ 	b	.L0f0bddc8
/*  f0bddc0:	3043ffff */ 	andi	$v1,$v0,0xffff
.L0f0bddc4:
/*  f0bddc4:	00001825 */ 	or	$v1,$zero,$zero
.L0f0bddc8:
/*  f0bddc8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bddcc:	8e1900d8 */ 	lw	$t9,0xd8($s0)
/*  f0bddd0:	57200011 */ 	bnezl	$t9,.L0f0bde18
/*  f0bddd4:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bddd8:	8e091a24 */ 	lw	$t1,0x1a24($s0)
/*  f0bdddc:	306a1000 */ 	andi	$t2,$v1,0x1000
/*  f0bdde0:	5520000d */ 	bnezl	$t1,.L0f0bde18
/*  f0bdde4:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bdde8:	5140000b */ 	beqzl	$t2,.L0f0bde18
/*  f0bddec:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bddf0:	8e6b0314 */ 	lw	$t3,0x314($s3)
/*  f0bddf4:	15600005 */ 	bnez	$t3,.L0f0bde0c
/*  f0bddf8:	00000000 */ 	nop
/*  f0bddfc:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f0bde00:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0bde04:	10000004 */ 	b	.L0f0bde18
/*  f0bde08:	8e6c0034 */ 	lw	$t4,0x34($s3)
.L0f0bde0c:
/*  f0bde0c:	0fc5e36f */ 	jal	mpPushPauseDialog
/*  f0bde10:	00000000 */ 	nop
/*  f0bde14:	8e6c0034 */ 	lw	$t4,0x34($s3)
.L0f0bde18:
/*  f0bde18:	5180001d */ 	beqzl	$t4,.L0f0bde90
/*  f0bde1c:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0bde20:	0fc3424a */ 	jal	func0f0d0928
/*  f0bde24:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f0bde28:	10000019 */ 	b	.L0f0bde90
/*  f0bde2c:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0bde30:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
.L0f0bde34:
/*  f0bde34:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f0bde38:	00114880 */ 	sll	$t1,$s1,0x2
/*  f0bde3c:	01c07827 */ 	nor	$t7,$t6,$zero
/*  f0bde40:	01afc024 */ 	and	$t8,$t5,$t7
/*  f0bde44:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0bde48:	13200010 */ 	beqz	$t9,.L0f0bde8c
/*  f0bde4c:	3c0a8007 */ 	lui	$t2,%hi(g_PlayersWithControl)
/*  f0bde50:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0bde54:	8d4a0750 */ 	lw	$t2,%lo(g_PlayersWithControl)($t2)
/*  f0bde58:	5140000d */ 	beqzl	$t2,.L0f0bde90
/*  f0bde5c:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0bde60:	0fc340c4 */ 	jal	func0f0d0310
/*  f0bde64:	00000000 */ 	nop
/*  f0bde68:	54400009 */ 	bnezl	$v0,.L0f0bde90
/*  f0bde6c:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0bde70:	a2550034 */ 	sb	$s5,0x34($s2)
/*  f0bde74:	a2400037 */ 	sb	$zero,0x37($s2)
/*  f0bde78:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bde7c:	2401fffb */ 	addiu	$at,$zero,-5
/*  f0bde80:	8e0b00c4 */ 	lw	$t3,0xc4($s0)
/*  f0bde84:	01616024 */ 	and	$t4,$t3,$at
/*  f0bde88:	ae0c00c4 */ 	sw	$t4,0xc4($s0)
.L0f0bde8c:
/*  f0bde8c:	924e0035 */ 	lbu	$t6,0x35($s2)
.L0f0bde90:
/*  f0bde90:	00116880 */ 	sll	$t5,$s1,0x2
/*  f0bde94:	3c0f8007 */ 	lui	$t7,%hi(g_PlayersWithControl)
/*  f0bde98:	11c0002b */ 	beqz	$t6,.L0f0bdf48
/*  f0bde9c:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f0bdea0:	8def0750 */ 	lw	$t7,%lo(g_PlayersWithControl)($t7)
/*  f0bdea4:	11e00028 */ 	beqz	$t7,.L0f0bdf48
/*  f0bdea8:	00000000 */ 	nop
/*  f0bdeac:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdeb0:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f0bdeb4:	8e1800c4 */ 	lw	$t8,0xc4($s0)
/*  f0bdeb8:	03204827 */ 	nor	$t1,$t9,$zero
/*  f0bdebc:	03095024 */ 	and	$t2,$t8,$t1
/*  f0bdec0:	314b0004 */ 	andi	$t3,$t2,0x4
/*  f0bdec4:	11600020 */ 	beqz	$t3,.L0f0bdf48
/*  f0bdec8:	00000000 */ 	nop
/*  f0bdecc:	824c0037 */ 	lb	$t4,0x37($s2)
/*  f0bded0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0bded4:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0bded8:	15800019 */ 	bnez	$t4,.L0f0bdf40
/*  f0bdedc:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0bdee0:	a2400039 */ 	sb	$zero,0x39($s2)
/*  f0bdee4:	824d0039 */ 	lb	$t5,0x39($s2)
/*  f0bdee8:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0bdeec:	a24e0037 */ 	sb	$t6,0x37($s2)
/*  f0bdef0:	a2400068 */ 	sb	$zero,0x68($s2)
/*  f0bdef4:	a2400036 */ 	sb	$zero,0x36($s2)
/*  f0bdef8:	a24d0038 */ 	sb	$t5,0x38($s2)
/*  f0bdefc:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f0bdf00:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bdf04:	44814000 */ 	mtc1	$at,$f8
/*  f0bdf08:	af0f0120 */ 	sw	$t7,0x120($t8)
/*  f0bdf0c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0bdf10:	240affff */ 	addiu	$t2,$zero,-1
/*  f0bdf14:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0bdf18:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0bdf1c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0bdf20:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0bdf24:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0bdf28:	240580ab */ 	addiu	$a1,$zero,-32597
/*  f0bdf2c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bdf30:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0bdf34:	0c004241 */ 	jal	audioStart
/*  f0bdf38:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0bdf3c:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bdf40:
/*  f0bdf40:	2411ffd8 */ 	addiu	$s1,$zero,-40
/*  f0bdf44:	a611024c */ 	sh	$s1,0x24c($s0)
.L0f0bdf48:
/*  f0bdf48:	0fc5b364 */ 	jal	soloIsPaused
/*  f0bdf4c:	2411ffd8 */ 	addiu	$s1,$zero,-40
/*  f0bdf50:	50400004 */ 	beqzl	$v0,.L0f0bdf64
/*  f0bdf54:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdf58:	0fc2eb38 */ 	jal	func0f0bace0
/*  f0bdf5c:	00000000 */ 	nop
/*  f0bdf60:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bdf64:
/*  f0bdf64:	8e0c1a24 */ 	lw	$t4,0x1a24($s0)
/*  f0bdf68:	51800005 */ 	beqzl	$t4,.L0f0bdf80
/*  f0bdf6c:	960e0010 */ 	lhu	$t6,0x10($s0)
/*  f0bdf70:	0fc2eb5b */ 	jal	func0f0bad6c
/*  f0bdf74:	00000000 */ 	nop
/*  f0bdf78:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdf7c:	960e0010 */ 	lhu	$t6,0x10($s0)
.L0f0bdf80:
/*  f0bdf80:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bdf84:	55c1000c */ 	bnel	$t6,$at,.L0f0bdfb8
/*  f0bdf88:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0bdf8c:	8e0d0264 */ 	lw	$t5,0x264($s0)
/*  f0bdf90:	51a00005 */ 	beqzl	$t5,.L0f0bdfa8
/*  f0bdf94:	ae000264 */ 	sw	$zero,0x264($s0)
/*  f0bdf98:	8e1900d8 */ 	lw	$t9,0xd8($s0)
/*  f0bdf9c:	53200006 */ 	beqzl	$t9,.L0f0bdfb8
/*  f0bdfa0:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0bdfa4:	ae000264 */ 	sw	$zero,0x264($s0)
.L0f0bdfa8:
/*  f0bdfa8:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f0bdfac:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f0bdfb0:	a70f0010 */ 	sh	$t7,0x10($t8)
/*  f0bdfb4:	8e6302ac */ 	lw	$v1,0x2ac($s3)
.L0f0bdfb8:
/*  f0bdfb8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0bdfbc:	10610002 */ 	beq	$v1,$at,.L0f0bdfc8
/*  f0bdfc0:	3c018007 */ 	lui	$at,%hi(var80070764)
/*  f0bdfc4:	ac200764 */ 	sw	$zero,%lo(var80070764)($at)
.L0f0bdfc8:
/*  f0bdfc8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0bdfcc:	54610054 */ 	bnel	$v1,$at,.L0f0be120
/*  f0bdfd0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdfd4:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0bdfd8:	00000000 */ 	nop
/*  f0bdfdc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bdfe0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bdfe4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bdfe8:	8e0919c8 */ 	lw	$t1,0x19c8($s0)
/*  f0bdfec:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bdff0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0bdff4:	51200008 */ 	beqzl	$t1,.L0f0be018
/*  f0bdff8:	8e6b006c */ 	lw	$t3,0x6c($s3)
/*  f0bdffc:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0be000:	a611024c */ 	sh	$s1,0x24c($s0)
/*  f0be004:	0fc2e8a7 */ 	jal	func0f0ba29c
/*  f0be008:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f0be00c:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0be010:	a551024c */ 	sh	$s1,0x24c($t2)
/*  f0be014:	8e6b006c */ 	lw	$t3,0x6c($s3)
.L0f0be018:
/*  f0be018:	00003025 */ 	or	$a2,$zero,$zero
/*  f0be01c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0be020:	11600003 */ 	beqz	$t3,.L0f0be030
/*  f0be024:	00002825 */ 	or	$a1,$zero,$zero
/*  f0be028:	10000001 */ 	b	.L0f0be030
/*  f0be02c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0be030:
/*  f0be030:	8e6c0068 */ 	lw	$t4,0x68($s3)
/*  f0be034:	00002025 */ 	or	$a0,$zero,$zero
/*  f0be038:	00001025 */ 	or	$v0,$zero,$zero
/*  f0be03c:	11800003 */ 	beqz	$t4,.L0f0be04c
/*  f0be040:	00064880 */ 	sll	$t1,$a2,0x2
/*  f0be044:	10000001 */ 	b	.L0f0be04c
/*  f0be048:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0be04c:
/*  f0be04c:	8e6e0064 */ 	lw	$t6,0x64($s3)
/*  f0be050:	02691821 */ 	addu	$v1,$s3,$t1
/*  f0be054:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0be058:	11c00003 */ 	beqz	$t6,.L0f0be068
/*  f0be05c:	00000000 */ 	nop
/*  f0be060:	10000001 */ 	b	.L0f0be068
/*  f0be064:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0be068:
/*  f0be068:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f0be06c:	11a00003 */ 	beqz	$t5,.L0f0be07c
/*  f0be070:	00000000 */ 	nop
/*  f0be074:	10000001 */ 	b	.L0f0be07c
/*  f0be078:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0be07c:
/*  f0be07c:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0be080:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0be084:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0be088:	1b000022 */ 	blez	$t8,.L0f0be114
/*  f0be08c:	00000000 */ 	nop
/*  f0be090:	8c6a0064 */ 	lw	$t2,0x64($v1)
.L0f0be094:
/*  f0be094:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0be098:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0be09c:	ad481c40 */ 	sw	$t0,0x1c40($t2)
/*  f0be0a0:	8e6b006c */ 	lw	$t3,0x6c($s3)
/*  f0be0a4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0be0a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0be0ac:	11600003 */ 	beqz	$t3,.L0f0be0bc
/*  f0be0b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0be0b4:	10000001 */ 	b	.L0f0be0bc
/*  f0be0b8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0be0bc:
/*  f0be0bc:	8e6c0068 */ 	lw	$t4,0x68($s3)
/*  f0be0c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0be0c4:	11800003 */ 	beqz	$t4,.L0f0be0d4
/*  f0be0c8:	00000000 */ 	nop
/*  f0be0cc:	10000001 */ 	b	.L0f0be0d4
/*  f0be0d0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0be0d4:
/*  f0be0d4:	8e6e0064 */ 	lw	$t6,0x64($s3)
/*  f0be0d8:	11c00003 */ 	beqz	$t6,.L0f0be0e8
/*  f0be0dc:	00000000 */ 	nop
/*  f0be0e0:	10000001 */ 	b	.L0f0be0e8
/*  f0be0e4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0be0e8:
/*  f0be0e8:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f0be0ec:	11a00003 */ 	beqz	$t5,.L0f0be0fc
/*  f0be0f0:	00000000 */ 	nop
/*  f0be0f4:	10000001 */ 	b	.L0f0be0fc
/*  f0be0f8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0be0fc:
/*  f0be0fc:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0be100:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0be104:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0be108:	00d8082a */ 	slt	$at,$a2,$t8
/*  f0be10c:	5420ffe1 */ 	bnezl	$at,.L0f0be094
/*  f0be110:	8c6a0064 */ 	lw	$t2,0x64($v1)
.L0f0be114:
/*  f0be114:	10000607 */ 	b	.L0f0bf934
/*  f0be118:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be11c:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0be120:
/*  f0be120:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f0be124:	5040002f */ 	beqzl	$v0,.L0f0be1e4
/*  f0be128:	920e1bfc */ 	lbu	$t6,0x1bfc($s0)
/*  f0be12c:	8e0a1c54 */ 	lw	$t2,0x1c54($s0)
/*  f0be130:	8e0900c4 */ 	lw	$t1,0xc4($s0)
/*  f0be134:	01405827 */ 	nor	$t3,$t2,$zero
/*  f0be138:	012b6024 */ 	and	$t4,$t1,$t3
/*  f0be13c:	318e0004 */ 	andi	$t6,$t4,0x4
/*  f0be140:	51c00028 */ 	beqzl	$t6,.L0f0be1e4
/*  f0be144:	920e1bfc */ 	lbu	$t6,0x1bfc($s0)
/*  f0be148:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0be14c:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0be150:	51a00024 */ 	beqzl	$t5,.L0f0be1e4
/*  f0be154:	920e1bfc */ 	lbu	$t6,0x1bfc($s0)
/*  f0be158:	4481a000 */ 	mtc1	$at,$f20
/*  f0be15c:	0fc4a2b5 */ 	jal	currentPlayerSetFovY
/*  f0be160:	4600a306 */ 	mov.s	$f12,$f20
/*  f0be164:	0c002f4c */ 	jal	viSetFovY
/*  f0be168:	4600a306 */ 	mov.s	$f12,$f20
/*  f0be16c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be170:	8e190480 */ 	lw	$t9,0x480($s0)
/*  f0be174:	8f2f0000 */ 	lw	$t7,0x0($t9)
/*  f0be178:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f0be17c:	e7aa0308 */ 	swc1	$f10,0x308($sp)
/*  f0be180:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f0be184:	8f0a0000 */ 	lw	$t2,0x0($t8)
/*  f0be188:	c552000c */ 	lwc1	$f18,0xc($t2)
/*  f0be18c:	e7b2030c */ 	swc1	$f18,0x30c($sp)
/*  f0be190:	8e090480 */ 	lw	$t1,0x480($s0)
/*  f0be194:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0be198:	c5640010 */ 	lwc1	$f4,0x10($t3)
/*  f0be19c:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0be1a0:	e7a40310 */ 	swc1	$f4,0x310($sp)
/*  f0be1a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0be1a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0be1ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0be1b0:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0be1b4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0be1b8:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0be1bc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0be1c0:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f0be1c4:	27a40308 */ 	addiu	$a0,$sp,0x308
/*  f0be1c8:	8d820480 */ 	lw	$v0,0x480($t4)
/*  f0be1cc:	24450010 */ 	addiu	$a1,$v0,0x10
/*  f0be1d0:	0fc306f6 */ 	jal	func0f0c1bd8
/*  f0be1d4:	24460004 */ 	addiu	$a2,$v0,0x4
/*  f0be1d8:	100005d6 */ 	b	.L0f0bf934
/*  f0be1dc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be1e0:	920e1bfc */ 	lbu	$t6,0x1bfc($s0)
.L0f0be1e4:
/*  f0be1e4:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f0be1e8:	544e0011 */ 	bnel	$v0,$t6,.L0f0be230
/*  f0be1ec:	960f0010 */ 	lhu	$t7,0x10($s0)
/*  f0be1f0:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0be1f4:	00000000 */ 	nop
/*  f0be1f8:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f0be1fc:	3c01800a */ 	lui	$at,%hi(g_WarpPadId)
/*  f0be200:	00002025 */ 	or	$a0,$zero,$zero
/*  f0be204:	95b91c00 */ 	lhu	$t9,0x1c00($t5)
/*  f0be208:	00002825 */ 	or	$a1,$zero,$zero
/*  f0be20c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0be210:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0be214:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0be218:	a439dde8 */ 	sh	$t9,%lo(g_WarpPadId)($at)
/*  f0be21c:	0fc2e72f */ 	jal	func0f0b9cbc
/*  f0be220:	00000000 */ 	nop
/*  f0be224:	100005c3 */ 	b	.L0f0bf934
/*  f0be228:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be22c:	960f0010 */ 	lhu	$t7,0x10($s0)
.L0f0be230:
/*  f0be230:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0be234:	27b802fc */ 	addiu	$t8,$sp,0x2fc
/*  f0be238:	15e10241 */ 	bne	$t7,$at,.L0f0beb40
/*  f0be23c:	3c0a8007 */ 	lui	$t2,%hi(var800709d0)
/*  f0be240:	254a09d0 */ 	addiu	$t2,$t2,%lo(var800709d0)
/*  f0be244:	8d410000 */ 	lw	$at,0x0($t2)
/*  f0be248:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0be24c:	3c0e8007 */ 	lui	$t6,%hi(var800709dc)
/*  f0be250:	af010000 */ 	sw	$at,0x0($t8)
/*  f0be254:	8d410008 */ 	lw	$at,0x8($t2)
/*  f0be258:	25ce09dc */ 	addiu	$t6,$t6,%lo(var800709dc)
/*  f0be25c:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0be260:	af010008 */ 	sw	$at,0x8($t8)
/*  f0be264:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0be268:	27ac02f0 */ 	addiu	$t4,$sp,0x2f0
/*  f0be26c:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0be270:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0be274:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0be278:	3c098007 */ 	lui	$t1,%hi(var800709e8)
/*  f0be27c:	252909e8 */ 	addiu	$t1,$t1,%lo(var800709e8)
/*  f0be280:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0be284:	ad810008 */ 	sw	$at,0x8($t4)
/*  f0be288:	8d210000 */ 	lw	$at,0x0($t1)
/*  f0be28c:	27af02e4 */ 	addiu	$t7,$sp,0x2e4
/*  f0be290:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f0be294:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0be298:	8d210008 */ 	lw	$at,0x8($t1)
/*  f0be29c:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f0be2a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0be2a4:	ade10008 */ 	sw	$at,0x8($t7)
/*  f0be2a8:	afa002e0 */ 	sw	$zero,0x2e0($sp)
/*  f0be2ac:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0be2b0:	8e110264 */ 	lw	$s1,0x264($s0)
/*  f0be2b4:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0be2b8:	00000000 */ 	nop
/*  f0be2bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0be2c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0be2c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0be2c8:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0be2cc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0be2d0:	0fc2f4f1 */ 	jal	func0f0bd3c4
/*  f0be2d4:	00000000 */ 	nop
/*  f0be2d8:	522001fc */ 	beqzl	$s1,.L0f0beacc
/*  f0be2dc:	8faa02e0 */ 	lw	$t2,0x2e0($sp)
/*  f0be2e0:	8e2b0014 */ 	lw	$t3,0x14($s1)
/*  f0be2e4:	516001f9 */ 	beqzl	$t3,.L0f0beacc
/*  f0be2e8:	8faa02e0 */ 	lw	$t2,0x2e0($sp)
/*  f0be2ec:	c622001c */ 	lwc1	$f2,0x1c($s1)
/*  f0be2f0:	c62e0028 */ 	lwc1	$f14,0x28($s1)
/*  f0be2f4:	c6200034 */ 	lwc1	$f0,0x34($s1)
/*  f0be2f8:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0be2fc:	00000000 */ 	nop
/*  f0be300:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0be304:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0be308:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0be30c:	0c012974 */ 	jal	sqrtf
/*  f0be310:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0be314:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f0be318:	c624001c */ 	lwc1	$f4,0x1c($s1)
/*  f0be31c:	27b9024e */ 	addiu	$t9,$sp,0x24e
/*  f0be320:	00008025 */ 	or	$s0,$zero,$zero
/*  f0be324:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0be328:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0be32c:	27a5027c */ 	addiu	$a1,$sp,0x27c
/*  f0be330:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f0be334:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f0be338:	e7a602b8 */ 	swc1	$f6,0x2b8($sp)
/*  f0be33c:	c6280020 */ 	lwc1	$f8,0x20($s1)
/*  f0be340:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f0be344:	e7b202bc */ 	swc1	$f18,0x2bc($sp)
/*  f0be348:	c62a0024 */ 	lwc1	$f10,0x24($s1)
/*  f0be34c:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0be350:	e7a402c0 */ 	swc1	$f4,0x2c0($sp)
/*  f0be354:	c6260028 */ 	lwc1	$f6,0x28($s1)
/*  f0be358:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0be35c:	e7a802c4 */ 	swc1	$f8,0x2c4($sp)
/*  f0be360:	c632002c */ 	lwc1	$f18,0x2c($s1)
/*  f0be364:	46009283 */ 	div.s	$f10,$f18,$f0
/*  f0be368:	e7aa02c8 */ 	swc1	$f10,0x2c8($sp)
/*  f0be36c:	c6240030 */ 	lwc1	$f4,0x30($s1)
/*  f0be370:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0be374:	e7a602cc */ 	swc1	$f6,0x2cc($sp)
/*  f0be378:	c6280034 */ 	lwc1	$f8,0x34($s1)
/*  f0be37c:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f0be380:	e7b202d0 */ 	swc1	$f18,0x2d0($sp)
/*  f0be384:	c62a0038 */ 	lwc1	$f10,0x38($s1)
/*  f0be388:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0be38c:	e7a402d4 */ 	swc1	$f4,0x2d4($sp)
/*  f0be390:	c626003c */ 	lwc1	$f6,0x3c($s1)
/*  f0be394:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0be398:	e7a802d8 */ 	swc1	$f8,0x2d8($sp)
/*  f0be39c:	8e2d0014 */ 	lw	$t5,0x14($s1)
/*  f0be3a0:	c5b20008 */ 	lwc1	$f18,0x8($t5)
/*  f0be3a4:	e7b202fc */ 	swc1	$f18,0x2fc($sp)
/*  f0be3a8:	8e2c0014 */ 	lw	$t4,0x14($s1)
/*  f0be3ac:	c58a000c */ 	lwc1	$f10,0xc($t4)
/*  f0be3b0:	e7aa0300 */ 	swc1	$f10,0x300($sp)
/*  f0be3b4:	8e2e0014 */ 	lw	$t6,0x14($s1)
/*  f0be3b8:	c5c40010 */ 	lwc1	$f4,0x10($t6)
/*  f0be3bc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0be3c0:	0fc58865 */ 	jal	func0f162194
/*  f0be3c4:	e7a40304 */ 	swc1	$f4,0x304($sp)
/*  f0be3c8:	87b8027c */ 	lh	$t8,0x27c($sp)
/*  f0be3cc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0be3d0:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0be3d4:	17010002 */ 	bne	$t8,$at,.L0f0be3e0
/*  f0be3d8:	00000000 */ 	nop
/*  f0be3dc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0be3e0:
/*  f0be3e0:	5200000f */ 	beqzl	$s0,.L0f0be420
/*  f0be3e4:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be3e8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be3ec:	8e690038 */ 	lw	$t1,0x38($s3)
/*  f0be3f0:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f0be3f4:	8e0f00c8 */ 	lw	$t7,0xc8($s0)
/*  f0be3f8:	01e95021 */ 	addu	$t2,$t7,$t1
/*  f0be3fc:	ae0a00c8 */ 	sw	$t2,0xc8($s0)
/*  f0be400:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be404:	8e0b00c8 */ 	lw	$t3,0xc8($s0)
/*  f0be408:	29610079 */ 	slti	$at,$t3,0x79
/*  f0be40c:	1420000f */ 	bnez	$at,.L0f0be44c
/*  f0be410:	00000000 */ 	nop
/*  f0be414:	1000000d */ 	b	.L0f0be44c
/*  f0be418:	a60d0010 */ 	sh	$t5,0x10($s0)
/*  f0be41c:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0be420:
/*  f0be420:	8e0200c8 */ 	lw	$v0,0xc8($s0)
/*  f0be424:	18400009 */ 	blez	$v0,.L0f0be44c
/*  f0be428:	00000000 */ 	nop
/*  f0be42c:	8e6c0038 */ 	lw	$t4,0x38($s3)
/*  f0be430:	004c7023 */ 	subu	$t6,$v0,$t4
/*  f0be434:	ae0e00c8 */ 	sw	$t6,0xc8($s0)
/*  f0be438:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0be43c:	8e1900c8 */ 	lw	$t9,0xc8($s0)
/*  f0be440:	07210002 */ 	bgez	$t9,.L0f0be44c
/*  f0be444:	00000000 */ 	nop
/*  f0be448:	ae0000c8 */ 	sw	$zero,0xc8($s0)
.L0f0be44c:
/*  f0be44c:	0c005882 */ 	jal	func00016208
/*  f0be450:	27a502f0 */ 	addiu	$a1,$sp,0x2f0
/*  f0be454:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0be458:	0c005882 */ 	jal	func00016208
/*  f0be45c:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0be460:	8e380040 */ 	lw	$t8,0x40($s1)
/*  f0be464:	330f0080 */ 	andi	$t7,$t8,0x80
/*  f0be468:	51e00198 */ 	beqzl	$t7,.L0f0beacc
/*  f0be46c:	8faa02e0 */ 	lw	$t2,0x2e0($sp)
/*  f0be470:	8e690288 */ 	lw	$t1,0x288($s3)
/*  f0be474:	8e340048 */ 	lw	$s4,0x48($s1)
/*  f0be478:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0be47c:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0be480:	8e6a0288 */ 	lw	$t2,0x288($s3)
/*  f0be484:	00408025 */ 	or	$s0,$v0,$zero
/*  f0be488:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0be48c:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0be490:	8e6d0288 */ 	lw	$t5,0x288($s3)
/*  f0be494:	00029600 */ 	sll	$s2,$v0,0x18
/*  f0be498:	00125e03 */ 	sra	$t3,$s2,0x18
/*  f0be49c:	01609025 */ 	or	$s2,$t3,$zero
/*  f0be4a0:	0fc549d9 */ 	jal	optionsGetContpadNum2
/*  f0be4a4:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0be4a8:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0be4ac:	00156603 */ 	sra	$t4,$s5,0x18
/*  f0be4b0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0be4b4:	0180a825 */ 	or	$s5,$t4,$zero
/*  f0be4b8:	a3a0023d */ 	sb	$zero,0x23d($sp)
/*  f0be4bc:	a3a0023c */ 	sb	$zero,0x23c($sp)
/*  f0be4c0:	afa00118 */ 	sw	$zero,0x118($sp)
/*  f0be4c4:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0be4c8:	12010008 */ 	beq	$s0,$at,.L0f0be4ec
/*  f0be4cc:	afa00110 */ 	sw	$zero,0x110($sp)
/*  f0be4d0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0be4d4:	12010005 */ 	beq	$s0,$at,.L0f0be4ec
/*  f0be4d8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0be4dc:	12010003 */ 	beq	$s0,$at,.L0f0be4ec
/*  f0be4e0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0be4e4:	56010062 */ 	bnel	$s0,$at,.L0f0be670
/*  f0be4e8:	8e6f028c */ 	lw	$t7,0x28c($s3)
.L0f0be4ec:
/*  f0be4ec:	8e6e028c */ 	lw	$t6,0x28c($s3)
/*  f0be4f0:	3c188007 */ 	lui	$t8,%hi(g_PlayersWithControl)
/*  f0be4f4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0be4f8:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0be4fc:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f0be500:	8f180750 */ 	lw	$t8,%lo(g_PlayersWithControl)($t8)
/*  f0be504:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0be508:	53000049 */ 	beqzl	$t8,.L0f0be630
/*  f0be50c:	afac0114 */ 	sw	$t4,0x114($sp)
/*  f0be510:	12010004 */ 	beq	$s0,$at,.L0f0be524
/*  f0be514:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be518:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0be51c:	1601001d */ 	bne	$s0,$at,.L0f0be594
/*  f0be520:	3405c000 */ 	dli	$a1,0xc000
.L0f0be524:
/*  f0be524:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0be528:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0be52c:	0c0053d8 */ 	jal	contGetButtons
/*  f0be530:	3405c000 */ 	dli	$a1,0xc000
/*  f0be534:	1440000c */ 	bnez	$v0,.L0f0be568
/*  f0be538:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be53c:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0be540:	01202025 */ 	or	$a0,$t1,$zero
/*  f0be544:	0c0053d8 */ 	jal	contGetButtons
/*  f0be548:	3405c000 */ 	dli	$a1,0xc000
/*  f0be54c:	14400006 */ 	bnez	$v0,.L0f0be568
/*  f0be550:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be554:	00045603 */ 	sra	$t2,$a0,0x18
/*  f0be558:	01402025 */ 	or	$a0,$t2,$zero
/*  f0be55c:	0c0053d8 */ 	jal	contGetButtons
/*  f0be560:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f0be564:	10400002 */ 	beqz	$v0,.L0f0be570
.L0f0be568:
/*  f0be568:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0be56c:	afab0114 */ 	sw	$t3,0x114($sp)
.L0f0be570:
/*  f0be570:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be574:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f0be578:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0be57c:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f0be580:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f0be584:	1040001e */ 	beqz	$v0,.L0f0be600
/*  f0be588:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0be58c:	1000001c */ 	b	.L0f0be600
/*  f0be590:	afac0118 */ 	sw	$t4,0x118($sp)
.L0f0be594:
/*  f0be594:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be598:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0be59c:	0c0053d8 */ 	jal	contGetButtons
/*  f0be5a0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0be5a4:	1440000c */ 	bnez	$v0,.L0f0be5d8
/*  f0be5a8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be5ac:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0be5b0:	03202025 */ 	or	$a0,$t9,$zero
/*  f0be5b4:	0c0053d8 */ 	jal	contGetButtons
/*  f0be5b8:	3405c000 */ 	dli	$a1,0xc000
/*  f0be5bc:	14400006 */ 	bnez	$v0,.L0f0be5d8
/*  f0be5c0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be5c4:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0be5c8:	03002025 */ 	or	$a0,$t8,$zero
/*  f0be5cc:	0c0053d8 */ 	jal	contGetButtons
/*  f0be5d0:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f0be5d4:	10400002 */ 	beqz	$v0,.L0f0be5e0
.L0f0be5d8:
/*  f0be5d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0be5dc:	afaf0114 */ 	sw	$t7,0x114($sp)
.L0f0be5e0:
/*  f0be5e0:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be5e4:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0be5e8:	01202025 */ 	or	$a0,$t1,$zero
/*  f0be5ec:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f0be5f0:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f0be5f4:	10400002 */ 	beqz	$v0,.L0f0be600
/*  f0be5f8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0be5fc:	afaa0118 */ 	sw	$t2,0x118($sp)
.L0f0be600:
/*  f0be600:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be604:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0be608:	0c005384 */ 	jal	contGetStickX
/*  f0be60c:	01602025 */ 	or	$a0,$t3,$zero
/*  f0be610:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be614:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f0be618:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f0be61c:	0c0053ae */ 	jal	contGetStickY
/*  f0be620:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0be624:	10000002 */ 	b	.L0f0be630
/*  f0be628:	a3a2023c */ 	sb	$v0,0x23c($sp)
/*  f0be62c:	afac0114 */ 	sw	$t4,0x114($sp)
.L0f0be630:
/*  f0be630:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be634:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0be638:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0be63c:	0c0053d8 */ 	jal	contGetButtons
/*  f0be640:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f0be644:	14400006 */ 	bnez	$v0,.L0f0be660
/*  f0be648:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be64c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0be650:	03202025 */ 	or	$a0,$t9,$zero
/*  f0be654:	0c0053d8 */ 	jal	contGetButtons
/*  f0be658:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f0be65c:	10400044 */ 	beqz	$v0,.L0f0be770
.L0f0be660:
/*  f0be660:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0be664:	10000042 */ 	b	.L0f0be770
/*  f0be668:	afb80110 */ 	sw	$t8,0x110($sp)
/*  f0be66c:	8e6f028c */ 	lw	$t7,0x28c($s3)
.L0f0be670:
/*  f0be670:	3c0a8007 */ 	lui	$t2,%hi(g_PlayersWithControl)
/*  f0be674:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0be678:	000f4880 */ 	sll	$t1,$t7,0x2
/*  f0be67c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0be680:	8d4a0750 */ 	lw	$t2,%lo(g_PlayersWithControl)($t2)
/*  f0be684:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0be688:	51400031 */ 	beqzl	$t2,.L0f0be750
/*  f0be68c:	afad0114 */ 	sw	$t5,0x114($sp)
/*  f0be690:	12010004 */ 	beq	$s0,$at,.L0f0be6a4
/*  f0be694:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be698:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0be69c:	16010011 */ 	bne	$s0,$at,.L0f0be6e4
/*  f0be6a0:	24052000 */ 	addiu	$a1,$zero,0x2000
.L0f0be6a4:
/*  f0be6a4:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0be6a8:	01602025 */ 	or	$a0,$t3,$zero
/*  f0be6ac:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f0be6b0:	34058000 */ 	dli	$a1,0x8000
/*  f0be6b4:	10400003 */ 	beqz	$v0,.L0f0be6c4
/*  f0be6b8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be6bc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0be6c0:	afad0118 */ 	sw	$t5,0x118($sp)
.L0f0be6c4:
/*  f0be6c4:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0be6c8:	01802025 */ 	or	$a0,$t4,$zero
/*  f0be6cc:	0c0053d8 */ 	jal	contGetButtons
/*  f0be6d0:	24056030 */ 	addiu	$a1,$zero,0x6030
/*  f0be6d4:	10400012 */ 	beqz	$v0,.L0f0be720
/*  f0be6d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0be6dc:	10000010 */ 	b	.L0f0be720
/*  f0be6e0:	afae0114 */ 	sw	$t6,0x114($sp)
.L0f0be6e4:
/*  f0be6e4:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be6e8:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0be6ec:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f0be6f0:	03202025 */ 	or	$a0,$t9,$zero
/*  f0be6f4:	10400003 */ 	beqz	$v0,.L0f0be704
/*  f0be6f8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be6fc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0be700:	afb80118 */ 	sw	$t8,0x118($sp)
.L0f0be704:
/*  f0be704:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0be708:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0be70c:	0c0053d8 */ 	jal	contGetButtons
/*  f0be710:	3405c030 */ 	dli	$a1,0xc030
/*  f0be714:	10400002 */ 	beqz	$v0,.L0f0be720
/*  f0be718:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0be71c:	afa90114 */ 	sw	$t1,0x114($sp)
.L0f0be720:
/*  f0be720:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be724:	00045603 */ 	sra	$t2,$a0,0x18
/*  f0be728:	0c005384 */ 	jal	contGetStickX
/*  f0be72c:	01402025 */ 	or	$a0,$t2,$zero
/*  f0be730:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be734:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0be738:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f0be73c:	0c0053ae */ 	jal	contGetStickY
/*  f0be740:	01602025 */ 	or	$a0,$t3,$zero
/*  f0be744:	10000002 */ 	b	.L0f0be750
/*  f0be748:	a3a2023c */ 	sb	$v0,0x23c($sp)
/*  f0be74c:	afad0114 */ 	sw	$t5,0x114($sp)
.L0f0be750:
/*  f0be750:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be754:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0be758:	01802025 */ 	or	$a0,$t4,$zero
/*  f0be75c:	0c0053d8 */ 	jal	contGetButtons
/*  f0be760:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f0be764:	10400002 */ 	beqz	$v0,.L0f0be770
/*  f0be768:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0be76c:	afae0110 */ 	sw	$t6,0x110($sp)
.L0f0be770:
/*  f0be770:	8fb90110 */ 	lw	$t9,0x110($sp)
/*  f0be774:	5320000b */ 	beqzl	$t9,.L0f0be7a4
/*  f0be778:	83a9023c */ 	lb	$t1,0x23c($sp)
/*  f0be77c:	8e780314 */ 	lw	$t8,0x314($s3)
/*  f0be780:	17000005 */ 	bnez	$t8,.L0f0be798
/*  f0be784:	00000000 */ 	nop
/*  f0be788:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f0be78c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0be790:	10000004 */ 	b	.L0f0be7a4
/*  f0be794:	83a9023c */ 	lb	$t1,0x23c($sp)
.L0f0be798:
/*  f0be798:	0fc5e36f */ 	jal	mpPushPauseDialog
/*  f0be79c:	00000000 */ 	nop
/*  f0be7a0:	83a9023c */ 	lb	$t1,0x23c($sp)
.L0f0be7a4:
/*  f0be7a4:	c6600044 */ 	lwc1	$f0,0x44($s3)
/*  f0be7a8:	83aa023d */ 	lb	$t2,0x23d($sp)
/*  f0be7ac:	44893000 */ 	mtc1	$t1,$f6
/*  f0be7b0:	3c017f1b */ 	lui	$at,%hi(var7f1ad684)
/*  f0be7b4:	000a5823 */ 	negu	$t3,$t2
/*  f0be7b8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0be7bc:	448b5000 */ 	mtc1	$t3,$f10
/*  f0be7c0:	c430d684 */ 	lwc1	$f16,%lo(var7f1ad684)($at)
/*  f0be7c4:	c7ae02c0 */ 	lwc1	$f14,0x2c0($sp)
/*  f0be7c8:	c7a202b8 */ 	lwc1	$f2,0x2b8($sp)
/*  f0be7cc:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0be7d0:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0be7d4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0be7d8:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f0be7dc:	e7ae02b4 */ 	swc1	$f14,0x2b4($sp)
/*  f0be7e0:	e7a202ac */ 	swc1	$f2,0x2ac($sp)
/*  f0be7e4:	46109582 */ 	mul.s	$f22,$f18,$f16
/*  f0be7e8:	00000000 */ 	nop
/*  f0be7ec:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0be7f0:	00000000 */ 	nop
/*  f0be7f4:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0be7f8:	00000000 */ 	nop
/*  f0be7fc:	460e7482 */ 	mul.s	$f18,$f14,$f14
/*  f0be800:	00000000 */ 	nop
/*  f0be804:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0be808:	e7a80174 */ 	swc1	$f8,0x174($sp)
/*  f0be80c:	0c012974 */ 	jal	sqrtf
/*  f0be810:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0be814:	c7a202ac */ 	lwc1	$f2,0x2ac($sp)
/*  f0be818:	c7ae02b4 */ 	lwc1	$f14,0x2b4($sp)
/*  f0be81c:	4600b306 */ 	mov.s	$f12,$f22
/*  f0be820:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f0be824:	46007383 */ 	div.s	$f14,$f14,$f0
/*  f0be828:	e7a202ac */ 	swc1	$f2,0x2ac($sp)
/*  f0be82c:	0c0068f7 */ 	jal	sinf
/*  f0be830:	e7ae02b4 */ 	swc1	$f14,0x2b4($sp)
/*  f0be834:	46000506 */ 	mov.s	$f20,$f0
/*  f0be838:	0c0068f4 */ 	jal	cosf
/*  f0be83c:	4600b306 */ 	mov.s	$f12,$f22
/*  f0be840:	c7a202ac */ 	lwc1	$f2,0x2ac($sp)
/*  f0be844:	c7ae02b4 */ 	lwc1	$f14,0x2b4($sp)
/*  f0be848:	44803000 */ 	mtc1	$zero,$f6
/*  f0be84c:	46141102 */ 	mul.s	$f4,$f2,$f20
/*  f0be850:	e7a0014c */ 	swc1	$f0,0x14c($sp)
/*  f0be854:	c7ac0174 */ 	lwc1	$f12,0x174($sp)
/*  f0be858:	46147202 */ 	mul.s	$f8,$f14,$f20
/*  f0be85c:	e7a60154 */ 	swc1	$f6,0x154($sp)
/*  f0be860:	e7a40150 */ 	swc1	$f4,0x150($sp)
/*  f0be864:	0c0068f7 */ 	jal	sinf
/*  f0be868:	e7a80158 */ 	swc1	$f8,0x158($sp)
/*  f0be86c:	46000506 */ 	mov.s	$f20,$f0
/*  f0be870:	0c0068f4 */ 	jal	cosf
/*  f0be874:	c7ac0174 */ 	lwc1	$f12,0x174($sp)
/*  f0be878:	44801000 */ 	mtc1	$zero,$f2
/*  f0be87c:	c7b202c8 */ 	lwc1	$f18,0x2c8($sp)
/*  f0be880:	27b5013c */ 	addiu	$s5,$sp,0x13c
/*  f0be884:	e7a0015c */ 	swc1	$f0,0x15c($sp)
/*  f0be888:	4612103e */ 	c.le.s	$f2,$f18
/*  f0be88c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0be890:	27a4015c */ 	addiu	$a0,$sp,0x15c
/*  f0be894:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f0be898:	45000003 */ 	bc1f	.L0f0be8a8
/*  f0be89c:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f0be8a0:	10000003 */ 	b	.L0f0be8b0
/*  f0be8a4:	e7b40164 */ 	swc1	$f20,0x164($sp)
.L0f0be8a8:
/*  f0be8a8:	4600a287 */ 	neg.s	$f10,$f20
/*  f0be8ac:	e7aa0164 */ 	swc1	$f10,0x164($sp)
.L0f0be8b0:
/*  f0be8b0:	0fc25dce */ 	jal	func0f097738
/*  f0be8b4:	e7a20168 */ 	swc1	$f2,0x168($sp)
/*  f0be8b8:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f0be8bc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0be8c0:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0be8c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0be8c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0be8cc:	0c0056c4 */ 	jal	func00015b10
/*  f0be8d0:	26850004 */ 	addiu	$a1,$s4,0x4
/*  f0be8d4:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0be8d8:	44808000 */ 	mtc1	$zero,$f16
/*  f0be8dc:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0be8e0:	358e4000 */ 	ori	$t6,$t4,0x4000
/*  f0be8e4:	31d80080 */ 	andi	$t8,$t6,0x80
/*  f0be8e8:	a68d00b2 */ 	sh	$t5,0xb2($s4)
/*  f0be8ec:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f0be8f0:	e6900018 */ 	swc1	$f16,0x18($s4)
/*  f0be8f4:	e6900014 */ 	swc1	$f16,0x14($s4)
/*  f0be8f8:	17000002 */ 	bnez	$t8,.L0f0be904
/*  f0be8fc:	e6900010 */ 	swc1	$f16,0x10($s4)
/*  f0be900:	ae800088 */ 	sw	$zero,0x88($s4)
.L0f0be904:
/*  f0be904:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f0be908:	51e00003 */ 	beqzl	$t7,.L0f0be918
/*  f0be90c:	c6820004 */ 	lwc1	$f2,0x4($s4)
/*  f0be910:	a6200062 */ 	sh	$zero,0x62($s1)
/*  f0be914:	c6820004 */ 	lwc1	$f2,0x4($s4)
.L0f0be918:
/*  f0be918:	c68e0008 */ 	lwc1	$f14,0x8($s4)
/*  f0be91c:	c680000c */ 	lwc1	$f0,0xc($s4)
/*  f0be920:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0be924:	00000000 */ 	nop
/*  f0be928:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0be92c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0be930:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0be934:	0c012974 */ 	jal	sqrtf
/*  f0be938:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f0be93c:	8fa90114 */ 	lw	$t1,0x114($sp)
/*  f0be940:	46000386 */ 	mov.s	$f14,$f0
/*  f0be944:	3c014140 */ 	lui	$at,0x4140
/*  f0be948:	51200006 */ 	beqzl	$t1,.L0f0be964
/*  f0be94c:	44816000 */ 	mtc1	$at,$f12
/*  f0be950:	3c013f80 */ 	lui	$at,0x3f80
/*  f0be954:	44816000 */ 	mtc1	$at,$f12
/*  f0be958:	10000004 */ 	b	.L0f0be96c
/*  f0be95c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0be960:	44816000 */ 	mtc1	$at,$f12
.L0f0be964:
/*  f0be964:	00000000 */ 	nop
/*  f0be968:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0be96c:
/*  f0be96c:	46000086 */ 	mov.s	$f2,$f0
/*  f0be970:	3c017f1b */ 	lui	$at,%hi(var7f1ad688)
/*  f0be974:	4502000c */ 	bc1fl	.L0f0be9a8
/*  f0be978:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0be97c:	c42ad688 */ 	lwc1	$f10,%lo(var7f1ad688)($at)
/*  f0be980:	c6640044 */ 	lwc1	$f4,0x44($s3)
/*  f0be984:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0be988:	46003080 */ 	add.s	$f2,$f6,$f0
/*  f0be98c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0be990:	00000000 */ 	nop
/*  f0be994:	45020011 */ 	bc1fl	.L0f0be9dc
/*  f0be998:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0be99c:	1000000e */ 	b	.L0f0be9d8
/*  f0be9a0:	46006086 */ 	mov.s	$f2,$f12
/*  f0be9a4:	4600603c */ 	c.lt.s	$f12,$f0
.L0f0be9a8:
/*  f0be9a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad68c)
/*  f0be9ac:	4502000b */ 	bc1fl	.L0f0be9dc
/*  f0be9b0:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0be9b4:	c432d68c */ 	lwc1	$f18,%lo(var7f1ad68c)($at)
/*  f0be9b8:	c6680044 */ 	lwc1	$f8,0x44($s3)
/*  f0be9bc:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f0be9c0:	460a0081 */ 	sub.s	$f2,$f0,$f10
/*  f0be9c4:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0be9c8:	00000000 */ 	nop
/*  f0be9cc:	45020003 */ 	bc1fl	.L0f0be9dc
/*  f0be9d0:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0be9d4:	46006086 */ 	mov.s	$f2,$f12
.L0f0be9d8:
/*  f0be9d8:	c6840004 */ 	lwc1	$f4,0x4($s4)
.L0f0be9dc:
/*  f0be9dc:	c6880008 */ 	lwc1	$f8,0x8($s4)
/*  f0be9e0:	27b001bc */ 	addiu	$s0,$sp,0x1bc
/*  f0be9e4:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0be9e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0be9ec:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0be9f0:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0be9f4:	460e3483 */ 	div.s	$f18,$f6,$f14
/*  f0be9f8:	c686000c */ 	lwc1	$f6,0xc($s4)
/*  f0be9fc:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f0bea00:	e6920004 */ 	swc1	$f18,0x4($s4)
/*  f0bea04:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f0bea08:	460e9203 */ 	div.s	$f8,$f18,$f14
/*  f0bea0c:	e6840008 */ 	swc1	$f4,0x8($s4)
/*  f0bea10:	0c005755 */ 	jal	func00015d54
/*  f0bea14:	e688000c */ 	swc1	$f8,0xc($s4)
/*  f0bea18:	27b2012c */ 	addiu	$s2,$sp,0x12c
/*  f0bea1c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0bea20:	0fc25c11 */ 	jal	func0f097044
/*  f0bea24:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bea28:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f0bea2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bea30:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0bea34:	0fc25dce */ 	jal	func0f097738
/*  f0bea38:	02402825 */ 	or	$a1,$s2,$zero
/*  f0bea3c:	27b2017c */ 	addiu	$s2,$sp,0x17c
/*  f0bea40:	02402825 */ 	or	$a1,$s2,$zero
/*  f0bea44:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0bea48:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bea4c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0bea50:	0c005768 */ 	jal	func00015da0
/*  f0bea54:	27a502b8 */ 	addiu	$a1,$sp,0x2b8
/*  f0bea58:	c7a002a8 */ 	lwc1	$f0,0x2a8($sp)
/*  f0bea5c:	c7aa02b8 */ 	lwc1	$f10,0x2b8($sp)
/*  f0bea60:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0bea64:	e624001c */ 	swc1	$f4,0x1c($s1)
/*  f0bea68:	c7a602bc */ 	lwc1	$f6,0x2bc($sp)
/*  f0bea6c:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0bea70:	e6320020 */ 	swc1	$f18,0x20($s1)
/*  f0bea74:	c7a802c0 */ 	lwc1	$f8,0x2c0($sp)
/*  f0bea78:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0bea7c:	e62a0024 */ 	swc1	$f10,0x24($s1)
/*  f0bea80:	c7a402c4 */ 	lwc1	$f4,0x2c4($sp)
/*  f0bea84:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bea88:	e6260028 */ 	swc1	$f6,0x28($s1)
/*  f0bea8c:	c7b202c8 */ 	lwc1	$f18,0x2c8($sp)
/*  f0bea90:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f0bea94:	e628002c */ 	swc1	$f8,0x2c($s1)
/*  f0bea98:	c7aa02cc */ 	lwc1	$f10,0x2cc($sp)
/*  f0bea9c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0beaa0:	e6240030 */ 	swc1	$f4,0x30($s1)
/*  f0beaa4:	c7a602d0 */ 	lwc1	$f6,0x2d0($sp)
/*  f0beaa8:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0beaac:	e6320034 */ 	swc1	$f18,0x34($s1)
/*  f0beab0:	c7a802d4 */ 	lwc1	$f8,0x2d4($sp)
/*  f0beab4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0beab8:	e62a0038 */ 	swc1	$f10,0x38($s1)
/*  f0beabc:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
/*  f0beac0:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0beac4:	e626003c */ 	swc1	$f6,0x3c($s1)
/*  f0beac8:	8faa02e0 */ 	lw	$t2,0x2e0($sp)
.L0f0beacc:
/*  f0beacc:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0bead0:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0bead4:	15400006 */ 	bnez	$t2,.L0f0beaf0
/*  f0bead8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f0beadc:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0beae0:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f0beae4:	ad600264 */ 	sw	$zero,0x264($t3)
/*  f0beae8:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f0beaec:	a58d0010 */ 	sh	$t5,0x10($t4)
.L0f0beaf0:
/*  f0beaf0:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0beaf4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0beaf8:	1220000c */ 	beqz	$s1,.L0f0beb2c
/*  f0beafc:	af2e0274 */ 	sw	$t6,0x274($t9)
/*  f0beb00:	8e220014 */ 	lw	$v0,0x14($s1)
/*  f0beb04:	10400009 */ 	beqz	$v0,.L0f0beb2c
/*  f0beb08:	24470008 */ 	addiu	$a3,$v0,0x8
/*  f0beb0c:	24580028 */ 	addiu	$t8,$v0,0x28
/*  f0beb10:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0beb14:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0beb18:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0beb1c:	0fc30610 */ 	jal	func0f0c1840
/*  f0beb20:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f0beb24:	10000004 */ 	b	.L0f0beb38
/*  f0beb28:	00000000 */ 	nop
.L0f0beb2c:
/*  f0beb2c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0beb30:	0fc30610 */ 	jal	func0f0c1840
/*  f0beb34:	afa00010 */ 	sw	$zero,0x10($sp)
.L0f0beb38:
/*  f0beb38:	1000037e */ 	b	.L0f0bf934
/*  f0beb3c:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0beb40:
/*  f0beb40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0beb44:	14610261 */ 	bne	$v1,$at,.L0f0bf4cc
/*  f0beb48:	00000000 */ 	nop
/*  f0beb4c:	0fc2e54e */ 	jal	func0f0b9538
/*  f0beb50:	00000000 */ 	nop
/*  f0beb54:	8e6f028c */ 	lw	$t7,0x28c($s3)
/*  f0beb58:	3c0a8007 */ 	lui	$t2,%hi(g_PlayersWithControl)
/*  f0beb5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0beb60:	000f4880 */ 	sll	$t1,$t7,0x2
/*  f0beb64:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0beb68:	8d4a0750 */ 	lw	$t2,%lo(g_PlayersWithControl)($t2)
/*  f0beb6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0beb70:	00002825 */ 	or	$a1,$zero,$zero
/*  f0beb74:	11400007 */ 	beqz	$t2,.L0f0beb94
/*  f0beb78:	00003025 */ 	or	$a2,$zero,$zero
/*  f0beb7c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0beb80:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0beb84:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0beb88:	8fa60330 */ 	lw	$a2,0x330($sp)
/*  f0beb8c:	10000003 */ 	b	.L0f0beb9c
/*  f0beb90:	00000000 */ 	nop
.L0f0beb94:
/*  f0beb94:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0beb98:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0beb9c:
/*  f0beb9c:	0fc2f4f1 */ 	jal	func0f0bd3c4
/*  f0beba0:	00000000 */ 	nop
/*  f0beba4:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0beba8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bebac:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bebb0:	44802000 */ 	mtc1	$zero,$f4
/*  f0bebb4:	27a400f4 */ 	addiu	$a0,$sp,0xf4
/*  f0bebb8:	c612037c */ 	lwc1	$f18,0x37c($s0)
/*  f0bebbc:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0bebc0:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0bebc4:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f0bebc8:	c6080380 */ 	lwc1	$f8,0x380($s0)
/*  f0bebcc:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0bebd0:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f0bebd4:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f0bebd8:	c60a0384 */ 	lwc1	$f10,0x384($s0)
/*  f0bebdc:	44804000 */ 	mtc1	$zero,$f8
/*  f0bebe0:	44803000 */ 	mtc1	$zero,$f6
/*  f0bebe4:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f0bebe8:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f0bebec:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f0bebf0:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f0bebf4:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0bebf8:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0bebfc:	e7a400f8 */ 	swc1	$f4,0xf8($sp)
/*  f0bec00:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f0bec04:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bec08:	246b0028 */ 	addiu	$t3,$v1,0x28
/*  f0bec0c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0bec10:	0fc30610 */ 	jal	func0f0c1840
/*  f0bec14:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bec18:	8e6d0318 */ 	lw	$t5,0x318($s3)
/*  f0bec1c:	3c0c800a */ 	lui	$t4,%hi(g_MissionConfig+0x3)
/*  f0bec20:	15a00228 */ 	bnez	$t5,.L0f0bf4c4
/*  f0bec24:	00000000 */ 	nop
/*  f0bec28:	818edfeb */ 	lb	$t6,%lo(g_MissionConfig+0x3)($t4)
/*  f0bec2c:	05c10225 */ 	bgez	$t6,.L0f0bf4c4
/*  f0bec30:	00000000 */ 	nop
/*  f0bec34:	8e620474 */ 	lw	$v0,0x474($s3)
/*  f0bec38:	18400222 */ 	blez	$v0,.L0f0bf4c4
/*  f0bec3c:	00000000 */ 	nop
/*  f0bec40:	8e790478 */ 	lw	$t9,0x478($s3)
/*  f0bec44:	1720021f */ 	bnez	$t9,.L0f0bf4c4
/*  f0bec48:	00000000 */ 	nop
/*  f0bec4c:	8e7804b4 */ 	lw	$t8,0x4b4($s3)
/*  f0bec50:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0bec54:	1301021b */ 	beq	$t8,$at,.L0f0bf4c4
/*  f0bec58:	00000000 */ 	nop
/*  f0bec5c:	8e6f000c */ 	lw	$t7,0xc($s3)
/*  f0bec60:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0bec64:	29e10015 */ 	slti	$at,$t7,0x15
/*  f0bec68:	14200216 */ 	bnez	$at,.L0f0bf4c4
/*  f0bec6c:	00000000 */ 	nop
/*  f0bec70:	ae690478 */ 	sw	$t1,0x478($s3)
/*  f0bec74:	18400213 */ 	blez	$v0,.L0f0bf4c4
/*  f0bec78:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f0bec7c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0bec80:	4481b000 */ 	mtc1	$at,$f22
/*  f0bec84:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0bec88:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0bec8c:	3c017f1b */ 	lui	$at,%hi(var7f1ad690)
/*  f0bec90:	c434d690 */ 	lwc1	$f20,%lo(var7f1ad690)($at)
/*  f0bec94:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0bec98:	24140013 */ 	addiu	$s4,$zero,0x13
/*  f0bec9c:	24120064 */ 	addiu	$s2,$zero,0x64
.L0f0beca0:
/*  f0beca0:	3c0b800a */ 	lui	$t3,%hi(g_CheatsActiveBank0)
/*  f0beca4:	8d6b21d0 */ 	lw	$t3,%lo(g_CheatsActiveBank0)($t3)
/*  f0beca8:	3c0103c0 */ 	lui	$at,0x3c0
/*  f0becac:	00008825 */ 	or	$s1,$zero,$zero
/*  f0becb0:	01616824 */ 	and	$t5,$t3,$at
/*  f0becb4:	15a00078 */ 	bnez	$t5,.L0f0bee98
/*  f0becb8:	00000000 */ 	nop
/*  f0becbc:	0fc59585 */ 	jal	stageGetIndex
/*  f0becc0:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0becc4:	14540015 */ 	bne	$v0,$s4,.L0f0bed1c
/*  f0becc8:	00000000 */ 	nop
/*  f0beccc:	0c006134 */ 	jal	ailistFindById
/*  f0becd0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0becd4:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0becd8:	3c014000 */ 	lui	$at,0x4000
/*  f0becdc:	44812000 */ 	mtc1	$at,$f4
/*  f0bece0:	c60a0144 */ 	lwc1	$f10,0x144($s0)
/*  f0bece4:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bece8:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f0becec:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0becf0:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0becf4:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0becf8:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f0becfc:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f0bed00:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bed04:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bed08:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bed0c:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bed10:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bed14:	1000002a */ 	b	.L0f0bedc0
/*  f0bed18:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bed1c:
/*  f0bed1c:	0fc59585 */ 	jal	stageGetIndex
/*  f0bed20:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bed24:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0bed28:	14410012 */ 	bne	$v0,$at,.L0f0bed74
/*  f0bed2c:	00000000 */ 	nop
/*  f0bed30:	0c006134 */ 	jal	ailistFindById
/*  f0bed34:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bed38:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bed3c:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f0bed40:	2404005b */ 	addiu	$a0,$zero,0x5b
/*  f0bed44:	c6080144 */ 	lwc1	$f8,0x144($s0)
/*  f0bed48:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bed4c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0bed50:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bed54:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bed58:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0bed5c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bed60:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bed64:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bed68:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bed6c:	10000014 */ 	b	.L0f0bedc0
/*  f0bed70:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bed74:
/*  f0bed74:	0c006134 */ 	jal	ailistFindById
/*  f0bed78:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bed7c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bed80:	3c014000 */ 	lui	$at,0x4000
/*  f0bed84:	44813000 */ 	mtc1	$at,$f6
/*  f0bed88:	c6040144 */ 	lwc1	$f4,0x144($s0)
/*  f0bed8c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bed90:	24190010 */ 	addiu	$t9,$zero,0x10
/*  f0bed94:	46062483 */ 	div.s	$f18,$f4,$f6
/*  f0bed98:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0bed9c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0beda0:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f0beda4:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f0beda8:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bedac:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bedb0:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0bedb4:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bedb8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bedbc:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bedc0:
/*  f0bedc0:	10400035 */ 	beqz	$v0,.L0f0bee98
/*  f0bedc4:	3c014030 */ 	lui	$at,0x4030
/*  f0bedc8:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bedcc:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f0bedd0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0bedd4:	8e090118 */ 	lw	$t1,0x118($s0)
/*  f0bedd8:	8e180114 */ 	lw	$t8,0x114($s0)
/*  f0beddc:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*  f0bede0:	01215025 */ 	or	$t2,$t1,$at
/*  f0bede4:	3c018000 */ 	lui	$at,0x8000
/*  f0bede8:	24190032 */ 	addiu	$t9,$zero,0x32
/*  f0bedec:	370f2000 */ 	ori	$t7,$t8,0x2000
/*  f0bedf0:	01a16025 */ 	or	$t4,$t5,$at
/*  f0bedf4:	ae0f0114 */ 	sw	$t7,0x114($s0)
/*  f0bedf8:	ae0a0118 */ 	sw	$t2,0x118($s0)
/*  f0bedfc:	a20b0125 */ 	sb	$t3,0x125($s0)
/*  f0bee00:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bee04:	ae0c0014 */ 	sw	$t4,0x14($s0)
/*  f0bee08:	a20e02b1 */ 	sb	$t6,0x2b1($s0)
/*  f0bee0c:	a21902e2 */ 	sb	$t9,0x2e2($s0)
/*  f0bee10:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bee14:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bee18:	0fc59585 */ 	jal	stageGetIndex
/*  f0bee1c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bee20:	14540005 */ 	bne	$v0,$s4,.L0f0bee38
/*  f0bee24:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bee28:	0fc0816b */ 	jal	chrAddHealth
/*  f0bee2c:	3c054220 */ 	lui	$a1,0x4220
/*  f0bee30:	10000005 */ 	b	.L0f0bee48
/*  f0bee34:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bee38:
/*  f0bee38:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bee3c:	0fc0816b */ 	jal	chrAddHealth
/*  f0bee40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bee44:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bee48:
/*  f0bee48:	0fc08166 */ 	jal	chrSetMaxDamage
/*  f0bee4c:	3c054080 */ 	lui	$a1,0x4080
/*  f0bee50:	8e180018 */ 	lw	$t8,0x18($s0)
/*  f0bee54:	920d02e1 */ 	lbu	$t5,0x2e1($s0)
/*  f0bee58:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f0bee5c:	3c010004 */ 	lui	$at,0x4
/*  f0bee60:	03017825 */ 	or	$t7,$t8,$at
/*  f0bee64:	35ae0001 */ 	ori	$t6,$t5,0x1
/*  f0bee68:	3c012000 */ 	lui	$at,0x2000
/*  f0bee6c:	a20e02e1 */ 	sb	$t6,0x2e1($s0)
/*  f0bee70:	31d90001 */ 	andi	$t9,$t6,0x1
/*  f0bee74:	01215025 */ 	or	$t2,$t1,$at
/*  f0bee78:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f0bee7c:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f0bee80:	a21902e1 */ 	sb	$t9,0x2e1($s0)
/*  f0bee84:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bee88:	240500f5 */ 	addiu	$a1,$zero,0xf5
/*  f0bee8c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0bee90:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f0bee94:	00003825 */ 	or	$a3,$zero,$zero
.L0f0bee98:
/*  f0bee98:	0fc41b99 */ 	jal	cheatIsActive
/*  f0bee9c:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f0beea0:	10400058 */ 	beqz	$v0,.L0f0bf004
/*  f0beea4:	00000000 */ 	nop
/*  f0beea8:	0fc59585 */ 	jal	stageGetIndex
/*  f0beeac:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0beeb0:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0beeb4:	14410012 */ 	bne	$v0,$at,.L0f0bef00
/*  f0beeb8:	00000000 */ 	nop
/*  f0beebc:	0c006134 */ 	jal	ailistFindById
/*  f0beec0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0beec4:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0beec8:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f0beecc:	2404005b */ 	addiu	$a0,$zero,0x5b
/*  f0beed0:	c60a0144 */ 	lwc1	$f10,0x144($s0)
/*  f0beed4:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0beed8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0beedc:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0beee0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0beee4:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0beee8:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0beeec:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0beef0:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0beef4:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0beef8:	10000011 */ 	b	.L0f0bef40
/*  f0beefc:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bef00:
/*  f0bef00:	0c006134 */ 	jal	ailistFindById
/*  f0bef04:	02802025 */ 	or	$a0,$s4,$zero
/*  f0bef08:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bef0c:	240f0010 */ 	addiu	$t7,$zero,0x10
/*  f0bef10:	2404005a */ 	addiu	$a0,$zero,0x5a
/*  f0bef14:	c6060144 */ 	lwc1	$f6,0x144($s0)
/*  f0bef18:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bef1c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0bef20:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bef24:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bef28:	2405001b */ 	addiu	$a1,$zero,0x1b
/*  f0bef2c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bef30:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bef34:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bef38:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bef3c:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bef40:
/*  f0bef40:	10400030 */ 	beqz	$v0,.L0f0bf004
/*  f0bef44:	3c014030 */ 	lui	$at,0x4030
/*  f0bef48:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bef4c:	34210081 */ 	ori	$at,$at,0x81
/*  f0bef50:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f0bef54:	8e0b0118 */ 	lw	$t3,0x118($s0)
/*  f0bef58:	8e090114 */ 	lw	$t1,0x114($s0)
/*  f0bef5c:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f0bef60:	01616825 */ 	or	$t5,$t3,$at
/*  f0bef64:	3c018000 */ 	lui	$at,0x8000
/*  f0bef68:	240e0064 */ 	addiu	$t6,$zero,0x64
/*  f0bef6c:	352a2080 */ 	ori	$t2,$t1,0x2080
/*  f0bef70:	0321c025 */ 	or	$t8,$t9,$at
/*  f0bef74:	ae0a0114 */ 	sw	$t2,0x114($s0)
/*  f0bef78:	ae0d0118 */ 	sw	$t5,0x118($s0)
/*  f0bef7c:	a20c0125 */ 	sb	$t4,0x125($s0)
/*  f0bef80:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bef84:	a20e02e2 */ 	sb	$t6,0x2e2($s0)
/*  f0bef88:	ae180014 */ 	sw	$t8,0x14($s0)
/*  f0bef8c:	a21502b1 */ 	sb	$s5,0x2b1($s0)
/*  f0bef90:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bef94:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bef98:	0fc59585 */ 	jal	stageGetIndex
/*  f0bef9c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0befa0:	14540005 */ 	bne	$v0,$s4,.L0f0befb8
/*  f0befa4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0befa8:	0fc0816b */ 	jal	chrAddHealth
/*  f0befac:	3c054220 */ 	lui	$a1,0x4220
/*  f0befb0:	10000005 */ 	b	.L0f0befc8
/*  f0befb4:	8e0f0018 */ 	lw	$t7,0x18($s0)
.L0f0befb8:
/*  f0befb8:	4405b000 */ 	mfc1	$a1,$f22
/*  f0befbc:	0fc0816b */ 	jal	chrAddHealth
/*  f0befc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0befc4:	8e0f0018 */ 	lw	$t7,0x18($s0)
.L0f0befc8:
/*  f0befc8:	920c02e1 */ 	lbu	$t4,0x2e1($s0)
/*  f0befcc:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*  f0befd0:	3c010004 */ 	lui	$at,0x4
/*  f0befd4:	01e14825 */ 	or	$t1,$t7,$at
/*  f0befd8:	35990001 */ 	ori	$t9,$t4,0x1
/*  f0befdc:	3c012000 */ 	lui	$at,0x2000
/*  f0befe0:	a21902e1 */ 	sb	$t9,0x2e1($s0)
/*  f0befe4:	33380001 */ 	andi	$t8,$t9,0x1
/*  f0befe8:	4405b000 */ 	mfc1	$a1,$f22
/*  f0befec:	01415825 */ 	or	$t3,$t2,$at
/*  f0beff0:	ae090018 */ 	sw	$t1,0x18($s0)
/*  f0beff4:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*  f0beff8:	a21802e1 */ 	sb	$t8,0x2e1($s0)
/*  f0beffc:	0fc08166 */ 	jal	chrSetMaxDamage
/*  f0bf000:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf004:
/*  f0bf004:	0fc41b99 */ 	jal	cheatIsActive
/*  f0bf008:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f0bf00c:	1040005e */ 	beqz	$v0,.L0f0bf188
/*  f0bf010:	00000000 */ 	nop
/*  f0bf014:	0fc59585 */ 	jal	stageGetIndex
/*  f0bf018:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf01c:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0bf020:	14410012 */ 	bne	$v0,$at,.L0f0bf06c
/*  f0bf024:	00000000 */ 	nop
/*  f0bf028:	0c006134 */ 	jal	ailistFindById
/*  f0bf02c:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bf030:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf034:	240f0010 */ 	addiu	$t7,$zero,0x10
/*  f0bf038:	2404005b */ 	addiu	$a0,$zero,0x5b
/*  f0bf03c:	c6080144 */ 	lwc1	$f8,0x144($s0)
/*  f0bf040:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf044:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0bf048:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bf04c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf050:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0bf054:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf058:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf05c:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bf060:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bf064:	10000011 */ 	b	.L0f0bf0ac
/*  f0bf068:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bf06c:
/*  f0bf06c:	0c006134 */ 	jal	ailistFindById
/*  f0bf070:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bf074:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf078:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f0bf07c:	2404005b */ 	addiu	$a0,$zero,0x5b
/*  f0bf080:	c6040144 */ 	lwc1	$f4,0x144($s0)
/*  f0bf084:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf088:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0bf08c:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0bf090:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf094:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f0bf098:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf09c:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf0a0:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bf0a4:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0bf0a8:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bf0ac:
/*  f0bf0ac:	10400036 */ 	beqz	$v0,.L0f0bf188
/*  f0bf0b0:	3c018030 */ 	lui	$at,0x8030
/*  f0bf0b4:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf0b8:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f0bf0bc:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0bf0c0:	8e0d0118 */ 	lw	$t5,0x118($s0)
/*  f0bf0c4:	8e0a0114 */ 	lw	$t2,0x114($s0)
/*  f0bf0c8:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f0bf0cc:	01a16025 */ 	or	$t4,$t5,$at
/*  f0bf0d0:	3c018000 */ 	lui	$at,0x8000
/*  f0bf0d4:	354b2000 */ 	ori	$t3,$t2,0x2000
/*  f0bf0d8:	24090032 */ 	addiu	$t1,$zero,0x32
/*  f0bf0dc:	240a0032 */ 	addiu	$t2,$zero,0x32
/*  f0bf0e0:	0321c025 */ 	or	$t8,$t9,$at
/*  f0bf0e4:	ae0b0114 */ 	sw	$t3,0x114($s0)
/*  f0bf0e8:	ae0c0118 */ 	sw	$t4,0x118($s0)
/*  f0bf0ec:	a20e0125 */ 	sb	$t6,0x125($s0)
/*  f0bf0f0:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf0f4:	ae180014 */ 	sw	$t8,0x14($s0)
/*  f0bf0f8:	a20f02b1 */ 	sb	$t7,0x2b1($s0)
/*  f0bf0fc:	a20902e2 */ 	sb	$t1,0x2e2($s0)
/*  f0bf100:	a20a0002 */ 	sb	$t2,0x2($s0)
/*  f0bf104:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf108:	0fc59585 */ 	jal	stageGetIndex
/*  f0bf10c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf110:	14540006 */ 	bne	$v0,$s4,.L0f0bf12c
/*  f0bf114:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf118:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf11c:	0fc0816b */ 	jal	chrAddHealth
/*  f0bf120:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf124:	10000004 */ 	b	.L0f0bf138
/*  f0bf128:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf12c:
/*  f0bf12c:	0fc0816b */ 	jal	chrAddHealth
/*  f0bf130:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf134:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf138:
/*  f0bf138:	0fc08166 */ 	jal	chrSetMaxDamage
/*  f0bf13c:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf140:	8e0b0018 */ 	lw	$t3,0x18($s0)
/*  f0bf144:	921802e1 */ 	lbu	$t8,0x2e1($s0)
/*  f0bf148:	8e0c0014 */ 	lw	$t4,0x14($s0)
/*  f0bf14c:	3c010004 */ 	lui	$at,0x4
/*  f0bf150:	01616825 */ 	or	$t5,$t3,$at
/*  f0bf154:	37090001 */ 	ori	$t1,$t8,0x1
/*  f0bf158:	3c012000 */ 	lui	$at,0x2000
/*  f0bf15c:	a20902e1 */ 	sb	$t1,0x2e1($s0)
/*  f0bf160:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f0bf164:	01817025 */ 	or	$t6,$t4,$at
/*  f0bf168:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*  f0bf16c:	ae0e0014 */ 	sw	$t6,0x14($s0)
/*  f0bf170:	a20a02e1 */ 	sb	$t2,0x2e1($s0)
/*  f0bf174:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf178:	24050101 */ 	addiu	$a1,$zero,0x101
/*  f0bf17c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f0bf180:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f0bf184:	00003825 */ 	or	$a3,$zero,$zero
.L0f0bf188:
/*  f0bf188:	0fc41b99 */ 	jal	cheatIsActive
/*  f0bf18c:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f0bf190:	10400062 */ 	beqz	$v0,.L0f0bf31c
/*  f0bf194:	00000000 */ 	nop
/*  f0bf198:	0fc59585 */ 	jal	stageGetIndex
/*  f0bf19c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf1a0:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0bf1a4:	14410012 */ 	bne	$v0,$at,.L0f0bf1f0
/*  f0bf1a8:	00000000 */ 	nop
/*  f0bf1ac:	0c006134 */ 	jal	ailistFindById
/*  f0bf1b0:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bf1b4:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf1b8:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f0bf1bc:	2404005b */ 	addiu	$a0,$zero,0x5b
/*  f0bf1c0:	c6120144 */ 	lwc1	$f18,0x144($s0)
/*  f0bf1c4:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf1c8:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0bf1cc:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0bf1d0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf1d4:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0bf1d8:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf1dc:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf1e0:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bf1e4:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bf1e8:	10000011 */ 	b	.L0f0bf230
/*  f0bf1ec:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bf1f0:
/*  f0bf1f0:	0c006134 */ 	jal	ailistFindById
/*  f0bf1f4:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bf1f8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf1fc:	240d0010 */ 	addiu	$t5,$zero,0x10
/*  f0bf200:	24040092 */ 	addiu	$a0,$zero,0x92
/*  f0bf204:	c60a0144 */ 	lwc1	$f10,0x144($s0)
/*  f0bf208:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf20c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0bf210:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0bf214:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf218:	02802825 */ 	or	$a1,$s4,$zero
/*  f0bf21c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf220:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf224:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bf228:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0bf22c:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bf230:
/*  f0bf230:	1040003a */ 	beqz	$v0,.L0f0bf31c
/*  f0bf234:	3c014030 */ 	lui	$at,0x4030
/*  f0bf238:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf23c:	240f0010 */ 	addiu	$t7,$zero,0x10
/*  f0bf240:	240b0064 */ 	addiu	$t3,$zero,0x64
/*  f0bf244:	8e190118 */ 	lw	$t9,0x118($s0)
/*  f0bf248:	8e0c0114 */ 	lw	$t4,0x114($s0)
/*  f0bf24c:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f0bf250:	0321c025 */ 	or	$t8,$t9,$at
/*  f0bf254:	3c018000 */ 	lui	$at,0x8000
/*  f0bf258:	240d0032 */ 	addiu	$t5,$zero,0x32
/*  f0bf25c:	358e2000 */ 	ori	$t6,$t4,0x2000
/*  f0bf260:	01215025 */ 	or	$t2,$t1,$at
/*  f0bf264:	ae0e0114 */ 	sw	$t6,0x114($s0)
/*  f0bf268:	ae180118 */ 	sw	$t8,0x118($s0)
/*  f0bf26c:	a20f0125 */ 	sb	$t7,0x125($s0)
/*  f0bf270:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf274:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f0bf278:	a20002b1 */ 	sb	$zero,0x2b1($s0)
/*  f0bf27c:	a20b02e2 */ 	sb	$t3,0x2e2($s0)
/*  f0bf280:	a20d0002 */ 	sb	$t5,0x2($s0)
/*  f0bf284:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf288:	0fc59585 */ 	jal	stageGetIndex
/*  f0bf28c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf290:	14540005 */ 	bne	$v0,$s4,.L0f0bf2a8
/*  f0bf294:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf298:	0fc0816b */ 	jal	chrAddHealth
/*  f0bf29c:	3c054220 */ 	lui	$a1,0x4220
/*  f0bf2a0:	10000005 */ 	b	.L0f0bf2b8
/*  f0bf2a4:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf2a8:
/*  f0bf2a8:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf2ac:	0fc0816b */ 	jal	chrAddHealth
/*  f0bf2b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf2b4:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf2b8:
/*  f0bf2b8:	0fc08166 */ 	jal	chrSetMaxDamage
/*  f0bf2bc:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf2c0:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f0bf2c4:	920902e1 */ 	lbu	$t1,0x2e1($s0)
/*  f0bf2c8:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f0bf2cc:	3c010004 */ 	lui	$at,0x4
/*  f0bf2d0:	01817025 */ 	or	$t6,$t4,$at
/*  f0bf2d4:	352b0001 */ 	ori	$t3,$t1,0x1
/*  f0bf2d8:	3c012000 */ 	lui	$at,0x2000
/*  f0bf2dc:	a20b02e1 */ 	sb	$t3,0x2e1($s0)
/*  f0bf2e0:	316d0001 */ 	andi	$t5,$t3,0x1
/*  f0bf2e4:	0321c025 */ 	or	$t8,$t9,$at
/*  f0bf2e8:	ae0e0018 */ 	sw	$t6,0x18($s0)
/*  f0bf2ec:	ae180014 */ 	sw	$t8,0x14($s0)
/*  f0bf2f0:	a20d02e1 */ 	sb	$t5,0x2e1($s0)
/*  f0bf2f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf2f8:	240500f9 */ 	addiu	$a1,$zero,0xf9
/*  f0bf2fc:	24060009 */ 	addiu	$a2,$zero,0x9
/*  f0bf300:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f0bf304:	00003825 */ 	or	$a3,$zero,$zero
/*  f0bf308:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf30c:	240500f8 */ 	addiu	$a1,$zero,0xf8
/*  f0bf310:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0bf314:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f0bf318:	3c071000 */ 	lui	$a3,0x1000
.L0f0bf31c:
/*  f0bf31c:	0fc41b99 */ 	jal	cheatIsActive
/*  f0bf320:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f0bf324:	5040005d */ 	beqzl	$v0,.L0f0bf49c
/*  f0bf328:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0bf32c:	0fc59585 */ 	jal	stageGetIndex
/*  f0bf330:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf334:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0bf338:	14410012 */ 	bne	$v0,$at,.L0f0bf384
/*  f0bf33c:	00000000 */ 	nop
/*  f0bf340:	0c006134 */ 	jal	ailistFindById
/*  f0bf344:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bf348:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf34c:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f0bf350:	2404005b */ 	addiu	$a0,$zero,0x5b
/*  f0bf354:	c6060144 */ 	lwc1	$f6,0x144($s0)
/*  f0bf358:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf35c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0bf360:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bf364:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf368:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0bf36c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf370:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf374:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bf378:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bf37c:	10000011 */ 	b	.L0f0bf3c4
/*  f0bf380:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bf384:
/*  f0bf384:	0c006134 */ 	jal	ailistFindById
/*  f0bf388:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f0bf38c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf390:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f0bf394:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f0bf398:	c6080144 */ 	lwc1	$f8,0x144($s0)
/*  f0bf39c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf3a0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0bf3a4:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bf3a8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf3ac:	24050029 */ 	addiu	$a1,$zero,0x29
/*  f0bf3b0:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf3b4:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf3b8:	0fc12cbd */ 	jal	chrSpawnAtCoord
/*  f0bf3bc:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bf3c0:	00408825 */ 	or	$s1,$v0,$zero
.L0f0bf3c4:
/*  f0bf3c4:	10400034 */ 	beqz	$v0,.L0f0bf498
/*  f0bf3c8:	3c01c030 */ 	lui	$at,0xc030
/*  f0bf3cc:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf3d0:	240a0010 */ 	addiu	$t2,$zero,0x10
/*  f0bf3d4:	240c0096 */ 	addiu	$t4,$zero,0x96
/*  f0bf3d8:	8e0f0118 */ 	lw	$t7,0x118($s0)
/*  f0bf3dc:	8e190114 */ 	lw	$t9,0x114($s0)
/*  f0bf3e0:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0bf3e4:	01e14825 */ 	or	$t1,$t7,$at
/*  f0bf3e8:	3c018000 */ 	lui	$at,0x8000
/*  f0bf3ec:	37382000 */ 	ori	$t8,$t9,0x2000
/*  f0bf3f0:	01616825 */ 	or	$t5,$t3,$at
/*  f0bf3f4:	ae180114 */ 	sw	$t8,0x114($s0)
/*  f0bf3f8:	ae090118 */ 	sw	$t1,0x118($s0)
/*  f0bf3fc:	a20a0125 */ 	sb	$t2,0x125($s0)
/*  f0bf400:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf404:	ae0d0014 */ 	sw	$t5,0x14($s0)
/*  f0bf408:	a20002b1 */ 	sb	$zero,0x2b1($s0)
/*  f0bf40c:	a20c02e2 */ 	sb	$t4,0x2e2($s0)
/*  f0bf410:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bf414:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf418:	0fc59585 */ 	jal	stageGetIndex
/*  f0bf41c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf420:	14540005 */ 	bne	$v0,$s4,.L0f0bf438
/*  f0bf424:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf428:	0fc0816b */ 	jal	chrAddHealth
/*  f0bf42c:	3c054220 */ 	lui	$a1,0x4220
/*  f0bf430:	10000005 */ 	b	.L0f0bf448
/*  f0bf434:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf438:
/*  f0bf438:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf43c:	0fc0816b */ 	jal	chrAddHealth
/*  f0bf440:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf444:	02002025 */ 	or	$a0,$s0,$zero
.L0f0bf448:
/*  f0bf448:	0fc08166 */ 	jal	chrSetMaxDamage
/*  f0bf44c:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf450:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0bf454:	920a02e1 */ 	lbu	$t2,0x2e1($s0)
/*  f0bf458:	8e180014 */ 	lw	$t8,0x14($s0)
/*  f0bf45c:	3c010004 */ 	lui	$at,0x4
/*  f0bf460:	01c1c825 */ 	or	$t9,$t6,$at
/*  f0bf464:	354d0001 */ 	ori	$t5,$t2,0x1
/*  f0bf468:	3c012000 */ 	lui	$at,0x2000
/*  f0bf46c:	a20d02e1 */ 	sb	$t5,0x2e1($s0)
/*  f0bf470:	31ac0001 */ 	andi	$t4,$t5,0x1
/*  f0bf474:	03017825 */ 	or	$t7,$t8,$at
/*  f0bf478:	ae190018 */ 	sw	$t9,0x18($s0)
/*  f0bf47c:	ae0f0014 */ 	sw	$t7,0x14($s0)
/*  f0bf480:	a20c02e1 */ 	sb	$t4,0x2e1($s0)
/*  f0bf484:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bf488:	24050104 */ 	addiu	$a1,$zero,0x104
/*  f0bf48c:	2406000d */ 	addiu	$a2,$zero,0xd
/*  f0bf490:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f0bf494:	00003825 */ 	or	$a3,$zero,$zero
.L0f0bf498:
/*  f0bf498:	8fae0058 */ 	lw	$t6,0x58($sp)
.L0f0bf49c:
/*  f0bf49c:	add104b8 */ 	sw	$s1,0x4b8($t6)
/*  f0bf4a0:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f0bf4a4:	8e6a0474 */ 	lw	$t2,0x474($s3)
/*  f0bf4a8:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0bf4ac:	27380001 */ 	addiu	$t8,$t9,0x1
/*  f0bf4b0:	030a082a */ 	slt	$at,$t8,$t2
/*  f0bf4b4:	25e90004 */ 	addiu	$t1,$t7,0x4
/*  f0bf4b8:	afa90058 */ 	sw	$t1,0x58($sp)
/*  f0bf4bc:	1420fdf8 */ 	bnez	$at,.L0f0beca0
/*  f0bf4c0:	afb800e8 */ 	sw	$t8,0xe8($sp)
.L0f0bf4c4:
/*  f0bf4c4:	1000011b */ 	b	.L0f0bf934
/*  f0bf4c8:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf4cc:
/*  f0bf4cc:	10600003 */ 	beqz	$v1,.L0f0bf4dc
/*  f0bf4d0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0bf4d4:	54610018 */ 	bnel	$v1,$at,.L0f0bf538
/*  f0bf4d8:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0bf4dc:
/*  f0bf4dc:	0fc2e54e */ 	jal	func0f0b9538
/*  f0bf4e0:	00000000 */ 	nop
/*  f0bf4e4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0bf4e8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0bf4ec:	8fa60330 */ 	lw	$a2,0x330($sp)
/*  f0bf4f0:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0bf4f4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0bf4f8:	0fc2f4f1 */ 	jal	func0f0bd3c4
/*  f0bf4fc:	00000000 */ 	nop
/*  f0bf500:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0bf504:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bf508:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf50c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf510:	2604037c */ 	addiu	$a0,$s0,0x37c
/*  f0bf514:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0bf518:	246b0028 */ 	addiu	$t3,$v1,0x28
/*  f0bf51c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0bf520:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0bf524:	0fc30610 */ 	jal	func0f0c1840
/*  f0bf528:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bf52c:	10000101 */ 	b	.L0f0bf934
/*  f0bf530:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf534:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0bf538:
/*  f0bf538:	1461000c */ 	bne	$v1,$at,.L0f0bf56c
/*  f0bf53c:	00000000 */ 	nop
/*  f0bf540:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0bf544:	00000000 */ 	nop
/*  f0bf548:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bf54c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bf550:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bf554:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0bf558:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0bf55c:	0fc2e5ba */ 	jal	func0f0b96e8
/*  f0bf560:	00000000 */ 	nop
/*  f0bf564:	100000f3 */ 	b	.L0f0bf934
/*  f0bf568:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf56c:
/*  f0bf56c:	1443000c */ 	bne	$v0,$v1,.L0f0bf5a0
/*  f0bf570:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0bf574:	0fc2e2e8 */ 	jal	func0f0b8ba0
/*  f0bf578:	00000000 */ 	nop
/*  f0bf57c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bf580:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bf584:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bf588:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0bf58c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0bf590:	0fc2e72f */ 	jal	func0f0b9cbc
/*  f0bf594:	00000000 */ 	nop
/*  f0bf598:	100000e6 */ 	b	.L0f0bf934
/*  f0bf59c:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf5a0:
/*  f0bf5a0:	546100e5 */ 	bnel	$v1,$at,.L0f0bf938
/*  f0bf5a4:	c60a1b80 */ 	lwc1	$f10,0x1b80($s0)
/*  f0bf5a8:	0fc2e54e */ 	jal	func0f0b9538
/*  f0bf5ac:	00000000 */ 	nop
/*  f0bf5b0:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f0bf5b4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0bf5b8:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0bf5bc:	0fc456ac */ 	jal	padUnpack
/*  f0bf5c0:	85a41ba4 */ 	lh	$a0,0x1ba4($t5)
/*  f0bf5c4:	0c003a61 */ 	jal	mainGetStageNum
/*  f0bf5c8:	00000000 */ 	nop
/*  f0bf5cc:	3c0c8008 */ 	lui	$t4,%hi(g_Stages+0x310)
/*  f0bf5d0:	858cffd0 */ 	lh	$t4,%lo(g_Stages+0x310)($t4)
/*  f0bf5d4:	544c000c */ 	bnel	$v0,$t4,.L0f0bf608
/*  f0bf5d8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf5dc:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f0bf5e0:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0bf5e4:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0bf5e8:	85d91ba4 */ 	lh	$t9,0x1ba4($t6)
/*  f0bf5ec:	17210005 */ 	bne	$t9,$at,.L0f0bf604
/*  f0bf5f0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0bf5f4:	44813000 */ 	mtc1	$at,$f6
/*  f0bf5f8:	00000000 */ 	nop
/*  f0bf5fc:	46062481 */ 	sub.s	$f18,$f4,$f6
/*  f0bf600:	e7b20078 */ 	swc1	$f18,0x78($sp)
.L0f0bf604:
/*  f0bf604:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf608:
/*  f0bf608:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0bf60c:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0bf610:	c60a037c */ 	lwc1	$f10,0x37c($s0)
/*  f0bf614:	c6060384 */ 	lwc1	$f6,0x384($s0)
/*  f0bf618:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f0bf61c:	46062381 */ 	sub.s	$f14,$f4,$f6
/*  f0bf620:	e7ac00d8 */ 	swc1	$f12,0xd8($sp)
/*  f0bf624:	0fc259d4 */ 	jal	func0f096750
/*  f0bf628:	e7ae00d4 */ 	swc1	$f14,0xd4($sp)
/*  f0bf62c:	3c017f1b */ 	lui	$at,%hi(var7f1ad694)
/*  f0bf630:	c436d694 */ 	lwc1	$f22,%lo(var7f1ad694)($at)
/*  f0bf634:	44809000 */ 	mtc1	$zero,$f18
/*  f0bf638:	46000506 */ 	mov.s	$f20,$f0
/*  f0bf63c:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0bf640:	00000000 */ 	nop
/*  f0bf644:	45020003 */ 	bc1fl	.L0f0bf654
/*  f0bf648:	4612a03c */ 	c.lt.s	$f20,$f18
/*  f0bf64c:	46160501 */ 	sub.s	$f20,$f0,$f22
/*  f0bf650:	4612a03c */ 	c.lt.s	$f20,$f18
.L0f0bf654:
/*  f0bf654:	00000000 */ 	nop
/*  f0bf658:	45020003 */ 	bc1fl	.L0f0bf668
/*  f0bf65c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf660:	4616a500 */ 	add.s	$f20,$f20,$f22
/*  f0bf664:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf668:
/*  f0bf668:	c60c036c */ 	lwc1	$f12,0x36c($s0)
/*  f0bf66c:	0fc259d4 */ 	jal	func0f096750
/*  f0bf670:	c60e0374 */ 	lwc1	$f14,0x374($s0)
/*  f0bf674:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0bf678:	44804000 */ 	mtc1	$zero,$f8
/*  f0bf67c:	46000086 */ 	mov.s	$f2,$f0
/*  f0bf680:	3c017f1b */ 	lui	$at,%hi(var7f1ad698)
/*  f0bf684:	45020003 */ 	bc1fl	.L0f0bf694
/*  f0bf688:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0bf68c:	46160081 */ 	sub.s	$f2,$f0,$f22
/*  f0bf690:	4608103c */ 	c.lt.s	$f2,$f8
.L0f0bf694:
/*  f0bf694:	00000000 */ 	nop
/*  f0bf698:	45020003 */ 	bc1fl	.L0f0bf6a8
/*  f0bf69c:	46141301 */ 	sub.s	$f12,$f2,$f20
/*  f0bf6a0:	46161080 */ 	add.s	$f2,$f2,$f22
/*  f0bf6a4:	46141301 */ 	sub.s	$f12,$f2,$f20
.L0f0bf6a8:
/*  f0bf6a8:	c42ed698 */ 	lwc1	$f14,%lo(var7f1ad698)($at)
/*  f0bf6ac:	3c017f1b */ 	lui	$at,%hi(var7f1ad69c)
/*  f0bf6b0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0bf6b4:	46006006 */ 	mov.s	$f0,$f12
/*  f0bf6b8:	45000002 */ 	bc1f	.L0f0bf6c4
/*  f0bf6bc:	00000000 */ 	nop
/*  f0bf6c0:	46166001 */ 	sub.s	$f0,$f12,$f22
.L0f0bf6c4:
/*  f0bf6c4:	c42ad69c */ 	lwc1	$f10,%lo(var7f1ad69c)($at)
/*  f0bf6c8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0bf6cc:	00000000 */ 	nop
/*  f0bf6d0:	45020003 */ 	bc1fl	.L0f0bf6e0
/*  f0bf6d4:	460e0103 */ 	div.s	$f4,$f0,$f14
/*  f0bf6d8:	46160000 */ 	add.s	$f0,$f0,$f22
/*  f0bf6dc:	460e0103 */ 	div.s	$f4,$f0,$f14
.L0f0bf6e0:
/*  f0bf6e0:	44803000 */ 	mtc1	$zero,$f6
/*  f0bf6e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bf6e8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0bf6ec:	00000000 */ 	nop
/*  f0bf6f0:	45020006 */ 	bc1fl	.L0f0bf70c
/*  f0bf6f4:	44811000 */ 	mtc1	$at,$f2
/*  f0bf6f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bf6fc:	44811000 */ 	mtc1	$at,$f2
/*  f0bf700:	10000004 */ 	b	.L0f0bf714
/*  f0bf704:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf708:	44811000 */ 	mtc1	$at,$f2
.L0f0bf70c:
/*  f0bf70c:	00000000 */ 	nop
/*  f0bf710:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf714:
/*  f0bf714:	3c017f1b */ 	lui	$at,%hi(var7f1ad6a0)
/*  f0bf718:	8e0f1bac */ 	lw	$t7,0x1bac($s0)
/*  f0bf71c:	448f9000 */ 	mtc1	$t7,$f18
/*  f0bf720:	00000000 */ 	nop
/*  f0bf724:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0bf728:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0bf72c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0bf730:	44182000 */ 	mfc1	$t8,$f4
/*  f0bf734:	00000000 */ 	nop
/*  f0bf738:	ae181bd8 */ 	sw	$t8,0x1bd8($s0)
/*  f0bf73c:	c426d6a0 */ 	lwc1	$f6,%lo(var7f1ad6a0)($at)
/*  f0bf740:	3c017f1b */ 	lui	$at,%hi(var7f1ad6a4)
/*  f0bf744:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0bf748:	00000000 */ 	nop
/*  f0bf74c:	4503000e */ 	bc1tl	.L0f0bf788
/*  f0bf750:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf754:	c432d6a4 */ 	lwc1	$f18,%lo(var7f1ad6a4)($at)
/*  f0bf758:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0bf75c:	00000000 */ 	nop
/*  f0bf760:	45030009 */ 	bc1tl	.L0f0bf788
/*  f0bf764:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf768:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0bf76c:	ad401bd8 */ 	sw	$zero,0x1bd8($t2)
/*  f0bf770:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf774:	860b1baa */ 	lh	$t3,0x1baa($s0)
/*  f0bf778:	55600003 */ 	bnezl	$t3,.L0f0bf788
/*  f0bf77c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf780:	ae001bac */ 	sw	$zero,0x1bac($s0)
/*  f0bf784:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf788:
/*  f0bf788:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0bf78c:	44814000 */ 	mtc1	$at,$f8
/*  f0bf790:	c6020154 */ 	lwc1	$f2,0x154($s0)
/*  f0bf794:	4608103e */ 	c.le.s	$f2,$f8
/*  f0bf798:	00000000 */ 	nop
/*  f0bf79c:	4502000d */ 	bc1fl	.L0f0bf7d4
/*  f0bf7a0:	86021baa */ 	lh	$v0,0x1baa($s0)
/*  f0bf7a4:	860d1ba6 */ 	lh	$t5,0x1ba6($s0)
/*  f0bf7a8:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0bf7ac:	44813000 */ 	mtc1	$at,$f6
/*  f0bf7b0:	448d5000 */ 	mtc1	$t5,$f10
/*  f0bf7b4:	00000000 */ 	nop
/*  f0bf7b8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0bf7bc:	46062483 */ 	div.s	$f18,$f4,$f6
/*  f0bf7c0:	46169202 */ 	mul.s	$f8,$f18,$f22
/*  f0bf7c4:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0bf7c8:	e60a0154 */ 	swc1	$f10,0x154($s0)
/*  f0bf7cc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf7d0:	86021baa */ 	lh	$v0,0x1baa($s0)
.L0f0bf7d4:
/*  f0bf7d4:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f0bf7d8:	3c017f1b */ 	lui	$at,%hi(var7f1ad6a8)
/*  f0bf7dc:	10400015 */ 	beqz	$v0,.L0f0bf834
/*  f0bf7e0:	00000000 */ 	nop
/*  f0bf7e4:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0bf7e8:	c7a000d4 */ 	lwc1	$f0,0xd4($sp)
/*  f0bf7ec:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0bf7f0:	0c012974 */ 	jal	sqrtf
/*  f0bf7f4:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f0bf7f8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf7fc:	e7a000d8 */ 	swc1	$f0,0xd8($sp)
/*  f0bf800:	860c1ba8 */ 	lh	$t4,0x1ba8($s0)
/*  f0bf804:	448c4000 */ 	mtc1	$t4,$f8
/*  f0bf808:	00000000 */ 	nop
/*  f0bf80c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0bf810:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0bf814:	00000000 */ 	nop
/*  f0bf818:	45000004 */ 	bc1f	.L0f0bf82c
/*  f0bf81c:	00000000 */ 	nop
/*  f0bf820:	0fc2e58f */ 	jal	setTickMode
/*  f0bf824:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0bf828:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf82c:
/*  f0bf82c:	10000010 */ 	b	.L0f0bf870
/*  f0bf830:	86021baa */ 	lh	$v0,0x1baa($s0)
.L0f0bf834:
/*  f0bf834:	c424d6a8 */ 	lwc1	$f4,%lo(var7f1ad6a8)($at)
/*  f0bf838:	3c017f1b */ 	lui	$at,%hi(var7f1ad6ac)
/*  f0bf83c:	4600203e */ 	c.le.s	$f4,$f0
/*  f0bf840:	00000000 */ 	nop
/*  f0bf844:	4502000b */ 	bc1fl	.L0f0bf874
/*  f0bf848:	860e1ba8 */ 	lh	$t6,0x1ba8($s0)
/*  f0bf84c:	c426d6ac */ 	lwc1	$f6,%lo(var7f1ad6ac)($at)
/*  f0bf850:	4606003e */ 	c.le.s	$f0,$f6
/*  f0bf854:	00000000 */ 	nop
/*  f0bf858:	45020006 */ 	bc1fl	.L0f0bf874
/*  f0bf85c:	860e1ba8 */ 	lh	$t6,0x1ba8($s0)
/*  f0bf860:	0fc2e58f */ 	jal	setTickMode
/*  f0bf864:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0bf868:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf86c:	86021baa */ 	lh	$v0,0x1baa($s0)
.L0f0bf870:
/*  f0bf870:	860e1ba8 */ 	lh	$t6,0x1ba8($s0)
.L0f0bf874:
/*  f0bf874:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f0bf878:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bf87c:	448e9000 */ 	mtc1	$t6,$f18
/*  f0bf880:	44811000 */ 	mtc1	$at,$f2
/*  f0bf884:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0bf888:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0bf88c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0bf890:	00000000 */ 	nop
/*  f0bf894:	4502000f */ 	bc1fl	.L0f0bf8d4
/*  f0bf898:	44824000 */ 	mtc1	$v0,$f8
/*  f0bf89c:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0bf8a0:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f0bf8a4:	45020005 */ 	bc1fl	.L0f0bf8bc
/*  f0bf8a8:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0bf8ac:	44801000 */ 	mtc1	$zero,$f2
/*  f0bf8b0:	10000008 */ 	b	.L0f0bf8d4
/*  f0bf8b4:	44824000 */ 	mtc1	$v0,$f8
/*  f0bf8b8:	46002181 */ 	sub.s	$f6,$f4,$f0
.L0f0bf8bc:
/*  f0bf8bc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0bf8c0:	44816000 */ 	mtc1	$at,$f12
/*  f0bf8c4:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f0bf8c8:	460c9282 */ 	mul.s	$f10,$f18,$f12
/*  f0bf8cc:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f0bf8d0:	44824000 */ 	mtc1	$v0,$f8
.L0f0bf8d4:
/*  f0bf8d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0bf8d8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0bf8dc:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0bf8e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bf8e4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0bf8e8:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0bf8ec:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0bf8f0:	440f9000 */ 	mfc1	$t7,$f18
/*  f0bf8f4:	0fc32f16 */ 	jal	currentPlayerUpdateFootsteps
/*  f0bf8f8:	ae0f1bdc */ 	sw	$t7,0x1bdc($s0)
/*  f0bf8fc:	0fc2f4f1 */ 	jal	func0f0bd3c4
/*  f0bf900:	00000000 */ 	nop
/*  f0bf904:	0fc3060c */ 	jal	currentPlayerSetCameraMode
/*  f0bf908:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bf90c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf910:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bf914:	2604037c */ 	addiu	$a0,$s0,0x37c
/*  f0bf918:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0bf91c:	24690028 */ 	addiu	$t1,$v1,0x28
/*  f0bf920:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0bf924:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0bf928:	0fc30610 */ 	jal	func0f0c1840
/*  f0bf92c:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bf930:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bf934:
/*  f0bf934:	c60a1b80 */ 	lwc1	$f10,0x1b80($s0)
.L0f0bf938:
/*  f0bf938:	c6680010 */ 	lwc1	$f8,0x10($s3)
/*  f0bf93c:	3c118007 */ 	lui	$s1,%hi(var8007074c)
/*  f0bf940:	2631074c */ 	addiu	$s1,$s1,%lo(var8007074c)
/*  f0bf944:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0bf948:	e6041b80 */ 	swc1	$f4,0x1b80($s0)
/*  f0bf94c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0bf950:	13000047 */ 	beqz	$t8,.L0f0bfa70
/*  f0bf954:	00000000 */ 	nop
/*  f0bf958:	8e6a0288 */ 	lw	$t2,0x288($s3)
/*  f0bf95c:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0bf960:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0bf964:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0bf968:	00105e03 */ 	sra	$t3,$s0,0x18
/*  f0bf96c:	0fc5b364 */ 	jal	soloIsPaused
/*  f0bf970:	01608025 */ 	or	$s0,$t3,$zero
/*  f0bf974:	1440002c */ 	bnez	$v0,.L0f0bfa28
/*  f0bf978:	8fad0330 */ 	lw	$t5,0x330($sp)
/*  f0bf97c:	11a0002a */ 	beqz	$t5,.L0f0bfa28
/*  f0bf980:	00102600 */ 	sll	$a0,$s0,0x18
/*  f0bf984:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0bf988:	01802025 */ 	or	$a0,$t4,$zero
/*  f0bf98c:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f0bf990:	3405f030 */ 	dli	$a1,0xf030
/*  f0bf994:	10400024 */ 	beqz	$v0,.L0f0bfa28
/*  f0bf998:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0bf99c:	0fc2ecff */ 	jal	currentPlayerIsFadeComplete
/*  f0bf9a0:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0bf9a4:	50400016 */ 	beqzl	$v0,.L0f0bfa00
/*  f0bf9a8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf9ac:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0bf9b0:	44800000 */ 	mtc1	$zero,$f0
/*  f0bf9b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bf9b8:	c72602e4 */ 	lwc1	$f6,0x2e4($t9)
/*  f0bf9bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bf9c0:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0bf9c4:	00000000 */ 	nop
/*  f0bf9c8:	45020018 */ 	bc1fl	.L0f0bfa2c
/*  f0bf9cc:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bf9d0:	44070000 */ 	mfc1	$a3,$f0
/*  f0bf9d4:	0fc2ecc8 */ 	jal	currentPlayerSetFadeColour
/*  f0bf9d8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0bf9dc:	3c014270 */ 	lui	$at,0x4270
/*  f0bf9e0:	44816000 */ 	mtc1	$at,$f12
/*  f0bf9e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bf9e8:	44817000 */ 	mtc1	$at,$f14
/*  f0bf9ec:	0fc2ecf2 */ 	jal	currentPlayerSetFadeFrac
/*  f0bf9f0:	00000000 */ 	nop
/*  f0bf9f4:	1000000d */ 	b	.L0f0bfa2c
/*  f0bf9f8:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bf9fc:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bfa00:
/*  f0bfa00:	44809000 */ 	mtc1	$zero,$f18
/*  f0bfa04:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfa08:	c60a030c */ 	lwc1	$f10,0x30c($s0)
/*  f0bfa0c:	460a9032 */ 	c.eq.s	$f18,$f10
/*  f0bfa10:	00000000 */ 	nop
/*  f0bfa14:	45020005 */ 	bc1fl	.L0f0bfa2c
/*  f0bfa18:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bfa1c:	44817000 */ 	mtc1	$at,$f14
/*  f0bfa20:	0fc2ecf2 */ 	jal	currentPlayerSetFadeFrac
/*  f0bfa24:	c60c02e8 */ 	lwc1	$f12,0x2e8($s0)
.L0f0bfa28:
/*  f0bfa28:	8e2f0000 */ 	lw	$t7,0x0($s1)
.L0f0bfa2c:
/*  f0bfa2c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bfa30:	15e1000f */ 	bne	$t7,$at,.L0f0bfa70
/*  f0bfa34:	00000000 */ 	nop
/*  f0bfa38:	0fc2ecff */ 	jal	currentPlayerIsFadeComplete
/*  f0bfa3c:	00000000 */ 	nop
/*  f0bfa40:	1040000b */ 	beqz	$v0,.L0f0bfa70
/*  f0bfa44:	00000000 */ 	nop
/*  f0bfa48:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0bfa4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfa50:	44814000 */ 	mtc1	$at,$f8
/*  f0bfa54:	c52402e4 */ 	lwc1	$f4,0x2e4($t1)
/*  f0bfa58:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0bfa5c:	00000000 */ 	nop
/*  f0bfa60:	45000003 */ 	bc1f	.L0f0bfa70
/*  f0bfa64:	00000000 */ 	nop
/*  f0bfa68:	0c003a64 */ 	jal	func0000e990
/*  f0bfa6c:	00000000 */ 	nop
.L0f0bfa70:
/*  f0bfa70:	3c188007 */ 	lui	$t8,%hi(var80070744)
/*  f0bfa74:	8f180744 */ 	lw	$t8,%lo(var80070744)($t8)
/*  f0bfa78:	53000004 */ 	beqzl	$t8,.L0f0bfa8c
/*  f0bfa7c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bfa80:	0fc2e594 */ 	jal	func0f0b9650
/*  f0bfa84:	00000000 */ 	nop
/*  f0bfa88:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f0bfa8c:
/*  f0bfa8c:	8e0a00d8 */ 	lw	$t2,0xd8($s0)
/*  f0bfa90:	51400035 */ 	beqzl	$t2,.L0f0bfb68
/*  f0bfa94:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfa98:	8e02032c */ 	lw	$v0,0x32c($s0)
/*  f0bfa9c:	14400005 */ 	bnez	$v0,.L0f0bfab4
/*  f0bfaa0:	00000000 */ 	nop
/*  f0bfaa4:	0fc28a72 */ 	jal	func0f0a29c8
/*  f0bfaa8:	00000000 */ 	nop
/*  f0bfaac:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bfab0:	8e02032c */ 	lw	$v0,0x32c($s0)
.L0f0bfab4:
/*  f0bfab4:	5040002c */ 	beqzl	$v0,.L0f0bfb68
/*  f0bfab8:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfabc:	8e0b0330 */ 	lw	$t3,0x330($s0)
/*  f0bfac0:	51600029 */ 	beqzl	$t3,.L0f0bfb68
/*  f0bfac4:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfac8:	8e6d0314 */ 	lw	$t5,0x314($s3)
/*  f0bfacc:	55a00006 */ 	bnezl	$t5,.L0f0bfae8
/*  f0bfad0:	8e6c0298 */ 	lw	$t4,0x298($s3)
/*  f0bfad4:	0c0039a1 */ 	jal	mainEndStage
/*  f0bfad8:	00000000 */ 	nop
/*  f0bfadc:	10000022 */ 	b	.L0f0bfb68
/*  f0bfae0:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfae4:	8e6c0298 */ 	lw	$t4,0x298($s3)
.L0f0bfae8:
/*  f0bfae8:	05820017 */ 	bltzl	$t4,.L0f0bfb48
/*  f0bfaec:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f0bfaf0:	8e6e02a0 */ 	lw	$t6,0x2a0($s3)
/*  f0bfaf4:	15d0000f */ 	bne	$t6,$s0,.L0f0bfb34
/*  f0bfaf8:	00000000 */ 	nop
/*  f0bfafc:	8e6202a4 */ 	lw	$v0,0x2a4($s3)
/*  f0bfb00:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f0bfb04:	1320000b */ 	beqz	$t9,.L0f0bfb34
/*  f0bfb08:	00000000 */ 	nop
/*  f0bfb0c:	8c4f032c */ 	lw	$t7,0x32c($v0)
/*  f0bfb10:	11e00008 */ 	beqz	$t7,.L0f0bfb34
/*  f0bfb14:	00000000 */ 	nop
/*  f0bfb18:	8c490330 */ 	lw	$t1,0x330($v0)
/*  f0bfb1c:	11200005 */ 	beqz	$t1,.L0f0bfb34
/*  f0bfb20:	00000000 */ 	nop
/*  f0bfb24:	0c0039a1 */ 	jal	mainEndStage
/*  f0bfb28:	00000000 */ 	nop
/*  f0bfb2c:	1000000e */ 	b	.L0f0bfb68
/*  f0bfb30:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
.L0f0bfb34:
/*  f0bfb34:	0fc12591 */ 	jal	func0f049644
/*  f0bfb38:	8e64028c */ 	lw	$a0,0x28c($s3)
/*  f0bfb3c:	1000000a */ 	b	.L0f0bfb68
/*  f0bfb40:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfb44:	8e78029c */ 	lw	$t8,0x29c($s3)
.L0f0bfb48:
/*  f0bfb48:	07020007 */ 	bltzl	$t8,.L0f0bfb68
/*  f0bfb4c:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfb50:	8e6a02a0 */ 	lw	$t2,0x2a0($s3)
/*  f0bfb54:	55500004 */ 	bnel	$t2,$s0,.L0f0bfb68
/*  f0bfb58:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f0bfb5c:	0c0039a1 */ 	jal	mainEndStage
/*  f0bfb60:	00000000 */ 	nop
/*  f0bfb64:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
.L0f0bfb68:
/*  f0bfb68:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0bfb6c:	55610008 */ 	bnel	$t3,$at,.L0f0bfb90
/*  f0bfb70:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0bfb74:	0fc2ecff */ 	jal	currentPlayerIsFadeComplete
/*  f0bfb78:	00000000 */ 	nop
/*  f0bfb7c:	50400004 */ 	beqzl	$v0,.L0f0bfb90
/*  f0bfb80:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0bfb84:	0c0039a1 */ 	jal	mainEndStage
/*  f0bfb88:	00000000 */ 	nop
/*  f0bfb8c:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0bfb90:
/*  f0bfb90:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0bfb94:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0bfb98:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0bfb9c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0bfba0:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0bfba4:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0bfba8:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0bfbac:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0bfbb0:	03e00008 */ 	jr	$ra
/*  f0bfbb4:	27bd0330 */ 	addiu	$sp,$sp,0x330
);

//void func0f0bd904(bool param_1)
//{
//	f32 aspectratio;
//
//	g_HiResActive = g_HiResEnabled;
//
//	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && PLAYERCOUNT() > 1) {
//		g_HiResActive = false;
//	}
//
//	// d9dc
//	if (g_HiResActive == true) {
//		func0f1531dc(true);
//	} else {
//		func0f1531dc(false);
//	}
//
//	// da00
//	if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
//		aspectratio = func0f0bd358() * 1.3333f;
//	} else {
//		aspectratio = func0f0bd358();
//	}
//
//	// da3c
//	func0000db30("tps", &var8007083c); // var7f1ad524
//
//	if (var8007083c != TELEPORTSTATE_0) {
//		var8007083c = TELEPORTSTATE_0;
//		g_Vars.currentplayer->teleporttime = 0;
//		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_STARTING;
//	}
//
//	// da7c
//	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_0) {
//		func0f0bd4e4(&aspectratio);
//	}
//
//	// da98
//	if (g_Vars.stagenum == STAGE_TEST_OLD && func0f01ad5c()) {
//		func0f01adb8();
//		return;
//	}
//
//	// dac8
//	currentPlayerSetFovY(60);
//	currentPlayerSetAspectRatio(aspectratio);
//	currentPlayerSetViewSize(func0f0bc554(), func0f0bcaa0());
//	currentPlayerSetViewPosition(func0f0bc7ac(), func0f0bce24());
//
//	// db44
//	func0000aab0(var800705c0[g_HiResActive].unk10);
//	viSetFovAspectAndSize(60, aspectratio, func0f0bc554(), func0f0bcaa0());
//	viSetViewPosition(func0f0bc7ac(), func0f0bce24());
//	viSetXY(func0f0bc44c(), func0f0bc478());
//	viSetBuf(func0f0bc44c(), func0f0bc478());
//	func0f0bb42c();
//	currentPlayerTickChrFade();
//	currentPlayerSetAutoAimY(optionsGetAutoAim(g_Vars.currentplayerstats->mpindex));
//	currentPlayerSetAutoAimX(optionsGetAutoAim(g_Vars.currentplayerstats->mpindex));
//	currentPlayerSetAutoMoveCentreEnabled(optionsGetLookAhead(g_Vars.currentplayerstats->mpindex));
//	func0f0a95ec(1, optionsGetAmmoOnScreen(g_Vars.currentplayerstats->mpindex));
//	currentPlayerSetGunSightVisible(GUNSIGHTREASON_1, true);
//
//	// dc9c
//	if ((g_Vars.tickmode == TICKMODE_0 || g_Vars.tickmode == TICKMODE_1)
//			&& var80070764 == 0
//			&& var8005d9d0 == 0) {
//		g_Vars.currentplayer->bondviewlevtime60 += g_Vars.lvupdate240_60;
//	}
//
//	// dcdc
//	if (g_Vars.currentplayer->itemswitch & 0x20) {
//		// Suicide pill?
//		currentPlayerDieByShooter(g_Vars.currentplayernum, true);
//	}
//
//	// dcfc
//	func0f0bb814();
//	func0f0bc120();
//
//	// dd14
//	if (g_Vars.currentplayer->eyespy) {
//		struct eyespy *eyespy = g_Vars.currentplayer->eyespy;
//		u32 playernum = g_Vars.currentplayernum;
//
//		// dd28
//		if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
//			struct chrdata *chr = eyespy->prop->chr;
//			eyespy->initialised = false;
//			eyespy->init = true;
//			eyespy->active = false;
//			func0f0926bc(eyespy->prop, 1, 0xffff);
//			chr->chrflags |= CHRCFLAG_HIDDEN;
//			chr->chrflags |= CHRCFLAG_INVINCIBLE_TO_GUNFIRE;
//			g_Vars.currentplayer->itemswitch &= ~0x00000004;
//		} else {
//			// dd7c
//			if (eyespy->init == false) {
//				// dd8c
//				if (eyespy->active) {
//					s8 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//					u16 buttons = param_1 ? contGetButtons(contpad1, 0xffff) : 0;
//
//					if (g_Vars.currentplayer->isdead == false
//							&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED
//							&& (buttons & START_BUTTON)) {
//						if (g_Vars.mplayerisrunning == false) {
//							currentPlayerPause(PAUSEMODE_2);
//						} else {
//							mpPushPauseDialog();
//						}
//					}
//				}
//
//				// de18
//				if (g_Vars.lvupdate240) {
//					func0f0d0928(param_1);
//				}
//			} else {
//				// de34
//				if ((g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->joybutinhibit & 4)
//						&& g_PlayersWithControl[playernum]
//						&& func0f0d0310() == 0) {
//					eyespy->init = true;
//					eyespy->active = false;
//					g_Vars.currentplayer->itemswitch &= ~0x00000004;
//				}
//			}
//
//			// de90
//			if (eyespy->initialised
//					&& g_PlayersWithControl[playernum]
//					&& (g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->joybutinhibit & 4)) {
//				// ded8
//				if (eyespy->active == false) {
//					eyespy->buttonheld = eyespy->camerabuttonheld = false;
//					eyespy->active = true;
//					eyespy->camerashuttertime = 0;
//					eyespy->startuptimer60 = 0;
//					eyespy->prop->chr->soundtimer = 10;
//					audioStart(var80095200, 0x80ab, NULL, -1, -1, -1, -1, -1);
//				}
//
//				g_Vars.currentplayer->invdowntime = -40;
//			}
//		}
//	}
//
//	// df48
//	if (soloIsPaused()) {
//		func0f0bace0();
//	}
//
//	// df64
//	if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
//		func0f0bad6c();
//	}
//
//	// df80
//	if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
//		if (g_Vars.currentplayer->slayerrocket == NULL || g_Vars.currentplayer->isdead) {
//			g_Vars.currentplayer->slayerrocket = NULL;
//			g_Vars.currentplayer->visionmode = VISIONMODE_3;
//		}
//	}
//
//	// dfb8
//	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
//		var80070764 = 0;
//	}
//
//	// dfc8
//	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
//		s32 i;
//
//		func0f0b8ba0();
//
//		// dfdc
//		if (g_Vars.currentplayer->haschrbody) {
//			g_Vars.currentplayer->invdowntime = -40;
//			currentPlayerUpdateFootsteps(0, 0, 0, 1);
//			func0f0ba29c(param_1);
//			g_Vars.currentplayer->invdowntime = -40;
//		}
//
//		// e018
//		for (i = 0; i < PLAYERCOUNT(); i++) {
//			g_Vars.players[i]->joybutinhibit = 0xffffffff;
//		}
//	} else {
//		// e120
//		if (g_Vars.currentplayer->eyespy
//				&& (g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->joybutinhibit & 4)
//				&& g_Vars.currentplayer->eyespy->active) {
//			struct coord sp776;
//			currentPlayerSetFovY(120);
//			viSetFovY(120);
//			sp776.x = g_Vars.currentplayer->eyespy->prop->pos.x;
//			sp776.y = g_Vars.currentplayer->eyespy->prop->pos.y;
//			sp776.z = g_Vars.currentplayer->eyespy->prop->pos.z;
//			func0f0b8ba0();
//			currentPlayerUpdateFootsteps(0, 0, 0, 1);
//			currentPlayerSetCameraMode(CAMERAMODE_EYESPY);
//			func0f0c1bd8(&sp776, &g_Vars.currentplayer->eyespy->up, &g_Vars.currentplayer->eyespy->look);
//		} else {
//			// e1e4
//			if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_3) {
//				func0f0b8ba0();
//				g_WarpPadId = g_Vars.currentplayer->teleportcamerapad;
//				currentPlayerUpdateFootsteps(0, 0, 0, 1);
//				func0f0b9cbc();
//			} else {
//				// e230
//				if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
//					struct coord sp764 = {0, 0, 0};
//					struct coord sp752 = {0, 0, 1};
//					struct coord sp740 = {0, 1, 0};
//
//					bool sp736 = false;
//					struct weaponobj *rocket = g_Vars.currentplayer->slayerrocket;
//
//					// e2ac
//					currentPlayerSetCameraMode(CAMERAMODE_THIRDPERSON);
//					func0f0b8ba0();
//					currentPlayerUpdateFootsteps(0, 0, 0, 1);
//					func0f0bd3c4();
//
//					// e2d8
//					if (rocket && rocket->base.prop) {
//						f32 sp696[9];
//						f32 sp680 = sqrtf(
//								rocket->base.realrot[6] * rocket->base.realrot[6] +
//								rocket->base.realrot[0] * rocket->base.realrot[0] +
//								rocket->base.realrot[3] * rocket->base.realrot[3]);
//						s16 rooms[8];
//						s16 sp590[8];
//
//						sp696[0] = rocket->base.realrot[0] / sp680;
//						sp696[1] = rocket->base.realrot[1] / sp680;
//						sp696[2] = rocket->base.realrot[2] / sp680;
//						sp696[3] = rocket->base.realrot[3] / sp680;
//						sp696[4] = rocket->base.realrot[4] / sp680;
//						sp696[5] = rocket->base.realrot[5] / sp680;
//						sp696[6] = rocket->base.realrot[6] / sp680;
//						sp696[7] = rocket->base.realrot[7] / sp680;
//						sp696[8] = rocket->base.realrot[8] / sp680;
//
//						sp764.x = rocket->base.prop->pos.x;
//						sp764.y = rocket->base.prop->pos.y;
//						sp764.z = rocket->base.prop->pos.z;
//
//						// e3c0
//						func0f162194(&sp764, rooms, &sp590[1], 20, &sp590[0]);
//
//						if (rooms[0] == -1) {
//							// Slayer rocket has flown out of bounds
//							// Allow 2 seconds of this, then blow up rocket
//							g_Vars.currentplayer->badrockettime += g_Vars.lvupdate240_60;
//
//							if (g_Vars.currentplayer->badrockettime > 120) {
//								g_Vars.currentplayer->visionmode = VISIONMODE_3;
//							}
//						} else if (g_Vars.currentplayer->badrockettime > 0) {
//							// Slayer rocket is in bounds, but was recently out
//							g_Vars.currentplayer->badrockettime -= g_Vars.lvupdate240_60;
//
//							if (g_Vars.currentplayer->badrockettime < 0) {
//								g_Vars.currentplayer->badrockettime = 0;
//							}
//						}
//
//						// e44c
//						func00016208(sp696, &sp752);
//						func00016208(sp696, &sp740);
//
//						if (rocket->base.hidden & OBJHFLAG_00000080) {
//							// e470
//							struct obj48 *obj48 = rocket->base.unk48;
//							u32 mode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);
//							s8 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//							s8 contpad2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex);
//
//							u8 cStack243 = 0;
//							u8 cStack244 = 0;
//							f32 fVar22;
//							f32 fVar20;
//							struct coord sp684;
//							f32 sp508[9];
//							f32 sp444[9];
//							f32 sp380[4];
//							f32 sp372;
//							f32 sp348[6];
//							f32 sp332[4];
//							f32 sp316[4];
//							f32 sp300[4];
//							f32 sp284[4];
//							bool explode = false; // sp280
//							bool slow = false; // sp276
//							bool pause = false; // sp272
//							f32 targetspeed;
//							f32 prevspeed;
//							f32 newspeed;
//
//							if (mode == CONTROLMODE_23
//									|| mode == CONTROLMODE_24
//									|| mode == CONTROLMODE_22
//									|| mode == CONTROLMODE_21) {
//								if (g_PlayersWithControl[g_Vars.currentplayernum]) {
//									if (mode == CONTROLMODE_21 || mode == CONTROLMODE_22) {
//										// e52c
//										if (contGetButtons(contpad1, A_BUTTON | B_BUTTON)
//												|| contGetButtons(contpad2, A_BUTTON | B_BUTTON)
//												|| contGetButtons(contpad2, Z_TRIG)) {
//											// 568
//											slow = true;
//										}
//
//										// e57c
//										if (contGetButtonsPressedThisFrame(contpad1, Z_TRIG)) {
//											explode = true;
//										}
//									} else {
//										if (contGetButtons(contpad1, A_BUTTON | B_BUTTON)
//												|| contGetButtons(contpad2, A_BUTTON | B_BUTTON)
//												|| contGetButtons(contpad1, Z_TRIG)) {
//											slow = true;
//										}
//
//										if (contGetButtonsPressedThisFrame(contpad2, Z_TRIG)) {
//											explode = true;
//										}
//									}
//
//									cStack243 = contGetStickX(contpad1);
//									cStack244 = contGetStickY(contpad1);
//								} else {
//									slow = true;
//								}
//
//								if (contGetButtons(contpad1, START_BUTTON) || contGetButtons(contpad2, START_BUTTON)) {
//									pause = true;
//								}
//							} else {
//								if (g_PlayersWithControl[g_Vars.currentplayernum]) {
//									if (mode == CONTROLMODE_13 || mode == CONTROLMODE_14) {
//										if (contGetButtonsPressedThisFrame(contpad1, A_BUTTON)) {
//											explode = true;
//										}
//
//										if (contGetButtons(contpad1, B_BUTTON | Z_TRIG | L_TRIG | R_TRIG)) {
//											slow = true;
//										}
//									} else {
//										if (contGetButtonsPressedThisFrame(contpad1, Z_TRIG)) {
//											explode = true;
//										}
//
//										if (contGetButtons(contpad1, A_BUTTON | B_BUTTON | L_TRIG | R_TRIG)) {
//											slow = true;
//										}
//									}
//
//									cStack243 = contGetStickX(contpad1);
//									cStack244 = contGetStickY(contpad1);
//								} else {
//									slow = true;
//								}
//
//								if (contGetButtons(contpad1, START_BUTTON)) {
//									pause = true;
//								}
//							}
//
//							if (pause) {
//								if (g_Vars.mplayerisrunning == false) {
//									currentPlayerPause(PAUSEMODE_2);
//								} else {
//									mpPushPauseDialog();
//								}
//							}
//
//							// e7a4
//							sp736 = true;
//							sp684.z = sp696[2];
//							sp684.x = sp696[0];
//							fVar22 = cStack244 * g_Vars.lvupdate240f * 0.00025f;
//							sp372 = -cStack243 * g_Vars.lvupdate240f * 0.00025f;
//
//							// e80c
//							fVar20 = sqrtf(sp696[2] * sp696[2] + sp696[0] * sp696[0]);
//							sp684.x = sp684.x / fVar20;
//							sp684.z = sp684.z / fVar20;
//							sp332[3] = sinf(fVar22);
//							sp332[0] = cosf(fVar22);
//
//							sp332[1] = sp684.x * sp332[3];
//							sp332[2] = 0;
//							sp332[3] = sp684.z * sp332[3];
//
//							// e864
//							sp348[2] = sinf(sp372);
//							sp348[1] = 0;
//							sp348[0] = cosf(sp372);
//
//							if (sp696[4] < 0) {
//								sp348[2] = -sp348[2];
//							}
//
//							sp348[3] = 0;
//
//							// e8b0
//							func0f097738(sp348, sp332, sp316);
//							func0f096ed4(sp316, sp508);
//							func00015b10(sp508, &obj48->unk04);
//
//							obj48->unkb2 = 0xffff;
//							obj48->flags |= 0x00004000;
//							obj48->unk18 = 0;
//							obj48->unk14 = 0;
//							obj48->unk10 = 0;
//
//							if ((obj48->flags & 0x00000080) == 0) {
//								obj48->unk88 = 0;
//							}
//
//							if (explode) {
//								rocket->team = TEAM_00;
//							}
//
//							prevspeed = sqrtf(
//									obj48->unk04.z * obj48->unk04.z +
//									obj48->unk04.x * obj48->unk04.x +
//									obj48->unk04.y * obj48->unk04.y);
//
//							if (slow == false) {
//								targetspeed = 12;
//							} else {
//								targetspeed = 1;
//							}
//
//							if (prevspeed < targetspeed) {
//								newspeed = prevspeed + 0.05f * g_Vars.lvupdate240f;
//
//								if (newspeed > targetspeed) {
//									newspeed = targetspeed;
//								}
//							} else if (prevspeed > targetspeed) {
//								newspeed = prevspeed - 0.05f * g_Vars.lvupdate240f;
//
//								if (newspeed < targetspeed) {
//									newspeed = targetspeed;
//								}
//							} else {
//								newspeed = prevspeed;
//							}
//
//							obj48->unk04.x = (obj48->unk04.x * newspeed) / prevspeed;
//							obj48->unk04.y = (obj48->unk04.y * newspeed) / prevspeed;
//							obj48->unk04.z = (obj48->unk04.z * newspeed) / prevspeed;
//
//							// ea10
//							func00015d54(sp696, sp444);
//							func0f097044(sp444, sp300);
//							func0f097738(sp316, sp300, sp284);
//							func0f096ed4(sp284, sp380);
//							func00015da0(sp380, sp696);
//
//							rocket->base.realrot[0] = sp696[0] * sp680;
//							rocket->base.realrot[1] = sp696[1] * sp680;
//							rocket->base.realrot[2] = sp696[2] * sp680;
//							rocket->base.realrot[3] = sp696[3] * sp680;
//							rocket->base.realrot[4] = sp696[4] * sp680;
//							rocket->base.realrot[5] = sp696[5] * sp680;
//							rocket->base.realrot[6] = sp696[6] * sp680;
//							rocket->base.realrot[7] = sp696[7] * sp680;
//							rocket->base.realrot[8] = sp696[8] * sp680;
//						}
//					}
//
//					if (sp736 == false) {
//						g_Vars.currentplayer->slayerrocket = NULL;
//						g_Vars.currentplayer->visionmode = VISIONMODE_3;
//					}
//
//					g_Vars.currentplayer->waitforzrelease = true;
//
//					if (rocket && rocket->base.prop) {
//						func0f0c1840(&sp764, &sp740, &sp752, &rocket->base.prop->pos, rocket->base.prop->rooms);
//					} else {
//						func0f0c1840(&sp764, &sp740, &sp752, NULL, NULL);
//					}
//				} else {
//					if (g_Vars.tickmode == TICKMODE_1) {
//						struct coord sp244;
//
//						func0f0b9538();
//
//						if (g_PlayersWithControl[g_Vars.currentplayernum] == false) {
//							currentPlayerUpdateFootsteps(0, 0, 0, 1);
//						} else {
//							currentPlayerUpdateFootsteps(1, 1, param_1, 0);
//						}
//
//						func0f0bd3c4();
//						currentPlayerSetCameraMode(CAMERAMODE_DEFAULT);
//
//						sp244.x = g_Vars.currentplayer->bond2.unk10.x;
//						sp244.y = g_Vars.currentplayer->bond2.unk10.y;
//						sp244.z = g_Vars.currentplayer->bond2.unk10.z;
//
//						// ec10
//						func0f0c1840(&sp244,
//								&g_Vars.currentplayer->bond2.unk28,
//								&g_Vars.currentplayer->bond2.unk1c,
//								&g_Vars.currentplayer->prop->pos,
//								g_Vars.currentplayer->prop->rooms);
//
//						if (g_Vars.normmplayerisrunning == false
//								&& g_MissionConfig.iscoop
//								&& g_Vars.numaibuddies > 0
//								&& g_Vars.unk000478 == 0
//								&& g_Vars.stagenum != STAGE_CITRAINING
//								&& g_Vars.lvframenum > 20) {
//							s32 i;
//							g_Vars.unk000478 = 1;
//
//							// Spawn coop aibots
//							for (i = 0; i < g_Vars.numaibuddies; i++) {
//								struct prop *prop = NULL;
//
//								if ((g_CheatsActiveBank0 & (CHEAT_PUGILIST | CHEAT_HOTSHOT | CHEAT_HITANDRUN | CHEAT_ALIEN)) == 0) {
//									if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
//										// d0c
//										prop = chrSpawnAtCoord(BODY_DARK_COMBAT, HEAD_VD,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta / 2),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									} else if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
//										// d64
//										prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									} else {
//										// db4
//										prop = chrSpawnAtCoord(BODY_DARK_COMBAT, HEAD_VD,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta / 2),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									}
//
//									if (prop) {
//										struct chrdata *chr = prop->chr;
//										chr->flags |= CHRFLAG0_00002000;
//										chr->flags2 |= CHRFLAG1_40000000 | CHRFLAG1_00200000 | CHRFLAG1_00100000;
//										chr->team = TEAM_ALLY;
//										chr->squadron = SQUADRON_01;
//										chr->hidden |= CHRHFLAG_PSYCHOSISED;
//										chr->voicebox = VOICEBOX_3;
//										chr->teamscandist = 50;
//										chr->accuracyrating = 100;
//										chr->speedrating = 100;
//
//										if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
//											chrAddHealth(chr, 40);
//										} else {
//											chrAddHealth(chr, 40);
//										}
//
//										chrSetMaxDamage(chr, 4);
//
//										chr->cloakfadefinished = true;
//										chr->chrflags |= CHRCFLAG_00040000;
//										chr->hidden |= CHRHFLAG_CLOAKED;
//										chr->cloakfadefrac = 0;
//
//										chrGiveWeapon(chr, MODEL_CHRFALCON2, WEAPON_FALCON2, 0);
//									}
//								}
//
//								if (cheatIsActive(CHEAT_PUGILIST)) {
//									if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
//										// eef0
//										prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									} else {
//										// ef34
//										prop = chrSpawnAtCoord(BODY_CARRINGTON, HEAD_JAMIE,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_200),
//												0);
//									}
//
//									if (prop) {
//										struct chrdata *chr = prop->chr;
//										chr->flags |= CHRFLAG0_00002000 | CHRFLAG0_00000080;
//										chr->flags2 |= CHRFLAG1_40000000 | CHRFLAG1_00200000 | CHRFLAG1_00100000 | CHRFLAG1_00000080 | CHRFLAG1_00000001;
//										chr->team = TEAM_ALLY;
//										chr->squadron = SQUADRON_01;
//										chr->teamscandist = 100;
//										chr->hidden |= CHRHFLAG_PSYCHOSISED;
//										chr->voicebox = VOICEBOX_1;
//										chr->accuracyrating = 100;
//										chr->speedrating = 100;
//
//										if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
//											chrAddHealth(chr, 40);
//										} else {
//											chrAddHealth(chr, 40);
//										}
//
//										chr->cloakfadefinished = true;
//										chr->chrflags |= CHRCFLAG_00040000;
//										chr->hidden |= CHRHFLAG_PSYCHOSISED;
//										chr->cloakfadefrac = 0;
//
//										chrSetMaxDamage(chr, 20);
//									}
//								}
//
//								if (cheatIsActive(CHEAT_HITANDRUN)) {
//									if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
//										// f05c
//										prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									} else {
//										// f0a0
//										prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MARK2,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									}
//
//									if (prop) {
//										struct chrdata *chr = prop->chr;
//										chr->flags |= CHRFLAG0_00002000;
//										chr->flags2 |= CHRFLAG1_80000000 | CHRFLAG1_00200000 | CHRFLAG1_00100000;
//										chr->team = TEAM_ALLY;
//										chr->squadron = SQUADRON_01;
//										chr->hidden |= CHRHFLAG_PSYCHOSISED;
//										chr->voicebox = VOICEBOX_2;
//										chr->teamscandist = 50;
//										chr->accuracyrating = 50;
//										chr->speedrating = 100;
//
//										if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
//											chrAddHealth(chr, 10);
//										} else {
//											chrAddHealth(chr, 10);
//										}
//
//										chrSetMaxDamage(chr, 10);
//
//										chr->cloakfadefinished = true;
//										chr->chrflags |= CHRCFLAG_00040000;
//										chr->hidden |= CHRHFLAG_CLOAKED;
//										chr->cloakfadefrac = 0;
//
//										chrGiveWeapon(chr, MODEL_CHRAVENGER, WEAPON_K7AVENGER, 0);
//									}
//								}
//
//								if (cheatIsActive(CHEAT_HOTSHOT)) {
//									if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
//										// f1e0
//										prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									} else {
//										// f224
//										prop = chrSpawnAtCoord(BODY_CISOLDIER, HEAD_CHRIST,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									}
//
//									if (prop) {
//										struct chrdata *chr = prop->chr;
//										chr->flags |= CHRFLAG0_00002000;
//										chr->flags2 |= CHRFLAG1_40000000 | CHRFLAG1_00200000 | CHRFLAG1_00100000;
//										chr->team = TEAM_ALLY;
//										chr->squadron = SQUADRON_01;
//										chr->hidden |= CHRHFLAG_PSYCHOSISED;
//										chr->voicebox = VOICEBOX_0;
//										chr->teamscandist = 100;
//										chr->accuracyrating = 50;
//										chr->speedrating = 100;
//
//										if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
//											chrAddHealth(chr, 40);
//										} else {
//											chrAddHealth(chr, 40);
//										}
//
//										chrSetMaxDamage(chr, 10);
//
//										chr->cloakfadefinished = true;
//										chr->chrflags |= CHRCFLAG_00040000;
//										chr->hidden |= CHRHFLAG_CLOAKED;
//										chr->cloakfadefrac = 0;
//
//										chrGiveWeapon(chr, MODEL_CHRDY357TRENT, WEAPON_DY357LX, 0);
//										chrGiveWeapon(chr, MODEL_CHRDY357, WEAPON_DY357MAGNUM, 0x10000000);
//									}
//								}
//
//								if (cheatIsActive(CHEAT_ALIEN)) {
//									if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
//										// f374
//										prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									} else {
//										// f3b8
//										prop = chrSpawnAtCoord(BODY_ELVIS1, HEAD_MAIAN_S,
//												&g_Vars.currentplayer->prop->pos,
//												g_Vars.currentplayer->prop->rooms,
//												BADDEG2RAD(g_Vars.currentplayer->vv_theta),
//												ailistFindById(GAILIST_INIT_COOP_100),
//												0);
//									}
//
//									if (prop) {
//										struct chrdata *chr = prop->chr;
//										chr->flags |= CHRFLAG0_00002000;
//										chr->flags2 |= CHRFLAG1_80000000 | CHRFLAG1_40000000 | CHRFLAG1_00200000 | CHRFLAG1_00100000;
//										chr->team = TEAM_ALLY;
//										chr->squadron = SQUADRON_01;
//										chr->hidden |= CHRHFLAG_PSYCHOSISED;
//										chr->voicebox = VOICEBOX_0;
//										chr->teamscandist = 150;
//										chr->accuracyrating = 100;
//										chr->speedrating = 100;
//
//										if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
//											chrAddHealth(chr, 40);
//										} else {
//											chrAddHealth(chr, 40);
//										}
//
//										chrSetMaxDamage(chr, 10);
//
//										chr->cloakfadefinished = true;
//										chr->chrflags |= CHRCFLAG_00040000;
//										chr->hidden |= CHRHFLAG_CLOAKED;
//										chr->cloakfadefrac = 0;
//
//										chrGiveWeapon(chr, MODEL_CHRRCP120, WEAPON_RCP120, 0);
//									}
//								}
//
//								g_Vars.aibuddies[i] = prop;
//							}
//						}
//					} else if (g_Vars.tickmode == TICKMODE_0 || g_Vars.tickmode == TICKMODE_5) {
//						func0f0b9538();
//						currentPlayerUpdateFootsteps(1, 1, param_1, 0);
//						func0f0bd3c4();
//						currentPlayerSetCameraMode(CAMERAMODE_DEFAULT);
//						func0f0c1840(&g_Vars.currentplayer->bond2.unk10,
//								&g_Vars.currentplayer->bond2.unk28,
//								&g_Vars.currentplayer->bond2.unk1c,
//								&g_Vars.currentplayer->prop->pos,
//								g_Vars.currentplayer->prop->rooms);
//					} else if (g_Vars.tickmode == TICKMODE_4) {
//						func0f0b8ba0();
//						currentPlayerUpdateFootsteps(0, 0, 0, 1);
//						func0f0b96e8();
//					} else if (g_Vars.tickmode == TICKMODE_3) {
//						func0f0b8ba0();
//						currentPlayerUpdateFootsteps(0, 0, 0, 1);
//						func0f0b9cbc();
//					} else if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
//						struct pad pad;
//						f32 sp216;
//						f32 sp212;
//						f32 fVar20;
//						f32 fVar22;
//						f32 fVar18;
//
//						func0f0b9538();
//						padUnpack(g_Vars.currentplayer->autocontrol_aimpad, PADFIELD_POS, &pad);
//
//						if (mainGetStageNum() == g_Stages[STAGE_EXTRACTION].id
//								&& g_Vars.currentplayer->autocontrol_aimpad == 0x19) {
//							pad.pos.x -= 100;
//						}
//
//						sp216 = pad.pos.x - g_Vars.currentplayer->bond2.unk10.x;
//						sp212 = pad.pos.z - g_Vars.currentplayer->bond2.unk10.z;
//						fVar20 = func0f096750(sp216, sp212);
//
//						if (fVar20 > M_TAU) {
//							fVar20 -= M_TAU;
//						}
//
//						if (fVar20 < 0) {
//							fVar20 += M_TAU;
//						}
//
//						fVar22 = M_TAU;
//						fVar18 = func0f096750(g_Vars.currentplayer->bond2.unk00.x, g_Vars.currentplayer->bond2.unk00.z);
//
//						if (fVar18 > fVar22) {
//							fVar18 -= fVar22;
//						}
//
//						if (fVar18 < 0) {
//							fVar18 += fVar22;
//						}
//
//						fVar18 -= fVar20;
//
//						if (fVar18 > M_PI) {
//							fVar18 -= fVar22;
//						}
//
//						if (fVar18 < -M_PI) {
//							fVar18 += fVar22;
//						}
//
//						fVar20 = 1;
//
//						if (fVar18 / M_PI < 0) {
//							fVar20 = -1;
//						}
//
//						g_Vars.currentplayer->unk1bd8 = (fVar20 * g_Vars.currentplayer->autocontrol_turnspeed);
//
//						if (fVar18 >= -0.09f && fVar18 <= 0.09f) {
//							g_Vars.currentplayer->unk1bd8 = 0;
//
//							 if (g_Vars.currentplayer->autocontrol_walkspeed == 0) {
//								g_Vars.currentplayer->autocontrol_turnspeed = 0;
//							 }
//						}
//
//						if (g_Vars.currentplayer->vv_verta <= 30) {
//							g_Vars.currentplayer->vv_verta +=
//								(g_Vars.currentplayer->autocontrol_lookup / 360.0f) * fVar22;
//						}
//
//						if (g_Vars.currentplayer->autocontrol_walkspeed == 0) {
//							if (fVar18 >= -0.2f && fVar18 <= 0.2f) {
//								setTickMode(TICKMODE_1);
//							}
//						} else {
//							sp216 = sqrtf(sp216 * sp216 + sp212 * sp212);
//
//							if (sp216 < g_Vars.currentplayer->autocontrol_dist) {
//								setTickMode(TICKMODE_1);
//							}
//						}
//
//						fVar20 = 1;
//						fVar22 = g_Vars.currentplayer->autocontrol_dist;
//
//						if (sp216 < fVar22 + fVar22) {
//							if (sp216 < fVar22) {
//								fVar20 = 0.00000000;
//							} else {
//								fVar20 = ((sp216 - fVar22) / fVar22) * 0.5f + 0.5f;
//							}
//						}
//
//						g_Vars.currentplayer->unk1bdc = g_Vars.currentplayer->autocontrol_walkspeed * fVar20;
//						currentPlayerUpdateFootsteps(1, 1, 0, 1);
//						func0f0bd3c4();
//						currentPlayerSetCameraMode(CAMERAMODE_DEFAULT);
//						func0f0c1840(&g_Vars.currentplayer->bond2.unk10,
//								&g_Vars.currentplayer->bond2.unk28,
//								&g_Vars.currentplayer->bond2.unk1c,
//								&g_Vars.currentplayer->prop->pos,
//								g_Vars.currentplayer->prop->rooms);
//					}
//				}
//			}
//		}
//	}
//
//	// f934
//	g_Vars.currentplayer->bondwatchtime60 += g_Vars.diffframe60freal;
//
//	if (var8007074c != 0) {
//		u32 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//
//		if (soloIsPaused() == false
//				&& param_1
//				&& contGetButtonsPressedThisFrame(contpad1, A_BUTTON | B_BUTTON | Z_TRIG | START_BUTTON | L_TRIG | R_TRIG)) {
//			var8007074c = 2;
//
//			if (currentPlayerIsFadeComplete()) {
//				if (g_Vars.currentplayer->colourscreenfrac == 0) {
//					currentPlayerSetFadeColour(0, 0, 0, 0);
//					currentPlayerSetFadeFrac(60, 1);
//				}
//			} else {
//				if (g_Vars.currentplayer->colourfadefracnew == 0) {
//					currentPlayerSetFadeFrac(g_Vars.currentplayer->colourfadetime60, 1);
//				}
//			}
//		}
//
//		if (var8007074c == 2
//				&& currentPlayerIsFadeComplete()
//				&& g_Vars.currentplayer->colourscreenfrac == 1) {
//			func0000e990();
//		}
//	}
//
//	if (var80070744) {
//		func0f0b9650();
//	}
//
//	if (g_Vars.currentplayer->isdead) {
//		if (g_Vars.currentplayer->redbloodfinished == false) {
//			func0f0a29c8();
//		}
//
//		if (g_Vars.currentplayer->redbloodfinished
//				&& g_Vars.currentplayer->deathanimfinished) {
//			if (g_Vars.mplayerisrunning == false) {
//				mainEndStage();
//			} else {
//				if (g_Vars.coopplayernum < 0) {
//					if (g_Vars.antiplayernum >= 0 && g_Vars.bond == g_Vars.currentplayer) {
//						mainEndStage();
//					}
//				} else {
//					if (g_Vars.bond == g_Vars.currentplayer
//							&& g_Vars.coop->isdead
//							&& g_Vars.coop->redbloodfinished
//							&& g_Vars.coop->deathanimfinished) {
//						mainEndStage();
//					} else {
//						func0f049644(g_Vars.currentplayernum);
//					}
//				}
//			}
//		}
//	}
//
//	if (g_Vars.tickmode == TICKMODE_5 && currentPlayerIsFadeComplete()) {
//		mainEndStage();
//	}
//}

const u32 var7f1ad528[] = {0x49742400};
const u32 var7f1ad52c[] = {0x49742400};
const u32 var7f1ad530[] = {0x471c4000};
const u32 var7f1ad534[] = {0x40c907a9};
const u32 var7f1ad538[] = {0x40c907a9};

u32 var800709f4 = 0x02810000;
u32 var800709f8 = 0x00000000;
u32 var800709fc = 0x00000000;
u32 var80070a00 = 0x00000000;
u32 var80070a04 = 0x00000000;
u32 var80070a08 = 0x00000000;
u32 var80070a0c = 0x00000000;
u32 var80070a10 = 0x00000000;
u32 var80070a14 = 0x00000000;
u32 var80070a18 = 0x00000000;
u32 var80070a1c = 0x00000000;
u32 var80070a20 = 0x00000000;
u32 var80070a24 = 0x3eb2b17a;
u32 var80070a28 = 0xbfc907a9;
u32 var80070a2c = 0x3fc907a9;
u32 var80070a30 = 0xbfc907a9;
u32 var80070a34 = 0x00000000;
u32 var80070a38 = 0x00000000;
u32 var80070a3c = 0x02850000;
u32 var80070a40 = 0x00000000;
u32 var80070a44 = 0x00000000;
u32 var80070a48 = 0x00000000;
u32 var80070a4c = 0x00000000;
u32 var80070a50 = 0x00000000;
u32 var80070a54 = 0x00000000;
u32 var80070a58 = 0x00000000;
u32 var80070a5c = 0x00000000;
u32 var80070a60 = 0x00000000;
u32 var80070a64 = 0x00000000;
u32 var80070a68 = 0x00000000;
u32 var80070a6c = 0x3eb2b17a;
u32 var80070a70 = 0xbfc907a9;
u32 var80070a74 = 0x3fc907a9;
u32 var80070a78 = 0xbfc907a9;
u32 var80070a7c = 0x00000000;
u32 var80070a80 = 0x00000000;
u32 var80070a84 = 0x02820000;
u32 var80070a88 = 0x00000000;
u32 var80070a8c = 0x00000000;
u32 var80070a90 = 0x00000000;
u32 var80070a94 = 0x00000000;
u32 var80070a98 = 0x00000000;
u32 var80070a9c = 0x00000000;
u32 var80070aa0 = 0x00000000;
u32 var80070aa4 = 0x00000000;
u32 var80070aa8 = 0x00000000;
u32 var80070aac = 0x00000000;
u32 var80070ab0 = 0x00000000;
u32 var80070ab4 = 0x3eb2b17a;
u32 var80070ab8 = 0xbfc907a9;
u32 var80070abc = 0x3fc907a9;
u32 var80070ac0 = 0xbfc907a9;
u32 var80070ac4 = 0x3fcccccd;
u32 var80070ac8 = 0x3fcccccd;
u32 var80070acc = 0x02860000;
u32 var80070ad0 = 0x00000000;
u32 var80070ad4 = 0x00000000;
u32 var80070ad8 = 0x00000000;
u32 var80070adc = 0x00000000;
u32 var80070ae0 = 0x00000000;
u32 var80070ae4 = 0x00000000;
u32 var80070ae8 = 0x00000000;
u32 var80070aec = 0x00000000;
u32 var80070af0 = 0x00000000;
u32 var80070af4 = 0x00000000;
u32 var80070af8 = 0x00000000;
u32 var80070afc = 0x3e32b17a;
u32 var80070b00 = 0xbfc907a9;
u32 var80070b04 = 0x3fc907a9;
u32 var80070b08 = 0xbfc907a9;
u32 var80070b0c = 0x3fcccccd;
u32 var80070b10 = 0x3fcccccd;
u32 var80070b14 = 0x02830000;
u32 var80070b18 = 0x00000000;
u32 var80070b1c = 0x00000000;
u32 var80070b20 = 0x00000000;
u32 var80070b24 = 0x00000000;
u32 var80070b28 = 0x00000000;
u32 var80070b2c = 0x00000000;
u32 var80070b30 = 0x00000000;
u32 var80070b34 = 0x00000000;
u32 var80070b38 = 0x00000000;
u32 var80070b3c = 0x00000000;
u32 var80070b40 = 0x00000000;
u32 var80070b44 = 0x3eb2b17a;
u32 var80070b48 = 0xbfc907a9;
u32 var80070b4c = 0x3fc907a9;
u32 var80070b50 = 0xbfc907a9;
u32 var80070b54 = 0x00000000;
u32 var80070b58 = 0x00000000;
u32 var80070b5c = 0x02870000;
u32 var80070b60 = 0x00000000;
u32 var80070b64 = 0x00000000;
u32 var80070b68 = 0x00000000;
u32 var80070b6c = 0x00000000;
u32 var80070b70 = 0x00000000;
u32 var80070b74 = 0x00000000;
u32 var80070b78 = 0x00000000;
u32 var80070b7c = 0x00000000;
u32 var80070b80 = 0x00000000;
u32 var80070b84 = 0x00000000;
u32 var80070b88 = 0x00000000;
u32 var80070b8c = 0x3e32b17a;
u32 var80070b90 = 0xbfc907a9;
u32 var80070b94 = 0x3fc907a9;
u32 var80070b98 = 0xbfc907a9;
u32 var80070b9c = 0x00000000;
u32 var80070ba0 = 0x00000000;
u32 var80070ba4 = (u32) &var80065be0;
u32 var80070ba8 = 0x00000000;
u32 var80070bac = 0x3dcccccd;
u32 var80070bb0 = 0x429e0000;
u32 var80070bb4 = 0x42ae0000;
u32 var80070bb8 = 0x3f86051b;
u32 var80070bbc = (u32) &var80067aa0;
u32 var80070bc0 = 0x00000000;
u32 var80070bc4 = 0x3f000000;
u32 var80070bc8 = 0xbf800000;
u32 var80070bcc = 0xbf800000;
u32 var80070bd0 = 0x3f86051b;
u32 var80070bd4 = (u32) &var80067ae8;
u32 var80070bd8 = 0x00000000;
u32 var80070bdc = 0x3f000000;
u32 var80070be0 = 0xbf800000;
u32 var80070be4 = 0xbf800000;
u32 var80070be8 = 0x3f86051b;
u32 var80070bec = (u32) &var800709f4;
u32 var80070bf0 = 0x00000000;
u32 var80070bf4 = 0x3a83126f;
u32 var80070bf8 = 0x00000000;
u32 var80070bfc = 0x3dcccccd;
u32 var80070c00 = 0x3f86051b;
u32 var80070c04 = (u32) &var800709f4;
u32 var80070c08 = 0x00000000;
u32 var80070c0c = 0x3f00c49c;
u32 var80070c10 = 0xbf800000;
u32 var80070c14 = 0xbf800000;
u32 var80070c18 = 0x3f86051b;
u32 var80070c1c = (u32) &var80070a3c;
u32 var80070c20 = 0x00000000;
u32 var80070c24 = 0x3a83126f;
u32 var80070c28 = 0x00000000;
u32 var80070c2c = 0x3dcccccd;
u32 var80070c30 = 0x3f06051b;
u32 var80070c34 = (u32) &var80070a3c;
u32 var80070c38 = 0x00000000;
u32 var80070c3c = 0x3ee66666;
u32 var80070c40 = 0xbf800000;
u32 var80070c44 = 0xbf800000;
u32 var80070c48 = 0x3f06051b;
u32 var80070c4c = (u32) &var800656c0;
u32 var80070c50 = 0x00000000;
u32 var80070c54 = 0x3d4ccccd;
u32 var80070c58 = 0x420c0000;
u32 var80070c5c = 0x42200000;
u32 var80070c60 = 0x3f86051b;
u32 var80070c64 = (u32) &var80067a10;
u32 var80070c68 = 0x00000000;
u32 var80070c6c = 0x3f000000;
u32 var80070c70 = 0xbf800000;
u32 var80070c74 = 0xbf800000;
u32 var80070c78 = 0x3f86051b;
u32 var80070c7c = (u32) &var80067a58;
u32 var80070c80 = 0x00000000;
u32 var80070c84 = 0x3f000000;
u32 var80070c88 = 0xbf800000;
u32 var80070c8c = 0xbf800000;
u32 var80070c90 = 0x3f86051b;
u32 var80070c94 = (u32) &var80070a84;
u32 var80070c98 = 0x00000000;
u32 var80070c9c = 0x3a83126f;
u32 var80070ca0 = 0x00000000;
u32 var80070ca4 = 0x3dcccccd;
u32 var80070ca8 = 0x3f86051b;
u32 var80070cac = (u32) &var80070a84;
u32 var80070cb0 = 0x00000000;
u32 var80070cb4 = 0x3f00c49c;
u32 var80070cb8 = 0xbf800000;
u32 var80070cbc = 0xbf800000;
u32 var80070cc0 = 0x3f86051b;
u32 var80070cc4 = (u32) &var80070acc;
u32 var80070cc8 = 0x00000000;
u32 var80070ccc = 0x3a83126f;
u32 var80070cd0 = 0x00000000;
u32 var80070cd4 = 0x3dcccccd;
u32 var80070cd8 = 0x3f06051b;
u32 var80070cdc = (u32) &var80070acc;
u32 var80070ce0 = 0x00000000;
u32 var80070ce4 = 0x3ee66666;
u32 var80070ce8 = 0xbf800000;
u32 var80070cec = 0xbf800000;
u32 var80070cf0 = 0x3f06051b;
u32 var80070cf4 = 0x00000000;
u32 var80070cf8 = 0x006a0000;
u32 var80070cfc = 0x3e800000;
u32 var80070d00 = 0x00000000;
u32 var80070d04 = 0xbf800000;
u32 var80070d08 = 0x3f86051b;
u32 var80070d0c = 0x00000000;
u32 var80070d10 = 0x006b0000;
u32 var80070d14 = 0x3f000000;
u32 var80070d18 = 0xbf800000;
u32 var80070d1c = 0xbf800000;
u32 var80070d20 = 0x3f86051b;
u32 var80070d24 = 0x00000000;
u32 var80070d28 = 0x00590000;
u32 var80070d2c = 0x3f000000;
u32 var80070d30 = 0xbf800000;
u32 var80070d34 = 0xbf800000;
u32 var80070d38 = 0x3f86051b;
u32 var80070d3c = 0x00000000;
u32 var80070d40 = 0x02800000;
u32 var80070d44 = 0x3a83126f;
u32 var80070d48 = 0x00000000;
u32 var80070d4c = 0x3dcccccd;
u32 var80070d50 = 0x3f86051b;
u32 var80070d54 = 0x00000000;
u32 var80070d58 = 0x02800000;
u32 var80070d5c = 0x3f00c49c;
u32 var80070d60 = 0xbf800000;
u32 var80070d64 = 0xbf800000;
u32 var80070d68 = 0x3f86051b;
u32 var80070d6c = 0x00000000;
u32 var80070d70 = 0x02840000;
u32 var80070d74 = 0x3a83126f;
u32 var80070d78 = 0x00000000;
u32 var80070d7c = 0x3dcccccd;
u32 var80070d80 = 0x3f06051b;
u32 var80070d84 = 0x00000000;
u32 var80070d88 = 0x02840000;
u32 var80070d8c = 0x3ee66666;
u32 var80070d90 = 0xbf800000;
u32 var80070d94 = 0xbf800000;
u32 var80070d98 = 0x3f06051b;
u32 var80070d9c = (u32) &var800663d8;
u32 var80070da0 = 0x00000000;
u32 var80070da4 = 0x3dcccccd;
u32 var80070da8 = 0x42000000;
u32 var80070dac = 0x42280000;
u32 var80070db0 = 0x3f86051b;
u32 var80070db4 = (u32) &var80067b30;
u32 var80070db8 = 0x00000000;
u32 var80070dbc = 0x3f000000;
u32 var80070dc0 = 0xbf800000;
u32 var80070dc4 = 0xbf800000;
u32 var80070dc8 = 0x3f86051b;
u32 var80070dcc = (u32) &var80067b78;
u32 var80070dd0 = 0x00000000;
u32 var80070dd4 = 0x3f000000;
u32 var80070dd8 = 0xbf800000;
u32 var80070ddc = 0xbf800000;
u32 var80070de0 = 0x3f86051b;
u32 var80070de4 = (u32) &var80070b14;
u32 var80070de8 = 0x00000000;
u32 var80070dec = 0x3a83126f;
u32 var80070df0 = 0x00000000;
u32 var80070df4 = 0x3dcccccd;
u32 var80070df8 = 0x3f86051b;
u32 var80070dfc = (u32) &var80070b14;
u32 var80070e00 = 0x00000000;
u32 var80070e04 = 0x3f00c49c;
u32 var80070e08 = 0xbf800000;
u32 var80070e0c = 0xbf800000;
u32 var80070e10 = 0x3f86051b;
u32 var80070e14 = (u32) &var80070b5c;
u32 var80070e18 = 0x00000000;
u32 var80070e1c = 0x3a83126f;
u32 var80070e20 = 0x00000000;
u32 var80070e24 = 0x3dcccccd;
u32 var80070e28 = 0x3f06051b;
u32 var80070e2c = (u32) &var80070b5c;
u32 var80070e30 = 0x00000000;
u32 var80070e34 = 0x3ee66666;
u32 var80070e38 = 0xbf800000;
u32 var80070e3c = 0xbf800000;
u32 var80070e40 = 0x3f06051b;
u32 var80070e44 = 0x00000000;
u32 var80070e48 = 0x00000000;
u32 var80070e4c = 0x00000000;


void currentPlayerSetGlobalDrawWorldOffset(s32 room)
{
	func0f166df0(room, &g_Vars.currentplayer->globaldrawworldoffset);

	g_Vars.currentplayer->globaldrawworldbgoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawworldbgoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawworldbgoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	currentPlayerSetLastRoomForOffset(room);
}

void currentPlayerSetGlobalDrawCameraOffset(void)
{
	g_Vars.currentplayer->globaldrawcameraoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawcameraoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawcameraoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	func00015b10(currentPlayerGetMatrix(), &g_Vars.currentplayer->globaldrawcameraoffset);
}

GLOBAL_ASM(
glabel func0f0bfc7c
/*  f0bfc7c:	27bdfef0 */ 	addiu	$sp,$sp,-272
/*  f0bfc80:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0bfc84:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0bfc88:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0bfc8c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0bfc90:	00c08825 */ 	or	$s1,$a2,$zero
/*  f0bfc94:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0bfc98:	0fc5722e */ 	jal	currentPlayerGetScaleBg2Gfx
/*  f0bfc9c:	afa40110 */ 	sw	$a0,0x110($sp)
/*  f0bfca0:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0bfca4:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0bfca8:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0bfcac:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0bfcb0:	0fc2feee */ 	jal	currentPlayerSetGlobalDrawWorldOffset
/*  f0bfcb4:	8dc41ba0 */ 	lw	$a0,0x1ba0($t6)
/*  f0bfcb8:	0fc59e66 */ 	jal	func0f167998
/*  f0bfcbc:	00000000 */ 	nop
/*  f0bfcc0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0bfcc4:	0fc59e66 */ 	jal	func0f167998
/*  f0bfcc8:	ade2005c */ 	sw	$v0,0x5c($t7)
/*  f0bfccc:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0bfcd0:	0fc59e66 */ 	jal	func0f167998
/*  f0bfcd4:	af020060 */ 	sw	$v0,0x60($t8)
/*  f0bfcd8:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0bfcdc:	0fc59e66 */ 	jal	func0f167998
/*  f0bfce0:	af220064 */ 	sw	$v0,0x64($t9)
/*  f0bfce4:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0bfce8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0bfcec:	0fc59e6c */ 	jal	func0f1679b0
/*  f0bfcf0:	ad220068 */ 	sw	$v0,0x68($t1)
/*  f0bfcf4:	8fa80110 */ 	lw	$t0,0x110($sp)
/*  f0bfcf8:	8e430284 */ 	lw	$v1,0x284($s2)
/*  f0bfcfc:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0bfd00:	c5040000 */ 	lwc1	$f4,0x0($t0)
/*  f0bfd04:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f0bfd08:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f0bfd0c:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f0bfd10:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0bfd14:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0bfd18:	e7aa0074 */ 	swc1	$f10,0x74($sp)
/*  f0bfd1c:	c5100004 */ 	lwc1	$f16,0x4($t0)
/*  f0bfd20:	c472003c */ 	lwc1	$f18,0x3c($v1)
/*  f0bfd24:	44055000 */ 	mfc1	$a1,$f10
/*  f0bfd28:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0bfd2c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bfd30:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f0bfd34:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f0bfd38:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0bfd3c:	44063000 */ 	mfc1	$a2,$f6
/*  f0bfd40:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f0bfd44:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0bfd48:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0bfd4c:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f0bfd50:	44072000 */ 	mfc1	$a3,$f4
/*  f0bfd54:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f0bfd58:	e7b00080 */ 	swc1	$f16,0x80($sp)
/*  f0bfd5c:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0bfd60:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f0bfd64:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0bfd68:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f0bfd6c:	46048480 */ 	add.s	$f18,$f16,$f4
/*  f0bfd70:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*  f0bfd74:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f0bfd78:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bfd7c:	c6100004 */ 	lwc1	$f16,0x4($s0)
/*  f0bfd80:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0bfd84:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f0bfd88:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0bfd8c:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f0bfd90:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f0bfd94:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f0bfd98:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0bfd9c:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*  f0bfda0:	0c005a1d */ 	jal	func00016874
/*  f0bfda4:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0bfda8:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f0bfdac:	c7b00080 */ 	lwc1	$f16,0x80($sp)
/*  f0bfdb0:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f0bfdb4:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0bfdb8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bfdbc:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0bfdc0:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0bfdc4:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f0bfdc8:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0bfdcc:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0bfdd0:	8fa500cc */ 	lw	$a1,0xcc($sp)
/*  f0bfdd4:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0bfdd8:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f0bfddc:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0bfde0:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0bfde4:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0bfde8:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0bfdec:	0c0011c3 */ 	jal	func0000470c
/*  f0bfdf0:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f0bfdf4:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f0bfdf8:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0bfdfc:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f0bfe00:	8c450000 */ 	lw	$a1,0x0($v0)
/*  f0bfe04:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0bfe08:	8c470008 */ 	lw	$a3,0x8($v0)
/*  f0bfe0c:	8d440064 */ 	lw	$a0,0x64($t2)
/*  f0bfe10:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0bfe14:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0bfe18:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0bfe1c:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0bfe20:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0bfe24:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0bfe28:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0bfe2c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f0bfe30:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0bfe34:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0bfe38:	0c005a1d */ 	jal	func00016874
/*  f0bfe3c:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0bfe40:	8fac0110 */ 	lw	$t4,0x110($sp)
/*  f0bfe44:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0bfe48:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f0bfe4c:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f0bfe50:	8d860004 */ 	lw	$a2,0x4($t4)
/*  f0bfe54:	8d870008 */ 	lw	$a3,0x8($t4)
/*  f0bfe58:	8d640068 */ 	lw	$a0,0x68($t3)
/*  f0bfe5c:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0bfe60:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0bfe64:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0bfe68:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0bfe6c:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0bfe70:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0bfe74:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0bfe78:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f0bfe7c:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0bfe80:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0bfe84:	0c005ad6 */ 	jal	func00016b58
/*  f0bfe88:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0bfe8c:	0fc59e66 */ 	jal	func0f167998
/*  f0bfe90:	00000000 */ 	nop
/*  f0bfe94:	0fc59e66 */ 	jal	func0f167998
/*  f0bfe98:	00408825 */ 	or	$s1,$v0,$zero
/*  f0bfe9c:	0fc2d5c6 */ 	jal	currentPlayerGetUnk1754
/*  f0bfea0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0bfea4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bfea8:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0bfeac:	0c005680 */ 	jal	func00015a00
/*  f0bfeb0:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bfeb4:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f0bfeb8:	44816000 */ 	mtc1	$at,$f12
/*  f0bfebc:	3c0146fa */ 	lui	$at,0x46fa
/*  f0bfec0:	44811000 */ 	mtc1	$at,$f2
/*  f0bfec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bfec8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bfecc:	24080004 */ 	addiu	$t0,$zero,0x4
/*  f0bfed0:	24040010 */ 	addiu	$a0,$zero,0x10
.L0f0bfed4:
/*  f0bfed4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bfed8:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0bfedc:
/*  f0bfedc:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0bfee0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0bfee4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0bfee8:	00000000 */ 	nop
/*  f0bfeec:	45020004 */ 	bc1fl	.L0f0bff00
/*  f0bfef0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0bfef4:	10000006 */ 	b	.L0f0bff10
/*  f0bfef8:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f0bfefc:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0bff00:
/*  f0bff00:	00000000 */ 	nop
/*  f0bff04:	45000002 */ 	bc1f	.L0f0bff10
/*  f0bff08:	00000000 */ 	nop
/*  f0bff0c:	e44c0000 */ 	swc1	$f12,0x0($v0)
.L0f0bff10:
/*  f0bff10:	1464fff2 */ 	bne	$v1,$a0,.L0f0bfedc
/*  f0bff14:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0bff18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0bff1c:	14a8ffed */ 	bne	$a1,$t0,.L0f0bfed4
/*  f0bff20:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f0bff24:	0fc2d3ee */ 	jal	currentPlayerSetUnk006c
/*  f0bff28:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bff2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bff30:	0c0128d8 */ 	jal	func0004a360
/*  f0bff34:	02202825 */ 	or	$a1,$s1,$zero
/*  f0bff38:	0fc2d3fe */ 	jal	currentPlayerSetUnk1758
/*  f0bff3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0bff40:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f0bff44:	0c0057c1 */ 	jal	func00015f04
/*  f0bff48:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0bff4c:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0bff50:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f0bff54:	0c0128d8 */ 	jal	func0004a360
/*  f0bff58:	8da5005c */ 	lw	$a1,0x5c($t5)
/*  f0bff5c:	8e430284 */ 	lw	$v1,0x284($s2)
/*  f0bff60:	8c64005c */ 	lw	$a0,0x5c($v1)
/*  f0bff64:	0c005a08 */ 	jal	func00016820
/*  f0bff68:	8c650060 */ 	lw	$a1,0x60($v1)
/*  f0bff6c:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0bff70:	0fc2d3e6 */ 	jal	currentPlayerSetUnk173c
/*  f0bff74:	8dc4005c */ 	lw	$a0,0x5c($t6)
/*  f0bff78:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0bff7c:	0fc2d3de */ 	jal	currentPlayerSetUnk1738
/*  f0bff80:	8de40060 */ 	lw	$a0,0x60($t7)
/*  f0bff84:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0bff88:	0fc2d406 */ 	jal	currentPlayerSetMatrix
/*  f0bff8c:	8f040064 */ 	lw	$a0,0x64($t8)
/*  f0bff90:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0bff94:	0fc2d5d6 */ 	jal	currentPlayerSetUnk174c
/*  f0bff98:	8f240068 */ 	lw	$a0,0x68($t9)
/*  f0bff9c:	0fc2d5e6 */ 	jal	currentPlayerSetUnk175c
/*  f0bffa0:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*  f0bffa4:	0fc2d60e */ 	jal	func0f0b5838
/*  f0bffa8:	00000000 */ 	nop
/*  f0bffac:	0fc2ff07 */ 	jal	currentPlayerSetGlobalDrawCameraOffset
/*  f0bffb0:	00000000 */ 	nop
/*  f0bffb4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0bffb8:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0bffbc:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0bffc0:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0bffc4:	03e00008 */ 	jr	$ra
/*  f0bffc8:	27bd0110 */ 	addiu	$sp,$sp,0x110
);

GLOBAL_ASM(
glabel func0f0bffcc
.late_rodata
glabel var7f1ad6b0
.word 0x40c907a9
glabel var7f1ad6b4
.word 0x40490fdb
glabel var7f1ad6b8
.word 0x40c907a9
glabel var7f1ad6bc
.word 0x40490fdb
.text
/*  f0bffcc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0bffd0:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0bffd4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0bffd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0bffdc:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0bffe0:	24441bb0 */ 	addiu	$a0,$v0,0x1bb0
/*  f0bffe4:	24451bbc */ 	addiu	$a1,$v0,0x1bbc
/*  f0bffe8:	0fc2ff1f */ 	jal	func0f0bfc7c
/*  f0bffec:	24461bc8 */ 	addiu	$a2,$v0,0x1bc8
/*  f0bfff0:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f0bfff4:	0fc28302 */ 	jal	func0f0a0c08
/*  f0bfff8:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f0bfffc:	c7a00044 */ 	lwc1	$f0,0x44($sp)
/*  f0c0000:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0c0004:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f0c0008:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0c000c:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*  f0c0010:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0c0014:	0c012974 */ 	jal	sqrtf
/*  f0c0018:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f0c001c:	c7ac002c */ 	lwc1	$f12,0x2c($sp)
/*  f0c0020:	0fc259d4 */ 	jal	func0f096750
/*  f0c0024:	46000386 */ 	mov.s	$f14,$f0
/*  f0c0028:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0c002c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0c0030:	3c017f1b */ 	lui	$at,%hi(var7f1ad6b0)
/*  f0c0034:	c430d6b0 */ 	lwc1	$f16,%lo(var7f1ad6b0)($at)
/*  f0c0038:	c44a0154 */ 	lwc1	$f10,0x154($v0)
/*  f0c003c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c0040:	44812000 */ 	mtc1	$at,$f4
/*  f0c0044:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0c0048:	3c017f1b */ 	lui	$at,%hi(var7f1ad6b4)
/*  f0c004c:	c428d6b4 */ 	lwc1	$f8,%lo(var7f1ad6b4)($at)
/*  f0c0050:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f0c0054:	46060080 */ 	add.s	$f2,$f0,$f6
/*  f0c0058:	4602403e */ 	c.le.s	$f8,$f2
/*  f0c005c:	00000000 */ 	nop
/*  f0c0060:	45020003 */ 	bc1fl	.L0f0c0070
/*  f0c0064:	e442196c */ 	swc1	$f2,0x196c($v0)
/*  f0c0068:	46101081 */ 	sub.s	$f2,$f2,$f16
/*  f0c006c:	e442196c */ 	swc1	$f2,0x196c($v0)
.L0f0c0070:
/*  f0c0070:	c7ae0044 */ 	lwc1	$f14,0x44($sp)
/*  f0c0074:	c7ac003c */ 	lwc1	$f12,0x3c($sp)
/*  f0c0078:	46007387 */ 	neg.s	$f14,$f14
/*  f0c007c:	0fc259d4 */ 	jal	func0f096750
/*  f0c0080:	46006307 */ 	neg.s	$f12,$f12
/*  f0c0084:	3c017f1b */ 	lui	$at,%hi(var7f1ad6b8)
/*  f0c0088:	c430d6b8 */ 	lwc1	$f16,%lo(var7f1ad6b8)($at)
/*  f0c008c:	3c017f1b */ 	lui	$at,%hi(var7f1ad6bc)
/*  f0c0090:	c42ad6bc */ 	lwc1	$f10,%lo(var7f1ad6bc)($at)
/*  f0c0094:	46000086 */ 	mov.s	$f2,$f0
/*  f0c0098:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0c009c:	4600503e */ 	c.le.s	$f10,$f0
/*  f0c00a0:	00000000 */ 	nop
/*  f0c00a4:	45000002 */ 	bc1f	.L0f0c00b0
/*  f0c00a8:	00000000 */ 	nop
/*  f0c00ac:	46100081 */ 	sub.s	$f2,$f0,$f16
.L0f0c00b0:
/*  f0c00b0:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0c00b4:	e5c21970 */ 	swc1	$f2,0x1970($t6)
/*  f0c00b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c00bc:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0c00c0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0c00c4:	03e00008 */ 	jr	$ra
/*  f0c00c8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0c00cc
/*  f0c00cc:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0c00d0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0c00d4:	8c830284 */ 	lw	$v1,0x284($a0)
/*  f0c00d8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0c00dc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c00e0:	44803000 */ 	mtc1	$zero,$f6
/*  f0c00e4:	c4640280 */ 	lwc1	$f4,0x280($v1)
/*  f0c00e8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0c00ec:	00000000 */ 	nop
/*  f0c00f0:	45020021 */ 	bc1fl	.L0f0c0178
/*  f0c00f4:	44808000 */ 	mtc1	$zero,$f16
/*  f0c00f8:	8c6e027c */ 	lw	$t6,0x27c($v1)
/*  f0c00fc:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f0c0100:	000e7c02 */ 	srl	$t7,$t6,0x10
/*  f0c0104:	01e1001b */ 	divu	$zero,$t7,$at
/*  f0c0108:	0000c010 */ 	mfhi	$t8
/*  f0c010c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0c0110:	27280320 */ 	addiu	$t0,$t9,0x320
/*  f0c0114:	0c004b70 */ 	jal	random
/*  f0c0118:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0c011c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0c0120:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0c0124:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f0c0128:	ad22027c */ 	sw	$v0,0x27c($t1)
/*  f0c012c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f0c0130:	8c8a0058 */ 	lw	$t2,0x58($a0)
/*  f0c0134:	8c8d0284 */ 	lw	$t5,0x284($a0)
/*  f0c0138:	014b001a */ 	div	$zero,$t2,$t3
/*  f0c013c:	00006010 */ 	mfhi	$t4
/*  f0c0140:	448c4000 */ 	mtc1	$t4,$f8
/*  f0c0144:	15600002 */ 	bnez	$t3,.L0f0c0150
/*  f0c0148:	00000000 */ 	nop
/*  f0c014c:	0007000d */ 	break	0x7
.L0f0c0150:
/*  f0c0150:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c0154:	15610004 */ 	bne	$t3,$at,.L0f0c0168
/*  f0c0158:	3c018000 */ 	lui	$at,0x8000
/*  f0c015c:	15410002 */ 	bne	$t2,$at,.L0f0c0168
/*  f0c0160:	00000000 */ 	nop
/*  f0c0164:	0006000d */ 	break	0x6
.L0f0c0168:
/*  f0c0168:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0c016c:	e5aa0278 */ 	swc1	$f10,0x278($t5)
/*  f0c0170:	8c830284 */ 	lw	$v1,0x284($a0)
/*  f0c0174:	44808000 */ 	mtc1	$zero,$f16
.L0f0c0178:
/*  f0c0178:	00000000 */ 	nop
/*  f0c017c:	e4700280 */ 	swc1	$f16,0x280($v1)
/*  f0c0180:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c0184:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0c0188:	03e00008 */ 	jr	$ra
/*  f0c018c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0c0190
.late_rodata
glabel var7f1ad6c0
.word 0x3c888889
glabel var7f1ad6c4
.word 0x3f4ccccd
glabel var7f1ad6c8
.word 0x40c907a9
glabel var7f1ad6cc
.word 0x3b03126f
glabel var7f1ad6d0
.word 0x3e4ccccd
glabel var7f1ad6d4
.word 0x3c888889
glabel var7f1ad6d8
.word 0x3b03126f
glabel var7f1ad6dc
.word 0x3e4ccccd
glabel var7f1ad6e0
.word 0x3c888889
glabel var7f1ad6e4
.word 0x3c088889
glabel var7f1ad6e8
.word 0x3c088889
glabel var7f1ad6ec
.word 0x3c888889
.text
/*  f0c0190:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0c0194:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0c0198:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0c019c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0c01a0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c01a4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0c01a8:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f0c01ac:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0c01b0:	44803000 */ 	mtc1	$zero,$f6
/*  f0c01b4:	c5c40280 */ 	lwc1	$f4,0x280($t6)
/*  f0c01b8:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c01bc:	00000000 */ 	nop
/*  f0c01c0:	4502017c */ 	bc1fl	.L0f0c07b4
/*  f0c01c4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0c01c8:	0fc30869 */ 	jal	func0f0c21a4
/*  f0c01cc:	00000000 */ 	nop
/*  f0c01d0:	3c014100 */ 	lui	$at,0x4100
/*  f0c01d4:	44814000 */ 	mtc1	$at,$f8
/*  f0c01d8:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f0c01dc:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c01e0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0c01e4:	e7aa0084 */ 	swc1	$f10,0x84($sp)
/*  f0c01e8:	8c62027c */ 	lw	$v0,0x27c($v1)
/*  f0c01ec:	c4720280 */ 	lwc1	$f18,0x280($v1)
/*  f0c01f0:	00027c02 */ 	srl	$t7,$v0,0x10
/*  f0c01f4:	01e1001b */ 	divu	$zero,$t7,$at
/*  f0c01f8:	3c014270 */ 	lui	$at,0x4270
/*  f0c01fc:	44818000 */ 	mtc1	$at,$f16
/*  f0c0200:	3c017f1b */ 	lui	$at,%hi(var7f1ad6c0)
/*  f0c0204:	c426d6c0 */ 	lwc1	$f6,%lo(var7f1ad6c0)($at)
/*  f0c0208:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0c020c:	3c017f1b */ 	lui	$at,%hi(var7f1ad6c4)
/*  f0c0210:	c428d6c4 */ 	lwc1	$f8,%lo(var7f1ad6c4)($at)
/*  f0c0214:	0000c010 */ 	mfhi	$t8
/*  f0c0218:	46062502 */ 	mul.s	$f20,$f4,$f6
/*  f0c021c:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f0c0220:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0c0224:	27220320 */ 	addiu	$v0,$t9,0x320
/*  f0c0228:	3c017f1b */ 	lui	$at,%hi(var7f1ad6c8)
/*  f0c022c:	4614a280 */ 	add.s	$f10,$f20,$f20
/*  f0c0230:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0c0234:	c46a0278 */ 	lwc1	$f10,0x278($v1)
/*  f0c0238:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f0c023c:	44828000 */ 	mtc1	$v0,$f16
/*  f0c0240:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f0c0244:	468083a0 */ 	cvt.s.w	$f14,$f16
/*  f0c0248:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0c024c:	e4680278 */ 	swc1	$f8,0x278($v1)
/*  f0c0250:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c0254:	c4620278 */ 	lwc1	$f2,0x278($v1)
/*  f0c0258:	4602703e */ 	c.le.s	$f14,$f2
/*  f0c025c:	00000000 */ 	nop
/*  f0c0260:	45000005 */ 	bc1f	.L0f0c0278
/*  f0c0264:	00000000 */ 	nop
/*  f0c0268:	460e1101 */ 	sub.s	$f4,$f2,$f14
/*  f0c026c:	e4640278 */ 	swc1	$f4,0x278($v1)
/*  f0c0270:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c0274:	c5220278 */ 	lwc1	$f2,0x278($t1)
.L0f0c0278:
/*  f0c0278:	c432d6c8 */ 	lwc1	$f18,%lo(var7f1ad6c8)($at)
/*  f0c027c:	460e9003 */ 	div.s	$f0,$f18,$f14
/*  f0c0280:	46001302 */ 	mul.s	$f12,$f2,$f0
/*  f0c0284:	0c0068f7 */ 	jal	sinf
/*  f0c0288:	e7a0004c */ 	swc1	$f0,0x4c($sp)
/*  f0c028c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c0290:	44815000 */ 	mtc1	$at,$f10
/*  f0c0294:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c0298:	44814000 */ 	mtc1	$at,$f8
/*  f0c029c:	460a0180 */ 	add.s	$f6,$f0,$f10
/*  f0c02a0:	46083502 */ 	mul.s	$f20,$f6,$f8
/*  f0c02a4:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0c02a8:	00000000 */ 	nop
/*  f0c02ac:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0c02b0:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0c02b4:	46140402 */ 	mul.s	$f16,$f0,$f20
/*  f0c02b8:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f0c02bc:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c02c0:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f0c02c4:	46048480 */ 	add.s	$f18,$f16,$f4
/*  f0c02c8:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f0c02cc:	c54a0278 */ 	lwc1	$f10,0x278($t2)
/*  f0c02d0:	46065302 */ 	mul.s	$f12,$f10,$f6
/*  f0c02d4:	0c0068f4 */ 	jal	cosf
/*  f0c02d8:	00000000 */ 	nop
/*  f0c02dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c02e0:	44814000 */ 	mtc1	$at,$f8
/*  f0c02e4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c02e8:	44812000 */ 	mtc1	$at,$f4
/*  f0c02ec:	46080400 */ 	add.s	$f16,$f0,$f8
/*  f0c02f0:	46048502 */ 	mul.s	$f20,$f16,$f4
/*  f0c02f4:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0c02f8:	00000000 */ 	nop
/*  f0c02fc:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0c0300:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0c0304:	46140482 */ 	mul.s	$f18,$f0,$f20
/*  f0c0308:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f0c030c:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f0c0310:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0c0314:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f0c0318:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c031c:	24040064 */ 	addiu	$a0,$zero,0x64
/*  f0c0320:	3c017f1b */ 	lui	$at,%hi(var7f1ad6cc)
/*  f0c0324:	8c62027c */ 	lw	$v0,0x27c($v1)
/*  f0c0328:	c422d6cc */ 	lwc1	$f2,%lo(var7f1ad6cc)($at)
/*  f0c032c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c0330:	00025d02 */ 	srl	$t3,$v0,0x14
/*  f0c0334:	0164001b */ 	divu	$zero,$t3,$a0
/*  f0c0338:	00006010 */ 	mfhi	$t4
/*  f0c033c:	448c8000 */ 	mtc1	$t4,$f16
/*  f0c0340:	44814000 */ 	mtc1	$at,$f8
/*  f0c0344:	14800002 */ 	bnez	$a0,.L0f0c0350
/*  f0c0348:	00000000 */ 	nop
/*  f0c034c:	0007000d */ 	break	0x7
.L0f0c0350:
/*  f0c0350:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f0c0354:	05810004 */ 	bgez	$t4,.L0f0c0368
/*  f0c0358:	3c014f80 */ 	lui	$at,0x4f80
/*  f0c035c:	44819000 */ 	mtc1	$at,$f18
/*  f0c0360:	00000000 */ 	nop
/*  f0c0364:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f0c0368:
/*  f0c0368:	0044001b */ 	divu	$zero,$v0,$a0
/*  f0c036c:	46041282 */ 	mul.s	$f10,$f2,$f4
/*  f0c0370:	00006810 */ 	mfhi	$t5
/*  f0c0374:	448d9000 */ 	mtc1	$t5,$f18
/*  f0c0378:	3c017f1b */ 	lui	$at,%hi(var7f1ad6d0)
/*  f0c037c:	c430d6d0 */ 	lwc1	$f16,%lo(var7f1ad6d0)($at)
/*  f0c0380:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0c0384:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f0c0388:	14800002 */ 	bnez	$a0,.L0f0c0394
/*  f0c038c:	00000000 */ 	nop
/*  f0c0390:	0007000d */ 	break	0x7
.L0f0c0394:
/*  f0c0394:	05a10004 */ 	bgez	$t5,.L0f0c03a8
/*  f0c0398:	3c014f80 */ 	lui	$at,0x4f80
/*  f0c039c:	44814000 */ 	mtc1	$at,$f8
/*  f0c03a0:	00000000 */ 	nop
/*  f0c03a4:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f0c03a8:
/*  f0c03a8:	46041282 */ 	mul.s	$f10,$f2,$f4
/*  f0c03ac:	c4680280 */ 	lwc1	$f8,0x280($v1)
/*  f0c03b0:	3c017f1b */ 	lui	$at,%hi(var7f1ad6d4)
/*  f0c03b4:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f0c03b8:	c430d6d4 */ 	lwc1	$f16,%lo(var7f1ad6d4)($at)
/*  f0c03bc:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f0c03c0:	00000000 */ 	nop
/*  f0c03c4:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f0c03c8:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c03cc:	46080482 */ 	mul.s	$f18,$f0,$f8
/*  f0c03d0:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0c03d4:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*  f0c03d8:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c03dc:	24040064 */ 	addiu	$a0,$zero,0x64
/*  f0c03e0:	3c017f1b */ 	lui	$at,%hi(var7f1ad6d8)
/*  f0c03e4:	8c62027c */ 	lw	$v0,0x27c($v1)
/*  f0c03e8:	c422d6d8 */ 	lwc1	$f2,%lo(var7f1ad6d8)($at)
/*  f0c03ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c03f0:	00027602 */ 	srl	$t6,$v0,0x18
/*  f0c03f4:	01c4001b */ 	divu	$zero,$t6,$a0
/*  f0c03f8:	00007810 */ 	mfhi	$t7
/*  f0c03fc:	448f8000 */ 	mtc1	$t7,$f16
/*  f0c0400:	44812000 */ 	mtc1	$at,$f4
/*  f0c0404:	14800002 */ 	bnez	$a0,.L0f0c0410
/*  f0c0408:	00000000 */ 	nop
/*  f0c040c:	0007000d */ 	break	0x7
.L0f0c0410:
/*  f0c0410:	0002c202 */ 	srl	$t8,$v0,0x8
/*  f0c0414:	05e10005 */ 	bgez	$t7,.L0f0c042c
/*  f0c0418:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0c041c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0c0420:	44815000 */ 	mtc1	$at,$f10
/*  f0c0424:	00000000 */ 	nop
/*  f0c0428:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f0c042c:
/*  f0c042c:	0304001b */ 	divu	$zero,$t8,$a0
/*  f0c0430:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0c0434:	0000c810 */ 	mfhi	$t9
/*  f0c0438:	44995000 */ 	mtc1	$t9,$f10
/*  f0c043c:	3c017f1b */ 	lui	$at,%hi(var7f1ad6dc)
/*  f0c0440:	c430d6dc */ 	lwc1	$f16,%lo(var7f1ad6dc)($at)
/*  f0c0444:	3c014f80 */ 	lui	$at,0x4f80
/*  f0c0448:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0c044c:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f0c0450:	14800002 */ 	bnez	$a0,.L0f0c045c
/*  f0c0454:	00000000 */ 	nop
/*  f0c0458:	0007000d */ 	break	0x7
.L0f0c045c:
/*  f0c045c:	07210004 */ 	bgez	$t9,.L0f0c0470
/*  f0c0460:	00000000 */ 	nop
/*  f0c0464:	44812000 */ 	mtc1	$at,$f4
/*  f0c0468:	00000000 */ 	nop
/*  f0c046c:	46043180 */ 	add.s	$f6,$f6,$f4
.L0f0c0470:
/*  f0c0470:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0c0474:	c4640280 */ 	lwc1	$f4,0x280($v1)
/*  f0c0478:	3c017f1b */ 	lui	$at,%hi(var7f1ad6e0)
/*  f0c047c:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f0c0480:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f0c0484:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f0c0488:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f0c048c:	46088280 */ 	add.s	$f10,$f16,$f8
/*  f0c0490:	c430d6e0 */ 	lwc1	$f16,%lo(var7f1ad6e0)($at)
/*  f0c0494:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0c0498:	00000000 */ 	nop
/*  f0c049c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0c04a0:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f0c04a4:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0c04a8:	0fc0a57e */ 	jal	func0f0295f8
/*  f0c04ac:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0c04b0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c04b4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c04b8:	44813000 */ 	mtc1	$at,$f6
/*  f0c04bc:	c4600280 */ 	lwc1	$f0,0x280($v1)
/*  f0c04c0:	3c014270 */ 	lui	$at,0x4270
/*  f0c04c4:	3c05800b */ 	lui	$a1,%hi(var800ab58c)
/*  f0c04c8:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0c04cc:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0c04d0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0c04d4:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f0c04d8:	45000010 */ 	bc1f	.L0f0c051c
/*  f0c04dc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c04e0:	3c017f1b */ 	lui	$at,%hi(var7f1ad6e4)
/*  f0c04e4:	c422d6e4 */ 	lwc1	$f2,%lo(var7f1ad6e4)($at)
/*  f0c04e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c04ec:	44818000 */ 	mtc1	$at,$f16
/*  f0c04f0:	46020482 */ 	mul.s	$f18,$f0,$f2
/*  f0c04f4:	3c014248 */ 	lui	$at,0x4248
/*  f0c04f8:	44814000 */ 	mtc1	$at,$f8
/*  f0c04fc:	46128501 */ 	sub.s	$f20,$f16,$f18
/*  f0c0500:	46144102 */ 	mul.s	$f4,$f8,$f20
/*  f0c0504:	00000000 */ 	nop
/*  f0c0508:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0c050c:	00000000 */ 	nop
/*  f0c0510:	46145502 */ 	mul.s	$f20,$f10,$f20
/*  f0c0514:	1000000f */ 	b	.L0f0c0554
/*  f0c0518:	00000000 */ 	nop
.L0f0c051c:
/*  f0c051c:	44813000 */ 	mtc1	$at,$f6
/*  f0c0520:	3c017f1b */ 	lui	$at,%hi(var7f1ad6e8)
/*  f0c0524:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0c0528:	00000000 */ 	nop
/*  f0c052c:	4502000a */ 	bc1fl	.L0f0c0558
/*  f0c0530:	4600a20d */ 	trunc.w.s	$f8,$f20
/*  f0c0534:	c422d6e8 */ 	lwc1	$f2,%lo(var7f1ad6e8)($at)
/*  f0c0538:	3c01c1f0 */ 	lui	$at,0xc1f0
/*  f0c053c:	44819000 */ 	mtc1	$at,$f18
/*  f0c0540:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f0c0544:	46028502 */ 	mul.s	$f20,$f16,$f2
/*  f0c0548:	00000000 */ 	nop
/*  f0c054c:	46149502 */ 	mul.s	$f20,$f18,$f20
/*  f0c0550:	00000000 */ 	nop
.L0f0c0554:
/*  f0c0554:	4600a20d */ 	trunc.w.s	$f8,$f20
.L0f0c0558:
/*  f0c0558:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0c055c:	44024000 */ 	mfc1	$v0,$f8
/*  f0c0560:	00000000 */ 	nop
/*  f0c0564:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0c0568:	28810100 */ 	slti	$at,$a0,0x100
/*  f0c056c:	14200004 */ 	bnez	$at,.L0f0c0580
/*  f0c0570:	00000000 */ 	nop
/*  f0c0574:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f0c0578:	10000004 */ 	b	.L0f0c058c
/*  f0c057c:	afa40080 */ 	sw	$a0,0x80($sp)
.L0f0c0580:
/*  f0c0580:	04810002 */ 	bgez	$a0,.L0f0c058c
/*  f0c0584:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0c0588:	afa00080 */ 	sw	$zero,0x80($sp)
.L0f0c058c:
/*  f0c058c:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0c0590:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0c0594:	28810100 */ 	slti	$at,$a0,0x100
/*  f0c0598:	14200004 */ 	bnez	$at,.L0f0c05ac
/*  f0c059c:	00000000 */ 	nop
/*  f0c05a0:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f0c05a4:	10000004 */ 	b	.L0f0c05b8
/*  f0c05a8:	afa4007c */ 	sw	$a0,0x7c($sp)
.L0f0c05ac:
/*  f0c05ac:	04810002 */ 	bgez	$a0,.L0f0c05b8
/*  f0c05b0:	afa4007c */ 	sw	$a0,0x7c($sp)
/*  f0c05b4:	afa0007c */ 	sw	$zero,0x7c($sp)
.L0f0c05b8:
/*  f0c05b8:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0c05bc:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0c05c0:	28810100 */ 	slti	$at,$a0,0x100
/*  f0c05c4:	14200004 */ 	bnez	$at,.L0f0c05d8
/*  f0c05c8:	00000000 */ 	nop
/*  f0c05cc:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f0c05d0:	10000004 */ 	b	.L0f0c05e4
/*  f0c05d4:	afa40078 */ 	sw	$a0,0x78($sp)
.L0f0c05d8:
/*  f0c05d8:	04810002 */ 	bgez	$a0,.L0f0c05e4
/*  f0c05dc:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0c05e0:	afa00078 */ 	sw	$zero,0x78($sp)
.L0f0c05e4:
/*  f0c05e4:	3c017f1b */ 	lui	$at,%hi(var7f1ad6ec)
/*  f0c05e8:	c42ad6ec */ 	lwc1	$f10,%lo(var7f1ad6ec)($at)
/*  f0c05ec:	c4640280 */ 	lwc1	$f4,0x280($v1)
/*  f0c05f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c05f4:	44818000 */ 	mtc1	$at,$f16
/*  f0c05f8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0c05fc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c0600:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0c0604:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c0608:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0c060c:	8ca5b58c */ 	lw	$a1,%lo(var800ab58c)($a1)
/*  f0c0610:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0c0614:	46068501 */ 	sub.s	$f20,$f16,$f6
/*  f0c0618:	8fac0098 */ 	lw	$t4,0x98($sp)
/*  f0c061c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0c0620:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f0c0624:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0c0628:	afad0098 */ 	sw	$t5,0x98($sp)
/*  f0c062c:	3c0f0010 */ 	lui	$t7,0x10
/*  f0c0630:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0c0634:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0c0638:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f0c063c:	3c014348 */ 	lui	$at,0x4348
/*  f0c0640:	44819000 */ 	mtc1	$at,$f18
/*  f0c0644:	3c01432f */ 	lui	$at,0x432f
/*  f0c0648:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0c064c:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0c0650:	44815000 */ 	mtc1	$at,$f10
/*  f0c0654:	afb90098 */ 	sw	$t9,0x98($sp)
/*  f0c0658:	3c09b900 */ 	lui	$t1,0xb900
/*  f0c065c:	3c0a0c18 */ 	lui	$t2,0xc18
/*  f0c0660:	354a4340 */ 	ori	$t2,$t2,0x4340
/*  f0c0664:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0c0668:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0c066c:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f0c0670:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0c0674:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0c0678:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f0c067c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0c0680:	248c0008 */ 	addiu	$t4,$a0,0x8
/*  f0c0684:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f0c0688:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0c068c:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f0c0690:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0c0694:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0c0698:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f0c069c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0c06a0:	332900ff */ 	andi	$t1,$t9,0xff
/*  f0c06a4:	00095400 */ 	sll	$t2,$t1,0x10
/*  f0c06a8:	44092000 */ 	mfc1	$t1,$f4
/*  f0c06ac:	000fc600 */ 	sll	$t8,$t7,0x18
/*  f0c06b0:	030a5825 */ 	or	$t3,$t8,$t2
/*  f0c06b4:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0c06b8:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f0c06bc:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0c06c0:	016e7825 */ 	or	$t7,$t3,$t6
/*  f0c06c4:	313800ff */ 	andi	$t8,$t1,0xff
/*  f0c06c8:	01f85025 */ 	or	$t2,$t7,$t8
/*  f0c06cc:	ac8a0004 */ 	sw	$t2,0x4($a0)
/*  f0c06d0:	8fac0098 */ 	lw	$t4,0x98($sp)
/*  f0c06d4:	44199000 */ 	mfc1	$t9,$f18
/*  f0c06d8:	3c0bfa00 */ 	lui	$t3,0xfa00
/*  f0c06dc:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0c06e0:	afad0098 */ 	sw	$t5,0x98($sp)
/*  f0c06e4:	332900ff */ 	andi	$t1,$t9,0xff
/*  f0c06e8:	01217825 */ 	or	$t7,$t1,$at
/*  f0c06ec:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0c06f0:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*  f0c06f4:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f0c06f8:	3c0cfc12 */ 	lui	$t4,0xfc12
/*  f0c06fc:	3c0dffcf */ 	lui	$t5,0xffcf
/*  f0c0700:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0c0704:	afaa0098 */ 	sw	$t2,0x98($sp)
/*  f0c0708:	35adfe00 */ 	ori	$t5,$t5,0xfe00
/*  f0c070c:	358c9bff */ 	ori	$t4,$t4,0x9bff
/*  f0c0710:	3c03800b */ 	lui	$v1,%hi(var800ab58c)
/*  f0c0714:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0c0718:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f0c071c:	8c63b58c */ 	lw	$v1,%lo(var800ab58c)($v1)
/*  f0c0720:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c0724:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0c0728:	906b0005 */ 	lbu	$t3,0x5($v1)
/*  f0c072c:	90670004 */ 	lbu	$a3,0x4($v1)
/*  f0c0730:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0c0734:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c0738:	8dc2027c */ 	lw	$v0,0x27c($t6)
/*  f0c073c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c0740:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0c0744:	30590001 */ 	andi	$t9,$v0,0x1
/*  f0c0748:	304f0002 */ 	andi	$t7,$v0,0x2
/*  f0c074c:	304a0004 */ 	andi	$t2,$v0,0x4
/*  f0c0750:	000a602b */ 	sltu	$t4,$zero,$t2
/*  f0c0754:	000fc02b */ 	sltu	$t8,$zero,$t7
/*  f0c0758:	0019482b */ 	sltu	$t1,$zero,$t9
/*  f0c075c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0c0760:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0c0764:	0fc2c9d0 */ 	jal	func0f0b2740
/*  f0c0768:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0c076c:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c0770:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f0c0774:	3c014270 */ 	lui	$at,0x4270
/*  f0c0778:	c4680280 */ 	lwc1	$f8,0x280($v1)
/*  f0c077c:	44818000 */ 	mtc1	$at,$f16
/*  f0c0780:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c0784:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0c0788:	e46a0280 */ 	swc1	$f10,0x280($v1)
/*  f0c078c:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0c0790:	c4660280 */ 	lwc1	$f6,0x280($v1)
/*  f0c0794:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c0798:	00000000 */ 	nop
/*  f0c079c:	45020005 */ 	bc1fl	.L0f0c07b4
/*  f0c07a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0c07a4:	44819000 */ 	mtc1	$at,$f18
/*  f0c07a8:	00000000 */ 	nop
/*  f0c07ac:	e4720280 */ 	swc1	$f18,0x280($v1)
/*  f0c07b0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0c07b4:
/*  f0c07b4:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0c07b8:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f0c07bc:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0c07c0:	03e00008 */ 	jr	$ra
/*  f0c07c4:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

Gfx *func0f0c07c8(Gfx *gdl)
{
	if (g_Vars.currentplayer->cameramode == CAMERAMODE_THIRDPERSON) {
		gdl = func0f0aeed8(gdl);
		gdl = func0f15b114(gdl);
		gdl = hudRenderMessages(gdl);

		if (g_Vars.currentplayer->isdead == false) {
			gdl = currentPlayerDrawFade(gdl);
		}

		if (g_Vars.stagenum == STAGE_ESCAPE) {
			gdl = hudRenderGasIfEnabled(gdl);
		}

		return gdl;
	}

	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY) {
		func0f0a6c30();
		gdl = func0f0aeed8(gdl);
		func0f0a7138(&gdl);
		gdl = func0f0af158(gdl);

		if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
			gdl = func0f15b114(gdl);
		}

		if (var80061640 != 0) {
			gdl = func0f00a490(gdl);
		}

		if (g_Vars.stagenum == STAGE_ESCAPE) {
			gdl = hudRenderGasIfEnabled(gdl);
		}

		gdl = func0f0c0190(gdl);

		// Adjust eyes shutting
		if (g_Vars.currentplayer->eyesshut) {
			if (g_Vars.currentplayer->eyesshutfrac < 0.95f) {
				g_Vars.currentplayer->eyesshutfrac += g_Vars.lvupdate240freal * 0.12f;

				if (g_Vars.currentplayer->eyesshutfrac > 0.95f) {
					g_Vars.currentplayer->eyesshutfrac = 0.95f;
				}
			}
		} else {
			if (g_Vars.currentplayer->eyesshutfrac > 0) {
				g_Vars.currentplayer->eyesshutfrac -= g_Vars.lvupdate240freal * 0.12f;

				if (g_Vars.currentplayer->eyesshutfrac < 0) {
					g_Vars.currentplayer->eyesshutfrac = 0;
				}
			}
		}

		if (g_Vars.currentplayer->isdead == false
				&& var80070764 == 0
				&& (!g_Vars.currentplayer->eyespy || (g_Vars.currentplayer->eyespy && !g_Vars.currentplayer->eyespy->active))
				&& ((g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->unk1c54) & 1)) {
			gdl = func0f1472fc(gdl);
			gdl = func0f147570(gdl);
		} else if (g_Vars.currentplayer->isdead == false
				&& var80070764 == 0
				&& (!g_Vars.currentplayer->eyespy || (g_Vars.currentplayer->eyespy && !g_Vars.currentplayer->eyespy->active))
				&& ((g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->unk1c54) & 8)) {
			gdl = func0f147578(gdl);
			gdl = func0f14886c(gdl);
		}

		if (g_Vars.currentplayer->eyesshutfrac > 0) {
			gdl = fadeDraw(gdl, 0, 0, 0, g_Vars.currentplayer->eyesshutfrac);
		}
	}

	gdl = func0f0baf84(gdl);

	// Draw menu
	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY && g_Vars.currentplayer->mpmenuon) {
		s32 a = viGetViewLeft();
		s32 b = viGetViewTop();
		s32 c = viGetViewLeft() + viGetViewX();
		s32 d = viGetViewTop() + viGetViewY();

		gdl = func0f153628(gdl);
		gdl = func0f153a34(gdl, a, b, c, d, 160);
		gdl = func0f153780(gdl);
	}

	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
			&& currentPlayerIsHealthVisible()
			&& func0f0f0c68()) {
		gdl = hudRenderHealthBar(gdl);
	}

	if (g_Vars.normmplayerisrunning == false) {
		objectivesCheckAll();
	}

	if (g_Vars.currentplayer->isdead) {
		g_Vars.currentplayer->coopcanrestart = false;

		if (g_Vars.currentplayer->deathanimfinished == false) {
			bool pass = false;

			if (g_Vars.currentplayer->isdead == 1) {
				func0f11dd58(g_Vars.currentplayernum);
				g_Vars.currentplayer->isdead = 2;
				pass = true;
			}

			if (pass) {
				if (g_Vars.mplayerisrunning == false) {
					musicStartSoloDeath();
				} else {
					func0f16dd14();
				}
			} else {
				if (g_Vars.currentplayer->redbloodfinished) {
					currentPlayerSetFadeColour(0x96, 0, 0, 0.70588237f);
				} else {
					g_Vars.currentplayer->redbloodfinished = true;
				}
			}
		}

		if (modelGetCurAnimFrame(&g_Vars.currentplayer->model) >= modelGetAnimEndFrame(&g_Vars.currentplayer->model)
				&& g_Vars.currentplayer->redbloodfinished) {
			if (g_Vars.currentplayer->deathanimfinished == false) {
				g_Vars.currentplayer->deathanimfinished = true;
				currentPlayerAdjustFade(60, 0, 0, 0, 1);
				currentPlayerStartChrFade(120, 0);
			}

			if (currentPlayerIsFadeComplete()) {
				bool canrestart = false;

				if (g_Vars.mplayerisrunning) {
					if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
						// Coop or anti
						struct chrdata *chr = g_Vars.currentplayer->prop->chr;

						if (chr) {
							chr->chrflags |= CHRCFLAG_HIDDEN;
						}

						if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.anti) {
							// Anti
							if (contGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000) && !mpIsPaused()) {
								g_Vars.currentplayer->dostartnewlife = true;
							}
						} else {
							// Coop
							if (g_Vars.coopplayernum >= 0 &&
									(!g_Vars.bond->isdead || !g_Vars.coop->isdead)) {
								f32 totalhealth;
								u32 buddyplayernum = g_Vars.bondplayernum;
								u32 prevplayernum = g_Vars.currentplayernum;
								f32 stealhealth;
								f32 shield;

								canrestart = contGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000)
									&& !mpIsPaused();

								// Get ready to respawn.
								// The other player's health will be halved.
								buddyplayernum = g_Vars.currentplayer == g_Vars.coop ? g_Vars.bondplayernum : g_Vars.coopplayernum;

								setCurrentPlayerNum(buddyplayernum);
								shield = chrGetShield(g_Vars.currentplayer->prop->chr) * 0.125f;
								totalhealth = g_Vars.currentplayer->bondhealth + shield;

#if VERSION >= VERSION_NTSC_FINAL
								// NTSC final prevents coop from being able to respawn
								// in Deep Sea after the mid cutscene. Without this condition,
								// the player could respawn on the other side of the exit trigger.
								// Additionally, the logic for coopcanrestart is different.
								if (totalhealth > 0.125f
										&& !(mainGetStageNum() == STAGE_DEEPSEA && chrHasStageFlag(NULL, 0x00000200))) {
									if (canrestart) {
										func0f0bb69c();

										stealhealth = totalhealth * 0.5f;

										if (stealhealth < shield) {
											chrSetShield(g_Vars.currentplayer->prop->chr, (shield - stealhealth) * 8.0f);
										} else {
											chrSetShield(g_Vars.currentplayer->prop->chr, 0);
											g_Vars.currentplayer->bondhealth -= stealhealth - shield;
										}

										// Back to the player who died
										setCurrentPlayerNum(prevplayernum);
										g_Vars.currentplayer->dostartnewlife = true;
										g_Vars.currentplayer->oldhealth = 0;
										g_Vars.currentplayer->oldarmour = 0;
										g_Vars.currentplayer->apparenthealth = 0;
										g_Vars.currentplayer->apparentarmour = 0;
										g_Vars.currentplayer->stealhealth = stealhealth;
									} else {
										setCurrentPlayerNum(prevplayernum);
									}

									g_Vars.currentplayer->coopcanrestart = true;
								} else {
									// Can't respawn
									setCurrentPlayerNum(prevplayernum);
								}
#else
								if (totalhealth > 0.125f && canrestart) {
									func0f0bb69c();

									stealhealth = totalhealth * 0.5f;

									if (stealhealth < shield) {
										chrSetShield(g_Vars.currentplayer->prop->chr, (shield - stealhealth) * 8.0f);
									} else {
										chrSetShield(g_Vars.currentplayer->prop->chr, 0);
										g_Vars.currentplayer->bondhealth -= stealhealth - shield;
									}

									// Back to the player who died
									setCurrentPlayerNum(prevplayernum);
									g_Vars.currentplayer->dostartnewlife = true;
									g_Vars.currentplayer->oldhealth = 0;
									g_Vars.currentplayer->oldarmour = 0;
									g_Vars.currentplayer->apparenthealth = 0;
									g_Vars.currentplayer->apparentarmour = 0;
									g_Vars.currentplayer->stealhealth = stealhealth;
								} else {
									setCurrentPlayerNum(prevplayernum);
								}

								if (totalhealth > 0.125f) {
									g_Vars.currentplayer->coopcanrestart = true;
								}
#endif
							}
						}
					} else {
						u32 playernum = g_Vars.currentplayernum;
						s32 playercount = PLAYERCOUNT();
						struct chrdata *chr = g_Vars.currentplayer->prop->chr;
						s32 numdeaths = 0;
						s32 i;

						if (chr) {
							chr->chrflags |= CHRCFLAG_HIDDEN;
						}

						for (i = 0; i < playercount; i++) {
							numdeaths += g_Vars.playerstats[i].kills[playernum];
						}

						if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
							if (g_Vars.currentplayer->deadtimer < 0) {
								g_Vars.currentplayer->deadtimer = 600;
							}

							if (g_Vars.currentplayer->deadtimer >= 0) {
								g_Vars.currentplayer->deadtimer -= g_Vars.lvupdate240_60;

								if (g_Vars.currentplayer->deadtimer < 0) {
									canrestart = true;
								}
							}
						}

						if (contGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000)
								&& !mpIsPaused()
								&& g_NumReasonsToEndMpMatch == 0) {
							canrestart = true;
						}

						if (canrestart) {
							g_Vars.currentplayer->dostartnewlife = true;
						}
					}
				}
			}
		}
	}

	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY) {
		gdl = func0f0abcb0(gdl);

		if (getCurrentPlayerWeaponId(0) == WEAPON_HORIZONSCANNER) {
			gdl = hudRenderHorizonScanner(gdl);
		}

		if (optionsGetAmmoOnScreen(g_Vars.currentplayerstats->mpindex)) {
			gdl = hudRenderAmmo(gdl);
		}

		gdl = func0f18f874(gdl);
		gdl = hudRenderMessages(gdl);
		gdl = currentPlayerDrawFade(gdl);
	} else {
		gdl = func0f15b114(gdl);

		if (g_Vars.currentplayer->eyespy) {
			if (g_Vars.currentplayer->eyespy->startuptimer60 < 50) {
				gdl = hudRenderEyespyView(gdl, -1, 255, 0, g_Vars.currentplayer->eyespy->startuptimer60, g_Vars.currentplayer->eyespy->hit);
			} else {
				s32 time = g_Vars.currentplayer->eyespy->camerashuttertime;

				if (time > 0) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						gdl = hudRenderEyespyView(gdl, -1, 255, time, 50, g_Vars.currentplayer->eyespy->hit);
					} else {
						gdl = hudRenderEyespyView(gdl, -1, 255, 0, 50, g_Vars.currentplayer->eyespy->hit);
					}

					g_Vars.currentplayer->eyespy->camerashuttertime -= g_Vars.lvupdate240_60;
				} else {
					gdl = hudRenderEyespyView(gdl, -1, 255, 0, 50, g_Vars.currentplayer->eyespy->hit);
				}
			}

			gdl = hudRenderEyespyUi(gdl);
		}

		if (g_Vars.currentplayer->mpmenuon) {
			s32 a = viGetViewLeft();
			s32 b = viGetViewTop();
			s32 c = viGetViewLeft() + viGetViewX();
			s32 d = viGetViewTop() + viGetViewY();

			gdl = func0f153628(gdl);
			gdl = func0f153a34(gdl, a, b, c, d, 160);
			gdl = func0f153780(gdl);
		}

		gdl = hudRenderMessages(gdl);
		gdl = currentPlayerDrawFade(gdl);
	}

	return gdl;
}

void currentPlayerDie(bool force)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	s32 shooter;

	if (chr->lastshooter >= 0 && chr->timeshooter > 0) {
		shooter = chr->lastshooter;
	} else {
		shooter = g_Vars.currentplayernum;
	}

	currentPlayerDieByShooter(shooter, force);
}

void currentPlayerDieByShooter(u32 shooter, bool force)
{
	if (!g_Vars.currentplayer->isdead &&
			(force || !g_Vars.currentplayer->invincible)) {
		u32 prevplayernum = g_MpPlayerNum;
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
		func0f0f8120();
		g_MpPlayerNum = prevplayernum;

		hudmsgRemoveForDeadPlayer(g_Vars.currentplayernum);

		if (g_Vars.mplayerisrunning) {
			func0f0b09f4(shooter, g_Vars.currentplayernum);
		}

		chrUncloak(g_Vars.currentplayer->prop->chr, true);

		if (g_Vars.mplayerisrunning &&
				(g_Vars.antiplayernum < 0
				 || g_Vars.currentplayernum != g_Vars.antiplayernum
				 || shooter != g_Vars.antiplayernum)) {
			func0f0910ac();
		}

		g_Vars.currentplayer->isdead = true;
		g_Vars.currentplayer->bonddie = g_Vars.currentplayer->bond2;
		g_Vars.currentplayer->thetadie = g_Vars.currentplayer->vv_theta;
		g_Vars.currentplayer->vertadie = g_Vars.currentplayer->vv_verta;
		g_Vars.currentplayer->posdie.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->posdie.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->posdie.z = g_Vars.currentplayer->prop->pos.z;

		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
			if (g_Vars.currentplayer->unk1af0) {
				g_Vars.currentplayer->bondtankexplode = true;
			}
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
			g_Vars.currentplayer->bondtankexplode = true;
		}

		currentPlayerSetMoveMode(MOVEMODE_WALK);
		func0f0a29c8();

		if (getMissionTime() - g_Vars.currentplayer->lifestarttime60 < g_Vars.currentplayerstats->shortestlife) {
			g_Vars.currentplayerstats->shortestlife = getMissionTime() - g_Vars.currentplayer->lifestarttime60;
		}

		g_Vars.currentplayer->lifestarttime60 = getMissionTime();
	}
}

GLOBAL_ASM(
glabel func0f0c160c
.late_rodata
glabel var7f1ad6fc
.word 0x40490fdb
.text
/*  f0c160c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c1610:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c1614:	8c6e0318 */ 	lw	$t6,0x318($v1)
/*  f0c1618:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0c161c:	44856000 */ 	mtc1	$a1,$f12
/*  f0c1620:	44867000 */ 	mtc1	$a2,$f14
/*  f0c1624:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c1628:	11c0002e */ 	beqz	$t6,.L0f0c16e4
/*  f0c162c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0c1630:	8c6f028c */ 	lw	$t7,0x28c($v1)
/*  f0c1634:	0fc259d4 */ 	jal	func0f096750
/*  f0c1638:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0c163c:	3c014334 */ 	lui	$at,0x4334
/*  f0c1640:	44812000 */ 	mtc1	$at,$f4
/*  f0c1644:	3c017f1b */ 	lui	$at,%hi(var7f1ad6fc)
/*  f0c1648:	c428d6fc */ 	lwc1	$f8,%lo(var7f1ad6fc)($at)
/*  f0c164c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0c1650:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f0c1654:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c1658:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c165c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c1660:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0c1664:	44818000 */ 	mtc1	$at,$f16
/*  f0c1668:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0c166c:	00794021 */ 	addu	$t0,$v1,$t9
/*  f0c1670:	8d090064 */ 	lw	$t1,0x64($t0)
/*  f0c1674:	44803000 */ 	mtc1	$zero,$f6
/*  f0c1678:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f0c167c:	c5240144 */ 	lwc1	$f4,0x144($t1)
/*  f0c1680:	3c0142b4 */ 	lui	$at,0x42b4
/*  f0c1684:	44814000 */ 	mtc1	$at,$f8
/*  f0c1688:	000a59c0 */ 	sll	$t3,$t2,0x7
/*  f0c168c:	3c014387 */ 	lui	$at,0x4387
/*  f0c1690:	006b1021 */ 	addu	$v0,$v1,$t3
/*  f0c1694:	460a8481 */ 	sub.s	$f18,$f16,$f10
/*  f0c1698:	46122081 */ 	sub.s	$f2,$f4,$f18
/*  f0c169c:	4606103c */ 	c.lt.s	$f2,$f6
/*  f0c16a0:	00000000 */ 	nop
/*  f0c16a4:	45020003 */ 	bc1fl	.L0f0c16b4
/*  f0c16a8:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0c16ac:	46001087 */ 	neg.s	$f2,$f2
/*  f0c16b0:	4608103c */ 	c.lt.s	$f2,$f8
.L0f0c16b4:
/*  f0c16b4:	00000000 */ 	nop
/*  f0c16b8:	45030008 */ 	bc1tl	.L0f0c16dc
/*  f0c16bc:	8c4c00b0 */ 	lw	$t4,0xb0($v0)
/*  f0c16c0:	44818000 */ 	mtc1	$at,$f16
/*  f0c16c4:	00000000 */ 	nop
/*  f0c16c8:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0c16cc:	00000000 */ 	nop
/*  f0c16d0:	45020005 */ 	bc1fl	.L0f0c16e8
/*  f0c16d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c16d8:	8c4c00b0 */ 	lw	$t4,0xb0($v0)
.L0f0c16dc:
/*  f0c16dc:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0c16e0:	ac4d00b0 */ 	sw	$t5,0xb0($v0)
.L0f0c16e4:
/*  f0c16e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c16e8:
/*  f0c16e8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0c16ec:	03e00008 */ 	jr	$ra
/*  f0c16f0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel currentPlayerGetHealthBarHeightFrac
/*  f0c16f4:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f0c16f8:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f0c16fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1700:	8c6200fc */ 	lw	$v0,0xfc($v1)
/*  f0c1704:	50400008 */ 	beqzl	$v0,.L0f0c1728
/*  f0c1708:	44800000 */ 	mtc1	$zero,$f0
/*  f0c170c:	10410008 */ 	beq	$v0,$at,.L0f0c1730
/*  f0c1710:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c1714:	50410014 */ 	beql	$v0,$at,.L0f0c1768
/*  f0c1718:	8c791924 */ 	lw	$t9,0x1924($v1)
/*  f0c171c:	10000027 */ 	b	.L0f0c17bc
/*  f0c1720:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c1724:	44800000 */ 	mtc1	$zero,$f0
.L0f0c1728:
/*  f0c1728:	03e00008 */ 	jr	$ra
/*  f0c172c:	00000000 */ 	nop
.L0f0c1730:
/*  f0c1730:	8c6e1924 */ 	lw	$t6,0x1924($v1)
/*  f0c1734:	3c188007 */ 	lui	$t8,%hi(g_HealthDamageTypes)
/*  f0c1738:	c46c00f8 */ 	lwc1	$f12,0xf8($v1)
/*  f0c173c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0c1740:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0c1744:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0c1748:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0c174c:	8f180924 */ 	lw	$t8,%lo(g_HealthDamageTypes)($t8)
/*  f0c1750:	44982000 */ 	mtc1	$t8,$f4
/*  f0c1754:	00000000 */ 	nop
/*  f0c1758:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f0c175c:	03e00008 */ 	jr	$ra
/*  f0c1760:	46026003 */ 	div.s	$f0,$f12,$f2
/*  f0c1764:	8c791924 */ 	lw	$t9,0x1924($v1)
.L0f0c1768:
/*  f0c1768:	3c098007 */ 	lui	$t1,%hi(g_HealthDamageTypes)
/*  f0c176c:	25290924 */ 	addiu	$t1,$t1,%lo(g_HealthDamageTypes)
/*  f0c1770:	00194080 */ 	sll	$t0,$t9,0x2
/*  f0c1774:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0c1778:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0c177c:	01091021 */ 	addu	$v0,$t0,$t1
/*  f0c1780:	8c44000c */ 	lw	$a0,0xc($v0)
/*  f0c1784:	8c4a0010 */ 	lw	$t2,0x10($v0)
/*  f0c1788:	c46800f8 */ 	lwc1	$f8,0xf8($v1)
/*  f0c178c:	44845000 */ 	mtc1	$a0,$f10
/*  f0c1790:	01445823 */ 	subu	$t3,$t2,$a0
/*  f0c1794:	448b3000 */ 	mtc1	$t3,$f6
/*  f0c1798:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c179c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c17a0:	44819000 */ 	mtc1	$at,$f18
/*  f0c17a4:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0c17a8:	46104301 */ 	sub.s	$f12,$f8,$f16
/*  f0c17ac:	46026103 */ 	div.s	$f4,$f12,$f2
/*  f0c17b0:	03e00008 */ 	jr	$ra
/*  f0c17b4:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f0c17b8:	3c013f80 */ 	lui	$at,0x3f80
.L0f0c17bc:
/*  f0c17bc:	44810000 */ 	mtc1	$at,$f0
/*  f0c17c0:	00000000 */ 	nop
/*  f0c17c4:	03e00008 */ 	jr	$ra
/*  f0c17c8:	00000000 */ 	nop
);

/**
 * Determines what height the health bar should have. The function is called
 * while any menu is open and any time when the health bar should be shown.
 *
 * A return value of 0 means zero height, while 1 means full expanded height.
 */
// regalloc
//f32 currentPlayerGetHealthBarHeightFrac(void)
//{
//	switch (g_Vars.currentplayer->healthshowmode) {
//	case HEALTHSHOWMODE_HIDDEN:
//		return 0;
//	case HEALTHSHOWMODE_OPENING: // 730
//		{
//			f32 duration = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].openduration;
//			return g_Vars.currentplayer->healthshowtime / duration;
//		}
//	case HEALTHSHOWMODE_CLOSING: // 768
//		{
//			f32 value =
//				(g_Vars.currentplayer->healthshowtime - g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].unk0c) /
//				(g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].unk10 - g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].unk0c);
//
//			return 1 - value;
//		}
//	}
//
//	return 1;
//}

bool currentPlayerIsHealthVisible(void)
{
	return g_Vars.currentplayer->healthshowmode != HEALTHSHOWMODE_HIDDEN;
}

// Never called
void setInvincible(bool enable)
{
	if (enable) {
		cheatActivate(CHEAT_INVINCIBLE);
	} else {
		cheatDeactivate(CHEAT_INVINCIBLE);
	}
}

void setGvars324(s32 arg0)
{
	g_Vars.unk000324 = arg0;
}

void setGvars328(s32 arg0)
{
	g_Vars.unk000328 = arg0;
}

void currentPlayerSetCameraMode(s32 mode)
{
	g_Vars.currentplayer->cameramode = mode;
}

GLOBAL_ASM(
glabel func0f0c1840
/*  f0c1840:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f0c1844:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0c1848:	8fb000d0 */ 	lw	$s0,0xd0($sp)
/*  f0c184c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0c1850:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0c1854:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c1858:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0c185c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0c1860:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0c1864:	afa500c4 */ 	sw	$a1,0xc4($sp)
/*  f0c1868:	afa600c8 */ 	sw	$a2,0xc8($sp)
/*  f0c186c:	1200007f */ 	beqz	$s0,.L0f0c1a6c
/*  f0c1870:	afa000bc */ 	sw	$zero,0xbc($sp)
/*  f0c1874:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f0c1878:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f0c187c:	27b20054 */ 	addiu	$s2,$sp,0x54
/*  f0c1880:	122e007a */ 	beq	$s1,$t6,.L0f0c1a6c
/*  f0c1884:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0c1888:	02802825 */ 	or	$a1,$s4,$zero
/*  f0c188c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0c1890:	02403825 */ 	or	$a3,$s2,$zero
/*  f0c1894:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0c1898:	0c006052 */ 	jal	func00018148
/*  f0c189c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0c18a0:	87af0054 */ 	lh	$t7,0x54($sp)
/*  f0c18a4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c18a8:	27b00054 */ 	addiu	$s0,$sp,0x54
/*  f0c18ac:	522f001e */ 	beql	$s1,$t7,.L0f0c1928
/*  f0c18b0:	87ab0054 */ 	lh	$t3,0x54($sp)
/*  f0c18b4:	86050000 */ 	lh	$a1,0x0($s0)
/*  f0c18b8:	02802025 */ 	or	$a0,$s4,$zero
.L0f0c18bc:
/*  f0c18bc:	0fc586b7 */ 	jal	func0f161adc
/*  f0c18c0:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0c18c4:	14400012 */ 	bnez	$v0,.L0f0c1910
/*  f0c18c8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0c18cc:	86190002 */ 	lh	$t9,0x2($s0)
/*  f0c18d0:	24c40001 */ 	addiu	$a0,$a2,0x1
/*  f0c18d4:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0c18d8:	1239000a */ 	beq	$s1,$t9,.L0f0c1904
/*  f0c18dc:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f0c18e0:	00044040 */ 	sll	$t0,$a0,0x1
/*  f0c18e4:	02481021 */ 	addu	$v0,$s2,$t0
/*  f0c18e8:	84430000 */ 	lh	$v1,0x0($v0)
/*  f0c18ec:	a443fffe */ 	sh	$v1,-0x2($v0)
.L0f0c18f0:
/*  f0c18f0:	84430002 */ 	lh	$v1,0x2($v0)
/*  f0c18f4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0c18f8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0c18fc:	5623fffc */ 	bnel	$s1,$v1,.L0f0c18f0
/*  f0c1900:	a443fffe */ 	sh	$v1,-0x2($v0)
.L0f0c1904:
/*  f0c1904:	00044840 */ 	sll	$t1,$a0,0x1
/*  f0c1908:	02495021 */ 	addu	$t2,$s2,$t1
/*  f0c190c:	a551fffe */ 	sh	$s1,-0x2($t2)
.L0f0c1910:
/*  f0c1910:	86050002 */ 	lh	$a1,0x2($s0)
/*  f0c1914:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0c1918:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0c191c:	5625ffe7 */ 	bnel	$s1,$a1,.L0f0c18bc
/*  f0c1920:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1924:	87ab0054 */ 	lh	$t3,0x54($sp)
.L0f0c1928:
/*  f0c1928:	87ac0056 */ 	lh	$t4,0x56($sp)
/*  f0c192c:	522b000a */ 	beql	$s1,$t3,.L0f0c1958
/*  f0c1930:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0c1934:	162c0007 */ 	bne	$s1,$t4,.L0f0c1954
/*  f0c1938:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c193c:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1940:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1944:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0c1948:	01603825 */ 	or	$a3,$t3,$zero
/*  f0c194c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c1950:	afad00bc */ 	sw	$t5,0xbc($sp)
.L0f0c1954:
/*  f0c1954:	8fae00bc */ 	lw	$t6,0xbc($sp)
.L0f0c1958:
/*  f0c1958:	87af0054 */ 	lh	$t7,0x54($sp)
/*  f0c195c:	55c00021 */ 	bnezl	$t6,.L0f0c19e4
/*  f0c1960:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f0c1964:	122f001e */ 	beq	$s1,$t7,.L0f0c19e0
/*  f0c1968:	27b00054 */ 	addiu	$s0,$sp,0x54
/*  f0c196c:	3c12800a */ 	lui	$s2,%hi(g_Rooms)
/*  f0c1970:	26524928 */ 	addiu	$s2,$s2,%lo(g_Rooms)
/*  f0c1974:	86050000 */ 	lh	$a1,0x0($s0)
/*  f0c1978:	2413008c */ 	addiu	$s3,$zero,0x8c
.L0f0c197c:
/*  f0c197c:	00b30019 */ 	multu	$a1,$s3
/*  f0c1980:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0c1984:	00004012 */ 	mflo	$t0
/*  f0c1988:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0c198c:	952a0000 */ 	lhu	$t2,0x0($t1)
/*  f0c1990:	314c0010 */ 	andi	$t4,$t2,0x10
/*  f0c1994:	5580000f */ 	bnezl	$t4,.L0f0c19d4
/*  f0c1998:	86050002 */ 	lh	$a1,0x2($s0)
/*  f0c199c:	0fc5884a */ 	jal	func0f162128
/*  f0c19a0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c19a4:	5040000b */ 	beqzl	$v0,.L0f0c19d4
/*  f0c19a8:	86050002 */ 	lh	$a1,0x2($s0)
/*  f0c19ac:	86070000 */ 	lh	$a3,0x0($s0)
/*  f0c19b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c19b4:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f0c19b8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c19bc:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c19c0:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0c19c4:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c19c8:	10000006 */ 	b	.L0f0c19e4
/*  f0c19cc:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f0c19d0:	86050002 */ 	lh	$a1,0x2($s0)
.L0f0c19d4:
/*  f0c19d4:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0c19d8:	1625ffe8 */ 	bne	$s1,$a1,.L0f0c197c
/*  f0c19dc:	00000000 */ 	nop
.L0f0c19e0:
/*  f0c19e0:	8fad00bc */ 	lw	$t5,0xbc($sp)
.L0f0c19e4:
/*  f0c19e4:	3c12800a */ 	lui	$s2,%hi(g_Rooms)
/*  f0c19e8:	26524928 */ 	addiu	$s2,$s2,%lo(g_Rooms)
/*  f0c19ec:	15a0001f */ 	bnez	$t5,.L0f0c1a6c
/*  f0c19f0:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f0c19f4:	87ae0054 */ 	lh	$t6,0x54($sp)
/*  f0c19f8:	27b00054 */ 	addiu	$s0,$sp,0x54
/*  f0c19fc:	522e001c */ 	beql	$s1,$t6,.L0f0c1a70
/*  f0c1a00:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f0c1a04:	86050000 */ 	lh	$a1,0x0($s0)
.L0f0c1a08:
/*  f0c1a08:	00b30019 */ 	multu	$a1,$s3
/*  f0c1a0c:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0c1a10:	0000c812 */ 	mflo	$t9
/*  f0c1a14:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0c1a18:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f0c1a1c:	312a0010 */ 	andi	$t2,$t1,0x10
/*  f0c1a20:	5140000f */ 	beqzl	$t2,.L0f0c1a60
/*  f0c1a24:	86050002 */ 	lh	$a1,0x2($s0)
/*  f0c1a28:	0fc5884a */ 	jal	func0f162128
/*  f0c1a2c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1a30:	5040000b */ 	beqzl	$v0,.L0f0c1a60
/*  f0c1a34:	86050002 */ 	lh	$a1,0x2($s0)
/*  f0c1a38:	86070000 */ 	lh	$a3,0x0($s0)
/*  f0c1a3c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0c1a40:	afac00bc */ 	sw	$t4,0xbc($sp)
/*  f0c1a44:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1a48:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1a4c:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0c1a50:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1a54:	10000006 */ 	b	.L0f0c1a70
/*  f0c1a58:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f0c1a5c:	86050002 */ 	lh	$a1,0x2($s0)
.L0f0c1a60:
/*  f0c1a60:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0c1a64:	1625ffe8 */ 	bne	$s1,$a1,.L0f0c1a08
/*  f0c1a68:	00000000 */ 	nop
.L0f0c1a6c:
/*  f0c1a6c:	8fab00bc */ 	lw	$t3,0xbc($sp)
.L0f0c1a70:
/*  f0c1a70:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f0c1a74:	27b00090 */ 	addiu	$s0,$sp,0x90
/*  f0c1a78:	15600042 */ 	bnez	$t3,.L0f0c1b84
/*  f0c1a7c:	27b20064 */ 	addiu	$s2,$sp,0x64
/*  f0c1a80:	27ad0052 */ 	addiu	$t5,$sp,0x52
/*  f0c1a84:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0c1a88:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1a8c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0c1a90:	02403025 */ 	or	$a2,$s2,$zero
/*  f0c1a94:	0fc58865 */ 	jal	func0f162194
/*  f0c1a98:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f0c1a9c:	87ae0090 */ 	lh	$t6,0x90($sp)
/*  f0c1aa0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1aa4:	87b80064 */ 	lh	$t8,0x64($sp)
/*  f0c1aa8:	122e0014 */ 	beq	$s1,$t6,.L0f0c1afc
/*  f0c1aac:	00000000 */ 	nop
/*  f0c1ab0:	0c00a900 */ 	jal	func0002a400
/*  f0c1ab4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0c1ab8:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0c1abc:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f0c1ac0:	18400007 */ 	blez	$v0,.L0f0c1ae0
/*  f0c1ac4:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0c1ac8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1acc:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1ad0:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0c1ad4:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1ad8:	1000002b */ 	b	.L0f0c1b88
/*  f0c1adc:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c1ae0:
/*  f0c1ae0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1ae4:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1ae8:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1aec:	0fc30709 */ 	jal	currentPlayerSetCamPropertiesWithRoom
/*  f0c1af0:	87a70090 */ 	lh	$a3,0x90($sp)
/*  f0c1af4:	10000024 */ 	b	.L0f0c1b88
/*  f0c1af8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c1afc:
/*  f0c1afc:	12380015 */ 	beq	$s1,$t8,.L0f0c1b54
/*  f0c1b00:	87a70052 */ 	lh	$a3,0x52($sp)
/*  f0c1b04:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1b08:	0c00a900 */ 	jal	func0002a400
/*  f0c1b0c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0c1b10:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0c1b14:	0007cc03 */ 	sra	$t9,$a3,0x10
/*  f0c1b18:	18400007 */ 	blez	$v0,.L0f0c1b38
/*  f0c1b1c:	03203825 */ 	or	$a3,$t9,$zero
/*  f0c1b20:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1b24:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1b28:	0fc3071d */ 	jal	currentPlayerSetCamPropertiesWithoutRoom
/*  f0c1b2c:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1b30:	10000015 */ 	b	.L0f0c1b88
/*  f0c1b34:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c1b38:
/*  f0c1b38:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1b3c:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1b40:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1b44:	0fc3071d */ 	jal	currentPlayerSetCamPropertiesWithoutRoom
/*  f0c1b48:	87a70064 */ 	lh	$a3,0x64($sp)
/*  f0c1b4c:	1000000e */ 	b	.L0f0c1b88
/*  f0c1b50:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c1b54:
/*  f0c1b54:	10f10007 */ 	beq	$a3,$s1,.L0f0c1b74
/*  f0c1b58:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1b5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0c1b60:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1b64:	0fc3071d */ 	jal	currentPlayerSetCamPropertiesWithoutRoom
/*  f0c1b68:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1b6c:	10000006 */ 	b	.L0f0c1b88
/*  f0c1b70:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c1b74:
/*  f0c1b74:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*  f0c1b78:	8fa600c8 */ 	lw	$a2,0xc8($sp)
/*  f0c1b7c:	0fc3071d */ 	jal	currentPlayerSetCamPropertiesWithoutRoom
/*  f0c1b80:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0c1b84:
/*  f0c1b84:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c1b88:
/*  f0c1b88:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0c1b8c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0c1b90:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0c1b94:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0c1b98:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0c1b9c:	03e00008 */ 	jr	$ra
/*  f0c1ba0:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

void func0f0c1ba4(struct coord *pos, struct coord *up, struct coord *look, struct coord *memcampos, s32 memcamroom)
{
	s16 rooms[2];
	rooms[0] = memcamroom;
	rooms[1] = -1;

	func0f0c1840(pos, up, look, memcampos, rooms);
}

void func0f0c1bd8(struct coord *pos, struct coord *up, struct coord *look)
{
	if (g_Vars.currentplayer->memcamroom >= 0) {
		func0f0c1ba4(pos, up, look, &g_Vars.currentplayer->memcampos, g_Vars.currentplayer->memcamroom);
	} else {
		func0f0c1840(pos, up, look, NULL, NULL);
	}
}

void currentPlayerSetCamPropertiesWithRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	g_Vars.currentplayer->memcampos.x = pos->x;
	g_Vars.currentplayer->memcampos.y = pos->y;
	g_Vars.currentplayer->memcampos.z = pos->z;
	g_Vars.currentplayer->memcamroom = room;
	currentPlayerSetCamProperties(pos, up, look, room);
}

void currentPlayerSetCamPropertiesWithoutRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	currentPlayerClearMemCamRoom();
	currentPlayerSetCamProperties(pos, up, look, room);
}

void currentPlayerSetCamProperties(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	struct player *player = g_Vars.currentplayer;
	player->cam_pos.x = pos->x;
	player->cam_pos.y = pos->y;
	player->cam_pos.z = pos->z;
	player->cam_up.x = up->x;
	player->cam_up.y = up->y;
	player->cam_up.z = up->z;
	player->cam_look.x = look->x;
	player->cam_look.y = look->y;
	player->cam_look.z = look->z;
	player->cam_room = room;
}

void currentPlayerClearMemCamRoom(void)
{
	g_Vars.currentplayer->memcamroom = -1;
}

GLOBAL_ASM(
glabel func0f0c1d20
/*  f0c1d20:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0c1d24:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c1d28:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0c1d2c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0c1d30:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0c1d34:	8e0e028c */ 	lw	$t6,0x28c($s0)
/*  f0c1d38:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c1d3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c1d40:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c1d44:	11e00003 */ 	beqz	$t7,.L0f0c1d54
/*  f0c1d48:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0c1d4c:	10000002 */ 	b	.L0f0c1d58
/*  f0c1d50:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c1d54:
/*  f0c1d54:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c1d58:
/*  f0c1d58:	8e180068 */ 	lw	$t8,0x68($s0)
/*  f0c1d5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c1d60:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c1d64:	13000003 */ 	beqz	$t8,.L0f0c1d74
/*  f0c1d68:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c1d6c:	10000001 */ 	b	.L0f0c1d74
/*  f0c1d70:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c1d74:
/*  f0c1d74:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f0c1d78:	13200003 */ 	beqz	$t9,.L0f0c1d88
/*  f0c1d7c:	00000000 */ 	nop
/*  f0c1d80:	10000001 */ 	b	.L0f0c1d88
/*  f0c1d84:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c1d88:
/*  f0c1d88:	8e080070 */ 	lw	$t0,0x70($s0)
/*  f0c1d8c:	11000003 */ 	beqz	$t0,.L0f0c1d9c
/*  f0c1d90:	00000000 */ 	nop
/*  f0c1d94:	10000001 */ 	b	.L0f0c1d9c
/*  f0c1d98:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c1d9c:
/*  f0c1d9c:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0c1da0:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0c1da4:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0c1da8:	19600023 */ 	blez	$t3,.L0f0c1e38
/*  f0c1dac:	00000000 */ 	nop
.L0f0c1db0:
/*  f0c1db0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0c1db4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0c1db8:	0fc30743 */ 	jal	currentPlayerClearMemCamRoom
/*  f0c1dbc:	00000000 */ 	nop
/*  f0c1dc0:	8e0c006c */ 	lw	$t4,0x6c($s0)
/*  f0c1dc4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0c1dc8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c1dcc:	11800003 */ 	beqz	$t4,.L0f0c1ddc
/*  f0c1dd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c1dd4:	10000001 */ 	b	.L0f0c1ddc
/*  f0c1dd8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c1ddc:
/*  f0c1ddc:	8e0d0068 */ 	lw	$t5,0x68($s0)
/*  f0c1de0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c1de4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c1de8:	11a00003 */ 	beqz	$t5,.L0f0c1df8
/*  f0c1dec:	00000000 */ 	nop
/*  f0c1df0:	10000001 */ 	b	.L0f0c1df8
/*  f0c1df4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c1df8:
/*  f0c1df8:	8e0e0064 */ 	lw	$t6,0x64($s0)
/*  f0c1dfc:	11c00003 */ 	beqz	$t6,.L0f0c1e0c
/*  f0c1e00:	00000000 */ 	nop
/*  f0c1e04:	10000001 */ 	b	.L0f0c1e0c
/*  f0c1e08:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c1e0c:
/*  f0c1e0c:	8e0f0070 */ 	lw	$t7,0x70($s0)
/*  f0c1e10:	11e00003 */ 	beqz	$t7,.L0f0c1e20
/*  f0c1e14:	00000000 */ 	nop
/*  f0c1e18:	10000001 */ 	b	.L0f0c1e20
/*  f0c1e1c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c1e20:
/*  f0c1e20:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0c1e24:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0c1e28:	03254021 */ 	addu	$t0,$t9,$a1
/*  f0c1e2c:	0228082a */ 	slt	$at,$s1,$t0
/*  f0c1e30:	1420ffdf */ 	bnez	$at,.L0f0c1db0
/*  f0c1e34:	00000000 */ 	nop
.L0f0c1e38:
/*  f0c1e38:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0c1e3c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f0c1e40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c1e44:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0c1e48:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0c1e4c:	03e00008 */ 	jr	$ra
/*  f0c1e50:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

void func0f0c1e54(struct prop *prop, bool enable)
{
	u32 playernum = propGetPlayerNum(prop);

	if (g_Vars.players[playernum]->haschrbody) {
		chrSetOrUnsetHiddenFlag00000100(prop->chr, enable);
	}

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		if (g_Vars.currentplayer->unk1af0) {
			propObjSetOrUnsetHiddenFlag00400000(g_Vars.currentplayer->unk1af0, enable);
		}
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		propObjSetOrUnsetHiddenFlag00400000(g_Vars.currentplayer->hoverbike, enable);
	}

	g_Vars.players[playernum]->bondperimenabled = enable;
}

GLOBAL_ASM(
glabel func0f0c1f08
/*  f0c1f08:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c1f0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c1f10:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0c1f14:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c1f18:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0c1f1c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0c1f20:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0c1f24:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0c1f28:	00ce2021 */ 	addu	$a0,$a2,$t6
/*  f0c1f2c:	8c830064 */ 	lw	$v1,0x64($a0)
/*  f0c1f30:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0c1f34:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f0c1f38:	8c6f00c0 */ 	lw	$t7,0xc0($v1)
/*  f0c1f3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c1f40:	51e00027 */ 	beqzl	$t7,.L0f0c1fe0
/*  f0c1f44:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0c1f48:	8cd80314 */ 	lw	$t8,0x314($a2)
/*  f0c1f4c:	53000005 */ 	beqzl	$t8,.L0f0c1f64
/*  f0c1f50:	8cc8048c */ 	lw	$t0,0x48c($a2)
/*  f0c1f54:	8c7900d8 */ 	lw	$t9,0xd8($v1)
/*  f0c1f58:	57200021 */ 	bnezl	$t9,.L0f0c1fe0
/*  f0c1f5c:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0c1f60:	8cc8048c */ 	lw	$t0,0x48c($a2)
.L0f0c1f64:
/*  f0c1f64:	51000017 */ 	beqzl	$t0,.L0f0c1fc4
/*  f0c1f68:	246f19cc */ 	addiu	$t7,$v1,0x19cc
/*  f0c1f6c:	8c6119cc */ 	lw	$at,0x19cc($v1)
/*  f0c1f70:	8c6b19d0 */ 	lw	$t3,0x19d0($v1)
/*  f0c1f74:	ac6119e4 */ 	sw	$at,0x19e4($v1)
/*  f0c1f78:	8c6119d4 */ 	lw	$at,0x19d4($v1)
/*  f0c1f7c:	ac6b19e8 */ 	sw	$t3,0x19e8($v1)
/*  f0c1f80:	8c6b19d8 */ 	lw	$t3,0x19d8($v1)
/*  f0c1f84:	ac6119ec */ 	sw	$at,0x19ec($v1)
/*  f0c1f88:	8c6119dc */ 	lw	$at,0x19dc($v1)
/*  f0c1f8c:	ac6b19f0 */ 	sw	$t3,0x19f0($v1)
/*  f0c1f90:	8c6b19e0 */ 	lw	$t3,0x19e0($v1)
/*  f0c1f94:	ac6119f4 */ 	sw	$at,0x19f4($v1)
/*  f0c1f98:	3c014170 */ 	lui	$at,0x4170
/*  f0c1f9c:	ac6b19f8 */ 	sw	$t3,0x19f8($v1)
/*  f0c1fa0:	8c8c0064 */ 	lw	$t4,0x64($a0)
/*  f0c1fa4:	44812000 */ 	mtc1	$at,$f4
/*  f0c1fa8:	00000000 */ 	nop
/*  f0c1fac:	e58419f8 */ 	swc1	$f4,0x19f8($t4)
/*  f0c1fb0:	8c8d0064 */ 	lw	$t5,0x64($a0)
/*  f0c1fb4:	25ae19e4 */ 	addiu	$t6,$t5,0x19e4
/*  f0c1fb8:	10000003 */ 	b	.L0f0c1fc8
/*  f0c1fbc:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f0c1fc0:	246f19cc */ 	addiu	$t7,$v1,0x19cc
.L0f0c1fc4:
/*  f0c1fc4:	acaf0000 */ 	sw	$t7,0x0($a1)
.L0f0c1fc8:
/*  f0c1fc8:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0c1fcc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0c1fd0:	27190018 */ 	addiu	$t9,$t8,0x18
/*  f0c1fd4:	10000003 */ 	b	.L0f0c1fe4
/*  f0c1fd8:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f0c1fdc:	ace00000 */ 	sw	$zero,0x0($a3)
.L0f0c1fe0:
/*  f0c1fe0:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0c1fe4:
/*  f0c1fe4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c1fe8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c1fec:	03e00008 */ 	jr	$ra
/*  f0c1ff0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0c1ff4
/*  f0c1ff4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c1ff8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c1ffc:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0c2000:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0c2004:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0c2008:	a1ee19cc */ 	sb	$t6,0x19cc($t7)
/*  f0c200c:	8c790284 */ 	lw	$t9,0x284($v1)
/*  f0c2010:	a73819ce */ 	sh	$t8,0x19ce($t9)
/*  f0c2014:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c2018:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c201c:	e44419d4 */ 	swc1	$f4,0x19d4($v0)
/*  f0c2020:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c2024:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c2028:	c44819c0 */ 	lwc1	$f8,0x19c0($v0)
/*  f0c202c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c2030:	e44a19d0 */ 	swc1	$f10,0x19d0($v0)
/*  f0c2034:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c2038:	8c4801b0 */ 	lw	$t0,0x1b0($v0)
/*  f0c203c:	55000014 */ 	bnezl	$t0,.L0f0c2090
/*  f0c2040:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c2044:	8c4919b8 */ 	lw	$t1,0x19b8($v0)
/*  f0c2048:	c45019d0 */ 	lwc1	$f16,0x19d0($v0)
/*  f0c204c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0c2050:	44899000 */ 	mtc1	$t1,$f18
/*  f0c2054:	44815000 */ 	mtc1	$at,$f10
/*  f0c2058:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0c205c:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0c2060:	e44619d0 */ 	swc1	$f6,0x19d0($v0)
/*  f0c2064:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c2068:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c206c:	c45219d0 */ 	lwc1	$f18,0x19d0($v0)
/*  f0c2070:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f0c2074:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c2078:	00000000 */ 	nop
/*  f0c207c:	45020004 */ 	bc1fl	.L0f0c2090
/*  f0c2080:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c2084:	e44019d0 */ 	swc1	$f0,0x19d0($v0)
/*  f0c2088:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c208c:	8c4a00bc */ 	lw	$t2,0xbc($v0)
.L0f0c2090:
/*  f0c2090:	c5500008 */ 	lwc1	$f16,0x8($t2)
/*  f0c2094:	e45019d8 */ 	swc1	$f16,0x19d8($v0)
/*  f0c2098:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c209c:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f0c20a0:	c5640010 */ 	lwc1	$f4,0x10($t3)
/*  f0c20a4:	e44419dc */ 	swc1	$f4,0x19dc($v0)
/*  f0c20a8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c20ac:	c4460378 */ 	lwc1	$f6,0x378($v0)
/*  f0c20b0:	03e00008 */ 	jr	$ra
/*  f0c20b4:	e44619e0 */ 	swc1	$f6,0x19e0($v0)
);

/**
 * Populates the width, ymax and ymin arguments with absolute coordinates.
 *
 * ymin is set to 30 units above the player's feet. This allows them to go up
 * steps or ledges that are 30 units or smaller.
 *
 * ymax is the top of the head, minus some if crouching, and always at least 80
 * units above the feet.
 */
void propPlayerGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin)
{
	s32 playernum = propGetPlayerNum(prop);

	*width = g_Vars.players[playernum]->bond2.width;
	*ymin = g_Vars.currentplayer->vv_manground + 30;
	*ymax = g_Vars.currentplayer->vv_manground + g_Vars.players[playernum]->vv_headheight;

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		// note: crouchoffsetrealsmall is negative
		f32 minsane;
		*ymax += g_Vars.players[playernum]->crouchoffsetrealsmall;
		minsane = g_Vars.currentplayer->vv_manground + 80;

		if (*ymax < minsane) {
			*ymax = minsane;
		}
	}
}

f32 currentPlayerGetHealth(void)
{
	return g_Vars.currentplayer->bondhealth;
}

GLOBAL_ASM(
glabel func0f0c21a4
/*  f0c21a4:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0c21a8:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0c21ac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c21b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c21b4:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0c21b8:	0fc0cfe8 */ 	jal	chrGetShield
/*  f0c21bc:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0c21c0:	3c013e00 */ 	lui	$at,0x3e00
/*  f0c21c4:	44812000 */ 	mtc1	$at,$f4
/*  f0c21c8:	44807000 */ 	mtc1	$zero,$f14
/*  f0c21cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c21d0:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0c21d4:	44810000 */ 	mtc1	$at,$f0
/*  f0c21d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c21dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c21e0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c21e4:	46001306 */ 	mov.s	$f12,$f2
/*  f0c21e8:	45020003 */ 	bc1fl	.L0f0c21f8
/*  f0c21ec:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c21f0:	46007306 */ 	mov.s	$f12,$f14
/*  f0c21f4:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0c21f8:
/*  f0c21f8:	00000000 */ 	nop
/*  f0c21fc:	45000002 */ 	bc1f	.L0f0c2208
/*  f0c2200:	00000000 */ 	nop
/*  f0c2204:	46000306 */ 	mov.s	$f12,$f0
.L0f0c2208:
/*  f0c2208:	03e00008 */ 	jr	$ra
/*  f0c220c:	46006006 */ 	mov.s	$f0,$f12
);

void currentPlayerSetShieldFrac(f32 shield)
{
	if (shield < 0) {
		shield = 0;
	}

	if (shield > 1) {
		shield = 1;
	}

	chrSetShield(g_Vars.currentplayer->prop->chr, shield * 8);
}

s32 getMissionTime(void)
{
	return g_Vars.currentplayer->bondviewlevtime60;
}

GLOBAL_ASM(
glabel func0f0c228c
/*  f0c228c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0c2290:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c2294:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c2298:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0c229c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0c22a0:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x64)
/*  f0c22a4:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f0c22a8:	8c84a024 */ 	lw	$a0,%lo(g_Vars+0x64)($a0)
/*  f0c22ac:	0fc2b6ef */ 	jal	bullettailTick
/*  f0c22b0:	24840814 */ 	addiu	$a0,$a0,2068
/*  f0c22b4:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c22b8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0c22bc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f0c22c0:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x64)
/*  f0c22c4:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f0c22c8:	8c84a024 */ 	lw	$a0,%lo(g_Vars+0x64)($a0)
/*  f0c22cc:	0fc2b6ef */ 	jal	bullettailTick
/*  f0c22d0:	24840fb8 */ 	addiu	$a0,$a0,4024
/*  f0c22d4:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f0c22d8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x314)
/*  f0c22dc:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f0c22e0:	5040001c */ 	beqzl	$v0,.L0f0c2354
/*  f0c22e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c22e8:	8f39a2d4 */ 	lw	$t9,%lo(g_Vars+0x314)($t9)
/*  f0c22ec:	53200019 */ 	beqzl	$t9,.L0f0c2354
/*  f0c22f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c22f4:	8045017c */ 	lb	$a1,0x17c($v0)
/*  f0c22f8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c22fc:	3c0a800a */ 	lui	$t2,%hi(g_Fireslots)
/*  f0c2300:	04a00009 */ 	bltz	$a1,.L0f0c2328
/*  f0c2304:	00054080 */ 	sll	$t0,$a1,0x2
/*  f0c2308:	01054023 */ 	subu	$t0,$t0,$a1
/*  f0c230c:	00084100 */ 	sll	$t0,$t0,0x4
/*  f0c2310:	25090004 */ 	addiu	$t1,$t0,0x4
/*  f0c2314:	254ad150 */ 	addiu	$t2,$t2,%lo(g_Fireslots)
/*  f0c2318:	012a2021 */ 	addu	$a0,$t1,$t2
/*  f0c231c:	0fc2b6ef */ 	jal	bullettailTick
/*  f0c2320:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0c2324:	8fa3001c */ 	lw	$v1,0x1c($sp)
.L0f0c2328:
/*  f0c2328:	8062017d */ 	lb	$v0,0x17d($v1)
/*  f0c232c:	3c0d800a */ 	lui	$t5,%hi(g_Fireslots)
/*  f0c2330:	25add150 */ 	addiu	$t5,$t5,%lo(g_Fireslots)
/*  f0c2334:	04400006 */ 	bltz	$v0,.L0f0c2350
/*  f0c2338:	00025880 */ 	sll	$t3,$v0,0x2
/*  f0c233c:	01625823 */ 	subu	$t3,$t3,$v0
/*  f0c2340:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0c2344:	256c0004 */ 	addiu	$t4,$t3,0x4
/*  f0c2348:	0fc2b6ef */ 	jal	bullettailTick
/*  f0c234c:	018d2021 */ 	addu	$a0,$t4,$t5
.L0f0c2350:
/*  f0c2350:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c2354:
/*  f0c2354:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0c2358:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c235c:	03e00008 */ 	jr	$ra
/*  f0c2360:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0c2364
.late_rodata
glabel var7f1ad700
.word 0x40c907a9
glabel var7f1ad704
.word 0x40c907a9
glabel var7f1ad708
.word 0x40c907a9
glabel var7f1ad70c
.word 0x3c8ef461
glabel var7f1ad710
.word 0x411ffffe
.text
/*  f0c2364:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0c2368:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c236c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0c2370:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0c2374:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0c2378:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c237c:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f0c2380:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0c2384:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0c2388:	8e590290 */ 	lw	$t9,0x290($s2)
/*  f0c238c:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0c2390:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0c2394:	afa200fc */ 	sw	$v0,0xfc($sp)
/*  f0c2398:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f0c239c:	8df10064 */ 	lw	$s1,0x64($t7)
/*  f0c23a0:	17200008 */ 	bnez	$t9,.L0f0c23c4
/*  f0c23a4:	8f100004 */ 	lw	$s0,0x4($t8)
/*  f0c23a8:	8e2819c8 */ 	lw	$t0,0x19c8($s1)
/*  f0c23ac:	51000006 */ 	beqzl	$t0,.L0f0c23c8
/*  f0c23b0:	8e2619c8 */ 	lw	$a2,0x19c8($s1)
/*  f0c23b4:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f0c23b8:	2401f7ff */ 	addiu	$at,$zero,-2049
/*  f0c23bc:	01215024 */ 	and	$t2,$t1,$at
/*  f0c23c0:	ae0a0014 */ 	sw	$t2,0x14($s0)
.L0f0c23c4:
/*  f0c23c4:	8e2619c8 */ 	lw	$a2,0x19c8($s1)
.L0f0c23c8:
/*  f0c23c8:	10c00070 */ 	beqz	$a2,.L0f0c258c
/*  f0c23cc:	00000000 */ 	nop
/*  f0c23d0:	8e2b00d4 */ 	lw	$t3,0xd4($s1)
/*  f0c23d4:	3c038007 */ 	lui	$v1,%hi(var80075d60)
/*  f0c23d8:	1160006c */ 	beqz	$t3,.L0f0c258c
/*  f0c23dc:	00000000 */ 	nop
/*  f0c23e0:	8c635d60 */ 	lw	$v1,%lo(var80075d60)($v1)
/*  f0c23e4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0c23e8:	5060000b */ 	beqzl	$v1,.L0f0c2418
/*  f0c23ec:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0c23f0:	50e30009 */ 	beql	$a3,$v1,.L0f0c2418
/*  f0c23f4:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0c23f8:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0c23fc:	14ec0063 */ 	bne	$a3,$t4,.L0f0c258c
/*  f0c2400:	00000000 */ 	nop
/*  f0c2404:	962d0010 */ 	lhu	$t5,0x10($s1)
/*  f0c2408:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c240c:	11a1005f */ 	beq	$t5,$at,.L0f0c258c
/*  f0c2410:	00000000 */ 	nop
/*  f0c2414:	8e0e0018 */ 	lw	$t6,0x18($s0)
.L0f0c2418:
/*  f0c2418:	35cf0001 */ 	ori	$t7,$t6,0x1
/*  f0c241c:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f0c2420:	ae2000c0 */ 	sw	$zero,0xc0($s1)
/*  f0c2424:	0fc08c26 */ 	jal	func0f023098
/*  f0c2428:	8fa40100 */ 	lw	$a0,0x100($sp)
/*  f0c242c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c2430:	ae3800c0 */ 	sw	$t8,0xc0($s1)
/*  f0c2434:	c60400b8 */ 	lwc1	$f4,0xb8($s0)
/*  f0c2438:	00409025 */ 	or	$s2,$v0,$zero
/*  f0c243c:	e6240078 */ 	swc1	$f4,0x78($s1)
/*  f0c2440:	c60600b8 */ 	lwc1	$f6,0xb8($s0)
/*  f0c2444:	e6260074 */ 	swc1	$f6,0x74($s1)
/*  f0c2448:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f0c244c:	0fc0882b */ 	jal	func0f0220ac
/*  f0c2450:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f0c2454:	8fa80100 */ 	lw	$t0,0x100($sp)
/*  f0c2458:	91090001 */ 	lbu	$t1,0x1($t0)
/*  f0c245c:	312a0002 */ 	andi	$t2,$t1,0x2
/*  f0c2460:	51400030 */ 	beqzl	$t2,.L0f0c2524
/*  f0c2464:	8e2e00bc */ 	lw	$t6,0xbc($s1)
/*  f0c2468:	8e2200d4 */ 	lw	$v0,0xd4($s1)
/*  f0c246c:	3c0b8008 */ 	lui	$t3,%hi(stagethinglist_22e60)
/*  f0c2470:	256bce40 */ 	addiu	$t3,$t3,%lo(stagethinglist_22e60)
/*  f0c2474:	8c4c0008 */ 	lw	$t4,0x8($v0)
/*  f0c2478:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f0c247c:	556d0004 */ 	bnel	$t3,$t5,.L0f0c2490
/*  f0c2480:	8c45000c */ 	lw	$a1,0xc($v0)
/*  f0c2484:	10000002 */ 	b	.L0f0c2490
/*  f0c2488:	8c45000c */ 	lw	$a1,0xc($v0)
/*  f0c248c:	8c45000c */ 	lw	$a1,0xc($v0)
.L0f0c2490:
/*  f0c2490:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f0c2494:	afa500e8 */ 	sw	$a1,0xe8($sp)
/*  f0c2498:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0c249c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c24a0:	0c0056f9 */ 	jal	func00015be4
/*  f0c24a4:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0c24a8:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0c24ac:	44810000 */ 	mtc1	$at,$f0
/*  f0c24b0:	c7a800b8 */ 	lwc1	$f8,0xb8($sp)
/*  f0c24b4:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f0c24b8:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f0c24bc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0c24c0:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f0c24c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c24c8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0c24cc:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*  f0c24d0:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0c24d4:	c7b000c0 */ 	lwc1	$f16,0xc0($sp)
/*  f0c24d8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c24dc:	e7b2009c */ 	swc1	$f18,0x9c($sp)
/*  f0c24e0:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0c24e4:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f0c24e8:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c24ec:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f0c24f0:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f0c24f4:	3c017f1b */ 	lui	$at,%hi(var7f1ad700)
/*  f0c24f8:	c422d700 */ 	lwc1	$f2,%lo(var7f1ad700)($at)
/*  f0c24fc:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c2500:	44815000 */ 	mtc1	$at,$f10
/*  f0c2504:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0c2508:	44802000 */ 	mtc1	$zero,$f4
/*  f0c250c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0c2510:	e6240154 */ 	swc1	$f4,0x154($s1)
/*  f0c2514:	46028483 */ 	div.s	$f18,$f16,$f2
/*  f0c2518:	10000016 */ 	b	.L0f0c2574
/*  f0c251c:	e6320144 */ 	swc1	$f18,0x144($s1)
/*  f0c2520:	8e2e00bc */ 	lw	$t6,0xbc($s1)
.L0f0c2524:
/*  f0c2524:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c2528:	c5c60008 */ 	lwc1	$f6,0x8($t6)
/*  f0c252c:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f0c2530:	8e2f00bc */ 	lw	$t7,0xbc($s1)
/*  f0c2534:	c5e8000c */ 	lwc1	$f8,0xc($t7)
/*  f0c2538:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f0c253c:	8e3800bc */ 	lw	$t8,0xbc($s1)
/*  f0c2540:	c70a0010 */ 	lwc1	$f10,0x10($t8)
/*  f0c2544:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f0c2548:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f0c254c:	3c017f1b */ 	lui	$at,%hi(var7f1ad704)
/*  f0c2550:	c422d704 */ 	lwc1	$f2,%lo(var7f1ad704)($at)
/*  f0c2554:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c2558:	44819000 */ 	mtc1	$at,$f18
/*  f0c255c:	46001401 */ 	sub.s	$f16,$f2,$f0
/*  f0c2560:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2564:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0c2568:	e6280154 */ 	swc1	$f8,0x154($s1)
/*  f0c256c:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f0c2570:	e6260144 */ 	swc1	$f6,0x144($s1)
.L0f0c2574:
/*  f0c2574:	0fc32fd4 */ 	jal	func0f0cbf50
/*  f0c2578:	00000000 */ 	nop
/*  f0c257c:	0fc33067 */ 	jal	func0f0cc19c
/*  f0c2580:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f0c2584:	1000012e */ 	b	.L0f0c2a40
/*  f0c2588:	02401025 */ 	or	$v0,$s2,$zero
.L0f0c258c:
/*  f0c258c:	10c000d6 */ 	beqz	$a2,.L0f0c28e8
/*  f0c2590:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0c2594:	8e3900d4 */ 	lw	$t9,0xd4($s1)
/*  f0c2598:	532000d4 */ 	beqzl	$t9,.L0f0c28ec
/*  f0c259c:	8e59006c */ 	lw	$t9,0x6c($s2)
/*  f0c25a0:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0c25a4:	51000005 */ 	beqzl	$t0,.L0f0c25bc
/*  f0c25a8:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f0c25ac:	8e49028c */ 	lw	$t1,0x28c($s2)
/*  f0c25b0:	5449000c */ 	bnel	$v0,$t1,.L0f0c25e4
/*  f0c25b4:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0c25b8:	8e220000 */ 	lw	$v0,0x0($s1)
.L0f0c25bc:
/*  f0c25bc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c25c0:	50410008 */ 	beql	$v0,$at,.L0f0c25e4
/*  f0c25c4:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0c25c8:	54e200c8 */ 	bnel	$a3,$v0,.L0f0c28ec
/*  f0c25cc:	8e59006c */ 	lw	$t9,0x6c($s2)
/*  f0c25d0:	962a0010 */ 	lhu	$t2,0x10($s1)
/*  f0c25d4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c25d8:	554100c4 */ 	bnel	$t2,$at,.L0f0c28ec
/*  f0c25dc:	8e59006c */ 	lw	$t9,0x6c($s2)
/*  f0c25e0:	8e0b0014 */ 	lw	$t3,0x14($s0)
.L0f0c25e4:
/*  f0c25e4:	240c0019 */ 	addiu	$t4,$zero,0x19
/*  f0c25e8:	a20c0007 */ 	sb	$t4,0x7($s0)
/*  f0c25ec:	316d0800 */ 	andi	$t5,$t3,0x800
/*  f0c25f0:	15a00050 */ 	bnez	$t5,.L0f0c2734
/*  f0c25f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c25f8:	0fc0a209 */ 	jal	chrGetEquippedWeaponProp
/*  f0c25fc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2600:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0c2604:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c2608:	0fc0a209 */ 	jal	chrGetEquippedWeaponProp
/*  f0c260c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2610:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f0c2614:	0c00744f */ 	jal	modelGetAnimNum
/*  f0c2618:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0c261c:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0c2620:	0fc331ab */ 	jal	playerGetCrouchPos
/*  f0c2624:	8fa400fc */ 	lw	$a0,0xfc($sp)
/*  f0c2628:	c62a0148 */ 	lwc1	$f10,0x148($s1)
/*  f0c262c:	8e260168 */ 	lw	$a2,0x168($s1)
/*  f0c2630:	8e270170 */ 	lw	$a3,0x170($s1)
/*  f0c2634:	262e18f4 */ 	addiu	$t6,$s1,0x18f4
/*  f0c2638:	260f002c */ 	addiu	$t7,$s0,0x2c
/*  f0c263c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0c2640:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0c2644:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c2648:	00402825 */ 	or	$a1,$v0,$zero
/*  f0c264c:	0fc30a96 */ 	jal	func0f0c2a58
/*  f0c2650:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0c2654:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0c2658:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c265c:	50400006 */ 	beqzl	$v0,.L0f0c2678
/*  f0c2660:	c620196c */ 	lwc1	$f0,0x196c($s1)
/*  f0c2664:	44800000 */ 	mtc1	$zero,$f0
/*  f0c2668:	44801000 */ 	mtc1	$zero,$f2
/*  f0c266c:	10000004 */ 	b	.L0f0c2680
/*  f0c2670:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0c2674:	c620196c */ 	lwc1	$f0,0x196c($s1)
.L0f0c2678:
/*  f0c2678:	c6221970 */ 	lwc1	$f2,0x1970($s1)
/*  f0c267c:	8e040020 */ 	lw	$a0,0x20($s0)
.L0f0c2680:
/*  f0c2680:	e7a20070 */ 	swc1	$f2,0x70($sp)
/*  f0c2684:	0c00744f */ 	jal	modelGetAnimNum
/*  f0c2688:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f0c268c:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0c2690:	c7a00074 */ 	lwc1	$f0,0x74($sp)
/*  f0c2694:	c7a20070 */ 	lwc1	$f2,0x70($sp)
/*  f0c2698:	5458001c */ 	bnel	$v0,$t8,.L0f0c270c
/*  f0c269c:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0c26a0:	8e05002c */ 	lw	$a1,0x2c($s0)
/*  f0c26a4:	50a00011 */ 	beqzl	$a1,.L0f0c26ec
/*  f0c26a8:	960c0192 */ 	lhu	$t4,0x192($s0)
/*  f0c26ac:	96190192 */ 	lhu	$t9,0x192($s0)
/*  f0c26b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c26b4:	3328fffb */ 	andi	$t0,$t9,0xfffb
/*  f0c26b8:	a6080192 */ 	sh	$t0,0x192($s0)
/*  f0c26bc:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0c26c0:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0c26c4:	e7a20070 */ 	swc1	$f2,0x70($sp)
/*  f0c26c8:	0007502b */ 	sltu	$t2,$zero,$a3
/*  f0c26cc:	0006482b */ 	sltu	$t1,$zero,$a2
/*  f0c26d0:	01203025 */ 	or	$a2,$t1,$zero
/*  f0c26d4:	01403825 */ 	or	$a3,$t2,$zero
/*  f0c26d8:	0fc0fdde */ 	jal	func0f03f778
/*  f0c26dc:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f0c26e0:	10000009 */ 	b	.L0f0c2708
/*  f0c26e4:	c7a20070 */ 	lwc1	$f2,0x70($sp)
/*  f0c26e8:	960c0192 */ 	lhu	$t4,0x192($s0)
.L0f0c26ec:
/*  f0c26ec:	44808000 */ 	mtc1	$zero,$f16
/*  f0c26f0:	44809000 */ 	mtc1	$zero,$f18
/*  f0c26f4:	358b0004 */ 	ori	$t3,$t4,0x4
/*  f0c26f8:	a60b0192 */ 	sh	$t3,0x192($s0)
/*  f0c26fc:	e6000168 */ 	swc1	$f0,0x168($s0)
/*  f0c2700:	e6100164 */ 	swc1	$f16,0x164($s0)
/*  f0c2704:	e6120160 */ 	swc1	$f18,0x160($s0)
.L0f0c2708:
/*  f0c2708:	240d000a */ 	addiu	$t5,$zero,0xa
.L0f0c270c:
/*  f0c270c:	e602016c */ 	swc1	$f2,0x16c($s0)
/*  f0c2710:	a20d000e */ 	sb	$t5,0xe($s0)
/*  f0c2714:	8226063d */ 	lb	$a2,0x63d($s1)
/*  f0c2718:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c271c:	0fc0fe12 */ 	jal	chrSetFiring
/*  f0c2720:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2724:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c2728:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c272c:	0fc0fe12 */ 	jal	chrSetFiring
/*  f0c2730:	82260de1 */ 	lb	$a2,0xde1($s1)
.L0f0c2734:
/*  f0c2734:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0c2738:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0c273c:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f0c2740:	e7a40080 */ 	swc1	$f4,0x80($sp)
/*  f0c2744:	c5c6000c */ 	lwc1	$f6,0xc($t6)
/*  f0c2748:	e7a60084 */ 	swc1	$f6,0x84($sp)
/*  f0c274c:	c5c80010 */ 	lwc1	$f8,0x10($t6)
/*  f0c2750:	e7a80088 */ 	swc1	$f8,0x88($sp)
/*  f0c2754:	0c006b43 */ 	jal	modelGetRootPosition
/*  f0c2758:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0c275c:	8fa20100 */ 	lw	$v0,0x100($sp)
/*  f0c2760:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0c2764:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c2768:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0c276c:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*  f0c2770:	e7b00094 */ 	swc1	$f16,0x94($sp)
/*  f0c2774:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0c2778:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0c277c:	3c017f1b */ 	lui	$at,%hi(var7f1ad708)
/*  f0c2780:	c422d708 */ 	lwc1	$f2,%lo(var7f1ad708)($at)
/*  f0c2784:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c2788:	44819000 */ 	mtc1	$at,$f18
/*  f0c278c:	c6240144 */ 	lwc1	$f4,0x144($s1)
/*  f0c2790:	3c017f1b */ 	lui	$at,%hi(var7f1ad70c)
/*  f0c2794:	c428d70c */ 	lwc1	$f8,%lo(var7f1ad70c)($at)
/*  f0c2798:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0c279c:	c63018f4 */ 	lwc1	$f16,0x18f4($s1)
/*  f0c27a0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0c27a4:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f0c27a8:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c27ac:	00000000 */ 	nop
/*  f0c27b0:	45020004 */ 	bc1fl	.L0f0c27c4
/*  f0c27b4:	44809000 */ 	mtc1	$zero,$f18
/*  f0c27b8:	10000008 */ 	b	.L0f0c27dc
/*  f0c27bc:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f0c27c0:	44809000 */ 	mtc1	$zero,$f18
.L0f0c27c4:
/*  f0c27c4:	00000000 */ 	nop
/*  f0c27c8:	4612003c */ 	c.lt.s	$f0,$f18
/*  f0c27cc:	00000000 */ 	nop
/*  f0c27d0:	45020003 */ 	bc1fl	.L0f0c27e0
/*  f0c27d4:	44050000 */ 	mfc1	$a1,$f0
/*  f0c27d8:	46020000 */ 	add.s	$f0,$f0,$f2
.L0f0c27dc:
/*  f0c27dc:	44050000 */ 	mfc1	$a1,$f0
.L0f0c27e0:
/*  f0c27e0:	0fc0f94e */ 	jal	func0f03e538
/*  f0c27e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c27e8:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f0c27ec:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f0c27f0:	ae180018 */ 	sw	$t8,0x18($s0)
/*  f0c27f4:	0fc08c26 */ 	jal	func0f023098
/*  f0c27f8:	8fa40100 */ 	lw	$a0,0x100($sp)
/*  f0c27fc:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0c2800:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f0c2804:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0c2808:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c280c:	e7240008 */ 	swc1	$f4,0x8($t9)
/*  f0c2810:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f0c2814:	02201825 */ 	or	$v1,$s1,$zero
/*  f0c2818:	2626197c */ 	addiu	$a2,$s1,0x197c
/*  f0c281c:	e726000c */ 	swc1	$f6,0xc($t9)
/*  f0c2820:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*  f0c2824:	02203825 */ 	or	$a3,$s1,$zero
/*  f0c2828:	e7280010 */ 	swc1	$f8,0x10($t9)
/*  f0c282c:	8e080014 */ 	lw	$t0,0x14($s0)
/*  f0c2830:	31090800 */ 	andi	$t1,$t0,0x800
/*  f0c2834:	1520002a */ 	bnez	$t1,.L0f0c28e0
.L0f0c2838:
/*  f0c2838:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c283c:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0c2840:	afa500f0 */ 	sw	$a1,0xf0($sp)
/*  f0c2844:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f0c2848:	0fc0ff79 */ 	jal	func0f03fde4
/*  f0c284c:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0c2850:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f0c2854:	8fa500f0 */ 	lw	$a1,0xf0($sp)
/*  f0c2858:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0c285c:	10400004 */ 	beqz	$v0,.L0f0c2870
/*  f0c2860:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0c2864:	8e4a000c */ 	lw	$t2,0xc($s2)
/*  f0c2868:	10000014 */ 	b	.L0f0c28bc
/*  f0c286c:	acea1994 */ 	sw	$t2,0x1994($a3)
.L0f0c2870:
/*  f0c2870:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f0c2874:	8cec1994 */ 	lw	$t4,0x1994($a3)
/*  f0c2878:	00057100 */ 	sll	$t6,$a1,0x4
/*  f0c287c:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0c2880:	018d082a */ 	slt	$at,$t4,$t5
/*  f0c2884:	1020000d */ 	beqz	$at,.L0f0c28bc
/*  f0c2888:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f0c288c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0c2890:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f0c2894:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0c2898:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f0c289c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0c28a0:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f0c28a4:	c44a09ac */ 	lwc1	$f10,0x9ac($v0)
/*  f0c28a8:	e46a197c */ 	swc1	$f10,0x197c($v1)
/*  f0c28ac:	c45009b0 */ 	lwc1	$f16,0x9b0($v0)
/*  f0c28b0:	e4701980 */ 	swc1	$f16,0x1980($v1)
/*  f0c28b4:	c45209b4 */ 	lwc1	$f18,0x9b4($v0)
/*  f0c28b8:	e4721984 */ 	swc1	$f18,0x1984($v1)
.L0f0c28bc:
/*  f0c28bc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0c28c0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c28c4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f0c28c8:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0c28cc:	14a1ffda */ 	bne	$a1,$at,.L0f0c2838
/*  f0c28d0:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c28d4:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*  f0c28d8:	35f80800 */ 	ori	$t8,$t7,0x800
/*  f0c28dc:	ae180014 */ 	sw	$t8,0x14($s0)
.L0f0c28e0:
/*  f0c28e0:	10000057 */ 	b	.L0f0c2a40
/*  f0c28e4:	8fa20098 */ 	lw	$v0,0x98($sp)
.L0f0c28e8:
/*  f0c28e8:	8e59006c */ 	lw	$t9,0x6c($s2)
.L0f0c28ec:
/*  f0c28ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c28f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c28f4:	13200003 */ 	beqz	$t9,.L0f0c2904
/*  f0c28f8:	00000000 */ 	nop
/*  f0c28fc:	10000001 */ 	b	.L0f0c2904
/*  f0c2900:	00e02825 */ 	or	$a1,$a3,$zero
.L0f0c2904:
/*  f0c2904:	8e480068 */ 	lw	$t0,0x68($s2)
/*  f0c2908:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c290c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c2910:	11000003 */ 	beqz	$t0,.L0f0c2920
/*  f0c2914:	00000000 */ 	nop
/*  f0c2918:	10000001 */ 	b	.L0f0c2920
/*  f0c291c:	00e01825 */ 	or	$v1,$a3,$zero
.L0f0c2920:
/*  f0c2920:	8e490064 */ 	lw	$t1,0x64($s2)
/*  f0c2924:	11200003 */ 	beqz	$t1,.L0f0c2934
/*  f0c2928:	00000000 */ 	nop
/*  f0c292c:	10000001 */ 	b	.L0f0c2934
/*  f0c2930:	00e02025 */ 	or	$a0,$a3,$zero
.L0f0c2934:
/*  f0c2934:	8e4a0070 */ 	lw	$t2,0x70($s2)
/*  f0c2938:	11400003 */ 	beqz	$t2,.L0f0c2948
/*  f0c293c:	00000000 */ 	nop
/*  f0c2940:	10000001 */ 	b	.L0f0c2948
/*  f0c2944:	00e01025 */ 	or	$v0,$a3,$zero
.L0f0c2948:
/*  f0c2948:	00445821 */ 	addu	$t3,$v0,$a0
/*  f0c294c:	01636021 */ 	addu	$t4,$t3,$v1
/*  f0c2950:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0c2954:	14ed0004 */ 	bne	$a3,$t5,.L0f0c2968
/*  f0c2958:	00000000 */ 	nop
/*  f0c295c:	0fc08989 */ 	jal	chrUpdateCloak
/*  f0c2960:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c2964:	8e2619c8 */ 	lw	$a2,0x19c8($s1)
.L0f0c2968:
/*  f0c2968:	50c0000f */ 	beqzl	$a2,.L0f0c29a8
/*  f0c296c:	c6280078 */ 	lwc1	$f8,0x78($s1)
/*  f0c2970:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0c2974:	5080000c */ 	beqzl	$a0,.L0f0c29a8
/*  f0c2978:	c6280078 */ 	lwc1	$f8,0x78($s1)
/*  f0c297c:	0c006b43 */ 	jal	modelGetRootPosition
/*  f0c2980:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0c2984:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0c2988:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0c298c:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f0c2990:	e7a4005c */ 	swc1	$f4,0x5c($sp)
/*  f0c2994:	c5c60010 */ 	lwc1	$f6,0x10($t6)
/*  f0c2998:	e7a60064 */ 	swc1	$f6,0x64($sp)
/*  f0c299c:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0c29a0:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f0c29a4:	c6280078 */ 	lwc1	$f8,0x78($s1)
.L0f0c29a8:
/*  f0c29a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad710)
/*  f0c29ac:	e60800b8 */ 	swc1	$f8,0xb8($s0)
/*  f0c29b0:	c62a0074 */ 	lwc1	$f10,0x74($s1)
/*  f0c29b4:	e60a00b4 */ 	swc1	$f10,0xb4($s0)
/*  f0c29b8:	c432d710 */ 	lwc1	$f18,%lo(var7f1ad710)($at)
/*  f0c29bc:	c61000b4 */ 	lwc1	$f16,0xb4($s0)
/*  f0c29c0:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0c29c4:	e60400b0 */ 	swc1	$f4,0xb0($s0)
/*  f0c29c8:	8e4f0314 */ 	lw	$t7,0x314($s2)
/*  f0c29cc:	51e00018 */ 	beqzl	$t7,.L0f0c2a30
/*  f0c29d0:	8faa0100 */ 	lw	$t2,0x100($sp)
/*  f0c29d4:	8e020170 */ 	lw	$v0,0x170($s0)
/*  f0c29d8:	5040000a */ 	beqzl	$v0,.L0f0c2a04
/*  f0c29dc:	8e020174 */ 	lw	$v0,0x174($s0)
/*  f0c29e0:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c29e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c29e8:	8c980040 */ 	lw	$t8,0x40($a0)
/*  f0c29ec:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0c29f0:	53200004 */ 	beqzl	$t9,.L0f0c2a04
/*  f0c29f4:	8e020174 */ 	lw	$v0,0x174($s0)
/*  f0c29f8:	0fc1ab4b */ 	jal	func0f06ad2c
/*  f0c29fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c2a00:	8e020174 */ 	lw	$v0,0x174($s0)
.L0f0c2a04:
/*  f0c2a04:	5040000a */ 	beqzl	$v0,.L0f0c2a30
/*  f0c2a08:	8faa0100 */ 	lw	$t2,0x100($sp)
/*  f0c2a0c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c2a10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2a14:	8c880040 */ 	lw	$t0,0x40($a0)
/*  f0c2a18:	31090004 */ 	andi	$t1,$t0,0x4
/*  f0c2a1c:	51200004 */ 	beqzl	$t1,.L0f0c2a30
/*  f0c2a20:	8faa0100 */ 	lw	$t2,0x100($sp)
/*  f0c2a24:	0fc1ab4b */ 	jal	func0f06ad2c
/*  f0c2a28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c2a2c:	8faa0100 */ 	lw	$t2,0x100($sp)
.L0f0c2a30:
/*  f0c2a30:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c2a34:	914b0001 */ 	lbu	$t3,0x1($t2)
/*  f0c2a38:	316cfffd */ 	andi	$t4,$t3,0xfffd
/*  f0c2a3c:	a14c0001 */ 	sb	$t4,0x1($t2)
.L0f0c2a40:
/*  f0c2a40:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0c2a44:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0c2a48:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0c2a4c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0c2a50:	03e00008 */ 	jr	$ra
/*  f0c2a54:	27bd0100 */ 	addiu	$sp,$sp,0x100
);

GLOBAL_ASM(
glabel func0f0c2a58
.late_rodata
glabel var7f1ad714
.word 0x3d4ccccd
glabel var7f1ad718
.word 0x404907a9
glabel var7f1ad71c
.word 0x40c907a9
glabel var7f1ad720
.word 0x3f99999a
glabel var7f1ad724
.word 0x4036db6e
glabel var7f1ad728
.word 0x3f99999a
glabel var7f1ad72c
.word 0x3ecccccd
glabel var7f1ad730
.word 0x404907a9
glabel var7f1ad734
.word 0x3f99999a
glabel var7f1ad738
.word 0x3f99999a
glabel var7f1ad73c
.word 0xbfd11234
glabel var7f1ad740
.word 0x3fd11234
glabel var7f1ad744
.word 0x3dd66e92
.text
/*  f0c2a58:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0c2a5c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c2a60:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0c2a64:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0c2a68:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0c2a6c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0c2a70:	0fc0a209 */ 	jal	chrGetEquippedWeaponProp
/*  f0c2a74:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2a78:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0c2a7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2a80:	0fc0a209 */ 	jal	chrGetEquippedWeaponProp
/*  f0c2a84:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0c2a88:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0c2a8c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c2a90:	44811000 */ 	mtc1	$at,$f2
/*  f0c2a94:	00402825 */ 	or	$a1,$v0,$zero
/*  f0c2a98:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c2a9c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c2aa0:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*  f0c2aa4:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f0c2aa8:	10600002 */ 	beqz	$v1,.L0f0c2ab4
/*  f0c2aac:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f0c2ab0:	8c660004 */ 	lw	$a2,0x4($v1)
.L0f0c2ab4:
/*  f0c2ab4:	10400002 */ 	beqz	$v0,.L0f0c2ac0
/*  f0c2ab8:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0c2abc:	8c470004 */ 	lw	$a3,0x4($v0)
.L0f0c2ac0:
/*  f0c2ac0:	8dc40020 */ 	lw	$a0,0x20($t6)
/*  f0c2ac4:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2ac8:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0c2acc:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2ad0:	afa50058 */ 	sw	$a1,0x58($sp)
/*  f0c2ad4:	0c00744f */ 	jal	modelGetAnimNum
/*  f0c2ad8:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0c2adc:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0c2ae0:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0c2ae4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0c2ae8:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0c2aec:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0c2af0:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2af4:	1040002d */ 	beqz	$v0,.L0f0c2bac
/*  f0c2af8:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2afc:	3c048007 */ 	lui	$a0,%hi(g_NumDeathAnimations)
/*  f0c2b00:	8c84077c */ 	lw	$a0,%lo(g_NumDeathAnimations)($a0)
/*  f0c2b04:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2b08:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c2b0c:	1880000c */ 	blez	$a0,.L0f0c2b40
/*  f0c2b10:	3c038007 */ 	lui	$v1,%hi(g_DeathAnimations)
/*  f0c2b14:	24630768 */ 	addiu	$v1,$v1,%lo(g_DeathAnimations)
/*  f0c2b18:	8fa60040 */ 	lw	$a2,0x40($sp)
.L0f0c2b1c:
/*  f0c2b1c:	846f0000 */ 	lh	$t7,0x0($v1)
/*  f0c2b20:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c2b24:	0044082a */ 	slt	$at,$v0,$a0
/*  f0c2b28:	14cf0003 */ 	bne	$a2,$t7,.L0f0c2b38
/*  f0c2b2c:	00000000 */ 	nop
/*  f0c2b30:	10000003 */ 	b	.L0f0c2b40
/*  f0c2b34:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c2b38:
/*  f0c2b38:	1420fff8 */ 	bnez	$at,.L0f0c2b1c
/*  f0c2b3c:	24630002 */ 	addiu	$v1,$v1,0x2
.L0f0c2b40:
/*  f0c2b40:	10a00005 */ 	beqz	$a1,.L0f0c2b58
/*  f0c2b44:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c2b48:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c2b4c:	44819000 */ 	mtc1	$at,$f18
/*  f0c2b50:	10000013 */ 	b	.L0f0c2ba0
/*  f0c2b54:	a7a6004e */ 	sh	$a2,0x4e($sp)
.L0f0c2b58:
/*  f0c2b58:	0c004b70 */ 	jal	random
/*  f0c2b5c:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2b60:	3c198007 */ 	lui	$t9,%hi(g_NumDeathAnimations)
/*  f0c2b64:	8f39077c */ 	lw	$t9,%lo(g_NumDeathAnimations)($t9)
/*  f0c2b68:	3c0b8007 */ 	lui	$t3,%hi(g_DeathAnimations)
/*  f0c2b6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c2b70:	0059001b */ 	divu	$zero,$v0,$t9
/*  f0c2b74:	00004810 */ 	mfhi	$t1
/*  f0c2b78:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0c2b7c:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0c2b80:	856b0768 */ 	lh	$t3,%lo(g_DeathAnimations)($t3)
/*  f0c2b84:	44819000 */ 	mtc1	$at,$f18
/*  f0c2b88:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2b8c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c2b90:	17200002 */ 	bnez	$t9,.L0f0c2b9c
/*  f0c2b94:	00000000 */ 	nop
/*  f0c2b98:	0007000d */ 	break	0x7
.L0f0c2b9c:
/*  f0c2b9c:	a7ab004e */ 	sh	$t3,0x4e($sp)
.L0f0c2ba0:
/*  f0c2ba0:	87a5004e */ 	lh	$a1,0x4e($sp)
/*  f0c2ba4:	10000158 */ 	b	.L0f0c3108
/*  f0c2ba8:	00004025 */ 	or	$t0,$zero,$zero
.L0f0c2bac:
/*  f0c2bac:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0c2bb0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c2bb4:	8d84001c */ 	lw	$a0,0x1c($t4)
/*  f0c2bb8:	908d0000 */ 	lbu	$t5,0x0($a0)
/*  f0c2bbc:	15a10048 */ 	bne	$t5,$at,.L0f0c2ce0
/*  f0c2bc0:	00000000 */ 	nop
/*  f0c2bc4:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0c2bc8:	afa50058 */ 	sw	$a1,0x58($sp)
/*  f0c2bcc:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2bd0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c2bd4:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2bd8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0c2bdc:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x64)
/*  f0c2be0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0c2be4:	8defa024 */ 	lw	$t7,%lo(g_Vars+0x64)($t7)
/*  f0c2be8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c2bec:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0c2bf0:	8df801b0 */ 	lw	$t8,0x1b0($t7)
/*  f0c2bf4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0c2bf8:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2bfc:	17010038 */ 	bne	$t8,$at,.L0f0c2ce0
/*  f0c2c00:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2c04:	10600005 */ 	beqz	$v1,.L0f0c2c1c
/*  f0c2c08:	00000000 */ 	nop
/*  f0c2c0c:	10a00003 */ 	beqz	$a1,.L0f0c2c1c
/*  f0c2c10:	00000000 */ 	nop
/*  f0c2c14:	1000001c */ 	b	.L0f0c2c88
/*  f0c2c18:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f0c2c1c:
/*  f0c2c1c:	14600005 */ 	bnez	$v1,.L0f0c2c34
/*  f0c2c20:	00000000 */ 	nop
/*  f0c2c24:	14a00003 */ 	bnez	$a1,.L0f0c2c34
/*  f0c2c28:	00000000 */ 	nop
/*  f0c2c2c:	10000016 */ 	b	.L0f0c2c88
/*  f0c2c30:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2c34:
/*  f0c2c34:	10c00008 */ 	beqz	$a2,.L0f0c2c58
/*  f0c2c38:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2c3c:	90c4005c */ 	lbu	$a0,0x5c($a2)
/*  f0c2c40:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2c44:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2c48:	10400003 */ 	beqz	$v0,.L0f0c2c58
/*  f0c2c4c:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2c50:	1000000d */ 	b	.L0f0c2c88
/*  f0c2c54:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c2c58:
/*  f0c2c58:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0c2c5c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2c60:	50400009 */ 	beqzl	$v0,.L0f0c2c88
/*  f0c2c64:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2c68:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f0c2c6c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2c70:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2c74:	10400003 */ 	beqz	$v0,.L0f0c2c84
/*  f0c2c78:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2c7c:	10000002 */ 	b	.L0f0c2c88
/*  f0c2c80:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c2c84:
/*  f0c2c84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c2c88:
/*  f0c2c88:	14a00004 */ 	bnez	$a1,.L0f0c2c9c
/*  f0c2c8c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0c2c90:	2419029c */ 	addiu	$t9,$zero,0x29c
/*  f0c2c94:	1000000d */ 	b	.L0f0c2ccc
/*  f0c2c98:	a7b9004e */ 	sh	$t9,0x4e($sp)
.L0f0c2c9c:
/*  f0c2c9c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c2ca0:	14a10003 */ 	bne	$a1,$at,.L0f0c2cb0
/*  f0c2ca4:	2409029d */ 	addiu	$t1,$zero,0x29d
/*  f0c2ca8:	10000008 */ 	b	.L0f0c2ccc
/*  f0c2cac:	a7a9004e */ 	sh	$t1,0x4e($sp)
.L0f0c2cb0:
/*  f0c2cb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2cb4:	14a10004 */ 	bne	$a1,$at,.L0f0c2cc8
/*  f0c2cb8:	240b029b */ 	addiu	$t3,$zero,0x29b
/*  f0c2cbc:	240a029e */ 	addiu	$t2,$zero,0x29e
/*  f0c2cc0:	10000002 */ 	b	.L0f0c2ccc
/*  f0c2cc4:	a7aa004e */ 	sh	$t2,0x4e($sp)
.L0f0c2cc8:
/*  f0c2cc8:	a7ab004e */ 	sh	$t3,0x4e($sp)
.L0f0c2ccc:
/*  f0c2ccc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c2cd0:	44819000 */ 	mtc1	$at,$f18
/*  f0c2cd4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c2cd8:	1000010b */ 	b	.L0f0c3108
/*  f0c2cdc:	87a5004e */ 	lh	$a1,0x4e($sp)
.L0f0c2ce0:
/*  f0c2ce0:	10600005 */ 	beqz	$v1,.L0f0c2cf8
/*  f0c2ce4:	00000000 */ 	nop
/*  f0c2ce8:	10a00003 */ 	beqz	$a1,.L0f0c2cf8
/*  f0c2cec:	00000000 */ 	nop
/*  f0c2cf0:	1000002e */ 	b	.L0f0c2dac
/*  f0c2cf4:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f0c2cf8:
/*  f0c2cf8:	14600005 */ 	bnez	$v1,.L0f0c2d10
/*  f0c2cfc:	00000000 */ 	nop
/*  f0c2d00:	14a00003 */ 	bnez	$a1,.L0f0c2d10
/*  f0c2d04:	00000000 */ 	nop
/*  f0c2d08:	10000028 */ 	b	.L0f0c2dac
/*  f0c2d0c:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2d10:
/*  f0c2d10:	10c00008 */ 	beqz	$a2,.L0f0c2d34
/*  f0c2d14:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0c2d18:	90c4005c */ 	lbu	$a0,0x5c($a2)
/*  f0c2d1c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d20:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2d24:	14400003 */ 	bnez	$v0,.L0f0c2d34
/*  f0c2d28:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2d2c:	1000001f */ 	b	.L0f0c2dac
/*  f0c2d30:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2d34:
/*  f0c2d34:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0c2d38:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0c2d3c:	10400008 */ 	beqz	$v0,.L0f0c2d60
/*  f0c2d40:	00000000 */ 	nop
/*  f0c2d44:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f0c2d48:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d4c:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2d50:	14400003 */ 	bnez	$v0,.L0f0c2d60
/*  f0c2d54:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2d58:	10000014 */ 	b	.L0f0c2dac
/*  f0c2d5c:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2d60:
/*  f0c2d60:	10c00007 */ 	beqz	$a2,.L0f0c2d80
/*  f0c2d64:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2d68:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d6c:	90c4005c */ 	lbu	$a0,0x5c($a2)
/*  f0c2d70:	50400004 */ 	beqzl	$v0,.L0f0c2d84
/*  f0c2d74:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0c2d78:	1000000c */ 	b	.L0f0c2dac
/*  f0c2d7c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c2d80:
/*  f0c2d80:	8fa20050 */ 	lw	$v0,0x50($sp)
.L0f0c2d84:
/*  f0c2d84:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2d88:	50400008 */ 	beqzl	$v0,.L0f0c2dac
/*  f0c2d8c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2d90:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d94:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f0c2d98:	50400004 */ 	beqzl	$v0,.L0f0c2dac
/*  f0c2d9c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2da0:	10000002 */ 	b	.L0f0c2dac
/*  f0c2da4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2da8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c2dac:
/*  f0c2dac:	c7a00068 */ 	lwc1	$f0,0x68($sp)
/*  f0c2db0:	c7a2006c */ 	lwc1	$f2,0x6c($sp)
/*  f0c2db4:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0c2db8:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0c2dbc:	00000000 */ 	nop
/*  f0c2dc0:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0c2dc4:	0c012974 */ 	jal	sqrtf
/*  f0c2dc8:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0c2dcc:	c7a20070 */ 	lwc1	$f2,0x70($sp)
/*  f0c2dd0:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2dd4:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0c2dd8:	46000406 */ 	mov.s	$f16,$f0
/*  f0c2ddc:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0c2de0:	3c017f1b */ 	lui	$at,%hi(var7f1ad714)
/*  f0c2de4:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*  f0c2de8:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f0c2dec:	45020003 */ 	bc1fl	.L0f0c2dfc
/*  f0c2df0:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c2df4:	46001087 */ 	neg.s	$f2,$f2
/*  f0c2df8:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0c2dfc:
/*  f0c2dfc:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0c2e00:	45000002 */ 	bc1f	.L0f0c2e0c
/*  f0c2e04:	00000000 */ 	nop
/*  f0c2e08:	46001406 */ 	mov.s	$f16,$f2
.L0f0c2e0c:
/*  f0c2e0c:	c42ad714 */ 	lwc1	$f10,%lo(var7f1ad714)($at)
/*  f0c2e10:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0c2e14:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2e18:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c2e1c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0c2e20:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2e24:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0c2e28:	45000013 */ 	bc1f	.L0f0c2e78
/*  f0c2e2c:	3c0f8007 */ 	lui	$t7,%hi(var80070ba4)
/*  f0c2e30:	14400003 */ 	bnez	$v0,.L0f0c2e40
/*  f0c2e34:	25ef0ba4 */ 	addiu	$t7,$t7,%lo(var80070ba4)
/*  f0c2e38:	10000006 */ 	b	.L0f0c2e54
/*  f0c2e3c:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0c2e40:
/*  f0c2e40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2e44:	14410003 */ 	bne	$v0,$at,.L0f0c2e54
/*  f0c2e48:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c2e4c:	10000001 */ 	b	.L0f0c2e54
/*  f0c2e50:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0c2e54:
/*  f0c2e54:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0c2e58:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0c2e5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c2e60:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0c2e64:	44819000 */ 	mtc1	$at,$f18
/*  f0c2e68:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0c2e6c:	44806000 */ 	mtc1	$zero,$f12
/*  f0c2e70:	10000081 */ 	b	.L0f0c3078
/*  f0c2e74:	01cf1021 */ 	addu	$v0,$t6,$t7
.L0f0c2e78:
/*  f0c2e78:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0c2e7c:	0fc259d4 */ 	jal	func0f096750
/*  f0c2e80:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0c2e84:	3c017f1b */ 	lui	$at,%hi(var7f1ad718)
/*  f0c2e88:	c42ed718 */ 	lwc1	$f14,%lo(var7f1ad718)($at)
/*  f0c2e8c:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0c2e90:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f0c2e94:	4600703e */ 	c.le.s	$f14,$f0
/*  f0c2e98:	46000306 */ 	mov.s	$f12,$f0
/*  f0c2e9c:	3c017f1b */ 	lui	$at,%hi(var7f1ad71c)
/*  f0c2ea0:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0c2ea4:	45000003 */ 	bc1f	.L0f0c2eb4
/*  f0c2ea8:	00000000 */ 	nop
/*  f0c2eac:	c424d71c */ 	lwc1	$f4,%lo(var7f1ad71c)($at)
/*  f0c2eb0:	46040301 */ 	sub.s	$f12,$f0,$f4
.L0f0c2eb4:
/*  f0c2eb4:	1440000d */ 	bnez	$v0,.L0f0c2eec
/*  f0c2eb8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2ebc:	3c017f1b */ 	lui	$at,%hi(var7f1ad720)
/*  f0c2ec0:	c422d720 */ 	lwc1	$f2,%lo(var7f1ad720)($at)
/*  f0c2ec4:	3c017f1b */ 	lui	$at,%hi(var7f1ad724)
/*  f0c2ec8:	c426d724 */ 	lwc1	$f6,%lo(var7f1ad724)($at)
/*  f0c2ecc:	24030006 */ 	addiu	$v1,$zero,0x6
/*  f0c2ed0:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f0c2ed4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c2ed8:	00000000 */ 	nop
/*  f0c2edc:	4500003e */ 	bc1f	.L0f0c2fd8
/*  f0c2ee0:	00000000 */ 	nop
/*  f0c2ee4:	1000003c */ 	b	.L0f0c2fd8
/*  f0c2ee8:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2eec:
/*  f0c2eec:	1441000c */ 	bne	$v0,$at,.L0f0c2f20
/*  f0c2ef0:	3c017f1b */ 	lui	$at,%hi(var7f1ad728)
/*  f0c2ef4:	c422d728 */ 	lwc1	$f2,%lo(var7f1ad728)($at)
/*  f0c2ef8:	3c014000 */ 	lui	$at,0x4000
/*  f0c2efc:	44814000 */ 	mtc1	$at,$f8
/*  f0c2f00:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0c2f04:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f0c2f08:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c2f0c:	00000000 */ 	nop
/*  f0c2f10:	45000031 */ 	bc1f	.L0f0c2fd8
/*  f0c2f14:	00000000 */ 	nop
/*  f0c2f18:	1000002f */ 	b	.L0f0c2fd8
/*  f0c2f1c:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2f20:
/*  f0c2f20:	3c017f1b */ 	lui	$at,%hi(var7f1ad72c)
/*  f0c2f24:	c42ad72c */ 	lwc1	$f10,%lo(var7f1ad72c)($at)
/*  f0c2f28:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c2f2c:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c2f30:	00000000 */ 	nop
/*  f0c2f34:	45030016 */ 	bc1tl	.L0f0c2f90
/*  f0c2f38:	46108480 */ 	add.s	$f18,$f16,$f16
/*  f0c2f3c:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0c2f40:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c2f44:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f0c2f48:	1721001a */ 	bne	$t9,$at,.L0f0c2fb4
/*  f0c2f4c:	00000000 */ 	nop
/*  f0c2f50:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0c2f54:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f0c2f58:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c2f5c:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0c2f60:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0c2f64:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x64)
/*  f0c2f68:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0c2f6c:	8d4aa024 */ 	lw	$t2,%lo(g_Vars+0x64)($t2)
/*  f0c2f70:	3c017f1b */ 	lui	$at,%hi(var7f1ad730)
/*  f0c2f74:	c42ed730 */ 	lwc1	$f14,%lo(var7f1ad730)($at)
/*  f0c2f78:	8d4b03ac */ 	lw	$t3,0x3ac($t2)
/*  f0c2f7c:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0c2f80:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0c2f84:	1560000b */ 	bnez	$t3,.L0f0c2fb4
/*  f0c2f88:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f0c2f8c:	46108480 */ 	add.s	$f18,$f16,$f16
.L0f0c2f90:
/*  f0c2f90:	3c017f1b */ 	lui	$at,%hi(var7f1ad734)
/*  f0c2f94:	c422d734 */ 	lwc1	$f2,%lo(var7f1ad734)($at)
/*  f0c2f98:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c2f9c:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c2fa0:	00000000 */ 	nop
/*  f0c2fa4:	4500000c */ 	bc1f	.L0f0c2fd8
/*  f0c2fa8:	00000000 */ 	nop
/*  f0c2fac:	1000000a */ 	b	.L0f0c2fd8
/*  f0c2fb0:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2fb4:
/*  f0c2fb4:	3c017f1b */ 	lui	$at,%hi(var7f1ad738)
/*  f0c2fb8:	c422d738 */ 	lwc1	$f2,%lo(var7f1ad738)($at)
/*  f0c2fbc:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0c2fc0:	46008486 */ 	mov.s	$f18,$f16
/*  f0c2fc4:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0c2fc8:	00000000 */ 	nop
/*  f0c2fcc:	45000002 */ 	bc1f	.L0f0c2fd8
/*  f0c2fd0:	00000000 */ 	nop
/*  f0c2fd4:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2fd8:
/*  f0c2fd8:	3c017f1b */ 	lui	$at,%hi(var7f1ad73c)
/*  f0c2fdc:	c424d73c */ 	lwc1	$f4,%lo(var7f1ad73c)($at)
/*  f0c2fe0:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0c2fe4:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2fe8:	4604603c */ 	c.lt.s	$f12,$f4
/*  f0c2fec:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0c2ff0:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2ff4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0c2ff8:	45000004 */ 	bc1f	.L0f0c300c
/*  f0c2ffc:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0c3000:	460e6300 */ 	add.s	$f12,$f12,$f14
/*  f0c3004:	10000009 */ 	b	.L0f0c302c
/*  f0c3008:	46009487 */ 	neg.s	$f18,$f18
.L0f0c300c:
/*  f0c300c:	3c017f1b */ 	lui	$at,%hi(var7f1ad740)
/*  f0c3010:	c426d740 */ 	lwc1	$f6,%lo(var7f1ad740)($at)
/*  f0c3014:	460c303c */ 	c.lt.s	$f6,$f12
/*  f0c3018:	00000000 */ 	nop
/*  f0c301c:	45020004 */ 	bc1fl	.L0f0c3030
/*  f0c3020:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0c3024:	460e6301 */ 	sub.s	$f12,$f12,$f14
/*  f0c3028:	46009487 */ 	neg.s	$f18,$f18
.L0f0c302c:
/*  f0c302c:	01a36823 */ 	subu	$t5,$t5,$v1
.L0f0c3030:
/*  f0c3030:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0c3034:	3c0f8007 */ 	lui	$t7,%hi(var80070ba4)
/*  f0c3038:	25ef0ba4 */ 	addiu	$t7,$t7,%lo(var80070ba4)
/*  f0c303c:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0c3040:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0c3044:	c4400014 */ 	lwc1	$f0,0x14($v0)
/*  f0c3048:	46000087 */ 	neg.s	$f2,$f0
/*  f0c304c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c3050:	00000000 */ 	nop
/*  f0c3054:	45020004 */ 	bc1fl	.L0f0c3068
/*  f0c3058:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c305c:	10000006 */ 	b	.L0f0c3078
/*  f0c3060:	46001306 */ 	mov.s	$f12,$f2
/*  f0c3064:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0c3068:
/*  f0c3068:	00000000 */ 	nop
/*  f0c306c:	45000002 */ 	bc1f	.L0f0c3078
/*  f0c3070:	00000000 */ 	nop
/*  f0c3074:	46000306 */ 	mov.s	$f12,$f0
.L0f0c3078:
/*  f0c3078:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f0c307c:	c428a00c */ 	lwc1	$f8,%lo(g_Vars+0x4c)($at)
/*  f0c3080:	3c017f1b */ 	lui	$at,%hi(var7f1ad744)
/*  f0c3084:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0c3088:	c42ad744 */ 	lwc1	$f10,%lo(var7f1ad744)($at)
/*  f0c308c:	c4620000 */ 	lwc1	$f2,0x0($v1)
/*  f0c3090:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0c3094:	46026381 */ 	sub.s	$f14,$f12,$f2
/*  f0c3098:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0c309c:	00000000 */ 	nop
/*  f0c30a0:	45020005 */ 	bc1fl	.L0f0c30b8
/*  f0c30a4:	46000187 */ 	neg.s	$f6,$f0
/*  f0c30a8:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f0c30ac:	1000000a */ 	b	.L0f0c30d8
/*  f0c30b0:	e4640000 */ 	swc1	$f4,0x0($v1)
/*  f0c30b4:	46000187 */ 	neg.s	$f6,$f0
.L0f0c30b8:
/*  f0c30b8:	4606703c */ 	c.lt.s	$f14,$f6
/*  f0c30bc:	00000000 */ 	nop
/*  f0c30c0:	45020005 */ 	bc1fl	.L0f0c30d8
/*  f0c30c4:	e46c0000 */ 	swc1	$f12,0x0($v1)
/*  f0c30c8:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0c30cc:	10000002 */ 	b	.L0f0c30d8
/*  f0c30d0:	e4680000 */ 	swc1	$f8,0x0($v1)
/*  f0c30d4:	e46c0000 */ 	swc1	$f12,0x0($v1)
.L0f0c30d8:
/*  f0c30d8:	84430004 */ 	lh	$v1,0x4($v0)
/*  f0c30dc:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f0c30e0:	50600003 */ 	beqzl	$v1,.L0f0c30f0
/*  f0c30e4:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c30e8:	a7a3004e */ 	sh	$v1,0x4e($sp)
/*  f0c30ec:	c44a0008 */ 	lwc1	$f10,0x8($v0)
.L0f0c30f0:
/*  f0c30f0:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c30f4:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f0c30f8:	460a9482 */ 	mul.s	$f18,$f18,$f10
/*  f0c30fc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c3100:	87a5004e */ 	lh	$a1,0x4e($sp)
/*  f0c3104:	e7a4002c */ 	swc1	$f4,0x2c($sp)
.L0f0c3108:
/*  f0c3108:	44806000 */ 	mtc1	$zero,$f12
/*  f0c310c:	11000004 */ 	beqz	$t0,.L0f0c3120
/*  f0c3110:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c3114:	14a00002 */ 	bnez	$a1,.L0f0c3120
/*  f0c3118:	00000000 */ 	nop
/*  f0c311c:	85050000 */ 	lh	$a1,0x0($t0)
.L0f0c3120:
/*  f0c3120:	50a60003 */ 	beql	$a1,$a2,.L0f0c3130
/*  f0c3124:	4602603e */ 	c.le.s	$f12,$f2
/*  f0c3128:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0c312c:	4602603e */ 	c.le.s	$f12,$f2
.L0f0c3130:
/*  f0c3130:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0c3134:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c3138:	4502000d */ 	bc1fl	.L0f0c3170
/*  f0c313c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c3140:	8f190020 */ 	lw	$t9,0x20($t8)
/*  f0c3144:	8f220020 */ 	lw	$v0,0x20($t9)
/*  f0c3148:	8049000a */ 	lb	$t1,0xa($v0)
/*  f0c314c:	51200007 */ 	beqzl	$t1,.L0f0c316c
/*  f0c3150:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c3154:	c4460060 */ 	lwc1	$f6,0x60($v0)
/*  f0c3158:	46061032 */ 	c.eq.s	$f2,$f6
/*  f0c315c:	00000000 */ 	nop
/*  f0c3160:	45030003 */ 	bc1tl	.L0f0c3170
/*  f0c3164:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c3168:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c316c:
/*  f0c316c:	460c103c */ 	c.lt.s	$f2,$f12
.L0f0c3170:
/*  f0c3170:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f0c3174:	45000006 */ 	bc1f	.L0f0c3190
/*  f0c3178:	8d440020 */ 	lw	$a0,0x20($t2)
/*  f0c317c:	8c8b0020 */ 	lw	$t3,0x20($a0)
/*  f0c3180:	816c000a */ 	lb	$t4,0xa($t3)
/*  f0c3184:	11800002 */ 	beqz	$t4,.L0f0c3190
/*  f0c3188:	00000000 */ 	nop
/*  f0c318c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c3190:
/*  f0c3190:	5060002f */ 	beqzl	$v1,.L0f0c3250
/*  f0c3194:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3198:	8c8d0020 */ 	lw	$t5,0x20($a0)
/*  f0c319c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c31a0:	3c014180 */ 	lui	$at,0x4180
/*  f0c31a4:	85ae0002 */ 	lh	$t6,0x2($t5)
/*  f0c31a8:	55c00038 */ 	bnezl	$t6,.L0f0c328c
/*  f0c31ac:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0c31b0:	4602603e */ 	c.le.s	$f12,$f2
/*  f0c31b4:	44814000 */ 	mtc1	$at,$f8
/*  f0c31b8:	45020004 */ 	bc1fl	.L0f0c31cc
/*  f0c31bc:	46006006 */ 	mov.s	$f0,$f12
/*  f0c31c0:	10000002 */ 	b	.L0f0c31cc
/*  f0c31c4:	46001006 */ 	mov.s	$f0,$f2
/*  f0c31c8:	46006006 */ 	mov.s	$f0,$f12
.L0f0c31cc:
/*  f0c31cc:	44070000 */ 	mfc1	$a3,$f0
/*  f0c31d0:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0c31d4:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0c31d8:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c31dc:	0c007733 */ 	jal	modelSetAnimation
/*  f0c31e0:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c31e4:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c31e8:	44805000 */ 	mtc1	$zero,$f10
/*  f0c31ec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c31f0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0c31f4:	4602503e */ 	c.le.s	$f10,$f2
/*  f0c31f8:	3c064180 */ 	lui	$a2,0x4180
/*  f0c31fc:	45020007 */ 	bc1fl	.L0f0c321c
/*  f0c3200:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0c3204:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0c3208:	44051000 */ 	mfc1	$a1,$f2
/*  f0c320c:	0c00777b */ 	jal	modelSetAnimLooping
/*  f0c3210:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3214:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c3218:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
.L0f0c321c:
/*  f0c321c:	44803000 */ 	mtc1	$zero,$f6
/*  f0c3220:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c3224:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c3228:	00000000 */ 	nop
/*  f0c322c:	45020017 */ 	bc1fl	.L0f0c328c
/*  f0c3230:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0c3234:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0c3238:	44052000 */ 	mfc1	$a1,$f4
/*  f0c323c:	0c007787 */ 	jal	modelSetAnimEndFrame
/*  f0c3240:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3244:	10000010 */ 	b	.L0f0c3288
/*  f0c3248:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c324c:	afa80048 */ 	sw	$t0,0x48($sp)
.L0f0c3250:
/*  f0c3250:	0c007498 */ 	jal	modelGetAnimSpeed
/*  f0c3254:	e7b20044 */ 	swc1	$f18,0x44($sp)
/*  f0c3258:	c7b20044 */ 	lwc1	$f18,0x44($sp)
/*  f0c325c:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c3260:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0c3264:	46120032 */ 	c.eq.s	$f0,$f18
/*  f0c3268:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0c326c:	45030007 */ 	bc1tl	.L0f0c328c
/*  f0c3270:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0c3274:	8f240020 */ 	lw	$a0,0x20($t9)
/*  f0c3278:	44059000 */ 	mfc1	$a1,$f18
/*  f0c327c:	0c0077ac */ 	jal	modelSetAnimSpeed
/*  f0c3280:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3284:	8fa80048 */ 	lw	$t0,0x48($sp)
.L0f0c3288:
/*  f0c3288:	8fa90078 */ 	lw	$t1,0x78($sp)
.L0f0c328c:
/*  f0c328c:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f0c3290:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c3294:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0c3298:	03e00008 */ 	jr	$ra
/*  f0c329c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0c32a0
/*  f0c32a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c32a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c32a8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0c32ac:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0c32b0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c32b4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0c32b8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0c32bc:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x64)
/*  f0c32c0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0c32c4:	8defa024 */ 	lw	$t7,%lo(g_Vars+0x64)($t7)
/*  f0c32c8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0c32cc:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0c32d0:	8df819c8 */ 	lw	$t8,0x19c8($t7)
/*  f0c32d4:	53000005 */ 	beqzl	$t8,.L0f0c32ec
/*  f0c32d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c32dc:	0fc094a2 */ 	jal	func0f025288
/*  f0c32e0:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0c32e4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0c32e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c32ec:
/*  f0c32ec:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f0c32f0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c32f4:	03e00008 */ 	jr	$ra
/*  f0c32f8:	00000000 */ 	nop
);

Gfx *currentPlayerLoadMatrix(Gfx *gdl)
{
	gSPMatrix(gdl++, g_Vars.currentplayer->matrix5c, G_MTX_LOAD);
	return gdl;
}

GLOBAL_ASM(
glabel func0f0c3320
/*  f0c3320:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0c3324:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0c3328:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0c332c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c3330:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0c3334:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0c3338:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0c333c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0c3340:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0c3344:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c3348:	18a0001f */ 	blez	$a1,.L0f0c33c8
/*  f0c334c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c3350:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f0c3354:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f0c3358:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c335c:	27b20040 */ 	addiu	$s2,$sp,0x40
.L0f0c3360:
/*  f0c3360:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f0c3364:	00000000 */ 	nop
/*  f0c3368:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c336c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0c3370:	0c0056f9 */ 	jal	func00015be4
/*  f0c3374:	02403025 */ 	or	$a2,$s2,$zero
/*  f0c3378:	8e620284 */ 	lw	$v0,0x284($s3)
/*  f0c337c:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f0c3380:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0c3384:	c4460038 */ 	lwc1	$f6,0x38($v0)
/*  f0c3388:	00117180 */ 	sll	$t6,$s1,0x6
/*  f0c338c:	01d52821 */ 	addu	$a1,$t6,$s5
/*  f0c3390:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c3394:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0c3398:	02402025 */ 	or	$a0,$s2,$zero
/*  f0c339c:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f0c33a0:	c450003c */ 	lwc1	$f16,0x3c($v0)
/*  f0c33a4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0c33a8:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f0c33ac:	c4460040 */ 	lwc1	$f6,0x40($v0)
/*  f0c33b0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c33b4:	0c005815 */ 	jal	func00016054
/*  f0c33b8:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f0c33bc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0c33c0:	1634ffe7 */ 	bne	$s1,$s4,.L0f0c3360
/*  f0c33c4:	26100040 */ 	addiu	$s0,$s0,0x40
.L0f0c33c8:
/*  f0c33c8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0c33cc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0c33d0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0c33d4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0c33d8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0c33dc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0c33e0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0c33e4:	03e00008 */ 	jr	$ra
/*  f0c33e8:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
