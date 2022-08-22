#include <ultra64.h>
#include "lib/tlb.h"
#include "lib/boot.h"
#include "lib/reset.h"
#include "lib/segments.h"
#include "constants.h"
#include "game/menugfx.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/rzip.h"
#include "lib/crash.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/pimgr.h"
#include "lib/videbug.h"
#include "lib/rmon.h"
#include "lib/lib_48150.h"
#include "data.h"
#include "types.h"

OSThread g_RmonThread;
OSThread g_IdleThread;
OSThread g_MainThread;
OSThread g_SchedThread;
OSMesgQueue g_SchedMesgQueue;
OSMesg var8008db48[32];
OSMesgQueue *g_SchedCmdQ;
u32 var8008dbcc;
OSSched g_Sched;
OSScClient var8008dca8;
#if VERSION >= VERSION_NTSC_1_0
u32 g_OsMemSize;
#else
u16 *var800902e4;
u16 var800902e8;
#endif

u32 var8005ce00 = 0;
u32 var8005ce04 = 0;
u32 var8005ce08 = 0;
u32 var8005ce0c = 0;
u8 *g_StackLeftAddrs[7] = {0};
u8 *g_StackRightAddrs[7] = {0};
u8 *g_StackAllocatedPos = (u8 *)0x80400000;
u32 var8005ce4c = 0x00000002;
u32 var8005ce50 = 0x10000000;

extern u8 *_libSegmentStart;
extern u8 *_datazipSegmentRomStart;
extern u8 *_datazipSegmentRomEnd;
extern u8 *_dataSegmentStart;
extern u8 *_inflateSegmentStart;
extern u8 *_inflateSegmentRomStart;
extern u8 *_inflateSegmentRomEnd;

#if VERSION >= VERSION_NTSC_1_0
s32 bootGetMemSize(void)
{
	return g_OsMemSize;
}
#endif

u32 __osGetFpcCsr(void);
u32 __osSetFpcCsr(u32 arg0);

/**
 * Prepares the inflate, .data and lib segments, then creates and starts the
 * main thread.
 *
 * This function relies on the fact that the N64 BIOS loads the first 1MB of ROM
 * data into memory at power on. The inflate, .data and lib segments are already
 * in RAM thanks to this but need to be relocated, and .data and lib need to be
 * unzipped too.
 */
void bootPhase1(void)
{
	s32 datacomplen;
	s32 inflatelen;
	u8 *dataziprom;
	u8 *datazipram;
	u32 *libram;
	u32 *libzipram;
	u32 dataram;
	u32 copylen;
	s32 i;
	s32 numlibwords;
	u32 flags;

#if VERSION >= VERSION_NTSC_1_0
	if (osResetType == RESETTYPE_WARM) {
		g_OsMemSize = *(u32 *)(STACK_START - 8);
	} else {
		*(u32 *)(STACK_START - 8) = g_OsMemSize = osMemSize;
	}
#endif

	// Copy compressed .data and inflate segments
	// .data is copied from ROM to 0x701eb000 - 0x70200000
	// inflate is copied from ROM to 0x70200000 - 0x702013f0
	datacomplen = (s32) &_datazipSegmentRomEnd - (s32) &_datazipSegmentRomStart;
#if VERSION >= VERSION_NTSC_1_0
	if (1);
#endif
	inflatelen = (s32) &_inflateSegmentRomEnd - (s32) &_inflateSegmentRomStart;
	copylen = datacomplen + inflatelen;
	libram = (u32 *) ((u32) &_libSegmentStart + 0x2000);
	libzipram = (u32 *) 0x70280000;
	dataziprom = (u8 *) ((s32) &_datazipSegmentRomStart | 0x70000000);
	datazipram = (u8 *) (0x70200000 - datacomplen);
	dataram = (u32) &_dataSegmentStart;

	for (i = copylen - 1; i >= 0; i--) {
		datazipram[i] = dataziprom[i];
	}

	// Copy the compressed part of lib to 0x70280000.
	// lib is compressed from 2KB onwards.
	// It's assumed that lib's compressed length is less than 75000 words.
	// This is fine, as it's about half that.
	numlibwords = 75000;

	for (i = 0; i < numlibwords; i++) {
		libzipram[i] = libram[i];
	}

	// Inflate compressed part of lib
	segInflate((void *) libzipram, (void *) libram, (void *) 0x80300000);

	// Inflate .data
	segInflate((void *) datazipram, (void *) dataram, (void *) 0x80300000);

#if PIRACYCHECKS
	if (IO_READ(0xa00002e8) != 0xc86e2000) {
		while (1);
	}
#endif

	tlbUnmapRange(1, NTLBENTRIES);

	// Clear the stack allocation pointers
	for (i = 0; i < ARRAYCOUNT(g_StackLeftAddrs); i++) {
		g_StackLeftAddrs[i] = NULL;
		g_StackRightAddrs[i] = NULL;
	}

	osInitialize();

	// Write all data memory cache into physical memory
	osWritebackDCacheAll();

	// Invalidate all instruction cache
	osInvalICache((void *) 0x80000000, ICACHE_SIZE);

	// Configure the floating point unit
	flags = __osGetFpcCsr();
	flags |= FPCSR_EI; // enable inexact operation
	flags |= FPCSR_EO; // enable overflow
	flags |= FPCSR_EZ; // enable division by zero
	flags |= FPCSR_EV; // enable invalid operation

	__osSetFpcCsr(flags);

#if VERSION < VERSION_NTSC_1_0
	var800902e4 = (void *) 0xbc000c02;
	var800902e8 = 0x4040;
	*(s16 *) 0xbc000c02 = 0x4040;
#endif

	// Create and start the main thread
	osCreateThread(&g_MainThread, THREAD_MAIN, bootPhase2, NULL, bootAllocateStack(THREAD_MAIN, STACKSIZE_MAIN), THREADPRI_MAIN);
	osStartThread(&g_MainThread);
}

/**
 * Allocate stack space for the given thread ID.
 *
 * Each allocation is aligned to 16 bytes.
 *
 * Allocations start from the end of onboard memory (0x80400000) and are
 * allocated right to left.
 *
 * The returned address leaves 8 bytes free on the right side of the stack,
 * presumably for identification purposes. So the actual stack space available
 * can be 8 bytes above or below what was requested.
 *
 * The stack is initialised with the thread's ID. This makes it easier to
 * identify in memory and detect when a stack overflow has occurred.
 */
void *bootAllocateStack(s32 threadid, s32 size)
{
	u8 *ptr8;
	u32 *ptr32;
	s32 i;
	s32 j;
	u8 *tmp;

	g_StackRightAddrs[threadid] = g_StackAllocatedPos;
	size = (size + 0xf) & 0xfffffff0;

	g_StackAllocatedPos -= size;
	g_StackLeftAddrs[threadid] = (tmp = g_StackAllocatedPos);

	ptr8 = g_StackAllocatedPos;

	for (i = 0; i < size; i++) {
		ptr8[i] = ((0xf - (threadid & 0xf)) << 4) | (threadid & 0xf);
	}

#if VERSION < VERSION_NTSC_1_0
	// Mark the first 8 words specially
	ptr32 = (u32 *)g_StackLeftAddrs[threadid];

	for (j = 0; j < 8; j++) {
		*ptr32 = 0xdeadbabe;
		ptr32++;
	}
#endif

	return g_StackAllocatedPos + size - 8;
}

#if VERSION < VERSION_NTSC_1_0
u8 *bootGetStackPos(void)
{
	return g_StackAllocatedPos;
}
#endif

#if VERSION < VERSION_NTSC_1_0
void func00001978(void)
{
	var8005ce4c = 1;
	var8005ce50 = 0x10000000;
}
#endif

void idleproc(void *data)
{
	while (true);
}

void bootCreateIdleThread(void)
{
	osCreateThread(&g_IdleThread, THREAD_IDLE, idleproc, NULL, bootAllocateStack(THREAD_IDLE, STACKSIZE_IDLE), THREADPRI_IDLE);
	osStartThread(&g_IdleThread);
}

void bootCreateRmonThread(void)
{
	osCreateThread(&g_RmonThread, THREAD_RMON, rmonproc, NULL, bootAllocateStack(THREAD_RMON, STACKSIZE_RMON), THREADPRI_RMON);
	osStartThread(&g_RmonThread);
}

void bootCreateSchedThread(void)
{
	osCreateMesgQueue(&g_SchedMesgQueue, var8008db48, ARRAYCOUNT(var8008db48));

	if (osTvType == OS_TV_MPAL) {
		osCreateScheduler(&g_Sched, &g_SchedThread, OS_VI_MPAL_LAN1, 1);
	} else {
		osCreateScheduler(&g_Sched, &g_SchedThread, OS_VI_NTSC_LAN1, 1);
	}

	osScAddClient(&g_Sched, &var8008dca8, &g_SchedMesgQueue, 0);
	g_SchedCmdQ = osScGetCmdQ(&g_Sched);
}

void bootPhase2(void *arg)
{
	bootCreateIdleThread();
	videbugCreate();
	pimgrCreate();
	bootCreateRmonThread();

	if (argsParseDebugArgs()) {
		osStopThread(NULL);
	}

	osSetThreadPri(0, THREADPRI_MAIN);
	bootCreateSchedThread();
	mainProc();
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00001b70nb
/*     1b70:	3c048006 */ 	lui	$a0,0x8006
/*     1b74:	3c068006 */ 	lui	$a2,0x8006
/*     1b78:	24c6e5ac */ 	addiu	$a2,$a2,-6740
/*     1b7c:	2484e590 */ 	addiu	$a0,$a0,-6768
/*     1b80:	00001025 */ 	move	$v0,$zero
/*     1b84:	240a0007 */ 	li	$t2,0x7
/*     1b88:	2409000f */ 	li	$t1,0xf
.L00001b8c:
/*     1b8c:	8c830000 */ 	lw	$v1,0x0($a0)
/*     1b90:	24840004 */ 	addiu	$a0,$a0,0x4
/*     1b94:	8cc50000 */ 	lw	$a1,0x0($a2)
/*     1b98:	10600011 */ 	beqz	$v1,.L00001be0
/*     1b9c:	3047000f */ 	andi	$a3,$v0,0xf
/*     1ba0:	90780020 */ 	lbu	$t8,0x20($v1)
/*     1ba4:	01277023 */ 	subu	$t6,$t1,$a3
/*     1ba8:	000e7900 */ 	sll	$t7,$t6,0x4
/*     1bac:	01e74025 */ 	or	$t0,$t7,$a3
/*     1bb0:	1518000b */ 	bne	$t0,$t8,.L00001be0
/*     1bb4:	24630020 */ 	addiu	$v1,$v1,0x20
/*     1bb8:	0065082b */ 	sltu	$at,$v1,$a1
/*     1bbc:	50200009 */ 	beqzl	$at,.L00001be4
/*     1bc0:	24420001 */ 	addiu	$v0,$v0,0x1
/*     1bc4:	90790001 */ 	lbu	$t9,0x1($v1)
.L00001bc8:
/*     1bc8:	24630001 */ 	addiu	$v1,$v1,0x1
/*     1bcc:	0065082b */ 	sltu	$at,$v1,$a1
/*     1bd0:	55190004 */ 	bnel	$t0,$t9,.L00001be4
/*     1bd4:	24420001 */ 	addiu	$v0,$v0,0x1
/*     1bd8:	5420fffb */ 	bnezl	$at,.L00001bc8
/*     1bdc:	90790001 */ 	lbu	$t9,0x1($v1)
.L00001be0:
/*     1be0:	24420001 */ 	addiu	$v0,$v0,0x1
.L00001be4:
/*     1be4:	144affe9 */ 	bne	$v0,$t2,.L00001b8c
/*     1be8:	24c60004 */ 	addiu	$a2,$a2,0x4
/*     1bec:	03e00008 */ 	jr	$ra
/*     1bf0:	00000000 */ 	nop
);
#endif

#if VERSION < VERSION_NTSC_1_0
const char var700539b0nb[] = "Stack overflow thread %d";

GLOBAL_ASM(
glabel func00001bf4nb
/*     1bf4:	27bdff28 */ 	addiu	$sp,$sp,-216
/*     1bf8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     1bfc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     1c00:	afb40028 */ 	sw	$s4,0x28($sp)
/*     1c04:	afb70034 */ 	sw	$s7,0x34($sp)
/*     1c08:	afb60030 */ 	sw	$s6,0x30($sp)
/*     1c0c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     1c10:	afb20020 */ 	sw	$s2,0x20($sp)
/*     1c14:	3c14dead */ 	lui	$s4,0xdead
/*     1c18:	3c157005 */ 	lui	$s5,0x7005
/*     1c1c:	3c1e8006 */ 	lui	$s8,0x8006
/*     1c20:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     1c24:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     1c28:	afb00018 */ 	sw	$s0,0x18($sp)
/*     1c2c:	27dee590 */ 	addiu	$s8,$s8,-6768
/*     1c30:	26b539b0 */ 	addiu	$s5,$s5,0x39b0
/*     1c34:	3694babe */ 	ori	$s4,$s4,0xbabe
/*     1c38:	27b2004c */ 	addiu	$s2,$sp,0x4c
/*     1c3c:	00009825 */ 	move	$s3,$zero
/*     1c40:	24160045 */ 	li	$s6,0x45
/*     1c44:	24170008 */ 	li	$s7,0x8
.L00001c48:
/*     1c48:	8fc20000 */ 	lw	$v0,0x0($s8)
/*     1c4c:	00008825 */ 	move	$s1,$zero
/*     1c50:	10400010 */ 	beqz	$v0,.L00001c94
/*     1c54:	00408025 */ 	move	$s0,$v0
.L00001c58:
/*     1c58:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*     1c5c:	528e000b */ 	beql	$s4,$t6,.L00001c8c
/*     1c60:	26310001 */ 	addiu	$s1,$s1,0x1
/*     1c64:	0c0006dc */ 	jal	func00001b70nb
/*     1c68:	00000000 */ 	nop
/*     1c6c:	02402025 */ 	move	$a0,$s2
/*     1c70:	02a02825 */ 	move	$a1,$s5
/*     1c74:	0c004fc1 */ 	jal	sprintf
/*     1c78:	02603025 */ 	move	$a2,$s3
/*     1c7c:	0c003074 */ 	jal	crashSetMessage
/*     1c80:	02402025 */ 	move	$a0,$s2
/*     1c84:	a0160000 */ 	sb	$s6,0x0($zero)
/*     1c88:	26310001 */ 	addiu	$s1,$s1,0x1
.L00001c8c:
/*     1c8c:	1637fff2 */ 	bne	$s1,$s7,.L00001c58
/*     1c90:	26100004 */ 	addiu	$s0,$s0,0x4
.L00001c94:
/*     1c94:	26730001 */ 	addiu	$s3,$s3,0x1
/*     1c98:	24010007 */ 	li	$at,0x7
/*     1c9c:	1661ffea */ 	bne	$s3,$at,.L00001c48
/*     1ca0:	27de0004 */ 	addiu	$s8,$s8,0x4
/*     1ca4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     1ca8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     1cac:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     1cb0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     1cb4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     1cb8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     1cbc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     1cc0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     1cc4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     1cc8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     1ccc:	03e00008 */ 	jr	$ra
/*     1cd0:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#endif
