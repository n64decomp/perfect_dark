#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel bcopy
	beqz  $a2, .L0004b1dc
	move  $a3, $a1
	beq   $a0, $a1, .L0004b1dc
	slt   $at, $a1, $a0
	bnezl $at, .L0004b1a4
	slti  $at, $a2, 0x10
	add   $v0, $a0, $a2
	slt   $at, $a1, $v0
	beqzl $at, .L0004b1a4
	slti  $at, $a2, 0x10
	b     .L0004b308
	slti  $at, $a2, 0x10
	slti  $at, $a2, 0x10
.L0004b1a4:
	bnez  $at, .L0004b1bc
 	nop
	andi  $v0, $a0, 0x3
	andi  $v1, $a1, 0x3
	beq   $v0, $v1, .L0004b1e4
 	nop
.L0004b1bc:
	beqz  $a2, .L0004b1dc
 	nop
	addu  $v1, $a0, $a2
.L0004b1c8:
	lb    $v0, 0x0($a0)
	addiu $a0, $a0, 0x1
	addiu $a1, $a1, 0x1
	bne   $a0, $v1, .L0004b1c8
	sb    $v0, -0x1($a1)
.L0004b1dc:
	jr    $ra
	move  $v0, $a3
.L0004b1e4:
	beqz  $v0, .L0004b248
	addiu $at, $zero, 0x1
	beq   $v0, $at, .L0004b22c
	addiu $at, $zero, 0x2
	beql  $v0, $at, .L0004b218
	lh    $v0, 0x0($a0)
	lb    $v0, 0x0($a0)
	addiu $a0, $a0, 0x1
	addiu $a1, $a1, 0x1
	addiu $a2, $a2, -1
	b     .L0004b248
	sb    $v0, -0x1($a1)
	lh    $v0, 0x0($a0)
.L0004b218:
	addiu $a0, $a0, 0x2
	addiu $a1, $a1, 0x2
	addiu $a2, $a2, -2
	b     .L0004b248
	sh    $v0, -0x2($a1)
.L0004b22c:
	lb    $v0, 0x0($a0)
	lh    $v1, 0x1($a0)
	addiu $a0, $a0, 0x3
	addiu $a1, $a1, 0x3
	addiu $a2, $a2, -3
	sb    $v0, -0x3($a1)
	sh    $v1, -0x2($a1)
.L0004b248:
	slti  $at, $a2, 0x20
	bnezl $at, .L0004b2a8
	slti  $at, $a2, 0x10
	lw    $v0, 0x0($a0)
	lw    $v1, 0x4($a0)
	lw    $t0, 0x8($a0)
	lw    $t1, 0xc($a0)
	lw    $t2, 0x10($a0)
	lw    $t3, 0x14($a0)
	lw    $t4, 0x18($a0)
	lw    $t5, 0x1c($a0)
	addiu $a0, $a0, 0x20
	addiu $a1, $a1, 0x20
	addiu $a2, $a2, -32
	sw    $v0, -0x20($a1)
	sw    $v1, -0x1c($a1)
	sw    $t0, -0x18($a1)
	sw    $t1, -0x14($a1)
	sw    $t2, -0x10($a1)
	sw    $t3, -0xc($a1)
	sw    $t4, -0x8($a1)
	b     .L0004b248
	sw    $t5, -0x4($a1)
.L0004b2a4:
	slti  $at, $a2, 0x10
.L0004b2a8:
	bnezl $at, .L0004b2e4
	slti  $at, $a2, 0x4
	lw    $v0, 0x0($a0)
	lw    $v1, 0x4($a0)
	lw    $t0, 0x8($a0)
	lw    $t1, 0xc($a0)
	addiu $a0, $a0, 0x10
	addiu $a1, $a1, 0x10
	addiu $a2, $a2, -16
	sw    $v0, -0x10($a1)
	sw    $v1, -0xc($a1)
	sw    $t0, -0x8($a1)
	b     .L0004b2a4
	sw    $t1, -0x4($a1)
.L0004b2e0:
	slti  $at, $a2, 0x4
.L0004b2e4:
	bnez  $at, .L0004b1bc
 	nop
	lw    $v0, 0x0($a0)
	addiu $a0, $a0, 0x4
	addiu $a1, $a1, 0x4
	addiu $a2, $a2, -4
	b     .L0004b2e0
	sw    $v0, -0x4($a1)
	slti  $at, $a2, 0x10
.L0004b308:
	add   $a0, $a0, $a2
	bnez  $at, .L0004b324
	add   $a1, $a1, $a2
	andi  $v0, $a0, 0x3
	andi  $v1, $a1, 0x3
	beq   $v0, $v1, .L0004b354
 	nop
.L0004b324:
	beqz  $a2, .L0004b1dc
 	nop
	addiu $a0, $a0, -1
	addiu $a1, $a1, -1
	subu  $v1, $a0, $a2
.L0004b338:
	lb    $v0, 0x0($a0)
	addiu $a0, $a0, -1
	addiu $a1, $a1, -1
	bne   $a0, $v1, .L0004b338
	sb    $v0, 0x1($a1)
	jr    $ra
	move  $v0, $a3
.L0004b354:
	beqz  $v0, .L0004b3b8
	addiu $at, $zero, 0x3
	beq   $v0, $at, .L0004b39c
	addiu $at, $zero, 0x2
	beql  $v0, $at, .L0004b388
	lh    $v0, -0x2($a0)
	lb    $v0, -0x1($a0)
	addiu $a0, $a0, -1
	addiu $a1, $a1, -1
	addiu $a2, $a2, -1
	b     .L0004b3b8
	sb    $v0, 0x0($a1)
	lh    $v0, -0x2($a0)
.L0004b388:
	addiu $a0, $a0, -2
	addiu $a1, $a1, -2
	addiu $a2, $a2, -2
	b     .L0004b3b8
	sh    $v0, 0x0($a1)
.L0004b39c:
	lb    $v0, -0x1($a0)
	lh    $v1, -0x3($a0)
	addiu $a0, $a0, -3
	addiu $a1, $a1, -3
	addiu $a2, $a2, -3
	sb    $v0, 0x2($a1)
	sh    $v1, 0x0($a1)
.L0004b3b8:
	slti  $at, $a2, 0x20
	bnezl $at, .L0004b418
	slti  $at, $a2, 0x10
	lw    $v0, -0x4($a0)
	lw    $v1, -0x8($a0)
	lw    $t0, -0xc($a0)
	lw    $t1, -0x10($a0)
	lw    $t2, -0x14($a0)
	lw    $t3, -0x18($a0)
	lw    $t4, -0x1c($a0)
	lw    $t5, -0x20($a0)
	addiu $a0, $a0, -32
	addiu $a1, $a1, -32
	addiu $a2, $a2, -32
	sw    $v0, 0x1c($a1)
	sw    $v1, 0x18($a1)
	sw    $t0, 0x14($a1)
	sw    $t1, 0x10($a1)
	sw    $t2, 0xc($a1)
	sw    $t3, 0x8($a1)
	sw    $t4, 0x4($a1)
	b     .L0004b3b8
	sw    $t5, 0x0($a1)
.L0004b414:
	slti  $at, $a2, 0x10
.L0004b418:
	bnezl $at, .L0004b454
	slti  $at, $a2, 0x4
	lw    $v0, -0x4($a0)
	lw    $v1, -0x8($a0)
	lw    $t0, -0xc($a0)
	lw    $t1, -0x10($a0)
	addiu $a0, $a0, -16
	addiu $a1, $a1, -16
	addiu $a2, $a2, -16
	sw    $v0, 0xc($a1)
	sw    $v1, 0x8($a1)
	sw    $t0, 0x4($a1)
	b     .L0004b414
	sw    $t1, 0x0($a1)
.L0004b450:
	slti  $at, $a2, 0x4
.L0004b454:
	bnez  $at, .L0004b324
 	nop
	lw    $v0, -0x4($a0)
	addiu $a0, $a0, -4
	addiu $a1, $a1, -4
	addiu $a2, $a2, -4
	b     .L0004b450
	sw    $v0, 0x0($a1)
