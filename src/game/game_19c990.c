#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_000920.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096750.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b63b0.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/game_114240.h"
#include "game/game_129900.h"
#include "game/game_13e0e0.h"
#include "game/game_150820.h"
#include "game/game_1531a0.h"
#include "game/game_157db0.h"
#include "game/game_19c990.h"
#include "game/game_1a3340.h"
#include "game/lang.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1b9180[] = "%s %d\n";
const char var7f1b9188[] = "%02d\n";
const char var7f1b9190[] = "%03d\n";
const char var7f1b9198[] = "%s %d\n";
const char var7f1b91a0[] = "";
const char var7f1b91a4[] = "%s%s%.2f%%\n";
const char var7f1b91b0[] = "";
const char var7f1b91b4[] = "";
const char var7f1b91b8[] = "%s %d%%\n";
const char var7f1b91c4[] = "%02d:%02d\n";
const char var7f1b91d0[] = "%s";
const char var7f1b91d4[] = "%s";
const char var7f1b91d8[] = "%s %02d:%02d\n";
const char var7f1b91e8[] = "010\n";
const char var7f1b91f0[] = "%03d\n";
const char var7f1b91f8[] = "%s";
const char var7f1b91fc[] = "%s";
const char var7f1b9200[] = "%s";
const char var7f1b9204[] = "%s";
const char var7f1b9208[] = "%s";
const char var7f1b920c[] = "\n";

bool ciIsTourDone(void)
{
	return savefileHasFlag(SAVEFILEFLAG_CI_TOUR_DONE);
}

u8 ciGetFiringRangeScore(s32 weapon_id)
{
	// Data at firingrangescores is a u8 array where each score uses 2 bits
	return (g_SoloSaveFile.firingrangescores[weapon_id >> 2] >> (weapon_id % 4) * 2) & 3;
}

GLOBAL_ASM(
glabel func0f19c9e4
/*  f19c9e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19c9e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19c9ec:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f19c9f0:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19c9f4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f19c9f8:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f19c9fc:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f19ca00:	3c0f800a */ 	lui	$t7,%hi(g_SoloSaveFile)
/*  f19ca04:	0047082a */ 	slt	$at,$v0,$a3
/*  f19ca08:	10200017 */ 	beqz	$at,.L0f19ca68
/*  f19ca0c:	00067083 */ 	sra	$t6,$a2,0x2
/*  f19ca10:	25ef2200 */ 	addiu	$t7,$t7,%lo(g_SoloSaveFile)
/*  f19ca14:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f19ca18:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19ca1c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f19ca20:	908200ac */ 	lbu	$v0,0xac($a0)
/*  f19ca24:	04c10004 */ 	bgez	$a2,.L0f19ca38
/*  f19ca28:	30c30003 */ 	andi	$v1,$a2,0x3
/*  f19ca2c:	10600002 */ 	beqz	$v1,.L0f19ca38
/*  f19ca30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ca34:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f19ca38:
/*  f19ca38:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f19ca3c:	27090001 */ 	addiu	$t1,$t8,0x1
/*  f19ca40:	012a5804 */ 	sllv	$t3,$t2,$t1
/*  f19ca44:	03194004 */ 	sllv	$t0,$t9,$t8
/*  f19ca48:	010b2821 */ 	addu	$a1,$t0,$t3
/*  f19ca4c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f19ca50:	01856823 */ 	subu	$t5,$t4,$a1
/*  f19ca54:	03077004 */ 	sllv	$t6,$a3,$t8
/*  f19ca58:	01c57824 */ 	and	$t7,$t6,$a1
/*  f19ca5c:	004d1024 */ 	and	$v0,$v0,$t5
/*  f19ca60:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f19ca64:	a08200ac */ 	sb	$v0,0xac($a0)
.L0f19ca68:
/*  f19ca68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ca6c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19ca70:	03e00008 */ 	jr	$ra
/*  f19ca74:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 func0f19ca78(u32 weaponnum)
{
	s32 slot = -1;
	s32 i;

	for (i = 0; i <= WEAPON_HORIZONSCANNER; i++) {
		switch (i) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SCOPE:
		case WEAPON_FALCON2_SILENCER:
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
		case WEAPON_PHOENIX:
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
		case WEAPON_CMP150:
		case WEAPON_CYCLONE:
		case WEAPON_CALLISTONTG:
		case WEAPON_RCP120:
		case WEAPON_LAPTOPGUN:
		case WEAPON_DRAGON:
		case WEAPON_K7AVENGER:
		case WEAPON_AR34:
		case WEAPON_SUPERDRAGON:
		case WEAPON_SHOTGUN:
		case WEAPON_SNIPERRIFLE:
		case WEAPON_FARSIGHTXR20:
		case WEAPON_CROSSBOW:
		case WEAPON_TRANQUILIZER:
		case WEAPON_REAPER:
		case WEAPON_DEVASTATOR:
		case WEAPON_ROCKETLAUNCHER:
		case WEAPON_SLAYER:
		case WEAPON_COMBATKNIFE:
		case WEAPON_LASER:
		case WEAPON_GRENADE:
		case WEAPON_TIMEDMINE:
		case WEAPON_PROXIMITYMINE:
		case WEAPON_REMOTEMINE:
			slot++;
		}

		if (i == weaponnum) {
			return slot;
		}
	}

	return -1;
}

GLOBAL_ASM(
glabel func0f19cad4
/*  f19cad4:	28810002 */ 	slti	$at,$a0,0x2
/*  f19cad8:	50200004 */ 	beqzl	$at,.L0f19caec
/*  f19cadc:	28810030 */ 	slti	$at,$a0,0x30
/*  f19cae0:	03e00008 */ 	jr	$ra
/*  f19cae4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19cae8:	28810030 */ 	slti	$at,$a0,0x30
.L0f19caec:
/*  f19caec:	10200010 */ 	beqz	$at,.L0f19cb30
/*  f19caf0:	00001025 */ 	or	$v0,$zero,$zero
/*  f19caf4:	000470c3 */ 	sra	$t6,$a0,0x3
/*  f19caf8:	3c0f800a */ 	lui	$t7,0x800a
/*  f19cafc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f19cb00:	91ef22b5 */ 	lbu	$t7,0x22b5($t7)
/*  f19cb04:	04810004 */ 	bgez	$a0,.L0f19cb18
/*  f19cb08:	30980007 */ 	andi	$t8,$a0,0x7
/*  f19cb0c:	13000002 */ 	beqz	$t8,.L0f19cb18
/*  f19cb10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19cb14:	2718fff8 */ 	addiu	$t8,$t8,-8
.L0f19cb18:
/*  f19cb18:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19cb1c:	03194004 */ 	sllv	$t0,$t9,$t8
/*  f19cb20:	01e81024 */ 	and	$v0,$t7,$t0
/*  f19cb24:	304900ff */ 	andi	$t1,$v0,0xff
/*  f19cb28:	03e00008 */ 	jr	$ra
/*  f19cb2c:	01201025 */ 	or	$v0,$t1,$zero
.L0f19cb30:
/*  f19cb30:	03e00008 */ 	jr	$ra
/*  f19cb34:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19cb38
/*  f19cb38:	28810030 */ 	slti	$at,$a0,0x30
/*  f19cb3c:	1020000e */ 	beqz	$at,.L0f19cb78
/*  f19cb40:	000470c3 */ 	sra	$t6,$a0,0x3
/*  f19cb44:	3c0f800a */ 	lui	$t7,%hi(g_SoloSaveFile)
/*  f19cb48:	25ef2200 */ 	addiu	$t7,$t7,%lo(g_SoloSaveFile)
/*  f19cb4c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f19cb50:	906200b5 */ 	lbu	$v0,0xb5($v1)
/*  f19cb54:	04810004 */ 	bgez	$a0,.L0f19cb68
/*  f19cb58:	30980007 */ 	andi	$t8,$a0,0x7
/*  f19cb5c:	13000002 */ 	beqz	$t8,.L0f19cb68
/*  f19cb60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19cb64:	2718fff8 */ 	addiu	$t8,$t8,-8
.L0f19cb68:
/*  f19cb68:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19cb6c:	03194004 */ 	sllv	$t0,$t9,$t8
/*  f19cb70:	00481025 */ 	or	$v0,$v0,$t0
/*  f19cb74:	a06200b5 */ 	sb	$v0,0xb5($v1)
.L0f19cb78:
/*  f19cb78:	03e00008 */ 	jr	$ra
/*  f19cb7c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel stageIsComplete
/*  f19cb80:	00047080 */ 	sll	$t6,$a0,0x2
/*  f19cb84:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f19cb88:	3c0f800a */ 	lui	$t7,%hi(g_SoloSaveFile)
/*  f19cb8c:	25ef2200 */ 	addiu	$t7,$t7,%lo(g_SoloSaveFile)
/*  f19cb90:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f19cb94:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f19cb98:	94620020 */ 	lhu	$v0,0x20($v1)
/*  f19cb9c:	0002c02b */ 	sltu	$t8,$zero,$v0
/*  f19cba0:	17000008 */ 	bnez	$t8,.L0f19cbc4
/*  f19cba4:	03001025 */ 	or	$v0,$t8,$zero
/*  f19cba8:	94620022 */ 	lhu	$v0,0x22($v1)
/*  f19cbac:	0002c82b */ 	sltu	$t9,$zero,$v0
/*  f19cbb0:	17200004 */ 	bnez	$t9,.L0f19cbc4
/*  f19cbb4:	03201025 */ 	or	$v0,$t9,$zero
/*  f19cbb8:	94620024 */ 	lhu	$v0,0x24($v1)
/*  f19cbbc:	0002402b */ 	sltu	$t0,$zero,$v0
/*  f19cbc0:	01001025 */ 	or	$v0,$t0,$zero
.L0f19cbc4:
/*  f19cbc4:	03e00008 */ 	jr	$ra
/*  f19cbc8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19cbcc
/*  f19cbcc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19cbd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19cbd4:	18800004 */ 	blez	$a0,.L0f19cbe8
/*  f19cbd8:	00802825 */ 	or	$a1,$a0,$zero
/*  f19cbdc:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f19cbe0:	54810004 */ 	bnel	$a0,$at,.L0f19cbf4
/*  f19cbe4:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f19cbe8:
/*  f19cbe8:	10000015 */ 	beqz	$zero,.L0f19cc40
/*  f19cbec:	00001025 */ 	or	$v0,$zero,$zero
/*  f19cbf0:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f19cbf4:
/*  f19cbf4:	14a10007 */ 	bne	$a1,$at,.L0f19cc14
/*  f19cbf8:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f19cbfc:	0fc672e0 */ 	jal	stageIsComplete
/*  f19cc00:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f19cc04:	10400003 */ 	beqz	$v0,.L0f19cc14
/*  f19cc08:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f19cc0c:	1000000c */ 	beqz	$zero,.L0f19cc40
/*  f19cc10:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19cc14:
/*  f19cc14:	24010031 */ 	addiu	$at,$zero,0x31
/*  f19cc18:	14a10007 */ 	bne	$a1,$at,.L0f19cc38
/*  f19cc1c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f19cc20:	0fc672e0 */ 	jal	stageIsComplete
/*  f19cc24:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f19cc28:	10400003 */ 	beqz	$v0,.L0f19cc38
/*  f19cc2c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f19cc30:	10000003 */ 	beqz	$zero,.L0f19cc40
/*  f19cc34:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19cc38:
/*  f19cc38:	0fc672b5 */ 	jal	func0f19cad4
/*  f19cc3c:	00a02025 */ 	or	$a0,$a1,$zero
.L0f19cc40:
/*  f19cc40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19cc44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19cc48:	03e00008 */ 	jr	$ra
/*  f19cc4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19cc50
/*  f19cc50:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19cc54:	28810002 */ 	slti	$at,$a0,0x2
/*  f19cc58:	1420000a */ 	bnez	$at,.L0f19cc84
/*  f19cc5c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19cc60:	28810023 */ 	slti	$at,$a0,0x23
/*  f19cc64:	10200007 */ 	beqz	$at,.L0f19cc84
/*  f19cc68:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f19cc6c:	10810005 */ 	beq	$a0,$at,.L0f19cc84
/*  f19cc70:	24010023 */ 	addiu	$at,$zero,0x23
/*  f19cc74:	10810003 */ 	beq	$a0,$at,.L0f19cc84
/*  f19cc78:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f19cc7c:	54810004 */ 	bnel	$a0,$at,.L0f19cc90
/*  f19cc80:	24010002 */ 	addiu	$at,$zero,0x2
.L0f19cc84:
/*  f19cc84:	1000000a */ 	beqz	$zero,.L0f19ccb0
/*  f19cc88:	00001025 */ 	or	$v0,$zero,$zero
/*  f19cc8c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f19cc90:
/*  f19cc90:	10810003 */ 	beq	$a0,$at,.L0f19cca0
/*  f19cc94:	2401000a */ 	addiu	$at,$zero,0xa
/*  f19cc98:	14810003 */ 	bne	$a0,$at,.L0f19cca8
/*  f19cc9c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19cca0:
/*  f19cca0:	10000003 */ 	beqz	$zero,.L0f19ccb0
/*  f19cca4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19cca8:
/*  f19cca8:	0fc672b5 */ 	jal	func0f19cad4
/*  f19ccac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19ccb0:
/*  f19ccb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ccb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19ccb8:	03e00008 */ 	jr	$ra
/*  f19ccbc:	00000000 */ 	sll	$zero,$zero,0x0
);

u32 func0f19ccc0(u32 weaponnum)
{
	switch (weaponnum) {
	case WEAPON_FALCON2:          return 0;
	case WEAPON_FALCON2_SCOPE:    return 1;
	case WEAPON_FALCON2_SILENCER: return 2;
	case WEAPON_MAGSEC4:          return 3;
	case WEAPON_MAULER:           return 4;
	case WEAPON_PHOENIX:          return 5;
	case WEAPON_DY357MAGNUM:      return 6;
	case WEAPON_DY357LX:          return 7;
	case WEAPON_CMP150:           return 8;
	case WEAPON_CYCLONE:          return 9;
	case WEAPON_CALLISTONTG:      return 10;
	case WEAPON_RCP120:           return 11;
	case WEAPON_LAPTOPGUN:        return 12;
	case WEAPON_DRAGON:           return 13;
	case WEAPON_K7AVENGER:        return 14;
	case WEAPON_AR34:             return 15;
	case WEAPON_SUPERDRAGON:      return 16;
	case WEAPON_SHOTGUN:          return 17;
	case WEAPON_SNIPERRIFLE:      return 18;
	case WEAPON_FARSIGHTXR20:     return 19;
	case WEAPON_CROSSBOW:         return 20;
	case WEAPON_TRANQUILIZER:     return 21;
	case WEAPON_REAPER:           return 22;
	case WEAPON_DEVASTATOR:       return 23;
	case WEAPON_ROCKETLAUNCHER:   return 24;
	case WEAPON_SLAYER:           return 25;
	case WEAPON_COMBATKNIFE:      return 26;
	case WEAPON_LASER:            return 27;
	case WEAPON_GRENADE:          return 28;
	case WEAPON_TIMEDMINE:        return 29;
	case WEAPON_PROXIMITYMINE:    return 30;
	case WEAPON_REMOTEMINE:       return 31;
	}

	return 0;
}

u32 func0f19cdf0(u32 weaponnum)
{
	switch (weaponnum) {
	case WEAPON_FALCON2:          return 1;
	case WEAPON_FALCON2_SCOPE:    return 2;
	case WEAPON_FALCON2_SILENCER: return 3;
	case WEAPON_MAGSEC4:          return 4;
	case WEAPON_MAULER:           return 5;
	case WEAPON_PHOENIX:          return 6;
	case WEAPON_DY357MAGNUM:      return 7;
	case WEAPON_DY357LX:          return 8;
	case WEAPON_CMP150:           return 9;
	case WEAPON_CYCLONE:          return 10;
	case WEAPON_CALLISTONTG:      return 11;
	case WEAPON_RCP120:           return 12;
	case WEAPON_LAPTOPGUN:        return 13;
	case WEAPON_DRAGON:           return 14;
	case WEAPON_K7AVENGER:        return 15;
	case WEAPON_AR34:             return 16;
	case WEAPON_SUPERDRAGON:      return 17;
	case WEAPON_SHOTGUN:          return 18;
	case WEAPON_SNIPERRIFLE:      return 19;
	case WEAPON_FARSIGHTXR20:     return 20;
	case WEAPON_CROSSBOW:         return 21;
	case WEAPON_TRANQUILIZER:     return 22;
	case WEAPON_REAPER:           return 23;
	case WEAPON_DEVASTATOR:       return 24;
	case WEAPON_ROCKETLAUNCHER:   return 25;
	case WEAPON_SLAYER:           return 26;
	case WEAPON_COMBATKNIFE:      return 27;
	case WEAPON_LASER:            return 28;
	case WEAPON_GRENADE:          return 29;
	case WEAPON_TIMEDMINE:        return 31;
	case WEAPON_PROXIMITYMINE:    return 32;
	case WEAPON_REMOTEMINE:       return 33;
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f19cf20
.late_rodata
glabel var7f1b939c
.word 0x7f19cf50
glabel var7f1b93a0
.word 0x7f19cf98
glabel var7f1b93a4
.word 0x7f19d010
glabel var7f1b93a8
.word 0x7f19d070
glabel var7f1b93ac
.word 0x7f19d0e8
glabel var7f1b93b0
.word 0x7f19d148
glabel var7f1b93b4
.word 0x7f19d190
glabel var7f1b93b8
.word 0x7f19d1f0
.text
/*  f19cf20:	248effdc */ 	addiu	$t6,$a0,-36
/*  f19cf24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f19cf28:	2dc10008 */ 	sltiu	$at,$t6,0x8
/*  f19cf2c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f19cf30:	102000c1 */ 	beqz	$at,.L0f19d238
/*  f19cf34:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19cf38:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19cf3c:	3c017f1c */ 	lui	$at,%hi(var7f1b939c)
/*  f19cf40:	002e0821 */ 	addu	$at,$at,$t6
/*  f19cf44:	8c2e939c */ 	lw	$t6,%lo(var7f1b939c)($at)
/*  f19cf48:	01c00008 */ 	jr	$t6
/*  f19cf4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19cf50:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cf54:	00002025 */ 	or	$a0,$zero,$zero
/*  f19cf58:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19cf5c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cf60:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cf64:	504000b6 */ 	beqzl	$v0,.L0f19d240
/*  f19cf68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19cf6c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cf70:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f19cf74:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cf78:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cf7c:	504000b0 */ 	beqzl	$v0,.L0f19d240
/*  f19cf80:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19cf84:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cf88:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f19cf8c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cf90:	100000aa */ 	beqz	$zero,.L0f19d23c
/*  f19cf94:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cf98:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cf9c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f19cfa0:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19cfa4:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cfa8:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cfac:	504000a4 */ 	beqzl	$v0,.L0f19d240
/*  f19cfb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19cfb4:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cfb8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f19cfbc:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cfc0:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cfc4:	5040009e */ 	beqzl	$v0,.L0f19d240
/*  f19cfc8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19cfcc:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cfd0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f19cfd4:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cfd8:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cfdc:	50400098 */ 	beqzl	$v0,.L0f19d240
/*  f19cfe0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19cfe4:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19cfe8:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f19cfec:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19cff0:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19cff4:	50400092 */ 	beqzl	$v0,.L0f19d240
/*  f19cff8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19cffc:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d000:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f19d004:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d008:	1000008c */ 	beqz	$zero,.L0f19d23c
/*  f19d00c:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d010:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d014:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f19d018:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19d01c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d020:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d024:	50400086 */ 	beqzl	$v0,.L0f19d240
/*  f19d028:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d02c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d030:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f19d034:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d038:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d03c:	50400080 */ 	beqzl	$v0,.L0f19d240
/*  f19d040:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d044:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d048:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f19d04c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d050:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d054:	5040007a */ 	beqzl	$v0,.L0f19d240
/*  f19d058:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d05c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d060:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19d064:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d068:	10000074 */ 	beqz	$zero,.L0f19d23c
/*  f19d06c:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d070:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d074:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f19d078:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19d07c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d080:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d084:	5040006e */ 	beqzl	$v0,.L0f19d240
/*  f19d088:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d08c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d090:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f19d094:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d098:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d09c:	50400068 */ 	beqzl	$v0,.L0f19d240
/*  f19d0a0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d0a4:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d0a8:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f19d0ac:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d0b0:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d0b4:	50400062 */ 	beqzl	$v0,.L0f19d240
/*  f19d0b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d0bc:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d0c0:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f19d0c4:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d0c8:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d0cc:	5040005c */ 	beqzl	$v0,.L0f19d240
/*  f19d0d0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d0d4:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d0d8:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f19d0dc:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d0e0:	10000056 */ 	beqz	$zero,.L0f19d23c
/*  f19d0e4:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d0e8:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d0ec:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f19d0f0:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19d0f4:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d0f8:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d0fc:	50400050 */ 	beqzl	$v0,.L0f19d240
/*  f19d100:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d104:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d108:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f19d10c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d110:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d114:	5040004a */ 	beqzl	$v0,.L0f19d240
/*  f19d118:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d11c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d120:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f19d124:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d128:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d12c:	50400044 */ 	beqzl	$v0,.L0f19d240
/*  f19d130:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d134:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d138:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f19d13c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d140:	1000003e */ 	beqz	$zero,.L0f19d23c
/*  f19d144:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d148:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d14c:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f19d150:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19d154:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d158:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d15c:	50400038 */ 	beqzl	$v0,.L0f19d240
/*  f19d160:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d164:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d168:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f19d16c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d170:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d174:	50400032 */ 	beqzl	$v0,.L0f19d240
/*  f19d178:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d17c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d180:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f19d184:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d188:	1000002c */ 	beqz	$zero,.L0f19d23c
/*  f19d18c:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d190:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d194:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f19d198:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19d19c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d1a0:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d1a4:	50400026 */ 	beqzl	$v0,.L0f19d240
/*  f19d1a8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d1ac:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d1b0:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f19d1b4:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d1b8:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d1bc:	50400020 */ 	beqzl	$v0,.L0f19d240
/*  f19d1c0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d1c4:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d1c8:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f19d1cc:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d1d0:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d1d4:	5040001a */ 	beqzl	$v0,.L0f19d240
/*  f19d1d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d1dc:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d1e0:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f19d1e4:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d1e8:	10000014 */ 	beqz	$zero,.L0f19d23c
/*  f19d1ec:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d1f0:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d1f4:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f19d1f8:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f19d1fc:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d200:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d204:	5040000e */ 	beqzl	$v0,.L0f19d240
/*  f19d208:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d20c:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d210:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f19d214:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d218:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f19d21c:	50400008 */ 	beqzl	$v0,.L0f19d240
/*  f19d220:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19d224:	0fc6726c */ 	jal	ciGetFiringRangeScore
/*  f19d228:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f19d22c:	02021026 */ 	xor	$v0,$s0,$v0
/*  f19d230:	10000002 */ 	beqz	$zero,.L0f19d23c
/*  f19d234:	2c420001 */ 	sltiu	$v0,$v0,0x1
.L0f19d238:
/*  f19d238:	00001025 */ 	or	$v0,$zero,$zero
.L0f19d23c:
/*  f19d23c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f19d240:
/*  f19d240:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19d244:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f19d248:	03e00008 */ 	jr	$ra
/*  f19d24c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19d250
/*  f19d250:	3c02800b */ 	lui	$v0,0x800b
/*  f19d254:	03e00008 */ 	jr	$ra
/*  f19d258:	9442d176 */ 	lhu	$v0,-0x2e8a($v0)
);

GLOBAL_ASM(
glabel func0f19d25c
/*  f19d25c:	3c01800b */ 	lui	$at,0x800b
/*  f19d260:	03e00008 */ 	jr	$ra
/*  f19d264:	a424d176 */ 	sh	$a0,-0x2e8a($at)
);

GLOBAL_ASM(
glabel func0f19d268
/*  f19d268:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19d26c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19d270:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19d274:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19d278:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19d27c:	00809825 */ 	or	$s3,$a0,$zero
/*  f19d280:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19d284:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f19d288:	00008025 */ 	or	$s0,$zero,$zero
/*  f19d28c:	24120033 */ 	addiu	$s2,$zero,0x33
.L0f19d290:
/*  f19d290:	0fc67314 */ 	jal	func0f19cc50
/*  f19d294:	02002025 */ 	or	$a0,$s0,$zero
/*  f19d298:	10400002 */ 	beqz	$v0,.L0f19d2a4
/*  f19d29c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d2a0:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f19d2a4:
/*  f19d2a4:	56710004 */ 	bnel	$s3,$s1,.L0f19d2b8
/*  f19d2a8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19d2ac:	10000005 */ 	beqz	$zero,.L0f19d2c4
/*  f19d2b0:	02001025 */ 	or	$v0,$s0,$zero
/*  f19d2b4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19d2b8:
/*  f19d2b8:	1612fff5 */ 	bne	$s0,$s2,.L0f19d290
/*  f19d2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d2c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19d2c4:
/*  f19d2c4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19d2c8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19d2cc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19d2d0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19d2d4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19d2d8:	03e00008 */ 	jr	$ra
/*  f19d2dc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f19d2e0
/*  f19d2e0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19d2e4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19d2e8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19d2ec:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19d2f0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19d2f4:	00008825 */ 	or	$s1,$zero,$zero
/*  f19d2f8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f19d2fc:	24120033 */ 	addiu	$s2,$zero,0x33
.L0f19d300:
/*  f19d300:	0fc67314 */ 	jal	func0f19cc50
/*  f19d304:	02002025 */ 	or	$a0,$s0,$zero
/*  f19d308:	10400002 */ 	beqz	$v0,.L0f19d314
/*  f19d30c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19d310:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f19d314:
/*  f19d314:	1612fffa */ 	bne	$s0,$s2,.L0f19d300
/*  f19d318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d31c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19d320:	02201025 */ 	or	$v0,$s1,$zero
/*  f19d324:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19d328:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19d32c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19d330:	03e00008 */ 	jr	$ra
/*  f19d334:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f19d338
/*  f19d338:	3c0e800b */ 	lui	$t6,%hi(var800ad184)
/*  f19d33c:	8dced184 */ 	lw	$t6,%lo(var800ad184)($t6)
/*  f19d340:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f19d344:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f19d348:	000ec2c0 */ 	sll	$t8,$t6,0xb
/*  f19d34c:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f19d350:	07000028 */ 	bltz	$t8,.L0f19d3f4
/*  f19d354:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f19d358:	24100007 */ 	addiu	$s0,$zero,0x7
/*  f19d35c:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f19d360:	24190020 */ 	addiu	$t9,$zero,0x20
.L0f19d364:
/*  f19d364:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19d368:	02002025 */ 	or	$a0,$s0,$zero
/*  f19d36c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19d370:	24060032 */ 	addiu	$a2,$zero,0x32
/*  f19d374:	0fc00b0a */ 	jal	func0f002c28
/*  f19d378:	24070064 */ 	addiu	$a3,$zero,0x64
/*  f19d37c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19d380:	5611fff8 */ 	bnel	$s0,$s1,.L0f19d364
/*  f19d384:	24190020 */ 	addiu	$t9,$zero,0x20
/*  f19d388:	24080020 */ 	addiu	$t0,$zero,0x20
/*  f19d38c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f19d390:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f19d394:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19d398:	24060019 */ 	addiu	$a2,$zero,0x19
/*  f19d39c:	0fc00b0a */ 	jal	func0f002c28
/*  f19d3a0:	24070064 */ 	addiu	$a3,$zero,0x64
/*  f19d3a4:	3c09800b */ 	lui	$t1,0x800b
/*  f19d3a8:	912ad185 */ 	lbu	$t2,-0x2e7b($t1)
/*  f19d3ac:	3c01800b */ 	lui	$at,0x800b
/*  f19d3b0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19d3b4:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f19d3b8:	a02bd185 */ 	sb	$t3,-0x2e7b($at)
/*  f19d3bc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19d3c0:	44812000 */ 	mtc1	$at,$f4
/*  f19d3c4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19d3c8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19d3cc:	240effff */ 	addiu	$t6,$zero,-1
/*  f19d3d0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f19d3d4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f19d3d8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f19d3dc:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19d3e0:	240505d5 */ 	addiu	$a1,$zero,0x5d5
/*  f19d3e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f19d3e8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19d3ec:	0c004241 */ 	jal	func00010904
/*  f19d3f0:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f19d3f4:
/*  f19d3f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f19d3f8:	0fc127cb */ 	jal	chrSetStageFlag
/*  f19d3fc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19d400:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f19d404:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f19d408:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f19d40c:	03e00008 */ 	jr	$ra
/*  f19d410:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f19d414
/*  f19d414:	3c0e800b */ 	lui	$t6,%hi(var800ad184)
/*  f19d418:	8dced184 */ 	lw	$t6,%lo(var800ad184)($t6)
/*  f19d41c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f19d420:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19d424:	000e7ac0 */ 	sll	$t7,$t6,0xb
/*  f19d428:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f19d42c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f19d430:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f19d434:	17010028 */ 	bne	$t8,$at,.L0f19d4d8
/*  f19d438:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f19d43c:	24100007 */ 	addiu	$s0,$zero,0x7
/*  f19d440:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f19d444:	24190008 */ 	addiu	$t9,$zero,0x8
.L0f19d448:
/*  f19d448:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19d44c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19d450:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19d454:	24060064 */ 	addiu	$a2,$zero,0x64
/*  f19d458:	0fc00b0a */ 	jal	func0f002c28
/*  f19d45c:	24070032 */ 	addiu	$a3,$zero,0x32
/*  f19d460:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19d464:	5611fff8 */ 	bnel	$s0,$s1,.L0f19d448
/*  f19d468:	24190008 */ 	addiu	$t9,$zero,0x8
/*  f19d46c:	24080008 */ 	addiu	$t0,$zero,0x8
/*  f19d470:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f19d474:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f19d478:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19d47c:	24060064 */ 	addiu	$a2,$zero,0x64
/*  f19d480:	0fc00b0a */ 	jal	func0f002c28
/*  f19d484:	24070019 */ 	addiu	$a3,$zero,0x19
/*  f19d488:	3c09800b */ 	lui	$t1,0x800b
/*  f19d48c:	9129d185 */ 	lbu	$t1,-0x2e7b($t1)
/*  f19d490:	3c01800b */ 	lui	$at,0x800b
/*  f19d494:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19d498:	312affef */ 	andi	$t2,$t1,0xffef
/*  f19d49c:	a02ad185 */ 	sb	$t2,-0x2e7b($at)
/*  f19d4a0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19d4a4:	44812000 */ 	mtc1	$at,$f4
/*  f19d4a8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f19d4ac:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19d4b0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19d4b4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19d4b8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f19d4bc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f19d4c0:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19d4c4:	240505d6 */ 	addiu	$a1,$zero,0x5d6
/*  f19d4c8:	00003025 */ 	or	$a2,$zero,$zero
/*  f19d4cc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19d4d0:	0c004241 */ 	jal	func00010904
/*  f19d4d4:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f19d4d8:
/*  f19d4d8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f19d4dc:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f19d4e0:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f19d4e4:	03e00008 */ 	jr	$ra
/*  f19d4e8:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f19d4ec
/*  f19d4ec:	3c018009 */ 	lui	$at,0x8009
/*  f19d4f0:	ac208800 */ 	sw	$zero,-0x7800($at)
/*  f19d4f4:	3c018009 */ 	lui	$at,0x8009
/*  f19d4f8:	a0208808 */ 	sb	$zero,-0x77f8($at)
/*  f19d4fc:	3c018009 */ 	lui	$at,0x8009
/*  f19d500:	a0208804 */ 	sb	$zero,-0x77fc($at)
/*  f19d504:	3c04800b */ 	lui	$a0,%hi(var800acd20)
/*  f19d508:	3c018009 */ 	lui	$at,0x8009
/*  f19d50c:	2484cd20 */ 	addiu	$a0,$a0,%lo(var800acd20)
/*  f19d510:	ac208810 */ 	sw	$zero,-0x77f0($at)
/*  f19d514:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f19d518:	3c02800b */ 	lui	$v0,%hi(var800ad158)
/*  f19d51c:	a0800466 */ 	sb	$zero,0x466($a0)
/*  f19d520:	a0800467 */ 	sb	$zero,0x467($a0)
/*  f19d524:	a0800468 */ 	sb	$zero,0x468($a0)
/*  f19d528:	ac80046c */ 	sw	$zero,0x46c($a0)
/*  f19d52c:	a0800464 */ 	sb	$zero,0x464($a0)
/*  f19d530:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f19d534:	2442d158 */ 	addiu	$v0,$v0,%lo(var800ad158)
/*  f19d538:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
.L0f19d53c:
/*  f19d53c:	906e0010 */ 	lbu	$t6,0x10($v1)
/*  f19d540:	2463003c */ 	addiu	$v1,$v1,0x3c
/*  f19d544:	ac60ffd8 */ 	sw	$zero,-0x28($v1)
/*  f19d548:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f19d54c:	1462fffb */ 	bne	$v1,$v0,.L0f19d53c
/*  f19d550:	a06fffd4 */ 	sb	$t7,-0x2c($v1)
/*  f19d554:	3c018009 */ 	lui	$at,0x8009
/*  f19d558:	03e00008 */ 	jr	$ra
/*  f19d55c:	a020880c */ 	sb	$zero,-0x77f4($at)
);

GLOBAL_ASM(
glabel func0f19d560
/*  f19d560:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19d564:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f19d568:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f19d56c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19d570:	348e000f */ 	ori	$t6,$a0,0xf
/*  f19d574:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f19d578:	0c0048f2 */ 	jal	malloc
/*  f19d57c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19d580:	3c038009 */ 	lui	$v1,%hi(var80088810)
/*  f19d584:	24638810 */ 	addiu	$v1,$v1,%lo(var80088810)
/*  f19d588:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f19d58c:	10400007 */ 	beqz	$v0,.L0f19d5ac
/*  f19d590:	00402025 */ 	or	$a0,$v0,$zero
/*  f19d594:	3c05007f */ 	lui	$a1,0x7f
/*  f19d598:	24a59d20 */ 	addiu	$a1,$a1,-25312
/*  f19d59c:	0c003522 */ 	jal	func0000d488
/*  f19d5a0:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f19d5a4:	10000003 */ 	beqz	$zero,.L0f19d5b4
/*  f19d5a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d5ac:
/*  f19d5ac:	00001025 */ 	or	$v0,$zero,$zero
/*  f19d5b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d5b4:
/*  f19d5b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19d5b8:	03e00008 */ 	jr	$ra
/*  f19d5bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19d5c0
/*  f19d5c0:	04830003 */ 	bgezl	$a0,.L0f19d5d0
/*  f19d5c4:	28810003 */ 	slti	$at,$a0,0x3
/*  f19d5c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f19d5cc:	28810003 */ 	slti	$at,$a0,0x3
.L0f19d5d0:
/*  f19d5d0:	14200002 */ 	bnez	$at,.L0f19d5dc
/*  f19d5d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d5d8:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f19d5dc:
/*  f19d5dc:	3c01800b */ 	lui	$at,0x800b
/*  f19d5e0:	03e00008 */ 	jr	$ra
/*  f19d5e4:	a024d168 */ 	sb	$a0,-0x2e98($at)
);

GLOBAL_ASM(
glabel func0f19d5e8
/*  f19d5e8:	3c02800b */ 	lui	$v0,%hi(var800ad168)
/*  f19d5ec:	03e00008 */ 	jr	$ra
/*  f19d5f0:	9042d168 */ 	lbu	$v0,%lo(var800ad168)($v0)
);

GLOBAL_ASM(
glabel func0f19d5f4
/*  f19d5f4:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f19d5f8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19d5fc:	3c018009 */ 	lui	$at,0x8009
/*  f19d600:	3c048009 */ 	lui	$a0,%hi(var80088814)
/*  f19d604:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f19d608:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f19d60c:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f19d610:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f19d614:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f19d618:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f19d61c:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f19d620:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f19d624:	a020880c */ 	sb	$zero,-0x77f4($at)
/*  f19d628:	94848814 */ 	lhu	$a0,%lo(var80088814)($a0)
/*  f19d62c:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f19d630:	0fc456ac */ 	jal	padUnpack
/*  f19d634:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19d638:	3c12800b */ 	lui	$s2,%hi(var800acd20)
/*  f19d63c:	2652cd20 */ 	addiu	$s2,$s2,%lo(var800acd20)
/*  f19d640:	3c013f80 */ 	lui	$at,0x3f80
/*  f19d644:	44812000 */ 	mtc1	$at,$f4
/*  f19d648:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f19d64c:	3c0140c0 */ 	lui	$at,0x40c0
/*  f19d650:	240e00c8 */ 	addiu	$t6,$zero,0xc8
/*  f19d654:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19d658:	4481b000 */ 	mtc1	$at,$f22
/*  f19d65c:	4480a000 */ 	mtc1	$zero,$f20
/*  f19d660:	a2400000 */ 	sb	$zero,0x0($s2)
/*  f19d664:	a6400002 */ 	sh	$zero,0x2($s2)
/*  f19d668:	a24e0005 */ 	sb	$t6,0x5($s2)
/*  f19d66c:	a2420006 */ 	sb	$v0,0x6($s2)
/*  f19d670:	a2420007 */ 	sb	$v0,0x7($s2)
/*  f19d674:	a2400008 */ 	sb	$zero,0x8($s2)
/*  f19d678:	a2420004 */ 	sb	$v0,0x4($s2)
/*  f19d67c:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19d680:	00008825 */ 	or	$s1,$zero,$zero
/*  f19d684:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f19d688:	24140012 */ 	addiu	$s4,$zero,0x12
/*  f19d68c:	24133bc4 */ 	addiu	$s3,$zero,0x3bc4
/*  f19d690:	e644000c */ 	swc1	$f4,0xc($s2)
.L0f19d694:
/*  f19d694:	44918000 */ 	mtc1	$s1,$f16
/*  f19d698:	920f0010 */ 	lbu	$t7,0x10($s0)
/*  f19d69c:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f19d6a0:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f19d6a4:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f19d6a8:	31f9ff7f */ 	andi	$t9,$t7,0xff7f
/*  f19d6ac:	332900fb */ 	andi	$t1,$t9,0xfb
/*  f19d6b0:	e6060018 */ 	swc1	$f6,0x18($s0)
/*  f19d6b4:	a2190010 */ 	sb	$t9,0x10($s0)
/*  f19d6b8:	4612b102 */ 	mul.s	$f4,$f22,$f18
/*  f19d6bc:	312b00df */ 	andi	$t3,$t1,0xdf
/*  f19d6c0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f19d6c4:	a2090010 */ 	sb	$t1,0x10($s0)
/*  f19d6c8:	a20b0010 */ 	sb	$t3,0x10($s0)
/*  f19d6cc:	316c00f7 */ 	andi	$t4,$t3,0xf7
/*  f19d6d0:	a2000030 */ 	sb	$zero,0x30($s0)
/*  f19d6d4:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f19d6d8:	a2000031 */ 	sb	$zero,0x31($s0)
/*  f19d6dc:	e614002c */ 	swc1	$f20,0x2c($s0)
/*  f19d6e0:	ae130024 */ 	sw	$s3,0x24($s0)
/*  f19d6e4:	e6060020 */ 	swc1	$f6,0x20($s0)
/*  f19d6e8:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f19d6ec:	a20c0010 */ 	sb	$t4,0x10($s0)
/*  f19d6f0:	e6140034 */ 	swc1	$f20,0x34($s0)
/*  f19d6f4:	e6140038 */ 	swc1	$f20,0x38($s0)
/*  f19d6f8:	e614003c */ 	swc1	$f20,0x3c($s0)
/*  f19d6fc:	a2000041 */ 	sb	$zero,0x41($s0)
/*  f19d700:	a2000042 */ 	sb	$zero,0x42($s0)
/*  f19d704:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f19d708:	ae000048 */ 	sw	$zero,0x48($s0)
/*  f19d70c:	a2150044 */ 	sb	$s5,0x44($s0)
/*  f19d710:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f19d714:	00002825 */ 	or	$a1,$zero,$zero
/*  f19d718:	0fc4f903 */ 	jal	func0f13e40c
/*  f19d71c:	e608001c */ 	swc1	$f8,0x1c($s0)
/*  f19d720:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f19d724:	0fc4f903 */ 	jal	func0f13e40c
/*  f19d728:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19d72c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19d730:	1634ffd8 */ 	bne	$s1,$s4,.L0f19d694
/*  f19d734:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19d738:	924e0465 */ 	lbu	$t6,0x465($s2)
/*  f19d73c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19d740:	240dff10 */ 	addiu	$t5,$zero,-240
/*  f19d744:	31d9fff7 */ 	andi	$t9,$t6,0xfff7
/*  f19d748:	a2590465 */ 	sb	$t9,0x465($s2)
/*  f19d74c:	37280004 */ 	ori	$t0,$t9,0x4
/*  f19d750:	a6550476 */ 	sh	$s5,0x476($s2)
/*  f19d754:	ae4d044c */ 	sw	$t5,0x44c($s2)
/*  f19d758:	ae400450 */ 	sw	$zero,0x450($s2)
/*  f19d75c:	a2400454 */ 	sb	$zero,0x454($s2)
/*  f19d760:	a2400455 */ 	sb	$zero,0x455($s2)
/*  f19d764:	a2400464 */ 	sb	$zero,0x464($s2)
/*  f19d768:	a2400470 */ 	sb	$zero,0x470($s2)
/*  f19d76c:	a2400471 */ 	sb	$zero,0x471($s2)
/*  f19d770:	a2400472 */ 	sb	$zero,0x472($s2)
/*  f19d774:	a240045b */ 	sb	$zero,0x45b($s2)
/*  f19d778:	a6400458 */ 	sh	$zero,0x458($s2)
/*  f19d77c:	a6400462 */ 	sh	$zero,0x462($s2)
/*  f19d780:	a6400460 */ 	sh	$zero,0x460($s2)
/*  f19d784:	a640045e */ 	sh	$zero,0x45e($s2)
/*  f19d788:	a640045c */ 	sh	$zero,0x45c($s2)
/*  f19d78c:	a2400466 */ 	sb	$zero,0x466($s2)
/*  f19d790:	a2400467 */ 	sb	$zero,0x467($s2)
/*  f19d794:	a2400468 */ 	sb	$zero,0x468($s2)
/*  f19d798:	ae40046c */ 	sw	$zero,0x46c($s2)
/*  f19d79c:	a6400474 */ 	sh	$zero,0x474($s2)
/*  f19d7a0:	a2480465 */ 	sb	$t0,0x465($s2)
/*  f19d7a4:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f19d7a8:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f19d7ac:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f19d7b0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f19d7b4:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f19d7b8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f19d7bc:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f19d7c0:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f19d7c4:	03e00008 */ 	jr	$ra
/*  f19d7c8:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f19d7cc
/*  f19d7cc:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f19d7d0:	03e00008 */ 	jr	$ra
/*  f19d7d4:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
);

GLOBAL_ASM(
glabel func0f19d7d8
/*  f19d7d8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19d7dc:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f19d7e0:	1081000a */ 	beq	$a0,$at,.L0f19d80c
/*  f19d7e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19d7e8:	24010020 */ 	addiu	$at,$zero,0x20
/*  f19d7ec:	1081000f */ 	beq	$a0,$at,.L0f19d82c
/*  f19d7f0:	24010021 */ 	addiu	$at,$zero,0x21
/*  f19d7f4:	10810015 */ 	beq	$a0,$at,.L0f19d84c
/*  f19d7f8:	24010022 */ 	addiu	$at,$zero,0x22
/*  f19d7fc:	1081001b */ 	beq	$a0,$at,.L0f19d86c
/*  f19d800:	3c08800b */ 	lui	$t0,%hi(var800ad190)
/*  f19d804:	10000021 */ 	beqz	$zero,.L0f19d88c
/*  f19d808:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19d80c:
/*  f19d80c:	0c004b70 */ 	jal	random
/*  f19d810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d814:	24010009 */ 	addiu	$at,$zero,0x9
/*  f19d818:	0041001b */ 	divu	$zero,$v0,$at
/*  f19d81c:	00007010 */ 	mfhi	$t6
/*  f19d820:	25c20004 */ 	addiu	$v0,$t6,0x4
/*  f19d824:	1000001c */ 	beqz	$zero,.L0f19d898
/*  f19d828:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d82c:
/*  f19d82c:	0c004b70 */ 	jal	random
/*  f19d830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d834:	24010009 */ 	addiu	$at,$zero,0x9
/*  f19d838:	0041001b */ 	divu	$zero,$v0,$at
/*  f19d83c:	00007810 */ 	mfhi	$t7
/*  f19d840:	25e2000d */ 	addiu	$v0,$t7,0xd
/*  f19d844:	10000014 */ 	beqz	$zero,.L0f19d898
/*  f19d848:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d84c:
/*  f19d84c:	0c004b70 */ 	jal	random
/*  f19d850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d854:	24010009 */ 	addiu	$at,$zero,0x9
/*  f19d858:	0041001b */ 	divu	$zero,$v0,$at
/*  f19d85c:	0000c010 */ 	mfhi	$t8
/*  f19d860:	27020016 */ 	addiu	$v0,$t8,0x16
/*  f19d864:	1000000c */ 	beqz	$zero,.L0f19d898
/*  f19d868:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d86c:
/*  f19d86c:	0c004b70 */ 	jal	random
/*  f19d870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d874:	2401001b */ 	addiu	$at,$zero,0x1b
/*  f19d878:	0041001b */ 	divu	$zero,$v0,$at
/*  f19d87c:	0000c810 */ 	mfhi	$t9
/*  f19d880:	27220004 */ 	addiu	$v0,$t9,0x4
/*  f19d884:	10000004 */ 	beqz	$zero,.L0f19d898
/*  f19d888:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d88c:
/*  f19d88c:	9108d190 */ 	lbu	$t0,%lo(var800ad190)($t0)
/*  f19d890:	01041021 */ 	addu	$v0,$t0,$a0
/*  f19d894:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19d898:
/*  f19d898:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19d89c:	03e00008 */ 	jr	$ra
/*  f19d8a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19d8a4
/*  f19d8a4:	3c02800b */ 	lui	$v0,%hi(var800ad168)
/*  f19d8a8:	9042d168 */ 	lbu	$v0,%lo(var800ad168)($v0)
/*  f19d8ac:	308e0001 */ 	andi	$t6,$a0,0x1
/*  f19d8b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19d8b4:	14400005 */ 	bnez	$v0,.L0f19d8cc
/*  f19d8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d8bc:	55c00011 */ 	bnezl	$t6,.L0f19d904
/*  f19d8c0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19d8c4:	03e00008 */ 	jr	$ra
/*  f19d8c8:	00001025 */ 	or	$v0,$zero,$zero
.L0f19d8cc:
/*  f19d8cc:	14410005 */ 	bne	$v0,$at,.L0f19d8e4
/*  f19d8d0:	308f0002 */ 	andi	$t7,$a0,0x2
/*  f19d8d4:	55e0000b */ 	bnezl	$t7,.L0f19d904
/*  f19d8d8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19d8dc:	03e00008 */ 	jr	$ra
/*  f19d8e0:	00001025 */ 	or	$v0,$zero,$zero
.L0f19d8e4:
/*  f19d8e4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19d8e8:	14410005 */ 	bne	$v0,$at,.L0f19d900
/*  f19d8ec:	30980004 */ 	andi	$t8,$a0,0x4
/*  f19d8f0:	57000004 */ 	bnezl	$t8,.L0f19d904
/*  f19d8f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19d8f8:	03e00008 */ 	jr	$ra
/*  f19d8fc:	00001025 */ 	or	$v0,$zero,$zero
.L0f19d900:
/*  f19d900:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19d904:
/*  f19d904:	03e00008 */ 	jr	$ra
/*  f19d908:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19d90c
.late_rodata
glabel var7f1b93bc
.word 0x7f19d9d0
glabel var7f1b93c0
.word 0x7f19db00
glabel var7f1b93c4
.word 0x7f19db58
glabel var7f1b93c8
.word 0x7f19db84
glabel var7f1b93cc
.word 0x7f19dbb8
glabel var7f1b93d0
.word 0x7f19dc6c
glabel var7f1b93d4
.word 0x7f19dcc4
glabel var7f1b93d8
.word 0x7f19dce8
glabel var7f1b93dc
.word 0x7f19dd0c
glabel var7f1b93e0
.word 0x7f19dc1c
glabel var7f1b93e4
.word 0x7f19d9b8
glabel var7f1b93e8
.word 0x7f19db24
glabel var7f1b93ec
.word 0x3dcccccd
.text
/*  f19d90c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f19d910:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19d914:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19d918:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19d91c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19d920:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19d924:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19d928:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19d92c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19d930:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19d934:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19d938:	0480012e */ 	bltz	$a0,.L0f19ddf4
/*  f19d93c:	00009025 */ 	or	$s2,$zero,$zero
/*  f19d940:	28810022 */ 	slti	$at,$a0,0x22
/*  f19d944:	1020012b */ 	beqz	$at,.L0f19ddf4
/*  f19d948:	3c0e8009 */ 	lui	$t6,%hi(var80088800)
/*  f19d94c:	8dce8800 */ 	lw	$t6,%lo(var80088800)($t6)
/*  f19d950:	00047840 */ 	sll	$t7,$a0,0x1
/*  f19d954:	3c088009 */ 	lui	$t0,%hi(var80088810)
/*  f19d958:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19d95c:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f19d960:	8d088810 */ 	lw	$t0,%lo(var80088810)($t0)
/*  f19d964:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19d968:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f19d96c:	0328a021 */ 	addu	$s4,$t9,$t0
/*  f19d970:	92890000 */ 	lbu	$t1,0x0($s4)
/*  f19d974:	02808821 */ 	addu	$s1,$s4,$zero
/*  f19d978:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f19d97c:	1121011d */ 	beq	$t1,$at,.L0f19ddf4
/*  f19d980:	312200ff */ 	andi	$v0,$t1,0xff
/*  f19d984:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19d988:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19d98c:	241700ff */ 	addiu	$s7,$zero,0xff
/*  f19d990:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f19d994:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f19d998:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f19d99c:
/*  f19d99c:	10200111 */ 	beqz	$at,.L0f19dde4
/*  f19d9a0:	00025080 */ 	sll	$t2,$v0,0x2
/*  f19d9a4:	3c017f1c */ 	lui	$at,%hi(var7f1b93bc)
/*  f19d9a8:	002a0821 */ 	addu	$at,$at,$t2
/*  f19d9ac:	8c2a93bc */ 	lw	$t2,%lo(var7f1b93bc)($at)
/*  f19d9b0:	01400008 */ 	jr	$t2
/*  f19d9b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19d9b8:	922b0001 */ 	lbu	$t3,0x1($s1)
/*  f19d9bc:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f19d9c0:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f19d9c4:	a20b0470 */ 	sb	$t3,0x470($s0)
/*  f19d9c8:	10000106 */ 	beqz	$zero,.L0f19dde4
/*  f19d9cc:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19d9d0:	0fc67629 */ 	jal	func0f19d8a4
/*  f19d9d4:	92240004 */ 	lbu	$a0,0x4($s1)
/*  f19d9d8:	54400006 */ 	bnezl	$v0,.L0f19d9f4
/*  f19d9dc:	920c0454 */ 	lbu	$t4,0x454($s0)
/*  f19d9e0:	26520005 */ 	addiu	$s2,$s2,0x5
/*  f19d9e4:	26310005 */ 	addiu	$s1,$s1,0x5
/*  f19d9e8:	100000fe */ 	beqz	$zero,.L0f19dde4
/*  f19d9ec:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19d9f0:	920c0454 */ 	lbu	$t4,0x454($s0)
.L0f19d9f4:
/*  f19d9f4:	29810012 */ 	slti	$at,$t4,0x12
/*  f19d9f8:	5020003e */ 	beqzl	$at,.L0f19daf4
/*  f19d9fc:	26520005 */ 	addiu	$s2,$s2,0x5
/*  f19da00:	0fc675f6 */ 	jal	func0f19d7d8
/*  f19da04:	92240001 */ 	lbu	$a0,0x1($s1)
/*  f19da08:	920d0454 */ 	lbu	$t5,0x454($s0)
/*  f19da0c:	30580003 */ 	andi	$t8,$v0,0x3
/*  f19da10:	01b50019 */ 	multu	$t5,$s5
/*  f19da14:	00007012 */ 	mflo	$t6
/*  f19da18:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f19da1c:	90790010 */ 	lbu	$t9,0x10($v1)
/*  f19da20:	3328fffc */ 	andi	$t0,$t9,0xfffc
/*  f19da24:	03084825 */ 	or	$t1,$t8,$t0
/*  f19da28:	a0690010 */ 	sb	$t1,0x10($v1)
/*  f19da2c:	920b0454 */ 	lbu	$t3,0x454($s0)
/*  f19da30:	922a0002 */ 	lbu	$t2,0x2($s1)
/*  f19da34:	01750019 */ 	multu	$t3,$s5
/*  f19da38:	00006012 */ 	mflo	$t4
/*  f19da3c:	020c6821 */ 	addu	$t5,$s0,$t4
/*  f19da40:	a1aa0012 */ 	sb	$t2,0x12($t5)
/*  f19da44:	920f0454 */ 	lbu	$t7,0x454($s0)
/*  f19da48:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f19da4c:	01f50019 */ 	multu	$t7,$s5
/*  f19da50:	0000c812 */ 	mflo	$t9
/*  f19da54:	0219c021 */ 	addu	$t8,$s0,$t9
/*  f19da58:	a30e0011 */ 	sb	$t6,0x11($t8)
/*  f19da5c:	92080454 */ 	lbu	$t0,0x454($s0)
/*  f19da60:	01150019 */ 	multu	$t0,$s5
/*  f19da64:	00004812 */ 	mflo	$t1
/*  f19da68:	02091821 */ 	addu	$v1,$s0,$t1
/*  f19da6c:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f19da70:	358a0080 */ 	ori	$t2,$t4,0x80
/*  f19da74:	a06a0010 */ 	sb	$t2,0x10($v1)
/*  f19da78:	920f0454 */ 	lbu	$t7,0x454($s0)
/*  f19da7c:	922d0004 */ 	lbu	$t5,0x4($s1)
/*  f19da80:	01f50019 */ 	multu	$t7,$s5
/*  f19da84:	0000c812 */ 	mflo	$t9
/*  f19da88:	02197021 */ 	addu	$t6,$s0,$t9
/*  f19da8c:	a1cd0040 */ 	sb	$t5,0x40($t6)
/*  f19da90:	92040454 */ 	lbu	$a0,0x454($s0)
/*  f19da94:	00950019 */ 	multu	$a0,$s5
/*  f19da98:	0000c012 */ 	mflo	$t8
/*  f19da9c:	02181821 */ 	addu	$v1,$s0,$t8
/*  f19daa0:	90650040 */ 	lbu	$a1,0x40($v1)
/*  f19daa4:	30a80008 */ 	andi	$t0,$a1,0x8
/*  f19daa8:	5100000b */ 	beqzl	$t0,.L0f19dad8
/*  f19daac:	30af0020 */ 	andi	$t7,$a1,0x20
/*  f19dab0:	906b0010 */ 	lbu	$t3,0x10($v1)
/*  f19dab4:	356c0004 */ 	ori	$t4,$t3,0x4
/*  f19dab8:	a06c0010 */ 	sb	$t4,0x10($v1)
/*  f19dabc:	92040454 */ 	lbu	$a0,0x454($s0)
/*  f19dac0:	00045100 */ 	sll	$t2,$a0,0x4
/*  f19dac4:	01445023 */ 	subu	$t2,$t2,$a0
/*  f19dac8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f19dacc:	020a1821 */ 	addu	$v1,$s0,$t2
/*  f19dad0:	90650040 */ 	lbu	$a1,0x40($v1)
/*  f19dad4:	30af0020 */ 	andi	$t7,$a1,0x20
.L0f19dad8:
/*  f19dad8:	51e00004 */ 	beqzl	$t7,.L0f19daec
/*  f19dadc:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f19dae0:	a07e0011 */ 	sb	$s8,0x11($v1)
/*  f19dae4:	92040454 */ 	lbu	$a0,0x454($s0)
/*  f19dae8:	24990001 */ 	addiu	$t9,$a0,0x1
.L0f19daec:
/*  f19daec:	a2190454 */ 	sb	$t9,0x454($s0)
/*  f19daf0:	26520005 */ 	addiu	$s2,$s2,0x5
.L0f19daf4:
/*  f19daf4:	26310005 */ 	addiu	$s1,$s1,0x5
/*  f19daf8:	100000ba */ 	beqz	$zero,.L0f19dde4
/*  f19dafc:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db00:	920d0448 */ 	lbu	$t5,0x448($s0)
/*  f19db04:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db08:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f19db0c:	01d4c021 */ 	addu	$t8,$t6,$s4
/*  f19db10:	93080001 */ 	lbu	$t0,0x1($t8)
/*  f19db14:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19db18:	a2080000 */ 	sb	$t0,0x0($s0)
/*  f19db1c:	100000b1 */ 	beqz	$zero,.L0f19dde4
/*  f19db20:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db24:	92090448 */ 	lbu	$t1,0x448($s0)
/*  f19db28:	33d600ff */ 	andi	$s6,$s8,0xff
/*  f19db2c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db30:	01325821 */ 	addu	$t3,$t1,$s2
/*  f19db34:	01746021 */ 	addu	$t4,$t3,$s4
/*  f19db38:	91820001 */ 	lbu	$v0,0x1($t4)
/*  f19db3c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19db40:	18400003 */ 	blez	$v0,.L0f19db50
/*  f19db44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19db48:	10000001 */ 	beqz	$zero,.L0f19db50
/*  f19db4c:	305600ff */ 	andi	$s6,$v0,0xff
.L0f19db50:
/*  f19db50:	100000a4 */ 	beqz	$zero,.L0f19dde4
/*  f19db54:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db58:	920a0448 */ 	lbu	$t2,0x448($s0)
/*  f19db5c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db60:	01527821 */ 	addu	$t7,$t2,$s2
/*  f19db64:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f19db68:	932d0001 */ 	lbu	$t5,0x1($t9)
/*  f19db6c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19db70:	01b60019 */ 	multu	$t5,$s6
/*  f19db74:	00007012 */ 	mflo	$t6
/*  f19db78:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f19db7c:	10000099 */ 	beqz	$zero,.L0f19dde4
/*  f19db80:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db84:	92180448 */ 	lbu	$t8,0x448($s0)
/*  f19db88:	240a0078 */ 	addiu	$t2,$zero,0x78
/*  f19db8c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db90:	03124021 */ 	addu	$t0,$t8,$s2
/*  f19db94:	01144821 */ 	addu	$t1,$t0,$s4
/*  f19db98:	912b0001 */ 	lbu	$t3,0x1($t1)
/*  f19db9c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dba0:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f19dba4:	16ec0002 */ 	bne	$s7,$t4,.L0f19dbb0
/*  f19dba8:	a20b0005 */ 	sb	$t3,0x5($s0)
/*  f19dbac:	a20a0005 */ 	sb	$t2,0x5($s0)
.L0f19dbb0:
/*  f19dbb0:	1000008c */ 	beqz	$zero,.L0f19dde4
/*  f19dbb4:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dbb8:	0fc6749a */ 	jal	func0f19d268
/*  f19dbbc:	96040456 */ 	lhu	$a0,0x456($s0)
/*  f19dbc0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19dbc4:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19dbc8:	00002825 */ 	or	$a1,$zero,$zero
/*  f19dbcc:	0fc2a63d */ 	jal	func0f0a98f4
/*  f19dbd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19dbd4:	920f0448 */ 	lbu	$t7,0x448($s0)
/*  f19dbd8:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dbdc:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f19dbe0:	03346821 */ 	addu	$t5,$t9,$s4
/*  f19dbe4:	91ae0001 */ 	lbu	$t6,0x1($t5)
/*  f19dbe8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dbec:	31c300ff */ 	andi	$v1,$t6,0xff
/*  f19dbf0:	12e30008 */ 	beq	$s7,$v1,.L0f19dc14
/*  f19dbf4:	a20e0006 */ 	sb	$t6,0x6($s0)
/*  f19dbf8:	0043082a */ 	slt	$at,$v0,$v1
/*  f19dbfc:	10200004 */ 	beqz	$at,.L0f19dc10
/*  f19dc00:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f19dc04:	3c01800b */ 	lui	$at,0x800b
/*  f19dc08:	10000002 */ 	beqz	$zero,.L0f19dc14
/*  f19dc0c:	a438d196 */ 	sh	$t8,-0x2e6a($at)
.L0f19dc10:
/*  f19dc10:	a6000476 */ 	sh	$zero,0x476($s0)
.L0f19dc14:
/*  f19dc14:	10000073 */ 	beqz	$zero,.L0f19dde4
/*  f19dc18:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dc1c:	0fc2a63d */ 	jal	func0f0a98f4
/*  f19dc20:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19dc24:	92080448 */ 	lbu	$t0,0x448($s0)
/*  f19dc28:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dc2c:	01124821 */ 	addu	$t1,$t0,$s2
/*  f19dc30:	01345821 */ 	addu	$t3,$t1,$s4
/*  f19dc34:	916c0001 */ 	lbu	$t4,0x1($t3)
/*  f19dc38:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dc3c:	318300ff */ 	andi	$v1,$t4,0xff
/*  f19dc40:	12e30008 */ 	beq	$s7,$v1,.L0f19dc64
/*  f19dc44:	a20c0007 */ 	sb	$t4,0x7($s0)
/*  f19dc48:	0043082a */ 	slt	$at,$v0,$v1
/*  f19dc4c:	10200004 */ 	beqz	$at,.L0f19dc60
/*  f19dc50:	00625023 */ 	subu	$t2,$v1,$v0
/*  f19dc54:	3c01800b */ 	lui	$at,0x800b
/*  f19dc58:	10000002 */ 	beqz	$zero,.L0f19dc64
/*  f19dc5c:	a42ad198 */ 	sh	$t2,-0x2e68($at)
.L0f19dc60:
/*  f19dc60:	a6000478 */ 	sh	$zero,0x478($s0)
.L0f19dc64:
/*  f19dc64:	1000005f */ 	beqz	$zero,.L0f19dde4
/*  f19dc68:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dc6c:	920f0448 */ 	lbu	$t7,0x448($s0)
/*  f19dc70:	3c014f80 */ 	lui	$at,0x4f80
/*  f19dc74:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f19dc78:	03346821 */ 	addu	$t5,$t9,$s4
/*  f19dc7c:	91ae0001 */ 	lbu	$t6,0x1($t5)
/*  f19dc80:	448e2000 */ 	mtc1	$t6,$f4
/*  f19dc84:	05c10004 */ 	bgez	$t6,.L0f19dc98
/*  f19dc88:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19dc8c:	44814000 */ 	mtc1	$at,$f8
/*  f19dc90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19dc94:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f19dc98:
/*  f19dc98:	3c017f1c */ 	lui	$at,%hi(var7f1b93ec)
/*  f19dc9c:	c42a93ec */ 	lwc1	$f10,%lo(var7f1b93ec)($at)
/*  f19dca0:	3c013f80 */ 	lui	$at,0x3f80
/*  f19dca4:	44819000 */ 	mtc1	$at,$f18
/*  f19dca8:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f19dcac:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dcb0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dcb4:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f19dcb8:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f19dcbc:	10000049 */ 	beqz	$zero,.L0f19dde4
/*  f19dcc0:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dcc4:	92180448 */ 	lbu	$t8,0x448($s0)
/*  f19dcc8:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dccc:	03124021 */ 	addu	$t0,$t8,$s2
/*  f19dcd0:	01144821 */ 	addu	$t1,$t0,$s4
/*  f19dcd4:	912b0001 */ 	lbu	$t3,0x1($t1)
/*  f19dcd8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dcdc:	a20b0008 */ 	sb	$t3,0x8($s0)
/*  f19dce0:	10000040 */ 	beqz	$zero,.L0f19dde4
/*  f19dce4:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dce8:	920c0448 */ 	lbu	$t4,0x448($s0)
/*  f19dcec:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dcf0:	01925021 */ 	addu	$t2,$t4,$s2
/*  f19dcf4:	01547821 */ 	addu	$t7,$t2,$s4
/*  f19dcf8:	91f90001 */ 	lbu	$t9,0x1($t7)
/*  f19dcfc:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dd00:	a2190004 */ 	sb	$t9,0x4($s0)
/*  f19dd04:	10000037 */ 	beqz	$zero,.L0f19dde4
/*  f19dd08:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dd0c:	922d0001 */ 	lbu	$t5,0x1($s1)
/*  f19dd10:	a21e0468 */ 	sb	$s8,0x468($s0)
/*  f19dd14:	3c0e8009 */ 	lui	$t6,%hi(var80088800)
/*  f19dd18:	a20d0466 */ 	sb	$t5,0x466($s0)
/*  f19dd1c:	8dce8800 */ 	lw	$t6,%lo(var80088800)($t6)
/*  f19dd20:	31a300ff */ 	andi	$v1,$t5,0xff
/*  f19dd24:	24630071 */ 	addiu	$v1,$v1,0x71
/*  f19dd28:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f19dd2c:	92020448 */ 	lbu	$v0,0x448($s0)
/*  f19dd30:	3c0b8009 */ 	lui	$t3,%hi(var80088810)
/*  f19dd34:	01d84021 */ 	addu	$t0,$t6,$t8
/*  f19dd38:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f19dd3c:	8d6b8810 */ 	lw	$t3,%lo(var80088810)($t3)
/*  f19dd40:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f19dd44:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f19dd48:	14400003 */ 	bnez	$v0,.L0f19dd58
/*  f19dd4c:	012b2821 */ 	addu	$a1,$t1,$t3
/*  f19dd50:	1000000a */ 	beqz	$zero,.L0f19dd7c
/*  f19dd54:	241300fb */ 	addiu	$s3,$zero,0xfb
.L0f19dd58:
/*  f19dd58:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19dd5c:	54410004 */ 	bnel	$v0,$at,.L0f19dd70
/*  f19dd60:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19dd64:	10000005 */ 	beqz	$zero,.L0f19dd7c
/*  f19dd68:	241300fc */ 	addiu	$s3,$zero,0xfc
/*  f19dd6c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f19dd70:
/*  f19dd70:	54410003 */ 	bnel	$v0,$at,.L0f19dd80
/*  f19dd74:	a2000467 */ 	sb	$zero,0x467($s0)
/*  f19dd78:	241300fd */ 	addiu	$s3,$zero,0xfd
.L0f19dd7c:
/*  f19dd7c:	a2000467 */ 	sb	$zero,0x467($s0)
.L0f19dd80:
/*  f19dd80:	00a01025 */ 	or	$v0,$a1,$zero
.L0f19dd84:
/*  f19dd84:	920c0467 */ 	lbu	$t4,0x467($s0)
/*  f19dd88:	258a0001 */ 	addiu	$t2,$t4,0x1
/*  f19dd8c:	a20a0467 */ 	sb	$t2,0x467($s0)
/*  f19dd90:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f19dd94:	166f0011 */ 	bne	$s3,$t7,.L0f19dddc
/*  f19dd98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19dd9c:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f19dda0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19dda4:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f19dda8:	286100fb */ 	slti	$at,$v1,0xfb
/*  f19ddac:	54200004 */ 	bnezl	$at,.L0f19ddc0
/*  f19ddb0:	286100fb */ 	slti	$at,$v1,0xfb
/*  f19ddb4:	a20d0467 */ 	sb	$t5,0x467($s0)
/*  f19ddb8:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f19ddbc:	286100fb */ 	slti	$at,$v1,0xfb
.L0f19ddc0:
/*  f19ddc0:	14200004 */ 	bnez	$at,.L0f19ddd4
/*  f19ddc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ddc8:	920e0467 */ 	lbu	$t6,0x467($s0)
/*  f19ddcc:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f19ddd0:	a2180467 */ 	sb	$t8,0x467($s0)
.L0f19ddd4:
/*  f19ddd4:	10000003 */ 	beqz	$zero,.L0f19dde4
/*  f19ddd8:	92220000 */ 	lbu	$v0,0x0($s1)
.L0f19dddc:
/*  f19dddc:	1000ffe9 */ 	beqz	$zero,.L0f19dd84
/*  f19dde0:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f19dde4:
/*  f19dde4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19dde8:	5441feec */ 	bnel	$v0,$at,.L0f19d99c
/*  f19ddec:	2c41000c */ 	sltiu	$at,$v0,0xc
/*  f19ddf0:	afb30044 */ 	sw	$s3,0x44($sp)
.L0f19ddf4:
/*  f19ddf4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19ddf8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19ddfc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19de00:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19de04:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19de08:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19de0c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19de10:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19de14:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19de18:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19de1c:	03e00008 */ 	jr	$ra
/*  f19de20:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f19de24
/*  f19de24:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f19de28:	3c0f8009 */ 	lui	$t7,%hi(var80088854)
/*  f19de2c:	25ef8854 */ 	addiu	$t7,$t7,%lo(var80088854)
/*  f19de30:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f19de34:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f19de38:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f19de3c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19de40:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19de44:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19de48:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19de4c:	25e80048 */ 	addiu	$t0,$t7,0x48
/*  f19de50:	27ae003c */ 	addiu	$t6,$sp,0x3c
.L0f19de54:
/*  f19de54:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19de58:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f19de5c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f19de60:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f19de64:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f19de68:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f19de6c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f19de70:	15e8fff8 */ 	bne	$t7,$t0,.L0f19de54
/*  f19de74:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f19de78:	3c12800b */ 	lui	$s2,%hi(var800acd20)
/*  f19de7c:	2652cd20 */ 	addiu	$s2,$s2,%lo(var800acd20)
/*  f19de80:	00008025 */ 	or	$s0,$zero,$zero
/*  f19de84:	27b1003c */ 	addiu	$s1,$sp,0x3c
/*  f19de88:	24150012 */ 	addiu	$s5,$zero,0x12
/*  f19de8c:	3c140008 */ 	lui	$s4,0x8
/*  f19de90:	2413003c */ 	addiu	$s3,$zero,0x3c
.L0f19de94:
/*  f19de94:	0fc2556c */ 	jal	objFindByTagId
/*  f19de98:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f19de9c:	5040000a */ 	beqzl	$v0,.L0f19dec8
/*  f19dea0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19dea4:	02130019 */ 	multu	$s0,$s3
/*  f19dea8:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f19deac:	00005012 */ 	mflo	$t2
/*  f19deb0:	024a5821 */ 	addu	$t3,$s2,$t2
/*  f19deb4:	ad690014 */ 	sw	$t1,0x14($t3)
/*  f19deb8:	8c4c000c */ 	lw	$t4,0xc($v0)
/*  f19debc:	01946825 */ 	or	$t5,$t4,$s4
/*  f19dec0:	ac4d000c */ 	sw	$t5,0xc($v0)
/*  f19dec4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19dec8:
/*  f19dec8:	1615fff2 */ 	bne	$s0,$s5,.L0f19de94
/*  f19decc:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19ded0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f19ded4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19ded8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19dedc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19dee0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19dee4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f19dee8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f19deec:	03e00008 */ 	jr	$ra
/*  f19def0:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel func0f19def4
/*  f19def4:	00047100 */ 	sll	$t6,$a0,0x4
/*  f19def8:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f19defc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19df00:	3c02800b */ 	lui	$v0,0x800b
/*  f19df04:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f19df08:	9042cd51 */ 	lbu	$v0,-0x32af($v0)
/*  f19df0c:	2c4f0001 */ 	sltiu	$t7,$v0,0x1
/*  f19df10:	03e00008 */ 	jr	$ra
/*  f19df14:	01e01025 */ 	or	$v0,$t7,$zero
);

GLOBAL_ASM(
glabel func0f19df18
/*  f19df18:	3c0f8009 */ 	lui	$t7,%hi(var80088810)
/*  f19df1c:	8def8810 */ 	lw	$t7,%lo(var80088810)($t7)
/*  f19df20:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19df24:	00047040 */ 	sll	$t6,$a0,0x1
/*  f19df28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19df2c:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f19df30:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f19df34:	90580001 */ 	lbu	$t8,0x1($v0)
/*  f19df38:	00194a00 */ 	sll	$t1,$t9,0x8
/*  f19df3c:	03091825 */ 	or	$v1,$t8,$t1
/*  f19df40:	0fc5b9f1 */ 	jal	langGet
/*  f19df44:	3064ffff */ 	andi	$a0,$v1,0xffff
/*  f19df48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19df4c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19df50:	03e00008 */ 	jr	$ra
/*  f19df54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19df58
/*  f19df58:	3c07800b */ 	lui	$a3,%hi(var800acd20)
/*  f19df5c:	24e7cd20 */ 	addiu	$a3,$a3,%lo(var800acd20)
/*  f19df60:	90ee0468 */ 	lbu	$t6,0x468($a3)
/*  f19df64:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19df68:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19df6c:	11c00044 */ 	beqz	$t6,.L0f19e080
/*  f19df70:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f19df74:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f19df78:	8c6f0034 */ 	lw	$t7,0x34($v1)
/*  f19df7c:	51e00041 */ 	beqzl	$t7,.L0f19e084
/*  f19df80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19df84:	8ce2046c */ 	lw	$v0,0x46c($a3)
/*  f19df88:	3c188009 */ 	lui	$t8,%hi(var80088800)
/*  f19df8c:	3c0b8009 */ 	lui	$t3,%hi(var80088810)
/*  f19df90:	54400037 */ 	bnezl	$v0,.L0f19e070
/*  f19df94:	8c6a0038 */ 	lw	$t2,0x38($v1)
/*  f19df98:	90e30466 */ 	lbu	$v1,0x466($a3)
/*  f19df9c:	8f188800 */ 	lw	$t8,%lo(var80088800)($t8)
/*  f19dfa0:	8d6b8810 */ 	lw	$t3,%lo(var80088810)($t3)
/*  f19dfa4:	24630071 */ 	addiu	$v1,$v1,0x71
/*  f19dfa8:	0003c840 */ 	sll	$t9,$v1,0x1
/*  f19dfac:	03194821 */ 	addu	$t1,$t8,$t9
/*  f19dfb0:	952a0000 */ 	lhu	$t2,0x0($t1)
/*  f19dfb4:	90e80467 */ 	lbu	$t0,0x467($a3)
/*  f19dfb8:	24010010 */ 	addiu	$at,$zero,0x10
/*  f19dfbc:	014b2021 */ 	addu	$a0,$t2,$t3
/*  f19dfc0:	00883021 */ 	addu	$a2,$a0,$t0
/*  f19dfc4:	90c20000 */ 	lbu	$v0,0x0($a2)
/*  f19dfc8:	1041000f */ 	beq	$v0,$at,.L0f19e008
/*  f19dfcc:	24010011 */ 	addiu	$at,$zero,0x11
/*  f19dfd0:	10410020 */ 	beq	$v0,$at,.L0f19e054
/*  f19dfd4:	24010012 */ 	addiu	$at,$zero,0x12
/*  f19dfd8:	10410016 */ 	beq	$v0,$at,.L0f19e034
/*  f19dfdc:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19dfe0:	10410007 */ 	beq	$v0,$at,.L0f19e000
/*  f19dfe4:	240100fb */ 	addiu	$at,$zero,0xfb
/*  f19dfe8:	10410005 */ 	beq	$v0,$at,.L0f19e000
/*  f19dfec:	240100fc */ 	addiu	$at,$zero,0xfc
/*  f19dff0:	10410003 */ 	beq	$v0,$at,.L0f19e000
/*  f19dff4:	240100fd */ 	addiu	$at,$zero,0xfd
/*  f19dff8:	54410022 */ 	bnel	$v0,$at,.L0f19e084
/*  f19dffc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19e000:
/*  f19e000:	1000001f */ 	beqz	$zero,.L0f19e080
/*  f19e004:	a0e00468 */ 	sb	$zero,0x468($a3)
.L0f19e008:
/*  f19e008:	0fc677c6 */ 	jal	func0f19df18
/*  f19e00c:	90c40001 */ 	lbu	$a0,0x1($a2)
/*  f19e010:	00402025 */ 	or	$a0,$v0,$zero
/*  f19e014:	0fc377c7 */ 	jal	currentPlayerQueueMessage
/*  f19e018:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f19e01c:	3c07800b */ 	lui	$a3,%hi(var800acd20)
/*  f19e020:	24e7cd20 */ 	addiu	$a3,$a3,%lo(var800acd20)
/*  f19e024:	90ec0467 */ 	lbu	$t4,0x467($a3)
/*  f19e028:	258d0002 */ 	addiu	$t5,$t4,0x2
/*  f19e02c:	10000014 */ 	beqz	$zero,.L0f19e080
/*  f19e030:	a0ed0467 */ 	sb	$t5,0x467($a3)
.L0f19e034:
/*  f19e034:	90ce0001 */ 	lbu	$t6,0x1($a2)
/*  f19e038:	25180002 */ 	addiu	$t8,$t0,0x2
/*  f19e03c:	a0f80467 */ 	sb	$t8,0x467($a3)
/*  f19e040:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f19e044:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f19e048:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f19e04c:	1000000c */ 	beqz	$zero,.L0f19e080
/*  f19e050:	acef046c */ 	sw	$t7,0x46c($a3)
.L0f19e054:
/*  f19e054:	94f90458 */ 	lhu	$t9,0x458($a3)
/*  f19e058:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f19e05c:	53200009 */ 	beqzl	$t9,.L0f19e084
/*  f19e060:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e064:	10000006 */ 	beqz	$zero,.L0f19e080
/*  f19e068:	a0e90467 */ 	sb	$t1,0x467($a3)
/*  f19e06c:	8c6a0038 */ 	lw	$t2,0x38($v1)
.L0f19e070:
/*  f19e070:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f19e074:	1d600002 */ 	bgtz	$t3,.L0f19e080
/*  f19e078:	aceb046c */ 	sw	$t3,0x46c($a3)
/*  f19e07c:	ace0046c */ 	sw	$zero,0x46c($a3)
.L0f19e080:
/*  f19e080:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19e084:
/*  f19e084:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19e088:	03e00008 */ 	jr	$ra
/*  f19e08c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19e090
.late_rodata
glabel var7f1b93f0
.word 0x7f19e138
glabel var7f1b93f4
.word 0x7f19e2e4
glabel var7f1b93f8
.word 0x7f19e2f0
glabel var7f1b93fc
.word 0x7f19e320
glabel var7f1b9400
.word 0x7f19e3cc
glabel var7f1b9404
.word 0x7f19e3cc
glabel var7f1b9408
.word 0x7f19e3cc
glabel var7f1b940c
.word 0x7f19e11c
glabel var7f1b9410
.word 0xbfc90fdb
glabel var7f1b9414
.word 0xc0490fdb
glabel var7f1b9418
.word 0x3fc90fdb
glabel var7f1b941c
.word 0x40490fdb
.text
/*  f19e090:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f19e094:	00890019 */ 	multu	$a0,$t1
/*  f19e098:	3c18800b */ 	lui	$t8,%hi(var800acd20)
/*  f19e09c:	2718cd20 */ 	addiu	$t8,$t8,%lo(var800acd20)
/*  f19e0a0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f19e0a4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f19e0a8:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f19e0ac:	3c0a8009 */ 	lui	$t2,%hi(var80088800)
/*  f19e0b0:	3c0e8009 */ 	lui	$t6,%hi(var80088810)
/*  f19e0b4:	00007812 */ 	mflo	$t7
/*  f19e0b8:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f19e0bc:	8c670010 */ 	lw	$a3,0x10($v1)
/*  f19e0c0:	0007cfc2 */ 	srl	$t9,$a3,0x1f
/*  f19e0c4:	532000c2 */ 	beqzl	$t9,.L0f19e3d0
/*  f19e0c8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e0cc:	90620012 */ 	lbu	$v0,0x12($v1)
/*  f19e0d0:	8d4a8800 */ 	lw	$t2,%lo(var80088800)($t2)
/*  f19e0d4:	8dce8810 */ 	lw	$t6,%lo(var80088810)($t6)
/*  f19e0d8:	24420022 */ 	addiu	$v0,$v0,0x22
/*  f19e0dc:	00025840 */ 	sll	$t3,$v0,0x1
/*  f19e0e0:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f19e0e4:	958d0000 */ 	lhu	$t5,0x0($t4)
/*  f19e0e8:	90660031 */ 	lbu	$a2,0x31($v1)
/*  f19e0ec:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f19e0f0:	00864021 */ 	addu	$t0,$a0,$a2
/*  f19e0f4:	910f0000 */ 	lbu	$t7,0x0($t0)
/*  f19e0f8:	25f8fff4 */ 	addiu	$t8,$t7,-12
/*  f19e0fc:	2f010008 */ 	sltiu	$at,$t8,0x8
/*  f19e100:	102000b2 */ 	beqz	$at,.L0f19e3cc
/*  f19e104:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f19e108:	3c017f1c */ 	lui	$at,%hi(var7f1b93f0)
/*  f19e10c:	00380821 */ 	addu	$at,$at,$t8
/*  f19e110:	8c3893f0 */ 	lw	$t8,%lo(var7f1b93f0)($at)
/*  f19e114:	03000008 */ 	jr	$t8
/*  f19e118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e11c:	906a0010 */ 	lbu	$t2,0x10($v1)
/*  f19e120:	240c3bc4 */ 	addiu	$t4,$zero,0x3bc4
/*  f19e124:	ac6c0024 */ 	sw	$t4,0x24($v1)
/*  f19e128:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f19e12c:	a06b0010 */ 	sb	$t3,0x10($v1)
/*  f19e130:	100000a7 */ 	beqz	$zero,.L0f19e3d0
/*  f19e134:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e138:	91040001 */ 	lbu	$a0,0x1($t0)
/*  f19e13c:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f19e140:	0fc675f6 */ 	jal	func0f19d7d8
/*  f19e144:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f19e148:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f19e14c:	00403825 */ 	or	$a3,$v0,$zero
/*  f19e150:	0007c040 */ 	sll	$t8,$a3,0x1
/*  f19e154:	806d0044 */ 	lb	$t5,0x44($v1)
/*  f19e158:	3c048009 */ 	lui	$a0,%hi(var80088814)
/*  f19e15c:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19e160:	144d0006 */ 	bne	$v0,$t5,.L0f19e17c
/*  f19e164:	00982021 */ 	addu	$a0,$a0,$t8
/*  f19e168:	906e0031 */ 	lbu	$t6,0x31($v1)
/*  f19e16c:	00001025 */ 	or	$v0,$zero,$zero
/*  f19e170:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*  f19e174:	10000096 */ 	beqz	$zero,.L0f19e3d0
/*  f19e178:	a06f0031 */ 	sb	$t7,0x31($v1)
.L0f19e17c:
/*  f19e17c:	a0670044 */ 	sb	$a3,0x44($v1)
/*  f19e180:	94848814 */ 	lhu	$a0,%lo(var80088814)($a0)
/*  f19e184:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19e188:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f19e18c:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f19e190:	0fc456ac */ 	jal	padUnpack
/*  f19e194:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f19e198:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f19e19c:	3c0140c0 */ 	lui	$at,0x40c0
/*  f19e1a0:	44814000 */ 	mtc1	$at,$f8
/*  f19e1a4:	44995000 */ 	mtc1	$t9,$f10
/*  f19e1a8:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f19e1ac:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f19e1b0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f19e1b4:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f19e1b8:	e4640018 */ 	swc1	$f4,0x18($v1)
/*  f19e1bc:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f19e1c0:	e466001c */ 	swc1	$f6,0x1c($v1)
/*  f19e1c4:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19e1c8:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f19e1cc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f19e1d0:	3c098009 */ 	lui	$t1,%hi(var8008880c)
/*  f19e1d4:	2529880c */ 	addiu	$t1,$t1,%lo(var8008880c)
/*  f19e1d8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f19e1dc:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f19e1e0:	e4660020 */ 	swc1	$f6,0x20($v1)
/*  f19e1e4:	91040002 */ 	lbu	$a0,0x2($t0)
/*  f19e1e8:	14810005 */ 	bne	$a0,$at,.L0f19e200
/*  f19e1ec:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19e1f0:	44810000 */ 	mtc1	$at,$f0
/*  f19e1f4:	a06a0043 */ 	sb	$t2,0x43($v1)
/*  f19e1f8:	1000002f */ 	beqz	$zero,.L0f19e2b8
/*  f19e1fc:	e460002c */ 	swc1	$f0,0x2c($v1)
.L0f19e200:
/*  f19e200:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f19e204:	240605d9 */ 	addiu	$a2,$zero,0x5d9
/*  f19e208:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19e20c:	28410003 */ 	slti	$at,$v0,0x3
/*  f19e210:	10200019 */ 	beqz	$at,.L0f19e278
/*  f19e214:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f19e218:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19e21c:	44810000 */ 	mtc1	$at,$f0
/*  f19e220:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19e224:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19e228:	a12b0000 */ 	sb	$t3,0x0($t1)
/*  f19e22c:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f19e230:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f19e234:	00002025 */ 	or	$a0,$zero,$zero
/*  f19e238:	8c650014 */ 	lw	$a1,0x14($v1)
/*  f19e23c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19e240:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f19e244:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f19e248:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f19e24c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19e250:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f19e254:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f19e258:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f19e25c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19e260:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f19e264:	0fc24e7e */ 	jal	func0f0939f8
/*  f19e268:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f19e26c:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19e270:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f19e274:	91040002 */ 	lbu	$a0,0x2($t0)
.L0f19e278:
/*  f19e278:	44845000 */ 	mtc1	$a0,$f10
/*  f19e27c:	3c014f80 */ 	lui	$at,0x4f80
/*  f19e280:	04810004 */ 	bgez	$a0,.L0f19e294
/*  f19e284:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f19e288:	44818000 */ 	mtc1	$at,$f16
/*  f19e28c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e290:	46104200 */ 	add.s	$f8,$f8,$f16
.L0f19e294:
/*  f19e294:	3c014270 */ 	lui	$at,0x4270
/*  f19e298:	44812000 */ 	mtc1	$at,$f4
/*  f19e29c:	3c01800b */ 	lui	$at,0x800b
/*  f19e2a0:	c426cd2c */ 	lwc1	$f6,-0x32d4($at)
/*  f19e2a4:	46044483 */ 	div.s	$f18,$f8,$f4
/*  f19e2a8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f19e2ac:	a06e0043 */ 	sb	$t6,0x43($v1)
/*  f19e2b0:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f19e2b4:	e46a002c */ 	swc1	$f10,0x2c($v1)
.L0f19e2b8:
/*  f19e2b8:	910f0003 */ 	lbu	$t7,0x3($t0)
/*  f19e2bc:	90790031 */ 	lbu	$t9,0x31($v1)
/*  f19e2c0:	a0600042 */ 	sb	$zero,0x42($v1)
/*  f19e2c4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f19e2c8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f19e2cc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f19e2d0:	272a0004 */ 	addiu	$t2,$t9,0x4
/*  f19e2d4:	ac780024 */ 	sw	$t8,0x24($v1)
/*  f19e2d8:	a06a0031 */ 	sb	$t2,0x31($v1)
/*  f19e2dc:	1000003c */ 	beqz	$zero,.L0f19e3d0
/*  f19e2e0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e2e4:	a0600031 */ 	sb	$zero,0x31($v1)
/*  f19e2e8:	10000039 */ 	beqz	$zero,.L0f19e3d0
/*  f19e2ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e2f0:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f19e2f4:	24d80002 */ 	addiu	$t8,$a2,0x2
/*  f19e2f8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e2fc:	358d0010 */ 	ori	$t5,$t4,0x10
/*  f19e300:	a06d0010 */ 	sb	$t5,0x10($v1)
/*  f19e304:	910e0001 */ 	lbu	$t6,0x1($t0)
/*  f19e308:	a0780031 */ 	sb	$t8,0x31($v1)
/*  f19e30c:	01c90019 */ 	multu	$t6,$t1
/*  f19e310:	00007812 */ 	mflo	$t7
/*  f19e314:	ac6f0024 */ 	sw	$t7,0x24($v1)
/*  f19e318:	1000002e */ 	beqz	$zero,.L0f19e3d4
/*  f19e31c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f19e320:	00075140 */ 	sll	$t2,$a3,0x5
/*  f19e324:	05400025 */ 	bltz	$t2,.L0f19e3bc
/*  f19e328:	3c017f1c */ 	lui	$at,%hi(var7f1b9410)
/*  f19e32c:	c4309410 */ 	lwc1	$f16,%lo(var7f1b9410)($at)
/*  f19e330:	3c017f1c */ 	lui	$at,%hi(var7f1b9414)
/*  f19e334:	c4289414 */ 	lwc1	$f8,%lo(var7f1b9414)($at)
/*  f19e338:	3c017f1c */ 	lui	$at,%hi(var7f1b9418)
/*  f19e33c:	c4249418 */ 	lwc1	$f4,%lo(var7f1b9418)($at)
/*  f19e340:	3c017f1c */ 	lui	$at,%hi(var7f1b941c)
/*  f19e344:	c432941c */ 	lwc1	$f18,%lo(var7f1b941c)($at)
/*  f19e348:	e7b0005c */ 	swc1	$f16,0x5c($sp)
/*  f19e34c:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f19e350:	e7a40064 */ 	swc1	$f4,0x64($sp)
/*  f19e354:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f19e358:	910b0001 */ 	lbu	$t3,0x1($t0)
/*  f19e35c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*  f19e360:	c46a0038 */ 	lwc1	$f10,0x38($v1)
/*  f19e364:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f19e368:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f19e36c:	c5a60000 */ 	lwc1	$f6,0x0($t5)
/*  f19e370:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f19e374:	90660031 */ 	lbu	$a2,0x31($v1)
/*  f19e378:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f19e37c:	e470003c */ 	swc1	$f16,0x3c($v1)
/*  f19e380:	91190002 */ 	lbu	$t9,0x2($t0)
/*  f19e384:	910e0001 */ 	lbu	$t6,0x1($t0)
/*  f19e388:	00195100 */ 	sll	$t2,$t9,0x4
/*  f19e38c:	01595023 */ 	subu	$t2,$t2,$t9
/*  f19e390:	448a2000 */ 	mtc1	$t2,$f4
/*  f19e394:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f19e398:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f19e39c:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f19e3a0:	c7080000 */ 	lwc1	$f8,0x0($t8)
/*  f19e3a4:	358e0008 */ 	ori	$t6,$t4,0x8
/*  f19e3a8:	a06e0010 */ 	sb	$t6,0x10($v1)
/*  f19e3ac:	31cf00ef */ 	andi	$t7,$t6,0xef
/*  f19e3b0:	a06f0010 */ 	sb	$t7,0x10($v1)
/*  f19e3b4:	46124183 */ 	div.s	$f6,$f8,$f18
/*  f19e3b8:	e4660034 */ 	swc1	$f6,0x34($v1)
.L0f19e3bc:
/*  f19e3bc:	24d80003 */ 	addiu	$t8,$a2,0x3
/*  f19e3c0:	a0780031 */ 	sb	$t8,0x31($v1)
/*  f19e3c4:	10000002 */ 	beqz	$zero,.L0f19e3d0
/*  f19e3c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19e3cc:
/*  f19e3cc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19e3d0:
/*  f19e3d0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f19e3d4:
/*  f19e3d4:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f19e3d8:	03e00008 */ 	jr	$ra
/*  f19e3dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19e3e0
/*  f19e3e0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19e3e4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19e3e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19e3ec:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19e3f0:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19e3f4:	3c12800b */ 	lui	$s2,%hi(var800ad158)
/*  f19e3f8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19e3fc:	2652d158 */ 	addiu	$s2,$s2,%lo(var800ad158)
/*  f19e400:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19e404:	3c110008 */ 	lui	$s1,0x8
/*  f19e408:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19e40c:
/*  f19e40c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19e410:	3406ffff */ 	dli	$a2,0xffff
/*  f19e414:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f19e418:	8c4e000c */ 	lw	$t6,0xc($v0)
/*  f19e41c:	01d17825 */ 	or	$t7,$t6,$s1
/*  f19e420:	0fc249af */ 	jal	func0f0926bc
/*  f19e424:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f19e428:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19e42c:	5612fff7 */ 	bnel	$s0,$s2,.L0f19e40c
/*  f19e430:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f19e434:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19e438:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19e43c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19e440:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19e444:	03e00008 */ 	jr	$ra
/*  f19e448:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f19e44c
.late_rodata
glabel var7f1b9420
.word 0x459c4000
glabel var7f1b9424
.word 0x40490fdb
.text
/*  f19e44c:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f19e450:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f19e454:	3c017f1c */ 	lui	$at,%hi(var7f1b9420)
/*  f19e458:	c43c9420 */ 	lwc1	$f28,%lo(var7f1b9420)($at)
/*  f19e45c:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f19e460:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19e464:	4481d000 */ 	mtc1	$at,$f26
/*  f19e468:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f19e46c:	3c017f1c */ 	lui	$at,%hi(var7f1b9424)
/*  f19e470:	c4389424 */ 	lwc1	$f24,%lo(var7f1b9424)($at)
/*  f19e474:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f19e478:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f19e47c:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f19e480:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f19e484:	3c0140c0 */ 	lui	$at,0x40c0
/*  f19e488:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f19e48c:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f19e490:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f19e494:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f19e498:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f19e49c:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19e4a0:	3c1e800b */ 	lui	$s8,%hi(var800acd20)
/*  f19e4a4:	4481a000 */ 	mtc1	$at,$f20
/*  f19e4a8:	4480b000 */ 	mtc1	$zero,$f22
/*  f19e4ac:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f19e4b0:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f19e4b4:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f19e4b8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19e4bc:	27decd20 */ 	addiu	$s8,$s8,%lo(var800acd20)
/*  f19e4c0:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19e4c4:	00009825 */ 	or	$s3,$zero,$zero
/*  f19e4c8:	27b40090 */ 	addiu	$s4,$sp,0x90
/*  f19e4cc:	3c150008 */ 	lui	$s5,0x8
/*  f19e4d0:	27b7006c */ 	addiu	$s7,$sp,0x6c
.L0f19e4d4:
/*  f19e4d4:	8e120014 */ 	lw	$s2,0x14($s0)
/*  f19e4d8:	00002825 */ 	or	$a1,$zero,$zero
/*  f19e4dc:	52400073 */ 	beqzl	$s2,.L0f19e6ac
/*  f19e4e0:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19e4e4:	8e510004 */ 	lw	$s1,0x4($s2)
/*  f19e4e8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19e4ec:	0fc1ab4b */ 	jal	setupParseObject
/*  f19e4f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f19e4f4:	a620004c */ 	sh	$zero,0x4c($s1)
/*  f19e4f8:	a6400002 */ 	sh	$zero,0x2($s2)
/*  f19e4fc:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*  f19e500:	3c048009 */ 	lui	$a0,%hi(var80088814)
/*  f19e504:	000e7fc2 */ 	srl	$t7,$t6,0x1f
/*  f19e508:	51e0003b */ 	beqzl	$t7,.L0f19e5f8
/*  f19e50c:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f19e510:	92180010 */ 	lbu	$t8,0x10($s0)
/*  f19e514:	3308ffef */ 	andi	$t0,$t8,0xffef
/*  f19e518:	a2080010 */ 	sb	$t0,0x10($s0)
/*  f19e51c:	310900df */ 	andi	$t1,$t0,0xdf
/*  f19e520:	a2090010 */ 	sb	$t1,0x10($s0)
/*  f19e524:	93ca0000 */ 	lbu	$t2,0x0($s8)
/*  f19e528:	02ca082a */ 	slt	$at,$s6,$t2
/*  f19e52c:	5020000b */ 	beqzl	$at,.L0f19e55c
/*  f19e530:	8e38000c */ 	lw	$t8,0xc($s1)
/*  f19e534:	8e2b000c */ 	lw	$t3,0xc($s1)
/*  f19e538:	3c01fff7 */ 	lui	$at,0xfff7
/*  f19e53c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f19e540:	01616024 */ 	and	$t4,$t3,$at
/*  f19e544:	ae2c000c */ 	sw	$t4,0xc($s1)
/*  f19e548:	920e0010 */ 	lbu	$t6,0x10($s0)
/*  f19e54c:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f19e550:	10000007 */ 	beqz	$zero,.L0f19e570
/*  f19e554:	a20f0010 */ 	sb	$t7,0x10($s0)
/*  f19e558:	8e38000c */ 	lw	$t8,0xc($s1)
.L0f19e55c:
/*  f19e55c:	0315c825 */ 	or	$t9,$t8,$s5
/*  f19e560:	ae39000c */ 	sw	$t9,0xc($s1)
/*  f19e564:	92080010 */ 	lbu	$t0,0x10($s0)
/*  f19e568:	3109ffbf */ 	andi	$t1,$t0,0xffbf
/*  f19e56c:	a2090010 */ 	sb	$t1,0x10($s0)
.L0f19e570:
/*  f19e570:	920a0010 */ 	lbu	$t2,0x10($s0)
/*  f19e574:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19e578:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f19e57c:	314b0003 */ 	andi	$t3,$t2,0x3
/*  f19e580:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f19e584:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f19e588:	0fc456ac */ 	jal	padUnpack
/*  f19e58c:	94848814 */ 	lhu	$a0,%lo(var80088814)($a0)
/*  f19e590:	44935000 */ 	mtc1	$s3,$f10
/*  f19e594:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f19e598:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f19e59c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f19e5a0:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f19e5a4:	c7a600e0 */ 	lwc1	$f6,0xe0($sp)
/*  f19e5a8:	02602025 */ 	or	$a0,$s3,$zero
/*  f19e5ac:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f19e5b0:	4610a482 */ 	mul.s	$f18,$f20,$f16
/*  f19e5b4:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f19e5b8:	0fc67824 */ 	jal	func0f19e090
/*  f19e5bc:	e7a400d8 */ 	swc1	$f4,0xd8($sp)
/*  f19e5c0:	c606002c */ 	lwc1	$f6,0x2c($s0)
/*  f19e5c4:	4606d032 */ 	c.eq.s	$f26,$f6
/*  f19e5c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e5cc:	45000007 */ 	bc1f	.L0f19e5ec
/*  f19e5d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e5d4:	c60a0018 */ 	lwc1	$f10,0x18($s0)
/*  f19e5d8:	c610001c */ 	lwc1	$f16,0x1c($s0)
/*  f19e5dc:	c6080020 */ 	lwc1	$f8,0x20($s0)
/*  f19e5e0:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f19e5e4:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f19e5e8:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
.L0f19e5ec:
/*  f19e5ec:	10000004 */ 	beqz	$zero,.L0f19e600
/*  f19e5f0:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f19e5f4:	8e2d000c */ 	lw	$t5,0xc($s1)
.L0f19e5f8:
/*  f19e5f8:	01b57025 */ 	or	$t6,$t5,$s5
/*  f19e5fc:	ae2e000c */ 	sw	$t6,0xc($s1)
.L0f19e600:
/*  f19e600:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f19e604:	02802825 */ 	or	$a1,$s4,$zero
/*  f19e608:	01f5c024 */ 	and	$t8,$t7,$s5
/*  f19e60c:	53000008 */ 	beqzl	$t8,.L0f19e630
/*  f19e610:	92190040 */ 	lbu	$t9,0x40($s0)
/*  f19e614:	44939000 */ 	mtc1	$s3,$f18
/*  f19e618:	e7b600d0 */ 	swc1	$f22,0xd0($sp)
/*  f19e61c:	e7bc00d4 */ 	swc1	$f28,0xd4($sp)
/*  f19e620:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f19e624:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f19e628:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f19e62c:	92190040 */ 	lbu	$t9,0x40($s0)
.L0f19e630:
/*  f19e630:	33280010 */ 	andi	$t0,$t9,0x10
/*  f19e634:	11000006 */ 	beqz	$t0,.L0f19e650
/*  f19e638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e63c:	4600b306 */ 	mov.s	$f12,$f22
/*  f19e640:	0c0058dd */ 	jal	func00016374
/*  f19e644:	02802825 */ 	or	$a1,$s4,$zero
/*  f19e648:	10000003 */ 	beqz	$zero,.L0f19e658
/*  f19e64c:	e6180038 */ 	swc1	$f24,0x38($s0)
.L0f19e650:
/*  f19e650:	0c0058dd */ 	jal	func00016374
/*  f19e654:	4600c306 */ 	mov.s	$f12,$f24
.L0f19e658:
/*  f19e658:	8e290018 */ 	lw	$t1,0x18($s1)
/*  f19e65c:	02802825 */ 	or	$a1,$s4,$zero
/*  f19e660:	0c0057c1 */ 	jal	func00015f04
/*  f19e664:	c52c0014 */ 	lwc1	$f12,0x14($t1)
/*  f19e668:	02802025 */ 	or	$a0,$s4,$zero
/*  f19e66c:	0c005768 */ 	jal	func00015da0
/*  f19e670:	02e02825 */ 	or	$a1,$s7,$zero
/*  f19e674:	02e02025 */ 	or	$a0,$s7,$zero
/*  f19e678:	0c005736 */ 	jal	func00015cd8
/*  f19e67c:	2625001c */ 	addiu	$a1,$s1,0x1c
/*  f19e680:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f19e684:	02202025 */ 	or	$a0,$s1,$zero
/*  f19e688:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19e68c:	e64a0008 */ 	swc1	$f10,0x8($s2)
/*  f19e690:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
/*  f19e694:	00003025 */ 	or	$a2,$zero,$zero
/*  f19e698:	e650000c */ 	swc1	$f16,0xc($s2)
/*  f19e69c:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f19e6a0:	0fc1a71c */ 	jal	func0f069c70
/*  f19e6a4:	e6480010 */ 	swc1	$f8,0x10($s2)
/*  f19e6a8:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f19e6ac:
/*  f19e6ac:	24010012 */ 	addiu	$at,$zero,0x12
/*  f19e6b0:	1661ff88 */ 	bne	$s3,$at,.L0f19e4d4
/*  f19e6b4:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19e6b8:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f19e6bc:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f19e6c0:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f19e6c4:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f19e6c8:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f19e6cc:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f19e6d0:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f19e6d4:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f19e6d8:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f19e6dc:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f19e6e0:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f19e6e4:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f19e6e8:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f19e6ec:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f19e6f0:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f19e6f4:	03e00008 */ 	jr	$ra
/*  f19e6f8:	27bd0140 */ 	addiu	$sp,$sp,0x140
);

GLOBAL_ASM(
glabel func0f19e6fc
/*  f19e6fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19e700:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19e704:	0fc2556c */ 	jal	objFindByTagId
/*  f19e708:	24040091 */ 	addiu	$a0,$zero,0x91
/*  f19e70c:	1040000d */ 	beqz	$v0,.L0f19e744
/*  f19e710:	00402025 */ 	or	$a0,$v0,$zero
/*  f19e714:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f19e718:	5060000b */ 	beqzl	$v1,.L0f19e748
/*  f19e71c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e720:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f19e724:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19e728:	55c10007 */ 	bnel	$t6,$at,.L0f19e748
/*  f19e72c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e730:	8c4f0074 */ 	lw	$t7,0x74($v0)
/*  f19e734:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19e738:	35f80040 */ 	ori	$t8,$t7,0x40
/*  f19e73c:	0fc23922 */ 	jal	doorActivate
/*  f19e740:	ac580074 */ 	sw	$t8,0x74($v0)
.L0f19e744:
/*  f19e744:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19e748:
/*  f19e748:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19e74c:	03e00008 */ 	jr	$ra
/*  f19e750:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19e754
/*  f19e754:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19e758:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19e75c:	0fc2556c */ 	jal	objFindByTagId
/*  f19e760:	24040091 */ 	addiu	$a0,$zero,0x91
/*  f19e764:	5040000d */ 	beqzl	$v0,.L0f19e79c
/*  f19e768:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e76c:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f19e770:	5060000a */ 	beqzl	$v1,.L0f19e79c
/*  f19e774:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e778:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f19e77c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19e780:	55c10006 */ 	bnel	$t6,$at,.L0f19e79c
/*  f19e784:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e788:	8c4f0074 */ 	lw	$t7,0x74($v0)
/*  f19e78c:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f19e790:	01e1c024 */ 	and	$t8,$t7,$at
/*  f19e794:	ac580074 */ 	sw	$t8,0x74($v0)
/*  f19e798:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19e79c:
/*  f19e79c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19e7a0:	03e00008 */ 	jr	$ra
/*  f19e7a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19e7a8
/*  f19e7a8:	3c028009 */ 	lui	$v0,%hi(var80088808)
/*  f19e7ac:	24428808 */ 	addiu	$v0,$v0,%lo(var80088808)
/*  f19e7b0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f19e7b4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f19e7b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19e7bc:	15c0004c */ 	bnez	$t6,.L0f19e8f0
/*  f19e7c0:	3c0f007f */ 	lui	$t7,0x7f
/*  f19e7c4:	3c18007f */ 	lui	$t8,0x7f
/*  f19e7c8:	27189d20 */ 	addiu	$t8,$t8,-25312
/*  f19e7cc:	25efb270 */ 	addiu	$t7,$t7,-19856
/*  f19e7d0:	01f82023 */ 	subu	$a0,$t7,$t8
/*  f19e7d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f19e7d8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19e7dc:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f19e7e0:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f19e7e4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f19e7e8:	afa4002c */ 	sw	$a0,0x2c($sp)
/*  f19e7ec:	0fc67558 */ 	jal	func0f19d560
/*  f19e7f0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19e7f4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*  f19e7f8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f19e7fc:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f19e800:	2d410013 */ 	sltiu	$at,$t2,0x13
/*  f19e804:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*  f19e808:	1420000c */ 	bnez	$at,.L0f19e83c
/*  f19e80c:	24030012 */ 	addiu	$v1,$zero,0x12
/*  f19e810:	3c028009 */ 	lui	$v0,%hi(var80088810)
/*  f19e814:	8c428810 */ 	lw	$v0,%lo(var80088810)($v0)
/*  f19e818:	240800fe */ 	addiu	$t0,$zero,0xfe
/*  f19e81c:	24420012 */ 	addiu	$v0,$v0,0x12
.L0f19e820:
/*  f19e820:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f19e824:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19e828:	150b0002 */ 	bne	$t0,$t3,.L0f19e834
/*  f19e82c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e830:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f19e834:
/*  f19e834:	1469fffa */ 	bne	$v1,$t1,.L0f19e820
/*  f19e838:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f19e83c:
/*  f19e83c:	00072040 */ 	sll	$a0,$a3,0x1
/*  f19e840:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f19e844:	348c000f */ 	ori	$t4,$a0,0xf
/*  f19e848:	3984000f */ 	xori	$a0,$t4,0xf
/*  f19e84c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19e850:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f19e854:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f19e858:	0c0048f2 */ 	jal	malloc
/*  f19e85c:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f19e860:	3c048009 */ 	lui	$a0,%hi(var80088800)
/*  f19e864:	24848800 */ 	addiu	$a0,$a0,%lo(var80088800)
/*  f19e868:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f19e86c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f19e870:	240800fe */ 	addiu	$t0,$zero,0xfe
/*  f19e874:	10400015 */ 	beqz	$v0,.L0f19e8cc
/*  f19e878:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*  f19e87c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f19e880:	3c028009 */ 	lui	$v0,%hi(var80088810)
/*  f19e884:	24428810 */ 	addiu	$v0,$v0,%lo(var80088810)
/*  f19e888:	2de10013 */ 	sltiu	$at,$t7,0x13
/*  f19e88c:	1420000f */ 	bnez	$at,.L0f19e8cc
/*  f19e890:	24030012 */ 	addiu	$v1,$zero,0x12
/*  f19e894:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f19e898:
/*  f19e898:	246b0001 */ 	addiu	$t3,$v1,0x1
/*  f19e89c:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f19e8a0:	932a0000 */ 	lbu	$t2,0x0($t9)
/*  f19e8a4:	550a0007 */ 	bnel	$t0,$t2,.L0f19e8c4
/*  f19e8a8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19e8ac:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*  f19e8b0:	00066840 */ 	sll	$t5,$a2,0x1
/*  f19e8b4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f19e8b8:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f19e8bc:	a5cb0000 */ 	sh	$t3,0x0($t6)
/*  f19e8c0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19e8c4:
/*  f19e8c4:	5469fff4 */ 	bnel	$v1,$t1,.L0f19e898
/*  f19e8c8:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f19e8cc:
/*  f19e8cc:	0fc67789 */ 	jal	func0f19de24
/*  f19e8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e8d4:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f19e8d8:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f19e8dc:	904f0465 */ 	lbu	$t7,0x465($v0)
/*  f19e8e0:	a4400456 */ 	sh	$zero,0x456($v0)
/*  f19e8e4:	a0400448 */ 	sb	$zero,0x448($v0)
/*  f19e8e8:	31f8ffef */ 	andi	$t8,$t7,0xffef
/*  f19e8ec:	a0580465 */ 	sb	$t8,0x465($v0)
.L0f19e8f0:
/*  f19e8f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e8f4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f19e8f8:	03e00008 */ 	jr	$ra
/*  f19e8fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19e900
/*  f19e900:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19e904:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19e908:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f19e90c:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19e910:	00002825 */ 	or	$a1,$zero,$zero
/*  f19e914:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f19e918:	0fc2a63d */ 	jal	func0f0a98f4
/*  f19e91c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19e920:	0fc6757d */ 	jal	func0f19d5f4
/*  f19e924:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f19e928:	0fc6737c */ 	jal	func0f19cdf0
/*  f19e92c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f19e930:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f19e934:	0fc67643 */ 	jal	func0f19d90c
/*  f19e938:	00402025 */ 	or	$a0,$v0,$zero
/*  f19e93c:	3c05800b */ 	lui	$a1,0x800b
/*  f19e940:	90a5cd26 */ 	lbu	$a1,-0x32da($a1)
/*  f19e944:	240100ff */ 	addiu	$at,$zero,0xff
/*  f19e948:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f19e94c:	14a10005 */ 	bne	$a1,$at,.L0f19e964
/*  f19e950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e954:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19e958:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f19e95c:	10000004 */ 	beqz	$zero,.L0f19e970
/*  f19e960:	8fae0028 */ 	lw	$t6,0x28($sp)
.L0f19e964:
/*  f19e964:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19e968:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f19e96c:	8fae0028 */ 	lw	$t6,0x28($sp)
.L0f19e970:
/*  f19e970:	24010012 */ 	addiu	$at,$zero,0x12
/*  f19e974:	3c05800b */ 	lui	$a1,0x800b
/*  f19e978:	55c1000d */ 	bnel	$t6,$at,.L0f19e9b0
/*  f19e97c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e980:	90a5cd27 */ 	lbu	$a1,-0x32d9($a1)
/*  f19e984:	240100ff */ 	addiu	$at,$zero,0xff
/*  f19e988:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19e98c:	14a10005 */ 	bne	$a1,$at,.L0f19e9a4
/*  f19e990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e994:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19e998:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f19e99c:	10000004 */ 	beqz	$zero,.L0f19e9b0
/*  f19e9a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19e9a4:
/*  f19e9a4:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19e9a8:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19e9ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19e9b0:
/*  f19e9b0:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f19e9b4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f19e9b8:	03e00008 */ 	jr	$ra
/*  f19e9bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19e9c0
/*  f19e9c0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19e9c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19e9c8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f19e9cc:	0fc2556c */ 	jal	objFindByTagId
/*  f19e9d0:	2404007f */ 	addiu	$a0,$zero,0x7f
/*  f19e9d4:	10400005 */ 	beqz	$v0,.L0f19e9ec
/*  f19e9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e9dc:	8c4e0008 */ 	lw	$t6,0x8($v0)
/*  f19e9e0:	3c010200 */ 	lui	$at,0x200
/*  f19e9e4:	01c17825 */ 	or	$t7,$t6,$at
/*  f19e9e8:	ac4f0008 */ 	sw	$t7,0x8($v0)
.L0f19e9ec:
/*  f19e9ec:	0fc679bf */ 	jal	func0f19e6fc
/*  f19e9f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19e9f4:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f19e9f8:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f19e9fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f19ea00:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19ea04:	8ca40284 */ 	lw	$a0,0x284($a1)
.L0f19ea08:
/*  f19ea08:	00031080 */ 	sll	$v0,$v1,0x2
/*  f19ea0c:	0083c021 */ 	addu	$t8,$a0,$v1
/*  f19ea10:	831915e4 */ 	lb	$t9,0x15e4($t8)
/*  f19ea14:	00824021 */ 	addu	$t0,$a0,$v0
/*  f19ea18:	07220006 */ 	bltzl	$t9,.L0f19ea34
/*  f19ea1c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19ea20:	ad000858 */ 	sw	$zero,0x858($t0)
/*  f19ea24:	8ca90284 */ 	lw	$t1,0x284($a1)
/*  f19ea28:	01225021 */ 	addu	$t2,$t1,$v0
/*  f19ea2c:	ad400ffc */ 	sw	$zero,0xffc($t2)
/*  f19ea30:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19ea34:
/*  f19ea34:	5466fff4 */ 	bnel	$v1,$a2,.L0f19ea08
/*  f19ea38:	8ca40284 */ 	lw	$a0,0x284($a1)
/*  f19ea3c:	0fc67a40 */ 	jal	func0f19e900
/*  f19ea40:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f19ea44:	14400004 */ 	bnez	$v0,.L0f19ea58
/*  f19ea48:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19ea4c:	3c018009 */ 	lui	$at,0x8009
/*  f19ea50:	10000003 */ 	beqz	$zero,.L0f19ea60
/*  f19ea54:	a0208804 */ 	sb	$zero,-0x77fc($at)
.L0f19ea58:
/*  f19ea58:	3c018009 */ 	lui	$at,0x8009
/*  f19ea5c:	a02b8804 */ 	sb	$t3,-0x77fc($at)
.L0f19ea60:
/*  f19ea60:	0fc67913 */ 	jal	func0f19e44c
/*  f19ea64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ea68:	0fc2a4ab */ 	jal	func0f0a92ac
/*  f19ea6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f19ea70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ea74:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19ea78:	03e00008 */ 	jr	$ra
/*  f19ea7c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19ea80
.late_rodata
glabel var7f1b9428
.word 0x7f19eabc
glabel var7f1b942c
.word 0x7f19eadc
glabel var7f1b9430
.word 0x7f19eacc
glabel var7f1b9434
.word 0x7f19eaec
glabel var7f1b9438
.word 0x7f19eafc
glabel var7f1b943c
.word 0x7f19eb0c
glabel var7f1b9440
.word 0x7f19eb1c
glabel var7f1b9444
.word 0x7f19eb2c
glabel var7f1b9448
.word 0x7f19eb3c
glabel var7f1b944c
.word 0x7f19eb4c
glabel var7f1b9450
.word 0x7f19eb5c
glabel var7f1b9454
.word 0x7f19eb6c
glabel var7f1b9458
.word 0x7f19eb7c
glabel var7f1b945c
.word 0x7f19eb8c
glabel var7f1b9460
.word 0x7f19eb9c
glabel var7f1b9464
.word 0x7f19ebac
glabel var7f1b9468
.word 0x7f19ebbc
glabel var7f1b946c
.word 0x7f19ebcc
glabel var7f1b9470
.word 0x7f19ec1c
glabel var7f1b9474
.word 0x7f19ebdc
glabel var7f1b9478
.word 0x7f19ebec
glabel var7f1b947c
.word 0x7f19ec2c
glabel var7f1b9480
.word 0x7f19ec3c
glabel var7f1b9484
.word 0x7f19ec4c
glabel var7f1b9488
.word 0x7f19ec5c
glabel var7f1b948c
.word 0x7f19ebfc
glabel var7f1b9490
.word 0x7f19ec0c
glabel var7f1b9494
.word 0x7f19ec6c
glabel var7f1b9498
.word 0x7f19ec7c
glabel var7f1b949c
.word 0x7f19ec8c
glabel var7f1b94a0
.word 0x7f19ec9c
glabel var7f1b94a4
.word 0x7f19ecac
glabel var7f1b94a8
.word 0x7f19ecbc
.text
/*  f19ea80:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19ea84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19ea88:	3c04800b */ 	lui	$a0,0x800b
/*  f19ea8c:	0fc6749a */ 	jal	func0f19d268
/*  f19ea90:	9484d176 */ 	lhu	$a0,-0x2e8a($a0)
/*  f19ea94:	244efffe */ 	addiu	$t6,$v0,-2
/*  f19ea98:	2dc10021 */ 	sltiu	$at,$t6,0x21
/*  f19ea9c:	1020008b */ 	beqz	$at,.L0f19eccc
/*  f19eaa0:	00001025 */ 	or	$v0,$zero,$zero
/*  f19eaa4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19eaa8:	3c017f1c */ 	lui	$at,%hi(var7f1b9428)
/*  f19eaac:	002e0821 */ 	addu	$at,$at,$t6
/*  f19eab0:	8c2e9428 */ 	lw	$t6,%lo(var7f1b9428)($at)
/*  f19eab4:	01c00008 */ 	jr	$t6
/*  f19eab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19eabc:	0fc5b9f1 */ 	jal	langGet
/*  f19eac0:	24045979 */ 	addiu	$a0,$zero,0x5979
/*  f19eac4:	10000082 */ 	beqz	$zero,.L0f19ecd0
/*  f19eac8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eacc:	0fc5b9f1 */ 	jal	langGet
/*  f19ead0:	2404597a */ 	addiu	$a0,$zero,0x597a
/*  f19ead4:	1000007e */ 	beqz	$zero,.L0f19ecd0
/*  f19ead8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eadc:	0fc5b9f1 */ 	jal	langGet
/*  f19eae0:	2404597b */ 	addiu	$a0,$zero,0x597b
/*  f19eae4:	1000007a */ 	beqz	$zero,.L0f19ecd0
/*  f19eae8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eaec:	0fc5b9f1 */ 	jal	langGet
/*  f19eaf0:	2404597c */ 	addiu	$a0,$zero,0x597c
/*  f19eaf4:	10000076 */ 	beqz	$zero,.L0f19ecd0
/*  f19eaf8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eafc:	0fc5b9f1 */ 	jal	langGet
/*  f19eb00:	2404597d */ 	addiu	$a0,$zero,0x597d
/*  f19eb04:	10000072 */ 	beqz	$zero,.L0f19ecd0
/*  f19eb08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb0c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb10:	2404597e */ 	addiu	$a0,$zero,0x597e
/*  f19eb14:	1000006e */ 	beqz	$zero,.L0f19ecd0
/*  f19eb18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb1c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb20:	2404597f */ 	addiu	$a0,$zero,0x597f
/*  f19eb24:	1000006a */ 	beqz	$zero,.L0f19ecd0
/*  f19eb28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb2c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb30:	24045980 */ 	addiu	$a0,$zero,0x5980
/*  f19eb34:	10000066 */ 	beqz	$zero,.L0f19ecd0
/*  f19eb38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb3c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb40:	24045981 */ 	addiu	$a0,$zero,0x5981
/*  f19eb44:	10000062 */ 	beqz	$zero,.L0f19ecd0
/*  f19eb48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb4c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb50:	24045982 */ 	addiu	$a0,$zero,0x5982
/*  f19eb54:	1000005e */ 	beqz	$zero,.L0f19ecd0
/*  f19eb58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb5c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb60:	24045983 */ 	addiu	$a0,$zero,0x5983
/*  f19eb64:	1000005a */ 	beqz	$zero,.L0f19ecd0
/*  f19eb68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb6c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb70:	24045984 */ 	addiu	$a0,$zero,0x5984
/*  f19eb74:	10000056 */ 	beqz	$zero,.L0f19ecd0
/*  f19eb78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb7c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb80:	24045985 */ 	addiu	$a0,$zero,0x5985
/*  f19eb84:	10000052 */ 	beqz	$zero,.L0f19ecd0
/*  f19eb88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb8c:	0fc5b9f1 */ 	jal	langGet
/*  f19eb90:	24045986 */ 	addiu	$a0,$zero,0x5986
/*  f19eb94:	1000004e */ 	beqz	$zero,.L0f19ecd0
/*  f19eb98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19eb9c:	0fc5b9f1 */ 	jal	langGet
/*  f19eba0:	24045987 */ 	addiu	$a0,$zero,0x5987
/*  f19eba4:	1000004a */ 	beqz	$zero,.L0f19ecd0
/*  f19eba8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ebac:	0fc5b9f1 */ 	jal	langGet
/*  f19ebb0:	24045988 */ 	addiu	$a0,$zero,0x5988
/*  f19ebb4:	10000046 */ 	beqz	$zero,.L0f19ecd0
/*  f19ebb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ebbc:	0fc5b9f1 */ 	jal	langGet
/*  f19ebc0:	24045989 */ 	addiu	$a0,$zero,0x5989
/*  f19ebc4:	10000042 */ 	beqz	$zero,.L0f19ecd0
/*  f19ebc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ebcc:	0fc5b9f1 */ 	jal	langGet
/*  f19ebd0:	2404598a */ 	addiu	$a0,$zero,0x598a
/*  f19ebd4:	1000003e */ 	beqz	$zero,.L0f19ecd0
/*  f19ebd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ebdc:	0fc5b9f1 */ 	jal	langGet
/*  f19ebe0:	2404598b */ 	addiu	$a0,$zero,0x598b
/*  f19ebe4:	1000003a */ 	beqz	$zero,.L0f19ecd0
/*  f19ebe8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ebec:	0fc5b9f1 */ 	jal	langGet
/*  f19ebf0:	2404598c */ 	addiu	$a0,$zero,0x598c
/*  f19ebf4:	10000036 */ 	beqz	$zero,.L0f19ecd0
/*  f19ebf8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ebfc:	0fc5b9f1 */ 	jal	langGet
/*  f19ec00:	2404598d */ 	addiu	$a0,$zero,0x598d
/*  f19ec04:	10000032 */ 	beqz	$zero,.L0f19ecd0
/*  f19ec08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec0c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec10:	2404598e */ 	addiu	$a0,$zero,0x598e
/*  f19ec14:	1000002e */ 	beqz	$zero,.L0f19ecd0
/*  f19ec18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec1c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec20:	2404598f */ 	addiu	$a0,$zero,0x598f
/*  f19ec24:	1000002a */ 	beqz	$zero,.L0f19ecd0
/*  f19ec28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec2c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec30:	24045990 */ 	addiu	$a0,$zero,0x5990
/*  f19ec34:	10000026 */ 	beqz	$zero,.L0f19ecd0
/*  f19ec38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec3c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec40:	24045991 */ 	addiu	$a0,$zero,0x5991
/*  f19ec44:	10000022 */ 	beqz	$zero,.L0f19ecd0
/*  f19ec48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec4c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec50:	24045992 */ 	addiu	$a0,$zero,0x5992
/*  f19ec54:	1000001e */ 	beqz	$zero,.L0f19ecd0
/*  f19ec58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec5c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec60:	24045993 */ 	addiu	$a0,$zero,0x5993
/*  f19ec64:	1000001a */ 	beqz	$zero,.L0f19ecd0
/*  f19ec68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec6c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec70:	24045994 */ 	addiu	$a0,$zero,0x5994
/*  f19ec74:	10000016 */ 	beqz	$zero,.L0f19ecd0
/*  f19ec78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec7c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec80:	24045995 */ 	addiu	$a0,$zero,0x5995
/*  f19ec84:	10000012 */ 	beqz	$zero,.L0f19ecd0
/*  f19ec88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec8c:	0fc5b9f1 */ 	jal	langGet
/*  f19ec90:	24045996 */ 	addiu	$a0,$zero,0x5996
/*  f19ec94:	1000000e */ 	beqz	$zero,.L0f19ecd0
/*  f19ec98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ec9c:	0fc5b9f1 */ 	jal	langGet
/*  f19eca0:	24045997 */ 	addiu	$a0,$zero,0x5997
/*  f19eca4:	1000000a */ 	beqz	$zero,.L0f19ecd0
/*  f19eca8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ecac:	0fc5b9f1 */ 	jal	langGet
/*  f19ecb0:	24045998 */ 	addiu	$a0,$zero,0x5998
/*  f19ecb4:	10000006 */ 	beqz	$zero,.L0f19ecd0
/*  f19ecb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ecbc:	0fc5b9f1 */ 	jal	langGet
/*  f19ecc0:	24045999 */ 	addiu	$a0,$zero,0x5999
/*  f19ecc4:	10000002 */ 	beqz	$zero,.L0f19ecd0
/*  f19ecc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19eccc:
/*  f19eccc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19ecd0:
/*  f19ecd0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19ecd4:	03e00008 */ 	jr	$ra
/*  f19ecd8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19ecdc
/*  f19ecdc:	27bdfd60 */ 	addiu	$sp,$sp,-672
/*  f19ece0:	3c0e8009 */ 	lui	$t6,%hi(var80088808)
/*  f19ece4:	91ce8808 */ 	lbu	$t6,%lo(var80088808)($t6)
/*  f19ece8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19ecec:	00808025 */ 	or	$s0,$a0,$zero
/*  f19ecf0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f19ecf4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19ecf8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19ecfc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19ed00:	11c000cf */ 	beqz	$t6,.L0f19f040
/*  f19ed04:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19ed08:	0fc2556c */ 	jal	objFindByTagId
/*  f19ed0c:	2404007f */ 	addiu	$a0,$zero,0x7f
/*  f19ed10:	10400006 */ 	beqz	$v0,.L0f19ed2c
/*  f19ed14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ed18:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*  f19ed1c:	3c01fdff */ 	lui	$at,0xfdff
/*  f19ed20:	3421ffff */ 	ori	$at,$at,0xffff
/*  f19ed24:	01e1c024 */ 	and	$t8,$t7,$at
/*  f19ed28:	ac580008 */ 	sw	$t8,0x8($v0)
.L0f19ed2c:
/*  f19ed2c:	0fc679d5 */ 	jal	func0f19e754
/*  f19ed30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ed34:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f19ed38:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f19ed3c:	8e820284 */ 	lw	$v0,0x284($s4)
/*  f19ed40:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19ed44:	94590010 */ 	lhu	$t9,0x10($v0)
/*  f19ed48:	17210002 */ 	bne	$t9,$at,.L0f19ed54
/*  f19ed4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ed50:	a4400010 */ 	sh	$zero,0x10($v0)
.L0f19ed54:
/*  f19ed54:	0fc2a4ab */ 	jal	func0f0a92ac
/*  f19ed58:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f19ed5c:	3c018009 */ 	lui	$at,0x8009
/*  f19ed60:	0fc67505 */ 	jal	func0f19d414
/*  f19ed64:	a0208804 */ 	sb	$zero,-0x77fc($at)
/*  f19ed68:	12000003 */ 	beqz	$s0,.L0f19ed78
/*  f19ed6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ed70:	0fc678f8 */ 	jal	func0f19e3e0
/*  f19ed74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19ed78:
/*  f19ed78:	3c048007 */ 	lui	$a0,%hi(var80069968)
/*  f19ed7c:	8c849968 */ 	lw	$a0,%lo(var80069968)($a0)
/*  f19ed80:	8c890014 */ 	lw	$t1,0x14($a0)
/*  f19ed84:	51200004 */ 	beqzl	$t1,.L0f19ed98
/*  f19ed88:	8e8a0284 */ 	lw	$t2,0x284($s4)
/*  f19ed8c:	0fc1acd3 */ 	jal	setupParseObjectWithArg2False
/*  f19ed90:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19ed94:	8e8a0284 */ 	lw	$t2,0x284($s4)
.L0f19ed98:
/*  f19ed98:	27b2006c */ 	addiu	$s2,$sp,0x6c
/*  f19ed9c:	02402825 */ 	or	$a1,$s2,$zero
/*  f19eda0:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f19eda4:	0fc195e9 */ 	jal	roomsCopy
/*  f19eda8:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f19edac:	8e8b0284 */ 	lw	$t3,0x284($s4)
/*  f19edb0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19edb4:	00008825 */ 	or	$s1,$zero,$zero
/*  f19edb8:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f19edbc:	00008025 */ 	or	$s0,$zero,$zero
/*  f19edc0:	844c0028 */ 	lh	$t4,0x28($v0)
/*  f19edc4:	51810014 */ 	beql	$t4,$at,.L0f19ee18
/*  f19edc8:	27b00098 */ 	addiu	$s0,$sp,0x98
/*  f19edcc:	84440028 */ 	lh	$a0,0x28($v0)
/*  f19edd0:	27b10054 */ 	addiu	$s1,$sp,0x54
/*  f19edd4:	02202825 */ 	or	$a1,$s1,$zero
.L0f19edd8:
/*  f19edd8:	0fc5916a */ 	jal	func0f1645a8
/*  f19eddc:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f19ede0:	02202025 */ 	or	$a0,$s1,$zero
/*  f19ede4:	02402825 */ 	or	$a1,$s2,$zero
/*  f19ede8:	0fc195f6 */ 	jal	func0f0657d8
/*  f19edec:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f19edf0:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f19edf4:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f19edf8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19edfc:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f19ee00:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f19ee04:	85e40028 */ 	lh	$a0,0x28($t7)
/*  f19ee08:	5481fff3 */ 	bnel	$a0,$at,.L0f19edd8
/*  f19ee0c:	02202825 */ 	or	$a1,$s1,$zero
/*  f19ee10:	00008825 */ 	or	$s1,$zero,$zero
/*  f19ee14:	27b00098 */ 	addiu	$s0,$sp,0x98
.L0f19ee18:
/*  f19ee18:	02002825 */ 	or	$a1,$s0,$zero
/*  f19ee1c:	02402025 */ 	or	$a0,$s2,$zero
/*  f19ee20:	0fc197e0 */ 	jal	roomGetProps
/*  f19ee24:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f19ee28:	87b80098 */ 	lh	$t8,0x98($sp)
/*  f19ee2c:	02009025 */ 	or	$s2,$s0,$zero
/*  f19ee30:	27b90098 */ 	addiu	$t9,$sp,0x98
/*  f19ee34:	07000042 */ 	bltz	$t8,.L0f19ef40
/*  f19ee38:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f19ee3c:	87230000 */ 	lh	$v1,0x0($t9)
/*  f19ee40:	8e8a0338 */ 	lw	$t2,0x338($s4)
.L0f19ee44:
/*  f19ee44:	000348c0 */ 	sll	$t1,$v1,0x3
/*  f19ee48:	01234821 */ 	addu	$t1,$t1,$v1
/*  f19ee4c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f19ee50:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f19ee54:	50400037 */ 	beqzl	$v0,.L0f19ef34
/*  f19ee58:	86430002 */ 	lh	$v1,0x2($s2)
/*  f19ee5c:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f19ee60:	24010004 */ 	addiu	$at,$zero,0x4
/*  f19ee64:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f19ee68:	55610032 */ 	bnel	$t3,$at,.L0f19ef34
/*  f19ee6c:	86430002 */ 	lh	$v1,0x2($s2)
/*  f19ee70:	92020003 */ 	lbu	$v0,0x3($s0)
/*  f19ee74:	2401000d */ 	addiu	$at,$zero,0xd
/*  f19ee78:	02002025 */ 	or	$a0,$s0,$zero
/*  f19ee7c:	54410005 */ 	bnel	$v0,$at,.L0f19ee94
/*  f19ee80:	24010008 */ 	addiu	$at,$zero,0x8
/*  f19ee84:	0fc1acd3 */ 	jal	setupParseObjectWithArg2False
/*  f19ee88:	02602825 */ 	or	$a1,$s3,$zero
/*  f19ee8c:	92020003 */ 	lbu	$v0,0x3($s0)
/*  f19ee90:	24010008 */ 	addiu	$at,$zero,0x8
.L0f19ee94:
/*  f19ee94:	54410027 */ 	bnel	$v0,$at,.L0f19ef34
/*  f19ee98:	86430002 */ 	lh	$v1,0x2($s2)
/*  f19ee9c:	9202005c */ 	lbu	$v0,0x5c($s0)
/*  f19eea0:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f19eea4:	02002025 */ 	or	$a0,$s0,$zero
/*  f19eea8:	1041001f */ 	beq	$v0,$at,.L0f19ef28
/*  f19eeac:	24010056 */ 	addiu	$at,$zero,0x56
/*  f19eeb0:	1041001d */ 	beq	$v0,$at,.L0f19ef28
/*  f19eeb4:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f19eeb8:	1041001b */ 	beq	$v0,$at,.L0f19ef28
/*  f19eebc:	24010054 */ 	addiu	$at,$zero,0x54
/*  f19eec0:	10410019 */ 	beq	$v0,$at,.L0f19ef28
/*  f19eec4:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19eec8:	10410017 */ 	beq	$v0,$at,.L0f19ef28
/*  f19eecc:	24010055 */ 	addiu	$at,$zero,0x55
/*  f19eed0:	10410015 */ 	beq	$v0,$at,.L0f19ef28
/*  f19eed4:	24010021 */ 	addiu	$at,$zero,0x21
/*  f19eed8:	10410013 */ 	beq	$v0,$at,.L0f19ef28
/*  f19eedc:	24010022 */ 	addiu	$at,$zero,0x22
/*  f19eee0:	10410011 */ 	beq	$v0,$at,.L0f19ef28
/*  f19eee4:	24010053 */ 	addiu	$at,$zero,0x53
/*  f19eee8:	1041000f */ 	beq	$v0,$at,.L0f19ef28
/*  f19eeec:	24010020 */ 	addiu	$at,$zero,0x20
/*  f19eef0:	1041000d */ 	beq	$v0,$at,.L0f19ef28
/*  f19eef4:	24010058 */ 	addiu	$at,$zero,0x58
/*  f19eef8:	1041000b */ 	beq	$v0,$at,.L0f19ef28
/*  f19eefc:	2401000f */ 	addiu	$at,$zero,0xf
/*  f19ef00:	54410004 */ 	bnel	$v0,$at,.L0f19ef14
/*  f19ef04:	2401000e */ 	addiu	$at,$zero,0xe
/*  f19ef08:	920c005f */ 	lbu	$t4,0x5f($s0)
/*  f19ef0c:	126c0006 */ 	beq	$s3,$t4,.L0f19ef28
/*  f19ef10:	2401000e */ 	addiu	$at,$zero,0xe
.L0f19ef14:
/*  f19ef14:	54410007 */ 	bnel	$v0,$at,.L0f19ef34
/*  f19ef18:	86430002 */ 	lh	$v1,0x2($s2)
/*  f19ef1c:	920d005f */ 	lbu	$t5,0x5f($s0)
/*  f19ef20:	566d0004 */ 	bnel	$s3,$t5,.L0f19ef34
/*  f19ef24:	86430002 */ 	lh	$v1,0x2($s2)
.L0f19ef28:
/*  f19ef28:	0fc1acd3 */ 	jal	setupParseObjectWithArg2False
/*  f19ef2c:	02602825 */ 	or	$a1,$s3,$zero
/*  f19ef30:	86430002 */ 	lh	$v1,0x2($s2)
.L0f19ef34:
/*  f19ef34:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f19ef38:	0463ffc2 */ 	bgezl	$v1,.L0f19ee44
/*  f19ef3c:	8e8a0338 */ 	lw	$t2,0x338($s4)
.L0f19ef40:
/*  f19ef40:	3c08800a */ 	lui	$t0,%hi(var800a3434)
/*  f19ef44:	25083434 */ 	addiu	$t0,$t0,%lo(var800a3434)
/*  f19ef48:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f19ef4c:	00002825 */ 	or	$a1,$zero,$zero
/*  f19ef50:	24070100 */ 	addiu	$a3,$zero,0x100
/*  f19ef54:	19c00019 */ 	blez	$t6,.L0f19efbc
/*  f19ef58:	240403c0 */ 	addiu	$a0,$zero,0x3c0
/*  f19ef5c:	3c03800a */ 	lui	$v1,%hi(var800a3430)
/*  f19ef60:	24633430 */ 	addiu	$v1,$v1,%lo(var800a3430)
/*  f19ef64:	8c6f0000 */ 	lw	$t7,0x0($v1)
.L0f19ef68:
/*  f19ef68:	00001025 */ 	or	$v0,$zero,$zero
/*  f19ef6c:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f19ef70:	a70703c8 */ 	sh	$a3,0x3c8($t8)
.L0f19ef74:
/*  f19ef74:	001148c0 */ 	sll	$t1,$s1,0x3
/*  f19ef78:	01314821 */ 	addu	$t1,$t1,$s1
/*  f19ef7c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f19ef80:	00094900 */ 	sll	$t1,$t1,0x4
/*  f19ef84:	01314823 */ 	subu	$t1,$t1,$s1
/*  f19ef88:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f19ef8c:	03295021 */ 	addu	$t2,$t9,$t1
/*  f19ef90:	01425821 */ 	addu	$t3,$t2,$v0
/*  f19ef94:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f19ef98:	1444fff6 */ 	bne	$v0,$a0,.L0f19ef74
/*  f19ef9c:	a560001c */ 	sh	$zero,0x1c($t3)
/*  f19efa0:	8d0c0000 */ 	lw	$t4,0x0($t0)
/*  f19efa4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19efa8:	24a50478 */ 	addiu	$a1,$a1,0x478
/*  f19efac:	022c082a */ 	slt	$at,$s1,$t4
/*  f19efb0:	5420ffed */ 	bnezl	$at,.L0f19ef68
/*  f19efb4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f19efb8:	00008825 */ 	or	$s1,$zero,$zero
.L0f19efbc:
/*  f19efbc:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f19efc0:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f19efc4:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f19efc8:	24070100 */ 	addiu	$a3,$zero,0x100
/*  f19efcc:	00002825 */ 	or	$a1,$zero,$zero
/*  f19efd0:	19a0001b */ 	blez	$t5,.L0f19f040
/*  f19efd4:	24040190 */ 	addiu	$a0,$zero,0x190
/*  f19efd8:	3c03800a */ 	lui	$v1,%hi(var800a3440)
/*  f19efdc:	44800000 */ 	mtc1	$zero,$f0
/*  f19efe0:	24633440 */ 	addiu	$v1,$v1,%lo(var800a3440)
/*  f19efe4:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f19efe8:
/*  f19efe8:	00001025 */ 	or	$v0,$zero,$zero
/*  f19efec:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f19eff0:	a5e70004 */ 	sh	$a3,0x4($t7)
.L0f19eff4:
/*  f19eff4:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f19eff8:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f19effc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f19f000:	0331c821 */ 	addu	$t9,$t9,$s1
/*  f19f004:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f19f008:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f19f00c:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f19f010:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f19f014:	03194821 */ 	addu	$t1,$t8,$t9
/*  f19f018:	01225021 */ 	addu	$t2,$t1,$v0
/*  f19f01c:	24420028 */ 	addiu	$v0,$v0,0x28
/*  f19f020:	1444fff4 */ 	bne	$v0,$a0,.L0f19eff4
/*  f19f024:	e5400014 */ 	swc1	$f0,0x14($t2)
/*  f19f028:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f19f02c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19f030:	24a5019c */ 	addiu	$a1,$a1,0x19c
/*  f19f034:	022b082a */ 	slt	$at,$s1,$t3
/*  f19f038:	5420ffeb */ 	bnezl	$at,.L0f19efe8
/*  f19f03c:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f19f040:
/*  f19f040:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f19f044:	0fc2eda7 */ 	jal	func0f0bb69c
/*  f19f048:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f19f04c:	3c013f80 */ 	lui	$at,0x3f80
/*  f19f050:	44812000 */ 	mtc1	$at,$f4
/*  f19f054:	8e8c0284 */ 	lw	$t4,0x284($s4)
/*  f19f058:	e58400dc */ 	swc1	$f4,0xdc($t4)
/*  f19f05c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f19f060:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19f064:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19f068:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19f06c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19f070:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19f074:	03e00008 */ 	jr	$ra
/*  f19f078:	27bd02a0 */ 	addiu	$sp,$sp,0x2a0
);

GLOBAL_ASM(
glabel func0f19f07c
/*  f19f07c:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f19f080:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
/*  f19f084:	946e0462 */ 	lhu	$t6,0x462($v1)
/*  f19f088:	946f045c */ 	lhu	$t7,0x45c($v1)
/*  f19f08c:	9479045e */ 	lhu	$t9,0x45e($v1)
/*  f19f090:	94690460 */ 	lhu	$t1,0x460($v1)
/*  f19f094:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19f098:	03194021 */ 	addu	$t0,$t8,$t9
/*  f19f09c:	01095021 */ 	addu	$t2,$t0,$t1
/*  f19f0a0:	448a2000 */ 	mtc1	$t2,$f4
/*  f19f0a4:	3c0142c8 */ 	lui	$at,0x42c8
/*  f19f0a8:	44814000 */ 	mtc1	$at,$f8
/*  f19f0ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19f0b0:	94620458 */ 	lhu	$v0,0x458($v1)
/*  f19f0b4:	46083002 */ 	mul.s	$f0,$f6,$f8
/*  f19f0b8:	50400018 */ 	beqzl	$v0,.L0f19f11c
/*  f19f0bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f0c0:	44825000 */ 	mtc1	$v0,$f10
/*  f19f0c4:	3c014f80 */ 	lui	$at,0x4f80
/*  f19f0c8:	04410004 */ 	bgez	$v0,.L0f19f0dc
/*  f19f0cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f19f0d0:	44819000 */ 	mtc1	$at,$f18
/*  f19f0d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f0d8:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f19f0dc:
/*  f19f0dc:	906b0008 */ 	lbu	$t3,0x8($v1)
/*  f19f0e0:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f19f0e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f19f0e8:	448b2000 */ 	mtc1	$t3,$f4
/*  f19f0ec:	05610004 */ 	bgez	$t3,.L0f19f100
/*  f19f0f0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19f0f4:	44814000 */ 	mtc1	$at,$f8
/*  f19f0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f0fc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f19f100:
/*  f19f100:	4606103c */ 	c.lt.s	$f2,$f6
/*  f19f104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f108:	45020004 */ 	bc1fl	.L0f19f11c
/*  f19f10c:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f110:	03e00008 */ 	jr	$ra
/*  f19f114:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19f118:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f11c:
/*  f19f11c:	03e00008 */ 	jr	$ra
/*  f19f120:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19f124
/*  f19f124:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19f128:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19f12c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f19f130:	0fc67b37 */ 	jal	func0f19ecdc
/*  f19f134:	00002025 */ 	or	$a0,$zero,$zero
/*  f19f138:	0fc67c1f */ 	jal	func0f19f07c
/*  f19f13c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f140:	10400006 */ 	beqz	$v0,.L0f19f15c
/*  f19f144:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f19f148:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f19f14c:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f19f150:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f19f154:	10000005 */ 	beqz	$zero,.L0f19f16c
/*  f19f158:	a04e045b */ 	sb	$t6,0x45b($v0)
.L0f19f15c:
/*  f19f15c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f19f160:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f19f164:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f19f168:	a04f045b */ 	sb	$t7,0x45b($v0)
.L0f19f16c:
/*  f19f16c:	90580465 */ 	lbu	$t8,0x465($v0)
/*  f19f170:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19f174:	a0490464 */ 	sb	$t1,0x464($v0)
/*  f19f178:	3319ff1f */ 	andi	$t9,$t8,0xff1f
/*  f19f17c:	37280040 */ 	ori	$t0,$t9,0x40
/*  f19f180:	a0480465 */ 	sb	$t0,0x465($v0)
/*  f19f184:	03e00008 */ 	jr	$ra
/*  f19f188:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f19f18c
/*  f19f18c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f19f190:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f19f194:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19f198:	0fc67b37 */ 	jal	func0f19ecdc
/*  f19f19c:	00002025 */ 	or	$a0,$zero,$zero
/*  f19f1a0:	0fc67c1f */ 	jal	func0f19f07c
/*  f19f1a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f1a8:	1040000a */ 	beqz	$v0,.L0f19f1d4
/*  f19f1ac:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19f1b0:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19f1b4:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19f1b8:	920f0465 */ 	lbu	$t7,0x465($s0)
/*  f19f1bc:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f19f1c0:	a20e045b */ 	sb	$t6,0x45b($s0)
/*  f19f1c4:	31f8ff1f */ 	andi	$t8,$t7,0xff1f
/*  f19f1c8:	37190040 */ 	ori	$t9,$t8,0x40
/*  f19f1cc:	1000000e */ 	beqz	$zero,.L0f19f208
/*  f19f1d0:	a2190465 */ 	sb	$t9,0x465($s0)
.L0f19f1d4:
/*  f19f1d4:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19f1d8:	0fc6749a */ 	jal	func0f19d268
/*  f19f1dc:	96040456 */ 	lhu	$a0,0x456($s0)
/*  f19f1e0:	0fc67330 */ 	jal	func0f19ccc0
/*  f19f1e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f19f1e8:	92050448 */ 	lbu	$a1,0x448($s0)
/*  f19f1ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f19f1f0:	0fc67279 */ 	jal	func0f19c9e4
/*  f19f1f4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f19f1f8:	92080465 */ 	lbu	$t0,0x465($s0)
/*  f19f1fc:	3109ff1f */ 	andi	$t1,$t0,0xff1f
/*  f19f200:	352a0060 */ 	ori	$t2,$t1,0x60
/*  f19f204:	a20a0465 */ 	sb	$t2,0x465($s0)
.L0f19f208:
/*  f19f208:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f19f20c:	240b003c */ 	addiu	$t3,$zero,0x3c
/*  f19f210:	a20b0464 */ 	sb	$t3,0x464($s0)
/*  f19f214:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19f218:	03e00008 */ 	jr	$ra
/*  f19f21c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f19f220
/*  f19f220:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f19f224:	3c05800b */ 	lui	$a1,%hi(var800ad158)
/*  f19f228:	24a5d158 */ 	addiu	$a1,$a1,%lo(var800ad158)
/*  f19f22c:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
/*  f19f230:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f19f234:
/*  f19f234:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19f238:	11c00010 */ 	beqz	$t6,.L0f19f27c
/*  f19f23c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19f240:	0700000e */ 	bltz	$t8,.L0f19f27c
/*  f19f244:	00024040 */ 	sll	$t0,$v0,0x1
/*  f19f248:	0503000d */ 	bgezl	$t0,.L0f19f280
/*  f19f24c:	2463003c */ 	addiu	$v1,$v1,0x3c
/*  f19f250:	8c690014 */ 	lw	$t1,0x14($v1)
/*  f19f254:	5489000a */ 	bnel	$a0,$t1,.L0f19f280
/*  f19f258:	2463003c */ 	addiu	$v1,$v1,0x3c
/*  f19f25c:	906a0040 */ 	lbu	$t2,0x40($v1)
/*  f19f260:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f19f264:	11600003 */ 	beqz	$t3,.L0f19f274
/*  f19f268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f26c:	03e00008 */ 	jr	$ra
/*  f19f270:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19f274:
/*  f19f274:	03e00008 */ 	jr	$ra
/*  f19f278:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f27c:
/*  f19f27c:	2463003c */ 	addiu	$v1,$v1,0x3c
.L0f19f280:
/*  f19f280:	5465ffec */ 	bnel	$v1,$a1,.L0f19f234
/*  f19f284:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f19f288:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f28c:	03e00008 */ 	jr	$ra
/*  f19f290:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19f294
.late_rodata
glabel var7f1b94ac
.word 0x40c907a9
.text
/*  f19f294:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19f298:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19f29c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f19f2a0:	c4c60000 */ 	lwc1	$f6,0x0($a2)
/*  f19f2a4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f19f2a8:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f19f2ac:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f19f2b0:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f19f2b4:	0fc259d4 */ 	jal	func0f096750
/*  f19f2b8:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f19f2bc:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*  f19f2c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19f2c4:	3c017f1c */ 	lui	$at,%hi(var7f1b94ac)
/*  f19f2c8:	460e003c */ 	c.lt.s	$f0,$f14
/*  f19f2cc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19f2d0:	460e0301 */ 	sub.s	$f12,$f0,$f14
/*  f19f2d4:	45000003 */ 	bc1f	.L0f19f2e4
/*  f19f2d8:	46006086 */ 	mov.s	$f2,$f12
/*  f19f2dc:	c43094ac */ 	lwc1	$f16,%lo(var7f1b94ac)($at)
/*  f19f2e0:	46106080 */ 	add.s	$f2,$f12,$f16
.L0f19f2e4:
/*  f19f2e4:	03e00008 */ 	jr	$ra
/*  f19f2e8:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f19f2ec
.late_rodata
glabel var7f1b94b0
.word 0x3fc90fdb
glabel var7f1b94b4
.word 0x4096c5bf
.text
/*  f19f2ec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19f2f0:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f19f2f4:	3c03800b */ 	lui	$v1,%hi(var800ad158)
/*  f19f2f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19f2fc:	00803825 */ 	or	$a3,$a0,$zero
/*  f19f300:	00a03025 */ 	or	$a2,$a1,$zero
/*  f19f304:	2463d158 */ 	addiu	$v1,$v1,%lo(var800ad158)
/*  f19f308:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f19f30c:	8c4e0014 */ 	lw	$t6,0x14($v0)
.L0f19f310:
/*  f19f310:	54ee001b */ 	bnel	$a3,$t6,.L0f19f380
/*  f19f314:	2442003c */ 	addiu	$v0,$v0,0x3c
/*  f19f318:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f19f31c:	24e40008 */ 	addiu	$a0,$a3,0x8
/*  f19f320:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f19f324:	07210003 */ 	bgez	$t9,.L0f19f334
/*  f19f328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f32c:	10000017 */ 	beqz	$zero,.L0f19f38c
/*  f19f330:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f334:
/*  f19f334:	0fc67ca5 */ 	jal	func0f19f294
/*  f19f338:	8c450038 */ 	lw	$a1,0x38($v0)
/*  f19f33c:	3c017f1c */ 	lui	$at,%hi(var7f1b94b0)
/*  f19f340:	c42494b0 */ 	lwc1	$f4,%lo(var7f1b94b0)($at)
/*  f19f344:	3c017f1c */ 	lui	$at,%hi(var7f1b94b4)
/*  f19f348:	4600203c */ 	c.lt.s	$f4,$f0
/*  f19f34c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f350:	45000008 */ 	bc1f	.L0f19f374
/*  f19f354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f358:	c42694b4 */ 	lwc1	$f6,%lo(var7f1b94b4)($at)
/*  f19f35c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f19f360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f364:	45000003 */ 	bc1f	.L0f19f374
/*  f19f368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f36c:	10000007 */ 	beqz	$zero,.L0f19f38c
/*  f19f370:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f374:
/*  f19f374:	10000005 */ 	beqz	$zero,.L0f19f38c
/*  f19f378:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19f37c:	2442003c */ 	addiu	$v0,$v0,0x3c
.L0f19f380:
/*  f19f380:	5443ffe3 */ 	bnel	$v0,$v1,.L0f19f310
/*  f19f384:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f19f388:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19f38c:
/*  f19f38c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19f390:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19f394:	03e00008 */ 	jr	$ra
/*  f19f398:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19f39c
.late_rodata
glabel var7f1b94b8
.word 0x4096c5bf
glabel var7f1b94bc
.word 0x3fc90fdb
.text
/*  f19f39c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f19f3a0:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f19f3a4:	3c014e00 */ 	lui	$at,0x4e00
/*  f19f3a8:	4481b000 */ 	mtc1	$at,$f22
/*  f19f3ac:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f19f3b0:	3c017f1c */ 	lui	$at,%hi(var7f1b94b8)
/*  f19f3b4:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f19f3b8:	c43894b8 */ 	lwc1	$f24,%lo(var7f1b94b8)($at)
/*  f19f3bc:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f19f3c0:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f19f3c4:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f19f3c8:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f19f3cc:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f19f3d0:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f19f3d4:	3c017f1c */ 	lui	$at,%hi(var7f1b94bc)
/*  f19f3d8:	3c11800b */ 	lui	$s1,%hi(var800acd20)
/*  f19f3dc:	00809825 */ 	or	$s3,$a0,$zero
/*  f19f3e0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f19f3e4:	00009025 */ 	or	$s2,$zero,$zero
/*  f19f3e8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19f3ec:	2631cd20 */ 	addiu	$s1,$s1,%lo(var800acd20)
/*  f19f3f0:	c43494bc */ 	lwc1	$f20,%lo(var7f1b94bc)($at)
/*  f19f3f4:	00008025 */ 	or	$s0,$zero,$zero
/*  f19f3f8:	27b40084 */ 	addiu	$s4,$sp,0x84
.L0f19f3fc:
/*  f19f3fc:	8e220010 */ 	lw	$v0,0x10($s1)
/*  f19f400:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19f404:	11c00014 */ 	beqz	$t6,.L0f19f458
/*  f19f408:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19f40c:	07000012 */ 	bltz	$t8,.L0f19f458
/*  f19f410:	00024040 */ 	sll	$t0,$v0,0x1
/*  f19f414:	05010010 */ 	bgez	$t0,.L0f19f458
/*  f19f418:	02603025 */ 	or	$a2,$s3,$zero
/*  f19f41c:	8e240014 */ 	lw	$a0,0x14($s1)
/*  f19f420:	8e250038 */ 	lw	$a1,0x38($s1)
/*  f19f424:	0fc67ca5 */ 	jal	func0f19f294
/*  f19f428:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f19f42c:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f19f430:	00124880 */ 	sll	$t1,$s2,0x2
/*  f19f434:	02895021 */ 	addu	$t2,$s4,$t1
/*  f19f438:	45020006 */ 	bc1fl	.L0f19f454
/*  f19f43c:	ad500000 */ 	sw	$s0,0x0($t2)
/*  f19f440:	4618003c */ 	c.lt.s	$f0,$f24
/*  f19f444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f448:	45030004 */ 	bc1tl	.L0f19f45c
/*  f19f44c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19f450:	ad500000 */ 	sw	$s0,0x0($t2)
.L0f19f454:
/*  f19f454:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f19f458:
/*  f19f458:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19f45c:
/*  f19f45c:	2a010012 */ 	slti	$at,$s0,0x12
/*  f19f460:	1420ffe6 */ 	bnez	$at,.L0f19f3fc
/*  f19f464:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f19f468:	1a400021 */ 	blez	$s2,.L0f19f4f0
/*  f19f46c:	00008025 */ 	or	$s0,$zero,$zero
/*  f19f470:	3c04800b */ 	lui	$a0,%hi(var800acd20)
/*  f19f474:	2484cd20 */ 	addiu	$a0,$a0,%lo(var800acd20)
/*  f19f478:	27a30084 */ 	addiu	$v1,$sp,0x84
/*  f19f47c:	c6700000 */ 	lwc1	$f16,0x0($s3)
/*  f19f480:	c6720004 */ 	lwc1	$f18,0x4($s3)
/*  f19f484:	c6740008 */ 	lwc1	$f20,0x8($s3)
/*  f19f488:	2405003c */ 	addiu	$a1,$zero,0x3c
.L0f19f48c:
/*  f19f48c:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f19f490:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19f494:	01650019 */ 	multu	$t3,$a1
/*  f19f498:	00006012 */ 	mflo	$t4
/*  f19f49c:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f19f4a0:	8da20014 */ 	lw	$v0,0x14($t5)
/*  f19f4a4:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f19f4a8:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f19f4ac:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f19f4b0:	46102001 */ 	sub.s	$f0,$f4,$f16
/*  f19f4b4:	46123081 */ 	sub.s	$f2,$f6,$f18
/*  f19f4b8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f19f4bc:	46144301 */ 	sub.s	$f12,$f8,$f20
/*  f19f4c0:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f19f4c4:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f19f4c8:	460c6202 */ 	mul.s	$f8,$f12,$f12
/*  f19f4cc:	46083380 */ 	add.s	$f14,$f6,$f8
/*  f19f4d0:	4616703c */ 	c.lt.s	$f14,$f22
/*  f19f4d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f4d8:	45000003 */ 	bc1f	.L0f19f4e8
/*  f19f4dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f4e0:	46007586 */ 	mov.s	$f22,$f14
/*  f19f4e4:	0040a825 */ 	or	$s5,$v0,$zero
.L0f19f4e8:
/*  f19f4e8:	1612ffe8 */ 	bne	$s0,$s2,.L0f19f48c
/*  f19f4ec:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f19f4f0:
/*  f19f4f0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f19f4f4:	02a01025 */ 	or	$v0,$s5,$zero
/*  f19f4f8:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f19f4fc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f19f500:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f19f504:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f19f508:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f19f50c:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f19f510:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f19f514:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f19f518:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f19f51c:	03e00008 */ 	jr	$ra
/*  f19f520:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

GLOBAL_ASM(
glabel func0f19f524
/*  f19f524:	27bdfd40 */ 	addiu	$sp,$sp,-704
/*  f19f528:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19f52c:	3c04800b */ 	lui	$a0,0x800b
/*  f19f530:	0fc6749a */ 	jal	func0f19d268
/*  f19f534:	9484d176 */ 	lhu	$a0,-0x2e8a($a0)
/*  f19f538:	afa202bc */ 	sw	$v0,0x2bc($sp)
/*  f19f53c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19f540:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19f544:	00002825 */ 	or	$a1,$zero,$zero
/*  f19f548:	afa202b4 */ 	sw	$v0,0x2b4($sp)
/*  f19f54c:	8fa402bc */ 	lw	$a0,0x2bc($sp)
/*  f19f550:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19f554:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19f558:	3c03800a */ 	lui	$v1,0x800a
/*  f19f55c:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f19f560:	8fae02bc */ 	lw	$t6,0x2bc($sp)
/*  f19f564:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f19f568:	00403825 */ 	or	$a3,$v0,$zero
/*  f19f56c:	24650638 */ 	addiu	$a1,$v1,0x638
/*  f19f570:	15c10003 */ 	bne	$t6,$at,.L0f19f580
/*  f19f574:	24660ddc */ 	addiu	$a2,$v1,0xddc
/*  f19f578:	10000102 */ 	beqz	$zero,.L0f19f984
/*  f19f57c:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f580:
/*  f19f580:	8ccf0220 */ 	lw	$t7,0x220($a2)
/*  f19f584:	8cb80220 */ 	lw	$t8,0x220($a1)
/*  f19f588:	8fa402b4 */ 	lw	$a0,0x2b4($sp)
/*  f19f58c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f19f590:	afb902a0 */ 	sw	$t9,0x2a0($sp)
/*  f19f594:	8caf0224 */ 	lw	$t7,0x224($a1)
/*  f19f598:	8cce0224 */ 	lw	$t6,0x224($a2)
/*  f19f59c:	afa702b0 */ 	sw	$a3,0x2b0($sp)
/*  f19f5a0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19f5a4:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19f5a8:	afb802a4 */ 	sw	$t8,0x2a4($sp)
/*  f19f5ac:	8fb902a0 */ 	lw	$t9,0x2a0($sp)
/*  f19f5b0:	8fa402b0 */ 	lw	$a0,0x2b0($sp)
/*  f19f5b4:	03227021 */ 	addu	$t6,$t9,$v0
/*  f19f5b8:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19f5bc:	afae0298 */ 	sw	$t6,0x298($sp)
/*  f19f5c0:	8fb80298 */ 	lw	$t8,0x298($sp)
/*  f19f5c4:	8faf02a4 */ 	lw	$t7,0x2a4($sp)
/*  f19f5c8:	1f0000ed */ 	bgtz	$t8,.L0f19f980
/*  f19f5cc:	01e21821 */ 	addu	$v1,$t7,$v0
/*  f19f5d0:	1c6000eb */ 	bgtz	$v1,.L0f19f980
/*  f19f5d4:	afa3029c */ 	sw	$v1,0x29c($sp)
/*  f19f5d8:	3c06800b */ 	lui	$a2,%hi(var800acd20)
/*  f19f5dc:	24c6cd20 */ 	addiu	$a2,$a2,%lo(var800acd20)
/*  f19f5e0:	8cd90464 */ 	lw	$t9,0x464($a2)
/*  f19f5e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f5e8:	3c03800a */ 	lui	$v1,%hi(var800a0478)
/*  f19f5ec:	00197b40 */ 	sll	$t7,$t9,0xd
/*  f19f5f0:	05e10006 */ 	bgez	$t7,.L0f19f60c
/*  f19f5f4:	24041ad0 */ 	addiu	$a0,$zero,0x1ad0
/*  f19f5f8:	90d80465 */ 	lbu	$t8,0x465($a2)
/*  f19f5fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f600:	3319fffb */ 	andi	$t9,$t8,0xfffb
/*  f19f604:	100000df */ 	beqz	$zero,.L0f19f984
/*  f19f608:	a0d90465 */ 	sb	$t9,0x465($a2)
.L0f19f60c:
/*  f19f60c:	8c633430 */ 	lw	$v1,0x3430($v1)
.L0f19f610:
/*  f19f610:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f19f614:	24420478 */ 	addiu	$v0,$v0,0x478
/*  f19f618:	11c00003 */ 	beqz	$t6,.L0f19f628
/*  f19f61c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f620:	100000d8 */ 	beqz	$zero,.L0f19f984
/*  f19f624:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f628:
/*  f19f628:	1444fff9 */ 	bne	$v0,$a0,.L0f19f610
/*  f19f62c:	24630478 */ 	addiu	$v1,$v1,%lo(var800a0478)
/*  f19f630:	8fa202bc */ 	lw	$v0,0x2bc($sp)
/*  f19f634:	24010018 */ 	addiu	$at,$zero,0x18
/*  f19f638:	3c0f800a */ 	lui	$t7,0x800a
/*  f19f63c:	10410015 */ 	beq	$v0,$at,.L0f19f694
/*  f19f640:	24010019 */ 	addiu	$at,$zero,0x19
/*  f19f644:	10410013 */ 	beq	$v0,$at,.L0f19f694
/*  f19f648:	24010017 */ 	addiu	$at,$zero,0x17
/*  f19f64c:	10410011 */ 	beq	$v0,$at,.L0f19f694
/*  f19f650:	24010012 */ 	addiu	$at,$zero,0x12
/*  f19f654:	1041000f */ 	beq	$v0,$at,.L0f19f694
/*  f19f658:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f19f65c:	1041000d */ 	beq	$v0,$at,.L0f19f694
/*  f19f660:	2401001b */ 	addiu	$at,$zero,0x1b
/*  f19f664:	1041000b */ 	beq	$v0,$at,.L0f19f694
/*  f19f668:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19f66c:	10410009 */ 	beq	$v0,$at,.L0f19f694
/*  f19f670:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f19f674:	10410007 */ 	beq	$v0,$at,.L0f19f694
/*  f19f678:	24010020 */ 	addiu	$at,$zero,0x20
/*  f19f67c:	10410005 */ 	beq	$v0,$at,.L0f19f694
/*  f19f680:	24010021 */ 	addiu	$at,$zero,0x21
/*  f19f684:	10410003 */ 	beq	$v0,$at,.L0f19f694
/*  f19f688:	24010022 */ 	addiu	$at,$zero,0x22
/*  f19f68c:	144100ba */ 	bne	$v0,$at,.L0f19f978
/*  f19f690:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19f694:
/*  f19f694:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f19f698:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f19f69c:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f19f6a0:	0fc195e9 */ 	jal	roomsCopy
/*  f19f6a4:	24840028 */ 	addiu	$a0,$a0,0x0028
/*  f19f6a8:	3c18800a */ 	lui	$t8,0x800a
/*  f19f6ac:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f19f6b0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19f6b4:	00001825 */ 	or	$v1,$zero,$zero
/*  f19f6b8:	8f0200bc */ 	lw	$v0,0xbc($t8)
/*  f19f6bc:	84590028 */ 	lh	$t9,0x28($v0)
/*  f19f6c0:	53210015 */ 	beql	$t9,$at,.L0f19f718
/*  f19f6c4:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f19f6c8:	84440028 */ 	lh	$a0,0x28($v0)
/*  f19f6cc:	27a5004c */ 	addiu	$a1,$sp,0x4c
.L0f19f6d0:
/*  f19f6d0:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f19f6d4:	0fc5916a */ 	jal	func0f1645a8
/*  f19f6d8:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f19f6dc:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f19f6e0:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f19f6e4:	0fc195f6 */ 	jal	func0f0657d8
/*  f19f6e8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f19f6ec:	3c0e800a */ 	lui	$t6,0x800a
/*  f19f6f0:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f19f6f4:	8fa30020 */ 	lw	$v1,0x20($sp)
/*  f19f6f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19f6fc:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f19f700:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f19f704:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f19f708:	87040028 */ 	lh	$a0,0x28($t8)
/*  f19f70c:	5481fff0 */ 	bnel	$a0,$at,.L0f19f6d0
/*  f19f710:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f19f714:	27a40064 */ 	addiu	$a0,$sp,0x64
.L0f19f718:
/*  f19f718:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f19f71c:	0fc197e0 */ 	jal	roomGetProps
/*  f19f720:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f19f724:	87ae0090 */ 	lh	$t6,0x90($sp)
/*  f19f728:	27b90090 */ 	addiu	$t9,$sp,0x90
/*  f19f72c:	03203025 */ 	or	$a2,$t9,$zero
/*  f19f730:	05c00091 */ 	bltz	$t6,.L0f19f978
/*  f19f734:	3c0f800a */ 	lui	$t7,0x800a
/*  f19f738:	8defa2f8 */ 	lw	$t7,-0x5d08($t7)
/*  f19f73c:	87230000 */ 	lh	$v1,0x0($t9)
/*  f19f740:	241f0056 */ 	addiu	$ra,$zero,0x56
/*  f19f744:	240d0054 */ 	addiu	$t5,$zero,0x54
/*  f19f748:	240c0053 */ 	addiu	$t4,$zero,0x53
/*  f19f74c:	240b0048 */ 	addiu	$t3,$zero,0x48
/*  f19f750:	240a0021 */ 	addiu	$t2,$zero,0x21
/*  f19f754:	24090020 */ 	addiu	$t1,$zero,0x20
/*  f19f758:	24080022 */ 	addiu	$t0,$zero,0x22
/*  f19f75c:	24070055 */ 	addiu	$a3,$zero,0x55
/*  f19f760:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19f764:	afaf0020 */ 	sw	$t7,0x20($sp)
.L0f19f768:
/*  f19f768:	006b0019 */ 	multu	$v1,$t3
/*  f19f76c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f19f770:	0000c012 */ 	mflo	$t8
/*  f19f774:	030e2021 */ 	addu	$a0,$t8,$t6
/*  f19f778:	8c82001c */ 	lw	$v0,0x1c($a0)
/*  f19f77c:	10400008 */ 	beqz	$v0,.L0f19f7a0
/*  f19f780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f784:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f19f788:	14b90005 */ 	bne	$a1,$t9,.L0f19f7a0
/*  f19f78c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f790:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f19f794:	91f8005c */ 	lbu	$t8,0x5c($t7)
/*  f19f798:	1138001c */ 	beq	$t1,$t8,.L0f19f80c
/*  f19f79c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19f7a0:
/*  f19f7a0:	10400008 */ 	beqz	$v0,.L0f19f7c4
/*  f19f7a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f7a8:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f19f7ac:	14ae0005 */ 	bne	$a1,$t6,.L0f19f7c4
/*  f19f7b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f7b4:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f19f7b8:	932f005c */ 	lbu	$t7,0x5c($t9)
/*  f19f7bc:	110f0013 */ 	beq	$t0,$t7,.L0f19f80c
/*  f19f7c0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19f7c4:
/*  f19f7c4:	10400008 */ 	beqz	$v0,.L0f19f7e8
/*  f19f7c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f7cc:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f19f7d0:	14b80005 */ 	bne	$a1,$t8,.L0f19f7e8
/*  f19f7d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f7d8:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f19f7dc:	91d9005c */ 	lbu	$t9,0x5c($t6)
/*  f19f7e0:	1159000a */ 	beq	$t2,$t9,.L0f19f80c
/*  f19f7e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19f7e8:
/*  f19f7e8:	5040000b */ 	beqzl	$v0,.L0f19f818
/*  f19f7ec:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f19f7f0:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f19f7f4:	54af0008 */ 	bnel	$a1,$t7,.L0f19f818
/*  f19f7f8:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f19f7fc:	8c580004 */ 	lw	$t8,0x4($v0)
/*  f19f800:	930e005c */ 	lbu	$t6,0x5c($t8)
/*  f19f804:	54ee0004 */ 	bnel	$a3,$t6,.L0f19f818
/*  f19f808:	90990000 */ 	lbu	$t9,0x0($a0)
.L0f19f80c:
/*  f19f80c:	1000005d */ 	beqz	$zero,.L0f19f984
/*  f19f810:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f814:	90990000 */ 	lbu	$t9,0x0($a0)
.L0f19f818:
/*  f19f818:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19f81c:	54b90053 */ 	bnel	$a1,$t9,.L0f19f96c
/*  f19f820:	84c30002 */ 	lh	$v1,0x2($a2)
/*  f19f824:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f19f828:	9062005c */ 	lbu	$v0,0x5c($v1)
/*  f19f82c:	11820007 */ 	beq	$t4,$v0,.L0f19f84c
/*  f19f830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f834:	11a20005 */ 	beq	$t5,$v0,.L0f19f84c
/*  f19f838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f83c:	10410003 */ 	beq	$v0,$at,.L0f19f84c
/*  f19f840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f844:	14e20003 */ 	bne	$a3,$v0,.L0f19f854
/*  f19f848:	2401001a */ 	addiu	$at,$zero,0x1a
.L0f19f84c:
/*  f19f84c:	1000004d */ 	beqz	$zero,.L0f19f984
/*  f19f850:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f854:
/*  f19f854:	53e20004 */ 	beql	$ra,$v0,.L0f19f868
/*  f19f858:	8c6f0040 */ 	lw	$t7,0x40($v1)
/*  f19f85c:	14410007 */ 	bne	$v0,$at,.L0f19f87c
/*  f19f860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f864:	8c6f0040 */ 	lw	$t7,0x40($v1)
.L0f19f868:
/*  f19f868:	31f80080 */ 	andi	$t8,$t7,0x80
/*  f19f86c:	5300003f */ 	beqzl	$t8,.L0f19f96c
/*  f19f870:	84c30002 */ 	lh	$v1,0x2($a2)
/*  f19f874:	10000043 */ 	beqz	$zero,.L0f19f984
/*  f19f878:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f87c:
/*  f19f87c:	11220003 */ 	beq	$t1,$v0,.L0f19f88c
/*  f19f880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f884:	15020003 */ 	bne	$t0,$v0,.L0f19f894
/*  f19f888:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19f88c:
/*  f19f88c:	1000003d */ 	beqz	$zero,.L0f19f984
/*  f19f890:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f894:
/*  f19f894:	55420035 */ 	bnel	$t2,$v0,.L0f19f96c
/*  f19f898:	84c30002 */ 	lh	$v1,0x2($a2)
/*  f19f89c:	3c06800b */ 	lui	$a2,%hi(var800acd20)
/*  f19f8a0:	24c6cd20 */ 	addiu	$a2,$a2,%lo(var800acd20)
/*  f19f8a4:	84c20474 */ 	lh	$v0,0x474($a2)
/*  f19f8a8:	2405ff01 */ 	addiu	$a1,$zero,-255
/*  f19f8ac:	14a20003 */ 	bne	$a1,$v0,.L0f19f8bc
/*  f19f8b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f8b4:	10000033 */ 	beqz	$zero,.L0f19f984
/*  f19f8b8:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f8bc:
/*  f19f8bc:	14400014 */ 	bnez	$v0,.L0f19f910
/*  f19f8c0:	3c0f800a */ 	lui	$t7,0x800a
/*  f19f8c4:	8fa402bc */ 	lw	$a0,0x2bc($sp)
/*  f19f8c8:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19f8cc:	00002825 */ 	or	$a1,$zero,$zero
/*  f19f8d0:	3c0e800a */ 	lui	$t6,0x800a
/*  f19f8d4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f19f8d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f19f8dc:	25d90638 */ 	addiu	$t9,$t6,0x638
/*  f19f8e0:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19f8e4:	afb90034 */ 	sw	$t9,0x34($sp)
/*  f19f8e8:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f19f8ec:	2419012c */ 	addiu	$t9,$zero,0x12c
/*  f19f8f0:	3c01800b */ 	lui	$at,0x800b
/*  f19f8f4:	8df80220 */ 	lw	$t8,0x220($t7)
/*  f19f8f8:	03027021 */ 	addu	$t6,$t8,$v0
/*  f19f8fc:	15c00002 */ 	bnez	$t6,.L0f19f908
/*  f19f900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f904:	a439d194 */ 	sh	$t9,-0x2e6c($at)
.L0f19f908:
/*  f19f908:	1000001e */ 	beqz	$zero,.L0f19f984
/*  f19f90c:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f910:
/*  f19f910:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f19f914:	3c04800a */ 	lui	$a0,%hi(var8009ce38)
/*  f19f918:	2484ce38 */ 	addiu	$a0,$a0,%lo(var8009ce38)
/*  f19f91c:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f19f920:	a4d80474 */ 	sh	$t8,0x474($a2)
/*  f19f924:	84ce0474 */ 	lh	$t6,0x474($a2)
/*  f19f928:	3c02800a */ 	lui	$v0,%hi(var8009cdc0)
/*  f19f92c:	2442cdc0 */ 	addiu	$v0,$v0,%lo(var8009cdc0)
/*  f19f930:	1dc0000b */ 	bgtz	$t6,.L0f19f960
/*  f19f934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f938:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f19f93c:
/*  f19f93c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f19f940:	10600002 */ 	beqz	$v1,.L0f19f94c
/*  f19f944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f948:	a4600062 */ 	sh	$zero,0x62($v1)
.L0f19f94c:
/*  f19f94c:	5444fffb */ 	bnel	$v0,$a0,.L0f19f93c
/*  f19f950:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f19f954:	a4c50474 */ 	sh	$a1,0x474($a2)
/*  f19f958:	1000000a */ 	beqz	$zero,.L0f19f984
/*  f19f95c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19f960:
/*  f19f960:	10000008 */ 	beqz	$zero,.L0f19f984
/*  f19f964:	00001025 */ 	or	$v0,$zero,$zero
/*  f19f968:	84c30002 */ 	lh	$v1,0x2($a2)
.L0f19f96c:
/*  f19f96c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f19f970:	0461ff7d */ 	bgez	$v1,.L0f19f768
/*  f19f974:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19f978:
/*  f19f978:	10000002 */ 	beqz	$zero,.L0f19f984
/*  f19f97c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19f980:
/*  f19f980:	00001025 */ 	or	$v0,$zero,$zero
.L0f19f984:
/*  f19f984:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19f988:	27bd02c0 */ 	addiu	$sp,$sp,0x2c0
/*  f19f98c:	03e00008 */ 	jr	$ra
/*  f19f990:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19f994
.late_rodata
glabel var7f1b94c0
.word 0x4012a974
glabel var7f1b94c4
.word 0x407f7642
glabel var7f1b94c8
.word 0x40490fdb
glabel var7f1b94cc
.word 0xc59c4000
glabel var7f1b94d0
.word 0x40c907a9
glabel var7f1b94d4
.word 0x40490fdb
glabel var7f1b94d8
.word 0xbd0efa35
glabel var7f1b94dc
.word 0x40490fdb
glabel var7f1b94e0
.word 0x3d0efa35
glabel var7f1b94e4
.word 0x40490fdb
.text
/*  f19f994:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f19f998:	3c0e8009 */ 	lui	$t6,%hi(var80088804)
/*  f19f99c:	91ce8804 */ 	lbu	$t6,%lo(var80088804)($t6)
/*  f19f9a0:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f19f9a4:	afb60078 */ 	sw	$s6,0x78($sp)
/*  f19f9a8:	afb50074 */ 	sw	$s5,0x74($sp)
/*  f19f9ac:	afb40070 */ 	sw	$s4,0x70($sp)
/*  f19f9b0:	afb3006c */ 	sw	$s3,0x6c($sp)
/*  f19f9b4:	afb20068 */ 	sw	$s2,0x68($sp)
/*  f19f9b8:	afb10064 */ 	sw	$s1,0x64($sp)
/*  f19f9bc:	afb00060 */ 	sw	$s0,0x60($sp)
/*  f19f9c0:	f7b80058 */ 	sdc1	$f24,0x58($sp)
/*  f19f9c4:	f7b60050 */ 	sdc1	$f22,0x50($sp)
/*  f19f9c8:	11c00014 */ 	beqz	$t6,.L0f19fa1c
/*  f19f9cc:	f7b40048 */ 	sdc1	$f20,0x48($sp)
/*  f19f9d0:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f19f9d4:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f19f9d8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f19f9dc:	3c15800b */ 	lui	$s5,%hi(var800acd20)
/*  f19f9e0:	26b5cd20 */ 	addiu	$s5,$s5,%lo(var800acd20)
/*  f19f9e4:	8df81580 */ 	lw	$t8,0x1580($t7)
/*  f19f9e8:	00184f00 */ 	sll	$t1,$t8,0x1c
/*  f19f9ec:	0520000b */ 	bltz	$t1,.L0f19fa1c
/*  f19f9f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19f9f4:	0fc6749a */ 	jal	func0f19d268
/*  f19f9f8:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19f9fc:	0fc44727 */ 	jal	currentPlayerCanHaveWeapon
/*  f19fa00:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fa04:	10400005 */ 	beqz	$v0,.L0f19fa1c
/*  f19fa08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fa0c:	0fc6749a */ 	jal	func0f19d268
/*  f19fa10:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19fa14:	0fc2865b */ 	jal	currentPlayerEquipWeaponInCutscene
/*  f19fa18:	00402025 */ 	or	$a0,$v0,$zero
.L0f19fa1c:
/*  f19fa1c:	3c15800b */ 	lui	$s5,%hi(var800acd20)
/*  f19fa20:	26b5cd20 */ 	addiu	$s5,$s5,%lo(var800acd20)
/*  f19fa24:	82a30464 */ 	lb	$v1,0x464($s5)
/*  f19fa28:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f19fa2c:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f19fa30:	5060006e */ 	beqzl	$v1,.L0f19fbec
/*  f19fa34:	8ec20284 */ 	lw	$v0,0x284($s6)
/*  f19fa38:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f19fa3c:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19fa40:	3c11800b */ 	lui	$s1,%hi(var800ad158)
/*  f19fa44:	006a5823 */ 	subu	$t3,$v1,$t2
/*  f19fa48:	a2ab0464 */ 	sb	$t3,0x464($s5)
/*  f19fa4c:	82a30464 */ 	lb	$v1,0x464($s5)
/*  f19fa50:	2631d158 */ 	addiu	$s1,$s1,%lo(var800ad158)
/*  f19fa54:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19fa58:	1c60000f */ 	bgtz	$v1,.L0f19fa98
/*  f19fa5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fa60:	92a20465 */ 	lbu	$v0,0x465($s5)
/*  f19fa64:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19fa68:	00026142 */ 	srl	$t4,$v0,0x5
/*  f19fa6c:	11810003 */ 	beq	$t4,$at,.L0f19fa7c
/*  f19fa70:	24010003 */ 	addiu	$at,$zero,0x3
/*  f19fa74:	15810008 */ 	bne	$t4,$at,.L0f19fa98
/*  f19fa78:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19fa7c:
/*  f19fa7c:	8ecd0284 */ 	lw	$t5,0x284($s6)
/*  f19fa80:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f19fa84:	91ae0638 */ 	lbu	$t6,0x638($t5)
/*  f19fa88:	126e0003 */ 	beq	$s3,$t6,.L0f19fa98
/*  f19fa8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fa90:	a2b30464 */ 	sb	$s3,0x464($s5)
/*  f19fa94:	82a30464 */ 	lb	$v1,0x464($s5)
.L0f19fa98:
/*  f19fa98:	1c600395 */ 	bgtz	$v1,.L0f1a08f0
/*  f19fa9c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f19faa0:	a2a00464 */ 	sb	$zero,0x464($s5)
/*  f19faa4:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19faa8:
/*  f19faa8:	02602825 */ 	or	$a1,$s3,$zero
/*  f19faac:	50800004 */ 	beqzl	$a0,.L0f19fac0
/*  f19fab0:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fab4:	0fc249af */ 	jal	func0f0926bc
/*  f19fab8:	3406ffff */ 	dli	$a2,0xffff
/*  f19fabc:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f19fac0:
/*  f19fac0:	5611fff9 */ 	bnel	$s0,$s1,.L0f19faa8
/*  f19fac4:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f19fac8:	3c02800b */ 	lui	$v0,0x800b
/*  f19facc:	9042d185 */ 	lbu	$v0,-0x2e7b($v0)
/*  f19fad0:	00027942 */ 	srl	$t7,$v0,0x5
/*  f19fad4:	11e0000b */ 	beqz	$t7,.L0f19fb04
/*  f19fad8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fadc:	11f30010 */ 	beq	$t7,$s3,.L0f19fb20
/*  f19fae0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19fae4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19fae8:	11e10012 */ 	beq	$t7,$at,.L0f19fb34
/*  f19faec:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19faf0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f19faf4:	11e10023 */ 	beq	$t7,$at,.L0f19fb84
/*  f19faf8:	3c048009 */ 	lui	$a0,%hi(menudialog_frtraininginfo2)
/*  f19fafc:	1000037d */ 	beqz	$zero,.L0f1a08f4
/*  f19fb00:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb04:
/*  f19fb04:	0fc69d55 */ 	jal	func0f1a7554
/*  f19fb08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fb0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fb10:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fb14:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fb18:	10000376 */ 	beqz	$zero,.L0f1a08f4
/*  f19fb1c:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb20:
/*  f19fb20:	24848f60 */ 	addiu	$a0,$a0,%lo(menudialog_frtraininginfo2)
/*  f19fb24:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fb28:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fb2c:	10000371 */ 	beqz	$zero,.L0f1a08f4
/*  f19fb30:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb34:
/*  f19fb34:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19fb38:	4481c000 */ 	mtc1	$at,$f24
/*  f19fb3c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f19fb40:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f19fb44:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f19fb48:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f19fb4c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f19fb50:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19fb54:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19fb58:	240505db */ 	addiu	$a1,$zero,0x5db
/*  f19fb5c:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fb60:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19fb64:	0c004241 */ 	jal	func00010904
/*  f19fb68:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f19fb6c:	3c048009 */ 	lui	$a0,%hi(menudialog_frtrainingstats2)
/*  f19fb70:	24849198 */ 	addiu	$a0,$a0,%lo(menudialog_frtrainingstats2)
/*  f19fb74:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fb78:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fb7c:	1000035d */ 	beqz	$zero,.L0f1a08f4
/*  f19fb80:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb84:
/*  f19fb84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19fb88:	4481c000 */ 	mtc1	$at,$f24
/*  f19fb8c:	240affff */ 	addiu	$t2,$zero,-1
/*  f19fb90:	240bffff */ 	addiu	$t3,$zero,-1
/*  f19fb94:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19fb98:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f19fb9c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f19fba0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f19fba4:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19fba8:	240505dc */ 	addiu	$a1,$zero,0x5dc
/*  f19fbac:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fbb0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19fbb4:	0c004241 */ 	jal	func00010904
/*  f19fbb8:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f19fbbc:	3c048009 */ 	lui	$a0,%hi(menudialog_frtrainingstats)
/*  f19fbc0:	2484907c */ 	addiu	$a0,$a0,%lo(menudialog_frtrainingstats)
/*  f19fbc4:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fbc8:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fbcc:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f19fbd0:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f19fbd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f19fbd8:	0fc42539 */ 	jal	func0f1094e4
/*  f19fbdc:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fbe0:	10000344 */ 	beqz	$zero,.L0f1a08f4
/*  f19fbe4:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19fbe8:	8ec20284 */ 	lw	$v0,0x284($s6)
.L0f19fbec:
/*  f19fbec:	3c038009 */ 	lui	$v1,%hi(var8009003c)
/*  f19fbf0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f19fbf4:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f19fbf8:	90638804 */ 	lbu	$v1,-0x77fc($v1)
/*  f19fbfc:	85ae0028 */ 	lh	$t6,0x28($t5)
/*  f19fc00:	11c10024 */ 	beq	$t6,$at,.L0f19fc94
/*  f19fc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fc08:	10600339 */ 	beqz	$v1,.L0f1a08f0
/*  f19fc0c:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19fc10:	3c11800b */ 	lui	$s1,%hi(var800ad158)
/*  f19fc14:	2631d158 */ 	addiu	$s1,$s1,%lo(var800ad158)
/*  f19fc18:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19fc1c:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f19fc20:
/*  f19fc20:	00027fc2 */ 	srl	$t7,$v0,0x1f
/*  f19fc24:	11e0000e */ 	beqz	$t7,.L0f19fc60
/*  f19fc28:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f19fc2c:	0722000d */ 	bltzl	$t9,.L0f19fc64
/*  f19fc30:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fc34:	92090041 */ 	lbu	$t1,0x41($s0)
/*  f19fc38:	5520000a */ 	bnezl	$t1,.L0f19fc64
/*  f19fc3c:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fc40:	920a0043 */ 	lbu	$t2,0x43($s0)
/*  f19fc44:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19fc48:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19fc4c:	11400004 */ 	beqz	$t2,.L0f19fc60
/*  f19fc50:	3406ffff */ 	dli	$a2,0xffff
/*  f19fc54:	a20b0041 */ 	sb	$t3,0x41($s0)
/*  f19fc58:	0fc249af */ 	jal	func0f0926bc
/*  f19fc5c:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19fc60:
/*  f19fc60:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f19fc64:
/*  f19fc64:	5611ffee */ 	bnel	$s0,$s1,.L0f19fc20
/*  f19fc68:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f19fc6c:	3c02800a */ 	lui	$v0,0x800a
/*  f19fc70:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f19fc74:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f19fc78:	0fc67b37 */ 	jal	func0f19ecdc
/*  f19fc7c:	ac401c08 */ 	sw	$zero,0x1c08($v0)
/*  f19fc80:	00002025 */ 	or	$a0,$zero,$zero
/*  f19fc84:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f19fc88:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19fc8c:	10000319 */ 	beqz	$zero,.L0f1a08f4
/*  f19fc90:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fc94:
/*  f19fc94:	50600317 */ 	beqzl	$v1,.L0f1a08f4
/*  f19fc98:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19fc9c:	8c4c00d8 */ 	lw	$t4,0xd8($v0)
/*  f19fca0:	51800004 */ 	beqzl	$t4,.L0f19fcb4
/*  f19fca4:	8ecd0034 */ 	lw	$t5,0x34($s6)
/*  f19fca8:	0fc67b37 */ 	jal	func0f19ecdc
/*  f19fcac:	00002025 */ 	or	$a0,$zero,$zero
/*  f19fcb0:	8ecd0034 */ 	lw	$t5,0x34($s6)
.L0f19fcb4:
/*  f19fcb4:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19fcb8:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19fcbc:	15a00018 */ 	bnez	$t5,.L0f19fd20
/*  f19fcc0:	3c11800b */ 	lui	$s1,%hi(var800ad158)
/*  f19fcc4:	2631d158 */ 	addiu	$s1,$s1,%lo(var800ad158)
/*  f19fcc8:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f19fccc:
/*  f19fccc:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19fcd0:	11c0000e */ 	beqz	$t6,.L0f19fd0c
/*  f19fcd4:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19fcd8:	0702000d */ 	bltzl	$t8,.L0f19fd10
/*  f19fcdc:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fce0:	92190041 */ 	lbu	$t9,0x41($s0)
/*  f19fce4:	5720000a */ 	bnezl	$t9,.L0f19fd10
/*  f19fce8:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fcec:	92090043 */ 	lbu	$t1,0x43($s0)
/*  f19fcf0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f19fcf4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19fcf8:	11200004 */ 	beqz	$t1,.L0f19fd0c
/*  f19fcfc:	3406ffff */ 	dli	$a2,0xffff
/*  f19fd00:	a20a0041 */ 	sb	$t2,0x41($s0)
/*  f19fd04:	0fc249af */ 	jal	func0f0926bc
/*  f19fd08:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19fd0c:
/*  f19fd0c:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f19fd10:
/*  f19fd10:	5611ffee */ 	bnel	$s0,$s1,.L0f19fccc
/*  f19fd14:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f19fd18:	100002f6 */ 	beqz	$zero,.L0f1a08f4
/*  f19fd1c:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fd20:
/*  f19fd20:	8ecc0284 */ 	lw	$t4,0x284($s6)
/*  f19fd24:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19fd28:	0fc677d6 */ 	jal	func0f19df58
/*  f19fd2c:	ad8b1c08 */ 	sw	$t3,0x1c08($t4)
/*  f19fd30:	92ad045a */ 	lbu	$t5,0x45a($s5)
/*  f19fd34:	51a0004b */ 	beqzl	$t5,.L0f19fe64
/*  f19fd38:	8eab044c */ 	lw	$t3,0x44c($s5)
/*  f19fd3c:	0fc6749a */ 	jal	func0f19d268
/*  f19fd40:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19fd44:	00409025 */ 	or	$s2,$v0,$zero
/*  f19fd48:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fd4c:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19fd50:	00002825 */ 	or	$a1,$zero,$zero
/*  f19fd54:	00408825 */ 	or	$s1,$v0,$zero
/*  f19fd58:	0fc2a63d */ 	jal	func0f0a98f4
/*  f19fd5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fd60:	00408025 */ 	or	$s0,$v0,$zero
/*  f19fd64:	02402025 */ 	or	$a0,$s2,$zero
/*  f19fd68:	0fc2c47b */ 	jal	func0f0b11ec
/*  f19fd6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f19fd70:	10400003 */ 	beqz	$v0,.L0f19fd80
/*  f19fd74:	00001825 */ 	or	$v1,$zero,$zero
/*  f19fd78:	10000001 */ 	beqz	$zero,.L0f19fd80
/*  f19fd7c:	84430008 */ 	lh	$v1,0x8($v0)
.L0f19fd80:
/*  f19fd80:	86a20476 */ 	lh	$v0,0x476($s5)
/*  f19fd84:	02038023 */ 	subu	$s0,$s0,$v1
/*  f19fd88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19fd8c:	18400011 */ 	blez	$v0,.L0f19fdd4
/*  f19fd90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fd94:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19fd98:	02202025 */ 	or	$a0,$s1,$zero
/*  f19fd9c:	92a3045a */ 	lbu	$v1,0x45a($s5)
/*  f19fda0:	86ae0476 */ 	lh	$t6,0x476($s5)
/*  f19fda4:	00403025 */ 	or	$a2,$v0,$zero
/*  f19fda8:	00662821 */ 	addu	$a1,$v1,$a2
/*  f19fdac:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f19fdb0:	a6af0476 */ 	sh	$t7,0x476($s5)
/*  f19fdb4:	86b80476 */ 	lh	$t8,0x476($s5)
/*  f19fdb8:	07010002 */ 	bgez	$t8,.L0f19fdc4
/*  f19fdbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fdc0:	a6a00476 */ 	sh	$zero,0x476($s5)
.L0f19fdc4:
/*  f19fdc4:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19fdc8:	02202025 */ 	or	$a0,$s1,$zero
/*  f19fdcc:	10000006 */ 	beqz	$zero,.L0f19fde8
/*  f19fdd0:	24010012 */ 	addiu	$at,$zero,0x12
.L0f19fdd4:
/*  f19fdd4:	14410003 */ 	bne	$v0,$at,.L0f19fde4
/*  f19fdd8:	02202025 */ 	or	$a0,$s1,$zero
/*  f19fddc:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19fde0:	02002825 */ 	or	$a1,$s0,$zero
.L0f19fde4:
/*  f19fde4:	24010012 */ 	addiu	$at,$zero,0x12
.L0f19fde8:
/*  f19fde8:	5641001d */ 	bnel	$s2,$at,.L0f19fe60
/*  f19fdec:	a2a0045a */ 	sb	$zero,0x45a($s5)
/*  f19fdf0:	0fc2a63d */ 	jal	func0f0a98f4
/*  f19fdf4:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fdf8:	86a30478 */ 	lh	$v1,0x478($s5)
/*  f19fdfc:	00408025 */ 	or	$s0,$v0,$zero
/*  f19fe00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19fe04:	18600011 */ 	blez	$v1,.L0f19fe4c
/*  f19fe08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fe0c:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19fe10:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fe14:	92a3045a */ 	lbu	$v1,0x45a($s5)
/*  f19fe18:	86b90478 */ 	lh	$t9,0x478($s5)
/*  f19fe1c:	00403025 */ 	or	$a2,$v0,$zero
/*  f19fe20:	00662821 */ 	addu	$a1,$v1,$a2
/*  f19fe24:	03234823 */ 	subu	$t1,$t9,$v1
/*  f19fe28:	a6a90478 */ 	sh	$t1,0x478($s5)
/*  f19fe2c:	86aa0478 */ 	lh	$t2,0x478($s5)
/*  f19fe30:	05410002 */ 	bgez	$t2,.L0f19fe3c
/*  f19fe34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19fe38:	a6a00478 */ 	sh	$zero,0x478($s5)
.L0f19fe3c:
/*  f19fe3c:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19fe40:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fe44:	10000006 */ 	beqz	$zero,.L0f19fe60
/*  f19fe48:	a2a0045a */ 	sb	$zero,0x45a($s5)
.L0f19fe4c:
/*  f19fe4c:	14610003 */ 	bne	$v1,$at,.L0f19fe5c
/*  f19fe50:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fe54:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f19fe58:	02002825 */ 	or	$a1,$s0,$zero
.L0f19fe5c:
/*  f19fe5c:	a2a0045a */ 	sb	$zero,0x45a($s5)
.L0f19fe60:
/*  f19fe60:	8eab044c */ 	lw	$t3,0x44c($s5)
.L0f19fe64:
/*  f19fe64:	8ecc0038 */ 	lw	$t4,0x38($s6)
/*  f19fe68:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f19fe6c:	05a10032 */ 	bgez	$t5,.L0f19ff38
/*  f19fe70:	aead044c */ 	sw	$t5,0x44c($s5)
/*  f19fe74:	96ae0458 */ 	lhu	$t6,0x458($s5)
/*  f19fe78:	55c00026 */ 	bnezl	$t6,.L0f19ff14
/*  f19fe7c:	8eb90464 */ 	lw	$t9,0x464($s5)
/*  f19fe80:	8ea30464 */ 	lw	$v1,0x464($s5)
/*  f19fe84:	29a1ff4d */ 	slti	$at,$t5,-179
/*  f19fe88:	0003c300 */ 	sll	$t8,$v1,0xc
/*  f19fe8c:	07020016 */ 	bltzl	$t8,.L0f19fee8
/*  f19fe90:	00037ac0 */ 	sll	$t7,$v1,0xb
/*  f19fe94:	14200013 */ 	bnez	$at,.L0f19fee4
/*  f19fe98:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19fe9c:	92a90465 */ 	lbu	$t1,0x465($s5)
/*  f19fea0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19fea4:	4481c000 */ 	mtc1	$at,$f24
/*  f19fea8:	352a0008 */ 	ori	$t2,$t1,0x8
/*  f19feac:	a2aa0465 */ 	sb	$t2,0x465($s5)
/*  f19feb0:	240bffff */ 	addiu	$t3,$zero,-1
/*  f19feb4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19feb8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19febc:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19fec0:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f19fec4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f19fec8:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19fecc:	240505d4 */ 	addiu	$a1,$zero,0x5d4
/*  f19fed0:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fed4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19fed8:	0c004241 */ 	jal	func00010904
/*  f19fedc:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f19fee0:	8ea30464 */ 	lw	$v1,0x464($s5)
.L0f19fee4:
/*  f19fee4:	00037ac0 */ 	sll	$t7,$v1,0xb
.L0f19fee8:
/*  f19fee8:	05e20282 */ 	bltzl	$t7,.L0f1a08f4
/*  f19feec:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19fef0:	8eb8044c */ 	lw	$t8,0x44c($s5)
/*  f19fef4:	2b01ff20 */ 	slti	$at,$t8,-224
/*  f19fef8:	5420027e */ 	bnezl	$at,.L0f1a08f4
/*  f19fefc:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19ff00:	0fc674ce */ 	jal	func0f19d338
/*  f19ff04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ff08:	1000027a */ 	beqz	$zero,.L0f1a08f4
/*  f19ff0c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19ff10:	8eb90464 */ 	lw	$t9,0x464($s5)
.L0f19ff14:
/*  f19ff14:	001952c0 */ 	sll	$t2,$t9,0xb
/*  f19ff18:	05420004 */ 	bltzl	$t2,.L0f19ff2c
/*  f19ff1c:	92ac0465 */ 	lbu	$t4,0x465($s5)
/*  f19ff20:	0fc674ce */ 	jal	func0f19d338
/*  f19ff24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ff28:	92ac0465 */ 	lbu	$t4,0x465($s5)
.L0f19ff2c:
/*  f19ff2c:	aea0044c */ 	sw	$zero,0x44c($s5)
/*  f19ff30:	358d0008 */ 	ori	$t5,$t4,0x8
/*  f19ff34:	a2ad0465 */ 	sb	$t5,0x465($s5)
.L0f19ff38:
/*  f19ff38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19ff3c:	4481c000 */ 	mtc1	$at,$f24
/*  f19ff40:	3c017f1c */ 	lui	$at,%hi(var7f1b94c0)
/*  f19ff44:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f19ff48:	3c14800b */ 	lui	$s4,%hi(var800ad158)
/*  f19ff4c:	4480b000 */ 	mtc1	$zero,$f22
/*  f19ff50:	2694d158 */ 	addiu	$s4,$s4,%lo(var800ad158)
/*  f19ff54:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f19ff58:	c43494c0 */ 	lwc1	$f20,%lo(var7f1b94c0)($at)
/*  f19ff5c:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f19ff60:
/*  f19ff60:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19ff64:	11c000d5 */ 	beqz	$t6,.L0f1a02bc
/*  f19ff68:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19ff6c:	070000d3 */ 	bltz	$t8,.L0f1a02bc
/*  f19ff70:	00024840 */ 	sll	$t1,$v0,0x1
/*  f19ff74:	052100d1 */ 	bgez	$t1,.L0f1a02bc
/*  f19ff78:	00009025 */ 	or	$s2,$zero,$zero
/*  f19ff7c:	a3a00123 */ 	sb	$zero,0x123($sp)
/*  f19ff80:	0fc6749a */ 	jal	func0f19d268
/*  f19ff84:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19ff88:	8e110014 */ 	lw	$s1,0x14($s0)
/*  f19ff8c:	304300ff */ 	andi	$v1,$v0,0xff
/*  f19ff90:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19ff94:	10610003 */ 	beq	$v1,$at,.L0f19ffa4
/*  f19ff98:	8e330004 */ 	lw	$s3,0x4($s1)
/*  f19ff9c:	24010021 */ 	addiu	$at,$zero,0x21
/*  f19ffa0:	14610003 */ 	bne	$v1,$at,.L0f19ffb0
.L0f19ffa4:
/*  f19ffa4:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f19ffa8:	0fc22af5 */ 	jal	func0f08abd4
/*  f19ffac:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f19ffb0:
/*  f19ffb0:	920a0043 */ 	lbu	$t2,0x43($s0)
/*  f19ffb4:	5140001c */ 	beqzl	$t2,.L0f1a0028
/*  f19ffb8:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f19ffbc:	920b0041 */ 	lbu	$t3,0x41($s0)
/*  f19ffc0:	51600019 */ 	beqzl	$t3,.L0f1a0028
/*  f19ffc4:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f19ffc8:	c604002c */ 	lwc1	$f4,0x2c($s0)
/*  f19ffcc:	00002025 */ 	or	$a0,$zero,$zero
/*  f19ffd0:	240605d9 */ 	addiu	$a2,$zero,0x5d9
/*  f19ffd4:	4604c032 */ 	c.eq.s	$f24,$f4
/*  f19ffd8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19ffdc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19ffe0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19ffe4:	45030010 */ 	bc1tl	.L0f1a0028
/*  f19ffe8:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f19ffec:	a2000041 */ 	sb	$zero,0x41($s0)
/*  f19fff0:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f19fff4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f19fff8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19fffc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a0000:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1a0004:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1a0008:	e7b80024 */ 	swc1	$f24,0x24($sp)
/*  f1a000c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a0010:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f1a0014:	e7b80030 */ 	swc1	$f24,0x30($sp)
/*  f1a0018:	e7b80034 */ 	swc1	$f24,0x34($sp)
/*  f1a001c:	0fc24e7e */ 	jal	func0f0939f8
/*  f1a0020:	e7b80038 */ 	swc1	$f24,0x38($sp)
/*  f1a0024:	c6000038 */ 	lwc1	$f0,0x38($s0)
.L0f1a0028:
/*  f1a0028:	3c017f1c */ 	lui	$at,%hi(var7f1b94c4)
/*  f1a002c:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1a0030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0034:	45020008 */ 	bc1fl	.L0f1a0058
/*  f1a0038:	920e0040 */ 	lbu	$t6,0x40($s0)
/*  f1a003c:	c42694c4 */ 	lwc1	$f6,%lo(var7f1b94c4)($at)
/*  f1a0040:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1a0044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0048:	45020003 */ 	bc1fl	.L0f1a0058
/*  f1a004c:	920e0040 */ 	lbu	$t6,0x40($s0)
/*  f1a0050:	a660004c */ 	sh	$zero,0x4c($s3)
/*  f1a0054:	920e0040 */ 	lbu	$t6,0x40($s0)
.L0f1a0058:
/*  f1a0058:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f1a005c:	51e0000a */ 	beqzl	$t7,.L0f1a0088
/*  f1a0060:	8662004c */ 	lh	$v0,0x4c($s3)
/*  f1a0064:	8e020048 */ 	lw	$v0,0x48($s0)
/*  f1a0068:	2841012c */ 	slti	$at,$v0,0x12c
/*  f1a006c:	50200006 */ 	beqzl	$at,.L0f1a0088
/*  f1a0070:	8662004c */ 	lh	$v0,0x4c($s3)
/*  f1a0074:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f1a0078:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f1a007c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f1a0080:	ae190048 */ 	sw	$t9,0x48($s0)
/*  f1a0084:	8662004c */ 	lh	$v0,0x4c($s3)
.L0f1a0088:
/*  f1a0088:	58400025 */ 	blezl	$v0,.L0f1a0120
/*  f1a008c:	93aa0123 */ 	lbu	$t2,0x123($sp)
/*  f1a0090:	16400007 */ 	bnez	$s2,.L0f1a00b0
/*  f1a0094:	3c017f1c */ 	lui	$at,%hi(var7f1b94c8)
/*  f1a0098:	c42894c8 */ 	lwc1	$f8,%lo(var7f1b94c8)($at)
/*  f1a009c:	c60a0038 */ 	lwc1	$f10,0x38($s0)
/*  f1a00a0:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f1a00a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a00a8:	45020004 */ 	bc1fl	.L0f1a00bc
/*  f1a00ac:	92090040 */ 	lbu	$t1,0x40($s0)
.L0f1a00b0:
/*  f1a00b0:	1000001a */ 	beqz	$zero,.L0f1a011c
/*  f1a00b4:	a660004c */ 	sh	$zero,0x4c($s3)
/*  f1a00b8:	92090040 */ 	lbu	$t1,0x40($s0)
.L0f1a00bc:
/*  f1a00bc:	312a0020 */ 	andi	$t2,$t1,0x20
/*  f1a00c0:	5540000b */ 	bnezl	$t2,.L0f1a00f0
/*  f1a00c4:	96ac045c */ 	lhu	$t4,0x45c($s5)
/*  f1a00c8:	866b004e */ 	lh	$t3,0x4e($s3)
/*  f1a00cc:	004b082a */ 	slt	$at,$v0,$t3
/*  f1a00d0:	50200007 */ 	beqzl	$at,.L0f1a00f0
/*  f1a00d4:	96ac045c */ 	lhu	$t4,0x45c($s5)
/*  f1a00d8:	0fc6749a */ 	jal	func0f19d268
/*  f1a00dc:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f1a00e0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1a00e4:	5441000e */ 	bnel	$v0,$at,.L0f1a0120
/*  f1a00e8:	93aa0123 */ 	lbu	$t2,0x123($sp)
/*  f1a00ec:	96ac045c */ 	lhu	$t4,0x45c($s5)
.L0f1a00f0:
/*  f1a00f0:	8eae0450 */ 	lw	$t6,0x450($s5)
/*  f1a00f4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1a00f8:	2419003c */ 	addiu	$t9,$zero,0x3c
/*  f1a00fc:	2409000b */ 	addiu	$t1,$zero,0xb
/*  f1a0100:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1a0104:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f1a0108:	a6ad045c */ 	sh	$t5,0x45c($s5)
/*  f1a010c:	aeaf0450 */ 	sw	$t7,0x450($s5)
/*  f1a0110:	a3b80123 */ 	sb	$t8,0x123($sp)
/*  f1a0114:	a2b90472 */ 	sb	$t9,0x472($s5)
/*  f1a0118:	a2a90471 */ 	sb	$t1,0x471($s5)
.L0f1a011c:
/*  f1a011c:	93aa0123 */ 	lbu	$t2,0x123($sp)
.L0f1a0120:
/*  f1a0120:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a0124:	26320008 */ 	addiu	$s2,$s1,0x8
/*  f1a0128:	15400009 */ 	bnez	$t2,.L0f1a0150
/*  f1a012c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0130:	92020011 */ 	lbu	$v0,0x11($s0)
/*  f1a0134:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a0138:	10410060 */ 	beq	$v0,$at,.L0f1a02bc
/*  f1a013c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0140:	920b0030 */ 	lbu	$t3,0x30($s0)
/*  f1a0144:	0162082a */ 	slt	$at,$t3,$v0
/*  f1a0148:	1420005c */ 	bnez	$at,.L0f1a02bc
/*  f1a014c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a0150:
/*  f1a0150:	0fc1a2bd */ 	jal	func0f068af4
/*  f1a0154:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a0158:	3c038009 */ 	lui	$v1,%hi(var8009003c)
/*  f1a015c:	9063880c */ 	lbu	$v1,-0x77f4($v1)
/*  f1a0160:	00404025 */ 	or	$t0,$v0,$zero
/*  f1a0164:	5060000d */ 	beqzl	$v1,.L0f1a019c
/*  f1a0168:	c5100004 */ 	lwc1	$f16,0x4($t0)
/*  f1a016c:	920c0043 */ 	lbu	$t4,0x43($s0)
/*  f1a0170:	246dffff */ 	addiu	$t5,$v1,-1
/*  f1a0174:	3c018009 */ 	lui	$at,0x8009
/*  f1a0178:	11800007 */ 	beqz	$t4,.L0f1a0198
/*  f1a017c:	02202025 */ 	or	$a0,$s1,$zero
/*  f1a0180:	a02d880c */ 	sb	$t5,-0x77f4($at)
/*  f1a0184:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a0188:	3406ffff */ 	dli	$a2,0xffff
/*  f1a018c:	0fc249af */ 	jal	func0f0926bc
/*  f1a0190:	afa20118 */ 	sw	$v0,0x118($sp)
/*  f1a0194:	8fa80118 */ 	lw	$t0,0x118($sp)
.L0f1a0198:
/*  f1a0198:	c5100004 */ 	lwc1	$f16,0x4($t0)
.L0f1a019c:
/*  f1a019c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f1a01a0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a01a4:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f1a01a8:	c5120008 */ 	lwc1	$f18,0x8($t0)
/*  f1a01ac:	2665001c */ 	addiu	$a1,$s3,0x1c
/*  f1a01b0:	26660028 */ 	addiu	$a2,$s3,0x28
/*  f1a01b4:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f1a01b8:	c504000c */ 	lwc1	$f4,0xc($t0)
/*  f1a01bc:	26670034 */ 	addiu	$a3,$s3,0x34
/*  f1a01c0:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*  f1a01c4:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f1a01c8:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1a01cc:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f1a01d0:	0fc54208 */ 	jal	func0f150820
/*  f1a01d4:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f1a01d8:	92af0455 */ 	lbu	$t7,0x455($s5)
/*  f1a01dc:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1a01e0:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f1a01e4:	a2b80455 */ 	sb	$t8,0x455($s5)
/*  f1a01e8:	92190040 */ 	lbu	$t9,0x40($s0)
/*  f1a01ec:	33290020 */ 	andi	$t1,$t9,0x20
/*  f1a01f0:	51200008 */ 	beqzl	$t1,.L0f1a0214
/*  f1a01f4:	920b0010 */ 	lbu	$t3,0x10($s0)
/*  f1a01f8:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f1a01fc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1a0200:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a0204:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f1a0208:	0fc4a640 */ 	jal	func0f129900
/*  f1a020c:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f1a0210:	920b0010 */ 	lbu	$t3,0x10($s0)
.L0f1a0214:
/*  f1a0214:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f1a0218:	3c010008 */ 	lui	$at,0x8
/*  f1a021c:	316effbf */ 	andi	$t6,$t3,0xffbf
/*  f1a0220:	a20e0010 */ 	sb	$t6,0x10($s0)
/*  f1a0224:	35cf0020 */ 	ori	$t7,$t6,0x20
/*  f1a0228:	a20f0010 */ 	sb	$t7,0x10($s0)
/*  f1a022c:	8e78000c */ 	lw	$t8,0xc($s3)
/*  f1a0230:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a0234:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a0238:	0301c825 */ 	or	$t9,$t8,$at
/*  f1a023c:	ae79000c */ 	sw	$t9,0xc($s3)
/*  f1a0240:	e6360008 */ 	swc1	$f22,0x8($s1)
/*  f1a0244:	3c017f1c */ 	lui	$at,%hi(var7f1b94cc)
/*  f1a0248:	c42894cc */ 	lwc1	$f8,%lo(var7f1b94cc)($at)
/*  f1a024c:	e6360010 */ 	swc1	$f22,0x10($s1)
/*  f1a0250:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a0254:	0fc1a71c */ 	jal	func0f069c70
/*  f1a0258:	e628000c */ 	swc1	$f8,0xc($s1)
/*  f1a025c:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f1a0260:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
/*  f1a0264:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f1a0268:
/*  f1a0268:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1a026c:	05400010 */ 	bltz	$t2,.L0f1a02b0
/*  f1a0270:	00025fc2 */ 	srl	$t3,$v0,0x1f
/*  f1a0274:	1160000e */ 	beqz	$t3,.L0f1a02b0
/*  f1a0278:	00026840 */ 	sll	$t5,$v0,0x1
/*  f1a027c:	05a2000d */ 	bltzl	$t5,.L0f1a02b4
/*  f1a0280:	2463003c */ 	addiu	$v1,$v1,%lo(var8009003c)
/*  f1a0284:	8c6e0014 */ 	lw	$t6,0x14($v1)
/*  f1a0288:	90780010 */ 	lbu	$t8,0x10($v1)
/*  f1a028c:	3c01fff7 */ 	lui	$at,0xfff7
/*  f1a0290:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f1a0294:	37190040 */ 	ori	$t9,$t8,0x40
/*  f1a0298:	a0790010 */ 	sb	$t9,0x10($v1)
/*  f1a029c:	8c49000c */ 	lw	$t1,0xc($v0)
/*  f1a02a0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1a02a4:	01215024 */ 	and	$t2,$t1,$at
/*  f1a02a8:	10000004 */ 	beqz	$zero,.L0f1a02bc
/*  f1a02ac:	ac4a000c */ 	sw	$t2,0xc($v0)
.L0f1a02b0:
/*  f1a02b0:	2463003c */ 	addiu	$v1,$v1,%lo(var8009003c)
.L0f1a02b4:
/*  f1a02b4:	5474ffec */ 	bnel	$v1,$s4,.L0f1a0268
/*  f1a02b8:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f1a02bc:
/*  f1a02bc:	3c0b800b */ 	lui	$t3,%hi(var800ad158)
/*  f1a02c0:	256bd158 */ 	addiu	$t3,$t3,%lo(var800ad158)
/*  f1a02c4:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f1a02c8:	020b082b */ 	sltu	$at,$s0,$t3
/*  f1a02cc:	5420ff24 */ 	bnezl	$at,.L0f19ff60
/*  f1a02d0:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f1a02d4:	92a30004 */ 	lbu	$v1,0x4($s5)
/*  f1a02d8:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a02dc:	5461000f */ 	bnel	$v1,$at,.L0f1a031c
/*  f1a02e0:	92a20455 */ 	lbu	$v0,0x455($s5)
/*  f1a02e4:	96a20002 */ 	lhu	$v0,0x2($s5)
/*  f1a02e8:	10400009 */ 	beqz	$v0,.L0f1a0310
/*  f1a02ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a02f0:	8eac0450 */ 	lw	$t4,0x450($s5)
/*  f1a02f4:	0182082a */ 	slt	$at,$t4,$v0
/*  f1a02f8:	14200005 */ 	bnez	$at,.L0f1a0310
/*  f1a02fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0300:	0fc67c63 */ 	jal	func0f19f18c
/*  f1a0304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0308:	1000017a */ 	beqz	$zero,.L0f1a08f4
/*  f1a030c:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a0310:
/*  f1a0310:	10000010 */ 	beqz	$zero,.L0f1a0354
/*  f1a0314:	92a20455 */ 	lbu	$v0,0x455($s5)
/*  f1a0318:	92a20455 */ 	lbu	$v0,0x455($s5)
.L0f1a031c:
/*  f1a031c:	0043082a */ 	slt	$at,$v0,$v1
/*  f1a0320:	5420000d */ 	bnezl	$at,.L0f1a0358
/*  f1a0324:	92ae0454 */ 	lbu	$t6,0x454($s5)
/*  f1a0328:	96a30002 */ 	lhu	$v1,0x2($s5)
/*  f1a032c:	10600005 */ 	beqz	$v1,.L0f1a0344
/*  f1a0330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0334:	8ead0450 */ 	lw	$t5,0x450($s5)
/*  f1a0338:	01a3082a */ 	slt	$at,$t5,$v1
/*  f1a033c:	54200006 */ 	bnezl	$at,.L0f1a0358
/*  f1a0340:	92ae0454 */ 	lbu	$t6,0x454($s5)
.L0f1a0344:
/*  f1a0344:	0fc67c63 */ 	jal	func0f19f18c
/*  f1a0348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a034c:	10000169 */ 	beqz	$zero,.L0f1a08f4
/*  f1a0350:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a0354:
/*  f1a0354:	92ae0454 */ 	lbu	$t6,0x454($s5)
.L0f1a0358:
/*  f1a0358:	004e082a */ 	slt	$at,$v0,$t6
/*  f1a035c:	14200005 */ 	bnez	$at,.L0f1a0374
/*  f1a0360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0364:	0fc67c49 */ 	jal	func0f19f124
/*  f1a0368:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f1a036c:	10000161 */ 	beqz	$zero,.L0f1a08f4
/*  f1a0370:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a0374:
/*  f1a0374:	0fc67d49 */ 	jal	func0f19f524
/*  f1a0378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a037c:	50400006 */ 	beqzl	$v0,.L0f1a0398
/*  f1a0380:	92a20005 */ 	lbu	$v0,0x5($s5)
/*  f1a0384:	0fc67c49 */ 	jal	func0f19f124
/*  f1a0388:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1a038c:	10000159 */ 	beqz	$zero,.L0f1a08f4
/*  f1a0390:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f1a0394:	92a20005 */ 	lbu	$v0,0x5($s5)
.L0f1a0398:
/*  f1a0398:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a039c:	00009025 */ 	or	$s2,$zero,$zero
/*  f1a03a0:	1041000b */ 	beq	$v0,$at,.L0f1a03d0
/*  f1a03a4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f1a03a8:	8eaf044c */ 	lw	$t7,0x44c($s5)
/*  f1a03ac:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f1a03b0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1a03b4:	01f8082a */ 	slt	$at,$t7,$t8
/*  f1a03b8:	14200005 */ 	bnez	$at,.L0f1a03d0
/*  f1a03bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a03c0:	0fc67c49 */ 	jal	func0f19f124
/*  f1a03c4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1a03c8:	1000014a */ 	beqz	$zero,.L0f1a08f4
/*  f1a03cc:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a03d0:
/*  f1a03d0:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f1a03d4:	3c017f1c */ 	lui	$at,%hi(var7f1b94d0)
/*  f1a03d8:	c43494d0 */ 	lwc1	$f20,%lo(var7f1b94d0)($at)
/*  f1a03dc:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f1a03e0:	27b50098 */ 	addiu	$s5,$sp,0x98
/*  f1a03e4:	27b400bc */ 	addiu	$s4,$sp,0xbc
.L0f1a03e8:
/*  f1a03e8:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f1a03ec:	0002cfc2 */ 	srl	$t9,$v0,0x1f
/*  f1a03f0:	1320013b */ 	beqz	$t9,.L0f1a08e0
/*  f1a03f4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1a03f8:	05400139 */ 	bltz	$t2,.L0f1a08e0
/*  f1a03fc:	00026040 */ 	sll	$t4,$v0,0x1
/*  f1a0400:	05830138 */ 	bgezl	$t4,.L0f1a08e4
/*  f1a0404:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a0408:	920d0043 */ 	lbu	$t5,0x43($s0)
/*  f1a040c:	8e110014 */ 	lw	$s1,0x14($s0)
/*  f1a0410:	11a00089 */ 	beqz	$t5,.L0f1a0638
/*  f1a0414:	8e330004 */ 	lw	$s3,0x4($s1)
/*  f1a0418:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*  f1a041c:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a0420:	44817000 */ 	mtc1	$at,$f14
/*  f1a0424:	460ac032 */ 	c.eq.s	$f24,$f10
/*  f1a0428:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a042c:	3c01c000 */ 	lui	$at,0xc000
/*  f1a0430:	45020006 */ 	bc1fl	.L0f1a044c
/*  f1a0434:	c6100018 */ 	lwc1	$f16,0x18($s0)
/*  f1a0438:	44816000 */ 	mtc1	$at,$f12
/*  f1a043c:	a20e0042 */ 	sb	$t6,0x42($s0)
/*  f1a0440:	10000043 */ 	beqz	$zero,.L0f1a0550
/*  f1a0444:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f1a0448:	c6100018 */ 	lwc1	$f16,0x18($s0)
.L0f1a044c:
/*  f1a044c:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f1a0450:	c606001c */ 	lwc1	$f6,0x1c($s0)
/*  f1a0454:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f1a0458:	c6100020 */ 	lwc1	$f16,0x20($s0)
/*  f1a045c:	e7a40158 */ 	swc1	$f4,0x158($sp)
/*  f1a0460:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f1a0464:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f1a0468:	c7a60158 */ 	lwc1	$f6,0x158($sp)
/*  f1a046c:	e7aa015c */ 	swc1	$f10,0x15c($sp)
/*  f1a0470:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f1a0474:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f1a0478:	c7aa015c */ 	lwc1	$f10,0x15c($sp)
/*  f1a047c:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f1a0480:	e7ae0110 */ 	swc1	$f14,0x110($sp)
/*  f1a0484:	460a5402 */ 	mul.s	$f16,$f10,$f10
/*  f1a0488:	e7a40160 */ 	swc1	$f4,0x160($sp)
/*  f1a048c:	c7a40160 */ 	lwc1	$f4,0x160($sp)
/*  f1a0490:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f1a0494:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f1a0498:	0c012974 */ 	jal	sqrtf
/*  f1a049c:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f1a04a0:	46160032 */ 	c.eq.s	$f0,$f22
/*  f1a04a4:	c7ae0110 */ 	lwc1	$f14,0x110($sp)
/*  f1a04a8:	46000306 */ 	mov.s	$f12,$f0
/*  f1a04ac:	3c01c000 */ 	lui	$at,0xc000
/*  f1a04b0:	45030026 */ 	bc1tl	.L0f1a054c
/*  f1a04b4:	44816000 */ 	mtc1	$at,$f12
/*  f1a04b8:	3c013e80 */ 	lui	$at,0x3e80
/*  f1a04bc:	44813000 */ 	mtc1	$at,$f6
/*  f1a04c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a04c4:	44819000 */ 	mtc1	$at,$f18
/*  f1a04c8:	8ecf0034 */ 	lw	$t7,0x34($s6)
/*  f1a04cc:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*  f1a04d0:	46009083 */ 	div.s	$f2,$f18,$f0
/*  f1a04d4:	448f4000 */ 	mtc1	$t7,$f8
/*  f1a04d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a04dc:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f1a04e0:	c7a80158 */ 	lwc1	$f8,0x158($sp)
/*  f1a04e4:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f1a04e8:	c7b0015c */ 	lwc1	$f16,0x15c($sp)
/*  f1a04ec:	46062382 */ 	mul.s	$f14,$f4,$f6
/*  f1a04f0:	c7a60160 */ 	lwc1	$f6,0x160($sp)
/*  f1a04f4:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1a04f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a04fc:	46028102 */ 	mul.s	$f4,$f16,$f2
/*  f1a0500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0504:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f1a0508:	e7aa0158 */ 	swc1	$f10,0x158($sp)
/*  f1a050c:	460e5202 */ 	mul.s	$f8,$f10,$f14
/*  f1a0510:	e7a4015c */ 	swc1	$f4,0x15c($sp)
/*  f1a0514:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f1a0518:	e7b20160 */ 	swc1	$f18,0x160($sp)
/*  f1a051c:	c6300008 */ 	lwc1	$f16,0x8($s1)
/*  f1a0520:	46104180 */ 	add.s	$f6,$f8,$f16
/*  f1a0524:	e7a6014c */ 	swc1	$f6,0x14c($sp)
/*  f1a0528:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f1a052c:	460e9182 */ 	mul.s	$f6,$f18,$f14
/*  f1a0530:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f1a0534:	e7b00150 */ 	swc1	$f16,0x150($sp)
/*  f1a0538:	c6240010 */ 	lwc1	$f4,0x10($s1)
/*  f1a053c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f1a0540:	10000003 */ 	beqz	$zero,.L0f1a0550
/*  f1a0544:	e7aa0154 */ 	swc1	$f10,0x154($sp)
/*  f1a0548:	44816000 */ 	mtc1	$at,$f12
.L0f1a054c:
/*  f1a054c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a0550:
/*  f1a0550:	460e603e */ 	c.le.s	$f12,$f14
/*  f1a0554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0558:	4502002d */ 	bc1fl	.L0f1a0610
/*  f1a055c:	c7a6014c */ 	lwc1	$f6,0x14c($sp)
/*  f1a0560:	92190010 */ 	lbu	$t9,0x10($s0)
/*  f1a0564:	920a0042 */ 	lbu	$t2,0x42($s0)
/*  f1a0568:	c6080018 */ 	lwc1	$f8,0x18($s0)
/*  f1a056c:	c610001c */ 	lwc1	$f16,0x1c($s0)
/*  f1a0570:	c6120020 */ 	lwc1	$f18,0x20($s0)
/*  f1a0574:	37290010 */ 	ori	$t1,$t9,0x10
/*  f1a0578:	a2090010 */ 	sb	$t1,0x10($s0)
/*  f1a057c:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f1a0580:	e7a8014c */ 	swc1	$f8,0x14c($sp)
/*  f1a0584:	e7b00150 */ 	swc1	$f16,0x150($sp)
/*  f1a0588:	15400020 */ 	bnez	$t2,.L0f1a060c
/*  f1a058c:	e7b20154 */ 	swc1	$f18,0x154($sp)
/*  f1a0590:	3c028009 */ 	lui	$v0,%hi(var8008880c)
/*  f1a0594:	2442880c */ 	addiu	$v0,$v0,%lo(var8008880c)
/*  f1a0598:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1a059c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1a05a0:	a20b0042 */ 	sb	$t3,0x42($s0)
/*  f1a05a4:	10600003 */ 	beqz	$v1,.L0f1a05b4
/*  f1a05a8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1a05ac:	246cffff */ 	addiu	$t4,$v1,-1
/*  f1a05b0:	a04c0000 */ 	sb	$t4,0x0($v0)
.L0f1a05b4:
/*  f1a05b4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a05b8:	0fc249af */ 	jal	func0f0926bc
/*  f1a05bc:	3406ffff */ 	dli	$a2,0xffff
/*  f1a05c0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1a05c4:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f1a05c8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1a05cc:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f1a05d0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a05d4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a05d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a05dc:	02202825 */ 	or	$a1,$s1,$zero
/*  f1a05e0:	240605da */ 	addiu	$a2,$zero,0x5da
/*  f1a05e4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1a05e8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a05ec:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1a05f0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1a05f4:	e7b80024 */ 	swc1	$f24,0x24($sp)
/*  f1a05f8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a05fc:	e7b80030 */ 	swc1	$f24,0x30($sp)
/*  f1a0600:	e7b80034 */ 	swc1	$f24,0x34($sp)
/*  f1a0604:	0fc24e7e */ 	jal	func0f0939f8
/*  f1a0608:	e7b80038 */ 	swc1	$f24,0x38($sp)
.L0f1a060c:
/*  f1a060c:	c7a6014c */ 	lwc1	$f6,0x14c($sp)
.L0f1a0610:
/*  f1a0610:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a0614:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a0618:	e6260008 */ 	swc1	$f6,0x8($s1)
/*  f1a061c:	c7a40150 */ 	lwc1	$f4,0x150($sp)
/*  f1a0620:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a0624:	e624000c */ 	swc1	$f4,0xc($s1)
/*  f1a0628:	c7aa0154 */ 	lwc1	$f10,0x154($sp)
/*  f1a062c:	0fc1a71c */ 	jal	func0f069c70
/*  f1a0630:	e62a0010 */ 	swc1	$f10,0x10($s1)
/*  f1a0634:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f1a0638:
/*  f1a0638:	0002c940 */ 	sll	$t9,$v0,0x5
/*  f1a063c:	07210033 */ 	bgez	$t9,.L0f1a070c
/*  f1a0640:	00025100 */ 	sll	$t2,$v0,0x4
/*  f1a0644:	05420032 */ 	bltzl	$t2,.L0f1a0710
/*  f1a0648:	00027100 */ 	sll	$t6,$v0,0x4
/*  f1a064c:	8e020028 */ 	lw	$v0,0x28($s0)
/*  f1a0650:	54400025 */ 	bnezl	$v0,.L0f1a06e8
/*  f1a0654:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f1a0658:	8ecb0284 */ 	lw	$t3,0x284($s6)
/*  f1a065c:	3c017f1c */ 	lui	$at,%hi(var7f1b94d4)
/*  f1a0660:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f1a0664:	8d820004 */ 	lw	$v0,0x4($t4)
/*  f1a0668:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f1a066c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f1a0670:	05a3000f */ 	bgezl	$t5,.L0f1a06b0
/*  f1a0674:	c6060038 */ 	lwc1	$f6,0x38($s0)
/*  f1a0678:	c42894d4 */ 	lwc1	$f8,%lo(var7f1b94d4)($at)
/*  f1a067c:	c6100038 */ 	lwc1	$f16,0x38($s0)
/*  f1a0680:	240e003c */ 	addiu	$t6,$zero,0x3c
/*  f1a0684:	3c017f1c */ 	lui	$at,%hi(var7f1b94d8)
/*  f1a0688:	46104032 */ 	c.eq.s	$f8,$f16
/*  f1a068c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0690:	4500001c */ 	bc1f	.L0f1a0704
/*  f1a0694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0698:	ae0e0028 */ 	sw	$t6,0x28($s0)
/*  f1a069c:	e616003c */ 	swc1	$f22,0x3c($s0)
/*  f1a06a0:	c43294d8 */ 	lwc1	$f18,%lo(var7f1b94d8)($at)
/*  f1a06a4:	10000017 */ 	beqz	$zero,.L0f1a0704
/*  f1a06a8:	e6120034 */ 	swc1	$f18,0x34($s0)
/*  f1a06ac:	c6060038 */ 	lwc1	$f6,0x38($s0)
.L0f1a06b0:
/*  f1a06b0:	240f003c */ 	addiu	$t7,$zero,0x3c
/*  f1a06b4:	3c017f1c */ 	lui	$at,%hi(var7f1b94dc)
/*  f1a06b8:	4606b032 */ 	c.eq.s	$f22,$f6
/*  f1a06bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a06c0:	45000010 */ 	bc1f	.L0f1a0704
/*  f1a06c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a06c8:	ae0f0028 */ 	sw	$t7,0x28($s0)
/*  f1a06cc:	c42494dc */ 	lwc1	$f4,%lo(var7f1b94dc)($at)
/*  f1a06d0:	3c017f1c */ 	lui	$at,%hi(var7f1b94e0)
/*  f1a06d4:	e604003c */ 	swc1	$f4,0x3c($s0)
/*  f1a06d8:	c42a94e0 */ 	lwc1	$f10,%lo(var7f1b94e0)($at)
/*  f1a06dc:	10000009 */ 	beqz	$zero,.L0f1a0704
/*  f1a06e0:	e60a0034 */ 	swc1	$f10,0x34($s0)
/*  f1a06e4:	8ed80038 */ 	lw	$t8,0x38($s6)
.L0f1a06e8:
/*  f1a06e8:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f1a06ec:	1f200005 */ 	bgtz	$t9,.L0f1a0704
/*  f1a06f0:	ae190028 */ 	sw	$t9,0x28($s0)
/*  f1a06f4:	920b0010 */ 	lbu	$t3,0x10($s0)
/*  f1a06f8:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f1a06fc:	356c0008 */ 	ori	$t4,$t3,0x8
/*  f1a0700:	a20c0010 */ 	sb	$t4,0x10($s0)
.L0f1a0704:
/*  f1a0704:	10000054 */ 	beqz	$zero,.L0f1a0858
/*  f1a0708:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f1a070c:
/*  f1a070c:	00027100 */ 	sll	$t6,$v0,0x4
.L0f1a0710:
/*  f1a0710:	05c30052 */ 	bgezl	$t6,.L0f1a085c
/*  f1a0714:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f1a0718:	c60c003c */ 	lwc1	$f12,0x3c($s0)
/*  f1a071c:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a0720:	c60e0034 */ 	lwc1	$f14,0x34($s0)
/*  f1a0724:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a0728:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1a072c:	46006086 */ 	mov.s	$f2,$f12
/*  f1a0730:	45020003 */ 	bc1fl	.L0f1a0740
/*  f1a0734:	8ed80034 */ 	lw	$t8,0x34($s6)
/*  f1a0738:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a073c:	8ed80034 */ 	lw	$t8,0x34($s6)
.L0f1a0740:
/*  f1a0740:	3c013e80 */ 	lui	$at,0x3e80
/*  f1a0744:	44813000 */ 	mtc1	$at,$f6
/*  f1a0748:	44984000 */ 	mtc1	$t8,$f8
/*  f1a074c:	304f00ff */ 	andi	$t7,$v0,0xff
/*  f1a0750:	01e01025 */ 	or	$v0,$t7,$zero
/*  f1a0754:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f1a0758:	00001825 */ 	or	$v1,$zero,$zero
/*  f1a075c:	3c017f1c */ 	lui	$at,%hi(var7f1b94e4)
/*  f1a0760:	46107482 */ 	mul.s	$f18,$f14,$f16
/*  f1a0764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0768:	46069102 */ 	mul.s	$f4,$f18,$f6
/*  f1a076c:	46040280 */ 	add.s	$f10,$f0,$f4
/*  f1a0770:	e60a0038 */ 	swc1	$f10,0x38($s0)
/*  f1a0774:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a0778:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1a077c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0780:	45000002 */ 	bc1f	.L0f1a078c
/*  f1a0784:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0788:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1a078c:
/*  f1a078c:	307900ff */ 	andi	$t9,$v1,0xff
/*  f1a0790:	57220006 */ 	bnel	$t9,$v0,.L0f1a07ac
/*  f1a0794:	92090010 */ 	lbu	$t1,0x10($s0)
/*  f1a0798:	46001032 */ 	c.eq.s	$f2,$f0
/*  f1a079c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a07a0:	4500001e */ 	bc1f	.L0f1a081c
/*  f1a07a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a07a8:	92090010 */ 	lbu	$t1,0x10($s0)
.L0f1a07ac:
/*  f1a07ac:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f1a07b0:	e60c0038 */ 	swc1	$f12,0x38($s0)
/*  f1a07b4:	312cfff7 */ 	andi	$t4,$t1,0xfff7
/*  f1a07b8:	a20c0010 */ 	sb	$t4,0x10($s0)
/*  f1a07bc:	358d0010 */ 	ori	$t5,$t4,0x10
/*  f1a07c0:	a20d0010 */ 	sb	$t5,0x10($s0)
/*  f1a07c4:	45000009 */ 	bc1f	.L0f1a07ec
/*  f1a07c8:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f1a07cc:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a07d0:	46140201 */ 	sub.s	$f8,$f0,$f20
.L0f1a07d4:
/*  f1a07d4:	e6080038 */ 	swc1	$f8,0x38($s0)
/*  f1a07d8:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a07dc:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1a07e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a07e4:	4503fffb */ 	bc1tl	.L0f1a07d4
/*  f1a07e8:	46140201 */ 	sub.s	$f8,$f0,$f20
.L0f1a07ec:
/*  f1a07ec:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a07f0:	4616003c */ 	c.lt.s	$f0,$f22
/*  f1a07f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a07f8:	45000008 */ 	bc1f	.L0f1a081c
/*  f1a07fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0800:	46140400 */ 	add.s	$f16,$f0,$f20
.L0f1a0804:
/*  f1a0804:	e6100038 */ 	swc1	$f16,0x38($s0)
/*  f1a0808:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a080c:	4616003c */ 	c.lt.s	$f0,$f22
/*  f1a0810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0814:	4503fffb */ 	bc1tl	.L0f1a0804
/*  f1a0818:	46140400 */ 	add.s	$f16,$f0,$f20
.L0f1a081c:
/*  f1a081c:	c43294e4 */ 	lwc1	$f18,%lo(var7f1b94e4)($at)
/*  f1a0820:	02802825 */ 	or	$a1,$s4,$zero
/*  f1a0824:	0c0058dd */ 	jal	func00016374
/*  f1a0828:	46120300 */ 	add.s	$f12,$f0,$f18
/*  f1a082c:	8e6e0018 */ 	lw	$t6,0x18($s3)
/*  f1a0830:	02802825 */ 	or	$a1,$s4,$zero
/*  f1a0834:	0c0057c1 */ 	jal	func00015f04
/*  f1a0838:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f1a083c:	02802025 */ 	or	$a0,$s4,$zero
/*  f1a0840:	0c005768 */ 	jal	func00015da0
/*  f1a0844:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1a0848:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1a084c:	0c005736 */ 	jal	func00015cd8
/*  f1a0850:	2665001c */ 	addiu	$a1,$s3,0x1c
/*  f1a0854:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f1a0858:
/*  f1a0858:	0002c0c0 */ 	sll	$t8,$v0,0x3
.L0f1a085c:
/*  f1a085c:	07030021 */ 	bgezl	$t8,.L0f1a08e4
/*  f1a0860:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a0864:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f1a0868:	24013bc4 */ 	addiu	$at,$zero,0x3bc4
/*  f1a086c:	5041001d */ 	beql	$v0,$at,.L0f1a08e4
/*  f1a0870:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a0874:	8ed90038 */ 	lw	$t9,0x38($s6)
/*  f1a0878:	00594823 */ 	subu	$t1,$v0,$t9
/*  f1a087c:	1d200018 */ 	bgtz	$t1,.L0f1a08e0
/*  f1a0880:	ae090024 */ 	sw	$t1,0x24($s0)
/*  f1a0884:	920b0010 */ 	lbu	$t3,0x10($s0)
/*  f1a0888:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a088c:	316cffef */ 	andi	$t4,$t3,0xffef
/*  f1a0890:	0fc67824 */ 	jal	func0f19e090
/*  f1a0894:	a20c0010 */ 	sb	$t4,0x10($s0)
/*  f1a0898:	14400005 */ 	bnez	$v0,.L0f1a08b0
/*  f1a089c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a08a0:
/*  f1a08a0:	0fc67824 */ 	jal	func0f19e090
/*  f1a08a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08a8:	1040fffd */ 	beqz	$v0,.L0f1a08a0
/*  f1a08ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a08b0:
/*  f1a08b0:	0fc677bd */ 	jal	func0f19def4
/*  f1a08b4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08b8:	5040000a */ 	beqzl	$v0,.L0f1a08e4
/*  f1a08bc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a08c0:	0fc67824 */ 	jal	func0f19e090
/*  f1a08c4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08c8:	54400006 */ 	bnezl	$v0,.L0f1a08e4
/*  f1a08cc:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f1a08d0:
/*  f1a08d0:	0fc67824 */ 	jal	func0f19e090
/*  f1a08d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08d8:	1040fffd */ 	beqz	$v0,.L0f1a08d0
/*  f1a08dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a08e0:
/*  f1a08e0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f1a08e4:
/*  f1a08e4:	24010012 */ 	addiu	$at,$zero,0x12
/*  f1a08e8:	1641febf */ 	bne	$s2,$at,.L0f1a03e8
/*  f1a08ec:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f1a08f0:
/*  f1a08f0:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a08f4:
/*  f1a08f4:	d7b40048 */ 	ldc1	$f20,0x48($sp)
/*  f1a08f8:	d7b60050 */ 	ldc1	$f22,0x50($sp)
/*  f1a08fc:	d7b80058 */ 	ldc1	$f24,0x58($sp)
/*  f1a0900:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f1a0904:	8fb10064 */ 	lw	$s1,0x64($sp)
/*  f1a0908:	8fb20068 */ 	lw	$s2,0x68($sp)
/*  f1a090c:	8fb3006c */ 	lw	$s3,0x6c($sp)
/*  f1a0910:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f1a0914:	8fb50074 */ 	lw	$s5,0x74($sp)
/*  f1a0918:	8fb60078 */ 	lw	$s6,0x78($sp)
/*  f1a091c:	03e00008 */ 	jr	$ra
/*  f1a0920:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

GLOBAL_ASM(
glabel func0f1a0924
/*  f1a0924:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f1a0928:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a092c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1a0930:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f1a0934:	2401014c */ 	addiu	$at,$zero,0x14c
/*  f1a0938:	00808025 */ 	or	$s0,$a0,$zero
/*  f1a093c:	844e0004 */ 	lh	$t6,0x4($v0)
/*  f1a0940:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f1a0944:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f1a0948:	15c10044 */ 	bne	$t6,$at,.L0f1a0a5c
/*  f1a094c:	27a7003c */ 	addiu	$a3,$sp,0x3c
/*  f1a0950:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1a0954:	44810000 */ 	mtc1	$at,$f0
/*  f1a0958:	3c01c000 */ 	lui	$at,0xc000
/*  f1a095c:	44811000 */ 	mtc1	$at,$f2
/*  f1a0960:	e7a00040 */ 	swc1	$f0,0x40($sp)
/*  f1a0964:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f1a0968:	e7a20038 */ 	swc1	$f2,0x38($sp)
/*  f1a096c:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f1a0970:	8c440018 */ 	lw	$a0,0x18($v0)
/*  f1a0974:	27af0044 */ 	addiu	$t7,$sp,0x44
/*  f1a0978:	0fc1a006 */ 	jal	func0f068018
/*  f1a097c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a0980:	3c03800a */ 	lui	$v1,%hi(var800a000c)
/*  f1a0984:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f1a0988:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a098c:	00002825 */ 	or	$a1,$zero,$zero
/*  f1a0990:	24060004 */ 	addiu	$a2,$zero,0x4
.L0f1a0994:
/*  f1a0994:	8c641630 */ 	lw	$a0,0x1630($v1)
/*  f1a0998:	52040031 */ 	beql	$s0,$a0,.L0f1a0a60
/*  f1a099c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a09a0:	1480002a */ 	bnez	$a0,.L0f1a0a4c
/*  f1a09a4:	3c014000 */ 	lui	$at,0x4000
/*  f1a09a8:	ac701630 */ 	sw	$s0,0x1630($v1)
/*  f1a09ac:	44810000 */ 	mtc1	$at,$f0
/*  f1a09b0:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f1a09b4:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f1a09b8:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f1a09bc:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f1a09c0:	8c880284 */ 	lw	$t0,0x284($a0)
/*  f1a09c4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1a09c8:	01054821 */ 	addu	$t1,$t0,$a1
/*  f1a09cc:	44194000 */ 	mfc1	$t9,$f8
/*  f1a09d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a09d4:	a5391634 */ 	sh	$t9,0x1634($t1)
/*  f1a09d8:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f1a09dc:	8c8c0284 */ 	lw	$t4,0x284($a0)
/*  f1a09e0:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f1a09e4:	01856821 */ 	addu	$t5,$t4,$a1
/*  f1a09e8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1a09ec:	440b9000 */ 	mfc1	$t3,$f18
/*  f1a09f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a09f4:	a5ab1638 */ 	sh	$t3,0x1638($t5)
/*  f1a09f8:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f1a09fc:	8c980284 */ 	lw	$t8,0x284($a0)
/*  f1a0a00:	00026840 */ 	sll	$t5,$v0,0x1
/*  f1a0a04:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f1a0a08:	03054021 */ 	addu	$t0,$t8,$a1
/*  f1a0a0c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1a0a10:	440f4000 */ 	mfc1	$t7,$f8
/*  f1a0a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0a18:	a50f1636 */ 	sh	$t7,0x1636($t0)
/*  f1a0a1c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f1a0a20:	8c8a0284 */ 	lw	$t2,0x284($a0)
/*  f1a0a24:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f1a0a28:	01456021 */ 	addu	$t4,$t2,$a1
/*  f1a0a2c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1a0a30:	44099000 */ 	mfc1	$t1,$f18
/*  f1a0a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0a38:	a589163a */ 	sh	$t1,0x163a($t4)
/*  f1a0a3c:	8c8b0284 */ 	lw	$t3,0x284($a0)
/*  f1a0a40:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f1a0a44:	10000005 */ 	beqz	$zero,.L0f1a0a5c
/*  f1a0a48:	a5c01b90 */ 	sh	$zero,0x1b90($t6)
.L0f1a0a4c:
/*  f1a0a4c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1a0a50:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f1a0a54:	1446ffcf */ 	bne	$v0,$a2,.L0f1a0994
/*  f1a0a58:	2463000c */ 	addiu	$v1,$v1,%lo(var800a000c)
.L0f1a0a5c:
/*  f1a0a5c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1a0a60:
/*  f1a0a60:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1a0a64:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f1a0a68:	03e00008 */ 	jr	$ra
/*  f1a0a6c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a0a70
/*  f1a0a70:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f1a0a74:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*  f1a0a78:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a0a7c:	4481e000 */ 	mtc1	$at,$f28
/*  f1a0a80:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*  f1a0a84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1a0a88:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f1a0a8c:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f1a0a90:	afb40054 */ 	sw	$s4,0x54($sp)
/*  f1a0a94:	4481f000 */ 	mtc1	$at,$f30
/*  f1a0a98:	afb30050 */ 	sw	$s3,0x50($sp)
/*  f1a0a9c:	afb2004c */ 	sw	$s2,0x4c($sp)
/*  f1a0aa0:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f1a0aa4:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f1a0aa8:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f1a0aac:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f1a0ab0:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f1a0ab4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f1a0ab8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1a0abc:	0000a825 */ 	or	$s5,$zero,$zero
/*  f1a0ac0:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f1a0ac4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a0ac8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f1a0acc:	14410042 */ 	bne	$v0,$at,.L0f1a0bd8
/*  f1a0ad0:	3c11800b */ 	lui	$s1,%hi(var800acd20)
/*  f1a0ad4:	3c13800b */ 	lui	$s3,%hi(var800ad158)
/*  f1a0ad8:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f1a0adc:	4480d000 */ 	mtc1	$zero,$f26
/*  f1a0ae0:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f1a0ae4:	2673d158 */ 	addiu	$s3,$s3,%lo(var800ad158)
/*  f1a0ae8:	2631cd20 */ 	addiu	$s1,$s1,%lo(var800acd20)
/*  f1a0aec:	8e220010 */ 	lw	$v0,0x10($s1)
.L0f1a0af0:
/*  f1a0af0:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f1a0af4:	11c00035 */ 	beqz	$t6,.L0f1a0bcc
/*  f1a0af8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1a0afc:	07000033 */ 	bltz	$t8,.L0f1a0bcc
/*  f1a0b00:	00024040 */ 	sll	$t0,$v0,0x1
/*  f1a0b04:	05030032 */ 	bgezl	$t0,.L0f1a0bd0
/*  f1a0b08:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0b0c:	92290040 */ 	lbu	$t1,0x40($s1)
/*  f1a0b10:	312a0040 */ 	andi	$t2,$t1,0x40
/*  f1a0b14:	5140002e */ 	beqzl	$t2,.L0f1a0bd0
/*  f1a0b18:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0b1c:	8e300014 */ 	lw	$s0,0x14($s1)
/*  f1a0b20:	8e420284 */ 	lw	$v0,0x284($s2)
/*  f1a0b24:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f1a0b28:	c444037c */ 	lwc1	$f4,0x37c($v0)
/*  f1a0b2c:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*  f1a0b30:	c4480380 */ 	lwc1	$f8,0x380($v0)
/*  f1a0b34:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f1a0b38:	c6120010 */ 	lwc1	$f18,0x10($s0)
/*  f1a0b3c:	c4500384 */ 	lwc1	$f16,0x384($v0)
/*  f1a0b40:	460a4581 */ 	sub.s	$f22,$f8,$f10
/*  f1a0b44:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f1a0b48:	46128601 */ 	sub.s	$f24,$f16,$f18
/*  f1a0b4c:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f1a0b50:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1a0b54:	4618c282 */ 	mul.s	$f10,$f24,$f24
/*  f1a0b58:	0c012974 */ 	jal	sqrtf
/*  f1a0b5c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f1a0b60:	4600d03c */ 	c.lt.s	$f26,$f0
/*  f1a0b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0b68:	45020019 */ 	bc1fl	.L0f1a0bd0
/*  f1a0b6c:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0b70:	8e420284 */ 	lw	$v0,0x284($s2)
/*  f1a0b74:	c4500388 */ 	lwc1	$f16,0x388($v0)
/*  f1a0b78:	c444038c */ 	lwc1	$f4,0x38c($v0)
/*  f1a0b7c:	c44a0390 */ 	lwc1	$f10,0x390($v0)
/*  f1a0b80:	4610a482 */ 	mul.s	$f18,$f20,$f16
/*  f1a0b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0b88:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f1a0b8c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f1a0b90:	46185402 */ 	mul.s	$f16,$f10,$f24
/*  f1a0b94:	46088100 */ 	add.s	$f4,$f16,$f8
/*  f1a0b98:	46002083 */ 	div.s	$f2,$f4,$f0
/*  f1a0b9c:	461a103c */ 	c.lt.s	$f2,$f26
/*  f1a0ba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0ba4:	45000009 */ 	bc1f	.L0f1a0bcc
/*  f1a0ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0bac:	461c103c */ 	c.lt.s	$f2,$f28
/*  f1a0bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0bb4:	45020006 */ 	bc1fl	.L0f1a0bd0
/*  f1a0bb8:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0bbc:	46001706 */ 	mov.s	$f28,$f2
/*  f1a0bc0:	0200a025 */ 	or	$s4,$s0,$zero
/*  f1a0bc4:	46000786 */ 	mov.s	$f30,$f0
/*  f1a0bc8:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f1a0bcc:
/*  f1a0bcc:	2631003c */ 	addiu	$s1,$s1,0x3c
.L0f1a0bd0:
/*  f1a0bd0:	5633ffc7 */ 	bnel	$s1,$s3,.L0f1a0af0
/*  f1a0bd4:	8e220010 */ 	lw	$v0,0x10($s1)
.L0f1a0bd8:
/*  f1a0bd8:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f1a0bdc:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f1a0be0:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f1a0be4:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1a0be8:	e57e0258 */ 	swc1	$f30,0x258($t3)
/*  f1a0bec:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f1a0bf0:	ad94025c */ 	sw	$s4,0x25c($t4)
/*  f1a0bf4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1a0bf8:	8fb50058 */ 	lw	$s5,0x58($sp)
/*  f1a0bfc:	8fb40054 */ 	lw	$s4,0x54($sp)
/*  f1a0c00:	8fb30050 */ 	lw	$s3,0x50($sp)
/*  f1a0c04:	8fb2004c */ 	lw	$s2,0x4c($sp)
/*  f1a0c08:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f1a0c0c:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f1a0c10:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*  f1a0c14:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*  f1a0c18:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f1a0c1c:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f1a0c20:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f1a0c24:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f1a0c28:	03e00008 */ 	jr	$ra
/*  f1a0c2c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f1a0c30
/*  f1a0c30:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f1a0c34:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
/*  f1a0c38:	806e0464 */ 	lb	$t6,0x464($v1)
/*  f1a0c3c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a0c40:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a0c44:	19c0000a */ 	blez	$t6,.L0f1a0c70
/*  f1a0c48:	3c18800a */ 	lui	$t8,0x800a
/*  f1a0c4c:	90620465 */ 	lbu	$v0,0x465($v1)
/*  f1a0c50:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1a0c54:	00027942 */ 	srl	$t7,$v0,0x5
/*  f1a0c58:	11e10003 */ 	beq	$t7,$at,.L0f1a0c68
/*  f1a0c5c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1a0c60:	15e10003 */ 	bne	$t7,$at,.L0f1a0c70
/*  f1a0c64:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a0c68:
/*  f1a0c68:	10000011 */ 	beqz	$zero,.L0f1a0cb0
/*  f1a0c6c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a0c70:
/*  f1a0c70:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f1a0c74:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f1a0c78:	87220028 */ 	lh	$v0,0x28($t9)
/*  f1a0c7c:	3848000a */ 	xori	$t0,$v0,0xa
/*  f1a0c80:	2d020001 */ 	sltiu	$v0,$t0,0x1
/*  f1a0c84:	5040000b */ 	beqzl	$v0,.L0f1a0cb4
/*  f1a0c88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a0c8c:	3c028009 */ 	lui	$v0,%hi(var80088804)
/*  f1a0c90:	90428804 */ 	lbu	$v0,%lo(var80088804)($v0)
/*  f1a0c94:	0002482b */ 	sltu	$t1,$zero,$v0
/*  f1a0c98:	11200005 */ 	beqz	$t1,.L0f1a0cb0
/*  f1a0c9c:	01201025 */ 	or	$v0,$t1,$zero
/*  f1a0ca0:	0c003a61 */ 	jal	getCurrentStageId
/*  f1a0ca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0ca8:	384a0026 */ 	xori	$t2,$v0,0x26
/*  f1a0cac:	2d420001 */ 	sltiu	$v0,$t2,0x1
.L0f1a0cb0:
/*  f1a0cb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a0cb4:
/*  f1a0cb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a0cb8:	03e00008 */ 	jr	$ra
/*  f1a0cbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a0cc0
.late_rodata
glabel var7f1b94e8
.word 0x3dcccccd
.text
/*  f1a0cc0:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f1a0cc4:	3c0e8009 */ 	lui	$t6,%hi(var80088804)
/*  f1a0cc8:	91ce8804 */ 	lbu	$t6,%lo(var80088804)($t6)
/*  f1a0ccc:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f1a0cd0:	4486f000 */ 	mtc1	$a2,$f30
/*  f1a0cd4:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f1a0cd8:	00a09025 */ 	or	$s2,$a1,$zero
/*  f1a0cdc:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f1a0ce0:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f1a0ce4:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f1a0ce8:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f1a0cec:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f1a0cf0:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f1a0cf4:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f1a0cf8:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f1a0cfc:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f1a0d00:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f1a0d04:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f1a0d08:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f1a0d0c:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f1a0d10:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f1a0d14:	11c0009a */ 	beqz	$t6,.L0f1a0f80
/*  f1a0d18:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f1a0d1c:	3c017f1c */ 	lui	$at,%hi(var7f1b94e8)
/*  f1a0d20:	c43c94e8 */ 	lwc1	$f28,%lo(var7f1b94e8)($at)
/*  f1a0d24:	3c014260 */ 	lui	$at,0x4260
/*  f1a0d28:	4481d000 */ 	mtc1	$at,$f26
/*  f1a0d2c:	3c014214 */ 	lui	$at,0x4214
/*  f1a0d30:	4481c000 */ 	mtc1	$at,$f24
/*  f1a0d34:	3c014190 */ 	lui	$at,0x4190
/*  f1a0d38:	3c11800b */ 	lui	$s1,%hi(var800acd20)
/*  f1a0d3c:	3c15800b */ 	lui	$s5,%hi(var800ad158)
/*  f1a0d40:	3c10800b */ 	lui	$s0,%hi(var800acd20)
/*  f1a0d44:	4481b000 */ 	mtc1	$at,$f22
/*  f1a0d48:	2610cd20 */ 	addiu	$s0,$s0,%lo(var800acd20)
/*  f1a0d4c:	26b5d158 */ 	addiu	$s5,$s5,%lo(var800ad158)
/*  f1a0d50:	2631cd20 */ 	addiu	$s1,$s1,%lo(var800acd20)
/*  f1a0d54:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f1a0d58:	24170002 */ 	addiu	$s7,$zero,0x2
/*  f1a0d5c:	24160005 */ 	addiu	$s6,$zero,0x5
/*  f1a0d60:	2414003c */ 	addiu	$s4,$zero,0x3c
/*  f1a0d64:	2413000a */ 	addiu	$s3,$zero,0xa
/*  f1a0d68:	8e220014 */ 	lw	$v0,0x14($s1)
.L0f1a0d6c:
/*  f1a0d6c:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f1a0d70:	8c580004 */ 	lw	$t8,0x4($v0)
/*  f1a0d74:	55f80080 */ 	bnel	$t7,$t8,.L0f1a0f78
/*  f1a0d78:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0d7c:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f1a0d80:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f1a0d84:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f1a0d88:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f1a0d8c:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1a0d90:	c6500008 */ 	lwc1	$f16,0x8($s2)
/*  f1a0d94:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f1a0d98:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f1a0d9c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f1a0da0:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f1a0da4:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f1a0da8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1a0dac:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f1a0db0:	0c012974 */ 	jal	sqrtf
/*  f1a0db4:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f1a0db8:	92390040 */ 	lbu	$t9,0x40($s1)
/*  f1a0dbc:	46000506 */ 	mov.s	$f20,$f0
/*  f1a0dc0:	33280020 */ 	andi	$t0,$t9,0x20
/*  f1a0dc4:	11000004 */ 	beqz	$t0,.L0f1a0dd8
/*  f1a0dc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0dcc:	92290011 */ 	lbu	$t1,0x11($s1)
/*  f1a0dd0:	10000044 */ 	beqz	$zero,.L0f1a0ee4
/*  f1a0dd4:	a2290030 */ 	sb	$t1,0x30($s1)
.L0f1a0dd8:
/*  f1a0dd8:	0fc6749a */ 	jal	func0f19d268
/*  f1a0ddc:	96040456 */ 	lhu	$a0,0x456($s0)
/*  f1a0de0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1a0de4:	54410035 */ 	bnel	$v0,$at,.L0f1a0ebc
/*  f1a0de8:	92380040 */ 	lbu	$t8,0x40($s1)
/*  f1a0dec:	461cf182 */ 	mul.s	$f6,$f30,$f28
/*  f1a0df0:	922a0030 */ 	lbu	$t2,0x30($s1)
/*  f1a0df4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a0df8:	448a8000 */ 	mtc1	$t2,$f16
/*  f1a0dfc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1a0e00:	05410004 */ 	bgez	$t2,.L0f1a0e14
/*  f1a0e04:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1a0e08:	44812000 */ 	mtc1	$at,$f4
/*  f1a0e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e10:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f1a0e14:
/*  f1a0e14:	440c4000 */ 	mfc1	$t4,$f8
/*  f1a0e18:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1a0e1c:	3c014f00 */ 	lui	$at,0x4f00
/*  f1a0e20:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1a0e24:	448d5000 */ 	mtc1	$t5,$f10
/*  f1a0e28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e2c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1a0e30:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f1a0e34:	444ef800 */ 	cfc1	$t6,$31
/*  f1a0e38:	44cff800 */ 	ctc1	$t7,$31
/*  f1a0e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e40:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f1a0e44:	444ff800 */ 	cfc1	$t7,$31
/*  f1a0e48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e4c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1a0e50:	51e00013 */ 	beqzl	$t7,.L0f1a0ea0
/*  f1a0e54:	440f3000 */ 	mfc1	$t7,$f6
/*  f1a0e58:	44813000 */ 	mtc1	$at,$f6
/*  f1a0e5c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1a0e60:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f1a0e64:	44cff800 */ 	ctc1	$t7,$31
/*  f1a0e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e6c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f1a0e70:	444ff800 */ 	cfc1	$t7,$31
/*  f1a0e74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e78:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1a0e7c:	15e00005 */ 	bnez	$t7,.L0f1a0e94
/*  f1a0e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0e84:	440f3000 */ 	mfc1	$t7,$f6
/*  f1a0e88:	3c018000 */ 	lui	$at,0x8000
/*  f1a0e8c:	10000007 */ 	beqz	$zero,.L0f1a0eac
/*  f1a0e90:	01e17825 */ 	or	$t7,$t7,$at
.L0f1a0e94:
/*  f1a0e94:	10000005 */ 	beqz	$zero,.L0f1a0eac
/*  f1a0e98:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1a0e9c:	440f3000 */ 	mfc1	$t7,$f6
.L0f1a0ea0:
/*  f1a0ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0ea4:	05e0fffb */ 	bltz	$t7,.L0f1a0e94
/*  f1a0ea8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a0eac:
/*  f1a0eac:	44cef800 */ 	ctc1	$t6,$31
/*  f1a0eb0:	1000000c */ 	beqz	$zero,.L0f1a0ee4
/*  f1a0eb4:	a22f0030 */ 	sb	$t7,0x30($s1)
/*  f1a0eb8:	92380040 */ 	lbu	$t8,0x40($s1)
.L0f1a0ebc:
/*  f1a0ebc:	33190080 */ 	andi	$t9,$t8,0x80
/*  f1a0ec0:	53200006 */ 	beqzl	$t9,.L0f1a0edc
/*  f1a0ec4:	92290030 */ 	lbu	$t1,0x30($s1)
/*  f1a0ec8:	8e280048 */ 	lw	$t0,0x48($s1)
/*  f1a0ecc:	2901012c */ 	slti	$at,$t0,0x12c
/*  f1a0ed0:	54200005 */ 	bnezl	$at,.L0f1a0ee8
/*  f1a0ed4:	4616a03c */ 	c.lt.s	$f20,$f22
/*  f1a0ed8:	92290030 */ 	lbu	$t1,0x30($s1)
.L0f1a0edc:
/*  f1a0edc:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f1a0ee0:	a22a0030 */ 	sb	$t2,0x30($s1)
.L0f1a0ee4:
/*  f1a0ee4:	4616a03c */ 	c.lt.s	$f20,$f22
.L0f1a0ee8:
/*  f1a0ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0eec:	45020007 */ 	bc1fl	.L0f1a0f0c
/*  f1a0ef0:	4618a03c */ 	c.lt.s	$f20,$f24
/*  f1a0ef4:	960b045c */ 	lhu	$t3,0x45c($s0)
/*  f1a0ef8:	a2130471 */ 	sb	$s3,0x471($s0)
/*  f1a0efc:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f1a0f00:	10000017 */ 	beqz	$zero,.L0f1a0f60
/*  f1a0f04:	a60c045c */ 	sh	$t4,0x45c($s0)
/*  f1a0f08:	4618a03c */ 	c.lt.s	$f20,$f24
.L0f1a0f0c:
/*  f1a0f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0f10:	45020007 */ 	bc1fl	.L0f1a0f30
/*  f1a0f14:	461aa03c */ 	c.lt.s	$f20,$f26
/*  f1a0f18:	960d045e */ 	lhu	$t5,0x45e($s0)
/*  f1a0f1c:	a2160471 */ 	sb	$s6,0x471($s0)
/*  f1a0f20:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1a0f24:	1000000e */ 	beqz	$zero,.L0f1a0f60
/*  f1a0f28:	a60e045e */ 	sh	$t6,0x45e($s0)
/*  f1a0f2c:	461aa03c */ 	c.lt.s	$f20,$f26
.L0f1a0f30:
/*  f1a0f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a0f34:	45020007 */ 	bc1fl	.L0f1a0f54
/*  f1a0f38:	96190462 */ 	lhu	$t9,0x462($s0)
/*  f1a0f3c:	960f0460 */ 	lhu	$t7,0x460($s0)
/*  f1a0f40:	a2170471 */ 	sb	$s7,0x471($s0)
/*  f1a0f44:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f1a0f48:	10000005 */ 	beqz	$zero,.L0f1a0f60
/*  f1a0f4c:	a6180460 */ 	sh	$t8,0x460($s0)
/*  f1a0f50:	96190462 */ 	lhu	$t9,0x462($s0)
.L0f1a0f54:
/*  f1a0f54:	a21e0471 */ 	sb	$s8,0x471($s0)
/*  f1a0f58:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f1a0f5c:	a6080462 */ 	sh	$t0,0x462($s0)
.L0f1a0f60:
/*  f1a0f60:	8e090450 */ 	lw	$t1,0x450($s0)
/*  f1a0f64:	920a0471 */ 	lbu	$t2,0x471($s0)
/*  f1a0f68:	a2140472 */ 	sb	$s4,0x472($s0)
/*  f1a0f6c:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f1a0f70:	ae0b0450 */ 	sw	$t3,0x450($s0)
/*  f1a0f74:	2631003c */ 	addiu	$s1,$s1,0x3c
.L0f1a0f78:
/*  f1a0f78:	5635ff7c */ 	bnel	$s1,$s5,.L0f1a0d6c
/*  f1a0f7c:	8e220014 */ 	lw	$v0,0x14($s1)
.L0f1a0f80:
/*  f1a0f80:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f1a0f84:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1a0f88:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f1a0f8c:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f1a0f90:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f1a0f94:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f1a0f98:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f1a0f9c:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f1a0fa0:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f1a0fa4:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f1a0fa8:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f1a0fac:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f1a0fb0:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f1a0fb4:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f1a0fb8:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f1a0fbc:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f1a0fc0:	03e00008 */ 	jr	$ra
/*  f1a0fc4:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f1a0fc8
/*  f1a0fc8:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f1a0fcc:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f1a0fd0:	944e0458 */ 	lhu	$t6,0x458($v0)
/*  f1a0fd4:	9058045a */ 	lbu	$t8,0x45a($v0)
/*  f1a0fd8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1a0fdc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f1a0fe0:	a44f0458 */ 	sh	$t7,0x458($v0)
/*  f1a0fe4:	03e00008 */ 	jr	$ra
/*  f1a0fe8:	a059045a */ 	sb	$t9,0x45a($v0)
);

bool ciIsChrBioUnlocked(u32 bodynum)
{
	switch (bodynum) {
	case BODY_DARK_COMBAT:
	case BODY_CARRINGTON:
		return true;
	case BODY_CASSANDRA:
		return stageIsComplete(SOLOSTAGEINDEX_DEFECTION);
	case BODY_DRCAROLL:
		return stageIsComplete(SOLOSTAGEINDEX_INVESTIGATION);
	case BODY_MRBLONDE:
		return stageIsComplete(SOLOSTAGEINDEX_EXTRACTION);
	case BODY_TRENT:
		return stageIsComplete(SOLOSTAGEINDEX_G5BUILDING);
	case BODY_JONATHAN:
		return stageIsComplete(SOLOSTAGEINDEX_INFILTRATION);
	case BODY_THEKING:
		return stageIsComplete(SOLOSTAGEINDEX_RESCUE);
	case BODY_PRESIDENT:
		return stageIsComplete(SOLOSTAGEINDEX_AIRFORCEONE);
	}

	return false;
}

struct chrbio *ciGetChrBioByBodynum(u32 bodynum)
{
	struct chrbio bios[10] = g_ChrBios;

	switch (bodynum) {
	case BODY_DARK_COMBAT:
		return &bios[0];
	case BODY_JONATHAN:
		return &bios[1];
	case BODY_CARRINGTON:
		return &bios[2];
	case BODY_CASSANDRA:
		return &bios[3];
	case BODY_TRENT:
		return &bios[4];
	case BODY_DRCAROLL:
		return &bios[5];
	case BODY_THEKING:
		return &bios[6];
	case BODY_MRBLONDE:
		if (stageIsComplete(SOLOSTAGEINDEX_CRASHSITE)) {
			return &bios[8];
		}
		return &bios[7];
	case BODY_PRESIDENT:
		return &bios[9];
	}

	return NULL;
}

GLOBAL_ASM(
glabel func0f1a1184
/*  f1a1184:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a1188:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a118c:	3c048009 */ 	lui	$a0,%hi(var800888a0)
/*  f1a1190:	0fc68484 */ 	jal	func0f1a1210
/*  f1a1194:	908488a0 */ 	lbu	$a0,%lo(var800888a0)($a0)
/*  f1a1198:	0fc68429 */ 	jal	ciGetChrBioByBodynum
/*  f1a119c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a11a0:	0fc5b9f1 */ 	jal	langGet
/*  f1a11a4:	8c44000c */ 	lw	$a0,0xc($v0)
/*  f1a11a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a11ac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a11b0:	03e00008 */ 	jr	$ra
/*  f1a11b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a11b8
/*  f1a11b8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a11bc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a11c0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a11c4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a11c8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a11cc:	00008825 */ 	or	$s1,$zero,$zero
/*  f1a11d0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a11d4:	24120097 */ 	addiu	$s2,$zero,0x97
.L0f1a11d8:
/*  f1a11d8:	0fc683fb */ 	jal	ciIsChrBioUnlocked
/*  f1a11dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a11e0:	10400002 */ 	beqz	$v0,.L0f1a11ec
/*  f1a11e4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a11e8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a11ec:
/*  f1a11ec:	1612fffa */ 	bne	$s0,$s2,.L0f1a11d8
/*  f1a11f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a11f4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a11f8:	02201025 */ 	or	$v0,$s1,$zero
/*  f1a11fc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a1200:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a1204:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a1208:	03e00008 */ 	jr	$ra
/*  f1a120c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1210
/*  f1a1210:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1214:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1a1218:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1a121c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1a1220:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1a1224:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a1228:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a122c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f1a1230:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a1234:	24120097 */ 	addiu	$s2,$zero,0x97
.L0f1a1238:
/*  f1a1238:	0fc683fb */ 	jal	ciIsChrBioUnlocked
/*  f1a123c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a1240:	10400002 */ 	beqz	$v0,.L0f1a124c
/*  f1a1244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1248:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a124c:
/*  f1a124c:	56330004 */ 	bnel	$s1,$s3,.L0f1a1260
/*  f1a1250:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a1254:	10000005 */ 	beqz	$zero,.L0f1a126c
/*  f1a1258:	02001025 */ 	or	$v0,$s0,$zero
/*  f1a125c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1a1260:
/*  f1a1260:	1612fff5 */ 	bne	$s0,$s2,.L0f1a1238
/*  f1a1264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1268:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a126c:
/*  f1a126c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a1270:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1a1274:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1a1278:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1a127c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1a1280:	03e00008 */ 	jr	$ra
/*  f1a1284:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1288
/*  f1a1288:	3c0e8009 */ 	lui	$t6,%hi(misc_bios)
/*  f1a128c:	25ce8944 */ 	addiu	$t6,$t6,%lo(misc_bios)
/*  f1a1290:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a1294:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1298:	27a30008 */ 	addiu	$v1,$sp,0x8
/*  f1a129c:	ac610000 */ 	sw	$at,0x0($v1)
/*  f1a12a0:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1a12a4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1a12a8:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f1a12ac:	ac610008 */ 	sw	$at,0x8($v1)
/*  f1a12b0:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f1a12b4:	ac79000c */ 	sw	$t9,0xc($v1)
/*  f1a12b8:	8dc10010 */ 	lw	$at,0x10($t6)
/*  f1a12bc:	ac610010 */ 	sw	$at,0x10($v1)
/*  f1a12c0:	8dd90014 */ 	lw	$t9,0x14($t6)
/*  f1a12c4:	ac790014 */ 	sw	$t9,0x14($v1)
/*  f1a12c8:	8dc10018 */ 	lw	$at,0x18($t6)
/*  f1a12cc:	ac610018 */ 	sw	$at,0x18($v1)
/*  f1a12d0:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f1a12d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a12d8:	10800009 */ 	beqz	$a0,.L0f1a1300
/*  f1a12dc:	ac79001c */ 	sw	$t9,0x1c($v1)
/*  f1a12e0:	10810009 */ 	beq	$a0,$at,.L0f1a1308
/*  f1a12e4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1a12e8:	10810009 */ 	beq	$a0,$at,.L0f1a1310
/*  f1a12ec:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1a12f0:	10810009 */ 	beq	$a0,$at,.L0f1a1318
/*  f1a12f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a12f8:	10000009 */ 	beqz	$zero,.L0f1a1320
/*  f1a12fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a1300:
/*  f1a1300:	10000007 */ 	beqz	$zero,.L0f1a1320
/*  f1a1304:	00601025 */ 	or	$v0,$v1,$zero
.L0f1a1308:
/*  f1a1308:	10000005 */ 	beqz	$zero,.L0f1a1320
/*  f1a130c:	27a20010 */ 	addiu	$v0,$sp,0x10
.L0f1a1310:
/*  f1a1310:	10000003 */ 	beqz	$zero,.L0f1a1320
/*  f1a1314:	27a20018 */ 	addiu	$v0,$sp,0x18
.L0f1a1318:
/*  f1a1318:	10000001 */ 	beqz	$zero,.L0f1a1320
/*  f1a131c:	27a20020 */ 	addiu	$v0,$sp,0x20
.L0f1a1320:
/*  f1a1320:	03e00008 */ 	jr	$ra
/*  f1a1324:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1328
/*  f1a1328:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a132c:	1080000a */ 	beqz	$a0,.L0f1a1358
/*  f1a1330:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1334:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1a1338:	1081000b */ 	beq	$a0,$at,.L0f1a1368
/*  f1a133c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1a1340:	1081000d */ 	beq	$a0,$at,.L0f1a1378
/*  f1a1344:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1a1348:	1081000b */ 	beq	$a0,$at,.L0f1a1378
/*  f1a134c:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a1350:	1000000d */ 	beqz	$zero,.L0f1a1388
/*  f1a1354:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a1358:
/*  f1a1358:	0fc672e0 */ 	jal	stageIsComplete
/*  f1a135c:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f1a1360:	1000000a */ 	beqz	$zero,.L0f1a138c
/*  f1a1364:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a1368:
/*  f1a1368:	0fc672e0 */ 	jal	stageIsComplete
/*  f1a136c:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f1a1370:	10000006 */ 	beqz	$zero,.L0f1a138c
/*  f1a1374:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a1378:
/*  f1a1378:	0fc672e0 */ 	jal	stageIsComplete
/*  f1a137c:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f1a1380:	10000002 */ 	beqz	$zero,.L0f1a138c
/*  f1a1384:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a1388:
/*  f1a1388:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a138c:
/*  f1a138c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1390:	03e00008 */ 	jr	$ra
/*  f1a1394:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1398
/*  f1a1398:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a139c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a13a0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a13a4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a13a8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a13ac:	00008825 */ 	or	$s1,$zero,$zero
/*  f1a13b0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a13b4:	24120004 */ 	addiu	$s2,$zero,0x4
.L0f1a13b8:
/*  f1a13b8:	0fc684ca */ 	jal	func0f1a1328
/*  f1a13bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a13c0:	10400002 */ 	beqz	$v0,.L0f1a13cc
/*  f1a13c4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a13c8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a13cc:
/*  f1a13cc:	1612fffa */ 	bne	$s0,$s2,.L0f1a13b8
/*  f1a13d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a13d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a13d8:	02201025 */ 	or	$v0,$s1,$zero
/*  f1a13dc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a13e0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a13e4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a13e8:	03e00008 */ 	jr	$ra
/*  f1a13ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a13f0
/*  f1a13f0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a13f4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1a13f8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1a13fc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1a1400:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1a1404:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a1408:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a140c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f1a1410:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a1414:	24120004 */ 	addiu	$s2,$zero,0x4
.L0f1a1418:
/*  f1a1418:	0fc684ca */ 	jal	func0f1a1328
/*  f1a141c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a1420:	10400002 */ 	beqz	$v0,.L0f1a142c
/*  f1a1424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1428:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a142c:
/*  f1a142c:	56330004 */ 	bnel	$s1,$s3,.L0f1a1440
/*  f1a1430:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a1434:	10000005 */ 	beqz	$zero,.L0f1a144c
/*  f1a1438:	02001025 */ 	or	$v0,$s0,$zero
/*  f1a143c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1a1440:
/*  f1a1440:	1612fff5 */ 	bne	$s0,$s2,.L0f1a1418
/*  f1a1444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1448:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a144c:
/*  f1a144c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a1450:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1a1454:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1a1458:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1a145c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1a1460:	03e00008 */ 	jr	$ra
/*  f1a1464:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1468
/*  f1a1468:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a146c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1470:	0fc6846e */ 	jal	func0f1a11b8
/*  f1a1474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1478:	3c0e8009 */ 	lui	$t6,%hi(var800888a0)
/*  f1a147c:	91ce88a0 */ 	lbu	$t6,%lo(var800888a0)($t6)
/*  f1a1480:	0fc684fc */ 	jal	func0f1a13f0
/*  f1a1484:	01c22023 */ 	subu	$a0,$t6,$v0
/*  f1a1488:	0fc684a2 */ 	jal	func0f1a1288
/*  f1a148c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a1490:	0fc5b9f1 */ 	jal	langGet
/*  f1a1494:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1a1498:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a149c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a14a0:	03e00008 */ 	jr	$ra
/*  f1a14a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a14a8
/*  f1a14a8:	2882000e */ 	slti	$v0,$a0,0xe
/*  f1a14ac:	03e00008 */ 	jr	$ra
/*  f1a14b0:	38420001 */ 	xori	$v0,$v0,0x1
);

GLOBAL_ASM(
glabel func0f1a14b4
.late_rodata
glabel var7f1b96cc
.word 0x7f1a1524
glabel var7f1b96d0
.word 0x7f1a152c
glabel var7f1b96d4
.word 0x7f1a1534
glabel var7f1b96d8
.word 0x7f1a153c
glabel var7f1b96dc
.word 0x7f1a1544
glabel var7f1b96e0
.word 0x7f1a154c
glabel var7f1b96e4
.word 0x7f1a1554
glabel var7f1b96e8
.word 0x7f1a155c
glabel var7f1b96ec
.word 0x7f1a1564
glabel var7f1b96f0
.word 0x7f1a156c
glabel var7f1b96f4
.word 0x7f1a1574
glabel var7f1b96f8
.word 0x7f1a157c
glabel var7f1b96fc
.word 0x7f1a1584
glabel var7f1b9700
.word 0x7f1a158c
glabel var7f1b9704
.word 0x7f1a1594
glabel var7f1b9708
.word 0x7f1a159c
glabel var7f1b970c
.word 0x7f1a15a4
glabel var7f1b9710
.word 0x7f1a15ac
glabel var7f1b9714
.word 0x7f1a15b4
glabel var7f1b9718
.word 0x7f1a15bc
glabel var7f1b971c
.word 0x7f1a15c4
glabel var7f1b9720
.word 0x7f1a15cc
glabel var7f1b9724
.word 0x7f1a15d4
.text
/*  f1a14b4:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f1a14b8:	3c0e8009 */ 	lui	$t6,%hi(place_bios)
/*  f1a14bc:	27a30000 */ 	addiu	$v1,$sp,0x0
/*  f1a14c0:	25ce8968 */ 	addiu	$t6,$t6,%lo(place_bios)
/*  f1a14c4:	25d90168 */ 	addiu	$t9,$t6,0x168
/*  f1a14c8:	00604025 */ 	or	$t0,$v1,$zero
.L0f1a14cc:
/*  f1a14cc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a14d0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a14d4:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f1a14d8:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f1a14dc:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a14e0:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f1a14e4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a14e8:	15d9fff8 */ 	bne	$t6,$t9,.L0f1a14cc
/*  f1a14ec:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f1a14f0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a14f4:	00044880 */ 	sll	$t1,$a0,0x2
/*  f1a14f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a14fc:	ad010000 */ 	sw	$at,0x0($t0)
/*  f1a1500:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1a1504:	2c810017 */ 	sltiu	$at,$a0,0x17
/*  f1a1508:	10200034 */ 	beqz	$at,.L0f1a15dc
/*  f1a150c:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f1a1510:	3c017f1c */ 	lui	$at,%hi(var7f1b96cc)
/*  f1a1514:	00290821 */ 	addu	$at,$at,$t1
/*  f1a1518:	8c2996cc */ 	lw	$t1,%lo(var7f1b96cc)($at)
/*  f1a151c:	01200008 */ 	jr	$t1
/*  f1a1520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1524:	1000002d */ 	beqz	$zero,.L0f1a15dc
/*  f1a1528:	00601025 */ 	or	$v0,$v1,$zero
/*  f1a152c:	1000002b */ 	beqz	$zero,.L0f1a15dc
/*  f1a1530:	27a20010 */ 	addiu	$v0,$sp,0x10
/*  f1a1534:	10000029 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1538:	27a20020 */ 	addiu	$v0,$sp,0x20
/*  f1a153c:	10000027 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1540:	27a20030 */ 	addiu	$v0,$sp,0x30
/*  f1a1544:	10000025 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1548:	27a20040 */ 	addiu	$v0,$sp,0x40
/*  f1a154c:	10000023 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1550:	27a20050 */ 	addiu	$v0,$sp,0x50
/*  f1a1554:	10000021 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1558:	27a20060 */ 	addiu	$v0,$sp,0x60
/*  f1a155c:	1000001f */ 	beqz	$zero,.L0f1a15dc
/*  f1a1560:	27a20070 */ 	addiu	$v0,$sp,0x70
/*  f1a1564:	1000001d */ 	beqz	$zero,.L0f1a15dc
/*  f1a1568:	27a20080 */ 	addiu	$v0,$sp,0x80
/*  f1a156c:	1000001b */ 	beqz	$zero,.L0f1a15dc
/*  f1a1570:	27a20090 */ 	addiu	$v0,$sp,0x90
/*  f1a1574:	10000019 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1578:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1a157c:	10000017 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1580:	27a200b0 */ 	addiu	$v0,$sp,0xb0
/*  f1a1584:	10000015 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1588:	27a200c0 */ 	addiu	$v0,$sp,0xc0
/*  f1a158c:	10000013 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1590:	27a200d0 */ 	addiu	$v0,$sp,0xd0
/*  f1a1594:	10000011 */ 	beqz	$zero,.L0f1a15dc
/*  f1a1598:	27a200e0 */ 	addiu	$v0,$sp,0xe0
/*  f1a159c:	1000000f */ 	beqz	$zero,.L0f1a15dc
/*  f1a15a0:	27a200f0 */ 	addiu	$v0,$sp,0xf0
/*  f1a15a4:	1000000d */ 	beqz	$zero,.L0f1a15dc
/*  f1a15a8:	27a20100 */ 	addiu	$v0,$sp,0x100
/*  f1a15ac:	1000000b */ 	beqz	$zero,.L0f1a15dc
/*  f1a15b0:	27a20110 */ 	addiu	$v0,$sp,0x110
/*  f1a15b4:	10000009 */ 	beqz	$zero,.L0f1a15dc
/*  f1a15b8:	27a20120 */ 	addiu	$v0,$sp,0x120
/*  f1a15bc:	10000007 */ 	beqz	$zero,.L0f1a15dc
/*  f1a15c0:	27a20130 */ 	addiu	$v0,$sp,0x130
/*  f1a15c4:	10000005 */ 	beqz	$zero,.L0f1a15dc
/*  f1a15c8:	27a20140 */ 	addiu	$v0,$sp,0x140
/*  f1a15cc:	10000003 */ 	beqz	$zero,.L0f1a15dc
/*  f1a15d0:	27a20150 */ 	addiu	$v0,$sp,0x150
/*  f1a15d4:	10000001 */ 	beqz	$zero,.L0f1a15dc
/*  f1a15d8:	27a20160 */ 	addiu	$v0,$sp,0x160
.L0f1a15dc:
/*  f1a15dc:	03e00008 */ 	jr	$ra
/*  f1a15e0:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

bool bioIsUnlocked(u32 bioindex)
{
	u32 stage;

	// bioindex is an index into place_bios
	switch (bioindex) {
	case 0:
	case 15:
		return true;
	case 1:
		stage = SOLOSTAGEINDEX_DEFECTION;
		break;
	case 2:
	case 17:
		stage = SOLOSTAGEINDEX_INVESTIGATION;
		break;
	case 18:
		stage = SOLOSTAGEINDEX_EXTRACTION;
		break;
	case 3:
	case 14:
		stage = SOLOSTAGEINDEX_VILLA;
		break;
	case 4:
		stage = SOLOSTAGEINDEX_CHICAGO;
		break;
	case 5:
	case 19:
		stage = SOLOSTAGEINDEX_G5BUILDING;
		break;
	case 6:
	case 16:
	case 20:
		stage = SOLOSTAGEINDEX_INFILTRATION;
		break;
	case 7:
		stage = SOLOSTAGEINDEX_AIRBASE;
		break;
	case 8:
		stage = SOLOSTAGEINDEX_AIRFORCEONE;
		break;
	case 9:
	case 21:
		stage = SOLOSTAGEINDEX_CRASHSITE;
		break;
	case 10:
		stage = SOLOSTAGEINDEX_PELAGIC;
		break;
	case 11:
		stage = SOLOSTAGEINDEX_DEEPSEA;
		break;
	case 12:
	case 22:
		stage = SOLOSTAGEINDEX_DEFENSE;
		break;
	case 13:
		stage = SOLOSTAGEINDEX_ATTACKSHIP;
		break;
	default:
		return false;
	}

	return stageIsComplete(stage);
}

GLOBAL_ASM(
glabel func0f1a16a4
/*  f1a16a4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a16a8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a16ac:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a16b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a16b4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a16b8:	00008825 */ 	or	$s1,$zero,$zero
/*  f1a16bc:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a16c0:	24120017 */ 	addiu	$s2,$zero,0x17
.L0f1a16c4:
/*  f1a16c4:	0fc6852a */ 	jal	func0f1a14a8
/*  f1a16c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a16cc:	10400003 */ 	beqz	$v0,.L0f1a16dc
/*  f1a16d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a16d4:	10000009 */ 	beqz	$zero,.L0f1a16fc
/*  f1a16d8:	02201025 */ 	or	$v0,$s1,$zero
.L0f1a16dc:
/*  f1a16dc:	0fc68579 */ 	jal	bioIsUnlocked
/*  f1a16e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a16e4:	10400002 */ 	beqz	$v0,.L0f1a16f0
/*  f1a16e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a16ec:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a16f0:
/*  f1a16f0:	1612fff4 */ 	bne	$s0,$s2,.L0f1a16c4
/*  f1a16f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a16f8:	02201025 */ 	or	$v0,$s1,$zero
.L0f1a16fc:
/*  f1a16fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a1700:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a1704:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a1708:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a170c:	03e00008 */ 	jr	$ra
/*  f1a1710:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1714
/*  f1a1714:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1718:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a171c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a1720:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a1724:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a1728:	00008825 */ 	or	$s1,$zero,$zero
/*  f1a172c:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a1730:	24120017 */ 	addiu	$s2,$zero,0x17
.L0f1a1734:
/*  f1a1734:	0fc68579 */ 	jal	bioIsUnlocked
/*  f1a1738:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a173c:	10400002 */ 	beqz	$v0,.L0f1a1748
/*  f1a1740:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a1744:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a1748:
/*  f1a1748:	1612fffa */ 	bne	$s0,$s2,.L0f1a1734
/*  f1a174c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1750:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a1754:	02201025 */ 	or	$v0,$s1,$zero
/*  f1a1758:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a175c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a1760:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a1764:	03e00008 */ 	jr	$ra
/*  f1a1768:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a176c
/*  f1a176c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1770:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1a1774:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1a1778:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1a177c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1a1780:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a1784:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a1788:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f1a178c:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a1790:	24120017 */ 	addiu	$s2,$zero,0x17
.L0f1a1794:
/*  f1a1794:	0fc68579 */ 	jal	bioIsUnlocked
/*  f1a1798:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a179c:	10400002 */ 	beqz	$v0,.L0f1a17a8
/*  f1a17a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a17a4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a17a8:
/*  f1a17a8:	56330004 */ 	bnel	$s1,$s3,.L0f1a17bc
/*  f1a17ac:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a17b0:	10000005 */ 	beqz	$zero,.L0f1a17c8
/*  f1a17b4:	02001025 */ 	or	$v0,$s0,$zero
/*  f1a17b8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1a17bc:
/*  f1a17bc:	1612fff5 */ 	bne	$s0,$s2,.L0f1a1794
/*  f1a17c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a17c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a17c8:
/*  f1a17c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a17cc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1a17d0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1a17d4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1a17d8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1a17dc:	03e00008 */ 	jr	$ra
/*  f1a17e0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a17e4
/*  f1a17e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a17e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a17ec:	3c048009 */ 	lui	$a0,%hi(var80088964)
/*  f1a17f0:	0fc685db */ 	jal	func0f1a176c
/*  f1a17f4:	90848964 */ 	lbu	$a0,%lo(var80088964)($a0)
/*  f1a17f8:	0fc6852d */ 	jal	func0f1a14b4
/*  f1a17fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a1800:	0fc5b9f1 */ 	jal	langGet
/*  f1a1804:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1a1808:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a180c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1810:	03e00008 */ 	jr	$ra
/*  f1a1814:	00000000 */ 	sll	$zero,$zero,0x0
);

struct trainingdata *ciGetTrainingData(void)
{
	return &g_TrainingData;
}

GLOBAL_ASM(
glabel func0f1a1824
/*  f1a1824:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a1828:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a182c:	0fc2a4ab */ 	jal	func0f0a92ac
/*  f1a1830:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1a1834:	3c04800b */ 	lui	$a0,%hi(var800ad1a8)
/*  f1a1838:	8c84d1a8 */ 	lw	$a0,%lo(var800ad1a8)($a0)
/*  f1a183c:	10800003 */ 	beqz	$a0,.L0f1a184c
/*  f1a1840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1844:	0fc1acd3 */ 	jal	setupParseObjectWithArg2False
/*  f1a1848:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1a184c:
/*  f1a184c:	3c01800b */ 	lui	$at,0x800b
/*  f1a1850:	3c048009 */ 	lui	$a0,%hi(var80088ad8)
/*  f1a1854:	ac20d1a8 */ 	sw	$zero,-0x2e58($at)
/*  f1a1858:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a185c:	90848ad8 */ 	lbu	$a0,%lo(var80088ad8)($a0)
/*  f1a1860:	0fc68778 */ 	jal	func0f1a1de0
/*  f1a1864:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a1868:	24010035 */ 	addiu	$at,$zero,0x35
/*  f1a186c:	14410003 */ 	bne	$v0,$at,.L0f1a187c
/*  f1a1870:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f1a1874:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f1a1878:	00002825 */ 	or	$a1,$zero,$zero
.L0f1a187c:
/*  f1a187c:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f1a1880:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f1a1884:	8cee0284 */ 	lw	$t6,0x284($a3)
/*  f1a1888:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f1a188c:	5060001c */ 	beqzl	$v1,.L0f1a1900
/*  f1a1890:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1894:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f1a1898:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1a189c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a18a0:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f1a18a4:	a0600035 */ 	sb	$zero,0x35($v1)
/*  f1a18a8:	8cf90284 */ 	lw	$t9,0x284($a3)
/*  f1a18ac:	3406ffff */ 	dli	$a2,0xffff
/*  f1a18b0:	8f280480 */ 	lw	$t0,0x480($t9)
/*  f1a18b4:	a1180034 */ 	sb	$t8,0x34($t0)
/*  f1a18b8:	8ce90284 */ 	lw	$t1,0x284($a3)
/*  f1a18bc:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f1a18c0:	a1400037 */ 	sb	$zero,0x37($t2)
/*  f1a18c4:	8c4b0018 */ 	lw	$t3,0x18($v0)
/*  f1a18c8:	356c0400 */ 	ori	$t4,$t3,0x400
/*  f1a18cc:	ac4c0018 */ 	sw	$t4,0x18($v0)
/*  f1a18d0:	8ced0284 */ 	lw	$t5,0x284($a3)
/*  f1a18d4:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f1a18d8:	0fc249af */ 	jal	func0f0926bc
/*  f1a18dc:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f1a18e0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f1a18e4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f1a18e8:	8ce20284 */ 	lw	$v0,0x284($a3)
/*  f1a18ec:	2401fffb */ 	addiu	$at,$zero,-5
/*  f1a18f0:	8c4f00c4 */ 	lw	$t7,0xc4($v0)
/*  f1a18f4:	01e1c824 */ 	and	$t9,$t7,$at
/*  f1a18f8:	ac5900c4 */ 	sw	$t9,0xc4($v0)
/*  f1a18fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a1900:
/*  f1a1900:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1904:	03e00008 */ 	jr	$ra
/*  f1a1908:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a190c
/*  f1a190c:	3c02800b */ 	lui	$v0,%hi(g_TrainingData)
/*  f1a1910:	2442d1a0 */ 	addiu	$v0,$v0,%lo(g_TrainingData)
/*  f1a1914:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1a1918:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a191c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1920:	00037880 */ 	sll	$t7,$v1,0x2
/*  f1a1924:	05e10008 */ 	bgez	$t7,.L0f1a1948
/*  f1a1928:	0003c840 */ 	sll	$t9,$v1,0x1
/*  f1a192c:	3c048009 */ 	lui	$a0,%hi(menudialog_trainingstats_completed)
/*  f1a1930:	2484959c */ 	addiu	$a0,$a0,%lo(menudialog_trainingstats_completed)
/*  f1a1934:	0fc3e178 */ 	jal	func0f0f85e0
/*  f1a1938:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f1a193c:	3c02800b */ 	lui	$v0,%hi(g_TrainingData)
/*  f1a1940:	10000008 */ 	beqz	$zero,.L0f1a1964
/*  f1a1944:	2442d1a0 */ 	addiu	$v0,$v0,%lo(g_TrainingData)
.L0f1a1948:
/*  f1a1948:	07210006 */ 	bgez	$t9,.L0f1a1964
/*  f1a194c:	3c048009 */ 	lui	$a0,%hi(menudialog_trainingstats_failed)
/*  f1a1950:	2484950c */ 	addiu	$a0,$a0,%lo(menudialog_trainingstats_failed)
/*  f1a1954:	0fc3e178 */ 	jal	func0f0f85e0
/*  f1a1958:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f1a195c:	3c02800b */ 	lui	$v0,%hi(g_TrainingData)
/*  f1a1960:	2442d1a0 */ 	addiu	$v0,$v0,%lo(g_TrainingData)
.L0f1a1964:
/*  f1a1964:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f1a1968:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a196c:	a0400001 */ 	sb	$zero,0x1($v0)
/*  f1a1970:	310affdf */ 	andi	$t2,$t0,0xffdf
/*  f1a1974:	314c00bf */ 	andi	$t4,$t2,0xbf
/*  f1a1978:	a04a0000 */ 	sb	$t2,0x0($v0)
/*  f1a197c:	318e00ef */ 	andi	$t6,$t4,0xef
/*  f1a1980:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f1a1984:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f1a1988:	31cf00f7 */ 	andi	$t7,$t6,0xf7
/*  f1a198c:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f1a1990:	03e00008 */ 	jr	$ra
/*  f1a1994:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a1998
/*  f1a1998:	3c0e8009 */ 	lui	$t6,%hi(var80088adc)
/*  f1a199c:	91ce8adc */ 	lbu	$t6,%lo(var80088adc)($t6)
/*  f1a19a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a19a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a19a8:	11c00041 */ 	beqz	$t6,.L0f1a1ab0
/*  f1a19ac:	3c03800b */ 	lui	$v1,%hi(g_TrainingData)
/*  f1a19b0:	2463d1a0 */ 	addiu	$v1,$v1,%lo(g_TrainingData)
/*  f1a19b4:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f1a19b8:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f1a19bc:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f1a19c0:	00027fc2 */ 	srl	$t7,$v0,0x1f
/*  f1a19c4:	11e0002c */ 	beqz	$t7,.L0f1a1a78
/*  f1a19c8:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f1a19cc:	8c780004 */ 	lw	$t8,0x4($v1)
/*  f1a19d0:	8c990038 */ 	lw	$t9,0x38($a0)
/*  f1a19d4:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f1a19d8:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1a19dc:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f1a19e0:	8d2a00d8 */ 	lw	$t2,0xd8($t1)
/*  f1a19e4:	51400004 */ 	beqzl	$t2,.L0f1a19f8
/*  f1a19e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a19ec:	0fc686fb */ 	jal	func0f1a1bec
/*  f1a19f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a19f4:	00002025 */ 	or	$a0,$zero,$zero
.L0f1a19f8:
/*  f1a19f8:	0fc127da */ 	jal	chrHasStageFlag
/*  f1a19fc:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f1a1a00:	1040000d */ 	beqz	$v0,.L0f1a1a38
/*  f1a1a04:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1a08:	0fc686fb */ 	jal	func0f1a1bec
/*  f1a1a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1a10:	3c03800b */ 	lui	$v1,%hi(g_TrainingData)
/*  f1a1a14:	2463d1a0 */ 	addiu	$v1,$v1,%lo(g_TrainingData)
/*  f1a1a18:	906c0000 */ 	lbu	$t4,0x0($v1)
/*  f1a1a1c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a1a20:	a06e0001 */ 	sb	$t6,0x1($v1)
/*  f1a1a24:	35980040 */ 	ori	$t8,$t4,0x40
/*  f1a1a28:	a0780000 */ 	sb	$t8,0x0($v1)
/*  f1a1a2c:	37190010 */ 	ori	$t9,$t8,0x10
/*  f1a1a30:	1000001f */ 	beqz	$zero,.L0f1a1ab0
/*  f1a1a34:	a0790000 */ 	sb	$t9,0x0($v1)
.L0f1a1a38:
/*  f1a1a38:	0fc127da */ 	jal	chrHasStageFlag
/*  f1a1a3c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1a1a40:	5040001c */ 	beqzl	$v0,.L0f1a1ab4
/*  f1a1a44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1a48:	0fc686fb */ 	jal	func0f1a1bec
/*  f1a1a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1a50:	3c03800b */ 	lui	$v1,%hi(g_TrainingData)
/*  f1a1a54:	2463d1a0 */ 	addiu	$v1,$v1,%lo(g_TrainingData)
/*  f1a1a58:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f1a1a5c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1a1a60:	a06b0001 */ 	sb	$t3,0x1($v1)
/*  f1a1a64:	352d0020 */ 	ori	$t5,$t1,0x20
/*  f1a1a68:	a06d0000 */ 	sb	$t5,0x0($v1)
/*  f1a1a6c:	35ae0010 */ 	ori	$t6,$t5,0x10
/*  f1a1a70:	1000000f */ 	beqz	$zero,.L0f1a1ab0
/*  f1a1a74:	a06e0000 */ 	sb	$t6,0x0($v1)
.L0f1a1a78:
/*  f1a1a78:	0703000e */ 	bgezl	$t8,.L0f1a1ab4
/*  f1a1a7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1a80:	80620001 */ 	lb	$v0,0x1($v1)
/*  f1a1a84:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f1a1a88:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f1a1a8c:	5c400006 */ 	bgtzl	$v0,.L0f1a1aa8
/*  f1a1a90:	8c990038 */ 	lw	$t9,0x38($a0)
/*  f1a1a94:	0fc68643 */ 	jal	func0f1a190c
/*  f1a1a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1a9c:	10000005 */ 	beqz	$zero,.L0f1a1ab4
/*  f1a1aa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1aa4:	8c990038 */ 	lw	$t9,0x38($a0)
.L0f1a1aa8:
/*  f1a1aa8:	00594023 */ 	subu	$t0,$v0,$t9
/*  f1a1aac:	a0680001 */ 	sb	$t0,0x1($v1)
.L0f1a1ab0:
/*  f1a1ab0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a1ab4:
/*  f1a1ab4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1ab8:	03e00008 */ 	jr	$ra
/*  f1a1abc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1ac0
/*  f1a1ac0:	3c038009 */ 	lui	$v1,%hi(var80088adc)
/*  f1a1ac4:	24638adc */ 	addiu	$v1,$v1,%lo(var80088adc)
/*  f1a1ac8:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f1a1acc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a1ad0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1ad4:	15c0001b */ 	bnez	$t6,.L0f1a1b44
/*  f1a1ad8:	3c02800b */ 	lui	$v0,%hi(g_TrainingData)
/*  f1a1adc:	2442d1a0 */ 	addiu	$v0,$v0,%lo(g_TrainingData)
/*  f1a1ae0:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1a1ae4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1a1ae8:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f1a1aec:	3308ff7f */ 	andi	$t0,$t8,0xff7f
/*  f1a1af0:	310a00bf */ 	andi	$t2,$t0,0xbf
/*  f1a1af4:	a0480000 */ 	sb	$t0,0x0($v0)
/*  f1a1af8:	314c00df */ 	andi	$t4,$t2,0xdf
/*  f1a1afc:	a04a0000 */ 	sb	$t2,0x0($v0)
/*  f1a1b00:	318e00ef */ 	andi	$t6,$t4,0xef
/*  f1a1b04:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f1a1b08:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f1a1b0c:	31cf00f7 */ 	andi	$t7,$t6,0xf7
/*  f1a1b10:	a0400001 */ 	sb	$zero,0x1($v0)
/*  f1a1b14:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f1a1b18:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1a1b1c:	ac400008 */ 	sw	$zero,0x8($v0)
/*  f1a1b20:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1b24:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1b28:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1a1b2c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1b30:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1b34:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1a1b38:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1b3c:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1b40:	24050010 */ 	addiu	$a1,$zero,0x10
.L0f1a1b44:
/*  f1a1b44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1b48:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1b4c:	03e00008 */ 	jr	$ra
/*  f1a1b50:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1b54
/*  f1a1b54:	3c02800b */ 	lui	$v0,%hi(g_TrainingData)
/*  f1a1b58:	2442d1a0 */ 	addiu	$v0,$v0,%lo(g_TrainingData)
/*  f1a1b5c:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f1a1b60:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a1b64:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1b68:	35f80080 */ 	ori	$t8,$t7,0x80
/*  f1a1b6c:	a0580000 */ 	sb	$t8,0x0($v0)
/*  f1a1b70:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1a1b74:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1b78:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1b7c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1a1b80:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1b84:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1b88:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1a1b8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1b90:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1b94:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f1a1b98:	3c048009 */ 	lui	$a0,%hi(var80088ad8)
/*  f1a1b9c:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a1ba0:	90848ad8 */ 	lbu	$a0,%lo(var80088ad8)($a0)
/*  f1a1ba4:	0fc6878e */ 	jal	func0f1a1e38
/*  f1a1ba8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a1bac:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1bb0:	0fc127cb */ 	jal	chrSetStageFlag
/*  f1a1bb4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a1bb8:	3c08800a */ 	lui	$t0,0x800a
/*  f1a1bbc:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f1a1bc0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1a1bc4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1bc8:	0fc2a4ab */ 	jal	func0f0a92ac
/*  f1a1bcc:	ad191c08 */ 	sw	$t9,0x1c08($t0)
/*  f1a1bd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1bd4:	0fc127cb */ 	jal	chrSetStageFlag
/*  f1a1bd8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a1bdc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1be0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1be4:	03e00008 */ 	jr	$ra
/*  f1a1be8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1bec
/*  f1a1bec:	3c02800b */ 	lui	$v0,%hi(g_TrainingData)
/*  f1a1bf0:	2442d1a0 */ 	addiu	$v0,$v0,%lo(g_TrainingData)
/*  f1a1bf4:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f1a1bf8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a1bfc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1c00:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f1a1c04:	0fc68609 */ 	jal	func0f1a1824
/*  f1a1c08:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f1a1c0c:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f1a1c10:	0fc2a58a */ 	jal	currentPlayerGiveAmmo
/*  f1a1c14:	00002825 */ 	or	$a1,$zero,$zero
/*  f1a1c18:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1c1c:	0fc127cb */ 	jal	chrSetStageFlag
/*  f1a1c20:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1a1c24:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1c28:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1c2c:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f1a1c30:	3c048009 */ 	lui	$a0,%hi(var80088ad8)
/*  f1a1c34:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a1c38:	90848ad8 */ 	lbu	$a0,%lo(var80088ad8)($a0)
/*  f1a1c3c:	0fc6878e */ 	jal	func0f1a1e38
/*  f1a1c40:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a1c44:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1c48:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1c4c:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a1c50:	3c18800a */ 	lui	$t8,0x800a
/*  f1a1c54:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f1a1c58:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a1c5c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a1c60:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a1c64:	af001c08 */ 	sw	$zero,0x1c08($t8)
/*  f1a1c68:	0fc2eda7 */ 	jal	func0f0bb69c
/*  f1a1c6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1c70:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a1c74:	3c19800a */ 	lui	$t9,0x800a
/*  f1a1c78:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f1a1c7c:	44812000 */ 	mtc1	$at,$f4
/*  f1a1c80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1c84:	e72400dc */ 	swc1	$f4,0xdc($t9)
/*  f1a1c88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1c8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a1c90:	03e00008 */ 	jr	$ra
/*  f1a1c94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1c98
/*  f1a1c98:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1c9c:	3c0e8009 */ 	lui	$t6,%hi(var80088ae0)
/*  f1a1ca0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1ca4:	25ce8ae0 */ 	addiu	$t6,$t6,%lo(var80088ae0)
/*  f1a1ca8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a1cac:	27a2001c */ 	addiu	$v0,$sp,0x1c
/*  f1a1cb0:	2485ffff */ 	addiu	$a1,$a0,-1
/*  f1a1cb4:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1a1cb8:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1a1cbc:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1a1cc0:	95c10008 */ 	lhu	$at,0x8($t6)
/*  f1a1cc4:	a4410008 */ 	sh	$at,0x8($v0)
/*  f1a1cc8:	28a1000a */ 	slti	$at,$a1,0xa
/*  f1a1ccc:	14200003 */ 	bnez	$at,.L0f1a1cdc
/*  f1a1cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1cd4:	1000000a */ 	beqz	$zero,.L0f1a1d00
/*  f1a1cd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a1cdc:
/*  f1a1cdc:	04a00005 */ 	bltz	$a1,.L0f1a1cf4
/*  f1a1ce0:	00454021 */ 	addu	$t0,$v0,$a1
/*  f1a1ce4:	0fc43c63 */ 	jal	savefileHasFlag
/*  f1a1ce8:	91040000 */ 	lbu	$a0,0x0($t0)
/*  f1a1cec:	50400004 */ 	beqzl	$v0,.L0f1a1d00
/*  f1a1cf0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a1cf4:
/*  f1a1cf4:	10000002 */ 	beqz	$zero,.L0f1a1d00
/*  f1a1cf8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a1cfc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a1d00:
/*  f1a1d00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1d04:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a1d08:	03e00008 */ 	jr	$ra
/*  f1a1d0c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1d10
/*  f1a1d10:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1d14:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a1d18:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a1d1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a1d20:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a1d24:	00008825 */ 	or	$s1,$zero,$zero
/*  f1a1d28:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a1d2c:	2412000a */ 	addiu	$s2,$zero,0xa
.L0f1a1d30:
/*  f1a1d30:	0fc68726 */ 	jal	func0f1a1c98
/*  f1a1d34:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a1d38:	10400002 */ 	beqz	$v0,.L0f1a1d44
/*  f1a1d3c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a1d40:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a1d44:
/*  f1a1d44:	1612fffa */ 	bne	$s0,$s2,.L0f1a1d30
/*  f1a1d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1d4c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a1d50:	02201025 */ 	or	$v0,$s1,$zero
/*  f1a1d54:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a1d58:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a1d5c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a1d60:	03e00008 */ 	jr	$ra
/*  f1a1d64:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1d68
/*  f1a1d68:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1d6c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1a1d70:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1a1d74:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1a1d78:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1a1d7c:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a1d80:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a1d84:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f1a1d88:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a1d8c:	2412000a */ 	addiu	$s2,$zero,0xa
.L0f1a1d90:
/*  f1a1d90:	0fc68726 */ 	jal	func0f1a1c98
/*  f1a1d94:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a1d98:	10400002 */ 	beqz	$v0,.L0f1a1da4
/*  f1a1d9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1da0:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a1da4:
/*  f1a1da4:	56330004 */ 	bnel	$s1,$s3,.L0f1a1db8
/*  f1a1da8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a1dac:	10000005 */ 	beqz	$zero,.L0f1a1dc4
/*  f1a1db0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1a1db4:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1a1db8:
/*  f1a1db8:	1612fff5 */ 	bne	$s0,$s2,.L0f1a1d90
/*  f1a1dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a1dc0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a1dc4:
/*  f1a1dc4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a1dc8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1a1dcc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1a1dd0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1a1dd4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1a1dd8:	03e00008 */ 	jr	$ra
/*  f1a1ddc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1de0
/*  f1a1de0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1de4:	3c0e8009 */ 	lui	$t6,%hi(var80088aec)
/*  f1a1de8:	27a30000 */ 	addiu	$v1,$sp,0x0
/*  f1a1dec:	25ce8aec */ 	addiu	$t6,$t6,%lo(var80088aec)
/*  f1a1df0:	25d90024 */ 	addiu	$t9,$t6,0x24
/*  f1a1df4:	00604025 */ 	or	$t0,$v1,$zero
.L0f1a1df8:
/*  f1a1df8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a1dfc:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a1e00:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f1a1e04:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f1a1e08:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a1e0c:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f1a1e10:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a1e14:	15d9fff8 */ 	bne	$t6,$t9,.L0f1a1df8
/*  f1a1e18:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f1a1e1c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a1e20:	00044880 */ 	sll	$t1,$a0,0x2
/*  f1a1e24:	00695021 */ 	addu	$t2,$v1,$t1
/*  f1a1e28:	ad010000 */ 	sw	$at,0x0($t0)
/*  f1a1e2c:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f1a1e30:	03e00008 */ 	jr	$ra
/*  f1a1e34:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1e38
/*  f1a1e38:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a1e3c:	3c0e8009 */ 	lui	$t6,%hi(var80088b14)
/*  f1a1e40:	27a30000 */ 	addiu	$v1,$sp,0x0
/*  f1a1e44:	25ce8b14 */ 	addiu	$t6,$t6,%lo(var80088b14)
/*  f1a1e48:	25d90024 */ 	addiu	$t9,$t6,0x24
/*  f1a1e4c:	00604025 */ 	or	$t0,$v1,$zero
.L0f1a1e50:
/*  f1a1e50:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a1e54:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a1e58:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f1a1e5c:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f1a1e60:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f1a1e64:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f1a1e68:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f1a1e6c:	15d9fff8 */ 	bne	$t6,$t9,.L0f1a1e50
/*  f1a1e70:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f1a1e74:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a1e78:	00044880 */ 	sll	$t1,$a0,0x2
/*  f1a1e7c:	00695021 */ 	addu	$t2,$v1,$t1
/*  f1a1e80:	ad010000 */ 	sw	$at,0x0($t0)
/*  f1a1e84:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f1a1e88:	03e00008 */ 	jr	$ra
/*  f1a1e8c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a1e90
/*  f1a1e90:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1a1e94:	3c0f8009 */ 	lui	$t7,%hi(device_descriptions)
/*  f1a1e98:	25ef8b3c */ 	addiu	$t7,$t7,%lo(device_descriptions)
/*  f1a1e9c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1ea0:	25e80024 */ 	addiu	$t0,$t7,0x24
/*  f1a1ea4:	27ae0020 */ 	addiu	$t6,$sp,0x20
.L0f1a1ea8:
/*  f1a1ea8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a1eac:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f1a1eb0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a1eb4:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f1a1eb8:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f1a1ebc:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1a1ec0:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f1a1ec4:	15e8fff8 */ 	bne	$t7,$t0,.L0f1a1ea8
/*  f1a1ec8:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1a1ecc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a1ed0:	3c048009 */ 	lui	$a0,%hi(var80088ad8)
/*  f1a1ed4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a1ed8:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a1edc:	90848ad8 */ 	lbu	$a0,%lo(var80088ad8)($a0)
/*  f1a1ee0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1a1ee4:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f1a1ee8:	0fc5b9f1 */ 	jal	langGet
/*  f1a1eec:	8c840020 */ 	lw	$a0,0x20($a0)
/*  f1a1ef0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1ef4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f1a1ef8:	03e00008 */ 	jr	$ra
/*  f1a1efc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1f00
/*  f1a1f00:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1a1f04:	3c0f8009 */ 	lui	$t7,%hi(device_tips1)
/*  f1a1f08:	25ef8b64 */ 	addiu	$t7,$t7,%lo(device_tips1)
/*  f1a1f0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1f10:	25e80024 */ 	addiu	$t0,$t7,0x24
/*  f1a1f14:	27ae0020 */ 	addiu	$t6,$sp,0x20
.L0f1a1f18:
/*  f1a1f18:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a1f1c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f1a1f20:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a1f24:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f1a1f28:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f1a1f2c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1a1f30:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f1a1f34:	15e8fff8 */ 	bne	$t7,$t0,.L0f1a1f18
/*  f1a1f38:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1a1f3c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a1f40:	3c048009 */ 	lui	$a0,%hi(var80088ad8)
/*  f1a1f44:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a1f48:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a1f4c:	90848ad8 */ 	lbu	$a0,%lo(var80088ad8)($a0)
/*  f1a1f50:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1a1f54:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f1a1f58:	0fc5b9f1 */ 	jal	langGet
/*  f1a1f5c:	8c840020 */ 	lw	$a0,0x20($a0)
/*  f1a1f60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1f64:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f1a1f68:	03e00008 */ 	jr	$ra
/*  f1a1f6c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1f70
/*  f1a1f70:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1a1f74:	3c0f8009 */ 	lui	$t7,%hi(device_tips2)
/*  f1a1f78:	25ef8b8c */ 	addiu	$t7,$t7,%lo(device_tips2)
/*  f1a1f7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a1f80:	25e80024 */ 	addiu	$t0,$t7,0x24
/*  f1a1f84:	27ae0020 */ 	addiu	$t6,$sp,0x20
.L0f1a1f88:
/*  f1a1f88:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a1f8c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f1a1f90:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f1a1f94:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f1a1f98:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f1a1f9c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1a1fa0:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f1a1fa4:	15e8fff8 */ 	bne	$t7,$t0,.L0f1a1f88
/*  f1a1fa8:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1a1fac:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a1fb0:	3c048009 */ 	lui	$a0,%hi(var80088ad8)
/*  f1a1fb4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a1fb8:	0fc6875a */ 	jal	func0f1a1d68
/*  f1a1fbc:	90848ad8 */ 	lbu	$a0,%lo(var80088ad8)($a0)
/*  f1a1fc0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1a1fc4:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f1a1fc8:	0fc5b9f1 */ 	jal	langGet
/*  f1a1fcc:	8c840020 */ 	lw	$a0,0x20($a0)
/*  f1a1fd0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a1fd4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f1a1fd8:	03e00008 */ 	jr	$ra
/*  f1a1fdc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a1fe0
/*  f1a1fe0:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a1fe4:	03e00008 */ 	jr	$ra
/*  f1a1fe8:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
);

GLOBAL_ASM(
glabel func0f1a1fec
/*  f1a1fec:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a1ff0:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
/*  f1a1ff4:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1a1ff8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a1ffc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2000:	00037880 */ 	sll	$t7,$v1,0x2
/*  f1a2004:	05e10008 */ 	bgez	$t7,.L0f1a2028
/*  f1a2008:	0003c840 */ 	sll	$t9,$v1,0x1
/*  f1a200c:	3c048009 */ 	lui	$a0,%hi(menudialog_trainingstats_completed2)
/*  f1a2010:	2484978c */ 	addiu	$a0,$a0,%lo(menudialog_trainingstats_completed2)
/*  f1a2014:	0fc3e178 */ 	jal	func0f0f85e0
/*  f1a2018:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f1a201c:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a2020:	10000008 */ 	beqz	$zero,.L0f1a2044
/*  f1a2024:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
.L0f1a2028:
/*  f1a2028:	07210006 */ 	bgez	$t9,.L0f1a2044
/*  f1a202c:	3c048009 */ 	lui	$a0,%hi(menudialog_trainingstats_failed2)
/*  f1a2030:	248496fc */ 	addiu	$a0,$a0,%lo(menudialog_trainingstats_failed2)
/*  f1a2034:	0fc3e178 */ 	jal	func0f0f85e0
/*  f1a2038:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f1a203c:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a2040:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
.L0f1a2044:
/*  f1a2044:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f1a2048:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a204c:	a0400001 */ 	sb	$zero,0x1($v0)
/*  f1a2050:	310affdf */ 	andi	$t2,$t0,0xffdf
/*  f1a2054:	314c00bf */ 	andi	$t4,$t2,0xbf
/*  f1a2058:	a04a0000 */ 	sb	$t2,0x0($v0)
/*  f1a205c:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f1a2060:	318d00ef */ 	andi	$t5,$t4,0xef
/*  f1a2064:	a04d0000 */ 	sb	$t5,0x0($v0)
/*  f1a2068:	03e00008 */ 	jr	$ra
/*  f1a206c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a2070
/*  f1a2070:	3c0e8009 */ 	lui	$t6,%hi(var80088bb8)
/*  f1a2074:	91ce8bb8 */ 	lbu	$t6,%lo(var80088bb8)($t6)
/*  f1a2078:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a207c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2080:	11c00041 */ 	beqz	$t6,.L0f1a2188
/*  f1a2084:	3c03800b */ 	lui	$v1,%hi(var800ad1b0)
/*  f1a2088:	2463d1b0 */ 	addiu	$v1,$v1,%lo(var800ad1b0)
/*  f1a208c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f1a2090:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f1a2094:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f1a2098:	00027fc2 */ 	srl	$t7,$v0,0x1f
/*  f1a209c:	11e0002c */ 	beqz	$t7,.L0f1a2150
/*  f1a20a0:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f1a20a4:	8c780004 */ 	lw	$t8,0x4($v1)
/*  f1a20a8:	8c990038 */ 	lw	$t9,0x38($a0)
/*  f1a20ac:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f1a20b0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1a20b4:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f1a20b8:	8d2a00d8 */ 	lw	$t2,0xd8($t1)
/*  f1a20bc:	51400004 */ 	beqzl	$t2,.L0f1a20d0
/*  f1a20c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a20c4:	0fc688b5 */ 	jal	func0f1a22d4
/*  f1a20c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a20cc:	00002025 */ 	or	$a0,$zero,$zero
.L0f1a20d0:
/*  f1a20d0:	0fc127da */ 	jal	chrHasStageFlag
/*  f1a20d4:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f1a20d8:	1040000d */ 	beqz	$v0,.L0f1a2110
/*  f1a20dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a20e0:	0fc688b5 */ 	jal	func0f1a22d4
/*  f1a20e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a20e8:	3c03800b */ 	lui	$v1,%hi(var800ad1b0)
/*  f1a20ec:	2463d1b0 */ 	addiu	$v1,$v1,%lo(var800ad1b0)
/*  f1a20f0:	906c0000 */ 	lbu	$t4,0x0($v1)
/*  f1a20f4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a20f8:	a06e0001 */ 	sb	$t6,0x1($v1)
/*  f1a20fc:	35980040 */ 	ori	$t8,$t4,0x40
/*  f1a2100:	a0780000 */ 	sb	$t8,0x0($v1)
/*  f1a2104:	37190010 */ 	ori	$t9,$t8,0x10
/*  f1a2108:	1000001f */ 	beqz	$zero,.L0f1a2188
/*  f1a210c:	a0790000 */ 	sb	$t9,0x0($v1)
.L0f1a2110:
/*  f1a2110:	0fc127da */ 	jal	chrHasStageFlag
/*  f1a2114:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f1a2118:	5040001c */ 	beqzl	$v0,.L0f1a218c
/*  f1a211c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2120:	0fc688b5 */ 	jal	func0f1a22d4
/*  f1a2124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2128:	3c03800b */ 	lui	$v1,%hi(var800ad1b0)
/*  f1a212c:	2463d1b0 */ 	addiu	$v1,$v1,%lo(var800ad1b0)
/*  f1a2130:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f1a2134:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1a2138:	a06b0001 */ 	sb	$t3,0x1($v1)
/*  f1a213c:	352d0020 */ 	ori	$t5,$t1,0x20
/*  f1a2140:	a06d0000 */ 	sb	$t5,0x0($v1)
/*  f1a2144:	35ae0010 */ 	ori	$t6,$t5,0x10
/*  f1a2148:	1000000f */ 	beqz	$zero,.L0f1a2188
/*  f1a214c:	a06e0000 */ 	sb	$t6,0x0($v1)
.L0f1a2150:
/*  f1a2150:	0703000e */ 	bgezl	$t8,.L0f1a218c
/*  f1a2154:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2158:	80620001 */ 	lb	$v0,0x1($v1)
/*  f1a215c:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f1a2160:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f1a2164:	5c400006 */ 	bgtzl	$v0,.L0f1a2180
/*  f1a2168:	8c990038 */ 	lw	$t9,0x38($a0)
/*  f1a216c:	0fc687fb */ 	jal	func0f1a1fec
/*  f1a2170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2174:	10000005 */ 	beqz	$zero,.L0f1a218c
/*  f1a2178:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a217c:	8c990038 */ 	lw	$t9,0x38($a0)
.L0f1a2180:
/*  f1a2180:	00594023 */ 	subu	$t0,$v0,$t9
/*  f1a2184:	a0680001 */ 	sb	$t0,0x1($v1)
.L0f1a2188:
/*  f1a2188:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a218c:
/*  f1a218c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a2190:	03e00008 */ 	jr	$ra
/*  f1a2194:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2198
/*  f1a2198:	3c038009 */ 	lui	$v1,%hi(var80088bb8)
/*  f1a219c:	24638bb8 */ 	addiu	$v1,$v1,%lo(var80088bb8)
/*  f1a21a0:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f1a21a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a21a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a21ac:	15c00018 */ 	bnez	$t6,.L0f1a2210
/*  f1a21b0:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a21b4:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
/*  f1a21b8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1a21bc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1a21c0:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f1a21c4:	3308ff7f */ 	andi	$t0,$t8,0xff7f
/*  f1a21c8:	310a00bf */ 	andi	$t2,$t0,0xbf
/*  f1a21cc:	a0480000 */ 	sb	$t0,0x0($v0)
/*  f1a21d0:	314c00df */ 	andi	$t4,$t2,0xdf
/*  f1a21d4:	a04a0000 */ 	sb	$t2,0x0($v0)
/*  f1a21d8:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f1a21dc:	318d00ef */ 	andi	$t5,$t4,0xef
/*  f1a21e0:	a04d0000 */ 	sb	$t5,0x0($v0)
/*  f1a21e4:	a0400001 */ 	sb	$zero,0x1($v0)
/*  f1a21e8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1a21ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a21f0:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a21f4:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f1a21f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a21fc:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a2200:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f1a2204:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2208:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a220c:	24050080 */ 	addiu	$a1,$zero,0x80
.L0f1a2210:
/*  f1a2210:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2214:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a2218:	03e00008 */ 	jr	$ra
/*  f1a221c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2220
/*  f1a2220:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a2224:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
/*  f1a2228:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1a222c:	3c0e800a */ 	lui	$t6,%hi(g_StageSetup)
/*  f1a2230:	8dced030 */ 	lw	$t6,%lo(g_StageSetup)($t6)
/*  f1a2234:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1a2238:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a223c:	37190080 */ 	ori	$t9,$t8,0x80
/*  f1a2240:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f1a2244:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1a2248:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a224c:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f1a2250:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a2254:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1a2258:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a225c:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a2260:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f1a2264:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2268:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a226c:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f1a2270:	3c048009 */ 	lui	$a0,%hi(var80088bb4)
/*  f1a2274:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a2278:	90848bb4 */ 	lbu	$a0,%lo(var80088bb4)($a0)
/*  f1a227c:	0fc68970 */ 	jal	func0f1a25c0
/*  f1a2280:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a2284:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2288:	0fc127cb */ 	jal	chrSetStageFlag
/*  f1a228c:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a2290:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f1a2294:	24440200 */ 	addiu	$a0,$v0,0x200
/*  f1a2298:	0fc45692 */ 	jal	func0f115a48
/*  f1a229c:	24450310 */ 	addiu	$a1,$v0,0x310
/*  f1a22a0:	3c09800a */ 	lui	$t1,0x800a
/*  f1a22a4:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f1a22a8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1a22ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a22b0:	0fc2a4ab */ 	jal	func0f0a92ac
/*  f1a22b4:	ad281c08 */ 	sw	$t0,0x1c08($t1)
/*  f1a22b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a22bc:	0fc127cb */ 	jal	chrSetStageFlag
/*  f1a22c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a22c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a22c8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1a22cc:	03e00008 */ 	jr	$ra
/*  f1a22d0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a22d4
/*  f1a22d4:	27bdfda8 */ 	addiu	$sp,$sp,-600
/*  f1a22d8:	3c0e8009 */ 	lui	$t6,%hi(var80088bbc)
/*  f1a22dc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1a22e0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1a22e4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1a22e8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a22ec:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a22f0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a22f4:	25ce8bbc */ 	addiu	$t6,$t6,%lo(var80088bbc)
/*  f1a22f8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a22fc:	27b20044 */ 	addiu	$s2,$sp,0x44
/*  f1a2300:	3c02800b */ 	lui	$v0,%hi(var800ad1b0)
/*  f1a2304:	ae410000 */ 	sw	$at,0x0($s2)
/*  f1a2308:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1a230c:	2442d1b0 */ 	addiu	$v0,$v0,%lo(var800ad1b0)
/*  f1a2310:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f1a2314:	ae590004 */ 	sw	$t9,0x4($s2)
/*  f1a2318:	95c10008 */ 	lhu	$at,0x8($t6)
/*  f1a231c:	3c10800a */ 	lui	$s0,%hi(g_StageSetup)
/*  f1a2320:	3109ff7f */ 	andi	$t1,$t0,0xff7f
/*  f1a2324:	a6410008 */ 	sh	$at,0x8($s2)
/*  f1a2328:	8e10d030 */ 	lw	$s0,%lo(g_StageSetup)($s0)
/*  f1a232c:	a0490000 */ 	sb	$t1,0x0($v0)
/*  f1a2330:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2334:	0fc127cb */ 	jal	chrSetStageFlag
/*  f1a2338:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f1a233c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2340:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a2344:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f1a2348:	3c048009 */ 	lui	$a0,%hi(var80088bb4)
/*  f1a234c:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a2350:	90848bb4 */ 	lbu	$a0,%lo(var80088bb4)($a0)
/*  f1a2354:	0fc68970 */ 	jal	func0f1a25c0
/*  f1a2358:	00402025 */ 	or	$a0,$v0,$zero
/*  f1a235c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2360:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a2364:	00402825 */ 	or	$a1,$v0,$zero
/*  f1a2368:	26040200 */ 	addiu	$a0,$s0,0x200
/*  f1a236c:	0fc4569e */ 	jal	func0f115a78
/*  f1a2370:	26050310 */ 	addiu	$a1,$s0,0x310
/*  f1a2374:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f1a2378:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f1a237c:	8e8a0284 */ 	lw	$t2,0x284($s4)
/*  f1a2380:	27b10050 */ 	addiu	$s1,$sp,0x50
/*  f1a2384:	02202825 */ 	or	$a1,$s1,$zero
/*  f1a2388:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a238c:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f1a2390:	0fc197e0 */ 	jal	roomGetProps
/*  f1a2394:	ad401c08 */ 	sw	$zero,0x1c08($t2)
/*  f1a2398:	87ab0050 */ 	lh	$t3,0x50($sp)
/*  f1a239c:	02208025 */ 	or	$s0,$s1,$zero
/*  f1a23a0:	27ac0050 */ 	addiu	$t4,$sp,0x50
/*  f1a23a4:	05600017 */ 	bltz	$t3,.L0f1a2404
/*  f1a23a8:	24130008 */ 	addiu	$s3,$zero,0x8
/*  f1a23ac:	85830000 */ 	lh	$v1,0x0($t4)
/*  f1a23b0:	24120004 */ 	addiu	$s2,$zero,0x4
/*  f1a23b4:	24110048 */ 	addiu	$s1,$zero,0x48
.L0f1a23b8:
/*  f1a23b8:	00710019 */ 	multu	$v1,$s1
/*  f1a23bc:	8e980338 */ 	lw	$t8,0x338($s4)
/*  f1a23c0:	00006812 */ 	mflo	$t5
/*  f1a23c4:	01b81021 */ 	addu	$v0,$t5,$t8
/*  f1a23c8:	5040000b */ 	beqzl	$v0,.L0f1a23f8
/*  f1a23cc:	86030002 */ 	lh	$v1,0x2($s0)
/*  f1a23d0:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f1a23d4:	564f0008 */ 	bnel	$s2,$t7,.L0f1a23f8
/*  f1a23d8:	86030002 */ 	lh	$v1,0x2($s0)
/*  f1a23dc:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1a23e0:	908e0003 */ 	lbu	$t6,0x3($a0)
/*  f1a23e4:	566e0004 */ 	bnel	$s3,$t6,.L0f1a23f8
/*  f1a23e8:	86030002 */ 	lh	$v1,0x2($s0)
/*  f1a23ec:	0fc1acd3 */ 	jal	setupParseObjectWithArg2False
/*  f1a23f0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a23f4:	86030002 */ 	lh	$v1,0x2($s0)
.L0f1a23f8:
/*  f1a23f8:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f1a23fc:	0461ffee */ 	bgez	$v1,.L0f1a23b8
/*  f1a2400:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1a2404:
/*  f1a2404:	0fc2a4ab */ 	jal	func0f0a92ac
/*  f1a2408:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1a240c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a2410:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f1a2414:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a2418:	0fc2eda7 */ 	jal	func0f0bb69c
/*  f1a241c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2420:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a2424:	44812000 */ 	mtc1	$at,$f4
/*  f1a2428:	8e990284 */ 	lw	$t9,0x284($s4)
/*  f1a242c:	e72400dc */ 	swc1	$f4,0xdc($t9)
/*  f1a2430:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1a2434:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1a2438:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1a243c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a2440:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a2444:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a2448:	03e00008 */ 	jr	$ra
/*  f1a244c:	27bd0258 */ 	addiu	$sp,$sp,0x258
);

bool func0f1a2450(u32 value)
{
	switch (value) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		return true;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f1a2484
/*  f1a2484:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a2488:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1a248c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1a2490:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1a2494:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a2498:	00008825 */ 	or	$s1,$zero,$zero
/*  f1a249c:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a24a0:	24120007 */ 	addiu	$s2,$zero,0x7
.L0f1a24a4:
/*  f1a24a4:	0fc68914 */ 	jal	func0f1a2450
/*  f1a24a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a24ac:	10400002 */ 	beqz	$v0,.L0f1a24b8
/*  f1a24b0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a24b4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a24b8:
/*  f1a24b8:	1612fffa */ 	bne	$s0,$s2,.L0f1a24a4
/*  f1a24bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a24c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a24c4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1a24c8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1a24cc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1a24d0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1a24d4:	03e00008 */ 	jr	$ra
/*  f1a24d8:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a24dc
/*  f1a24dc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a24e0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1a24e4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1a24e8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1a24ec:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1a24f0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1a24f4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a24f8:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f1a24fc:	00008025 */ 	or	$s0,$zero,$zero
/*  f1a2500:	24120007 */ 	addiu	$s2,$zero,0x7
.L0f1a2504:
/*  f1a2504:	0fc68914 */ 	jal	func0f1a2450
/*  f1a2508:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a250c:	10400002 */ 	beqz	$v0,.L0f1a2518
/*  f1a2510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2514:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1a2518:
/*  f1a2518:	56330004 */ 	bnel	$s1,$s3,.L0f1a252c
/*  f1a251c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1a2520:	10000005 */ 	beqz	$zero,.L0f1a2538
/*  f1a2524:	02001025 */ 	or	$v0,$s0,$zero
/*  f1a2528:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1a252c:
/*  f1a252c:	1612fff5 */ 	bne	$s0,$s2,.L0f1a2504
/*  f1a2530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2534:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a2538:
/*  f1a2538:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a253c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1a2540:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1a2544:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1a2548:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1a254c:	03e00008 */ 	jr	$ra
/*  f1a2550:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1a2554
/*  f1a2554:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a2558:	3c0e8009 */ 	lui	$t6,%hi(var80088bc8)
/*  f1a255c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2560:	25ce8bc8 */ 	addiu	$t6,$t6,%lo(var80088bc8)
/*  f1a2564:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a2568:	27a2001c */ 	addiu	$v0,$sp,0x1c
/*  f1a256c:	00044080 */ 	sll	$t0,$a0,0x2
/*  f1a2570:	ac410000 */ 	sw	$at,0x0($v0)
/*  f1a2574:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1a2578:	00484821 */ 	addu	$t1,$v0,$t0
/*  f1a257c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1a2580:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f1a2584:	ac410008 */ 	sw	$at,0x8($v0)
/*  f1a2588:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f1a258c:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f1a2590:	8dc10010 */ 	lw	$at,0x10($t6)
/*  f1a2594:	ac410010 */ 	sw	$at,0x10($v0)
/*  f1a2598:	8dd90014 */ 	lw	$t9,0x14($t6)
/*  f1a259c:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f1a25a0:	8dc10018 */ 	lw	$at,0x18($t6)
/*  f1a25a4:	ac410018 */ 	sw	$at,0x18($v0)
/*  f1a25a8:	0fc5b9f1 */ 	jal	langGet
/*  f1a25ac:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f1a25b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a25b4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a25b8:	03e00008 */ 	jr	$ra
/*  f1a25bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a25c0
/*  f1a25c0:	3c0e8009 */ 	lui	$t6,%hi(var80088be4)
/*  f1a25c4:	25ce8be4 */ 	addiu	$t6,$t6,%lo(var80088be4)
/*  f1a25c8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f1a25cc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1a25d0:	27a30000 */ 	addiu	$v1,$sp,0x0
/*  f1a25d4:	ac610000 */ 	sw	$at,0x0($v1)
/*  f1a25d8:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f1a25dc:	00044080 */ 	sll	$t0,$a0,0x2
/*  f1a25e0:	00684821 */ 	addu	$t1,$v1,$t0
/*  f1a25e4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1a25e8:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f1a25ec:	ac610008 */ 	sw	$at,0x8($v1)
/*  f1a25f0:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f1a25f4:	ac79000c */ 	sw	$t9,0xc($v1)
/*  f1a25f8:	8dc10010 */ 	lw	$at,0x10($t6)
/*  f1a25fc:	ac610010 */ 	sw	$at,0x10($v1)
/*  f1a2600:	8dd90014 */ 	lw	$t9,0x14($t6)
/*  f1a2604:	ac790014 */ 	sw	$t9,0x14($v1)
/*  f1a2608:	8dc10018 */ 	lw	$at,0x18($t6)
/*  f1a260c:	ac610018 */ 	sw	$at,0x18($v1)
/*  f1a2610:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f1a2614:	ac79001c */ 	sw	$t9,0x1c($v1)
/*  f1a2618:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f1a261c:	03e00008 */ 	jr	$ra
/*  f1a2620:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f1a2624
/*  f1a2624:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a2628:	3c0f8009 */ 	lui	$t7,%hi(var80088c04)
/*  f1a262c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2630:	25ef8c04 */ 	addiu	$t7,$t7,%lo(var80088c04)
/*  f1a2634:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a2638:	27ae001c */ 	addiu	$t6,$sp,0x1c
/*  f1a263c:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a2640:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a2644:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a2648:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a264c:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1a2650:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1a2654:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1a2658:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1a265c:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f1a2660:	adc10010 */ 	sw	$at,0x10($t6)
/*  f1a2664:	8de10018 */ 	lw	$at,0x18($t7)
/*  f1a2668:	3c048009 */ 	lui	$a0,%hi(var80088bb4)
/*  f1a266c:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f1a2670:	adc10018 */ 	sw	$at,0x18($t6)
/*  f1a2674:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a2678:	90848bb4 */ 	lbu	$a0,%lo(var80088bb4)($a0)
/*  f1a267c:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1a2680:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f1a2684:	0fc5b9f1 */ 	jal	langGet
/*  f1a2688:	8c84001c */ 	lw	$a0,0x1c($a0)
/*  f1a268c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2690:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a2694:	03e00008 */ 	jr	$ra
/*  f1a2698:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a269c
/*  f1a269c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a26a0:	3c0f8009 */ 	lui	$t7,%hi(var80088c20)
/*  f1a26a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a26a8:	25ef8c20 */ 	addiu	$t7,$t7,%lo(var80088c20)
/*  f1a26ac:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a26b0:	27ae001c */ 	addiu	$t6,$sp,0x1c
/*  f1a26b4:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a26b8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a26bc:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a26c0:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a26c4:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1a26c8:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1a26cc:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1a26d0:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1a26d4:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f1a26d8:	adc10010 */ 	sw	$at,0x10($t6)
/*  f1a26dc:	8de10018 */ 	lw	$at,0x18($t7)
/*  f1a26e0:	3c048009 */ 	lui	$a0,%hi(var80088bb4)
/*  f1a26e4:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f1a26e8:	adc10018 */ 	sw	$at,0x18($t6)
/*  f1a26ec:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a26f0:	90848bb4 */ 	lbu	$a0,%lo(var80088bb4)($a0)
/*  f1a26f4:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1a26f8:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f1a26fc:	0fc5b9f1 */ 	jal	langGet
/*  f1a2700:	8c84001c */ 	lw	$a0,0x1c($a0)
/*  f1a2704:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2708:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a270c:	03e00008 */ 	jr	$ra
/*  f1a2710:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2714
/*  f1a2714:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a2718:	3c0f8009 */ 	lui	$t7,%hi(var80088c3c)
/*  f1a271c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2720:	25ef8c3c */ 	addiu	$t7,$t7,%lo(var80088c3c)
/*  f1a2724:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a2728:	27ae001c */ 	addiu	$t6,$sp,0x1c
/*  f1a272c:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a2730:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a2734:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a2738:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a273c:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1a2740:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1a2744:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1a2748:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1a274c:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f1a2750:	adc10010 */ 	sw	$at,0x10($t6)
/*  f1a2754:	8de10018 */ 	lw	$at,0x18($t7)
/*  f1a2758:	3c048009 */ 	lui	$a0,%hi(var80088bb4)
/*  f1a275c:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f1a2760:	adc10018 */ 	sw	$at,0x18($t6)
/*  f1a2764:	0fc68937 */ 	jal	func0f1a24dc
/*  f1a2768:	90848bb4 */ 	lbu	$a0,%lo(var80088bb4)($a0)
/*  f1a276c:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1a2770:	03a92021 */ 	addu	$a0,$sp,$t1
/*  f1a2774:	0fc5b9f1 */ 	jal	langGet
/*  f1a2778:	8c84001c */ 	lw	$a0,0x1c($a0)
/*  f1a277c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2780:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a2784:	03e00008 */ 	jr	$ra
/*  f1a2788:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a278c
/*  f1a278c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a2790:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2794:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a2798:	0fc5b9f1 */ 	jal	langGet
/*  f1a279c:	240459a1 */ 	addiu	$a0,$zero,0x59a1
/*  f1a27a0:	3c057f1c */ 	lui	$a1,%hi(var7f1b9180)
/*  f1a27a4:	3c07800b */ 	lui	$a3,%hi(var800acd24)
/*  f1a27a8:	90e7cd24 */ 	lbu	$a3,%lo(var800acd24)($a3)
/*  f1a27ac:	24a59180 */ 	addiu	$a1,$a1,%lo(var7f1b9180)
/*  f1a27b0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1a27b4:	0c004dad */ 	jal	sprintf
/*  f1a27b8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a27bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a27c0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a27c4:	03e00008 */ 	jr	$ra
/*  f1a27c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a27cc
/*  f1a27cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a27d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a27d4:	3c057f1c */ 	lui	$a1,%hi(var7f1b9188)
/*  f1a27d8:	3c06800b */ 	lui	$a2,0x800b
/*  f1a27dc:	90c6d175 */ 	lbu	$a2,-0x2e8b($a2)
/*  f1a27e0:	0c004dad */ 	jal	sprintf
/*  f1a27e4:	24a59188 */ 	addiu	$a1,$a1,%lo(var7f1b9188)
/*  f1a27e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a27ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a27f0:	03e00008 */ 	jr	$ra
/*  f1a27f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a27f8
/*  f1a27f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a27fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2800:	3c057f1c */ 	lui	$a1,%hi(var7f1b9190)
/*  f1a2804:	3c06800b */ 	lui	$a2,%hi(var800ad170)
/*  f1a2808:	8cc6d170 */ 	lw	$a2,%lo(var800ad170)($a2)
/*  f1a280c:	0c004dad */ 	jal	sprintf
/*  f1a2810:	24a59190 */ 	addiu	$a1,$a1,%lo(var7f1b9190)
/*  f1a2814:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2818:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a281c:	03e00008 */ 	jr	$ra
/*  f1a2820:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2824
/*  f1a2824:	3c0e800b */ 	lui	$t6,0x800b
/*  f1a2828:	95cecd22 */ 	lhu	$t6,-0x32de($t6)
/*  f1a282c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a2830:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2834:	11c0000c */ 	beqz	$t6,.L0f1a2868
/*  f1a2838:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a283c:	0fc5b9f1 */ 	jal	langGet
/*  f1a2840:	240459a2 */ 	addiu	$a0,$zero,0x59a2
/*  f1a2844:	3c057f1c */ 	lui	$a1,%hi(var7f1b9198)
/*  f1a2848:	3c07800b */ 	lui	$a3,0x800b
/*  f1a284c:	94e7cd22 */ 	lhu	$a3,-0x32de($a3)
/*  f1a2850:	24a59198 */ 	addiu	$a1,$a1,%lo(var7f1b9198)
/*  f1a2854:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1a2858:	0c004dad */ 	jal	sprintf
/*  f1a285c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2860:	10000006 */ 	beqz	$zero,.L0f1a287c
/*  f1a2864:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a2868:
/*  f1a2868:	3c057f1c */ 	lui	$a1,%hi(var7f1b91a0)
/*  f1a286c:	24a591a0 */ 	addiu	$a1,$a1,%lo(var7f1b91a0)
/*  f1a2870:	0c004dad */ 	jal	sprintf
/*  f1a2874:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1a2878:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1a287c:
/*  f1a287c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1a2880:	03e00008 */ 	jr	$ra
/*  f1a2884:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2888
/*  f1a2888:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f1a288c:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f1a2890:	944e0462 */ 	lhu	$t6,0x462($v0)
/*  f1a2894:	944f045c */ 	lhu	$t7,0x45c($v0)
/*  f1a2898:	9459045e */ 	lhu	$t9,0x45e($v0)
/*  f1a289c:	94490460 */ 	lhu	$t1,0x460($v0)
/*  f1a28a0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f1a28a4:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1a28a8:	01095021 */ 	addu	$t2,$t0,$t1
/*  f1a28ac:	448a2000 */ 	mtc1	$t2,$f4
/*  f1a28b0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f1a28b4:	44810000 */ 	mtc1	$at,$f0
/*  f1a28b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a28bc:	94430458 */ 	lhu	$v1,0x458($v0)
/*  f1a28c0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a28c4:	3c057f1c */ 	lui	$a1,%hi(var7f1b91a4)
/*  f1a28c8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1a28cc:	24a591a4 */ 	addiu	$a1,$a1,%lo(var7f1b91a4)
/*  f1a28d0:	46003302 */ 	mul.s	$f12,$f6,$f0
/*  f1a28d4:	10600009 */ 	beqz	$v1,.L0f1a28fc
/*  f1a28d8:	46000086 */ 	mov.s	$f2,$f0
/*  f1a28dc:	44834000 */ 	mtc1	$v1,$f8
/*  f1a28e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a28e4:	04610004 */ 	bgez	$v1,.L0f1a28f8
/*  f1a28e8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1a28ec:	44818000 */ 	mtc1	$at,$f16
/*  f1a28f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a28f4:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f1a28f8:
/*  f1a28f8:	460a6083 */ 	div.s	$f2,$f12,$f10
.L0f1a28fc:
/*  f1a28fc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1a2900:	3c067f1c */ 	lui	$a2,%hi(var7f1b91b0)
/*  f1a2904:	3c077f1c */ 	lui	$a3,%hi(var7f1b91b4)
/*  f1a2908:	24e791b4 */ 	addiu	$a3,$a3,%lo(var7f1b91b4)
/*  f1a290c:	45000002 */ 	bc1f	.L0f1a2918
/*  f1a2910:	24c691b0 */ 	addiu	$a2,$a2,%lo(var7f1b91b0)
/*  f1a2914:	46000086 */ 	mov.s	$f2,$f0
.L0f1a2918:
/*  f1a2918:	460014a1 */ 	cvt.d.s	$f18,$f2
/*  f1a291c:	e7a20020 */ 	swc1	$f2,0x20($sp)
/*  f1a2920:	0c004dad */ 	jal	sprintf
/*  f1a2924:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f1a2928:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1a292c:	c7a20020 */ 	lwc1	$f2,0x20($sp)
/*  f1a2930:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a2934:	03e00008 */ 	jr	$ra
/*  f1a2938:	46001006 */ 	mov.s	$f0,$f2
);

GLOBAL_ASM(
glabel func0f1a293c
/*  f1a293c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1a2940:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2944:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1a2948:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1a294c:	0fc5b9f1 */ 	jal	langGet
/*  f1a2950:	240459a3 */ 	addiu	$a0,$zero,0x59a3
/*  f1a2954:	3c057f1c */ 	lui	$a1,%hi(var7f1b91b8)
/*  f1a2958:	3c07800b */ 	lui	$a3,%hi(var800acd28)
/*  f1a295c:	90e7cd28 */ 	lbu	$a3,%lo(var800acd28)($a3)
/*  f1a2960:	24a591b8 */ 	addiu	$a1,$a1,%lo(var7f1b91b8)
/*  f1a2964:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1a2968:	0c004dad */ 	jal	sprintf
/*  f1a296c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2970:	3c0e800b */ 	lui	$t6,%hi(var800acd28)
/*  f1a2974:	91cecd28 */ 	lbu	$t6,%lo(var800acd28)($t6)
/*  f1a2978:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f1a297c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2980:	448e3000 */ 	mtc1	$t6,$f6
/*  f1a2984:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a2988:	05c10004 */ 	bgez	$t6,.L0f1a299c
/*  f1a298c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a2990:	44815000 */ 	mtc1	$at,$f10
/*  f1a2994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2998:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1a299c:
/*  f1a299c:	4608203c */ 	c.lt.s	$f4,$f8
/*  f1a29a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a29a4:	45000002 */ 	bc1f	.L0f1a29b0
/*  f1a29a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a29ac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a29b0:
/*  f1a29b0:	03e00008 */ 	jr	$ra
/*  f1a29b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f1a29b8
/*  f1a29b8:	3c06800b */ 	lui	$a2,%hi(var800acd20)
/*  f1a29bc:	24c6cd20 */ 	addiu	$a2,$a2,%lo(var800acd20)
/*  f1a29c0:	8cc3044c */ 	lw	$v1,0x44c($a2)
/*  f1a29c4:	3c014270 */ 	lui	$at,0x4270
/*  f1a29c8:	44814000 */ 	mtc1	$at,$f8
/*  f1a29cc:	44832000 */ 	mtc1	$v1,$f4
/*  f1a29d0:	90c50005 */ 	lbu	$a1,0x5($a2)
/*  f1a29d4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a29d8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a29dc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a29e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a29e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a29e8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1a29ec:	00004025 */ 	or	$t0,$zero,$zero
/*  f1a29f0:	10a1000f */ 	beq	$a1,$at,.L0f1a2a30
/*  f1a29f4:	46083083 */ 	div.s	$f2,$f6,$f8
/*  f1a29f8:	44855000 */ 	mtc1	$a1,$f10
/*  f1a29fc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1a2a00:	04a10004 */ 	bgez	$a1,.L0f1a2a14
/*  f1a2a04:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f1a2a08:	44818000 */ 	mtc1	$at,$f16
/*  f1a2a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a10:	46100000 */ 	add.s	$f0,$f0,$f16
.L0f1a2a14:
/*  f1a2a14:	4602003e */ 	c.le.s	$f0,$f2
/*  f1a2a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a1c:	45000004 */ 	bc1f	.L0f1a2a30
/*  f1a2a20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a24:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1a2a28:	10000004 */ 	beqz	$zero,.L0f1a2a3c
/*  f1a2a2c:	46000086 */ 	mov.s	$f2,$f0
.L0f1a2a30:
/*  f1a2a30:	04630003 */ 	bgezl	$v1,.L0f1a2a40
/*  f1a2a34:	44809000 */ 	mtc1	$zero,$f18
/*  f1a2a38:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1a2a3c:
/*  f1a2a3c:	44809000 */ 	mtc1	$zero,$f18
.L0f1a2a40:
/*  f1a2a40:	3c014270 */ 	lui	$at,0x4270
/*  f1a2a44:	44810000 */ 	mtc1	$at,$f0
/*  f1a2a48:	4612103c */ 	c.lt.s	$f2,$f18
/*  f1a2a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a50:	45020004 */ 	bc1fl	.L0f1a2a64
/*  f1a2a54:	4602003e */ 	c.le.s	$f0,$f2
/*  f1a2a58:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1a2a5c:	46001087 */ 	neg.s	$f2,$f2
/*  f1a2a60:	4602003e */ 	c.le.s	$f0,$f2
.L0f1a2a64:
/*  f1a2a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a68:	4500000b */ 	bc1f	.L0f1a2a98
/*  f1a2a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a70:	4602003e */ 	c.le.s	$f0,$f2
/*  f1a2a74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a78:	45000007 */ 	bc1f	.L0f1a2a98
/*  f1a2a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a80:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f1a2a84:
/*  f1a2a84:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1a2a88:	4602003e */ 	c.le.s	$f0,$f2
/*  f1a2a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2a90:	4503fffc */ 	bc1tl	.L0f1a2a84
/*  f1a2a94:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f1a2a98:
/*  f1a2a98:	01220019 */ 	multu	$t1,$v0
/*  f1a2a9c:	4600110d */ 	trunc.w.s	$f4,$f2
/*  f1a2aa0:	3c057f1c */ 	lui	$a1,%hi(var7f1b91c4)
/*  f1a2aa4:	24a591c4 */ 	addiu	$a1,$a1,%lo(var7f1b91c4)
/*  f1a2aa8:	a3a8001b */ 	sb	$t0,0x1b($sp)
/*  f1a2aac:	44072000 */ 	mfc1	$a3,$f4
/*  f1a2ab0:	00003012 */ 	mflo	$a2
/*  f1a2ab4:	0c004dad */ 	jal	sprintf
/*  f1a2ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2abc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2ac0:	93a2001b */ 	lbu	$v0,0x1b($sp)
/*  f1a2ac4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a2ac8:	03e00008 */ 	jr	$ra
/*  f1a2acc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2ad0
/*  f1a2ad0:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f1a2ad4:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
/*  f1a2ad8:	8c62044c */ 	lw	$v0,0x44c($v1)
/*  f1a2adc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1a2ae0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1a2ae4:	2841ff4c */ 	slti	$at,$v0,-180
/*  f1a2ae8:	1020000a */ 	beqz	$at,.L0f1a2b14
/*  f1a2aec:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1a2af0:	0fc5b9f1 */ 	jal	langGet
/*  f1a2af4:	240459a4 */ 	addiu	$a0,$zero,0x59a4
/*  f1a2af8:	3c057f1c */ 	lui	$a1,%hi(var7f1b91d0)
/*  f1a2afc:	24a591d0 */ 	addiu	$a1,$a1,%lo(var7f1b91d0)
/*  f1a2b00:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f1a2b04:	0c004dad */ 	jal	sprintf
/*  f1a2b08:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2b0c:	10000029 */ 	beqz	$zero,.L0f1a2bb4
/*  f1a2b10:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a2b14:
/*  f1a2b14:	0443000b */ 	bgezl	$v0,.L0f1a2b44
/*  f1a2b18:	90620005 */ 	lbu	$v0,0x5($v1)
/*  f1a2b1c:	0fc5b9f1 */ 	jal	langGet
/*  f1a2b20:	240459a5 */ 	addiu	$a0,$zero,0x59a5
/*  f1a2b24:	3c057f1c */ 	lui	$a1,%hi(var7f1b91d4)
/*  f1a2b28:	24a591d4 */ 	addiu	$a1,$a1,%lo(var7f1b91d4)
/*  f1a2b2c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f1a2b30:	0c004dad */ 	jal	sprintf
/*  f1a2b34:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2b38:	1000001e */ 	beqz	$zero,.L0f1a2bb4
/*  f1a2b3c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a2b40:	90620005 */ 	lbu	$v0,0x5($v1)
.L0f1a2b44:
/*  f1a2b44:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a2b48:	240459a6 */ 	addiu	$a0,$zero,0x59a6
/*  f1a2b4c:	14410003 */ 	bne	$v0,$at,.L0f1a2b5c
/*  f1a2b50:	00401825 */ 	or	$v1,$v0,$zero
/*  f1a2b54:	10000017 */ 	beqz	$zero,.L0f1a2bb4
/*  f1a2b58:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a2b5c:
/*  f1a2b5c:	2841003c */ 	slti	$at,$v0,0x3c
/*  f1a2b60:	14200008 */ 	bnez	$at,.L0f1a2b84
/*  f1a2b64:	00003825 */ 	or	$a3,$zero,$zero
/*  f1a2b68:	2841003c */ 	slti	$at,$v0,0x3c
/*  f1a2b6c:	54200006 */ 	bnezl	$at,.L0f1a2b88
/*  f1a2b70:	afa30024 */ 	sw	$v1,0x24($sp)
.L0f1a2b74:
/*  f1a2b74:	2463ffc4 */ 	addiu	$v1,$v1,-60
/*  f1a2b78:	2861003c */ 	slti	$at,$v1,0x3c
/*  f1a2b7c:	1020fffd */ 	beqz	$at,.L0f1a2b74
/*  f1a2b80:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f1a2b84:
/*  f1a2b84:	afa30024 */ 	sw	$v1,0x24($sp)
.L0f1a2b88:
/*  f1a2b88:	0fc5b9f1 */ 	jal	langGet
/*  f1a2b8c:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f1a2b90:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f1a2b94:	3c057f1c */ 	lui	$a1,%hi(var7f1b91d8)
/*  f1a2b98:	24a591d8 */ 	addiu	$a1,$a1,%lo(var7f1b91d8)
/*  f1a2b9c:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f1a2ba0:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f1a2ba4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2ba8:	0c004dad */ 	jal	sprintf
/*  f1a2bac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f1a2bb0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a2bb4:
/*  f1a2bb4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1a2bb8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1a2bbc:	03e00008 */ 	jr	$ra
/*  f1a2bc0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2bc4
.late_rodata
glabel var7f1b97a0
.word 0x7f1a2ca8
glabel var7f1b97a4
.word 0x7f1a2ccc
glabel var7f1b97a8
.word 0x7f1a2d5c
glabel var7f1b97ac
.word 0x7f1a2d5c
glabel var7f1b97b0
.word 0x7f1a2cf0
glabel var7f1b97b4
.word 0x7f1a2d5c
glabel var7f1b97b8
.word 0x7f1a2d5c
glabel var7f1b97bc
.word 0x7f1a2d5c
glabel var7f1b97c0
.word 0x7f1a2d5c
glabel var7f1b97c4
.word 0x7f1a2d14
glabel var7f1b97c8
.word 0x7f1a2d38
.text
/*  f1a2bc4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f1a2bc8:	3c0f8009 */ 	lui	$t7,%hi(var80088c58)
/*  f1a2bcc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1a2bd0:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f1a2bd4:	25ef8c58 */ 	addiu	$t7,$t7,%lo(var80088c58)
/*  f1a2bd8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1a2bdc:	27ae0024 */ 	addiu	$t6,$sp,0x24
/*  f1a2be0:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1a2be4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1a2be8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1a2bec:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1a2bf0:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1a2bf4:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1a2bf8:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1a2bfc:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f1a2c00:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
/*  f1a2c04:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1a2c08:	adc10010 */ 	sw	$at,0x10($t6)
/*  f1a2c0c:	90620471 */ 	lbu	$v0,0x471($v1)
/*  f1a2c10:	3c0a800a */ 	lui	$t2,0x800a
/*  f1a2c14:	50400058 */ 	beqzl	$v0,.L0f1a2d78
/*  f1a2c18:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a2c1c:	80690472 */ 	lb	$t1,0x472($v1)
/*  f1a2c20:	8d4a9ff8 */ 	lw	$t2,-0x6008($t2)
/*  f1a2c24:	2401000b */ 	addiu	$at,$zero,0xb
/*  f1a2c28:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f1a2c2c:	a06b0472 */ 	sb	$t3,0x472($v1)
/*  f1a2c30:	806c0472 */ 	lb	$t4,0x472($v1)
/*  f1a2c34:	1d800005 */ 	bgtz	$t4,.L0f1a2c4c
/*  f1a2c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2c3c:	a0600471 */ 	sb	$zero,0x471($v1)
/*  f1a2c40:	a0600472 */ 	sb	$zero,0x472($v1)
/*  f1a2c44:	1000004c */ 	beqz	$zero,.L0f1a2d78
/*  f1a2c48:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a2c4c:
/*  f1a2c4c:	14410007 */ 	bne	$v0,$at,.L0f1a2c6c
/*  f1a2c50:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2c54:	3c057f1c */ 	lui	$a1,%hi(var7f1b91e8)
/*  f1a2c58:	0c004dad */ 	jal	sprintf
/*  f1a2c5c:	24a591e8 */ 	addiu	$a1,$a1,%lo(var7f1b91e8)
/*  f1a2c60:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f1a2c64:	10000006 */ 	beqz	$zero,.L0f1a2c80
/*  f1a2c68:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
.L0f1a2c6c:
/*  f1a2c6c:	3c057f1c */ 	lui	$a1,%hi(var7f1b91f0)
/*  f1a2c70:	0c004dad */ 	jal	sprintf
/*  f1a2c74:	24a591f0 */ 	addiu	$a1,$a1,%lo(var7f1b91f0)
/*  f1a2c78:	3c03800b */ 	lui	$v1,%hi(var800acd20)
/*  f1a2c7c:	2463cd20 */ 	addiu	$v1,$v1,%lo(var800acd20)
.L0f1a2c80:
/*  f1a2c80:	906d0471 */ 	lbu	$t5,0x471($v1)
/*  f1a2c84:	25b9ffff */ 	addiu	$t9,$t5,-1
/*  f1a2c88:	2f21000b */ 	sltiu	$at,$t9,0xb
/*  f1a2c8c:	10200033 */ 	beqz	$at,.L0f1a2d5c
/*  f1a2c90:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1a2c94:	3c017f1c */ 	lui	$at,%hi(var7f1b97a0)
/*  f1a2c98:	00390821 */ 	addu	$at,$at,$t9
/*  f1a2c9c:	8c3997a0 */ 	lw	$t9,%lo(var7f1b97a0)($at)
/*  f1a2ca0:	03200008 */ 	jr	$t9
/*  f1a2ca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2ca8:	0fc5b9f1 */ 	jal	langGet
/*  f1a2cac:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f1a2cb0:	3c057f1c */ 	lui	$a1,%hi(var7f1b91f8)
/*  f1a2cb4:	24a591f8 */ 	addiu	$a1,$a1,%lo(var7f1b91f8)
/*  f1a2cb8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f1a2cbc:	0c004dad */ 	jal	sprintf
/*  f1a2cc0:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2cc4:	1000002c */ 	beqz	$zero,.L0f1a2d78
/*  f1a2cc8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a2ccc:	0fc5b9f1 */ 	jal	langGet
/*  f1a2cd0:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f1a2cd4:	3c057f1c */ 	lui	$a1,%hi(var7f1b91fc)
/*  f1a2cd8:	24a591fc */ 	addiu	$a1,$a1,%lo(var7f1b91fc)
/*  f1a2cdc:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f1a2ce0:	0c004dad */ 	jal	sprintf
/*  f1a2ce4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2ce8:	10000023 */ 	beqz	$zero,.L0f1a2d78
/*  f1a2cec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a2cf0:	0fc5b9f1 */ 	jal	langGet
/*  f1a2cf4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f1a2cf8:	3c057f1c */ 	lui	$a1,%hi(var7f1b9200)
/*  f1a2cfc:	24a59200 */ 	addiu	$a1,$a1,%lo(var7f1b9200)
/*  f1a2d00:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f1a2d04:	0c004dad */ 	jal	sprintf
/*  f1a2d08:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2d0c:	1000001a */ 	beqz	$zero,.L0f1a2d78
/*  f1a2d10:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a2d14:	0fc5b9f1 */ 	jal	langGet
/*  f1a2d18:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f1a2d1c:	3c057f1c */ 	lui	$a1,%hi(var7f1b9204)
/*  f1a2d20:	24a59204 */ 	addiu	$a1,$a1,%lo(var7f1b9204)
/*  f1a2d24:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f1a2d28:	0c004dad */ 	jal	sprintf
/*  f1a2d2c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2d30:	10000011 */ 	beqz	$zero,.L0f1a2d78
/*  f1a2d34:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a2d38:	0fc5b9f1 */ 	jal	langGet
/*  f1a2d3c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f1a2d40:	3c057f1c */ 	lui	$a1,%hi(var7f1b9208)
/*  f1a2d44:	24a59208 */ 	addiu	$a1,$a1,%lo(var7f1b9208)
/*  f1a2d48:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f1a2d4c:	0c004dad */ 	jal	sprintf
/*  f1a2d50:	00403025 */ 	or	$a2,$v0,$zero
/*  f1a2d54:	10000008 */ 	beqz	$zero,.L0f1a2d78
/*  f1a2d58:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1a2d5c:
/*  f1a2d5c:	3c057f1c */ 	lui	$a1,%hi(var7f1b920c)
/*  f1a2d60:	24a5920c */ 	addiu	$a1,$a1,%lo(var7f1b920c)
/*  f1a2d64:	0c004dad */ 	jal	sprintf
/*  f1a2d68:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f1a2d6c:	10000002 */ 	beqz	$zero,.L0f1a2d78
/*  f1a2d70:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a2d74:	00001025 */ 	or	$v0,$zero,$zero
.L0f1a2d78:
/*  f1a2d78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1a2d7c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1a2d80:	03e00008 */ 	jr	$ra
/*  f1a2d84:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1a2d88
/*  f1a2d88:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1a2d8c:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f1a2d90:	3c0e8008 */ 	lui	$t6,%hi(var8007fb14)
/*  f1a2d94:	8dcefb14 */ 	lw	$t6,%lo(var8007fb14)($t6)
/*  f1a2d98:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1a2d9c:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f1a2da0:	00e03025 */ 	or	$a2,$a3,$zero
/*  f1a2da4:	00808025 */ 	or	$s0,$a0,$zero
/*  f1a2da8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1a2dac:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f1a2db0:	3c078008 */ 	lui	$a3,%hi(var8007fb18)
/*  f1a2db4:	8ce7fb18 */ 	lw	$a3,%lo(var8007fb18)($a3)
/*  f1a2db8:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f1a2dbc:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f1a2dc0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a2dc4:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a2dc8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1a2dcc:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f1a2dd0:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f1a2dd4:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f1a2dd8:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f1a2ddc:	27ac0064 */ 	addiu	$t4,$sp,0x64
/*  f1a2de0:	01f95023 */ 	subu	$t2,$t7,$t9
/*  f1a2de4:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f1a2de8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1a2dec:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a2df0:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1a2df4:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1a2df8:	27a70060 */ 	addiu	$a3,$sp,0x60
/*  f1a2dfc:	0fc54e16 */ 	jal	func0f153858
/*  f1a2e00:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f1a2e04:	0c002f02 */ 	jal	func0000bc08
/*  f1a2e08:	00408025 */ 	or	$s0,$v0,$zero
/*  f1a2e0c:	0c002f06 */ 	jal	func0000bc18
/*  f1a2e10:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f1a2e14:	93a30083 */ 	lbu	$v1,0x83($sp)
/*  f1a2e18:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f1a2e1c:	3c0d8008 */ 	lui	$t5,%hi(var8007fb18)
/*  f1a2e20:	3c0e8008 */ 	lui	$t6,%hi(var8007fb14)
/*  f1a2e24:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1a2e28:	8dcefb14 */ 	lw	$t6,%lo(var8007fb14)($t6)
/*  f1a2e2c:	8dadfb18 */ 	lw	$t5,%lo(var8007fb18)($t5)
/*  f1a2e30:	87b9004c */ 	lh	$t9,0x4c($sp)
/*  f1a2e34:	03017824 */ 	and	$t7,$t8,$at
/*  f1a2e38:	01e34825 */ 	or	$t1,$t7,$v1
/*  f1a2e3c:	00034043 */ 	sra	$t0,$v1,0x1
/*  f1a2e40:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f1a2e44:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f1a2e48:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1a2e4c:	afa90044 */ 	sw	$t1,0x44($sp)
/*  f1a2e50:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a2e54:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1a2e58:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1a2e5c:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f1a2e60:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1a2e64:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a2e68:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1a2e6c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a2e70:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a2e74:	0fc55b92 */ 	jal	func0f156e48
/*  f1a2e78:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f1a2e7c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f1a2e80:	00408025 */ 	or	$s0,$v0,$zero
/*  f1a2e84:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f1a2e88:	10c00030 */ 	beqz	$a2,.L0f1a2f4c
/*  f1a2e8c:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f1a2e90:	3c0a8008 */ 	lui	$t2,%hi(var8007fb04)
/*  f1a2e94:	8d4afb04 */ 	lw	$t2,%lo(var8007fb04)($t2)
/*  f1a2e98:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f1a2e9c:	8ce7fb08 */ 	lw	$a3,%lo(var8007fb08)($a3)
/*  f1a2ea0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1a2ea4:	0fc55cbe */ 	jal	func0f1572f8
/*  f1a2ea8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a2eac:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f1a2eb0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1a2eb4:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f1a2eb8:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f1a2ebc:	27b90064 */ 	addiu	$t9,$sp,0x64
/*  f1a2ec0:	016d7023 */ 	subu	$t6,$t3,$t5
/*  f1a2ec4:	270f0011 */ 	addiu	$t7,$t8,0x11
/*  f1a2ec8:	afae005c */ 	sw	$t6,0x5c($sp)
/*  f1a2ecc:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f1a2ed0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a2ed4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a2ed8:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1a2edc:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1a2ee0:	0fc54e16 */ 	jal	func0f153858
/*  f1a2ee4:	27a70060 */ 	addiu	$a3,$sp,0x60
/*  f1a2ee8:	0c002f02 */ 	jal	func0000bc08
/*  f1a2eec:	00408025 */ 	or	$s0,$v0,$zero
/*  f1a2ef0:	0c002f06 */ 	jal	func0000bc18
/*  f1a2ef4:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f1a2ef8:	3c0a8008 */ 	lui	$t2,%hi(var8007fb08)
/*  f1a2efc:	3c0c8008 */ 	lui	$t4,%hi(var8007fb04)
/*  f1a2f00:	8d8cfb04 */ 	lw	$t4,%lo(var8007fb04)($t4)
/*  f1a2f04:	8d4afb08 */ 	lw	$t2,%lo(var8007fb08)($t2)
/*  f1a2f08:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f1a2f0c:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f1a2f10:	87ae004c */ 	lh	$t6,0x4c($sp)
/*  f1a2f14:	02002025 */ 	or	$a0,$s0,$zero
/*  f1a2f18:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1a2f1c:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1a2f20:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f1a2f24:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1a2f28:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a2f2c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1a2f30:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1a2f34:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a2f38:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1a2f3c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1a2f40:	0fc55b92 */ 	jal	func0f156e48
/*  f1a2f44:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f1a2f48:	00408025 */ 	or	$s0,$v0,$zero
.L0f1a2f4c:
/*  f1a2f4c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1a2f50:	02001025 */ 	or	$v0,$s0,$zero
/*  f1a2f54:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1a2f58:	03e00008 */ 	jr	$ra
/*  f1a2f5c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f1a2f60
.late_rodata
glabel var7f1b97cc
.word 0x4019999a
.text
/*  f1a2f60:	27bdfea8 */ 	addiu	$sp,$sp,-344
/*  f1a2f64:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1a2f68:	240e00a0 */ 	addiu	$t6,$zero,0xa0
/*  f1a2f6c:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f1a2f70:	0c002f22 */ 	jal	func0000bc88
/*  f1a2f74:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f1a2f78:	28410191 */ 	slti	$at,$v0,0x191
/*  f1a2f7c:	14200005 */ 	bnez	$at,.L0f1a2f94
/*  f1a2f80:	3c0f8009 */ 	lui	$t7,%hi(var80088804)
/*  f1a2f84:	3c014000 */ 	lui	$at,0x4000
/*  f1a2f88:	44812000 */ 	mtc1	$at,$f4
/*  f1a2f8c:	10000005 */ 	beqz	$zero,.L0f1a2fa4
/*  f1a2f90:	e7a40048 */ 	swc1	$f4,0x48($sp)
.L0f1a2f94:
/*  f1a2f94:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a2f98:	44813000 */ 	mtc1	$at,$f6
/*  f1a2f9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2fa0:	e7a60048 */ 	swc1	$f6,0x48($sp)
.L0f1a2fa4:
/*  f1a2fa4:	91ef8804 */ 	lbu	$t7,%lo(var80088804)($t7)
/*  f1a2fa8:	3c18800b */ 	lui	$t8,%hi(var800ad184)
/*  f1a2fac:	3c02800b */ 	lui	$v0,%hi(var800ad184)
/*  f1a2fb0:	15e00006 */ 	bnez	$t7,.L0f1a2fcc
/*  f1a2fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2fb8:	8318d184 */ 	lb	$t8,%lo(var800ad184)($t8)
/*  f1a2fbc:	1f000003 */ 	bgtz	$t8,.L0f1a2fcc
/*  f1a2fc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a2fc4:	100000d9 */ 	beqz	$zero,.L0f1a332c
/*  f1a2fc8:	8fa20158 */ 	lw	$v0,0x158($sp)
.L0f1a2fcc:
/*  f1a2fcc:	8042d184 */ 	lb	$v0,%lo(var800ad184)($v0)
/*  f1a2fd0:	1040000c */ 	beqz	$v0,.L0f1a3004
/*  f1a2fd4:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f1a2fd8:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f1a2fdc:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f1a2fe0:	44994000 */ 	mtc1	$t9,$f8
/*  f1a2fe4:	3c014270 */ 	lui	$at,0x4270
/*  f1a2fe8:	44818000 */ 	mtc1	$at,$f16
/*  f1a2fec:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1a2ff0:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f1a2ff4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f1a2ff8:	440b2000 */ 	mfc1	$t3,$f4
/*  f1a2ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3000:	afab004c */ 	sw	$t3,0x4c($sp)
.L0f1a3004:
/*  f1a3004:	0fc54d8a */ 	jal	func0f153628
/*  f1a3008:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f1a300c:	afa20158 */ 	sw	$v0,0x158($sp)
/*  f1a3010:	0fc68a6e */ 	jal	func0f1a29b8
/*  f1a3014:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f1a3018:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f1a301c:	0fc68ab4 */ 	jal	func0f1a2ad0
/*  f1a3020:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f1a3024:	0c002f22 */ 	jal	func0000bc88
/*  f1a3028:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f1a302c:	0c002f44 */ 	jal	func0000bd10
/*  f1a3030:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f1a3034:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f1a3038:	00021c00 */ 	sll	$v1,$v0,0x10
/*  f1a303c:	00036403 */ 	sra	$t4,$v1,0x10
/*  f1a3040:	11a00003 */ 	beqz	$t5,.L0f1a3050
/*  f1a3044:	01801825 */ 	or	$v1,$t4,$zero
/*  f1a3048:	10000002 */ 	beqz	$zero,.L0f1a3054
/*  f1a304c:	27a80058 */ 	addiu	$t0,$sp,0x58
.L0f1a3050:
/*  f1a3050:	00004025 */ 	or	$t0,$zero,$zero
.L0f1a3054:
/*  f1a3054:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f1a3058:	87a5003c */ 	lh	$a1,0x3c($sp)
/*  f1a305c:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f1a3060:	11c00004 */ 	beqz	$t6,.L0f1a3074
/*  f1a3064:	00057843 */ 	sra	$t7,$a1,0x1
/*  f1a3068:	3c02ff00 */ 	lui	$v0,0xff00
/*  f1a306c:	10000003 */ 	beqz	$zero,.L0f1a307c
/*  f1a3070:	344200a0 */ 	ori	$v0,$v0,0xa0
.L0f1a3074:
/*  f1a3074:	3c0200ff */ 	lui	$v0,0xff
/*  f1a3078:	344200a0 */ 	ori	$v0,$v0,0xa0
.L0f1a307c:
/*  f1a307c:	93a9004f */ 	lbu	$t1,0x4f($sp)
/*  f1a3080:	01e02825 */ 	or	$a1,$t7,$zero
/*  f1a3084:	2466000c */ 	addiu	$a2,$v1,0xc
/*  f1a3088:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f1a308c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f1a3090:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1a3094:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f1a3098:	0fc68b62 */ 	jal	func0f1a2d88
/*  f1a309c:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f1a30a0:	afa20158 */ 	sw	$v0,0x158($sp)
/*  f1a30a4:	0fc689fe */ 	jal	func0f1a27f8
/*  f1a30a8:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f1a30ac:	0fc68a09 */ 	jal	func0f1a2824
/*  f1a30b0:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f1a30b4:	0c002f40 */ 	jal	func0000bd00
/*  f1a30b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a30bc:	0c002f44 */ 	jal	func0000bd10
/*  f1a30c0:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f1a30c4:	87b8003c */ 	lh	$t8,0x3c($sp)
/*  f1a30c8:	3c014282 */ 	lui	$at,0x4282
/*  f1a30cc:	44813000 */ 	mtc1	$at,$f6
/*  f1a30d0:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f1a30d4:	44985000 */ 	mtc1	$t8,$f10
/*  f1a30d8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f1a30dc:	46083002 */ 	mul.s	$f0,$f6,$f8
/*  f1a30e0:	3c0b00ff */ 	lui	$t3,0xff
/*  f1a30e4:	356b00a0 */ 	ori	$t3,$t3,0xa0
/*  f1a30e8:	27aa0058 */ 	addiu	$t2,$sp,0x58
/*  f1a30ec:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a30f0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f1a30f4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1a30f8:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f1a30fc:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f1a3100:	2446000c */ 	addiu	$a2,$v0,0xc
/*  f1a3104:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f1a3108:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1a310c:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f1a3110:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f1a3114:	44052000 */ 	mfc1	$a1,$f4
/*  f1a3118:	0fc68b62 */ 	jal	func0f1a2d88
/*  f1a311c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3120:	afa20158 */ 	sw	$v0,0x158($sp)
/*  f1a3124:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f1a3128:	0fc68af1 */ 	jal	func0f1a2bc4
/*  f1a312c:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f1a3130:	10400019 */ 	beqz	$v0,.L0f1a3198
/*  f1a3134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3138:	0c002f40 */ 	jal	func0000bd00
/*  f1a313c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3140:	0c002f44 */ 	jal	func0000bd10
/*  f1a3144:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f1a3148:	87ad003c */ 	lh	$t5,0x3c($sp)
/*  f1a314c:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f1a3150:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f1a3154:	448d3000 */ 	mtc1	$t5,$f6
/*  f1a3158:	3c1800ff */ 	lui	$t8,0xff
/*  f1a315c:	371800a0 */ 	ori	$t8,$t8,0xa0
/*  f1a3160:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1a3164:	27af0058 */ 	addiu	$t7,$sp,0x58
/*  f1a3168:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1a316c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1a3170:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f1a3174:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f1a3178:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f1a317c:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f1a3180:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1a3184:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1a3188:	44059000 */ 	mfc1	$a1,$f18
/*  f1a318c:	0fc68b62 */ 	jal	func0f1a2d88
/*  f1a3190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3194:	afa20158 */ 	sw	$v0,0x158($sp)
.L0f1a3198:
/*  f1a3198:	3c02800b */ 	lui	$v0,%hi(var800acd20)
/*  f1a319c:	2442cd20 */ 	addiu	$v0,$v0,%lo(var800acd20)
/*  f1a31a0:	904a0008 */ 	lbu	$t2,0x8($v0)
/*  f1a31a4:	5940002f */ 	blezl	$t2,.L0f1a3264
/*  f1a31a8:	904b0004 */ 	lbu	$t3,0x4($v0)
/*  f1a31ac:	0fc68a22 */ 	jal	func0f1a2888
/*  f1a31b0:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f1a31b4:	44050000 */ 	mfc1	$a1,$f0
/*  f1a31b8:	0fc68a4f */ 	jal	func0f1a293c
/*  f1a31bc:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f1a31c0:	0c002f40 */ 	jal	func0000bd00
/*  f1a31c4:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f1a31c8:	0c002f22 */ 	jal	func0000bc88
/*  f1a31cc:	a7a20036 */ 	sh	$v0,0x36($sp)
/*  f1a31d0:	0c002f44 */ 	jal	func0000bd10
/*  f1a31d4:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f1a31d8:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f1a31dc:	00021c00 */ 	sll	$v1,$v0,0x10
/*  f1a31e0:	00035c03 */ 	sra	$t3,$v1,0x10
/*  f1a31e4:	11800004 */ 	beqz	$t4,.L0f1a31f8
/*  f1a31e8:	01601825 */ 	or	$v1,$t3,$zero
/*  f1a31ec:	3c02ff00 */ 	lui	$v0,0xff00
/*  f1a31f0:	10000003 */ 	beqz	$zero,.L0f1a3200
/*  f1a31f4:	344200a0 */ 	ori	$v0,$v0,0xa0
.L0f1a31f8:
/*  f1a31f8:	3c0200ff */ 	lui	$v0,0xff
/*  f1a31fc:	344200a0 */ 	ori	$v0,$v0,0xa0
.L0f1a3200:
/*  f1a3200:	87ad003c */ 	lh	$t5,0x3c($sp)
/*  f1a3204:	87ae0036 */ 	lh	$t6,0x36($sp)
/*  f1a3208:	3c01428c */ 	lui	$at,0x428c
/*  f1a320c:	44814000 */ 	mtc1	$at,$f8
/*  f1a3210:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f1a3214:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1a3218:	448f2000 */ 	mtc1	$t7,$f4
/*  f1a321c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f1a3220:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f1a3224:	27b90058 */ 	addiu	$t9,$sp,0x58
/*  f1a3228:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1a322c:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f1a3230:	2466000c */ 	addiu	$a2,$v1,0xc
/*  f1a3234:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1a3238:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f1a323c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1a3240:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f1a3244:	46103481 */ 	sub.s	$f18,$f6,$f16
/*  f1a3248:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f1a324c:	44052000 */ 	mfc1	$a1,$f4
/*  f1a3250:	0fc68b62 */ 	jal	func0f1a2d88
/*  f1a3254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3258:	10000032 */ 	beqz	$zero,.L0f1a3324
/*  f1a325c:	afa20158 */ 	sw	$v0,0x158($sp)
/*  f1a3260:	904b0004 */ 	lbu	$t3,0x4($v0)
.L0f1a3264:
/*  f1a3264:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a3268:	1161002e */ 	beq	$t3,$at,.L0f1a3324
/*  f1a326c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3270:	0fc689f3 */ 	jal	func0f1a27cc
/*  f1a3274:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f1a3278:	0fc689e3 */ 	jal	func0f1a278c
/*  f1a327c:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f1a3280:	3c014000 */ 	lui	$at,0x4000
/*  f1a3284:	44815000 */ 	mtc1	$at,$f10
/*  f1a3288:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f1a328c:	3c017f1c */ 	lui	$at,%hi(var7f1b97cc)
/*  f1a3290:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f1a3294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3298:	45000003 */ 	bc1f	.L0f1a32a8
/*  f1a329c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a32a0:	c42697cc */ 	lwc1	$f6,%lo(var7f1b97cc)($at)
/*  f1a32a4:	e7a60048 */ 	swc1	$f6,0x48($sp)
.L0f1a32a8:
/*  f1a32a8:	0c002f40 */ 	jal	func0000bd00
/*  f1a32ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a32b0:	0c002f22 */ 	jal	func0000bc88
/*  f1a32b4:	a7a20036 */ 	sh	$v0,0x36($sp)
/*  f1a32b8:	0c002f44 */ 	jal	func0000bd10
/*  f1a32bc:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f1a32c0:	87ac003c */ 	lh	$t4,0x3c($sp)
/*  f1a32c4:	87ad0036 */ 	lh	$t5,0x36($sp)
/*  f1a32c8:	3c01428c */ 	lui	$at,0x428c
/*  f1a32cc:	44812000 */ 	mtc1	$at,$f4
/*  f1a32d0:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f1a32d4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f1a32d8:	448e8000 */ 	mtc1	$t6,$f16
/*  f1a32dc:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f1a32e0:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f1a32e4:	3c1900ff */ 	lui	$t9,0xff
/*  f1a32e8:	373900a0 */ 	ori	$t9,$t9,0xa0
/*  f1a32ec:	27b80058 */ 	addiu	$t8,$sp,0x58
/*  f1a32f0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1a32f4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1a32f8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1a32fc:	8fa40158 */ 	lw	$a0,0x158($sp)
/*  f1a3300:	2446000c */ 	addiu	$a2,$v0,0xc
/*  f1a3304:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f1a3308:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f1a330c:	460a9181 */ 	sub.s	$f6,$f18,$f10
/*  f1a3310:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f1a3314:	44058000 */ 	mfc1	$a1,$f16
/*  f1a3318:	0fc68b62 */ 	jal	func0f1a2d88
/*  f1a331c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a3320:	afa20158 */ 	sw	$v0,0x158($sp)
.L0f1a3324:
/*  f1a3324:	0fc54de0 */ 	jal	func0f153780
/*  f1a3328:	8fa40158 */ 	lw	$a0,0x158($sp)
.L0f1a332c:
/*  f1a332c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1a3330:	27bd0158 */ 	addiu	$sp,$sp,0x158
/*  f1a3334:	03e00008 */ 	jr	$ra
/*  f1a3338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1a333c:	00000000 */ 	sll	$zero,$zero,0x0
);
