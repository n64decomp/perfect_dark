#include "n_synthInternals.h"
#include <os.h>
#include <R4300.h>

#define ADPCMFBYTES      9
#define LFSAMPLES        4

GLOBAL_ASM(
glabel n_alAdpcmPull
/*    44f60:	27bdff80 */ 	addiu	$sp,$sp,-128
/*    44f64:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    44f68:	afa40080 */ 	sw	$a0,0x80($sp)
/*    44f6c:	afa50084 */ 	sw	$a1,0x84($sp)
/*    44f70:	afa60088 */ 	sw	$a2,0x88($sp)
/*    44f74:	afa7008c */ 	sw	$a3,0x8c($sp)
/*    44f78:	afb00028 */ 	sw	$s0,0x28($sp)
/*    44f7c:	8fae008c */ 	lw	$t6,0x8c($sp)
/*    44f80:	afae007c */ 	sw	$t6,0x7c($sp)
/*    44f84:	afa0004c */ 	sw	$zero,0x4c($sp)
/*    44f88:	afa00048 */ 	sw	$zero,0x48($sp)
/*    44f8c:	8faf0080 */ 	lw	$t7,0x80($sp)
/*    44f90:	afaf0044 */ 	sw	$t7,0x44($sp)
/*    44f94:	8fb80088 */ 	lw	$t8,0x88($sp)
/*    44f98:	17000003 */ 	bnez	$t8,.L00044fa8
/*    44f9c:	00000000 */ 	nop
/*    44fa0:	10000194 */ 	b	.L000455f4
/*    44fa4:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L00044fa8:
/*    44fa8:	a7a0007a */ 	sh	$zero,0x7a($sp)
/*    44fac:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*    44fb0:	27280008 */ 	addiu	$t0,$t9,0x8
/*    44fb4:	afa8007c */ 	sw	$t0,0x7c($sp)
/*    44fb8:	afb90040 */ 	sw	$t9,0x40($sp)
/*    44fbc:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    44fc0:	3c0100ff */ 	lui	$at,0xff
/*    44fc4:	3421ffff */ 	ori	$at,$at,0xffff
/*    44fc8:	8d2a0024 */ 	lw	$t2,0x24($t1)
/*    44fcc:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    44fd0:	01415824 */ 	and	$t3,$t2,$at
/*    44fd4:	3c010b00 */ 	lui	$at,0xb00
/*    44fd8:	01616025 */ 	or	$t4,$t3,$at
/*    44fdc:	adac0000 */ 	sw	$t4,0x0($t5)
/*    44fe0:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    44fe4:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    44fe8:	3c011fff */ 	lui	$at,0x1fff
/*    44fec:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    44ff0:	3421ffff */ 	ori	$at,$at,0xffff
/*    44ff4:	8df80010 */ 	lw	$t8,0x10($t7)
/*    44ff8:	27190008 */ 	addiu	$t9,$t8,0x8
/*    44ffc:	03214024 */ 	and	$t0,$t9,$at
/*    45000:	ad280004 */ 	sw	$t0,0x4($t1)
/*    45004:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    45008:	8fac0088 */ 	lw	$t4,0x88($sp)
/*    4500c:	8d4b0030 */ 	lw	$t3,0x30($t2)
/*    45010:	8d4e0018 */ 	lw	$t6,0x18($t2)
/*    45014:	016c6821 */ 	addu	$t5,$t3,$t4
/*    45018:	01cd802b */ 	sltu	$s0,$t6,$t5
/*    4501c:	12000003 */ 	beqz	$s0,.L0004502c
/*    45020:	00000000 */ 	nop
/*    45024:	8d50001c */ 	lw	$s0,0x1c($t2)
/*    45028:	0010802b */ 	sltu	$s0,$zero,$s0
.L0004502c:
/*    4502c:	afb00048 */ 	sw	$s0,0x48($sp)
/*    45030:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    45034:	11e00007 */ 	beqz	$t7,.L00045054
/*    45038:	00000000 */ 	nop
/*    4503c:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    45040:	8f190018 */ 	lw	$t9,0x18($t8)
/*    45044:	8f080030 */ 	lw	$t0,0x30($t8)
/*    45048:	03284823 */ 	subu	$t1,$t9,$t0
/*    4504c:	10000003 */ 	b	.L0004505c
/*    45050:	afa9005c */ 	sw	$t1,0x5c($sp)
.L00045054:
/*    45054:	8fab0088 */ 	lw	$t3,0x88($sp)
/*    45058:	afab005c */ 	sw	$t3,0x5c($sp)
.L0004505c:
/*    4505c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    45060:	8d8d0034 */ 	lw	$t5,0x34($t4)
/*    45064:	11a00007 */ 	beqz	$t5,.L00045084
/*    45068:	00000000 */ 	nop
/*    4506c:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    45070:	240f0010 */ 	addiu	$t7,$zero,0x10
/*    45074:	8dca0034 */ 	lw	$t2,0x34($t6)
/*    45078:	01eac023 */ 	subu	$t8,$t7,$t2
/*    4507c:	10000002 */ 	b	.L00045088
/*    45080:	afb80054 */ 	sw	$t8,0x54($sp)
.L00045084:
/*    45084:	afa00054 */ 	sw	$zero,0x54($sp)
.L00045088:
/*    45088:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    4508c:	8fa80054 */ 	lw	$t0,0x54($sp)
/*    45090:	03284823 */ 	subu	$t1,$t9,$t0
/*    45094:	afa90074 */ 	sw	$t1,0x74($sp)
/*    45098:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    4509c:	05610002 */ 	bgez	$t3,.L000450a8
/*    450a0:	00000000 */ 	nop
/*    450a4:	afa00074 */ 	sw	$zero,0x74($sp)
.L000450a8:
/*    450a8:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    450ac:	258d000f */ 	addiu	$t5,$t4,0xf
/*    450b0:	000d7103 */ 	sra	$t6,$t5,0x4
/*    450b4:	afae0070 */ 	sw	$t6,0x70($sp)
/*    450b8:	8faf0070 */ 	lw	$t7,0x70($sp)
/*    450bc:	000f50c0 */ 	sll	$t2,$t7,0x3
/*    450c0:	014f5021 */ 	addu	$t2,$t2,$t7
/*    450c4:	afaa006c */ 	sw	$t2,0x6c($sp)
/*    450c8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    450cc:	130000b6 */ 	beqz	$t8,.L000453a8
/*    450d0:	00000000 */ 	nop
/*    450d4:	8fa80084 */ 	lw	$t0,0x84($sp)
/*    450d8:	87ab007a */ 	lh	$t3,0x7a($sp)
/*    450dc:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    450e0:	85090000 */ 	lh	$t1,0x0($t0)
/*    450e4:	afab0014 */ 	sw	$t3,0x14($sp)
/*    450e8:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*    450ec:	afa90010 */ 	sw	$t1,0x10($sp)
/*    450f0:	8f2c0038 */ 	lw	$t4,0x38($t9)
/*    450f4:	8fa60074 */ 	lw	$a2,0x74($sp)
/*    450f8:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*    450fc:	03202825 */ 	or	$a1,$t9,$zero
/*    45100:	0c01163e */ 	jal	_decodeChunk
/*    45104:	afac0018 */ 	sw	$t4,0x18($sp)
/*    45108:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    4510c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    45110:	8dae0034 */ 	lw	$t6,0x34($t5)
/*    45114:	11c00009 */ 	beqz	$t6,.L0004513c
/*    45118:	00000000 */ 	nop
/*    4511c:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    45120:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    45124:	8f080034 */ 	lw	$t0,0x34($t8)
/*    45128:	85ea0000 */ 	lh	$t2,0x0($t7)
/*    4512c:	00084840 */ 	sll	$t1,$t0,0x1
/*    45130:	01495821 */ 	addu	$t3,$t2,$t1
/*    45134:	10000005 */ 	b	.L0004514c
/*    45138:	a5eb0000 */ 	sh	$t3,0x0($t7)
.L0004513c:
/*    4513c:	8fb90084 */ 	lw	$t9,0x84($sp)
/*    45140:	872c0000 */ 	lh	$t4,0x0($t9)
/*    45144:	258d0020 */ 	addiu	$t5,$t4,0x20
/*    45148:	a72d0000 */ 	sh	$t5,0x0($t9)
.L0004514c:
/*    4514c:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    45150:	8dd80014 */ 	lw	$t8,0x14($t6)
/*    45154:	3308000f */ 	andi	$t0,$t8,0xf
/*    45158:	adc80034 */ 	sw	$t0,0x34($t6)
/*    4515c:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    45160:	8d490020 */ 	lw	$t1,0x20($t2)
/*    45164:	8d4f0014 */ 	lw	$t7,0x14($t2)
/*    45168:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    4516c:	000f6102 */ 	srl	$t4,$t7,0x4
/*    45170:	000c68c0 */ 	sll	$t5,$t4,0x3
/*    45174:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    45178:	016dc821 */ 	addu	$t9,$t3,$t5
/*    4517c:	27380009 */ 	addiu	$t8,$t9,0x9
/*    45180:	ad58003c */ 	sw	$t8,0x3c($t2)
/*    45184:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    45188:	8d0e0014 */ 	lw	$t6,0x14($t0)
/*    4518c:	ad0e0030 */ 	sw	$t6,0x30($t0)
/*    45190:	8fa90084 */ 	lw	$t1,0x84($sp)
/*    45194:	852f0000 */ 	lh	$t7,0x0($t1)
/*    45198:	afaf0050 */ 	sw	$t7,0x50($sp)
/*    4519c:	8fac0088 */ 	lw	$t4,0x88($sp)
/*    451a0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    451a4:	016c082a */ 	slt	$at,$t3,$t4
/*    451a8:	1020006b */ 	beqz	$at,.L00045358
/*    451ac:	00000000 */ 	nop
.L000451b0:
/*    451b0:	8fad0088 */ 	lw	$t5,0x88($sp)
/*    451b4:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    451b8:	01b9c023 */ 	subu	$t8,$t5,$t9
/*    451bc:	afb80088 */ 	sw	$t8,0x88($sp)
/*    451c0:	8faa0070 */ 	lw	$t2,0x70($sp)
/*    451c4:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    451c8:	2401ffe0 */ 	addiu	$at,$zero,-32
/*    451cc:	254e0001 */ 	addiu	$t6,$t2,0x1
/*    451d0:	000e4140 */ 	sll	$t0,$t6,0x5
/*    451d4:	01097821 */ 	addu	$t7,$t0,$t1
/*    451d8:	25ec0010 */ 	addiu	$t4,$t7,0x10
/*    451dc:	01815824 */ 	and	$t3,$t4,$at
/*    451e0:	afab0058 */ 	sw	$t3,0x58($sp)
/*    451e4:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    451e8:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    451ec:	0019c040 */ 	sll	$t8,$t9,0x1
/*    451f0:	01b85021 */ 	addu	$t2,$t5,$t8
/*    451f4:	afaa0050 */ 	sw	$t2,0x50($sp)
/*    451f8:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    451fc:	2401ffff */ 	addiu	$at,$zero,-1
/*    45200:	8dc8001c */ 	lw	$t0,0x1c($t6)
/*    45204:	11010007 */ 	beq	$t0,$at,.L00045224
/*    45208:	00000000 */ 	nop
/*    4520c:	11000005 */ 	beqz	$t0,.L00045224
/*    45210:	00000000 */ 	nop
/*    45214:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    45218:	8d2f001c */ 	lw	$t7,0x1c($t1)
/*    4521c:	25ecffff */ 	addiu	$t4,$t7,-1
/*    45220:	ad2c001c */ 	sw	$t4,0x1c($t1)
.L00045224:
/*    45224:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    45228:	8fab0088 */ 	lw	$t3,0x88($sp)
/*    4522c:	8f2d0018 */ 	lw	$t5,0x18($t9)
/*    45230:	8f380014 */ 	lw	$t8,0x14($t9)
/*    45234:	01b85023 */ 	subu	$t2,$t5,$t8
/*    45238:	016a082b */ 	sltu	$at,$t3,$t2
/*    4523c:	10200003 */ 	beqz	$at,.L0004524c
/*    45240:	00000000 */ 	nop
/*    45244:	10000006 */ 	b	.L00045260
/*    45248:	afab005c */ 	sw	$t3,0x5c($sp)
.L0004524c:
/*    4524c:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    45250:	8dc80018 */ 	lw	$t0,0x18($t6)
/*    45254:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    45258:	010f6023 */ 	subu	$t4,$t0,$t7
/*    4525c:	afac005c */ 	sw	$t4,0x5c($sp)
.L00045260:
/*    45260:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    45264:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    45268:	8f2d0034 */ 	lw	$t5,0x34($t9)
/*    4526c:	012dc021 */ 	addu	$t8,$t1,$t5
/*    45270:	270afff0 */ 	addiu	$t2,$t8,-16
/*    45274:	afaa0074 */ 	sw	$t2,0x74($sp)
/*    45278:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    4527c:	05610002 */ 	bgez	$t3,.L00045288
/*    45280:	00000000 */ 	nop
/*    45284:	afa00074 */ 	sw	$zero,0x74($sp)
.L00045288:
/*    45288:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    4528c:	25c8000f */ 	addiu	$t0,$t6,0xf
/*    45290:	00087903 */ 	sra	$t7,$t0,0x4
/*    45294:	afaf0070 */ 	sw	$t7,0x70($sp)
/*    45298:	8fac0070 */ 	lw	$t4,0x70($sp)
/*    4529c:	000cc8c0 */ 	sll	$t9,$t4,0x3
/*    452a0:	032cc821 */ 	addu	$t9,$t9,$t4
/*    452a4:	afb9006c */ 	sw	$t9,0x6c($sp)
/*    452a8:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    452ac:	87b8007a */ 	lh	$t8,0x7a($sp)
/*    452b0:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    452b4:	afad0010 */ 	sw	$t5,0x10($sp)
/*    452b8:	afb80014 */ 	sw	$t8,0x14($sp)
/*    452bc:	8d2a0038 */ 	lw	$t2,0x38($t1)
/*    452c0:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*    452c4:	8fa60074 */ 	lw	$a2,0x74($sp)
/*    452c8:	354b0002 */ 	ori	$t3,$t2,0x2
/*    452cc:	afab0018 */ 	sw	$t3,0x18($sp)
/*    452d0:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*    452d4:	0c01163e */ 	jal	_decodeChunk
/*    452d8:	01202825 */ 	or	$a1,$t1,$zero
/*    452dc:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    452e0:	8fae007c */ 	lw	$t6,0x7c($sp)
/*    452e4:	25c80008 */ 	addiu	$t0,$t6,0x8
/*    452e8:	afa8007c */ 	sw	$t0,0x7c($sp)
/*    452ec:	afae003c */ 	sw	$t6,0x3c($sp)
/*    452f0:	8faf0044 */ 	lw	$t7,0x44($sp)
/*    452f4:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    452f8:	3c0100ff */ 	lui	$at,0xff
/*    452fc:	8dec0034 */ 	lw	$t4,0x34($t7)
/*    45300:	3421ffff */ 	ori	$at,$at,0xffff
/*    45304:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    45308:	000cc840 */ 	sll	$t9,$t4,0x1
/*    4530c:	032dc021 */ 	addu	$t8,$t9,$t5
/*    45310:	03014824 */ 	and	$t1,$t8,$at
/*    45314:	3c010a00 */ 	lui	$at,0xa00
/*    45318:	01215025 */ 	or	$t2,$t1,$at
/*    4531c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    45320:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    45324:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    45328:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    4532c:	31c8ffff */ 	andi	$t0,$t6,0xffff
/*    45330:	000cc840 */ 	sll	$t9,$t4,0x1
/*    45334:	332dffff */ 	andi	$t5,$t9,0xffff
/*    45338:	00087c00 */ 	sll	$t7,$t0,0x10
/*    4533c:	01edc025 */ 	or	$t8,$t7,$t5
/*    45340:	ad380004 */ 	sw	$t8,0x4($t1)
/*    45344:	8faa0088 */ 	lw	$t2,0x88($sp)
/*    45348:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    4534c:	016a082a */ 	slt	$at,$t3,$t2
/*    45350:	1420ff97 */ 	bnez	$at,.L000451b0
/*    45354:	00000000 */ 	nop
.L00045358:
/*    45358:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    4535c:	8fac0088 */ 	lw	$t4,0x88($sp)
/*    45360:	8dc80034 */ 	lw	$t0,0x34($t6)
/*    45364:	010cc821 */ 	addu	$t9,$t0,$t4
/*    45368:	332f000f */ 	andi	$t7,$t9,0xf
/*    4536c:	adcf0034 */ 	sw	$t7,0x34($t6)
/*    45370:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    45374:	8fa90088 */ 	lw	$t1,0x88($sp)
/*    45378:	8db80030 */ 	lw	$t8,0x30($t5)
/*    4537c:	03095021 */ 	addu	$t2,$t8,$t1
/*    45380:	adaa0030 */ 	sw	$t2,0x30($t5)
/*    45384:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    45388:	8fac0070 */ 	lw	$t4,0x70($sp)
/*    4538c:	8d68003c */ 	lw	$t0,0x3c($t3)
/*    45390:	000cc8c0 */ 	sll	$t9,$t4,0x3
/*    45394:	032cc821 */ 	addu	$t9,$t9,$t4
/*    45398:	01197821 */ 	addu	$t7,$t0,$t9
/*    4539c:	ad6f003c */ 	sw	$t7,0x3c($t3)
/*    453a0:	10000094 */ 	b	.L000455f4
/*    453a4:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L000453a8:
/*    453a8:	8fae0070 */ 	lw	$t6,0x70($sp)
/*    453ac:	000ec100 */ 	sll	$t8,$t6,0x4
/*    453b0:	afb8005c */ 	sw	$t8,0x5c($sp)
/*    453b4:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    453b8:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    453bc:	8d280020 */ 	lw	$t0,0x20($t1)
/*    453c0:	8d2a003c */ 	lw	$t2,0x3c($t1)
/*    453c4:	8d190000 */ 	lw	$t9,0x0($t0)
/*    453c8:	8d0f0004 */ 	lw	$t7,0x4($t0)
/*    453cc:	014d6021 */ 	addu	$t4,$t2,$t5
/*    453d0:	032f5821 */ 	addu	$t3,$t9,$t7
/*    453d4:	018b7023 */ 	subu	$t6,$t4,$t3
/*    453d8:	afae0068 */ 	sw	$t6,0x68($sp)
/*    453dc:	8fb80068 */ 	lw	$t8,0x68($sp)
/*    453e0:	07010002 */ 	bgez	$t8,.L000453ec
/*    453e4:	00000000 */ 	nop
/*    453e8:	afa00068 */ 	sw	$zero,0x68($sp)
.L000453ec:
/*    453ec:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    453f0:	24010009 */ 	addiu	$at,$zero,0x9
/*    453f4:	0141001a */ 	div	$zero,$t2,$at
/*    453f8:	00006812 */ 	mflo	$t5
/*    453fc:	000d4900 */ 	sll	$t1,$t5,0x4
/*    45400:	afa90060 */ 	sw	$t1,0x60($sp)
/*    45404:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    45408:	8faf0054 */ 	lw	$t7,0x54($sp)
/*    4540c:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    45410:	032f6021 */ 	addu	$t4,$t9,$t7
/*    45414:	0188082a */ 	slt	$at,$t4,$t0
/*    45418:	10200005 */ 	beqz	$at,.L00045430
/*    4541c:	00000000 */ 	nop
/*    45420:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    45424:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    45428:	016ec021 */ 	addu	$t8,$t3,$t6
/*    4542c:	afb80060 */ 	sw	$t8,0x60($sp)
.L00045430:
/*    45430:	8faa006c */ 	lw	$t2,0x6c($sp)
/*    45434:	8fad0068 */ 	lw	$t5,0x68($sp)
/*    45438:	014d4823 */ 	subu	$t1,$t2,$t5
/*    4543c:	afa9006c */ 	sw	$t1,0x6c($sp)
/*    45440:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    45444:	8fac0088 */ 	lw	$t4,0x88($sp)
/*    45448:	332f000f */ 	andi	$t7,$t9,0xf
/*    4544c:	032f4023 */ 	subu	$t0,$t9,$t7
/*    45450:	010c082a */ 	slt	$at,$t0,$t4
/*    45454:	10200036 */ 	beqz	$at,.L00045530
/*    45458:	00000000 */ 	nop
/*    4545c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    45460:	afab004c */ 	sw	$t3,0x4c($sp)
/*    45464:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    45468:	87b9007a */ 	lh	$t9,0x7a($sp)
/*    4546c:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    45470:	85a90000 */ 	lh	$t1,0x0($t5)
/*    45474:	afb90014 */ 	sw	$t9,0x14($sp)
/*    45478:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    4547c:	afa90010 */ 	sw	$t1,0x10($sp)
/*    45480:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    45484:	8dcf0038 */ 	lw	$t7,0x38($t6)
/*    45488:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*    4548c:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*    45490:	01c02825 */ 	or	$a1,$t6,$zero
/*    45494:	030a3023 */ 	subu	$a2,$t8,$t2
/*    45498:	0c01163e */ 	jal	_decodeChunk
/*    4549c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    454a0:	afa2007c */ 	sw	$v0,0x7c($sp)
/*    454a4:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    454a8:	8d0c0034 */ 	lw	$t4,0x34($t0)
/*    454ac:	11800009 */ 	beqz	$t4,.L000454d4
/*    454b0:	00000000 */ 	nop
/*    454b4:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    454b8:	8fab0084 */ 	lw	$t3,0x84($sp)
/*    454bc:	8d4d0034 */ 	lw	$t5,0x34($t2)
/*    454c0:	85780000 */ 	lh	$t8,0x0($t3)
/*    454c4:	000d4840 */ 	sll	$t1,$t5,0x1
/*    454c8:	0309c821 */ 	addu	$t9,$t8,$t1
/*    454cc:	10000005 */ 	b	.L000454e4
/*    454d0:	a5790000 */ 	sh	$t9,0x0($t3)
.L000454d4:
/*    454d4:	8fae0084 */ 	lw	$t6,0x84($sp)
/*    454d8:	85cf0000 */ 	lh	$t7,0x0($t6)
/*    454dc:	25e80020 */ 	addiu	$t0,$t7,0x20
/*    454e0:	a5c80000 */ 	sh	$t0,0x0($t6)
.L000454e4:
/*    454e4:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    454e8:	8fad0088 */ 	lw	$t5,0x88($sp)
/*    454ec:	8d8a0034 */ 	lw	$t2,0x34($t4)
/*    454f0:	014dc021 */ 	addu	$t8,$t2,$t5
/*    454f4:	3309000f */ 	andi	$t1,$t8,0xf
/*    454f8:	ad890034 */ 	sw	$t1,0x34($t4)
/*    454fc:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    45500:	8faf0088 */ 	lw	$t7,0x88($sp)
/*    45504:	8f2b0030 */ 	lw	$t3,0x30($t9)
/*    45508:	016f4021 */ 	addu	$t0,$t3,$t7
/*    4550c:	af280030 */ 	sw	$t0,0x30($t9)
/*    45510:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    45514:	8fad0070 */ 	lw	$t5,0x70($sp)
/*    45518:	8dca003c */ 	lw	$t2,0x3c($t6)
/*    4551c:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*    45520:	030dc021 */ 	addu	$t8,$t8,$t5
/*    45524:	01584821 */ 	addu	$t1,$t2,$t8
/*    45528:	1000000a */ 	b	.L00045554
/*    4552c:	adc9003c */ 	sw	$t1,0x3c($t6)
.L00045530:
/*    45530:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    45534:	ad800034 */ 	sw	$zero,0x34($t4)
/*    45538:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    4553c:	8fa80070 */ 	lw	$t0,0x70($sp)
/*    45540:	8d6f003c */ 	lw	$t7,0x3c($t3)
/*    45544:	0008c8c0 */ 	sll	$t9,$t0,0x3
/*    45548:	0328c821 */ 	addu	$t9,$t9,$t0
/*    4554c:	01f96821 */ 	addu	$t5,$t7,$t9
/*    45550:	ad6d003c */ 	sw	$t5,0x3c($t3)
.L00045554:
/*    45554:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    45558:	11400022 */ 	beqz	$t2,.L000455e4
/*    4555c:	00000000 */ 	nop
/*    45560:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    45564:	af000034 */ 	sw	$zero,0x34($t8)
/*    45568:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    4556c:	11200009 */ 	beqz	$t1,.L00045594
/*    45570:	00000000 */ 	nop
/*    45574:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    45578:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    4557c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    45580:	01cc4021 */ 	addu	$t0,$t6,$t4
/*    45584:	010fc823 */ 	subu	$t9,$t0,$t7
/*    45588:	00196840 */ 	sll	$t5,$t9,0x1
/*    4558c:	10000002 */ 	b	.L00045598
/*    45590:	afad0064 */ 	sw	$t5,0x64($sp)
.L00045594:
/*    45594:	afa00064 */ 	sw	$zero,0x64($sp)
.L00045598:
/*    45598:	8fab007c */ 	lw	$t3,0x7c($sp)
/*    4559c:	256a0008 */ 	addiu	$t2,$t3,0x8
/*    455a0:	afaa007c */ 	sw	$t2,0x7c($sp)
/*    455a4:	afab0038 */ 	sw	$t3,0x38($sp)
/*    455a8:	8fb80084 */ 	lw	$t8,0x84($sp)
/*    455ac:	8fae0064 */ 	lw	$t6,0x64($sp)
/*    455b0:	3c0100ff */ 	lui	$at,0xff
/*    455b4:	87090000 */ 	lh	$t1,0x0($t8)
/*    455b8:	3421ffff */ 	ori	$at,$at,0xffff
/*    455bc:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    455c0:	012e6021 */ 	addu	$t4,$t1,$t6
/*    455c4:	01814024 */ 	and	$t0,$t4,$at
/*    455c8:	3c010200 */ 	lui	$at,0x200
/*    455cc:	01017825 */ 	or	$t7,$t0,$at
/*    455d0:	af2f0000 */ 	sw	$t7,0x0($t9)
/*    455d4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    455d8:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    455dc:	000d5840 */ 	sll	$t3,$t5,0x1
/*    455e0:	ad4b0004 */ 	sw	$t3,0x4($t2)
.L000455e4:
/*    455e4:	10000003 */ 	b	.L000455f4
/*    455e8:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*    455ec:	10000001 */ 	b	.L000455f4
/*    455f0:	00000000 */ 	nop
.L000455f4:
/*    455f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    455f8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*    455fc:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*    45600:	03e00008 */ 	jr	$ra
/*    45604:	00000000 */ 	nop
);

Acmd *_decodeChunk(Acmd *ptr, N_PVoice *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags);

// Mismatch: extra move instruction
//Acmd *n_alAdpcmPull(N_PVoice *filter, s16 *outp, s32 outCount, Acmd *p)
//{
//	Acmd        *ptr = p;
//	s16         inp;
//	s32         tsam;
//	s32         nframes;
//	s32         nbytes;
//	s32         overFlow;
//	s32         startZero;
//	s32         nOver;
//	s32         nSam;
//	s32         op;
//	s32         nLeft;
//	s32         bEnd;
//	s32         decoded = 0;
//	s32         looped = 0;
//
//	N_PVoice *f = filter;
//
//	if (outCount == 0)
//		return ptr;
//
//	inp = N_AL_DECODER_IN;
//
//	aLoadADPCM(ptr++, f->dc_bookSize,
//			K0_TO_PHYS(f->dc_table->waveInfo.adpcmWave.book->book));
//
//	looped = (outCount + f->dc_sample > f->dc_loop.end) && (f->dc_loop.count != 0);
//
//	if (looped)
//		nSam = f->dc_loop.end - f->dc_sample;
//	else
//		nSam = outCount;
//
//	if (f->dc_lastsam)
//		nLeft = ADPCMFSIZE - f->dc_lastsam;
//	else
//		nLeft = 0;
//	tsam = nSam - nLeft;
//	if (tsam<0) tsam = 0;
//
//	nframes = (tsam+ADPCMFSIZE-1)>>LFSAMPLES;
//	nbytes =  nframes*ADPCMFBYTES;
//
//	if (looped){
//		ptr = _decodeChunk(ptr, f, tsam, nbytes, *outp, inp, f->dc_first);
//
//		/*
//		 * Fix up output pointer, which will be used as the input pointer
//		 * by the following module.
//		 */
//		if (f->dc_lastsam)
//			*outp += (f->dc_lastsam<<1);
//		else
//			*outp += (ADPCMFSIZE<<1);
//
//		/*
//		 * Now fix up state info to reflect the loop start point
//		 */
//		f->dc_lastsam = f->dc_loop.start &0xf;
//		f->dc_memin = (s32) f->dc_table->base + ADPCMFBYTES *
//			((s32) (f->dc_loop.start>>LFSAMPLES) + 1);
//		f->dc_sample = f->dc_loop.start;
//
//		bEnd = *outp;
//		while (outCount > nSam){
//
//			outCount -= nSam;
//
//			/*
//			 * Put next one after the end of the last lot - on the
//			 * frame boundary (32 byte) after the end.
//			 */
//			op = (bEnd + ((nframes+1)<<(LFSAMPLES+1)) + 16) & ~0x1f;
//
//			/*
//			 * The actual end of data
//			 */
//			bEnd += (nSam<<1);
//
//			/*
//			 * -1 is loop forever - the loop count is not exact now
//			 * for small loops!
//			 */
//			if ((f->dc_loop.count != -1) && (f->dc_loop.count != 0))
//				f->dc_loop.count--;
//
//			/*
//			 * What's left to compute.
//			 */
//			nSam = MIN(outCount, f->dc_loop.end - f->dc_loop.start);
//			tsam = nSam - ADPCMFSIZE + f->dc_lastsam;
//			if (tsam<0) tsam = 0;
//			nframes = (tsam+ADPCMFSIZE-1)>>LFSAMPLES;
//			nbytes =  nframes*ADPCMFBYTES;
//			ptr = _decodeChunk(ptr, f, tsam, nbytes, op, inp, f->dc_first | A_LOOP);
//
//			/*
//			 * Merge the two sections in DMEM.
//			 */
//			aDMEMMove(ptr++, op+(f->dc_lastsam<<1), bEnd, nSam<<1);
//		}
//
//		f->dc_lastsam = (outCount + f->dc_lastsam) & 0xf;
//		f->dc_sample += outCount;
//		f->dc_memin += ADPCMFBYTES*nframes;
//
//		return ptr;
//	}
//
//	/*
//	 * The unlooped case, which is executed most of the time
//	 */
//
//	nSam = nframes<<LFSAMPLES;
//
//	/*
//	 * overFlow is the number of bytes past the end
//	 * of the bitstream I try to generate
//	 */
//	overFlow = f->dc_memin + nbytes - ((s32) f->dc_table->base + f->dc_table->len);
//	if (overFlow < 0)
//		overFlow = 0;
//	nOver = (overFlow/ADPCMFBYTES)<<LFSAMPLES;
//	if (nOver > nSam + nLeft)
//		nOver = nSam + nLeft;
//
//	nbytes -= overFlow;
//
//	if ((nOver - (nOver & 0xf))< outCount){
//		decoded = 1;
//		ptr = _decodeChunk(ptr, f, nSam - nOver, nbytes, *outp, inp, f->dc_first);
//
//		if (f->dc_lastsam)
//			*outp += (f->dc_lastsam<<1);
//		else
//			*outp += (ADPCMFSIZE<<1);
//
//		f->dc_lastsam = (outCount + f->dc_lastsam) & 0xf;
//		f->dc_sample += outCount;
//		f->dc_memin += ADPCMFBYTES*nframes;
//	} else {
//		f->dc_lastsam = 0;
//		f->dc_memin += ADPCMFBYTES*nframes;
//	}
//
//	/*
//	 * Put zeros in if necessary
//	 */
//	if (nOver){
//		f->dc_lastsam = 0;
//		if (decoded)
//			startZero = (nLeft + nSam - nOver)<<1;
//		else
//			startZero = 0;
//		aClearBuffer(ptr++, startZero + *outp, nOver<<1);
//	}
//
//	return ptr;
//}

s32 n_alLoadParam(N_PVoice *filter, s32 paramID, void *param)
{
	N_PVoice *a = filter;

	switch (paramID) {
	case (AL_FILTER_SET_WAVETABLE):
		a->dc_table = (ALWaveTable *) param;
		a->dc_memin = (s32) a->dc_table->base;
		a->dc_sample = 0;

		switch (a->dc_table->type) {
		case (AL_ADPCM_WAVE):
			a->dc_table->len = ADPCMFBYTES * ((s32) (a->dc_table->len/ADPCMFBYTES));

			a->dc_bookSize = 2*a->dc_table->waveInfo.adpcmWave.book->order*
				a->dc_table->waveInfo.adpcmWave.book->npredictors*ADPCMVSIZE;

			if (a->dc_table->waveInfo.adpcmWave.loop) {
				a->dc_loop.start = a->dc_table->waveInfo.adpcmWave.loop->start;
				a->dc_loop.end = a->dc_table->waveInfo.adpcmWave.loop->end;
				a->dc_loop.count = a->dc_table->waveInfo.adpcmWave.loop->count;

				bcopy(a->dc_table->waveInfo.adpcmWave.loop->state, a->dc_lstate, sizeof(ADPCM_STATE));
			} else {
				a->dc_loop.start = a->dc_loop.end = a->dc_loop.count = 0;
			}
			break;
		case (AL_RAW16_WAVE):
			if (a->dc_table->waveInfo.rawWave.loop) {
				a->dc_loop.start = a->dc_table->waveInfo.rawWave.loop->start;
				a->dc_loop.end = a->dc_table->waveInfo.rawWave.loop->end;
				a->dc_loop.count = a->dc_table->waveInfo.rawWave.loop->count;
			} else {
				a->dc_loop.start = a->dc_loop.end = a->dc_loop.count = 0;
			}
			break;
		default:
			break;
		}
		break;
	case (AL_FILTER_RESET):
		a->dc_lastsam = 0;
		a->dc_first   = 1;
		a->dc_sample = 0;

		/* sct 2/14/96 - Check table since it is initialized to null and */
		/* Get loop info according to table type. */
		if (a->dc_table) {
			a->dc_memin  = (s32) a->dc_table->base;

			if (a->dc_table->type == AL_ADPCM_WAVE) {
				if (a->dc_table->waveInfo.adpcmWave.loop) {
					a->dc_loop.count = a->dc_table->waveInfo.adpcmWave.loop->count;
				}
			} else if (a->dc_table->type == AL_RAW16_WAVE) {
				if (a->dc_table->waveInfo.rawWave.loop) {
					a->dc_loop.count = a->dc_table->waveInfo.rawWave.loop->count;
				}
			}
		}
		break;
	default:
		break;
	}

	return 0;
}

GLOBAL_ASM(
glabel _decodeChunk
/*    458f8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    458fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    45900:	afa40030 */ 	sw	$a0,0x30($sp)
/*    45904:	afa50034 */ 	sw	$a1,0x34($sp)
/*    45908:	afa60038 */ 	sw	$a2,0x38($sp)
/*    4590c:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    45910:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    45914:	19c00028 */ 	blez	$t6,.L000459b8
/*    45918:	00000000 */ 	nop
/*    4591c:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    45920:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    45924:	8df90028 */ 	lw	$t9,0x28($t7)
/*    45928:	8de4003c */ 	lw	$a0,0x3c($t7)
/*    4592c:	8de6002c */ 	lw	$a2,0x2c($t7)
/*    45930:	0320f809 */ 	jalr	$t9
/*    45934:	00000000 */ 	nop
/*    45938:	afa20028 */ 	sw	$v0,0x28($sp)
/*    4593c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    45940:	33080007 */ 	andi	$t0,$t8,0x7
/*    45944:	afa8002c */ 	sw	$t0,0x2c($sp)
/*    45948:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    4594c:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    45950:	012a5821 */ 	addu	$t3,$t1,$t2
/*    45954:	afab003c */ 	sw	$t3,0x3c($sp)
/*    45958:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    4595c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    45960:	afad0030 */ 	sw	$t5,0x30($sp)
/*    45964:	afac0024 */ 	sw	$t4,0x24($sp)
/*    45968:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    4596c:	87ab0046 */ 	lh	$t3,0x46($sp)
/*    45970:	3c010400 */ 	lui	$at,0x400
/*    45974:	31cf0007 */ 	andi	$t7,$t6,0x7
/*    45978:	01cfc823 */ 	subu	$t9,$t6,$t7
/*    4597c:	27380008 */ 	addiu	$t8,$t9,0x8
/*    45980:	33080fff */ 	andi	$t0,$t8,0xfff
/*    45984:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    45988:	00084b00 */ 	sll	$t1,$t0,0xc
/*    4598c:	01215025 */ 	or	$t2,$t1,$at
/*    45990:	316c0fff */ 	andi	$t4,$t3,0xfff
/*    45994:	014c6825 */ 	or	$t5,$t2,$t4
/*    45998:	adcd0000 */ 	sw	$t5,0x0($t6)
/*    4599c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    459a0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    459a4:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    459a8:	01f9c023 */ 	subu	$t8,$t7,$t9
/*    459ac:	ad180004 */ 	sw	$t8,0x4($t0)
/*    459b0:	10000002 */ 	b	.L000459bc
/*    459b4:	00000000 */ 	nop
.L000459b8:
/*    459b8:	afa0002c */ 	sw	$zero,0x2c($sp)
.L000459bc:
/*    459bc:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    459c0:	312b0002 */ 	andi	$t3,$t1,0x2
/*    459c4:	1160000f */ 	beqz	$t3,.L00045a04
/*    459c8:	00000000 */ 	nop
/*    459cc:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    459d0:	254c0008 */ 	addiu	$t4,$t2,0x8
/*    459d4:	afac0030 */ 	sw	$t4,0x30($sp)
/*    459d8:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    459dc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    459e0:	3c0d0f00 */ 	lui	$t5,0xf00
/*    459e4:	adcd0000 */ 	sw	$t5,0x0($t6)
/*    459e8:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    459ec:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    459f0:	3c011fff */ 	lui	$at,0x1fff
/*    459f4:	8df90010 */ 	lw	$t9,0x10($t7)
/*    459f8:	3421ffff */ 	ori	$at,$at,0xffff
/*    459fc:	0321c024 */ 	and	$t8,$t9,$at
/*    45a00:	ad180004 */ 	sw	$t8,0x4($t0)
.L00045a04:
/*    45a04:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    45a08:	252b0008 */ 	addiu	$t3,$t1,0x8
/*    45a0c:	afab0030 */ 	sw	$t3,0x30($sp)
/*    45a10:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    45a14:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    45a18:	3c011fff */ 	lui	$at,0x1fff
/*    45a1c:	3421ffff */ 	ori	$at,$at,0xffff
/*    45a20:	8d4c000c */ 	lw	$t4,0xc($t2)
/*    45a24:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    45a28:	01816824 */ 	and	$t5,$t4,$at
/*    45a2c:	3c0100ff */ 	lui	$at,0xff
/*    45a30:	3421ffff */ 	ori	$at,$at,0xffff
/*    45a34:	01a17024 */ 	and	$t6,$t5,$at
/*    45a38:	3c010100 */ 	lui	$at,0x100
/*    45a3c:	01c17825 */ 	or	$t7,$t6,$at
/*    45a40:	af2f0000 */ 	sw	$t7,0x0($t9)
/*    45a44:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    45a48:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    45a4c:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    45a50:	000b5040 */ 	sll	$t2,$t3,0x1
/*    45a54:	314c0fff */ 	andi	$t4,$t2,0xfff
/*    45a58:	3308000f */ 	andi	$t0,$t8,0xf
/*    45a5c:	87ab0042 */ 	lh	$t3,0x42($sp)
/*    45a60:	00084f00 */ 	sll	$t1,$t0,0x1c
/*    45a64:	000c6c00 */ 	sll	$t5,$t4,0x10
/*    45a68:	012d7025 */ 	or	$t6,$t1,$t5
/*    45a6c:	31f9000f */ 	andi	$t9,$t7,0xf
/*    45a70:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    45a74:	0019c300 */ 	sll	$t8,$t9,0xc
/*    45a78:	01d84025 */ 	or	$t0,$t6,$t8
/*    45a7c:	316a0fff */ 	andi	$t2,$t3,0xfff
/*    45a80:	010a6025 */ 	or	$t4,$t0,$t2
/*    45a84:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*    45a88:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    45a8c:	ada00038 */ 	sw	$zero,0x38($t5)
/*    45a90:	10000003 */ 	b	.L00045aa0
/*    45a94:	8fa20030 */ 	lw	$v0,0x30($sp)
/*    45a98:	10000001 */ 	b	.L00045aa0
/*    45a9c:	00000000 */ 	nop
.L00045aa0:
/*    45aa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    45aa4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    45aa8:	03e00008 */ 	jr	$ra
/*    45aac:	00000000 */ 	nop
);
