#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/cheats.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/game_115ab0.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/game_16cfa0.h"
#include "game/game_19c990.h"

GLOBAL_ASM(
glabel cheatIsUnlocked
/*  f106d40:	3c0f8007 */ 	lui	$t7,%hi(g_Cheats)
/*  f106d44:	25ef3a90 */ 	addiu	$t7,$t7,%lo(g_Cheats)
/*  f106d48:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f106d4c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f106d50:	90660006 */ 	lbu	$a2,0x6($v1)
/*  f106d54:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f106d58:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f106d5c:	30d80008 */ 	andi	$t8,$a2,0x8
/*  f106d60:	1300000b */ 	beqz	$t8,.L0f106d90
/*  f106d64:	00002825 */ 	or	$a1,$zero,$zero
/*  f106d68:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f106d6c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f106d70:	0fc673c8 */ 	jal	func0f19cf20
/*  f106d74:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f106d78:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f106d7c:	10400002 */ 	beqz	$v0,.L0f106d88
/*  f106d80:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f106d84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106d88:
/*  f106d88:	10000029 */ 	beqz	$zero,.L0f106e30
/*  f106d8c:	90660006 */ 	lbu	$a2,0x6($v1)
.L0f106d90:
/*  f106d90:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f106d94:	53200016 */ 	beqzl	$t9,.L0f106df0
/*  f106d98:	906e0004 */ 	lbu	$t6,0x4($v1)
/*  f106d9c:	90680004 */ 	lbu	$t0,0x4($v1)
/*  f106da0:	3c0a800a */ 	lui	$t2,%hi(var800a2200)
/*  f106da4:	254a2200 */ 	addiu	$t2,$t2,%lo(var800a2200)
/*  f106da8:	00084880 */ 	sll	$t1,$t0,0x2
/*  f106dac:	01284823 */ 	subu	$t1,$t1,$t0
/*  f106db0:	00094840 */ 	sll	$t1,$t1,0x1
/*  f106db4:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f106db8:	944b0020 */ 	lhu	$t3,0x20($v0)
/*  f106dbc:	51600003 */ 	beqzl	$t3,.L0f106dcc
/*  f106dc0:	944c0022 */ 	lhu	$t4,0x22($v0)
/*  f106dc4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f106dc8:	944c0022 */ 	lhu	$t4,0x22($v0)
.L0f106dcc:
/*  f106dcc:	51800003 */ 	beqzl	$t4,.L0f106ddc
/*  f106dd0:	944d0024 */ 	lhu	$t5,0x24($v0)
/*  f106dd4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f106dd8:	944d0024 */ 	lhu	$t5,0x24($v0)
.L0f106ddc:
/*  f106ddc:	51a00015 */ 	beqzl	$t5,.L0f106e34
/*  f106de0:	30ca0002 */ 	andi	$t2,$a2,0x2
/*  f106de4:	10000012 */ 	beqz	$zero,.L0f106e30
/*  f106de8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f106dec:	906e0004 */ 	lbu	$t6,0x4($v1)
.L0f106df0:
/*  f106df0:	90780005 */ 	lbu	$t8,0x5($v1)
/*  f106df4:	3c02800a */ 	lui	$v0,0x800a
/*  f106df8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f106dfc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f106e00:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f106e04:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f106e08:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f106e0c:	00481021 */ 	addu	$v0,$v0,$t0
/*  f106e10:	94422220 */ 	lhu	$v0,0x2220($v0)
/*  f106e14:	50400007 */ 	beqzl	$v0,.L0f106e34
/*  f106e18:	30ca0002 */ 	andi	$t2,$a2,0x2
/*  f106e1c:	94690002 */ 	lhu	$t1,0x2($v1)
/*  f106e20:	0122082a */ 	slt	$at,$t1,$v0
/*  f106e24:	54200003 */ 	bnezl	$at,.L0f106e34
/*  f106e28:	30ca0002 */ 	andi	$t2,$a2,0x2
/*  f106e2c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106e30:
/*  f106e30:	30ca0002 */ 	andi	$t2,$a2,0x2
.L0f106e34:
/*  f106e34:	11400006 */ 	beqz	$t2,.L0f106e50
/*  f106e38:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f106e3c:	0fc43c63 */ 	jal	eepromGet
/*  f106e40:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f106e44:	10400002 */ 	beqz	$v0,.L0f106e50
/*  f106e48:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f106e4c:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f106e50:
/*  f106e50:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f106e54:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f106e58:	00a01025 */ 	or	$v0,$a1,$zero
/*  f106e5c:	03e00008 */ 	jr	$ra
/*  f106e60:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch due to incorrect jump address for g_BestTimes.
// It appears to be in a struct that starts 0x20 earlier, but this means other
// variables like g_EepromFlags are in the struct too. Resolving this will be
// done separately.
//bool cheatIsUnlocked(s32 cheat_id)
//{
//	struct cheat *cheat = &g_Cheats[cheat_id];
//	bool unlocked = false;
//
//	if (cheat->flags & CHEATFLAG_FIRINGRANGE) {
//		if (func0f19cf20(cheat->time)) {
//			unlocked = true;
//		}
//	} else if (cheat->flags & CHEATFLAG_COMPLETION) {
//		if (g_BestTimes[cheat->stage_index * 3]) {
//			unlocked++;
//		}
//		if (g_BestTimes[cheat->stage_index * 3 + 1]) {
//			unlocked++;
//		}
//		if (g_BestTimes[cheat->stage_index * 3 + 2]) {
//			unlocked++;
//		}
//	} else {
//		s32 mytime = g_BestTimes[cheat->stage_index * 3 + cheat->difficulty];
//
//		if (mytime && mytime <= cheat->time) {
//			unlocked = true;
//		}
//	}
//
//	if (cheat->flags & CHEATFLAG_TRANSFERPAK) {
//		if (eepromGet(0x23)) {
//			unlocked++;
//		}
//	}
//
//	return unlocked;
//}

bool cheatIsActive(s32 cheat_id)
{
	if (cheat_id < 32) {
		return g_CheatsActiveBank0 & (1 << cheat_id);
	}

	return g_CheatsActiveBank1 & (1 << cheat_id);
}

GLOBAL_ASM(
glabel cheatActivate
/*  f106ea0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f106ea4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f106ea8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f106eac:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f106eb0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f106eb4:	10810006 */ 	beq	$a0,$at,.L0f106ed0
/*  f106eb8:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f106ebc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f106ec0:	1081004a */ 	beq	$a0,$at,.L0f106fec
/*  f106ec4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f106ec8:	100000a6 */ 	beqz	$zero,.L0f107164
/*  f106ecc:	8faf0028 */ 	lw	$t7,0x28($sp)
.L0f106ed0:
/*  f106ed0:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f106ed4:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f106ed8:	8e38006c */ 	lw	$t8,0x6c($s1)
/*  f106edc:	8e2f028c */ 	lw	$t7,0x28c($s1)
/*  f106ee0:	00008025 */ 	or	$s0,$zero,$zero
/*  f106ee4:	13000003 */ 	beqz	$t8,.L0f106ef4
/*  f106ee8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f106eec:	10000002 */ 	beqz	$zero,.L0f106ef8
/*  f106ef0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106ef4:
/*  f106ef4:	00002825 */ 	or	$a1,$zero,$zero
.L0f106ef8:
/*  f106ef8:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f106efc:	00002025 */ 	or	$a0,$zero,$zero
/*  f106f00:	00001825 */ 	or	$v1,$zero,$zero
/*  f106f04:	13200003 */ 	beqz	$t9,.L0f106f14
/*  f106f08:	00001025 */ 	or	$v0,$zero,$zero
/*  f106f0c:	10000001 */ 	beqz	$zero,.L0f106f14
/*  f106f10:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f106f14:
/*  f106f14:	8e2a0064 */ 	lw	$t2,0x64($s1)
/*  f106f18:	11400003 */ 	beqz	$t2,.L0f106f28
/*  f106f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106f20:	10000001 */ 	beqz	$zero,.L0f106f28
/*  f106f24:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f106f28:
/*  f106f28:	8e2b0070 */ 	lw	$t3,0x70($s1)
/*  f106f2c:	11600003 */ 	beqz	$t3,.L0f106f3c
/*  f106f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106f34:	10000001 */ 	beqz	$zero,.L0f106f3c
/*  f106f38:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f106f3c:
/*  f106f3c:	00436021 */ 	addu	$t4,$v0,$v1
/*  f106f40:	01846821 */ 	addu	$t5,$t4,$a0
/*  f106f44:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f106f48:	19c00024 */ 	blez	$t6,.L0f106fdc
/*  f106f4c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f106f50:
/*  f106f50:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f106f54:	02002025 */ 	or	$a0,$s0,$zero
/*  f106f58:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f106f5c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f106f60:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f106f64:	a30f1922 */ 	sb	$t7,0x1922($t8)
/*  f106f68:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f106f6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f106f70:	00002025 */ 	or	$a0,$zero,$zero
/*  f106f74:	13200003 */ 	beqz	$t9,.L0f106f84
/*  f106f78:	00001825 */ 	or	$v1,$zero,$zero
/*  f106f7c:	10000001 */ 	beqz	$zero,.L0f106f84
/*  f106f80:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f106f84:
/*  f106f84:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f106f88:	00001025 */ 	or	$v0,$zero,$zero
/*  f106f8c:	11400003 */ 	beqz	$t2,.L0f106f9c
/*  f106f90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106f94:	10000001 */ 	beqz	$zero,.L0f106f9c
/*  f106f98:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f106f9c:
/*  f106f9c:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*  f106fa0:	11600003 */ 	beqz	$t3,.L0f106fb0
/*  f106fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106fa8:	10000001 */ 	beqz	$zero,.L0f106fb0
/*  f106fac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f106fb0:
/*  f106fb0:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f106fb4:	11800003 */ 	beqz	$t4,.L0f106fc4
/*  f106fb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f106fbc:	10000001 */ 	beqz	$zero,.L0f106fc4
/*  f106fc0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f106fc4:
/*  f106fc4:	00436821 */ 	addu	$t5,$v0,$v1
/*  f106fc8:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f106fcc:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f106fd0:	020f082a */ 	slt	$at,$s0,$t7
/*  f106fd4:	1420ffde */ 	bnez	$at,.L0f106f50
/*  f106fd8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f106fdc:
/*  f106fdc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f106fe0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f106fe4:	1000005f */ 	beqz	$zero,.L0f107164
/*  f106fe8:	8faf0028 */ 	lw	$t7,0x28($sp)
.L0f106fec:
/*  f106fec:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f106ff0:	8e26006c */ 	lw	$a2,0x6c($s1)
/*  f106ff4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f106ff8:	00002825 */ 	or	$a1,$zero,$zero
/*  f106ffc:	10c00003 */ 	beqz	$a2,.L0f10700c
/*  f107000:	00002025 */ 	or	$a0,$zero,$zero
/*  f107004:	10000001 */ 	beqz	$zero,.L0f10700c
/*  f107008:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10700c:
/*  f10700c:	8e270068 */ 	lw	$a3,0x68($s1)
/*  f107010:	00001825 */ 	or	$v1,$zero,$zero
/*  f107014:	00001025 */ 	or	$v0,$zero,$zero
/*  f107018:	10e00003 */ 	beqz	$a3,.L0f107028
/*  f10701c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107020:	10000001 */ 	beqz	$zero,.L0f107028
/*  f107024:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f107028:
/*  f107028:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f10702c:	11000003 */ 	beqz	$t0,.L0f10703c
/*  f107030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107034:	10000001 */ 	beqz	$zero,.L0f10703c
/*  f107038:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10703c:
/*  f10703c:	8e290070 */ 	lw	$t1,0x70($s1)
/*  f107040:	11200003 */ 	beqz	$t1,.L0f107050
/*  f107044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107048:	10000001 */ 	beqz	$zero,.L0f107050
/*  f10704c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107050:
/*  f107050:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f107054:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f107058:	03255021 */ 	addu	$t2,$t9,$a1
/*  f10705c:	55410041 */ 	bnel	$t2,$at,.L0f107164
/*  f107060:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f107064:	8e2b0318 */ 	lw	$t3,0x318($s1)
/*  f107068:	5560003e */ 	bnezl	$t3,.L0f107164
/*  f10706c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f107070:	8e2c028c */ 	lw	$t4,0x28c($s1)
/*  f107074:	00008025 */ 	or	$s0,$zero,$zero
/*  f107078:	10c00003 */ 	beqz	$a2,.L0f107088
/*  f10707c:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f107080:	10000002 */ 	beqz	$zero,.L0f10708c
/*  f107084:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f107088:
/*  f107088:	00002825 */ 	or	$a1,$zero,$zero
.L0f10708c:
/*  f10708c:	10e00003 */ 	beqz	$a3,.L0f10709c
/*  f107090:	00002025 */ 	or	$a0,$zero,$zero
/*  f107094:	10000001 */ 	beqz	$zero,.L0f10709c
/*  f107098:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10709c:
/*  f10709c:	11000003 */ 	beqz	$t0,.L0f1070ac
/*  f1070a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1070a4:	10000001 */ 	beqz	$zero,.L0f1070ac
/*  f1070a8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1070ac:
/*  f1070ac:	11200003 */ 	beqz	$t1,.L0f1070bc
/*  f1070b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1070b4:	10000001 */ 	beqz	$zero,.L0f1070bc
/*  f1070b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1070bc:
/*  f1070bc:	00436821 */ 	addu	$t5,$v0,$v1
/*  f1070c0:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f1070c4:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f1070c8:	19e00023 */ 	blez	$t7,.L0f107158
/*  f1070cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1070d0:
/*  f1070d0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1070d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1070d8:	0fc44660 */ 	jal	func0f111980
/*  f1070dc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1070e0:	8e38006c */ 	lw	$t8,0x6c($s1)
/*  f1070e4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1070e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1070ec:	13000003 */ 	beqz	$t8,.L0f1070fc
/*  f1070f0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1070f4:	10000001 */ 	beqz	$zero,.L0f1070fc
/*  f1070f8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1070fc:
/*  f1070fc:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f107100:	00001825 */ 	or	$v1,$zero,$zero
/*  f107104:	00001025 */ 	or	$v0,$zero,$zero
/*  f107108:	13200003 */ 	beqz	$t9,.L0f107118
/*  f10710c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107110:	10000001 */ 	beqz	$zero,.L0f107118
/*  f107114:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f107118:
/*  f107118:	8e2a0064 */ 	lw	$t2,0x64($s1)
/*  f10711c:	11400003 */ 	beqz	$t2,.L0f10712c
/*  f107120:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107124:	10000001 */ 	beqz	$zero,.L0f10712c
/*  f107128:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10712c:
/*  f10712c:	8e2b0070 */ 	lw	$t3,0x70($s1)
/*  f107130:	11600003 */ 	beqz	$t3,.L0f107140
/*  f107134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107138:	10000001 */ 	beqz	$zero,.L0f107140
/*  f10713c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107140:
/*  f107140:	00436021 */ 	addu	$t4,$v0,$v1
/*  f107144:	01846821 */ 	addu	$t5,$t4,$a0
/*  f107148:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f10714c:	020e082a */ 	slt	$at,$s0,$t6
/*  f107150:	1420ffdf */ 	bnez	$at,.L0f1070d0
/*  f107154:	00000000 */ 	sll	$zero,$zero,0x0
.L0f107158:
/*  f107158:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f10715c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f107160:	8faf0028 */ 	lw	$t7,0x28($sp)
.L0f107164:
/*  f107164:	3c02800a */ 	lui	$v0,%hi(g_CheatsActiveBank0)
/*  f107168:	244221d0 */ 	addiu	$v0,$v0,%lo(g_CheatsActiveBank0)
/*  f10716c:	29e10020 */ 	slti	$at,$t7,0x20
/*  f107170:	10200007 */ 	beqz	$at,.L0f107190
/*  f107174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107178:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f10717c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f107180:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f107184:	032a5825 */ 	or	$t3,$t9,$t2
/*  f107188:	10000009 */ 	beqz	$zero,.L0f1071b0
/*  f10718c:	ac4b0000 */ 	sw	$t3,0x0($v0)
.L0f107190:
/*  f107190:	3c02800a */ 	lui	$v0,%hi(g_CheatsActiveBank1)
/*  f107194:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f107198:	244221d4 */ 	addiu	$v0,$v0,%lo(g_CheatsActiveBank1)
/*  f10719c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1071a0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1071a4:	018d7004 */ 	sllv	$t6,$t5,$t4
/*  f1071a8:	01d87825 */ 	or	$t7,$t6,$t8
/*  f1071ac:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L0f1071b0:
/*  f1071b0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1071b4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1071b8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1071bc:	03e00008 */ 	jr	$ra
/*  f1071c0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel cheatDeactivate
/*  f1071c4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1071c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1071cc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1071d0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1071d4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1071d8:	10810006 */ 	beq	$a0,$at,.L0f1071f4
/*  f1071dc:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1071e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1071e4:	1081004a */ 	beq	$a0,$at,.L0f107310
/*  f1071e8:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f1071ec:	100000a6 */ 	beqz	$zero,.L0f107488
/*  f1071f0:	8faf0028 */ 	lw	$t7,0x28($sp)
.L0f1071f4:
/*  f1071f4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f1071f8:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f1071fc:	8e38006c */ 	lw	$t8,0x6c($s1)
/*  f107200:	8e2f028c */ 	lw	$t7,0x28c($s1)
/*  f107204:	00008025 */ 	or	$s0,$zero,$zero
/*  f107208:	13000003 */ 	beqz	$t8,.L0f107218
/*  f10720c:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f107210:	10000002 */ 	beqz	$zero,.L0f10721c
/*  f107214:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f107218:
/*  f107218:	00002825 */ 	or	$a1,$zero,$zero
.L0f10721c:
/*  f10721c:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f107220:	00002025 */ 	or	$a0,$zero,$zero
/*  f107224:	00001825 */ 	or	$v1,$zero,$zero
/*  f107228:	13200003 */ 	beqz	$t9,.L0f107238
/*  f10722c:	00001025 */ 	or	$v0,$zero,$zero
/*  f107230:	10000001 */ 	beqz	$zero,.L0f107238
/*  f107234:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f107238:
/*  f107238:	8e2a0064 */ 	lw	$t2,0x64($s1)
/*  f10723c:	11400003 */ 	beqz	$t2,.L0f10724c
/*  f107240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107244:	10000001 */ 	beqz	$zero,.L0f10724c
/*  f107248:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10724c:
/*  f10724c:	8e2b0070 */ 	lw	$t3,0x70($s1)
/*  f107250:	11600003 */ 	beqz	$t3,.L0f107260
/*  f107254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107258:	10000001 */ 	beqz	$zero,.L0f107260
/*  f10725c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107260:
/*  f107260:	00436021 */ 	addu	$t4,$v0,$v1
/*  f107264:	01846821 */ 	addu	$t5,$t4,$a0
/*  f107268:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f10726c:	19c00024 */ 	blez	$t6,.L0f107300
/*  f107270:	00000000 */ 	sll	$zero,$zero,0x0
.L0f107274:
/*  f107274:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f107278:	02002025 */ 	or	$a0,$s0,$zero
/*  f10727c:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f107280:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f107284:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f107288:	a30f1922 */ 	sb	$t7,0x1922($t8)
/*  f10728c:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f107290:	00002825 */ 	or	$a1,$zero,$zero
/*  f107294:	00002025 */ 	or	$a0,$zero,$zero
/*  f107298:	13200003 */ 	beqz	$t9,.L0f1072a8
/*  f10729c:	00001825 */ 	or	$v1,$zero,$zero
/*  f1072a0:	10000001 */ 	beqz	$zero,.L0f1072a8
/*  f1072a4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1072a8:
/*  f1072a8:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f1072ac:	00001025 */ 	or	$v0,$zero,$zero
/*  f1072b0:	11400003 */ 	beqz	$t2,.L0f1072c0
/*  f1072b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1072b8:	10000001 */ 	beqz	$zero,.L0f1072c0
/*  f1072bc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1072c0:
/*  f1072c0:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*  f1072c4:	11600003 */ 	beqz	$t3,.L0f1072d4
/*  f1072c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1072cc:	10000001 */ 	beqz	$zero,.L0f1072d4
/*  f1072d0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1072d4:
/*  f1072d4:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f1072d8:	11800003 */ 	beqz	$t4,.L0f1072e8
/*  f1072dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1072e0:	10000001 */ 	beqz	$zero,.L0f1072e8
/*  f1072e4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1072e8:
/*  f1072e8:	00436821 */ 	addu	$t5,$v0,$v1
/*  f1072ec:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f1072f0:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f1072f4:	020f082a */ 	slt	$at,$s0,$t7
/*  f1072f8:	1420ffde */ 	bnez	$at,.L0f107274
/*  f1072fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f107300:
/*  f107300:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f107304:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f107308:	1000005f */ 	beqz	$zero,.L0f107488
/*  f10730c:	8faf0028 */ 	lw	$t7,0x28($sp)
.L0f107310:
/*  f107310:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f107314:	8e26006c */ 	lw	$a2,0x6c($s1)
/*  f107318:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10731c:	00002825 */ 	or	$a1,$zero,$zero
/*  f107320:	10c00003 */ 	beqz	$a2,.L0f107330
/*  f107324:	00002025 */ 	or	$a0,$zero,$zero
/*  f107328:	10000001 */ 	beqz	$zero,.L0f107330
/*  f10732c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f107330:
/*  f107330:	8e270068 */ 	lw	$a3,0x68($s1)
/*  f107334:	00001825 */ 	or	$v1,$zero,$zero
/*  f107338:	00001025 */ 	or	$v0,$zero,$zero
/*  f10733c:	10e00003 */ 	beqz	$a3,.L0f10734c
/*  f107340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107344:	10000001 */ 	beqz	$zero,.L0f10734c
/*  f107348:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10734c:
/*  f10734c:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f107350:	11000003 */ 	beqz	$t0,.L0f107360
/*  f107354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107358:	10000001 */ 	beqz	$zero,.L0f107360
/*  f10735c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f107360:
/*  f107360:	8e290070 */ 	lw	$t1,0x70($s1)
/*  f107364:	11200003 */ 	beqz	$t1,.L0f107374
/*  f107368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10736c:	10000001 */ 	beqz	$zero,.L0f107374
/*  f107370:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107374:
/*  f107374:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f107378:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f10737c:	03255021 */ 	addu	$t2,$t9,$a1
/*  f107380:	55410041 */ 	bnel	$t2,$at,.L0f107488
/*  f107384:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f107388:	8e2b0318 */ 	lw	$t3,0x318($s1)
/*  f10738c:	5560003e */ 	bnezl	$t3,.L0f107488
/*  f107390:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f107394:	8e2c028c */ 	lw	$t4,0x28c($s1)
/*  f107398:	00008025 */ 	or	$s0,$zero,$zero
/*  f10739c:	10c00003 */ 	beqz	$a2,.L0f1073ac
/*  f1073a0:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f1073a4:	10000002 */ 	beqz	$zero,.L0f1073b0
/*  f1073a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1073ac:
/*  f1073ac:	00002825 */ 	or	$a1,$zero,$zero
.L0f1073b0:
/*  f1073b0:	10e00003 */ 	beqz	$a3,.L0f1073c0
/*  f1073b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1073b8:	10000001 */ 	beqz	$zero,.L0f1073c0
/*  f1073bc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1073c0:
/*  f1073c0:	11000003 */ 	beqz	$t0,.L0f1073d0
/*  f1073c4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1073c8:	10000001 */ 	beqz	$zero,.L0f1073d0
/*  f1073cc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1073d0:
/*  f1073d0:	11200003 */ 	beqz	$t1,.L0f1073e0
/*  f1073d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1073d8:	10000001 */ 	beqz	$zero,.L0f1073e0
/*  f1073dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1073e0:
/*  f1073e0:	00436821 */ 	addu	$t5,$v0,$v1
/*  f1073e4:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f1073e8:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f1073ec:	19e00023 */ 	blez	$t7,.L0f10747c
/*  f1073f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1073f4:
/*  f1073f4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1073f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1073fc:	0fc44660 */ 	jal	func0f111980
/*  f107400:	00002025 */ 	or	$a0,$zero,$zero
/*  f107404:	8e38006c */ 	lw	$t8,0x6c($s1)
/*  f107408:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10740c:	00002825 */ 	or	$a1,$zero,$zero
/*  f107410:	13000003 */ 	beqz	$t8,.L0f107420
/*  f107414:	00002025 */ 	or	$a0,$zero,$zero
/*  f107418:	10000001 */ 	beqz	$zero,.L0f107420
/*  f10741c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f107420:
/*  f107420:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f107424:	00001825 */ 	or	$v1,$zero,$zero
/*  f107428:	00001025 */ 	or	$v0,$zero,$zero
/*  f10742c:	13200003 */ 	beqz	$t9,.L0f10743c
/*  f107430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107434:	10000001 */ 	beqz	$zero,.L0f10743c
/*  f107438:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10743c:
/*  f10743c:	8e2a0064 */ 	lw	$t2,0x64($s1)
/*  f107440:	11400003 */ 	beqz	$t2,.L0f107450
/*  f107444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107448:	10000001 */ 	beqz	$zero,.L0f107450
/*  f10744c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f107450:
/*  f107450:	8e2b0070 */ 	lw	$t3,0x70($s1)
/*  f107454:	11600003 */ 	beqz	$t3,.L0f107464
/*  f107458:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10745c:	10000001 */ 	beqz	$zero,.L0f107464
/*  f107460:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107464:
/*  f107464:	00436021 */ 	addu	$t4,$v0,$v1
/*  f107468:	01846821 */ 	addu	$t5,$t4,$a0
/*  f10746c:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f107470:	020e082a */ 	slt	$at,$s0,$t6
/*  f107474:	1420ffdf */ 	bnez	$at,.L0f1073f4
/*  f107478:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10747c:
/*  f10747c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f107480:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f107484:	8faf0028 */ 	lw	$t7,0x28($sp)
.L0f107488:
/*  f107488:	3c02800a */ 	lui	$v0,%hi(g_CheatsActiveBank0)
/*  f10748c:	244221d0 */ 	addiu	$v0,$v0,%lo(g_CheatsActiveBank0)
/*  f107490:	29e10020 */ 	slti	$at,$t7,0x20
/*  f107494:	10200007 */ 	beqz	$at,.L0f1074b4
/*  f107498:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f10749c:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f1074a0:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f1074a4:	03205027 */ 	nor	$t2,$t9,$zero
/*  f1074a8:	014b6024 */ 	and	$t4,$t2,$t3
/*  f1074ac:	1000000a */ 	beqz	$zero,.L0f1074d8
/*  f1074b0:	ac4c0000 */ 	sw	$t4,0x0($v0)
.L0f1074b4:
/*  f1074b4:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f1074b8:	3c02800a */ 	lui	$v0,%hi(g_CheatsActiveBank1)
/*  f1074bc:	244221d4 */ 	addiu	$v0,$v0,%lo(g_CheatsActiveBank1)
/*  f1074c0:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f1074c4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1074c8:	01aec004 */ 	sllv	$t8,$t6,$t5
/*  f1074cc:	03007827 */ 	nor	$t7,$t8,$zero
/*  f1074d0:	01f95024 */ 	and	$t2,$t7,$t9
/*  f1074d4:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L0f1074d8:
/*  f1074d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1074dc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1074e0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1074e4:	03e00008 */ 	jr	$ra
/*  f1074e8:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

void cheatsDisableAll(void)
{
	g_CheatsActiveBank0 = 0;
	g_CheatsActiveBank1 = 0;
	g_CheatsEnabledBank0 = 0;
	g_CheatsEnabledBank1 = 0;
}

void cheatsActivate(void)
{
	s32 cheat_id;

	if (g_Vars.unk0004b4 != 38) {
		g_CheatsActiveBank0 = g_CheatsEnabledBank0;
		g_CheatsActiveBank1 = g_CheatsEnabledBank1;

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 || g_Vars.unk000318) {
			// Co-op/counter-op - deactivate "Weapons for Jo in Solo" cheats
			g_CheatsActiveBank0 &= ~(
				(1 << CHEAT_TRENTSMAGNUM) |
				(1 << CHEAT_FARSIGHT) |
				(1 << CHEAT_ROCKETLAUNCHER) |
				(1 << CHEAT_SNIPERRIFLE) |
				(1 << CHEAT_XRAYSCANNER) |
				(1 << CHEAT_SUPERDRAGON) |
				(1 << CHEAT_LAPTOPGUN)
			);
			g_CheatsActiveBank1 &= ~(
				(1 << CHEAT_PHOENIX - 32) |
				(1 << CHEAT_PSYCHOSISGUN - 32) |
				(1 << CHEAT_PP9I - 32) |
				(1 << CHEAT_CC13 - 32) |
				(1 << CHEAT_KLO1313 - 32) |
				(1 << CHEAT_KF7SPECIAL - 32) |
				(1 << CHEAT_ZZT - 32) |
				(1 << CHEAT_DMC - 32) |
				(1 << CHEAT_AR53 - 32) |
				(1 << CHEAT_RCP45 - 32)
			);
		}
	} else {
		g_CheatsActiveBank0 = 0;
		g_CheatsActiveBank1 = 0;
	}

	for (cheat_id = 0; cheat_id != NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].flags & CHEATFLAG_ALWAYSON) {
			if (cheatIsUnlocked(cheat_id)) {
				if (cheat_id < 32) {
					g_CheatsActiveBank0 = g_CheatsActiveBank0 | (1 << cheat_id);
				} else {
					g_CheatsActiveBank1 = g_CheatsActiveBank1 | (1 << cheat_id);
				}
			} else {
				if (cheat_id < 32) {
					g_CheatsActiveBank0 = g_CheatsActiveBank0 & ~(1 << cheat_id);
				} else {
					g_CheatsActiveBank1 = g_CheatsActiveBank1 & ~(1 << cheat_id);
				}
			}
		}

		if (cheatIsActive(cheat_id)) {
			cheatActivate(cheat_id);
		}
	}
}

GLOBAL_ASM(
glabel cheatMenuHandleCheatCheckbox
/*  f1076b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1076b4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1076b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1076bc:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1076c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1076c4:	1081001f */ 	beq	$a0,$at,.L0f107744
/*  f1076c8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1076cc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f1076d0:	54810054 */ 	bnel	$a0,$at,.L0f107824
/*  f1076d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1076d8:	90a20001 */ 	lbu	$v0,0x1($a1)
/*  f1076dc:	3c06800a */ 	lui	$a2,%hi(g_CheatsEnabledBank1)
/*  f1076e0:	3c05800a */ 	lui	$a1,%hi(g_CheatsEnabledBank0)
/*  f1076e4:	28410020 */ 	slti	$at,$v0,0x20
/*  f1076e8:	1020000c */ 	beqz	$at,.L0f10771c
/*  f1076ec:	24c621dc */ 	addiu	$a2,$a2,%lo(g_CheatsEnabledBank1)
/*  f1076f0:	24a521d8 */ 	addiu	$a1,$a1,%lo(g_CheatsEnabledBank0)
/*  f1076f4:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f1076f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1076fc:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f107700:	01f8c824 */ 	and	$t9,$t7,$t8
/*  f107704:	13200003 */ 	beqz	$t9,.L0f107714
/*  f107708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10770c:	10000045 */ 	beqz	$zero,.L0f107824
/*  f107710:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f107714:
/*  f107714:	10000043 */ 	beqz	$zero,.L0f107824
/*  f107718:	00001025 */ 	or	$v0,$zero,$zero
.L0f10771c:
/*  f10771c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f107720:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f107724:	00484804 */ 	sllv	$t1,$t0,$v0
/*  f107728:	012a5824 */ 	and	$t3,$t1,$t2
/*  f10772c:	11600003 */ 	beqz	$t3,.L0f10773c
/*  f107730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107734:	1000003b */ 	beqz	$zero,.L0f107824
/*  f107738:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10773c:
/*  f10773c:	10000039 */ 	beqz	$zero,.L0f107824
/*  f107740:	00001025 */ 	or	$v0,$zero,$zero
.L0f107744:
/*  f107744:	90c40001 */ 	lbu	$a0,0x1($a2)
/*  f107748:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10774c:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f107750:	10400033 */ 	beqz	$v0,.L0f107820
/*  f107754:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f107758:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f10775c:	3c05800a */ 	lui	$a1,%hi(g_CheatsEnabledBank0)
/*  f107760:	24a521d8 */ 	addiu	$a1,$a1,%lo(g_CheatsEnabledBank0)
/*  f107764:	28410020 */ 	slti	$at,$v0,0x20
/*  f107768:	1020001f */ 	beqz	$at,.L0f1077e8
/*  f10776c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107770:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f107774:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f107778:	004c2004 */ 	sllv	$a0,$t4,$v0
/*  f10777c:	00836824 */ 	and	$t5,$a0,$v1
/*  f107780:	11a00005 */ 	beqz	$t5,.L0f107798
/*  f107784:	24010014 */ 	addiu	$at,$zero,0x14
/*  f107788:	00807027 */ 	nor	$t6,$a0,$zero
/*  f10778c:	01c37824 */ 	and	$t7,$t6,$v1
/*  f107790:	10000023 */ 	beqz	$zero,.L0f107820
/*  f107794:	acaf0000 */ 	sw	$t7,0x0($a1)
.L0f107798:
/*  f107798:	14410007 */ 	bne	$v0,$at,.L0f1077b8
/*  f10779c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1077a0:	3c01fffb */ 	lui	$at,0xfffb
/*  f1077a4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1077a8:	0061c024 */ 	and	$t8,$v1,$at
/*  f1077ac:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1077b0:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f1077b4:	03001825 */ 	or	$v1,$t8,$zero
.L0f1077b8:
/*  f1077b8:	24010012 */ 	addiu	$at,$zero,0x12
/*  f1077bc:	14410006 */ 	bne	$v0,$at,.L0f1077d8
/*  f1077c0:	3c01ffef */ 	lui	$at,0xffef
/*  f1077c4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1077c8:	0061c824 */ 	and	$t9,$v1,$at
/*  f1077cc:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f1077d0:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f1077d4:	03201825 */ 	or	$v1,$t9,$zero
.L0f1077d8:
/*  f1077d8:	00484804 */ 	sllv	$t1,$t0,$v0
/*  f1077dc:	01235025 */ 	or	$t2,$t1,$v1
/*  f1077e0:	1000000f */ 	beqz	$zero,.L0f107820
/*  f1077e4:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f1077e8:
/*  f1077e8:	3c06800a */ 	lui	$a2,%hi(g_CheatsEnabledBank1)
/*  f1077ec:	24c621dc */ 	addiu	$a2,$a2,%lo(g_CheatsEnabledBank1)
/*  f1077f0:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f1077f4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1077f8:	004b2004 */ 	sllv	$a0,$t3,$v0
/*  f1077fc:	00836024 */ 	and	$t4,$a0,$v1
/*  f107800:	11800005 */ 	beqz	$t4,.L0f107818
/*  f107804:	00802825 */ 	or	$a1,$a0,$zero
/*  f107808:	00806827 */ 	nor	$t5,$a0,$zero
/*  f10780c:	01a37024 */ 	and	$t6,$t5,$v1
/*  f107810:	10000003 */ 	beqz	$zero,.L0f107820
/*  f107814:	acce0000 */ 	sw	$t6,0x0($a2)
.L0f107818:
/*  f107818:	00a37825 */ 	or	$t7,$a1,$v1
/*  f10781c:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f107820:
/*  f107820:	00001025 */ 	or	$v0,$zero,$zero
.L0f107824:
/*  f107824:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f107828:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10782c:	03e00008 */ 	jr	$ra
/*  f107830:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch due to different registers in case 6 (v1/a0)
//s32 cheatMenuHandleCheatCheckbox(u32 arg0, struct menu_item *item, s32 arg2)
//{
//	switch (arg0) {
//	case 8:
//		if (item->param < 32) {
//			if (g_CheatsEnabledBank0 & (1 << item->param)) {
//				return true;
//			}
//
//			return false;
//		}
//
//		if (g_CheatsEnabledBank1 & (1 << item->param)) {
//			return true;
//		}
//
//		return false;
//	case 6:
//		if (cheatIsUnlocked(item->param)) {
//			if (item->param < 32) { // Bank 0
//				if (g_CheatsEnabledBank0 & (1 << item->param)) { // Turning off
//					g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << item->param);
//				} else { // Turning on
//					// If enabling Marquis or enemy rockets, turn off the other
//					if (item->param == CHEAT_MARQUIS) {
//						g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << CHEAT_ENEMYROCKETS);
//					}
//
//					if (item->param == CHEAT_ENEMYROCKETS) {
//						g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << CHEAT_MARQUIS);
//					}
//
//					g_CheatsEnabledBank0 = g_CheatsEnabledBank0 | (1 << item->param);
//				}
//			} else { // Bank 1
//				if ((1 << item->param) & g_CheatsEnabledBank1) { // Turning off
//					g_CheatsEnabledBank1 = g_CheatsEnabledBank1 & ~(1 << item->param);
//				} else { // Turning on
//					g_CheatsEnabledBank1 = g_CheatsEnabledBank1 | (1 << item->param);
//				}
//			}
//		}
//	}
//
//	return 0;
//}

s32 cheatMenuHandleBuddyCheckbox(s32 operation, struct menu_item *item, s32 arg2)
{
	switch (operation) {
	case MENUOP_GET:
		if (item->param == 0) {
			if (g_CheatsEnabledBank0 & (1 << CHEAT_PUGILIST | 1 << CHEAT_HOTSHOT | 1 << CHEAT_HITANDRUN | 1 << CHEAT_ALIEN)) {
				return false;
			}

			return true;
		}

		if (g_CheatsEnabledBank0 & (1 << item->param)) {
			return true;
		}

		return false;
	case MENUOP_SET:
		if (item->param == 0) {
			// Velvet
			g_CheatsEnabledBank0 &= ~(
				(1 << CHEAT_PUGILIST) |
				(1 << CHEAT_HOTSHOT) |
				(1 << CHEAT_HITANDRUN) |
				(1 << CHEAT_ALIEN)
			);
		} else if (cheatIsUnlocked(item->param)) {
			// Not Velvet
			g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(
				(1 << CHEAT_PUGILIST) |
				(1 << CHEAT_HOTSHOT) |
				(1 << CHEAT_HITANDRUN) |
				(1 << CHEAT_ALIEN)
			);
			g_CheatsEnabledBank0 = g_CheatsEnabledBank0 | (1 << item->param);
		}
	}

	return 0;
}

char *cheatGetNameIfUnlocked(struct menu_item *item)
{
	if (cheatIsUnlocked(item->param)) {
		return textGet(g_Cheats[item->param].nametextid);
	}

	return textGet(0x544a); // "----------"
}

GLOBAL_ASM(
glabel cheatMenuHandleDialog
/*  f107990:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f107994:	24010064 */ 	addiu	$at,$zero,0x64
/*  f107998:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10799c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1079a0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1079a4:	14810023 */ 	bne	$a0,$at,.L0f107a34
/*  f1079a8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1079ac:	0fc5294b */ 	jal	func0f14a52c
/*  f1079b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1079b4:	0fc479e3 */ 	jal	func0f11e78c
/*  f1079b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1079bc:	10400003 */ 	beqz	$v0,.L0f1079cc
/*  f1079c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1079c4:	0fc43c4f */ 	jal	eepromSet
/*  f1079c8:	24040023 */ 	addiu	$a0,$zero,0x23
.L0f1079cc:
/*  f1079cc:	3c067000 */ 	lui	$a2,0x7000
/*  f1079d0:	3c057000 */ 	lui	$a1,0x7000
/*  f1079d4:	24c62148 */ 	addiu	$a2,$a2,0x2148
/*  f1079d8:	24a422e0 */ 	addiu	$a0,$a1,0x22e0
/*  f1079dc:	00c4082b */ 	sltu	$at,$a2,$a0
/*  f1079e0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f1079e4:	10200007 */ 	beqz	$at,.L0f107a04
/*  f1079e8:	00001825 */ 	or	$v1,$zero,$zero
.L0f1079ec:
/*  f1079ec:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f1079f0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1079f4:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1079f8:	01e0c027 */ 	nor	$t8,$t7,$zero
/*  f1079fc:	1420fffb */ 	bnez	$at,.L0f1079ec
/*  f107a00:	00781826 */ 	xor	$v1,$v1,$t8
.L0f107a04:
/*  f107a04:	3c016f76 */ 	lui	$at,0x6f76
/*  f107a08:	34214531 */ 	ori	$at,$at,0x4531
/*  f107a0c:	10610009 */ 	beq	$v1,$at,.L0f107a34
/*  f107a10:	24c20050 */ 	addiu	$v0,$a2,0x50
/*  f107a14:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f107a18:	0044082b */ 	sltu	$at,$v0,$a0
/*  f107a1c:	10200005 */ 	beqz	$at,.L0f107a34
/*  f107a20:	24030012 */ 	addiu	$v1,$zero,0x12
.L0f107a24:
/*  f107a24:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f107a28:	0044082b */ 	sltu	$at,$v0,$a0
/*  f107a2c:	1420fffd */ 	bnez	$at,.L0f107a24
/*  f107a30:	ac43fffc */ 	sw	$v1,-0x4($v0)
.L0f107a34:
/*  f107a34:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f107a38:	24010065 */ 	addiu	$at,$zero,0x65
/*  f107a3c:	5721000a */ 	bnel	$t9,$at,.L0f107a68
/*  f107a40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f107a44:	0fc479e3 */ 	jal	func0f11e78c
/*  f107a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107a4c:	10400003 */ 	beqz	$v0,.L0f107a5c
/*  f107a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107a54:	0fc43c4f */ 	jal	eepromSet
/*  f107a58:	24040023 */ 	addiu	$a0,$zero,0x23
.L0f107a5c:
/*  f107a5c:	0fc52958 */ 	jal	func0f14a560
/*  f107a60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107a64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f107a68:
/*  f107a68:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f107a6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f107a70:	03e00008 */ 	jr	$ra
/*  f107a74:	00000000 */ 	sll	$zero,$zero,0x0
);

char *cheatGetMarquee(struct menu_item *arg0)
{
	u32 cheat_id;
	u8 *ptr;
	u8 difficultyname[256];
	u8 cheatname[256];

	if (g_MenuStack[g_MenuStackDepth].unk00 && g_MenuStack[g_MenuStackDepth].unk00->item && g_MenuStack[g_MenuStackDepth].unk00->item->type == MENUITEMTYPE_CHECKBOX) {
		cheat_id = g_MenuStack[g_MenuStackDepth].unk00->item->param;

		if (g_MenuStack[g_MenuStackDepth].unk00->dialog == &menudialog_cheats_buddies && g_MenuStack[g_MenuStackDepth].unk00->item == &menuitems_cheats_buddies[0]) {
			// Velvet
			sprintf(g_CheatMarqueeString, "%s: %s", textGet(0x548f), textGet(0x5475)); // "Buddy Available", "Velvet Dark"
			return g_CheatMarqueeString;
		}

		if (cheatIsUnlocked(cheat_id)) {
			// Show cheat name
			sprintf(g_CheatMarqueeString, "%s: %s\n",
					g_MenuStack[g_MenuStackDepth].unk00->dialog == &menudialog_cheats_buddies ? textGet(0x548f) : textGet(0x5488), // "Buddy Available", "Cheat available"
					textGet(g_Cheats[cheat_id].nametextid)
			);
			return g_CheatMarqueeString;
		}

		// Locked
		strcpy(&cheatname, textGet(g_Cheats[cheat_id].nametextid));
		ptr = cheatname;

		while (*ptr != '\n') {
			ptr++;
		}

		*ptr = '\0';

		if (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) {
			sprintf(g_CheatMarqueeString, "%s %s: %s %s %s",
					textGet(0x5489), // "Complete"
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
					textGet(0x548a), // "for cheat:"
					&cheatname
			);
		} else {
			// Timed
			strcpy(&difficultyname, textGet(0x56fb + g_Cheats[cheat_id].difficulty));
			ptr = difficultyname;

			while (*ptr != '\n') {
				ptr++;
			}

			*ptr = '\0';

			sprintf(g_CheatMarqueeString, "%s %s: %s %s %s %s %d:%02d %s %s",
					textGet(0x5489), // "Complete"
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
					textGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
					textGet(0x548b), // "on"
					&difficultyname,
					textGet(0x548c), // "in under"
					g_Cheats[cheat_id].time / 60,
					g_Cheats[cheat_id].time % 60,
					textGet(0x548a), // "for cheat:"
					&cheatname
			);
		}

		if (g_Cheats[cheat_id].flags & CHEATFLAG_TRANSFERPAK) {
			func00013224(&g_CheatMarqueeString, textGet(0x548d)); // " or insert Game Boy ..."
		}

		func00013224(&g_CheatMarqueeString, "\n");
		return g_CheatMarqueeString;
	}

	// No cheat selected
	return textGet(0x548e); // "Select cheat for information"
}

bool cheatMenuHandleTurnOffAllCheats(u32 operation, u32 arg1, u32 *arg2)
{
	if (operation == MENUOP_SET) {
		g_CheatsEnabledBank0 = 0;
		g_CheatsEnabledBank1 = 0;
	}

	return false;
}

s32 cheatGetByTimedStageIndex(s32 stage_index, s32 difficulty)
{
	s32 cheat_id;

	for (cheat_id = 0; cheat_id < NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].stage_index == stage_index &&
				g_Cheats[cheat_id].difficulty == difficulty &&
				(g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) == 0 &&
				(g_Cheats[cheat_id].flags & CHEATFLAG_FIRINGRANGE) == 0) {
			return cheat_id;
		}
	}

	return -1;
}

s32 cheatGetByCompletedStageIndex(s32 stage_index)
{
	s32 cheat_id;

	for (cheat_id = 0; cheat_id < NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].stage_index == stage_index && (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION)) {
			return cheat_id;
		}
	}

	return -1;
}

s32 cheatGetTime(s32 cheat_id)
{
	return g_Cheats[cheat_id].time;
}

char *cheatGetName(s32 cheat_id)
{
	return textGet(g_Cheats[cheat_id].nametextid);
}
