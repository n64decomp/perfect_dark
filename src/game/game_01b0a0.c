#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0fd660.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "library/library_13130.h"
#include "library/library_13900.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f01b0a0
/*  f01b0a0:	44800000 */ 	mtc1	$zero,$f0
/*  f01b0a4:	03e00008 */ 	jr	$ra
/*  f01b0a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b0ac
/*  f01b0ac:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f01b0b0:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f01b0b4:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01b0b8:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f01b0bc:	51e00004 */ 	beqzl	$t7,.L0f01b0d0
/*  f01b0c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f01b0c4:	03e00008 */ 	jr	$ra
/*  f01b0c8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f01b0cc:	3c013f80 */ 	lui	$at,0x3f80
.L0f01b0d0:
/*  f01b0d0:	44810000 */ 	mtc1	$at,$f0
/*  f01b0d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b0d8:	03e00008 */ 	jr	$ra
/*  f01b0dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b0e0
/*  f01b0e0:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f01b0e4:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f01b0e8:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01b0ec:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f01b0f0:	51e00004 */ 	beqzl	$t7,.L0f01b104
/*  f01b0f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f01b0f8:	03e00008 */ 	jr	$ra
/*  f01b0fc:	c4400010 */ 	lwc1	$f0,0x10($v0)
/*  f01b100:	3c013f80 */ 	lui	$at,0x3f80
.L0f01b104:
/*  f01b104:	44810000 */ 	mtc1	$at,$f0
/*  f01b108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b10c:	03e00008 */ 	jr	$ra
/*  f01b110:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b114
/*  f01b114:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f01b118:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f01b11c:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01b120:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f01b124:	51e00004 */ 	beqzl	$t7,.L0f01b138
/*  f01b128:	3c013f80 */ 	lui	$at,0x3f80
/*  f01b12c:	03e00008 */ 	jr	$ra
/*  f01b130:	c4400014 */ 	lwc1	$f0,0x14($v0)
/*  f01b134:	3c013f80 */ 	lui	$at,0x3f80
.L0f01b138:
/*  f01b138:	44810000 */ 	mtc1	$at,$f0
/*  f01b13c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b140:	03e00008 */ 	jr	$ra
/*  f01b144:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b148
/*  f01b148:	3c018006 */ 	lui	$at,0x8006
/*  f01b14c:	03e00008 */ 	jr	$ra
/*  f01b150:	ac2424e0 */ 	sw	$a0,0x24e0($at)
);

GLOBAL_ASM(
glabel func0f01b154
/*  f01b154:	3c018006 */ 	lui	$at,0x8006
/*  f01b158:	03e00008 */ 	jr	$ra
/*  f01b15c:	ac2424e4 */ 	sw	$a0,0x24e4($at)
);

GLOBAL_ASM(
glabel func0f01b160
/*  f01b160:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f01b164:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f01b168:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f01b16c:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f01b170:	8cce028c */ 	lw	$t6,0x28c($a2)
/*  f01b174:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f01b178:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f01b17c:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f01b180:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f01b184:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f01b188:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f01b18c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f01b190:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f01b194:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f01b198:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f01b19c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f01b1a0:	00003825 */ 	or	$a3,$zero,$zero
/*  f01b1a4:	11e00003 */ 	beqz	$t7,.L0f01b1b4
/*  f01b1a8:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f01b1ac:	10000002 */ 	beqz	$zero,.L0f01b1b8
/*  f01b1b0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f01b1b4:
/*  f01b1b4:	00002825 */ 	or	$a1,$zero,$zero
.L0f01b1b8:
/*  f01b1b8:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f01b1bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b1c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f01b1c4:	13000003 */ 	beqz	$t8,.L0f01b1d4
/*  f01b1c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f01b1cc:	10000001 */ 	beqz	$zero,.L0f01b1d4
/*  f01b1d0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f01b1d4:
/*  f01b1d4:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f01b1d8:	3c017f1b */ 	lui	$at,%hi(var7f1a85a4)
/*  f01b1dc:	13200003 */ 	beqz	$t9,.L0f01b1ec
/*  f01b1e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b1e4:	10000001 */ 	beqz	$zero,.L0f01b1ec
/*  f01b1e8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f01b1ec:
/*  f01b1ec:	8cc80070 */ 	lw	$t0,0x70($a2)
/*  f01b1f0:	11000003 */ 	beqz	$t0,.L0f01b200
/*  f01b1f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b1f8:	10000001 */ 	beqz	$zero,.L0f01b200
/*  f01b1fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01b200:
/*  f01b200:	00434821 */ 	addu	$t1,$v0,$v1
/*  f01b204:	01245021 */ 	addu	$t2,$t1,$a0
/*  f01b208:	01455821 */ 	addu	$t3,$t2,$a1
/*  f01b20c:	19600313 */ 	blez	$t3,.L0f01be5c
/*  f01b210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b214:	afa700d8 */ 	sw	$a3,0xd8($sp)
/*  f01b218:	c43485a4 */ 	lwc1	$f20,%lo(var7f1a85a4)($at)
.L0f01b21c:
/*  f01b21c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01b220:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f01b224:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01b228:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01b22c:	8cec028c */ 	lw	$t4,0x28c($a3)
/*  f01b230:	3c01800a */ 	lui	$at,0x800a
/*  f01b234:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b238:	ac2c21b8 */ 	sw	$t4,0x21b8($at)
/*  f01b23c:	8dad21b8 */ 	lw	$t5,0x21b8($t5)
/*  f01b240:	3c0f800a */ 	lui	$t7,0x800a
/*  f01b244:	2404003c */ 	addiu	$a0,$zero,0x3c
/*  f01b248:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f01b24c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f01b250:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f01b254:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f01b258:	91ef2100 */ 	lbu	$t7,0x2100($t7)
/*  f01b25c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01b260:	51e0000f */ 	beqzl	$t7,.L0f01b2a0
/*  f01b264:	8ce80318 */ 	lw	$t0,0x318($a3)
/*  f01b268:	0fc2a257 */ 	jal	func0f0a895c
/*  f01b26c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f01b270:	18400009 */ 	blez	$v0,.L0f01b298
/*  f01b274:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01b278:	3c18800a */ 	lui	$t8,0x800a
/*  f01b27c:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f01b280:	3c01800a */ 	lui	$at,0x800a
/*  f01b284:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f01b288:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f01b28c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f01b290:	00390821 */ 	addu	$at,$at,$t9
/*  f01b294:	a0202100 */ 	sb	$zero,0x2100($at)
.L0f01b298:
/*  f01b298:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01b29c:	8ce80318 */ 	lw	$t0,0x318($a3)
.L0f01b2a0:
/*  f01b2a0:	1500000f */ 	bnez	$t0,.L0f01b2e0
/*  f01b2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2a8:	0fc44a54 */ 	jal	currentPlayerGetNumInvItems
/*  f01b2ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2b0:	3c09800a */ 	lui	$t1,0x800a
/*  f01b2b4:	8d2921b8 */ 	lw	$t1,0x21b8($t1)
/*  f01b2b8:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b2bc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f01b2c0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f01b2c4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f01b2c8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f01b2cc:	916b2101 */ 	lbu	$t3,0x2101($t3)
/*  f01b2d0:	104b0003 */ 	beq	$v0,$t3,.L0f01b2e0
/*  f01b2d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2d8:	0fc3fb35 */ 	jal	func0f0fecd4
/*  f01b2dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b2e0:
/*  f01b2e0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01b2e4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01b2e8:	8cec0284 */ 	lw	$t4,0x284($a3)
/*  f01b2ec:	918d0250 */ 	lbu	$t5,0x250($t4)
/*  f01b2f0:	11a00244 */ 	beqz	$t5,.L0f01bc04
/*  f01b2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2f8:	8cee0288 */ 	lw	$t6,0x288($a3)
/*  f01b2fc:	0000f025 */ 	or	$s8,$zero,$zero
/*  f01b300:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f01b304:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f01b308:	3c0f800a */ 	lui	$t7,0x800a
/*  f01b30c:	8defa248 */ 	lw	$t7,-0x5db8($t7)
/*  f01b310:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f01b314:	0fc549d2 */ 	jal	optionsGetUnk45
/*  f01b318:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f01b31c:	0c005207 */ 	jal	func0001481c
/*  f01b320:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f01b324:	18400237 */ 	blez	$v0,.L0f01bc04
/*  f01b328:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f01b32c:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.L0f01b330:
/*  f01b330:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b334:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b338:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f01b33c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b340:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b344:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f01b348:	0c005212 */ 	jal	func00014848
/*  f01b34c:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f01b350:	0002b600 */ 	sll	$s6,$v0,0x18
/*  f01b354:	0016c603 */ 	sra	$t8,$s6,0x18
/*  f01b358:	0300b025 */ 	or	$s6,$t8,$zero
/*  f01b35c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b360:	0c005241 */ 	jal	func00014904
/*  f01b364:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b368:	0002be00 */ 	sll	$s7,$v0,0x18
/*  f01b36c:	0017ce03 */ 	sra	$t9,$s7,0x18
/*  f01b370:	0320b825 */ 	or	$s7,$t9,$zero
/*  f01b374:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b378:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b37c:	0c00529e */ 	jal	func00014a78
/*  f01b380:	3406ffff */ 	dli	$a2,0xffff
/*  f01b384:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f01b388:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b38c:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b390:	0c0052d4 */ 	jal	func00014b50
/*  f01b394:	3406ffff */ 	dli	$a2,0xffff
/*  f01b398:	3c08800a */ 	lui	$t0,0x800a
/*  f01b39c:	8d0821b8 */ 	lw	$t0,0x21b8($t0)
/*  f01b3a0:	3c0a800a */ 	lui	$t2,%hi(g_ActiveMenuThings)
/*  f01b3a4:	254a20d0 */ 	addiu	$t2,$t2,%lo(g_ActiveMenuThings)
/*  f01b3a8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b3ac:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b3b0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b3b4:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b3b8:	a2000032 */ 	sb	$zero,0x32($s0)
/*  f01b3bc:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b3c0:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f01b3c4:	a7a200be */ 	sh	$v0,0xbe($sp)
/*  f01b3c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b3cc:	916c0250 */ 	lbu	$t4,0x250($t3)
/*  f01b3d0:	02206825 */ 	or	$t5,$s1,$zero
/*  f01b3d4:	55810006 */ 	bnel	$t4,$at,.L0f01b3f0
/*  f01b3d8:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f01b3dc:	31b18000 */ 	andi	$s1,$t5,0x8000
/*  f01b3e0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f01b3e4:	0000b825 */ 	or	$s7,$zero,$zero
/*  f01b3e8:	a7a000be */ 	sh	$zero,0xbe($sp)
/*  f01b3ec:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.L0f01b3f0:
/*  f01b3f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b3f4:	32380010 */ 	andi	$t8,$s1,0x10
/*  f01b3f8:	11e10003 */ 	beq	$t7,$at,.L0f01b408
/*  f01b3fc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01b400:	15e1000c */ 	bne	$t7,$at,.L0f01b434
/*  f01b404:	322b8000 */ 	andi	$t3,$s1,0x8000
.L0f01b408:
/*  f01b408:	17000003 */ 	bnez	$t8,.L0f01b418
/*  f01b40c:	02209025 */ 	or	$s2,$s1,$zero
/*  f01b410:	32390020 */ 	andi	$t9,$s1,0x20
/*  f01b414:	13200002 */ 	beqz	$t9,.L0f01b420
.L0f01b418:
/*  f01b418:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01b41c:	afa800b0 */ 	sw	$t0,0xb0($sp)
.L0f01b420:
/*  f01b420:	32498000 */ 	andi	$t1,$s2,0x8000
/*  f01b424:	1120000d */ 	beqz	$t1,.L0f01b45c
/*  f01b428:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01b42c:	1000000b */ 	beqz	$zero,.L0f01b45c
/*  f01b430:	a20a0032 */ 	sb	$t2,0x32($s0)
.L0f01b434:
/*  f01b434:	11600003 */ 	beqz	$t3,.L0f01b444
/*  f01b438:	02209025 */ 	or	$s2,$s1,$zero
/*  f01b43c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f01b440:	afac00b0 */ 	sw	$t4,0xb0($sp)
.L0f01b444:
/*  f01b444:	324d0010 */ 	andi	$t5,$s2,0x10
/*  f01b448:	15a00002 */ 	bnez	$t5,.L0f01b454
/*  f01b44c:	324e0020 */ 	andi	$t6,$s2,0x20
/*  f01b450:	11c00002 */ 	beqz	$t6,.L0f01b45c
.L0f01b454:
/*  f01b454:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b458:	a20f0032 */ 	sb	$t7,0x32($s0)
.L0f01b45c:
/*  f01b45c:	92020032 */ 	lbu	$v0,0x32($s0)
/*  f01b460:	10400016 */ 	beqz	$v0,.L0f01b4bc
/*  f01b464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b468:	82030000 */ 	lb	$v1,0x0($s0)
/*  f01b46c:	28610002 */ 	slti	$at,$v1,0x2
/*  f01b470:	14200012 */ 	bnez	$at,.L0f01b4bc
/*  f01b474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b478:	82180034 */ 	lb	$t8,0x34($s0)
/*  f01b47c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f01b480:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b484:	1700000d */ 	bnez	$t8,.L0f01b4bc
/*  f01b488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b48c:	a2030034 */ 	sb	$v1,0x34($s0)
/*  f01b490:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01b494:	a2190000 */ 	sb	$t9,0x0($s0)
/*  f01b498:	3c08800a */ 	lui	$t0,0x800a
/*  f01b49c:	8d0821b8 */ 	lw	$t0,0x21b8($t0)
/*  f01b4a0:	3c0a800a */ 	lui	$t2,%hi(g_ActiveMenuThings)
/*  f01b4a4:	254a20d0 */ 	addiu	$t2,$t2,%lo(g_ActiveMenuThings)
/*  f01b4a8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b4ac:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b4b0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b4b4:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b4b8:	92020032 */ 	lbu	$v0,0x32($s0)
.L0f01b4bc:
/*  f01b4bc:	54400009 */ 	bnezl	$v0,.L0f01b4e4
/*  f01b4c0:	324b0008 */ 	andi	$t3,$s2,0x8
/*  f01b4c4:	82020034 */ 	lb	$v0,0x34($s0)
/*  f01b4c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b4cc:	50400005 */ 	beqzl	$v0,.L0f01b4e4
/*  f01b4d0:	324b0008 */ 	andi	$t3,$s2,0x8
/*  f01b4d4:	a2020000 */ 	sb	$v0,0x0($s0)
/*  f01b4d8:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01b4dc:	a2000034 */ 	sb	$zero,0x34($s0)
/*  f01b4e0:	324b0008 */ 	andi	$t3,$s2,0x8
.L0f01b4e4:
/*  f01b4e4:	11600002 */ 	beqz	$t3,.L0f01b4f0
/*  f01b4e8:	324c0004 */ 	andi	$t4,$s2,0x4
/*  f01b4ec:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b4f0:
/*  f01b4f0:	11800002 */ 	beqz	$t4,.L0f01b4fc
/*  f01b4f4:	324d0002 */ 	andi	$t5,$s2,0x2
/*  f01b4f8:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b4fc:
/*  f01b4fc:	11a00002 */ 	beqz	$t5,.L0f01b508
/*  f01b500:	324e0001 */ 	andi	$t6,$s2,0x1
/*  f01b504:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b508:
/*  f01b508:	11c00002 */ 	beqz	$t6,.L0f01b514
/*  f01b50c:	324f0800 */ 	andi	$t7,$s2,0x800
/*  f01b510:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b514:
/*  f01b514:	11e00002 */ 	beqz	$t7,.L0f01b520
/*  f01b518:	32580400 */ 	andi	$t8,$s2,0x400
/*  f01b51c:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b520:
/*  f01b520:	13000002 */ 	beqz	$t8,.L0f01b52c
/*  f01b524:	32590200 */ 	andi	$t9,$s2,0x200
/*  f01b528:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b52c:
/*  f01b52c:	13200002 */ 	beqz	$t9,.L0f01b538
/*  f01b530:	32480100 */ 	andi	$t0,$s2,0x100
/*  f01b534:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b538:
/*  f01b538:	11000002 */ 	beqz	$t0,.L0f01b544
/*  f01b53c:	8fa900d4 */ 	lw	$t1,0xd4($sp)
/*  f01b540:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b544:
/*  f01b544:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01b548:	11210008 */ 	beq	$t1,$at,.L0f01b56c
/*  f01b54c:	3c0a800a */ 	lui	$t2,0x800a
/*  f01b550:	24010007 */ 	addiu	$at,$zero,0x7
/*  f01b554:	11210005 */ 	beq	$t1,$at,.L0f01b56c
/*  f01b558:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01b55c:	11210003 */ 	beq	$t1,$at,.L0f01b56c
/*  f01b560:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b564:	15210089 */ 	bne	$t1,$at,.L0f01b78c
/*  f01b568:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b56c:
/*  f01b56c:	8d4aa248 */ 	lw	$t2,-0x5db8($t2)
/*  f01b570:	0fc549d9 */ 	jal	optionsGetUnk46
/*  f01b574:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f01b578:	00028600 */ 	sll	$s0,$v0,0x18
/*  f01b57c:	00022e00 */ 	sll	$a1,$v0,0x18
/*  f01b580:	00105e03 */ 	sra	$t3,$s0,0x18
/*  f01b584:	00056603 */ 	sra	$t4,$a1,0x18
/*  f01b588:	01608025 */ 	or	$s0,$t3,$zero
/*  f01b58c:	01802825 */ 	or	$a1,$t4,$zero
/*  f01b590:	0c005212 */ 	jal	func00014848
/*  f01b594:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b598:	00029600 */ 	sll	$s2,$v0,0x18
/*  f01b59c:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b5a0:	00126e03 */ 	sra	$t5,$s2,0x18
/*  f01b5a4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f01b5a8:	01a09025 */ 	or	$s2,$t5,$zero
/*  f01b5ac:	01c02825 */ 	or	$a1,$t6,$zero
/*  f01b5b0:	0c005241 */ 	jal	func00014904
/*  f01b5b4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b5b8:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f01b5bc:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b5c0:	00137e03 */ 	sra	$t7,$s3,0x18
/*  f01b5c4:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f01b5c8:	01e09825 */ 	or	$s3,$t7,$zero
/*  f01b5cc:	03002825 */ 	or	$a1,$t8,$zero
/*  f01b5d0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b5d4:	0c00529e */ 	jal	func00014a78
/*  f01b5d8:	3406ffff */ 	dli	$a2,0xffff
/*  f01b5dc:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b5e0:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f01b5e4:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f01b5e8:	03202825 */ 	or	$a1,$t9,$zero
/*  f01b5ec:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b5f0:	0c0052d4 */ 	jal	func00014b50
/*  f01b5f4:	3406ffff */ 	dli	$a2,0xffff
/*  f01b5f8:	3c08800a */ 	lui	$t0,0x800a
/*  f01b5fc:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f01b600:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b604:	3043ffff */ 	andi	$v1,$v0,0xffff
/*  f01b608:	91090250 */ 	lbu	$t1,0x250($t0)
/*  f01b60c:	02205025 */ 	or	$t2,$s1,$zero
/*  f01b610:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01b614:	15210005 */ 	bne	$t1,$at,.L0f01b62c
/*  f01b618:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b61c:	31518000 */ 	andi	$s1,$t2,0x8000
/*  f01b620:	00009025 */ 	or	$s2,$zero,$zero
/*  f01b624:	00009825 */ 	or	$s3,$zero,$zero
/*  f01b628:	00001825 */ 	or	$v1,$zero,$zero
.L0f01b62c:
/*  f01b62c:	322c8000 */ 	andi	$t4,$s1,0x8000
/*  f01b630:	11800002 */ 	beqz	$t4,.L0f01b63c
/*  f01b634:	02201025 */ 	or	$v0,$s1,$zero
/*  f01b638:	afad00b0 */ 	sw	$t5,0xb0($sp)
.L0f01b63c:
/*  f01b63c:	306e2000 */ 	andi	$t6,$v1,0x2000
/*  f01b640:	11c00002 */ 	beqz	$t6,.L0f01b64c
/*  f01b644:	30580008 */ 	andi	$t8,$v0,0x8
/*  f01b648:	afaf00ac */ 	sw	$t7,0xac($sp)
.L0f01b64c:
/*  f01b64c:	13000002 */ 	beqz	$t8,.L0f01b658
/*  f01b650:	30590004 */ 	andi	$t9,$v0,0x4
/*  f01b654:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b658:
/*  f01b658:	13200002 */ 	beqz	$t9,.L0f01b664
/*  f01b65c:	30480002 */ 	andi	$t0,$v0,0x2
/*  f01b660:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b664:
/*  f01b664:	11000002 */ 	beqz	$t0,.L0f01b670
/*  f01b668:	30490001 */ 	andi	$t1,$v0,0x1
/*  f01b66c:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b670:
/*  f01b670:	11200002 */ 	beqz	$t1,.L0f01b67c
/*  f01b674:	304a0800 */ 	andi	$t2,$v0,0x800
/*  f01b678:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b67c:
/*  f01b67c:	11400002 */ 	beqz	$t2,.L0f01b688
/*  f01b680:	304b0400 */ 	andi	$t3,$v0,0x400
/*  f01b684:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b688:
/*  f01b688:	11600002 */ 	beqz	$t3,.L0f01b694
/*  f01b68c:	304c0200 */ 	andi	$t4,$v0,0x200
/*  f01b690:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b694:
/*  f01b694:	11800002 */ 	beqz	$t4,.L0f01b6a0
/*  f01b698:	304d0100 */ 	andi	$t5,$v0,0x100
/*  f01b69c:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b6a0:
/*  f01b6a0:	11a00002 */ 	beqz	$t5,.L0f01b6ac
/*  f01b6a4:	00121e00 */ 	sll	$v1,$s2,0x18
/*  f01b6a8:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b6ac:
/*  f01b6ac:	06410005 */ 	bgez	$s2,.L0f01b6c4
/*  f01b6b0:	0003c603 */ 	sra	$t8,$v1,0x18
/*  f01b6b4:	00121823 */ 	negu	$v1,$s2
/*  f01b6b8:	00037600 */ 	sll	$t6,$v1,0x18
/*  f01b6bc:	10000002 */ 	beqz	$zero,.L0f01b6c8
/*  f01b6c0:	000e1e03 */ 	sra	$v1,$t6,0x18
.L0f01b6c4:
/*  f01b6c4:	03001825 */ 	or	$v1,$t8,$zero
.L0f01b6c8:
/*  f01b6c8:	06610005 */ 	bgez	$s3,.L0f01b6e0
/*  f01b6cc:	28610015 */ 	slti	$at,$v1,0x15
/*  f01b6d0:	00131023 */ 	negu	$v0,$s3
/*  f01b6d4:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f01b6d8:	10000004 */ 	beqz	$zero,.L0f01b6ec
/*  f01b6dc:	00191603 */ 	sra	$v0,$t9,0x18
.L0f01b6e0:
/*  f01b6e0:	00131600 */ 	sll	$v0,$s3,0x18
/*  f01b6e4:	00024e03 */ 	sra	$t1,$v0,0x18
/*  f01b6e8:	01201025 */ 	or	$v0,$t1,$zero
.L0f01b6ec:
/*  f01b6ec:	10200004 */ 	beqz	$at,.L0f01b700
/*  f01b6f0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01b6f4:	28410015 */ 	slti	$at,$v0,0x15
/*  f01b6f8:	14200024 */ 	bnez	$at,.L0f01b78c
/*  f01b6fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b700:
/*  f01b700:	44822000 */ 	mtc1	$v0,$f4
/*  f01b704:	44833000 */ 	mtc1	$v1,$f6
/*  f01b708:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f01b70c:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f01b710:	46020203 */ 	div.s	$f8,$f0,$f2
/*  f01b714:	4614403c */ 	c.lt.s	$f8,$f20
/*  f01b718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b71c:	45020008 */ 	bc1fl	.L0f01b740
/*  f01b720:	46001283 */ 	div.s	$f10,$f2,$f0
/*  f01b724:	06410003 */ 	bgez	$s2,.L0f01b734
/*  f01b728:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b72c:	10000016 */ 	beqz	$zero,.L0f01b788
/*  f01b730:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b734:
/*  f01b734:	10000014 */ 	beqz	$zero,.L0f01b788
/*  f01b738:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b73c:	46001283 */ 	div.s	$f10,$f2,$f0
.L0f01b740:
/*  f01b740:	4614503c */ 	c.lt.s	$f10,$f20
/*  f01b744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b748:	45000007 */ 	bc1f	.L0f01b768
/*  f01b74c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b750:	06610003 */ 	bgez	$s3,.L0f01b760
/*  f01b754:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b758:	1000000b */ 	beqz	$zero,.L0f01b788
/*  f01b75c:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b760:
/*  f01b760:	10000009 */ 	beqz	$zero,.L0f01b788
/*  f01b764:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b768:
/*  f01b768:	06410003 */ 	bgez	$s2,.L0f01b778
/*  f01b76c:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b770:	10000001 */ 	beqz	$zero,.L0f01b778
/*  f01b774:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b778:
/*  f01b778:	06610003 */ 	bgez	$s3,.L0f01b788
/*  f01b77c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f01b780:	10000001 */ 	beqz	$zero,.L0f01b788
/*  f01b784:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b788:
/*  f01b788:	afaa00b8 */ 	sw	$t2,0xb8($sp)
.L0f01b78c:
/*  f01b78c:	3c04800a */ 	lui	$a0,0x800a
/*  f01b790:	06c10005 */ 	bgez	$s6,.L0f01b7a8
/*  f01b794:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f01b798:	00161823 */ 	negu	$v1,$s6
/*  f01b79c:	00035e00 */ 	sll	$t3,$v1,0x18
/*  f01b7a0:	10000004 */ 	beqz	$zero,.L0f01b7b4
/*  f01b7a4:	000b1e03 */ 	sra	$v1,$t3,0x18
.L0f01b7a8:
/*  f01b7a8:	00161e00 */ 	sll	$v1,$s6,0x18
/*  f01b7ac:	00036e03 */ 	sra	$t5,$v1,0x18
/*  f01b7b0:	01a01825 */ 	or	$v1,$t5,$zero
.L0f01b7b4:
/*  f01b7b4:	06e10005 */ 	bgez	$s7,.L0f01b7cc
/*  f01b7b8:	28610015 */ 	slti	$at,$v1,0x15
/*  f01b7bc:	00171023 */ 	negu	$v0,$s7
/*  f01b7c0:	00027600 */ 	sll	$t6,$v0,0x18
/*  f01b7c4:	10000004 */ 	beqz	$zero,.L0f01b7d8
/*  f01b7c8:	000e1603 */ 	sra	$v0,$t6,0x18
.L0f01b7cc:
/*  f01b7cc:	00171600 */ 	sll	$v0,$s7,0x18
/*  f01b7d0:	0002c603 */ 	sra	$t8,$v0,0x18
/*  f01b7d4:	03001025 */ 	or	$v0,$t8,$zero
.L0f01b7d8:
/*  f01b7d8:	10200004 */ 	beqz	$at,.L0f01b7ec
/*  f01b7dc:	3c09800a */ 	lui	$t1,0x800a
/*  f01b7e0:	28410015 */ 	slti	$at,$v0,0x15
/*  f01b7e4:	54200026 */ 	bnezl	$at,.L0f01b880
/*  f01b7e8:	8c8800d8 */ 	lw	$t0,0xd8($a0)
.L0f01b7ec:
/*  f01b7ec:	44828000 */ 	mtc1	$v0,$f16
/*  f01b7f0:	44839000 */ 	mtc1	$v1,$f18
/*  f01b7f4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01b7f8:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f01b7fc:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f01b800:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f01b804:	46020103 */ 	div.s	$f4,$f0,$f2
/*  f01b808:	4614203c */ 	c.lt.s	$f4,$f20
/*  f01b80c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b810:	45020008 */ 	bc1fl	.L0f01b834
/*  f01b814:	46001183 */ 	div.s	$f6,$f2,$f0
/*  f01b818:	06c10003 */ 	bgez	$s6,.L0f01b828
/*  f01b81c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b820:	10000016 */ 	beqz	$zero,.L0f01b87c
/*  f01b824:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b828:
/*  f01b828:	10000014 */ 	beqz	$zero,.L0f01b87c
/*  f01b82c:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b830:	46001183 */ 	div.s	$f6,$f2,$f0
.L0f01b834:
/*  f01b834:	4614303c */ 	c.lt.s	$f6,$f20
/*  f01b838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b83c:	45000007 */ 	bc1f	.L0f01b85c
/*  f01b840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b844:	06e10003 */ 	bgez	$s7,.L0f01b854
/*  f01b848:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b84c:	1000000b */ 	beqz	$zero,.L0f01b87c
/*  f01b850:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b854:
/*  f01b854:	10000009 */ 	beqz	$zero,.L0f01b87c
/*  f01b858:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b85c:
/*  f01b85c:	06c10003 */ 	bgez	$s6,.L0f01b86c
/*  f01b860:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b864:	10000001 */ 	beqz	$zero,.L0f01b86c
/*  f01b868:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b86c:
/*  f01b86c:	06e10003 */ 	bgez	$s7,.L0f01b87c
/*  f01b870:	0000a025 */ 	or	$s4,$zero,$zero
/*  f01b874:	10000001 */ 	beqz	$zero,.L0f01b87c
/*  f01b878:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b87c:
/*  f01b87c:	8c8800d8 */ 	lw	$t0,0xd8($a0)
.L0f01b880:
/*  f01b880:	3c0c8007 */ 	lui	$t4,0x8007
/*  f01b884:	11000002 */ 	beqz	$t0,.L0f01b890
/*  f01b888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b88c:	afa000b0 */ 	sw	$zero,0xb0($sp)
.L0f01b890:
/*  f01b890:	8d299ff4 */ 	lw	$t1,-0x600c($t1)
/*  f01b894:	55200003 */ 	bnezl	$t1,.L0f01b8a4
/*  f01b898:	8faa00b0 */ 	lw	$t2,0xb0($sp)
/*  f01b89c:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f01b8a0:	8faa00b0 */ 	lw	$t2,0xb0($sp)
.L0f01b8a4:
/*  f01b8a4:	97af00be */ 	lhu	$t7,0xbe($sp)
/*  f01b8a8:	15400016 */ 	bnez	$t2,.L0f01b904
/*  f01b8ac:	31f82000 */ 	andi	$t8,$t7,0x2000
/*  f01b8b0:	908b0250 */ 	lbu	$t3,0x250($a0)
/*  f01b8b4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b8b8:	1561000e */ 	bne	$t3,$at,.L0f01b8f4
/*  f01b8bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b8c0:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f01b8c4:	3c0e800a */ 	lui	$t6,0x800a
/*  f01b8c8:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f01b8cc:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01b8d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f01b8d4:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f01b8d8:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f01b8dc:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01b8e0:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f01b8e4:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f01b8e8:	8dcee4f8 */ 	lw	$t6,-0x1b08($t6)
/*  f01b8ec:	15c00005 */ 	bnez	$t6,.L0f01b904
/*  f01b8f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b8f4:
/*  f01b8f4:	0fc3fc10 */ 	jal	activemenuClose
/*  f01b8f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b8fc:	100000c1 */ 	beqz	$zero,.L0f01bc04
/*  f01b900:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b904:
/*  f01b904:	13000002 */ 	beqz	$t8,.L0f01b910
/*  f01b908:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01b90c:	afb900ac */ 	sw	$t9,0xac($sp)
.L0f01b910:
/*  f01b910:	8fa800ac */ 	lw	$t0,0xac($sp)
/*  f01b914:	3c09800a */ 	lui	$t1,0x800a
/*  f01b918:	51000047 */ 	beqzl	$t0,.L0f01ba38
/*  f01b91c:	83ad00c7 */ 	lb	$t5,0xc7($sp)
/*  f01b920:	8d2921b8 */ 	lw	$t1,0x21b8($t1)
/*  f01b924:	3c0b800a */ 	lui	$t3,%hi(g_ActiveMenuThings)
/*  f01b928:	256b20d0 */ 	addiu	$t3,$t3,%lo(g_ActiveMenuThings)
/*  f01b92c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f01b930:	01495023 */ 	subu	$t2,$t2,$t1
/*  f01b934:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f01b938:	014b8021 */ 	addu	$s0,$t2,$t3
/*  f01b93c:	820c0000 */ 	lb	$t4,0x0($s0)
/*  f01b940:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b944:	29810002 */ 	slti	$at,$t4,0x2
/*  f01b948:	54200032 */ 	bnezl	$at,.L0f01ba14
/*  f01b94c:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b950:	8dada434 */ 	lw	$t5,-0x5bcc($t5)
/*  f01b954:	3c0e800a */ 	lui	$t6,0x800a
/*  f01b958:	51a00010 */ 	beqzl	$t5,.L0f01b99c
/*  f01b95c:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f01b960:	81cfdfeb */ 	lb	$t7,-0x2015($t6)
/*  f01b964:	05e3000d */ 	bgezl	$t7,.L0f01b99c
/*  f01b968:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f01b96c:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b970:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b974:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f01b978:	14810003 */ 	bne	$a0,$at,.L0f01b988
/*  f01b97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b980:	1000002c */ 	beqz	$zero,.L0f01ba34
/*  f01b984:	a3b800c7 */ 	sb	$t8,0xc7($sp)
.L0f01b988:
/*  f01b988:	0fc3f7c5 */ 	jal	activemenuApply
/*  f01b98c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b990:	10000029 */ 	beqz	$zero,.L0f01ba38
/*  f01b994:	83ad00c7 */ 	lb	$t5,0xc7($sp)
/*  f01b998:	9202000e */ 	lbu	$v0,0xe($s0)
.L0f01b99c:
/*  f01b99c:	3c19800b */ 	lui	$t9,0x800b
/*  f01b9a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01b9a4:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f01b9a8:	9339cb78 */ 	lbu	$t9,-0x3488($t9)
/*  f01b9ac:	5721000d */ 	bnel	$t9,$at,.L0f01b9e4
/*  f01b9b0:	920a0032 */ 	lbu	$t2,0x32($s0)
/*  f01b9b4:	0fc3f598 */ 	jal	mpOpenPickTarget
/*  f01b9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b9bc:	3c08800a */ 	lui	$t0,0x800a
/*  f01b9c0:	8d0821b8 */ 	lw	$t0,0x21b8($t0)
/*  f01b9c4:	3c02800a */ 	lui	$v0,0x800a
/*  f01b9c8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b9cc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b9d0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b9d4:	00491021 */ 	addu	$v0,$v0,$t1
/*  f01b9d8:	10000006 */ 	beqz	$zero,.L0f01b9f4
/*  f01b9dc:	904220de */ 	lbu	$v0,0x20de($v0)
/*  f01b9e0:	920a0032 */ 	lbu	$t2,0x32($s0)
.L0f01b9e4:
/*  f01b9e4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f01b9e8:	55400003 */ 	bnezl	$t2,.L0f01b9f8
/*  f01b9ec:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b9f0:	a3ab00c7 */ 	sb	$t3,0xc7($sp)
.L0f01b9f4:
/*  f01b9f4:	24010004 */ 	addiu	$at,$zero,0x4
.L0f01b9f8:
/*  f01b9f8:	1041000e */ 	beq	$v0,$at,.L0f01ba34
/*  f01b9fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f01ba00:	0fc3f7c5 */ 	jal	activemenuApply
/*  f01ba04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba08:	1000000b */ 	beqz	$zero,.L0f01ba38
/*  f01ba0c:	83ad00c7 */ 	lb	$t5,0xc7($sp)
/*  f01ba10:	9204000e */ 	lbu	$a0,0xe($s0)
.L0f01ba14:
/*  f01ba14:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01ba18:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f01ba1c:	14810003 */ 	bne	$a0,$at,.L0f01ba2c
/*  f01ba20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba24:	10000003 */ 	beqz	$zero,.L0f01ba34
/*  f01ba28:	a3ac00c7 */ 	sb	$t4,0xc7($sp)
.L0f01ba2c:
/*  f01ba2c:	0fc3f7c5 */ 	jal	activemenuApply
/*  f01ba30:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01ba34:
/*  f01ba34:	83ad00c7 */ 	lb	$t5,0xc7($sp)
.L0f01ba38:
/*  f01ba38:	11a0001f */ 	beqz	$t5,.L0f01bab8
/*  f01ba3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba40:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01ba44:	01a02025 */ 	or	$a0,$t5,$zero
/*  f01ba48:	3c0e800a */ 	lui	$t6,0x800a
/*  f01ba4c:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f01ba50:	3c18800a */ 	lui	$t8,0x800a
/*  f01ba54:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01ba58:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f01ba5c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f01ba60:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f01ba64:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f01ba68:	831820d0 */ 	lb	$t8,0x20d0($t8)
/*  f01ba6c:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f01ba70:	17010011 */ 	bne	$t8,$at,.L0f01bab8
/*  f01ba74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba78:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f01ba7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01ba80:	0fc2c42e */ 	jal	weaponGetFunction
/*  f01ba84:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f01ba88:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f01ba8c:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f01ba90:	00408025 */ 	or	$s0,$v0,$zero
/*  f01ba94:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f01ba98:	0fc2c42e */ 	jal	weaponGetFunction
/*  f01ba9c:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f01baa0:	16000005 */ 	bnez	$s0,.L0f01bab8
/*  f01baa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01baa8:	14400003 */ 	bnez	$v0,.L0f01bab8
/*  f01baac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bab0:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01bab4:	83a400c7 */ 	lb	$a0,0xc7($sp)
.L0f01bab8:
/*  f01bab8:	3c19800a */ 	lui	$t9,0x800a
/*  f01babc:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f01bac0:	00144880 */ 	sll	$t1,$s4,0x2
/*  f01bac4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01bac8:	93280250 */ 	lbu	$t0,0x250($t9)
/*  f01bacc:	01344823 */ 	subu	$t1,$t1,$s4
/*  f01bad0:	02a99021 */ 	addu	$s2,$s5,$t1
/*  f01bad4:	11010046 */ 	beq	$t0,$at,.L0f01bbf0
/*  f01bad8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01badc:	16410011 */ 	bne	$s2,$at,.L0f01bb24
/*  f01bae0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f01bae4:	3c0a800a */ 	lui	$t2,0x800a
/*  f01bae8:	8d4a21b8 */ 	lw	$t2,0x21b8($t2)
/*  f01baec:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuThings)
/*  f01baf0:	258c20d0 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuThings)
/*  f01baf4:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f01baf8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f01bafc:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f01bb00:	016c8021 */ 	addu	$s0,$t3,$t4
/*  f01bb04:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f01bb08:	1c400004 */ 	bgtz	$v0,.L0f01bb1c
/*  f01bb0c:	244dffff */ 	addiu	$t5,$v0,-1
/*  f01bb10:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f01bb14:	10000036 */ 	beqz	$zero,.L0f01bbf0
/*  f01bb18:	a212000e */ 	sb	$s2,0xe($s0)
.L0f01bb1c:
/*  f01bb1c:	10000034 */ 	beqz	$zero,.L0f01bbf0
/*  f01bb20:	ae0d0014 */ 	sw	$t5,0x14($s0)
.L0f01bb24:
/*  f01bb24:	02402025 */ 	or	$a0,$s2,$zero
/*  f01bb28:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f01bb2c:	0fc3f8a0 */ 	jal	activemenuGetSlotDetails
/*  f01bb30:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f01bb34:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f01bb38:	24a585a0 */ 	addiu	$a1,$a1,-31328
/*  f01bb3c:	0c004c9d */ 	jal	func00013274
/*  f01bb40:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f01bb44:	14400002 */ 	bnez	$v0,.L0f01bb50
/*  f01bb48:	3c0e800a */ 	lui	$t6,0x800a
/*  f01bb4c:	00008825 */ 	or	$s1,$zero,$zero
.L0f01bb50:
/*  f01bb50:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f01bb54:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuThings)
/*  f01bb58:	271820d0 */ 	addiu	$t8,$t8,%lo(g_ActiveMenuThings)
/*  f01bb5c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f01bb60:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f01bb64:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f01bb68:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f01bb6c:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01bb70:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01bb74:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f01bb78:	10810019 */ 	beq	$a0,$at,.L0f01bbe0
/*  f01bb7c:	240b000f */ 	addiu	$t3,$zero,0xf
/*  f01bb80:	17200017 */ 	bnez	$t9,.L0f01bbe0
/*  f01bb84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bb88:	10800007 */ 	beqz	$a0,.L0f01bba8
/*  f01bb8c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01bb90:	10810005 */ 	beq	$a0,$at,.L0f01bba8
/*  f01bb94:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01bb98:	10810003 */ 	beq	$a0,$at,.L0f01bba8
/*  f01bb9c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f01bba0:	1481000f */ 	bne	$a0,$at,.L0f01bbe0
/*  f01bba4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01bba8:
/*  f01bba8:	9208000f */ 	lbu	$t0,0xf($s0)
/*  f01bbac:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f01bbb0:	52480005 */ 	beql	$s2,$t0,.L0f01bbc8
/*  f01bbb4:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f01bbb8:	ae090010 */ 	sw	$t1,0x10($s0)
/*  f01bbbc:	a212000f */ 	sb	$s2,0xf($s0)
/*  f01bbc0:	00008825 */ 	or	$s1,$zero,$zero
/*  f01bbc4:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f01bbc8:
/*  f01bbc8:	18400005 */ 	blez	$v0,.L0f01bbe0
/*  f01bbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bbd0:	12200003 */ 	beqz	$s1,.L0f01bbe0
/*  f01bbd4:	244affff */ 	addiu	$t2,$v0,-1
/*  f01bbd8:	00008825 */ 	or	$s1,$zero,$zero
/*  f01bbdc:	ae0a0010 */ 	sw	$t2,0x10($s0)
.L0f01bbe0:
/*  f01bbe0:	52200004 */ 	beqzl	$s1,.L0f01bbf4
/*  f01bbe4:	8fac00cc */ 	lw	$t4,0xcc($sp)
/*  f01bbe8:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*  f01bbec:	a212000e */ 	sb	$s2,0xe($s0)
.L0f01bbf0:
/*  f01bbf0:	8fac00cc */ 	lw	$t4,0xcc($sp)
.L0f01bbf4:
/*  f01bbf4:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f01bbf8:	03cc082a */ 	slt	$at,$s8,$t4
/*  f01bbfc:	5420fdcc */ 	bnezl	$at,.L0f01b330
/*  f01bc00:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.L0f01bc04:
/*  f01bc04:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01bc08:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01bc0c:	8ced0284 */ 	lw	$t5,0x284($a3)
/*  f01bc10:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01bc14:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01bc18:	91ae0250 */ 	lbu	$t6,0x250($t5)
/*  f01bc1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01bc20:	3c0f800a */ 	lui	$t7,0x800a
/*  f01bc24:	11c1006e */ 	beq	$t6,$at,.L0f01bde0
/*  f01bc28:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01bc2c:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f01bc30:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuThings)
/*  f01bc34:	273920d0 */ 	addiu	$t9,$t9,%lo(g_ActiveMenuThings)
/*  f01bc38:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f01bc3c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f01bc40:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f01bc44:	03198021 */ 	addu	$s0,$t8,$t9
/*  f01bc48:	8603000a */ 	lh	$v1,0xa($s0)
/*  f01bc4c:	2401ff85 */ 	addiu	$at,$zero,-123
/*  f01bc50:	50610026 */ 	beql	$v1,$at,.L0f01bcec
/*  f01bc54:	86020004 */ 	lh	$v0,0x4($s0)
/*  f01bc58:	86080006 */ 	lh	$t0,0x6($s0)
/*  f01bc5c:	8604000c */ 	lh	$a0,0xc($s0)
/*  f01bc60:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f01bc64:	00684821 */ 	addu	$t1,$v1,$t0
/*  f01bc68:	05210003 */ 	bgez	$t1,.L0f01bc78
/*  f01bc6c:	00095043 */ 	sra	$t2,$t1,0x1
/*  f01bc70:	25210001 */ 	addiu	$at,$t1,0x1
/*  f01bc74:	00015043 */ 	sra	$t2,$at,0x1
.L0f01bc78:
/*  f01bc78:	a60a0006 */ 	sh	$t2,0x6($s0)
/*  f01bc7c:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f01bc80:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f01bc84:	05810003 */ 	bgez	$t4,.L0f01bc94
/*  f01bc88:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f01bc8c:	25810001 */ 	addiu	$at,$t4,0x1
/*  f01bc90:	00016843 */ 	sra	$t5,$at,0x1
.L0f01bc94:
/*  f01bc94:	01c31023 */ 	subu	$v0,$t6,$v1
/*  f01bc98:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f01bc9c:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f01bca0:	2b010002 */ 	slti	$at,$t8,0x2
/*  f01bca4:	10200006 */ 	beqz	$at,.L0f01bcc0
/*  f01bca8:	a60d0008 */ 	sh	$t5,0x8($s0)
/*  f01bcac:	2b01ffff */ 	slti	$at,$t8,-1
/*  f01bcb0:	54200004 */ 	bnezl	$at,.L0f01bcc4
/*  f01bcb4:	86190008 */ 	lh	$t9,0x8($s0)
/*  f01bcb8:	a6030006 */ 	sh	$v1,0x6($s0)
/*  f01bcbc:	8604000c */ 	lh	$a0,0xc($s0)
.L0f01bcc0:
/*  f01bcc0:	86190008 */ 	lh	$t9,0x8($s0)
.L0f01bcc4:
/*  f01bcc4:	03241023 */ 	subu	$v0,$t9,$a0
/*  f01bcc8:	00024400 */ 	sll	$t0,$v0,0x10
/*  f01bccc:	00084c03 */ 	sra	$t1,$t0,0x10
/*  f01bcd0:	29210002 */ 	slti	$at,$t1,0x2
/*  f01bcd4:	10200004 */ 	beqz	$at,.L0f01bce8
/*  f01bcd8:	2921ffff */ 	slti	$at,$t1,-1
/*  f01bcdc:	54200003 */ 	bnezl	$at,.L0f01bcec
/*  f01bce0:	86020004 */ 	lh	$v0,0x4($s0)
/*  f01bce4:	a6040008 */ 	sh	$a0,0x8($s0)
.L0f01bce8:
/*  f01bce8:	86020004 */ 	lh	$v0,0x4($s0)
.L0f01bcec:
/*  f01bcec:	860c0002 */ 	lh	$t4,0x2($s0)
/*  f01bcf0:	24420005 */ 	addiu	$v0,$v0,0x5
/*  f01bcf4:	00025400 */ 	sll	$t2,$v0,0x10
/*  f01bcf8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f01bcfc:	000a5c03 */ 	sra	$t3,$t2,0x10
/*  f01bd00:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01bd04:	01ab7021 */ 	addu	$t6,$t5,$t3
/*  f01bd08:	01601025 */ 	or	$v0,$t3,$zero
/*  f01bd0c:	05c10003 */ 	bgez	$t6,.L0f01bd1c
/*  f01bd10:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f01bd14:	25c10003 */ 	addiu	$at,$t6,0x3
/*  f01bd18:	00017883 */ 	sra	$t7,$at,0x2
.L0f01bd1c:
/*  f01bd1c:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f01bd20:	86180002 */ 	lh	$t8,0x2($s0)
/*  f01bd24:	03021823 */ 	subu	$v1,$t8,$v0
/*  f01bd28:	0003cc00 */ 	sll	$t9,$v1,0x10
/*  f01bd2c:	00194403 */ 	sra	$t0,$t9,0x10
/*  f01bd30:	29010002 */ 	slti	$at,$t0,0x2
/*  f01bd34:	10200004 */ 	beqz	$at,.L0f01bd48
/*  f01bd38:	2901ffff */ 	slti	$at,$t0,-1
/*  f01bd3c:	54200003 */ 	bnezl	$at,.L0f01bd4c
/*  f01bd40:	3c013f80 */ 	lui	$at,0x3f80
/*  f01bd44:	a6020002 */ 	sh	$v0,0x2($s0)
.L0f01bd48:
/*  f01bd48:	3c013f80 */ 	lui	$at,0x3f80
.L0f01bd4c:
/*  f01bd4c:	44816000 */ 	mtc1	$at,$f12
/*  f01bd50:	c6000018 */ 	lwc1	$f0,0x18($s0)
/*  f01bd54:	3c01800a */ 	lui	$at,0x800a
/*  f01bd58:	460c003c */ 	c.lt.s	$f0,$f12
/*  f01bd5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bd60:	45000009 */ 	bc1f	.L0f01bd88
/*  f01bd64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bd68:	c428a004 */ 	lwc1	$f8,-0x5ffc($at)
/*  f01bd6c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f01bd70:	44815000 */ 	mtc1	$at,$f10
/*  f01bd74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bd78:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f01bd7c:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f01bd80:	e6120018 */ 	swc1	$f18,0x18($s0)
/*  f01bd84:	c6000018 */ 	lwc1	$f0,0x18($s0)
.L0f01bd88:
/*  f01bd88:	3c01800a */ 	lui	$at,0x800a
/*  f01bd8c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f01bd90:	c422a004 */ 	lwc1	$f2,-0x5ffc($at)
/*  f01bd94:	3c0140a0 */ 	lui	$at,0x40a0
/*  f01bd98:	44813000 */ 	mtc1	$at,$f6
/*  f01bd9c:	45000002 */ 	bc1f	.L0f01bda8
/*  f01bda0:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f01bda4:	e60c0018 */ 	swc1	$f12,0x18($s0)
.L0f01bda8:
/*  f01bda8:	c604001c */ 	lwc1	$f4,0x1c($s0)
/*  f01bdac:	3c017f1b */ 	lui	$at,%hi(var7f1a85a8)
/*  f01bdb0:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f01bdb4:	e60a001c */ 	swc1	$f10,0x1c($s0)
/*  f01bdb8:	c43085a8 */ 	lwc1	$f16,%lo(var7f1a85a8)($at)
/*  f01bdbc:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*  f01bdc0:	3c017f1b */ 	lui	$at,%hi(var7f1a85ac)
/*  f01bdc4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f01bdc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bdcc:	45020005 */ 	bc1fl	.L0f01bde4
/*  f01bdd0:	8ce9006c */ 	lw	$t1,0x6c($a3)
/*  f01bdd4:	c43285ac */ 	lwc1	$f18,%lo(var7f1a85ac)($at)
/*  f01bdd8:	46120181 */ 	sub.s	$f6,$f0,$f18
/*  f01bddc:	e606001c */ 	swc1	$f6,0x1c($s0)
.L0f01bde0:
/*  f01bde0:	8ce9006c */ 	lw	$t1,0x6c($a3)
.L0f01bde4:
/*  f01bde4:	8fa600d8 */ 	lw	$a2,0xd8($sp)
/*  f01bde8:	3c0b800a */ 	lui	$t3,0x800a
/*  f01bdec:	11200003 */ 	beqz	$t1,.L0f01bdfc
/*  f01bdf0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f01bdf4:	10000001 */ 	beqz	$zero,.L0f01bdfc
/*  f01bdf8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f01bdfc:
/*  f01bdfc:	8cea0068 */ 	lw	$t2,0x68($a3)
/*  f01be00:	3c0c800a */ 	lui	$t4,0x800a
/*  f01be04:	00002025 */ 	or	$a0,$zero,$zero
/*  f01be08:	11400003 */ 	beqz	$t2,.L0f01be18
/*  f01be0c:	00001825 */ 	or	$v1,$zero,$zero
/*  f01be10:	10000001 */ 	beqz	$zero,.L0f01be18
/*  f01be14:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f01be18:
/*  f01be18:	8d6ba024 */ 	lw	$t3,-0x5fdc($t3)
/*  f01be1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f01be20:	11600003 */ 	beqz	$t3,.L0f01be30
/*  f01be24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01be28:	10000001 */ 	beqz	$zero,.L0f01be30
/*  f01be2c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f01be30:
/*  f01be30:	8d8ca030 */ 	lw	$t4,-0x5fd0($t4)
/*  f01be34:	11800003 */ 	beqz	$t4,.L0f01be44
/*  f01be38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01be3c:	10000001 */ 	beqz	$zero,.L0f01be44
/*  f01be40:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01be44:
/*  f01be44:	00436821 */ 	addu	$t5,$v0,$v1
/*  f01be48:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f01be4c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f01be50:	00cf082a */ 	slt	$at,$a2,$t7
/*  f01be54:	1420fcf1 */ 	bnez	$at,.L0f01b21c
/*  f01be58:	afa600d8 */ 	sw	$a2,0xd8($sp)
.L0f01be5c:
/*  f01be5c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01be60:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f01be64:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f01be68:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f01be6c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f01be70:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f01be74:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f01be78:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f01be7c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f01be80:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f01be84:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f01be88:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f01be8c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f01be90:	03e00008 */ 	jr	$ra
/*  f01be94:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
/*  f01be98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01be9c:	00000000 */ 	sll	$zero,$zero,0x0
);
