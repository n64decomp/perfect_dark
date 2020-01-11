#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_015470.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_096750.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/game_0b2150.h"
#include "game/game_0b28d0.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/cheats.h"
#include "game/game_114240.h"
#include "game/game_115ab0.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/pdoptions.h"
#include "game/game_152fa0.h"
#include "game/game_157db0.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "library/library_12dc0.h"

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
/*  f187d7c:	3c02800b */ 	lui	$v0,%hi(var800acb78)
/*  f187d80:	3c03800b */ 	lui	$v1,0x800b
/*  f187d84:	2463cb81 */ 	addiu	$v1,$v1,-13439
/*  f187d88:	2442cb78 */ 	addiu	$v0,$v0,%lo(var800acb78)
/*  f187d8c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f187d90:
/*  f187d90:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f187d94:	1443fffe */ 	bne	$v0,$v1,.L0f187d90
/*  f187d98:	a044ffff */ 	sb	$a0,-0x1($v0)
/*  f187d9c:	3c02800b */ 	lui	$v0,%hi(var800acb78)
/*  f187da0:	2442cb78 */ 	addiu	$v0,$v0,%lo(var800acb78)
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
/*  f187e88:	3c09800b */ 	lui	$t1,0x800b
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
/*  f187ee4:	8d29c530 */ 	lw	$t1,-0x3ad0($t1)
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
/*  f187f28:	3c09800b */ 	lui	$t1,0x800b
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
/*  f187f90:	8d29c530 */ 	lw	$t1,-0x3ad0($t1)
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
/*  f1880c4:	0fc5b9f1 */ 	jal	textGet
/*  f1880c8:	240459b5 */ 	addiu	$a0,$zero,0x59b5
/*  f1880cc:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1880d0:	24a58a2c */ 	addiu	$a1,$a1,-30164
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
/*  f188254:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f188258:	ac800020 */ 	sw	$zero,0x20($a0)
/*  f18825c:	a4800024 */ 	sh	$zero,0x24($a0)
/*  f188260:	0c004c4c */ 	jal	strcpy
/*  f188264:	24a58a34 */ 	addiu	$a1,$a1,-30156
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
/*  f1882a4:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1882a8:	24a58a38 */ 	addiu	$a1,$a1,-30152
/*  f1882ac:	0c004c04 */ 	jal	func00013010
/*  f1882b0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1882b4:	10400009 */ 	beqz	$v0,.L0f1882dc
/*  f1882b8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1882bc:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f1882c0:	0c004c04 */ 	jal	func00013010
/*  f1882c4:	24a58a44 */ 	addiu	$a1,$a1,-30140
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
/*  f188320:	3c06800b */ 	lui	$a2,%hi(var800acb78)
/*  f188324:	24c6cb78 */ 	addiu	$a2,$a2,%lo(var800acb78)
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
/*  f188394:	0fc5b9f1 */ 	jal	textGet
/*  f188398:	240459b6 */ 	addiu	$a0,$zero,0x59b6
/*  f18839c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1883a0:	0c004c4c */ 	jal	strcpy
/*  f1883a4:	00402825 */ 	or	$a1,$v0,$zero
.L0f1883a8:
/*  f1883a8:	3c11800b */ 	lui	$s1,%hi(var800acbb0)
/*  f1883ac:	2631cbb0 */ 	addiu	$s1,$s1,%lo(var800acbb0)
/*  f1883b0:	00008025 */ 	or	$s0,$zero,$zero
.L0f1883b4:
/*  f1883b4:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f1883b8:	55e00007 */ 	bnezl	$t7,.L0f1883d8
/*  f1883bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1883c0:	0fc5b9f1 */ 	jal	textGet
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
/*  f1883e8:	3c127f1c */ 	lui	$s2,0x7f1c
/*  f1883ec:	26528a50 */ 	addiu	$s2,$s2,-30128
/*  f1883f0:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpPlayers)
/*  f1883f4:	00008025 */ 	or	$s0,$zero,$zero
/*  f1883f8:	24130004 */ 	addiu	$s3,$zero,0x4
.L0f1883fc:
/*  f1883fc:	92380000 */ 	lbu	$t8,0x0($s1)
/*  f188400:	57000009 */ 	bnezl	$t8,.L0f188428
/*  f188404:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188408:	0fc5b9f1 */ 	jal	textGet
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
/*  f188c94:	0fc5b9f1 */ 	jal	textGet
/*  f188c98:	2404543a */ 	addiu	$a0,$zero,0x543a
/*  f188c9c:	10000019 */ 	beqz	$zero,.L0f188d04
/*  f188ca0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f188ca4:
/*  f188ca4:	54810006 */ 	bnel	$a0,$at,.L0f188cc0
/*  f188ca8:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f188cac:	0fc5b9f1 */ 	jal	textGet
/*  f188cb0:	2404543b */ 	addiu	$a0,$zero,0x543b
/*  f188cb4:	10000013 */ 	beqz	$zero,.L0f188d04
/*  f188cb8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f188cbc:	2401005c */ 	addiu	$at,$zero,0x5c
.L0f188cc0:
/*  f188cc0:	14810005 */ 	bne	$a0,$at,.L0f188cd8
/*  f188cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188cc8:	0fc5b9f1 */ 	jal	textGet
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
/*  f188cf8:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f188cfc:	24428a58 */ 	addiu	$v0,$v0,-30120
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
/*  f1890cc:	0fc5b9f1 */ 	jal	textGet
/*  f1890d0:	24045429 */ 	addiu	$a0,$zero,0x5429
/*  f1890d4:	10000016 */ 	beqz	$zero,.L0f189130
/*  f1890d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1890dc:	2401000d */ 	addiu	$at,$zero,0xd
.L0f1890e0:
/*  f1890e0:	54410006 */ 	bnel	$v0,$at,.L0f1890fc
/*  f1890e4:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1890e8:	0fc5b9f1 */ 	jal	textGet
/*  f1890ec:	2404542a */ 	addiu	$a0,$zero,0x542a
/*  f1890f0:	1000000f */ 	beqz	$zero,.L0f189130
/*  f1890f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1890f8:	2401000c */ 	addiu	$at,$zero,0xc
.L0f1890fc:
/*  f1890fc:	14410005 */ 	bne	$v0,$at,.L0f189114
/*  f189100:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f189104:	0fc5b9f1 */ 	jal	textGet
/*  f189108:	2404542b */ 	addiu	$a0,$zero,0x542b
/*  f18910c:	10000008 */ 	beqz	$zero,.L0f189130
/*  f189110:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189114:
/*  f189114:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f189118:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18911c:	3c048008 */ 	lui	$a0,0x8008
/*  f189120:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f189124:	0fc5b9f1 */ 	jal	textGet
/*  f189128:	948473f0 */ 	lhu	$a0,0x73f0($a0)
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
/*  f1895e8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1895ec:	8dce74c8 */ 	lw	$t6,0x74c8($t6)
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
/*  f189624:	3c048008 */ 	lui	$a0,0x8008
/*  f189628:	0fc623b5 */ 	jal	func0f188ed4
/*  f18962c:	8c8474c8 */ 	lw	$a0,0x74c8($a0)
/*  f189630:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189634:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f189638:	03e00008 */ 	jr	$ra
/*  f18963c:	00000000 */ 	sll	$zero,$zero,0x0
);

bool mpIsPaused(void)
{
	if (PLAYERCOUNT() == 1 && g_Vars.unk000314 && g_MenuStack[g_Vars.unk000288->mpchrnum].unk00) {
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
/*  f1897b0:	0fc5b9f1 */ 	jal	textGet
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
/*  f1897fc:	3c0d800a */ 	lui	$t5,0x800a
/*  f189800:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f189804:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f189808:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f18980c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f189810:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f189814:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f189818:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f18981c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f189820:	8dade4f8 */ 	lw	$t5,-0x1b08($t5)
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
/*  f18986c:	3c088008 */ 	lui	$t0,0x8008
/*  f189870:	8d08fb14 */ 	lw	$t0,-0x4ec($t0)
/*  f189874:	3c078008 */ 	lui	$a3,0x8008
/*  f189878:	8ce7fb18 */ 	lw	$a3,-0x4e8($a3)
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
/*  f1898c4:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1898c8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1898cc:	3c0100ff */ 	lui	$at,0xff
/*  f1898d0:	8dcefb14 */ 	lw	$t6,-0x4ec($t6)
/*  f1898d4:	8dadfb18 */ 	lw	$t5,-0x4e8($t5)
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
/*  f189930:	3c098006 */ 	lui	$t1,0x8006
/*  f189934:	8d29d9d0 */ 	lw	$t1,-0x2630($t1)
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
/*  f1899a4:	3c098007 */ 	lui	$t1,0x8007
/*  f1899a8:	514000c1 */ 	beqzl	$t2,.L0f189cb0
/*  f1899ac:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899b0:	8d290764 */ 	lw	$t1,0x764($t1)
/*  f1899b4:	552000be */ 	bnezl	$t1,.L0f189cb0
/*  f1899b8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899bc:	8c6b029c */ 	lw	$t3,0x29c($v1)
.L0f1899c0:
/*  f1899c0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1899c4:	05600008 */ 	bltz	$t3,.L0f1899e8
/*  f1899c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1899cc:	8c6c02a8 */ 	lw	$t4,0x2a8($v1)
/*  f1899d0:	3c0d8007 */ 	lui	$t5,0x8007
/*  f1899d4:	558200b6 */ 	bnel	$t4,$v0,.L0f189cb0
/*  f1899d8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899dc:	8dad0764 */ 	lw	$t5,0x764($t5)
/*  f1899e0:	55a000b3 */ 	bnezl	$t5,.L0f189cb0
/*  f1899e4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f1899e8:
/*  f1899e8:	8dce4038 */ 	lw	$t6,0x4038($t6)
/*  f1899ec:	55c000b0 */ 	bnezl	$t6,.L0f189cb0
/*  f1899f0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899f4:	0fc54d8a */ 	jal	func0f153628
/*  f1899f8:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1899fc:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189a00:	0fc5b9f1 */ 	jal	textGet
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
/*  f189a50:	3c0b8008 */ 	lui	$t3,0x8008
/*  f189a54:	8d6bfb0c */ 	lw	$t3,-0x4f4($t3)
/*  f189a58:	04410003 */ 	bgez	$v0,.L0f189a68
/*  f189a5c:	00024043 */ 	sra	$t0,$v0,0x1
/*  f189a60:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189a64:	00014043 */ 	sra	$t0,$at,0x1
.L0f189a68:
/*  f189a68:	3c078008 */ 	lui	$a3,0x8008
/*  f189a6c:	010a4821 */ 	addu	$t1,$t0,$t2
/*  f189a70:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f189a74:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
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
/*  f189abc:	3c188008 */ 	lui	$t8,0x8008
/*  f189ac0:	3c198008 */ 	lui	$t9,0x8008
/*  f189ac4:	8f39fb0c */ 	lw	$t9,-0x4f4($t9)
/*  f189ac8:	8f18fb10 */ 	lw	$t8,-0x4f0($t8)
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
/*  f189b98:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f189b9c:	24c6003b */ 	addiu	$a2,$a2,0x3b
/*  f189ba0:	00c1001a */ 	div	$zero,$a2,$at
/*  f189ba4:	00003012 */ 	mflo	$a2
/*  f189ba8:	24a58aa4 */ 	addiu	$a1,$a1,-30044
/*  f189bac:	0c004dad */ 	jal	sprintf
/*  f189bb0:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f189bb4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f189bb8:	8dcefb0c */ 	lw	$t6,-0x4f4($t6)
/*  f189bbc:	3c078008 */ 	lui	$a3,0x8008
/*  f189bc0:	8ce7fb10 */ 	lw	$a3,-0x4f0($a3)
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
/*  f189c10:	3c098008 */ 	lui	$t1,0x8008
/*  f189c14:	3c0b8008 */ 	lui	$t3,0x8008
/*  f189c18:	8d6bfb0c */ 	lw	$t3,-0x4f4($t3)
/*  f189c1c:	8d29fb10 */ 	lw	$t1,-0x4f0($t1)
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
/*  f18a190:	3c0f7f1c */ 	lui	$t7,0x7f1c
/*  f18a194:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f18a198:	25ef8aa8 */ 	addiu	$t7,$t7,-30040
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
/*  f18a618:	0fc3089f */ 	jal	func0f0c227c
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
/*  f18a8fc:	3c19800a */ 	lui	$t9,0x800a
/*  f18a900:	3c0e800a */ 	lui	$t6,0x800a
/*  f18a904:	460a103c */ 	c.lt.s	$f2,$f10
/*  f18a908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a90c:	45020003 */ 	bc1fl	.L0f18a91c
/*  f18a910:	a2000094 */ 	sb	$zero,0x94($s0)
/*  f18a914:	e6620038 */ 	swc1	$f2,0x38($s3)
/*  f18a918:	a2000094 */ 	sb	$zero,0x94($s0)
.L0f18a91c:
/*  f18a91c:	8f3921d0 */ 	lw	$t9,0x21d0($t9)
/*  f18a920:	57200173 */ 	bnezl	$t9,.L0f18aef0
/*  f18a924:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f18a928:	8dce21d4 */ 	lw	$t6,0x21d4($t6)
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
/*  f18b5cc:	0fc5b9f1 */ 	jal	textGet
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
/*  f18b690:	0fc5b9f1 */ 	jal	textGet
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
/*  f18b7b0:	3c0e800a */ 	lui	$t6,0x800a
/*  f18b7b4:	8dce21d0 */ 	lw	$t6,0x21d0($t6)
/*  f18b7b8:	3c0d800a */ 	lui	$t5,0x800a
/*  f18b7bc:	15c00038 */ 	bnez	$t6,.L0f18b8a0
/*  f18b7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b7c4:	8dad21d4 */ 	lw	$t5,0x21d4($t5)
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
/*  f18b8a0:	3c0f800a */ 	lui	$t7,0x800a
/*  f18b8a4:	8def21d0 */ 	lw	$t7,0x21d0($t7)
/*  f18b8a8:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f18b8ac:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18b8b0:	15e00035 */ 	bnez	$t7,.L0f18b988
/*  f18b8b4:	3c0e800a */ 	lui	$t6,0x800a
/*  f18b8b8:	8dce21d4 */ 	lw	$t6,0x21d4($t6)
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
	return 75;
}

s32 mpGetNumHeads(void)
{
	return 75;
}

GLOBAL_ASM(
glabel func0f18bb2c
/*  f18bb2c:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f18bb30:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18bb34:	3c028008 */ 	lui	$v0,0x8008
/*  f18bb38:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f18bb3c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f18bb40:	03e00008 */ 	jr	$ra
/*  f18bb44:	8442752c */ 	lh	$v0,0x752c($v0)
);

GLOBAL_ASM(
glabel func0f18bb48
/*  f18bb48:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f18bb4c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18bb50:	3c028008 */ 	lui	$v0,0x8008
/*  f18bb54:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f18bb58:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f18bb5c:	03e00008 */ 	jr	$ra
/*  f18bb60:	9042752e */ 	lbu	$v0,0x752e($v0)
);

GLOBAL_ASM(
glabel func0f18bb64
/*  f18bb64:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f18bb68:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18bb6c:	3c028008 */ 	lui	$v0,0x8008
/*  f18bb70:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f18bb74:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f18bb78:	03e00008 */ 	jr	$ra
/*  f18bb7c:	84427518 */ 	lh	$v0,0x7518($v0)
/*  f18bb80:	03e00008 */ 	jr	$ra
/*  f18bb84:	24020005 */ 	addiu	$v0,$zero,0x5
);

u32 func0f18bb88(void)
{
	return 61;
}

GLOBAL_ASM(
glabel func0f18bb90
/*  f18bb90:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f18bb94:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f18bb98:	29c1003e */ 	slti	$at,$t6,0x3e
/*  f18bb9c:	14200008 */ 	bnez	$at,.L0f18bbc0
/*  f18bba0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f18bba4:	2401003e */ 	addiu	$at,$zero,0x3e
/*  f18bba8:	15c10003 */ 	bne	$t6,$at,.L0f18bbb8
/*  f18bbac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bbb0:	03e00008 */ 	jr	$ra
/*  f18bbb4:	2402006b */ 	addiu	$v0,$zero,0x6b
.L0f18bbb8:
/*  f18bbb8:	03e00008 */ 	jr	$ra
/*  f18bbbc:	24020056 */ 	addiu	$v0,$zero,0x56
.L0f18bbc0:
/*  f18bbc0:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f18bbc4:	3c028008 */ 	lui	$v0,0x8008
/*  f18bbc8:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f18bbcc:	844277bc */ 	lh	$v0,0x77bc($v0)
/*  f18bbd0:	03e00008 */ 	jr	$ra
/*  f18bbd4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18bbd8
/*  f18bbd8:	3082ffff */ 	andi	$v0,$a0,0xffff
/*  f18bbdc:	2401006b */ 	addiu	$at,$zero,0x6b
/*  f18bbe0:	14410003 */ 	bne	$v0,$at,.L0f18bbf0
/*  f18bbe4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f18bbe8:	03e00008 */ 	jr	$ra
/*  f18bbec:	2402003e */ 	addiu	$v0,$zero,0x3e
.L0f18bbf0:
/*  f18bbf0:	3c048008 */ 	lui	$a0,%hi(mpbodytable)
/*  f18bbf4:	248477bc */ 	addiu	$a0,$a0,%lo(mpbodytable)
/*  f18bbf8:	00001825 */ 	or	$v1,$zero,$zero
/*  f18bbfc:	2405003d */ 	addiu	$a1,$zero,0x3d
.L0f18bc00:
/*  f18bc00:	848f0000 */ 	lh	$t7,0x0($a0)
/*  f18bc04:	544f0004 */ 	bnel	$v0,$t7,.L0f18bc18
/*  f18bc08:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18bc0c:	03e00008 */ 	jr	$ra
/*  f18bc10:	00601025 */ 	or	$v0,$v1,$zero
/*  f18bc14:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18bc18:
/*  f18bc18:	1465fff9 */ 	bne	$v1,$a1,.L0f18bc00
/*  f18bc1c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f18bc20:	3c028008 */ 	lui	$v0,0x8008
/*  f18bc24:	844277bc */ 	lh	$v0,0x77bc($v0)
/*  f18bc28:	03e00008 */ 	jr	$ra
/*  f18bc2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18bc30
/*  f18bc30:	308500ff */ 	andi	$a1,$a0,0xff
/*  f18bc34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18bc38:	28a1003e */ 	slti	$at,$a1,0x3e
/*  f18bc3c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18bc40:	14200002 */ 	bnez	$at,.L0f18bc4c
/*  f18bc44:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f18bc48:	00002825 */ 	or	$a1,$zero,$zero
.L0f18bc4c:
/*  f18bc4c:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f18bc50:	3c048008 */ 	lui	$a0,0x8008
/*  f18bc54:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f18bc58:	0fc5b9f1 */ 	jal	textGet
/*  f18bc5c:	848477be */ 	lh	$a0,0x77be($a0)
/*  f18bc60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18bc64:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18bc68:	03e00008 */ 	jr	$ra
/*  f18bc6c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18bc70
/*  f18bc70:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f18bc74:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f18bc78:	29c1003e */ 	slti	$at,$t6,0x3e
/*  f18bc7c:	14200002 */ 	bnez	$at,.L0f18bc88
/*  f18bc80:	01c02025 */ 	or	$a0,$t6,$zero
/*  f18bc84:	00002025 */ 	or	$a0,$zero,$zero
.L0f18bc88:
/*  f18bc88:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f18bc8c:	3c028008 */ 	lui	$v0,0x8008
/*  f18bc90:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f18bc94:	03e00008 */ 	jr	$ra
/*  f18bc98:	904277c2 */ 	lbu	$v0,0x77c2($v0)
);

GLOBAL_ASM(
glabel func0f18bc9c
/*  f18bc9c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f18bca0:	2881003e */ 	slti	$at,$a0,0x3e
/*  f18bca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18bca8:	14200002 */ 	bnez	$at,.L0f18bcb4
/*  f18bcac:	00003025 */ 	or	$a2,$zero,$zero
/*  f18bcb0:	00002025 */ 	or	$a0,$zero,$zero
.L0f18bcb4:
/*  f18bcb4:	3c0f8008 */ 	lui	$t7,%hi(mpbodytable)
/*  f18bcb8:	25ef77bc */ 	addiu	$t7,$t7,%lo(mpbodytable)
/*  f18bcbc:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f18bcc0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f18bcc4:	84450004 */ 	lh	$a1,0x4($v0)
/*  f18bcc8:	240103e8 */ 	addiu	$at,$zero,0x3e8
/*  f18bccc:	14a10020 */ 	bne	$a1,$at,.L0f18bd50
/*  f18bcd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bcd4:	84580000 */ 	lh	$t8,0x0($v0)
/*  f18bcd8:	3c088008 */ 	lui	$t0,0x8008
/*  f18bcdc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18bce0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f18bce4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18bce8:	01194021 */ 	addu	$t0,$t0,$t9
/*  f18bcec:	8d08cf04 */ 	lw	$t0,-0x30fc($t0)
/*  f18bcf0:	00084fc2 */ 	srl	$t1,$t0,0x1f
/*  f18bcf4:	1120000c */ 	beqz	$t1,.L0f18bd28
/*  f18bcf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bcfc:	0c004b70 */ 	jal	random
/*  f18bd00:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f18bd04:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f18bd08:	0041001b */ 	divu	$zero,$v0,$at
/*  f18bd0c:	00005010 */ 	mfhi	$t2
/*  f18bd10:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f18bd14:	3c058008 */ 	lui	$a1,0x8008
/*  f18bd18:	00ab2821 */ 	addu	$a1,$a1,$t3
/*  f18bd1c:	8ca579a4 */ 	lw	$a1,0x79a4($a1)
/*  f18bd20:	1000000b */ 	beqz	$zero,.L0f18bd50
/*  f18bd24:	8fa60018 */ 	lw	$a2,0x18($sp)
.L0f18bd28:
/*  f18bd28:	0c004b70 */ 	jal	random
/*  f18bd2c:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f18bd30:	24010007 */ 	addiu	$at,$zero,0x7
/*  f18bd34:	0041001b */ 	divu	$zero,$v0,$at
/*  f18bd38:	00006010 */ 	mfhi	$t4
/*  f18bd3c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f18bd40:	3c058008 */ 	lui	$a1,0x8008
/*  f18bd44:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f18bd48:	8ca57a54 */ 	lw	$a1,0x7a54($a1)
/*  f18bd4c:	8fa60018 */ 	lw	$a2,0x18($sp)
.L0f18bd50:
/*  f18bd50:	3c038008 */ 	lui	$v1,%hi(mpheadstable)
/*  f18bd54:	2463752c */ 	addiu	$v1,$v1,%lo(mpheadstable)
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
/*  f18bf70:	3c02800b */ 	lui	$v0,%hi(var800acbb0)
/*  f18bf74:	2442cbb0 */ 	addiu	$v0,$v0,%lo(var800acbb0)
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
	return g_MpLockType;
}

u32 mpGetLockPlayerNum(void)
{
	return g_MpLockPlayerNum;
}

GLOBAL_ASM(
glabel func0f18bfd8
/*  f18bfd8:	3c0e800b */ 	lui	$t6,0x800b
/*  f18bfdc:	91cecc10 */ 	lbu	$t6,-0x33f0($t6)
/*  f18bfe0:	3c0f800b */ 	lui	$t7,0x800b
/*  f18bfe4:	15c00003 */ 	bnez	$t6,.L0f18bff4
/*  f18bfe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18bfec:	03e00008 */ 	jr	$ra
/*  f18bff0:	00001025 */ 	or	$v0,$zero,$zero
.L0f18bff4:
/*  f18bff4:	81efcc20 */ 	lb	$t7,-0x33e0($t7)
/*  f18bff8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18bffc:	148f0003 */ 	bne	$a0,$t7,.L0f18c00c
/*  f18c000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c004:	03e00008 */ 	jr	$ra
/*  f18c008:	00001025 */ 	or	$v0,$zero,$zero
.L0f18c00c:
/*  f18c00c:	03e00008 */ 	jr	$ra
/*  f18c010:	00000000 */ 	sll	$zero,$zero,0x0
);

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
glabel func0f18c0c0
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
/*  f18c0fc:	3c18800a */ 	lui	$t8,0x800a
/*  f18c100:	27182200 */ 	addiu	$t8,$t8,0x2200
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

GLOBAL_ASM(
glabel func0f18c138
/*  f18c138:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18c13c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18c140:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18c144:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18c148:	00809025 */ 	or	$s2,$a0,$zero
/*  f18c14c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18c150:	00008825 */ 	or	$s1,$zero,$zero
/*  f18c154:	18800008 */ 	blez	$a0,.L0f18c178
/*  f18c158:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c15c:
/*  f18c15c:	0fc63030 */ 	jal	func0f18c0c0
/*  f18c160:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c164:	10400002 */ 	beqz	$v0,.L0f18c170
/*  f18c168:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c16c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18c170:
/*  f18c170:	1612fffa */ 	bne	$s0,$s2,.L0f18c15c
/*  f18c174:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18c178:
/*  f18c178:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18c17c:	02201025 */ 	or	$v0,$s1,$zero
/*  f18c180:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18c184:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18c188:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18c18c:	03e00008 */ 	jr	$ra
/*  f18c190:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18c194
/*  f18c194:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18c198:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18c19c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18c1a0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18c1a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18c1a8:	00809825 */ 	or	$s3,$a0,$zero
/*  f18c1ac:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18c1b0:	00008825 */ 	or	$s1,$zero,$zero
/*  f18c1b4:	00008025 */ 	or	$s0,$zero,$zero
/*  f18c1b8:	2412002a */ 	addiu	$s2,$zero,0x2a
.L0f18c1bc:
/*  f18c1bc:	0fc63030 */ 	jal	func0f18c0c0
/*  f18c1c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c1c4:	50400004 */ 	beqzl	$v0,.L0f18c1d8
/*  f18c1c8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c1cc:	12330004 */ 	beq	$s1,$s3,.L0f18c1e0
/*  f18c1d0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18c1d4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18c1d8:
/*  f18c1d8:	1612fff8 */ 	bne	$s0,$s2,.L0f18c1bc
/*  f18c1dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18c1e0:
/*  f18c1e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18c1e4:	02001025 */ 	or	$v0,$s0,$zero
/*  f18c1e8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18c1ec:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18c1f0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18c1f4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18c1f8:	03e00008 */ 	jr	$ra
/*  f18c1fc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18c200
/*  f18c200:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c204:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c208:	0fc6304e */ 	jal	func0f18c138
/*  f18c20c:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f18c210:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c214:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c218:	03e00008 */ 	jr	$ra
/*  f18c21c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18c220
/*  f18c220:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c224:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c228:	0fc63065 */ 	jal	func0f18c194
/*  f18c22c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c230:	00027080 */ 	sll	$t6,$v0,0x2
/*  f18c234:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18c238:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18c23c:	3c028008 */ 	lui	$v0,0x8008
/*  f18c240:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f18c244:	94427a70 */ 	lhu	$v0,0x7a70($v0)
/*  f18c248:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c24c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c250:	00027a42 */ 	srl	$t7,$v0,0x9
/*  f18c254:	03e00008 */ 	jr	$ra
/*  f18c258:	01e01025 */ 	or	$v0,$t7,$zero
);

GLOBAL_ASM(
glabel func0f18c25c
/*  f18c25c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c260:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c264:	0fc63065 */ 	jal	func0f18c194
/*  f18c268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c26c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f18c270:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18c274:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18c278:	3c048008 */ 	lui	$a0,0x8008
/*  f18c27c:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f18c280:	0fc5b9f1 */ 	jal	textGet
/*  f18c284:	84847a72 */ 	lh	$a0,0x7a72($a0)
/*  f18c288:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18c28c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f18c290:	03e00008 */ 	jr	$ra
/*  f18c294:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel mpSetUsingMultipleTunes
/*  f18c298:	3c01800b */ 	lui	$at,0x800b
/*  f18c29c:	03e00008 */ 	jr	$ra
/*  f18c2a0:	a024cc12 */ 	sb	$a0,-0x33ee($at)
);

GLOBAL_ASM(
glabel mpGetUsingMultipleTunes
/*  f18c2a4:	3c02800b */ 	lui	$v0,0x800b
/*  f18c2a8:	03e00008 */ 	jr	$ra
/*  f18c2ac:	9042cc12 */ 	lbu	$v0,-0x33ee($v0)
);

GLOBAL_ASM(
glabel func0f18c2b0
/*  f18c2b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c2b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c2b8:	0fc63065 */ 	jal	func0f18c194
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
/*  f18c30c:	0fc63065 */ 	jal	func0f18c194
/*  f18c310:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f18c314:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f18c318:	3c18800b */ 	lui	$t8,%hi(var800acbb0)
/*  f18c31c:	2718cbb0 */ 	addiu	$t8,$t8,%lo(var800acbb0)
/*  f18c320:	11c0000d */ 	beqz	$t6,.L0f18c358
/*  f18c324:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f18c328:	000278c3 */ 	sra	$t7,$v0,0x3
/*  f18c32c:	3c19800b */ 	lui	$t9,%hi(var800acbb0)
/*  f18c330:	2739cbb0 */ 	addiu	$t9,$t9,%lo(var800acbb0)
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
/*  f18c3c4:	0fc63065 */ 	jal	func0f18c194
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
/*  f18c3e4:	3c03800b */ 	lui	$v1,%hi(var800acbb0)
/*  f18c3e8:	3c04800b */ 	lui	$a0,0x800b
/*  f18c3ec:	2484cbb6 */ 	addiu	$a0,$a0,-13386
/*  f18c3f0:	2463cbb0 */ 	addiu	$v1,$v1,%lo(var800acbb0)
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
/*  f18c40c:	3c03800b */ 	lui	$v1,%hi(var800acbb0)
/*  f18c410:	3c02800b */ 	lui	$v0,0x800b
/*  f18c414:	2442cbb6 */ 	addiu	$v0,$v0,-13386
/*  f18c418:	2463cbb0 */ 	addiu	$v1,$v1,%lo(var800acbb0)
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
/*  f18c43c:	3c10800b */ 	lui	$s0,%hi(var800acbb0)
/*  f18c440:	3c11800b */ 	lui	$s1,0x800b
/*  f18c444:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18c448:	2631cbb6 */ 	addiu	$s1,$s1,-13386
/*  f18c44c:	2610cbb0 */ 	addiu	$s0,$s0,%lo(var800acbb0)
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
/*  f18c488:	3c04800b */ 	lui	$a0,0x800b
/*  f18c48c:	8084cc14 */ 	lb	$a0,-0x33ec($a0)
/*  f18c490:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18c494:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18c498:	04810003 */ 	bgez	$a0,.L0f18c4a8
/*  f18c49c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c4a0:	10000003 */ 	beqz	$zero,.L0f18c4b0
/*  f18c4a4:	00801025 */ 	or	$v0,$a0,$zero
.L0f18c4a8:
/*  f18c4a8:	0fc6304e */ 	jal	func0f18c138
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
/*  f18c550:	0fc63065 */ 	jal	func0f18c194
/*  f18c554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c558:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18c55c:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c560:	104efff4 */ 	beq	$v0,$t6,.L0f18c534
/*  f18c564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c568:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c56c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c570:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c574:	3c038008 */ 	lui	$v1,0x8008
/*  f18c578:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c57c:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18c580:	94637a70 */ 	lhu	$v1,0x7a70($v1)
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
/*  f18c60c:	3c038008 */ 	lui	$v1,0x8008
/*  f18c610:	94637a70 */ 	lhu	$v1,0x7a70($v1)
/*  f18c614:	3c018008 */ 	lui	$at,0x8008
/*  f18c618:	306801ff */ 	andi	$t0,$v1,0x1ff
/*  f18c61c:	00084900 */ 	sll	$t1,$t0,0x4
/*  f18c620:	01284823 */ 	subu	$t1,$t1,$t0
/*  f18c624:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c628:	ac2940f8 */ 	sw	$t1,0x40f8($at)
/*  f18c62c:	1000004f */ 	beqz	$zero,.L0f18c76c
/*  f18c630:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c634:
/*  f18c634:	0fc63065 */ 	jal	func0f18c194
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
/*  f18c660:	3c038008 */ 	lui	$v1,0x8008
/*  f18c664:	aed30004 */ 	sw	$s3,0x4($s6)
/*  f18c668:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18c66c:	94637a70 */ 	lhu	$v1,0x7a70($v1)
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
/*  f18c6d0:	0fc63065 */ 	jal	func0f18c194
/*  f18c6d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6d8:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18c6dc:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c6e0:	104efff4 */ 	beq	$v0,$t6,.L0f18c6b4
/*  f18c6e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c6e8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c6ec:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c6f0:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c6f4:	3c038008 */ 	lui	$v1,0x8008
/*  f18c6f8:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c6fc:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18c700:	94637a70 */ 	lhu	$v1,0x7a70($v1)
/*  f18c704:	3c018008 */ 	lui	$at,0x8008
/*  f18c708:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18c70c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f18c710:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18c714:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18c718:	ac3940f8 */ 	sw	$t9,0x40f8($at)
/*  f18c71c:	10000013 */ 	beqz	$zero,.L0f18c76c
/*  f18c720:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c724:
/*  f18c724:	0fc63065 */ 	jal	func0f18c194
/*  f18c728:	02602025 */ 	or	$a0,$s3,$zero
/*  f18c72c:	00024080 */ 	sll	$t0,$v0,0x2
/*  f18c730:	3c16800b */ 	lui	$s6,%hi(g_MpLockPlayerNum)
/*  f18c734:	01024023 */ 	subu	$t0,$t0,$v0
/*  f18c738:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockPlayerNum)
/*  f18c73c:	00084040 */ 	sll	$t0,$t0,0x1
/*  f18c740:	3c038008 */ 	lui	$v1,0x8008
/*  f18c744:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c748:	00681821 */ 	addu	$v1,$v1,$t0
/*  f18c74c:	94637a70 */ 	lhu	$v1,0x7a70($v1)
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
/*  f18ca48:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f18ca4c:	016e7825 */ 	or	$t7,$t3,$t6
/*  f18ca50:	a44f0016 */ 	sh	$t7,0x16($v0)
/*  f18ca54:	24a58b6c */ 	addiu	$a1,$a1,-29844
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
/*  f18cf5c:	0fc5b9f1 */ 	jal	textGet
/*  f18cf60:	85c40002 */ 	lh	$a0,0x2($t6)
/*  f18cf64:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f18cf68:	24a58b74 */ 	addiu	$a1,$a1,-29836
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
/*  f18cf90:	0fc5b9f1 */ 	jal	textGet
/*  f18cf94:	87240002 */ 	lh	$a0,0x2($t9)
/*  f18cf98:	3c057f1c */ 	lui	$a1,0x7f1c
/*  f18cf9c:	24a58b7c */ 	addiu	$a1,$a1,-29828
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

GLOBAL_ASM(
glabel mpPlayerGetIndex
/*  f18cff8:	3c02800b */ 	lui	$v0,0x800b
/*  f18cffc:	8c42c530 */ 	lw	$v0,-0x3ad0($v0)
/*  f18d000:	3c05800b */ 	lui	$a1,%hi(g_MpPlayerChrs)
/*  f18d004:	24a5c4d0 */ 	addiu	$a1,$a1,%lo(g_MpPlayerChrs)
/*  f18d008:	1840000a */ 	blez	$v0,.L0f18d034
/*  f18d00c:	00001825 */ 	or	$v1,$zero,$zero
.L0f18d010:
/*  f18d010:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f18d014:	548e0004 */ 	bnel	$a0,$t6,.L0f18d028
/*  f18d018:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d01c:	03e00008 */ 	jr	$ra
/*  f18d020:	00601025 */ 	or	$v0,$v1,$zero
/*  f18d024:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d028:
/*  f18d028:	0062082a */ 	slt	$at,$v1,$v0
/*  f18d02c:	1420fff8 */ 	bnez	$at,.L0f18d010
/*  f18d030:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f18d034:
/*  f18d034:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f18d038:	03e00008 */ 	jr	$ra
/*  f18d03c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18d040
/*  f18d040:	04800009 */ 	bltz	$a0,.L0f18d068
/*  f18d044:	3c0e800b */ 	lui	$t6,0x800b
/*  f18d048:	8dcec530 */ 	lw	$t6,-0x3ad0($t6)
/*  f18d04c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f18d050:	3c02800b */ 	lui	$v0,0x800b
/*  f18d054:	008e082a */ 	slt	$at,$a0,$t6
/*  f18d058:	10200003 */ 	beqz	$at,.L0f18d068
/*  f18d05c:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f18d060:	03e00008 */ 	jr	$ra
/*  f18d064:	8c42c4d0 */ 	lw	$v0,-0x3b30($v0)
.L0f18d068:
/*  f18d068:	00001025 */ 	or	$v0,$zero,$zero
/*  f18d06c:	03e00008 */ 	jr	$ra
/*  f18d070:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18d074
/*  f18d074:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18d078:	3c05800b */ 	lui	$a1,0x800b
/*  f18d07c:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f18d080:	3c02800b */ 	lui	$v0,%hi(g_MpPlayers)
/*  f18d084:	2442c7b8 */ 	addiu	$v0,$v0,%lo(g_MpPlayers)
/*  f18d088:	8ca5c500 */ 	lw	$a1,-0x3b00($a1)
/*  f18d08c:	00001825 */ 	or	$v1,$zero,$zero
.L0f18d090:
/*  f18d090:	54450004 */ 	bnel	$v0,$a1,.L0f18d0a4
/*  f18d094:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d098:	03e00008 */ 	jr	$ra
/*  f18d09c:	00601025 */ 	or	$v0,$v1,$zero
/*  f18d0a0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d0a4:
/*  f18d0a4:	28610004 */ 	slti	$at,$v1,0x4
/*  f18d0a8:	1420fff9 */ 	bnez	$at,.L0f18d090
/*  f18d0ac:	244200a0 */ 	addiu	$v0,$v0,0xa0
/*  f18d0b0:	3c02800b */ 	lui	$v0,%hi(g_MpSimulants)
/*  f18d0b4:	2442c538 */ 	addiu	$v0,$v0,%lo(g_MpSimulants)
/*  f18d0b8:	00001825 */ 	or	$v1,$zero,$zero
/*  f18d0bc:	24040008 */ 	addiu	$a0,$zero,0x8
.L0f18d0c0:
/*  f18d0c0:	54450004 */ 	bnel	$v0,$a1,.L0f18d0d4
/*  f18d0c4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d0c8:	03e00008 */ 	jr	$ra
/*  f18d0cc:	24620004 */ 	addiu	$v0,$v1,0x4
/*  f18d0d0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d0d4:
/*  f18d0d4:	1464fffa */ 	bne	$v1,$a0,.L0f18d0c0
/*  f18d0d8:	2442004c */ 	addiu	$v0,$v0,0x4c
/*  f18d0dc:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f18d0e0:	03e00008 */ 	jr	$ra
/*  f18d0e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f18d0e8
/*  f18d0e8:	28810004 */ 	slti	$at,$a0,0x4
/*  f18d0ec:	10200018 */ 	beqz	$at,.L0f18d150
/*  f18d0f0:	3c02800b */ 	lui	$v0,0x800b
/*  f18d0f4:	3c02800b */ 	lui	$v0,0x800b
/*  f18d0f8:	8c42c530 */ 	lw	$v0,-0x3ad0($v0)
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
/*  f18d398:	3c038007 */ 	lui	$v1,0x8007
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
/*  f18d3c4:	8c631448 */ 	lw	$v1,0x1448($v1)
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

u32 func0f18db7c(void)
{
	return 14;
}

GLOBAL_ASM(
glabel func0f18db84
/*  f18db84:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18db88:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18db8c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f18db90:	3c0f8008 */ 	lui	$t7,%hi(mppresets)
/*  f18db94:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18db98:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18db9c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18dba0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18dba4:	25ef7b6c */ 	addiu	$t7,$t7,%lo(mppresets)
/*  f18dba8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f18dbac:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18dbb0:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f18dbb4:	00008825 */ 	or	$s1,$zero,$zero
/*  f18dbb8:	24120016 */ 	addiu	$s2,$zero,0x16
/*  f18dbbc:	24130010 */ 	addiu	$s3,$zero,0x10
.L0f18dbc0:
/*  f18dbc0:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f18dbc4:	92040008 */ 	lbu	$a0,0x8($s0)
/*  f18dbc8:	14400006 */ 	bnez	$v0,.L0f18dbe4
/*  f18dbcc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18dbd0:	92180008 */ 	lbu	$t8,0x8($s0)
/*  f18dbd4:	12580003 */ 	beq	$s2,$t8,.L0f18dbe4
/*  f18dbd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18dbdc:	10000004 */ 	beqz	$zero,.L0f18dbf0
/*  f18dbe0:	00001025 */ 	or	$v0,$zero,$zero
.L0f18dbe4:
/*  f18dbe4:	1633fff6 */ 	bne	$s1,$s3,.L0f18dbc0
/*  f18dbe8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18dbec:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18dbf0:
/*  f18dbf0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18dbf4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18dbf8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18dbfc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18dc00:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18dc04:	03e00008 */ 	jr	$ra
/*  f18dc08:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18dc0c
/*  f18dc0c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18dc10:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18dc14:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18dc18:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18dc1c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18dc20:	00008825 */ 	or	$s1,$zero,$zero
/*  f18dc24:	00008025 */ 	or	$s0,$zero,$zero
/*  f18dc28:	2412000e */ 	addiu	$s2,$zero,0xe
.L0f18dc2c:
/*  f18dc2c:	0fc636e1 */ 	jal	func0f18db84
/*  f18dc30:	02002025 */ 	or	$a0,$s0,$zero
/*  f18dc34:	10400002 */ 	beqz	$v0,.L0f18dc40
/*  f18dc38:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18dc3c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18dc40:
/*  f18dc40:	1612fffa */ 	bne	$s0,$s2,.L0f18dc2c
/*  f18dc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18dc48:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18dc4c:	02201025 */ 	or	$v0,$s1,$zero
/*  f18dc50:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18dc54:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18dc58:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18dc5c:	03e00008 */ 	jr	$ra
/*  f18dc60:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18dc64
/*  f18dc64:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18dc68:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18dc6c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18dc70:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18dc74:	00808825 */ 	or	$s1,$a0,$zero
/*  f18dc78:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18dc7c:	00008025 */ 	or	$s0,$zero,$zero
/*  f18dc80:	2412000e */ 	addiu	$s2,$zero,0xe
.L0f18dc84:
/*  f18dc84:	0fc636e1 */ 	jal	func0f18db84
/*  f18dc88:	02002025 */ 	or	$a0,$s0,$zero
/*  f18dc8c:	5040000d */ 	beqzl	$v0,.L0f18dcc4
/*  f18dc90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18dc94:	16200009 */ 	bnez	$s1,.L0f18dcbc
/*  f18dc98:	00107080 */ 	sll	$t6,$s0,0x2
/*  f18dc9c:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18dca0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f18dca4:	3c048008 */ 	lui	$a0,0x8008
/*  f18dca8:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f18dcac:	0fc5b9f1 */ 	jal	textGet
/*  f18dcb0:	94847b6c */ 	lhu	$a0,0x7b6c($a0)
/*  f18dcb4:	10000008 */ 	beqz	$zero,.L0f18dcd8
/*  f18dcb8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f18dcbc:
/*  f18dcbc:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f18dcc0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18dcc4:
/*  f18dcc4:	1612ffef */ 	bne	$s0,$s2,.L0f18dc84
/*  f18dcc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18dccc:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f18dcd0:	24428c3c */ 	addiu	$v0,$v0,-29636
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
/*  f18ddbc:	3c0d8009 */ 	lui	$t5,0x8009
/*  f18ddc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18ddc4:	a22c0048 */ 	sb	$t4,0x48($s1)
/*  f18ddc8:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f18ddcc:	00137100 */ 	sll	$t6,$s3,0x4
/*  f18ddd0:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f18ddd4:	15a1000a */ 	bne	$t5,$at,.L0f18de00
/*  f18ddd8:	02202025 */ 	or	$a0,$s1,$zero
/*  f18dddc:	0fc5b9f1 */ 	jal	textGet
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
/*  f18dee8:	0fc636e1 */ 	jal	func0f18db84
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
/*  f18e580:	3c02800b */ 	lui	$v0,0x800b
/*  f18e584:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f18e588:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f18e58c:	03e00008 */ 	jr	$ra
/*  f18e590:	8c42cc28 */ 	lw	$v0,-0x33d8($v0)
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

GLOBAL_ASM(
glabel teamGetIndex
/*  f18e968:	308e0001 */ 	andi	$t6,$a0,0x1
/*  f18e96c:	15c0001d */ 	bnez	$t6,.L0f18e9e4
/*  f18e970:	00001825 */ 	or	$v1,$zero,$zero
/*  f18e974:	308f0002 */ 	andi	$t7,$a0,0x2
/*  f18e978:	11e00003 */ 	beqz	$t7,.L0f18e988
/*  f18e97c:	30980004 */ 	andi	$t8,$a0,0x4
/*  f18e980:	03e00008 */ 	jr	$ra
/*  f18e984:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18e988:
/*  f18e988:	13000003 */ 	beqz	$t8,.L0f18e998
/*  f18e98c:	30990008 */ 	andi	$t9,$a0,0x8
/*  f18e990:	03e00008 */ 	jr	$ra
/*  f18e994:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f18e998:
/*  f18e998:	13200003 */ 	beqz	$t9,.L0f18e9a8
/*  f18e99c:	30880010 */ 	andi	$t0,$a0,0x10
/*  f18e9a0:	03e00008 */ 	jr	$ra
/*  f18e9a4:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f18e9a8:
/*  f18e9a8:	11000003 */ 	beqz	$t0,.L0f18e9b8
/*  f18e9ac:	30890020 */ 	andi	$t1,$a0,0x20
/*  f18e9b0:	03e00008 */ 	jr	$ra
/*  f18e9b4:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f18e9b8:
/*  f18e9b8:	11200003 */ 	beqz	$t1,.L0f18e9c8
/*  f18e9bc:	308a0040 */ 	andi	$t2,$a0,0x40
/*  f18e9c0:	03e00008 */ 	jr	$ra
/*  f18e9c4:	24020005 */ 	addiu	$v0,$zero,0x5
.L0f18e9c8:
/*  f18e9c8:	11400003 */ 	beqz	$t2,.L0f18e9d8
/*  f18e9cc:	308b0080 */ 	andi	$t3,$a0,0x80
/*  f18e9d0:	03e00008 */ 	jr	$ra
/*  f18e9d4:	24020006 */ 	addiu	$v0,$zero,0x6
.L0f18e9d8:
/*  f18e9d8:	11600002 */ 	beqz	$t3,.L0f18e9e4
/*  f18e9dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18e9e0:	24030007 */ 	addiu	$v1,$zero,0x7
.L0f18e9e4:
/*  f18e9e4:	03e00008 */ 	jr	$ra
/*  f18e9e8:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18e9ec
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
/*  f18eac4:	0c0068f7 */ 	jal	func0001a3dc
/*  f18eac8:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f18eacc:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18ead0:	3c19800b */ 	lui	$t9,0x800b
/*  f18ead4:	8f39cc70 */ 	lw	$t9,-0x3390($t9)
/*  f18ead8:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f18eadc:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f18eae0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f18eae4:	44184000 */ 	mfc1	$t8,$f8
/*  f18eae8:	0c0068f4 */ 	jal	func0001a3d0
/*  f18eaec:	03198821 */ 	addu	$s1,$t8,$t9
/*  f18eaf0:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18eaf4:	8fac00f4 */ 	lw	$t4,0xf4($sp)
/*  f18eaf8:	3c0b800b */ 	lui	$t3,0x800b
/*  f18eafc:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f18eb00:	8d6bcc74 */ 	lw	$t3,-0x338c($t3)
/*  f18eb04:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f18eb08:	440a9000 */ 	mfc1	$t2,$f18
/*  f18eb0c:	118001a8 */ 	beqz	$t4,.L0f18f1b0
/*  f18eb10:	014ba021 */ 	addu	$s4,$t2,$t3
/*  f18eb14:	8ead0284 */ 	lw	$t5,0x284($s5)
/*  f18eb18:	02002025 */ 	or	$a0,$s0,$zero
/*  f18eb1c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18eb20:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f18eb24:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18eb28:	3c028008 */ 	lui	$v0,0x8008
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
/*  f18ed48:	8c427cc0 */ 	lw	$v0,0x7cc0($v0)
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
/*  f18f1c4:	3c028008 */ 	lui	$v0,0x8008
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
/*  f18f3e4:	8c427cc0 */ 	lw	$v0,0x7cc0($v0)
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
/*  f18f888:	3c0e800b */ 	lui	$t6,0x800b
/*  f18f88c:	8dceb5ac */ 	lw	$t6,-0x4a54($t6)
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
/*  f18f9d0:	3c198007 */ 	lui	$t9,0x8007
/*  f18f9d4:	11e00003 */ 	beqz	$t7,.L0f18f9e4
/*  f18f9d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f18f9dc:
/*  f18f9dc:	1000019a */ 	beqz	$zero,.L0f190048
/*  f18f9e0:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f18f9e4:
/*  f18f9e4:	8f3906c8 */ 	lw	$t9,0x6c8($t9)
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
/*  f18fa20:	3c0d8008 */ 	lui	$t5,0x8008
/*  f18fa24:	8dadfac0 */ 	lw	$t5,-0x540($t5)
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
/*  f18fa74:	3c028009 */ 	lui	$v0,0x8009
/*  f18fa78:	90420af0 */ 	lbu	$v0,0xaf0($v0)
/*  f18fa7c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fa80:	50410008 */ 	beql	$v0,$at,.L0f18faa4
/*  f18fa84:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f18fa88:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f18fa8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fa90:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18fa94:	1441000f */ 	bne	$v0,$at,.L0f18fad4
/*  f18fa98:	3c028009 */ 	lui	$v0,0x8009
/*  f18fa9c:	90420af0 */ 	lbu	$v0,0xaf0($v0)
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
/*  f18fb40:	3c198009 */ 	lui	$t9,0x8009
/*  f18fb44:	93390af0 */ 	lbu	$t9,0xaf0($t9)
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
/*  f18fcfc:	3c078008 */ 	lui	$a3,0x8008
/*  f18fd00:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f18fd04:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f18fd08:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f18fd0c:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18fd10:	9063c7c9 */ 	lbu	$v1,-0x3837($v1)
/*  f18fd14:	00036080 */ 	sll	$t4,$v1,0x2
/*  f18fd18:	00ec3821 */ 	addu	$a3,$a3,$t4
/*  f18fd1c:	10000001 */ 	beqz	$zero,.L0f18fd24
/*  f18fd20:	8ce77cc4 */ 	lw	$a3,0x7cc4($a3)
.L0f18fd24:
/*  f18fd24:	8c4500bc */ 	lw	$a1,0xbc($v0)
/*  f18fd28:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18fd2c:	0fc63a7b */ 	jal	func0f18e9ec
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
/*  f18fe10:	0fc63a7b */ 	jal	func0f18e9ec
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
/*  f18fe40:	3c188008 */ 	lui	$t8,0x8008
/*  f18fe44:	11c00046 */ 	beqz	$t6,.L0f18ff60
/*  f18fe48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18fe4c:	93187d10 */ 	lbu	$t8,0x7d10($t8)
/*  f18fe50:	3c10800b */ 	lui	$s0,%hi(var800acc80)
/*  f18fe54:	2610cc80 */ 	addiu	$s0,$s0,%lo(var800acc80)
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
/*  f18ff14:	3c078008 */ 	lui	$a3,0x8008
/*  f18ff18:	00eb3821 */ 	addu	$a3,$a3,$t3
/*  f18ff1c:	8ce77cc4 */ 	lw	$a3,0x7cc4($a3)
/*  f18ff20:	10000001 */ 	beqz	$zero,.L0f18ff28
/*  f18ff24:	8e030000 */ 	lw	$v1,0x0($s0)
.L0f18ff28:
/*  f18ff28:	8c65001c */ 	lw	$a1,0x1c($v1)
/*  f18ff2c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18ff30:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f18ff34:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18ff38:	0fc63a7b */ 	jal	func0f18e9ec
/*  f18ff3c:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f18ff40:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f18ff44:
/*  f18ff44:	3c0c8008 */ 	lui	$t4,0x8008
/*  f18ff48:	918c7d10 */ 	lbu	$t4,0x7d10($t4)
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
/*  f18ff8c:	0fc64018 */ 	jal	func0f190060
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
/*  f18ffec:	3c078008 */ 	lui	$a3,0x8008
/*  f18fff0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18fff4:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f18fff8:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18fffc:	00591021 */ 	addu	$v0,$v0,$t9
/*  f190000:	9042c7c9 */ 	lbu	$v0,-0x3837($v0)
/*  f190004:	00025080 */ 	sll	$t2,$v0,0x2
/*  f190008:	00ea3821 */ 	addu	$a3,$a3,$t2
/*  f19000c:	10000002 */ 	beqz	$zero,.L0f190018
/*  f190010:	8ce77cc4 */ 	lw	$a3,0x7cc4($a3)
.L0f190014:
/*  f190014:	3c0700ff */ 	lui	$a3,0xff
.L0f190018:
/*  f190018:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f19001c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f190020:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f190024:	8d6500bc */ 	lw	$a1,0xbc($t3)
/*  f190028:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19002c:	0fc63a7b */ 	jal	func0f18e9ec
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

GLOBAL_ASM(
glabel func0f190060
/*  f190060:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f190064:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f190068:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f19006c:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f190070:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f190074:	8c50033c */ 	lw	$s0,0x33c($v0)
/*  f190078:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f19007c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f190080:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f190084:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f190088:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f19008c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f190090:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f190094:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f190098:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f19009c:	8dd200bc */ 	lw	$s2,0xbc($t6)
/*  f1900a0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1900a4:	1200005f */ 	beqz	$s0,.L0f190224
/*  f1900a8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1900ac:	3c1effff */ 	lui	$s8,0xffff
/*  f1900b0:	24170003 */ 	addiu	$s7,$zero,0x3
/*  f1900b4:	24160002 */ 	addiu	$s6,$zero,0x2
/*  f1900b8:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f1900bc:	24140004 */ 	addiu	$s4,$zero,0x4
/*  f1900c0:	92070000 */ 	lbu	$a3,0x0($s0)
.L0f1900c4:
/*  f1900c4:	50f50008 */ 	beql	$a3,$s5,.L0f1900e8
/*  f1900c8:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f1900cc:	50f60006 */ 	beql	$a3,$s6,.L0f1900e8
/*  f1900d0:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f1900d4:	50f7002c */ 	beql	$a3,$s7,.L0f190188
/*  f1900d8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f1900dc:	54f4004f */ 	bnel	$a3,$s4,.L0f19021c
/*  f1900e0:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f1900e4:	8e110004 */ 	lw	$s1,0x4($s0)
.L0f1900e8:
/*  f1900e8:	8e2f0010 */ 	lw	$t7,0x10($s1)
/*  f1900ec:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f1900f0:	5700000a */ 	bnezl	$t8,.L0f19011c
/*  f1900f4:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f1900f8:	0fc41b99 */ 	jal	cheatIsActive
/*  f1900fc:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f190100:	50400046 */ 	beqzl	$v0,.L0f19021c
/*  f190104:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f190108:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f19010c:	33280800 */ 	andi	$t0,$t9,0x800
/*  f190110:	51000042 */ 	beqzl	$t0,.L0f19021c
/*  f190114:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f190118:	c6040008 */ 	lwc1	$f4,0x8($s0)
.L0f19011c:
/*  f19011c:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f190120:	02602025 */ 	or	$a0,$s3,$zero
/*  f190124:	02002825 */ 	or	$a1,$s0,$zero
/*  f190128:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f19012c:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f190130:	3407ff00 */ 	dli	$a3,0xff00
/*  f190134:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f190138:	c6500004 */ 	lwc1	$f16,0x4($s2)
/*  f19013c:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*  f190140:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f190144:	e7b20064 */ 	swc1	$f18,0x64($sp)
/*  f190148:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f19014c:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f190150:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f190154:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f190158:	8e290010 */ 	lw	$t1,0x10($s1)
/*  f19015c:	312a0040 */ 	andi	$t2,$t1,0x40
/*  f190160:	11400003 */ 	beqz	$t2,.L0f190170
/*  f190164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190168:	10000001 */ 	beqz	$zero,.L0f190170
/*  f19016c:	03c03825 */ 	or	$a3,$s8,$zero
.L0f190170:
/*  f190170:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f190174:	0fc63a7b */ 	jal	func0f18e9ec
/*  f190178:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19017c:	10000026 */ 	beqz	$zero,.L0f190218
/*  f190180:	00409825 */ 	or	$s3,$v0,$zero
/*  f190184:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f190188:
/*  f190188:	50400024 */ 	beqzl	$v0,.L0f19021c
/*  f19018c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f190190:	8c4b032c */ 	lw	$t3,0x32c($v0)
/*  f190194:	000b6d00 */ 	sll	$t5,$t3,0x14
/*  f190198:	05a30020 */ 	bgezl	$t5,.L0f19021c
/*  f19019c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f1901a0:	80430007 */ 	lb	$v1,0x7($v0)
/*  f1901a4:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1901a8:	5283001c */ 	beql	$s4,$v1,.L0f19021c
/*  f1901ac:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f1901b0:	5061001a */ 	beql	$v1,$at,.L0f19021c
/*  f1901b4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f1901b8:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f1901bc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1901c0:	05e20016 */ 	bltzl	$t7,.L0f19021c
/*  f1901c4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f1901c8:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f1901cc:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f1901d0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1901d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1901d8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1901dc:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f1901e0:	3c07ff00 */ 	lui	$a3,0xff00
/*  f1901e4:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*  f1901e8:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f1901ec:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f1901f0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1901f4:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f1901f8:	c6500008 */ 	lwc1	$f16,0x8($s2)
/*  f1901fc:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f190200:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f190204:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f190208:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f19020c:	0fc63a7b */ 	jal	func0f18e9ec
/*  f190210:	e7b20058 */ 	swc1	$f18,0x58($sp)
/*  f190214:	00409825 */ 	or	$s3,$v0,$zero
.L0f190218:
/*  f190218:	8e100020 */ 	lw	$s0,0x20($s0)
.L0f19021c:
/*  f19021c:	5600ffa9 */ 	bnezl	$s0,.L0f1900c4
/*  f190220:	92070000 */ 	lbu	$a3,0x0($s0)
.L0f190224:
/*  f190224:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f190228:	02601025 */ 	or	$v0,$s3,$zero
/*  f19022c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f190230:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f190234:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f190238:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f19023c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f190240:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f190244:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f190248:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f19024c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f190250:	03e00008 */ 	jr	$ra
/*  f190254:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f190258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19025c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f190260
/*  f190260:	8c8f02d4 */ 	lw	$t7,0x2d4($a0)
/*  f190264:	3c098008 */ 	lui	$t1,0x8008
/*  f190268:	848e02d8 */ 	lh	$t6,0x2d8($a0)
/*  f19026c:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f190270:	93190048 */ 	lbu	$t9,0x48($t8)
/*  f190274:	00194140 */ 	sll	$t0,$t9,0x5
/*  f190278:	01284821 */ 	addu	$t1,$t1,$t0
/*  f19027c:	8d297d30 */ 	lw	$t1,0x7d30($t1)
/*  f190280:	01c9102a */ 	slt	$v0,$t6,$t1
/*  f190284:	03e00008 */ 	jr	$ra
/*  f190288:	38420001 */ 	xori	$v0,$v0,0x1
);

GLOBAL_ASM(
glabel func0f19028c
/*  f19028c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f190290:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f190294:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f190298:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19029c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1902a0:	8c9002d4 */ 	lw	$s0,0x2d4($a0)
/*  f1902a4:	00808825 */ 	or	$s1,$a0,$zero
/*  f1902a8:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f1902ac:	120000cb */ 	beqz	$s0,.L0f1905dc
/*  f1902b0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f1902b4:	8c980018 */ 	lw	$t8,0x18($a0)
/*  f1902b8:	2401feff */ 	addiu	$at,$zero,-257
/*  f1902bc:	8c880014 */ 	lw	$t0,0x14($a0)
/*  f1902c0:	0301c824 */ 	and	$t9,$t8,$at
/*  f1902c4:	3c01dfff */ 	lui	$at,0xdfff
/*  f1902c8:	44801000 */ 	mtc1	$zero,$f2
/*  f1902cc:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1902d0:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f1902d4:	01014824 */ 	and	$t1,$t0,$at
/*  f1902d8:	a08f000c */ 	sb	$t7,0xc($a0)
/*  f1902dc:	ac990018 */ 	sw	$t9,0x18($a0)
/*  f1902e0:	ac890014 */ 	sw	$t1,0x14($a0)
/*  f1902e4:	a08a02a0 */ 	sb	$t2,0x2a0($a0)
/*  f1902e8:	11c000a0 */ 	beqz	$t6,.L0f19056c
/*  f1902ec:	e482014c */ 	swc1	$f2,0x14c($a0)
/*  f1902f0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1902f4:	44051000 */ 	mfc1	$a1,$f2
/*  f1902f8:	a080000a */ 	sb	$zero,0xa($a0)
/*  f1902fc:	e4820100 */ 	swc1	$f2,0x100($a0)
/*  f190300:	a486017e */ 	sh	$a2,0x17e($a0)
/*  f190304:	a486012a */ 	sh	$a2,0x12a($a0)
/*  f190308:	0fc0cfea */ 	jal	chrSetShield
/*  f19030c:	a4860292 */ 	sh	$a2,0x292($a0)
/*  f190310:	a2200184 */ 	sb	$zero,0x184($s1)
/*  f190314:	a2200185 */ 	sb	$zero,0x185($s1)
/*  f190318:	0fc29c32 */ 	jal	freeFireslot
/*  f19031c:	8224017c */ 	lb	$a0,0x17c($s1)
/*  f190320:	0fc29c32 */ 	jal	freeFireslot
/*  f190324:	8224017d */ 	lb	$a0,0x17d($s1)
/*  f190328:	922b032d */ 	lbu	$t3,0x32d($s1)
/*  f19032c:	3c014339 */ 	lui	$at,0x4339
/*  f190330:	44812000 */ 	mtc1	$at,$f4
/*  f190334:	316dfff3 */ 	andi	$t5,$t3,0xfff3
/*  f190338:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f19033c:	a22d032d */ 	sb	$t5,0x32d($s1)
/*  f190340:	31ae007f */ 	andi	$t6,$t5,0x7f
/*  f190344:	a226017c */ 	sb	$a2,0x17c($s1)
/*  f190348:	a226017d */ 	sb	$a2,0x17d($s1)
/*  f19034c:	a2200004 */ 	sb	$zero,0x4($s1)
/*  f190350:	a2200005 */ 	sb	$zero,0x5($s1)
/*  f190354:	ae200170 */ 	sw	$zero,0x170($s1)
/*  f190358:	ae200174 */ 	sw	$zero,0x174($s1)
/*  f19035c:	ae200178 */ 	sw	$zero,0x178($s1)
/*  f190360:	a220032c */ 	sb	$zero,0x32c($s1)
/*  f190364:	a22e032d */ 	sb	$t6,0x32d($s1)
/*  f190368:	ae200364 */ 	sw	$zero,0x364($s1)
/*  f19036c:	00001825 */ 	or	$v1,$zero,$zero
/*  f190370:	e6240028 */ 	swc1	$f4,0x28($s1)
.L0f190374:
/*  f190374:	8e0f001c */ 	lw	$t7,0x1c($s0)
/*  f190378:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f19037c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f190380:	28610084 */ 	slti	$at,$v1,0x84
/*  f190384:	1420fffb */ 	bnez	$at,.L0f190374
/*  f190388:	af000000 */ 	sw	$zero,0x0($t8)
/*  f19038c:	0fc65f00 */ 	jal	func0f197c00
/*  f190390:	02202025 */ 	or	$a0,$s1,$zero
/*  f190394:	9208004c */ 	lbu	$t0,0x4c($s0)
/*  f190398:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f19039c:	44801000 */ 	mtc1	$zero,$f2
/*  f1903a0:	310bffdf */ 	andi	$t3,$t0,0xffdf
/*  f1903a4:	31d8ff7f */ 	andi	$t8,$t6,0xff7f
/*  f1903a8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1903ac:	35680040 */ 	ori	$t0,$t3,0x40
/*  f1903b0:	a20b004c */ 	sb	$t3,0x4c($s0)
/*  f1903b4:	310c00fd */ 	andi	$t4,$t0,0xfd
/*  f1903b8:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f1903bc:	a218009c */ 	sb	$t8,0x9c($s0)
/*  f1903c0:	330a00bf */ 	andi	$t2,$t8,0xbf
/*  f1903c4:	318e00f7 */ 	andi	$t6,$t4,0xf7
/*  f1903c8:	a20c004c */ 	sb	$t4,0x4c($s0)
/*  f1903cc:	31d800ef */ 	andi	$t8,$t6,0xef
/*  f1903d0:	a20e004c */ 	sb	$t6,0x4c($s0)
/*  f1903d4:	330800fb */ 	andi	$t0,$t8,0xfb
/*  f1903d8:	a218004c */ 	sb	$t8,0x4c($s0)
/*  f1903dc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1903e0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1903e4:	240d012d */ 	addiu	$t5,$zero,0x12d
/*  f1903e8:	a20a009c */ 	sb	$t2,0x9c($s0)
/*  f1903ec:	314b00df */ 	andi	$t3,$t2,0xdf
/*  f1903f0:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f1903f4:	3109007f */ 	andi	$t1,$t0,0x7f
/*  f1903f8:	44810000 */ 	mtc1	$at,$f0
/*  f1903fc:	ae190020 */ 	sw	$t9,0x20($s0)
/*  f190400:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f190404:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f190408:	ae000010 */ 	sw	$zero,0x10($s0)
/*  f19040c:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f190410:	a600002e */ 	sh	$zero,0x2e($s0)
/*  f190414:	ae00005c */ 	sw	$zero,0x5c($s0)
/*  f190418:	ae000060 */ 	sw	$zero,0x60($s0)
/*  f19041c:	a2060074 */ 	sb	$a2,0x74($s0)
/*  f190420:	ae0d0030 */ 	sw	$t5,0x30($s0)
/*  f190424:	ae000034 */ 	sw	$zero,0x34($s0)
/*  f190428:	a200004d */ 	sb	$zero,0x4d($s0)
/*  f19042c:	a200004e */ 	sb	$zero,0x4e($s0)
/*  f190430:	ae000044 */ 	sw	$zero,0x44($s0)
/*  f190434:	ae0000a0 */ 	sw	$zero,0xa0($s0)
/*  f190438:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19043c:	a6000064 */ 	sh	$zero,0x64($s0)
/*  f190440:	a209004c */ 	sb	$t1,0x4c($s0)
/*  f190444:	a6060048 */ 	sh	$a2,0x48($s0)
/*  f190448:	a606004a */ 	sh	$a2,0x4a($s0)
/*  f19044c:	ae0600bc */ 	sw	$a2,0xbc($s0)
/*  f190450:	ae0000c8 */ 	sw	$zero,0xc8($s0)
/*  f190454:	ae0000c4 */ 	sw	$zero,0xc4($s0)
/*  f190458:	ae0000cc */ 	sw	$zero,0xcc($s0)
/*  f19045c:	ae0000d0 */ 	sw	$zero,0xd0($s0)
/*  f190460:	ae0000d8 */ 	sw	$zero,0xd8($s0)
/*  f190464:	ae0000dc */ 	sw	$zero,0xdc($s0)
/*  f190468:	a606003e */ 	sh	$a2,0x3e($s0)
/*  f19046c:	a600003c */ 	sh	$zero,0x3c($s0)
/*  f190470:	a60000e2 */ 	sh	$zero,0xe2($s0)
/*  f190474:	a60000e0 */ 	sh	$zero,0xe0($s0)
/*  f190478:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f19047c:	ae00011c */ 	sw	$zero,0x11c($s0)
/*  f190480:	ae060120 */ 	sw	$a2,0x120($s0)
/*  f190484:	ae060124 */ 	sw	$a2,0x124($s0)
/*  f190488:	ae000128 */ 	sw	$zero,0x128($s0)
/*  f19048c:	ae00012c */ 	sw	$zero,0x12c($s0)
/*  f190490:	00002025 */ 	or	$a0,$zero,$zero
/*  f190494:	02001025 */ 	or	$v0,$s0,$zero
/*  f190498:	02001825 */ 	or	$v1,$s0,$zero
/*  f19049c:	02002825 */ 	or	$a1,$s0,$zero
/*  f1904a0:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f1904a4:	e6020040 */ 	swc1	$f2,0x40($s0)
/*  f1904a8:	e602006c */ 	swc1	$f2,0x6c($s0)
/*  f1904ac:	e6020070 */ 	swc1	$f2,0x70($s0)
/*  f1904b0:	e60200e8 */ 	swc1	$f2,0xe8($s0)
/*  f1904b4:	e60200e4 */ 	swc1	$f2,0xe4($s0)
/*  f1904b8:	e6020108 */ 	swc1	$f2,0x108($s0)
/*  f1904bc:	e602010c */ 	swc1	$f2,0x10c($s0)
/*  f1904c0:	e6020110 */ 	swc1	$f2,0x110($s0)
.L0f1904c4:
/*  f1904c4:	a0460130 */ 	sb	$a2,0x130($v0)
/*  f1904c8:	e460013c */ 	swc1	$f0,0x13c($v1)
/*  f1904cc:	a040016c */ 	sb	$zero,0x16c($v0)
/*  f1904d0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1904d4:	ac660178 */ 	sw	$a2,0x178($v1)
/*  f1904d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1904dc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1904e0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f1904e4:	1487fff7 */ 	bne	$a0,$a3,.L0f1904c4
/*  f1904e8:	a4a601a6 */ 	sh	$a2,0x1a6($a1)
/*  f1904ec:	ae0001e8 */ 	sw	$zero,0x1e8($s0)
/*  f1904f0:	0c004b70 */ 	jal	random
/*  f1904f4:	ae000208 */ 	sw	$zero,0x208($s0)
/*  f1904f8:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f1904fc:	44801000 */ 	mtc1	$zero,$f2
/*  f190500:	ae020210 */ 	sw	$v0,0x210($s0)
/*  f190504:	314bffef */ 	andi	$t3,$t2,0xffef
/*  f190508:	ae00020c */ 	sw	$zero,0x20c($s0)
/*  f19050c:	ae0002c8 */ 	sw	$zero,0x2c8($s0)
/*  f190510:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f190514:	ae0002cc */ 	sw	$zero,0x2cc($s0)
/*  f190518:	0c004b70 */ 	jal	random
/*  f19051c:	e60202c4 */ 	swc1	$f2,0x2c4($s0)
/*  f190520:	0c004b70 */ 	jal	random
/*  f190524:	ae0202d0 */ 	sw	$v0,0x2d0($s0)
/*  f190528:	44823000 */ 	mtc1	$v0,$f6
/*  f19052c:	3c014f80 */ 	lui	$at,0x4f80
/*  f190530:	04410004 */ 	bgez	$v0,.L0f190544
/*  f190534:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f190538:	44815000 */ 	mtc1	$at,$f10
/*  f19053c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190540:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f190544:
/*  f190544:	3c012f80 */ 	lui	$at,0x2f80
/*  f190548:	44818000 */ 	mtc1	$at,$f16
/*  f19054c:	920c009c */ 	lbu	$t4,0x9c($s0)
/*  f190550:	a2000078 */ 	sb	$zero,0x78($s0)
/*  f190554:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f190558:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*  f19055c:	a20d009c */ 	sb	$t5,0x9c($s0)
/*  f190560:	ae000050 */ 	sw	$zero,0x50($s0)
/*  f190564:	a200009d */ 	sb	$zero,0x9d($s0)
/*  f190568:	e61202d4 */ 	swc1	$f18,0x2d4($s0)
.L0f19056c:
/*  f19056c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f190570:	2401000b */ 	addiu	$at,$zero,0xb
/*  f190574:	90430047 */ 	lbu	$v1,0x47($v0)
/*  f190578:	10610002 */ 	beq	$v1,$at,.L0f190584
/*  f19057c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f190580:	14610005 */ 	bne	$v1,$at,.L0f190598
.L0f190584:
/*  f190584:	3c014100 */ 	lui	$at,0x4100
/*  f190588:	44812000 */ 	mtc1	$at,$f4
/*  f19058c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190590:	e6240180 */ 	swc1	$f4,0x180($s1)
/*  f190594:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f190598:
/*  f190598:	904e0048 */ 	lbu	$t6,0x48($v0)
/*  f19059c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1905a0:	55c1000b */ 	bnel	$t6,$at,.L0f1905d0
/*  f1905a4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1905a8:	960f0064 */ 	lhu	$t7,0x64($s0)
/*  f1905ac:	31f8fffe */ 	andi	$t8,$t7,0xfffe
/*  f1905b0:	0fc6609e */ 	jal	func0f198278
/*  f1905b4:	a6180064 */ 	sh	$t8,0x64($s0)
/*  f1905b8:	10400004 */ 	beqz	$v0,.L0f1905cc
/*  f1905bc:	3c014100 */ 	lui	$at,0x4100
/*  f1905c0:	44813000 */ 	mtc1	$at,$f6
/*  f1905c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1905c8:	e6260180 */ 	swc1	$f6,0x180($s1)
.L0f1905cc:
/*  f1905cc:	24190001 */ 	addiu	$t9,$zero,0x1
.L0f1905d0:
/*  f1905d0:	24080078 */ 	addiu	$t0,$zero,0x78
/*  f1905d4:	a2190059 */ 	sb	$t9,0x59($s0)
/*  f1905d8:	a2080058 */ 	sb	$t0,0x58($s0)
.L0f1905dc:
/*  f1905dc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1905e0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1905e4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1905e8:	03e00008 */ 	jr	$ra
/*  f1905ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f1905f0
/*  f1905f0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f1905f4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1905f8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1905fc:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f190600:	8c83001c */ 	lw	$v1,0x1c($a0)
/*  f190604:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f190608:	01c02825 */ 	or	$a1,$t6,$zero
/*  f19060c:	00808025 */ 	or	$s0,$a0,$zero
/*  f190610:	1060000d */ 	beqz	$v1,.L0f190648
/*  f190614:	8c8602d4 */ 	lw	$a2,0x2d4($a0)
/*  f190618:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f19061c:	1040000a */ 	beqz	$v0,.L0f190648
/*  f190620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190624:	8c430004 */ 	lw	$v1,0x4($v0)
.L0f190628:
/*  f190628:	50600005 */ 	beqzl	$v1,.L0f190640
/*  f19062c:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f190630:	8c6f0040 */ 	lw	$t7,0x40($v1)
/*  f190634:	35f80004 */ 	ori	$t8,$t7,0x4
/*  f190638:	ac780040 */ 	sw	$t8,0x40($v1)
/*  f19063c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f190640:
/*  f190640:	5440fff9 */ 	bnezl	$v0,.L0f190628
/*  f190644:	8c430004 */ 	lw	$v1,0x4($v0)
.L0f190648:
/*  f190648:	50c0002b */ 	beqzl	$a2,.L0f1906f8
/*  f19064c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f190650:	0fc640a3 */ 	jal	func0f19028c
/*  f190654:	02002025 */ 	or	$a0,$s0,$zero
/*  f190658:	0fc52719 */ 	jal	func0f149c64
/*  f19065c:	02002025 */ 	or	$a0,$s0,$zero
/*  f190660:	c60c0024 */ 	lwc1	$f12,0x24($s0)
/*  f190664:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f190668:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f19066c:	0fc6185f */ 	jal	scenarioCallback2c
/*  f190670:	8e07001c */ 	lw	$a3,0x1c($s0)
/*  f190674:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f190678:	3c010010 */ 	lui	$at,0x10
/*  f19067c:	44070000 */ 	mfc1	$a3,$f0
/*  f190680:	03214025 */ 	or	$t0,$t9,$at
/*  f190684:	ae080014 */ 	sw	$t0,0x14($s0)
/*  f190688:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f19068c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f190690:	02002025 */ 	or	$a0,$s0,$zero
/*  f190694:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f190698:	0fc12dd2 */ 	jal	func0f04b748
/*  f19069c:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f1906a0:	0c006b91 */ 	jal	func0001ae44
/*  f1906a4:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f1906a8:	8e0a02d4 */ 	lw	$t2,0x2d4($s0)
/*  f1906ac:	44801000 */ 	mtc1	$zero,$f2
/*  f1906b0:	e54000a4 */ 	swc1	$f0,0xa4($t2)
/*  f1906b4:	8e0b02d4 */ 	lw	$t3,0x2d4($s0)
/*  f1906b8:	e56200a8 */ 	swc1	$f2,0xa8($t3)
/*  f1906bc:	8e0c02d4 */ 	lw	$t4,0x2d4($s0)
/*  f1906c0:	e58200ac */ 	swc1	$f2,0xac($t4)
/*  f1906c4:	0c006b91 */ 	jal	func0001ae44
/*  f1906c8:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f1906cc:	8e0d02d4 */ 	lw	$t5,0x2d4($s0)
/*  f1906d0:	44801000 */ 	mtc1	$zero,$f2
/*  f1906d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1906d8:	e5a000b0 */ 	swc1	$f0,0xb0($t5)
/*  f1906dc:	8e0e02d4 */ 	lw	$t6,0x2d4($s0)
/*  f1906e0:	44051000 */ 	mfc1	$a1,$f2
/*  f1906e4:	e5c200b4 */ 	swc1	$f2,0xb4($t6)
/*  f1906e8:	8e0f02d4 */ 	lw	$t7,0x2d4($s0)
/*  f1906ec:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f1906f0:	e5e200b8 */ 	swc1	$f2,0xb8($t7)
/*  f1906f4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1906f8:
/*  f1906f8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1906fc:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f190700:	03e00008 */ 	jr	$ra
/*  f190704:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f190708
/*  f190708:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19070c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f190710:	3c128008 */ 	lui	$s2,%hi(var80087d10)
/*  f190714:	26527d10 */ 	addiu	$s2,$s2,%lo(var80087d10)
/*  f190718:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f19071c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f190720:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f190724:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f190728:	19c0000c */ 	blez	$t6,.L0f19075c
/*  f19072c:	00008025 */ 	or	$s0,$zero,$zero
/*  f190730:	3c11800b */ 	lui	$s1,%hi(var800acc80)
/*  f190734:	2631cc80 */ 	addiu	$s1,$s1,%lo(var800acc80)
/*  f190738:	8e240000 */ 	lw	$a0,0x0($s1)
.L0f19073c:
/*  f19073c:	0fc6417c */ 	jal	func0f1905f0
/*  f190740:	00002825 */ 	or	$a1,$zero,$zero
/*  f190744:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f190748:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19074c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f190750:	020f082a */ 	slt	$at,$s0,$t7
/*  f190754:	5420fff9 */ 	bnezl	$at,.L0f19073c
/*  f190758:	8e240000 */ 	lw	$a0,0x0($s1)
.L0f19075c:
/*  f19075c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f190760:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f190764:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f190768:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19076c:	03e00008 */ 	jr	$ra
/*  f190770:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f190774
/*  f190774:	3c018765 */ 	lui	$at,0x8765
/*  f190778:	34214321 */ 	ori	$at,$at,0x4321
/*  f19077c:	03e00008 */ 	jr	$ra
/*  f190780:	00811021 */ 	addu	$v0,$a0,$at
);

GLOBAL_ASM(
glabel func0f190784
/*  f190784:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f190788:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f19078c:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f190790:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f190794:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f190798:	10a00004 */ 	beqz	$a1,.L0f1907ac
/*  f19079c:	afaf009c */ 	sw	$t7,0x9c($sp)
/*  f1907a0:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f1907a4:	17000003 */ 	bnez	$t8,.L0f1907b4
/*  f1907a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1907ac:
/*  f1907ac:	10000108 */ 	beqz	$zero,.L0f190bd0
/*  f1907b0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1907b4:
/*  f1907b4:	0fc47bba */ 	jal	dprint
/*  f1907b8:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f1907bc:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f1907c0:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f1907c4:	8d190010 */ 	lw	$t9,0x10($t0)
/*  f1907c8:	910a0003 */ 	lbu	$t2,0x3($t0)
/*  f1907cc:	03214824 */ 	and	$t1,$t9,$at
/*  f1907d0:	254bfffd */ 	addiu	$t3,$t2,-3
/*  f1907d4:	2d61002d */ 	sltiu	$at,$t3,0x2d
/*  f1907d8:	102000fc */ 	beqz	$at,.L0f190bcc
/*  f1907dc:	ad090010 */ 	sw	$t1,0x10($t0)
/*  f1907e0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1907e4:	3c017f1c */ 	lui	$at,%hi(var7f1b8df0)
/*  f1907e8:	002b0821 */ 	addu	$at,$at,$t3
/*  f1907ec:	8c2b8df0 */ 	lw	$t3,%lo(var7f1b8df0)($at)
/*  f1907f0:	01600008 */ 	jr	$t3
/*  f1907f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1907f8:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f1907fc:	8d840004 */ 	lw	$a0,0x4($t4)
/*  f190800:	0fc22067 */ 	jal	func0f08819c
/*  f190804:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f190808:	0fc47bba */ 	jal	dprint
/*  f19080c:	00408025 */ 	or	$s0,$v0,$zero
/*  f190810:	12000006 */ 	beqz	$s0,.L0f19082c
/*  f190814:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f190818:	8fae0098 */ 	lw	$t6,0x98($sp)
/*  f19081c:	8da402d4 */ 	lw	$a0,0x2d4($t5)
/*  f190820:	02003025 */ 	or	$a2,$s0,$zero
/*  f190824:	0fc667bd */ 	jal	func0f199ef4
/*  f190828:	8dc5005c */ 	lw	$a1,0x5c($t6)
.L0f19082c:
/*  f19082c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f190830:	44810000 */ 	mtc1	$at,$f0
/*  f190834:	240fffff */ 	addiu	$t7,$zero,-1
/*  f190838:	24180400 */ 	addiu	$t8,$zero,0x400
/*  f19083c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f190840:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f190844:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f190848:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f19084c:	00002025 */ 	or	$a0,$zero,$zero
/*  f190850:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f190854:	240600ea */ 	addiu	$a2,$zero,0xea
/*  f190858:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19085c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f190860:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f190864:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f190868:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19086c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f190870:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f190874:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f190878:	0fc24e7e */ 	jal	func0f0939f8
/*  f19087c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f190880:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f190884:	00002825 */ 	or	$a1,$zero,$zero
/*  f190888:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f19088c:	30c90004 */ 	andi	$t1,$a2,0x4
/*  f190890:	0fc1ab4b */ 	jal	setupParseObject
/*  f190894:	01203025 */ 	or	$a2,$t1,$zero
/*  f190898:	12000003 */ 	beqz	$s0,.L0f1908a8
/*  f19089c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1908a0:	0fc47bba */ 	jal	dprint
/*  f1908a4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1908a8:
/*  f1908a8:	100000c9 */ 	beqz	$zero,.L0f190bd0
/*  f1908ac:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1908b0:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f1908b4:	3c057f09 */ 	lui	$a1,0x7f09
/*  f1908b8:	3c067f09 */ 	lui	$a2,0x7f09
/*  f1908bc:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f1908c0:	24a3e2ac */ 	addiu	$v1,$a1,-7508
/*  f1908c4:	24c4e3a4 */ 	addiu	$a0,$a2,-7260
/*  f1908c8:	0064082b */ 	sltu	$at,$v1,$a0
/*  f1908cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1908d0:	10200008 */ 	beqz	$at,.L0f1908f4
/*  f1908d4:	afab0090 */ 	sw	$t3,0x90($sp)
.L0f1908d8:
/*  f1908d8:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f1908dc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1908e0:	0064082b */ 	sltu	$at,$v1,$a0
/*  f1908e4:	004c1021 */ 	addu	$v0,$v0,$t4
/*  f1908e8:	00026840 */ 	sll	$t5,$v0,0x1
/*  f1908ec:	1420fffa */ 	bnez	$at,.L0f1908d8
/*  f1908f0:	01a01025 */ 	or	$v0,$t5,$zero
.L0f1908f4:
/*  f1908f4:	3c01a0bf */ 	lui	$at,0xa0bf
/*  f1908f8:	34211e60 */ 	ori	$at,$at,0x1e60
/*  f1908fc:	1041000e */ 	beq	$v0,$at,.L0f190938
/*  f190900:	3c049c9c */ 	lui	$a0,0x9c9c
/*  f190904:	0fc641dd */ 	jal	func0f190774
/*  f190908:	3484bce0 */ 	ori	$a0,$a0,0xbce0
/*  f19090c:	3c107f04 */ 	lui	$s0,0x7f04
/*  f190910:	2610978c */ 	addiu	$s0,$s0,-26740
/*  f190914:	3c047c7a */ 	lui	$a0,0x7c7a
/*  f190918:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f19091c:	0fc641dd */ 	jal	func0f190774
/*  f190920:	3484bce7 */ 	ori	$a0,$a0,0xbce7
/*  f190924:	3c04789a */ 	lui	$a0,0x789a
/*  f190928:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f19092c:	0fc641dd */ 	jal	func0f190774
/*  f190930:	3484bcdf */ 	ori	$a0,$a0,0xbcdf
/*  f190934:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f190938:
/*  f190938:	0fc47bba */ 	jal	dprint
/*  f19093c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190940:	00008025 */ 	or	$s0,$zero,$zero
/*  f190944:	8fa30090 */ 	lw	$v1,0x90($sp)
.L0f190948:
/*  f190948:	9466005e */ 	lhu	$a2,0x5e($v1)
/*  f19094c:	10c00006 */ 	beqz	$a2,.L0f190968
/*  f190950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190954:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f190958:	0fc47bba */ 	jal	dprint
/*  f19095c:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f190960:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f190964:	8fa60088 */ 	lw	$a2,0x88($sp)
.L0f190968:
/*  f190968:	10c00006 */ 	beqz	$a2,.L0f190984
/*  f19096c:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f190970:	8dc402d4 */ 	lw	$a0,0x2d4($t6)
/*  f190974:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f190978:	0fc667bd */ 	jal	func0f199ef4
/*  f19097c:	26050001 */ 	addiu	$a1,$s0,0x1
/*  f190980:	8fa30050 */ 	lw	$v1,0x50($sp)
.L0f190984:
/*  f190984:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f190988:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19098c:	1601ffee */ 	bne	$s0,$at,.L0f190948
/*  f190990:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f190994:	3c01bf80 */ 	lui	$at,0xbf80
/*  f190998:	44810000 */ 	mtc1	$at,$f0
/*  f19099c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1909a0:	24180400 */ 	addiu	$t8,$zero,0x400
/*  f1909a4:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1909a8:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f1909ac:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1909b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1909b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1909b8:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f1909bc:	240600ea */ 	addiu	$a2,$zero,0xea
/*  f1909c0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1909c4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1909c8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1909cc:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1909d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1909d4:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f1909d8:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f1909dc:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f1909e0:	0fc24e7e */ 	jal	func0f0939f8
/*  f1909e4:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f1909e8:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f1909ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f1909f0:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f1909f4:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f1909f8:	0fc1ab4b */ 	jal	setupParseObject
/*  f1909fc:	01403025 */ 	or	$a2,$t2,$zero
/*  f190a00:	10000073 */ 	beqz	$zero,.L0f190bd0
/*  f190a04:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f190a08:	8fab00a0 */ 	lw	$t3,0xa0($sp)
/*  f190a0c:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190a10:	8d700004 */ 	lw	$s0,0x4($t3)
/*  f190a14:	0fc65f90 */ 	jal	func0f197e40
/*  f190a18:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f190a1c:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f190a20:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f190a24:	24010057 */ 	addiu	$at,$zero,0x57
/*  f190a28:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190a2c:	54a10006 */ 	bnel	$a1,$at,.L0f190a48
/*  f190a30:	24010036 */ 	addiu	$at,$zero,0x36
/*  f190a34:	0fc61a26 */ 	jal	func0f186898
/*  f190a38:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f190a3c:	10000065 */ 	beqz	$zero,.L0f190bd4
/*  f190a40:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f190a44:	24010036 */ 	addiu	$at,$zero,0x36
.L0f190a48:
/*  f190a48:	14a10005 */ 	bne	$a1,$at,.L0f190a60
/*  f190a4c:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190a50:	0fc61d04 */ 	jal	func0f187410
/*  f190a54:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f190a58:	1000005e */ 	beqz	$zero,.L0f190bd4
/*  f190a5c:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f190a60:
/*  f190a60:	0fc21f03 */ 	jal	func0f087c0c
/*  f190a64:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f190a68:	0fc22095 */ 	jal	func0f088254
/*  f190a6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f190a70:	10400006 */ 	beqz	$v0,.L0f190a8c
/*  f190a74:	00403825 */ 	or	$a3,$v0,$zero
/*  f190a78:	8fac00a4 */ 	lw	$t4,0xa4($sp)
/*  f190a7c:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f190a80:	9206005f */ 	lbu	$a2,0x5f($s0)
/*  f190a84:	0fc6678f */ 	jal	func0f199e3c
/*  f190a88:	8d8402d4 */ 	lw	$a0,0x2d4($t4)
.L0f190a8c:
/*  f190a8c:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f190a90:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190a94:	11a0001c */ 	beqz	$t5,.L0f190b08
/*  f190a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190a9c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f190aa0:	9204005c */ 	lbu	$a0,0x5c($s0)
/*  f190aa4:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f190aa8:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f190aac:	0fc65fcc */ 	jal	func0f197f30
/*  f190ab0:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190ab4:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f190ab8:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f190abc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190ac0:	8fa30060 */ 	lw	$v1,0x60($sp)
/*  f190ac4:	15e1000e */ 	bne	$t7,$at,.L0f190b00
/*  f190ac8:	85c40006 */ 	lh	$a0,0x6($t6)
/*  f190acc:	1060000c */ 	beqz	$v1,.L0f190b00
/*  f190ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190ad4:	8c78004c */ 	lw	$t8,0x4c($v1)
/*  f190ad8:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f190adc:	13200008 */ 	beqz	$t9,.L0f190b00
/*  f190ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190ae4:	10440006 */ 	beq	$v0,$a0,.L0f190b00
/*  f190ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190aec:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190af0:	0fc65fc1 */ 	jal	func0f197f04
/*  f190af4:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f190af8:	10000006 */ 	beqz	$zero,.L0f190b14
/*  f190afc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f190b00:
/*  f190b00:	10000004 */ 	beqz	$zero,.L0f190b14
/*  f190b04:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f190b08:
/*  f190b08:	0fc65fdb */ 	jal	func0f197f6c
/*  f190b0c:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f190b10:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f190b14:
/*  f190b14:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f190b18:	00002825 */ 	or	$a1,$zero,$zero
/*  f190b1c:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f190b20:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f190b24:	0fc1ab4b */ 	jal	setupParseObject
/*  f190b28:	01403025 */ 	or	$a2,$t2,$zero
/*  f190b2c:	10000028 */ 	beqz	$zero,.L0f190bd0
/*  f190b30:	02001025 */ 	or	$v0,$s0,$zero
/*  f190b34:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f190b38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f190b3c:	44810000 */ 	mtc1	$at,$f0
/*  f190b40:	8cb00004 */ 	lw	$s0,0x4($a1)
/*  f190b44:	240bffff */ 	addiu	$t3,$zero,-1
/*  f190b48:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f190b4c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f190b50:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f190b54:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f190b58:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f190b5c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f190b60:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f190b64:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f190b68:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f190b6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f190b70:	240601cd */ 	addiu	$a2,$zero,0x1cd
/*  f190b74:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f190b78:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f190b7c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f190b80:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f190b84:	0fc24e7e */ 	jal	func0f0939f8
/*  f190b88:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f190b8c:	3c014100 */ 	lui	$at,0x4100
/*  f190b90:	44813000 */ 	mtc1	$at,$f6
/*  f190b94:	c6040060 */ 	lwc1	$f4,0x60($s0)
/*  f190b98:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f190b9c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f190ba0:	44054000 */ 	mfc1	$a1,$f8
/*  f190ba4:	0fc0cfea */ 	jal	chrSetShield
/*  f190ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190bac:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f190bb0:	00002825 */ 	or	$a1,$zero,$zero
/*  f190bb4:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f190bb8:	30ce0004 */ 	andi	$t6,$a2,0x4
/*  f190bbc:	0fc1ab4b */ 	jal	setupParseObject
/*  f190bc0:	01c03025 */ 	or	$a2,$t6,$zero
/*  f190bc4:	10000002 */ 	beqz	$zero,.L0f190bd0
/*  f190bc8:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f190bcc:
/*  f190bcc:	00001025 */ 	or	$v0,$zero,$zero
.L0f190bd0:
/*  f190bd0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f190bd4:
/*  f190bd4:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f190bd8:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f190bdc:	03e00008 */ 	jr	$ra
/*  f190be0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f190be4
/*  f190be4:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f190be8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f190bec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f190bf0:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f190bf4:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f190bf8:	10a0000d */ 	beqz	$a1,.L0f190c30
/*  f190bfc:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f190c00:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f190c04:	3c19800a */ 	lui	$t9,0x800a
/*  f190c08:	13000009 */ 	beqz	$t8,.L0f190c30
/*  f190c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190c10:	8f39a2dc */ 	lw	$t9,-0x5d24($t9)
/*  f190c14:	00a02025 */ 	or	$a0,$a1,$zero
/*  f190c18:	13200005 */ 	beqz	$t9,.L0f190c30
/*  f190c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190c20:	0fc0e6a5 */ 	jal	chrIsDead
/*  f190c24:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f190c28:	10400003 */ 	beqz	$v0,.L0f190c38
/*  f190c2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f190c30:
/*  f190c30:	10000153 */ 	beqz	$zero,.L0f191180
/*  f190c34:	00001025 */ 	or	$v0,$zero,$zero
.L0f190c38:
/*  f190c38:	0fc47bba */ 	jal	dprint
/*  f190c3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190c40:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f190c44:	85090002 */ 	lh	$t1,0x2($t0)
/*  f190c48:	11200003 */ 	beqz	$t1,.L0f190c58
/*  f190c4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190c50:	1000014b */ 	beqz	$zero,.L0f191180
/*  f190c54:	00001025 */ 	or	$v0,$zero,$zero
.L0f190c58:
/*  f190c58:	0fc21465 */ 	jal	func0f085194
/*  f190c5c:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190c60:	5040000d */ 	beqzl	$v0,.L0f190c98
/*  f190c64:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c68:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c6c:	24010011 */ 	addiu	$at,$zero,0x11
/*  f190c70:	904a0003 */ 	lbu	$t2,0x3($v0)
/*  f190c74:	51410008 */ 	beql	$t2,$at,.L0f190c98
/*  f190c78:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c7c:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f190c80:	000b62c0 */ 	sll	$t4,$t3,0xb
/*  f190c84:	0581000a */ 	bgez	$t4,.L0f190cb0
/*  f190c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190c8c:	1000013c */ 	beqz	$zero,.L0f191180
/*  f190c90:	00001025 */ 	or	$v0,$zero,$zero
/*  f190c94:	8fa20084 */ 	lw	$v0,0x84($sp)
.L0f190c98:
/*  f190c98:	8c4d0008 */ 	lw	$t5,0x8($v0)
/*  f190c9c:	000d7340 */ 	sll	$t6,$t5,0xd
/*  f190ca0:	05c00003 */ 	bltz	$t6,.L0f190cb0
/*  f190ca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190ca8:	10000135 */ 	beqz	$zero,.L0f191180
/*  f190cac:	00001025 */ 	or	$v0,$zero,$zero
.L0f190cb0:
/*  f190cb0:	0fc47bba */ 	jal	dprint
/*  f190cb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190cb8:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190cbc:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f190cc0:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f190cc4:	17000005 */ 	bnez	$t8,.L0f190cdc
/*  f190cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190ccc:	8c590008 */ 	lw	$t9,0x8($v0)
/*  f190cd0:	00194300 */ 	sll	$t0,$t9,0xc
/*  f190cd4:	05010003 */ 	bgez	$t0,.L0f190ce4
/*  f190cd8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f190cdc:
/*  f190cdc:	10000128 */ 	beqz	$zero,.L0f191180
/*  f190ce0:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ce4:
/*  f190ce4:	0fc47bba */ 	jal	dprint
/*  f190ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190cec:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f190cf0:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f190cf4:	312a0080 */ 	andi	$t2,$t1,0x80
/*  f190cf8:	1140000c */ 	beqz	$t2,.L0f190d2c
/*  f190cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d00:	8c620048 */ 	lw	$v0,0x48($v1)
/*  f190d04:	10400009 */ 	beqz	$v0,.L0f190d2c
/*  f190d08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d0c:	8c4b00b4 */ 	lw	$t3,0xb4($v0)
/*  f190d10:	19600006 */ 	blez	$t3,.L0f190d2c
/*  f190d14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d18:	8c4c0090 */ 	lw	$t4,0x90($v0)
/*  f190d1c:	15800003 */ 	bnez	$t4,.L0f190d2c
/*  f190d20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d24:	10000116 */ 	beqz	$zero,.L0f191180
/*  f190d28:	00001025 */ 	or	$v0,$zero,$zero
.L0f190d2c:
/*  f190d2c:	0fc47bba */ 	jal	dprint
/*  f190d30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d34:	0fc19990 */ 	jal	func0f066640
/*  f190d38:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190d3c:	14400003 */ 	bnez	$v0,.L0f190d4c
/*  f190d40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d44:	1000010e */ 	beqz	$zero,.L0f191180
/*  f190d48:	00001025 */ 	or	$v0,$zero,$zero
.L0f190d4c:
/*  f190d4c:	0fc47bba */ 	jal	dprint
/*  f190d50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190d54:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f190d58:	24010008 */ 	addiu	$at,$zero,0x8
/*  f190d5c:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f190d60:	91a20003 */ 	lbu	$v0,0x3($t5)
/*  f190d64:	5441003c */ 	bnel	$v0,$at,.L0f190e58
/*  f190d68:	24010007 */ 	addiu	$at,$zero,0x7
/*  f190d6c:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f190d70:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190d74:	9045005c */ 	lbu	$a1,0x5c($v0)
/*  f190d78:	0fc65f90 */ 	jal	func0f197e40
/*  f190d7c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f190d80:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f190d84:	91e4005c */ 	lbu	$a0,0x5c($t7)
/*  f190d88:	0fc2c3f4 */ 	jal	weaponFindById
/*  f190d8c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f190d90:	0002282b */ 	sltu	$a1,$zero,$v0
/*  f190d94:	10a00004 */ 	beqz	$a1,.L0f190da8
/*  f190d98:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f190d9c:	8c45004c */ 	lw	$a1,0x4c($v0)
/*  f190da0:	30b81000 */ 	andi	$t8,$a1,0x1000
/*  f190da4:	2f050001 */ 	sltiu	$a1,$t8,0x1
.L0f190da8:
/*  f190da8:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190dac:	24010057 */ 	addiu	$at,$zero,0x57
/*  f190db0:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f190db4:	1201009b */ 	beq	$s0,$at,.L0f191024
/*  f190db8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f190dbc:	10c10006 */ 	beq	$a2,$at,.L0f190dd8
/*  f190dc0:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f190dc4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190dc8:	54c10015 */ 	bnel	$a2,$at,.L0f190e20
/*  f190dcc:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190dd0:	50a00013 */ 	beqzl	$a1,.L0f190e20
/*  f190dd4:	8fa20080 */ 	lw	$v0,0x80($sp)
.L0f190dd8:
/*  f190dd8:	8d0402d4 */ 	lw	$a0,0x2d4($t0)
/*  f190ddc:	02002825 */ 	or	$a1,$s0,$zero
/*  f190de0:	9046005f */ 	lbu	$a2,0x5f($v0)
/*  f190de4:	0fc666f9 */ 	jal	func0f199be4
/*  f190de8:	00003825 */ 	or	$a3,$zero,$zero
/*  f190dec:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f190df0:	00408025 */ 	or	$s0,$v0,$zero
/*  f190df4:	9124005c */ 	lbu	$a0,0x5c($t1)
/*  f190df8:	0fc6666c */ 	jal	func0f1999b0
/*  f190dfc:	9125005f */ 	lbu	$a1,0x5f($t1)
/*  f190e00:	0fc2a63d */ 	jal	func0f0a98f4
/*  f190e04:	00402025 */ 	or	$a0,$v0,$zero
/*  f190e08:	0202082a */ 	slt	$at,$s0,$v0
/*  f190e0c:	54200004 */ 	bnezl	$at,.L0f190e20
/*  f190e10:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190e14:	100000da */ 	beqz	$zero,.L0f191180
/*  f190e18:	00001025 */ 	or	$v0,$zero,$zero
/*  f190e1c:	8fa20080 */ 	lw	$v0,0x80($sp)
.L0f190e20:
/*  f190e20:	24010053 */ 	addiu	$at,$zero,0x53
/*  f190e24:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f190e28:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f190e2c:	12010003 */ 	beq	$s0,$at,.L0f190e3c
/*  f190e30:	24010054 */ 	addiu	$at,$zero,0x54
/*  f190e34:	5601007c */ 	bnel	$s0,$at,.L0f191028
/*  f190e38:	8fa9008c */ 	lw	$t1,0x8c($sp)
.L0f190e3c:
/*  f190e3c:	8d4b0040 */ 	lw	$t3,0x40($t2)
/*  f190e40:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f190e44:	51800078 */ 	beqzl	$t4,.L0f191028
/*  f190e48:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190e4c:	100000cc */ 	beqz	$zero,.L0f191180
/*  f190e50:	00001025 */ 	or	$v0,$zero,$zero
/*  f190e54:	24010007 */ 	addiu	$at,$zero,0x7
.L0f190e58:
/*  f190e58:	14410010 */ 	bne	$v0,$at,.L0f190e9c
/*  f190e5c:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f190e60:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f190e64:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f190e68:	00003025 */ 	or	$a2,$zero,$zero
/*  f190e6c:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f190e70:	0fc6672e */ 	jal	func0f199cb8
/*  f190e74:	8dc402d4 */ 	lw	$a0,0x2d4($t6)
/*  f190e78:	8e04005c */ 	lw	$a0,0x5c($s0)
/*  f190e7c:	0fc2a63d */ 	jal	func0f0a98f4
/*  f190e80:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f190e84:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f190e88:	00a2082a */ 	slt	$at,$a1,$v0
/*  f190e8c:	54200066 */ 	bnezl	$at,.L0f191028
/*  f190e90:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190e94:	100000ba */ 	beqz	$zero,.L0f191180
/*  f190e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f190e9c:
/*  f190e9c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f190ea0:	1441003d */ 	bne	$v0,$at,.L0f190f98
/*  f190ea4:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f190ea8:	8df00004 */ 	lw	$s0,0x4($t7)
/*  f190eac:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f190eb0:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f190eb4:	0fc1a1ee */ 	jal	func0f0687b8
/*  f190eb8:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190ebc:	10400005 */ 	beqz	$v0,.L0f190ed4
/*  f190ec0:	02001825 */ 	or	$v1,$s0,$zero
/*  f190ec4:	0fc47bba */ 	jal	dprint
/*  f190ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190ecc:	100000ac */ 	beqz	$zero,.L0f191180
/*  f190ed0:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ed4:
/*  f190ed4:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ed8:
/*  f190ed8:	24500001 */ 	addiu	$s0,$v0,0x1
/*  f190edc:	02002025 */ 	or	$a0,$s0,$zero
/*  f190ee0:	0fc668c7 */ 	jal	func0f19a31c
/*  f190ee4:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f190ee8:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f190eec:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f190ef0:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f190ef4:	9479005e */ 	lhu	$t9,0x5e($v1)
/*  f190ef8:	02002825 */ 	or	$a1,$s0,$zero
/*  f190efc:	00003025 */ 	or	$a2,$zero,$zero
/*  f190f00:	5b20001d */ 	blezl	$t9,.L0f190f78
/*  f190f04:	24010013 */ 	addiu	$at,$zero,0x13
/*  f190f08:	8d0402d4 */ 	lw	$a0,0x2d4($t0)
/*  f190f0c:	0fc6672e */ 	jal	func0f199cb8
/*  f190f10:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f190f14:	02002025 */ 	or	$a0,$s0,$zero
/*  f190f18:	0fc2a63d */ 	jal	func0f0a98f4
/*  f190f1c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f190f20:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f190f24:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f190f28:	00a2082a */ 	slt	$at,$a1,$v0
/*  f190f2c:	50200012 */ 	beqzl	$at,.L0f190f78
/*  f190f30:	24010013 */ 	addiu	$at,$zero,0x13
/*  f190f34:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f190f38:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f190f3c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190f40:	51200011 */ 	beqzl	$t1,.L0f190f88
/*  f190f44:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f48:	0fc65f90 */ 	jal	func0f197e40
/*  f190f4c:	01202825 */ 	or	$a1,$t1,$zero
/*  f190f50:	5440000d */ 	bnezl	$v0,.L0f190f88
/*  f190f54:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f58:	0fc47bba */ 	jal	dprint
/*  f190f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190f60:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190f64:	0fc65fdb */ 	jal	func0f197f6c
/*  f190f68:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f190f6c:	10000006 */ 	beqz	$zero,.L0f190f88
/*  f190f70:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f74:	24010013 */ 	addiu	$at,$zero,0x13
.L0f190f78:
/*  f190f78:	02001025 */ 	or	$v0,$s0,$zero
/*  f190f7c:	1601ffd6 */ 	bne	$s0,$at,.L0f190ed8
/*  f190f80:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f190f84:	8faa0064 */ 	lw	$t2,0x64($sp)
.L0f190f88:
/*  f190f88:	51400027 */ 	beqzl	$t2,.L0f191028
/*  f190f8c:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190f90:	1000007b */ 	beqz	$zero,.L0f191180
/*  f190f94:	00001025 */ 	or	$v0,$zero,$zero
.L0f190f98:
/*  f190f98:	24010015 */ 	addiu	$at,$zero,0x15
/*  f190f9c:	14410021 */ 	bne	$v0,$at,.L0f191024
/*  f190fa0:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f190fa4:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f190fa8:	00008025 */ 	or	$s0,$zero,$zero
/*  f190fac:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190fb0:	0fc0cfe8 */ 	jal	chrGetShield
/*  f190fb4:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f190fb8:	3c013e00 */ 	lui	$at,0x3e00
/*  f190fbc:	44812000 */ 	mtc1	$at,$f4
/*  f190fc0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f190fc4:	3c0e800b */ 	lui	$t6,0x800b
/*  f190fc8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f190fcc:	c5a80060 */ 	lwc1	$f8,0x60($t5)
/*  f190fd0:	4606403e */ 	c.le.s	$f8,$f6
/*  f190fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190fd8:	45000003 */ 	bc1f	.L0f190fe8
/*  f190fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190fe0:	1000000c */ 	beqz	$zero,.L0f191014
/*  f190fe4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f190fe8:
/*  f190fe8:	91cecb98 */ 	lbu	$t6,-0x3468($t6)
/*  f190fec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190ff0:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f190ff4:	15c10007 */ 	bne	$t6,$at,.L0f191014
/*  f190ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f190ffc:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f191000:	8f19009c */ 	lw	$t9,0x9c($t8)
/*  f191004:	001947c2 */ 	srl	$t0,$t9,0x1f
/*  f191008:	11000002 */ 	beqz	$t0,.L0f191014
/*  f19100c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191010:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f191014:
/*  f191014:	52000004 */ 	beqzl	$s0,.L0f191028
/*  f191018:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f19101c:	10000058 */ 	beqz	$zero,.L0f191180
/*  f191020:	00001025 */ 	or	$v0,$zero,$zero
.L0f191024:
/*  f191024:	8fa9008c */ 	lw	$t1,0x8c($sp)
.L0f191028:
/*  f191028:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f19102c:	8d30001c */ 	lw	$s0,0x1c($t1)
/*  f191030:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f191034:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f191038:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f19103c:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f191040:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f191044:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f191048:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f19104c:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f191050:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f191054:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f191058:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f19105c:	0fc47bba */ 	jal	dprint
/*  f191060:	e7ae0044 */ 	swc1	$f14,0x44($sp)
/*  f191064:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f191068:	8faa008c */ 	lw	$t2,0x8c($sp)
/*  f19106c:	c7ae0044 */ 	lwc1	$f14,0x44($sp)
/*  f191070:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f191074:	8d4b02d4 */ 	lw	$t3,0x2d4($t2)
/*  f191078:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f19107c:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f191080:	916c009c */ 	lbu	$t4,0x9c($t3)
/*  f191084:	3c017f1c */ 	lui	$at,%hi(var7f1b8ea4)
/*  f191088:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f19108c:	11a00004 */ 	beqz	$t5,.L0f1910a0
/*  f191090:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f191094:	3c017f1c */ 	lui	$at,%hi(var7f1b8ea8)
/*  f191098:	10000002 */ 	beqz	$zero,.L0f1910a4
/*  f19109c:	c4208ea4 */ 	lwc1	$f0,%lo(var7f1b8ea4)($at)
.L0f1910a0:
/*  f1910a0:	c4208ea8 */ 	lwc1	$f0,%lo(var7f1b8ea8)($at)
.L0f1910a4:
/*  f1910a4:	4600903e */ 	c.le.s	$f18,$f0
/*  f1910a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1910ac:	3c01c348 */ 	lui	$at,0xc348
/*  f1910b0:	45000002 */ 	bc1f	.L0f1910bc
/*  f1910b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1910b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1910bc:
/*  f1910bc:	10400012 */ 	beqz	$v0,.L0f191108
/*  f1910c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1910c4:	44812000 */ 	mtc1	$at,$f4
/*  f1910c8:	3c014348 */ 	lui	$at,0x4348
/*  f1910cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1910d0:	460c203e */ 	c.le.s	$f4,$f12
/*  f1910d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1910d8:	45000002 */ 	bc1f	.L0f1910e4
/*  f1910dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1910e0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1910e4:
/*  f1910e4:	10400008 */ 	beqz	$v0,.L0f191108
/*  f1910e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1910ec:	44813000 */ 	mtc1	$at,$f6
/*  f1910f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1910f4:	4606603e */ 	c.le.s	$f12,$f6
/*  f1910f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1910fc:	45000002 */ 	bc1f	.L0f191108
/*  f191100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191104:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f191108:
/*  f191108:	10a00014 */ 	beqz	$a1,.L0f19115c
/*  f19110c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f191110:	0fc47bba */ 	jal	dprint
/*  f191114:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f191118:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f19111c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f191120:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f191124:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f191128:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f19112c:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f191130:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f191134:	17000009 */ 	bnez	$t8,.L0f19115c
/*  f191138:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f19113c:	24190022 */ 	addiu	$t9,$zero,0x22
/*  f191140:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f191144:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f191148:	0c00b734 */ 	jal	func0002dcd0
/*  f19114c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f191150:	14400002 */ 	bnez	$v0,.L0f19115c
/*  f191154:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f191158:	00001825 */ 	or	$v1,$zero,$zero
.L0f19115c:
/*  f19115c:	10600008 */ 	beqz	$v1,.L0f191180
/*  f191160:	00001025 */ 	or	$v0,$zero,$zero
/*  f191164:	0fc47bba */ 	jal	dprint
/*  f191168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19116c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f191170:	0fc641e1 */ 	jal	func0f190784
/*  f191174:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f191178:	10000002 */ 	beqz	$zero,.L0f191184
/*  f19117c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191180:
/*  f191180:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191184:
/*  f191184:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f191188:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f19118c:	03e00008 */ 	jr	$ra
/*  f191190:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f191194
/*  f191194:	54800004 */ 	bnezl	$a0,.L0f1911a8
/*  f191198:	90820003 */ 	lbu	$v0,0x3($a0)
/*  f19119c:	03e00008 */ 	jr	$ra
/*  f1911a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1911a4:	90820003 */ 	lbu	$v0,0x3($a0)
.L0f1911a8:
/*  f1911a8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1911ac:	10410005 */ 	beq	$v0,$at,.L0f1911c4
/*  f1911b0:	24010014 */ 	addiu	$at,$zero,0x14
/*  f1911b4:	10410003 */ 	beq	$v0,$at,.L0f1911c4
/*  f1911b8:	24010015 */ 	addiu	$at,$zero,0x15
/*  f1911bc:	54410004 */ 	bnel	$v0,$at,.L0f1911d0
/*  f1911c0:	24010008 */ 	addiu	$at,$zero,0x8
.L0f1911c4:
/*  f1911c4:	03e00008 */ 	jr	$ra
/*  f1911c8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1911cc:	24010008 */ 	addiu	$at,$zero,0x8
.L0f1911d0:
/*  f1911d0:	5441001c */ 	bnel	$v0,$at,.L0f191244
/*  f1911d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1911d8:	9082005c */ 	lbu	$v0,0x5c($a0)
/*  f1911dc:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f1911e0:	10410013 */ 	beq	$v0,$at,.L0f191230
/*  f1911e4:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f1911e8:	10410011 */ 	beq	$v0,$at,.L0f191230
/*  f1911ec:	24010055 */ 	addiu	$at,$zero,0x55
/*  f1911f0:	1041000f */ 	beq	$v0,$at,.L0f191230
/*  f1911f4:	24010021 */ 	addiu	$at,$zero,0x21
/*  f1911f8:	1041000d */ 	beq	$v0,$at,.L0f191230
/*  f1911fc:	24010022 */ 	addiu	$at,$zero,0x22
/*  f191200:	1041000b */ 	beq	$v0,$at,.L0f191230
/*  f191204:	24010020 */ 	addiu	$at,$zero,0x20
/*  f191208:	10410009 */ 	beq	$v0,$at,.L0f191230
/*  f19120c:	24010058 */ 	addiu	$at,$zero,0x58
/*  f191210:	10410007 */ 	beq	$v0,$at,.L0f191230
/*  f191214:	2401000f */ 	addiu	$at,$zero,0xf
/*  f191218:	14410007 */ 	bne	$v0,$at,.L0f191238
/*  f19121c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191220:	908e005f */ 	lbu	$t6,0x5f($a0)
/*  f191224:	24010001 */ 	addiu	$at,$zero,0x1
/*  f191228:	15c10003 */ 	bne	$t6,$at,.L0f191238
/*  f19122c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f191230:
/*  f191230:	03e00008 */ 	jr	$ra
/*  f191234:	00001025 */ 	or	$v0,$zero,$zero
.L0f191238:
/*  f191238:	03e00008 */ 	jr	$ra
/*  f19123c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f191240:	00001025 */ 	or	$v0,$zero,$zero
.L0f191244:
/*  f191244:	03e00008 */ 	jr	$ra
/*  f191248:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19124c
/*  f19124c:	27bdfd60 */ 	addiu	$sp,$sp,-672
/*  f191250:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f191254:	0080a025 */ 	or	$s4,$a0,$zero
/*  f191258:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f19125c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f191260:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f191264:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f191268:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19126c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f191270:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f191274:	8c84001c */ 	lw	$a0,0x1c($a0)
/*  f191278:	27b30064 */ 	addiu	$s3,$sp,0x64
/*  f19127c:	02602825 */ 	or	$a1,$s3,$zero
/*  f191280:	0fc195e9 */ 	jal	func0f0657a4
/*  f191284:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f191288:	8e82001c */ 	lw	$v0,0x1c($s4)
/*  f19128c:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f191290:	00008025 */ 	or	$s0,$zero,$zero
/*  f191294:	844e0028 */ 	lh	$t6,0x28($v0)
/*  f191298:	27b1004c */ 	addiu	$s1,$sp,0x4c
/*  f19129c:	524e0010 */ 	beql	$s2,$t6,.L0f1912e0
/*  f1912a0:	27b00090 */ 	addiu	$s0,$sp,0x90
/*  f1912a4:	84440028 */ 	lh	$a0,0x28($v0)
/*  f1912a8:	02202825 */ 	or	$a1,$s1,$zero
.L0f1912ac:
/*  f1912ac:	0fc5916a */ 	jal	func0f1645a8
/*  f1912b0:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f1912b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1912b8:	02602825 */ 	or	$a1,$s3,$zero
/*  f1912bc:	0fc195f6 */ 	jal	func0f0657d8
/*  f1912c0:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f1912c4:	8e8f001c */ 	lw	$t7,0x1c($s4)
/*  f1912c8:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f1912cc:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f1912d0:	87040028 */ 	lh	$a0,0x28($t8)
/*  f1912d4:	5644fff5 */ 	bnel	$s2,$a0,.L0f1912ac
/*  f1912d8:	02202825 */ 	or	$a1,$s1,$zero
/*  f1912dc:	27b00090 */ 	addiu	$s0,$sp,0x90
.L0f1912e0:
/*  f1912e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1912e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1912e8:	0fc197e0 */ 	jal	func0f065f80
/*  f1912ec:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f1912f0:	87b90090 */ 	lh	$t9,0x90($sp)
/*  f1912f4:	02008825 */ 	or	$s1,$s0,$zero
/*  f1912f8:	27a80090 */ 	addiu	$t0,$sp,0x90
/*  f1912fc:	07200034 */ 	bltz	$t9,.L0f1913d0
/*  f191300:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f191304:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f191308:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f19130c:	85020000 */ 	lh	$v0,0x0($t0)
/*  f191310:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f191314:	24120048 */ 	addiu	$s2,$zero,0x48
.L0f191318:
/*  f191318:	00520019 */ 	multu	$v0,$s2
/*  f19131c:	8e6a0338 */ 	lw	$t2,0x338($s3)
/*  f191320:	00004812 */ 	mflo	$t1
/*  f191324:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f191328:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f19132c:	52a30004 */ 	beql	$s5,$v1,.L0f191340
/*  f191330:	860b0002 */ 	lh	$t3,0x2($s0)
/*  f191334:	56c30023 */ 	bnel	$s6,$v1,.L0f1913c4
/*  f191338:	86220002 */ 	lh	$v0,0x2($s1)
/*  f19133c:	860b0002 */ 	lh	$t3,0x2($s0)
.L0f191340:
/*  f191340:	55600020 */ 	bnezl	$t3,.L0f1913c4
/*  f191344:	86220002 */ 	lh	$v0,0x2($s1)
/*  f191348:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f19134c:	5080001d */ 	beqzl	$a0,.L0f1913c4
/*  f191350:	86220002 */ 	lh	$v0,0x2($s1)
/*  f191354:	8c8c0040 */ 	lw	$t4,0x40($a0)
/*  f191358:	318d0080 */ 	andi	$t5,$t4,0x80
/*  f19135c:	11a0000a */ 	beqz	$t5,.L0f191388
/*  f191360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191364:	8c820048 */ 	lw	$v0,0x48($a0)
/*  f191368:	10400007 */ 	beqz	$v0,.L0f191388
/*  f19136c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191370:	8c4e00b4 */ 	lw	$t6,0xb4($v0)
/*  f191374:	19c00004 */ 	blez	$t6,.L0f191388
/*  f191378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19137c:	8c4f0090 */ 	lw	$t7,0x90($v0)
/*  f191380:	51e00010 */ 	beqzl	$t7,.L0f1913c4
/*  f191384:	86220002 */ 	lh	$v0,0x2($s1)
.L0f191388:
/*  f191388:	0fc64465 */ 	jal	func0f191194
/*  f19138c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191390:	1040000b */ 	beqz	$v0,.L0f1913c0
/*  f191394:	02002025 */ 	or	$a0,$s0,$zero
/*  f191398:	0fc642f9 */ 	jal	func0f190be4
/*  f19139c:	02802825 */ 	or	$a1,$s4,$zero
/*  f1913a0:	10400005 */ 	beqz	$v0,.L0f1913b8
/*  f1913a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1913a8:	0fc18ad9 */ 	jal	func0f062b64
/*  f1913ac:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1913b0:	10000004 */ 	beqz	$zero,.L0f1913c4
/*  f1913b4:	86220002 */ 	lh	$v0,0x2($s1)
.L0f1913b8:
/*  f1913b8:	0fc47bba */ 	jal	dprint
/*  f1913bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1913c0:
/*  f1913c0:	86220002 */ 	lh	$v0,0x2($s1)
.L0f1913c4:
/*  f1913c4:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f1913c8:	0441ffd3 */ 	bgez	$v0,.L0f191318
/*  f1913cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1913d0:
/*  f1913d0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1913d4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1913d8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1913dc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1913e0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1913e4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1913e8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1913ec:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1913f0:	03e00008 */ 	jr	$ra
/*  f1913f4:	27bd02a0 */ 	addiu	$sp,$sp,0x2a0
);

GLOBAL_ASM(
glabel func0f1913f8
/*  f1913f8:	3c0142b4 */ 	lui	$at,0x42b4
/*  f1913fc:	44812000 */ 	mtc1	$at,$f4
/*  f191400:	c4800028 */ 	lwc1	$f0,0x28($a0)
/*  f191404:	3c014307 */ 	lui	$at,0x4307
/*  f191408:	4604003e */ 	c.le.s	$f0,$f4
/*  f19140c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191410:	45020004 */ 	bc1fl	.L0f191424
/*  f191414:	44813000 */ 	mtc1	$at,$f6
/*  f191418:	03e00008 */ 	jr	$ra
/*  f19141c:	00001025 */ 	or	$v0,$zero,$zero
/*  f191420:	44813000 */ 	mtc1	$at,$f6
.L0f191424:
/*  f191424:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f191428:	4606003e */ 	c.le.s	$f0,$f6
/*  f19142c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191430:	45000003 */ 	bc1f	.L0f191440
/*  f191434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191438:	03e00008 */ 	jr	$ra
/*  f19143c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f191440:
/*  f191440:	03e00008 */ 	jr	$ra
/*  f191444:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f191448
/*  f191448:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f19144c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f191450:	00808825 */ 	or	$s1,$a0,$zero
/*  f191454:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f191458:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f19145c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f191460:	10800004 */ 	beqz	$a0,.L0f191474
/*  f191464:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f191468:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f19146c:	14400003 */ 	bnez	$v0,.L0f19147c
/*  f191470:	00408025 */ 	or	$s0,$v0,$zero
.L0f191474:
/*  f191474:	10000048 */ 	beqz	$zero,.L0f191598
/*  f191478:	00001025 */ 	or	$v0,$zero,$zero
.L0f19147c:
/*  f19147c:	0fc0f917 */ 	jal	func0f03e45c
/*  f191480:	02202025 */ 	or	$a0,$s1,$zero
/*  f191484:	46000506 */ 	mov.s	$f20,$f0
/*  f191488:	0fc0f95e */ 	jal	func0f03e578
/*  f19148c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191490:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f191494:	4600a081 */ 	sub.s	$f2,$f20,$f0
/*  f191498:	45000004 */ 	bc1f	.L0f1914ac
/*  f19149c:	46001586 */ 	mov.s	$f22,$f2
/*  f1914a0:	3c017f1c */ 	lui	$at,%hi(var7f1b8eac)
/*  f1914a4:	c4248eac */ 	lwc1	$f4,%lo(var7f1b8eac)($at)
/*  f1914a8:	46041580 */ 	add.s	$f22,$f2,$f4
.L0f1914ac:
/*  f1914ac:	0c0068f4 */ 	jal	func0001a3d0
/*  f1914b0:	4600b306 */ 	mov.s	$f12,$f22
/*  f1914b4:	46000506 */ 	mov.s	$f20,$f0
/*  f1914b8:	0c0068f7 */ 	jal	func0001a3dc
/*  f1914bc:	4600b306 */ 	mov.s	$f12,$f22
/*  f1914c0:	c606006c */ 	lwc1	$f6,0x6c($s0)
/*  f1914c4:	c60a0070 */ 	lwc1	$f10,0x70($s0)
/*  f1914c8:	4600b306 */ 	mov.s	$f12,$f22
/*  f1914cc:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f1914d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1914d4:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f1914d8:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f1914dc:	0c0068f7 */ 	jal	func0001a3dc
/*  f1914e0:	e7b20044 */ 	swc1	$f18,0x44($sp)
/*  f1914e4:	46000506 */ 	mov.s	$f20,$f0
/*  f1914e8:	0c0068f4 */ 	jal	func0001a3d0
/*  f1914ec:	4600b306 */ 	mov.s	$f12,$f22
/*  f1914f0:	c6040070 */ 	lwc1	$f4,0x70($s0)
/*  f1914f4:	c60a006c */ 	lwc1	$f10,0x6c($s0)
/*  f1914f8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1914fc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f191500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191504:	46145202 */ 	mul.s	$f8,$f10,$f20
/*  f191508:	0fc644fe */ 	jal	func0f1913f8
/*  f19150c:	46083580 */ 	add.s	$f22,$f6,$f8
/*  f191510:	c61000ac */ 	lwc1	$f16,0xac($s0)
/*  f191514:	4406b000 */ 	mfc1	$a2,$f22
/*  f191518:	260e00a8 */ 	addiu	$t6,$s0,0xa8
/*  f19151c:	260f0068 */ 	addiu	$t7,$s0,0x68
/*  f191520:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f191524:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f191528:	02202025 */ 	or	$a0,$s1,$zero
/*  f19152c:	00402825 */ 	or	$a1,$v0,$zero
/*  f191530:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f191534:	0fc30a96 */ 	jal	func0f0c2a58
/*  f191538:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f19153c:	0fc0f917 */ 	jal	func0f03e45c
/*  f191540:	02202025 */ 	or	$a0,$s1,$zero
/*  f191544:	c61200a8 */ 	lwc1	$f18,0xa8($s0)
/*  f191548:	44802000 */ 	mtc1	$zero,$f4
/*  f19154c:	3c017f1c */ 	lui	$at,%hi(var7f1b8eb0)
/*  f191550:	46120081 */ 	sub.s	$f2,$f0,$f18
/*  f191554:	4604103c */ 	c.lt.s	$f2,$f4
/*  f191558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19155c:	45000003 */ 	bc1f	.L0f19156c
/*  f191560:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191564:	c4208eb0 */ 	lwc1	$f0,%lo(var7f1b8eb0)($at)
/*  f191568:	46001080 */ 	add.s	$f2,$f2,$f0
.L0f19156c:
/*  f19156c:	3c017f1c */ 	lui	$at,%hi(var7f1b8eb4)
/*  f191570:	c4208eb4 */ 	lwc1	$f0,%lo(var7f1b8eb4)($at)
/*  f191574:	4602003e */ 	c.le.s	$f0,$f2
/*  f191578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19157c:	45020003 */ 	bc1fl	.L0f19158c
/*  f191580:	44051000 */ 	mfc1	$a1,$f2
/*  f191584:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f191588:	44051000 */ 	mfc1	$a1,$f2
.L0f19158c:
/*  f19158c:	0c006ba4 */ 	jal	func0001ae90
/*  f191590:	8e240020 */ 	lw	$a0,0x20($s1)
/*  f191594:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f191598:
/*  f191598:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19159c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f1915a0:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f1915a4:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f1915a8:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f1915ac:	03e00008 */ 	jr	$ra
/*  f1915b0:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

u32 func0f1915b4(struct chrdata *chr)
{
	if (chr->unk2d4) {
		return chr->unk2d4->unk20;
	}

	return g_Vars.players[propGetPlayerNum(chr->prop)]->unk0638;
}

u8 func0f191600(struct chrdata *chr)
{
	struct prop *prop = chrGetTargetProp(chr);
	u8 result = 0;

	if (prop) {
		result = func0f1915b4(prop->chr);
	}

	return result;
}

GLOBAL_ASM(
glabel func0f191638
/*  f191638:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f19163c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f191640:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f191644:	848e017e */ 	lh	$t6,0x17e($a0)
/*  f191648:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19164c:	00003025 */ 	or	$a2,$zero,$zero
/*  f191650:	51c1009b */ 	beql	$t6,$at,.L0f1918c0
/*  f191654:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f191658:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f19165c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f191660:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f191664:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f191668:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f19166c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f191670:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f191674:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f191678:	00024080 */ 	sll	$t0,$v0,0x2
/*  f19167c:	8ce302d4 */ 	lw	$v1,0x2d4($a3)
/*  f191680:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f191684:	3c0b800a */ 	lui	$t3,0x800a
/*  f191688:	00627821 */ 	addu	$t7,$v1,$v0
/*  f19168c:	91f8016c */ 	lbu	$t8,0x16c($t7)
/*  f191690:	00684821 */ 	addu	$t1,$v1,$t0
/*  f191694:	53000003 */ 	beqzl	$t8,.L0f1916a4
/*  f191698:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f19169c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1916a0:	8c790004 */ 	lw	$t9,0x4($v1)
.L0f1916a4:
/*  f1916a4:	93240048 */ 	lbu	$a0,0x48($t9)
/*  f1916a8:	58800042 */ 	blezl	$a0,.L0f1917b4
/*  f1916ac:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f1916b0:	8d6b9fc8 */ 	lw	$t3,-0x6038($t3)
/*  f1916b4:	8d2a0178 */ 	lw	$t2,0x178($t1)
/*  f1916b8:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f1916bc:	256cff10 */ 	addiu	$t4,$t3,-240
/*  f1916c0:	014c082a */ 	slt	$at,$t2,$t4
/*  f1916c4:	10200007 */ 	beqz	$at,.L0f1916e4
/*  f1916c8:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f1916cc:	8ce4001c */ 	lw	$a0,0x1c($a3)
/*  f1916d0:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f1916d4:	0fc19620 */ 	jal	func0f065880
/*  f1916d8:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f1916dc:	10400002 */ 	beqz	$v0,.L0f1916e8
/*  f1916e0:	8fa6002c */ 	lw	$a2,0x2c($sp)
.L0f1916e4:
/*  f1916e4:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1916e8:
/*  f1916e8:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f1916ec:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f1916f0:	8ced02d4 */ 	lw	$t5,0x2d4($a3)
/*  f1916f4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f1916f8:	91c40048 */ 	lbu	$a0,0x48($t6)
/*  f1916fc:	28810002 */ 	slti	$at,$a0,0x2
/*  f191700:	5420002c */ 	bnezl	$at,.L0f1917b4
/*  f191704:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f191708:	8cef001c */ 	lw	$t7,0x1c($a3)
/*  f19170c:	87050028 */ 	lh	$a1,0x28($t8)
/*  f191710:	85e40028 */ 	lh	$a0,0x28($t7)
/*  f191714:	0fc591ae */ 	jal	func0f1646b8
/*  f191718:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f19171c:	1440000f */ 	bnez	$v0,.L0f19175c
/*  f191720:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f191724:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f191728:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f19172c:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f191730:	8f2802d4 */ 	lw	$t0,0x2d4($t9)
/*  f191734:	00095840 */ 	sll	$t3,$t1,0x1
/*  f191738:	85850028 */ 	lh	$a1,0x28($t4)
/*  f19173c:	010b5021 */ 	addu	$t2,$t0,$t3
/*  f191740:	854401a8 */ 	lh	$a0,0x1a8($t2)
/*  f191744:	50850006 */ 	beql	$a0,$a1,.L0f191760
/*  f191748:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19174c:	0fc591ae */ 	jal	func0f1646b8
/*  f191750:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f191754:	10400002 */ 	beqz	$v0,.L0f191760
/*  f191758:	8fa6002c */ 	lw	$a2,0x2c($sp)
.L0f19175c:
/*  f19175c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f191760:
/*  f191760:	8fad0030 */ 	lw	$t5,0x30($sp)
/*  f191764:	24010002 */ 	addiu	$at,$zero,0x2
/*  f191768:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f19176c:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f191770:	91c40048 */ 	lbu	$a0,0x48($t6)
/*  f191774:	54810009 */ 	bnel	$a0,$at,.L0f19179c
/*  f191778:	8c620208 */ 	lw	$v0,0x208($v1)
/*  f19177c:	8c620208 */ 	lw	$v0,0x208($v1)
/*  f191780:	1840000b */ 	blez	$v0,.L0f1917b0
/*  f191784:	28410004 */ 	slti	$at,$v0,0x4
/*  f191788:	5020000a */ 	beqzl	$at,.L0f1917b4
/*  f19178c:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f191790:	10000007 */ 	beqz	$zero,.L0f1917b0
/*  f191794:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f191798:	8c620208 */ 	lw	$v0,0x208($v1)
.L0f19179c:
/*  f19179c:	18400004 */ 	blez	$v0,.L0f1917b0
/*  f1917a0:	28410005 */ 	slti	$at,$v0,0x5
/*  f1917a4:	50200003 */ 	beqzl	$at,.L0f1917b4
/*  f1917a8:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f1917ac:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1917b0:
/*  f1917b0:	8faf0034 */ 	lw	$t7,0x34($sp)
.L0f1917b4:
/*  f1917b4:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f1917b8:	55e00041 */ 	bnezl	$t7,.L0f1918c0
/*  f1917bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1917c0:	10800002 */ 	beqz	$a0,.L0f1917cc
/*  f1917c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1917c8:	1481003c */ 	bne	$a0,$at,.L0f1918bc
.L0f1917cc:
/*  f1917cc:	00e02025 */ 	or	$a0,$a3,$zero
/*  f1917d0:	0fc0b819 */ 	jal	func0f02e064
/*  f1917d4:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f1917d8:	14400038 */ 	bnez	$v0,.L0f1918bc
/*  f1917dc:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f1917e0:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f1917e4:	0fc0f95e */ 	jal	func0f03e578
/*  f1917e8:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f1917ec:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f1917f0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f1917f4:	8f02001c */ 	lw	$v0,0x1c($t8)
/*  f1917f8:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f1917fc:	c7280010 */ 	lwc1	$f8,0x10($t9)
/*  f191800:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f191804:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f191808:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f19180c:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f191810:	0fc259d4 */ 	jal	func0f096750
/*  f191814:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f191818:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*  f19181c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f191820:	3c017f1c */ 	lui	$at,%hi(var7f1b8eb8)
/*  f191824:	4610003c */ 	c.lt.s	$f0,$f16
/*  f191828:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f19182c:	46100301 */ 	sub.s	$f12,$f0,$f16
/*  f191830:	45000003 */ 	bc1f	.L0f191840
/*  f191834:	46006086 */ 	mov.s	$f2,$f12
/*  f191838:	c4328eb8 */ 	lwc1	$f18,%lo(var7f1b8eb8)($at)
/*  f19183c:	46126080 */ 	add.s	$f2,$f12,$f18
.L0f191840:
/*  f191840:	3c017f1c */ 	lui	$at,%hi(var7f1b8ebc)
/*  f191844:	c4248ebc */ 	lwc1	$f4,%lo(var7f1b8ebc)($at)
/*  f191848:	3c017f1c */ 	lui	$at,%hi(var7f1b8ec0)
/*  f19184c:	4602203c */ 	c.lt.s	$f4,$f2
/*  f191850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191854:	45020004 */ 	bc1fl	.L0f191868
/*  f191858:	8d2802d4 */ 	lw	$t0,0x2d4($t1)
/*  f19185c:	c4268ec0 */ 	lwc1	$f6,%lo(var7f1b8ec0)($at)
/*  f191860:	46023081 */ 	sub.s	$f2,$f6,$f2
/*  f191864:	8d2802d4 */ 	lw	$t0,0x2d4($t1)
.L0f191868:
/*  f191868:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19186c:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*  f191870:	91640048 */ 	lbu	$a0,0x48($t3)
/*  f191874:	14800009 */ 	bnez	$a0,.L0f19189c
/*  f191878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19187c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ec4)
/*  f191880:	c4288ec4 */ 	lwc1	$f8,%lo(var7f1b8ec4)($at)
/*  f191884:	4602403c */ 	c.lt.s	$f8,$f2
/*  f191888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19188c:	4502000c */ 	bc1fl	.L0f1918c0
/*  f191890:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f191894:	10000009 */ 	beqz	$zero,.L0f1918bc
/*  f191898:	00003025 */ 	or	$a2,$zero,$zero
.L0f19189c:
/*  f19189c:	14810007 */ 	bne	$a0,$at,.L0f1918bc
/*  f1918a0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ec8)
/*  f1918a4:	c42a8ec8 */ 	lwc1	$f10,%lo(var7f1b8ec8)($at)
/*  f1918a8:	4602503c */ 	c.lt.s	$f10,$f2
/*  f1918ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1918b0:	45020003 */ 	bc1fl	.L0f1918c0
/*  f1918b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1918b8:	00003025 */ 	or	$a2,$zero,$zero
.L0f1918bc:
/*  f1918bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1918c0:
/*  f1918c0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1918c4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f1918c8:	03e00008 */ 	jr	$ra
/*  f1918cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1918d0
/*  f1918d0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1918d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1918d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1918dc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1918e0:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f1918e4:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f1918e8:	8e3002d4 */ 	lw	$s0,0x2d4($s1)
/*  f1918ec:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f1918f0:	90870001 */ 	lbu	$a3,0x1($a0)
/*  f1918f4:	30ef0008 */ 	andi	$t7,$a3,0x8
/*  f1918f8:	000f382b */ 	sltu	$a3,$zero,$t7
/*  f1918fc:	10e00005 */ 	beqz	$a3,.L0f191914
/*  f191900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191904:	3c07800a */ 	lui	$a3,0x800a
/*  f191908:	8ce79ff4 */ 	lw	$a3,-0x600c($a3)
/*  f19190c:	0007c82b */ 	sltu	$t9,$zero,$a3
/*  f191910:	03203825 */ 	or	$a3,$t9,$zero
.L0f191914:
/*  f191914:	1200019d */ 	beqz	$s0,.L0f191f8c
/*  f191918:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f19191c:	10e00183 */ 	beqz	$a3,.L0f191f2c
/*  f191920:	3c08800a */ 	lui	$t0,0x800a
/*  f191924:	8d089fc8 */ 	lw	$t0,-0x6038($t0)
/*  f191928:	29010091 */ 	slti	$at,$t0,0x91
/*  f19192c:	1420017f */ 	bnez	$at,.L0f191f2c
/*  f191930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191934:	0fc652d0 */ 	jal	func0f194b40
/*  f191938:	02202025 */ 	or	$a0,$s1,$zero
/*  f19193c:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f191940:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191944:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f191948:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19194c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f191950:	858d0028 */ 	lh	$t5,0x28($t4)
/*  f191954:	11a10014 */ 	beq	$t5,$at,.L0f1919a8
/*  f191958:	01801825 */ 	or	$v1,$t4,$zero
/*  f19195c:	85840028 */ 	lh	$a0,0x28($t4)
.L0f191960:
/*  f191960:	0fc575ba */ 	jal	func0f15d6e8
/*  f191964:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f191968:	14400006 */ 	bnez	$v0,.L0f191984
/*  f19196c:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f191970:	84640028 */ 	lh	$a0,0x28($v1)
/*  f191974:	0fc575d1 */ 	jal	func0f15d744
/*  f191978:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f19197c:	10400005 */ 	beqz	$v0,.L0f191994
/*  f191980:	8fa30028 */ 	lw	$v1,0x28($sp)
.L0f191984:
/*  f191984:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f191988:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f19198c:	10000006 */ 	beqz	$zero,.L0f1919a8
/*  f191990:	a20f009c */ 	sb	$t7,0x9c($s0)
.L0f191994:
/*  f191994:	8464002a */ 	lh	$a0,0x2a($v1)
/*  f191998:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19199c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f1919a0:	1481ffef */ 	bne	$a0,$at,.L0f191960
/*  f1919a4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1919a8:
/*  f1919a8:	862202d8 */ 	lh	$v0,0x2d8($s1)
/*  f1919ac:	18400012 */ 	blez	$v0,.L0f1919f8
/*  f1919b0:	28411389 */ 	slti	$at,$v0,0x1389
/*  f1919b4:	14200004 */ 	bnez	$at,.L0f1919c8
/*  f1919b8:	3c19800a */ 	lui	$t9,0x800a
/*  f1919bc:	24181388 */ 	addiu	$t8,$zero,0x1388
/*  f1919c0:	a63802d8 */ 	sh	$t8,0x2d8($s1)
/*  f1919c4:	862202d8 */ 	lh	$v0,0x2d8($s1)
.L0f1919c8:
/*  f1919c8:	922802ff */ 	lbu	$t0,0x2ff($s1)
/*  f1919cc:	8f399ff8 */ 	lw	$t9,-0x6008($t9)
/*  f1919d0:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f1919d4:	03290019 */ 	multu	$t9,$t1
/*  f1919d8:	00005012 */ 	mflo	$t2
/*  f1919dc:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f1919e0:	a62b02d8 */ 	sh	$t3,0x2d8($s1)
/*  f1919e4:	862d02d8 */ 	lh	$t5,0x2d8($s1)
/*  f1919e8:	1da00003 */ 	bgtz	$t5,.L0f1919f8
/*  f1919ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1919f0:	a62002d8 */ 	sh	$zero,0x2d8($s1)
/*  f1919f4:	a22002ff */ 	sb	$zero,0x2ff($s1)
.L0f1919f8:
/*  f1919f8:	0fc0f917 */ 	jal	func0f03e45c
/*  f1919fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a00:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f191a04:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191a08:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a0c:	50400006 */ 	beqzl	$v0,.L0f191a28
/*  f191a10:	8e0c0044 */ 	lw	$t4,0x44($s0)
/*  f191a14:	0fc0f917 */ 	jal	func0f03e45c
/*  f191a18:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a1c:	1000005b */ 	beqz	$zero,.L0f191b8c
/*  f191a20:	46000086 */ 	mov.s	$f2,$f0
/*  f191a24:	8e0c0044 */ 	lw	$t4,0x44($s0)
.L0f191a28:
/*  f191a28:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a2c:	11800005 */ 	beqz	$t4,.L0f191a44
/*  f191a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191a34:	0fc0f917 */ 	jal	func0f03e45c
/*  f191a38:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a3c:	10000053 */ 	beqz	$zero,.L0f191b8c
/*  f191a40:	46000086 */ 	mov.s	$f2,$f0
.L0f191a44:
/*  f191a44:	0fc6458e */ 	jal	func0f191638
/*  f191a48:	00002825 */ 	or	$a1,$zero,$zero
/*  f191a4c:	5040000c */ 	beqzl	$v0,.L0f191a80
/*  f191a50:	922402a0 */ 	lbu	$a0,0x2a0($s1)
/*  f191a54:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f191a58:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a60:	0fc122a1 */ 	jal	func0f048a84
/*  f191a64:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f191a68:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191a6c:	c60801c0 */ 	lwc1	$f8,0x1c0($s0)
/*  f191a70:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f191a74:	10000045 */ 	beqz	$zero,.L0f191b8c
/*  f191a78:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f191a7c:	922402a0 */ 	lbu	$a0,0x2a0($s1)
.L0f191a80:
/*  f191a80:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f191a84:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f191a88:	1481000f */ 	bne	$a0,$at,.L0f191ac8
/*  f191a8c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f191a90:	8c6200d4 */ 	lw	$v0,0xd4($v1)
/*  f191a94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191a98:	1041000b */ 	beq	$v0,$at,.L0f191ac8
/*  f191a9c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f191aa0:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f191aa4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f191aa8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f191aac:	8de50080 */ 	lw	$a1,0x80($t7)
/*  f191ab0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191ab4:	0fc122a1 */ 	jal	func0f048a84
/*  f191ab8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f191abc:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191ac0:	10000032 */ 	beqz	$zero,.L0f191b8c
/*  f191ac4:	46005080 */ 	add.s	$f2,$f10,$f0
.L0f191ac8:
/*  f191ac8:	24010032 */ 	addiu	$at,$zero,0x32
/*  f191acc:	5481001e */ 	bnel	$a0,$at,.L0f191b48
/*  f191ad0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191ad4:	8602000a */ 	lh	$v0,0xa($s0)
/*  f191ad8:	3c014396 */ 	lui	$at,0x4396
/*  f191adc:	04400019 */ 	bltz	$v0,.L0f191b44
/*  f191ae0:	00021880 */ 	sll	$v1,$v0,0x2
/*  f191ae4:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f191ae8:	c704013c */ 	lwc1	$f4,0x13c($t8)
/*  f191aec:	44813000 */ 	mtc1	$at,$f6
/*  f191af0:	3c19800a */ 	lui	$t9,0x800a
/*  f191af4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f191af8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191afc:	45020012 */ 	bc1fl	.L0f191b48
/*  f191b00:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b04:	8f399fc8 */ 	lw	$t9,-0x6038($t9)
/*  f191b08:	8e0801e4 */ 	lw	$t0,0x1e4($s0)
/*  f191b0c:	2729ffc4 */ 	addiu	$t1,$t9,-60
/*  f191b10:	0109082a */ 	slt	$at,$t0,$t1
/*  f191b14:	5420000c */ 	bnezl	$at,.L0f191b48
/*  f191b18:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b1c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f191b20:	914b0048 */ 	lbu	$t3,0x48($t2)
/*  f191b24:	51600008 */ 	beqzl	$t3,.L0f191b48
/*  f191b28:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b2c:	3c04800b */ 	lui	$a0,0x800b
/*  f191b30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f191b34:	0fc0f917 */ 	jal	func0f03e45c
/*  f191b38:	8c84c4d0 */ 	lw	$a0,-0x3b30($a0)
/*  f191b3c:	10000013 */ 	beqz	$zero,.L0f191b8c
/*  f191b40:	46000086 */ 	mov.s	$f2,$f0
.L0f191b44:
/*  f191b44:	24010033 */ 	addiu	$at,$zero,0x33
.L0f191b48:
/*  f191b48:	1481000d */ 	bne	$a0,$at,.L0f191b80
/*  f191b4c:	3c0c800a */ 	lui	$t4,0x800a
/*  f191b50:	8d8c9fc8 */ 	lw	$t4,-0x6038($t4)
/*  f191b54:	8e0d01e4 */ 	lw	$t5,0x1e4($s0)
/*  f191b58:	258effc4 */ 	addiu	$t6,$t4,-60
/*  f191b5c:	01ae082a */ 	slt	$at,$t5,$t6
/*  f191b60:	14200007 */ 	bnez	$at,.L0f191b80
/*  f191b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191b68:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f191b6c:	91f80048 */ 	lbu	$t8,0x48($t7)
/*  f191b70:	13000003 */ 	beqz	$t8,.L0f191b80
/*  f191b74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191b78:	10000004 */ 	beqz	$zero,.L0f191b8c
/*  f191b7c:	c6020098 */ 	lwc1	$f2,0x98($s0)
.L0f191b80:
/*  f191b80:	0fc0f95e */ 	jal	func0f03e578
/*  f191b84:	02202025 */ 	or	$a0,$s1,$zero
/*  f191b88:	46000086 */ 	mov.s	$f2,$f0
.L0f191b8c:
/*  f191b8c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ecc)
/*  f191b90:	c42e8ecc */ 	lwc1	$f14,%lo(var7f1b8ecc)($at)
/*  f191b94:	44809000 */ 	mtc1	$zero,$f18
/*  f191b98:	4602703e */ 	c.le.s	$f14,$f2
/*  f191b9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191ba0:	45020007 */ 	bc1fl	.L0f191bc0
/*  f191ba4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191ba8:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191bac:
/*  f191bac:	4602703e */ 	c.le.s	$f14,$f2
/*  f191bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191bb4:	4503fffd */ 	bc1tl	.L0f191bac
/*  f191bb8:	460e1081 */ 	sub.s	$f2,$f2,$f14
/*  f191bbc:	4612103c */ 	c.lt.s	$f2,$f18
.L0f191bc0:
/*  f191bc0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191bc4:	45020007 */ 	bc1fl	.L0f191be4
/*  f191bc8:	863902d8 */ 	lh	$t9,0x2d8($s1)
/*  f191bcc:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191bd0:
/*  f191bd0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191bd8:	4503fffd */ 	bc1tl	.L0f191bd0
/*  f191bdc:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f191be0:	863902d8 */ 	lh	$t9,0x2d8($s1)
.L0f191be4:
/*  f191be4:	5b20002c */ 	blezl	$t9,.L0f191c98
/*  f191be8:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191bec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191bf0:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191bf4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed0)
/*  f191bf8:	44809000 */ 	mtc1	$zero,$f18
/*  f191bfc:	c42e8ed0 */ 	lwc1	$f14,%lo(var7f1b8ed0)($at)
/*  f191c00:	14400024 */ 	bnez	$v0,.L0f191c94
/*  f191c04:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c08:	8e080044 */ 	lw	$t0,0x44($s0)
/*  f191c0c:	3c09800a */ 	lui	$t1,0x800a
/*  f191c10:	55000021 */ 	bnezl	$t0,.L0f191c98
/*  f191c14:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191c18:	8d299fc8 */ 	lw	$t1,-0x6038($t1)
/*  f191c1c:	24010078 */ 	addiu	$at,$zero,0x78
/*  f191c20:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191c24:	0121001a */ 	div	$zero,$t1,$at
/*  f191c28:	00005010 */ 	mfhi	$t2
/*  f191c2c:	448a4000 */ 	mtc1	$t2,$f8
/*  f191c30:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed4)
/*  f191c34:	c4248ed4 */ 	lwc1	$f4,%lo(var7f1b8ed4)($at)
/*  f191c38:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f191c3c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f191c40:	0c0068f7 */ 	jal	func0001a3dc
/*  f191c44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191c48:	862b02d8 */ 	lh	$t3,0x2d8($s1)
/*  f191c4c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed8)
/*  f191c50:	c42e8ed8 */ 	lwc1	$f14,%lo(var7f1b8ed8)($at)
/*  f191c54:	448b3000 */ 	mtc1	$t3,$f6
/*  f191c58:	3c017f1c */ 	lui	$at,%hi(var7f1b8edc)
/*  f191c5c:	c42a8edc */ 	lwc1	$f10,%lo(var7f1b8edc)($at)
/*  f191c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f191c64:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c68:	44809000 */ 	mtc1	$zero,$f18
/*  f191c6c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f191c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191c74:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f191c78:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f191c7c:	4602703e */ 	c.le.s	$f14,$f2
/*  f191c80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191c84:	45000002 */ 	bc1f	.L0f191c90
/*  f191c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191c8c:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191c90:
/*  f191c90:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191c94:
/*  f191c94:	c7a40044 */ 	lwc1	$f4,0x44($sp)
.L0f191c98:
/*  f191c98:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee0)
/*  f191c9c:	c42a8ee0 */ 	lwc1	$f10,%lo(var7f1b8ee0)($at)
/*  f191ca0:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f191ca4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee4)
/*  f191ca8:	c4268ee4 */ 	lwc1	$f6,%lo(var7f1b8ee4)($at)
/*  f191cac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f191cb0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f191cb4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f191cb8:	c448004c */ 	lwc1	$f8,0x4c($v0)
/*  f191cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f191cc0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee8)
/*  f191cc4:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f191cc8:	45000003 */ 	bc1f	.L0f191cd8
/*  f191ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191cd0:	10000007 */ 	beqz	$zero,.L0f191cf0
/*  f191cd4:	460e0400 */ 	add.s	$f16,$f0,$f14
.L0f191cd8:
/*  f191cd8:	c4288ee8 */ 	lwc1	$f8,%lo(var7f1b8ee8)($at)
/*  f191cdc:	4600403e */ 	c.le.s	$f8,$f0
/*  f191ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191ce4:	45020003 */ 	bc1fl	.L0f191cf4
/*  f191ce8:	4610903e */ 	c.le.s	$f18,$f16
/*  f191cec:	460e0401 */ 	sub.s	$f16,$f0,$f14
.L0f191cf0:
/*  f191cf0:	4610903e */ 	c.le.s	$f18,$f16
.L0f191cf4:
/*  f191cf4:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f191cf8:	3c017f1c */ 	lui	$at,%hi(var7f1b8eec)
/*  f191cfc:	4502000f */ 	bc1fl	.L0f191d3c
/*  f191d00:	46006107 */ 	neg.s	$f4,$f12
/*  f191d04:	460c803e */ 	c.le.s	$f16,$f12
/*  f191d08:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191d0c:	45020004 */ 	bc1fl	.L0f191d20
/*  f191d10:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f191d14:	10000015 */ 	beqz	$zero,.L0f191d6c
/*  f191d18:	46001006 */ 	mov.s	$f0,$f2
/*  f191d1c:	460c5080 */ 	add.s	$f2,$f10,$f12
.L0f191d20:
/*  f191d20:	4602703e */ 	c.le.s	$f14,$f2
/*  f191d24:	46001006 */ 	mov.s	$f0,$f2
/*  f191d28:	45020011 */ 	bc1fl	.L0f191d70
/*  f191d2c:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f191d30:	1000000e */ 	beqz	$zero,.L0f191d6c
/*  f191d34:	460e1001 */ 	sub.s	$f0,$f2,$f14
/*  f191d38:	46006107 */ 	neg.s	$f4,$f12
.L0f191d3c:
/*  f191d3c:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f191d40:	4610203e */ 	c.le.s	$f4,$f16
/*  f191d44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191d48:	45020004 */ 	bc1fl	.L0f191d5c
/*  f191d4c:	460c303c */ 	c.lt.s	$f6,$f12
/*  f191d50:	10000006 */ 	beqz	$zero,.L0f191d6c
/*  f191d54:	46001006 */ 	mov.s	$f0,$f2
/*  f191d58:	460c303c */ 	c.lt.s	$f6,$f12
.L0f191d5c:
/*  f191d5c:	460c3081 */ 	sub.s	$f2,$f6,$f12
/*  f191d60:	45000002 */ 	bc1f	.L0f191d6c
/*  f191d64:	46001006 */ 	mov.s	$f0,$f2
/*  f191d68:	460e1000 */ 	add.s	$f0,$f2,$f14
.L0f191d6c:
/*  f191d6c:	46080281 */ 	sub.s	$f10,$f0,$f8
.L0f191d70:
/*  f191d70:	e60a00ac */ 	swc1	$f10,0xac($s0)
/*  f191d74:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191d78:	4604003c */ 	c.lt.s	$f0,$f4
/*  f191d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191d80:	45020005 */ 	bc1fl	.L0f191d98
/*  f191d84:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191d88:	c60600ac */ 	lwc1	$f6,0xac($s0)
/*  f191d8c:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f191d90:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191d94:	c60200ac */ 	lwc1	$f2,0xac($s0)
.L0f191d98:
/*  f191d98:	c42a8eec */ 	lwc1	$f10,%lo(var7f1b8eec)($at)
/*  f191d9c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef0)
/*  f191da0:	4602503e */ 	c.le.s	$f10,$f2
/*  f191da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191da8:	45020005 */ 	bc1fl	.L0f191dc0
/*  f191dac:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f191db0:	460e1101 */ 	sub.s	$f4,$f2,$f14
/*  f191db4:	e60400ac */ 	swc1	$f4,0xac($s0)
/*  f191db8:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191dbc:	c446004c */ 	lwc1	$f6,0x4c($v0)
.L0f191dc0:
/*  f191dc0:	4600703e */ 	c.le.s	$f14,$f0
/*  f191dc4:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f191dc8:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191dcc:	c60a00ac */ 	lwc1	$f10,0xac($s0)
/*  f191dd0:	c4248ef0 */ 	lwc1	$f4,%lo(var7f1b8ef0)($at)
/*  f191dd4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f191dd8:	45000006 */ 	bc1f	.L0f191df4
/*  f191ddc:	e60600ac */ 	swc1	$f6,0xac($s0)
/*  f191de0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191de4:
/*  f191de4:	4600703e */ 	c.le.s	$f14,$f0
/*  f191de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191dec:	4503fffd */ 	bc1tl	.L0f191de4
/*  f191df0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191df4:
/*  f191df4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191df8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191dfc:	45020007 */ 	bc1fl	.L0f191e1c
/*  f191e00:	44050000 */ 	mfc1	$a1,$f0
/*  f191e04:	460e0000 */ 	add.s	$f0,$f0,$f14
.L0f191e08:
/*  f191e08:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191e10:	4503fffd */ 	bc1tl	.L0f191e08
/*  f191e14:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f191e18:	44050000 */ 	mfc1	$a1,$f0
.L0f191e1c:
/*  f191e1c:	0fc0f94e */ 	jal	func0f03e538
/*  f191e20:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e24:	862c017e */ 	lh	$t4,0x17e($s1)
/*  f191e28:	44809000 */ 	mtc1	$zero,$f18
/*  f191e2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191e30:	11810018 */ 	beq	$t4,$at,.L0f191e94
/*  f191e34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191e38:	8e0d004c */ 	lw	$t5,0x4c($s0)
/*  f191e3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e40:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f191e44:	05e00013 */ 	bltz	$t7,.L0f191e94
/*  f191e48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191e4c:	8e380174 */ 	lw	$t8,0x174($s1)
/*  f191e50:	00003025 */ 	or	$a2,$zero,$zero
/*  f191e54:	00003825 */ 	or	$a3,$zero,$zero
/*  f191e58:	13000003 */ 	beqz	$t8,.L0f191e68
/*  f191e5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191e60:	10000001 */ 	beqz	$zero,.L0f191e68
/*  f191e64:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f191e68:
/*  f191e68:	8e390170 */ 	lw	$t9,0x170($s1)
/*  f191e6c:	13200003 */ 	beqz	$t9,.L0f191e7c
/*  f191e70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191e74:	10000001 */ 	beqz	$zero,.L0f191e7c
/*  f191e78:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f191e7c:
/*  f191e7c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f191e80:	0fc0fa7d */ 	jal	func0f03e9f4
/*  f191e84:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f191e88:	44809000 */ 	mtc1	$zero,$f18
/*  f191e8c:	10000006 */ 	beqz	$zero,.L0f191ea8
/*  f191e90:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191e94:
/*  f191e94:	0fc0fe0a */ 	jal	chrResetAimEndProperties
/*  f191e98:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e9c:	44809000 */ 	mtc1	$zero,$f18
/*  f191ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191ea4:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191ea8:
/*  f191ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191eac:	10410003 */ 	beq	$v0,$at,.L0f191ebc
/*  f191eb0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f191eb4:	54410005 */ 	bnel	$v0,$at,.L0f191ecc
/*  f191eb8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ebc:
/*  f191ebc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ec0:	1000001a */ 	beqz	$zero,.L0f191f2c
/*  f191ec4:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ec8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ecc:
/*  f191ecc:	3c09800a */ 	lui	$t1,0x800a
/*  f191ed0:	2401000f */ 	addiu	$at,$zero,0xf
/*  f191ed4:	11000006 */ 	beqz	$t0,.L0f191ef0
/*  f191ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f191edc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ee0:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ee4:	8d299fc8 */ 	lw	$t1,-0x6038($t1)
/*  f191ee8:	10000010 */ 	beqz	$zero,.L0f191f2c
/*  f191eec:	ae0901e4 */ 	sw	$t1,0x1e4($s0)
.L0f191ef0:
/*  f191ef0:	1441000a */ 	bne	$v0,$at,.L0f191f1c
/*  f191ef4:	3c0c800a */ 	lui	$t4,0x800a
/*  f191ef8:	922a0065 */ 	lbu	$t2,0x65($s1)
/*  f191efc:	3c013f80 */ 	lui	$at,0x3f80
/*  f191f00:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f191f04:	55600006 */ 	bnezl	$t3,.L0f191f20
/*  f191f08:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191f0c:	44814000 */ 	mtc1	$at,$f8
/*  f191f10:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f14:	10000005 */ 	beqz	$zero,.L0f191f2c
/*  f191f18:	e608006c */ 	swc1	$f8,0x6c($s0)
.L0f191f1c:
/*  f191f1c:	e612006c */ 	swc1	$f18,0x6c($s0)
.L0f191f20:
/*  f191f20:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f24:	8d8c9fc8 */ 	lw	$t4,-0x6038($t4)
/*  f191f28:	ae0c01e4 */ 	sw	$t4,0x1e4($s0)
.L0f191f2c:
/*  f191f2c:	0fc64512 */ 	jal	func0f191448
/*  f191f30:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f34:	0fc08c26 */ 	jal	func0f023098
/*  f191f38:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191f3c:	3c0d800a */ 	lui	$t5,0x800a
/*  f191f40:	8dad9fc8 */ 	lw	$t5,-0x6038($t5)
/*  f191f44:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f191f48:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f191f4c:	29a10091 */ 	slti	$at,$t5,0x91
/*  f191f50:	5420000f */ 	bnezl	$at,.L0f191f90
/*  f191f54:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f58:	51c00004 */ 	beqzl	$t6,.L0f191f6c
/*  f191f5c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f191f60:	0fc615c8 */ 	jal	scenarioCallback14
/*  f191f64:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f68:	8faf0058 */ 	lw	$t7,0x58($sp)
.L0f191f6c:
/*  f191f6c:	51e00008 */ 	beqzl	$t7,.L0f191f90
/*  f191f70:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f74:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191f78:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f7c:	54400004 */ 	bnezl	$v0,.L0f191f90
/*  f191f80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f84:	0fc64493 */ 	jal	func0f19124c
/*  f191f88:	02202025 */ 	or	$a0,$s1,$zero
.L0f191f8c:
/*  f191f8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191f90:
/*  f191f90:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f191f94:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f191f98:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f191f9c:	03e00008 */ 	jr	$ra
/*  f191fa0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f191fa4
/*  f191fa4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f191fa8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f191fac:	8c8502d4 */ 	lw	$a1,0x2d4($a0)
/*  f191fb0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef4)
/*  f191fb4:	8ca2009c */ 	lw	$v0,0x9c($a1)
/*  f191fb8:	00027840 */ 	sll	$t7,$v0,0x1
/*  f191fbc:	05e00003 */ 	bltz	$t7,.L0f191fcc
/*  f191fc0:	0002c7c2 */ 	srl	$t8,$v0,0x1f
/*  f191fc4:	53000004 */ 	beqzl	$t8,.L0f191fd8
/*  f191fc8:	84990010 */ 	lh	$t9,0x10($a0)
.L0f191fcc:
/*  f191fcc:	10000015 */ 	beqz	$zero,.L0f192024
/*  f191fd0:	c4228ef4 */ 	lwc1	$f2,%lo(var7f1b8ef4)($at)
/*  f191fd4:	84990010 */ 	lh	$t9,0x10($a0)
.L0f191fd8:
/*  f191fd8:	3c098008 */ 	lui	$t1,0x8008
/*  f191fdc:	3c014f80 */ 	lui	$at,0x4f80
/*  f191fe0:	00194080 */ 	sll	$t0,$t9,0x2
/*  f191fe4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f191fe8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f191fec:	01284821 */ 	addu	$t1,$t1,$t0
/*  f191ff0:	8d29cf04 */ 	lw	$t1,-0x30fc($t1)
/*  f191ff4:	00095180 */ 	sll	$t2,$t1,0x6
/*  f191ff8:	000a5e02 */ 	srl	$t3,$t2,0x18
/*  f191ffc:	448b2000 */ 	mtc1	$t3,$f4
/*  f192000:	05610004 */ 	bgez	$t3,.L0f192014
/*  f192004:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f192008:	44814000 */ 	mtc1	$at,$f8
/*  f19200c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192010:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f192014:
/*  f192014:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef8)
/*  f192018:	c42a8ef8 */ 	lwc1	$f10,%lo(var7f1b8ef8)($at)
/*  f19201c:	460a3082 */ 	mul.s	$f2,$f6,$f10
/*  f192020:	00000000 */ 	sll	$zero,$zero,0x0
.L0f192024:
/*  f192024:	3c017f1c */ 	lui	$at,%hi(var7f1b8efc)
/*  f192028:	c4308efc */ 	lwc1	$f16,%lo(var7f1b8efc)($at)
/*  f19202c:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f192030:	3c013f80 */ 	lui	$at,0x3f80
/*  f192034:	46101482 */ 	mul.s	$f18,$f2,$f16
/*  f192038:	44812000 */ 	mtc1	$at,$f4
/*  f19203c:	90430047 */ 	lbu	$v1,0x47($v0)
/*  f192040:	2401000b */ 	addiu	$at,$zero,0xb
/*  f192044:	14610007 */ 	bne	$v1,$at,.L0f192064
/*  f192048:	46049080 */ 	add.s	$f2,$f18,$f4
/*  f19204c:	3c014060 */ 	lui	$at,0x4060
/*  f192050:	44814000 */ 	mtc1	$at,$f8
/*  f192054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192058:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f19205c:	10000031 */ 	beqz	$zero,.L0f192124
/*  f192060:	afa40020 */ 	sw	$a0,0x20($sp)
.L0f192064:
/*  f192064:	2401000a */ 	addiu	$at,$zero,0xa
/*  f192068:	14610006 */ 	bne	$v1,$at,.L0f192084
/*  f19206c:	3c014160 */ 	lui	$at,0x4160
/*  f192070:	44813000 */ 	mtc1	$at,$f6
/*  f192074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192078:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f19207c:	10000029 */ 	beqz	$zero,.L0f192124
/*  f192080:	afa40020 */ 	sw	$a0,0x20($sp)
.L0f192084:
/*  f192084:	904c0048 */ 	lbu	$t4,0x48($v0)
/*  f192088:	2d810006 */ 	sltiu	$at,$t4,0x6
/*  f19208c:	10200011 */ 	beqz	$at,.L0f1920d4
/*  f192090:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f192094:	3c017f1c */ 	lui	$at,%hi(var7f1b8f00)
/*  f192098:	002c0821 */ 	addu	$at,$at,$t4
/*  f19209c:	8c2c8f00 */ 	lw	$t4,%lo(var7f1b8f00)($at)
/*  f1920a0:	01800008 */ 	jr	$t4
/*  f1920a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1920a8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1920ac:	44815000 */ 	mtc1	$at,$f10
/*  f1920b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1920b4:	460a1082 */ 	mul.s	$f2,$f2,$f10
/*  f1920b8:	1000001a */ 	beqz	$zero,.L0f192124
/*  f1920bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1920c0:	3c017f1c */ 	lui	$at,%hi(var7f1b8f18)
/*  f1920c4:	c4308f18 */ 	lwc1	$f16,%lo(var7f1b8f18)($at)
/*  f1920c8:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f1920cc:	10000015 */ 	beqz	$zero,.L0f192124
/*  f1920d0:	afa40020 */ 	sw	$a0,0x20($sp)
.L0f1920d4:
/*  f1920d4:	3c017f1c */ 	lui	$at,%hi(var7f1b8f1c)
/*  f1920d8:	c4328f1c */ 	lwc1	$f18,%lo(var7f1b8f1c)($at)
/*  f1920dc:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f1920e0:	10000010 */ 	beqz	$zero,.L0f192124
/*  f1920e4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1920e8:	3c017f1c */ 	lui	$at,%hi(var7f1b8f20)
/*  f1920ec:	c4248f20 */ 	lwc1	$f4,%lo(var7f1b8f20)($at)
/*  f1920f0:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f1920f4:	1000000b */ 	beqz	$zero,.L0f192124
/*  f1920f8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1920fc:	3c017f1c */ 	lui	$at,%hi(var7f1b8f24)
/*  f192100:	c4288f24 */ 	lwc1	$f8,%lo(var7f1b8f24)($at)
/*  f192104:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f192108:	10000006 */ 	beqz	$zero,.L0f192124
/*  f19210c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f192110:	3c017f1c */ 	lui	$at,%hi(var7f1b8f28)
/*  f192114:	c4268f28 */ 	lwc1	$f6,%lo(var7f1b8f28)($at)
/*  f192118:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f19211c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192120:	afa40020 */ 	sw	$a0,0x20($sp)
.L0f192124:
/*  f192124:	0fc644fe */ 	jal	func0f1913f8
/*  f192128:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f19212c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f192130:	14400006 */ 	bnez	$v0,.L0f19214c
/*  f192134:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f192138:	3c017f1c */ 	lui	$at,%hi(var7f1b8f2c)
/*  f19213c:	c42a8f2c */ 	lwc1	$f10,%lo(var7f1b8f2c)($at)
/*  f192140:	460a1082 */ 	mul.s	$f2,$f2,$f10
/*  f192144:	10000028 */ 	beqz	$zero,.L0f1921e8
/*  f192148:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19214c:
/*  f19214c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f192150:	0fc644fe */ 	jal	func0f1913f8
/*  f192154:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f192158:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19215c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f192160:	14410007 */ 	bne	$v0,$at,.L0f192180
/*  f192164:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f192168:	3c013f00 */ 	lui	$at,0x3f00
/*  f19216c:	44818000 */ 	mtc1	$at,$f16
/*  f192170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192174:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f192178:	1000001b */ 	beqz	$zero,.L0f1921e8
/*  f19217c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f192180:
/*  f192180:	808d0007 */ 	lb	$t5,0x7($a0)
/*  f192184:	2401000f */ 	addiu	$at,$zero,0xf
/*  f192188:	55a10017 */ 	bnel	$t5,$at,.L0f1921e8
/*  f19218c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f192190:	908e0064 */ 	lbu	$t6,0x64($a0)
/*  f192194:	2485002c */ 	addiu	$a1,$a0,0x2c
/*  f192198:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f19219c:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f1921a0:	8f19004c */ 	lw	$t9,0x4c($t8)
/*  f1921a4:	57200010 */ 	bnezl	$t9,.L0f1921e8
/*  f1921a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1921ac:	0fc12524 */ 	jal	chrGetLateralDistanceToCoord
/*  f1921b0:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f1921b4:	3c014348 */ 	lui	$at,0x4348
/*  f1921b8:	44819000 */ 	mtc1	$at,$f18
/*  f1921bc:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f1921c0:	3c013f00 */ 	lui	$at,0x3f00
/*  f1921c4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f1921c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1921cc:	45020006 */ 	bc1fl	.L0f1921e8
/*  f1921d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1921d4:	44812000 */ 	mtc1	$at,$f4
/*  f1921d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1921dc:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f1921e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1921e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1921e8:
/*  f1921e8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1921ec:	46001006 */ 	mov.s	$f0,$f2
/*  f1921f0:	03e00008 */ 	jr	$ra
/*  f1921f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1921f8
/*  f1921f8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f1921fc:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f192200:	00808025 */ 	or	$s0,$a0,$zero
/*  f192204:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f192208:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f19220c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f192210:	10800070 */ 	beqz	$a0,.L0f1923d4
/*  f192214:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f192218:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f19221c:	3c0e800a */ 	lui	$t6,0x800a
/*  f192220:	5040006d */ 	beqzl	$v0,.L0f1923d8
/*  f192224:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f192228:	8dce9fc8 */ 	lw	$t6,-0x6038($t6)
/*  f19222c:	02002025 */ 	or	$a0,$s0,$zero
/*  f192230:	29c10091 */ 	slti	$at,$t6,0x91
/*  f192234:	50200007 */ 	beqzl	$at,.L0f192254
/*  f192238:	c4540070 */ 	lwc1	$f20,0x70($v0)
/*  f19223c:	44806000 */ 	mtc1	$zero,$f12
/*  f192240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192244:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*  f192248:	10000062 */ 	beqz	$zero,.L0f1923d4
/*  f19224c:	e4ac0004 */ 	swc1	$f12,0x4($a1)
/*  f192250:	c4540070 */ 	lwc1	$f20,0x70($v0)
.L0f192254:
/*  f192254:	c456006c */ 	lwc1	$f22,0x6c($v0)
/*  f192258:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f19225c:	0fc647e9 */ 	jal	func0f191fa4
/*  f192260:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f192264:	4600a502 */ 	mul.s	$f20,$f20,$f0
/*  f192268:	02002025 */ 	or	$a0,$s0,$zero
/*  f19226c:	4600b582 */ 	mul.s	$f22,$f22,$f0
/*  f192270:	0fc0f95e */ 	jal	func0f03e578
/*  f192274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192278:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f19227c:	0c0068f4 */ 	jal	func0001a3d0
/*  f192280:	46000306 */ 	mov.s	$f12,$f0
/*  f192284:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f192288:	0c0068f7 */ 	jal	func0001a3dc
/*  f19228c:	e7a0004c */ 	swc1	$f0,0x4c($sp)
/*  f192290:	c7ae004c */ 	lwc1	$f14,0x4c($sp)
/*  f192294:	4600a287 */ 	neg.s	$f10,$f20
/*  f192298:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f19229c:	460ea102 */ 	mul.s	$f4,$f20,$f14
/*  f1922a0:	44806000 */ 	mtc1	$zero,$f12
/*  f1922a4:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f1922a8:	4600b182 */ 	mul.s	$f6,$f22,$f0
/*  f1922ac:	3c017f1c */ 	lui	$at,%hi(var7f1b8f30)
/*  f1922b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1922b4:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f1922b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1922bc:	460eb482 */ 	mul.s	$f18,$f22,$f14
/*  f1922c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1922c4:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f1922c8:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f1922cc:	44868000 */ 	mtc1	$a2,$f16
/*  f1922d0:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f1922d4:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*  f1922d8:	e4ac0004 */ 	swc1	$f12,0x4($a1)
/*  f1922dc:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f1922e0:	c4268f30 */ 	lwc1	$f6,%lo(var7f1b8f30)($at)
/*  f1922e4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1922e8:	3c017f1c */ 	lui	$at,%hi(var7f1b8f34)
/*  f1922ec:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f1922f0:	18c00038 */ 	blez	$a2,.L0f1923d4
/*  f1922f4:	46125083 */ 	div.s	$f2,$f10,$f18
/*  f1922f8:	c4208f34 */ 	lwc1	$f0,%lo(var7f1b8f34)($at)
/*  f1922fc:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f192300:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f192304:	c7b60030 */ 	lwc1	$f22,0x30($sp)
/*  f192308:	c44e00b4 */ 	lwc1	$f14,0xb4($v0)
/*  f19230c:	460e0502 */ 	mul.s	$f20,$f0,$f14
/*  f192310:	5066001d */ 	beql	$v1,$a2,.L0f192388
/*  f192314:	4614b480 */ 	add.s	$f18,$f22,$f20
/*  f192318:	4614b480 */ 	add.s	$f18,$f22,$f20
.L0f19231c:
/*  f19231c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f192320:	e45200b4 */ 	swc1	$f18,0xb4($v0)
/*  f192324:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f192328:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f19232c:	c45000b8 */ 	lwc1	$f16,0xb8($v0)
/*  f192330:	46100402 */ 	mul.s	$f16,$f0,$f16
/*  f192334:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f192338:	e45000b8 */ 	swc1	$f16,0xb8($v0)
/*  f19233c:	8e0f02d4 */ 	lw	$t7,0x2d4($s0)
/*  f192340:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*  f192344:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f192348:	c5ee00b4 */ 	lwc1	$f14,0xb4($t7)
/*  f19234c:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f192350:	460e8380 */ 	add.s	$f14,$f16,$f14
/*  f192354:	e4ae0000 */ 	swc1	$f14,0x0($a1)
/*  f192358:	8e1802d4 */ 	lw	$t8,0x2d4($s0)
/*  f19235c:	c70e00b8 */ 	lwc1	$f14,0xb8($t8)
/*  f192360:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f192364:	460e9380 */ 	add.s	$f14,$f18,$f14
/*  f192368:	e4ae0004 */ 	swc1	$f14,0x4($a1)
/*  f19236c:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f192370:	c7b60030 */ 	lwc1	$f22,0x30($sp)
/*  f192374:	c44e00b4 */ 	lwc1	$f14,0xb4($v0)
/*  f192378:	460e0502 */ 	mul.s	$f20,$f0,$f14
/*  f19237c:	5466ffe7 */ 	bnel	$v1,$a2,.L0f19231c
/*  f192380:	4614b480 */ 	add.s	$f18,$f22,$f20
/*  f192384:	4614b480 */ 	add.s	$f18,$f22,$f20
.L0f192388:
/*  f192388:	e45200b4 */ 	swc1	$f18,0xb4($v0)
/*  f19238c:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f192390:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f192394:	c45000b8 */ 	lwc1	$f16,0xb8($v0)
/*  f192398:	46100402 */ 	mul.s	$f16,$f0,$f16
/*  f19239c:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f1923a0:	e45000b8 */ 	swc1	$f16,0xb8($v0)
/*  f1923a4:	8e0f02d4 */ 	lw	$t7,0x2d4($s0)
/*  f1923a8:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*  f1923ac:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f1923b0:	c5ee00b4 */ 	lwc1	$f14,0xb4($t7)
/*  f1923b4:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f1923b8:	460e8380 */ 	add.s	$f14,$f16,$f14
/*  f1923bc:	e4ae0000 */ 	swc1	$f14,0x0($a1)
/*  f1923c0:	8e1802d4 */ 	lw	$t8,0x2d4($s0)
/*  f1923c4:	c70e00b8 */ 	lwc1	$f14,0xb8($t8)
/*  f1923c8:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f1923cc:	460e9380 */ 	add.s	$f14,$f18,$f14
/*  f1923d0:	e4ae0004 */ 	swc1	$f14,0x4($a1)
.L0f1923d4:
/*  f1923d4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1923d8:
/*  f1923d8:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1923dc:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f1923e0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f1923e4:	03e00008 */ 	jr	$ra
/*  f1923e8:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

char *mpGetBotCommandName(s32 command)
{
	if (command < 0 || command > 13) {
		return textGet(0x58b3); // "Normal"
	}

	return textGet(g_MpBotCommands[command]);
}

void func0f192438(struct chrdata *chr, struct prop *prop)
{
	chr->unk2d4->unk79 = 1;
	chr->unk2d4->unkc0_propindex = prop - g_Vars.props;
	chr->unk2d4->unkd8 = 1;
}

void func0f192474(struct chrdata *chr, struct prop *prop)
{
	chr->unk2d4->unk79 = 0;
	chr->unk2d4->unkd4_propindex = prop - g_Vars.props;
	chr->unk2d4->unkd8 = 1;
}

void func0f1924ac(struct chrdata *chr, struct prop *prop)
{
	chr->unk2d4->unk79 = 13;
	chr->unk2d4->unkd4_propindex = prop - g_Vars.props;
	chr->unk2d4->unkd8 = 1;
}

void func0f1924e8(struct chrdata *chr, struct coord *pos, s32 *arg2, f32 arg3)
{
	chr->unk2d4->unk79 = 2;
	chr->unk2d4->unk8c.x = pos->x;
	chr->unk2d4->unk8c.y = pos->y;
	chr->unk2d4->unk8c.z = pos->z;
	func0f0657a4(arg2, &chr->unk2d4->unk7a);
	chr->unk2d4->unk98 = arg3;
	chr->unk2d4->unkd8 = 1;
}

void func0f19257c(struct chrdata *chr, struct coord *pos, s32 *arg2, f32 arg3)
{
	chr->unk2d4->unk79 = 3;
	chr->unk2d4->unk8c.x = pos->x;
	chr->unk2d4->unk8c.y = pos->y;
	chr->unk2d4->unk8c.z = pos->z;
	func0f0657a4(arg2, &chr->unk2d4->unk7a);
	chr->unk2d4->unk98 = arg3;
	chr->unk2d4->unkd8 = 1;
}

void func0f192610(struct chrdata *chr, s32 arg1)
{
	chr->unk2d4->unk79 = arg1;
	chr->unk2d4->unkd8 = 1;
}

GLOBAL_ASM(
glabel func0f192628
/*  f192628:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f19262c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f192630:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f192634:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f192638:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f19263c:	00808025 */ 	or	$s0,$a0,$zero
/*  f192640:	8dc20020 */ 	lw	$v0,0x20($t6)
/*  f192644:	28410002 */ 	slti	$at,$v0,0x2
/*  f192648:	14200047 */ 	bnez	$at,.L0f192768
/*  f19264c:	24010057 */ 	addiu	$at,$zero,0x57
/*  f192650:	50410046 */ 	beql	$v0,$at,.L0f19276c
/*  f192654:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f192658:	8c830174 */ 	lw	$v1,0x174($a0)
/*  f19265c:	00003825 */ 	or	$a3,$zero,$zero
/*  f192660:	00002825 */ 	or	$a1,$zero,$zero
/*  f192664:	10600006 */ 	beqz	$v1,.L0f192680
/*  f192668:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f19266c:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f192670:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f192674:	35f80004 */ 	ori	$t8,$t7,0x4
/*  f192678:	ac580040 */ 	sw	$t8,0x40($v0)
/*  f19267c:	ac800174 */ 	sw	$zero,0x174($a0)
.L0f192680:
/*  f192680:	8e020170 */ 	lw	$v0,0x170($s0)
/*  f192684:	10400006 */ 	beqz	$v0,.L0f1926a0
/*  f192688:	00402025 */ 	or	$a0,$v0,$zero
/*  f19268c:	0fc22ed7 */ 	jal	func0f08bb5c
/*  f192690:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f192694:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f192698:	10000010 */ 	beqz	$zero,.L0f1926dc
/*  f19269c:	ae000170 */ 	sw	$zero,0x170($s0)
.L0f1926a0:
/*  f1926a0:	8e1902d4 */ 	lw	$t9,0x2d4($s0)
/*  f1926a4:	8f240020 */ 	lw	$a0,0x20($t9)
/*  f1926a8:	0fc4a2bd */ 	jal	func0f128af4
/*  f1926ac:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f1926b0:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f1926b4:	04400009 */ 	bltz	$v0,.L0f1926dc
/*  f1926b8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1926bc:	8e0802d4 */ 	lw	$t0,0x2d4($s0)
/*  f1926c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1926c4:	3c072000 */ 	lui	$a3,0x2000
/*  f1926c8:	8d060020 */ 	lw	$a2,0x20($t0)
/*  f1926cc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1926d0:	0fc22e3a */ 	jal	func0f08b8e8
/*  f1926d4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1926d8:	00403825 */ 	or	$a3,$v0,$zero
.L0f1926dc:
/*  f1926dc:	50e00017 */ 	beqzl	$a3,.L0f19273c
/*  f1926e0:	8e1902d4 */ 	lw	$t9,0x2d4($s0)
/*  f1926e4:	8ce30004 */ 	lw	$v1,0x4($a3)
/*  f1926e8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f1926ec:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1926f0:	50600012 */ 	beqzl	$v1,.L0f19273c
/*  f1926f4:	8e1902d4 */ 	lw	$t9,0x2d4($s0)
/*  f1926f8:	0fc20a59 */ 	jal	func0f082964
/*  f1926fc:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f192700:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f192704:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f192708:	352a0001 */ 	ori	$t2,$t1,0x1
/*  f19270c:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f192710:	8c4b0040 */ 	lw	$t3,0x40($v0)
/*  f192714:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f192718:	51800008 */ 	beqzl	$t4,.L0f19273c
/*  f19271c:	8e1902d4 */ 	lw	$t9,0x2d4($s0)
/*  f192720:	8c4e0048 */ 	lw	$t6,0x48($v0)
/*  f192724:	240d00f0 */ 	addiu	$t5,$zero,0xf0
/*  f192728:	adcd00b4 */ 	sw	$t5,0xb4($t6)
/*  f19272c:	8c580048 */ 	lw	$t8,0x48($v0)
/*  f192730:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f192734:	af0f0108 */ 	sw	$t7,0x108($t8)
/*  f192738:	8e1902d4 */ 	lw	$t9,0x2d4($s0)
.L0f19273c:
/*  f19273c:	02002025 */ 	or	$a0,$s0,$zero
/*  f192740:	0fc65f65 */ 	jal	func0f197d94
/*  f192744:	8f250020 */ 	lw	$a1,0x20($t9)
/*  f192748:	8e0802d4 */ 	lw	$t0,0x2d4($s0)
/*  f19274c:	02002025 */ 	or	$a0,$s0,$zero
/*  f192750:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f192754:	ad000024 */ 	sw	$zero,0x24($t0)
/*  f192758:	8e0902d4 */ 	lw	$t1,0x2d4($s0)
/*  f19275c:	00003025 */ 	or	$a2,$zero,$zero
/*  f192760:	0fc6652c */ 	jal	func0f1994b0
/*  f192764:	ad200028 */ 	sw	$zero,0x28($t1)
.L0f192768:
/*  f192768:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19276c:
/*  f19276c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f192770:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f192774:	03e00008 */ 	jr	$ra
/*  f192778:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19277c
/*  f19277c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f192780:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f192784:	00803025 */ 	or	$a2,$a0,$zero
/*  f192788:	04a0001c */ 	bltz	$a1,.L0f1927fc
/*  f19278c:	00003825 */ 	or	$a3,$zero,$zero
/*  f192790:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f192794:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f192798:	8d0f0338 */ 	lw	$t7,0x338($t0)
/*  f19279c:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f1927a0:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f1927a4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f1927a8:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f1927ac:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f1927b0:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1927b4:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1927b8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1927bc:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f1927c0:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f1927c4:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f1927c8:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f1927cc:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f1927d0:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1927d4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f1927d8:	0062c821 */ 	addu	$t9,$v1,$v0
/*  f1927dc:	9329016c */ 	lbu	$t1,0x16c($t9)
/*  f1927e0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f1927e4:	ac690128 */ 	sw	$t1,0x128($v1)
/*  f1927e8:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f1927ec:	006a5821 */ 	addu	$t3,$v1,$t2
/*  f1927f0:	8d6c0178 */ 	lw	$t4,0x178($t3)
/*  f1927f4:	10000008 */ 	beqz	$zero,.L0f192818
/*  f1927f8:	ac6c0120 */ 	sw	$t4,0x120($v1)
.L0f1927fc:
/*  f1927fc:	8ccd02d4 */ 	lw	$t5,0x2d4($a2)
/*  f192800:	240effff */ 	addiu	$t6,$zero,-1
/*  f192804:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f192808:	ada00128 */ 	sw	$zero,0x128($t5)
/*  f19280c:	8ccf02d4 */ 	lw	$t7,0x2d4($a2)
/*  f192810:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f192814:	adee0120 */ 	sw	$t6,0x120($t7)
.L0f192818:
/*  f192818:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f19281c:	8c620120 */ 	lw	$v0,0x120($v1)
/*  f192820:	8c780124 */ 	lw	$t8,0x124($v1)
/*  f192824:	0302082a */ 	slt	$at,$t8,$v0
/*  f192828:	50200004 */ 	beqzl	$at,.L0f19283c
/*  f19282c:	84d9017e */ 	lh	$t9,0x17e($a2)
/*  f192830:	ac620124 */ 	sw	$v0,0x124($v1)
/*  f192834:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f192838:	84d9017e */ 	lh	$t9,0x17e($a2)
.L0f19283c:
/*  f19283c:	50b90013 */ 	beql	$a1,$t9,.L0f19288c
/*  f192840:	8c6d0128 */ 	lw	$t5,0x128($v1)
/*  f192844:	a4c5017e */ 	sh	$a1,0x17e($a2)
/*  f192848:	ac60011c */ 	sw	$zero,0x11c($v1)
/*  f19284c:	8cc902d4 */ 	lw	$t1,0x2d4($a2)
/*  f192850:	ad2001e8 */ 	sw	$zero,0x1e8($t1)
/*  f192854:	8cca02d4 */ 	lw	$t2,0x2d4($a2)
/*  f192858:	ad400208 */ 	sw	$zero,0x208($t2)
/*  f19285c:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f192860:	8c6b0128 */ 	lw	$t3,0x128($v1)
/*  f192864:	51600006 */ 	beqzl	$t3,.L0f192880
/*  f192868:	ac6002c8 */ 	sw	$zero,0x2c8($v1)
/*  f19286c:	10e00003 */ 	beqz	$a3,.L0f19287c
/*  f192870:	240c0078 */ 	addiu	$t4,$zero,0x78
/*  f192874:	10000002 */ 	beqz	$zero,.L0f192880
/*  f192878:	ac6c02c8 */ 	sw	$t4,0x2c8($v1)
.L0f19287c:
/*  f19287c:	ac6002c8 */ 	sw	$zero,0x2c8($v1)
.L0f192880:
/*  f192880:	1000001a */ 	beqz	$zero,.L0f1928ec
/*  f192884:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f192888:	8c6d0128 */ 	lw	$t5,0x128($v1)
.L0f19288c:
/*  f19288c:	51a0000b */ 	beqzl	$t5,.L0f1928bc
/*  f192890:	8d090034 */ 	lw	$t1,0x34($t0)
/*  f192894:	8d0e0034 */ 	lw	$t6,0x34($t0)
/*  f192898:	59c00015 */ 	blezl	$t6,.L0f1928f0
/*  f19289c:	8c6e0128 */ 	lw	$t6,0x128($v1)
/*  f1928a0:	8c6f011c */ 	lw	$t7,0x11c($v1)
/*  f1928a4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1928a8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1928ac:	ac79011c */ 	sw	$t9,0x11c($v1)
/*  f1928b0:	1000000e */ 	beqz	$zero,.L0f1928ec
/*  f1928b4:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f1928b8:	8d090034 */ 	lw	$t1,0x34($t0)
.L0f1928bc:
/*  f1928bc:	59200007 */ 	blezl	$t1,.L0f1928dc
/*  f1928c0:	8c6d011c */ 	lw	$t5,0x11c($v1)
/*  f1928c4:	8c6a011c */ 	lw	$t2,0x11c($v1)
/*  f1928c8:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f1928cc:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f1928d0:	ac6c011c */ 	sw	$t4,0x11c($v1)
/*  f1928d4:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
/*  f1928d8:	8c6d011c */ 	lw	$t5,0x11c($v1)
.L0f1928dc:
/*  f1928dc:	05a30004 */ 	bgezl	$t5,.L0f1928f0
/*  f1928e0:	8c6e0128 */ 	lw	$t6,0x128($v1)
/*  f1928e4:	ac60011c */ 	sw	$zero,0x11c($v1)
/*  f1928e8:	8cc302d4 */ 	lw	$v1,0x2d4($a2)
.L0f1928ec:
/*  f1928ec:	8c6e0128 */ 	lw	$t6,0x128($v1)
.L0f1928f0:
/*  f1928f0:	51c00012 */ 	beqzl	$t6,.L0f19293c
/*  f1928f4:	ac6002c8 */ 	sw	$zero,0x2c8($v1)
/*  f1928f8:	50e00010 */ 	beqzl	$a3,.L0f19293c
/*  f1928fc:	ac6002c8 */ 	sw	$zero,0x2c8($v1)
/*  f192900:	8cef0014 */ 	lw	$t7,0x14($a3)
/*  f192904:	24190078 */ 	addiu	$t9,$zero,0x78
/*  f192908:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f19290c:	07020004 */ 	bltzl	$t8,.L0f192920
/*  f192910:	8c6202c8 */ 	lw	$v0,0x2c8($v1)
/*  f192914:	10000009 */ 	beqz	$zero,.L0f19293c
/*  f192918:	ac7902c8 */ 	sw	$t9,0x2c8($v1)
/*  f19291c:	8c6202c8 */ 	lw	$v0,0x2c8($v1)
.L0f192920:
/*  f192920:	58400007 */ 	blezl	$v0,.L0f192940
/*  f192924:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f192928:	8d090038 */ 	lw	$t1,0x38($t0)
/*  f19292c:	00495023 */ 	subu	$t2,$v0,$t1
/*  f192930:	10000002 */ 	beqz	$zero,.L0f19293c
/*  f192934:	ac6a02c8 */ 	sw	$t2,0x2c8($v1)
/*  f192938:	ac6002c8 */ 	sw	$zero,0x2c8($v1)
.L0f19293c:
/*  f19293c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f192940:
/*  f192940:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f192944:	03e00008 */ 	jr	$ra
/*  f192948:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19294c
/*  f19294c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f192950:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f192954:	8ca3001c */ 	lw	$v1,0x1c($a1)
/*  f192958:	24010006 */ 	addiu	$at,$zero,0x6
/*  f19295c:	3c0f800a */ 	lui	$t7,0x800a
/*  f192960:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f192964:	55c10007 */ 	bnel	$t6,$at,.L0f192984
/*  f192968:	8cb80018 */ 	lw	$t8,0x18($a1)
/*  f19296c:	8defa2e4 */ 	lw	$t7,-0x5d1c($t7)
/*  f192970:	55e00004 */ 	bnezl	$t7,.L0f192984
/*  f192974:	8cb80018 */ 	lw	$t8,0x18($a1)
/*  f192978:	1000002f */ 	beqz	$zero,.L0f192a38
/*  f19297c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f192980:	8cb80018 */ 	lw	$t8,0x18($a1)
.L0f192984:
/*  f192984:	33190400 */ 	andi	$t9,$t8,0x400
/*  f192988:	53200004 */ 	beqzl	$t9,.L0f19299c
/*  f19298c:	8ca80014 */ 	lw	$t0,0x14($a1)
/*  f192990:	10000029 */ 	beqz	$zero,.L0f192a38
/*  f192994:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f192998:	8ca80014 */ 	lw	$t0,0x14($a1)
.L0f19299c:
/*  f19299c:	00001025 */ 	or	$v0,$zero,$zero
/*  f1929a0:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1929a4:	05210024 */ 	bgez	$t1,.L0f192a38
/*  f1929a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1929ac:	10800020 */ 	beqz	$a0,.L0f192a30
/*  f1929b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1929b4:	8c8a02d4 */ 	lw	$t2,0x2d4($a0)
/*  f1929b8:	1140001d */ 	beqz	$t2,.L0f192a30
/*  f1929bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1929c0:	848b017e */ 	lh	$t3,0x17e($a0)
/*  f1929c4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1929c8:	5161000e */ 	beql	$t3,$at,.L0f192a04
/*  f1929cc:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1929d0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1929d4:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f1929d8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1929dc:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f1929e0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1929e4:	8ca3001c */ 	lw	$v1,0x1c($a1)
/*  f1929e8:	54430006 */ 	bnel	$v0,$v1,.L0f192a04
/*  f1929ec:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1929f0:	8c8c02d4 */ 	lw	$t4,0x2d4($a0)
/*  f1929f4:	8d8d02c8 */ 	lw	$t5,0x2c8($t4)
/*  f1929f8:	1da0000b */ 	bgtz	$t5,.L0f192a28
/*  f1929fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192a00:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
.L0f192a04:
/*  f192a04:	24650008 */ 	addiu	$a1,$v1,0x8
/*  f192a08:	8dcf009c */ 	lw	$t7,0x9c($t6)
/*  f192a0c:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f192a10:	07210007 */ 	bgez	$t9,.L0f192a30
/*  f192a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192a18:	0fc12447 */ 	jal	func0f04911c
/*  f192a1c:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f192a20:	10400003 */ 	beqz	$v0,.L0f192a30
/*  f192a24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f192a28:
/*  f192a28:	10000003 */ 	beqz	$zero,.L0f192a38
/*  f192a2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f192a30:
/*  f192a30:	10000001 */ 	beqz	$zero,.L0f192a38
/*  f192a34:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f192a38:
/*  f192a38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f192a3c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f192a40:	03e00008 */ 	jr	$ra
/*  f192a44:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f192a48
/*  f192a48:	3c017f1c */ 	lui	$at,%hi(var7f1b8f38)
/*  f192a4c:	c4268f38 */ 	lwc1	$f6,%lo(var7f1b8f38)($at)
/*  f192a50:	c48400b8 */ 	lwc1	$f4,0xb8($a0)
/*  f192a54:	00001025 */ 	or	$v0,$zero,$zero
/*  f192a58:	4604303e */ 	c.le.s	$f6,$f4
/*  f192a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192a60:	45000002 */ 	bc1f	.L0f192a6c
/*  f192a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192a68:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f192a6c:
/*  f192a6c:	03e00008 */ 	jr	$ra
/*  f192a70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f192a74
/*  f192a74:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f192a78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f192a7c:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f192a80:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f192a84:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f192a88:	8cb80038 */ 	lw	$t8,0x38($a1)
/*  f192a8c:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*  f192a90:	8c6f01cc */ 	lw	$t7,0x1cc($v1)
/*  f192a94:	91c70048 */ 	lbu	$a3,0x48($t6)
/*  f192a98:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f192a9c:	1f200012 */ 	bgtz	$t9,.L0f192ae8
/*  f192aa0:	ac7901cc */ 	sw	$t9,0x1cc($v1)
/*  f192aa4:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f192aa8:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f192aac:	0c004b70 */ 	jal	random
/*  f192ab0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f192ab4:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f192ab8:	0c004b70 */ 	jal	random
/*  f192abc:	ac6201d0 */ 	sw	$v0,0x1d0($v1)
/*  f192ac0:	24010014 */ 	addiu	$at,$zero,0x14
/*  f192ac4:	0041001b */ 	divu	$zero,$v0,$at
/*  f192ac8:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f192acc:	00004810 */ 	mfhi	$t1
/*  f192ad0:	252a0014 */ 	addiu	$t2,$t1,0x14
/*  f192ad4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f192ad8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f192adc:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f192ae0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f192ae4:	ac6a01cc */ 	sw	$t2,0x1cc($v1)
.L0f192ae8:
/*  f192ae8:	8cab0034 */ 	lw	$t3,0x34($a1)
/*  f192aec:	59600025 */ 	blezl	$t3,.L0f192b84
/*  f192af0:	8c78011c */ 	lw	$t8,0x11c($v1)
/*  f192af4:	8c6c0128 */ 	lw	$t4,0x128($v1)
/*  f192af8:	5180000a */ 	beqzl	$t4,.L0f192b24
/*  f192afc:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f192b00:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f192b04:	c46401d4 */ 	lwc1	$f4,0x1d4($v1)
/*  f192b08:	448d3000 */ 	mtc1	$t5,$f6
/*  f192b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192b10:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f192b14:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f192b18:	10000008 */ 	beqz	$zero,.L0f192b3c
/*  f192b1c:	e46a01d4 */ 	swc1	$f10,0x1d4($v1)
/*  f192b20:	8cae0000 */ 	lw	$t6,0x0($a1)
.L0f192b24:
/*  f192b24:	c46601d4 */ 	lwc1	$f6,0x1d4($v1)
/*  f192b28:	448e2000 */ 	mtc1	$t6,$f4
/*  f192b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192b30:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f192b34:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f192b38:	e46a01d4 */ 	swc1	$f10,0x1d4($v1)
.L0f192b3c:
/*  f192b3c:	c46400ac */ 	lwc1	$f4,0xac($v1)
/*  f192b40:	c4a60044 */ 	lwc1	$f6,0x44($a1)
/*  f192b44:	00077940 */ 	sll	$t7,$a3,0x5
/*  f192b48:	3c018008 */ 	lui	$at,0x8008
/*  f192b4c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f192b50:	002f0821 */ 	addu	$at,$at,$t7
/*  f192b54:	c42a7d24 */ 	lwc1	$f10,0x7d24($at)
/*  f192b58:	44809000 */ 	mtc1	$zero,$f18
/*  f192b5c:	46085002 */ 	mul.s	$f0,$f10,$f8
/*  f192b60:	4612003c */ 	c.lt.s	$f0,$f18
/*  f192b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192b68:	45020003 */ 	bc1fl	.L0f192b78
/*  f192b6c:	c46401d4 */ 	lwc1	$f4,0x1d4($v1)
/*  f192b70:	46000007 */ 	neg.s	$f0,$f0
/*  f192b74:	c46401d4 */ 	lwc1	$f4,0x1d4($v1)
.L0f192b78:
/*  f192b78:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f192b7c:	e46601d4 */ 	swc1	$f6,0x1d4($v1)
/*  f192b80:	8c78011c */ 	lw	$t8,0x11c($v1)
.L0f192b84:
/*  f192b84:	c46c01d4 */ 	lwc1	$f12,0x1d4($v1)
/*  f192b88:	3c088008 */ 	lui	$t0,%hi(var80087d14)
/*  f192b8c:	44985000 */ 	mtc1	$t8,$f10
/*  f192b90:	44809000 */ 	mtc1	$zero,$f18
/*  f192b94:	25087d14 */ 	addiu	$t0,$t0,%lo(var80087d14)
/*  f192b98:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f192b9c:	0007c940 */ 	sll	$t9,$a3,0x5
/*  f192ba0:	03283021 */ 	addu	$a2,$t9,$t0
/*  f192ba4:	460c003c */ 	c.lt.s	$f0,$f12
/*  f192ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192bac:	45020004 */ 	bc1fl	.L0f192bc0
/*  f192bb0:	4612603c */ 	c.lt.s	$f12,$f18
/*  f192bb4:	e46001d4 */ 	swc1	$f0,0x1d4($v1)
/*  f192bb8:	c46c01d4 */ 	lwc1	$f12,0x1d4($v1)
/*  f192bbc:	4612603c */ 	c.lt.s	$f12,$f18
.L0f192bc0:
/*  f192bc0:	3c014f80 */ 	lui	$at,0x4f80
/*  f192bc4:	45020004 */ 	bc1fl	.L0f192bd8
/*  f192bc8:	94c9000c */ 	lhu	$t1,0xc($a2)
/*  f192bcc:	e47201d4 */ 	swc1	$f18,0x1d4($v1)
/*  f192bd0:	c46c01d4 */ 	lwc1	$f12,0x1d4($v1)
/*  f192bd4:	94c9000c */ 	lhu	$t1,0xc($a2)
.L0f192bd8:
/*  f192bd8:	44894000 */ 	mtc1	$t1,$f8
/*  f192bdc:	05210004 */ 	bgez	$t1,.L0f192bf0
/*  f192be0:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f192be4:	44812000 */ 	mtc1	$at,$f4
/*  f192be8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192bec:	46041080 */ 	add.s	$f2,$f2,$f4
.L0f192bf0:
/*  f192bf0:	460c103e */ 	c.le.s	$f2,$f12
/*  f192bf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192bf8:	45020006 */ 	bc1fl	.L0f192c14
/*  f192bfc:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f192c00:	e46201d4 */ 	swc1	$f2,0x1d4($v1)
/*  f192c04:	46009406 */ 	mov.s	$f16,$f18
/*  f192c08:	10000009 */ 	beqz	$zero,.L0f192c30
/*  f192c0c:	46009386 */ 	mov.s	$f14,$f18
/*  f192c10:	460c1181 */ 	sub.s	$f6,$f2,$f12
.L0f192c14:
/*  f192c14:	c4ca0004 */ 	lwc1	$f10,0x4($a2)
/*  f192c18:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f192c1c:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f192c20:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f192c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192c28:	46004382 */ 	mul.s	$f14,$f8,$f0
/*  f192c2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f192c30:
/*  f192c30:	848a017e */ 	lh	$t2,0x17e($a0)
/*  f192c34:	2401ffff */ 	addiu	$at,$zero,-1
/*  f192c38:	51410017 */ 	beql	$t2,$at,.L0f192c98
/*  f192c3c:	c4c00018 */ 	lwc1	$f0,0x18($a2)
/*  f192c40:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f192c44:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f192c48:	e7ae002c */ 	swc1	$f14,0x2c($sp)
/*  f192c4c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f192c50:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f192c54:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*  f192c58:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f192c5c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f192c60:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*  f192c64:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f192c68:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f192c6c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f192c70:	c7ae002c */ 	lwc1	$f14,0x2c($sp)
/*  f192c74:	05a10007 */ 	bgez	$t5,.L0f192c94
/*  f192c78:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f192c7c:	c4c00014 */ 	lwc1	$f0,0x14($a2)
/*  f192c80:	4600703c */ 	c.lt.s	$f14,$f0
/*  f192c84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192c88:	45020003 */ 	bc1fl	.L0f192c98
/*  f192c8c:	c4c00018 */ 	lwc1	$f0,0x18($a2)
/*  f192c90:	46000386 */ 	mov.s	$f14,$f0
.L0f192c94:
/*  f192c94:	c4c00018 */ 	lwc1	$f0,0x18($a2)
.L0f192c98:
/*  f192c98:	3c014f80 */ 	lui	$at,0x4f80
/*  f192c9c:	4600703c */ 	c.lt.s	$f14,$f0
/*  f192ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192ca4:	45020003 */ 	bc1fl	.L0f192cb4
/*  f192ca8:	8c6201d0 */ 	lw	$v0,0x1d0($v1)
/*  f192cac:	46000386 */ 	mov.s	$f14,$f0
/*  f192cb0:	8c6201d0 */ 	lw	$v0,0x1d0($v1)
.L0f192cb4:
/*  f192cb4:	46107101 */ 	sub.s	$f4,$f14,$f16
/*  f192cb8:	304effff */ 	andi	$t6,$v0,0xffff
/*  f192cbc:	448e3000 */ 	mtc1	$t6,$f6
/*  f192cc0:	05c10004 */ 	bgez	$t6,.L0f192cd4
/*  f192cc4:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f192cc8:	44814000 */ 	mtc1	$at,$f8
/*  f192ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192cd0:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f192cd4:
/*  f192cd4:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f192cd8:	3c017f1c */ 	lui	$at,%hi(var7f1b8f3c)
/*  f192cdc:	c4288f3c */ 	lwc1	$f8,%lo(var7f1b8f3c)($at)
/*  f192ce0:	00027bc0 */ 	sll	$t7,$v0,0xf
/*  f192ce4:	3c017f1c */ 	lui	$at,%hi(var7f1b8f40)
/*  f192ce8:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f192cec:	46102280 */ 	add.s	$f10,$f4,$f16
/*  f192cf0:	05e10004 */ 	bgez	$t7,.L0f192d04
/*  f192cf4:	e46a01c8 */ 	swc1	$f10,0x1c8($v1)
/*  f192cf8:	c46601c8 */ 	lwc1	$f6,0x1c8($v1)
/*  f192cfc:	46003207 */ 	neg.s	$f8,$f6
/*  f192d00:	e46801c8 */ 	swc1	$f8,0x1c8($v1)
.L0f192d04:
/*  f192d04:	8cb80034 */ 	lw	$t8,0x34($a1)
/*  f192d08:	00001025 */ 	or	$v0,$zero,$zero
/*  f192d0c:	1b00000c */ 	blez	$t8,.L0f192d40
/*  f192d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192d14:	c46201c8 */ 	lwc1	$f2,0x1c8($v1)
/*  f192d18:	c4208f40 */ 	lwc1	$f0,%lo(var7f1b8f40)($at)
/*  f192d1c:	c46401c4 */ 	lwc1	$f4,0x1c4($v1)
.L0f192d20:
/*  f192d20:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f192d24:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f192d28:	46025180 */ 	add.s	$f6,$f10,$f2
/*  f192d2c:	e46601c4 */ 	swc1	$f6,0x1c4($v1)
/*  f192d30:	8cb90034 */ 	lw	$t9,0x34($a1)
/*  f192d34:	0059082a */ 	slt	$at,$v0,$t9
/*  f192d38:	5420fff9 */ 	bnezl	$at,.L0f192d20
/*  f192d3c:	c46401c4 */ 	lwc1	$f4,0x1c4($v1)
.L0f192d40:
/*  f192d40:	3c017f1c */ 	lui	$at,%hi(var7f1b8f44)
/*  f192d44:	c4248f44 */ 	lwc1	$f4,%lo(var7f1b8f44)($at)
/*  f192d48:	c46801c4 */ 	lwc1	$f8,0x1c4($v1)
/*  f192d4c:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f192d50:	e46a01c0 */ 	swc1	$f10,0x1c0($v1)
/*  f192d54:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f192d58:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f192d5c:	03e00008 */ 	jr	$ra
/*  f192d60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f192d64
/*  f192d64:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f192d68:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f192d6c:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f192d70:	24010001 */ 	addiu	$at,$zero,0x1
/*  f192d74:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f192d78:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f192d7c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f192d80:	91cf0047 */ 	lbu	$t7,0x47($t6)
/*  f192d84:	55e1000a */ 	bnel	$t7,$at,.L0f192db0
/*  f192d88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f192d8c:	0fc6456d */ 	jal	func0f1915b4
/*  f192d90:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f192d94:	10400004 */ 	beqz	$v0,.L0f192da8
/*  f192d98:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f192d9c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f192da0:	54410003 */ 	bnel	$v0,$at,.L0f192db0
/*  f192da4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f192da8:
/*  f192da8:	00001825 */ 	or	$v1,$zero,$zero
/*  f192dac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f192db0:
/*  f192db0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f192db4:	00601025 */ 	or	$v0,$v1,$zero
/*  f192db8:	03e00008 */ 	jr	$ra
/*  f192dbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f192dc0
/*  f192dc0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f192dc4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f192dc8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f192dcc:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f192dd0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f192dd4:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f192dd8:	8c780004 */ 	lw	$t8,0x4($v1)
/*  f192ddc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f192de0:	00a02025 */ 	or	$a0,$a1,$zero
/*  f192de4:	93190047 */ 	lbu	$t9,0x47($t8)
/*  f192de8:	57210025 */ 	bnel	$t9,$at,.L0f192e80
/*  f192dec:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f192df0:	0fc6456d */ 	jal	func0f1915b4
/*  f192df4:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f192df8:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f192dfc:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f192e00:	27a80040 */ 	addiu	$t0,$sp,0x40
/*  f192e04:	8c650020 */ 	lw	$a1,0x20($v1)
/*  f192e08:	27a9003c */ 	addiu	$t1,$sp,0x3c
/*  f192e0c:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f192e10:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f192e14:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f192e18:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f192e1c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f192e20:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f192e24:	00003025 */ 	or	$a2,$zero,$zero
/*  f192e28:	0fc660ce */ 	jal	func0f198338
/*  f192e2c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f192e30:	27aa0038 */ 	addiu	$t2,$sp,0x38
/*  f192e34:	27ab0034 */ 	addiu	$t3,$sp,0x34
/*  f192e38:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f192e3c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f192e40:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f192e44:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f192e48:	00003025 */ 	or	$a2,$zero,$zero
/*  f192e4c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f192e50:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f192e54:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f192e58:	0fc660ce */ 	jal	func0f198338
/*  f192e5c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f192e60:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f192e64:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f192e68:	25aeffe2 */ 	addiu	$t6,$t5,-30
/*  f192e6c:	018e082a */ 	slt	$at,$t4,$t6
/*  f192e70:	54200003 */ 	bnezl	$at,.L0f192e80
/*  f192e74:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f192e78:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f192e7c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f192e80:
/*  f192e80:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f192e84:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f192e88:	03e00008 */ 	jr	$ra
/*  f192e8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f192e90
/*  f192e90:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f192e94:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f192e98:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f192e9c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f192ea0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f192ea4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f192ea8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f192eac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f192eb0:	8c9302d4 */ 	lw	$s3,0x2d4($a0)
/*  f192eb4:	240effff */ 	addiu	$t6,$zero,-1
/*  f192eb8:	a7ae006a */ 	sh	$t6,0x6a($sp)
/*  f192ebc:	8e6f012c */ 	lw	$t7,0x12c($s3)
/*  f192ec0:	3c19800b */ 	lui	$t9,0x800b
/*  f192ec4:	8f39c530 */ 	lw	$t9,-0x3ad0($t9)
/*  f192ec8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f192ecc:	0080a825 */ 	or	$s5,$a0,$zero
/*  f192ed0:	0319001a */ 	div	$zero,$t8,$t9
/*  f192ed4:	00002010 */ 	mfhi	$a0
/*  f192ed8:	ae64012c */ 	sw	$a0,0x12c($s3)
/*  f192edc:	17200002 */ 	bnez	$t9,.L0f192ee8
/*  f192ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192ee4:	0007000d */ 	break	0x7
.L0f192ee8:
/*  f192ee8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f192eec:	17210004 */ 	bne	$t9,$at,.L0f192f00
/*  f192ef0:	3c018000 */ 	lui	$at,0x8000
/*  f192ef4:	17010002 */ 	bne	$t8,$at,.L0f192f00
/*  f192ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192efc:	0006000d */ 	break	0x6
.L0f192f00:
/*  f192f00:	0fc63410 */ 	jal	func0f18d040
/*  f192f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192f08:	1055002b */ 	beq	$v0,$s5,.L0f192fb8
/*  f192f0c:	00408825 */ 	or	$s1,$v0,$zero
/*  f192f10:	0c004b70 */ 	jal	random
/*  f192f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192f18:	24013840 */ 	addiu	$at,$zero,0x3840
/*  f192f1c:	0041001b */ 	divu	$zero,$v0,$at
/*  f192f20:	3c0d800b */ 	lui	$t5,0x800b
/*  f192f24:	3c0e800a */ 	lui	$t6,0x800a
/*  f192f28:	8dce9ff8 */ 	lw	$t6,-0x6008($t6)
/*  f192f2c:	8dadc530 */ 	lw	$t5,-0x3ad0($t5)
/*  f192f30:	00006010 */ 	mfhi	$t4
/*  f192f34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f192f3c:	01ae0019 */ 	multu	$t5,$t6
/*  f192f40:	00007812 */ 	mflo	$t7
/*  f192f44:	018f082b */ 	sltu	$at,$t4,$t7
/*  f192f48:	50200005 */ 	beqzl	$at,.L0f192f60
/*  f192f4c:	8e25001c */ 	lw	$a1,0x1c($s1)
/*  f192f50:	9279009c */ 	lbu	$t9,0x9c($s3)
/*  f192f54:	372b0010 */ 	ori	$t3,$t9,0x10
/*  f192f58:	a26b009c */ 	sb	$t3,0x9c($s3)
/*  f192f5c:	8e25001c */ 	lw	$a1,0x1c($s1)
.L0f192f60:
/*  f192f60:	02a02025 */ 	or	$a0,$s5,$zero
/*  f192f64:	0fc1250e */ 	jal	chrGetDistanceToCoord
/*  f192f68:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f192f6c:	8e6d012c */ 	lw	$t5,0x12c($s3)
/*  f192f70:	02a02025 */ 	or	$a0,$s5,$zero
/*  f192f74:	02202825 */ 	or	$a1,$s1,$zero
/*  f192f78:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f192f7c:	026e6021 */ 	addu	$t4,$s3,$t6
/*  f192f80:	e580013c */ 	swc1	$f0,0x13c($t4)
/*  f192f84:	0fc0e48b */ 	jal	func0f03922c
/*  f192f88:	27a6006a */ 	addiu	$a2,$sp,0x6a
/*  f192f8c:	8e6f012c */ 	lw	$t7,0x12c($s3)
/*  f192f90:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f192f94:	a302016c */ 	sb	$v0,0x16c($t8)
/*  f192f98:	8e6b012c */ 	lw	$t3,0x12c($s3)
/*  f192f9c:	87b9006a */ 	lh	$t9,0x6a($sp)
/*  f192fa0:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f192fa4:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f192fa8:	a5d901a8 */ 	sh	$t9,0x1a8($t6)
/*  f192fac:	926c009c */ 	lbu	$t4,0x9c($s3)
/*  f192fb0:	318fffef */ 	andi	$t7,$t4,0xffef
/*  f192fb4:	a26f009c */ 	sb	$t7,0x9c($s3)
.L0f192fb8:
/*  f192fb8:	3c07800b */ 	lui	$a3,0x800b
/*  f192fbc:	8ce7c530 */ 	lw	$a3,-0x3ad0($a3)
/*  f192fc0:	00009025 */ 	or	$s2,$zero,$zero
/*  f192fc4:	02608025 */ 	or	$s0,$s3,$zero
/*  f192fc8:	18e00010 */ 	blez	$a3,.L0f19300c
/*  f192fcc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f192fd0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L0f192fd4:
/*  f192fd4:	9218016c */ 	lbu	$t8,0x16c($s0)
/*  f192fd8:	00126880 */ 	sll	$t5,$s2,0x2
/*  f192fdc:	53000007 */ 	beqzl	$t8,.L0f192ffc
/*  f192fe0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f192fe4:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*  f192fe8:	026dc821 */ 	addu	$t9,$s3,$t5
/*  f192fec:	3c07800b */ 	lui	$a3,0x800b
/*  f192ff0:	af2b0178 */ 	sw	$t3,0x178($t9)
/*  f192ff4:	8ce7c530 */ 	lw	$a3,-0x3ad0($a3)
/*  f192ff8:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f192ffc:
/*  f192ffc:	0247082a */ 	slt	$at,$s2,$a3
/*  f193000:	1420fff4 */ 	bnez	$at,.L0f192fd4
/*  f193004:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f193008:	00009025 */ 	or	$s2,$zero,$zero
.L0f19300c:
/*  f19300c:	18e00008 */ 	blez	$a3,.L0f193030
/*  f193010:	27a2006c */ 	addiu	$v0,$sp,0x6c
/*  f193014:	00076080 */ 	sll	$t4,$a3,0x2
/*  f193018:	01821821 */ 	addu	$v1,$t4,$v0
.L0f19301c:
/*  f19301c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f193020:	0043082b */ 	sltu	$at,$v0,$v1
/*  f193024:	1420fffd */ 	bnez	$at,.L0f19301c
/*  f193028:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f19302c:	00009025 */ 	or	$s2,$zero,$zero
.L0f193030:
/*  f193030:	18e00026 */ 	blez	$a3,.L0f1930cc
/*  f193034:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f193038:	44801000 */ 	mtc1	$zero,$f2
/*  f19303c:	27a8006c */ 	addiu	$t0,$sp,0x6c
/*  f193040:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f193044:
/*  f193044:	46001006 */ 	mov.s	$f0,$f2
/*  f193048:	18e00014 */ 	blez	$a3,.L0f19309c
/*  f19304c:	00001825 */ 	or	$v1,$zero,$zero
/*  f193050:	00002025 */ 	or	$a0,$zero,$zero
/*  f193054:	27a5006c */ 	addiu	$a1,$sp,0x6c
.L0f193058:
/*  f193058:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f19305c:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f193060:	55e0000b */ 	bnezl	$t7,.L0f193090
/*  f193064:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f193068:	04c00006 */ 	bltz	$a2,.L0f193084
/*  f19306c:	02641021 */ 	addu	$v0,$s3,$a0
/*  f193070:	c444013c */ 	lwc1	$f4,0x13c($v0)
/*  f193074:	4600203c */ 	c.lt.s	$f4,$f0
/*  f193078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19307c:	45020004 */ 	bc1fl	.L0f193090
/*  f193080:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f193084:
/*  f193084:	00603025 */ 	or	$a2,$v1,$zero
/*  f193088:	c440013c */ 	lwc1	$f0,0x13c($v0)
/*  f19308c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f193090:
/*  f193090:	0067082a */ 	slt	$at,$v1,$a3
/*  f193094:	1420fff0 */ 	bnez	$at,.L0f193058
/*  f193098:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f19309c:
/*  f19309c:	04c00007 */ 	bltz	$a2,.L0f1930bc
/*  f1930a0:	0272c021 */ 	addu	$t8,$s3,$s2
/*  f1930a4:	00066880 */ 	sll	$t5,$a2,0x2
/*  f1930a8:	a3060130 */ 	sb	$a2,0x130($t8)
/*  f1930ac:	010d5821 */ 	addu	$t3,$t0,$t5
/*  f1930b0:	ad690000 */ 	sw	$t1,0x0($t3)
/*  f1930b4:	3c07800b */ 	lui	$a3,0x800b
/*  f1930b8:	8ce7c530 */ 	lw	$a3,-0x3ad0($a3)
.L0f1930bc:
/*  f1930bc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1930c0:	0247082a */ 	slt	$at,$s2,$a3
/*  f1930c4:	5420ffdf */ 	bnezl	$at,.L0f193044
/*  f1930c8:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f1930cc:
/*  f1930cc:	0fc64a9d */ 	jal	func0f192a74
/*  f1930d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1930d4:	92a202a0 */ 	lbu	$v0,0x2a0($s5)
/*  f1930d8:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1930dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1930e0:	54410006 */ 	bnel	$v0,$at,.L0f1930fc
/*  f1930e4:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1930e8:	0fc649df */ 	jal	func0f19277c
/*  f1930ec:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1930f0:	100000f2 */ 	beqz	$zero,.L0f1934bc
/*  f1930f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1930f8:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f1930fc:
/*  f1930fc:	5441001f */ 	bnel	$v0,$at,.L0f19317c
/*  f193100:	86b8017e */ 	lh	$t8,0x17e($s5)
/*  f193104:	86620008 */ 	lh	$v0,0x8($s3)
/*  f193108:	0440001b */ 	bltz	$v0,.L0f193178
/*  f19310c:	0262c821 */ 	addu	$t9,$s3,$v0
/*  f193110:	932c016c */ 	lbu	$t4,0x16c($t9)
/*  f193114:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f193118:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f19311c:	11800016 */ 	beqz	$t4,.L0f193178
/*  f193120:	00027080 */ 	sll	$t6,$v0,0x2
/*  f193124:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f193128:	0fc0e6a5 */ 	jal	chrIsDead
/*  f19312c:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f193130:	54400012 */ 	bnezl	$v0,.L0f19317c
/*  f193134:	86b8017e */ 	lh	$t8,0x17e($s5)
/*  f193138:	86780008 */ 	lh	$t8,0x8($s3)
/*  f19313c:	3c0e800a */ 	lui	$t6,0x800a
/*  f193140:	8dcea2f8 */ 	lw	$t6,-0x5d08($t6)
/*  f193144:	00186880 */ 	sll	$t5,$t8,0x2
/*  f193148:	020d5821 */ 	addu	$t3,$s0,$t5
/*  f19314c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f193150:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193154:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193158:	8f2c001c */ 	lw	$t4,0x1c($t9)
/*  f19315c:	018e2823 */ 	subu	$a1,$t4,$t6
/*  f193160:	00a1001a */ 	div	$zero,$a1,$at
/*  f193164:	00002812 */ 	mflo	$a1
/*  f193168:	0fc649df */ 	jal	func0f19277c
/*  f19316c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193170:	100000d2 */ 	beqz	$zero,.L0f1934bc
/*  f193174:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193178:
/*  f193178:	86b8017e */ 	lh	$t8,0x17e($s5)
.L0f19317c:
/*  f19317c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f193180:	52380028 */ 	beql	$s1,$t8,.L0f193224
/*  f193184:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f193188:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19318c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193190:	00408025 */ 	or	$s0,$v0,$zero
/*  f193194:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193198:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19319c:	10400002 */ 	beqz	$v0,.L0f1931a8
/*  f1931a0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931a4:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931a8:
/*  f1931a8:	8ead02d4 */ 	lw	$t5,0x2d4($s5)
/*  f1931ac:	8dab0128 */ 	lw	$t3,0x128($t5)
/*  f1931b0:	55600007 */ 	bnezl	$t3,.L0f1931d0
/*  f1931b4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931b8:	0fc64a53 */ 	jal	func0f19294c
/*  f1931bc:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931c0:	50400003 */ 	beqzl	$v0,.L0f1931d0
/*  f1931c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931c8:	a6b1017e */ 	sh	$s1,0x17e($s5)
/*  f1931cc:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1931d0:
/*  f1931d0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931d4:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f1931d8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1931dc:	10400002 */ 	beqz	$v0,.L0f1931e8
/*  f1931e0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931e4:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931e8:
/*  f1931e8:	0fc64b59 */ 	jal	func0f192d64
/*  f1931ec:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931f0:	14400002 */ 	bnez	$v0,.L0f1931fc
/*  f1931f4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931f8:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931fc:
/*  f1931fc:	8eb902d4 */ 	lw	$t9,0x2d4($s5)
/*  f193200:	8f2c0128 */ 	lw	$t4,0x128($t9)
/*  f193204:	55800007 */ 	bnezl	$t4,.L0f193224
/*  f193208:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f19320c:	0fc64b70 */ 	jal	func0f192dc0
/*  f193210:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f193214:	54400003 */ 	bnezl	$v0,.L0f193224
/*  f193218:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f19321c:	a6b1017e */ 	sh	$s1,0x17e($s5)
/*  f193220:	86a2017e */ 	lh	$v0,0x17e($s5)
.L0f193224:
/*  f193224:	3c0f800b */ 	lui	$t7,0x800b
/*  f193228:	3c0b800a */ 	lui	$t3,0x800a
/*  f19322c:	16220062 */ 	bne	$s1,$v0,.L0f1933b8
/*  f193230:	000268c0 */ 	sll	$t5,$v0,0x3
/*  f193234:	8defc530 */ 	lw	$t7,-0x3ad0($t7)
/*  f193238:	240effff */ 	addiu	$t6,$zero,-1
/*  f19323c:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f193240:	19e00047 */ 	blez	$t7,.L0f193360
/*  f193244:	00009025 */ 	or	$s2,$zero,$zero
/*  f193248:	0260a025 */ 	or	$s4,$s3,$zero
/*  f19324c:	82900130 */ 	lb	$s0,0x130($s4)
.L0f193250:
/*  f193250:	0fc63410 */ 	jal	func0f18d040
/*  f193254:	02002025 */ 	or	$a0,$s0,$zero
/*  f193258:	1055003a */ 	beq	$v0,$s5,.L0f193344
/*  f19325c:	00408825 */ 	or	$s1,$v0,$zero
/*  f193260:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193264:	00402025 */ 	or	$a0,$v0,$zero
/*  f193268:	14400036 */ 	bnez	$v0,.L0f193344
/*  f19326c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193270:	02202825 */ 	or	$a1,$s1,$zero
/*  f193274:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f193278:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19327c:	10400031 */ 	beqz	$v0,.L0f193344
/*  f193280:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193284:	0fc64b59 */ 	jal	func0f192d64
/*  f193288:	02202825 */ 	or	$a1,$s1,$zero
/*  f19328c:	1040002d */ 	beqz	$v0,.L0f193344
/*  f193290:	0270c021 */ 	addu	$t8,$s3,$s0
/*  f193294:	930d016c */ 	lbu	$t5,0x16c($t8)
/*  f193298:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19329c:	11a0000c */ 	beqz	$t5,.L0f1932d0
/*  f1932a0:	3c19800a */ 	lui	$t9,0x800a
/*  f1932a4:	8f39a2f8 */ 	lw	$t9,-0x5d08($t9)
/*  f1932a8:	8e2b001c */ 	lw	$t3,0x1c($s1)
/*  f1932ac:	24010048 */ 	addiu	$at,$zero,0x48
/*  f1932b0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1932b4:	01792823 */ 	subu	$a1,$t3,$t9
/*  f1932b8:	00a1001a */ 	div	$zero,$a1,$at
/*  f1932bc:	00002812 */ 	mflo	$a1
/*  f1932c0:	0fc649df */ 	jal	func0f19277c
/*  f1932c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1932c8:	1000007c */ 	beqz	$zero,.L0f1934bc
/*  f1932cc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1932d0:
/*  f1932d0:	0fc64a53 */ 	jal	func0f19294c
/*  f1932d4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1932d8:	14400013 */ 	bnez	$v0,.L0f193328
/*  f1932dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1932e0:	8e6e0004 */ 	lw	$t6,0x4($s3)
/*  f1932e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1932e8:	91c20048 */ 	lbu	$v0,0x48($t6)
/*  f1932ec:	10400002 */ 	beqz	$v0,.L0f1932f8
/*  f1932f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1932f4:	1441000c */ 	bne	$v0,$at,.L0f193328
.L0f1932f8:
/*  f1932f8:	3c18800a */ 	lui	$t8,0x800a
/*  f1932fc:	8f18a2f8 */ 	lw	$t8,-0x5d08($t8)
/*  f193300:	8e2f001c */ 	lw	$t7,0x1c($s1)
/*  f193304:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193308:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19330c:	01f82823 */ 	subu	$a1,$t7,$t8
/*  f193310:	00a1001a */ 	div	$zero,$a1,$at
/*  f193314:	00002812 */ 	mflo	$a1
/*  f193318:	0fc649df */ 	jal	func0f19277c
/*  f19331c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193320:	10000066 */ 	beqz	$zero,.L0f1934bc
/*  f193324:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193328:
/*  f193328:	0fc64a53 */ 	jal	func0f19294c
/*  f19332c:	02202825 */ 	or	$a1,$s1,$zero
/*  f193330:	14400004 */ 	bnez	$v0,.L0f193344
/*  f193334:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f193338:	05610002 */ 	bgez	$t3,.L0f193344
/*  f19333c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193340:	afb00050 */ 	sw	$s0,0x50($sp)
.L0f193344:
/*  f193344:	3c19800b */ 	lui	$t9,0x800b
/*  f193348:	8f39c530 */ 	lw	$t9,-0x3ad0($t9)
/*  f19334c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f193350:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193354:	0259082a */ 	slt	$at,$s2,$t9
/*  f193358:	5420ffbd */ 	bnezl	$at,.L0f193250
/*  f19335c:	82900130 */ 	lb	$s0,0x130($s4)
.L0f193360:
/*  f193360:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f193364:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193368:	0580000f */ 	bltz	$t4,.L0f1933a8
/*  f19336c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193370:	0fc63410 */ 	jal	func0f18d040
/*  f193374:	01802025 */ 	or	$a0,$t4,$zero
/*  f193378:	3c0f800a */ 	lui	$t7,0x800a
/*  f19337c:	8defa2f8 */ 	lw	$t7,-0x5d08($t7)
/*  f193380:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f193384:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193388:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19338c:	01cf2823 */ 	subu	$a1,$t6,$t7
/*  f193390:	00a1001a */ 	div	$zero,$a1,$at
/*  f193394:	00002812 */ 	mflo	$a1
/*  f193398:	0fc649df */ 	jal	func0f19277c
/*  f19339c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1933a0:	10000046 */ 	beqz	$zero,.L0f1934bc
/*  f1933a4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933a8:
/*  f1933a8:	0fc649df */ 	jal	func0f19277c
/*  f1933ac:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1933b0:	10000042 */ 	beqz	$zero,.L0f1934bc
/*  f1933b4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933b8:
/*  f1933b8:	8d6ba2f8 */ 	lw	$t3,-0x5d08($t3)
/*  f1933bc:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f1933c0:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f1933c4:	01abc821 */ 	addu	$t9,$t5,$t3
/*  f1933c8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1933cc:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f1933d0:	02626021 */ 	addu	$t4,$s3,$v0
/*  f1933d4:	918e016c */ 	lbu	$t6,0x16c($t4)
/*  f1933d8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1933dc:	3c0f800b */ 	lui	$t7,0x800b
/*  f1933e0:	11c00005 */ 	beqz	$t6,.L0f1933f8
/*  f1933e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1933e8:	0fc649df */ 	jal	func0f19277c
/*  f1933ec:	86a5017e */ 	lh	$a1,0x17e($s5)
/*  f1933f0:	10000032 */ 	beqz	$zero,.L0f1934bc
/*  f1933f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933f8:
/*  f1933f8:	8defc530 */ 	lw	$t7,-0x3ad0($t7)
/*  f1933fc:	00009025 */ 	or	$s2,$zero,$zero
/*  f193400:	02608025 */ 	or	$s0,$s3,$zero
/*  f193404:	59e0002a */ 	blezl	$t7,.L0f1934b0
/*  f193408:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19340c:	82040130 */ 	lb	$a0,0x130($s0)
.L0f193410:
/*  f193410:	0264c021 */ 	addu	$t8,$s3,$a0
/*  f193414:	930d016c */ 	lbu	$t5,0x16c($t8)
/*  f193418:	11a0001d */ 	beqz	$t5,.L0f193490
/*  f19341c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193420:	0fc63410 */ 	jal	func0f18d040
/*  f193424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193428:	10550019 */ 	beq	$v0,$s5,.L0f193490
/*  f19342c:	00408825 */ 	or	$s1,$v0,$zero
/*  f193430:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193434:	00402025 */ 	or	$a0,$v0,$zero
/*  f193438:	14400015 */ 	bnez	$v0,.L0f193490
/*  f19343c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193440:	02202825 */ 	or	$a1,$s1,$zero
/*  f193444:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f193448:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19344c:	10400010 */ 	beqz	$v0,.L0f193490
/*  f193450:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193454:	0fc64b59 */ 	jal	func0f192d64
/*  f193458:	02202825 */ 	or	$a1,$s1,$zero
/*  f19345c:	1040000c */ 	beqz	$v0,.L0f193490
/*  f193460:	3c19800a */ 	lui	$t9,0x800a
/*  f193464:	8f39a2f8 */ 	lw	$t9,-0x5d08($t9)
/*  f193468:	8e2b001c */ 	lw	$t3,0x1c($s1)
/*  f19346c:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193470:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193474:	01792823 */ 	subu	$a1,$t3,$t9
/*  f193478:	00a1001a */ 	div	$zero,$a1,$at
/*  f19347c:	00002812 */ 	mflo	$a1
/*  f193480:	0fc649df */ 	jal	func0f19277c
/*  f193484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193488:	1000000c */ 	beqz	$zero,.L0f1934bc
/*  f19348c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193490:
/*  f193490:	3c0e800b */ 	lui	$t6,0x800b
/*  f193494:	8dcec530 */ 	lw	$t6,-0x3ad0($t6)
/*  f193498:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19349c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1934a0:	024e082a */ 	slt	$at,$s2,$t6
/*  f1934a4:	5420ffda */ 	bnezl	$at,.L0f193410
/*  f1934a8:	82040130 */ 	lb	$a0,0x130($s0)
/*  f1934ac:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1934b0:
/*  f1934b0:	0fc649df */ 	jal	func0f19277c
/*  f1934b4:	86a5017e */ 	lh	$a1,0x17e($s5)
/*  f1934b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1934bc:
/*  f1934bc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1934c0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1934c4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1934c8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1934cc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f1934d0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f1934d4:	03e00008 */ 	jr	$ra
/*  f1934d8:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

bool mpIsChrFollowedByChr(struct chrdata *leader, struct chrdata *follower)
{
	bool result = true;

	while (true) {
		struct chr2d4 *chr2d4 = follower->unk2d4;

		if (!chr2d4 || follower->myaction != MA_AIBOTFOLLOW || chr2d4->followingplayernum < 0) {
			break;
		}

		follower = g_MpPlayerChrs[chr2d4->followingplayernum];

		if (follower == leader) {
			result = false;
			break;
		}
	}

	return result;
}

s32 func0f193530(struct chrdata *chr, f32 arg1)
{
	s32 result = -1;

	if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
		if (chr->myaction != MA_AIBOTFOLLOW && (random() % 100) < chr->unk2d4->unk00) {
			f32 bestvalue = 0;
			s32 bestindex = -1;
			s32 i;

			for (i = 0; i < g_MpNumPlayers; i++) {
				if (chr != g_MpPlayerChrs[i] &&
						!chrIsDead(g_MpPlayerChrs[i]) &&
						chr->team == g_MpPlayerChrs[i]->team &&
						mpIsChrFollowedByChr(chr, g_MpPlayerChrs[i])) {
					f32 value = chr->unk2d4->unk13c[i];

					if (bestindex < 0 || value < bestvalue) {
						bestindex = i;
						bestvalue = value;
					}
				}
			}

			if (bestindex >= 0 && bestvalue < arg1) {
				result = bestindex;
			}
		}
	}

	return result;
}

GLOBAL_ASM(
glabel func0f19369c
/*  f19369c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1936a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1936a4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1936a8:	8c8602d4 */ 	lw	$a2,0x2d4($a0)
/*  f1936ac:	3c028008 */ 	lui	$v0,%hi(var80087eb0)
/*  f1936b0:	24427eb0 */ 	addiu	$v0,$v0,%lo(var80087eb0)
/*  f1936b4:	8ccf0020 */ 	lw	$t7,0x20($a2)
/*  f1936b8:	00054040 */ 	sll	$t0,$a1,0x1
/*  f1936bc:	00c86021 */ 	addu	$t4,$a2,$t0
/*  f1936c0:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f1936c4:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f1936c8:	9729000e */ 	lhu	$t1,0xe($t9)
/*  f1936cc:	00803825 */ 	or	$a3,$a0,$zero
/*  f1936d0:	00095342 */ 	srl	$t2,$t1,0xd
/*  f1936d4:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f1936d8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1936dc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1936e0:	a58b002c */ 	sh	$t3,0x2c($t4)
/*  f1936e4:	8c8602d4 */ 	lw	$a2,0x2d4($a0)
/*  f1936e8:	8ccd0020 */ 	lw	$t5,0x20($a2)
/*  f1936ec:	000d7900 */ 	sll	$t7,$t5,0x4
/*  f1936f0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1936f4:	9719000e */ 	lhu	$t9,0xe($t8)
/*  f1936f8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1936fc:	01a02025 */ 	or	$a0,$t5,$zero
/*  f193700:	001954c0 */ 	sll	$t2,$t9,0x13
/*  f193704:	05430024 */ 	bgezl	$t2,.L0f193798
/*  f193708:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19370c:	8cc5004c */ 	lw	$a1,0x4c($a2)
/*  f193710:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f193714:	afa70028 */ 	sw	$a3,0x28($sp)
/*  f193718:	00055880 */ 	sll	$t3,$a1,0x2
/*  f19371c:	0fc6667e */ 	jal	func0f1999f8
/*  f193720:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f193724:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f193728:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f19372c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f193730:	8ce602d4 */ 	lw	$a2,0x2d4($a3)
/*  f193734:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f193738:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f19373c:	8f290024 */ 	lw	$t1,0x24($t9)
/*  f193740:	00c81821 */ 	addu	$v1,$a2,$t0
/*  f193744:	846d002c */ 	lh	$t5,0x2c($v1)
/*  f193748:	00495023 */ 	subu	$t2,$v0,$t1
/*  f19374c:	01aa0019 */ 	multu	$t5,$t2
/*  f193750:	00007012 */ 	mflo	$t6
/*  f193754:	a46e002c */ 	sh	$t6,0x2c($v1)
/*  f193758:	8ceb02d4 */ 	lw	$t3,0x2d4($a3)
/*  f19375c:	01681821 */ 	addu	$v1,$t3,$t0
/*  f193760:	846c002c */ 	lh	$t4,0x2c($v1)
/*  f193764:	0182001a */ 	div	$zero,$t4,$v0
/*  f193768:	00007812 */ 	mflo	$t7
/*  f19376c:	a46f002c */ 	sh	$t7,0x2c($v1)
/*  f193770:	14400002 */ 	bnez	$v0,.L0f19377c
/*  f193774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193778:	0007000d */ 	break	0x7
.L0f19377c:
/*  f19377c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f193780:	14410004 */ 	bne	$v0,$at,.L0f193794
/*  f193784:	3c018000 */ 	lui	$at,0x8000
/*  f193788:	15810002 */ 	bne	$t4,$at,.L0f193794
/*  f19378c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193790:	0006000d */ 	break	0x6
.L0f193794:
/*  f193794:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f193798:
/*  f193798:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f19379c:	03e00008 */ 	jr	$ra
/*  f1937a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1937a4
/*  f1937a4:	27bdfd88 */ 	addiu	$sp,$sp,-632
/*  f1937a8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1937ac:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f1937b0:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f1937b4:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f1937b8:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f1937bc:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f1937c0:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f1937c4:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1937c8:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1937cc:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1937d0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f1937d4:	afa5027c */ 	sw	$a1,0x27c($sp)
/*  f1937d8:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1937dc:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f1937e0:	afa000c4 */ 	sw	$zero,0xc4($sp)
/*  f1937e4:	afae0274 */ 	sw	$t6,0x274($sp)
/*  f1937e8:	81d9004f */ 	lb	$t9,0x4f($t6)
/*  f1937ec:	0080f025 */ 	or	$s8,$a0,$zero
/*  f1937f0:	07210017 */ 	bgez	$t9,.L0f193850
/*  f1937f4:	3c08800b */ 	lui	$t0,0x800b
/*  f1937f8:	9108cb98 */ 	lbu	$t0,-0x3468($t0)
/*  f1937fc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f193800:	55010014 */ 	bnel	$t0,$at,.L0f193854
/*  f193804:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193808:	8c89001c */ 	lw	$t1,0x1c($a0)
/*  f19380c:	3c0b800b */ 	lui	$t3,0x800b
/*  f193810:	856bc11e */ 	lh	$t3,-0x3ee2($t3)
/*  f193814:	852a0028 */ 	lh	$t2,0x28($t1)
/*  f193818:	554b000e */ 	bnel	$t2,$t3,.L0f193854
/*  f19381c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193820:	0fc65241 */ 	jal	mpGetNumTeammatesInRoomDoingSomething
/*  f193824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193828:	00408025 */ 	or	$s0,$v0,$zero
/*  f19382c:	0fc65264 */ 	jal	func0f194990
/*  f193830:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193834:	0202082a */ 	slt	$at,$s0,$v0
/*  f193838:	14200005 */ 	bnez	$at,.L0f193850
/*  f19383c:	244c0002 */ 	addiu	$t4,$v0,0x2
/*  f193840:	0190082a */ 	slt	$at,$t4,$s0
/*  f193844:	14200002 */ 	bnez	$at,.L0f193850
/*  f193848:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f19384c:	afad00c4 */ 	sw	$t5,0xc4($sp)
.L0f193850:
/*  f193850:	03c02025 */ 	or	$a0,$s8,$zero
.L0f193854:
/*  f193854:	27a5025c */ 	addiu	$a1,$sp,0x25c
/*  f193858:	27a60244 */ 	addiu	$a2,$sp,0x244
/*  f19385c:	0fc6601a */ 	jal	func0f198068
/*  f193860:	27a7022c */ 	addiu	$a3,$sp,0x22c
/*  f193864:	27b00214 */ 	addiu	$s0,$sp,0x214
/*  f193868:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f19386c:
/*  f19386c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193870:	2a810007 */ 	slti	$at,$s4,0x7
/*  f193874:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f193878:	1420fffc */ 	bnez	$at,.L0f19386c
/*  f19387c:	ae00fffc */ 	sw	$zero,-0x4($s0)
/*  f193880:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f193884:	27a20178 */ 	addiu	$v0,$sp,0x178
/*  f193888:	27a301fc */ 	addiu	$v1,$sp,0x1fc
.L0f19388c:
/*  f19388c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f193890:	0043082b */ 	sltu	$at,$v0,$v1
/*  f193894:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193898:	1420fffc */ 	bnez	$at,.L0f19388c
/*  f19389c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f1938a0:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f1938a4:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f1938a8:	27b000dc */ 	addiu	$s0,$sp,0xdc
/*  f1938ac:	27b100f4 */ 	addiu	$s1,$sp,0xf4
.L0f1938b0:
/*  f1938b0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1938b4:	0fc65f3c */ 	jal	func0f197cf0
/*  f1938b8:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1938bc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1938c0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1938c4:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f1938c8:	1611fff9 */ 	bne	$s0,$s1,.L0f1938b0
/*  f1938cc:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*  f1938d0:	3c15800a */ 	lui	$s5,0x800a
/*  f1938d4:	8eb5a2fc */ 	lw	$s5,-0x5d04($s5)
/*  f1938d8:	27b701fc */ 	addiu	$s7,$sp,0x1fc
/*  f1938dc:	27b20274 */ 	addiu	$s2,$sp,0x274
/*  f1938e0:	52a000db */ 	beqzl	$s5,.L0f193c50
/*  f1938e4:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f1938e8:	8eaf0018 */ 	lw	$t7,0x18($s5)
.L0f1938ec:
/*  f1938ec:	55e000d5 */ 	bnezl	$t7,.L0f193c44
/*  f1938f0:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f1938f4:	86b80002 */ 	lh	$t8,0x2($s5)
/*  f1938f8:	570000d2 */ 	bnezl	$t8,.L0f193c44
/*  f1938fc:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193900:	92a20000 */ 	lbu	$v0,0x0($s5)
/*  f193904:	24010004 */ 	addiu	$at,$zero,0x4
/*  f193908:	5441004f */ 	bnel	$v0,$at,.L0f193a48
/*  f19390c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193910:	8eb10004 */ 	lw	$s1,0x4($s5)
/*  f193914:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193918:	26a50008 */ 	addiu	$a1,$s5,0x8
/*  f19391c:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f193920:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f193924:	15000045 */ 	bnez	$t0,.L0f193a3c
/*  f193928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19392c:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f193930:	00001025 */ 	or	$v0,$zero,$zero
/*  f193934:	46000506 */ 	mov.s	$f20,$f0
/*  f193938:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19393c:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f193940:	9224005c */ 	lbu	$a0,0x5c($s1)
/*  f193944:	27a20274 */ 	addiu	$v0,$sp,0x274
.L0f193948:
/*  f193948:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f19394c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193950:	28a10002 */ 	slti	$at,$a1,0x2
/*  f193954:	1420001b */ 	bnez	$at,.L0f1939c4
/*  f193958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19395c:	14850019 */ 	bne	$a0,$a1,.L0f1939c4
/*  f193960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193964:	0c004b70 */ 	jal	random
/*  f193968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19396c:	3049000f */ 	andi	$t1,$v0,0xf
/*  f193970:	11200012 */ 	beqz	$t1,.L0f1939bc
/*  f193974:	27aa0214 */ 	addiu	$t2,$sp,0x214
/*  f193978:	02ca8021 */ 	addu	$s0,$s6,$t2
/*  f19397c:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f193980:	02f66021 */ 	addu	$t4,$s7,$s6
/*  f193984:	5160000b */ 	beqzl	$t3,.L0f1939b4
/*  f193988:	02f67021 */ 	addu	$t6,$s7,$s6
/*  f19398c:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f193990:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f193994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193998:	45030006 */ 	bc1tl	.L0f1939b4
/*  f19399c:	02f67021 */ 	addu	$t6,$s7,$s6
/*  f1939a0:	0c004b70 */ 	jal	random
/*  f1939a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1939a8:	304d000f */ 	andi	$t5,$v0,0xf
/*  f1939ac:	15a00003 */ 	bnez	$t5,.L0f1939bc
/*  f1939b0:	02f67021 */ 	addu	$t6,$s7,$s6
.L0f1939b4:
/*  f1939b4:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f1939b8:	e5d40000 */ 	swc1	$f20,0x0($t6)
.L0f1939bc:
/*  f1939bc:	10000003 */ 	beqz	$zero,.L0f1939cc
/*  f1939c0:	9224005c */ 	lbu	$a0,0x5c($s1)
.L0f1939c4:
/*  f1939c4:	1662ffe0 */ 	bne	$s3,$v0,.L0f193948
/*  f1939c8:	26d60004 */ 	addiu	$s6,$s6,0x4
.L0f1939cc:
/*  f1939cc:	0fc6666c */ 	jal	func0f1999b0
/*  f1939d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1939d4:	18400019 */ 	blez	$v0,.L0f193a3c
/*  f1939d8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1939dc:	0c004b70 */ 	jal	random
/*  f1939e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1939e4:	304f000f */ 	andi	$t7,$v0,0xf
/*  f1939e8:	11e00014 */ 	beqz	$t7,.L0f193a3c
/*  f1939ec:	00118080 */ 	sll	$s0,$s1,0x2
/*  f1939f0:	27b80178 */ 	addiu	$t8,$sp,0x178
/*  f1939f4:	02189821 */ 	addu	$s3,$s0,$t8
/*  f1939f8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f1939fc:	03b04021 */ 	addu	$t0,$sp,$s0
/*  f193a00:	5320000c */ 	beqzl	$t9,.L0f193a34
/*  f193a04:	ae750000 */ 	sw	$s5,0x0($s3)
/*  f193a08:	c50600f4 */ 	lwc1	$f6,0xf4($t0)
/*  f193a0c:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f193a10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193a14:	45030007 */ 	bc1tl	.L0f193a34
/*  f193a18:	ae750000 */ 	sw	$s5,0x0($s3)
/*  f193a1c:	0c004b70 */ 	jal	random
/*  f193a20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193a24:	3049000f */ 	andi	$t1,$v0,0xf
/*  f193a28:	15200004 */ 	bnez	$t1,.L0f193a3c
/*  f193a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193a30:	ae750000 */ 	sw	$s5,0x0($s3)
.L0f193a34:
/*  f193a34:	03b05021 */ 	addu	$t2,$sp,$s0
/*  f193a38:	e55400f4 */ 	swc1	$f20,0xf4($t2)
.L0f193a3c:
/*  f193a3c:	10000081 */ 	beqz	$zero,.L0f193c44
/*  f193a40:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193a44:	24010001 */ 	addiu	$at,$zero,0x1
.L0f193a48:
/*  f193a48:	5441007e */ 	bnel	$v0,$at,.L0f193c44
/*  f193a4c:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193a50:	8ea20004 */ 	lw	$v0,0x4($s5)
/*  f193a54:	8c4b0010 */ 	lw	$t3,0x10($v0)
/*  f193a58:	316c4000 */ 	andi	$t4,$t3,0x4000
/*  f193a5c:	55800079 */ 	bnezl	$t4,.L0f193c44
/*  f193a60:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193a64:	90440003 */ 	lbu	$a0,0x3($v0)
/*  f193a68:	24010014 */ 	addiu	$at,$zero,0x14
/*  f193a6c:	00408025 */ 	or	$s0,$v0,$zero
/*  f193a70:	1481004d */ 	bne	$a0,$at,.L0f193ba8
/*  f193a74:	26a50008 */ 	addiu	$a1,$s5,0x8
/*  f193a78:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193a7c:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f193a80:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f193a84:	46000506 */ 	mov.s	$f20,$f0
/*  f193a88:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f193a8c:	02009825 */ 	or	$s3,$s0,$zero
.L0f193a90:
/*  f193a90:	966d005e */ 	lhu	$t5,0x5e($s3)
/*  f193a94:	59a0003f */ 	blezl	$t5,.L0f193b94
/*  f193a98:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193a9c:	0fc668c7 */ 	jal	func0f19a31c
/*  f193aa0:	02802025 */ 	or	$a0,$s4,$zero
/*  f193aa4:	18400022 */ 	blez	$v0,.L0f193b30
/*  f193aa8:	00008025 */ 	or	$s0,$zero,$zero
/*  f193aac:	27a3025c */ 	addiu	$v1,$sp,0x25c
.L0f193ab0:
/*  f193ab0:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f193ab4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f193ab8:	28810002 */ 	slti	$at,$a0,0x2
/*  f193abc:	1420001a */ 	bnez	$at,.L0f193b28
/*  f193ac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193ac4:	14440018 */ 	bne	$v0,$a0,.L0f193b28
/*  f193ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193acc:	0c004b70 */ 	jal	random
/*  f193ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193ad4:	304e000f */ 	andi	$t6,$v0,0xf
/*  f193ad8:	11c00015 */ 	beqz	$t6,.L0f193b30
/*  f193adc:	27af0214 */ 	addiu	$t7,$sp,0x214
/*  f193ae0:	020f8821 */ 	addu	$s1,$s0,$t7
/*  f193ae4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f193ae8:	02f0c821 */ 	addu	$t9,$s7,$s0
/*  f193aec:	5300000b */ 	beqzl	$t8,.L0f193b1c
/*  f193af0:	02f04821 */ 	addu	$t1,$s7,$s0
/*  f193af4:	c7280000 */ 	lwc1	$f8,0x0($t9)
/*  f193af8:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f193afc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193b00:	45030006 */ 	bc1tl	.L0f193b1c
/*  f193b04:	02f04821 */ 	addu	$t1,$s7,$s0
/*  f193b08:	0c004b70 */ 	jal	random
/*  f193b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193b10:	3048000f */ 	andi	$t0,$v0,0xf
/*  f193b14:	15000006 */ 	bnez	$t0,.L0f193b30
/*  f193b18:	02f04821 */ 	addu	$t1,$s7,$s0
.L0f193b1c:
/*  f193b1c:	ae350000 */ 	sw	$s5,0x0($s1)
/*  f193b20:	10000003 */ 	beqz	$zero,.L0f193b30
/*  f193b24:	e5340000 */ 	swc1	$f20,0x0($t1)
.L0f193b28:
/*  f193b28:	1472ffe1 */ 	bne	$v1,$s2,.L0f193ab0
/*  f193b2c:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f193b30:
/*  f193b30:	0c004b70 */ 	jal	random
/*  f193b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193b38:	304a000f */ 	andi	$t2,$v0,0xf
/*  f193b3c:	11400014 */ 	beqz	$t2,.L0f193b90
/*  f193b40:	00141080 */ 	sll	$v0,$s4,0x2
/*  f193b44:	27ab0178 */ 	addiu	$t3,$sp,0x178
/*  f193b48:	004b8021 */ 	addu	$s0,$v0,$t3
/*  f193b4c:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f193b50:	27ac00f4 */ 	addiu	$t4,$sp,0xf4
/*  f193b54:	004c8821 */ 	addu	$s1,$v0,$t4
/*  f193b58:	51a0000c */ 	beqzl	$t5,.L0f193b8c
/*  f193b5c:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f193b60:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f193b64:	460aa03c */ 	c.lt.s	$f20,$f10
/*  f193b68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193b6c:	45030007 */ 	bc1tl	.L0f193b8c
/*  f193b70:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f193b74:	0c004b70 */ 	jal	random
/*  f193b78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193b7c:	304e000f */ 	andi	$t6,$v0,0xf
/*  f193b80:	55c00004 */ 	bnezl	$t6,.L0f193b94
/*  f193b84:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193b88:	ae150000 */ 	sw	$s5,0x0($s0)
.L0f193b8c:
/*  f193b8c:	e6340000 */ 	swc1	$f20,0x0($s1)
.L0f193b90:
/*  f193b90:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f193b94:
/*  f193b94:	24010014 */ 	addiu	$at,$zero,0x14
/*  f193b98:	1681ffbd */ 	bne	$s4,$at,.L0f193a90
/*  f193b9c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193ba0:	10000028 */ 	beqz	$zero,.L0f193c44
/*  f193ba4:	8eb50020 */ 	lw	$s5,0x20($s5)
.L0f193ba8:
/*  f193ba8:	24010015 */ 	addiu	$at,$zero,0x15
/*  f193bac:	14810024 */ 	bne	$a0,$at,.L0f193c40
/*  f193bb0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f193bb4:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f193bb8:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f193bbc:	27a30274 */ 	addiu	$v1,$sp,0x274
.L0f193bc0:
/*  f193bc0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f193bc4:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f193bc8:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193bcc:	15e1001a */ 	bne	$t7,$at,.L0f193c38
/*  f193bd0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193bd4:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f193bd8:	26a50008 */ 	addiu	$a1,$s5,0x8
/*  f193bdc:	0c004b70 */ 	jal	random
/*  f193be0:	46000506 */ 	mov.s	$f20,$f0
/*  f193be4:	3058000f */ 	andi	$t8,$v0,0xf
/*  f193be8:	13000015 */ 	beqz	$t8,.L0f193c40
/*  f193bec:	27b90214 */ 	addiu	$t9,$sp,0x214
/*  f193bf0:	02d98021 */ 	addu	$s0,$s6,$t9
/*  f193bf4:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f193bf8:	02f64821 */ 	addu	$t1,$s7,$s6
/*  f193bfc:	5100000b */ 	beqzl	$t0,.L0f193c2c
/*  f193c00:	02f65821 */ 	addu	$t3,$s7,$s6
/*  f193c04:	c5240000 */ 	lwc1	$f4,0x0($t1)
/*  f193c08:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f193c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193c10:	45030006 */ 	bc1tl	.L0f193c2c
/*  f193c14:	02f65821 */ 	addu	$t3,$s7,$s6
/*  f193c18:	0c004b70 */ 	jal	random
/*  f193c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193c20:	304a000f */ 	andi	$t2,$v0,0xf
/*  f193c24:	15400006 */ 	bnez	$t2,.L0f193c40
/*  f193c28:	02f65821 */ 	addu	$t3,$s7,$s6
.L0f193c2c:
/*  f193c2c:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f193c30:	10000003 */ 	beqz	$zero,.L0f193c40
/*  f193c34:	e5740000 */ 	swc1	$f20,0x0($t3)
.L0f193c38:
/*  f193c38:	1663ffe1 */ 	bne	$s3,$v1,.L0f193bc0
/*  f193c3c:	26d60004 */ 	addiu	$s6,$s6,0x4
.L0f193c40:
/*  f193c40:	8eb50020 */ 	lw	$s5,0x20($s5)
.L0f193c44:
/*  f193c44:	56a0ff29 */ 	bnezl	$s5,.L0f1938ec
/*  f193c48:	8eaf0018 */ 	lw	$t7,0x18($s5)
/*  f193c4c:	afa000a0 */ 	sw	$zero,0xa0($sp)
.L0f193c50:
/*  f193c50:	afa0009c */ 	sw	$zero,0x9c($sp)
/*  f193c54:	0000b025 */ 	or	$s6,$zero,$zero
/*  f193c58:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f193c5c:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f193c60:	27b00274 */ 	addiu	$s0,$sp,0x274
.L0f193c64:
/*  f193c64:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193c68:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f193c6c:	0fc6639e */ 	jal	func0f198e78
/*  f193c70:	00003025 */ 	or	$a2,$zero,$zero
/*  f193c74:	14400006 */ 	bnez	$v0,.L0f193c90
/*  f193c78:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193c7c:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f193c80:	0fc6639e */ 	jal	func0f198e78
/*  f193c84:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f193c88:	50400013 */ 	beqzl	$v0,.L0f193cd8
/*  f193c8c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f193c90:
/*  f193c90:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f193c94:	3c038008 */ 	lui	$v1,0x8008
/*  f193c98:	03b61021 */ 	addu	$v0,$sp,$s6
/*  f193c9c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f193ca0:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f193ca4:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
/*  f193ca8:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f193cac:	000373c2 */ 	srl	$t6,$v1,0xf
/*  f193cb0:	15c00003 */ 	bnez	$t6,.L0f193cc0
/*  f193cb4:	0003c440 */ 	sll	$t8,$v1,0x11
/*  f193cb8:	07030007 */ 	bgezl	$t8,.L0f193cd8
/*  f193cbc:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f193cc0:
/*  f193cc0:	8c420244 */ 	lw	$v0,0x244($v0)
/*  f193cc4:	0322082a */ 	slt	$at,$t9,$v0
/*  f193cc8:	50200003 */ 	beqzl	$at,.L0f193cd8
/*  f193ccc:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193cd0:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f193cd4:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f193cd8:
/*  f193cd8:	0270082b */ 	sltu	$at,$s3,$s0
/*  f193cdc:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f193ce0:	1420ffe0 */ 	bnez	$at,.L0f193c64
/*  f193ce4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193ce8:	3c017f1c */ 	lui	$at,%hi(var7f1b8f48)
/*  f193cec:	c4328f48 */ 	lwc1	$f18,%lo(var7f1b8f48)($at)
/*  f193cf0:	3c014080 */ 	lui	$at,0x4080
/*  f193cf4:	27a8025c */ 	addiu	$t0,$sp,0x25c
/*  f193cf8:	44818000 */ 	mtc1	$at,$f16
/*  f193cfc:	44806000 */ 	mtc1	$zero,$f12
/*  f193d00:	00089821 */ 	addu	$s3,$zero,$t0
/*  f193d04:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f193d08:	0000b025 */ 	or	$s6,$zero,$zero
/*  f193d0c:	27b00274 */ 	addiu	$s0,$sp,0x274
/*  f193d10:	8e690000 */ 	lw	$t1,0x0($s3)
.L0f193d14:
/*  f193d14:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f193d18:	3c03800b */ 	lui	$v1,0x800b
/*  f193d1c:	552100d0 */ 	bnel	$t1,$at,.L0f194060
/*  f193d20:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193d24:	9063cb98 */ 	lbu	$v1,-0x3468($v1)
/*  f193d28:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193d2c:	8fad0274 */ 	lw	$t5,0x274($sp)
/*  f193d30:	54610007 */ 	bnel	$v1,$at,.L0f193d50
/*  f193d34:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f193d38:	8fca02d4 */ 	lw	$t2,0x2d4($s8)
/*  f193d3c:	8d4b009c */ 	lw	$t3,0x9c($t2)
/*  f193d40:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f193d44:	558000c6 */ 	bnezl	$t4,.L0f194060
/*  f193d48:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193d4c:	8da20004 */ 	lw	$v0,0x4($t5)
.L0f193d50:
/*  f193d50:	3c017f1c */ 	lui	$at,%hi(var7f1b8f4c)
/*  f193d54:	c4228f4c */ 	lwc1	$f2,%lo(var7f1b8f4c)($at)
/*  f193d58:	904e0047 */ 	lbu	$t6,0x47($v0)
/*  f193d5c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193d60:	46006506 */ 	mov.s	$f20,$f12
/*  f193d64:	15c1001b */ 	bne	$t6,$at,.L0f193dd4
/*  f193d68:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f193d6c:	8faf027c */ 	lw	$t7,0x27c($sp)
/*  f193d70:	c7c60104 */ 	lwc1	$f6,0x104($s8)
/*  f193d74:	c7c80100 */ 	lwc1	$f8,0x100($s8)
/*  f193d78:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193d7c:	90430048 */ 	lbu	$v1,0x48($v0)
/*  f193d80:	15e10003 */ 	bne	$t7,$at,.L0f193d90
/*  f193d84:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f193d88:	1000005b */ 	beqz	$zero,.L0f193ef8
/*  f193d8c:	46009506 */ 	mov.s	$f20,$f18
.L0f193d90:
/*  f193d90:	8fb8027c */ 	lw	$t8,0x27c($sp)
/*  f193d94:	8fb90274 */ 	lw	$t9,0x274($sp)
/*  f193d98:	8fa8027c */ 	lw	$t0,0x27c($sp)
/*  f193d9c:	17000007 */ 	bnez	$t8,.L0f193dbc
/*  f193da0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193da4:	c72002d4 */ 	lwc1	$f0,0x2d4($t9)
/*  f193da8:	3c0140c0 */ 	lui	$at,0x40c0
/*  f193dac:	44815000 */ 	mtc1	$at,$f10
/*  f193db0:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f193db4:	10000050 */ 	beqz	$zero,.L0f193ef8
/*  f193db8:	46045501 */ 	sub.s	$f20,$f10,$f4
.L0f193dbc:
/*  f193dbc:	1501004e */ 	bne	$t0,$at,.L0f193ef8
/*  f193dc0:	8fa90274 */ 	lw	$t1,0x274($sp)
/*  f193dc4:	c52002d4 */ 	lwc1	$f0,0x2d4($t1)
/*  f193dc8:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f193dcc:	1000004a */ 	beqz	$zero,.L0f193ef8
/*  f193dd0:	46068501 */ 	sub.s	$f20,$f16,$f6
.L0f193dd4:
/*  f193dd4:	1140000d */ 	beqz	$t2,.L0f193e0c
/*  f193dd8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f193ddc:	8fab0274 */ 	lw	$t3,0x274($sp)
/*  f193de0:	3c013f80 */ 	lui	$at,0x3f80
/*  f193de4:	44815000 */ 	mtc1	$at,$f10
/*  f193de8:	c56002d4 */ 	lwc1	$f0,0x2d4($t3)
/*  f193dec:	c7c40104 */ 	lwc1	$f4,0x104($s8)
/*  f193df0:	c7c60100 */ 	lwc1	$f6,0x100($s8)
/*  f193df4:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f193df8:	90430048 */ 	lbu	$v1,0x48($v0)
/*  f193dfc:	46005501 */ 	sub.s	$f20,$f10,$f0
/*  f193e00:	46088081 */ 	sub.s	$f2,$f16,$f8
/*  f193e04:	1000003c */ 	beqz	$zero,.L0f193ef8
/*  f193e08:	46062381 */ 	sub.s	$f14,$f4,$f6
.L0f193e0c:
/*  f193e0c:	14610016 */ 	bne	$v1,$at,.L0f193e68
/*  f193e10:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193e14:	0fc65227 */ 	jal	func0f19489c
/*  f193e18:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f193e1c:	3c014080 */ 	lui	$at,0x4080
/*  f193e20:	44818000 */ 	mtc1	$at,$f16
/*  f193e24:	3c017f1c */ 	lui	$at,%hi(var7f1b8f50)
/*  f193e28:	44806000 */ 	mtc1	$zero,$f12
/*  f193e2c:	c4328f50 */ 	lwc1	$f18,%lo(var7f1b8f50)($at)
/*  f193e30:	1040000d */ 	beqz	$v0,.L0f193e68
/*  f193e34:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f193e38:	8fac0274 */ 	lw	$t4,0x274($sp)
/*  f193e3c:	3c014040 */ 	lui	$at,0x4040
/*  f193e40:	44814000 */ 	mtc1	$at,$f8
/*  f193e44:	c58002d4 */ 	lwc1	$f0,0x2d4($t4)
/*  f193e48:	c7c40104 */ 	lwc1	$f4,0x104($s8)
/*  f193e4c:	c7c60100 */ 	lwc1	$f6,0x100($s8)
/*  f193e50:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f193e54:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f193e58:	46062381 */ 	sub.s	$f14,$f4,$f6
/*  f193e5c:	91a30048 */ 	lbu	$v1,0x48($t5)
/*  f193e60:	10000025 */ 	beqz	$zero,.L0f193ef8
/*  f193e64:	460a4081 */ 	sub.s	$f2,$f8,$f10
.L0f193e68:
/*  f193e68:	8fae0274 */ 	lw	$t6,0x274($sp)
/*  f193e6c:	93d802a0 */ 	lbu	$t8,0x2a0($s8)
/*  f193e70:	c7c80104 */ 	lwc1	$f8,0x104($s8)
/*  f193e74:	c7ca0100 */ 	lwc1	$f10,0x100($s8)
/*  f193e78:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f193e7c:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f193e80:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f193e84:	17010007 */ 	bne	$t8,$at,.L0f193ea4
/*  f193e88:	91e30048 */ 	lbu	$v1,0x48($t7)
/*  f193e8c:	c5c002d4 */ 	lwc1	$f0,0x2d4($t6)
/*  f193e90:	3c013f80 */ 	lui	$at,0x3f80
/*  f193e94:	4481a000 */ 	mtc1	$at,$f20
/*  f193e98:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f193e9c:	10000016 */ 	beqz	$zero,.L0f193ef8
/*  f193ea0:	46048081 */ 	sub.s	$f2,$f16,$f4
.L0f193ea4:
/*  f193ea4:	8fb9027c */ 	lw	$t9,0x27c($sp)
/*  f193ea8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193eac:	8fa8027c */ 	lw	$t0,0x27c($sp)
/*  f193eb0:	17210003 */ 	bne	$t9,$at,.L0f193ec0
/*  f193eb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193eb8:	1000000f */ 	beqz	$zero,.L0f193ef8
/*  f193ebc:	46009506 */ 	mov.s	$f20,$f18
.L0f193ec0:
/*  f193ec0:	15000006 */ 	bnez	$t0,.L0f193edc
/*  f193ec4:	8faa027c */ 	lw	$t2,0x27c($sp)
/*  f193ec8:	8fa90274 */ 	lw	$t1,0x274($sp)
/*  f193ecc:	c52002d4 */ 	lwc1	$f0,0x2d4($t1)
/*  f193ed0:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f193ed4:	10000008 */ 	beqz	$zero,.L0f193ef8
/*  f193ed8:	46068501 */ 	sub.s	$f20,$f16,$f6
.L0f193edc:
/*  f193edc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193ee0:	15410005 */ 	bne	$t2,$at,.L0f193ef8
/*  f193ee4:	8fab0274 */ 	lw	$t3,0x274($sp)
/*  f193ee8:	3c014000 */ 	lui	$at,0x4000
/*  f193eec:	44814000 */ 	mtc1	$at,$f8
/*  f193ef0:	c56a02d4 */ 	lwc1	$f10,0x2d4($t3)
/*  f193ef4:	460a4501 */ 	sub.s	$f20,$f8,$f10
.L0f193ef8:
/*  f193ef8:	1460001f */ 	bnez	$v1,.L0f193f78
/*  f193efc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193f00:	8fac0274 */ 	lw	$t4,0x274($sp)
/*  f193f04:	8faf0274 */ 	lw	$t7,0x274($sp)
/*  f193f08:	8d8202d0 */ 	lw	$v0,0x2d0($t4)
/*  f193f0c:	304d0007 */ 	andi	$t5,$v0,0x7
/*  f193f10:	29a10002 */ 	slti	$at,$t5,0x2
/*  f193f14:	10200004 */ 	beqz	$at,.L0f193f28
/*  f193f18:	01a01025 */ 	or	$v0,$t5,$zero
/*  f193f1c:	46006506 */ 	mov.s	$f20,$f12
/*  f193f20:	10000038 */ 	beqz	$zero,.L0f194004
/*  f193f24:	46006086 */ 	mov.s	$f2,$f12
.L0f193f28:
/*  f193f28:	28410004 */ 	slti	$at,$v0,0x4
/*  f193f2c:	10200006 */ 	beqz	$at,.L0f193f48
/*  f193f30:	c5e002d4 */ 	lwc1	$f0,0x2d4($t7)
/*  f193f34:	3c014000 */ 	lui	$at,0x4000
/*  f193f38:	44812000 */ 	mtc1	$at,$f4
/*  f193f3c:	46006506 */ 	mov.s	$f20,$f12
/*  f193f40:	10000030 */ 	beqz	$zero,.L0f194004
/*  f193f44:	46002081 */ 	sub.s	$f2,$f4,$f0
.L0f193f48:
/*  f193f48:	3c014180 */ 	lui	$at,0x4180
/*  f193f4c:	44813000 */ 	mtc1	$at,$f6
/*  f193f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193f54:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f193f58:	4608a501 */ 	sub.s	$f20,$f20,$f8
/*  f193f5c:	460ca03e */ 	c.le.s	$f20,$f12
/*  f193f60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193f64:	45020028 */ 	bc1fl	.L0f194008
/*  f193f68:	4602703c */ 	c.lt.s	$f14,$f2
/*  f193f6c:	46141080 */ 	add.s	$f2,$f2,$f20
/*  f193f70:	10000024 */ 	beqz	$zero,.L0f194004
/*  f193f74:	46006506 */ 	mov.s	$f20,$f12
.L0f193f78:
/*  f193f78:	14610016 */ 	bne	$v1,$at,.L0f193fd4
/*  f193f7c:	8fb80274 */ 	lw	$t8,0x274($sp)
/*  f193f80:	8f0202d0 */ 	lw	$v0,0x2d0($t8)
/*  f193f84:	8fb90274 */ 	lw	$t9,0x274($sp)
/*  f193f88:	3c014130 */ 	lui	$at,0x4130
/*  f193f8c:	304e0007 */ 	andi	$t6,$v0,0x7
/*  f193f90:	5dc00005 */ 	bgtzl	$t6,.L0f193fa8
/*  f193f94:	c72a02d4 */ 	lwc1	$f10,0x2d4($t9)
/*  f193f98:	46006506 */ 	mov.s	$f20,$f12
/*  f193f9c:	10000019 */ 	beqz	$zero,.L0f194004
/*  f193fa0:	46006086 */ 	mov.s	$f2,$f12
/*  f193fa4:	c72a02d4 */ 	lwc1	$f10,0x2d4($t9)
.L0f193fa8:
/*  f193fa8:	44812000 */ 	mtc1	$at,$f4
/*  f193fac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193fb0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f193fb4:	4606a501 */ 	sub.s	$f20,$f20,$f6
/*  f193fb8:	460ca03e */ 	c.le.s	$f20,$f12
/*  f193fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193fc0:	45020011 */ 	bc1fl	.L0f194008
/*  f193fc4:	4602703c */ 	c.lt.s	$f14,$f2
/*  f193fc8:	46141080 */ 	add.s	$f2,$f2,$f20
/*  f193fcc:	1000000d */ 	beqz	$zero,.L0f194004
/*  f193fd0:	46006506 */ 	mov.s	$f20,$f12
.L0f193fd4:
/*  f193fd4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193fd8:	1461000a */ 	bne	$v1,$at,.L0f194004
/*  f193fdc:	8fa80274 */ 	lw	$t0,0x274($sp)
/*  f193fe0:	c50802d4 */ 	lwc1	$f8,0x2d4($t0)
/*  f193fe4:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f193fe8:	460aa501 */ 	sub.s	$f20,$f20,$f10
/*  f193fec:	460ca03e */ 	c.le.s	$f20,$f12
/*  f193ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f193ff4:	45020004 */ 	bc1fl	.L0f194008
/*  f193ff8:	4602703c */ 	c.lt.s	$f14,$f2
/*  f193ffc:	46141080 */ 	add.s	$f2,$f2,$f20
/*  f194000:	46006506 */ 	mov.s	$f20,$f12
.L0f194004:
/*  f194004:	4602703c */ 	c.lt.s	$f14,$f2
.L0f194008:
/*  f194008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19400c:	45020014 */ 	bc1fl	.L0f194060
/*  f194010:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194014:	c7c40180 */ 	lwc1	$f4,0x180($s8)
/*  f194018:	03b61021 */ 	addu	$v0,$sp,$s6
/*  f19401c:	4614203e */ 	c.le.s	$f4,$f20
/*  f194020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194024:	4502000e */ 	bc1fl	.L0f194060
/*  f194028:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f19402c:	8c420214 */ 	lw	$v0,0x214($v0)
/*  f194030:	03b64821 */ 	addu	$t1,$sp,$s6
/*  f194034:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f194038:	50400009 */ 	beqzl	$v0,.L0f194060
/*  f19403c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194040:	8d29022c */ 	lw	$t1,0x22c($t1)
/*  f194044:	012a082a */ 	slt	$at,$t1,$t2
/*  f194048:	14200004 */ 	bnez	$at,.L0f19405c
/*  f19404c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f194050:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194054:	10000008 */ 	beqz	$zero,.L0f194078
/*  f194058:	afab009c */ 	sw	$t3,0x9c($sp)
.L0f19405c:
/*  f19405c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f194060:
/*  f194060:	0270082b */ 	sltu	$at,$s3,$s0
/*  f194064:	10200004 */ 	beqz	$at,.L0f194078
/*  f194068:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f19406c:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f194070:	5180ff28 */ 	beqzl	$t4,.L0f193d14
/*  f194074:	8e690000 */ 	lw	$t1,0x0($s3)
.L0f194078:
/*  f194078:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f19407c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f194080:	0000b025 */ 	or	$s6,$zero,$zero
/*  f194084:	15a000fe */ 	bnez	$t5,.L0f194480
/*  f194088:	27af025c */ 	addiu	$t7,$sp,0x25c
/*  f19408c:	000f9821 */ 	addu	$s3,$zero,$t7
/*  f194090:	8fb70088 */ 	lw	$s7,0x88($sp)
/*  f194094:	8fb50084 */ 	lw	$s5,0x84($sp)
/*  f194098:	8e650000 */ 	lw	$a1,0x0($s3)
.L0f19409c:
/*  f19409c:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1940a0:	03b6c021 */ 	addu	$t8,$sp,$s6
/*  f1940a4:	50a100ea */ 	beql	$a1,$at,.L0f194450
/*  f1940a8:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f1940ac:	8f1800dc */ 	lw	$t8,0xdc($t8)
/*  f1940b0:	00057100 */ 	sll	$t6,$a1,0x4
/*  f1940b4:	3c038008 */ 	lui	$v1,0x8008
/*  f1940b8:	130000e4 */ 	beqz	$t8,.L0f19444c
/*  f1940bc:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f1940c0:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
/*  f1940c4:	03b65021 */ 	addu	$t2,$sp,$s6
/*  f1940c8:	8fab00a0 */ 	lw	$t3,0xa0($sp)
/*  f1940cc:	0003cbc2 */ 	srl	$t9,$v1,0xf
/*  f1940d0:	17200003 */ 	bnez	$t9,.L0f1940e0
/*  f1940d4:	00034c40 */ 	sll	$t1,$v1,0x11
/*  f1940d8:	052300dd */ 	bgezl	$t1,.L0f194450
/*  f1940dc:	8fb400d8 */ 	lw	$s4,0xd8($sp)
.L0f1940e0:
/*  f1940e0:	8d4a022c */ 	lw	$t2,0x22c($t2)
/*  f1940e4:	3c0c800b */ 	lui	$t4,0x800b
/*  f1940e8:	014b082a */ 	slt	$at,$t2,$t3
/*  f1940ec:	542000d8 */ 	bnezl	$at,.L0f194450
/*  f1940f0:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f1940f4:	918ccb98 */ 	lbu	$t4,-0x3468($t4)
/*  f1940f8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1940fc:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f194100:	55810008 */ 	bnel	$t4,$at,.L0f194124
/*  f194104:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
/*  f194108:	0fc65227 */ 	jal	func0f19489c
/*  f19410c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f194110:	10400003 */ 	beqz	$v0,.L0f194120
/*  f194114:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f194118:	100000d9 */ 	beqz	$zero,.L0f194480
/*  f19411c:	afad009c */ 	sw	$t5,0x9c($sp)
.L0f194120:
/*  f194120:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
.L0f194124:
/*  f194124:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f194128:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f19412c:	15e10004 */ 	bne	$t7,$at,.L0f194140
/*  f194130:	8fad027c */ 	lw	$t5,0x27c($sp)
/*  f194134:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f194138:	100000d1 */ 	beqz	$zero,.L0f194480
/*  f19413c:	afb8009c */ 	sw	$t8,0x9c($sp)
.L0f194140:
/*  f194140:	11c0002a */ 	beqz	$t6,.L0f1941ec
/*  f194144:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194148:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f19414c:	3c088008 */ 	lui	$t0,%hi(var80087eb0)
/*  f194150:	25087eb0 */ 	addiu	$t0,$t0,%lo(var80087eb0)
/*  f194154:	0005c900 */ 	sll	$t9,$a1,0x4
/*  f194158:	03281021 */ 	addu	$v0,$t9,$t0
/*  f19415c:	9457000a */ 	lhu	$s7,0xa($v0)
/*  f194160:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f194164:	00003025 */ 	or	$a2,$zero,$zero
/*  f194168:	2ae10002 */ 	slti	$at,$s7,0x2
/*  f19416c:	14200002 */ 	bnez	$at,.L0f194178
/*  f194170:	000323c2 */ 	srl	$a0,$v1,0xf
/*  f194174:	24170001 */ 	addiu	$s7,$zero,0x1
.L0f194178:
/*  f194178:	9455000c */ 	lhu	$s5,0xc($v0)
/*  f19417c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f194180:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f194184:	14200002 */ 	bnez	$at,.L0f194190
/*  f194188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19418c:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f194190:
/*  f194190:	5080000c */ 	beqzl	$a0,.L0f1941c4
/*  f194194:	00035c40 */ 	sll	$t3,$v1,0x11
/*  f194198:	0fc666f9 */ 	jal	func0f199be4
/*  f19419c:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1941a0:	0057082a */ 	slt	$at,$v0,$s7
/*  f1941a4:	5020000f */ 	beqzl	$at,.L0f1941e4
/*  f1941a8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1941ac:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1941b0:	3c038008 */ 	lui	$v1,0x8008
/*  f1941b4:	00054900 */ 	sll	$t1,$a1,0x4
/*  f1941b8:	00691821 */ 	addu	$v1,$v1,$t1
/*  f1941bc:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
/*  f1941c0:	00035c40 */ 	sll	$t3,$v1,0x11
.L0f1941c4:
/*  f1941c4:	05610080 */ 	bgez	$t3,.L0f1943c8
/*  f1941c8:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1941cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1941d0:	0fc666f9 */ 	jal	func0f199be4
/*  f1941d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1941d8:	0055082a */ 	slt	$at,$v0,$s5
/*  f1941dc:	1420007a */ 	bnez	$at,.L0f1943c8
/*  f1941e0:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f1941e4:
/*  f1941e4:	100000a6 */ 	beqz	$zero,.L0f194480
/*  f1941e8:	afac009c */ 	sw	$t4,0x9c($sp)
.L0f1941ec:
/*  f1941ec:	15a1002f */ 	bne	$t5,$at,.L0f1942ac
/*  f1941f0:	8fa9027c */ 	lw	$t1,0x27c($sp)
/*  f1941f4:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1941f8:	0fc6666c */ 	jal	func0f1999b0
/*  f1941fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f194200:	0fc2a63d */ 	jal	func0f0a98f4
/*  f194204:	00402025 */ 	or	$a0,$v0,$zero
/*  f194208:	0040b825 */ 	or	$s7,$v0,$zero
/*  f19420c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f194210:	0fc6666c */ 	jal	func0f1999b0
/*  f194214:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f194218:	0fc2a63d */ 	jal	func0f0a98f4
/*  f19421c:	00402025 */ 	or	$a0,$v0,$zero
/*  f194220:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194224:	3c038008 */ 	lui	$v1,0x8008
/*  f194228:	0040a825 */ 	or	$s5,$v0,$zero
/*  f19422c:	00057900 */ 	sll	$t7,$a1,0x4
/*  f194230:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f194234:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
/*  f194238:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f19423c:	00003025 */ 	or	$a2,$zero,$zero
/*  f194240:	0003c3c2 */ 	srl	$t8,$v1,0xf
/*  f194244:	5300000c */ 	beqzl	$t8,.L0f194278
/*  f194248:	00034440 */ 	sll	$t0,$v1,0x11
/*  f19424c:	0fc666f9 */ 	jal	func0f199be4
/*  f194250:	00003825 */ 	or	$a3,$zero,$zero
/*  f194254:	0057082a */ 	slt	$at,$v0,$s7
/*  f194258:	14200012 */ 	bnez	$at,.L0f1942a4
/*  f19425c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194260:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194264:	3c038008 */ 	lui	$v1,0x8008
/*  f194268:	00057100 */ 	sll	$t6,$a1,0x4
/*  f19426c:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f194270:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
/*  f194274:	00034440 */ 	sll	$t0,$v1,0x11
.L0f194278:
/*  f194278:	05010007 */ 	bgez	$t0,.L0f194298
/*  f19427c:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f194280:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f194284:	0fc666f9 */ 	jal	func0f199be4
/*  f194288:	00003825 */ 	or	$a3,$zero,$zero
/*  f19428c:	0055082a */ 	slt	$at,$v0,$s5
/*  f194290:	14200004 */ 	bnez	$at,.L0f1942a4
/*  f194294:	00000000 */ 	sll	$zero,$zero,0x0
.L0f194298:
/*  f194298:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f19429c:	1000006d */ 	beqz	$zero,.L0f194454
/*  f1942a0:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1942a4:
/*  f1942a4:	10000048 */ 	beqz	$zero,.L0f1943c8
/*  f1942a8:	0000a025 */ 	or	$s4,$zero,$zero
.L0f1942ac:
/*  f1942ac:	15200022 */ 	bnez	$t1,.L0f194338
/*  f1942b0:	8fb9027c */ 	lw	$t9,0x27c($sp)
/*  f1942b4:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1942b8:	3c0b8008 */ 	lui	$t3,%hi(var80087eb0)
/*  f1942bc:	256b7eb0 */ 	addiu	$t3,$t3,%lo(var80087eb0)
/*  f1942c0:	00055100 */ 	sll	$t2,$a1,0x4
/*  f1942c4:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f1942c8:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f1942cc:	94570006 */ 	lhu	$s7,0x6($v0)
/*  f1942d0:	94550008 */ 	lhu	$s5,0x8($v0)
/*  f1942d4:	000363c2 */ 	srl	$t4,$v1,0xf
/*  f1942d8:	1180000c */ 	beqz	$t4,.L0f19430c
/*  f1942dc:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1942e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1942e4:	0fc666f9 */ 	jal	func0f199be4
/*  f1942e8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1942ec:	0057082a */ 	slt	$at,$v0,$s7
/*  f1942f0:	5020000f */ 	beqzl	$at,.L0f194330
/*  f1942f4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1942f8:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1942fc:	3c038008 */ 	lui	$v1,0x8008
/*  f194300:	00056900 */ 	sll	$t5,$a1,0x4
/*  f194304:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f194308:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
.L0f19430c:
/*  f19430c:	0003c440 */ 	sll	$t8,$v1,0x11
/*  f194310:	0701002d */ 	bgez	$t8,.L0f1943c8
/*  f194314:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f194318:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19431c:	0fc666f9 */ 	jal	func0f199be4
/*  f194320:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f194324:	0055082a */ 	slt	$at,$v0,$s5
/*  f194328:	14200027 */ 	bnez	$at,.L0f1943c8
/*  f19432c:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f194330:
/*  f194330:	10000053 */ 	beqz	$zero,.L0f194480
/*  f194334:	afae009c */ 	sw	$t6,0x9c($sp)
.L0f194338:
/*  f194338:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19433c:	57210023 */ 	bnel	$t9,$at,.L0f1943cc
/*  f194340:	00008025 */ 	or	$s0,$zero,$zero
/*  f194344:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194348:	3c098008 */ 	lui	$t1,%hi(var80087eb0)
/*  f19434c:	25297eb0 */ 	addiu	$t1,$t1,%lo(var80087eb0)
/*  f194350:	00054100 */ 	sll	$t0,$a1,0x4
/*  f194354:	01091021 */ 	addu	$v0,$t0,$t1
/*  f194358:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f19435c:	9457000a */ 	lhu	$s7,0xa($v0)
/*  f194360:	9455000c */ 	lhu	$s5,0xc($v0)
/*  f194364:	000353c2 */ 	srl	$t2,$v1,0xf
/*  f194368:	1140000c */ 	beqz	$t2,.L0f19439c
/*  f19436c:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f194370:	00003025 */ 	or	$a2,$zero,$zero
/*  f194374:	0fc666f9 */ 	jal	func0f199be4
/*  f194378:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f19437c:	0057082a */ 	slt	$at,$v0,$s7
/*  f194380:	5020000f */ 	beqzl	$at,.L0f1943c0
/*  f194384:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f194388:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f19438c:	3c038008 */ 	lui	$v1,0x8008
/*  f194390:	00055900 */ 	sll	$t3,$a1,0x4
/*  f194394:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f194398:	94637eb4 */ 	lhu	$v1,0x7eb4($v1)
.L0f19439c:
/*  f19439c:	00036c40 */ 	sll	$t5,$v1,0x11
/*  f1943a0:	05a10009 */ 	bgez	$t5,.L0f1943c8
/*  f1943a4:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1943a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1943ac:	0fc666f9 */ 	jal	func0f199be4
/*  f1943b0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1943b4:	0055082a */ 	slt	$at,$v0,$s5
/*  f1943b8:	14200003 */ 	bnez	$at,.L0f1943c8
/*  f1943bc:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0f1943c0:
/*  f1943c0:	1000002f */ 	beqz	$zero,.L0f194480
/*  f1943c4:	afaf009c */ 	sw	$t7,0x9c($sp)
.L0f1943c8:
/*  f1943c8:	00008025 */ 	or	$s0,$zero,$zero
.L0f1943cc:
/*  f1943cc:	03c02025 */ 	or	$a0,$s8,$zero
.L0f1943d0:
/*  f1943d0:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1943d4:	0fc6639e */ 	jal	func0f198e78
/*  f1943d8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1943dc:	10400017 */ 	beqz	$v0,.L0f19443c
/*  f1943e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1943e4:	0fc6666c */ 	jal	func0f1999b0
/*  f1943e8:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1943ec:	18400013 */ 	blez	$v0,.L0f19443c
/*  f1943f0:	00409025 */ 	or	$s2,$v0,$zero
/*  f1943f4:	12000003 */ 	beqz	$s0,.L0f194404
/*  f1943f8:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1943fc:	10000002 */ 	beqz	$zero,.L0f194408
/*  f194400:	02a08825 */ 	or	$s1,$s5,$zero
.L0f194404:
/*  f194404:	02e08825 */ 	or	$s1,$s7,$zero
.L0f194408:
/*  f194408:	02402825 */ 	or	$a1,$s2,$zero
/*  f19440c:	0fc6672e */ 	jal	func0f199cb8
/*  f194410:	02803025 */ 	or	$a2,$s4,$zero
/*  f194414:	0051082a */ 	slt	$at,$v0,$s1
/*  f194418:	10200008 */ 	beqz	$at,.L0f19443c
/*  f19441c:	0012c080 */ 	sll	$t8,$s2,0x2
/*  f194420:	03b81021 */ 	addu	$v0,$sp,$t8
/*  f194424:	8c420178 */ 	lw	$v0,0x178($v0)
/*  f194428:	10400004 */ 	beqz	$v0,.L0f19443c
/*  f19442c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f194430:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194434:	10000005 */ 	beqz	$zero,.L0f19444c
/*  f194438:	afae009c */ 	sw	$t6,0x9c($sp)
.L0f19443c:
/*  f19443c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194440:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194444:	5601ffe2 */ 	bnel	$s0,$at,.L0f1943d0
/*  f194448:	03c02025 */ 	or	$a0,$s8,$zero
.L0f19444c:
/*  f19444c:	8fb400d8 */ 	lw	$s4,0xd8($sp)
.L0f194450:
/*  f194450:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f194454:
/*  f194454:	afb400d8 */ 	sw	$s4,0xd8($sp)
/*  f194458:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f19445c:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f194460:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194464:	2b210006 */ 	slti	$at,$t9,0x6
/*  f194468:	10200005 */ 	beqz	$at,.L0f194480
/*  f19446c:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f194470:	5100ff0a */ 	beqzl	$t0,.L0f19409c
/*  f194474:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194478:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f19447c:	afb50084 */ 	sw	$s5,0x84($sp)
.L0f194480:
/*  f194480:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f194484:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f194488:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19448c:	15200036 */ 	bnez	$t1,.L0f194568
/*  f194490:	27aa025c */ 	addiu	$t2,$sp,0x25c
/*  f194494:	000a9821 */ 	addu	$s3,$zero,$t2
/*  f194498:	27b00274 */ 	addiu	$s0,$sp,0x274
/*  f19449c:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f1944a0:
/*  f1944a0:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1944a4:	3c0c800b */ 	lui	$t4,0x800b
/*  f1944a8:	51610029 */ 	beql	$t3,$at,.L0f194550
/*  f1944ac:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f1944b0:	918ccb98 */ 	lbu	$t4,-0x3468($t4)
/*  f1944b4:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1944b8:	55810008 */ 	bnel	$t4,$at,.L0f1944dc
/*  f1944bc:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
/*  f1944c0:	0fc65227 */ 	jal	func0f19489c
/*  f1944c4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1944c8:	10400003 */ 	beqz	$v0,.L0f1944d8
/*  f1944cc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1944d0:	10000025 */ 	beqz	$zero,.L0f194568
/*  f1944d4:	afad009c */ 	sw	$t5,0x9c($sp)
.L0f1944d8:
/*  f1944d8:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
.L0f1944dc:
/*  f1944dc:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1944e0:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f1944e4:	15e10004 */ 	bne	$t7,$at,.L0f1944f8
/*  f1944e8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1944ec:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1944f0:	1000001d */ 	beqz	$zero,.L0f194568
/*  f1944f4:	afb8009c */ 	sw	$t8,0x9c($sp)
.L0f1944f8:
/*  f1944f8:	15c00014 */ 	bnez	$t6,.L0f19454c
/*  f1944fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f194500:	0fc6639e */ 	jal	func0f198e78
/*  f194504:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194508:	14400005 */ 	bnez	$v0,.L0f194520
/*  f19450c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f194510:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194514:	0fc6639e */ 	jal	func0f198e78
/*  f194518:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19451c:	1040000b */ 	beqz	$v0,.L0f19454c
.L0f194520:
/*  f194520:	03b6c821 */ 	addu	$t9,$sp,$s6
/*  f194524:	8f3900dc */ 	lw	$t9,0xdc($t9)
/*  f194528:	03b61021 */ 	addu	$v0,$sp,$s6
/*  f19452c:	57200008 */ 	bnezl	$t9,.L0f194550
/*  f194530:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194534:	8c420214 */ 	lw	$v0,0x214($v0)
/*  f194538:	10400004 */ 	beqz	$v0,.L0f19454c
/*  f19453c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f194540:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194544:	10000008 */ 	beqz	$zero,.L0f194568
/*  f194548:	afa8009c */ 	sw	$t0,0x9c($sp)
.L0f19454c:
/*  f19454c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f194550:
/*  f194550:	0270082b */ 	sltu	$at,$s3,$s0
/*  f194554:	10200004 */ 	beqz	$at,.L0f194568
/*  f194558:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f19455c:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f194560:	5120ffcf */ 	beqzl	$t1,.L0f1944a0
/*  f194564:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f194568:
/*  f194568:	8faa027c */ 	lw	$t2,0x27c($sp)
/*  f19456c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194570:	55410032 */ 	bnel	$t2,$at,.L0f19463c
/*  f194574:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f194578:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f19457c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f194580:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f194584:	1560002c */ 	bnez	$t3,.L0f194638
/*  f194588:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f19458c:	27b50274 */ 	addiu	$s5,$sp,0x274
/*  f194590:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f194594:
/*  f194594:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f194598:	00008825 */ 	or	$s1,$zero,$zero
/*  f19459c:	1181001f */ 	beq	$t4,$at,.L0f19461c
/*  f1945a0:	03c02025 */ 	or	$a0,$s8,$zero
.L0f1945a4:
/*  f1945a4:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1945a8:	0fc6639e */ 	jal	func0f198e78
/*  f1945ac:	02203025 */ 	or	$a2,$s1,$zero
/*  f1945b0:	10400016 */ 	beqz	$v0,.L0f19460c
/*  f1945b4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1945b8:	0fc6666c */ 	jal	func0f1999b0
/*  f1945bc:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1945c0:	18400012 */ 	blez	$v0,.L0f19460c
/*  f1945c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f1945c8:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1945cc:	00402825 */ 	or	$a1,$v0,$zero
/*  f1945d0:	0fc6672e */ 	jal	func0f199cb8
/*  f1945d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1945d8:	00409025 */ 	or	$s2,$v0,$zero
/*  f1945dc:	0fc2a63d */ 	jal	func0f0a98f4
/*  f1945e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1945e4:	0242082a */ 	slt	$at,$s2,$v0
/*  f1945e8:	10200008 */ 	beqz	$at,.L0f19460c
/*  f1945ec:	00106880 */ 	sll	$t5,$s0,0x2
/*  f1945f0:	03ad1021 */ 	addu	$v0,$sp,$t5
/*  f1945f4:	8c420178 */ 	lw	$v0,0x178($v0)
/*  f1945f8:	10400004 */ 	beqz	$v0,.L0f19460c
/*  f1945fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f194600:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194604:	10000005 */ 	beqz	$zero,.L0f19461c
/*  f194608:	afaf009c */ 	sw	$t7,0x9c($sp)
.L0f19460c:
/*  f19460c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f194610:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194614:	5621ffe3 */ 	bnel	$s1,$at,.L0f1945a4
/*  f194618:	03c02025 */ 	or	$a0,$s8,$zero
.L0f19461c:
/*  f19461c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194620:	0275082b */ 	sltu	$at,$s3,$s5
/*  f194624:	10200004 */ 	beqz	$at,.L0f194638
/*  f194628:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19462c:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f194630:	5300ffd8 */ 	beqzl	$t8,.L0f194594
/*  f194634:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f194638:
/*  f194638:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f19463c:
/*  f19463c:	8fa200c8 */ 	lw	$v0,0xc8($sp)
/*  f194640:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f194644:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f194648:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f19464c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f194650:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f194654:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f194658:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f19465c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f194660:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f194664:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f194668:	03e00008 */ 	jr	$ra
/*  f19466c:	27bd0278 */ 	addiu	$sp,$sp,0x278
);

bool func0f194670(struct chrdata *chr)
{
	return func0f1937a4(chr, 1) != 0;
}

s32 func0f194694(struct chrdata *chr)
{
	return func0f1937a4(chr, 0);
}

s32 func0f1946b4(struct chrdata *chr)
{
	return func0f1937a4(chr, 2);
}

s32 mpGetNumPlayerTeammates(struct chrdata *chr)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (chr->team == g_MpPlayerChrs[i]->team) {
			count++;
		}
	}

	return count;
}

s32 func0f194724(struct chrdata *self, s32 arg1, bool includeself)
{
	s32 count = 0;
	s32 i;

	for (i = PLAYERCOUNT(); i < g_MpNumPlayers; i++) {
		if (self->team == g_MpPlayerChrs[i]->team) {
			if (includeself || self != g_MpPlayerChrs[i]) {
				if (arg1 == g_MpPlayerChrs[i]->unk2d4->unk79) {
					count++;
				}
			}
		}
	}

	return count;
}

s32 scenarioCtcIsChrsTokenHeld(struct chrdata *chr)
{
	struct mpchr *mpchr = var800ac500[mpPlayerGetIndex(chr)];
	struct prop *prop = g_ScenarioData.ctc.tokens[mpchr->team];

	return prop && (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER);
}

bool func0f19489c(struct chrdata *chr)
{
	if (chr->unk2d4->unk9c_01) {
		if (chr->unk2d4->unk4f_00 == 0 || mpGetNumPlayerTeammates(chr) >= 2 || !scenarioCtcIsChrsTokenHeld(chr)) {
			return true;
		}
	}

	return false;
}

s32 mpGetNumTeammatesInRoomDoingSomething(struct chrdata *bot)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (bot->team == g_MpPlayerChrs[i]->team && g_MpPlayerChrs[i]->prop->rooms[0] == g_ScenarioData.cbt.unk0e[0]) {
			if (g_MpPlayerChrs[i]->unk2d4->unk79 == 9 || g_MpPlayerChrs[i]->unk2d4->unk79 == 10) {
				count++;
			}
		}
	}

	return count;
}

GLOBAL_ASM(
glabel func0f194990
/*  f194990:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f194994:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f194998:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19499c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1949a0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1949a4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1949a8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1949ac:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1949b0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1949b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1949b8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1949bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1949c0:	3c188008 */ 	lui	$t8,%hi(var80087e2c)
/*  f1949c4:	27187e2c */ 	addiu	$t8,$t8,%lo(var80087e2c)
/*  f1949c8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1949cc:	3c1e800b */ 	lui	$s8,0x800b
/*  f1949d0:	8f010000 */ 	lw	$at,0x0($t8)
/*  f1949d4:	8f090004 */ 	lw	$t1,0x4($t8)
/*  f1949d8:	03cef021 */ 	addu	$s8,$s8,$t6
/*  f1949dc:	8fdec500 */ 	lw	$s8,-0x3b00($s8)
/*  f1949e0:	27af0060 */ 	addiu	$t7,$sp,0x60
/*  f1949e4:	ade10000 */ 	sw	$at,0x0($t7)
/*  f1949e8:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f1949ec:	8f09000c */ 	lw	$t1,0xc($t8)
/*  f1949f0:	8f010008 */ 	lw	$at,0x8($t8)
/*  f1949f4:	3c0a800b */ 	lui	$t2,0x800b
/*  f1949f8:	ade9000c */ 	sw	$t1,0xc($t7)
/*  f1949fc:	ade10008 */ 	sw	$at,0x8($t7)
/*  f194a00:	8f010010 */ 	lw	$at,0x10($t8)
/*  f194a04:	8f090014 */ 	lw	$t1,0x14($t8)
/*  f194a08:	3c11800b */ 	lui	$s1,%hi(g_MpPlayerChrs)
/*  f194a0c:	ade10010 */ 	sw	$at,0x10($t7)
/*  f194a10:	ade90014 */ 	sw	$t1,0x14($t7)
/*  f194a14:	8f09001c */ 	lw	$t1,0x1c($t8)
/*  f194a18:	8f010018 */ 	lw	$at,0x18($t8)
/*  f194a1c:	00009025 */ 	or	$s2,$zero,$zero
/*  f194a20:	ade9001c */ 	sw	$t1,0x1c($t7)
/*  f194a24:	ade10018 */ 	sw	$at,0x18($t7)
/*  f194a28:	8d4ac530 */ 	lw	$t2,-0x3ad0($t2)
/*  f194a2c:	2631c4d0 */ 	addiu	$s1,$s1,%lo(g_MpPlayerChrs)
/*  f194a30:	00008025 */ 	or	$s0,$zero,$zero
/*  f194a34:	1940002b */ 	blez	$t2,.L0f194ae4
/*  f194a38:	2417004c */ 	addiu	$s7,$zero,0x4c
/*  f194a3c:	3c16800b */ 	lui	$s6,%hi(g_MpSimulants)
/*  f194a40:	3c14800b */ 	lui	$s4,%hi(g_MpPlayers)
/*  f194a44:	3c13800b */ 	lui	$s3,%hi(g_ScenarioData)
/*  f194a48:	2673c110 */ 	addiu	$s3,$s3,%lo(g_ScenarioData)
/*  f194a4c:	2694c7b8 */ 	addiu	$s4,$s4,%lo(g_MpPlayers)
/*  f194a50:	26d6c538 */ 	addiu	$s6,$s6,%lo(g_MpSimulants)
/*  f194a54:	241500a0 */ 	addiu	$s5,$zero,0xa0
/*  f194a58:	8e2b0000 */ 	lw	$t3,0x0($s1)
.L0f194a5c:
/*  f194a5c:	866e000e */ 	lh	$t6,0xe($s3)
/*  f194a60:	8d6c001c */ 	lw	$t4,0x1c($t3)
/*  f194a64:	858d0028 */ 	lh	$t5,0x28($t4)
/*  f194a68:	15ae0017 */ 	bne	$t5,$t6,.L0f194ac8
/*  f194a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194a70:	0fc6341d */ 	jal	func0f18d074
/*  f194a74:	02002025 */ 	or	$a0,$s0,$zero
/*  f194a78:	28410004 */ 	slti	$at,$v0,0x4
/*  f194a7c:	10200006 */ 	beqz	$at,.L0f194a98
/*  f194a80:	27a90060 */ 	addiu	$t1,$sp,0x60
/*  f194a84:	00550019 */ 	multu	$v0,$s5
/*  f194a88:	00004012 */ 	mflo	$t0
/*  f194a8c:	02881821 */ 	addu	$v1,$s4,$t0
/*  f194a90:	10000006 */ 	beqz	$zero,.L0f194aac
/*  f194a94:	90640011 */ 	lbu	$a0,0x11($v1)
.L0f194a98:
/*  f194a98:	00570019 */ 	multu	$v0,$s7
/*  f194a9c:	0000c812 */ 	mflo	$t9
/*  f194aa0:	02d91821 */ 	addu	$v1,$s6,$t9
/*  f194aa4:	2463fed0 */ 	addiu	$v1,$v1,-304
/*  f194aa8:	90640011 */ 	lbu	$a0,0x11($v1)
.L0f194aac:
/*  f194aac:	93cf0011 */ 	lbu	$t7,0x11($s8)
/*  f194ab0:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f194ab4:	11e40004 */ 	beq	$t7,$a0,.L0f194ac8
/*  f194ab8:	03091021 */ 	addu	$v0,$t8,$t1
/*  f194abc:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f194ac0:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f194ac4:	ac4b0000 */ 	sw	$t3,0x0($v0)
.L0f194ac8:
/*  f194ac8:	3c0c800b */ 	lui	$t4,0x800b
/*  f194acc:	8d8cc530 */ 	lw	$t4,-0x3ad0($t4)
/*  f194ad0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194ad4:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f194ad8:	020c082a */ 	slt	$at,$s0,$t4
/*  f194adc:	5420ffdf */ 	bnezl	$at,.L0f194a5c
/*  f194ae0:	8e2b0000 */ 	lw	$t3,0x0($s1)
.L0f194ae4:
/*  f194ae4:	27a20060 */ 	addiu	$v0,$sp,0x60
/*  f194ae8:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f194aec:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f194af0:
/*  f194af0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f194af4:	0243082a */ 	slt	$at,$s2,$v1
/*  f194af8:	10200002 */ 	beqz	$at,.L0f194b04
/*  f194afc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194b00:	00609025 */ 	or	$s2,$v1,$zero
.L0f194b04:
/*  f194b04:	5444fffa */ 	bnel	$v0,$a0,.L0f194af0
/*  f194b08:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f194b0c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f194b10:	02401025 */ 	or	$v0,$s2,$zero
/*  f194b14:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f194b18:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f194b1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f194b20:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f194b24:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f194b28:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f194b2c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f194b30:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f194b34:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f194b38:	03e00008 */ 	jr	$ra
/*  f194b3c:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel func0f194b40
/*  f194b40:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f194b44:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f194b48:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f194b4c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f194b50:	0080a025 */ 	or	$s4,$a0,$zero
/*  f194b54:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f194b58:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f194b5c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f194b60:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f194b64:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f194b68:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f194b6c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f194b70:	0fc0e6a5 */ 	jal	chrIsDead
/*  f194b74:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f194b78:	14400a66 */ 	bnez	$v0,.L0f197514
/*  f194b7c:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f194b80:	8e9202d4 */ 	lw	$s2,0x2d4($s4)
/*  f194b84:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f194b88:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f194b8c:	8e4e02cc */ 	lw	$t6,0x2cc($s2)
/*  f194b90:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f194b94:	07210017 */ 	bgez	$t9,.L0f194bf4
/*  f194b98:	ae5902cc */ 	sw	$t9,0x2cc($s2)
/*  f194b9c:	0c004b70 */ 	jal	random
/*  f194ba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194ba4:	24013840 */ 	addiu	$at,$zero,0x3840
/*  f194ba8:	0041001b */ 	divu	$zero,$v0,$at
/*  f194bac:	00004810 */ 	mfhi	$t1
/*  f194bb0:	252a0708 */ 	addiu	$t2,$t1,0x708
/*  f194bb4:	0c004b70 */ 	jal	random
/*  f194bb8:	ae4a02cc */ 	sw	$t2,0x2cc($s2)
/*  f194bbc:	0c004b70 */ 	jal	random
/*  f194bc0:	ae4202d0 */ 	sw	$v0,0x2d0($s2)
/*  f194bc4:	44822000 */ 	mtc1	$v0,$f4
/*  f194bc8:	3c014f80 */ 	lui	$at,0x4f80
/*  f194bcc:	04410004 */ 	bgez	$v0,.L0f194be0
/*  f194bd0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f194bd4:	44814000 */ 	mtc1	$at,$f8
/*  f194bd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194bdc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f194be0:
/*  f194be0:	3c012f80 */ 	lui	$at,0x2f80
/*  f194be4:	44815000 */ 	mtc1	$at,$f10
/*  f194be8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194bec:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f194bf0:	e65202d4 */ 	swc1	$f18,0x2d4($s2)
.L0f194bf4:
/*  f194bf4:	00008025 */ 	or	$s0,$zero,$zero
/*  f194bf8:	02403825 */ 	or	$a3,$s2,$zero
.L0f194bfc:
/*  f194bfc:	84e2002c */ 	lh	$v0,0x2c($a3)
/*  f194c00:	5840000f */ 	blezl	$v0,.L0f194c40
/*  f194c04:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f194c08:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f194c0c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194c10:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f194c14:	a4ec002c */ 	sh	$t4,0x2c($a3)
/*  f194c18:	84ed002c */ 	lh	$t5,0x2c($a3)
/*  f194c1c:	5da00037 */ 	bgtzl	$t5,.L0f194cfc
/*  f194c20:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194c24:	02002825 */ 	or	$a1,$s0,$zero
/*  f194c28:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f194c2c:	0fc66690 */ 	jal	func0f199a40
/*  f194c30:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194c34:	10000030 */ 	beqz	$zero,.L0f194cf8
/*  f194c38:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f194c3c:	8e45004c */ 	lw	$a1,0x4c($s2)
.L0f194c40:
/*  f194c40:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f194c44:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194c48:	00057080 */ 	sll	$t6,$a1,0x2
/*  f194c4c:	0fc668a7 */ 	jal	func0f19a29c
/*  f194c50:	000e2fc2 */ 	srl	$a1,$t6,0x1f
/*  f194c54:	14400028 */ 	bnez	$v0,.L0f194cf8
/*  f194c58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f194c5c:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f194c60:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f194c64:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f194c68:	8f230024 */ 	lw	$v1,0x24($t9)
/*  f194c6c:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f194c70:	00054880 */ 	sll	$t1,$a1,0x2
/*  f194c74:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f194c78:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194c7c:	0fc6667e */ 	jal	func0f1999f8
/*  f194c80:	afa302e8 */ 	sw	$v1,0x2e8($sp)
/*  f194c84:	8fa302e8 */ 	lw	$v1,0x2e8($sp)
/*  f194c88:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f194c8c:	1c600008 */ 	bgtz	$v1,.L0f194cb0
/*  f194c90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194c94:	18400006 */ 	blez	$v0,.L0f194cb0
/*  f194c98:	02802025 */ 	or	$a0,$s4,$zero
/*  f194c9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f194ca0:	0fc64da7 */ 	jal	func0f19369c
/*  f194ca4:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194ca8:	10000013 */ 	beqz	$zero,.L0f194cf8
/*  f194cac:	8fa70054 */ 	lw	$a3,0x54($sp)
.L0f194cb0:
/*  f194cb0:	04410003 */ 	bgez	$v0,.L0f194cc0
/*  f194cb4:	00025843 */ 	sra	$t3,$v0,0x1
/*  f194cb8:	24410001 */ 	addiu	$at,$v0,0x1
/*  f194cbc:	00015843 */ 	sra	$t3,$at,0x1
.L0f194cc0:
/*  f194cc0:	006b082a */ 	slt	$at,$v1,$t3
/*  f194cc4:	5020000d */ 	beqzl	$at,.L0f194cfc
/*  f194cc8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194ccc:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f194cd0:	8e4c0124 */ 	lw	$t4,0x124($s2)
/*  f194cd4:	02802025 */ 	or	$a0,$s4,$zero
/*  f194cd8:	25aeff88 */ 	addiu	$t6,$t5,-120
/*  f194cdc:	018e082a */ 	slt	$at,$t4,$t6
/*  f194ce0:	50200006 */ 	beqzl	$at,.L0f194cfc
/*  f194ce4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194ce8:	02002825 */ 	or	$a1,$s0,$zero
/*  f194cec:	0fc64da7 */ 	jal	func0f19369c
/*  f194cf0:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194cf4:	8fa70054 */ 	lw	$a3,0x54($sp)
.L0f194cf8:
/*  f194cf8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f194cfc:
/*  f194cfc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194d00:	1601ffbe */ 	bne	$s0,$at,.L0f194bfc
/*  f194d04:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f194d08:	8e4200cc */ 	lw	$v0,0xcc($s2)
/*  f194d0c:	58400045 */ 	blezl	$v0,.L0f194e24
/*  f194d10:	8e4d0020 */ 	lw	$t5,0x20($s2)
/*  f194d14:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f194d18:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d1c:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f194d20:	1f20003f */ 	bgtz	$t9,.L0f194e20
/*  f194d24:	ae5900cc */ 	sw	$t9,0xcc($s2)
/*  f194d28:	0fc65f3c */ 	jal	func0f197cf0
/*  f194d2c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f194d30:	00408025 */ 	or	$s0,$v0,$zero
/*  f194d34:	0fc4a2bd */ 	jal	func0f128af4
/*  f194d38:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f194d3c:	12000019 */ 	beqz	$s0,.L0f194da4
/*  f194d40:	00408825 */ 	or	$s1,$v0,$zero
/*  f194d44:	04400017 */ 	bltz	$v0,.L0f194da4
/*  f194d48:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d4c:	00402825 */ 	or	$a1,$v0,$zero
/*  f194d50:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f194d54:	0fc22eb4 */ 	jal	func0f08bad0
/*  f194d58:	00003825 */ 	or	$a3,$zero,$zero
/*  f194d5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d60:	00002825 */ 	or	$a1,$zero,$zero
/*  f194d64:	0fc66690 */ 	jal	func0f199a40
/*  f194d68:	00003025 */ 	or	$a2,$zero,$zero
/*  f194d6c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f194d70:	24010003 */ 	addiu	$at,$zero,0x3
/*  f194d74:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d78:	15210008 */ 	bne	$t1,$at,.L0f194d9c
/*  f194d7c:	02202825 */ 	or	$a1,$s1,$zero
/*  f194d80:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f194d84:	0fc22eb4 */ 	jal	func0f08bad0
/*  f194d88:	3c071000 */ 	lui	$a3,0x1000
/*  f194d8c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d90:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f194d94:	0fc66690 */ 	jal	func0f199a40
/*  f194d98:	00003025 */ 	or	$a2,$zero,$zero
.L0f194d9c:
/*  f194d9c:	1000000e */ 	beqz	$zero,.L0f194dd8
/*  f194da0:	ae400034 */ 	sw	$zero,0x34($s2)
.L0f194da4:
/*  f194da4:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f194da8:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f194dac:	ad570020 */ 	sw	$s7,0x20($t2)
/*  f194db0:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f194db4:	906b004c */ 	lbu	$t3,0x4c($v1)
/*  f194db8:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f194dbc:	a06d004c */ 	sb	$t5,0x4c($v1)
/*  f194dc0:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f194dc4:	906c004c */ 	lbu	$t4,0x4c($v1)
/*  f194dc8:	318effbf */ 	andi	$t6,$t4,0xffbf
/*  f194dcc:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f194dd0:	a06f004c */ 	sb	$t7,0x4c($v1)
/*  f194dd4:	ae400034 */ 	sw	$zero,0x34($s2)
.L0f194dd8:
/*  f194dd8:	02401025 */ 	or	$v0,$s2,$zero
/*  f194ddc:	00001825 */ 	or	$v1,$zero,$zero
/*  f194de0:	02802025 */ 	or	$a0,$s4,$zero
/*  f194de4:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f194de8:
/*  f194de8:	a440003c */ 	sh	$zero,0x3c($v0)
/*  f194dec:	8c850170 */ 	lw	$a1,0x170($a0)
/*  f194df0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f194df4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f194df8:	10a00007 */ 	beqz	$a1,.L0f194e18
/*  f194dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194e00:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f194e04:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f194e08:	8f19004c */ 	lw	$t9,0x4c($t8)
/*  f194e0c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f194e10:	000957c2 */ 	srl	$t2,$t1,0x1f
/*  f194e14:	a16a005f */ 	sb	$t2,0x5f($t3)
.L0f194e18:
/*  f194e18:	1466fff3 */ 	bne	$v1,$a2,.L0f194de8
/*  f194e1c:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f194e20:
/*  f194e20:	8e4d0020 */ 	lw	$t5,0x20($s2)
.L0f194e24:
/*  f194e24:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f194e28:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f194e2c:	55a10005 */ 	bnel	$t5,$at,.L0f194e44
/*  f194e30:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f194e34:	8e8e02d4 */ 	lw	$t6,0x2d4($s4)
/*  f194e38:	240c03e7 */ 	addiu	$t4,$zero,0x3e7
/*  f194e3c:	adcc0024 */ 	sw	$t4,0x24($t6)
/*  f194e40:	8e4f001c */ 	lw	$t7,0x1c($s2)
.L0f194e44:
/*  f194e44:	8df80050 */ 	lw	$t8,0x50($t7)
/*  f194e48:	1b00000d */ 	blez	$t8,.L0f194e80
/*  f194e4c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194e50:	0fc6458e */ 	jal	func0f191638
/*  f194e54:	02e02825 */ 	or	$a1,$s7,$zero
/*  f194e58:	54400006 */ 	bnezl	$v0,.L0f194e74
/*  f194e5c:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f194e60:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f194e64:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f194e68:	57210006 */ 	bnel	$t9,$at,.L0f194e84
/*  f194e6c:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f194e70:	924a004c */ 	lbu	$t2,0x4c($s2)
.L0f194e74:
/*  f194e74:	354b0002 */ 	ori	$t3,$t2,0x2
/*  f194e78:	1000001e */ 	beqz	$zero,.L0f194ef4
/*  f194e7c:	a24b004c */ 	sb	$t3,0x4c($s2)
.L0f194e80:
/*  f194e80:	8e420210 */ 	lw	$v0,0x210($s2)
.L0f194e84:
/*  f194e84:	240404b0 */ 	addiu	$a0,$zero,0x4b0
/*  f194e88:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f194e8c:	00026142 */ 	srl	$t4,$v0,0x5
/*  f194e90:	0184001b */ 	divu	$zero,$t4,$a0
/*  f194e94:	8da30050 */ 	lw	$v1,0x50($t5)
/*  f194e98:	00007010 */ 	mfhi	$t6
/*  f194e9c:	25cf04b0 */ 	addiu	$t7,$t6,0x4b0
/*  f194ea0:	14800002 */ 	bnez	$a0,.L0f194eac
/*  f194ea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194ea8:	0007000d */ 	break	0x7
.L0f194eac:
/*  f194eac:	01e3082b */ 	sltu	$at,$t7,$v1
/*  f194eb0:	10200005 */ 	beqz	$at,.L0f194ec8
/*  f194eb4:	00025442 */ 	srl	$t2,$v0,0x11
/*  f194eb8:	9259004c */ 	lbu	$t9,0x4c($s2)
/*  f194ebc:	37290002 */ 	ori	$t1,$t9,0x2
/*  f194ec0:	1000000c */ 	beqz	$zero,.L0f194ef4
/*  f194ec4:	a249004c */ 	sb	$t1,0x4c($s2)
.L0f194ec8:
/*  f194ec8:	0144001b */ 	divu	$zero,$t2,$a0
/*  f194ecc:	00005810 */ 	mfhi	$t3
/*  f194ed0:	0163082b */ 	sltu	$at,$t3,$v1
/*  f194ed4:	14800002 */ 	bnez	$a0,.L0f194ee0
/*  f194ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f194edc:	0007000d */ 	break	0x7
.L0f194ee0:
/*  f194ee0:	54200005 */ 	bnezl	$at,.L0f194ef8
/*  f194ee4:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f194ee8:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f194eec:	31acfffd */ 	andi	$t4,$t5,0xfffd
/*  f194ef0:	a24c004c */ 	sb	$t4,0x4c($s2)
.L0f194ef4:
/*  f194ef4:	8e4e004c */ 	lw	$t6,0x4c($s2)
.L0f194ef8:
/*  f194ef8:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f194efc:	07020039 */ 	bltzl	$t8,.L0f194fe4
/*  f194f00:	924b009c */ 	lbu	$t3,0x9c($s2)
/*  f194f04:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f194f08:	2401000d */ 	addiu	$at,$zero,0xd
/*  f194f0c:	02402025 */ 	or	$a0,$s2,$zero
/*  f194f10:	17210033 */ 	bne	$t9,$at,.L0f194fe0
/*  f194f14:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f194f18:	00003025 */ 	or	$a2,$zero,$zero
/*  f194f1c:	0fc666f9 */ 	jal	func0f199be4
/*  f194f20:	02e03825 */ 	or	$a3,$s7,$zero
/*  f194f24:	00408025 */ 	or	$s0,$v0,$zero
/*  f194f28:	02802025 */ 	or	$a0,$s4,$zero
/*  f194f2c:	0fc6458e */ 	jal	func0f191638
/*  f194f30:	02e02825 */ 	or	$a1,$s7,$zero
/*  f194f34:	5040001a */ 	beqzl	$v0,.L0f194fa0
/*  f194f38:	8e4b0210 */ 	lw	$t3,0x210($s2)
/*  f194f3c:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f194f40:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f194f44:	00024982 */ 	srl	$t1,$v0,0x6
/*  f194f48:	0121001b */ 	divu	$zero,$t1,$at
/*  f194f4c:	00005010 */ 	mfhi	$t2
/*  f194f50:	254b00c8 */ 	addiu	$t3,$t2,0xc8
/*  f194f54:	0170082b */ 	sltu	$at,$t3,$s0
/*  f194f58:	10200005 */ 	beqz	$at,.L0f194f70
/*  f194f5c:	00027c02 */ 	srl	$t7,$v0,0x10
/*  f194f60:	924c009c */ 	lbu	$t4,0x9c($s2)
/*  f194f64:	358e0020 */ 	ori	$t6,$t4,0x20
/*  f194f68:	10000020 */ 	beqz	$zero,.L0f194fec
/*  f194f6c:	a24e009c */ 	sb	$t6,0x9c($s2)
.L0f194f70:
/*  f194f70:	24010046 */ 	addiu	$at,$zero,0x46
/*  f194f74:	01e1001b */ 	divu	$zero,$t7,$at
/*  f194f78:	0000c010 */ 	mfhi	$t8
/*  f194f7c:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f194f80:	0330082b */ 	sltu	$at,$t9,$s0
/*  f194f84:	5420001a */ 	bnezl	$at,.L0f194ff0
/*  f194f88:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f194f8c:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f194f90:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f194f94:	10000015 */ 	beqz	$zero,.L0f194fec
/*  f194f98:	a24a009c */ 	sb	$t2,0x9c($s2)
/*  f194f9c:	8e4b0210 */ 	lw	$t3,0x210($s2)
.L0f194fa0:
/*  f194fa0:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f194fa4:	000b6b02 */ 	srl	$t5,$t3,0xc
/*  f194fa8:	01a1001b */ 	divu	$zero,$t5,$at
/*  f194fac:	00006010 */ 	mfhi	$t4
/*  f194fb0:	258e012c */ 	addiu	$t6,$t4,0x12c
/*  f194fb4:	01d0082b */ 	sltu	$at,$t6,$s0
/*  f194fb8:	50200006 */ 	beqzl	$at,.L0f194fd4
/*  f194fbc:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f194fc0:	9258009c */ 	lbu	$t8,0x9c($s2)
/*  f194fc4:	37190020 */ 	ori	$t9,$t8,0x20
/*  f194fc8:	10000008 */ 	beqz	$zero,.L0f194fec
/*  f194fcc:	a259009c */ 	sb	$t9,0x9c($s2)
/*  f194fd0:	9249009c */ 	lbu	$t1,0x9c($s2)
.L0f194fd4:
/*  f194fd4:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f194fd8:	10000004 */ 	beqz	$zero,.L0f194fec
/*  f194fdc:	a24a009c */ 	sb	$t2,0x9c($s2)
.L0f194fe0:
/*  f194fe0:	924b009c */ 	lbu	$t3,0x9c($s2)
.L0f194fe4:
/*  f194fe4:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f194fe8:	a24d009c */ 	sb	$t5,0x9c($s2)
.L0f194fec:
/*  f194fec:	8e4c0004 */ 	lw	$t4,0x4($s2)
.L0f194ff0:
/*  f194ff0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f194ff4:	918e0047 */ 	lbu	$t6,0x47($t4)
/*  f194ff8:	55c1000e */ 	bnel	$t6,$at,.L0f195034
/*  f194ffc:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f195000:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f195004:	241effff */ 	addiu	$s8,$zero,-1
/*  f195008:	53cf000a */ 	beql	$s8,$t7,.L0f195034
/*  f19500c:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f195010:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f195014:	53000007 */ 	beqzl	$t8,.L0f195034
/*  f195018:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f19501c:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f195020:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f195024:	53210003 */ 	beql	$t9,$at,.L0f195034
/*  f195028:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f19502c:	ae5700d8 */ 	sw	$s7,0xd8($s2)
/*  f195030:	824a004f */ 	lb	$t2,0x4f($s2)
.L0f195034:
/*  f195034:	241effff */ 	addiu	$s8,$zero,-1
/*  f195038:	05430143 */ 	bgezl	$t2,.L0f195548
/*  f19503c:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f195040:	8e420118 */ 	lw	$v0,0x118($s2)
/*  f195044:	18400005 */ 	blez	$v0,.L0f19505c
/*  f195048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19504c:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f195050:	004b6823 */ 	subu	$t5,$v0,$t3
/*  f195054:	ae4d0118 */ 	sw	$t5,0x118($s2)
/*  f195058:	01a01025 */ 	or	$v0,$t5,$zero
.L0f19505c:
/*  f19505c:	5c40013a */ 	bgtzl	$v0,.L0f195548
/*  f195060:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f195064:	0fc651b5 */ 	jal	mpGetNumPlayerTeammates
/*  f195068:	02802025 */ 	or	$a0,$s4,$zero
/*  f19506c:	3c03800b */ 	lui	$v1,0x800b
/*  f195070:	9063cb98 */ 	lbu	$v1,-0x3468($v1)
/*  f195074:	00409825 */ 	or	$s3,$v0,$zero
/*  f195078:	02802025 */ 	or	$a0,$s4,$zero
/*  f19507c:	16e3001e */ 	bne	$s7,$v1,.L0f1950f8
/*  f195080:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195084:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f195088:	0fc651c9 */ 	jal	func0f194724
/*  f19508c:	00003025 */ 	or	$a2,$zero,$zero
/*  f195090:	18400010 */ 	blez	$v0,.L0f1950d4
/*  f195094:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f195098:	05810003 */ 	bgez	$t4,.L0f1950a8
/*  f19509c:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f1950a0:	25810001 */ 	addiu	$at,$t4,0x1
/*  f1950a4:	00017043 */ 	sra	$t6,$at,0x1
.L0f1950a8:
/*  f1950a8:	004e082a */ 	slt	$at,$v0,$t6
/*  f1950ac:	5420000a */ 	bnezl	$at,.L0f1950d8
/*  f1950b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1950b4:	0c004b70 */ 	jal	random
/*  f1950b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1950bc:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1950c0:	0041001b */ 	divu	$zero,$v0,$at
/*  f1950c4:	00007810 */ 	mfhi	$t7
/*  f1950c8:	2de10042 */ 	sltiu	$at,$t7,0x42
/*  f1950cc:	10200006 */ 	beqz	$at,.L0f1950e8
/*  f1950d0:	02802025 */ 	or	$a0,$s4,$zero
.L0f1950d4:
/*  f1950d4:	02802025 */ 	or	$a0,$s4,$zero
.L0f1950d8:
/*  f1950d8:	0fc64984 */ 	jal	func0f192610
/*  f1950dc:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f1950e0:	10000111 */ 	beqz	$zero,.L0f195528
/*  f1950e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1950e8:
/*  f1950e8:	0fc64984 */ 	jal	func0f192610
/*  f1950ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1950f0:	1000010d */ 	beqz	$zero,.L0f195528
/*  f1950f4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1950f8:
/*  f1950f8:	14610022 */ 	bne	$v1,$at,.L0f195184
/*  f1950fc:	02802025 */ 	or	$a0,$s4,$zero
/*  f195100:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f195104:	0fc651c9 */ 	jal	func0f194724
/*  f195108:	00003025 */ 	or	$a2,$zero,$zero
/*  f19510c:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f195110:	00184940 */ 	sll	$t1,$t8,0x5
/*  f195114:	05220013 */ 	bltzl	$t1,.L0f195164
/*  f195118:	02802025 */ 	or	$a0,$s4,$zero
/*  f19511c:	18400010 */ 	blez	$v0,.L0f195160
/*  f195120:	266a0001 */ 	addiu	$t2,$s3,0x1
/*  f195124:	05410003 */ 	bgez	$t2,.L0f195134
/*  f195128:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f19512c:	25410001 */ 	addiu	$at,$t2,0x1
/*  f195130:	00015843 */ 	sra	$t3,$at,0x1
.L0f195134:
/*  f195134:	004b082a */ 	slt	$at,$v0,$t3
/*  f195138:	5420000a */ 	bnezl	$at,.L0f195164
/*  f19513c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195140:	0c004b70 */ 	jal	random
/*  f195144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195148:	24010064 */ 	addiu	$at,$zero,0x64
/*  f19514c:	0041001b */ 	divu	$zero,$v0,$at
/*  f195150:	00006810 */ 	mfhi	$t5
/*  f195154:	2da10032 */ 	sltiu	$at,$t5,0x32
/*  f195158:	10200006 */ 	beqz	$at,.L0f195174
/*  f19515c:	02802025 */ 	or	$a0,$s4,$zero
.L0f195160:
/*  f195160:	02802025 */ 	or	$a0,$s4,$zero
.L0f195164:
/*  f195164:	0fc64984 */ 	jal	func0f192610
/*  f195168:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f19516c:	100000ee */ 	beqz	$zero,.L0f195528
/*  f195170:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195174:
/*  f195174:	0fc64984 */ 	jal	func0f192610
/*  f195178:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19517c:	100000ea */ 	beqz	$zero,.L0f195528
/*  f195180:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195184:
/*  f195184:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195188:	1461001e */ 	bne	$v1,$at,.L0f195204
/*  f19518c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195190:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f195194:	0fc651c9 */ 	jal	func0f194724
/*  f195198:	00003025 */ 	or	$a2,$zero,$zero
/*  f19519c:	18400010 */ 	blez	$v0,.L0f1951e0
/*  f1951a0:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f1951a4:	05810003 */ 	bgez	$t4,.L0f1951b4
/*  f1951a8:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f1951ac:	25810001 */ 	addiu	$at,$t4,0x1
/*  f1951b0:	00017043 */ 	sra	$t6,$at,0x1
.L0f1951b4:
/*  f1951b4:	004e082a */ 	slt	$at,$v0,$t6
/*  f1951b8:	5420000a */ 	bnezl	$at,.L0f1951e4
/*  f1951bc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1951c0:	0c004b70 */ 	jal	random
/*  f1951c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1951c8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1951cc:	0041001b */ 	divu	$zero,$v0,$at
/*  f1951d0:	00007810 */ 	mfhi	$t7
/*  f1951d4:	2de10032 */ 	sltiu	$at,$t7,0x32
/*  f1951d8:	10200006 */ 	beqz	$at,.L0f1951f4
/*  f1951dc:	02802025 */ 	or	$a0,$s4,$zero
.L0f1951e0:
/*  f1951e0:	02802025 */ 	or	$a0,$s4,$zero
.L0f1951e4:
/*  f1951e4:	0fc64984 */ 	jal	func0f192610
/*  f1951e8:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f1951ec:	100000ce */ 	beqz	$zero,.L0f195528
/*  f1951f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1951f4:
/*  f1951f4:	0fc64984 */ 	jal	func0f192610
/*  f1951f8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1951fc:	100000ca */ 	beqz	$zero,.L0f195528
/*  f195200:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195204:
/*  f195204:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195208:	54610034 */ 	bnel	$v1,$at,.L0f1952dc
/*  f19520c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195210:	0fc65241 */ 	jal	mpGetNumTeammatesInRoomDoingSomething
/*  f195214:	02802025 */ 	or	$a0,$s4,$zero
/*  f195218:	8e98001c */ 	lw	$t8,0x1c($s4)
/*  f19521c:	3c09800b */ 	lui	$t1,0x800b
/*  f195220:	8529c11e */ 	lh	$t1,-0x3ee2($t1)
/*  f195224:	87190028 */ 	lh	$t9,0x28($t8)
/*  f195228:	00408025 */ 	or	$s0,$v0,$zero
/*  f19522c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195230:	17290002 */ 	bne	$t9,$t1,.L0f19523c
/*  f195234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195238:	2450ffff */ 	addiu	$s0,$v0,-1
.L0f19523c:
/*  f19523c:	1a000008 */ 	blez	$s0,.L0f195260
/*  f195240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195244:	06610003 */ 	bgez	$s3,.L0f195254
/*  f195248:	00135043 */ 	sra	$t2,$s3,0x1
/*  f19524c:	26610001 */ 	addiu	$at,$s3,0x1
/*  f195250:	00015043 */ 	sra	$t2,$at,0x1
.L0f195254:
/*  f195254:	020a082a */ 	slt	$at,$s0,$t2
/*  f195258:	10200005 */ 	beqz	$at,.L0f195270
/*  f19525c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195260:
/*  f195260:	0fc64984 */ 	jal	func0f192610
/*  f195264:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f195268:	100000af */ 	beqz	$zero,.L0f195528
/*  f19526c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195270:
/*  f195270:	0fc65264 */ 	jal	func0f194990
/*  f195274:	02802025 */ 	or	$a0,$s4,$zero
/*  f195278:	0050082a */ 	slt	$at,$v0,$s0
/*  f19527c:	10200012 */ 	beqz	$at,.L0f1952c8
/*  f195280:	02802025 */ 	or	$a0,$s4,$zero
/*  f195284:	0c004b70 */ 	jal	random
/*  f195288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19528c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195290:	0041001b */ 	divu	$zero,$v0,$at
/*  f195294:	00005810 */ 	mfhi	$t3
/*  f195298:	2d610032 */ 	sltiu	$at,$t3,0x32
/*  f19529c:	10200006 */ 	beqz	$at,.L0f1952b8
/*  f1952a0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952a4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952a8:	0fc64984 */ 	jal	func0f192610
/*  f1952ac:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1952b0:	1000009d */ 	beqz	$zero,.L0f195528
/*  f1952b4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1952b8:
/*  f1952b8:	0fc64984 */ 	jal	func0f192610
/*  f1952bc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1952c0:	10000099 */ 	beqz	$zero,.L0f195528
/*  f1952c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1952c8:
/*  f1952c8:	0fc64984 */ 	jal	func0f192610
/*  f1952cc:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f1952d0:	10000095 */ 	beqz	$zero,.L0f195528
/*  f1952d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1952d8:	24010005 */ 	addiu	$at,$zero,0x5
.L0f1952dc:
/*  f1952dc:	14610092 */ 	bne	$v1,$at,.L0f195528
/*  f1952e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1952e4:	14570035 */ 	bne	$v0,$s7,.L0f1953bc
/*  f1952e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952f0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1952f4:	0fc651c9 */ 	jal	func0f194724
/*  f1952f8:	02e03025 */ 	or	$a2,$s7,$zero
/*  f1952fc:	00408025 */ 	or	$s0,$v0,$zero
/*  f195300:	0fc65227 */ 	jal	func0f19489c
/*  f195304:	02802025 */ 	or	$a0,$s4,$zero
/*  f195308:	10400005 */ 	beqz	$v0,.L0f195320
/*  f19530c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195310:	0fc64984 */ 	jal	func0f192610
/*  f195314:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f195318:	10000083 */ 	beqz	$zero,.L0f195528
/*  f19531c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195320:
/*  f195320:	0fc6520d */ 	jal	scenarioCtcIsChrsTokenHeld
/*  f195324:	02802025 */ 	or	$a0,$s4,$zero
/*  f195328:	10400012 */ 	beqz	$v0,.L0f195374
/*  f19532c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195330:	0c004b70 */ 	jal	random
/*  f195334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195338:	24010064 */ 	addiu	$at,$zero,0x64
/*  f19533c:	0041001b */ 	divu	$zero,$v0,$at
/*  f195340:	00006810 */ 	mfhi	$t5
/*  f195344:	2da1001e */ 	sltiu	$at,$t5,0x1e
/*  f195348:	10200006 */ 	beqz	$at,.L0f195364
/*  f19534c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195350:	02802025 */ 	or	$a0,$s4,$zero
/*  f195354:	0fc64984 */ 	jal	func0f192610
/*  f195358:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f19535c:	10000072 */ 	beqz	$zero,.L0f195528
/*  f195360:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195364:
/*  f195364:	0fc64984 */ 	jal	func0f192610
/*  f195368:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f19536c:	1000006e */ 	beqz	$zero,.L0f195528
/*  f195370:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195374:
/*  f195374:	0c004b70 */ 	jal	random
/*  f195378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19537c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195380:	0041001b */ 	divu	$zero,$v0,$at
/*  f195384:	00006010 */ 	mfhi	$t4
/*  f195388:	2d810046 */ 	sltiu	$at,$t4,0x46
/*  f19538c:	14200003 */ 	bnez	$at,.L0f19539c
/*  f195390:	02802025 */ 	or	$a0,$s4,$zero
/*  f195394:	1e000005 */ 	bgtz	$s0,.L0f1953ac
/*  f195398:	24050008 */ 	addiu	$a1,$zero,0x8
.L0f19539c:
/*  f19539c:	0fc64984 */ 	jal	func0f192610
/*  f1953a0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1953a4:	10000060 */ 	beqz	$zero,.L0f195528
/*  f1953a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1953ac:
/*  f1953ac:	0fc64984 */ 	jal	func0f192610
/*  f1953b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953b4:	1000005c */ 	beqz	$zero,.L0f195528
/*  f1953b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1953bc:
/*  f1953bc:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1953c0:	0fc651c9 */ 	jal	func0f194724
/*  f1953c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1953c8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1953cc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953d0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1953d4:	0fc651c9 */ 	jal	func0f194724
/*  f1953d8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1953dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f1953e0:	0fc65227 */ 	jal	func0f19489c
/*  f1953e4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953e8:	10400005 */ 	beqz	$v0,.L0f195400
/*  f1953ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953f0:	0fc64984 */ 	jal	func0f192610
/*  f1953f4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1953f8:	1000004b */ 	beqz	$zero,.L0f195528
/*  f1953fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195400:
/*  f195400:	0fc6520d */ 	jal	scenarioCtcIsChrsTokenHeld
/*  f195404:	02802025 */ 	or	$a0,$s4,$zero
/*  f195408:	10400014 */ 	beqz	$v0,.L0f19545c
/*  f19540c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195410:	5a00000a */ 	blezl	$s0,.L0f19543c
/*  f195414:	02802025 */ 	or	$a0,$s4,$zero
/*  f195418:	0c004b70 */ 	jal	random
/*  f19541c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195420:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195424:	0041001b */ 	divu	$zero,$v0,$at
/*  f195428:	00007010 */ 	mfhi	$t6
/*  f19542c:	2dc10046 */ 	sltiu	$at,$t6,0x46
/*  f195430:	10200006 */ 	beqz	$at,.L0f19544c
/*  f195434:	02802025 */ 	or	$a0,$s4,$zero
/*  f195438:	02802025 */ 	or	$a0,$s4,$zero
.L0f19543c:
/*  f19543c:	0fc64984 */ 	jal	func0f192610
/*  f195440:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f195444:	10000038 */ 	beqz	$zero,.L0f195528
/*  f195448:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19544c:
/*  f19544c:	0fc64984 */ 	jal	func0f192610
/*  f195450:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f195454:	10000034 */ 	beqz	$zero,.L0f195528
/*  f195458:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19545c:
/*  f19545c:	1a200005 */ 	blez	$s1,.L0f195474
/*  f195460:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195464:	0261001a */ 	div	$zero,$s3,$at
/*  f195468:	00007812 */ 	mflo	$t7
/*  f19546c:	022f082a */ 	slt	$at,$s1,$t7
/*  f195470:	10200005 */ 	beqz	$at,.L0f195488
.L0f195474:
/*  f195474:	02802025 */ 	or	$a0,$s4,$zero
/*  f195478:	0fc64984 */ 	jal	func0f192610
/*  f19547c:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f195480:	10000029 */ 	beqz	$zero,.L0f195528
/*  f195484:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195488:
/*  f195488:	1a000008 */ 	blez	$s0,.L0f1954ac
/*  f19548c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195490:	06610003 */ 	bgez	$s3,.L0f1954a0
/*  f195494:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f195498:	26610003 */ 	addiu	$at,$s3,0x3
/*  f19549c:	0001c083 */ 	sra	$t8,$at,0x2
.L0f1954a0:
/*  f1954a0:	0218082a */ 	slt	$at,$s0,$t8
/*  f1954a4:	10200005 */ 	beqz	$at,.L0f1954bc
/*  f1954a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1954ac:
/*  f1954ac:	0fc64984 */ 	jal	func0f192610
/*  f1954b0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1954b4:	1000001c */ 	beqz	$zero,.L0f195528
/*  f1954b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1954bc:
/*  f1954bc:	0c004b70 */ 	jal	random
/*  f1954c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1954c4:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1954c8:	0041001b */ 	divu	$zero,$v0,$at
/*  f1954cc:	0000c810 */ 	mfhi	$t9
/*  f1954d0:	2f21001e */ 	sltiu	$at,$t9,0x1e
/*  f1954d4:	10200005 */ 	beqz	$at,.L0f1954ec
/*  f1954d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1954dc:	0fc64984 */ 	jal	func0f192610
/*  f1954e0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1954e4:	10000010 */ 	beqz	$zero,.L0f195528
/*  f1954e8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1954ec:
/*  f1954ec:	0c004b70 */ 	jal	random
/*  f1954f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1954f4:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1954f8:	0041001b */ 	divu	$zero,$v0,$at
/*  f1954fc:	00004810 */ 	mfhi	$t1
/*  f195500:	2d21001e */ 	sltiu	$at,$t1,0x1e
/*  f195504:	10200006 */ 	beqz	$at,.L0f195520
/*  f195508:	02802025 */ 	or	$a0,$s4,$zero
/*  f19550c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195510:	0fc64984 */ 	jal	func0f192610
/*  f195514:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f195518:	10000003 */ 	beqz	$zero,.L0f195528
/*  f19551c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f195520:
/*  f195520:	0fc64984 */ 	jal	func0f192610
/*  f195524:	24050004 */ 	addiu	$a1,$zero,0x4
.L0f195528:
/*  f195528:	0c004b70 */ 	jal	random
/*  f19552c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195530:	24010960 */ 	addiu	$at,$zero,0x960
/*  f195534:	0041001b */ 	divu	$zero,$v0,$at
/*  f195538:	00005010 */ 	mfhi	$t2
/*  f19553c:	254b04b0 */ 	addiu	$t3,$t2,0x4b0
/*  f195540:	ae4b0118 */ 	sw	$t3,0x118($s2)
/*  f195544:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
.L0f195548:
/*  f195548:	24010029 */ 	addiu	$at,$zero,0x29
/*  f19554c:	51a10005 */ 	beql	$t5,$at,.L0f195564
/*  f195550:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f195554:	8e4c00d8 */ 	lw	$t4,0xd8($s2)
/*  f195558:	11800398 */ 	beqz	$t4,.L0f1963bc
/*  f19555c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195560:	8e4e0004 */ 	lw	$t6,0x4($s2)
.L0f195564:
/*  f195564:	ae4000d8 */ 	sw	$zero,0xd8($s2)
/*  f195568:	a65e0008 */ 	sh	$s8,0x8($s2)
/*  f19556c:	91cf0047 */ 	lbu	$t7,0x47($t6)
/*  f195570:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195574:	15e1000e */ 	bne	$t7,$at,.L0f1955b0
/*  f195578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19557c:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f195580:	13d8000b */ 	beq	$s8,$t8,.L0f1955b0
/*  f195584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195588:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f19558c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195590:	13200007 */ 	beqz	$t9,.L0f1955b0
/*  f195594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195598:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19559c:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f1955a0:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1955a4:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1955a8:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1955ac:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f1955b0:
/*  f1955b0:	06a10006 */ 	bgez	$s5,.L0f1955cc
/*  f1955b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1955b8:	0fc651a5 */ 	jal	func0f194694
/*  f1955bc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1955c0:	10400002 */ 	beqz	$v0,.L0f1955cc
/*  f1955c4:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f1955c8:	2415002a */ 	addiu	$s5,$zero,0x2a
.L0f1955cc:
/*  f1955cc:	06a10240 */ 	bgez	$s5,.L0f195ed0
/*  f1955d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1955d4:	92420079 */ 	lbu	$v0,0x79($s2)
/*  f1955d8:	16e20019 */ 	bne	$s7,$v0,.L0f195640
/*  f1955dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1955e0:	8e4900c0 */ 	lw	$t1,0xc0($s2)
/*  f1955e4:	8ecb0338 */ 	lw	$t3,0x338($s6)
/*  f1955e8:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1955ec:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1955f0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1955f4:	014b6821 */ 	addu	$t5,$t2,$t3
/*  f1955f8:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f1955fc:	0fc0e6a5 */ 	jal	chrIsDead
/*  f195600:	02002025 */ 	or	$a0,$s0,$zero
/*  f195604:	14400232 */ 	bnez	$v0,.L0f195ed0
/*  f195608:	02802025 */ 	or	$a0,$s4,$zero
/*  f19560c:	0fc64a53 */ 	jal	func0f19294c
/*  f195610:	02002825 */ 	or	$a1,$s0,$zero
/*  f195614:	1440022e */ 	bnez	$v0,.L0f195ed0
/*  f195618:	02802025 */ 	or	$a0,$s4,$zero
/*  f19561c:	0fc64b70 */ 	jal	func0f192dc0
/*  f195620:	02002825 */ 	or	$a1,$s0,$zero
/*  f195624:	1040022a */ 	beqz	$v0,.L0f195ed0
/*  f195628:	02002025 */ 	or	$a0,$s0,$zero
/*  f19562c:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195630:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195634:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195638:	10000225 */ 	beqz	$zero,.L0f195ed0
/*  f19563c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f195640:
/*  f195640:	1440000d */ 	bnez	$v0,.L0f195678
/*  f195644:	2401000d */ 	addiu	$at,$zero,0xd
/*  f195648:	8e4c00d4 */ 	lw	$t4,0xd4($s2)
/*  f19564c:	ae5701e0 */ 	sw	$s7,0x1e0($s2)
/*  f195650:	8ecf0338 */ 	lw	$t7,0x338($s6)
/*  f195654:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f195658:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f19565c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f195660:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f195664:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195668:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f19566c:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f195670:	10000217 */ 	beqz	$zero,.L0f195ed0
/*  f195674:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195678:
/*  f195678:	5441000e */ 	bnel	$v0,$at,.L0f1956b4
/*  f19567c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195680:	8e5900d4 */ 	lw	$t9,0xd4($s2)
/*  f195684:	ae4001e0 */ 	sw	$zero,0x1e0($s2)
/*  f195688:	8eca0338 */ 	lw	$t2,0x338($s6)
/*  f19568c:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f195690:	01394821 */ 	addu	$t1,$t1,$t9
/*  f195694:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f195698:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f19569c:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f1956a0:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1956a4:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f1956a8:	10000209 */ 	beqz	$zero,.L0f195ed0
/*  f1956ac:	a642000a */ 	sh	$v0,0xa($s2)
/*  f1956b0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f1956b4:
/*  f1956b4:	54410005 */ 	bnel	$v0,$at,.L0f1956cc
/*  f1956b8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1956bc:	24150033 */ 	addiu	$s5,$zero,0x33
/*  f1956c0:	10000203 */ 	beqz	$zero,.L0f195ed0
/*  f1956c4:	ae5701dc */ 	sw	$s7,0x1dc($s2)
/*  f1956c8:	24010003 */ 	addiu	$at,$zero,0x3
.L0f1956cc:
/*  f1956cc:	54410005 */ 	bnel	$v0,$at,.L0f1956e4
/*  f1956d0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1956d4:	24150033 */ 	addiu	$s5,$zero,0x33
/*  f1956d8:	100001fd */ 	beqz	$zero,.L0f195ed0
/*  f1956dc:	ae4001dc */ 	sw	$zero,0x1dc($s2)
/*  f1956e0:	24010006 */ 	addiu	$at,$zero,0x6
.L0f1956e4:
/*  f1956e4:	14410089 */ 	bne	$v0,$at,.L0f19590c
/*  f1956e8:	3c0d800b */ 	lui	$t5,0x800b
/*  f1956ec:	91adcb98 */ 	lbu	$t5,-0x3468($t5)
/*  f1956f0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1956f4:	15a10083 */ 	bne	$t5,$at,.L0f195904
/*  f1956f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1956fc:	8e4c009c */ 	lw	$t4,0x9c($s2)
/*  f195700:	000c7840 */ 	sll	$t7,$t4,0x1
/*  f195704:	05e0007f */ 	bltz	$t7,.L0f195904
/*  f195708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19570c:	0fc63a5a */ 	jal	teamGetIndex
/*  f195710:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f195714:	3c07800b */ 	lui	$a3,%hi(g_ScenarioData)
/*  f195718:	00003025 */ 	or	$a2,$zero,$zero
/*  f19571c:	24e7c110 */ 	addiu	$a3,$a3,%lo(g_ScenarioData)
/*  f195720:	00002825 */ 	or	$a1,$zero,$zero
/*  f195724:	27b00298 */ 	addiu	$s0,$sp,0x298
/*  f195728:	24080003 */ 	addiu	$t0,$zero,0x3
.L0f19572c:
/*  f19572c:	10a20020 */ 	beq	$a1,$v0,.L0f1957b0
/*  f195730:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f195734:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f195738:	87290000 */ 	lh	$t1,0x0($t9)
/*  f19573c:	00055080 */ 	sll	$t2,$a1,0x2
/*  f195740:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f195744:	5120001b */ 	beqzl	$t1,.L0f1957b4
/*  f195748:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f19574c:	8d640058 */ 	lw	$a0,0x58($t3)
/*  f195750:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195754:	00066880 */ 	sll	$t5,$a2,0x2
/*  f195758:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f19575c:	020d6021 */ 	addu	$t4,$s0,$t5
/*  f195760:	50610004 */ 	beql	$v1,$at,.L0f195774
/*  f195764:	ad840000 */ 	sw	$a0,0x0($t4)
/*  f195768:	16e30004 */ 	bne	$s7,$v1,.L0f19577c
/*  f19576c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195770:	ad840000 */ 	sw	$a0,0x0($t4)
.L0f195774:
/*  f195774:	1000000e */ 	beqz	$zero,.L0f1957b0
/*  f195778:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f19577c:
/*  f19577c:	11030003 */ 	beq	$t0,$v1,.L0f19578c
/*  f195780:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195784:	5461000b */ 	bnel	$v1,$at,.L0f1957b4
/*  f195788:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f19578c:
/*  f19578c:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f195790:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f195794:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f195798:	906f0125 */ 	lbu	$t7,0x125($v1)
/*  f19579c:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f1957a0:	55cf0004 */ 	bnel	$t6,$t7,.L0f1957b4
/*  f1957a4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1957a8:	af240000 */ 	sw	$a0,0x0($t9)
/*  f1957ac:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1957b0:
/*  f1957b0:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f1957b4:
/*  f1957b4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1957b8:	14a1ffdc */ 	bne	$a1,$at,.L0f19572c
/*  f1957bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1957c0:	18c00050 */ 	blez	$a2,.L0f195904
/*  f1957c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1957c8:	0c004b70 */ 	jal	random
/*  f1957cc:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f1957d0:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f1957d4:	0046001b */ 	divu	$zero,$v0,$a2
/*  f1957d8:	00002010 */ 	mfhi	$a0
/*  f1957dc:	24890001 */ 	addiu	$t1,$a0,0x1
/*  f1957e0:	00808825 */ 	or	$s1,$a0,$zero
/*  f1957e4:	0126001a */ 	div	$zero,$t1,$a2
/*  f1957e8:	00001810 */ 	mfhi	$v1
/*  f1957ec:	14c00002 */ 	bnez	$a2,.L0f1957f8
/*  f1957f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1957f4:	0007000d */ 	break	0x7
.L0f1957f8:
/*  f1957f8:	14c00002 */ 	bnez	$a2,.L0f195804
/*  f1957fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195800:	0007000d */ 	break	0x7
.L0f195804:
/*  f195804:	2401ffff */ 	addiu	$at,$zero,-1
/*  f195808:	14c10004 */ 	bne	$a2,$at,.L0f19581c
/*  f19580c:	3c018000 */ 	lui	$at,0x8000
/*  f195810:	15210002 */ 	bne	$t1,$at,.L0f19581c
/*  f195814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195818:	0006000d */ 	break	0x6
.L0f19581c:
/*  f19581c:	00035080 */ 	sll	$t2,$v1,0x2
.L0f195820:
/*  f195820:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f195824:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f195828:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f19582c:	afa30288 */ 	sw	$v1,0x288($sp)
/*  f195830:	02802025 */ 	or	$a0,$s4,$zero
/*  f195834:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f195838:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f19583c:	3c017f1c */ 	lui	$at,%hi(var7f1b8f54)
/*  f195840:	c4248f54 */ 	lwc1	$f4,%lo(var7f1b8f54)($at)
/*  f195844:	8fa30288 */ 	lw	$v1,0x288($sp)
/*  f195848:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f19584c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f195850:	246d0001 */ 	addiu	$t5,$v1,0x1
/*  f195854:	45000003 */ 	bc1f	.L0f195864
/*  f195858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19585c:	10000010 */ 	beqz	$zero,.L0f1958a0
/*  f195860:	00608825 */ 	or	$s1,$v1,$zero
.L0f195864:
/*  f195864:	5071000f */ 	beql	$v1,$s1,.L0f1958a4
/*  f195868:	00116080 */ 	sll	$t4,$s1,0x2
/*  f19586c:	01a6001a */ 	div	$zero,$t5,$a2
/*  f195870:	00001810 */ 	mfhi	$v1
/*  f195874:	14c00002 */ 	bnez	$a2,.L0f195880
/*  f195878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19587c:	0007000d */ 	break	0x7
.L0f195880:
/*  f195880:	2401ffff */ 	addiu	$at,$zero,-1
/*  f195884:	14c10004 */ 	bne	$a2,$at,.L0f195898
/*  f195888:	3c018000 */ 	lui	$at,0x8000
/*  f19588c:	15a10002 */ 	bne	$t5,$at,.L0f195898
/*  f195890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195894:	0006000d */ 	break	0x6
.L0f195898:
/*  f195898:	1000ffe1 */ 	beqz	$zero,.L0f195820
/*  f19589c:	00035080 */ 	sll	$t2,$v1,0x2
.L0f1958a0:
/*  f1958a0:	00116080 */ 	sll	$t4,$s1,0x2
.L0f1958a4:
/*  f1958a4:	020c9821 */ 	addu	$s3,$s0,$t4
/*  f1958a8:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f1958ac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1958b0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1958b4:	50610004 */ 	beql	$v1,$at,.L0f1958c8
/*  f1958b8:	2415002a */ 	addiu	$s5,$zero,0x2a
/*  f1958bc:	16e30004 */ 	bne	$s7,$v1,.L0f1958d0
/*  f1958c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1958c4:	2415002a */ 	addiu	$s5,$zero,0x2a
.L0f1958c8:
/*  f1958c8:	10000181 */ 	beqz	$zero,.L0f195ed0
/*  f1958cc:	ae420010 */ 	sw	$v0,0x10($s2)
.L0f1958d0:
/*  f1958d0:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f1958d4:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f1958d8:	1040000a */ 	beqz	$v0,.L0f195904
/*  f1958dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1958e0:	0c004b70 */ 	jal	random
/*  f1958e4:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f1958e8:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f1958ec:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*  f1958f0:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f1958f4:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f1958f8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1958fc:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f195900:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195904:
/*  f195904:	10000172 */ 	beqz	$zero,.L0f195ed0
/*  f195908:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19590c:
/*  f19590c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f195910:	14410043 */ 	bne	$v0,$at,.L0f195a20
/*  f195914:	3c19800b */ 	lui	$t9,0x800b
/*  f195918:	9339cb98 */ 	lbu	$t9,-0x3468($t9)
/*  f19591c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195920:	1721016b */ 	bne	$t9,$at,.L0f195ed0
/*  f195924:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195928:	0fc63a5a */ 	jal	teamGetIndex
/*  f19592c:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f195930:	00024880 */ 	sll	$t1,$v0,0x2
/*  f195934:	3c03800b */ 	lui	$v1,0x800b
/*  f195938:	00691821 */ 	addu	$v1,$v1,$t1
/*  f19593c:	8c63c168 */ 	lw	$v1,-0x3e98($v1)
/*  f195940:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195944:	90640000 */ 	lbu	$a0,0x0($v1)
/*  f195948:	10810003 */ 	beq	$a0,$at,.L0f195958
/*  f19594c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195950:	54810026 */ 	bnel	$a0,$at,.L0f1959ec
/*  f195954:	c4680008 */ 	lwc1	$f8,0x8($v1)
.L0f195958:
/*  f195958:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f19595c:	928a0125 */ 	lbu	$t2,0x125($s4)
/*  f195960:	02802025 */ 	or	$a0,$s4,$zero
/*  f195964:	920b0125 */ 	lbu	$t3,0x125($s0)
/*  f195968:	154b000e */ 	bne	$t2,$t3,.L0f1959a4
/*  f19596c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195970:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195974:	02002825 */ 	or	$a1,$s0,$zero
/*  f195978:	10400155 */ 	beqz	$v0,.L0f195ed0
/*  f19597c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195980:	0c004b70 */ 	jal	random
/*  f195984:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195988:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f19598c:	2dac0001 */ 	sltiu	$t4,$t5,0x1
/*  f195990:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f195994:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195998:	02002025 */ 	or	$a0,$s0,$zero
/*  f19599c:	1000014c */ 	beqz	$zero,.L0f195ed0
/*  f1959a0:	a642000a */ 	sh	$v0,0xa($s2)
.L0f1959a4:
/*  f1959a4:	0fc0e6a5 */ 	jal	chrIsDead
/*  f1959a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1959ac:	14400148 */ 	bnez	$v0,.L0f195ed0
/*  f1959b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1959b4:	0fc64a53 */ 	jal	func0f19294c
/*  f1959b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1959bc:	14400144 */ 	bnez	$v0,.L0f195ed0
/*  f1959c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1959c4:	0fc64b70 */ 	jal	func0f192dc0
/*  f1959c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1959cc:	10400140 */ 	beqz	$v0,.L0f195ed0
/*  f1959d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1959d4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1959d8:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f1959dc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1959e0:	1000013b */ 	beqz	$zero,.L0f195ed0
/*  f1959e4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f1959e8:	c4680008 */ 	lwc1	$f8,0x8($v1)
.L0f1959ec:
/*  f1959ec:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f1959f0:	24640028 */ 	addiu	$a0,$v1,0x28
/*  f1959f4:	e64800ec */ 	swc1	$f8,0xec($s2)
/*  f1959f8:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f1959fc:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f195a00:	e64600f0 */ 	swc1	$f6,0xf0($s2)
/*  f195a04:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f195a08:	0fc195e9 */ 	jal	func0f0657a4
/*  f195a0c:	e64a00f4 */ 	swc1	$f10,0xf4($s2)
/*  f195a10:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f195a14:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f195a18:	1000012d */ 	beqz	$zero,.L0f195ed0
/*  f195a1c:	a24f004c */ 	sb	$t7,0x4c($s2)
.L0f195a20:
/*  f195a20:	24010009 */ 	addiu	$at,$zero,0x9
/*  f195a24:	14410048 */ 	bne	$v0,$at,.L0f195b48
/*  f195a28:	3c18800b */ 	lui	$t8,0x800b
/*  f195a2c:	9318cb98 */ 	lbu	$t8,-0x3468($t8)
/*  f195a30:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195a34:	17010126 */ 	bne	$t8,$at,.L0f195ed0
/*  f195a38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195a3c:	8e99001c */ 	lw	$t9,0x1c($s4)
/*  f195a40:	3c0a800b */ 	lui	$t2,0x800b
/*  f195a44:	854ac11e */ 	lh	$t2,-0x3ee2($t2)
/*  f195a48:	87290028 */ 	lh	$t1,0x28($t9)
/*  f195a4c:	152a0016 */ 	bne	$t1,$t2,.L0f195aa8
/*  f195a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195a54:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f195a58:	13cb0013 */ 	beq	$s8,$t3,.L0f195aa8
/*  f195a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195a60:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f195a64:	11a00010 */ 	beqz	$t5,.L0f195aa8
/*  f195a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195a6c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f195a70:	02802025 */ 	or	$a0,$s4,$zero
/*  f195a74:	02802025 */ 	or	$a0,$s4,$zero
/*  f195a78:	0fc64b70 */ 	jal	func0f192dc0
/*  f195a7c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f195a80:	10400009 */ 	beqz	$v0,.L0f195aa8
/*  f195a84:	02802025 */ 	or	$a0,$s4,$zero
/*  f195a88:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f195a8c:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195a90:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195a94:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f195a98:	240c012c */ 	addiu	$t4,$zero,0x12c
/*  f195a9c:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195aa0:	1000010b */ 	beqz	$zero,.L0f195ed0
/*  f195aa4:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
.L0f195aa8:
/*  f195aa8:	3c04800b */ 	lui	$a0,0x800b
/*  f195aac:	27ae0260 */ 	addiu	$t6,$sp,0x260
/*  f195ab0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f195ab4:	8484c11e */ 	lh	$a0,-0x3ee2($a0)
/*  f195ab8:	27a5026c */ 	addiu	$a1,$sp,0x26c
/*  f195abc:	27a60268 */ 	addiu	$a2,$sp,0x268
/*  f195ac0:	0fc66adc */ 	jal	func0f19ab70
/*  f195ac4:	27a70264 */ 	addiu	$a3,$sp,0x264
/*  f195ac8:	10400101 */ 	beqz	$v0,.L0f195ed0
/*  f195acc:	c7b2026c */ 	lwc1	$f18,0x26c($sp)
/*  f195ad0:	e65200ec */ 	swc1	$f18,0xec($s2)
/*  f195ad4:	c7a40270 */ 	lwc1	$f4,0x270($sp)
/*  f195ad8:	3c04800b */ 	lui	$a0,0x800b
/*  f195adc:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f195ae0:	e64400f0 */ 	swc1	$f4,0xf0($s2)
/*  f195ae4:	c7a80274 */ 	lwc1	$f8,0x274($sp)
/*  f195ae8:	2484c11e */ 	addiu	$a0,$a0,-16098
/*  f195aec:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f195af0:	0fc195e9 */ 	jal	func0f0657a4
/*  f195af4:	e64800f4 */ 	swc1	$f8,0xf4($s2)
/*  f195af8:	8e8f001c */ 	lw	$t7,0x1c($s4)
/*  f195afc:	3c19800b */ 	lui	$t9,0x800b
/*  f195b00:	8739c11e */ 	lh	$t9,-0x3ee2($t9)
/*  f195b04:	85f80028 */ 	lh	$t8,0x28($t7)
/*  f195b08:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f195b0c:	3c0a800b */ 	lui	$t2,0x800b
/*  f195b10:	03194826 */ 	xor	$t1,$t8,$t9
/*  f195b14:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*  f195b18:	0009582b */ 	sltu	$t3,$zero,$t1
/*  f195b1c:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f195b20:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f195b24:	018fc025 */ 	or	$t8,$t4,$t7
/*  f195b28:	a258004c */ 	sb	$t8,0x4c($s2)
/*  f195b2c:	8fb90264 */ 	lw	$t9,0x264($sp)
/*  f195b30:	a6590048 */ 	sh	$t9,0x48($s2)
/*  f195b34:	8fa90260 */ 	lw	$t1,0x260($sp)
/*  f195b38:	a649004a */ 	sh	$t1,0x4a($s2)
/*  f195b3c:	854ac11e */ 	lh	$t2,-0x3ee2($t2)
/*  f195b40:	100000e3 */ 	beqz	$zero,.L0f195ed0
/*  f195b44:	ae4a00bc */ 	sw	$t2,0xbc($s2)
.L0f195b48:
/*  f195b48:	2401000a */ 	addiu	$at,$zero,0xa
/*  f195b4c:	1441002c */ 	bne	$v0,$at,.L0f195c00
/*  f195b50:	3c0b800b */ 	lui	$t3,0x800b
/*  f195b54:	916bcb98 */ 	lbu	$t3,-0x3468($t3)
/*  f195b58:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195b5c:	3c04800b */ 	lui	$a0,0x800b
/*  f195b60:	156100db */ 	bne	$t3,$at,.L0f195ed0
/*  f195b64:	27a50254 */ 	addiu	$a1,$sp,0x254
/*  f195b68:	27ad0248 */ 	addiu	$t5,$sp,0x248
/*  f195b6c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f195b70:	8484c11e */ 	lh	$a0,-0x3ee2($a0)
/*  f195b74:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f195b78:	0fc66adc */ 	jal	func0f19ab70
/*  f195b7c:	27a7024c */ 	addiu	$a3,$sp,0x24c
/*  f195b80:	104000d3 */ 	beqz	$v0,.L0f195ed0
/*  f195b84:	c7a60254 */ 	lwc1	$f6,0x254($sp)
/*  f195b88:	e64600ec */ 	swc1	$f6,0xec($s2)
/*  f195b8c:	c7aa0258 */ 	lwc1	$f10,0x258($sp)
/*  f195b90:	3c04800b */ 	lui	$a0,0x800b
/*  f195b94:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f195b98:	e64a00f0 */ 	swc1	$f10,0xf0($s2)
/*  f195b9c:	c7b2025c */ 	lwc1	$f18,0x25c($sp)
/*  f195ba0:	2484c11e */ 	addiu	$a0,$a0,-16098
/*  f195ba4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f195ba8:	0fc195e9 */ 	jal	func0f0657a4
/*  f195bac:	e65200f4 */ 	swc1	$f18,0xf4($s2)
/*  f195bb0:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f195bb4:	3c0f800b */ 	lui	$t7,0x800b
/*  f195bb8:	85efc11e */ 	lh	$t7,-0x3ee2($t7)
/*  f195bbc:	85cc0028 */ 	lh	$t4,0x28($t6)
/*  f195bc0:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f195bc4:	3c19800b */ 	lui	$t9,0x800b
/*  f195bc8:	018fc026 */ 	xor	$t8,$t4,$t7
/*  f195bcc:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f195bd0:	0018482b */ 	sltu	$t1,$zero,$t8
/*  f195bd4:	000959c0 */ 	sll	$t3,$t1,0x7
/*  f195bd8:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f195bdc:	016e6025 */ 	or	$t4,$t3,$t6
/*  f195be0:	a24c004c */ 	sb	$t4,0x4c($s2)
/*  f195be4:	8faf024c */ 	lw	$t7,0x24c($sp)
/*  f195be8:	a64f0048 */ 	sh	$t7,0x48($s2)
/*  f195bec:	8fb80248 */ 	lw	$t8,0x248($sp)
/*  f195bf0:	a658004a */ 	sh	$t8,0x4a($s2)
/*  f195bf4:	8739c11e */ 	lh	$t9,-0x3ee2($t9)
/*  f195bf8:	100000b5 */ 	beqz	$zero,.L0f195ed0
/*  f195bfc:	ae5900bc */ 	sw	$t9,0xbc($s2)
.L0f195c00:
/*  f195c00:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195c04:	1441003b */ 	bne	$v0,$at,.L0f195cf4
/*  f195c08:	3c09800b */ 	lui	$t1,0x800b
/*  f195c0c:	9129cb98 */ 	lbu	$t1,-0x3468($t1)
/*  f195c10:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195c14:	3c02800b */ 	lui	$v0,0x800b
/*  f195c18:	152100ad */ 	bne	$t1,$at,.L0f195ed0
/*  f195c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195c20:	8c42c24c */ 	lw	$v0,-0x3db4($v0)
/*  f195c24:	104000aa */ 	beqz	$v0,.L0f195ed0
/*  f195c28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195c2c:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f195c30:	104a00a7 */ 	beq	$v0,$t2,.L0f195ed0
/*  f195c34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195c38:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f195c3c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195c40:	3c0d800b */ 	lui	$t5,0x800b
/*  f195c44:	10610003 */ 	beq	$v1,$at,.L0f195c54
/*  f195c48:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195c4c:	54610027 */ 	bnel	$v1,$at,.L0f195cec
/*  f195c50:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195c54:
/*  f195c54:	8dadcb94 */ 	lw	$t5,-0x346c($t5)
/*  f195c58:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f195c5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195c60:	31ab0002 */ 	andi	$t3,$t5,0x2
/*  f195c64:	11600013 */ 	beqz	$t3,.L0f195cb4
/*  f195c68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195c6c:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f195c70:	920c0125 */ 	lbu	$t4,0x125($s0)
/*  f195c74:	02002825 */ 	or	$a1,$s0,$zero
/*  f195c78:	15cc000e */ 	bne	$t6,$t4,.L0f195cb4
/*  f195c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195c80:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195c84:	02802025 */ 	or	$a0,$s4,$zero
/*  f195c88:	10400091 */ 	beqz	$v0,.L0f195ed0
/*  f195c8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195c90:	0c004b70 */ 	jal	random
/*  f195c94:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195c98:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f195c9c:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f195ca0:	ae5801e0 */ 	sw	$t8,0x1e0($s2)
/*  f195ca4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195ca8:	02002025 */ 	or	$a0,$s0,$zero
/*  f195cac:	10000088 */ 	beqz	$zero,.L0f195ed0
/*  f195cb0:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195cb4:
/*  f195cb4:	0fc64a53 */ 	jal	func0f19294c
/*  f195cb8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195cbc:	14400084 */ 	bnez	$v0,.L0f195ed0
/*  f195cc0:	02802025 */ 	or	$a0,$s4,$zero
/*  f195cc4:	0fc64b70 */ 	jal	func0f192dc0
/*  f195cc8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195ccc:	10400080 */ 	beqz	$v0,.L0f195ed0
/*  f195cd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f195cd4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195cd8:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195cdc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195ce0:	1000007b */ 	beqz	$zero,.L0f195ed0
/*  f195ce4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f195ce8:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195cec:
/*  f195cec:	10000078 */ 	beqz	$zero,.L0f195ed0
/*  f195cf0:	ae420010 */ 	sw	$v0,0x10($s2)
.L0f195cf4:
/*  f195cf4:	2401000b */ 	addiu	$at,$zero,0xb
/*  f195cf8:	1441003a */ 	bne	$v0,$at,.L0f195de4
/*  f195cfc:	3c19800b */ 	lui	$t9,0x800b
/*  f195d00:	9339cb98 */ 	lbu	$t9,-0x3468($t9)
/*  f195d04:	3c02800b */ 	lui	$v0,0x800b
/*  f195d08:	16f90071 */ 	bne	$s7,$t9,.L0f195ed0
/*  f195d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195d10:	8c42c114 */ 	lw	$v0,-0x3eec($v0)
/*  f195d14:	1040006e */ 	beqz	$v0,.L0f195ed0
/*  f195d18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195d1c:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f195d20:	1049006b */ 	beq	$v0,$t1,.L0f195ed0
/*  f195d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195d28:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f195d2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195d30:	3c0a800b */ 	lui	$t2,0x800b
/*  f195d34:	10610003 */ 	beq	$v1,$at,.L0f195d44
/*  f195d38:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195d3c:	54610027 */ 	bnel	$v1,$at,.L0f195ddc
/*  f195d40:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195d44:
/*  f195d44:	8d4acb94 */ 	lw	$t2,-0x346c($t2)
/*  f195d48:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f195d4c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195d50:	314d0002 */ 	andi	$t5,$t2,0x2
/*  f195d54:	11a00013 */ 	beqz	$t5,.L0f195da4
/*  f195d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195d5c:	928b0125 */ 	lbu	$t3,0x125($s4)
/*  f195d60:	920e0125 */ 	lbu	$t6,0x125($s0)
/*  f195d64:	02002825 */ 	or	$a1,$s0,$zero
/*  f195d68:	156e000e */ 	bne	$t3,$t6,.L0f195da4
/*  f195d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195d70:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195d74:	02802025 */ 	or	$a0,$s4,$zero
/*  f195d78:	10400055 */ 	beqz	$v0,.L0f195ed0
/*  f195d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195d80:	0c004b70 */ 	jal	random
/*  f195d84:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195d88:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f195d8c:	2d8f0001 */ 	sltiu	$t7,$t4,0x1
/*  f195d90:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f195d94:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195d98:	02002025 */ 	or	$a0,$s0,$zero
/*  f195d9c:	1000004c */ 	beqz	$zero,.L0f195ed0
/*  f195da0:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195da4:
/*  f195da4:	0fc64a53 */ 	jal	func0f19294c
/*  f195da8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195dac:	14400048 */ 	bnez	$v0,.L0f195ed0
/*  f195db0:	02802025 */ 	or	$a0,$s4,$zero
/*  f195db4:	0fc64b70 */ 	jal	func0f192dc0
/*  f195db8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195dbc:	10400044 */ 	beqz	$v0,.L0f195ed0
/*  f195dc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f195dc4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195dc8:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195dcc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195dd0:	1000003f */ 	beqz	$zero,.L0f195ed0
/*  f195dd4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f195dd8:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195ddc:
/*  f195ddc:	1000003c */ 	beqz	$zero,.L0f195ed0
/*  f195de0:	ae420010 */ 	sw	$v0,0x10($s2)
.L0f195de4:
/*  f195de4:	2401000c */ 	addiu	$at,$zero,0xc
/*  f195de8:	14410039 */ 	bne	$v0,$at,.L0f195ed0
/*  f195dec:	3c18800b */ 	lui	$t8,0x800b
/*  f195df0:	9318cb98 */ 	lbu	$t8,-0x3468($t8)
/*  f195df4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195df8:	3c02800b */ 	lui	$v0,0x800b
/*  f195dfc:	17010034 */ 	bne	$t8,$at,.L0f195ed0
/*  f195e00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195e04:	8c42c114 */ 	lw	$v0,-0x3eec($v0)
/*  f195e08:	3c09800b */ 	lui	$t1,0x800b
/*  f195e0c:	04400030 */ 	bltz	$v0,.L0f195ed0
/*  f195e10:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f195e14:	01394821 */ 	addu	$t1,$t1,$t9
/*  f195e18:	8529c118 */ 	lh	$t1,-0x3ee8($t1)
/*  f195e1c:	3c0d800b */ 	lui	$t5,0x800b
/*  f195e20:	8e8b001c */ 	lw	$t3,0x1c($s4)
/*  f195e24:	00095080 */ 	sll	$t2,$t1,0x2
/*  f195e28:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f195e2c:	8dadc4d0 */ 	lw	$t5,-0x3b30($t5)
/*  f195e30:	3c0e800b */ 	lui	$t6,0x800b
/*  f195e34:	8da3001c */ 	lw	$v1,0x1c($t5)
/*  f195e38:	106b0025 */ 	beq	$v1,$t3,.L0f195ed0
/*  f195e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195e40:	8dcecb94 */ 	lw	$t6,-0x346c($t6)
/*  f195e44:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f195e48:	02802025 */ 	or	$a0,$s4,$zero
/*  f195e4c:	31cc0002 */ 	andi	$t4,$t6,0x2
/*  f195e50:	11800013 */ 	beqz	$t4,.L0f195ea0
/*  f195e54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195e58:	928f0125 */ 	lbu	$t7,0x125($s4)
/*  f195e5c:	92180125 */ 	lbu	$t8,0x125($s0)
/*  f195e60:	02002825 */ 	or	$a1,$s0,$zero
/*  f195e64:	15f8000e */ 	bne	$t7,$t8,.L0f195ea0
/*  f195e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195e6c:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195e70:	02802025 */ 	or	$a0,$s4,$zero
/*  f195e74:	10400016 */ 	beqz	$v0,.L0f195ed0
/*  f195e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195e7c:	0c004b70 */ 	jal	random
/*  f195e80:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195e84:	30590003 */ 	andi	$t9,$v0,0x3
/*  f195e88:	2f290001 */ 	sltiu	$t1,$t9,0x1
/*  f195e8c:	ae4901e0 */ 	sw	$t1,0x1e0($s2)
/*  f195e90:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195e94:	02002025 */ 	or	$a0,$s0,$zero
/*  f195e98:	1000000d */ 	beqz	$zero,.L0f195ed0
/*  f195e9c:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195ea0:
/*  f195ea0:	0fc64a53 */ 	jal	func0f19294c
/*  f195ea4:	02002825 */ 	or	$a1,$s0,$zero
/*  f195ea8:	14400009 */ 	bnez	$v0,.L0f195ed0
/*  f195eac:	02802025 */ 	or	$a0,$s4,$zero
/*  f195eb0:	0fc64b70 */ 	jal	func0f192dc0
/*  f195eb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f195eb8:	10400005 */ 	beqz	$v0,.L0f195ed0
/*  f195ebc:	02002025 */ 	or	$a0,$s0,$zero
/*  f195ec0:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195ec4:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195ec8:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195ecc:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f195ed0:
/*  f195ed0:	06a10078 */ 	bgez	$s5,.L0f1960b4
/*  f195ed4:	3c03800b */ 	lui	$v1,0x800b
/*  f195ed8:	9063cb98 */ 	lbu	$v1,-0x3468($v1)
/*  f195edc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195ee0:	16e3001a */ 	bne	$s7,$v1,.L0f195f4c
/*  f195ee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195ee8:	8e4a009c */ 	lw	$t2,0x9c($s2)
/*  f195eec:	000a6fc2 */ 	srl	$t5,$t2,0x1f
/*  f195ef0:	11a00070 */ 	beqz	$t5,.L0f1960b4
/*  f195ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195ef8:	0c004b70 */ 	jal	random
/*  f195efc:	03c08025 */ 	or	$s0,$s8,$zero
/*  f195f00:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195f04:	0041001b */ 	divu	$zero,$v0,$at
/*  f195f08:	00005810 */ 	mfhi	$t3
/*  f195f0c:	2d610042 */ 	sltiu	$at,$t3,0x42
/*  f195f10:	10200005 */ 	beqz	$at,.L0f195f28
/*  f195f14:	02802025 */ 	or	$a0,$s4,$zero
/*  f195f18:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f195f1c:	0fc64d4c */ 	jal	func0f193530
/*  f195f20:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f195f24:	00408025 */ 	or	$s0,$v0,$zero
.L0f195f28:
/*  f195f28:	06000062 */ 	bltz	$s0,.L0f1960b4
/*  f195f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195f30:	0c004b70 */ 	jal	random
/*  f195f34:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195f38:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f195f3c:	2dcc0001 */ 	sltiu	$t4,$t6,0x1
/*  f195f40:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f195f44:	1000005b */ 	beqz	$zero,.L0f1960b4
/*  f195f48:	a650000a */ 	sh	$s0,0xa($s2)
.L0f195f4c:
/*  f195f4c:	14610024 */ 	bne	$v1,$at,.L0f195fe0
/*  f195f50:	3c02800b */ 	lui	$v0,0x800b
/*  f195f54:	8c42c114 */ 	lw	$v0,-0x3eec($v0)
/*  f195f58:	3c18800b */ 	lui	$t8,0x800b
/*  f195f5c:	04400055 */ 	bltz	$v0,.L0f1960b4
/*  f195f60:	00027840 */ 	sll	$t7,$v0,0x1
/*  f195f64:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f195f68:	8718c118 */ 	lh	$t8,-0x3ee8($t8)
/*  f195f6c:	3c09800b */ 	lui	$t1,0x800b
/*  f195f70:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f195f74:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f195f78:	01394821 */ 	addu	$t1,$t1,$t9
/*  f195f7c:	8d29c4d0 */ 	lw	$t1,-0x3b30($t1)
/*  f195f80:	8d23001c */ 	lw	$v1,0x1c($t1)
/*  f195f84:	146a004b */ 	bne	$v1,$t2,.L0f1960b4
/*  f195f88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195f8c:	0c004b70 */ 	jal	random
/*  f195f90:	03c08025 */ 	or	$s0,$s8,$zero
/*  f195f94:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195f98:	0041001b */ 	divu	$zero,$v0,$at
/*  f195f9c:	00006810 */ 	mfhi	$t5
/*  f195fa0:	2da10042 */ 	sltiu	$at,$t5,0x42
/*  f195fa4:	10200005 */ 	beqz	$at,.L0f195fbc
/*  f195fa8:	02802025 */ 	or	$a0,$s4,$zero
/*  f195fac:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f195fb0:	0fc64d4c */ 	jal	func0f193530
/*  f195fb4:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f195fb8:	00408025 */ 	or	$s0,$v0,$zero
.L0f195fbc:
/*  f195fbc:	0600003d */ 	bltz	$s0,.L0f1960b4
/*  f195fc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195fc4:	0c004b70 */ 	jal	random
/*  f195fc8:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195fcc:	304b0003 */ 	andi	$t3,$v0,0x3
/*  f195fd0:	2d6e0001 */ 	sltiu	$t6,$t3,0x1
/*  f195fd4:	ae4e01e0 */ 	sw	$t6,0x1e0($s2)
/*  f195fd8:	10000036 */ 	beqz	$zero,.L0f1960b4
/*  f195fdc:	a650000a */ 	sh	$s0,0xa($s2)
.L0f195fe0:
/*  f195fe0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195fe4:	54610021 */ 	bnel	$v1,$at,.L0f19606c
/*  f195fe8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195fec:	0fc65227 */ 	jal	func0f19489c
/*  f195ff0:	02802025 */ 	or	$a0,$s4,$zero
/*  f195ff4:	1040002f */ 	beqz	$v0,.L0f1960b4
/*  f195ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195ffc:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f196000:	0fc63a5a */ 	jal	teamGetIndex
/*  f196004:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f196008:	3c07800b */ 	lui	$a3,%hi(g_ScenarioData)
/*  f19600c:	24e7c110 */ 	addiu	$a3,$a3,%lo(g_ScenarioData)
/*  f196010:	00026040 */ 	sll	$t4,$v0,0x1
/*  f196014:	00ec7821 */ 	addu	$t7,$a3,$t4
/*  f196018:	85e30008 */ 	lh	$v1,0x8($t7)
/*  f19601c:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f196020:	27a601d8 */ 	addiu	$a2,$sp,0x1d8
/*  f196024:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f196028:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f19602c:	0fc456ac */ 	jal	padUnpack
/*  f196030:	87240018 */ 	lh	$a0,0x18($t9)
/*  f196034:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
/*  f196038:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f19603c:	e64400ec */ 	swc1	$f4,0xec($s2)
/*  f196040:	c7a801dc */ 	lwc1	$f8,0x1dc($sp)
/*  f196044:	314dff7f */ 	andi	$t5,$t2,0xff7f
/*  f196048:	e64800f0 */ 	swc1	$f8,0xf0($s2)
/*  f19604c:	c7a601e0 */ 	lwc1	$f6,0x1e0($sp)
/*  f196050:	e64600f4 */ 	swc1	$f6,0xf4($s2)
/*  f196054:	8fa90220 */ 	lw	$t1,0x220($sp)
/*  f196058:	a65e00fa */ 	sh	$s8,0xfa($s2)
/*  f19605c:	a24d004c */ 	sb	$t5,0x4c($s2)
/*  f196060:	10000014 */ 	beqz	$zero,.L0f1960b4
/*  f196064:	a64900f8 */ 	sh	$t1,0xf8($s2)
/*  f196068:	24010002 */ 	addiu	$at,$zero,0x2
.L0f19606c:
/*  f19606c:	14610011 */ 	bne	$v1,$at,.L0f1960b4
/*  f196070:	3c0b800b */ 	lui	$t3,0x800b
/*  f196074:	8d6bc24c */ 	lw	$t3,-0x3db4($t3)
/*  f196078:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f19607c:	156e000d */ 	bne	$t3,$t6,.L0f1960b4
/*  f196080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196084:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196088:	02802025 */ 	or	$a0,$s4,$zero
/*  f19608c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f196090:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f196094:	846c00d2 */ 	lh	$t4,0xd2($v1)
/*  f196098:	2415002e */ 	addiu	$s5,$zero,0x2e
/*  f19609c:	104c0005 */ 	beq	$v0,$t4,.L0f1960b4
/*  f1960a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1960a4:	8c6f0080 */ 	lw	$t7,0x80($v1)
/*  f1960a8:	2415002c */ 	addiu	$s5,$zero,0x2c
/*  f1960ac:	10000001 */ 	beqz	$zero,.L0f1960b4
/*  f1960b0:	ae4f0010 */ 	sw	$t7,0x10($s2)
.L0f1960b4:
/*  f1960b4:	06a100a0 */ 	bgez	$s5,.L0f196338
/*  f1960b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1960bc:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f1960c0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1960c4:	93020047 */ 	lbu	$v0,0x47($t8)
/*  f1960c8:	54410011 */ 	bnel	$v0,$at,.L0f196110
/*  f1960cc:	24010009 */ 	addiu	$at,$zero,0x9
/*  f1960d0:	86420076 */ 	lh	$v0,0x76($s2)
/*  f1960d4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1960d8:	3c05800b */ 	lui	$a1,0x800b
/*  f1960dc:	04400096 */ 	bltz	$v0,.L0f196338
/*  f1960e0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f1960e4:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f1960e8:	0fc64a53 */ 	jal	func0f19294c
/*  f1960ec:	8ca5c4d0 */ 	lw	$a1,-0x3b30($a1)
/*  f1960f0:	14400091 */ 	bnez	$v0,.L0f196338
/*  f1960f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1960f8:	86490076 */ 	lh	$t1,0x76($s2)
/*  f1960fc:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196100:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196104:	1000008c */ 	beqz	$zero,.L0f196338
/*  f196108:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f19610c:	24010009 */ 	addiu	$at,$zero,0x9
.L0f196110:
/*  f196110:	54410021 */ 	bnel	$v0,$at,.L0f196198
/*  f196114:	24010008 */ 	addiu	$at,$zero,0x8
/*  f196118:	8e4a0114 */ 	lw	$t2,0x114($s2)
/*  f19611c:	0543000f */ 	bgezl	$t2,.L0f19615c
/*  f196120:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f196124:	86420076 */ 	lh	$v0,0x76($s2)
/*  f196128:	02802025 */ 	or	$a0,$s4,$zero
/*  f19612c:	3c05800b */ 	lui	$a1,0x800b
/*  f196130:	04400009 */ 	bltz	$v0,.L0f196158
/*  f196134:	00026880 */ 	sll	$t5,$v0,0x2
/*  f196138:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f19613c:	8ca5c4d0 */ 	lw	$a1,-0x3b30($a1)
/*  f196140:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f196144:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f196148:	54400004 */ 	bnezl	$v0,.L0f19615c
/*  f19614c:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f196150:	864b0076 */ 	lh	$t3,0x76($s2)
/*  f196154:	ae4b0114 */ 	sw	$t3,0x114($s2)
.L0f196158:
/*  f196158:	8e420114 */ 	lw	$v0,0x114($s2)
.L0f19615c:
/*  f19615c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196160:	3c05800b */ 	lui	$a1,0x800b
/*  f196164:	04400074 */ 	bltz	$v0,.L0f196338
/*  f196168:	00027080 */ 	sll	$t6,$v0,0x2
/*  f19616c:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f196170:	0fc64a53 */ 	jal	func0f19294c
/*  f196174:	8ca5c4d0 */ 	lw	$a1,-0x3b30($a1)
/*  f196178:	1440006f */ 	bnez	$v0,.L0f196338
/*  f19617c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196180:	8e4c0114 */ 	lw	$t4,0x114($s2)
/*  f196184:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196188:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f19618c:	1000006a */ 	beqz	$zero,.L0f196338
/*  f196190:	a64c0008 */ 	sh	$t4,0x8($s2)
/*  f196194:	24010008 */ 	addiu	$at,$zero,0x8
.L0f196198:
/*  f196198:	54410028 */ 	bnel	$v0,$at,.L0f19623c
/*  f19619c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1961a0:	0fc62179 */ 	jal	func0f1885e4
/*  f1961a4:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f1961a8:	18400063 */ 	blez	$v0,.L0f196338
/*  f1961ac:	00408825 */ 	or	$s1,$v0,$zero
/*  f1961b0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1961b4:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f1961b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1961bc:	27b000e4 */ 	addiu	$s0,$sp,0xe4
/*  f1961c0:	03109821 */ 	addu	$s3,$t8,$s0
.L0f1961c4:
/*  f1961c4:	0fc6343a */ 	jal	func0f18d0e8
/*  f1961c8:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f1961cc:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f1961d0:	0fc63410 */ 	jal	func0f18d040
/*  f1961d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1961d8:	10540011 */ 	beq	$v0,$s4,.L0f196220
/*  f1961dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1961e0:	0fc0e6a5 */ 	jal	chrIsDead
/*  f1961e4:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f1961e8:	1440000d */ 	bnez	$v0,.L0f196220
/*  f1961ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f1961f0:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f1961f4:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f1961f8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1961fc:	10400008 */ 	beqz	$v0,.L0f196220
/*  f196200:	02802025 */ 	or	$a0,$s4,$zero
/*  f196204:	0fc64a53 */ 	jal	func0f19294c
/*  f196208:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f19620c:	14400004 */ 	bnez	$v0,.L0f196220
/*  f196210:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f196214:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196218:	a6590008 */ 	sh	$t9,0x8($s2)
/*  f19621c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f196220:
/*  f196220:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f196224:	0213082b */ 	sltu	$at,$s0,$s3
/*  f196228:	1420ffe6 */ 	bnez	$at,.L0f1961c4
/*  f19622c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196230:	10000041 */ 	beqz	$zero,.L0f196338
/*  f196234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196238:	24010006 */ 	addiu	$at,$zero,0x6
.L0f19623c:
/*  f19623c:	1441003e */ 	bne	$v0,$at,.L0f196338
/*  f196240:	3c13800b */ 	lui	$s3,%hi(g_MpNumPlayers)
/*  f196244:	2673c530 */ 	addiu	$s3,$s3,%lo(g_MpNumPlayers)
/*  f196248:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f19624c:	44805000 */ 	mtc1	$zero,$f10
/*  f196250:	03c08825 */ 	or	$s1,$s8,$zero
/*  f196254:	00008025 */ 	or	$s0,$zero,$zero
/*  f196258:	19200032 */ 	blez	$t1,.L0f196324
/*  f19625c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
.L0f196260:
/*  f196260:	0fc63410 */ 	jal	func0f18d040
/*  f196264:	02002025 */ 	or	$a0,$s0,$zero
/*  f196268:	10540029 */ 	beq	$v0,$s4,.L0f196310
/*  f19626c:	00402025 */ 	or	$a0,$v0,$zero
/*  f196270:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196274:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f196278:	14400025 */ 	bnez	$v0,.L0f196310
/*  f19627c:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f196280:	02802025 */ 	or	$a0,$s4,$zero
/*  f196284:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f196288:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f19628c:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f196290:	1040001f */ 	beqz	$v0,.L0f196310
/*  f196294:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f196298:	02802025 */ 	or	$a0,$s4,$zero
/*  f19629c:	0fc64a53 */ 	jal	func0f19294c
/*  f1962a0:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f1962a4:	1440001a */ 	bnez	$v0,.L0f196310
/*  f1962a8:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f1962ac:	8caa02d4 */ 	lw	$t2,0x2d4($a1)
/*  f1962b0:	11400005 */ 	beqz	$t2,.L0f1962c8
/*  f1962b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1962b8:	c4b20104 */ 	lwc1	$f18,0x104($a1)
/*  f1962bc:	c4a40100 */ 	lwc1	$f4,0x100($a1)
/*  f1962c0:	1000000b */ 	beqz	$zero,.L0f1962f0
/*  f1962c4:	46049001 */ 	sub.s	$f0,$f18,$f4
.L0f1962c8:
/*  f1962c8:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f1962cc:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f1962d0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1962d4:	02cd5821 */ 	addu	$t3,$s6,$t5
/*  f1962d8:	8d6e0064 */ 	lw	$t6,0x64($t3)
/*  f1962dc:	3c014100 */ 	lui	$at,0x4100
/*  f1962e0:	44813000 */ 	mtc1	$at,$f6
/*  f1962e4:	c5c800dc */ 	lwc1	$f8,0xdc($t6)
/*  f1962e8:	46064002 */ 	mul.s	$f0,$f8,$f6
/*  f1962ec:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1962f0:
/*  f1962f0:	06200005 */ 	bltz	$s1,.L0f196308
/*  f1962f4:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f1962f8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f1962fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196300:	45020004 */ 	bc1fl	.L0f196314
/*  f196304:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f196308:
/*  f196308:	02008825 */ 	or	$s1,$s0,$zero
/*  f19630c:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
.L0f196310:
/*  f196310:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f196314:
/*  f196314:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f196318:	020c082a */ 	slt	$at,$s0,$t4
/*  f19631c:	1420ffd0 */ 	bnez	$at,.L0f196260
/*  f196320:	00000000 */ 	sll	$zero,$zero,0x0
.L0f196324:
/*  f196324:	06200004 */ 	bltz	$s1,.L0f196338
/*  f196328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19632c:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196330:	a6510008 */ 	sh	$s1,0x8($s2)
/*  f196334:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f196338:
/*  f196338:	06a1000d */ 	bgez	$s5,.L0f196370
/*  f19633c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196340:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f196344:	13d8000a */ 	beq	$s8,$t8,.L0f196370
/*  f196348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19634c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196350:	02802025 */ 	or	$a0,$s4,$zero
/*  f196354:	02802025 */ 	or	$a0,$s4,$zero
/*  f196358:	0fc64b70 */ 	jal	func0f192dc0
/*  f19635c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196360:	10400003 */ 	beqz	$v0,.L0f196370
/*  f196364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196368:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f19636c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f196370:
/*  f196370:	06a1000b */ 	bgez	$s5,.L0f1963a0
/*  f196374:	02802025 */ 	or	$a0,$s4,$zero
/*  f196378:	0fc64d4c */ 	jal	func0f193530
/*  f19637c:	3c054396 */ 	lui	$a1,0x4396
/*  f196380:	04400007 */ 	bltz	$v0,.L0f1963a0
/*  f196384:	00408025 */ 	or	$s0,$v0,$zero
/*  f196388:	0c004b70 */ 	jal	random
/*  f19638c:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f196390:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f196394:	2df90001 */ 	sltiu	$t9,$t7,0x1
/*  f196398:	ae5901e0 */ 	sw	$t9,0x1e0($s2)
/*  f19639c:	a650000a */ 	sh	$s0,0xa($s2)
.L0f1963a0:
/*  f1963a0:	06a10006 */ 	bgez	$s5,.L0f1963bc
/*  f1963a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1963a8:	0fc651ad */ 	jal	func0f1946b4
/*  f1963ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f1963b0:	10400002 */ 	beqz	$v0,.L0f1963bc
/*  f1963b4:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f1963b8:	2415002a */ 	addiu	$s5,$zero,0x2a
.L0f1963bc:
/*  f1963bc:	3c13800b */ 	lui	$s3,%hi(g_MpNumPlayers)
/*  f1963c0:	06a0007f */ 	bltz	$s5,.L0f1965c0
/*  f1963c4:	2673c530 */ 	addiu	$s3,$s3,%lo(g_MpNumPlayers)
/*  f1963c8:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1963cc:	56a1000a */ 	bnel	$s5,$at,.L0f1963f8
/*  f1963d0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1963d4:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1963d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1963dc:	50a00079 */ 	beqzl	$a1,.L0f1965c4
/*  f1963e0:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1963e4:	0fc0eadd */ 	jal	func0f03ab74
/*  f1963e8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1963ec:	10000074 */ 	beqz	$zero,.L0f1965c0
/*  f1963f0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1963f4:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f1963f8:
/*  f1963f8:	16a10008 */ 	bne	$s5,$at,.L0f19641c
/*  f1963fc:	24100032 */ 	addiu	$s0,$zero,0x32
/*  f196400:	928902a0 */ 	lbu	$t1,0x2a0($s4)
/*  f196404:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f196408:	5121006e */ 	beql	$t1,$at,.L0f1965c4
/*  f19640c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196410:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196414:	1000006a */ 	beqz	$zero,.L0f1965c0
/*  f196418:	a25e0074 */ 	sb	$s8,0x74($s2)
.L0f19641c:
/*  f19641c:	16b0000e */ 	bne	$s5,$s0,.L0f196458
/*  f196420:	24010033 */ 	addiu	$at,$zero,0x33
/*  f196424:	928a02a0 */ 	lbu	$t2,0x2a0($s4)
/*  f196428:	520a0066 */ 	beql	$s0,$t2,.L0f1965c4
/*  f19642c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196430:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196434:	8e4d01e0 */ 	lw	$t5,0x1e0($s2)
/*  f196438:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f19643c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196440:	51a00060 */ 	beqzl	$t5,.L0f1965c4
/*  f196444:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196448:	0fc649df */ 	jal	func0f19277c
/*  f19644c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f196450:	1000005c */ 	beqz	$zero,.L0f1965c4
/*  f196454:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.L0f196458:
/*  f196458:	56a10010 */ 	bnel	$s5,$at,.L0f19649c
/*  f19645c:	2401002b */ 	addiu	$at,$zero,0x2b
/*  f196460:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196464:	8e4b01dc */ 	lw	$t3,0x1dc($s2)
/*  f196468:	02802025 */ 	or	$a0,$s4,$zero
/*  f19646c:	51600004 */ 	beqzl	$t3,.L0f196480
/*  f196470:	02802025 */ 	or	$a0,$s4,$zero
/*  f196474:	0fc649df */ 	jal	func0f19277c
/*  f196478:	03c02825 */ 	or	$a1,$s8,$zero
/*  f19647c:	02802025 */ 	or	$a0,$s4,$zero
.L0f196480:
/*  f196480:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f196484:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f196488:	0fc0e10f */ 	jal	func0f03843c
/*  f19648c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f196490:	1000004c */ 	beqz	$zero,.L0f1965c4
/*  f196494:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196498:	2401002b */ 	addiu	$at,$zero,0x2b
.L0f19649c:
/*  f19649c:	56a10037 */ 	bnel	$s5,$at,.L0f19657c
/*  f1964a0:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f1964a4:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f1964a8:	c64400ec */ 	lwc1	$f4,0xec($s2)
/*  f1964ac:	44808000 */ 	mtc1	$zero,$f16
/*  f1964b0:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f1964b4:	c64600f0 */ 	lwc1	$f6,0xf0($s2)
/*  f1964b8:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f1964bc:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f1964c0:	c65200f4 */ 	lwc1	$f18,0xf4($s2)
/*  f1964c4:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f1964c8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f1964cc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f1964d0:	44817000 */ 	mtc1	$at,$f14
/*  f1964d4:	46064081 */ 	sub.s	$f2,$f8,$f6
/*  f1964d8:	45000002 */ 	bc1f	.L0f1964e4
/*  f1964dc:	46125301 */ 	sub.s	$f12,$f10,$f18
/*  f1964e0:	46000007 */ 	neg.s	$f0,$f0
.L0f1964e4:
/*  f1964e4:	4610103c */ 	c.lt.s	$f2,$f16
/*  f1964e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1964ec:	264500ec */ 	addiu	$a1,$s2,0xec
/*  f1964f0:	264600f8 */ 	addiu	$a2,$s2,0xf8
/*  f1964f4:	45000002 */ 	bc1f	.L0f196500
/*  f1964f8:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f1964fc:	46001087 */ 	neg.s	$f2,$f2
.L0f196500:
/*  f196500:	4610603c */ 	c.lt.s	$f12,$f16
/*  f196504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196508:	45020003 */ 	bc1fl	.L0f196518
/*  f19650c:	4600703c */ 	c.lt.s	$f14,$f0
/*  f196510:	46006307 */ 	neg.s	$f12,$f12
/*  f196514:	4600703c */ 	c.lt.s	$f14,$f0
.L0f196518:
/*  f196518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19651c:	4501000e */ 	bc1t	.L0f196558
/*  f196520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196524:	460c703c */ 	c.lt.s	$f14,$f12
/*  f196528:	3c014348 */ 	lui	$at,0x4348
/*  f19652c:	4501000a */ 	bc1t	.L0f196558
/*  f196530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196534:	44812000 */ 	mtc1	$at,$f4
/*  f196538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19653c:	4602203c */ 	c.lt.s	$f4,$f2
/*  f196540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196544:	45000008 */ 	bc1f	.L0f196568
/*  f196548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19654c:	828c032d */ 	lb	$t4,0x32d($s4)
/*  f196550:	05800005 */ 	bltz	$t4,.L0f196568
/*  f196554:	00000000 */ 	sll	$zero,$zero,0x0
.L0f196558:
/*  f196558:	0fc0e10f */ 	jal	func0f03843c
/*  f19655c:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196560:	10000018 */ 	beqz	$zero,.L0f1965c4
/*  f196564:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.L0f196568:
/*  f196568:	0fc0baaf */ 	jal	func0f02eabc
/*  f19656c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196570:	10000014 */ 	beqz	$zero,.L0f1965c4
/*  f196574:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196578:	2401002c */ 	addiu	$at,$zero,0x2c
.L0f19657c:
/*  f19657c:	56a1000c */ 	bnel	$s5,$at,.L0f1965b0
/*  f196580:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f196584:	8e580010 */ 	lw	$t8,0x10($s2)
/*  f196588:	02802025 */ 	or	$a0,$s4,$zero
/*  f19658c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f196590:	5300000c */ 	beqzl	$t8,.L0f1965c4
/*  f196594:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196598:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f19659c:	0fc0eadd */ 	jal	func0f03ab74
/*  f1965a0:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1965a4:	10000007 */ 	beqz	$zero,.L0f1965c4
/*  f1965a8:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1965ac:	2401002e */ 	addiu	$at,$zero,0x2e
.L0f1965b0:
/*  f1965b0:	16a10003 */ 	bne	$s5,$at,.L0f1965c0
/*  f1965b4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1965b8:	0fc0baaf */ 	jal	func0f02eabc
/*  f1965bc:	a29502a0 */ 	sb	$s5,0x2a0($s4)
.L0f1965c0:
/*  f1965c0:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.L0f1965c4:
/*  f1965c4:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1965c8:	24100032 */ 	addiu	$s0,$zero,0x32
/*  f1965cc:	54410012 */ 	bnel	$v0,$at,.L0f196618
/*  f1965d0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1965d4:	828f0007 */ 	lb	$t7,0x7($s4)
/*  f1965d8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1965dc:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f1965e0:	15e1000a */ 	bne	$t7,$at,.L0f19660c
/*  f1965e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1965e8:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1965ec:	10a00007 */ 	beqz	$a1,.L0f19660c
/*  f1965f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1965f4:	8cb90018 */ 	lw	$t9,0x18($a1)
/*  f1965f8:	17200004 */ 	bnez	$t9,.L0f19660c
/*  f1965fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196600:	84a90002 */ 	lh	$t1,0x2($a1)
/*  f196604:	11200160 */ 	beqz	$t1,.L0f196b88
/*  f196608:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19660c:
/*  f19660c:	1000015e */ 	beqz	$zero,.L0f196b88
/*  f196610:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
/*  f196614:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f196618:
/*  f196618:	1441003e */ 	bne	$v0,$at,.L0f196714
/*  f19661c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196620:	86420008 */ 	lh	$v0,0x8($s2)
/*  f196624:	3c04800b */ 	lui	$a0,0x800b
/*  f196628:	04400011 */ 	bltz	$v0,.L0f196670
/*  f19662c:	00026880 */ 	sll	$t5,$v0,0x2
/*  f196630:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f196634:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196638:	8c84c4d0 */ 	lw	$a0,-0x3b30($a0)
/*  f19663c:	5440000a */ 	bnezl	$v0,.L0f196668
/*  f196640:	240c0029 */ 	addiu	$t4,$zero,0x29
/*  f196644:	864b0008 */ 	lh	$t3,0x8($s2)
/*  f196648:	3c05800b */ 	lui	$a1,0x800b
/*  f19664c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196650:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f196654:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f196658:	0fc64b70 */ 	jal	func0f192dc0
/*  f19665c:	8ca5c4d0 */ 	lw	$a1,-0x3b30($a1)
/*  f196660:	14400003 */ 	bnez	$v0,.L0f196670
/*  f196664:	240c0029 */ 	addiu	$t4,$zero,0x29
.L0f196668:
/*  f196668:	10000147 */ 	beqz	$zero,.L0f196b88
/*  f19666c:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.L0f196670:
/*  f196670:	86580008 */ 	lh	$t8,0x8($s2)
/*  f196674:	07010013 */ 	bgez	$t8,.L0f1966c4
/*  f196678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19667c:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f196680:	53cf000e */ 	beql	$s8,$t7,.L0f1966bc
/*  f196684:	24190029 */ 	addiu	$t9,$zero,0x29
/*  f196688:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19668c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196690:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196694:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196698:	54400008 */ 	bnezl	$v0,.L0f1966bc
/*  f19669c:	24190029 */ 	addiu	$t9,$zero,0x29
/*  f1966a0:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f1966a4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966a8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966ac:	0fc64b70 */ 	jal	func0f192dc0
/*  f1966b0:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f1966b4:	14400003 */ 	bnez	$v0,.L0f1966c4
/*  f1966b8:	24190029 */ 	addiu	$t9,$zero,0x29
.L0f1966bc:
/*  f1966bc:	10000132 */ 	beqz	$zero,.L0f196b88
/*  f1966c0:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.L0f1966c4:
/*  f1966c4:	0fc65d80 */ 	jal	func0f197600
/*  f1966c8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966cc:	0fc6519c */ 	jal	func0f194670
/*  f1966d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966d4:	10400003 */ 	beqz	$v0,.L0f1966e4
/*  f1966d8:	24090029 */ 	addiu	$t1,$zero,0x29
/*  f1966dc:	1000012a */ 	beqz	$zero,.L0f196b88
/*  f1966e0:	a28902a0 */ 	sb	$t1,0x2a0($s4)
.L0f1966e4:
/*  f1966e4:	8e4201d8 */ 	lw	$v0,0x1d8($s2)
/*  f1966e8:	04400127 */ 	bltz	$v0,.L0f196b88
/*  f1966ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1966f0:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f1966f4:	8e4a0120 */ 	lw	$t2,0x120($s2)
/*  f1966f8:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f1966fc:	01a25823 */ 	subu	$t3,$t5,$v0
/*  f196700:	014b082a */ 	slt	$at,$t2,$t3
/*  f196704:	10200120 */ 	beqz	$at,.L0f196b88
/*  f196708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19670c:	1000011e */ 	beqz	$zero,.L0f196b88
/*  f196710:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
.L0f196714:
/*  f196714:	1602004d */ 	bne	$s0,$v0,.L0f19684c
/*  f196718:	24010033 */ 	addiu	$at,$zero,0x33
/*  f19671c:	8642000a */ 	lh	$v0,0xa($s2)
/*  f196720:	3c04800b */ 	lui	$a0,0x800b
/*  f196724:	04400005 */ 	bltz	$v0,.L0f19673c
/*  f196728:	00026080 */ 	sll	$t4,$v0,0x2
/*  f19672c:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f196730:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196734:	8c84c4d0 */ 	lw	$a0,-0x3b30($a0)
/*  f196738:	10400003 */ 	beqz	$v0,.L0f196748
.L0f19673c:
/*  f19673c:	24180029 */ 	addiu	$t8,$zero,0x29
/*  f196740:	10000111 */ 	beqz	$zero,.L0f196b88
/*  f196744:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.L0f196748:
/*  f196748:	0fc65d80 */ 	jal	func0f197600
/*  f19674c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196750:	8e4f01e0 */ 	lw	$t7,0x1e0($s2)
/*  f196754:	11e00037 */ 	beqz	$t7,.L0f196834
/*  f196758:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19675c:	8699017e */ 	lh	$t9,0x17e($s4)
/*  f196760:	13d90034 */ 	beq	$s8,$t9,.L0f196834
/*  f196764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196768:	8e490128 */ 	lw	$t1,0x128($s2)
/*  f19676c:	11200031 */ 	beqz	$t1,.L0f196834
/*  f196770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196774:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196778:	02802025 */ 	or	$a0,$s4,$zero
/*  f19677c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196780:	0fc64b70 */ 	jal	func0f192dc0
/*  f196784:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196788:	1040002a */ 	beqz	$v0,.L0f196834
/*  f19678c:	3c0143fa */ 	lui	$at,0x43fa
/*  f196790:	864d000a */ 	lh	$t5,0xa($s2)
/*  f196794:	3c0b800b */ 	lui	$t3,0x800b
/*  f196798:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f19679c:	000d5080 */ 	sll	$t2,$t5,0x2
/*  f1967a0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f1967a4:	8d6bc4d0 */ 	lw	$t3,-0x3b30($t3)
/*  f1967a8:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f1967ac:	44806000 */ 	mtc1	$zero,$f12
/*  f1967b0:	8d62001c */ 	lw	$v0,0x1c($t3)
/*  f1967b4:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f1967b8:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f1967bc:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f1967c0:	46064001 */ 	sub.s	$f0,$f8,$f6
/*  f1967c4:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f1967c8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1967cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1967d0:	45020003 */ 	bc1fl	.L0f1967e0
/*  f1967d4:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1967d8:	46000007 */ 	neg.s	$f0,$f0
/*  f1967dc:	460c103c */ 	c.lt.s	$f2,$f12
.L0f1967e0:
/*  f1967e0:	44816000 */ 	mtc1	$at,$f12
/*  f1967e4:	45020003 */ 	bc1fl	.L0f1967f4
/*  f1967e8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1967ec:	46001087 */ 	neg.s	$f2,$f2
/*  f1967f0:	460c003c */ 	c.lt.s	$f0,$f12
.L0f1967f4:
/*  f1967f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1967f8:	4500000e */ 	bc1f	.L0f196834
/*  f1967fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196800:	460c103c */ 	c.lt.s	$f2,$f12
/*  f196804:	240e002f */ 	addiu	$t6,$zero,0x2f
/*  f196808:	02802025 */ 	or	$a0,$s4,$zero
/*  f19680c:	45000009 */ 	bc1f	.L0f196834
/*  f196810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196814:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196818:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
/*  f19681c:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196820:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196824:	240c012c */ 	addiu	$t4,$zero,0x12c
/*  f196828:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f19682c:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
/*  f196830:	a25e0074 */ 	sb	$s8,0x74($s2)
.L0f196834:
/*  f196834:	0fc6519c */ 	jal	func0f194670
/*  f196838:	02802025 */ 	or	$a0,$s4,$zero
/*  f19683c:	104000d2 */ 	beqz	$v0,.L0f196b88
/*  f196840:	24180029 */ 	addiu	$t8,$zero,0x29
/*  f196844:	100000d0 */ 	beqz	$zero,.L0f196b88
/*  f196848:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.L0f19684c:
/*  f19684c:	54410063 */ 	bnel	$v0,$at,.L0f1969dc
/*  f196850:	2401002b */ 	addiu	$at,$zero,0x2b
/*  f196854:	828f0007 */ 	lb	$t7,0x7($s4)
/*  f196858:	2401000f */ 	addiu	$at,$zero,0xf
/*  f19685c:	11e10058 */ 	beq	$t7,$at,.L0f1969c0
/*  f196860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196864:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f196868:	c648008c */ 	lwc1	$f8,0x8c($s2)
/*  f19686c:	44807000 */ 	mtc1	$zero,$f14
/*  f196870:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f196874:	c64a0090 */ 	lwc1	$f10,0x90($s2)
/*  f196878:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f19687c:	46082001 */ 	sub.s	$f0,$f4,$f8
/*  f196880:	c6440094 */ 	lwc1	$f4,0x94($s2)
/*  f196884:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f196888:	3c014220 */ 	lui	$at,0x4220
/*  f19688c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f196890:	460a3081 */ 	sub.s	$f2,$f6,$f10
/*  f196894:	45000002 */ 	bc1f	.L0f1968a0
/*  f196898:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f19689c:	46000007 */ 	neg.s	$f0,$f0
.L0f1968a0:
/*  f1968a0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f1968a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1968a8:	45020003 */ 	bc1fl	.L0f1968b8
/*  f1968ac:	460e603c */ 	c.lt.s	$f12,$f14
/*  f1968b0:	46001087 */ 	neg.s	$f2,$f2
/*  f1968b4:	460e603c */ 	c.lt.s	$f12,$f14
.L0f1968b8:
/*  f1968b8:	44817000 */ 	mtc1	$at,$f14
/*  f1968bc:	45020003 */ 	bc1fl	.L0f1968cc
/*  f1968c0:	8e4200dc */ 	lw	$v0,0xdc($s2)
/*  f1968c4:	46006307 */ 	neg.s	$f12,$f12
/*  f1968c8:	8e4200dc */ 	lw	$v0,0xdc($s2)
.L0f1968cc:
/*  f1968cc:	58400005 */ 	blezl	$v0,.L0f1968e4
/*  f1968d0:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1968d4:	8ed90038 */ 	lw	$t9,0x38($s6)
/*  f1968d8:	00594823 */ 	subu	$t1,$v0,$t9
/*  f1968dc:	ae4900dc */ 	sw	$t1,0xdc($s2)
/*  f1968e0:	4600703c */ 	c.lt.s	$f14,$f0
.L0f1968e4:
/*  f1968e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1968e8:	4503000f */ 	bc1tl	.L0f196928
/*  f1968ec:	8e4b00dc */ 	lw	$t3,0xdc($s2)
/*  f1968f0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1968f4:	3c014348 */ 	lui	$at,0x4348
/*  f1968f8:	4503000b */ 	bc1tl	.L0f196928
/*  f1968fc:	8e4b00dc */ 	lw	$t3,0xdc($s2)
/*  f196900:	44814000 */ 	mtc1	$at,$f8
/*  f196904:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196908:	4602403c */ 	c.lt.s	$f8,$f2
/*  f19690c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196910:	4502000e */ 	bc1fl	.L0f19694c
/*  f196914:	8e4e01dc */ 	lw	$t6,0x1dc($s2)
/*  f196918:	828a032d */ 	lb	$t2,0x32d($s4)
/*  f19691c:	0542000b */ 	bltzl	$t2,.L0f19694c
/*  f196920:	8e4e01dc */ 	lw	$t6,0x1dc($s2)
/*  f196924:	8e4b00dc */ 	lw	$t3,0xdc($s2)
.L0f196928:
/*  f196928:	02802025 */ 	or	$a0,$s4,$zero
/*  f19692c:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f196930:	1d60001e */ 	bgtz	$t3,.L0f1969ac
/*  f196934:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f196938:	0fc0e10f */ 	jal	func0f03843c
/*  f19693c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f196940:	1000001b */ 	beqz	$zero,.L0f1969b0
/*  f196944:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f196948:	8e4e01dc */ 	lw	$t6,0x1dc($s2)
.L0f19694c:
/*  f19694c:	51c00018 */ 	beqzl	$t6,.L0f1969b0
/*  f196950:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f196954:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f196958:	53cc0015 */ 	beql	$s8,$t4,.L0f1969b0
/*  f19695c:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f196960:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f196964:	53000012 */ 	beqzl	$t8,.L0f1969b0
/*  f196968:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f19696c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196970:	02802025 */ 	or	$a0,$s4,$zero
/*  f196974:	02802025 */ 	or	$a0,$s4,$zero
/*  f196978:	0fc64b70 */ 	jal	func0f192dc0
/*  f19697c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196980:	1040000a */ 	beqz	$v0,.L0f1969ac
/*  f196984:	240f002f */ 	addiu	$t7,$zero,0x2f
/*  f196988:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
/*  f19698c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196990:	02802025 */ 	or	$a0,$s4,$zero
/*  f196994:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196998:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19699c:	2419012c */ 	addiu	$t9,$zero,0x12c
/*  f1969a0:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1969a4:	ae5901d8 */ 	sw	$t9,0x1d8($s2)
/*  f1969a8:	a25e0074 */ 	sb	$s8,0x74($s2)
.L0f1969ac:
/*  f1969ac:	8e4900dc */ 	lw	$t1,0xdc($s2)
.L0f1969b0:
/*  f1969b0:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f1969b4:	1d200002 */ 	bgtz	$t1,.L0f1969c0
/*  f1969b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1969bc:	ae4d00dc */ 	sw	$t5,0xdc($s2)
.L0f1969c0:
/*  f1969c0:	0fc6519c */ 	jal	func0f194670
/*  f1969c4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1969c8:	1040006f */ 	beqz	$v0,.L0f196b88
/*  f1969cc:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f1969d0:	1000006d */ 	beqz	$zero,.L0f196b88
/*  f1969d4:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
/*  f1969d8:	2401002b */ 	addiu	$at,$zero,0x2b
.L0f1969dc:
/*  f1969dc:	1441002f */ 	bne	$v0,$at,.L0f196a9c
/*  f1969e0:	3c0b800b */ 	lui	$t3,0x800b
/*  f1969e4:	916bcb98 */ 	lbu	$t3,-0x3468($t3)
/*  f1969e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1969ec:	5561001f */ 	bnel	$t3,$at,.L0f196a6c
/*  f1969f0:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f1969f4:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f1969f8:	3c02800b */ 	lui	$v0,0x800b
/*  f1969fc:	000e67c2 */ 	srl	$t4,$t6,0x1f
/*  f196a00:	5180001a */ 	beqzl	$t4,.L0f196a6c
/*  f196a04:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a08:	8442c11e */ 	lh	$v0,-0x3ee2($v0)
/*  f196a0c:	8e5800bc */ 	lw	$t8,0xbc($s2)
/*  f196a10:	53020006 */ 	beql	$t8,$v0,.L0f196a2c
/*  f196a14:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f196a18:	924f004c */ 	lbu	$t7,0x4c($s2)
/*  f196a1c:	31f9ff7f */ 	andi	$t9,$t7,0xff7f
/*  f196a20:	10000011 */ 	beqz	$zero,.L0f196a68
/*  f196a24:	a259004c */ 	sb	$t9,0x4c($s2)
/*  f196a28:	8e89001c */ 	lw	$t1,0x1c($s4)
.L0f196a2c:
/*  f196a2c:	852d0028 */ 	lh	$t5,0x28($t1)
/*  f196a30:	51a2000e */ 	beql	$t5,$v0,.L0f196a6c
/*  f196a34:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a38:	86440048 */ 	lh	$a0,0x48($s2)
/*  f196a3c:	04820006 */ 	bltzl	$a0,.L0f196a58
/*  f196a40:	8644004a */ 	lh	$a0,0x4a($s2)
/*  f196a44:	0fc45890 */ 	jal	func0f116240
/*  f196a48:	3c050002 */ 	lui	$a1,0x2
/*  f196a4c:	10000007 */ 	beqz	$zero,.L0f196a6c
/*  f196a50:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a54:	8644004a */ 	lh	$a0,0x4a($s2)
.L0f196a58:
/*  f196a58:	04820004 */ 	bltzl	$a0,.L0f196a6c
/*  f196a5c:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a60:	0fc45942 */ 	jal	func0f116508
/*  f196a64:	24050100 */ 	addiu	$a1,$zero,0x100
.L0f196a68:
/*  f196a68:	828a0007 */ 	lb	$t2,0x7($s4)
.L0f196a6c:
/*  f196a6c:	2401000f */ 	addiu	$at,$zero,0xf
/*  f196a70:	240b0029 */ 	addiu	$t3,$zero,0x29
/*  f196a74:	11410003 */ 	beq	$t2,$at,.L0f196a84
/*  f196a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196a7c:	10000042 */ 	beqz	$zero,.L0f196b88
/*  f196a80:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
.L0f196a84:
/*  f196a84:	0fc6519c */ 	jal	func0f194670
/*  f196a88:	02802025 */ 	or	$a0,$s4,$zero
/*  f196a8c:	1040003e */ 	beqz	$v0,.L0f196b88
/*  f196a90:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f196a94:	1000003c */ 	beqz	$zero,.L0f196b88
/*  f196a98:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
.L0f196a9c:
/*  f196a9c:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f196aa0:	54410029 */ 	bnel	$v0,$at,.L0f196b48
/*  f196aa4:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f196aa8:	0fc6519c */ 	jal	func0f194670
/*  f196aac:	02802025 */ 	or	$a0,$s4,$zero
/*  f196ab0:	10400003 */ 	beqz	$v0,.L0f196ac0
/*  f196ab4:	240c0029 */ 	addiu	$t4,$zero,0x29
/*  f196ab8:	10000033 */ 	beqz	$zero,.L0f196b88
/*  f196abc:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.L0f196ac0:
/*  f196ac0:	82980007 */ 	lb	$t8,0x7($s4)
/*  f196ac4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f196ac8:	24190029 */ 	addiu	$t9,$zero,0x29
/*  f196acc:	17010008 */ 	bne	$t8,$at,.L0f196af0
/*  f196ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196ad4:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f196ad8:	10a00005 */ 	beqz	$a1,.L0f196af0
/*  f196adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196ae0:	8caf0018 */ 	lw	$t7,0x18($a1)
/*  f196ae4:	3c03800b */ 	lui	$v1,0x800b
/*  f196ae8:	11e00003 */ 	beqz	$t7,.L0f196af8
/*  f196aec:	00000000 */ 	sll	$zero,$zero,0x0
.L0f196af0:
/*  f196af0:	10000025 */ 	beqz	$zero,.L0f196b88
/*  f196af4:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.L0f196af8:
/*  f196af8:	9063cb98 */ 	lbu	$v1,-0x3468($v1)
/*  f196afc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f196b00:	12e30021 */ 	beq	$s7,$v1,.L0f196b88
/*  f196b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196b08:	1461001f */ 	bne	$v1,$at,.L0f196b88
/*  f196b0c:	3c09800b */ 	lui	$t1,0x800b
/*  f196b10:	8d29c24c */ 	lw	$t1,-0x3db4($t1)
/*  f196b14:	8e8d001c */ 	lw	$t5,0x1c($s4)
/*  f196b18:	152d001b */ 	bne	$t1,$t5,.L0f196b88
/*  f196b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196b20:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196b24:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b28:	3c0a800b */ 	lui	$t2,0x800b
/*  f196b2c:	854ac1e2 */ 	lh	$t2,-0x3e1e($t2)
/*  f196b30:	240b0029 */ 	addiu	$t3,$zero,0x29
/*  f196b34:	144a0014 */ 	bne	$v0,$t2,.L0f196b88
/*  f196b38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196b3c:	10000012 */ 	beqz	$zero,.L0f196b88
/*  f196b40:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f196b44:	2401002e */ 	addiu	$at,$zero,0x2e
.L0f196b48:
/*  f196b48:	1441000f */ 	bne	$v0,$at,.L0f196b88
/*  f196b4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196b50:	0fc6519c */ 	jal	func0f194670
/*  f196b54:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b58:	10400003 */ 	beqz	$v0,.L0f196b68
/*  f196b5c:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f196b60:	10000009 */ 	beqz	$zero,.L0f196b88
/*  f196b64:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
.L0f196b68:
/*  f196b68:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196b6c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b70:	3c0c800b */ 	lui	$t4,0x800b
/*  f196b74:	858cc1e2 */ 	lh	$t4,-0x3e1e($t4)
/*  f196b78:	24180029 */ 	addiu	$t8,$zero,0x29
/*  f196b7c:	104c0002 */ 	beq	$v0,$t4,.L0f196b88
/*  f196b80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196b84:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.L0f196b88:
/*  f196b88:	0fc64ba4 */ 	jal	func0f192e90
/*  f196b8c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b90:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196b94:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b98:	8ecf000c */ 	lw	$t7,0xc($s6)
/*  f196b9c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f196ba0:	01f9001a */ 	div	$zero,$t7,$t9
/*  f196ba4:	00004810 */ 	mfhi	$t1
/*  f196ba8:	17200002 */ 	bnez	$t9,.L0f196bb4
/*  f196bac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196bb0:	0007000d */ 	break	0x7
.L0f196bb4:
/*  f196bb4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f196bb8:	17210004 */ 	bne	$t9,$at,.L0f196bcc
/*  f196bbc:	3c018000 */ 	lui	$at,0x8000
/*  f196bc0:	15e10002 */ 	bne	$t7,$at,.L0f196bcc
/*  f196bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196bc8:	0006000d */ 	break	0x6
.L0f196bcc:
/*  f196bcc:	14490024 */ 	bne	$v0,$t1,.L0f196c60
/*  f196bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196bd4:	868d017e */ 	lh	$t5,0x17e($s4)
/*  f196bd8:	13cd0021 */ 	beq	$s8,$t5,.L0f196c60
/*  f196bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196be0:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196be4:	02802025 */ 	or	$a0,$s4,$zero
/*  f196be8:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f196bec:	00408025 */ 	or	$s0,$v0,$zero
/*  f196bf0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f196bf4:	0fc45095 */ 	jal	func0f114254
/*  f196bf8:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f196bfc:	00408825 */ 	or	$s1,$v0,$zero
/*  f196c00:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f196c04:	0fc45095 */ 	jal	func0f114254
/*  f196c08:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f196c0c:	12200014 */ 	beqz	$s1,.L0f196c60
/*  f196c10:	00408025 */ 	or	$s0,$v0,$zero
/*  f196c14:	10400012 */ 	beqz	$v0,.L0f196c60
/*  f196c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196c1c:	8eca0008 */ 	lw	$t2,0x8($s6)
/*  f196c20:	868c0000 */ 	lh	$t4,0x0($s4)
/*  f196c24:	000a5a43 */ 	sra	$t3,$t2,0x9
/*  f196c28:	000b71c0 */ 	sll	$t6,$t3,0x7
/*  f196c2c:	000cc0c0 */ 	sll	$t8,$t4,0x3
/*  f196c30:	01d82021 */ 	addu	$a0,$t6,$t8
/*  f196c34:	0fc45090 */ 	jal	func0f114240
/*  f196c38:	00802825 */ 	or	$a1,$a0,$zero
/*  f196c3c:	02002025 */ 	or	$a0,$s0,$zero
/*  f196c40:	02202825 */ 	or	$a1,$s1,$zero
/*  f196c44:	264601e8 */ 	addiu	$a2,$s2,0x1e8
/*  f196c48:	0fc4547b */ 	jal	func0f1151ec
/*  f196c4c:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f196c50:	ae420208 */ 	sw	$v0,0x208($s2)
/*  f196c54:	00002025 */ 	or	$a0,$zero,$zero
/*  f196c58:	0fc45090 */ 	jal	func0f114240
/*  f196c5c:	00002825 */ 	or	$a1,$zero,$zero
.L0f196c60:
/*  f196c60:	0fc663bb */ 	jal	func0f198eec
/*  f196c64:	02802025 */ 	or	$a0,$s4,$zero
/*  f196c68:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f196c6c:	00009825 */ 	or	$s3,$zero,$zero
/*  f196c70:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f196c74:	02408825 */ 	or	$s1,$s2,$zero
.L0f196c78:
/*  f196c78:	8e22005c */ 	lw	$v0,0x5c($s1)
/*  f196c7c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f196c80:	18400004 */ 	blez	$v0,.L0f196c94
/*  f196c84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196c88:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f196c8c:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f196c90:	ae39005c */ 	sw	$t9,0x5c($s1)
.L0f196c94:
/*  f196c94:	16770004 */ 	bne	$s3,$s7,.L0f196ca8
/*  f196c98:	8fa90088 */ 	lw	$t1,0x88($sp)
/*  f196c9c:	51200003 */ 	beqzl	$t1,.L0f196cac
/*  f196ca0:	8e4d0044 */ 	lw	$t5,0x44($s2)
/*  f196ca4:	ae37005c */ 	sw	$s7,0x5c($s1)
.L0f196ca8:
/*  f196ca8:	8e4d0044 */ 	lw	$t5,0x44($s2)
.L0f196cac:
/*  f196cac:	15a00207 */ 	bnez	$t5,.L0f1974cc
/*  f196cb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196cb4:	8e4a00cc */ 	lw	$t2,0xcc($s2)
/*  f196cb8:	1d400204 */ 	bgtz	$t2,.L0f1974cc
/*  f196cbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196cc0:	8e42004c */ 	lw	$v0,0x4c($s2)
/*  f196cc4:	00137040 */ 	sll	$t6,$s3,0x1
/*  f196cc8:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f196ccc:	00026040 */ 	sll	$t4,$v0,0x1
/*  f196cd0:	058300b5 */ 	bgezl	$t4,.L0f196fa8
/*  f196cd4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f196cd8:	8478003c */ 	lh	$t8,0x3c($v1)
/*  f196cdc:	070001fb */ 	bltz	$t8,.L0f1974cc
/*  f196ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196ce4:	846f002c */ 	lh	$t7,0x2c($v1)
/*  f196ce8:	1de001f8 */ 	bgtz	$t7,.L0f1974cc
/*  f196cec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196cf0:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f196cf4:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f196cf8:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f196cfc:	1721000d */ 	bne	$t9,$at,.L0f196d34
/*  f196d00:	02e02825 */ 	or	$a1,$s7,$zero
/*  f196d04:	0fc26d36 */ 	jal	func0f09b4d8
/*  f196d08:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196d0c:	8e290024 */ 	lw	$t1,0x24($s1)
/*  f196d10:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196d14:	02802025 */ 	or	$a0,$s4,$zero
/*  f196d18:	0122082a */ 	slt	$at,$t1,$v0
/*  f196d1c:	10200005 */ 	beqz	$at,.L0f196d34
/*  f196d20:	02602825 */ 	or	$a1,$s3,$zero
/*  f196d24:	0fc64da7 */ 	jal	func0f19369c
/*  f196d28:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d2c:	100001e7 */ 	beqz	$zero,.L0f1974cc
/*  f196d30:	00000000 */ 	sll	$zero,$zero,0x0
.L0f196d34:
/*  f196d34:	846d003c */ 	lh	$t5,0x3c($v1)
/*  f196d38:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f196d3c:	01aa5823 */ 	subu	$t3,$t5,$t2
/*  f196d40:	a46b003c */ 	sh	$t3,0x3c($v1)
/*  f196d44:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f196d48:	53cc0042 */ 	beql	$s8,$t4,.L0f196e54
/*  f196d4c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d50:	8e4e0128 */ 	lw	$t6,0x128($s2)
/*  f196d54:	51c0003f */ 	beqzl	$t6,.L0f196e54
/*  f196d58:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d5c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f196d60:	3c0d8008 */ 	lui	$t5,0x8008
/*  f196d64:	8e58011c */ 	lw	$t8,0x11c($s2)
/*  f196d68:	91f90048 */ 	lbu	$t9,0x48($t7)
/*  f196d6c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196d70:	00194940 */ 	sll	$t1,$t9,0x5
/*  f196d74:	01a96821 */ 	addu	$t5,$t5,$t1
/*  f196d78:	91ad7d14 */ 	lbu	$t5,0x7d14($t5)
/*  f196d7c:	030d082a */ 	slt	$at,$t8,$t5
/*  f196d80:	54200034 */ 	bnezl	$at,.L0f196e54
/*  f196d84:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d88:	0fc64098 */ 	jal	func0f190260
/*  f196d8c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196d90:	14400030 */ 	bnez	$v0,.L0f196e54
/*  f196d94:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196d98:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f196d9c:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f196da0:	02802025 */ 	or	$a0,$s4,$zero
/*  f196da4:	15410014 */ 	bne	$t2,$at,.L0f196df8
/*  f196da8:	24050028 */ 	addiu	$a1,$zero,0x28
/*  f196dac:	02802025 */ 	or	$a0,$s4,$zero
/*  f196db0:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f196db4:	00003025 */ 	or	$a2,$zero,$zero
/*  f196db8:	0fc1241a */ 	jal	func0f049068
/*  f196dbc:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196dc0:	1040000b */ 	beqz	$v0,.L0f196df0
/*  f196dc4:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196dc8:	02802025 */ 	or	$a0,$s4,$zero
/*  f196dcc:	0fc12472 */ 	jal	chrGetDistanceToTarget
/*  f196dd0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196dd4:	3c014352 */ 	lui	$at,0x4352
/*  f196dd8:	44813000 */ 	mtc1	$at,$f6
/*  f196ddc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196de0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f196de4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196de8:	4502001b */ 	bc1fl	.L0f196e58
/*  f196dec:	846b003c */ 	lh	$t3,0x3c($v1)
.L0f196df0:
/*  f196df0:	10000018 */ 	beqz	$zero,.L0f196e54
/*  f196df4:	a460003c */ 	sh	$zero,0x3c($v1)
.L0f196df8:
/*  f196df8:	00003025 */ 	or	$a2,$zero,$zero
/*  f196dfc:	0fc1241a */ 	jal	func0f049068
/*  f196e00:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196e04:	10400010 */ 	beqz	$v0,.L0f196e48
/*  f196e08:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196e0c:	3c014352 */ 	lui	$at,0x4352
/*  f196e10:	44815000 */ 	mtc1	$at,$f10
/*  f196e14:	3c014316 */ 	lui	$at,0x4316
/*  f196e18:	44819000 */ 	mtc1	$at,$f18
/*  f196e1c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196e20:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196e24:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f196e28:	0fc12472 */ 	jal	chrGetDistanceToTarget
/*  f196e2c:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f196e30:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f196e34:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196e38:	4600403c */ 	c.lt.s	$f8,$f0
/*  f196e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196e40:	45020005 */ 	bc1fl	.L0f196e58
/*  f196e44:	846b003c */ 	lh	$t3,0x3c($v1)
.L0f196e48:
/*  f196e48:	10000002 */ 	beqz	$zero,.L0f196e54
/*  f196e4c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196e50:	a460003c */ 	sh	$zero,0x3c($v1)
.L0f196e54:
/*  f196e54:	846b003c */ 	lh	$t3,0x3c($v1)
.L0f196e58:
/*  f196e58:	3c014352 */ 	lui	$at,0x4352
/*  f196e5c:	0561019b */ 	bgez	$t3,.L0f1974cc
/*  f196e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196e64:	44813000 */ 	mtc1	$at,$f6
/*  f196e68:	02802025 */ 	or	$a0,$s4,$zero
/*  f196e6c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f196e70:	44105000 */ 	mfc1	$s0,$f10
/*  f196e74:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f196e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196e7c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196e80:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f196e84:	02003025 */ 	or	$a2,$s0,$zero
/*  f196e88:	0fc0ee91 */ 	jal	func0f03ba44
/*  f196e8c:	00003825 */ 	or	$a3,$zero,$zero
/*  f196e90:	1660018e */ 	bnez	$s3,.L0f1974cc
/*  f196e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196e98:	8e4e0020 */ 	lw	$t6,0x20($s2)
/*  f196e9c:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f196ea0:	2de1001c */ 	sltiu	$at,$t7,0x1c
/*  f196ea4:	10200006 */ 	beqz	$at,.L0f196ec0
/*  f196ea8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f196eac:	3c017f1c */ 	lui	$at,%hi(var7f1b8f58)
/*  f196eb0:	002f0821 */ 	addu	$at,$at,$t7
/*  f196eb4:	8c2f8f58 */ 	lw	$t7,%lo(var7f1b8f58)($at)
/*  f196eb8:	01e00008 */ 	jr	$t7
/*  f196ebc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f196ec0:
/*  f196ec0:	8e9902d4 */ 	lw	$t9,0x2d4($s4)
/*  f196ec4:	24180078 */ 	addiu	$t8,$zero,0x78
/*  f196ec8:	8f290004 */ 	lw	$t1,0x4($t9)
/*  f196ecc:	91220048 */ 	lbu	$v0,0x48($t1)
/*  f196ed0:	14400003 */ 	bnez	$v0,.L0f196ee0
/*  f196ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196ed8:	10000007 */ 	beqz	$zero,.L0f196ef8
/*  f196edc:	a658003c */ 	sh	$t8,0x3c($s2)
.L0f196ee0:
/*  f196ee0:	16e20004 */ 	bne	$s7,$v0,.L0f196ef4
/*  f196ee4:	240a001e */ 	addiu	$t2,$zero,0x1e
/*  f196ee8:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f196eec:	10000002 */ 	beqz	$zero,.L0f196ef8
/*  f196ef0:	a64d003c */ 	sh	$t5,0x3c($s2)
.L0f196ef4:
/*  f196ef4:	a64a003c */ 	sh	$t2,0x3c($s2)
.L0f196ef8:
/*  f196ef8:	0c004b70 */ 	jal	random
/*  f196efc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196f00:	24010003 */ 	addiu	$at,$zero,0x3
/*  f196f04:	0041001b */ 	divu	$zero,$v0,$at
/*  f196f08:	00005810 */ 	mfhi	$t3
/*  f196f0c:	1560016f */ 	bnez	$t3,.L0f1974cc
/*  f196f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196f14:	864c003c */ 	lh	$t4,0x3c($s2)
/*  f196f18:	258effec */ 	addiu	$t6,$t4,-20
/*  f196f1c:	1000016b */ 	beqz	$zero,.L0f1974cc
/*  f196f20:	a64e003e */ 	sh	$t6,0x3e($s2)
/*  f196f24:	8e8f02d4 */ 	lw	$t7,0x2d4($s4)
/*  f196f28:	24090078 */ 	addiu	$t1,$zero,0x78
/*  f196f2c:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f196f30:	93220048 */ 	lbu	$v0,0x48($t9)
/*  f196f34:	14400003 */ 	bnez	$v0,.L0f196f44
/*  f196f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196f3c:	10000007 */ 	beqz	$zero,.L0f196f5c
/*  f196f40:	a649003c */ 	sh	$t1,0x3c($s2)
.L0f196f44:
/*  f196f44:	16e20004 */ 	bne	$s7,$v0,.L0f196f58
/*  f196f48:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f196f4c:	2418005a */ 	addiu	$t8,$zero,0x5a
/*  f196f50:	10000002 */ 	beqz	$zero,.L0f196f5c
/*  f196f54:	a658003c */ 	sh	$t8,0x3c($s2)
.L0f196f58:
/*  f196f58:	a64d003c */ 	sh	$t5,0x3c($s2)
.L0f196f5c:
/*  f196f5c:	8e8a0174 */ 	lw	$t2,0x174($s4)
/*  f196f60:	1140015a */ 	beqz	$t2,.L0f1974cc
/*  f196f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196f68:	864b003c */ 	lh	$t3,0x3c($s2)
/*  f196f6c:	256cffd8 */ 	addiu	$t4,$t3,-40
/*  f196f70:	10000156 */ 	beqz	$zero,.L0f1974cc
/*  f196f74:	a64c003e */ 	sh	$t4,0x3e($s2)
/*  f196f78:	240e003c */ 	addiu	$t6,$zero,0x3c
/*  f196f7c:	a64e003c */ 	sh	$t6,0x3c($s2)
/*  f196f80:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f196f84:	0fc26d36 */ 	jal	func0f09b4d8
/*  f196f88:	02e02825 */ 	or	$a1,$s7,$zero
/*  f196f8c:	8e4f0024 */ 	lw	$t7,0x24($s2)
/*  f196f90:	01e2c823 */ 	subu	$t9,$t7,$v0
/*  f196f94:	1000014d */ 	beqz	$zero,.L0f1974cc
/*  f196f98:	ae590024 */ 	sw	$t9,0x24($s2)
/*  f196f9c:	1000014b */ 	beqz	$zero,.L0f1974cc
/*  f196fa0:	a640003c */ 	sh	$zero,0x3c($s2)
/*  f196fa4:	8e440020 */ 	lw	$a0,0x20($s2)
.L0f196fa8:
/*  f196fa8:	24010019 */ 	addiu	$at,$zero,0x19
/*  f196fac:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f196fb0:	14810011 */ 	bne	$a0,$at,.L0f196ff8
/*  f196fb4:	00022880 */ 	sll	$a1,$v0,0x2
/*  f196fb8:	07030010 */ 	bgezl	$t8,.L0f196ffc
/*  f196fbc:	000577c2 */ 	srl	$t6,$a1,0x1f
/*  f196fc0:	868d017e */ 	lh	$t5,0x17e($s4)
/*  f196fc4:	53cd000d */ 	beql	$s8,$t5,.L0f196ffc
/*  f196fc8:	000577c2 */ 	srl	$t6,$a1,0x1f
/*  f196fcc:	8e4a0024 */ 	lw	$t2,0x24($s2)
/*  f196fd0:	1940013e */ 	blez	$t2,.L0f1974cc
/*  f196fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f196fd8:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f196fdc:	02802025 */ 	or	$a0,$s4,$zero
/*  f196fe0:	0fc66a14 */ 	jal	func0f19a850
/*  f196fe4:	02802025 */ 	or	$a0,$s4,$zero
/*  f196fe8:	8e4b0024 */ 	lw	$t3,0x24($s2)
/*  f196fec:	256cffff */ 	addiu	$t4,$t3,-1
/*  f196ff0:	10000136 */ 	beqz	$zero,.L0f1974cc
/*  f196ff4:	ae4c0024 */ 	sw	$t4,0x24($s2)
.L0f196ff8:
/*  f196ff8:	000577c2 */ 	srl	$t6,$a1,0x1f
.L0f196ffc:
/*  f196ffc:	0fc668a7 */ 	jal	func0f19a29c
/*  f197000:	01c02825 */ 	or	$a1,$t6,$zero
/*  f197004:	1040005b */ 	beqz	$v0,.L0f197174
/*  f197008:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f19700c:	1660012f */ 	bnez	$s3,.L0f1974cc
/*  f197010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197014:	8e420034 */ 	lw	$v0,0x34($s2)
/*  f197018:	02402025 */ 	or	$a0,$s2,$zero
/*  f19701c:	58400005 */ 	blezl	$v0,.L0f197034
/*  f197020:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197024:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f197028:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f19702c:	ae590034 */ 	sw	$t9,0x34($s2)
/*  f197030:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
.L0f197034:
/*  f197034:	8d380034 */ 	lw	$t8,0x34($t1)
/*  f197038:	1f000124 */ 	bgtz	$t8,.L0f1974cc
/*  f19703c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197040:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f197044:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f197048:	00003825 */ 	or	$a3,$zero,$zero
/*  f19704c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f197050:	0fc666f9 */ 	jal	func0f199be4
/*  f197054:	000d37c2 */ 	srl	$a2,$t5,0x1f
/*  f197058:	5c400008 */ 	bgtzl	$v0,.L0f19707c
/*  f19705c:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f197060:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f197064:	2401000e */ 	addiu	$at,$zero,0xe
/*  f197068:	10810003 */ 	beq	$a0,$at,.L0f197078
/*  f19706c:	2401000f */ 	addiu	$at,$zero,0xf
/*  f197070:	14810116 */ 	bne	$a0,$at,.L0f1974cc
/*  f197074:	00000000 */ 	sll	$zero,$zero,0x0
.L0f197078:
/*  f197078:	868b017e */ 	lh	$t3,0x17e($s4)
.L0f19707c:
/*  f19707c:	00008025 */ 	or	$s0,$zero,$zero
/*  f197080:	13cb0018 */ 	beq	$s8,$t3,.L0f1970e4
/*  f197084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197088:	8e4c0128 */ 	lw	$t4,0x128($s2)
/*  f19708c:	11800015 */ 	beqz	$t4,.L0f1970e4
/*  f197090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197094:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f197098:	3c188008 */ 	lui	$t8,0x8008
/*  f19709c:	8e4e011c */ 	lw	$t6,0x11c($s2)
/*  f1970a0:	91f90048 */ 	lbu	$t9,0x48($t7)
/*  f1970a4:	00194940 */ 	sll	$t1,$t9,0x5
/*  f1970a8:	0309c021 */ 	addu	$t8,$t8,$t1
/*  f1970ac:	93187d14 */ 	lbu	$t8,0x7d14($t8)
/*  f1970b0:	01d8082a */ 	slt	$at,$t6,$t8
/*  f1970b4:	1420000b */ 	bnez	$at,.L0f1970e4
/*  f1970b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1970bc:	0fc64098 */ 	jal	func0f190260
/*  f1970c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1970c4:	14400006 */ 	bnez	$v0,.L0f1970e0
/*  f1970c8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1970cc:	2405002d */ 	addiu	$a1,$zero,0x2d
/*  f1970d0:	0fc1241a */ 	jal	func0f049068
/*  f1970d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1970d8:	10400002 */ 	beqz	$v0,.L0f1970e4
/*  f1970dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1970e0:
/*  f1970e0:	02e08025 */ 	or	$s0,$s7,$zero
.L0f1970e4:
/*  f1970e4:	120000f9 */ 	beqz	$s0,.L0f1974cc
/*  f1970e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1970ec:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f1970f0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1970f4:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f1970f8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1970fc:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f197100:	00066880 */ 	sll	$t5,$a2,0x2
/*  f197104:	000d37c2 */ 	srl	$a2,$t5,0x1f
/*  f197108:	0fc6675c */ 	jal	func0f199d70
/*  f19710c:	02e03825 */ 	or	$a3,$s7,$zero
/*  f197110:	0fc668df */ 	jal	func0f19a37c
/*  f197114:	02802025 */ 	or	$a0,$s4,$zero
/*  f197118:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19711c:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f197120:	00055880 */ 	sll	$t3,$a1,0x2
/*  f197124:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f197128:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f19712c:	5040000d */ 	beqzl	$v0,.L0f197164
/*  f197130:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197134:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f197138:	02802025 */ 	or	$a0,$s4,$zero
/*  f19713c:	000fcb40 */ 	sll	$t9,$t7,0xd
/*  f197140:	07230008 */ 	bgezl	$t9,.L0f197164
/*  f197144:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197148:	0fc65f65 */ 	jal	func0f197d94
/*  f19714c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f197150:	02802025 */ 	or	$a0,$s4,$zero
/*  f197154:	02e02825 */ 	or	$a1,$s7,$zero
/*  f197158:	0fc6652c */ 	jal	func0f1994b0
/*  f19715c:	00003025 */ 	or	$a2,$zero,$zero
/*  f197160:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
.L0f197164:
/*  f197164:	0fc668b7 */ 	jal	func0f19a2dc
/*  f197168:	8d240020 */ 	lw	$a0,0x20($t1)
/*  f19716c:	100000d7 */ 	beqz	$zero,.L0f1974cc
/*  f197170:	ae420034 */ 	sw	$v0,0x34($s2)
.L0f197174:
/*  f197174:	028ec021 */ 	addu	$t8,$s4,$t6
/*  f197178:	8f0d0170 */ 	lw	$t5,0x170($t8)
/*  f19717c:	02537821 */ 	addu	$t7,$s2,$s3
/*  f197180:	51a000ce */ 	beqzl	$t5,.L0f1974bc
/*  f197184:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f197188:	8e2a0024 */ 	lw	$t2,0x24($s1)
/*  f19718c:	594000cb */ 	blezl	$t2,.L0f1974bc
/*  f197190:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f197194:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f197198:	00008025 */ 	or	$s0,$zero,$zero
/*  f19719c:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1971a0:	00055880 */ 	sll	$t3,$a1,0x2
/*  f1971a4:	0fc2c7ba */ 	jal	func0f0b1ee8
/*  f1971a8:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f1971ac:	5c400030 */ 	bgtzl	$v0,.L0f197270
/*  f1971b0:	02e08025 */ 	or	$s0,$s7,$zero
/*  f1971b4:	8e4f0020 */ 	lw	$t7,0x20($s2)
/*  f1971b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1971bc:	55e10027 */ 	bnel	$t7,$at,.L0f19725c
/*  f1971c0:	8e2f005c */ 	lw	$t7,0x5c($s1)
/*  f1971c4:	8e59004c */ 	lw	$t9,0x4c($s2)
/*  f1971c8:	00194880 */ 	sll	$t1,$t9,0x2
/*  f1971cc:	000977c2 */ 	srl	$t6,$t1,0x1f
/*  f1971d0:	56ee0022 */ 	bnel	$s7,$t6,.L0f19725c
/*  f1971d4:	8e2f005c */ 	lw	$t7,0x5c($s1)
/*  f1971d8:	8e380024 */ 	lw	$t8,0x24($s1)
/*  f1971dc:	2b010002 */ 	slti	$at,$t8,0x2
/*  f1971e0:	1420001d */ 	bnez	$at,.L0f197258
/*  f1971e4:	3c017f1c */ 	lui	$at,%hi(var7f1b8fc8)
/*  f1971e8:	c4288fc8 */ 	lwc1	$f8,%lo(var7f1b8fc8)($at)
/*  f1971ec:	c6c4004c */ 	lwc1	$f4,0x4c($s6)
/*  f1971f0:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f1971f4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1971f8:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f1971fc:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f197200:	44039000 */ 	mfc1	$v1,$f18
/*  f197204:	44819000 */ 	mtc1	$at,$f18
/*  f197208:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f19720c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f197210:	e62a00e4 */ 	swc1	$f10,0xe4($s1)
/*  f197214:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f197218:	4600903c */ 	c.lt.s	$f18,$f0
/*  f19721c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197220:	45020006 */ 	bc1fl	.L0f19723c
/*  f197224:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f197228:	44812000 */ 	mtc1	$at,$f4
/*  f19722c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197230:	e62400e4 */ 	swc1	$f4,0xe4($s1)
/*  f197234:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f197238:	4600020d */ 	trunc.w.s	$f8,$f0
.L0f19723c:
/*  f19723c:	44024000 */ 	mfc1	$v0,$f8
/*  f197240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197244:	50430005 */ 	beql	$v0,$v1,.L0f19725c
/*  f197248:	8e2f005c */ 	lw	$t7,0x5c($s1)
/*  f19724c:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f197250:	256cffff */ 	addiu	$t4,$t3,-1
/*  f197254:	ae2c0024 */ 	sw	$t4,0x24($s1)
.L0f197258:
/*  f197258:	8e2f005c */ 	lw	$t7,0x5c($s1)
.L0f19725c:
/*  f19725c:	1de00004 */ 	bgtz	$t7,.L0f197270
/*  f197260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197264:	10000002 */ 	beqz	$zero,.L0f197270
/*  f197268:	02e08025 */ 	or	$s0,$s7,$zero
/*  f19726c:	02e08025 */ 	or	$s0,$s7,$zero
.L0f197270:
/*  f197270:	52000052 */ 	beqzl	$s0,.L0f1973bc
/*  f197274:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f197278:	8e3900c4 */ 	lw	$t9,0xc4($s1)
/*  f19727c:	02534821 */ 	addu	$t1,$s2,$s3
/*  f197280:	17200004 */ 	bnez	$t9,.L0f197294
/*  f197284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197288:	912e004d */ 	lbu	$t6,0x4d($t1)
/*  f19728c:	59c00004 */ 	blezl	$t6,.L0f1972a0
/*  f197290:	8698017e */ 	lh	$t8,0x17e($s4)
.L0f197294:
/*  f197294:	1000003a */ 	beqz	$zero,.L0f197380
/*  f197298:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f19729c:	8698017e */ 	lh	$t8,0x17e($s4)
.L0f1972a0:
/*  f1972a0:	13d80037 */ 	beq	$s8,$t8,.L0f197380
/*  f1972a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1972a8:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f1972ac:	11a00034 */ 	beqz	$t5,.L0f197380
/*  f1972b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1972b4:	8e4b0004 */ 	lw	$t3,0x4($s2)
/*  f1972b8:	3c198008 */ 	lui	$t9,0x8008
/*  f1972bc:	8e4a011c */ 	lw	$t2,0x11c($s2)
/*  f1972c0:	916c0048 */ 	lbu	$t4,0x48($t3)
/*  f1972c4:	000c7940 */ 	sll	$t7,$t4,0x5
/*  f1972c8:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f1972cc:	93397d14 */ 	lbu	$t9,0x7d14($t9)
/*  f1972d0:	0159082a */ 	slt	$at,$t2,$t9
/*  f1972d4:	1420002a */ 	bnez	$at,.L0f197380
/*  f1972d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1972dc:	0fc64098 */ 	jal	func0f190260
/*  f1972e0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1972e4:	14400006 */ 	bnez	$v0,.L0f197300
/*  f1972e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1972ec:	2405002d */ 	addiu	$a1,$zero,0x2d
/*  f1972f0:	0fc1241a */ 	jal	func0f049068
/*  f1972f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1972f8:	10400021 */ 	beqz	$v0,.L0f197380
/*  f1972fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f197300:
/*  f197300:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f197304:	02802025 */ 	or	$a0,$s4,$zero
/*  f197308:	0fc0e6a5 */ 	jal	chrIsDead
/*  f19730c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197310:	1440001b */ 	bnez	$v0,.L0f197380
/*  f197314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197318:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f19731c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f197320:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f197324:	54810009 */ 	bnel	$a0,$at,.L0f19734c
/*  f197328:	24010014 */ 	addiu	$at,$zero,0x14
/*  f19732c:	8e49004c */ 	lw	$t1,0x4c($s2)
/*  f197330:	00097080 */ 	sll	$t6,$t1,0x2
/*  f197334:	000ec7c2 */ 	srl	$t8,$t6,0x1f
/*  f197338:	56f80004 */ 	bnel	$s7,$t8,.L0f19734c
/*  f19733c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f197340:	1000000f */ 	beqz	$zero,.L0f197380
/*  f197344:	ae3700c4 */ 	sw	$s7,0xc4($s1)
/*  f197348:	24010014 */ 	addiu	$at,$zero,0x14
.L0f19734c:
/*  f19734c:	1481000c */ 	bne	$a0,$at,.L0f197380
/*  f197350:	00136840 */ 	sll	$t5,$s3,0x1
/*  f197354:	024d1821 */ 	addu	$v1,$s2,$t5
/*  f197358:	846b00e0 */ 	lh	$t3,0xe0($v1)
/*  f19735c:	8ecc0038 */ 	lw	$t4,0x38($s6)
/*  f197360:	2419005a */ 	addiu	$t9,$zero,0x5a
/*  f197364:	016c7821 */ 	addu	$t7,$t3,$t4
/*  f197368:	a46f00e0 */ 	sh	$t7,0xe0($v1)
/*  f19736c:	846a00e0 */ 	lh	$t2,0xe0($v1)
/*  f197370:	2941005b */ 	slti	$at,$t2,0x5b
/*  f197374:	14200002 */ 	bnez	$at,.L0f197380
/*  f197378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19737c:	a47900e0 */ 	sh	$t9,0xe0($v1)
.L0f197380:
/*  f197380:	16a0000d */ 	bnez	$s5,.L0f1973b8
/*  f197384:	00134840 */ 	sll	$t1,$s3,0x1
/*  f197388:	02491821 */ 	addu	$v1,$s2,$t1
/*  f19738c:	846200e0 */ 	lh	$v0,0xe0($v1)
/*  f197390:	5840000a */ 	blezl	$v0,.L0f1973bc
/*  f197394:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f197398:	8ece0038 */ 	lw	$t6,0x38($s6)
/*  f19739c:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f1973a0:	004ec023 */ 	subu	$t8,$v0,$t6
/*  f1973a4:	a47800e0 */ 	sh	$t8,0xe0($v1)
/*  f1973a8:	846d00e0 */ 	lh	$t5,0xe0($v1)
/*  f1973ac:	05a30003 */ 	bgezl	$t5,.L0f1973bc
/*  f1973b0:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1973b4:	a46000e0 */ 	sh	$zero,0xe0($v1)
.L0f1973b8:
/*  f1973b8:	8e45004c */ 	lw	$a1,0x4c($s2)
.L0f1973bc:
/*  f1973bc:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1973c0:	00055880 */ 	sll	$t3,$a1,0x2
/*  f1973c4:	0fc2c7ba */ 	jal	func0f0b1ee8
/*  f1973c8:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f1973cc:	1c40003f */ 	bgtz	$v0,.L0f1974cc
/*  f1973d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1973d4:	12a0003d */ 	beqz	$s5,.L0f1974cc
/*  f1973d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1973dc:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1973e0:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1973e4:	00057880 */ 	sll	$t7,$a1,0x2
/*  f1973e8:	0fc66983 */ 	jal	func0f19a60c
/*  f1973ec:	000f2fc2 */ 	srl	$a1,$t7,0x1f
/*  f1973f0:	ae22005c */ 	sw	$v0,0x5c($s1)
/*  f1973f4:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1973f8:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1973fc:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f197400:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f197404:	00192fc2 */ 	srl	$a1,$t9,0x1f
/*  f197408:	10400030 */ 	beqz	$v0,.L0f1974cc
/*  f19740c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197410:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f197414:	306e1002 */ 	andi	$t6,$v1,0x1002
/*  f197418:	11c0002c */ 	beqz	$t6,.L0f1974cc
/*  f19741c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197420:	8e380024 */ 	lw	$t8,0x24($s1)
/*  f197424:	306d1000 */ 	andi	$t5,$v1,0x1000
/*  f197428:	2b010002 */ 	slti	$at,$t8,0x2
/*  f19742c:	14200027 */ 	bnez	$at,.L0f1974cc
/*  f197430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197434:	11a00003 */ 	beqz	$t5,.L0f197444
/*  f197438:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f19743c:	10000001 */ 	beqz	$zero,.L0f197444
/*  f197440:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f197444:
/*  f197444:	8e8b02d4 */ 	lw	$t3,0x2d4($s4)
/*  f197448:	01731021 */ 	addu	$v0,$t3,$s3
/*  f19744c:	904c004d */ 	lbu	$t4,0x4d($v0)
/*  f197450:	258f0001 */ 	addiu	$t7,$t4,0x1
/*  f197454:	a04f004d */ 	sb	$t7,0x4d($v0)
/*  f197458:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f19745c:	01531021 */ 	addu	$v0,$t2,$s3
/*  f197460:	9059004d */ 	lbu	$t9,0x4d($v0)
/*  f197464:	0324001a */ 	div	$zero,$t9,$a0
/*  f197468:	00004810 */ 	mfhi	$t1
/*  f19746c:	a049004d */ 	sb	$t1,0x4d($v0)
/*  f197470:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f197474:	14800002 */ 	bnez	$a0,.L0f197480
/*  f197478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19747c:	0007000d */ 	break	0x7
.L0f197480:
/*  f197480:	2401ffff */ 	addiu	$at,$zero,-1
/*  f197484:	14810004 */ 	bne	$a0,$at,.L0f197498
/*  f197488:	3c018000 */ 	lui	$at,0x8000
/*  f19748c:	17210002 */ 	bne	$t9,$at,.L0f197498
/*  f197490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f197494:	0006000d */ 	break	0x6
.L0f197498:
/*  f197498:	00737021 */ 	addu	$t6,$v1,$s3
/*  f19749c:	91d8004d */ 	lbu	$t8,0x4d($t6)
/*  f1974a0:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f1974a4:	13000009 */ 	beqz	$t8,.L0f1974cc
/*  f1974a8:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f1974ac:	006b6021 */ 	addu	$t4,$v1,$t3
/*  f1974b0:	10000006 */ 	beqz	$zero,.L0f1974cc
/*  f1974b4:	ad8d005c */ 	sw	$t5,0x5c($t4)
/*  f1974b8:	ae2000c4 */ 	sw	$zero,0xc4($s1)
.L0f1974bc:
/*  f1974bc:	00135040 */ 	sll	$t2,$s3,0x1
/*  f1974c0:	a1e0004d */ 	sb	$zero,0x4d($t7)
/*  f1974c4:	024ac821 */ 	addu	$t9,$s2,$t2
/*  f1974c8:	a72000e0 */ 	sh	$zero,0xe0($t9)
.L0f1974cc:
/*  f1974cc:	52a00007 */ 	beqzl	$s5,.L0f1974ec
/*  f1974d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1974d4:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f1974d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1974dc:	56600003 */ 	bnezl	$s3,.L0f1974ec
/*  f1974e0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1974e4:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f1974e8:	02802025 */ 	or	$a0,$s4,$zero
.L0f1974ec:
/*  f1974ec:	02602825 */ 	or	$a1,$s3,$zero
/*  f1974f0:	0fc0fe62 */ 	jal	func0f03f988
/*  f1974f4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1974f8:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f1974fc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f197500:	24010002 */ 	addiu	$at,$zero,0x2
/*  f197504:	252e0004 */ 	addiu	$t6,$t1,0x4
/*  f197508:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f19750c:	1661fdda */ 	bne	$s3,$at,.L0f196c78
/*  f197510:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f197514:
/*  f197514:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f197518:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f19751c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f197520:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f197524:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f197528:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f19752c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f197530:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f197534:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f197538:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f19753c:	03e00008 */ 	jr	$ra
/*  f197540:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);

void func0f197544(struct chrdata *chr)
{
	bool pass = false;
	struct chr2d4 *chr2d4 = chr->unk2d4;

	if (chr->myaction == MA_AIBOTGETITEM) {
		if (chr->act_aibotgetitem.unk4c[chr->unk064] == 0) {
			struct prop *prop = chr2d4->prop;

			if (prop && !prop->parent && prop->timetoregen == 0) {
				if (prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ) {
					prop->obj->flags3 |= OBJECTFLAG2_00004000;
				}
			}
		}

		chr2d4->unkd8 = 1;
		pass = true;
	}

	if (!pass) {
		func0f03843c(chr, &chr->act_aibotgetitem.pos, &chr->act_aibotgetitem.rooms[0], chr->speed);
	}
}
