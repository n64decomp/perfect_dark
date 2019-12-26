#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_106d40.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/game_115ab0.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/game_16cfa0.h"
#include "game/game_19c990.h"

const char var7f1b2eb0[] = "%s: %s";
const char var7f1b2eb8[] = "%s: %s\n";
const char var7f1b2ec0[] = "%s %s: %s %s %s";
const char var7f1b2ed0[] = "%s %s: %s %s %s %s %d:%02d %s %s";
const char var7f1b2ef4[] = "\n";
const char var7f1b2ef8[] = "";
const char var7f1b2efc[] = "";

GLOBAL_ASM(
glabel func0f106d40
/*  f106d40:	3c0f8007 */ 	lui	$t7,%hi(cheatspecs)
/*  f106d44:	25ef3a90 */ 	addiu	$t7,$t7,%lo(cheatspecs)
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

bool cheatIsEnabled(s32 cheat_id)
{
	if (cheat_id < 32) {
		return g_CheatsEnabledBank0 & (1 << cheat_id);
	}

	return g_CheatsEnabledBank1 & (1 << cheat_id);
}

GLOBAL_ASM(
glabel func0f106ea0
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
/*  f107164:	3c02800a */ 	lui	$v0,%hi(g_CheatsEnabledBank0)
/*  f107168:	244221d0 */ 	addiu	$v0,$v0,%lo(g_CheatsEnabledBank0)
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
/*  f107190:	3c02800a */ 	lui	$v0,%hi(g_CheatsEnabledBank1)
/*  f107194:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f107198:	244221d4 */ 	addiu	$v0,$v0,%lo(g_CheatsEnabledBank1)
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
glabel func0f1071c4
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
/*  f107488:	3c02800a */ 	lui	$v0,%hi(g_CheatsEnabledBank0)
/*  f10748c:	244221d0 */ 	addiu	$v0,$v0,%lo(g_CheatsEnabledBank0)
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
/*  f1074b8:	3c02800a */ 	lui	$v0,%hi(g_CheatsEnabledBank1)
/*  f1074bc:	244221d4 */ 	addiu	$v0,$v0,%lo(g_CheatsEnabledBank1)
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

GLOBAL_ASM(
glabel func0f1074ec
/*  f1074ec:	3c01800a */ 	lui	$at,0x800a
/*  f1074f0:	ac2021d0 */ 	sw	$zero,0x21d0($at)
/*  f1074f4:	3c01800a */ 	lui	$at,0x800a
/*  f1074f8:	ac2021d4 */ 	sw	$zero,0x21d4($at)
/*  f1074fc:	3c01800a */ 	lui	$at,0x800a
/*  f107500:	ac2021d8 */ 	sw	$zero,0x21d8($at)
/*  f107504:	3c01800a */ 	lui	$at,0x800a
/*  f107508:	03e00008 */ 	jr	$ra
/*  f10750c:	ac2021dc */ 	sw	$zero,0x21dc($at)
);

GLOBAL_ASM(
glabel func0f107510
/*  f107510:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f107514:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f107518:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f10751c:	8c4e04b4 */ 	lw	$t6,0x4b4($v0)
/*  f107520:	24010026 */ 	addiu	$at,$zero,0x26
/*  f107524:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f107528:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f10752c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f107530:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f107534:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f107538:	11c1001d */ 	beq	$t6,$at,.L0f1075b0
/*  f10753c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f107540:	3c0f800a */ 	lui	$t7,0x800a
/*  f107544:	8def21d8 */ 	lw	$t7,0x21d8($t7)
/*  f107548:	3c12800a */ 	lui	$s2,%hi(g_CheatsEnabledBank0)
/*  f10754c:	265221d0 */ 	addiu	$s2,$s2,%lo(g_CheatsEnabledBank0)
/*  f107550:	8c590298 */ 	lw	$t9,0x298($v0)
/*  f107554:	3c18800a */ 	lui	$t8,0x800a
/*  f107558:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f10755c:	8f1821dc */ 	lw	$t8,0x21dc($t8)
/*  f107560:	3c13800a */ 	lui	$s3,%hi(g_CheatsEnabledBank1)
/*  f107564:	267321d4 */ 	addiu	$s3,$s3,%lo(g_CheatsEnabledBank1)
/*  f107568:	07210007 */ 	bgez	$t9,.L0f107588
/*  f10756c:	ae780000 */ 	sw	$t8,0x0($s3)
/*  f107570:	8c48029c */ 	lw	$t0,0x29c($v0)
/*  f107574:	05030005 */ 	bgezl	$t0,.L0f10758c
/*  f107578:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f10757c:	8c490318 */ 	lw	$t1,0x318($v0)
/*  f107580:	11200011 */ 	beqz	$t1,.L0f1075c8
/*  f107584:	00000000 */ 	sll	$zero,$zero,0x0
.L0f107588:
/*  f107588:	8e4a0000 */ 	lw	$t2,0x0($s2)
.L0f10758c:
/*  f10758c:	3c0107ff */ 	lui	$at,0x7ff
/*  f107590:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f107594:	3421fcff */ 	ori	$at,$at,0xfcff
/*  f107598:	01415824 */ 	and	$t3,$t2,$at
/*  f10759c:	2401fc00 */ 	addiu	$at,$zero,-1024
/*  f1075a0:	01816824 */ 	and	$t5,$t4,$at
/*  f1075a4:	ae4b0000 */ 	sw	$t3,0x0($s2)
/*  f1075a8:	10000007 */ 	beqz	$zero,.L0f1075c8
/*  f1075ac:	ae6d0000 */ 	sw	$t5,0x0($s3)
.L0f1075b0:
/*  f1075b0:	3c12800a */ 	lui	$s2,%hi(g_CheatsEnabledBank0)
/*  f1075b4:	3c13800a */ 	lui	$s3,%hi(g_CheatsEnabledBank1)
/*  f1075b8:	267321d4 */ 	addiu	$s3,$s3,%lo(g_CheatsEnabledBank1)
/*  f1075bc:	265221d0 */ 	addiu	$s2,$s2,%lo(g_CheatsEnabledBank0)
/*  f1075c0:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f1075c4:	ae600000 */ 	sw	$zero,0x0($s3)
.L0f1075c8:
/*  f1075c8:	3c118007 */ 	lui	$s1,%hi(cheatspecs)
/*  f1075cc:	26313a90 */ 	addiu	$s1,$s1,%lo(cheatspecs)
/*  f1075d0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1075d4:	2414002a */ 	addiu	$s4,$zero,0x2a
.L0f1075d8:
/*  f1075d8:	922e0006 */ 	lbu	$t6,0x6($s1)
/*  f1075dc:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f1075e0:	11e00022 */ 	beqz	$t7,.L0f10766c
/*  f1075e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1075e8:	0fc41b50 */ 	jal	func0f106d40
/*  f1075ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f1075f0:	10400010 */ 	beqz	$v0,.L0f107634
/*  f1075f4:	2a010020 */ 	slti	$at,$s0,0x20
/*  f1075f8:	2a010020 */ 	slti	$at,$s0,0x20
/*  f1075fc:	50200008 */ 	beqzl	$at,.L0f107620
/*  f107600:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f107604:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f107608:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f10760c:	0218c804 */ 	sllv	$t9,$t8,$s0
/*  f107610:	03284825 */ 	or	$t1,$t9,$t0
/*  f107614:	10000015 */ 	beqz	$zero,.L0f10766c
/*  f107618:	ae490000 */ 	sw	$t1,0x0($s2)
/*  f10761c:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f107620:
/*  f107620:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f107624:	020a5804 */ 	sllv	$t3,$t2,$s0
/*  f107628:	016c6825 */ 	or	$t5,$t3,$t4
/*  f10762c:	1000000f */ 	beqz	$zero,.L0f10766c
/*  f107630:	ae6d0000 */ 	sw	$t5,0x0($s3)
.L0f107634:
/*  f107634:	10200008 */ 	beqz	$at,.L0f107658
/*  f107638:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f10763c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f107640:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f107644:	020e7804 */ 	sllv	$t7,$t6,$s0
/*  f107648:	01e0c027 */ 	nor	$t8,$t7,$zero
/*  f10764c:	03194024 */ 	and	$t0,$t8,$t9
/*  f107650:	10000006 */ 	beqz	$zero,.L0f10766c
/*  f107654:	ae480000 */ 	sw	$t0,0x0($s2)
.L0f107658:
/*  f107658:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f10765c:	02095004 */ 	sllv	$t2,$t1,$s0
/*  f107660:	01405827 */ 	nor	$t3,$t2,$zero
/*  f107664:	016c6824 */ 	and	$t5,$t3,$t4
/*  f107668:	ae6d0000 */ 	sw	$t5,0x0($s3)
.L0f10766c:
/*  f10766c:	0fc41b99 */ 	jal	cheatIsEnabled
/*  f107670:	02002025 */ 	or	$a0,$s0,$zero
/*  f107674:	50400004 */ 	beqzl	$v0,.L0f107688
/*  f107678:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10767c:	0fc41ba8 */ 	jal	func0f106ea0
/*  f107680:	02002025 */ 	or	$a0,$s0,$zero
/*  f107684:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f107688:
/*  f107688:	1614ffd3 */ 	bne	$s0,$s4,.L0f1075d8
/*  f10768c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f107690:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f107694:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f107698:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f10769c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1076a0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1076a4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1076a8:	03e00008 */ 	jr	$ra
/*  f1076ac:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel menuhandlerCheat
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
/*  f1076dc:	3c06800a */ 	lui	$a2,%hi(var800a21dc)
/*  f1076e0:	3c05800a */ 	lui	$a1,%hi(var800a21d8)
/*  f1076e4:	28410020 */ 	slti	$at,$v0,0x20
/*  f1076e8:	1020000c */ 	beqz	$at,.L0f10771c
/*  f1076ec:	24c621dc */ 	addiu	$a2,$a2,%lo(var800a21dc)
/*  f1076f0:	24a521d8 */ 	addiu	$a1,$a1,%lo(var800a21d8)
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
/*  f107748:	0fc41b50 */ 	jal	func0f106d40
/*  f10774c:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f107750:	10400033 */ 	beqz	$v0,.L0f107820
/*  f107754:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f107758:	90c20001 */ 	lbu	$v0,0x1($a2)
/*  f10775c:	3c05800a */ 	lui	$a1,%hi(var800a21d8)
/*  f107760:	24a521d8 */ 	addiu	$a1,$a1,%lo(var800a21d8)
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
/*  f1077e8:	3c06800a */ 	lui	$a2,%hi(var800a21dc)
/*  f1077ec:	24c621dc */ 	addiu	$a2,$a2,%lo(var800a21dc)
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

GLOBAL_ASM(
glabel menuhandlerCheatBuddy
/*  f107834:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f107838:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10783c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f107840:	1081001e */ 	beq	$a0,$at,.L0f1078bc
/*  f107844:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f107848:	24010008 */ 	addiu	$at,$zero,0x8
/*  f10784c:	54810037 */ 	bnel	$a0,$at,.L0f10792c
/*  f107850:	00001025 */ 	or	$v0,$zero,$zero
/*  f107854:	90a40001 */ 	lbu	$a0,0x1($a1)
/*  f107858:	3c02800a */ 	lui	$v0,%hi(var800a21d8)
/*  f10785c:	244221d8 */ 	addiu	$v0,$v0,%lo(var800a21d8)
/*  f107860:	5480000d */ 	bnezl	$a0,.L0f107898
/*  f107864:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f107868:	3c02800a */ 	lui	$v0,%hi(var800a21d8)
/*  f10786c:	244221d8 */ 	addiu	$v0,$v0,%lo(var800a21d8)
/*  f107870:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f107874:	3c0103c0 */ 	lui	$at,0x3c0
/*  f107878:	01c17824 */ 	and	$t7,$t6,$at
/*  f10787c:	11e00003 */ 	beqz	$t7,.L0f10788c
/*  f107880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107884:	10000029 */ 	beqz	$zero,.L0f10792c
/*  f107888:	00001025 */ 	or	$v0,$zero,$zero
.L0f10788c:
/*  f10788c:	10000027 */ 	beqz	$zero,.L0f10792c
/*  f107890:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f107894:	8c480000 */ 	lw	$t0,0x0($v0)
.L0f107898:
/*  f107898:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f10789c:	0098c804 */ 	sllv	$t9,$t8,$a0
/*  f1078a0:	03284824 */ 	and	$t1,$t9,$t0
/*  f1078a4:	11200003 */ 	beqz	$t1,.L0f1078b4
/*  f1078a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1078ac:	1000001f */ 	beqz	$zero,.L0f10792c
/*  f1078b0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1078b4:
/*  f1078b4:	1000001d */ 	beqz	$zero,.L0f10792c
/*  f1078b8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1078bc:
/*  f1078bc:	90a40001 */ 	lbu	$a0,0x1($a1)
/*  f1078c0:	3c02800a */ 	lui	$v0,%hi(var800a21d8)
/*  f1078c4:	244221d8 */ 	addiu	$v0,$v0,%lo(var800a21d8)
/*  f1078c8:	14800007 */ 	bnez	$a0,.L0f1078e8
/*  f1078cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1078d0:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f1078d4:	3c01fc3f */ 	lui	$at,0xfc3f
/*  f1078d8:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1078dc:	01415824 */ 	and	$t3,$t2,$at
/*  f1078e0:	10000011 */ 	beqz	$zero,.L0f107928
/*  f1078e4:	ac4b0000 */ 	sw	$t3,0x0($v0)
.L0f1078e8:
/*  f1078e8:	0fc41b50 */ 	jal	func0f106d40
/*  f1078ec:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1078f0:	1040000d */ 	beqz	$v0,.L0f107928
/*  f1078f4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f1078f8:	3c02800a */ 	lui	$v0,%hi(var800a21d8)
/*  f1078fc:	244221d8 */ 	addiu	$v0,$v0,%lo(var800a21d8)
/*  f107900:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f107904:	3c01fc3f */ 	lui	$at,0xfc3f
/*  f107908:	3421ffff */ 	ori	$at,$at,0xffff
/*  f10790c:	01816824 */ 	and	$t5,$t4,$at
/*  f107910:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f107914:	90ae0001 */ 	lbu	$t6,0x1($a1)
/*  f107918:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10791c:	01cfc004 */ 	sllv	$t8,$t7,$t6
/*  f107920:	030d4025 */ 	or	$t0,$t8,$t5
/*  f107924:	ac480000 */ 	sw	$t0,0x0($v0)
.L0f107928:
/*  f107928:	00001025 */ 	or	$v0,$zero,$zero
.L0f10792c:
/*  f10792c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f107930:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f107934:	03e00008 */ 	jr	$ra
/*  f107938:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10793c
/*  f10793c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f107940:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f107944:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f107948:	0fc41b50 */ 	jal	func0f106d40
/*  f10794c:	90840001 */ 	lbu	$a0,0x1($a0)
/*  f107950:	10400009 */ 	beqz	$v0,.L0f107978
/*  f107954:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f107958:	91f80001 */ 	lbu	$t8,0x1($t7)
/*  f10795c:	3c048007 */ 	lui	$a0,0x8007
/*  f107960:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f107964:	00992021 */ 	addu	$a0,$a0,$t9
/*  f107968:	0fc5b9f1 */ 	jal	textGet
/*  f10796c:	94843a90 */ 	lhu	$a0,0x3a90($a0)
/*  f107970:	10000004 */ 	beqz	$zero,.L0f107984
/*  f107974:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f107978:
/*  f107978:	0fc5b9f1 */ 	jal	textGet
/*  f10797c:	2404544a */ 	addiu	$a0,$zero,0x544a
/*  f107980:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f107984:
/*  f107984:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f107988:	03e00008 */ 	jr	$ra
/*  f10798c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog00107990
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

GLOBAL_ASM(
glabel func0f107a78
/*  f107a78:	3c0e8007 */ 	lui	$t6,0x8007
/*  f107a7c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f107a80:	3c03800a */ 	lui	$v1,0x800a
/*  f107a84:	27bdfda0 */ 	addiu	$sp,$sp,-608
/*  f107a88:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f107a8c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f107a90:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f107a94:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f107a98:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f107a9c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f107aa0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f107aa4:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f107aa8:	8c63e4f8 */ 	lw	$v1,-0x1b08($v1)
/*  f107aac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f107ab0:	afa40260 */ 	sw	$a0,0x260($sp)
/*  f107ab4:	106000f0 */ 	beqz	$v1,.L0f107e78
/*  f107ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107abc:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f107ac0:	104000ed */ 	beqz	$v0,.L0f107e78
/*  f107ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107ac8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f107acc:	24010009 */ 	addiu	$at,$zero,0x9
/*  f107ad0:	170100e9 */ 	bne	$t8,$at,.L0f107e78
/*  f107ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107ad8:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f107adc:	3c198007 */ 	lui	$t9,%hi(menudialog_cheats_buddies)
/*  f107ae0:	27394274 */ 	addiu	$t9,$t9,%lo(menudialog_cheats_buddies)
/*  f107ae4:	17290014 */ 	bne	$t9,$t1,.L0f107b38
/*  f107ae8:	90440001 */ 	lbu	$a0,0x1($v0)
/*  f107aec:	3c0a8007 */ 	lui	$t2,%hi(menuitems_cheats_buddies)
/*  f107af0:	254a41ac */ 	addiu	$t2,$t2,%lo(menuitems_cheats_buddies)
/*  f107af4:	15420010 */ 	bne	$t2,$v0,.L0f107b38
/*  f107af8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107afc:	0fc5b9f1 */ 	jal	textGet
/*  f107b00:	2404548f */ 	addiu	$a0,$zero,0x548f
/*  f107b04:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f107b08:	0fc5b9f1 */ 	jal	textGet
/*  f107b0c:	24045475 */ 	addiu	$a0,$zero,0x5475
/*  f107b10:	3c04800a */ 	lui	$a0,%hi(var8009dec0)
/*  f107b14:	3c057f1b */ 	lui	$a1,%hi(var7f1b2eb0)
/*  f107b18:	24a52eb0 */ 	addiu	$a1,$a1,%lo(var7f1b2eb0)
/*  f107b1c:	2484dec0 */ 	addiu	$a0,$a0,%lo(var8009dec0)
/*  f107b20:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f107b24:	0c004dad */ 	jal	func000136b4
/*  f107b28:	00403825 */ 	or	$a3,$v0,$zero
/*  f107b2c:	3c02800a */ 	lui	$v0,%hi(var8009dec0)
/*  f107b30:	100000d3 */ 	beqz	$zero,.L0f107e80
/*  f107b34:	2442dec0 */ 	addiu	$v0,$v0,%lo(var8009dec0)
.L0f107b38:
/*  f107b38:	0fc41b50 */ 	jal	func0f106d40
/*  f107b3c:	afa4025c */ 	sw	$a0,0x25c($sp)
/*  f107b40:	10400029 */ 	beqz	$v0,.L0f107be8
/*  f107b44:	8fa9025c */ 	lw	$t1,0x25c($sp)
/*  f107b48:	3c0c8007 */ 	lui	$t4,0x8007
/*  f107b4c:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f107b50:	3c0e800a */ 	lui	$t6,0x800a
/*  f107b54:	3c0b8007 */ 	lui	$t3,%hi(menudialog_cheats_buddies)
/*  f107b58:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f107b5c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f107b60:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f107b64:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f107b68:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f107b6c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f107b70:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f107b74:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f107b78:	8dcee4f8 */ 	lw	$t6,-0x1b08($t6)
/*  f107b7c:	256b4274 */ 	addiu	$t3,$t3,%lo(menudialog_cheats_buddies)
/*  f107b80:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f107b84:	156f0005 */ 	bne	$t3,$t7,.L0f107b9c
/*  f107b88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107b8c:	0fc5b9f1 */ 	jal	textGet
/*  f107b90:	2404548f */ 	addiu	$a0,$zero,0x548f
/*  f107b94:	10000004 */ 	beqz	$zero,.L0f107ba8
/*  f107b98:	afa20050 */ 	sw	$v0,0x50($sp)
.L0f107b9c:
/*  f107b9c:	0fc5b9f1 */ 	jal	textGet
/*  f107ba0:	24045488 */ 	addiu	$a0,$zero,0x5488
/*  f107ba4:	afa20050 */ 	sw	$v0,0x50($sp)
.L0f107ba8:
/*  f107ba8:	8fb8025c */ 	lw	$t8,0x25c($sp)
/*  f107bac:	3c048007 */ 	lui	$a0,0x8007
/*  f107bb0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f107bb4:	00992021 */ 	addu	$a0,$a0,$t9
/*  f107bb8:	0fc5b9f1 */ 	jal	textGet
/*  f107bbc:	94843a90 */ 	lhu	$a0,0x3a90($a0)
/*  f107bc0:	3c04800a */ 	lui	$a0,%hi(var8009dec0)
/*  f107bc4:	3c057f1b */ 	lui	$a1,%hi(var7f1b2eb8)
/*  f107bc8:	24a52eb8 */ 	addiu	$a1,$a1,%lo(var7f1b2eb8)
/*  f107bcc:	2484dec0 */ 	addiu	$a0,$a0,%lo(var8009dec0)
/*  f107bd0:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f107bd4:	0c004dad */ 	jal	func000136b4
/*  f107bd8:	00403825 */ 	or	$a3,$v0,$zero
/*  f107bdc:	3c02800a */ 	lui	$v0,%hi(var8009dec0)
/*  f107be0:	100000a7 */ 	beqz	$zero,.L0f107e80
/*  f107be4:	2442dec0 */ 	addiu	$v0,$v0,%lo(var8009dec0)
.L0f107be8:
/*  f107be8:	3c0c8007 */ 	lui	$t4,%hi(cheatspecs)
/*  f107bec:	258c3a90 */ 	addiu	$t4,$t4,%lo(cheatspecs)
/*  f107bf0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f107bf4:	014c1021 */ 	addu	$v0,$t2,$t4
/*  f107bf8:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f107bfc:	0fc5b9f1 */ 	jal	textGet
/*  f107c00:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f107c04:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f107c08:	0c004c4c */ 	jal	func00013130
/*  f107c0c:	00402825 */ 	or	$a1,$v0,$zero
/*  f107c10:	93ad0058 */ 	lbu	$t5,0x58($sp)
/*  f107c14:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f107c18:	27a30058 */ 	addiu	$v1,$sp,0x58
/*  f107c1c:	10cd0005 */ 	beq	$a2,$t5,.L0f107c34
/*  f107c20:	8fa2003c */ 	lw	$v0,0x3c($sp)
/*  f107c24:	906e0001 */ 	lbu	$t6,0x1($v1)
.L0f107c28:
/*  f107c28:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107c2c:	54cefffe */ 	bnel	$a2,$t6,.L0f107c28
/*  f107c30:	906e0001 */ 	lbu	$t6,0x1($v1)
.L0f107c34:
/*  f107c34:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f107c38:	904b0006 */ 	lbu	$t3,0x6($v0)
/*  f107c3c:	316f0004 */ 	andi	$t7,$t3,0x4
/*  f107c40:	51e00029 */ 	beqzl	$t7,.L0f107ce8
/*  f107c44:	90440005 */ 	lbu	$a0,0x5($v0)
/*  f107c48:	0fc5b9f1 */ 	jal	textGet
/*  f107c4c:	24045489 */ 	addiu	$a0,$zero,0x5489
/*  f107c50:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f107c54:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f107c58:	3c048007 */ 	lui	$a0,0x8007
/*  f107c5c:	93190004 */ 	lbu	$t9,0x4($t8)
/*  f107c60:	00194880 */ 	sll	$t1,$t9,0x2
/*  f107c64:	01394823 */ 	subu	$t1,$t1,$t9
/*  f107c68:	00094880 */ 	sll	$t1,$t1,0x2
/*  f107c6c:	00892021 */ 	addu	$a0,$a0,$t1
/*  f107c70:	0fc5b9f1 */ 	jal	textGet
/*  f107c74:	94841e72 */ 	lhu	$a0,0x1e72($a0)
/*  f107c78:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f107c7c:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f107c80:	3c048007 */ 	lui	$a0,0x8007
/*  f107c84:	914c0004 */ 	lbu	$t4,0x4($t2)
/*  f107c88:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f107c8c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f107c90:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f107c94:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f107c98:	0fc5b9f1 */ 	jal	textGet
/*  f107c9c:	94841e74 */ 	lhu	$a0,0x1e74($a0)
/*  f107ca0:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f107ca4:	0fc5b9f1 */ 	jal	textGet
/*  f107ca8:	2404548a */ 	addiu	$a0,$zero,0x548a
/*  f107cac:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f107cb0:	3c04800a */ 	lui	$a0,%hi(var8009dec0)
/*  f107cb4:	3c057f1b */ 	lui	$a1,%hi(var7f1b2ec0)
/*  f107cb8:	27ab0058 */ 	addiu	$t3,$sp,0x58
/*  f107cbc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f107cc0:	24a52ec0 */ 	addiu	$a1,$a1,%lo(var7f1b2ec0)
/*  f107cc4:	2484dec0 */ 	addiu	$a0,$a0,%lo(var8009dec0)
/*  f107cc8:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f107ccc:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f107cd0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f107cd4:	0c004dad */ 	jal	func000136b4
/*  f107cd8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f107cdc:	10000054 */ 	beqz	$zero,.L0f107e30
/*  f107ce0:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f107ce4:	90440005 */ 	lbu	$a0,0x5($v0)
.L0f107ce8:
/*  f107ce8:	0fc5b9f1 */ 	jal	textGet
/*  f107cec:	248456fb */ 	addiu	$a0,$a0,0x56fb
/*  f107cf0:	27a40158 */ 	addiu	$a0,$sp,0x158
/*  f107cf4:	0c004c4c */ 	jal	func00013130
/*  f107cf8:	00402825 */ 	or	$a1,$v0,$zero
/*  f107cfc:	93af0158 */ 	lbu	$t7,0x158($sp)
/*  f107d00:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f107d04:	27a30158 */ 	addiu	$v1,$sp,0x158
/*  f107d08:	10cf0005 */ 	beq	$a2,$t7,.L0f107d20
/*  f107d0c:	24045489 */ 	addiu	$a0,$zero,0x5489
/*  f107d10:	90780001 */ 	lbu	$t8,0x1($v1)
.L0f107d14:
/*  f107d14:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107d18:	54d8fffe */ 	bnel	$a2,$t8,.L0f107d14
/*  f107d1c:	90780001 */ 	lbu	$t8,0x1($v1)
.L0f107d20:
/*  f107d20:	0fc5b9f1 */ 	jal	textGet
/*  f107d24:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f107d28:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f107d2c:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f107d30:	3c048007 */ 	lui	$a0,0x8007
/*  f107d34:	93290004 */ 	lbu	$t1,0x4($t9)
/*  f107d38:	00095080 */ 	sll	$t2,$t1,0x2
/*  f107d3c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f107d40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f107d44:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f107d48:	0fc5b9f1 */ 	jal	textGet
/*  f107d4c:	94841e72 */ 	lhu	$a0,0x1e72($a0)
/*  f107d50:	8fac003c */ 	lw	$t4,0x3c($sp)
/*  f107d54:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f107d58:	3c048007 */ 	lui	$a0,0x8007
/*  f107d5c:	918d0004 */ 	lbu	$t5,0x4($t4)
/*  f107d60:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f107d64:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f107d68:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f107d6c:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f107d70:	0fc5b9f1 */ 	jal	textGet
/*  f107d74:	94841e74 */ 	lhu	$a0,0x1e74($a0)
/*  f107d78:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f107d7c:	0fc5b9f1 */ 	jal	textGet
/*  f107d80:	2404548b */ 	addiu	$a0,$zero,0x548b
/*  f107d84:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f107d88:	0fc5b9f1 */ 	jal	textGet
/*  f107d8c:	2404548c */ 	addiu	$a0,$zero,0x548c
/*  f107d90:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f107d94:	0fc5b9f1 */ 	jal	textGet
/*  f107d98:	2404548a */ 	addiu	$a0,$zero,0x548a
/*  f107d9c:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f107da0:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f107da4:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f107da8:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f107dac:	27b80158 */ 	addiu	$t8,$sp,0x158
/*  f107db0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f107db4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f107db8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f107dbc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f107dc0:	95230002 */ 	lhu	$v1,0x2($t1)
/*  f107dc4:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f107dc8:	3c04800a */ 	lui	$a0,%hi(var8009dec0)
/*  f107dcc:	0068001a */ 	div	$zero,$v1,$t0
/*  f107dd0:	00006010 */ 	mfhi	$t4
/*  f107dd4:	00005012 */ 	mflo	$t2
/*  f107dd8:	3c057f1b */ 	lui	$a1,%hi(var7f1b2ed0)
/*  f107ddc:	27ad0058 */ 	addiu	$t5,$sp,0x58
/*  f107de0:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f107de4:	24a52ed0 */ 	addiu	$a1,$a1,%lo(var7f1b2ed0)
/*  f107de8:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f107dec:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f107df0:	2484dec0 */ 	addiu	$a0,$a0,%lo(var8009dec0)
/*  f107df4:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f107df8:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f107dfc:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f107e00:	15000002 */ 	bnez	$t0,.L0f107e0c
/*  f107e04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107e08:	0007000d */ 	break	0x7
.L0f107e0c:
/*  f107e0c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f107e10:	15010004 */ 	bne	$t0,$at,.L0f107e24
/*  f107e14:	3c018000 */ 	lui	$at,0x8000
/*  f107e18:	14610002 */ 	bne	$v1,$at,.L0f107e24
/*  f107e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107e20:	0006000d */ 	break	0x6
.L0f107e24:
/*  f107e24:	0c004dad */ 	jal	func000136b4
/*  f107e28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107e2c:	8fae003c */ 	lw	$t6,0x3c($sp)
.L0f107e30:
/*  f107e30:	91cb0006 */ 	lbu	$t3,0x6($t6)
/*  f107e34:	316f0002 */ 	andi	$t7,$t3,0x2
/*  f107e38:	11e00007 */ 	beqz	$t7,.L0f107e58
/*  f107e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107e40:	0fc5b9f1 */ 	jal	textGet
/*  f107e44:	2404548d */ 	addiu	$a0,$zero,0x548d
/*  f107e48:	3c04800a */ 	lui	$a0,%hi(var8009dec0)
/*  f107e4c:	2484dec0 */ 	addiu	$a0,$a0,%lo(var8009dec0)
/*  f107e50:	0c004c89 */ 	jal	func00013224
/*  f107e54:	00402825 */ 	or	$a1,$v0,$zero
.L0f107e58:
/*  f107e58:	3c04800a */ 	lui	$a0,%hi(var8009dec0)
/*  f107e5c:	3c057f1b */ 	lui	$a1,%hi(var7f1b2ef4)
/*  f107e60:	24a52ef4 */ 	addiu	$a1,$a1,%lo(var7f1b2ef4)
/*  f107e64:	0c004c89 */ 	jal	func00013224
/*  f107e68:	2484dec0 */ 	addiu	$a0,$a0,%lo(var8009dec0)
/*  f107e6c:	3c02800a */ 	lui	$v0,%hi(var8009dec0)
/*  f107e70:	10000003 */ 	beqz	$zero,.L0f107e80
/*  f107e74:	2442dec0 */ 	addiu	$v0,$v0,%lo(var8009dec0)
.L0f107e78:
/*  f107e78:	0fc5b9f1 */ 	jal	textGet
/*  f107e7c:	2404548e */ 	addiu	$a0,$zero,0x548e
.L0f107e80:
/*  f107e80:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f107e84:	27bd0260 */ 	addiu	$sp,$sp,0x260
/*  f107e88:	03e00008 */ 	jr	$ra
/*  f107e8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandlerTurnOffAllCheats
/*  f107e90:	24010006 */ 	addiu	$at,$zero,0x6
/*  f107e94:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f107e98:	14810005 */ 	bne	$a0,$at,.L0f107eb0
/*  f107e9c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f107ea0:	3c01800a */ 	lui	$at,0x800a
/*  f107ea4:	ac2021d8 */ 	sw	$zero,0x21d8($at)
/*  f107ea8:	3c01800a */ 	lui	$at,0x800a
/*  f107eac:	ac2021dc */ 	sw	$zero,0x21dc($at)
.L0f107eb0:
/*  f107eb0:	03e00008 */ 	jr	$ra
/*  f107eb4:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f107eb8
/*  f107eb8:	3c028007 */ 	lui	$v0,%hi(cheatspecs)
/*  f107ebc:	24423a90 */ 	addiu	$v0,$v0,%lo(cheatspecs)
/*  f107ec0:	00001825 */ 	or	$v1,$zero,$zero
/*  f107ec4:	2407002a */ 	addiu	$a3,$zero,0x2a
.L0f107ec8:
/*  f107ec8:	904e0004 */ 	lbu	$t6,0x4($v0)
/*  f107ecc:	548e000d */ 	bnel	$a0,$t6,.L0f107f04
/*  f107ed0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107ed4:	904f0005 */ 	lbu	$t7,0x5($v0)
/*  f107ed8:	54af000a */ 	bnel	$a1,$t7,.L0f107f04
/*  f107edc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107ee0:	90460006 */ 	lbu	$a2,0x6($v0)
/*  f107ee4:	30d80004 */ 	andi	$t8,$a2,0x4
/*  f107ee8:	17000005 */ 	bnez	$t8,.L0f107f00
/*  f107eec:	30d90008 */ 	andi	$t9,$a2,0x8
/*  f107ef0:	57200004 */ 	bnezl	$t9,.L0f107f04
/*  f107ef4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107ef8:	03e00008 */ 	jr	$ra
/*  f107efc:	00601025 */ 	or	$v0,$v1,$zero
.L0f107f00:
/*  f107f00:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f107f04:
/*  f107f04:	1467fff0 */ 	bne	$v1,$a3,.L0f107ec8
/*  f107f08:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f107f0c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f107f10:	03e00008 */ 	jr	$ra
/*  f107f14:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f107f18
/*  f107f18:	3c028007 */ 	lui	$v0,%hi(cheatspecs)
/*  f107f1c:	24423a90 */ 	addiu	$v0,$v0,%lo(cheatspecs)
/*  f107f20:	00001825 */ 	or	$v1,$zero,$zero
/*  f107f24:	2405002a */ 	addiu	$a1,$zero,0x2a
.L0f107f28:
/*  f107f28:	904e0004 */ 	lbu	$t6,0x4($v0)
/*  f107f2c:	548e0008 */ 	bnel	$a0,$t6,.L0f107f50
/*  f107f30:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107f34:	904f0006 */ 	lbu	$t7,0x6($v0)
/*  f107f38:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f107f3c:	53000004 */ 	beqzl	$t8,.L0f107f50
/*  f107f40:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f107f44:	03e00008 */ 	jr	$ra
/*  f107f48:	00601025 */ 	or	$v0,$v1,$zero
/*  f107f4c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f107f50:
/*  f107f50:	1465fff5 */ 	bne	$v1,$a1,.L0f107f28
/*  f107f54:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f107f58:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f107f5c:	03e00008 */ 	jr	$ra
/*  f107f60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f107f64
/*  f107f64:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f107f68:	3c028007 */ 	lui	$v0,0x8007
/*  f107f6c:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f107f70:	03e00008 */ 	jr	$ra
/*  f107f74:	94423a92 */ 	lhu	$v0,0x3a92($v0)
);

GLOBAL_ASM(
glabel func0f107f78
/*  f107f78:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f107f7c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f107f80:	3c048007 */ 	lui	$a0,0x8007
/*  f107f84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f107f88:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f107f8c:	0fc5b9f1 */ 	jal	textGet
/*  f107f90:	94843a90 */ 	lhu	$a0,0x3a90($a0)
/*  f107f94:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f107f98:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f107f9c:	03e00008 */ 	jr	$ra
/*  f107fa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f107fac:	00000000 */ 	sll	$zero,$zero,0x0
);
