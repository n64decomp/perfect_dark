#ifndef __SYS_U64GIO_H__
#define __SYS_U64GIO_H__

/*
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
 * the contents of this file may not be disclosed to third parties, copied or
 * duplicated in any form, in whole or in part, without the prior written
 * permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
 * and Computer Software clause at DFARS 252.227-7013, and/or in similar or
 * successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
 * rights reserved under the Copyright Laws of the United States.
 *
 */

#define DEV_U64	"/dev/u64"
#define DEV_U64_PRINT "/dev/u64_print"
#define DEV_U64_DEBUG "/dev/u64_debug"
#define DEV_U64_LOG "/dev/u64_logging"
#define DEV_U64_DATA "/dev/u64_data"
#define DEV_U64_FAULT "/dev/u64_fault"
#define DEV_U64_KDEBUG "/dev/u64_kdebug"
#define DEV_U64_PROFILE "/dev/u64_profile"
/*
 * ioctls
 */
#define U64IOC		('u'<<24|'6'<<16)
#define U64IOCTL(x)	(U64IOC|x)

#define U64_RESET	U64IOCTL(1)	/* arg: 0 - deassert, 1 - assert */
#define U64_WRITE	U64IOCTL(2)
#define U64_READ	U64IOCTL(3)
#define U64_SAFE_WRITE	U64IOCTL(4)
#define U64_SAFE_READ	U64IOCTL(5)
#define U64_LISTEN	U64IOCTL(6)	/* arg is register value for listen */
#define	U64_SIGNAL	U64IOCTL(7)	/* arg is register value for signal */

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* structure for WRITE  & SAFE_WRITE*/
typedef struct u64_write_arg {
    void *buffer;
    long ramrom_addr;
    int nbytes;
} u64_write_arg_t;

/* structure for READ & SAFE_READ */
typedef struct u64_read_arg {
    void *buffer;
    long ramrom_addr;
    int nbytes;
} u64_read_arg_t;

/* NOTE: if game is in reset, don't interrupt the game */

struct u64_board {
    volatile unsigned int	product_id_reg;	/* bf400000, read only */
    unsigned char 			fill_0[0x3fc];
    volatile unsigned int	reset_control;	/* bf400400, write only */
    unsigned char 			fill_1[0x3fc];
    volatile unsigned int	cart_interrupt;	/* bf400800, read/write */
    unsigned char 			fill_3[0x1fc];
    volatile unsigned int	dram_page_cntrl;/* bf400a00, read/write */
    unsigned char 			fill_2[0x1fc]; 
    volatile unsigned int	gio_interrupt;	/* bf400c00, read only */ 
    unsigned char 			fill_4[0x1fc]; 
    volatile unsigned int	gio_sync;	/* bf400e00, read only */
};

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/* 
 * _U64_PRODUCT_ID_REG - GIO bus Product ID register 
 */
#define	_U64_PRODUCT_ID_MASK		0x0000007f
#define	_U64_PRODUCT_ID_VALUE		0x00000015

/*
 * reset control register has two bits defined
 */
#define _U64_RESET_CONTROL_NMI		0x4
#define _U64_RESET_CONTROL_RESET	0x2

/*
 * Only look at the least significant 5 bits of the sync and interrupt
 * registers.  Future revs of the firmware may provide more.
 */

#define _U64_REGMASK			0x1f

/*
 * 16MB available, one meg at a time, selected by the 4 bit 
 * dram_page_cntrl register setting.
 */
#define U64_MEM_SIZE			0x100000

/*
 * Declare size of gio-addressable memory to mmap, and provide the base
 * physical address so that clients who want to mmap() may do so.
 */
#define U64_GIOBUS_SIZE	0x200000	/* 2 MB */
#define U64_GIOBUS_BASE 0x1f400000

#endif /* __SYS_U64GIO_H__ */
