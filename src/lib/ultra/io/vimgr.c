#include <libultra_internal.h>
#include "bss.h"

OSDevMgr __osViDevMgr = {0};
u32 var8005cefc = 0;

OSThread viThread;
char viThreadStack[512];
OSMesgQueue viEventQueue;
OSMesg viEventBuf[5];
u32 var8009025c;
OSIoMesg viRetraceMsg;
OSIoMesg viCounterMsg;
u32 var80090290;

void viMgrMain(void *args);

void osCreateViManager(OSPri pri)
{
	u32 savedMask;
	OSPri oldPri;
	OSPri myPri;

	if (__osViDevMgr.active == 0) {
		__osTimerServicesInit();
		var8005cefc = 0;
		osCreateMesgQueue(&viEventQueue, viEventBuf, 5);

		viRetraceMsg.hdr.type = OS_MESG_TYPE_VRETRACE;
		viRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
		viRetraceMsg.hdr.retQueue = NULL;
		viCounterMsg.hdr.type = OS_MESG_TYPE_COUNTER;
		viCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
		viCounterMsg.hdr.retQueue = NULL;

		osSetEventMesg(OS_EVENT_VI, &viEventQueue, &viRetraceMsg);
		osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, &viCounterMsg);

		oldPri = -1;
		myPri = osGetThreadPri(NULL);

		if (myPri < pri) {
			oldPri = myPri;
			osSetThreadPri(NULL, pri);
		}

		savedMask = __osDisableInt();

		__osViDevMgr.active = 1;
		__osViDevMgr.thread = &viThread;
		__osViDevMgr.cmdQueue = &viEventQueue;
		__osViDevMgr.evtQueue = &viEventQueue;
		__osViDevMgr.acsQueue = NULL;
		__osViDevMgr.dma = NULL;
		__osViDevMgr.edma = NULL;

		osCreateThread(&viThread, 0, viMgrMain, &__osViDevMgr, &viThreadStack[512], pri);
		__osViInit();
		osStartThread(&viThread);
		__osRestoreInt(savedMask);

		if (oldPri != -1) {
			osSetThreadPri(0, oldPri);
		}
	}
}

GLOBAL_ASM(
glabel viMgrMain
/*     31d0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*     31d4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     31d8:	afb70030 */ 	sw	$s7,0x30($sp)
/*     31dc:	0080b825 */ 	or	$s7,$a0,$zero
/*     31e0:	afb6002c */ 	sw	$s6,0x2c($sp)
/*     31e4:	afb50028 */ 	sw	$s5,0x28($sp)
/*     31e8:	afb40024 */ 	sw	$s4,0x24($sp)
/*     31ec:	afb30020 */ 	sw	$s3,0x20($sp)
/*     31f0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     31f4:	afb10018 */ 	sw	$s1,0x18($sp)
/*     31f8:	afb00014 */ 	sw	$s0,0x14($sp)
/*     31fc:	0c0125e0 */ 	jal	__osViGetCurrentContext
/*     3200:	afa00044 */ 	sw	$zero,0x44($sp)
/*     3204:	94430002 */ 	lhu	$v1,0x2($v0)
/*     3208:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     320c:	2416000e */ 	addiu	$s6,$zero,0xe
/*     3210:	14600004 */ 	bnez	$v1,.L00003224
/*     3214:	a4230290 */ 	sh	$v1,%lo(var80090290)($at)
/*     3218:	24030001 */ 	addiu	$v1,$zero,0x1
/*     321c:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     3220:	a4230290 */ 	sh	$v1,%lo(var80090290)($at)
.L00003224:
/*     3224:	3c13800a */ 	lui	$s3,%hi(__osViIntrCount)
/*     3228:	3c12800a */ 	lui	$s2,%hi(__osBaseCounter)
/*     322c:	3c11800a */ 	lui	$s1,%hi(__osCurrentTime)
/*     3230:	2631c780 */ 	addiu	$s1,$s1,%lo(__osCurrentTime)
/*     3234:	2652c788 */ 	addiu	$s2,$s2,%lo(__osBaseCounter)
/*     3238:	2673c78c */ 	addiu	$s3,$s3,%lo(__osViIntrCount)
/*     323c:	2415000d */ 	addiu	$s5,$zero,0xd
/*     3240:	27b40044 */ 	addiu	$s4,$sp,0x44
.L00003244:
/*     3244:	8ee4000c */ 	lw	$a0,0xc($s7)
.L00003248:
/*     3248:	02802825 */ 	or	$a1,$s4,$zero
/*     324c:	0c0121bc */ 	jal	osRecvMesg
/*     3250:	24060001 */ 	addiu	$a2,$zero,0x1
/*     3254:	8fae0044 */ 	lw	$t6,0x44($sp)
/*     3258:	95c30000 */ 	lhu	$v1,0x0($t6)
/*     325c:	10750005 */ 	beq	$v1,$s5,.L00003274
/*     3260:	00000000 */ 	nop
/*     3264:	1076002a */ 	beq	$v1,$s6,.L00003310
/*     3268:	00000000 */ 	nop
/*     326c:	1000fff6 */ 	b	.L00003248
/*     3270:	8ee4000c */ 	lw	$a0,0xc($s7)
.L00003274:
/*     3274:	0c0125e4 */ 	jal	__osViSwapContext
/*     3278:	00000000 */ 	nop
/*     327c:	3c038009 */ 	lui	$v1,%hi(var80090290)
/*     3280:	94630290 */ 	lhu	$v1,%lo(var80090290)($v1)
/*     3284:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     3288:	2463ffff */ 	addiu	$v1,$v1,-1
/*     328c:	306fffff */ 	andi	$t7,$v1,0xffff
/*     3290:	15e0000e */ 	bnez	$t7,.L000032cc
/*     3294:	a42f0290 */ 	sh	$t7,%lo(var80090290)($at)
/*     3298:	0c0125e0 */ 	jal	__osViGetCurrentContext
/*     329c:	00000000 */ 	nop
/*     32a0:	8c580010 */ 	lw	$t8,0x10($v0)
/*     32a4:	00408025 */ 	or	$s0,$v0,$zero
/*     32a8:	00003025 */ 	or	$a2,$zero,$zero
/*     32ac:	53000005 */ 	beqzl	$t8,.L000032c4
/*     32b0:	96030002 */ 	lhu	$v1,0x2($s0)
/*     32b4:	8c440010 */ 	lw	$a0,0x10($v0)
/*     32b8:	0c012238 */ 	jal	osSendMesg
/*     32bc:	8c450014 */ 	lw	$a1,0x14($v0)
/*     32c0:	96030002 */ 	lhu	$v1,0x2($s0)
.L000032c4:
/*     32c4:	3c018009 */ 	lui	$at,%hi(var80090290)
/*     32c8:	a4230290 */ 	sh	$v1,%lo(var80090290)($at)
.L000032cc:
/*     32cc:	8e790000 */ 	lw	$t9,0x0($s3)
/*     32d0:	8e500000 */ 	lw	$s0,0x0($s2)
/*     32d4:	27280001 */ 	addiu	$t0,$t9,0x1
/*     32d8:	0c012144 */ 	jal	osGetCount
/*     32dc:	ae680000 */ 	sw	$t0,0x0($s3)
/*     32e0:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*     32e4:	00508023 */ 	subu	$s0,$v0,$s0
/*     32e8:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*     32ec:	020d7821 */ 	addu	$t7,$s0,$t5
/*     32f0:	240a0000 */ 	addiu	$t2,$zero,0x0
/*     32f4:	01ed082b */ 	sltu	$at,$t7,$t5
/*     32f8:	002a7021 */ 	addu	$t6,$at,$t2
/*     32fc:	01cc7021 */ 	addu	$t6,$t6,$t4
/*     3300:	ae420000 */ 	sw	$v0,0x0($s2)
/*     3304:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*     3308:	1000ffce */ 	b	.L00003244
/*     330c:	ae2f0004 */ 	sw	$t7,0x4($s1)
.L00003310:
/*     3310:	0c01248f */ 	jal	__osTimerInterrupt
/*     3314:	00000000 */ 	nop
/*     3318:	1000ffcb */ 	b	.L00003248
/*     331c:	8ee4000c */ 	lw	$a0,0xc($s7)
/*     3320:	00000000 */ 	nop
/*     3324:	00000000 */ 	nop
/*     3328:	00000000 */ 	nop
/*     332c:	00000000 */ 	nop
/*     3330:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     3334:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     3338:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     333c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     3340:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     3344:	8fb40024 */ 	lw	$s4,0x24($sp)
/*     3348:	8fb50028 */ 	lw	$s5,0x28($sp)
/*     334c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*     3350:	8fb70030 */ 	lw	$s7,0x30($sp)
/*     3354:	03e00008 */ 	jr	$ra
/*     3358:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

// This matches, but the infinite loop causes ld to add 0x10 bytes of fill
// to the start of this file's .text section.
//void viMgrMain(void *args)
//{
//	__OSViContext *vc;
//	OSDevMgr *dm;
//	OSIoMesg *mb;
//	static u16 retrace; // var80090290
//	s32 first;
//	u32 count;
//
//	mb = NULL;
//	first = 0;
//	vc = __osViGetCurrentContext();
//	retrace = vc->retraceCount;
//
//	if (retrace == 0) {
//		retrace = 1;
//	}
//
//	dm = (OSDevMgr *)args;
//
//	while (true) {
//		osRecvMesg(dm->evtQueue, (OSMesg) &mb, OS_MESG_BLOCK);
//
//		switch (mb->hdr.type) {
//		case OS_MESG_TYPE_VRETRACE:
//			__osViSwapContext();
//			retrace--;
//
//			if (retrace == 0) {
//				vc = __osViGetCurrentContext();
//
//				if (vc->msgq != NULL) {
//					osSendMesg(vc->msgq, vc->msg, OS_MESG_NOBLOCK);
//				}
//
//				retrace = vc->retraceCount;
//			}
//
//			__osViIntrCount++;
//
//			if (first) {
//				count = osGetCount();
//				__osCurrentTime = count;
//				first = 0;
//			}
//
//			count = __osBaseCounter;
//			__osBaseCounter = osGetCount();
//			count = __osBaseCounter - count;
//			__osCurrentTime = __osCurrentTime + count;
//			break;
//		case OS_MESG_TYPE_COUNTER:
//			__osTimerInterrupt();
//			break;
//		}
//	}
//}
