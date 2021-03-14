#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/entry.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

u32 var8005d5b0 = 0x00000000;
s16 g_CrashCurX = 0;
s16 g_CrashCurY = 0;

struct crashdescription {
	u32 mask;
	u32 value;
	const char *text;
};

struct crashdescription g_CrashCauseDescriptions[] = {
	{ 0x80000000, 0x80000000, "BD"                                              },
	{ 0x00008000, 0x00008000, "IP8"                                             },
	{ 0x00004000, 0x00004000, "IP7"                                             },
	{ 0x00002000, 0x00002000, "IP6"                                             },
	{ 0x00001000, 0x00001000, "IP5"                                             },
	{ 0x00000800, 0x00000800, "IP4"                                             },
	{ 0x00000400, 0x00000400, "IP3"                                             },
	{ 0x00000200, 0x00000200, "IP2"                                             },
	{ 0x00000100, 0x00000100, "IP1"                                             },
	{ 0x0000007c, 0x00000000, "Int"                                             },
	{ 0x0000007c, 0x00000004, "TLBmod"                                          },
	{ 0x0000007c, 0x00000008, "TLBload"                                         },
	{ 0x0000007c, 0x0000000c, "TLBstore"                                        },
	{ 0x0000007c, 0x00000010, "Address error on load or instruction fetch"      },
	{ 0x0000007c, 0x00000014, "Address error on store"                          },
	{ 0x0000007c, 0x00000018, "Bus error exception on instruction fetch"        },
	{ 0x0000007c, 0x0000001c, "Bus error exception on data reference"           },
	{ 0x0000007c, 0x00000020, "Syscall"                                         },
	{ 0x0000007c, 0x00000024, "Brk"                                             },
	{ 0x0000007c, 0x00000028, "Reserved instruction"                            },
	{ 0x0000007c, 0x0000002c, "Cop unusable"                                    },
	{ 0x0000007c, 0x00000030, "Overflow"                                        },
	{ 0x0000007c, 0x00000034, "Trap"                                            },
	{ 0x0000007c, 0x00000038, "Virtual coherency exception on intruction fetch" },
	{ 0x0000007c, 0x0000003c, "Fp exception"                                    },
	{ 0x0000007c, 0x0000005c, "Watchpoint"                                      },
	{ 0x0000007c, 0x0000007c, "Virtual coherency exception on data reference"   },
	{ 0x00000000, 0x00000000, ""                                                },
	{ 0x80000000, 0x80000000, "CU3"                                             },
	{ 0x40000000, 0x40000000, "CU2"                                             },
	{ 0x20000000, 0x20000000, "CU1"                                             },
	{ 0x10000000, 0x10000000, "CU0"                                             },
	{ 0x08000000, 0x08000000, "RP"                                              },
	{ 0x04000000, 0x04000000, "FR"                                              },
	{ 0x02000000, 0x02000000, "RE"                                              },
	{ 0x00400000, 0x00400000, "BEV"                                             },
	{ 0x00200000, 0x00200000, "TS"                                              },
	{ 0x00100000, 0x00100000, "SR"                                              },
	{ 0x00040000, 0x00040000, "CH"                                              },
	{ 0x00020000, 0x00020000, "CE"                                              },
	{ 0x00010000, 0x00010000, "DE"                                              },
	{ 0x00008000, 0x00008000, "IM8"                                             },
	{ 0x00004000, 0x00004000, "IM7"                                             },
	{ 0x00002000, 0x00002000, "IM6"                                             },
	{ 0x00001000, 0x00001000, "IM5"                                             },
	{ 0x00000800, 0x00000800, "IM4"                                             },
	{ 0x00000400, 0x00000400, "IM3"                                             },
	{ 0x00000200, 0x00000200, "IM2"                                             },
	{ 0x00000100, 0x00000100, "IM1"                                             },
	{ 0x00000080, 0x00000080, "KX"                                              },
	{ 0x00000040, 0x00000040, "SX"                                              },
	{ 0x00000020, 0x00000020, "UX"                                              },
	{ 0x00000018, 0x00000010, "USR"                                             },
	{ 0x00000018, 0x00000008, "SUP"                                             },
	{ 0x00000018, 0x00000000, "KER"                                             },
	{ 0x00000004, 0x00000004, "ERL"                                             },
	{ 0x00000002, 0x00000002, "EXL"                                             },
	{ 0x00000001, 0x00000001, "IE"                                              },
	{ 0x00000000, 0x00000000, ""                                                },
};

struct crashdescription g_CrashFpcsrDescriptions[] = {
	{ 0x01000000, 0x01000000, "FS"            },
	{ 0x00800000, 0x00800000, "C"             },
	{ 0x00020000, 0x00020000, "Unimplemented" },
	{ 0x00010000, 0x00010000, "Invalid op"    },
	{ 0x00008000, 0x00008000, "/ by 0.0"      },
	{ 0x00004000, 0x00004000, "Overflow"      },
	{ 0x00002000, 0x00002000, "Underflow"     },
	{ 0x00001000, 0x00001000, "Inexact op"    },
	{ 0x00000800, 0x00000800, "EV"            },
	{ 0x00000400, 0x00000400, "EZ"            },
	{ 0x00000200, 0x00000200, "EO"            },
	{ 0x00000100, 0x00000100, "EU"            },
	{ 0x00000080, 0x00000080, "EI"            },
	{ 0x00000040, 0x00000040, "FV"            },
	{ 0x00000020, 0x00000020, "FZ"            },
	{ 0x00000010, 0x00000010, "FO"            },
	{ 0x00000008, 0x00000008, "FU"            },
	{ 0x00000004, 0x00000004, "FI"            },
	{ 0x00000003, 0x00000000, "RN"            },
	{ 0x00000003, 0x00000001, "RZ"            },
	{ 0x00000003, 0x00000002, "RP"            },
	{ 0x00000003, 0x00000003, "RM"            },
	{ 0x00000000, 0x00000000, ""              },
};

char (*g_CrashCharBuffer)[71] = NULL;
u32 var8005d998 = 0;

extern u32 _libSegmentStart;
extern u32 _libSegmentEnd;

void faultproc(void *arg0);
void crashPrintDescription(u32 mask, char *label, struct crashdescription *descriptions);

void faultCreateThread2(void)
{
	osCreateMesgQueue(&g_FaultMesgQueue, &g_FaultMesg, 1);
	osCreateThread(&g_FaultThread, THREAD_FAULT, faultproc, NULL, &g_FaultSp, THREADPRI_FAULT);
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

GLOBAL_ASM(
glabel func0000c118
/*     c118:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*     c11c:	afa40010 */ 	sw	$a0,0x10($sp)
/*     c120:	afb1000c */ 	sw	$s1,0xc($sp)
/*     c124:	afb00008 */ 	sw	$s0,0x8($sp)
/*     c128:	00c01825 */ 	or	$v1,$a2,$zero
/*     c12c:	00001025 */ 	or	$v0,$zero,$zero
/*     c130:	00004025 */ 	or	$t0,$zero,$zero
/*     c134:	24040020 */ 	addiu	$a0,$zero,0x20
/*     c138:	00004825 */ 	or	$t1,$zero,$zero
/*     c13c:	00e05025 */ 	or	$t2,$a3,$zero
.L0000c140:
/*     c140:	25290001 */ 	addiu	$t1,$t1,0x1
/*     c144:	ad400000 */ 	sw	$zero,0x0($t2)
/*     c148:	1524fffd */ 	bne	$t1,$a0,.L0000c140
/*     c14c:	254a0004 */ 	addiu	$t2,$t2,0x4
/*     c150:	8fa40010 */ 	lw	$a0,0x10($sp)
/*     c154:	3c1103e0 */ 	lui	$s1,0x3e0
/*     c158:	36310008 */ 	ori	$s1,$s1,0x8
/*     c15c:	0085082b */ 	sltu	$at,$a0,$a1
/*     c160:	1420002d */ 	bnez	$at,.L0000c218
/*     c164:	2410001f */ 	addiu	$s0,$zero,0x1f
/*     c168:	3c0dffe0 */ 	lui	$t5,0xffe0
/*     c16c:	3c0cafa0 */ 	lui	$t4,0xafa0
/*     c170:	3c0bffff */ 	lui	$t3,0xffff
/*     c174:	3c0a27bd */ 	lui	$t2,0x27bd
/*     c178:	8c890000 */ 	lw	$t1,0x0($a0)
.L0000c17c:
/*     c17c:	2484fffc */ 	addiu	$a0,$a0,-4
/*     c180:	0085082b */ 	sltu	$at,$a0,$a1
/*     c184:	012b7824 */ 	and	$t7,$t1,$t3
/*     c188:	154f000b */ 	bne	$t2,$t7,.L0000c1b8
/*     c18c:	012dc024 */ 	and	$t8,$t1,$t5
/*     c190:	0009c400 */ 	sll	$t8,$t1,0x10
/*     c194:	0018cc03 */ 	sra	$t9,$t8,0x10
/*     c198:	1f20001f */ 	bgtz	$t9,.L0000c218
/*     c19c:	24020001 */ 	addiu	$v0,$zero,0x1
/*     c1a0:	00197083 */ 	sra	$t6,$t9,0x2
/*     c1a4:	000e7880 */ 	sll	$t7,$t6,0x2
/*     c1a8:	11000019 */ 	beqz	$t0,.L0000c210
/*     c1ac:	006f1823 */ 	subu	$v1,$v1,$t7
/*     c1b0:	10000019 */ 	b	.L0000c218
/*     c1b4:	00000000 */ 	nop
.L0000c1b8:
/*     c1b8:	15980013 */ 	bne	$t4,$t8,.L0000c208
/*     c1bc:	00093402 */ 	srl	$a2,$t1,0x10
/*     c1c0:	30d9001f */ 	andi	$t9,$a2,0x1f
/*     c1c4:	00097c00 */ 	sll	$t7,$t1,0x10
/*     c1c8:	000fc403 */ 	sra	$t8,$t7,0x10
/*     c1cc:	03203025 */ 	or	$a2,$t9,$zero
/*     c1d0:	0018c883 */ 	sra	$t9,$t8,0x2
/*     c1d4:	00197080 */ 	sll	$t6,$t9,0x2
/*     c1d8:	0006c080 */ 	sll	$t8,$a2,0x2
/*     c1dc:	00f8c821 */ 	addu	$t9,$a3,$t8
/*     c1e0:	01c37821 */ 	addu	$t7,$t6,$v1
/*     c1e4:	16060002 */ 	bne	$s0,$a2,.L0000c1f0
/*     c1e8:	af2f0000 */ 	sw	$t7,0x0($t9)
/*     c1ec:	24080001 */ 	addiu	$t0,$zero,0x1
.L0000c1f0:
/*     c1f0:	10400007 */ 	beqz	$v0,.L0000c210
/*     c1f4:	00000000 */ 	nop
/*     c1f8:	11000005 */ 	beqz	$t0,.L0000c210
/*     c1fc:	00000000 */ 	nop
/*     c200:	10000005 */ 	b	.L0000c218
/*     c204:	00000000 */ 	nop
.L0000c208:
/*     c208:	11310003 */ 	beq	$t1,$s1,.L0000c218
/*     c20c:	00000000 */ 	nop
.L0000c210:
/*     c210:	5020ffda */ 	beqzl	$at,.L0000c17c
/*     c214:	8c890000 */ 	lw	$t1,0x0($a0)
.L0000c218:
/*     c218:	10400005 */ 	beqz	$v0,.L0000c230
/*     c21c:	8fb00008 */ 	lw	$s0,0x8($sp)
/*     c220:	51000004 */ 	beqzl	$t0,.L0000c234
/*     c224:	00001025 */ 	or	$v0,$zero,$zero
/*     c228:	10000002 */ 	b	.L0000c234
/*     c22c:	00601025 */ 	or	$v0,$v1,$zero
.L0000c230:
/*     c230:	00001025 */ 	or	$v0,$zero,$zero
.L0000c234:
/*     c234:	8fb1000c */ 	lw	$s1,0xc($sp)
/*     c238:	03e00008 */ 	jr	$ra
/*     c23c:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

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

GLOBAL_ASM(
glabel crashIsDouble
/*     c398:	e7ac0000 */ 	swc1	$f12,0x0($sp)
/*     c39c:	8fa40000 */ 	lw	$a0,0x0($sp)
/*     c3a0:	3c01007f */ 	lui	$at,0x7f
/*     c3a4:	3421ffff */ 	ori	$at,$at,0xffff
/*     c3a8:	00811024 */ 	and	$v0,$a0,$at
/*     c3ac:	2c4e0001 */ 	sltiu	$t6,$v0,0x1
/*     c3b0:	15c00008 */ 	bnez	$t6,.L0000c3d4
/*     c3b4:	01c01025 */ 	or	$v0,$t6,$zero
/*     c3b8:	00041dc2 */ 	srl	$v1,$a0,0x17
/*     c3bc:	306f00ff */ 	andi	$t7,$v1,0xff
/*     c3c0:	000f102b */ 	sltu	$v0,$zero,$t7
/*     c3c4:	10400003 */ 	beqz	$v0,.L0000c3d4
/*     c3c8:	00000000 */ 	nop
/*     c3cc:	39e200ff */ 	xori	$v0,$t7,0xff
/*     c3d0:	0002102b */ 	sltu	$v0,$zero,$v0
.L0000c3d4:
/*     c3d4:	03e00008 */ 	jr	$ra
/*     c3d8:	00000000 */ 	nop
);

//bool crashIsDouble(f32 value)
//{
//	u32 bits = *(u32 *)&value;
//
//	return (bits & 0x7fffff) != 0
//		&& ((bits >> 23) & 0xff) != 0
//		&& ((bits >> 23) & 0xff) != 0xff;
//}

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
	u32 sp64[32];
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
		sp = (u32 *) func0000c118(ptr, &_libSegmentStart, (u32)sp, sp64);
		crashPrint(" %08x ", ptr);

		callstack[*tracelen] = ptr;
		*tracelen = *tracelen + 1;

		if (i == 4) {
			crashPrint("\n       ");
		}

		if (sp == NULL) {
			sp = (u32 *)ctx->sp;
		}

		if (sp64[31] == 0) {
			ptr = ctx->ra;
		} else {
			ptr = *(u32 *)(sp64[31]);
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

GLOBAL_ASM(
glabel func0000cdc8
/*     cdc8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     cdcc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     cdd0:	afa40018 */ 	sw	$a0,0x18($sp)
/*     cdd4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*     cdd8:	0c002f02 */ 	jal	viGetWidth
/*     cddc:	afa60020 */ 	sw	$a2,0x20($sp)
/*     cde0:	93a30023 */ 	lbu	$v1,0x23($sp)
/*     cde4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*     cde8:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*     cdec:	54600003 */ 	bnezl	$v1,.L0000cdfc
/*     cdf0:	28610020 */ 	slti	$at,$v1,0x20
/*     cdf4:	24030020 */ 	addiu	$v1,$zero,0x20
/*     cdf8:	28610020 */ 	slti	$at,$v1,0x20
.L0000cdfc:
/*     cdfc:	1420003a */ 	bnez	$at,.L0000cee8
/*     ce00:	2861007f */ 	slti	$at,$v1,0x7f
/*     ce04:	10200038 */ 	beqz	$at,.L0000cee8
/*     ce08:	38490280 */ 	xori	$t1,$v0,0x280
/*     ce0c:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*     ce10:	1120000a */ 	beqz	$t1,.L0000ce3c
/*     ce14:	00006025 */ 	or	$t4,$zero,$zero
/*     ce18:	00c20019 */ 	multu	$a2,$v0
/*     ce1c:	3c188006 */ 	lui	$t8,%hi(var8005d998)
/*     ce20:	8f18d998 */ 	lw	$t8,%lo(var8005d998)($t8)
/*     ce24:	00057880 */ 	sll	$t7,$a1,0x2
/*     ce28:	01f8c821 */ 	addu	$t9,$t7,$t8
/*     ce2c:	00007012 */ 	mflo	$t6
/*     ce30:	000e7840 */ 	sll	$t7,$t6,0x1
/*     ce34:	10000009 */ 	b	.L0000ce5c
/*     ce38:	032f2021 */ 	addu	$a0,$t9,$t7
.L0000ce3c:
/*     ce3c:	00c20019 */ 	multu	$a2,$v0
/*     ce40:	3c0e8006 */ 	lui	$t6,%hi(var8005d998)
/*     ce44:	8dced998 */ 	lw	$t6,%lo(var8005d998)($t6)
/*     ce48:	0005c040 */ 	sll	$t8,$a1,0x1
/*     ce4c:	030ec821 */ 	addu	$t9,$t8,$t6
/*     ce50:	00007812 */ 	mflo	$t7
/*     ce54:	000fc040 */ 	sll	$t8,$t7,0x1
/*     ce58:	03382021 */ 	addu	$a0,$t9,$t8
.L0000ce5c:
/*     ce5c:	00003025 */ 	or	$a2,$zero,$zero
/*     ce60:	00026840 */ 	sll	$t5,$v0,0x1
/*     ce64:	241f0007 */ 	addiu	$ra,$zero,0x7
/*     ce68:	240b0004 */ 	addiu	$t3,$zero,0x4
/*     ce6c:	3c0a8000 */ 	lui	$t2,0x8000
/*     ce70:	24080001 */ 	addiu	$t0,$zero,0x1
/*     ce74:	24077bdf */ 	addiu	$a3,$zero,0x7bdf
/*     ce78:	00002825 */ 	or	$a1,$zero,$zero
.L0000ce7c:
/*     ce7c:	00ca1824 */ 	and	$v1,$a2,$t2
/*     ce80:	10600003 */ 	beqz	$v1,.L0000ce90
/*     ce84:	00067040 */ 	sll	$t6,$a2,0x1
/*     ce88:	10000002 */ 	b	.L0000ce94
/*     ce8c:	a4870000 */ 	sh	$a3,0x0($a0)
.L0000ce90:
/*     ce90:	a4880000 */ 	sh	$t0,0x0($a0)
.L0000ce94:
/*     ce94:	11200006 */ 	beqz	$t1,.L0000ceb0
/*     ce98:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     ce9c:	50600004 */ 	beqzl	$v1,.L0000ceb0
/*     cea0:	a4880002 */ 	sh	$t0,0x2($a0)
/*     cea4:	10000002 */ 	b	.L0000ceb0
/*     cea8:	a4870002 */ 	sh	$a3,0x2($a0)
/*     ceac:	a4880002 */ 	sh	$t0,0x2($a0)
.L0000ceb0:
/*     ceb0:	11200002 */ 	beqz	$t1,.L0000cebc
/*     ceb4:	24840002 */ 	addiu	$a0,$a0,0x2
/*     ceb8:	24840002 */ 	addiu	$a0,$a0,0x2
.L0000cebc:
/*     cebc:	14abffef */ 	bne	$a1,$t3,.L0000ce7c
/*     cec0:	01c03025 */ 	or	$a2,$t6,$zero
/*     cec4:	11200004 */ 	beqz	$t1,.L0000ced8
/*     cec8:	258c0001 */ 	addiu	$t4,$t4,0x1
/*     cecc:	008d2021 */ 	addu	$a0,$a0,$t5
/*     ced0:	10000003 */ 	b	.L0000cee0
/*     ced4:	2484fff0 */ 	addiu	$a0,$a0,-16
.L0000ced8:
/*     ced8:	008d2021 */ 	addu	$a0,$a0,$t5
/*     cedc:	2484fff8 */ 	addiu	$a0,$a0,-8
.L0000cee0:
/*     cee0:	559fffe6 */ 	bnel	$t4,$ra,.L0000ce7c
/*     cee4:	00002825 */ 	or	$a1,$zero,$zero
.L0000cee8:
/*     cee8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     ceec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     cef0:	03e00008 */ 	jr	$ra
/*     cef4:	00000000 */ 	nop
);

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

	var8005d998 = (u32)fb | 0xa0000000;

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
