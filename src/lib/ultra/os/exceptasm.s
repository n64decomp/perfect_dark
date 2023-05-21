#include "asm_helper.h"
#include "macros.inc"
#include "PR/os_exception.h"
#include "PR/os_message.h"
#include "PR/os_thread.h"
.set noat
.set noreorder
.set gp=64

#define SIZEOF_OSEVENTSTATE 0x8

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
.word .handle_intr_redispatch
.word .handle_intr_sw1
.word .handle_intr_sw2
.word .handle_intr_rcp
.word .handle_intr_cart
.word .handle_intr_prenmi
.word .handle_intr_ip6
.word .handle_intr_ip7
.word .handle_intr_counter

.text

glabel __osExceptionPreamble
	la    $k0, __osException
	jr    $k0
 	nop

glabel __osException
	la    $k0, __osThreadSave
	sd    $at, 0x20($k0)
	mfc0  $k1, C0_SR
	sw    $k1, 0x118($k0)
	li    $at, ~(SR_IE | SR_EXL)
	and   $k1, $k1, $at
	mtc0  $k1, C0_SR
	sd    $t0, 0x58($k0)
	sd    $t1, 0x60($k0)
	sd    $t2, 0x68($k0)
	sw    $zero, 0x18($k0)
	mfc0  $t0, C0_CAUSE

	# Set t0 = &__osThreadSave
	# Set k0 = __osRunningThread
	move  $t0, $k0
	lw    $k0, __osRunningThread
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
	andi  $t1, $k1, SR_IMASK
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
	beqz  $t1, .after_interrupt_mask
	sd    $t0, 0x110($k0)

	la    $t0, __osGlobalIntMask
	lw    $t0, 0x0($t0)
	li    $at, 0xffffffff
	xor   $t2, $t0, $at
	lui   $at, 0xffff
	andi  $t2, $t2, SR_IMASK
	ori   $at, $at, 0xff
	or    $t4, $t1, $t2
	and   $t3, $k1, $at
	andi  $t0, $t0, SR_IMASK
	or    $t3, $t3, $t4
	and   $t1, $t1, $t0
	and   $k1, $k1, $at
	sw    $t3, 0x118($k0)
	or    $k1, $k1, $t1

.after_interrupt_mask:
	lw    $t1, PHYS_TO_K1(MI_INTR_MASK_REG)
	beqzl $t1, .after_mi_interrupt_reg
	sw    $t1, 0x128($k0)

	la    $t0, __osGlobalIntMask
	lw    $t0, 0x0($t0)
	lw    $t4, 0x128($k0)
	li    $at, 0xffffffff
	srl   $t0, $t0, 0x10
	xor   $t0, $t0, $at
	andi  $t0, $t0, 0x3f
	and   $t0, $t0, $t4
	or    $t1, $t1, $t0
	sw    $t1, 0x128($k0)

.after_mi_interrupt_reg:
	mfc0  $t0, C0_EPC
	sw    $t0, 0x11c($k0)

	lw    $t0, 0x18($k0)
	beqz  $t0, .after_fp
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

.after_fp:
	mfc0  $t0, C0_CAUSE
	sw    $t0, 0x120($k0)

	li    $t1, OS_STATE_RUNNABLE
	sh    $t1, 0x10($k0)

	andi  $t1, $t0, CAUSE_EXCMASK

	li    $t2, EXC_RMISS
	beq   $t1, $t2, .handle_rmiss
 	nop

	li    $t2, EXC_WMISS
	beq   $t1, $t2, .handle_wmiss
 	nop

	li    $t2, EXC_BREAK
	beql  $t1, $t2, .handle_break
	li    $t1, OS_FLAG_CPU_BREAK

	li    $t2, EXC_CPU
	beq   $t1, $t2, .handle_cpu
 	nop

	li    $t2, EXC_INT
	bne   $t1, $t2, handle_fault
 	nop

.handle_interrupt:
	and   $s0, $k1, $t0

.interrupt_loop_outer:
	andi  $t1, $s0, CAUSE_IPMASK
.interrupt_loop_inner:
	srl   $t2, $t1, 0xc
	bnez  $t2, .after_get_upper
 	nop
	srl   $t2, $t1, 0x8
	addi  $t2, $t2, 0x10
.after_get_upper:
	lui   $at, %hi(__osIntOffTable)
	addu  $at, $at, $t2
	lbu   $t2, %lo(__osIntOffTable)($at)
	lui   $at, %hi(__osIntTable)
	addu  $at, $at, $t2
	lw    $t2, %lo(__osIntTable)($at)
	jr    $t2
 	nop

.handle_intr_ip6:
	li    $at, ~CAUSE_IP6
	b     .interrupt_loop_outer
	and   $s0, $s0, $at

.handle_intr_ip7:
	li    $at, ~CAUSE_IP7
	b     .interrupt_loop_outer
	and   $s0, $s0, $at

.handle_intr_counter:
	mfc0  $t1, C0_COMPARE
	mtc0  $t1, C0_COMPARE
	jal   send_mesg
	li    $a0, OS_EVENT_COUNTER * SIZEOF_OSEVENTSTATE
	li    $at, ~CAUSE_IP8
	b     .interrupt_loop_outer
	and   $s0, $s0, $at

.handle_intr_cart:
	la    $t1, __osHwIntTable
	lw    $t2, 0x8($t1)
	li    $at, ~CAUSE_IP4
	and   $s0, $s0, $at
	beqz  $t2, .no_cart_override
	addi  $t1, $t1, 0x8
	jalr  $t2
	lw    $sp, 0x4($t1)
	beqz  $v0, .no_cart_override
 	nop
	b     .dispatch_thread
 	nop
.no_cart_override:
	jal   send_mesg
	li    $a0, OS_EVENT_CART * SIZEOF_OSEVENTSTATE
	b     .interrupt_loop_inner
	andi  $t1, $s0, CAUSE_IPMASK

.handle_intr_rcp:
	la    $t0, __osGlobalIntMask
	lw    $t0, 0x0($t0)
	lw    $s1, PHYS_TO_K1(MI_INTR_REG)
	srl   $t0, $t0, 0x10
	and   $s1, $s1, $t0
	andi  $t1, $s1, 0x1
	beqzl $t1, .after_sp_break
	andi  $t1, $s1, 0x8
	lw    $t4, PHYS_TO_K1(SP_STATUS_REG)
	li    $t1, SP_CLR_INTR | SP_CLR_SIG3
	lui   $at, %hi(PHYS_TO_K1(SP_STATUS_REG))
	andi  $t4, $t4, SP_STATUS_SIG1 | SP_STATUS_SIG2
	andi  $s1, $s1, 0x3e
	beqz  $t4, .sp_break
	sw    $t1, %lo(PHYS_TO_K1(SP_STATUS_REG))($at)
	jal   send_mesg
	li    $a0, OS_EVENT_SP * SIZEOF_OSEVENTSTATE
	beqzl $s1, .after_clear_all_interrupts
	li    $at, ~CAUSE_IP3
	b     .after_sp_break
	andi  $t1, $s1, 0x8
.sp_break:
	jal   send_mesg
	li    $a0, OS_EVENT_SP_BREAK * SIZEOF_OSEVENTSTATE
	beqzl $s1, .after_clear_all_interrupts
	li    $at, ~CAUSE_IP3
	andi  $t1, $s1, 0x8
.after_sp_break:
	beqz  $t1, .after_clear_vi_current
	lui   $at, %hi(PHYS_TO_K1(VI_CURRENT_REG))
	andi  $s1, $s1, 0x37
	sw    $zero, %lo(PHYS_TO_K1(VI_CURRENT_REG))($at)
	jal   send_mesg
	li    $a0, OS_EVENT_VI * SIZEOF_OSEVENTSTATE
	beqzl $s1, .after_clear_all_interrupts
	li    $at, ~CAUSE_IP3
.after_clear_vi_current:
	andi  $t1, $s1, 0x4
	beqzl $t1, .after_clear_ai_interrupt
	andi  $t1, $s1, 0x2
	li    $t1, 1
	lui   $at, %hi(PHYS_TO_K1(AI_STATUS_REG))
	andi  $s1, $s1, 0x3b
	sw    $t1, %lo(PHYS_TO_K1(AI_STATUS_REG))($at)
	jal   send_mesg
	li    $a0, OS_EVENT_AI * SIZEOF_OSEVENTSTATE
	beqzl $s1, .after_clear_all_interrupts
	li    $at, ~CAUSE_IP3
	andi  $t1, $s1, 0x2
.after_clear_ai_interrupt:
	beqz  $t1, .after_clear_si_interrupt
	lui   $at, %hi(PHYS_TO_K1(SI_STATUS_REG))
	andi  $s1, $s1, 0x3d
	sw    $zero, %lo(PHYS_TO_K1(SI_STATUS_REG))($at)
	jal   send_mesg
	li    $a0, OS_EVENT_SI * SIZEOF_OSEVENTSTATE
	beqzl $s1, .after_clear_all_interrupts
	li    $at, ~CAUSE_IP3
.after_clear_si_interrupt:
	andi  $t1, $s1, 0x10
	beqzl $t1, .after_clear_pi_interrupt
	andi  $t1, $s1, 0x20
	li    $t1, PI_STATUS_CLR_INTR
	lui   $at, %hi(PHYS_TO_K1(PI_STATUS_REG))
	andi  $s1, $s1, 0x2f
	sw    $t1, %lo(PHYS_TO_K1(PI_STATUS_REG))($at)
	jal   send_mesg
	li    $a0, OS_EVENT_PI * SIZEOF_OSEVENTSTATE
	beqzl $s1, .after_clear_all_interrupts
	li    $at, ~CAUSE_IP3
	andi  $t1, $s1, 0x20
.after_clear_pi_interrupt:
	beqzl $t1, .after_clear_dp_interrupt
	li    $at, ~CAUSE_IP3
	li    $t1, MI_CLR_DP_INTR
	lui   $at, %hi(PHYS_TO_K1(MI_MODE_REG))
	andi  $s1, $s1, 0x1f
	sw    $t1, %lo(PHYS_TO_K1(MI_MODE_REG))($at)
	jal   send_mesg
	li    $a0, OS_EVENT_DP * SIZEOF_OSEVENTSTATE
	li    $at, ~CAUSE_IP3
.after_clear_dp_interrupt:
.after_clear_all_interrupts:
	b     .interrupt_loop_outer
	and   $s0, $s0, $at

.handle_intr_prenmi:
	lw    $k1, 0x118($k0)
	li    $at, ~CAUSE_IP5
	lui   $t1, %hi(_osShutdown)
	and   $k1, $k1, $at
	sw    $k1, 0x118($k0)
	addiu $t1, $t1, %lo(_osShutdown)
	lw    $t2, 0x0($t1)
	beqz  $t2, .not_shutting_down
	li    $at, ~CAUSE_IP5
	b     .dispatch_thread
	and   $s0, $s0, $at
.not_shutting_down:
	li    $t2, 0x1
	sw    $t2, 0x0($t1)
	jal   send_mesg
	li    $a0, OS_EVENT_PRENMI * SIZEOF_OSEVENTSTATE
	lui   $t2, %hi(__osRunQueue)
	lw    $t2, %lo(__osRunQueue)($t2)
	li    $at, ~CAUSE_IP5
	and   $s0, $s0, $at
	lw    $k1, 0x118($t2)
	and   $k1, $k1, $at
	b     .dispatch_thread
	sw    $k1, 0x118($t2)

.handle_intr_sw2:
	li    $at, ~CAUSE_SW2
	and   $t0, $t0, $at
	mtc0  $t0, C0_CAUSE
	jal   send_mesg
	li    $a0, OS_EVENT_SW2 * SIZEOF_OSEVENTSTATE
	li    $at, ~CAUSE_SW2
	b     .interrupt_loop_outer
	and   $s0, $s0, $at

.handle_intr_sw1:
	li    $at, ~CAUSE_SW1
	and   $t0, $t0, $at
	mtc0  $t0, C0_CAUSE
	jal   send_mesg
	li    $a0, OS_EVENT_SW1 * SIZEOF_OSEVENTSTATE
	li    $at, ~CAUSE_SW1
	b     .interrupt_loop_outer
	and   $s0, $s0, $at

.handle_rmiss:
	jal   vmHandleMiss
 	nop
	b     .dispatch_thread
 	nop

.handle_wmiss:
	j     handle_fault
 	nop

	li    $t1, OS_FLAG_CPU_BREAK
.handle_break:
	sh    $t1, 0x12($k0)
	lw    $t1, 0x11c($k0)
	li    $at, 0x6
	lw    $t1, 0x0($t1)
	srl   $t1, $t1, 0x10
	andi  $t1, $t1, 0xff
	beq   $t1, $at, handle_fault
	li    $at, 0x7
	beq   $t1, $at, handle_fault
 	nop
	jal   send_mesg
	li    $a0, OS_EVENT_CPU_BREAK * SIZEOF_OSEVENTSTATE
	b     .dispatch_thread
 	nop

.handle_intr_redispatch:
.dispatch_thread:
	lw    $t2, __osRunQueue
	lw    $t1, 0x4($k0) # t1 = __osRunningThread->priority
	lw    $t3, 0x4($t2) # t3 = __osRunQueue->priority
	slt   $at, $t1, $t3
	beqz  $at, .prepend_to_runqueue
 	nop
 	# The run queue has the higher priority thread -> queue the running thread
	lui   $a0, %hi(__osRunQueue)
	move  $a1, $k0
	jal   __osEnqueueThread
	addiu $a0, $a0, %lo(__osRunQueue)
	j     __osDispatchThread
 	nop
.prepend_to_runqueue:
	la    $t1, __osRunQueue
	lw    $t2, 0x0($t1)
	sw    $t2, 0x0($k0)
	j     __osDispatchThread
	sw    $k0, 0x0($t1)

glabel handle_fault
	lui   $at, %hi(__osFaultedThread)
	sw    $k0, %lo(__osFaultedThread)($at)
	li    $t1, OS_STATE_STOPPED
	sh    $t1, 0x10($k0)
	li    $t1, OS_FLAG_FAULT
	sh    $t1, 0x12($k0)
	mfc0  $t2, C0_BADVADDR
	sw    $t2, 0x124($k0)
	jal   send_mesg
	li    $a0, OS_EVENT_FAULT * SIZEOF_OSEVENTSTATE
	j     __osDispatchThread
 	nop

glabel send_mesg
	la    $t2, __osEventStateTab
	addu  $t2, $t2, $a0 # t2 = __OSEventState
	lw    $t1, 0x0($t2) # t1 = message queue
	move  $s2, $ra
	beqz  $t1, .send_mesg_return # No message queue
 	nop
	lw    $t3, 0x8($t1)  # t3 = queue->validCount
	lw    $t4, 0x10($t1) # t4 = queue->msgCount
	slt   $at, $t3, $t4
	beqz  $at, .send_mesg_return # Queue is full
 	nop
	lw    $t5, 0xc($t1)  # t5 = queue->first
	addu  $t5, $t5, $t3
	div   $zero, $t5, $t4
	bnez  $t4, .L00003b00
 	nop
	break 0x7
.L00003b00:
	li    $at, -1
	bne   $t4, $at, .L00003b18
	li    $at, 0x80000000
	bne   $t5, $at, .L00003b18
 	nop
	break 0x6
.L00003b18:
	lw    $t4, 0x14($t1) # t4 = queue->msg
	mfhi  $t5
	sll   $t5, $t5, 0x2
	addu  $t4, $t4, $t5
	lw    $t5, 0x4($t2)  # t5 = eventstate->message
	addiu $t2, $t3, 0x1
	sw    $t5, 0x0($t4)
	sw    $t2, 0x8($t1)
	lw    $t2, 0x0($t1)
	lw    $t3, 0x0($t2)
	beqz  $t3, .send_mesg_return
 	nop
	jal   __osPopThread
	move  $a0, $t1
	move  $t2, $v0
	lui   $a0, %hi(__osRunQueue)
	move  $a1, $t2
	jal   __osEnqueueThread
	addiu $a0, $a0, %lo(__osRunQueue)
.send_mesg_return:
	jr    $s2
 	nop

.handle_cpu:
	li    $at, CAUSE_CEMASK
	and   $t1, $t0, $at
	srl   $t1, $t1, CAUSE_CESHIFT
	li    $t2, 1
	bne   $t1, $t2, handle_fault
 	nop
	lw    $k1, 0x118($k0)
	li    $at, SR_CU1
	li    $t1, 1
	or    $k1, $k1, $at
	sw    $t1, 0x18($k0)  # Set __osRunningThread->fp = 1
	b     .prepend_to_runqueue
	sw    $k1, 0x118($k0) # Set __osRunningThread->sr

glabel __osEnqueueAndYield
	lw    $a1, __osRunningThread
	mfc0  $t0, C0_SR
	lw    $k1, 0x18($a1)
	ori   $t0, $t0, SR_EXL
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
	beqz  $k1, .after_store_fp
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
.after_store_fp:
	lw    $k1, 0x118($a1)
	andi  $t1, $k1, SR_IMASK
	beqzl $t1, .after_store_imask
	la    $k1, PHYS_TO_K1(MI_MODE_REG)
	la    $t0, __osGlobalIntMask
	lw    $t0, 0x0($t0)
	li    $at, 0xffffffff
	xor   $t0, $t0, $at
	lui   $at, 0xffff
	andi  $t0, $t0, 0xff00
	ori   $at, $at, 0xff
	or    $t1, $t1, $t0
	and   $k1, $k1, $at
	or    $k1, $k1, $t1
	sw    $k1, 0x118($a1)
	lui   $k1, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
.after_store_imask:
	lw    $k1, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($k1)
	beqz  $k1, .after_load_imask
 	nop
	la    $k0, __osGlobalIntMask
	lw    $k0, 0x0($k0)
	lw    $t0, 0x128($a1)
	li    $at, 0xffffffff
	srl   $k0, $k0, 0x10
	xor   $k0, $k0, $at
	andi  $k0, $k0, 0x3f
	and   $k0, $k0, $t0
	or    $k1, $k1, $k0
.after_load_imask:
	beqz  $a0, .after_enqueue
	sw    $k1, 0x128($a1)
	jal   __osEnqueueThread
 	nop
.after_enqueue:
	j     __osDispatchThread
 	nop

/**
 * a0 = OSThread **queue
 * a1 = OSThread *thread
 */
glabel __osEnqueueThread
	lw    $t8, 0x0($a0)  # t8 = queue->next
	lw    $t7, 0x4($a1)  # t7 = thread->priority
	move  $t9, $a0       # iter = queue
	lw    $t6, 0x4($t8)  # t6 = queue->next->priority
	slt   $at, $t6, $t7
	bnezl $at, .enqueue_here
	lw    $t8, 0x0($t9)

	move  $t9, $t8
.enqueue_loop:
	lw    $t8, 0x0($t8)
	lw    $t6, 0x4($t8)
	slt   $at, $t6, $t7
	beqzl $at, .enqueue_loop
	move  $t9, $t8

	lw    $t8, 0x0($t9)
.enqueue_here:
	sw    $t8, 0x0($a1)  # thread->next = t8
	sw    $a1, 0x0($t9)  # iter->next = thread
	jr    $ra
	sw    $a0, 0x8($a1)  # thread->queue = queue

/**
 * a0 = OSThread **queue
 */
glabel __osPopThread
 	lw	$v0, 0x0($a0)  # v0 = *queue
 	lw	$t9, 0x0($v0)  # t9 = v0->next
 	jr	$ra
 	sw	$t9, 0x0($a0)  # *queue = t9

glabel __osDispatchThread
	lui   $a0, %hi(__osRunQueue)
	jal   __osPopThread
	addiu $a0, $a0, %lo(__osRunQueue)
	lui   $at, %hi(__osRunningThread)
	sw    $v0, %lo(__osRunningThread)($at)
	li    $t0, OS_STATE_RUNNING
	sh    $t0, 0x10($v0)
	move  $k0, $v0
	lui   $t0, %hi(__osGlobalIntMask)
	lw    $k1, 0x118($k0)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t0, 0x0($t0)
	lui   $at, 0xffff
	andi  $t1, $k1, SR_IMASK
	ori   $at, $at, 0xff
	andi  $t0, $t0, SR_IMASK
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
	beqz  $k1, .after_restore_fp
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
.after_restore_fp:
	lw    $k1, 0x128($k0)
	la    $k0, __osGlobalIntMask
	lw    $k0, 0x0($k0)
	srl   $k0, $k0, 0x10
	and   $k1, $k1, $k0
	sll   $k1, $k1, 0x1
	la    $k0, var70059e30
	addu  $k1, $k1, $k0
	lhu   $k1, 0x0($k1)
	lui   $k0, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
	addiu $k0, $k0, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))
	sw    $k1, 0x0($k0)
 	nop
 	nop
 	nop
 	nop
 	eret

glabel __osCleanupThread
 	jal	  osDestroyThread
 	move  $a0, $zero
