#include <ultra64.h>
#include "types.h"
#include "library/library_0c000.h"
#include "library/library_2fa00.h"

const char var700526e0[] = "ASSERTION : %s, %d: (\"%s\")\n";
const char var700526fc[] = "";
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

GLOBAL_ASM(
glabel func0000bfb0
/*     bfb0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     bfb4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     bfb8:	0c003000 */ 	jal	func0000c000
/*     bfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*     bfc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     bfc4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     bfc8:	03e00008 */ 	jr	$ra
/*     bfcc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000bfd0
/*     bfd0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     bfd4:	00803825 */ 	or	$a3,$a0,$zero
/*     bfd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     bfdc:	3c047005 */ 	lui	$a0,%hi(var700526e0)
/*     bfe0:	0c00bea9 */ 	jal	func0002faa4
/*     bfe4:	248426e0 */ 	addiu	$a0,$a0,%lo(var700526e0)
/*     bfe8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     bfec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     bff0:	03e00008 */ 	jr	$ra
/*     bff4:	00000000 */ 	sll	$zero,$zero,0x0
/*     bff8:	00000000 */ 	sll	$zero,$zero,0x0
/*     bffc:	00000000 */ 	sll	$zero,$zero,0x0
);