#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "library/library_09660.h"
#include "library/library_0d520.h"
#include "library/library_0e9d0.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_00c490.h"
#include "game/game_015470.h"
#include "game/game_066310.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/pdoptions.h"
#include "game/game_152fa0.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_187770.h"
#include "game/game_1999b0.h"
#include "game/game_19c990.h"

const char var7f1b2cf0[] = "%s\n";
const char var7f1b2cf4[] = "%s: %s\n";
const char var7f1b2cfc[] = "%s%s%.00f%%\n";
const char var7f1b2d0c[] = "";
const char var7f1b2d10[] = "";
const char var7f1b2d14[] = "--:--\n";
const char var7f1b2d1c[] = "==:==\n";
const char var7f1b2d24[] = "%dm:%02ds";
const char var7f1b2d30[] = "%dh:%02dm:%02ds";

const u32 var7f1b2d40[] = {0x57055706};
const u32 var7f1b2d44[] = {0x57075708};
const u32 var7f1b2d48[] = {0x57090000};
const u32 var7f1b2d4c[] = {0x570f5710};

const char var7f1b2d50[] = "\n";
const char var7f1b2d54[] = "%s: %s\n";

const u32 var7f1b2d5c[] = {0x7f102398};
const u32 var7f1b2d60[] = {0x7f1023a4};
const u32 var7f1b2d64[] = {0x7f1023b0};
const u32 var7f1b2d68[] = {0x7f1023d0};
const u32 var7f1b2d6c[] = {0x7f1023ec};
const u32 var7f1b2d70[] = {0x7f10240c};
const u32 var7f1b2d74[] = {0x7f102430};
const u32 var7f1b2d78[] = {0x7f1024c8};
const u32 var7f1b2d7c[] = {0x7f1024c8};
const u32 var7f1b2d80[] = {0x7f1024c8};
const u32 var7f1b2d84[] = {0x7f1024c8};
const u32 var7f1b2d88[] = {0x7f1024c8};
const u32 var7f1b2d8c[] = {0x7f1024c8};
const u32 var7f1b2d90[] = {0x7f1024c8};
const u32 var7f1b2d94[] = {0x7f1024c8};
const u32 var7f1b2d98[] = {0x7f102480};
const u32 var7f1b2d9c[] = {0x7f1047ec};
const u32 var7f1b2da0[] = {0x7f104b00};
const u32 var7f1b2da4[] = {0x7f1048b0};
const u32 var7f1b2da8[] = {0x7f104b6c};
const u32 var7f1b2dac[] = {0x7f104ba0};
const u32 var7f1b2db0[] = {0x7f10493c};
const u32 var7f1b2db4[] = {0x7f104a14};
const u32 var7f1b2db8[] = {0x7f105584};
const u32 var7f1b2dbc[] = {0x7f105584};
const u32 var7f1b2dc0[] = {0x7f105584};
const u32 var7f1b2dc4[] = {0x7f105584};
const u32 var7f1b2dc8[] = {0x7f105584};
const u32 var7f1b2dcc[] = {0x7f105584};
const u32 var7f1b2dd0[] = {0x7f105584};
const u32 var7f1b2dd4[] = {0x7f105584};
const u32 var7f1b2dd8[] = {0x7f105584};
const u32 var7f1b2ddc[] = {0x7f105584};
const u32 var7f1b2de0[] = {0x7f105584};
const u32 var7f1b2de4[] = {0x7f104be8};
const u32 var7f1b2de8[] = {0x7f10557c};
const u32 var7f1b2dec[] = {0x7f105584};
const u32 var7f1b2df0[] = {0x7f105584};
const u32 var7f1b2df4[] = {0x7f105584};
const u32 var7f1b2df8[] = {0x7f105584};
const u32 var7f1b2dfc[] = {0x7f104a24};
const u32 var7f1b2e00[] = {0xbe4ccccd};
const u32 var7f1b2e04[] = {0x4196cbe4};
const u32 var7f1b2e08[] = {0x7f106070};
const u32 var7f1b2e0c[] = {0x7f106058};
const u32 var7f1b2e10[] = {0x7f106084};
const u32 var7f1b2e14[] = {0x7f106060};
const u32 var7f1b2e18[] = {0x7f106068};
const u32 var7f1b2e1c[] = {0x7f1060a4};
const u32 var7f1b2e20[] = {0x7f1060b8};
const u32 var7f1b2e24[] = {0x7f106164};
const u32 var7f1b2e28[] = {0x7f106164};
const u32 var7f1b2e2c[] = {0x7f106164};
const u32 var7f1b2e30[] = {0x7f106164};
const u32 var7f1b2e34[] = {0x7f106164};
const u32 var7f1b2e38[] = {0x7f106164};
const u32 var7f1b2e3c[] = {0x7f106164};
const u32 var7f1b2e40[] = {0x7f106164};
const u32 var7f1b2e44[] = {0x7f1060c8};
const u32 var7f1b2e48[] = {0x7f1061ac};
const u32 var7f1b2e4c[] = {0x7f106380};
const u32 var7f1b2e50[] = {0x7f1061c0};
const u32 var7f1b2e54[] = {0x7f106380};
const u32 var7f1b2e58[] = {0x7f106380};
const u32 var7f1b2e5c[] = {0x7f1061d4};
const u32 var7f1b2e60[] = {0x7f1062b0};
const u32 var7f1b2e64[] = {0x7f106380};
const u32 var7f1b2e68[] = {0x7f106380};
const u32 var7f1b2e6c[] = {0x7f106380};
const u32 var7f1b2e70[] = {0x7f106380};
const u32 var7f1b2e74[] = {0x7f106380};
const u32 var7f1b2e78[] = {0x7f106380};
const u32 var7f1b2e7c[] = {0x7f1062c4};
const u32 var7f1b2e80[] = {0x7f106380};
const u32 var7f1b2e84[] = {0x7f1062f4};
const u32 var7f1b2e88[] = {0x7f1066b4};
const u32 var7f1b2e8c[] = {0x7f1067ac};
const u32 var7f1b2e90[] = {0x7f1066dc};
const u32 var7f1b2e94[] = {0x7f1067b8};
const u32 var7f1b2e98[] = {0x7f1067d4};
const u32 var7f1b2e9c[] = {0x7f10672c};
const u32 var7f1b2ea0[] = {0x7f10679c};
const u32 var7f1b2ea4[] = {0x00000000};
const u32 var7f1b2ea8[] = {0x00000000};
const u32 var7f1b2eac[] = {0x00000000};

GLOBAL_ASM(
glabel func0f102240
/*  f102240:	3c0e800a */ 	lui	$t6,0x800a
/*  f102244:	91cedfea */ 	lbu	$t6,-0x2016($t6)
/*  f102248:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10224c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f102250:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f102254:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f102258:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10225c:	3c048007 */ 	lui	$a0,0x8007
/*  f102260:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f102264:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f102268:	0fc5b9f1 */ 	jal	textGet
/*  f10226c:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f102270:	3c048007 */ 	lui	$a0,0x8007
/*  f102274:	3c057f1b */ 	lui	$a1,%hi(var7f1b2cf0)
/*  f102278:	24a52cf0 */ 	addiu	$a1,$a1,%lo(var7f1b2cf0)
/*  f10227c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f102280:	0c004dad */ 	jal	sprintf
/*  f102284:	00403025 */ 	or	$a2,$v0,$zero
/*  f102288:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10228c:	3c028007 */ 	lui	$v0,0x8007
/*  f102290:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f102294:	03e00008 */ 	jr	$ra
/*  f102298:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

char *menutextDifficulty(s32 arg0)
{
	if (g_MissionConfig.pdmode) {
		return textGet(0x54dd);
	}

	switch (g_MissionConfig.difficulty) {
	case DIFF_SA:
		return textGet(0x56fc);
	case DIFF_PA:
		return textGet(0x56fd);
	case DIFF_A:
	default:
		return textGet(0x56fb);
	}
}

GLOBAL_ASM(
glabel func0f102330
/*  f102330:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f102334:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f102338:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10233c:	3c0e8007 */ 	lui	$t6,%hi(options_controlmode)
/*  f102340:	8c480298 */ 	lw	$t0,0x298($v0)
/*  f102344:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f102348:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f10234c:	25ce19e0 */ 	addiu	$t6,$t6,%lo(options_controlmode)
/*  f102350:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f102354:	27a3001c */ 	addiu	$v1,$sp,0x1c
/*  f102358:	05010004 */ 	bgez	$t0,.L0f10236c
/*  f10235c:	ac610000 */ 	sw	$at,0x0($v1)
/*  f102360:	8c49029c */ 	lw	$t1,0x29c($v0)
/*  f102364:	05220004 */ 	bltzl	$t1,.L0f102378
/*  f102368:	248bffff */ 	addiu	$t3,$a0,-1
.L0f10236c:
/*  f10236c:	8c4a0288 */ 	lw	$t2,0x288($v0)
/*  f102370:	8d470070 */ 	lw	$a3,0x70($t2)
/*  f102374:	248bffff */ 	addiu	$t3,$a0,-1
.L0f102378:
/*  f102378:	2d610010 */ 	sltiu	$at,$t3,0x10
/*  f10237c:	10200052 */ 	beqz	$at,.L0f1024c8
/*  f102380:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f102384:	3c017f1b */ 	lui	$at,%hi(var7f1b2d5c)
/*  f102388:	002b0821 */ 	addu	$at,$at,$t3
/*  f10238c:	8c2b2d5c */ 	lw	$t3,%lo(var7f1b2d5c)($at)
/*  f102390:	01600008 */ 	jr	$t3
/*  f102394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f102398:	240c0008 */ 	addiu	$t4,$zero,0x8
/*  f10239c:	1000004a */ 	beqz	$zero,.L0f1024c8
/*  f1023a0:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f1023a4:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f1023a8:	10000047 */ 	beqz	$zero,.L0f1024c8
/*  f1023ac:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f1023b0:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1023b4:	3c048007 */ 	lui	$a0,0x8007
/*  f1023b8:	00187840 */ 	sll	$t7,$t8,0x1
/*  f1023bc:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f1023c0:	0fc5b9f1 */ 	jal	textGet
/*  f1023c4:	948419d0 */ 	lhu	$a0,0x19d0($a0)
/*  f1023c8:	10000041 */ 	beqz	$zero,.L0f1024d0
/*  f1023cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1023d0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1023d4:	000ec840 */ 	sll	$t9,$t6,0x1
/*  f1023d8:	00794021 */ 	addu	$t0,$v1,$t9
/*  f1023dc:	0fc5b9f1 */ 	jal	textGet
/*  f1023e0:	95040000 */ 	lhu	$a0,0x0($t0)
/*  f1023e4:	1000003a */ 	beqz	$zero,.L0f1024d0
/*  f1023e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1023ec:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f1023f0:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f1023f4:	15200003 */ 	bnez	$t1,.L0f102404
/*  f1023f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1023fc:	10000032 */ 	beqz	$zero,.L0f1024c8
/*  f102400:	acc00008 */ 	sw	$zero,0x8($a2)
.L0f102404:
/*  f102404:	10000030 */ 	beqz	$zero,.L0f1024c8
/*  f102408:	acca0008 */ 	sw	$t2,0x8($a2)
/*  f10240c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f102410:	0fc549cb */ 	jal	optionsSetControlMode
/*  f102414:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f102418:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10241c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f102420:	8c4b0458 */ 	lw	$t3,0x458($v0)
/*  f102424:	356c0001 */ 	ori	$t4,$t3,0x1
/*  f102428:	10000027 */ 	beqz	$zero,.L0f1024c8
/*  f10242c:	ac4c0458 */ 	sw	$t4,0x458($v0)
/*  f102430:	00e02025 */ 	or	$a0,$a3,$zero
/*  f102434:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f102438:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f10243c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f102440:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f102444:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f102448:	3c0d8007 */ 	lui	$t5,0x8007
/*  f10244c:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f102450:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f102454:	3c01800a */ 	lui	$at,0x800a
/*  f102458:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f10245c:	030dc023 */ 	subu	$t8,$t8,$t5
/*  f102460:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f102464:	030dc021 */ 	addu	$t8,$t8,$t5
/*  f102468:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10246c:	030dc023 */ 	subu	$t8,$t8,$t5
/*  f102470:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f102474:	00380821 */ 	addu	$at,$at,$t8
/*  f102478:	10000013 */ 	beqz	$zero,.L0f1024c8
/*  f10247c:	ac27ee24 */ 	sw	$a3,-0x11dc($at)
/*  f102480:	3c0f800a */ 	lui	$t7,0x800a
/*  f102484:	8def19c4 */ 	lw	$t7,0x19c4($t7)
/*  f102488:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10248c:	3c198007 */ 	lui	$t9,0x8007
/*  f102490:	55e1000e */ 	bnel	$t7,$at,.L0f1024cc
/*  f102494:	00001025 */ 	or	$v0,$zero,$zero
/*  f102498:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f10249c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f1024a0:	3c01800a */ 	lui	$at,0x800a
/*  f1024a4:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f1024a8:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1024ac:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1024b0:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1024b4:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1024b8:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1024bc:	00084100 */ 	sll	$t0,$t0,0x4
/*  f1024c0:	00280821 */ 	addu	$at,$at,$t0
/*  f1024c4:	ac2eee20 */ 	sw	$t6,-0x11e0($at)
.L0f1024c8:
/*  f1024c8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1024cc:
/*  f1024cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1024d0:
/*  f1024d0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1024d4:	03e00008 */ 	jr	$ra
/*  f1024d8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandler001024dc(u32 operation, struct menu_item *item, s32 *value)
{
	return func0f102330(operation, item, value, 4);
}

s32 menuhandler001024fc(u32 operation, struct menu_item *item, s32 *value)
{
	return func0f102330(operation, item, value, 5);
}

s32 menuhandlerReversePitch(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return !optionsGetForwardPitch(mpchrnum);
	case MENUOP_SET:
		optionsSetForwardPitch(mpchrnum, *enable == false);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandlerAimControl
/*  f1025b4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1025b8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1025bc:	8c4e0298 */ 	lw	$t6,0x298($v0)
/*  f1025c0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1025c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1025c8:	05c10004 */ 	bgez	$t6,.L0f1025dc
/*  f1025cc:	00803825 */ 	or	$a3,$a0,$zero
/*  f1025d0:	8c4f029c */ 	lw	$t7,0x29c($v0)
/*  f1025d4:	05e20005 */ 	bltzl	$t7,.L0f1025ec
/*  f1025d8:	8ca4000c */ 	lw	$a0,0xc($a1)
.L0f1025dc:
/*  f1025dc:	8c580288 */ 	lw	$t8,0x288($v0)
/*  f1025e0:	10000002 */ 	beqz	$zero,.L0f1025ec
/*  f1025e4:	8f040070 */ 	lw	$a0,0x70($t8)
/*  f1025e8:	8ca4000c */ 	lw	$a0,0xc($a1)
.L0f1025ec:
/*  f1025ec:	3c198007 */ 	lui	$t9,%hi(g_AimControlOptions)
/*  f1025f0:	273919e4 */ 	addiu	$t9,$t9,%lo(g_AimControlOptions)
/*  f1025f4:	8f210000 */ 	lw	$at,0x0($t9)
/*  f1025f8:	27a30020 */ 	addiu	$v1,$sp,0x20
/*  f1025fc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f102600:	ac610000 */ 	sw	$at,0x0($v1)
/*  f102604:	24010001 */ 	addiu	$at,$zero,0x1
/*  f102608:	10e10009 */ 	beq	$a3,$at,.L0f102630
/*  f10260c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f102610:	10e10009 */ 	beq	$a3,$at,.L0f102638
/*  f102614:	24010006 */ 	addiu	$at,$zero,0x6
/*  f102618:	10e1000e */ 	beq	$a3,$at,.L0f102654
/*  f10261c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f102620:	10e10014 */ 	beq	$a3,$at,.L0f102674
/*  f102624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f102628:	10000017 */ 	beqz	$zero,.L0f102688
/*  f10262c:	00001025 */ 	or	$v0,$zero,$zero
.L0f102630:
/*  f102630:	10000014 */ 	beqz	$zero,.L0f102684
/*  f102634:	acca0000 */ 	sw	$t2,0x0($a2)
.L0f102638:
/*  f102638:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f10263c:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f102640:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f102644:	0fc5b9f1 */ 	jal	textGet
/*  f102648:	95a40000 */ 	lhu	$a0,0x0($t5)
/*  f10264c:	1000000f */ 	beqz	$zero,.L0f10268c
/*  f102650:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102654:
/*  f102654:	0fc54a94 */ 	jal	optionsSetAimControl
/*  f102658:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f10265c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f102660:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f102664:	8c4e0458 */ 	lw	$t6,0x458($v0)
/*  f102668:	35cf0001 */ 	ori	$t7,$t6,0x1
/*  f10266c:	10000005 */ 	beqz	$zero,.L0f102684
/*  f102670:	ac4f0458 */ 	sw	$t7,0x458($v0)
.L0f102674:
/*  f102674:	0fc549fb */ 	jal	optionsGetAimControl
/*  f102678:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f10267c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f102680:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f102684:
/*  f102684:	00001025 */ 	or	$v0,$zero,$zero
.L0f102688:
/*  f102688:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10268c:
/*  f10268c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f102690:	03e00008 */ 	jr	$ra
/*  f102694:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerSoundMode
/*  f102698:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10269c:	3c0e8007 */ 	lui	$t6,%hi(g_SoundModeOptions)
/*  f1026a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1026a4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f1026a8:	25ce19e8 */ 	addiu	$t6,$t6,%lo(g_SoundModeOptions)
/*  f1026ac:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1026b0:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f1026b4:	24080004 */ 	addiu	$t0,$zero,0x4
/*  f1026b8:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1026bc:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1026c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1026c4:	1081000a */ 	beq	$a0,$at,.L0f1026f0
/*  f1026c8:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1026cc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1026d0:	10810009 */ 	beq	$a0,$at,.L0f1026f8
/*  f1026d4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1026d8:	1081000e */ 	beq	$a0,$at,.L0f102714
/*  f1026dc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1026e0:	10810014 */ 	beq	$a0,$at,.L0f102734
/*  f1026e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1026e8:	10000016 */ 	beqz	$zero,.L0f102744
/*  f1026ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f1026f0:
/*  f1026f0:	10000013 */ 	beqz	$zero,.L0f102740
/*  f1026f4:	acc80000 */ 	sw	$t0,0x0($a2)
.L0f1026f8:
/*  f1026f8:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f1026fc:	00095040 */ 	sll	$t2,$t1,0x1
/*  f102700:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f102704:	0fc5b9f1 */ 	jal	textGet
/*  f102708:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f10270c:	1000000e */ 	beqz	$zero,.L0f102748
/*  f102710:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102714:
/*  f102714:	0c003ce3 */ 	jal	audioSetSoundMode
/*  f102718:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f10271c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f102720:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f102724:	8c4c0458 */ 	lw	$t4,0x458($v0)
/*  f102728:	358d0001 */ 	ori	$t5,$t4,0x1
/*  f10272c:	10000004 */ 	beqz	$zero,.L0f102740
/*  f102730:	ac4d0458 */ 	sw	$t5,0x458($v0)
.L0f102734:
/*  f102734:	3c188006 */ 	lui	$t8,0x8006
/*  f102738:	8f18ddcc */ 	lw	$t8,-0x2234($t8)
/*  f10273c:	acd80000 */ 	sw	$t8,0x0($a2)
.L0f102740:
/*  f102740:	00001025 */ 	or	$v0,$zero,$zero
.L0f102744:
/*  f102744:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102748:
/*  f102748:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10274c:	03e00008 */ 	jr	$ra
/*  f102750:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerScreenSize
/*  f102754:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f102758:	3c0e8007 */ 	lui	$t6,%hi(g_ScreenSizeOptions)
/*  f10275c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f102760:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f102764:	25ce19f0 */ 	addiu	$t6,$t6,%lo(g_ScreenSizeOptions)
/*  f102768:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f10276c:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f102770:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f102774:	ac410000 */ 	sw	$at,0x0($v0)
/*  f102778:	95c10004 */ 	lhu	$at,0x4($t6)
/*  f10277c:	a4410004 */ 	sh	$at,0x4($v0)
/*  f102780:	24010001 */ 	addiu	$at,$zero,0x1
/*  f102784:	10810009 */ 	beq	$a0,$at,.L0f1027ac
/*  f102788:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10278c:	10810009 */ 	beq	$a0,$at,.L0f1027b4
/*  f102790:	24010006 */ 	addiu	$at,$zero,0x6
/*  f102794:	1081000e */ 	beq	$a0,$at,.L0f1027d0
/*  f102798:	24010007 */ 	addiu	$at,$zero,0x7
/*  f10279c:	10810014 */ 	beq	$a0,$at,.L0f1027f0
/*  f1027a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1027a4:	10000017 */ 	beqz	$zero,.L0f102804
/*  f1027a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1027ac:
/*  f1027ac:	10000014 */ 	beqz	$zero,.L0f102800
/*  f1027b0:	acc80000 */ 	sw	$t0,0x0($a2)
.L0f1027b4:
/*  f1027b4:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f1027b8:	00095040 */ 	sll	$t2,$t1,0x1
/*  f1027bc:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f1027c0:	0fc5b9f1 */ 	jal	textGet
/*  f1027c4:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f1027c8:	1000000f */ 	beqz	$zero,.L0f102808
/*  f1027cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1027d0:
/*  f1027d0:	0fc54bc4 */ 	jal	optionsSetScreenSize
/*  f1027d4:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1027d8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1027dc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1027e0:	8c4c0458 */ 	lw	$t4,0x458($v0)
/*  f1027e4:	358d0001 */ 	ori	$t5,$t4,0x1
/*  f1027e8:	10000005 */ 	beqz	$zero,.L0f102800
/*  f1027ec:	ac4d0458 */ 	sw	$t5,0x458($v0)
.L0f1027f0:
/*  f1027f0:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f1027f4:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f1027f8:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f1027fc:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f102800:
/*  f102800:	00001025 */ 	or	$v0,$zero,$zero
.L0f102804:
/*  f102804:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102808:
/*  f102808:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10280c:	03e00008 */ 	jr	$ra
/*  f102810:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerScreenRatio
/*  f102814:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f102818:	3c0e8007 */ 	lui	$t6,%hi(g_ScreenRatioOptions)
/*  f10281c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f102820:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f102824:	25ce19f8 */ 	addiu	$t6,$t6,%lo(g_ScreenRatioOptions)
/*  f102828:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f10282c:	27a2001c */ 	addiu	$v0,$sp,0x1c
/*  f102830:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f102834:	ac410000 */ 	sw	$at,0x0($v0)
/*  f102838:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10283c:	10810009 */ 	beq	$a0,$at,.L0f102864
/*  f102840:	24010003 */ 	addiu	$at,$zero,0x3
/*  f102844:	10810009 */ 	beq	$a0,$at,.L0f10286c
/*  f102848:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10284c:	1081000e */ 	beq	$a0,$at,.L0f102888
/*  f102850:	24010007 */ 	addiu	$at,$zero,0x7
/*  f102854:	10810014 */ 	beq	$a0,$at,.L0f1028a8
/*  f102858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10285c:	10000017 */ 	beqz	$zero,.L0f1028bc
/*  f102860:	00001025 */ 	or	$v0,$zero,$zero
.L0f102864:
/*  f102864:	10000014 */ 	beqz	$zero,.L0f1028b8
/*  f102868:	acc80000 */ 	sw	$t0,0x0($a2)
.L0f10286c:
/*  f10286c:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f102870:	00095040 */ 	sll	$t2,$t1,0x1
/*  f102874:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f102878:	0fc5b9f1 */ 	jal	textGet
/*  f10287c:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f102880:	1000000f */ 	beqz	$zero,.L0f1028c0
/*  f102884:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102888:
/*  f102888:	0fc54bca */ 	jal	optionsSetScreenRatio
/*  f10288c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f102890:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f102894:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f102898:	8c4c0458 */ 	lw	$t4,0x458($v0)
/*  f10289c:	358d0001 */ 	ori	$t5,$t4,0x1
/*  f1028a0:	10000005 */ 	beqz	$zero,.L0f1028b8
/*  f1028a4:	ac4d0458 */ 	sw	$t5,0x458($v0)
.L0f1028a8:
/*  f1028a8:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f1028ac:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f1028b0:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f1028b4:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f1028b8:
/*  f1028b8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1028bc:
/*  f1028bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1028c0:
/*  f1028c0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1028c4:	03e00008 */ 	jr	$ra
/*  f1028c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerScreenSplit
/*  f1028cc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1028d0:	3c0e8007 */ 	lui	$t6,%hi(g_ScreenSplitOptions)
/*  f1028d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1028d8:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f1028dc:	25ce19fc */ 	addiu	$t6,$t6,%lo(g_ScreenSplitOptions)
/*  f1028e0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1028e4:	27a20034 */ 	addiu	$v0,$sp,0x34
/*  f1028e8:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f1028ec:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1028f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1028f4:	10810009 */ 	beq	$a0,$at,.L0f10291c
/*  f1028f8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1028fc:	10810009 */ 	beq	$a0,$at,.L0f102924
/*  f102900:	24010006 */ 	addiu	$at,$zero,0x6
/*  f102904:	1081000e */ 	beq	$a0,$at,.L0f102940
/*  f102908:	24010007 */ 	addiu	$at,$zero,0x7
/*  f10290c:	10810043 */ 	beq	$a0,$at,.L0f102a1c
/*  f102910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f102914:	10000046 */ 	beqz	$zero,.L0f102a30
/*  f102918:	00001025 */ 	or	$v0,$zero,$zero
.L0f10291c:
/*  f10291c:	10000043 */ 	beqz	$zero,.L0f102a2c
/*  f102920:	acc80000 */ 	sw	$t0,0x0($a2)
.L0f102924:
/*  f102924:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f102928:	00095040 */ 	sll	$t2,$t1,0x1
/*  f10292c:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f102930:	0fc5b9f1 */ 	jal	textGet
/*  f102934:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f102938:	1000003e */ 	beqz	$zero,.L0f102a34
/*  f10293c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102940:
/*  f102940:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f102944:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f102948:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f10294c:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f102950:	50430037 */ 	beql	$v0,$v1,.L0f102a30
/*  f102954:	00001025 */ 	or	$v0,$zero,$zero
/*  f102958:	0fc54bd0 */ 	jal	optionsSetScreenSplit
/*  f10295c:	306400ff */ 	andi	$a0,$v1,0xff
/*  f102960:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f102964:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f102968:	8c4c0458 */ 	lw	$t4,0x458($v0)
/*  f10296c:	8c58006c */ 	lw	$t8,0x6c($v0)
/*  f102970:	00002825 */ 	or	$a1,$zero,$zero
/*  f102974:	358d0001 */ 	ori	$t5,$t4,0x1
/*  f102978:	13000003 */ 	beqz	$t8,.L0f102988
/*  f10297c:	ac4d0458 */ 	sw	$t5,0x458($v0)
/*  f102980:	10000001 */ 	beqz	$zero,.L0f102988
/*  f102984:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f102988:
/*  f102988:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f10298c:	00001825 */ 	or	$v1,$zero,$zero
/*  f102990:	00002025 */ 	or	$a0,$zero,$zero
/*  f102994:	11e00003 */ 	beqz	$t7,.L0f1029a4
/*  f102998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10299c:	10000001 */ 	beqz	$zero,.L0f1029a4
/*  f1029a0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1029a4:
/*  f1029a4:	8c4e0064 */ 	lw	$t6,0x64($v0)
/*  f1029a8:	11c00003 */ 	beqz	$t6,.L0f1029b8
/*  f1029ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1029b0:	10000001 */ 	beqz	$zero,.L0f1029b8
/*  f1029b4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1029b8:
/*  f1029b8:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f1029bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1029c0:	13200003 */ 	beqz	$t9,.L0f1029d0
/*  f1029c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1029c8:	10000001 */ 	beqz	$zero,.L0f1029d0
/*  f1029cc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1029d0:
/*  f1029d0:	00444021 */ 	addu	$t0,$v0,$a0
/*  f1029d4:	01034821 */ 	addu	$t1,$t0,$v1
/*  f1029d8:	01255021 */ 	addu	$t2,$t1,$a1
/*  f1029dc:	29410002 */ 	slti	$at,$t2,0x2
/*  f1029e0:	14200012 */ 	bnez	$at,.L0f102a2c
/*  f1029e4:	3c028007 */ 	lui	$v0,%hi(g_MpPlayerNum)
/*  f1029e8:	24421448 */ 	addiu	$v0,$v0,%lo(g_MpPlayerNum)
/*  f1029ec:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f1029f0:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f1029f4:	0fc3e048 */ 	jal	func0f0f8120
/*  f1029f8:	afab0030 */ 	sw	$t3,0x30($sp)
/*  f1029fc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f102a00:	3c018007 */ 	lui	$at,0x8007
/*  f102a04:	0fc3e048 */ 	jal	func0f0f8120
/*  f102a08:	ac2c1448 */ 	sw	$t4,0x1448($at)
/*  f102a0c:	8fad0030 */ 	lw	$t5,0x30($sp)
/*  f102a10:	3c018007 */ 	lui	$at,0x8007
/*  f102a14:	10000005 */ 	beqz	$zero,.L0f102a2c
/*  f102a18:	ac2d1448 */ 	sw	$t5,0x1448($at)
.L0f102a1c:
/*  f102a1c:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f102a20:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f102a24:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f102a28:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f102a2c:
/*  f102a2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f102a30:
/*  f102a30:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f102a34:
/*  f102a34:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f102a38:	03e00008 */ 	jr	$ra
/*  f102a3c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerLookAhead(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetLookAhead(mpchrnum);
	case MENUOP_SET:
		optionsSetLookAhead(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerHeadRoll(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetHeadRoll(mpchrnum);
	case MENUOP_SET:
		optionsSetHeadRoll(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerInGameSubtitles(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_GET:
		return optionsGetInGameSubtitles();
	case MENUOP_SET:
		optionsSetInGameSubtitles(*enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerCutsceneSubtitles(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_GET:
		return optionsGetCutsceneSubtitles();
	case MENUOP_SET:
		optionsSetCutsceneSubtitles(*enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerAlternativeTitle(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.stagenum != STAGE_CITRAINING || var800a2328[3] == 0) {
			return true;
		}
		break;
	case MENUOP_GET:
		return g_AltTitle;
	case MENUOP_SET:
		g_AltTitle = *enable;
		g_Vars.unk000458 |= 4;
	}

	return 0;
}

s32 menuhandlerHiRes(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if (var80090af0 == 1) {
			return true;
		}
		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			if (PLAYERCOUNT() >= 2) {
				return true;
			}
		}
		break;
	case MENUOP_GET:
		return g_HiRes == true;
	case MENUOP_SET:
		optionsSetHiRes(*enable ? 1 : 0);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerAmmoOnScreen(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetAmmoOnScreen(mpchrnum);
	case MENUOP_SET:
		optionsSetAmmoOnScreen(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerShowGunFunction(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_CHECKDISABLED:
		if (optionsGetAmmoOnScreen(mpchrnum) == 0) {
			return true;
		}
		break;
	case MENUOP_GET:
		return optionsGetShowGunFunction(mpchrnum);
	case MENUOP_SET:
		optionsSetShowGunFunction(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerShowMissionTime(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetShowMissionTime(mpchrnum);
	case MENUOP_SET:
		optionsSetShowMissionTime(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerAlwaysShowTarget(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_CHECKDISABLED:
		if (optionsGetSightOnScreen(mpchrnum) == 0) {
			return true;
		}
		break;
	case MENUOP_GET:
		return optionsGetAlwaysShowTarget(mpchrnum);
	case MENUOP_SET:
		optionsSetAlwaysShowTarget(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerShowZoomRange(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_CHECKDISABLED:
		if (optionsGetSightOnScreen(mpchrnum) == 0) {
			return true;
		}
		break;
	case MENUOP_GET:
		return optionsGetShowZoomRange(mpchrnum);
	case MENUOP_SET:
		optionsSetShowZoomRange(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerPaintball(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetPaintball(mpchrnum);
	case MENUOP_SET:
		optionsSetPaintball(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerSightOnScreen(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetSightOnScreen(mpchrnum);
	case MENUOP_SET:
		optionsSetSightOnScreen(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerAutoAim(u32 operation, struct menu_item *item, bool *enable)
{
	u32 mpchrnum;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mpchrnum = g_Vars.unk000288->mpchrnum;
	} else {
		mpchrnum = item->param3;
	}

	switch (operation) {
	case MENUOP_GET:
		return optionsGetAutoAim(mpchrnum);
	case MENUOP_SET:
		optionsSetAutoAim(mpchrnum, *enable);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerMusicVolume(u32 operation, struct menu_item *item, u32 *volume)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		*volume = optionsGetMusicVolume();
		break;
	case MENUOP_SET:
		optionsSetMusicVolume(*volume);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerSfxVolume(u32 operation, struct menu_item *item, u32 *volume)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		if (g_SfxVolume > 0x5000) {
			*volume = 0x5000;
		} else {
			*volume = g_SfxVolume;
		}
		break;
	case MENUOP_SET:
		audioSetSfxVolume(*volume);
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog00103368
/*  f103368:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10336c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f103370:	1481001c */ 	bne	$a0,$at,.L0f1033e4
/*  f103374:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f103378:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10337c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f103380:	3c02800a */ 	lui	$v0,0x800a
/*  f103384:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f103388:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10338c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f103390:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f103394:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f103398:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10339c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f1033a0:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f1033a4:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f1033a8:	5040000f */ 	beqzl	$v0,.L0f1033e8
/*  f1033ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1033b0:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1033b4:	54b8000c */ 	bnel	$a1,$t8,.L0f1033e8
/*  f1033b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1033bc:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1033c0:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f1033c4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1033c8:	8059000a */ 	lb	$t9,0xa($v0)
/*  f1033cc:	53200005 */ 	beqzl	$t9,.L0f1033e4
/*  f1033d0:	a040000a */ 	sb	$zero,0xa($v0)
/*  f1033d4:	0fc40cfe */ 	jal	menuhandlerAcceptMission
/*  f1033d8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1033dc:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f1033e0:	a040000a */ 	sb	$zero,0xa($v0)
.L0f1033e4:
/*  f1033e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1033e8:
/*  f1033e8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1033ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f1033f0:	03e00008 */ 	jr	$ra
/*  f1033f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerAcceptMission
/*  f1033f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1033fc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f103400:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f103404:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f103408:	1481004c */ 	bne	$a0,$at,.END
/*  f10340c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f103410:	0fc06fa8 */ 	jal	func0f01bea0
/*  f103414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103418:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10341c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f103420:	3c04800a */ 	lui	$a0,0x800a
/*  f103424:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f103428:	8c4e04b4 */ 	lw	$t6,0x4b4($v0)
/*  f10342c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f103430:	15c40002 */ 	bne	$t6,$a0,.START
/*  f103434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103438:	ac43046c */ 	sw	$v1,0x46c($v0)
.START:
/*  f10343c:	0fc06c55 */ 	jal	func0f01b154
/*  f103440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103444:	3c06800a */ 	lui	$a2,%hi(g_MissionConfig)
/*  f103448:	24c6dfe8 */ 	addiu	$a2,$a2,%lo(g_MissionConfig)
/*  f10344c:	80d80003 */ 	lb	$t8,0x3($a2)
/*  f103450:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f103454:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f103458:	07010014 */ 	bgez	$t8,.NOTCOOP
/*  f10345c:	24030001 */ 	addiu	$v1,$zero,0x1
.COOP:
/*  f103460:	8c590474 */ 	lw	$t9,0x474($v0)
/*  f103464:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f103468:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10346c:	5720000a */ 	bnezl	$t9,.COOPBUDDIES
/*  f103470:	ac400294 */ 	sw	$zero,0x294($v0)
.COOPNOBUDDIES:
/*  f103474:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f103478:	ac400294 */ 	sw	$zero,0x294($v0)
/*  f10347c:	ac430298 */ 	sw	$v1,0x298($v0)
/*  f103480:	ac45029c */ 	sw	$a1,0x29c($v0)
/*  f103484:	0fc068d5 */ 	jal	setNumPlayers
/*  f103488:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10348c:	1000001f */ 	beqz	$zero,.DONE
/*  f103490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103494:	ac400294 */ 	sw	$zero,0x294($v0)
.COOPBUDDIES:
/*  f103498:	ac450298 */ 	sw	$a1,0x298($v0)
/*  f10349c:	0fc068d5 */ 	jal	setNumPlayers
/*  f1034a0:	ac45029c */ 	sw	$a1,0x29c($v0)
/*  f1034a4:	10000019 */ 	beqz	$zero,.DONE
/*  f1034a8:	00000000 */ 	sll	$zero,$zero,0x0
.NOTCOOP:
/*  f1034ac:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f1034b0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1034b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1034b8:	00085640 */ 	sll	$t2,$t0,0x19
/*  f1034bc:	05430010 */ 	bgezl	$t2,.SOLO
/*  f1034c0:	ac400294 */ 	sw	$zero,0x294($v0)
.ANTI:
/*  f1034c4:	8c4b0450 */ 	lw	$t3,0x450($v0)
/*  f1034c8:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1034cc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1034d0:	546b0005 */ 	bnel	$v1,$t3,.ANTIP0
/*  f1034d4:	ac430294 */ 	sw	$v1,0x294($v0)
.ANTIP1:
/*  f1034d8:	ac400294 */ 	sw	$zero,0x294($v0)
/*  f1034dc:	10000003 */ 	beqz	$zero,.ANTIEND
/*  f1034e0:	ac43029c */ 	sw	$v1,0x29c($v0)
/*  f1034e4:	ac430294 */ 	sw	$v1,0x294($v0)
.ANTIP0:
/*  f1034e8:	ac40029c */ 	sw	$zero,0x29c($v0)
.ANTIEND:
/*  f1034ec:	0fc068d5 */ 	jal	setNumPlayers
/*  f1034f0:	ac450298 */ 	sw	$a1,0x298($v0)
/*  f1034f4:	10000005 */ 	beqz	$zero,.DONE
/*  f1034f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1034fc:	ac400294 */ 	sw	$zero,0x294($v0)
.SOLO:
/*  f103500:	ac450298 */ 	sw	$a1,0x298($v0)
/*  f103504:	0fc068d5 */ 	jal	setNumPlayers
/*  f103508:	ac45029c */ 	sw	$a1,0x29c($v0)
.DONE:
/*  f10350c:	3c04800a */ 	lui	$a0,0x800a
/*  f103510:	8c84dfe8 */ 	lw	$a0,-0x2018($a0)
/*  f103514:	00046642 */ 	srl	$t4,$a0,0x19
/*  f103518:	0fc5b36a */ 	jal	setDifficulty
/*  f10351c:	01802025 */ 	or	$a0,$t4,$zero
/*  f103520:	0fc069f9 */ 	jal	func0f01a7e4
/*  f103524:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f103528:	3c04800a */ 	lui	$a0,0x800a
/*  f10352c:	0c003a57 */ 	jal	func0000e95c
/*  f103530:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f103534:	0c0027b1 */ 	jal	func00009ec4
/*  f103538:	24040001 */ 	addiu	$a0,$zero,0x1
.END:
/*  f10353c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f103540:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f103544:	00001025 */ 	or	$v0,$zero,$zero
/*  f103548:	03e00008 */ 	jr	$ra
/*  f10354c:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatching branch/branch-likelys
//s32 menuhandlerAcceptMission(u32 operation, struct menu_item *item, s32 *value)
//{
//	if (operation == MENUOP_SET) {
//		func0f01bea0();
//
//		if (g_Vars.stagenum == g_MissionConfig.stagenum) {
//			g_Vars.restartlevel = true;
//		}
//
//		func0f01b154(g_MissionConfig.stagenum);
//
//		if (g_MissionConfig.iscoop) {
//			if (g_Vars.numaibuddies == 0) {
//				// Coop with human buddy
//				g_Vars.bondplayernum = 0;
//				g_Vars.coopplayernum = 1;
//				g_Vars.antiplayernum = -1;
//				setNumPlayers(2);
//			} else {
//				// Coop with AI buddies
//				g_Vars.bondplayernum = 0;
//				g_Vars.coopplayernum = -1;
//				g_Vars.antiplayernum = -1;
//				setNumPlayers(1);
//			}
//		} else if (g_MissionConfig.isanti) {
//			if (g_Vars.pendingantiplayernum == 1) {
//				g_Vars.bondplayernum = 0;
//				g_Vars.antiplayernum = 1;
//			} else {
//				g_Vars.bondplayernum = 1;
//				g_Vars.antiplayernum = 0;
//			}
//
//			g_Vars.coopplayernum = -1;
//			setNumPlayers(2);
//		} else {
//			// Solo
//			g_Vars.bondplayernum = 0;
//			g_Vars.coopplayernum = -1;
//			g_Vars.antiplayernum = -1;
//			setNumPlayers(1);
//		}
//
//		setDifficulty(g_MissionConfig.difficulty);
//		func0f01a7e4(5);
//		func0000e95c(g_MissionConfig.stagenum);
//		func00009ec4(1);
//	}
//
//	return 0;
//}

GLOBAL_ASM(
glabel func0f103550
/*  f103550:	3c0e8007 */ 	lui	$t6,0x8007
/*  f103554:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f103558:	3c18800a */ 	lui	$t8,0x800a
/*  f10355c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f103560:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f103564:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f103568:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10356c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f103570:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f103574:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f103578:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10357c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f103580:	8f18e4f8 */ 	lw	$t8,-0x1b08($t8)
/*  f103584:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f103588:	3c08800a */ 	lui	$t0,0x800a
/*  f10358c:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f103590:	10990005 */ 	beq	$a0,$t9,.L0f1035a8
/*  f103594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103598:	0fc5b9f1 */ 	jal	textGet
/*  f10359c:	24045711 */ 	addiu	$a0,$zero,0x5711
/*  f1035a0:	10000016 */ 	beqz	$zero,.L0f1035fc
/*  f1035a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1035a8:
/*  f1035a8:	9108dfea */ 	lbu	$t0,-0x2016($t0)
/*  f1035ac:	3c048007 */ 	lui	$a0,0x8007
/*  f1035b0:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1035b4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1035b8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1035bc:	00892021 */ 	addu	$a0,$a0,$t1
/*  f1035c0:	0fc5b9f1 */ 	jal	textGet
/*  f1035c4:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f1035c8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f1035cc:	0fc5b9f1 */ 	jal	textGet
/*  f1035d0:	24045711 */ 	addiu	$a0,$zero,0x5711
/*  f1035d4:	3c048007 */ 	lui	$a0,0x8007
/*  f1035d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b2cf4)
/*  f1035dc:	24a52cf4 */ 	addiu	$a1,$a1,%lo(var7f1b2cf4)
/*  f1035e0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1035e4:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f1035e8:	0c004dad */ 	jal	sprintf
/*  f1035ec:	00403825 */ 	or	$a3,$v0,$zero
/*  f1035f0:	3c028007 */ 	lui	$v0,0x8007
/*  f1035f4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1035f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1035fc:
/*  f1035fc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f103600:	03e00008 */ 	jr	$ra
/*  f103604:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog00103608
/*  f103608:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10360c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f103610:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f103614:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f103618:	10810006 */ 	beq	$a0,$at,.L0f103634
/*  f10361c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f103620:	24010065 */ 	addiu	$at,$zero,0x65
/*  f103624:	10810019 */ 	beq	$a0,$at,.L0f10368c
/*  f103628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10362c:	1000001b */ 	beqz	$zero,.L0f10369c
/*  f103630:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f103634:
/*  f103634:	3c0e8007 */ 	lui	$t6,0x8007
/*  f103638:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10363c:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f103640:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f103644:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f103648:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10364c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f103650:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f103654:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f103658:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10365c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f103660:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f103664:	ac400850 */ 	sw	$zero,0x850($v0)
/*  f103668:	3c04800a */ 	lui	$a0,0x800a
/*  f10366c:	3c07800a */ 	lui	$a3,%hi(var8009dfc8)
/*  f103670:	24e7dfc8 */ 	addiu	$a3,$a3,%lo(var8009dfc8)
/*  f103674:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f103678:	8c450844 */ 	lw	$a1,0x844($v0)
/*  f10367c:	0fc03a60 */ 	jal	func0f00e980
/*  f103680:	8c460848 */ 	lw	$a2,0x848($v0)
/*  f103684:	10000005 */ 	beqz	$zero,.L0f10369c
/*  f103688:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10368c:
/*  f10368c:	3c04800a */ 	lui	$a0,0x800a
/*  f103690:	0fc5b9ec */ 	jal	textClearBank
/*  f103694:	9484dfe2 */ 	lhu	$a0,-0x201e($a0)
/*  f103698:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10369c:
/*  f10369c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1036a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1036a4:	03e00008 */ 	jr	$ra
/*  f1036a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1036ac
/*  f1036ac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1036b0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1036b4:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f1036b8:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1036bc:	14a0000c */ 	bnez	$a1,.L0f1036f0
/*  f1036c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1036c4:	44842000 */ 	mtc1	$a0,$f4
/*  f1036c8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1036cc:	05c10004 */ 	bgez	$t6,.L0f1036e0
/*  f1036d0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1036d4:	44814000 */ 	mtc1	$at,$f8
/*  f1036d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1036dc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1036e0:
/*  f1036e0:	3c01437f */ 	lui	$at,0x437f
/*  f1036e4:	44815000 */ 	mtc1	$at,$f10
/*  f1036e8:	10000003 */ 	beqz	$zero,.L0f1036f8
/*  f1036ec:	460a3003 */ 	div.s	$f0,$f6,$f10
.L0f1036f0:
/*  f1036f0:	0fc61ddc */ 	jal	func0f187770
/*  f1036f4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1036f8:
/*  f1036f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1036fc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f103700:	03e00008 */ 	jr	$ra
/*  f103704:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerPdModeSetting
/*  f103708:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10370c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f103710:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f103714:	90a70001 */ 	lbu	$a3,0x1($a1)
/*  f103718:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10371c:	10e00009 */ 	beqz	$a3,.L0f103744
/*  f103720:	00e01025 */ 	or	$v0,$a3,$zero
/*  f103724:	1041000a */ 	beq	$v0,$at,.L0f103750
/*  f103728:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10372c:	1041000b */ 	beq	$v0,$at,.L0f10375c
/*  f103730:	24010003 */ 	addiu	$at,$zero,0x3
/*  f103734:	1041000c */ 	beq	$v0,$at,.L0f103768
/*  f103738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10373c:	1000003b */ 	beqz	$zero,.L0f10382c
/*  f103740:	00001025 */ 	or	$v0,$zero,$zero
.L0f103744:
/*  f103744:	3c02800a */ 	lui	$v0,0x800a
/*  f103748:	1000000c */ 	beqz	$zero,.L0f10377c
/*  f10374c:	2442dfec */ 	addiu	$v0,$v0,0xdfec
.L0f103750:
/*  f103750:	3c02800a */ 	lui	$v0,0x800a
/*  f103754:	10000009 */ 	beqz	$zero,.L0f10377c
/*  f103758:	2442dfed */ 	addiu	$v0,$v0,-8211
.L0f10375c:
/*  f10375c:	3c02800a */ 	lui	$v0,0x800a
/*  f103760:	10000006 */ 	beqz	$zero,.L0f10377c
/*  f103764:	2442dfee */ 	addiu	$v0,$v0,-8210
.L0f103768:
/*  f103768:	3c02800a */ 	lui	$v0,0x800a
/*  f10376c:	10000003 */ 	beqz	$zero,.L0f10377c
/*  f103770:	2442dfef */ 	addiu	$v0,$v0,-8209
/*  f103774:	1000002d */ 	beqz	$zero,.L0f10382c
/*  f103778:	00001025 */ 	or	$v0,$zero,$zero
.L0f10377c:
/*  f10377c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f103780:	1081000a */ 	beq	$a0,$at,.L0f1037ac
/*  f103784:	24010009 */ 	addiu	$at,$zero,0x9
/*  f103788:	10810005 */ 	beq	$a0,$at,.L0f1037a0
/*  f10378c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f103790:	10810009 */ 	beq	$a0,$at,.L0f1037b8
/*  f103794:	00e02825 */ 	or	$a1,$a3,$zero
/*  f103798:	10000024 */ 	beqz	$zero,.L0f10382c
/*  f10379c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1037a0:
/*  f1037a0:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f1037a4:	10000020 */ 	beqz	$zero,.L0f103828
/*  f1037a8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f1037ac:
/*  f1037ac:	94d80002 */ 	lhu	$t8,0x2($a2)
/*  f1037b0:	1000001d */ 	beqz	$zero,.L0f103828
/*  f1037b4:	a0580000 */ 	sb	$t8,0x0($v0)
.L0f1037b8:
/*  f1037b8:	90440000 */ 	lbu	$a0,0x0($v0)
/*  f1037bc:	0fc40dab */ 	jal	func0f1036ac
/*  f1037c0:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f1037c4:	8fb90024 */ 	lw	$t9,0x24($sp)
/*  f1037c8:	46000086 */ 	mov.s	$f2,$f0
/*  f1037cc:	3c014080 */ 	lui	$at,0x4080
/*  f1037d0:	93280001 */ 	lbu	$t0,0x1($t9)
/*  f1037d4:	55000007 */ 	bnezl	$t0,.L0f1037f4
/*  f1037d8:	3c0142c8 */ 	lui	$at,0x42c8
/*  f1037dc:	44812000 */ 	mtc1	$at,$f4
/*  f1037e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1037e4:	44814000 */ 	mtc1	$at,$f8
/*  f1037e8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f1037ec:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f1037f0:	3c0142c8 */ 	lui	$at,0x42c8
.L0f1037f4:
/*  f1037f4:	44815000 */ 	mtc1	$at,$f10
/*  f1037f8:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f1037fc:	3c057f1b */ 	lui	$a1,%hi(var7f1b2cfc)
/*  f103800:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f103804:	3c067f1b */ 	lui	$a2,%hi(var7f1b2d0c)
/*  f103808:	3c077f1b */ 	lui	$a3,%hi(var7f1b2d10)
/*  f10380c:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f103810:	24e72d10 */ 	addiu	$a3,$a3,%lo(var7f1b2d10)
/*  f103814:	24c62d0c */ 	addiu	$a2,$a2,%lo(var7f1b2d0c)
/*  f103818:	24a52cfc */ 	addiu	$a1,$a1,%lo(var7f1b2cfc)
/*  f10381c:	460084a1 */ 	cvt.d.s	$f18,$f16
/*  f103820:	0c004dad */ 	jal	sprintf
/*  f103824:	f7b20010 */ 	sdc1	$f18,0x10($sp)
.L0f103828:
/*  f103828:	00001025 */ 	or	$v0,$zero,$zero
.L0f10382c:
/*  f10382c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f103830:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f103834:	03e00008 */ 	jr	$ra
/*  f103838:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerAcceptPdModeSettings(s32 operation, struct menu_item *item, bool *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.pdmode = true;
		g_MissionConfig.fpdmodehealth = func0f1036ac(g_MissionConfig.updmodehealth, 1);
		g_MissionConfig.fpdmodedamage = func0f1036ac(g_MissionConfig.updmodedamage, 2);
		g_MissionConfig.fpdmodeaccuracy = func0f1036ac(g_MissionConfig.updmodeaccuracy, 3);
		g_MissionConfig.difficulty = DIFF_PA;
		setDifficulty(g_MissionConfig.difficulty);
		menuPopDialog();
		menuPopDialog();
		menuPushDialog(&g_ObjectivesMenuDialog);
	}

	return 0;
}

GLOBAL_ASM(
glabel isStageDifficultyUnlocked
/*  f1038ec:	28810011 */ 	slti	$at,$a0,0x11
/*  f1038f0:	14200024 */ 	bnez	$at,.L0f103984
/*  f1038f4:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1038f8:	3c05800a */ 	lui	$a1,0x800a
/*  f1038fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f103900:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f103904:	00001825 */ 	or	$v1,$zero,$zero
.L0f103908:
/*  f103908:	94ae0080 */ 	lhu	$t6,0x80($a1)
/*  f10390c:	51c00003 */ 	beqzl	$t6,.L0f10391c
/*  f103910:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103914:	00601025 */ 	or	$v0,$v1,$zero
/*  f103918:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f10391c:
/*  f10391c:	28610003 */ 	slti	$at,$v1,0x3
/*  f103920:	1420fff9 */ 	bnez	$at,.L0f103908
/*  f103924:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f103928:	0046082a */ 	slt	$at,$v0,$a2
/*  f10392c:	14200003 */ 	bnez	$at,.L0f10393c
/*  f103930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103934:	03e00008 */ 	jr	$ra
/*  f103938:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10393c:
/*  f10393c:	18c0000f */ 	blez	$a2,.L0f10397c
/*  f103940:	00001825 */ 	or	$v1,$zero,$zero
/*  f103944:	00047880 */ 	sll	$t7,$a0,0x2
/*  f103948:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f10394c:	3c18800a */ 	lui	$t8,0x800a
/*  f103950:	27182200 */ 	addiu	$t8,$t8,0x2200
/*  f103954:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f103958:	01f81021 */ 	addu	$v0,$t7,$t8
.L0f10395c:
/*  f10395c:	94590020 */ 	lhu	$t9,0x20($v0)
/*  f103960:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103964:	17200003 */ 	bnez	$t9,.L0f103974
/*  f103968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10396c:	03e00008 */ 	jr	$ra
/*  f103970:	00001025 */ 	or	$v0,$zero,$zero
.L0f103974:
/*  f103974:	1466fff9 */ 	bne	$v1,$a2,.L0f10395c
/*  f103978:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f10397c:
/*  f10397c:	03e00008 */ 	jr	$ra
/*  f103980:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f103984:
/*  f103984:	28810011 */ 	slti	$at,$a0,0x11
/*  f103988:	102000d6 */ 	beqz	$at,.L0f103ce4
/*  f10398c:	28c10003 */ 	slti	$at,$a2,0x3
/*  f103990:	102000d4 */ 	beqz	$at,.L0f103ce4
/*  f103994:	00046080 */ 	sll	$t4,$a0,0x2
/*  f103998:	01846023 */ 	subu	$t4,$t4,$a0
/*  f10399c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1039a0:	3c058007 */ 	lui	$a1,0x8007
/*  f1039a4:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f1039a8:	8ca51e6c */ 	lw	$a1,0x1e6c($a1)
/*  f1039ac:	24010030 */ 	addiu	$at,$zero,0x30
/*  f1039b0:	54a10004 */ 	bnel	$a1,$at,.L0f1039c4
/*  f1039b4:	28c10003 */ 	slti	$at,$a2,0x3
/*  f1039b8:	03e00008 */ 	jr	$ra
/*  f1039bc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1039c0:	28c10003 */ 	slti	$at,$a2,0x3
.L0f1039c4:
/*  f1039c4:	10200026 */ 	beqz	$at,.L0f103a60
/*  f1039c8:	00c01825 */ 	or	$v1,$a2,$zero
/*  f1039cc:	00046880 */ 	sll	$t5,$a0,0x2
/*  f1039d0:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f1039d4:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f1039d8:	00037040 */ 	sll	$t6,$v1,0x1
/*  f1039dc:	3c18800a */ 	lui	$t8,0x800a
/*  f1039e0:	27182200 */ 	addiu	$t8,$t8,0x2200
/*  f1039e4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1039e8:	3c0a800a */ 	lui	$t2,0x800a
/*  f1039ec:	3c09800a */ 	lui	$t1,%hi(g_MissionConfig)
/*  f1039f0:	2529dfe8 */ 	addiu	$t1,$t1,%lo(g_MissionConfig)
/*  f1039f4:	254a2200 */ 	addiu	$t2,$t2,0x2200
/*  f1039f8:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f1039fc:	240b0003 */ 	addiu	$t3,$zero,0x3
.L0f103a00:
/*  f103a00:	94590020 */ 	lhu	$t9,0x20($v0)
/*  f103a04:	53200004 */ 	beqzl	$t9,.L0f103a18
/*  f103a08:	812d0003 */ 	lb	$t5,0x3($t1)
/*  f103a0c:	03e00008 */ 	jr	$ra
/*  f103a10:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f103a14:	812d0003 */ 	lb	$t5,0x3($t1)
.L0f103a18:
/*  f103a18:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f103a1c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103a20:	05a00005 */ 	bltz	$t5,.L0f103a38
/*  f103a24:	01596021 */ 	addu	$t4,$t2,$t9
/*  f103a28:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f103a2c:	000ec640 */ 	sll	$t8,$t6,0x19
/*  f103a30:	07010009 */ 	bgez	$t8,.L0f103a58
/*  f103a34:	00000000 */ 	sll	$zero,$zero,0x0
.L0f103a38:
/*  f103a38:	8d8d00a0 */ 	lw	$t5,0xa0($t4)
/*  f103a3c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f103a40:	008e7804 */ 	sllv	$t7,$t6,$a0
/*  f103a44:	01afc024 */ 	and	$t8,$t5,$t7
/*  f103a48:	13000003 */ 	beqz	$t8,.L0f103a58
/*  f103a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103a50:	03e00008 */ 	jr	$ra
/*  f103a54:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f103a58:
/*  f103a58:	146bffe9 */ 	bne	$v1,$t3,.L0f103a00
/*  f103a5c:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f103a60:
/*  f103a60:	3c09800a */ 	lui	$t1,%hi(g_MissionConfig)
/*  f103a64:	3c0a800a */ 	lui	$t2,0x800a
/*  f103a68:	254a2200 */ 	addiu	$t2,$t2,0x2200
/*  f103a6c:	2529dfe8 */ 	addiu	$t1,$t1,%lo(g_MissionConfig)
/*  f103a70:	18800052 */ 	blez	$a0,.L0f103bbc
/*  f103a74:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f103a78:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f103a7c:	10a10024 */ 	beq	$a1,$at,.L0f103b10
/*  f103a80:	28c10003 */ 	slti	$at,$a2,0x3
/*  f103a84:	1020004d */ 	beqz	$at,.L0f103bbc
/*  f103a88:	00c01825 */ 	or	$v1,$a2,$zero
/*  f103a8c:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f103a90:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f103a94:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f103a98:	01596021 */ 	addu	$t4,$t2,$t9
/*  f103a9c:	00037040 */ 	sll	$t6,$v1,0x1
/*  f103aa0:	018e1021 */ 	addu	$v0,$t4,$t6
.L0f103aa4:
/*  f103aa4:	944d001a */ 	lhu	$t5,0x1a($v0)
/*  f103aa8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f103aac:	51a00004 */ 	beqzl	$t5,.L0f103ac0
/*  f103ab0:	81380003 */ 	lb	$t8,0x3($t1)
/*  f103ab4:	03e00008 */ 	jr	$ra
/*  f103ab8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f103abc:	81380003 */ 	lb	$t8,0x3($t1)
.L0f103ac0:
/*  f103ac0:	00036880 */ 	sll	$t5,$v1,0x2
/*  f103ac4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103ac8:	07000005 */ 	bltz	$t8,.L0f103ae0
/*  f103acc:	014d7821 */ 	addu	$t7,$t2,$t5
/*  f103ad0:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f103ad4:	00197640 */ 	sll	$t6,$t9,0x19
/*  f103ad8:	05c10009 */ 	bgez	$t6,.L0f103b00
/*  f103adc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f103ae0:
/*  f103ae0:	8df800a0 */ 	lw	$t8,0xa0($t7)
/*  f103ae4:	2499001f */ 	addiu	$t9,$a0,0x1f
/*  f103ae8:	032c7004 */ 	sllv	$t6,$t4,$t9
/*  f103aec:	030e6824 */ 	and	$t5,$t8,$t6
/*  f103af0:	11a00003 */ 	beqz	$t5,.L0f103b00
/*  f103af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103af8:	03e00008 */ 	jr	$ra
/*  f103afc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f103b00:
/*  f103b00:	146bffe8 */ 	bne	$v1,$t3,.L0f103aa4
/*  f103b04:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f103b08:	1000002c */ 	beqz	$zero,.L0f103bbc
/*  f103b0c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f103b10:
/*  f103b10:	18800025 */ 	blez	$a0,.L0f103ba8
/*  f103b14:	00003825 */ 	or	$a3,$zero,$zero
/*  f103b18:	28c10003 */ 	slti	$at,$a2,0x3
.L0f103b1c:
/*  f103b1c:	1020001c */ 	beqz	$at,.L0f103b90
/*  f103b20:	00c01825 */ 	or	$v1,$a2,$zero
/*  f103b24:	00077880 */ 	sll	$t7,$a3,0x2
/*  f103b28:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f103b2c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f103b30:	014f6021 */ 	addu	$t4,$t2,$t7
/*  f103b34:	0003c840 */ 	sll	$t9,$v1,0x1
/*  f103b38:	01994021 */ 	addu	$t0,$t4,$t9
.L0f103b3c:
/*  f103b3c:	95180020 */ 	lhu	$t8,0x20($t0)
/*  f103b40:	57000014 */ 	bnezl	$t8,.L0f103b94
/*  f103b44:	28610003 */ 	slti	$at,$v1,0x3
/*  f103b48:	812d0003 */ 	lb	$t5,0x3($t1)
/*  f103b4c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f103b50:	01587021 */ 	addu	$t6,$t2,$t8
/*  f103b54:	05a20006 */ 	bltzl	$t5,.L0f103b70
/*  f103b58:	8dcd00a0 */ 	lw	$t5,0xa0($t6)
/*  f103b5c:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f103b60:	000fce40 */ 	sll	$t9,$t7,0x19
/*  f103b64:	07230008 */ 	bgezl	$t9,.L0f103b88
/*  f103b68:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103b6c:	8dcd00a0 */ 	lw	$t5,0xa0($t6)
.L0f103b70:
/*  f103b70:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f103b74:	00ef6004 */ 	sllv	$t4,$t7,$a3
/*  f103b78:	01acc824 */ 	and	$t9,$t5,$t4
/*  f103b7c:	57200005 */ 	bnezl	$t9,.L0f103b94
/*  f103b80:	28610003 */ 	slti	$at,$v1,0x3
/*  f103b84:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f103b88:
/*  f103b88:	146bffec */ 	bne	$v1,$t3,.L0f103b3c
/*  f103b8c:	25080002 */ 	addiu	$t0,$t0,0x2
.L0f103b90:
/*  f103b90:	28610003 */ 	slti	$at,$v1,0x3
.L0f103b94:
/*  f103b94:	50200005 */ 	beqzl	$at,.L0f103bac
/*  f103b98:	00e4082a */ 	slt	$at,$a3,$a0
/*  f103b9c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f103ba0:	54e4ffde */ 	bnel	$a3,$a0,.L0f103b1c
/*  f103ba4:	28c10003 */ 	slti	$at,$a2,0x3
.L0f103ba8:
/*  f103ba8:	00e4082a */ 	slt	$at,$a3,$a0
.L0f103bac:
/*  f103bac:	14200003 */ 	bnez	$at,.L0f103bbc
/*  f103bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103bb4:	03e00008 */ 	jr	$ra
/*  f103bb8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f103bbc:
/*  f103bbc:	18c00049 */ 	blez	$a2,.L0f103ce4
/*  f103bc0:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f103bc4:	10a10047 */ 	beq	$a1,$at,.L0f103ce4
/*  f103bc8:	00003825 */ 	or	$a3,$zero,$zero
/*  f103bcc:	3c05800a */ 	lui	$a1,0x800a
/*  f103bd0:	24a52200 */ 	addiu	$a1,$a1,0x2200
.L0f103bd4:
/*  f103bd4:	00001825 */ 	or	$v1,$zero,$zero
/*  f103bd8:	00001025 */ 	or	$v0,$zero,$zero
/*  f103bdc:	00a04025 */ 	or	$t0,$a1,$zero
.L0f103be0:
/*  f103be0:	95180020 */ 	lhu	$t8,0x20($t0)
/*  f103be4:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f103be8:	57000013 */ 	bnezl	$t8,.L0f103c38
/*  f103bec:	28410006 */ 	slti	$at,$v0,0x6
/*  f103bf0:	812f0003 */ 	lb	$t7,0x3($t1)
/*  f103bf4:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f103bf8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103bfc:	05e00005 */ 	bltz	$t7,.L0f103c14
/*  f103c00:	01587021 */ 	addu	$t6,$t2,$t8
/*  f103c04:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f103c08:	000dce40 */ 	sll	$t9,$t5,0x19
/*  f103c0c:	07230007 */ 	bgezl	$t9,.L0f103c2c
/*  f103c10:	28610003 */ 	slti	$at,$v1,0x3
.L0f103c14:
/*  f103c14:	8dcf00a0 */ 	lw	$t7,0xa0($t6)
/*  f103c18:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f103c1c:	00ed6004 */ 	sllv	$t4,$t5,$a3
/*  f103c20:	01ecc824 */ 	and	$t9,$t7,$t4
/*  f103c24:	17200003 */ 	bnez	$t9,.L0f103c34
/*  f103c28:	28610003 */ 	slti	$at,$v1,0x3
.L0f103c2c:
/*  f103c2c:	1420ffec */ 	bnez	$at,.L0f103be0
/*  f103c30:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f103c34:
/*  f103c34:	28410006 */ 	slti	$at,$v0,0x6
.L0f103c38:
/*  f103c38:	10200004 */ 	beqz	$at,.L0f103c4c
/*  f103c3c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f103c40:	28e10011 */ 	slti	$at,$a3,0x11
/*  f103c44:	1420ffe3 */ 	bnez	$at,.L0f103bd4
/*  f103c48:	24a50006 */ 	addiu	$a1,$a1,0x6
.L0f103c4c:
/*  f103c4c:	3c18800a */ 	lui	$t8,0x800a
/*  f103c50:	27182266 */ 	addiu	$t8,$t8,0x2266
/*  f103c54:	00b8082b */ 	sltu	$at,$a1,$t8
/*  f103c58:	14200022 */ 	bnez	$at,.L0f103ce4
/*  f103c5c:	24c2ffff */ 	addiu	$v0,$a2,-1
/*  f103c60:	28410003 */ 	slti	$at,$v0,0x3
/*  f103c64:	1020001f */ 	beqz	$at,.L0f103ce4
/*  f103c68:	00401825 */ 	or	$v1,$v0,$zero
/*  f103c6c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f103c70:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f103c74:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f103c78:	014e6821 */ 	addu	$t5,$t2,$t6
/*  f103c7c:	00027840 */ 	sll	$t7,$v0,0x1
/*  f103c80:	01af1021 */ 	addu	$v0,$t5,$t7
.L0f103c84:
/*  f103c84:	944c0020 */ 	lhu	$t4,0x20($v0)
/*  f103c88:	51800004 */ 	beqzl	$t4,.L0f103c9c
/*  f103c8c:	81380003 */ 	lb	$t8,0x3($t1)
/*  f103c90:	03e00008 */ 	jr	$ra
/*  f103c94:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f103c98:	81380003 */ 	lb	$t8,0x3($t1)
.L0f103c9c:
/*  f103c9c:	00036080 */ 	sll	$t4,$v1,0x2
/*  f103ca0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f103ca4:	07000005 */ 	bltz	$t8,.L0f103cbc
/*  f103ca8:	014cc821 */ 	addu	$t9,$t2,$t4
/*  f103cac:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f103cb0:	000e7e40 */ 	sll	$t7,$t6,0x19
/*  f103cb4:	05e10009 */ 	bgez	$t7,.L0f103cdc
/*  f103cb8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f103cbc:
/*  f103cbc:	8f3800a0 */ 	lw	$t8,0xa0($t9)
/*  f103cc0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f103cc4:	008e6804 */ 	sllv	$t5,$t6,$a0
/*  f103cc8:	030d7824 */ 	and	$t7,$t8,$t5
/*  f103ccc:	11e00003 */ 	beqz	$t7,.L0f103cdc
/*  f103cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103cd4:	03e00008 */ 	jr	$ra
/*  f103cd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f103cdc:
/*  f103cdc:	146bffe9 */ 	bne	$v1,$t3,.L0f103c84
/*  f103ce0:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f103ce4:
/*  f103ce4:	00001025 */ 	or	$v0,$zero,$zero
/*  f103ce8:	03e00008 */ 	jr	$ra
/*  f103cec:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerSoloDifficulty(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_CHECKPREFOCUSED:
		if (isStageDifficultyUnlocked(g_MissionConfig.stageindex, item->param)) {
			if (item->param3 == 0) {
				return true;
			}
			if ((g_SoloSaveFile.unk08 & 7) >= item->param) {
				return true;
			}
		}
		break;
	case MENUOP_SET:
		g_MissionConfig.pdmode = false;
		g_MissionConfig.difficulty = item->param;
		setDifficulty(g_MissionConfig.difficulty);
		menuPopDialog();
		menuPushDialog(&g_ObjectivesMenuDialog);
		break;
	case MENUOP_CHECKDISABLED:
		if (!isStageDifficultyUnlocked(g_MissionConfig.stageindex, item->param)) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerPdMode(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_SET:
		menuPushDialog(&g_PdModeSettingsDialog);
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_SoloSaveFile.besttimes[SOLOSTAGEINDEX_SKEDARRUINS][DIFF_PA] == 0) {
			return true;
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f103e68
/*  f103e68:	3c0e800a */ 	lui	$t6,0x800a
/*  f103e6c:	91cedfea */ 	lbu	$t6,-0x2016($t6)
/*  f103e70:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f103e74:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f103e78:	90980001 */ 	lbu	$t8,0x1($a0)
/*  f103e7c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f103e80:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f103e84:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f103e88:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f103e8c:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f103e90:	3c03800a */ 	lui	$v1,0x800a
/*  f103e94:	00681821 */ 	addu	$v1,$v1,$t0
/*  f103e98:	94622220 */ 	lhu	$v0,0x2220($v1)
/*  f103e9c:	14400004 */ 	bnez	$v0,.L0f103eb0
/*  f103ea0:	28410fff */ 	slti	$at,$v0,0xfff
/*  f103ea4:	3c027f1b */ 	lui	$v0,%hi(var7f1b2d14)
/*  f103ea8:	1000005f */ 	beqz	$zero,.L0f104028
/*  f103eac:	24422d14 */ 	addiu	$v0,$v0,%lo(var7f1b2d14)
.L0f103eb0:
/*  f103eb0:	54200005 */ 	bnezl	$at,.L0f103ec8
/*  f103eb4:	24010e10 */ 	addiu	$at,$zero,0xe10
/*  f103eb8:	3c027f1b */ 	lui	$v0,%hi(var7f1b2d1c)
/*  f103ebc:	1000005a */ 	beqz	$zero,.L0f104028
/*  f103ec0:	24422d1c */ 	addiu	$v0,$v0,%lo(var7f1b2d1c)
/*  f103ec4:	24010e10 */ 	addiu	$at,$zero,0xe10
.L0f103ec8:
/*  f103ec8:	0041001a */ 	div	$zero,$v0,$at
/*  f103ecc:	00003012 */ 	mflo	$a2
/*  f103ed0:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f103ed4:	14c0002b */ 	bnez	$a2,.L0f103f84
/*  f103ed8:	3c048007 */ 	lui	$a0,0x8007
/*  f103edc:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f103ee0:	0043001a */ 	div	$zero,$v0,$v1
/*  f103ee4:	00004812 */ 	mflo	$t1
/*  f103ee8:	3c048007 */ 	lui	$a0,0x8007
/*  f103eec:	3c057f1b */ 	lui	$a1,%hi(var7f1b2d24)
/*  f103ef0:	0123001a */ 	div	$zero,$t1,$v1
/*  f103ef4:	00003010 */ 	mfhi	$a2
/*  f103ef8:	24a52d24 */ 	addiu	$a1,$a1,%lo(var7f1b2d24)
/*  f103efc:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f103f00:	0043001a */ 	div	$zero,$v0,$v1
/*  f103f04:	14600002 */ 	bnez	$v1,.L0f103f10
/*  f103f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f0c:	0007000d */ 	break	0x7
.L0f103f10:
/*  f103f10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f103f14:	14610004 */ 	bne	$v1,$at,.L0f103f28
/*  f103f18:	3c018000 */ 	lui	$at,0x8000
/*  f103f1c:	14410002 */ 	bne	$v0,$at,.L0f103f28
/*  f103f20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f24:	0006000d */ 	break	0x6
.L0f103f28:
/*  f103f28:	00003810 */ 	mfhi	$a3
/*  f103f2c:	14600002 */ 	bnez	$v1,.L0f103f38
/*  f103f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f34:	0007000d */ 	break	0x7
.L0f103f38:
/*  f103f38:	2401ffff */ 	addiu	$at,$zero,-1
/*  f103f3c:	14610004 */ 	bne	$v1,$at,.L0f103f50
/*  f103f40:	3c018000 */ 	lui	$at,0x8000
/*  f103f44:	15210002 */ 	bne	$t1,$at,.L0f103f50
/*  f103f48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f4c:	0006000d */ 	break	0x6
.L0f103f50:
/*  f103f50:	14600002 */ 	bnez	$v1,.L0f103f5c
/*  f103f54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f58:	0007000d */ 	break	0x7
.L0f103f5c:
/*  f103f5c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f103f60:	14610004 */ 	bne	$v1,$at,.L0f103f74
/*  f103f64:	3c018000 */ 	lui	$at,0x8000
/*  f103f68:	14410002 */ 	bne	$v0,$at,.L0f103f74
/*  f103f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f70:	0006000d */ 	break	0x6
.L0f103f74:
/*  f103f74:	0c004dad */ 	jal	sprintf
/*  f103f78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103f7c:	10000028 */ 	beqz	$zero,.L0f104020
/*  f103f80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f103f84:
/*  f103f84:	0043001a */ 	div	$zero,$v0,$v1
/*  f103f88:	00005012 */ 	mflo	$t2
/*  f103f8c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2d30)
/*  f103f90:	24a52d30 */ 	addiu	$a1,$a1,%lo(var7f1b2d30)
/*  f103f94:	0143001a */ 	div	$zero,$t2,$v1
/*  f103f98:	00003810 */ 	mfhi	$a3
/*  f103f9c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f103fa0:	14600002 */ 	bnez	$v1,.L0f103fac
/*  f103fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103fa8:	0007000d */ 	break	0x7
.L0f103fac:
/*  f103fac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f103fb0:	14610004 */ 	bne	$v1,$at,.L0f103fc4
/*  f103fb4:	3c018000 */ 	lui	$at,0x8000
/*  f103fb8:	14410002 */ 	bne	$v0,$at,.L0f103fc4
/*  f103fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103fc0:	0006000d */ 	break	0x6
.L0f103fc4:
/*  f103fc4:	0043001a */ 	div	$zero,$v0,$v1
/*  f103fc8:	14600002 */ 	bnez	$v1,.L0f103fd4
/*  f103fcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103fd0:	0007000d */ 	break	0x7
.L0f103fd4:
/*  f103fd4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f103fd8:	14610004 */ 	bne	$v1,$at,.L0f103fec
/*  f103fdc:	3c018000 */ 	lui	$at,0x8000
/*  f103fe0:	15410002 */ 	bne	$t2,$at,.L0f103fec
/*  f103fe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103fe8:	0006000d */ 	break	0x6
.L0f103fec:
/*  f103fec:	00005810 */ 	mfhi	$t3
/*  f103ff0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f103ff4:	14600002 */ 	bnez	$v1,.L0f104000
/*  f103ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f103ffc:	0007000d */ 	break	0x7
.L0f104000:
/*  f104000:	2401ffff */ 	addiu	$at,$zero,-1
/*  f104004:	14610004 */ 	bne	$v1,$at,.L0f104018
/*  f104008:	3c018000 */ 	lui	$at,0x8000
/*  f10400c:	14410002 */ 	bne	$v0,$at,.L0f104018
/*  f104010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104014:	0006000d */ 	break	0x6
.L0f104018:
/*  f104018:	0c004dad */ 	jal	sprintf
/*  f10401c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f104020:
/*  f104020:	3c028007 */ 	lui	$v0,0x8007
/*  f104024:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f104028:
/*  f104028:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10402c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f104030:	03e00008 */ 	jr	$ra
/*  f104034:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerBuddyOptionsContinue(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&g_ObjectivesMenuDialog);
	}

	if (operation == MENUOP_CHECKPREFOCUSED) {
		return true;
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10408c
/*  f10408c:	3c0e800a */ 	lui	$t6,0x800a
/*  f104090:	8dcedfe8 */ 	lw	$t6,-0x2018($t6)
/*  f104094:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f104098:	3c05800a */ 	lui	$a1,0x800a
/*  f10409c:	000e7e42 */ 	srl	$t7,$t6,0x19
/*  f1040a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1040a4:	030f1823 */ 	subu	$v1,$t8,$t7
/*  f1040a8:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f1040ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f1040b0:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f1040b4:	3c07fffe */ 	lui	$a3,0xfffe
/*  f1040b8:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f1040bc:
/*  f1040bc:	8cb900a0 */ 	lw	$t9,0xa0($a1)
/*  f1040c0:	03274825 */ 	or	$t1,$t9,$a3
/*  f1040c4:	54c90003 */ 	bnel	$a2,$t1,.L0f1040d4
/*  f1040c8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1040cc:	24820001 */ 	addiu	$v0,$a0,0x1
/*  f1040d0:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f1040d4:
/*  f1040d4:	1488fff9 */ 	bne	$a0,$t0,.L0f1040bc
/*  f1040d8:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1040dc:	00621821 */ 	addu	$v1,$v1,$v0
/*  f1040e0:	28610005 */ 	slti	$at,$v1,0x5
/*  f1040e4:	14200002 */ 	bnez	$at,.L0f1040f0
/*  f1040e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1040ec:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f1040f0:
/*  f1040f0:	1c600002 */ 	bgtz	$v1,.L0f1040fc
/*  f1040f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1040f8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1040fc:
/*  f1040fc:	03e00008 */ 	jr	$ra
/*  f104100:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel menudialog00104104
/*  f104104:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f104108:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10410c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f104110:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f104114:	1481000a */ 	bne	$a0,$at,.L0f104140
/*  f104118:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f10411c:	0fc41023 */ 	jal	func0f10408c
/*  f104120:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f104124:	3c0e800a */ 	lui	$t6,0x800a
/*  f104128:	8dcea434 */ 	lw	$t6,-0x5bcc($t6)
/*  f10412c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f104130:	004e082a */ 	slt	$at,$v0,$t6
/*  f104134:	10200002 */ 	beqz	$at,.L0f104140
/*  f104138:	3c01800a */ 	lui	$at,0x800a
/*  f10413c:	ac22a434 */ 	sw	$v0,-0x5bcc($at)
.L0f104140:
/*  f104140:	24010066 */ 	addiu	$at,$zero,0x66
/*  f104144:	1481001e */ 	bne	$a0,$at,.L0f1041c0
/*  f104148:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10414c:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f104150:	3c02800a */ 	lui	$v0,0x800a
/*  f104154:	8fb90024 */ 	lw	$t9,0x24($sp)
/*  f104158:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10415c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f104160:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f104164:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f104168:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10416c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f104170:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f104174:	00581021 */ 	addu	$v0,$v0,$t8
/*  f104178:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f10417c:	50400011 */ 	beqzl	$v0,.L0f1041c4
/*  f104180:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f104184:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f104188:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f10418c:	5728000d */ 	bnel	$t9,$t0,.L0f1041c4
/*  f104190:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f104194:	8d230000 */ 	lw	$v1,0x0($t1)
/*  f104198:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10419c:	00002825 */ 	or	$a1,$zero,$zero
/*  f1041a0:	806a000a */ 	lb	$t2,0xa($v1)
/*  f1041a4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1041a8:	51400005 */ 	beqzl	$t2,.L0f1041c0
/*  f1041ac:	a060000a */ 	sb	$zero,0xa($v1)
/*  f1041b0:	0fc4100e */ 	jal	menuhandlerBuddyOptionsContinue
/*  f1041b4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f1041b8:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f1041bc:	a060000a */ 	sb	$zero,0xa($v1)
.L0f1041c0:
/*  f1041c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1041c4:
/*  f1041c4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1041c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1041cc:	03e00008 */ 	jr	$ra
/*  f1041d0:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerCoopRadar(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_GET:
		return g_Vars.coopradaron;
	case MENUOP_SET:
		g_Vars.coopradaron = *enable ? 1 : 0;
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerCoopFriendlyFire(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_GET:
		return g_Vars.coopfriendlyfire;
	case MENUOP_SET:
		g_Vars.coopfriendlyfire = *enable ? 1 : 0;
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandlerCoopBuddy
/*  f10429c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1042a0:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b2d40)
/*  f1042a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1042a8:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f1042ac:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1042b0:	25ef2d40 */ 	addiu	$t7,$t7,%lo(var7f1b2d40)
/*  f1042b4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1042b8:	27ae0034 */ 	addiu	$t6,$sp,0x34
/*  f1042bc:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1042c0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1042c4:	95e10008 */ 	lhu	$at,0x8($t7)
/*  f1042c8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1042cc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1042d0:	1085000c */ 	beq	$a0,$a1,.L0f104304
/*  f1042d4:	a5c10008 */ 	sh	$at,0x8($t6)
/*  f1042d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1042dc:	10810017 */ 	beq	$a0,$at,.L0f10433c
/*  f1042e0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1042e4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1042e8:	10810024 */ 	beq	$a0,$at,.L0f10437c
/*  f1042ec:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1042f0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1042f4:	10810031 */ 	beq	$a0,$at,.L0f1043bc
/*  f1042f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1042fc:	10000044 */ 	beqz	$zero,.L0f104410
/*  f104300:	00001025 */ 	or	$v0,$zero,$zero
.L0f104304:
/*  f104304:	0fc41023 */ 	jal	func0f10408c
/*  f104308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10430c:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f104310:	0c005013 */ 	jal	func0001404c
/*  f104314:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f104318:	30490002 */ 	andi	$t1,$v0,0x2
/*  f10431c:	11200002 */ 	beqz	$t1,.L0f104328
/*  f104320:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f104324:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f104328:
/*  f104328:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f10432c:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f104330:	006a5821 */ 	addu	$t3,$v1,$t2
/*  f104334:	10000035 */ 	beqz	$zero,.L0f10440c
/*  f104338:	ad8b0000 */ 	sw	$t3,0x0($t4)
.L0f10433c:
/*  f10433c:	0c005013 */ 	jal	func0001404c
/*  f104340:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f104344:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f104348:	11a00002 */ 	beqz	$t5,.L0f104354
/*  f10434c:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f104350:	00001825 */ 	or	$v1,$zero,$zero
.L0f104354:
/*  f104354:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f104358:	00037840 */ 	sll	$t7,$v1,0x1
/*  f10435c:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f104360:	00187040 */ 	sll	$t6,$t8,0x1
/*  f104364:	01cf4021 */ 	addu	$t0,$t6,$t7
/*  f104368:	03a82021 */ 	addu	$a0,$sp,$t0
/*  f10436c:	0fc5b9f1 */ 	jal	textGet
/*  f104370:	94840034 */ 	lhu	$a0,0x34($a0)
/*  f104374:	10000027 */ 	beqz	$zero,.L0f104414
/*  f104378:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10437c:
/*  f10437c:	0c005013 */ 	jal	func0001404c
/*  f104380:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f104384:	30490002 */ 	andi	$t1,$v0,0x2
/*  f104388:	11200002 */ 	beqz	$t1,.L0f104394
/*  f10438c:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f104390:	00001825 */ 	or	$v1,$zero,$zero
.L0f104394:
/*  f104394:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f104398:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10439c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1043a0:	8c4d0458 */ 	lw	$t5,0x458($v0)
/*  f1043a4:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f1043a8:	35b90001 */ 	ori	$t9,$t5,0x1
/*  f1043ac:	01636021 */ 	addu	$t4,$t3,$v1
/*  f1043b0:	ac4c0474 */ 	sw	$t4,0x474($v0)
/*  f1043b4:	10000015 */ 	beqz	$zero,.L0f10440c
/*  f1043b8:	ac590458 */ 	sw	$t9,0x458($v0)
.L0f1043bc:
/*  f1043bc:	0c005013 */ 	jal	func0001404c
/*  f1043c0:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f1043c4:	30580002 */ 	andi	$t8,$v0,0x2
/*  f1043c8:	8fa30020 */ 	lw	$v1,0x20($sp)
/*  f1043cc:	13000002 */ 	beqz	$t8,.L0f1043d8
/*  f1043d0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1043d4:	00001825 */ 	or	$v1,$zero,$zero
.L0f1043d8:
/*  f1043d8:	14650006 */ 	bne	$v1,$a1,.L0f1043f4
/*  f1043dc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1043e0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1043e4:	8c4e0474 */ 	lw	$t6,0x474($v0)
/*  f1043e8:	15c00002 */ 	bnez	$t6,.L0f1043f4
/*  f1043ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1043f0:	ac450474 */ 	sw	$a1,0x474($v0)
.L0f1043f4:
/*  f1043f4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1043f8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1043fc:	8c4f0474 */ 	lw	$t7,0x474($v0)
/*  f104400:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f104404:	01e34023 */ 	subu	$t0,$t7,$v1
/*  f104408:	ad280000 */ 	sw	$t0,0x0($t1)
.L0f10440c:
/*  f10440c:	00001025 */ 	or	$v0,$zero,$zero
.L0f104410:
/*  f104410:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f104414:
/*  f104414:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f104418:	03e00008 */ 	jr	$ra
/*  f10441c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerAntiRadar(u32 operation, struct menu_item *item, bool *enable)
{
	switch (operation) {
	case MENUOP_GET:
		return g_Vars.antiradaron;
	case MENUOP_SET:
		g_Vars.antiradaron = *enable ? 1 : 0;
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandlerAntiPlayer
/*  f104484:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f104488:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b2d4c)
/*  f10448c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f104490:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f104494:	25ce2d4c */ 	addiu	$t6,$t6,%lo(var7f1b2d4c)
/*  f104498:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f10449c:	27a2001c */ 	addiu	$v0,$sp,0x1c
/*  f1044a0:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f1044a4:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1044a8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1044ac:	1081000a */ 	beq	$a0,$at,.L0f1044d8
/*  f1044b0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1044b4:	1081000a */ 	beq	$a0,$at,.L0f1044e0
/*  f1044b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1044bc:	1081000f */ 	beq	$a0,$at,.L0f1044fc
/*  f1044c0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1044c4:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1044c8:	10810013 */ 	beq	$a0,$at,.L0f104518
/*  f1044cc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1044d0:	10000015 */ 	beqz	$zero,.L0f104528
/*  f1044d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1044d8:
/*  f1044d8:	10000012 */ 	beqz	$zero,.L0f104524
/*  f1044dc:	acc80000 */ 	sw	$t0,0x0($a2)
.L0f1044e0:
/*  f1044e0:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f1044e4:	00095040 */ 	sll	$t2,$t1,0x1
/*  f1044e8:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f1044ec:	0fc5b9f1 */ 	jal	textGet
/*  f1044f0:	95640000 */ 	lhu	$a0,0x0($t3)
/*  f1044f4:	1000000d */ 	beqz	$zero,.L0f10452c
/*  f1044f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1044fc:
/*  f1044fc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f104500:	8c4d0458 */ 	lw	$t5,0x458($v0)
/*  f104504:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f104508:	35b80001 */ 	ori	$t8,$t5,0x1
/*  f10450c:	ac580458 */ 	sw	$t8,0x458($v0)
/*  f104510:	10000004 */ 	beqz	$zero,.L0f104524
/*  f104514:	ac4c0450 */ 	sw	$t4,0x450($v0)
.L0f104518:
/*  f104518:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10451c:	8c4f0450 */ 	lw	$t7,0x450($v0)
/*  f104520:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f104524:
/*  f104524:	00001025 */ 	or	$v0,$zero,$zero
.L0f104528:
/*  f104528:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10452c:
/*  f10452c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f104530:	03e00008 */ 	jr	$ra
/*  f104534:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerCoopDifficulty(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_SET:
		g_MissionConfig.pdmode = false;
		g_MissionConfig.difficulty = item->param;
		setDifficulty(g_MissionConfig.difficulty);
		menuPopDialog();
		menuPushDialog(&g_CoopOptionsMenuDialog);
		break;
	case MENUOP_CHECKDISABLED:
		if (!isStageDifficultyUnlocked(g_MissionConfig.stageindex, item->param)) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerAntiDifficulty(u32 operation, struct menu_item *item, s32 *value)
{
	switch (operation) {
	case MENUOP_SET:
		g_MissionConfig.pdmode = false;
		g_MissionConfig.difficulty = item->param;
		setDifficulty(g_MissionConfig.difficulty);
		menuPopDialog();
		menuPushDialog(&g_AntiOptionsMenuDialog);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f104664
/*  f104664:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f104668:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f10466c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f104670:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f104674:	3c02800a */ 	lui	$v0,0x800a
/*  f104678:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f10467c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f104680:	00009825 */ 	or	$s3,$zero,$zero
/*  f104684:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f104688:	24422200 */ 	addiu	$v0,$v0,0x2200
/*  f10468c:	00008025 */ 	or	$s0,$zero,$zero
.L0f104690:
/*  f104690:	944e0080 */ 	lhu	$t6,0x80($v0)
/*  f104694:	51c00003 */ 	beqzl	$t6,.L0f1046a4
/*  f104698:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10469c:	26130001 */ 	addiu	$s3,$s0,0x1
/*  f1046a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1046a4:
/*  f1046a4:	2a010003 */ 	slti	$at,$s0,0x3
/*  f1046a8:	1420fff9 */ 	bnez	$at,.L0f104690
/*  f1046ac:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f1046b0:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f1046b4:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f1046b8:	80580003 */ 	lb	$t8,0x3($v0)
/*  f1046bc:	07000007 */ 	bltz	$t8,.L0f1046dc
/*  f1046c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1046c4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f1046c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1046cc:	24110020 */ 	addiu	$s1,$zero,0x20
/*  f1046d0:	00194e40 */ 	sll	$t1,$t9,0x19
/*  f1046d4:	05210003 */ 	bgez	$t1,.L0f1046e4
/*  f1046d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1046dc:
/*  f1046dc:	10000008 */ 	beqz	$zero,.L0f104700
/*  f1046e0:	00009025 */ 	or	$s2,$zero,$zero
.L0f1046e4:
/*  f1046e4:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f1046e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1046ec:	1c400002 */ 	bgtz	$v0,.L0f1046f8
/*  f1046f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1046f4:	00009025 */ 	or	$s2,$zero,$zero
.L0f1046f8:
/*  f1046f8:	1611fffa */ 	bne	$s0,$s1,.L0f1046e4
/*  f1046fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f104700:
/*  f104700:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f104704:	02721021 */ 	addu	$v0,$s3,$s2
/*  f104708:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f10470c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f104710:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f104714:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f104718:	03e00008 */ 	jr	$ra
/*  f10471c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f104720
/*  f104720:	3c05800a */ 	lui	$a1,0x800a
/*  f104724:	00001025 */ 	or	$v0,$zero,$zero
/*  f104728:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10472c:	00001825 */ 	or	$v1,$zero,$zero
/*  f104730:	24060003 */ 	addiu	$a2,$zero,0x3
.L0f104734:
/*  f104734:	94ae0080 */ 	lhu	$t6,0x80($a1)
/*  f104738:	51c00003 */ 	beqzl	$t6,.L0f104748
/*  f10473c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f104740:	24620001 */ 	addiu	$v0,$v1,0x1
/*  f104744:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f104748:
/*  f104748:	1466fffa */ 	bne	$v1,$a2,.L0f104734
/*  f10474c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f104750:	0082082a */ 	slt	$at,$a0,$v0
/*  f104754:	10200003 */ 	beqz	$at,.L0f104764
/*  f104758:	24020014 */ 	addiu	$v0,$zero,0x14
/*  f10475c:	03e00008 */ 	jr	$ra
/*  f104760:	24820011 */ 	addiu	$v0,$a0,0x11
.L0f104764:
/*  f104764:	03e00008 */ 	jr	$ra
/*  f104768:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0010476c
/*  f10476c:	27bdfe08 */ 	addiu	$sp,$sp,-504
/*  f104770:	3c0e8007 */ 	lui	$t6,%hi(missions)
/*  f104774:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f104778:	27a201a8 */ 	addiu	$v0,$sp,0x1a8
/*  f10477c:	25ce1f68 */ 	addiu	$t6,$t6,%lo(missions)
/*  f104780:	00c08025 */ 	or	$s0,$a2,$zero
/*  f104784:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f104788:	afa501fc */ 	sw	$a1,0x1fc($sp)
/*  f10478c:	25d90048 */ 	addiu	$t9,$t6,0x48
/*  f104790:	0040c025 */ 	or	$t8,$v0,$zero
.L0f104794:
/*  f104794:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f104798:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f10479c:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f1047a0:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f1047a4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1047a8:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f1047ac:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1047b0:	15d9fff8 */ 	bne	$t6,$t9,.L0f104794
/*  f1047b4:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f1047b8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1047bc:	248fffff */ 	addiu	$t7,$a0,-1
/*  f1047c0:	af010000 */ 	sw	$at,0x0($t8)
/*  f1047c4:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1047c8:	2de10019 */ 	sltiu	$at,$t7,0x19
/*  f1047cc:	1020036d */ 	beqz	$at,.L0f105584
/*  f1047d0:	af190004 */ 	sw	$t9,0x4($t8)
/*  f1047d4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1047d8:	3c017f1b */ 	lui	$at,%hi(var7f1b2d9c)
/*  f1047dc:	002f0821 */ 	addu	$at,$at,$t7
/*  f1047e0:	8c2f2d9c */ 	lw	$t7,%lo(var7f1b2d9c)($at)
/*  f1047e4:	01e00008 */ 	jr	$t7
/*  f1047e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1047ec:	3c0a800a */ 	lui	$t2,0x800a
/*  f1047f0:	3c09800a */ 	lui	$t1,0x800a
/*  f1047f4:	3c08800a */ 	lui	$t0,%hi(g_MissionConfig)
/*  f1047f8:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f1047fc:	2508dfe8 */ 	addiu	$t0,$t0,%lo(g_MissionConfig)
/*  f104800:	25292200 */ 	addiu	$t1,$t1,0x2200
/*  f104804:	254a2200 */ 	addiu	$t2,$t2,0x2200
/*  f104808:	00003025 */ 	or	$a2,$zero,$zero
/*  f10480c:	240b0011 */ 	addiu	$t3,$zero,0x11
/*  f104810:	24070003 */ 	addiu	$a3,$zero,0x3
.L0f104814:
/*  f104814:	91050003 */ 	lbu	$a1,0x3($t0)
/*  f104818:	00002025 */ 	or	$a0,$zero,$zero
/*  f10481c:	00001025 */ 	or	$v0,$zero,$zero
/*  f104820:	0005c9c2 */ 	srl	$t9,$a1,0x7
/*  f104824:	03202825 */ 	or	$a1,$t9,$zero
/*  f104828:	01401825 */ 	or	$v1,$t2,$zero
.L0f10482c:
/*  f10482c:	946e0020 */ 	lhu	$t6,0x20($v1)
/*  f104830:	11c00002 */ 	beqz	$t6,.L0f10483c
/*  f104834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104838:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10483c:
/*  f10483c:	14a00004 */ 	bnez	$a1,.L0f104850
/*  f104840:	00027080 */ 	sll	$t6,$v0,0x2
/*  f104844:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f104848:	0018ce40 */ 	sll	$t9,$t8,0x19
/*  f10484c:	07210008 */ 	bgez	$t9,.L0f104870
.L0f104850:
/*  f104850:	012ec021 */ 	addu	$t8,$t1,$t6
/*  f104854:	8f0f00a0 */ 	lw	$t7,0xa0($t8)
/*  f104858:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f10485c:	00d97004 */ 	sllv	$t6,$t9,$a2
/*  f104860:	01eec024 */ 	and	$t8,$t7,$t6
/*  f104864:	53000003 */ 	beqzl	$t8,.L0f104874
/*  f104868:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10486c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f104870:
/*  f104870:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f104874:
/*  f104874:	1447ffed */ 	bne	$v0,$a3,.L0f10482c
/*  f104878:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f10487c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f104880:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f104884:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f104888:	10800003 */ 	beqz	$a0,.L0f104898
/*  f10488c:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f104890:	14cbffe0 */ 	bne	$a2,$t3,.L0f104814
/*  f104894:	254a0006 */ 	addiu	$t2,$t2,0x6
.L0f104898:
/*  f104898:	0fc41199 */ 	jal	func0f104664
/*  f10489c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1048a0:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1048a4:	01c2c021 */ 	addu	$t8,$t6,$v0
/*  f1048a8:	10000336 */ 	beqz	$zero,.L0f105584
/*  f1048ac:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f1048b0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1048b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1048b8:	27a6018c */ 	addiu	$a2,$sp,0x18c
/*  f1048bc:	54a00009 */ 	bnezl	$a1,.L0f1048e4
/*  f1048c0:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f1048c4:	0fc411db */ 	jal	menuhandler0010476c
/*  f1048c8:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f1048cc:	0fc41199 */ 	jal	func0f104664
/*  f1048d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1048d4:	8fb9018c */ 	lw	$t9,0x18c($sp)
/*  f1048d8:	03222823 */ 	subu	$a1,$t9,$v0
/*  f1048dc:	ae050004 */ 	sw	$a1,0x4($s0)
/*  f1048e0:	8e030000 */ 	lw	$v1,0x0($s0)
.L0f1048e4:
/*  f1048e4:	3c048007 */ 	lui	$a0,0x8007
/*  f1048e8:	0065082b */ 	sltu	$at,$v1,$a1
/*  f1048ec:	10200008 */ 	beqz	$at,.L0f104910
/*  f1048f0:	00037080 */ 	sll	$t6,$v1,0x2
/*  f1048f4:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f1048f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1048fc:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f104900:	0fc5b9f1 */ 	jal	textGet
/*  f104904:	94841e72 */ 	lhu	$a0,0x1e72($a0)
/*  f104908:	10000320 */ 	beqz	$zero,.L0f10558c
/*  f10490c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f104910:
/*  f104910:	0fc411c8 */ 	jal	func0f104720
/*  f104914:	00652023 */ 	subu	$a0,$v1,$a1
/*  f104918:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f10491c:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f104920:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f104924:	3c048007 */ 	lui	$a0,0x8007
/*  f104928:	00982021 */ 	addu	$a0,$a0,$t8
/*  f10492c:	0fc5b9f1 */ 	jal	textGet
/*  f104930:	94841e72 */ 	lhu	$a0,0x1e72($a0)
/*  f104934:	10000315 */ 	beqz	$zero,.L0f10558c
/*  f104938:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f10493c:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f104940:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f104944:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f104948:	27a60178 */ 	addiu	$a2,$sp,0x178
/*  f10494c:	0fc411db */ 	jal	menuhandler0010476c
/*  f104950:	afa70188 */ 	sw	$a3,0x188($sp)
/*  f104954:	0fc41199 */ 	jal	func0f104664
/*  f104958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10495c:	8fb90178 */ 	lw	$t9,0x178($sp)
/*  f104960:	8fa70188 */ 	lw	$a3,0x188($sp)
/*  f104964:	03227823 */ 	subu	$t7,$t9,$v0
/*  f104968:	afaf0178 */ 	sw	$t7,0x178($sp)
/*  f10496c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f104970:	006f082b */ 	sltu	$at,$v1,$t7
/*  f104974:	14200004 */ 	bnez	$at,.L0f104988
/*  f104978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10497c:	0fc411c8 */ 	jal	func0f104720
/*  f104980:	006f2023 */ 	subu	$a0,$v1,$t7
/*  f104984:	00403825 */ 	or	$a3,$v0,$zero
.L0f104988:
/*  f104988:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f10498c:	00077080 */ 	sll	$t6,$a3,0x2
/*  f104990:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f104994:	3c08800a */ 	lui	$t0,%hi(g_MissionConfig)
/*  f104998:	01c77023 */ 	subu	$t6,$t6,$a3
/*  f10499c:	2508dfe8 */ 	addiu	$t0,$t0,%lo(g_MissionConfig)
/*  f1049a0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1049a4:	3c188007 */ 	lui	$t8,0x8007
/*  f1049a8:	810f0003 */ 	lb	$t7,0x3($t0)
/*  f1049ac:	ac400314 */ 	sw	$zero,0x314($v0)
/*  f1049b0:	ac400318 */ 	sw	$zero,0x318($v0)
/*  f1049b4:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f1049b8:	8f181e6c */ 	lw	$t8,0x1e6c($t8)
/*  f1049bc:	a1070002 */ 	sb	$a3,0x2($t0)
/*  f1049c0:	05e10006 */ 	bgez	$t7,.L0f1049dc
/*  f1049c4:	a1180001 */ 	sb	$t8,0x1($t0)
/*  f1049c8:	3c048007 */ 	lui	$a0,%hi(menudialog_selectdifficulty2)
/*  f1049cc:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1049d0:	24841dc4 */ 	addiu	$a0,$a0,%lo(menudialog_selectdifficulty2)
/*  f1049d4:	100002ec */ 	beqz	$zero,.L0f105588
/*  f1049d8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1049dc:
/*  f1049dc:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1049e0:	3c048007 */ 	lui	$a0,%hi(menudialog_selectdifficulty)
/*  f1049e4:	000ece40 */ 	sll	$t9,$t6,0x19
/*  f1049e8:	07210006 */ 	bgez	$t9,.L0f104a04
/*  f1049ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1049f0:	3c048007 */ 	lui	$a0,%hi(menudialog_selectdifficulty3)
/*  f1049f4:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f1049f8:	24841e54 */ 	addiu	$a0,$a0,%lo(menudialog_selectdifficulty3)
/*  f1049fc:	100002e2 */ 	beqz	$zero,.L0f105588
/*  f104a00:	00001025 */ 	or	$v0,$zero,$zero
.L0f104a04:
/*  f104a04:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f104a08:	24841c00 */ 	addiu	$a0,$a0,%lo(menudialog_selectdifficulty)
/*  f104a0c:	100002de */ 	beqz	$zero,.L0f105588
/*  f104a10:	00001025 */ 	or	$v0,$zero,$zero
/*  f104a14:	3c0f000f */ 	lui	$t7,0xf
/*  f104a18:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f104a1c:	100002d9 */ 	beqz	$zero,.L0f105584
/*  f104a20:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f104a24:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f104a28:	3c08800a */ 	lui	$t0,%hi(g_MissionConfig)
/*  f104a2c:	2508dfe8 */ 	addiu	$t0,$t0,%lo(g_MissionConfig)
/*  f104a30:	55c002d5 */ 	bnezl	$t6,.L0f105588
/*  f104a34:	00001025 */ 	or	$v0,$zero,$zero
/*  f104a38:	81190003 */ 	lb	$t9,0x3($t0)
/*  f104a3c:	072202d2 */ 	bltzl	$t9,.L0f105588
/*  f104a40:	00001025 */ 	or	$v0,$zero,$zero
/*  f104a44:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f104a48:	3c09800a */ 	lui	$t1,0x800a
/*  f104a4c:	25292200 */ 	addiu	$t1,$t1,0x2200
/*  f104a50:	000fc640 */ 	sll	$t8,$t7,0x19
/*  f104a54:	070202cc */ 	bltzl	$t8,.L0f105588
/*  f104a58:	00001025 */ 	or	$v0,$zero,$zero
/*  f104a5c:	9139000c */ 	lbu	$t9,0xc($t1)
/*  f104a60:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f104a64:	27a60168 */ 	addiu	$a2,$sp,0x168
/*  f104a68:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f104a6c:	0fc411db */ 	jal	menuhandler0010476c
/*  f104a70:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f104a74:	0fc41199 */ 	jal	func0f104664
/*  f104a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104a7c:	8faf0168 */ 	lw	$t7,0x168($sp)
/*  f104a80:	01e27023 */ 	subu	$t6,$t7,$v0
/*  f104a84:	afae0168 */ 	sw	$t6,0x168($sp)
/*  f104a88:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f104a8c:	030e082b */ 	sltu	$at,$t8,$t6
/*  f104a90:	542002bd */ 	bnezl	$at,.L0f105588
/*  f104a94:	00001025 */ 	or	$v0,$zero,$zero
/*  f104a98:	0fc41199 */ 	jal	func0f104664
/*  f104a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104aa0:	8fb90168 */ 	lw	$t9,0x168($sp)
/*  f104aa4:	00401825 */ 	or	$v1,$v0,$zero
/*  f104aa8:	00002025 */ 	or	$a0,$zero,$zero
/*  f104aac:	272fffff */ 	addiu	$t7,$t9,-1
/*  f104ab0:	184002b4 */ 	blez	$v0,.L0f105584
/*  f104ab4:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f104ab8:	afa30164 */ 	sw	$v1,0x164($sp)
.L0f104abc:
/*  f104abc:	0fc411c8 */ 	jal	func0f104720
/*  f104ac0:	afa40160 */ 	sw	$a0,0x160($sp)
/*  f104ac4:	3c09800a */ 	lui	$t1,0x800a
/*  f104ac8:	25292200 */ 	addiu	$t1,$t1,0x2200
/*  f104acc:	9138000c */ 	lbu	$t8,0xc($t1)
/*  f104ad0:	8fa30164 */ 	lw	$v1,0x164($sp)
/*  f104ad4:	8fa40160 */ 	lw	$a0,0x160($sp)
/*  f104ad8:	14580003 */ 	bne	$v0,$t8,.L0f104ae8
/*  f104adc:	8fae0168 */ 	lw	$t6,0x168($sp)
/*  f104ae0:	01c4c821 */ 	addu	$t9,$t6,$a0
/*  f104ae4:	ae190000 */ 	sw	$t9,0x0($s0)
.L0f104ae8:
/*  f104ae8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f104aec:	0083082a */ 	slt	$at,$a0,$v1
/*  f104af0:	5420fff2 */ 	bnezl	$at,.L0f104abc
/*  f104af4:	afa30164 */ 	sw	$v1,0x164($sp)
/*  f104af8:	100002a3 */ 	beqz	$zero,.L0f105588
/*  f104afc:	00001025 */ 	or	$v0,$zero,$zero
/*  f104b00:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f104b04:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f104b08:	0fc411db */ 	jal	menuhandler0010476c
/*  f104b0c:	27a60150 */ 	addiu	$a2,$sp,0x150
/*  f104b10:	0fc41199 */ 	jal	func0f104664
/*  f104b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104b18:	8faf0150 */ 	lw	$t7,0x150($sp)
/*  f104b1c:	27a301a8 */ 	addiu	$v1,$sp,0x1a8
/*  f104b20:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f104b24:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f104b28:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f104b2c:	27a201f8 */ 	addiu	$v0,$sp,0x1f8
/*  f104b30:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f104b34:
/*  f104b34:	8fb90150 */ 	lw	$t9,0x150($sp)
/*  f104b38:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f104b3c:	01d9082b */ 	sltu	$at,$t6,$t9
/*  f104b40:	10200004 */ 	beqz	$at,.L0f104b54
/*  f104b44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104b48:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f104b4c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f104b50:	ae18000c */ 	sw	$t8,0xc($s0)
.L0f104b54:
/*  f104b54:	5462fff7 */ 	bnel	$v1,$v0,.L0f104b34
/*  f104b58:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f104b5c:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f104b60:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f104b64:	10000287 */ 	beqz	$zero,.L0f105584
/*  f104b68:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f104b6c:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f104b70:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f104b74:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f104b78:	146f0005 */ 	bne	$v1,$t7,.L0f104b90
/*  f104b7c:	00587021 */ 	addu	$t6,$v0,$t8
/*  f104b80:	0fc5b9f1 */ 	jal	textGet
/*  f104b84:	97a401f4 */ 	lhu	$a0,0x1f4($sp)
/*  f104b88:	10000280 */ 	beqz	$zero,.L0f10558c
/*  f104b8c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f104b90:
/*  f104b90:	0fc5b9f1 */ 	jal	textGet
/*  f104b94:	95c40004 */ 	lhu	$a0,0x4($t6)
/*  f104b98:	1000027c */ 	beqz	$zero,.L0f10558c
/*  f104b9c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f104ba0:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f104ba4:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f104ba8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f104bac:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f104bb0:	14790009 */ 	bne	$v1,$t9,.L0f104bd8
/*  f104bb4:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f104bb8:	0fc411db */ 	jal	menuhandler0010476c
/*  f104bbc:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f104bc0:	0fc41199 */ 	jal	func0f104664
/*  f104bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104bc8:	8faf013c */ 	lw	$t7,0x13c($sp)
/*  f104bcc:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f104bd0:	1000026c */ 	beqz	$zero,.L0f105584
/*  f104bd4:	ae180008 */ 	sw	$t8,0x8($s0)
.L0f104bd8:
/*  f104bd8:	004ec821 */ 	addu	$t9,$v0,$t6
/*  f104bdc:	8f2f0000 */ 	lw	$t7,0x0($t9)
/*  f104be0:	10000268 */ 	beqz	$zero,.L0f105584
/*  f104be4:	ae0f0008 */ 	sw	$t7,0x8($s0)
/*  f104be8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f104bec:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f104bf0:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f104bf4:	afa00124 */ 	sw	$zero,0x124($sp)
/*  f104bf8:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f104bfc:	afa500ec */ 	sw	$a1,0xec($sp)
/*  f104c00:	8e03000c */ 	lw	$v1,0xc($s0)
/*  f104c04:	1460000c */ 	bnez	$v1,.L0f104c38
/*  f104c08:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f104c0c:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f104c10:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f104c14:	0fc411db */ 	jal	menuhandler0010476c
/*  f104c18:	afaa0134 */ 	sw	$t2,0x134($sp)
/*  f104c1c:	0fc41199 */ 	jal	func0f104664
/*  f104c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104c24:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f104c28:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f104c2c:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f104c30:	01c21823 */ 	subu	$v1,$t6,$v0
/*  f104c34:	ae03000c */ 	sw	$v1,0xc($s0)
.L0f104c38:
/*  f104c38:	00a3082b */ 	sltu	$at,$a1,$v1
/*  f104c3c:	14200005 */ 	bnez	$at,.L0f104c54
/*  f104c40:	00a32023 */ 	subu	$a0,$a1,$v1
/*  f104c44:	0fc411c8 */ 	jal	func0f104720
/*  f104c48:	afaa0134 */ 	sw	$t2,0x134($sp)
/*  f104c4c:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f104c50:	afa200ec */ 	sw	$v0,0xec($sp)
.L0f104c54:
/*  f104c54:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f104c58:	3c0ee700 */ 	lui	$t6,0xe700
/*  f104c5c:	27b00138 */ 	addiu	$s0,$sp,0x138
/*  f104c60:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f104c64:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f104c68:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f104c6c:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f104c70:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f104c74:	3c18ba00 */ 	lui	$t8,0xba00
/*  f104c78:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f104c7c:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f104c80:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f104c84:	af200004 */ 	sw	$zero,0x4($t9)
/*  f104c88:	af380000 */ 	sw	$t8,0x0($t9)
/*  f104c8c:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f104c90:	3c0fb900 */ 	lui	$t7,0xb900
/*  f104c94:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f104c98:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f104c9c:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f104ca0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f104ca4:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f104ca8:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f104cac:	3c19ba00 */ 	lui	$t9,0xba00
/*  f104cb0:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f104cb4:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f104cb8:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f104cbc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f104cc0:	af190000 */ 	sw	$t9,0x0($t8)
/*  f104cc4:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f104cc8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f104ccc:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f104cd0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f104cd4:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f104cd8:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f104cdc:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f104ce0:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f104ce4:	8fa200ec */ 	lw	$v0,0xec($sp)
/*  f104ce8:	3c18800b */ 	lui	$t8,0x800b
/*  f104cec:	8f18b5a8 */ 	lw	$t8,-0x4a58($t8)
/*  f104cf0:	00027880 */ 	sll	$t7,$v0,0x2
/*  f104cf4:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f104cf8:	000f1080 */ 	sll	$v0,$t7,0x2
/*  f104cfc:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f104d00:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f104d04:	03022821 */ 	addu	$a1,$t8,$v0
/*  f104d08:	24a5009c */ 	addiu	$a1,$a1,0x9c
/*  f104d0c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f104d10:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f104d14:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f104d18:	afaa0134 */ 	sw	$t2,0x134($sp)
/*  f104d1c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f104d20:	02002025 */ 	or	$a0,$s0,$zero
/*  f104d24:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f104d28:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f104d2c:	00003825 */ 	or	$a3,$zero,$zero
/*  f104d30:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f104d34:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f104d38:	3c0eba00 */ 	lui	$t6,0xba00
/*  f104d3c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f104d40:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f104d44:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f104d48:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f104d4c:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f104d50:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f104d54:	3c0eff37 */ 	lui	$t6,0xff37
/*  f104d58:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f104d5c:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f104d60:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f104d64:	37189a25 */ 	ori	$t8,$t8,0x9a25
/*  f104d68:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f104d6c:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f104d70:	af380000 */ 	sw	$t8,0x0($t9)
/*  f104d74:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f104d78:	3c18ba00 */ 	lui	$t8,0xba00
/*  f104d7c:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f104d80:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f104d84:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f104d88:	af200004 */ 	sw	$zero,0x4($t9)
/*  f104d8c:	af380000 */ 	sw	$t8,0x0($t9)
/*  f104d90:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f104d94:	03202025 */ 	or	$a0,$t9,$zero
/*  f104d98:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f104d9c:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f104da0:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f104da4:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f104da8:	8d4f000c */ 	lw	$t7,0xc($t2)
/*  f104dac:	01c02825 */ 	or	$a1,$t6,$zero
/*  f104db0:	241fff00 */ 	addiu	$ra,$zero,-256
/*  f104db4:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f104db8:	00187200 */ 	sll	$t6,$t8,0x8
/*  f104dbc:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f104dc0:	000eca02 */ 	srl	$t9,$t6,0x8
/*  f104dc4:	033f7825 */ 	or	$t7,$t9,$ra
/*  f104dc8:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f104dcc:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f104dd0:	3c098008 */ 	lui	$t1,%hi(var8007fac0)
/*  f104dd4:	2529fac0 */ 	addiu	$t1,$t1,%lo(var8007fac0)
/*  f104dd8:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f104ddc:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f104de0:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f104de4:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f104de8:	03003025 */ 	or	$a2,$t8,$zero
/*  f104dec:	272f003c */ 	addiu	$t7,$t9,0x3c
/*  f104df0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f104df4:	030e0019 */ 	multu	$t8,$t6
/*  f104df8:	3c01e400 */ 	lui	$at,0xe400
/*  f104dfc:	3c08800a */ 	lui	$t0,%hi(g_MissionConfig)
/*  f104e00:	2508dfe8 */ 	addiu	$t0,$t0,%lo(g_MissionConfig)
/*  f104e04:	3c0b800b */ 	lui	$t3,%hi(var800ab5a8)
/*  f104e08:	256bb5a8 */ 	addiu	$t3,$t3,%lo(var800ab5a8)
/*  f104e0c:	0000c812 */ 	mflo	$t9
/*  f104e10:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f104e14:	8d590004 */ 	lw	$t9,0x4($t2)
/*  f104e18:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f104e1c:	03017025 */ 	or	$t6,$t8,$at
/*  f104e20:	272f0027 */ 	addiu	$t7,$t9,0x27
/*  f104e24:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f104e28:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f104e2c:	01d97825 */ 	or	$t7,$t6,$t9
/*  f104e30:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f104e34:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f104e38:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f104e3c:	270e0004 */ 	addiu	$t6,$t8,0x4
/*  f104e40:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f104e44:	032f0019 */ 	multu	$t9,$t7
/*  f104e48:	8d4f0004 */ 	lw	$t7,0x4($t2)
/*  f104e4c:	0000c012 */ 	mflo	$t8
/*  f104e50:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f104e54:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f104e58:	25f80003 */ 	addiu	$t8,$t7,0x3
/*  f104e5c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f104e60:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f104e64:	032fc025 */ 	or	$t8,$t9,$t7
/*  f104e68:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f104e6c:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f104e70:	24180480 */ 	addiu	$t8,$zero,0x480
/*  f104e74:	3c0fb400 */ 	lui	$t7,0xb400
/*  f104e78:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f104e7c:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f104e80:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f104e84:	add80004 */ 	sw	$t8,0x4($t6)
/*  f104e88:	01c01025 */ 	or	$v0,$t6,$zero
/*  f104e8c:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f104e90:	3c0fb300 */ 	lui	$t7,0xb300
/*  f104e94:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f104e98:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f104e9c:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f104ea0:	01c01825 */ 	or	$v1,$t6,$zero
/*  f104ea4:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f104ea8:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f104eac:	01d8001a */ 	div	$zero,$t6,$t8
/*  f104eb0:	00007812 */ 	mflo	$t7
/*  f104eb4:	17000002 */ 	bnez	$t8,.L0f104ec0
/*  f104eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104ebc:	0007000d */ 	break	0x7
.L0f104ec0:
/*  f104ec0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f104ec4:	17010004 */ 	bne	$t8,$at,.L0f104ed8
/*  f104ec8:	3c018000 */ 	lui	$at,0x8000
/*  f104ecc:	15c10002 */ 	bne	$t6,$at,.L0f104ed8
/*  f104ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f104ed4:	0006000d */ 	break	0x6
.L0f104ed8:
/*  f104ed8:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f104edc:	35d8fc00 */ 	ori	$t8,$t6,0xfc00
/*  f104ee0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f104ee4:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f104ee8:	00197e40 */ 	sll	$t7,$t9,0x19
/*  f104eec:	000f77c2 */ 	srl	$t6,$t7,0x1f
/*  f104ef0:	55c0014f */ 	bnezl	$t6,.L0f105430
/*  f104ef4:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f104ef8:	81190003 */ 	lb	$t9,0x3($t0)
/*  f104efc:	02002025 */ 	or	$a0,$s0,$zero
/*  f104f00:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f104f04:	072100a2 */ 	bgez	$t9,.L0f105190
/*  f104f08:	00003825 */ 	or	$a3,$zero,$zero
/*  f104f0c:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f104f10:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f104f14:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f104f18:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f104f1c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f104f20:	02002025 */ 	or	$a0,$s0,$zero
/*  f104f24:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f104f28:	00003825 */ 	or	$a3,$zero,$zero
/*  f104f2c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f104f30:	afaa0134 */ 	sw	$t2,0x134($sp)
/*  f104f34:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f104f38:	24a501b0 */ 	addiu	$a1,$a1,0x1b0
/*  f104f3c:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f104f40:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f104f44:	3c0fba00 */ 	lui	$t7,0xba00
/*  f104f48:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f104f4c:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f104f50:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f104f54:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f104f58:	af000004 */ 	sw	$zero,0x4($t8)
/*  f104f5c:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f104f60:	3c19ba00 */ 	lui	$t9,0xba00
/*  f104f64:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f104f68:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f104f6c:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f104f70:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f104f74:	add90000 */ 	sw	$t9,0x0($t6)
/*  f104f78:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f104f7c:	3c098008 */ 	lui	$t1,%hi(var8007fac0)
/*  f104f80:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f104f84:	3c06800a */ 	lui	$a2,0x800a
/*  f104f88:	3c10800a */ 	lui	$s0,0x800a
/*  f104f8c:	3c0b0010 */ 	lui	$t3,0x10
/*  f104f90:	2529fac0 */ 	addiu	$t1,$t1,%lo(var8007fac0)
/*  f104f94:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f104f98:	241fff00 */ 	addiu	$ra,$zero,-256
/*  f104f9c:	356b01c0 */ 	ori	$t3,$t3,0x1c0
/*  f104fa0:	2610220c */ 	addiu	$s0,$s0,0x220c
/*  f104fa4:	24c62200 */ 	addiu	$a2,$a2,0x2200
/*  f104fa8:	2405003f */ 	addiu	$a1,$zero,0x3f
/*  f104fac:	2408003f */ 	addiu	$t0,$zero,0x3f
/*  f104fb0:	01ee6004 */ 	sllv	$t4,$t6,$t7
.L0f104fb4:
/*  f104fb4:	8cd800a0 */ 	lw	$t8,0xa0($a2)
/*  f104fb8:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f104fbc:	00a03825 */ 	or	$a3,$a1,$zero
/*  f104fc0:	030cc824 */ 	and	$t9,$t8,$t4
/*  f104fc4:	17200016 */ 	bnez	$t9,.L0f105020
/*  f104fc8:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f104fcc:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f104fd0:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f104fd4:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f104fd8:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f104fdc:	8d58000c */ 	lw	$t8,0xc($t2)
/*  f104fe0:	331900ff */ 	andi	$t9,$t8,0xff
/*  f104fe4:	03280019 */ 	multu	$t9,$t0
/*  f104fe8:	00007012 */ 	mflo	$t6
/*  f104fec:	000e7a02 */ 	srl	$t7,$t6,0x8
/*  f104ff0:	01ffc025 */ 	or	$t8,$t7,$ra
/*  f104ff4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f104ff8:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f104ffc:	3c18ff37 */ 	lui	$t8,0xff37
/*  f105000:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f105004:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f105008:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f10500c:	35ef9a25 */ 	ori	$t7,$t7,0x9a25
/*  f105010:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f105014:	af380004 */ 	sw	$t8,0x4($t9)
/*  f105018:	10000017 */ 	beqz	$zero,.L0f105078
/*  f10501c:	af2f0000 */ 	sw	$t7,0x0($t9)
.L0f105020:
/*  f105020:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f105024:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f105028:	8d4f000c */ 	lw	$t7,0xc($t2)
/*  f10502c:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f105030:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f105034:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f105038:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10503c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f105040:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f105044:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f105048:	00197202 */ 	srl	$t6,$t9,0x8
/*  f10504c:	01df7825 */ 	or	$t7,$t6,$ra
/*  f105050:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f105054:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f105058:	3c0ffffc */ 	lui	$t7,0xfffc
/*  f10505c:	3c0efcff */ 	lui	$t6,0xfcff
/*  f105060:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f105064:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f105068:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f10506c:	35eff279 */ 	ori	$t7,$t7,0xf279
/*  f105070:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f105074:	af0e0000 */ 	sw	$t6,0x0($t8)
.L0f105078:
/*  f105078:	8fb80138 */ 	lw	$t8,0x138($sp)
/*  f10507c:	3c01e400 */ 	lui	$at,0xe400
/*  f105080:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f105084:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f105088:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f10508c:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f105090:	03001025 */ 	or	$v0,$t8,$zero
/*  f105094:	24a50011 */ 	addiu	$a1,$a1,0x11
/*  f105098:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f10509c:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f1050a0:	25f8000e */ 	addiu	$t8,$t7,0xe
/*  f1050a4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1050a8:	032e0019 */ 	multu	$t9,$t6
/*  f1050ac:	00007812 */ 	mflo	$t7
/*  f1050b0:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f1050b4:	8d4f0004 */ 	lw	$t7,0x4($t2)
/*  f1050b8:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f1050bc:	03217025 */ 	or	$t6,$t9,$at
/*  f1050c0:	25f80027 */ 	addiu	$t8,$t7,0x27
/*  f1050c4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1050c8:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f1050cc:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f1050d0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f1050d4:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f1050d8:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f1050dc:	03277021 */ 	addu	$t6,$t9,$a3
/*  f1050e0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1050e4:	01f80019 */ 	multu	$t7,$t8
/*  f1050e8:	8d580004 */ 	lw	$t8,0x4($t2)
/*  f1050ec:	0000c812 */ 	mflo	$t9
/*  f1050f0:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f1050f4:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f1050f8:	27190019 */ 	addiu	$t9,$t8,0x19
/*  f1050fc:	00197080 */ 	sll	$t6,$t9,0x2
/*  f105100:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f105104:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f105108:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f10510c:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f105110:	3c18b400 */ 	lui	$t8,0xb400
/*  f105114:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f105118:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f10511c:	adcb0004 */ 	sw	$t3,0x4($t6)
/*  f105120:	add80000 */ 	sw	$t8,0x0($t6)
/*  f105124:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f105128:	01c01825 */ 	or	$v1,$t6,$zero
/*  f10512c:	3c0fb300 */ 	lui	$t7,0xb300
/*  f105130:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f105134:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f105138:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f10513c:	03202025 */ 	or	$a0,$t9,$zero
/*  f105140:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f105144:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f105148:	0338001a */ 	div	$zero,$t9,$t8
/*  f10514c:	00007012 */ 	mflo	$t6
/*  f105150:	31cfffff */ 	andi	$t7,$t6,0xffff
/*  f105154:	17000002 */ 	bnez	$t8,.L0f105160
/*  f105158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10515c:	0007000d */ 	break	0x7
.L0f105160:
/*  f105160:	2401ffff */ 	addiu	$at,$zero,-1
/*  f105164:	17010004 */ 	bne	$t8,$at,.L0f105178
/*  f105168:	3c018000 */ 	lui	$at,0x8000
/*  f10516c:	17210002 */ 	bne	$t9,$at,.L0f105178
/*  f105170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105174:	0006000d */ 	break	0x6
.L0f105178:
/*  f105178:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f10517c:	3738fc00 */ 	ori	$t8,$t9,0xfc00
/*  f105180:	14d0ff8c */ 	bne	$a2,$s0,.L0f104fb4
/*  f105184:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f105188:	100000a9 */ 	beqz	$zero,.L0f105430
/*  f10518c:	8d590000 */ 	lw	$t9,0x0($t2)
.L0f105190:
/*  f105190:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f105194:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f105198:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10519c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1051a0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1051a4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1051a8:	afaa0134 */ 	sw	$t2,0x134($sp)
/*  f1051ac:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1051b0:	24a50198 */ 	addiu	$a1,$a1,0x198
/*  f1051b4:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f1051b8:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f1051bc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1051c0:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f1051c4:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f1051c8:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f1051cc:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f1051d0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1051d4:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f1051d8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1051dc:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f1051e0:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f1051e4:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f1051e8:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f1051ec:	adf80000 */ 	sw	$t8,0x0($t7)
/*  f1051f0:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f1051f4:	3c18fffc */ 	lui	$t8,0xfffc
/*  f1051f8:	3c19fcff */ 	lui	$t9,0xfcff
/*  f1051fc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f105200:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f105204:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f105208:	3718f279 */ 	ori	$t8,$t8,0xf279
/*  f10520c:	add80004 */ 	sw	$t8,0x4($t6)
/*  f105210:	add90000 */ 	sw	$t9,0x0($t6)
/*  f105214:	8fa70138 */ 	lw	$a3,0x138($sp)
/*  f105218:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f10521c:	241fff00 */ 	addiu	$ra,$zero,-256
/*  f105220:	24ef0008 */ 	addiu	$t7,$a3,0x8
/*  f105224:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f105228:	aced0000 */ 	sw	$t5,0x0($a3)
/*  f10522c:	8d59000c */ 	lw	$t9,0xc($t2)
/*  f105230:	3c098008 */ 	lui	$t1,%hi(var8007fac0)
/*  f105234:	2529fac0 */ 	addiu	$t1,$t1,%lo(var8007fac0)
/*  f105238:	333800ff */ 	andi	$t8,$t9,0xff
/*  f10523c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f105240:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f105244:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f105248:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f10524c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f105250:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f105254:	000e7a02 */ 	srl	$t7,$t6,0x8
/*  f105258:	01ffc825 */ 	or	$t9,$t7,$ra
/*  f10525c:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f105260:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f105264:	3c0f800a */ 	lui	$t7,0x800a
/*  f105268:	25ef2200 */ 	addiu	$t7,$t7,0x2200
/*  f10526c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f105270:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f105274:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f105278:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f10527c:	00001825 */ 	or	$v1,$zero,$zero
.L0f105280:
/*  f105280:	94590020 */ 	lhu	$t9,0x20($v0)
/*  f105284:	24780001 */ 	addiu	$t8,$v1,0x1
/*  f105288:	53200003 */ 	beqzl	$t9,.L0f105298
/*  f10528c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f105290:	afb80124 */ 	sw	$t8,0x124($sp)
/*  f105294:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f105298:
/*  f105298:	28610003 */ 	slti	$at,$v1,0x3
/*  f10529c:	1420fff8 */ 	bnez	$at,.L0f105280
/*  f1052a0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f1052a4:	8fa70124 */ 	lw	$a3,0x124($sp)
/*  f1052a8:	3c0b0010 */ 	lui	$t3,0x10
/*  f1052ac:	356b01c0 */ 	ori	$t3,$t3,0x1c0
/*  f1052b0:	00077100 */ 	sll	$t6,$a3,0x4
/*  f1052b4:	01c77021 */ 	addu	$t6,$t6,$a3
/*  f1052b8:	25c7003f */ 	addiu	$a3,$t6,0x3f
/*  f1052bc:	2405003f */ 	addiu	$a1,$zero,0x3f
/*  f1052c0:	3c10e400 */ 	lui	$s0,0xe400
/*  f1052c4:	240c0072 */ 	addiu	$t4,$zero,0x72
/*  f1052c8:	2408003f */ 	addiu	$t0,$zero,0x3f
.L0f1052cc:
/*  f1052cc:	14a70015 */ 	bne	$a1,$a3,.L0f105324
/*  f1052d0:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1052d4:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f1052d8:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f1052dc:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f1052e0:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1052e4:	8d58000c */ 	lw	$t8,0xc($t2)
/*  f1052e8:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f1052ec:	01c80019 */ 	multu	$t6,$t0
/*  f1052f0:	00007812 */ 	mflo	$t7
/*  f1052f4:	000fca02 */ 	srl	$t9,$t7,0x8
/*  f1052f8:	033fc025 */ 	or	$t8,$t9,$ra
/*  f1052fc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f105300:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f105304:	3c18ff37 */ 	lui	$t8,0xff37
/*  f105308:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f10530c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f105310:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f105314:	37399a25 */ 	ori	$t9,$t9,0x9a25
/*  f105318:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f10531c:	add80004 */ 	sw	$t8,0x4($t6)
/*  f105320:	add90000 */ 	sw	$t9,0x0($t6)
.L0f105324:
/*  f105324:	8fae0138 */ 	lw	$t6,0x138($sp)
/*  f105328:	24a50011 */ 	addiu	$a1,$a1,0x11
/*  f10532c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f105330:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f105334:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f105338:	01c01025 */ 	or	$v0,$t6,$zero
/*  f10533c:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f105340:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f105344:	270e000e */ 	addiu	$t6,$t8,0xe
/*  f105348:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10534c:	01f90019 */ 	multu	$t7,$t9
/*  f105350:	0000c012 */ 	mflo	$t8
/*  f105354:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f105358:	8d580004 */ 	lw	$t8,0x4($t2)
/*  f10535c:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f105360:	01f0c825 */ 	or	$t9,$t7,$s0
/*  f105364:	270e0027 */ 	addiu	$t6,$t8,0x27
/*  f105368:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10536c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f105370:	03387025 */ 	or	$t6,$t9,$t8
/*  f105374:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f105378:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f10537c:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f105380:	01e6c821 */ 	addu	$t9,$t7,$a2
/*  f105384:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f105388:	030e0019 */ 	multu	$t8,$t6
/*  f10538c:	8d4e0004 */ 	lw	$t6,0x4($t2)
/*  f105390:	00007812 */ 	mflo	$t7
/*  f105394:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f105398:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f10539c:	25cf0019 */ 	addiu	$t7,$t6,0x19
/*  f1053a0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1053a4:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f1053a8:	030e7825 */ 	or	$t7,$t8,$t6
/*  f1053ac:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1053b0:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f1053b4:	3c0eb400 */ 	lui	$t6,0xb400
/*  f1053b8:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f1053bc:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f1053c0:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f1053c4:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f1053c8:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f1053cc:	03201825 */ 	or	$v1,$t9,$zero
/*  f1053d0:	3c18b300 */ 	lui	$t8,0xb300
/*  f1053d4:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f1053d8:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f1053dc:	adf80000 */ 	sw	$t8,0x0($t7)
/*  f1053e0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1053e4:	240f0400 */ 	addiu	$t7,$zero,0x400
/*  f1053e8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f1053ec:	01ee001a */ 	div	$zero,$t7,$t6
/*  f1053f0:	0000c812 */ 	mflo	$t9
/*  f1053f4:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f1053f8:	15c00002 */ 	bnez	$t6,.L0f105404
/*  f1053fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105400:	0007000d */ 	break	0x7
.L0f105404:
/*  f105404:	2401ffff */ 	addiu	$at,$zero,-1
/*  f105408:	15c10004 */ 	bne	$t6,$at,.L0f10541c
/*  f10540c:	3c018000 */ 	lui	$at,0x8000
/*  f105410:	15e10002 */ 	bne	$t7,$at,.L0f10541c
/*  f105414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105418:	0006000d */ 	break	0x6
.L0f10541c:
/*  f10541c:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f105420:	35eefc00 */ 	ori	$t6,$t7,0xfc00
/*  f105424:	14acffa9 */ 	bne	$a1,$t4,.L0f1052cc
/*  f105428:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f10542c:	8d590000 */ 	lw	$t9,0x0($t2)
.L0f105430:
/*  f105430:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f105434:	2738003e */ 	addiu	$t8,$t9,0x3e
/*  f105438:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f10543c:	8d4f0004 */ 	lw	$t7,0x4($t2)
/*  f105440:	afaa0134 */ 	sw	$t2,0x134($sp)
/*  f105444:	25ee0003 */ 	addiu	$t6,$t7,0x3
/*  f105448:	0fc54d8a */ 	jal	func0f153628
/*  f10544c:	afae012c */ 	sw	$t6,0x12c($sp)
/*  f105450:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f105454:	3c188007 */ 	lui	$t8,%hi(g_StageNames)
/*  f105458:	27181e6c */ 	addiu	$t8,$t8,%lo(g_StageNames)
/*  f10545c:	03381821 */ 	addu	$v1,$t9,$t8
/*  f105460:	afa20138 */ 	sw	$v0,0x138($sp)
/*  f105464:	94640006 */ 	lhu	$a0,0x6($v1)
/*  f105468:	0fc5b9f1 */ 	jal	textGet
/*  f10546c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f105470:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f105474:	0c004c4c */ 	jal	strcpy
/*  f105478:	00402825 */ 	or	$a1,$v0,$zero
/*  f10547c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2d50)
/*  f105480:	24a52d50 */ 	addiu	$a1,$a1,%lo(var7f1b2d50)
/*  f105484:	0c004c89 */ 	jal	func00013224
/*  f105488:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f10548c:	0c002f02 */ 	jal	func0000bc08
/*  f105490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105494:	00028400 */ 	sll	$s0,$v0,0x10
/*  f105498:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f10549c:	0c002f06 */ 	jal	func0000bc18
/*  f1054a0:	01e08025 */ 	or	$s0,$t7,$zero
/*  f1054a4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1054a8:	3c198008 */ 	lui	$t9,0x8008
/*  f1054ac:	8f39fb14 */ 	lw	$t9,-0x4ec($t9)
/*  f1054b0:	8dcefb18 */ 	lw	$t6,-0x4e8($t6)
/*  f1054b4:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f1054b8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1054bc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1054c0:	8d58000c */ 	lw	$t8,0xc($t2)
/*  f1054c4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1054c8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1054cc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1054d0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1054d4:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f1054d8:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f1054dc:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f1054e0:	27a700f0 */ 	addiu	$a3,$sp,0xf0
/*  f1054e4:	0fc5580f */ 	jal	func0f15603c
/*  f1054e8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1054ec:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f1054f0:	afa20138 */ 	sw	$v0,0x138($sp)
/*  f1054f4:	0fc5b9f1 */ 	jal	textGet
/*  f1054f8:	95e40008 */ 	lhu	$a0,0x8($t7)
/*  f1054fc:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f105500:	0c004c4c */ 	jal	strcpy
/*  f105504:	00402825 */ 	or	$a1,$v0,$zero
/*  f105508:	0c002f02 */ 	jal	func0000bc08
/*  f10550c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105510:	00028400 */ 	sll	$s0,$v0,0x10
/*  f105514:	00107403 */ 	sra	$t6,$s0,0x10
/*  f105518:	0c002f06 */ 	jal	func0000bc18
/*  f10551c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f105520:	3c198008 */ 	lui	$t9,0x8008
/*  f105524:	3c188008 */ 	lui	$t8,0x8008
/*  f105528:	8f18fb0c */ 	lw	$t8,-0x4f4($t8)
/*  f10552c:	8f39fb10 */ 	lw	$t9,-0x4f0($t9)
/*  f105530:	8faa0134 */ 	lw	$t2,0x134($sp)
/*  f105534:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f105538:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f10553c:	8d4f000c */ 	lw	$t7,0xc($t2)
/*  f105540:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f105544:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f105548:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10554c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f105550:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f105554:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f105558:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f10555c:	27a700f0 */ 	addiu	$a3,$sp,0xf0
/*  f105560:	0fc5580f */ 	jal	func0f15603c
/*  f105564:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f105568:	afa20138 */ 	sw	$v0,0x138($sp)
/*  f10556c:	0fc54de0 */ 	jal	func0f153780
/*  f105570:	00402025 */ 	or	$a0,$v0,$zero
/*  f105574:	10000005 */ 	beqz	$zero,.L0f10558c
/*  f105578:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f10557c:	240e002a */ 	addiu	$t6,$zero,0x2a
/*  f105580:	ae0e0000 */ 	sw	$t6,0x0($s0)
.L0f105584:
/*  f105584:	00001025 */ 	or	$v0,$zero,$zero
.L0f105588:
/*  f105588:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f10558c:
/*  f10558c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f105590:	27bd01f8 */ 	addiu	$sp,$sp,0x1f8
/*  f105594:	03e00008 */ 	jr	$ra
/*  f105598:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010559c
/*  f10559c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1055a0:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1055a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1055a8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1055ac:	10810028 */ 	beq	$a0,$at,.L0f105650
/*  f1055b0:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1055b4:	24010065 */ 	addiu	$at,$zero,0x65
/*  f1055b8:	14810025 */ 	bne	$a0,$at,.L0f105650
/*  f1055bc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f1055c0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f1055c4:	8c620458 */ 	lw	$v0,0x458($v1)
/*  f1055c8:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f1055cc:	51c00016 */ 	beqzl	$t6,.L0f105628
/*  f1055d0:	304b0004 */ 	andi	$t3,$v0,0x4
/*  f1055d4:	8c6f0298 */ 	lw	$t7,0x298($v1)
/*  f1055d8:	05e30013 */ 	bgezl	$t7,.L0f105628
/*  f1055dc:	304b0004 */ 	andi	$t3,$v0,0x4
/*  f1055e0:	8c78029c */ 	lw	$t8,0x29c($v1)
/*  f1055e4:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f1055e8:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f1055ec:	0701000d */ 	bgez	$t8,.L0f105624
/*  f1055f0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1055f4:	0fc42539 */ 	jal	func0f1094e4
/*  f1055f8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1055fc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f105600:	14400004 */ 	bnez	$v0,.L0f105614
/*  f105604:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f105608:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f10560c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f105610:	ad190000 */ 	sw	$t9,0x0($t0)
.L0f105614:
/*  f105614:	8c690458 */ 	lw	$t1,0x458($v1)
/*  f105618:	2401fffe */ 	addiu	$at,$zero,-2
/*  f10561c:	01211024 */ 	and	$v0,$t1,$at
/*  f105620:	ac620458 */ 	sw	$v0,0x458($v1)
.L0f105624:
/*  f105624:	304b0004 */ 	andi	$t3,$v0,0x4
.L0f105628:
/*  f105628:	5160000a */ 	beqzl	$t3,.L0f105654
/*  f10562c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f105630:	0fc44270 */ 	jal	func0f1109c0
/*  f105634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105638:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10563c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f105640:	8c6c0458 */ 	lw	$t4,0x458($v1)
/*  f105644:	2401fffb */ 	addiu	$at,$zero,-5
/*  f105648:	01816824 */ 	and	$t5,$t4,$at
/*  f10564c:	ac6d0458 */ 	sw	$t5,0x458($v1)
.L0f105650:
/*  f105650:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f105654:
/*  f105654:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f105658:	00001025 */ 	or	$v0,$zero,$zero
/*  f10565c:	03e00008 */ 	jr	$ra
/*  f105660:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f105664
/*  f105664:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f105668:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10566c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f105670:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f105674:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f105678:	0fc40937 */ 	jal	menuhandler001024dc
/*  f10567c:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f105680:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f105684:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f105688:	0fc40937 */ 	jal	menuhandler001024dc
/*  f10568c:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f105690:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f105694:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f105698:	03e00008 */ 	jr	$ra
/*  f10569c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1056a0
/*  f1056a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1056a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1056a8:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1056ac:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f1056b0:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f1056b4:	0fc4093f */ 	jal	menuhandler001024fc
/*  f1056b8:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f1056bc:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f1056c0:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f1056c4:	0fc4093f */ 	jal	menuhandler001024fc
/*  f1056c8:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f1056cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1056d0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1056d4:	03e00008 */ 	jr	$ra
/*  f1056d8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerLangFilter(u32 operation, struct menu_item *item, u32 *enable)
{
	switch (operation) {
	case MENUOP_GET:
		return g_Vars.langFilterActive;
	case MENUOP_SET:
		g_Vars.langFilterActive = *enable;
		g_Vars.unk000458 |= 1;
	}

	return 0;
}

s32 menuhandlerControlStyle(s32 operation, struct menu_item *item, u32 *value)
{
	if (operation == MENUOP_SET) {
		if (PLAYERCOUNT() >= 2) {
			menuPushDialog(&g_ControlStyleMultiMenuDialog);
		} else {
			menuPushDialog(&g_ControlStyleSingleMenuDialog);
		}
	}

	return 0;
}

s32 menuhandler001057ec(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f1094e4(&var800a22c0, 2, 0);
	}

	return 0;
}

s32 menuhandlerChangeAgent(s32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(NULL, -7);
	}

	return 0;
}

char *func0f105864(s32 arg0)
{
	struct inventory_function *primaryfunc = weaponGetFunctionById(var800a21c0, 0);
	struct inventory_function *secondaryfunc = weaponGetFunctionById(var800a21c0, 1);

	if (primaryfunc && secondaryfunc) {
		return textGet(primaryfunc->name);
	}

	return textGet(0x5603); // "\n"
}

char *func0f1058d0(s32 arg0)
{
	struct inventory_function *primaryfunc = weaponGetFunctionById(var800a21c0, 0);
	struct inventory_function *secondaryfunc = weaponGetFunctionById(var800a21c0, 1);

	if (secondaryfunc) {
		return textGet(secondaryfunc->name);
	}

	if (primaryfunc) {
		return textGet(primaryfunc->name);
	}

	return textGet(0x5603); // "\n"
}

GLOBAL_ASM(
glabel func0f105948
/*  f105948:	27bdf988 */ 	addiu	$sp,$sp,-1656
/*  f10594c:	3c0f8007 */ 	lui	$t7,%hi(var80072d8c)
/*  f105950:	25ef2d8c */ 	addiu	$t7,$t7,%lo(var80072d8c)
/*  f105954:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f105958:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f10595c:	25ea0624 */ 	addiu	$t2,$t7,0x624
/*  f105960:	27ae004c */ 	addiu	$t6,$sp,0x4c
.L0f105964:
/*  f105964:	8de10000 */ 	lw	$at,0x0($t7)
/*  f105968:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f10596c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f105970:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f105974:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f105978:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f10597c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f105980:	15eafff8 */ 	bne	$t7,$t2,.L0f105964
/*  f105984:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f105988:	8de10000 */ 	lw	$at,0x0($t7)
/*  f10598c:	8dea0004 */ 	lw	$t2,0x4($t7)
/*  f105990:	2488fffe */ 	addiu	$t0,$a0,-2
/*  f105994:	adc10000 */ 	sw	$at,0x0($t6)
/*  f105998:	2901004f */ 	slti	$at,$t0,0x4f
/*  f10599c:	01004825 */ 	or	$t1,$t0,$zero
/*  f1059a0:	14200002 */ 	bnez	$at,.L0f1059ac
/*  f1059a4:	adca0004 */ 	sw	$t2,0x4($t6)
/*  f1059a8:	00004825 */ 	or	$t1,$zero,$zero
.L0f1059ac:
/*  f1059ac:	3c050004 */ 	lui	$a1,0x4
/*  f1059b0:	afa40678 */ 	sw	$a0,0x678($sp)
/*  f1059b4:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f1059b8:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f1059bc:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f1059c0:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f1059c4:	1440008f */ 	bnez	$v0,.L0f105c04
/*  f1059c8:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f1059cc:	0520008d */ 	bltz	$t1,.L0f105c04
/*  f1059d0:	8fa40678 */ 	lw	$a0,0x678($sp)
/*  f1059d4:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f1059d8:	0fc2c3f4 */ 	jal	weaponFindById
/*  f1059dc:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f1059e0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1059e4:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f1059e8:	3c0d800a */ 	lui	$t5,%hi(var8009e000)
/*  f1059ec:	25ade000 */ 	addiu	$t5,$t5,%lo(var8009e000)
/*  f1059f0:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1059f4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1059f8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1059fc:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f105a00:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f105a04:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f105a08:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f105a0c:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f105a10:	24190008 */ 	addiu	$t9,$zero,0x8
/*  f105a14:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f105a18:	a2190840 */ 	sb	$t9,0x840($s0)
/*  f105a1c:	ae000850 */ 	sw	$zero,0x850($s0)
/*  f105a20:	0fc2c686 */ 	jal	func0f0b1a18
/*  f105a24:	8fa40678 */ 	lw	$a0,0x678($sp)
/*  f105a28:	3c188007 */ 	lui	$t8,0x8007
/*  f105a2c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f105a30:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f105a34:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f105a38:	001850c0 */ 	sll	$t2,$t8,0x3
/*  f105a3c:	01585023 */ 	subu	$t2,$t2,$t8
/*  f105a40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f105a44:	01585021 */ 	addu	$t2,$t2,$t8
/*  f105a48:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f105a4c:	01585023 */ 	subu	$t2,$t2,$t8
/*  f105a50:	44800000 */ 	mtc1	$zero,$f0
/*  f105a54:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f105a58:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f105a5c:	014f8021 */ 	addu	$s0,$t2,$t7
/*  f105a60:	00097080 */ 	sll	$t6,$t1,0x2
/*  f105a64:	01c97021 */ 	addu	$t6,$t6,$t1
/*  f105a68:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f105a6c:	27ab004c */ 	addiu	$t3,$sp,0x4c
/*  f105a70:	01cb1821 */ 	addu	$v1,$t6,$t3
/*  f105a74:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f105a78:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f105a7c:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f105a80:	c462000c */ 	lwc1	$f2,0xc($v1)
/*  f105a84:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f105a88:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f105a8c:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f105a90:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f105a94:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f105a98:	44050000 */ 	mfc1	$a1,$f0
/*  f105a9c:	44060000 */ 	mfc1	$a2,$f0
/*  f105aa0:	44070000 */ 	mfc1	$a3,$f0
/*  f105aa4:	ae02084c */ 	sw	$v0,0x84c($s0)
/*  f105aa8:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f105aac:	26040840 */ 	addiu	$a0,$s0,0x840
/*  f105ab0:	e6000d78 */ 	swc1	$f0,0xd78($s0)
/*  f105ab4:	e6000d50 */ 	swc1	$f0,0xd50($s0)
/*  f105ab8:	e6000d7c */ 	swc1	$f0,0xd7c($s0)
/*  f105abc:	e6000d54 */ 	swc1	$f0,0xd54($s0)
/*  f105ac0:	e6000d80 */ 	swc1	$f0,0xd80($s0)
/*  f105ac4:	e6000d58 */ 	swc1	$f0,0xd58($s0)
/*  f105ac8:	e6000d90 */ 	swc1	$f0,0xd90($s0)
/*  f105acc:	e6000d68 */ 	swc1	$f0,0xd68($s0)
/*  f105ad0:	e6040d6c */ 	swc1	$f4,0xd6c($s0)
/*  f105ad4:	e6060d70 */ 	swc1	$f6,0xd70($s0)
/*  f105ad8:	e6080d74 */ 	swc1	$f8,0xd74($s0)
/*  f105adc:	e6020d88 */ 	swc1	$f2,0xd88($s0)
/*  f105ae0:	e6020d60 */ 	swc1	$f2,0xd60($s0)
/*  f105ae4:	0fc3cdcb */ 	jal	func0f0f372c
/*  f105ae8:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f105aec:	3c0d8007 */ 	lui	$t5,0x8007
/*  f105af0:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f105af4:	44800000 */ 	mtc1	$zero,$f0
/*  f105af8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f105afc:	000dc8c0 */ 	sll	$t9,$t5,0x3
/*  f105b00:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f105b04:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f105b08:	032dc821 */ 	addu	$t9,$t9,$t5
/*  f105b0c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f105b10:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f105b14:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f105b18:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f105b1c:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f105b20:	03388021 */ 	addu	$s0,$t9,$t8
/*  f105b24:	3c01bf80 */ 	lui	$at,0xbf80
/*  f105b28:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f105b2c:	44818000 */ 	mtc1	$at,$f16
/*  f105b30:	e6000d5c */ 	swc1	$f0,0xd5c($s0)
/*  f105b34:	8d4f0040 */ 	lw	$t7,0x40($t2)
/*  f105b38:	2401003e */ 	addiu	$at,$zero,0x3e
/*  f105b3c:	e6100d94 */ 	swc1	$f16,0xd94($s0)
/*  f105b40:	11010003 */ 	beq	$t0,$at,.L0f105b50
/*  f105b44:	ae0f0df4 */ 	sw	$t7,0xdf4($s0)
/*  f105b48:	2401003f */ 	addiu	$at,$zero,0x3f
/*  f105b4c:	1501003c */ 	bne	$t0,$at,.L0f105c40
.L0f105b50:
/*  f105b50:	2401003e */ 	addiu	$at,$zero,0x3e
/*  f105b54:	15010005 */ 	bne	$t0,$at,.L0f105b6c
/*  f105b58:	26040840 */ 	addiu	$a0,$s0,0x840
/*  f105b5c:	3c0e0a01 */ 	lui	$t6,0xa01
/*  f105b60:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f105b64:	10000004 */ 	beqz	$zero,.L0f105b78
/*  f105b68:	ae0e084c */ 	sw	$t6,0x84c($s0)
.L0f105b6c:
/*  f105b6c:	3c0b0400 */ 	lui	$t3,0x400
/*  f105b70:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f105b74:	ae0b084c */ 	sw	$t3,0x84c($s0)
.L0f105b78:
/*  f105b78:	3c013f80 */ 	lui	$at,0x3f80
/*  f105b7c:	44819000 */ 	mtc1	$at,$f18
/*  f105b80:	44050000 */ 	mfc1	$a1,$f0
/*  f105b84:	44060000 */ 	mfc1	$a2,$f0
/*  f105b88:	44070000 */ 	mfc1	$a3,$f0
/*  f105b8c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f105b90:	ae000df4 */ 	sw	$zero,0xdf4($s0)
/*  f105b94:	ae000dc0 */ 	sw	$zero,0xdc0($s0)
/*  f105b98:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f105b9c:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f105ba0:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f105ba4:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f105ba8:	0fc3cdcb */ 	jal	func0f0f372c
/*  f105bac:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f105bb0:	3c0d8007 */ 	lui	$t5,0x8007
/*  f105bb4:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f105bb8:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f105bbc:	3c017f1b */ 	lui	$at,%hi(var7f1b2e00)
/*  f105bc0:	000dc8c0 */ 	sll	$t9,$t5,0x3
/*  f105bc4:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f105bc8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f105bcc:	032dc821 */ 	addu	$t9,$t9,$t5
/*  f105bd0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f105bd4:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f105bd8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f105bdc:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f105be0:	c4202e00 */ 	lwc1	$f0,%lo(var7f1b2e00)($at)
/*  f105be4:	03388021 */ 	addu	$s0,$t9,$t8
/*  f105be8:	240a003c */ 	addiu	$t2,$zero,0x3c
/*  f105bec:	240f0078 */ 	addiu	$t7,$zero,0x78
/*  f105bf0:	ae0a0db8 */ 	sw	$t2,0xdb8($s0)
/*  f105bf4:	ae0f0db4 */ 	sw	$t7,0xdb4($s0)
/*  f105bf8:	e6000d8c */ 	swc1	$f0,0xd8c($s0)
/*  f105bfc:	10000010 */ 	beqz	$zero,.L0f105c40
/*  f105c00:	e6000d64 */ 	swc1	$f0,0xd64($s0)
.L0f105c04:
/*  f105c04:	3c0e8007 */ 	lui	$t6,0x8007
/*  f105c08:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f105c0c:	3c0c800a */ 	lui	$t4,%hi(var8009e000)
/*  f105c10:	258ce000 */ 	addiu	$t4,$t4,%lo(var8009e000)
/*  f105c14:	000e58c0 */ 	sll	$t3,$t6,0x3
/*  f105c18:	016e5823 */ 	subu	$t3,$t3,$t6
/*  f105c1c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f105c20:	016e5821 */ 	addu	$t3,$t3,$t6
/*  f105c24:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f105c28:	016e5823 */ 	subu	$t3,$t3,$t6
/*  f105c2c:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f105c30:	016c8021 */ 	addu	$s0,$t3,$t4
/*  f105c34:	ae000894 */ 	sw	$zero,0x894($s0)
/*  f105c38:	ae000850 */ 	sw	$zero,0x850($s0)
/*  f105c3c:	ae00084c */ 	sw	$zero,0x84c($s0)
.L0f105c40:
/*  f105c40:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f105c44:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f105c48:	27bd0678 */ 	addiu	$sp,$sp,0x678
/*  f105c4c:	03e00008 */ 	jr	$ra
/*  f105c50:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog00105c54
/*  f105c54:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f105c58:	24010066 */ 	addiu	$at,$zero,0x66
/*  f105c5c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f105c60:	14810049 */ 	bne	$a0,$at,.L0f105d88
/*  f105c64:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f105c68:	3c0e8007 */ 	lui	$t6,0x8007
/*  f105c6c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f105c70:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f105c74:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f105c78:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f105c7c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f105c80:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f105c84:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f105c88:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f105c8c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f105c90:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f105c94:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f105c98:	8c4304f8 */ 	lw	$v1,0x4f8($v0)
/*  f105c9c:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f105ca0:	3c018007 */ 	lui	$at,0x8007
/*  f105ca4:	10600037 */ 	beqz	$v1,.L0f105d84
/*  f105ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105cac:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f105cb0:	3c09800a */ 	lui	$t1,0x800a
/*  f105cb4:	14b90033 */ 	bne	$a1,$t9,.L0f105d84
/*  f105cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105cbc:	8c480db4 */ 	lw	$t0,0xdb4($v0)
/*  f105cc0:	8d299fc0 */ 	lw	$t1,-0x6040($t1)
/*  f105cc4:	3c017f1b */ 	lui	$at,%hi(var7f1b2e04)
/*  f105cc8:	44801000 */ 	mtc1	$zero,$f2
/*  f105ccc:	01095023 */ 	subu	$t2,$t0,$t1
/*  f105cd0:	ac4a0db4 */ 	sw	$t2,0xdb4($v0)
/*  f105cd4:	c4242e04 */ 	lwc1	$f4,%lo(var7f1b2e04)($at)
/*  f105cd8:	3c018006 */ 	lui	$at,0x8006
/*  f105cdc:	c4261630 */ 	lwc1	$f6,0x1630($at)
/*  f105ce0:	e4420d68 */ 	swc1	$f2,0xd68($v0)
/*  f105ce4:	e4420d90 */ 	swc1	$f2,0xd90($v0)
/*  f105ce8:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f105cec:	3c04800a */ 	lui	$a0,0x800a
/*  f105cf0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f105cf4:	e4400d8c */ 	swc1	$f0,0xd8c($v0)
/*  f105cf8:	e4400d64 */ 	swc1	$f0,0xd64($v0)
/*  f105cfc:	916b2d88 */ 	lbu	$t3,0x2d88($t3)
/*  f105d00:	908421c0 */ 	lbu	$a0,0x21c0($a0)
/*  f105d04:	508b0008 */ 	beql	$a0,$t3,.L0f105d28
/*  f105d08:	24010040 */ 	addiu	$at,$zero,0x40
/*  f105d0c:	0fc41652 */ 	jal	func0f105948
/*  f105d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105d14:	3c02800a */ 	lui	$v0,0x800a
/*  f105d18:	904421c0 */ 	lbu	$a0,0x21c0($v0)
/*  f105d1c:	3c018007 */ 	lui	$at,0x8007
/*  f105d20:	a0242d88 */ 	sb	$a0,0x2d88($at)
/*  f105d24:	24010040 */ 	addiu	$at,$zero,0x40
.L0f105d28:
/*  f105d28:	10810004 */ 	beq	$a0,$at,.L0f105d3c
/*  f105d2c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f105d30:	24010041 */ 	addiu	$at,$zero,0x41
/*  f105d34:	54810015 */ 	bnel	$a0,$at,.L0f105d8c
/*  f105d38:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f105d3c:
/*  f105d3c:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f105d40:	3c0e800a */ 	lui	$t6,%hi(var8009e000)
/*  f105d44:	25cee000 */ 	addiu	$t6,$t6,%lo(var8009e000)
/*  f105d48:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f105d4c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f105d50:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f105d54:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f105d58:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f105d5c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f105d60:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f105d64:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f105d68:	240f006a */ 	addiu	$t7,$zero,0x6a
/*  f105d6c:	2418003c */ 	addiu	$t8,$zero,0x3c
/*  f105d70:	24190078 */ 	addiu	$t9,$zero,0x78
/*  f105d74:	a44f089c */ 	sh	$t7,0x89c($v0)
/*  f105d78:	ac580db8 */ 	sw	$t8,0xdb8($v0)
/*  f105d7c:	10000002 */ 	beqz	$zero,.L0f105d88
/*  f105d80:	ac590db4 */ 	sw	$t9,0xdb4($v0)
.L0f105d84:
/*  f105d84:	a0282d88 */ 	sb	$t0,0x2d88($at)
.L0f105d88:
/*  f105d88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f105d8c:
/*  f105d8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f105d90:	00001025 */ 	or	$v0,$zero,$zero
/*  f105d94:	03e00008 */ 	jr	$ra
/*  f105d98:	00000000 */ 	sll	$zero,$zero,0x0
);

char *func0f105d9c(s32 arg0)
{
	struct weapon *weapon = weaponFindById(var800a21c0);

	if (weapon) {
		if (weapon->manufacturer == 0x4c00) { // "\n"
			return textGet(0x5603); // "\n"
		}

		return textGet(weapon->name);
	}

	return textGet(0x5603); // "\n"
}

/**
 * Return manufacturer, with fallback to weapon name if manufacturer is blank.
 */
char *func0f105e04(s32 arg0)
{
	struct weapon *weapon = weaponFindById(var800a21c0);
	u32 textid = 0x4c00; // "\n"

	if (weapon) {
		textid = weapon->manufacturer;
	}

	if (textid != 0x4c00) {
		return textGet(textid);
	}

	weapon = weaponFindById(var800a21c0);

	if (weapon) {
		return textGet(weapon->name);
	}

	return textGet(0x5603); // "\n"
}

GLOBAL_ASM(
glabel func0f105e80
/*  f105e80:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f105e84:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f105e88:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f105e8c:	3c04800a */ 	lui	$a0,0x800a
/*  f105e90:	0fc2c3f4 */ 	jal	weaponFindById
/*  f105e94:	908421c0 */ 	lbu	$a0,0x21c0($a0)
/*  f105e98:	1040005d */ 	beqz	$v0,.L0f106010
/*  f105e9c:	00402825 */ 	or	$a1,$v0,$zero
/*  f105ea0:	3c02800a */ 	lui	$v0,0x800a
/*  f105ea4:	904221c0 */ 	lbu	$v0,0x21c0($v0)
/*  f105ea8:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f105eac:	3c0e800a */ 	lui	$t6,0x800a
/*  f105eb0:	54410015 */ 	bnel	$v0,$at,.L0f105f08
/*  f105eb4:	24010050 */ 	addiu	$at,$zero,0x50
/*  f105eb8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f105ebc:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f105ec0:	50600011 */ 	beqzl	$v1,.L0f105f08
/*  f105ec4:	24010050 */ 	addiu	$at,$zero,0x50
/*  f105ec8:	9064006b */ 	lbu	$a0,0x6b($v1)
/*  f105ecc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f105ed0:	54810006 */ 	bnel	$a0,$at,.L0f105eec
/*  f105ed4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f105ed8:	0fc5b9f1 */ 	jal	textGet
/*  f105edc:	24044ced */ 	addiu	$a0,$zero,0x4ced
/*  f105ee0:	1000004e */ 	beqz	$zero,.L0f10601c
/*  f105ee4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f105ee8:	24010002 */ 	addiu	$at,$zero,0x2
.L0f105eec:
/*  f105eec:	54810006 */ 	bnel	$a0,$at,.L0f105f08
/*  f105ef0:	24010050 */ 	addiu	$at,$zero,0x50
/*  f105ef4:	0fc5b9f1 */ 	jal	textGet
/*  f105ef8:	24044cec */ 	addiu	$a0,$zero,0x4cec
/*  f105efc:	10000047 */ 	beqz	$zero,.L0f10601c
/*  f105f00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f105f04:	24010050 */ 	addiu	$at,$zero,0x50
.L0f105f08:
/*  f105f08:	1441003d */ 	bne	$v0,$at,.L0f106000
/*  f105f0c:	3c0f800a */ 	lui	$t7,0x800a
/*  f105f10:	8defa474 */ 	lw	$t7,-0x5b8c($t7)
/*  f105f14:	24010034 */ 	addiu	$at,$zero,0x34
/*  f105f18:	15e10039 */ 	bne	$t7,$at,.L0f106000
/*  f105f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f105f20:	0fc5b367 */ 	jal	getDifficulty
/*  f105f24:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f105f28:	28410002 */ 	slti	$at,$v0,0x2
/*  f105f2c:	14200034 */ 	bnez	$at,.L0f106000
/*  f105f30:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f105f34:	3c198007 */ 	lui	$t9,%hi(var800733b8)
/*  f105f38:	273933b8 */ 	addiu	$t9,$t9,%lo(var800733b8)
/*  f105f3c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f105f40:	27b80040 */ 	addiu	$t8,$sp,0x40
/*  f105f44:	8f290004 */ 	lw	$t1,0x4($t9)
/*  f105f48:	af010000 */ 	sw	$at,0x0($t8)
/*  f105f4c:	97210008 */ 	lhu	$at,0x8($t9)
/*  f105f50:	3c0b8007 */ 	lui	$t3,%hi(var800733c4)
/*  f105f54:	256b33c4 */ 	addiu	$t3,$t3,%lo(var800733c4)
/*  f105f58:	af090004 */ 	sw	$t1,0x4($t8)
/*  f105f5c:	a7010008 */ 	sh	$at,0x8($t8)
/*  f105f60:	8d610000 */ 	lw	$at,0x0($t3)
/*  f105f64:	27aa0030 */ 	addiu	$t2,$sp,0x30
/*  f105f68:	8d6d0004 */ 	lw	$t5,0x4($t3)
/*  f105f6c:	ad410000 */ 	sw	$at,0x0($t2)
/*  f105f70:	8d610008 */ 	lw	$at,0x8($t3)
/*  f105f74:	27a20040 */ 	addiu	$v0,$sp,0x40
/*  f105f78:	00001825 */ 	or	$v1,$zero,$zero
/*  f105f7c:	ad410008 */ 	sw	$at,0x8($t2)
/*  f105f80:	9561000c */ 	lhu	$at,0xc($t3)
/*  f105f84:	24040038 */ 	addiu	$a0,$zero,0x38
/*  f105f88:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f105f8c:	a541000c */ 	sh	$at,0xc($t2)
.L0f105f90:
/*  f105f90:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f105f94:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f105f98:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f105f9c:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f105fa0:	2861005a */ 	slti	$at,$v1,0x5a
/*  f105fa4:	25e8fff7 */ 	addiu	$t0,$t7,-9
/*  f105fa8:	1420fff9 */ 	bnez	$at,.L0f105f90
/*  f105fac:	a048ffff */ 	sb	$t0,-0x1($v0)
/*  f105fb0:	27a20030 */ 	addiu	$v0,$sp,0x30
/*  f105fb4:	00001825 */ 	or	$v1,$zero,$zero
.L0f105fb8:
/*  f105fb8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f105fbc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f105fc0:	0303c823 */ 	subu	$t9,$t8,$v1
/*  f105fc4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f105fc8:	2729fffc */ 	addiu	$t1,$t9,-4
/*  f105fcc:	1464fffa */ 	bne	$v1,$a0,.L0f105fb8
/*  f105fd0:	a049ffff */ 	sb	$t1,-0x1($v0)
/*  f105fd4:	0fc5b9f1 */ 	jal	textGet
/*  f105fd8:	24044cef */ 	addiu	$a0,$zero,0x4cef
/*  f105fdc:	3c048007 */ 	lui	$a0,0x8007
/*  f105fe0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f105fe4:	00402825 */ 	or	$a1,$v0,$zero
/*  f105fe8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f105fec:	0c004dad */ 	jal	sprintf
/*  f105ff0:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f105ff4:	3c028007 */ 	lui	$v0,0x8007
/*  f105ff8:	10000007 */ 	beqz	$zero,.L0f106018
/*  f105ffc:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f106000:
/*  f106000:	0fc5b9f1 */ 	jal	textGet
/*  f106004:	94a4004a */ 	lhu	$a0,0x4a($a1)
/*  f106008:	10000004 */ 	beqz	$zero,.L0f10601c
/*  f10600c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f106010:
/*  f106010:	0fc5b9f1 */ 	jal	textGet
/*  f106014:	24045603 */ 	addiu	$a0,$zero,0x5603
.L0f106018:
/*  f106018:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10601c:
/*  f10601c:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f106020:	03e00008 */ 	jr	$ra
/*  f106024:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler00106028
/*  f106028:	248effff */ 	addiu	$t6,$a0,-1
/*  f10602c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f106030:	2dc10010 */ 	sltiu	$at,$t6,0x10
/*  f106034:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106038:	1020004a */ 	beqz	$at,.L0f106164
/*  f10603c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f106040:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f106044:	3c017f1b */ 	lui	$at,%hi(var7f1b2e08)
/*  f106048:	002e0821 */ 	addu	$at,$at,$t6
/*  f10604c:	8c2e2e08 */ 	lw	$t6,%lo(var7f1b2e08)($at)
/*  f106050:	01c00008 */ 	jr	$t6
/*  f106054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106058:	10000042 */ 	beqz	$zero,.L0f106164
/*  f10605c:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f106060:	10000041 */ 	beqz	$zero,.L0f106168
/*  f106064:	00001025 */ 	or	$v0,$zero,$zero
/*  f106068:	1000003e */ 	beqz	$zero,.L0f106164
/*  f10606c:	acc00008 */ 	sw	$zero,0x8($a2)
/*  f106070:	0fc674b8 */ 	jal	func0f19d2e0
/*  f106074:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f106078:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f10607c:	10000039 */ 	beqz	$zero,.L0f106164
/*  f106080:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f106084:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f106088:	3c018007 */ 	lui	$at,0x8007
/*  f10608c:	0fc6749a */ 	jal	func0f19d268
/*  f106090:	a0243544 */ 	sb	$a0,0x3544($at)
/*  f106094:	0fc28857 */ 	jal	func0f0a215c
/*  f106098:	00402025 */ 	or	$a0,$v0,$zero
/*  f10609c:	10000033 */ 	beqz	$zero,.L0f10616c
/*  f1060a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1060a4:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1060a8:	3c018007 */ 	lui	$at,0x8007
/*  f1060ac:	00001025 */ 	or	$v0,$zero,$zero
/*  f1060b0:	1000002d */ 	beqz	$zero,.L0f106168
/*  f1060b4:	a02f3544 */ 	sb	$t7,0x3544($at)
/*  f1060b8:	3c188007 */ 	lui	$t8,0x8007
/*  f1060bc:	93183544 */ 	lbu	$t8,0x3544($t8)
/*  f1060c0:	10000028 */ 	beqz	$zero,.L0f106164
/*  f1060c4:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f1060c8:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f1060cc:	0fc6749a */ 	jal	func0f19d268
/*  f1060d0:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1060d4:	3c03800a */ 	lui	$v1,%hi(var800a21c0)
/*  f1060d8:	246321c0 */ 	addiu	$v1,$v1,%lo(var800a21c0)
/*  f1060dc:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f1060e0:	3c088007 */ 	lui	$t0,0x8007
/*  f1060e4:	8d081448 */ 	lw	$t0,0x1448($t0)
/*  f1060e8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f1060ec:	3c01800a */ 	lui	$at,0x800a
/*  f1060f0:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1060f4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1060f8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1060fc:	01284821 */ 	addu	$t1,$t1,$t0
/*  f106100:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f106104:	01284823 */ 	subu	$t1,$t1,$t0
/*  f106108:	00094900 */ 	sll	$t1,$t1,0x4
/*  f10610c:	00290821 */ 	addu	$at,$at,$t1
/*  f106110:	305900ff */ 	andi	$t9,$v0,0xff
/*  f106114:	ac39ee28 */ 	sw	$t9,-0x11d8($at)
/*  f106118:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f10611c:	3c018007 */ 	lui	$at,0x8007
/*  f106120:	3c048007 */ 	lui	$a0,0x8007
/*  f106124:	248433e8 */ 	addiu	$a0,$a0,0x33e8
/*  f106128:	3c05bf80 */ 	lui	$a1,0xbf80
/*  f10612c:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f106130:	a02a3544 */ 	sb	$t2,0x3544($at)
/*  f106134:	3c048007 */ 	lui	$a0,0x8007
/*  f106138:	248433fc */ 	addiu	$a0,$a0,0x33fc
/*  f10613c:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f106140:	3c05bf80 */ 	lui	$a1,0xbf80
/*  f106144:	3c048007 */ 	lui	$a0,0x8007
/*  f106148:	24843424 */ 	addiu	$a0,$a0,0x3424
/*  f10614c:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f106150:	3c05bf80 */ 	lui	$a1,0xbf80
/*  f106154:	3c048007 */ 	lui	$a0,0x8007
/*  f106158:	24843438 */ 	addiu	$a0,$a0,0x3438
/*  f10615c:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f106160:	3c05bf80 */ 	lui	$a1,0xbf80
.L0f106164:
/*  f106164:	00001025 */ 	or	$v0,$zero,$zero
.L0f106168:
/*  f106168:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10616c:
/*  f10616c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f106170:	03e00008 */ 	jr	$ra
/*  f106174:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler00106178
/*  f106178:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10617c:	248effff */ 	addiu	$t6,$a0,-1
/*  f106180:	2dc10010 */ 	sltiu	$at,$t6,0x10
/*  f106184:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106188:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f10618c:	1020007c */ 	beqz	$at,.L0f106380
/*  f106190:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f106194:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f106198:	3c017f1b */ 	lui	$at,%hi(var7f1b2e48)
/*  f10619c:	002e0821 */ 	addu	$at,$at,$t6
/*  f1061a0:	8c2e2e48 */ 	lw	$t6,%lo(var7f1b2e48)($at)
/*  f1061a4:	01c00008 */ 	jr	$t6
/*  f1061a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1061ac:	0fc44a54 */ 	jal	func0f112950
/*  f1061b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1061b4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f1061b8:	10000071 */ 	beqz	$zero,.L0f106380
/*  f1061bc:	ade20000 */ 	sw	$v0,0x0($t7)
/*  f1061c0:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f1061c4:	0fc44b7f */ 	jal	func0f112dfc
/*  f1061c8:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f1061cc:	1000006e */ 	beqz	$zero,.L0f106388
/*  f1061d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1061d4:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f1061d8:	0fc44b11 */ 	jal	func0f112c44
/*  f1061dc:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f1061e0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1061e4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1061e8:	10400014 */ 	beqz	$v0,.L0f10623c
/*  f1061ec:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f1061f0:	0fc2c62f */ 	jal	currentPlayerHasWeaponEquipped
/*  f1061f4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1061f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1061fc:	50410010 */ 	beql	$v0,$at,.L0f106240
/*  f106200:	8fab0018 */ 	lw	$t3,0x18($sp)
/*  f106204:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f106208:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f10620c:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f106210:	5540000b */ 	bnezl	$t2,.L0f106240
/*  f106214:	8fab0018 */ 	lw	$t3,0x18($sp)
/*  f106218:	14400006 */ 	bnez	$v0,.L0f106234
/*  f10621c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f106220:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f106224:	0fc2c652 */ 	jal	func0f0b1948
/*  f106228:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10622c:	10000004 */ 	beqz	$zero,.L0f106240
/*  f106230:	8fab0018 */ 	lw	$t3,0x18($sp)
.L0f106234:
/*  f106234:	0fc2c652 */ 	jal	func0f0b1948
/*  f106238:	00002825 */ 	or	$a1,$zero,$zero
.L0f10623c:
/*  f10623c:	8fab0018 */ 	lw	$t3,0x18($sp)
.L0f106240:
/*  f106240:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f106244:	51600016 */ 	beqzl	$t3,.L0f1062a0
/*  f106248:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f10624c:	0fc44bd8 */ 	jal	func0f112f60
/*  f106250:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f106254:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f106258:	0fc4473e */ 	jal	func0f111cf8
/*  f10625c:	00802825 */ 	or	$a1,$a0,$zero
/*  f106260:	10400009 */ 	beqz	$v0,.L0f106288
/*  f106264:	00002025 */ 	or	$a0,$zero,$zero
/*  f106268:	00002025 */ 	or	$a0,$zero,$zero
/*  f10626c:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f106270:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f106274:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f106278:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f10627c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f106280:	10000007 */ 	beqz	$zero,.L0f1062a0
/*  f106284:	8fad0028 */ 	lw	$t5,0x28($sp)
.L0f106288:
/*  f106288:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f10628c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f106290:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f106294:	0fc28824 */ 	jal	currentPlayerEquipWeapon
/*  f106298:	00002825 */ 	or	$a1,$zero,$zero
/*  f10629c:	8fad0028 */ 	lw	$t5,0x28($sp)
.L0f1062a0:
/*  f1062a0:	3c018007 */ 	lui	$at,0x8007
/*  f1062a4:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f1062a8:	10000035 */ 	beqz	$zero,.L0f106380
/*  f1062ac:	ac2e11f0 */ 	sw	$t6,0x11f0($at)
/*  f1062b0:	0fc44bd4 */ 	jal	func0f112f50
/*  f1062b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1062b8:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f1062bc:	10000030 */ 	beqz	$zero,.L0f106380
/*  f1062c0:	ade20000 */ 	sw	$v0,0x0($t7)
/*  f1062c4:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f1062c8:	0fc44b11 */ 	jal	func0f112c44
/*  f1062cc:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f1062d0:	1040002b */ 	beqz	$v0,.L0f106380
/*  f1062d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1062d8:	0fc2c62f */ 	jal	currentPlayerHasWeaponEquipped
/*  f1062dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1062e0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1062e4:	10410026 */ 	beq	$v0,$at,.L0f106380
/*  f1062e8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f1062ec:	10000024 */ 	beqz	$zero,.L0f106380
/*  f1062f0:	af220004 */ 	sw	$v0,0x4($t9)
/*  f1062f4:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f1062f8:	0fc44b11 */ 	jal	func0f112c44
/*  f1062fc:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f106300:	3c03800a */ 	lui	$v1,%hi(var800a21c0)
/*  f106304:	246321c0 */ 	addiu	$v1,$v1,%lo(var800a21c0)
/*  f106308:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f10630c:	3c0a8007 */ 	lui	$t2,0x8007
/*  f106310:	8d4a1448 */ 	lw	$t2,0x1448($t2)
/*  f106314:	3c01800a */ 	lui	$at,0x800a
/*  f106318:	304900ff */ 	andi	$t1,$v0,0xff
/*  f10631c:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f106320:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f106324:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f106328:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f10632c:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f106330:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f106334:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f106338:	002b0821 */ 	addu	$at,$at,$t3
/*  f10633c:	3c048007 */ 	lui	$a0,0x8007
/*  f106340:	ac29ee28 */ 	sw	$t1,-0x11d8($at)
/*  f106344:	248433e8 */ 	addiu	$a0,$a0,0x33e8
/*  f106348:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f10634c:	3c05bf80 */ 	lui	$a1,0xbf80
/*  f106350:	3c048007 */ 	lui	$a0,0x8007
/*  f106354:	248433fc */ 	addiu	$a0,$a0,0x33fc
/*  f106358:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f10635c:	3c05bf80 */ 	lui	$a1,0xbf80
/*  f106360:	3c048007 */ 	lui	$a0,0x8007
/*  f106364:	24843424 */ 	addiu	$a0,$a0,0x3424
/*  f106368:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f10636c:	3c05bf80 */ 	lui	$a1,0xbf80
/*  f106370:	3c048007 */ 	lui	$a0,0x8007
/*  f106374:	24843438 */ 	addiu	$a0,$a0,0x3438
/*  f106378:	0fc3c4e7 */ 	jal	func0f0f139c
/*  f10637c:	3c05bf80 */ 	lui	$a1,0xbf80
.L0f106380:
/*  f106380:	00001025 */ 	or	$v0,$zero,$zero
/*  f106384:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f106388:
/*  f106388:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10638c:	03e00008 */ 	jr	$ra
/*  f106390:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerAbortMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_Vars.currentplayer->aborted = true;
		func0000e684();
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog001063d4
/*  f1063d4:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f1063d8:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f1063dc:	03e00008 */ 	jr	$ra
/*  f1063e0:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel menudialog001063e4
/*  f1063e4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1063e8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1063ec:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1063f0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1063f4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1063f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1063fc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f106400:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f106404:	14810038 */ 	bne	$a0,$at,.L0f1064e8
/*  f106408:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f10640c:	3c10800a */ 	lui	$s0,0x800a
/*  f106410:	8e10d0b4 */ 	lw	$s0,-0x2f4c($s0)
/*  f106414:	0fc5b367 */ 	jal	getDifficulty
/*  f106418:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f10641c:	14400002 */ 	bnez	$v0,.L0f106428
/*  f106420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106424:	24110003 */ 	addiu	$s1,$zero,0x3
.L0f106428:
/*  f106428:	0fc5b367 */ 	jal	getDifficulty
/*  f10642c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106430:	24010001 */ 	addiu	$at,$zero,0x1
/*  f106434:	14410002 */ 	bne	$v0,$at,.L0f106440
/*  f106438:	3c13800a */ 	lui	$s3,%hi(var8009dfc8)
/*  f10643c:	24110002 */ 	addiu	$s1,$zero,0x2
.L0f106440:
/*  f106440:	2673dfc8 */ 	addiu	$s3,$s3,%lo(var8009dfc8)
/*  f106444:	240e582a */ 	addiu	$t6,$zero,0x582a
/*  f106448:	12000010 */ 	beqz	$s0,.L0f10648c
/*  f10644c:	a66e0000 */ 	sh	$t6,0x0($s3)
/*  f106450:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f106454:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f106458:
/*  f106458:	14620004 */ 	bne	$v1,$v0,.L0f10646c
/*  f10645c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106460:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f106464:	a66f0000 */ 	sh	$t7,0x0($s3)
/*  f106468:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f10646c:
/*  f10646c:	56220005 */ 	bnel	$s1,$v0,.L0f106484
/*  f106470:	8e10000c */ 	lw	$s0,0xc($s0)
/*  f106474:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f106478:	10000004 */ 	beqz	$zero,.L0f10648c
/*  f10647c:	a6780000 */ 	sh	$t8,0x0($s3)
/*  f106480:	8e10000c */ 	lw	$s0,0xc($s0)
.L0f106484:
/*  f106484:	5600fff4 */ 	bnezl	$s0,.L0f106458
/*  f106488:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f10648c:
/*  f10648c:	0fc2557d */ 	jal	objectiveGetCount
/*  f106490:	00008025 */ 	or	$s0,$zero,$zero
/*  f106494:	18400014 */ 	blez	$v0,.L0f1064e8
/*  f106498:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f10649c:	3c08800a */ 	lui	$t0,%hi(var8009d060)
/*  f1064a0:	2508d060 */ 	addiu	$t0,$t0,%lo(var8009d060)
/*  f1064a4:	03289021 */ 	addu	$s2,$t9,$t0
/*  f1064a8:	8e420000 */ 	lw	$v0,0x0($s2)
.L0f1064ac:
/*  f1064ac:	00104840 */ 	sll	$t1,$s0,0x1
/*  f1064b0:	02698821 */ 	addu	$s1,$s3,$t1
/*  f1064b4:	50400007 */ 	beqzl	$v0,.L0f1064d4
/*  f1064b8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1064bc:	8c4a0008 */ 	lw	$t2,0x8($v0)
/*  f1064c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1064c4:	0fc25594 */ 	jal	objectiveGetDifficultyBits
/*  f1064c8:	a62a0002 */ 	sh	$t2,0x2($s1)
/*  f1064cc:	a622000e */ 	sh	$v0,0xe($s1)
/*  f1064d0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1064d4:
/*  f1064d4:	0fc2557d */ 	jal	objectiveGetCount
/*  f1064d8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f1064dc:	0202082a */ 	slt	$at,$s0,$v0
/*  f1064e0:	5420fff2 */ 	bnezl	$at,.L0f1064ac
/*  f1064e4:	8e420000 */ 	lw	$v0,0x0($s2)
.L0f1064e8:
/*  f1064e8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1064ec:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1064f0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1064f4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1064f8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1064fc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f106500:	03e00008 */ 	jr	$ra
/*  f106504:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f106508
/*  f106508:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10650c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f106510:	3c18800a */ 	lui	$t8,0x800a
/*  f106514:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f106518:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10651c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f106520:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f106524:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f106528:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10652c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f106530:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f106534:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f106538:	8f18e4f8 */ 	lw	$t8,-0x1b08($t8)
/*  f10653c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106540:	3c08800a */ 	lui	$t0,0x800a
/*  f106544:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f106548:	10990005 */ 	beq	$a0,$t9,.L0f106560
/*  f10654c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106550:	0fc5b9f1 */ 	jal	textGet
/*  f106554:	240456ac */ 	addiu	$a0,$zero,0x56ac
/*  f106558:	10000016 */ 	beqz	$zero,.L0f1065b4
/*  f10655c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f106560:
/*  f106560:	9108dfea */ 	lbu	$t0,-0x2016($t0)
/*  f106564:	3c048007 */ 	lui	$a0,0x8007
/*  f106568:	00084880 */ 	sll	$t1,$t0,0x2
/*  f10656c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f106570:	00094880 */ 	sll	$t1,$t1,0x2
/*  f106574:	00892021 */ 	addu	$a0,$a0,$t1
/*  f106578:	0fc5b9f1 */ 	jal	textGet
/*  f10657c:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f106580:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f106584:	0fc5b9f1 */ 	jal	textGet
/*  f106588:	240456ac */ 	addiu	$a0,$zero,0x56ac
/*  f10658c:	3c048007 */ 	lui	$a0,0x8007
/*  f106590:	3c057f1b */ 	lui	$a1,%hi(var7f1b2d54)
/*  f106594:	24a52d54 */ 	addiu	$a1,$a1,%lo(var7f1b2d54)
/*  f106598:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10659c:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f1065a0:	0c004dad */ 	jal	sprintf
/*  f1065a4:	00403825 */ 	or	$a3,$v0,$zero
/*  f1065a8:	3c028007 */ 	lui	$v0,0x8007
/*  f1065ac:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f1065b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1065b4:
/*  f1065b4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1065b8:	03e00008 */ 	jr	$ra
/*  f1065bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1065c0
/*  f1065c0:	3c06800a */ 	lui	$a2,0x800a
/*  f1065c4:	3c08800a */ 	lui	$t0,0x800a
/*  f1065c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f1065cc:	25082200 */ 	addiu	$t0,$t0,0x2200
/*  f1065d0:	24c62200 */ 	addiu	$a2,$a2,0x2200
/*  f1065d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1065d8:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f1065dc:	24090011 */ 	addiu	$t1,$zero,0x11
.L0f1065e0:
/*  f1065e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1065e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1065e8:	00c03825 */ 	or	$a3,$a2,$zero
.L0f1065ec:
/*  f1065ec:	94ee0020 */ 	lhu	$t6,0x20($a3)
/*  f1065f0:	00057880 */ 	sll	$t7,$a1,0x2
/*  f1065f4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1065f8:	15c00007 */ 	bnez	$t6,.L0f106618
/*  f1065fc:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f106600:	8f1900a0 */ 	lw	$t9,0xa0($t8)
/*  f106604:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f106608:	004b6004 */ 	sllv	$t4,$t3,$v0
/*  f10660c:	032c6824 */ 	and	$t5,$t9,$t4
/*  f106610:	11a00004 */ 	beqz	$t5,.L0f106624
/*  f106614:	00000000 */ 	sll	$zero,$zero,0x0
.L0f106618:
/*  f106618:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f10661c:	10000003 */ 	beqz	$zero,.L0f10662c
/*  f106620:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f106624:
/*  f106624:	14aafff1 */ 	bne	$a1,$t2,.L0f1065ec
/*  f106628:	24e70002 */ 	addiu	$a3,$a3,0x2
.L0f10662c:
/*  f10662c:	10800003 */ 	beqz	$a0,.L0f10663c
/*  f106630:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f106634:	1449ffea */ 	bne	$v0,$t1,.L0f1065e0
/*  f106638:	24c60006 */ 	addiu	$a2,$a2,0x6
.L0f10663c:
/*  f10663c:	03e00008 */ 	jr	$ra
/*  f106640:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel menuhandler00106644
/*  f106644:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f106648:	3c0e8007 */ 	lui	$t6,%hi(cutscenegrouptable)
/*  f10664c:	27a20028 */ 	addiu	$v0,$sp,0x28
/*  f106650:	25ce38e8 */ 	addiu	$t6,$t6,%lo(cutscenegrouptable)
/*  f106654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106658:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f10665c:	25d90054 */ 	addiu	$t9,$t6,0x54
/*  f106660:	00404025 */ 	or	$t0,$v0,$zero
.L0f106664:
/*  f106664:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f106668:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f10666c:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f106670:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f106674:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f106678:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f10667c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f106680:	15d9fff8 */ 	bne	$t6,$t9,.L0f106664
/*  f106684:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f106688:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f10668c:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f106690:	ad010000 */ 	sw	$at,0x0($t0)
/*  f106694:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f106698:	10200053 */ 	beqz	$at,.L0f1067e8
/*  f10669c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1066a0:	3c017f1b */ 	lui	$at,%hi(var7f1b2e88)
/*  f1066a4:	00290821 */ 	addu	$at,$at,$t1
/*  f1066a8:	8c292e88 */ 	lw	$t1,%lo(var7f1b2e88)($at)
/*  f1066ac:	01200008 */ 	jr	$t1
/*  f1066b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1066b4:	0fc41970 */ 	jal	func0f1065c0
/*  f1066b8:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f1066bc:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1066c0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1066c4:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f1066c8:	8d6b38a0 */ 	lw	$t3,0x38a0($t3)
/*  f1066cc:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f1066d0:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f1066d4:	10000044 */ 	beqz	$zero,.L0f1067e8
/*  f1066d8:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f1066dc:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1066e0:	3c048007 */ 	lui	$a0,0x8007
/*  f1066e4:	1440000a */ 	bnez	$v0,.L0f106710
/*  f1066e8:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1066ec:	0fc5b9f1 */ 	jal	textGet
/*  f1066f0:	240457c0 */ 	addiu	$a0,$zero,0x57c0
/*  f1066f4:	3c048007 */ 	lui	$a0,0x8007
/*  f1066f8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f1066fc:	0c004dad */ 	jal	sprintf
/*  f106700:	00402825 */ 	or	$a1,$v0,$zero
/*  f106704:	3c028007 */ 	lui	$v0,0x8007
/*  f106708:	10000038 */ 	beqz	$zero,.L0f1067ec
/*  f10670c:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f106710:
/*  f106710:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f106714:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f106718:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f10671c:	0fc5b9f1 */ 	jal	textGet
/*  f106720:	948436d4 */ 	lhu	$a0,0x36d4($a0)
/*  f106724:	10000032 */ 	beqz	$zero,.L0f1067f0
/*  f106728:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10672c:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f106730:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f106734:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f106738:	14400010 */ 	bnez	$v0,.L0f10677c
/*  f10673c:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f106740:	0fc41970 */ 	jal	func0f1065c0
/*  f106744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106748:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10674c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f106750:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f106754:	3c0f8007 */ 	lui	$t7,0x8007
/*  f106758:	a06004d4 */ 	sb	$zero,0x4d4($v1)
/*  f10675c:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f106760:	8def38a0 */ 	lw	$t7,0x38a0($t7)
/*  f106764:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f106768:	a06f04d5 */ 	sb	$t7,0x4d5($v1)
/*  f10676c:	0fc06fa8 */ 	jal	func0f01bea0
/*  f106770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106774:	1000001d */ 	beqz	$zero,.L0f1067ec
/*  f106778:	00001025 */ 	or	$v0,$zero,$zero
.L0f10677c:
/*  f10677c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f106780:	a07904d4 */ 	sb	$t9,0x4d4($v1)
/*  f106784:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f106788:	a06e04d5 */ 	sb	$t6,0x4d5($v1)
/*  f10678c:	0fc06fa8 */ 	jal	func0f01bea0
/*  f106790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106794:	10000015 */ 	beqz	$zero,.L0f1067ec
/*  f106798:	00001025 */ 	or	$v0,$zero,$zero
/*  f10679c:	3c08000f */ 	lui	$t0,0xf
/*  f1067a0:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f1067a4:	10000010 */ 	beqz	$zero,.L0f1067e8
/*  f1067a8:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f1067ac:	2409000b */ 	addiu	$t1,$zero,0xb
/*  f1067b0:	1000000d */ 	beqz	$zero,.L0f1067e8
/*  f1067b4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1067b8:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f1067bc:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f1067c0:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f1067c4:	0fc5b9f1 */ 	jal	textGet
/*  f1067c8:	95840004 */ 	lhu	$a0,0x4($t4)
/*  f1067cc:	10000008 */ 	beqz	$zero,.L0f1067f0
/*  f1067d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1067d4:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f1067d8:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f1067dc:	00587821 */ 	addu	$t7,$v0,$t8
/*  f1067e0:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f1067e4:	acd90008 */ 	sw	$t9,0x8($a2)
.L0f1067e8:
/*  f1067e8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1067ec:
/*  f1067ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1067f0:
/*  f1067f0:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f1067f4:	03e00008 */ 	jr	$ra
/*  f1067f8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerMainMenuSoloMissions(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.iscoop = false;
		g_MissionConfig.isanti = false;
		menuPushDialog(&g_SelectMissionMenuDialog);
	}

	if (operation == MENUOP_CHECKPREFOCUSED) {
		if (isStageDifficultyUnlocked(1, DIFF_A)) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMainMenuCombatSimulator(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_Vars.bondplayernum = 0;
		g_Vars.coopplayernum = -1;
		g_Vars.antiplayernum = -1;
		func0f19afdc();
		g_Vars.unk000490 = 2;
		func0f0f820c(&g_CombatSimulatorMenuDialog, 3);
		func0f0f8300();
	}

	return 0;
}

s32 menuhandlerMainMenuCooperative(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.iscoop = true;
		g_MissionConfig.isanti = false;
		menuPushDialog(&g_SelectMissionMenuDialog);
	}

	return 0;
}

s32 menuhandlerMainMenuCounterOperative(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if ((func0001404c() & 2) == 0) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		g_MissionConfig.iscoop = false;
		g_MissionConfig.isanti = true;
		menuPushDialog(&g_SelectMissionMenuDialog);
	}

	return 0;
}

bool menudialogMainMenu(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem)
{
	switch (operation) {
	case MENUOP_100:
		g_MenuStack[g_MpPlayerNum].unk934 = 0;
		break;
	case MENUOP_102:
		if (g_MenuStack[g_MpPlayerNum].unk00 &&
				g_MenuStack[g_MpPlayerNum].unk00->dialog == dialog) {
			g_MissionConfig.iscoop = false;
			g_MissionConfig.isanti = false;
		}
		break;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f106a7c
/*  f106a7c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f106a80:	3c0e8007 */ 	lui	$t6,%hi(mainmenulabels_nocheats)
/*  f106a84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106a88:	25ce39c0 */ 	addiu	$t6,$t6,%lo(mainmenulabels_nocheats)
/*  f106a8c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f106a90:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f106a94:	3c088007 */ 	lui	$t0,%hi(mainmenulabels_withcheats)
/*  f106a98:	ac410000 */ 	sw	$at,0x0($v0)
/*  f106a9c:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f106aa0:	250839c8 */ 	addiu	$t0,$t0,%lo(mainmenulabels_withcheats)
/*  f106aa4:	27a30018 */ 	addiu	$v1,$sp,0x18
/*  f106aa8:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f106aac:	8d010000 */ 	lw	$at,0x0($t0)
/*  f106ab0:	3c0c800a */ 	lui	$t4,0x800a
/*  f106ab4:	00802825 */ 	or	$a1,$a0,$zero
/*  f106ab8:	ac610000 */ 	sw	$at,0x0($v1)
/*  f106abc:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*  f106ac0:	3c0d800a */ 	lui	$t5,0x800a
/*  f106ac4:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f106ac8:	8d8c21d8 */ 	lw	$t4,0x21d8($t4)
/*  f106acc:	55800005 */ 	bnezl	$t4,.L0f106ae4
/*  f106ad0:	90b80001 */ 	lbu	$t8,0x1($a1)
/*  f106ad4:	8dad21dc */ 	lw	$t5,0x21dc($t5)
/*  f106ad8:	51a00009 */ 	beqzl	$t5,.L0f106b00
/*  f106adc:	90b90001 */ 	lbu	$t9,0x1($a1)
/*  f106ae0:	90b80001 */ 	lbu	$t8,0x1($a1)
.L0f106ae4:
/*  f106ae4:	00187840 */ 	sll	$t7,$t8,0x1
/*  f106ae8:	006f7021 */ 	addu	$t6,$v1,$t7
/*  f106aec:	0fc5b9f1 */ 	jal	textGet
/*  f106af0:	95c40000 */ 	lhu	$a0,0x0($t6)
/*  f106af4:	10000007 */ 	beqz	$zero,.L0f106b14
/*  f106af8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f106afc:	90b90001 */ 	lbu	$t9,0x1($a1)
.L0f106b00:
/*  f106b00:	00195040 */ 	sll	$t2,$t9,0x1
/*  f106b04:	004a4821 */ 	addu	$t1,$v0,$t2
/*  f106b08:	0fc5b9f1 */ 	jal	textGet
/*  f106b0c:	95240000 */ 	lhu	$a0,0x0($t1)
/*  f106b10:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f106b14:
/*  f106b14:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f106b18:	03e00008 */ 	jr	$ra
/*  f106b1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f106b20
/*  f106b20:	3c0e8007 */ 	lui	$t6,0x8007
/*  f106b24:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f106b28:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f106b2c:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f106b30:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f106b34:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f106b38:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f106b3c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f106b40:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f106b44:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f106b48:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f106b4c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f106b50:	9059083c */ 	lbu	$t9,0x83c($v0)
/*  f106b54:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f106b58:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106b5c:	17200071 */ 	bnez	$t9,.L0f106d24
/*  f106b60:	3c08800a */ 	lui	$t0,0x800a
/*  f106b64:	a040083b */ 	sb	$zero,0x83b($v0)
/*  f106b68:	8d08a474 */ 	lw	$t0,-0x5b8c($t0)
/*  f106b6c:	24010026 */ 	addiu	$at,$zero,0x26
/*  f106b70:	3c048007 */ 	lui	$a0,%hi(menudialog_196b0)
/*  f106b74:	15010067 */ 	bne	$t0,$at,.L0f106d14
/*  f106b78:	24843690 */ 	addiu	$a0,$a0,%lo(menudialog_196b0)
/*  f106b7c:	0fc67264 */ 	jal	ciIsTourDone
/*  f106b80:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f106b84:	1040005c */ 	beqz	$v0,.L0f106cf8
/*  f106b88:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f106b8c:	0fc68606 */ 	jal	ciGetTrainingData
/*  f106b90:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f106b94:	3c09800a */ 	lui	$t1,0x800a
/*  f106b98:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f106b9c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f106ba0:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f106ba4:	85440028 */ 	lh	$a0,0x28($t2)
/*  f106ba8:	28810016 */ 	slti	$at,$a0,0x16
/*  f106bac:	1420001a */ 	bnez	$at,.L0f106c18
/*  f106bb0:	2881001a */ 	slti	$at,$a0,0x1a
/*  f106bb4:	50200019 */ 	beqzl	$at,.L0f106c1c
/*  f106bb8:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f106bbc:	0fc687f8 */ 	jal	func0f1a1fe0
/*  f106bc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106bc4:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f106bc8:	3c048009 */ 	lui	$a0,%hi(menudialog_2f68c)
/*  f106bcc:	2484966c */ 	addiu	$a0,$a0,%lo(menudialog_2f68c)
/*  f106bd0:	00035fc2 */ 	srl	$t3,$v1,0x1f
/*  f106bd4:	11600005 */ 	beqz	$t3,.L0f106bec
/*  f106bd8:	000368c0 */ 	sll	$t5,$v1,0x3
/*  f106bdc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106be0:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106be4:	10000044 */ 	beqz	$zero,.L0f106cf8
/*  f106be8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106bec:
/*  f106bec:	05a10005 */ 	bgez	$t5,.L0f106c04
/*  f106bf0:	3c048009 */ 	lui	$a0,%hi(menudialog_holotraining)
/*  f106bf4:	0fc687fb */ 	jal	func0f1a1fec
/*  f106bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106bfc:	1000003e */ 	beqz	$zero,.L0f106cf8
/*  f106c00:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106c04:
/*  f106c04:	248495dc */ 	addiu	$a0,$a0,%lo(menudialog_holotraining)
/*  f106c08:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106c0c:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106c10:	10000039 */ 	beqz	$zero,.L0f106cf8
/*  f106c14:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106c18:
/*  f106c18:	2401001e */ 	addiu	$at,$zero,0x1e
.L0f106c1c:
/*  f106c1c:	54810017 */ 	bnel	$a0,$at,.L0f106c7c
/*  f106c20:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f106c24:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f106c28:	3c048009 */ 	lui	$a0,%hi(menudialog_2f49c)
/*  f106c2c:	2484947c */ 	addiu	$a0,$a0,%lo(menudialog_2f49c)
/*  f106c30:	000377c2 */ 	srl	$t6,$v1,0x1f
/*  f106c34:	11c00005 */ 	beqz	$t6,.L0f106c4c
/*  f106c38:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f106c3c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106c40:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106c44:	1000002c */ 	beqz	$zero,.L0f106cf8
/*  f106c48:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106c4c:
/*  f106c4c:	07010005 */ 	bgez	$t8,.L0f106c64
/*  f106c50:	3c048009 */ 	lui	$a0,%hi(menudialog_devicelist)
/*  f106c54:	0fc68643 */ 	jal	func0f1a190c
/*  f106c58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106c5c:	10000026 */ 	beqz	$zero,.L0f106cf8
/*  f106c60:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106c64:
/*  f106c64:	248493e0 */ 	addiu	$a0,$a0,%lo(menudialog_devicelist)
/*  f106c68:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106c6c:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106c70:	10000021 */ 	beqz	$zero,.L0f106cf8
/*  f106c74:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f106c78:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f106c7c:
/*  f106c7c:	0003cfc2 */ 	srl	$t9,$v1,0x1f
/*  f106c80:	13200007 */ 	beqz	$t9,.L0f106ca0
/*  f106c84:	000348c0 */ 	sll	$t1,$v1,0x3
/*  f106c88:	3c048009 */ 	lui	$a0,%hi(menudialog_2f49c)
/*  f106c8c:	2484947c */ 	addiu	$a0,$a0,%lo(menudialog_2f49c)
/*  f106c90:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106c94:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106c98:	10000017 */ 	beqz	$zero,.L0f106cf8
/*  f106c9c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106ca0:
/*  f106ca0:	05210005 */ 	bgez	$t1,.L0f106cb8
/*  f106ca4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f106ca8:	0fc68643 */ 	jal	func0f1a190c
/*  f106cac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106cb0:	10000011 */ 	beqz	$zero,.L0f106cf8
/*  f106cb4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106cb8:
/*  f106cb8:	1481000f */ 	bne	$a0,$at,.L0f106cf8
/*  f106cbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106cc0:	0fc6830c */ 	jal	func0f1a0c30
/*  f106cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106cc8:	10400007 */ 	beqz	$v0,.L0f106ce8
/*  f106ccc:	3c048009 */ 	lui	$a0,%hi(g_frWeaponMenuDialog)
/*  f106cd0:	3c048009 */ 	lui	$a0,%hi(menudialog_frtraininginfo)
/*  f106cd4:	24848e6c */ 	addiu	$a0,$a0,%lo(menudialog_frtraininginfo)
/*  f106cd8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106cdc:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106ce0:	10000005 */ 	beqz	$zero,.L0f106cf8
/*  f106ce4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106ce8:
/*  f106ce8:	24848d78 */ 	addiu	$a0,$a0,%lo(g_frWeaponMenuDialog)
/*  f106cec:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106cf0:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f106cf4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106cf8:
/*  f106cf8:	14a00008 */ 	bnez	$a1,.L0f106d1c
/*  f106cfc:	3c048007 */ 	lui	$a0,%hi(menudialog_mainmenu2)
/*  f106d00:	24843a74 */ 	addiu	$a0,$a0,%lo(menudialog_mainmenu2)
/*  f106d04:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106d08:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f106d0c:	10000006 */ 	beqz	$zero,.L0f106d28
/*  f106d10:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f106d14:
/*  f106d14:	0fc3e0cc */ 	jal	func0f0f8330
/*  f106d18:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f106d1c:
/*  f106d1c:	10000002 */ 	beqz	$zero,.L0f106d28
/*  f106d20:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f106d24:
/*  f106d24:	00001025 */ 	or	$v0,$zero,$zero
.L0f106d28:
/*  f106d28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f106d2c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f106d30:	03e00008 */ 	jr	$ra
/*  f106d34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106d38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106d3c:	00000000 */ 	sll	$zero,$zero,0x0
);
