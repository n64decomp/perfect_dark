#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "types.h"

#define GETBYTE()   (inbuf[inptr++])
#define NEXTBYTE()  (u8)GETBYTE()
#define NEEDBITS(n) {while(k<(n)){b|=((u32)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

struct huft {
	u8 e;                /* number of extra bits or operation */
	u8 b;                /* number of bits in this code or subcode */
	union {
		u16 n;            /* literal, length base, or distance base */
		struct huft *t;   /* pointer to next level of table */
	} v;
};

u8 *inbuf = 0;
u8 *outbuf = 0;

u32 inptr = 0;
u32 wp = 0;
u8 *var702012e0 = 0;

u8 border[] = { /* Order of the bit length code lengths */
        16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

/* Tables for deflate from PKZIP's appnote.txt. */
u16 cplens[] = { /* Copy lengths for literal codes 257..285 */
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};

        /* actually lengths - 2; also see note #13 above about 258 */
u8 cplext[] = { /* Extra bits for literal codes 257..285 */
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99}; /* 128==invalid */

u16 cpdist[] = { /* Copy offsets for distance codes 0..29 */
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};

u8 cpdext[] = { /* Extra bits for distance codes */
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

u32 bb = 0;
u32 bk = 0;

/* And'ing with mask[n] masks the lower n bits */
u16 mask_bits[] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};

u32 lbits = 9;
u32 dbits = 6;
u32 hufts = 0;

GLOBAL_ASM(
glabel huft_build
.L70200000:
/* 70200000:	27bdfa18 */ 	addiu	$sp,$sp,-1512
/* 70200004:	afb20010 */ 	sw	$s2,0x10($sp)
/* 70200008:	afb00008 */ 	sw	$s0,0x8($sp)
/* 7020000c:	00808025 */ 	move	$s0,$a0
/* 70200010:	00a09025 */ 	move	$s2,$a1
/* 70200014:	afbf002c */ 	sw	$ra,0x2c($sp)
/* 70200018:	afbe0028 */ 	sw	$s8,0x28($sp)
/* 7020001c:	afb70024 */ 	sw	$s7,0x24($sp)
/* 70200020:	afb60020 */ 	sw	$s6,0x20($sp)
/* 70200024:	afb5001c */ 	sw	$s5,0x1c($sp)
/* 70200028:	afb40018 */ 	sw	$s4,0x18($sp)
/* 7020002c:	afb30014 */ 	sw	$s3,0x14($sp)
/* 70200030:	afb1000c */ 	sw	$s1,0xc($sp)
/* 70200034:	afa605f0 */ 	sw	$a2,0x5f0($sp)
/* 70200038:	afa705f4 */ 	sw	$a3,0x5f4($sp)
/* 7020003c:	27a305a0 */ 	addiu	$v1,$sp,0x5a0
/* 70200040:	27a205e4 */ 	addiu	$v0,$sp,0x5e4
.L70200044:
/* 70200044:	24630004 */ 	addiu	$v1,$v1,0x4
/* 70200048:	1462fffe */ 	bne	$v1,$v0,.L70200044
/* 7020004c:	ac60fffc */ 	sw	$zero,-0x4($v1)
/* 70200050:	0200f825 */ 	move	$ra,$s0
/* 70200054:	02406825 */ 	move	$t5,$s2
/* 70200058:	27a405a0 */ 	addiu	$a0,$sp,0x5a0
.L7020005c:
/* 7020005c:	8fee0000 */ 	lw	$t6,0x0($ra)
/* 70200060:	25adffff */ 	addiu	$t5,$t5,-1
/* 70200064:	27ff0004 */ 	addiu	$ra,$ra,0x4
/* 70200068:	000e7880 */ 	sll	$t7,$t6,0x2
/* 7020006c:	008f1021 */ 	addu	$v0,$a0,$t7
/* 70200070:	8c580000 */ 	lw	$t8,0x0($v0)
/* 70200074:	27190001 */ 	addiu	$t9,$t8,0x1
/* 70200078:	15a0fff8 */ 	bnez	$t5,.L7020005c
/* 7020007c:	ac590000 */ 	sw	$t9,0x0($v0)
/* 70200080:	8fae05a0 */ 	lw	$t6,0x5a0($sp)
/* 70200084:	8fa50600 */ 	lw	$a1,0x600($sp)
/* 70200088:	24070001 */ 	li	$a3,0x1
/* 7020008c:	164e0007 */ 	bne	$s2,$t6,.L702000ac
/* 70200090:	27a605a4 */ 	addiu	$a2,$sp,0x5a4
/* 70200094:	8fb605fc */ 	lw	$s6,0x5fc($sp)
/* 70200098:	8fa50600 */ 	lw	$a1,0x600($sp)
/* 7020009c:	00001025 */ 	move	$v0,$zero
/* 702000a0:	aec00000 */ 	sw	$zero,0x0($s6)
/* 702000a4:	10000121 */ 	b	.L7020052c
/* 702000a8:	aca00000 */ 	sw	$zero,0x0($a1)
.L702000ac:
/* 702000ac:	8cb10000 */ 	lw	$s1,0x0($a1)
/* 702000b0:	24020011 */ 	li	$v0,0x11
.L702000b4:
/* 702000b4:	8ccf0000 */ 	lw	$t7,0x0($a2)
/* 702000b8:	55e00005 */ 	bnezl	$t7,.L702000d0
/* 702000bc:	0227082b */ 	sltu	$at,$s1,$a3
/* 702000c0:	24e70001 */ 	addiu	$a3,$a3,0x1
/* 702000c4:	14e2fffb */ 	bne	$a3,$v0,.L702000b4
/* 702000c8:	24c60004 */ 	addiu	$a2,$a2,0x4
/* 702000cc:	0227082b */ 	sltu	$at,$s1,$a3
.L702000d0:
/* 702000d0:	10200002 */ 	beqz	$at,.L702000dc
/* 702000d4:	00e09825 */ 	move	$s3,$a3
/* 702000d8:	00e08825 */ 	move	$s1,$a3
.L702000dc:
/* 702000dc:	240d0010 */ 	li	$t5,0x10
/* 702000e0:	27a205e0 */ 	addiu	$v0,$sp,0x5e0
.L702000e4:
/* 702000e4:	8c580000 */ 	lw	$t8,0x0($v0)
/* 702000e8:	57000005 */ 	bnezl	$t8,.L70200100
/* 702000ec:	01b1082b */ 	sltu	$at,$t5,$s1
/* 702000f0:	25adffff */ 	addiu	$t5,$t5,-1
/* 702000f4:	15a0fffb */ 	bnez	$t5,.L702000e4
/* 702000f8:	2442fffc */ 	addiu	$v0,$v0,-4
/* 702000fc:	01b1082b */ 	sltu	$at,$t5,$s1
.L70200100:
/* 70200100:	10200002 */ 	beqz	$at,.L7020010c
/* 70200104:	afad0598 */ 	sw	$t5,0x598($sp)
/* 70200108:	01a08825 */ 	move	$s1,$t5
.L7020010c:
/* 7020010c:	24190001 */ 	li	$t9,0x1
/* 70200110:	00ed082b */ 	sltu	$at,$a3,$t5
/* 70200114:	acb10000 */ 	sw	$s1,0x0($a1)
/* 70200118:	1020000b */ 	beqz	$at,.L70200148
/* 7020011c:	00f91804 */ 	sllv	$v1,$t9,$a3
/* 70200120:	000d7080 */ 	sll	$t6,$t5,0x2
/* 70200124:	27af05a0 */ 	addiu	$t7,$sp,0x5a0
/* 70200128:	01cf2821 */ 	addu	$a1,$t6,$t7
.L7020012c:
/* 7020012c:	8cd80000 */ 	lw	$t8,0x0($a2)
/* 70200130:	24c60004 */ 	addiu	$a2,$a2,0x4
/* 70200134:	00c5082b */ 	sltu	$at,$a2,$a1
/* 70200138:	00781823 */ 	subu	$v1,$v1,$t8
/* 7020013c:	0003c840 */ 	sll	$t9,$v1,0x1
/* 70200140:	1420fffa */ 	bnez	$at,.L7020012c
/* 70200144:	03201825 */ 	move	$v1,$t9
.L70200148:
/* 70200148:	8c460000 */ 	lw	$a2,0x0($v0)
/* 7020014c:	2442fffc */ 	addiu	$v0,$v0,-4
/* 70200150:	27af05a0 */ 	addiu	$t7,$sp,0x5a0
/* 70200154:	00661823 */ 	subu	$v1,$v1,$a2
/* 70200158:	00c37021 */ 	addu	$t6,$a2,$v1
/* 7020015c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/* 70200160:	afa00070 */ 	sw	$zero,0x70($sp)
/* 70200164:	00003825 */ 	move	$a3,$zero
/* 70200168:	27bf05a4 */ 	addiu	$ra,$sp,0x5a4
/* 7020016c:	104f0009 */ 	beq	$v0,$t7,.L70200194
/* 70200170:	27a50074 */ 	addiu	$a1,$sp,0x74
/* 70200174:	27a605a0 */ 	addiu	$a2,$sp,0x5a0
.L70200178:
/* 70200178:	8ff80000 */ 	lw	$t8,0x0($ra)
/* 7020017c:	2442fffc */ 	addiu	$v0,$v0,-4
/* 70200180:	24a50004 */ 	addiu	$a1,$a1,0x4
/* 70200184:	00f83821 */ 	addu	$a3,$a3,$t8
/* 70200188:	aca7fffc */ 	sw	$a3,-0x4($a1)
/* 7020018c:	1446fffa */ 	bne	$v0,$a2,.L70200178
/* 70200190:	27ff0004 */ 	addiu	$ra,$ra,0x4
.L70200194:
/* 70200194:	0200f825 */ 	move	$ra,$s0
/* 70200198:	00006825 */ 	move	$t5,$zero
/* 7020019c:	afb205ec */ 	sw	$s2,0x5ec($sp)
/* 702001a0:	02404825 */ 	move	$t1,$s2
/* 702001a4:	27a8006c */ 	addiu	$t0,$sp,0x6c
/* 702001a8:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/* 702001ac:	8fe70000 */ 	lw	$a3,0x0($ra)
.L702001b0:
/* 702001b0:	27ff0004 */ 	addiu	$ra,$ra,0x4
/* 702001b4:	10e00008 */ 	beqz	$a3,.L702001d8
/* 702001b8:	0007c880 */ 	sll	$t9,$a3,0x2
/* 702001bc:	01191021 */ 	addu	$v0,$t0,$t9
/* 702001c0:	8c450000 */ 	lw	$a1,0x0($v0)
/* 702001c4:	00057080 */ 	sll	$t6,$a1,0x2
/* 702001c8:	00ce7821 */ 	addu	$t7,$a2,$t6
/* 702001cc:	aded0000 */ 	sw	$t5,0x0($t7)
/* 702001d0:	24b80001 */ 	addiu	$t8,$a1,0x1
/* 702001d4:	ac580000 */ 	sw	$t8,0x0($v0)
.L702001d8:
/* 702001d8:	25ad0001 */ 	addiu	$t5,$t5,0x1
/* 702001dc:	01a9082b */ 	sltu	$at,$t5,$t1
/* 702001e0:	5420fff3 */ 	bnezl	$at,.L702001b0
/* 702001e4:	8fe70000 */ 	lw	$a3,0x0($ra)
/* 702001e8:	8fb90598 */ 	lw	$t9,0x598($sp)
/* 702001ec:	afa30064 */ 	sw	$v1,0x64($sp)
/* 702001f0:	00006825 */ 	move	$t5,$zero
/* 702001f4:	0333082a */ 	slt	$at,$t9,$s3
/* 702001f8:	afa0006c */ 	sw	$zero,0x6c($sp)
/* 702001fc:	00c0f825 */ 	move	$ra,$a2
/* 70200200:	240cffff */ 	li	$t4,-1
/* 70200204:	00115023 */ 	negu	$t2,$s1
/* 70200208:	afa00534 */ 	sw	$zero,0x534($sp)
/* 7020020c:	00002825 */ 	move	$a1,$zero
/* 70200210:	142000bf */ 	bnez	$at,.L70200510
/* 70200214:	00004025 */ 	move	$t0,$zero
/* 70200218:	00137080 */ 	sll	$t6,$s3,0x2
/* 7020021c:	27af05a0 */ 	addiu	$t7,$sp,0x5a0
/* 70200220:	01cfc021 */ 	addu	$t8,$t6,$t7
/* 70200224:	3c1e7020 */ 	lui	$s8,%hi(var702012e0)
/* 70200228:	3c147020 */ 	lui	$s4,%hi(hufts)
/* 7020022c:	269413e8 */ 	addiu	$s4,$s4,%lo(hufts)
/* 70200230:	27de12e0 */ 	addiu	$s8,$s8,%lo(var702012e0)
/* 70200234:	afb80050 */ 	sw	$t8,0x50($sp)
/* 70200238:	8fb605fc */ 	lw	$s6,0x5fc($sp)
/* 7020023c:	27b50574 */ 	addiu	$s5,$sp,0x574
.L70200240:
/* 70200240:	8fb90050 */ 	lw	$t9,0x50($sp)
/* 70200244:	8faf05ec */ 	lw	$t7,0x5ec($sp)
/* 70200248:	000c8080 */ 	sll	$s0,$t4,0x2
/* 7020024c:	8f370000 */ 	lw	$s7,0x0($t9)
/* 70200250:	27ae006c */ 	addiu	$t6,$sp,0x6c
/* 70200254:	000fc080 */ 	sll	$t8,$t7,0x2
/* 70200258:	02e03025 */ 	move	$a2,$s7
/* 7020025c:	12e000a4 */ 	beqz	$s7,.L702004f0
/* 70200260:	26f7ffff */ 	addiu	$s7,$s7,-1
/* 70200264:	020e5821 */ 	addu	$t3,$s0,$t6
/* 70200268:	27b900b4 */ 	addiu	$t9,$sp,0xb4
/* 7020026c:	03197021 */ 	addu	$t6,$t8,$t9
/* 70200270:	24180001 */ 	li	$t8,0x1
/* 70200274:	266f001f */ 	addiu	$t7,$s3,0x1f
/* 70200278:	01f8c804 */ 	sllv	$t9,$t8,$t7
/* 7020027c:	afb90034 */ 	sw	$t9,0x34($sp)
/* 70200280:	afae0038 */ 	sw	$t6,0x38($sp)
.L70200284:
/* 70200284:	01511821 */ 	addu	$v1,$t2,$s1
/* 70200288:	0073082a */ 	slt	$at,$v1,$s3
/* 7020028c:	10200047 */ 	beqz	$at,.L702003ac
/* 70200290:	26f20001 */ 	addiu	$s2,$s7,0x1
/* 70200294:	27ae0534 */ 	addiu	$t6,$sp,0x534
/* 70200298:	020e4821 */ 	addu	$t1,$s0,$t6
/* 7020029c:	8fb80598 */ 	lw	$t8,0x598($sp)
.L702002a0:
/* 702002a0:	258c0001 */ 	addiu	$t4,$t4,0x1
/* 702002a4:	26100004 */ 	addiu	$s0,$s0,0x4
/* 702002a8:	03034023 */ 	subu	$t0,$t8,$v1
/* 702002ac:	0228082b */ 	sltu	$at,$s1,$t0
/* 702002b0:	25290004 */ 	addiu	$t1,$t1,0x4
/* 702002b4:	256b0004 */ 	addiu	$t3,$t3,0x4
/* 702002b8:	10200002 */ 	beqz	$at,.L702002c4
/* 702002bc:	00605025 */ 	move	$t2,$v1
/* 702002c0:	02204025 */ 	move	$t0,$s1
.L702002c4:
/* 702002c4:	026a1023 */ 	subu	$v0,$s3,$t2
/* 702002c8:	240f0001 */ 	li	$t7,0x1
/* 702002cc:	004f2004 */ 	sllv	$a0,$t7,$v0
/* 702002d0:	0244082b */ 	sltu	$at,$s2,$a0
/* 702002d4:	10200013 */ 	beqz	$at,.L70200324
/* 702002d8:	00403825 */ 	move	$a3,$v0
/* 702002dc:	24470001 */ 	addiu	$a3,$v0,0x1
/* 702002e0:	00971823 */ 	subu	$v1,$a0,$s7
/* 702002e4:	0013c880 */ 	sll	$t9,$s3,0x2
/* 702002e8:	27ae05a0 */ 	addiu	$t6,$sp,0x5a0
/* 702002ec:	00e8082b */ 	sltu	$at,$a3,$t0
/* 702002f0:	2463ffff */ 	addiu	$v1,$v1,-1
/* 702002f4:	1020000b */ 	beqz	$at,.L70200324
/* 702002f8:	032e2821 */ 	addu	$a1,$t9,$t6
.L702002fc:
/* 702002fc:	8ca40004 */ 	lw	$a0,0x4($a1)
/* 70200300:	00031040 */ 	sll	$v0,$v1,0x1
/* 70200304:	24a50004 */ 	addiu	$a1,$a1,0x4
/* 70200308:	0082082b */ 	sltu	$at,$a0,$v0
/* 7020030c:	50200006 */ 	beqzl	$at,.L70200328
/* 70200310:	8e830000 */ 	lw	$v1,0x0($s4)
/* 70200314:	24e70001 */ 	addiu	$a3,$a3,0x1
/* 70200318:	00e8082b */ 	sltu	$at,$a3,$t0
/* 7020031c:	1420fff7 */ 	bnez	$at,.L702002fc
/* 70200320:	00441823 */ 	subu	$v1,$v0,$a0
.L70200324:
/* 70200324:	8e830000 */ 	lw	$v1,0x0($s4)
.L70200328:
/* 70200328:	8fd90000 */ 	lw	$t9,0x0($s8)
/* 7020032c:	24180001 */ 	li	$t8,0x1
/* 70200330:	00f84004 */ 	sllv	$t0,$t8,$a3
/* 70200334:	000378c0 */ 	sll	$t7,$v1,0x3
/* 70200338:	00687021 */ 	addu	$t6,$v1,$t0
/* 7020033c:	25d80001 */ 	addiu	$t8,$t6,0x1
/* 70200340:	01f92821 */ 	addu	$a1,$t7,$t9
/* 70200344:	ae980000 */ 	sw	$t8,0x0($s4)
/* 70200348:	24a40008 */ 	addiu	$a0,$a1,0x8
/* 7020034c:	aec40000 */ 	sw	$a0,0x0($s6)
/* 70200350:	aca00004 */ 	sw	$zero,0x4($a1)
/* 70200354:	24b60004 */ 	addiu	$s6,$a1,0x4
/* 70200358:	00802825 */ 	move	$a1,$a0
/* 7020035c:	1180000f */ 	beqz	$t4,.L7020039c
/* 70200360:	ad240000 */ 	sw	$a0,0x0($t1)
/* 70200364:	ad6d0000 */ 	sw	$t5,0x0($t3)
/* 70200368:	24ef0010 */ 	addiu	$t7,$a3,0x10
/* 7020036c:	a3b10575 */ 	sb	$s1,0x575($sp)
/* 70200370:	a3af0574 */ 	sb	$t7,0x574($sp)
/* 70200374:	afa40578 */ 	sw	$a0,0x578($sp)
/* 70200378:	8d39fffc */ 	lw	$t9,-0x4($t1)
/* 7020037c:	01517023 */ 	subu	$t6,$t2,$s1
/* 70200380:	8ea10000 */ 	lw	$at,0x0($s5)
/* 70200384:	01cdc006 */ 	srlv	$t8,$t5,$t6
/* 70200388:	001878c0 */ 	sll	$t7,$t8,0x3
/* 7020038c:	032f7021 */ 	addu	$t6,$t9,$t7
/* 70200390:	adc10000 */ 	sw	$at,0x0($t6)
/* 70200394:	8eaf0004 */ 	lw	$t7,0x4($s5)
/* 70200398:	adcf0004 */ 	sw	$t7,0x4($t6)
.L7020039c:
/* 7020039c:	01511821 */ 	addu	$v1,$t2,$s1
/* 702003a0:	0073082a */ 	slt	$at,$v1,$s3
/* 702003a4:	5420ffbe */ 	bnezl	$at,.L702002a0
/* 702003a8:	8fb80598 */ 	lw	$t8,0x598($sp)
.L702003ac:
/* 702003ac:	8fb80038 */ 	lw	$t8,0x38($sp)
/* 702003b0:	24190001 */ 	li	$t9,0x1
/* 702003b4:	026a1823 */ 	subu	$v1,$s3,$t2
/* 702003b8:	01593004 */ 	sllv	$a2,$t9,$t2
/* 702003bc:	03f8082b */ 	sltu	$at,$ra,$t8
/* 702003c0:	a3a30575 */ 	sb	$v1,0x575($sp)
/* 702003c4:	14200004 */ 	bnez	$at,.L702003d8
/* 702003c8:	24c6ffff */ 	addiu	$a2,$a2,-1
/* 702003cc:	240e0063 */ 	li	$t6,0x63
/* 702003d0:	10000020 */ 	b	.L70200454
/* 702003d4:	a3ae0574 */ 	sb	$t6,0x574($sp)
.L702003d8:
/* 702003d8:	8fe20000 */ 	lw	$v0,0x0($ra)
/* 702003dc:	8faf05f0 */ 	lw	$t7,0x5f0($sp)
/* 702003e0:	8fa405f0 */ 	lw	$a0,0x5f0($sp)
/* 702003e4:	8fb905f8 */ 	lw	$t9,0x5f8($sp)
/* 702003e8:	004f082b */ 	sltu	$at,$v0,$t7
/* 702003ec:	1020000b */ 	beqz	$at,.L7020041c
/* 702003f0:	2c410100 */ 	sltiu	$at,$v0,0x100
/* 702003f4:	10200004 */ 	beqz	$at,.L70200408
/* 702003f8:	2418000f */ 	li	$t8,0xf
/* 702003fc:	24190010 */ 	li	$t9,0x10
/* 70200400:	10000002 */ 	b	.L7020040c
/* 70200404:	a3b90574 */ 	sb	$t9,0x574($sp)
.L70200408:
/* 70200408:	a3b80574 */ 	sb	$t8,0x574($sp)
.L7020040c:
/* 7020040c:	8fee0000 */ 	lw	$t6,0x0($ra)
/* 70200410:	27ff0004 */ 	addiu	$ra,$ra,0x4
/* 70200414:	1000000f */ 	b	.L70200454
/* 70200418:	a7ae0578 */ 	sh	$t6,0x578($sp)
.L7020041c:
/* 7020041c:	00447823 */ 	subu	$t7,$v0,$a0
/* 70200420:	01f9c021 */ 	addu	$t8,$t7,$t9
/* 70200424:	930e0000 */ 	lbu	$t6,0x0($t8)
/* 70200428:	8faf05f4 */ 	lw	$t7,0x5f4($sp)
/* 7020042c:	27ff0004 */ 	addiu	$ra,$ra,0x4
/* 70200430:	a3ae0574 */ 	sb	$t6,0x574($sp)
/* 70200434:	8ff9fffc */ 	lw	$t9,-0x4($ra)
/* 70200438:	0019c040 */ 	sll	$t8,$t9,0x1
/* 7020043c:	0004c840 */ 	sll	$t9,$a0,0x1
/* 70200440:	01f87021 */ 	addu	$t6,$t7,$t8
/* 70200444:	00197823 */ 	negu	$t7,$t9
/* 70200448:	01cfc021 */ 	addu	$t8,$t6,$t7
/* 7020044c:	97190000 */ 	lhu	$t9,0x0($t8)
/* 70200450:	a7b90578 */ 	sh	$t9,0x578($sp)
.L70200454:
/* 70200454:	014d3806 */ 	srlv	$a3,$t5,$t2
/* 70200458:	00e8082b */ 	sltu	$at,$a3,$t0
/* 7020045c:	1020000b */ 	beqz	$at,.L7020048c
/* 70200460:	240e0001 */ 	li	$t6,0x1
/* 70200464:	006e1004 */ 	sllv	$v0,$t6,$v1
.L70200468:
/* 70200468:	8ea10000 */ 	lw	$at,0x0($s5)
/* 7020046c:	000778c0 */ 	sll	$t7,$a3,0x3
/* 70200470:	00afc021 */ 	addu	$t8,$a1,$t7
/* 70200474:	af010000 */ 	sw	$at,0x0($t8)
/* 70200478:	8eae0004 */ 	lw	$t6,0x4($s5)
/* 7020047c:	00e23821 */ 	addu	$a3,$a3,$v0
/* 70200480:	00e8082b */ 	sltu	$at,$a3,$t0
/* 70200484:	1420fff8 */ 	bnez	$at,.L70200468
/* 70200488:	af0e0004 */ 	sw	$t6,0x4($t8)
.L7020048c:
/* 7020048c:	8fa70034 */ 	lw	$a3,0x34($sp)
/* 70200490:	8d620000 */ 	lw	$v0,0x0($t3)
/* 70200494:	01a77824 */ 	and	$t7,$t5,$a3
/* 70200498:	11e00005 */ 	beqz	$t7,.L702004b0
.L7020049c:
/* 7020049c:	0007c842 */ 	srl	$t9,$a3,0x1
/* 702004a0:	01a76826 */ 	xor	$t5,$t5,$a3
/* 702004a4:	01b9c024 */ 	and	$t8,$t5,$t9
/* 702004a8:	1700fffc */ 	bnez	$t8,.L7020049c
/* 702004ac:	03203825 */ 	move	$a3,$t9
.L702004b0:
/* 702004b0:	01a76826 */ 	xor	$t5,$t5,$a3
/* 702004b4:	01a67024 */ 	and	$t6,$t5,$a2
/* 702004b8:	11c2000b */ 	beq	$t6,$v0,.L702004e8
/* 702004bc:	02e03025 */ 	move	$a2,$s7
.L702004c0:
/* 702004c0:	01515023 */ 	subu	$t2,$t2,$s1
/* 702004c4:	240f0001 */ 	li	$t7,0x1
/* 702004c8:	014fc804 */ 	sllv	$t9,$t7,$t2
/* 702004cc:	8d6ffffc */ 	lw	$t7,-0x4($t3)
/* 702004d0:	2738ffff */ 	addiu	$t8,$t9,-1
/* 702004d4:	01b87024 */ 	and	$t6,$t5,$t8
/* 702004d8:	258cffff */ 	addiu	$t4,$t4,-1
/* 702004dc:	2610fffc */ 	addiu	$s0,$s0,-4
/* 702004e0:	15cffff7 */ 	bne	$t6,$t7,.L702004c0
/* 702004e4:	256bfffc */ 	addiu	$t3,$t3,-4
.L702004e8:
/* 702004e8:	16e0ff66 */ 	bnez	$s7,.L70200284
/* 702004ec:	26f7ffff */ 	addiu	$s7,$s7,-1
.L702004f0:
/* 702004f0:	8fb90050 */ 	lw	$t9,0x50($sp)
/* 702004f4:	8fae0598 */ 	lw	$t6,0x598($sp)
/* 702004f8:	26730001 */ 	addiu	$s3,$s3,0x1
/* 702004fc:	27380004 */ 	addiu	$t8,$t9,0x4
/* 70200500:	01d3082a */ 	slt	$at,$t6,$s3
/* 70200504:	1020ff4e */ 	beqz	$at,.L70200240
/* 70200508:	afb80050 */ 	sw	$t8,0x50($sp)
/* 7020050c:	afb605fc */ 	sw	$s6,0x5fc($sp)
.L70200510:
/* 70200510:	8fa20064 */ 	lw	$v0,0x64($sp)
/* 70200514:	0002782b */ 	sltu	$t7,$zero,$v0
/* 70200518:	11e00004 */ 	beqz	$t7,.L7020052c
/* 7020051c:	01e01025 */ 	move	$v0,$t7
/* 70200520:	8fa20598 */ 	lw	$v0,0x598($sp)
/* 70200524:	38590001 */ 	xori	$t9,$v0,0x1
/* 70200528:	0019102b */ 	sltu	$v0,$zero,$t9
.L7020052c:
/* 7020052c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/* 70200530:	8fb00008 */ 	lw	$s0,0x8($sp)
/* 70200534:	8fb1000c */ 	lw	$s1,0xc($sp)
/* 70200538:	8fb20010 */ 	lw	$s2,0x10($sp)
/* 7020053c:	8fb30014 */ 	lw	$s3,0x14($sp)
/* 70200540:	8fb40018 */ 	lw	$s4,0x18($sp)
/* 70200544:	8fb5001c */ 	lw	$s5,0x1c($sp)
/* 70200548:	8fb60020 */ 	lw	$s6,0x20($sp)
/* 7020054c:	8fb70024 */ 	lw	$s7,0x24($sp)
/* 70200550:	8fbe0028 */ 	lw	$s8,0x28($sp)
/* 70200554:	03e00008 */ 	jr	$ra
/* 70200558:	27bd05e8 */ 	addiu	$sp,$sp,0x5e8
);

u32 inflate_codes(struct huft *tl, struct huft *td, int bl, int bd)
{
	register u32 e;  /* table entry flag/number of extra bits */
	u32 n, d;        /* length and index for copy */
	u32 w;           /* current window position */
	struct huft *t;       /* pointer to table entry */
	u32 ml, md;      /* masks for bl and bd bits */
	register u32 b;       /* bit buffer */
	register u32 k;  /* number of bits in bit buffer */

	/* make local copies of globals */
	b = bb;                       /* initialize bit buffer */
	k = bk;
	w = wp;                       /* initialize window position */

	/* inflate the coded data */
	ml = mask_bits[bl];           /* precompute masks for speed */
	md = mask_bits[bd];

	for (;;) {                    /* do until end of block */
		NEEDBITS(bl)
		if ((e = (t = tl + (b & ml))->e) > 16) {
			do {
				DUMPBITS(t->b)
				e -= 16;
				NEEDBITS(e)
			} while ((e = (t = t->v.t + (b & mask_bits[e]))->e) > 16);
		}
		DUMPBITS(t->b)

		if (e == 16) {              /* then it's a literal */
			outbuf[w++] = (u8)t->v.n;
		} else {                      /* it's an EOB or a length */
			/* exit if end of block */
			if (e == 15) {
				break;
			}

			/* get length of block to copy */
			NEEDBITS(e)
			n = t->v.n + (b & mask_bits[e]);
			DUMPBITS(e);

			/* decode distance of block to copy */
			NEEDBITS(bd)
			if ((e = (t = td + (b & md))->e) > 16) {
				do {
					DUMPBITS(t->b)
					e -= 16;
					NEEDBITS(e)
				} while ((e = (t = t->v.t + (b & mask_bits[e]))->e) > 16);
			}
			DUMPBITS(t->b)
			NEEDBITS(e)
			d = w - t->v.n - (b & mask_bits[e]);
			DUMPBITS(e)

			/* do the copy */
			do {
				e = n;
				n = 0;

				do {
					outbuf[w++] = outbuf[d++];
				} while (--e);
			} while (n);
		}
	}

	/* restore the globals from the locals */
	wp = w;                       /* restore global window pointer */
	bb = b;                       /* restore global bit buffer */
	bk = k;

	/* done */
	return 0;
}

u32 inflate_stored(void)
{
	s32 n;           /* number of bytes in block */
	s32 w;           /* current window position */
	register u32 b; /* bit buffer */
	register u32 k;  /* number of bits in bit buffer */

	/* make local copies of globals */
	b = bb;                       /* initialize bit buffer */
	k = bk;
	w = wp;                       /* initialize window position */

	/* go to byte boundary */
	n = k & 7;
	DUMPBITS(n);

	/* get the length and its complement */
	NEEDBITS(16)
	n = (b & 0xffff);
	DUMPBITS(16)

	NEEDBITS(16)
	DUMPBITS(16)

	/* read and output the compressed data */
	while (n--) {
		NEEDBITS(8)
		outbuf[w++] = (u8)b;

		DUMPBITS(8)
	}

	/* restore the globals from the locals */
	wp = w;                       /* restore global window pointer */
	bb = b;                       /* restore global bit buffer */
	bk = k;
	return 0;
}

u32 inflate_fixed(void)
{
	s32 i;                /* temporary variable */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	u32 bl;               /* lookup bits for tl */
	u32 bd;               /* lookup bits for td */
	u32 l[288];           /* length list for huft_build */

	/* set up literal table */
	for (i = 0; i < 144; i++) {
		l[i] = 8;
	}
	for (; i < 256; i++) {
		l[i] = 9;
	}
	for (; i < 280; i++) {
		l[i] = 7;
	}
	for (; i < 288; i++) {
		l[i] = 8;
	}

	bl = 7;

	huft_build(l, 288, 257, cplens, cplext, &tl, &bl);

	/* set up distance table */
	for (i = 0; i < 30; i++) {
		l[i] = 5;
	}

	bd = 5;

	huft_build(l, 30, 0, cpdist, cpdext, &td, &bd);

	inflate_codes(tl, td, bl, bd);

	return 0;
}

u32 inflate_dynamic(void)
{
	s32 i;                /* temporary variables */
	u32 j;
	u32 l;           /* last length */
	u32 m;           /* mask for bit lengths table */
	u32 n;           /* number of lengths to get */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 nb;          /* number of bit length codes */
	u32 nl;          /* number of literal/length codes */
	u32 nd;          /* number of distance codes */
	register u32 k;  /* number of bits in bit buffer */
	register u32 b;  /* bit buffer */
	u32 ll[286+30];  /* literal/length and distance code lengths */

	/* make local bit buffer */
	b = bb;
	k = bk;

	/* read in table lengths */
	NEEDBITS(5)
	nl = 257 + (b & 0x1f);      /* number of literal/length codes */
	DUMPBITS(5)
	NEEDBITS(5)
	nd = 1 + (b & 0x1f);        /* number of distance codes */
	DUMPBITS(5)
	NEEDBITS(4)
	nb = 4 + (b & 0xf);         /* number of bit length codes */
	DUMPBITS(4)

	/* read in bit-length-code lengths */
	for (j = 0; j < nb; j++) {
		NEEDBITS(3)
		ll[border[j]] = b & 7;
		DUMPBITS(3)
	}

	for (; j < 19; j++) {
		ll[border[j]] = 0;
	}

	/* build decoding table for trees--single level, 7 bit lookup */
	bl = 7;

	huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);

	/* read in literal and distance code lengths */
	n = nl + nd;
	m = mask_bits[bl];
	i = l = 0;

	while (i < n) {
		NEEDBITS(bl)
		j = (td = tl + (b & m))->b;
		DUMPBITS(j)

		j = td->v.n;

		if (j < 16) {                 /* length of code in bits (0..15) */
			ll[i++] = l = j;          /* save last length in l */
		} else if (j == 16) {         /* repeat last length 3 to 6 times */
			NEEDBITS(2)
			j = 3 + (b & 3);
			DUMPBITS(2)

			while (j--) {
				ll[i++] = l;
			}
		} else if (j == 17) {         /* 3 to 10 zero length codes */
			NEEDBITS(3)
			j = 3 + (b & 7);
			DUMPBITS(3)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		} else {                      /* j == 18: 11 to 138 zero length codes */
			NEEDBITS(7)
			j = 11 + (b & 0x7f);
			DUMPBITS(7)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		}
	}

	/* restore the global bit buffer */
	bb = b;
	bk = k;

	/* build the decoding tables for literal/length and distance codes */
	bl = lbits;

	huft_build(ll, nl, 257, cplens, cplext, &tl, &bl);

	bd = dbits;

	huft_build(ll + nl, nd, 0, cpdist, cpdext, &td, &bd);

	/* decompress until an end-of-block code */
	inflate_codes(tl, td, bl, bd);

	return 0;
}

u32 inflate_block(u32 *e)
{
	u32 t;
	u32 b = bb;
	u32 k = bk;

	NEEDBITS(1)
	*e = b & 1;
	DUMPBITS(1)

	NEEDBITS(2)
	t = b & 3;
	DUMPBITS(2)

	bb = b;
	bk = k;

	if (t == 2) {
		return inflate_dynamic();
	}

	if (t == 0) {
		return inflate_stored();
	}

	if (t == 1) {
		return inflate_fixed();
	}

	return 2;
}

u32 inflate(void)
{
	u32 sp52;
	u32 r;
	u32 s1;

	wp = 0;
	bk = 0;
	bb = 0;
	s1 = 0;

	do {
		hufts = 0;
		r = inflate_block(&sp52);

		if (r != 0) {
			return r;
		}

		if (s1 < hufts) {
			s1 = hufts;
		}
	} while (sp52 == 0);

	while (bk >= 8) {
		bk -= 8;
		inptr--;
	}

	return 0;
}

u32 inflate1173(void *src, void *dst, void *buffer)
{
	inbuf = src;
	outbuf = dst;
	var702012e0 = buffer;
	inbuf += 2;
	inbuf += 3;
	wp = 0;
	inptr = 0;

	inflate();

	return wp;
}
