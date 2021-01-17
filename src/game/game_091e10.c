#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0601b0.h"
#include "game/game_091e10.h"
#include "game/game_0b28d0.h"
#include "game/game_157db0.h"
#include "game/game_1a7560.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_1a500.h"
#include "types.h"

u32 setupGetCommandLength(u32 *cmd)
{
	switch ((u8)cmd[0]) {
	case OBJTYPE_CHR:                return 11;
	case OBJTYPE_DOOR:               return 55;
	case OBJTYPE_DOORSCALE:          return 2;
	case OBJTYPE_BASIC:              return 23;
	case OBJTYPE_DEBRIS:             return 23;
	case OBJTYPE_GLASS:              return 24;
	case OBJTYPE_TINTEDGLASS:        return 26;
	case OBJTYPE_SAFE:               return 23;
	case OBJTYPE_24:                 return 23;
	case OBJTYPE_KEY:                return 24;
	case OBJTYPE_ALARM:              return 23;
	case OBJTYPE_CAMERA:             return 49;
	case OBJTYPE_AMMOCRATE:          return 24;
	case OBJTYPE_WEAPON:             return 26;
	case OBJTYPE_SINGLEMONITOR:      return 53;
	case OBJTYPE_MULTIMONITOR:       return 140;
	case OBJTYPE_HANGINGMONITORS:    return 23;
	case OBJTYPE_AUTOGUN:            return 43;
	case OBJTYPE_LINKGUNS:           return 2;
	case OBJTYPE_HAT:                return 23;
	case OBJTYPE_GRENADEPROB:        return 2;
	case OBJTYPE_LINKLIFTDOOR:       return 5;
	case OBJTYPE_SAFEITEM:           return 5;
	case OBJTYPE_MULTIAMMOCRATE:     return 42;
	case OBJTYPE_SHIELD:             return 26;
	case OBJTYPE_TAG:                return 4;
	case OBJTYPE_RENAMEOBJ:          return 10;
	case OBJTYPE_BEGINOBJECTIVE:     return 4;
	case OBJTYPE_ENDOBJECTIVE:       return 1;
	case OBJECTIVETYPE_DESTROYOBJ:   return 2;
	case OBJECTIVETYPE_COMPFLAGS:    return 2;
	case OBJECTIVETYPE_FAILFLAGS:    return 2;
	case OBJECTIVETYPE_COLLECTOBJ:   return 2;
	case OBJECTIVETYPE_THROWOBJ:     return 2;
	case OBJECTIVETYPE_HOLOGRAPH:    return 4;
	case OBJECTIVETYPE_1F:           return 1;
	case OBJECTIVETYPE_ENTERROOM:    return 4;
	case OBJECTIVETYPE_ATTACHOBJ:    return 5;
	case OBJTYPE_22:                 return 1;
	case OBJTYPE_BRIEFING:           return 4;
	case OBJTYPE_PADLOCKEDDOOR:      return 4;
	case OBJTYPE_TRUCK:              return 34;
	case OBJTYPE_HELI:               return 35;
	case OBJTYPE_TANK:               return 32;
	case OBJTYPE_CAMERA2:            return 7;
	case OBJTYPE_LIFT:               return 37;
	case OBJTYPE_CONDITIONALSCENERY: return 5;
	case OBJTYPE_BLOCKEDPATH:        return 4;
	case OBJTYPE_HOVERBIKE:          return 56;
	case OBJTYPE_HOVERPROP:          return 39;
	case OBJTYPE_FAN:                return 29;
	case OBJTYPE_HOVERCAR:           return 38;
	case OBJTYPE_CHOPPER:            return 58;
	case OBJTYPE_PADEFFECT:          return 3;
	case OBJTYPE_MINE:               return 26;
	case OBJTYPE_ESCASTEP:           return 27;
	}

	return 1;
}

GLOBAL_ASM(
glabel setupGetPtrToCommandByIndex
/*  f092004:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f092008:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09200c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f092010:	3c11800a */ 	lui	$s1,%hi(g_StageSetup+0x10)
/*  f092014:	00809825 */ 	or	$s3,$a0,$zero
/*  f092018:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f09201c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f092020:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f092024:	04800014 */ 	bltz	$a0,.L0f092078
/*  f092028:	8e31d040 */ 	lw	$s1,%lo(g_StageSetup+0x10)($s1)
/*  f09202c:	52200013 */ 	beqzl	$s1,.L0f09207c
/*  f092030:	00001025 */ 	or	$v0,$zero,$zero
/*  f092034:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f092038:	24120034 */ 	addiu	$s2,$zero,0x34
/*  f09203c:	00008025 */ 	or	$s0,$zero,$zero
/*  f092040:	524e000e */ 	beql	$s2,$t6,.L0f09207c
/*  f092044:	00001025 */ 	or	$v0,$zero,$zero
.L0f092048:
/*  f092048:	16130003 */ 	bne	$s0,$s3,.L0f092058
/*  f09204c:	00000000 */ 	nop
/*  f092050:	1000000a */ 	b	.L0f09207c
/*  f092054:	02201025 */ 	or	$v0,$s1,$zero
.L0f092058:
/*  f092058:	0fc24784 */ 	jal	setupGetCommandLength
/*  f09205c:	02202025 */ 	or	$a0,$s1,$zero
/*  f092060:	00027880 */ 	sll	$t7,$v0,0x2
/*  f092064:	01f18821 */ 	addu	$s1,$t7,$s1
/*  f092068:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f09206c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f092070:	1658fff5 */ 	bne	$s2,$t8,.L0f092048
/*  f092074:	00000000 */ 	nop
.L0f092078:
/*  f092078:	00001025 */ 	or	$v0,$zero,$zero
.L0f09207c:
/*  f09207c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f092080:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f092084:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f092088:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f09208c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f092090:	03e00008 */ 	jr	$ra
/*  f092094:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

s32 tagGetCommandIndex(struct tag *tag)
{
	u32 *cmd = g_StageSetup.props;

	if (cmd) {
		s32 cmdindex = 0;

		while ((u8)cmd[0] != OBJTYPE_END) {
			if ((struct tag *)cmd == tag) {
				return cmdindex;
			}

			cmd = cmd + setupGetCommandLength(cmd);
			cmdindex++;
		}
	}

	return -1;
}

GLOBAL_ASM(
glabel setupGetCommandOffset
/*  f092124:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f092128:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f09212c:	3c10800a */ 	lui	$s0,%hi(g_StageSetup+0x10)
/*  f092130:	8e10d040 */ 	lw	$s0,%lo(g_StageSetup+0x10)($s0)
/*  f092134:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f092138:	00809825 */ 	or	$s3,$a0,$zero
/*  f09213c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f092140:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f092144:	12000013 */ 	beqz	$s0,.L0f092194
/*  f092148:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f09214c:	920e0003 */ 	lbu	$t6,0x3($s0)
/*  f092150:	24120034 */ 	addiu	$s2,$zero,0x34
/*  f092154:	00008825 */ 	or	$s1,$zero,$zero
/*  f092158:	524e000f */ 	beql	$s2,$t6,.L0f092198
/*  f09215c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f092160:	8e0f0014 */ 	lw	$t7,0x14($s0)
.L0f092164:
/*  f092164:	166f0003 */ 	bne	$s3,$t7,.L0f092174
/*  f092168:	00000000 */ 	nop
/*  f09216c:	1000000a */ 	b	.L0f092198
/*  f092170:	02201025 */ 	or	$v0,$s1,$zero
.L0f092174:
/*  f092174:	0fc24784 */ 	jal	setupGetCommandLength
/*  f092178:	02002025 */ 	or	$a0,$s0,$zero
/*  f09217c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f092180:	03108021 */ 	addu	$s0,$t8,$s0
/*  f092184:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f092188:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f09218c:	5659fff5 */ 	bnel	$s2,$t9,.L0f092164
/*  f092190:	8e0f0014 */ 	lw	$t7,0x14($s0)
.L0f092194:
/*  f092194:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f092198:
/*  f092198:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f09219c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0921a0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0921a4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0921a8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0921ac:	03e00008 */ 	jr	$ra
/*  f0921b0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

bool propLoad(s32 propnum)
{
	if (g_Props[propnum].filedata == NULL) {
		g_Props[propnum].filedata = fileLoad(g_Props[propnum].fileid);
		func00022d24(g_Props[propnum].filedata);
		return true;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f09220c
/*  f09220c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f092210:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f092214:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f092218:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f09221c:	00c08825 */ 	or	$s1,$a2,$zero
/*  f092220:	00a09025 */ 	or	$s2,$a1,$zero
/*  f092224:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f092228:	0fc1a2bd */ 	jal	func0f068af4
/*  f09222c:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f092230:	1040002d */ 	beqz	$v0,.L0f0922e8
/*  f092234:	00408025 */ 	or	$s0,$v0,$zero
/*  f092238:	00402025 */ 	or	$a0,$v0,$zero
/*  f09223c:	0fc19a3f */ 	jal	func0f0668fc
/*  f092240:	02202825 */ 	or	$a1,$s1,$zero
/*  f092244:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f092248:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f09224c:	02002025 */ 	or	$a0,$s0,$zero
/*  f092250:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f092254:	02202825 */ 	or	$a1,$s1,$zero
/*  f092258:	0fc19a57 */ 	jal	func0f06695c
/*  f09225c:	e5c60000 */ 	swc1	$f6,0x0($t6)
/*  f092260:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f092264:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f092268:	02002025 */ 	or	$a0,$s0,$zero
/*  f09226c:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f092270:	02202825 */ 	or	$a1,$s1,$zero
/*  f092274:	0fc19a6f */ 	jal	func0f0669bc
/*  f092278:	e5ea0004 */ 	swc1	$f10,0x4($t7)
/*  f09227c:	c6500008 */ 	lwc1	$f16,0x8($s2)
/*  f092280:	8fb80034 */ 	lw	$t8,0x34($sp)
/*  f092284:	02002025 */ 	or	$a0,$s0,$zero
/*  f092288:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f09228c:	02202825 */ 	or	$a1,$s1,$zero
/*  f092290:	0fc19a4b */ 	jal	func0f06692c
/*  f092294:	e7120008 */ 	swc1	$f18,0x8($t8)
/*  f092298:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f09229c:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f0922a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0922a4:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0922a8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0922ac:	0fc19a63 */ 	jal	func0f06698c
/*  f0922b0:	e7260000 */ 	swc1	$f6,0x0($t9)
/*  f0922b4:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f0922b8:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0922bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0922c0:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0922c4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0922c8:	0fc19a7b */ 	jal	func0f0669ec
/*  f0922cc:	e50a0004 */ 	swc1	$f10,0x4($t0)
/*  f0922d0:	c6500008 */ 	lwc1	$f16,0x8($s2)
/*  f0922d4:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f0922d8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0922dc:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f0922e0:	10000002 */ 	b	.L0f0922ec
/*  f0922e4:	e5320008 */ 	swc1	$f18,0x8($t1)
.L0f0922e8:
/*  f0922e8:	00001025 */ 	or	$v0,$zero,$zero
.L0f0922ec:
/*  f0922ec:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0922f0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0922f4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0922f8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0922fc:	03e00008 */ 	jr	$ra
/*  f092300:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

bool func0f092304(struct defaultobj *obj, struct coord *arg1, struct coord *arg2)
{
	return func0f09220c(obj, &obj->prop->pos, obj->realrot, arg1, arg2);
}

void func0f09233c(struct defaultobj *obj, struct coord *pos, f32 *realrot, s16 *rooms)
{
	struct coord a;
	struct coord b;
	u32 stack;

	if (func0f09220c(obj, pos, realrot, &a, &b)) {
		a.x -= 1;
		a.y -= 1;
		a.z -= 1;
		b.x += 1;
		b.y += 1;
		b.z += 1;

		func0f1650d0(&a, &b, rooms, 7, 0);
	}
}

void func0f0923d4(struct defaultobj *obj)
{
	func0f065c44(obj->prop);
	func0f09233c(obj, &obj->prop->pos, obj->realrot, obj->prop->rooms);
	func0f065cb0(obj->prop);
}

struct defaultobj *setupCommandGetObject(u32 cmdindex)
{
	u32 *cmd = setupGetPtrToCommandByIndex(cmdindex);

	if (cmd) {
		switch ((u8)cmd[0]) {
		case OBJTYPE_DOOR:
		case OBJTYPE_BASIC:
		case OBJTYPE_KEY:
		case OBJTYPE_ALARM:
		case OBJTYPE_CAMERA:
		case OBJTYPE_AMMOCRATE:
		case OBJTYPE_WEAPON:
		case OBJTYPE_SINGLEMONITOR:
		case OBJTYPE_MULTIMONITOR:
		case OBJTYPE_HANGINGMONITORS:
		case OBJTYPE_AUTOGUN:
		case OBJTYPE_DEBRIS:
		case OBJTYPE_HAT:
		case OBJTYPE_MULTIAMMOCRATE:
		case OBJTYPE_SHIELD:
		case OBJTYPE_24:
		case OBJTYPE_TRUCK:
		case OBJTYPE_HELI:
		case OBJTYPE_29:
		case OBJTYPE_GLASS:
		case OBJTYPE_SAFE:
		case OBJTYPE_TANK:
		case OBJTYPE_TINTEDGLASS:
		case OBJTYPE_LIFT:
		case OBJTYPE_HOVERBIKE:
		case OBJTYPE_HOVERPROP:
		case OBJTYPE_FAN:
		case OBJTYPE_HOVERCAR:
		case OBJTYPE_CHOPPER:
		case OBJTYPE_ESCASTEP:
			return (struct defaultobj *)cmd;
		case OBJTYPE_DOORSCALE:
		case OBJTYPE_CHR:
		case OBJTYPE_LINKGUNS:
		case OBJTYPE_GRENADEPROB:
		case OBJTYPE_LINKLIFTDOOR:
		case OBJTYPE_TAG:
		case OBJTYPE_BEGINOBJECTIVE:
		case OBJTYPE_ENDOBJECTIVE:
		case OBJECTIVETYPE_DESTROYOBJ:
		case OBJECTIVETYPE_COMPFLAGS:
		case OBJECTIVETYPE_FAILFLAGS:
		case OBJECTIVETYPE_COLLECTOBJ:
		case OBJECTIVETYPE_THROWOBJ:
		case OBJECTIVETYPE_HOLOGRAPH:
		case OBJECTIVETYPE_1F:
		case OBJECTIVETYPE_ENTERROOM:
		case OBJECTIVETYPE_ATTACHOBJ:
		case OBJTYPE_22:
		case OBJTYPE_BRIEFING:
		case OBJTYPE_RENAMEOBJ:
		case OBJTYPE_PADLOCKEDDOOR:
		case OBJTYPE_SAFEITEM:
		case OBJTYPE_CAMERA2:
		case OBJTYPE_CONDITIONALSCENERY:
		case OBJTYPE_BLOCKEDPATH:
		case OBJTYPE_PADEFFECT:
			return NULL;
		}
	}

	return (struct defaultobj *)cmd;
}

GLOBAL_ASM(
glabel func0f092484
/*  f092484:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f092488:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09248c:	3c10800a */ 	lui	$s0,%hi(g_StageSetup+0x10)
/*  f092490:	8e10d040 */ 	lw	$s0,%lo(g_StageSetup+0x10)($s0)
/*  f092494:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f092498:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f09249c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0924a0:	0080b825 */ 	or	$s7,$a0,$zero
/*  f0924a4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0924a8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0924ac:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0924b0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0924b4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0924b8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0924bc:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0924c0:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0924c4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0924c8:	00009025 */ 	or	$s2,$zero,$zero
/*  f0924cc:	1200003f */ 	beqz	$s0,.L0f0925cc
/*  f0924d0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0924d4:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f0924d8:	24010034 */ 	addiu	$at,$zero,0x34
/*  f0924dc:	309e00ff */ 	andi	$s8,$a0,0xff
/*  f0924e0:	1061003a */ 	beq	$v1,$at,.L0f0925cc
/*  f0924e4:	3c160080 */ 	lui	$s6,0x80
/*  f0924e8:	24150008 */ 	addiu	$s5,$zero,0x8
/*  f0924ec:	8fb40054 */ 	lw	$s4,0x54($sp)
/*  f0924f0:	8fb10050 */ 	lw	$s1,0x50($sp)
.L0f0924f4:
/*  f0924f4:	17c3002d */ 	bne	$s8,$v1,.L0f0925ac
/*  f0924f8:	00000000 */ 	nop
/*  f0924fc:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f092500:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f092504:	14400007 */ 	bnez	$v0,.L0f092524
/*  f092508:	00000000 */ 	nop
/*  f09250c:	15c00027 */ 	bnez	$t6,.L0f0925ac
/*  f092510:	00000000 */ 	nop
/*  f092514:	16200025 */ 	bnez	$s1,.L0f0925ac
/*  f092518:	00000000 */ 	nop
/*  f09251c:	10000030 */ 	b	.L0f0925e0
/*  f092520:	02001025 */ 	or	$v0,$s0,$zero
.L0f092524:
/*  f092524:	12f50021 */ 	beq	$s7,$s5,.L0f0925ac
/*  f092528:	00000000 */ 	nop
/*  f09252c:	8e0f0040 */ 	lw	$t7,0x40($s0)
/*  f092530:	31f80080 */ 	andi	$t8,$t7,0x80
/*  f092534:	1700001d */ 	bnez	$t8,.L0f0925ac
/*  f092538:	00000000 */ 	nop
/*  f09253c:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f092540:	33280004 */ 	andi	$t0,$t9,0x4
/*  f092544:	15000019 */ 	bnez	$t0,.L0f0925ac
/*  f092548:	00000000 */ 	nop
/*  f09254c:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f092550:	01365024 */ 	and	$t2,$t1,$s6
/*  f092554:	15400015 */ 	bnez	$t2,.L0f0925ac
/*  f092558:	00000000 */ 	nop
/*  f09255c:	8c4b0018 */ 	lw	$t3,0x18($v0)
/*  f092560:	15600012 */ 	bnez	$t3,.L0f0925ac
/*  f092564:	00000000 */ 	nop
/*  f092568:	12200005 */ 	beqz	$s1,.L0f092580
/*  f09256c:	02802825 */ 	or	$a1,$s4,$zero
/*  f092570:	0fc2ca34 */ 	jal	func0f0b28d0
/*  f092574:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f092578:	1040000c */ 	beqz	$v0,.L0f0925ac
/*  f09257c:	00000000 */ 	nop
.L0f092580:
/*  f092580:	16400007 */ 	bnez	$s2,.L0f0925a0
/*  f092584:	00000000 */ 	nop
/*  f092588:	8e0c0014 */ 	lw	$t4,0x14($s0)
/*  f09258c:	918d0001 */ 	lbu	$t5,0x1($t4)
/*  f092590:	31ae00c2 */ 	andi	$t6,$t5,0xc2
/*  f092594:	15c00002 */ 	bnez	$t6,.L0f0925a0
/*  f092598:	00000000 */ 	nop
/*  f09259c:	02009025 */ 	or	$s2,$s0,$zero
.L0f0925a0:
/*  f0925a0:	16600002 */ 	bnez	$s3,.L0f0925ac
/*  f0925a4:	00000000 */ 	nop
/*  f0925a8:	02009825 */ 	or	$s3,$s0,$zero
.L0f0925ac:
/*  f0925ac:	0fc24784 */ 	jal	setupGetCommandLength
/*  f0925b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0925b4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f0925b8:	01f08021 */ 	addu	$s0,$t7,$s0
/*  f0925bc:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f0925c0:	24010034 */ 	addiu	$at,$zero,0x34
/*  f0925c4:	1461ffcb */ 	bne	$v1,$at,.L0f0924f4
/*  f0925c8:	00000000 */ 	nop
.L0f0925cc:
/*  f0925cc:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0925d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0925d4:	af120000 */ 	sw	$s2,0x0($t8)
/*  f0925d8:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0925dc:	af330000 */ 	sw	$s3,0x0($t9)
.L0f0925e0:
/*  f0925e0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0925e4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0925e8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0925ec:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0925f0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0925f4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0925f8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0925fc:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f092600:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f092604:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f092608:	03e00008 */ 	jr	$ra
/*  f09260c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
