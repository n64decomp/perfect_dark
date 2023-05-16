#ifdef DEBUG

#include <ultra64.h>
#include <stdarg.h>
#include "os_internal.h"
#include "lib/libc/xprintf.h"
#include "constants.h"
#include "bss.h"
#include "lib/tlb.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/sched.h"
#include "lib/str.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

#define MSG_FAULT 0x10

#define MAX_LINES 29

OSThread g_FaultThread;
u8 g_FaultStack[STACKSIZE_FAULT];
OSMesgQueue g_FaultMesgQueue;
OSMesg g_FaultMesg;

bool g_CrashEnabled = false;

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

u32 var8005f138nb[] = {
	0x00000000, 0x22220200, 0x55000000, 0x05f5f500,
	0x27427200, 0x05124500, 0x34255300, 0x22000000,
	0x24444420, 0x42222240, 0x06f6f600, 0x00272000,
	0x00000240, 0x00070000, 0x00000200, 0x11224480,
	0x25555200, 0x26222700, 0x25125700, 0x61211600,
	0x33557300, 0x64611600, 0x24655200, 0x71112200,
	0x25755200, 0x25531600, 0x00200200, 0x00200640,
	0x01242100, 0x00707000, 0x04212400, 0x07120200,
	0x25ff5700, 0x02557d00, 0x06575e00, 0x07445300,
	0x07555600, 0x07565700, 0x07564400, 0x07c95700,
	0x05575500, 0x07222700, 0x03111600, 0x05665500,
	0x04445f00, 0x0dff9d00, 0x0f777d00, 0x07dd5700,
	0x07564600, 0x07995770, 0x07565500, 0x07461e00,
	0x07222200, 0x0d999600, 0x0d552200, 0x0df77500,
	0x0d625500, 0x05622600, 0x07125700, 0x32222230,
	0x44222110, 0x62222260, 0x25000000, 0x00000700,
	0x42200000, 0x0067d700, 0x44755700, 0x00788600,
	0x117dd700, 0x006fc700, 0x32722700, 0x007dd730,
	0x44755500, 0x02622700, 0x02711130, 0x44766500,
	0x62222700, 0x00ffff00, 0x00755d00, 0x006dd600,
	0x00755740, 0x00799710, 0x00744600, 0x00775700,
	0x02722300, 0x00555700, 0x00552200, 0x00577500,
	0x00562500, 0x00552220, 0x00703700, 0x12242210,
	0x02222220, 0x42212240, 0x005a0000,
};

u16 *g_CrashFrameBuffer = NULL;

extern u32 _libSegmentStart;
extern u32 _libSegmentEnd;

static void faultproc(void *arg0);
static u32 crashGenerate(OSThread *thread, u32 *callstack, s32 *tracelen);
static void crashPrintDescription(u32 mask, char *label, struct crashdescription *descriptions);
static void crashAppendChar(char c);
static void crashScroll(s32 numlines);

void schedSetCrashedUnexpectedly(bool enable);

void crashCreateThread(void)
{
	osCreateMesgQueue(&g_FaultMesgQueue, &g_FaultMesg, 1);
	osCreateThread(&g_FaultThread, THREAD_FAULT, faultproc, NULL, &g_FaultStack[STACKSIZE_FAULT], THREADPRI_FAULT);
	osStartThread(&g_FaultThread);
}

static void faultproc(void *arg0)
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
		osRecvMesg(&g_FaultMesgQueue, &msg, OS_MESG_BLOCK);
		mask = osSetIntMask(1);
		curr = __osGetCurrFaultedThread();

		if (1);

		if (!curr) {
			continue;
		}

		osSetIntMask(mask);

		crashGenerate(curr, callstack, &tracelen);
		schedSetCrashedUnexpectedly(true);
	}
}

char var80097178nb[MAX_LINES + 1][71];

static bool crashIsReturnAddress(u32 *instruction)
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

static char *rmonProut(char *dst, const char *src, size_t count)
{
	s32 i = 0;

	while (i != count) {
		crashAppendChar(src[i++]);
	}

	return (char *) 1;
}

void rmonPrintf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	_Printf(rmonProut, NULL, format, ap);
}

static u32 crashGetStackEnd(u32 sp, s32 tid)
{
	u32 start;
	u32 end;

	if (tid <= 0 || tid > 6U) {
		rmonPrintf("Bad tid\n");
		return 0;
	}

	start = (u32)g_StackLeftAddrs[tid];
	end = (u32)g_StackRightAddrs[tid];

	if (sp >= K0BASE) {
		return end;
	}

	return (sp & 0xf0000000) | (end - start);
}

static u32 crashGetStackStart(u32 sp, s32 tid)
{
	u32 start;

	if (tid <= 0 || tid > 6U) {
		rmonPrintf("Bad tid\n");
		return 0;
	}

	start = (u32)g_StackLeftAddrs[tid];

	if (sp >= K0BASE) {
		return start;
	}

	return sp & 0xf0000000;
}

static bool crashIsDouble(f32 value)
{
	u32 bits = *(u32*)&value;
	u32 fraction = bits & 0x7fffff;
	u8 exponent = (u8)(bits >> 23);

	return fraction == 0 || (exponent != 0 && exponent != 0xff);
}

static void crashPrintFloat(s32 index, f32 value)
{
	if (crashIsDouble(value)) {
		rmonPrintf("%s%s%02d: % .7e ", "", "", index, (f64)value);
	} else {
		u32 bits = *(u32 *)&value;
		rmonPrintf("%02d: I%d.%03d.%07d ", index, (bits & 0x80000000) >> 31, (bits & 0x7f800000) >> 23, bits & 0x7fffff);
	}
}

static void crashPrint2Floats(s32 index, f32 value1, f32 value2)
{
	crashPrintFloat(index, value1);
	rmonPrintf(" ");

	crashPrintFloat(index + 1, value2);
	rmonPrintf("\n");
}

static void crashPrint3Floats(s32 index, f32 value1, f32 value2, f32 value3)
{
	crashPrintFloat(index, value1);
	rmonPrintf(" ");

	crashPrintFloat(index + 1, value2);
	rmonPrintf(" ");

	crashPrintFloat(index + 2, value3);
	rmonPrintf("\n");
}

static u32 crashGenerate(OSThread *thread, u32 *callstack, s32 *tracelen)
{
	s32 i;
	u32 ptr;
	u32 *sp;
	u32 regs[32];
	u32 *stackend;
	u32 *stackstart;
	__OSThreadContext *ctx = &thread->context;
	bool done;
	u32 *tmpsp;

	rmonPrintf("\n\nFAULT-\n");

	if (!g_Vars.fourmeg2player) {
		// Print a stack trace in a dodgy way.
		// It works by iterating through the stack allocation, looking for any
		// values which could potentially be a return address, and prints them.
		u32 *stackend = (u32 *) crashGetStackEnd(ctx->sp, thread->id);
		rmonPrintf("DodgyStackTrace: %08llx ", ctx->ra & 0xffffffff);
		tmpsp = (u32 *) ctx->sp;

		while (tmpsp < stackend) {
			if (crashIsReturnAddress((u32 *)*tmpsp)) {
				rmonPrintf("%08x ", *tmpsp);
			}

			tmpsp++;
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

	rmonPrintf("\n");
	rmonPrintf("\n");

	return 0;
}

static void crashPrintDescription(u32 mask, char *label, struct crashdescription *description)
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

static void crashPutChar(s32 x, s32 y, char c)
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

static void crashAppendChar(char c)
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

static void crashScroll(s32 numlines)
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

/**
 * Render a character to the crash buffer.
 */
static void crashRenderChar(s32 x, s32 y, char c)
{
	s32 i;
	s32 j;
	s32 width;
	u16 *fbpos;
	bool hires;
	s32 tmp;
	u32 a2;

	width = g_ViBackData->x;

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

	a2 = var8005f138nb[c - ' '];

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 4; j++) {
			u32 gray = a2 & 0x80000000;

			if (gray) {
				fbpos[0] = GPACK_RGBA5551(0x78, 0x78, 0x78, 1);
			} else {
				fbpos[0] = GPACK_RGBA5551(0, 0, 0, 1);
			}

			if (hires) {
				if (gray) {
					fbpos[1] = GPACK_RGBA5551(0x78, 0x78, 0x78, 1);
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

void crashReset(void)
{
	g_CrashCharBuffer = var80097178nb;

	if (g_CrashCharBuffer) {
		s32 x;
		s32 y;

		for (y = 0; y < MAX_LINES + 1; y++) {
			for (x = 0; x < 71; x++) {
				g_CrashCharBuffer[y][x] = '\0';
			}
		}
	}
}

void crashRenderFrame(u16 *fb)
{
	s32 width;
	s32 height;
	s32 x;
	s32 y;

	g_CrashFrameBuffer = (u16 *) PHYS_TO_K1(fb);

	width = (g_ViBackData->x - 13) / 4;
	height = (g_ViBackData->y - 10) / 7 - 1;

	if (g_CrashCharBuffer != NULL) {
		for (y = 0; y < height && y < MAX_LINES; y++) {
			for (x = 0; x < width - 5 && x < 71; x++) {
				crashRenderChar(20 + x * 4, 7 + y * 7, g_CrashCharBuffer[y][x]);
			}
		}
	}
}

#endif
