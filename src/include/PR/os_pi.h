#ifndef _ULTRA64_PI_H_
#define _ULTRA64_PI_H_

/* Ultra64 Parallel Interface */

/* Types */

typedef struct
{
    u32 errStatus;
    void *dramAddr;
    void *C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
} __OSBlockInfo;

typedef struct
{
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 devAddr;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    __OSBlockInfo block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_s
{
    struct OSPiHandle_s *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle;

typedef struct
{
    u8 type;
    u32 address;
} OSPiInfo;

typedef struct
{
    u16 type;
    u8 pri;
    u8 status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct
{
    /*0x00*/ OSIoMesgHdr hdr;
    /*0x08*/ void *dramAddr;
    /*0x0C*/ u32 devAddr;
    /*0x10*/ u32 size;
    OSPiHandle *piHandle; //from the official definition
} OSIoMesg;

typedef struct {
	s32             active;		/* Status flag */
	OSThread	*thread;	/* Calling thread */
	OSMesgQueue  	*cmdQueue;	/* Command queue */
	OSMesgQueue  	*evtQueue;	/* Event queue */
	OSMesgQueue  	*acsQueue;	/* Access queue */
	/* Raw DMA routine */
	s32             (*dma)(s32, u32, void *, u32);
	s32             (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;

/* Definitions */

#define OS_READ 0  // device -> RDRAM
#define OS_WRITE 1 // device <- RDRAM

#define OS_MESG_PRI_NORMAL 0
#define OS_MESG_PRI_HIGH 1

#define WAIT_ON_IOBUSY(stat)                                \
    stat = IO_READ(PI_STATUS_REG);                          \
    while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) \
        stat = IO_READ(PI_STATUS_REG);

#define UPDATE_REG(reg, var)           \
    if (cHandle->var != pihandle->var) \
        IO_WRITE(reg, pihandle->var);

#define LEO_BASE_REG 0x05000000

#define LEO_CMD (LEO_BASE_REG + 0x508)
#define LEO_STATUS (LEO_BASE_REG + 0x508)

#define LEO_BM_CTL (LEO_BASE_REG + 0x510)
#define LEO_BM_STATUS (LEO_BASE_REG + 0x510)

#define LEO_SEQ_CTL (LEO_BASE_REG + 0x518)
#define LEO_SEQ_STATUS (LEO_BASE_REG + 0x518)

#define LEO_C2_BUFF (LEO_BASE_REG + 0x000)      //C2 Sector Buffer
#define LEO_SECTOR_BUFF (LEO_BASE_REG + 0x400)  //Data Sector Buffer
#define LEO_DATA (LEO_BASE_REG + 0x500)         //Data
#define LEO_MISC_REG (LEO_BASE_REG + 0x504)     //Misc Register
#define LEO_CUR_TK (LEO_BASE_REG + 0x50C)       //Current Track
#define LEO_ERR_SECTOR (LEO_BASE_REG + 0x514)   //Sector Error Status
#define LEO_CUR_SECTOR (LEO_BASE_REG + 0x51C)   //Current Sector
#define LEO_HARD_RESET (LEO_BASE_REG + 0x520)   //Hard Reset
#define LEO_C1_S0 (LEO_BASE_REG + 0x524)        //C1
#define LEO_HOST_SECBYTE (LEO_BASE_REG + 0x528) //Sector Size (in bytes)
#define LEO_C1_S2 (LEO_BASE_REG + 0x52C)        //C1
#define LEO_SEC_BYTE (LEO_BASE_REG + 0x530)     //Sectors per Block, Full Size
#define LEO_C1_S4 (LEO_BASE_REG + 0x534)        //C1
#define LEO_C1_S6 (LEO_BASE_REG + 0x538)        //C1
#define LEO_CUR_ADDR (LEO_BASE_REG + 0x53C)     //Current Address?
#define LEO_ID_REG (LEO_BASE_REG + 0x540)       //ID
#define LEO_TEST_REG (LEO_BASE_REG + 0x544)     //Test Read
#define LEO_TEST_PIN_SEL (LEO_BASE_REG + 0x548) //Test Write
#define LEO_RAM_ADDR (LEO_BASE_REG + 0x580)     //Microsequencer RAM

#define LEO_STATUS_PRESENCE_MASK 0xFFFF

#define LEO_STATUS_DATA_REQUEST             0x40000000
#define LEO_STATUS_C2_TRANSFER              0x10000000
#define LEO_STATUS_BUFFER_MANAGER_ERROR     0x08000000
#define LEO_STATUS_BUFFER_MANAGER_INTERRUPT 0x04000000
#define LEO_STATUS_MECHANIC_INTERRUPT       0x02000000
#define LEO_STATUS_DISK_PRESENT             0x01000000
#define LEO_STATUS_BUSY_STATE               0x00800000
#define LEO_STATUS_RESET_STATE              0x00400000
#define LEO_STATUS_MOTOR_NOT_SPINNING       0x00100000
#define LEO_STATUS_HEAD_RETRACTED           0x00080000
#define LEO_STATUS_WRITE_PROTECT_ERROR      0x00040000
#define LEO_STATUS_MECHANIC_ERROR           0x00020000
#define LEO_STATUS_DISK_CHANGE              0x00010000

#define LEO_STATUS_MODE_MASK (LEO_STATUS_MOTOR_NOT_SPINNING | LEO_STATUS_HEAD_RETRACTED)
#define LEO_STATUS_MODE_SLEEP (LEO_STATUS_MOTOR_NOT_SPINNING | LEO_STATUS_HEAD_RETRACTED)
#define LEO_STATUS_MODE_STANDBY (LEO_STATUS_HEAD_RETRACTED)
#define LEO_STATUS_MODE_ACTIVE 0

#define LEO_CUR_TK_INDEX_LOCK 0x60000000

#define LEO_BM_STATUS_RUNNING      0x80000000
#define LEO_BM_STATUS_ERROR        0x04000000
#define LEO_BM_STATUS_MICRO        0x02000000
#define LEO_BM_STATUS_BLOCK        0x01000000
#define LEO_BM_STATUS_C1CORRECTION 0x00800000
#define LEO_BM_STATUS_C1DOUBLE     0x00400000
#define LEO_BM_STATUS_C1SINGLE     0x00200000
#define LEO_BM_STATUS_C1ERROR      0x00010000

#define LEO_BM_CTL_START             0x80000000
#define LEO_BM_CTL_MODE              0x40000000
#define LEO_BM_CTL_IMASK             0x20000000
#define LEO_BM_CTL_RESET             0x10000000
#define LEO_BM_CTL_DISABLE_OR        0x08000000
#define LEO_BM_CTL_DISABLE_C1        0x04000000
#define LEO_BM_CTL_BLOCK             0x02000000
#define LEO_BM_CTL_CLR_MECHANIC_INTR 0x01000000

#define LEO_BM_CTL_CONTROL_MASK 0xFF000000
#define LEO_BM_CTL_SECTOR_MASK  0x00FF0000
#define LEO_BM_CTL_SECTOR_SHIFT 16

#define LEO_CMD_TYPE_0 0
#define LEO_CMD_TYPE_1 1
#define LEO_CMD_TYPE_2 2

#define LEO_ERROR_GOOD 0
#define LEO_ERROR_4    4
#define LEO_ERROR_22   22
#define LEO_ERROR_23   23
#define LEO_ERROR_24   24
#define LEO_ERROR_29   29

/* Functions */

s32 osPiStartDma(OSIoMesg *mb, s32 priority, s32 direction,
                 u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *mq);
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf,
                       s32 cmdMsgCnt);
OSMesgQueue *osPiGetCmdQueue(void);
s32 osPiWriteIo(u32 devAddr, u32 data);
s32 osPiReadIo(u32 devAddr, u32 *data);
s32 osPiRawStartDma(s32 direction, u32 devAddr, void *dramAddr, u32 size);
s32 osEPiRawStartDma(OSPiHandle *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size);
void __osDevMgrMain(void *args);


#endif
