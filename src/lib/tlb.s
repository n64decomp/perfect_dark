#include "os_tlb.h"
#include "asm_helper.h"
#include "macros.inc"
#include "versions.h"
.set noat
.set noreorder

.bss
.balign 4

.space 4

glabel g_VmStateTable
.space 4

glabel g_VmZipBuffer
.space 4

glabel g_VmZipTable
.space 8

glabel var8008ae38
.space 0x1000

glabel var8008be38
.space 0x1400

.space 0x20

.space 4

glabel var8008d25c
.space 4

glabel var8008d260
.space 4

glabel var8008d264
.space 4

glabel var8008d268
.space 4

.text

/**
 * Sets up TLB index 0 (0x70000000), then calls bootPhase1.
 */
glabel tlbInit
	lui    $t0, %hi(bootPhase1)
	addiu  $t0, $t0, %lo(bootPhase1)
	jr     $t0
 	nop

glabel tlbHandleMiss
	mfc0   $t0, C0_CONTEXT
	sll    $s5, $t0, 0x9
	lui    $t1, 0x7f00
	sub    $t0, $s5, $t1
	srl    $t0, $t0, 0xc
	sll    $t0, $t0, 0x3
	lui    $t1, %hi(g_VmStateTable)
	lw     $t1, %lo(g_VmStateTable)($t1)
	addu   $s0, $t0, $t1
	lui    $s8, 0x7f00
	slt    $at, $s5, $s8
	bnez   $at, .L0000162c
 	nop
	lui    $t1, %hi(g_VmRamEnd)
	lw     $t1, %lo(g_VmRamEnd)($t1)
	slt    $at, $s5, $t1
	beqz   $at, .L0000162c
 	nop
	mfc0   $t9, C0_BADVADDR
	srl    $t9, $t9, 0xc
	andi   $t9, $t9, 0x1
	beqzl  $t9, .L000011e0
	lw     $s1, 0x0($s0)
	lw     $s1, 0x8($s0)
.L000011e0:
	bnezl  $s1, .L000014c4
	addiu  $t5, $zero, 0x1
	addiu  $t5, $zero, 0x0
	lui    $t1, %hi(var8008d25c)
	lw     $t1, %lo(var8008d25c)($t1)
	lui    $t2, %hi(var8008d260)
	lw     $t2, %lo(var8008d260)($t2)
.L000011fc:
	lbu    $t0, 0x0($t1)
	beqz   $t0, .L0000122c
 	nop
	addiu  $t6, $zero, 0x0
	addiu  $t7, $zero, 0x1
.L00001210:
	and    $t8, $t0, $t7
	bnez   $t8, .L0000123c
 	nop
	addiu  $t6, $t6, 0x1
	addiu  $at, $zero, 0x8
	bne    $t6, $at, .L00001210
	sll    $t7, $t7, 0x1
.L0000122c:
	bne    $t1, $t2, .L000011fc
	addiu  $t1, $t1, 0x1
	j      .L00001570
 	nop
.L0000123c:
	xor    $t0, $t0, $t7
	sb     $t0, 0x0($t1)
	lui    $t2, %hi(var8008d25c)
	lw     $t2, %lo(var8008d25c)($t2)
	lui    $s1, %hi(var8008d268)
	lw     $s1, %lo(var8008d268)($s1)
	subu   $t1, $t1, $t2
	sll    $t1, $t1, 0x3
	addu   $t0, $t6, $t1
	sll    $t0, $t0, 0xc
	addu   $s1, $s1, $t0
.L00001268:
	mfc0   $t2, C0_BADVADDR
	lui    $t0, 0xff
	ori    $t0, $t0, 0xf000
	and    $t2, $t2, $t0
	srl    $t2, $t2, 0xa
	lui    $t0, %hi(g_VmZipTable)
	lw     $t0, %lo(g_VmZipTable)($t0)
	addu   $t0, $t0, $t2
	lw     $t2, 0x0($t0)
	lw     $t0, 0x4($t0)
	subu   $t0, $t0, $t2
	addiu  $t1, $zero, -16
	addiu  $t0, $t0, 0xf
	and    $t6, $t0, $t1
	lui    $t0, 0xa460
	ori    $t0, $t0, 0x10
.L000012a8:
	lw     $t1, 0x0($t0)
	andi   $t1, $t1, 0x3
	bnez   $t1, .L000012a8
 	nop
	lui    $s6, 0xa430
	lw     $s6, 0x8($s6)
	andi   $s6, $s6, 0x10
	lui    $t0, 0xa460
	lui    $t1, %hi(g_VmZipBuffer)
	lw     $t1, %lo(g_VmZipBuffer)($t1)
	lui    $t7, 0xfff
	ori    $t7, $t7, 0xffff
	and    $t1, $t1, $t7
	sw     $t1, 0x0($t0)
	lui    $t0, 0xa460
	ori    $t0, $t0, 0x4
	lui    $t1, 0x8000
	lw     $t1, 0x308($t1)
	or     $t1, $t1, $t2
	lui    $t2, 0x1fff
	ori    $t2, $t2, 0xffff
	and    $t1, $t1, $t2
	sw     $t1, 0x0($t0)
	lui    $t0, 0xa460
	ori    $t0, $t0, 0xc
	addiu  $t6, $t6, -1
	sw     $t6, 0x0($t0)
	beqzl  $t9, .L00001324
 	nop
	beqzl  $zero, .L00001328
	sw     $s1, 0x8($s0)
.L00001324:
	sw     $s1, 0x0($s0)
.L00001328:
	lui    $t0, 0xa460
	ori    $t0, $t0, 0x10
.L00001330:
	lw     $t1, 0x0($t0)
	andi   $t1, $t1, 0x3
	bnez   $t1, .L00001330
 	nop
	lui    $t0, %hi(g_VmZipBuffer)
	lw     $t0, %lo(g_VmZipBuffer)($t0)
	addiu  $t1, $t0, 0x1000
.L0000134c:
	cache  0x15, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .L0000134c
	addiu  $t0, $t0, 16
	bnez   $s6, .L00001370
 	nop
	addiu  $t0, $zero, 0x2
	lui    $at, 0xa460
	sw     $t0, 0x10($at)
.L00001370:
	lui    $a0, %hi(var8008ae38)
	addiu  $a0, $a0, %lo(var8008ae38)
	addiu  $a0, $a0, 0xff8
	sw     $sp, 0x0($a0)
	addiu  $sp, $a0, 0x0
	lui    $a0, %hi(g_VmZipBuffer)
	lw     $a0, %lo(g_VmZipBuffer)($a0)
	addiu  $a0, $a0, 0x2
	lui    $t0, 0x8000
	or     $a1, $s1, $t0
	lui    $a2, %hi(var8008be38)
	addiu  $a2, $a2, %lo(var8008be38)
	addiu  $sp, $sp, -128
	sw     $ra, 0x0($sp)
	sw     $at, 0x4($sp)
	sw     $v0, 0x8($sp)
	sw     $v1, 0xc($sp)
	sw     $a0, 0x10($sp)
	sw     $a1, 0x14($sp)
	sw     $a2, 0x18($sp)
	sw     $a3, 0x1c($sp)
	sw     $t0, 0x20($sp)
	sw     $t1, 0x24($sp)
	sw     $t2, 0x28($sp)
	sw     $t3, 0x2c($sp)
	sw     $t4, 0x30($sp)
	sw     $t5, 0x34($sp)
	sw     $t6, 0x38($sp)
	sw     $t7, 0x3c($sp)
	sw     $s0, 0x40($sp)
	sw     $s1, 0x44($sp)
	sw     $s2, 0x48($sp)
	sw     $s3, 0x4c($sp)
	sw     $s4, 0x50($sp)
	sw     $s5, 0x54($sp)
	sw     $s6, 0x58($sp)
	sw     $s7, 0x5c($sp)
	sw     $t8, 0x60($sp)
	sw     $t9, 0x64($sp)
	sw     $gp, 0x70($sp)
	sw     $sp, 0x74($sp)
	sw     $s8, 0x78($sp)
	jal    rzipInflate
 	nop
	lw     $ra, 0x0($sp)
	lw     $at, 0x4($sp)
	lw     $v0, 0x8($sp)
	lw     $v1, 0xc($sp)
	lw     $a0, 0x10($sp)
	lw     $a1, 0x14($sp)
	lw     $a2, 0x18($sp)
	lw     $a3, 0x1c($sp)
	lw     $t0, 0x20($sp)
	lw     $t1, 0x24($sp)
	lw     $t2, 0x28($sp)
	lw     $t3, 0x2c($sp)
	lw     $t4, 0x30($sp)
	lw     $t5, 0x34($sp)
	lw     $t6, 0x38($sp)
	lw     $t7, 0x3c($sp)
	lw     $s0, 0x40($sp)
	lw     $s1, 0x44($sp)
	lw     $s2, 0x48($sp)
	lw     $s3, 0x4c($sp)
	lw     $s4, 0x50($sp)
	lw     $s5, 0x54($sp)
	lw     $s6, 0x58($sp)
	lw     $s7, 0x5c($sp)
	lw     $t8, 0x60($sp)
	lw     $t9, 0x64($sp)
	lw     $gp, 0x70($sp)
	lw     $sp, 0x74($sp)
	lw     $s8, 0x78($sp)
	addiu  $sp, $sp, 0x80
	lui    $a0, %hi(var8008ae38)
	addiu  $a0, $a0, %lo(var8008ae38)
	addiu  $a0, $a0, 4088
	lw     $sp, 0x0($a0)
	lui    $t0, 0x8000
	or     $t0, $s1, $t0
	addiu  $t1, $t0, 0xff0
.L000014b4:
	cache  0x19, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .L000014b4
	addiu  $t0, $t0, 0x10
.L000014c4:
	addiu  $t0, $zero, OS_PM_4K
	mtc0   $t0, C0_PAGEMASK
	mtc0   $s5, C0_ENTRYHI
 	nop
 	nop
 	nop
 	tlbp
 	nop
 	nop
	mfc0   $t1, C0_INX
	mtc0   $t0, C0_PAGEMASK
	mtc0   $s5, C0_ENTRYHI
	lw     $t0, 0x0($s0)
	srl    $t0, $t0, 0xc
	sll    $t0, $t0, 0x6
	bnezl  $t0, .L00001508
	ori    $t0, $t0, 0x1e
.L00001508:
	mtc0   $t0, C0_ENTRYLO0
	lw     $t0, 0x8($s0)
	srl    $t0, $t0, 0xc
	sll    $t0, $t0, 0x6
	bnezl  $t0, .L00001520
	ori    $t0, $t0, 0x1e
.L00001520:
	mtc0   $t0, C0_ENTRYLO1
	bltzl  $t1, .L00001534
 	nop
	b      .L00001538
 	tlbwi
.L00001534:
 	tlbwr
.L00001538:
	bnez   $t5, .L00001568
 	nop
	or     $t0, $s5, $zero
	bnezl  $t9, .L0000154c
	addiu  $t0, $t0, 0x1000
.L0000154c:
	addiu  $t1, $t0, 0xfe0
	andi   $t2, $t0, 0x1f
	subu   $t0, $t0, $t2
.L00001558:
	cache  0x10, 0x0($t0)
	sltu   $at, $t0, $t1
	bnez   $at, .L00001558
	addiu  $t0, $t0, 0x20
.L00001568:
	jr     $ra
 	nop
.L00001570:
.L00001570_2:
	lui    $s4, %hi(g_VmStateTable)
	lw     $s4, %lo(g_VmStateTable)($s4)
	lui    $gp, %hi(g_VmStateTableEnd)
	lw     $gp, %lo(g_VmStateTableEnd)($gp)
	mfc0   $t0, C0_COUNT
	lui    $t1, %hi(var8008d264+0x2)
	lhu    $t1, %lo(var8008d264+0x2)($t1)
	lui    $t2, %hi(g_VmNumPages)
	lw     $t2, %lo(g_VmNumPages)($t2)
	and    $t0, $t0, $t1
	slt    $at, $t0, $t2
	beqzl  $at, .L000015a4
	subu   $t0, $t0, $t2
.L000015a4:
	sll    $t1, $t0, 0x3
	addu   $t1, $t1, $s4
.L000015ac:
	lw     $s1, 0x0($t1)
	bnez   $s1, .L000015cc
 	nop
	addiu  $t1, $t1, 8
	bne    $t1, $gp, .L000015ac
 	nop
	j      .L000015ac
	or     $t1, $s4, $zero
.L000015cc:
	subu   $t0, $t1, $s4
	srl    $t0, $t0, 0x3
	sll    $t0, $t0, 0xc
	addu   $t0, $t0, $s8
	addiu  $t2, $zero, -4096
	and    $t0, $t0, $t2
	mtc0   $t0, C0_ENTRYHI
	addiu  $t0, $zero, 0x0
	mtc0   $t0, C0_PAGEMASK
 	nop
 	nop
 	nop
 	tlbp
 	nop
 	nop
	mfc0   $t2, C0_INX
	mfc0   $t0, C0_ENTRYHI
	bltz   $t2, .L00001620
 	nop
	j      .L00001570_2
 	nop
.L00001620:
	sw     $zero, 0x0($t1)
	j      .L00001268
 	nop
.L0000162c:
	j      L00003a88
 	nop

glabel tlbUnmapRange
	mfc0   $t0, C0_ENTRYHI
	lui    $t2, 0x8000
	mtc0   $t2, C0_ENTRYHI
	mtc0   $zero, C0_ENTRYLO0
	mtc0   $zero, C0_ENTRYLO1
.L00001648:
	mtc0   $a1, C0_INX
 	nop
 	tlbwi
 	nop
 	nop
	bne    $a1, $a0, .L00001648
	addi   $a1, $a1, -1
	mtc0   $t0, C0_ENTRYHI
	jr     $ra
 	nop
