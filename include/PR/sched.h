/*====================================================================
 * sched.h
 *
 * Synopsis:
 *
 * Copyright 1993, Silicon Graphics, Inc.
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

/**************************************************************************
 *
 *  $Revision: 1.7 $
 *  $Date: 1997/02/11 08:32:02 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/sched.h,v $
 *
 **************************************************************************/

#ifndef __sched__
#define __sched__

#include <ultra64.h>

#define OS_SC_STACKSIZE      0x2000

#define OS_SC_RETRACE_MSG       1
#define OS_SC_DONE_MSG          2
#define OS_SC_RDP_DONE_MSG      3
#define OS_SC_RSP_MSG           4  // custom - tells audiomgr it's time to do an audio frame
#define OS_SC_PRE_NMI_MSG       5
#define OS_SC_QUIT_MSG          10
#define OS_SC_LAST_MSG          10	/* this should have highest number */

#define OS_SC_MAX_MESGS         8

typedef struct {
    short type;
    char  misc[30];
} OSScMsg;

typedef struct OSScTask_s {
    struct OSScTask_s   *next;          /* note: this must be first */
    u32                 state;
    u32			flags;
    void		*framebuffer;	/* used by graphics tasks */

    OSTask              list;
    OSMesgQueue         *msgQ;
    OSMesg              msg;
} OSScTask;

/*
 * OSScTask flags:
 */
#define OS_SC_NEEDS_RDP	        0x0001	/* uses the RDP */
#define OS_SC_NEEDS_RSP	        0x0002  /* uses the RSP */
#define OS_SC_DRAM_DLIST        0x0004  /* SP & DP communicate through DRAM */
#define OS_SC_PARALLEL_TASK     0x0010	/* must be first gfx task on list */
#define OS_SC_LAST_TASK	        0x0020	/* last task in queue for frame */
#define OS_SC_SWAPBUFFER        0x0040	/* swapbuffers when gfx task done */

#define OS_SC_RCP_MASK		0x0003	/* mask for needs bits */
#define OS_SC_TYPE_MASK		0x0007	/* complete type mask */
/*
 * OSScClient:
 *
 * Data structure used by threads that wish to communicate to the
 * scheduling thread
 *
 */
typedef struct SCClient_s {
    struct SCClient_s   *next;  /* next client in the list      */
    OSMesgQueue         *msgQ;  /* where to send the frame msg  */
    s32                 is8mb;
} OSScClient;

typedef struct {
    OSScMsg     retraceMsg;
    OSScMsg     prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg      intBuf[OS_SC_MAX_MESGS];
    OSThread    *thread;
    OSScTask    *nextAudTask;
    OSScTask    *nextGfxTask;
    OSScTask    *nextGfxTask2;
    OSScTask    *curRSPTask;
    OSScTask    *curRDPTask;
    u32         frameCount;
    u32         alt;
    OSMesgQueue *audmq;
    OSMesgQueue *gfxmq;
    void        *scheduledFB;
    void        *queuedFB;
} OSSched;

void            osCreateScheduler(OSSched *s, OSThread *thread, u8 mode, u32 numFields);
void            osScAddClient(OSSched *s, OSScClient *c, OSMesgQueue *msgQ, int is8mb);
void            osScRemoveClient(OSSched *s, OSScClient *c);
OSMesgQueue     *osScGetCmdQ(OSSched *s);

#endif

