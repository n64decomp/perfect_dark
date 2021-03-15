#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/entry.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

OSThread g_FaultThread;
u8 g_FaultStack[STACKSIZE_FAULT];
OSMesgQueue g_FaultMesgQueue;
OSMesg g_FaultMesg;
u32 var80094acc;
u32 var80094ad0;

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
void crashPrintDescription(u32 mask, char *label, struct crashdescription *descriptions);

void faultCreateThread2(void)
{
	osCreateMesgQueue(&g_FaultMesgQueue, &g_FaultMesg, 1);
	osCreateThread(&g_FaultThread, THREAD_FAULT, faultproc, NULL, &g_FaultStack[1024], THREADPRI_FAULT);
	osStartThread(&g_FaultThread);
}

GLOBAL_ASM(
glabel faultproc
/*     c06c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*     c070:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     c074:	3c118009 */ 	lui	$s1,%hi(g_FaultMesgQueue)
/*     c078:	26314ab0 */ 	addiu	$s1,$s1,%lo(g_FaultMesgQueue)
/*     c07c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     c080:	afa40060 */ 	sw	$a0,0x60($sp)
/*     c084:	afb20020 */ 	sw	$s2,0x20($sp)
/*     c088:	afb00018 */ 	sw	$s0,0x18($sp)
/*     c08c:	afa0005c */ 	sw	$zero,0x5c($sp)
/*     c090:	2404000c */ 	addiu	$a0,$zero,0xc
/*     c094:	02202825 */ 	or	$a1,$s1,$zero
/*     c098:	0c012148 */ 	jal	osSetEventMesg
/*     c09c:	24060010 */ 	addiu	$a2,$zero,0x10
/*     c0a0:	3c018009 */ 	lui	$at,%hi(var80094ad0)
/*     c0a4:	ac204ad0 */ 	sw	$zero,%lo(var80094ad0)($at)
/*     c0a8:	27b2005c */ 	addiu	$s2,$sp,0x5c
.L0000c0ac:
/*     c0ac:	02202025 */ 	or	$a0,$s1,$zero
.L0000c0b0:
/*     c0b0:	02402825 */ 	or	$a1,$s2,$zero
/*     c0b4:	0c0121bc */ 	jal	osRecvMesg
/*     c0b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*     c0bc:	0c012194 */ 	jal	osSetIntMask
/*     c0c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*     c0c4:	0c013990 */ 	jal	__osGetCurrFaultedThread
/*     c0c8:	00408025 */ 	or	$s0,$v0,$zero
/*     c0cc:	3c018009 */ 	lui	$at,%hi(var80094acc)
/*     c0d0:	1040fff6 */ 	beqz	$v0,.L0000c0ac
/*     c0d4:	ac224acc */ 	sw	$v0,%lo(var80094acc)($at)
/*     c0d8:	0c012194 */ 	jal	osSetIntMask
/*     c0dc:	02002025 */ 	or	$a0,$s0,$zero
/*     c0e0:	1000fff3 */ 	b	.L0000c0b0
/*     c0e4:	02202025 */ 	or	$a0,$s1,$zero
/*     c0e8:	00000000 */ 	nop
/*     c0ec:	00000000 */ 	nop
/*     c0f0:	00000000 */ 	nop
/*     c0f4:	00000000 */ 	nop
/*     c0f8:	00000000 */ 	nop
/*     c0fc:	00000000 */ 	nop
/*     c100:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     c104:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     c108:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     c10c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     c110:	03e00008 */ 	jr	$ra
/*     c114:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

// Mismatch because bss needs to be sprinkled around various files first
//void faultproc(void *arg0)
//{
//	OSMesg msg = 0;
//	OSIntMask mask;
//	u8 stack2[4];
//	u8 stack1[44];
//	static u32 result; // var80094acc
//
//	osSetEventMesg(OS_EVENT_FAULT, &g_FaultMesgQueue, (OSMesg) 16);
//	var80094ad0 = 0;
//
//	while (true) {
//		do {
//			osRecvMesg(&g_FaultMesgQueue, &msg, 1);
//			mask = osSetIntMask(1);
//			result = __osGetCurrFaultedThread();
//		} while (!result);
//
//		osSetIntMask(mask);
//
//		// Beta versions have something like this here:
//		//crashRender(result, stack1, stack2);
//		//func00001b1c(true);
//	}
//}

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

	if (g_Vars.unk0004e0 == 0) {
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

	if (g_Vars.unk0004e0 == 0) {
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
