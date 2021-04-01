#ifndef _ULTRA64_SCHED_H_
#define _ULTRA64_SCHED_H_
#include <ultra64.h>

#define OS_SC_STACKSIZE      0x2000

#define OS_SC_RETRACE_MSG       1
#define OS_SC_DONE_MSG          2
#define OS_SC_RDP_DONE_MSG      3
#define OS_SC_PRE_NMI_MSG       4
#define OS_SC_LAST_MSG          4	/* this should have highest number */
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

#define OS_SC_DP                0x0001  /* set if still needs dp        */
#define OS_SC_SP                0x0002  /* set if still needs sp        */
#define OS_SC_YIELD             0x0010  /* set if yield requested       */
#define OS_SC_YIELDED           0x0020  /* set if yield completed       */

/*
 * OSScTask->flags type identifier
 */
#define OS_SC_XBUS      (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM      (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS   (OS_SC_SP)
#define OS_SC_DP_DRAM   (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS   (OS_SC_DP)
#define OS_SC_SP_DRAM   (OS_SC_DP | OS_SC_DRAM_DLIST)

/*
 * private typedefs and defines
 */
#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669

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
} OSScClient;

typedef struct {
    OSScMsg     retraceMsg;
    OSScMsg     prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg      intBuf[OS_SC_MAX_MESGS];
    OSMesgQueue cmdQ;
    OSMesg      cmdMsgBuf[OS_SC_MAX_MESGS];
    OSThread    *thread;
    OSScClient  *clientList;
    OSScTask    *audioListHead;
    OSScTask    *gfxListHead;
    OSScTask    *audioListTail;
    OSScTask    *gfxListTail;
    OSScTask    *curRSPTask;
    OSScTask    *curRDPTask;
    u32         frameCount;
    s32         doAudio;
} OSSched;

void            osCreateScheduler(OSSched *s, void *stack, u8 mode, u32 numFields);
void            osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, OSScClient *next);
void            osScRemoveClient(OSSched *s, OSScClient *c);
OSMesgQueue     *osScGetCmdQ(OSSched *s);

#endif

