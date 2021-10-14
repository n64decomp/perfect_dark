#ifndef __SYS_U64DRIVER_H__
#define __SYS_U64DRIVER_H__

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

#include <PR/rdb.h>
#include <PR/ramrom.h>
#include "u64gio.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)


#define U64_MINOR_PRINT         1
#define U64_MINOR_DEBUG         2
#define U64_MINOR_LOGGING       3
#define U64_MINOR_DATA		4
#define U64_MINOR_FAULT         5
#define U64_MINOR_KDEBUG        6
#define U64_MINOR_PROFILE       7
#define NUMBER_MINORS           8   /* don't use minor zero , but must count 0-7 */

#define U64_MINOR_PRINT_BUF_SIZE         0x80000  /* buffer used by incoming printf data */
#define U64_MINOR_DEBUG_BUF_SIZE         0x4000
#define U64_MINOR_LOGGING_BUF_SIZE       RDB_LOG_MAX_BLOCK_SIZE  /* buffer used by incoming logging data */
#define U64_MINOR_DATA_BUF_SIZE          RDB_DATA_MAX_BLOCK_SIZE  /* buffer used by incoming data */
#define U64_MINOR_FAULT_BUF_SIZE         1024    /* buffer used for incoming fault data */
#define U64_MINOR_KDEBUG_BUF_SIZE        1024    /* buffer used for incoming kdebug data */
#define U64_MINOR_PROFILE_BUF_SIZE       2048    /* buffer used for incoming profile data */
#define U64_MINOR_PROFILE_SEND_BUF_SIZE  16      /* only send one byte messages */
#define U64_INTERNAL_WRITE_BUF_SIZE      0x8000  /* buffer used to store packets waiting to go out */



#define u64_increment_Qptr(x)	{ ((x) = ((x) + 1) & 0xff) ; }


typedef struct {
    sema_t           minor_sema;     /* used to allow only one app to open the minor */
    sema_t           read_sema;      /* used to block while waiting for data */
    sema_t           write_sema;     /* only allow one entry to write at a time */
    int              read_count;     /* the number of bytes waiting to be read */
    int              write_count;    /* the number of bytes waiting to be written */
    int              read_cur_write;
    int              write_cur_write;
    int              read_cur_read;
    int              write_cur_read;
    unsigned char    *read_buf;
    unsigned char    *write_buf;
    int              read_buf_size;  /* measured in unsigned char's */
    int              write_buf_size;  /* measured in unsigned char's */
    int              incoming_ct;    /* used by minors that receive data from game */
                                     /* indicates how many bytes left in block  */
                                     /* before signaling game that transfer is done */
                                     /* used by logging and game to host data stuff */
    int              message;        /* when not zero, send this message to game to */
                                     /* indicate that data or log data has been read */
    struct pollhead  *phead;
} u64_minor;

/*
 * Our private one-per-board data structure
 * The user can't get at any of this
 */
struct u64_data {

    volatile struct u64_board	*board;
    unsigned char		*memaddr;	/* 16/32 bit access R/W */

    /*
     * Only one client may be in the kernel at a time; this semaphore is used
     * to prevent multiple clients from overrunning each other's interactions
     * with the hardware.
     */
    sema_t			ioctl_sema;

    /*
     * The ramrom_sema is used by the driver so that it can arbitrate for the
     * control of ramrom with the game, and sleep while waiting for the game
     * to respond.
     */
    sema_t			ramrom_sema;

    /*
     * Allocate a megabyte buffer which we can use when reading/writing data
     * to or from the board (we can't copyin/copyout directly from the user's
     * buffer, because those routines use 64 bit transfers).
     */
    unsigned int		*oneMeg;

    union {
	u64_write_arg_t u64_write;	/* WRITE, SAFE_WRITE */
	u64_read_arg_t u64_read;	/* READ, SAFE_READ */
    }                           args;

    /* rdb port */
    unsigned int                *write_buf;
    unsigned int                write_buf_cur_write;
    unsigned int                write_buf_cur_read;
    unsigned int                write_buf_ct;    /* number of packets waiting for transmission */
    unsigned int                write_buf_size;  /* measured in rdbPackets */
    sema_t                      write_buf_sema;
    u64_minor                   minors[NUMBER_MINORS];

};

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#endif /* __SYS_U64DRIVER_H__ */






