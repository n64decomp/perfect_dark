/**************************************************************************
 *									  *
 * Copyright (C) 1991-1992 Silicon Graphics, Inc.			  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/
#ifndef __SGIDEFS_H__
#define __SGIDEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#ident "$Revision: 1.5 $"

/*
 * sgidefs.h - SGI/MIPS basic software generation system constants & types
 *
 * This file MUST be includable in any language
 * and in the 'C' case must be ANSI compliant
 * In particular this means NO long long ...
 *
 * Constants and types defined here are to support
 * multi-isa (instruction set architecture) coding
 *
 * Each catagory has a define that the compilation system will set
 * based on the environment the compile is initiated in. Programs
 * can test the define using the manifest constants defined here.
 * (e.g. #if (_MIPS_FPSET == 16) )
 */

/*
 * Floating Point register set
 * Define:
 *	_MIPS_FPSET
 * Can take on the values 16 or 32
 */

/*
 * Instruction Set Architecture
 * Define:
 *	_MIPS_ISA
 */
#define _MIPS_ISA_MIPS1	1	/* R2/3K */
#define _MIPS_ISA_MIPS2	2	/* R4K/6K */
#define _MIPS_ISA_MIPS3	3	/* R4K */
#define _MIPS_ISA_MIPS4	4	/* TFP */

/*
 * Subprogram Interface Model
 * Define:
 *	_MIPS_SIM
 */
#define _MIPS_SIM_ABI32		1	/* MIPS MSIG calling convention */
#define _MIPS_SIM_NABI32	2	/* MIPS new 32-bit abi */
		/* NABI32 is 64bit calling convention but 32bit type sizes) */
#define _MIPS_SIM_ABI64		3	/* MIPS 64 calling convention */

/*
 * Data Types Sizes (C and C++)
 * Defines:
 *	_MIPS_SZINT
 *	_MIPS_SZLONG
 *	_MIPS_SZPTR
 *
 * These can take on the values: 32, 64, 128
 */

/*
 * Compilation Environments
 *	various compilers may offer a set of different compilation environments
 *	each one will pre-define the above defines appropriately.
 * The MIPS ABI environment will pre-define the following:
 *	(cc -systype=XXX)
 *
 *	-D_MIPS_FPSET=16 -D_MIPS_ISA=_MIPS_ISA_MIPS1
 *	-D_MIPS_SIM=_MIPS_SIM_ABI32 -D_MIPS_SZINT=32
 *	-D_MIPS_SZLONG=32 -D_MIPS_SZPTR=32
 *
 * The new MIPS 32-bit ABI environment will pre-define the following
 *	(cc -systype=XXX)
 *	-D_MIPS_FPSET=32 -D_MIPS_ISA=_MIPS_ISA_MIPS3
 *	-D_MIPS_SIM=_MIPS_SIM_NABI32 -D_MIPS_SZINT=32
 *	-D_MIPS_SZLONG=32 -D_MIPS_SZPTR=32
 *
 * The MIPS 64 bit environment will pre-define the following
 *	(cc -systype=XXX)
 *	-D_MIPS_FPSET=32 -D_MIPS_ISA=_MIPS_ISA_MIPS3
 *	-D_MIPS_SIM=_MIPS_SIM_ABI64 -D_MIPS_SZINT=32
 *	-D_MIPS_SZLONG=64 -D_MIPS_SZPTR=64
 *
 */

/*
 * Language Specific
 * Type __psint_t - a pointer sized int - this can be used:
 *	a) when casting a pointer so can perform e.g. a bit operation
 *	b) as a return code for functions incorrectly typed as int but
 *	   return a pointer.
 * User level code can also use the ANSI std ptrdiff_t, defined in stddef.h
 *	in place of __psint_t
 * Type __scint_t - a 'scaling' int - used when in fact one wants an 'int'
 *	that scales when moving to say 64 bit. (e.g. byte counts, bit lens)
 */

#if (defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS))

/*
 * assumes int is 32 -
 * otherwise there must be some other compiler basic type
 */
#if (_MIPS_SZINT != 32)
#ifdef _MIPS_SZINT
ERROR -- the macro "_MIPS_SZINT" is set to _MIPS_SZINT -- should be 32
#else
ERROR -- the macro "_MIPS_SZINT" is unset (currently, must be set to 32)
#endif
#endif

typedef int __int32_t;
typedef unsigned  __uint32_t;

#if (_MIPS_SZLONG == 64)

typedef long __int64_t;
typedef unsigned long __uint64_t;

#else

#if defined(_LONGLONG)

typedef long long __int64_t;
typedef unsigned long long  __uint64_t;

#else

typedef struct {
        int hi32;
        int lo32;
} __int64_t;
typedef struct {
        unsigned int hi32;
        unsigned int lo32;
} __uint64_t;

#endif /* _LONGLONG */

#endif /* _MIPS_SZLONG */

#if (_MIPS_SZPTR == 32)
typedef __int32_t __psint_t;
typedef __uint32_t __psunsigned_t;
#endif

#if (_MIPS_SZPTR == 64)
typedef __int64_t __psint_t;
typedef __uint64_t __psunsigned_t;
#endif

/*
 * If any fundamental type is 64 bit, then set the scaling type
 * to 64 bit
 */
#if (_MIPS_SZPTR == 64) || (_MIPS_SZLONG == 64) || (_MIPS_SZINT == 64)

/* there exists some large fundamental type */
typedef __int64_t __scint_t;
typedef __uint64_t __scunsigned_t;

#else

/* a 32 bit world */
typedef __int32_t __scint_t;
typedef __uint32_t __scunsigned_t;

#endif 

#endif /* C || C++ */

#ifdef __cplusplus
}
#endif

#endif /* !__SGIDEFS_H__ */
