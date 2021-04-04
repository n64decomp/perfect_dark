#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_37b00.h"
#include "types.h"

struct mp3vars g_Mp3Vars;
u8 *var8009c3f4;

s32 func00038ba8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3);

void mp3Init(ALHeap *heap)
{
	bzero(&g_Mp3Vars, sizeof(struct mp3vars));

#if VERSION < VERSION_NTSC_1_0
	crashPrint("MPEG : RWI -> Allocating %d bytes for ASISTREAM from audio heap\n", 0x8480);
#endif

	var8009c3f4 = alHeapAlloc(heap, 0x8480, 1);
	var8005f6f8 = alHeapAlloc(heap, 1, 0x2200);
	var8005f6fc = alHeapAlloc(heap, 1, 0x2200);

	var8009c6d8 = alHeapAlloc(heap, 0x400, 1);
	var8009c6dc = alHeapAlloc(heap, 0x400, 1);
	var8009c640 = alHeapAlloc(heap, 0xa410, 1);
	var8009c644 = alHeapAlloc(heap, 0x8000, 1);

	func00044404();

	g_Mp3Vars.var8009c398 = alHeapAlloc(heap, 1, 0x50);
	*(u8 **)((u32)&g_Mp3Vars+0x44) = alHeapAlloc(heap, 1, 0x440);

	g_Mp3Vars.var8009c3e0 = 0;
	g_Mp3Vars.var8009c3e4 = 0x7fff;
	g_Mp3Vars.var8009c3ec = g_Mp3Vars.var8009c3ee = 0x40;
	g_Mp3Vars.var8009c39e = 0x7fff;
	g_Mp3Vars.var8009c39c = 0x40;

	g_Mp3Vars.ivol1 = (var8005f570[g_Mp3Vars.var8009c39c & 0x7f] * g_Mp3Vars.var8009c39e) >> 15;
	g_Mp3Vars.ivol2 = (var8005f570[127 - (g_Mp3Vars.var8009c39c & 0x7f)] * g_Mp3Vars.var8009c39e) >> 15;

	g_Mp3Vars.var8009c3b4 = 1;
	g_Mp3Vars.var8009c3a4 = 0x7ffc;

	if (g_Mp3Vars.var8009c39c & 0x80) {
		g_Mp3Vars.var8009c3a6 = 1;
	} else {
		g_Mp3Vars.var8009c3a6 = 0;
	}

	func00038b90(func00038ba8);
}

void func00037d88(s32 arg0, s32 arg1)
{
	if (g_Mp3Vars.var8009c3dc == NULL) {
		return;
	}

	g_Mp3Vars.var8009c390 = arg0;
	g_Mp3Vars.var8009c3c0 = arg1;
	g_Mp3Vars.var8009c3c4 = 0;
	g_Mp3Vars.var8009c3e8 = 0;
	g_Mp3Vars.var8009c3e4 = 0x7fff;
	g_Mp3Vars.var8009c3f0 = 5;

	func00038cac();

	g_Mp3Vars.var8009c3e0 = 4;
}

void func00037e1c(void)
{
	g_Mp3Vars.var8009c3e0 = 3;
}

void func00037e38(void)
{
	if (g_Mp3Vars.var8009c3e0 == 1) {
		g_Mp3Vars.var8009c3e0 = 2;
	}
}

void func00037e68(void)
{
	if (g_Mp3Vars.var8009c3e0 == 2) {
		g_Mp3Vars.var8009c3f0 = 5;
		g_Mp3Vars.var8009c3e0 = 5;
	}
}

s32 func00037ea4(void)
{
	if (g_Mp3Vars.var8009c3e0 == 1
			|| g_Mp3Vars.var8009c3e0 == 4
			|| g_Mp3Vars.var8009c3e0 == 5
			|| g_Mp3Vars.var8009c3e0 == 2) {
		return g_Mp3Vars.var8009c3e0;
	} else {
		return 0;
	}
}

void func00037f08(s32 arg0, s32 arg1)
{
	if (arg0 < 0) {
		g_Mp3Vars.var8009c3e4 = 0;
	} else if (arg0 > 0x7fff) {
		g_Mp3Vars.var8009c3e4 = 0x7fff;
	} else {
		g_Mp3Vars.var8009c3e4 = arg0;
	}

	g_Mp3Vars.var8009c3e8 = arg1;
}

void func00037f5c(s32 arg0, bool arg1)
{
	if (arg0 > 255) {
		arg0 = 255;
	}

	if (arg0 < 0) {
		arg0 = 0;
	}

	g_Mp3Vars.var8009c3ee = arg0;

	if (arg1) {
		g_Mp3Vars.var8009c3ec = g_Mp3Vars.var8009c3ee;
	}
}

void func00037fa8(s32 arg0, s32 arg1)
{
	// empty
}

GLOBAL_ASM(
glabel func00037fc0
/*    37fc0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    37fc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    37fc8:	afa40068 */ 	sw	$a0,0x68($sp)
/*    37fcc:	afa5006c */ 	sw	$a1,0x6c($sp)
/*    37fd0:	afa0005c */ 	sw	$zero,0x5c($sp)
/*    37fd4:	afa00054 */ 	sw	$zero,0x54($sp)
/*    37fd8:	240e04e0 */ 	addiu	$t6,$zero,0x4e0
/*    37fdc:	afae004c */ 	sw	$t6,0x4c($sp)
/*    37fe0:	240f0650 */ 	addiu	$t7,$zero,0x650
/*    37fe4:	afaf0048 */ 	sw	$t7,0x48($sp)
/*    37fe8:	3c18800a */ 	lui	$t8,%hi(g_Mp3Vars+0x5c)
/*    37fec:	3c19800a */ 	lui	$t9,%hi(g_Mp3Vars+0x5c+0x2)
/*    37ff0:	8739c3ee */ 	lh	$t9,%lo(g_Mp3Vars+0x5c+0x2)($t9)
/*    37ff4:	8718c3ec */ 	lh	$t8,%lo(g_Mp3Vars+0x5c)($t8)
/*    37ff8:	13190024 */ 	beq	$t8,$t9,.L0003808c
/*    37ffc:	00000000 */ 	nop
/*    38000:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x5c+0x2)
/*    38004:	3c09800a */ 	lui	$t1,%hi(g_Mp3Vars+0x5c)
/*    38008:	8529c3ec */ 	lh	$t1,%lo(g_Mp3Vars+0x5c)($t1)
/*    3800c:	8508c3ee */ 	lh	$t0,%lo(g_Mp3Vars+0x5c+0x2)($t0)
/*    38010:	01095023 */ 	subu	$t2,$t0,$t1
/*    38014:	afaa0060 */ 	sw	$t2,0x60($sp)
/*    38018:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    3801c:	2961fffe */ 	slti	$at,$t3,-2
/*    38020:	1420000b */ 	bnez	$at,.L00038050
/*    38024:	00000000 */ 	nop
/*    38028:	29610003 */ 	slti	$at,$t3,0x3
/*    3802c:	10200008 */ 	beqz	$at,.L00038050
/*    38030:	00000000 */ 	nop
/*    38034:	3c0c800a */ 	lui	$t4,%hi(g_Mp3Vars+0x5c)
/*    38038:	858cc3ec */ 	lh	$t4,%lo(g_Mp3Vars+0x5c)($t4)
/*    3803c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    38040:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x5c)
/*    38044:	018d7021 */ 	addu	$t6,$t4,$t5
/*    38048:	10000010 */ 	b	.L0003808c
/*    3804c:	a42ec3ec */ 	sh	$t6,%lo(g_Mp3Vars+0x5c)($at)
.L00038050:
/*    38050:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    38054:	29e10003 */ 	slti	$at,$t7,0x3
/*    38058:	14200007 */ 	bnez	$at,.L00038078
/*    3805c:	00000000 */ 	nop
/*    38060:	3c18800a */ 	lui	$t8,%hi(g_Mp3Vars+0x5c)
/*    38064:	8718c3ec */ 	lh	$t8,%lo(g_Mp3Vars+0x5c)($t8)
/*    38068:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x5c)
/*    3806c:	27190002 */ 	addiu	$t9,$t8,0x2
/*    38070:	10000006 */ 	b	.L0003808c
/*    38074:	a439c3ec */ 	sh	$t9,%lo(g_Mp3Vars+0x5c)($at)
.L00038078:
/*    38078:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x5c)
/*    3807c:	8508c3ec */ 	lh	$t0,%lo(g_Mp3Vars+0x5c)($t0)
/*    38080:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x5c)
/*    38084:	2509fffe */ 	addiu	$t1,$t0,-2
/*    38088:	a429c3ec */ 	sh	$t1,%lo(g_Mp3Vars+0x5c)($at)
.L0003808c:
/*    3808c:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x50)
/*    38090:	8d4ac3e0 */ 	lw	$t2,%lo(g_Mp3Vars+0x50)($t2)
/*    38094:	24010004 */ 	addiu	$at,$zero,0x4
/*    38098:	15410033 */ 	bne	$t2,$at,.L00038168
/*    3809c:	00000000 */ 	nop
/*    380a0:	0c00e32b */ 	jal	func00038cac
/*    380a4:	00000000 */ 	nop
/*    380a8:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x60)
/*    380ac:	916bc3f0 */ 	lbu	$t3,%lo(g_Mp3Vars+0x60)($t3)
/*    380b0:	15600028 */ 	bnez	$t3,.L00038154
/*    380b4:	00000000 */ 	nop
/*    380b8:	3c05800a */ 	lui	$a1,%hi(g_Mp3Vars+0x4c)
/*    380bc:	3c06800a */ 	lui	$a2,%hi(g_Mp3Vars+0x30)
/*    380c0:	8cc6c3c0 */ 	lw	$a2,%lo(g_Mp3Vars+0x30)($a2)
/*    380c4:	8ca5c3dc */ 	lw	$a1,%lo(g_Mp3Vars+0x4c)($a1)
/*    380c8:	0c011118 */ 	jal	func00044460
/*    380cc:	00002025 */ 	or	$a0,$zero,$zero
/*    380d0:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x04)
/*    380d4:	ac22c394 */ 	sw	$v0,%lo(g_Mp3Vars+0x04)($at)
/*    380d8:	3c0c800a */ 	lui	$t4,%hi(g_Mp3Vars+0x04)
/*    380dc:	8d8cc394 */ 	lw	$t4,%lo(g_Mp3Vars+0x04)($t4)
/*    380e0:	15800007 */ 	bnez	$t4,.L00038100
/*    380e4:	00000000 */ 	nop
/*    380e8:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x50)
/*    380ec:	ac20c3e0 */ 	sw	$zero,%lo(g_Mp3Vars+0x50)($at)
/*    380f0:	10000208 */ 	b	.L00038914
/*    380f4:	00001025 */ 	or	$v0,$zero,$zero
/*    380f8:	10000014 */ 	b	.L0003814c
/*    380fc:	00000000 */ 	nop
.L00038100:
/*    38100:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    38104:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x50)
/*    38108:	ac2dc3e0 */ 	sw	$t5,%lo(g_Mp3Vars+0x50)($at)
/*    3810c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    38110:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x24)
/*    38114:	a42ec3b4 */ 	sh	$t6,%lo(g_Mp3Vars+0x24)($at)
/*    38118:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x38)
/*    3811c:	ac20c3c8 */ 	sw	$zero,%lo(g_Mp3Vars+0x38)($at)
/*    38120:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x3c)
/*    38124:	ac20c3cc */ 	sw	$zero,%lo(g_Mp3Vars+0x3c)($at)
/*    38128:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x40)
/*    3812c:	ac20c3d0 */ 	sw	$zero,%lo(g_Mp3Vars+0x40)($at)
/*    38130:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x48)
/*    38134:	ac20c3d8 */ 	sw	$zero,%lo(g_Mp3Vars+0x48)($at)
/*    38138:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars)
/*    3813c:	25efc390 */ 	addiu	$t7,$t7,%lo(g_Mp3Vars)
/*    38140:	8de40044 */ 	lw	$a0,0x44($t7)
/*    38144:	0c012c30 */ 	jal	bzero
/*    38148:	24050440 */ 	addiu	$a1,$zero,0x440
.L0003814c:
/*    3814c:	10000006 */ 	b	.L00038168
/*    38150:	00000000 */ 	nop
.L00038154:
/*    38154:	3c18800a */ 	lui	$t8,%hi(g_Mp3Vars+0x60)
/*    38158:	9318c3f0 */ 	lbu	$t8,%lo(g_Mp3Vars+0x60)($t8)
/*    3815c:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x60)
/*    38160:	2719ffff */ 	addiu	$t9,$t8,-1
/*    38164:	a039c3f0 */ 	sb	$t9,%lo(g_Mp3Vars+0x60)($at)
.L00038168:
/*    38168:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x50)
/*    3816c:	8d08c3e0 */ 	lw	$t0,%lo(g_Mp3Vars+0x50)($t0)
/*    38170:	24010005 */ 	addiu	$at,$zero,0x5
/*    38174:	15010010 */ 	bne	$t0,$at,.L000381b8
/*    38178:	00000000 */ 	nop
/*    3817c:	0c00e32b */ 	jal	func00038cac
/*    38180:	00000000 */ 	nop
/*    38184:	3c09800a */ 	lui	$t1,%hi(g_Mp3Vars+0x60)
/*    38188:	9129c3f0 */ 	lbu	$t1,%lo(g_Mp3Vars+0x60)($t1)
/*    3818c:	15200005 */ 	bnez	$t1,.L000381a4
/*    38190:	00000000 */ 	nop
/*    38194:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    38198:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x50)
/*    3819c:	10000006 */ 	b	.L000381b8
/*    381a0:	ac2ac3e0 */ 	sw	$t2,%lo(g_Mp3Vars+0x50)($at)
.L000381a4:
/*    381a4:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x60)
/*    381a8:	916bc3f0 */ 	lbu	$t3,%lo(g_Mp3Vars+0x60)($t3)
/*    381ac:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x60)
/*    381b0:	256cffff */ 	addiu	$t4,$t3,-1
/*    381b4:	a02cc3f0 */ 	sb	$t4,%lo(g_Mp3Vars+0x60)($at)
.L000381b8:
/*    381b8:	3c0d800a */ 	lui	$t5,%hi(g_Mp3Vars+0x50)
/*    381bc:	8dadc3e0 */ 	lw	$t5,%lo(g_Mp3Vars+0x50)($t5)
/*    381c0:	24010001 */ 	addiu	$at,$zero,0x1
/*    381c4:	15a101cd */ 	bne	$t5,$at,.L000388fc
/*    381c8:	00000000 */ 	nop
/*    381cc:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x40)
/*    381d0:	8defc3d0 */ 	lw	$t7,%lo(g_Mp3Vars+0x40)($t7)
/*    381d4:	8fae0068 */ 	lw	$t6,0x68($sp)
/*    381d8:	3c19800a */ 	lui	$t9,%hi(g_Mp3Vars+0x3c)
/*    381dc:	8f39c3cc */ 	lw	$t9,%lo(g_Mp3Vars+0x3c)($t9)
/*    381e0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    381e4:	0338082a */ 	slt	$at,$t9,$t8
/*    381e8:	10200066 */ 	beqz	$at,.L00038384
/*    381ec:	00000000 */ 	nop
/*    381f0:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x3c)
/*    381f4:	3c09800a */ 	lui	$t1,%hi(g_Mp3Vars+0x40)
/*    381f8:	8d29c3d0 */ 	lw	$t1,%lo(g_Mp3Vars+0x40)($t1)
/*    381fc:	8d08c3cc */ 	lw	$t0,%lo(g_Mp3Vars+0x3c)($t0)
/*    38200:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x3c)
/*    38204:	01095023 */ 	subu	$t2,$t0,$t1
/*    38208:	ac2ac3cc */ 	sw	$t2,%lo(g_Mp3Vars+0x3c)($at)
/*    3820c:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x3c)
/*    38210:	8d6bc3cc */ 	lw	$t3,%lo(g_Mp3Vars+0x3c)($t3)
/*    38214:	1160000f */ 	beqz	$t3,.L00038254
/*    38218:	00000000 */ 	nop
/*    3821c:	3c0c800a */ 	lui	$t4,%hi(g_Mp3Vars+0x38)
/*    38220:	8d8cc3c8 */ 	lw	$t4,%lo(g_Mp3Vars+0x38)($t4)
/*    38224:	1180000b */ 	beqz	$t4,.L00038254
/*    38228:	00000000 */ 	nop
/*    3822c:	3c0d800a */ 	lui	$t5,%hi(g_Mp3Vars+0x40)
/*    38230:	8dadc3d0 */ 	lw	$t5,%lo(g_Mp3Vars+0x40)($t5)
/*    38234:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x38)
/*    38238:	8defc3c8 */ 	lw	$t7,%lo(g_Mp3Vars+0x38)($t7)
/*    3823c:	000d7040 */ 	sll	$t6,$t5,0x1
/*    38240:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    38244:	afb80054 */ 	sw	$t8,0x54($sp)
/*    38248:	3c19800a */ 	lui	$t9,%hi(g_Mp3Vars+0x3c)
/*    3824c:	8f39c3cc */ 	lw	$t9,%lo(g_Mp3Vars+0x3c)($t9)
/*    38250:	afb90050 */ 	sw	$t9,0x50($sp)
.L00038254:
/*    38254:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x40)
/*    38258:	ac20c3d0 */ 	sw	$zero,%lo(g_Mp3Vars+0x40)($at)
/*    3825c:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x3c)
/*    38260:	ac20c3cc */ 	sw	$zero,%lo(g_Mp3Vars+0x3c)($at)
/*    38264:	3c04800a */ 	lui	$a0,%hi(g_Mp3Vars+0x04)
/*    38268:	8c84c394 */ 	lw	$a0,%lo(g_Mp3Vars+0x04)($a0)
/*    3826c:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    38270:	0c01114f */ 	jal	func0004453c
/*    38274:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*    38278:	10400042 */ 	beqz	$v0,.L00038384
/*    3827c:	00000000 */ 	nop
/*    38280:	8fa80058 */ 	lw	$t0,0x58($sp)
/*    38284:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x38)
/*    38288:	ac28c3c8 */ 	sw	$t0,%lo(g_Mp3Vars+0x38)($at)
/*    3828c:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    38290:	afa00064 */ 	sw	$zero,0x64($sp)
/*    38294:	1920002c */ 	blez	$t1,.L00038348
/*    38298:	00000000 */ 	nop
.L0003829c:
/*    3829c:	8faa006c */ 	lw	$t2,0x6c($sp)
/*    382a0:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    382a4:	afab0044 */ 	sw	$t3,0x44($sp)
/*    382a8:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*    382ac:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    382b0:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*    382b4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*    382b8:	3c0e0800 */ 	lui	$t6,0x800
/*    382bc:	adee0000 */ 	sw	$t6,0x0($t7)
/*    382c0:	8fb80064 */ 	lw	$t8,0x64($sp)
/*    382c4:	3c04800a */ 	lui	$a0,%hi(g_Mp3Vars+0x44)
/*    382c8:	0018c880 */ 	sll	$t9,$t8,0x2
/*    382cc:	00992021 */ 	addu	$a0,$a0,$t9
/*    382d0:	0c012d20 */ 	jal	osVirtualToPhysical
/*    382d4:	8c84c3d4 */ 	lw	$a0,%lo(g_Mp3Vars+0x44)($a0)
/*    382d8:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    382dc:	ad020004 */ 	sw	$v0,0x4($t0)
/*    382e0:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*    382e4:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    382e8:	afab0040 */ 	sw	$t3,0x40($sp)
/*    382ec:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*    382f0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    382f4:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*    382f8:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x48)
/*    382fc:	8d4ac3d8 */ 	lw	$t2,%lo(g_Mp3Vars+0x48)($t2)
/*    38300:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    38304:	3c010700 */ 	lui	$at,0x700
/*    38308:	314effff */ 	andi	$t6,$t2,0xffff
/*    3830c:	01c17825 */ 	or	$t7,$t6,$at
/*    38310:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    38314:	0c012d20 */ 	jal	osVirtualToPhysical
/*    38318:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    3831c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    38320:	af220004 */ 	sw	$v0,0x4($t9)
/*    38324:	8fa80058 */ 	lw	$t0,0x58($sp)
/*    38328:	250b0488 */ 	addiu	$t3,$t0,0x488
/*    3832c:	afab0058 */ 	sw	$t3,0x58($sp)
/*    38330:	8fac0064 */ 	lw	$t4,0x64($sp)
/*    38334:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    38338:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    3833c:	01a9082a */ 	slt	$at,$t5,$t1
/*    38340:	1420ffd6 */ 	bnez	$at,.L0003829c
/*    38344:	afad0064 */ 	sw	$t5,0x64($sp)
.L00038348:
/*    38348:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x48)
/*    3834c:	8d4ac3d8 */ 	lw	$t2,%lo(g_Mp3Vars+0x48)($t2)
/*    38350:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x48)
/*    38354:	254effdc */ 	addiu	$t6,$t2,-36
/*    38358:	31cf001e */ 	andi	$t7,$t6,0x1e
/*    3835c:	ac2fc3d8 */ 	sw	$t7,%lo(g_Mp3Vars+0x48)($at)
/*    38360:	24180240 */ 	addiu	$t8,$zero,0x240
/*    38364:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x3c)
/*    38368:	ac38c3cc */ 	sw	$t8,%lo(g_Mp3Vars+0x3c)($at)
/*    3836c:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    38370:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x60+0x1)
/*    38374:	3b280002 */ 	xori	$t0,$t9,0x2
/*    38378:	2d080001 */ 	sltiu	$t0,$t0,0x1
/*    3837c:	10000001 */ 	b	.L00038384
/*    38380:	a028c3f1 */ 	sb	$t0,%lo(g_Mp3Vars+0x60+0x1)($at)
.L00038384:
/*    38384:	0c00e32b */ 	jal	func00038cac
/*    38388:	00000000 */ 	nop
/*    3838c:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x60+0x1)
/*    38390:	916bc3f1 */ 	lbu	$t3,%lo(g_Mp3Vars+0x60+0x1)($t3)
/*    38394:	15600002 */ 	bnez	$t3,.L000383a0
/*    38398:	00000000 */ 	nop
/*    3839c:	afa0004c */ 	sw	$zero,0x4c($sp)
.L000383a0:
/*    383a0:	8fac0054 */ 	lw	$t4,0x54($sp)
/*    383a4:	11800040 */ 	beqz	$t4,.L000384a8
/*    383a8:	00000000 */ 	nop
/*    383ac:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    383b0:	8da90000 */ 	lw	$t1,0x0($t5)
/*    383b4:	afa9003c */ 	sw	$t1,0x3c($sp)
/*    383b8:	8daa0000 */ 	lw	$t2,0x0($t5)
/*    383bc:	254e0008 */ 	addiu	$t6,$t2,0x8
/*    383c0:	adae0000 */ 	sw	$t6,0x0($t5)
/*    383c4:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    383c8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*    383cc:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    383d0:	01efc021 */ 	addu	$t8,$t7,$t7
/*    383d4:	33190fff */ 	andi	$t9,$t8,0xfff
/*    383d8:	00194300 */ 	sll	$t0,$t9,0xc
/*    383dc:	3c010400 */ 	lui	$at,0x400
/*    383e0:	01015825 */ 	or	$t3,$t0,$at
/*    383e4:	31890fff */ 	andi	$t1,$t4,0xfff
/*    383e8:	01695025 */ 	or	$t2,$t3,$t1
/*    383ec:	adca0000 */ 	sw	$t2,0x0($t6)
/*    383f0:	0c012d20 */ 	jal	osVirtualToPhysical
/*    383f4:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    383f8:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    383fc:	ada20004 */ 	sw	$v0,0x4($t5)
/*    38400:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x60+0x1)
/*    38404:	91efc3f1 */ 	lbu	$t7,%lo(g_Mp3Vars+0x60+0x1)($t7)
/*    38408:	11e00019 */ 	beqz	$t7,.L00038470
/*    3840c:	00000000 */ 	nop
/*    38410:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    38414:	27190488 */ 	addiu	$t9,$t8,0x488
/*    38418:	afb90054 */ 	sw	$t9,0x54($sp)
/*    3841c:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*    38420:	8d0c0000 */ 	lw	$t4,0x0($t0)
/*    38424:	afac0038 */ 	sw	$t4,0x38($sp)
/*    38428:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*    3842c:	25690008 */ 	addiu	$t1,$t3,0x8
/*    38430:	ad090000 */ 	sw	$t1,0x0($t0)
/*    38434:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    38438:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    3843c:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    38440:	014a7021 */ 	addu	$t6,$t2,$t2
/*    38444:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*    38448:	000d7b00 */ 	sll	$t7,$t5,0xc
/*    3844c:	3c010400 */ 	lui	$at,0x400
/*    38450:	01e1c025 */ 	or	$t8,$t7,$at
/*    38454:	332c0fff */ 	andi	$t4,$t9,0xfff
/*    38458:	030c5825 */ 	or	$t3,$t8,$t4
/*    3845c:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*    38460:	0c012d20 */ 	jal	osVirtualToPhysical
/*    38464:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    38468:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    3846c:	ad020004 */ 	sw	$v0,0x4($t0)
.L00038470:
/*    38470:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    38474:	8fad004c */ 	lw	$t5,0x4c($sp)
/*    38478:	014a7021 */ 	addu	$t6,$t2,$t2
/*    3847c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    38480:	afaf004c */ 	sw	$t7,0x4c($sp)
/*    38484:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    38488:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    3848c:	0339c021 */ 	addu	$t8,$t9,$t9
/*    38490:	01985821 */ 	addu	$t3,$t4,$t8
/*    38494:	afab0048 */ 	sw	$t3,0x48($sp)
/*    38498:	8fa90068 */ 	lw	$t1,0x68($sp)
/*    3849c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    384a0:	01285023 */ 	subu	$t2,$t1,$t0
/*    384a4:	afaa0068 */ 	sw	$t2,0x68($sp)
.L000384a8:
/*    384a8:	8fad0068 */ 	lw	$t5,0x68($sp)
/*    384ac:	19a00043 */ 	blez	$t5,.L000385bc
/*    384b0:	00000000 */ 	nop
/*    384b4:	3c0e800a */ 	lui	$t6,%hi(g_Mp3Vars+0x38)
/*    384b8:	8dcec3c8 */ 	lw	$t6,%lo(g_Mp3Vars+0x38)($t6)
/*    384bc:	11c0003f */ 	beqz	$t6,.L000385bc
/*    384c0:	00000000 */ 	nop
/*    384c4:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x40)
/*    384c8:	8defc3d0 */ 	lw	$t7,%lo(g_Mp3Vars+0x40)($t7)
/*    384cc:	3c0c800a */ 	lui	$t4,%hi(g_Mp3Vars+0x38)
/*    384d0:	8d8cc3c8 */ 	lw	$t4,%lo(g_Mp3Vars+0x38)($t4)
/*    384d4:	000fc840 */ 	sll	$t9,$t7,0x1
/*    384d8:	032cc021 */ 	addu	$t8,$t9,$t4
/*    384dc:	afb80054 */ 	sw	$t8,0x54($sp)
/*    384e0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*    384e4:	8d690000 */ 	lw	$t1,0x0($t3)
/*    384e8:	afa90034 */ 	sw	$t1,0x34($sp)
/*    384ec:	8d680000 */ 	lw	$t0,0x0($t3)
/*    384f0:	250a0008 */ 	addiu	$t2,$t0,0x8
/*    384f4:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    384f8:	8fad0068 */ 	lw	$t5,0x68($sp)
/*    384fc:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*    38500:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    38504:	01ad7021 */ 	addu	$t6,$t5,$t5
/*    38508:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*    3850c:	000fcb00 */ 	sll	$t9,$t7,0xc
/*    38510:	3c010400 */ 	lui	$at,0x400
/*    38514:	03216025 */ 	or	$t4,$t9,$at
/*    38518:	33090fff */ 	andi	$t1,$t8,0xfff
/*    3851c:	01894025 */ 	or	$t0,$t4,$t1
/*    38520:	ad480000 */ 	sw	$t0,0x0($t2)
/*    38524:	0c012d20 */ 	jal	osVirtualToPhysical
/*    38528:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    3852c:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    38530:	ad620004 */ 	sw	$v0,0x4($t3)
/*    38534:	3c0d800a */ 	lui	$t5,%hi(g_Mp3Vars+0x60+0x1)
/*    38538:	91adc3f1 */ 	lbu	$t5,%lo(g_Mp3Vars+0x60+0x1)($t5)
/*    3853c:	11a00019 */ 	beqz	$t5,.L000385a4
/*    38540:	00000000 */ 	nop
/*    38544:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    38548:	25cf0488 */ 	addiu	$t7,$t6,0x488
/*    3854c:	afaf0054 */ 	sw	$t7,0x54($sp)
/*    38550:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*    38554:	8f380000 */ 	lw	$t8,0x0($t9)
/*    38558:	afb80030 */ 	sw	$t8,0x30($sp)
/*    3855c:	8f2c0000 */ 	lw	$t4,0x0($t9)
/*    38560:	25890008 */ 	addiu	$t1,$t4,0x8
/*    38564:	af290000 */ 	sw	$t1,0x0($t9)
/*    38568:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    3856c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    38570:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    38574:	01085021 */ 	addu	$t2,$t0,$t0
/*    38578:	314b0fff */ 	andi	$t3,$t2,0xfff
/*    3857c:	000b6b00 */ 	sll	$t5,$t3,0xc
/*    38580:	3c010400 */ 	lui	$at,0x400
/*    38584:	01a17025 */ 	or	$t6,$t5,$at
/*    38588:	31f80fff */ 	andi	$t8,$t7,0xfff
/*    3858c:	01d86025 */ 	or	$t4,$t6,$t8
/*    38590:	ad2c0000 */ 	sw	$t4,0x0($t1)
/*    38594:	0c012d20 */ 	jal	osVirtualToPhysical
/*    38598:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    3859c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    385a0:	af220004 */ 	sw	$v0,0x4($t9)
.L000385a4:
/*    385a4:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x40)
/*    385a8:	8d08c3d0 */ 	lw	$t0,%lo(g_Mp3Vars+0x40)($t0)
/*    385ac:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    385b0:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x40)
/*    385b4:	010a5821 */ 	addu	$t3,$t0,$t2
/*    385b8:	ac2bc3d0 */ 	sw	$t3,%lo(g_Mp3Vars+0x40)($at)
.L000385bc:
/*    385bc:	3c04800a */ 	lui	$a0,%hi(g_Mp3Vars)
/*    385c0:	0c00e249 */ 	jal	func00038924
/*    385c4:	2484c390 */ 	addiu	$a0,$a0,%lo(g_Mp3Vars)
/*    385c8:	3c0d800a */ 	lui	$t5,%hi(g_Mp3Vars+0x60+0x1)
/*    385cc:	91adc3f1 */ 	lbu	$t5,%lo(g_Mp3Vars+0x60+0x1)($t5)
/*    385d0:	15a000c8 */ 	bnez	$t5,.L000388f4
/*    385d4:	00000000 */ 	nop
/*    385d8:	8faf006c */ 	lw	$t7,0x6c($sp)
/*    385dc:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    385e0:	afae002c */ 	sw	$t6,0x2c($sp)
/*    385e4:	8df80000 */ 	lw	$t8,0x0($t7)
/*    385e8:	270c0008 */ 	addiu	$t4,$t8,0x8
/*    385ec:	adec0000 */ 	sw	$t4,0x0($t7)
/*    385f0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    385f4:	3c090200 */ 	lui	$t1,0x200
/*    385f8:	352904e0 */ 	ori	$t1,$t1,0x4e0
/*    385fc:	af290000 */ 	sw	$t1,0x0($t9)
/*    38600:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    38604:	240802e0 */ 	addiu	$t0,$zero,0x2e0
/*    38608:	ad480004 */ 	sw	$t0,0x4($t2)
/*    3860c:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x24)
/*    38610:	856bc3b4 */ 	lh	$t3,%lo(g_Mp3Vars+0x24)($t3)
/*    38614:	11600099 */ 	beqz	$t3,.L0003887c
/*    38618:	00000000 */ 	nop
/*    3861c:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x24)
/*    38620:	a420c3b4 */ 	sh	$zero,%lo(g_Mp3Vars+0x24)($at)
/*    38624:	3c0d800a */ 	lui	$t5,%hi(g_Mp3Vars+0x0c)
/*    38628:	85adc39c */ 	lh	$t5,%lo(g_Mp3Vars+0x0c)($t5)
/*    3862c:	3c0c8006 */ 	lui	$t4,%hi(var8005f570)
/*    38630:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x0c+0x2)
/*    38634:	31ae007f */ 	andi	$t6,$t5,0x7f
/*    38638:	000ec040 */ 	sll	$t8,$t6,0x1
/*    3863c:	01986021 */ 	addu	$t4,$t4,$t8
/*    38640:	858cf570 */ 	lh	$t4,%lo(var8005f570)($t4)
/*    38644:	85efc39e */ 	lh	$t7,%lo(g_Mp3Vars+0x0c+0x2)($t7)
/*    38648:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x1c)
/*    3864c:	018f0019 */ 	multu	$t4,$t7
/*    38650:	00004812 */ 	mflo	$t1
/*    38654:	0009cbc3 */ 	sra	$t9,$t1,0xf
/*    38658:	a439c3ac */ 	sh	$t9,%lo(g_Mp3Vars+0x1c)($at)
/*    3865c:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x10)
/*    38660:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x1c)
/*    38664:	854ac3ac */ 	lh	$t2,%lo(g_Mp3Vars+0x1c)($t2)
/*    38668:	8508c3a0 */ 	lh	$t0,%lo(g_Mp3Vars+0x10)($t0)
/*    3866c:	3c07800a */ 	lui	$a3,%hi(g_Mp3Vars)
/*    38670:	448a3000 */ 	mtc1	$t2,$f6
/*    38674:	44882000 */ 	mtc1	$t0,$f4
/*    38678:	24e7c390 */ 	addiu	$a3,$a3,%lo(g_Mp3Vars)
/*    3867c:	3c06800a */ 	lui	$a2,%hi(g_Mp3Vars+0x2c)
/*    38680:	8cc6c3bc */ 	lw	$a2,%lo(g_Mp3Vars+0x2c)($a2)
/*    38684:	24e70018 */ 	addiu	$a3,$a3,0x18
/*    38688:	468033a0 */ 	cvt.s.w	$f14,$f6
/*    3868c:	0c00fd83 */ 	jal	func0003f60c
/*    38690:	46802320 */ 	cvt.s.w	$f12,$f4
/*    38694:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x18+0x2)
/*    38698:	a422c3aa */ 	sh	$v0,%lo(g_Mp3Vars+0x18+0x2)($at)
/*    3869c:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x0c)
/*    386a0:	856bc39c */ 	lh	$t3,%lo(g_Mp3Vars+0x0c)($t3)
/*    386a4:	3c0c8006 */ 	lui	$t4,%hi(var8005f570+0xfe)
/*    386a8:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x0c+0x2)
/*    386ac:	316d007f */ 	andi	$t5,$t3,0x7f
/*    386b0:	000d7023 */ 	negu	$t6,$t5
/*    386b4:	000ec040 */ 	sll	$t8,$t6,0x1
/*    386b8:	01986021 */ 	addu	$t4,$t4,$t8
/*    386bc:	858cf66e */ 	lh	$t4,%lo(var8005f570+0xfe)($t4)
/*    386c0:	85efc39e */ 	lh	$t7,%lo(g_Mp3Vars+0x0c+0x2)($t7)
/*    386c4:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x20+0x2)
/*    386c8:	018f0019 */ 	multu	$t4,$t7
/*    386cc:	00004812 */ 	mflo	$t1
/*    386d0:	0009cbc3 */ 	sra	$t9,$t1,0xf
/*    386d4:	a439c3b2 */ 	sh	$t9,%lo(g_Mp3Vars+0x20+0x2)($at)
/*    386d8:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x10+0x2)
/*    386dc:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x20+0x2)
/*    386e0:	854ac3b2 */ 	lh	$t2,%lo(g_Mp3Vars+0x20+0x2)($t2)
/*    386e4:	8508c3a2 */ 	lh	$t0,%lo(g_Mp3Vars+0x10+0x2)($t0)
/*    386e8:	3c07800a */ 	lui	$a3,%hi(g_Mp3Vars)
/*    386ec:	448a5000 */ 	mtc1	$t2,$f10
/*    386f0:	44884000 */ 	mtc1	$t0,$f8
/*    386f4:	24e7c390 */ 	addiu	$a3,$a3,%lo(g_Mp3Vars)
/*    386f8:	3c06800a */ 	lui	$a2,%hi(g_Mp3Vars+0x2c)
/*    386fc:	8cc6c3bc */ 	lw	$a2,%lo(g_Mp3Vars+0x2c)($a2)
/*    38700:	24e7001e */ 	addiu	$a3,$a3,0x1e
/*    38704:	468053a0 */ 	cvt.s.w	$f14,$f10
/*    38708:	0c00fd83 */ 	jal	func0003f60c
/*    3870c:	46804320 */ 	cvt.s.w	$f12,$f8
/*    38710:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x20)
/*    38714:	a422c3b0 */ 	sh	$v0,%lo(g_Mp3Vars+0x20)($at)
/*    38718:	8fab006c */ 	lw	$t3,0x6c($sp)
/*    3871c:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*    38720:	afad0028 */ 	sw	$t5,0x28($sp)
/*    38724:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*    38728:	25d80008 */ 	addiu	$t8,$t6,0x8
/*    3872c:	ad780000 */ 	sw	$t8,0x0($t3)
/*    38730:	3c0c800a */ 	lui	$t4,%hi(g_Mp3Vars+0x10)
/*    38734:	858cc3a0 */ 	lh	$t4,%lo(g_Mp3Vars+0x10)($t4)
/*    38738:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3873c:	3c010906 */ 	lui	$at,0x906
/*    38740:	318fffff */ 	andi	$t7,$t4,0xffff
/*    38744:	01e14825 */ 	or	$t1,$t7,$at
/*    38748:	af290000 */ 	sw	$t1,0x0($t9)
/*    3874c:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x14)
/*    38750:	8508c3a4 */ 	lh	$t0,%lo(g_Mp3Vars+0x14)($t0)
/*    38754:	3c0e800a */ 	lui	$t6,%hi(g_Mp3Vars+0x14+0x2)
/*    38758:	85cec3a6 */ 	lh	$t6,%lo(g_Mp3Vars+0x14+0x2)($t6)
/*    3875c:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    38760:	310affff */ 	andi	$t2,$t0,0xffff
/*    38764:	000a6c00 */ 	sll	$t5,$t2,0x10
/*    38768:	31d8ffff */ 	andi	$t8,$t6,0xffff
/*    3876c:	01b85825 */ 	or	$t3,$t5,$t8
/*    38770:	ad8b0004 */ 	sw	$t3,0x4($t4)
/*    38774:	8faf006c */ 	lw	$t7,0x6c($sp)
/*    38778:	8de90000 */ 	lw	$t1,0x0($t7)
/*    3877c:	afa90024 */ 	sw	$t1,0x24($sp)
/*    38780:	8df90000 */ 	lw	$t9,0x0($t7)
/*    38784:	27280008 */ 	addiu	$t0,$t9,0x8
/*    38788:	ade80000 */ 	sw	$t0,0x0($t7)
/*    3878c:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x20+0x2)
/*    38790:	854ac3b2 */ 	lh	$t2,%lo(g_Mp3Vars+0x20+0x2)($t2)
/*    38794:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    38798:	3c010904 */ 	lui	$at,0x904
/*    3879c:	314effff */ 	andi	$t6,$t2,0xffff
/*    387a0:	01c16825 */ 	or	$t5,$t6,$at
/*    387a4:	af0d0000 */ 	sw	$t5,0x0($t8)
/*    387a8:	3c0b800a */ 	lui	$t3,%hi(g_Mp3Vars+0x20)
/*    387ac:	856bc3b0 */ 	lh	$t3,%lo(g_Mp3Vars+0x20)($t3)
/*    387b0:	3c19800a */ 	lui	$t9,%hi(g_Mp3Vars+0x1c+0x2)
/*    387b4:	9739c3ae */ 	lhu	$t9,%lo(g_Mp3Vars+0x1c+0x2)($t9)
/*    387b8:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    387bc:	316cffff */ 	andi	$t4,$t3,0xffff
/*    387c0:	000c4c00 */ 	sll	$t1,$t4,0x10
/*    387c4:	3328ffff */ 	andi	$t0,$t9,0xffff
/*    387c8:	01287825 */ 	or	$t7,$t1,$t0
/*    387cc:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*    387d0:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    387d4:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*    387d8:	afad0020 */ 	sw	$t5,0x20($sp)
/*    387dc:	8dd80000 */ 	lw	$t8,0x0($t6)
/*    387e0:	270b0008 */ 	addiu	$t3,$t8,0x8
/*    387e4:	adcb0000 */ 	sw	$t3,0x0($t6)
/*    387e8:	3c0c800a */ 	lui	$t4,%hi(g_Mp3Vars+0x1c)
/*    387ec:	858cc3ac */ 	lh	$t4,%lo(g_Mp3Vars+0x1c)($t4)
/*    387f0:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    387f4:	3c010900 */ 	lui	$at,0x900
/*    387f8:	3199ffff */ 	andi	$t9,$t4,0xffff
/*    387fc:	03214825 */ 	or	$t1,$t9,$at
/*    38800:	ad090000 */ 	sw	$t1,0x0($t0)
/*    38804:	3c0f800a */ 	lui	$t7,%hi(g_Mp3Vars+0x18+0x2)
/*    38808:	85efc3aa */ 	lh	$t7,%lo(g_Mp3Vars+0x18+0x2)($t7)
/*    3880c:	3c18800a */ 	lui	$t8,%hi(g_Mp3Vars+0x18)
/*    38810:	9718c3a8 */ 	lhu	$t8,%lo(g_Mp3Vars+0x18)($t8)
/*    38814:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    38818:	31eaffff */ 	andi	$t2,$t7,0xffff
/*    3881c:	000a6c00 */ 	sll	$t5,$t2,0x10
/*    38820:	330bffff */ 	andi	$t3,$t8,0xffff
/*    38824:	01ab7025 */ 	or	$t6,$t5,$t3
/*    38828:	ad8e0004 */ 	sw	$t6,0x4($t4)
/*    3882c:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*    38830:	8f290000 */ 	lw	$t1,0x0($t9)
/*    38834:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    38838:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3883c:	250f0008 */ 	addiu	$t7,$t0,0x8
/*    38840:	af2f0000 */ 	sw	$t7,0x0($t9)
/*    38844:	3c0a800a */ 	lui	$t2,%hi(g_Mp3Vars+0x10+0x2)
/*    38848:	854ac3a2 */ 	lh	$t2,%lo(g_Mp3Vars+0x10+0x2)($t2)
/*    3884c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    38850:	3c010301 */ 	lui	$at,0x301
/*    38854:	3158ffff */ 	andi	$t8,$t2,0xffff
/*    38858:	03016825 */ 	or	$t5,$t8,$at
/*    3885c:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*    38860:	3c04800a */ 	lui	$a0,%hi(g_Mp3Vars+0x08)
/*    38864:	0c012d20 */ 	jal	osVirtualToPhysical
/*    38868:	8c84c398 */ 	lw	$a0,%lo(g_Mp3Vars+0x08)($a0)
/*    3886c:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    38870:	adc20004 */ 	sw	$v0,0x4($t6)
/*    38874:	1000000f */ 	b	.L000388b4
/*    38878:	00000000 */ 	nop
.L0003887c:
/*    3887c:	8fac006c */ 	lw	$t4,0x6c($sp)
/*    38880:	8d890000 */ 	lw	$t1,0x0($t4)
/*    38884:	afa90018 */ 	sw	$t1,0x18($sp)
/*    38888:	8d880000 */ 	lw	$t0,0x0($t4)
/*    3888c:	250f0008 */ 	addiu	$t7,$t0,0x8
/*    38890:	ad8f0000 */ 	sw	$t7,0x0($t4)
/*    38894:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    38898:	3c190300 */ 	lui	$t9,0x300
/*    3889c:	ad590000 */ 	sw	$t9,0x0($t2)
/*    388a0:	3c04800a */ 	lui	$a0,%hi(g_Mp3Vars+0x08)
/*    388a4:	0c012d20 */ 	jal	osVirtualToPhysical
/*    388a8:	8c84c398 */ 	lw	$a0,%lo(g_Mp3Vars+0x08)($a0)
/*    388ac:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    388b0:	af020004 */ 	sw	$v0,0x4($t8)
.L000388b4:
/*    388b4:	3c0d800a */ 	lui	$t5,%hi(g_Mp3Vars+0x28)
/*    388b8:	8dadc3b8 */ 	lw	$t5,%lo(g_Mp3Vars+0x28)($t5)
/*    388bc:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x28)
/*    388c0:	25ab00b8 */ 	addiu	$t3,$t5,0xb8
/*    388c4:	ac2bc3b8 */ 	sw	$t3,%lo(g_Mp3Vars+0x28)($at)
/*    388c8:	3c0e800a */ 	lui	$t6,%hi(g_Mp3Vars+0x28)
/*    388cc:	3c09800a */ 	lui	$t1,%hi(g_Mp3Vars+0x2c)
/*    388d0:	8d29c3bc */ 	lw	$t1,%lo(g_Mp3Vars+0x2c)($t1)
/*    388d4:	8dcec3b8 */ 	lw	$t6,%lo(g_Mp3Vars+0x28)($t6)
/*    388d8:	012e082a */ 	slt	$at,$t1,$t6
/*    388dc:	10200005 */ 	beqz	$at,.L000388f4
/*    388e0:	00000000 */ 	nop
/*    388e4:	3c08800a */ 	lui	$t0,%hi(g_Mp3Vars+0x2c)
/*    388e8:	8d08c3bc */ 	lw	$t0,%lo(g_Mp3Vars+0x2c)($t0)
/*    388ec:	3c01800a */ 	lui	$at,%hi(g_Mp3Vars+0x28)
/*    388f0:	ac28c3b8 */ 	sw	$t0,%lo(g_Mp3Vars+0x28)($at)
.L000388f4:
/*    388f4:	10000003 */ 	b	.L00038904
/*    388f8:	00000000 */ 	nop
.L000388fc:
/*    388fc:	10000005 */ 	b	.L00038914
/*    38900:	00001025 */ 	or	$v0,$zero,$zero
.L00038904:
/*    38904:	10000003 */ 	b	.L00038914
/*    38908:	24020001 */ 	addiu	$v0,$zero,0x1
/*    3890c:	10000001 */ 	b	.L00038914
/*    38910:	00000000 */ 	nop
.L00038914:
/*    38914:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    38918:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    3891c:	03e00008 */ 	jr	$ra
/*    38920:	00000000 */ 	nop
);

void func00038924(struct mp3vars *vars)
{
	if (vars->var8009c39e != vars->var8009c3e4 || vars->var8009c39c != vars->var8009c3ec) {
		if (vars->samples >= vars->var8009c3bc) {
			vars->var8009c3ac = (var8005f570[vars->var8009c39c & 0x7f] * vars->var8009c39e >> 15);
			vars->var8009c3b2 = (var8005f570[127 - (vars->var8009c39c & 0x7f)] * vars->var8009c39e >> 15);
			vars->samples = vars->var8009c3bc;
			vars->ivol1 = vars->var8009c3ac;
			vars->ivol2 = vars->var8009c3b2;
		} else {
			vars->ivol1 = _getVol(vars->ivol1, vars->samples, vars->ratem1, vars->ratel1);
			vars->ivol2 = _getVol(vars->ivol2, vars->samples, vars->ratem2, vars->ratel2);
		}

		if (vars->ivol1 == 0) {
			vars->ivol1 = 1;
		}

		if (vars->ivol2 == 0) {
			vars->ivol2 = 1;
		}

		vars->var8009c39e = vars->var8009c3e4;

		if (vars->var8009c39c != vars->var8009c3ec) {
			if (var8009c340.unk02) {
				vars->var8009c39c = ((s16)(vars->var8009c3ec & 0x7f) >> 1) + 32;
			} else {
				if (var8009c340.unk01) {
					vars->var8009c39c = 64;
				} else {
					vars->var8009c39c = vars->var8009c3ec;
				}
			}

			vars->var8009c39c &= (vars->var8009c3ec & 0x80) + 0x7f;

			vars->var8009c3a6 = (vars->var8009c39c & 0x80) ? 1 : 0;
		}

		vars->samples = 0;
		vars->var8009c3bc = (vars->var8009c3e8 + 183) / 184 * 184;
		vars->var8009c3b4 = 1;
	}
}

void func00038b90(void *fn)
{
	g_Mp3Vars.var8009c3dc = fn;
}

s32 func00038ba8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3)
{
	u32 sp1c;
	ALDMAproc proc;

	if (arg3 != -1) {
		g_Mp3Vars.var8009c3c4 = arg3;
	}

	if (g_Mp3Vars.var8009c3c4 + arg2 > g_Mp3Vars.var8009c3c0) {
		arg2 = g_Mp3Vars.var8009c3c0 - g_Mp3Vars.var8009c3c4;
	}

	proc = n_syn->drvr.dma(&sp1c);
	sp1c = OS_K0_TO_PHYSICAL(proc(g_Mp3Vars.var8009c390 + g_Mp3Vars.var8009c3c4, arg2, 0));

	bcopy((u8 *)sp1c, arg1, arg2);

	g_Mp3Vars.var8009c3c4 += arg2;

	return arg2;
}

void func00038cac(void)
{
	u32 state;
	ALDMAproc proc;

	proc = n_syn->drvr.dma(&state);

	proc(g_Mp3Vars.var8009c390 + g_Mp3Vars.var8009c3c4, 0x400, 0);
}
