#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "types.h"

const char var70052700[] = "BD";
const char var70052704[] = "IP8";
const char var70052708[] = "IP7";
const char var7005270c[] = "IP6";
const char var70052710[] = "IP5";
const char var70052714[] = "IP4";
const char var70052718[] = "IP3";
const char var7005271c[] = "IP2";
const char var70052720[] = "IP1";
const char var70052724[] = "Int";
const char var70052728[] = "TLBmod";
const char var70052730[] = "TLBload";
const char var70052738[] = "TLBstore";
const char var70052744[] = "Address error on load or instruction fetch";
const char var70052770[] = "Address error on store";
const char var70052788[] = "Bus error exception on instruction fetch";
const char var700527b4[] = "Bus error exception on data reference";
const char var700527dc[] = "Syscall";
const char var700527e4[] = "Brk";
const char var700527e8[] = "Reserved instruction";
const char var70052800[] = "Cop unusable";
const char var70052810[] = "Overflow";
const char var7005281c[] = "Trap";
const char var70052824[] = "Virtual coherency exception on intruction fetch";
const char var70052854[] = "Fp exception";
const char var70052864[] = "Watchpoint";
const char var70052870[] = "Virtual coherency exception on data reference";
const char var700528a0[] = "";
const char var700528a4[] = "CU3";
const char var700528a8[] = "CU2";
const char var700528ac[] = "CU1";
const char var700528b0[] = "CU0";
const char var700528b4[] = "RP";
const char var700528b8[] = "FR";
const char var700528bc[] = "RE";
const char var700528c0[] = "BEV";
const char var700528c4[] = "TS";
const char var700528c8[] = "SR";
const char var700528cc[] = "CH";
const char var700528d0[] = "CE";
const char var700528d4[] = "DE";
const char var700528d8[] = "IM8";
const char var700528dc[] = "IM7";
const char var700528e0[] = "IM6";
const char var700528e4[] = "IM5";
const char var700528e8[] = "IM4";
const char var700528ec[] = "IM3";
const char var700528f0[] = "IM2";
const char var700528f4[] = "IM1";
const char var700528f8[] = "KX";
const char var700528fc[] = "SX";
const char var70052900[] = "UX";
const char var70052904[] = "USR";
const char var70052908[] = "SUP";
const char var7005290c[] = "KER";
const char var70052910[] = "ERL";
const char var70052914[] = "EXL";
const char var70052918[] = "IE";
const char var7005291c[] = "";
const char var70052920[] = "FS";
const char var70052924[] = "C";
const char var70052928[] = "Unimplemented";
const char var70052938[] = "Invalid op";
const char var70052944[] = "/ by 0.0";
const char var70052950[] = "Overflow";
const char var7005295c[] = "Underflow";
const char var70052968[] = "Inexact op";
const char var70052974[] = "EV";
const char var70052978[] = "EZ";
const char var7005297c[] = "EO";
const char var70052980[] = "EU";
const char var70052984[] = "EI";
const char var70052988[] = "FV";
const char var7005298c[] = "FZ";
const char var70052990[] = "FO";
const char var70052994[] = "FU";
const char var70052998[] = "FI";
const char var7005299c[] = "RN";
const char var700529a0[] = "RZ";
const char var700529a4[] = "RP";
const char var700529a8[] = "RM";
const char var700529ac[] = "";

const char var700529b0[] = "Bad tid\n";
const char var700529bc[] = "Bad tid\n";
const char var700529c8[] = "%s%s%02d: % .7e ";
const char var700529dc[] = "";
const char var700529e0[] = "";
const char var700529e4[] = "%02d: I%d.%03d.%07d ";
const char var700529fc[] = " ";
const char var70052a00[] = "\n";
const char var70052a04[] = " ";
const char var70052a08[] = " ";
const char var70052a0c[] = "\n";
const char var70052a10[] = "\n\nFAULT-\n";
const char var70052a1c[] = "DodgyStackTrace: %08llx ";
const char var70052a38[] = "%08x ";
const char var70052a40[] = ".\n";
const char var70052a44[] = "%H#@! Another Perfect Crash (tm)\n";
const char var70052a68[] = "at 0x%016llx v0 0x%016llx v1 0x%016llx\n";
const char var70052a90[] = "a0 0x%016llx a1 0x%016llx a2 0x%016llx\n";
const char var70052ab8[] = "a3 0x%016llx t0 0x%016llx t1 0x%016llx\n";
const char var70052ae0[] = "t2 0x%016llx t3 0x%016llx t4 0x%016llx\n";
const char var70052b08[] = "t5 0x%016llx t6 0x%016llx t7 0x%016llx\n";
const char var70052b30[] = "s0 0x%016llx s1 0x%016llx s2 0x%016llx\n";
const char var70052b58[] = "s3 0x%016llx s4 0x%016llx s5 0x%016llx\n";
const char var70052b80[] = "s6 0x%016llx s7 0x%016llx t8 0x%016llx\n";
const char var70052ba8[] = "t9 0x%016llx gp 0x%016llx sp 0x%016llx\n";
const char var70052bd0[] = "s8 0x%016llx ra 0x%016llx\n";
const char var70052bec[] = "TID %d epc %08x caus %08x fp %08x badv %08x sr %08x\n";
const char var70052c24[] = "dshex -a %08x %08x %08x %08x %08x\n";
const char var70052c48[] = "cause";
const char var70052c50[] = " : ";
const char var70052c54[] = "fpcsr";
const char var70052c5c[] = "\n";
const char var70052c60[] = "nearl: ";
const char var70052c68[] = " %08x ";
const char var70052c70[] = "\n       ";
const char var70052c7c[] = "\n";
const char var70052c80[] = "\n";
const char var70052c84[] = "%s <";
const char var70052c8c[] = ",";
const char var70052c90[] = "%s";
const char var70052c94[] = ">";
const char var70052c98[] = "";
const char var70052c9c[] = "";

u32 var8005d5b0 = 0x00000000;
u32 var8005d5b4 = 0x00000000;
u32 var8005d5b8 = 0x00000000;
u32 var8005d5bc = 0x80000000;
u32 var8005d5c0 = 0x80000000;
u32 var8005d5c4 = (u32) &var70052700;
u32 var8005d5c8 = 0x00008000;
u32 var8005d5cc = 0x00008000;
u32 var8005d5d0 = (u32) &var70052704;
u32 var8005d5d4 = 0x00004000;
u32 var8005d5d8 = 0x00004000;
u32 var8005d5dc = (u32) &var70052708;
u32 var8005d5e0 = 0x00002000;
u32 var8005d5e4 = 0x00002000;
u32 var8005d5e8 = (u32) &var7005270c;
u32 var8005d5ec = 0x00001000;
u32 var8005d5f0 = 0x00001000;
u32 var8005d5f4 = (u32) &var70052710;
u32 var8005d5f8 = 0x00000800;
u32 var8005d5fc = 0x00000800;
u32 var8005d600 = (u32) &var70052714;
u32 var8005d604 = 0x00000400;
u32 var8005d608 = 0x00000400;
u32 var8005d60c = (u32) &var70052718;
u32 var8005d610 = 0x00000200;
u32 var8005d614 = 0x00000200;
u32 var8005d618 = (u32) &var7005271c;
u32 var8005d61c = 0x00000100;
u32 var8005d620 = 0x00000100;
u32 var8005d624 = (u32) &var70052720;
u32 var8005d628 = 0x0000007c;
u32 var8005d62c = 0x00000000;
u32 var8005d630 = (u32) &var70052724;
u32 var8005d634 = 0x0000007c;
u32 var8005d638 = 0x00000004;
u32 var8005d63c = (u32) &var70052728;
u32 var8005d640 = 0x0000007c;
u32 var8005d644 = 0x00000008;
u32 var8005d648 = (u32) &var70052730;
u32 var8005d64c = 0x0000007c;
u32 var8005d650 = 0x0000000c;
u32 var8005d654 = (u32) &var70052738;
u32 var8005d658 = 0x0000007c;
u32 var8005d65c = 0x00000010;
u32 var8005d660 = (u32) &var70052744;
u32 var8005d664 = 0x0000007c;
u32 var8005d668 = 0x00000014;
u32 var8005d66c = (u32) &var70052770;
u32 var8005d670 = 0x0000007c;
u32 var8005d674 = 0x00000018;
u32 var8005d678 = (u32) &var70052788;
u32 var8005d67c = 0x0000007c;
u32 var8005d680 = 0x0000001c;
u32 var8005d684 = (u32) &var700527b4;
u32 var8005d688 = 0x0000007c;
u32 var8005d68c = 0x00000020;
u32 var8005d690 = (u32) &var700527dc;
u32 var8005d694 = 0x0000007c;
u32 var8005d698 = 0x00000024;
u32 var8005d69c = (u32) &var700527e4;
u32 var8005d6a0 = 0x0000007c;
u32 var8005d6a4 = 0x00000028;
u32 var8005d6a8 = (u32) &var700527e8;
u32 var8005d6ac = 0x0000007c;
u32 var8005d6b0 = 0x0000002c;
u32 var8005d6b4 = (u32) &var70052800;
u32 var8005d6b8 = 0x0000007c;
u32 var8005d6bc = 0x00000030;
u32 var8005d6c0 = (u32) &var70052810;
u32 var8005d6c4 = 0x0000007c;
u32 var8005d6c8 = 0x00000034;
u32 var8005d6cc = (u32) &var7005281c;
u32 var8005d6d0 = 0x0000007c;
u32 var8005d6d4 = 0x00000038;
u32 var8005d6d8 = (u32) &var70052824;
u32 var8005d6dc = 0x0000007c;
u32 var8005d6e0 = 0x0000003c;
u32 var8005d6e4 = (u32) &var70052854;
u32 var8005d6e8 = 0x0000007c;
u32 var8005d6ec = 0x0000005c;
u32 var8005d6f0 = (u32) &var70052864;
u32 var8005d6f4 = 0x0000007c;
u32 var8005d6f8 = 0x0000007c;
u32 var8005d6fc = (u32) &var70052870;
u32 var8005d700 = 0x00000000;
u32 var8005d704 = 0x00000000;
u32 var8005d708 = (u32) &var700528a0;
u32 var8005d70c = 0x80000000;
u32 var8005d710 = 0x80000000;
u32 var8005d714 = (u32) &var700528a4;
u32 var8005d718 = 0x40000000;
u32 var8005d71c = 0x40000000;
u32 var8005d720 = (u32) &var700528a8;
u32 var8005d724 = 0x20000000;
u32 var8005d728 = 0x20000000;
u32 var8005d72c = (u32) &var700528ac;
u32 var8005d730 = 0x10000000;
u32 var8005d734 = 0x10000000;
u32 var8005d738 = (u32) &var700528b0;
u32 var8005d73c = 0x08000000;
u32 var8005d740 = 0x08000000;
u32 var8005d744 = (u32) &var700528b4;
u32 var8005d748 = 0x04000000;
u32 var8005d74c = 0x04000000;
u32 var8005d750 = (u32) &var700528b8;
u32 var8005d754 = 0x02000000;
u32 var8005d758 = 0x02000000;
u32 var8005d75c = (u32) &var700528bc;
u32 var8005d760 = 0x00400000;
u32 var8005d764 = 0x00400000;
u32 var8005d768 = (u32) &var700528c0;
u32 var8005d76c = 0x00200000;
u32 var8005d770 = 0x00200000;
u32 var8005d774 = (u32) &var700528c4;
u32 var8005d778 = 0x00100000;
u32 var8005d77c = 0x00100000;
u32 var8005d780 = (u32) &var700528c8;
u32 var8005d784 = 0x00040000;
u32 var8005d788 = 0x00040000;
u32 var8005d78c = (u32) &var700528cc;
u32 var8005d790 = 0x00020000;
u32 var8005d794 = 0x00020000;
u32 var8005d798 = (u32) &var700528d0;
u32 var8005d79c = 0x00010000;
u32 var8005d7a0 = 0x00010000;
u32 var8005d7a4 = (u32) &var700528d4;
u32 var8005d7a8 = 0x00008000;
u32 var8005d7ac = 0x00008000;
u32 var8005d7b0 = (u32) &var700528d8;
u32 var8005d7b4 = 0x00004000;
u32 var8005d7b8 = 0x00004000;
u32 var8005d7bc = (u32) &var700528dc;
u32 var8005d7c0 = 0x00002000;
u32 var8005d7c4 = 0x00002000;
u32 var8005d7c8 = (u32) &var700528e0;
u32 var8005d7cc = 0x00001000;
u32 var8005d7d0 = 0x00001000;
u32 var8005d7d4 = (u32) &var700528e4;
u32 var8005d7d8 = 0x00000800;
u32 var8005d7dc = 0x00000800;
u32 var8005d7e0 = (u32) &var700528e8;
u32 var8005d7e4 = 0x00000400;
u32 var8005d7e8 = 0x00000400;
u32 var8005d7ec = (u32) &var700528ec;
u32 var8005d7f0 = 0x00000200;
u32 var8005d7f4 = 0x00000200;
u32 var8005d7f8 = (u32) &var700528f0;
u32 var8005d7fc = 0x00000100;
u32 var8005d800 = 0x00000100;
u32 var8005d804 = (u32) &var700528f4;
u32 var8005d808 = 0x00000080;
u32 var8005d80c = 0x00000080;
u32 var8005d810 = (u32) &var700528f8;
u32 var8005d814 = 0x00000040;
u32 var8005d818 = 0x00000040;
u32 var8005d81c = (u32) &var700528fc;
u32 var8005d820 = 0x00000020;
u32 var8005d824 = 0x00000020;
u32 var8005d828 = (u32) &var70052900;
u32 var8005d82c = 0x00000018;
u32 var8005d830 = 0x00000010;
u32 var8005d834 = (u32) &var70052904;
u32 var8005d838 = 0x00000018;
u32 var8005d83c = 0x00000008;
u32 var8005d840 = (u32) &var70052908;
u32 var8005d844 = 0x00000018;
u32 var8005d848 = 0x00000000;
u32 var8005d84c = (u32) &var7005290c;
u32 var8005d850 = 0x00000004;
u32 var8005d854 = 0x00000004;
u32 var8005d858 = (u32) &var70052910;
u32 var8005d85c = 0x00000002;
u32 var8005d860 = 0x00000002;
u32 var8005d864 = (u32) &var70052914;
u32 var8005d868 = 0x00000001;
u32 var8005d86c = 0x00000001;
u32 var8005d870 = (u32) &var70052918;
u32 var8005d874 = 0x00000000;
u32 var8005d878 = 0x00000000;
u32 var8005d87c = (u32) &var7005291c;
u32 var8005d880 = 0x01000000;
u32 var8005d884 = 0x01000000;
u32 var8005d888 = (u32) &var70052920;
u32 var8005d88c = 0x00800000;
u32 var8005d890 = 0x00800000;
u32 var8005d894 = (u32) &var70052924;
u32 var8005d898 = 0x00020000;
u32 var8005d89c = 0x00020000;
u32 var8005d8a0 = (u32) &var70052928;
u32 var8005d8a4 = 0x00010000;
u32 var8005d8a8 = 0x00010000;
u32 var8005d8ac = (u32) &var70052938;
u32 var8005d8b0 = 0x00008000;
u32 var8005d8b4 = 0x00008000;
u32 var8005d8b8 = (u32) &var70052944;
u32 var8005d8bc = 0x00004000;
u32 var8005d8c0 = 0x00004000;
u32 var8005d8c4 = (u32) &var70052950;
u32 var8005d8c8 = 0x00002000;
u32 var8005d8cc = 0x00002000;
u32 var8005d8d0 = (u32) &var7005295c;
u32 var8005d8d4 = 0x00001000;
u32 var8005d8d8 = 0x00001000;
u32 var8005d8dc = (u32) &var70052968;
u32 var8005d8e0 = 0x00000800;
u32 var8005d8e4 = 0x00000800;
u32 var8005d8e8 = (u32) &var70052974;
u32 var8005d8ec = 0x00000400;
u32 var8005d8f0 = 0x00000400;
u32 var8005d8f4 = (u32) &var70052978;
u32 var8005d8f8 = 0x00000200;
u32 var8005d8fc = 0x00000200;
u32 var8005d900 = (u32) &var7005297c;
u32 var8005d904 = 0x00000100;
u32 var8005d908 = 0x00000100;
u32 var8005d90c = (u32) &var70052980;
u32 var8005d910 = 0x00000080;
u32 var8005d914 = 0x00000080;
u32 var8005d918 = (u32) &var70052984;
u32 var8005d91c = 0x00000040;
u32 var8005d920 = 0x00000040;
u32 var8005d924 = (u32) &var70052988;
u32 var8005d928 = 0x00000020;
u32 var8005d92c = 0x00000020;
u32 var8005d930 = (u32) &var7005298c;
u32 var8005d934 = 0x00000010;
u32 var8005d938 = 0x00000010;
u32 var8005d93c = (u32) &var70052990;
u32 var8005d940 = 0x00000008;
u32 var8005d944 = 0x00000008;
u32 var8005d948 = (u32) &var70052994;
u32 var8005d94c = 0x00000004;
u32 var8005d950 = 0x00000004;
u32 var8005d954 = (u32) &var70052998;
u32 var8005d958 = 0x00000003;
u32 var8005d95c = 0x00000000;
u32 var8005d960 = (u32) &var7005299c;
u32 var8005d964 = 0x00000003;
u32 var8005d968 = 0x00000001;
u32 var8005d96c = (u32) &var700529a0;
u32 var8005d970 = 0x00000003;
u32 var8005d974 = 0x00000002;
u32 var8005d978 = (u32) &var700529a4;
u32 var8005d97c = 0x00000003;
u32 var8005d980 = 0x00000003;
u32 var8005d984 = (u32) &var700529a8;
u32 var8005d988 = 0x00000000;
u32 var8005d98c = 0x00000000;
u32 var8005d990 = (u32) &var700529ac;
u32 var8005d994 = 0x00000000;
u32 var8005d998 = 0x00000000;
u32 var8005d99c = 0x00000000;

void faultproc(void *arg0);

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
/*     c0c4:	0c013990 */ 	jal	func0004e640
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
//			result = func0004e640();
//		} while (!result);
//
//		osSetIntMask(mask);
//
//		// Beta versions have something like this here:
//		//rmonDrawCrashScreen(result, stack1, stack2);
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

GLOBAL_ASM(
glabel func0000c240
/*     c240:	308e0003 */ 	andi	$t6,$a0,0x3
/*     c244:	15c00019 */ 	bnez	$t6,.L0000c2ac
/*     c248:	3c0f7000 */ 	lui	$t7,%hi(func00001050)
/*     c24c:	25ef1050 */ 	addiu	$t7,$t7,%lo(func00001050)
/*     c250:	008f082b */ 	sltu	$at,$a0,$t7
/*     c254:	14200015 */ 	bnez	$at,.L0000c2ac
/*     c258:	3c187006 */ 	lui	$t8,0x7006
/*     c25c:	27189fe0 */ 	addiu	$t8,$t8,-0x6020
/*     c260:	0304082b */ 	sltu	$at,$t8,$a0
/*     c264:	54200012 */ 	bnezl	$at,.L0000c2b0
/*     c268:	00001025 */ 	or	$v0,$zero,$zero
/*     c26c:	8c82fff8 */ 	lw	$v0,-0x8($a0)
/*     c270:	3c01fc00 */ 	lui	$at,0xfc00
/*     c274:	3421003c */ 	ori	$at,$at,0x3c
/*     c278:	0041c824 */ 	and	$t9,$v0,$at
/*     c27c:	24010009 */ 	addiu	$at,$zero,0x9
/*     c280:	57210004 */ 	bnel	$t9,$at,.L0000c294
/*     c284:	3c01fc00 */ 	lui	$at,0xfc00
/*     c288:	03e00008 */ 	jr	$ra
/*     c28c:	24020001 */ 	addiu	$v0,$zero,0x1
/*     c290:	3c01fc00 */ 	lui	$at,0xfc00
.L0000c294:
/*     c294:	00414024 */ 	and	$t0,$v0,$at
/*     c298:	3c010c00 */ 	lui	$at,0xc00
/*     c29c:	55010004 */ 	bnel	$t0,$at,.L0000c2b0
/*     c2a0:	00001025 */ 	or	$v0,$zero,$zero
/*     c2a4:	03e00008 */ 	jr	$ra
/*     c2a8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000c2ac:
/*     c2ac:	00001025 */ 	or	$v0,$zero,$zero
.L0000c2b0:
/*     c2b0:	03e00008 */ 	jr	$ra
/*     c2b4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000c2b8
/*     c2b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c2bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c2c0:	18a00004 */ 	blez	$a1,.L0000c2d4
/*     c2c4:	00803025 */ 	or	$a2,$a0,$zero
/*     c2c8:	2ca10007 */ 	sltiu	$at,$a1,0x7
/*     c2cc:	14200006 */ 	bnez	$at,.L0000c2e8
/*     c2d0:	00051080 */ 	sll	$v0,$a1,0x2
.L0000c2d4:
/*     c2d4:	3c047005 */ 	lui	$a0,%hi(var700529b0)
/*     c2d8:	0c00bea9 */ 	jal	func0002faa4
/*     c2dc:	248429b0 */ 	addiu	$a0,$a0,%lo(var700529b0)
/*     c2e0:	10000010 */ 	b	.L0000c324
/*     c2e4:	00001025 */ 	or	$v0,$zero,$zero
.L0000c2e8:
/*     c2e8:	3c048006 */ 	lui	$a0,%hi(g_StackStartAddrs)
/*     c2ec:	3c038006 */ 	lui	$v1,%hi(g_StackEndAddrs)
/*     c2f0:	3c018000 */ 	lui	$at,0x8000
/*     c2f4:	00822021 */ 	addu	$a0,$a0,$v0
/*     c2f8:	00621821 */ 	addu	$v1,$v1,$v0
/*     c2fc:	00c1082b */ 	sltu	$at,$a2,$at
/*     c300:	8c84ce10 */ 	lw	$a0,%lo(g_StackStartAddrs)($a0)
/*     c304:	14200003 */ 	bnez	$at,.L0000c314
/*     c308:	8c63ce2c */ 	lw	$v1,%lo(g_StackEndAddrs)($v1)
/*     c30c:	10000005 */ 	b	.L0000c324
/*     c310:	00601025 */ 	or	$v0,$v1,$zero
.L0000c314:
/*     c314:	3c01f000 */ 	lui	$at,0xf000
/*     c318:	00c17024 */ 	and	$t6,$a2,$at
/*     c31c:	00647823 */ 	subu	$t7,$v1,$a0
/*     c320:	01cf1025 */ 	or	$v0,$t6,$t7
.L0000c324:
/*     c324:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c328:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c32c:	03e00008 */ 	jr	$ra
/*     c330:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000c334
/*     c334:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c338:	18a00004 */ 	blez	$a1,.L0000c34c
/*     c33c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c340:	2ca10007 */ 	sltiu	$at,$a1,0x7
/*     c344:	14200006 */ 	bnez	$at,.L0000c360
/*     c348:	00057080 */ 	sll	$t6,$a1,0x2
.L0000c34c:
/*     c34c:	3c047005 */ 	lui	$a0,%hi(var700529bc)
/*     c350:	0c00bea9 */ 	jal	func0002faa4
/*     c354:	248429bc */ 	addiu	$a0,$a0,%lo(var700529bc)
/*     c358:	1000000b */ 	b	.L0000c388
/*     c35c:	00001025 */ 	or	$v0,$zero,$zero
.L0000c360:
/*     c360:	3c038006 */ 	lui	$v1,%hi(g_StackStartAddrs)
/*     c364:	3c018000 */ 	lui	$at,0x8000
/*     c368:	006e1821 */ 	addu	$v1,$v1,$t6
/*     c36c:	0081082b */ 	sltu	$at,$a0,$at
/*     c370:	14200003 */ 	bnez	$at,.L0000c380
/*     c374:	8c63ce10 */ 	lw	$v1,%lo(g_StackStartAddrs)($v1)
/*     c378:	10000003 */ 	b	.L0000c388
/*     c37c:	00601025 */ 	or	$v0,$v1,$zero
.L0000c380:
/*     c380:	3c01f000 */ 	lui	$at,0xf000
/*     c384:	00811024 */ 	and	$v0,$a0,$at
.L0000c388:
/*     c388:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c38c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c390:	03e00008 */ 	jr	$ra
/*     c394:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000c398
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

GLOBAL_ASM(
glabel func0000c3dc
/*     c3dc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     c3e0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     c3e4:	afa50024 */ 	sw	$a1,0x24($sp)
/*     c3e8:	afa40020 */ 	sw	$a0,0x20($sp)
/*     c3ec:	0c0030e6 */ 	jal	func0000c398
/*     c3f0:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*     c3f4:	1040000e */ 	beqz	$v0,.L0000c430
/*     c3f8:	3c047005 */ 	lui	$a0,%hi(var700529e4)
/*     c3fc:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*     c400:	3c047005 */ 	lui	$a0,%hi(var700529c8)
/*     c404:	3c057005 */ 	lui	$a1,%hi(var700529dc)
/*     c408:	460021a1 */ 	cvt.d.s	$f6,$f4
/*     c40c:	3c067005 */ 	lui	$a2,%hi(var700529e0)
/*     c410:	24c629e0 */ 	addiu	$a2,$a2,%lo(var700529e0)
/*     c414:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*     c418:	24a529dc */ 	addiu	$a1,$a1,%lo(var700529dc)
/*     c41c:	248429c8 */ 	addiu	$a0,$a0,%lo(var700529c8)
/*     c420:	0c00bea9 */ 	jal	func0002faa4
/*     c424:	8fa70020 */ 	lw	$a3,0x20($sp)
/*     c428:	10000012 */ 	b	.L0000c474
/*     c42c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000c430:
/*     c430:	8fa20024 */ 	lw	$v0,0x24($sp)
/*     c434:	3c018000 */ 	lui	$at,0x8000
/*     c438:	248429e4 */ 	addiu	$a0,$a0,%lo(var700529e4)
/*     c43c:	00413024 */ 	and	$a2,$v0,$at
/*     c440:	3c017f80 */ 	lui	$at,0x7f80
/*     c444:	00413824 */ 	and	$a3,$v0,$at
/*     c448:	3c01007f */ 	lui	$at,0x7f
/*     c44c:	3421ffff */ 	ori	$at,$at,0xffff
/*     c450:	00077dc2 */ 	srl	$t7,$a3,0x17
/*     c454:	000677c2 */ 	srl	$t6,$a2,0x1f
/*     c458:	0041c024 */ 	and	$t8,$v0,$at
/*     c45c:	afb80010 */ 	sw	$t8,0x10($sp)
/*     c460:	01c03025 */ 	or	$a2,$t6,$zero
/*     c464:	01e03825 */ 	or	$a3,$t7,$zero
/*     c468:	0c00bea9 */ 	jal	func0002faa4
/*     c46c:	8fa50020 */ 	lw	$a1,0x20($sp)
/*     c470:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000c474:
/*     c474:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*     c478:	03e00008 */ 	jr	$ra
/*     c47c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000c480
/*     c480:	44856000 */ 	mtc1	$a1,$f12
/*     c484:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c488:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c48c:	44056000 */ 	mfc1	$a1,$f12
/*     c490:	afa40018 */ 	sw	$a0,0x18($sp)
/*     c494:	0c0030f7 */ 	jal	func0000c3dc
/*     c498:	afa60020 */ 	sw	$a2,0x20($sp)
/*     c49c:	3c047005 */ 	lui	$a0,%hi(var700529fc)
/*     c4a0:	0c00bea9 */ 	jal	func0002faa4
/*     c4a4:	248429fc */ 	addiu	$a0,$a0,%lo(var700529fc)
/*     c4a8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*     c4ac:	8fa50020 */ 	lw	$a1,0x20($sp)
/*     c4b0:	0c0030f7 */ 	jal	func0000c3dc
/*     c4b4:	24840001 */ 	addiu	$a0,$a0,0x1
/*     c4b8:	3c047005 */ 	lui	$a0,%hi(var70052a00)
/*     c4bc:	0c00bea9 */ 	jal	func0002faa4
/*     c4c0:	24842a00 */ 	addiu	$a0,$a0,%lo(var70052a00)
/*     c4c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c4c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c4cc:	03e00008 */ 	jr	$ra
/*     c4d0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000c4d4
/*     c4d4:	44856000 */ 	mtc1	$a1,$f12
/*     c4d8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     c4dc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     c4e0:	44056000 */ 	mfc1	$a1,$f12
/*     c4e4:	afa40018 */ 	sw	$a0,0x18($sp)
/*     c4e8:	afa60020 */ 	sw	$a2,0x20($sp)
/*     c4ec:	0c0030f7 */ 	jal	func0000c3dc
/*     c4f0:	afa70024 */ 	sw	$a3,0x24($sp)
/*     c4f4:	3c047005 */ 	lui	$a0,%hi(var70052a04)
/*     c4f8:	0c00bea9 */ 	jal	func0002faa4
/*     c4fc:	24842a04 */ 	addiu	$a0,$a0,%lo(var70052a04)
/*     c500:	8fa40018 */ 	lw	$a0,0x18($sp)
/*     c504:	8fa50020 */ 	lw	$a1,0x20($sp)
/*     c508:	0c0030f7 */ 	jal	func0000c3dc
/*     c50c:	24840001 */ 	addiu	$a0,$a0,0x1
/*     c510:	3c047005 */ 	lui	$a0,%hi(var70052a08)
/*     c514:	0c00bea9 */ 	jal	func0002faa4
/*     c518:	24842a08 */ 	addiu	$a0,$a0,%lo(var70052a08)
/*     c51c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*     c520:	8fa50024 */ 	lw	$a1,0x24($sp)
/*     c524:	0c0030f7 */ 	jal	func0000c3dc
/*     c528:	24840002 */ 	addiu	$a0,$a0,0x2
/*     c52c:	3c047005 */ 	lui	$a0,%hi(var70052a0c)
/*     c530:	0c00bea9 */ 	jal	func0002faa4
/*     c534:	24842a0c */ 	addiu	$a0,$a0,%lo(var70052a0c)
/*     c538:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     c53c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     c540:	03e00008 */ 	jr	$ra
/*     c544:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel rmonDrawCrashScreen
/*     c548:	27bdff10 */ 	addiu	$sp,$sp,-240
/*     c54c:	afa400f0 */ 	sw	$a0,0xf0($sp)
/*     c550:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     c554:	afb50038 */ 	sw	$s5,0x38($sp)
/*     c558:	3c047005 */ 	lui	$a0,%hi(var70052a10)
/*     c55c:	00c0a825 */ 	or	$s5,$a2,$zero
/*     c560:	afb40034 */ 	sw	$s4,0x34($sp)
/*     c564:	afb30030 */ 	sw	$s3,0x30($sp)
/*     c568:	afb2002c */ 	sw	$s2,0x2c($sp)
/*     c56c:	afb10028 */ 	sw	$s1,0x28($sp)
/*     c570:	afb00024 */ 	sw	$s0,0x24($sp)
/*     c574:	afa500f4 */ 	sw	$a1,0xf4($sp)
/*     c578:	0c00bea9 */ 	jal	func0002faa4
/*     c57c:	24842a10 */ 	addiu	$a0,$a0,%lo(var70052a10)
/*     c580:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*     c584:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*     c588:	928e04e0 */ 	lbu	$t6,0x4e0($s4)
/*     c58c:	55c00023 */ 	bnezl	$t6,.L0000c61c
/*     c590:	8fb200f0 */ 	lw	$s2,0xf0($sp)
/*     c594:	8fa200f0 */ 	lw	$v0,0xf0($sp)
/*     c598:	24520020 */ 	addiu	$s2,$v0,0x20
/*     c59c:	8e4400d4 */ 	lw	$a0,0xd4($s2)
/*     c5a0:	0c0030ae */ 	jal	func0000c2b8
/*     c5a4:	8c450014 */ 	lw	$a1,0x14($v0)
/*     c5a8:	8e4700e4 */ 	lw	$a3,0xe4($s2)
/*     c5ac:	2401ffff */ 	addiu	$at,$zero,-1
/*     c5b0:	3c047005 */ 	lui	$a0,%hi(var70052a1c)
/*     c5b4:	00e14824 */ 	and	$t1,$a3,$at
/*     c5b8:	00409825 */ 	or	$s3,$v0,$zero
/*     c5bc:	01203825 */ 	or	$a3,$t1,$zero
/*     c5c0:	24842a1c */ 	addiu	$a0,$a0,%lo(var70052a1c)
/*     c5c4:	0c00bea9 */ 	jal	func0002faa4
/*     c5c8:	00003025 */ 	or	$a2,$zero,$zero
/*     c5cc:	8e5000d4 */ 	lw	$s0,0xd4($s2)
/*     c5d0:	3c117005 */ 	lui	$s1,%hi(var70052a38)
/*     c5d4:	26312a38 */ 	addiu	$s1,$s1,%lo(var70052a38)
/*     c5d8:	0213082b */ 	sltu	$at,$s0,$s3
/*     c5dc:	1020000b */ 	beqz	$at,.L0000c60c
/*     c5e0:	00000000 */ 	nop
.L0000c5e4:
/*     c5e4:	0c003090 */ 	jal	func0000c240
/*     c5e8:	8e040000 */ 	lw	$a0,0x0($s0)
/*     c5ec:	10400003 */ 	beqz	$v0,.L0000c5fc
/*     c5f0:	02202025 */ 	or	$a0,$s1,$zero
/*     c5f4:	0c00bea9 */ 	jal	func0002faa4
/*     c5f8:	8e050000 */ 	lw	$a1,0x0($s0)
.L0000c5fc:
/*     c5fc:	26100004 */ 	addiu	$s0,$s0,0x4
/*     c600:	0213082b */ 	sltu	$at,$s0,$s3
/*     c604:	1420fff7 */ 	bnez	$at,.L0000c5e4
/*     c608:	00000000 */ 	nop
.L0000c60c:
/*     c60c:	3c047005 */ 	lui	$a0,%hi(var70052a40)
/*     c610:	0c00bea9 */ 	jal	func0002faa4
/*     c614:	24842a40 */ 	addiu	$a0,$a0,%lo(var70052a40)
/*     c618:	8fb200f0 */ 	lw	$s2,0xf0($sp)
.L0000c61c:
/*     c61c:	3c047005 */ 	lui	$a0,%hi(var70052a44)
/*     c620:	24842a44 */ 	addiu	$a0,$a0,%lo(var70052a44)
/*     c624:	0c00bea9 */ 	jal	func0002faa4
/*     c628:	26520020 */ 	addiu	$s2,$s2,0x20
/*     c62c:	928f04e0 */ 	lbu	$t7,0x4e0($s4)
/*     c630:	15e00036 */ 	bnez	$t7,.L0000c70c
/*     c634:	00002025 */ 	or	$a0,$zero,$zero
/*     c638:	8e450114 */ 	lw	$a1,0x114($s2)
/*     c63c:	0c003120 */ 	jal	func0000c480
/*     c640:	8e46011c */ 	lw	$a2,0x11c($s2)
/*     c644:	24040002 */ 	addiu	$a0,$zero,0x2
/*     c648:	8e450124 */ 	lw	$a1,0x124($s2)
/*     c64c:	8e46012c */ 	lw	$a2,0x12c($s2)
/*     c650:	0c003135 */ 	jal	func0000c4d4
/*     c654:	8e470134 */ 	lw	$a3,0x134($s2)
/*     c658:	24040005 */ 	addiu	$a0,$zero,0x5
/*     c65c:	8e45013c */ 	lw	$a1,0x13c($s2)
/*     c660:	8e460144 */ 	lw	$a2,0x144($s2)
/*     c664:	0c003135 */ 	jal	func0000c4d4
/*     c668:	8e47014c */ 	lw	$a3,0x14c($s2)
/*     c66c:	24040008 */ 	addiu	$a0,$zero,0x8
/*     c670:	8e450154 */ 	lw	$a1,0x154($s2)
/*     c674:	8e46015c */ 	lw	$a2,0x15c($s2)
/*     c678:	0c003135 */ 	jal	func0000c4d4
/*     c67c:	8e470164 */ 	lw	$a3,0x164($s2)
/*     c680:	2404000b */ 	addiu	$a0,$zero,0xb
/*     c684:	8e45016c */ 	lw	$a1,0x16c($s2)
/*     c688:	8e460174 */ 	lw	$a2,0x174($s2)
/*     c68c:	0c003135 */ 	jal	func0000c4d4
/*     c690:	8e47017c */ 	lw	$a3,0x17c($s2)
/*     c694:	2404000e */ 	addiu	$a0,$zero,0xe
/*     c698:	8e450184 */ 	lw	$a1,0x184($s2)
/*     c69c:	8e46018c */ 	lw	$a2,0x18c($s2)
/*     c6a0:	0c003135 */ 	jal	func0000c4d4
/*     c6a4:	8e470194 */ 	lw	$a3,0x194($s2)
/*     c6a8:	24040011 */ 	addiu	$a0,$zero,0x11
/*     c6ac:	8e45019c */ 	lw	$a1,0x19c($s2)
/*     c6b0:	8e4601a4 */ 	lw	$a2,0x1a4($s2)
/*     c6b4:	0c003135 */ 	jal	func0000c4d4
/*     c6b8:	8e4701ac */ 	lw	$a3,0x1ac($s2)
/*     c6bc:	24040014 */ 	addiu	$a0,$zero,0x14
/*     c6c0:	8e4501b4 */ 	lw	$a1,0x1b4($s2)
/*     c6c4:	8e4601bc */ 	lw	$a2,0x1bc($s2)
/*     c6c8:	0c003135 */ 	jal	func0000c4d4
/*     c6cc:	8e4701c4 */ 	lw	$a3,0x1c4($s2)
/*     c6d0:	24040017 */ 	addiu	$a0,$zero,0x17
/*     c6d4:	8e4501cc */ 	lw	$a1,0x1cc($s2)
/*     c6d8:	8e4601d4 */ 	lw	$a2,0x1d4($s2)
/*     c6dc:	0c003135 */ 	jal	func0000c4d4
/*     c6e0:	8e4701dc */ 	lw	$a3,0x1dc($s2)
/*     c6e4:	2404001a */ 	addiu	$a0,$zero,0x1a
/*     c6e8:	8e4501e4 */ 	lw	$a1,0x1e4($s2)
/*     c6ec:	8e4601ec */ 	lw	$a2,0x1ec($s2)
/*     c6f0:	0c003135 */ 	jal	func0000c4d4
/*     c6f4:	8e4701f4 */ 	lw	$a3,0x1f4($s2)
/*     c6f8:	2404001d */ 	addiu	$a0,$zero,0x1d
/*     c6fc:	8e4501fc */ 	lw	$a1,0x1fc($s2)
/*     c700:	8e460204 */ 	lw	$a2,0x204($s2)
/*     c704:	0c003135 */ 	jal	func0000c4d4
/*     c708:	8e47020c */ 	lw	$a3,0x20c($s2)
.L0000c70c:
/*     c70c:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*     c710:	8e4d000c */ 	lw	$t5,0xc($s2)
/*     c714:	8e460000 */ 	lw	$a2,0x0($s2)
/*     c718:	8e470004 */ 	lw	$a3,0x4($s2)
/*     c71c:	afac0010 */ 	sw	$t4,0x10($sp)
/*     c720:	afad0014 */ 	sw	$t5,0x14($sp)
/*     c724:	8e4f0014 */ 	lw	$t7,0x14($s2)
/*     c728:	8e4e0010 */ 	lw	$t6,0x10($s2)
/*     c72c:	3c047005 */ 	lui	$a0,%hi(var70052a68)
/*     c730:	24842a68 */ 	addiu	$a0,$a0,%lo(var70052a68)
/*     c734:	afaf001c */ 	sw	$t7,0x1c($sp)
/*     c738:	0c00bea9 */ 	jal	func0002faa4
/*     c73c:	afae0018 */ 	sw	$t6,0x18($sp)
/*     c740:	8e580020 */ 	lw	$t8,0x20($s2)
/*     c744:	8e590024 */ 	lw	$t9,0x24($s2)
/*     c748:	8e460018 */ 	lw	$a2,0x18($s2)
/*     c74c:	8e47001c */ 	lw	$a3,0x1c($s2)
/*     c750:	afb80010 */ 	sw	$t8,0x10($sp)
/*     c754:	afb90014 */ 	sw	$t9,0x14($sp)
/*     c758:	8e49002c */ 	lw	$t1,0x2c($s2)
/*     c75c:	8e480028 */ 	lw	$t0,0x28($s2)
/*     c760:	3c047005 */ 	lui	$a0,%hi(var70052a90)
/*     c764:	24842a90 */ 	addiu	$a0,$a0,%lo(var70052a90)
/*     c768:	afa9001c */ 	sw	$t1,0x1c($sp)
/*     c76c:	0c00bea9 */ 	jal	func0002faa4
/*     c770:	afa80018 */ 	sw	$t0,0x18($sp)
/*     c774:	8e4a0038 */ 	lw	$t2,0x38($s2)
/*     c778:	8e4b003c */ 	lw	$t3,0x3c($s2)
/*     c77c:	8e460030 */ 	lw	$a2,0x30($s2)
/*     c780:	8e470034 */ 	lw	$a3,0x34($s2)
/*     c784:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     c788:	afab0014 */ 	sw	$t3,0x14($sp)
/*     c78c:	8e4d0044 */ 	lw	$t5,0x44($s2)
/*     c790:	8e4c0040 */ 	lw	$t4,0x40($s2)
/*     c794:	3c047005 */ 	lui	$a0,%hi(var70052ab8)
/*     c798:	24842ab8 */ 	addiu	$a0,$a0,%lo(var70052ab8)
/*     c79c:	afad001c */ 	sw	$t5,0x1c($sp)
/*     c7a0:	0c00bea9 */ 	jal	func0002faa4
/*     c7a4:	afac0018 */ 	sw	$t4,0x18($sp)
/*     c7a8:	8e4e0050 */ 	lw	$t6,0x50($s2)
/*     c7ac:	8e4f0054 */ 	lw	$t7,0x54($s2)
/*     c7b0:	8e460048 */ 	lw	$a2,0x48($s2)
/*     c7b4:	8e47004c */ 	lw	$a3,0x4c($s2)
/*     c7b8:	afae0010 */ 	sw	$t6,0x10($sp)
/*     c7bc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     c7c0:	8e59005c */ 	lw	$t9,0x5c($s2)
/*     c7c4:	8e580058 */ 	lw	$t8,0x58($s2)
/*     c7c8:	3c047005 */ 	lui	$a0,%hi(var70052ae0)
/*     c7cc:	24842ae0 */ 	addiu	$a0,$a0,%lo(var70052ae0)
/*     c7d0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     c7d4:	0c00bea9 */ 	jal	func0002faa4
/*     c7d8:	afb80018 */ 	sw	$t8,0x18($sp)
/*     c7dc:	8e480068 */ 	lw	$t0,0x68($s2)
/*     c7e0:	8e49006c */ 	lw	$t1,0x6c($s2)
/*     c7e4:	8e460060 */ 	lw	$a2,0x60($s2)
/*     c7e8:	8e470064 */ 	lw	$a3,0x64($s2)
/*     c7ec:	afa80010 */ 	sw	$t0,0x10($sp)
/*     c7f0:	afa90014 */ 	sw	$t1,0x14($sp)
/*     c7f4:	8e4b0074 */ 	lw	$t3,0x74($s2)
/*     c7f8:	8e4a0070 */ 	lw	$t2,0x70($s2)
/*     c7fc:	3c047005 */ 	lui	$a0,%hi(var70052b08)
/*     c800:	24842b08 */ 	addiu	$a0,$a0,%lo(var70052b08)
/*     c804:	afab001c */ 	sw	$t3,0x1c($sp)
/*     c808:	0c00bea9 */ 	jal	func0002faa4
/*     c80c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*     c810:	8e4c0080 */ 	lw	$t4,0x80($s2)
/*     c814:	8e4d0084 */ 	lw	$t5,0x84($s2)
/*     c818:	8e460078 */ 	lw	$a2,0x78($s2)
/*     c81c:	8e47007c */ 	lw	$a3,0x7c($s2)
/*     c820:	afac0010 */ 	sw	$t4,0x10($sp)
/*     c824:	afad0014 */ 	sw	$t5,0x14($sp)
/*     c828:	8e4f008c */ 	lw	$t7,0x8c($s2)
/*     c82c:	8e4e0088 */ 	lw	$t6,0x88($s2)
/*     c830:	3c047005 */ 	lui	$a0,%hi(var70052b30)
/*     c834:	24842b30 */ 	addiu	$a0,$a0,%lo(var70052b30)
/*     c838:	afaf001c */ 	sw	$t7,0x1c($sp)
/*     c83c:	0c00bea9 */ 	jal	func0002faa4
/*     c840:	afae0018 */ 	sw	$t6,0x18($sp)
/*     c844:	8e580098 */ 	lw	$t8,0x98($s2)
/*     c848:	8e59009c */ 	lw	$t9,0x9c($s2)
/*     c84c:	8e460090 */ 	lw	$a2,0x90($s2)
/*     c850:	8e470094 */ 	lw	$a3,0x94($s2)
/*     c854:	afb80010 */ 	sw	$t8,0x10($sp)
/*     c858:	afb90014 */ 	sw	$t9,0x14($sp)
/*     c85c:	8e4900a4 */ 	lw	$t1,0xa4($s2)
/*     c860:	8e4800a0 */ 	lw	$t0,0xa0($s2)
/*     c864:	3c047005 */ 	lui	$a0,%hi(var70052b58)
/*     c868:	24842b58 */ 	addiu	$a0,$a0,%lo(var70052b58)
/*     c86c:	afa9001c */ 	sw	$t1,0x1c($sp)
/*     c870:	0c00bea9 */ 	jal	func0002faa4
/*     c874:	afa80018 */ 	sw	$t0,0x18($sp)
/*     c878:	8e4a00b0 */ 	lw	$t2,0xb0($s2)
/*     c87c:	8e4b00b4 */ 	lw	$t3,0xb4($s2)
/*     c880:	8e4600a8 */ 	lw	$a2,0xa8($s2)
/*     c884:	8e4700ac */ 	lw	$a3,0xac($s2)
/*     c888:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     c88c:	afab0014 */ 	sw	$t3,0x14($sp)
/*     c890:	8e4d00bc */ 	lw	$t5,0xbc($s2)
/*     c894:	8e4c00b8 */ 	lw	$t4,0xb8($s2)
/*     c898:	3c047005 */ 	lui	$a0,%hi(var70052b80)
/*     c89c:	24842b80 */ 	addiu	$a0,$a0,%lo(var70052b80)
/*     c8a0:	afad001c */ 	sw	$t5,0x1c($sp)
/*     c8a4:	0c00bea9 */ 	jal	func0002faa4
/*     c8a8:	afac0018 */ 	sw	$t4,0x18($sp)
/*     c8ac:	8e4e00c8 */ 	lw	$t6,0xc8($s2)
/*     c8b0:	8e4f00cc */ 	lw	$t7,0xcc($s2)
/*     c8b4:	8e4600c0 */ 	lw	$a2,0xc0($s2)
/*     c8b8:	8e4700c4 */ 	lw	$a3,0xc4($s2)
/*     c8bc:	afae0010 */ 	sw	$t6,0x10($sp)
/*     c8c0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     c8c4:	8e5900d4 */ 	lw	$t9,0xd4($s2)
/*     c8c8:	8e5800d0 */ 	lw	$t8,0xd0($s2)
/*     c8cc:	3c047005 */ 	lui	$a0,%hi(var70052ba8)
/*     c8d0:	24842ba8 */ 	addiu	$a0,$a0,%lo(var70052ba8)
/*     c8d4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     c8d8:	0c00bea9 */ 	jal	func0002faa4
/*     c8dc:	afb80018 */ 	sw	$t8,0x18($sp)
/*     c8e0:	8e4800e0 */ 	lw	$t0,0xe0($s2)
/*     c8e4:	8e4900e4 */ 	lw	$t1,0xe4($s2)
/*     c8e8:	3c047005 */ 	lui	$a0,%hi(var70052bd0)
/*     c8ec:	8e4600d8 */ 	lw	$a2,0xd8($s2)
/*     c8f0:	8e4700dc */ 	lw	$a3,0xdc($s2)
/*     c8f4:	24842bd0 */ 	addiu	$a0,$a0,%lo(var70052bd0)
/*     c8f8:	afa80010 */ 	sw	$t0,0x10($sp)
/*     c8fc:	0c00bea9 */ 	jal	func0002faa4
/*     c900:	afa90014 */ 	sw	$t1,0x14($sp)
/*     c904:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*     c908:	8e4b010c */ 	lw	$t3,0x10c($s2)
/*     c90c:	8e4600fc */ 	lw	$a2,0xfc($s2)
/*     c910:	8e470100 */ 	lw	$a3,0x100($s2)
/*     c914:	8d450014 */ 	lw	$a1,0x14($t2)
/*     c918:	afab0010 */ 	sw	$t3,0x10($sp)
/*     c91c:	8e4c0104 */ 	lw	$t4,0x104($s2)
/*     c920:	3c047005 */ 	lui	$a0,%hi(var70052bec)
/*     c924:	24842bec */ 	addiu	$a0,$a0,%lo(var70052bec)
/*     c928:	afac0014 */ 	sw	$t4,0x14($sp)
/*     c92c:	8e4d00f8 */ 	lw	$t5,0xf8($s2)
/*     c930:	0c00bea9 */ 	jal	func0002faa4
/*     c934:	afad0018 */ 	sw	$t5,0x18($sp)
/*     c938:	8e4500fc */ 	lw	$a1,0xfc($s2)
/*     c93c:	3c047005 */ 	lui	$a0,%hi(var70052c24)
/*     c940:	24842c24 */ 	addiu	$a0,$a0,%lo(var70052c24)
/*     c944:	8cae0008 */ 	lw	$t6,0x8($a1)
/*     c948:	8ca60000 */ 	lw	$a2,0x0($a1)
/*     c94c:	8ca70004 */ 	lw	$a3,0x4($a1)
/*     c950:	afae0010 */ 	sw	$t6,0x10($sp)
/*     c954:	8caf000c */ 	lw	$t7,0xc($a1)
/*     c958:	00a01025 */ 	or	$v0,$a1,$zero
/*     c95c:	0c00bea9 */ 	jal	func0002faa4
/*     c960:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     c964:	3c057005 */ 	lui	$a1,%hi(var70052c48)
/*     c968:	3c068006 */ 	lui	$a2,%hi(var8005d5bc)
/*     c96c:	24c6d5bc */ 	addiu	$a2,$a2,%lo(var8005d5bc)
/*     c970:	24a52c48 */ 	addiu	$a1,$a1,%lo(var70052c48)
/*     c974:	0c0032b9 */ 	jal	func0000cae4
/*     c978:	8e440100 */ 	lw	$a0,0x100($s2)
/*     c97c:	3c047005 */ 	lui	$a0,%hi(var70052c50)
/*     c980:	0c00bea9 */ 	jal	func0002faa4
/*     c984:	24842c50 */ 	addiu	$a0,$a0,%lo(var70052c50)
/*     c988:	3c057005 */ 	lui	$a1,%hi(var70052c54)
/*     c98c:	3c068006 */ 	lui	$a2,%hi(var8005d880)
/*     c990:	24c6d880 */ 	addiu	$a2,$a2,%lo(var8005d880)
/*     c994:	24a52c54 */ 	addiu	$a1,$a1,%lo(var70052c54)
/*     c998:	0c0032b9 */ 	jal	func0000cae4
/*     c99c:	8e44010c */ 	lw	$a0,0x10c($s2)
/*     c9a0:	3c047005 */ 	lui	$a0,%hi(var70052c5c)
/*     c9a4:	0c00bea9 */ 	jal	func0002faa4
/*     c9a8:	24842c5c */ 	addiu	$a0,$a0,%lo(var70052c5c)
/*     c9ac:	8e4400d4 */ 	lw	$a0,0xd4($s2)
/*     c9b0:	8fa800f0 */ 	lw	$t0,0xf0($sp)
/*     c9b4:	00009825 */ 	or	$s3,$zero,$zero
/*     c9b8:	00808825 */ 	or	$s1,$a0,$zero
/*     c9bc:	0c0030ae */ 	jal	func0000c2b8
/*     c9c0:	8d050014 */ 	lw	$a1,0x14($t0)
/*     c9c4:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*     c9c8:	0040a025 */ 	or	$s4,$v0,$zero
/*     c9cc:	02202025 */ 	or	$a0,$s1,$zero
/*     c9d0:	0c0030cd */ 	jal	func0000c334
/*     c9d4:	8d250014 */ 	lw	$a1,0x14($t1)
/*     c9d8:	afa2005c */ 	sw	$v0,0x5c($sp)
/*     c9dc:	8e5000fc */ 	lw	$s0,0xfc($s2)
/*     c9e0:	3c047005 */ 	lui	$a0,%hi(var70052c60)
/*     c9e4:	aea00000 */ 	sw	$zero,0x0($s5)
/*     c9e8:	0c00bea9 */ 	jal	func0002faa4
/*     c9ec:	24842c60 */ 	addiu	$a0,$a0,%lo(var70052c60)
.L0000c9f0:
/*     c9f0:	3c057000 */ 	lui	$a1,%hi(func00001050)
/*     c9f4:	24a51050 */ 	addiu	$a1,$a1,%lo(func00001050)
/*     c9f8:	02002025 */ 	or	$a0,$s0,$zero
/*     c9fc:	02203025 */ 	or	$a2,$s1,$zero
/*     ca00:	0c003046 */ 	jal	func0000c118
/*     ca04:	27a70064 */ 	addiu	$a3,$sp,0x64
/*     ca08:	3c047005 */ 	lui	$a0,%hi(var70052c68)
/*     ca0c:	00408825 */ 	or	$s1,$v0,$zero
/*     ca10:	24842c68 */ 	addiu	$a0,$a0,%lo(var70052c68)
/*     ca14:	0c00bea9 */ 	jal	func0002faa4
/*     ca18:	02002825 */ 	or	$a1,$s0,$zero
/*     ca1c:	8eab0000 */ 	lw	$t3,0x0($s5)
/*     ca20:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*     ca24:	24010004 */ 	addiu	$at,$zero,0x4
/*     ca28:	000b6080 */ 	sll	$t4,$t3,0x2
/*     ca2c:	014c6821 */ 	addu	$t5,$t2,$t4
/*     ca30:	adb00000 */ 	sw	$s0,0x0($t5)
/*     ca34:	8eae0000 */ 	lw	$t6,0x0($s5)
/*     ca38:	3c047005 */ 	lui	$a0,%hi(var70052c70)
/*     ca3c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*     ca40:	16610003 */ 	bne	$s3,$at,.L0000ca50
/*     ca44:	aeaf0000 */ 	sw	$t7,0x0($s5)
/*     ca48:	0c00bea9 */ 	jal	func0002faa4
/*     ca4c:	24842c70 */ 	addiu	$a0,$a0,%lo(var70052c70)
.L0000ca50:
/*     ca50:	16200002 */ 	bnez	$s1,.L0000ca5c
/*     ca54:	8fa800e0 */ 	lw	$t0,0xe0($sp)
/*     ca58:	8e5100d4 */ 	lw	$s1,0xd4($s2)
.L0000ca5c:
/*     ca5c:	15000003 */ 	bnez	$t0,.L0000ca6c
/*     ca60:	8fac005c */ 	lw	$t4,0x5c($sp)
/*     ca64:	10000003 */ 	b	.L0000ca74
/*     ca68:	8e5000e4 */ 	lw	$s0,0xe4($s2)
.L0000ca6c:
/*     ca6c:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*     ca70:	8d300000 */ 	lw	$s0,0x0($t1)
.L0000ca74:
/*     ca74:	022c082b */ 	sltu	$at,$s1,$t4
/*     ca78:	1420000a */ 	bnez	$at,.L0000caa4
/*     ca7c:	262d0010 */ 	addiu	$t5,$s1,0x10
/*     ca80:	0234082b */ 	sltu	$at,$s1,$s4
/*     ca84:	10200007 */ 	beqz	$at,.L0000caa4
/*     ca88:	2a620009 */ 	slti	$v0,$s3,0x9
/*     ca8c:	11b40005 */ 	beq	$t5,$s4,.L0000caa4
/*     ca90:	00000000 */ 	nop
/*     ca94:	12000003 */ 	beqz	$s0,.L0000caa4
/*     ca98:	00000000 */ 	nop
/*     ca9c:	1440ffd4 */ 	bnez	$v0,.L0000c9f0
/*     caa0:	26730001 */ 	addiu	$s3,$s3,0x1
.L0000caa4:
/*     caa4:	3c047005 */ 	lui	$a0,%hi(var70052c7c)
/*     caa8:	0c00bea9 */ 	jal	func0002faa4
/*     caac:	24842c7c */ 	addiu	$a0,$a0,%lo(var70052c7c)
/*     cab0:	3c047005 */ 	lui	$a0,%hi(var70052c80)
/*     cab4:	0c00bea9 */ 	jal	func0002faa4
/*     cab8:	24842c80 */ 	addiu	$a0,$a0,%lo(var70052c80)
/*     cabc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     cac0:	8fb00024 */ 	lw	$s0,0x24($sp)
/*     cac4:	8fb10028 */ 	lw	$s1,0x28($sp)
/*     cac8:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*     cacc:	8fb30030 */ 	lw	$s3,0x30($sp)
/*     cad0:	8fb40034 */ 	lw	$s4,0x34($sp)
/*     cad4:	8fb50038 */ 	lw	$s5,0x38($sp)
/*     cad8:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*     cadc:	03e00008 */ 	jr	$ra
/*     cae0:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0000cae4
/*     cae4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     cae8:	afb40028 */ 	sw	$s4,0x28($sp)
/*     caec:	0080a025 */ 	or	$s4,$a0,$zero
/*     caf0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     caf4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     caf8:	afb00018 */ 	sw	$s0,0x18($sp)
/*     cafc:	3c047005 */ 	lui	$a0,%hi(var70052c84)
/*     cb00:	00c08025 */ 	or	$s0,$a2,$zero
/*     cb04:	afb30024 */ 	sw	$s3,0x24($sp)
/*     cb08:	afb20020 */ 	sw	$s2,0x20($sp)
/*     cb0c:	24110001 */ 	addiu	$s1,$zero,0x1
/*     cb10:	0c00bea9 */ 	jal	func0002faa4
/*     cb14:	24842c84 */ 	addiu	$a0,$a0,%lo(var70052c84)
/*     cb18:	8e020000 */ 	lw	$v0,0x0($s0)
/*     cb1c:	3c137005 */ 	lui	$s3,%hi(var70052c8c)
/*     cb20:	26732c8c */ 	addiu	$s3,$s3,%lo(var70052c8c)
/*     cb24:	10400013 */ 	beqz	$v0,.L0000cb74
/*     cb28:	3c127005 */ 	lui	$s2,%hi(var70052c90)
/*     cb2c:	26522c90 */ 	addiu	$s2,$s2,%lo(var70052c90)
/*     cb30:	8e0e0004 */ 	lw	$t6,0x4($s0)
.L0000cb34:
/*     cb34:	00547824 */ 	and	$t7,$v0,$s4
/*     cb38:	55cf000b */ 	bnel	$t6,$t7,.L0000cb68
/*     cb3c:	8e02000c */ 	lw	$v0,0xc($s0)
/*     cb40:	12200003 */ 	beqz	$s1,.L0000cb50
/*     cb44:	00000000 */ 	nop
/*     cb48:	10000003 */ 	b	.L0000cb58
/*     cb4c:	00008825 */ 	or	$s1,$zero,$zero
.L0000cb50:
/*     cb50:	0c00bea9 */ 	jal	func0002faa4
/*     cb54:	02602025 */ 	or	$a0,$s3,$zero
.L0000cb58:
/*     cb58:	02402025 */ 	or	$a0,$s2,$zero
/*     cb5c:	0c00bea9 */ 	jal	func0002faa4
/*     cb60:	8e050008 */ 	lw	$a1,0x8($s0)
/*     cb64:	8e02000c */ 	lw	$v0,0xc($s0)
.L0000cb68:
/*     cb68:	2610000c */ 	addiu	$s0,$s0,0xc
/*     cb6c:	5440fff1 */ 	bnezl	$v0,.L0000cb34
/*     cb70:	8e0e0004 */ 	lw	$t6,0x4($s0)
.L0000cb74:
/*     cb74:	3c047005 */ 	lui	$a0,%hi(var70052c94)
/*     cb78:	0c00bea9 */ 	jal	func0002faa4
/*     cb7c:	24842c94 */ 	addiu	$a0,$a0,%lo(var70052c94)
/*     cb80:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     cb84:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     cb88:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     cb8c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     cb90:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     cb94:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     cb98:	03e00008 */ 	jr	$ra
/*     cb9c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

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
/*     cdd8:	0c002f02 */ 	jal	viGetX
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

GLOBAL_ASM(
glabel func0000cef8
/*     cef8:	3c048006 */ 	lui	$a0,%hi(var8005d994)
/*     cefc:	2484d994 */ 	addiu	$a0,$a0,%lo(var8005d994)
/*     cf00:	10000012 */ 	b	.L0000cf4c
/*     cf04:	ac800000 */ 	sw	$zero,0x0($a0)
/*     cf08:	00001025 */ 	or	$v0,$zero,$zero
/*     cf0c:	2406001e */ 	addiu	$a2,$zero,0x1e
/*     cf10:	24050047 */ 	addiu	$a1,$zero,0x47
/*     cf14:	00001825 */ 	or	$v1,$zero,$zero
.L0000cf18:
/*     cf18:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*     cf1c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*     cf20:	0302c021 */ 	addu	$t8,$t8,$v0
/*     cf24:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*     cf28:	0302c023 */ 	subu	$t8,$t8,$v0
/*     cf2c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*     cf30:	03234021 */ 	addu	$t0,$t9,$v1
/*     cf34:	24630001 */ 	addiu	$v1,$v1,0x1
/*     cf38:	1465fff7 */ 	bne	$v1,$a1,.L0000cf18
/*     cf3c:	a1000000 */ 	sb	$zero,0x0($t0)
/*     cf40:	24420001 */ 	addiu	$v0,$v0,0x1
/*     cf44:	5446fff4 */ 	bnel	$v0,$a2,.L0000cf18
/*     cf48:	00001825 */ 	or	$v1,$zero,$zero
.L0000cf4c:
/*     cf4c:	03e00008 */ 	jr	$ra
/*     cf50:	00000000 */ 	nop
);

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
/*     cf8c:	0c002f02 */ 	jal	viGetX
/*     cf90:	ac2ed998 */ 	sw	$t6,%lo(var8005d998)($at)
/*     cf94:	2450fff3 */ 	addiu	$s0,$v0,-13
/*     cf98:	06010003 */ 	bgez	$s0,.L0000cfa8
/*     cf9c:	00107883 */ 	sra	$t7,$s0,0x2
/*     cfa0:	26010003 */ 	addiu	$at,$s0,0x3
/*     cfa4:	00017883 */ 	sra	$t7,$at,0x2
.L0000cfa8:
/*     cfa8:	0c002f06 */ 	jal	viGetY
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
