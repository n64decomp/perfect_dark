
/*====================================================================
 * os_cont.h
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

        $RCSfile: os_cont.h,v $
        $Revision: 1.1 $
        $Date: 1998/10/09 08:01:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_CONT_H_
#define	_OS_CONT_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for controllers
 */

typedef struct {
	u16     type;                   /* Controller Type */
	u8      status;                 /* Controller status */
	u8	errno;
}OSContStatus;

typedef struct {
	u16     button;
	s8      stick_x;		/* -80 <= stick_x <= 80 */
	s8      stick_y;		/* -80 <= stick_y <= 80 */
	u8	errno;
} OSContPad;

typedef struct {
	void    *address;               /* Ram pad Address:  11 bits */
	u8      databuffer[32];         /* address of the data buffer */
        u8      addressCrc;             /* CRC code for address */
	u8      dataCrc;                /* CRC code for data */
	u8	errno;
} OSContRamIo;

typedef struct
{
    /* 0x0 */ u32 ramarray[15];
    /* 0x3C */ u32 pifstatus;
} OSPifRam;

typedef struct
{
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u16 button;
    /* 0x6 */ s8 stick_x;
    /* 0x7 */ s8 stick_y;
} __OSContReadFormat;

typedef struct
{
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u8 typeh;
    /* 0x5 */ u8 typel;
    /* 0x6 */ u8 status;
    /* 0x7 */ u8 dummy1;
} __OSContRequestFormat;

typedef struct
{
    /* 0x0 */ u8 txsize;
    /* 0x1 */ u8 rxsize;
    /* 0x2 */ u8 cmd;
    /* 0x3 */ u8 typeh;
    /* 0x4 */ u8 typel;
    /* 0x5 */ u8 status;
} __OSContRequestFormatShort;

typedef struct
{
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u8 hi;
    /* 0x4 */ u8 lo;
    /* 0x6 */ u8 data[BLOCKSIZE];
    /* 0x26 */ u8 datacrc;
} __OSContRamReadFormat;

typedef union {
    /* 0x0 */ struct
    {
        /* 0x0 */ u8 bank;
        /* 0x1 */ u8 page;
    } inode_t;
    /* 0x0 */ u16 ipage;
} __OSInodeUnit;

typedef struct
{
    /* 0x0 */ u32 game_code;
    /* 0x4 */ u16 company_code;
    /* 0x6 */ __OSInodeUnit start_page;
    /* 0x8 */ u8 status;
    /* 0x9 */ s8 reserved;
    /* 0xA */ u16 data_sum;
    /* 0xC */ u8 ext_name[16];
    /* 0x10 */ u8 game_name[4];
} __OSDir;

typedef struct
{
    /* 0x0 */ __OSInodeUnit inode_page[128];
} __OSInode;

typedef struct
{
    /* 0x0 */ u32 repaired;
    /* 0x4 */ u32 random;
    /* 0x8 */ u64 serial_mid;
    /* 0x10 */ u64 serial_low;
    /* 0x18 */ u16 deviceid;
    /* 0x1A */ u8 banks;
    /* 0x1B */ u8 version;
    /* 0x1C */ u16 checksum;
    /* 0x1E */ u16 inverted_checksum;
} __OSPackId;

typedef struct
{
    /* 0x0 */ u8 txsize;
    /* 0x1 */ u8 rxsize;
    /* 0x2 */ u8 cmd;
    /* 0x3 */ u8 address;
    /* 0x4 */ u8 data[EEPROM_BLOCK_SIZE];
} __OSContEepromFormat;

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 *  Controllers  number
 */

#ifndef _HW_VERSION_1
#define MAXCONTROLLERS  4
#else
#define MAXCONTROLLERS  6
#endif

/* controller errors */
#define CONT_NO_RESPONSE_ERROR          0x8
#define CONT_OVERRUN_ERROR              0x4
#ifdef _HW_VERSION_1
#define CONT_FRAME_ERROR                0x2
#define CONT_COLLISION_ERROR            0x1
#endif

/* Controller type */

#define CONT_ABSOLUTE           0x0001
#define CONT_RELATIVE           0x0002
#define CONT_JOYPORT            0x0004
#define CONT_EEPROM		0x8000
#define CONT_EEP16K		0x4000
#define	CONT_TYPE_MASK		0x1f07
#define	CONT_TYPE_NORMAL	0x0005
#define	CONT_TYPE_MOUSE		0x0002
#define	CONT_TYPE_VOICE		0x0100

/* Controller status */

#define CONT_CARD_ON            0x01
#define CONT_CARD_PULL          0x02
#define CONT_ADDR_CRC_ER        0x04
#define CONT_EEPROM_BUSY	0x80

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D

/* Controller error number */

#define	CONT_ERR_NO_CONTROLLER		PFS_ERR_NOPACK 		/* 1 */
#define	CONT_ERR_CONTRFAIL		CONT_OVERRUN_ERROR	/* 4 */
#define	CONT_ERR_INVALID		PFS_ERR_INVALID		/* 5 */
#define	CONT_ERR_DEVICE			PFS_ERR_DEVICE 		/* 11 */
#define	CONT_ERR_NOT_READY		12
#define	CONT_ERR_VOICE_MEMORY		13
#define	CONT_ERR_VOICE_WORD		14
#define	CONT_ERR_VOICE_NO_RESPONSE	15

#define CONT_CMD_REQUEST_STATUS 0
#define CONT_CMD_READ_BUTTON    1
#define CONT_CMD_READ_MEMPACK   2
#define CONT_CMD_WRITE_MEMPACK  3
#define CONT_CMD_READ_EEPROM    4
#define CONT_CMD_WRITE_EEPROM   5
#define CONT_CMD_RESET          0xff

#define CONT_CMD_REQUEST_STATUS_TX 1
#define CONT_CMD_READ_BUTTON_TX    1
#define CONT_CMD_READ_MEMPACK_TX   3
#define CONT_CMD_WRITE_MEMPACK_TX  35
#define CONT_CMD_READ_EEPROM_TX    2
#define CONT_CMD_WRITE_EEPROM_TX   10
#define CONT_CMD_RESET_TX          1

#define CONT_CMD_REQUEST_STATUS_RX 3
#define CONT_CMD_READ_BUTTON_RX    4
#define CONT_CMD_READ_MEMPACK_RX   33
#define CONT_CMD_WRITE_MEMPACK_RX  1
#define CONT_CMD_READ_EEPROM_RX    8
#define CONT_CMD_WRITE_EEPROM_RX   1
#define CONT_CMD_RESET_RX          3

#define CONT_CMD_NOP 0xff
#define CONT_CMD_END 0xfe //indicates end of a command
#define CONT_CMD_EXE 1    //set pif ram status byte to this to do a command

#define DIR_STATUS_EMPTY    0
#define DIR_STATUS_UNKNOWN  1
#define DIR_STATUS_OCCUPIED 2

#define CHNL_ERR(format) ((format.rxsize & CHNL_ERR_MASK) >> 4)

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


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

/* Controller interface */

extern s32		osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32		osContReset(OSMesgQueue *, OSContStatus *);
extern s32		osContStartQuery(OSMesgQueue *);
extern s32		osContStartReadData(OSMesgQueue *);
#ifndef _HW_VERSION_1
extern s32		osContSetCh(u8);
#endif
extern void		osContGetQuery(OSContStatus *);
extern void		osContGetReadData(OSContPad *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_CONT_H_ */
