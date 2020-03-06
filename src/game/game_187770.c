#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_016100.h"
#include "game/game_01b0a0.h"
#include "game/game_096750.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_1165d0.h"
#include "game/game_127910.h"
#include "game/game_148b80.h"
#include "game/game_152fa0.h"
#include "game/game_1531a0.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_179060.h"
#include "game/game_187770.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_16110.h"
#include "lib/lib_317f0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1b8a00[] = "||||||||||||| Starting game... players %d\n";
const char var7f1b8a2c[] = "%s %d\n";
const char var7f1b8a34[] = "";
const char var7f1b8a38[] = "-mpwpnset";
const char var7f1b8a44[] = "-mpwpnset";
const char var7f1b8a50[] = "%s %d\n";
const char var7f1b8a58[] = "";
const char var7f1b8a5c[] = "Gun index %d -> slot %d = gun %d\n\n";
const char var7f1b8a80[] = "HOLDER: selecting weapon set %d\n";
const char var7f1b8aa4[] = "%d\n";

const u32 var7f1b8aa8[] = {0x00000002};
const u32 var7f1b8aac[] = {0x00000004};
const u32 var7f1b8ab0[] = {0x00000008};
const u32 var7f1b8ab4[] = {0x00000010};
const u32 var7f1b8ab8[] = {0x0000001c};
const u32 var7f1b8abc[] = {0x0000003c};
const u32 var7f1b8ac0[] = {0x00000064};
const u32 var7f1b8ac4[] = {0x00000096};
const u32 var7f1b8ac8[] = {0x000000d2};
const u32 var7f1b8acc[] = {0x0000012c};

const char var7f1b8ad0[] = "%s%sAccuracy Peak! real value: %f (*100)\n";
const char var7f1b8afc[] = "";
const char var7f1b8b00[] = "";
const char var7f1b8b04[] = "%splayer %d Accuracy :%f\n";
const char var7f1b8b20[] = "";
const char var7f1b8b24[] = "%splayer %d dist:%f -> %f = %d\n";
const char var7f1b8b44[] = "";
const char var7f1b8b48[] = "Player %d TitleCalc ============\n";
const char var7f1b8b6c[] = "Sim\n";
const char var7f1b8b74[] = "%s:%d\n";
const char var7f1b8b7c[] = "%s\n";
const char var7f1b8b80[] = "Adding GBCHead to load to slot %d: guid is %x-%x, player is %d\n";
const char var7f1b8bc0[] = "PakId for player %d: %d\n";
const char var7f1b8bdc[] = "Save Player Result: %d   New GUID: %x\n";
const char var7f1b8c04[] = "PakId for player %d: %d\n";
const char var7f1b8c20[] = "Load Player - Result: %d\n";
const char var7f1b8c3c[] = "";
const char var7f1b8c40[] = "bot %d headId %d bodyId %d\n";
const char var7f1b8c5c[] = "team change %s %d\n";
const char var7f1b8c70[] = "mplayer.c";
const char var7f1b8c7c[] = "team change %s %d\n";
const char var7f1b8c90[] = "mplayer.c";
const char var7f1b8c9c[] = "SaveMultiGameFile : PakId=0x%x, FileId=0x%x\n";
const char var7f1b8ccc[] = "SaveGame Result: %d   New GUID: %x\n";
const char var7f1b8cf0[] = "LoadMultiGameFile : PakId=0x%x, FileId=0x%x\n";
const char var7f1b8d20[] = "LoadGame Result: %d\n";
const char var7f1b8d38[] = "GBCHead: Call to create head for slot %d (gbcheadobjs[slotno]=%x)\n";

const u32 var7f1b8d7c[] = {0x3f666666};
const u32 var7f1b8d80[] = {0x3dcccccd};
const u32 var7f1b8d84[] = {0x7f187e40};
const u32 var7f1b8d88[] = {0x7f187e20};
const u32 var7f1b8d8c[] = {0x7f187e30};
const u32 var7f1b8d90[] = {0x7f187e0c};
const u32 var7f1b8d94[] = {0x7f187df8};
const u32 var7f1b8d98[] = {0x4852f000};
const u32 var7f1b8d9c[] = {0x47c35000};
const u32 var7f1b8da0[] = {0x461c4000};
const u32 var7f1b8da4[] = {0x3e99999a};
const u32 var7f1b8da8[] = {0x3f333333};
const u32 var7f1b8dac[] = {0x3dcccccd};
const u32 var7f1b8db0[] = {0x3dcccccd};
const u32 var7f1b8db4[] = {0x00000000};
const u32 var7f1b8db8[] = {0x00000000};
const u32 var7f1b8dbc[] = {0x00000000};

const char var7f1b8dc0[] = "RadarDrawDot : Prop=%x";

const u32 var7f1b8dd8[] = {0x40490fdb};
const u32 var7f1b8ddc[] = {0x3b83126f};
const u32 var7f1b8de0[] = {0x3c8efa35};
const u32 var7f1b8de4[] = {0x00000000};
const u32 var7f1b8de8[] = {0x00000000};
const u32 var7f1b8dec[] = {0x00000000};
const u32 var7f1b8df0[] = {0x7f190bcc};
const u32 var7f1b8df4[] = {0x7f1907f8};
const u32 var7f1b8df8[] = {0x7f190bcc};
const u32 var7f1b8dfc[] = {0x7f190bcc};
const u32 var7f1b8e00[] = {0x7f1907f8};
const u32 var7f1b8e04[] = {0x7f190a08};
const u32 var7f1b8e08[] = {0x7f190bcc};
const u32 var7f1b8e0c[] = {0x7f190bcc};
const u32 var7f1b8e10[] = {0x7f190bcc};
const u32 var7f1b8e14[] = {0x7f190bcc};
const u32 var7f1b8e18[] = {0x7f190bcc};
const u32 var7f1b8e1c[] = {0x7f190bcc};
const u32 var7f1b8e20[] = {0x7f190bcc};
const u32 var7f1b8e24[] = {0x7f190bcc};
const u32 var7f1b8e28[] = {0x7f190bcc};
const u32 var7f1b8e2c[] = {0x7f190bcc};
const u32 var7f1b8e30[] = {0x7f190bcc};
const u32 var7f1b8e34[] = {0x7f1908b0};
const u32 var7f1b8e38[] = {0x7f190b34};
const u32 var7f1b8e3c[] = {0x7f190bcc};
const u32 var7f1b8e40[] = {0x7f190bcc};
const u32 var7f1b8e44[] = {0x7f190bcc};
const u32 var7f1b8e48[] = {0x7f190bcc};
const u32 var7f1b8e4c[] = {0x7f190bcc};
const u32 var7f1b8e50[] = {0x7f190bcc};
const u32 var7f1b8e54[] = {0x7f190bcc};
const u32 var7f1b8e58[] = {0x7f190bcc};
const u32 var7f1b8e5c[] = {0x7f190bcc};
const u32 var7f1b8e60[] = {0x7f190bcc};
const u32 var7f1b8e64[] = {0x7f190bcc};
const u32 var7f1b8e68[] = {0x7f190bcc};
const u32 var7f1b8e6c[] = {0x7f190bcc};
const u32 var7f1b8e70[] = {0x7f190bcc};
const u32 var7f1b8e74[] = {0x7f190bcc};
const u32 var7f1b8e78[] = {0x7f190bcc};
const u32 var7f1b8e7c[] = {0x7f190bcc};
const u32 var7f1b8e80[] = {0x7f190bcc};
const u32 var7f1b8e84[] = {0x7f190bcc};
const u32 var7f1b8e88[] = {0x7f190bcc};
const u32 var7f1b8e8c[] = {0x7f190bcc};
const u32 var7f1b8e90[] = {0x7f190bcc};
const u32 var7f1b8e94[] = {0x7f190bcc};
const u32 var7f1b8e98[] = {0x7f190bcc};
const u32 var7f1b8e9c[] = {0x7f190bcc};
const u32 var7f1b8ea0[] = {0x7f190bcc};
const u32 var7f1b8ea4[] = {0x47742400};
const u32 var7f1b8ea8[] = {0x461c4000};
const u32 var7f1b8eac[] = {0x40c907a9};
const u32 var7f1b8eb0[] = {0x40c907a9};
const u32 var7f1b8eb4[] = {0x40c907a9};
const u32 var7f1b8eb8[] = {0x40c907a9};
const u32 var7f1b8ebc[] = {0x40490fdb};
const u32 var7f1b8ec0[] = {0x40c907a9};
const u32 var7f1b8ec4[] = {0x3edf5dd8};
const u32 var7f1b8ec8[] = {0x3fc907a8};
const u32 var7f1b8ecc[] = {0x40c907a9};
const u32 var7f1b8ed0[] = {0x40c907a9};
const u32 var7f1b8ed4[] = {0x3d566e92};
const u32 var7f1b8ed8[] = {0x40c907a9};
const u32 var7f1b8edc[] = {0x39a4af08};
const u32 var7f1b8ee0[] = {0x3d7c45d9};
const u32 var7f1b8ee4[] = {0xc0490fdb};
const u32 var7f1b8ee8[] = {0x40490fdb};
const u32 var7f1b8eec[] = {0x40490fdb};
const u32 var7f1b8ef0[] = {0x4181e420};
const u32 var7f1b8ef4[] = {0xc27e6668};
const u32 var7f1b8ef8[] = {0x3bce168a};
const u32 var7f1b8efc[] = {0x3b397ab1};
const u32 var7f1b8f00[] = {0x7f1920a8};
const u32 var7f1b8f04[] = {0x7f1920c0};
const u32 var7f1b8f08[] = {0x7f1920d4};
const u32 var7f1b8f0c[] = {0x7f1920e8};
const u32 var7f1b8f10[] = {0x7f1920fc};
const u32 var7f1b8f14[] = {0x7f192110};
const u32 var7f1b8f18[] = {0x40c66666};
const u32 var7f1b8f1c[] = {0x40f33333};
const u32 var7f1b8f20[] = {0x41166666};
const u32 var7f1b8f24[] = {0x41333333};
const u32 var7f1b8f28[] = {0x41333333};
const u32 var7f1b8f2c[] = {0x3eb33333};
const u32 var7f1b8f30[] = {0x3d6147b0};
const u32 var7f1b8f34[] = {0x3f71eb85};
const u32 var7f1b8f38[] = {0xc69c4000};
const u32 var7f1b8f3c[] = {0x37800080};
const u32 var7f1b8f40[] = {0x3f79999a};
const u32 var7f1b8f44[] = {0x3cccccc0};
const u32 var7f1b8f48[] = {0x40fccccd};
const u32 var7f1b8f4c[] = {0x4101999a};
const u32 var7f1b8f50[] = {0x40fccccd};
const u32 var7f1b8f54[] = {0x49742400};
const u32 var7f1b8f58[] = {0x7f196ec0};
const u32 var7f1b8f5c[] = {0x7f196f24};
const u32 var7f1b8f60[] = {0x7f196f24};
const u32 var7f1b8f64[] = {0x7f196f24};
const u32 var7f1b8f68[] = {0x7f196ec0};
const u32 var7f1b8f6c[] = {0x7f196ec0};
const u32 var7f1b8f70[] = {0x7f196ec0};
const u32 var7f1b8f74[] = {0x7f196f24};
const u32 var7f1b8f78[] = {0x7f196f24};
const u32 var7f1b8f7c[] = {0x7f196ec0};
const u32 var7f1b8f80[] = {0x7f196ec0};
const u32 var7f1b8f84[] = {0x7f196ec0};
const u32 var7f1b8f88[] = {0x7f196ec0};
const u32 var7f1b8f8c[] = {0x7f196ec0};
const u32 var7f1b8f90[] = {0x7f196ec0};
const u32 var7f1b8f94[] = {0x7f196ec0};
const u32 var7f1b8f98[] = {0x7f196ec0};
const u32 var7f1b8f9c[] = {0x7f196ec0};
const u32 var7f1b8fa0[] = {0x7f196ec0};
const u32 var7f1b8fa4[] = {0x7f196f9c};
const u32 var7f1b8fa8[] = {0x7f196ec0};
const u32 var7f1b8fac[] = {0x7f196ec0};
const u32 var7f1b8fb0[] = {0x7f196ec0};
const u32 var7f1b8fb4[] = {0x7f196ec0};
const u32 var7f1b8fb8[] = {0x7f196ec0};
const u32 var7f1b8fbc[] = {0x7f196f24};
const u32 var7f1b8fc0[] = {0x7f196ec0};
const u32 var7f1b8fc4[] = {0x7f196f78};
const u32 var7f1b8fc8[] = {0x3d4ccccd};
const u32 var7f1b8fcc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f187770
/*  f187770:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f187774:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f187778:	29c1007f */ 	slti	$at,$t6,0x7f
/*  f18777c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f187780:	10200014 */ 	beqz	$at,.L0f1877d4
/*  f187784:	01c01025 */ 	or	$v0,$t6,$zero
/*  f187788:	44842000 */ 	mtc1	$a0,$f4
/*  f18778c:	3c014f80 */ 	lui	$at,0x4f80
/*  f187790:	05c10004 */ 	bgez	$t6,.L0f1877a4
/*  f187794:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f187798:	44814000 */ 	mtc1	$at,$f8
/*  f18779c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1877a0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1877a4:
/*  f1877a4:	3c0142fe */ 	lui	$at,0x42fe
/*  f1877a8:	44815000 */ 	mtc1	$at,$f10
/*  f1877ac:	3c017f1c */ 	lui	$at,%hi(var7f1b8d7c)
/*  f1877b0:	c4328d7c */ 	lwc1	$f18,%lo(var7f1b8d7c)($at)
/*  f1877b4:	460a3083 */ 	div.s	$f2,$f6,$f10
/*  f1877b8:	3c017f1c */ 	lui	$at,%hi(var7f1b8d80)
/*  f1877bc:	c4288d80 */ 	lwc1	$f8,%lo(var7f1b8d80)($at)
/*  f1877c0:	46021402 */ 	mul.s	$f16,$f2,$f2
/*  f1877c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1877c8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f1877cc:	03e00008 */ 	jr	$ra
/*  f1877d0:	46082000 */ 	add.s	$f0,$f4,$f8
.L0f1877d4:
/*  f1877d4:	2401007f */ 	addiu	$at,$zero,0x7f
/*  f1877d8:	14410005 */ 	bne	$v0,$at,.L0f1877f0
/*  f1877dc:	244fff80 */ 	addiu	$t7,$v0,-128
/*  f1877e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1877e4:	44810000 */ 	mtc1	$at,$f0
/*  f1877e8:	03e00008 */ 	jr	$ra
/*  f1877ec:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1877f0:
/*  f1877f0:	448f3000 */ 	mtc1	$t7,$f6
/*  f1877f4:	3c0142fe */ 	lui	$at,0x42fe
/*  f1877f8:	44818000 */ 	mtc1	$at,$f16
/*  f1877fc:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f187800:	3c013f80 */ 	lui	$at,0x3f80
/*  f187804:	44812000 */ 	mtc1	$at,$f4
/*  f187808:	3c014040 */ 	lui	$at,0x4040
/*  f18780c:	44813000 */ 	mtc1	$at,$f6
/*  f187810:	3c014000 */ 	lui	$at,0x4000
/*  f187814:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f187818:	44818000 */ 	mtc1	$at,$f16
/*  f18781c:	46049080 */ 	add.s	$f2,$f18,$f4
/*  f187820:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f187824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187828:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f18782c:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f187830:	03e00008 */ 	jr	$ra
/*  f187834:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f187838
/*  f187838:	00001025 */ 	or	$v0,$zero,$zero
/*  f18783c:	00801825 */ 	or	$v1,$a0,$zero
/*  f187840:	2405000c */ 	addiu	$a1,$zero,0xc
.L0f187844:
/*  f187844:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f187848:	a4600024 */ 	sh	$zero,0x24($v1)
/*  f18784c:	1445fffd */ 	bne	$v0,$a1,.L0f187844
/*  f187850:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f187854:	a480003c */ 	sh	$zero,0x3c($a0)
/*  f187858:	a480003e */ 	sh	$zero,0x3e($a0)
/*  f18785c:	03e00008 */ 	jr	$ra
/*  f187860:	a4800040 */ 	sh	$zero,0x40($a0)
);

GLOBAL_ASM(
glabel func0f187864
/*  f187864:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f187868:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18786c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f187870:	0fc5fc98 */ 	jal	func0f17f260
/*  f187874:	00008025 */ 	or	$s0,$zero,$zero
/*  f187878:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18787c:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f187880:	14400006 */ 	bnez	$v0,.L0f18789c
/*  f187884:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f187888:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f18788c:	8cae000c */ 	lw	$t6,0xc($a1)
/*  f187890:	2401fffe */ 	addiu	$at,$zero,-2
/*  f187894:	01c17824 */ 	and	$t7,$t6,$at
/*  f187898:	acaf000c */ 	sw	$t7,0xc($a1)
.L0f18789c:
/*  f18789c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1878a0:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f1878a4:	3c05800b */ 	lui	$a1,%hi(g_MpSetup)
/*  f1878a8:	14400005 */ 	bnez	$v0,.L0f1878c0
/*  f1878ac:	24a5cb88 */ 	addiu	$a1,$a1,%lo(g_MpSetup)
/*  f1878b0:	8cb8000c */ 	lw	$t8,0xc($a1)
/*  f1878b4:	2401ff3f */ 	addiu	$at,$zero,-193
/*  f1878b8:	0301c824 */ 	and	$t9,$t8,$at
/*  f1878bc:	acb9000c */ 	sw	$t9,0xc($a1)
.L0f1878c0:
/*  f1878c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1878c4:	94a30016 */ 	lhu	$v1,0x16($a1)
/*  f1878c8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f1878cc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1878d0:
/*  f1878d0:	00484804 */ 	sllv	$t1,$t0,$v0
/*  f1878d4:	00695024 */ 	and	$t2,$v1,$t1
/*  f1878d8:	11400002 */ 	beqz	$t2,.L0f1878e4
/*  f1878dc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1878e0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1878e4:
/*  f1878e4:	5444fffa */ 	bnel	$v0,$a0,.L0f1878d0
/*  f1878e8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1878ec:	90a40011 */ 	lbu	$a0,0x11($a1)
/*  f1878f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1878f4:	14810004 */ 	bne	$a0,$at,.L0f187908
/*  f1878f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1878fc:	0fc5e441 */ 	jal	func0f179104
/*  f187900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187904:	00402025 */ 	or	$a0,$v0,$zero
.L0f187908:
/*  f187908:	0fc06c55 */ 	jal	func0f01b154
/*  f18790c:	afa40024 */ 	sw	$a0,0x24($sp)
/*  f187910:	0c003a57 */ 	jal	func0000e95c
/*  f187914:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f187918:	0fc068d5 */ 	jal	setNumPlayers
/*  f18791c:	02002025 */ 	or	$a0,$s0,$zero
/*  f187920:	0fc069f9 */ 	jal	func0f01a7e4
/*  f187924:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f187928:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18792c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f187930:	3c01800a */ 	lui	$at,0x800a
/*  f187934:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f187938:	ac2ba430 */ 	sw	$t3,-0x5bd0($at)
/*  f18793c:	03e00008 */ 	jr	$ra
/*  f187940:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f187944
/*  f187944:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f187948:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f18794c:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f187950:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f187954:	8eae0298 */ 	lw	$t6,0x298($s5)
/*  f187958:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f18795c:	2463c530 */ 	addiu	$v1,$v1,%lo(g_MpNumPlayers)
/*  f187960:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f187964:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f187968:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18796c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f187970:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f187974:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f187978:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18797c:	00009025 */ 	or	$s2,$zero,$zero
/*  f187980:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f187984:	05c10004 */ 	bgez	$t6,.L0f187998
/*  f187988:	aea20314 */ 	sw	$v0,0x314($s5)
/*  f18798c:	8eaf029c */ 	lw	$t7,0x29c($s5)
/*  f187990:	05e20004 */ 	bltzl	$t7,.L0f1879a4
/*  f187994:	aea20318 */ 	sw	$v0,0x318($s5)
.L0f187998:
/*  f187998:	10000002 */ 	beqz	$zero,.L0f1879a4
/*  f18799c:	aea00318 */ 	sw	$zero,0x318($s5)
/*  f1879a0:	aea20318 */ 	sw	$v0,0x318($s5)
.L0f1879a4:
/*  f1879a4:	0fc63319 */ 	jal	func0f18cc64
/*  f1879a8:	aea00470 */ 	sw	$zero,0x470($s5)
/*  f1879ac:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f1879b0:	10400003 */ 	beqz	$v0,.L0f1879c0
/*  f1879b4:	2463c530 */ 	addiu	$v1,$v1,%lo(g_MpNumPlayers)
/*  f1879b8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1879bc:	aeb8031c */ 	sw	$t8,0x31c($s5)
.L0f1879c0:
/*  f1879c0:	8eb90298 */ 	lw	$t9,0x298($s5)
/*  f1879c4:	3c04800b */ 	lui	$a0,%hi(var800aca38)
/*  f1879c8:	2484ca38 */ 	addiu	$a0,$a0,%lo(var800aca38)
/*  f1879cc:	07210003 */ 	bgez	$t9,.L0f1879dc
/*  f1879d0:	27a20048 */ 	addiu	$v0,$sp,0x48
/*  f1879d4:	8ea8029c */ 	lw	$t0,0x29c($s5)
/*  f1879d8:	0500008d */ 	bltz	$t0,.L0f187c10
.L0f1879dc:
/*  f1879dc:	3c05800b */ 	lui	$a1,%hi(var800acad8)
/*  f1879e0:	3c06800b */ 	lui	$a2,0x800b
/*  f1879e4:	3c14800b */ 	lui	$s4,%hi(g_MpPlayers)
/*  f1879e8:	2694c7b8 */ 	addiu	$s4,$s4,%lo(g_MpPlayers)
/*  f1879ec:	24c6c858 */ 	addiu	$a2,$a2,-14248
/*  f1879f0:	24a5cad8 */ 	addiu	$a1,$a1,%lo(var800acad8)
/*  f1879f4:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f1879f8:	00805825 */ 	or	$t3,$a0,$zero
/*  f1879fc:	00406025 */ 	or	$t4,$v0,$zero
/*  f187a00:	248a009c */ 	addiu	$t2,$a0,0x9c
.L0f187a04:
/*  f187a04:	8d610000 */ 	lw	$at,0x0($t3)
/*  f187a08:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f187a0c:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f187a10:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f187a14:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f187a18:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f187a1c:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f187a20:	156afff8 */ 	bne	$t3,$t2,.L0f187a04
/*  f187a24:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f187a28:	8d610000 */ 	lw	$at,0x0($t3)
/*  f187a2c:	02807825 */ 	or	$t7,$s4,$zero
/*  f187a30:	0080c025 */ 	or	$t8,$a0,$zero
/*  f187a34:	268e009c */ 	addiu	$t6,$s4,0x9c
/*  f187a38:	ad810000 */ 	sw	$at,0x0($t4)
.L0f187a3c:
/*  f187a3c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f187a40:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f187a44:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f187a48:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f187a4c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f187a50:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f187a54:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f187a58:	15eefff8 */ 	bne	$t7,$t6,.L0f187a3c
/*  f187a5c:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f187a60:	8de10000 */ 	lw	$at,0x0($t7)
/*  f187a64:	00404825 */ 	or	$t1,$v0,$zero
/*  f187a68:	02805025 */ 	or	$t2,$s4,$zero
/*  f187a6c:	2448009c */ 	addiu	$t0,$v0,0x9c
/*  f187a70:	af010000 */ 	sw	$at,0x0($t8)
.L0f187a74:
/*  f187a74:	8d210000 */ 	lw	$at,0x0($t1)
/*  f187a78:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f187a7c:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f187a80:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f187a84:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f187a88:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f187a8c:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f187a90:	1528fff8 */ 	bne	$t1,$t0,.L0f187a74
/*  f187a94:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f187a98:	8d210000 */ 	lw	$at,0x0($t1)
/*  f187a9c:	00a06825 */ 	or	$t5,$a1,$zero
/*  f187aa0:	00407025 */ 	or	$t6,$v0,$zero
/*  f187aa4:	24ac009c */ 	addiu	$t4,$a1,0x9c
/*  f187aa8:	ad410000 */ 	sw	$at,0x0($t2)
.L0f187aac:
/*  f187aac:	8da10000 */ 	lw	$at,0x0($t5)
/*  f187ab0:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f187ab4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f187ab8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f187abc:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f187ac0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f187ac4:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f187ac8:	15acfff8 */ 	bne	$t5,$t4,.L0f187aac
/*  f187acc:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f187ad0:	8da10000 */ 	lw	$at,0x0($t5)
/*  f187ad4:	00c0c825 */ 	or	$t9,$a2,$zero
/*  f187ad8:	00a04025 */ 	or	$t0,$a1,$zero
/*  f187adc:	24d8009c */ 	addiu	$t8,$a2,0x9c
/*  f187ae0:	adc10000 */ 	sw	$at,0x0($t6)
.L0f187ae4:
/*  f187ae4:	8f210000 */ 	lw	$at,0x0($t9)
/*  f187ae8:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f187aec:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f187af0:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f187af4:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f187af8:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f187afc:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f187b00:	1738fff8 */ 	bne	$t9,$t8,.L0f187ae4
/*  f187b04:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f187b08:	8f210000 */ 	lw	$at,0x0($t9)
/*  f187b0c:	00405825 */ 	or	$t3,$v0,$zero
/*  f187b10:	00c06025 */ 	or	$t4,$a2,$zero
/*  f187b14:	244a009c */ 	addiu	$t2,$v0,0x9c
/*  f187b18:	ad010000 */ 	sw	$at,0x0($t0)
.L0f187b1c:
/*  f187b1c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f187b20:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f187b24:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f187b28:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f187b2c:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f187b30:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f187b34:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f187b38:	156afff8 */ 	bne	$t3,$t2,.L0f187b1c
/*  f187b3c:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f187b40:	8d610000 */ 	lw	$at,0x0($t3)
/*  f187b44:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f187b48:	241300a0 */ 	addiu	$s3,$zero,0xa0
/*  f187b4c:	ad810000 */ 	sw	$at,0x0($t4)
/*  f187b50:	8ead0298 */ 	lw	$t5,0x298($s5)
/*  f187b54:	aea000e4 */ 	sw	$zero,0xe4($s5)
/*  f187b58:	a2800045 */ 	sb	$zero,0x45($s4)
/*  f187b5c:	05a00004 */ 	bltz	$t5,.L0f187b70
/*  f187b60:	a2870046 */ 	sb	$a3,0x46($s4)
/*  f187b64:	8eae0448 */ 	lw	$t6,0x448($s5)
/*  f187b68:	55c00008 */ 	bnezl	$t6,.L0f187b8c
/*  f187b6c:	8e990014 */ 	lw	$t9,0x14($s4)
.L0f187b70:
/*  f187b70:	8eaf029c */ 	lw	$t7,0x29c($s5)
/*  f187b74:	05e20009 */ 	bltzl	$t7,.L0f187b9c
/*  f187b78:	8e890014 */ 	lw	$t1,0x14($s4)
/*  f187b7c:	8eb8044c */ 	lw	$t8,0x44c($s5)
/*  f187b80:	53000006 */ 	beqzl	$t8,.L0f187b9c
/*  f187b84:	8e890014 */ 	lw	$t1,0x14($s4)
/*  f187b88:	8e990014 */ 	lw	$t9,0x14($s4)
.L0f187b8c:
/*  f187b8c:	37280004 */ 	ori	$t0,$t9,0x4
/*  f187b90:	10000005 */ 	beqz	$zero,.L0f187ba8
/*  f187b94:	ae880014 */ 	sw	$t0,0x14($s4)
/*  f187b98:	8e890014 */ 	lw	$t1,0x14($s4)
.L0f187b9c:
/*  f187b9c:	2401fffb */ 	addiu	$at,$zero,-5
/*  f187ba0:	01215024 */ 	and	$t2,$t1,$at
/*  f187ba4:	ae8a0014 */ 	sw	$t2,0x14($s4)
.L0f187ba8:
/*  f187ba8:	8eae0298 */ 	lw	$t6,0x298($s5)
/*  f187bac:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f187bb0:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f187bb4:	aeab0164 */ 	sw	$t3,0x164($s5)
/*  f187bb8:	a28c00e5 */ 	sb	$t4,0xe5($s4)
/*  f187bbc:	05c00004 */ 	bltz	$t6,.L0f187bd0
/*  f187bc0:	a28d00e6 */ 	sb	$t5,0xe6($s4)
/*  f187bc4:	8eaf0448 */ 	lw	$t7,0x448($s5)
/*  f187bc8:	55e00008 */ 	bnezl	$t7,.L0f187bec
/*  f187bcc:	8e8800b4 */ 	lw	$t0,0xb4($s4)
.L0f187bd0:
/*  f187bd0:	8eb8029c */ 	lw	$t8,0x29c($s5)
/*  f187bd4:	07020009 */ 	bltzl	$t8,.L0f187bfc
/*  f187bd8:	8e8a00b4 */ 	lw	$t2,0xb4($s4)
/*  f187bdc:	8eb9044c */ 	lw	$t9,0x44c($s5)
/*  f187be0:	53200006 */ 	beqzl	$t9,.L0f187bfc
/*  f187be4:	8e8a00b4 */ 	lw	$t2,0xb4($s4)
/*  f187be8:	8e8800b4 */ 	lw	$t0,0xb4($s4)
.L0f187bec:
/*  f187bec:	35090004 */ 	ori	$t1,$t0,0x4
/*  f187bf0:	10000005 */ 	beqz	$zero,.L0f187c08
/*  f187bf4:	ae8900b4 */ 	sw	$t1,0xb4($s4)
/*  f187bf8:	8e8a00b4 */ 	lw	$t2,0xb4($s4)
.L0f187bfc:
/*  f187bfc:	2401fffb */ 	addiu	$at,$zero,-5
/*  f187c00:	01415824 */ 	and	$t3,$t2,$at
/*  f187c04:	ae8b00b4 */ 	sw	$t3,0xb4($s4)
.L0f187c08:
/*  f187c08:	10000022 */ 	beqz	$zero,.L0f187c94
/*  f187c0c:	ac670000 */ 	sw	$a3,0x0($v1)
.L0f187c10:
/*  f187c10:	3c14800b */ 	lui	$s4,%hi(g_MpPlayers)
/*  f187c14:	2694c7b8 */ 	addiu	$s4,$s4,%lo(g_MpPlayers)
/*  f187c18:	00008025 */ 	or	$s0,$zero,$zero
/*  f187c1c:	241300a0 */ 	addiu	$s3,$zero,0xa0
.L0f187c20:
/*  f187c20:	3c0c800b */ 	lui	$t4,0x800b
/*  f187c24:	958ccb9e */ 	lhu	$t4,-0x3462($t4)
/*  f187c28:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f187c2c:	020d7004 */ 	sllv	$t6,$t5,$s0
/*  f187c30:	018e7824 */ 	and	$t7,$t4,$t6
/*  f187c34:	51e00014 */ 	beqzl	$t7,.L0f187c88
/*  f187c38:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187c3c:	02130019 */ 	multu	$s0,$s3
/*  f187c40:	0012c1c0 */ 	sll	$t8,$s2,0x7
/*  f187c44:	02b8c821 */ 	addu	$t9,$s5,$t8
/*  f187c48:	af3000e4 */ 	sw	$s0,0xe4($t9)
/*  f187c4c:	00004012 */ 	mflo	$t0
/*  f187c50:	02888821 */ 	addu	$s1,$s4,$t0
/*  f187c54:	a2300045 */ 	sb	$s0,0x45($s1)
/*  f187c58:	a2200046 */ 	sb	$zero,0x46($s1)
/*  f187c5c:	0fc62864 */ 	jal	func0f18a190
/*  f187c60:	02202025 */ 	or	$a0,$s1,$zero
/*  f187c64:	3c03800b */ 	lui	$v1,%hi(g_MpNumPlayers)
/*  f187c68:	2463c530 */ 	addiu	$v1,$v1,%lo(g_MpNumPlayers)
/*  f187c6c:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f187c70:	92290095 */ 	lbu	$t1,0x95($s1)
/*  f187c74:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f187c78:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f187c7c:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f187c80:	a2290096 */ 	sb	$t1,0x96($s1)
/*  f187c84:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f187c88:
/*  f187c88:	24010004 */ 	addiu	$at,$zero,0x4
/*  f187c8c:	1601ffe4 */ 	bne	$s0,$at,.L0f187c20
/*  f187c90:	00000000 */ 	sll	$zero,$zero,0x0
.L0f187c94:
/*  f187c94:	3c11800b */ 	lui	$s1,%hi(g_MpPlayerChrs)
/*  f187c98:	2631c4d0 */ 	addiu	$s1,$s1,%lo(g_MpPlayerChrs)
/*  f187c9c:	00008025 */ 	or	$s0,$zero,$zero
/*  f187ca0:	2412000c */ 	addiu	$s2,$zero,0xc
.L0f187ca4:
/*  f187ca4:	2a010004 */ 	slti	$at,$s0,0x4
/*  f187ca8:	10200006 */ 	beqz	$at,.L0f187cc4
/*  f187cac:	00106080 */ 	sll	$t4,$s0,0x2
/*  f187cb0:	02130019 */ 	multu	$s0,$s3
/*  f187cb4:	00006812 */ 	mflo	$t5
/*  f187cb8:	028d2021 */ 	addu	$a0,$s4,$t5
/*  f187cbc:	10000009 */ 	beqz	$zero,.L0f187ce4
/*  f187cc0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f187cc4:
/*  f187cc4:	01906021 */ 	addu	$t4,$t4,$s0
/*  f187cc8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187ccc:	01906023 */ 	subu	$t4,$t4,$s0
/*  f187cd0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187cd4:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f187cd8:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f187cdc:	258efed0 */ 	addiu	$t6,$t4,-304
/*  f187ce0:	01cf2021 */ 	addu	$a0,$t6,$t7
.L0f187ce4:
/*  f187ce4:	0fc61e0e */ 	jal	func0f187838
/*  f187ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187cec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187cf0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f187cf4:	1612ffeb */ 	bne	$s0,$s2,.L0f187ca4
/*  f187cf8:	ae20fffc */ 	sw	$zero,-0x4($s1)
/*  f187cfc:	3c01800b */ 	lui	$at,0x800b
/*  f187d00:	a020cba6 */ 	sb	$zero,-0x345a($at)
/*  f187d04:	8eb80318 */ 	lw	$t8,0x318($s5)
/*  f187d08:	3c138008 */ 	lui	$s3,%hi(var80087264)
/*  f187d0c:	26737264 */ 	addiu	$s3,$s3,%lo(var80087264)
/*  f187d10:	1300001a */ 	beqz	$t8,.L0f187d7c
/*  f187d14:	ae600000 */ 	sw	$zero,0x0($s3)
/*  f187d18:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f187d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187d20:	10400013 */ 	beqz	$v0,.L0f187d70
/*  f187d24:	00008025 */ 	or	$s0,$zero,$zero
/*  f187d28:	0fc63080 */ 	jal	func0f18c200
/*  f187d2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f187d30:	1840000b */ 	blez	$v0,.L0f187d60
/*  f187d34:	00409025 */ 	or	$s2,$v0,$zero
.L0f187d38:
/*  f187d38:	0fc630ac */ 	jal	func0f18c2b0
/*  f187d3c:	02002025 */ 	or	$a0,$s0,$zero
/*  f187d40:	10400002 */ 	beqz	$v0,.L0f187d4c
/*  f187d44:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187d48:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f187d4c:
/*  f187d4c:	0212082a */ 	slt	$at,$s0,$s2
/*  f187d50:	10200003 */ 	beqz	$at,.L0f187d60
/*  f187d54:	2a210002 */ 	slti	$at,$s1,0x2
/*  f187d58:	1420fff7 */ 	bnez	$at,.L0f187d38
/*  f187d5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f187d60:
/*  f187d60:	2a210002 */ 	slti	$at,$s1,0x2
/*  f187d64:	14200002 */ 	bnez	$at,.L0f187d70
/*  f187d68:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f187d6c:	ae790000 */ 	sw	$t9,0x0($s3)
.L0f187d70:
/*  f187d70:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f187d74:	3c01800b */ 	lui	$at,0x800b
/*  f187d78:	ac28cc24 */ 	sw	$t0,-0x33dc($at)
.L0f187d7c:
/*  f187d7c:	3c02800b */ 	lui	$v0,%hi(g_ActiveMenuMpBotCommands)
/*  f187d80:	3c03800b */ 	lui	$v1,0x800b
/*  f187d84:	2463cb81 */ 	addiu	$v1,$v1,-13439
/*  f187d88:	2442cb78 */ 	addiu	$v0,$v0,%lo(g_ActiveMenuMpBotCommands)
/*  f187d8c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f187d90:
/*  f187d90:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f187d94:	1443fffe */ 	bne	$v0,$v1,.L0f187d90
/*  f187d98:	a044ffff */ 	sb	$a0,-0x1($v0)
/*  f187d9c:	3c02800b */ 	lui	$v0,%hi(g_ActiveMenuMpBotCommands)
/*  f187da0:	2442cb78 */ 	addiu	$v0,$v0,%lo(g_ActiveMenuMpBotCommands)
/*  f187da4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f187da8:	240a000d */ 	addiu	$t2,$zero,0xd
/*  f187dac:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f187db0:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f187db4:	a0490001 */ 	sb	$t1,0x1($v0)
/*  f187db8:	a0440007 */ 	sb	$a0,0x7($v0)
/*  f187dbc:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f187dc0:	a04a0002 */ 	sb	$t2,0x2($v0)
/*  f187dc4:	a04b0003 */ 	sb	$t3,0x3($v0)
/*  f187dc8:	a04d0005 */ 	sb	$t5,0x5($v0)
/*  f187dcc:	3c0c800b */ 	lui	$t4,0x800b
/*  f187dd0:	918ccb98 */ 	lbu	$t4,-0x3468($t4)
/*  f187dd4:	258effff */ 	addiu	$t6,$t4,-1
/*  f187dd8:	2dc10005 */ 	sltiu	$at,$t6,0x5
/*  f187ddc:	1020001b */ 	beqz	$at,.L0f187e4c
/*  f187de0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f187de4:	3c017f1c */ 	lui	$at,%hi(var7f1b8d84)
/*  f187de8:	002e0821 */ 	addu	$at,$at,$t6
/*  f187dec:	8c2e8d84 */ 	lw	$t6,%lo(var7f1b8d84)($at)
/*  f187df0:	01c00008 */ 	jr	$t6
/*  f187df4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187df8:	240f0006 */ 	addiu	$t7,$zero,0x6
/*  f187dfc:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f187e00:	a04f0003 */ 	sb	$t7,0x3($v0)
/*  f187e04:	10000011 */ 	beqz	$zero,.L0f187e4c
/*  f187e08:	a0580005 */ 	sb	$t8,0x5($v0)
/*  f187e0c:	24190009 */ 	addiu	$t9,$zero,0x9
/*  f187e10:	2408000a */ 	addiu	$t0,$zero,0xa
/*  f187e14:	a0590006 */ 	sb	$t9,0x6($v0)
/*  f187e18:	1000000c */ 	beqz	$zero,.L0f187e4c
/*  f187e1c:	a0480008 */ 	sb	$t0,0x8($v0)
/*  f187e20:	24030005 */ 	addiu	$v1,$zero,0x5
/*  f187e24:	a0430006 */ 	sb	$v1,0x6($v0)
/*  f187e28:	10000008 */ 	beqz	$zero,.L0f187e4c
/*  f187e2c:	a0430008 */ 	sb	$v1,0x8($v0)
/*  f187e30:	2403000c */ 	addiu	$v1,$zero,0xc
/*  f187e34:	a0430006 */ 	sb	$v1,0x6($v0)
/*  f187e38:	10000004 */ 	beqz	$zero,.L0f187e4c
/*  f187e3c:	a0430008 */ 	sb	$v1,0x8($v0)
/*  f187e40:	2403000b */ 	addiu	$v1,$zero,0xb
/*  f187e44:	a0430006 */ 	sb	$v1,0x6($v0)
/*  f187e48:	a0430008 */ 	sb	$v1,0x8($v0)
.L0f187e4c:
/*  f187e4c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f187e50:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f187e54:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f187e58:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f187e5c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f187e60:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f187e64:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f187e68:	03e00008 */ 	jr	$ra
/*  f187e6c:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel func0f187e70
/*  f187e70:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f187e74:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f187e78:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f187e7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f187e80:	00001825 */ 	or	$v1,$zero,$zero
/*  f187e84:	11c00003 */ 	beqz	$t6,.L0f187e94
/*  f187e88:	3c09800b */ 	lui	$t1,%hi(g_MpNumPlayers)
/*  f187e8c:	10000001 */ 	beqz	$zero,.L0f187e94
/*  f187e90:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f187e94:
/*  f187e94:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f187e98:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayerChrs)
/*  f187e9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f187ea0:	11e00003 */ 	beqz	$t7,.L0f187eb0
/*  f187ea4:	25cec4d0 */ 	addiu	$t6,$t6,%lo(g_MpPlayerChrs)
/*  f187ea8:	10000001 */ 	beqz	$zero,.L0f187eb0
/*  f187eac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f187eb0:
/*  f187eb0:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f187eb4:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f187eb8:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f187ebc:	13000003 */ 	beqz	$t8,.L0f187ecc
/*  f187ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187ec4:	10000001 */ 	beqz	$zero,.L0f187ecc
/*  f187ec8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f187ecc:
/*  f187ecc:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f187ed0:	00002825 */ 	or	$a1,$zero,$zero
/*  f187ed4:	13200003 */ 	beqz	$t9,.L0f187ee4
/*  f187ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187edc:	10000001 */ 	beqz	$zero,.L0f187ee4
/*  f187ee0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f187ee4:
/*  f187ee4:	8d29c530 */ 	lw	$t1,%lo(g_MpNumPlayers)($t1)
/*  f187ee8:	00a45821 */ 	addu	$t3,$a1,$a0
/*  f187eec:	01636021 */ 	addu	$t4,$t3,$v1
/*  f187ef0:	01823821 */ 	addu	$a3,$t4,$v0
/*  f187ef4:	00e9082a */ 	slt	$at,$a3,$t1
/*  f187ef8:	1020002e */ 	beqz	$at,.L0f187fb4
/*  f187efc:	00e03025 */ 	or	$a2,$a3,$zero
/*  f187f00:	00076880 */ 	sll	$t5,$a3,0x2
/*  f187f04:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f187f08:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f187f0c:
/*  f187f0c:	3c18800b */ 	lui	$t8,%hi(g_MpPlayerChrs)
/*  f187f10:	2718c4d0 */ 	addiu	$t8,$t8,%lo(g_MpPlayerChrs)
/*  f187f14:	14600003 */ 	bnez	$v1,.L0f187f24
/*  f187f18:	00097880 */ 	sll	$t7,$t1,0x2
/*  f187f1c:	10000021 */ 	beqz	$zero,.L0f187fa4
/*  f187f20:	01f81821 */ 	addu	$v1,$t7,$t8
.L0f187f24:
/*  f187f24:	8c6402d4 */ 	lw	$a0,0x2d4($v1)
/*  f187f28:	3c09800b */ 	lui	$t1,%hi(g_MpNumPlayers)
/*  f187f2c:	908b004f */ 	lbu	$t3,0x4f($a0)
/*  f187f30:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f187f34:	a08c004f */ 	sb	$t4,0x4f($a0)
/*  f187f38:	8d4d000c */ 	lw	$t5,0xc($t2)
/*  f187f3c:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f187f40:	11c00013 */ 	beqz	$t6,.L0f187f90
/*  f187f44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187f48:	18e00011 */ 	blez	$a3,.L0f187f90
/*  f187f4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f187f50:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f187f54:	3c08800b */ 	lui	$t0,%hi(g_MpPlayerChrs)
/*  f187f58:	2508c4d0 */ 	addiu	$t0,$t0,%lo(g_MpPlayerChrs)
/*  f187f5c:	90650125 */ 	lbu	$a1,0x125($v1)
.L0f187f60:
/*  f187f60:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f187f64:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f187f68:	91f80125 */ 	lbu	$t8,0x125($t7)
/*  f187f6c:	14b80006 */ 	bne	$a1,$t8,.L0f187f88
/*  f187f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f187f74:	8c6402d4 */ 	lw	$a0,0x2d4($v1)
/*  f187f78:	9099004f */ 	lbu	$t9,0x4f($a0)
/*  f187f7c:	332bff7f */ 	andi	$t3,$t9,0xff7f
/*  f187f80:	10000003 */ 	beqz	$zero,.L0f187f90
/*  f187f84:	a08b004f */ 	sb	$t3,0x4f($a0)
.L0f187f88:
/*  f187f88:	1486fff5 */ 	bne	$a0,$a2,.L0f187f60
/*  f187f8c:	25080004 */ 	addiu	$t0,$t0,0x4
.L0f187f90:
/*  f187f90:	8d29c530 */ 	lw	$t1,%lo(g_MpNumPlayers)($t1)
/*  f187f94:	3c0d800b */ 	lui	$t5,%hi(g_MpPlayerChrs)
/*  f187f98:	25adc4d0 */ 	addiu	$t5,$t5,%lo(g_MpPlayerChrs)
/*  f187f9c:	00096080 */ 	sll	$t4,$t1,0x2
/*  f187fa0:	018d1821 */ 	addu	$v1,$t4,$t5
.L0f187fa4:
/*  f187fa4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f187fa8:	0043082b */ 	sltu	$at,$v0,$v1
/*  f187fac:	5420ffd7 */ 	bnezl	$at,.L0f187f0c
/*  f187fb0:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f187fb4:
/*  f187fb4:	03e00008 */ 	jr	$ra
/*  f187fb8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f187fbc
/*  f187fbc:	00047080 */ 	sll	$t6,$a0,0x2
/*  f187fc0:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f187fc4:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f187fc8:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f187fcc:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f187fd0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f187fd4:	24030050 */ 	addiu	$v1,$zero,0x50
/*  f187fd8:	2418004b */ 	addiu	$t8,$zero,0x4b
/*  f187fdc:	a4430018 */ 	sh	$v1,0x18($v0)
/*  f187fe0:	a443001a */ 	sh	$v1,0x1a($v0)
/*  f187fe4:	03e00008 */ 	jr	$ra
/*  f187fe8:	a458001c */ 	sh	$t8,0x1c($v0)
);

GLOBAL_ASM(
glabel func0f187fec
/*  f187fec:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f187ff0:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f187ff4:	24030009 */ 	addiu	$v1,$zero,0x9
/*  f187ff8:	240e0013 */ 	addiu	$t6,$zero,0x13
/*  f187ffc:	a0430012 */ 	sb	$v1,0x12($v0)
/*  f188000:	a0430013 */ 	sb	$v1,0x13($v0)
/*  f188004:	03e00008 */ 	jr	$ra
/*  f188008:	a44e0014 */ 	sh	$t6,0x14($v0)
);

GLOBAL_ASM(
glabel func0f18800c
/*  f18800c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f188010:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f188014:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188018:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18801c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f188020:	00809825 */ 	or	$s3,$a0,$zero
/*  f188024:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f188028:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18802c:	0fc61fef */ 	jal	func0f187fbc
/*  f188030:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188034:	00137080 */ 	sll	$t6,$s3,0x2
/*  f188038:	01d37021 */ 	addu	$t6,$t6,$s3
/*  f18803c:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f188040:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f188044:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f188048:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f18804c:	241807ee */ 	addiu	$t8,$zero,0x7ee
/*  f188050:	24190080 */ 	addiu	$t9,$zero,0x80
/*  f188054:	a2000044 */ 	sb	$zero,0x44($s0)
/*  f188058:	a6180048 */ 	sh	$t8,0x48($s0)
/*  f18805c:	1260000a */ 	beqz	$s3,.L0f188088
/*  f188060:	a219009d */ 	sb	$t9,0x9d($s0)
/*  f188064:	24010001 */ 	addiu	$at,$zero,0x1
/*  f188068:	12610009 */ 	beq	$s3,$at,.L0f188090
/*  f18806c:	24080011 */ 	addiu	$t0,$zero,0x11
/*  f188070:	24010002 */ 	addiu	$at,$zero,0x2
/*  f188074:	12610008 */ 	beq	$s3,$at,.L0f188098
/*  f188078:	2409000e */ 	addiu	$t1,$zero,0xe
/*  f18807c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f188080:	12610007 */ 	beq	$s3,$at,.L0f1880a0
/*  f188084:	240a0014 */ 	addiu	$t2,$zero,0x14
.L0f188088:
/*  f188088:	10000006 */ 	beqz	$zero,.L0f1880a4
/*  f18808c:	a2000010 */ 	sb	$zero,0x10($s0)
.L0f188090:
/*  f188090:	10000004 */ 	beqz	$zero,.L0f1880a4
/*  f188094:	a2080010 */ 	sb	$t0,0x10($s0)
.L0f188098:
/*  f188098:	10000002 */ 	beqz	$zero,.L0f1880a4
/*  f18809c:	a2090010 */ 	sb	$t1,0x10($s0)
.L0f1880a0:
/*  f1880a0:	a20a0010 */ 	sb	$t2,0x10($s0)
.L0f1880a4:
/*  f1880a4:	0fc62f27 */ 	jal	func0f18bc9c
/*  f1880a8:	92040010 */ 	lbu	$a0,0x10($s0)
/*  f1880ac:	240b000c */ 	addiu	$t3,$zero,0xc
/*  f1880b0:	a202000f */ 	sb	$v0,0xf($s0)
/*  f1880b4:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*  f1880b8:	ae00004c */ 	sw	$zero,0x4c($s0)
/*  f1880bc:	1220000b */ 	beqz	$s1,.L0f1880ec
/*  f1880c0:	a6000050 */ 	sh	$zero,0x50($s0)
/*  f1880c4:	0fc5b9f1 */ 	jal	langGet
/*  f1880c8:	240459b5 */ 	addiu	$a0,$zero,0x59b5
/*  f1880cc:	3c057f1c */ 	lui	$a1,%hi(var7f1b8a2c)
/*  f1880d0:	24a58a2c */ 	addiu	$a1,$a1,%lo(var7f1b8a2c)
/*  f1880d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1880d8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1880dc:	0c004dad */ 	jal	sprintf
/*  f1880e0:	26670001 */ 	addiu	$a3,$s3,0x1
/*  f1880e4:	10000003 */ 	beqz	$zero,.L0f1880f4
/*  f1880e8:	240c03e8 */ 	addiu	$t4,$zero,0x3e8
.L0f1880ec:
/*  f1880ec:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f1880f0:	240c03e8 */ 	addiu	$t4,$zero,0x3e8
.L0f1880f4:
/*  f1880f4:	2a610004 */ 	slti	$at,$s3,0x4
/*  f1880f8:	ae000054 */ 	sw	$zero,0x54($s0)
/*  f1880fc:	ae000058 */ 	sw	$zero,0x58($s0)
/*  f188100:	ae00005c */ 	sw	$zero,0x5c($s0)
/*  f188104:	ae000060 */ 	sw	$zero,0x60($s0)
/*  f188108:	ae000064 */ 	sw	$zero,0x64($s0)
/*  f18810c:	ae000068 */ 	sw	$zero,0x68($s0)
/*  f188110:	ae00006c */ 	sw	$zero,0x6c($s0)
/*  f188114:	ae0c0070 */ 	sw	$t4,0x70($s0)
/*  f188118:	ae000074 */ 	sw	$zero,0x74($s0)
/*  f18811c:	ae000078 */ 	sw	$zero,0x78($s0)
/*  f188120:	ae00007c */ 	sw	$zero,0x7c($s0)
/*  f188124:	ae000080 */ 	sw	$zero,0x80($s0)
/*  f188128:	ae000084 */ 	sw	$zero,0x84($s0)
/*  f18812c:	ae000088 */ 	sw	$zero,0x88($s0)
/*  f188130:	ae00008c */ 	sw	$zero,0x8c($s0)
/*  f188134:	ae000090 */ 	sw	$zero,0x90($s0)
/*  f188138:	10200012 */ 	beqz	$at,.L0f188184
/*  f18813c:	a2000095 */ 	sb	$zero,0x95($s0)
/*  f188140:	00008825 */ 	or	$s1,$zero,$zero
/*  f188144:	2414001e */ 	addiu	$s4,$zero,0x1e
/*  f188148:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f18814c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f188150:
/*  f188150:	02602025 */ 	or	$a0,$s3,$zero
.L0f188154:
/*  f188154:	02202825 */ 	or	$a1,$s1,$zero
/*  f188158:	02003025 */ 	or	$a2,$s0,$zero
/*  f18815c:	0fc6712e */ 	jal	mpSetChallengeCompletedByChrWithNumPlayers
/*  f188160:	00003825 */ 	or	$a3,$zero,$zero
/*  f188164:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188168:	5612fffa */ 	bnel	$s0,$s2,.L0f188154
/*  f18816c:	02602025 */ 	or	$a0,$s3,$zero
/*  f188170:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f188174:	5634fff6 */ 	bnel	$s1,$s4,.L0f188150
/*  f188178:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18817c:	0fc66bf7 */ 	jal	func0f19afdc
/*  f188180:	00000000 */ 	sll	$zero,$zero,0x0
.L0f188184:
/*  f188184:	00136880 */ 	sll	$t5,$s3,0x2
/*  f188188:	01b36821 */ 	addu	$t5,$t5,$s3
/*  f18818c:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f188190:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f188194:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f188198:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f18819c:	00008825 */ 	or	$s1,$zero,$zero
/*  f1881a0:	24030006 */ 	addiu	$v1,$zero,0x6
.L0f1881a4:
/*  f1881a4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1881a8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1881ac:	1623fffd */ 	bne	$s1,$v1,.L0f1881a4
/*  f1881b0:	a0400096 */ 	sb	$zero,0x96($v0)
/*  f1881b4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1881b8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1881bc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1881c0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1881c4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1881c8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1881cc:	03e00008 */ 	jr	$ra
/*  f1881d0:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f1881d4
/*  f1881d4:	00047080 */ 	sll	$t6,$a0,0x2
/*  f1881d8:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f1881dc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1881e0:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f1881e4:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f1881e8:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f1881ec:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1881f0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f1881f4:	24180006 */ 	addiu	$t8,$zero,0x6
/*  f1881f8:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f1881fc:	a040000f */ 	sb	$zero,0xf($v0)
/*  f188200:	a0400010 */ 	sb	$zero,0x10($v0)
/*  f188204:	a0400047 */ 	sb	$zero,0x47($v0)
/*  f188208:	03e00008 */ 	jr	$ra
/*  f18820c:	a0580048 */ 	sb	$t8,0x48($v0)
);

GLOBAL_ASM(
glabel func0f188210
/*  f188210:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f188214:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f188218:	3c0f001f */ 	lui	$t7,0x1f
/*  f18821c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f188220:	240e0032 */ 	addiu	$t6,$zero,0x32
/*  f188224:	35effe00 */ 	ori	$t7,$t7,0xfe00
/*  f188228:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18822c:	a0400010 */ 	sb	$zero,0x10($v0)
/*  f188230:	a04e0011 */ 	sb	$t6,0x11($v0)
/*  f188234:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f188238:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f18823c:	3c01800a */ 	lui	$at,0x800a
/*  f188240:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188244:	0fc61ffb */ 	jal	func0f187fec
/*  f188248:	ac38a444 */ 	sw	$t8,-0x5bbc($at)
/*  f18824c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f188250:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f188254:	3c057f1c */ 	lui	$a1,%hi(var7f1b8a34)
/*  f188258:	ac800020 */ 	sw	$zero,0x20($a0)
/*  f18825c:	a4800024 */ 	sh	$zero,0x24($a0)
/*  f188260:	0c004c4c */ 	jal	strcpy
/*  f188264:	24a58a34 */ 	addiu	$a1,$a1,%lo(var7f1b8a34)
/*  f188268:	00008025 */ 	or	$s0,$zero,$zero
/*  f18826c:	02002025 */ 	or	$a0,$s0,$zero
.L0f188270:
/*  f188270:	0fc62003 */ 	jal	func0f18800c
/*  f188274:	00002825 */ 	or	$a1,$zero,$zero
/*  f188278:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18827c:	2a010006 */ 	slti	$at,$s0,0x6
/*  f188280:	5420fffb */ 	bnezl	$at,.L0f188270
/*  f188284:	02002025 */ 	or	$a0,$s0,$zero
/*  f188288:	00008025 */ 	or	$s0,$zero,$zero
.L0f18828c:
/*  f18828c:	0fc62075 */ 	jal	func0f1881d4
/*  f188290:	02002025 */ 	or	$a0,$s0,$zero
/*  f188294:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188298:	2a010008 */ 	slti	$at,$s0,0x8
/*  f18829c:	1420fffb */ 	bnez	$at,.L0f18828c
/*  f1882a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1882a4:	3c057f1c */ 	lui	$a1,%hi(var7f1b8a38)
/*  f1882a8:	24a58a38 */ 	addiu	$a1,$a1,%lo(var7f1b8a38)
/*  f1882ac:	0c004c04 */ 	jal	func00013010
/*  f1882b0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1882b4:	10400009 */ 	beqz	$v0,.L0f1882dc
/*  f1882b8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1882bc:	3c057f1c */ 	lui	$a1,%hi(var7f1b8a44)
/*  f1882c0:	0c004c04 */ 	jal	func00013010
/*  f1882c4:	24a58a44 */ 	addiu	$a1,$a1,%lo(var7f1b8a44)
/*  f1882c8:	90440000 */ 	lbu	$a0,0x0($v0)
/*  f1882cc:	0fc6256f */ 	jal	func0f1895bc
/*  f1882d0:	2484ffd0 */ 	addiu	$a0,$a0,-48
/*  f1882d4:	10000003 */ 	beqz	$zero,.L0f1882e4
/*  f1882d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1882dc:
/*  f1882dc:	0fc6256f */ 	jal	func0f1895bc
/*  f1882e0:	00002025 */ 	or	$a0,$zero,$zero
.L0f1882e4:
/*  f1882e4:	3c02800b */ 	lui	$v0,%hi(g_MpLockPlayerNum)
/*  f1882e8:	2442cc20 */ 	addiu	$v0,$v0,%lo(g_MpLockPlayerNum)
/*  f1882ec:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f1882f0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f1882f4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f1882f8:	ac800314 */ 	sw	$zero,0x314($a0)
/*  f1882fc:	ac800318 */ 	sw	$zero,0x318($a0)
/*  f188300:	ac80031c */ 	sw	$zero,0x31c($a0)
/*  f188304:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f188308:	a0430001 */ 	sb	$v1,0x1($v0)
/*  f18830c:	a0430002 */ 	sb	$v1,0x2($v0)
/*  f188310:	a0430003 */ 	sb	$v1,0x3($v0)
/*  f188314:	0fc66fe8 */ 	jal	func0f19bfa0
/*  f188318:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f18831c:	3c05800b */ 	lui	$a1,%hi(g_MpPlayers)
/*  f188320:	3c06800b */ 	lui	$a2,%hi(g_ActiveMenuMpBotCommands)
/*  f188324:	24c6cb78 */ 	addiu	$a2,$a2,%lo(g_ActiveMenuMpBotCommands)
/*  f188328:	24a5c7b8 */ 	addiu	$a1,$a1,%lo(g_MpPlayers)
/*  f18832c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f188330:	00001025 */ 	or	$v0,$zero,$zero
.L0f188334:
/*  f188334:	00a01825 */ 	or	$v1,$a1,$zero
.L0f188338:
/*  f188338:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18833c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f188340:	1444fffd */ 	bne	$v0,$a0,.L0f188338
/*  f188344:	a0600096 */ 	sb	$zero,0x96($v1)
/*  f188348:	24a500a0 */ 	addiu	$a1,$a1,0xa0
/*  f18834c:	54a6fff9 */ 	bnel	$a1,$a2,.L0f188334
/*  f188350:	00001025 */ 	or	$v0,$zero,$zero
/*  f188354:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f188358:	3c01800b */ 	lui	$at,0x800b
/*  f18835c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188360:	a420cb9e */ 	sh	$zero,-0x3462($at)
/*  f188364:	03e00008 */ 	jr	$ra
/*  f188368:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f18836c
/*  f18836c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f188370:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f188374:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f188378:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
/*  f18837c:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f188380:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f188384:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f188388:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18838c:	15c00006 */ 	bnez	$t6,.L0f1883a8
/*  f188390:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f188394:	0fc5b9f1 */ 	jal	langGet
/*  f188398:	240459b6 */ 	addiu	$a0,$zero,0x59b6
/*  f18839c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1883a0:	0c004c4c */ 	jal	strcpy
/*  f1883a4:	00402825 */ 	or	$a1,$v0,$zero
.L0f1883a8:
/*  f1883a8:	3c11800b */ 	lui	$s1,0x800b
/*  f1883ac:	2631cbb0 */ 	addiu	$s1,$s1,-13392
/*  f1883b0:	00008025 */ 	or	$s0,$zero,$zero
.L0f1883b4:
/*  f1883b4:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f1883b8:	55e00007 */ 	bnezl	$t7,.L0f1883d8
/*  f1883bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1883c0:	0fc5b9f1 */ 	jal	langGet
/*  f1883c4:	26045608 */ 	addiu	$a0,$s0,0x5608
/*  f1883c8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1883cc:	0c004c4c */ 	jal	strcpy
/*  f1883d0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1883d4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1883d8:
/*  f1883d8:	2a010008 */ 	slti	$at,$s0,0x8
/*  f1883dc:	1420fff5 */ 	bnez	$at,.L0f1883b4
/*  f1883e0:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f1883e4:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers)
/*  f1883e8:	3c127f1c */ 	lui	$s2,%hi(var7f1b8a50)
/*  f1883ec:	26528a50 */ 	addiu	$s2,$s2,%lo(var7f1b8a50)
/*  f1883f0:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpPlayers)
/*  f1883f4:	00008025 */ 	or	$s0,$zero,$zero
/*  f1883f8:	24130004 */ 	addiu	$s3,$zero,0x4
.L0f1883fc:
/*  f1883fc:	92380000 */ 	lbu	$t8,0x0($s1)
/*  f188400:	57000009 */ 	bnezl	$t8,.L0f188428
/*  f188404:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188408:	0fc5b9f1 */ 	jal	langGet
/*  f18840c:	240459b5 */ 	addiu	$a0,$zero,0x59b5
/*  f188410:	02202025 */ 	or	$a0,$s1,$zero
/*  f188414:	02402825 */ 	or	$a1,$s2,$zero
/*  f188418:	00403025 */ 	or	$a2,$v0,$zero
/*  f18841c:	0c004dad */ 	jal	sprintf
/*  f188420:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f188424:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f188428:
/*  f188428:	1613fff4 */ 	bne	$s0,$s3,.L0f1883fc
/*  f18842c:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f188430:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188434:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f188438:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18843c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f188440:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f188444:	03e00008 */ 	jr	$ra
/*  f188448:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18844c
/*  f18844c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f188450:	3c0e800b */ 	lui	$t6,0x800b
/*  f188454:	91cecc10 */ 	lbu	$t6,-0x33f0($t6)
/*  f188458:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f18845c:	94820014 */ 	lhu	$v0,0x14($a0)
/*  f188460:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f188464:	14ce0030 */ 	bne	$a2,$t6,.L0f188528
/*  f188468:	00401825 */ 	or	$v1,$v0,$zero
/*  f18846c:	24010190 */ 	addiu	$at,$zero,0x190
/*  f188470:	1041002d */ 	beq	$v0,$at,.L0f188528
/*  f188474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188478:	90820010 */ 	lbu	$v0,0x10($a0)
/*  f18847c:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f188480:	00002025 */ 	or	$a0,$zero,$zero
/*  f188484:	10400002 */ 	beqz	$v0,.L0f188490
/*  f188488:	3c05800b */ 	lui	$a1,0x800b
/*  f18848c:	14e20026 */ 	bne	$a3,$v0,.L0f188528
.L0f188490:
/*  f188490:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f188494:	00001025 */ 	or	$v0,$zero,$zero
/*  f188498:	94a5cb9e */ 	lhu	$a1,-0x3462($a1)
/*  f18849c:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0f1884a0:
/*  f1884a0:	008fc004 */ 	sllv	$t8,$t7,$a0
/*  f1884a4:	00b8c824 */ 	and	$t9,$a1,$t8
/*  f1884a8:	13200002 */ 	beqz	$t9,.L0f1884b4
/*  f1884ac:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1884b0:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f1884b4:
/*  f1884b4:	5487fffa */ 	bnel	$a0,$a3,.L0f1884a0
/*  f1884b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1884bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1884c0:	10410019 */ 	beq	$v0,$at,.L0f188528
/*  f1884c4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1884c8:	10410008 */ 	beq	$v0,$at,.L0f1884ec
/*  f1884cc:	00034040 */ 	sll	$t0,$v1,0x1
/*  f1884d0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f1884d4:	10440007 */ 	beq	$v0,$a0,.L0f1884f4
/*  f1884d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1884dc:	1047000e */ 	beq	$v0,$a3,.L0f188518
/*  f1884e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1884e4:	03e00008 */ 	jr	$ra
/*  f1884e8:	00601025 */ 	or	$v0,$v1,$zero
.L0f1884ec:
/*  f1884ec:	03e00008 */ 	jr	$ra
/*  f1884f0:	25020001 */ 	addiu	$v0,$t0,0x1
.L0f1884f4:
/*  f1884f4:	00660019 */ 	multu	$v1,$a2
/*  f1884f8:	00001812 */ 	mflo	$v1
/*  f1884fc:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f188500:	04610003 */ 	bgez	$v1,.L0f188510
/*  f188504:	00034843 */ 	sra	$t1,$v1,0x1
/*  f188508:	24610001 */ 	addiu	$at,$v1,0x1
/*  f18850c:	00014843 */ 	sra	$t1,$at,0x1
.L0f188510:
/*  f188510:	03e00008 */ 	jr	$ra
/*  f188514:	2522ffff */ 	addiu	$v0,$t1,-1
.L0f188518:
/*  f188518:	00640019 */ 	multu	$v1,$a0
/*  f18851c:	00001812 */ 	mflo	$v1
/*  f188520:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f188524:	00000000 */ 	sll	$zero,$zero,0x0
.L0f188528:
/*  f188528:	03e00008 */ 	jr	$ra
/*  f18852c:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f188530
/*  f188530:	3c02800b */ 	lui	$v0,0x800b
/*  f188534:	9042cb9a */ 	lbu	$v0,-0x3466($v0)
/*  f188538:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18853c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f188540:	2841003c */ 	slti	$at,$v0,0x3c
/*  f188544:	14200005 */ 	bnez	$at,.L0f18855c
/*  f188548:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f18854c:	0fc5b372 */ 	jal	setVar80084028
/*  f188550:	00002025 */ 	or	$a0,$zero,$zero
/*  f188554:	10000007 */ 	beqz	$zero,.L0f188574
/*  f188558:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18855c:
/*  f18855c:	00822023 */ 	subu	$a0,$a0,$v0
/*  f188560:	00042140 */ 	sll	$a0,$a0,0x5
/*  f188564:	00822021 */ 	addu	$a0,$a0,$v0
/*  f188568:	00042100 */ 	sll	$a0,$a0,0x4
/*  f18856c:	0fc5b372 */ 	jal	setVar80084028
/*  f188570:	24840e10 */ 	addiu	$a0,$a0,0xe10
.L0f188574:
/*  f188574:	3c02800b */ 	lui	$v0,0x800b
/*  f188578:	9042cb9b */ 	lbu	$v0,-0x3465($v0)
/*  f18857c:	28410064 */ 	slti	$at,$v0,0x64
/*  f188580:	14200005 */ 	bnez	$at,.L0f188598
/*  f188584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188588:	0fc5b375 */ 	jal	setVar8008402c
/*  f18858c:	00002025 */ 	or	$a0,$zero,$zero
/*  f188590:	10000003 */ 	beqz	$zero,.L0f1885a0
/*  f188594:	00000000 */ 	sll	$zero,$zero,0x0
.L0f188598:
/*  f188598:	0fc5b375 */ 	jal	setVar8008402c
/*  f18859c:	24440001 */ 	addiu	$a0,$v0,0x1
.L0f1885a0:
/*  f1885a0:	3c0e800b */ 	lui	$t6,0x800b
/*  f1885a4:	95cecb9c */ 	lhu	$t6,-0x3464($t6)
/*  f1885a8:	29c10190 */ 	slti	$at,$t6,0x190
/*  f1885ac:	14200005 */ 	bnez	$at,.L0f1885c4
/*  f1885b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1885b4:	0fc5b378 */ 	jal	setVar80084030
/*  f1885b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1885bc:	10000006 */ 	beqz	$zero,.L0f1885d8
/*  f1885c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1885c4:
/*  f1885c4:	0fc62113 */ 	jal	func0f18844c
/*  f1885c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1885cc:	0fc5b378 */ 	jal	setVar80084030
/*  f1885d0:	24440001 */ 	addiu	$a0,$v0,0x1
/*  f1885d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1885d8:
/*  f1885d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1885dc:	03e00008 */ 	jr	$ra
/*  f1885e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1885e4
/*  f1885e4:	27bdfdc8 */ 	addiu	$sp,$sp,-568
/*  f1885e8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1885ec:	3c14800b */ 	lui	$s4,%hi(g_MpSetup)
/*  f1885f0:	2694cb88 */ 	addiu	$s4,$s4,%lo(g_MpSetup)
/*  f1885f4:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f1885f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1885fc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f188600:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f188604:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188608:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18860c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188610:	afa40238 */ 	sw	$a0,0x238($sp)
/*  f188614:	11e00004 */ 	beqz	$t7,.L0f188628
/*  f188618:	00008025 */ 	or	$s0,$zero,$zero
/*  f18861c:	0fc622a1 */ 	jal	func0f188a84
/*  f188620:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f188624:	afa2016c */ 	sw	$v0,0x16c($sp)
.L0f188628:
/*  f188628:	8fac016c */ 	lw	$t4,0x16c($sp)
/*  f18862c:	00008825 */ 	or	$s1,$zero,$zero
/*  f188630:	27b301d4 */ 	addiu	$s3,$sp,0x1d4
/*  f188634:	96980016 */ 	lhu	$t8,0x16($s4)
.L0f188638:
/*  f188638:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18863c:	02397004 */ 	sllv	$t6,$t9,$s1
/*  f188640:	030e7824 */ 	and	$t7,$t8,$t6
/*  f188644:	11e00064 */ 	beqz	$t7,.L0f1887d8
/*  f188648:	00004025 */ 	or	$t0,$zero,$zero
/*  f18864c:	2a210004 */ 	slti	$at,$s1,0x4
/*  f188650:	10200008 */ 	beqz	$at,.L0f188674
/*  f188654:	00001825 */ 	or	$v1,$zero,$zero
/*  f188658:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f18865c:	0331c821 */ 	addu	$t9,$t9,$s1
/*  f188660:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f188664:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f188668:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18866c:	1000000a */ 	beqz	$zero,.L0f188698
/*  f188670:	03389021 */ 	addu	$s2,$t9,$t8
.L0f188674:
/*  f188674:	00117080 */ 	sll	$t6,$s1,0x2
/*  f188678:	01d17021 */ 	addu	$t6,$t6,$s1
/*  f18867c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f188680:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f188684:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f188688:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18868c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f188690:	25cffed0 */ 	addiu	$t7,$t6,-304
/*  f188694:	01f99021 */ 	addu	$s2,$t7,$t9
.L0f188698:
/*  f188698:	02402025 */ 	or	$a0,$s2,$zero
/*  f18869c:	02202825 */ 	or	$a1,$s1,$zero
/*  f1886a0:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f1886a4:	27a7006c */ 	addiu	$a3,$sp,0x6c
/*  f1886a8:	afa30060 */ 	sw	$v1,0x60($sp)
/*  f1886ac:	afa80064 */ 	sw	$t0,0x64($sp)
/*  f1886b0:	0fc61705 */ 	jal	func0f185c14
/*  f1886b4:	afac016c */ 	sw	$t4,0x16c($sp)
/*  f1886b8:	8fa30060 */ 	lw	$v1,0x60($sp)
/*  f1886bc:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f1886c0:	8fac016c */ 	lw	$t4,0x16c($sp)
/*  f1886c4:	1a000017 */ 	blez	$s0,.L0f188724
/*  f1886c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1886cc:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f1886d0:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f1886d4:	34018000 */ 	dli	$at,0x8000
/*  f1886d8:	0161c021 */ 	addu	$t8,$t3,$at
/*  f1886dc:	00187400 */ 	sll	$t6,$t8,0x10
/*  f1886e0:	3419ffff */ 	dli	$t9,0xffff
/*  f1886e4:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f1886e8:	0000c880 */ 	sll	$t9,$zero,0x2
/*  f1886ec:	02791021 */ 	addu	$v0,$s3,$t9
/*  f1886f0:	01d84825 */ 	or	$t1,$t6,$t8
/*  f1886f4:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f1886f8:
/*  f1886f8:	01e9082b */ 	sltu	$at,$t7,$t1
/*  f1886fc:	50200004 */ 	beqzl	$at,.L0f188710
/*  f188700:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f188704:	00804025 */ 	or	$t0,$a0,$zero
/*  f188708:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f18870c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f188710:
/*  f188710:	0090082a */ 	slt	$at,$a0,$s0
/*  f188714:	10200003 */ 	beqz	$at,.L0f188724
/*  f188718:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18871c:	5060fff6 */ 	beqzl	$v1,.L0f1886f8
/*  f188720:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f188724:
/*  f188724:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f188728:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f18872c:	34018000 */ 	dli	$at,0x8000
/*  f188730:	01617021 */ 	addu	$t6,$t3,$at
/*  f188734:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f188738:	340fffff */ 	dli	$t7,0xffff
/*  f18873c:	01f97023 */ 	subu	$t6,$t7,$t9
/*  f188740:	14600002 */ 	bnez	$v1,.L0f18874c
/*  f188744:	030e4825 */ 	or	$t1,$t8,$t6
/*  f188748:	02004025 */ 	or	$t0,$s0,$zero
.L0f18874c:
/*  f18874c:	0110082a */ 	slt	$at,$t0,$s0
/*  f188750:	10200017 */ 	beqz	$at,.L0f1887b0
/*  f188754:	02002025 */ 	or	$a0,$s0,$zero
/*  f188758:	00045080 */ 	sll	$t2,$a0,0x2
/*  f18875c:	27af0204 */ 	addiu	$t7,$sp,0x204
/*  f188760:	27b901a4 */ 	addiu	$t9,$sp,0x1a4
/*  f188764:	27b80174 */ 	addiu	$t8,$sp,0x174
/*  f188768:	01583021 */ 	addu	$a2,$t2,$t8
/*  f18876c:	01592821 */ 	addu	$a1,$t2,$t9
/*  f188770:	014f3821 */ 	addu	$a3,$t2,$t7
/*  f188774:	026a1021 */ 	addu	$v0,$s3,$t2
.L0f188778:
/*  f188778:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f18877c:	8ceffffc */ 	lw	$t7,-0x4($a3)
/*  f188780:	8cb9fffc */ 	lw	$t9,-0x4($a1)
/*  f188784:	8cd8fffc */ 	lw	$t8,-0x4($a2)
/*  f188788:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f18878c:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f188790:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f188794:	24a5fffc */ 	addiu	$a1,$a1,-4
/*  f188798:	24c6fffc */ 	addiu	$a2,$a2,-4
/*  f18879c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1887a0:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f1887a4:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1887a8:	1504fff3 */ 	bne	$t0,$a0,.L0f188778
/*  f1887ac:	acd80004 */ 	sw	$t8,0x4($a2)
.L0f1887b0:
/*  f1887b0:	00081080 */ 	sll	$v0,$t0,0x2
/*  f1887b4:	02627021 */ 	addu	$t6,$s3,$v0
/*  f1887b8:	adc90000 */ 	sw	$t1,0x0($t6)
/*  f1887bc:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f1887c0:	adeb0204 */ 	sw	$t3,0x204($t7)
/*  f1887c4:	03a2c821 */ 	addu	$t9,$sp,$v0
/*  f1887c8:	af3201a4 */ 	sw	$s2,0x1a4($t9)
/*  f1887cc:	03a2c021 */ 	addu	$t8,$sp,$v0
/*  f1887d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1887d4:	af110174 */ 	sw	$s1,0x174($t8)
.L0f1887d8:
/*  f1887d8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1887dc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1887e0:	5621ff95 */ 	bnel	$s1,$at,.L0f188638
/*  f1887e4:	96980016 */ 	lhu	$t8,0x16($s4)
/*  f1887e8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1887ec:	241fffff */ 	addiu	$ra,$zero,-1
/*  f1887f0:	1a00003a */ 	blez	$s0,.L0f1888dc
/*  f1887f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1887f8:	00005025 */ 	or	$t2,$zero,$zero
/*  f1887fc:	27a70204 */ 	addiu	$a3,$sp,0x204
/*  f188800:	27a501a4 */ 	addiu	$a1,$sp,0x1a4
/*  f188804:	27a60174 */ 	addiu	$a2,$sp,0x174
/*  f188808:	8fab0238 */ 	lw	$t3,0x238($sp)
/*  f18880c:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f188810:	241100ff */ 	addiu	$s1,$zero,0xff
.L0f188814:
/*  f188814:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f188818:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f18881c:	256b0014 */ 	addiu	$t3,$t3,0x14
/*  f188820:	ad6effec */ 	sw	$t6,-0x14($t3)
/*  f188824:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f188828:	ad64fff4 */ 	sw	$a0,-0xc($t3)
/*  f18882c:	a160fff8 */ 	sb	$zero,-0x8($t3)
/*  f188830:	ad6ffff0 */ 	sw	$t7,-0x10($t3)
/*  f188834:	8cf9fffc */ 	lw	$t9,-0x4($a3)
/*  f188838:	2589ffff */ 	addiu	$t1,$t4,-1
/*  f18883c:	ad79fffc */ 	sw	$t9,-0x4($t3)
/*  f188840:	8e98000c */ 	lw	$t8,0xc($s4)
/*  f188844:	330e0002 */ 	andi	$t6,$t8,0x2
/*  f188848:	51c00014 */ 	beqzl	$t6,.L0f18889c
/*  f18884c:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f188850:	1980000b */ 	blez	$t4,.L0f188880
/*  f188854:	00001025 */ 	or	$v0,$zero,$zero
/*  f188858:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f18885c:	27a3007c */ 	addiu	$v1,$sp,0x7c
/*  f188860:	91e80011 */ 	lbu	$t0,0x11($t7)
.L0f188864:
/*  f188864:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f188868:	57280003 */ 	bnel	$t9,$t0,.L0f188878
/*  f18886c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f188870:	00404825 */ 	or	$t1,$v0,$zero
/*  f188874:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f188878:
/*  f188878:	144cfffa */ 	bne	$v0,$t4,.L0f188864
/*  f18887c:	24630014 */ 	addiu	$v1,$v1,0x14
.L0f188880:
/*  f188880:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f188884:	02297023 */ 	subu	$t6,$s1,$t1
/*  f188888:	a309001e */ 	sb	$t1,0x1e($t8)
/*  f18888c:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f188890:	10000007 */ 	beqz	$zero,.L0f1888b0
/*  f188894:	adee0020 */ 	sw	$t6,0x20($t7)
/*  f188898:	8cb90000 */ 	lw	$t9,0x0($a1)
.L0f18889c:
/*  f18889c:	026ac021 */ 	addu	$t8,$s3,$t2
/*  f1888a0:	a324001e */ 	sb	$a0,0x1e($t9)
/*  f1888a4:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f1888a8:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f1888ac:	adee0020 */ 	sw	$t6,0x20($t7)
.L0f1888b0:
/*  f1888b0:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1888b4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1888b8:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f1888bc:	28410004 */ 	slti	$at,$v0,0x4
/*  f1888c0:	10200004 */ 	beqz	$at,.L0f1888d4
/*  f1888c4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1888c8:	15b20002 */ 	bne	$t5,$s2,.L0f1888d4
/*  f1888cc:	0040f825 */ 	or	$ra,$v0,$zero
/*  f1888d0:	00406825 */ 	or	$t5,$v0,$zero
.L0f1888d4:
/*  f1888d4:	1490ffcf */ 	bne	$a0,$s0,.L0f188814
/*  f1888d8:	24c60004 */ 	addiu	$a2,$a2,0x4
.L0f1888dc:
/*  f1888dc:	3c11800b */ 	lui	$s1,%hi(g_MpLockPlayerNum)
/*  f1888e0:	2631cc20 */ 	addiu	$s1,$s1,%lo(g_MpLockPlayerNum)
/*  f1888e4:	a22d0001 */ 	sb	$t5,0x1($s1)
/*  f1888e8:	a23f0002 */ 	sb	$ra,0x2($s1)
/*  f1888ec:	3c19800b */ 	lui	$t9,0x800b
/*  f1888f0:	9339cc10 */ 	lbu	$t9,-0x33f0($t9)
/*  f1888f4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1888f8:	57210005 */ 	bnel	$t9,$at,.L0f188910
/*  f1888fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f188900:	0fc62fba */ 	jal	func0f18bee8
/*  f188904:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188908:	a2220000 */ 	sb	$v0,0x0($s1)
/*  f18890c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f188910:
/*  f188910:	02001025 */ 	or	$v0,$s0,$zero
/*  f188914:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188918:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18891c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188920:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188924:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188928:	03e00008 */ 	jr	$ra
/*  f18892c:	27bd0238 */ 	addiu	$sp,$sp,0x238
);

GLOBAL_ASM(
glabel func0f188930
/*  f188930:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f188934:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f188938:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18893c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f188940:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f188944:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f188948:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18894c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188950:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188954:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188958:	3c14800b */ 	lui	$s4,%hi(g_MpSetup)
/*  f18895c:	3c15800b */ 	lui	$s5,%hi(g_MpPlayers)
/*  f188960:	00809825 */ 	or	$s3,$a0,$zero
/*  f188964:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f188968:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f18896c:	00008825 */ 	or	$s1,$zero,$zero
/*  f188970:	00009025 */ 	or	$s2,$zero,$zero
/*  f188974:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f188978:	26b5c7b8 */ 	addiu	$s5,$s5,%lo(g_MpPlayers)
/*  f18897c:	2694cb88 */ 	addiu	$s4,$s4,%lo(g_MpSetup)
/*  f188980:	00008025 */ 	or	$s0,$zero,$zero
/*  f188984:	241600a0 */ 	addiu	$s6,$zero,0xa0
/*  f188988:	27b70044 */ 	addiu	$s7,$sp,0x44
/*  f18898c:	27be0040 */ 	addiu	$s8,$sp,0x40
/*  f188990:	968e0016 */ 	lhu	$t6,0x16($s4)
.L0f188994:
/*  f188994:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f188998:	020fc004 */ 	sllv	$t8,$t7,$s0
/*  f18899c:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f1889a0:	1320001c */ 	beqz	$t9,.L0f188a14
/*  f1889a4:	2a010004 */ 	slti	$at,$s0,0x4
/*  f1889a8:	10200006 */ 	beqz	$at,.L0f1889c4
/*  f1889ac:	00104880 */ 	sll	$t1,$s0,0x2
/*  f1889b0:	02160019 */ 	multu	$s0,$s6
/*  f1889b4:	00004012 */ 	mflo	$t0
/*  f1889b8:	02a82021 */ 	addu	$a0,$s5,$t0
/*  f1889bc:	1000000a */ 	beqz	$zero,.L0f1889e8
/*  f1889c0:	908c0011 */ 	lbu	$t4,0x11($a0)
.L0f1889c4:
/*  f1889c4:	01304821 */ 	addu	$t1,$t1,$s0
/*  f1889c8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1889cc:	01304823 */ 	subu	$t1,$t1,$s0
/*  f1889d0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1889d4:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f1889d8:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f1889dc:	252afed0 */ 	addiu	$t2,$t1,-304
/*  f1889e0:	014b2021 */ 	addu	$a0,$t2,$t3
/*  f1889e4:	908c0011 */ 	lbu	$t4,0x11($a0)
.L0f1889e8:
/*  f1889e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1889ec:	02e03025 */ 	or	$a2,$s7,$zero
/*  f1889f0:	166c0008 */ 	bne	$s3,$t4,.L0f188a14
/*  f1889f4:	03c03825 */ 	or	$a3,$s8,$zero
/*  f1889f8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1889fc:	0fc61705 */ 	jal	func0f185c14
/*  f188a00:	afad0050 */ 	sw	$t5,0x50($sp)
/*  f188a04:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f188a08:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f188a0c:	022f8821 */ 	addu	$s1,$s1,$t7
/*  f188a10:	024e9021 */ 	addu	$s2,$s2,$t6
.L0f188a14:
/*  f188a14:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188a18:	2401000c */ 	addiu	$at,$zero,0xc
/*  f188a1c:	5601ffdd */ 	bnel	$s0,$at,.L0f188994
/*  f188a20:	968e0016 */ 	lhu	$t6,0x16($s4)
/*  f188a24:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f188a28:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f188a2c:	34018000 */ 	dli	$at,0x8000
/*  f188a30:	13000008 */ 	beqz	$t8,.L0f188a54
/*  f188a34:	00001025 */ 	or	$v0,$zero,$zero
/*  f188a38:	02214021 */ 	addu	$t0,$s1,$at
/*  f188a3c:	340affff */ 	dli	$t2,0xffff
/*  f188a40:	01525823 */ 	subu	$t3,$t2,$s2
/*  f188a44:	00084c00 */ 	sll	$t1,$t0,0x10
/*  f188a48:	af310000 */ 	sw	$s1,0x0($t9)
/*  f188a4c:	10000001 */ 	beqz	$zero,.L0f188a54
/*  f188a50:	012b1025 */ 	or	$v0,$t1,$t3
.L0f188a54:
/*  f188a54:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f188a58:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188a5c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188a60:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188a64:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188a68:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188a6c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f188a70:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f188a74:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f188a78:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f188a7c:	03e00008 */ 	jr	$ra
/*  f188a80:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f188a84
/*  f188a84:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f188a88:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f188a8c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f188a90:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f188a94:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188a98:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188a9c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188aa0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188aa4:	0080b025 */ 	or	$s6,$a0,$zero
/*  f188aa8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f188aac:	0000a825 */ 	or	$s5,$zero,$zero
/*  f188ab0:	00008025 */ 	or	$s0,$zero,$zero
/*  f188ab4:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f188ab8:	27b20068 */ 	addiu	$s2,$sp,0x68
/*  f188abc:	27b30048 */ 	addiu	$s3,$sp,0x48
/*  f188ac0:	2414e0c0 */ 	addiu	$s4,$zero,-8000
.L0f188ac4:
/*  f188ac4:	ae540000 */ 	sw	$s4,0x0($s2)
/*  f188ac8:	02002025 */ 	or	$a0,$s0,$zero
/*  f188acc:	0fc6224c */ 	jal	func0f188930
/*  f188ad0:	02402825 */ 	or	$a1,$s2,$zero
/*  f188ad4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188ad8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f188adc:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f188ae0:	1611fff8 */ 	bne	$s0,$s1,.L0f188ac4
/*  f188ae4:	ae62fffc */ 	sw	$v0,-0x4($s3)
/*  f188ae8:	27ab0068 */ 	addiu	$t3,$sp,0x68
/*  f188aec:	240a0014 */ 	addiu	$t2,$zero,0x14
/*  f188af0:	27a90048 */ 	addiu	$t1,$sp,0x48
/*  f188af4:	24080007 */ 	addiu	$t0,$zero,0x7
/*  f188af8:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f188afc:	00002825 */ 	or	$a1,$zero,$zero
.L0f188b00:
/*  f188b00:	02803025 */ 	or	$a2,$s4,$zero
/*  f188b04:	00008025 */ 	or	$s0,$zero,$zero
/*  f188b08:	00001825 */ 	or	$v1,$zero,$zero
/*  f188b0c:	27a40084 */ 	addiu	$a0,$sp,0x84
.L0f188b10:
/*  f188b10:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f188b14:	00037823 */ 	negu	$t7,$v1
/*  f188b18:	2484fffc */ 	addiu	$a0,$a0,-4
/*  f188b1c:	29c1e0c1 */ 	slti	$at,$t6,-7999
/*  f188b20:	14200009 */ 	bnez	$at,.L0f188b48
/*  f188b24:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f188b28:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f188b2c:	0325082b */ 	sltu	$at,$t9,$a1
/*  f188b30:	54200006 */ 	bnezl	$at,.L0f188b4c
/*  f188b34:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188b38:	01103023 */ 	subu	$a2,$t0,$s0
/*  f188b3c:	00066080 */ 	sll	$t4,$a2,0x2
/*  f188b40:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f188b44:	8da50000 */ 	lw	$a1,0x0($t5)
.L0f188b48:
/*  f188b48:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f188b4c:
/*  f188b4c:	1611fff0 */ 	bne	$s0,$s1,.L0f188b10
/*  f188b50:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f188b54:	28c1e0c1 */ 	slti	$at,$a2,-7999
/*  f188b58:	1420000f */ 	bnez	$at,.L0f188b98
/*  f188b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188b60:	02aa0019 */ 	multu	$s5,$t2
/*  f188b64:	26a30001 */ 	addiu	$v1,$s5,0x1
/*  f188b68:	00067880 */ 	sll	$t7,$a2,0x2
/*  f188b6c:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f188b70:	0060a825 */ 	or	$s5,$v1,$zero
/*  f188b74:	00007012 */ 	mflo	$t6
/*  f188b78:	02ce1021 */ 	addu	$v0,$s6,$t6
/*  f188b7c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f188b80:	ac460004 */ 	sw	$a2,0x4($v0)
/*  f188b84:	ac430008 */ 	sw	$v1,0x8($v0)
/*  f188b88:	a040000c */ 	sb	$zero,0xc($v0)
/*  f188b8c:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f188b90:	ac580010 */ 	sw	$t8,0x10($v0)
/*  f188b94:	ac940000 */ 	sw	$s4,0x0($a0)
.L0f188b98:
/*  f188b98:	54d4ffd9 */ 	bnel	$a2,$s4,.L0f188b00
/*  f188b9c:	00002825 */ 	or	$a1,$zero,$zero
/*  f188ba0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f188ba4:	02a01025 */ 	or	$v0,$s5,$zero
/*  f188ba8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f188bac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188bb0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188bb4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188bb8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188bbc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188bc0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f188bc4:	03e00008 */ 	jr	$ra
/*  f188bc8:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

u32 func0f188bcc(void)
{
	return 39;
}

GLOBAL_ASM(
glabel mpGetNumWeaponOptions
/*  f188bd4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f188bd8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188bdc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188be0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188be4:	3c108008 */ 	lui	$s0,%hi(mpweaponstable)
/*  f188be8:	3c128008 */ 	lui	$s2,0x8008
/*  f188bec:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f188bf0:	00008825 */ 	or	$s1,$zero,$zero
/*  f188bf4:	265273ee */ 	addiu	$s2,$s2,0x73ee
/*  f188bf8:	26107268 */ 	addiu	$s0,$s0,%lo(mpweaponstable)
/*  f188bfc:	96040004 */ 	lhu	$a0,0x4($s0)
.L0f188c00:
/*  f188c00:	308e007f */ 	andi	$t6,$a0,0x7f
/*  f188c04:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188c08:	01c02025 */ 	or	$a0,$t6,$zero
/*  f188c0c:	10400002 */ 	beqz	$v0,.L0f188c18
/*  f188c10:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f188c14:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f188c18:
/*  f188c18:	5612fff9 */ 	bnel	$s0,$s2,.L0f188c00
/*  f188c1c:	96040004 */ 	lhu	$a0,0x4($s0)
/*  f188c20:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188c24:	02201025 */ 	or	$v0,$s1,$zero
/*  f188c28:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188c2c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188c30:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188c34:	03e00008 */ 	jr	$ra
/*  f188c38:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel mpGetWeaponLabel
/*  f188c3c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f188c40:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188c44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188c48:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188c4c:	3c108008 */ 	lui	$s0,%hi(mpweaponstable)
/*  f188c50:	3c128008 */ 	lui	$s2,0x8008
/*  f188c54:	00808825 */ 	or	$s1,$a0,$zero
/*  f188c58:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f188c5c:	265273ee */ 	addiu	$s2,$s2,0x73ee
/*  f188c60:	26107268 */ 	addiu	$s0,$s0,%lo(mpweaponstable)
/*  f188c64:	96040004 */ 	lhu	$a0,0x4($s0)
.L0f188c68:
/*  f188c68:	308e007f */ 	andi	$t6,$a0,0x7f
/*  f188c6c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188c70:	01c02025 */ 	or	$a0,$t6,$zero
/*  f188c74:	5040001e */ 	beqzl	$v0,.L0f188cf0
/*  f188c78:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f188c7c:	5620001b */ 	bnezl	$s1,.L0f188cec
/*  f188c80:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f188c84:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f188c88:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f188c8c:	14800005 */ 	bnez	$a0,.L0f188ca4
/*  f188c90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188c94:	0fc5b9f1 */ 	jal	langGet
/*  f188c98:	2404543a */ 	addiu	$a0,$zero,0x543a
/*  f188c9c:	10000019 */ 	beqz	$zero,.L0f188d04
/*  f188ca0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f188ca4:
/*  f188ca4:	54810006 */ 	bnel	$a0,$at,.L0f188cc0
/*  f188ca8:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f188cac:	0fc5b9f1 */ 	jal	langGet
/*  f188cb0:	2404543b */ 	addiu	$a0,$zero,0x543b
/*  f188cb4:	10000013 */ 	beqz	$zero,.L0f188d04
/*  f188cb8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188cbc:	2401005c */ 	addiu	$at,$zero,0x5c
.L0f188cc0:
/*  f188cc0:	14810005 */ 	bne	$a0,$at,.L0f188cd8
/*  f188cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188cc8:	0fc5b9f1 */ 	jal	langGet
/*  f188ccc:	2404543c */ 	addiu	$a0,$zero,0x543c
/*  f188cd0:	1000000c */ 	beqz	$zero,.L0f188d04
/*  f188cd4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f188cd8:
/*  f188cd8:	0fc28857 */ 	jal	func0f0a215c
/*  f188cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188ce0:	10000008 */ 	beqz	$zero,.L0f188d04
/*  f188ce4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188ce8:	2631ffff */ 	addiu	$s1,$s1,-1
.L0f188cec:
/*  f188cec:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f188cf0:
/*  f188cf0:	5612ffdd */ 	bnel	$s0,$s2,.L0f188c68
/*  f188cf4:	96040004 */ 	lhu	$a0,0x4($s0)
/*  f188cf8:	3c027f1c */ 	lui	$v0,%hi(var7f1b8a58)
/*  f188cfc:	24428a58 */ 	addiu	$v0,$v0,%lo(var7f1b8a58)
/*  f188d00:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f188d04:
/*  f188d04:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188d08:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188d0c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188d10:	03e00008 */ 	jr	$ra
/*  f188d14:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel mpSetWeaponSlot
/*  f188d18:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f188d1c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188d20:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188d24:	00a08825 */ 	or	$s1,$a1,$zero
/*  f188d28:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f188d2c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188d30:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f188d34:	04a0000d */ 	bltz	$a1,.L0f188d6c
/*  f188d38:	00009025 */ 	or	$s2,$zero,$zero
/*  f188d3c:	3c108008 */ 	lui	$s0,%hi(mpweaponstable)
/*  f188d40:	26107268 */ 	addiu	$s0,$s0,%lo(mpweaponstable)
.L0f188d44:
/*  f188d44:	96040004 */ 	lhu	$a0,0x4($s0)
/*  f188d48:	308e007f */ 	andi	$t6,$a0,0x7f
/*  f188d4c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188d50:	01c02025 */ 	or	$a0,$t6,$zero
/*  f188d54:	14400002 */ 	bnez	$v0,.L0f188d60
/*  f188d58:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f188d5c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f188d60:
/*  f188d60:	0232082a */ 	slt	$at,$s1,$s2
/*  f188d64:	1020fff7 */ 	beqz	$at,.L0f188d44
/*  f188d68:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f188d6c:
/*  f188d6c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f188d70:	3c01800b */ 	lui	$at,0x800b
/*  f188d74:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188d78:	002f0821 */ 	addu	$at,$at,$t7
/*  f188d7c:	a031cba0 */ 	sb	$s1,-0x3460($at)
/*  f188d80:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188d84:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188d88:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188d8c:	03e00008 */ 	jr	$ra
/*  f188d90:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel mpGetWeaponSlot
/*  f188d94:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f188d98:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup)
/*  f188d9c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f188da0:	25cecb88 */ 	addiu	$t6,$t6,%lo(g_MpSetup)
/*  f188da4:	008e9821 */ 	addu	$s3,$a0,$t6
/*  f188da8:	926f0018 */ 	lbu	$t7,0x18($s3)
/*  f188dac:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f188db0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f188db4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f188db8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f188dbc:	00009025 */ 	or	$s2,$zero,$zero
/*  f188dc0:	19e00010 */ 	blez	$t7,.L0f188e04
/*  f188dc4:	00008825 */ 	or	$s1,$zero,$zero
/*  f188dc8:	3c108008 */ 	lui	$s0,%hi(mpweaponstable)
/*  f188dcc:	26107268 */ 	addiu	$s0,$s0,%lo(mpweaponstable)
/*  f188dd0:	96040004 */ 	lhu	$a0,0x4($s0)
.L0f188dd4:
/*  f188dd4:	3098007f */ 	andi	$t8,$a0,0x7f
/*  f188dd8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188ddc:	03002025 */ 	or	$a0,$t8,$zero
/*  f188de0:	50400003 */ 	beqzl	$v0,.L0f188df0
/*  f188de4:	92790018 */ 	lbu	$t9,0x18($s3)
/*  f188de8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f188dec:	92790018 */ 	lbu	$t9,0x18($s3)
.L0f188df0:
/*  f188df0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f188df4:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f188df8:	0239082a */ 	slt	$at,$s1,$t9
/*  f188dfc:	5420fff5 */ 	bnezl	$at,.L0f188dd4
/*  f188e00:	96040004 */ 	lhu	$a0,0x4($s0)
.L0f188e04:
/*  f188e04:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188e08:	02401025 */ 	or	$v0,$s2,$zero
/*  f188e0c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f188e10:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f188e14:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f188e18:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f188e1c:	03e00008 */ 	jr	$ra
/*  f188e20:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f188e24
/*  f188e24:	24860001 */ 	addiu	$a2,$a0,0x1
/*  f188e28:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f188e2c:	00c01025 */ 	or	$v0,$a2,$zero
/*  f188e30:	18c0001e */ 	blez	$a2,.L0f188eac
/*  f188e34:	00002825 */ 	or	$a1,$zero,$zero
/*  f188e38:	3c088008 */ 	lui	$t0,%hi(mpweaponstable)
/*  f188e3c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f188e40:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f188e44:	25087268 */ 	addiu	$t0,$t0,%lo(mpweaponstable)
/*  f188e48:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f188e4c:	2407005c */ 	addiu	$a3,$zero,0x5c
/*  f188e50:	00857021 */ 	addu	$t6,$a0,$a1
.L0f188e54:
/*  f188e54:	91c30018 */ 	lbu	$v1,0x18($t6)
/*  f188e58:	00690019 */ 	multu	$v1,$t1
/*  f188e5c:	00007812 */ 	mflo	$t7
/*  f188e60:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f188e64:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f188e68:	10f90002 */ 	beq	$a3,$t9,.L0f188e74
/*  f188e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188e70:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f188e74:
/*  f188e74:	1840000a */ 	blez	$v0,.L0f188ea0
/*  f188e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188e7c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f188e80:	28a10006 */ 	slti	$at,$a1,0x6
/*  f188e84:	14200006 */ 	bnez	$at,.L0f188ea0
/*  f188e88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188e8c:	14c20003 */ 	bne	$a2,$v0,.L0f188e9c
/*  f188e90:	00002825 */ 	or	$a1,$zero,$zero
/*  f188e94:	00001825 */ 	or	$v1,$zero,$zero
/*  f188e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f188e9c:
/*  f188e9c:	00403025 */ 	or	$a2,$v0,$zero
.L0f188ea0:
/*  f188ea0:	5c40ffec */ 	bgtzl	$v0,.L0f188e54
/*  f188ea4:	00857021 */ 	addu	$t6,$a0,$a1
/*  f188ea8:	a3a30003 */ 	sb	$v1,0x3($sp)
.L0f188eac:
/*  f188eac:	93a30003 */ 	lbu	$v1,0x3($sp)
/*  f188eb0:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f188eb4:	3c088008 */ 	lui	$t0,%hi(mpweaponstable)
/*  f188eb8:	00690019 */ 	multu	$v1,$t1
/*  f188ebc:	25087268 */ 	addiu	$t0,$t0,%lo(mpweaponstable)
/*  f188ec0:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*  f188ec4:	00005012 */ 	mflo	$t2
/*  f188ec8:	010a1021 */ 	addu	$v0,$t0,$t2
/*  f188ecc:	03e00008 */ 	jr	$ra
/*  f188ed0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f188ed4
/*  f188ed4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f188ed8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188edc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188ee0:	2881000c */ 	slti	$at,$a0,0xc
/*  f188ee4:	00809825 */ 	or	$s3,$a0,$zero
/*  f188ee8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f188eec:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f188ef0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188ef4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188ef8:	14200003 */ 	bnez	$at,.L0f188f08
/*  f188efc:	00009025 */ 	or	$s2,$zero,$zero
/*  f188f00:	2492fff4 */ 	addiu	$s2,$a0,-12
/*  f188f04:	2413000c */ 	addiu	$s3,$zero,0xc
.L0f188f08:
/*  f188f08:	1a60001b */ 	blez	$s3,.L0f188f78
/*  f188f0c:	00008825 */ 	or	$s1,$zero,$zero
/*  f188f10:	3c108008 */ 	lui	$s0,%hi(mpweaponsetstable)
/*  f188f14:	261073f0 */ 	addiu	$s0,$s0,%lo(mpweaponsetstable)
/*  f188f18:	2414005c */ 	addiu	$s4,$zero,0x5c
.L0f188f1c:
/*  f188f1c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188f20:	92040008 */ 	lbu	$a0,0x8($s0)
/*  f188f24:	5040000e */ 	beqzl	$v0,.L0f188f60
/*  f188f28:	920e000c */ 	lbu	$t6,0xc($s0)
/*  f188f2c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188f30:	92040009 */ 	lbu	$a0,0x9($s0)
/*  f188f34:	5040000a */ 	beqzl	$v0,.L0f188f60
/*  f188f38:	920e000c */ 	lbu	$t6,0xc($s0)
/*  f188f3c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188f40:	9204000a */ 	lbu	$a0,0xa($s0)
/*  f188f44:	50400006 */ 	beqzl	$v0,.L0f188f60
/*  f188f48:	920e000c */ 	lbu	$t6,0xc($s0)
/*  f188f4c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188f50:	9204000b */ 	lbu	$a0,0xb($s0)
/*  f188f54:	54400005 */ 	bnezl	$v0,.L0f188f6c
/*  f188f58:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f188f5c:	920e000c */ 	lbu	$t6,0xc($s0)
.L0f188f60:
/*  f188f60:	528e0003 */ 	beql	$s4,$t6,.L0f188f70
/*  f188f64:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f188f68:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f188f6c:
/*  f188f6c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f188f70:
/*  f188f70:	1633ffea */ 	bne	$s1,$s3,.L0f188f1c
/*  f188f74:	26100012 */ 	addiu	$s0,$s0,0x12
.L0f188f78:
/*  f188f78:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f188f7c:	02401025 */ 	or	$v0,$s2,$zero
/*  f188f80:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188f84:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188f88:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188f8c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188f90:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188f94:	03e00008 */ 	jr	$ra
/*  f188f98:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f188f9c
/*  f188f9c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f188fa0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188fa4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f188fa8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188fac:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188fb0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188fb4:	3c108008 */ 	lui	$s0,%hi(mpweaponsetstable)
/*  f188fb8:	00809025 */ 	or	$s2,$a0,$zero
/*  f188fbc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f188fc0:	261073f0 */ 	addiu	$s0,$s0,%lo(mpweaponsetstable)
/*  f188fc4:	00008825 */ 	or	$s1,$zero,$zero
/*  f188fc8:	2413005c */ 	addiu	$s3,$zero,0x5c
/*  f188fcc:	2414000c */ 	addiu	$s4,$zero,0xc
.L0f188fd0:
/*  f188fd0:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188fd4:	92040008 */ 	lbu	$a0,0x8($s0)
/*  f188fd8:	5040000e */ 	beqzl	$v0,.L0f189014
/*  f188fdc:	920e000c */ 	lbu	$t6,0xc($s0)
/*  f188fe0:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188fe4:	92040009 */ 	lbu	$a0,0x9($s0)
/*  f188fe8:	5040000a */ 	beqzl	$v0,.L0f189014
/*  f188fec:	920e000c */ 	lbu	$t6,0xc($s0)
/*  f188ff0:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f188ff4:	9204000a */ 	lbu	$a0,0xa($s0)
/*  f188ff8:	50400006 */ 	beqzl	$v0,.L0f189014
/*  f188ffc:	920e000c */ 	lbu	$t6,0xc($s0)
/*  f189000:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189004:	9204000b */ 	lbu	$a0,0xb($s0)
/*  f189008:	14400004 */ 	bnez	$v0,.L0f18901c
/*  f18900c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189010:	920e000c */ 	lbu	$t6,0xc($s0)
.L0f189014:
/*  f189014:	526e0005 */ 	beql	$s3,$t6,.L0f18902c
/*  f189018:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18901c:
/*  f18901c:	52400006 */ 	beqzl	$s2,.L0f189038
/*  f189020:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f189024:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f189028:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18902c:
/*  f18902c:	1634ffe8 */ 	bne	$s1,$s4,.L0f188fd0
/*  f189030:	26100012 */ 	addiu	$s0,$s0,0x12
/*  f189034:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f189038:
/*  f189038:	02321021 */ 	addu	$v0,$s1,$s2
/*  f18903c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f189040:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f189044:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f189048:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18904c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f189050:	03e00008 */ 	jr	$ra
/*  f189054:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f189058
/*  f189058:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18905c:	10800003 */ 	beqz	$a0,.L0f18906c
/*  f189060:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189064:	10000002 */ 	beqz	$zero,.L0f189070
/*  f189068:	2404000f */ 	addiu	$a0,$zero,0xf
.L0f18906c:
/*  f18906c:	2404000c */ 	addiu	$a0,$zero,0xc
.L0f189070:
/*  f189070:	0fc623b5 */ 	jal	func0f188ed4
/*  f189074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189078:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18907c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f189080:	03e00008 */ 	jr	$ra
/*  f189084:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f189088
/*  f189088:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18908c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189090:	0fc623b5 */ 	jal	func0f188ed4
/*  f189094:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f189098:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18909c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1890a0:	03e00008 */ 	jr	$ra
/*  f1890a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1890a8
/*  f1890a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1890ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1890b0:	0fc623e7 */ 	jal	func0f188f9c
/*  f1890b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1890b8:	04400004 */ 	bltz	$v0,.L0f1890cc
/*  f1890bc:	00402825 */ 	or	$a1,$v0,$zero
/*  f1890c0:	2841000e */ 	slti	$at,$v0,0xe
/*  f1890c4:	54200006 */ 	bnezl	$at,.L0f1890e0
/*  f1890c8:	2401000d */ 	addiu	$at,$zero,0xd
.L0f1890cc:
/*  f1890cc:	0fc5b9f1 */ 	jal	langGet
/*  f1890d0:	24045429 */ 	addiu	$a0,$zero,0x5429
/*  f1890d4:	10000016 */ 	beqz	$zero,.L0f189130
/*  f1890d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1890dc:	2401000d */ 	addiu	$at,$zero,0xd
.L0f1890e0:
/*  f1890e0:	54410006 */ 	bnel	$v0,$at,.L0f1890fc
/*  f1890e4:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1890e8:	0fc5b9f1 */ 	jal	langGet
/*  f1890ec:	2404542a */ 	addiu	$a0,$zero,0x542a
/*  f1890f0:	1000000f */ 	beqz	$zero,.L0f189130
/*  f1890f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1890f8:	2401000c */ 	addiu	$at,$zero,0xc
.L0f1890fc:
/*  f1890fc:	14410005 */ 	bne	$v0,$at,.L0f189114
/*  f189100:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f189104:	0fc5b9f1 */ 	jal	langGet
/*  f189108:	2404542b */ 	addiu	$a0,$zero,0x542b
/*  f18910c:	10000008 */ 	beqz	$zero,.L0f189130
/*  f189110:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189114:
/*  f189114:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f189118:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18911c:	3c048008 */ 	lui	$a0,%hi(mpweaponsetstable)
/*  f189120:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f189124:	0fc5b9f1 */ 	jal	langGet
/*  f189128:	948473f0 */ 	lhu	$a0,%lo(mpweaponsetstable)($a0)
/*  f18912c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189130:
/*  f189130:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f189134:	03e00008 */ 	jr	$ra
/*  f189138:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18913c
/*  f18913c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f189140:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f189144:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f189148:	3c0f8008 */ 	lui	$t7,%hi(mpweaponsetstable)
/*  f18914c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f189150:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f189154:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f189158:	25ef73f0 */ 	addiu	$t7,$t7,%lo(mpweaponsetstable)
/*  f18915c:	3c158008 */ 	lui	$s5,%hi(mpweaponstable)
/*  f189160:	3c17800b */ 	lui	$s7,0x800b
/*  f189164:	00007100 */ 	sll	$t6,$zero,0x4
/*  f189168:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18916c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f189170:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f189174:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f189178:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18917c:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f189180:	01cff021 */ 	addu	$s8,$t6,$t7
/*  f189184:	26f7cb8e */ 	addiu	$s7,$s7,-13426
/*  f189188:	26b57268 */ 	addiu	$s5,$s5,%lo(mpweaponstable)
/*  f18918c:	2414005b */ 	addiu	$s4,$zero,0x5b
/*  f189190:	2416000a */ 	addiu	$s6,$zero,0xa
/*  f189194:	afa00044 */ 	sw	$zero,0x44($sp)
.L0f189198:
/*  f189198:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18919c:	93c40008 */ 	lbu	$a0,0x8($s8)
/*  f1891a0:	50400010 */ 	beqzl	$v0,.L0f1891e4
/*  f1891a4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891a8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1891ac:	93c40009 */ 	lbu	$a0,0x9($s8)
/*  f1891b0:	5040000c */ 	beqzl	$v0,.L0f1891e4
/*  f1891b4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891b8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1891bc:	93c4000a */ 	lbu	$a0,0xa($s8)
/*  f1891c0:	50400008 */ 	beqzl	$v0,.L0f1891e4
/*  f1891c4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891c8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f1891cc:	93c4000b */ 	lbu	$a0,0xb($s8)
/*  f1891d0:	50400004 */ 	beqzl	$v0,.L0f1891e4
/*  f1891d4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891d8:	10000008 */ 	beqz	$zero,.L0f1891fc
/*  f1891dc:	27c20002 */ 	addiu	$v0,$s8,0x2
/*  f1891e0:	93d8000c */ 	lbu	$t8,0xc($s8)
.L0f1891e4:
/*  f1891e4:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f1891e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1891ec:	13010003 */ 	beq	$t8,$at,.L0f1891fc
/*  f1891f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1891f4:	10000001 */ 	beqz	$zero,.L0f1891fc
/*  f1891f8:	27c2000c */ 	addiu	$v0,$s8,0xc
.L0f1891fc:
/*  f1891fc:	1040001d */ 	beqz	$v0,.L0f189274
/*  f189200:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f189204:	3c11800b */ 	lui	$s1,%hi(g_MpSetup)
/*  f189208:	2631cb88 */ 	addiu	$s1,$s1,%lo(g_MpSetup)
/*  f18920c:	00409025 */ 	or	$s2,$v0,$zero
.L0f189210:
/*  f189210:	92500000 */ 	lbu	$s0,0x0($s2)
/*  f189214:	56140007 */ 	bnel	$s0,$s4,.L0f189234
/*  f189218:	92390018 */ 	lbu	$t9,0x18($s1)
/*  f18921c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189220:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f189224:	54400003 */ 	bnezl	$v0,.L0f189234
/*  f189228:	92390018 */ 	lbu	$t9,0x18($s1)
/*  f18922c:	00008025 */ 	or	$s0,$zero,$zero
/*  f189230:	92390018 */ 	lbu	$t9,0x18($s1)
.L0f189234:
/*  f189234:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f189238:	03360019 */ 	multu	$t9,$s6
/*  f18923c:	00004012 */ 	mflo	$t0
/*  f189240:	02a84821 */ 	addu	$t1,$s5,$t0
/*  f189244:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f189248:	120a0002 */ 	beq	$s0,$t2,.L0f189254
/*  f18924c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189250:	00009825 */ 	or	$s3,$zero,$zero
.L0f189254:
/*  f189254:	1637ffee */ 	bne	$s1,$s7,.L0f189210
/*  f189258:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18925c:	12600005 */ 	beqz	$s3,.L0f189274
/*  f189260:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f189264:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f189268:	3c018008 */ 	lui	$at,0x8008
/*  f18926c:	afab0040 */ 	sw	$t3,0x40($sp)
/*  f189270:	ac2274c8 */ 	sw	$v0,0x74c8($at)
.L0f189274:
/*  f189274:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f189278:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f18927c:	27de0012 */ 	addiu	$s8,$s8,0x12
/*  f189280:	15800004 */ 	bnez	$t4,.L0f189294
/*  f189284:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f189288:	2401000c */ 	addiu	$at,$zero,0xc
/*  f18928c:	1441ffc2 */ 	bne	$v0,$at,.L0f189198
/*  f189290:	afa20044 */ 	sw	$v0,0x44($sp)
.L0f189294:
/*  f189294:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f189298:	240e000e */ 	addiu	$t6,$zero,0xe
/*  f18929c:	3c018008 */ 	lui	$at,0x8008
/*  f1892a0:	55a00003 */ 	bnezl	$t5,.L0f1892b0
/*  f1892a4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1892a8:	ac2e74c8 */ 	sw	$t6,0x74c8($at)
/*  f1892ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1892b0:
/*  f1892b0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1892b4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1892b8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1892bc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1892c0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1892c4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1892c8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1892cc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f1892d0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f1892d4:	03e00008 */ 	jr	$ra
/*  f1892d8:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f1892dc
/*  f1892dc:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f1892e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1892e4:	3c108008 */ 	lui	$s0,%hi(var800874c8)
/*  f1892e8:	261074c8 */ 	addiu	$s0,$s0,%lo(var800874c8)
/*  f1892ec:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1892f0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1892f4:	04400077 */ 	bltz	$v0,.L0f1894d4
/*  f1892f8:	2841000c */ 	slti	$at,$v0,0xc
/*  f1892fc:	10200075 */ 	beqz	$at,.L0f1894d4
/*  f189300:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f189304:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f189308:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18930c:	3c048008 */ 	lui	$a0,0x8008
/*  f189310:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f189314:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189318:	908473f8 */ 	lbu	$a0,0x73f8($a0)
/*  f18931c:	50400029 */ 	beqzl	$v0,.L0f1893c4
/*  f189320:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f189324:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f189328:	3c048008 */ 	lui	$a0,0x8008
/*  f18932c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f189330:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f189334:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f189338:	00982021 */ 	addu	$a0,$a0,$t8
/*  f18933c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189340:	908473f9 */ 	lbu	$a0,0x73f9($a0)
/*  f189344:	5040001f */ 	beqzl	$v0,.L0f1893c4
/*  f189348:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18934c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f189350:	3c048008 */ 	lui	$a0,0x8008
/*  f189354:	001960c0 */ 	sll	$t4,$t9,0x3
/*  f189358:	01996021 */ 	addu	$t4,$t4,$t9
/*  f18935c:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f189360:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f189364:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189368:	908473fa */ 	lbu	$a0,0x73fa($a0)
/*  f18936c:	50400015 */ 	beqzl	$v0,.L0f1893c4
/*  f189370:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f189374:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f189378:	3c048008 */ 	lui	$a0,0x8008
/*  f18937c:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f189380:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f189384:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f189388:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f18938c:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189390:	908473fb */ 	lbu	$a0,0x73fb($a0)
/*  f189394:	5040000b */ 	beqzl	$v0,.L0f1893c4
/*  f189398:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18939c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1893a0:	3c0c8008 */ 	lui	$t4,%hi(mpweaponsetstable)
/*  f1893a4:	258c73f0 */ 	addiu	$t4,$t4,%lo(mpweaponsetstable)
/*  f1893a8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f1893ac:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1893b0:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f1893b4:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f1893b8:	1000000f */ 	beqz	$zero,.L0f1893f8
/*  f1893bc:	032c1021 */ 	addu	$v0,$t9,$t4
/*  f1893c0:	8e0d0000 */ 	lw	$t5,0x0($s0)
.L0f1893c4:
/*  f1893c4:	3c0f8008 */ 	lui	$t7,%hi(mpweaponsetstable)
/*  f1893c8:	25ef73f0 */ 	addiu	$t7,$t7,%lo(mpweaponsetstable)
/*  f1893cc:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1893d0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f1893d4:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1893d8:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f1893dc:	9078000c */ 	lbu	$t8,0xc($v1)
/*  f1893e0:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f1893e4:	53010004 */ 	beql	$t8,$at,.L0f1893f8
/*  f1893e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1893ec:	10000002 */ 	beqz	$zero,.L0f1893f8
/*  f1893f0:	2462000c */ 	addiu	$v0,$v1,0xc
/*  f1893f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1893f8:
/*  f1893f8:	1040006b */ 	beqz	$v0,.L0f1895a8
/*  f1893fc:	00405825 */ 	or	$t3,$v0,$zero
/*  f189400:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f189404:	3c088008 */ 	lui	$t0,%hi(mpweaponstable)
/*  f189408:	25087268 */ 	addiu	$t0,$t0,%lo(mpweaponstable)
/*  f18940c:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f189410:	2410005b */ 	addiu	$s0,$zero,0x5b
/*  f189414:	2409000a */ 	addiu	$t1,$zero,0xa
.L0f189418:
/*  f189418:	91660000 */ 	lbu	$a2,0x0($t3)
/*  f18941c:	00002825 */ 	or	$a1,$zero,$zero
/*  f189420:	00003825 */ 	or	$a3,$zero,$zero
/*  f189424:	14d00014 */ 	bne	$a2,$s0,.L0f189478
/*  f189428:	00001825 */ 	or	$v1,$zero,$zero
/*  f18942c:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f189430:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f189434:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f189438:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f18943c:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f189440:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f189444:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f189448:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f18944c:	3c088008 */ 	lui	$t0,%hi(mpweaponstable)
/*  f189450:	25087268 */ 	addiu	$t0,$t0,%lo(mpweaponstable)
/*  f189454:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f189458:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f18945c:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f189460:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f189464:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f189468:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f18946c:	14400002 */ 	bnez	$v0,.L0f189478
/*  f189470:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f189474:	00003025 */ 	or	$a2,$zero,$zero
.L0f189478:
/*  f189478:	2c610027 */ 	sltiu	$at,$v1,0x27
/*  f18947c:	14200003 */ 	bnez	$at,.L0f18948c
/*  f189480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189484:	10000009 */ 	beqz	$zero,.L0f1894ac
/*  f189488:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18948c:
/*  f18948c:	00690019 */ 	multu	$v1,$t1
/*  f189490:	0000c812 */ 	mflo	$t9
/*  f189494:	01196021 */ 	addu	$t4,$t0,$t9
/*  f189498:	918d0000 */ 	lbu	$t5,0x0($t4)
/*  f18949c:	14cd0003 */ 	bne	$a2,$t5,.L0f1894ac
/*  f1894a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1894a4:	00603825 */ 	or	$a3,$v1,$zero
/*  f1894a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1894ac:
/*  f1894ac:	10a0fff2 */ 	beqz	$a1,.L0f189478
/*  f1894b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1894b4:	3c0e800b */ 	lui	$t6,0x800b
/*  f1894b8:	25cecb8e */ 	addiu	$t6,$t6,-13426
/*  f1894bc:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f1894c0:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f1894c4:	154effd4 */ 	bne	$t2,$t6,.L0f189418
/*  f1894c8:	a1470017 */ 	sb	$a3,0x17($t2)
/*  f1894cc:	10000037 */ 	beqz	$zero,.L0f1895ac
/*  f1894d0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1894d4:
/*  f1894d4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f1894d8:	54410017 */ 	bnel	$v0,$at,.L0f189538
/*  f1894dc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1894e0:	0fc622f5 */ 	jal	mpGetNumWeaponOptions
/*  f1894e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1894e8:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f1894ec:	00008025 */ 	or	$s0,$zero,$zero
.L0f1894f0:
/*  f1894f0:	0c004b70 */ 	jal	random
/*  f1894f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1894f8:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f1894fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f189500:	004f001b */ 	divu	$zero,$v0,$t7
/*  f189504:	00002810 */ 	mfhi	$a1
/*  f189508:	15e00002 */ 	bnez	$t7,.L0f189514
/*  f18950c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189510:	0007000d */ 	break	0x7
.L0f189514:
/*  f189514:	0fc62346 */ 	jal	mpSetWeaponSlot
/*  f189518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18951c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f189520:	24010006 */ 	addiu	$at,$zero,0x6
/*  f189524:	1601fff2 */ 	bne	$s0,$at,.L0f1894f0
/*  f189528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18952c:	1000001f */ 	beqz	$zero,.L0f1895ac
/*  f189530:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f189534:	2401000c */ 	addiu	$at,$zero,0xc
.L0f189538:
/*  f189538:	5441001c */ 	bnel	$v0,$at,.L0f1895ac
/*  f18953c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f189540:	0fc622f5 */ 	jal	mpGetNumWeaponOptions
/*  f189544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189548:	2458fffe */ 	addiu	$t8,$v0,-2
/*  f18954c:	afb80030 */ 	sw	$t8,0x30($sp)
/*  f189550:	00008025 */ 	or	$s0,$zero,$zero
.L0f189554:
/*  f189554:	0c004b70 */ 	jal	random
/*  f189558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18955c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f189560:	02002025 */ 	or	$a0,$s0,$zero
/*  f189564:	0059001b */ 	divu	$zero,$v0,$t9
/*  f189568:	00002810 */ 	mfhi	$a1
/*  f18956c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f189570:	17200002 */ 	bnez	$t9,.L0f18957c
/*  f189574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189578:	0007000d */ 	break	0x7
.L0f18957c:
/*  f18957c:	0fc62346 */ 	jal	mpSetWeaponSlot
/*  f189580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189584:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f189588:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18958c:	1601fff1 */ 	bne	$s0,$at,.L0f189554
/*  f189590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189594:	0fc622f5 */ 	jal	mpGetNumWeaponOptions
/*  f189598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18959c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1895a0:	0fc62346 */ 	jal	mpSetWeaponSlot
/*  f1895a4:	2445ffff */ 	addiu	$a1,$v0,-1
.L0f1895a8:
/*  f1895a8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1895ac:
/*  f1895ac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1895b0:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f1895b4:	03e00008 */ 	jr	$ra
/*  f1895b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1895bc
/*  f1895bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1895c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1895c4:	0fc623e7 */ 	jal	func0f188f9c
/*  f1895c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1895cc:	3c018008 */ 	lui	$at,0x8008
/*  f1895d0:	0fc624b7 */ 	jal	func0f1892dc
/*  f1895d4:	ac2274c8 */ 	sw	$v0,0x74c8($at)
/*  f1895d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1895dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1895e0:	03e00008 */ 	jr	$ra
/*  f1895e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1895e8
/*  f1895e8:	3c0e8008 */ 	lui	$t6,%hi(var800874c8)
/*  f1895ec:	8dce74c8 */ 	lw	$t6,%lo(var800874c8)($t6)
/*  f1895f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1895f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1895f8:	29c1000c */ 	slti	$at,$t6,0xc
/*  f1895fc:	50200004 */ 	beqzl	$at,.L0f189610
/*  f189600:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189604:	0fc624b7 */ 	jal	func0f1892dc
/*  f189608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18960c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189610:
/*  f189610:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f189614:	03e00008 */ 	jr	$ra
/*  f189618:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18961c
/*  f18961c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f189620:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189624:	3c048008 */ 	lui	$a0,%hi(var800874c8)
/*  f189628:	0fc623b5 */ 	jal	func0f188ed4
/*  f18962c:	8c8474c8 */ 	lw	$a0,%lo(var800874c8)($a0)
/*  f189630:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189634:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f189638:	03e00008 */ 	jr	$ra
/*  f18963c:	00000000 */ 	sll	$zero,$zero,0x0
);

bool mpIsPaused(void)
{
	if (PLAYERCOUNT() == 1 && g_Vars.mplayerisrunning && g_MenuStack[g_Vars.currentplayerstats->mpindex].unk00) {
		return true;
	}

	if (!g_MpSetup.paused) {
		return false;
	}

	return true;
}

void mpSetPaused(u8 pause)
{
	g_MpSetup.paused = pause;
}

GLOBAL_ASM(
glabel func0f18973c
/*  f18973c:	3c02800b */ 	lui	$v0,0x800b
/*  f189740:	9042cba6 */ 	lbu	$v0,-0x345a($v0)
/*  f189744:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f189748:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18974c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f189750:	14410077 */ 	bne	$v0,$at,.L0f189930
/*  f189754:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f189758:	3c013f80 */ 	lui	$at,0x3f80
/*  f18975c:	44812000 */ 	mtc1	$at,$f4
/*  f189760:	3c018006 */ 	lui	$at,0x8006
/*  f189764:	c4261630 */ 	lwc1	$f6,0x1630($at)
/*  f189768:	3c0141a0 */ 	lui	$at,0x41a0
/*  f18976c:	44815000 */ 	mtc1	$at,$f10
/*  f189770:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f189774:	3c01437f */ 	lui	$at,0x437f
/*  f189778:	44819000 */ 	mtc1	$at,$f18
/*  f18977c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f189780:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f189784:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189788:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f18978c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f189790:	440f3000 */ 	mfc1	$t7,$f6
/*  f189794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189798:	01e1001a */ 	div	$zero,$t7,$at
/*  f18979c:	0000c010 */ 	mfhi	$t8
/*  f1897a0:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f1897a4:	0fc54d8a */ 	jal	func0f153628
/*  f1897a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1897ac:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f1897b0:	0fc5b9f1 */ 	jal	langGet
/*  f1897b4:	24045428 */ 	addiu	$a0,$zero,0x5428
/*  f1897b8:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f1897bc:	0c004c4c */ 	jal	strcpy
/*  f1897c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1897c4:	0c002f40 */ 	jal	func0000bd00
/*  f1897c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1897cc:	0c002f22 */ 	jal	func0000bc88
/*  f1897d0:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f1897d4:	87a80042 */ 	lh	$t0,0x42($sp)
/*  f1897d8:	3c0a800a */ 	lui	$t2,0x800a
/*  f1897dc:	8d4aa248 */ 	lw	$t2,-0x5db8($t2)
/*  f1897e0:	04410003 */ 	bgez	$v0,.L0f1897f0
/*  f1897e4:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f1897e8:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1897ec:	0001c843 */ 	sra	$t9,$at,0x1
.L0f1897f0:
/*  f1897f0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1897f4:	afa90094 */ 	sw	$t1,0x94($sp)
/*  f1897f8:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f1897fc:	3c0d800a */ 	lui	$t5,%hi(g_MenuStack)
/*  f189800:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f189804:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f189808:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f18980c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f189810:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f189814:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f189818:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f18981c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f189820:	8dade4f8 */ 	lw	$t5,%lo(g_MenuStack)($t5)
/*  f189824:	11a00006 */ 	beqz	$t5,.L0f189840
/*  f189828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18982c:	0c002f44 */ 	jal	func0000bd10
/*  f189830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189834:	244e000a */ 	addiu	$t6,$v0,0xa
/*  f189838:	1000000c */ 	beqz	$zero,.L0f18986c
/*  f18983c:	afae0090 */ 	sw	$t6,0x90($sp)
.L0f189840:
/*  f189840:	0c002f44 */ 	jal	func0000bd10
/*  f189844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189848:	0c002f26 */ 	jal	func0000bc98
/*  f18984c:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189850:	87b80042 */ 	lh	$t8,0x42($sp)
/*  f189854:	04410003 */ 	bgez	$v0,.L0f189864
/*  f189858:	00027843 */ 	sra	$t7,$v0,0x1
/*  f18985c:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189860:	00017843 */ 	sra	$t7,$at,0x1
.L0f189864:
/*  f189864:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f189868:	afb90090 */ 	sw	$t9,0x90($sp)
.L0f18986c:
/*  f18986c:	3c088008 */ 	lui	$t0,%hi(var8007fb14)
/*  f189870:	8d08fb14 */ 	lw	$t0,%lo(var8007fb14)($t0)
/*  f189874:	3c078008 */ 	lui	$a3,%hi(var8007fb18)
/*  f189878:	8ce7fb18 */ 	lw	$a3,%lo(var8007fb18)($a3)
/*  f18987c:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f189880:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f189884:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f189888:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18988c:	0fc55cbe */ 	jal	func0f1572f8
/*  f189890:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f189894:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f189898:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f18989c:	05410003 */ 	bgez	$t2,.L0f1898ac
/*  f1898a0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f1898a4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f1898a8:	00015843 */ 	sra	$t3,$at,0x1
.L0f1898ac:
/*  f1898ac:	012b6023 */ 	subu	$t4,$t1,$t3
/*  f1898b0:	0c002f02 */ 	jal	func0000bc08
/*  f1898b4:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f1898b8:	0c002f02 */ 	jal	func0000bc08
/*  f1898bc:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f1898c0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f1898c4:	3c0d8008 */ 	lui	$t5,%hi(var8007fb18)
/*  f1898c8:	3c0e8008 */ 	lui	$t6,%hi(var8007fb14)
/*  f1898cc:	3c0100ff */ 	lui	$at,0xff
/*  f1898d0:	8dcefb14 */ 	lw	$t6,%lo(var8007fb14)($t6)
/*  f1898d4:	8dadfb18 */ 	lw	$t5,%lo(var8007fb18)($t5)
/*  f1898d8:	87aa0040 */ 	lh	$t2,0x40($sp)
/*  f1898dc:	342100ff */ 	ori	$at,$at,0xff
/*  f1898e0:	000fc600 */ 	sll	$t8,$t7,0x18
/*  f1898e4:	0301c825 */ 	or	$t9,$t8,$at
/*  f1898e8:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f1898ec:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f1898f0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1898f4:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1898f8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1898fc:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f189900:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f189904:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f189908:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18990c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f189910:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f189914:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f189918:	0fc55b92 */ 	jal	func0f156e48
/*  f18991c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f189920:	0fc54de0 */ 	jal	func0f153780
/*  f189924:	00402025 */ 	or	$a0,$v0,$zero
/*  f189928:	100000e0 */ 	beqz	$zero,.L0f189cac
/*  f18992c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f189930:
/*  f189930:	3c098006 */ 	lui	$t1,%hi(var8005d9d0)
/*  f189934:	8d29d9d0 */ 	lw	$t1,%lo(var8005d9d0)($t1)
/*  f189938:	552000dd */ 	bnezl	$t1,.L0f189cb0
/*  f18993c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f189940:	144000da */ 	bnez	$v0,.L0f189cac
/*  f189944:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f189948:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f18994c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f189950:	8c4b00d8 */ 	lw	$t3,0xd8($v0)
/*  f189954:	516000d6 */ 	beqzl	$t3,.L0f189cb0
/*  f189958:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18995c:	8c4c032c */ 	lw	$t4,0x32c($v0)
/*  f189960:	518000d3 */ 	beqzl	$t4,.L0f189cb0
/*  f189964:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f189968:	8c4d0330 */ 	lw	$t5,0x330($v0)
/*  f18996c:	51a000d0 */ 	beqzl	$t5,.L0f189cb0
/*  f189970:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f189974:	8c6e0298 */ 	lw	$t6,0x298($v1)
/*  f189978:	05c20011 */ 	bltzl	$t6,.L0f1899c0
/*  f18997c:	8c6b029c */ 	lw	$t3,0x29c($v1)
/*  f189980:	8c6f02a0 */ 	lw	$t7,0x2a0($v1)
/*  f189984:	8df800d8 */ 	lw	$t8,0xd8($t7)
/*  f189988:	53000006 */ 	beqzl	$t8,.L0f1899a4
/*  f18998c:	8c4a1c10 */ 	lw	$t2,0x1c10($v0)
/*  f189990:	8c7902a4 */ 	lw	$t9,0x2a4($v1)
/*  f189994:	8f2800d8 */ 	lw	$t0,0xd8($t9)
/*  f189998:	550000c5 */ 	bnezl	$t0,.L0f189cb0
/*  f18999c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899a0:	8c4a1c10 */ 	lw	$t2,0x1c10($v0)
.L0f1899a4:
/*  f1899a4:	3c098007 */ 	lui	$t1,%hi(var80070764)
/*  f1899a8:	514000c1 */ 	beqzl	$t2,.L0f189cb0
/*  f1899ac:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899b0:	8d290764 */ 	lw	$t1,%lo(var80070764)($t1)
/*  f1899b4:	552000be */ 	bnezl	$t1,.L0f189cb0
/*  f1899b8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899bc:	8c6b029c */ 	lw	$t3,0x29c($v1)
.L0f1899c0:
/*  f1899c0:	3c0e8008 */ 	lui	$t6,%hi(var80084038)
/*  f1899c4:	05600008 */ 	bltz	$t3,.L0f1899e8
/*  f1899c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1899cc:	8c6c02a8 */ 	lw	$t4,0x2a8($v1)
/*  f1899d0:	3c0d8007 */ 	lui	$t5,%hi(var80070764)
/*  f1899d4:	558200b6 */ 	bnel	$t4,$v0,.L0f189cb0
/*  f1899d8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899dc:	8dad0764 */ 	lw	$t5,%lo(var80070764)($t5)
/*  f1899e0:	55a000b3 */ 	bnezl	$t5,.L0f189cb0
/*  f1899e4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f1899e8:
/*  f1899e8:	8dce4038 */ 	lw	$t6,%lo(var80084038)($t6)
/*  f1899ec:	55c000b0 */ 	bnezl	$t6,.L0f189cb0
/*  f1899f0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899f4:	0fc54d8a */ 	jal	func0f153628
/*  f1899f8:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1899fc:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189a00:	0fc5b9f1 */ 	jal	langGet
/*  f189a04:	24045427 */ 	addiu	$a0,$zero,0x5427
/*  f189a08:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f189a0c:	0c004c4c */ 	jal	strcpy
/*  f189a10:	00402825 */ 	or	$a1,$v0,$zero
/*  f189a14:	0c002f40 */ 	jal	func0000bd00
/*  f189a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189a1c:	0c002f22 */ 	jal	func0000bc88
/*  f189a20:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189a24:	87b80042 */ 	lh	$t8,0x42($sp)
/*  f189a28:	04410003 */ 	bgez	$v0,.L0f189a38
/*  f189a2c:	00027843 */ 	sra	$t7,$v0,0x1
/*  f189a30:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189a34:	00017843 */ 	sra	$t7,$at,0x1
.L0f189a38:
/*  f189a38:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f189a3c:	0c002f44 */ 	jal	func0000bd10
/*  f189a40:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f189a44:	0c002f26 */ 	jal	func0000bc98
/*  f189a48:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189a4c:	87aa0042 */ 	lh	$t2,0x42($sp)
/*  f189a50:	3c0b8008 */ 	lui	$t3,%hi(var8007fb0c)
/*  f189a54:	8d6bfb0c */ 	lw	$t3,%lo(var8007fb0c)($t3)
/*  f189a58:	04410003 */ 	bgez	$v0,.L0f189a68
/*  f189a5c:	00024043 */ 	sra	$t0,$v0,0x1
/*  f189a60:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189a64:	00014043 */ 	sra	$t0,$at,0x1
.L0f189a68:
/*  f189a68:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f189a6c:	010a4821 */ 	addu	$t1,$t0,$t2
/*  f189a70:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f189a74:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f189a78:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f189a7c:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f189a80:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f189a84:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f189a88:	0fc55cbe */ 	jal	func0f1572f8
/*  f189a8c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f189a90:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f189a94:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f189a98:	05a10003 */ 	bgez	$t5,.L0f189aa8
/*  f189a9c:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f189aa0:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f189aa4:	00017043 */ 	sra	$t6,$at,0x1
.L0f189aa8:
/*  f189aa8:	018e7823 */ 	subu	$t7,$t4,$t6
/*  f189aac:	0c002f02 */ 	jal	func0000bc08
/*  f189ab0:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f189ab4:	0c002f02 */ 	jal	func0000bc08
/*  f189ab8:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f189abc:	3c188008 */ 	lui	$t8,%hi(var8007fb10)
/*  f189ac0:	3c198008 */ 	lui	$t9,%hi(var8007fb0c)
/*  f189ac4:	8f39fb0c */ 	lw	$t9,%lo(var8007fb0c)($t9)
/*  f189ac8:	8f18fb10 */ 	lw	$t8,%lo(var8007fb10)($t8)
/*  f189acc:	87a90040 */ 	lh	$t1,0x40($sp)
/*  f189ad0:	3c08ff00 */ 	lui	$t0,0xff00
/*  f189ad4:	350800ff */ 	ori	$t0,$t0,0xff
/*  f189ad8:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f189adc:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f189ae0:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189ae4:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f189ae8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f189aec:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f189af0:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f189af4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f189af8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f189afc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f189b00:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f189b04:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f189b08:	0fc55b92 */ 	jal	func0f156e48
/*  f189b0c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f189b10:	3c0b800a */ 	lui	$t3,0x800a
/*  f189b14:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f189b18:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189b1c:	8d6d1c0c */ 	lw	$t5,0x1c0c($t3)
/*  f189b20:	19a00051 */ 	blez	$t5,.L0f189c68
/*  f189b24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189b28:	0c002f44 */ 	jal	func0000bd10
/*  f189b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189b30:	0c002f26 */ 	jal	func0000bc98
/*  f189b34:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189b38:	87ae0042 */ 	lh	$t6,0x42($sp)
/*  f189b3c:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f189b40:	04410003 */ 	bgez	$v0,.L0f189b50
/*  f189b44:	00026043 */ 	sra	$t4,$v0,0x1
/*  f189b48:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189b4c:	00016043 */ 	sra	$t4,$at,0x1
.L0f189b50:
/*  f189b50:	018e7821 */ 	addu	$t7,$t4,$t6
/*  f189b54:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f189b58:	27280002 */ 	addiu	$t0,$t9,0x2
/*  f189b5c:	0c002f40 */ 	jal	func0000bd00
/*  f189b60:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f189b64:	0c002f22 */ 	jal	func0000bc88
/*  f189b68:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189b6c:	87a90042 */ 	lh	$t1,0x42($sp)
/*  f189b70:	3c0d800a */ 	lui	$t5,0x800a
/*  f189b74:	8dada244 */ 	lw	$t5,-0x5dbc($t5)
/*  f189b78:	04410003 */ 	bgez	$v0,.L0f189b88
/*  f189b7c:	00025043 */ 	sra	$t2,$v0,0x1
/*  f189b80:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189b84:	00015043 */ 	sra	$t2,$at,0x1
.L0f189b88:
/*  f189b88:	01495821 */ 	addu	$t3,$t2,$t1
/*  f189b8c:	afab0048 */ 	sw	$t3,0x48($sp)
/*  f189b90:	8da61c0c */ 	lw	$a2,0x1c0c($t5)
/*  f189b94:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f189b98:	3c057f1c */ 	lui	$a1,%hi(var7f1b8aa4)
/*  f189b9c:	24c6003b */ 	addiu	$a2,$a2,0x3b
/*  f189ba0:	00c1001a */ 	div	$zero,$a2,$at
/*  f189ba4:	00003012 */ 	mflo	$a2
/*  f189ba8:	24a58aa4 */ 	addiu	$a1,$a1,%lo(var7f1b8aa4)
/*  f189bac:	0c004dad */ 	jal	sprintf
/*  f189bb0:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f189bb4:	3c0e8008 */ 	lui	$t6,%hi(var8007fb0c)
/*  f189bb8:	8dcefb0c */ 	lw	$t6,%lo(var8007fb0c)($t6)
/*  f189bbc:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f189bc0:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f189bc4:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f189bc8:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f189bcc:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f189bd0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f189bd4:	0fc55cbe */ 	jal	func0f1572f8
/*  f189bd8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f189bdc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f189be0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f189be4:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f189be8:	07010003 */ 	bgez	$t8,.L0f189bf8
/*  f189bec:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f189bf0:	27010001 */ 	addiu	$at,$t8,0x1
/*  f189bf4:	0001c843 */ 	sra	$t9,$at,0x1
.L0f189bf8:
/*  f189bf8:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f189bfc:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f189c00:	0c002f02 */ 	jal	func0000bc08
/*  f189c04:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f189c08:	0c002f02 */ 	jal	func0000bc08
/*  f189c0c:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f189c10:	3c098008 */ 	lui	$t1,%hi(var8007fb10)
/*  f189c14:	3c0b8008 */ 	lui	$t3,%hi(var8007fb0c)
/*  f189c18:	8d6bfb0c */ 	lw	$t3,%lo(var8007fb0c)($t3)
/*  f189c1c:	8d29fb10 */ 	lw	$t1,%lo(var8007fb10)($t1)
/*  f189c20:	87ae0040 */ 	lh	$t6,0x40($sp)
/*  f189c24:	3c0dff00 */ 	lui	$t5,0xff00
/*  f189c28:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f189c2c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f189c30:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f189c34:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f189c38:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f189c3c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f189c40:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f189c44:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f189c48:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f189c4c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f189c50:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f189c54:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f189c58:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f189c5c:	0fc55b92 */ 	jal	func0f156e48
/*  f189c60:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f189c64:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f189c68:
/*  f189c68:	0fc54de0 */ 	jal	func0f153780
/*  f189c6c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f189c70:	3c0f800a */ 	lui	$t7,0x800a
/*  f189c74:	8defa248 */ 	lw	$t7,-0x5db8($t7)
/*  f189c78:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189c7c:	3c01800a */ 	lui	$at,0x800a
/*  f189c80:	8df90070 */ 	lw	$t9,0x70($t7)
/*  f189c84:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f189c88:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f189c8c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f189c90:	00084080 */ 	sll	$t0,$t0,0x2
/*  f189c94:	01194021 */ 	addu	$t0,$t0,$t9
/*  f189c98:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f189c9c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f189ca0:	00084100 */ 	sll	$t0,$t0,0x4
/*  f189ca4:	00280821 */ 	addu	$at,$at,$t0
/*  f189ca8:	a038e83c */ 	sb	$t8,-0x17c4($at)
.L0f189cac:
/*  f189cac:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f189cb0:
/*  f189cb0:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f189cb4:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f189cb8:	03e00008 */ 	jr	$ra
/*  f189cbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f189cc0
/*  f189cc0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f189cc4:	28810002 */ 	slti	$at,$a0,0x2
/*  f189cc8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189ccc:	14200039 */ 	bnez	$at,.L0f189db4
/*  f189cd0:	00004025 */ 	or	$t0,$zero,$zero
/*  f189cd4:	00a6082a */ 	slt	$at,$a1,$a2
/*  f189cd8:	54200011 */ 	bnezl	$at,.L0f189d20
/*  f189cdc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f189ce0:	54c50012 */ 	bnel	$a2,$a1,.L0f189d2c
/*  f189ce4:	00a01825 */ 	or	$v1,$a1,$zero
/*  f189ce8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189cec:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f189cf0:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f189cf4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189cf8:	0c004b70 */ 	jal	random
/*  f189cfc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f189d00:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f189d04:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189d08:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f189d0c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f189d10:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189d14:	11c00004 */ 	beqz	$t6,.L0f189d28
/*  f189d18:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189d1c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f189d20:
/*  f189d20:	10000002 */ 	beqz	$zero,.L0f189d2c
/*  f189d24:	00c01825 */ 	or	$v1,$a2,$zero
.L0f189d28:
/*  f189d28:	00a01825 */ 	or	$v1,$a1,$zero
.L0f189d2c:
/*  f189d2c:	28810003 */ 	slti	$at,$a0,0x3
/*  f189d30:	14200020 */ 	bnez	$at,.L0f189db4
/*  f189d34:	0067082a */ 	slt	$at,$v1,$a3
/*  f189d38:	5420000f */ 	bnezl	$at,.L0f189d78
/*  f189d3c:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f189d40:	54e3000f */ 	bnel	$a3,$v1,.L0f189d80
/*  f189d44:	28810004 */ 	slti	$at,$a0,0x4
/*  f189d48:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f189d4c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189d50:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189d54:	0c004b70 */ 	jal	random
/*  f189d58:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189d5c:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f189d60:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f189d64:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189d68:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189d6c:	11e00003 */ 	beqz	$t7,.L0f189d7c
/*  f189d70:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189d74:	24080002 */ 	addiu	$t0,$zero,0x2
.L0f189d78:
/*  f189d78:	00e01825 */ 	or	$v1,$a3,$zero
.L0f189d7c:
/*  f189d7c:	28810004 */ 	slti	$at,$a0,0x4
.L0f189d80:
/*  f189d80:	1420000c */ 	bnez	$at,.L0f189db4
/*  f189d84:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f189d88:	0062082a */ 	slt	$at,$v1,$v0
/*  f189d8c:	54200009 */ 	bnezl	$at,.L0f189db4
/*  f189d90:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f189d94:	54430008 */ 	bnel	$v0,$v1,.L0f189db8
/*  f189d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189d9c:	0c004b70 */ 	jal	random
/*  f189da0:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189da4:	30580001 */ 	andi	$t8,$v0,0x1
/*  f189da8:	13000002 */ 	beqz	$t8,.L0f189db4
/*  f189dac:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189db0:	24080003 */ 	addiu	$t0,$zero,0x3
.L0f189db4:
/*  f189db4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189db8:
/*  f189db8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f189dbc:	01001025 */ 	or	$v0,$t0,$zero
/*  f189dc0:	03e00008 */ 	jr	$ra
/*  f189dc4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f189dc8
/*  f189dc8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f189dcc:	28810002 */ 	slti	$at,$a0,0x2
/*  f189dd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189dd4:	14200039 */ 	bnez	$at,.L0f189ebc
/*  f189dd8:	00004025 */ 	or	$t0,$zero,$zero
/*  f189ddc:	00c5082a */ 	slt	$at,$a2,$a1
/*  f189de0:	54200011 */ 	bnezl	$at,.L0f189e28
/*  f189de4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f189de8:	54c50012 */ 	bnel	$a2,$a1,.L0f189e34
/*  f189dec:	00a01825 */ 	or	$v1,$a1,$zero
/*  f189df0:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189df4:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f189df8:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f189dfc:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189e00:	0c004b70 */ 	jal	random
/*  f189e04:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f189e08:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f189e0c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189e10:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f189e14:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f189e18:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189e1c:	11c00004 */ 	beqz	$t6,.L0f189e30
/*  f189e20:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189e24:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f189e28:
/*  f189e28:	10000002 */ 	beqz	$zero,.L0f189e34
/*  f189e2c:	00c01825 */ 	or	$v1,$a2,$zero
.L0f189e30:
/*  f189e30:	00a01825 */ 	or	$v1,$a1,$zero
.L0f189e34:
/*  f189e34:	28810003 */ 	slti	$at,$a0,0x3
/*  f189e38:	14200020 */ 	bnez	$at,.L0f189ebc
/*  f189e3c:	00e3082a */ 	slt	$at,$a3,$v1
/*  f189e40:	5420000f */ 	bnezl	$at,.L0f189e80
/*  f189e44:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f189e48:	54e3000f */ 	bnel	$a3,$v1,.L0f189e88
/*  f189e4c:	28810004 */ 	slti	$at,$a0,0x4
/*  f189e50:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f189e54:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189e58:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189e5c:	0c004b70 */ 	jal	random
/*  f189e60:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189e64:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f189e68:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f189e6c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189e70:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189e74:	11e00003 */ 	beqz	$t7,.L0f189e84
/*  f189e78:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189e7c:	24080002 */ 	addiu	$t0,$zero,0x2
.L0f189e80:
/*  f189e80:	00e01825 */ 	or	$v1,$a3,$zero
.L0f189e84:
/*  f189e84:	28810004 */ 	slti	$at,$a0,0x4
.L0f189e88:
/*  f189e88:	1420000c */ 	bnez	$at,.L0f189ebc
/*  f189e8c:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f189e90:	0043082a */ 	slt	$at,$v0,$v1
/*  f189e94:	54200009 */ 	bnezl	$at,.L0f189ebc
/*  f189e98:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f189e9c:	54430008 */ 	bnel	$v0,$v1,.L0f189ec0
/*  f189ea0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189ea4:	0c004b70 */ 	jal	random
/*  f189ea8:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189eac:	30580001 */ 	andi	$t8,$v0,0x1
/*  f189eb0:	13000002 */ 	beqz	$t8,.L0f189ebc
/*  f189eb4:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189eb8:	24080003 */ 	addiu	$t0,$zero,0x3
.L0f189ebc:
/*  f189ebc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189ec0:
/*  f189ec0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f189ec4:	01001025 */ 	or	$v0,$t0,$zero
/*  f189ec8:	03e00008 */ 	jr	$ra
/*  f189ecc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f189ed0
/*  f189ed0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f189ed4:	44856000 */ 	mtc1	$a1,$f12
/*  f189ed8:	44867000 */ 	mtc1	$a2,$f14
/*  f189edc:	28810002 */ 	slti	$at,$a0,0x2
/*  f189ee0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189ee4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189ee8:	1420004c */ 	bnez	$at,.L0f18a01c
/*  f189eec:	00002825 */ 	or	$a1,$zero,$zero
/*  f189ef0:	460e603c */ 	c.lt.s	$f12,$f14
/*  f189ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189ef8:	45030011 */ 	bc1tl	.L0f189f40
/*  f189efc:	4600710d */ 	trunc.w.s	$f4,$f14
/*  f189f00:	460c7032 */ 	c.eq.s	$f14,$f12
/*  f189f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189f08:	45020012 */ 	bc1fl	.L0f189f54
/*  f189f0c:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f189f10:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189f14:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f189f18:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f189f1c:	0c004b70 */ 	jal	random
/*  f189f20:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f189f24:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f189f28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189f2c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f189f30:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f189f34:	11c00006 */ 	beqz	$t6,.L0f189f50
/*  f189f38:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*  f189f3c:	4600710d */ 	trunc.w.s	$f4,$f14
.L0f189f40:
/*  f189f40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f189f44:	44032000 */ 	mfc1	$v1,$f4
/*  f189f48:	10000005 */ 	beqz	$zero,.L0f189f60
/*  f189f4c:	28810003 */ 	slti	$at,$a0,0x3
.L0f189f50:
/*  f189f50:	4600618d */ 	trunc.w.s	$f6,$f12
.L0f189f54:
/*  f189f54:	44033000 */ 	mfc1	$v1,$f6
/*  f189f58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189f5c:	28810003 */ 	slti	$at,$a0,0x3
.L0f189f60:
/*  f189f60:	5420002f */ 	bnezl	$at,.L0f18a020
/*  f189f64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189f68:	44834000 */ 	mtc1	$v1,$f8
/*  f189f6c:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f189f70:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f189f74:	460a003c */ 	c.lt.s	$f0,$f10
/*  f189f78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189f7c:	4503000f */ 	bc1tl	.L0f189fbc
/*  f189f80:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f189f84:	46005032 */ 	c.eq.s	$f10,$f0
/*  f189f88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189f8c:	45020010 */ 	bc1fl	.L0f189fd0
/*  f189f90:	28810004 */ 	slti	$at,$a0,0x4
/*  f189f94:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f189f98:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189f9c:	0c004b70 */ 	jal	random
/*  f189fa0:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f189fa4:	30590001 */ 	andi	$t9,$v0,0x1
/*  f189fa8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f189fac:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189fb0:	13200006 */ 	beqz	$t9,.L0f189fcc
/*  f189fb4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f189fb8:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
.L0f189fbc:
/*  f189fbc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f189fc0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f189fc4:	44039000 */ 	mfc1	$v1,$f18
/*  f189fc8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f189fcc:
/*  f189fcc:	28810004 */ 	slti	$at,$a0,0x4
.L0f189fd0:
/*  f189fd0:	54200013 */ 	bnezl	$at,.L0f18a020
/*  f189fd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189fd8:	44832000 */ 	mtc1	$v1,$f4
/*  f189fdc:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f189fe0:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f189fe4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f189fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189fec:	4503000b */ 	bc1tl	.L0f18a01c
/*  f189ff0:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f189ff4:	46001032 */ 	c.eq.s	$f2,$f0
/*  f189ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f189ffc:	45020008 */ 	bc1fl	.L0f18a020
/*  f18a000:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a004:	0c004b70 */ 	jal	random
/*  f18a008:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f18a00c:	30490001 */ 	andi	$t1,$v0,0x1
/*  f18a010:	11200002 */ 	beqz	$t1,.L0f18a01c
/*  f18a014:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a018:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f18a01c:
/*  f18a01c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18a020:
/*  f18a020:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f18a024:	00a01025 */ 	or	$v0,$a1,$zero
/*  f18a028:	03e00008 */ 	jr	$ra
/*  f18a02c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18a030
/*  f18a030:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f18a034:	44856000 */ 	mtc1	$a1,$f12
/*  f18a038:	44867000 */ 	mtc1	$a2,$f14
/*  f18a03c:	28810002 */ 	slti	$at,$a0,0x2
/*  f18a040:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18a044:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f18a048:	1420004c */ 	bnez	$at,.L0f18a17c
/*  f18a04c:	00002825 */ 	or	$a1,$zero,$zero
/*  f18a050:	460c703c */ 	c.lt.s	$f14,$f12
/*  f18a054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a058:	45030011 */ 	bc1tl	.L0f18a0a0
/*  f18a05c:	4600710d */ 	trunc.w.s	$f4,$f14
/*  f18a060:	460c7032 */ 	c.eq.s	$f14,$f12
/*  f18a064:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a068:	45020012 */ 	bc1fl	.L0f18a0b4
/*  f18a06c:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f18a070:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f18a074:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18a078:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f18a07c:	0c004b70 */ 	jal	random
/*  f18a080:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f18a084:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f18a088:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f18a08c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a090:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f18a094:	11c00006 */ 	beqz	$t6,.L0f18a0b0
/*  f18a098:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*  f18a09c:	4600710d */ 	trunc.w.s	$f4,$f14
.L0f18a0a0:
/*  f18a0a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18a0a4:	44032000 */ 	mfc1	$v1,$f4
/*  f18a0a8:	10000005 */ 	beqz	$zero,.L0f18a0c0
/*  f18a0ac:	28810003 */ 	slti	$at,$a0,0x3
.L0f18a0b0:
/*  f18a0b0:	4600618d */ 	trunc.w.s	$f6,$f12
.L0f18a0b4:
/*  f18a0b4:	44033000 */ 	mfc1	$v1,$f6
/*  f18a0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a0bc:	28810003 */ 	slti	$at,$a0,0x3
.L0f18a0c0:
/*  f18a0c0:	5420002f */ 	bnezl	$at,.L0f18a180
/*  f18a0c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a0c8:	44834000 */ 	mtc1	$v1,$f8
/*  f18a0cc:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f18a0d0:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f18a0d4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f18a0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a0dc:	4503000f */ 	bc1tl	.L0f18a11c
/*  f18a0e0:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f18a0e4:	46005032 */ 	c.eq.s	$f10,$f0
/*  f18a0e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a0ec:	45020010 */ 	bc1fl	.L0f18a130
/*  f18a0f0:	28810004 */ 	slti	$at,$a0,0x4
/*  f18a0f4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f18a0f8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f18a0fc:	0c004b70 */ 	jal	random
/*  f18a100:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f18a104:	30590001 */ 	andi	$t9,$v0,0x1
/*  f18a108:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f18a10c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f18a110:	13200006 */ 	beqz	$t9,.L0f18a12c
/*  f18a114:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a118:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
.L0f18a11c:
/*  f18a11c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f18a120:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f18a124:	44039000 */ 	mfc1	$v1,$f18
/*  f18a128:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18a12c:
/*  f18a12c:	28810004 */ 	slti	$at,$a0,0x4
.L0f18a130:
/*  f18a130:	54200013 */ 	bnezl	$at,.L0f18a180
/*  f18a134:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a138:	44832000 */ 	mtc1	$v1,$f4
/*  f18a13c:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f18a140:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f18a144:	4600103c */ 	c.lt.s	$f2,$f0
/*  f18a148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a14c:	4503000b */ 	bc1tl	.L0f18a17c
/*  f18a150:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18a154:	46001032 */ 	c.eq.s	$f2,$f0
/*  f18a158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a15c:	45020008 */ 	bc1fl	.L0f18a180
/*  f18a160:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a164:	0c004b70 */ 	jal	random
/*  f18a168:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f18a16c:	30490001 */ 	andi	$t1,$v0,0x1
/*  f18a170:	11200002 */ 	beqz	$t1,.L0f18a17c
/*  f18a174:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a178:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f18a17c:
/*  f18a17c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18a180:
/*  f18a180:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f18a184:	00a01025 */ 	or	$v0,$a1,$zero
/*  f18a188:	03e00008 */ 	jr	$ra
/*  f18a18c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18a190
/*  f18a190:	3c0f7f1c */ 	lui	$t7,%hi(var7f1b8aa8)
/*  f18a194:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f18a198:	25ef8aa8 */ 	addiu	$t7,$t7,%lo(var7f1b8aa8)
/*  f18a19c:	25e80024 */ 	addiu	$t0,$t7,0x24
/*  f18a1a0:	27ae0038 */ 	addiu	$t6,$sp,0x38
.L0f18a1a4:
/*  f18a1a4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f18a1a8:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f18a1ac:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f18a1b0:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f18a1b4:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f18a1b8:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f18a1bc:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f18a1c0:	15e8fff8 */ 	bne	$t7,$t0,.L0f18a1a4
/*  f18a1c4:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f18a1c8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f18a1cc:	3c0a8008 */ 	lui	$t2,%hi(var800874f0)
/*  f18a1d0:	254a74f0 */ 	addiu	$t2,$t2,%lo(var800874f0)
/*  f18a1d4:	254d0024 */ 	addiu	$t5,$t2,0x24
/*  f18a1d8:	27a90010 */ 	addiu	$t1,$sp,0x10
/*  f18a1dc:	adc10000 */ 	sw	$at,0x0($t6)
.L0f18a1e0:
/*  f18a1e0:	8d410000 */ 	lw	$at,0x0($t2)
/*  f18a1e4:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f18a1e8:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f18a1ec:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f18a1f0:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*  f18a1f4:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f18a1f8:	8d41fffc */ 	lw	$at,-0x4($t2)
/*  f18a1fc:	154dfff8 */ 	bne	$t2,$t5,.L0f18a1e0
/*  f18a200:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f18a204:	8d410000 */ 	lw	$at,0x0($t2)
/*  f18a208:	27a20038 */ 	addiu	$v0,$sp,0x38
/*  f18a20c:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a210:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f18a214:	ad210000 */ 	sw	$at,0x0($t1)
/*  f18a218:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f18a21c:
/*  f18a21c:	8c990054 */ 	lw	$t9,0x54($a0)
/*  f18a220:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f18a224:	03030019 */ 	multu	$t8,$v1
/*  f18a228:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a22c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18a230:	00004012 */ 	mflo	$t0
/*  f18a234:	0328082b */ 	sltu	$at,$t9,$t0
/*  f18a238:	14200003 */ 	bnez	$at,.L0f18a248
/*  f18a23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a240:	10000003 */ 	beqz	$zero,.L0f18a250
/*  f18a244:	afae0010 */ 	sw	$t6,0x10($sp)
.L0f18a248:
/*  f18a248:	10000005 */ 	beqz	$zero,.L0f18a260
/*  f18a24c:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a250:
/*  f18a250:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a254:	5420fff1 */ 	bnezl	$at,.L0f18a21c
/*  f18a258:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f18a25c:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a260:
/*  f18a260:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a264:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f18a268:	8c4b0000 */ 	lw	$t3,0x0($v0)
.L0f18a26c:
/*  f18a26c:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*  f18a270:	8faa0014 */ 	lw	$t2,0x14($sp)
/*  f18a274:	01630019 */ 	multu	$t3,$v1
/*  f18a278:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a27c:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f18a280:	00006812 */ 	mflo	$t5
/*  f18a284:	018d082b */ 	sltu	$at,$t4,$t5
/*  f18a288:	14200003 */ 	bnez	$at,.L0f18a298
/*  f18a28c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a290:	10000003 */ 	beqz	$zero,.L0f18a2a0
/*  f18a294:	afa90014 */ 	sw	$t1,0x14($sp)
.L0f18a298:
/*  f18a298:	10000005 */ 	beqz	$zero,.L0f18a2b0
/*  f18a29c:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a2a0:
/*  f18a2a0:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a2a4:	5420fff1 */ 	bnezl	$at,.L0f18a26c
/*  f18a2a8:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f18a2ac:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a2b0:
/*  f18a2b0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a2b4:	8c590000 */ 	lw	$t9,0x0($v0)
.L0f18a2b8:
/*  f18a2b8:	8c980084 */ 	lw	$t8,0x84($a0)
/*  f18a2bc:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f18a2c0:	03230019 */ 	multu	$t9,$v1
/*  f18a2c4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a2c8:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18a2cc:	00004012 */ 	mflo	$t0
/*  f18a2d0:	0308082b */ 	sltu	$at,$t8,$t0
/*  f18a2d4:	14200003 */ 	bnez	$at,.L0f18a2e4
/*  f18a2d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a2dc:	10000003 */ 	beqz	$zero,.L0f18a2ec
/*  f18a2e0:	afae0018 */ 	sw	$t6,0x18($sp)
.L0f18a2e4:
/*  f18a2e4:	10000005 */ 	beqz	$zero,.L0f18a2fc
/*  f18a2e8:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a2ec:
/*  f18a2ec:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a2f0:	5420fff1 */ 	bnezl	$at,.L0f18a2b8
/*  f18a2f4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f18a2f8:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a2fc:
/*  f18a2fc:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a300:	8c4c0000 */ 	lw	$t4,0x0($v0)
.L0f18a304:
/*  f18a304:	8c8b0088 */ 	lw	$t3,0x88($a0)
/*  f18a308:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f18a30c:	01830019 */ 	multu	$t4,$v1
/*  f18a310:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a314:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f18a318:	00006812 */ 	mflo	$t5
/*  f18a31c:	016d082b */ 	sltu	$at,$t3,$t5
/*  f18a320:	14200003 */ 	bnez	$at,.L0f18a330
/*  f18a324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a328:	10000003 */ 	beqz	$zero,.L0f18a338
/*  f18a32c:	afa9001c */ 	sw	$t1,0x1c($sp)
.L0f18a330:
/*  f18a330:	10000005 */ 	beqz	$zero,.L0f18a348
/*  f18a334:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a338:
/*  f18a338:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a33c:	5420fff1 */ 	bnezl	$at,.L0f18a304
/*  f18a340:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f18a344:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a348:
/*  f18a348:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a34c:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f18a350:
/*  f18a350:	8c99008c */ 	lw	$t9,0x8c($a0)
/*  f18a354:	8faf0020 */ 	lw	$t7,0x20($sp)
/*  f18a358:	03030019 */ 	multu	$t8,$v1
/*  f18a35c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a360:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18a364:	00004012 */ 	mflo	$t0
/*  f18a368:	0328082b */ 	sltu	$at,$t9,$t0
/*  f18a36c:	14200003 */ 	bnez	$at,.L0f18a37c
/*  f18a370:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a374:	10000003 */ 	beqz	$zero,.L0f18a384
/*  f18a378:	afae0020 */ 	sw	$t6,0x20($sp)
.L0f18a37c:
/*  f18a37c:	10000005 */ 	beqz	$zero,.L0f18a394
/*  f18a380:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a384:
/*  f18a384:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a388:	5420fff1 */ 	bnezl	$at,.L0f18a350
/*  f18a38c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f18a390:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a394:
/*  f18a394:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f18a398:	24050e10 */ 	addiu	$a1,$zero,0xe10
/*  f18a39c:	8c4b0000 */ 	lw	$t3,0x0($v0)
.L0f18a3a0:
/*  f18a3a0:	8c8c0068 */ 	lw	$t4,0x68($a0)
/*  f18a3a4:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f18a3a8:	01650019 */ 	multu	$t3,$a1
/*  f18a3ac:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a3b0:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f18a3b4:	00006812 */ 	mflo	$t5
/*  f18a3b8:	018d082b */ 	sltu	$at,$t4,$t5
/*  f18a3bc:	14200003 */ 	bnez	$at,.L0f18a3cc
/*  f18a3c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a3c4:	10000003 */ 	beqz	$zero,.L0f18a3d4
/*  f18a3c8:	afa90024 */ 	sw	$t1,0x24($sp)
.L0f18a3cc:
/*  f18a3cc:	10000005 */ 	beqz	$zero,.L0f18a3e4
/*  f18a3d0:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a3d4:
/*  f18a3d4:	0046082b */ 	sltu	$at,$v0,$a2
/*  f18a3d8:	5420fff1 */ 	bnezl	$at,.L0f18a3a0
/*  f18a3dc:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f18a3e0:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a3e4:
/*  f18a3e4:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f18a3e8:	2405012c */ 	addiu	$a1,$zero,0x12c
/*  f18a3ec:	8c590000 */ 	lw	$t9,0x0($v0)
.L0f18a3f0:
/*  f18a3f0:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f18a3f4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f18a3f8:	03250019 */ 	multu	$t9,$a1
/*  f18a3fc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a400:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18a404:	00004012 */ 	mflo	$t0
/*  f18a408:	0308082b */ 	sltu	$at,$t8,$t0
/*  f18a40c:	14200003 */ 	bnez	$at,.L0f18a41c
/*  f18a410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a414:	10000003 */ 	beqz	$zero,.L0f18a424
/*  f18a418:	afae0028 */ 	sw	$t6,0x28($sp)
.L0f18a41c:
/*  f18a41c:	10000005 */ 	beqz	$zero,.L0f18a434
/*  f18a420:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a424:
/*  f18a424:	0046082b */ 	sltu	$at,$v0,$a2
/*  f18a428:	5420fff1 */ 	bnezl	$at,.L0f18a3f0
/*  f18a42c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f18a430:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a434:
/*  f18a434:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a438:	8c4c0000 */ 	lw	$t4,0x0($v0)
.L0f18a43c:
/*  f18a43c:	8c8b0074 */ 	lw	$t3,0x74($a0)
/*  f18a440:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f18a444:	01830019 */ 	multu	$t4,$v1
/*  f18a448:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a44c:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f18a450:	00006812 */ 	mflo	$t5
/*  f18a454:	016d082b */ 	sltu	$at,$t3,$t5
/*  f18a458:	14200003 */ 	bnez	$at,.L0f18a468
/*  f18a45c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a460:	10000003 */ 	beqz	$zero,.L0f18a470
/*  f18a464:	afa9002c */ 	sw	$t1,0x2c($sp)
.L0f18a468:
/*  f18a468:	10000005 */ 	beqz	$zero,.L0f18a480
/*  f18a46c:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a470:
/*  f18a470:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a474:	5420fff1 */ 	bnezl	$at,.L0f18a43c
/*  f18a478:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f18a47c:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a480:
/*  f18a480:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f18a484:	240505dc */ 	addiu	$a1,$zero,0x5dc
/*  f18a488:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f18a48c:
/*  f18a48c:	8c990080 */ 	lw	$t9,0x80($a0)
/*  f18a490:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f18a494:	03050019 */ 	multu	$t8,$a1
/*  f18a498:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a49c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18a4a0:	00004012 */ 	mflo	$t0
/*  f18a4a4:	0328082b */ 	sltu	$at,$t9,$t0
/*  f18a4a8:	14200003 */ 	bnez	$at,.L0f18a4b8
/*  f18a4ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a4b0:	10000003 */ 	beqz	$zero,.L0f18a4c0
/*  f18a4b4:	afae0030 */ 	sw	$t6,0x30($sp)
.L0f18a4b8:
/*  f18a4b8:	10000005 */ 	beqz	$zero,.L0f18a4d0
/*  f18a4bc:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a4c0:
/*  f18a4c0:	0046082b */ 	sltu	$at,$v0,$a2
/*  f18a4c4:	5420fff1 */ 	bnezl	$at,.L0f18a48c
/*  f18a4c8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f18a4cc:	27a20038 */ 	addiu	$v0,$sp,0x38
.L0f18a4d0:
/*  f18a4d0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18a4d4:	8c4b0000 */ 	lw	$t3,0x0($v0)
.L0f18a4d8:
/*  f18a4d8:	8c8c0090 */ 	lw	$t4,0x90($a0)
/*  f18a4dc:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f18a4e0:	01630019 */ 	multu	$t3,$v1
/*  f18a4e4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a4e8:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f18a4ec:	00006812 */ 	mflo	$t5
/*  f18a4f0:	018d082b */ 	sltu	$at,$t4,$t5
/*  f18a4f4:	14200003 */ 	bnez	$at,.L0f18a504
/*  f18a4f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a4fc:	10000003 */ 	beqz	$zero,.L0f18a50c
/*  f18a500:	afa90034 */ 	sw	$t1,0x34($sp)
.L0f18a504:
/*  f18a504:	10000005 */ 	beqz	$zero,.L0f18a51c
/*  f18a508:	00001025 */ 	or	$v0,$zero,$zero
.L0f18a50c:
/*  f18a50c:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18a510:	5420fff1 */ 	bnezl	$at,.L0f18a4d8
/*  f18a514:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f18a518:	00001025 */ 	or	$v0,$zero,$zero
.L0f18a51c:
/*  f18a51c:	27a30010 */ 	addiu	$v1,$sp,0x10
/*  f18a520:	27a50038 */ 	addiu	$a1,$sp,0x38
.L0f18a524:
/*  f18a524:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f18a528:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f18a52c:	1465fffd */ 	bne	$v1,$a1,.L0f18a524
/*  f18a530:	03021021 */ 	addu	$v0,$t8,$v0
/*  f18a534:	28410065 */ 	slti	$at,$v0,0x65
/*  f18a538:	14200002 */ 	bnez	$at,.L0f18a544
/*  f18a53c:	240f0014 */ 	addiu	$t7,$zero,0x14
/*  f18a540:	24020064 */ 	addiu	$v0,$zero,0x64
.L0f18a544:
/*  f18a544:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18a548:	0041001a */ 	div	$zero,$v0,$at
/*  f18a54c:	0000c812 */ 	mflo	$t9
/*  f18a550:	332800ff */ 	andi	$t0,$t9,0xff
/*  f18a554:	29010015 */ 	slti	$at,$t0,0x15
/*  f18a558:	14200002 */ 	bnez	$at,.L0f18a564
/*  f18a55c:	a0990095 */ 	sb	$t9,0x95($a0)
/*  f18a560:	a08f0095 */ 	sb	$t7,0x95($a0)
.L0f18a564:
/*  f18a564:	03e00008 */ 	jr	$ra
/*  f18a568:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f18a56c
/*  f18a56c:	27bdfd00 */ 	addiu	$sp,$sp,-768
/*  f18a570:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f18a574:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f18a578:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f18a57c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f18a580:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f18a584:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f18a588:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f18a58c:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f18a590:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f18a594:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f18a598:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f18a59c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f18a5a0:	11c00004 */ 	beqz	$t6,.L0f18a5b4
/*  f18a5a4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f18a5a8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18a5ac:	10000002 */ 	beqz	$zero,.L0f18a5b8
/*  f18a5b0:	afaf0064 */ 	sw	$t7,0x64($sp)
.L0f18a5b4:
/*  f18a5b4:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f18a5b8:
/*  f18a5b8:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f18a5bc:	13000003 */ 	beqz	$t8,.L0f18a5cc
/*  f18a5c0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18a5c4:	10000002 */ 	beqz	$zero,.L0f18a5d0
/*  f18a5c8:	afb90068 */ 	sw	$t9,0x68($sp)
.L0f18a5cc:
/*  f18a5cc:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f18a5d0:
/*  f18a5d0:	8c4d0064 */ 	lw	$t5,0x64($v0)
/*  f18a5d4:	11a00003 */ 	beqz	$t5,.L0f18a5e4
/*  f18a5d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18a5dc:	10000002 */ 	beqz	$zero,.L0f18a5e8
/*  f18a5e0:	afae006c */ 	sw	$t6,0x6c($sp)
.L0f18a5e4:
/*  f18a5e4:	afa0006c */ 	sw	$zero,0x6c($sp)
.L0f18a5e8:
/*  f18a5e8:	8c4f0070 */ 	lw	$t7,0x70($v0)
/*  f18a5ec:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f18a5f0:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f18a5f4:	51e00004 */ 	beqzl	$t7,.L0f18a608
/*  f18a5f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f18a5fc:	10000002 */ 	beqz	$zero,.L0f18a608
/*  f18a600:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f18a604:	00008825 */ 	or	$s1,$zero,$zero
.L0f18a608:
/*  f18a608:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f18a60c:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f18a610:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f18a614:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f18a618:	0fc3089f */ 	jal	getMissionTime
/*  f18a61c:	afb002fc */ 	sw	$s0,0x2fc($sp)
/*  f18a620:	0c00cf76 */ 	jal	func00033dd8
/*  f18a624:	afa202ec */ 	sw	$v0,0x2ec($sp)
/*  f18a628:	0fc62179 */ 	jal	func0f1885e4
/*  f18a62c:	27a401e8 */ 	addiu	$a0,$sp,0x1e8
/*  f18a630:	3c15800b */ 	lui	$s5,%hi(g_MpSetup)
/*  f18a634:	26b5cb88 */ 	addiu	$s5,$s5,%lo(g_MpSetup)
/*  f18a638:	8eb8000c */ 	lw	$t8,0xc($s5)
/*  f18a63c:	afa201e4 */ 	sw	$v0,0x1e4($sp)
/*  f18a640:	33190002 */ 	andi	$t9,$t8,0x2
/*  f18a644:	53200006 */ 	beqzl	$t9,.L0f18a660
/*  f18a648:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f18a64c:	0fc622a1 */ 	jal	func0f188a84
/*  f18a650:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f18a654:	10000002 */ 	beqz	$zero,.L0f18a660
/*  f18a658:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f18a65c:	afa001e0 */ 	sw	$zero,0x1e0($sp)
.L0f18a660:
/*  f18a660:	3c0d800a */ 	lui	$t5,0x800a
/*  f18a664:	8dada24c */ 	lw	$t5,-0x5db4($t5)
/*  f18a668:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18a66c:	1a000224 */ 	blez	$s0,.L0f18af00
/*  f18a670:	afad02f0 */ 	sw	$t5,0x2f0($sp)
/*  f18a674:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f18a678:	3c017f1c */ 	lui	$at,%hi(var7f1b8d98)
/*  f18a67c:	c4288d98 */ 	lwc1	$f8,%lo(var7f1b8d98)($at)
/*  f18a680:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f18a684:	448f2000 */ 	mtc1	$t7,$f4
/*  f18a688:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f18a68c:	3c1e800b */ 	lui	$s8,%hi(g_MpPlayers)
/*  f18a690:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f18a694:	27dec7b8 */ 	addiu	$s8,$s8,%lo(g_MpPlayers)
/*  f18a698:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f18a69c:	27b301fc */ 	addiu	$s3,$sp,0x1fc
/*  f18a6a0:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f18a6a4:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f18a6a8:	e7aa0048 */ 	swc1	$f10,0x48($sp)
.L0f18a6ac:
/*  f18a6ac:	0fc631e5 */ 	jal	func0f18c794
/*  f18a6b0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18a6b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f18a6b8:	00408025 */ 	or	$s0,$v0,$zero
/*  f18a6bc:	0fc6320a */ 	jal	func0f18c828
/*  f18a6c0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18a6c4:	00408825 */ 	or	$s1,$v0,$zero
/*  f18a6c8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18a6cc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18a6d0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f18a6d4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f18a6d8:	8c580284 */ 	lw	$t8,0x284($v0)
/*  f18a6dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a6e0:	af001974 */ 	sw	$zero,0x1974($t8)
/*  f18a6e4:	8c590284 */ 	lw	$t9,0x284($v0)
/*  f18a6e8:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a6ec:	af201978 */ 	sw	$zero,0x1978($t9)
/*  f18a6f0:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f18a6f4:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a6f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f18a6fc:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f18a700:	ae600008 */ 	sw	$zero,0x8($s3)
/*  f18a704:	ae60000c */ 	sw	$zero,0xc($s3)
/*  f18a708:	ae600010 */ 	sw	$zero,0x10($s3)
/*  f18a70c:	00113040 */ 	sll	$a2,$s1,0x1
/*  f18a710:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a714:	02402825 */ 	or	$a1,$s2,$zero
.L0f18a718:
/*  f18a718:	54c40007 */ 	bnel	$a2,$a0,.L0f18a738
/*  f18a71c:	8e780008 */ 	lw	$t8,0x8($s3)
/*  f18a720:	8e6d0010 */ 	lw	$t5,0x10($s3)
/*  f18a724:	84ae0024 */ 	lh	$t6,0x24($a1)
/*  f18a728:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f18a72c:	10000005 */ 	beqz	$zero,.L0f18a744
/*  f18a730:	ae6f0010 */ 	sw	$t7,0x10($s3)
/*  f18a734:	8e780008 */ 	lw	$t8,0x8($s3)
.L0f18a738:
/*  f18a738:	84b90024 */ 	lh	$t9,0x24($a1)
/*  f18a73c:	03196821 */ 	addu	$t5,$t8,$t9
/*  f18a740:	ae6d0008 */ 	sw	$t5,0x8($s3)
.L0f18a744:
/*  f18a744:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f18a748:	28810018 */ 	slti	$at,$a0,0x18
/*  f18a74c:	1420fff2 */ 	bnez	$at,.L0f18a718
/*  f18a750:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f18a754:	00001825 */ 	or	$v1,$zero,$zero
/*  f18a758:	00112040 */ 	sll	$a0,$s1,0x1
/*  f18a75c:	240500a0 */ 	addiu	$a1,$zero,0xa0
.L0f18a760:
/*  f18a760:	28610004 */ 	slti	$at,$v1,0x4
/*  f18a764:	10200006 */ 	beqz	$at,.L0f18a780
/*  f18a768:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18a76c:	00650019 */ 	multu	$v1,$a1
/*  f18a770:	00007012 */ 	mflo	$t6
/*  f18a774:	03ce1021 */ 	addu	$v0,$s8,$t6
/*  f18a778:	1000000a */ 	beqz	$zero,.L0f18a7a4
/*  f18a77c:	00447021 */ 	addu	$t6,$v0,$a0
.L0f18a780:
/*  f18a780:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f18a784:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18a788:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f18a78c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18a790:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18a794:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f18a798:	25f8fed0 */ 	addiu	$t8,$t7,-304
/*  f18a79c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f18a7a0:	00447021 */ 	addu	$t6,$v0,$a0
.L0f18a7a4:
/*  f18a7a4:	85cf0024 */ 	lh	$t7,0x24($t6)
/*  f18a7a8:	8e6d000c */ 	lw	$t5,0xc($s3)
/*  f18a7ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18a7b0:	2861000c */ 	slti	$at,$v1,0xc
/*  f18a7b4:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f18a7b8:	1420ffe9 */ 	bnez	$at,.L0f18a760
/*  f18a7bc:	ae78000c */ 	sw	$t8,0xc($s3)
/*  f18a7c0:	8e790008 */ 	lw	$t9,0x8($s3)
/*  f18a7c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f18a7c8:	44811000 */ 	mtc1	$at,$f2
/*  f18a7cc:	44998000 */ 	mtc1	$t9,$f16
/*  f18a7d0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f18a7d4:	44812000 */ 	mtc1	$at,$f4
/*  f18a7d8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f18a7dc:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f18a7e0:	03006825 */ 	or	$t5,$t8,$zero
/*  f18a7e4:	8e8f00b0 */ 	lw	$t7,0xb0($s4)
/*  f18a7e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f18a7ec:	8e9800a8 */ 	lw	$t8,0xa8($s4)
/*  f18a7f0:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f18a7f4:	448d9000 */ 	mtc1	$t5,$f18
/*  f18a7f8:	3c017f1c */ 	lui	$at,%hi(var7f1b8d9c)
/*  f18a7fc:	ae6f001c */ 	sw	$t7,0x1c($s3)
/*  f18a800:	ae780020 */ 	sw	$t8,0x20($s3)
/*  f18a804:	8e9900c0 */ 	lw	$t9,0xc0($s4)
/*  f18a808:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f18a80c:	8e8e00c4 */ 	lw	$t6,0xc4($s4)
/*  f18a810:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f18a814:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f18a818:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f18a81c:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f18a820:	460a0403 */ 	div.s	$f16,$f0,$f10
/*  f18a824:	c68a00ac */ 	lwc1	$f10,0xac($s4)
/*  f18a828:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f18a82c:	e6700014 */ 	swc1	$f16,0x14($s3)
/*  f18a830:	e6680018 */ 	swc1	$f8,0x18($s3)
/*  f18a834:	c4308d9c */ 	lwc1	$f16,%lo(var7f1b8d9c)($at)
/*  f18a838:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f18a83c:	c68800b4 */ 	lwc1	$f8,0xb4($s4)
/*  f18a840:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f18a844:	ae60002c */ 	sw	$zero,0x2c($s3)
/*  f18a848:	ae790030 */ 	sw	$t9,0x30($s3)
/*  f18a84c:	ae6e0034 */ 	sw	$t6,0x34($s3)
/*  f18a850:	e6680028 */ 	swc1	$f8,0x28($s3)
/*  f18a854:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f18a858:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a85c:	e6660024 */ 	swc1	$f6,0x24($s3)
/*  f18a860:	00409025 */ 	or	$s2,$v0,$zero
/*  f18a864:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a868:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f18a86c:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f18a870:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a874:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f18a878:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f18a87c:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a880:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f18a884:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f18a888:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a88c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f18a890:	00408825 */ 	or	$s1,$v0,$zero
/*  f18a894:	0fc2c14b */ 	jal	func0f0b052c
/*  f18a898:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f18a89c:	8e630000 */ 	lw	$v1,0x0($s3)
/*  f18a8a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f18a8a4:	44811000 */ 	mtc1	$at,$f2
/*  f18a8a8:	18600010 */ 	blez	$v1,.L0f18a8ec
/*  f18a8ac:	00516821 */ 	addu	$t5,$v0,$s1
/*  f18a8b0:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f18a8b4:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f18a8b8:	44839000 */ 	mtc1	$v1,$f18
/*  f18a8bc:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f18a8c0:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f18a8c4:	03197021 */ 	addu	$t6,$t8,$t9
/*  f18a8c8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f18a8cc:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f18a8d0:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f18a8d4:	44985000 */ 	mtc1	$t8,$f10
/*  f18a8d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a8dc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f18a8e0:	46048183 */ 	div.s	$f6,$f16,$f4
/*  f18a8e4:	10000004 */ 	beqz	$zero,.L0f18a8f8
/*  f18a8e8:	e6660038 */ 	swc1	$f6,0x38($s3)
.L0f18a8ec:
/*  f18a8ec:	44804000 */ 	mtc1	$zero,$f8
/*  f18a8f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a8f4:	e6680038 */ 	swc1	$f8,0x38($s3)
.L0f18a8f8:
/*  f18a8f8:	c66a0038 */ 	lwc1	$f10,0x38($s3)
/*  f18a8fc:	3c19800a */ 	lui	$t9,%hi(g_CheatsActiveBank0)
/*  f18a900:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank1)
/*  f18a904:	460a103c */ 	c.lt.s	$f2,$f10
/*  f18a908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a90c:	45020003 */ 	bc1fl	.L0f18a91c
/*  f18a910:	a2000094 */ 	sb	$zero,0x94($s0)
/*  f18a914:	e6620038 */ 	swc1	$f2,0x38($s3)
/*  f18a918:	a2000094 */ 	sb	$zero,0x94($s0)
.L0f18a91c:
/*  f18a91c:	8f3921d0 */ 	lw	$t9,%lo(g_CheatsActiveBank0)($t9)
/*  f18a920:	57200173 */ 	bnezl	$t9,.L0f18aef0
/*  f18a924:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f18a928:	8dce21d4 */ 	lw	$t6,%lo(g_CheatsActiveBank1)($t6)
/*  f18a92c:	55c00170 */ 	bnezl	$t6,.L0f18aef0
/*  f18a930:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f18a934:	8e0d0054 */ 	lw	$t5,0x54($s0)
/*  f18a938:	8e6f0008 */ 	lw	$t7,0x8($s3)
/*  f18a93c:	8e190058 */ 	lw	$t9,0x58($s0)
/*  f18a940:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f18a944:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f18a948:	ae180054 */ 	sw	$t8,0x54($s0)
/*  f18a94c:	8e6e000c */ 	lw	$t6,0xc($s3)
/*  f18a950:	8e0f005c */ 	lw	$t7,0x5c($s0)
/*  f18a954:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f18a958:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f18a95c:	ae0d0058 */ 	sw	$t5,0x58($s0)
/*  f18a960:	ae18005c */ 	sw	$t8,0x5c($s0)
/*  f18a964:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f18a968:	8e190068 */ 	lw	$t9,0x68($s0)
/*  f18a96c:	01c1001a */ 	div	$zero,$t6,$at
/*  f18a970:	00006812 */ 	mflo	$t5
/*  f18a974:	032d7821 */ 	addu	$t7,$t9,$t5
/*  f18a978:	ae0f0068 */ 	sw	$t7,0x68($s0)
/*  f18a97c:	3c017f1c */ 	lui	$at,%hi(var7f1b8da0)
/*  f18a980:	c4308da0 */ 	lwc1	$f16,%lo(var7f1b8da0)($at)
/*  f18a984:	c69200ac */ 	lwc1	$f18,0xac($s4)
/*  f18a988:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18a98c:	3c014f00 */ 	lui	$at,0x4f00
/*  f18a990:	46109103 */ 	div.s	$f4,$f18,$f16
/*  f18a994:	4458f800 */ 	cfc1	$t8,$31
/*  f18a998:	44cef800 */ 	ctc1	$t6,$31
/*  f18a99c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a9a0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f18a9a4:	444ef800 */ 	cfc1	$t6,$31
/*  f18a9a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a9ac:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18a9b0:	51c00013 */ 	beqzl	$t6,.L0f18aa00
/*  f18a9b4:	440e3000 */ 	mfc1	$t6,$f6
/*  f18a9b8:	44813000 */ 	mtc1	$at,$f6
/*  f18a9bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18a9c0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f18a9c4:	44cef800 */ 	ctc1	$t6,$31
/*  f18a9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a9cc:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f18a9d0:	444ef800 */ 	cfc1	$t6,$31
/*  f18a9d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a9d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18a9dc:	15c00005 */ 	bnez	$t6,.L0f18a9f4
/*  f18a9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a9e4:	440e3000 */ 	mfc1	$t6,$f6
/*  f18a9e8:	3c018000 */ 	lui	$at,0x8000
/*  f18a9ec:	10000007 */ 	beqz	$zero,.L0f18aa0c
/*  f18a9f0:	01c17025 */ 	or	$t6,$t6,$at
.L0f18a9f4:
/*  f18a9f4:	10000005 */ 	beqz	$zero,.L0f18aa0c
/*  f18a9f8:	240effff */ 	addiu	$t6,$zero,-1
/*  f18a9fc:	440e3000 */ 	mfc1	$t6,$f6
.L0f18aa00:
/*  f18aa00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa04:	05c0fffb */ 	bltz	$t6,.L0f18a9f4
/*  f18aa08:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18aa0c:
/*  f18aa0c:	8e19006c */ 	lw	$t9,0x6c($s0)
/*  f18aa10:	44d8f800 */ 	ctc1	$t8,$31
/*  f18aa14:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f18aa18:	ae0d006c */ 	sw	$t5,0x6c($s0)
/*  f18aa1c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f18aa20:	19e00062 */ 	blez	$t7,.L0f18abac
/*  f18aa24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa28:	8e18005c */ 	lw	$t8,0x5c($s0)
/*  f18aa2c:	2f010002 */ 	sltiu	$at,$t8,0x2
/*  f18aa30:	10200027 */ 	beqz	$at,.L0f18aad0
/*  f18aa34:	3c01447a */ 	lui	$at,0x447a
/*  f18aa38:	44815000 */ 	mtc1	$at,$f10
/*  f18aa3c:	c6680038 */ 	lwc1	$f8,0x38($s3)
/*  f18aa40:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18aa44:	3c014f00 */ 	lui	$at,0x4f00
/*  f18aa48:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f18aa4c:	4459f800 */ 	cfc1	$t9,$31
/*  f18aa50:	44cef800 */ 	ctc1	$t6,$31
/*  f18aa54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa58:	46009424 */ 	cvt.w.s	$f16,$f18
/*  f18aa5c:	444ef800 */ 	cfc1	$t6,$31
/*  f18aa60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa64:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18aa68:	51c00013 */ 	beqzl	$t6,.L0f18aab8
/*  f18aa6c:	440e8000 */ 	mfc1	$t6,$f16
/*  f18aa70:	44818000 */ 	mtc1	$at,$f16
/*  f18aa74:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18aa78:	46109401 */ 	sub.s	$f16,$f18,$f16
/*  f18aa7c:	44cef800 */ 	ctc1	$t6,$31
/*  f18aa80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa84:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f18aa88:	444ef800 */ 	cfc1	$t6,$31
/*  f18aa8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa90:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18aa94:	15c00005 */ 	bnez	$t6,.L0f18aaac
/*  f18aa98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa9c:	440e8000 */ 	mfc1	$t6,$f16
/*  f18aaa0:	3c018000 */ 	lui	$at,0x8000
/*  f18aaa4:	10000007 */ 	beqz	$zero,.L0f18aac4
/*  f18aaa8:	01c17025 */ 	or	$t6,$t6,$at
.L0f18aaac:
/*  f18aaac:	10000005 */ 	beqz	$zero,.L0f18aac4
/*  f18aab0:	240effff */ 	addiu	$t6,$zero,-1
/*  f18aab4:	440e8000 */ 	mfc1	$t6,$f16
.L0f18aab8:
/*  f18aab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aabc:	05c0fffb */ 	bltz	$t6,.L0f18aaac
/*  f18aac0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18aac4:
/*  f18aac4:	44d9f800 */ 	ctc1	$t9,$31
/*  f18aac8:	10000038 */ 	beqz	$zero,.L0f18abac
/*  f18aacc:	ae0e0070 */ 	sw	$t6,0x70($s0)
.L0f18aad0:
/*  f18aad0:	3c01447a */ 	lui	$at,0x447a
/*  f18aad4:	44810000 */ 	mtc1	$at,$f0
/*  f18aad8:	8e0d0070 */ 	lw	$t5,0x70($s0)
/*  f18aadc:	3c017f1c */ 	lui	$at,%hi(var7f1b8da4)
/*  f18aae0:	c4268da4 */ 	lwc1	$f6,%lo(var7f1b8da4)($at)
/*  f18aae4:	c6640038 */ 	lwc1	$f4,0x38($s3)
/*  f18aae8:	448d5000 */ 	mtc1	$t5,$f10
/*  f18aaec:	3c014f80 */ 	lui	$at,0x4f80
/*  f18aaf0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f18aaf4:	05a10004 */ 	bgez	$t5,.L0f18ab08
/*  f18aaf8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f18aafc:	44818000 */ 	mtc1	$at,$f16
/*  f18ab00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab04:	46109480 */ 	add.s	$f18,$f18,$f16
.L0f18ab08:
/*  f18ab08:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f18ab0c:	3c017f1c */ 	lui	$at,%hi(var7f1b8da8)
/*  f18ab10:	c4268da8 */ 	lwc1	$f6,%lo(var7f1b8da8)($at)
/*  f18ab14:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18ab18:	3c014f00 */ 	lui	$at,0x4f00
/*  f18ab1c:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f18ab20:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f18ab24:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f18ab28:	444ff800 */ 	cfc1	$t7,$31
/*  f18ab2c:	44d8f800 */ 	ctc1	$t8,$31
/*  f18ab30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab34:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f18ab38:	4458f800 */ 	cfc1	$t8,$31
/*  f18ab3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab40:	33180078 */ 	andi	$t8,$t8,0x78
/*  f18ab44:	53000013 */ 	beqzl	$t8,.L0f18ab94
/*  f18ab48:	44182000 */ 	mfc1	$t8,$f4
/*  f18ab4c:	44812000 */ 	mtc1	$at,$f4
/*  f18ab50:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18ab54:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f18ab58:	44d8f800 */ 	ctc1	$t8,$31
/*  f18ab5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab60:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f18ab64:	4458f800 */ 	cfc1	$t8,$31
/*  f18ab68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab6c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f18ab70:	17000005 */ 	bnez	$t8,.L0f18ab88
/*  f18ab74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab78:	44182000 */ 	mfc1	$t8,$f4
/*  f18ab7c:	3c018000 */ 	lui	$at,0x8000
/*  f18ab80:	10000007 */ 	beqz	$zero,.L0f18aba0
/*  f18ab84:	0301c025 */ 	or	$t8,$t8,$at
.L0f18ab88:
/*  f18ab88:	10000005 */ 	beqz	$zero,.L0f18aba0
/*  f18ab8c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f18ab90:	44182000 */ 	mfc1	$t8,$f4
.L0f18ab94:
/*  f18ab94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab98:	0700fffb */ 	bltz	$t8,.L0f18ab88
/*  f18ab9c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18aba0:
/*  f18aba0:	44cff800 */ 	ctc1	$t7,$31
/*  f18aba4:	ae180070 */ 	sw	$t8,0x70($s0)
/*  f18aba8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18abac:
/*  f18abac:	3c017f1c */ 	lui	$at,%hi(var7f1b8dac)
/*  f18abb0:	c4288dac */ 	lwc1	$f8,%lo(var7f1b8dac)($at)
/*  f18abb4:	c68600f0 */ 	lwc1	$f6,0xf0($s4)
/*  f18abb8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18abbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f18abc0:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f18abc4:	4459f800 */ 	cfc1	$t9,$31
/*  f18abc8:	44cef800 */ 	ctc1	$t6,$31
/*  f18abcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abd0:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f18abd4:	444ef800 */ 	cfc1	$t6,$31
/*  f18abd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abdc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18abe0:	51c00013 */ 	beqzl	$t6,.L0f18ac30
/*  f18abe4:	440e8000 */ 	mfc1	$t6,$f16
/*  f18abe8:	44818000 */ 	mtc1	$at,$f16
/*  f18abec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18abf0:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f18abf4:	44cef800 */ 	ctc1	$t6,$31
/*  f18abf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abfc:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f18ac00:	444ef800 */ 	cfc1	$t6,$31
/*  f18ac04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ac08:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18ac0c:	15c00005 */ 	bnez	$t6,.L0f18ac24
/*  f18ac10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ac14:	440e8000 */ 	mfc1	$t6,$f16
/*  f18ac18:	3c018000 */ 	lui	$at,0x8000
/*  f18ac1c:	10000007 */ 	beqz	$zero,.L0f18ac3c
/*  f18ac20:	01c17025 */ 	or	$t6,$t6,$at
.L0f18ac24:
/*  f18ac24:	10000005 */ 	beqz	$zero,.L0f18ac3c
/*  f18ac28:	240effff */ 	addiu	$t6,$zero,-1
/*  f18ac2c:	440e8000 */ 	mfc1	$t6,$f16
.L0f18ac30:
/*  f18ac30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ac34:	05c0fffb */ 	bltz	$t6,.L0f18ac24
/*  f18ac38:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18ac3c:
/*  f18ac3c:	8e0d0074 */ 	lw	$t5,0x74($s0)
/*  f18ac40:	3c017f1c */ 	lui	$at,%hi(var7f1b8db0)
/*  f18ac44:	44d9f800 */ 	ctc1	$t9,$31
/*  f18ac48:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f18ac4c:	ae0f0074 */ 	sw	$t7,0x74($s0)
/*  f18ac50:	c4248db0 */ 	lwc1	$f4,%lo(var7f1b8db0)($at)
/*  f18ac54:	c69200ec */ 	lwc1	$f18,0xec($s4)
/*  f18ac58:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18ac5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f18ac60:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f18ac64:	4458f800 */ 	cfc1	$t8,$31
/*  f18ac68:	44d9f800 */ 	ctc1	$t9,$31
/*  f18ac6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ac70:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f18ac74:	4459f800 */ 	cfc1	$t9,$31
/*  f18ac78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ac7c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f18ac80:	53200013 */ 	beqzl	$t9,.L0f18acd0
/*  f18ac84:	44194000 */ 	mfc1	$t9,$f8
/*  f18ac88:	44814000 */ 	mtc1	$at,$f8
/*  f18ac8c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18ac90:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f18ac94:	44d9f800 */ 	ctc1	$t9,$31
/*  f18ac98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ac9c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f18aca0:	4459f800 */ 	cfc1	$t9,$31
/*  f18aca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aca8:	33390078 */ 	andi	$t9,$t9,0x78
/*  f18acac:	17200005 */ 	bnez	$t9,.L0f18acc4
/*  f18acb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18acb4:	44194000 */ 	mfc1	$t9,$f8
/*  f18acb8:	3c018000 */ 	lui	$at,0x8000
/*  f18acbc:	10000007 */ 	beqz	$zero,.L0f18acdc
/*  f18acc0:	0321c825 */ 	or	$t9,$t9,$at
.L0f18acc4:
/*  f18acc4:	10000005 */ 	beqz	$zero,.L0f18acdc
/*  f18acc8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f18accc:	44194000 */ 	mfc1	$t9,$f8
.L0f18acd0:
/*  f18acd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18acd4:	0720fffb */ 	bltz	$t9,.L0f18acc4
/*  f18acd8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18acdc:
/*  f18acdc:	8e0d0078 */ 	lw	$t5,0x78($s0)
/*  f18ace0:	44d8f800 */ 	ctc1	$t8,$31
/*  f18ace4:	8e0f007c */ 	lw	$t7,0x7c($s0)
/*  f18ace8:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f18acec:	ae0e0078 */ 	sw	$t6,0x78($s0)
/*  f18acf0:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f18acf4:	8e190080 */ 	lw	$t9,0x80($s0)
/*  f18acf8:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f18acfc:	ae0d007c */ 	sw	$t5,0x7c($s0)
/*  f18ad00:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f18ad04:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f18ad08:	ae0f0080 */ 	sw	$t7,0x80($s0)
/*  f18ad0c:	8fb801e4 */ 	lw	$t8,0x1e4($sp)
/*  f18ad10:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f18ad14:	2b010002 */ 	slti	$at,$t8,0x2
/*  f18ad18:	54200005 */ 	bnezl	$at,.L0f18ad30
/*  f18ad1c:	29c10002 */ 	slti	$at,$t6,0x2
/*  f18ad20:	8ead000c */ 	lw	$t5,0xc($s5)
/*  f18ad24:	31b90002 */ 	andi	$t9,$t5,0x2
/*  f18ad28:	13200003 */ 	beqz	$t9,.L0f18ad38
/*  f18ad2c:	29c10002 */ 	slti	$at,$t6,0x2
.L0f18ad30:
/*  f18ad30:	5420006f */ 	bnezl	$at,.L0f18aef0
/*  f18ad34:	8faf02fc */ 	lw	$t7,0x2fc($sp)
.L0f18ad38:
/*  f18ad38:	820f001e */ 	lb	$t7,0x1e($s0)
/*  f18ad3c:	00002825 */ 	or	$a1,$zero,$zero
/*  f18ad40:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ad44:	55e0002e */ 	bnezl	$t7,.L0f18ae00
/*  f18ad48:	8ea6000c */ 	lw	$a2,0xc($s5)
/*  f18ad4c:	96a70016 */ 	lhu	$a3,0x16($s5)
/*  f18ad50:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f18ad54:
/*  f18ad54:	00786804 */ 	sllv	$t5,$t8,$v1
/*  f18ad58:	00edc824 */ 	and	$t9,$a3,$t5
/*  f18ad5c:	1320001f */ 	beqz	$t9,.L0f18addc
/*  f18ad60:	28610004 */ 	slti	$at,$v1,0x4
/*  f18ad64:	10200006 */ 	beqz	$at,.L0f18ad80
/*  f18ad68:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f18ad6c:	00037080 */ 	sll	$t6,$v1,0x2
/*  f18ad70:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f18ad74:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18ad78:	1000000a */ 	beqz	$zero,.L0f18ada4
/*  f18ad7c:	03ce1021 */ 	addu	$v0,$s8,$t6
.L0f18ad80:
/*  f18ad80:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18ad84:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f18ad88:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18ad8c:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f18ad90:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18ad94:	3c0d800b */ 	lui	$t5,%hi(g_MpSimulants)
/*  f18ad98:	25adc538 */ 	addiu	$t5,$t5,%lo(g_MpSimulants)
/*  f18ad9c:	25f8fed0 */ 	addiu	$t8,$t7,-304
/*  f18ada0:	030d1021 */ 	addu	$v0,$t8,$t5
.L0f18ada4:
/*  f18ada4:	8c590020 */ 	lw	$t9,0x20($v0)
/*  f18ada8:	5499000d */ 	bnel	$a0,$t9,.L0f18ade0
/*  f18adac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18adb0:	5202000b */ 	beql	$s0,$v0,.L0f18ade0
/*  f18adb4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18adb8:	8eae000c */ 	lw	$t6,0xc($s5)
/*  f18adbc:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f18adc0:	51e00006 */ 	beqzl	$t7,.L0f18addc
/*  f18adc4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18adc8:	92180011 */ 	lbu	$t8,0x11($s0)
/*  f18adcc:	904d0011 */ 	lbu	$t5,0x11($v0)
/*  f18add0:	530d0003 */ 	beql	$t8,$t5,.L0f18ade0
/*  f18add4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18add8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18addc:
/*  f18addc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18ade0:
/*  f18ade0:	5477ffdc */ 	bnel	$v1,$s7,.L0f18ad54
/*  f18ade4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18ade8:	54a00005 */ 	bnezl	$a1,.L0f18ae00
/*  f18adec:	8ea6000c */ 	lw	$a2,0xc($s5)
/*  f18adf0:	8e190060 */ 	lw	$t9,0x60($s0)
/*  f18adf4:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f18adf8:	ae0e0060 */ 	sw	$t6,0x60($s0)
/*  f18adfc:	8ea6000c */ 	lw	$a2,0xc($s5)
.L0f18ae00:
/*  f18ae00:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f18ae04:	15e00006 */ 	bnez	$t7,.L0f18ae20
/*  f18ae08:	01e03025 */ 	or	$a2,$t7,$zero
/*  f18ae0c:	820d001e */ 	lb	$t5,0x1e($s0)
/*  f18ae10:	8fb801e4 */ 	lw	$t8,0x1e4($sp)
/*  f18ae14:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f18ae18:	53190008 */ 	beql	$t8,$t9,.L0f18ae3c
/*  f18ae1c:	00002825 */ 	or	$a1,$zero,$zero
.L0f18ae20:
/*  f18ae20:	10c00032 */ 	beqz	$a2,.L0f18aeec
/*  f18ae24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae28:	820f001e */ 	lb	$t7,0x1e($s0)
/*  f18ae2c:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f18ae30:	25ed0001 */ 	addiu	$t5,$t7,0x1
/*  f18ae34:	15cd002d */ 	bne	$t6,$t5,.L0f18aeec
/*  f18ae38:	00002825 */ 	or	$a1,$zero,$zero
.L0f18ae3c:
/*  f18ae3c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ae40:	96a70016 */ 	lhu	$a3,0x16($s5)
/*  f18ae44:	240800a0 */ 	addiu	$t0,$zero,0xa0
/*  f18ae48:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f18ae4c:
/*  f18ae4c:	0078c804 */ 	sllv	$t9,$t8,$v1
/*  f18ae50:	00f97824 */ 	and	$t7,$a3,$t9
/*  f18ae54:	11e0001d */ 	beqz	$t7,.L0f18aecc
/*  f18ae58:	28610004 */ 	slti	$at,$v1,0x4
/*  f18ae5c:	10200006 */ 	beqz	$at,.L0f18ae78
/*  f18ae60:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f18ae64:	00680019 */ 	multu	$v1,$t0
/*  f18ae68:	00007012 */ 	mflo	$t6
/*  f18ae6c:	03ce1021 */ 	addu	$v0,$s8,$t6
/*  f18ae70:	1000000b */ 	beqz	$zero,.L0f18aea0
/*  f18ae74:	8c4f0020 */ 	lw	$t7,0x20($v0)
.L0f18ae78:
/*  f18ae78:	00036880 */ 	sll	$t5,$v1,0x2
/*  f18ae7c:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f18ae80:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18ae84:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f18ae88:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18ae8c:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18ae90:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f18ae94:	25b8fed0 */ 	addiu	$t8,$t5,-304
/*  f18ae98:	03191021 */ 	addu	$v0,$t8,$t9
/*  f18ae9c:	8c4f0020 */ 	lw	$t7,0x20($v0)
.L0f18aea0:
/*  f18aea0:	548f000b */ 	bnel	$a0,$t7,.L0f18aed0
/*  f18aea4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18aea8:	52020009 */ 	beql	$s0,$v0,.L0f18aed0
/*  f18aeac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18aeb0:	50c00006 */ 	beqzl	$a2,.L0f18aecc
/*  f18aeb4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18aeb8:	920e0011 */ 	lbu	$t6,0x11($s0)
/*  f18aebc:	904d0011 */ 	lbu	$t5,0x11($v0)
/*  f18aec0:	51cd0003 */ 	beql	$t6,$t5,.L0f18aed0
/*  f18aec4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18aec8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18aecc:
/*  f18aecc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18aed0:
/*  f18aed0:	5477ffde */ 	bnel	$v1,$s7,.L0f18ae4c
/*  f18aed4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18aed8:	14a00004 */ 	bnez	$a1,.L0f18aeec
/*  f18aedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aee0:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f18aee4:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f18aee8:	ae190064 */ 	sw	$t9,0x64($s0)
.L0f18aeec:
/*  f18aeec:	8faf02fc */ 	lw	$t7,0x2fc($sp)
.L0f18aef0:
/*  f18aef0:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18aef4:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f18aef8:	16cffdec */ 	bne	$s6,$t7,.L0f18a6ac
/*  f18aefc:	26940080 */ 	addiu	$s4,$s4,0x80
.L0f18af00:
/*  f18af00:	3c1e800b */ 	lui	$s8,%hi(g_MpPlayers)
/*  f18af04:	27dec7b8 */ 	addiu	$s8,$s8,%lo(g_MpPlayers)
/*  f18af08:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f18af0c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18af10:	8fa402f0 */ 	lw	$a0,0x2f0($sp)
/*  f18af14:	8fae02c0 */ 	lw	$t6,0x2c0($sp)
/*  f18af18:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18af1c:	8fa5020c */ 	lw	$a1,0x20c($sp)
/*  f18af20:	8fa60248 */ 	lw	$a2,0x248($sp)
/*  f18af24:	8fa70284 */ 	lw	$a3,0x284($sp)
/*  f18af28:	0fc62730 */ 	jal	func0f189cc0
/*  f18af2c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f18af30:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18af34:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18af38:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18af3c:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18af40:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18af44:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f18af48:	5b200005 */ 	blezl	$t9,.L0f18af60
/*  f18af4c:	8fad02b0 */ 	lw	$t5,0x2b0($sp)
/*  f18af50:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18af54:	35ee0001 */ 	ori	$t6,$t7,0x1
/*  f18af58:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f18af5c:	8fad02b0 */ 	lw	$t5,0x2b0($sp)
.L0f18af60:
/*  f18af60:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18af64:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f18af68:	8fa60238 */ 	lw	$a2,0x238($sp)
/*  f18af6c:	8fa70274 */ 	lw	$a3,0x274($sp)
/*  f18af70:	0fc62772 */ 	jal	func0f189dc8
/*  f18af74:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f18af78:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f18af7c:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f18af80:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18af84:	27b901fc */ 	addiu	$t9,$sp,0x1fc
/*  f18af88:	03198021 */ 	addu	$s0,$t8,$t9
/*  f18af8c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18af90:	29e10064 */ 	slti	$at,$t7,0x64
/*  f18af94:	50200005 */ 	beqzl	$at,.L0f18afac
/*  f18af98:	c7aa02d8 */ 	lwc1	$f10,0x2d8($sp)
/*  f18af9c:	8e0e002c */ 	lw	$t6,0x2c($s0)
/*  f18afa0:	35cd0002 */ 	ori	$t5,$t6,0x2
/*  f18afa4:	ae0d002c */ 	sw	$t5,0x2c($s0)
/*  f18afa8:	c7aa02d8 */ 	lwc1	$f10,0x2d8($sp)
.L0f18afac:
/*  f18afac:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18afb0:	8fa50224 */ 	lw	$a1,0x224($sp)
/*  f18afb4:	8fa60260 */ 	lw	$a2,0x260($sp)
/*  f18afb8:	8fa7029c */ 	lw	$a3,0x29c($sp)
/*  f18afbc:	0fc6280c */ 	jal	func0f18a030
/*  f18afc0:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f18afc4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f18afc8:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f18afcc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18afd0:	27b901fc */ 	addiu	$t9,$sp,0x1fc
/*  f18afd4:	03198021 */ 	addu	$s0,$t8,$t9
/*  f18afd8:	3c014000 */ 	lui	$at,0x4000
/*  f18afdc:	44818000 */ 	mtc1	$at,$f16
/*  f18afe0:	c6120028 */ 	lwc1	$f18,0x28($s0)
/*  f18afe4:	4610903e */ 	c.le.s	$f18,$f16
/*  f18afe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18afec:	45020005 */ 	bc1fl	.L0f18b004
/*  f18aff0:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
/*  f18aff4:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18aff8:	35ee0004 */ 	ori	$t6,$t7,0x4
/*  f18affc:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f18b000:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
.L0f18b004:
/*  f18b004:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b008:	8fa50224 */ 	lw	$a1,0x224($sp)
/*  f18b00c:	8fa60260 */ 	lw	$a2,0x260($sp)
/*  f18b010:	8fa7029c */ 	lw	$a3,0x29c($sp)
/*  f18b014:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b018:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f18b01c:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b020:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b024:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b028:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b02c:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18b030:	3c0140c0 */ 	lui	$at,0x40c0
/*  f18b034:	44813000 */ 	mtc1	$at,$f6
/*  f18b038:	c6080028 */ 	lwc1	$f8,0x28($s0)
/*  f18b03c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18b040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b044:	45020005 */ 	bc1fl	.L0f18b05c
/*  f18b048:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f18b04c:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f18b050:	372f0008 */ 	ori	$t7,$t9,0x8
/*  f18b054:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f18b058:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
.L0f18b05c:
/*  f18b05c:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b060:	8fa50200 */ 	lw	$a1,0x200($sp)
/*  f18b064:	8fa6023c */ 	lw	$a2,0x23c($sp)
/*  f18b068:	8fa70278 */ 	lw	$a3,0x278($sp)
/*  f18b06c:	0fc62730 */ 	jal	func0f189cc0
/*  f18b070:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f18b074:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b078:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b07c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b080:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b084:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18b088:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f18b08c:	5b200005 */ 	blezl	$t9,.L0f18b0a4
/*  f18b090:	c7aa02c4 */ 	lwc1	$f10,0x2c4($sp)
/*  f18b094:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18b098:	35ee0010 */ 	ori	$t6,$t7,0x10
/*  f18b09c:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f18b0a0:	c7aa02c4 */ 	lwc1	$f10,0x2c4($sp)
.L0f18b0a4:
/*  f18b0a4:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b0a8:	8fa50210 */ 	lw	$a1,0x210($sp)
/*  f18b0ac:	8fa6024c */ 	lw	$a2,0x24c($sp)
/*  f18b0b0:	8fa70288 */ 	lw	$a3,0x288($sp)
/*  f18b0b4:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b0b8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f18b0bc:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b0c0:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b0c4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b0c8:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b0cc:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18b0d0:	c6120014 */ 	lwc1	$f18,0x14($s0)
/*  f18b0d4:	44808000 */ 	mtc1	$zero,$f16
/*  f18b0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0dc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f18b0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0e4:	45020005 */ 	bc1fl	.L0f18b0fc
/*  f18b0e8:	c7a402c8 */ 	lwc1	$f4,0x2c8($sp)
/*  f18b0ec:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f18b0f0:	372f0020 */ 	ori	$t7,$t9,0x20
/*  f18b0f4:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f18b0f8:	c7a402c8 */ 	lwc1	$f4,0x2c8($sp)
.L0f18b0fc:
/*  f18b0fc:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b100:	8fa50214 */ 	lw	$a1,0x214($sp)
/*  f18b104:	8fa60250 */ 	lw	$a2,0x250($sp)
/*  f18b108:	8fa7028c */ 	lw	$a3,0x28c($sp)
/*  f18b10c:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b110:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f18b114:	00027100 */ 	sll	$t6,$v0,0x4
/*  f18b118:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18b11c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b120:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b124:	01cd8021 */ 	addu	$s0,$t6,$t5
/*  f18b128:	c6080018 */ 	lwc1	$f8,0x18($s0)
/*  f18b12c:	44803000 */ 	mtc1	$zero,$f6
/*  f18b130:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b134:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18b138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b13c:	45020005 */ 	bc1fl	.L0f18b154
/*  f18b140:	c7aa02c8 */ 	lwc1	$f10,0x2c8($sp)
/*  f18b144:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f18b148:	37190040 */ 	ori	$t9,$t8,0x40
/*  f18b14c:	ae19002c */ 	sw	$t9,0x2c($s0)
/*  f18b150:	c7aa02c8 */ 	lwc1	$f10,0x2c8($sp)
.L0f18b154:
/*  f18b154:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b158:	8fa50214 */ 	lw	$a1,0x214($sp)
/*  f18b15c:	8fa60250 */ 	lw	$a2,0x250($sp)
/*  f18b160:	8fa7028c */ 	lw	$a3,0x28c($sp)
/*  f18b164:	0fc6280c */ 	jal	func0f18a030
/*  f18b168:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f18b16c:	3c0f800a */ 	lui	$t7,0x800a
/*  f18b170:	8defa02c */ 	lw	$t7,-0x5fd4($t7)
/*  f18b174:	3c0d800a */ 	lui	$t5,0x800a
/*  f18b178:	3c19800a */ 	lui	$t9,0x800a
/*  f18b17c:	11e00003 */ 	beqz	$t7,.L0f18b18c
/*  f18b180:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18b184:	10000002 */ 	beqz	$zero,.L0f18b190
/*  f18b188:	afae0064 */ 	sw	$t6,0x64($sp)
.L0f18b18c:
/*  f18b18c:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f18b190:
/*  f18b190:	8dada028 */ 	lw	$t5,-0x5fd8($t5)
/*  f18b194:	3c0e800a */ 	lui	$t6,0x800a
/*  f18b198:	11a00003 */ 	beqz	$t5,.L0f18b1a8
/*  f18b19c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b1a0:	10000002 */ 	beqz	$zero,.L0f18b1ac
/*  f18b1a4:	afb80068 */ 	sw	$t8,0x68($sp)
.L0f18b1a8:
/*  f18b1a8:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f18b1ac:
/*  f18b1ac:	8f39a024 */ 	lw	$t9,-0x5fdc($t9)
/*  f18b1b0:	13200003 */ 	beqz	$t9,.L0f18b1c0
/*  f18b1b4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18b1b8:	10000002 */ 	beqz	$zero,.L0f18b1c4
/*  f18b1bc:	afaf006c */ 	sw	$t7,0x6c($sp)
.L0f18b1c0:
/*  f18b1c0:	afa0006c */ 	sw	$zero,0x6c($sp)
.L0f18b1c4:
/*  f18b1c4:	8dcea030 */ 	lw	$t6,-0x5fd0($t6)
/*  f18b1c8:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f18b1cc:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f18b1d0:	51c00004 */ 	beqzl	$t6,.L0f18b1e4
/*  f18b1d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f18b1d8:	10000002 */ 	beqz	$zero,.L0f18b1e4
/*  f18b1dc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f18b1e0:	00008825 */ 	or	$s1,$zero,$zero
.L0f18b1e4:
/*  f18b1e4:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f18b1e8:	022dc021 */ 	addu	$t8,$s1,$t5
/*  f18b1ec:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18b1f0:	01ee6821 */ 	addu	$t5,$t7,$t6
/*  f18b1f4:	29a10002 */ 	slti	$at,$t5,0x2
/*  f18b1f8:	14200008 */ 	bnez	$at,.L0f18b21c
/*  f18b1fc:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f18b200:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f18b204:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18b208:	27b901fc */ 	addiu	$t9,$sp,0x1fc
/*  f18b20c:	03198021 */ 	addu	$s0,$t8,$t9
/*  f18b210:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18b214:	35ee0080 */ 	ori	$t6,$t7,0x80
/*  f18b218:	ae0e002c */ 	sw	$t6,0x2c($s0)
.L0f18b21c:
/*  f18b21c:	8fad02d0 */ 	lw	$t5,0x2d0($sp)
/*  f18b220:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b224:	8fa5021c */ 	lw	$a1,0x21c($sp)
/*  f18b228:	8fa60258 */ 	lw	$a2,0x258($sp)
/*  f18b22c:	8fa70294 */ 	lw	$a3,0x294($sp)
/*  f18b230:	0fc62772 */ 	jal	func0f189dc8
/*  f18b234:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f18b238:	3c18800a */ 	lui	$t8,0x800a
/*  f18b23c:	8f18a02c */ 	lw	$t8,-0x5fd4($t8)
/*  f18b240:	3c0f800a */ 	lui	$t7,0x800a
/*  f18b244:	3c0d800a */ 	lui	$t5,0x800a
/*  f18b248:	13000003 */ 	beqz	$t8,.L0f18b258
/*  f18b24c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18b250:	10000002 */ 	beqz	$zero,.L0f18b25c
/*  f18b254:	afb90064 */ 	sw	$t9,0x64($sp)
.L0f18b258:
/*  f18b258:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f18b25c:
/*  f18b25c:	8defa028 */ 	lw	$t7,-0x5fd8($t7)
/*  f18b260:	3c19800a */ 	lui	$t9,0x800a
/*  f18b264:	11e00003 */ 	beqz	$t7,.L0f18b274
/*  f18b268:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18b26c:	10000002 */ 	beqz	$zero,.L0f18b278
/*  f18b270:	afae0068 */ 	sw	$t6,0x68($sp)
.L0f18b274:
/*  f18b274:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f18b278:
/*  f18b278:	8dada024 */ 	lw	$t5,-0x5fdc($t5)
/*  f18b27c:	11a00003 */ 	beqz	$t5,.L0f18b28c
/*  f18b280:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b284:	10000002 */ 	beqz	$zero,.L0f18b290
/*  f18b288:	afb8006c */ 	sw	$t8,0x6c($sp)
.L0f18b28c:
/*  f18b28c:	afa0006c */ 	sw	$zero,0x6c($sp)
.L0f18b290:
/*  f18b290:	8f39a030 */ 	lw	$t9,-0x5fd0($t9)
/*  f18b294:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f18b298:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f18b29c:	53200004 */ 	beqzl	$t9,.L0f18b2b0
/*  f18b2a0:	00008825 */ 	or	$s1,$zero,$zero
/*  f18b2a4:	10000002 */ 	beqz	$zero,.L0f18b2b0
/*  f18b2a8:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f18b2ac:	00008825 */ 	or	$s1,$zero,$zero
.L0f18b2b0:
/*  f18b2b0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f18b2b4:	022f7021 */ 	addu	$t6,$s1,$t7
/*  f18b2b8:	01cdc021 */ 	addu	$t8,$t6,$t5
/*  f18b2bc:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18b2c0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f18b2c4:	14200008 */ 	bnez	$at,.L0f18b2e8
/*  f18b2c8:	00027100 */ 	sll	$t6,$v0,0x4
/*  f18b2cc:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18b2d0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b2d4:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b2d8:	01cd8021 */ 	addu	$s0,$t6,$t5
/*  f18b2dc:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f18b2e0:	37190100 */ 	ori	$t9,$t8,0x100
/*  f18b2e4:	ae19002c */ 	sw	$t9,0x2c($s0)
.L0f18b2e8:
/*  f18b2e8:	c7b002d4 */ 	lwc1	$f16,0x2d4($sp)
/*  f18b2ec:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b2f0:	8fa50220 */ 	lw	$a1,0x220($sp)
/*  f18b2f4:	8fa6025c */ 	lw	$a2,0x25c($sp)
/*  f18b2f8:	8fa70298 */ 	lw	$a3,0x298($sp)
/*  f18b2fc:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b300:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f18b304:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18b308:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18b30c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b310:	27ae01fc */ 	addiu	$t6,$sp,0x1fc
/*  f18b314:	01ee8021 */ 	addu	$s0,$t7,$t6
/*  f18b318:	3c014120 */ 	lui	$at,0x4120
/*  f18b31c:	44819000 */ 	mtc1	$at,$f18
/*  f18b320:	c6040024 */ 	lwc1	$f4,0x24($s0)
/*  f18b324:	4604903c */ 	c.lt.s	$f18,$f4
/*  f18b328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b32c:	45020005 */ 	bc1fl	.L0f18b344
/*  f18b330:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f18b334:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f18b338:	35b80200 */ 	ori	$t8,$t5,0x200
/*  f18b33c:	ae18002c */ 	sw	$t8,0x2c($s0)
/*  f18b340:	8fb902cc */ 	lw	$t9,0x2cc($sp)
.L0f18b344:
/*  f18b344:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b348:	8fa50218 */ 	lw	$a1,0x218($sp)
/*  f18b34c:	8fa60254 */ 	lw	$a2,0x254($sp)
/*  f18b350:	8fa70290 */ 	lw	$a3,0x290($sp)
/*  f18b354:	0fc62772 */ 	jal	func0f189dc8
/*  f18b358:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f18b35c:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18b360:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18b364:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b368:	27ae01fc */ 	addiu	$t6,$sp,0x1fc
/*  f18b36c:	01ee8021 */ 	addu	$s0,$t7,$t6
/*  f18b370:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f18b374:	35b80400 */ 	ori	$t8,$t5,0x400
/*  f18b378:	ae18002c */ 	sw	$t8,0x2c($s0)
/*  f18b37c:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f18b380:	8fa70290 */ 	lw	$a3,0x290($sp)
/*  f18b384:	8fa60254 */ 	lw	$a2,0x254($sp)
/*  f18b388:	8fa50218 */ 	lw	$a1,0x218($sp)
/*  f18b38c:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b390:	0fc62730 */ 	jal	func0f189cc0
/*  f18b394:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f18b398:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18b39c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18b3a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b3a4:	27ae01fc */ 	addiu	$t6,$sp,0x1fc
/*  f18b3a8:	01ee8021 */ 	addu	$s0,$t7,$t6
/*  f18b3ac:	8e0d001c */ 	lw	$t5,0x1c($s0)
/*  f18b3b0:	59a00007 */ 	blezl	$t5,.L0f18b3d0
/*  f18b3b4:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f18b3b8:	8e03002c */ 	lw	$v1,0x2c($s0)
/*  f18b3bc:	30780400 */ 	andi	$t8,$v1,0x400
/*  f18b3c0:	17000002 */ 	bnez	$t8,.L0f18b3cc
/*  f18b3c4:	34790800 */ 	ori	$t9,$v1,0x800
/*  f18b3c8:	ae19002c */ 	sw	$t9,0x2c($s0)
.L0f18b3cc:
/*  f18b3cc:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
.L0f18b3d0:
/*  f18b3d0:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b3d4:	8fa5022c */ 	lw	$a1,0x22c($sp)
/*  f18b3d8:	8fa60268 */ 	lw	$a2,0x268($sp)
/*  f18b3dc:	8fa702a4 */ 	lw	$a3,0x2a4($sp)
/*  f18b3e0:	0fc62730 */ 	jal	func0f189cc0
/*  f18b3e4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18b3e8:	00027100 */ 	sll	$t6,$v0,0x4
/*  f18b3ec:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18b3f0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b3f4:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b3f8:	01cd8021 */ 	addu	$s0,$t6,$t5
/*  f18b3fc:	8e180030 */ 	lw	$t8,0x30($s0)
/*  f18b400:	5b000005 */ 	blezl	$t8,.L0f18b418
/*  f18b404:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f18b408:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f18b40c:	372f2000 */ 	ori	$t7,$t9,0x2000
/*  f18b410:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f18b414:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
.L0f18b418:
/*  f18b418:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b41c:	8fa50230 */ 	lw	$a1,0x230($sp)
/*  f18b420:	8fa6026c */ 	lw	$a2,0x26c($sp)
/*  f18b424:	8fa702a8 */ 	lw	$a3,0x2a8($sp)
/*  f18b428:	0fc62772 */ 	jal	func0f189dc8
/*  f18b42c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f18b430:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b434:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b438:	27a701fc */ 	addiu	$a3,$sp,0x1fc
/*  f18b43c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b440:	00ed8021 */ 	addu	$s0,$a3,$t5
/*  f18b444:	8e180034 */ 	lw	$t8,0x34($s0)
/*  f18b448:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f18b44c:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f18b450:	1b000007 */ 	blez	$t8,.L0f18b470
/*  f18b454:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f18b458:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f18b45c:	5b200005 */ 	blezl	$t9,.L0f18b474
/*  f18b460:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f18b464:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18b468:	35ee1000 */ 	ori	$t6,$t7,0x1000
/*  f18b46c:	ae0e002c */ 	sw	$t6,0x2c($s0)
.L0f18b470:
/*  f18b470:	8fa802fc */ 	lw	$t0,0x2fc($sp)
.L0f18b474:
/*  f18b474:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18b478:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18b47c:	19000021 */ 	blez	$t0,.L0f18b504
/*  f18b480:	3c040001 */ 	lui	$a0,0x1
/*  f18b484:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f18b488:
/*  f18b488:	8e8200cc */ 	lw	$v0,0xcc($s4)
/*  f18b48c:	00166900 */ 	sll	$t5,$s6,0x4
/*  f18b490:	01b66823 */ 	subu	$t5,$t5,$s6
/*  f18b494:	14620006 */ 	bne	$v1,$v0,.L0f18b4b0
/*  f18b498:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b49c:	00ed9821 */ 	addu	$s3,$a3,$t5
/*  f18b4a0:	8e78002c */ 	lw	$t8,0x2c($s3)
/*  f18b4a4:	0304c825 */ 	or	$t9,$t8,$a0
/*  f18b4a8:	10000012 */ 	beqz	$zero,.L0f18b4f4
/*  f18b4ac:	ae79002c */ 	sw	$t9,0x2c($s3)
.L0f18b4b0:
/*  f18b4b0:	14a20008 */ 	bne	$a1,$v0,.L0f18b4d4
/*  f18b4b4:	00167900 */ 	sll	$t7,$s6,0x4
/*  f18b4b8:	01f67823 */ 	subu	$t7,$t7,$s6
/*  f18b4bc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b4c0:	00ef9821 */ 	addu	$s3,$a3,$t7
/*  f18b4c4:	8e6e002c */ 	lw	$t6,0x2c($s3)
/*  f18b4c8:	35cd8000 */ 	ori	$t5,$t6,0x8000
/*  f18b4cc:	10000009 */ 	beqz	$zero,.L0f18b4f4
/*  f18b4d0:	ae6d002c */ 	sw	$t5,0x2c($s3)
.L0f18b4d4:
/*  f18b4d4:	14c20007 */ 	bne	$a2,$v0,.L0f18b4f4
/*  f18b4d8:	0016c100 */ 	sll	$t8,$s6,0x4
/*  f18b4dc:	0316c023 */ 	subu	$t8,$t8,$s6
/*  f18b4e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18b4e4:	00f89821 */ 	addu	$s3,$a3,$t8
/*  f18b4e8:	8e79002c */ 	lw	$t9,0x2c($s3)
/*  f18b4ec:	372f4000 */ 	ori	$t7,$t9,0x4000
/*  f18b4f0:	ae6f002c */ 	sw	$t7,0x2c($s3)
.L0f18b4f4:
/*  f18b4f4:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b4f8:	16c8ffe3 */ 	bne	$s6,$t0,.L0f18b488
/*  f18b4fc:	26940080 */ 	addiu	$s4,$s4,0x80
/*  f18b500:	0000b025 */ 	or	$s6,$zero,$zero
.L0f18b504:
/*  f18b504:	1900000a */ 	blez	$t0,.L0f18b530
/*  f18b508:	27b301fc */ 	addiu	$s3,$sp,0x1fc
/*  f18b50c:	24020011 */ 	addiu	$v0,$zero,0x11
.L0f18b510:
/*  f18b510:	00001825 */ 	or	$v1,$zero,$zero
/*  f18b514:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18b518:
/*  f18b518:	5462ffff */ 	bnel	$v1,$v0,.L0f18b518
/*  f18b51c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18b520:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b524:	16c8fffa */ 	bne	$s6,$t0,.L0f18b510
/*  f18b528:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f18b52c:	0000b025 */ 	or	$s6,$zero,$zero
.L0f18b530:
/*  f18b530:	19000066 */ 	blez	$t0,.L0f18b6cc
/*  f18b534:	3c148008 */ 	lui	$s4,%hi(var800874cc)
/*  f18b538:	269474cc */ 	addiu	$s4,$s4,%lo(var800874cc)
/*  f18b53c:	24150011 */ 	addiu	$s5,$zero,0x11
/*  f18b540:	8fae02fc */ 	lw	$t6,0x2fc($sp)
.L0f18b544:
/*  f18b544:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18b548:	00009025 */ 	or	$s2,$zero,$zero
/*  f18b54c:	15c1000b */ 	bne	$t6,$at,.L0f18b57c
/*  f18b550:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f18b554:	00166900 */ 	sll	$t5,$s6,0x4
/*  f18b558:	01b66823 */ 	subu	$t5,$t5,$s6
/*  f18b55c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b560:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b564:	01b89821 */ 	addu	$s3,$t5,$t8
/*  f18b568:	8e79002c */ 	lw	$t9,0x2c($s3)
/*  f18b56c:	3c010001 */ 	lui	$at,0x1
/*  f18b570:	3421c670 */ 	ori	$at,$at,0xc670
/*  f18b574:	03217824 */ 	and	$t7,$t9,$at
/*  f18b578:	ae6f002c */ 	sw	$t7,0x2c($s3)
.L0f18b57c:
/*  f18b57c:	00167100 */ 	sll	$t6,$s6,0x4
/*  f18b580:	01d67023 */ 	subu	$t6,$t6,$s6
/*  f18b584:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b588:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b58c:	01cd9821 */ 	addu	$s3,$t6,$t5
/*  f18b590:	8e70002c */ 	lw	$s0,0x2c($s3)
.L0f18b594:
/*  f18b594:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b598:	00b81004 */ 	sllv	$v0,$t8,$a1
/*  f18b59c:	0202c824 */ 	and	$t9,$s0,$v0
/*  f18b5a0:	1320000f */ 	beqz	$t9,.L0f18b5e0
/*  f18b5a4:	00407827 */ 	nor	$t7,$v0,$zero
/*  f18b5a8:	020f7024 */ 	and	$t6,$s0,$t7
/*  f18b5ac:	3c0f800a */ 	lui	$t7,%hi(g_Vars)
/*  f18b5b0:	00056840 */ 	sll	$t5,$a1,0x1
/*  f18b5b4:	028dc021 */ 	addu	$t8,$s4,$t5
/*  f18b5b8:	25ef9fc0 */ 	addiu	$t7,$t7,%lo(g_Vars)
/*  f18b5bc:	0016c880 */ 	sll	$t9,$s6,0x2
/*  f18b5c0:	ae6e002c */ 	sw	$t6,0x2c($s3)
/*  f18b5c4:	032f8821 */ 	addu	$s1,$t9,$t7
/*  f18b5c8:	97040000 */ 	lhu	$a0,0x0($t8)
/*  f18b5cc:	0fc5b9f1 */ 	jal	langGet
/*  f18b5d0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f18b5d4:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f18b5d8:	adc21974 */ 	sw	$v0,0x1974($t6)
/*  f18b5dc:	8e70002c */ 	lw	$s0,0x2c($s3)
.L0f18b5e0:
/*  f18b5e0:	16000002 */ 	bnez	$s0,.L0f18b5ec
/*  f18b5e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b5e8:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f18b5ec:
/*  f18b5ec:	0c004b70 */ 	jal	random
/*  f18b5f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b5f4:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18b5f8:	00002810 */ 	mfhi	$a1
/*  f18b5fc:	16a00002 */ 	bnez	$s5,.L0f18b608
/*  f18b600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b604:	0007000d */ 	break	0x7
.L0f18b608:
/*  f18b608:	5240ffe2 */ 	beqzl	$s2,.L0f18b594
/*  f18b60c:	8e70002c */ 	lw	$s0,0x2c($s3)
/*  f18b610:	2a410002 */ 	slti	$at,$s2,0x2
/*  f18b614:	10200029 */ 	beqz	$at,.L0f18b6bc
/*  f18b618:	00166900 */ 	sll	$t5,$s6,0x4
/*  f18b61c:	01b66823 */ 	subu	$t5,$t5,$s6
/*  f18b620:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b624:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b628:	01b89821 */ 	addu	$s3,$t5,$t8
.L0f18b62c:
/*  f18b62c:	0c004b70 */ 	jal	random
/*  f18b630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b634:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18b638:	8e70002c */ 	lw	$s0,0x2c($s3)
/*  f18b63c:	00001810 */ 	mfhi	$v1
/*  f18b640:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18b644:	00797804 */ 	sllv	$t7,$t9,$v1
/*  f18b648:	16a00002 */ 	bnez	$s5,.L0f18b654
/*  f18b64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b650:	0007000d */ 	break	0x7
.L0f18b654:
/*  f18b654:	020f7024 */ 	and	$t6,$s0,$t7
/*  f18b658:	11c00012 */ 	beqz	$t6,.L0f18b6a4
/*  f18b65c:	00602825 */ 	or	$a1,$v1,$zero
/*  f18b660:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f18b664:	006dc004 */ 	sllv	$t8,$t5,$v1
/*  f18b668:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f18b66c:	02197824 */ 	and	$t7,$s0,$t9
/*  f18b670:	3c19800a */ 	lui	$t9,%hi(g_Vars)
/*  f18b674:	00037040 */ 	sll	$t6,$v1,0x1
/*  f18b678:	028e6821 */ 	addu	$t5,$s4,$t6
/*  f18b67c:	27399fc0 */ 	addiu	$t9,$t9,%lo(g_Vars)
/*  f18b680:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f18b684:	ae6f002c */ 	sw	$t7,0x2c($s3)
/*  f18b688:	03198821 */ 	addu	$s1,$t8,$t9
/*  f18b68c:	95a40000 */ 	lhu	$a0,0x0($t5)
/*  f18b690:	0fc5b9f1 */ 	jal	langGet
/*  f18b694:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f18b698:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f18b69c:	ade21978 */ 	sw	$v0,0x1978($t7)
/*  f18b6a0:	8e70002c */ 	lw	$s0,0x2c($s3)
.L0f18b6a4:
/*  f18b6a4:	56000003 */ 	bnezl	$s0,.L0f18b6b4
/*  f18b6a8:	2a410002 */ 	slti	$at,$s2,0x2
/*  f18b6ac:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f18b6b0:	2a410002 */ 	slti	$at,$s2,0x2
.L0f18b6b4:
/*  f18b6b4:	1420ffdd */ 	bnez	$at,.L0f18b62c
/*  f18b6b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18b6bc:
/*  f18b6bc:	8fae02fc */ 	lw	$t6,0x2fc($sp)
/*  f18b6c0:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b6c4:	56ceff9f */ 	bnel	$s6,$t6,.L0f18b544
/*  f18b6c8:	8fae02fc */ 	lw	$t6,0x2fc($sp)
.L0f18b6cc:
/*  f18b6cc:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f18b6d0:	29a10002 */ 	slti	$at,$t5,0x2
/*  f18b6d4:	14200072 */ 	bnez	$at,.L0f18b8a0
/*  f18b6d8:	3c0800ff */ 	lui	$t0,0xff
/*  f18b6dc:	3c07800b */ 	lui	$a3,0x800b
/*  f18b6e0:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f18b6e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f18b6e8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f18b6ec:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f18b6f0:	240affff */ 	addiu	$t2,$zero,-1
/*  f18b6f4:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f18b6f8:	94e7cb9e */ 	lhu	$a3,-0x3462($a3)
/*  f18b6fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f18b700:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f18b704:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f18b708:
/*  f18b708:	00b8c804 */ 	sllv	$t9,$t8,$a1
/*  f18b70c:	00f97824 */ 	and	$t7,$a3,$t9
/*  f18b710:	11e00024 */ 	beqz	$t7,.L0f18b7a4
/*  f18b714:	28a10004 */ 	slti	$at,$a1,0x4
/*  f18b718:	10200006 */ 	beqz	$at,.L0f18b734
/*  f18b71c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b720:	00057080 */ 	sll	$t6,$a1,0x2
/*  f18b724:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f18b728:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18b72c:	10000005 */ 	beqz	$zero,.L0f18b744
/*  f18b730:	03ce2021 */ 	addu	$a0,$s8,$t6
.L0f18b734:
/*  f18b734:	00ac0019 */ 	multu	$a1,$t4
/*  f18b738:	00006812 */ 	mflo	$t5
/*  f18b73c:	016d2021 */ 	addu	$a0,$t3,$t5
/*  f18b740:	2484fed0 */ 	addiu	$a0,$a0,-304
.L0f18b744:
/*  f18b744:	00001825 */ 	or	$v1,$zero,$zero
.L0f18b748:
/*  f18b748:	12c30004 */ 	beq	$s6,$v1,.L0f18b75c
/*  f18b74c:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f18b750:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f18b754:	872f0024 */ 	lh	$t7,0x24($t9)
/*  f18b758:	004f1021 */ 	addu	$v0,$v0,$t7
.L0f18b75c:
/*  f18b75c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18b760:	1477fff9 */ 	bne	$v1,$s7,.L0f18b748
/*  f18b764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b768:	14460002 */ 	bne	$v0,$a2,.L0f18b774
/*  f18b76c:	00c2082a */ 	slt	$at,$a2,$v0
/*  f18b770:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f18b774:
/*  f18b774:	50200004 */ 	beqzl	$at,.L0f18b788
/*  f18b778:	8482003c */ 	lh	$v0,0x3c($a0)
/*  f18b77c:	00a04825 */ 	or	$t1,$a1,$zero
/*  f18b780:	00403025 */ 	or	$a2,$v0,$zero
/*  f18b784:	8482003c */ 	lh	$v0,0x3c($a0)
.L0f18b788:
/*  f18b788:	15020002 */ 	bne	$t0,$v0,.L0f18b794
/*  f18b78c:	0048082a */ 	slt	$at,$v0,$t0
/*  f18b790:	240affff */ 	addiu	$t2,$zero,-1
.L0f18b794:
/*  f18b794:	50200004 */ 	beqzl	$at,.L0f18b7a8
/*  f18b798:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f18b79c:	00a05025 */ 	or	$t2,$a1,$zero
/*  f18b7a0:	00404025 */ 	or	$t0,$v0,$zero
.L0f18b7a4:
/*  f18b7a4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f18b7a8:
/*  f18b7a8:	54b7ffd7 */ 	bnel	$a1,$s7,.L0f18b708
/*  f18b7ac:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b7b0:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank0)
/*  f18b7b4:	8dce21d0 */ 	lw	$t6,%lo(g_CheatsActiveBank0)($t6)
/*  f18b7b8:	3c0d800a */ 	lui	$t5,%hi(g_CheatsActiveBank1)
/*  f18b7bc:	15c00038 */ 	bnez	$t6,.L0f18b8a0
/*  f18b7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b7c4:	8dad21d4 */ 	lw	$t5,%lo(g_CheatsActiveBank1)($t5)
/*  f18b7c8:	29210004 */ 	slti	$at,$t1,0x4
/*  f18b7cc:	15a00034 */ 	bnez	$t5,.L0f18b8a0
/*  f18b7d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b7d4:	50200019 */ 	beqzl	$at,.L0f18b83c
/*  f18b7d8:	29410004 */ 	slti	$at,$t2,0x4
/*  f18b7dc:	05200016 */ 	bltz	$t1,.L0f18b838
/*  f18b7e0:	29210004 */ 	slti	$at,$t1,0x4
/*  f18b7e4:	10200006 */ 	beqz	$at,.L0f18b800
/*  f18b7e8:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f18b7ec:	0009c080 */ 	sll	$t8,$t1,0x2
/*  f18b7f0:	0309c021 */ 	addu	$t8,$t8,$t1
/*  f18b7f4:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f18b7f8:	10000009 */ 	beqz	$zero,.L0f18b820
/*  f18b7fc:	03d81021 */ 	addu	$v0,$s8,$t8
.L0f18b800:
/*  f18b800:	0329c821 */ 	addu	$t9,$t9,$t1
/*  f18b804:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18b808:	0329c823 */ 	subu	$t9,$t9,$t1
/*  f18b80c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18b810:	3c0e800b */ 	lui	$t6,%hi(g_MpSimulants)
/*  f18b814:	25cec538 */ 	addiu	$t6,$t6,%lo(g_MpSimulants)
/*  f18b818:	272ffed0 */ 	addiu	$t7,$t9,-304
/*  f18b81c:	01ee1021 */ 	addu	$v0,$t7,$t6
.L0f18b820:
/*  f18b820:	904d0094 */ 	lbu	$t5,0x94($v0)
/*  f18b824:	8c59008c */ 	lw	$t9,0x8c($v0)
/*  f18b828:	35b80001 */ 	ori	$t8,$t5,0x1
/*  f18b82c:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f18b830:	a0580094 */ 	sb	$t8,0x94($v0)
/*  f18b834:	ac4f008c */ 	sw	$t7,0x8c($v0)
.L0f18b838:
/*  f18b838:	29410004 */ 	slti	$at,$t2,0x4
.L0f18b83c:
/*  f18b83c:	10200018 */ 	beqz	$at,.L0f18b8a0
/*  f18b840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b844:	05400016 */ 	bltz	$t2,.L0f18b8a0
/*  f18b848:	29410004 */ 	slti	$at,$t2,0x4
/*  f18b84c:	10200006 */ 	beqz	$at,.L0f18b868
/*  f18b850:	000a6880 */ 	sll	$t5,$t2,0x2
/*  f18b854:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f18b858:	01ca7021 */ 	addu	$t6,$t6,$t2
/*  f18b85c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18b860:	10000009 */ 	beqz	$zero,.L0f18b888
/*  f18b864:	03ce1021 */ 	addu	$v0,$s8,$t6
.L0f18b868:
/*  f18b868:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f18b86c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b870:	01aa6823 */ 	subu	$t5,$t5,$t2
/*  f18b874:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b878:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18b87c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f18b880:	25b8fed0 */ 	addiu	$t8,$t5,-304
/*  f18b884:	03191021 */ 	addu	$v0,$t8,$t9
.L0f18b888:
/*  f18b888:	904f0094 */ 	lbu	$t7,0x94($v0)
/*  f18b88c:	8c4d0090 */ 	lw	$t5,0x90($v0)
/*  f18b890:	35ee0008 */ 	ori	$t6,$t7,0x8
/*  f18b894:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f18b898:	a04e0094 */ 	sb	$t6,0x94($v0)
/*  f18b89c:	ac580090 */ 	sw	$t8,0x90($v0)
.L0f18b8a0:
/*  f18b8a0:	3c0f800a */ 	lui	$t7,%hi(g_CheatsActiveBank0)
/*  f18b8a4:	8def21d0 */ 	lw	$t7,%lo(g_CheatsActiveBank0)($t7)
/*  f18b8a8:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f18b8ac:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18b8b0:	15e00035 */ 	bnez	$t7,.L0f18b988
/*  f18b8b4:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank1)
/*  f18b8b8:	8dce21d4 */ 	lw	$t6,%lo(g_CheatsActiveBank1)($t6)
/*  f18b8bc:	2b210002 */ 	slti	$at,$t9,0x2
/*  f18b8c0:	55c00032 */ 	bnezl	$t6,.L0f18b98c
/*  f18b8c4:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f18b8c8:	1420002f */ 	bnez	$at,.L0f18b988
/*  f18b8cc:	00001825 */ 	or	$v1,$zero,$zero
/*  f18b8d0:	3c013f00 */ 	lui	$at,0x3f00
/*  f18b8d4:	44811000 */ 	mtc1	$at,$f2
/*  f18b8d8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f18b8dc:	1b200016 */ 	blez	$t9,.L0f18b938
/*  f18b8e0:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f18b8e4:	27b301fc */ 	addiu	$s3,$sp,0x1fc
.L0f18b8e8:
/*  f18b8e8:	8e620004 */ 	lw	$v0,0x4($s3)
/*  f18b8ec:	8fad02fc */ 	lw	$t5,0x2fc($sp)
/*  f18b8f0:	14620002 */ 	bne	$v1,$v0,.L0f18b8fc
/*  f18b8f4:	0062082a */ 	slt	$at,$v1,$v0
/*  f18b8f8:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f18b8fc:
/*  f18b8fc:	50200004 */ 	beqzl	$at,.L0f18b910
/*  f18b900:	c6600038 */ 	lwc1	$f0,0x38($s3)
/*  f18b904:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18b908:	00401825 */ 	or	$v1,$v0,$zero
/*  f18b90c:	c6600038 */ 	lwc1	$f0,0x38($s3)
.L0f18b910:
/*  f18b910:	4600103c */ 	c.lt.s	$f2,$f0
/*  f18b914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b918:	45020004 */ 	bc1fl	.L0f18b92c
/*  f18b91c:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b920:	02c08025 */ 	or	$s0,$s6,$zero
/*  f18b924:	46000086 */ 	mov.s	$f2,$f0
/*  f18b928:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f18b92c:
/*  f18b92c:	16cdffee */ 	bne	$s6,$t5,.L0f18b8e8
/*  f18b930:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f18b934:	0000b025 */ 	or	$s6,$zero,$zero
.L0f18b938:
/*  f18b938:	04800009 */ 	bltz	$a0,.L0f18b960
/*  f18b93c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b940:	0fc631e5 */ 	jal	func0f18c794
/*  f18b944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b948:	90580094 */ 	lbu	$t8,0x94($v0)
/*  f18b94c:	8c4e0088 */ 	lw	$t6,0x88($v0)
/*  f18b950:	370f0002 */ 	ori	$t7,$t8,0x2
/*  f18b954:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f18b958:	a04f0094 */ 	sb	$t7,0x94($v0)
/*  f18b95c:	ac590088 */ 	sw	$t9,0x88($v0)
.L0f18b960:
/*  f18b960:	0602000a */ 	bltzl	$s0,.L0f18b98c
/*  f18b964:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f18b968:	0fc631e5 */ 	jal	func0f18c794
/*  f18b96c:	02002025 */ 	or	$a0,$s0,$zero
/*  f18b970:	904d0094 */ 	lbu	$t5,0x94($v0)
/*  f18b974:	8c4f0084 */ 	lw	$t7,0x84($v0)
/*  f18b978:	35b80004 */ 	ori	$t8,$t5,0x4
/*  f18b97c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18b980:	a0580094 */ 	sb	$t8,0x94($v0)
/*  f18b984:	ac4e0084 */ 	sw	$t6,0x84($v0)
.L0f18b988:
/*  f18b988:	8fa802fc */ 	lw	$t0,0x2fc($sp)
.L0f18b98c:
/*  f18b98c:	5900000a */ 	blezl	$t0,.L0f18b9b8
/*  f18b990:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f18b994:
/*  f18b994:	0fc631e5 */ 	jal	func0f18c794
/*  f18b998:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18b99c:	0fc62864 */ 	jal	func0f18a190
/*  f18b9a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18b9a4:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f18b9a8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b9ac:	16d9fff9 */ 	bne	$s6,$t9,.L0f18b994
/*  f18b9b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b9b4:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f18b9b8:
/*  f18b9b8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f18b9bc:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f18b9c0:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f18b9c4:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f18b9c8:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f18b9cc:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f18b9d0:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f18b9d4:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f18b9d8:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f18b9dc:	03e00008 */ 	jr	$ra
/*  f18b9e0:	27bd0300 */ 	addiu	$sp,$sp,0x300
);

GLOBAL_ASM(
glabel func0f18b9e4
/*  f18b9e4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18b9e8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18b9ec:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f18b9f0:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f18b9f4:	8e2e006c */ 	lw	$t6,0x6c($s1)
/*  f18b9f8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18b9fc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18ba00:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18ba04:	11c00003 */ 	beqz	$t6,.L0f18ba14
/*  f18ba08:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18ba0c:	10000002 */ 	beqz	$zero,.L0f18ba18
/*  f18ba10:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18ba14:
/*  f18ba14:	00002825 */ 	or	$a1,$zero,$zero
.L0f18ba18:
/*  f18ba18:	8e2f0068 */ 	lw	$t7,0x68($s1)
/*  f18ba1c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ba20:	11e00003 */ 	beqz	$t7,.L0f18ba30
/*  f18ba24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ba28:	10000001 */ 	beqz	$zero,.L0f18ba30
/*  f18ba2c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f18ba30:
/*  f18ba30:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f18ba34:	00002025 */ 	or	$a0,$zero,$zero
/*  f18ba38:	13000003 */ 	beqz	$t8,.L0f18ba48
/*  f18ba3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ba40:	10000001 */ 	beqz	$zero,.L0f18ba48
/*  f18ba44:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18ba48:
/*  f18ba48:	8e390070 */ 	lw	$t9,0x70($s1)
/*  f18ba4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18ba50:	13200003 */ 	beqz	$t9,.L0f18ba60
/*  f18ba54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ba58:	10000001 */ 	beqz	$zero,.L0f18ba60
/*  f18ba5c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18ba60:
/*  f18ba60:	00444021 */ 	addu	$t0,$v0,$a0
/*  f18ba64:	01034821 */ 	addu	$t1,$t0,$v1
/*  f18ba68:	01259021 */ 	addu	$s2,$t1,$a1
/*  f18ba6c:	0fc5b6c5 */ 	jal	func0f16db14
/*  f18ba70:	02409825 */ 	or	$s3,$s2,$zero
/*  f18ba74:	0fc625cb */ 	jal	mpSetPaused
/*  f18ba78:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f18ba7c:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f18ba80:	00008025 */ 	or	$s0,$zero,$zero
/*  f18ba84:	1a400010 */ 	blez	$s2,.L0f18bac8
/*  f18ba88:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f18ba8c:	24120002 */ 	addiu	$s2,$zero,0x2
.L0f18ba90:
/*  f18ba90:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18ba94:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ba98:	8e2b0284 */ 	lw	$t3,0x284($s1)
/*  f18ba9c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18baa0:	ad601974 */ 	sw	$zero,0x1974($t3)
/*  f18baa4:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f18baa8:	ad801978 */ 	sw	$zero,0x1978($t4)
/*  f18baac:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f18bab0:	944d0010 */ 	lhu	$t5,0x10($v0)
/*  f18bab4:	164d0002 */ 	bne	$s2,$t5,.L0f18bac0
/*  f18bab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18babc:	a4400010 */ 	sh	$zero,0x10($v0)
.L0f18bac0:
/*  f18bac0:	1613fff3 */ 	bne	$s0,$s3,.L0f18ba90
/*  f18bac4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18bac8:
/*  f18bac8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18bacc:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f18bad0:	0fc6295b */ 	jal	func0f18a56c
/*  f18bad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bad8:	3c0e800b */ 	lui	$t6,0x800b
/*  f18badc:	91cecc10 */ 	lbu	$t6,-0x33f0($t6)
/*  f18bae0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18bae4:	55c10004 */ 	bnel	$t6,$at,.L0f18baf8
/*  f18bae8:	00002025 */ 	or	$a0,$zero,$zero
/*  f18baec:	0fc671af */ 	jal	mpConsiderMarkingCurrentChallengeComplete
/*  f18baf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18baf4:	00002025 */ 	or	$a0,$zero,$zero
.L0f18baf8:
/*  f18baf8:	0fc3e083 */ 	jal	func0f0f820c
/*  f18bafc:	2405fffa */ 	addiu	$a1,$zero,-6
/*  f18bb00:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18bb04:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18bb08:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18bb0c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18bb10:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18bb14:	03e00008 */ 	jr	$ra
/*  f18bb18:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

u32 func0f18bb1c(void)
{
	return NUM_MPHEADS;
}

s32 mpGetNumHeads(void)
{
	return NUM_MPHEADS;
}

s32 mpGetHeadId(u8 headnum)
{
	return g_MpHeads[headnum].headid;
}

s32 mpGetHeadUnlockValue(u8 headnum)
{
	return g_MpHeads[headnum].unlockvalue;
}

s32 mpGetBeauHeadId(u8 headnum)
{
	return g_MpBeauHeads[headnum].headid;
}

s32 mpGetNumBeauHeads(void)
{
	return NUM_MPBEAUHEADS;
}

u32 mpGetNumBodies(void)
{
	return NUM_MPBODIES;
}

s32 mpGetBodyId(u8 bodynum)
{
	if (bodynum >= 62) {
		if (bodynum == 62) {
			return BODY_DRCAROLL;
		}

		return BODY_DARK_COMBAT;
	}

	return g_MpBodies[bodynum].bodyid;
}

s32 mpGetBodyIndexByBodyId(u16 bodyid)
{
	s32 i;

	if (bodyid == BODY_DRCAROLL) {
		return 62; // NUM_MPBODIES + 1
	}

	for (i = 0; i != NUM_MPBODIES; i++) {
		if (g_MpBodies[i].bodyid == bodyid) {
			return i;
		}
	}

	// @bug: Should return 0 as a fallback, not the first body's bodyid
	return g_MpBodies[0].bodyid;
}

char *mpGetBodyName(u8 bodynum)
{
	// Possible @bug: This should probably be >=
	if (bodynum > NUM_MPBODIES) {
		bodynum = 0;
	}

	return langGet(g_MpBodies[bodynum].name);
}

u8 mpGetBodyUnk06(u8 bodynum)
{
	// Possible @bug: This should probably be >=
	if (bodynum > NUM_MPBODIES) {
		bodynum = 0;
	}

	return g_MpBodies[bodynum].unk06;
}

GLOBAL_ASM(
glabel func0f18bc9c
/*  f18bc9c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f18bca0:	2881003e */ 	slti	$at,$a0,0x3e
/*  f18bca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18bca8:	14200002 */ 	bnez	$at,.L0f18bcb4
/*  f18bcac:	00003025 */ 	or	$a2,$zero,$zero
/*  f18bcb0:	00002025 */ 	or	$a0,$zero,$zero
.L0f18bcb4:
/*  f18bcb4:	3c0f8008 */ 	lui	$t7,%hi(g_MpBodies)
/*  f18bcb8:	25ef77bc */ 	addiu	$t7,$t7,%lo(g_MpBodies)
/*  f18bcbc:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f18bcc0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f18bcc4:	84450004 */ 	lh	$a1,0x4($v0)
/*  f18bcc8:	240103e8 */ 	addiu	$at,$zero,0x3e8
/*  f18bccc:	14a10020 */ 	bne	$a1,$at,.L0f18bd50
/*  f18bcd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bcd4:	84580000 */ 	lh	$t8,0x0($v0)
/*  f18bcd8:	3c088008 */ 	lui	$t0,%hi(g_Bodies)
/*  f18bcdc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18bce0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f18bce4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18bce8:	01194021 */ 	addu	$t0,$t0,$t9
/*  f18bcec:	8d08cf04 */ 	lw	$t0,%lo(g_Bodies)($t0)
/*  f18bcf0:	00084fc2 */ 	srl	$t1,$t0,0x1f
/*  f18bcf4:	1120000c */ 	beqz	$t1,.L0f18bd28
/*  f18bcf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bcfc:	0c004b70 */ 	jal	random
/*  f18bd00:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f18bd04:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f18bd08:	0041001b */ 	divu	$zero,$v0,$at
/*  f18bd0c:	00005010 */ 	mfhi	$t2
/*  f18bd10:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f18bd14:	3c058008 */ 	lui	$a1,%hi(var800879a4)
/*  f18bd18:	00ab2821 */ 	addu	$a1,$a1,$t3
/*  f18bd1c:	8ca579a4 */ 	lw	$a1,%lo(var800879a4)($a1)
/*  f18bd20:	1000000b */ 	beqz	$zero,.L0f18bd50
/*  f18bd24:	8fa60018 */ 	lw	$a2,0x18($sp)
.L0f18bd28:
/*  f18bd28:	0c004b70 */ 	jal	random
/*  f18bd2c:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f18bd30:	24010007 */ 	addiu	$at,$zero,0x7
/*  f18bd34:	0041001b */ 	divu	$zero,$v0,$at
/*  f18bd38:	00006010 */ 	mfhi	$t4
/*  f18bd3c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f18bd40:	3c058008 */ 	lui	$a1,%hi(var80087a54)
/*  f18bd44:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f18bd48:	8ca57a54 */ 	lw	$a1,%lo(var80087a54)($a1)
/*  f18bd4c:	8fa60018 */ 	lw	$a2,0x18($sp)
.L0f18bd50:
/*  f18bd50:	3c038008 */ 	lui	$v1,%hi(g_MpHeads)
/*  f18bd54:	2463752c */ 	addiu	$v1,$v1,%lo(g_MpHeads)
/*  f18bd58:	00001025 */ 	or	$v0,$zero,$zero
/*  f18bd5c:	2404004b */ 	addiu	$a0,$zero,0x4b
.L0f18bd60:
/*  f18bd60:	846e0000 */ 	lh	$t6,0x0($v1)
/*  f18bd64:	54ae0003 */ 	bnel	$a1,$t6,.L0f18bd74
/*  f18bd68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18bd6c:	00403025 */ 	or	$a2,$v0,$zero
/*  f18bd70:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f18bd74:
/*  f18bd74:	1444fffa */ 	bne	$v0,$a0,.L0f18bd60
/*  f18bd78:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f18bd7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18bd80:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f18bd84:	00c01025 */ 	or	$v0,$a2,$zero
/*  f18bd88:	03e00008 */ 	jr	$ra
/*  f18bd8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bd90:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18bd94:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f18bd98:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18bd9c:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f18bda0:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f18bda4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f18bda8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18bdac:	3c12800b */ 	lui	$s2,%hi(g_MpPlayers)
/*  f18bdb0:	3c15800b */ 	lui	$s5,%hi(g_MpSimulants)
/*  f18bdb4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18bdb8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18bdbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18bdc0:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f18bdc4:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f18bdc8:	26b5c538 */ 	addiu	$s5,$s5,%lo(g_MpSimulants)
/*  f18bdcc:	2652c7b8 */ 	addiu	$s2,$s2,%lo(g_MpPlayers)
/*  f18bdd0:	241300a0 */ 	addiu	$s3,$zero,0xa0
/*  f18bdd4:	2414000c */ 	addiu	$s4,$zero,0xc
/*  f18bdd8:	2416004c */ 	addiu	$s6,$zero,0x4c
/*  f18bddc:	2417004b */ 	addiu	$s7,$zero,0x4b
.L0f18bde0:
/*  f18bde0:	0c004b70 */ 	jal	random
/*  f18bde4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18bde8:	0057001b */ 	divu	$zero,$v0,$s7
/*  f18bdec:	00008810 */ 	mfhi	$s1
/*  f18bdf0:	322e00ff */ 	andi	$t6,$s1,0xff
/*  f18bdf4:	16e00002 */ 	bnez	$s7,.L0f18be00
/*  f18bdf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bdfc:	0007000d */ 	break	0x7
.L0f18be00:
/*  f18be00:	01c08825 */ 	or	$s1,$t6,$zero
/*  f18be04:	0c004b70 */ 	jal	random
/*  f18be08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18be0c:	3c07800b */ 	lui	$a3,0x800b
/*  f18be10:	94e7cb9e */ 	lhu	$a3,-0x3462($a3)
/*  f18be14:	00002025 */ 	or	$a0,$zero,$zero
/*  f18be18:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0f18be1c:
/*  f18be1c:	008fc004 */ 	sllv	$t8,$t7,$a0
/*  f18be20:	00f8c824 */ 	and	$t9,$a3,$t8
/*  f18be24:	13200019 */ 	beqz	$t9,.L0f18be8c
/*  f18be28:	02202825 */ 	or	$a1,$s1,$zero
/*  f18be2c:	2401003d */ 	addiu	$at,$zero,0x3d
/*  f18be30:	0041001b */ 	divu	$zero,$v0,$at
/*  f18be34:	00003010 */ 	mfhi	$a2
/*  f18be38:	30c800ff */ 	andi	$t0,$a2,0xff
/*  f18be3c:	28810004 */ 	slti	$at,$a0,0x4
/*  f18be40:	10200006 */ 	beqz	$at,.L0f18be5c
/*  f18be44:	01003025 */ 	or	$a2,$t0,$zero
/*  f18be48:	00930019 */ 	multu	$a0,$s3
/*  f18be4c:	00004812 */ 	mflo	$t1
/*  f18be50:	02491821 */ 	addu	$v1,$s2,$t1
/*  f18be54:	10000006 */ 	beqz	$zero,.L0f18be70
/*  f18be58:	906b000f */ 	lbu	$t3,0xf($v1)
.L0f18be5c:
/*  f18be5c:	00960019 */ 	multu	$a0,$s6
/*  f18be60:	00005012 */ 	mflo	$t2
/*  f18be64:	02aa1821 */ 	addu	$v1,$s5,$t2
/*  f18be68:	2463fed0 */ 	addiu	$v1,$v1,-304
/*  f18be6c:	906b000f */ 	lbu	$t3,0xf($v1)
.L0f18be70:
/*  f18be70:	54ab0003 */ 	bnel	$a1,$t3,.L0f18be80
/*  f18be74:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f18be78:	00008025 */ 	or	$s0,$zero,$zero
/*  f18be7c:	906c0010 */ 	lbu	$t4,0x10($v1)
.L0f18be80:
/*  f18be80:	54cc0003 */ 	bnel	$a2,$t4,.L0f18be90
/*  f18be84:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18be88:	00008025 */ 	or	$s0,$zero,$zero
.L0f18be8c:
/*  f18be8c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f18be90:
/*  f18be90:	5494ffe2 */ 	bnel	$a0,$s4,.L0f18be1c
/*  f18be94:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18be98:	1200ffd1 */ 	beqz	$s0,.L0f18bde0
/*  f18be9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bea0:	2401003d */ 	addiu	$at,$zero,0x3d
/*  f18bea4:	0041001b */ 	divu	$zero,$v0,$at
/*  f18bea8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f18beac:	00006810 */ 	mfhi	$t5
/*  f18beb0:	a1d10000 */ 	sb	$s1,0x0($t6)
/*  f18beb4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18beb8:	a1ed0000 */ 	sb	$t5,0x0($t7)
/*  f18bebc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18bec0:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f18bec4:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f18bec8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f18becc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f18bed0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18bed4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18bed8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18bedc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18bee0:	03e00008 */ 	jr	$ra
/*  f18bee4:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f18bee8
/*  f18bee8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18beec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18bef0:	0c004b70 */ 	jal	random
/*  f18bef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bef8:	30440003 */ 	andi	$a0,$v0,0x3
/*  f18befc:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f18bf00:	04610004 */ 	bgez	$v1,.L0f18bf14
/*  f18bf04:	306e0003 */ 	andi	$t6,$v1,0x3
/*  f18bf08:	11c00002 */ 	beqz	$t6,.L0f18bf14
/*  f18bf0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bf10:	25cefffc */ 	addiu	$t6,$t6,-4
.L0f18bf14:
/*  f18bf14:	3c05800b */ 	lui	$a1,0x800b
/*  f18bf18:	94a5cb9e */ 	lhu	$a1,-0x3462($a1)
/*  f18bf1c:	01c01825 */ 	or	$v1,$t6,$zero
/*  f18bf20:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18bf24:	006fc004 */ 	sllv	$t8,$t7,$v1
/*  f18bf28:	00b8c824 */ 	and	$t9,$a1,$t8
/*  f18bf2c:	1720000d */ 	bnez	$t9,.L0f18bf64
/*  f18bf30:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18bf34:
/*  f18bf34:	1064000b */ 	beq	$v1,$a0,.L0f18bf64
/*  f18bf38:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18bf3c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18bf40:	04610004 */ 	bgez	$v1,.L0f18bf54
/*  f18bf44:	30680003 */ 	andi	$t0,$v1,0x3
/*  f18bf48:	11000002 */ 	beqz	$t0,.L0f18bf54
/*  f18bf4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bf50:	2508fffc */ 	addiu	$t0,$t0,-4
.L0f18bf54:
/*  f18bf54:	010fc004 */ 	sllv	$t8,$t7,$t0
/*  f18bf58:	00b8c824 */ 	and	$t9,$a1,$t8
/*  f18bf5c:	1320fff5 */ 	beqz	$t9,.L0f18bf34
/*  f18bf60:	01001825 */ 	or	$v1,$t0,$zero
.L0f18bf64:
/*  f18bf64:	00601025 */ 	or	$v0,$v1,$zero
/*  f18bf68:	03e00008 */ 	jr	$ra
/*  f18bf6c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel mpSetLock
/*  f18bf70:	3c02800b */ 	lui	$v0,0x800b
/*  f18bf74:	2442cbb0 */ 	addiu	$v0,$v0,-13392
/*  f18bf78:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18bf7c:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f18bf80:	24010003 */ 	addiu	$at,$zero,0x3
/*  f18bf84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18bf88:	15c10006 */ 	bne	$t6,$at,.L0f18bfa4
/*  f18bf8c:	a0440060 */ 	sb	$a0,0x60($v0)
/*  f18bf90:	0fc62fba */ 	jal	func0f18bee8
/*  f18bf94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bf98:	3c01800b */ 	lui	$at,0x800b
/*  f18bf9c:	10000003 */ 	beqz	$zero,.L0f18bfac
/*  f18bfa0:	a022cc20 */ 	sb	$v0,-0x33e0($at)
.L0f18bfa4:
/*  f18bfa4:	3c01800b */ 	lui	$at,0x800b
/*  f18bfa8:	a025cc20 */ 	sb	$a1,-0x33e0($at)
.L0f18bfac:
/*  f18bfac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18bfb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18bfb4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18bfb8:	03e00008 */ 	jr	$ra
/*  f18bfbc:	00000000 */ 	sll	$zero,$zero,0x0
);

u32 mpGetLockType(void)
{
	return g_MpSetup.locktype;
}

u32 mpGetLockPlayerNum(void)
{
	return g_MpLockPlayerNum;
}

bool mpIsPlayerLockedOut(u32 playernum)
{
	if (g_MpSetup.locktype == MPLOCKTYPE_NONE) {
		return false;
	}

	if (g_MpLockPlayerNum == playernum) {
		return false;
	}

	return true;
}

GLOBAL_ASM(
glabel func0f18c014
/*  f18c014:	3c04800b */ 	lui	$a0,0x800b
/*  f18c018:	9084cc10 */ 	lbu	$a0,-0x33f0($a0)
/*  f18c01c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c020:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18c024:	14810007 */ 	bne	$a0,$at,.L0f18c044
/*  f18c028:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c02c:	3c03800b */ 	lui	$v1,%hi(g_MpLockPlayerNum)
/*  f18c030:	2463cc20 */ 	addiu	$v1,$v1,%lo(g_MpLockPlayerNum)
/*  f18c034:	80620001 */ 	lb	$v0,0x1($v1)
/*  f18c038:	04400002 */ 	bltz	$v0,.L0f18c044
/*  f18c03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c040:	a0620000 */ 	sb	$v0,0x0($v1)
.L0f18c044:
/*  f18c044:	3c03800b */ 	lui	$v1,%hi(g_MpLockPlayerNum)
/*  f18c048:	24010002 */ 	addiu	$at,$zero,0x2
/*  f18c04c:	14810005 */ 	bne	$a0,$at,.L0f18c064
/*  f18c050:	2463cc20 */ 	addiu	$v1,$v1,%lo(g_MpLockPlayerNum)
/*  f18c054:	80620002 */ 	lb	$v0,0x2($v1)
/*  f18c058:	04420003 */ 	bltzl	$v0,.L0f18c068
/*  f18c05c:	80620000 */ 	lb	$v0,0x0($v1)
/*  f18c060:	a0620000 */ 	sb	$v0,0x0($v1)
.L0f18c064:
/*  f18c064:	80620000 */ 	lb	$v0,0x0($v1)
.L0f18c068:
/*  f18c068:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18c06c:	04420011 */ 	bltzl	$v0,.L0f18c0b4
/*  f18c070:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c074:	1081000e */ 	beq	$a0,$at,.L0f18c0b0
/*  f18c078:	3c0e800b */ 	lui	$t6,0x800b
/*  f18c07c:	95cecb9e */ 	lhu	$t6,-0x3462($t6)
/*  f18c080:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18c084:	004fc004 */ 	sllv	$t8,$t7,$v0
/*  f18c088:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f18c08c:	17200008 */ 	bnez	$t9,.L0f18c0b0
/*  f18c090:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f18c094:	a0680002 */ 	sb	$t0,0x2($v1)
/*  f18c098:	80690002 */ 	lb	$t1,0x2($v1)
/*  f18c09c:	0fc62fba */ 	jal	func0f18bee8
/*  f18c0a0:	a0690001 */ 	sb	$t1,0x1($v1)
/*  f18c0a4:	3c03800b */ 	lui	$v1,%hi(g_MpLockPlayerNum)
/*  f18c0a8:	2463cc20 */ 	addiu	$v1,$v1,%lo(g_MpLockPlayerNum)
/*  f18c0ac:	a0620000 */ 	sb	$v0,0x0($v1)
.L0f18c0b0:
/*  f18c0b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18c0b4:
/*  f18c0b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c0b8:	03e00008 */ 	jr	$ra
/*  f18c0bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel mpIsTrackUnlocked
/*  f18c0c0:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18c0c4:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f18c0c8:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18c0cc:	3c028008 */ 	lui	$v0,0x8008
/*  f18c0d0:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f18c0d4:	84427a74 */ 	lh	$v0,0x7a74($v0)
/*  f18c0d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c0dc:	04400003 */ 	bltz	$v0,.L0f18c0ec
/*  f18c0e0:	28410011 */ 	slti	$at,$v0,0x11
/*  f18c0e4:	14200003 */ 	bnez	$at,.L0f18c0f4
/*  f18c0e8:	00002825 */ 	or	$a1,$zero,$zero
.L0f18c0ec:
/*  f18c0ec:	03e00008 */ 	jr	$ra
/*  f18c0f0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18c0f4:
/*  f18c0f4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c0f8:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c0fc:	3c18800a */ 	lui	$t8,%hi(g_SoloSaveFile)
/*  f18c100:	27182200 */ 	addiu	$t8,$t8,%lo(g_SoloSaveFile)
/*  f18c104:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c108:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f18c10c:	24020006 */ 	addiu	$v0,$zero,0x6
.L0f18c110:
/*  f18c110:	94d90020 */ 	lhu	$t9,0x20($a2)
/*  f18c114:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f18c118:	13200003 */ 	beqz	$t9,.L0f18c128
/*  f18c11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c120:	03e00008 */ 	jr	$ra
/*  f18c124:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18c128:
/*  f18c128:	14a2fff9 */ 	bne	$a1,$v0,.L0f18c110
/*  f18c12c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f18c130:	03e00008 */ 	jr	$ra
/*  f18c134:	00601025 */ 	or	$v0,$v1,$zero
);

// Mismatch because the compiler optimises out the unlocked variable
//bool mpIsTrackUnlocked(s32 tracknum)
//{
//	s16 stageindex = g_MpTracks[tracknum].unlockstage;
//	bool unlocked = false;
//	u32 i;
//
//	if (stageindex < 0 || stageindex >= NUM_SOLONORMALSTAGES) {
//		return true;
//	}
//
//	for (i = 0; i != 3; i++) {
//		if (g_SoloSaveFile.besttimes[stageindex][i]) {
//			return true;
//		}
//	}
//
//	return unlocked;
//}

s32 mpGetTrackSlotIndex(s32 tracknum)
{
	s32 i;
	s32 slotindex = 0;

	for (i = 0; i < tracknum; i++) {
		if (mpIsTrackUnlocked(i)) {
			slotindex++;
		}
	}

	return slotindex;
}

s32 mpGetTrackNumAtSlotIndex(s32 slotindex)
{
	s32 i;
	s32 numunlocked = 0;

	for (i = 0; i != NUM_MPTRACKS; i++) {
		if (mpIsTrackUnlocked(i)) {
			if (numunlocked == slotindex) {
				break;
			}

			numunlocked++;
		}
	}

	return i;
}

s32 func0f18c200(void)
{
	return mpGetTrackSlotIndex(NUM_MPTRACKS);
}

s32 mpGetTrackAudioId(s32 slotindex)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slotindex);

	return g_MpTracks[tracknum].audioid;
}

char *mpGetTrackName(s32 slotindex)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slotindex);

	return langGet(g_MpTracks[tracknum].name);
}

void mpSetUsingMultipleTunes(bool enable)
{
	g_MpSetup.usingmultipletunes = enable;
}

bool mpGetUsingMultipleTunes(void)
{
	return g_MpSetup.usingmultipletunes;
}

GLOBAL_ASM(
glabel func0f18c2b0
/*  f18c2b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c2b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c2b8:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c2c0:	000270c3 */ 	sra	$t6,$v0,0x3
/*  f18c2c4:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f18c2c8:	3c18800b */ 	lui	$t8,0x800b
/*  f18c2cc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f18c2d0:	9318cc15 */ 	lbu	$t8,-0x33eb($t8)
/*  f18c2d4:	30590007 */ 	andi	$t9,$v0,0x7
/*  f18c2d8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18c2dc:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f18c2e0:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f18c2e4:	030a5824 */ 	and	$t3,$t8,$t2
/*  f18c2e8:	15600003 */ 	bnez	$t3,.L0f18c2f8
/*  f18c2ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c2f0:	10000002 */ 	beqz	$zero,.L0f18c2fc
/*  f18c2f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f18c2f8:
/*  f18c2f8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18c2fc:
/*  f18c2fc:	03e00008 */ 	jr	$ra
/*  f18c300:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f18c304
/*  f18c304:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c308:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c30c:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c310:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f18c314:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f18c318:	3c18800b */ 	lui	$t8,0x800b
/*  f18c31c:	2718cbb0 */ 	addiu	$t8,$t8,-13392
/*  f18c320:	11c0000d */ 	beqz	$t6,.L0f18c358
/*  f18c324:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f18c328:	000278c3 */ 	sra	$t7,$v0,0x3
/*  f18c32c:	3c19800b */ 	lui	$t9,0x800b
/*  f18c330:	2739cbb0 */ 	addiu	$t9,$t9,-13392
/*  f18c334:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f18c338:	03191821 */ 	addu	$v1,$t8,$t9
/*  f18c33c:	90680065 */ 	lbu	$t0,0x65($v1)
/*  f18c340:	30490007 */ 	andi	$t1,$v0,0x7
/*  f18c344:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f18c348:	012a6004 */ 	sllv	$t4,$t2,$t1
/*  f18c34c:	010c6825 */ 	or	$t5,$t0,$t4
/*  f18c350:	1000000a */ 	beqz	$zero,.L0f18c37c
/*  f18c354:	a06d0065 */ 	sb	$t5,0x65($v1)
.L0f18c358:
/*  f18c358:	000270c3 */ 	sra	$t6,$v0,0x3
/*  f18c35c:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f18c360:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f18c364:	90790065 */ 	lbu	$t9,0x65($v1)
/*  f18c368:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f18c36c:	01494004 */ 	sllv	$t0,$t1,$t2
/*  f18c370:	01006027 */ 	nor	$t4,$t0,$zero
/*  f18c374:	032c6824 */ 	and	$t5,$t9,$t4
/*  f18c378:	a06d0065 */ 	sb	$t5,0x65($v1)
.L0f18c37c:
/*  f18c37c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c380:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c384:	03e00008 */ 	jr	$ra
/*  f18c388:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18c38c
/*  f18c38c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c390:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c394:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f18c398:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f18c39c:	10400009 */ 	beqz	$v0,.L0f18c3c4
/*  f18c3a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c3a4:	0fc630ac */ 	jal	func0f18c2b0
/*  f18c3a8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f18c3ac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c3b0:	01c22823 */ 	subu	$a1,$t6,$v0
/*  f18c3b4:	0fc630c1 */ 	jal	func0f18c304
/*  f18c3b8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f18c3bc:	10000006 */ 	beqz	$zero,.L0f18c3d8
/*  f18c3c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18c3c4:
/*  f18c3c4:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c3c8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f18c3cc:	3c01800b */ 	lui	$at,0x800b
/*  f18c3d0:	a022cc14 */ 	sb	$v0,-0x33ec($at)
/*  f18c3d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18c3d8:
/*  f18c3d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c3dc:	03e00008 */ 	jr	$ra
/*  f18c3e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18c3e4
/*  f18c3e4:	3c03800b */ 	lui	$v1,0x800b
/*  f18c3e8:	3c04800b */ 	lui	$a0,0x800b
/*  f18c3ec:	2484cbb6 */ 	addiu	$a0,$a0,-13386
/*  f18c3f0:	2463cbb0 */ 	addiu	$v1,$v1,-13392
/*  f18c3f4:	240200ff */ 	addiu	$v0,$zero,0xff
.L0f18c3f8:
/*  f18c3f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18c3fc:	1464fffe */ 	bne	$v1,$a0,.L0f18c3f8
/*  f18c400:	a0620064 */ 	sb	$v0,0x64($v1)
/*  f18c404:	03e00008 */ 	jr	$ra
/*  f18c408:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18c40c
/*  f18c40c:	3c03800b */ 	lui	$v1,0x800b
/*  f18c410:	3c02800b */ 	lui	$v0,0x800b
/*  f18c414:	2442cbb6 */ 	addiu	$v0,$v0,-13386
/*  f18c418:	2463cbb0 */ 	addiu	$v1,$v1,-13392
.L0f18c41c:
/*  f18c41c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18c420:	1462fffe */ 	bne	$v1,$v0,.L0f18c41c
/*  f18c424:	a0600064 */ 	sb	$zero,0x64($v1)
/*  f18c428:	03e00008 */ 	jr	$ra
/*  f18c42c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18c430
/*  f18c430:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f18c434:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18c438:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18c43c:	3c10800b */ 	lui	$s0,0x800b
/*  f18c440:	3c11800b */ 	lui	$s1,0x800b
/*  f18c444:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18c448:	2631cbb6 */ 	addiu	$s1,$s1,-13386
/*  f18c44c:	2610cbb0 */ 	addiu	$s0,$s0,-13392
.L0f18c450:
/*  f18c450:	0c004b70 */ 	jal	random
/*  f18c454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c458:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c45c:	1611fffc */ 	bne	$s0,$s1,.L0f18c450
/*  f18c460:	a2020064 */ 	sb	$v0,0x64($s0)
/*  f18c464:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18c468:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18c46c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18c470:	03e00008 */ 	jr	$ra
/*  f18c474:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f18c478
/*  f18c478:	240effff */ 	addiu	$t6,$zero,-1
/*  f18c47c:	3c01800b */ 	lui	$at,0x800b
/*  f18c480:	03e00008 */ 	jr	$ra
/*  f18c484:	a02ecc14 */ 	sb	$t6,-0x33ec($at)
);

GLOBAL_ASM(
glabel func0f18c488
/*  f18c488:	3c04800b */ 	lui	$a0,%hi(var800acc14)
/*  f18c48c:	8084cc14 */ 	lb	$a0,%lo(var800acc14)($a0)
/*  f18c490:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c494:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c498:	04810003 */ 	bgez	$a0,.L0f18c4a8
/*  f18c49c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c4a0:	10000003 */ 	beqz	$zero,.L0f18c4b0
/*  f18c4a4:	00801025 */ 	or	$v0,$a0,$zero
.L0f18c4a8:
/*  f18c4a8:	0fc6304e */ 	jal	mpGetTrackSlotIndex
/*  f18c4ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18c4b0:
/*  f18c4b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c4b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c4b8:	03e00008 */ 	jr	$ra
/*  f18c4bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18c4c0
/*  f18c4c0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18c4c4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18c4c8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18c4cc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18c4d0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18c4d4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18c4d8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18c4dc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18c4e0:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f18c4e4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18c4e8:	10400069 */ 	beqz	$v0,.L0f18c690
/*  f18c4ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c4f0:	0fc63080 */ 	jal	func0f18c200
/*  f18c4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c4f8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f18c4fc:	0000a825 */ 	or	$s5,$zero,$zero
/*  f18c500:	18400009 */ 	blez	$v0,.L0f18c528
/*  f18c504:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c508:
/*  f18c508:	0fc630ac */ 	jal	func0f18c2b0
/*  f18c50c:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c510:	10400002 */ 	beqz	$v0,.L0f18c51c
/*  f18c514:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c518:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f18c51c:
/*  f18c51c:	0214082a */ 	slt	$at,$s0,$s4
/*  f18c520:	1420fff9 */ 	bnez	$at,.L0f18c508
/*  f18c524:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18c528:
/*  f18c528:	16a0001e */ 	bnez	$s5,.L0f18c5a4
/*  f18c52c:	3c16800b */ 	lui	$s6,%hi(g_MpLockPlayerNum)
/*  f18c530:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockPlayerNum)
.L0f18c534:
/*  f18c534:	0c004b70 */ 	jal	random
/*  f18c538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c53c:	0054001b */ 	divu	$zero,$v0,$s4
/*  f18c540:	00002010 */ 	mfhi	$a0
/*  f18c544:	16800002 */ 	bnez	$s4,.L0f18c550
/*  f18c548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c54c:	0007000d */ 	break	0x7
.L0f18c550:
/*  f18c550:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c558:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18c55c:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c560:	104efff4 */ 	beq	$v0,$t6,.L0f18c534
/*  f18c564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c568:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c56c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c570:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c574:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c578:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c57c:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18c580:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c584:	3c018008 */ 	lui	$at,0x8008
/*  f18c588:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18c58c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f18c590:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18c594:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18c598:	ac3940f8 */ 	sw	$t9,0x40f8($at)
/*  f18c59c:	10000073 */ 	beqz	$zero,.L0f18c76c
/*  f18c5a0:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c5a4:
/*  f18c5a4:	3c16800b */ 	lui	$s6,%hi(g_MpLockPlayerNum)
/*  f18c5a8:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockPlayerNum)
/*  f18c5ac:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c5b0:
/*  f18c5b0:	0c004b70 */ 	jal	random
/*  f18c5b4:	00008825 */ 	or	$s1,$zero,$zero
/*  f18c5b8:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18c5bc:	00009010 */ 	mfhi	$s2
/*  f18c5c0:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f18c5c4:	16a00002 */ 	bnez	$s5,.L0f18c5d0
/*  f18c5c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c5cc:	0007000d */ 	break	0x7
.L0f18c5d0:
/*  f18c5d0:	5a80000d */ 	blezl	$s4,.L0f18c608
/*  f18c5d4:	2401ffff */ 	addiu	$at,$zero,-1
.L0f18c5d8:
/*  f18c5d8:	0fc630ac */ 	jal	func0f18c2b0
/*  f18c5dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c5e0:	50400006 */ 	beqzl	$v0,.L0f18c5fc
/*  f18c5e4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c5e8:	56510003 */ 	bnel	$s2,$s1,.L0f18c5f8
/*  f18c5ec:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18c5f0:	02009825 */ 	or	$s3,$s0,$zero
/*  f18c5f4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18c5f8:
/*  f18c5f8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18c5fc:
/*  f18c5fc:	1614fff6 */ 	bne	$s0,$s4,.L0f18c5d8
/*  f18c600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c604:	2401ffff */ 	addiu	$at,$zero,-1
.L0f18c608:
/*  f18c608:	1661000a */ 	bne	$s3,$at,.L0f18c634
/*  f18c60c:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c610:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c614:	3c018008 */ 	lui	$at,0x8008
/*  f18c618:	306801ff */ 	andi	$t0,$v1,0x1ff
/*  f18c61c:	00084900 */ 	sll	$t1,$t0,0x4
/*  f18c620:	01284823 */ 	subu	$t1,$t1,$t0
/*  f18c624:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c628:	ac2940f8 */ 	sw	$t1,0x40f8($at)
/*  f18c62c:	1000004f */ 	beqz	$zero,.L0f18c76c
/*  f18c630:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c634:
/*  f18c634:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c638:	02602025 */ 	or	$a0,$s3,$zero
/*  f18c63c:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f18c640:	14200004 */ 	bnez	$at,.L0f18c654
/*  f18c644:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c648:	8eca0004 */ 	lw	$t2,0x4($s6)
/*  f18c64c:	504affd8 */ 	beql	$v0,$t2,.L0f18c5b0
/*  f18c650:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c654:
/*  f18c654:	00135880 */ 	sll	$t3,$s3,0x2
/*  f18c658:	01735823 */ 	subu	$t3,$t3,$s3
/*  f18c65c:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f18c660:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c664:	aed30004 */ 	sw	$s3,0x4($s6)
/*  f18c668:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18c66c:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c670:	3c018008 */ 	lui	$at,0x8008
/*  f18c674:	306c01ff */ 	andi	$t4,$v1,0x1ff
/*  f18c678:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f18c67c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f18c680:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18c684:	ac2d40f8 */ 	sw	$t5,0x40f8($at)
/*  f18c688:	10000038 */ 	beqz	$zero,.L0f18c76c
/*  f18c68c:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c690:
/*  f18c690:	0fc63122 */ 	jal	func0f18c488
/*  f18c694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c698:	04410022 */ 	bgez	$v0,.L0f18c724
/*  f18c69c:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c6a0:	0fc63080 */ 	jal	func0f18c200
/*  f18c6a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6a8:	3c16800b */ 	lui	$s6,%hi(g_MpLockPlayerNum)
/*  f18c6ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f18c6b0:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockPlayerNum)
.L0f18c6b4:
/*  f18c6b4:	0c004b70 */ 	jal	random
/*  f18c6b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6bc:	0050001b */ 	divu	$zero,$v0,$s0
/*  f18c6c0:	00002010 */ 	mfhi	$a0
/*  f18c6c4:	16000002 */ 	bnez	$s0,.L0f18c6d0
/*  f18c6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6cc:	0007000d */ 	break	0x7
.L0f18c6d0:
/*  f18c6d0:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c6d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6d8:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18c6dc:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c6e0:	104efff4 */ 	beq	$v0,$t6,.L0f18c6b4
/*  f18c6e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6e8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c6ec:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c6f0:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c6f4:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c6f8:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c6fc:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18c700:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c704:	3c018008 */ 	lui	$at,0x8008
/*  f18c708:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18c70c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f18c710:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18c714:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18c718:	ac3940f8 */ 	sw	$t9,0x40f8($at)
/*  f18c71c:	10000013 */ 	beqz	$zero,.L0f18c76c
/*  f18c720:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c724:
/*  f18c724:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c728:	02602025 */ 	or	$a0,$s3,$zero
/*  f18c72c:	00024080 */ 	sll	$t0,$v0,0x2
/*  f18c730:	3c16800b */ 	lui	$s6,%hi(g_MpLockPlayerNum)
/*  f18c734:	01024023 */ 	subu	$t0,$t0,$v0
/*  f18c738:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockPlayerNum)
/*  f18c73c:	00084040 */ 	sll	$t0,$t0,0x1
/*  f18c740:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c744:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c748:	00681821 */ 	addu	$v1,$v1,$t0
/*  f18c74c:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c750:	3c018008 */ 	lui	$at,0x8008
/*  f18c754:	306901ff */ 	andi	$t1,$v1,0x1ff
/*  f18c758:	00095100 */ 	sll	$t2,$t1,0x4
/*  f18c75c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f18c760:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18c764:	ac2a40f8 */ 	sw	$t2,0x40f8($at)
/*  f18c768:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c76c:
/*  f18c76c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18c770:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18c774:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18c778:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18c77c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18c780:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18c784:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18c788:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18c78c:	03e00008 */ 	jr	$ra
/*  f18c790:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f18c794
/*  f18c794:	3c06800b */ 	lui	$a2,0x800b
/*  f18c798:	00001025 */ 	or	$v0,$zero,$zero
/*  f18c79c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c7a0:	94c6cb9e */ 	lhu	$a2,-0x3462($a2)
/*  f18c7a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f18c7a8:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f18c7ac:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c7b0:
/*  f18c7b0:	00ae7804 */ 	sllv	$t7,$t6,$a1
/*  f18c7b4:	00cfc024 */ 	and	$t8,$a2,$t7
/*  f18c7b8:	53000017 */ 	beqzl	$t8,.L0f18c818
/*  f18c7bc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f18c7c0:	14440013 */ 	bne	$v0,$a0,.L0f18c810
/*  f18c7c4:	28a10004 */ 	slti	$at,$a1,0x4
/*  f18c7c8:	10200008 */ 	beqz	$at,.L0f18c7ec
/*  f18c7cc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f18c7d0:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f18c7d4:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f18c7d8:	3c08800b */ 	lui	$t0,%hi(g_MpPlayers)
/*  f18c7dc:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpPlayers)
/*  f18c7e0:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18c7e4:	03e00008 */ 	jr	$ra
/*  f18c7e8:	03281021 */ 	addu	$v0,$t9,$t0
.L0f18c7ec:
/*  f18c7ec:	01254821 */ 	addu	$t1,$t1,$a1
/*  f18c7f0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c7f4:	01254823 */ 	subu	$t1,$t1,$a1
/*  f18c7f8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c7fc:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f18c800:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f18c804:	252afed0 */ 	addiu	$t2,$t1,-304
/*  f18c808:	03e00008 */ 	jr	$ra
/*  f18c80c:	014b1021 */ 	addu	$v0,$t2,$t3
.L0f18c810:
/*  f18c810:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18c814:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f18c818:
/*  f18c818:	54a7ffe5 */ 	bnel	$a1,$a3,.L0f18c7b0
/*  f18c81c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c820:	03e00008 */ 	jr	$ra
/*  f18c824:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18c828
/*  f18c828:	3c06800b */ 	lui	$a2,0x800b
/*  f18c82c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18c830:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c834:	94c6cb9e */ 	lhu	$a2,-0x3462($a2)
/*  f18c838:	00002825 */ 	or	$a1,$zero,$zero
/*  f18c83c:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f18c840:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c844:
/*  f18c844:	00ae7804 */ 	sllv	$t7,$t6,$a1
/*  f18c848:	00cfc024 */ 	and	$t8,$a2,$t7
/*  f18c84c:	53000007 */ 	beqzl	$t8,.L0f18c86c
/*  f18c850:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f18c854:	54440004 */ 	bnel	$v0,$a0,.L0f18c868
/*  f18c858:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18c85c:	03e00008 */ 	jr	$ra
/*  f18c860:	00a01025 */ 	or	$v0,$a1,$zero
/*  f18c864:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f18c868:
/*  f18c868:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f18c86c:
/*  f18c86c:	54a7fff5 */ 	bnel	$a1,$a3,.L0f18c844
/*  f18c870:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c874:	03e00008 */ 	jr	$ra
/*  f18c878:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18c87c
/*  f18c87c:	3c04800b */ 	lui	$a0,0x800b
/*  f18c880:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c884:	9484cb9e */ 	lhu	$a0,-0x3462($a0)
/*  f18c888:	00001025 */ 	or	$v0,$zero,$zero
/*  f18c88c:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f18c890:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c894:
/*  f18c894:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f18c898:	008fc024 */ 	and	$t8,$a0,$t7
/*  f18c89c:	13000002 */ 	beqz	$t8,.L0f18c8a8
/*  f18c8a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18c8a4:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18c8a8:
/*  f18c8a8:	5445fffa */ 	bnel	$v0,$a1,.L0f18c894
/*  f18c8ac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c8b0:	03e00008 */ 	jr	$ra
/*  f18c8b4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18c8b8
/*  f18c8b8:	3c05800b */ 	lui	$a1,0x800b
/*  f18c8bc:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f18c8c0:	3c08800b */ 	lui	$t0,%hi(g_MpPlayers)
/*  f18c8c4:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c8c8:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpPlayers)
/*  f18c8cc:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f18c8d0:	94a5cb9e */ 	lhu	$a1,-0x3462($a1)
/*  f18c8d4:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f18c8d8:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f18c8dc:	240900a0 */ 	addiu	$t1,$zero,0xa0
/*  f18c8e0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18c8e4:
/*  f18c8e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f18c8e8:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c8ec:
/*  f18c8ec:	008e7804 */ 	sllv	$t7,$t6,$a0
/*  f18c8f0:	00afc024 */ 	and	$t8,$a1,$t7
/*  f18c8f4:	13000010 */ 	beqz	$t8,.L0f18c938
/*  f18c8f8:	28810004 */ 	slti	$at,$a0,0x4
/*  f18c8fc:	10200006 */ 	beqz	$at,.L0f18c918
/*  f18c900:	00603825 */ 	or	$a3,$v1,$zero
/*  f18c904:	00890019 */ 	multu	$a0,$t1
/*  f18c908:	0000c812 */ 	mflo	$t9
/*  f18c90c:	01193021 */ 	addu	$a2,$t0,$t9
/*  f18c910:	10000006 */ 	beqz	$zero,.L0f18c92c
/*  f18c914:	90ce0011 */ 	lbu	$t6,0x11($a2)
.L0f18c918:
/*  f18c918:	008c0019 */ 	multu	$a0,$t4
/*  f18c91c:	00006812 */ 	mflo	$t5
/*  f18c920:	016d3021 */ 	addu	$a2,$t3,$t5
/*  f18c924:	24c6fed0 */ 	addiu	$a2,$a2,-304
/*  f18c928:	90ce0011 */ 	lbu	$t6,0x11($a2)
.L0f18c92c:
/*  f18c92c:	54ee0003 */ 	bnel	$a3,$t6,.L0f18c93c
/*  f18c930:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18c934:	00001025 */ 	or	$v0,$zero,$zero
.L0f18c938:
/*  f18c938:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f18c93c:
/*  f18c93c:	548affeb */ 	bnel	$a0,$t2,.L0f18c8ec
/*  f18c940:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c944:	54400005 */ 	bnezl	$v0,.L0f18c95c
/*  f18c948:	28610007 */ 	slti	$at,$v1,0x7
/*  f18c94c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18c950:	306f00ff */ 	andi	$t7,$v1,0xff
/*  f18c954:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18c958:	28610007 */ 	slti	$at,$v1,0x7
.L0f18c95c:
/*  f18c95c:	50200004 */ 	beqzl	$at,.L0f18c970
/*  f18c960:	28610008 */ 	slti	$at,$v1,0x8
/*  f18c964:	5040ffdf */ 	beqzl	$v0,.L0f18c8e4
/*  f18c968:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18c96c:	28610008 */ 	slti	$at,$v1,0x8
.L0f18c970:
/*  f18c970:	14200002 */ 	bnez	$at,.L0f18c97c
/*  f18c974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c978:	24030007 */ 	addiu	$v1,$zero,0x7
.L0f18c97c:
/*  f18c97c:	03e00008 */ 	jr	$ra
/*  f18c980:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18c984
/*  f18c984:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f18c988:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18c98c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18c990:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18c994:	00808025 */ 	or	$s0,$a0,$zero
/*  f18c998:	30b200ff */ 	andi	$s2,$a1,0xff
/*  f18c99c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18c9a0:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18c9a4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18c9a8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18c9ac:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18c9b0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18c9b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18c9b8:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f18c9bc:	0fc6322e */ 	jal	func0f18c8b8
/*  f18c9c0:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f18c9c4:	2415004c */ 	addiu	$s5,$zero,0x4c
/*  f18c9c8:	02150019 */ 	multu	$s0,$s5
/*  f18c9cc:	3c188008 */ 	lui	$t8,%hi(g_MpGeneralSimulants)
/*  f18c9d0:	2718772c */ 	addiu	$t8,$t8,%lo(g_MpGeneralSimulants)
/*  f18c9d4:	001278c0 */ 	sll	$t7,$s2,0x3
/*  f18c9d8:	01f83821 */ 	addu	$a3,$t7,$t8
/*  f18c9dc:	90e80001 */ 	lbu	$t0,0x1($a3)
/*  f18c9e0:	3c14800b */ 	lui	$s4,%hi(g_MpSimulants)
/*  f18c9e4:	90f90000 */ 	lbu	$t9,0x0($a3)
/*  f18c9e8:	2694c538 */ 	addiu	$s4,$s4,%lo(g_MpSimulants)
/*  f18c9ec:	3c0a800b */ 	lui	$t2,%hi(var800ac798)
/*  f18c9f0:	00007012 */ 	mflo	$t6
/*  f18c9f4:	028ef021 */ 	addu	$s8,$s4,$t6
/*  f18c9f8:	305100ff */ 	andi	$s1,$v0,0xff
/*  f18c9fc:	254ac798 */ 	addiu	$t2,$t2,%lo(var800ac798)
/*  f18ca00:	00104880 */ 	sll	$t1,$s0,0x2
/*  f18ca04:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f18ca08:	012a2021 */ 	addu	$a0,$t1,$t2
/*  f18ca0c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f18ca10:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ca14:	a3c80048 */ 	sb	$t0,0x48($s8)
/*  f18ca18:	310500ff */ 	andi	$a1,$t0,0xff
/*  f18ca1c:	a3d90047 */ 	sb	$t9,0x47($s8)
.L0f18ca20:
/*  f18ca20:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18ca24:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18ca28:	1462fffd */ 	bne	$v1,$v0,.L0f18ca20
/*  f18ca2c:	a085ffff */ 	sb	$a1,-0x1($a0)
/*  f18ca30:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18ca34:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18ca38:	944b0016 */ 	lhu	$t3,0x16($v0)
/*  f18ca3c:	260c0004 */ 	addiu	$t4,$s0,0x4
/*  f18ca40:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f18ca44:	018d7004 */ 	sllv	$t6,$t5,$t4
/*  f18ca48:	3c057f1c */ 	lui	$a1,%hi(var7f1b8b6c)
/*  f18ca4c:	016e7825 */ 	or	$t7,$t3,$t6
/*  f18ca50:	a44f0016 */ 	sh	$t7,0x16($v0)
/*  f18ca54:	24a58b6c */ 	addiu	$a1,$a1,%lo(var7f1b8b6c)
/*  f18ca58:	03c02025 */ 	or	$a0,$s8,$zero
/*  f18ca5c:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f18ca60:	0c004c4c */ 	jal	strcpy
/*  f18ca64:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f18ca68:	a3d10011 */ 	sb	$s1,0x11($s8)
/*  f18ca6c:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers)
/*  f18ca70:	3c168008 */ 	lui	$s6,%hi(table_0x2d678)
/*  f18ca74:	26d67658 */ 	addiu	$s6,$s6,%lo(table_0x2d678)
/*  f18ca78:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpPlayers)
/*  f18ca7c:	24170035 */ 	addiu	$s7,$zero,0x35
/*  f18ca80:	2413000c */ 	addiu	$s3,$zero,0xc
/*  f18ca84:	241200a0 */ 	addiu	$s2,$zero,0xa0
.L0f18ca88:
/*  f18ca88:	0c004b70 */ 	jal	random
/*  f18ca8c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18ca90:	0057001b */ 	divu	$zero,$v0,$s7
/*  f18ca94:	0000c010 */ 	mfhi	$t8
/*  f18ca98:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18ca9c:	02d94021 */ 	addu	$t0,$s6,$t9
/*  f18caa0:	3c04800b */ 	lui	$a0,0x800b
/*  f18caa4:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f18caa8:	16e00002 */ 	bnez	$s7,.L0f18cab4
/*  f18caac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cab0:	0007000d */ 	break	0x7
.L0f18cab4:
/*  f18cab4:	9484cb9e */ 	lhu	$a0,-0x3462($a0)
/*  f18cab8:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cabc:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f18cac0:
/*  f18cac0:	00695004 */ 	sllv	$t2,$t1,$v1
/*  f18cac4:	008a6824 */ 	and	$t5,$a0,$t2
/*  f18cac8:	11a00010 */ 	beqz	$t5,.L0f18cb0c
/*  f18cacc:	28610004 */ 	slti	$at,$v1,0x4
/*  f18cad0:	10200006 */ 	beqz	$at,.L0f18caec
/*  f18cad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cad8:	00720019 */ 	multu	$v1,$s2
/*  f18cadc:	00006012 */ 	mflo	$t4
/*  f18cae0:	022c1021 */ 	addu	$v0,$s1,$t4
/*  f18cae4:	10000006 */ 	beqz	$zero,.L0f18cb00
/*  f18cae8:	904e000f */ 	lbu	$t6,0xf($v0)
.L0f18caec:
/*  f18caec:	00750019 */ 	multu	$v1,$s5
/*  f18caf0:	00005812 */ 	mflo	$t3
/*  f18caf4:	028b1021 */ 	addu	$v0,$s4,$t3
/*  f18caf8:	2442fed0 */ 	addiu	$v0,$v0,-304
/*  f18cafc:	904e000f */ 	lbu	$t6,0xf($v0)
.L0f18cb00:
/*  f18cb00:	54ce0003 */ 	bnel	$a2,$t6,.L0f18cb10
/*  f18cb04:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18cb08:	00008025 */ 	or	$s0,$zero,$zero
.L0f18cb0c:
/*  f18cb0c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18cb10:
/*  f18cb10:	5473ffeb */ 	bnel	$v1,$s3,.L0f18cac0
/*  f18cb14:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f18cb18:	1200ffdb */ 	beqz	$s0,.L0f18ca88
/*  f18cb1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cb20:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f18cb24:	a3c6000f */ 	sb	$a2,0xf($s8)
/*  f18cb28:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18cb2c:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f18cb30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18cb34:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18cb38:	a3d80010 */ 	sb	$t8,0x10($s8)
/*  f18cb3c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18cb40:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18cb44:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18cb48:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18cb4c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18cb50:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18cb54:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18cb58:	03e00008 */ 	jr	$ra
/*  f18cb5c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f18cb60
/*  f18cb60:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18cb64:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f18cb68:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18cb6c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f18cb70:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f18cb74:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f18cb78:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18cb7c:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f18cb80:	3c19800b */ 	lui	$t9,%hi(var800ac798)
/*  f18cb84:	a0450048 */ 	sb	$a1,0x48($v0)
/*  f18cb88:	2739c798 */ 	addiu	$t9,$t9,%lo(var800ac798)
/*  f18cb8c:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f18cb90:	03193021 */ 	addu	$a2,$t8,$t9
/*  f18cb94:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f18cb98:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cb9c:	30a700ff */ 	andi	$a3,$a1,0xff
.L0f18cba0:
/*  f18cba0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18cba4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f18cba8:	1462fffd */ 	bne	$v1,$v0,.L0f18cba0
/*  f18cbac:	a0c7ffff */ 	sb	$a3,-0x1($a2)
/*  f18cbb0:	03e00008 */ 	jr	$ra
/*  f18cbb4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18cbb8
/*  f18cbb8:	3c02800b */ 	lui	$v0,0x800b
/*  f18cbbc:	9442cb9e */ 	lhu	$v0,-0x3462($v0)
/*  f18cbc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cbc4:	304e0010 */ 	andi	$t6,$v0,0x10
/*  f18cbc8:	11c0000a */ 	beqz	$t6,.L0f18cbf4
/*  f18cbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cbd0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18cbd4:
/*  f18cbd4:	28610007 */ 	slti	$at,$v1,0x7
/*  f18cbd8:	10200006 */ 	beqz	$at,.L0f18cbf4
/*  f18cbdc:	246f0004 */ 	addiu	$t7,$v1,0x4
/*  f18cbe0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18cbe4:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f18cbe8:	00594024 */ 	and	$t0,$v0,$t9
/*  f18cbec:	5500fff9 */ 	bnezl	$t0,.L0f18cbd4
/*  f18cbf0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18cbf4:
/*  f18cbf4:	03e00008 */ 	jr	$ra
/*  f18cbf8:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel mpRemoveSimulant
/*  f18cbfc:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18cc00:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18cc04:	00045080 */ 	sll	$t2,$a0,0x2
/*  f18cc08:	944e0016 */ 	lhu	$t6,0x16($v0)
/*  f18cc0c:	248f0004 */ 	addiu	$t7,$a0,0x4
/*  f18cc10:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18cc14:	01445021 */ 	addu	$t2,$t2,$a0
/*  f18cc18:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f18cc1c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18cc20:	03204027 */ 	nor	$t0,$t9,$zero
/*  f18cc24:	01445023 */ 	subu	$t2,$t2,$a0
/*  f18cc28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18cc2c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18cc30:	3c01800b */ 	lui	$at,0x800b
/*  f18cc34:	01c84824 */ 	and	$t1,$t6,$t0
/*  f18cc38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18cc3c:	a4490016 */ 	sh	$t1,0x16($v0)
/*  f18cc40:	002a0821 */ 	addu	$at,$at,$t2
/*  f18cc44:	0fc62075 */ 	jal	func0f1881d4
/*  f18cc48:	a020c538 */ 	sb	$zero,-0x3ac8($at)
/*  f18cc4c:	0fc63377 */ 	jal	func0f18cddc
/*  f18cc50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cc54:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18cc58:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18cc5c:	03e00008 */ 	jr	$ra
/*  f18cc60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18cc64
/*  f18cc64:	3c0e800b */ 	lui	$t6,0x800b
/*  f18cc68:	95cecb9e */ 	lhu	$t6,-0x3462($t6)
/*  f18cc6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18cc70:	31cffff0 */ 	andi	$t7,$t6,0xfff0
/*  f18cc74:	11e00003 */ 	beqz	$t7,.L0f18cc84
/*  f18cc78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cc7c:	03e00008 */ 	jr	$ra
/*  f18cc80:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18cc84:
/*  f18cc84:	03e00008 */ 	jr	$ra
/*  f18cc88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18cc8c
/*  f18cc8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18cc90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18cc94:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18cc98:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f18cc9c:	10400003 */ 	beqz	$v0,.L0f18ccac
/*  f18cca0:	3c04800b */ 	lui	$a0,0x800b
/*  f18cca4:	10000002 */ 	beqz	$zero,.L0f18ccb0
/*  f18cca8:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f18ccac:
/*  f18ccac:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f18ccb0:
/*  f18ccb0:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f18ccb4:	9484cb9e */ 	lhu	$a0,-0x3462($a0)
/*  f18ccb8:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f18ccbc:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18ccc0:
/*  f18ccc0:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f18ccc4:	008fc024 */ 	and	$t8,$a0,$t7
/*  f18ccc8:	13000002 */ 	beqz	$t8,.L0f18ccd4
/*  f18cccc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18ccd0:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f18ccd4:
/*  f18ccd4:	5445fffa */ 	bnel	$v0,$a1,.L0f18ccc0
/*  f18ccd8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18ccdc:	18600003 */ 	blez	$v1,.L0f18ccec
/*  f18cce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18cce4:	10000002 */ 	beqz	$zero,.L0f18ccf0
/*  f18cce8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18ccec:
/*  f18ccec:	00001025 */ 	or	$v0,$zero,$zero
.L0f18ccf0:
/*  f18ccf0:	03e00008 */ 	jr	$ra
/*  f18ccf4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel mpIsSimSlotEnabled
/*  f18ccf8:	3c03800b */ 	lui	$v1,0x800b
/*  f18ccfc:	9463cb9e */ 	lhu	$v1,-0x3462($v1)
/*  f18cd00:	248e0004 */ 	addiu	$t6,$a0,0x4
/*  f18cd04:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18cd08:	01cfc004 */ 	sllv	$t8,$t7,$t6
/*  f18cd0c:	0078c824 */ 	and	$t9,$v1,$t8
/*  f18cd10:	17200012 */ 	bnez	$t9,.L0f18cd5c
/*  f18cd14:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f18cd18:	00002025 */ 	or	$a0,$zero,$zero
/*  f18cd1c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f18cd20:	24880004 */ 	addiu	$t0,$a0,0x4
.L0f18cd24:
/*  f18cd24:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f18cd28:	01095004 */ 	sllv	$t2,$t1,$t0
/*  f18cd2c:	006a5824 */ 	and	$t3,$v1,$t2
/*  f18cd30:	11600002 */ 	beqz	$t3,.L0f18cd3c
/*  f18cd34:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18cd38:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f18cd3c:
/*  f18cd3c:	5485fff9 */ 	bnel	$a0,$a1,.L0f18cd24
/*  f18cd40:	24880004 */ 	addiu	$t0,$a0,0x4
/*  f18cd44:	18400003 */ 	blez	$v0,.L0f18cd54
/*  f18cd48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cd4c:	03e00008 */ 	jr	$ra
/*  f18cd50:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18cd54:
/*  f18cd54:	03e00008 */ 	jr	$ra
/*  f18cd58:	00001025 */ 	or	$v0,$zero,$zero
.L0f18cd5c:
/*  f18cd5c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18cd60:	03e00008 */ 	jr	$ra
/*  f18cd64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18cd68
/*  f18cd68:	1480000d */ 	bnez	$a0,.L0f18cda0
/*  f18cd6c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cd70:	3c028008 */ 	lui	$v0,%hi(g_MpGeneralSimulants)
/*  f18cd74:	2442772c */ 	addiu	$v0,$v0,%lo(g_MpGeneralSimulants)
/*  f18cd78:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cd7c:	24060012 */ 	addiu	$a2,$zero,0x12
.L0f18cd80:
/*  f18cd80:	904e0001 */ 	lbu	$t6,0x1($v0)
/*  f18cd84:	50ae0010 */ 	beql	$a1,$t6,.L0f18cdc8
/*  f18cd88:	28610012 */ 	slti	$at,$v1,0x12
/*  f18cd8c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18cd90:	1466fffb */ 	bne	$v1,$a2,.L0f18cd80
/*  f18cd94:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f18cd98:	1000000b */ 	beqz	$zero,.L0f18cdc8
/*  f18cd9c:	28610012 */ 	slti	$at,$v1,0x12
.L0f18cda0:
/*  f18cda0:	3c028008 */ 	lui	$v0,%hi(g_MpGeneralSimulants)
/*  f18cda4:	2442772c */ 	addiu	$v0,$v0,%lo(g_MpGeneralSimulants)
/*  f18cda8:	24060012 */ 	addiu	$a2,$zero,0x12
.L0f18cdac:
/*  f18cdac:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f18cdb0:	508f0005 */ 	beql	$a0,$t7,.L0f18cdc8
/*  f18cdb4:	28610012 */ 	slti	$at,$v1,0x12
/*  f18cdb8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18cdbc:	1466fffb */ 	bne	$v1,$a2,.L0f18cdac
/*  f18cdc0:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f18cdc4:	28610012 */ 	slti	$at,$v1,0x12
.L0f18cdc8:
/*  f18cdc8:	14200002 */ 	bnez	$at,.L0f18cdd4
/*  f18cdcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18cdd0:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f18cdd4:
/*  f18cdd4:	03e00008 */ 	jr	$ra
/*  f18cdd8:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18cddc
/*  f18cddc:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f18cde0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18cde4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18cde8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18cdec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18cdf0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18cdf4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18cdf8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18cdfc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18ce00:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ce04:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ce08:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f18ce0c:	27a300b0 */ 	addiu	$v1,$sp,0xb0
.L0f18ce10:
/*  f18ce10:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18ce14:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18ce18:	1420fffd */ 	bnez	$at,.L0f18ce10
/*  f18ce1c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f18ce20:	3c17800b */ 	lui	$s7,%hi(g_MpSimulants)
/*  f18ce24:	3c16800b */ 	lui	$s6,%hi(g_MpSetup)
/*  f18ce28:	26d6cb88 */ 	addiu	$s6,$s6,%lo(g_MpSetup)
/*  f18ce2c:	26f7c538 */ 	addiu	$s7,$s7,%lo(g_MpSimulants)
/*  f18ce30:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f18ce34:	241e004c */ 	addiu	$s8,$zero,0x4c
/*  f18ce38:	27b50068 */ 	addiu	$s5,$sp,0x68
/*  f18ce3c:	96ce0016 */ 	lhu	$t6,0x16($s6)
.L0f18ce40:
/*  f18ce40:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18ce44:	022fc004 */ 	sllv	$t8,$t7,$s1
/*  f18ce48:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f18ce4c:	53200010 */ 	beqzl	$t9,.L0f18ce90
/*  f18ce50:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18ce54:	023e0019 */ 	multu	$s1,$s8
/*  f18ce58:	00004012 */ 	mflo	$t0
/*  f18ce5c:	02e88021 */ 	addu	$s0,$s7,$t0
/*  f18ce60:	9204ff17 */ 	lbu	$a0,-0xe9($s0)
/*  f18ce64:	0fc6335a */ 	jal	func0f18cd68
/*  f18ce68:	9205ff18 */ 	lbu	$a1,-0xe8($s0)
/*  f18ce6c:	04400007 */ 	bltz	$v0,.L0f18ce8c
/*  f18ce70:	28410012 */ 	slti	$at,$v0,0x12
/*  f18ce74:	10200005 */ 	beqz	$at,.L0f18ce8c
/*  f18ce78:	00024880 */ 	sll	$t1,$v0,0x2
/*  f18ce7c:	02a91821 */ 	addu	$v1,$s5,$t1
/*  f18ce80:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f18ce84:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f18ce88:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f18ce8c:
/*  f18ce8c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18ce90:
/*  f18ce90:	2a21000c */ 	slti	$at,$s1,0xc
/*  f18ce94:	5420ffea */ 	bnezl	$at,.L0f18ce40
/*  f18ce98:	96ce0016 */ 	lhu	$t6,0x16($s6)
/*  f18ce9c:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f18cea0:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f18cea4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f18cea8:	8c4c0000 */ 	lw	$t4,0x0($v0)
.L0f18ceac:
/*  f18ceac:	29810002 */ 	slti	$at,$t4,0x2
/*  f18ceb0:	50200004 */ 	beqzl	$at,.L0f18cec4
/*  f18ceb4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f18ceb8:	10000002 */ 	beqz	$zero,.L0f18cec4
/*  f18cebc:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f18cec0:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f18cec4:
/*  f18cec4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18cec8:	0044082b */ 	sltu	$at,$v0,$a0
/*  f18cecc:	5420fff7 */ 	bnezl	$at,.L0f18ceac
/*  f18ced0:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f18ced4:	3c148008 */ 	lui	$s4,%hi(g_MpGeneralSimulants)
/*  f18ced8:	2694772c */ 	addiu	$s4,$s4,%lo(g_MpGeneralSimulants)
/*  f18cedc:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f18cee0:	27b30050 */ 	addiu	$s3,$sp,0x50
/*  f18cee4:	96cd0016 */ 	lhu	$t5,0x16($s6)
.L0f18cee8:
/*  f18cee8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18ceec:	022f7004 */ 	sllv	$t6,$t7,$s1
/*  f18cef0:	01aec024 */ 	and	$t8,$t5,$t6
/*  f18cef4:	53000031 */ 	beqzl	$t8,.L0f18cfbc
/*  f18cef8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18cefc:	023e0019 */ 	multu	$s1,$s8
/*  f18cf00:	0000c812 */ 	mflo	$t9
/*  f18cf04:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f18cf08:	9204ff17 */ 	lbu	$a0,-0xe9($s0)
/*  f18cf0c:	0fc6335a */ 	jal	func0f18cd68
/*  f18cf10:	9205ff18 */ 	lbu	$a1,-0xe8($s0)
/*  f18cf14:	04400028 */ 	bltz	$v0,.L0f18cfb8
/*  f18cf18:	00401825 */ 	or	$v1,$v0,$zero
/*  f18cf1c:	28410012 */ 	slti	$at,$v0,0x12
/*  f18cf20:	10200025 */ 	beqz	$at,.L0f18cfb8
/*  f18cf24:	00024080 */ 	sll	$t0,$v0,0x2
/*  f18cf28:	02a84821 */ 	addu	$t1,$s5,$t0
/*  f18cf2c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f18cf30:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f18cf34:	2612fed0 */ 	addiu	$s2,$s0,-304
/*  f18cf38:	05400015 */ 	bltz	$t2,.L0f18cf90
/*  f18cf3c:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f18cf40:	00025880 */ 	sll	$t3,$v0,0x2
/*  f18cf44:	02ab8021 */ 	addu	$s0,$s5,$t3
/*  f18cf48:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18cf4c:	000268c0 */ 	sll	$t5,$v0,0x3
/*  f18cf50:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f18cf54:	258f0001 */ 	addiu	$t7,$t4,0x1
/*  f18cf58:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f18cf5c:	0fc5b9f1 */ 	jal	langGet
/*  f18cf60:	85c40002 */ 	lh	$a0,0x2($t6)
/*  f18cf64:	3c057f1c */ 	lui	$a1,%hi(var7f1b8b74)
/*  f18cf68:	24a58b74 */ 	addiu	$a1,$a1,%lo(var7f1b8b74)
/*  f18cf6c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18cf70:	00403025 */ 	or	$a2,$v0,$zero
/*  f18cf74:	0c004dad */ 	jal	sprintf
/*  f18cf78:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f18cf7c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18cf80:	0c004c4c */ 	jal	strcpy
/*  f18cf84:	02602825 */ 	or	$a1,$s3,$zero
/*  f18cf88:	1000000c */ 	beqz	$zero,.L0f18cfbc
/*  f18cf8c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18cf90:
/*  f18cf90:	0fc5b9f1 */ 	jal	langGet
/*  f18cf94:	87240002 */ 	lh	$a0,0x2($t9)
/*  f18cf98:	3c057f1c */ 	lui	$a1,%hi(var7f1b8b7c)
/*  f18cf9c:	24a58b7c */ 	addiu	$a1,$a1,%lo(var7f1b8b7c)
/*  f18cfa0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18cfa4:	0c004dad */ 	jal	sprintf
/*  f18cfa8:	00403025 */ 	or	$a2,$v0,$zero
/*  f18cfac:	02402025 */ 	or	$a0,$s2,$zero
/*  f18cfb0:	0c004c4c */ 	jal	strcpy
/*  f18cfb4:	02602825 */ 	or	$a1,$s3,$zero
.L0f18cfb8:
/*  f18cfb8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18cfbc:
/*  f18cfbc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f18cfc0:	5621ffc9 */ 	bnel	$s1,$at,.L0f18cee8
/*  f18cfc4:	96cd0016 */ 	lhu	$t5,0x16($s6)
/*  f18cfc8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18cfcc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18cfd0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18cfd4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18cfd8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18cfdc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18cfe0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18cfe4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18cfe8:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18cfec:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18cff0:	03e00008 */ 	jr	$ra
/*  f18cff4:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

s32 mpPlayerGetIndex(struct chrdata *chr)
{
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (g_MpPlayerChrs[i] == chr) {
			return i;
		}
	}

	return -1;
}

struct chrdata *mpGetChrFromPlayerIndex(s32 index)
{
	if (index >= 0 && index < g_MpNumPlayers) {
		return g_MpPlayerChrs[index];
	}

	return NULL;
}

s32 func0f18d074(s32 index)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (&g_MpPlayers[i].base == var800ac500[index]) {
			return i;
		}
	}

	for (i = 0; i < MAX_SIMULANTS; i++) {
		if (&g_MpSimulants[i].base == var800ac500[index]) {
			return i + 4;
		}
	}

	return -1;
}

GLOBAL_ASM(
glabel func0f18d0e8
/*  f18d0e8:	28810004 */ 	slti	$at,$a0,0x4
/*  f18d0ec:	10200018 */ 	beqz	$at,.L0f18d150
/*  f18d0f0:	3c02800b */ 	lui	$v0,0x800b
/*  f18d0f4:	3c02800b */ 	lui	$v0,%hi(g_MpNumPlayers)
/*  f18d0f8:	8c42c530 */ 	lw	$v0,%lo(g_MpNumPlayers)($v0)
/*  f18d0fc:	3c05800b */ 	lui	$a1,%hi(var800ac500)
/*  f18d100:	24a5c500 */ 	addiu	$a1,$a1,%lo(var800ac500)
/*  f18d104:	18400029 */ 	blez	$v0,.L0f18d1ac
/*  f18d108:	00001825 */ 	or	$v1,$zero,$zero
/*  f18d10c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18d110:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f18d114:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d118:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d11c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d120:	01cf3021 */ 	addu	$a2,$t6,$t7
.L0f18d124:
/*  f18d124:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f18d128:	57060004 */ 	bnel	$t8,$a2,.L0f18d13c
/*  f18d12c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d130:	03e00008 */ 	jr	$ra
/*  f18d134:	00601025 */ 	or	$v0,$v1,$zero
/*  f18d138:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d13c:
/*  f18d13c:	0062082a */ 	slt	$at,$v1,$v0
/*  f18d140:	1420fff8 */ 	bnez	$at,.L0f18d124
/*  f18d144:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f18d148:	10000019 */ 	beqz	$zero,.L0f18d1b0
/*  f18d14c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18d150:
/*  f18d150:	8c42c530 */ 	lw	$v0,-0x3ad0($v0)
/*  f18d154:	3c05800b */ 	lui	$a1,%hi(var800ac500)
/*  f18d158:	24a5c500 */ 	addiu	$a1,$a1,%lo(var800ac500)
/*  f18d15c:	18400013 */ 	blez	$v0,.L0f18d1ac
/*  f18d160:	00001825 */ 	or	$v1,$zero,$zero
/*  f18d164:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f18d168:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f18d16c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18d170:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f18d174:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18d178:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f18d17c:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f18d180:	2728fed0 */ 	addiu	$t0,$t9,-304
/*  f18d184:	01093021 */ 	addu	$a2,$t0,$t1
.L0f18d188:
/*  f18d188:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f18d18c:	55460004 */ 	bnel	$t2,$a2,.L0f18d1a0
/*  f18d190:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d194:	03e00008 */ 	jr	$ra
/*  f18d198:	00601025 */ 	or	$v0,$v1,$zero
/*  f18d19c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d1a0:
/*  f18d1a0:	0062082a */ 	slt	$at,$v1,$v0
/*  f18d1a4:	1420fff8 */ 	bnez	$at,.L0f18d188
/*  f18d1a8:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f18d1ac:
/*  f18d1ac:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18d1b0:
/*  f18d1b0:	03e00008 */ 	jr	$ra
/*  f18d1b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18d1b8
/*  f18d1b8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18d1bc:	00057080 */ 	sll	$t6,$a1,0x2
/*  f18d1c0:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f18d1c4:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d1c8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18d1cc:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18d1d0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18d1d4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18d1d8:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d1dc:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d1e0:	00809025 */ 	or	$s2,$a0,$zero
/*  f18d1e4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18d1e8:	24100023 */ 	addiu	$s0,$zero,0x23
/*  f18d1ec:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f18d1f0:	2413fffb */ 	addiu	$s3,$zero,-5
.L0f18d1f4:
/*  f18d1f4:	2a010009 */ 	slti	$at,$s0,0x9
/*  f18d1f8:	14200002 */ 	bnez	$at,.L0f18d204
/*  f18d1fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f18d200:	24050008 */ 	addiu	$a1,$zero,0x8
.L0f18d204:
/*  f18d204:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d208:	02402025 */ 	or	$a0,$s2,$zero
/*  f18d20c:	2610fff8 */ 	addiu	$s0,$s0,-8
/*  f18d210:	a2220097 */ 	sb	$v0,0x97($s1)
/*  f18d214:	1613fff7 */ 	bne	$s0,$s3,.L0f18d1f4
/*  f18d218:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d21c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18d220:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18d224:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18d228:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18d22c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18d230:	03e00008 */ 	jr	$ra
/*  f18d234:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18d238
/*  f18d238:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18d23c:	00057080 */ 	sll	$t6,$a1,0x2
/*  f18d240:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f18d244:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d248:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18d24c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18d250:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18d254:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18d258:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d25c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d260:	00809025 */ 	or	$s2,$a0,$zero
/*  f18d264:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18d268:	24100023 */ 	addiu	$s0,$zero,0x23
/*  f18d26c:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f18d270:	2413fffb */ 	addiu	$s3,$zero,-5
.L0f18d274:
/*  f18d274:	2a010009 */ 	slti	$at,$s0,0x9
/*  f18d278:	14200002 */ 	bnez	$at,.L0f18d284
/*  f18d27c:	02003025 */ 	or	$a2,$s0,$zero
/*  f18d280:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f18d284:
/*  f18d284:	02402025 */ 	or	$a0,$s2,$zero
/*  f18d288:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d28c:	92250097 */ 	lbu	$a1,0x97($s1)
/*  f18d290:	2610fff8 */ 	addiu	$s0,$s0,-8
/*  f18d294:	1613fff7 */ 	bne	$s0,$s3,.L0f18d274
/*  f18d298:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d29c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18d2a0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18d2a4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18d2a8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18d2ac:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18d2b0:	03e00008 */ 	jr	$ra
/*  f18d2b4:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18d2b8
/*  f18d2b8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f18d2bc:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f18d2c0:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18d2c4:	00147080 */ 	sll	$t6,$s4,0x2
/*  f18d2c8:	01d47021 */ 	addu	$t6,$t6,$s4
/*  f18d2cc:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d2d0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f18d2d4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18d2d8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18d2dc:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d2e0:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d2e4:	00c08025 */ 	or	$s0,$a2,$zero
/*  f18d2e8:	00a09825 */ 	or	$s3,$a1,$zero
/*  f18d2ec:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18d2f0:	01cfa821 */ 	addu	$s5,$t6,$t7
/*  f18d2f4:	00a02025 */ 	or	$a0,$a1,$zero
/*  f18d2f8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18d2fc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18d300:	02a02825 */ 	or	$a1,$s5,$zero
/*  f18d304:	0fc35539 */ 	jal	func0f0d54e4
/*  f18d308:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18d30c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d310:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d314:	2405001c */ 	addiu	$a1,$zero,0x1c
/*  f18d318:	12000037 */ 	beqz	$s0,.L0f18d3f8
/*  f18d31c:	aea20068 */ 	sw	$v0,0x68($s5)
/*  f18d320:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d324:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d328:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d32c:	a2a2000f */ 	sb	$v0,0xf($s5)
/*  f18d330:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d334:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d338:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d33c:	a2a20010 */ 	sb	$v0,0x10($s5)
/*  f18d340:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d344:	0fc355e7 */ 	jal	func0f0d579c
/*  f18d348:	27a50050 */ 	addiu	$a1,$sp,0x50
/*  f18d34c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f18d350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d354:	92b8000f */ 	lbu	$t8,0xf($s5)
/*  f18d358:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f18d35c:	0302082a */ 	slt	$at,$t8,$v0
/*  f18d360:	5420002f */ 	bnezl	$at,.L0f18d420
/*  f18d364:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d368:	10c00021 */ 	beqz	$a2,.L0f18d3f0
/*  f18d36c:	97a70054 */ 	lhu	$a3,0x54($sp)
/*  f18d370:	10e0001f */ 	beqz	$a3,.L0f18d3f0
/*  f18d374:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f18d378:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f18d37c:	80450668 */ 	lb	$a1,0x668($v0)
/*  f18d380:	28a1000b */ 	slti	$at,$a1,0xb
/*  f18d384:	10200025 */ 	beqz	$at,.L0f18d41c
/*  f18d388:	24b90001 */ 	addiu	$t9,$a1,0x1
/*  f18d38c:	a0590668 */ 	sb	$t9,0x668($v0)
/*  f18d390:	80480668 */ 	lb	$t0,0x668($v0)
/*  f18d394:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f18d398:	3c038007 */ 	lui	$v1,%hi(g_MpPlayerNum)
/*  f18d39c:	01040019 */ 	multu	$t0,$a0
/*  f18d3a0:	00004812 */ 	mflo	$t1
/*  f18d3a4:	00495021 */ 	addu	$t2,$v0,$t1
/*  f18d3a8:	ad4605d8 */ 	sw	$a2,0x5d8($t2)
/*  f18d3ac:	804b0668 */ 	lb	$t3,0x668($v0)
/*  f18d3b0:	01640019 */ 	multu	$t3,$a0
/*  f18d3b4:	00006012 */ 	mflo	$t4
/*  f18d3b8:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f18d3bc:	a5a705dc */ 	sh	$a3,0x5dc($t5)
/*  f18d3c0:	804e0668 */ 	lb	$t6,0x668($v0)
/*  f18d3c4:	8c631448 */ 	lw	$v1,%lo(g_MpPlayerNum)($v1)
/*  f18d3c8:	01c40019 */ 	multu	$t6,$a0
/*  f18d3cc:	00007812 */ 	mflo	$t7
/*  f18d3d0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f18d3d4:	a30305e0 */ 	sb	$v1,0x5e0($t8)
/*  f18d3d8:	80590668 */ 	lb	$t9,0x668($v0)
/*  f18d3dc:	03240019 */ 	multu	$t9,$a0
/*  f18d3e0:	00004012 */ 	mflo	$t0
/*  f18d3e4:	00484821 */ 	addu	$t1,$v0,$t0
/*  f18d3e8:	1000000c */ 	beqz	$zero,.L0f18d41c
/*  f18d3ec:	a12305e1 */ 	sb	$v1,0x5e1($t1)
.L0f18d3f0:
/*  f18d3f0:	1000000a */ 	beqz	$zero,.L0f18d41c
/*  f18d3f4:	a2a0000f */ 	sb	$zero,0xf($s5)
.L0f18d3f8:
/*  f18d3f8:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d3fc:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d400:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d404:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d408:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d40c:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d410:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d414:	0fc355e7 */ 	jal	func0f0d579c
/*  f18d418:	27a50050 */ 	addiu	$a1,$sp,0x50
.L0f18d41c:
/*  f18d41c:	02602025 */ 	or	$a0,$s3,$zero
.L0f18d420:
/*  f18d420:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d424:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f18d428:	aea20014 */ 	sw	$v0,0x14($s5)
/*  f18d42c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d430:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d434:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f18d438:	aea20054 */ 	sw	$v0,0x54($s5)
/*  f18d43c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d440:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d444:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f18d448:	aea20058 */ 	sw	$v0,0x58($s5)
/*  f18d44c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d450:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d454:	24050013 */ 	addiu	$a1,$zero,0x13
/*  f18d458:	aea2005c */ 	sw	$v0,0x5c($s5)
/*  f18d45c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d460:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d464:	24050013 */ 	addiu	$a1,$zero,0x13
/*  f18d468:	aea20060 */ 	sw	$v0,0x60($s5)
/*  f18d46c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d470:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d474:	24050013 */ 	addiu	$a1,$zero,0x13
/*  f18d478:	aea20064 */ 	sw	$v0,0x64($s5)
/*  f18d47c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d480:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d484:	24050019 */ 	addiu	$a1,$zero,0x19
/*  f18d488:	aea2006c */ 	sw	$v0,0x6c($s5)
/*  f18d48c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d490:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d494:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f18d498:	aea20070 */ 	sw	$v0,0x70($s5)
/*  f18d49c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4a0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d4a4:	2405001a */ 	addiu	$a1,$zero,0x1a
/*  f18d4a8:	aea20074 */ 	sw	$v0,0x74($s5)
/*  f18d4ac:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4b0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d4b4:	2405001a */ 	addiu	$a1,$zero,0x1a
/*  f18d4b8:	aea20078 */ 	sw	$v0,0x78($s5)
/*  f18d4bc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4c0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d4c4:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f18d4c8:	aea2007c */ 	sw	$v0,0x7c($s5)
/*  f18d4cc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4d0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d4d4:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f18d4d8:	aea20080 */ 	sw	$v0,0x80($s5)
/*  f18d4dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4e0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d4e4:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f18d4e8:	aea20084 */ 	sw	$v0,0x84($s5)
/*  f18d4ec:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4f0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d4f4:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f18d4f8:	aea20088 */ 	sw	$v0,0x88($s5)
/*  f18d4fc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d500:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d504:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f18d508:	aea2008c */ 	sw	$v0,0x8c($s5)
/*  f18d50c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d510:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d514:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f18d518:	aea20090 */ 	sw	$v0,0x90($s5)
/*  f18d51c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d520:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d524:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f18d528:	a2a20044 */ 	sb	$v0,0x44($s5)
/*  f18d52c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d530:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d534:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f18d538:	a6a20048 */ 	sh	$v0,0x48($s5)
/*  f18d53c:	00008825 */ 	or	$s1,$zero,$zero
/*  f18d540:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f18d544:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f18d548:
/*  f18d548:	02602025 */ 	or	$a0,$s3,$zero
.L0f18d54c:
/*  f18d54c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d550:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18d554:	02802025 */ 	or	$a0,$s4,$zero
/*  f18d558:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d55c:	02003025 */ 	or	$a2,$s0,$zero
/*  f18d560:	0fc6712e */ 	jal	mpSetChallengeCompletedByChrWithNumPlayers
/*  f18d564:	00403825 */ 	or	$a3,$v0,$zero
/*  f18d568:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18d56c:	5612fff7 */ 	bnel	$s0,$s2,.L0f18d54c
/*  f18d570:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d574:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d578:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f18d57c:	5621fff2 */ 	bnel	$s1,$at,.L0f18d548
/*  f18d580:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18d584:	0fc66bf7 */ 	jal	func0f19afdc
/*  f18d588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d58c:	0fc62864 */ 	jal	func0f18a190
/*  f18d590:	02a02025 */ 	or	$a0,$s5,$zero
/*  f18d594:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d598:	0fc6346e */ 	jal	func0f18d1b8
/*  f18d59c:	02802825 */ 	or	$a1,$s4,$zero
/*  f18d5a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18d5a4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18d5a8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18d5ac:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18d5b0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18d5b4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f18d5b8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f18d5bc:	03e00008 */ 	jr	$ra
/*  f18d5c0:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f18d5c4
/*  f18d5c4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f18d5c8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18d5cc:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18d5d0:	00147080 */ 	sll	$t6,$s4,0x2
/*  f18d5d4:	01d47021 */ 	addu	$t6,$t6,$s4
/*  f18d5d8:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d5dc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18d5e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18d5e4:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d5e8:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d5ec:	00a09825 */ 	or	$s3,$a1,$zero
/*  f18d5f0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18d5f4:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f18d5f8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f18d5fc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18d600:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18d604:	0fc35569 */ 	jal	func0f0d55a4
/*  f18d608:	02002825 */ 	or	$a1,$s0,$zero
/*  f18d60c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f18d610:	3c011000 */ 	lui	$at,0x1000
/*  f18d614:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d618:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d61c:	14200003 */ 	bnez	$at,.L0f18d62c
/*  f18d620:	3c180fff */ 	lui	$t8,0xfff
/*  f18d624:	3705ffff */ 	ori	$a1,$t8,0xffff
/*  f18d628:	ae050068 */ 	sw	$a1,0x68($s0)
.L0f18d62c:
/*  f18d62c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d630:	2406001c */ 	addiu	$a2,$zero,0x1c
/*  f18d634:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d638:	9205000f */ 	lbu	$a1,0xf($s0)
/*  f18d63c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d640:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18d644:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d648:	92050010 */ 	lbu	$a1,0x10($s0)
/*  f18d64c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d650:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18d654:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f18d658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d65c:	9219000f */ 	lbu	$t9,0xf($s0)
/*  f18d660:	0322082a */ 	slt	$at,$t9,$v0
/*  f18d664:	5420000e */ 	bnezl	$at,.L0f18d6a0
/*  f18d668:	a7a00040 */ 	sh	$zero,0x40($sp)
/*  f18d66c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f18d670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d674:	9208000f */ 	lbu	$t0,0xf($s0)
/*  f18d678:	27b10044 */ 	addiu	$s1,$sp,0x44
/*  f18d67c:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d680:	0fc541ed */ 	jal	func0f1507b4
/*  f18d684:	01022023 */ 	subu	$a0,$t0,$v0
/*  f18d688:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d68c:	0fc355d7 */ 	jal	func0f0d575c
/*  f18d690:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d694:	10000007 */ 	beqz	$zero,.L0f18d6b4
/*  f18d698:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d69c:	a7a00040 */ 	sh	$zero,0x40($sp)
.L0f18d6a0:
/*  f18d6a0:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f18d6a4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d6a8:	0fc355d7 */ 	jal	func0f0d575c
/*  f18d6ac:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f18d6b0:	02602025 */ 	or	$a0,$s3,$zero
.L0f18d6b4:
/*  f18d6b4:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f18d6b8:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d6bc:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f18d6c0:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f18d6c4:	3c010010 */ 	lui	$at,0x10
/*  f18d6c8:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d6cc:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d6d0:	14200003 */ 	bnez	$at,.L0f18d6e0
/*  f18d6d4:	3c09000f */ 	lui	$t1,0xf
/*  f18d6d8:	3525ffff */ 	ori	$a1,$t1,0xffff
/*  f18d6dc:	ae050054 */ 	sw	$a1,0x54($s0)
.L0f18d6e0:
/*  f18d6e0:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d6e4:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18d6e8:	8e050058 */ 	lw	$a1,0x58($s0)
/*  f18d6ec:	3c010010 */ 	lui	$at,0x10
/*  f18d6f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d6f4:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d6f8:	14200003 */ 	bnez	$at,.L0f18d708
/*  f18d6fc:	3c0a000f */ 	lui	$t2,0xf
/*  f18d700:	3545ffff */ 	ori	$a1,$t2,0xffff
/*  f18d704:	ae050058 */ 	sw	$a1,0x58($s0)
.L0f18d708:
/*  f18d708:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d70c:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18d710:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f18d714:	3c110008 */ 	lui	$s1,0x8
/*  f18d718:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d71c:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d720:	14200004 */ 	bnez	$at,.L0f18d734
/*  f18d724:	24060013 */ 	addiu	$a2,$zero,0x13
/*  f18d728:	3c120007 */ 	lui	$s2,0x7
/*  f18d72c:	3645ffff */ 	ori	$a1,$s2,0xffff
/*  f18d730:	ae05005c */ 	sw	$a1,0x5c($s0)
.L0f18d734:
/*  f18d734:	3c120007 */ 	lui	$s2,0x7
/*  f18d738:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d73c:	3652ffff */ 	ori	$s2,$s2,0xffff
/*  f18d740:	8e050060 */ 	lw	$a1,0x60($s0)
/*  f18d744:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d748:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d74c:	14200003 */ 	bnez	$at,.L0f18d75c
/*  f18d750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d754:	ae120060 */ 	sw	$s2,0x60($s0)
/*  f18d758:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d75c:
/*  f18d75c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d760:	24060013 */ 	addiu	$a2,$zero,0x13
/*  f18d764:	8e050064 */ 	lw	$a1,0x64($s0)
/*  f18d768:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d76c:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d770:	14200003 */ 	bnez	$at,.L0f18d780
/*  f18d774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d778:	ae120064 */ 	sw	$s2,0x64($s0)
/*  f18d77c:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d780:
/*  f18d780:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d784:	24060013 */ 	addiu	$a2,$zero,0x13
/*  f18d788:	8e05006c */ 	lw	$a1,0x6c($s0)
/*  f18d78c:	3c010200 */ 	lui	$at,0x200
/*  f18d790:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d794:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d798:	14200003 */ 	bnez	$at,.L0f18d7a8
/*  f18d79c:	3c0b01ff */ 	lui	$t3,0x1ff
/*  f18d7a0:	3565ffff */ 	ori	$a1,$t3,0xffff
/*  f18d7a4:	ae05006c */ 	sw	$a1,0x6c($s0)
.L0f18d7a8:
/*  f18d7a8:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d7ac:	24060019 */ 	addiu	$a2,$zero,0x19
/*  f18d7b0:	8e050070 */ 	lw	$a1,0x70($s0)
/*  f18d7b4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d7b8:	2ca10400 */ 	sltiu	$at,$a1,0x400
/*  f18d7bc:	14200003 */ 	bnez	$at,.L0f18d7cc
/*  f18d7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d7c4:	240503ff */ 	addiu	$a1,$zero,0x3ff
/*  f18d7c8:	ae050070 */ 	sw	$a1,0x70($s0)
.L0f18d7cc:
/*  f18d7cc:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d7d0:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f18d7d4:	8e050074 */ 	lw	$a1,0x74($s0)
/*  f18d7d8:	3c110400 */ 	lui	$s1,0x400
/*  f18d7dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d7e0:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d7e4:	14200003 */ 	bnez	$at,.L0f18d7f4
/*  f18d7e8:	3c0d03ff */ 	lui	$t5,0x3ff
/*  f18d7ec:	35a5ffff */ 	ori	$a1,$t5,0xffff
/*  f18d7f0:	ae050074 */ 	sw	$a1,0x74($s0)
.L0f18d7f4:
/*  f18d7f4:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d7f8:	2406001a */ 	addiu	$a2,$zero,0x1a
/*  f18d7fc:	8e050078 */ 	lw	$a1,0x78($s0)
/*  f18d800:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d804:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d808:	14200003 */ 	bnez	$at,.L0f18d818
/*  f18d80c:	3c0e03ff */ 	lui	$t6,0x3ff
/*  f18d810:	35c5ffff */ 	ori	$a1,$t6,0xffff
/*  f18d814:	ae050078 */ 	sw	$a1,0x78($s0)
.L0f18d818:
/*  f18d818:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d81c:	2406001a */ 	addiu	$a2,$zero,0x1a
/*  f18d820:	8e05007c */ 	lw	$a1,0x7c($s0)
/*  f18d824:	3c010010 */ 	lui	$at,0x10
/*  f18d828:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d82c:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d830:	14200003 */ 	bnez	$at,.L0f18d840
/*  f18d834:	3c0f000f */ 	lui	$t7,0xf
/*  f18d838:	35e5ffff */ 	ori	$a1,$t7,0xffff
/*  f18d83c:	ae05007c */ 	sw	$a1,0x7c($s0)
.L0f18d840:
/*  f18d840:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d844:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18d848:	8e050080 */ 	lw	$a1,0x80($s0)
/*  f18d84c:	3c014000 */ 	lui	$at,0x4000
/*  f18d850:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d854:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d858:	14200003 */ 	bnez	$at,.L0f18d868
/*  f18d85c:	3c183fff */ 	lui	$t8,0x3fff
/*  f18d860:	3705ffff */ 	ori	$a1,$t8,0xffff
/*  f18d864:	ae050080 */ 	sw	$a1,0x80($s0)
.L0f18d868:
/*  f18d868:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d86c:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f18d870:	8e050084 */ 	lw	$a1,0x84($s0)
/*  f18d874:	3c110004 */ 	lui	$s1,0x4
/*  f18d878:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d87c:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d880:	14200004 */ 	bnez	$at,.L0f18d894
/*  f18d884:	24060012 */ 	addiu	$a2,$zero,0x12
/*  f18d888:	3c120003 */ 	lui	$s2,0x3
/*  f18d88c:	3645ffff */ 	ori	$a1,$s2,0xffff
/*  f18d890:	ae050084 */ 	sw	$a1,0x84($s0)
.L0f18d894:
/*  f18d894:	3c120003 */ 	lui	$s2,0x3
/*  f18d898:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d89c:	3652ffff */ 	ori	$s2,$s2,0xffff
/*  f18d8a0:	8e050088 */ 	lw	$a1,0x88($s0)
/*  f18d8a4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d8a8:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d8ac:	14200003 */ 	bnez	$at,.L0f18d8bc
/*  f18d8b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d8b4:	ae120088 */ 	sw	$s2,0x88($s0)
/*  f18d8b8:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d8bc:
/*  f18d8bc:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d8c0:	24060012 */ 	addiu	$a2,$zero,0x12
/*  f18d8c4:	8e05008c */ 	lw	$a1,0x8c($s0)
/*  f18d8c8:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d8cc:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d8d0:	14200003 */ 	bnez	$at,.L0f18d8e0
/*  f18d8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d8d8:	ae12008c */ 	sw	$s2,0x8c($s0)
/*  f18d8dc:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d8e0:
/*  f18d8e0:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d8e4:	24060012 */ 	addiu	$a2,$zero,0x12
/*  f18d8e8:	8e050090 */ 	lw	$a1,0x90($s0)
/*  f18d8ec:	3c010001 */ 	lui	$at,0x1
/*  f18d8f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d8f4:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d8f8:	14200003 */ 	bnez	$at,.L0f18d908
/*  f18d8fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18d900:	3405ffff */ 	dli	$a1,0xffff
/*  f18d904:	ae050090 */ 	sw	$a1,0x90($s0)
.L0f18d908:
/*  f18d908:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d90c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f18d910:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d914:	92050044 */ 	lbu	$a1,0x44($s0)
/*  f18d918:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d91c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f18d920:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d924:	96050048 */ 	lhu	$a1,0x48($s0)
/*  f18d928:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d92c:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f18d930:	00008825 */ 	or	$s1,$zero,$zero
/*  f18d934:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f18d938:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f18d93c:
/*  f18d93c:	02802025 */ 	or	$a0,$s4,$zero
.L0f18d940:
/*  f18d940:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d944:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f18d948:	02003025 */ 	or	$a2,$s0,$zero
/*  f18d94c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d950:	00402825 */ 	or	$a1,$v0,$zero
/*  f18d954:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18d958:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18d95c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18d960:	5612fff7 */ 	bnel	$s0,$s2,.L0f18d940
/*  f18d964:	02802025 */ 	or	$a0,$s4,$zero
/*  f18d968:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d96c:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f18d970:	5621fff2 */ 	bnel	$s1,$at,.L0f18d93c
/*  f18d974:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18d978:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d97c:	0fc6348e */ 	jal	func0f18d238
/*  f18d980:	02802825 */ 	or	$a1,$s4,$zero
/*  f18d984:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18d988:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18d98c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18d990:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18d994:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18d998:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18d99c:	03e00008 */ 	jr	$ra
/*  f18d9a0:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f18d9a4
/*  f18d9a4:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f18d9a8:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f18d9ac:	00802825 */ 	or	$a1,$a0,$zero
/*  f18d9b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18d9b4:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f18d9b8:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f18d9bc:	2406000f */ 	addiu	$a2,$zero,0xf
/*  f18d9c0:	0fc35521 */ 	jal	func0f0d5484
/*  f18d9c4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18d9c8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18d9cc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f18d9d0:	0fc35539 */ 	jal	func0f0d54e4
/*  f18d9d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f18d9d8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18d9dc:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18d9e0:	2405001c */ 	addiu	$a1,$zero,0x1c
/*  f18d9e4:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f18d9e8:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f18d9ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18d9f0:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f18d9f4:	03e00008 */ 	jr	$ra
/*  f18d9f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18d9fc
/*  f18d9fc:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f18da00:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18da04:	afa40108 */ 	sw	$a0,0x108($sp)
/*  f18da08:	afa5010c */ 	sw	$a1,0x10c($sp)
/*  f18da0c:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f18da10:	04a00026 */ 	bltz	$a1,.L0f18daac
/*  f18da14:	afa70114 */ 	sw	$a3,0x114($sp)
/*  f18da18:	0fc35517 */ 	jal	func0f0d545c
/*  f18da1c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18da20:	8fa40108 */ 	lw	$a0,0x108($sp)
/*  f18da24:	0fc63571 */ 	jal	func0f18d5c4
/*  f18da28:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f18da2c:	0fc35531 */ 	jal	func0f0d54c4
/*  f18da30:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18da34:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18da38:	3c018007 */ 	lui	$at,0x8007
/*  f18da3c:	27b80100 */ 	addiu	$t8,$sp,0x100
/*  f18da40:	ac2f5bd8 */ 	sw	$t7,0x5bd8($at)
/*  f18da44:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18da48:	83a4010f */ 	lb	$a0,0x10f($sp)
/*  f18da4c:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f18da50:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f18da54:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f18da58:	0fc45a0a */ 	jal	func0f116828
/*  f18da5c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18da60:	1440000e */ 	bnez	$v0,.L0f18da9c
/*  f18da64:	00401825 */ 	or	$v1,$v0,$zero
/*  f18da68:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f18da6c:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers)
/*  f18da70:	8faa0100 */ 	lw	$t2,0x100($sp)
/*  f18da74:	00194080 */ 	sll	$t0,$t9,0x2
/*  f18da78:	01194021 */ 	addu	$t0,$t0,$t9
/*  f18da7c:	97ab0116 */ 	lhu	$t3,0x116($sp)
/*  f18da80:	00084140 */ 	sll	$t0,$t0,0x5
/*  f18da84:	2529c7b8 */ 	addiu	$t1,$t1,%lo(g_MpPlayers)
/*  f18da88:	01091821 */ 	addu	$v1,$t0,$t1
/*  f18da8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18da90:	ac6a004c */ 	sw	$t2,0x4c($v1)
/*  f18da94:	10000006 */ 	beqz	$zero,.L0f18dab0
/*  f18da98:	a46b0050 */ 	sh	$t3,0x50($v1)
.L0f18da9c:
/*  f18da9c:	3c01800a */ 	lui	$at,0x800a
/*  f18daa0:	ac2321f8 */ 	sw	$v1,0x21f8($at)
/*  f18daa4:	10000002 */ 	beqz	$zero,.L0f18dab0
/*  f18daa8:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18daac:
/*  f18daac:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18dab0:
/*  f18dab0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18dab4:	27bd0108 */ 	addiu	$sp,$sp,0x108
/*  f18dab8:	03e00008 */ 	jr	$ra
/*  f18dabc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18dac0
/*  f18dac0:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f18dac4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18dac8:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f18dacc:	afa50104 */ 	sw	$a1,0x104($sp)
/*  f18dad0:	afa60108 */ 	sw	$a2,0x108($sp)
/*  f18dad4:	04a00024 */ 	bltz	$a1,.L0f18db68
/*  f18dad8:	afa7010c */ 	sw	$a3,0x10c($sp)
/*  f18dadc:	0fc35517 */ 	jal	func0f0d545c
/*  f18dae0:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18dae4:	83a40107 */ 	lb	$a0,0x107($sp)
/*  f18dae8:	8fa50108 */ 	lw	$a1,0x108($sp)
/*  f18daec:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f18daf0:	0fc45a00 */ 	jal	func0f116800
/*  f18daf4:	00003825 */ 	or	$a3,$zero,$zero
/*  f18daf8:	14400017 */ 	bnez	$v0,.L0f18db58
/*  f18dafc:	00401825 */ 	or	$v1,$v0,$zero
/*  f18db00:	8fa40100 */ 	lw	$a0,0x100($sp)
/*  f18db04:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f18db08:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f18db0c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f18db10:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f18db14:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f18db18:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f18db1c:	97a8010e */ 	lhu	$t0,0x10e($sp)
/*  f18db20:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f18db24:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f18db28:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*  f18db2c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18db30:	ac79004c */ 	sw	$t9,0x4c($v1)
/*  f18db34:	0fc634ae */ 	jal	func0f18d2b8
/*  f18db38:	a4680050 */ 	sh	$t0,0x50($v1)
/*  f18db3c:	0fc35531 */ 	jal	func0f0d54c4
/*  f18db40:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18db44:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f18db48:	24090080 */ 	addiu	$t1,$zero,0x80
/*  f18db4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18db50:	10000006 */ 	beqz	$zero,.L0f18db6c
/*  f18db54:	a069009d */ 	sb	$t1,0x9d($v1)
.L0f18db58:
/*  f18db58:	3c01800a */ 	lui	$at,0x800a
/*  f18db5c:	ac2321f8 */ 	sw	$v1,0x21f8($at)
/*  f18db60:	10000002 */ 	beqz	$zero,.L0f18db6c
/*  f18db64:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18db68:
/*  f18db68:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18db6c:
/*  f18db6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18db70:	27bd0100 */ 	addiu	$sp,$sp,0x100
/*  f18db74:	03e00008 */ 	jr	$ra
/*  f18db78:	00000000 */ 	sll	$zero,$zero,0x0
);

u32 mpGetNumPresets(void)
{
	return NUM_MPPRESETS;
}

bool mpIsPresetUnlocked(s32 presetnum)
{
	s32 i;

	for (i = 0; i != 16; i++) {
		if (!mpIsChallengeComplete(g_MpPresets[presetnum].challenges[i]) &&
				g_MpPresets[presetnum].challenges[i] != 22) {
			return false;
		}
	}

	return true;
}

s32 mpGetNumUnlockedPresets(void)
{
	s32 numunlocked = 0;
	s32 i;

	for (i = 0; i != NUM_MPPRESETS; i++) {
		if (mpIsPresetUnlocked(i)) {
			numunlocked++;
		}
	}

	return numunlocked;
}

GLOBAL_ASM(
glabel mpGetPresetNameBySlot
/*  f18dc64:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18dc68:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18dc6c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18dc70:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18dc74:	00808825 */ 	or	$s1,$a0,$zero
/*  f18dc78:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18dc7c:	00008025 */ 	or	$s0,$zero,$zero
/*  f18dc80:	2412000e */ 	addiu	$s2,$zero,0xe
.L0f18dc84:
/*  f18dc84:	0fc636e1 */ 	jal	mpIsPresetUnlocked
/*  f18dc88:	02002025 */ 	or	$a0,$s0,$zero
/*  f18dc8c:	5040000d */ 	beqzl	$v0,.L0f18dcc4
/*  f18dc90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18dc94:	16200009 */ 	bnez	$s1,.L0f18dcbc
/*  f18dc98:	00107080 */ 	sll	$t6,$s0,0x2
/*  f18dc9c:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18dca0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f18dca4:	3c048008 */ 	lui	$a0,%hi(g_MpPresets)
/*  f18dca8:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f18dcac:	0fc5b9f1 */ 	jal	langGet
/*  f18dcb0:	94847b6c */ 	lhu	$a0,%lo(g_MpPresets)($a0)
/*  f18dcb4:	10000008 */ 	beqz	$zero,.L0f18dcd8
/*  f18dcb8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f18dcbc:
/*  f18dcbc:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f18dcc0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18dcc4:
/*  f18dcc4:	1612ffef */ 	bne	$s0,$s2,.L0f18dc84
/*  f18dcc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18dccc:	3c027f1c */ 	lui	$v0,%hi(var7f1b8c3c)
/*  f18dcd0:	24428c3c */ 	addiu	$v0,$v0,%lo(var7f1b8c3c)
/*  f18dcd4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f18dcd8:
/*  f18dcd8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18dcdc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18dce0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18dce4:	03e00008 */ 	jr	$ra
/*  f18dce8:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18dcec
/*  f18dcec:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f18dcf0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18dcf4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18dcf8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18dcfc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18dd00:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18dd04:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18dd08:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18dd0c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18dd10:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18dd14:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18dd18:	908e0010 */ 	lbu	$t6,0x10($a0)
/*  f18dd1c:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f18dd20:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
/*  f18dd24:	0080f025 */ 	or	$s8,$a0,$zero
/*  f18dd28:	0fc61521 */ 	jal	scenarioInit
/*  f18dd2c:	a20e0010 */ 	sb	$t6,0x10($s0)
/*  f18dd30:	03c0c825 */ 	or	$t9,$s8,$zero
/*  f18dd34:	02004025 */ 	or	$t0,$s0,$zero
/*  f18dd38:	27d80024 */ 	addiu	$t8,$s8,0x24
.L0f18dd3c:
/*  f18dd3c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f18dd40:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f18dd44:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f18dd48:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f18dd4c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f18dd50:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f18dd54:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f18dd58:	1738fff8 */ 	bne	$t9,$t8,.L0f18dd3c
/*  f18dd5c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f18dd60:	8f210000 */ 	lw	$at,0x0($t9)
/*  f18dd64:	3c09800b */ 	lui	$t1,0x800b
/*  f18dd68:	2537c798 */ 	addiu	$s7,$t1,-14440
/*  f18dd6c:	3c11800b */ 	lui	$s1,%hi(g_MpSimulants)
/*  f18dd70:	2631c538 */ 	addiu	$s1,$s1,%lo(g_MpSimulants)
/*  f18dd74:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f18dd78:	00009825 */ 	or	$s3,$zero,$zero
/*  f18dd7c:	03c0a025 */ 	or	$s4,$s8,$zero
/*  f18dd80:	03c0b025 */ 	or	$s6,$s8,$zero
/*  f18dd84:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f18dd88:	ad010000 */ 	sw	$at,0x0($t0)
.L0f18dd8c:
/*  f18dd8c:	928a0028 */ 	lbu	$t2,0x28($s4)
/*  f18dd90:	00001025 */ 	or	$v0,$zero,$zero
/*  f18dd94:	02a01825 */ 	or	$v1,$s5,$zero
/*  f18dd98:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18dd9c:	a22a0047 */ 	sb	$t2,0x47($s1)
.L0f18dda0:
/*  f18dda0:	908b002c */ 	lbu	$t3,0x2c($a0)
/*  f18dda4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18dda8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18ddac:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18ddb0:	1450fffb */ 	bne	$v0,$s0,.L0f18dda0
/*  f18ddb4:	a06bffff */ 	sb	$t3,-0x1($v1)
/*  f18ddb8:	92ec0000 */ 	lbu	$t4,0x0($s7)
/*  f18ddbc:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f18ddc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18ddc4:	a22c0048 */ 	sb	$t4,0x48($s1)
/*  f18ddc8:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f18ddcc:	00137100 */ 	sll	$t6,$s3,0x4
/*  f18ddd0:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f18ddd4:	15a1000a */ 	bne	$t5,$at,.L0f18de00
/*  f18ddd8:	02202025 */ 	or	$a0,$s1,$zero
/*  f18dddc:	0fc5b9f1 */ 	jal	langGet
/*  f18dde0:	240454f1 */ 	addiu	$a0,$zero,0x54f1
/*  f18dde4:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18dde8:	02403025 */ 	or	$a2,$s2,$zero
/*  f18ddec:	02202025 */ 	or	$a0,$s1,$zero
/*  f18ddf0:	0c004dad */ 	jal	sprintf
/*  f18ddf4:	00402825 */ 	or	$a1,$v0,$zero
/*  f18ddf8:	10000006 */ 	beqz	$zero,.L0f18de14
/*  f18ddfc:	928f0029 */ 	lbu	$t7,0x29($s4)
.L0f18de00:
/*  f18de00:	03ce2821 */ 	addu	$a1,$s8,$t6
/*  f18de04:	0c004c4c */ 	jal	strcpy
/*  f18de08:	24a50130 */ 	addiu	$a1,$a1,0x130
/*  f18de0c:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18de10:	928f0029 */ 	lbu	$t7,0x29($s4)
.L0f18de14:
/*  f18de14:	2a410008 */ 	slti	$at,$s2,0x8
/*  f18de18:	02409825 */ 	or	$s3,$s2,$zero
/*  f18de1c:	a22f000f */ 	sb	$t7,0xf($s1)
/*  f18de20:	9298002a */ 	lbu	$t8,0x2a($s4)
/*  f18de24:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f18de28:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f18de2c:	a238ffc4 */ 	sb	$t8,-0x3c($s1)
/*  f18de30:	92990023 */ 	lbu	$t9,0x23($s4)
/*  f18de34:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f18de38:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f18de3c:	26f70004 */ 	addiu	$s7,$s7,0x4
/*  f18de40:	1420ffd2 */ 	bnez	$at,.L0f18dd8c
/*  f18de44:	a239ffc5 */ 	sb	$t9,-0x3b($s1)
/*  f18de48:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18de4c:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f18de50:	1440000c */ 	bnez	$v0,.L0f18de84
/*  f18de54:	3c04800b */ 	lui	$a0,0x800b
/*  f18de58:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18de5c:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18de60:	2484cb8e */ 	addiu	$a0,$a0,-13426
/*  f18de64:	24030025 */ 	addiu	$v1,$zero,0x25
/*  f18de68:	90480018 */ 	lbu	$t0,0x18($v0)
.L0f18de6c:
/*  f18de6c:	54680003 */ 	bnel	$v1,$t0,.L0f18de7c
/*  f18de70:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18de74:	a0400018 */ 	sb	$zero,0x18($v0)
/*  f18de78:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f18de7c:
/*  f18de7c:	5444fffb */ 	bnel	$v0,$a0,.L0f18de6c
/*  f18de80:	90480018 */ 	lbu	$t0,0x18($v0)
.L0f18de84:
/*  f18de84:	0fc6244f */ 	jal	func0f18913c
/*  f18de88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18de8c:	0fc67064 */ 	jal	func0f19c190
/*  f18de90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18de94:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18de98:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18de9c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18dea0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18dea4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18dea8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18deac:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18deb0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18deb4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18deb8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18debc:	03e00008 */ 	jr	$ra
/*  f18dec0:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f18dec4
/*  f18dec4:	27bdfe00 */ 	addiu	$sp,$sp,-512
/*  f18dec8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18decc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ded0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ded4:	00808825 */ 	or	$s1,$a0,$zero
/*  f18ded8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18dedc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f18dee0:	00008025 */ 	or	$s0,$zero,$zero
/*  f18dee4:	2412000e */ 	addiu	$s2,$zero,0xe
.L0f18dee8:
/*  f18dee8:	0fc636e1 */ 	jal	mpIsPresetUnlocked
/*  f18deec:	02002025 */ 	or	$a0,$s0,$zero
/*  f18def0:	5040000c */ 	beqzl	$v0,.L0f18df24
/*  f18def4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18def8:	16200008 */ 	bnez	$s1,.L0f18df1c
/*  f18defc:	00107080 */ 	sll	$t6,$s0,0x2
/*  f18df00:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18df04:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f18df08:	3c0f8008 */ 	lui	$t7,0x8008
/*  f18df0c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f18df10:	8def7b70 */ 	lw	$t7,0x7b70($t7)
/*  f18df14:	10000005 */ 	beqz	$zero,.L0f18df2c
/*  f18df18:	afaf002c */ 	sw	$t7,0x2c($sp)
.L0f18df1c:
/*  f18df1c:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f18df20:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18df24:
/*  f18df24:	1612fff0 */ 	bne	$s0,$s2,.L0f18dee8
/*  f18df28:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18df2c:
/*  f18df2c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f18df30:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f18df34:	0fc66e45 */ 	jal	func0f19b914
/*  f18df38:	240601ca */ 	addiu	$a2,$zero,0x1ca
/*  f18df3c:	0fc6373b */ 	jal	func0f18dcec
/*  f18df40:	00402025 */ 	or	$a0,$v0,$zero
/*  f18df44:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18df48:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18df4c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18df50:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18df54:	03e00008 */ 	jr	$ra
/*  f18df58:	27bd0200 */ 	addiu	$sp,$sp,0x200
);

GLOBAL_ASM(
glabel func0f18df5c
/*  f18df5c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18df60:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18df64:	3c15800b */ 	lui	$s5,%hi(g_MpSetup)
/*  f18df68:	26b5cb88 */ 	addiu	$s5,$s5,%lo(g_MpSetup)
/*  f18df6c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18df70:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18df74:	00809825 */ 	or	$s3,$a0,$zero
/*  f18df78:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18df7c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18df80:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18df84:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18df88:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18df8c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f18df90:	0fc35539 */ 	jal	func0f0d54e4
/*  f18df94:	00003025 */ 	or	$a2,$zero,$zero
/*  f18df98:	02602025 */ 	or	$a0,$s3,$zero
/*  f18df9c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18dfa0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f18dfa4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfa8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18dfac:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18dfb0:	a2a20011 */ 	sb	$v0,0x11($s5)
/*  f18dfb4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfb8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18dfbc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18dfc0:	0fc61521 */ 	jal	scenarioInit
/*  f18dfc4:	a2a20010 */ 	sb	$v0,0x10($s5)
/*  f18dfc8:	0fc614f4 */ 	jal	scenarioCallback40
/*  f18dfcc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfd0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfd4:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18dfd8:	24050015 */ 	addiu	$a1,$zero,0x15
/*  f18dfdc:	96ae0016 */ 	lhu	$t6,0x16($s5)
/*  f18dfe0:	3c11800b */ 	lui	$s1,%hi(g_MpSimulants)
/*  f18dfe4:	3c14800b */ 	lui	$s4,%hi(var800ac798)
/*  f18dfe8:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f18dfec:	aea2000c */ 	sw	$v0,0xc($s5)
/*  f18dff0:	a6af0016 */ 	sh	$t7,0x16($s5)
/*  f18dff4:	2694c798 */ 	addiu	$s4,$s4,%lo(var800ac798)
/*  f18dff8:	2631c538 */ 	addiu	$s1,$s1,%lo(g_MpSimulants)
/*  f18dffc:	00009025 */ 	or	$s2,$zero,$zero
/*  f18e000:	24160006 */ 	addiu	$s6,$zero,0x6
/*  f18e004:	24100004 */ 	addiu	$s0,$zero,0x4
.L0f18e008:
/*  f18e008:	a2200000 */ 	sb	$zero,0x0($s1)
/*  f18e00c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e010:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e014:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f18e018:	a2220047 */ 	sb	$v0,0x47($s1)
/*  f18e01c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e020:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e024:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e028:	a2220048 */ 	sb	$v0,0x48($s1)
/*  f18e02c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18e030:	02802025 */ 	or	$a0,$s4,$zero
/*  f18e034:	304500ff */ 	andi	$a1,$v0,0xff
.L0f18e038:
/*  f18e038:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18e03c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18e040:	1470fffd */ 	bne	$v1,$s0,.L0f18e038
/*  f18e044:	a085ffff */ 	sb	$a1,-0x1($a0)
/*  f18e048:	12c50007 */ 	beq	$s6,$a1,.L0f18e068
/*  f18e04c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e050:	96b80016 */ 	lhu	$t8,0x16($s5)
/*  f18e054:	26590004 */ 	addiu	$t9,$s2,0x4
/*  f18e058:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18e05c:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f18e060:	03095025 */ 	or	$t2,$t8,$t1
/*  f18e064:	a6aa0016 */ 	sh	$t2,0x16($s5)
.L0f18e068:
/*  f18e068:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e06c:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e070:	a222000f */ 	sb	$v0,0xf($s1)
/*  f18e074:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e078:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e07c:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e080:	a2220010 */ 	sb	$v0,0x10($s1)
/*  f18e084:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e088:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e08c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e090:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18e094:	2a410008 */ 	slti	$at,$s2,0x8
/*  f18e098:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f18e09c:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f18e0a0:	1420ffd9 */ 	bnez	$at,.L0f18e008
/*  f18e0a4:	a222ffc5 */ 	sb	$v0,-0x3b($s1)
/*  f18e0a8:	0fc63377 */ 	jal	func0f18cddc
/*  f18e0ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e0b0:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f18e0b4:	3c11800b */ 	lui	$s1,0x800b
/*  f18e0b8:	2631cb8e */ 	addiu	$s1,$s1,-13426
/*  f18e0bc:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
.L0f18e0c0:
/*  f18e0c0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e0c4:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e0c8:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e0cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18e0d0:	0211082b */ 	sltu	$at,$s0,$s1
/*  f18e0d4:	1420fffa */ 	bnez	$at,.L0f18e0c0
/*  f18e0d8:	a2020017 */ 	sb	$v0,0x17($s0)
/*  f18e0dc:	0fc6244f */ 	jal	func0f18913c
/*  f18e0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e0e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e0e8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e0ec:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f18e0f0:	a2a20012 */ 	sb	$v0,0x12($s5)
/*  f18e0f4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e0f8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e0fc:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e100:	a2a20013 */ 	sb	$v0,0x13($s5)
/*  f18e104:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e108:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e10c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18e110:	3c10800b */ 	lui	$s0,%hi(g_MpPlayers)
/*  f18e114:	3c11800b */ 	lui	$s1,%hi(var800aca38)
/*  f18e118:	a6a20014 */ 	sh	$v0,0x14($s5)
/*  f18e11c:	2631ca38 */ 	addiu	$s1,$s1,%lo(var800aca38)
/*  f18e120:	2610c7b8 */ 	addiu	$s0,$s0,%lo(g_MpPlayers)
.L0f18e124:
/*  f18e124:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e128:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e12c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e130:	261000a0 */ 	addiu	$s0,$s0,0xa0
/*  f18e134:	1611fffb */ 	bne	$s0,$s1,.L0f18e124
/*  f18e138:	a202ff71 */ 	sb	$v0,-0x8f($s0)
/*  f18e13c:	0fc66fe8 */ 	jal	func0f19bfa0
/*  f18e140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e144:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18e148:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18e14c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18e150:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18e154:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18e158:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18e15c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18e160:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18e164:	03e00008 */ 	jr	$ra
/*  f18e168:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f18e16c
/*  f18e16c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18e170:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18e174:	3c13800b */ 	lui	$s3,%hi(g_MpSetup)
/*  f18e178:	2673cb88 */ 	addiu	$s3,$s3,%lo(g_MpSetup)
/*  f18e17c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18e180:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18e184:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18e188:	00809025 */ 	or	$s2,$a0,$zero
/*  f18e18c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18e190:	00008025 */ 	or	$s0,$zero,$zero
/*  f18e194:	0fc35569 */ 	jal	func0f0d55a4
/*  f18e198:	02602825 */ 	or	$a1,$s3,$zero
/*  f18e19c:	00008825 */ 	or	$s1,$zero,$zero
/*  f18e1a0:	96620016 */ 	lhu	$v0,0x16($s3)
/*  f18e1a4:	262e0004 */ 	addiu	$t6,$s1,0x4
.L0f18e1a8:
/*  f18e1a8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18e1ac:	01cfc004 */ 	sllv	$t8,$t7,$t6
/*  f18e1b0:	0058c824 */ 	and	$t9,$v0,$t8
/*  f18e1b4:	13200002 */ 	beqz	$t9,.L0f18e1c0
/*  f18e1b8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18e1bc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18e1c0:
/*  f18e1c0:	2a210008 */ 	slti	$at,$s1,0x8
/*  f18e1c4:	5420fff8 */ 	bnezl	$at,.L0f18e1a8
/*  f18e1c8:	262e0004 */ 	addiu	$t6,$s1,0x4
/*  f18e1cc:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e1d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f18e1d4:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e1d8:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f18e1dc:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e1e0:	92650011 */ 	lbu	$a1,0x11($s3)
/*  f18e1e4:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e1e8:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e1ec:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e1f0:	92650010 */ 	lbu	$a1,0x10($s3)
/*  f18e1f4:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e1f8:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e1fc:	0fc6150a */ 	jal	scenarioCallback44
/*  f18e200:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e204:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e208:	8e65000c */ 	lw	$a1,0xc($s3)
/*  f18e20c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e210:	24060015 */ 	addiu	$a2,$zero,0x15
/*  f18e214:	3c10800b */ 	lui	$s0,%hi(g_MpSimulants)
/*  f18e218:	2610c538 */ 	addiu	$s0,$s0,%lo(g_MpSimulants)
/*  f18e21c:	00008825 */ 	or	$s1,$zero,$zero
.L0f18e220:
/*  f18e220:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e224:	92050047 */ 	lbu	$a1,0x47($s0)
/*  f18e228:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e22c:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f18e230:	96680016 */ 	lhu	$t0,0x16($s3)
/*  f18e234:	26290004 */ 	addiu	$t1,$s1,0x4
/*  f18e238:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f18e23c:	012a5804 */ 	sllv	$t3,$t2,$t1
/*  f18e240:	010b6024 */ 	and	$t4,$t0,$t3
/*  f18e244:	11800007 */ 	beqz	$t4,.L0f18e264
/*  f18e248:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e24c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e250:	92050048 */ 	lbu	$a1,0x48($s0)
/*  f18e254:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e258:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e25c:	10000005 */ 	beqz	$zero,.L0f18e274
/*  f18e260:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e264:
/*  f18e264:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f18e268:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e26c:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e270:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e274:
/*  f18e274:	9205000f */ 	lbu	$a1,0xf($s0)
/*  f18e278:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e27c:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e280:	92020010 */ 	lbu	$v0,0x10($s0)
/*  f18e284:	240100ff */ 	addiu	$at,$zero,0xff
/*  f18e288:	1441000f */ 	bne	$v0,$at,.L0f18e2c8
/*  f18e28c:	00402825 */ 	or	$a1,$v0,$zero
/*  f18e290:	92040047 */ 	lbu	$a0,0x47($s0)
/*  f18e294:	0fc6335a */ 	jal	func0f18cd68
/*  f18e298:	92050048 */ 	lbu	$a1,0x48($s0)
/*  f18e29c:	04400004 */ 	bltz	$v0,.L0f18e2b0
/*  f18e2a0:	00401825 */ 	or	$v1,$v0,$zero
/*  f18e2a4:	28410012 */ 	slti	$at,$v0,0x12
/*  f18e2a8:	54200003 */ 	bnezl	$at,.L0f18e2b8
/*  f18e2ac:	000368c0 */ 	sll	$t5,$v1,0x3
.L0f18e2b0:
/*  f18e2b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f18e2b4:	000368c0 */ 	sll	$t5,$v1,0x3
.L0f18e2b8:
/*  f18e2b8:	3c058008 */ 	lui	$a1,0x8008
/*  f18e2bc:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f18e2c0:	10000001 */ 	beqz	$zero,.L0f18e2c8
/*  f18e2c4:	84a57730 */ 	lh	$a1,0x7730($a1)
.L0f18e2c8:
/*  f18e2c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e2cc:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e2d0:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e2d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e2d8:	92050011 */ 	lbu	$a1,0x11($s0)
/*  f18e2dc:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e2e0:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e2e4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18e2e8:	2a210008 */ 	slti	$at,$s1,0x8
/*  f18e2ec:	1420ffcc */ 	bnez	$at,.L0f18e220
/*  f18e2f0:	2610004c */ 	addiu	$s0,$s0,0x4c
/*  f18e2f4:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f18e2f8:	3c11800b */ 	lui	$s1,0x800b
/*  f18e2fc:	2631cb8e */ 	addiu	$s1,$s1,-13426
/*  f18e300:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
/*  f18e304:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e308:
/*  f18e308:	92050018 */ 	lbu	$a1,0x18($s0)
/*  f18e30c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e310:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e314:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18e318:	0211082b */ 	sltu	$at,$s0,$s1
/*  f18e31c:	5420fffa */ 	bnezl	$at,.L0f18e308
/*  f18e320:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e324:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e328:	92650012 */ 	lbu	$a1,0x12($s3)
/*  f18e32c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e330:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f18e334:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e338:	92650013 */ 	lbu	$a1,0x13($s3)
/*  f18e33c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e340:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e344:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e348:	96650014 */ 	lhu	$a1,0x14($s3)
/*  f18e34c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e350:	24060009 */ 	addiu	$a2,$zero,0x9
/*  f18e354:	3c10800b */ 	lui	$s0,%hi(g_MpPlayers)
/*  f18e358:	3c11800b */ 	lui	$s1,%hi(var800aca38)
/*  f18e35c:	2631ca38 */ 	addiu	$s1,$s1,%lo(var800aca38)
/*  f18e360:	2610c7b8 */ 	addiu	$s0,$s0,%lo(g_MpPlayers)
/*  f18e364:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e368:
/*  f18e368:	92050011 */ 	lbu	$a1,0x11($s0)
/*  f18e36c:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f18e370:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e374:	261000a0 */ 	addiu	$s0,$s0,0xa0
/*  f18e378:	5611fffb */ 	bnel	$s0,$s1,.L0f18e368
/*  f18e37c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e380:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18e384:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18e388:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18e38c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18e390:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18e394:	03e00008 */ 	jr	$ra
/*  f18e398:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18e39c
/*  f18e39c:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f18e3a0:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f18e3a4:	00802825 */ 	or	$a1,$a0,$zero
/*  f18e3a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18e3ac:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f18e3b0:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f18e3b4:	afa70104 */ 	sw	$a3,0x104($sp)
/*  f18e3b8:	2406000f */ 	addiu	$a2,$zero,0xf
/*  f18e3bc:	0fc35521 */ 	jal	func0f0d5484
/*  f18e3c0:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3c4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3c8:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f18e3cc:	0fc35539 */ 	jal	func0f0d54e4
/*  f18e3d0:	00003025 */ 	or	$a2,$zero,$zero
/*  f18e3d4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3d8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e3dc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f18e3e0:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f18e3e4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3e8:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e3ec:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e3f0:	a5c20000 */ 	sh	$v0,0x0($t6)
/*  f18e3f4:	8faf0104 */ 	lw	$t7,0x104($sp)
/*  f18e3f8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3fc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e400:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f18e404:	a5e20000 */ 	sh	$v0,0x0($t7)
/*  f18e408:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f18e40c:	a7020000 */ 	sh	$v0,0x0($t8)
/*  f18e410:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18e414:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f18e418:	03e00008 */ 	jr	$ra
/*  f18e41c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18e420
/*  f18e420:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f18e424:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18e428:	afa40108 */ 	sw	$a0,0x108($sp)
/*  f18e42c:	afa5010c */ 	sw	$a1,0x10c($sp)
/*  f18e430:	04800020 */ 	bltz	$a0,.L0f18e4b4
/*  f18e434:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f18e438:	0fc35517 */ 	jal	func0f0d545c
/*  f18e43c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18e440:	0fc6385b */ 	jal	func0f18e16c
/*  f18e444:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18e448:	0fc35531 */ 	jal	func0f0d54c4
/*  f18e44c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18e450:	27af0100 */ 	addiu	$t7,$sp,0x100
/*  f18e454:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18e458:	83a4010b */ 	lb	$a0,0x10b($sp)
/*  f18e45c:	8fa5010c */ 	lw	$a1,0x10c($sp)
/*  f18e460:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f18e464:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f18e468:	0fc45a0a */ 	jal	func0f116828
/*  f18e46c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18e470:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18e474:	3c018007 */ 	lui	$at,0x8007
/*  f18e478:	00401825 */ 	or	$v1,$v0,$zero
/*  f18e47c:	14400009 */ 	bnez	$v0,.L0f18e4a4
/*  f18e480:	ac385bd4 */ 	sw	$t8,0x5bd4($at)
/*  f18e484:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f18e488:	97a80112 */ 	lhu	$t0,0x112($sp)
/*  f18e48c:	3c03800b */ 	lui	$v1,%hi(g_MpSetup)
/*  f18e490:	2463cb88 */ 	addiu	$v1,$v1,%lo(g_MpSetup)
/*  f18e494:	00001025 */ 	or	$v0,$zero,$zero
/*  f18e498:	ac790020 */ 	sw	$t9,0x20($v1)
/*  f18e49c:	10000006 */ 	beqz	$zero,.L0f18e4b8
/*  f18e4a0:	a4680024 */ 	sh	$t0,0x24($v1)
.L0f18e4a4:
/*  f18e4a4:	3c01800a */ 	lui	$at,0x800a
/*  f18e4a8:	ac2321f8 */ 	sw	$v1,0x21f8($at)
/*  f18e4ac:	10000002 */ 	beqz	$zero,.L0f18e4b8
/*  f18e4b0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e4b4:
/*  f18e4b4:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e4b8:
/*  f18e4b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18e4bc:	27bd0108 */ 	addiu	$sp,$sp,0x108
/*  f18e4c0:	03e00008 */ 	jr	$ra
/*  f18e4c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18e4c8
/*  f18e4c8:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f18e4cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18e4d0:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f18e4d4:	afa50104 */ 	sw	$a1,0x104($sp)
/*  f18e4d8:	0480001a */ 	bltz	$a0,.L0f18e544
/*  f18e4dc:	afa60108 */ 	sw	$a2,0x108($sp)
/*  f18e4e0:	0fc35517 */ 	jal	func0f0d545c
/*  f18e4e4:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18e4e8:	83a40103 */ 	lb	$a0,0x103($sp)
/*  f18e4ec:	8fa50104 */ 	lw	$a1,0x104($sp)
/*  f18e4f0:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f18e4f4:	0fc45a00 */ 	jal	func0f116800
/*  f18e4f8:	00003825 */ 	or	$a3,$zero,$zero
/*  f18e4fc:	1440000d */ 	bnez	$v0,.L0f18e534
/*  f18e500:	00401825 */ 	or	$v1,$v0,$zero
/*  f18e504:	8faf0104 */ 	lw	$t7,0x104($sp)
/*  f18e508:	97b8010a */ 	lhu	$t8,0x10a($sp)
/*  f18e50c:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18e510:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18e514:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18e518:	ac4f0020 */ 	sw	$t7,0x20($v0)
/*  f18e51c:	0fc637d7 */ 	jal	func0f18df5c
/*  f18e520:	a4580024 */ 	sh	$t8,0x24($v0)
/*  f18e524:	0fc35531 */ 	jal	func0f0d54c4
/*  f18e528:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18e52c:	10000006 */ 	beqz	$zero,.L0f18e548
/*  f18e530:	00001025 */ 	or	$v0,$zero,$zero
.L0f18e534:
/*  f18e534:	3c01800a */ 	lui	$at,0x800a
/*  f18e538:	ac2321f8 */ 	sw	$v1,0x21f8($at)
/*  f18e53c:	10000002 */ 	beqz	$zero,.L0f18e548
/*  f18e540:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e544:
/*  f18e544:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e548:
/*  f18e548:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18e54c:	27bd0100 */ 	addiu	$sp,$sp,0x100
/*  f18e550:	03e00008 */ 	jr	$ra
/*  f18e554:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18e558
/*  f18e558:	3c03800b */ 	lui	$v1,%hi(var800acc28)
/*  f18e55c:	3c02800b */ 	lui	$v0,%hi(var800acc70)
/*  f18e560:	2442cc70 */ 	addiu	$v0,$v0,%lo(var800acc70)
/*  f18e564:	2463cc28 */ 	addiu	$v1,$v1,%lo(var800acc28)
.L0f18e568:
/*  f18e568:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f18e56c:	1462fffe */ 	bne	$v1,$v0,.L0f18e568
/*  f18e570:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f18e574:	03e00008 */ 	jr	$ra
/*  f18e578:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18e57c
/*  f18e57c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18e580:	3c02800b */ 	lui	$v0,%hi(var800acc28)
/*  f18e584:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f18e588:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f18e58c:	03e00008 */ 	jr	$ra
/*  f18e590:	8c42cc28 */ 	lw	$v0,%lo(var800acc28)($v0)
/*  f18e594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e59c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e5a0:	3c018008 */ 	lui	$at,0x8008
/*  f18e5a4:	03e00008 */ 	jr	$ra
/*  f18e5a8:	ac247cc0 */ 	sw	$a0,0x7cc0($at)
);

GLOBAL_ASM(
glabel func0f18e5ac
/*  f18e5ac:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f18e5b0:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f18e5b4:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f18e5b8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f18e5bc:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f18e5c0:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f18e5c4:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f18e5c8:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e5cc:	3c18ba00 */ 	lui	$t8,0xba00
/*  f18e5d0:	37180602 */ 	ori	$t8,$t8,0x602
/*  f18e5d4:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f18e5d8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f18e5dc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f18e5e0:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f18e5e4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f18e5e8:	358c1301 */ 	ori	$t4,$t4,0x1301
/*  f18e5ec:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f18e5f0:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f18e5f4:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f18e5f8:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f18e5fc:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f18e600:	3c0fb900 */ 	lui	$t7,0xb900
/*  f18e604:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f18e608:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f18e60c:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e610:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f18e614:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f18e618:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e61c:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e620:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f18e624:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e628:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e62c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f18e630:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e634:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f18e638:	3c0dba00 */ 	lui	$t5,0xba00
/*  f18e63c:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f18e640:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f18e644:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f18e648:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f18e64c:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f18e650:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f18e654:	3c18ba00 */ 	lui	$t8,0xba00
/*  f18e658:	37180903 */ 	ori	$t8,$t8,0x903
/*  f18e65c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f18e660:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e664:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f18e668:	add90004 */ 	sw	$t9,0x4($t6)
/*  f18e66c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f18e670:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f18e674:	3c0cba00 */ 	lui	$t4,0xba00
/*  f18e678:	358c0e02 */ 	ori	$t4,$t4,0xe02
/*  f18e67c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f18e680:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f18e684:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f18e688:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f18e68c:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f18e690:	3c0fe700 */ 	lui	$t7,0xe700
/*  f18e694:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e698:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f18e69c:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e6a0:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f18e6a4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f18e6a8:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e6ac:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f18e6b0:	3c0db900 */ 	lui	$t5,0xb900
/*  f18e6b4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e6b8:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e6bc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f18e6c0:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e6c4:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f18e6c8:	3c0e0050 */ 	lui	$t6,0x50
/*  f18e6cc:	35ce4240 */ 	ori	$t6,$t6,0x4240
/*  f18e6d0:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f18e6d4:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f18e6d8:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f18e6dc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f18e6e0:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f18e6e4:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f18e6e8:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f18e6ec:	8fa700c0 */ 	lw	$a3,0xc0($sp)
/*  f18e6f0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f18e6f4:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f18e6f8:	3c0afffd */ 	lui	$t2,0xfffd
/*  f18e6fc:	3c19fcff */ 	lui	$t9,0xfcff
/*  f18e700:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f18e704:	354af6fb */ 	ori	$t2,$t2,0xf6fb
/*  f18e708:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f18e70c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f18e710:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f18e714:	3c0dfa00 */ 	lui	$t5,0xfa00
/*  f18e718:	00a08025 */ 	or	$s0,$a1,$zero
/*  f18e71c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f18e720:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f18e724:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f18e728:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f18e72c:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f18e730:	3c068008 */ 	lui	$a2,%hi(var8007fac0)
/*  f18e734:	24c6fac0 */ 	addiu	$a2,$a2,%lo(var8007fac0)
/*  f18e738:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f18e73c:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e740:	92050004 */ 	lbu	$a1,0x4($s0)
/*  f18e744:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f18e748:	3c01f600 */ 	lui	$at,0xf600
/*  f18e74c:	00a7c021 */ 	addu	$t8,$a1,$a3
/*  f18e750:	03190019 */ 	multu	$t8,$t9
/*  f18e754:	01257021 */ 	addu	$t6,$t1,$a1
/*  f18e758:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18e75c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f18e760:	312f03ff */ 	andi	$t7,$t1,0x3ff
/*  f18e764:	44894000 */ 	mtc1	$t1,$f8
/*  f18e768:	02002825 */ 	or	$a1,$s0,$zero
/*  f18e76c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f18e770:	00005012 */ 	mflo	$t2
/*  f18e774:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18e778:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f18e77c:	01816825 */ 	or	$t5,$t4,$at
/*  f18e780:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f18e784:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f18e788:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f18e78c:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f18e790:	00ea0019 */ 	multu	$a3,$t2
/*  f18e794:	00005812 */ 	mflo	$t3
/*  f18e798:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f18e79c:	000c7380 */ 	sll	$t6,$t4,0xe
/*  f18e7a0:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f18e7a4:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f18e7a8:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f18e7ac:	8fa200c8 */ 	lw	$v0,0xc8($sp)
/*  f18e7b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f18e7b4:	00e80019 */ 	multu	$a3,$t0
/*  f18e7b8:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f18e7bc:	00003825 */ 	or	$a3,$zero,$zero
/*  f18e7c0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f18e7c4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18e7c8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18e7cc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f18e7d0:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f18e7d4:	0000c812 */ 	mflo	$t9
/*  f18e7d8:	44992000 */ 	mtc1	$t9,$f4
/*  f18e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e7e0:	00480019 */ 	multu	$v0,$t0
/*  f18e7e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f18e7e8:	44822000 */ 	mtc1	$v0,$f4
/*  f18e7ec:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f18e7f0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f18e7f4:	00005012 */ 	mflo	$t2
/*  f18e7f8:	448a8000 */ 	mtc1	$t2,$f16
/*  f18e7fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e800:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f18e804:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f18e808:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f18e80c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f18e810:	920c0005 */ 	lbu	$t4,0x5($s0)
/*  f18e814:	92070004 */ 	lbu	$a3,0x4($s0)
/*  f18e818:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18e81c:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f18e820:	240d0028 */ 	addiu	$t5,$zero,0x28
/*  f18e824:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f18e828:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f18e82c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f18e830:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18e834:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18e838:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18e83c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18e840:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f18e844:	92180006 */ 	lbu	$t8,0x6($s0)
/*  f18e848:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f18e84c:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f18e850:	0018c82a */ 	slt	$t9,$zero,$t8
/*  f18e854:	afb90030 */ 	sw	$t9,0x30($sp)
/*  f18e858:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*  f18e85c:	0fc2c9e3 */ 	jal	func0f0b278c
/*  f18e860:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f18e864:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f18e868:	3c0ce700 */ 	lui	$t4,0xe700
/*  f18e86c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f18e870:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f18e874:	afab00b8 */ 	sw	$t3,0xb8($sp)
/*  f18e878:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f18e87c:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f18e880:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f18e884:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f18e888:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f18e88c:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f18e890:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e894:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f18e898:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f18e89c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f18e8a0:	3c0bba00 */ 	lui	$t3,0xba00
/*  f18e8a4:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f18e8a8:	272a0008 */ 	addiu	$t2,$t9,0x8
/*  f18e8ac:	afaa00b8 */ 	sw	$t2,0xb8($sp)
/*  f18e8b0:	3c0c0008 */ 	lui	$t4,0x8
/*  f18e8b4:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f18e8b8:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f18e8bc:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f18e8c0:	3c0db900 */ 	lui	$t5,0xb900
/*  f18e8c4:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f18e8c8:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f18e8cc:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f18e8d0:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f18e8d4:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f18e8d8:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e8dc:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e8e0:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f18e8e4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e8e8:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e8ec:	3c0b0001 */ 	lui	$t3,0x1
/*  f18e8f0:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f18e8f4:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e8f8:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f18e8fc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f18e900:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f18e904:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f18e908:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e90c:	240d2000 */ 	addiu	$t5,$zero,0x2000
/*  f18e910:	ad8d0004 */ 	sw	$t5,0x4($t4)
/*  f18e914:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f18e918:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f18e91c:	3c0aba00 */ 	lui	$t2,0xba00
/*  f18e920:	354a0903 */ 	ori	$t2,$t2,0x903
/*  f18e924:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f18e928:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f18e92c:	240b0c00 */ 	addiu	$t3,$zero,0xc00
/*  f18e930:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f18e934:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f18e938:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f18e93c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f18e940:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f18e944:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f18e948:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f18e94c:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f18e950:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f18e954:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f18e958:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f18e95c:	8fa200b8 */ 	lw	$v0,0xb8($sp)
/*  f18e960:	03e00008 */ 	jr	$ra
/*  f18e964:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

s32 teamGetIndex(s32 team)
{
	s32 index = 0;

	if (team & 1) {
		index = 0;
	} else if (team & 0x02) {
		index = 1;
	} else if (team & 0x04) {
		index = 2;
	} else if (team & 0x08) {
		index = 3;
	} else if (team & 0x10) {
		index = 4;
	} else if (team & 0x20) {
		index = 5;
	} else if (team & 0x40) {
		index = 6;
	} else if (team & 0x80) {
		index = 7;
	}

	return index;
}

GLOBAL_ASM(
glabel radarDrawDot
/*  f18e9ec:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f18e9f0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18e9f4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18e9f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18e9fc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ea00:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18ea04:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18ea08:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18ea0c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ea10:	afa700ec */ 	sw	$a3,0xec($sp)
/*  f18ea14:	00808025 */ 	or	$s0,$a0,$zero
/*  f18ea18:	00c09025 */ 	or	$s2,$a2,$zero
/*  f18ea1c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f18ea20:	c4ce0008 */ 	lwc1	$f14,0x8($a2)
/*  f18ea24:	0fc259d4 */ 	jal	func0f096750
/*  f18ea28:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f18ea2c:	3c014334 */ 	lui	$at,0x4334
/*  f18ea30:	44818000 */ 	mtc1	$at,$f16
/*  f18ea34:	3c017f1c */ 	lui	$at,%hi(var7f1b8dd8)
/*  f18ea38:	c4268dd8 */ 	lwc1	$f6,%lo(var7f1b8dd8)($at)
/*  f18ea3c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f18ea40:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f18ea44:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f18ea48:	8eae0284 */ 	lw	$t6,0x284($s5)
/*  f18ea4c:	c5ca0144 */ 	lwc1	$f10,0x144($t6)
/*  f18ea50:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f18ea54:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f18ea58:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f18ea5c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f18ea60:	c64e0008 */ 	lwc1	$f14,0x8($s2)
/*  f18ea64:	c6420000 */ 	lwc1	$f2,0x0($s2)
/*  f18ea68:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f18ea6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ea70:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f18ea74:	0c012974 */ 	jal	sqrtf
/*  f18ea78:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f18ea7c:	3c014180 */ 	lui	$at,0x4180
/*  f18ea80:	44816000 */ 	mtc1	$at,$f12
/*  f18ea84:	3c017f1c */ 	lui	$at,%hi(var7f1b8ddc)
/*  f18ea88:	c42a8ddc */ 	lwc1	$f10,%lo(var7f1b8ddc)($at)
/*  f18ea8c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f18ea90:	3c017f1c */ 	lui	$at,%hi(var7f1b8de0)
/*  f18ea94:	460a0382 */ 	mul.s	$f14,$f0,$f10
/*  f18ea98:	c7b200cc */ 	lwc1	$f18,0xcc($sp)
/*  f18ea9c:	460c703c */ 	c.lt.s	$f14,$f12
/*  f18eaa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18eaa4:	45020004 */ 	bc1fl	.L0f18eab8
/*  f18eaa8:	46006386 */ 	mov.s	$f14,$f12
/*  f18eaac:	10000002 */ 	beqz	$zero,.L0f18eab8
/*  f18eab0:	00009825 */ 	or	$s3,$zero,$zero
/*  f18eab4:	46006386 */ 	mov.s	$f14,$f12
.L0f18eab8:
/*  f18eab8:	c4248de0 */ 	lwc1	$f4,%lo(var7f1b8de0)($at)
/*  f18eabc:	e7ae00d0 */ 	swc1	$f14,0xd0($sp)
/*  f18eac0:	46049302 */ 	mul.s	$f12,$f18,$f4
/*  f18eac4:	0c0068f7 */ 	jal	fsin
/*  f18eac8:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f18eacc:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18ead0:	3c19800b */ 	lui	$t9,%hi(var800acc70)
/*  f18ead4:	8f39cc70 */ 	lw	$t9,%lo(var800acc70)($t9)
/*  f18ead8:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f18eadc:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f18eae0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f18eae4:	44184000 */ 	mfc1	$t8,$f8
/*  f18eae8:	0c0068f4 */ 	jal	fcos
/*  f18eaec:	03198821 */ 	addu	$s1,$t8,$t9
/*  f18eaf0:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18eaf4:	8fac00f4 */ 	lw	$t4,0xf4($sp)
/*  f18eaf8:	3c0b800b */ 	lui	$t3,%hi(var800acc74)
/*  f18eafc:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f18eb00:	8d6bcc74 */ 	lw	$t3,%lo(var800acc74)($t3)
/*  f18eb04:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f18eb08:	440a9000 */ 	mfc1	$t2,$f18
/*  f18eb0c:	118001a8 */ 	beqz	$t4,.L0f18f1b0
/*  f18eb10:	014ba021 */ 	addu	$s4,$t2,$t3
/*  f18eb14:	8ead0284 */ 	lw	$t5,0x284($s5)
/*  f18eb18:	02002025 */ 	or	$a0,$s0,$zero
/*  f18eb1c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18eb20:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f18eb24:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18eb28:	3c028008 */ 	lui	$v0,%hi(var80087cc0)
/*  f18eb2c:	16ce0086 */ 	bne	$s6,$t6,.L0f18ed48
/*  f18eb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18eb34:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18eb38:	0fc54df7 */ 	jal	func0f1537dc
/*  f18eb3c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18eb40:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18eb44:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18eb48:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18eb4c:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18eb50:	268d0003 */ 	addiu	$t5,$s4,0x3
/*  f18eb54:	02b90019 */ 	multu	$s5,$t9
/*  f18eb58:	3c13f600 */ 	lui	$s3,0xf600
/*  f18eb5c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18eb60:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18eb64:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18eb68:	26880002 */ 	addiu	$t0,$s4,0x2
/*  f18eb6c:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f18eb70:	00194080 */ 	sll	$t0,$t9,0x2
/*  f18eb74:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18eb78:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18eb7c:	00004812 */ 	mflo	$t1
/*  f18eb80:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f18eb84:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18eb88:	01736025 */ 	or	$t4,$t3,$s3
/*  f18eb8c:	018fc025 */ 	or	$t8,$t4,$t7
/*  f18eb90:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18eb94:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18eb98:	262f0002 */ 	addiu	$t7,$s1,0x2
/*  f18eb9c:	02ca0019 */ 	multu	$s6,$t2
/*  f18eba0:	00005812 */ 	mflo	$t3
/*  f18eba4:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18eba8:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f18ebac:	01c86025 */ 	or	$t4,$t6,$t0
/*  f18ebb0:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f18ebb4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ebb8:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f18ebbc:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f18ebc0:	01f80019 */ 	multu	$t7,$t8
/*  f18ebc4:	262ffffd */ 	addiu	$t7,$s1,-3
/*  f18ebc8:	0000c812 */ 	mflo	$t9
/*  f18ebcc:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ebd0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ebd4:	01535825 */ 	or	$t3,$t2,$s3
/*  f18ebd8:	01686825 */ 	or	$t5,$t3,$t0
/*  f18ebdc:	ac4d0008 */ 	sw	$t5,0x8($v0)
/*  f18ebe0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ebe4:	01f80019 */ 	multu	$t7,$t8
/*  f18ebe8:	0000c812 */ 	mflo	$t9
/*  f18ebec:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ebf0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ebf4:	01475825 */ 	or	$t3,$t2,$a3
/*  f18ebf8:	ac4b000c */ 	sw	$t3,0xc($v0)
/*  f18ebfc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18ec00:	02ad0019 */ 	multu	$s5,$t5
/*  f18ec04:	00007012 */ 	mflo	$t6
/*  f18ec08:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ec0c:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18ec10:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18ec14:	0307c825 */ 	or	$t9,$t8,$a3
/*  f18ec18:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f18ec1c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ec20:	268efffe */ 	addiu	$t6,$s4,-2
/*  f18ec24:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ec28:	02c90019 */ 	multu	$s6,$t1
/*  f18ec2c:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f18ec30:	00005012 */ 	mflo	$t2
/*  f18ec34:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18ec38:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18ec3c:	01afc025 */ 	or	$t8,$t5,$t7
/*  f18ec40:	ac580014 */ 	sw	$t8,0x14($v0)
/*  f18ec44:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f18ec48:	0fc54e0e */ 	jal	func0f153838
/*  f18ec4c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18ec50:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18ec54:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ec58:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ec5c:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18ec60:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ec64:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f18ec68:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18ec6c:	02290019 */ 	multu	$s1,$t1
/*  f18ec70:	2625ffff */ 	addiu	$a1,$s1,-1
/*  f18ec74:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18ec78:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f18ec7c:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f18ec80:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18ec84:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18ec88:	00005012 */ 	mflo	$t2
/*  f18ec8c:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18ec90:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18ec94:	01d36025 */ 	or	$t4,$t6,$s3
/*  f18ec98:	01886825 */ 	or	$t5,$t4,$t0
/*  f18ec9c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18eca0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18eca4:	00b90019 */ 	multu	$a1,$t9
/*  f18eca8:	00004812 */ 	mflo	$t1
/*  f18ecac:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f18ecb0:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18ecb4:	01667025 */ 	or	$t6,$t3,$a2
/*  f18ecb8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18ecbc:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18ecc0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f18ecc4:	01401825 */ 	or	$v1,$t2,$zero
/*  f18ecc8:	02ac0019 */ 	multu	$s5,$t4
/*  f18eccc:	00006812 */ 	mflo	$t5
/*  f18ecd0:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18ecd4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f18ecd8:	0313c825 */ 	or	$t9,$t8,$s3
/*  f18ecdc:	03264825 */ 	or	$t1,$t9,$a2
/*  f18ece0:	ac490008 */ 	sw	$t1,0x8($v0)
/*  f18ece4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18ece8:	02cb0019 */ 	multu	$s6,$t3
/*  f18ecec:	00007012 */ 	mflo	$t6
/*  f18ecf0:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ecf4:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f18ecf8:	01aa7825 */ 	or	$t7,$t5,$t2
/*  f18ecfc:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18ed00:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ed04:	02380019 */ 	multu	$s1,$t8
/*  f18ed08:	0000c812 */ 	mflo	$t9
/*  f18ed0c:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ed10:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ed14:	01535825 */ 	or	$t3,$t2,$s3
/*  f18ed18:	01637025 */ 	or	$t6,$t3,$v1
/*  f18ed1c:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f18ed20:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18ed24:	00ac0019 */ 	multu	$a1,$t4
/*  f18ed28:	00006812 */ 	mflo	$t5
/*  f18ed2c:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18ed30:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f18ed34:	0307c825 */ 	or	$t9,$t8,$a3
/*  f18ed38:	0fc54e0e */ 	jal	func0f153838
/*  f18ed3c:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f18ed40:	100002c1 */ 	beqz	$zero,.L0f18f848
/*  f18ed44:	00408025 */ 	or	$s0,$v0,$zero
.L0f18ed48:
/*  f18ed48:	8c427cc0 */ 	lw	$v0,%lo(var80087cc0)($v0)
/*  f18ed4c:	3c01437a */ 	lui	$at,0x437a
/*  f18ed50:	1040006b */ 	beqz	$v0,.L0f18ef00
/*  f18ed54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ed58:	44812000 */ 	mtc1	$at,$f4
/*  f18ed5c:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f18ed60:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ed64:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f18ed68:	4606203c */ 	c.lt.s	$f4,$f6
/*  f18ed6c:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18ed70:	45000063 */ 	bc1f	.L0f18ef00
/*  f18ed74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ed78:	02699007 */ 	srav	$s2,$t1,$s3
/*  f18ed7c:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ed80:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18ed84:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18ed88:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18ed8c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18ed90:	262b0002 */ 	addiu	$t3,$s1,0x2
/*  f18ed94:	26990002 */ 	addiu	$t9,$s4,0x2
/*  f18ed98:	016e0019 */ 	multu	$t3,$t6
/*  f18ed9c:	3c13f600 */ 	lui	$s3,0xf600
/*  f18eda0:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18eda4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f18eda8:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18edac:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f18edb0:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f18edb4:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18edb8:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18edbc:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18edc0:	00006012 */ 	mflo	$t4
/*  f18edc4:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f18edc8:	000d7b80 */ 	sll	$t7,$t5,0xe
/*  f18edcc:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18edd0:	030a5825 */ 	or	$t3,$t8,$t2
/*  f18edd4:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18edd8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18eddc:	262dfffd */ 	addiu	$t5,$s1,-3
/*  f18ede0:	01af0019 */ 	multu	$t5,$t7
/*  f18ede4:	0000c812 */ 	mflo	$t9
/*  f18ede8:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18edec:	0009c380 */ 	sll	$t8,$t1,0xe
/*  f18edf0:	03075025 */ 	or	$t2,$t8,$a3
/*  f18edf4:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f18edf8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18edfc:	02ab0019 */ 	multu	$s5,$t3
/*  f18ee00:	00007012 */ 	mflo	$t6
/*  f18ee04:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ee08:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f18ee0c:	01b37825 */ 	or	$t7,$t5,$s3
/*  f18ee10:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f18ee14:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f18ee18:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ee1c:	268efffe */ 	addiu	$t6,$s4,-2
/*  f18ee20:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ee24:	02c90019 */ 	multu	$s6,$t1
/*  f18ee28:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f18ee2c:	0000c012 */ 	mflo	$t8
/*  f18ee30:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18ee34:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18ee38:	016d7825 */ 	or	$t7,$t3,$t5
/*  f18ee3c:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18ee40:	0fc54e0e */ 	jal	func0f153838
/*  f18ee44:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18ee48:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18ee4c:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ee50:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ee54:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18ee58:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ee5c:	268b0001 */ 	addiu	$t3,$s4,0x1
/*  f18ee60:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18ee64:	02a90019 */ 	multu	$s5,$t1
/*  f18ee68:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f18ee6c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18ee70:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18ee74:	00034880 */ 	sll	$t1,$v1,0x2
/*  f18ee78:	01201825 */ 	or	$v1,$t1,$zero
/*  f18ee7c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18ee80:	0000c012 */ 	mflo	$t8
/*  f18ee84:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18ee88:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f18ee8c:	01d36025 */ 	or	$t4,$t6,$s3
/*  f18ee90:	018fc825 */ 	or	$t9,$t4,$t7
/*  f18ee94:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18ee98:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ee9c:	02d80019 */ 	multu	$s6,$t8
/*  f18eea0:	00005012 */ 	mflo	$t2
/*  f18eea4:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18eea8:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18eeac:	01696825 */ 	or	$t5,$t3,$t1
/*  f18eeb0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18eeb4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18eeb8:	262effff */ 	addiu	$t6,$s1,-1
/*  f18eebc:	022c0019 */ 	multu	$s1,$t4
/*  f18eec0:	00007812 */ 	mflo	$t7
/*  f18eec4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18eec8:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f18eecc:	0133c025 */ 	or	$t8,$t1,$s3
/*  f18eed0:	03035025 */ 	or	$t2,$t8,$v1
/*  f18eed4:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18eed8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18eedc:	01cb0019 */ 	multu	$t6,$t3
/*  f18eee0:	00006812 */ 	mflo	$t5
/*  f18eee4:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f18eee8:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18eeec:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f18eef0:	0fc54e0e */ 	jal	func0f153838
/*  f18eef4:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f18eef8:	10000253 */ 	beqz	$zero,.L0f18f848
/*  f18eefc:	00408025 */ 	or	$s0,$v0,$zero
.L0f18ef00:
/*  f18ef00:	1040006a */ 	beqz	$v0,.L0f18f0ac
/*  f18ef04:	3c01c37a */ 	lui	$at,0xc37a
/*  f18ef08:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f18ef0c:	44815000 */ 	mtc1	$at,$f10
/*  f18ef10:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ef14:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f18ef18:	460a403c */ 	c.lt.s	$f8,$f10
/*  f18ef1c:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18ef20:	45000062 */ 	bc1f	.L0f18f0ac
/*  f18ef24:	02699007 */ 	srav	$s2,$t1,$s3
/*  f18ef28:	0fc54df7 */ 	jal	func0f1537dc
/*  f18ef2c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18ef30:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18ef34:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18ef38:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18ef3c:	262b0002 */ 	addiu	$t3,$s1,0x2
/*  f18ef40:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18ef44:	016d0019 */ 	multu	$t3,$t5
/*  f18ef48:	3c13f600 */ 	lui	$s3,0xf600
/*  f18ef4c:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f18ef50:	000a3080 */ 	sll	$a2,$t2,0x2
/*  f18ef54:	262afffd */ 	addiu	$t2,$s1,-3
/*  f18ef58:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18ef5c:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18ef60:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18ef64:	00006012 */ 	mflo	$t4
/*  f18ef68:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18ef6c:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18ef70:	03334825 */ 	or	$t1,$t9,$s3
/*  f18ef74:	0126c025 */ 	or	$t8,$t1,$a2
/*  f18ef78:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18ef7c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18ef80:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18ef84:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18ef88:	014e0019 */ 	multu	$t2,$t6
/*  f18ef8c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f18ef90:	26990002 */ 	addiu	$t9,$s4,0x2
/*  f18ef94:	00005812 */ 	mflo	$t3
/*  f18ef98:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18ef9c:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f18efa0:	0189c025 */ 	or	$t8,$t4,$t1
/*  f18efa4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18efa8:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18efac:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f18efb0:	000c4880 */ 	sll	$t1,$t4,0x2
/*  f18efb4:	02aa0019 */ 	multu	$s5,$t2
/*  f18efb8:	00007012 */ 	mflo	$t6
/*  f18efbc:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18efc0:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18efc4:	01b37825 */ 	or	$t7,$t5,$s3
/*  f18efc8:	01e9c025 */ 	or	$t8,$t7,$t1
/*  f18efcc:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18efd0:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18efd4:	02ca0019 */ 	multu	$s6,$t2
/*  f18efd8:	00007012 */ 	mflo	$t6
/*  f18efdc:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18efe0:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18efe4:	01a6c825 */ 	or	$t9,$t5,$a2
/*  f18efe8:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f18efec:	0fc54e0e */ 	jal	func0f153838
/*  f18eff0:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18eff4:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f18eff8:	00402025 */ 	or	$a0,$v0,$zero
/*  f18effc:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f000:	024c2821 */ 	addu	$a1,$s2,$t4
/*  f18f004:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f008:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f00c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18f010:	02a90019 */ 	multu	$s5,$t1
/*  f18f014:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f18f018:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18f01c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f020:	0000c012 */ 	mflo	$t8
/*  f18f024:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f028:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f18f02c:	01d35825 */ 	or	$t3,$t6,$s3
/*  f18f030:	016f6825 */ 	or	$t5,$t3,$t7
/*  f18f034:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18f038:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f03c:	2698ffff */ 	addiu	$t8,$s4,-1
/*  f18f040:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f044:	02d90019 */ 	multu	$s6,$t9
/*  f18f048:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f18f04c:	00006012 */ 	mflo	$t4
/*  f18f050:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18f054:	000f4b80 */ 	sll	$t1,$t7,0xe
/*  f18f058:	012e5825 */ 	or	$t3,$t1,$t6
/*  f18f05c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f18f060:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f064:	2629ffff */ 	addiu	$t1,$s1,-1
/*  f18f068:	022d0019 */ 	multu	$s1,$t5
/*  f18f06c:	0000c812 */ 	mflo	$t9
/*  f18f070:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f18f074:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18f078:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18f07c:	03065025 */ 	or	$t2,$t8,$a2
/*  f18f080:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18f084:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f088:	012e0019 */ 	multu	$t1,$t6
/*  f18f08c:	00005812 */ 	mflo	$t3
/*  f18f090:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f094:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f18f098:	03236025 */ 	or	$t4,$t9,$v1
/*  f18f09c:	0fc54e0e */ 	jal	func0f153838
/*  f18f0a0:	ac4c000c */ 	sw	$t4,0xc($v0)
/*  f18f0a4:	100001e8 */ 	beqz	$zero,.L0f18f848
/*  f18f0a8:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f0ac:
/*  f18f0ac:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18f0b0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f0b4:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f0b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f0bc:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f0c0:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18f0c4:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18f0c8:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18f0cc:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f0d0:	262a0002 */ 	addiu	$t2,$s1,0x2
/*  f18f0d4:	268c0002 */ 	addiu	$t4,$s4,0x2
/*  f18f0d8:	01490019 */ 	multu	$t2,$t1
/*  f18f0dc:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f0e0:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18f0e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f18f0e8:	2629fffe */ 	addiu	$t1,$s1,-2
/*  f18f0ec:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f0f0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f0f4:	00007012 */ 	mflo	$t6
/*  f18f0f8:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18f0fc:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18f100:	01b3c825 */ 	or	$t9,$t5,$s3
/*  f18f104:	03385025 */ 	or	$t2,$t9,$t8
/*  f18f108:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f18f10c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f110:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18f114:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f18f118:	012e0019 */ 	multu	$t1,$t6
/*  f18f11c:	00005812 */ 	mflo	$t3
/*  f18f120:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f124:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f18f128:	01985025 */ 	or	$t2,$t4,$t8
/*  f18f12c:	0fc54e0e */ 	jal	func0f153838
/*  f18f130:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f18f134:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*  f18f138:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f13c:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f140:	02492821 */ 	addu	$a1,$s2,$t1
/*  f18f144:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f148:	262e0001 */ 	addiu	$t6,$s1,0x1
/*  f18f14c:	26980001 */ 	addiu	$t8,$s4,0x1
/*  f18f150:	01cb0019 */ 	multu	$t6,$t3
/*  f18f154:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f158:	000a4880 */ 	sll	$t1,$t2,0x2
/*  f18f15c:	262bffff */ 	addiu	$t3,$s1,-1
/*  f18f160:	268affff */ 	addiu	$t2,$s4,-1
/*  f18f164:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f168:	00006812 */ 	mflo	$t5
/*  f18f16c:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18f170:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f174:	03336025 */ 	or	$t4,$t9,$s3
/*  f18f178:	01897025 */ 	or	$t6,$t4,$t1
/*  f18f17c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f18f180:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f184:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f188:	000c4880 */ 	sll	$t1,$t4,0x2
/*  f18f18c:	016d0019 */ 	multu	$t3,$t5
/*  f18f190:	00007812 */ 	mflo	$t7
/*  f18f194:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18f198:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f18f19c:	03097025 */ 	or	$t6,$t8,$t1
/*  f18f1a0:	0fc54e0e */ 	jal	func0f153838
/*  f18f1a4:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18f1a8:	100001a7 */ 	beqz	$zero,.L0f18f848
/*  f18f1ac:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f1b0:
/*  f18f1b0:	8eab0284 */ 	lw	$t3,0x284($s5)
/*  f18f1b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f1b8:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f1bc:	8d6d00bc */ 	lw	$t5,0xbc($t3)
/*  f18f1c0:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f1c4:	3c028008 */ 	lui	$v0,%hi(var80087cc0)
/*  f18f1c8:	16cd0086 */ 	bne	$s6,$t5,.L0f18f3e4
/*  f18f1cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f1d0:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f1d4:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f1d8:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f1dc:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18f1e0:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18f1e4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f1e8:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f1ec:	268b0003 */ 	addiu	$t3,$s4,0x3
/*  f18f1f0:	02aa0019 */ 	multu	$s5,$t2
/*  f18f1f4:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f1f8:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f1fc:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f18f200:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f204:	26880002 */ 	addiu	$t0,$s4,0x2
/*  f18f208:	310a03ff */ 	andi	$t2,$t0,0x3ff
/*  f18f20c:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f18f210:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18f214:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18f218:	00006012 */ 	mflo	$t4
/*  f18f21c:	319803ff */ 	andi	$t8,$t4,0x3ff
/*  f18f220:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f224:	01337025 */ 	or	$t6,$t1,$s3
/*  f18f228:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f18f22c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18f230:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f234:	262f0002 */ 	addiu	$t7,$s1,0x2
/*  f18f238:	02d80019 */ 	multu	$s6,$t8
/*  f18f23c:	00004812 */ 	mflo	$t1
/*  f18f240:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f244:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18f248:	01a87025 */ 	or	$t6,$t5,$t0
/*  f18f24c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18f250:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f254:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f18f258:	000d3880 */ 	sll	$a3,$t5,0x2
/*  f18f25c:	01f90019 */ 	multu	$t7,$t9
/*  f18f260:	262ffffd */ 	addiu	$t7,$s1,-3
/*  f18f264:	00005012 */ 	mflo	$t2
/*  f18f268:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f26c:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f270:	03134825 */ 	or	$t1,$t8,$s3
/*  f18f274:	01285825 */ 	or	$t3,$t1,$t0
/*  f18f278:	ac4b0008 */ 	sw	$t3,0x8($v0)
/*  f18f27c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f280:	01f90019 */ 	multu	$t7,$t9
/*  f18f284:	00005012 */ 	mflo	$t2
/*  f18f288:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f28c:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f290:	03074825 */ 	or	$t1,$t8,$a3
/*  f18f294:	ac49000c */ 	sw	$t1,0xc($v0)
/*  f18f298:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f29c:	02ab0019 */ 	multu	$s5,$t3
/*  f18f2a0:	00006812 */ 	mflo	$t5
/*  f18f2a4:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f2a8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f2ac:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f2b0:	03275025 */ 	or	$t2,$t9,$a3
/*  f18f2b4:	ac4a0010 */ 	sw	$t2,0x10($v0)
/*  f18f2b8:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f2bc:	268dfffe */ 	addiu	$t5,$s4,-2
/*  f18f2c0:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f2c4:	02cc0019 */ 	multu	$s6,$t4
/*  f18f2c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18f2cc:	0000c012 */ 	mflo	$t8
/*  f18f2d0:	330903ff */ 	andi	$t1,$t8,0x3ff
/*  f18f2d4:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f2d8:	016fc825 */ 	or	$t9,$t3,$t7
/*  f18f2dc:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f18f2e0:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f18f2e4:	0fc54e0e */ 	jal	func0f153838
/*  f18f2e8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18f2ec:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18f2f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f2f4:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f2f8:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18f2fc:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f300:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f18f304:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18f308:	022c0019 */ 	multu	$s1,$t4
/*  f18f30c:	2625ffff */ 	addiu	$a1,$s1,-1
/*  f18f310:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18f314:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f18f318:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f18f31c:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f320:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18f324:	0000c012 */ 	mflo	$t8
/*  f18f328:	330903ff */ 	andi	$t1,$t8,0x3ff
/*  f18f32c:	00096b80 */ 	sll	$t5,$t1,0xe
/*  f18f330:	01b37025 */ 	or	$t6,$t5,$s3
/*  f18f334:	01c85825 */ 	or	$t3,$t6,$t0
/*  f18f338:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18f33c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f340:	00aa0019 */ 	multu	$a1,$t2
/*  f18f344:	00006012 */ 	mflo	$t4
/*  f18f348:	319803ff */ 	andi	$t8,$t4,0x3ff
/*  f18f34c:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f350:	01266825 */ 	or	$t5,$t1,$a2
/*  f18f354:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18f358:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f35c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f18f360:	03001825 */ 	or	$v1,$t8,$zero
/*  f18f364:	02ae0019 */ 	multu	$s5,$t6
/*  f18f368:	00005812 */ 	mflo	$t3
/*  f18f36c:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f370:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f374:	03335025 */ 	or	$t2,$t9,$s3
/*  f18f378:	01466025 */ 	or	$t4,$t2,$a2
/*  f18f37c:	ac4c0008 */ 	sw	$t4,0x8($v0)
/*  f18f380:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f384:	02c90019 */ 	multu	$s6,$t1
/*  f18f388:	00006812 */ 	mflo	$t5
/*  f18f38c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f390:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18f394:	01787825 */ 	or	$t7,$t3,$t8
/*  f18f398:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18f39c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f3a0:	02390019 */ 	multu	$s1,$t9
/*  f18f3a4:	00005012 */ 	mflo	$t2
/*  f18f3a8:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f3ac:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f3b0:	03134825 */ 	or	$t1,$t8,$s3
/*  f18f3b4:	01236825 */ 	or	$t5,$t1,$v1
/*  f18f3b8:	ac4d0010 */ 	sw	$t5,0x10($v0)
/*  f18f3bc:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f3c0:	00ae0019 */ 	multu	$a1,$t6
/*  f18f3c4:	00005812 */ 	mflo	$t3
/*  f18f3c8:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f3cc:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f3d0:	03275025 */ 	or	$t2,$t9,$a3
/*  f18f3d4:	0fc54e0e */ 	jal	func0f153838
/*  f18f3d8:	ac4a0014 */ 	sw	$t2,0x14($v0)
/*  f18f3dc:	1000011a */ 	beqz	$zero,.L0f18f848
/*  f18f3e0:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f3e4:
/*  f18f3e4:	8c427cc0 */ 	lw	$v0,%lo(var80087cc0)($v0)
/*  f18f3e8:	3c01437a */ 	lui	$at,0x437a
/*  f18f3ec:	1040006b */ 	beqz	$v0,.L0f18f59c
/*  f18f3f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f3f4:	44819000 */ 	mtc1	$at,$f18
/*  f18f3f8:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f18f3fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f400:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f18f404:	4604903c */ 	c.lt.s	$f18,$f4
/*  f18f408:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f18f40c:	45000063 */ 	bc1f	.L0f18f59c
/*  f18f410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f414:	026c9007 */ 	srav	$s2,$t4,$s3
/*  f18f418:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f41c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18f420:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18f424:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18f428:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f42c:	26290002 */ 	addiu	$t1,$s1,0x2
/*  f18f430:	268a0002 */ 	addiu	$t2,$s4,0x2
/*  f18f434:	012d0019 */ 	multu	$t1,$t5
/*  f18f438:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f43c:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f440:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f18f444:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18f448:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f18f44c:	000d3880 */ 	sll	$a3,$t5,0x2
/*  f18f450:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f454:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f458:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f45c:	00007012 */ 	mflo	$t6
/*  f18f460:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18f464:	000b7b80 */ 	sll	$t7,$t3,0xe
/*  f18f468:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f46c:	03384825 */ 	or	$t1,$t9,$t8
/*  f18f470:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f18f474:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18f478:	262bfffd */ 	addiu	$t3,$s1,-3
/*  f18f47c:	016f0019 */ 	multu	$t3,$t7
/*  f18f480:	00005012 */ 	mflo	$t2
/*  f18f484:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f488:	000ccb80 */ 	sll	$t9,$t4,0xe
/*  f18f48c:	0327c025 */ 	or	$t8,$t9,$a3
/*  f18f490:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18f494:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f498:	02a90019 */ 	multu	$s5,$t1
/*  f18f49c:	00006812 */ 	mflo	$t5
/*  f18f4a0:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f4a4:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18f4a8:	01737825 */ 	or	$t7,$t3,$s3
/*  f18f4ac:	01e75025 */ 	or	$t2,$t7,$a3
/*  f18f4b0:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18f4b4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f4b8:	268dfffe */ 	addiu	$t5,$s4,-2
/*  f18f4bc:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f4c0:	02cc0019 */ 	multu	$s6,$t4
/*  f18f4c4:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f18f4c8:	0000c812 */ 	mflo	$t9
/*  f18f4cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f4d0:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f4d4:	012b7825 */ 	or	$t7,$t1,$t3
/*  f18f4d8:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18f4dc:	0fc54e0e */ 	jal	func0f153838
/*  f18f4e0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18f4e4:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18f4e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f4ec:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f4f0:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18f4f4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f4f8:	26890001 */ 	addiu	$t1,$s4,0x1
/*  f18f4fc:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f500:	02ac0019 */ 	multu	$s5,$t4
/*  f18f504:	000b7880 */ 	sll	$t7,$t3,0x2
/*  f18f508:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18f50c:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f510:	00036080 */ 	sll	$t4,$v1,0x2
/*  f18f514:	01801825 */ 	or	$v1,$t4,$zero
/*  f18f518:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f51c:	0000c812 */ 	mflo	$t9
/*  f18f520:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f524:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f18f528:	01b37025 */ 	or	$t6,$t5,$s3
/*  f18f52c:	01cf5025 */ 	or	$t2,$t6,$t7
/*  f18f530:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f18f534:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f538:	02d90019 */ 	multu	$s6,$t9
/*  f18f53c:	0000c012 */ 	mflo	$t8
/*  f18f540:	330d03ff */ 	andi	$t5,$t8,0x3ff
/*  f18f544:	000d4b80 */ 	sll	$t1,$t5,0xe
/*  f18f548:	012c5825 */ 	or	$t3,$t1,$t4
/*  f18f54c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f18f550:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f554:	262dffff */ 	addiu	$t5,$s1,-1
/*  f18f558:	022e0019 */ 	multu	$s1,$t6
/*  f18f55c:	00007812 */ 	mflo	$t7
/*  f18f560:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f564:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f18f568:	0193c825 */ 	or	$t9,$t4,$s3
/*  f18f56c:	0323c025 */ 	or	$t8,$t9,$v1
/*  f18f570:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18f574:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f578:	01a90019 */ 	multu	$t5,$t1
/*  f18f57c:	00005812 */ 	mflo	$t3
/*  f18f580:	316e03ff */ 	andi	$t6,$t3,0x3ff
/*  f18f584:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f588:	01e75025 */ 	or	$t2,$t7,$a3
/*  f18f58c:	0fc54e0e */ 	jal	func0f153838
/*  f18f590:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f18f594:	100000ac */ 	beqz	$zero,.L0f18f848
/*  f18f598:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f59c:
/*  f18f59c:	1040006a */ 	beqz	$v0,.L0f18f748
/*  f18f5a0:	3c01c37a */ 	lui	$at,0xc37a
/*  f18f5a4:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f18f5a8:	44814000 */ 	mtc1	$at,$f8
/*  f18f5ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f5b0:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f18f5b4:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18f5b8:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f5bc:	45000062 */ 	bc1f	.L0f18f748
/*  f18f5c0:	026c9007 */ 	srav	$s2,$t4,$s3
/*  f18f5c4:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f5c8:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f5cc:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18f5d0:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18f5d4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f5d8:	26290002 */ 	addiu	$t1,$s1,0x2
/*  f18f5dc:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18f5e0:	012b0019 */ 	multu	$t1,$t3
/*  f18f5e4:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f5e8:	30d803ff */ 	andi	$t8,$a2,0x3ff
/*  f18f5ec:	00183080 */ 	sll	$a2,$t8,0x2
/*  f18f5f0:	2638fffd */ 	addiu	$t8,$s1,-3
/*  f18f5f4:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f5f8:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f5fc:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f600:	00007012 */ 	mflo	$t6
/*  f18f604:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f608:	000f5380 */ 	sll	$t2,$t7,0xe
/*  f18f60c:	01536025 */ 	or	$t4,$t2,$s3
/*  f18f610:	0186c825 */ 	or	$t9,$t4,$a2
/*  f18f614:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18f618:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f61c:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f620:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f624:	030d0019 */ 	multu	$t8,$t5
/*  f18f628:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f18f62c:	268a0002 */ 	addiu	$t2,$s4,0x2
/*  f18f630:	00004812 */ 	mflo	$t1
/*  f18f634:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f638:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18f63c:	01ccc825 */ 	or	$t9,$t6,$t4
/*  f18f640:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f18f644:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f648:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18f64c:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f18f650:	02b80019 */ 	multu	$s5,$t8
/*  f18f654:	00006812 */ 	mflo	$t5
/*  f18f658:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f65c:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f660:	01737825 */ 	or	$t7,$t3,$s3
/*  f18f664:	01ecc825 */ 	or	$t9,$t7,$t4
/*  f18f668:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f18f66c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f670:	02d80019 */ 	multu	$s6,$t8
/*  f18f674:	00006812 */ 	mflo	$t5
/*  f18f678:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f67c:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f680:	01665025 */ 	or	$t2,$t3,$a2
/*  f18f684:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f18f688:	0fc54e0e */ 	jal	func0f153838
/*  f18f68c:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18f690:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f18f694:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f698:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f69c:	024e2821 */ 	addu	$a1,$s2,$t6
/*  f18f6a0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f6a4:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f6a8:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18f6ac:	02ac0019 */ 	multu	$s5,$t4
/*  f18f6b0:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f18f6b4:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18f6b8:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f6bc:	0000c812 */ 	mflo	$t9
/*  f18f6c0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f6c4:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f18f6c8:	01b34825 */ 	or	$t1,$t5,$s3
/*  f18f6cc:	012f5825 */ 	or	$t3,$t1,$t7
/*  f18f6d0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18f6d4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f6d8:	2699ffff */ 	addiu	$t9,$s4,-1
/*  f18f6dc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f6e0:	02ca0019 */ 	multu	$s6,$t2
/*  f18f6e4:	00186880 */ 	sll	$t5,$t8,0x2
/*  f18f6e8:	00007012 */ 	mflo	$t6
/*  f18f6ec:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f6f0:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f18f6f4:	018d4825 */ 	or	$t1,$t4,$t5
/*  f18f6f8:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f18f6fc:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f700:	262cffff */ 	addiu	$t4,$s1,-1
/*  f18f704:	022b0019 */ 	multu	$s1,$t3
/*  f18f708:	00005012 */ 	mflo	$t2
/*  f18f70c:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18f710:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f714:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f718:	0326c025 */ 	or	$t8,$t9,$a2
/*  f18f71c:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18f720:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f724:	018d0019 */ 	multu	$t4,$t5
/*  f18f728:	00004812 */ 	mflo	$t1
/*  f18f72c:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f730:	000b5380 */ 	sll	$t2,$t3,0xe
/*  f18f734:	01437025 */ 	or	$t6,$t2,$v1
/*  f18f738:	0fc54e0e */ 	jal	func0f153838
/*  f18f73c:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f18f740:	10000041 */ 	beqz	$zero,.L0f18f848
/*  f18f744:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f748:
/*  f18f748:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f74c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f750:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f754:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f758:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f75c:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f760:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f18f764:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f18f768:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f76c:	26380002 */ 	addiu	$t8,$s1,0x2
/*  f18f770:	268e0002 */ 	addiu	$t6,$s4,0x2
/*  f18f774:	030c0019 */ 	multu	$t8,$t4
/*  f18f778:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f77c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f780:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18f784:	262cfffe */ 	addiu	$t4,$s1,-2
/*  f18f788:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f78c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f790:	00006812 */ 	mflo	$t5
/*  f18f794:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f798:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f79c:	01735025 */ 	or	$t2,$t3,$s3
/*  f18f7a0:	0159c025 */ 	or	$t8,$t2,$t9
/*  f18f7a4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18f7a8:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f7ac:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f7b0:	000ac880 */ 	sll	$t9,$t2,0x2
/*  f18f7b4:	018d0019 */ 	multu	$t4,$t5
/*  f18f7b8:	00004812 */ 	mflo	$t1
/*  f18f7bc:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f7c0:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18f7c4:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f18f7c8:	0fc54e0e */ 	jal	func0f153838
/*  f18f7cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18f7d0:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f18f7d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f7d8:	0fc54df7 */ 	jal	func0f1537dc
/*  f18f7dc:	024c2821 */ 	addu	$a1,$s2,$t4
/*  f18f7e0:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f7e4:	262d0001 */ 	addiu	$t5,$s1,0x1
/*  f18f7e8:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f18f7ec:	01a90019 */ 	multu	$t5,$t1
/*  f18f7f0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f7f4:	00186080 */ 	sll	$t4,$t8,0x2
/*  f18f7f8:	2629ffff */ 	addiu	$t1,$s1,-1
/*  f18f7fc:	2698ffff */ 	addiu	$t8,$s4,-1
/*  f18f800:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f804:	00005812 */ 	mflo	$t3
/*  f18f808:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f80c:	000f5380 */ 	sll	$t2,$t7,0xe
/*  f18f810:	01537025 */ 	or	$t6,$t2,$s3
/*  f18f814:	01cc6825 */ 	or	$t5,$t6,$t4
/*  f18f818:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18f81c:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f820:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f18f824:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f18f828:	012b0019 */ 	multu	$t1,$t3
/*  f18f82c:	00007812 */ 	mflo	$t7
/*  f18f830:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f834:	000acb80 */ 	sll	$t9,$t2,0xe
/*  f18f838:	032c6825 */ 	or	$t5,$t9,$t4
/*  f18f83c:	0fc54e0e */ 	jal	func0f153838
/*  f18f840:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18f844:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f848:
/*  f18f848:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18f84c:	02001025 */ 	or	$v0,$s0,$zero
/*  f18f850:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18f854:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18f858:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18f85c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18f860:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18f864:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18f868:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18f86c:	03e00008 */ 	jr	$ra
/*  f18f870:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);

GLOBAL_ASM(
glabel func0f18f874
/*  f18f874:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f18f878:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f18f87c:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f18f880:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f18f884:	8e58006c */ 	lw	$t8,0x6c($s2)
/*  f18f888:	3c0e800b */ 	lui	$t6,%hi(var800ab5ac)
/*  f18f88c:	8dceb5ac */ 	lw	$t6,%lo(var800ab5ac)($t6)
/*  f18f890:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f18f894:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18f898:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f18f89c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f18f8a0:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f18f8a4:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f18f8a8:	13000003 */ 	beqz	$t8,.L0f18f8b8
/*  f18f8ac:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f18f8b0:	10000002 */ 	beqz	$zero,.L0f18f8bc
/*  f18f8b4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18f8b8:
/*  f18f8b8:	00002825 */ 	or	$a1,$zero,$zero
.L0f18f8bc:
/*  f18f8bc:	8e590068 */ 	lw	$t9,0x68($s2)
/*  f18f8c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f18f8c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f18f8c8:	13200003 */ 	beqz	$t9,.L0f18f8d8
/*  f18f8cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f18f8d0:	10000001 */ 	beqz	$zero,.L0f18f8d8
/*  f18f8d4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f18f8d8:
/*  f18f8d8:	8e4a0064 */ 	lw	$t2,0x64($s2)
/*  f18f8dc:	11400003 */ 	beqz	$t2,.L0f18f8ec
/*  f18f8e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f8e4:	10000001 */ 	beqz	$zero,.L0f18f8ec
/*  f18f8e8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18f8ec:
/*  f18f8ec:	8e4b0070 */ 	lw	$t3,0x70($s2)
/*  f18f8f0:	11600003 */ 	beqz	$t3,.L0f18f900
/*  f18f8f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f8f8:	10000001 */ 	beqz	$zero,.L0f18f900
/*  f18f8fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18f900:
/*  f18f900:	8e4e0314 */ 	lw	$t6,0x314($s2)
/*  f18f904:	00446021 */ 	addu	$t4,$v0,$a0
/*  f18f908:	01836821 */ 	addu	$t5,$t4,$v1
/*  f18f90c:	01a53021 */ 	addu	$a2,$t5,$a1
/*  f18f910:	11c0001a */ 	beqz	$t6,.L0f18f97c
/*  f18f914:	afa6007c */ 	sw	$a2,0x7c($sp)
/*  f18f918:	8e4f0318 */ 	lw	$t7,0x318($s2)
/*  f18f91c:	3c18800b */ 	lui	$t8,0x800b
/*  f18f920:	51e00008 */ 	beqzl	$t7,.L0f18f944
/*  f18f924:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f18f928:	8f18cb94 */ 	lw	$t8,-0x346c($t8)
/*  f18f92c:	33190004 */ 	andi	$t9,$t8,0x4
/*  f18f930:	53200004 */ 	beqzl	$t9,.L0f18f944
/*  f18f934:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f18f938:	100001c3 */ 	beqz	$zero,.L0f190048
/*  f18f93c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f18f940:	8e4a0288 */ 	lw	$t2,0x288($s2)
.L0f18f944:
/*  f18f944:	3c0d800b */ 	lui	$t5,0x800b
/*  f18f948:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f18f94c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f18f950:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f18f954:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f18f958:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f18f95c:	8dadc7cc */ 	lw	$t5,-0x3834($t5)
/*  f18f960:	31ae0004 */ 	andi	$t6,$t5,0x4
/*  f18f964:	15c00003 */ 	bnez	$t6,.L0f18f974
/*  f18f968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f96c:	100001b6 */ 	beqz	$zero,.L0f190048
/*  f18f970:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f974:
/*  f18f974:	10000012 */ 	beqz	$zero,.L0f18f9c0
/*  f18f978:	8e480284 */ 	lw	$t0,0x284($s2)
.L0f18f97c:
/*  f18f97c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18f980:	3c0c800a */ 	lui	$t4,0x800a
/*  f18f984:	8d181c54 */ 	lw	$t8,0x1c54($t0)
/*  f18f988:	8d0f00c4 */ 	lw	$t7,0xc4($t0)
/*  f18f98c:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f18f990:	01f95024 */ 	and	$t2,$t7,$t9
/*  f18f994:	314b0010 */ 	andi	$t3,$t2,0x10
/*  f18f998:	5560000a */ 	bnezl	$t3,.L0f18f9c4
/*  f18f99c:	8d18192c */ 	lw	$t8,0x192c($t0)
/*  f18f9a0:	818ddfeb */ 	lb	$t5,-0x2015($t4)
/*  f18f9a4:	05a10004 */ 	bgez	$t5,.L0f18f9b8
/*  f18f9a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f9ac:	8e4e0448 */ 	lw	$t6,0x448($s2)
/*  f18f9b0:	55c00004 */ 	bnezl	$t6,.L0f18f9c4
/*  f18f9b4:	8d18192c */ 	lw	$t8,0x192c($t0)
.L0f18f9b8:
/*  f18f9b8:	100001a3 */ 	beqz	$zero,.L0f190048
/*  f18f9bc:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f9c0:
/*  f18f9c0:	8d18192c */ 	lw	$t8,0x192c($t0)
.L0f18f9c4:
/*  f18f9c4:	17000005 */ 	bnez	$t8,.L0f18f9dc
/*  f18f9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18f9cc:	8d0f00d8 */ 	lw	$t7,0xd8($t0)
/*  f18f9d0:	3c198007 */ 	lui	$t9,%hi(var800706c8)
/*  f18f9d4:	11e00003 */ 	beqz	$t7,.L0f18f9e4
/*  f18f9d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18f9dc:
/*  f18f9dc:	1000019a */ 	beqz	$zero,.L0f190048
/*  f18f9e0:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f9e4:
/*  f18f9e4:	8f3906c8 */ 	lw	$t9,%lo(var800706c8)($t9)
/*  f18f9e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18f9ec:	14590004 */ 	bne	$v0,$t9,.L0f18fa00
/*  f18f9f0:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f18f9f4:	3c018008 */ 	lui	$at,0x8008
/*  f18f9f8:	10000003 */ 	beqz	$zero,.L0f18fa08
/*  f18f9fc:	ac2afac0 */ 	sw	$t2,-0x540($at)
.L0f18fa00:
/*  f18fa00:	3c018008 */ 	lui	$at,0x8008
/*  f18fa04:	ac22fac0 */ 	sw	$v0,-0x540($at)
.L0f18fa08:
/*  f18fa08:	0c002f40 */ 	jal	func0000bd00
/*  f18fa0c:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18fa10:	00028400 */ 	sll	$s0,$v0,0x10
/*  f18fa14:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f18fa18:	0c002f22 */ 	jal	func0000bc88
/*  f18fa1c:	01608025 */ 	or	$s0,$t3,$zero
/*  f18fa20:	3c0d8008 */ 	lui	$t5,%hi(var8007fac0)
/*  f18fa24:	8dadfac0 */ 	lw	$t5,%lo(var8007fac0)($t5)
/*  f18fa28:	00506021 */ 	addu	$t4,$v0,$s0
/*  f18fa2c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fa30:	018d001a */ 	div	$zero,$t4,$t5
/*  f18fa34:	00007012 */ 	mflo	$t6
/*  f18fa38:	3c11800b */ 	lui	$s1,%hi(var800acc70)
/*  f18fa3c:	2631cc70 */ 	addiu	$s1,$s1,%lo(var800acc70)
/*  f18fa40:	15a00002 */ 	bnez	$t5,.L0f18fa4c
/*  f18fa44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fa48:	0007000d */ 	break	0x7
.L0f18fa4c:
/*  f18fa4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f18fa50:	15a10004 */ 	bne	$t5,$at,.L0f18fa64
/*  f18fa54:	3c018000 */ 	lui	$at,0x8000
/*  f18fa58:	15810002 */ 	bne	$t4,$at,.L0f18fa64
/*  f18fa5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fa60:	0006000d */ 	break	0x6
.L0f18fa64:
/*  f18fa64:	25d8ffd7 */ 	addiu	$t8,$t6,-41
/*  f18fa68:	24010002 */ 	addiu	$at,$zero,0x2
/*  f18fa6c:	15e1001d */ 	bne	$t7,$at,.L0f18fae4
/*  f18fa70:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f18fa74:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f18fa78:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f18fa7c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fa80:	50410008 */ 	beql	$v0,$at,.L0f18faa4
/*  f18fa84:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18fa88:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f18fa8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fa90:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fa94:	1441000f */ 	bne	$v0,$at,.L0f18fad4
/*  f18fa98:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f18fa9c:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f18faa0:	8fb90078 */ 	lw	$t9,0x78($sp)
.L0f18faa4:
/*  f18faa4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18faa8:	17200004 */ 	bnez	$t9,.L0f18fabc
/*  f18faac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fab0:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f18fab4:	254b0010 */ 	addiu	$t3,$t2,0x10
/*  f18fab8:	ae2b0000 */ 	sw	$t3,0x0($s1)
.L0f18fabc:
/*  f18fabc:	14410017 */ 	bne	$v0,$at,.L0f18fb1c
/*  f18fac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fac4:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f18fac8:	258dfffc */ 	addiu	$t5,$t4,-4
/*  f18facc:	10000013 */ 	beqz	$zero,.L0f18fb1c
/*  f18fad0:	ae2d0000 */ 	sw	$t5,0x0($s1)
.L0f18fad4:
/*  f18fad4:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f18fad8:	25d8fff9 */ 	addiu	$t8,$t6,-7
/*  f18fadc:	1000000f */ 	beqz	$zero,.L0f18fb1c
/*  f18fae0:	ae380000 */ 	sw	$t8,0x0($s1)
.L0f18fae4:
/*  f18fae4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fae8:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18faec:	29e10003 */ 	slti	$at,$t7,0x3
/*  f18faf0:	1420000a */ 	bnez	$at,.L0f18fb1c
/*  f18faf4:	332a0001 */ 	andi	$t2,$t9,0x1
/*  f18faf8:	55400006 */ 	bnezl	$t2,.L0f18fb14
/*  f18fafc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f18fb00:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f18fb04:	256c0007 */ 	addiu	$t4,$t3,0x7
/*  f18fb08:	10000004 */ 	beqz	$zero,.L0f18fb1c
/*  f18fb0c:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f18fb10:	8e2d0000 */ 	lw	$t5,0x0($s1)
.L0f18fb14:
/*  f18fb14:	25aefff9 */ 	addiu	$t6,$t5,-7
/*  f18fb18:	ae2e0000 */ 	sw	$t6,0x0($s1)
.L0f18fb1c:
/*  f18fb1c:	0c002f44 */ 	jal	func0000bd10
/*  f18fb20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fb24:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fb28:	3c10800b */ 	lui	$s0,%hi(var800acc74)
/*  f18fb2c:	2610cc74 */ 	addiu	$s0,$s0,%lo(var800acc74)
/*  f18fb30:	2458001a */ 	addiu	$t8,$v0,0x1a
/*  f18fb34:	24010002 */ 	addiu	$at,$zero,0x2
/*  f18fb38:	15e10015 */ 	bne	$t7,$at,.L0f18fb90
/*  f18fb3c:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f18fb40:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f18fb44:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*  f18fb48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fb4c:	270bfffa */ 	addiu	$t3,$t8,-6
/*  f18fb50:	17210003 */ 	bne	$t9,$at,.L0f18fb60
/*  f18fb54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fb58:	10000023 */ 	beqz	$zero,.L0f18fbe8
/*  f18fb5c:	ae0b0000 */ 	sw	$t3,0x0($s0)
.L0f18fb60:
/*  f18fb60:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f18fb64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fb68:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fb6c:	1041001e */ 	beq	$v0,$at,.L0f18fbe8
/*  f18fb70:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f18fb74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fb78:	5581001c */ 	bnel	$t4,$at,.L0f18fbec
/*  f18fb7c:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f18fb80:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18fb84:	25aefff8 */ 	addiu	$t6,$t5,-8
/*  f18fb88:	10000017 */ 	beqz	$zero,.L0f18fbe8
/*  f18fb8c:	ae0e0000 */ 	sw	$t6,0x0($s0)
.L0f18fb90:
/*  f18fb90:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f18fb94:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f18fb98:	2b010003 */ 	slti	$at,$t8,0x3
/*  f18fb9c:	1420000b */ 	bnez	$at,.L0f18fbcc
/*  f18fba0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f18fba4:	54200006 */ 	bnezl	$at,.L0f18fbc0
/*  f18fba8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18fbac:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18fbb0:	272afff8 */ 	addiu	$t2,$t9,-8
/*  f18fbb4:	1000000c */ 	beqz	$zero,.L0f18fbe8
/*  f18fbb8:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f18fbbc:	8e0b0000 */ 	lw	$t3,0x0($s0)
.L0f18fbc0:
/*  f18fbc0:	256cfffe */ 	addiu	$t4,$t3,-2
/*  f18fbc4:	10000008 */ 	beqz	$zero,.L0f18fbe8
/*  f18fbc8:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0f18fbcc:
/*  f18fbcc:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f18fbd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fbd4:	50400005 */ 	beqzl	$v0,.L0f18fbec
/*  f18fbd8:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f18fbdc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18fbe0:	25aefffa */ 	addiu	$t6,$t5,-6
/*  f18fbe4:	ae0e0000 */ 	sw	$t6,0x0($s0)
.L0f18fbe8:
/*  f18fbe8:	24180010 */ 	addiu	$t8,$zero,0x10
.L0f18fbec:
/*  f18fbec:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18fbf0:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18fbf4:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f18fbf8:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f18fbfc:	0fc6396b */ 	jal	func0f18e5ac
/*  f18fc00:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f18fc04:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18fc08:	0fc54c4d */ 	jal	func0f153134
/*  f18fc0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f18fc10:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18fc14:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18fc18:	00008825 */ 	or	$s1,$zero,$zero
/*  f18fc1c:	59e0004b */ 	blezl	$t7,.L0f18fd4c
/*  f18fc20:	8e4e0318 */ 	lw	$t6,0x318($s2)
/*  f18fc24:	8fb90078 */ 	lw	$t9,0x78($sp)
.L0f18fc28:
/*  f18fc28:	00115080 */ 	sll	$t2,$s1,0x2
/*  f18fc2c:	024a4821 */ 	addu	$t1,$s2,$t2
/*  f18fc30:	52390042 */ 	beql	$s1,$t9,.L0f18fd3c
/*  f18fc34:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f18fc38:	8d220064 */ 	lw	$v0,0x64($t1)
/*  f18fc3c:	8c4b00d8 */ 	lw	$t3,0xd8($v0)
/*  f18fc40:	5560003e */ 	bnezl	$t3,.L0f18fd3c
/*  f18fc44:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f18fc48:	8c4500bc */ 	lw	$a1,0xbc($v0)
/*  f18fc4c:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f18fc50:	8cac0004 */ 	lw	$t4,0x4($a1)
/*  f18fc54:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*  f18fc58:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f18fc5c:	05c20037 */ 	bltzl	$t6,.L0f18fd3c
/*  f18fc60:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f18fc64:	0fc61770 */ 	jal	scenarioRadar2
/*  f18fc68:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f18fc6c:	14400032 */ 	bnez	$v0,.L0f18fd38
/*  f18fc70:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f18fc74:	8d220064 */ 	lw	$v0,0x64($t1)
/*  f18fc78:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18fc7c:	8e4d0318 */ 	lw	$t5,0x318($s2)
/*  f18fc80:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f18fc84:	8d0f00bc */ 	lw	$t7,0xbc($t0)
/*  f18fc88:	3c0e800b */ 	lui	$t6,0x800b
/*  f18fc8c:	c7040008 */ 	lwc1	$f4,0x8($t8)
/*  f18fc90:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*  f18fc94:	3c0700ff */ 	lui	$a3,0xff
/*  f18fc98:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18fc9c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fca0:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18fca4:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f18fca8:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f18fcac:	8d0a00bc */ 	lw	$t2,0xbc($t0)
/*  f18fcb0:	c72a000c */ 	lwc1	$f10,0xc($t9)
/*  f18fcb4:	c550000c */ 	lwc1	$f16,0xc($t2)
/*  f18fcb8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fcbc:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*  f18fcc0:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f18fcc4:	8d0c00bc */ 	lw	$t4,0xbc($t0)
/*  f18fcc8:	c5640010 */ 	lwc1	$f4,0x10($t3)
/*  f18fccc:	c5860010 */ 	lwc1	$f6,0x10($t4)
/*  f18fcd0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fcd4:	11a00013 */ 	beqz	$t5,.L0f18fd24
/*  f18fcd8:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f18fcdc:	8dcecb94 */ 	lw	$t6,-0x346c($t6)
/*  f18fce0:	001179c0 */ 	sll	$t7,$s1,0x7
/*  f18fce4:	024fc821 */ 	addu	$t9,$s2,$t7
/*  f18fce8:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f18fcec:	1300000d */ 	beqz	$t8,.L0f18fd24
/*  f18fcf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fcf4:	8f2a00e4 */ 	lw	$t2,0xe4($t9)
/*  f18fcf8:	3c03800b */ 	lui	$v1,0x800b
/*  f18fcfc:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f18fd00:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f18fd04:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f18fd08:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f18fd0c:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18fd10:	9063c7c9 */ 	lbu	$v1,-0x3837($v1)
/*  f18fd14:	00036080 */ 	sll	$t4,$v1,0x2
/*  f18fd18:	00ec3821 */ 	addu	$a3,$a3,$t4
/*  f18fd1c:	10000001 */ 	beqz	$zero,.L0f18fd24
/*  f18fd20:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
.L0f18fd24:
/*  f18fd24:	8c4500bc */ 	lw	$a1,0xbc($v0)
/*  f18fd28:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18fd2c:	0fc63a7b */ 	jal	radarDrawDot
/*  f18fd30:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18fd34:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f18fd38:
/*  f18fd38:	8fad007c */ 	lw	$t5,0x7c($sp)
.L0f18fd3c:
/*  f18fd3c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fd40:	562dffb9 */ 	bnel	$s1,$t5,.L0f18fc28
/*  f18fd44:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18fd48:	8e4e0318 */ 	lw	$t6,0x318($s2)
.L0f18fd4c:
/*  f18fd4c:	3c18800a */ 	lui	$t8,0x800a
/*  f18fd50:	55c0003b */ 	bnezl	$t6,.L0f18fe40
/*  f18fd54:	8e4e0318 */ 	lw	$t6,0x318($s2)
/*  f18fd58:	830fdfeb */ 	lb	$t7,-0x2015($t8)
/*  f18fd5c:	05e30038 */ 	bgezl	$t7,.L0f18fe40
/*  f18fd60:	8e4e0318 */ 	lw	$t6,0x318($s2)
/*  f18fd64:	8e440474 */ 	lw	$a0,0x474($s2)
/*  f18fd68:	0000c880 */ 	sll	$t9,$zero,0x2
/*  f18fd6c:	02594821 */ 	addu	$t1,$s2,$t9
/*  f18fd70:	18800032 */ 	blez	$a0,.L0f18fe3c
/*  f18fd74:	00008825 */ 	or	$s1,$zero,$zero
/*  f18fd78:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f18fd7c:	8d2504b8 */ 	lw	$a1,0x4b8($t1)
.L0f18fd80:
/*  f18fd80:	50a00029 */ 	beqzl	$a1,.L0f18fe28
/*  f18fd84:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fd88:	90aa0000 */ 	lbu	$t2,0x0($a1)
/*  f18fd8c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f18fd90:	55410025 */ 	bnel	$t2,$at,.L0f18fe28
/*  f18fd94:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fd98:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f18fd9c:	50400022 */ 	beqzl	$v0,.L0f18fe28
/*  f18fda0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fda4:	80430007 */ 	lb	$v1,0x7($v0)
/*  f18fda8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18fdac:	5203001e */ 	beql	$s0,$v1,.L0f18fe28
/*  f18fdb0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fdb4:	5061001c */ 	beql	$v1,$at,.L0f18fe28
/*  f18fdb8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18fdbc:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18fdc0:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f18fdc4:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18fdc8:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f18fdcc:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18fdd0:	3c0700ff */ 	lui	$a3,0xff
/*  f18fdd4:	c5700008 */ 	lwc1	$f16,0x8($t3)
/*  f18fdd8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fddc:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f18fde0:	8d0c00bc */ 	lw	$t4,0xbc($t0)
/*  f18fde4:	c4a4000c */ 	lwc1	$f4,0xc($a1)
/*  f18fde8:	c586000c */ 	lwc1	$f6,0xc($t4)
/*  f18fdec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fdf0:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f18fdf4:	8d0d00bc */ 	lw	$t5,0xbc($t0)
/*  f18fdf8:	c4aa0010 */ 	lwc1	$f10,0x10($a1)
/*  f18fdfc:	c5b00010 */ 	lwc1	$f16,0x10($t5)
/*  f18fe00:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f18fe04:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18fe08:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fe0c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18fe10:	0fc63a7b */ 	jal	radarDrawDot
/*  f18fe14:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*  f18fe18:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f18fe1c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18fe20:	8e440474 */ 	lw	$a0,0x474($s2)
/*  f18fe24:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18fe28:
/*  f18fe28:	0224082a */ 	slt	$at,$s1,$a0
/*  f18fe2c:	10200003 */ 	beqz	$at,.L0f18fe3c
/*  f18fe30:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f18fe34:	5630ffd2 */ 	bnel	$s1,$s0,.L0f18fd80
/*  f18fe38:	8d2504b8 */ 	lw	$a1,0x4b8($t1)
.L0f18fe3c:
/*  f18fe3c:	8e4e0318 */ 	lw	$t6,0x318($s2)
.L0f18fe40:
/*  f18fe40:	3c188008 */ 	lui	$t8,%hi(g_NumMpSimulantChrs)
/*  f18fe44:	11c00046 */ 	beqz	$t6,.L0f18ff60
/*  f18fe48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fe4c:	93187d10 */ 	lbu	$t8,%lo(g_NumMpSimulantChrs)($t8)
/*  f18fe50:	3c10800b */ 	lui	$s0,%hi(g_MpSimulantChrs)
/*  f18fe54:	2610cc80 */ 	addiu	$s0,$s0,%lo(g_MpSimulantChrs)
/*  f18fe58:	1b000041 */ 	blez	$t8,.L0f18ff60
/*  f18fe5c:	00008825 */ 	or	$s1,$zero,$zero
.L0f18fe60:
/*  f18fe60:	0fc0e6a5 */ 	jal	chrIsDead
/*  f18fe64:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f18fe68:	14400036 */ 	bnez	$v0,.L0f18ff44
/*  f18fe6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fe70:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f18fe74:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f18fe78:	8c6f0014 */ 	lw	$t7,0x14($v1)
/*  f18fe7c:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18fe80:	07200030 */ 	bltz	$t9,.L0f18ff44
/*  f18fe84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fe88:	0fc61770 */ 	jal	scenarioRadar2
/*  f18fe8c:	8c65001c */ 	lw	$a1,0x1c($v1)
/*  f18fe90:	1440002c */ 	bnez	$v0,.L0f18ff44
/*  f18fe94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fe98:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f18fe9c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18fea0:	8e4f0318 */ 	lw	$t7,0x318($s2)
/*  f18fea4:	8c6a001c */ 	lw	$t2,0x1c($v1)
/*  f18fea8:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f18feac:	3c19800b */ 	lui	$t9,0x800b
/*  f18feb0:	c5440008 */ 	lwc1	$f4,0x8($t2)
/*  f18feb4:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f18feb8:	3c0700ff */ 	lui	$a3,0xff
/*  f18febc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fec0:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f18fec4:	8c6c001c */ 	lw	$t4,0x1c($v1)
/*  f18fec8:	8d0d00bc */ 	lw	$t5,0xbc($t0)
/*  f18fecc:	c58a000c */ 	lwc1	$f10,0xc($t4)
/*  f18fed0:	c5b0000c */ 	lwc1	$f16,0xc($t5)
/*  f18fed4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f18fed8:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*  f18fedc:	8c6e001c */ 	lw	$t6,0x1c($v1)
/*  f18fee0:	8d1800bc */ 	lw	$t8,0xbc($t0)
/*  f18fee4:	c5c40010 */ 	lwc1	$f4,0x10($t6)
/*  f18fee8:	c7060010 */ 	lwc1	$f6,0x10($t8)
/*  f18feec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f18fef0:	11e0000d */ 	beqz	$t7,.L0f18ff28
/*  f18fef4:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f18fef8:	8f39cb94 */ 	lw	$t9,-0x346c($t9)
/*  f18fefc:	332a0002 */ 	andi	$t2,$t9,0x2
/*  f18ff00:	11400009 */ 	beqz	$t2,.L0f18ff28
/*  f18ff04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ff08:	0fc63a5a */ 	jal	teamGetIndex
/*  f18ff0c:	90640125 */ 	lbu	$a0,0x125($v1)
/*  f18ff10:	00025880 */ 	sll	$t3,$v0,0x2
/*  f18ff14:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f18ff18:	00eb3821 */ 	addu	$a3,$a3,$t3
/*  f18ff1c:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
/*  f18ff20:	10000001 */ 	beqz	$zero,.L0f18ff28
/*  f18ff24:	8e030000 */ 	lw	$v1,0x0($s0)
.L0f18ff28:
/*  f18ff28:	8c65001c */ 	lw	$a1,0x1c($v1)
/*  f18ff2c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18ff30:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18ff34:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18ff38:	0fc63a7b */ 	jal	radarDrawDot
/*  f18ff3c:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18ff40:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f18ff44:
/*  f18ff44:	3c0c8008 */ 	lui	$t4,%hi(g_NumMpSimulantChrs)
/*  f18ff48:	918c7d10 */ 	lbu	$t4,%lo(g_NumMpSimulantChrs)($t4)
/*  f18ff4c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18ff50:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f18ff54:	022c082a */ 	slt	$at,$s1,$t4
/*  f18ff58:	1420ffc1 */ 	bnez	$at,.L0f18fe60
/*  f18ff5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18ff60:
/*  f18ff60:	0fc61758 */ 	jal	scenarioRadar
/*  f18ff64:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18ff68:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18ff6c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18ff70:	8d0e1c54 */ 	lw	$t6,0x1c54($t0)
/*  f18ff74:	8d0d00c4 */ 	lw	$t5,0xc4($t0)
/*  f18ff78:	01c0c027 */ 	nor	$t8,$t6,$zero
/*  f18ff7c:	01b87824 */ 	and	$t7,$t5,$t8
/*  f18ff80:	31f90010 */ 	andi	$t9,$t7,0x10
/*  f18ff84:	53200006 */ 	beqzl	$t9,.L0f18ffa0
/*  f18ff88:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f18ff8c:	0fc64018 */ 	jal	radarDrawProps
/*  f18ff90:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ff94:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f18ff98:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f18ff9c:	27a40088 */ 	addiu	$a0,$sp,0x88
.L0f18ffa0:
/*  f18ffa0:	0fc61770 */ 	jal	scenarioRadar2
/*  f18ffa4:	8d0500bc */ 	lw	$a1,0xbc($t0)
/*  f18ffa8:	54400024 */ 	bnezl	$v0,.L0f19003c
/*  f18ffac:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f18ffb0:	44800000 */ 	mtc1	$zero,$f0
/*  f18ffb4:	8e4a0318 */ 	lw	$t2,0x318($s2)
/*  f18ffb8:	3c0b800b */ 	lui	$t3,0x800b
/*  f18ffbc:	e7a00068 */ 	swc1	$f0,0x68($sp)
/*  f18ffc0:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f18ffc4:	11400013 */ 	beqz	$t2,.L0f190014
/*  f18ffc8:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f18ffcc:	8d6bcb94 */ 	lw	$t3,-0x346c($t3)
/*  f18ffd0:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f18ffd4:	316c0002 */ 	andi	$t4,$t3,0x2
/*  f18ffd8:	1180000e */ 	beqz	$t4,.L0f190014
/*  f18ffdc:	000e69c0 */ 	sll	$t5,$t6,0x7
/*  f18ffe0:	024dc021 */ 	addu	$t8,$s2,$t5
/*  f18ffe4:	8f0f00e4 */ 	lw	$t7,0xe4($t8)
/*  f18ffe8:	3c02800b */ 	lui	$v0,0x800b
/*  f18ffec:	3c078008 */ 	lui	$a3,%hi(g_TeamColours)
/*  f18fff0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18fff4:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f18fff8:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18fffc:	00591021 */ 	addu	$v0,$v0,$t9
/*  f190000:	9042c7c9 */ 	lbu	$v0,-0x3837($v0)
/*  f190004:	00025080 */ 	sll	$t2,$v0,0x2
/*  f190008:	00ea3821 */ 	addu	$a3,$a3,$t2
/*  f19000c:	10000002 */ 	beqz	$zero,.L0f190018
/*  f190010:	8ce77cc4 */ 	lw	$a3,%lo(g_TeamColours)($a3)
.L0f190014:
/*  f190014:	3c0700ff */ 	lui	$a3,0xff
.L0f190018:
/*  f190018:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f19001c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f190020:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f190024:	8d6500bc */ 	lw	$a1,0xbc($t3)
/*  f190028:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19002c:	0fc63a7b */ 	jal	radarDrawDot
/*  f190030:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f190034:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f190038:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f19003c:
/*  f19003c:	3c018008 */ 	lui	$at,0x8008
/*  f190040:	ac2cfac0 */ 	sw	$t4,-0x540($at)
/*  f190044:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f190048:
/*  f190048:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f19004c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f190050:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f190054:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f190058:	03e00008 */ 	jr	$ra
/*  f19005c:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

Gfx *radarDrawProps(Gfx *gdl)
{
	struct prop *prop = g_Vars.unk00033c;
	struct coord *playerpos = &g_Vars.currentplayer->prop->pos;
	struct defaultobj *obj;
	struct chrdata *chr;
	u32 stack1;
	struct coord dist1;
	u32 stack2;
	struct coord dist2;

	while (prop) {
		switch (prop->type) {
		case PROPTYPE_OBJ:
		case PROPTYPE_DOOR:
		case PROPTYPE_WEAPON:
			obj = prop->obj;

			if ((obj->flags3 & OBJFLAG3_RTRACKED_YELLOW) ||
					(cheatIsActive(CHEAT_RTRACKER) && (obj->flags3 & OBJFLAG3_RTRACKED_BLUE))) {
				dist1.x = prop->pos.x - playerpos->x;
				dist1.y = prop->pos.y - playerpos->y;
				dist1.z = prop->pos.z - playerpos->z;

				gdl = radarDrawDot(gdl, prop, &dist1,
						(obj->flags3 & OBJFLAG3_RTRACKED_YELLOW) ? 0xffff0000 : 0x0000ff00,
						0, 0);
			}
			break;
		case PROPTYPE_CHR:
			chr = prop->chr;

			if (chr && chr->unk32c_20
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DEAD
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0) {
				dist2.x = prop->pos.x - playerpos->x;
				dist2.y = prop->pos.y - playerpos->y;
				dist2.z = prop->pos.z - playerpos->z;
				gdl = radarDrawDot(gdl, prop, &dist2, 0xff000000, 0, 0);
			}
			break;
		}

		prop = prop->next;
	}

	return gdl;
}
