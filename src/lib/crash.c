#include <ultra64.h>
#include "os_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/tlb.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/rmon.h"
#include "data.h"
#include "types.h"

#define MSG_FAULT 0x10

#if VERSION >= VERSION_NTSC_1_0
#define MAX_LINES 29
#else
#define MAX_LINES 31
#endif

#if VERSION < VERSION_NTSC_1_0
char g_CrashMessage[70];
#endif

OSThread g_FaultThread;
u8 g_FaultStack[STACKSIZE_FAULT];
OSMesgQueue g_FaultMesgQueue;
OSMesg g_FaultMesg;

#if VERSION < VERSION_NTSC_1_0
s32 var80097104nb;
s32 var80097108nb;
u32 var8009710cnb;
#endif

#if VERSION == VERSION_NTSC_BETA
char *var80097110nb;
char *var80097114nb;
u32 var80097118nb[24];
u8 var80097178nb[MAX_LINES + 1][71];
#elif VERSION == VERSION_PAL_BETA
char *var80097110nb;
char *var80097114nb;
u8 var80097178nb[MAX_LINES + 1][71];
#endif

u8 g_CrashHasMessage = false;
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

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
u32 var8005f138nb = 0;

u32 var8005f13cnb[] = {
	0x22220200, 0x55000000, 0x05f5f500, 0x27427200,
	0x05124500, 0x34255300, 0x22000000, 0x24444420,
	0x42222240, 0x06f6f600, 0x00272000, 0x00000240,
	0x00070000, 0x00000200, 0x11224480, 0x25555200,
	0x26222700, 0x25125700, 0x61211600, 0x33557300,
	0x64611600, 0x24655200, 0x71112200, 0x25755200,
	0x25531600, 0x00200200, 0x00200640, 0x01242100,
	0x00707000, 0x04212400, 0x07120200, 0x25ff5700,
	0x02557d00, 0x06575e00, 0x07445300, 0x07555600,
	0x07565700, 0x07564400, 0x07c95700, 0x05575500,
	0x07222700, 0x03111600, 0x05665500, 0x04445f00,
	0x0dff9d00, 0x0f777d00, 0x07dd5700, 0x07564600,
	0x07995770, 0x07565500, 0x07461e00, 0x07222200,
	0x0d999600, 0x0d552200, 0x0df77500, 0x0d625500,
	0x05622600, 0x07125700, 0x32222230, 0x44222110,
	0x62222260, 0x25000000, 0x00000700, 0x42200000,
	0x0067d700, 0x44755700, 0x00788600, 0x117dd700,
	0x006fc700, 0x32722700, 0x007dd730, 0x44755500,
	0x02622700, 0x02711130, 0x44766500, 0x62222700,
	0x00ffff00, 0x00755d00, 0x006dd600, 0x00755740,
	0x00799710, 0x00744600, 0x00775700, 0x02722300,
	0x00555700, 0x00552200, 0x00577500, 0x00562500,
	0x00552220, 0x00703700, 0x12242210, 0x02222220,
	0x42212240, 0x005a0000,
};
#endif

u16 *g_CrashFrameBuffer = NULL;

extern u32 _libSegmentStart;
extern u32 _libSegmentEnd;

void faultproc(void *arg0);
u32 crashGenerate(OSThread *thread, u32 *callstack, s32 *tracelen);
void crashPrintDescription(u32 mask, char *label, struct crashdescription *descriptions);

#if VERSION < VERSION_NTSC_1_0
void crashSetMessage(char *string)
{
	strncpy(g_CrashMessage, string, sizeof(g_CrashMessage));
	g_CrashHasMessage = true;
}
#endif

void crashCreateThread(void)
{
	osCreateMesgQueue(&g_FaultMesgQueue, &g_FaultMesg, 1);
	osCreateThread(&g_FaultThread, THREAD_FAULT, faultproc, NULL, &g_FaultStack[1024], THREADPRI_FAULT);
	osStartThread(&g_FaultThread);
}

#if VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel faultproc
/*  bd9c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  bda0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  bda4:	3c118009 */ 	lui	$s1,0x8009
/*  bda8:	26316f90 */ 	addiu	$s1,$s1,0x6f90
/*  bdac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  bdb0:	afa40068 */ 	sw	$a0,0x68($sp)
/*  bdb4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  bdb8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  bdbc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  bdc0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  bdc4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  bdc8:	afa00064 */ 	sw	$zero,0x64($sp)
/*  bdcc:	2404000c */ 	li	$a0,0xc
/*  bdd0:	02202825 */ 	move	$a1,$s1
/*  bdd4:	0c0122b8 */ 	jal	osSetEventMesg
/*  bdd8:	24060010 */ 	li	$a2,0x10
/*  bddc:	3c018009 */ 	lui	$at,0x8009
/*  bde0:	3c138006 */ 	lui	$s3,0x8006
/*  bde4:	ac206fb0 */ 	sw	$zero,0x6fb0($at)
/*  bde8:	2673df40 */ 	addiu	$s3,$s3,-8384
/*  bdec:	27b50034 */ 	addiu	$s5,$sp,0x34
/*  bdf0:	27b40038 */ 	addiu	$s4,$sp,0x38
/*  bdf4:	27b20064 */ 	addiu	$s2,$sp,0x64
.PB0000bdf8:
/*  bdf8:	02202025 */ 	move	$a0,$s1
.PB0000bdfc:
/*  bdfc:	02402825 */ 	move	$a1,$s2
/*  be00:	0c01232c */ 	jal	osRecvMesg
/*  be04:	24060001 */ 	li	$a2,0x1
/*  be08:	0c012304 */ 	jal	osSetIntMask
/*  be0c:	24040001 */ 	li	$a0,0x1
/*  be10:	0c013b00 */ 	jal	__osGetCurrFaultedThread
/*  be14:	00408025 */ 	move	$s0,$v0
/*  be18:	3c018009 */ 	lui	$at,0x8009
/*  be1c:	1040fff6 */ 	beqz	$v0,.PB0000bdf8
/*  be20:	ac226fac */ 	sw	$v0,0x6fac($at)
/*  be24:	0c012304 */ 	jal	osSetIntMask
/*  be28:	02002025 */ 	move	$a0,$s0
/*  be2c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  be30:	51c0fff2 */ 	beqzl	$t6,.PB0000bdfc
/*  be34:	02202025 */ 	move	$a0,$s1
/*  be38:	3c048009 */ 	lui	$a0,0x8009
/*  be3c:	8c846fac */ 	lw	$a0,0x6fac($a0)
/*  be40:	02802825 */ 	move	$a1,$s4
/*  be44:	0c0030b1 */ 	jal	crashGenerate
/*  be48:	02a03025 */ 	move	$a2,$s5
/*  be4c:	0c0006c7 */ 	jal	schedSetCrashedUnexpectedly
/*  be50:	24040001 */ 	li	$a0,0x1
/*  be54:	1000ffe9 */ 	b	.PB0000bdfc
/*  be58:	02202025 */ 	move	$a0,$s1
/*  be5c:	00000000 */ 	nop
/*  be60:	00000000 */ 	nop
/*  be64:	00000000 */ 	nop
/*  be68:	00000000 */ 	nop
/*  be6c:	00000000 */ 	nop
/*  be70:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  be74:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  be78:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  be7c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  be80:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  be84:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  be88:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  be8c:	03e00008 */ 	jr	$ra
/*  be90:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#elif VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel faultproc
/*     c270:	27bdff98 */ 	addiu	$sp,$sp,-104
/*     c274:	afb40028 */ 	sw	$s4,0x28($sp)
/*     c278:	3c148009 */ 	lui	$s4,0x8009
/*     c27c:	269470e8 */ 	addiu	$s4,$s4,0x70e8
/*     c280:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     c284:	afa40068 */ 	sw	$a0,0x68($sp)
/*     c288:	afb30024 */ 	sw	$s3,0x24($sp)
/*     c28c:	afb20020 */ 	sw	$s2,0x20($sp)
/*     c290:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     c294:	afb00018 */ 	sw	$s0,0x18($sp)
/*     c298:	afa00064 */ 	sw	$zero,0x64($sp)
/*     c29c:	2404000c */ 	addiu	$a0,$zero,0xc
/*     c2a0:	02802825 */ 	or	$a1,$s4,$zero
/*     c2a4:	0c01263c */ 	jal	osSetEventMesg
/*     c2a8:	24060010 */ 	addiu	$a2,$zero,0x10
/*     c2ac:	3c018009 */ 	lui	$at,0x8009
/*     c2b0:	ac207108 */ 	sw	$zero,0x7108($at)
/*     c2b4:	27b30034 */ 	addiu	$s3,$sp,0x34
/*     c2b8:	27b20038 */ 	addiu	$s2,$sp,0x38
/*     c2bc:	27b10064 */ 	addiu	$s1,$sp,0x64
.NB0000c2c0:
/*     c2c0:	02802025 */ 	or	$a0,$s4,$zero
.NB0000c2c4:
/*     c2c4:	02202825 */ 	or	$a1,$s1,$zero
/*     c2c8:	0c0126b0 */ 	jal	osRecvMesg
/*     c2cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*     c2d0:	0c012688 */ 	jal	osSetIntMask
/*     c2d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*     c2d8:	0c013eb8 */ 	jal	__osGetCurrFaultedThread
/*     c2dc:	00408025 */ 	or	$s0,$v0,$zero
/*     c2e0:	3c018009 */ 	lui	$at,0x8009
/*     c2e4:	1040fff6 */ 	beqz	$v0,.NB0000c2c0
/*     c2e8:	ac227104 */ 	sw	$v0,0x7104($at)
/*     c2ec:	0c012688 */ 	jal	osSetIntMask
/*     c2f0:	02002025 */ 	or	$a0,$s0,$zero
/*     c2f4:	3c048009 */ 	lui	$a0,0x8009
/*     c2f8:	8c847104 */ 	lw	$a0,0x7104($a0)
/*     c2fc:	02402825 */ 	or	$a1,$s2,$zero
/*     c300:	0c003297 */ 	jal	crashGenerate
/*     c304:	02603025 */ 	or	$a2,$s3,$zero
/*     c308:	0c00073b */ 	jal	schedSetCrashedUnexpectedly
/*     c30c:	24040001 */ 	addiu	$a0,$zero,0x1
/*     c310:	1000ffec */ 	beqz	$zero,.NB0000c2c4
/*     c314:	02802025 */ 	or	$a0,$s4,$zero
/*     c318:	00000000 */ 	sll	$zero,$zero,0x0
/*     c31c:	00000000 */ 	sll	$zero,$zero,0x0
/*     c320:	00000000 */ 	sll	$zero,$zero,0x0
/*     c324:	00000000 */ 	sll	$zero,$zero,0x0
/*     c328:	00000000 */ 	sll	$zero,$zero,0x0
/*     c32c:	00000000 */ 	sll	$zero,$zero,0x0
/*     c330:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     c334:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     c338:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     c33c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     c340:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     c344:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     c348:	03e00008 */ 	jr	$ra
/*     c34c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#else
void faultproc(void *arg0)
{
	OSMesg msg = 0;
	OSIntMask mask;
	u32 callstack[10];
	s32 tracelen;
	static OSThread *curr;
	static OSThread *last;

	osSetEventMesg(OS_EVENT_FAULT, &g_FaultMesgQueue, (OSMesg) MSG_FAULT);
	last = NULL;

	while (true) {
		do {
			osRecvMesg(&g_FaultMesgQueue, &msg, OS_MESG_BLOCK);
			mask = osSetIntMask(1);
			curr = __osGetCurrFaultedThread();
		} while (!curr);

		osSetIntMask(mask);

#if VERSION == VERSION_NTSC_BETA
		crashGenerate(curr, callstack, &tracelen);
		schedSetCrashedUnexpectedly(true);
#endif
	}
}
#endif

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
			&& (u32)instruction >= (u32)tlbInit
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
u32 crash0000c52cnb(u32 romaddr)
{
	u32 addr;

	dmaExec(var80097118nb, romaddr, 0x60);

	var8009710cnb = var80097118nb[0];
	var80097110nb = (char *)&var80097118nb[1];
	var80097114nb = (char *)(func0000c4f0nb(var80097110nb) + (u32)var80097110nb + 1);

	addr = romaddr + func0000c4f0nb(var80097110nb) + func0000c4f0nb(var80097114nb) + 6;

	if (addr % 4) {
		addr = (addr | 3) + 1;
	}

	return addr;
}
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
/*     c608:	0c00314b */ 	jal	crash0000c52cnb
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
/*     c638:	0c00314b */ 	jal	crash0000c52cnb
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
bool crash0000c660nb(void)
{
	crash0000c52cnb(0xe00000);

	return var8009710cnb == 0x826475be;
}
#endif

#if VERSION < VERSION_NTSC_1_0
void crash0000c694nb(void)
{
	s32 numvalid = 0;
	s32 i;

	for (i = 0; i < 4; i++) {
		if (var80097110nb[i] >= '!' && var80097110nb[i] <= 0x7f) {
			numvalid++;
		}
	}

	if (numvalid == 4) {
		rmonPrintf("%.49s", var80097110nb);
	} else {
		rmonPrintf("???");
	}
}
#endif

#if VERSION < VERSION_NTSC_1_0
void crash0000c714nb(void)
{
	s32 numvalid = 0;
	s32 i;

	for (i = 0; i < 4; i++) {
		if (var80097114nb[i] >= '!' && var80097114nb[i] <= 0x7f) {
			numvalid++;
		}
	}

	if (numvalid == 4) {
		rmonPrintf("%.41s", var80097114nb);
	} else {
		rmonPrintf("???");
	}
}
#endif

#if VERSION < VERSION_NTSC_1_0
void crash0000c794nb(void)
{
	rmonPrintf("%08x", var8009710cnb);
}
#endif

#if VERSION < VERSION_NTSC_1_0
u32 crash0000c7c0nb(void)
{
	return var8009710cnb;
}
#endif

u32 crashGetStackEnd(u32 sp, s32 tid)
{
	u32 start;
	u32 end;

	if (tid <= 0 || tid > 6U) {
		rmonPrintf("Bad tid\n");
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
		rmonPrintf("Bad tid\n");
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
		rmonPrintf("%s%s%02d: % .7e ", "", "", index, (f64)value);
	} else {
		u32 bits = *(u32 *)&value;
		rmonPrintf("%02d: I%d.%03d.%07d ", index, (bits & 0x80000000) >> 31, (bits & 0x7f800000) >> 23, bits & 0x7fffff);
	}
}

void crashPrint2Floats(s32 index, f32 value1, f32 value2)
{
	crashPrintFloat(index, value1);
	rmonPrintf(" ");

	crashPrintFloat(index + 1, value2);
	rmonPrintf("\n");
}

void crashPrint3Floats(s32 index, f32 value1, f32 value2, f32 value3)
{
	crashPrintFloat(index, value1);
	rmonPrintf(" ");

	crashPrintFloat(index + 1, value2);
	rmonPrintf(" ");

	crashPrintFloat(index + 2, value3);
	rmonPrintf("\n");
}

#if VERSION >= VERSION_NTSC_1_0
u32 crashGenerate(OSThread *thread, u32 *callstack, s32 *tracelen)
{
	s32 i;
	u32 ptr;
	u32 *sp;
	u32 regs[32];
	u32 *stackend;
	u32 *stackstart;
	__OSThreadContext *ctx = &thread->context;
	bool done;

	rmonPrintf("\n\nFAULT-\n");

	if (!g_Vars.fourmeg2player) {
		// Print a stack trace in a dodgy way.
		// It works by iterating through the stack allocation, looking for any
		// values which could potentially be a return address, and prints them.
		u32 *stackend = (u32 *) crashGetStackEnd(ctx->sp, thread->id);
		u32 *sp;
		rmonPrintf("DodgyStackTrace: %08llx ", ctx->ra & 0xffffffff);
		sp = (u32 *) ctx->sp;

		while (sp < stackend) {
			if (crashIsReturnAddress((u32 *)*sp)) {
				rmonPrintf("%08x ", *sp);
			}

			sp++;
		}

		rmonPrintf(".\n");
	}

	rmonPrintf("%H#@! Another Perfect Crash (tm)\n");

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
	rmonPrintf("at 0x%016llx v0 0x%016llx v1 0x%016llx\n", ctx->at, ctx->v0, ctx->v1);
	rmonPrintf("a0 0x%016llx a1 0x%016llx a2 0x%016llx\n", ctx->a0, ctx->a1, ctx->a2);
	rmonPrintf("a3 0x%016llx t0 0x%016llx t1 0x%016llx\n", ctx->a3, ctx->t0, ctx->t1);
	rmonPrintf("t2 0x%016llx t3 0x%016llx t4 0x%016llx\n", ctx->t2, ctx->t3, ctx->t4);
	rmonPrintf("t5 0x%016llx t6 0x%016llx t7 0x%016llx\n", ctx->t5, ctx->t6, ctx->t7);
	rmonPrintf("s0 0x%016llx s1 0x%016llx s2 0x%016llx\n", ctx->s0, ctx->s1, ctx->s2);
	rmonPrintf("s3 0x%016llx s4 0x%016llx s5 0x%016llx\n", ctx->s3, ctx->s4, ctx->s5);
	rmonPrintf("s6 0x%016llx s7 0x%016llx t8 0x%016llx\n", ctx->s6, ctx->s7, ctx->t8);
	rmonPrintf("t9 0x%016llx gp 0x%016llx sp 0x%016llx\n", ctx->t9, ctx->gp, ctx->sp);
	rmonPrintf("s8 0x%016llx ra 0x%016llx\n", ctx->s8, ctx->ra);

	rmonPrintf("TID %d epc %08x caus %08x fp %08x badv %08x sr %08x\n",
			thread->id, ctx->pc, ctx->cause, ctx->fpcsr, ctx->badvaddr, ctx->sr);

	// Print the address of the faulted instruction, along with the instruction
	// itself and the next three - presumably to help the developer locate it.
	rmonPrintf("dshex -a %08x %08x %08x %08x %08x\n", ctx->pc,
			((u32 *)ctx->pc)[0],
			((u32 *)ctx->pc)[1],
			((u32 *)ctx->pc)[2],
			((u32 *)ctx->pc)[3]);

	crashPrintDescription(ctx->cause, "cause", g_CrashCauseDescriptions);
	rmonPrintf(" : ");
	crashPrintDescription(ctx->fpcsr, "fpcsr", g_CrashFpcsrDescriptions);
	rmonPrintf("\n");

	// Print a proper stack trace
	i = 0;
	done = false;
	sp = (u32 *)ctx->sp;
	stackend = (u32 *) crashGetStackEnd((u32)sp, thread->id);
	stackstart = (u32 *) crashGetStackStart((u32)sp, thread->id);
	ptr = ctx->pc;
	*tracelen = 0;
	rmonPrintf("nearl: ");

	while (!done) {
		sp = (u32 *) crashGetParentStackFrame((u32 *) ptr, &_libSegmentStart, (u32)sp, regs);
		rmonPrintf(" %08x ", ptr);

		callstack[*tracelen] = ptr;
		*tracelen = *tracelen + 1;

		if (i == 4) {
			rmonPrintf("\n       ");
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

	rmonPrintf("\n");
	rmonPrintf("\n");

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
glabel crashGenerate
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
/*     ca88:	0c00c47d */ 	jal	rmonPrintf
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
/*     cac0:	0c00c47d */ 	jal	rmonPrintf
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
/*     caec:	0c00c47d */ 	jal	rmonPrintf
/*     caf0:	8e050000 */ 	lw	$a1,0x0($s0)
.NB0000caf4:
/*     caf4:	26100004 */ 	addiu	$s0,$s0,0x4
/*     caf8:	0212082b */ 	sltu	$at,$s0,$s2
/*     cafc:	1420fff7 */ 	bnez	$at,.NB0000cadc
/*     cb00:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000cb04:
/*     cb04:	3c047005 */ 	lui	$a0,0x7005
/*     cb08:	0c00c47d */ 	jal	rmonPrintf
/*     cb0c:	24844080 */ 	addiu	$a0,$a0,0x4080
/*     cb10:	3c047005 */ 	lui	$a0,0x7005
/*     cb14:	0c00c47d */ 	jal	rmonPrintf
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
/*     cc20:	0c00c47d */ 	jal	rmonPrintf
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
/*     cc54:	0c00c47d */ 	jal	rmonPrintf
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
/*     cc88:	0c00c47d */ 	jal	rmonPrintf
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
/*     ccbc:	0c00c47d */ 	jal	rmonPrintf
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
/*     ccf0:	0c00c47d */ 	jal	rmonPrintf
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
/*     cd24:	0c00c47d */ 	jal	rmonPrintf
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
/*     cd58:	0c00c47d */ 	jal	rmonPrintf
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
/*     cd8c:	0c00c47d */ 	jal	rmonPrintf
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
/*     cdc0:	0c00c47d */ 	jal	rmonPrintf
/*     cdc4:	afae0018 */ 	sw	$t6,0x18($sp)
/*     cdc8:	8e7800e0 */ 	lw	$t8,0xe0($s3)
/*     cdcc:	8e7900e4 */ 	lw	$t9,0xe4($s3)
/*     cdd0:	3c047005 */ 	lui	$a0,0x7005
/*     cdd4:	8e6600d8 */ 	lw	$a2,0xd8($s3)
/*     cdd8:	8e6700dc */ 	lw	$a3,0xdc($s3)
/*     cddc:	24844204 */ 	addiu	$a0,$a0,0x4204
/*     cde0:	afb80010 */ 	sw	$t8,0x10($sp)
/*     cde4:	0c00c47d */ 	jal	rmonPrintf
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
/*     ce18:	0c00c47d */ 	jal	rmonPrintf
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
/*     ce44:	0c00c47d */ 	jal	rmonPrintf
/*     ce48:	afad0014 */ 	sw	$t5,0x14($sp)
/*     ce4c:	3c057005 */ 	lui	$a1,0x7005
/*     ce50:	3c068006 */ 	lui	$a2,0x8006
/*     ce54:	24c6ed5c */ 	addiu	$a2,$a2,-4772
/*     ce58:	24a5427c */ 	addiu	$a1,$a1,0x427c
/*     ce5c:	0c00342d */ 	jal	crashPrintDescription
/*     ce60:	8e640100 */ 	lw	$a0,0x100($s3)
/*     ce64:	3c047005 */ 	lui	$a0,0x7005
/*     ce68:	0c00c47d */ 	jal	rmonPrintf
/*     ce6c:	24844284 */ 	addiu	$a0,$a0,0x4284
/*     ce70:	3c057005 */ 	lui	$a1,0x7005
/*     ce74:	3c068006 */ 	lui	$a2,0x8006
/*     ce78:	24c6f020 */ 	addiu	$a2,$a2,-4064
/*     ce7c:	24a54288 */ 	addiu	$a1,$a1,0x4288
/*     ce80:	0c00342d */ 	jal	crashPrintDescription
/*     ce84:	8e64010c */ 	lw	$a0,0x10c($s3)
/*     ce88:	3c047005 */ 	lui	$a0,0x7005
/*     ce8c:	0c00c47d */ 	jal	rmonPrintf
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
/*     ced0:	0c00c47d */ 	jal	rmonPrintf
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
/*     cefc:	0c00c47d */ 	jal	rmonPrintf
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
/*     cf30:	0c00c47d */ 	jal	rmonPrintf
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
/*     d07c:	0c00c47d */ 	jal	rmonPrintf
/*     d080:	248442b0 */ 	addiu	$a0,$a0,0x42b0
/*     d084:	3c047005 */ 	lui	$a0,0x7005
/*     d088:	0c00c47d */ 	jal	rmonPrintf
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

	rmonPrintf("%s <", label);

	while (description->mask != 0) {
		if ((description->mask & mask) == description->value) {
			if (first) {
				first = false;
			} else {
				rmonPrintf(",");
			}

			rmonPrintf("%s", description->text);
		}

		description++;
	}

	rmonPrintf(">");
}

void crashPutChar(s32 x, s32 y, char c)
{
	if (c == '\t' || c == '\n') {
		c = '\0';
	}

	if ((c > '\0' && c < ' ') || c > '~') {
		c = '?';
	}

	if (x >= 0 && x < 72 && y >= 0 && y <= MAX_LINES && g_CrashCharBuffer != NULL) {
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

	if (g_CrashCurY >= MAX_LINES) {
		crashScroll(g_CrashCurY - MAX_LINES + 1);
		g_CrashCurY = MAX_LINES - 1;
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
		for (y = 0; y < MAX_LINES; y++) {
			for (x = 0; x < 71; x++) {
				g_CrashCharBuffer[y][x] = g_CrashCharBuffer[y + 1][x];
			}
		}
	}
}

#if VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel crashRenderChar
/*  cb44:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  cb48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  cb4c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  cb50:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  cb54:	0c002e4d */ 	jal	viGetWidth
/*  cb58:	afa60020 */ 	sw	$a2,0x20($sp)
/*  cb5c:	93a30023 */ 	lbu	$v1,0x23($sp)
/*  cb60:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  cb64:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  cb68:	54600003 */ 	bnezl	$v1,.PB0000cb78
/*  cb6c:	28610020 */ 	slti	$at,$v1,0x20
/*  cb70:	24030020 */ 	li	$v1,0x20
/*  cb74:	28610020 */ 	slti	$at,$v1,0x20
.PB0000cb78:
/*  cb78:	1420003d */ 	bnez	$at,.PB0000cc70
/*  cb7c:	2861007f */ 	slti	$at,$v1,0x7f
/*  cb80:	1020003b */ 	beqz	$at,.PB0000cc70
/*  cb84:	38490280 */ 	xori	$t1,$v0,0x280
/*  cb88:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*  cb8c:	1120000a */ 	beqz	$t1,.PB0000cbb8
/*  cb90:	00006025 */ 	move	$t4,$zero
/*  cb94:	00c20019 */ 	multu	$a2,$v0
/*  cb98:	3c188006 */ 	lui	$t8,0x8006
/*  cb9c:	8f18e4a4 */ 	lw	$t8,-0x1b5c($t8)
/*  cba0:	00057880 */ 	sll	$t7,$a1,0x2
/*  cba4:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  cba8:	00007012 */ 	mflo	$t6
/*  cbac:	000e7840 */ 	sll	$t7,$t6,0x1
/*  cbb0:	10000009 */ 	b	.PB0000cbd8
/*  cbb4:	032f2021 */ 	addu	$a0,$t9,$t7
.PB0000cbb8:
/*  cbb8:	00c20019 */ 	multu	$a2,$v0
/*  cbbc:	3c0e8006 */ 	lui	$t6,0x8006
/*  cbc0:	8dcee4a4 */ 	lw	$t6,-0x1b5c($t6)
/*  cbc4:	0005c040 */ 	sll	$t8,$a1,0x1
/*  cbc8:	030ec821 */ 	addu	$t9,$t8,$t6
/*  cbcc:	00007812 */ 	mflo	$t7
/*  cbd0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  cbd4:	03382021 */ 	addu	$a0,$t9,$t8
.PB0000cbd8:
/*  cbd8:	00037080 */ 	sll	$t6,$v1,0x2
/*  cbdc:	3c068006 */ 	lui	$a2,0x8006
/*  cbe0:	00ce3021 */ 	addu	$a2,$a2,$t6
/*  cbe4:	8cc6e2a8 */ 	lw	$a2,-0x1d58($a2)
/*  cbe8:	00026840 */ 	sll	$t5,$v0,0x1
/*  cbec:	241f0007 */ 	li	$ra,0x7
/*  cbf0:	240b0004 */ 	li	$t3,0x4
/*  cbf4:	3c0a8000 */ 	lui	$t2,0x8000
/*  cbf8:	24080001 */ 	li	$t0,0x1
/*  cbfc:	24077bdf */ 	li	$a3,0x7bdf
/*  cc00:	00002825 */ 	move	$a1,$zero
.PB0000cc04:
/*  cc04:	00ca1824 */ 	and	$v1,$a2,$t2
/*  cc08:	10600003 */ 	beqz	$v1,.PB0000cc18
/*  cc0c:	00067840 */ 	sll	$t7,$a2,0x1
/*  cc10:	10000002 */ 	b	.PB0000cc1c
/*  cc14:	a4870000 */ 	sh	$a3,0x0($a0)
.PB0000cc18:
/*  cc18:	a4880000 */ 	sh	$t0,0x0($a0)
.PB0000cc1c:
/*  cc1c:	11200006 */ 	beqz	$t1,.PB0000cc38
/*  cc20:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  cc24:	50600004 */ 	beqzl	$v1,.PB0000cc38
/*  cc28:	a4880002 */ 	sh	$t0,0x2($a0)
/*  cc2c:	10000002 */ 	b	.PB0000cc38
/*  cc30:	a4870002 */ 	sh	$a3,0x2($a0)
/*  cc34:	a4880002 */ 	sh	$t0,0x2($a0)
.PB0000cc38:
/*  cc38:	11200002 */ 	beqz	$t1,.PB0000cc44
/*  cc3c:	24840002 */ 	addiu	$a0,$a0,0x2
/*  cc40:	24840002 */ 	addiu	$a0,$a0,0x2
.PB0000cc44:
/*  cc44:	14abffef */ 	bne	$a1,$t3,.PB0000cc04
/*  cc48:	01e03025 */ 	move	$a2,$t7
/*  cc4c:	11200004 */ 	beqz	$t1,.PB0000cc60
/*  cc50:	258c0001 */ 	addiu	$t4,$t4,0x1
/*  cc54:	008d2021 */ 	addu	$a0,$a0,$t5
/*  cc58:	10000003 */ 	b	.PB0000cc68
/*  cc5c:	2484fff0 */ 	addiu	$a0,$a0,-16
.PB0000cc60:
/*  cc60:	008d2021 */ 	addu	$a0,$a0,$t5
/*  cc64:	2484fff8 */ 	addiu	$a0,$a0,-8
.PB0000cc68:
/*  cc68:	559fffe6 */ 	bnel	$t4,$ra,.PB0000cc04
/*  cc6c:	00002825 */ 	move	$a1,$zero
.PB0000cc70:
/*  cc70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  cc74:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  cc78:	03e00008 */ 	jr	$ra
/*  cc7c:	00000000 */ 	nop
);
#elif VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel crashRenderChar
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
#else
/**
 * Render a character to the crash buffer.
 *
 * It looks like the character rendering code has been removed however,
 * so it's just borders that remain.
 */
void crashRenderChar(s32 x, s32 y, char c)
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
			// gray occurs every 32nd pixel
			u32 gray = a2 & 0x80000000;

			if (gray) {
				fbpos[0] = GPACK_RGBA5551(120, 120, 120, 1);
			} else {
				fbpos[0] = GPACK_RGBA5551(0, 0, 0, 1);
			}

			if (hires) {
				if (gray) {
					fbpos[1] = GPACK_RGBA5551(120, 120, 120, 1);
				} else {
					fbpos[1] = GPACK_RGBA5551(0, 0, 0, 1);
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
#endif

void crashReset(void)
{
#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
	g_CrashCharBuffer = var80097178nb;
#else
	g_CrashCharBuffer = NULL;
#endif

	if (g_CrashCharBuffer) {
		// Unreachable
		s32 x;
		s32 y;

		for (y = 0; y < MAX_LINES + 1; y++) {
			for (x = 0; x < 71; x++) {
				g_CrashCharBuffer[y][x] = '\0';
			}
		}
	}
}

void crashRenderFrame(u8 *fb)
{
	s32 width;
	s32 height;
	s32 x;
	s32 y;

	g_CrashFrameBuffer = (u16 *) PHYS_TO_K1(fb);

	width = (viGetWidth() - 13) / 4;
	height = (viGetHeight() - 10) / 7 - 1;

	if (g_CrashCharBuffer != NULL) {
		for (y = 0; y < height && y < MAX_LINES; y++) {
			for (x = 0; x < width - 5 && x < 71; x++) {
				crashRenderChar(20 + x * 4, 7 + y * 7, g_CrashCharBuffer[y][x]);
			}
		}
	}
}
