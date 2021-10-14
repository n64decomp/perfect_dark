/*
 * Copyright (c) 1995, Silicon Graphics, Inc.  All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior written
 * permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
 * and Computer Software clause at DFARS 252.227-7013, and/or in similar or
 * successor clauses in the FAR, DOD or NASA FAR Supplement.  Unpublished
 * rights reserved under the Copyright Laws of the United States.
 *
 * Module: tinymon.h: constants for use with the tinymon family of debug servers
 */

#define GIO_BASE_REG_UPPER	0x1800
#define GIO_BASE_REG_UPPER_K1	0xb800
#define	GIO_INTR_REG_OFFSET	0x0
#define	GIO_SYNC_REG_OFFSET	0x400
#define	CART_INTR_REG_OFFSET	0x800

#define RAMROM_BASE_UPPER	0x1000
#define RAMROM_BASE_UPPER_K1	0xb000

/*
 * jal will or in the upper four bits of 0xb0000000 whenever we invoke these
 * routines.
 */
#define PIFMON_WRITE_ADDR	0xfc00030

#define PI_BASE_REG_UPPER	0x0460
#define PI_BASE_REG_UPPER_K1	0xa460
#define PI_STATUS_REG_OFFSET	0x10

/*
 * PI status register has 3 bits active when read from (PI_STATUS_REG - read)
 *	Bit 0: DMA busy - set when DMA is in progress
 *	Bit 1: IO busy  - set when IO is in progress
 *	Bit 2: Error    - set when R4300 issues IO request while DMA is busy
 */
#define	PI_STATUS_ERROR		0x04
#define	PI_STATUS_IO_BUSY	0x02
#define	PI_STATUS_DMA_BUSY	0x01

/*
 * Host to R4300 protocol definitions. 
 *
 *    Host writes DG_RAMROM_REQUEST, DG_RAMROM_CMD_READY to the cartridge 
 *    interrupt register (which the R4300 can poll),
 *
 *    R4300 writes DG_RAMROM_GRANT, DG_RAMROM_CMD_DONE to the gio sync register
 *    (which the host can poll).
 */

#define DG_CARTREG_MASK		0x3f

#define DG_RAMROM_REQUEST	1
#define DG_RAMROM_GRANT		2
#define DG_RAMROM_CMD_READY	3
#define DG_RAMROM_CMD_DONE	4

#define DG_TINYMON_READ_OP	1
#define DG_TINYMON_WRITE_OP	2
#define DG_TINYMON_DMA_READ_OP	3
#define DG_TINYMON_DMA_WRITE_OP	4
