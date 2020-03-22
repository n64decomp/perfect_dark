#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_016100.h"
#include "game/game_01b0a0.h"
#include "game/game_095320.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0e0770.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/gamefile.h"
#include "game/game_1655c0.h"
#include "game/game_167ae0.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var7f1b3860[] = "%s: %s\n";
const char var7f1b3868[] = "%s: %s\n";

s32 menuhandlerDeclineMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog0010cd0c
/*  f10cd0c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f10cd10:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10cd14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10cd18:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f10cd1c:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f10cd20:	1481004c */ 	bne	$a0,$at,.L0f10ce54
/*  f10cd24:	00a03825 */ 	or	$a3,$a1,$zero
/*  f10cd28:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f10cd2c:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f10cd30:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0x4f8)
/*  f10cd34:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10cd38:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10cd3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10cd40:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10cd44:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10cd48:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10cd4c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10cd50:	00581021 */ 	addu	$v0,$v0,$t8
/*  f10cd54:	8c42e4f8 */ 	lw	$v0,%lo(g_MenuStack+0x4f8)($v0)
/*  f10cd58:	5040003f */ 	beqzl	$v0,.L0f10ce58
/*  f10cd5c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f10cd60:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f10cd64:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f10cd68:	50a40007 */ 	beql	$a1,$a0,.L0f10cd88
/*  f10cd6c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f10cd70:	8ca30014 */ 	lw	$v1,0x14($a1)
/*  f10cd74:	50600038 */ 	beqzl	$v1,.L0f10ce58
/*  f10cd78:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f10cd7c:	54640036 */ 	bnel	$v1,$a0,.L0f10ce58
/*  f10cd80:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f10cd84:	8f240000 */ 	lw	$a0,0x0($t9)
.L0f10cd88:
/*  f10cd88:	00002825 */ 	or	$a1,$zero,$zero
/*  f10cd8c:	90880003 */ 	lbu	$t0,0x3($a0)
/*  f10cd90:	5100000b */ 	beqzl	$t0,.L0f10cdc0
/*  f10cd94:	8089000a */ 	lb	$t1,0xa($a0)
/*  f10cd98:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f10cd9c:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f10cda0:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10cda4:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f10cda8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10cdac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cdb0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f10cdb4:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f10cdb8:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f10cdbc:	8089000a */ 	lb	$t1,0xa($a0)
.L0f10cdc0:
/*  f10cdc0:	a0800003 */ 	sb	$zero,0x3($a0)
/*  f10cdc4:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f10cdc8:	11200002 */ 	beqz	$t1,.L0f10cdd4
/*  f10cdcc:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f10cdd0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10cdd4:
/*  f10cdd4:	908a0002 */ 	lbu	$t2,0x2($a0)
/*  f10cdd8:	a080000a */ 	sb	$zero,0xa($a0)
/*  f10cddc:	11400016 */ 	beqz	$t2,.L0f10ce38
/*  f10cde0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cde4:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f10cde8:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0x4f8)
/*  f10cdec:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f10cdf0:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f10cdf4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f10cdf8:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f10cdfc:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f10ce00:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f10ce04:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f10ce08:	004c1021 */ 	addu	$v0,$v0,$t4
/*  f10ce0c:	8c42e4f8 */ 	lw	$v0,%lo(g_MenuStack+0x4f8)($v0)
/*  f10ce10:	10400009 */ 	beqz	$v0,.L0f10ce38
/*  f10ce14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ce18:	8ce30014 */ 	lw	$v1,0x14($a3)
/*  f10ce1c:	10600006 */ 	beqz	$v1,.L0f10ce38
/*  f10ce20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ce24:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f10ce28:	146d0003 */ 	bne	$v1,$t5,.L0f10ce38
/*  f10ce2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ce30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10ce34:	a0800002 */ 	sb	$zero,0x2($a0)
.L0f10ce38:
/*  f10ce38:	10a00006 */ 	beqz	$a1,.L0f10ce54
/*  f10ce3c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10ce40:	8ce50008 */ 	lw	$a1,0x8($a3)
/*  f10ce44:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f10ce48:	0fc40cfe */ 	jal	menuhandlerAcceptMission
/*  f10ce4c:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f10ce50:	8fa70044 */ 	lw	$a3,0x44($sp)
.L0f10ce54:
/*  f10ce54:	8fa40040 */ 	lw	$a0,0x40($sp)
.L0f10ce58:
/*  f10ce58:	00e02825 */ 	or	$a1,$a3,$zero
/*  f10ce5c:	0fc40d82 */ 	jal	menudialog00103608
/*  f10ce60:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f10ce64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ce68:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f10ce6c:	03e00008 */ 	jr	$ra
/*  f10ce70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10ce74
/*  f10ce74:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10ce78:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10ce7c:	3c18800a */ 	lui	$t8,%hi(g_MenuStack+0x4f8)
/*  f10ce80:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ce84:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10ce88:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ce8c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10ce90:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10ce94:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10ce98:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ce9c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10cea0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10cea4:	8f18e4f8 */ 	lw	$t8,%lo(g_MenuStack+0x4f8)($t8)
/*  f10cea8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ceac:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f10ceb0:	10990005 */ 	beq	$a0,$t9,.L0f10cec8
/*  f10ceb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ceb8:	0fc5b9f1 */ 	jal	langGet
/*  f10cebc:	2404572c */ 	addiu	$a0,$zero,0x572c
/*  f10cec0:	10000017 */ 	beqz	$zero,.L0f10cf20
/*  f10cec4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cec8:
/*  f10cec8:	0fc5b9f1 */ 	jal	langGet
/*  f10cecc:	24045728 */ 	addiu	$a0,$zero,0x5728
/*  f10ced0:	3c08800a */ 	lui	$t0,%hi(g_MissionConfig+0x2)
/*  f10ced4:	9108dfea */ 	lbu	$t0,%lo(g_MissionConfig+0x2)($t0)
/*  f10ced8:	3c048007 */ 	lui	$a0,%hi(g_StageNames+0xa)
/*  f10cedc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10cee0:	00084880 */ 	sll	$t1,$t0,0x2
/*  f10cee4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10cee8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10ceec:	00892021 */ 	addu	$a0,$a0,$t1
/*  f10cef0:	0fc5b9f1 */ 	jal	langGet
/*  f10cef4:	94841e76 */ 	lhu	$a0,%lo(g_StageNames+0xa)($a0)
/*  f10cef8:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10cefc:	3c057f1b */ 	lui	$a1,%hi(var7f1b3860)
/*  f10cf00:	24a53860 */ 	addiu	$a1,$a1,%lo(var7f1b3860)
/*  f10cf04:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10cf08:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10cf0c:	0c004dad */ 	jal	sprintf
/*  f10cf10:	00403825 */ 	or	$a3,$v0,$zero
/*  f10cf14:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10cf18:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f10cf1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cf20:
/*  f10cf20:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10cf24:	03e00008 */ 	jr	$ra
/*  f10cf28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10cf2c
/*  f10cf2c:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10cf30:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10cf34:	3c18800a */ 	lui	$t8,%hi(g_MenuStack+0x4f8)
/*  f10cf38:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10cf3c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10cf40:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10cf44:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10cf48:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10cf4c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10cf50:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10cf54:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10cf58:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10cf5c:	8f18e4f8 */ 	lw	$t8,%lo(g_MenuStack+0x4f8)($t8)
/*  f10cf60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10cf64:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f10cf68:	10990005 */ 	beq	$a0,$t9,.L0f10cf80
/*  f10cf6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cf70:	0fc5b9f1 */ 	jal	langGet
/*  f10cf74:	2404572c */ 	addiu	$a0,$zero,0x572c
/*  f10cf78:	10000017 */ 	beqz	$zero,.L0f10cfd8
/*  f10cf7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cf80:
/*  f10cf80:	0fc5b9f1 */ 	jal	langGet
/*  f10cf84:	24045729 */ 	addiu	$a0,$zero,0x5729
/*  f10cf88:	3c08800a */ 	lui	$t0,%hi(g_MissionConfig+0x2)
/*  f10cf8c:	9108dfea */ 	lbu	$t0,%lo(g_MissionConfig+0x2)($t0)
/*  f10cf90:	3c048007 */ 	lui	$a0,%hi(g_StageNames+0xa)
/*  f10cf94:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10cf98:	00084880 */ 	sll	$t1,$t0,0x2
/*  f10cf9c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10cfa0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10cfa4:	00892021 */ 	addu	$a0,$a0,$t1
/*  f10cfa8:	0fc5b9f1 */ 	jal	langGet
/*  f10cfac:	94841e76 */ 	lhu	$a0,%lo(g_StageNames+0xa)($a0)
/*  f10cfb0:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10cfb4:	3c057f1b */ 	lui	$a1,%hi(var7f1b3868)
/*  f10cfb8:	24a53868 */ 	addiu	$a1,$a1,%lo(var7f1b3868)
/*  f10cfbc:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10cfc0:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10cfc4:	0c004dad */ 	jal	sprintf
/*  f10cfc8:	00403825 */ 	or	$a3,$v0,$zero
/*  f10cfcc:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10cfd0:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f10cfd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cfd8:
/*  f10cfd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10cfdc:	03e00008 */ 	jr	$ra
/*  f10cfe0:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerReplayPreviousMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.stageindex--;
		g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stage_id;
	}

	return menuhandlerAcceptMission(operation, NULL, value);
}

char *soloMenuTextNumKills(struct menu_item *item)
{
	sprintf(g_StringPointer, "%d", currentPlayerGetNumKills());
	return g_StringPointer;
}

char *soloMenuTextNumShots(struct menu_item *item)
{
	sprintf(g_StringPointer, "%d", currentPlayerGetShotCount(SHOTCOUNT_TOTAL));
	return g_StringPointer;
}

char *soloMenuTextNumHeadShots(struct menu_item *item)
{
	sprintf(g_StringPointer, "%d", currentPlayerGetShotCount(SHOTCOUNT_HEAD));
	return g_StringPointer;
}

char *soloMenuTextNumBodyShots(struct menu_item *item)
{
	sprintf(g_StringPointer, "%d", currentPlayerGetShotCount(SHOTCOUNT_BODY));
	return g_StringPointer;
}

char *soloMenuTextNumLimbShots(struct menu_item *item)
{
	sprintf(g_StringPointer, "%d", currentPlayerGetShotCount(SHOTCOUNT_LIMB));
	return g_StringPointer;
}

char *soloMenuTextNumOtherShots(struct menu_item *item)
{
	u32 total = currentPlayerGetShotCount(SHOTCOUNT_GUN) + currentPlayerGetShotCount(SHOTCOUNT_5);
	sprintf(g_StringPointer, "%d", total);
	return g_StringPointer;
}

char *soloMenuTextAccuracy(struct menu_item *item)
{
	s32 total = currentPlayerGetShotCount(SHOTCOUNT_TOTAL);
	s32 numhead = currentPlayerGetShotCount(SHOTCOUNT_HEAD);
	s32 numbody = currentPlayerGetShotCount(SHOTCOUNT_BODY);
	s32 numlimb = currentPlayerGetShotCount(SHOTCOUNT_LIMB);
	s32 numgun = currentPlayerGetShotCount(SHOTCOUNT_GUN);
	s32 num5 = currentPlayerGetShotCount(SHOTCOUNT_5);
	s32 numobject = currentPlayerGetShotCount(SHOTCOUNT_OBJECT);
	f32 accuracy;

	if (total > 0) {
		s32 hits = numhead + numbody + numlimb + numgun + num5 + numobject;
		accuracy = hits * 100.0f / total;
	} else {
		accuracy = 0;
	}

    if (accuracy > 100.0f) {
        accuracy = 100.0f;
    }

    sprintf(g_StringPointer, "%s%s%.1f%%", "", "", accuracy);
    return g_StringPointer;
}

char *soloMenuTextMissionStatus(struct menu_item *item)
{
	if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
		return langGet(L_MPWEAPONS(135)); // "Cheated"
	}

	if (g_Vars.coopplayernum >= 0) {
		if (g_Vars.bond->aborted || g_Vars.coop->aborted) {
			return langGet(L_OPTIONS(295)); // "Aborted"
		}

		if (g_Vars.bond->isdead && g_Vars.coop->isdead) {
			return langGet(L_OPTIONS(293)); // "Failed"
		}
	} else if (g_Vars.antiplayernum >= 0) {
		if (g_Vars.currentplayer == g_Vars.bond) {
			if (g_Vars.bond->aborted) {
				return langGet(L_OPTIONS(295)); // "Aborted"
			}

			if (g_Vars.anti->aborted) {
				return langGet(L_OPTIONS(295)); // "Aborted"
			}

			if (g_Vars.bond->isdead) {
				return langGet(L_OPTIONS(293)); // "Failed"
			}
		} else {
			if (g_Vars.anti->aborted) {
				return langGet(L_OPTIONS(295)); // "Aborted"
			}

			if (!g_Vars.bond->aborted && !g_Vars.bond->isdead) {
				return langGet(L_OPTIONS(293)); // "Failed"
			}
		}
	} else {
		if (g_Vars.bond->aborted) {
			return langGet(L_OPTIONS(295)); // "Aborted"
		}

		if (g_Vars.bond->isdead) {
			return langGet(L_OPTIONS(293)); // "Failed"
		}
	}

	if (objectiveIsAllComplete() == false) {
		return langGet(L_OPTIONS(293)); // "Failed"
	}

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		return langGet(L_MPWEAPONS(62)); // "Unknown"
	}

	return langGet(L_OPTIONS(294)); // "Completed"
}

char *soloMenuTextAgentStatus(struct menu_item *item)
{
	if (g_CheatsActiveBank0 || g_CheatsActiveBank1) {
		return langGet(L_MPWEAPONS(134)); // "Dishonored"
	}

	if (g_Vars.currentplayer->aborted) {
		return langGet(L_OPTIONS(292)); // "Disavowed"
	}

	if (g_Vars.currentplayer->isdead) {
		return langGet(L_OPTIONS(290)); // "Deceased"
	}

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		return langGet(L_MPWEAPONS(63)); // "Missing"
	}

	return langGet(L_OPTIONS(291)); // "Active"
}

GLOBAL_ASM(
glabel func0f10d588
/*  f10d588:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10d58c:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10d590:	3c18800a */ 	lui	$t8,%hi(g_MenuStack+0xe2c)
/*  f10d594:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10d598:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10d59c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d5a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d5a4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10d5a8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10d5ac:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d5b0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10d5b4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10d5b8:	8f18ee2c */ 	lw	$t8,%lo(g_MenuStack+0xe2c)($t8)
/*  f10d5bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10d5c0:	3c048007 */ 	lui	$a0,%hi(g_StageNames+0xa)
/*  f10d5c4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10d5c8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10d5cc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10d5d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d5d4:	00992021 */ 	addu	$a0,$a0,$t9
/*  f10d5d8:	0fc5b9f1 */ 	jal	langGet
/*  f10d5dc:	94841e76 */ 	lhu	$a0,%lo(g_StageNames+0xa)($a0)
/*  f10d5e0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10d5e4:	0fc5b9f1 */ 	jal	langGet
/*  f10d5e8:	24045714 */ 	addiu	$a0,$zero,0x5714
/*  f10d5ec:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10d5f0:	3c057f1b */ 	lui	$a1,%hi(var7f1b389c)
/*  f10d5f4:	24a5389c */ 	addiu	$a1,$a1,%lo(var7f1b389c)
/*  f10d5f8:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10d5fc:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10d600:	0c004dad */ 	jal	sprintf
/*  f10d604:	00403825 */ 	or	$a3,$v0,$zero
/*  f10d608:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d60c:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10d610:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f10d614:	03e00008 */ 	jr	$ra
/*  f10d618:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f10d61c
/*  f10d61c:	3c0e800a */ 	lui	$t6,%hi(g_MissionConfig+0x2)
/*  f10d620:	91cedfea */ 	lbu	$t6,%lo(g_MissionConfig+0x2)($t6)
/*  f10d624:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d628:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d62c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10d630:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d634:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d638:	3c048007 */ 	lui	$a0,%hi(g_StageNames+0xa)
/*  f10d63c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d640:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f10d644:	0fc5b9f1 */ 	jal	langGet
/*  f10d648:	94841e76 */ 	lhu	$a0,%lo(g_StageNames+0xa)($a0)
/*  f10d64c:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10d650:	3c057f1b */ 	lui	$a1,%hi(var7f1b38a4)
/*  f10d654:	24a538a4 */ 	addiu	$a1,$a1,%lo(var7f1b38a4)
/*  f10d658:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10d65c:	0c004dad */ 	jal	sprintf
/*  f10d660:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d664:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d668:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10d66c:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f10d670:	03e00008 */ 	jr	$ra
/*  f10d674:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d678
/*  f10d678:	3c0e800a */ 	lui	$t6,%hi(g_MissionConfig+0x2)
/*  f10d67c:	91cedfea */ 	lbu	$t6,%lo(g_MissionConfig+0x2)($t6)
/*  f10d680:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10d684:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10d688:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10d68c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d690:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d694:	3c048007 */ 	lui	$a0,%hi(g_StageNames+0xa)
/*  f10d698:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d69c:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f10d6a0:	0fc5b9f1 */ 	jal	langGet
/*  f10d6a4:	94841e76 */ 	lhu	$a0,%lo(g_StageNames+0xa)($a0)
/*  f10d6a8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10d6ac:	0fc5b9f1 */ 	jal	langGet
/*  f10d6b0:	24045715 */ 	addiu	$a0,$zero,0x5715
/*  f10d6b4:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10d6b8:	3c057f1b */ 	lui	$a1,%hi(var7f1b38a8)
/*  f10d6bc:	24a538a8 */ 	addiu	$a1,$a1,%lo(var7f1b38a8)
/*  f10d6c0:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10d6c4:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10d6c8:	0c004dad */ 	jal	sprintf
/*  f10d6cc:	00403825 */ 	or	$a3,$v0,$zero
/*  f10d6d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d6d4:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10d6d8:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
/*  f10d6dc:	03e00008 */ 	jr	$ra
/*  f10d6e0:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

const char var7f1b389c[] = "%s: %s\n";
const char var7f1b38a4[] = "%s\n";
const char var7f1b38a8[] = "%s: %s\n";

char *soloMenuTextMissionTime(struct menu_item *item)
{
	formatTime(g_StringPointer, getMissionTime(), 3);
	strcat(g_StringPointer, "\n");

	return g_StringPointer;
}

GLOBAL_ASM(
glabel func0f10d730
/*  f10d730:	3c03800a */ 	lui	$v1,%hi(g_MissionConfig)
/*  f10d734:	2463dfe8 */ 	addiu	$v1,$v1,%lo(g_MissionConfig)
/*  f10d738:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f10d73c:	3c088007 */ 	lui	$t0,%hi(g_StageNames)
/*  f10d740:	3c028007 */ 	lui	$v0,%hi(menudialog_promptnextmission)
/*  f10d744:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10d748:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f10d74c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10d750:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10d754:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10d758:	a06f0002 */ 	sb	$t7,0x2($v1)
/*  f10d75c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10d760:	8d081e6c */ 	lw	$t0,%lo(g_StageNames)($t0)
/*  f10d764:	24425630 */ 	addiu	$v0,$v0,%lo(menudialog_promptnextmission)
/*  f10d768:	03e00008 */ 	jr	$ra
/*  f10d76c:	a0680001 */ 	sb	$t0,0x1($v1)
);

void func0f10d770(void)
{
	func0f0f8bb4(&g_MenuStack[0].unk840, func0f09ddfc() - func0f0e4fe0(), 0);
	g_MenuStack[0].unk844 = func0f09ddec() + func0f0e4fe0();

	func0f0f8bb4(&g_MenuStack[1].unk840, func0f09ddfc() - func0f0e4fe0(), 0);
	g_MenuStack[1].unk844 = func0f09ddec() + func0f0e4fe0();

	func0f0f8bb4(&g_MenuStack[2].unk840, func0f09ddfc() - func0f0e4fe0(), 0);
	g_MenuStack[2].unk844 = func0f09ddec() + func0f0e4fe0();

	func0f0f8bb4(&g_MenuStack[3].unk840, func0f09ddfc() - func0f0e4fe0(), 0);
	g_MenuStack[3].unk844 = func0f09ddec() + func0f0e4fe0();
}

s32 menuhandlerReplayLastLevel(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stage_id;
		return menuhandlerAcceptMission(operation, NULL, value);
	}

	return 0;
}

/**
 * Displayed after Defense and Skedar Ruins completion screens.
 */
s32 menuhandlerContinueMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f10d910(2);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10d910
/*  f10d910:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10d914:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10d918:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10d91c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d920:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d924:	05c00005 */ 	bltz	$t6,.L0f10d93c
/*  f10d928:	00803825 */ 	or	$a3,$a0,$zero
/*  f10d92c:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10d930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d934:	100000f9 */ 	beqz	$zero,.L0f10dd1c
/*  f10d938:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d93c:
/*  f10d93c:	8c6f0298 */ 	lw	$t7,0x298($v1)
/*  f10d940:	05e20025 */ 	bltzl	$t7,.L0f10d9d8
/*  f10d944:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f10d948:	8c78006c */ 	lw	$t8,0x6c($v1)
/*  f10d94c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10d950:	00002025 */ 	or	$a0,$zero,$zero
/*  f10d954:	13000003 */ 	beqz	$t8,.L0f10d964
/*  f10d958:	00002825 */ 	or	$a1,$zero,$zero
/*  f10d95c:	10000001 */ 	beqz	$zero,.L0f10d964
/*  f10d960:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f10d964:
/*  f10d964:	8c790068 */ 	lw	$t9,0x68($v1)
/*  f10d968:	00001025 */ 	or	$v0,$zero,$zero
/*  f10d96c:	13200003 */ 	beqz	$t9,.L0f10d97c
/*  f10d970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d974:	10000001 */ 	beqz	$zero,.L0f10d97c
/*  f10d978:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10d97c:
/*  f10d97c:	8c680064 */ 	lw	$t0,0x64($v1)
/*  f10d980:	11000003 */ 	beqz	$t0,.L0f10d990
/*  f10d984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d988:	10000001 */ 	beqz	$zero,.L0f10d990
/*  f10d98c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10d990:
/*  f10d990:	8c690070 */ 	lw	$t1,0x70($v1)
/*  f10d994:	11200003 */ 	beqz	$t1,.L0f10d9a4
/*  f10d998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d99c:	10000001 */ 	beqz	$zero,.L0f10d9a4
/*  f10d9a0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10d9a4:
/*  f10d9a4:	00455021 */ 	addu	$t2,$v0,$a1
/*  f10d9a8:	01445821 */ 	addu	$t3,$t2,$a0
/*  f10d9ac:	01666021 */ 	addu	$t4,$t3,$a2
/*  f10d9b0:	29810002 */ 	slti	$at,$t4,0x2
/*  f10d9b4:	54200008 */ 	bnezl	$at,.L0f10d9d8
/*  f10d9b8:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f10d9bc:	54e00006 */ 	bnezl	$a3,.L0f10d9d8
/*  f10d9c0:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f10d9c4:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10d9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d9cc:	100000d3 */ 	beqz	$zero,.L0f10dd1c
/*  f10d9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d9d4:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
.L0f10d9d8:
/*  f10d9d8:	24040038 */ 	addiu	$a0,$zero,0x38
/*  f10d9dc:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10d9e0:	50820003 */ 	beql	$a0,$v0,.L0f10d9f0
/*  f10d9e4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10d9e8:	1441007f */ 	bne	$v0,$at,.L0f10dbe8
/*  f10d9ec:	24010002 */ 	addiu	$at,$zero,0x2
.L0f10d9f0:
/*  f10d9f0:	10e1000f */ 	beq	$a3,$at,.L0f10da30
/*  f10d9f4:	3c0d8007 */ 	lui	$t5,%hi(g_MpPlayerNum)
/*  f10d9f8:	8dad1448 */ 	lw	$t5,%lo(g_MpPlayerNum)($t5)
/*  f10d9fc:	3c0f800a */ 	lui	$t7,%hi(g_MenuStack+0xe24)
/*  f10da00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10da04:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f10da08:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10da0c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10da10:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f10da14:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10da18:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10da1c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f10da20:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10da24:	8defee24 */ 	lw	$t7,%lo(g_MenuStack+0xe24)($t7)
/*  f10da28:	11e00063 */ 	beqz	$t7,.L0f10dbb8
/*  f10da2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10da30:
/*  f10da30:	1482004c */ 	bne	$a0,$v0,.L0f10db64
/*  f10da34:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10da38:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f10da3c:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f10da40:	8c450000 */ 	lw	$a1,0x0($v0)
/*  f10da44:	90440002 */ 	lbu	$a0,0x2($v0)
/*  f10da48:	0005c642 */ 	srl	$t8,$a1,0x19
/*  f10da4c:	03002825 */ 	or	$a1,$t8,$zero
/*  f10da50:	0fc40e3b */ 	jal	isStageDifficultyUnlocked
/*  f10da54:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10da58:	14400007 */ 	bnez	$v0,.L0f10da78
/*  f10da5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10da60:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10da64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10da68:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10da6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10da70:	100000aa */ 	beqz	$zero,.L0f10dd1c
/*  f10da74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10da78:
/*  f10da78:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f10da7c:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f10da80:	90590002 */ 	lbu	$t9,0x2($v0)
/*  f10da84:	3c0b8007 */ 	lui	$t3,%hi(g_StageNames)
/*  f10da88:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f10da8c:	310900ff */ 	andi	$t1,$t0,0xff
/*  f10da90:	00095080 */ 	sll	$t2,$t1,0x2
/*  f10da94:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10da98:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10da9c:	a0480002 */ 	sb	$t0,0x2($v0)
/*  f10daa0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f10daa4:	8d6b1e6c */ 	lw	$t3,%lo(g_StageNames)($t3)
/*  f10daa8:	a04b0001 */ 	sb	$t3,0x1($v0)
/*  f10daac:	0fc06c55 */ 	jal	func0f01b154
/*  f10dab0:	316400ff */ 	andi	$a0,$t3,0xff
/*  f10dab4:	3c0c800a */ 	lui	$t4,%hi(g_MissionConfig+0x3)
/*  f10dab8:	818ddfeb */ 	lb	$t5,%lo(g_MissionConfig+0x3)($t4)
/*  f10dabc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10dac0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10dac4:	05a10014 */ 	bgez	$t5,.L0f10db18
/*  f10dac8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10dacc:	8c6e0474 */ 	lw	$t6,0x474($v1)
/*  f10dad0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10dad4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10dad8:	15c00009 */ 	bnez	$t6,.L0f10db00
/*  f10dadc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10dae0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10dae4:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f10dae8:	ac6f0298 */ 	sw	$t7,0x298($v1)
/*  f10daec:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f10daf0:	0fc068d5 */ 	jal	setNumPlayers
/*  f10daf4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10daf8:	1000000c */ 	beqz	$zero,.L0f10db2c
/*  f10dafc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10db00:
/*  f10db00:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f10db04:	ac620298 */ 	sw	$v0,0x298($v1)
/*  f10db08:	0fc068d5 */ 	jal	setNumPlayers
/*  f10db0c:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f10db10:	10000006 */ 	beqz	$zero,.L0f10db2c
/*  f10db14:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10db18:
/*  f10db18:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f10db1c:	ac620298 */ 	sw	$v0,0x298($v1)
/*  f10db20:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f10db24:	0fc068d5 */ 	jal	setNumPlayers
/*  f10db28:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10db2c:
/*  f10db2c:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig)
/*  f10db30:	8c84dfe8 */ 	lw	$a0,%lo(g_MissionConfig)($a0)
/*  f10db34:	0004c642 */ 	srl	$t8,$a0,0x19
/*  f10db38:	0fc5b36a */ 	jal	setDifficulty
/*  f10db3c:	03002025 */ 	or	$a0,$t8,$zero
/*  f10db40:	0fc069f9 */ 	jal	func0f01a7e4
/*  f10db44:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10db48:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig+0x1)
/*  f10db4c:	0c003a57 */ 	jal	func0000e95c
/*  f10db50:	9084dfe9 */ 	lbu	$a0,%lo(g_MissionConfig+0x1)($a0)
/*  f10db54:	0c0027b1 */ 	jal	func00009ec4
/*  f10db58:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10db5c:	1000006f */ 	beqz	$zero,.L0f10dd1c
/*  f10db60:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10db64:
/*  f10db64:	1441006c */ 	bne	$v0,$at,.L0f10dd18
/*  f10db68:	2419005c */ 	addiu	$t9,$zero,0x5c
/*  f10db6c:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f10db70:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f10db74:	a0590001 */ 	sb	$t9,0x1($v0)
/*  f10db78:	0fc06c55 */ 	jal	func0f01b154
/*  f10db7c:	332400ff */ 	andi	$a0,$t9,0xff
/*  f10db80:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig)
/*  f10db84:	8c84dfe8 */ 	lw	$a0,%lo(g_MissionConfig)($a0)
/*  f10db88:	00044642 */ 	srl	$t0,$a0,0x19
/*  f10db8c:	0fc5b36a */ 	jal	setDifficulty
/*  f10db90:	01002025 */ 	or	$a0,$t0,$zero
/*  f10db94:	0fc069f9 */ 	jal	func0f01a7e4
/*  f10db98:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10db9c:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig+0x1)
/*  f10dba0:	0c003a57 */ 	jal	func0000e95c
/*  f10dba4:	9084dfe9 */ 	lbu	$a0,%lo(g_MissionConfig+0x1)($a0)
/*  f10dba8:	0c0027b1 */ 	jal	func00009ec4
/*  f10dbac:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10dbb0:	1000005a */ 	beqz	$zero,.L0f10dd1c
/*  f10dbb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dbb8:
/*  f10dbb8:	14e10007 */ 	bne	$a3,$at,.L0f10dbd8
/*  f10dbbc:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dbc0:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dbc4:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dbc8:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10dbcc:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10dbd0:	10000052 */ 	beqz	$zero,.L0f10dd1c
/*  f10dbd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dbd8:
/*  f10dbd8:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dbdc:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dbe0:	1000004e */ 	beqz	$zero,.L0f10dd1c
/*  f10dbe4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dbe8:
/*  f10dbe8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10dbec:	14e10004 */ 	bne	$a3,$at,.L0f10dc00
/*  f10dbf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dbf4:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dbf8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dbfc:	8fa70018 */ 	lw	$a3,0x18($sp)
.L0f10dc00:
/*  f10dc00:	3c05800a */ 	lui	$a1,%hi(g_MissionConfig)
/*  f10dc04:	8ca5dfe8 */ 	lw	$a1,%lo(g_MissionConfig)($a1)
/*  f10dc08:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig+0x2)
/*  f10dc0c:	9084dfea */ 	lbu	$a0,%lo(g_MissionConfig+0x2)($a0)
/*  f10dc10:	00054e42 */ 	srl	$t1,$a1,0x19
/*  f10dc14:	01202825 */ 	or	$a1,$t1,$zero
/*  f10dc18:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dc1c:	0fc40e3b */ 	jal	isStageDifficultyUnlocked
/*  f10dc20:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10dc24:	1440000e */ 	bnez	$v0,.L0f10dc60
/*  f10dc28:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f10dc2c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10dc30:	14e10007 */ 	bne	$a3,$at,.L0f10dc50
/*  f10dc34:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dc38:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dc3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dc40:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dc48:	10000034 */ 	beqz	$zero,.L0f10dd1c
/*  f10dc4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dc50:
/*  f10dc50:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dc54:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dc58:	10000030 */ 	beqz	$zero,.L0f10dd1c
/*  f10dc5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dc60:
/*  f10dc60:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig+0x1)
/*  f10dc64:	9084dfe9 */ 	lbu	$a0,%lo(g_MissionConfig+0x1)($a0)
/*  f10dc68:	0fc59585 */ 	jal	stageGetIndex
/*  f10dc6c:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dc70:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10dc74:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10dc78:	04400009 */ 	bltz	$v0,.L0f10dca0
/*  f10dc7c:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f10dc80:	8c6a04b4 */ 	lw	$t2,0x4b4($v1)
/*  f10dc84:	24010026 */ 	addiu	$at,$zero,0x26
/*  f10dc88:	3c0b800a */ 	lui	$t3,%hi(g_MissionConfig+0x2)
/*  f10dc8c:	51410005 */ 	beql	$t2,$at,.L0f10dca4
/*  f10dc90:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10dc94:	916bdfea */ 	lbu	$t3,%lo(g_MissionConfig+0x2)($t3)
/*  f10dc98:	29610011 */ 	slti	$at,$t3,0x11
/*  f10dc9c:	1420000d */ 	bnez	$at,.L0f10dcd4
.L0f10dca0:
/*  f10dca0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f10dca4:
/*  f10dca4:	14e10007 */ 	bne	$a3,$at,.L0f10dcc4
/*  f10dca8:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dcac:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dcb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcb4:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dcb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcbc:	10000017 */ 	beqz	$zero,.L0f10dd1c
/*  f10dcc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dcc4:
/*  f10dcc4:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dcc8:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dccc:	10000013 */ 	beqz	$zero,.L0f10dd1c
/*  f10dcd0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dcd4:
/*  f10dcd4:	0fc435dc */ 	jal	func0f10d770
/*  f10dcd8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dcdc:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f10dce0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10dce4:	14e10008 */ 	bne	$a3,$at,.L0f10dd08
/*  f10dce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcec:	0fc435cc */ 	jal	func0f10d730
/*  f10dcf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcf4:	00402025 */ 	or	$a0,$v0,$zero
/*  f10dcf8:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10dcfc:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10dd00:	10000006 */ 	beqz	$zero,.L0f10dd1c
/*  f10dd04:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dd08:
/*  f10dd08:	0fc435cc */ 	jal	func0f10d730
/*  f10dd0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dd10:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dd14:	00402025 */ 	or	$a0,$v0,$zero
.L0f10dd18:
/*  f10dd18:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dd1c:
/*  f10dd1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10dd20:	03e00008 */ 	jr	$ra
/*  f10dd24:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010dd28
/*  f10dd28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10dd2c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10dd30:	1481000d */ 	bne	$a0,$at,.L0f10dd68
/*  f10dd34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10dd38:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10dd3c:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10dd40:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0xe1c)
/*  f10dd44:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10dd48:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10dd4c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10dd50:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10dd54:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10dd58:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10dd5c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10dd60:	002f0821 */ 	addu	$at,$at,$t7
/*  f10dd64:	ac20ee1c */ 	sw	$zero,%lo(g_MenuStack+0xe1c)($at)
.L0f10dd68:
/*  f10dd68:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10dd6c:	14810035 */ 	bne	$a0,$at,.L0f10de44
/*  f10dd70:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f10dd74:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f10dd78:	3c08800a */ 	lui	$t0,0x800a
/*  f10dd7c:	2508e000 */ 	addiu	$t0,$t0,-8192
/*  f10dd80:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10dd84:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10dd88:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10dd8c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10dd90:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10dd94:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10dd98:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10dd9c:	03282021 */ 	addu	$a0,$t9,$t0
/*  f10dda0:	8c8204f8 */ 	lw	$v0,0x4f8($a0)
/*  f10dda4:	50400028 */ 	beqzl	$v0,.L0f10de48
/*  f10dda8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ddac:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f10ddb0:	50a30007 */ 	beql	$a1,$v1,.L0f10ddd0
/*  f10ddb4:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f10ddb8:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f10ddbc:	50400022 */ 	beqzl	$v0,.L0f10de48
/*  f10ddc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ddc4:	54430020 */ 	bnel	$v0,$v1,.L0f10de48
/*  f10ddc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ddcc:	8cc30000 */ 	lw	$v1,0x0($a2)
.L0f10ddd0:
/*  f10ddd0:	240c0006 */ 	addiu	$t4,$zero,0x6
/*  f10ddd4:	3c0d800a */ 	lui	$t5,%hi(var8009dfc0)
/*  f10ddd8:	90690002 */ 	lbu	$t1,0x2($v1)
/*  f10dddc:	55200008 */ 	bnezl	$t1,.L0f10de00
/*  f10dde0:	ac8c0e1c */ 	sw	$t4,0xe1c($a0)
/*  f10dde4:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f10dde8:	55400005 */ 	bnezl	$t2,.L0f10de00
/*  f10ddec:	ac8c0e1c */ 	sw	$t4,0xe1c($a0)
/*  f10ddf0:	806b000a */ 	lb	$t3,0xa($v1)
/*  f10ddf4:	51600003 */ 	beqzl	$t3,.L0f10de04
/*  f10ddf8:	8c820e1c */ 	lw	$v0,0xe1c($a0)
/*  f10ddfc:	ac8c0e1c */ 	sw	$t4,0xe1c($a0)
.L0f10de00:
/*  f10de00:	8c820e1c */ 	lw	$v0,0xe1c($a0)
.L0f10de04:
/*  f10de04:	5040000d */ 	beqzl	$v0,.L0f10de3c
/*  f10de08:	a060000a */ 	sb	$zero,0xa($v1)
/*  f10de0c:	8daddfc0 */ 	lw	$t5,%lo(var8009dfc0)($t5)
/*  f10de10:	244effff */ 	addiu	$t6,$v0,-1
/*  f10de14:	11a00003 */ 	beqz	$t5,.L0f10de24
/*  f10de18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10de1c:	ac8e0e1c */ 	sw	$t6,0xe1c($a0)
/*  f10de20:	01c01025 */ 	or	$v0,$t6,$zero
.L0f10de24:
/*  f10de24:	14400004 */ 	bnez	$v0,.L0f10de38
/*  f10de28:	00002025 */ 	or	$a0,$zero,$zero
/*  f10de2c:	0fc43644 */ 	jal	func0f10d910
/*  f10de30:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f10de34:	8fa3001c */ 	lw	$v1,0x1c($sp)
.L0f10de38:
/*  f10de38:	a060000a */ 	sb	$zero,0xa($v1)
.L0f10de3c:
/*  f10de3c:	a0600003 */ 	sb	$zero,0x3($v1)
/*  f10de40:	a0600002 */ 	sb	$zero,0x2($v1)
.L0f10de44:
/*  f10de44:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10de48:
/*  f10de48:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10de4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10de50:	03e00008 */ 	jr	$ra
/*  f10de54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010de58
/*  f10de58:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10de5c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10de60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10de64:	1481000d */ 	bne	$a0,$at,.L0f10de9c
/*  f10de68:	00c03825 */ 	or	$a3,$a2,$zero
/*  f10de6c:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10de70:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10de74:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0xe1c)
/*  f10de78:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10de7c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10de80:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10de84:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10de88:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10de8c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10de90:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10de94:	002f0821 */ 	addu	$at,$at,$t7
/*  f10de98:	ac20ee1c */ 	sw	$zero,%lo(g_MenuStack+0xe1c)($at)
.L0f10de9c:
/*  f10de9c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10dea0:	1481006b */ 	bne	$a0,$at,.L0f10e050
/*  f10dea4:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f10dea8:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f10deac:	3c08800a */ 	lui	$t0,0x800a
/*  f10deb0:	2508e000 */ 	addiu	$t0,$t0,-8192
/*  f10deb4:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10deb8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10debc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10dec0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10dec4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10dec8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10decc:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10ded0:	03281821 */ 	addu	$v1,$t9,$t0
/*  f10ded4:	8c6204f8 */ 	lw	$v0,0x4f8($v1)
/*  f10ded8:	5040005e */ 	beqzl	$v0,.L0f10e054
/*  f10dedc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10dee0:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f10dee4:	50a40007 */ 	beql	$a1,$a0,.L0f10df04
/*  f10dee8:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f10deec:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f10def0:	50400058 */ 	beqzl	$v0,.L0f10e054
/*  f10def4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10def8:	54440056 */ 	bnel	$v0,$a0,.L0f10e054
/*  f10defc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10df00:	8ce60000 */ 	lw	$a2,0x0($a3)
.L0f10df04:
/*  f10df04:	240c0006 */ 	addiu	$t4,$zero,0x6
/*  f10df08:	3c0d800a */ 	lui	$t5,%hi(var8009dfc0)
/*  f10df0c:	90c90002 */ 	lbu	$t1,0x2($a2)
/*  f10df10:	55200008 */ 	bnezl	$t1,.L0f10df34
/*  f10df14:	ac6c0e1c */ 	sw	$t4,0xe1c($v1)
/*  f10df18:	90ca0003 */ 	lbu	$t2,0x3($a2)
/*  f10df1c:	55400005 */ 	bnezl	$t2,.L0f10df34
/*  f10df20:	ac6c0e1c */ 	sw	$t4,0xe1c($v1)
/*  f10df24:	80cb000a */ 	lb	$t3,0xa($a2)
/*  f10df28:	51600003 */ 	beqzl	$t3,.L0f10df38
/*  f10df2c:	8c620e1c */ 	lw	$v0,0xe1c($v1)
/*  f10df30:	ac6c0e1c */ 	sw	$t4,0xe1c($v1)
.L0f10df34:
/*  f10df34:	8c620e1c */ 	lw	$v0,0xe1c($v1)
.L0f10df38:
/*  f10df38:	50400043 */ 	beqzl	$v0,.L0f10e048
/*  f10df3c:	a0c0000a */ 	sb	$zero,0xa($a2)
/*  f10df40:	8daddfc0 */ 	lw	$t5,%lo(var8009dfc0)($t5)
/*  f10df44:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f10df48:	244effff */ 	addiu	$t6,$v0,-1
/*  f10df4c:	11a00003 */ 	beqz	$t5,.L0f10df5c
/*  f10df50:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f10df54:	ac6e0e1c */ 	sw	$t6,0xe1c($v1)
/*  f10df58:	01c01025 */ 	or	$v0,$t6,$zero
.L0f10df5c:
/*  f10df5c:	5440003a */ 	bnezl	$v0,.L0f10e048
/*  f10df60:	a0c0000a */ 	sb	$zero,0xa($a2)
/*  f10df64:	8caf029c */ 	lw	$t7,0x29c($a1)
/*  f10df68:	05e1002c */ 	bgez	$t7,.L0f10e01c
/*  f10df6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10df70:	8cb80298 */ 	lw	$t8,0x298($a1)
/*  f10df74:	0700001d */ 	bltz	$t8,.L0f10dfec
/*  f10df78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10df7c:	8cb9006c */ 	lw	$t9,0x6c($a1)
/*  f10df80:	00003825 */ 	or	$a3,$zero,$zero
/*  f10df84:	00001825 */ 	or	$v1,$zero,$zero
/*  f10df88:	13200003 */ 	beqz	$t9,.L0f10df98
/*  f10df8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f10df90:	10000001 */ 	beqz	$zero,.L0f10df98
/*  f10df94:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f10df98:
/*  f10df98:	8ca80068 */ 	lw	$t0,0x68($a1)
/*  f10df9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10dfa0:	11000003 */ 	beqz	$t0,.L0f10dfb0
/*  f10dfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dfa8:	10000001 */ 	beqz	$zero,.L0f10dfb0
/*  f10dfac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10dfb0:
/*  f10dfb0:	8ca90064 */ 	lw	$t1,0x64($a1)
/*  f10dfb4:	11200003 */ 	beqz	$t1,.L0f10dfc4
/*  f10dfb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dfbc:	10000001 */ 	beqz	$zero,.L0f10dfc4
/*  f10dfc0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10dfc4:
/*  f10dfc4:	8caa0070 */ 	lw	$t2,0x70($a1)
/*  f10dfc8:	11400003 */ 	beqz	$t2,.L0f10dfd8
/*  f10dfcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dfd0:	10000001 */ 	beqz	$zero,.L0f10dfd8
/*  f10dfd4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10dfd8:
/*  f10dfd8:	00445821 */ 	addu	$t3,$v0,$a0
/*  f10dfdc:	01636021 */ 	addu	$t4,$t3,$v1
/*  f10dfe0:	01876821 */ 	addu	$t5,$t4,$a3
/*  f10dfe4:	29a10002 */ 	slti	$at,$t5,0x2
/*  f10dfe8:	1020000c */ 	beqz	$at,.L0f10e01c
.L0f10dfec:
/*  f10dfec:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig+0x1)
/*  f10dff0:	9084dfe9 */ 	lbu	$a0,%lo(g_MissionConfig+0x1)($a0)
/*  f10dff4:	0fc59585 */ 	jal	stageGetIndex
/*  f10dff8:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10dffc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f10e000:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f10e004:	04400005 */ 	bltz	$v0,.L0f10e01c
/*  f10e008:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e00c:	8cae04b4 */ 	lw	$t6,0x4b4($a1)
/*  f10e010:	24010026 */ 	addiu	$at,$zero,0x26
/*  f10e014:	15c10005 */ 	bne	$t6,$at,.L0f10e02c
/*  f10e018:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10e01c:
/*  f10e01c:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10e020:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10e024:	10000007 */ 	beqz	$zero,.L0f10e044
/*  f10e028:	8fa6001c */ 	lw	$a2,0x1c($sp)
.L0f10e02c:
/*  f10e02c:	0fc435dc */ 	jal	func0f10d770
/*  f10e030:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10e034:	3c048007 */ 	lui	$a0,%hi(menudialog_1b5c0)
/*  f10e038:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10e03c:	248455a0 */ 	addiu	$a0,$a0,%lo(menudialog_1b5c0)
/*  f10e040:	8fa6001c */ 	lw	$a2,0x1c($sp)
.L0f10e044:
/*  f10e044:	a0c0000a */ 	sb	$zero,0xa($a2)
.L0f10e048:
/*  f10e048:	a0c00003 */ 	sb	$zero,0x3($a2)
/*  f10e04c:	a0c00002 */ 	sb	$zero,0x2($a2)
.L0f10e050:
/*  f10e050:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10e054:
/*  f10e054:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10e058:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e05c:	03e00008 */ 	jr	$ra
/*  f10e060:	00000000 */ 	sll	$zero,$zero,0x0
);

const char var7f1b38b4[] = "ctcol";

GLOBAL_ASM(
glabel menuhandler0010e064
/*  f10e064:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10e068:	24010016 */ 	addiu	$at,$zero,0x16
/*  f10e06c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e070:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10e074:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f10e078:	14810076 */ 	bne	$a0,$at,.L0f10e254
/*  f10e07c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f10e080:	3c058007 */ 	lui	$a1,%hi(g_MpPlayerNum)
/*  f10e084:	24a51448 */ 	addiu	$a1,$a1,%lo(g_MpPlayerNum)
/*  f10e088:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f10e08c:	24060e70 */ 	addiu	$a2,$zero,0xe70
/*  f10e090:	3c04800a */ 	lui	$a0,0x800a
/*  f10e094:	01e60019 */ 	multu	$t7,$a2
/*  f10e098:	2484e000 */ 	addiu	$a0,$a0,-8192
/*  f10e09c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f10e0a0:	0000c012 */ 	mflo	$t8
/*  f10e0a4:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f10e0a8:	8f280e20 */ 	lw	$t0,0xe20($t9)
/*  f10e0ac:	31090200 */ 	andi	$t1,$t0,0x200
/*  f10e0b0:	55200005 */ 	bnezl	$t1,.L0f10e0c8
/*  f10e0b4:	3c014220 */ 	lui	$at,0x4220
/*  f10e0b8:	914b0001 */ 	lbu	$t3,0x1($t2)
/*  f10e0bc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e0c0:	15610064 */ 	bne	$t3,$at,.L0f10e254
/*  f10e0c4:	3c014220 */ 	lui	$at,0x4220
.L0f10e0c8:
/*  f10e0c8:	44816000 */ 	mtc1	$at,$f12
/*  f10e0cc:	0fc01ac2 */ 	jal	func0f006b08
/*  f10e0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e0d4:	3c01437f */ 	lui	$at,0x437f
/*  f10e0d8:	44812000 */ 	mtc1	$at,$f4
/*  f10e0dc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10e0e0:	3c047f1b */ 	lui	$a0,%hi(var7f1b38b4)
/*  f10e0e4:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f10e0e8:	3c058007 */ 	lui	$a1,%hi(var80075968)
/*  f10e0ec:	3c014f00 */ 	lui	$at,0x4f00
/*  f10e0f0:	24a55968 */ 	addiu	$a1,$a1,%lo(var80075968)
/*  f10e0f4:	248438b4 */ 	addiu	$a0,$a0,%lo(var7f1b38b4)
/*  f10e0f8:	444cf800 */ 	cfc1	$t4,$31
/*  f10e0fc:	44cdf800 */ 	ctc1	$t5,$31
/*  f10e100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e104:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f10e108:	444df800 */ 	cfc1	$t5,$31
/*  f10e10c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e110:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f10e114:	51a00013 */ 	beqzl	$t5,.L0f10e164
/*  f10e118:	440d4000 */ 	mfc1	$t5,$f8
/*  f10e11c:	44814000 */ 	mtc1	$at,$f8
/*  f10e120:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10e124:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f10e128:	44cdf800 */ 	ctc1	$t5,$31
/*  f10e12c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e130:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f10e134:	444df800 */ 	cfc1	$t5,$31
/*  f10e138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e13c:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f10e140:	15a00005 */ 	bnez	$t5,.L0f10e158
/*  f10e144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e148:	440d4000 */ 	mfc1	$t5,$f8
/*  f10e14c:	3c018000 */ 	lui	$at,0x8000
/*  f10e150:	10000007 */ 	beqz	$zero,.L0f10e170
/*  f10e154:	01a16825 */ 	or	$t5,$t5,$at
.L0f10e158:
/*  f10e158:	10000005 */ 	beqz	$zero,.L0f10e170
/*  f10e15c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f10e160:	440d4000 */ 	mfc1	$t5,$f8
.L0f10e164:
/*  f10e164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e168:	05a0fffb */ 	bltz	$t5,.L0f10e158
/*  f10e16c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10e170:
/*  f10e170:	44ccf800 */ 	ctc1	$t4,$31
/*  f10e174:	0c0036cc */ 	jal	func0000db30
/*  f10e178:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f10e17c:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f10e180:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f10e184:	91cf0001 */ 	lbu	$t7,0x1($t6)
/*  f10e188:	55e00014 */ 	bnezl	$t7,.L0f10e1dc
/*  f10e18c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f10e190:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f10e194:	3c04800a */ 	lui	$a0,%hi(g_MenuStack+0xe20)
/*  f10e198:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10e19c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e1a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10e1a4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10e1a8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10e1ac:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e1b0:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10e1b4:	00992021 */ 	addu	$a0,$a0,$t9
/*  f10e1b8:	8c84ee20 */ 	lw	$a0,%lo(g_MenuStack+0xe20)($a0)
/*  f10e1bc:	308800ff */ 	andi	$t0,$a0,0xff
/*  f10e1c0:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e1c4:	01002025 */ 	or	$a0,$t0,$zero
/*  f10e1c8:	54400004 */ 	bnezl	$v0,.L0f10e1dc
/*  f10e1cc:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f10e1d0:	10000086 */ 	beqz	$zero,.L0f10e3ec
/*  f10e1d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e1d8:	8fa90028 */ 	lw	$t1,0x28($sp)
.L0f10e1dc:
/*  f10e1dc:	3c058007 */ 	lui	$a1,%hi(var80075968)
/*  f10e1e0:	8ca55968 */ 	lw	$a1,%lo(var80075968)($a1)
/*  f10e1e4:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e1e8:	0fc01a40 */ 	jal	func0f006900
/*  f10e1ec:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f10e1f0:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f10e1f4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10e1f8:	3c058007 */ 	lui	$a1,%hi(var80075968)
/*  f10e1fc:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f10e200:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f10e204:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e208:	91430001 */ 	lbu	$v1,0x1($t2)
/*  f10e20c:	54610009 */ 	bnel	$v1,$at,.L0f10e234
/*  f10e210:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e214:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f10e218:	0fc01a40 */ 	jal	func0f006900
/*  f10e21c:	8ca55968 */ 	lw	$a1,%lo(var80075968)($a1)
/*  f10e220:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f10e224:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f10e228:	8fac0024 */ 	lw	$t4,0x24($sp)
/*  f10e22c:	91830001 */ 	lbu	$v1,0x1($t4)
/*  f10e230:	24010005 */ 	addiu	$at,$zero,0x5
.L0f10e234:
/*  f10e234:	14610007 */ 	bne	$v1,$at,.L0f10e254
/*  f10e238:	3c058007 */ 	lui	$a1,%hi(var80075968)
/*  f10e23c:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f10e240:	8ca55968 */ 	lw	$a1,%lo(var80075968)($a1)
/*  f10e244:	0fc01a40 */ 	jal	func0f006900
/*  f10e248:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e24c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f10e250:	ada20000 */ 	sw	$v0,0x0($t5)
.L0f10e254:
/*  f10e254:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f10e258:	3c04800a */ 	lui	$a0,0x800a
/*  f10e25c:	3c058007 */ 	lui	$a1,%hi(g_MpPlayerNum)
/*  f10e260:	24010018 */ 	addiu	$at,$zero,0x18
/*  f10e264:	24a51448 */ 	addiu	$a1,$a1,%lo(g_MpPlayerNum)
/*  f10e268:	2484e000 */ 	addiu	$a0,$a0,-8192
/*  f10e26c:	15c1005e */ 	bne	$t6,$at,.L0f10e3e8
/*  f10e270:	24060e70 */ 	addiu	$a2,$zero,0xe70
/*  f10e274:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f10e278:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10e27c:	91e30001 */ 	lbu	$v1,0x1($t7)
/*  f10e280:	54610018 */ 	bnel	$v1,$at,.L0f10e2e4
/*  f10e284:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10e288:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f10e28c:	03060019 */ 	multu	$t8,$a2
/*  f10e290:	0000c812 */ 	mflo	$t9
/*  f10e294:	00994021 */ 	addu	$t0,$a0,$t9
/*  f10e298:	8d020e20 */ 	lw	$v0,0xe20($t0)
/*  f10e29c:	30490800 */ 	andi	$t1,$v0,0x800
/*  f10e2a0:	11200003 */ 	beqz	$t1,.L0f10e2b0
/*  f10e2a4:	304a0100 */ 	andi	$t2,$v0,0x100
/*  f10e2a8:	10000050 */ 	beqz	$zero,.L0f10e3ec
/*  f10e2ac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10e2b0:
/*  f10e2b0:	11400009 */ 	beqz	$t2,.L0f10e2d8
/*  f10e2b4:	304c0600 */ 	andi	$t4,$v0,0x600
/*  f10e2b8:	15800007 */ 	bnez	$t4,.L0f10e2d8
/*  f10e2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e2c0:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e2c4:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e2c8:	18400003 */ 	blez	$v0,.L0f10e2d8
/*  f10e2cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e2d0:	10000046 */ 	beqz	$zero,.L0f10e3ec
/*  f10e2d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e2d8:
/*  f10e2d8:	10000044 */ 	beqz	$zero,.L0f10e3ec
/*  f10e2dc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e2e0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f10e2e4:
/*  f10e2e4:	5461000c */ 	bnel	$v1,$at,.L0f10e318
/*  f10e2e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10e2ec:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f10e2f0:	01660019 */ 	multu	$t3,$a2
/*  f10e2f4:	00006812 */ 	mflo	$t5
/*  f10e2f8:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f10e2fc:	8dcf0e20 */ 	lw	$t7,0xe20($t6)
/*  f10e300:	31f80a00 */ 	andi	$t8,$t7,0xa00
/*  f10e304:	57000004 */ 	bnezl	$t8,.L0f10e318
/*  f10e308:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10e30c:	10000037 */ 	beqz	$zero,.L0f10e3ec
/*  f10e310:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e314:	24010003 */ 	addiu	$at,$zero,0x3
.L0f10e318:
/*  f10e318:	5461000c */ 	bnel	$v1,$at,.L0f10e34c
/*  f10e31c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f10e320:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f10e324:	03260019 */ 	multu	$t9,$a2
/*  f10e328:	00004012 */ 	mflo	$t0
/*  f10e32c:	00884821 */ 	addu	$t1,$a0,$t0
/*  f10e330:	8d2a0e20 */ 	lw	$t2,0xe20($t1)
/*  f10e334:	314c0200 */ 	andi	$t4,$t2,0x200
/*  f10e338:	55800004 */ 	bnezl	$t4,.L0f10e34c
/*  f10e33c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f10e340:	1000002a */ 	beqz	$zero,.L0f10e3ec
/*  f10e344:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e348:	24010004 */ 	addiu	$at,$zero,0x4
.L0f10e34c:
/*  f10e34c:	5461000c */ 	bnel	$v1,$at,.L0f10e380
/*  f10e350:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10e354:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f10e358:	01660019 */ 	multu	$t3,$a2
/*  f10e35c:	00006812 */ 	mflo	$t5
/*  f10e360:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f10e364:	8dcf0e20 */ 	lw	$t7,0xe20($t6)
/*  f10e368:	31f80a00 */ 	andi	$t8,$t7,0xa00
/*  f10e36c:	53000004 */ 	beqzl	$t8,.L0f10e380
/*  f10e370:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10e374:	1000001d */ 	beqz	$zero,.L0f10e3ec
/*  f10e378:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e37c:	24010006 */ 	addiu	$at,$zero,0x6
.L0f10e380:
/*  f10e380:	5461000d */ 	bnel	$v1,$at,.L0f10e3b8
/*  f10e384:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e388:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f10e38c:	24010a00 */ 	addiu	$at,$zero,0xa00
/*  f10e390:	03260019 */ 	multu	$t9,$a2
/*  f10e394:	00004012 */ 	mflo	$t0
/*  f10e398:	00884821 */ 	addu	$t1,$a0,$t0
/*  f10e39c:	8d2a0e20 */ 	lw	$t2,0xe20($t1)
/*  f10e3a0:	314c0a00 */ 	andi	$t4,$t2,0xa00
/*  f10e3a4:	55810004 */ 	bnel	$t4,$at,.L0f10e3b8
/*  f10e3a8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e3ac:	1000000f */ 	beqz	$zero,.L0f10e3ec
/*  f10e3b0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e3b4:	24010005 */ 	addiu	$at,$zero,0x5
.L0f10e3b8:
/*  f10e3b8:	5461000c */ 	bnel	$v1,$at,.L0f10e3ec
/*  f10e3bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e3c0:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f10e3c4:	01660019 */ 	multu	$t3,$a2
/*  f10e3c8:	00006812 */ 	mflo	$t5
/*  f10e3cc:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f10e3d0:	8dcf0e20 */ 	lw	$t7,0xe20($t6)
/*  f10e3d4:	31f80800 */ 	andi	$t8,$t7,0x800
/*  f10e3d8:	57000004 */ 	bnezl	$t8,.L0f10e3ec
/*  f10e3dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e3e0:	10000002 */ 	beqz	$zero,.L0f10e3ec
/*  f10e3e4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10e3e8:
/*  f10e3e8:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e3ec:
/*  f10e3ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10e3f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10e3f4:	03e00008 */ 	jr	$ra
/*  f10e3f8:	00000000 */ 	sll	$zero,$zero,0x0
);

char *soloMenuTextCheatName(struct menu_item *item)
{
	if (g_MenuStack[g_MpPlayerNum].slotcount & 0x00000300) {
		return cheatGetName(g_MenuStack[g_MpPlayerNum].slotcount & 0xff);
	}

	return NULL;
}

char *soloMenuTextCheatName2(struct menu_item *item)
{
	if (g_MenuStack[g_MpPlayerNum].slotcount & 0x00000800) {
		return cheatGetName((g_MenuStack[g_MpPlayerNum].slotcount >> 16) & 0xff);
	}

	return NULL;
}

GLOBAL_ASM(
glabel soloMenuTextTargetTime
/*  f10e4d8:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10e4dc:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10e4e0:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0xe20)
/*  f10e4e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10e4e8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e4ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e4f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e4f4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e4f8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e4fc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e500:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e504:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e508:	8c42ee20 */ 	lw	$v0,%lo(g_MenuStack+0xe20)($v0)
/*  f10e50c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e510:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10e514:	30580100 */ 	andi	$t8,$v0,0x100
/*  f10e518:	17000003 */ 	bnez	$t8,.L0f10e528
/*  f10e51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e520:	10000015 */ 	beqz	$zero,.L0f10e578
/*  f10e524:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e528:
/*  f10e528:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e52c:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e530:	14400003 */ 	bnez	$v0,.L0f10e540
/*  f10e534:	00403825 */ 	or	$a3,$v0,$zero
/*  f10e538:	1000000f */ 	beqz	$zero,.L0f10e578
/*  f10e53c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e540:
/*  f10e540:	00072900 */ 	sll	$a1,$a3,0x4
/*  f10e544:	00a72823 */ 	subu	$a1,$a1,$a3
/*  f10e548:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10e54c:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10e550:	00052880 */ 	sll	$a1,$a1,0x2
/*  f10e554:	0fc355f8 */ 	jal	formatTime
/*  f10e558:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f10e55c:	3c048007 */ 	lui	$a0,%hi(g_StringPointer)
/*  f10e560:	3c057f1b */ 	lui	$a1,%hi(var7f1b38bc)
/*  f10e564:	24a538bc */ 	addiu	$a1,$a1,%lo(var7f1b38bc)
/*  f10e568:	0c004c89 */ 	jal	strcat
/*  f10e56c:	8c841440 */ 	lw	$a0,%lo(g_StringPointer)($a0)
/*  f10e570:	3c028007 */ 	lui	$v0,%hi(g_StringPointer)
/*  f10e574:	8c421440 */ 	lw	$v0,%lo(g_StringPointer)($v0)
.L0f10e578:
/*  f10e578:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10e57c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10e580:	03e00008 */ 	jr	$ra
/*  f10e584:	00000000 */ 	sll	$zero,$zero,0x0
);

const char var7f1b38bc[] = "\n";

// regalloc
//char *soloMenuTextTargetTime(struct menu_item *item)
//{
//	s32 time;
//
//	if ((g_MenuStack[g_MpPlayerNum].slotcount & 0x00000100) == 0) {
//		return NULL;
//	}
//
//	time = cheatGetTime(g_MenuStack[g_MpPlayerNum].slotcount & 0xff);
//
//	if (!time) {
//		return NULL;
//	}
//
//	formatTime(g_StringPointer, time * 60, 3);
//	strcat(g_StringPointer, "\n");
//	return g_StringPointer;
//}

GLOBAL_ASM(
glabel func0f10e588
/*  f10e588:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank0)
/*  f10e58c:	8dce21d0 */ 	lw	$t6,%lo(g_CheatsActiveBank0)($t6)
/*  f10e590:	3c0f800a */ 	lui	$t7,%hi(g_CheatsActiveBank1)
/*  f10e594:	15c00020 */ 	bnez	$t6,.L0f10e618
/*  f10e598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e59c:	8def21d4 */ 	lw	$t7,%lo(g_CheatsActiveBank1)($t7)
/*  f10e5a0:	3c05800a */ 	lui	$a1,%hi(g_MissionConfig)
/*  f10e5a4:	24a5dfe8 */ 	addiu	$a1,$a1,%lo(g_MissionConfig)
/*  f10e5a8:	15e0001b */ 	bnez	$t7,.L0f10e618
/*  f10e5ac:	3c09800a */ 	lui	$t1,%hi(g_SoloSaveFile)
/*  f10e5b0:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f10e5b4:	25292200 */ 	addiu	$t1,$t1,%lo(g_SoloSaveFile)
/*  f10e5b8:	90aa0002 */ 	lbu	$t2,0x2($a1)
/*  f10e5bc:	0018ce42 */ 	srl	$t9,$t8,0x19
/*  f10e5c0:	00194080 */ 	sll	$t0,$t9,0x2
/*  f10e5c4:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10e5c8:	8c4300a0 */ 	lw	$v1,0xa0($v0)
/*  f10e5cc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f10e5d0:	014b2004 */ 	sllv	$a0,$t3,$t2
/*  f10e5d4:	00646024 */ 	and	$t4,$v1,$a0
/*  f10e5d8:	1180000e */ 	beqz	$t4,.L0f10e614
/*  f10e5dc:	0064c025 */ 	or	$t8,$v1,$a0
/*  f10e5e0:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10e5e4:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10e5e8:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0xe24)
/*  f10e5ec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10e5f0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e5f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e5f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e5fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e600:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e604:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e608:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e60c:	002f0821 */ 	addu	$at,$at,$t7
/*  f10e610:	ac2dee24 */ 	sw	$t5,%lo(g_MenuStack+0xe24)($at)
.L0f10e614:
/*  f10e614:	ac5800a0 */ 	sw	$t8,0xa0($v0)
.L0f10e618:
/*  f10e618:	03e00008 */ 	jr	$ra
/*  f10e61c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10e620
/*  f10e620:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10e624:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10e628:	3c07800a */ 	lui	$a3,%hi(g_MissionConfig)
/*  f10e62c:	24e7dfe8 */ 	addiu	$a3,$a3,%lo(g_MissionConfig)
/*  f10e630:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e634:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e638:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e63c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e640:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e644:	90e60002 */ 	lbu	$a2,0x2($a3)
/*  f10e648:	3c18800a */ 	lui	$t8,0x800a
/*  f10e64c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e650:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e654:	2718e000 */ 	addiu	$t8,$t8,-8192
/*  f10e658:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f10e65c:	3c03800a */ 	lui	$v1,%hi(g_MenuRoot)
/*  f10e660:	ad060e2c */ 	sw	$a2,0xe2c($t0)
/*  f10e664:	8c6319c4 */ 	lw	$v1,%lo(g_MenuRoot)($v1)
/*  f10e668:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f10e66c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10e670:	10610183 */ 	beq	$v1,$at,.L0f10ec80
/*  f10e674:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e678:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x314)
/*  f10e67c:	8f39a2d4 */ 	lw	$t9,%lo(g_Vars+0x314)($t9)
/*  f10e680:	57200180 */ 	bnezl	$t9,.L0f10ec84
/*  f10e684:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10e688:	80ea0003 */ 	lb	$t2,0x3($a3)
/*  f10e68c:	ad000e20 */ 	sw	$zero,0xe20($t0)
/*  f10e690:	ad000e24 */ 	sw	$zero,0xe24($t0)
/*  f10e694:	05400033 */ 	bltz	$t2,.L0f10e764
/*  f10e698:	a100083b */ 	sb	$zero,0x83b($t0)
/*  f10e69c:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f10e6a0:	00026640 */ 	sll	$t4,$v0,0x19
/*  f10e6a4:	0580002f */ 	bltz	$t4,.L0f10e764
/*  f10e6a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e6ac:	90ed0000 */ 	lbu	$t5,0x0($a3)
/*  f10e6b0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f10e6b4:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f10e6b8:	15c0002a */ 	bnez	$t6,.L0f10e764
/*  f10e6bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e6c0:	0fc41fae */ 	jal	cheatGetByTimedStageIndex
/*  f10e6c4:	00022e42 */ 	srl	$a1,$v0,0x19
/*  f10e6c8:	3c04800a */ 	lui	$a0,%hi(g_MissionConfig+0x2)
/*  f10e6cc:	9084dfea */ 	lbu	$a0,%lo(g_MissionConfig+0x2)($a0)
/*  f10e6d0:	0fc41fc6 */ 	jal	cheatGetByCompletedStageIndex
/*  f10e6d4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f10e6d8:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f10e6dc:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f10e6e0:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f10e6e4:	0460000d */ 	bltz	$v1,.L0f10e71c
/*  f10e6e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e6ec:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f10e6f0:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0xe20)
/*  f10e6f4:	346f0100 */ 	ori	$t7,$v1,0x100
/*  f10e6f8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10e6fc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e700:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10e704:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10e708:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10e70c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e710:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10e714:	00390821 */ 	addu	$at,$at,$t9
/*  f10e718:	ac2fee20 */ 	sw	$t7,%lo(g_MenuStack+0xe20)($at)
.L0f10e71c:
/*  f10e71c:	04400011 */ 	bltz	$v0,.L0f10e764
/*  f10e720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e724:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f10e728:	3c0b800a */ 	lui	$t3,0x800a
/*  f10e72c:	256be000 */ 	addiu	$t3,$t3,-8192
/*  f10e730:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f10e734:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e738:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10e73c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f10e740:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f10e744:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e748:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f10e74c:	014b4021 */ 	addu	$t0,$t2,$t3
/*  f10e750:	8d0c0e20 */ 	lw	$t4,0xe20($t0)
/*  f10e754:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f10e758:	35ae1000 */ 	ori	$t6,$t5,0x1000
/*  f10e75c:	018ec025 */ 	or	$t8,$t4,$t6
/*  f10e760:	ad180e20 */ 	sw	$t8,0xe20($t0)
.L0f10e764:
/*  f10e764:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f10e768:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f10e76c:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f10e770:	15e00008 */ 	bnez	$t7,.L0f10e794
/*  f10e774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e778:	8c59048c */ 	lw	$t9,0x48c($v0)
/*  f10e77c:	17200005 */ 	bnez	$t9,.L0f10e794
/*  f10e780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e784:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10e788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e78c:	1440000a */ 	bnez	$v0,.L0f10e7b8
/*  f10e790:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb44)
.L0f10e794:
/*  f10e794:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb5c)
/*  f10e798:	24845b3c */ 	addiu	$a0,$a0,%lo(menudialog_1bb5c)
/*  f10e79c:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10e7a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10e7a4:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig+0x3)
/*  f10e7a8:	9042dfeb */ 	lbu	$v0,%lo(g_MissionConfig+0x3)($v0)
/*  f10e7ac:	000249c2 */ 	srl	$t1,$v0,0x7
/*  f10e7b0:	1000000f */ 	beqz	$zero,.L0f10e7f0
/*  f10e7b4:	01201025 */ 	or	$v0,$t1,$zero
.L0f10e7b8:
/*  f10e7b8:	24845b24 */ 	addiu	$a0,$a0,%lo(menudialog_1bb44)
/*  f10e7bc:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10e7c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10e7c4:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig+0x3)
/*  f10e7c8:	9042dfeb */ 	lbu	$v0,%lo(g_MissionConfig+0x3)($v0)
/*  f10e7cc:	000251c2 */ 	srl	$t2,$v0,0x7
/*  f10e7d0:	11400007 */ 	beqz	$t2,.L0f10e7f0
/*  f10e7d4:	01401025 */ 	or	$v0,$t2,$zero
/*  f10e7d8:	0fc43962 */ 	jal	func0f10e588
/*  f10e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e7e0:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig+0x3)
/*  f10e7e4:	9042dfeb */ 	lbu	$v0,%lo(g_MissionConfig+0x3)($v0)
/*  f10e7e8:	000259c2 */ 	srl	$t3,$v0,0x7
/*  f10e7ec:	01601025 */ 	or	$v0,$t3,$zero
.L0f10e7f0:
/*  f10e7f0:	1440011c */ 	bnez	$v0,.L0f10ec64
/*  f10e7f4:	3c0d800a */ 	lui	$t5,%hi(g_MissionConfig)
/*  f10e7f8:	8daddfe8 */ 	lw	$t5,%lo(g_MissionConfig)($t5)
/*  f10e7fc:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f10e800:	000d7640 */ 	sll	$t6,$t5,0x19
/*  f10e804:	05c00117 */ 	bltz	$t6,.L0f10ec64
/*  f10e808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e80c:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f10e810:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0xe20)
/*  f10e814:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f10e818:	001878c0 */ 	sll	$t7,$t8,0x3
/*  f10e81c:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f10e820:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e824:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f10e828:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e82c:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f10e830:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e834:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e838:	8c42ee20 */ 	lw	$v0,%lo(g_MenuStack+0xe20)($v0)
/*  f10e83c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f10e840:	30590100 */ 	andi	$t9,$v0,0x100
/*  f10e844:	13200014 */ 	beqz	$t9,.L0f10e898
/*  f10e848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e84c:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10e850:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e854:	10400010 */ 	beqz	$v0,.L0f10e898
/*  f10e858:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10e85c:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f10e860:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f10e864:	3c0b800a */ 	lui	$t3,0x800a
/*  f10e868:	256be000 */ 	addiu	$t3,$t3,-8192
/*  f10e86c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f10e870:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e874:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10e878:	01495021 */ 	addu	$t2,$t2,$t1
/*  f10e87c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f10e880:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e884:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f10e888:	014b4021 */ 	addu	$t0,$t2,$t3
/*  f10e88c:	8d0d0e20 */ 	lw	$t5,0xe20($t0)
/*  f10e890:	35ac0400 */ 	ori	$t4,$t5,0x400
/*  f10e894:	ad0c0e20 */ 	sw	$t4,0xe20($t0)
.L0f10e898:
/*  f10e898:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10e89c:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10e8a0:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0xe20)
/*  f10e8a4:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*  f10e8a8:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f10e8ac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10e8b0:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f10e8b4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10e8b8:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f10e8bc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10e8c0:	00581021 */ 	addu	$v0,$v0,$t8
/*  f10e8c4:	8c42ee20 */ 	lw	$v0,%lo(g_MenuStack+0xe20)($v0)
/*  f10e8c8:	304f1000 */ 	andi	$t7,$v0,0x1000
/*  f10e8cc:	11e00005 */ 	beqz	$t7,.L0f10e8e4
/*  f10e8d0:	00022402 */ 	srl	$a0,$v0,0x10
/*  f10e8d4:	309900ff */ 	andi	$t9,$a0,0xff
/*  f10e8d8:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10e8dc:	03202025 */ 	or	$a0,$t9,$zero
/*  f10e8e0:	afa2001c */ 	sw	$v0,0x1c($sp)
.L0f10e8e4:
/*  f10e8e4:	0fc3089f */ 	jal	getMissionTime
/*  f10e8e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e8ec:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f10e8f0:	0041001a */ 	div	$zero,$v0,$at
/*  f10e8f4:	00001812 */ 	mflo	$v1
/*  f10e8f8:	3c047fff */ 	lui	$a0,0x7fff
/*  f10e8fc:	10600010 */ 	beqz	$v1,.L0f10e940
/*  f10e900:	3484ffff */ 	ori	$a0,$a0,0xffff
/*  f10e904:	0064082b */ 	sltu	$at,$v1,$a0
/*  f10e908:	10200007 */ 	beqz	$at,.L0f10e928
/*  f10e90c:	3c05800a */ 	lui	$a1,%hi(g_SoloSaveFile)
/*  f10e910:	24a52200 */ 	addiu	$a1,$a1,%lo(g_SoloSaveFile)
/*  f10e914:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f10e918:	00834823 */ 	subu	$t1,$a0,$v1
/*  f10e91c:	0049082b */ 	sltu	$at,$v0,$t1
/*  f10e920:	14200005 */ 	bnez	$at,.L0f10e938
/*  f10e924:	00435021 */ 	addu	$t2,$v0,$v1
.L0f10e928:
/*  f10e928:	3c05800a */ 	lui	$a1,%hi(g_SoloSaveFile)
/*  f10e92c:	24a52200 */ 	addiu	$a1,$a1,%lo(g_SoloSaveFile)
/*  f10e930:	10000003 */ 	beqz	$zero,.L0f10e940
/*  f10e934:	aca40010 */ 	sw	$a0,0x10($a1)
.L0f10e938:
/*  f10e938:	3c01800a */ 	lui	$at,%hi(g_SoloSaveFile+0x10)
/*  f10e93c:	ac2a2210 */ 	sw	$t2,%lo(g_SoloSaveFile+0x10)($at)
.L0f10e940:
/*  f10e940:	3c03800a */ 	lui	$v1,%hi(g_MissionConfig)
/*  f10e944:	2463dfe8 */ 	addiu	$v1,$v1,%lo(g_MissionConfig)
/*  f10e948:	3c05800a */ 	lui	$a1,%hi(g_SoloSaveFile)
/*  f10e94c:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f10e950:	24a52200 */ 	addiu	$a1,$a1,%lo(g_SoloSaveFile)
/*  f10e954:	90af000b */ 	lbu	$t7,0xb($a1)
/*  f10e958:	906b0002 */ 	lbu	$t3,0x2($v1)
/*  f10e95c:	000d7642 */ 	srl	$t6,$t5,0x19
/*  f10e960:	31d80007 */ 	andi	$t8,$t6,0x7
/*  f10e964:	31f9fff8 */ 	andi	$t9,$t7,0xfff8
/*  f10e968:	03194825 */ 	or	$t1,$t8,$t9
/*  f10e96c:	a0a9000b */ 	sb	$t1,0xb($a1)
/*  f10e970:	3c0a800a */ 	lui	$t2,%hi(g_CheatsActiveBank0)
/*  f10e974:	a0ab000c */ 	sb	$t3,0xc($a1)
/*  f10e978:	8d4a21d0 */ 	lw	$t2,%lo(g_CheatsActiveBank0)($t2)
/*  f10e97c:	3c0b800a */ 	lui	$t3,%hi(g_CheatsActiveBank1)
/*  f10e980:	154000b8 */ 	bnez	$t2,.L0f10ec64
/*  f10e984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e988:	8d6b21d4 */ 	lw	$t3,%lo(g_CheatsActiveBank1)($t3)
/*  f10e98c:	156000b5 */ 	bnez	$t3,.L0f10ec64
/*  f10e990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e994:	906d0000 */ 	lbu	$t5,0x0($v1)
/*  f10e998:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f10e99c:	31ac0001 */ 	andi	$t4,$t5,0x1
/*  f10e9a0:	158000b0 */ 	bnez	$t4,.L0f10ec64
/*  f10e9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9a8:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f10e9ac:	8c4e00d8 */ 	lw	$t6,0xd8($v0)
/*  f10e9b0:	15c000ac */ 	bnez	$t6,.L0f10ec64
/*  f10e9b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9b8:	8c4f048c */ 	lw	$t7,0x48c($v0)
/*  f10e9bc:	15e000a9 */ 	bnez	$t7,.L0f10ec64
/*  f10e9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9c4:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10e9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9cc:	104000a5 */ 	beqz	$v0,.L0f10ec64
/*  f10e9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9d4:	0fc3089f */ 	jal	getMissionTime
/*  f10e9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9dc:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f10e9e0:	0041001a */ 	div	$zero,$v0,$at
/*  f10e9e4:	00002012 */ 	mflo	$a0
/*  f10e9e8:	3c05800a */ 	lui	$a1,%hi(g_SoloSaveFile)
/*  f10e9ec:	2c811000 */ 	sltiu	$at,$a0,0x1000
/*  f10e9f0:	14200002 */ 	bnez	$at,.L0f10e9fc
/*  f10e9f4:	24a52200 */ 	addiu	$a1,$a1,%lo(g_SoloSaveFile)
/*  f10e9f8:	24040fff */ 	addiu	$a0,$zero,0xfff
.L0f10e9fc:
/*  f10e9fc:	14800002 */ 	bnez	$a0,.L0f10ea08
/*  f10ea00:	3c06800a */ 	lui	$a2,%hi(g_MissionConfig+0x2)
/*  f10ea04:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10ea08:
/*  f10ea08:	90c6dfea */ 	lbu	$a2,%lo(g_MissionConfig+0x2)($a2)
/*  f10ea0c:	3c09800a */ 	lui	$t1,%hi(g_MissionConfig)
/*  f10ea10:	8d29dfe8 */ 	lw	$t1,%lo(g_MissionConfig)($t1)
/*  f10ea14:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f10ea18:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f10ea1c:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f10ea20:	00095642 */ 	srl	$t2,$t1,0x19
/*  f10ea24:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f10ea28:	00b8c821 */ 	addu	$t9,$a1,$t8
/*  f10ea2c:	032b3821 */ 	addu	$a3,$t9,$t3
/*  f10ea30:	94e30020 */ 	lhu	$v1,0x20($a3)
/*  f10ea34:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f10ea38:	3c09800a */ 	lui	$t1,0x800a
/*  f10ea3c:	1460000d */ 	bnez	$v1,.L0f10ea74
/*  f10ea40:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f10ea44:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f10ea48:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0xe24)
/*  f10ea4c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10ea50:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f10ea54:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f10ea58:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10ea5c:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f10ea60:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10ea64:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f10ea68:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f10ea6c:	002e0821 */ 	addu	$at,$at,$t6
/*  f10ea70:	ac2dee24 */ 	sw	$t5,%lo(g_MenuStack+0xe24)($at)
.L0f10ea74:
/*  f10ea74:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f10ea78:	2529e000 */ 	addiu	$t1,$t1,-8192
/*  f10ea7c:	0083082b */ 	sltu	$at,$a0,$v1
/*  f10ea80:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10ea84:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ea88:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10ea8c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10ea90:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10ea94:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ea98:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ea9c:	14200003 */ 	bnez	$at,.L0f10eaac
/*  f10eaa0:	03094021 */ 	addu	$t0,$t8,$t1
/*  f10eaa4:	54600003 */ 	bnezl	$v1,.L0f10eab4
/*  f10eaa8:	28c10011 */ 	slti	$at,$a2,0x11
.L0f10eaac:
/*  f10eaac:	a4e40020 */ 	sh	$a0,0x20($a3)
/*  f10eab0:	28c10011 */ 	slti	$at,$a2,0x11
.L0f10eab4:
/*  f10eab4:	1020001d */ 	beqz	$at,.L0f10eb2c
/*  f10eab8:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f10eabc:	315900ff */ 	andi	$t9,$t2,0xff
/*  f10eac0:	2b210011 */ 	slti	$at,$t9,0x11
/*  f10eac4:	14200003 */ 	bnez	$at,.L0f10ead4
/*  f10eac8:	a0aa000c */ 	sb	$t2,0xc($a1)
/*  f10eacc:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f10ead0:	a0ab000c */ 	sb	$t3,0xc($a1)
.L0f10ead4:
/*  f10ead4:	00003025 */ 	or	$a2,$zero,$zero
/*  f10ead8:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f10eadc:	24040011 */ 	addiu	$a0,$zero,0x11
.L0f10eae0:
/*  f10eae0:	3c0c800a */ 	lui	$t4,%hi(g_SoloSaveFile)
/*  f10eae4:	258c2200 */ 	addiu	$t4,$t4,%lo(g_SoloSaveFile)
/*  f10eae8:	00cc1821 */ 	addu	$v1,$a2,$t4
/*  f10eaec:	00001025 */ 	or	$v0,$zero,$zero
.L0f10eaf0:
/*  f10eaf0:	946d0020 */ 	lhu	$t5,0x20($v1)
/*  f10eaf4:	51a00008 */ 	beqzl	$t5,.L0f10eb18
/*  f10eaf8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10eafc:	90aa000b */ 	lbu	$t2,0xb($a1)
/*  f10eb00:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f10eb04:	000f48c0 */ 	sll	$t1,$t7,0x3
/*  f10eb08:	3159ff07 */ 	andi	$t9,$t2,0xff07
/*  f10eb0c:	01395825 */ 	or	$t3,$t1,$t9
/*  f10eb10:	a0ab000b */ 	sb	$t3,0xb($a1)
/*  f10eb14:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f10eb18:
/*  f10eb18:	1444fff5 */ 	bne	$v0,$a0,.L0f10eaf0
/*  f10eb1c:	24630006 */ 	addiu	$v1,$v1,0x6
/*  f10eb20:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f10eb24:	14c7ffee */ 	bne	$a2,$a3,.L0f10eae0
/*  f10eb28:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10eb2c:
/*  f10eb2c:	8d020e20 */ 	lw	$v0,0xe20($t0)
/*  f10eb30:	304c0100 */ 	andi	$t4,$v0,0x100
/*  f10eb34:	11800016 */ 	beqz	$t4,.L0f10eb90
/*  f10eb38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eb3c:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10eb40:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10eb44:	8fad0020 */ 	lw	$t5,0x20($sp)
/*  f10eb48:	15a00011 */ 	bnez	$t5,.L0f10eb90
/*  f10eb4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eb50:	1040000f */ 	beqz	$v0,.L0f10eb90
/*  f10eb54:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10eb58:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10eb5c:	3c18800a */ 	lui	$t8,0x800a
/*  f10eb60:	2718e000 */ 	addiu	$t8,$t8,-8192
/*  f10eb64:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10eb68:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10eb6c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10eb70:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10eb74:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10eb78:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10eb7c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10eb80:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f10eb84:	8d0a0e20 */ 	lw	$t2,0xe20($t0)
/*  f10eb88:	35490200 */ 	ori	$t1,$t2,0x200
/*  f10eb8c:	ad090e20 */ 	sw	$t1,0xe20($t0)
.L0f10eb90:
/*  f10eb90:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f10eb94:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f10eb98:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0xe20)
/*  f10eb9c:	001958c0 */ 	sll	$t3,$t9,0x3
/*  f10eba0:	01795823 */ 	subu	$t3,$t3,$t9
/*  f10eba4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10eba8:	01795821 */ 	addu	$t3,$t3,$t9
/*  f10ebac:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f10ebb0:	01795823 */ 	subu	$t3,$t3,$t9
/*  f10ebb4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f10ebb8:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f10ebbc:	8c42ee20 */ 	lw	$v0,%lo(g_MenuStack+0xe20)($v0)
/*  f10ebc0:	304c1000 */ 	andi	$t4,$v0,0x1000
/*  f10ebc4:	11800017 */ 	beqz	$t4,.L0f10ec24
/*  f10ebc8:	00022402 */ 	srl	$a0,$v0,0x10
/*  f10ebcc:	308d00ff */ 	andi	$t5,$a0,0xff
/*  f10ebd0:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10ebd4:	01a02025 */ 	or	$a0,$t5,$zero
/*  f10ebd8:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f10ebdc:	15c00011 */ 	bnez	$t6,.L0f10ec24
/*  f10ebe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ebe4:	1040000f */ 	beqz	$v0,.L0f10ec24
/*  f10ebe8:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f10ebec:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f10ebf0:	3c0a800a */ 	lui	$t2,0x800a
/*  f10ebf4:	254ae000 */ 	addiu	$t2,$t2,-8192
/*  f10ebf8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10ebfc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ec00:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10ec04:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10ec08:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10ec0c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ec10:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ec14:	030a4021 */ 	addu	$t0,$t8,$t2
/*  f10ec18:	8d090e20 */ 	lw	$t1,0xe20($t0)
/*  f10ec1c:	35390800 */ 	ori	$t9,$t1,0x800
/*  f10ec20:	ad190e20 */ 	sw	$t9,0xe20($t0)
.L0f10ec24:
/*  f10ec24:	0fc66bf7 */ 	jal	func0f19afdc
/*  f10ec28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ec2c:	3c0b800a */ 	lui	$t3,%hi(g_MissionConfig+0x1)
/*  f10ec30:	916bdfe9 */ 	lbu	$t3,%lo(g_MissionConfig+0x1)($t3)
/*  f10ec34:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10ec38:	3c02800a */ 	lui	$v0,%hi(var800a2328+0x3)
/*  f10ec3c:	15610009 */ 	bne	$t3,$at,.L0f10ec64
/*  f10ec40:	2442232b */ 	addiu	$v0,$v0,%lo(var800a2328+0x3)
/*  f10ec44:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f10ec48:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10ec4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f10ec50:	15800004 */ 	bnez	$t4,.L0f10ec64
/*  f10ec54:	3c01800a */ 	lui	$at,%hi(g_AltTitle)
/*  f10ec58:	a04d0000 */ 	sb	$t5,0x0($v0)
/*  f10ec5c:	0fc44270 */ 	jal	func0f1109c0
/*  f10ec60:	a02e232c */ 	sb	$t6,%lo(g_AltTitle)($at)
.L0f10ec64:
/*  f10ec64:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10ec68:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f10ec6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f10ec70:	0fc42539 */ 	jal	func0f1094e4
/*  f10ec74:	00003025 */ 	or	$a2,$zero,$zero
/*  f10ec78:	3c03800a */ 	lui	$v1,%hi(g_MenuRoot)
/*  f10ec7c:	8c6319c4 */ 	lw	$v1,%lo(g_MenuRoot)($v1)
.L0f10ec80:
/*  f10ec80:	24010001 */ 	addiu	$at,$zero,0x1
.L0f10ec84:
/*  f10ec84:	54610008 */ 	bnel	$v1,$at,.L0f10eca8
/*  f10ec88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ec8c:	0fc5b350 */ 	jal	setVar80084014
/*  f10ec90:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10ec94:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f10ec98:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f10ec9c:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f10eca0:	af0f1a24 */ 	sw	$t7,0x1a24($t8)
/*  f10eca4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10eca8:
/*  f10eca8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f10ecac:	03e00008 */ 	jr	$ra
/*  f10ecb0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10ecb4
/*  f10ecb4:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10ecb8:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10ecbc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ecc0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ecc4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10ecc8:	0fc5b350 */ 	jal	setVar80084014
/*  f10eccc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ecd0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f10ecd4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f10ecd8:	8c8f0288 */ 	lw	$t7,0x288($a0)
/*  f10ecdc:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10ece0:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f10ece4:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f10ece8:	3c09800a */ 	lui	$t1,0x800a
/*  f10ecec:	2529e000 */ 	addiu	$t1,$t1,-8192
/*  f10ecf0:	ac381448 */ 	sw	$t8,%lo(g_MpPlayerNum)($at)
/*  f10ecf4:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f10ecf8:	3c0a800a */ 	lui	$t2,%hi(g_MissionConfig+0x2)
/*  f10ecfc:	8c8b028c */ 	lw	$t3,0x28c($a0)
/*  f10ed00:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f10ed04:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ed08:	00084080 */ 	sll	$t0,$t0,0x2
/*  f10ed0c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10ed10:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f10ed14:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ed18:	00084100 */ 	sll	$t0,$t0,0x4
/*  f10ed1c:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10ed20:	ac400e20 */ 	sw	$zero,0xe20($v0)
/*  f10ed24:	ac400e24 */ 	sw	$zero,0xe24($v0)
/*  f10ed28:	914adfea */ 	lbu	$t2,%lo(g_MissionConfig+0x2)($t2)
/*  f10ed2c:	8c8302a0 */ 	lw	$v1,0x2a0($a0)
/*  f10ed30:	a04b083b */ 	sb	$t3,0x83b($v0)
/*  f10ed34:	ac4a0e2c */ 	sw	$t2,0xe2c($v0)
/*  f10ed38:	8c6c00d8 */ 	lw	$t4,0xd8($v1)
/*  f10ed3c:	51800006 */ 	beqzl	$t4,.L0f10ed58
/*  f10ed40:	8c6f048c */ 	lw	$t7,0x48c($v1)
/*  f10ed44:	8c8d02a4 */ 	lw	$t5,0x2a4($a0)
/*  f10ed48:	8dae00d8 */ 	lw	$t6,0xd8($t5)
/*  f10ed4c:	15c0000c */ 	bnez	$t6,.L0f10ed80
/*  f10ed50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed54:	8c6f048c */ 	lw	$t7,0x48c($v1)
.L0f10ed58:
/*  f10ed58:	15e00009 */ 	bnez	$t7,.L0f10ed80
/*  f10ed5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed60:	8c9802a4 */ 	lw	$t8,0x2a4($a0)
/*  f10ed64:	8f19048c */ 	lw	$t9,0x48c($t8)
/*  f10ed68:	17200005 */ 	bnez	$t9,.L0f10ed80
/*  f10ed6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed70:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10ed74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed78:	14400011 */ 	bnez	$v0,.L0f10edc0
/*  f10ed7c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10ed80:
/*  f10ed80:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10ed84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed88:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10ed8c:	14410007 */ 	bne	$v0,$at,.L0f10edac
/*  f10ed90:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb8c)
/*  f10ed94:	3c048007 */ 	lui	$a0,%hi(menudialog_1bbbc)
/*  f10ed98:	24845b9c */ 	addiu	$a0,$a0,%lo(menudialog_1bbbc)
/*  f10ed9c:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10eda0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10eda4:	10000016 */ 	beqz	$zero,.L0f10ee00
/*  f10eda8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10edac:
/*  f10edac:	24845b6c */ 	addiu	$a0,$a0,%lo(menudialog_1bb8c)
/*  f10edb0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10edb4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10edb8:	10000011 */ 	beqz	$zero,.L0f10ee00
/*  f10edbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10edc0:
/*  f10edc0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10edc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10edc8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10edcc:	14410007 */ 	bne	$v0,$at,.L0f10edec
/*  f10edd0:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb74)
/*  f10edd4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bba4)
/*  f10edd8:	24845b84 */ 	addiu	$a0,$a0,%lo(menudialog_1bba4)
/*  f10eddc:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10ede0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10ede4:	10000004 */ 	beqz	$zero,.L0f10edf8
/*  f10ede8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10edec:
/*  f10edec:	24845b54 */ 	addiu	$a0,$a0,%lo(menudialog_1bb74)
/*  f10edf0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10edf4:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f10edf8:
/*  f10edf8:	0fc43962 */ 	jal	func0f10e588
/*  f10edfc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10ee00:
/*  f10ee00:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x2a0)
/*  f10ee04:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x284)
/*  f10ee08:	8d29a244 */ 	lw	$t1,%lo(g_Vars+0x284)($t1)
/*  f10ee0c:	8d08a260 */ 	lw	$t0,%lo(g_Vars+0x2a0)($t0)
/*  f10ee10:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10ee14:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f10ee18:	15090003 */ 	bne	$t0,$t1,.L0f10ee28
/*  f10ee1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f10ee20:	0fc42539 */ 	jal	func0f1094e4
/*  f10ee24:	00003025 */ 	or	$a2,$zero,$zero
.L0f10ee28:
/*  f10ee28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ee2c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f10ee30:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10ee34:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10ee38:	03e00008 */ 	jr	$ra
/*  f10ee3c:	ac2a1448 */ 	sw	$t2,%lo(g_MpPlayerNum)($at)
);

GLOBAL_ASM(
glabel func0f10ee40
/*  f10ee40:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f10ee44:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f10ee48:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f10ee4c:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f10ee50:	24841448 */ 	addiu	$a0,$a0,%lo(g_MpPlayerNum)
/*  f10ee54:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f10ee58:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f10ee5c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ee60:	3c01800a */ 	lui	$at,%hi(g_MenuStack+0x83b)
/*  f10ee64:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10ee68:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f10ee6c:	00380821 */ 	addu	$at,$at,$t8
/*  f10ee70:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10ee74:	a020e83b */ 	sb	$zero,%lo(g_MenuStack+0x83b)($at)
/*  f10ee78:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f10ee7c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ee80:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ee84:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ee88:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f10ee8c:	53200006 */ 	beqzl	$t9,.L0f10eea8
/*  f10ee90:	8c4a048c */ 	lw	$t2,0x48c($v0)
/*  f10ee94:	8c6802a4 */ 	lw	$t0,0x2a4($v1)
/*  f10ee98:	8d0900d8 */ 	lw	$t1,0xd8($t0)
/*  f10ee9c:	1520000c */ 	bnez	$t1,.L0f10eed0
/*  f10eea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eea4:	8c4a048c */ 	lw	$t2,0x48c($v0)
.L0f10eea8:
/*  f10eea8:	15400009 */ 	bnez	$t2,.L0f10eed0
/*  f10eeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eeb0:	8c6b02a4 */ 	lw	$t3,0x2a4($v1)
/*  f10eeb4:	8d6c048c */ 	lw	$t4,0x48c($t3)
/*  f10eeb8:	15800005 */ 	bnez	$t4,.L0f10eed0
/*  f10eebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eec0:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10eec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eec8:	14400009 */ 	bnez	$v0,.L0f10eef0
/*  f10eecc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10eed0:
/*  f10eed0:	0fc435dc */ 	jal	func0f10d770
/*  f10eed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eed8:	3c048007 */ 	lui	$a0,%hi(menudialog_1b5c0)
/*  f10eedc:	248455a0 */ 	addiu	$a0,$a0,%lo(menudialog_1b5c0)
/*  f10eee0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10eee4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10eee8:	10000004 */ 	beqz	$zero,.L0f10eefc
/*  f10eeec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10eef0:
/*  f10eef0:	0fc43644 */ 	jal	func0f10d910
/*  f10eef4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10eef8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10eefc:
/*  f10eefc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f10ef00:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10ef04:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10ef08:	03e00008 */ 	jr	$ra
/*  f10ef0c:	ac2d1448 */ 	sw	$t5,%lo(g_MpPlayerNum)($at)
);

GLOBAL_ASM(
glabel func0f10ef10
/*  f10ef10:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f10ef14:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f10ef18:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ef1c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ef20:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10ef24:	0fc5b350 */ 	jal	setVar80084014
/*  f10ef28:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ef2c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10ef30:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10ef34:	8c6f0288 */ 	lw	$t7,0x288($v1)
/*  f10ef38:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10ef3c:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f10ef40:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f10ef44:	3c09800a */ 	lui	$t1,0x800a
/*  f10ef48:	2529e000 */ 	addiu	$t1,$t1,-8192
/*  f10ef4c:	ac381448 */ 	sw	$t8,%lo(g_MpPlayerNum)($at)
/*  f10ef50:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f10ef54:	8c6c0284 */ 	lw	$t4,0x284($v1)
/*  f10ef58:	8c6402a0 */ 	lw	$a0,0x2a0($v1)
/*  f10ef5c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f10ef60:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ef64:	00084080 */ 	sll	$t0,$t0,0x2
/*  f10ef68:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10ef6c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f10ef70:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ef74:	00084100 */ 	sll	$t0,$t0,0x4
/*  f10ef78:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10ef7c:	ac400e20 */ 	sw	$zero,0xe20($v0)
/*  f10ef80:	ac400e24 */ 	sw	$zero,0xe24($v0)
/*  f10ef84:	3c0a800a */ 	lui	$t2,%hi(g_MissionConfig+0x2)
/*  f10ef88:	914adfea */ 	lbu	$t2,%lo(g_MissionConfig+0x2)($t2)
/*  f10ef8c:	8c6b028c */ 	lw	$t3,0x28c($v1)
/*  f10ef90:	ac4a0e2c */ 	sw	$t2,0xe2c($v0)
/*  f10ef94:	148c0034 */ 	bne	$a0,$t4,.L0f10f068
/*  f10ef98:	a04b083b */ 	sb	$t3,0x83b($v0)
/*  f10ef9c:	8c6d02a8 */ 	lw	$t5,0x2a8($v1)
/*  f10efa0:	8dae048c */ 	lw	$t6,0x48c($t5)
/*  f10efa4:	15c0001b */ 	bnez	$t6,.L0f10f014
/*  f10efa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efac:	8c8f00d8 */ 	lw	$t7,0xd8($a0)
/*  f10efb0:	15e00008 */ 	bnez	$t7,.L0f10efd4
/*  f10efb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efb8:	8c98048c */ 	lw	$t8,0x48c($a0)
/*  f10efbc:	17000005 */ 	bnez	$t8,.L0f10efd4
/*  f10efc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efc4:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10efc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efcc:	14400011 */ 	bnez	$v0,.L0f10f014
/*  f10efd0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10efd4:
/*  f10efd4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10efd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efdc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10efe0:	14410007 */ 	bne	$v0,$at,.L0f10f000
/*  f10efe4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb8c)
/*  f10efe8:	3c048007 */ 	lui	$a0,%hi(menudialog_1bbbc)
/*  f10efec:	24845b9c */ 	addiu	$a0,$a0,%lo(menudialog_1bbbc)
/*  f10eff0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10eff4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10eff8:	10000014 */ 	beqz	$zero,.L0f10f04c
/*  f10effc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f000:
/*  f10f000:	24845b6c */ 	addiu	$a0,$a0,%lo(menudialog_1bb8c)
/*  f10f004:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f008:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f00c:	1000000f */ 	beqz	$zero,.L0f10f04c
/*  f10f010:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f014:
/*  f10f014:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10f018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f01c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f020:	14410007 */ 	bne	$v0,$at,.L0f10f040
/*  f10f024:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb74)
/*  f10f028:	3c048007 */ 	lui	$a0,%hi(menudialog_1bba4)
/*  f10f02c:	24845b84 */ 	addiu	$a0,$a0,%lo(menudialog_1bba4)
/*  f10f030:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f034:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f038:	10000004 */ 	beqz	$zero,.L0f10f04c
/*  f10f03c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f040:
/*  f10f040:	24845b54 */ 	addiu	$a0,$a0,%lo(menudialog_1bb74)
/*  f10f044:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f048:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f10f04c:
/*  f10f04c:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10f050:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f10f054:	00002825 */ 	or	$a1,$zero,$zero
/*  f10f058:	0fc42539 */ 	jal	func0f1094e4
/*  f10f05c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f060:	1000002e */ 	beqz	$zero,.L0f10f11c
/*  f10f064:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f068:
/*  f10f068:	8c7902a8 */ 	lw	$t9,0x2a8($v1)
/*  f10f06c:	8f28048c */ 	lw	$t0,0x48c($t9)
/*  f10f070:	1500001b */ 	bnez	$t0,.L0f10f0e0
/*  f10f074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f078:	8c8900d8 */ 	lw	$t1,0xd8($a0)
/*  f10f07c:	15200008 */ 	bnez	$t1,.L0f10f0a0
/*  f10f080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f084:	8c8a048c */ 	lw	$t2,0x48c($a0)
/*  f10f088:	15400005 */ 	bnez	$t2,.L0f10f0a0
/*  f10f08c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f090:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10f094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f098:	14400011 */ 	bnez	$v0,.L0f10f0e0
/*  f10f09c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f0a0:
/*  f10f0a0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10f0a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f0a8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f0ac:	14410007 */ 	bne	$v0,$at,.L0f10f0cc
/*  f10f0b0:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb74)
/*  f10f0b4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bba4)
/*  f10f0b8:	24845b84 */ 	addiu	$a0,$a0,%lo(menudialog_1bba4)
/*  f10f0bc:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f0c0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f0c4:	10000015 */ 	beqz	$zero,.L0f10f11c
/*  f10f0c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f0cc:
/*  f10f0cc:	24845b54 */ 	addiu	$a0,$a0,%lo(menudialog_1bb74)
/*  f10f0d0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f0d4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f0d8:	10000010 */ 	beqz	$zero,.L0f10f11c
/*  f10f0dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f0e0:
/*  f10f0e0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10f0e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f0e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f0ec:	14410007 */ 	bne	$v0,$at,.L0f10f10c
/*  f10f0f0:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb8c)
/*  f10f0f4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bbbc)
/*  f10f0f8:	24845b9c */ 	addiu	$a0,$a0,%lo(menudialog_1bbbc)
/*  f10f0fc:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f100:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f104:	10000005 */ 	beqz	$zero,.L0f10f11c
/*  f10f108:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f10c:
/*  f10f10c:	24845b6c */ 	addiu	$a0,$a0,%lo(menudialog_1bb8c)
/*  f10f110:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f10f114:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f118:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f11c:
/*  f10f11c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f10f120:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f10f124:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10f128:	03e00008 */ 	jr	$ra
/*  f10f12c:	ac2b1448 */ 	sw	$t3,%lo(g_MpPlayerNum)($at)
);

const char var7f1b38c0[] = "Flag %d = %s";
const char var7f1b38d0[] = "TRUE";
const char var7f1b38d8[] = "FALSE";
const char var7f1b38e0[] = "Dark";
const char var7f1b38e8[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b391c[] = "pdoptions.c";
const char var7f1b3928[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b395c[] = "pdoptions.c";
const char var7f1b3968[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b399c[] = "pdoptions.c";
const char var7f1b39a8[] = "";
const char var7f1b39ac[] = "";
const char var7f1b39b0[] = "fileGuid";
const char var7f1b39bc[] = "bossfile.c";
const char var7f1b39c8[] = "";
const char var7f1b39cc[] = "";
