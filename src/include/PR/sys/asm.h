/**************************************************************************
 *									  *
 * 		 Copyright (C) 1990, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/
/*
 * Copyright 1985 by MIPS Computer Systems, Inc.
 */
#ifndef __SYS_ASM_H__
#define __SYS_ASM_H__

#ident "$Revision: 3.33 $"

#include "sgidefs.h"

/*
 * asm.h -- cpp definitions for assembler files
 */

/*
 * Notes on putting entry pt and frame info into symbol table for debuggers
 *
 *	.ent	name,lex-level	# name is entry pt, lex-level is 0 for c
 * name:			# actual entry point
 *	.frame	fp,framesize,saved_pc_reg
 *				# fp -- register which is pointer to base
 *				#	of previous frame, debuggers are special
 *				#	cased if "sp" to add "framesize"
 *				#	(sp is usually used)
 *				# framesize -- size of frame
 *				#	the expression:
 *				#		new_sp + framesize == old_sp
 *				#	should be true
 *				# saved_pc_reg -- either a register which
 *				#	contains callers pc or $0, if $0
 *				#	saved pc is assumed to be in
 *				#	(fp)+framesize-4
 *
 * Notes regarding multiple entry points:
 * LEAF is used when including the profiling header is appropriate
 * XLEAF is used when the profiling header is in appropriate (e.g.
 * when a entry point is known by multiple names, the profiling call
 * should appear only once.)  The correct ordering of ENTRY/XENTRY in this
 * case is:
 * LEAF(copyseg)		# declare globl and emit profiling code
 * XLEAF(copypage)		# declare globl and alternate entry
 */
/*
 * LEAF -- declare leaf routine
 */
#define	LEAF(x)						\
	.globl	x;					\
	.ent	x,0;					\
x:;							\
	.frame	sp,0,ra

/*
 * XLEAF -- declare alternate entry to leaf routine
 */
#define	XLEAF(x)					\
	.globl	x;					\
	.aent	x,0;					\
x:

/*
 * VECTOR -- declare exception routine entry
 */
#if _K32U32
#define	VECTOR(x, regmask)				\
	.globl	x;					\
	.ent	x,0;					\
x:;							\
	.frame	sp,EF_SIZE,$0;				\
	.mask	+(regmask)|M_EXCFRM,-(EF_SIZE-(EF_RA))
#else
#define	VECTOR(x, regmask)				\
	.globl	x;					\
	.ent	x,0;					\
x:;							\
	.frame	sp,EF_SIZE,$0;				\
	.mask	+(regmask)|M_EXCFRM,-(EF_SIZE-(EF_RA+4))
#endif

/*
 * NESTED -- declare nested routine entry point
 */
#define	NESTED(x, fsize, rpc)				\
	.globl	x;					\
	.ent	x,0;					\
x:;							\
	.frame	sp,fsize, rpc

/*
 * XNESTED -- declare alternate entry point to nested routine
 */
#define	XNESTED(x)					\
	.globl	x;					\
	.aent	x,0;					\
x:

/*
 * END -- mark end of procedure
 */
#define	END(proc)					\
	.end	proc

/*
 * IMPORT -- import external symbol
 */
#define	IMPORT(sym, size)				\
	.extern	sym,size

/*
 * ABS -- declare absolute symbol
 */
#define	ABS(x, y)					\
	.globl	x;					\
x	=	y

/*
 * EXPORT -- export definition of symbol
 */
#define	EXPORT(x)					\
	.globl	x;					\
x:

/*
 * BSS -- allocate space in bss
 */
#define	BSS(x,y)		\
	.comm	x,y

/*
 * LBSS -- allocate static space in bss
 */
#define	LBSS(x,y)		\
	.lcomm	x,y

/*
 * Macros for writing PIC asm code
 */
#ifdef PIC
#define PICOPT	.option	pic2

/*
 * Set gp when at 1st instruction
 */
#define SETUP_GP					\
        .set	noreorder;				\
        .cpload	t9;					\
    	.set	reorder

/*
 * Set gp when not at 1st instruction
 */
#define SETUP_GPX(r)					\
	.set	noreorder;				\
	move	r, ra;		/* save old ra */	\
	bal	10f;		/* find addr of cpload */\
	nop;						\
10:							\
	.cpload ra;					\
	move	ra, r;					\
	.set	reorder;

#define SAVE_GP(x)					\
	.cprestore x;	/* save gp trigger t9/jalr conversion */

#else /* PIC */

#define PICOPT
#define SETUP_GP
#define SETUP_GPX(r)
#define SAVE_GP(x)

#endif /* PIC */

/*
 * Stack Frame Definitions
 */
#if (_MIPS_SIM == _MIPS_SIM_ABI32)
#define NARGSAVE	4	/* space for 4 arg regs must be allocated */
#define ALSZ		7	/* align on 8 byte boundary */
#define ALMASK		~7
#endif
#if (_MIPS_SIM == _MIPS_SIM_ABI64)
#define NARGSAVE	0	/* no caller responsibilities */
#define ALSZ		15	/* align on 16 byte boundary */
#define ALMASK		~0xf
#endif

#if _KERNEL
/* Round the size of a stack frame to fit compiler conventions. */
#define FRAMESZ(size) (((size)+ALSZ) & ALMASK)
#endif

#if (_MIPS_ISA == _MIPS_ISA_MIPS1 || _MIPS_ISA == _MIPS_ISA_MIPS2) 
#define SZREG		4
#endif

#if (_MIPS_ISA == _MIPS_ISA_MIPS3 || _MIPS_ISA == _MIPS_ISA_MIPS4) 
#define SZREG		8
#endif

/*
 * The following macros reserve the usage of the local label '9'
 * By convention the caller should put the return addr in a2
 * so that the stack backtrace can trace from a leaf
 */
#if defined(STANDALONE) || defined(LOCORE)
#define	PANIC(msg)					\
	sw	zero,waittime;				\
	la	a0,9f;					\
	jal	panic;					\
	MSG(msg)

#define	PRINTF(msg)					\
	la	a0,9f;					\
	jal	printf;					\
	MSG(msg)

#else /* the kernel */
#define	PANIC(msg)					\
	li	a0,CE_PANIC;				\
	la	a1,9f;					\
	jal	cmn_err;				\
	MSG(msg)

#define	SPPANIC(msg)					\
	/* make sure a good frame */\
	lw	sp,VPDA_LBOOTSTACK(zero);		\
	li	a0,CE_PANIC;				\
	la	a1,9f;					\
	jal	cmn_err;				\
	MSG(msg)

#define ASMASSFAIL(msg)					\
	la	a0,9f;					\
	la	a1,lmsg;				\
	move	a2,zero;				\
	j	assfail;				\
	MSG(msg)

#define	PRINTF(msg)					\
	la	a0,9f;					\
	jal	dprintf;					\
	MSG(msg)

#endif /* defined(STANDALONE) || defined(LOCORE) */

#define	MSG(msg)					\
	.data;						\
9:	.asciiz	msg;					\
	.text

#define	SYSMAP(mname, vname, page, len)			\
	.globl	mname;					\
mname:							\
	.space	len*4;					\
	.globl	vname;					\
vname	=	((page)*NBPG)

#if !defined(_MIPSEB) && !defined(_MIPSEL)
	.error Must define either _MIPSEB or _MIPSEL
#endif
#if defined(_MIPSEB) && defined(_MIPSEL)
	.error Only one of _MIPSEB and _MIPSEL may be defined
#endif

/*
 * The following macros deal with the coprocessor 0 scheduling
 * hazards, which are different for the R3000 and R4000.
 * The first digit in the name refers to the number
 * of NOPs in the R2000/R3000 case, while the second digit
 * refers to the number of NOPs in the R4000 case.
 * NOTE: For now use R4000 values for TFP too.  This at least
 * lets us make the kernel.
 */
#if R4000
#define NOP_0_1		nop
#define NOP_0_2		nop; nop
#define NOP_0_3		nop; nop; nop
#define NOP_0_4		nop; nop; nop; nop
#define NOP_1_0
#define NOP_1_1		nop
#define NOP_1_2		nop; nop
#define NOP_1_3		nop; nop; nop
#define NOP_1_4		nop; nop; nop; nop
#endif

#if TFP
#define NOP_0_1
#define NOP_0_2
#define NOP_0_3
#define NOP_0_4
#define NOP_1_0
#define NOP_1_1		NOP_SSNOP
#define NOP_1_2		NOP_SSNOP
#define NOP_1_3		NOP_SSNOP
#define NOP_1_4		NOP_SSNOP
/* TFP has the following kinds of nops:
 * 
 * NOP_NOP	regular old nop -- takes a dispatch slot, but another
 *		integer instruction could be issued with it.  But since
 *		TFP has only one shifter, two consecutive NOP_NOPs would
 *		go in separate cycles
 * NOP_SSNOP	nop which breaks superscalar dispatch.  Will be the last
 *		instruction issued in a cycle.  Instruction following
 *		will be first instruction issued in next cycle.
 * NOP_NADA	more than one of these can be scheduled per cycle 
 *		since it does not use the shifter
 */
#define	NOP_NOP		sll zero,zero,0
#define	NOP_SSNOP	sll zero,zero,1
#define	NOP_NADA	addu zero,zero,zero
/*
 * The following hazards are intended to be the maximum needed so that we
 * do not have to worry about the instructions which follow.  You may make
 * use of the actual restrictions in order to optimize the code.
 * 
 * Theoretically, NOP_MFC1_HAZ and NOP_MTC1_HAZ should not be needed but they
 * are here just in case.
 *
 * NOP_MFC0_HAZ		hazard after loading from C0
 * NOP_MTC0_HAZ		hazard after storing to C0
 * NOP_ERET_HAZ		hazard before eret after storing C0 registers
 * NOP_COM_HAZ		hazard following a COM operation -- TLBW, TLBR, etc.
 * NOP_MFC1_HAZ		hazard after loading from C1
 * NOP_MTC1_HAZ		hazard after storing to C1
 *
 * Actual restrictions:
 * MFC0
 *	- two dmfc0 should not be executed in same cycle
 *	- a dmfc0 should not be issued in cycle following a dmtc0
 * MTC0
 *	- in cycle after dmtc0 VAddr a COM will not correctly execute
 *	- in cycle after dmtc0 status a COM will not correctly execute
 *	- in same cycle as dmtc0 TLBSet a COM will not correctly execute
 *	- integer store should not be execute in same cycle as dmtc0 VAddr
 *	- two dmtc0 should not be executed in the same cycle
 *	- a dmfc0 should not be issued in cycle following a dmtc0
 *
 *	- there should be three SSNOPs following a MTC0 which
 *	  is enabling/disabling interrupts in the SR before new mask is
 *	  effective
 *	- there should be three SSNOPs between a MTC0 which enables a CU
 *	  field (like the FP) before issuing an instruction which uses the
 *	  the FP.
 * COM
 *	- 2 cycles after a COM a memory instruction will not execute properly
 *	- a TLBR/DCTR followed by a dmfc0 of EntryHi/EntryLo/DCache should
 *	  leave two cycles between TLBR and dmfc0
 *
 * Additional restriction found executing kernel on RTL simulator:
 *--------------------------------------------------------------------------
 *	jr      r31
 *	dmtc0   r2,sr
 * The jr happens to jump to 0x801b9204.  However, the jal didn't store the
 * proper value (pc + 8) into r31.
 * The reason for this behavior is that mtc0's require an internal bus
 * (MiscBus to be specific), in the W cycle.  However, the jal also requires
 * the MiscBus in its E cycle.  Thus, the mux select lines for selecting
 * the data to go into the GPR was incorrect.
 * To make sure something like this won't occur again, it's probably a good
 * idea not to have mtc0's in the delay slot, unless you are sure that the
 * target quadword of instructions won't cause this internal bus collision.
 *--------------------------------------------------------------------------
 */
#define	NOP_MFC0_HAZ	NOP_SSNOP
#define	NOP_MTC0_HAZ	NOP_SSNOP; NOP_SSNOP; NOP_SSNOP; NOP_SSNOP
#define	NOP_ERET_HAZ
#define	NOP_COM_HAZ	NOP_SSNOP; NOP_SSNOP; NOP_SSNOP; NOP_SSNOP
/*
 * The NOP_MFC1_HAZ and NOP_MTC1_HAZ are here only due to paranoia.
 * I am also defining DMFC1 and DMTC1 which use these macros (in ip21prom.h).
 * All this will exist until there is established confidence in FPU.
 */
#define NOP_MFC1_HAZ	NOP_SSNOP; NOP_SSNOP; NOP_SSNOP; NOP_SSNOP
#define NOP_MTC1_HAZ	NOP_SSNOP; NOP_SSNOP; NOP_SSNOP; NOP_SSNOP
#endif 

#if R3000
#define NOP_0_1
#define NOP_0_2
#define NOP_0_3
#define NOP_0_4
#define NOP_1_0		nop
#define NOP_1_1		nop
#define NOP_1_2		nop
#define NOP_1_3		nop
#define NOP_1_4		nop
#endif

/*
 * register mask bit definitions
 */
#define	M_EXCFRM	0x00000001
#define	M_AT		0x00000002
#define	M_V0		0x00000004
#define	M_V1		0x00000008
#define	M_A0		0x00000010
#define	M_A1		0x00000020
#define	M_A2		0x00000040
#define	M_A3		0x00000080
#define	M_T0		0x00000100
#define	M_T1		0x00000200
#define	M_T2		0x00000400
#define	M_T3		0x00000800
#define	M_T4		0x00001000
#define	M_T5		0x00002000
#define	M_T6		0x00004000
#define	M_T7		0x00008000
#define	M_S0		0x00010000
#define	M_S1		0x00020000
#define	M_S2		0x00040000
#define	M_S3		0x00080000
#define	M_S4		0x00100000
#define	M_S5		0x00200000
#define	M_S6		0x00400000
#define	M_S7		0x00800000
#define	M_T8		0x01000000
#define	M_T9		0x02000000
#define	M_K0		0x04000000
#define	M_K1		0x08000000
#define	M_GP		0x10000000
#define	M_SP		0x20000000
#define	M_FP		0x40000000
#define	M_RA		0x80000000


/*
 * Macros for dealing with 64/32 bit asm files
 */

/*
 * Basic register save and restore
 */
#if (_MIPS_ISA == _MIPS_ISA_MIPS1 || _MIPS_ISA == _MIPS_ISA_MIPS2) 
#define REG_L	lw
#define REG_S	sw
#endif

#if (_MIPS_ISA == _MIPS_ISA_MIPS3 || _MIPS_ISA == _MIPS_ISA_MIPS4) 
#define REG_L	ld
#define REG_S	sd
#endif

#if (_MIPS_SZINT == 32)
#define INT_L	lw
#define INT_S	sw
#define INT_LLEFT	lwl	/* load left */
#define INT_SLEFT	swl	/* store left */
#define INT_LRIGHT	lwr	/* load right */
#define INT_SRIGHT	swr	/* store right */
#define INT_ADD		add
#define INT_ADDI	addi
#define INT_ADDIU	addiu
#define INT_ADDU	addu
#define INT_SUB		sub
#define INT_SUBI	subi
#define INT_SUBIU	subiu
#define INT_SUBU	subu
#define INT_SLL		sll
#define INT_SRL		srl
#define INT_SRA		sra
#define INT_SLLV	sllv
#define INT_SRLV	srlv
#define INT_SRAV	srav
#define INT_LL		ll
#define INT_SC		sc
#endif	/* _MIPS_SZINT == 32 */

#if (_MIPS_SZINT == 64)
#define INT_L	ld
#define INT_S	sd
#define INT_LLEFT	ldl	/* load left */
#define INT_SLEFT	sdl	/* store left */
#define INT_LRIGHT	ldr	/* load right */
#define INT_SRIGHT	sdr	/* store right */
#define INT_ADD		dadd
#define INT_ADDI	daddi
#define INT_ADDIU	daddiu
#define INT_ADDU	daddu
#define INT_SUB		dsub
#define INT_SUBI	dsubi
#define INT_SUBIU	dsubiu
#define INT_SUBU	dsubu
#define INT_SLL		dsll
#define INT_SRL		dsrl
#define INT_SRA		dsra
#define INT_SLLV	dsllv
#define INT_SRLV	dsrlv
#define INT_SRAV	dsrav
#define INT_LL		lld
#define INT_SC		scd
#endif	/* _MIPS_SZINT == 64 */

#if (_MIPS_SZLONG == 32)
#define LONG_L	lw
#define LONG_S	sw
#define LONG_LLEFT	lwl	/* load left */
#define LONG_SLEFT	swl	/* store left */
#define LONG_LRIGHT	lwr	/* load right */
#define LONG_SRIGHT	swr	/* store right */
#define LONG_ADD	add
#define LONG_ADDI	addi
#define LONG_ADDIU	addiu
#define LONG_ADDU	addu
#define LONG_SUB	sub
#define LONG_SUBI	subi
#define LONG_SUBIU	subiu
#define LONG_SUBU	subu
#define LONG_SLL	sll
#define LONG_SRL	srl
#define LONG_SRA	sra
#define LONG_SLLV	sllv
#define LONG_SRLV	srlv
#define LONG_SRAV	srav
#define LONG_LL		ll
#define LONG_SC		sc
#endif	/* _MIPS_SZLONG == 32 */

#if (_MIPS_SZLONG == 64)
#define LONG_L	ld
#define LONG_S	sd
#define LONG_LLEFT	ldl	/* load left */
#define LONG_SLEFT	sdl	/* store left */
#define LONG_LRIGHT	ldr	/* load right */
#define LONG_SRIGHT	sdr	/* store right */
#define LONG_ADD	dadd
#define LONG_ADDI	daddi
#define LONG_ADDIU	daddiu
#define LONG_ADDU	daddu
#define LONG_SUB	dsub
#define LONG_SUBI	dsubi
#define LONG_SUBIU	dsubiu
#define LONG_SUBU	dsubu
#define LONG_SLL	dsll
#define LONG_SRL	dsrl
#define LONG_SRA	dsra
#define LONG_SLLV	dsllv
#define LONG_SRLV	dsrlv
#define LONG_SRAV	dsrav
#define LONG_LL		lld
#define LONG_SC		scd
#endif	/* _MIPS_SZLONG == 64 */

#if (_MIPS_SZPTR == 32)
#define PTR_L	lw
#define PTR_S	sw
#define PTR_LLEFT	lwl	/* load left */
#define PTR_SLEFT	swl	/* store left */
#define PTR_LRIGHT	lwr	/* load right */
#define PTR_SRIGHT	swr	/* store right */
#define PTR_ADD		add
#define PTR_ADDI	addi
#define PTR_ADDIU	addiu
#define PTR_ADDU	addu
#define PTR_SUB		sub
#define PTR_SUBI	subi
#define PTR_SUBIU	subiu
#define PTR_SUBU	subu
#define PTR_SLL		sll
#define PTR_SRL		srl
#define PTR_SRA		sra
#define PTR_SLLV	sllv
#define PTR_SRLV	srlv
#define PTR_SRAV	srav
#define PTR_LL		ll
#define PTR_SC		sc

#define	PTR_WORD	.word	/* psuedo-op to reserve space for a ptr */
#define	PTR_SCALESHIFT	2

#define	LI		li
#define LA		la
#endif	/* _MIPS_SZPTR == 32 */

#if (_MIPS_SZPTR == 64)
#define PTR_L	ld
#define PTR_S	sd
#define PTR_LLEFT	ldl	/* load left */
#define PTR_SLEFT	sdl	/* store left */
#define PTR_LRIGHT	ldr	/* load right */
#define PTR_SRIGHT	sdr	/* store right */
#define PTR_ADD		dadd
#define PTR_ADDI	daddi
#define PTR_ADDIU	daddiu
#define PTR_ADDU	daddu
#define PTR_SUB		dsub
#define PTR_SUBI	dsubi
#define PTR_SUBIU	dsubiu
#define PTR_SUBU	dsubu
#define PTR_SLL		dsll
#define PTR_SRL		dsrl
#define PTR_SRA		dsra
#define PTR_SLLV	dsllv
#define PTR_SRLV	dsrlv
#define PTR_SRAV	dsrav
#define PTR_LL		lld
#define PTR_SC		scd

#define	PTR_WORD	.dword	/* psuedo-op to reserve space for a ptr */
#define	PTR_SCALESHIFT	3

#define	LI		dli
#define LA		dla
#endif	/* _MIPS_SZPTR == 64 */

#if (_MIPS_ISA == _MIPS_ISA_MIPS1 || _MIPS_ISA == _MIPS_ISA_MIPS2) 
#define MFC0	mfc0
#define MTC0	mtc0
#endif

#if (_MIPS_ISA == _MIPS_ISA_MIPS3 || _MIPS_ISA == _MIPS_ISA_MIPS4) 
#define MFC0	dmfc0
#define MTC0	dmtc0
#endif
#if TFP
#define	DMTC0(r,c)	dmtc0	r,c;	\
			NOP_MTC0_HAZ
#define	DMFC0(c,r)	dmfc0	c,r;	\
			NOP_MFC0_HAZ
#if _K32U32 || _K32U64
	# This code only works for SABLE
	# We need to avoid a tlbmiss on the PC address (our pseudo-K0 space)
	# because such a fault destroys values loaded into BADVADDR,
	# TLBHI, etc.
#define	SABLE_GOTO_KP64(reg1,reg2)	\
	lui	reg2,0xa000;	\
	dsll	reg2,32;	\
	la	reg1,1f;	\
	dsll	reg1,35;	\
	dsrl	reg1,35;	\
	dadd	reg1,reg2;	\
	NOP_SSNOP;		\
	j	reg1;		\
	NOP_SSNOP;		\
	NOP_SSNOP;		\
1:	NOP_SSNOP		\
	# Now we're executing in Kernel Physical (KP) space
#else
#define	SABLE_GOTO_KP64(reg1,reg2)
#endif	/* !_K32U32 && ! _K32U64 */

#endif	/* TFP */
#if R3000 || R4000
/* These macros let us replace existing mtc0/mfc0 instructions with macros
 * that have no additional overhead for non-TFP machines but have the required
 * number of scheduling NOPS for TFP.
 */
#define	DMTC0(r,c)	mtc0	r,c
#define	DMFC0(c,r)	mfc0	c,r
#define	SABLE_GOTO_KP64(reg1,reg2)
#endif	/* R3000 || R4000 */

#if TFP_TLBCACHE_WAR
/*
 * This problem occurs when there is an I-Cache miss within two cycles of 
 * a valid tlb or dct (data cache tag) instruction.  If the previous contents
 * of the I-Cache contained a store instruction, the data cache can be
 * corrupted.
 *
 * This problem can be worked around by putting all tlb/dct instructions on a
 * 16-byte boundary.   And, the three instructions that follow the tlb/dct
 * must be ssnops (super-scalar no-ops).  This guarantees that for the two
 * cycles following the tlb/dct instruction, there can only be noops in the
 * pipeline.
 */
#define	TLB_READ	.align 4;		\
			c0	C0_READ;	\
			NOP_SSNOP;		\
			NOP_SSNOP;		\
			NOP_SSNOP
#define	TLB_WRITER	.align 4;		\
			c0	C0_WRITER;	\
			NOP_SSNOP;		\
			NOP_SSNOP;		\
			NOP_SSNOP
#define	TLB_PROBE	.align 4;		\
			c0	C0_PROBE;	\
			NOP_SSNOP;		\
			NOP_SSNOP;		\
			NOP_SSNOP
#else	/* !TFP_TLBCACHE_WAR */
#if TFP
#define	TLB_READ	c0	C0_READ; 	\
			NOP_COM_HAZ
#define	TLB_WRITER	c0	C0_WRITER; 	\
			NOP_COM_HAZ
#define	TLB_PROBE	c0	C0_PROBE;	\
			NOP_COM_HAZ
#else
#define	TLB_READ	c0	C0_READ
#define	TLB_WRITER	c0	C0_WRITER
#endif
#endif	/* !TFP_TLBCACHE_WAR */
#endif	/* __SYS_ASM_H__ */
