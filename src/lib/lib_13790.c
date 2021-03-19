#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_13790.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_NTSC_1_0
// These are likely some of the same functions as ntsc-beta below,
// but it's not easy to tell which are which so leaving them separate for now.
void func00013790(void)
{
	// empty
}

void func00013798(void)
{
	// empty
}

void func000137a0(void)
{
	// empty
}

void func000137a8(void)
{
	// empty
}
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00013fe0nb
/*    13fe0:	afa40000 */ 	sw	$a0,0x0($sp)
/*    13fe4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    13fe8:	03e00008 */ 	jr	$ra
/*    13fec:	00001025 */ 	or	$v0,$zero,$zero
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00013ff0nb
/*    13ff0:	afa40000 */ 	sw	$a0,0x0($sp)
/*    13ff4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    13ff8:	03e00008 */ 	jr	$ra
/*    13ffc:	00001025 */ 	or	$v0,$zero,$zero
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00014000nb
/*    14000:	03e00008 */ 	jr	$ra
/*    14004:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00014008nb
/*    14008:	3c0e8006 */ 	lui	$t6,0x8006
/*    1400c:	25ce1238 */ 	addiu	$t6,$t6,0x1238
/*    14010:	8dc10000 */ 	lw	$at,0x0($t6)
/*    14014:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    14018:	27a50008 */ 	addiu	$a1,$sp,0x8
/*    1401c:	aca10000 */ 	sw	$at,0x0($a1)
/*    14020:	8dd90004 */ 	lw	$t9,0x4($t6)
/*    14024:	3c068006 */ 	lui	$a2,0x8006
/*    14028:	3c078006 */ 	lui	$a3,0x8006
/*    1402c:	3c088006 */ 	lui	$t0,0x8006
/*    14030:	3c0a800a */ 	lui	$t2,0x800a
/*    14034:	3c0b800a */ 	lui	$t3,0x800a
/*    14038:	3c0c800a */ 	lui	$t4,0x800a
/*    1403c:	25081210 */ 	addiu	$t0,$t0,0x1210
/*    14040:	24e7120c */ 	addiu	$a3,$a3,0x120c
/*    14044:	24c61208 */ 	addiu	$a2,$a2,0x1208
/*    14048:	254ac9e0 */ 	addiu	$t2,$t2,-13856
/*    1404c:	256bdfc0 */ 	addiu	$t3,$t3,-8256
/*    14050:	258ce0c0 */ 	addiu	$t4,$t4,-8000
/*    14054:	acca0000 */ 	sw	$t2,0x0($a2)
/*    14058:	aceb0000 */ 	sw	$t3,0x0($a3)
/*    1405c:	ad0c0000 */ 	sw	$t4,0x0($t0)
/*    14060:	3c018006 */ 	lui	$at,0x8006
/*    14064:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    14068:	acb90004 */ 	sw	$t9,0x4($a1)
/*    1406c:	ac2d117c */ 	sw	$t5,0x117c($at)
/*    14070:	00001025 */ 	or	$v0,$zero,$zero
/*    14074:	24090046 */ 	addiu	$t1,$zero,0x46
/*    14078:	00002025 */ 	or	$a0,$zero,$zero
.NB0001407c:
/*    1407c:	000278c0 */ 	sll	$t7,$v0,0x3
/*    14080:	01e27821 */ 	addu	$t7,$t7,$v0
/*    14084:	8cd80000 */ 	lw	$t8,0x0($a2)
/*    14088:	000f7880 */ 	sll	$t7,$t7,0x2
/*    1408c:	01e27823 */ 	subu	$t7,$t7,$v0
/*    14090:	000f7840 */ 	sll	$t7,$t7,0x1
/*    14094:	030f7021 */ 	addu	$t6,$t8,$t7
/*    14098:	01c4c821 */ 	addu	$t9,$t6,$a0
/*    1409c:	000258c0 */ 	sll	$t3,$v0,0x3
/*    140a0:	a3200000 */ 	sb	$zero,0x0($t9)
/*    140a4:	01625821 */ 	addu	$t3,$t3,$v0
/*    140a8:	8cca0000 */ 	lw	$t2,0x0($a2)
/*    140ac:	000b5880 */ 	sll	$t3,$t3,0x2
/*    140b0:	01625823 */ 	subu	$t3,$t3,$v0
/*    140b4:	000b5840 */ 	sll	$t3,$t3,0x1
/*    140b8:	014b6021 */ 	addu	$t4,$t2,$t3
/*    140bc:	01846821 */ 	addu	$t5,$t4,$a0
/*    140c0:	24840002 */ 	addiu	$a0,$a0,0x2
/*    140c4:	1489ffed */ 	bne	$a0,$t1,.NB0001407c
/*    140c8:	a1a00001 */ 	sb	$zero,0x1($t5)
/*    140cc:	24420001 */ 	addiu	$v0,$v0,0x1
/*    140d0:	28410050 */ 	slti	$at,$v0,0x50
/*    140d4:	5420ffe9 */ 	bnezl	$at,.NB0001407c
/*    140d8:	00002025 */ 	or	$a0,$zero,$zero
/*    140dc:	00001825 */ 	or	$v1,$zero,$zero
/*    140e0:	24020100 */ 	addiu	$v0,$zero,0x100
.NB000140e4:
/*    140e4:	8cf80000 */ 	lw	$t8,0x0($a3)
/*    140e8:	8ca10000 */ 	lw	$at,0x0($a1)
/*    140ec:	03037821 */ 	addu	$t7,$t8,$v1
/*    140f0:	ade10000 */ 	sw	$at,0x0($t7)
/*    140f4:	8cb90004 */ 	lw	$t9,0x4($a1)
/*    140f8:	adf90004 */ 	sw	$t9,0x4($t7)
/*    140fc:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*    14100:	8ca10000 */ 	lw	$at,0x0($a1)
/*    14104:	01435821 */ 	addu	$t3,$t2,$v1
/*    14108:	ad610000 */ 	sw	$at,0x0($t3)
/*    1410c:	8cad0004 */ 	lw	$t5,0x4($a1)
/*    14110:	24630008 */ 	addiu	$v1,$v1,0x8
/*    14114:	1462fff3 */ 	bne	$v1,$v0,.NB000140e4
/*    14118:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*    1411c:	03e00008 */ 	jr	$ra
/*    14120:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00014124nb
/*    14124:	3c0e8006 */ 	lui	$t6,0x8006
/*    14128:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    1412c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    14130:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    14134:	51c00004 */ 	beqzl	$t6,.NB00014148
/*    14138:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1413c:	0c0050b5 */ 	jal	0x142d4
/*    14140:	00000000 */ 	sll	$zero,$zero,0x0
/*    14144:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB00014148:
/*    14148:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1414c:	03e00008 */ 	jr	$ra
/*    14150:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00014154nb
/*    14154:	3c078006 */ 	lui	$a3,0x8006
/*    14158:	8ce7120c */ 	lw	$a3,0x120c($a3)
/*    1415c:	afa60008 */ 	sw	$a2,0x8($sp)
/*    14160:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    14164:	3c038006 */ 	lui	$v1,0x8006
/*    14168:	3c0b8006 */ 	lui	$t3,0x8006
/*    1416c:	3c0a8006 */ 	lui	$t2,0x8006
/*    14170:	01c03025 */ 	or	$a2,$t6,$zero
/*    14174:	254a1230 */ 	addiu	$t2,$t2,0x1230
/*    14178:	256b1210 */ 	addiu	$t3,$t3,0x1210
/*    1417c:	8c63122c */ 	lw	$v1,0x122c($v1)
/*    14180:	00001025 */ 	or	$v0,$zero,$zero
/*    14184:	00004025 */ 	or	$t0,$zero,$zero
/*    14188:	00e04825 */ 	or	$t1,$a3,$zero
.NB0001418c:
/*    1418c:	8d2f0004 */ 	lw	$t7,0x4($t1)
/*    14190:	25290008 */ 	addiu	$t1,$t1,0x8
/*    14194:	546f0008 */ 	bnel	$v1,$t7,.NB000141b8
/*    14198:	24420001 */ 	addiu	$v0,$v0,0x1
/*    1419c:	8d790000 */ 	lw	$t9,0x0($t3)
/*    141a0:	8d580004 */ 	lw	$t8,0x4($t2)
/*    141a4:	03286021 */ 	addu	$t4,$t9,$t0
/*    141a8:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    141ac:	130d0021 */ 	beq	$t8,$t5,.NB00014234
/*    141b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    141b4:	24420001 */ 	addiu	$v0,$v0,0x1
.NB000141b8:
/*    141b8:	28410020 */ 	slti	$at,$v0,0x20
/*    141bc:	1420fff3 */ 	bnez	$at,.NB0001418c
/*    141c0:	25080008 */ 	addiu	$t0,$t0,0x8
/*    141c4:	3c038006 */ 	lui	$v1,0x8006
/*    141c8:	24631214 */ 	addiu	$v1,$v1,0x1214
/*    141cc:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*    141d0:	3c0c8006 */ 	lui	$t4,0x8006
/*    141d4:	258c1228 */ 	addiu	$t4,$t4,0x1228
/*    141d8:	8d810000 */ 	lw	$at,0x0($t4)
/*    141dc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*    141e0:	00efc821 */ 	addu	$t9,$a3,$t7
/*    141e4:	af210000 */ 	sw	$at,0x0($t9)
/*    141e8:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    141ec:	af2d0004 */ 	sw	$t5,0x4($t9)
/*    141f0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    141f4:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*    141f8:	8d410000 */ 	lw	$at,0x0($t2)
/*    141fc:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*    14200:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    14204:	af210000 */ 	sw	$at,0x0($t9)
/*    14208:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*    1420c:	af2d0004 */ 	sw	$t5,0x4($t9)
/*    14210:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    14214:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*    14218:	05c10004 */ 	bgez	$t6,.NB0001422c
/*    1421c:	31d8001f */ 	andi	$t8,$t6,0x1f
/*    14220:	13000002 */ 	beqz	$t8,.NB0001422c
/*    14224:	00000000 */ 	sll	$zero,$zero,0x0
/*    14228:	2718ffe0 */ 	addiu	$t8,$t8,-32
.NB0001422c:
/*    1422c:	ac780000 */ 	sw	$t8,0x0($v1)
/*    14230:	03001025 */ 	or	$v0,$t8,$zero
.NB00014234:
/*    14234:	3c078006 */ 	lui	$a3,0x8006
/*    14238:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*    1423c:	24e71208 */ 	addiu	$a3,$a3,0x1208
/*    14240:	0324c821 */ 	addu	$t9,$t9,$a0
/*    14244:	8cec0000 */ 	lw	$t4,0x0($a3)
/*    14248:	0019c880 */ 	sll	$t9,$t9,0x2
/*    1424c:	0324c823 */ 	subu	$t9,$t9,$a0
/*    14250:	0019c840 */ 	sll	$t9,$t9,0x1
/*    14254:	00051840 */ 	sll	$v1,$a1,0x1
/*    14258:	01996821 */ 	addu	$t5,$t4,$t9
/*    1425c:	01a37821 */ 	addu	$t7,$t5,$v1
/*    14260:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*    14264:	a1e60000 */ 	sb	$a2,0x0($t7)
/*    14268:	0304c021 */ 	addu	$t8,$t8,$a0
/*    1426c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*    14270:	0018c080 */ 	sll	$t8,$t8,0x2
/*    14274:	0304c023 */ 	subu	$t8,$t8,$a0
/*    14278:	0018c040 */ 	sll	$t8,$t8,0x1
/*    1427c:	01d86021 */ 	addu	$t4,$t6,$t8
/*    14280:	0183c821 */ 	addu	$t9,$t4,$v1
/*    14284:	10c00003 */ 	beqz	$a2,.NB00014294
/*    14288:	a3220001 */ 	sb	$v0,0x1($t9)
/*    1428c:	3c018006 */ 	lui	$at,0x8006
/*    14290:	ac201178 */ 	sw	$zero,0x1178($at)
.NB00014294:
/*    14294:	03e00008 */ 	jr	$ra
/*    14298:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func0001429cnb
/*    1429c:	3c0e8006 */ 	lui	$t6,0x8006
/*    142a0:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    142a4:	3c0f8006 */ 	lui	$t7,0x8006
/*    142a8:	3c018006 */ 	lui	$at,0x8006
/*    142ac:	11c00007 */ 	beqz	$t6,.NB000142cc
/*    142b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    142b4:	8def1168 */ 	lw	$t7,0x1168($t7)
/*    142b8:	3c188006 */ 	lui	$t8,0x8006
/*    142bc:	8f18116c */ 	lw	$t8,0x116c($t8)
/*    142c0:	ac2f1170 */ 	sw	$t7,0x1170($at)
/*    142c4:	3c018006 */ 	lui	$at,0x8006
/*    142c8:	ac381174 */ 	sw	$t8,0x1174($at)
.NB000142cc:
/*    142cc:	03e00008 */ 	jr	$ra
/*    142d0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func000142d4nb
/*    142d4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    142d8:	3c0e8006 */ 	lui	$t6,0x8006
/*    142dc:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    142e0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    142e4:	afb30020 */ 	sw	$s3,0x20($sp)
/*    142e8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    142ec:	afb10018 */ 	sw	$s1,0x18($sp)
/*    142f0:	11c0001b */ 	beqz	$t6,.NB00014360
/*    142f4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    142f8:	3c0f8006 */ 	lui	$t7,0x8006
/*    142fc:	8def1178 */ 	lw	$t7,0x1178($t7)
/*    14300:	24010001 */ 	addiu	$at,$zero,0x1
/*    14304:	00009025 */ 	or	$s2,$zero,$zero
/*    14308:	11e10015 */ 	beq	$t7,$at,.NB00014360
/*    1430c:	24130023 */ 	addiu	$s3,$zero,0x23
/*    14310:	24110050 */ 	addiu	$s1,$zero,0x50
/*    14314:	00008025 */ 	or	$s0,$zero,$zero
.NB00014318:
/*    14318:	02002025 */ 	or	$a0,$s0,$zero
.NB0001431c:
/*    1431c:	02402825 */ 	or	$a1,$s2,$zero
/*    14320:	0c005055 */ 	jal	0x14154
/*    14324:	00003025 */ 	or	$a2,$zero,$zero
/*    14328:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1432c:	5611fffb */ 	bnel	$s0,$s1,.NB0001431c
/*    14330:	02002025 */ 	or	$a0,$s0,$zero
/*    14334:	26520001 */ 	addiu	$s2,$s2,0x1
/*    14338:	5653fff7 */ 	bnel	$s2,$s3,.NB00014318
/*    1433c:	00008025 */ 	or	$s0,$zero,$zero
/*    14340:	24180001 */ 	addiu	$t8,$zero,0x1
/*    14344:	3c018006 */ 	lui	$at,0x8006
/*    14348:	0c0050a7 */ 	jal	0x1429c
/*    1434c:	ac381178 */ 	sw	$t8,0x1178($at)
/*    14350:	0c005000 */ 	jal	0x14000
/*    14354:	00000000 */ 	sll	$zero,$zero,0x0
/*    14358:	3c018006 */ 	lui	$at,0x8006
/*    1435c:	ac201214 */ 	sw	$zero,0x1214($at)
.NB00014360:
/*    14360:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    14364:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    14368:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    1436c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    14370:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    14374:	03e00008 */ 	jr	$ra
/*    14378:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func000137b0(s32 arg0, s32 arg1)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func000137b0
/*    1437c:	3c0e8006 */ 	lui	$t6,0x8006
/*    14380:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    14384:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    14388:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1438c:	11c0001e */ 	beqz	$t6,.NB00014408
/*    14390:	3c0f8006 */ 	lui	$t7,0x8006
/*    14394:	3c188006 */ 	lui	$t8,0x8006
/*    14398:	8def1168 */ 	lw	$t7,0x1168($t7)
/*    1439c:	8f18116c */ 	lw	$t8,0x116c($t8)
/*    143a0:	008f2021 */ 	addu	$a0,$a0,$t7
/*    143a4:	00b82821 */ 	addu	$a1,$a1,$t8
/*    143a8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    143ac:	0c002f7b */ 	jal	0xbdec
/*    143b0:	afa40018 */ 	sw	$a0,0x18($sp)
/*    143b4:	2459fff6 */ 	addiu	$t9,$v0,-10
/*    143b8:	24010007 */ 	addiu	$at,$zero,0x7
/*    143bc:	0321001a */ 	div	$zero,$t9,$at
/*    143c0:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    143c4:	00004012 */ 	mflo	$t0
/*    143c8:	00a8082a */ 	slt	$at,$a1,$t0
/*    143cc:	5420000a */ 	bnezl	$at,.NB000143f8
/*    143d0:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    143d4:	0c002f7b */ 	jal	0xbdec
/*    143d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    143dc:	2445fff6 */ 	addiu	$a1,$v0,-10
/*    143e0:	24010007 */ 	addiu	$at,$zero,0x7
/*    143e4:	00a1001a */ 	div	$zero,$a1,$at
/*    143e8:	00004812 */ 	mflo	$t1
/*    143ec:	2525ffff */ 	addiu	$a1,$t1,-1
/*    143f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    143f4:	8faa0018 */ 	lw	$t2,0x18($sp)
.NB000143f8:
/*    143f8:	3c018006 */ 	lui	$at,0x8006
/*    143fc:	ac2a1170 */ 	sw	$t2,0x1170($at)
/*    14400:	3c018006 */ 	lui	$at,0x8006
/*    14404:	ac251174 */ 	sw	$a1,0x1174($at)
.NB00014408:
/*    14408:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1440c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    14410:	03e00008 */ 	jr	$ra
/*    14414:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func000137bc(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func000137bc
/*    14418:	3c0e8006 */ 	lui	$t6,0x8006
/*    1441c:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    14420:	00047e00 */ 	sll	$t7,$a0,0x18
/*    14424:	0005c400 */ 	sll	$t8,$a1,0x10
/*    14428:	11c00008 */ 	beqz	$t6,.NB0001444c
/*    1442c:	01f8c825 */ 	or	$t9,$t7,$t8
/*    14430:	00064200 */ 	sll	$t0,$a2,0x8
/*    14434:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    14438:	01475823 */ 	subu	$t3,$t2,$a3
/*    1443c:	03284825 */ 	or	$t1,$t9,$t0
/*    14440:	012b6025 */ 	or	$t4,$t1,$t3
/*    14444:	3c018006 */ 	lui	$at,0x8006
/*    14448:	ac2c122c */ 	sw	$t4,0x122c($at)
.NB0001444c:
/*    1444c:	03e00008 */ 	jr	$ra
/*    14450:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func000137d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func000137d0
/*    14454:	3c0e8006 */ 	lui	$t6,0x8006
/*    14458:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    1445c:	00047e00 */ 	sll	$t7,$a0,0x18
/*    14460:	0005c400 */ 	sll	$t8,$a1,0x10
/*    14464:	11c00008 */ 	beqz	$t6,.NB00014488
/*    14468:	01f8c825 */ 	or	$t9,$t7,$t8
/*    1446c:	00064200 */ 	sll	$t0,$a2,0x8
/*    14470:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    14474:	01475823 */ 	subu	$t3,$t2,$a3
/*    14478:	03284825 */ 	or	$t1,$t9,$t0
/*    1447c:	012b6025 */ 	or	$t4,$t1,$t3
/*    14480:	3c018006 */ 	lui	$at,0x8006
/*    14484:	ac2c1234 */ 	sw	$t4,0x1234($at)
.NB00014488:
/*    14488:	03e00008 */ 	jr	$ra
/*    1448c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func000137e4(s32 arg0)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func000137e4
/*    14490:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    14494:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    14498:	0c002f77 */ 	jal	0xbddc
/*    1449c:	afa40028 */ 	sw	$a0,0x28($sp)
/*    144a0:	244efff3 */ 	addiu	$t6,$v0,-13
/*    144a4:	05c10003 */ 	bgez	$t6,.NB000144b4
/*    144a8:	000e7883 */ 	sra	$t7,$t6,0x2
/*    144ac:	25c10003 */ 	addiu	$at,$t6,0x3
/*    144b0:	00017883 */ 	sra	$t7,$at,0x2
.NB000144b4:
/*    144b4:	0c002f7b */ 	jal	0xbdec
/*    144b8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    144bc:	2448fff6 */ 	addiu	$t0,$v0,-10
/*    144c0:	24010007 */ 	addiu	$at,$zero,0x7
/*    144c4:	0101001a */ 	div	$zero,$t0,$at
/*    144c8:	3c198006 */ 	lui	$t9,0x8006
/*    144cc:	8f39117c */ 	lw	$t9,0x117c($t9)
/*    144d0:	00004012 */ 	mflo	$t0
/*    144d4:	93a6002b */ 	lbu	$a2,0x2b($sp)
/*    144d8:	5320002d */ 	beqzl	$t9,.NB00014590
/*    144dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    144e0:	10c00005 */ 	beqz	$a2,.NB000144f8
/*    144e4:	00c01025 */ 	or	$v0,$a2,$zero
/*    144e8:	28410020 */ 	slti	$at,$v0,0x20
/*    144ec:	1420000d */ 	bnez	$at,.NB00014524
/*    144f0:	2841007f */ 	slti	$at,$v0,0x7f
/*    144f4:	1020000b */ 	beqz	$at,.NB00014524
.NB000144f8:
/*    144f8:	3c038006 */ 	lui	$v1,0x8006
/*    144fc:	3c078006 */ 	lui	$a3,0x8006
/*    14500:	24e71174 */ 	addiu	$a3,$a3,0x1174
/*    14504:	24631170 */ 	addiu	$v1,$v1,0x1170
/*    14508:	8c640000 */ 	lw	$a0,0x0($v1)
/*    1450c:	8ce50000 */ 	lw	$a1,0x0($a3)
/*    14510:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    14514:	0c005055 */ 	jal	0x14154
/*    14518:	afa80020 */ 	sw	$t0,0x20($sp)
/*    1451c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    14520:	8fa80020 */ 	lw	$t0,0x20($sp)
.NB00014524:
/*    14524:	3c038006 */ 	lui	$v1,0x8006
/*    14528:	24631170 */ 	addiu	$v1,$v1,0x1170
/*    1452c:	8c690000 */ 	lw	$t1,0x0($v1)
/*    14530:	3c078006 */ 	lui	$a3,0x8006
/*    14534:	2401000d */ 	addiu	$at,$zero,0xd
/*    14538:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    1453c:	24e71174 */ 	addiu	$a3,$a3,0x1174
/*    14540:	10410007 */ 	beq	$v0,$at,.NB00014560
/*    14544:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*    14548:	2401000a */ 	addiu	$at,$zero,0xa
/*    1454c:	10410004 */ 	beq	$v0,$at,.NB00014560
/*    14550:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    14554:	014c082a */ 	slt	$at,$t2,$t4
/*    14558:	5420000d */ 	bnezl	$at,.NB00014590
/*    1455c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB00014560:
/*    14560:	8cee0000 */ 	lw	$t6,0x0($a3)
/*    14564:	3c0d8006 */ 	lui	$t5,0x8006
/*    14568:	8dad1168 */ 	lw	$t5,0x1168($t5)
/*    1456c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    14570:	01e8082a */ 	slt	$at,$t7,$t0
/*    14574:	acef0000 */ 	sw	$t7,0x0($a3)
/*    14578:	14200004 */ 	bnez	$at,.NB0001458c
/*    1457c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*    14580:	3c198006 */ 	lui	$t9,0x8006
/*    14584:	8f39116c */ 	lw	$t9,0x116c($t9)
/*    14588:	acf90000 */ 	sw	$t9,0x0($a3)
.NB0001458c:
/*    1458c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB00014590:
/*    14590:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    14594:	03e00008 */ 	jr	$ra
/*    14598:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func000137ec(s32 arg0, s32 arg1, s32 arg2)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func000137ec
/*    1459c:	3c0e8006 */ 	lui	$t6,0x8006
/*    145a0:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    145a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    145a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    145ac:	11c00005 */ 	beqz	$t6,.NB000145c4
/*    145b0:	afa60020 */ 	sw	$a2,0x20($sp)
/*    145b4:	0c0050df */ 	jal	0x1437c
/*    145b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    145bc:	0c005124 */ 	jal	0x14490
/*    145c0:	93a40023 */ 	lbu	$a0,0x23($sp)
.NB000145c4:
/*    145c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    145c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    145cc:	03e00008 */ 	jr	$ra
/*    145d0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func000137fc(s32 arg0)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func000137fc
/*    145d4:	3c0e8006 */ 	lui	$t6,0x8006
/*    145d8:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    145dc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    145e0:	afb10018 */ 	sw	$s1,0x18($sp)
/*    145e4:	00808825 */ 	or	$s1,$a0,$zero
/*    145e8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    145ec:	11c00009 */ 	beqz	$t6,.NB00014614
/*    145f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    145f4:	90900000 */ 	lbu	$s0,0x0($a0)
/*    145f8:	12000006 */ 	beqz	$s0,.NB00014614
/*    145fc:	320400ff */ 	andi	$a0,$s0,0xff
.NB00014600:
/*    14600:	0c005124 */ 	jal	0x14490
/*    14604:	26310001 */ 	addiu	$s1,$s1,0x1
/*    14608:	92300000 */ 	lbu	$s0,0x0($s1)
/*    1460c:	5600fffc */ 	bnezl	$s0,.NB00014600
/*    14610:	320400ff */ 	andi	$a0,$s0,0xff
.NB00014614:
/*    14614:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    14618:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    1461c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    14620:	03e00008 */ 	jr	$ra
/*    14624:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void func00013804(s32 arg0, s32 arg1, s32 arg2)
{
	// empty
}
#else
GLOBAL_ASM(
glabel func00013804
/*    14628:	3c0e8006 */ 	lui	$t6,0x8006
/*    1462c:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    14630:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    14634:	afb10018 */ 	sw	$s1,0x18($sp)
/*    14638:	00c08825 */ 	or	$s1,$a2,$zero
/*    1463c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    14640:	11c0000b */ 	beqz	$t6,.NB00014670
/*    14644:	afb00014 */ 	sw	$s0,0x14($sp)
/*    14648:	0c0050df */ 	jal	0x1437c
/*    1464c:	00000000 */ 	sll	$zero,$zero,0x0
/*    14650:	92300000 */ 	lbu	$s0,0x0($s1)
/*    14654:	12000006 */ 	beqz	$s0,.NB00014670
/*    14658:	320400ff */ 	andi	$a0,$s0,0xff
.NB0001465c:
/*    1465c:	0c005124 */ 	jal	0x14490
/*    14660:	26310001 */ 	addiu	$s1,$s1,0x1
/*    14664:	92300000 */ 	lbu	$s0,0x0($s1)
/*    14668:	5600fffc */ 	bnezl	$s0,.NB0001465c
/*    1466c:	320400ff */ 	andi	$a0,$s0,0xff
.NB00014670:
/*    14670:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    14674:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    14678:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    1467c:	03e00008 */ 	jr	$ra
/*    14680:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

#if VERSION >= VERSION_NTSC_1_0
Gfx *func00013814(Gfx *gdl)
{
	return gdl;
}
#else
GLOBAL_ASM(
glabel func00013814
/*    14684:	27bdff78 */ 	addiu	$sp,$sp,-136
/*    14688:	3c0e8006 */ 	lui	$t6,0x8006
/*    1468c:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    14690:	afb00018 */ 	sw	$s0,0x18($sp)
/*    14694:	00808025 */ 	or	$s0,$a0,$zero
/*    14698:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    1469c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    146a0:	afb70034 */ 	sw	$s7,0x34($sp)
/*    146a4:	afb60030 */ 	sw	$s6,0x30($sp)
/*    146a8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    146ac:	afb40028 */ 	sw	$s4,0x28($sp)
/*    146b0:	afb30024 */ 	sw	$s3,0x24($sp)
/*    146b4:	afb20020 */ 	sw	$s2,0x20($sp)
/*    146b8:	15c00003 */ 	bnez	$t6,.NB000146c8
/*    146bc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    146c0:	100000a5 */ 	beqz	$zero,.NB00014958
/*    146c4:	00801025 */ 	or	$v0,$a0,$zero
.NB000146c8:
/*    146c8:	3c0f8006 */ 	lui	$t7,0x8006
/*    146cc:	8def1178 */ 	lw	$t7,0x1178($t7)
/*    146d0:	02008825 */ 	or	$s1,$s0,$zero
/*    146d4:	2406ffff */ 	addiu	$a2,$zero,-1
/*    146d8:	15e0009e */ 	bnez	$t7,.NB00014954
/*    146dc:	0000a025 */ 	or	$s4,$zero,$zero
/*    146e0:	3c078006 */ 	lui	$a3,0x8006
/*    146e4:	8ce71208 */ 	lw	$a3,0x1208($a3)
/*    146e8:	00004025 */ 	or	$t0,$zero,$zero
/*    146ec:	24090050 */ 	addiu	$t1,$zero,0x50
/*    146f0:	00002825 */ 	or	$a1,$zero,$zero
.NB000146f4:
/*    146f4:	00e82021 */ 	addu	$a0,$a3,$t0
.NB000146f8:
/*    146f8:	90820000 */ 	lbu	$v0,0x0($a0)
/*    146fc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    14700:	90830001 */ 	lbu	$v1,0x1($a0)
/*    14704:	10400006 */ 	beqz	$v0,.NB00014720
/*    14708:	00000000 */ 	sll	$zero,$zero,0x0
/*    1470c:	50660004 */ 	beql	$v1,$a2,.NB00014720
/*    14710:	26310018 */ 	addiu	$s1,$s1,0x18
/*    14714:	26310010 */ 	addiu	$s1,$s1,0x10
/*    14718:	00603025 */ 	or	$a2,$v1,$zero
/*    1471c:	26310018 */ 	addiu	$s1,$s1,0x18
.NB00014720:
/*    14720:	14a9fff5 */ 	bne	$a1,$t1,.NB000146f8
/*    14724:	24840046 */ 	addiu	$a0,$a0,0x46
/*    14728:	25080002 */ 	addiu	$t0,$t0,0x2
/*    1472c:	29010046 */ 	slti	$at,$t0,0x46
/*    14730:	5420fff0 */ 	bnezl	$at,.NB000146f4
/*    14734:	00002825 */ 	or	$a1,$zero,$zero
/*    14738:	0fc588f2 */ 	jal	0xf1623c8
/*    1473c:	02002025 */ 	or	$a0,$s0,$zero
/*    14740:	02302023 */ 	subu	$a0,$s1,$s0
/*    14744:	1c800003 */ 	bgtz	$a0,.NB00014754
/*    14748:	24090050 */ 	addiu	$t1,$zero,0x50
/*    1474c:	10000082 */ 	beqz	$zero,.NB00014958
/*    14750:	02001025 */ 	or	$v0,$s0,$zero
.NB00014754:
/*    14754:	2443f800 */ 	addiu	$v1,$v0,-2048
/*    14758:	1c600004 */ 	bgtz	$v1,.NB0001476c
/*    1475c:	2413ffff */ 	addiu	$s3,$zero,-1
/*    14760:	3c018006 */ 	lui	$at,0x8006
/*    14764:	10000017 */ 	beqz	$zero,.NB000147c4
/*    14768:	ac201240 */ 	sw	$zero,0x1240($at)
.NB0001476c:
/*    1476c:	0064082a */ 	slt	$at,$v1,$a0
/*    14770:	10200011 */ 	beqz	$at,.NB000147b8
/*    14774:	0003c200 */ 	sll	$t8,$v1,0x8
/*    14778:	0303c023 */ 	subu	$t8,$t8,$v1
/*    1477c:	0304001a */ 	div	$zero,$t8,$a0
/*    14780:	14800002 */ 	bnez	$a0,.NB0001478c
/*    14784:	00000000 */ 	sll	$zero,$zero,0x0
/*    14788:	0007000d */ 	break	0x7
.NB0001478c:
/*    1478c:	2401ffff */ 	addiu	$at,$zero,-1
/*    14790:	14810004 */ 	bne	$a0,$at,.NB000147a4
/*    14794:	3c018000 */ 	lui	$at,0x8000
/*    14798:	17010002 */ 	bne	$t8,$at,.NB000147a4
/*    1479c:	00000000 */ 	sll	$zero,$zero,0x0
/*    147a0:	0006000d */ 	break	0x6
.NB000147a4:
/*    147a4:	3c018006 */ 	lui	$at,0x8006
/*    147a8:	0000c812 */ 	mflo	$t9
/*    147ac:	ac391240 */ 	sw	$t9,0x1240($at)
/*    147b0:	10000005 */ 	beqz	$zero,.NB000147c8
/*    147b4:	02001025 */ 	or	$v0,$s0,$zero
.NB000147b8:
/*    147b8:	240a0100 */ 	addiu	$t2,$zero,0x100
/*    147bc:	3c018006 */ 	lui	$at,0x8006
/*    147c0:	ac2a1240 */ 	sw	$t2,0x1240($at)
.NB000147c4:
/*    147c4:	02001025 */ 	or	$v0,$s0,$zero
.NB000147c8:
/*    147c8:	3c0c8006 */ 	lui	$t4,0x8006
/*    147cc:	258c1180 */ 	addiu	$t4,$t4,0x1180
/*    147d0:	3c0b0600 */ 	lui	$t3,0x600
/*    147d4:	3c178006 */ 	lui	$s7,0x8006
/*    147d8:	3c168006 */ 	lui	$s6,0x8006
/*    147dc:	3c158006 */ 	lui	$s5,0x8006
/*    147e0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    147e4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    147e8:	26100008 */ 	addiu	$s0,$s0,0x8
/*    147ec:	26b51208 */ 	addiu	$s5,$s5,0x1208
/*    147f0:	26d6120c */ 	addiu	$s6,$s6,0x120c
/*    147f4:	26f71210 */ 	addiu	$s7,$s7,0x1210
/*    147f8:	0000a025 */ 	or	$s4,$zero,$zero
/*    147fc:	00004025 */ 	or	$t0,$zero,$zero
/*    14800:	3c1ee400 */ 	lui	$s8,0xe400
.NB00014804:
/*    14804:	00008825 */ 	or	$s1,$zero,$zero
/*    14808:	001170c0 */ 	sll	$t6,$s1,0x3
.NB0001480c:
/*    1480c:	01d17021 */ 	addu	$t6,$t6,$s1
/*    14810:	8ead0000 */ 	lw	$t5,0x0($s5)
/*    14814:	000e7080 */ 	sll	$t6,$t6,0x2
/*    14818:	01d17023 */ 	subu	$t6,$t6,$s1
/*    1481c:	000e7040 */ 	sll	$t6,$t6,0x1
/*    14820:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    14824:	01e81021 */ 	addu	$v0,$t7,$t0
/*    14828:	90520000 */ 	lbu	$s2,0x0($v0)
/*    1482c:	90430001 */ 	lbu	$v1,0x1($v0)
/*    14830:	52400042 */ 	beqzl	$s2,.NB0001493c
/*    14834:	26310001 */ 	addiu	$s1,$s1,0x1
/*    14838:	50730011 */ 	beql	$v1,$s3,.NB00014880
/*    1483c:	02002025 */ 	or	$a0,$s0,$zero
/*    14840:	8ed80000 */ 	lw	$t8,0x0($s6)
/*    14844:	000310c0 */ 	sll	$v0,$v1,0x3
/*    14848:	26100010 */ 	addiu	$s0,$s0,0x10
/*    1484c:	0302c821 */ 	addu	$t9,$t8,$v0
/*    14850:	8f210000 */ 	lw	$at,0x0($t9)
/*    14854:	00609825 */ 	or	$s3,$v1,$zero
/*    14858:	ae01fff0 */ 	sw	$at,-0x10($s0)
/*    1485c:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*    14860:	ae0bfff4 */ 	sw	$t3,-0xc($s0)
/*    14864:	8eec0000 */ 	lw	$t4,0x0($s7)
/*    14868:	01826821 */ 	addu	$t5,$t4,$v0
/*    1486c:	8da10000 */ 	lw	$at,0x0($t5)
/*    14870:	ae01fff8 */ 	sw	$at,-0x8($s0)
/*    14874:	8daf0004 */ 	lw	$t7,0x4($t5)
/*    14878:	ae0ffffc */ 	sw	$t7,-0x4($s0)
/*    1487c:	02002025 */ 	or	$a0,$s0,$zero
.NB00014880:
/*    14880:	0fc588f2 */ 	jal	0xf1623c8
/*    14884:	afa80040 */ 	sw	$t0,0x40($sp)
/*    14888:	28410400 */ 	slti	$at,$v0,0x400
/*    1488c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    14890:	14200029 */ 	bnez	$at,.NB00014938
/*    14894:	24090050 */ 	addiu	$t1,$zero,0x50
/*    14898:	00111900 */ 	sll	$v1,$s1,0x4
/*    1489c:	24780010 */ 	addiu	$t8,$v1,0x10
/*    148a0:	330a0fff */ 	andi	$t2,$t8,0xfff
/*    148a4:	001420c0 */ 	sll	$a0,$s4,0x3
/*    148a8:	00942023 */ 	subu	$a0,$a0,$s4
/*    148ac:	000acb00 */ 	sll	$t9,$t2,0xc
/*    148b0:	00042080 */ 	sll	$a0,$a0,0x2
/*    148b4:	306f0fff */ 	andi	$t7,$v1,0xfff
/*    148b8:	000fc300 */ 	sll	$t8,$t7,0xc
/*    148bc:	308a0fff */ 	andi	$t2,$a0,0xfff
/*    148c0:	033e5825 */ 	or	$t3,$t9,$s8
/*    148c4:	030ac825 */ 	or	$t9,$t8,$t2
/*    148c8:	248c001c */ 	addiu	$t4,$a0,0x1c
/*    148cc:	02001025 */ 	or	$v0,$s0,$zero
/*    148d0:	2646ffe0 */ 	addiu	$a2,$s2,-32
/*    148d4:	0006c143 */ 	sra	$t8,$a2,0x5
/*    148d8:	318e0fff */ 	andi	$t6,$t4,0xfff
/*    148dc:	016e6825 */ 	or	$t5,$t3,$t6
/*    148e0:	001850c0 */ 	sll	$t2,$t8,0x3
/*    148e4:	26100008 */ 	addiu	$s0,$s0,0x8
/*    148e8:	02002825 */ 	or	$a1,$s0,$zero
/*    148ec:	01585023 */ 	subu	$t2,$t2,$t8
/*    148f0:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    148f4:	ac590004 */ 	sw	$t9,0x4($v0)
/*    148f8:	30cd001f */ 	andi	$t5,$a2,0x1f
/*    148fc:	000a5140 */ 	sll	$t2,$t2,0x5
/*    14900:	3c0cb400 */ 	lui	$t4,0xb400
/*    14904:	acac0000 */ 	sw	$t4,0x0($a1)
/*    14908:	3159ffff */ 	andi	$t9,$t2,0xffff
/*    1490c:	000d7dc0 */ 	sll	$t7,$t5,0x17
/*    14910:	26100008 */ 	addiu	$s0,$s0,0x8
/*    14914:	02003825 */ 	or	$a3,$s0,$zero
/*    14918:	01f96025 */ 	or	$t4,$t7,$t9
/*    1491c:	acac0004 */ 	sw	$t4,0x4($a1)
/*    14920:	3c0e0400 */ 	lui	$t6,0x400
/*    14924:	35ce0400 */ 	ori	$t6,$t6,0x400
/*    14928:	3c0bb300 */ 	lui	$t3,0xb300
/*    1492c:	aceb0000 */ 	sw	$t3,0x0($a3)
/*    14930:	acee0004 */ 	sw	$t6,0x4($a3)
/*    14934:	26100008 */ 	addiu	$s0,$s0,0x8
.NB00014938:
/*    14938:	26310001 */ 	addiu	$s1,$s1,0x1
.NB0001493c:
/*    1493c:	5629ffb3 */ 	bnel	$s1,$t1,.NB0001480c
/*    14940:	001170c0 */ 	sll	$t6,$s1,0x3
/*    14944:	26940001 */ 	addiu	$s4,$s4,0x1
/*    14948:	24010023 */ 	addiu	$at,$zero,0x23
/*    1494c:	1681ffad */ 	bne	$s4,$at,.NB00014804
/*    14950:	25080002 */ 	addiu	$t0,$t0,0x2
.NB00014954:
/*    14954:	02001025 */ 	or	$v0,$s0,$zero
.NB00014958:
/*    14958:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    1495c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    14960:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    14964:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    14968:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    1496c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    14970:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    14974:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    14978:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    1497c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    14980:	03e00008 */ 	jr	$ra
/*    14984:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#endif
