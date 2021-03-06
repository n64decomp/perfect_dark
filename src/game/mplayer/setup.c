#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/game_1531a0.h"
#include "game/music.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct menuitem g_MpCharacterMenuItems[];
struct menudialog g_MpAddSimulantMenuDialog;
struct menudialog g_MpChangeSimulantMenuDialog;
struct menudialog g_MpChangeTeamNameMenuDialog;
struct menudialog g_MpEditSimulantMenuDialog;
struct menudialog g_MpSaveSetupNameMenuDialog;

s32 menuhandlerMpDropOut(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

char *mpGetCurrentPlayerName(struct menuitem *item)
{
	return g_MpPlayers[g_MpPlayerNum].base.name;
}

s32 menuhandlerMpTeamsLabel(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return true;
		}
	}

	return 0;
}

struct menuitem g_MpDropOutMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_196, 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_197, 0x00000000, menuhandlerMpDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_198, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpDropOutMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_195, // "Drop Out"
	g_MpDropOutMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct mparena g_MpArenas[] = {
	// Stage, unlock, name
	{ STAGE_MP_SKEDAR,     0,                          L_MPMENU_119 },
	{ STAGE_MP_PIPES,      0,                          L_MPMENU_120 },
	{ STAGE_MP_RAVINE,     MPFEATURE_STAGE_RAVINE,     L_MPMENU_121 },
	{ STAGE_MP_G5BUILDING, MPFEATURE_STAGE_G5BUILDING, L_MPMENU_122 },
	{ STAGE_MP_SEWERS,     MPFEATURE_STAGE_SEWERS,     L_MPMENU_123 },
	{ STAGE_MP_WAREHOUSE,  MPFEATURE_STAGE_WAREHOUSE,  L_MPMENU_124 },
	{ STAGE_MP_GRID,       MPFEATURE_STAGE_GRID,       L_MPMENU_125 },
	{ STAGE_MP_RUINS,      MPFEATURE_STAGE_RUINS,      L_MPMENU_126 },
	{ STAGE_MP_AREA52,     0,                          L_MPMENU_127 },
	{ STAGE_MP_BASE,       MPFEATURE_STAGE_BASE,       L_MPMENU_128 },
	{ STAGE_MP_FORTRESS,   MPFEATURE_STAGE_FORTRESS,   L_MPMENU_130 },
	{ STAGE_MP_VILLA,      MPFEATURE_STAGE_VILLA,      L_MPMENU_131 },
	{ STAGE_MP_CARPARK,    MPFEATURE_STAGE_CARPARK,    L_MPMENU_132 },
	{ STAGE_MP_TEMPLE,     MPFEATURE_STAGE_TEMPLE,     L_MPMENU_133 },
	{ STAGE_MP_COMPLEX,    MPFEATURE_STAGE_COMPLEX,    L_MPMENU_134 },
	{ STAGE_MP_FELICITY,   MPFEATURE_STAGE_FELICITY,   L_MPMENU_135 },
	{ 1,                   0,                          L_MPMENU_136 }, // "Random"
};

s32 mpGetNumStages(void)
{
	return 17;
}

s16 mpChooseRandomStage(void)
{
	s32 i;
	s32 numchallengescomplete = 0;
	s32 index;

	for (i = 0; i < 16; i++) {
		if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
			numchallengescomplete++;
		}
	}

	index = random() % numchallengescomplete;

	for (i = 0; i < 16; i++) {
		if (mpIsFeatureUnlocked(g_MpArenas[i].requirefeature)) {
			if (index == 0) {
				return g_MpArenas[i].stagenum;
			}

			index--;
		}
	}

	return STAGE_MP_SKEDAR;
}

u32 var80084c00[] = {
	0x00000000, 0x50740000, // "Dark"
	0x0000000d, 0x50750000, // "Classic"
	0x00000010, 0x50760000, // "Custom"
};

GLOBAL_ASM(
glabel menuhandler001791c8
.late_rodata
glabel var7f1b805c
.word menuhandler001791c8+0x80 # f179248
glabel var7f1b8060
.word menuhandler001791c8+0x194 # f17935c
glabel var7f1b8064
.word menuhandler001791c8+0xb4 # f17927c
glabel var7f1b8068
.word menuhandler001791c8+0x1dc # f1793a4
glabel var7f1b806c
.word menuhandler001791c8+0x234 # f1793fc
glabel var7f1b8070
.word menuhandler001791c8+0x104 # f1792cc
glabel var7f1b8074
.word menuhandler001791c8+0x148 # f179310
.text
/*  f1791c8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f1791cc:	3c0f8008 */ 	lui	$t7,%hi(var80084c00)
/*  f1791d0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1791d4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1791d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1791dc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1791e0:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f1791e4:	25ef4c00 */ 	addiu	$t7,$t7,%lo(var80084c00)
/*  f1791e8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1791ec:	27ae0040 */ 	addiu	$t6,$sp,0x40
/*  f1791f0:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1791f4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1791f8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1791fc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f179200:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f179204:	adc10008 */ 	sw	$at,0x8($t6)
/*  f179208:	8de10010 */ 	lw	$at,0x10($t7)
/*  f17920c:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f179210:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f179214:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f179218:	adc10010 */ 	sw	$at,0x10($t6)
/*  f17921c:	2d210007 */ 	sltiu	$at,$t1,0x7
/*  f179220:	00c09025 */ 	or	$s2,$a2,$zero
/*  f179224:	00008825 */ 	or	$s1,$zero,$zero
/*  f179228:	1020009b */ 	beqz	$at,.L0f179498
/*  f17922c:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f179230:	00094880 */ 	sll	$t1,$t1,0x2
/*  f179234:	3c017f1c */ 	lui	$at,%hi(var7f1b805c)
/*  f179238:	00290821 */ 	addu	$at,$at,$t1
/*  f17923c:	8c29805c */ 	lw	$t1,%lo(var7f1b805c)($at)
/*  f179240:	01200008 */ 	jr	$t1
/*  f179244:	00000000 */ 	nop
/*  f179248:	3c108008 */ 	lui	$s0,%hi(g_MpArenas)
/*  f17924c:	26104b98 */ 	addiu	$s0,$s0,%lo(g_MpArenas)
.L0f179250:
/*  f179250:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179254:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f179258:	10400002 */ 	beqz	$v0,.L0f179264
/*  f17925c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f179260:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f179264:
/*  f179264:	3c0a8008 */ 	lui	$t2,%hi(g_MpArenas+0x66)
/*  f179268:	254a4bfe */ 	addiu	$t2,$t2,%lo(g_MpArenas+0x66)
/*  f17926c:	160afff8 */ 	bne	$s0,$t2,.L0f179250
/*  f179270:	00000000 */ 	nop
/*  f179274:	10000088 */ 	b	.L0f179498
/*  f179278:	ae510000 */ 	sw	$s1,0x0($s2)
/*  f17927c:	3c108008 */ 	lui	$s0,%hi(g_MpArenas)
/*  f179280:	26104b98 */ 	addiu	$s0,$s0,%lo(g_MpArenas)
.L0f179284:
/*  f179284:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179288:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f17928c:	10400009 */ 	beqz	$v0,.L0f1792b4
/*  f179290:	3c0c8008 */ 	lui	$t4,%hi(g_MpArenas+0x66)
/*  f179294:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f179298:	562b0006 */ 	bnel	$s1,$t3,.L0f1792b4
/*  f17929c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1792a0:	0fc5b9f1 */ 	jal	langGet
/*  f1792a4:	96040004 */ 	lhu	$a0,0x4($s0)
/*  f1792a8:	1000007d */ 	b	.L0f1794a0
/*  f1792ac:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1792b0:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1792b4:
/*  f1792b4:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f1792b8:	258c4bfe */ 	addiu	$t4,$t4,%lo(g_MpArenas+0x66)
/*  f1792bc:	160cfff1 */ 	bne	$s0,$t4,.L0f179284
/*  f1792c0:	00000000 */ 	nop
/*  f1792c4:	10000075 */ 	b	.L0f17949c
/*  f1792c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1792cc:	3c108008 */ 	lui	$s0,%hi(g_MpArenas)
/*  f1792d0:	26104b98 */ 	addiu	$s0,$s0,%lo(g_MpArenas)
.L0f1792d4:
/*  f1792d4:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1792d8:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f1792dc:	10400004 */ 	beqz	$v0,.L0f1792f0
/*  f1792e0:	3c198008 */ 	lui	$t9,%hi(g_MpArenas+0x66)
/*  f1792e4:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f1792e8:	122d0005 */ 	beq	$s1,$t5,.L0f179300
/*  f1792ec:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1792f0:
/*  f1792f0:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f1792f4:	27394bfe */ 	addiu	$t9,$t9,%lo(g_MpArenas+0x66)
/*  f1792f8:	1619fff6 */ 	bne	$s0,$t9,.L0f1792d4
/*  f1792fc:	00000000 */ 	nop
.L0f179300:
/*  f179300:	86180000 */ 	lh	$t8,0x0($s0)
/*  f179304:	3c01800b */ 	lui	$at,%hi(g_MpSetup+0x11)
/*  f179308:	10000063 */ 	b	.L0f179498
/*  f17930c:	a038cb99 */ 	sb	$t8,%lo(g_MpSetup+0x11)($at)
/*  f179310:	3c108008 */ 	lui	$s0,%hi(g_MpArenas)
/*  f179314:	26104b98 */ 	addiu	$s0,$s0,%lo(g_MpArenas)
.L0f179318:
/*  f179318:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x11)
/*  f17931c:	91cecb99 */ 	lbu	$t6,%lo(g_MpSetup+0x11)($t6)
/*  f179320:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f179324:	15cf0002 */ 	bne	$t6,$t7,.L0f179330
/*  f179328:	00000000 */ 	nop
/*  f17932c:	ae510000 */ 	sw	$s1,0x0($s2)
.L0f179330:
/*  f179330:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179334:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f179338:	10400002 */ 	beqz	$v0,.L0f179344
/*  f17933c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f179340:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f179344:
/*  f179344:	3c088008 */ 	lui	$t0,%hi(g_MpArenas+0x66)
/*  f179348:	25084bfe */ 	addiu	$t0,$t0,%lo(g_MpArenas+0x66)
/*  f17934c:	1608fff2 */ 	bne	$s0,$t0,.L0f179318
/*  f179350:	00000000 */ 	nop
/*  f179354:	10000051 */ 	b	.L0f17949c
/*  f179358:	00001025 */ 	or	$v0,$zero,$zero
/*  f17935c:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f179360:	ae490000 */ 	sw	$t1,0x0($s2)
/*  f179364:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179368:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f17936c:	5440004b */ 	bnezl	$v0,.L0f17949c
/*  f179370:	00001025 */ 	or	$v0,$zero,$zero
/*  f179374:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179378:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f17937c:	54400047 */ 	bnezl	$v0,.L0f17949c
/*  f179380:	00001025 */ 	or	$v0,$zero,$zero
/*  f179384:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179388:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f17938c:	54400043 */ 	bnezl	$v0,.L0f17949c
/*  f179390:	00001025 */ 	or	$v0,$zero,$zero
/*  f179394:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f179398:	254bffff */ 	addiu	$t3,$t2,-1
/*  f17939c:	1000003e */ 	b	.L0f179498
/*  f1793a0:	ae4b0000 */ 	sw	$t3,0x0($s2)
/*  f1793a4:	8e510000 */ 	lw	$s1,0x0($s2)
/*  f1793a8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1793ac:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f1793b0:	5440000d */ 	bnezl	$v0,.L0f1793e8
/*  f1793b4:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793b8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1793bc:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f1793c0:	54400009 */ 	bnezl	$v0,.L0f1793e8
/*  f1793c4:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793c8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1793cc:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f1793d0:	54400005 */ 	bnezl	$v0,.L0f1793e8
/*  f1793d4:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793d8:	5a200003 */ 	blezl	$s1,.L0f1793e8
/*  f1793dc:	001160c0 */ 	sll	$t4,$s1,0x3
/*  f1793e0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1793e4:	001160c0 */ 	sll	$t4,$s1,0x3
.L0f1793e8:
/*  f1793e8:	03ac2021 */ 	addu	$a0,$sp,$t4
/*  f1793ec:	0fc5b9f1 */ 	jal	langGet
/*  f1793f0:	94840044 */ 	lhu	$a0,0x44($a0)
/*  f1793f4:	1000002a */ 	b	.L0f1794a0
/*  f1793f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1793fc:	8e500000 */ 	lw	$s0,0x0($s2)
/*  f179400:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179404:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f179408:	5440000d */ 	bnezl	$v0,.L0f179440
/*  f17940c:	001068c0 */ 	sll	$t5,$s0,0x3
/*  f179410:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179414:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f179418:	54400009 */ 	bnezl	$v0,.L0f179440
/*  f17941c:	001068c0 */ 	sll	$t5,$s0,0x3
/*  f179420:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179424:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f179428:	14400004 */ 	bnez	$v0,.L0f17943c
/*  f17942c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f179430:	56010003 */ 	bnel	$s0,$at,.L0f179440
/*  f179434:	001068c0 */ 	sll	$t5,$s0,0x3
/*  f179438:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f17943c:
/*  f17943c:	001068c0 */ 	sll	$t5,$s0,0x3
.L0f179440:
/*  f179440:	27b90040 */ 	addiu	$t9,$sp,0x40
/*  f179444:	01b92821 */ 	addu	$a1,$t5,$t9
/*  f179448:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f17944c:	3c108008 */ 	lui	$s0,%hi(g_MpArenas)
/*  f179450:	26104b98 */ 	addiu	$s0,$s0,%lo(g_MpArenas)
/*  f179454:	1b00000f */ 	blez	$t8,.L0f179494
/*  f179458:	00001825 */ 	or	$v1,$zero,$zero
/*  f17945c:	92040002 */ 	lbu	$a0,0x2($s0)
.L0f179460:
/*  f179460:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f179464:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179468:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f17946c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f179470:	10400002 */ 	beqz	$v0,.L0f17947c
/*  f179474:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f179478:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17947c:
/*  f17947c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f179480:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f179484:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f179488:	006e082a */ 	slt	$at,$v1,$t6
/*  f17948c:	5420fff4 */ 	bnezl	$at,.L0f179460
/*  f179490:	92040002 */ 	lbu	$a0,0x2($s0)
.L0f179494:
/*  f179494:	ae510008 */ 	sw	$s1,0x8($s2)
.L0f179498:
/*  f179498:	00001025 */ 	or	$v0,$zero,$zero
.L0f17949c:
/*  f17949c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1794a0:
/*  f1794a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1794a4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1794a8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1794ac:	03e00008 */ 	jr	$ra
/*  f1794b0:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

s32 menuhandlerMpControlStyle(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
		L_OPTIONS_239, // "1.1"
		L_OPTIONS_240, // "1.2"
		L_OPTIONS_241, // "1.3"
		L_OPTIONS_242, // "1.4"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 4;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(labels[data->dropdown.value]);
	case MENUOP_SET:
		optionsSetControlMode(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = optionsGetControlMode(g_MpPlayerNum);
		break;
	}

	return 0;
}

s32 menuhandlerMpWeaponSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mpGetNumWeaponOptions();
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) mpGetWeaponLabel(data->dropdown.value);
	case MENUOP_SET:
		mpSetWeaponSlot(item->param3, data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = mpGetWeaponSlot(item->param3);
	}

	return 0;
}

char *mpMenuTextWeaponNameForSlot(struct menuitem *item)
{
	return mpGetWeaponLabel(mpGetWeaponSlot(item->param));
}

s32 menuhandlerMpWeaponSetDropdown(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = func0f189058(item->param);
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) mpGetWeaponSetName(data->dropdown.value);
	case MENUOP_SET:
		mpSetWeaponSet(data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = mpGetWeaponSet();
		break;
	}

	return 0;
}

s32 menuhandlerMpControlCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 val;

	switch (operation) {
	case MENUOP_GET:
		if (item->param3 == OPTION_FORWARDPITCH) {
			if ((g_MpPlayers[g_MpPlayerNum].options & item->param3) == 0) {
				return true;
			}
			return false;
		}
		if ((g_MpPlayers[g_MpPlayerNum].options & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		val = OPTION_FORWARDPITCH;

		if (item->param3 == val) {
			if (data->checkbox.value == 0) {
				data->checkbox.value = val;
			} else {
				data->checkbox.value = 0;
			}
		}

		g_MpPlayers[g_MpPlayerNum].options &= ~item->param3;

		if (data->checkbox.value) {
			g_MpPlayers[g_MpPlayerNum].options |= item->param3;
		}
	}

	return 0;
}

s32 menuhandlerMpAimControl(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
#if PAL
		L_MPWEAPONS_276, // "Hold"
		L_MPWEAPONS_277, // "Toggle"
#else
		L_MPMENU_213, // "Hold"
		L_MPMENU_214, // "Toggle"
#endif
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 2;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) langGet(labels[data->dropdown.value]);
	case MENUOP_SET:
		optionsSetAimControl(g_MpPlayerNum, data->dropdown.value);
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = optionsGetAimControl(g_MpPlayerNum);
		break;
	}

	return 0;
}

s32 menuhandlerMpCheckboxOption(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		if ((g_MpSetup.options & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		g_MpSetup.options = g_MpSetup.options & ~item->param3;
		if (data->checkbox.value) {
			g_MpSetup.options = g_MpSetup.options | item->param3;
		}
	}

	return 0;
}

s32 menuhandlerMpTeamsEnabled(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE ||
				g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			return true;
		}

		return false;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

s32 menuhandlerMpDisplayOptionCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		if ((g_MpPlayers[g_MpPlayerNum].base.displayoptions & item->param3) == 0) {
			return false;
		}
		return true;
	case MENUOP_SET:
		g_MpPlayers[g_MpPlayerNum].base.displayoptions &= ~(u8)item->param3;

		if (data->checkbox.value) {
			g_MpPlayers[g_MpPlayerNum].base.displayoptions |= (u8)item->param3;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpConfirmSaveChr(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		filemgrPushSelectLocationDialog(6, 2);
	}

	return 0;
}

s32 menuhandlerMpPlayerName(s32 operation, struct menuitem *item, union handlerdata *data)
{
	char *name = data->keyboard.string;

	switch (operation) {
	case MENUOP_GETTEXT:
		strcpy(name, g_MpSetup.name);
		break;
	case MENUOP_SETTEXT:
		strcpy(g_MpSetup.name, name);
		break;
	case MENUOP_SET:
		filemgrPushSelectLocationDialog(7, 1);
		break;
	}

	return 0;
}

s32 menuhandlerMpSaveSetupOverwrite(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		func0f1094e4(&g_MpSetup.unk20, 4, NULL);
	}

	return 0;
}

s32 menuhandlerMpSaveSetupCopy(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPushDialog(&g_MpSaveSetupNameMenuDialog);
	}

	return 0;
}

char *mpMenuTextSetupName(struct menuitem *item)
{
	return g_MpSetup.name;
}

s32 func0f179b68(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpPlayers[g_MpPlayerNum].base.unk18;
		break;
	case MENUOP_SET:
		g_MpPlayers[g_MpPlayerNum].base.unk18 = (u8) data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%d%%\n", data->slider.value + 20);
		break;
	}

	return 0;
}

s32 func0f179c14(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpPlayers[g_MpPlayerNum].base.unk1a;
		break;
	case MENUOP_SET:
		g_MpPlayers[g_MpPlayerNum].base.unk1a = (u8) data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%d%%\n", data->slider.value + 20);
		break;
	}

	return 0;
}

s32 func0f179cc0(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpPlayers[g_MpPlayerNum].base.unk1c;
		break;
	case MENUOP_SET:
		g_MpPlayers[g_MpPlayerNum].base.unk1c = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%d%%\n", data->slider.value + 25);
		break;
	}

	return 0;
}

s32 func0f179d6c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fbc(g_MpPlayerNum);
	}

	return 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f179da4
.late_rodata
glabel var7f1b8078
.word func0f179da4+0x34 # f179dd8
glabel var7f1b807c
.word func0f179da4+0x270 # f17a014
glabel var7f1b8080
.word func0f179da4+0x270 # f17a014
glabel var7f1b8084
.word func0f179da4+0x270 # f17a014
glabel var7f1b8088
.word func0f179da4+0x270 # f17a014
glabel var7f1b808c
.word func0f179da4+0x168 # f179f0c
glabel var7f1b8090
.word func0f179da4+0x160 # f179f04
glabel var7f1b8094
.word func0f179da4+0x270 # f17a014
glabel var7f1b8098
.word func0f179da4+0x270 # f17a014
glabel var7f1b809c
.word func0f179da4+0x270 # f17a014
glabel var7f1b80a0
.word func0f179da4+0x48 # f179dec
glabel var7f1b80a4
.word func0f179da4+0x270 # f17a014
glabel var7f1b80a8
.word func0f179da4+0x128 # f179ecc
glabel var7f1b80ac
.word func0f179da4+0x270 # f17a014
glabel var7f1b80b0
.word func0f179da4+0x168 # f179f0c
glabel var7f1b80b4
.word func0f179da4+0x270 # f17a014
glabel var7f1b80b8
.word func0f179da4+0x270 # f17a014
glabel var7f1b80bc
.word func0f179da4+0x270 # f17a014
glabel var7f1b80c0
.word func0f179da4+0x270 # f17a014
glabel var7f1b80c4
.word func0f179da4+0x270 # f17a014
glabel var7f1b80c8
.word func0f179da4+0x108 # f179eac
glabel var7f1b80cc
.word 0x3c23d70a
glabel var7f1b80d0
.word 0x41033333
glabel var7f1b80d4
.word 0xc0833333
glabel var7f1b80d8
.word 0xbe4ccccd
glabel var7f1b80dc
.word 0x3b03126f
.text
/*  f179da4:	248effff */ 	addiu	$t6,$a0,-1
/*  f179da8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f179dac:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f179db0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f179db4:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f179db8:	10200096 */ 	beqz	$at,.L0f17a014
/*  f179dbc:	00801825 */ 	or	$v1,$a0,$zero
/*  f179dc0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f179dc4:	3c017f1c */ 	lui	$at,%hi(var7f1b8078)
/*  f179dc8:	002e0821 */ 	addu	$at,$at,$t6
/*  f179dcc:	8c2e8078 */ 	lw	$t6,%lo(var7f1b8078)($at)
/*  f179dd0:	01c00008 */ 	jr	$t6
/*  f179dd4:	00000000 */ 	nop
/*  f179dd8:	0fc62ee2 */ 	jal	mpGetNumBodies
/*  f179ddc:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f179de0:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f179de4:	1000008b */ 	b	.L0f17a014
/*  f179de8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f179dec:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f179df0:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f179df4:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f179df8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f179dfc:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f179e00:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179e04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f179e08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179e0c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f179e10:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179e14:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f179e18:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f179e1c:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f179e20:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f179e24:	03191021 */ 	addu	$v0,$t8,$t9
/*  f179e28:	8c4e0db4 */ 	lw	$t6,0xdb4($v0)
/*  f179e2c:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f179e30:	00095400 */ 	sll	$t2,$t1,0x10
/*  f179e34:	354bffff */ 	ori	$t3,$t2,0xffff
/*  f179e38:	00076600 */ 	sll	$t4,$a3,0x18
/*  f179e3c:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f179e40:	240801fc */ 	addiu	$t0,$zero,0x1fc
/*  f179e44:	016c6825 */ 	or	$t5,$t3,$t4
/*  f179e48:	29e101e1 */ 	slti	$at,$t7,0x191
/*  f179e4c:	a448089c */ 	sh	$t0,0x89c($v0)
/*  f179e50:	ac4d084c */ 	sw	$t5,0x84c($v0)
/*  f179e54:	14200003 */ 	bnez	$at,.L0f179e64
/*  f179e58:	ac4f0db4 */ 	sw	$t7,0xdb4($v0)
/*  f179e5c:	25f8fe20 */ 	addiu	$t8,$t7,-0x190
/*  f179e60:	ac580db4 */ 	sw	$t8,0xdb4($v0)
.L0f179e64:
/*  f179e64:	8c430db8 */ 	lw	$v1,0xdb8($v0)
/*  f179e68:	3c017f1c */ 	lui	$at,%hi(var7f1b80cc)
/*  f179e6c:	18600003 */ 	blez	$v1,.L0f179e7c
/*  f179e70:	0064c823 */ 	subu	$t9,$v1,$a0
/*  f179e74:	10000008 */ 	b	.L0f179e98
/*  f179e78:	ac590db8 */ 	sw	$t9,0xdb8($v0)
.L0f179e7c:
/*  f179e7c:	c42480cc */ 	lwc1	$f4,%lo(var7f1b80cc)($at)
/*  f179e80:	c4a60004 */ 	lwc1	$f6,0x10($a1)
/*  f179e84:	c44a0d64 */ 	lwc1	$f10,0xd64($v0)
/*  f179e88:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f179e8c:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f179e90:	e4400d8c */ 	swc1	$f0,0xd8c($v0)
/*  f179e94:	e4400d64 */ 	swc1	$f0,0xd64($v0)
.L0f179e98:
/*  f179e98:	3c0141f0 */ 	lui	$at,0x41f0
/*  f179e9c:	44818000 */ 	mtc1	$at,$f16
/*  f179ea0:	ac400df4 */ 	sw	$zero,0xdf4($v0)
/*  f179ea4:	1000005b */ 	b	.L0f17a014
/*  f179ea8:	e4500d94 */ 	swc1	$f16,0xd94($v0)
/*  f179eac:	0fc62f1c */ 	jal	mpGetBodyRequiredFeature
/*  f179eb0:	90c40003 */ 	lbu	$a0,0x3($a2)
/*  f179eb4:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179eb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f179ebc:	54400056 */ 	bnezl	$v0,.L0f17a018
/*  f179ec0:	00001025 */ 	or	$v0,$zero,$zero
/*  f179ec4:	10000054 */ 	b	.L0f17a018
/*  f179ec8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f179ecc:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f179ed0:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f179ed4:	3c01800a */ 	lui	$at,%hi(g_Menus+0x840)
/*  f179ed8:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f179edc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f179ee0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f179ee4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f179ee8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f179eec:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f179ef0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f179ef4:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f179ef8:	002a0821 */ 	addu	$at,$at,$t2
/*  f179efc:	10000045 */ 	b	.L0f17a014
/*  f179f00:	a028e840 */ 	sb	$t0,%lo(g_Menus+0x840)($at)
/*  f179f04:	10000043 */ 	b	.L0f17a014
/*  f179f08:	acc70000 */ 	sw	$a3,0x0($a2)
/*  f179f0c:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f179f10:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f179f14:	44800000 */ 	mtc1	$zero,$f0
/*  f179f18:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f179f1c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f179f20:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f179f24:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f179f28:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f179f2c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f179f30:	3c013f80 */ 	lui	$at,0x3f80
/*  f179f34:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f179f38:	44819000 */ 	mtc1	$at,$f18
/*  f179f3c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f179f40:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f179f44:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f179f48:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f179f4c:	44050000 */ 	mfc1	$a1,$f0
/*  f179f50:	44060000 */ 	mfc1	$a2,$f0
/*  f179f54:	44070000 */ 	mfc1	$a3,$f0
/*  f179f58:	ac400dc0 */ 	sw	$zero,0xdc0($v0)
/*  f179f5c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f179f60:	24440840 */ 	addiu	$a0,$v0,0x840
/*  f179f64:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f179f68:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f179f6c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f179f70:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f179f74:	0fc3cdcb */ 	jal	func0f0f372c
/*  f179f78:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f179f7c:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f179f80:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f179f84:	3c017f1c */ 	lui	$at,%hi(var7f1b80d0)
/*  f179f88:	c42080d0 */ 	lwc1	$f0,%lo(var7f1b80d0)($at)
/*  f179f8c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f179f90:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179f94:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f179f98:	3c017f1c */ 	lui	$at,%hi(var7f1b80d4)
/*  f179f9c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179fa0:	c42280d4 */ 	lwc1	$f2,%lo(var7f1b80d4)($at)
/*  f179fa4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f179fa8:	3c017f1c */ 	lui	$at,%hi(var7f1b80d8)
/*  f179fac:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f179fb0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179fb4:	c42c80d8 */ 	lwc1	$f12,%lo(var7f1b80d8)($at)
/*  f179fb8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f179fbc:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f179fc0:	03191021 */ 	addu	$v0,$t8,$t9
/*  f179fc4:	3c017f1c */ 	lui	$at,%hi(var7f1b80dc)
/*  f179fc8:	e4400d50 */ 	swc1	$f0,0xd50($v0)
/*  f179fcc:	e4400d78 */ 	swc1	$f0,0xd78($v0)
/*  f179fd0:	e4420d54 */ 	swc1	$f2,0xd54($v0)
/*  f179fd4:	e4420d7c */ 	swc1	$f2,0xd7c($v0)
/*  f179fd8:	c42480dc */ 	lwc1	$f4,%lo(var7f1b80dc)($at)
/*  f179fdc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f179fe0:	2409003c */ 	addiu	$t1,$zero,0x32
/*  f179fe4:	24080078 */ 	addiu	$t0,$zero,0x64
/*  f179fe8:	240a0008 */ 	addiu	$t2,$zero,0x8
/*  f179fec:	2401000f */ 	addiu	$at,$zero,0xf
/*  f179ff0:	ac490db8 */ 	sw	$t1,0xdb8($v0)
/*  f179ff4:	ac480db4 */ 	sw	$t0,0xdb4($v0)
/*  f179ff8:	a04a0840 */ 	sb	$t2,0x840($v0)
/*  f179ffc:	e44c0d64 */ 	swc1	$f12,0xd64($v0)
/*  f17a000:	e44c0d8c */ 	swc1	$f12,0xd8c($v0)
/*  f17a004:	14610003 */ 	bne	$v1,$at,.L0f17a014
/*  f17a008:	e4440d5c */ 	swc1	$f4,0xd5c($v0)
/*  f17a00c:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f17a010:	a04b0840 */ 	sb	$t3,0x840($v0)
.L0f17a014:
/*  f17a014:	00001025 */ 	or	$v0,$zero,$zero
.L0f17a018:
/*  f17a018:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17a01c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f17a020:	03e00008 */ 	jr	$ra
/*  f17a024:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f179da4
.late_rodata
glabel var7f1b8078
.word func0f179da4+0x34 # f179dd8
glabel var7f1b807c
.word func0f179da4+0x270 # f17a014
glabel var7f1b8080
.word func0f179da4+0x270 # f17a014
glabel var7f1b8084
.word func0f179da4+0x270 # f17a014
glabel var7f1b8088
.word func0f179da4+0x270 # f17a014
glabel var7f1b808c
.word func0f179da4+0x168 # f179f0c
glabel var7f1b8090
.word func0f179da4+0x160 # f179f04
glabel var7f1b8094
.word func0f179da4+0x270 # f17a014
glabel var7f1b8098
.word func0f179da4+0x270 # f17a014
glabel var7f1b809c
.word func0f179da4+0x270 # f17a014
glabel var7f1b80a0
.word func0f179da4+0x48 # f179dec
glabel var7f1b80a4
.word func0f179da4+0x270 # f17a014
glabel var7f1b80a8
.word func0f179da4+0x128 # f179ecc
glabel var7f1b80ac
.word func0f179da4+0x270 # f17a014
glabel var7f1b80b0
.word func0f179da4+0x168 # f179f0c
glabel var7f1b80b4
.word func0f179da4+0x270 # f17a014
glabel var7f1b80b8
.word func0f179da4+0x270 # f17a014
glabel var7f1b80bc
.word func0f179da4+0x270 # f17a014
glabel var7f1b80c0
.word func0f179da4+0x270 # f17a014
glabel var7f1b80c4
.word func0f179da4+0x270 # f17a014
glabel var7f1b80c8
.word func0f179da4+0x108 # f179eac
glabel var7f1b80cc
.word 0x3c23d70a
glabel var7f1b80d0
.word 0x41033333
glabel var7f1b80d4
.word 0xc0833333
glabel var7f1b80d8
.word 0xbe4ccccd
glabel var7f1b80dc
.word 0x3b03126f
.text
/*  f179da4:	248effff */ 	addiu	$t6,$a0,-1
/*  f179da8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f179dac:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f179db0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f179db4:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f179db8:	10200096 */ 	beqz	$at,.L0f17a014
/*  f179dbc:	00801825 */ 	or	$v1,$a0,$zero
/*  f179dc0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f179dc4:	3c017f1c */ 	lui	$at,%hi(var7f1b8078)
/*  f179dc8:	002e0821 */ 	addu	$at,$at,$t6
/*  f179dcc:	8c2e8078 */ 	lw	$t6,%lo(var7f1b8078)($at)
/*  f179dd0:	01c00008 */ 	jr	$t6
/*  f179dd4:	00000000 */ 	nop
/*  f179dd8:	0fc62ee2 */ 	jal	mpGetNumBodies
/*  f179ddc:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f179de0:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f179de4:	1000008b */ 	b	.L0f17a014
/*  f179de8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f179dec:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f179df0:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f179df4:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f179df8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f179dfc:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f179e00:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179e04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f179e08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179e0c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f179e10:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179e14:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f179e18:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f179e1c:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f179e20:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f179e24:	03191021 */ 	addu	$v0,$t8,$t9
/*  f179e28:	8c4e0db4 */ 	lw	$t6,0xdb4($v0)
/*  f179e2c:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f179e30:	00095400 */ 	sll	$t2,$t1,0x10
/*  f179e34:	354bffff */ 	ori	$t3,$t2,0xffff
/*  f179e38:	00076600 */ 	sll	$t4,$a3,0x18
/*  f179e3c:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f179e40:	240801fc */ 	addiu	$t0,$zero,0x1fc
/*  f179e44:	016c6825 */ 	or	$t5,$t3,$t4
/*  f179e48:	29e101e1 */ 	slti	$at,$t7,0x1e1
/*  f179e4c:	a448089c */ 	sh	$t0,0x89c($v0)
/*  f179e50:	ac4d084c */ 	sw	$t5,0x84c($v0)
/*  f179e54:	14200003 */ 	bnez	$at,.L0f179e64
/*  f179e58:	ac4f0db4 */ 	sw	$t7,0xdb4($v0)
/*  f179e5c:	25f8fe20 */ 	addiu	$t8,$t7,-480
/*  f179e60:	ac580db4 */ 	sw	$t8,0xdb4($v0)
.L0f179e64:
/*  f179e64:	8c430db8 */ 	lw	$v1,0xdb8($v0)
/*  f179e68:	3c017f1c */ 	lui	$at,%hi(var7f1b80cc)
/*  f179e6c:	18600003 */ 	blez	$v1,.L0f179e7c
/*  f179e70:	0064c823 */ 	subu	$t9,$v1,$a0
/*  f179e74:	10000008 */ 	b	.L0f179e98
/*  f179e78:	ac590db8 */ 	sw	$t9,0xdb8($v0)
.L0f179e7c:
/*  f179e7c:	c42480cc */ 	lwc1	$f4,%lo(var7f1b80cc)($at)
/*  f179e80:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f179e84:	c44a0d64 */ 	lwc1	$f10,0xd64($v0)
/*  f179e88:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f179e8c:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f179e90:	e4400d8c */ 	swc1	$f0,0xd8c($v0)
/*  f179e94:	e4400d64 */ 	swc1	$f0,0xd64($v0)
.L0f179e98:
/*  f179e98:	3c0141f0 */ 	lui	$at,0x41f0
/*  f179e9c:	44818000 */ 	mtc1	$at,$f16
/*  f179ea0:	ac400df4 */ 	sw	$zero,0xdf4($v0)
/*  f179ea4:	1000005b */ 	b	.L0f17a014
/*  f179ea8:	e4500d94 */ 	swc1	$f16,0xd94($v0)
/*  f179eac:	0fc62f1c */ 	jal	mpGetBodyRequiredFeature
/*  f179eb0:	90c40003 */ 	lbu	$a0,0x3($a2)
/*  f179eb4:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f179eb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f179ebc:	54400056 */ 	bnezl	$v0,.L0f17a018
/*  f179ec0:	00001025 */ 	or	$v0,$zero,$zero
/*  f179ec4:	10000054 */ 	b	.L0f17a018
/*  f179ec8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f179ecc:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f179ed0:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f179ed4:	3c01800a */ 	lui	$at,%hi(g_Menus+0x840)
/*  f179ed8:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f179edc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f179ee0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f179ee4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f179ee8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f179eec:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f179ef0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f179ef4:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f179ef8:	002a0821 */ 	addu	$at,$at,$t2
/*  f179efc:	10000045 */ 	b	.L0f17a014
/*  f179f00:	a028e840 */ 	sb	$t0,%lo(g_Menus+0x840)($at)
/*  f179f04:	10000043 */ 	b	.L0f17a014
/*  f179f08:	acc70000 */ 	sw	$a3,0x0($a2)
/*  f179f0c:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f179f10:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f179f14:	44800000 */ 	mtc1	$zero,$f0
/*  f179f18:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f179f1c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f179f20:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f179f24:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f179f28:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f179f2c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f179f30:	3c013f80 */ 	lui	$at,0x3f80
/*  f179f34:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f179f38:	44819000 */ 	mtc1	$at,$f18
/*  f179f3c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f179f40:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f179f44:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f179f48:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f179f4c:	44050000 */ 	mfc1	$a1,$f0
/*  f179f50:	44060000 */ 	mfc1	$a2,$f0
/*  f179f54:	44070000 */ 	mfc1	$a3,$f0
/*  f179f58:	ac400dc0 */ 	sw	$zero,0xdc0($v0)
/*  f179f5c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f179f60:	24440840 */ 	addiu	$a0,$v0,0x840
/*  f179f64:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f179f68:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f179f6c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f179f70:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f179f74:	0fc3cdcb */ 	jal	func0f0f372c
/*  f179f78:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f179f7c:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f179f80:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f179f84:	3c017f1c */ 	lui	$at,%hi(var7f1b80d0)
/*  f179f88:	c42080d0 */ 	lwc1	$f0,%lo(var7f1b80d0)($at)
/*  f179f8c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f179f90:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179f94:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f179f98:	3c017f1c */ 	lui	$at,%hi(var7f1b80d4)
/*  f179f9c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f179fa0:	c42280d4 */ 	lwc1	$f2,%lo(var7f1b80d4)($at)
/*  f179fa4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f179fa8:	3c017f1c */ 	lui	$at,%hi(var7f1b80d8)
/*  f179fac:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f179fb0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f179fb4:	c42c80d8 */ 	lwc1	$f12,%lo(var7f1b80d8)($at)
/*  f179fb8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f179fbc:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f179fc0:	03191021 */ 	addu	$v0,$t8,$t9
/*  f179fc4:	3c017f1c */ 	lui	$at,%hi(var7f1b80dc)
/*  f179fc8:	e4400d50 */ 	swc1	$f0,0xd50($v0)
/*  f179fcc:	e4400d78 */ 	swc1	$f0,0xd78($v0)
/*  f179fd0:	e4420d54 */ 	swc1	$f2,0xd54($v0)
/*  f179fd4:	e4420d7c */ 	swc1	$f2,0xd7c($v0)
/*  f179fd8:	c42480dc */ 	lwc1	$f4,%lo(var7f1b80dc)($at)
/*  f179fdc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f179fe0:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f179fe4:	24080078 */ 	addiu	$t0,$zero,0x78
/*  f179fe8:	240a0008 */ 	addiu	$t2,$zero,0x8
/*  f179fec:	2401000f */ 	addiu	$at,$zero,0xf
/*  f179ff0:	ac490db8 */ 	sw	$t1,0xdb8($v0)
/*  f179ff4:	ac480db4 */ 	sw	$t0,0xdb4($v0)
/*  f179ff8:	a04a0840 */ 	sb	$t2,0x840($v0)
/*  f179ffc:	e44c0d64 */ 	swc1	$f12,0xd64($v0)
/*  f17a000:	e44c0d8c */ 	swc1	$f12,0xd8c($v0)
/*  f17a004:	14610003 */ 	bne	$v1,$at,.L0f17a014
/*  f17a008:	e4440d5c */ 	swc1	$f4,0xd5c($v0)
/*  f17a00c:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f17a010:	a04b0840 */ 	sb	$t3,0x840($v0)
.L0f17a014:
/*  f17a014:	00001025 */ 	or	$v0,$zero,$zero
.L0f17a018:
/*  f17a018:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17a01c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f17a020:	03e00008 */ 	jr	$ra
/*  f17a024:	00000000 */ 	nop
);
#endif

s32 menuhandlerMpCharacterBody(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		if (g_MpPlayers[g_MpPlayerNum].base.mpheadnum < mpGetNumHeads()) {
			if (!data->carousel.unk04) {
				g_MpPlayers[g_MpPlayerNum].base.mpheadnum = mpGetMpheadnumByMpbodynum(data->carousel.value);
			}
		}
		g_MpPlayers[g_MpPlayerNum].base.mpbodynum = data->carousel.value;
		func0f17b8f0();
		break;
	case MENUOP_CHECKPREFOCUSED:
		func0f179da4(operation, item, data,
				g_MpPlayers[g_MpPlayerNum].base.mpbodynum,
				g_MpPlayers[g_MpPlayerNum].base.mpheadnum, 1);
		return true;
	}

	return func0f179da4(operation, item, data,
			g_MpPlayers[g_MpPlayerNum].base.mpbodynum,
			g_MpPlayers[g_MpPlayerNum].base.mpheadnum, 1);
}

s32 menudialog0017a174(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[1]
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[2]) {
			union handlerdata data;
			menuhandlerMpCharacterBody(MENUOP_11, &dialog->items[2], &data);
		}
	}

	return 0;
}

s32 mpChallengesListHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	Gfx *gdl;
	struct menuitemrenderdata *renderdata;
	s32 challengeindex;
	s32 x;
	s32 y;
	s32 loopx;
	s32 maxplayers;
	s32 i;
	char *name;
	s32 size = 11;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mpGetAutoFocusedChallengeIndex(g_MpPlayerNum);
		break;
	case MENUOP_RENDER:
		maxplayers = 4;
		gdl = data->type19.gdl;
		renderdata = data->type19.renderdata2;
		challengeindex = data->list.unk04;

		if (IS4MB()) {
			maxplayers = 2;
		}

		x = renderdata->x + 10;
		y = renderdata->y + 1;

		gdl = func0f153628(gdl);

		name = mpChallengeGetNameWithArg(g_MpPlayerNum, challengeindex);

		gdl = textRenderProjected(gdl, &x, &y, name,
				g_FontHandelGothicSm1, g_FontHandelGothicSm2, renderdata->colour,
				viGetWidth(), viGetHeight(), 0, 0);

		gdl = func0f153780(gdl);

		gDPPipeSync(gdl++);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);

		func0f0b39c0(&gdl, &var800ab5a8[35], 2, 0, 2, 1, 0);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetTextureFilter(gdl++, G_TF_POINT);

		for (i = 0, loopx = 10; i < maxplayers; i++) {
			if (mpIsChallengeCompletedByPlayerWithNumPlayers2(g_MpPlayerNum, challengeindex, i + 1)) {
				gDPSetEnvColorViaWord(gdl++, 0xb2efff00 | (renderdata->colour & 0xff) * 255 / 256);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0x30407000 | (renderdata->colour & 0xff) * 255 / 256);
			}

			gDPSetCombineLERP(gdl++,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0,
					TEXEL0, 0, ENVIRONMENT, 0);

			gSPTextureRectangle(gdl++,
					((renderdata->x + loopx) << 2) * g_ScaleX,
					(renderdata->y + size) << 2,
					((renderdata->x + size + loopx) << 2) * g_ScaleX,
					(renderdata->y + size * 2) << 2,
					G_TX_RENDERTILE,
					0, 0x0160, 0x0400 / g_ScaleX, 0xfc00);

			loopx += 13;
		}

		return (s32) gdl;
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = 26;
		break;
	}

	return 0;
}

const char var7f1b7ea8[] = "Menu99 -> Calling Camera Module Start\n";
const char var7f1b7ed0[] = "Menu99 -> Calling Camera Module Finish\n";

char *mpMenuTextKills(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].kills);
	return g_StringPointer;
}

char *mpMenuTextDeaths(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].deaths);
	return g_StringPointer;
}

char *mpMenuTextGamesPlayed(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].gamesplayed);
	return g_StringPointer;
}

char *mpMenuTextGamesWon(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].gameswon);
	return g_StringPointer;
}

char *mpMenuTextGamesLost(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].gameslost);
	return g_StringPointer;
}

char *mpMenuTextHeadShots(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].headshots);
	return g_StringPointer;
}

char *mpMenuTextMedalAccuracy(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].accuracymedals);
	return g_StringPointer;
}

char *mpMenuTextMedalHeadShot(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].headshotmedals);
	return g_StringPointer;
}

char *mpMenuTextMedalKillMaster(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].killmastermedals);
	return g_StringPointer;
}

char *mpMenuTextMedalSurvivor(struct menuitem *item)
{ \
	sprintf(g_StringPointer, "%d\n", g_MpPlayers[g_MpPlayerNum].survivormedals);
	return g_StringPointer;
}

char *mpMenuTextAmmoUsed(struct menuitem *item)
{
	s32 value = g_MpPlayers[g_MpPlayerNum].ammoused;

	if (value > 100000) {
		value = value / 1000;

		if (value > 100000) {
			value = value / 1000;
			sprintf(g_StringPointer, "%dM\n", value);
		} else {
			sprintf(g_StringPointer, "%dK\n", value);
		}
	} else {
		sprintf(g_StringPointer, "%d\n", value);
	}

	return g_StringPointer;
}

char *mpMenuTextDistance(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s%s%.1fkm\n", "", "", g_MpPlayers[g_MpPlayerNum].distance / 10.0f);
	return g_StringPointer;
}

GLOBAL_ASM(
glabel mpMenuTextTime
/*  f17ab38:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17ab3c:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17ab40:	3c02800b */ 	lui	$v0,%hi(g_MpPlayers+0x68)
/*  f17ab44:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f17ab48:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f17ab4c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ab50:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f17ab54:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f17ab58:	8c42c820 */ 	lw	$v0,%lo(g_MpPlayers+0x68)($v0)
/*  f17ab5c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f17ab60:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f17ab64:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17ab68:	00004810 */ 	mfhi	$t1
/*  f17ab6c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f17ab70:	15000002 */ 	bnez	$t0,.L0f17ab7c
/*  f17ab74:	00000000 */ 	nop
/*  f17ab78:	0007000d */ 	break	0x7
.L0f17ab7c:
/*  f17ab7c:	3c017fff */ 	lui	$at,0x7fff
/*  f17ab80:	54400005 */ 	bnezl	$v0,.L0f17ab98
/*  f17ab84:	3421ffff */ 	ori	$at,$at,0xffff
/*  f17ab88:	3c027f1b */ 	lui	$v0,%hi(var7f1b7f48)
/*  f17ab8c:	10000052 */ 	b	.L0f17acd8
/*  f17ab90:	24427f48 */ 	addiu	$v0,$v0,%lo(var7f1b7f48)
/*  f17ab94:	3421ffff */ 	ori	$at,$at,0xffff
.L0f17ab98:
/*  f17ab98:	0041082b */ 	sltu	$at,$v0,$at
/*  f17ab9c:	14200004 */ 	bnez	$at,.L0f17abb0
/*  f17aba0:	00000000 */ 	nop
/*  f17aba4:	3c027f1b */ 	lui	$v0,%hi(var7f1b7f50)
/*  f17aba8:	1000004b */ 	b	.L0f17acd8
/*  f17abac:	24427f50 */ 	addiu	$v0,$v0,%lo(var7f1b7f50)
.L0f17abb0:
/*  f17abb0:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17abb4:	00001012 */ 	mflo	$v0
/*  f17abb8:	240a0018 */ 	addiu	$t2,$zero,0x18
/*  f17abbc:	15000002 */ 	bnez	$t0,.L0f17abc8
/*  f17abc0:	00000000 */ 	nop
/*  f17abc4:	0007000d */ 	break	0x7
.L0f17abc8:
/*  f17abc8:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17abcc:	00001812 */ 	mflo	$v1
/*  f17abd0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f68)
/*  f17abd4:	15000002 */ 	bnez	$t0,.L0f17abe0
/*  f17abd8:	00000000 */ 	nop
/*  f17abdc:	0007000d */ 	break	0x7
.L0f17abe0:
/*  f17abe0:	006a001a */ 	div	$zero,$v1,$t2
/*  f17abe4:	00003012 */ 	mflo	$a2
/*  f17abe8:	24a57f68 */ 	addiu	$a1,$a1,%lo(var7f1b7f68)
/*  f17abec:	15400002 */ 	bnez	$t2,.L0f17abf8
/*  f17abf0:	00000000 */ 	nop
/*  f17abf4:	0007000d */ 	break	0x7
.L0f17abf8:
/*  f17abf8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17abfc:	15410004 */ 	bne	$t2,$at,.L0f17ac10
/*  f17ac00:	3c018000 */ 	lui	$at,0x8000
/*  f17ac04:	14610002 */ 	bne	$v1,$at,.L0f17ac10
/*  f17ac08:	00000000 */ 	nop
/*  f17ac0c:	0006000d */ 	break	0x6
.L0f17ac10:
/*  f17ac10:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f17ac14:	14c0001a */ 	bnez	$a2,.L0f17ac80
/*  f17ac18:	00000000 */ 	nop
/*  f17ac1c:	006a001a */ 	div	$zero,$v1,$t2
/*  f17ac20:	00003010 */ 	mfhi	$a2
/*  f17ac24:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f17ac28:	3c057f1b */ 	lui	$a1,%hi(var7f1b7f58)
/*  f17ac2c:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17ac30:	00003810 */ 	mfhi	$a3
/*  f17ac34:	24a57f58 */ 	addiu	$a1,$a1,%lo(var7f1b7f58)
/*  f17ac38:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f17ac3c:	15400002 */ 	bnez	$t2,.L0f17ac48
/*  f17ac40:	00000000 */ 	nop
/*  f17ac44:	0007000d */ 	break	0x7
.L0f17ac48:
/*  f17ac48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ac4c:	15410004 */ 	bne	$t2,$at,.L0f17ac60
/*  f17ac50:	3c018000 */ 	lui	$at,0x8000
/*  f17ac54:	14610002 */ 	bne	$v1,$at,.L0f17ac60
/*  f17ac58:	00000000 */ 	nop
/*  f17ac5c:	0006000d */ 	break	0x6
.L0f17ac60:
/*  f17ac60:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f17ac64:	15000002 */ 	bnez	$t0,.L0f17ac70
/*  f17ac68:	00000000 */ 	nop
/*  f17ac6c:	0007000d */ 	break	0x7
.L0f17ac70:
/*  f17ac70:	0c004dad */ 	jal	sprintf
/*  f17ac74:	00000000 */ 	nop
/*  f17ac78:	10000015 */ 	b	.L0f17acd0
/*  f17ac7c:	00000000 */ 	nop
.L0f17ac80:
/*  f17ac80:	006a001a */ 	div	$zero,$v1,$t2
/*  f17ac84:	00003810 */ 	mfhi	$a3
/*  f17ac88:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f17ac8c:	15400002 */ 	bnez	$t2,.L0f17ac98
/*  f17ac90:	00000000 */ 	nop
/*  f17ac94:	0007000d */ 	break	0x7
.L0f17ac98:
/*  f17ac98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17ac9c:	15410004 */ 	bne	$t2,$at,.L0f17acb0
/*  f17aca0:	3c018000 */ 	lui	$at,0x8000
/*  f17aca4:	14610002 */ 	bne	$v1,$at,.L0f17acb0
/*  f17aca8:	00000000 */ 	nop
/*  f17acac:	0006000d */ 	break	0x6
.L0f17acb0:
/*  f17acb0:	0048001b */ 	divu	$zero,$v0,$t0
/*  f17acb4:	0000c010 */ 	mfhi	$t8
/*  f17acb8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f17acbc:	15000002 */ 	bnez	$t0,.L0f17acc8
/*  f17acc0:	00000000 */ 	nop
/*  f17acc4:	0007000d */ 	break	0x7
.L0f17acc8:
/*  f17acc8:	0c004dad */ 	jal	sprintf
/*  f17accc:	00000000 */ 	nop
.L0f17acd0:
/*  f17acd0:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f17acd4:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
.L0f17acd8:
/*  f17acd8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f17acdc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f17ace0:	03e00008 */ 	jr	$ra
/*  f17ace4:	00000000 */ 	nop
);

const char var7f1b7f48[] = "--:--\n";
const char var7f1b7f50[] = "==:==\n";
const char var7f1b7f58[] = "%d:%02d.%02d";
const char var7f1b7f68[] = "%d:%02d:%02d";

char *mpMenuTextAccuracy(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s%s%.1f%%", "", "", g_MpPlayers[g_MpPlayerNum].accuracy / 10.0f);
	return g_StringPointer;
}

void mpFormatDamageValue(char *dst, f32 damage)
{
	if (damage < 1000) {
		sprintf(dst, "%s%s%.1f", "", "", damage);
	} else if (damage < 10000) {
		sprintf(dst, "%s%s%.0f", "", "", damage);
	} else if (damage < 100000) {
		damage = damage / 1000;
		sprintf(dst, "%s%s%.1fK", "", "", damage);
	} else if (damage < 1000000) {
		damage = damage / 1000;
		sprintf(dst, "%s%s%.0fK", "", "", damage);
	} else if (damage < 10000000) {
		damage = damage / 1000;
		damage = damage / 1000;
		sprintf(dst, "%s%s%.1fM", "", "", damage);
	} else {
		damage = damage / 1000;
		damage = damage / 1000;
		sprintf(dst, "%s%s%.0fM", "", "", damage);
	}
}

char *mpMenuTextPainReceived(struct menuitem *item)
{
	mpFormatDamageValue(g_StringPointer, g_MpPlayers[g_MpPlayerNum].painreceived / 10.0f);
	return g_StringPointer;
}

char *mpMenuTextDamageDealt(struct menuitem *item)
{
	mpFormatDamageValue(g_StringPointer, g_MpPlayers[g_MpPlayerNum].damagedealt / 10.0f);
	return g_StringPointer;
}

GLOBAL_ASM(
glabel menuhandlerMpMedal
/*  f17b01c:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f17b020:	24010013 */ 	addiu	$at,$zero,0x13
/*  f17b024:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f17b028:	148100c8 */ 	bne	$a0,$at,.L0f17b34c
/*  f17b02c:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f17b030:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f17b034:	3c19e700 */ 	lui	$t9,0xe700
/*  f17b038:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17b03c:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f17b040:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f17b044:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f17b048:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f17b04c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f17b050:	add90000 */ 	sw	$t9,0x0($t6)
/*  f17b054:	8faa006c */ 	lw	$t2,0x6c($sp)
/*  f17b058:	358c1301 */ 	ori	$t4,$t4,0x1301
/*  f17b05c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f17b060:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f17b064:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f17b068:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f17b06c:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f17b070:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f17b074:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f17b078:	3c0aba00 */ 	lui	$t2,0xba00
/*  f17b07c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17b080:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f17b084:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f17b088:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f17b08c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f17b090:	354a1001 */ 	ori	$t2,$t2,0x1001
/*  f17b094:	3c0dba00 */ 	lui	$t5,0xba00
/*  f17b098:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17b09c:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f17b0a0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f17b0a4:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f17b0a8:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f17b0ac:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f17b0b0:	240e0c00 */ 	addiu	$t6,$zero,0xc00
/*  f17b0b4:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f17b0b8:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f17b0bc:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f17b0c0:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f17b0c4:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f17b0c8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17b0cc:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f17b0d0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17b0d4:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f17b0d8:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f17b0dc:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17b0e0:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f17b0e4:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f17b0e8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f17b0ec:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f17b0f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f17b0f4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f17b0f8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17b0fc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17b100:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f17b104:	00003825 */ 	or	$a3,$zero,$zero
/*  f17b108:	afa80068 */ 	sw	$t0,0x68($sp)
/*  f17b10c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f17b110:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f17b114:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f17b118:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f17b11c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f17b120:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f17b124:	afad006c */ 	sw	$t5,0x6c($sp)
/*  f17b128:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f17b12c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f17b130:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f17b134:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f17b138:	3c19fcff */ 	lui	$t9,0xfcff
/*  f17b13c:	3c0afffc */ 	lui	$t2,0xfffc
/*  f17b140:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17b144:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f17b148:	354af279 */ 	ori	$t2,$t2,0xf279
/*  f17b14c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f17b150:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17b154:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f17b158:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f17b15c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f17b160:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f17b164:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f17b168:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f17b16c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f17b170:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f17b174:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f17b178:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17b17c:	91c50001 */ 	lbu	$a1,0x1($t6)
/*  f17b180:	50a0000a */ 	beqzl	$a1,.L0f17b1ac
/*  f17b184:	3c05ff7f */ 	lui	$a1,0xff7f
/*  f17b188:	10a1000a */ 	beq	$a1,$at,.L0f17b1b4
/*  f17b18c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f17b190:	10a1000b */ 	beq	$a1,$at,.L0f17b1c0
/*  f17b194:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17b198:	50a1000d */ 	beql	$a1,$at,.L0f17b1d0
/*  f17b19c:	3c0500bf */ 	lui	$a1,0xbf
/*  f17b1a0:	1000000c */ 	b	.L0f17b1d4
/*  f17b1a4:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f17b1a8:	3c05ff7f */ 	lui	$a1,0xff7f
.L0f17b1ac:
/*  f17b1ac:	10000009 */ 	b	.L0f17b1d4
/*  f17b1b0:	34a57fff */ 	ori	$a1,$a1,0x7fff
.L0f17b1b4:
/*  f17b1b4:	3c05bfbf */ 	lui	$a1,0xbfbf
/*  f17b1b8:	10000006 */ 	b	.L0f17b1d4
/*  f17b1bc:	34a500ff */ 	ori	$a1,$a1,0xff
.L0f17b1c0:
/*  f17b1c0:	3c0500ff */ 	lui	$a1,0xff
/*  f17b1c4:	10000003 */ 	b	.L0f17b1d4
/*  f17b1c8:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f17b1cc:	3c0500bf */ 	lui	$a1,0xbf
.L0f17b1d0:
/*  f17b1d0:	34a5bfff */ 	ori	$a1,$a1,0xbfff
.L0f17b1d4:
/*  f17b1d4:	8d18000c */ 	lw	$t8,0xc($t0)
/*  f17b1d8:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f17b1dc:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f17b1e0:	331900ff */ 	andi	$t9,$t8,0xff
/*  f17b1e4:	01f90019 */ 	multu	$t7,$t9
/*  f17b1e8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f17b1ec:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f17b1f0:	00a16024 */ 	and	$t4,$a1,$at
/*  f17b1f4:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f17b1f8:	3c18fb00 */ 	lui	$t8,0xfb00
/*  f17b1fc:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f17b200:	01a01025 */ 	or	$v0,$t5,$zero
/*  f17b204:	3c068008 */ 	lui	$a2,%hi(g_ScaleX)
/*  f17b208:	24c6fac0 */ 	addiu	$a2,$a2,%lo(g_ScaleX)
/*  f17b20c:	00005012 */ 	mflo	$t2
/*  f17b210:	000a5a02 */ 	srl	$t3,$t2,0x8
/*  f17b214:	018b2825 */ 	or	$a1,$t4,$t3
/*  f17b218:	ada50004 */ 	sw	$a1,0x4($t5)
/*  f17b21c:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f17b220:	3c0cff37 */ 	lui	$t4,0xff37
/*  f17b224:	3c0afc12 */ 	lui	$t2,0xfc12
/*  f17b228:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f17b22c:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f17b230:	354a9a25 */ 	ori	$t2,$t2,0x9a25
/*  f17b234:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f17b238:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f17b23c:	adea0000 */ 	sw	$t2,0x0($t7)
/*  f17b240:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f17b244:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f17b248:	3c01e400 */ 	lui	$at,0xe400
/*  f17b24c:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17b250:	afad006c */ 	sw	$t5,0x6c($sp)
/*  f17b254:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f17b258:	01602025 */ 	or	$a0,$t3,$zero
/*  f17b25c:	25d80014 */ 	addiu	$t8,$t6,0x14
/*  f17b260:	00187880 */ 	sll	$t7,$t8,0x2
/*  f17b264:	01f90019 */ 	multu	$t7,$t9
/*  f17b268:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f17b26c:	25d8000b */ 	addiu	$t8,$t6,0xb
/*  f17b270:	00187880 */ 	sll	$t7,$t8,0x2
/*  f17b274:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f17b278:	00005012 */ 	mflo	$t2
/*  f17b27c:	314c0fff */ 	andi	$t4,$t2,0xfff
/*  f17b280:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f17b284:	01616825 */ 	or	$t5,$t3,$at
/*  f17b288:	01b95025 */ 	or	$t2,$t5,$t9
/*  f17b28c:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f17b290:	8d0c0000 */ 	lw	$t4,0x0($t0)
/*  f17b294:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f17b298:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*  f17b29c:	258b0009 */ 	addiu	$t3,$t4,0x9
/*  f17b2a0:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f17b2a4:	01d80019 */ 	multu	$t6,$t8
/*  f17b2a8:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f17b2ac:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f17b2b0:	240a0160 */ 	addiu	$t2,$zero,0x160
/*  f17b2b4:	00007812 */ 	mflo	$t7
/*  f17b2b8:	31ed0fff */ 	andi	$t5,$t7,0xfff
/*  f17b2bc:	000dcb00 */ 	sll	$t9,$t5,0xc
/*  f17b2c0:	032b7025 */ 	or	$t6,$t9,$t3
/*  f17b2c4:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f17b2c8:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f17b2cc:	3c0db400 */ 	lui	$t5,0xb400
/*  f17b2d0:	3c0bb300 */ 	lui	$t3,0xb300
/*  f17b2d4:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f17b2d8:	afaf006c */ 	sw	$t7,0x6c($sp)
/*  f17b2dc:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f17b2e0:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f17b2e4:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f17b2e8:	03001825 */ 	or	$v1,$t8,$zero
/*  f17b2ec:	24180400 */ 	addiu	$t8,$zero,0x400
/*  f17b2f0:	25990008 */ 	addiu	$t9,$t4,0x8
/*  f17b2f4:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f17b2f8:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*  f17b2fc:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f17b300:	01802025 */ 	or	$a0,$t4,$zero
/*  f17b304:	030e001a */ 	div	$zero,$t8,$t6
/*  f17b308:	00007812 */ 	mflo	$t7
/*  f17b30c:	31edffff */ 	andi	$t5,$t7,0xffff
/*  f17b310:	000d5400 */ 	sll	$t2,$t5,0x10
/*  f17b314:	354cfc00 */ 	ori	$t4,$t2,0xfc00
/*  f17b318:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*  f17b31c:	15c00002 */ 	bnez	$t6,.L0f17b328
/*  f17b320:	00000000 */ 	nop
/*  f17b324:	0007000d */ 	break	0x7
.L0f17b328:
/*  f17b328:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17b32c:	15c10004 */ 	bne	$t6,$at,.L0f17b340
/*  f17b330:	3c018000 */ 	lui	$at,0x8000
/*  f17b334:	17010002 */ 	bne	$t8,$at,.L0f17b340
/*  f17b338:	00000000 */ 	nop
/*  f17b33c:	0006000d */ 	break	0x6
.L0f17b340:
/*  f17b340:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f17b344:	10000003 */ 	b	.L0f17b354
/*  f17b348:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f17b34c:
/*  f17b34c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b350:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f17b354:
/*  f17b354:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f17b358:	03e00008 */ 	jr	$ra
/*  f17b35c:	00000000 */ 	nop
);

char *mpMenuTitleStatsForPlayerName(struct menudialog *dialog)
{
	// "Stats for %s"
	sprintf(g_StringPointer, langGet(L_MPMENU_145), g_MpPlayers[g_MpPlayerNum].base.name);
	return g_StringPointer;
}

s32 menuhandlerMpUsernamePassword(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpPlayers[g_MpPlayerNum].title != MPPLAYERTITLE_PERFECT) {
			return true;
		}
	}

	return 0;
}

struct menuitem g_MpSavePlayerMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_191, 0x00000000, NULL }, // "Your player file is always saved automatically."
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_192, 0x00000000, NULL }, // "Save a copy now?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_193, 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_194, 0x00000000, menuhandlerMpConfirmSaveChr }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_190, // "Confirm"
	g_MpSavePlayerMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpSaveSetupNameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_189, 0x00000000, NULL }, // "Enter a name for your game setup file:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandlerMpPlayerName },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSaveSetupNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_188, // "Game File Name"
	g_MpSaveSetupNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpSaveSetupExistsMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPWEAPONS_230, (u32)&mpMenuTextSetupName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_184, 0x00000000, NULL }, // "Do you want to save over your original game file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_185, 0x00000000, menuhandlerMpSaveSetupOverwrite }, // "Save Over Original"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_186, 0x00000000, menuhandlerMpSaveSetupCopy }, // "Save Copy"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_187, 0x00000000, NULL }, // "Do Not Save"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSaveSetupExistsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_183, // "Save Game Setup"
	g_MpSaveSetupExistsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpWeaponsMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00020090, L_MPMENU_174, 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000212, L_MPMENU_175, 0x00000000, NULL }, // "Current Weapon Setup:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_176, 0x00000000, menuhandlerMpWeaponSlot }, // "1:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_177, 0x00000001, menuhandlerMpWeaponSlot }, // "2:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_178, 0x00000002, menuhandlerMpWeaponSlot }, // "3:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_179, 0x00000003, menuhandlerMpWeaponSlot }, // "4:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_180, 0x00000004, menuhandlerMpWeaponSlot }, // "5:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU_181, 0x00000005, menuhandlerMpWeaponSlot }, // "6:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_182, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_173, // "Weapons"
	g_MpWeaponsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpQuickTeamWeaponsMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020090, L_MPMENU_174, 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU_176, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "1:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000002, L_MPMENU_177, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "2:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000002, L_MPMENU_178, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "3:"
	{ MENUITEMTYPE_LABEL,       3, 0x00000002, L_MPMENU_179, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "4:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000002, L_MPMENU_180, (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "5:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_182, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_173, // "Weapons"
	g_MpQuickTeamWeaponsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpPlayerOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_168, MPDISPLAYOPTION_HIGHLIGHTPICKUPS, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Pickups"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_169, MPDISPLAYOPTION_HIGHLIGHTPLAYERS, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Players"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_170, MPDISPLAYOPTION_HIGHLIGHTTEAMS,   menuhandlerMpDisplayOptionCheckbox }, // "Highlight Teams"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_171, MPDISPLAYOPTION_RADAR,            menuhandlerMpDisplayOptionCheckbox }, // "Radar"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_172, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_167, // "Options"
	g_MpPlayerOptionsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpControlMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU_200, 0x00000000,              menuhandlerMpControlStyle }, // "Control Style"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_201, OPTION_FORWARDPITCH,     menuhandlerMpControlCheckbox }, // "Reverse Pitch"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_202, OPTION_LOOKAHEAD,        menuhandlerMpControlCheckbox }, // "Look Ahead"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_203, OPTION_HEADROLL,         menuhandlerMpControlCheckbox }, // "Head Roll"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_204, OPTION_AUTOAIM,          menuhandlerMpControlCheckbox }, // "Auto-Aim"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU_205, 0x00000000,              menuhandlerMpAimControl }, // "Aim Control"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_206, OPTION_SIGHTONSCREEN,    menuhandlerMpControlCheckbox }, // "Sight on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_207, OPTION_ALWAYSSHOWTARGET, menuhandlerMpControlCheckbox }, // "Show Target"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_208, OPTION_SHOWZOOMRANGE,    menuhandlerMpControlCheckbox }, // "Show Zoom Range"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_209, OPTION_AMMOONSCREEN,     menuhandlerMpControlCheckbox }, // "Ammo on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_210, OPTION_SHOWGUNFUNCTION,  menuhandlerMpControlCheckbox }, // "Gun Function"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU_211, OPTION_PAINTBALL,        menuhandlerMpControlCheckbox }, // "Paintball"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000,    0x00000000,              NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_212, 0x00000000,              NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000,    0x00000000,              NULL },
};

struct menudialog g_MpControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_199, // "Control"
	g_MpControlMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpCompletedChallengesMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x00000078, 0x0000004d, mpChallengesListHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpCompletedChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_165, // "Completed Challenges"
	g_MpCompletedChallengesMenuItems,
	NULL,
	0x00000048,
	NULL,
};

char *mpMenuTextUsernamePassword(struct menuitem *item)
{
	// Phrases included here to assist people searching the code for them:
	// EnTROpIcDeCAy
	// ZeRo-Tau

	u8 username[15] = {
		'E' + 9 * 1,
		'n' + 9 * 2,
		'T' + 9 * 3,
		'R' + 9 * 4,
		'O' + 9 * 5,
		'p' + 9 * 6,
		'I' + 9 * 7,
		'c' + 9 * 8,
		'D' + 9 * 9,
		'e' + 9 * 10,
		'C' + 9 * 11,
		'A' + 9 * 12,
		'y' + 9 * 13,
		'\n' + 9 * 14,
		'\0' + 9 * 15,
	};

	u8 password[10] = {
		'Z' + 4 * 1,
		'e' + 4 * 2,
		'R' + 4 * 3,
		'o' + 4 * 4,
		'-' + 4 * 5,
		'T' + 4 * 6,
		'a' + 4 * 7,
		'u' + 4 * 8,
		'\n' + 4 * 9,
		'\0' + 4 * 10,
	};

	u32 stack;
	s32 i;

	if (item->param == 0) {
		for (i = 0; i < 15; i++) {
			g_StringPointer[i] = username[i] - i * 9 - 9;
		}
	} else {
		for (i = 0; i < 10; i++) {
			g_StringPointer[i] = password[i] - i * 4 - 4;
		}
	}

	return g_StringPointer;
}

struct menuitem g_MpPlayerStatsMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_146, (u32)&mpMenuTextKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_147, (u32)&mpMenuTextDeaths, NULL }, // "Deaths:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_148, (u32)&mpMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_149, (u32)&mpMenuTextHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_150, (u32)&mpMenuTextAmmoUsed, NULL }, // "Ammo Used:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_151, (u32)&mpMenuTextDamageDealt, NULL }, // "Damage Dealt:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_152, (u32)&mpMenuTextPainReceived, NULL }, // "Pain Received:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_153, (u32)&mpMenuTextGamesPlayed, NULL }, // "Games Played:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_154, (u32)&mpMenuTextGamesWon, NULL }, // "Games Won:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_155, (u32)&mpMenuTextGamesLost, NULL }, // "Games Lost:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_156, (u32)&mpMenuTextTime, NULL }, // "Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_157, (u32)&mpMenuTextDistance, NULL }, // "Distance:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU_158, 0x00000000, NULL }, // "Medals Won:"
	{ MENUITEMTYPE_LABEL,       2, 0x00200000, L_MPMENU_159, (u32)&mpMenuTextMedalAccuracy, menuhandlerMpMedal }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       1, 0x00200000, L_MPMENU_160, (u32)&mpMenuTextMedalHeadShot, menuhandlerMpMedal }, // "Head Shot:"
	{ MENUITEMTYPE_LABEL,       0, 0x00200000, L_MPMENU_161, (u32)&mpMenuTextMedalKillMaster, menuhandlerMpMedal }, // "KillMaster:"
	{ MENUITEMTYPE_LABEL,       3, 0x00200000, L_MPMENU_162, (u32)&mpMenuTextMedalSurvivor, menuhandlerMpMedal }, // "Survivor:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_163, 0x00000000, NULL }, // "Your Title:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextPlayerTitle, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_219, 0x00000000, menuhandlerMpUsernamePassword }, // "USERNAME:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS_220, 0x00000000, menuhandlerMpUsernamePassword }, // "PASSWORD:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_164, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsForPlayerName,
	g_MpPlayerStatsMenuItems,
	NULL,
	0x00000048,
	&g_MpCompletedChallengesMenuDialog,
};

u32 var80085448 = 0x00000300;
u32 var8008544c = 0x0400ff00;

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f17b4f8
.late_rodata
glabel var7f1b80f0
.word func0f17b4f8+0x34 # f17b52c
glabel var7f1b80f4
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b80f8
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b80fc
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8100
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8104
.word func0f17b4f8+0x214 # f17b70c
glabel var7f1b8108
.word func0f17b4f8+0x208 # f17b700
glabel var7f1b810c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8110
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8114
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8118
.word func0f17b4f8+0x48 # f17b540
glabel var7f1b811c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8120
.word func0f17b4f8+0x214 # f17b70c
glabel var7f1b8124
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8128
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b812c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8130
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8134
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8138
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b813c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8140
.word func0f17b4f8+0x1e8 # f17b6e0
glabel var7f1b8144
.word 0x3c23d70a
glabel var7f1b8148
.word 0xbe99999a
glabel var7f1b814c
.word 0x3c23d70a
.text
/*  f17b4f8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17b4fc:	248effff */ 	addiu	$t6,$a0,-1
/*  f17b500:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f17b504:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17b508:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17b50c:	102000c7 */ 	beqz	$at,.L0f17b82c
/*  f17b510:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f17b514:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17b518:	3c017f1c */ 	lui	$at,%hi(var7f1b80f0)
/*  f17b51c:	002e0821 */ 	addu	$at,$at,$t6
/*  f17b520:	8c2e80f0 */ 	lw	$t6,%lo(var7f1b80f0)($at)
/*  f17b524:	01c00008 */ 	jr	$t6
/*  f17b528:	00000000 */ 	nop
/*  f17b52c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b530:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17b534:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17b538:	100000bc */ 	b	.L0f17b82c
/*  f17b53c:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f17b540:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f17b544:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f17b548:	3c017f1c */ 	lui	$at,%hi(var7f1b8144)
/*  f17b54c:	c4248144 */ 	lwc1	$f4,%lo(var7f1b8144)($at)
/*  f17b550:	3c01800a */ 	lui	$at,%hi(g_Vars+0x10)
/*  f17b554:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f17b558:	c4269fc4 */ 	lwc1	$f6,%lo(g_Vars+0x10)($at)
/*  f17b55c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17b560:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17b564:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17b568:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f17b56c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17b570:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f17b574:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17b578:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f17b57c:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f17b580:	03191821 */ 	addu	$v1,$t8,$t9
/*  f17b584:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f17b588:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f17b58c:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f17b590:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b594:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f17b598:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f17b59c:	0062082a */ 	slt	$at,$v1,$v0
/*  f17b5a0:	1020001a */ 	beqz	$at,.L0f17b60c
/*  f17b5a4:	00000000 */ 	nop
/*  f17b5a8:	0fc62ecb */ 	jal	mpGetHeadId
/*  f17b5ac:	306400ff */ 	andi	$a0,$v1,0xff
/*  f17b5b0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f17b5b4:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f17b5b8:	3c0a800a */ 	lui	$t2,%hi(g_Menus)
/*  f17b5bc:	254ae000 */ 	addiu	$t2,$t2,%lo(g_Menus)
/*  f17b5c0:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f17b5c4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17b5c8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17b5cc:	01284821 */ 	addu	$t1,$t1,$t0
/*  f17b5d0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17b5d4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17b5d8:	00094900 */ 	sll	$t1,$t1,0x4
/*  f17b5dc:	00025880 */ 	sll	$t3,$v0,0x2
/*  f17b5e0:	01625821 */ 	addu	$t3,$t3,$v0
/*  f17b5e4:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f17b5e8:	906d0df1 */ 	lbu	$t5,0xdf1($v1)
/*  f17b5ec:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17b5f0:	3c0c8008 */ 	lui	$t4,%hi(g_Bodies+0x2)
/*  f17b5f4:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17b5f8:	958ccf06 */ 	lhu	$t4,%lo(g_Bodies+0x2)($t4)
/*  f17b5fc:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f17b600:	a06e0df1 */ 	sb	$t6,0xdf1($v1)
/*  f17b604:	1000002e */ 	b	.L0f17b6c0
/*  f17b608:	ac6c084c */ 	sw	$t4,0x84c($v1)
.L0f17b60c:
/*  f17b60c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b610:	00000000 */ 	nop
/*  f17b614:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f17b618:	0fc52a7e */ 	jal	func0f14a9f8
/*  f17b61c:	01e22023 */ 	subu	$a0,$t7,$v0
/*  f17b620:	0fc62ed9 */ 	jal	mpGetBeauHeadId
/*  f17b624:	304400ff */ 	andi	$a0,$v0,0xff
/*  f17b628:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f17b62c:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f17b630:	3c08800a */ 	lui	$t0,%hi(g_Menus)
/*  f17b634:	2508e000 */ 	addiu	$t0,$t0,%lo(g_Menus)
/*  f17b638:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17b63c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17b640:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17b644:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17b648:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17b64c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17b650:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17b654:	00024880 */ 	sll	$t1,$v0,0x2
/*  f17b658:	01224821 */ 	addu	$t1,$t1,$v0
/*  f17b65c:	03281821 */ 	addu	$v1,$t9,$t0
/*  f17b660:	906c0df1 */ 	lbu	$t4,0xdf1($v1)
/*  f17b664:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17b668:	3c0a8008 */ 	lui	$t2,%hi(g_Bodies+0x2)
/*  f17b66c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17b670:	954acf06 */ 	lhu	$t2,%lo(g_Bodies+0x2)($t2)
/*  f17b674:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f17b678:	a06d0df1 */ 	sb	$t5,0xdf1($v1)
/*  f17b67c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b680:	ac6a084c */ 	sw	$t2,0x84c($v1)
/*  f17b684:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17b688:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17b68c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f17b690:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f17b694:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17b698:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b69c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17b6a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b6a4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17b6a8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b6ac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17b6b0:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f17b6b4:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f17b6b8:	03224023 */ 	subu	$t0,$t9,$v0
/*  f17b6bc:	a0680df0 */ 	sb	$t0,0xdf0($v1)
.L0f17b6c0:
/*  f17b6c0:	3c0141f0 */ 	lui	$at,0x41f0
/*  f17b6c4:	44818000 */ 	mtc1	$at,$f16
/*  f17b6c8:	3c098008 */ 	lui	$t1,%hi(var80085448)
/*  f17b6cc:	25295448 */ 	addiu	$t1,$t1,%lo(var80085448)
/*  f17b6d0:	ac600db4 */ 	sw	$zero,0xdb4($v1)
/*  f17b6d4:	ac690df4 */ 	sw	$t1,0xdf4($v1)
/*  f17b6d8:	10000054 */ 	b	.L0f17b82c
/*  f17b6dc:	e4700d94 */ 	swc1	$f16,0xd94($v1)
/*  f17b6e0:	0fc62ed2 */ 	jal	mpGetHeadRequiredFeature
/*  f17b6e4:	90c40003 */ 	lbu	$a0,0x3($a2)
/*  f17b6e8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17b6ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f17b6f0:	5440004f */ 	bnezl	$v0,.L0f17b830
/*  f17b6f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b6f8:	1000004d */ 	b	.L0f17b830
/*  f17b6fc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17b700:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f17b704:	10000049 */ 	b	.L0f17b82c
/*  f17b708:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f17b70c:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f17b710:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f17b714:	3c01800a */ 	lui	$at,%hi(g_Menus+0x840)
/*  f17b718:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f17b71c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17b720:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17b724:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17b728:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17b72c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17b730:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17b734:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17b738:	002d0821 */ 	addu	$at,$at,$t5
/*  f17b73c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b740:	a02be840 */ 	sb	$t3,%lo(g_Menus+0x840)($at)
/*  f17b744:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17b748:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17b74c:	44800000 */ 	mtc1	$zero,$f0
/*  f17b750:	3c013f80 */ 	lui	$at,0x3f80
/*  f17b754:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17b758:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b75c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17b760:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b764:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17b768:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b76c:	44819000 */ 	mtc1	$at,$f18
/*  f17b770:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17b774:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f17b778:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f17b77c:	25f80840 */ 	addiu	$t8,$t7,0x840
/*  f17b780:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f17b784:	44050000 */ 	mfc1	$a1,$f0
/*  f17b788:	44060000 */ 	mfc1	$a2,$f0
/*  f17b78c:	44070000 */ 	mfc1	$a3,$f0
/*  f17b790:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f17b794:	03192021 */ 	addu	$a0,$t8,$t9
/*  f17b798:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f17b79c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f17b7a0:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f17b7a4:	0fc3cdcb */ 	jal	func0f0f372c
/*  f17b7a8:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f17b7ac:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17b7b0:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f17b7b4:	3c017f1c */ 	lui	$at,%hi(var7f1b8148)
/*  f17b7b8:	3c0c800a */ 	lui	$t4,%hi(g_Menus)
/*  f17b7bc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f17b7c0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17b7c4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f17b7c8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17b7cc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17b7d0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17b7d4:	c4228148 */ 	lwc1	$f2,%lo(var7f1b8148)($at)
/*  f17b7d8:	44800000 */ 	mtc1	$zero,$f0
/*  f17b7dc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f17b7e0:	258ce000 */ 	addiu	$t4,$t4,%lo(g_Menus)
/*  f17b7e4:	014c1821 */ 	addu	$v1,$t2,$t4
/*  f17b7e8:	3c01c040 */ 	lui	$at,0xc040
/*  f17b7ec:	44812000 */ 	mtc1	$at,$f4
/*  f17b7f0:	3c017f1c */ 	lui	$at,%hi(var7f1b814c)
/*  f17b7f4:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f17b7f8:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f17b7fc:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f17b800:	e4640d7c */ 	swc1	$f4,0xd7c($v1)
/*  f17b804:	c426814c */ 	lwc1	$f6,%lo(var7f1b814c)($at)
/*  f17b808:	3c013f80 */ 	lui	$at,0x3f80
/*  f17b80c:	44815000 */ 	mtc1	$at,$f10
/*  f17b810:	3c0141f0 */ 	lui	$at,0x41f0
/*  f17b814:	44814000 */ 	mtc1	$at,$f8
/*  f17b818:	e4620d64 */ 	swc1	$f2,0xd64($v1)
/*  f17b81c:	e4620d8c */ 	swc1	$f2,0xd8c($v1)
/*  f17b820:	e4660d5c */ 	swc1	$f6,0xd5c($v1)
/*  f17b824:	e46a0d84 */ 	swc1	$f10,0xd84($v1)
/*  f17b828:	e4680d94 */ 	swc1	$f8,0xd94($v1)
.L0f17b82c:
/*  f17b82c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17b830:
/*  f17b830:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17b834:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f17b838:	03e00008 */ 	jr	$ra
/*  f17b83c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f17b4f8
.late_rodata
glabel var7f1b80f0
.word func0f17b4f8+0x34 # f17b52c
glabel var7f1b80f4
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b80f8
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b80fc
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8100
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8104
.word func0f17b4f8+0x214 # f17b70c
glabel var7f1b8108
.word func0f17b4f8+0x208 # f17b700
glabel var7f1b810c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8110
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8114
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8118
.word func0f17b4f8+0x48 # f17b540
glabel var7f1b811c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8120
.word func0f17b4f8+0x214 # f17b70c
glabel var7f1b8124
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8128
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b812c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8130
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8134
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8138
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b813c
.word func0f17b4f8+0x334 # f17b82c
glabel var7f1b8140
.word func0f17b4f8+0x1e8 # f17b6e0
glabel var7f1b8144
.word 0x3c23d70a
glabel var7f1b8148
.word 0xbe99999a
glabel var7f1b814c
.word 0x3c23d70a
.text
/*  f17b4f8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17b4fc:	248effff */ 	addiu	$t6,$a0,-1
/*  f17b500:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f17b504:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17b508:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17b50c:	102000c7 */ 	beqz	$at,.L0f17b82c
/*  f17b510:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f17b514:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17b518:	3c017f1c */ 	lui	$at,%hi(var7f1b80f0)
/*  f17b51c:	002e0821 */ 	addu	$at,$at,$t6
/*  f17b520:	8c2e80f0 */ 	lw	$t6,%lo(var7f1b80f0)($at)
/*  f17b524:	01c00008 */ 	jr	$t6
/*  f17b528:	00000000 */ 	nop
/*  f17b52c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b530:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f17b534:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f17b538:	100000bc */ 	b	.L0f17b82c
/*  f17b53c:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f17b540:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f17b544:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f17b548:	3c017f1c */ 	lui	$at,%hi(var7f1b8144)
/*  f17b54c:	c4248144 */ 	lwc1	$f4,%lo(var7f1b8144)($at)
/*  f17b550:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4)
/*  f17b554:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f17b558:	c4269fc4 */ 	lwc1	$f6,%lo(g_Vars+0x4)($at)
/*  f17b55c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17b560:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17b564:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17b568:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f17b56c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17b570:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f17b574:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17b578:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f17b57c:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f17b580:	03191821 */ 	addu	$v1,$t8,$t9
/*  f17b584:	c46a0d64 */ 	lwc1	$f10,0xd64($v1)
/*  f17b588:	46085000 */ 	add.s	$f0,$f10,$f8
/*  f17b58c:	e4600d8c */ 	swc1	$f0,0xd8c($v1)
/*  f17b590:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b594:	e4600d64 */ 	swc1	$f0,0xd64($v1)
/*  f17b598:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f17b59c:	0062082a */ 	slt	$at,$v1,$v0
/*  f17b5a0:	1020001a */ 	beqz	$at,.L0f17b60c
/*  f17b5a4:	00000000 */ 	nop
/*  f17b5a8:	0fc62ecb */ 	jal	mpGetHeadId
/*  f17b5ac:	306400ff */ 	andi	$a0,$v1,0xff
/*  f17b5b0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f17b5b4:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f17b5b8:	3c0a800a */ 	lui	$t2,%hi(g_Menus)
/*  f17b5bc:	254ae000 */ 	addiu	$t2,$t2,%lo(g_Menus)
/*  f17b5c0:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f17b5c4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17b5c8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17b5cc:	01284821 */ 	addu	$t1,$t1,$t0
/*  f17b5d0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17b5d4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17b5d8:	00094900 */ 	sll	$t1,$t1,0x4
/*  f17b5dc:	00025880 */ 	sll	$t3,$v0,0x2
/*  f17b5e0:	01625821 */ 	addu	$t3,$t3,$v0
/*  f17b5e4:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f17b5e8:	906d0df1 */ 	lbu	$t5,0xdf1($v1)
/*  f17b5ec:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17b5f0:	3c0c8008 */ 	lui	$t4,%hi(g_Bodies+0x2)
/*  f17b5f4:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17b5f8:	958ccf06 */ 	lhu	$t4,%lo(g_Bodies+0x2)($t4)
/*  f17b5fc:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f17b600:	a06e0df1 */ 	sb	$t6,0xdf1($v1)
/*  f17b604:	1000002e */ 	b	.L0f17b6c0
/*  f17b608:	ac6c084c */ 	sw	$t4,0x84c($v1)
.L0f17b60c:
/*  f17b60c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b610:	00000000 */ 	nop
/*  f17b614:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f17b618:	0fc52a7e */ 	jal	func0f14a9f8
/*  f17b61c:	01e22023 */ 	subu	$a0,$t7,$v0
/*  f17b620:	0fc62ed9 */ 	jal	mpGetBeauHeadId
/*  f17b624:	304400ff */ 	andi	$a0,$v0,0xff
/*  f17b628:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f17b62c:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f17b630:	3c08800a */ 	lui	$t0,%hi(g_Menus)
/*  f17b634:	2508e000 */ 	addiu	$t0,$t0,%lo(g_Menus)
/*  f17b638:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17b63c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17b640:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17b644:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17b648:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17b64c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17b650:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17b654:	00024880 */ 	sll	$t1,$v0,0x2
/*  f17b658:	01224821 */ 	addu	$t1,$t1,$v0
/*  f17b65c:	03281821 */ 	addu	$v1,$t9,$t0
/*  f17b660:	906c0df1 */ 	lbu	$t4,0xdf1($v1)
/*  f17b664:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17b668:	3c0a8008 */ 	lui	$t2,%hi(g_Bodies+0x2)
/*  f17b66c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17b670:	954acf06 */ 	lhu	$t2,%lo(g_Bodies+0x2)($t2)
/*  f17b674:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f17b678:	a06d0df1 */ 	sb	$t5,0xdf1($v1)
/*  f17b67c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b680:	ac6a084c */ 	sw	$t2,0x84c($v1)
/*  f17b684:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17b688:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17b68c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f17b690:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f17b694:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17b698:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b69c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17b6a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b6a4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17b6a8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b6ac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17b6b0:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f17b6b4:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f17b6b8:	03224023 */ 	subu	$t0,$t9,$v0
/*  f17b6bc:	a0680df0 */ 	sb	$t0,0xdf0($v1)
.L0f17b6c0:
/*  f17b6c0:	3c0141f0 */ 	lui	$at,0x41f0
/*  f17b6c4:	44818000 */ 	mtc1	$at,$f16
/*  f17b6c8:	3c098008 */ 	lui	$t1,%hi(var80085448)
/*  f17b6cc:	25295448 */ 	addiu	$t1,$t1,%lo(var80085448)
/*  f17b6d0:	ac600db4 */ 	sw	$zero,0xdb4($v1)
/*  f17b6d4:	ac690df4 */ 	sw	$t1,0xdf4($v1)
/*  f17b6d8:	10000054 */ 	b	.L0f17b82c
/*  f17b6dc:	e4700d94 */ 	swc1	$f16,0xd94($v1)
/*  f17b6e0:	0fc62ed2 */ 	jal	mpGetHeadRequiredFeature
/*  f17b6e4:	90c40003 */ 	lbu	$a0,0x3($a2)
/*  f17b6e8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17b6ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f17b6f0:	5440004f */ 	bnezl	$v0,.L0f17b830
/*  f17b6f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f17b6f8:	1000004d */ 	b	.L0f17b830
/*  f17b6fc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17b700:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f17b704:	10000049 */ 	b	.L0f17b82c
/*  f17b708:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f17b70c:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f17b710:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f17b714:	3c01800a */ 	lui	$at,%hi(g_Menus+0x840)
/*  f17b718:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f17b71c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17b720:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17b724:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17b728:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17b72c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17b730:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17b734:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17b738:	002d0821 */ 	addu	$at,$at,$t5
/*  f17b73c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f17b740:	a02be840 */ 	sb	$t3,%lo(g_Menus+0x840)($at)
/*  f17b744:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17b748:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17b74c:	44800000 */ 	mtc1	$zero,$f0
/*  f17b750:	3c013f80 */ 	lui	$at,0x3f80
/*  f17b754:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17b758:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b75c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17b760:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17b764:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17b768:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17b76c:	44819000 */ 	mtc1	$at,$f18
/*  f17b770:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17b774:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f17b778:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f17b77c:	25f80840 */ 	addiu	$t8,$t7,0x840
/*  f17b780:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f17b784:	44050000 */ 	mfc1	$a1,$f0
/*  f17b788:	44060000 */ 	mfc1	$a2,$f0
/*  f17b78c:	44070000 */ 	mfc1	$a3,$f0
/*  f17b790:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f17b794:	03192021 */ 	addu	$a0,$t8,$t9
/*  f17b798:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f17b79c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f17b7a0:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f17b7a4:	0fc3cdcb */ 	jal	func0f0f372c
/*  f17b7a8:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f17b7ac:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17b7b0:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f17b7b4:	3c017f1c */ 	lui	$at,%hi(var7f1b8148)
/*  f17b7b8:	3c0c800a */ 	lui	$t4,%hi(g_Menus)
/*  f17b7bc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f17b7c0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17b7c4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f17b7c8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17b7cc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17b7d0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17b7d4:	c4228148 */ 	lwc1	$f2,%lo(var7f1b8148)($at)
/*  f17b7d8:	44800000 */ 	mtc1	$zero,$f0
/*  f17b7dc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f17b7e0:	258ce000 */ 	addiu	$t4,$t4,%lo(g_Menus)
/*  f17b7e4:	014c1821 */ 	addu	$v1,$t2,$t4
/*  f17b7e8:	3c01c040 */ 	lui	$at,0xc040
/*  f17b7ec:	44812000 */ 	mtc1	$at,$f4
/*  f17b7f0:	3c017f1c */ 	lui	$at,%hi(var7f1b814c)
/*  f17b7f4:	e4600d50 */ 	swc1	$f0,0xd50($v1)
/*  f17b7f8:	e4600d54 */ 	swc1	$f0,0xd54($v1)
/*  f17b7fc:	e4600d78 */ 	swc1	$f0,0xd78($v1)
/*  f17b800:	e4640d7c */ 	swc1	$f4,0xd7c($v1)
/*  f17b804:	c426814c */ 	lwc1	$f6,%lo(var7f1b814c)($at)
/*  f17b808:	3c013f80 */ 	lui	$at,0x3f80
/*  f17b80c:	44815000 */ 	mtc1	$at,$f10
/*  f17b810:	3c0141f0 */ 	lui	$at,0x41f0
/*  f17b814:	44814000 */ 	mtc1	$at,$f8
/*  f17b818:	e4620d64 */ 	swc1	$f2,0xd64($v1)
/*  f17b81c:	e4620d8c */ 	swc1	$f2,0xd8c($v1)
/*  f17b820:	e4660d5c */ 	swc1	$f6,0xd5c($v1)
/*  f17b824:	e46a0d84 */ 	swc1	$f10,0xd84($v1)
/*  f17b828:	e4680d94 */ 	swc1	$f8,0xd94($v1)
.L0f17b82c:
/*  f17b82c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17b830:
/*  f17b830:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17b834:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f17b838:	03e00008 */ 	jr	$ra
/*  f17b83c:	00000000 */ 	nop
);
#endif

s32 menuhandlerMpCharacterHead(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_MpPlayers[g_MpPlayerNum].base.mpheadnum = data->carousel.value;
	}

	return func0f17b4f8(operation, item, data, g_MpPlayers[g_MpPlayerNum].base.mpheadnum, 1);
}

char *mpMenuTextBodyName(struct menuitem *item)
{
	return mpGetBodyName(g_MpPlayers[g_MpPlayerNum].base.mpbodynum);
}

void func0f17b8f0(void)
{
	func0f0f139c(g_MpCharacterMenuItems, -0.4f);
}

GLOBAL_ASM(
glabel menuhandler0017b91c
/*  f17b91c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f17b920:	24010011 */ 	addiu	$at,$zero,0x11
/*  f17b924:	10810006 */ 	beq	$a0,$at,.L0f17b940
/*  f17b928:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f17b92c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f17b930:	10810034 */ 	beq	$a0,$at,.L0f17ba04
/*  f17b934:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f17b938:	03e00008 */ 	jr	$ra
/*  f17b93c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17b940:
/*  f17b940:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f17b944:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f17b948:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f17b94c:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f17b950:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f17b954:	00047080 */ 	sll	$t6,$a0,0x2
/*  f17b958:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f17b95c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f17b960:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f17b964:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f17b968:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f17b96c:	00001825 */ 	or	$v1,$zero,$zero
/*  f17b970:	1138001a */ 	beq	$t1,$t8,.L0f17b9dc
/*  f17b974:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f17b978:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f17b97c:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f17b980:	00f92821 */ 	addu	$a1,$a3,$t9
/*  f17b984:	90ab0000 */ 	lbu	$t3,0x0($a1)
/*  f17b988:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17b98c:	240a000b */ 	addiu	$t2,$zero,0xb
/*  f17b990:	51600013 */ 	beqzl	$t3,.L0f17b9e0
/*  f17b994:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b998:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f17b99c:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17b9a0:
/*  f17b9a0:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f17b9a4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17b9a8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17b9ac:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17b9b0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f17b9b4:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f17b9b8:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f17b9bc:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f17b9c0:	93040000 */ 	lbu	$a0,0x0($t8)
/*  f17b9c4:	51240006 */ 	beql	$t1,$a0,.L0f17b9e0
/*  f17b9c8:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b9cc:	50800004 */ 	beqzl	$a0,.L0f17b9e0
/*  f17b9d0:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b9d4:	546afff2 */ 	bnel	$v1,$t2,.L0f17b9a0
/*  f17b9d8:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17b9dc:
/*  f17b9dc:	2861000b */ 	slti	$at,$v1,0xb
.L0f17b9e0:
/*  f17b9e0:	10200032 */ 	beqz	$at,.L0f17baac
/*  f17b9e4:	00433021 */ 	addu	$a2,$v0,$v1
.L0f17b9e8:
/*  f17b9e8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17b9ec:	2861000b */ 	slti	$at,$v1,0xb
/*  f17b9f0:	a0c00000 */ 	sb	$zero,0x0($a2)
/*  f17b9f4:	1420fffc */ 	bnez	$at,.L0f17b9e8
/*  f17b9f8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17b9fc:	03e00008 */ 	jr	$ra
/*  f17ba00:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ba04:
/*  f17ba04:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f17ba08:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f17ba0c:	00001825 */ 	or	$v1,$zero,$zero
/*  f17ba10:	13200014 */ 	beqz	$t9,.L0f17ba64
/*  f17ba14:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f17ba18:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f17ba1c:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f17ba20:	3c0e800b */ 	lui	$t6,%hi(g_MpPlayers)
/*  f17ba24:	25cec7b8 */ 	addiu	$t6,$t6,%lo(g_MpPlayers)
/*  f17ba28:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f17ba2c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17ba30:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f17ba34:	018e2021 */ 	addu	$a0,$t4,$t6
/*  f17ba38:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17ba3c:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f17ba40:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17ba44:
/*  f17ba44:	2861000b */ 	slti	$at,$v1,0xb
/*  f17ba48:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f17ba4c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17ba50:	10200004 */ 	beqz	$at,.L0f17ba64
/*  f17ba54:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17ba58:	90c50000 */ 	lbu	$a1,0x0($a2)
/*  f17ba5c:	54a0fff9 */ 	bnezl	$a1,.L0f17ba44
/*  f17ba60:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17ba64:
/*  f17ba64:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f17ba68:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f17ba6c:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f17ba70:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f17ba74:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f17ba78:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f17ba7c:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f17ba80:	03232021 */ 	addu	$a0,$t9,$v1
/*  f17ba84:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17ba88:	2861000b */ 	slti	$at,$v1,0xb
/*  f17ba8c:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f17ba90:	10200006 */ 	beqz	$at,.L0f17baac
/*  f17ba94:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17ba98:
/*  f17ba98:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17ba9c:	2861000b */ 	slti	$at,$v1,0xb
/*  f17baa0:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f17baa4:	1420fffc */ 	bnez	$at,.L0f17ba98
/*  f17baa8:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17baac:
/*  f17baac:	03e00008 */ 	jr	$ra
/*  f17bab0:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel menuhandler0017bab4
.late_rodata
glabel var7f1b8150
.word menuhandler0017bab4+0x38 # f17baec
glabel var7f1b8154
.word menuhandler0017bab4+0x200 # f17bcb4
glabel var7f1b8158
.word menuhandler0017bab4+0x68 # f17bb1c
glabel var7f1b815c
.word menuhandler0017bab4+0x228 # f17bcdc
glabel var7f1b8160
.word menuhandler0017bab4+0x26c # f17bd20
glabel var7f1b8164
.word menuhandler0017bab4+0x100 # f17bbb4
glabel var7f1b8168
.word menuhandler0017bab4+0x1f0 # f17bca4
glabel var7f1b816c
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b8170
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b8174
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b8178
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b817c
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b8180
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b8184
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b8188
.word menuhandler0017bab4+0x364 # f17be18
glabel var7f1b818c
.word menuhandler0017bab4+0x2cc # f17bd80
.text
/*  f17bab4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17bab8:	248fffff */ 	addiu	$t7,$a0,-1
/*  f17babc:	2de10010 */ 	sltiu	$at,$t7,0x10
/*  f17bac0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17bac4:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f17bac8:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17bacc:	102000d2 */ 	beqz	$at,.L0f17be18
/*  f17bad0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f17bad4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17bad8:	3c017f1c */ 	lui	$at,%hi(var7f1b8150)
/*  f17badc:	002f0821 */ 	addu	$at,$at,$t7
/*  f17bae0:	8c2f8150 */ 	lw	$t7,%lo(var7f1b8150)($at)
/*  f17bae4:	01e00008 */ 	jr	$t7
/*  f17bae8:	00000000 */ 	nop
/*  f17baec:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17baf0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17baf4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17baf8:	3c038007 */ 	lui	$v1,%hi(g_FileLists+0x4)
/*  f17bafc:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f17bb00:	8c635bc4 */ 	lw	$v1,%lo(g_FileLists+0x4)($v1)
/*  f17bb04:	506000c5 */ 	beqzl	$v1,.L0f17be1c
/*  f17bb08:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bb0c:	847902d0 */ 	lh	$t9,0x2d0($v1)
/*  f17bb10:	00594021 */ 	addu	$t0,$v0,$t9
/*  f17bb14:	100000c0 */ 	b	.L0f17be18
/*  f17bb18:	ace80000 */ 	sw	$t0,0x0($a3)
/*  f17bb1c:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bb20:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bb24:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bb28:	3c098007 */ 	lui	$t1,%hi(g_FileLists+0x4)
/*  f17bb2c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f17bb30:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17bb34:	10200005 */ 	beqz	$at,.L0f17bb4c
/*  f17bb38:	00000000 */ 	nop
/*  f17bb3c:	0fc63719 */ 	jal	mpGetPresetNameBySlot
/*  f17bb40:	00602025 */ 	or	$a0,$v1,$zero
/*  f17bb44:	100000b6 */ 	b	.L0f17be20
/*  f17bb48:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17bb4c:
/*  f17bb4c:	8d295bc4 */ 	lw	$t1,%lo(g_FileLists+0x4)($t1)
/*  f17bb50:	512000b2 */ 	beqzl	$t1,.L0f17be1c
/*  f17bb54:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bb58:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bb5c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bb60:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bb64:	3c0a8007 */ 	lui	$t2,%hi(g_FileLists+0x4)
/*  f17bb68:	8d4a5bc4 */ 	lw	$t2,%lo(g_FileLists+0x4)($t2)
/*  f17bb6c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f17bb70:	00027080 */ 	sll	$t6,$v0,0x2
/*  f17bb74:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17bb78:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f17bb7c:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f17bb80:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f17bb84:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17bb88:	000e7823 */ 	negu	$t7,$t6
/*  f17bb8c:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f17bb90:	01af2021 */ 	addu	$a0,$t5,$t7
/*  f17bb94:	3c058007 */ 	lui	$a1,%hi(g_StringPointer)
/*  f17bb98:	8ca51440 */ 	lw	$a1,%lo(g_StringPointer)($a1)
/*  f17bb9c:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f17bba0:	0fc35593 */ 	jal	func0f0d564c
/*  f17bba4:	00003025 */ 	or	$a2,$zero,$zero
/*  f17bba8:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f17bbac:	1000009b */ 	b	.L0f17be1c
/*  f17bbb0:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f17bbb4:	0fc5fe8a */ 	jal	func0f17fa28
/*  f17bbb8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bbbc:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bbc0:	00000000 */ 	nop
/*  f17bbc4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bbc8:	3c188007 */ 	lui	$t8,%hi(g_FileLists+0x4)
/*  f17bbcc:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f17bbd0:	0062082b */ 	sltu	$at,$v1,$v0
/*  f17bbd4:	10200005 */ 	beqz	$at,.L0f17bbec
/*  f17bbd8:	00000000 */ 	nop
/*  f17bbdc:	0fc637b1 */ 	jal	func0f18dec4
/*  f17bbe0:	00602025 */ 	or	$a0,$v1,$zero
/*  f17bbe4:	1000001c */ 	b	.L0f17bc58
/*  f17bbe8:	8faf0034 */ 	lw	$t7,0x34($sp)
.L0f17bbec:
/*  f17bbec:	8f185bc4 */ 	lw	$t8,%lo(g_FileLists+0x4)($t8)
/*  f17bbf0:	53000019 */ 	beqzl	$t8,.L0f17bc58
/*  f17bbf4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f17bbf8:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bbfc:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bc00:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bc04:	3c198007 */ 	lui	$t9,%hi(g_FileLists+0x4)
/*  f17bc08:	8f395bc4 */ 	lw	$t9,%lo(g_FileLists+0x4)($t9)
/*  f17bc0c:	8ce80000 */ 	lw	$t0,0x0($a3)
/*  f17bc10:	00025080 */ 	sll	$t2,$v0,0x2
/*  f17bc14:	01425023 */ 	subu	$t2,$t2,$v0
/*  f17bc18:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17bc1c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17bc20:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17bc24:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17bc28:	000a6023 */ 	negu	$t4,$t2
/*  f17bc2c:	03295821 */ 	addu	$t3,$t9,$t1
/*  f17bc30:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f17bc34:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f17bc38:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f17bc3c:	24050066 */ 	addiu	$a1,$zero,0x66
/*  f17bc40:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f17bc44:	946d0004 */ 	lhu	$t5,0x4($v1)
/*  f17bc48:	00003025 */ 	or	$a2,$zero,$zero
/*  f17bc4c:	0fc42539 */ 	jal	func0f1094e4
/*  f17bc50:	a7ad0028 */ 	sh	$t5,0x28($sp)
/*  f17bc54:	8faf0034 */ 	lw	$t7,0x34($sp)
.L0f17bc58:
/*  f17bc58:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17bc5c:	3c088009 */ 	lui	$t0,%hi(g_Is4Mb)
/*  f17bc60:	91f80001 */ 	lbu	$t8,0x1($t7)
/*  f17bc64:	5458006d */ 	bnel	$v0,$t8,.L0f17be1c
/*  f17bc68:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bc6c:	91080af0 */ 	lbu	$t0,%lo(g_Is4Mb)($t0)
/*  f17bc70:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f17bc74:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f17bc78:	14480006 */ 	bne	$v0,$t0,.L0f17bc94
/*  f17bc7c:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f17bc80:	3c048007 */ 	lui	$a0,%hi(g_MpQuickGo4MbMenuDialog)
/*  f17bc84:	0fc3e083 */ 	jal	func0f0f820c
/*  f17bc88:	24845120 */ 	addiu	$a0,$a0,%lo(g_MpQuickGo4MbMenuDialog)
/*  f17bc8c:	10000063 */ 	b	.L0f17be1c
/*  f17bc90:	00001025 */ 	or	$v0,$zero,$zero
.L0f17bc94:
/*  f17bc94:	0fc3e083 */ 	jal	func0f0f820c
/*  f17bc98:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f17bc9c:	1000005f */ 	b	.L0f17be1c
/*  f17bca0:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bca4:	3c19000f */ 	lui	$t9,0xf
/*  f17bca8:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f17bcac:	1000005a */ 	b	.L0f17be18
/*  f17bcb0:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f17bcb4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f17bcb8:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f17bcbc:	3c038007 */ 	lui	$v1,%hi(g_FileLists+0x4)
/*  f17bcc0:	8c635bc4 */ 	lw	$v1,%lo(g_FileLists+0x4)($v1)
/*  f17bcc4:	50600055 */ 	beqzl	$v1,.L0f17be1c
/*  f17bcc8:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bccc:	906b030a */ 	lbu	$t3,0x30a($v1)
/*  f17bcd0:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f17bcd4:	10000050 */ 	b	.L0f17be18
/*  f17bcd8:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f17bcdc:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f17bce0:	3c0e8007 */ 	lui	$t6,%hi(g_FileLists+0x4)
/*  f17bce4:	14600005 */ 	bnez	$v1,.L0f17bcfc
/*  f17bce8:	00000000 */ 	nop
/*  f17bcec:	0fc5b9f1 */ 	jal	langGet
/*  f17bcf0:	2404508d */ 	addiu	$a0,$zero,0x508d
/*  f17bcf4:	1000004a */ 	b	.L0f17be20
/*  f17bcf8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17bcfc:
/*  f17bcfc:	8dce5bc4 */ 	lw	$t6,%lo(g_FileLists+0x4)($t6)
/*  f17bd00:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f17bd04:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f17bd08:	51c00044 */ 	beqzl	$t6,.L0f17be1c
/*  f17bd0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bd10:	0fc421ae */ 	jal	filemgrGetDeviceNameOrStartIndex
/*  f17bd14:	2466ffff */ 	addiu	$a2,$v1,-1
/*  f17bd18:	10000041 */ 	b	.L0f17be20
/*  f17bd1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17bd20:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f17bd24:	15a00003 */ 	bnez	$t5,.L0f17bd34
/*  f17bd28:	00000000 */ 	nop
/*  f17bd2c:	1000003a */ 	b	.L0f17be18
/*  f17bd30:	ace00008 */ 	sw	$zero,0x8($a3)
.L0f17bd34:
/*  f17bd34:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bd38:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bd3c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bd40:	3c0f8007 */ 	lui	$t7,%hi(g_FileLists+0x4)
/*  f17bd44:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f17bd48:	ace20008 */ 	sw	$v0,0x8($a3)
/*  f17bd4c:	8def5bc4 */ 	lw	$t7,%lo(g_FileLists+0x4)($t7)
/*  f17bd50:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f17bd54:	51e00031 */ 	beqzl	$t7,.L0f17be1c
/*  f17bd58:	00001025 */ 	or	$v0,$zero,$zero
/*  f17bd5c:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f17bd60:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bd64:	0fc421ae */ 	jal	filemgrGetDeviceNameOrStartIndex
/*  f17bd68:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f17bd6c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bd70:	8cf80008 */ 	lw	$t8,0x8($a3)
/*  f17bd74:	03024021 */ 	addu	$t0,$t8,$v0
/*  f17bd78:	10000027 */ 	b	.L0f17be18
/*  f17bd7c:	ace80008 */ 	sw	$t0,0x8($a3)
/*  f17bd80:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bd84:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bd88:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bd8c:	3c0a8007 */ 	lui	$t2,%hi(g_MpPlayerNum)
/*  f17bd90:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f17bd94:	0322082b */ 	sltu	$at,$t9,$v0
/*  f17bd98:	1020000e */ 	beqz	$at,.L0f17bdd4
/*  f17bd9c:	00000000 */ 	nop
/*  f17bda0:	8d4a1448 */ 	lw	$t2,%lo(g_MpPlayerNum)($t2)
/*  f17bda4:	3c01800a */ 	lui	$at,%hi(g_Menus+0xe1c)
/*  f17bda8:	3409ffff */ 	dli	$t1,0xffff
/*  f17bdac:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f17bdb0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17bdb4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17bdb8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f17bdbc:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f17bdc0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17bdc4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f17bdc8:	002b0821 */ 	addu	$at,$at,$t3
/*  f17bdcc:	10000012 */ 	b	.L0f17be18
/*  f17bdd0:	ac29ee1c */ 	sw	$t1,%lo(g_Menus+0xe1c)($at)
.L0f17bdd4:
/*  f17bdd4:	0fc63703 */ 	jal	mpGetNumUnlockedPresets
/*  f17bdd8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f17bddc:	3c0d8007 */ 	lui	$t5,%hi(g_MpPlayerNum)
/*  f17bde0:	8dad1448 */ 	lw	$t5,%lo(g_MpPlayerNum)($t5)
/*  f17bde4:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f17bde8:	3c01800a */ 	lui	$at,%hi(g_Menus+0xe1c)
/*  f17bdec:	000d78c0 */ 	sll	$t7,$t5,0x3
/*  f17bdf0:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f17bdf4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17bdf8:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f17bdfc:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f17be00:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17be04:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f17be08:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17be0c:	002f0821 */ 	addu	$at,$at,$t7
/*  f17be10:	01827023 */ 	subu	$t6,$t4,$v0
/*  f17be14:	ac2eee1c */ 	sw	$t6,%lo(g_Menus+0xe1c)($at)
.L0f17be18:
/*  f17be18:	00001025 */ 	or	$v0,$zero,$zero
.L0f17be1c:
/*  f17be1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f17be20:
/*  f17be20:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f17be24:	03e00008 */ 	jr	$ra
/*  f17be28:	00000000 */ 	nop
);

char *mpMenuTextMpconfigMarquee(struct menuitem *item)
{
	char filename[20];
	u16 numsims;
	u16 stagenum;
	u16 scenarionum;
	s32 arenanum;
	s32 i;

	if (g_Menus[g_MpPlayerNum].data.mpsetup.slotindex < 0xffff && g_FileLists[1]) {
		arenanum = -1;
		func0f18e39c(g_FileLists[1]->unk000[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].unk06,
				filename, &numsims, &stagenum, &scenarionum);

		for (i = 0; i < ARRAYCOUNT(g_MpArenas); i++) {
			if (g_MpArenas[i].stagenum == stagenum) {
				arenanum = i;
			}
		}

		if (scenarionum <= 5 && arenanum != -1 && numsims >= 0 && filename[0] != '\0' && numsims <= 8) {
			// "%s:  Scenario: %s   Arena: %s    Simulants: %d"
			sprintf(g_StringPointer, langGet(L_MPMENU_140),
					filename,
					langGet(g_MpScenarioOverviews[scenarionum].name),
					langGet(g_MpArenas[arenanum].name),
					numsims);
		} else {
			return "";
		}

		return g_StringPointer;
	}

	return "";
}

GLOBAL_ASM(
glabel menuhandler0017bfc0
.late_rodata
glabel var7f1b8190
.word menuhandler0017bfc0+0x68 # f17c028
glabel var7f1b8194
.word menuhandler0017bfc0+0x184 # f17c144
glabel var7f1b8198
.word menuhandler0017bfc0+0x74 # f17c034
glabel var7f1b819c
.word menuhandler0017bfc0+0x190 # f17c150
glabel var7f1b81a0
.word menuhandler0017bfc0+0x1a4 # f17c164
glabel var7f1b81a4
.word menuhandler0017bfc0+0xa4 # f17c064
glabel var7f1b81a8
.word menuhandler0017bfc0+0x174 # f17c134
.text
/*  f17bfc0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f17bfc4:	3c028007 */ 	lui	$v0,%hi(g_FileLists)
/*  f17bfc8:	8c425bc0 */ 	lw	$v0,%lo(g_FileLists)($v0)
/*  f17bfcc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f17bfd0:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f17bfd4:	00802825 */ 	or	$a1,$a0,$zero
/*  f17bfd8:	00c09825 */ 	or	$s3,$a2,$zero
/*  f17bfdc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17bfe0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f17bfe4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f17bfe8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f17bfec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f17bff0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f17bff4:	14400003 */ 	bnez	$v0,.L0f17c004
/*  f17bff8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f17bffc:	10000060 */ 	b	.L0f17c180
/*  f17c000:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c004:
/*  f17c004:	24aeffff */ 	addiu	$t6,$a1,-1
/*  f17c008:	2dc10007 */ 	sltiu	$at,$t6,0x7
/*  f17c00c:	1020005b */ 	beqz	$at,.L0f17c17c
/*  f17c010:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17c014:	3c017f1c */ 	lui	$at,%hi(var7f1b8190)
/*  f17c018:	002e0821 */ 	addu	$at,$at,$t6
/*  f17c01c:	8c2e8190 */ 	lw	$t6,%lo(var7f1b8190)($at)
/*  f17c020:	01c00008 */ 	jr	$t6
/*  f17c024:	00000000 */ 	nop
/*  f17c028:	844f02d0 */ 	lh	$t7,0x2d0($v0)
/*  f17c02c:	10000053 */ 	b	.L0f17c17c
/*  f17c030:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f17c034:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f17c038:	3c108007 */ 	lui	$s0,%hi(g_StringPointer)
/*  f17c03c:	26101440 */ 	addiu	$s0,$s0,%lo(g_StringPointer)
/*  f17c040:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17c044:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17c048:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17c04c:	00592821 */ 	addu	$a1,$v0,$t9
/*  f17c050:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f17c054:	0fc42034 */ 	jal	filemgrGetFileName
/*  f17c058:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17c05c:	10000048 */ 	b	.L0f17c180
/*  f17c060:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f17c064:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f17c068:	3c13800b */ 	lui	$s3,%hi(g_MpSetup)
/*  f17c06c:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers)
/*  f17c070:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17c074:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17c078:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f17c07c:	00499021 */ 	addu	$s2,$v0,$t1
/*  f17c080:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f17c084:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpPlayers)
/*  f17c088:	2673cb88 */ 	addiu	$s3,$s3,%lo(g_MpSetup)
/*  f17c08c:	00008025 */ 	or	$s0,$zero,$zero
/*  f17c090:	24140004 */ 	addiu	$s4,$zero,0x4
.L0f17c094:
/*  f17c094:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f17c098:	8e2b004c */ 	lw	$t3,0x4c($s1)
/*  f17c09c:	554b0011 */ 	bnel	$t2,$t3,.L0f17c0e4
/*  f17c0a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f17c0a4:	964c0004 */ 	lhu	$t4,0x4($s2)
/*  f17c0a8:	962d0050 */ 	lhu	$t5,0x50($s1)
/*  f17c0ac:	558d000d */ 	bnel	$t4,$t5,.L0f17c0e4
/*  f17c0b0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f17c0b4:	966e0016 */ 	lhu	$t6,0x16($s3)
/*  f17c0b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f17c0bc:	020fc004 */ 	sllv	$t8,$t7,$s0
/*  f17c0c0:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f17c0c4:	17200005 */ 	bnez	$t9,.L0f17c0dc
/*  f17c0c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f17c0cc:	0fc62003 */ 	jal	mpPlayerSetDefaults
/*  f17c0d0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f17c0d4:	10000003 */ 	b	.L0f17c0e4
/*  f17c0d8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f17c0dc:
/*  f17c0dc:	0000a825 */ 	or	$s5,$zero,$zero
/*  f17c0e0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f17c0e4:
/*  f17c0e4:	1614ffeb */ 	bne	$s0,$s4,.L0f17c094
/*  f17c0e8:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f17c0ec:	12a0000d */ 	beqz	$s5,.L0f17c124
/*  f17c0f0:	00000000 */ 	nop
/*  f17c0f4:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f17c0f8:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f17c0fc:	96490004 */ 	lhu	$t1,0x4($s2)
/*  f17c100:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f17c104:	a7a90048 */ 	sh	$t1,0x48($sp)
/*  f17c108:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f17c10c:	8cc61448 */ 	lw	$a2,%lo(g_MpPlayerNum)($a2)
/*  f17c110:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f17c114:	0fc42539 */ 	jal	func0f1094e4
/*  f17c118:	24050065 */ 	addiu	$a1,$zero,0x65
/*  f17c11c:	10000018 */ 	b	.L0f17c180
/*  f17c120:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c124:
/*  f17c124:	0fc42197 */ 	jal	filemgrPushErrorDialog
/*  f17c128:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f17c12c:	10000014 */ 	b	.L0f17c180
/*  f17c130:	00001025 */ 	or	$v0,$zero,$zero
/*  f17c134:	3c0a000f */ 	lui	$t2,0xf
/*  f17c138:	354affff */ 	ori	$t2,$t2,0xffff
/*  f17c13c:	1000000f */ 	b	.L0f17c17c
/*  f17c140:	ae6a0000 */ 	sw	$t2,0x0($s3)
/*  f17c144:	904b030a */ 	lbu	$t3,0x30a($v0)
/*  f17c148:	1000000c */ 	b	.L0f17c17c
/*  f17c14c:	ae6b0000 */ 	sw	$t3,0x0($s3)
/*  f17c150:	00002025 */ 	or	$a0,$zero,$zero
/*  f17c154:	0fc421ae */ 	jal	filemgrGetDeviceNameOrStartIndex
/*  f17c158:	8e660000 */ 	lw	$a2,0x0($s3)
/*  f17c15c:	10000009 */ 	b	.L0f17c184
/*  f17c160:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17c164:	00002025 */ 	or	$a0,$zero,$zero
/*  f17c168:	0fc421ae */ 	jal	filemgrGetDeviceNameOrStartIndex
/*  f17c16c:	8e660000 */ 	lw	$a2,0x0($s3)
/*  f17c170:	ae620008 */ 	sw	$v0,0x8($s3)
/*  f17c174:	10000002 */ 	b	.L0f17c180
/*  f17c178:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c17c:
/*  f17c17c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17c180:
/*  f17c180:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17c184:
/*  f17c184:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f17c188:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f17c18c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f17c190:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f17c194:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f17c198:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f17c19c:	03e00008 */ 	jr	$ra
/*  f17c1a0:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

s32 menuhandlerMpTimeLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpSetup.timelimit;
		break;
	case MENUOP_SET:
		g_MpSetup.timelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 60) {
			sprintf(data->slider.label, langGet(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, langGet(L_MPMENU_114), data->slider.value + 1); // "%d Min"
		}
	}
	return 0;
}

s32 menuhandlerMpScoreLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpSetup.scorelimit;
		break;
	case MENUOP_SET:
		g_MpSetup.scorelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 100) {
			sprintf(data->slider.label, langGet(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, langGet(L_MPMENU_113), data->slider.value + 1); // "%d"
		}
	}

	return 0;
}

s32 menuhandlerMpTeamScoreLimitSlider(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = mpCalculateTeamScoreLimit();
		break;
	case MENUOP_SET:
		g_MpSetup.teamscorelimit = data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		if (data->slider.value == 400) {
			sprintf(data->slider.label, langGet(L_MPMENU_112)); // "No Limit"
		} else {
			sprintf(data->slider.label, langGet(L_MPMENU_113), data->slider.value + 1); // "%d"
		}
	}

	return 0;
}

s32 menuhandlerMpRestoreScoreDefaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f187fec();
	}

	return 0;
}

s32 menuhandlerMpHandicapPlayer(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_CHECKHIDDEN:
		if ((g_MpSetup.chrslots & (1 << item->param)) == 0) {
			return 1;
		}
		break;
	case MENUOP_GETSLIDER:
		data->slider.value = g_MpPlayers[item->param].handicap;
		break;
	case MENUOP_SET:
		g_MpPlayers[item->param].handicap = (u16)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, "%s%s%.00f%%\n", "", "", func0f187770(g_MpPlayers[item->param].handicap) * 100);
		break;
	}

	return 0;
}

char *mpMenuTextHandicapPlayerName(struct menuitem *item)
{
	if (g_MpSetup.chrslots & (1 << item->param)) {
		return g_MpPlayers[item->param].base.name;
	}

	return "";
}

const char var7f1b8028[] = "\n";

s32 menuhandlerMpRestoreHandicapDefaults(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i < 4; i++) {
			g_MpPlayers[i].handicap = 0x80;
		}
	}

	return 0;
}

s32 menudialogMpReady(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		if (g_MpPlayers[g_MpPlayerNum].unk4c.unk00 && g_MpPlayers[g_MpPlayerNum].unk4c.unk04) {
			func0f1094e4(&g_MpPlayers[g_MpPlayerNum].unk4c, 3, (void *)g_MpPlayerNum);
		}
	}

	return false;
}

s32 menudialogMpSimulant(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if ((u8)g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.name[0] == '\0') {
			menuPopDialog();
		}
	}

	return false;
}

struct menuitem g_MpCharacterMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004230, (u32)&mpMenuTextBodyName, 0x00000000, NULL },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x00000022, menuhandlerMpCharacterHead },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x0000001b, menuhandlerMpCharacterBody },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpCharacterMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_143, // "Character"
	g_MpCharacterMenuItems,
	menudialog0017a174,
	0x00000002,
	NULL,
};

struct menuitem g_MpPlayerNameMenuItems[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler0017b91c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_142, // "Player Name"
	g_MpPlayerNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpLoadSettingsMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x00000078, 0x00000042, menuhandler0017bab4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextMpconfigMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLoadSettingsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_139, // "Load Game Settings"
	g_MpLoadSettingsMenuItems,
	NULL,
	0x00000001,
	NULL,
};

struct menuitem g_MpLoadPresetMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00000000, 0x00000078, 0x00000042, menuhandler0017bab4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextMpconfigMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLoadPresetMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_139, // "Load Game Settings"
	g_MpLoadPresetMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpLoadPlayerMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x0000007e, 0x00000042, menuhandler0017bfc0 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPMENU_138, 0x00000000, NULL }, // "B Button to cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLoadPlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_137, // "Load Player"
	g_MpLoadPlayerMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpArenaMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x0000004d, menuhandler001791c8 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpArenaMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_115, // "Arena"
	g_MpArenaMenuItems,
	NULL,
	0x00000011,
	NULL,
};

struct menuitem g_MpLimitsMenuItems[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU_108, 0x0000003c, menuhandlerMpTimeLimitSlider }, // "Time"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU_109, 0x00000064, menuhandlerMpScoreLimitSlider }, // "Score"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MISC_447, 0x00000190, menuhandlerMpTeamScoreLimitSlider }, // "Team Score"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_110, 0x00000000, menuhandlerMpRestoreScoreDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_111, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpLimitsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_107, // "Limits"
	g_MpLimitsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpHandicapsMenuItems[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      1, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      2, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      3, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_110, 0x00000000, menuhandlerMpRestoreHandicapDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_111, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpHandicapsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_184, // "Player Handicaps"
	g_MpHandicapsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpReadyMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_106, 0x00000000, NULL }, // "...and waiting"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpReadyMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU_105, // "Ready!"
	g_MpReadyMenuItems,
	menudialogMpReady,
	0x00000001,
	NULL,
};

u32 var800857d0 = 0x00000000;
u32 var800857d4 = 0x50670000; // "Normal Simulants"
u32 var800857d8 = 0x00000006;
u32 var800857dc = 0x50680000; // "Special Simulants"

GLOBAL_ASM(
glabel menuhandler0017c6a4
.late_rodata
glabel var7f1b81ac
.word menuhandler0017c6a4+0x78 # f17c71c
glabel var7f1b81b0
.word menuhandler0017c6a4+0x2f0 # f17c994
glabel var7f1b81b4
.word menuhandler0017c6a4+0xac # f17c750
glabel var7f1b81b8
.word menuhandler0017c6a4+0x2fc # f17c9a0
glabel var7f1b81bc
.word menuhandler0017c6a4+0x318 # f17c9bc
glabel var7f1b81c0
.word menuhandler0017c6a4+0x100 # f17c7a4
glabel var7f1b81c4
.word menuhandler0017c6a4+0x2b8 # f17c95c
glabel var7f1b81c8
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81cc
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81d0
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81d4
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81d8
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81dc
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81e0
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81e4
.word menuhandler0017c6a4+0x378 # f17ca1c
glabel var7f1b81e8
.word menuhandler0017c6a4+0x250 # f17c8f4
.text
/*  f17c6a4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f17c6a8:	3c0e8008 */ 	lui	$t6,%hi(var800857d0)
/*  f17c6ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17c6b0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17c6b4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17c6b8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17c6bc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17c6c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17c6c4:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f17c6c8:	25ce57d0 */ 	addiu	$t6,$t6,%lo(var800857d0)
/*  f17c6cc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f17c6d0:	27b30040 */ 	addiu	$s3,$sp,0x40
/*  f17c6d4:	2488ffff */ 	addiu	$t0,$a0,-1
/*  f17c6d8:	ae610000 */ 	sw	$at,0x0($s3)
/*  f17c6dc:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f17c6e0:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f17c6e4:	00009025 */ 	or	$s2,$zero,$zero
/*  f17c6e8:	ae790004 */ 	sw	$t9,0x4($s3)
/*  f17c6ec:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f17c6f0:	ae610008 */ 	sw	$at,0x8($s3)
/*  f17c6f4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f17c6f8:	2d010010 */ 	sltiu	$at,$t0,0x10
/*  f17c6fc:	102000c7 */ 	beqz	$at,.L0f17ca1c
/*  f17c700:	ae79000c */ 	sw	$t9,0xc($s3)
/*  f17c704:	00084080 */ 	sll	$t0,$t0,0x2
/*  f17c708:	3c017f1c */ 	lui	$at,%hi(var7f1b81ac)
/*  f17c70c:	00280821 */ 	addu	$at,$at,$t0
/*  f17c710:	8c2881ac */ 	lw	$t0,%lo(var7f1b81ac)($at)
/*  f17c714:	01000008 */ 	jr	$t0
/*  f17c718:	00000000 */ 	nop
/*  f17c71c:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17c720:	3c118008 */ 	lui	$s1,%hi(g_MpBodies)
/*  f17c724:	263177bc */ 	addiu	$s1,$s1,%lo(g_MpBodies)
/*  f17c728:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
.L0f17c72c:
/*  f17c72c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17c730:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c734:	10400002 */ 	beqz	$v0,.L0f17c740
/*  f17c738:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17c73c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17c740:
/*  f17c740:	1611fffa */ 	bne	$s0,$s1,.L0f17c72c
/*  f17c744:	00000000 */ 	nop
/*  f17c748:	100000b4 */ 	b	.L0f17ca1c
/*  f17c74c:	ae920000 */ 	sw	$s2,0x0($s4)
/*  f17c750:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17c754:	3c118008 */ 	lui	$s1,%hi(g_MpBodies)
/*  f17c758:	263177bc */ 	addiu	$s1,$s1,%lo(g_MpBodies)
/*  f17c75c:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
.L0f17c760:
/*  f17c760:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17c764:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c768:	5040000a */ 	beqzl	$v0,.L0f17c794
/*  f17c76c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17c770:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f17c774:	56490006 */ 	bnel	$s2,$t1,.L0f17c790
/*  f17c778:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c77c:	0fc5b9f1 */ 	jal	langGet
/*  f17c780:	86040002 */ 	lh	$a0,0x2($s0)
/*  f17c784:	100000a7 */ 	b	.L0f17ca24
/*  f17c788:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17c78c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17c790:
/*  f17c790:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f17c794:
/*  f17c794:	1611fff2 */ 	bne	$s0,$s1,.L0f17c760
/*  f17c798:	00000000 */ 	nop
/*  f17c79c:	100000a0 */ 	b	.L0f17ca20
/*  f17c7a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f17c7a4:	3c0a8007 */ 	lui	$t2,%hi(g_MpPlayerNum)
/*  f17c7a8:	8d4a1448 */ 	lw	$t2,%lo(g_MpPlayerNum)($t2)
/*  f17c7ac:	3c0c800a */ 	lui	$t4,%hi(g_Menus+0xe1c)
/*  f17c7b0:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f17c7b4:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f17c7b8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17c7bc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f17c7c0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f17c7c4:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f17c7c8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f17c7cc:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f17c7d0:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f17c7d4:	8d8cee1c */ 	lw	$t4,%lo(g_Menus+0xe1c)($t4)
/*  f17c7d8:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0x16)
/*  f17c7dc:	05810007 */ 	bgez	$t4,.L0f17c7fc
/*  f17c7e0:	afac003c */ 	sw	$t4,0x3c($sp)
/*  f17c7e4:	0fc632ee */ 	jal	mpGetNumSimulants
/*  f17c7e8:	00000000 */ 	nop
/*  f17c7ec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f17c7f0:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f17c7f4:	1000000a */ 	b	.L0f17c820
/*  f17c7f8:	afad0038 */ 	sw	$t5,0x38($sp)
.L0f17c7fc:
/*  f17c7fc:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f17c800:	9718cb9e */ 	lhu	$t8,%lo(g_MpSetup+0x16)($t8)
/*  f17c804:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f17c808:	25ee0004 */ 	addiu	$t6,$t7,0x4
/*  f17c80c:	01d94004 */ 	sllv	$t0,$t9,$t6
/*  f17c810:	03084824 */ 	and	$t1,$t8,$t0
/*  f17c814:	15200002 */ 	bnez	$t1,.L0f17c820
/*  f17c818:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f17c81c:	afaa0038 */ 	sw	$t2,0x38($sp)
.L0f17c820:
/*  f17c820:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17c824:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
/*  f17c828:	00008825 */ 	or	$s1,$zero,$zero
/*  f17c82c:	24130012 */ 	addiu	$s3,$zero,0x12
.L0f17c830:
/*  f17c830:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17c834:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c838:	50400005 */ 	beqzl	$v0,.L0f17c850
/*  f17c83c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17c840:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f17c844:	124b0004 */ 	beq	$s2,$t3,.L0f17c858
/*  f17c848:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c84c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17c850:
/*  f17c850:	1633fff7 */ 	bne	$s1,$s3,.L0f17c830
/*  f17c854:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f17c858:
/*  f17c858:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f17c85c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f17c860:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f17c864:	11800006 */ 	beqz	$t4,.L0f17c880
/*  f17c868:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f17c86c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f17c870:	0fc63261 */ 	jal	func0f18c984
/*  f17c874:	322500ff */ 	andi	$a1,$s1,0xff
/*  f17c878:	1000000e */ 	b	.L0f17c8b4
/*  f17c87c:	00000000 */ 	nop
.L0f17c880:
/*  f17c880:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f17c884:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f17c888:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17c88c:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f17c890:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17c894:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f17c898:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f17c89c:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f17c8a0:	17000004 */ 	bnez	$t8,.L0f17c8b4
/*  f17c8a4:	a04e0047 */ 	sb	$t6,0x47($v0)
/*  f17c8a8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f17c8ac:	0fc632d8 */ 	jal	func0f18cb60
/*  f17c8b0:	92050001 */ 	lbu	$a1,0x1($s0)
.L0f17c8b4:
/*  f17c8b4:	0fc63377 */ 	jal	func0f18cddc
/*  f17c8b8:	00000000 */ 	nop
/*  f17c8bc:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17c8c0:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f17c8c4:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f17c8c8:	3c01800a */ 	lui	$at,%hi(g_Menus+0xe20)
/*  f17c8cc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f17c8d0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17c8d4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f17c8d8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f17c8dc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f17c8e0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f17c8e4:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f17c8e8:	002a0821 */ 	addu	$at,$at,$t2
/*  f17c8ec:	1000004b */ 	b	.L0f17ca1c
/*  f17c8f0:	ac28ee20 */ 	sw	$t0,%lo(g_Menus+0xe20)($at)
/*  f17c8f4:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17c8f8:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
/*  f17c8fc:	00008825 */ 	or	$s1,$zero,$zero
/*  f17c900:	24130012 */ 	addiu	$s3,$zero,0x12
.L0f17c904:
/*  f17c904:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17c908:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c90c:	50400005 */ 	beqzl	$v0,.L0f17c924
/*  f17c910:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17c914:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f17c918:	124b0004 */ 	beq	$s2,$t3,.L0f17c92c
/*  f17c91c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c920:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17c924:
/*  f17c924:	1633fff7 */ 	bne	$s1,$s3,.L0f17c904
/*  f17c928:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f17c92c:
/*  f17c92c:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f17c930:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f17c934:	3c01800a */ 	lui	$at,%hi(g_Menus+0xe24)
/*  f17c938:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17c93c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17c940:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17c944:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17c948:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17c94c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17c950:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17c954:	002d0821 */ 	addu	$at,$at,$t5
/*  f17c958:	ac31ee24 */ 	sw	$s1,%lo(g_Menus+0xe24)($at)
/*  f17c95c:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f17c960:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f17c964:	3c0e800a */ 	lui	$t6,%hi(g_Menus+0xe20)
/*  f17c968:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f17c96c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f17c970:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17c974:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f17c978:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17c97c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f17c980:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17c984:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f17c988:	8dceee20 */ 	lw	$t6,%lo(g_Menus+0xe20)($t6)
/*  f17c98c:	10000023 */ 	b	.L0f17ca1c
/*  f17c990:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f17c994:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f17c998:	10000020 */ 	b	.L0f17ca1c
/*  f17c99c:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f17c9a0:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f17c9a4:	000940c0 */ 	sll	$t0,$t1,0x3
/*  f17c9a8:	02685021 */ 	addu	$t2,$s3,$t0
/*  f17c9ac:	0fc5b9f1 */ 	jal	langGet
/*  f17c9b0:	95440004 */ 	lhu	$a0,0x4($t2)
/*  f17c9b4:	1000001b */ 	b	.L0f17ca24
/*  f17c9b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17c9bc:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f17c9c0:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17c9c4:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
/*  f17c9c8:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f17c9cc:	026c6821 */ 	addu	$t5,$s3,$t4
/*  f17c9d0:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f17c9d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f17c9d8:	59e00010 */ 	blezl	$t7,.L0f17ca1c
/*  f17c9dc:	ae920008 */ 	sw	$s2,0x8($s4)
.L0f17c9e0:
/*  f17c9e0:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17c9e4:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17c9e8:	50400003 */ 	beqzl	$v0,.L0f17c9f8
/*  f17c9ec:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f17c9f0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17c9f4:	8e990000 */ 	lw	$t9,0x0($s4)
.L0f17c9f8:
/*  f17c9f8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17c9fc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17ca00:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f17ca04:	026ec021 */ 	addu	$t8,$s3,$t6
/*  f17ca08:	8f090000 */ 	lw	$t1,0x0($t8)
/*  f17ca0c:	0229082a */ 	slt	$at,$s1,$t1
/*  f17ca10:	1420fff3 */ 	bnez	$at,.L0f17c9e0
/*  f17ca14:	00000000 */ 	nop
/*  f17ca18:	ae920008 */ 	sw	$s2,0x8($s4)
.L0f17ca1c:
/*  f17ca1c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ca20:
/*  f17ca20:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17ca24:
/*  f17ca24:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17ca28:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17ca2c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17ca30:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17ca34:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17ca38:	03e00008 */ 	jr	$ra
/*  f17ca3c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

char *mpMenuTextSimulantDescription(struct menuitem *item)
{
	return langGet(L_MISC_106 + g_Menus[g_MpPlayerNum].data.mpsetup.unke24);
}

s32 menuhandlerMpSimulantHead(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 start = 0;

	if (item->param2 == 1) {
		start = mpGetNumHeads();
	}

	/**
	 * Rare developers forgot to add a break statement to the first case,
	 * and when they noticed a problem their fix was to add an additional
	 * MENUOP_FOCUS check in the next case.
	 */
	switch (operation) {
	case MENUOP_SET:
		g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpheadnum = start + data->carousel.value;
	case MENUOP_FOCUS:
		if (operation == MENUOP_FOCUS
				&& item->param2 == 1
				&& g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpheadnum < start) {
			g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpheadnum = start;
		}
		break;
	}

	return func0f17b4f8(operation, item, data, g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpheadnum, 0);
}

s32 menuhandlerMpSimulantBody(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpbodynum = data->carousel.value;
	}

	return func0f179da4(operation, item, data,
			g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpbodynum,
			g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.mpheadnum,
			0);
}

s32 menudialog0017ccfc(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_TICK:
		if (g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[0]
				&& g_Menus[g_MpPlayerNum].curframe->focuseditem != &dialog->items[1]) {
			union handlerdata data;
			menuhandlerMpCharacterBody(MENUOP_11, &dialog->items[1], &data);
		}
	}

	return menudialogMpSimulant(operation, dialog, data);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menuhandlerMpSimulantDifficulty
/*  f17cda0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17cda4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17cda8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17cdac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17cdb0:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f17cdb4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17cdb8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17cdbc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17cdc0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17cdc4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17cdc8:	10810038 */ 	beq	$a0,$at,.L0f17ceac
/*  f17cdcc:	00009025 */ 	or	$s2,$zero,$zero
/*  f17cdd0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17cdd4:	10810042 */ 	beq	$a0,$at,.L0f17cee0
/*  f17cdd8:	00008825 */ 	or	$s1,$zero,$zero
/*  f17cddc:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f17cde0:	10930006 */ 	beq	$a0,$s3,.L0f17cdfc
/*  f17cde4:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17cde8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f17cdec:	10810014 */ 	beq	$a0,$at,.L0f17ce40
/*  f17cdf0:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f17cdf4:	10000050 */ 	b	.L0f17cf38
/*  f17cdf8:	00001025 */ 	or	$v0,$zero,$zero
.L0f17cdfc:
/*  f17cdfc:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17ce00:	3c04800a */ 	lui	$a0,%hi(g_Menus+0xe1c)
/*  f17ce04:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f17ce08:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17ce0c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ce10:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17ce14:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ce18:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17ce1c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ce20:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17ce24:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f17ce28:	0fc632d8 */ 	jal	func0f18cb60
/*  f17ce2c:	8c84ee1c */ 	lw	$a0,%lo(g_Menus+0xe1c)($a0)
/*  f17ce30:	0fc63377 */ 	jal	func0f18cddc
/*  f17ce34:	00000000 */ 	nop
/*  f17ce38:	1000003f */ 	b	.L0f17cf38
/*  f17ce3c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ce40:
/*  f17ce40:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f17ce44:	3c08800a */ 	lui	$t0,%hi(g_Menus+0xe1c)
/*  f17ce48:	3c02800b */ 	lui	$v0,%hi(g_MpSimulants+0x48)
/*  f17ce4c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17ce50:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17ce54:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17ce58:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17ce5c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17ce60:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17ce64:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17ce68:	01194021 */ 	addu	$t0,$t0,$t9
/*  f17ce6c:	8d08ee1c */ 	lw	$t0,%lo(g_Menus+0xe1c)($t0)
/*  f17ce70:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17ce74:	01284821 */ 	addu	$t1,$t1,$t0
/*  f17ce78:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17ce7c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17ce80:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17ce84:	00491021 */ 	addu	$v0,$v0,$t1
/*  f17ce88:	9042c580 */ 	lbu	$v0,%lo(g_MpSimulants+0x48)($v0)
/*  f17ce8c:	04400005 */ 	bltz	$v0,.L0f17cea4
/*  f17ce90:	28410006 */ 	slti	$at,$v0,0x6
/*  f17ce94:	10200003 */ 	beqz	$at,.L0f17cea4
/*  f17ce98:	00000000 */ 	nop
/*  f17ce9c:	10000025 */ 	b	.L0f17cf34
/*  f17cea0:	ae820000 */ 	sw	$v0,0x0($s4)
.L0f17cea4:
/*  f17cea4:	10000023 */ 	b	.L0f17cf34
/*  f17cea8:	ae800000 */ 	sw	$zero,0x0($s4)
.L0f17ceac:
/*  f17ceac:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17ceb0:	3c118008 */ 	lui	$s1,%hi(g_MpSimulantTypes+0x30)
/*  f17ceb4:	2631775c */ 	addiu	$s1,$s1,%lo(g_MpSimulantTypes+0x30)
/*  f17ceb8:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
.L0f17cebc:
/*  f17cebc:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17cec0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17cec4:	10400002 */ 	beqz	$v0,.L0f17ced0
/*  f17cec8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17cecc:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17ced0:
/*  f17ced0:	1611fffa */ 	bne	$s0,$s1,.L0f17cebc
/*  f17ced4:	00000000 */ 	nop
/*  f17ced8:	10000016 */ 	b	.L0f17cf34
/*  f17cedc:	ae920000 */ 	sw	$s2,0x0($s4)
.L0f17cee0:
/*  f17cee0:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17cee4:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
/*  f17cee8:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f17ceec:
/*  f17ceec:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17cef0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17cef4:	5040000a */ 	beqzl	$v0,.L0f17cf20
/*  f17cef8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17cefc:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f17cf00:	564a0006 */ 	bnel	$s2,$t2,.L0f17cf1c
/*  f17cf04:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17cf08:	0fc5b9f1 */ 	jal	langGet
/*  f17cf0c:	26245852 */ 	addiu	$a0,$s1,0x5815
/*  f17cf10:	1000000a */ 	b	.L0f17cf3c
/*  f17cf14:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17cf18:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17cf1c:
/*  f17cf1c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17cf20:
/*  f17cf20:	1633fff2 */ 	bne	$s1,$s3,.L0f17ceec
/*  f17cf24:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17cf28:	3c027f1c */ 	lui	$v0,%hi(var7f1b8028)
/*  f17cf2c:	10000002 */ 	b	.L0f17cf38
/*  f17cf30:	24428028 */ 	addiu	$v0,$v0,%lo(var7f1b8028)
.L0f17cf34:
/*  f17cf34:	00001025 */ 	or	$v0,$zero,$zero
.L0f17cf38:
/*  f17cf38:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17cf3c:
/*  f17cf3c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17cf40:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17cf44:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17cf48:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17cf4c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17cf50:	03e00008 */ 	jr	$ra
/*  f17cf54:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#else
GLOBAL_ASM(
glabel menuhandlerMpSimulantDifficulty
/*  f17cda0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f17cda4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17cda8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17cdac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17cdb0:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f17cdb4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f17cdb8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17cdbc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17cdc0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17cdc4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f17cdc8:	10810038 */ 	beq	$a0,$at,.L0f17ceac
/*  f17cdcc:	00009025 */ 	or	$s2,$zero,$zero
/*  f17cdd0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17cdd4:	10810042 */ 	beq	$a0,$at,.L0f17cee0
/*  f17cdd8:	00008825 */ 	or	$s1,$zero,$zero
/*  f17cddc:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f17cde0:	10930006 */ 	beq	$a0,$s3,.L0f17cdfc
/*  f17cde4:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f17cde8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f17cdec:	10810014 */ 	beq	$a0,$at,.L0f17ce40
/*  f17cdf0:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f17cdf4:	10000050 */ 	b	.L0f17cf38
/*  f17cdf8:	00001025 */ 	or	$v0,$zero,$zero
.L0f17cdfc:
/*  f17cdfc:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f17ce00:	3c04800a */ 	lui	$a0,%hi(g_Menus+0xe1c)
/*  f17ce04:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f17ce08:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f17ce0c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ce10:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17ce14:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f17ce18:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f17ce1c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f17ce20:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f17ce24:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f17ce28:	0fc632d8 */ 	jal	func0f18cb60
/*  f17ce2c:	8c84ee1c */ 	lw	$a0,%lo(g_Menus+0xe1c)($a0)
/*  f17ce30:	0fc63377 */ 	jal	func0f18cddc
/*  f17ce34:	00000000 */ 	nop
/*  f17ce38:	1000003f */ 	b	.L0f17cf38
/*  f17ce3c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17ce40:
/*  f17ce40:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f17ce44:	3c08800a */ 	lui	$t0,%hi(g_Menus+0xe1c)
/*  f17ce48:	3c02800b */ 	lui	$v0,%hi(g_MpSimulants+0x48)
/*  f17ce4c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17ce50:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17ce54:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17ce58:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17ce5c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17ce60:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17ce64:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17ce68:	01194021 */ 	addu	$t0,$t0,$t9
/*  f17ce6c:	8d08ee1c */ 	lw	$t0,%lo(g_Menus+0xe1c)($t0)
/*  f17ce70:	00084880 */ 	sll	$t1,$t0,0x2
/*  f17ce74:	01284821 */ 	addu	$t1,$t1,$t0
/*  f17ce78:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17ce7c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f17ce80:	00094880 */ 	sll	$t1,$t1,0x2
/*  f17ce84:	00491021 */ 	addu	$v0,$v0,$t1
/*  f17ce88:	9042c580 */ 	lbu	$v0,%lo(g_MpSimulants+0x48)($v0)
/*  f17ce8c:	04400005 */ 	bltz	$v0,.L0f17cea4
/*  f17ce90:	28410006 */ 	slti	$at,$v0,0x6
/*  f17ce94:	10200003 */ 	beqz	$at,.L0f17cea4
/*  f17ce98:	00000000 */ 	nop
/*  f17ce9c:	10000025 */ 	b	.L0f17cf34
/*  f17cea0:	ae820000 */ 	sw	$v0,0x0($s4)
.L0f17cea4:
/*  f17cea4:	10000023 */ 	b	.L0f17cf34
/*  f17cea8:	ae800000 */ 	sw	$zero,0x0($s4)
.L0f17ceac:
/*  f17ceac:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17ceb0:	3c118008 */ 	lui	$s1,%hi(g_MpSimulantTypes+0x30)
/*  f17ceb4:	2631775c */ 	addiu	$s1,$s1,%lo(g_MpSimulantTypes+0x30)
/*  f17ceb8:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
.L0f17cebc:
/*  f17cebc:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17cec0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17cec4:	10400002 */ 	beqz	$v0,.L0f17ced0
/*  f17cec8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17cecc:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17ced0:
/*  f17ced0:	1611fffa */ 	bne	$s0,$s1,.L0f17cebc
/*  f17ced4:	00000000 */ 	nop
/*  f17ced8:	10000016 */ 	b	.L0f17cf34
/*  f17cedc:	ae920000 */ 	sw	$s2,0x0($s4)
.L0f17cee0:
/*  f17cee0:	3c108008 */ 	lui	$s0,%hi(g_MpSimulantTypes)
/*  f17cee4:	2610772c */ 	addiu	$s0,$s0,%lo(g_MpSimulantTypes)
/*  f17cee8:	24130006 */ 	addiu	$s3,$zero,0x6
.L0f17ceec:
/*  f17ceec:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f17cef0:	92040006 */ 	lbu	$a0,0x6($s0)
/*  f17cef4:	5040000a */ 	beqzl	$v0,.L0f17cf20
/*  f17cef8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17cefc:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f17cf00:	564a0006 */ 	bnel	$s2,$t2,.L0f17cf1c
/*  f17cf04:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f17cf08:	0fc5b9f1 */ 	jal	langGet
/*  f17cf0c:	26245852 */ 	addiu	$a0,$s1,0x5852
/*  f17cf10:	1000000a */ 	b	.L0f17cf3c
/*  f17cf14:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f17cf18:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f17cf1c:
/*  f17cf1c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f17cf20:
/*  f17cf20:	1633fff2 */ 	bne	$s1,$s3,.L0f17ceec
/*  f17cf24:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f17cf28:	3c027f1c */ 	lui	$v0,%hi(var7f1b8028)
/*  f17cf2c:	10000002 */ 	b	.L0f17cf38
/*  f17cf30:	24428028 */ 	addiu	$v0,$v0,%lo(var7f1b8028)
.L0f17cf34:
/*  f17cf34:	00001025 */ 	or	$v0,$zero,$zero
.L0f17cf38:
/*  f17cf38:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f17cf3c:
/*  f17cf3c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17cf40:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17cf44:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17cf48:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17cf4c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17cf50:	03e00008 */ 	jr	$ra
/*  f17cf54:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#endif

s32 menuhandlerMpDeleteSimulant(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpRemoveSimulant(g_Menus[g_MpPlayerNum].data.mpsetup.slotindex);
		menuPopDialog();
	}

	return 0;
}

char *mpMenuTitleEditSimulant(struct menudialog *dialog)
{
	sprintf(g_StringPointer, "%s", &g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.name);
	return g_StringPointer;
}

s32 menuhandlerMpChangeSimulantType(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		s32 count = 0;
		s32 simtypeindex = mpGetSimTypeIndex(
				g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].base.simtype,
				g_MpSimulants[g_Menus[g_MpPlayerNum].data.mpsetup.slotindex].difficulty);

		for (i = 0; i < simtypeindex; i++) {
			if (mpIsFeatureUnlocked(g_MpSimulantTypes[i].requirefeature)) {
				count++;
			}
		}

		g_Menus[g_MpPlayerNum].data.mpsetup.slotcount = count;

		menuPushDialog(&g_MpChangeSimulantMenuDialog);
	}

	return 0;
}

s32 menuhandlerMpClearAllSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		for (i = 0; i < MAX_SIMULANTS; i++) {
			mpRemoveSimulant(i);
		}
	}

	return 0;
}

s32 menuhandlerMpAddSimulant(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].data.mpsetup.slotindex = -1;
		menuPushDialog(&g_MpAddSimulantMenuDialog);
		break;
	case MENUOP_CHECKDISABLED:
		if (func0f18cc8c() == 0) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpSimulantSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_SET:
		g_Menus[g_MpPlayerNum].data.mpsetup.slotindex = item->param;

		if ((g_MpSetup.chrslots & (1 << (item->param + 4))) == 0) {
			menuPushDialog(&g_MpAddSimulantMenuDialog);
		} else if (IS4MB()) {
			menuPushDialog(&g_MpEditSimulant4MbMenuDialog);
		} else {
			menuPushDialog(&g_MpEditSimulantMenuDialog);
		}
		break;
	case MENUOP_CHECKHIDDEN:
		if (item->param >= 4 && !mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
			return true;
		}
		break;
	case MENUOP_CHECKDISABLED:
		if (!mpIsSimSlotEnabled(item->param)) {
			return true;
		}
	}

	return 0;
}

char *mpMenuTextSimulantName(struct menuitem *item)
{
	s32 index = item->param;

	if (g_MpSimulants[index].base.name[0] == '\0' || (g_MpSetup.chrslots & 1 << (index + 4)) == 0) {
		return "";
	}

	return g_MpSimulants[index].base.name;
}

char *func0f17d3dc(struct menuitem *item)
{
	s32 index = item->param;

	if (g_MpSimulants[index].base.name[0] == '\0'
			|| ((g_MpSetup.chrslots & 1 << (index + 4)) == 0)) {
		return "";
	}

	sprintf(g_StringPointer, "%d:\n", index + 1);
	return g_StringPointer;
}

s32 menudialogMpSimulants(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Menus[g_MpPlayerNum].data.mpsetup.slotcount = 0;
	}

	return false;
}

struct menuitem g_MpAddChangeSimulantMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x00000042, menuhandler0017c6a4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextSimulantDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAddSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_101, // "Add Simulant"
	g_MpAddChangeSimulantMenuItems,
	NULL,
	0x00000011,
	NULL,
};

struct menudialog g_MpChangeSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_102, // "Change Simulant"
	g_MpAddChangeSimulantMenuItems,
	menudialogMpSimulant,
	0x00000011,
	NULL,
};

struct menuitem g_MpSimulantCharacterMenuItems[] = {
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x00000025, menuhandlerMpSimulantHead },
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x0000001b, menuhandlerMpSimulantBody },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSimulantCharacterMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_100, // "Simulant Character"
	g_MpSimulantCharacterMenuItems,
	menudialog0017ccfc,
	0x00000012,
	NULL,
};

struct menuitem g_MpEditSimulantMenuItems[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU_095, 0x00000000, menuhandlerMpSimulantDifficulty }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_096, 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_097, 0x00000000, (void *)&g_MpSimulantCharacterMenuDialog }, // "Character..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_098, 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_099, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpEditSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleEditSimulant,
	g_MpEditSimulantMenuItems,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

struct menuitem g_MpSimulantsMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_084, 0x00000000, menuhandlerMpAddSimulant }, // "Add Simulant..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_085, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "1:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_MPMENU_086, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "2:"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_MPMENU_087, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "3:"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_MPMENU_088, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "4:"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00000000, L_MPMENU_089, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "5:"
	{ MENUITEMTYPE_SELECTABLE,  5, 0x00000000, L_MPMENU_090, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "6:"
	{ MENUITEMTYPE_SELECTABLE,  6, 0x00000000, L_MPMENU_091, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "7:"
	{ MENUITEMTYPE_SELECTABLE,  7, 0x00000000, L_MPMENU_092, (u32)&mpMenuTextSimulantName, menuhandlerMpSimulantSlot }, // "8:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_093, 0x00000000, menuhandlerMpClearAllSimulants }, // "Clear All"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_094, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSimulantsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_083, // "Simulants"
	g_MpSimulantsMenuItems,
	menudialogMpSimulants,
	0x00000010,
	NULL,
};

s32 menuhandlerMpNTeams(s32 operation, struct menuitem *item, union handlerdata *data, s32 numteams)
{
	if (operation == MENUOP_SET) {
		s32 numchrs = mpGetNumChrs();
		s32 array[] = {0, 0, 0, 0};
		s32 somevalue = (numchrs + numteams - 1) / numteams;
		s32 teamsremaining = numteams;
		s32 chrsremaining = numchrs;
		s32 start = random() % numchrs;

		s32 i;
		s32 teamnum;

		if (!numchrs) {
			return 0;
		}

		i = (start + 1) % numchrs;

		do {
			struct mpchr *mpchr = func0f18c794(i);

			if (teamsremaining);

			if (teamsremaining >= chrsremaining) {
				teamnum = random() % numteams;

				while (true) {
					if (array[teamnum] == 0) {
						mpchr->team = teamnum;

						array[teamnum]++;
						teamsremaining--;
						chrsremaining--;
						break;
					} else {
						teamnum = (teamnum + 1) % numteams;
					}
				}
			} else {
				teamnum = random() % numteams;

				while (true) {
					if (array[teamnum] < somevalue) {
						mpchr->team = teamnum;

						if (array[teamnum] == 0) {
							teamsremaining--;
						}

						array[teamnum]++;
						chrsremaining--;
						break;
					} else {
						teamnum = (teamnum + 1) % numteams;
					}
				}
			}

			if (i == start) {
				break;
			}

			i = (i + 1) % numchrs;
		} while (true);

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpTwoTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 2);
}

s32 menuhandlerMpThreeTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 3);
}

s32 menuhandlerMpFourTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	return menuhandlerMpNTeams(operation, item, data, 4);
}

s32 menuhandlerMpMaximumTeams(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;
		u8 team = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *mpchr;

				if (i < 4) {
					mpchr = &g_MpPlayers[i].base;
				} else {
					mpchr = &g_MpSimulants[i - 4].base;
				}

				mpchr->team = team++;

				if (team >= scenarioGetMaxTeams()) {
					team = 0;
				}
			}
		}

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpHumansVsSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		s32 i;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *mpchr;

				if (i < 4) {
					mpchr = &g_MpPlayers[i].base;
				} else {
					mpchr = &g_MpSimulants[i - 4].base;
				}

				mpchr->team = i < 4 ? 0 : 1;
			}
		}

		menuPopDialog();
	}

	return 0;
}

s32 menuhandlerMpHumanSimulantPairs(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		u8 team_ids[4] = {0, 1, 2, 3};
		s32 i;
		s32 playerindex = 0;
		s32 simindex = 0;

		for (i = 0; i != MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *mpchr;

				if (i < 4) {
					mpchr = &g_MpPlayers[i].base;
				} else {
					mpchr = &g_MpSimulants[i - 4].base;
				}

				if (i < 4) {
					mpchr->team = team_ids[playerindex++];
				} else {
					mpchr->team = team_ids[simindex++];

					if (simindex >= playerindex) {
						simindex = 0;
					}
				}
			}
		}

		menuPopDialog();
	}

	return 0;
}

char *mpMenuTextChrNameForTeamSetup(struct menuitem *item)
{
	struct mpchr *mpchr = func0f18c794(item->param);

	if (mpchr) {
		return mpchr->name;
	}

	return "";
}

s32 func0f17dac4(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = scenarioGetMaxTeams();
		break;
	case MENUOP_GETOPTIONTEXT:
		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) {
			return (s32) "\n";
		}

		return (s32) g_MpSetupSaveFile.teamnames[data->list.value];
	}

	return menuhandlerMpTeamsLabel(operation, item, data);
}

s32 menuhandlerMpTeamSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct mpchr *mpchr;

	switch (operation) {
	case MENUOP_SET:
		mpchr = func0f18c794(item->param);
		mpchr->team = data->dropdown.value;
		break;
	case MENUOP_GETOPTIONVALUE:
		mpchr = func0f18c794(item->param);

		if (!mpchr) {
			data->dropdown.value = 0xff;
		} else {
			data->dropdown.value = mpchr->team;
		}

		break;
	case MENUOP_CHECKDISABLED:
		mpchr = func0f18c794(item->param);

		if (!mpchr) {
			return 1;
		}

		return menuhandlerMpTeamsLabel(operation, item, data);
	}

	return func0f17dac4(operation, item, data);
}

char *mpMenuTextSelectTuneOrTunes(struct menuitem *item)
{
	if (mpGetUsingMultipleTunes()) {
		return langGet(L_MPMENU_069); // "Select Tune"
	}

	return langGet(L_MPMENU_068); // "Select Tunes"
}

struct menuitem g_MpAutoTeamMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_076, 0x00000000, menuhandlerMpTwoTeams }, // "Two Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_077, 0x00000000, menuhandlerMpThreeTeams }, // "Three Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_078, 0x00000000, menuhandlerMpFourTeams }, // "Four Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_079, 0x00000000, menuhandlerMpMaximumTeams }, // "Maximum Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_080, 0x00000000, menuhandlerMpHumansVsSimulants }, // "Humans vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU_081, 0x00000000, menuhandlerMpHumanSimulantPairs }, // "Human-Simulant Pairs"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_082, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAutoTeamMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_075, // "Auto Team"
	g_MpAutoTeamMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpTeamsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,     0, 0x00020000, L_MPMENU_071, 0x00000002, menuhandlerMpTeamsEnabled }, // "Teams Enabled"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, PAL ? 0x85 : 0, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000010, L_MPMENU_072, 0x00000000, menuhandlerMpTeamsLabel }, // "Teams:"
	{ MENUITEMTYPE_DROPDOWN,     0, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     1, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     2, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     3, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     4, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     5, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     6, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     7, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     8, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     9, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    10, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    11, PAL ? 0x00021000 : 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000004, L_MPMENU_073, 0x00000000, (void *)&g_MpAutoTeamMenuDialog }, // "Auto Team..."
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000008, L_MPMENU_074, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpTeamsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_070, // "Team Control"
	g_MpTeamsMenuItems,
	NULL,
	0x00000010,
	NULL,
};

u32 var80085ce8[] = {
	L_MISC_166, // "Random"
	L_MISC_167, // "Select All"
	L_MISC_168, // "Select None"
	L_MISC_169, // "Randomize"
};

/**
 * List handler for the select tune dialog.
 *
 * If multiple tracks are disabled, the listing contains the track listing plus
 * one item for Randomize.
 *
 * If multiple tracks are disabled, the listing contains the track listing plus
 * 3 items for Select All, Select None and Randomize.
 */
s32 mpSelectTuneListHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->list.value = mpGetNumUnlockedTracks();

		if (mpGetUsingMultipleTunes()) {
			data->list.value += 3;
		} else {
			data->list.value++;
		}
		break;
	case MENUOP_GETOPTIONTEXT:
		{
			s32 numtracks = mpGetNumUnlockedTracks();

			if (data->list.value < numtracks) {
				return (s32) mpGetTrackName(data->list.value);
			}

			if (mpGetUsingMultipleTunes()) {
				return (s32) langGet(var80085ce8[1 + data->list.value - numtracks]);
			}

			return (s32) langGet(var80085ce8[data->list.value - numtracks]);
		}
	case MENUOP_SET:
		{
			s32 numtracks = mpGetNumUnlockedTracks();

			if (data->list.value < numtracks) {
				if (data->list.unk04 == 0) {
					mpSetTrackSlotEnabled(data->list.value);
				}
				g_Vars.modifiedfiles |= MODFILE_MPSETUP;
			} else if (mpGetUsingMultipleTunes()) {
				s32 index = data->list.value - numtracks;

				switch (index) {
				case 0:
					mpEnableAllMultiTracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				case 1:
					mpDisableAllMultiTracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				case 2:
					mpRandomiseMultiTracks();
					g_Vars.modifiedfiles |= MODFILE_MPSETUP;
					break;
				}
			} else {
				mpSetTrackToRandom();
				g_Vars.modifiedfiles |= MODFILE_MPSETUP;
			}
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		if (mpGetUsingMultipleTunes()) {
			data->list.value = 0x000fffff;
		} else {
			s32 slotnum = mpGetCurrentTrackSlotNum();

			if (slotnum < 0) {
				data->list.value = mpGetNumUnlockedTracks();
			} else {
				data->list.value = slotnum;
			}
		}
		break;
	case MENUOP_LISTITEMFOCUS:
		if (data->list.value < mpGetNumUnlockedTracks()) {
			musicStartMenu2(mpGetTrackMusicNum(data->list.value));
		}
		break;
	case MENUOP_GETLISTITEMCHECKBOX:
		{
			s32 numtracks = mpGetNumUnlockedTracks();

			if (mpGetUsingMultipleTunes() && data->list.value < numtracks) {
				data->list.unk04 = mpIsMultiTrackSlotEnabled(data->list.value);
			}
		}
		break;
	}

	return 0;
}

s32 menudialogMpSelectTune(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		var800840e0 = 80;
	}

	if (operation == MENUOP_CLOSE) {
		var800840e0 = 15;
	}

	return false;
}

char *mpMenuTextCurrentTrack(struct menuitem *item)
{
	s32 slotnum;

	if (mpGetUsingMultipleTunes()) {
		return langGet(L_MPMENU_066); // "Multiple Tunes"
	}

	slotnum = mpGetCurrentTrackSlotNum();

	if (slotnum >= 0) {
		return mpGetTrackName(slotnum);
	}

	return langGet(L_MPMENU_067); // "Random"
}

s32 menuhandlerMpMultipleTunes(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		return mpGetUsingMultipleTunes();
	case MENUOP_SET:
		mpSetUsingMultipleTunes(data->checkbox.value);
		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler0017e06c
/*  f17e06c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f17e070:	24010011 */ 	addiu	$at,$zero,0x11
/*  f17e074:	10810006 */ 	beq	$a0,$at,.L0f17e090
/*  f17e078:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f17e07c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f17e080:	1081003f */ 	beq	$a0,$at,.L0f17e180
/*  f17e084:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17e088:	03e00008 */ 	jr	$ra
/*  f17e08c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e090:
/*  f17e090:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f17e094:	25291448 */ 	addiu	$t1,$t1,%lo(g_MpPlayerNum)
/*  f17e098:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f17e09c:	240a0e70 */ 	addiu	$t2,$zero,0xe70
/*  f17e0a0:	3c08800a */ 	lui	$t0,%hi(g_Menus)
/*  f17e0a4:	01ca0019 */ 	multu	$t6,$t2
/*  f17e0a8:	2508e000 */ 	addiu	$t0,$t0,%lo(g_Menus)
/*  f17e0ac:	3c07800b */ 	lui	$a3,%hi(g_MpSetup+0x28)
/*  f17e0b0:	24e7cbb0 */ 	addiu	$a3,$a3,%lo(g_MpSetup+0x28)
/*  f17e0b4:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f17e0b8:	00001825 */ 	or	$v1,$zero,$zero
/*  f17e0bc:	00007812 */ 	mflo	$t7
/*  f17e0c0:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f17e0c4:	8f040e1c */ 	lw	$a0,0xe1c($t8)
/*  f17e0c8:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f17e0cc:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f17e0d0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17e0d4:	00f96821 */ 	addu	$t5,$a3,$t9
/*  f17e0d8:	91ae0000 */ 	lbu	$t6,0x0($t5)
/*  f17e0dc:	00047880 */ 	sll	$t7,$a0,0x2
/*  f17e0e0:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f17e0e4:	116e001c */ 	beq	$t3,$t6,.L0f17e158
/*  f17e0e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f17e0ec:	00ef2821 */ 	addu	$a1,$a3,$t7
/*  f17e0f0:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f17e0f4:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17e0f8:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f17e0fc:	53000017 */ 	beqzl	$t8,.L0f17e15c
/*  f17e100:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e104:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f17e108:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17e10c:
/*  f17e10c:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f17e110:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e114:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17e118:	01aa0019 */ 	multu	$t5,$t2
/*  f17e11c:	00007012 */ 	mflo	$t6
/*  f17e120:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f17e124:	8df80e1c */ 	lw	$t8,0xe1c($t7)
/*  f17e128:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e12c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17e130:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17e134:	00f96821 */ 	addu	$t5,$a3,$t9
/*  f17e138:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f17e13c:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f17e140:	51640006 */ 	beql	$t3,$a0,.L0f17e15c
/*  f17e144:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e148:	50800004 */ 	beqzl	$a0,.L0f17e15c
/*  f17e14c:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e150:	546cffee */ 	bnel	$v1,$t4,.L0f17e10c
/*  f17e154:	a0c40000 */ 	sb	$a0,0x0($a2)
.L0f17e158:
/*  f17e158:	2861000b */ 	slti	$at,$v1,0xb
.L0f17e15c:
/*  f17e15c:	10200048 */ 	beqz	$at,.L0f17e280
/*  f17e160:	00433021 */ 	addu	$a2,$v0,$v1
.L0f17e164:
/*  f17e164:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e168:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e16c:	a0c00000 */ 	sb	$zero,0x0($a2)
/*  f17e170:	1420fffc */ 	bnez	$at,.L0f17e164
/*  f17e174:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17e178:	03e00008 */ 	jr	$ra
/*  f17e17c:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e180:
/*  f17e180:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f17e184:	00001825 */ 	or	$v1,$zero,$zero
/*  f17e188:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f17e18c:	11e0001d */ 	beqz	$t7,.L0f17e204
/*  f17e190:	25291448 */ 	addiu	$t1,$t1,%lo(g_MpPlayerNum)
/*  f17e194:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f17e198:	3c0d800a */ 	lui	$t5,%hi(g_Menus+0xe1c)
/*  f17e19c:	00403021 */ 	addu	$a2,$v0,$zero
/*  f17e1a0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f17e1a4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17e1a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17e1ac:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17e1b0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17e1b4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f17e1b8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17e1bc:	01b96821 */ 	addu	$t5,$t5,$t9
/*  f17e1c0:	8dadee1c */ 	lw	$t5,%lo(g_Menus+0xe1c)($t5)
/*  f17e1c4:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0x28)
/*  f17e1c8:	2718cbb0 */ 	addiu	$t8,$t8,%lo(g_MpSetup+0x28)
/*  f17e1cc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f17e1d0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f17e1d4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17e1d8:	01d82021 */ 	addu	$a0,$t6,$t8
/*  f17e1dc:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f17e1e0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17e1e4:
/*  f17e1e4:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e1e8:	a0850000 */ 	sb	$a1,0x0($a0)
/*  f17e1ec:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17e1f0:	10200004 */ 	beqz	$at,.L0f17e204
/*  f17e1f4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17e1f8:	90c50000 */ 	lbu	$a1,0x0($a2)
/*  f17e1fc:	54a0fff9 */ 	bnezl	$a1,.L0f17e1e4
/*  f17e200:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f17e204:
/*  f17e204:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f17e208:	240a0e70 */ 	addiu	$t2,$zero,0xe70
/*  f17e20c:	3c08800a */ 	lui	$t0,%hi(g_Menus)
/*  f17e210:	032a0019 */ 	multu	$t9,$t2
/*  f17e214:	2508e000 */ 	addiu	$t0,$t0,%lo(g_Menus)
/*  f17e218:	3c07800b */ 	lui	$a3,%hi(g_MpSetup+0x28)
/*  f17e21c:	24e7cbb0 */ 	addiu	$a3,$a3,%lo(g_MpSetup+0x28)
/*  f17e220:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f17e224:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f17e228:	00006812 */ 	mflo	$t5
/*  f17e22c:	010d7021 */ 	addu	$t6,$t0,$t5
/*  f17e230:	8dcf0e1c */ 	lw	$t7,0xe1c($t6)
/*  f17e234:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f17e238:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f17e23c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f17e240:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17e244:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f17e248:	03232021 */ 	addu	$a0,$t9,$v1
/*  f17e24c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e250:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e254:	a08d0000 */ 	sb	$t5,0x0($a0)
/*  f17e258:	10200006 */ 	beqz	$at,.L0f17e274
/*  f17e25c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17e260:
/*  f17e260:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f17e264:	2861000b */ 	slti	$at,$v1,0xb
/*  f17e268:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f17e26c:	1420fffc */ 	bnez	$at,.L0f17e260
/*  f17e270:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f17e274:
/*  f17e274:	8c4e0458 */ 	lw	$t6,0x458($v0)
/*  f17e278:	35cf0002 */ 	ori	$t7,$t6,0x2
/*  f17e27c:	ac4f0458 */ 	sw	$t7,0x458($v0)
.L0f17e280:
/*  f17e280:	03e00008 */ 	jr	$ra
/*  f17e284:	00001025 */ 	or	$v0,$zero,$zero
);

/**
 * item->param2 is a text ID for that team's colour. The text IDs for team
 * colours are consecutive, so the index of the team is determined by
 * subtracting the first team's colour text ID.
 */
char *mpMenuTextTeamName(struct menuitem *item)
{
	s32 index = item->param2;
	index -= L_OPTIONS_008;

	return g_MpSetupSaveFile.teamnames[index];
}

s32 menuhandlerMpTeamNameSlot(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Menus[g_MpPlayerNum].data.mpsetup.slotindex = item->param2 - 0x5608;
		menuPushDialog(&g_MpChangeTeamNameMenuDialog);
	}

	return 0;
}

char *func0f17e318(struct menudialog *dialog)
{
	sprintf(g_StringPointer, langGet(L_MPMENU_056), mpGetChallengeNameBySlot(g_Menus[g_MpPlayerNum].data.mpsetup.slotindex));
	return g_StringPointer;
}

/**
 * An "Accept" item somewhere. Probably accepting a challenge.
 */
s32 menuhandler0017e38c(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpClearCurrentChallenge();
		menuPopDialog();
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].data.mpsetup.slotindex);
	}

	return 0;
}

s32 menudialog0017e3fc(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		g_Menus[g_MpPlayerNum].unk850 = 0;

		g_Menus[g_MpPlayerNum].data.train.mpconfig = mpGetNthAvailableChallengeSomething(
				g_Menus[g_MpPlayerNum].data.train.unke1c,
				g_Menus[g_MpPlayerNum].mpconfigbuffer,
				g_Menus[g_MpPlayerNum].mpconfigbufferlen);
		break;
	case MENUOP_CLOSE:
		break;
	case MENUOP_TICK:
		if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
			menuPopDialog();
		}
		break;
	}

	return 0;
}

GLOBAL_ASM(
glabel menuhandler0017e4d4
.late_rodata
glabel var7f1b822c
.word menuhandler0017e4d4+0x6c # f17e540
glabel var7f1b8230
.word menuhandler0017e4d4+0x12c # f17e600
glabel var7f1b8234
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8238
.word menuhandler0017e4d4+0x134 # f17e608
glabel var7f1b823c
.word menuhandler0017e4d4+0x13c # f17e610
glabel var7f1b8240
.word menuhandler0017e4d4+0x7c # f17e550
glabel var7f1b8244
.word menuhandler0017e4d4+0x11c # f17e5f0
glabel var7f1b8248
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b824c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8250
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8254
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8258
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b825c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8260
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8264
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8268
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b826c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8270
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8274
.word menuhandler0017e4d4+0x144 # f17e618
glabel var7f1b8278
.word menuhandler0017e4d4+0x4cc # f17e9a0
glabel var7f1b827c
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8280
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8284
.word menuhandler0017e4d4+0x4d4 # f17e9a8
glabel var7f1b8288
.word menuhandler0017e4d4+0x50 # f17e524
.text
/*  f17e4d4:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f17e4d8:	248effff */ 	addiu	$t6,$a0,-1
/*  f17e4dc:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f17e4e0:	2dc10018 */ 	sltiu	$at,$t6,0x18
/*  f17e4e4:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f17e4e8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f17e4ec:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f17e4f0:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f17e4f4:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f17e4f8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f17e4fc:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f17e500:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f17e504:	10200128 */ 	beqz	$at,.L0f17e9a8
/*  f17e508:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f17e50c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17e510:	3c017f1c */ 	lui	$at,%hi(var7f1b822c)
/*  f17e514:	002e0821 */ 	addu	$at,$at,$t6
/*  f17e518:	8c2e822c */ 	lw	$t6,%lo(var7f1b822c)($at)
/*  f17e51c:	01c00008 */ 	jr	$t6
/*  f17e520:	00000000 */ 	nop
/*  f17e524:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0x88)
/*  f17e528:	91efcc10 */ 	lbu	$t7,%lo(g_MpSetup+0x88)($t7)
/*  f17e52c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f17e530:	55e1011e */ 	bnel	$t7,$at,.L0f17e9ac
/*  f17e534:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e538:	1000011c */ 	b	.L0f17e9ac
/*  f17e53c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17e540:	0fc66d99 */ 	jal	mpGetNumAvailableChallenges
/*  f17e544:	00000000 */ 	nop
/*  f17e548:	10000117 */ 	b	.L0f17e9a8
/*  f17e54c:	aec20000 */ 	sw	$v0,0x0($s6)
/*  f17e550:	8ed80004 */ 	lw	$t8,0x4($s6)
/*  f17e554:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f17e558:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f17e55c:	13000002 */ 	beqz	$t8,.L0f17e568
/*  f17e560:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f17e564:	aed90004 */ 	sw	$t9,0x4($s6)
.L0f17e568:
/*  f17e568:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f17e56c:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f17e570:	3c01800a */ 	lui	$at,%hi(g_Menus+0xe1c)
/*  f17e574:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f17e578:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17e57c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17e580:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f17e584:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f17e588:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f17e58c:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f17e590:	002d0821 */ 	addu	$at,$at,$t5
/*  f17e594:	ac2bee1c */ 	sw	$t3,%lo(g_Menus+0xe1c)($at)
/*  f17e598:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f17e59c:	3c048008 */ 	lui	$a0,%hi(g_MpConfirmChallengeViaListOrDetailsMenuDialog)
/*  f17e5a0:	15c00005 */ 	bnez	$t6,.L0f17e5b8
/*  f17e5a4:	00000000 */ 	nop
/*  f17e5a8:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5ac:	24845f88 */ 	addiu	$a0,$a0,%lo(g_MpConfirmChallengeViaListOrDetailsMenuDialog)
/*  f17e5b0:	100000fe */ 	b	.L0f17e9ac
/*  f17e5b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e5b8:
/*  f17e5b8:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f17e5bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17e5c0:	3c048008 */ 	lui	$a0,%hi(g_MpConfirmChallengeMenuDialog)
/*  f17e5c4:	15e10006 */ 	bne	$t7,$at,.L0f17e5e0
/*  f17e5c8:	00000000 */ 	nop
/*  f17e5cc:	3c048007 */ 	lui	$a0,%hi(g_MpConfirmChallenge4MbMenuDialog)
/*  f17e5d0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5d4:	2484519c */ 	addiu	$a0,$a0,%lo(g_MpConfirmChallenge4MbMenuDialog)
/*  f17e5d8:	100000f4 */ 	b	.L0f17e9ac
/*  f17e5dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e5e0:
/*  f17e5e0:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f17e5e4:	248460ac */ 	addiu	$a0,$a0,%lo(g_MpConfirmChallengeMenuDialog)
/*  f17e5e8:	100000f0 */ 	b	.L0f17e9ac
/*  f17e5ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e5f0:	3c18000f */ 	lui	$t8,0xf
/*  f17e5f4:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f17e5f8:	100000eb */ 	b	.L0f17e9a8
/*  f17e5fc:	aed80000 */ 	sw	$t8,0x0($s6)
/*  f17e600:	100000e9 */ 	b	.L0f17e9a8
/*  f17e604:	aec00000 */ 	sw	$zero,0x0($s6)
/*  f17e608:	100000e8 */ 	b	.L0f17e9ac
/*  f17e60c:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e610:	100000e5 */ 	b	.L0f17e9a8
/*  f17e614:	aec00008 */ 	sw	$zero,0x8($s6)
/*  f17e618:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f17e61c:	3c0c8009 */ 	lui	$t4,%hi(g_Is4Mb)
/*  f17e620:	918c0af0 */ 	lbu	$t4,%lo(g_Is4Mb)($t4)
/*  f17e624:	24010001 */ 	addiu	$at,$zero,0x1
/*  f17e628:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17e62c:	8ed00008 */ 	lw	$s0,0x8($s6)
/*  f17e630:	2413000a */ 	addiu	$s3,$zero,0xa
/*  f17e634:	15810002 */ 	bne	$t4,$at,.L0f17e640
/*  f17e638:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f17e63c:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f17e640:
/*  f17e640:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f17e644:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f17e648:	256d000a */ 	addiu	$t5,$t3,0xa
/*  f17e64c:	afad00ac */ 	sw	$t5,0xac($sp)
/*  f17e650:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f17e654:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f17e658:	0fc54d8a */ 	jal	func0f153628
/*  f17e65c:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*  f17e660:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f17e664:	0fc66dbe */ 	jal	mpGetChallengeNameBySlot
/*  f17e668:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f17e66c:	0c002f02 */ 	jal	viGetWidth
/*  f17e670:	00408825 */ 	or	$s1,$v0,$zero
/*  f17e674:	00029400 */ 	sll	$s2,$v0,0x10
/*  f17e678:	0012c403 */ 	sra	$t8,$s2,0x10
/*  f17e67c:	0c002f06 */ 	jal	viGetHeight
/*  f17e680:	03009025 */ 	or	$s2,$t8,$zero
/*  f17e684:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm1)
/*  f17e688:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f17e68c:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f17e690:	8f39fb10 */ 	lw	$t9,%lo(g_FontHandelGothicSm1)($t9)
/*  f17e694:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f17e698:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f17e69c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f17e6a0:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f17e6a4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f17e6a8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f17e6ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f17e6b0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f17e6b4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f17e6b8:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f17e6bc:	02203825 */ 	or	$a3,$s1,$zero
/*  f17e6c0:	0fc5580f */ 	jal	textRenderProjected
/*  f17e6c4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f17e6c8:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f17e6cc:	0fc54de0 */ 	jal	func0f153780
/*  f17e6d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f17e6d4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f17e6d8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e6dc:	3c0ee700 */ 	lui	$t6,0xe700
/*  f17e6e0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f17e6e4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f17e6e8:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e6ec:	3c19ba00 */ 	lui	$t9,0xba00
/*  f17e6f0:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f17e6f4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e6f8:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e6fc:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f17e700:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17e704:	8fac00b4 */ 	lw	$t4,0xb4($sp)
/*  f17e708:	3c0db900 */ 	lui	$t5,0xb900
/*  f17e70c:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f17e710:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f17e714:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f17e718:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f17e71c:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*  f17e720:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f17e724:	3c18ba00 */ 	lui	$t8,0xba00
/*  f17e728:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f17e72c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f17e730:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f17e734:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f17e738:	add80000 */ 	sw	$t8,0x0($t6)
/*  f17e73c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f17e740:	3c0bba00 */ 	lui	$t3,0xba00
/*  f17e744:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f17e748:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f17e74c:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f17e750:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f17e754:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f17e758:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f17e75c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f17e760:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f17e764:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f17e768:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f17e76c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f17e770:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f17e774:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17e778:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f17e77c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f17e780:	00003825 */ 	or	$a3,$zero,$zero
/*  f17e784:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f17e788:	24a501a4 */ 	addiu	$a1,$a1,0x01a4
/*  f17e78c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f17e790:	3c0cba00 */ 	lui	$t4,0xba00
/*  f17e794:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f17e798:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f17e79c:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f17e7a0:	af000004 */ 	sw	$zero,0x4($t8)
/*  f17e7a4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f17e7a8:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e7ac:	3c0eba00 */ 	lui	$t6,0xba00
/*  f17e7b0:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f17e7b4:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17e7b8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e7bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f17e7c0:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f17e7c4:	1ae00074 */ 	blez	$s7,.L0f17e998
/*  f17e7c8:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f17e7cc:	3c128008 */ 	lui	$s2,%hi(g_ScaleX)
/*  f17e7d0:	2652fac0 */ 	addiu	$s2,$s2,%lo(g_ScaleX)
/*  f17e7d4:	241500ff */ 	addiu	$s5,$zero,0xff
/*  f17e7d8:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f17e7dc:	24510001 */ 	addiu	$s1,$v0,0x1
.L0f17e7e0:
/*  f17e7e0:	02202825 */ 	or	$a1,$s1,$zero
/*  f17e7e4:	0fc66e00 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot
/*  f17e7e8:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f17e7ec:	1040000f */ 	beqz	$v0,.L0f17e82c
/*  f17e7f0:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e7f4:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e7f8:	3c01ffe5 */ 	lui	$at,0xffe5
/*  f17e7fc:	34216500 */ 	ori	$at,$at,0x6500
/*  f17e800:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e804:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e808:	adf40000 */ 	sw	$s4,0x0($t7)
/*  f17e80c:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f17e810:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f17e814:	01950019 */ 	multu	$t4,$s5
/*  f17e818:	00005812 */ 	mflo	$t3
/*  f17e81c:	000b6a02 */ 	srl	$t5,$t3,0x8
/*  f17e820:	01a17025 */ 	or	$t6,$t5,$at
/*  f17e824:	1000000c */ 	b	.L0f17e858
/*  f17e828:	adee0004 */ 	sw	$t6,0x4($t7)
.L0f17e82c:
/*  f17e82c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e830:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e834:	adf40000 */ 	sw	$s4,0x0($t7)
/*  f17e838:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f17e83c:	3c014343 */ 	lui	$at,0x4343
/*  f17e840:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f17e844:	01950019 */ 	multu	$t4,$s5
/*  f17e848:	00005812 */ 	mflo	$t3
/*  f17e84c:	000b6a02 */ 	srl	$t5,$t3,0x8
/*  f17e850:	01a17025 */ 	or	$t6,$t5,$at
/*  f17e854:	adee0004 */ 	sw	$t6,0x4($t7)
.L0f17e858:
/*  f17e858:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f17e85c:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f17e860:	3c0cff37 */ 	lui	$t4,0xff37
/*  f17e864:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f17e868:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f17e86c:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f17e870:	37399a25 */ 	ori	$t9,$t9,0x9a25
/*  f17e874:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f17e878:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f17e87c:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e880:	01e01025 */ 	or	$v0,$t7,$zero
/*  f17e884:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f17e888:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f17e88c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f17e890:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17e894:	01601825 */ 	or	$v1,$t3,$zero
/*  f17e898:	3c01e400 */ 	lui	$at,0xe400
/*  f17e89c:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f17e8a0:	25f8000b */ 	addiu	$t8,$t7,0xb
/*  f17e8a4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8a8:	032c0019 */ 	multu	$t9,$t4
/*  f17e8ac:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f17e8b0:	02201025 */ 	or	$v0,$s1,$zero
/*  f17e8b4:	27190016 */ 	addiu	$t9,$t8,0x16
/*  f17e8b8:	00196080 */ 	sll	$t4,$t9,0x2
/*  f17e8bc:	00005812 */ 	mflo	$t3
/*  f17e8c0:	316d0fff */ 	andi	$t5,$t3,0xfff
/*  f17e8c4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f17e8c8:	01c17825 */ 	or	$t7,$t6,$at
/*  f17e8cc:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f17e8d0:	01eb6825 */ 	or	$t5,$t7,$t3
/*  f17e8d4:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f17e8d8:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f17e8dc:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f17e8e0:	01d3c021 */ 	addu	$t8,$t6,$s3
/*  f17e8e4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8e8:	032c0019 */ 	multu	$t9,$t4
/*  f17e8ec:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f17e8f0:	2673000d */ 	addiu	$s3,$s3,0xd
/*  f17e8f4:	25d8000b */ 	addiu	$t8,$t6,0xb
/*  f17e8f8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f17e8fc:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f17e900:	24190160 */ 	addiu	$t9,$zero,0x160
/*  f17e904:	3c18b400 */ 	lui	$t8,0xb400
/*  f17e908:	00007812 */ 	mflo	$t7
/*  f17e90c:	31eb0fff */ 	andi	$t3,$t7,0xfff
/*  f17e910:	000b6b00 */ 	sll	$t5,$t3,0xc
/*  f17e914:	01ac7825 */ 	or	$t7,$t5,$t4
/*  f17e918:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f17e91c:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f17e920:	3c0fb300 */ 	lui	$t7,0xb300
/*  f17e924:	256e0008 */ 	addiu	$t6,$t3,0x8
/*  f17e928:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f17e92c:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f17e930:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f17e934:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f17e938:	01602025 */ 	or	$a0,$t3,$zero
/*  f17e93c:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f17e940:	25ac0008 */ 	addiu	$t4,$t5,0x8
/*  f17e944:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f17e948:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f17e94c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f17e950:	01a02825 */ 	or	$a1,$t5,$zero
/*  f17e954:	01cb001a */ 	div	$zero,$t6,$t3
/*  f17e958:	0000c012 */ 	mflo	$t8
/*  f17e95c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f17e960:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f17e964:	35acfc00 */ 	ori	$t4,$t5,0xfc00
/*  f17e968:	15600002 */ 	bnez	$t3,.L0f17e974
/*  f17e96c:	00000000 */ 	nop
/*  f17e970:	0007000d */ 	break	0x7
.L0f17e974:
/*  f17e974:	2401ffff */ 	addiu	$at,$zero,-1
/*  f17e978:	15610004 */ 	bne	$t3,$at,.L0f17e98c
/*  f17e97c:	3c018000 */ 	lui	$at,0x8000
/*  f17e980:	15c10002 */ 	bne	$t6,$at,.L0f17e98c
/*  f17e984:	00000000 */ 	nop
/*  f17e988:	0006000d */ 	break	0x6
.L0f17e98c:
/*  f17e98c:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f17e990:	5637ff93 */ 	bnel	$s1,$s7,.L0f17e7e0
/*  f17e994:	24510001 */ 	addiu	$s1,$v0,0x1
.L0f17e998:
/*  f17e998:	10000004 */ 	b	.L0f17e9ac
/*  f17e99c:	8fa200b4 */ 	lw	$v0,0xb4($sp)
/*  f17e9a0:	240f001a */ 	addiu	$t7,$zero,0x1a
/*  f17e9a4:	aecf0000 */ 	sw	$t7,0x0($s6)
.L0f17e9a8:
/*  f17e9a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f17e9ac:
/*  f17e9ac:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f17e9b0:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f17e9b4:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f17e9b8:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f17e9bc:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f17e9c0:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f17e9c4:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f17e9c8:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f17e9cc:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f17e9d0:	03e00008 */ 	jr	$ra
/*  f17e9d4:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

/**
 * This is for a separator and fixed height thing in the dialog at:
 * Combat Simulator > Advanced Setup > Challenges > pick one > Accept
 */
s32 menuhandler0017e9d8(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpAbortChallenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}

	if (operation == MENUOP_SET) {
		mpRemoveLock();
	}

	return 0;
}

s32 menuhandlerMpStartChallenge(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE) {
			return true;
		}
	}
	if (operation == MENUOP_SET) {
		menuPushDialog(&g_MpReadyMenuDialog);
	}

	return 0;
}

char *mpMenuTextChallengeName(struct menuitem *item)
{
	if (g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE) {
		return langGet(L_MPMENU_050); // "Combat Challenges"
	}

	sprintf(g_StringPointer, "%s:\n", mpChallengeGetName(mpGetCurrentChallengeIndex()));
	return g_StringPointer;
}

s32 mpCombatChallengesMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE
				&& g_Menus[g_MpPlayerNum].curframe
				&& g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& !mpIsChallengeLoaded()) {
			g_Menus[g_MpPlayerNum].unk850 = 0x4fac5ace;

			mpLoadAndStoreCurrentChallenge(
					g_Menus[g_MpPlayerNum].mpconfigbuffer,
					g_Menus[g_MpPlayerNum].mpconfigbufferlen);
		}
	}

	if (operation == MENUOP_CLOSE) {
		if (g_Menus[g_MpPlayerNum].unk850 == 0x4fac5ace) {
			mpClearCurrentChallenge();
		}
	}

	return 0;
}

s32 menuhandler0017ec64(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		mpSetCurrentChallenge(g_Menus[g_MpPlayerNum].data.mpsetup.slotindex);
		func0f0f820c(&g_MpQuickGoMenuDialog, 3);
	}

	return 0;
}

struct menuitem g_MpSelectTunesMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x0000004d, mpSelectTuneListHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSelectTunesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextSelectTuneOrTunes,
	g_MpSelectTunesMenuItems,
	menudialogMpSelectTune,
	0x00000010,
	NULL,
};

struct menuitem g_MpSoundtrackMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU_063, 0x00000000, NULL }, // "Current:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS_003, (u32)&mpMenuTextCurrentTrack, NULL }, // ""
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, (u32)&mpMenuTextSelectTuneOrTunes, 0x00000000, (void *)&g_MpSelectTunesMenuDialog },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00020000, L_MPMENU_064, 0x00000000, menuhandlerMpMultipleTunes }, // "Multiple Tunes"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_065, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpSoundtrackMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_062, // "Soundtrack"
	g_MpSoundtrackMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpChangeTeamNameMenuItems[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler0017e06c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpChangeTeamNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_061, // "Change Team Name"
	g_MpChangeTeamNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpTeamNamesMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_008, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Red"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_009, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Yellow"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_010, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Blue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_011, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Magenta"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_012, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Cyan"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_013, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Orange"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_014, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Pink"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS_015, (u32)&mpMenuTextTeamName, menuhandlerMpTeamNameSlot }, // "Brown"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_060, 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpTeamNamesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_059, // "Team Names"
	g_MpTeamNamesMenuItems,
	NULL,
	0x00000010,
	NULL,
};

struct menuitem g_MpConfirmChallengeViaListOrDetailsMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   PAL ? 0x41 : 0x37, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00060000, L_MPMENU_057, 0x00000000, menuhandler0017e38c }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU_058, 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

struct menudialog g_MpConfirmChallengeViaListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallengeViaListOrDetailsMenuItems,
	menudialog0017e3fc,
	0x00000014,
	NULL,
};

struct menuitem g_MpChallengesListOrDetailsMenuItems[] = {
	{ MENUITEMTYPE_LIST,       0,                       0x00200000, 0x00000078,       0x0000004d, menuhandler0017e4d4         },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCHALLENGE, 0x00000000, 0x0000007c,       PAL ? 0x41 : 0x37, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SEPARATOR,  0,                       0x00000000, 0x00000000,       0x00000000, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPWEAPONS_171, 0x00000000, menuhandlerMpStartChallenge }, // "Start Challenge"
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPMENU_051,     0x00000000, menuhandlerMpAbortChallenge }, // "Abort Challenge"
	{ MENUITEMTYPE_END,        0,                       0x00000000, 0x00000000,       0x00000000, NULL                        },
};

struct menudialog g_MpChallengeListOrDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	g_MpChallengesListOrDetailsMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000808,
	NULL,
};

struct menudialog g_MpAdvancedSetupViaAdvChallengeMenuDialog;

struct menudialog g_MpChallengeListOrDetailsViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	g_MpChallengesListOrDetailsMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000808,
	&g_MpAdvancedSetupViaAdvChallengeMenuDialog,
};

struct menuitem g_MpConfirmChallengeMenuItems[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   PAL ? 0x41 : 0x37, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU_057, 0x00000000, menuhandler0017ec64 }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU_058, 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

struct menudialog g_MpConfirmChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	g_MpConfirmChallengeMenuItems,
	menudialog0017e3fc,
	0x00000004,
	NULL,
};

struct menuitem g_MpChallengesMenuItems[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpChallengesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_050, // "Combat Challenges"
	g_MpChallengesMenuItems,
	mpCombatChallengesMenuDialog,
	0x00000000,
	NULL,
};

s32 menuhandlerMpLock(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
		L_MPMENU_045, // "None"
		L_MPMENU_046, // "Last Winner"
		L_MPMENU_047, // "Last Loser"
		L_MPMENU_048, // "Random"
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = mpGetLockType() == MPLOCKTYPE_CHALLENGE ? 1 : 5;
		break;
	case MENUOP_GETOPTIONTEXT:
		if (mpGetLockType() == MPLOCKTYPE_CHALLENGE) {
			return (s32) langGet(L_MPMENU_049); // "Challenge"
		}
		if (data->dropdown.value <= 3) {
			return (s32) langGet(labels[data->dropdown.value]);
		}
		if (mpGetLockType() == MPLOCKTYPE_PLAYER) {
			return (s32) g_MpPlayers[mpGetLockPlayerNum()].base.name;
		}
		return (s32) mpGetCurrentPlayerName(item);
	case MENUOP_SET:
		if (mpGetLockType() != MPLOCKTYPE_CHALLENGE) {
			mpSetLock(data->dropdown.value, g_MpPlayerNum);
		}
		g_Vars.modifiedfiles |= MODFILE_MPSETUP;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = mpGetLockType() == MPLOCKTYPE_CHALLENGE ? 0 : mpGetLockType();
		break;
	}

	return 0;
}

s32 menuhandlerMpSavePlayer(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_MpPlayers[g_MpPlayerNum].unk4c.unk00 == false) {
			filemgrPushSelectLocationDialog(6, 2);
		} else {
			menuPushDialog(&g_MpSavePlayerMenuDialog);
		}
	}

	return 0;
}

char *mpMenuTextSavePlayerOrCopy(struct menuitem *item)
{
	if (g_MpPlayers[g_MpPlayerNum].unk4c.unk00 == false) {
		return langGet(L_MPMENU_038); // "Save Player"
	}

	return langGet(L_MPMENU_039); // "Save Copy of Player"
}

s32 menuhandler0017ef30(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			if (IS4MB()) {
				func0f0f820c(&g_CiMenuViaPauseMenuDialog, 2);
			} else {
				func0f0f820c(&g_CiMenuViaPcMenuDialog, 2);
			}
		} else {
			func0f0f820c(&g_SoloMissionPauseMenuDialog, 2);
		}
	}

	return 0;
}

s32 menuhandlerMpSaveSettings(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (g_MpSetup.unk20.unk00 == false) {
			menuPushDialog(&g_MpSaveSetupNameMenuDialog);
		} else {
			func0f108324(g_MpSetup.unk20.unk04);
			menuPushDialog(&g_MpSaveSetupExistsMenuDialog);
		}
	}

	return 0;
}

char *mpMenuTextArenaName(struct menuitem *item)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MpArenas); i++) {
		if (g_MpArenas[i].stagenum == g_MpSetup.stagenum) {
			return langGet(g_MpArenas[i].name);
		}
	}

	return "\n";
}

char *mpMenuTextWeaponSetName(struct menuitem *item)
{
	return mpGetWeaponSetName(mpGetWeaponSet());
}

s32 menudialogMpGameSetup(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000490 = 1;
		g_Vars.unk00049c = 1;
	}

	return false;
}

s32 menudialogMpQuickGo(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000490 = 3;
	}

	return false;
}

void mpConfigureQuickTeamPlayers(void)
{
	s32 i;

	if (g_Vars.mpquickteam != MPQUICKTEAM_NONE) {
		for (i = 0; i < 8; i++) {
			mpRemoveSimulant(i);
		}

		switch (g_Vars.mpquickteam) {
		case MPQUICKTEAM_PLAYERSONLY:
			g_MpSetup.options &= ~MPOPTION_TEAMSENABLED;
			break;
		case MPQUICKTEAM_PLAYERSANDSIMS:
			g_MpSetup.options &= ~MPOPTION_TEAMSENABLED;
			break;
		case MPQUICKTEAM_PLAYERSTEAMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < 4; i++) {
				g_MpPlayers[i].base.team = g_Vars.mpplayerteams[i];
			}

			break;
		case MPQUICKTEAM_PLAYERSVSSIMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < 4; i++) {
				g_MpPlayers[i].base.team = 0;
			}

			break;
		case MPQUICKTEAM_PLAYERSIMTEAMS:
			g_MpSetup.options |= MPOPTION_TEAMSENABLED;

			for (i = 0; i < 4; i++) {
				g_MpPlayers[i].base.team = i;
			}

			break;
		}
	}
}

void mpConfigureQuickTeamSimulants(void)
{
	struct mpchr *mpchr;
	s32 numchrs;
	s32 numsims;
	s32 i;
	s32 j;

	if (g_Vars.mpquickteam != MPQUICKTEAM_NONE) {
		switch (g_Vars.mpquickteam) {
		case MPQUICKTEAM_PLAYERSANDSIMS:
			for (i = 0; i < g_Vars.mpquickteamnumsims; i++) {
				numsims = mpGetNumSimulants();

				if (numsims >= 0) {
					func0f18c984(numsims, g_Vars.mpsimdifficulty);
				}
			}

			func0f18cddc();
			break;
		case MPQUICKTEAM_PLAYERSVSSIMS:
			for (i = 0; i < g_Vars.mpquickteamnumsims; i++) {
				numsims = mpGetNumSimulants();

				if (numsims >= 0) {
					func0f18c984(numsims, g_Vars.mpsimdifficulty);
				}
			}

			func0f18cddc();

			for (i = 0; i < ARRAYCOUNT(g_MpSimulants); i++) {
				g_MpSimulants[i].base.team = 1;
			}

			break;
		case MPQUICKTEAM_PLAYERSIMTEAMS:
			for (i = mpGetNumChrs() - 1; i >= 0; i--) {
				mpchr = func0f18c794(i);

				for (j = 0; j < g_Vars.unk0004a0; j++) {
					numsims = mpGetNumSimulants();

					if (numsims >= 0) {
						func0f18c984(numsims, g_Vars.mpsimdifficulty);
						g_MpSimulants[numsims].base.team = mpchr->team;
					}
				}
			}

			func0f18cddc();
			break;
		case MPQUICKTEAM_PLAYERSONLY:
		case MPQUICKTEAM_PLAYERSTEAMS:
			break;
		}
	}
}

void func0f17f428(void)
{
	mpConfigureQuickTeamPlayers();

	if (IS4MB()) {
		func0f0f820c(&g_MpQuickGo4MbMenuDialog, MENUROOT_4MBMAINMENU);
	} else {
		func0f0f820c(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
	}
}

s32 menuhandlerMpFinishedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKPREFOCUSED) {
		return true;
	}

	if (operation == MENUOP_SET) {
		func0f17f428();
	}

	return 0;
}

s32 menuhandlerQuickTeamSeparator(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKHIDDEN) {
		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerPlayerTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 8;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32) &g_MpSetupSaveFile.teamnames[data->dropdown.value];
	case MENUOP_SET:
		g_Vars.mpplayerteams[item->param] = data->dropdown.value;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.mpplayerteams[item->param];
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSTEAMS) {
			return true;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpNumberOfSimulants(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = !mpIsFeatureUnlocked(MPFEATURE_8BOTS) ? 4 : 8;
		break;
	case MENUOP_GETOPTIONTEXT:
		sprintf(g_StringPointer, "%d\n", data->dropdown.value + 1);
		return (s32) g_StringPointer;
	case MENUOP_SET:
		g_Vars.mpquickteamnumsims = data->dropdown.value + 1;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.mpquickteamnumsims - 1;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSANDSIMS
				&& g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSVSSIMS) {
			return true;
		}
		break;
	}

	return 0;
}

s32 menuhandlerMpSimulantsPerTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 2;
		break;
	case MENUOP_GETOPTIONTEXT:
		sprintf(g_StringPointer, "%d\n", data->dropdown.value + 1);
		return (s32) g_StringPointer;
	case MENUOP_SET:
		g_Vars.unk0004a0 = data->dropdown.value + 1;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.unk0004a0 - 1;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != MPQUICKTEAM_PLAYERSIMTEAMS) {
			return true;
		}
		break;
	}

	return 0;
}

s32 mpQuickTeamSimulantDifficultyHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	s32 count = 0;
	s32 i;

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < 6; i++) {
			if (mpIsFeatureUnlocked(g_MpSimulantTypes[i].requirefeature)) {
				count++;
			}
		}

		data->dropdown.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < 6; i++) {
			if (mpIsFeatureUnlocked(g_MpSimulantTypes[i].requirefeature)) {
				if (count == data->dropdown.value) {
					return (s32) langGet(i + L_MISC_082);
				}

				count++;
			}
		}
		break;
	case MENUOP_SET:
		g_Vars.mpsimdifficulty = data->dropdown.value;
		break;
	case MENUOP_GETOPTIONVALUE:
		data->dropdown.value = g_Vars.mpsimdifficulty;
		break;
	case MENUOP_CHECKHIDDEN:
		if (g_Vars.mpquickteam != 1 && g_Vars.mpquickteam != 3 && g_Vars.mpquickteam != 4) {
			return true;
		}
	}

	return 0;
}

s32 menuhandlerMpQuickTeamOption(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_Vars.mpquickteam = item->param;

		if (mpGetWeaponSet() >= func0f189058(0)) {
			mpSetWeaponSet(0);
		}

		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY ||
				g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSANDSIMS) {
			if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL ||
					g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
				g_MpSetup.scenario = MPSCENARIO_COMBAT;
			}
		}

		menuPushDialog(&g_MpQuickTeamGameSetupMenuDialog);
	}

	return 0;
}

s32 menudialogCombatSimulator(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		g_Vars.unk000494[0] = 0;
		g_Vars.unk000494[1] = 0;
		g_Vars.unk000494[2] = 0;
		g_Vars.unk000494[3] = 0;
	}

	if (g_Menus[g_MpPlayerNum].curframe
			&& g_Menus[g_MpPlayerNum].curframe->dialog == &g_CombatSimulatorMenuDialog
			&& operation == MENUOP_TICK) {
		g_Vars.unk000490 = 2;
		g_Vars.mpquickteam = MPQUICKTEAM_NONE;
		g_Vars.unk00049c = 0;
		mpClearCurrentChallenge();
		mpRemoveLock();
	}

	return false;
}

s32 menuhandlerMpAdvancedSetup(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f0f820c(&g_MpAdvancedSetupMenuDialog, 3);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f17fa28
/*  f17fa28:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f17fa2c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f17fa30:	3c1f8007 */ 	lui	$ra,%hi(g_MpPlayerNum)
/*  f17fa34:	27ff1448 */ 	addiu	$ra,$ra,%lo(g_MpPlayerNum)
/*  f17fa38:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f17fa3c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f17fa40:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f17fa44:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f17fa48:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f17fa4c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f17fa50:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17fa54:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f17fa58:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f17fa5c:	3c118008 */ 	lui	$s1,%hi(g_MpSaveSetupNameMenuDialog)
/*  f17fa60:	3c128008 */ 	lui	$s2,%hi(g_MpSaveSetupExistsMenuDialog)
/*  f17fa64:	3c138008 */ 	lui	$s3,%hi(g_MpAddSimulantMenuDialog)
/*  f17fa68:	3c148008 */ 	lui	$s4,%hi(g_MpChangeSimulantMenuDialog)
/*  f17fa6c:	3c158008 */ 	lui	$s5,%hi(g_MpEditSimulantMenuDialog)
/*  f17fa70:	3c168008 */ 	lui	$s6,%hi(g_MpCombatOptionsMenuDialog)
/*  f17fa74:	3c178008 */ 	lui	$s7,%hi(g_MpBriefcaseOptionsMenuDialog)
/*  f17fa78:	3c1e8008 */ 	lui	$s8,%hi(g_MpCaptureOptionsMenuDialog)
/*  f17fa7c:	3c098008 */ 	lui	$t1,%hi(g_MpPopacapOptionsMenuDialog)
/*  f17fa80:	3c088008 */ 	lui	$t0,%hi(g_MpHackerOptionsMenuDialog)
/*  f17fa84:	3c078008 */ 	lui	$a3,%hi(g_MpHillOptionsMenuDialog)
/*  f17fa88:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f17fa8c:	24e76ce0 */ 	addiu	$a3,$a3,%lo(g_MpHillOptionsMenuDialog)
/*  f17fa90:	25086dfc */ 	addiu	$t0,$t0,%lo(g_MpHackerOptionsMenuDialog)
/*  f17fa94:	25296f80 */ 	addiu	$t1,$t1,%lo(g_MpPopacapOptionsMenuDialog)
/*  f17fa98:	27de6b48 */ 	addiu	$s8,$s8,%lo(g_MpCaptureOptionsMenuDialog)
/*  f17fa9c:	26f769d4 */ 	addiu	$s7,$s7,%lo(g_MpBriefcaseOptionsMenuDialog)
/*  f17faa0:	26d668b8 */ 	addiu	$s6,$s6,%lo(g_MpCombatOptionsMenuDialog)
/*  f17faa4:	26b5592c */ 	addiu	$s5,$s5,%lo(g_MpEditSimulantMenuDialog)
/*  f17faa8:	26945834 */ 	addiu	$s4,$s4,%lo(g_MpChangeSimulantMenuDialog)
/*  f17faac:	2673581c */ 	addiu	$s3,$s3,%lo(g_MpAddSimulantMenuDialog)
/*  f17fab0:	26524d80 */ 	addiu	$s2,$s2,%lo(g_MpSaveSetupExistsMenuDialog)
/*  f17fab4:	26314cdc */ 	addiu	$s1,$s1,%lo(g_MpSaveSetupNameMenuDialog)
/*  f17fab8:	00001025 */ 	or	$v0,$zero,$zero
/*  f17fabc:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f17fac0:	0002c0c0 */ 	sll	$t8,$v0,0x3
.L0f17fac4:
/*  f17fac4:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f17fac8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f17facc:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f17fad0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f17fad4:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f17fad8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f17fadc:	3c19800a */ 	lui	$t9,%hi(g_Menus+0x4f8)
/*  f17fae0:	afe20000 */ 	sw	$v0,0x0($ra)
/*  f17fae4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f17fae8:	8f39e4f8 */ 	lw	$t9,%lo(g_Menus+0x4f8)($t9)
/*  f17faec:	5320005f */ 	beqzl	$t9,.L0f17fc6c
/*  f17faf0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f17faf4:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f17faf8:	8fe20000 */ 	lw	$v0,0x0($ra)
.L0f17fafc:
/*  f17fafc:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f17fb00:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f17fb04:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f17fb08:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17fb0c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f17fb10:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f17fb14:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17fb18:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f17fb1c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f17fb20:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f17fb24:	870d04f4 */ 	lh	$t5,0x4f4($t8)
/*  f17fb28:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f17fb2c:	00005025 */ 	or	$t2,$zero,$zero
/*  f17fb30:	19a0003e */ 	blez	$t5,.L0f17fc2c
/*  f17fb34:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f17fb38:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f17fb3c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f17fb40:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f17fb44:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f17fb48:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f17fb4c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f17fb50:	032f6021 */ 	addu	$t4,$t9,$t7
/*  f17fb54:	01805825 */ 	or	$t3,$t4,$zero
.L0f17fb58:
/*  f17fb58:	81620478 */ 	lb	$v0,0x478($t3)
/*  f17fb5c:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f17fb60:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f17fb64:	1840002d */ 	blez	$v0,.L0f17fc1c
/*  f17fb68:	00002025 */ 	or	$a0,$zero,$zero
/*  f17fb6c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f17fb70:	018e2821 */ 	addu	$a1,$t4,$t6
/*  f17fb74:	00023080 */ 	sll	$a2,$v0,0x2
.L0f17fb78:
/*  f17fb78:	8ca30464 */ 	lw	$v1,0x464($a1)
/*  f17fb7c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f17fb80:	0086082a */ 	slt	$at,$a0,$a2
/*  f17fb84:	10600023 */ 	beqz	$v1,.L0f17fc14
/*  f17fb88:	00000000 */ 	nop
/*  f17fb8c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f17fb90:	14510002 */ 	bne	$v0,$s1,.L0f17fb9c
/*  f17fb94:	00000000 */ 	nop
/*  f17fb98:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fb9c:
/*  f17fb9c:	14520002 */ 	bne	$v0,$s2,.L0f17fba8
/*  f17fba0:	00000000 */ 	nop
/*  f17fba4:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fba8:
/*  f17fba8:	14530002 */ 	bne	$v0,$s3,.L0f17fbb4
/*  f17fbac:	00000000 */ 	nop
/*  f17fbb0:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbb4:
/*  f17fbb4:	14540002 */ 	bne	$v0,$s4,.L0f17fbc0
/*  f17fbb8:	00000000 */ 	nop
/*  f17fbbc:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbc0:
/*  f17fbc0:	14550002 */ 	bne	$v0,$s5,.L0f17fbcc
/*  f17fbc4:	00000000 */ 	nop
/*  f17fbc8:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbcc:
/*  f17fbcc:	14560002 */ 	bne	$v0,$s6,.L0f17fbd8
/*  f17fbd0:	00000000 */ 	nop
/*  f17fbd4:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbd8:
/*  f17fbd8:	14570002 */ 	bne	$v0,$s7,.L0f17fbe4
/*  f17fbdc:	00000000 */ 	nop
/*  f17fbe0:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbe4:
/*  f17fbe4:	145e0002 */ 	bne	$v0,$s8,.L0f17fbf0
/*  f17fbe8:	00000000 */ 	nop
/*  f17fbec:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbf0:
/*  f17fbf0:	14470002 */ 	bne	$v0,$a3,.L0f17fbfc
/*  f17fbf4:	00000000 */ 	nop
/*  f17fbf8:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fbfc:
/*  f17fbfc:	14480002 */ 	bne	$v0,$t0,.L0f17fc08
/*  f17fc00:	00000000 */ 	nop
/*  f17fc04:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fc08:
/*  f17fc08:	14490002 */ 	bne	$v0,$t1,.L0f17fc14
/*  f17fc0c:	00000000 */ 	nop
/*  f17fc10:	00008025 */ 	or	$s0,$zero,$zero
.L0f17fc14:
/*  f17fc14:	1420ffd8 */ 	bnez	$at,.L0f17fb78
/*  f17fc18:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f17fc1c:
/*  f17fc1c:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f17fc20:	014d082a */ 	slt	$at,$t2,$t5
/*  f17fc24:	1420ffcc */ 	bnez	$at,.L0f17fb58
/*  f17fc28:	256b0018 */ 	addiu	$t3,$t3,0x18
.L0f17fc2c:
/*  f17fc2c:	1600000b */ 	bnez	$s0,.L0f17fc5c
/*  f17fc30:	00000000 */ 	nop
/*  f17fc34:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f17fc38:	00000000 */ 	nop
/*  f17fc3c:	3c078008 */ 	lui	$a3,%hi(g_MpHillOptionsMenuDialog)
/*  f17fc40:	3c088008 */ 	lui	$t0,%hi(g_MpHackerOptionsMenuDialog)
/*  f17fc44:	3c098008 */ 	lui	$t1,%hi(g_MpPopacapOptionsMenuDialog)
/*  f17fc48:	3c1f8007 */ 	lui	$ra,%hi(g_MpPlayerNum)
/*  f17fc4c:	27ff1448 */ 	addiu	$ra,$ra,%lo(g_MpPlayerNum)
/*  f17fc50:	25296f80 */ 	addiu	$t1,$t1,%lo(g_MpPopacapOptionsMenuDialog)
/*  f17fc54:	25086dfc */ 	addiu	$t0,$t0,%lo(g_MpHackerOptionsMenuDialog)
/*  f17fc58:	24e76ce0 */ 	addiu	$a3,$a3,%lo(g_MpHillOptionsMenuDialog)
.L0f17fc5c:
/*  f17fc5c:	5200ffa7 */ 	beqzl	$s0,.L0f17fafc
/*  f17fc60:	8fe20000 */ 	lw	$v0,0x0($ra)
/*  f17fc64:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f17fc68:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f17fc6c:
/*  f17fc6c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f17fc70:	5441ff94 */ 	bnel	$v0,$at,.L0f17fac4
/*  f17fc74:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f17fc78:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f17fc7c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f17fc80:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f17fc84:	aff80000 */ 	sw	$t8,0x0($ra)
/*  f17fc88:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f17fc8c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f17fc90:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f17fc94:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f17fc98:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f17fc9c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f17fca0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f17fca4:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f17fca8:	03e00008 */ 	jr	$ra
/*  f17fcac:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

struct menudialog g_MpAbortMenuDialog;

struct menuitem g_MpStuffMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_041, 0x00000000, (void *)&g_MpSoundtrackMenuDialog }, // "Soundtrack"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_042, 0x00000000, (void *)&g_MpTeamNamesMenuDialog }, // "Team Names"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU_044, 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS_216, 0x00000000, menuhandlerScreenRatio }, // "Ratio"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPWEAPONS_154, 0x00000000, menuhandlerScreenSplit }, // "Split"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_036, 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_037, 0x00000000, (void *)&g_MpDropOutMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_027, 0x00000000, (void *)&g_MpAbortMenuDialog }, // "Abort Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpStuffMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_040, // "Stuff"
	g_MpStuffMenuItems,
	NULL,
	0x00000810,
	&g_MpChallengeListOrDetailsMenuDialog,
};

struct menudialog g_MpStuffViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_040, // "Stuff"
	g_MpStuffMenuItems,
	NULL,
	0x00000810,
	NULL,
};

struct menuitem g_MpPlayerSetup234MenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_030, (u32)&mpGetCurrentPlayerName, (void *)&g_MpPlayerNameMenuDialog }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_031, 0x00000000, (void *)&g_MpCharacterMenuDialog }, // "Character"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_033, 0x00000000, (void *)&g_MpControlMenuDialog }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_034, 0x00000000, (void *)&g_MpPlayerOptionsMenuDialog }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_035, 0x00000000, (void *)&g_MpPlayerStatsMenuDialog }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_029, 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpPlayerSetupViaAdvMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0x00000800,
	&g_MpStuffMenuDialog,
};

struct menudialog g_MpPlayerSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0x00000800,
	&g_MpStuffViaAdvChallengeMenuDialog,
};

struct menudialog g_MpPlayerSetupViaQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_028, // "Player Setup"
	g_MpPlayerSetup234MenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpAbortMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU_053, 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_054, 0x00000000, menuhandler0017ef30 }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU_055, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAbortMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU_052, // "Abort"
	g_MpAbortMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpAdvancedSetupMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU_019, (u32)&mpMenuTextScenarioShortName, (void *)&g_MpScenarioMenuDialog }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_021, 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_020, (u32)&mpMenuTextArenaName, (void *)&g_MpArenaMenuDialog }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_023, 0x00000000, (void *)&g_MpWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_024, 0x00000000, (void *)&g_MpLimitsMenuDialog }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS_184, 0x00000000, (void *)&g_MpHandicapsMenuDialog }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_025, 0x00000000, (void *)&g_MpSimulantsMenuDialog }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_022, 0x00000000, (void *)&g_MpTeamsMenuDialog }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU_018, 0x00000000, (void *)&g_MpLoadSettingsMenuDialog }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_026, 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpAdvancedSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialogMpGameSetup,
	0x00000810,
	&g_MpPlayerSetupViaAdvMenuDialog,
};

struct menudialog g_MpAdvancedSetupViaAdvChallengeMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpAdvancedSetupMenuItems,
	menudialogMpGameSetup,
	0x00000810,
	&g_MpPlayerSetupViaAdvChallengeMenuDialog,
};

struct menuitem g_MpQuickGoMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_456, 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_029, 0x00000000, (void *)&g_MpLoadPlayerMenuDialog }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_458, 0x00000000, (void *)&g_MpPlayerSetupViaQuickGoMenuDialog }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC_457, 0x00000000, (void *)&g_MpDropOutMenuDialog }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_460, // "Quick Go"
	g_MpQuickGoMenuItems,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

struct menuitem g_MpQuickTeamGameSetupMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU_019, (u32)&mpMenuTextScenarioShortName, (void *)&g_MpQuickTeamScenarioMenuDialog }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU_021, 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_020, (u32)&mpMenuTextArenaName, (void *)&g_MpArenaMenuDialog }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_023, (u32)&mpMenuTextWeaponSetName, (void *)&g_MpQuickTeamWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU_024, 0x00000000, (void *)&g_MpLimitsMenuDialog }, // "Limits"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, menuhandlerQuickTeamSeparator },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_449, 0x00000000, menuhandlerPlayerTeam }, // "Player 1 Team"
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00000000, L_MISC_450, 0x00000000, menuhandlerPlayerTeam }, // "Player 2 Team"
	{ MENUITEMTYPE_DROPDOWN,    2, 0x00000000, L_MISC_451, 0x00000000, menuhandlerPlayerTeam }, // "Player 3 Team"
	{ MENUITEMTYPE_DROPDOWN,    3, 0x00000000, L_MISC_452, 0x00000000, menuhandlerPlayerTeam }, // "Player 4 Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_453, 0x00000000, menuhandlerMpNumberOfSimulants }, // "Number Of Simulants"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_454, 0x00000000, menuhandlerMpSimulantsPerTeam }, // "Simulants Per Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC_455, 0x00000000, mpQuickTeamSimulantDifficultyHandler }, // "Simulant Difficulty"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC_448, 0x00000000, menuhandlerMpFinishedSetup }, // "Finished Setup"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU_026, 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamGameSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_017, // "Game Setup"
	g_MpQuickTeamGameSetupMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem g_MpQuickTeamMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC_463, 0x00000000, menuhandlerMpQuickTeamOption }, // "Players Only"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00400000, L_MISC_464, 0x00000000, menuhandlerMpQuickTeamOption }, // "Players and Simulants"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00400000, L_MISC_465, 0x00000000, menuhandlerMpQuickTeamOption }, // "Player Teams"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00400000, L_MISC_466, 0x00000000, menuhandlerMpQuickTeamOption }, // "Players vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00400000, L_MISC_467, 0x00000000, menuhandlerMpQuickTeamOption }, // "Player-Simulant Teams"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_462, // "Quick Team"
	g_MpQuickTeamMenuItems,
	NULL,
	0x00000004,
	NULL,
};

struct menuitem g_CombatSimulatorMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_441, 0x00000000, (void *)&g_MpChallengesMenuDialog }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_442, 0x00000001, (void *)&g_MpLoadPresetMenuDialog }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC_443, 0x00000002, (void *)&g_MpQuickTeamMenuDialog }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC_444, 0x00000003, menuhandlerMpAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_CombatSimulatorMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC_445, // "Combat Simulator"
	g_CombatSimulatorMenuItems,
	menudialogCombatSimulator,
	0x00000004,
	NULL,
};
