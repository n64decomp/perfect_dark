#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u8 *g_FrameBuffers[2];

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f000000
/*  f000000:	3c0e8009 */ 	lui	$t6,0x8009
/*  f000004:	91ce1160 */ 	lbu	$t6,0x1160($t6)
/*  f000008:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00000c:	24010001 */ 	li	$at,0x1
/*  f000010:	15c10006 */ 	bne	$t6,$at,.JF0f00002c
/*  f000014:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f000018:	3c06800a */ 	lui	$a2,0x800a
/*  f00001c:	24c6d140 */ 	addiu	$a2,$a2,-11968
/*  f000020:	240f007c */ 	li	$t7,0x7c
/*  f000024:	10000005 */ 	b	.JF0f00003c
/*  f000028:	accf0000 */ 	sw	$t7,0x0($a2)
.JF0f00002c:
/*  f00002c:	3c06800a */ 	lui	$a2,0x800a
/*  f000030:	24c6d140 */ 	addiu	$a2,$a2,-11968
/*  f000034:	241800ae */ 	li	$t8,0xae
/*  f000038:	acd80000 */ 	sw	$t8,0x0($a2)
.JF0f00003c:
/*  f00003c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f000040:	24050006 */ 	li	$a1,0x6
/*  f000044:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f000048:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f00004c:	0c0048e2 */ 	jal	mempAlloc
/*  f000050:	00192140 */ 	sll	$a0,$t9,0x5
/*  f000054:	3c06800a */ 	lui	$a2,0x800a
/*  f000058:	3c01800b */ 	lui	$at,0x800b
/*  f00005c:	ac22b5a4 */ 	sw	$v0,-0x4a5c($at)
/*  f000060:	24c6d140 */ 	addiu	$a2,$a2,-11968
/*  f000064:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f000068:	24050006 */ 	li	$a1,0x6
/*  f00006c:	00044040 */ 	sll	$t0,$a0,0x1
/*  f000070:	2504000f */ 	addiu	$a0,$t0,0xf
/*  f000074:	3489000f */ 	ori	$t1,$a0,0xf
/*  f000078:	0c0048e2 */ 	jal	mempAlloc
/*  f00007c:	3924000f */ 	xori	$a0,$t1,0xf
/*  f000080:	3c06800a */ 	lui	$a2,0x800a
/*  f000084:	24c6d140 */ 	addiu	$a2,$a2,-11968
/*  f000088:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f00008c:	3c05800b */ 	lui	$a1,0x800b
/*  f000090:	24a5b5a8 */ 	addiu	$a1,$a1,-19032
/*  f000094:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f000098:	19600012 */ 	blez	$t3,.JF0f0000e4
/*  f00009c:	00002025 */ 	move	$a0,$zero
/*  f0000a0:	00001825 */ 	move	$v1,$zero
/*  f0000a4:	8cac0000 */ 	lw	$t4,0x0($a1)
.JF0f0000a8:
/*  f0000a8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0000ac:	01831021 */ 	addu	$v0,$t4,$v1
/*  f0000b0:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f0000b4:	31aeff3f */ 	andi	$t6,$t5,0xff3f
/*  f0000b8:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f0000bc:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f0000c0:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f0000c4:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f0000c8:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0000cc:	37283fff */ 	ori	$t0,$t9,0x3fff
/*  f0000d0:	a4480000 */ 	sh	$t0,0x0($v0)
/*  f0000d4:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f0000d8:	0089082a */ 	slt	$at,$a0,$t1
/*  f0000dc:	5420fff2 */ 	bnezl	$at,.JF0f0000a8
/*  f0000e0:	8cac0000 */ 	lw	$t4,0x0($a1)
.JF0f0000e4:
/*  f0000e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0000e8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0000ec:	03e00008 */ 	jr	$ra
/*  f0000f0:	00000000 */ 	nop
);
#else
void func0f000000(void)
{
	s32 i;

	if (g_Jpn) {
		var800aabb4 = mempAlloc(0x2e80, MEMPOOL_PERMANENT);
		var800aabb8 = mempAlloc(0x100, MEMPOOL_PERMANENT);

		for (i = 0; i < 0x7c; i++) {
			var800aabb8[i].unk00_00 = 0;
			var800aabb8[i].unk00_02 = 0x3fff;
		}
	}
}
#endif
