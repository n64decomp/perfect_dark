#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder
.set gp=64

.data

glabel __osHwIntTable
.word 0x0, 0x0, 0x0, 0x0, 0x0
.word 0x0, 0x0, 0x0, 0x0, 0x0

.rdata
#define REDISPATCH 0x00
#define SW1 0x04
#define SW2 0x08
#define RCP 0x0c
#define CART 0x10
#define PRENMI 0x14
#define IP6_HDLR 0x18
#define IP7_HDLR 0x1c
#define COUNTER 0x20
__osIntOffTable:
.byte REDISPATCH
.byte PRENMI
.byte IP6_HDLR
.byte IP6_HDLR
.byte IP7_HDLR
.byte IP7_HDLR
.byte IP7_HDLR
.byte IP7_HDLR
.byte COUNTER
.byte COUNTER
.byte COUNTER
.byte COUNTER
.byte COUNTER
.byte COUNTER
.byte COUNTER
.byte COUNTER
.byte REDISPATCH
.byte SW1
.byte SW2
.byte SW2
.byte RCP
.byte RCP
.byte RCP
.byte RCP
.byte CART
.byte CART
.byte CART
.byte CART
.byte CART
.byte CART
.byte CART
.byte CART

__osIntTable:
.word .L00003a3c
.word .L000039c8
.word .L000039a8
.word .L0000380c
.word .L000037c8
.word .L0000394c
.word .L00003790
.word .L0000379c
.word .L000037a8

.text

glabel __osExceptionPreamble
	lui   $k0, %hi(__osException)
	addiu $k0, $k0, %lo(__osException)
	jr    $k0
 	nop

glabel __osException
	lui   $k0, %hi(__osThreadSave)
	addiu $k0, $k0, %lo(__osThreadSave)
	sd    $at, 0x20($k0)
	mfc0  $k1, C0_SR
	sw    $k1, 0x118($k0)
	addiu $at, $zero, -4
	and   $k1, $k1, $at
	mtc0  $k1, C0_SR
	sd    $t0, 0x58($k0)
	sd    $t1, 0x60($k0)
	sd    $t2, 0x68($k0)
	sw    $zero, 0x18($k0)
	mfc0  $t0, C0_CAUSE
	move  $t0, $k0
	lui   $k0, %hi(__osRunningThread)
	lw    $k0, %lo(__osRunningThread)($k0)
	ld    $t1, 0x20($t0)
	sd    $t1, 0x20($k0)
	ld    $t1, 0x118($t0)
	sd    $t1, 0x118($k0)
	ld    $t1, 0x58($t0)
	sd    $t1, 0x58($k0)
	ld    $t1, 0x60($t0)
	sd    $t1, 0x60($k0)
	ld    $t1, 0x68($t0)
	sd    $t1, 0x68($k0)
	lw    $k1, 0x118($k0)
	mflo  $t0
	sd    $t0, 0x108($k0)
	mfhi  $t0
	andi  $t1, $k1, 0xff00
	sd    $v0, 0x28($k0)
	sd    $v1, 0x30($k0)
	sd    $a0, 0x38($k0)
	sd    $a1, 0x40($k0)
	sd    $a2, 0x48($k0)
	sd    $a3, 0x50($k0)
	sd    $t3, 0x70($k0)
	sd    $t4, 0x78($k0)
	sd    $t5, 0x80($k0)
	sd    $t6, 0x88($k0)
	sd    $t7, 0x90($k0)
	sd    $s0, 0x98($k0)
	sd    $s1, 0xa0($k0)
	sd    $s2, 0xa8($k0)
	sd    $s3, 0xb0($k0)
	sd    $s4, 0xb8($k0)
	sd    $s5, 0xc0($k0)
	sd    $s6, 0xc8($k0)
	sd    $s7, 0xd0($k0)
	sd    $t8, 0xd8($k0)
	sd    $t9, 0xe0($k0)
	sd    $gp, 0xe8($k0)
	sd    $sp, 0xf0($k0)
	sd    $s8, 0xf8($k0)
	sd    $ra, 0x100($k0)
	beqz  $t1, .L00003628
	sd    $t0, 0x110($k0)
	lui   $t0, %hi(__osGlobalIntMask)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t0, 0x0($t0)
	addiu $at, $zero, -1
	xor   $t2, $t0, $at
	lui   $at, 0xffff
	andi  $t2, $t2, 0xff00
	ori   $at, $at, 0xff
	or    $t4, $t1, $t2
	and   $t3, $k1, $at
	andi  $t0, $t0, 0xff00
	or    $t3, $t3, $t4
	and   $t1, $t1, $t0
	and   $k1, $k1, $at
	sw    $t3, 0x118($k0)
	or    $k1, $k1, $t1
.L00003628:
	lui   $t1, 0xa430
	lw    $t1, 0xc($t1)
	beqzl $t1, .L00003664
	sw    $t1, 0x128($k0)
	lui   $t0, %hi(__osGlobalIntMask)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t0, 0x0($t0)
	lw    $t4, 0x128($k0)
	addiu $at, $zero, -1
	srl   $t0, $t0, 0x10
	xor   $t0, $t0, $at
	andi  $t0, $t0, 0x3f
	and   $t0, $t0, $t4
	or    $t1, $t1, $t0
	sw    $t1, 0x128($k0)
.L00003664:
	mfc0  $t0, C0_EPC
	sw    $t0, 0x11c($k0)
	lw    $t0, 0x18($k0)
	beqz  $t0, .L00003704
 	nop
	cfc1  $t0, $31
 	nop
	sw    $t0, 0x12c($k0)
	sdc1  $f0, 0x130($k0)
	sdc1  $f1, 0x138($k0)
	sdc1  $f2, 0x140($k0)
	sdc1  $f3, 0x148($k0)
	sdc1  $f4, 0x150($k0)
	sdc1  $f5, 0x158($k0)
	sdc1  $f6, 0x160($k0)
	sdc1  $f7, 0x168($k0)
	sdc1  $f8, 0x170($k0)
	sdc1  $f9, 0x178($k0)
	sdc1  $f10, 0x180($k0)
	sdc1  $f11, 0x188($k0)
	sdc1  $f12, 0x190($k0)
	sdc1  $f13, 0x198($k0)
	sdc1  $f14, 0x1a0($k0)
	sdc1  $f15, 0x1a8($k0)
	sdc1  $f16, 0x1b0($k0)
	sdc1  $f17, 0x1b8($k0)
	sdc1  $f18, 0x1c0($k0)
	sdc1  $f19, 0x1c8($k0)
	sdc1  $f20, 0x1d0($k0)
	sdc1  $f21, 0x1d8($k0)
	sdc1  $f22, 0x1e0($k0)
	sdc1  $f23, 0x1e8($k0)
	sdc1  $f24, 0x1f0($k0)
	sdc1  $f25, 0x1f8($k0)
	sdc1  $f26, 0x200($k0)
	sdc1  $f27, 0x208($k0)
	sdc1  $f28, 0x210($k0)
	sdc1  $f29, 0x218($k0)
	sdc1  $f30, 0x220($k0)
	sdc1  $f31, 0x228($k0)
.L00003704:
	mfc0  $t0, C0_CAUSE
	sw    $t0, 0x120($k0)
	addiu $t1, $zero, 0x2
	sh    $t1, 0x10($k0)
	andi  $t1, $t0, 0x7c
	addiu $t2, $zero, 0x8
	beq   $t1, $t2, .L000039e8
 	nop
	addiu $t2, $zero, 0xc
	beq   $t1, $t2, .L000039f8
 	nop
	addiu $t2, $zero, 0x24
	beql  $t1, $t2, .L00003a04
	addiu $t1, $zero, 0x1
	addiu $t2, $zero, 0x2c
	beq   $t1, $t2, .L00003b6c
 	nop
	addiu $t2, $zero, 0x0
	bne   $t1, $t2, L00003a88
 	nop
	and   $s0, $k1, $t0
.L00003758:
	andi  $t1, $s0, 0xff00
.L0000375c:
	srl   $t2, $t1, 0xc
	bnez  $t2, .L00003770
 	nop
	srl   $t2, $t1, 0x8
	addi  $t2, $t2, 0x10
.L00003770:
	lui   $at, %hi(__osIntOffTable)
	addu  $at, $at, $t2
	lbu   $t2, %lo(__osIntOffTable)($at)
	lui   $at, %hi(__osIntTable)
	addu  $at, $at, $t2
	lw    $t2, %lo(__osIntTable)($at)
	jr    $t2
 	nop
.L00003790:
	addiu $at, $zero, -8193
	b     .L00003758
	and   $s0, $s0, $at
.L0000379c:
	addiu $at, $zero, -16385
	b     .L00003758
	and   $s0, $s0, $at
.L000037a8:
	mfc0  $t1, C0_COMPARE
	mtc0  $t1, C0_COMPARE
	jal   send_mesg
	addiu $a0, $zero, 0x18
	lui   $at, 0xffff
	ori   $at, $at, 0x7fff
	b     .L00003758
	and   $s0, $s0, $at
.L000037c8:
	lui   $t1, %hi(__osHwIntTable)
	addiu $t1, $t1, %lo(__osHwIntTable)
	lw    $t2, 0x8($t1)
	addiu $at, $zero, -2049
	and   $s0, $s0, $at
	beqz  $t2, .L000037fc
	addi  $t1, $t1, 0x8
	jalr  $t2
	lw    $sp, 0x4($t1)
	beqz  $v0, .L000037fc
 	nop
	b     .L00003a3c
 	nop
.L000037fc:
	jal   send_mesg
	addiu $a0, $zero, 0x10
	b     .L0000375c
	andi  $t1, $s0, 0xff00
.L0000380c:
	lui   $t0, %hi(__osGlobalIntMask)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t0, 0x0($t0)
	lui   $s1, 0xa430
	lw    $s1, 0x8($s1)
	srl   $t0, $t0, 0x10
	and   $s1, $s1, $t0
	andi  $t1, $s1, 0x1
	beqzl $t1, .L00003880
	andi  $t1, $s1, 0x8
	lui   $t4, 0xa404
	lw    $t4, 0x10($t4)
	dli   $t1, 0x8008
	lui   $at, 0xa404
	andi  $t4, $t4, 0x300
	andi  $s1, $s1, 0x3e
	beqz  $t4, .L0000386c
	sw    $t1, 0x10($at)
	jal   send_mesg
	addiu $a0, $zero, 0x20
	beqzl $s1, .L00003944
	addiu $at, $zero, -1025
	b     .L00003880
	andi  $t1, $s1, 0x8
.L0000386c:
	jal   send_mesg
	addiu $a0, $zero, 0x58
	beqzl $s1, .L00003944
	addiu $at, $zero, -1025
	andi  $t1, $s1, 0x8
.L00003880:
	beqz  $t1, .L000038a0
	lui   $at, 0xa440
	andi  $s1, $s1, 0x37
	sw    $zero, 0x10($at)
	jal   send_mesg
	addiu $a0, $zero, 0x38
	beqzl $s1, .L00003944
	addiu $at, $zero, -1025
.L000038a0:
	andi  $t1, $s1, 0x4
	beqzl $t1, .L000038d0
	andi  $t1, $s1, 0x2
	addiu $t1, $zero, 0x1
	lui   $at, 0xa450
	andi  $s1, $s1, 0x3b
	sw    $t1, 0xc($at)
	jal   send_mesg
	addiu $a0, $zero, 0x30
	beqzl $s1, .L00003944
	addiu $at, $zero, -1025
	andi  $t1, $s1, 0x2
.L000038d0:
	beqz  $t1, .L000038f0
	lui   $at, 0xa480
	andi  $s1, $s1, 0x3d
	sw    $zero, 0x18($at)
	jal   send_mesg
	addiu $a0, $zero, 0x28
	beqzl $s1, .L00003944
	addiu $at, $zero, -1025
.L000038f0:
	andi  $t1, $s1, 0x10
	beqzl $t1, .L00003920
	andi  $t1, $s1, 0x20
	addiu $t1, $zero, 0x2
	lui   $at, 0xa460
	andi  $s1, $s1, 0x2f
	sw    $t1, 0x10($at)
	jal   send_mesg
	addiu $a0, $zero, 0x40
	beqzl $s1, .L00003944
	addiu $at, $zero, -1025
	andi  $t1, $s1, 0x20
.L00003920:
	beqzl $t1, .L00003944
	addiu $at, $zero, -1025
	addiu $t1, $zero, 0x800
	lui   $at, 0xa430
	andi  $s1, $s1, 0x1f
	sw    $t1, 0x0($at)
	jal   send_mesg
	addiu $a0, $zero, 0x48
	addiu $at, $zero, -1025
.L00003944:
	b     .L00003758
	and   $s0, $s0, $at
.L0000394c:
	lw    $k1, 0x118($k0)
	addiu $at, $zero, -4097
	lui   $t1, %hi(_osShutdown)
	and   $k1, $k1, $at
	sw    $k1, 0x118($k0)
	addiu $t1, $t1, %lo(_osShutdown)
	lw    $t2, 0x0($t1)
	beqz  $t2, .L00003978
	addiu $at, $zero, -4097
	b     .L00003a3c
	and   $s0, $s0, $at
.L00003978:
	addiu $t2, $zero, 0x1
	sw    $t2, 0x0($t1)
	jal   send_mesg
	addiu $a0, $zero, 0x70
	lui   $t2, %hi(__osRunQueue)
	lw    $t2, %lo(__osRunQueue)($t2)
	addiu $at, $zero, -4097
	and   $s0, $s0, $at
	lw    $k1, 0x118($t2)
	and   $k1, $k1, $at
	b     .L00003a3c
	sw    $k1, 0x118($t2)
.L000039a8:
	addiu $at, $zero, -513
	and   $t0, $t0, $at
	mtc0  $t0, C0_CAUSE
	jal   send_mesg
	addiu $a0, $zero, 0x8
	addiu $at, $zero, -513
	b     .L00003758
	and   $s0, $s0, $at
.L000039c8:
	addiu $at, $zero, -257
	and   $t0, $t0, $at
	mtc0  $t0, C0_CAUSE
	jal   send_mesg
	addiu $a0, $zero, 0x0
	addiu $at, $zero, -257
	b     .L00003758
	and   $s0, $s0, $at
.L000039e8:
	jal   tlbHandleMiss
 	nop
	b     .L00003a3c
 	nop
.L000039f8:
	j     L00003a88
 	nop
	addiu $t1, $zero, 0x1
.L00003a04:
	sh    $t1, 0x12($k0)
	lw    $t1, 0x11c($k0)
	addiu $at, $zero, 0x6
	lw    $t1, 0x0($t1)
	srl   $t1, $t1, 0x10
	andi  $t1, $t1, 0xff
	beq   $t1, $at, L00003a88
	addiu $at, $zero, 0x7
	beq   $t1, $at, L00003a88
 	nop
	jal   send_mesg
	addiu $a0, $zero, 0x50
	b     .L00003a3c
 	nop
.L00003a3c:
	lui   $t2, %hi(__osRunQueue)
	lw    $t2, %lo(__osRunQueue)($t2)
	lw    $t1, 0x4($k0)
	lw    $t3, 0x4($t2)
	slt   $at, $t1, $t3
	beqz  $at, .L00003a70
 	nop
	lui   $a0, %hi(__osRunQueue)
	move  $a1, $k0
	jal   __osEnqueueThread
	addiu $a0, $a0, %lo(__osRunQueue)
	j     .L00003d10
 	nop
.L00003a70:
	lui   $t1, %hi(__osRunQueue)
	addiu $t1, $t1, %lo(__osRunQueue)
	lw    $t2, 0x0($t1)
	sw    $t2, 0x0($k0)
	j     .L00003d10
	sw    $k0, 0x0($t1)

glabel L00003a88
	lui   $at, %hi(__osFaultedThread)
	sw    $k0, %lo(__osFaultedThread)($at)
	addiu $t1, $zero, 0x1
	sh    $t1, 0x10($k0)
	addiu $t1, $zero, 0x2
	sh    $t1, 0x12($k0)
	mfc0  $t2, C0_BADVADDR
	sw    $t2, 0x124($k0)
	jal   send_mesg
	addiu $a0, $zero, 0x60
	j     .L00003d10
 	nop

glabel send_mesg
	lui   $t2, %hi(__osEventStateTab)
	addiu $t2, $t2, %lo(__osEventStateTab)
	addu  $t2, $t2, $a0
	lw    $t1, 0x0($t2)
	move  $s2, $ra
	beqz  $t1, .L00003b64
 	nop
	lw    $t3, 0x8($t1)
	lw    $t4, 0x10($t1)
	slt   $at, $t3, $t4
	beqz  $at, .L00003b64
 	nop
	lw    $t5, 0xc($t1)
	addu  $t5, $t5, $t3
	div   $zero, $t5, $t4
	bnez  $t4, .L00003b00
 	nop
	break 0x7
.L00003b00:
	addiu $at, $zero, -1
	bne   $t4, $at, .L00003b18
	lui   $at, 0x8000
	bne   $t5, $at, .L00003b18
 	nop
	break 0x6
.L00003b18:
	lw    $t4, 0x14($t1)
	mfhi  $t5
	sll   $t5, $t5, 0x2
	addu  $t4, $t4, $t5
	lw    $t5, 0x4($t2)
	addiu $t2, $t3, 0x1
	sw    $t5, 0x0($t4)
	sw    $t2, 0x8($t1)
	lw    $t2, 0x0($t1)
	lw    $t3, 0x0($t2)
	beqz  $t3, .L00003b64
 	nop
	jal   __osPopThread
	move  $a0, $t1
	move  $t2, $v0
	lui   $a0, %hi(__osRunQueue)
	move  $a1, $t2
	jal   __osEnqueueThread
	addiu $a0, $a0, %lo(__osRunQueue)
.L00003b64:
	jr    $s2
 	nop
.L00003b6c:
	lui   $at, 0x3000
	and   $t1, $t0, $at
	srl   $t1, $t1, 0x1c
	addiu $t2, $zero, 0x1
	bne   $t1, $t2, L00003a88
 	nop
	lw    $k1, 0x118($k0)
	lui   $at, 0x2000
	addiu $t1, $zero, 0x1
	or    $k1, $k1, $at
	sw    $t1, 0x18($k0)
	b     .L00003a70
	sw    $k1, 0x118($k0)

glabel __osEnqueueAndYield
	lui   $a1, %hi(__osRunningThread)
	lw    $a1, %lo(__osRunningThread)($a1)
	mfc0  $t0, C0_SR
	lw    $k1, 0x18($a1)
	ori   $t0, $t0, 0x2
	sw    $t0, 0x118($a1)
	sd    $s0, 0x98($a1)
	sd    $s1, 0xa0($a1)
	sd    $s2, 0xa8($a1)
	sd    $s3, 0xb0($a1)
	sd    $s4, 0xb8($a1)
	sd    $s5, 0xc0($a1)
	sd    $s6, 0xc8($a1)
	sd    $s7, 0xd0($a1)
	sd    $gp, 0xe8($a1)
	sd    $sp, 0xf0($a1)
	sd    $s8, 0xf8($a1)
	sd    $ra, 0x100($a1)
	beqz  $k1, .L00003c28
	sw    $ra, 0x11c($a1)
	cfc1  $k1, $31
	sdc1  $f20, 0x1d0($a1)
	sdc1  $f21, 0x1d8($a1)
	sdc1  $f22, 0x1e0($a1)
	sdc1  $f23, 0x1e8($a1)
	sdc1  $f24, 0x1f0($a1)
	sdc1  $f25, 0x1f8($a1)
	sdc1  $f26, 0x200($a1)
	sdc1  $f27, 0x208($a1)
	sdc1  $f28, 0x210($a1)
	sdc1  $f29, 0x218($a1)
	sdc1  $f30, 0x220($a1)
	sdc1  $f31, 0x228($a1)
	sw    $k1, 0x12c($a1)
.L00003c28:
	lw    $k1, 0x118($a1)
	andi  $t1, $k1, 0xff00
	beqzl $t1, .L00003c6c
	lui   $k1, 0xa430
	lui   $t0, %hi(__osGlobalIntMask)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t0, 0x0($t0)
	addiu $at, $zero, -1
	xor   $t0, $t0, $at
	lui   $at, 0xffff
	andi  $t0, $t0, 0xff00
	ori   $at, $at, 0xff
	or    $t1, $t1, $t0
	and   $k1, $k1, $at
	or    $k1, $k1, $t1
	sw    $k1, 0x118($a1)
	lui   $k1, 0xa430
.L00003c6c:
	lw    $k1, 0xc($k1)
	beqz  $k1, .L00003ca0
 	nop
	lui   $k0, %hi(__osGlobalIntMask)
	addiu $k0, $k0, %lo(__osGlobalIntMask)
	lw    $k0, 0x0($k0)
	lw    $t0, 0x128($a1)
	addiu $at, $zero, -1
	srl   $k0, $k0, 0x10
	xor   $k0, $k0, $at
	andi  $k0, $k0, 0x3f
	and   $k0, $k0, $t0
	or    $k1, $k1, $k0
.L00003ca0:
	beqz  $a0, .L00003cb0
	sw    $k1, 0x128($a1)
	jal   __osEnqueueThread
 	nop
.L00003cb0:
	j     .L00003d10
 	nop

glabel __osEnqueueThread
	lw    $t8, 0x0($a0)
	lw    $t7, 0x4($a1)
	move  $t9, $a0
	lw    $t6, 0x4($t8)
	slt   $at, $t6, $t7
	bnezl $at, .L00003cf0
	lw    $t8, 0x0($t9)
	move  $t9, $t8
.L00003cd8:
	lw    $t8, 0x0($t8)
	lw    $t6, 0x4($t8)
	slt   $at, $t6, $t7
	beqzl $at, .L00003cd8
	move  $t9, $t8
	lw    $t8, 0x0($t9)
.L00003cf0:
	sw    $t8, 0x0($a1)
	sw    $a1, 0x0($t9)
	jr    $ra
	sw    $a0, 0x8($a1)

glabel __osPopThread
 	lw	$v0, 0x0($a0)
 	lw	$t9, 0x0($v0)
 	jr	$ra
 	sw	$t9, 0x0($a0)

glabel __osDispatchThread
.L00003d10:
	lui   $a0, %hi(__osRunQueue)
	jal   __osPopThread
	addiu $a0, $a0, %lo(__osRunQueue)
	lui   $at, %hi(__osRunningThread)
	sw    $v0, %lo(__osRunningThread)($at)
	addiu $t0, $zero, 0x4
	sh    $t0, 0x10($v0)
	move  $k0, $v0
	lui   $t0, %hi(__osGlobalIntMask)
	lw    $k1, 0x118($k0)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t0, 0x0($t0)
	lui   $at, 0xffff
	andi  $t1, $k1, 0xff00
	ori   $at, $at, 0xff
	andi  $t0, $t0, 0xff00
	and   $t1, $t1, $t0
	and   $k1, $k1, $at
	or    $k1, $k1, $t1
	mtc0  $k1, C0_SR
	ld    $k1, 0x108($k0)
	ld    $at, 0x20($k0)
	ld    $v0, 0x28($k0)
	mtlo  $k1
	ld    $k1, 0x110($k0)
	ld    $v1, 0x30($k0)
	ld    $a0, 0x38($k0)
	ld    $a1, 0x40($k0)
	ld    $a2, 0x48($k0)
	ld    $a3, 0x50($k0)
	ld    $t0, 0x58($k0)
	ld    $t1, 0x60($k0)
	ld    $t2, 0x68($k0)
	ld    $t3, 0x70($k0)
	ld    $t4, 0x78($k0)
	ld    $t5, 0x80($k0)
	ld    $t6, 0x88($k0)
	ld    $t7, 0x90($k0)
	ld    $s0, 0x98($k0)
	ld    $s1, 0xa0($k0)
	ld    $s2, 0xa8($k0)
	ld    $s3, 0xb0($k0)
	ld    $s4, 0xb8($k0)
	ld    $s5, 0xc0($k0)
	ld    $s6, 0xc8($k0)
	ld    $s7, 0xd0($k0)
	ld    $t8, 0xd8($k0)
	ld    $t9, 0xe0($k0)
	ld    $gp, 0xe8($k0)
	mthi  $k1
	ld    $sp, 0xf0($k0)
	ld    $s8, 0xf8($k0)
	ld    $ra, 0x100($k0)
	lw    $k1, 0x11c($k0)
	mtc0  $k1, C0_EPC
	lw    $k1, 0x18($k0)
	beqz  $k1, .L00003e80
 	nop
	lw    $k1, 0x12c($k0)
	ctc1  $k1, $31
	ldc1  $f0, 0x130($k0)
	ldc1  $f1, 0x138($k0)
	ldc1  $f2, 0x140($k0)
	ldc1  $f3, 0x148($k0)
	ldc1  $f4, 0x150($k0)
	ldc1  $f5, 0x158($k0)
	ldc1  $f6, 0x160($k0)
	ldc1  $f7, 0x168($k0)
	ldc1  $f8, 0x170($k0)
	ldc1  $f9, 0x178($k0)
	ldc1  $f10, 0x180($k0)
	ldc1  $f11, 0x188($k0)
	ldc1  $f12, 0x190($k0)
	ldc1  $f13, 0x198($k0)
	ldc1  $f14, 0x1a0($k0)
	ldc1  $f15, 0x1a8($k0)
	ldc1  $f16, 0x1b0($k0)
	ldc1  $f17, 0x1b8($k0)
	ldc1  $f18, 0x1c0($k0)
	ldc1  $f19, 0x1c8($k0)
	ldc1  $f20, 0x1d0($k0)
	ldc1  $f21, 0x1d8($k0)
	ldc1  $f22, 0x1e0($k0)
	ldc1  $f23, 0x1e8($k0)
	ldc1  $f24, 0x1f0($k0)
	ldc1  $f25, 0x1f8($k0)
	ldc1  $f26, 0x200($k0)
	ldc1  $f27, 0x208($k0)
	ldc1  $f28, 0x210($k0)
	ldc1  $f29, 0x218($k0)
	ldc1  $f30, 0x220($k0)
	ldc1  $f31, 0x228($k0)
.L00003e80:
	lw    $k1, 0x128($k0)
	lui   $k0, %hi(__osGlobalIntMask)
	addiu $k0, $k0, %lo(__osGlobalIntMask)
	lw    $k0, 0x0($k0)
	srl   $k0, $k0, 0x10
	and   $k1, $k1, $k0
	sll   $k1, $k1, 0x1
	lui   $k0, %hi(var70059e30)
	addiu $k0, $k0, %lo(var70059e30)
	addu  $k1, $k1, $k0
	lhu   $k1, 0x0($k1)
	lui   $k0, 0xa430
	addiu $k0, $k0, 0xc
	sw    $k1, 0x0($k0)
 	nop
 	nop
 	nop
 	nop
 	eret

glabel __osCleanupThread
 	jal	 osDestroyThread
 	move $a0, $zero
