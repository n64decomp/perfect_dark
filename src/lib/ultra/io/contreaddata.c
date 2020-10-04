#include <libultra_internal.h>
#include "gvars/gvars.h"

void __osPackReadData(void);

s32 osContStartReadData(OSMesgQueue *mq)
{
	s32 ret = 0;
	s32 i;

	__osSiGetAccess();

	if (__osContLastCmd != 1) {
		__osPackReadData();
		ret = __osSiRawStartDma(OS_WRITE, &__osContPifRam);
		osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	}

	ret = __osSiRawStartDma(OS_READ, &__osContPifRam);

	__osContLastCmd = 1;
	__osSiRelAccess();

	return ret;
}

GLOBAL_ASM(
glabel osContGetReadData
/*    4f484:	3c05800a */ 	lui	$a1,%hi(__osContLastCmd+0x1)
/*    4f488:	24a5c821 */ 	addiu	$a1,$a1,%lo(__osContLastCmd+0x1)
/*    4f48c:	90ae0000 */ 	lbu	$t6,0x0($a1)
/*    4f490:	3c02800a */ 	lui	$v0,%hi(__osContPifRam)
/*    4f494:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4f498:	2442c7e0 */ 	addiu	$v0,$v0,%lo(__osContPifRam)
/*    4f49c:	19c0001a */ 	blez	$t6,.L0004f508
/*    4f4a0:	00001825 */ 	or	$v1,$zero,$zero
/*    4f4a4:	27a60004 */ 	addiu	$a2,$sp,0x4
.L0004f4a8:
/*    4f4a8:	88410000 */ 	lwl	$at,0x0($v0)
/*    4f4ac:	98410003 */ 	lwr	$at,0x3($v0)
/*    4f4b0:	acc10000 */ 	sw	$at,0x0($a2)
/*    4f4b4:	88580004 */ 	lwl	$t8,0x4($v0)
/*    4f4b8:	98580007 */ 	lwr	$t8,0x7($v0)
/*    4f4bc:	acd80004 */ 	sw	$t8,0x4($a2)
/*    4f4c0:	93b90006 */ 	lbu	$t9,0x6($sp)
/*    4f4c4:	332800c0 */ 	andi	$t0,$t9,0xc0
/*    4f4c8:	00084903 */ 	sra	$t1,$t0,0x4
/*    4f4cc:	312a00ff */ 	andi	$t2,$t1,0xff
/*    4f4d0:	15400007 */ 	bnez	$t2,.L0004f4f0
/*    4f4d4:	a0890004 */ 	sb	$t1,0x4($a0)
/*    4f4d8:	97ab0008 */ 	lhu	$t3,0x8($sp)
/*    4f4dc:	a48b0000 */ 	sh	$t3,0x0($a0)
/*    4f4e0:	83ac000a */ 	lb	$t4,0xa($sp)
/*    4f4e4:	a08c0002 */ 	sb	$t4,0x2($a0)
/*    4f4e8:	83ad000b */ 	lb	$t5,0xb($sp)
/*    4f4ec:	a08d0003 */ 	sb	$t5,0x3($a0)
.L0004f4f0:
/*    4f4f0:	90ae0000 */ 	lbu	$t6,0x0($a1)
/*    4f4f4:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4f4f8:	24420008 */ 	addiu	$v0,$v0,0x8
/*    4f4fc:	006e082a */ 	slt	$at,$v1,$t6
/*    4f500:	1420ffe9 */ 	bnez	$at,.L0004f4a8
/*    4f504:	24840006 */ 	addiu	$a0,$a0,0x6
.L0004f508:
/*    4f508:	03e00008 */ 	jr	$ra
/*    4f50c:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel __osPackReadData
/*    4f510:	3c05800a */ 	lui	$a1,%hi(__osContPifRam)
/*    4f514:	24a5c7e0 */ 	addiu	$a1,$a1,%lo(__osContPifRam)
/*    4f518:	3c04800a */ 	lui	$a0,%hi(__osContPifRam)
/*    4f51c:	3c03800a */ 	lui	$v1,%hi(var8009c81c)
/*    4f520:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4f524:	00a01025 */ 	or	$v0,$a1,$zero
/*    4f528:	2463c81c */ 	addiu	$v1,$v1,%lo(var8009c81c)
/*    4f52c:	2484c7e0 */ 	addiu	$a0,$a0,%lo(__osContPifRam)
.L0004f530:
/*    4f530:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4f534:	0083082b */ 	sltu	$at,$a0,$v1
/*    4f538:	1420fffd */ 	bnez	$at,.L0004f530
/*    4f53c:	ac80fffc */ 	sw	$zero,-0x4($a0)
/*    4f540:	3c04800a */ 	lui	$a0,%hi(__osContLastCmd+0x1)
/*    4f544:	2484c821 */ 	addiu	$a0,$a0,%lo(__osContLastCmd+0x1)
/*    4f548:	908c0000 */ 	lbu	$t4,0x0($a0)
/*    4f54c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4f550:	240f00ff */ 	addiu	$t7,$zero,0xff
/*    4f554:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4f558:	24190004 */ 	addiu	$t9,$zero,0x4
/*    4f55c:	24080001 */ 	addiu	$t0,$zero,0x1
/*    4f560:	3409ffff */ 	dli	$t1,0xffff
/*    4f564:	240affff */ 	addiu	$t2,$zero,-1
/*    4f568:	240bffff */ 	addiu	$t3,$zero,-1
/*    4f56c:	acae003c */ 	sw	$t6,0x3c($a1)
/*    4f570:	a3af000c */ 	sb	$t7,0xc($sp)
/*    4f574:	a3b8000d */ 	sb	$t8,0xd($sp)
/*    4f578:	a3b9000e */ 	sb	$t9,0xe($sp)
/*    4f57c:	a3a8000f */ 	sb	$t0,0xf($sp)
/*    4f580:	a7a90010 */ 	sh	$t1,0x10($sp)
/*    4f584:	a3aa0012 */ 	sb	$t2,0x12($sp)
/*    4f588:	a3ab0013 */ 	sb	$t3,0x13($sp)
/*    4f58c:	1980000e */ 	blez	$t4,.L0004f5c8
/*    4f590:	00001825 */ 	or	$v1,$zero,$zero
/*    4f594:	27a5000c */ 	addiu	$a1,$sp,0xc
/*    4f598:	8ca10000 */ 	lw	$at,0x0($a1)
.L0004f59c:
/*    4f59c:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4f5a0:	24420008 */ 	addiu	$v0,$v0,0x8
/*    4f5a4:	a841fff8 */ 	swl	$at,-0x8($v0)
/*    4f5a8:	b841fffb */ 	swr	$at,-0x5($v0)
/*    4f5ac:	8cae0004 */ 	lw	$t6,0x4($a1)
/*    4f5b0:	a84efffc */ 	swl	$t6,-0x4($v0)
/*    4f5b4:	b84effff */ 	swr	$t6,-0x1($v0)
/*    4f5b8:	908f0000 */ 	lbu	$t7,0x0($a0)
/*    4f5bc:	006f082a */ 	slt	$at,$v1,$t7
/*    4f5c0:	5420fff6 */ 	bnezl	$at,.L0004f59c
/*    4f5c4:	8ca10000 */ 	lw	$at,0x0($a1)
.L0004f5c8:
/*    4f5c8:	241800fe */ 	addiu	$t8,$zero,0xfe
/*    4f5cc:	a0580000 */ 	sb	$t8,0x0($v0)
/*    4f5d0:	03e00008 */ 	jr	$ra
/*    4f5d4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4f5d8:	00000000 */ 	nop
/*    4f5dc:	00000000 */ 	nop
);
