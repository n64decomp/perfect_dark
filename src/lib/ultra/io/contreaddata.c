#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

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

void __osPackReadData(void)
{
	u8 *ptr;
	__OSContReadFormat readformat;
	int i;

	ptr = (u8*)&__osContPifRam.ramarray;

	for (i = 0; i < ARRLEN(__osContPifRam.ramarray); i++) {
		__osContPifRam.ramarray[i] = 0;
	}

	__osContPifRam.pifstatus = CONT_CMD_EXE;
	readformat.dummy = CONT_CMD_NOP;
	readformat.txsize = CONT_CMD_READ_BUTTON_TX;
	readformat.rxsize = CONT_CMD_READ_BUTTON_RX;
	readformat.cmd = CONT_CMD_READ_BUTTON;
	readformat.button = -1;
	readformat.stick_x = -1;
	readformat.stick_y = -1;

	for(i=0; i < __osMaxControllers; i++) {
		*(__OSContReadFormat*)ptr = readformat;
		ptr += sizeof(__OSContReadFormat);
	}

	*ptr = CONT_CMD_END;
}
