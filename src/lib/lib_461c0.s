#include "macros.inc"
.set noat
.set noreorder

.text

glabel func000461c0
	andi   $t4, $t0, 0x7
	addiu  $t3, $zero, 0x8
	lbu    $t5, 0x0($a0)
	lbu    $t2, 0x1($a0)
	sll    $t1, $t5, 0x8
	or     $t1, $t1, $t2
	sub    $t3, $t3, $t4
	srlv   $t1, $t1, $t3
	andi   $t1, $t1, 0xff
	sll    $t3, $a2, 0x8
	add    $t3, $t3, $t1
	lui    $t2, %hi(var8005f6fc)
	addiu  $t2, $t2, %lo(var8005f6fc)
	lw     $t2, 0x0($t2)
	add    $t2, $t3, $t2
	lbu    $t2, 0x0($t2)
	beqz   $t2, .L00046238
 	nop
	add    $t0, $t0, $t2
	add    $t4, $t4, $t2
	srl    $t4, $t4, 0x3
	add    $a0, $a0, $t4
	lui    $t2, %hi(var8005f6f8)
	addiu  $t2, $t2, %lo(var8005f6f8)
	lw     $t2, 0x0($t2)
	add    $t2, $t3, $t2
	lbu    $t2, 0x0($t2)
	srl    $t1, $t2, 0x4
	jr     $ra
	andi   $v0, $t2, 0xf
.L00046238:
	add    $t7, $zero, $s0
	andi   $t1, $t0, 0x7
	addiu  $t2, $zero, 0x80
	srlv   $t2, $t2, $t1
	addiu  $t6, $zero, -1
.L0004624c:
	and    $t4, $t5, $t2
	beqzl  $t4, .L0004625c
	lbu    $t4, 0x0($t7)
	lbu    $t4, 0x1($t7)
.L0004625c:
	srl    $t2, $t2, 0x1
	sll    $t4, $t4, 0x2
	bnez   $t2, .L00046278
	add    $t7, $t7, $t4
	addiu  $t2, $zero, 0x80
	addi   $a0, $a0, 0x1
	lbu    $t5, 0x0($a0)
.L00046278:
	lb     $t1, 0x2($t7)
	beq    $t1, $t6, .L0004624c
	addi   $t0, $t0, 0x1
	add    $v0, $zero, $t1
	jr     $ra
	lb     $t1, 0x3($t7)

glabel func00046290
	lwl    $t1, 0x0($a0)
	lwr    $t1, 0x3($a0)
	andi   $t2, $t0, 0x7
	add    $t2, $t2, $s1
	srl    $t2, $t2, 0x3
	add    $a0, $a0, $t2
	andi   $t2, $t0, 0x7
	sllv   $t1, $t1, $t2
	addiu  $t2, $zero, 0x20
	sub    $t2, $t2, $s1
	srlv   $v0, $t1, $t2
	jr     $ra
	add    $t0, $t0, $s1

glabel func000462c4
	lw     $t0, 0x0($a1)
	srl    $t1, $t0, 0x3
	add    $a0, $a0, $t1
	lwl    $t1, 0x0($a0)
	lwr    $t1, 0x3($a0)
	andi   $t2, $t0, 0x7
	sllv   $t1, $t1, $t2
	addiu  $t2, $zero, 0x20
	sub    $t2, $t2, $a2
	srlv   $v0, $t1, $t2
	add    $t0, $t0, $a2
	jr     $ra
	sw     $t0, 0x0($a1)

glabel func000462f8
	addiu  $sp, $sp, -48
	sw     $ra, 0x0($sp)
	sw     $s0, 0x4($sp)
	sw     $s1, 0x8($sp)
	sw     $s2, 0xc($sp)
	sw     $s3, 0x10($sp)
	sw     $s4, 0x14($sp)
	sw     $s5, 0x18($sp)
	sw     $s6, 0x1c($sp)
	sw     $s7, 0x20($sp)
	sw     $s8, 0x24($sp)
	sw     $gp, 0x28($sp)
	sw     $ra, 0x2c($sp)
	lw     $t0, 0x0($a1)
	sll    $s0, $a2, 0x2
	lui    $t1, %hi(var8009c650)
	addiu  $t1, $t1, %lo(var8009c650)
	add    $s0, $s0, $t1
	lw     $s0, 0x0($s0)
	lw     $s1, 0x40($sp)
	lw     $s2, 0x44($sp)
	lw     $s3, 0x48($sp)
	lw     $s4, 0x4c($sp)
	lw     $s3, 0x0($s3)
	lw     $s4, 0x0($s4)
	srl    $t1, $t0, 0x3
	add    $a0, $a0, $t1
	sub    $t1, $s2, $a3
	blez   $t1, .L00046458
 	nop
.L00046370:
	jal    func000461c0
 	nop
	beqz   $s1, .L00046398
	add    $s6, $zero, $t1
	addiu  $t2, $zero, 0xf
	bne    $v0, $t2, .L00046398
 	nop
	jal    func00046290
 	nop
	addi   $v0, $v0, 0xf
.L00046398:
	beqzl  $v0, .L000463d8
	sb     $zero, 0x0($s4)
	lb     $t1, 0x0($a0)
	addiu  $t3, $zero, 0x7
	andi   $t2, $t0, 0x7
	addi   $t4, $t2, 0x1
	srl    $t4, $t4, 0x3
	add    $a0, $a0, $t4
	sub    $t2, $t3, $t2
	srlv   $t1, $t1, $t2
	andi   $t1, $t1, 0x1
	addi   $t0, $t0, 0x1
	addiu  $t2, $zero, 0x1
	beqzl  $t1, .L000463d8
	sb     $zero, 0x0($s4)
	sb     $t2, 0x0($s4)
.L000463d8:
	beqz   $s1, .L000463fc
	add    $s7, $zero, $v0
	addiu  $t2, $zero, 0xf
	bne    $s6, $t2, .L000463fc
 	nop
	jal    func00046290
 	nop
	addi   $s6, $v0, 0xf
	add    $v0, $zero, $s7
.L000463fc:
	sh     $v0, 0x0($s3)
	sh     $s6, 0x2($s3)
	addi   $s3, $s3, 0x4
	beqzl  $s6, .L00046448
	sb     $zero, 0x1($s4)
	lb     $t1, 0x0($a0)
	addiu  $t3, $zero, 0x7
	andi   $t2, $t0, 0x7
	addi   $t4, $t2, 0x1
	srl    $t4, $t4, 0x3
	add    $a0, $a0, $t4
	sub    $t2, $t3, $t2
	srlv   $t1, $t1, $t2
	andi   $t1, $t1, 0x1
	addi   $t0, $t0, 0x1
	addiu  $t2, $zero, 0x1
	beqzl  $t1, .L00046448
	sb     $zero, 0x1($s4)
	sb     $t2, 0x1($s4)
.L00046448:
	addi   $a3, $a3, 0x2
	sub    $t1, $s2, $a3
	bgtz   $t1, .L00046370
	addi   $s4, $s4, 0x2
.L00046458:
	sw     $t0, 0x0($a1)
	lw     $t0, 0x48($sp)
	lw     $t1, 0x4c($sp)
	sw     $s3, 0x0($t0)
	sw     $s4, 0x0($t1)
	lw     $ra, 0x0($sp)
	lw     $s0, 0x4($sp)
	lw     $s1, 0x8($sp)
	lw     $s2, 0xc($sp)
	lw     $s3, 0x10($sp)
	lw     $s4, 0x14($sp)
	lw     $s5, 0x18($sp)
	lw     $s6, 0x1c($sp)
	lw     $s7, 0x20($sp)
	lw     $s8, 0x24($sp)
	lw     $gp, 0x28($sp)
	lw     $ra, 0x2c($sp)
	addiu  $sp, $sp, 0x30
	jr     $ra
	add    $v0, $zero, $a3

glabel func000464a8
	addiu  $sp, $sp, -48
	sw     $ra, 0x0($sp)
	sw     $s0, 0x4($sp)
	sw     $s1, 0x8($sp)
	sw     $s2, 0xc($sp)
	sw     $s3, 0x10($sp)
	sw     $s4, 0x14($sp)
	sw     $s5, 0x18($sp)
	sw     $s6, 0x1c($sp)
	sw     $s7, 0x20($sp)
	sw     $s8, 0x24($sp)
	sw     $gp, 0x28($sp)
	sw     $ra, 0x2c($sp)
	lw     $t0, 0x0($a1)
	sll    $s0, $a2, 0x2
	lui    $t1, %hi(var8009c650)
	addiu  $t1, $t1, %lo(var8009c650)
	add    $s0, $s0, $t1
	lw     $s0, 0x0($s0)
	lw     $s2, 0x40($sp)
	lw     $s3, 0x44($sp)
	lw     $s4, 0x48($sp)
	lw     $s3, 0x0($s3)
	lw     $s4, 0x0($s4)
	srl    $t1, $t0, 0x3
	add    $a0, $a0, $t1
	sub    $t1, $s2, $t0
	blez   $t1, .L000465f4
 	nop
	addi   $t1, $a3, -576
	bgez   $t1, .L000465f4
 	nop
.L00046528:
	jal    func000461c0
 	nop
	srl    $t3, $v0, 0x3
	andi   $t3, $t3, 0x1
	srl    $t4, $v0, 0x2
	andi   $t4, $t4, 0x1
	srl    $t5, $v0, 0x1
	andi   $t5, $t5, 0x1
	andi   $t6, $v0, 0x1
	sh     $t3, 0x0($s3)
	sh     $t4, 0x2($s3)
	sh     $t5, 0x4($s3)
	sh     $t6, 0x6($s3)
	jal    func00046290
	addiu  $s1, $zero, 0x4
	addiu  $s1, $zero, 0x3
	sb     $v0, 0x0($s4)
	beqz   $t3, .L0004657c
	srlv   $t1, $v0, $s1
	and    $t3, $t3, $t1
	addi   $s1, $s1, -1
.L0004657c:
	beqz   $t4, .L00046590
	sb     $t3, 0x0($s4)
	srlv   $t1, $v0, $s1
	and    $t4, $t4, $t1
	addi   $s1, $s1, -1
.L00046590:
	beqz   $t5, .L000465a4
	sb     $t4, 0x1($s4)
	srlv   $t1, $v0, $s1
	and    $t5, $t5, $t1
	addi   $s1, $s1, -1
.L000465a4:
	beqz   $t6, .L000465b8
	sb     $t5, 0x2($s4)
	srlv   $t1, $v0, $s1
	and    $t6, $t6, $t1
	addi   $s1, $s1, -1
.L000465b8:
	sb     $t6, 0x3($s4)
	addi   $s1, $s1, 0x1
	andi   $t1, $t0, 0x7
	sub    $t1, $t1, $s1
	bgez   $t1, .L000465d4
	sub    $t0, $t0, $s1
	addi   $a0, $a0, -1
.L000465d4:
	addi   $s3, $s3, 0x8
	addi   $s4, $s4, 0x4
	addi   $a3, $a3, 0x4
	addi   $t1, $a3, -576
	bgez   $t1, .L000465f4
	sub    $t1, $s2, $t0
	bgtz   $t1, .L00046528
 	nop
.L000465f4:
	sw     $t0, 0x0($a1)
	lw     $t0, 0x44($sp)
	lw     $t1, 0x48($sp)
	sw     $s3, 0x0($t0)
	sw     $s4, 0x0($t1)
	lw     $ra, 0x0($sp)
	lw     $s0, 0x4($sp)
	lw     $s1, 0x8($sp)
	lw     $s2, 0xc($sp)
	lw     $s3, 0x10($sp)
	lw     $s4, 0x14($sp)
	lw     $s5, 0x18($sp)
	lw     $s6, 0x1c($sp)
	lw     $s7, 0x20($sp)
	lw     $s8, 0x24($sp)
	lw     $gp, 0x28($sp)
	lw     $ra, 0x2c($sp)
	addiu  $sp, $sp, 0x30
	jr     $ra
	add    $v0, $zero, $a3
