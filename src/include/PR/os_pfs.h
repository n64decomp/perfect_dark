
/*====================================================================
 * os_pfs.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)

        $RCSfile: os_pfs.h,v $
        $Revision: 1.1 $
        $Date: 1998/10/09 08:01:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_PFS_H_
#define	_OS_PFS_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


/**************************************************************************
 *
 * Type definitions
 *
 */

typedef struct {
	int		status;
	OSMesgQueue 	*queue;
	int		channel;
	u8		id[32];
	u8		label[32];
	int		version;
	int		dir_size;
	int		inode_table;		/* block location */
	int		minode_table;		/* mirrioring inode_table */
	int		dir_table;		/* block location */
	int		inode_start_page;	/* page # */
	u8		banks;
	u8		activebank;
} OSPfs;

typedef struct {
	u32	file_size;	/* bytes */
  	u32 	game_code;
  	u16 	company_code;
  	char  	ext_name[4];
  	char 	game_name[16];
} OSPfsState;

/**************************************************************************
 *
 * Global definitions
 *
 */

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

#define PFS_ERR_NOPACK       1  /* no memory card is plugged */
#define PFS_ERR_NEW_PACK     2  /* ram pack has been changed to a different one */
#define PFS_ERR_INCONSISTENT 3  /* need to run Pfschecker */
#define PFS_ERR_CONTRFAIL    4
#define PFS_ERR_INVALID      5  /* invalid parameter or file not exist */
#define PFS_ERR_BAD_DATA     6  /* the data read from pack are bad */
#define PFS_DATA_FULL        7  /* no free pages on ram pack */
#define PFS_DIR_FULL         8  /* no free directories on ram pack */
#define PFS_ERR_EXIST        9  /* file exists */
#define PFS_ERR_ID_FATAL     10 /* dead ram pack */
#define PFS_ERR_DEVICE       11 /* wrong device type */

#define	OS_PFS_VERSION		0x0200
#define	OS_PFS_VERSION_HI	(OS_PFS_VERSION >> 8)
#define	OS_PFS_VERSION_LO	(OS_PFS_VERSION & 255)

#define PFS_FILE_NAME_LEN       16
#define PFS_FILE_EXT_LEN        4
#define BLOCKSIZE		32		/* bytes */
#define PFS_ONE_PAGE            8		/* blocks */
#define PFS_MAX_BANKS		62

#define PFS_READ                0
#define PFS_WRITE               1
#define PFS_CREATE              2

#define PFS_INITIALIZED		0x1
#define PFS_CORRUPTED		0x2

/**************************************************************************
 *
 * Macro definitions
 *
 */

#define SET_ACTIVEBANK_TO_ZERO        \
    if (pfs->activebank != 0)         \
    {                                 \
        pfs->activebank = 0;          \
        ERRCK(__osPfsSelectBank(pfs)) \
    }

#define PFS_CHECK_ID                              \
    if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) \
        return PFS_ERR_NEW_PACK;

#define PFS_CHECK_STATUS                          \
    if ((pfs->status & PFS_INITIALIZED) == 0) \
        return PFS_ERR_INVALID;

#define PFS_GET_STATUS                      \
    __osSiGetAccess();                      \
    ret = __osPfsGetStatus(queue, channel); \
    __osSiRelAccess();                      \
    if (ret != 0)                           \
        return ret;

/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

extern s32		osPfsIsPlug(OSMesgQueue *, u8 *);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_PFS_H_ */
