#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/boot.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

OSThread g_FaultThread;
u8 g_FaultStack[STACKSIZE_FAULT];
OSMesgQueue g_FaultMesgQueue;
OSMesg g_FaultMesg;

u32 var8005d5b0 = 0;
s16 g_CrashCurX = 0;
s16 g_CrashCurY = 0;

struct crashdescription {
	u32 mask;
	u32 value;
	const char *text;
};

struct crashdescription g_CrashCauseDescriptions[] = {
	{ CAUSE_BD,      CAUSE_BD,    "BD"                                              },
    { CAUSE_IP8,     CAUSE_IP8,   "IP8"                                             },
    { CAUSE_IP7,     CAUSE_IP7,   "IP7"                                             },
    { CAUSE_IP6,     CAUSE_IP6,   "IP6"                                             },
    { CAUSE_IP5,     CAUSE_IP5,   "IP5"                                             },
    { CAUSE_IP4,     CAUSE_IP4,   "IP4"                                             },
    { CAUSE_IP3,     CAUSE_IP3,   "IP3"                                             },
    { CAUSE_SW2,     CAUSE_SW2,   "IP2"                                             },
    { CAUSE_SW1,     CAUSE_SW1,   "IP1"                                             },
    { CAUSE_EXCMASK, EXC_INT,     "Int"                                             },
    { CAUSE_EXCMASK, EXC_MOD,     "TLBmod"                                          },
    { CAUSE_EXCMASK, EXC_RMISS,   "TLBload"                                         },
    { CAUSE_EXCMASK, EXC_WMISS,   "TLBstore"                                        },
    { CAUSE_EXCMASK, EXC_RADE,    "Address error on load or instruction fetch"      },
    { CAUSE_EXCMASK, EXC_WADE,    "Address error on store"                          },
    { CAUSE_EXCMASK, EXC_IBE,     "Bus error exception on instruction fetch"        },
    { CAUSE_EXCMASK, EXC_DBE,     "Bus error exception on data reference"           },
    { CAUSE_EXCMASK, EXC_SYSCALL, "Syscall"                                         },
    { CAUSE_EXCMASK, EXC_BREAK,   "Brk"                                             },
    { CAUSE_EXCMASK, EXC_II,      "Reserved instruction"                            },
    { CAUSE_EXCMASK, EXC_CPU,     "Cop unusable"                                    },
    { CAUSE_EXCMASK, EXC_OV,      "Overflow"                                        },
    { CAUSE_EXCMASK, EXC_TRAP,    "Trap"                                            },
    { CAUSE_EXCMASK, EXC_VCEI,    "Virtual coherency exception on intruction fetch" },
    { CAUSE_EXCMASK, EXC_FPE,     "Fp exception"                                    },
    { CAUSE_EXCMASK, EXC_WATCH,   "Watchpoint"                                      },
    { CAUSE_EXCMASK, EXC_VCED,    "Virtual coherency exception on data reference"   },
    { 0,             0,           ""                                                },
};

struct crashdescription g_CrashSrDescriptions[] = {
	{ SR_CU3,      SR_CU3,     "CU3" },
	{ SR_CU2,      SR_CU2,     "CU2" },
	{ SR_CU1,      SR_CU1,     "CU1" },
	{ SR_CU0,      SR_CU0,     "CU0" },
	{ SR_RP,       SR_RP,      "RP"  },
	{ SR_FR,       SR_FR,      "FR"  },
	{ SR_RE,       SR_RE,      "RE"  },
	{ SR_BEV,      SR_BEV,     "BEV" },
	{ SR_TS,       SR_TS,      "TS"  },
	{ SR_SR,       SR_SR,      "SR"  },
	{ SR_CH,       SR_CH,      "CH"  },
	{ SR_CE,       SR_CE,      "CE"  },
	{ SR_DE,       SR_DE,      "DE"  },
	{ SR_IBIT8,    SR_IBIT8,   "IM8" },
	{ SR_IBIT7,    SR_IBIT7,   "IM7" },
	{ SR_IBIT6,    SR_IBIT6,   "IM6" },
	{ SR_IBIT5,    SR_IBIT5,   "IM5" },
	{ SR_IBIT4,    SR_IBIT4,   "IM4" },
	{ SR_IBIT3,    SR_IBIT3,   "IM3" },
	{ SR_IBIT2,    SR_IBIT2,   "IM2" },
	{ SR_IBIT1,    SR_IBIT1,   "IM1" },
	{ SR_KX,       SR_KX,      "KX"  },
	{ SR_SX,       SR_SX,      "SX"  },
	{ SR_UX,       SR_UX,      "UX"  },
	{ SR_KSU_MASK, SR_KSU_USR, "USR" },
	{ SR_KSU_MASK, SR_KSU_SUP, "SUP" },
	{ SR_KSU_MASK, SR_KSU_KER, "KER" },
	{ SR_ERL,      SR_ERL,     "ERL" },
	{ SR_EXL,      SR_EXL,     "EXL" },
	{ SR_IE,       SR_IE,      "IE"  },
	{ 0,           0,          ""    },
};

struct crashdescription g_CrashFpcsrDescriptions[] = {
	{ FPCSR_FS,      FPCSR_FS,    "FS"            },
	{ FPCSR_C,       FPCSR_C,     "C"             },
	{ FPCSR_CE,      FPCSR_CE,    "Unimplemented" },
	{ FPCSR_CV,      FPCSR_CV,    "Invalid op"    },
	{ FPCSR_CZ,      FPCSR_CZ,    "/ by 0.0"      },
	{ FPCSR_CO,      FPCSR_CO,    "Overflow"      },
	{ FPCSR_CU,      FPCSR_CU,    "Underflow"     },
	{ FPCSR_CI,      FPCSR_CI,    "Inexact op"    },
	{ FPCSR_EV,      FPCSR_EV,    "EV"            },
	{ FPCSR_EZ,      FPCSR_EZ,    "EZ"            },
	{ FPCSR_EO,      FPCSR_EO,    "EO"            },
	{ FPCSR_EU,      FPCSR_EU,    "EU"            },
	{ FPCSR_EI,      FPCSR_EI,    "EI"            },
	{ FPCSR_FV,      FPCSR_FV,    "FV"            },
	{ FPCSR_FZ,      FPCSR_FZ,    "FZ"            },
	{ FPCSR_FO,      FPCSR_FO,    "FO"            },
	{ FPCSR_FU,      FPCSR_FU,    "FU"            },
	{ FPCSR_FI,      FPCSR_FI,    "FI"            },
	{ FPCSR_RM_MASK, FPCSR_RM_RN, "RN"            },
	{ FPCSR_RM_MASK, FPCSR_RM_RZ, "RZ"            },
	{ FPCSR_RM_MASK, FPCSR_RM_RP, "RP"            },
	{ FPCSR_RM_MASK, FPCSR_RM_RM, "RM"            },
	{ 0,             0,           ""              },
};

char (*g_CrashCharBuffer)[71] = NULL;
u16 *g_CrashFrameBuffer = NULL;

extern u32 _libSegmentStart;
extern u32 _libSegmentEnd;

void faultproc(void *arg0);
u32 crashRender(OSThread *thread, u32 *callstack, s32 *tracelen);
void crashPrintDescription(u32 mask, char *label, struct crashdescription *descriptions);

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000c1d0nb
/*     c1d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c1d4:	00802825 */ 	or	$a1,$a0,$zero
/*     c1d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c1dc:	3c048009 */ 	lui	$a0,0x8009
/*     c1e0:	24844e70 */ 	addiu	$a0,$a0,0x4e70
/*     c1e4:	0c004e86 */ 	jal	strncpy
/*     c1e8:	24060046 */ 	addiu	$a2,$zero,0x46
/*     c1ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c1f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     c1f4:	3c018006 */ 	lui	$at,0x8006
/*     c1f8:	a02eed50 */ 	sb	$t6,-0x12b0($at)
/*     c1fc:	03e00008 */ 	jr	$ra
/*     c200:	27bd0018 */ 	addiu	$sp,$sp,0x18
);
#endif

void faultCreateThread2(void)
{
	osCreateMesgQueue(&g_FaultMesgQueue, &g_FaultMesg, 1);
	osCreateThread(&g_FaultThread, THREAD_FAULT, faultproc, NULL, &g_FaultStack[1024], THREADPRI_FAULT);
	osStartThread(&g_FaultThread);
}

void faultproc(void *arg0)
{
	OSMesg msg = 0;
	OSIntMask mask;
	u32 callstack[10];
	s32 tracelen;
	static OSThread *thread;
	static u32 var80094ad0;

	osSetEventMesg(OS_EVENT_FAULT, &g_FaultMesgQueue, (OSMesg) 16);
	var80094ad0 = 0;

	while (true) {
		do {
			osRecvMesg(&g_FaultMesgQueue, &msg, 1);
			mask = osSetIntMask(1);
			thread = __osGetCurrFaultedThread();
		} while (!thread);

		osSetIntMask(mask);

#if VERSION < VERSION_NTSC_1_0
		crashRender(thread, callstack, &tracelen);
		func00001b1c(true);
#endif
	}
}

/**
 * Given a pointer to an instruction and a stack frame pointer, attempt to find
 * the calling function. Return the address of the caller's stack frame and
 * populate regs with stack addresses where that register was saved. This can be
 * used to retrieve the RA value and invoke crashGetParentStackFrame again to
 * build a backtrace.
 *
 * origptr is a pointer to an instruction. This should be either the value of
 *     the PC register of the faulted thread, or an RA register if searching a
 *     parent.
 * minaddr is the memory address of the start of the code segment,
 *     ie. 0x70001050. This is used to prevent the function from walking out of
 *     the code segment.
 * origsp is the address of the stack frame for the given origptr.
 * regs is a pointer to an array of 32 words.
 *
 * The function works by walking backwards one instruction at a time, looking
 * for stack frame adjustments and stores of $ra to the stack. Once both of
 * these are are found, the function returns with this information.
 *
 * The function will return 0 if it can't reliably find the caller. This will
 * happen if the function being analysed didn't adjust the stack pointer or
 * store $ra in the stack. It can also fail if the function being analysed uses
 * returns within branches.
 */
u32 crashGetParentStackFrame(u32 *origptr, u32 *minaddr, u32 origsp, u32 *regs)
{
	u32 sp = origsp;
	u32 *ptr;
	bool foundaddsp = false;
	bool foundra = false;
	s32 regid;
	u32 instruction;
	s16 value;

	// Clear the regs array (note: reusing the instruction variable here)
	for (instruction = 0; instruction < 32; instruction++) regs[instruction] = 0;

	// Walk backwards through the instructions
	for (ptr = origptr; ptr >= minaddr; ptr--) {
		instruction = *ptr;
		value = instruction & 0xffff;

		if ((instruction & 0xffff0000) == 0x27bd0000) {
			// Found an addiu $sp, $sp, <amount> instruction, which adjusts the
			// stack pointer. These can exist near the start and end of any
			// function. The "add" at the start is done with a negative value
			// which increases the size of the stack, as the stack expands to
			// the left. This function is interested in these negative adds,
			// because it needs to reverse it and move the sp variable forward
			// to the next stack frame (the frame of the caller).

			foundaddsp = true;

			if (value > 0) {
				// Found the addiu sp at the end of the function. It's pretty
				// rare to crash (or jump elsewhere) after restoring the sp,
				// so this situation is not supported by this function.
				break;
			}

			// Change sp to point to the caller's stack frame
			sp -= (value >> 2) * 4;

			if (foundra) {
				break;
			}
		} else if ((instruction & 0xffe00000) == 0xafa00000) {
			// Found a store word instruction that stores to the stack.
			// The encoding of this instruction is:
			//
			//     oooooodd dddsssss iiiiiiii iiiiiiii
			//
			// Where:
			//     o is the opcode (already known to be sw).
			//     d is the destination register (already known to be $sp)
			//     s is the source register
			//     i is the offset to store to
			//
			// This looks for a store from $ra to the stack, so the value can
			// be read from the stack and used to find the caller's address.

			regid = (instruction >> 16) & 0x1f;
			regs[regid] = sp + (value >> 2) * 4;

			if (regid == 31) {
				foundra = true;
			}

			if (foundaddsp && foundra) {
				break;
			}
		} else if (instruction == 0x03e00008) {
			// Found a jr $ra statement, which is a return. This will happen if
			// this loop has walked out of the current function and into the one
			// prior to it, so bail.

			// It can also happen if the function has return statements within
			// branches, but handling these correctly would involve a lot of
			// complexity so that's unsupported. Because of this, this function
			// can end the backtrace prematurely if it encounters a function
			// that does this.
			break;
		}
	}

	if (foundaddsp && foundra) {
		return sp;
	}

	return 0;
}

bool crashIsReturnAddress(u32 *instruction)
{
	if (((u32)instruction % 4) == 0
			&& (u32)instruction >= (u32)boot
			&& (u32)instruction <= (u32)&_libSegmentEnd) {
		// This condition can never pass because 9 is masked out
		if ((instruction[-2] & 0xfc00003c) == 9) {
			return true;
		}

		// If 2 instructions earlier was a jal
		if ((instruction[-2] & 0xfc000000) == 0x0c000000) {
			return true;
		}
	}

	return false;
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000c4f0nb
/*     c4f0:	90820000 */ 	lbu	$v0,0x0($a0)
/*     c4f4:	00001825 */ 	or	$v1,$zero,$zero
/*     c4f8:	24840001 */ 	addiu	$a0,$a0,0x1
/*     c4fc:	10400009 */ 	beqz	$v0,.NB0000c524
/*     c500:	00000000 */ 	sll	$zero,$zero,0x0
/*     c504:	24630001 */ 	addiu	$v1,$v1,0x1
.NB0000c508:
/*     c508:	28610100 */ 	slti	$at,$v1,0x100
/*     c50c:	10200005 */ 	beqz	$at,.NB0000c524
/*     c510:	00000000 */ 	sll	$zero,$zero,0x0
/*     c514:	90820000 */ 	lbu	$v0,0x0($a0)
/*     c518:	24840001 */ 	addiu	$a0,$a0,0x1
/*     c51c:	5440fffa */ 	bnezl	$v0,.NB0000c508
/*     c520:	24630001 */ 	addiu	$v1,$v1,0x1
.NB0000c524:
/*     c524:	03e00008 */ 	jr	$ra
/*     c528:	00601025 */ 	or	$v0,$v1,$zero
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000c52cnb
/*     c52c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     c530:	afa40020 */ 	sw	$a0,0x20($sp)
/*     c534:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c538:	3c048009 */ 	lui	$a0,0x8009
/*     c53c:	24847118 */ 	addiu	$a0,$a0,0x7118
/*     c540:	8fa50020 */ 	lw	$a1,0x20($sp)
/*     c544:	0c003664 */ 	jal	dmaExec
/*     c548:	24060060 */ 	addiu	$a2,$zero,0x60
/*     c54c:	3c0e8009 */ 	lui	$t6,0x8009
/*     c550:	8dce7118 */ 	lw	$t6,0x7118($t6)
/*     c554:	3c028009 */ 	lui	$v0,0x8009
/*     c558:	3c018009 */ 	lui	$at,0x8009
/*     c55c:	3c0f8009 */ 	lui	$t7,0x8009
/*     c560:	24427110 */ 	addiu	$v0,$v0,0x7110
/*     c564:	25e4711c */ 	addiu	$a0,$t7,0x711c
/*     c568:	ac2e710c */ 	sw	$t6,0x710c($at)
/*     c56c:	0c00313c */ 	jal	func0000c4f0nb
/*     c570:	ac440000 */ 	sw	$a0,0x0($v0)
/*     c574:	3c048009 */ 	lui	$a0,0x8009
/*     c578:	8c847110 */ 	lw	$a0,0x7110($a0)
/*     c57c:	3c018009 */ 	lui	$at,0x8009
/*     c580:	0044c021 */ 	addu	$t8,$v0,$a0
/*     c584:	27190001 */ 	addiu	$t9,$t8,0x1
/*     c588:	0c00313c */ 	jal	func0000c4f0nb
/*     c58c:	ac397114 */ 	sw	$t9,0x7114($at)
/*     c590:	3c048009 */ 	lui	$a0,0x8009
/*     c594:	8c847114 */ 	lw	$a0,0x7114($a0)
/*     c598:	0c00313c */ 	jal	func0000c4f0nb
/*     c59c:	afa20018 */ 	sw	$v0,0x18($sp)
/*     c5a0:	8fa80020 */ 	lw	$t0,0x20($sp)
/*     c5a4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*     c5a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c5ac:	00484821 */ 	addu	$t1,$v0,$t0
/*     c5b0:	012a1821 */ 	addu	$v1,$t1,$t2
/*     c5b4:	24630006 */ 	addiu	$v1,$v1,0x6
/*     c5b8:	306b0003 */ 	andi	$t3,$v1,0x3
/*     c5bc:	11600003 */ 	beqz	$t3,.NB0000c5cc
/*     c5c0:	00602025 */ 	or	$a0,$v1,$zero
/*     c5c4:	34640003 */ 	ori	$a0,$v1,0x3
/*     c5c8:	24840001 */ 	addiu	$a0,$a0,0x1
.NB0000c5cc:
/*     c5cc:	00801025 */ 	or	$v0,$a0,$zero
/*     c5d0:	03e00008 */ 	jr	$ra
/*     c5d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000c5d8nb
/*     c5d8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     c5dc:	afb30020 */ 	sw	$s3,0x20($sp)
/*     c5e0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     c5e4:	3c0200e0 */ 	lui	$v0,0xe0
/*     c5e8:	34530004 */ 	ori	$s3,$v0,0x4
/*     c5ec:	afb10018 */ 	sw	$s1,0x18($sp)
/*     c5f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*     c5f4:	3c128009 */ 	lui	$s2,0x8009
/*     c5f8:	00808825 */ 	or	$s1,$a0,$zero
/*     c5fc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     c600:	02608025 */ 	or	$s0,$s3,$zero
/*     c604:	2652710c */ 	addiu	$s2,$s2,0x710c
.NB0000c608:
/*     c608:	0c00314b */ 	jal	func0000c52cnb
/*     c60c:	02002025 */ 	or	$a0,$s0,$zero
/*     c610:	8e430000 */ 	lw	$v1,0x0($s2)
/*     c614:	0223082b */ 	sltu	$at,$s1,$v1
/*     c618:	14200007 */ 	bnez	$at,.NB0000c638
/*     c61c:	00000000 */ 	sll	$zero,$zero,0x0
/*     c620:	14600003 */ 	bnez	$v1,.NB0000c630
/*     c624:	02009825 */ 	or	$s3,$s0,$zero
/*     c628:	10000006 */ 	beqz	$zero,.NB0000c644
/*     c62c:	00001025 */ 	or	$v0,$zero,$zero
.NB0000c630:
/*     c630:	1000fff5 */ 	beqz	$zero,.NB0000c608
/*     c634:	00408025 */ 	or	$s0,$v0,$zero
.NB0000c638:
/*     c638:	0c00314b */ 	jal	func0000c52cnb
/*     c63c:	02602025 */ 	or	$a0,$s3,$zero
/*     c640:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0000c644:
/*     c644:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     c648:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     c64c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     c650:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     c654:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     c658:	03e00008 */ 	jr	$ra
/*     c65c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000c660nb
/*     c660:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c664:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c668:	0c00314b */ 	jal	func0000c52cnb
/*     c66c:	3c0400e0 */ 	lui	$a0,0xe0
/*     c670:	3c028009 */ 	lui	$v0,0x8009
/*     c674:	8c42710c */ 	lw	$v0,0x710c($v0)
/*     c678:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c67c:	3c018264 */ 	lui	$at,0x8264
/*     c680:	342175be */ 	ori	$at,$at,0x75be
/*     c684:	00417026 */ 	xor	$t6,$v0,$at
/*     c688:	2dc20001 */ 	sltiu	$v0,$t6,0x1
/*     c68c:	03e00008 */ 	jr	$ra
/*     c690:	27bd0018 */ 	addiu	$sp,$sp,0x18
);
#endif

#if VERSION < VERSION_NTSC_1_0
const char var70053fd0nb[] = "%.49s";
const char var70053fd8nb[] = "???";

GLOBAL_ASM(
glabel func0000c694nb
/*     c694:	3c078009 */ 	lui	$a3,0x8009
/*     c698:	8ce77110 */ 	lw	$a3,0x7110($a3)
/*     c69c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c6a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c6a4:	00002825 */ 	or	$a1,$zero,$zero
/*     c6a8:	00001025 */ 	or	$v0,$zero,$zero
/*     c6ac:	24060004 */ 	addiu	$a2,$zero,0x4
/*     c6b0:	00e01825 */ 	or	$v1,$a3,$zero
.NB0000c6b4:
/*     c6b4:	90640000 */ 	lbu	$a0,0x0($v1)
/*     c6b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*     c6bc:	28810021 */ 	slti	$at,$a0,0x21
/*     c6c0:	14200004 */ 	bnez	$at,.NB0000c6d4
/*     c6c4:	28810080 */ 	slti	$at,$a0,0x80
/*     c6c8:	10200002 */ 	beqz	$at,.NB0000c6d4
/*     c6cc:	00000000 */ 	sll	$zero,$zero,0x0
/*     c6d0:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0000c6d4:
/*     c6d4:	1446fff7 */ 	bne	$v0,$a2,.NB0000c6b4
/*     c6d8:	24630001 */ 	addiu	$v1,$v1,0x1
/*     c6dc:	14a60007 */ 	bne	$a1,$a2,.NB0000c6fc
/*     c6e0:	3c047005 */ 	lui	$a0,0x7005
/*     c6e4:	3c047005 */ 	lui	$a0,0x7005
/*     c6e8:	24843fd0 */ 	addiu	$a0,$a0,0x3fd0
/*     c6ec:	0c00c47d */ 	jal	crashPrint
/*     c6f0:	00e02825 */ 	or	$a1,$a3,$zero
/*     c6f4:	10000004 */ 	beqz	$zero,.NB0000c708
/*     c6f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0000c6fc:
/*     c6fc:	0c00c47d */ 	jal	crashPrint
/*     c700:	24843fd8 */ 	addiu	$a0,$a0,0x3fd8
/*     c704:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0000c708:
/*     c708:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c70c:	03e00008 */ 	jr	$ra
/*     c710:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION < VERSION_NTSC_1_0
const char var70053fdcnb[] = "%.41s";
const char var70053fe4nb[] = "???";

GLOBAL_ASM(
glabel func0000c714nb
/*     c714:	3c078009 */ 	lui	$a3,0x8009
/*     c718:	8ce77114 */ 	lw	$a3,0x7114($a3)
/*     c71c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c720:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c724:	00002825 */ 	or	$a1,$zero,$zero
/*     c728:	00001025 */ 	or	$v0,$zero,$zero
/*     c72c:	24060004 */ 	addiu	$a2,$zero,0x4
/*     c730:	00e01825 */ 	or	$v1,$a3,$zero
.NB0000c734:
/*     c734:	90640000 */ 	lbu	$a0,0x0($v1)
/*     c738:	24420001 */ 	addiu	$v0,$v0,0x1
/*     c73c:	28810021 */ 	slti	$at,$a0,0x21
/*     c740:	14200004 */ 	bnez	$at,.NB0000c754
/*     c744:	28810080 */ 	slti	$at,$a0,0x80
/*     c748:	10200002 */ 	beqz	$at,.NB0000c754
/*     c74c:	00000000 */ 	sll	$zero,$zero,0x0
/*     c750:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0000c754:
/*     c754:	1446fff7 */ 	bne	$v0,$a2,.NB0000c734
/*     c758:	24630001 */ 	addiu	$v1,$v1,0x1
/*     c75c:	14a60007 */ 	bne	$a1,$a2,.NB0000c77c
/*     c760:	3c047005 */ 	lui	$a0,0x7005
/*     c764:	3c047005 */ 	lui	$a0,0x7005
/*     c768:	24843fdc */ 	addiu	$a0,$a0,0x3fdc
/*     c76c:	0c00c47d */ 	jal	crashPrint
/*     c770:	00e02825 */ 	or	$a1,$a3,$zero
/*     c774:	10000004 */ 	beqz	$zero,.NB0000c788
/*     c778:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0000c77c:
/*     c77c:	0c00c47d */ 	jal	crashPrint
/*     c780:	24843fe4 */ 	addiu	$a0,$a0,0x3fe4
/*     c784:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0000c788:
/*     c788:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c78c:	03e00008 */ 	jr	$ra
/*     c790:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION < VERSION_NTSC_1_0
const char var70053fe8nb[] = "%08x";

GLOBAL_ASM(
glabel func0000c794nb
/*     c794:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c798:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c79c:	3c047005 */ 	lui	$a0,0x7005
/*     c7a0:	3c058009 */ 	lui	$a1,0x8009
/*     c7a4:	8ca5710c */ 	lw	$a1,0x710c($a1)
/*     c7a8:	0c00c47d */ 	jal	crashPrint
/*     c7ac:	24843fe8 */ 	addiu	$a0,$a0,0x3fe8
/*     c7b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c7b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c7b8:	03e00008 */ 	jr	$ra
/*     c7bc:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000c7c0nb
/*     c7c0:	3c028009 */ 	lui	$v0,0x8009
/*     c7c4:	03e00008 */ 	jr	$ra
/*     c7c8:	8c42710c */ 	lw	$v0,0x710c($v0)
);
#endif

u32 crashGetStackEnd(u32 sp, s32 tid)
{
	u32 start;
	u32 end;

	if (tid <= 0 || tid > 6U) {
		crashPrint("Bad tid\n");
		return 0;
	}

	start = (u32)g_StackStartAddrs[tid];
	end = (u32)g_StackEndAddrs[tid];

	if (sp >= 0x80000000) {
		return end;
	}

	return (sp & 0xf0000000) | (end - start);
}

u32 crashGetStackStart(u32 sp, s32 tid)
{
	u32 start;

	if (tid <= 0 || tid > 6U) {
		crashPrint("Bad tid\n");
		return 0;
	}

	start = (u32)g_StackStartAddrs[tid];

	if (sp >= 0x80000000) {
		return start;
	}

	return sp & 0xf0000000;
}

bool crashIsDouble(f32 value)
{
	u32 bits = *(u32*)&value;
	u32 fraction = bits & 0x7fffff;
	u8 exponent = (u8)(bits >> 23);

	return fraction == 0 || (exponent != 0 && exponent != 0xff);
}

void crashPrintFloat(s32 index, f32 value)
{
	if (crashIsDouble(value)) {
		crashPrint("%s%s%02d: % .7e ", "", "", index, (f64)value);
	} else {
		u32 bits = *(u32 *)&value;
		crashPrint("%02d: I%d.%03d.%07d ", index, (bits & 0x80000000) >> 31, (bits & 0x7f800000) >> 23, bits & 0x7fffff);
	}
}

void crashPrint2Floats(s32 index, f32 value1, f32 value2)
{
	crashPrintFloat(index, value1);
	crashPrint(" ");

	crashPrintFloat(index + 1, value2);
	crashPrint("\n");
}

void crashPrint3Floats(s32 index, f32 value1, f32 value2, f32 value3)
{
	crashPrintFloat(index, value1);
	crashPrint(" ");

	crashPrintFloat(index + 1, value2);
	crashPrint(" ");

	crashPrintFloat(index + 2, value3);
	crashPrint("\n");
}

#if VERSION >= VERSION_NTSC_1_0
u32 crashRender(OSThread *thread, u32 *callstack, s32 *tracelen)
{
	s32 i;
	u32 ptr;
	u32 *sp;
	u32 regs[32];
	u32 *stackend;
	u32 *stackstart;
	__OSThreadContext *ctx = &thread->context;
	bool done;

	crashPrint("\n\nFAULT-\n");

	if (!g_Vars.fourmeg2player) {
		// Print a stack trace in a dodgy way.
		// It works by iterating through the stack allocation, looking for any
		// values which could potentially be a return address, and prints them.
		u32 *stackend = (u32 *) crashGetStackEnd(ctx->sp, thread->id);
		u32 *sp;
		crashPrint("DodgyStackTrace: %08llx ", ctx->ra & 0xffffffff);
		sp = (u32 *) ctx->sp;

		while (sp < stackend) {
			if (crashIsReturnAddress((u32 *)*sp)) {
				crashPrint("%08x ", *sp);
			}

			sp++;
		}

		crashPrint(".\n");
	}

	crashPrint("%H#@! Another Perfect Crash (tm)\n");

	if (!g_Vars.fourmeg2player) {
		// Print floating point registers
		crashPrint2Floats(0, ctx->fp0.f.f_odd, ctx->fp0.f.f_even);
		crashPrint3Floats(2, ctx->fp2.f.f_odd, ctx->fp2.f.f_even, ctx->fp4.f.f_odd);
		crashPrint3Floats(5, ctx->fp4.f.f_even, ctx->fp6.f.f_odd, ctx->fp6.f.f_even);
		crashPrint3Floats(8, ctx->fp8.f.f_odd, ctx->fp8.f.f_even, ctx->fp10.f.f_odd);
		crashPrint3Floats(11, ctx->fp10.f.f_even, ctx->fp12.f.f_odd, ctx->fp12.f.f_even);
		crashPrint3Floats(14, ctx->fp14.f.f_odd, ctx->fp14.f.f_even, ctx->fp16.f.f_odd);
		crashPrint3Floats(17, ctx->fp16.f.f_even, ctx->fp18.f.f_odd, ctx->fp18.f.f_even);
		crashPrint3Floats(20, ctx->fp20.f.f_odd, ctx->fp20.f.f_even, ctx->fp22.f.f_odd);
		crashPrint3Floats(23, ctx->fp22.f.f_even, ctx->fp24.f.f_odd, ctx->fp24.f.f_even);
		crashPrint3Floats(26, ctx->fp26.f.f_odd, ctx->fp26.f.f_even, ctx->fp28.f.f_odd);
		crashPrint3Floats(29, ctx->fp28.f.f_even, ctx->fp30.f.f_odd, ctx->fp30.f.f_even);
	}

	// Print integer registers
	crashPrint("at 0x%016llx v0 0x%016llx v1 0x%016llx\n", ctx->at, ctx->v0, ctx->v1);
	crashPrint("a0 0x%016llx a1 0x%016llx a2 0x%016llx\n", ctx->a0, ctx->a1, ctx->a2);
	crashPrint("a3 0x%016llx t0 0x%016llx t1 0x%016llx\n", ctx->a3, ctx->t0, ctx->t1);
	crashPrint("t2 0x%016llx t3 0x%016llx t4 0x%016llx\n", ctx->t2, ctx->t3, ctx->t4);
	crashPrint("t5 0x%016llx t6 0x%016llx t7 0x%016llx\n", ctx->t5, ctx->t6, ctx->t7);
	crashPrint("s0 0x%016llx s1 0x%016llx s2 0x%016llx\n", ctx->s0, ctx->s1, ctx->s2);
	crashPrint("s3 0x%016llx s4 0x%016llx s5 0x%016llx\n", ctx->s3, ctx->s4, ctx->s5);
	crashPrint("s6 0x%016llx s7 0x%016llx t8 0x%016llx\n", ctx->s6, ctx->s7, ctx->t8);
	crashPrint("t9 0x%016llx gp 0x%016llx sp 0x%016llx\n", ctx->t9, ctx->gp, ctx->sp);
	crashPrint("s8 0x%016llx ra 0x%016llx\n", ctx->s8, ctx->ra);

	crashPrint("TID %d epc %08x caus %08x fp %08x badv %08x sr %08x\n",
			thread->id, ctx->pc, ctx->cause, ctx->fpcsr, ctx->badvaddr, ctx->sr);

	// Print the address of the faulted instruction, along with the instruction
	// itself and the next three - presumably to help the developer locate it.
	crashPrint("dshex -a %08x %08x %08x %08x %08x\n", ctx->pc,
			((u32 *)ctx->pc)[0],
			((u32 *)ctx->pc)[1],
			((u32 *)ctx->pc)[2],
			((u32 *)ctx->pc)[3]);

	crashPrintDescription(ctx->cause, "cause", g_CrashCauseDescriptions);
	crashPrint(" : ");
	crashPrintDescription(ctx->fpcsr, "fpcsr", g_CrashFpcsrDescriptions);
	crashPrint("\n");

	// Print a proper stack trace
	i = 0;
	done = false;
	sp = (u32 *)ctx->sp;
	stackend = (u32 *) crashGetStackEnd((u32)sp, thread->id);
	stackstart = (u32 *) crashGetStackStart((u32)sp, thread->id);
	ptr = ctx->pc;
	*tracelen = 0;
	crashPrint("nearl: ");

	while (!done) {
		sp = (u32 *) crashGetParentStackFrame((u32 *) ptr, &_libSegmentStart, (u32)sp, regs);
		crashPrint(" %08x ", ptr);

		callstack[*tracelen] = ptr;
		*tracelen = *tracelen + 1;

		if (i == 4) {
			crashPrint("\n       ");
		}

		if (sp == NULL) {
			sp = (u32 *)ctx->sp;
		}

		if (regs[31] == 0) {
			ptr = ctx->ra;
		} else {
			ptr = *(u32 *)(regs[31]);
		}

		if (sp < stackstart || sp >= stackend || stackend == &sp[4] || ptr == 0) {
			break;
		}

		done = i >= 9;
		i++;
	}

	crashPrint("\n");
	crashPrint("\n");

	return 0;
}
#else
const char crashrodata00[] = "\n\nFAULT-\n";
const char crashrodata01[] = "DodgyStackTrace: %08llx ";
const char crashrodata02[] = "%08x ";
const char crashrodata03[] = ".\n";
const char crashrodata04[] = "\nPerfect Crash (tm)\n\n";
const char crashrodata05[] = "at 0x%016llx v0 0x%016llx v1 0x%016llx\n";
const char crashrodata06[] = "a0 0x%016llx a1 0x%016llx a2 0x%016llx\n";
const char crashrodata07[] = "a3 0x%016llx t0 0x%016llx t1 0x%016llx\n";
const char crashrodata08[] = "t2 0x%016llx t3 0x%016llx t4 0x%016llx\n";
const char crashrodata09[] = "t5 0x%016llx t6 0x%016llx t7 0x%016llx\n";
const char crashrodata10[] = "s0 0x%016llx s1 0x%016llx s2 0x%016llx\n";
const char crashrodata11[] = "s3 0x%016llx s4 0x%016llx s5 0x%016llx\n";
const char crashrodata12[] = "s6 0x%016llx s7 0x%016llx t8 0x%016llx\n";
const char crashrodata13[] = "t9 0x%016llx gp 0x%016llx sp 0x%016llx\n";
const char crashrodata14[] = "s8 0x%016llx ra 0x%016llx\n";
const char crashrodata15[] = "TID %d epc %08x cause %08x fp %08x badv %08x sr %08x\n";
const char crashrodata16[] = "dshex -a %08x %08x %08x %08x %08x\n";
const char crashrodata17[] = "cause";
const char crashrodata18[] = " : ";
const char crashrodata19[] = "fpcsr";
const char crashrodata20[] = "\n";
const char crashrodata21[] = "nearl: ";
const char crashrodata22[] = " %08x ";
const char crashrodata23[] = "\n       ";
const char crashrodata24[] = "\n";
const char crashrodata25[] = "\n";

GLOBAL_ASM(
glabel crashRender
/*     ca5c:	27bdff08 */ 	addiu	$sp,$sp,-248
/*     ca60:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*     ca64:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     ca68:	afb40038 */ 	sw	$s4,0x38($sp)
/*     ca6c:	3c047005 */ 	lui	$a0,0x7005
/*     ca70:	00c0a025 */ 	or	$s4,$a2,$zero
/*     ca74:	afb30034 */ 	sw	$s3,0x34($sp)
/*     ca78:	afb20030 */ 	sw	$s2,0x30($sp)
/*     ca7c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*     ca80:	afb00028 */ 	sw	$s0,0x28($sp)
/*     ca84:	afa500fc */ 	sw	$a1,0xfc($sp)
/*     ca88:	0c00c47d */ 	jal	crashPrint
/*     ca8c:	24844050 */ 	addiu	$a0,$a0,0x4050
/*     ca90:	8fa200f8 */ 	lw	$v0,0xf8($sp)
/*     ca94:	24530020 */ 	addiu	$s3,$v0,0x20
/*     ca98:	8e6400d4 */ 	lw	$a0,0xd4($s3)
/*     ca9c:	0c0031f3 */ 	jal	crashGetStackEnd
/*     caa0:	8c450014 */ 	lw	$a1,0x14($v0)
/*     caa4:	8e6700e4 */ 	lw	$a3,0xe4($s3)
/*     caa8:	2401ffff */ 	addiu	$at,$zero,-1
/*     caac:	3c047005 */ 	lui	$a0,0x7005
/*     cab0:	00e1c824 */ 	and	$t9,$a3,$at
/*     cab4:	00409025 */ 	or	$s2,$v0,$zero
/*     cab8:	03203825 */ 	or	$a3,$t9,$zero
/*     cabc:	2484405c */ 	addiu	$a0,$a0,0x405c
/*     cac0:	0c00c47d */ 	jal	crashPrint
/*     cac4:	00003025 */ 	or	$a2,$zero,$zero
/*     cac8:	8e7000d4 */ 	lw	$s0,0xd4($s3)
/*     cacc:	0212082b */ 	sltu	$at,$s0,$s2
/*     cad0:	1020000c */ 	beqz	$at,.NB0000cb04
/*     cad4:	3c117005 */ 	lui	$s1,0x7005
/*     cad8:	26314078 */ 	addiu	$s1,$s1,0x4078
.NB0000cadc:
/*     cadc:	0c00311e */ 	jal	crashIsReturnAddress
/*     cae0:	8e040000 */ 	lw	$a0,0x0($s0)
/*     cae4:	10400003 */ 	beqz	$v0,.NB0000caf4
/*     cae8:	02202025 */ 	or	$a0,$s1,$zero
/*     caec:	0c00c47d */ 	jal	crashPrint
/*     caf0:	8e050000 */ 	lw	$a1,0x0($s0)
.NB0000caf4:
/*     caf4:	26100004 */ 	addiu	$s0,$s0,0x4
/*     caf8:	0212082b */ 	sltu	$at,$s0,$s2
/*     cafc:	1420fff7 */ 	bnez	$at,.NB0000cadc
/*     cb00:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000cb04:
/*     cb04:	3c047005 */ 	lui	$a0,0x7005
/*     cb08:	0c00c47d */ 	jal	crashPrint
/*     cb0c:	24844080 */ 	addiu	$a0,$a0,0x4080
/*     cb10:	3c047005 */ 	lui	$a0,0x7005
/*     cb14:	0c00c47d */ 	jal	crashPrint
/*     cb18:	24844084 */ 	addiu	$a0,$a0,0x4084
/*     cb1c:	00002025 */ 	or	$a0,$zero,$zero
/*     cb20:	8e650114 */ 	lw	$a1,0x114($s3)
/*     cb24:	0c003265 */ 	jal	crashPrint2Floats
/*     cb28:	8e66011c */ 	lw	$a2,0x11c($s3)
/*     cb2c:	24040002 */ 	addiu	$a0,$zero,0x2
/*     cb30:	8e650124 */ 	lw	$a1,0x124($s3)
/*     cb34:	8e66012c */ 	lw	$a2,0x12c($s3)
/*     cb38:	0c00327a */ 	jal	crashPrint3Floats
/*     cb3c:	8e670134 */ 	lw	$a3,0x134($s3)
/*     cb40:	24040005 */ 	addiu	$a0,$zero,0x5
/*     cb44:	8e65013c */ 	lw	$a1,0x13c($s3)
/*     cb48:	8e660144 */ 	lw	$a2,0x144($s3)
/*     cb4c:	0c00327a */ 	jal	crashPrint3Floats
/*     cb50:	8e67014c */ 	lw	$a3,0x14c($s3)
/*     cb54:	24040008 */ 	addiu	$a0,$zero,0x8
/*     cb58:	8e650154 */ 	lw	$a1,0x154($s3)
/*     cb5c:	8e66015c */ 	lw	$a2,0x15c($s3)
/*     cb60:	0c00327a */ 	jal	crashPrint3Floats
/*     cb64:	8e670164 */ 	lw	$a3,0x164($s3)
/*     cb68:	2404000b */ 	addiu	$a0,$zero,0xb
/*     cb6c:	8e65016c */ 	lw	$a1,0x16c($s3)
/*     cb70:	8e660174 */ 	lw	$a2,0x174($s3)
/*     cb74:	0c00327a */ 	jal	crashPrint3Floats
/*     cb78:	8e67017c */ 	lw	$a3,0x17c($s3)
/*     cb7c:	2404000e */ 	addiu	$a0,$zero,0xe
/*     cb80:	8e650184 */ 	lw	$a1,0x184($s3)
/*     cb84:	8e66018c */ 	lw	$a2,0x18c($s3)
/*     cb88:	0c00327a */ 	jal	crashPrint3Floats
/*     cb8c:	8e670194 */ 	lw	$a3,0x194($s3)
/*     cb90:	24040011 */ 	addiu	$a0,$zero,0x11
/*     cb94:	8e65019c */ 	lw	$a1,0x19c($s3)
/*     cb98:	8e6601a4 */ 	lw	$a2,0x1a4($s3)
/*     cb9c:	0c00327a */ 	jal	crashPrint3Floats
/*     cba0:	8e6701ac */ 	lw	$a3,0x1ac($s3)
/*     cba4:	24040014 */ 	addiu	$a0,$zero,0x14
/*     cba8:	8e6501b4 */ 	lw	$a1,0x1b4($s3)
/*     cbac:	8e6601bc */ 	lw	$a2,0x1bc($s3)
/*     cbb0:	0c00327a */ 	jal	crashPrint3Floats
/*     cbb4:	8e6701c4 */ 	lw	$a3,0x1c4($s3)
/*     cbb8:	24040017 */ 	addiu	$a0,$zero,0x17
/*     cbbc:	8e6501cc */ 	lw	$a1,0x1cc($s3)
/*     cbc0:	8e6601d4 */ 	lw	$a2,0x1d4($s3)
/*     cbc4:	0c00327a */ 	jal	crashPrint3Floats
/*     cbc8:	8e6701dc */ 	lw	$a3,0x1dc($s3)
/*     cbcc:	2404001a */ 	addiu	$a0,$zero,0x1a
/*     cbd0:	8e6501e4 */ 	lw	$a1,0x1e4($s3)
/*     cbd4:	8e6601ec */ 	lw	$a2,0x1ec($s3)
/*     cbd8:	0c00327a */ 	jal	crashPrint3Floats
/*     cbdc:	8e6701f4 */ 	lw	$a3,0x1f4($s3)
/*     cbe0:	2404001d */ 	addiu	$a0,$zero,0x1d
/*     cbe4:	8e6501fc */ 	lw	$a1,0x1fc($s3)
/*     cbe8:	8e660204 */ 	lw	$a2,0x204($s3)
/*     cbec:	0c00327a */ 	jal	crashPrint3Floats
/*     cbf0:	8e67020c */ 	lw	$a3,0x20c($s3)
/*     cbf4:	8e6a0008 */ 	lw	$t2,0x8($s3)
/*     cbf8:	8e6b000c */ 	lw	$t3,0xc($s3)
/*     cbfc:	8e660000 */ 	lw	$a2,0x0($s3)
/*     cc00:	8e670004 */ 	lw	$a3,0x4($s3)
/*     cc04:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     cc08:	afab0014 */ 	sw	$t3,0x14($sp)
/*     cc0c:	8e6d0014 */ 	lw	$t5,0x14($s3)
/*     cc10:	8e6c0010 */ 	lw	$t4,0x10($s3)
/*     cc14:	3c047005 */ 	lui	$a0,0x7005
/*     cc18:	2484409c */ 	addiu	$a0,$a0,0x409c
/*     cc1c:	afad001c */ 	sw	$t5,0x1c($sp)
/*     cc20:	0c00c47d */ 	jal	crashPrint
/*     cc24:	afac0018 */ 	sw	$t4,0x18($sp)
/*     cc28:	8e6e0020 */ 	lw	$t6,0x20($s3)
/*     cc2c:	8e6f0024 */ 	lw	$t7,0x24($s3)
/*     cc30:	8e660018 */ 	lw	$a2,0x18($s3)
/*     cc34:	8e67001c */ 	lw	$a3,0x1c($s3)
/*     cc38:	afae0010 */ 	sw	$t6,0x10($sp)
/*     cc3c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     cc40:	8e79002c */ 	lw	$t9,0x2c($s3)
/*     cc44:	8e780028 */ 	lw	$t8,0x28($s3)
/*     cc48:	3c047005 */ 	lui	$a0,0x7005
/*     cc4c:	248440c4 */ 	addiu	$a0,$a0,0x40c4
/*     cc50:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     cc54:	0c00c47d */ 	jal	crashPrint
/*     cc58:	afb80018 */ 	sw	$t8,0x18($sp)
/*     cc5c:	8e680038 */ 	lw	$t0,0x38($s3)
/*     cc60:	8e69003c */ 	lw	$t1,0x3c($s3)
/*     cc64:	8e660030 */ 	lw	$a2,0x30($s3)
/*     cc68:	8e670034 */ 	lw	$a3,0x34($s3)
/*     cc6c:	afa80010 */ 	sw	$t0,0x10($sp)
/*     cc70:	afa90014 */ 	sw	$t1,0x14($sp)
/*     cc74:	8e6b0044 */ 	lw	$t3,0x44($s3)
/*     cc78:	8e6a0040 */ 	lw	$t2,0x40($s3)
/*     cc7c:	3c047005 */ 	lui	$a0,0x7005
/*     cc80:	248440ec */ 	addiu	$a0,$a0,0x40ec
/*     cc84:	afab001c */ 	sw	$t3,0x1c($sp)
/*     cc88:	0c00c47d */ 	jal	crashPrint
/*     cc8c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*     cc90:	8e6c0050 */ 	lw	$t4,0x50($s3)
/*     cc94:	8e6d0054 */ 	lw	$t5,0x54($s3)
/*     cc98:	8e660048 */ 	lw	$a2,0x48($s3)
/*     cc9c:	8e67004c */ 	lw	$a3,0x4c($s3)
/*     cca0:	afac0010 */ 	sw	$t4,0x10($sp)
/*     cca4:	afad0014 */ 	sw	$t5,0x14($sp)
/*     cca8:	8e6f005c */ 	lw	$t7,0x5c($s3)
/*     ccac:	8e6e0058 */ 	lw	$t6,0x58($s3)
/*     ccb0:	3c047005 */ 	lui	$a0,0x7005
/*     ccb4:	24844114 */ 	addiu	$a0,$a0,0x4114
/*     ccb8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*     ccbc:	0c00c47d */ 	jal	crashPrint
/*     ccc0:	afae0018 */ 	sw	$t6,0x18($sp)
/*     ccc4:	8e780068 */ 	lw	$t8,0x68($s3)
/*     ccc8:	8e79006c */ 	lw	$t9,0x6c($s3)
/*     cccc:	8e660060 */ 	lw	$a2,0x60($s3)
/*     ccd0:	8e670064 */ 	lw	$a3,0x64($s3)
/*     ccd4:	afb80010 */ 	sw	$t8,0x10($sp)
/*     ccd8:	afb90014 */ 	sw	$t9,0x14($sp)
/*     ccdc:	8e690074 */ 	lw	$t1,0x74($s3)
/*     cce0:	8e680070 */ 	lw	$t0,0x70($s3)
/*     cce4:	3c047005 */ 	lui	$a0,0x7005
/*     cce8:	2484413c */ 	addiu	$a0,$a0,0x413c
/*     ccec:	afa9001c */ 	sw	$t1,0x1c($sp)
/*     ccf0:	0c00c47d */ 	jal	crashPrint
/*     ccf4:	afa80018 */ 	sw	$t0,0x18($sp)
/*     ccf8:	8e6a0080 */ 	lw	$t2,0x80($s3)
/*     ccfc:	8e6b0084 */ 	lw	$t3,0x84($s3)
/*     cd00:	8e660078 */ 	lw	$a2,0x78($s3)
/*     cd04:	8e67007c */ 	lw	$a3,0x7c($s3)
/*     cd08:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     cd0c:	afab0014 */ 	sw	$t3,0x14($sp)
/*     cd10:	8e6d008c */ 	lw	$t5,0x8c($s3)
/*     cd14:	8e6c0088 */ 	lw	$t4,0x88($s3)
/*     cd18:	3c047005 */ 	lui	$a0,0x7005
/*     cd1c:	24844164 */ 	addiu	$a0,$a0,0x4164
/*     cd20:	afad001c */ 	sw	$t5,0x1c($sp)
/*     cd24:	0c00c47d */ 	jal	crashPrint
/*     cd28:	afac0018 */ 	sw	$t4,0x18($sp)
/*     cd2c:	8e6e0098 */ 	lw	$t6,0x98($s3)
/*     cd30:	8e6f009c */ 	lw	$t7,0x9c($s3)
/*     cd34:	8e660090 */ 	lw	$a2,0x90($s3)
/*     cd38:	8e670094 */ 	lw	$a3,0x94($s3)
/*     cd3c:	afae0010 */ 	sw	$t6,0x10($sp)
/*     cd40:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     cd44:	8e7900a4 */ 	lw	$t9,0xa4($s3)
/*     cd48:	8e7800a0 */ 	lw	$t8,0xa0($s3)
/*     cd4c:	3c047005 */ 	lui	$a0,0x7005
/*     cd50:	2484418c */ 	addiu	$a0,$a0,0x418c
/*     cd54:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     cd58:	0c00c47d */ 	jal	crashPrint
/*     cd5c:	afb80018 */ 	sw	$t8,0x18($sp)
/*     cd60:	8e6800b0 */ 	lw	$t0,0xb0($s3)
/*     cd64:	8e6900b4 */ 	lw	$t1,0xb4($s3)
/*     cd68:	8e6600a8 */ 	lw	$a2,0xa8($s3)
/*     cd6c:	8e6700ac */ 	lw	$a3,0xac($s3)
/*     cd70:	afa80010 */ 	sw	$t0,0x10($sp)
/*     cd74:	afa90014 */ 	sw	$t1,0x14($sp)
/*     cd78:	8e6b00bc */ 	lw	$t3,0xbc($s3)
/*     cd7c:	8e6a00b8 */ 	lw	$t2,0xb8($s3)
/*     cd80:	3c047005 */ 	lui	$a0,0x7005
/*     cd84:	248441b4 */ 	addiu	$a0,$a0,0x41b4
/*     cd88:	afab001c */ 	sw	$t3,0x1c($sp)
/*     cd8c:	0c00c47d */ 	jal	crashPrint
/*     cd90:	afaa0018 */ 	sw	$t2,0x18($sp)
/*     cd94:	8e6c00c8 */ 	lw	$t4,0xc8($s3)
/*     cd98:	8e6d00cc */ 	lw	$t5,0xcc($s3)
/*     cd9c:	8e6600c0 */ 	lw	$a2,0xc0($s3)
/*     cda0:	8e6700c4 */ 	lw	$a3,0xc4($s3)
/*     cda4:	afac0010 */ 	sw	$t4,0x10($sp)
/*     cda8:	afad0014 */ 	sw	$t5,0x14($sp)
/*     cdac:	8e6f00d4 */ 	lw	$t7,0xd4($s3)
/*     cdb0:	8e6e00d0 */ 	lw	$t6,0xd0($s3)
/*     cdb4:	3c047005 */ 	lui	$a0,0x7005
/*     cdb8:	248441dc */ 	addiu	$a0,$a0,0x41dc
/*     cdbc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*     cdc0:	0c00c47d */ 	jal	crashPrint
/*     cdc4:	afae0018 */ 	sw	$t6,0x18($sp)
/*     cdc8:	8e7800e0 */ 	lw	$t8,0xe0($s3)
/*     cdcc:	8e7900e4 */ 	lw	$t9,0xe4($s3)
/*     cdd0:	3c047005 */ 	lui	$a0,0x7005
/*     cdd4:	8e6600d8 */ 	lw	$a2,0xd8($s3)
/*     cdd8:	8e6700dc */ 	lw	$a3,0xdc($s3)
/*     cddc:	24844204 */ 	addiu	$a0,$a0,0x4204
/*     cde0:	afb80010 */ 	sw	$t8,0x10($sp)
/*     cde4:	0c00c47d */ 	jal	crashPrint
/*     cde8:	afb90014 */ 	sw	$t9,0x14($sp)
/*     cdec:	8fa800f8 */ 	lw	$t0,0xf8($sp)
/*     cdf0:	8e69010c */ 	lw	$t1,0x10c($s3)
/*     cdf4:	8e6600fc */ 	lw	$a2,0xfc($s3)
/*     cdf8:	8e670100 */ 	lw	$a3,0x100($s3)
/*     cdfc:	8d050014 */ 	lw	$a1,0x14($t0)
/*     ce00:	afa90010 */ 	sw	$t1,0x10($sp)
/*     ce04:	8e6a0104 */ 	lw	$t2,0x104($s3)
/*     ce08:	3c047005 */ 	lui	$a0,0x7005
/*     ce0c:	24844220 */ 	addiu	$a0,$a0,0x4220
/*     ce10:	afaa0014 */ 	sw	$t2,0x14($sp)
/*     ce14:	8e6b00f8 */ 	lw	$t3,0xf8($s3)
/*     ce18:	0c00c47d */ 	jal	crashPrint
/*     ce1c:	afab0018 */ 	sw	$t3,0x18($sp)
/*     ce20:	8e6500fc */ 	lw	$a1,0xfc($s3)
/*     ce24:	3c047005 */ 	lui	$a0,0x7005
/*     ce28:	24844258 */ 	addiu	$a0,$a0,0x4258
/*     ce2c:	8cac0008 */ 	lw	$t4,0x8($a1)
/*     ce30:	8ca60000 */ 	lw	$a2,0x0($a1)
/*     ce34:	8ca70004 */ 	lw	$a3,0x4($a1)
/*     ce38:	afac0010 */ 	sw	$t4,0x10($sp)
/*     ce3c:	8cad000c */ 	lw	$t5,0xc($a1)
/*     ce40:	00a01025 */ 	or	$v0,$a1,$zero
/*     ce44:	0c00c47d */ 	jal	crashPrint
/*     ce48:	afad0014 */ 	sw	$t5,0x14($sp)
/*     ce4c:	3c057005 */ 	lui	$a1,0x7005
/*     ce50:	3c068006 */ 	lui	$a2,0x8006
/*     ce54:	24c6ed5c */ 	addiu	$a2,$a2,-4772
/*     ce58:	24a5427c */ 	addiu	$a1,$a1,0x427c
/*     ce5c:	0c00342d */ 	jal	crashPrintDescription
/*     ce60:	8e640100 */ 	lw	$a0,0x100($s3)
/*     ce64:	3c047005 */ 	lui	$a0,0x7005
/*     ce68:	0c00c47d */ 	jal	crashPrint
/*     ce6c:	24844284 */ 	addiu	$a0,$a0,0x4284
/*     ce70:	3c057005 */ 	lui	$a1,0x7005
/*     ce74:	3c068006 */ 	lui	$a2,0x8006
/*     ce78:	24c6f020 */ 	addiu	$a2,$a2,-4064
/*     ce7c:	24a54288 */ 	addiu	$a1,$a1,0x4288
/*     ce80:	0c00342d */ 	jal	crashPrintDescription
/*     ce84:	8e64010c */ 	lw	$a0,0x10c($s3)
/*     ce88:	3c047005 */ 	lui	$a0,0x7005
/*     ce8c:	0c00c47d */ 	jal	crashPrint
/*     ce90:	24844290 */ 	addiu	$a0,$a0,0x4290
/*     ce94:	8e6400d4 */ 	lw	$a0,0xd4($s3)
/*     ce98:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*     ce9c:	00009025 */ 	or	$s2,$zero,$zero
/*     cea0:	00808825 */ 	or	$s1,$a0,$zero
/*     cea4:	0c0031f3 */ 	jal	crashGetStackEnd
/*     cea8:	8f050014 */ 	lw	$a1,0x14($t8)
/*     ceac:	8fb900f8 */ 	lw	$t9,0xf8($sp)
/*     ceb0:	afa20060 */ 	sw	$v0,0x60($sp)
/*     ceb4:	02202025 */ 	or	$a0,$s1,$zero
/*     ceb8:	0c003212 */ 	jal	crashGetStackStart
/*     cebc:	8f250014 */ 	lw	$a1,0x14($t9)
/*     cec0:	afa20064 */ 	sw	$v0,0x64($sp)
/*     cec4:	8e7000fc */ 	lw	$s0,0xfc($s3)
/*     cec8:	3c047005 */ 	lui	$a0,0x7005
/*     cecc:	ae800000 */ 	sw	$zero,0x0($s4)
/*     ced0:	0c00c47d */ 	jal	crashPrint
/*     ced4:	24844294 */ 	addiu	$a0,$a0,0x4294
.NB0000ced8:
/*     ced8:	3c057000 */ 	lui	$a1,0x7000
/*     cedc:	24a51050 */ 	addiu	$a1,$a1,0x1050
/*     cee0:	02002025 */ 	or	$a0,$s0,$zero
/*     cee4:	02203025 */ 	or	$a2,$s1,$zero
/*     cee8:	0c0030d4 */ 	jal	crashGetParentStackFrame
/*     ceec:	27a7006c */ 	addiu	$a3,$sp,0x6c
/*     cef0:	3c047005 */ 	lui	$a0,0x7005
/*     cef4:	00408825 */ 	or	$s1,$v0,$zero
/*     cef8:	2484429c */ 	addiu	$a0,$a0,0x429c
/*     cefc:	0c00c47d */ 	jal	crashPrint
/*     cf00:	02002825 */ 	or	$a1,$s0,$zero
/*     cf04:	8e890000 */ 	lw	$t1,0x0($s4)
/*     cf08:	8fa800fc */ 	lw	$t0,0xfc($sp)
/*     cf0c:	24010004 */ 	addiu	$at,$zero,0x4
/*     cf10:	00095080 */ 	sll	$t2,$t1,0x2
/*     cf14:	010a5821 */ 	addu	$t3,$t0,$t2
/*     cf18:	ad700000 */ 	sw	$s0,0x0($t3)
/*     cf1c:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*     cf20:	3c047005 */ 	lui	$a0,0x7005
/*     cf24:	258d0001 */ 	addiu	$t5,$t4,0x1
/*     cf28:	16410003 */ 	bne	$s2,$at,.NB0000cf38
/*     cf2c:	ae8d0000 */ 	sw	$t5,0x0($s4)
/*     cf30:	0c00c47d */ 	jal	crashPrint
/*     cf34:	248442a4 */ 	addiu	$a0,$a0,0x42a4
.NB0000cf38:
/*     cf38:	16200002 */ 	bnez	$s1,.NB0000cf44
/*     cf3c:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*     cf40:	8e7100d4 */ 	lw	$s1,0xd4($s3)
.NB0000cf44:
/*     cf44:	17000003 */ 	bnez	$t8,.NB0000cf54
/*     cf48:	8faa0064 */ 	lw	$t2,0x64($sp)
/*     cf4c:	10000003 */ 	beqz	$zero,.NB0000cf5c
/*     cf50:	8e7000e4 */ 	lw	$s0,0xe4($s3)
.NB0000cf54:
/*     cf54:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*     cf58:	8f300000 */ 	lw	$s0,0x0($t9)
.NB0000cf5c:
/*     cf5c:	022a082b */ 	sltu	$at,$s1,$t2
/*     cf60:	1420000a */ 	bnez	$at,.NB0000cf8c
/*     cf64:	8fa30060 */ 	lw	$v1,0x60($sp)
/*     cf68:	0223082b */ 	sltu	$at,$s1,$v1
/*     cf6c:	10200007 */ 	beqz	$at,.NB0000cf8c
/*     cf70:	262b0010 */ 	addiu	$t3,$s1,0x10
/*     cf74:	11630005 */ 	beq	$t3,$v1,.NB0000cf8c
/*     cf78:	2a420009 */ 	slti	$v0,$s2,0x9
/*     cf7c:	12000003 */ 	beqz	$s0,.NB0000cf8c
/*     cf80:	00000000 */ 	sll	$zero,$zero,0x0
/*     cf84:	1440ffd4 */ 	bnez	$v0,.NB0000ced8
/*     cf88:	26520001 */ 	addiu	$s2,$s2,0x1
.NB0000cf8c:
/*     cf8c:	3c0d8006 */ 	lui	$t5,0x8006
/*     cf90:	91aded50 */ 	lbu	$t5,-0x12b0($t5)
/*     cf94:	240c001f */ 	addiu	$t4,$zero,0x1f
/*     cf98:	3c018006 */ 	lui	$at,0x8006
/*     cf9c:	11a00024 */ 	beqz	$t5,.NB0000d030
/*     cfa0:	a42ced58 */ 	sh	$t4,-0x12a8($at)
/*     cfa4:	3c058006 */ 	lui	$a1,0x8006
/*     cfa8:	24a5ed54 */ 	addiu	$a1,$a1,-4780
/*     cfac:	3c028009 */ 	lui	$v0,0x8009
/*     cfb0:	a4a00000 */ 	sh	$zero,0x0($a1)
/*     cfb4:	24424e70 */ 	addiu	$v0,$v0,0x4e70
/*     cfb8:	00001825 */ 	or	$v1,$zero,$zero
/*     cfbc:	24040047 */ 	addiu	$a0,$zero,0x47
.NB0000cfc0:
/*     cfc0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*     cfc4:	51c00005 */ 	beqzl	$t6,.NB0000cfdc
/*     cfc8:	240f0047 */ 	addiu	$t7,$zero,0x47
/*     cfcc:	24630001 */ 	addiu	$v1,$v1,0x1
/*     cfd0:	1464fffb */ 	bne	$v1,$a0,.NB0000cfc0
/*     cfd4:	24420001 */ 	addiu	$v0,$v0,0x1
/*     cfd8:	240f0047 */ 	addiu	$t7,$zero,0x47
.NB0000cfdc:
/*     cfdc:	01e3c023 */ 	subu	$t8,$t7,$v1
/*     cfe0:	07010003 */ 	bgez	$t8,.NB0000cff0
/*     cfe4:	00184043 */ 	sra	$t0,$t8,0x1
/*     cfe8:	27010001 */ 	addiu	$at,$t8,0x1
/*     cfec:	00014043 */ 	sra	$t0,$at,0x1
.NB0000cff0:
/*     cff0:	a4a80000 */ 	sh	$t0,0x0($a1)
/*     cff4:	18600020 */ 	blez	$v1,.NB0000d078
/*     cff8:	00008025 */ 	or	$s0,$zero,$zero
/*     cffc:	3c028009 */ 	lui	$v0,0x8009
/*     d000:	24424e70 */ 	addiu	$v0,$v0,0x4e70
.NB0000d004:
/*     d004:	90440000 */ 	lbu	$a0,0x0($v0)
/*     d008:	afa20048 */ 	sw	$v0,0x48($sp)
/*     d00c:	0c003481 */ 	jal	crashAppendChar
/*     d010:	afa30050 */ 	sw	$v1,0x50($sp)
/*     d014:	8fa30050 */ 	lw	$v1,0x50($sp)
/*     d018:	8fa20048 */ 	lw	$v0,0x48($sp)
/*     d01c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d020:	1603fff8 */ 	bne	$s0,$v1,.NB0000d004
/*     d024:	24420001 */ 	addiu	$v0,$v0,0x1
/*     d028:	10000013 */ 	beqz	$zero,.NB0000d078
/*     d02c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000d030:
/*     d030:	3c058006 */ 	lui	$a1,0x8006
/*     d034:	24a5ed54 */ 	addiu	$a1,$a1,-4780
/*     d038:	24090020 */ 	addiu	$t1,$zero,0x20
/*     d03c:	a4a90000 */ 	sh	$t1,0x0($a1)
/*     d040:	0c003481 */ 	jal	crashAppendChar
/*     d044:	24040043 */ 	addiu	$a0,$zero,0x43
/*     d048:	0c003481 */ 	jal	crashAppendChar
/*     d04c:	24040052 */ 	addiu	$a0,$zero,0x52
/*     d050:	0c003481 */ 	jal	crashAppendChar
/*     d054:	24040041 */ 	addiu	$a0,$zero,0x41
/*     d058:	0c003481 */ 	jal	crashAppendChar
/*     d05c:	24040053 */ 	addiu	$a0,$zero,0x53
/*     d060:	0c003481 */ 	jal	crashAppendChar
/*     d064:	24040048 */ 	addiu	$a0,$zero,0x48
/*     d068:	0c003481 */ 	jal	crashAppendChar
/*     d06c:	24040045 */ 	addiu	$a0,$zero,0x45
/*     d070:	0c003481 */ 	jal	crashAppendChar
/*     d074:	24040044 */ 	addiu	$a0,$zero,0x44
.NB0000d078:
/*     d078:	3c047005 */ 	lui	$a0,0x7005
/*     d07c:	0c00c47d */ 	jal	crashPrint
/*     d080:	248442b0 */ 	addiu	$a0,$a0,0x42b0
/*     d084:	3c047005 */ 	lui	$a0,0x7005
/*     d088:	0c00c47d */ 	jal	crashPrint
/*     d08c:	248442b4 */ 	addiu	$a0,$a0,0x42b4
/*     d090:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     d094:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     d098:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*     d09c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*     d0a0:	8fb30034 */ 	lw	$s3,0x34($sp)
/*     d0a4:	8fb40038 */ 	lw	$s4,0x38($sp)
/*     d0a8:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*     d0ac:	03e00008 */ 	jr	$ra
/*     d0b0:	00001025 */ 	or	$v0,$zero,$zero
);
#endif

void crashPrintDescription(u32 mask, char *label, struct crashdescription *description)
{
	bool first = true;
	s32 i;

	crashPrint("%s <", label);

	while (description->mask != 0) {
		if ((description->mask & mask) == description->value) {
			if (first) {
				first = false;
			} else {
				crashPrint(",");
			}

			crashPrint("%s", description->text);
		}

		description++;
	}

	crashPrint(">");
}

void crashPutChar(s32 x, s32 y, char c)
{
	if (c == '\t' || c == '\n') {
		c = '\0';
	}

	if ((c > '\0' && c < ' ') || c > '~') {
		c = '?';
	}

	if (x >= 0 && x < 72 && y >= 0 && y < 30 && g_CrashCharBuffer != NULL) {
		g_CrashCharBuffer[y][x] = c;
	}
}

void crashAppendChar(char c)
{
	if (c == '\0') {
		return;
	}

	if (c == '\t') {
		do {
			crashAppendChar(' ');
		} while (g_CrashCurX & 7);

		return;
	}

	if (c == '\n') {
		g_CrashCurY++;
		g_CrashCurX = 0;
	}

	if (g_CrashCurY > 28) {
		crashScroll(g_CrashCurY - 28);
		g_CrashCurY = 28;
	}

	if (c != '\n') {
		crashPutChar(g_CrashCurX, g_CrashCurY, c);
		g_CrashCurX++;

		if (g_CrashCurX >= 71) {
			g_CrashCurX = 0;
			g_CrashCurY++;
		}
	}
}

void crashScroll(s32 numlines)
{
	s32 i;
	s32 y;
	s32 x;

	if (g_CrashCharBuffer == NULL) {
		return;
	}

	while (numlines-- > 0) {
		for (y = 0; y < 29; y++) {
			for (x = 0; x < 71; x++) {
				g_CrashCharBuffer[y][x] = g_CrashCharBuffer[y + 1][x];
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void func0000cdc8(s32 x, s32 y, char c)
{
	s32 i;
	s32 j;
	s32 width;
	u16 *fbpos;
	bool hires;
	s32 tmp;
	u32 a2;

	width = viGetWidth();

	if (c == '\0') {
		c = ' ';
	}

	if (c < ' ' || c > '~') {
		return;
	}

	hires = (width == 640);

	if (hires) {
		fbpos = g_CrashFrameBuffer + x * 2 + y * width;
	} else {
		fbpos = g_CrashFrameBuffer + x + y * width;
	}

	a2 = 0;

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 4; j++) {
			// "special" occurs every 32nd pixel
			u32 special = a2 & 0x80000000;

			if (special) {
				fbpos[0] = 0x7bdf;
			} else {
				fbpos[0] = 1;
			}

			if (hires) {
				if (special) {
					fbpos[1] = 0x7bdf;
				} else {
					fbpos[1] = 1;
				}
			}

			fbpos++;

			if (hires) {
				fbpos++;
			}

			a2 *= 2;
		}

		if (hires) {
			fbpos += width;
			fbpos -= 8;
		} else {
			fbpos += width;
			fbpos -= 4;
		}
	}
}
#else
GLOBAL_ASM(
glabel func0000cdc8
/*     d398:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     d39c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     d3a0:	afa40018 */ 	sw	$a0,0x18($sp)
/*     d3a4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*     d3a8:	0c002f77 */ 	jal	viGetWidth
/*     d3ac:	afa60020 */ 	sw	$a2,0x20($sp)
/*     d3b0:	93a30023 */ 	lbu	$v1,0x23($sp)
/*     d3b4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*     d3b8:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*     d3bc:	54600003 */ 	bnezl	$v1,.NB0000d3cc
/*     d3c0:	28610020 */ 	slti	$at,$v1,0x20
/*     d3c4:	24030020 */ 	addiu	$v1,$zero,0x20
/*     d3c8:	28610020 */ 	slti	$at,$v1,0x20
.NB0000d3cc:
/*     d3cc:	1420003d */ 	bnez	$at,.NB0000d4c4
/*     d3d0:	2861007f */ 	slti	$at,$v1,0x7f
/*     d3d4:	1020003b */ 	beqz	$at,.NB0000d4c4
/*     d3d8:	38490280 */ 	xori	$t1,$v0,0x280
/*     d3dc:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*     d3e0:	1120000a */ 	beqz	$t1,.NB0000d40c
/*     d3e4:	00006025 */ 	or	$t4,$zero,$zero
/*     d3e8:	00c20019 */ 	multu	$a2,$v0
/*     d3ec:	3c188006 */ 	lui	$t8,0x8006
/*     d3f0:	8f18f2b4 */ 	lw	$t8,-0xd4c($t8)
/*     d3f4:	00057880 */ 	sll	$t7,$a1,0x2
/*     d3f8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*     d3fc:	00007012 */ 	mflo	$t6
/*     d400:	000e7840 */ 	sll	$t7,$t6,0x1
/*     d404:	10000009 */ 	beqz	$zero,.NB0000d42c
/*     d408:	032f2021 */ 	addu	$a0,$t9,$t7
.NB0000d40c:
/*     d40c:	00c20019 */ 	multu	$a2,$v0
/*     d410:	3c0e8006 */ 	lui	$t6,0x8006
/*     d414:	8dcef2b4 */ 	lw	$t6,-0xd4c($t6)
/*     d418:	0005c040 */ 	sll	$t8,$a1,0x1
/*     d41c:	030ec821 */ 	addu	$t9,$t8,$t6
/*     d420:	00007812 */ 	mflo	$t7
/*     d424:	000fc040 */ 	sll	$t8,$t7,0x1
/*     d428:	03382021 */ 	addu	$a0,$t9,$t8
.NB0000d42c:
/*     d42c:	00037080 */ 	sll	$t6,$v1,0x2
/*     d430:	3c068006 */ 	lui	$a2,0x8006
/*     d434:	00ce3021 */ 	addu	$a2,$a2,$t6
/*     d438:	8cc6f0b8 */ 	lw	$a2,-0xf48($a2)
/*     d43c:	00026840 */ 	sll	$t5,$v0,0x1
/*     d440:	241f0007 */ 	addiu	$ra,$zero,0x7
/*     d444:	240b0004 */ 	addiu	$t3,$zero,0x4
/*     d448:	3c0a8000 */ 	lui	$t2,0x8000
/*     d44c:	24080001 */ 	addiu	$t0,$zero,0x1
/*     d450:	3407ffff */ 	dli	$a3,0xffff
/*     d454:	00002825 */ 	or	$a1,$zero,$zero
.NB0000d458:
/*     d458:	00ca1824 */ 	and	$v1,$a2,$t2
/*     d45c:	10600003 */ 	beqz	$v1,.NB0000d46c
/*     d460:	00067840 */ 	sll	$t7,$a2,0x1
/*     d464:	10000002 */ 	beqz	$zero,.NB0000d470
/*     d468:	a4870000 */ 	sh	$a3,0x0($a0)
.NB0000d46c:
/*     d46c:	a4880000 */ 	sh	$t0,0x0($a0)
.NB0000d470:
/*     d470:	11200006 */ 	beqz	$t1,.NB0000d48c
/*     d474:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     d478:	50600004 */ 	beqzl	$v1,.NB0000d48c
/*     d47c:	a4880002 */ 	sh	$t0,0x2($a0)
/*     d480:	10000002 */ 	beqz	$zero,.NB0000d48c
/*     d484:	a4870002 */ 	sh	$a3,0x2($a0)
/*     d488:	a4880002 */ 	sh	$t0,0x2($a0)
.NB0000d48c:
/*     d48c:	11200002 */ 	beqz	$t1,.NB0000d498
/*     d490:	24840002 */ 	addiu	$a0,$a0,0x2
/*     d494:	24840002 */ 	addiu	$a0,$a0,0x2
.NB0000d498:
/*     d498:	14abffef */ 	bne	$a1,$t3,.NB0000d458
/*     d49c:	01e03025 */ 	or	$a2,$t7,$zero
/*     d4a0:	11200004 */ 	beqz	$t1,.NB0000d4b4
/*     d4a4:	258c0001 */ 	addiu	$t4,$t4,0x1
/*     d4a8:	008d2021 */ 	addu	$a0,$a0,$t5
/*     d4ac:	10000003 */ 	beqz	$zero,.NB0000d4bc
/*     d4b0:	2484fff0 */ 	addiu	$a0,$a0,-16
.NB0000d4b4:
/*     d4b4:	008d2021 */ 	addu	$a0,$a0,$t5
/*     d4b8:	2484fff8 */ 	addiu	$a0,$a0,-8
.NB0000d4bc:
/*     d4bc:	559fffe6 */ 	bnel	$t4,$ra,.NB0000d458
/*     d4c0:	00002825 */ 	or	$a1,$zero,$zero
.NB0000d4c4:
/*     d4c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     d4c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     d4cc:	03e00008 */ 	jr	$ra
/*     d4d0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void crashReset(void)
{
	g_CrashCharBuffer = NULL;

	if (g_CrashCharBuffer) {
		// Unreachable
		s32 x;
		s32 y;

		for (y = 0; y < 30; y++) {
			for (x = 0; x < 71; x++) {
				g_CrashCharBuffer[y][x] = '\0';
			}
		}
	}
}
#else
GLOBAL_ASM(
glabel crashReset
/*     d4d4:	3c048006 */ 	lui	$a0,0x8006
/*     d4d8:	3c0e8009 */ 	lui	$t6,0x8009
/*     d4dc:	2484f134 */ 	addiu	$a0,$a0,-3788
/*     d4e0:	25ce7178 */ 	addiu	$t6,$t6,0x7178
/*     d4e4:	11c00012 */ 	beqz	$t6,.NB0000d530
/*     d4e8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*     d4ec:	00001025 */ 	or	$v0,$zero,$zero
/*     d4f0:	24060020 */ 	addiu	$a2,$zero,0x20
/*     d4f4:	24050047 */ 	addiu	$a1,$zero,0x47
/*     d4f8:	00001825 */ 	or	$v1,$zero,$zero
.NB0000d4fc:
/*     d4fc:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*     d500:	8c980000 */ 	lw	$t8,0x0($a0)
/*     d504:	0322c821 */ 	addu	$t9,$t9,$v0
/*     d508:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*     d50c:	0322c823 */ 	subu	$t9,$t9,$v0
/*     d510:	03194021 */ 	addu	$t0,$t8,$t9
/*     d514:	01034821 */ 	addu	$t1,$t0,$v1
/*     d518:	24630001 */ 	addiu	$v1,$v1,0x1
/*     d51c:	1465fff7 */ 	bne	$v1,$a1,.NB0000d4fc
/*     d520:	a1200000 */ 	sb	$zero,0x0($t1)
/*     d524:	24420001 */ 	addiu	$v0,$v0,0x1
/*     d528:	5446fff4 */ 	bnel	$v0,$a2,.NB0000d4fc
/*     d52c:	00001825 */ 	or	$v1,$zero,$zero
.NB0000d530:
/*     d530:	03e00008 */ 	jr	$ra
/*     d534:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void func0000cf54(u16 *fb)
{
	s32 width;
	s32 height;
	s32 x;
	s32 y;

	g_CrashFrameBuffer = (u16 *) PHYS_TO_K1(fb);

	width = (viGetWidth() - 13) / 4;
	height = (viGetHeight() - 10) / 7 - 1;

	if (g_CrashCharBuffer != NULL) {
		for (y = 0; y < height && y < 29; y++) {
			for (x = 0; x < width - 5 && x < 71; x++) {
				func0000cdc8(20 + x * 4, 7 + y * 7, g_CrashCharBuffer[y][x]);
			}
		}
	}
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000d678nb
/*     d678:	00000000 */ 	sll	$zero,$zero,0x0
/*     d67c:	00000000 */ 	sll	$zero,$zero,0x0
/*     d680:	03e02025 */ 	or	$a0,$ra,$zero
/*     d684:	2402ffff */ 	addiu	$v0,$zero,-1
/*     d688:	8c880000 */ 	lw	$t0,0x0($a0)
/*     d68c:	240a27bd */ 	addiu	$t2,$zero,0x27bd
/*     d690:	00084c02 */ 	srl	$t1,$t0,0x10
/*     d694:	112a000a */ 	beq	$t1,$t2,.NB0000d6c0
/*     d698:	00000000 */ 	sll	$zero,$zero,0x0
/*     d69c:	340aafbf */ 	dli	$t2,0xafbf
/*     d6a0:	512a0004 */ 	beql	$t1,$t2,.NB0000d6b4
/*     d6a4:	00085400 */ 	sll	$t2,$t0,0x10
/*     d6a8:	080035a2 */ 	j	0xd688
/*     d6ac:	2484fffc */ 	addiu	$a0,$a0,-4
/*     d6b0:	00085400 */ 	sll	$t2,$t0,0x10
.NB0000d6b4:
/*     d6b4:	000a5403 */ 	sra	$t2,$t2,0x10
/*     d6b8:	015d5020 */ 	add	$t2,$t2,$sp
/*     d6bc:	8d420000 */ 	lw	$v0,0x0($t2)
.NB0000d6c0:
/*     d6c0:	03e00008 */ 	jr	$ra
/*     d6c4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
