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
u32 var8005d5b4 = 0x00000000;
u32 var8005d5b8 = 0x00000000;

struct crashdescription {
	u32 mask;
	u32 value;
	const char *text;
};

struct var8005d994 {
	u8 unk00[30][71];
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

struct var8005d994 *var8005d994 = NULL;
u32 var8005d998 = 0;

extern u32 _libSegmentStart;

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

extern u32 _libSegmentEnd;

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

GLOBAL_ASM(
glabel func0000cba0
/*     cba0:	30ce00ff */ 	andi	$t6,$a2,0xff
/*     cba4:	afa60008 */ 	sw	$a2,0x8($sp)
/*     cba8:	24010009 */ 	addiu	$at,$zero,0x9
/*     cbac:	01c03025 */ 	or	$a2,$t6,$zero
/*     cbb0:	11c10004 */ 	beq	$t6,$at,.L0000cbc4
/*     cbb4:	01c01025 */ 	or	$v0,$t6,$zero
/*     cbb8:	2401000a */ 	addiu	$at,$zero,0xa
/*     cbbc:	15c10003 */ 	bne	$t6,$at,.L0000cbcc
/*     cbc0:	00000000 */ 	nop
.L0000cbc4:
/*     cbc4:	00003025 */ 	or	$a2,$zero,$zero
/*     cbc8:	00001025 */ 	or	$v0,$zero,$zero
.L0000cbcc:
/*     cbcc:	18400002 */ 	blez	$v0,.L0000cbd8
/*     cbd0:	28410020 */ 	slti	$at,$v0,0x20
/*     cbd4:	14200003 */ 	bnez	$at,.L0000cbe4
.L0000cbd8:
/*     cbd8:	2841007f */ 	slti	$at,$v0,0x7f
/*     cbdc:	14200002 */ 	bnez	$at,.L0000cbe8
/*     cbe0:	00000000 */ 	nop
.L0000cbe4:
/*     cbe4:	2406003f */ 	addiu	$a2,$zero,0x3f
.L0000cbe8:
/*     cbe8:	04800010 */ 	bltz	$a0,.L0000cc2c
/*     cbec:	28810048 */ 	slti	$at,$a0,0x48
/*     cbf0:	1020000e */ 	beqz	$at,.L0000cc2c
/*     cbf4:	00000000 */ 	nop
/*     cbf8:	04a0000c */ 	bltz	$a1,.L0000cc2c
/*     cbfc:	28a1001e */ 	slti	$at,$a1,0x1e
/*     cc00:	1020000a */ 	beqz	$at,.L0000cc2c
/*     cc04:	3c028006 */ 	lui	$v0,%hi(var8005d994)
/*     cc08:	8c42d994 */ 	lw	$v0,%lo(var8005d994)($v0)
/*     cc0c:	000578c0 */ 	sll	$t7,$a1,0x3
/*     cc10:	01e57821 */ 	addu	$t7,$t7,$a1
/*     cc14:	10400005 */ 	beqz	$v0,.L0000cc2c
/*     cc18:	000f78c0 */ 	sll	$t7,$t7,0x3
/*     cc1c:	01e57823 */ 	subu	$t7,$t7,$a1
/*     cc20:	004fc021 */ 	addu	$t8,$v0,$t7
/*     cc24:	0304c821 */ 	addu	$t9,$t8,$a0
/*     cc28:	a3260000 */ 	sb	$a2,0x0($t9)
.L0000cc2c:
/*     cc2c:	03e00008 */ 	jr	$ra
/*     cc30:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000cc34
/*     cc34:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     cc38:	308600ff */ 	andi	$a2,$a0,0xff
/*     cc3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     cc40:	afb00018 */ 	sw	$s0,0x18($sp)
/*     cc44:	afa40028 */ 	sw	$a0,0x28($sp)
/*     cc48:	10c0003b */ 	beqz	$a2,.L0000cd38
/*     cc4c:	00c01025 */ 	or	$v0,$a2,$zero
/*     cc50:	24010009 */ 	addiu	$at,$zero,0x9
/*     cc54:	14c1000a */ 	bne	$a2,$at,.L0000cc80
/*     cc58:	3c108006 */ 	lui	$s0,%hi(var8005d5b4)
/*     cc5c:	2610d5b4 */ 	addiu	$s0,$s0,%lo(var8005d5b4)
.L0000cc60:
/*     cc60:	0c00330d */ 	jal	func0000cc34
/*     cc64:	24040020 */ 	addiu	$a0,$zero,0x20
/*     cc68:	860e0000 */ 	lh	$t6,0x0($s0)
/*     cc6c:	31cf0007 */ 	andi	$t7,$t6,0x7
/*     cc70:	15e0fffb */ 	bnez	$t7,.L0000cc60
/*     cc74:	00000000 */ 	nop
/*     cc78:	10000030 */ 	b	.L0000cd3c
/*     cc7c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000cc80:
/*     cc80:	2401000a */ 	addiu	$at,$zero,0xa
/*     cc84:	14410008 */ 	bne	$v0,$at,.L0000cca8
/*     cc88:	3c038006 */ 	lui	$v1,%hi(var8005d5b8)
/*     cc8c:	2463d5b8 */ 	addiu	$v1,$v1,%lo(var8005d5b8)
/*     cc90:	84780000 */ 	lh	$t8,0x0($v1)
/*     cc94:	3c108006 */ 	lui	$s0,%hi(var8005d5b4)
/*     cc98:	2610d5b4 */ 	addiu	$s0,$s0,%lo(var8005d5b4)
/*     cc9c:	27190001 */ 	addiu	$t9,$t8,0x1
/*     cca0:	a4790000 */ 	sh	$t9,0x0($v1)
/*     cca4:	a6000000 */ 	sh	$zero,0x0($s0)
.L0000cca8:
/*     cca8:	3c038006 */ 	lui	$v1,%hi(var8005d5b8)
/*     ccac:	2463d5b8 */ 	addiu	$v1,$v1,%lo(var8005d5b8)
/*     ccb0:	84650000 */ 	lh	$a1,0x0($v1)
/*     ccb4:	3c108006 */ 	lui	$s0,%hi(var8005d5b4)
/*     ccb8:	2610d5b4 */ 	addiu	$s0,$s0,%lo(var8005d5b4)
/*     ccbc:	28a1001d */ 	slti	$at,$a1,0x1d
/*     ccc0:	1420000a */ 	bnez	$at,.L0000ccec
/*     ccc4:	24a4ffe4 */ 	addiu	$a0,$a1,-28
/*     ccc8:	afa20024 */ 	sw	$v0,0x24($sp)
/*     cccc:	0c003353 */ 	jal	func0000cd4c
/*     ccd0:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*     ccd4:	3c038006 */ 	lui	$v1,%hi(var8005d5b8)
/*     ccd8:	2463d5b8 */ 	addiu	$v1,$v1,%lo(var8005d5b8)
/*     ccdc:	2408001c */ 	addiu	$t0,$zero,0x1c
/*     cce0:	8fa20024 */ 	lw	$v0,0x24($sp)
/*     cce4:	93a6002b */ 	lbu	$a2,0x2b($sp)
/*     cce8:	a4680000 */ 	sh	$t0,0x0($v1)
.L0000ccec:
/*     ccec:	2401000a */ 	addiu	$at,$zero,0xa
/*     ccf0:	50410012 */ 	beql	$v0,$at,.L0000cd3c
/*     ccf4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     ccf8:	86040000 */ 	lh	$a0,0x0($s0)
/*     ccfc:	0c0032e8 */ 	jal	func0000cba0
/*     cd00:	84650000 */ 	lh	$a1,0x0($v1)
/*     cd04:	86090000 */ 	lh	$t1,0x0($s0)
/*     cd08:	3c038006 */ 	lui	$v1,%hi(var8005d5b8)
/*     cd0c:	2463d5b8 */ 	addiu	$v1,$v1,%lo(var8005d5b8)
/*     cd10:	252a0001 */ 	addiu	$t2,$t1,0x1
/*     cd14:	a60a0000 */ 	sh	$t2,0x0($s0)
/*     cd18:	860b0000 */ 	lh	$t3,0x0($s0)
/*     cd1c:	29610047 */ 	slti	$at,$t3,0x47
/*     cd20:	54200006 */ 	bnezl	$at,.L0000cd3c
/*     cd24:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     cd28:	846c0000 */ 	lh	$t4,0x0($v1)
/*     cd2c:	a6000000 */ 	sh	$zero,0x0($s0)
/*     cd30:	258d0001 */ 	addiu	$t5,$t4,0x1
/*     cd34:	a46d0000 */ 	sh	$t5,0x0($v1)
.L0000cd38:
/*     cd38:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000cd3c:
/*     cd3c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     cd40:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*     cd44:	03e00008 */ 	jr	$ra
/*     cd48:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000cd4c
/*     cd4c:	3c068006 */ 	lui	$a2,%hi(var8005d994)
/*     cd50:	24c6d994 */ 	addiu	$a2,$a2,%lo(var8005d994)
/*     cd54:	8cce0000 */ 	lw	$t6,0x0($a2)
/*     cd58:	0004102a */ 	slt	$v0,$zero,$a0
/*     cd5c:	11c00018 */ 	beqz	$t6,.L0000cdc0
/*     cd60:	00000000 */ 	nop
/*     cd64:	10400016 */ 	beqz	$v0,.L0000cdc0
/*     cd68:	2484ffff */ 	addiu	$a0,$a0,-1
/*     cd6c:	2408001d */ 	addiu	$t0,$zero,0x1d
/*     cd70:	24070047 */ 	addiu	$a3,$zero,0x47
.L0000cd74:
/*     cd74:	00001025 */ 	or	$v0,$zero,$zero
/*     cd78:	00001825 */ 	or	$v1,$zero,$zero
.L0000cd7c:
/*     cd7c:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*     cd80:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*     cd84:	0302c021 */ 	addu	$t8,$t8,$v0
/*     cd88:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*     cd8c:	0302c023 */ 	subu	$t8,$t8,$v0
/*     cd90:	01f8c821 */ 	addu	$t9,$t7,$t8
/*     cd94:	03232821 */ 	addu	$a1,$t9,$v1
/*     cd98:	90a90047 */ 	lbu	$t1,0x47($a1)
/*     cd9c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     cda0:	1467fff6 */ 	bne	$v1,$a3,.L0000cd7c
/*     cda4:	a0a90000 */ 	sb	$t1,0x0($a1)
/*     cda8:	24420001 */ 	addiu	$v0,$v0,0x1
/*     cdac:	5448fff3 */ 	bnel	$v0,$t0,.L0000cd7c
/*     cdb0:	00001825 */ 	or	$v1,$zero,$zero
/*     cdb4:	0004102a */ 	slt	$v0,$zero,$a0
/*     cdb8:	1440ffee */ 	bnez	$v0,.L0000cd74
/*     cdbc:	2484ffff */ 	addiu	$a0,$a0,-1
.L0000cdc0:
/*     cdc0:	03e00008 */ 	jr	$ra
/*     cdc4:	00000000 */ 	nop
);

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

void func0000cef8(void)
{
	var8005d994 = NULL;

	if (var8005d994) {
		// Unreachable
		s32 i;
		s32 j;

		for (i = 0; i < 30; i++) {
			for (j = 0; j < 71; j++) {
				var8005d994->unk00[i][j] = 0;
			}
		}
	}
}

GLOBAL_ASM(
glabel func0000cf54
/*     cf54:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*     cf58:	3c01a000 */ 	lui	$at,0xa000
/*     cf5c:	00817025 */ 	or	$t6,$a0,$at
/*     cf60:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     cf64:	3c018006 */ 	lui	$at,%hi(var8005d998)
/*     cf68:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     cf6c:	afb70034 */ 	sw	$s7,0x34($sp)
/*     cf70:	afb60030 */ 	sw	$s6,0x30($sp)
/*     cf74:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     cf78:	afb40028 */ 	sw	$s4,0x28($sp)
/*     cf7c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     cf80:	afb20020 */ 	sw	$s2,0x20($sp)
/*     cf84:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     cf88:	afb00018 */ 	sw	$s0,0x18($sp)
/*     cf8c:	0c002f02 */ 	jal	viGetWidth
/*     cf90:	ac2ed998 */ 	sw	$t6,%lo(var8005d998)($at)
/*     cf94:	2450fff3 */ 	addiu	$s0,$v0,-13
/*     cf98:	06010003 */ 	bgez	$s0,.L0000cfa8
/*     cf9c:	00107883 */ 	sra	$t7,$s0,0x2
/*     cfa0:	26010003 */ 	addiu	$at,$s0,0x3
/*     cfa4:	00017883 */ 	sra	$t7,$at,0x2
.L0000cfa8:
/*     cfa8:	0c002f06 */ 	jal	viGetHeight
/*     cfac:	01e08025 */ 	or	$s0,$t7,$zero
/*     cfb0:	2443fff6 */ 	addiu	$v1,$v0,-10
/*     cfb4:	24010007 */ 	addiu	$at,$zero,0x7
/*     cfb8:	0061001a */ 	div	$zero,$v1,$at
/*     cfbc:	3c168006 */ 	lui	$s6,%hi(var8005d994)
/*     cfc0:	26d6d994 */ 	addiu	$s6,$s6,%lo(var8005d994)
/*     cfc4:	8ed90000 */ 	lw	$t9,0x0($s6)
/*     cfc8:	0000c012 */ 	mflo	$t8
/*     cfcc:	2703ffff */ 	addiu	$v1,$t8,-1
/*     cfd0:	13200024 */ 	beqz	$t9,.L0000d064
/*     cfd4:	0060f025 */ 	or	$s8,$v1,$zero
/*     cfd8:	18600022 */ 	blez	$v1,.L0000d064
/*     cfdc:	00009825 */ 	or	$s3,$zero,$zero
/*     cfe0:	2615fffb */ 	addiu	$s5,$s0,-5
/*     cfe4:	2417001d */ 	addiu	$s7,$zero,0x1d
/*     cfe8:	24140047 */ 	addiu	$s4,$zero,0x47
.L0000cfec:
/*     cfec:	1aa00017 */ 	blez	$s5,.L0000d04c
/*     cff0:	00008025 */ 	or	$s0,$zero,$zero
/*     cff4:	001390c0 */ 	sll	$s2,$s3,0x3
/*     cff8:	02539023 */ 	subu	$s2,$s2,$s3
/*     cffc:	00008880 */ 	sll	$s1,$zero,0x2
/*     d000:	26310014 */ 	addiu	$s1,$s1,0x14
/*     d004:	26520007 */ 	addiu	$s2,$s2,0x7
/*     d008:	001348c0 */ 	sll	$t1,$s3,0x3
.L0000d00c:
/*     d00c:	8ec80000 */ 	lw	$t0,0x0($s6)
/*     d010:	01334821 */ 	addu	$t1,$t1,$s3
/*     d014:	000948c0 */ 	sll	$t1,$t1,0x3
/*     d018:	01334823 */ 	subu	$t1,$t1,$s3
/*     d01c:	01095021 */ 	addu	$t2,$t0,$t1
/*     d020:	01505821 */ 	addu	$t3,$t2,$s0
/*     d024:	91660000 */ 	lbu	$a2,0x0($t3)
/*     d028:	02202025 */ 	or	$a0,$s1,$zero
/*     d02c:	0c003372 */ 	jal	func0000cdc8
/*     d030:	02402825 */ 	or	$a1,$s2,$zero
/*     d034:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d038:	0215082a */ 	slt	$at,$s0,$s5
/*     d03c:	10200003 */ 	beqz	$at,.L0000d04c
/*     d040:	26310004 */ 	addiu	$s1,$s1,0x4
/*     d044:	5614fff1 */ 	bnel	$s0,$s4,.L0000d00c
/*     d048:	001348c0 */ 	sll	$t1,$s3,0x3
.L0000d04c:
/*     d04c:	26730001 */ 	addiu	$s3,$s3,0x1
/*     d050:	027e082a */ 	slt	$at,$s3,$s8
/*     d054:	50200004 */ 	beqzl	$at,.L0000d068
/*     d058:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     d05c:	1677ffe3 */ 	bne	$s3,$s7,.L0000cfec
/*     d060:	00000000 */ 	nop
.L0000d064:
/*     d064:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0000d068:
/*     d068:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     d06c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     d070:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     d074:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     d078:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     d07c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     d080:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     d084:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     d088:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     d08c:	03e00008 */ 	jr	$ra
/*     d090:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*     d094:	00000000 */ 	nop
/*     d098:	00000000 */ 	nop
/*     d09c:	00000000 */ 	nop
);
