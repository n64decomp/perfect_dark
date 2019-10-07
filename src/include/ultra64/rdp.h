#ifndef _ULTRA64_RDP_H_
#define _ULTRA64_RDP_H_

/* DP Command Registers */

#define DPC_REG_BASE 0xA4100000

#define DPC_START_REG    (*(vu32 *)(DPC_REG_BASE + 0x00))
#define DPC_END_REG      (*(vu32 *)(DPC_REG_BASE + 0x04))
#define DPC_CURRENT_REG  (*(vu32 *)(DPC_REG_BASE + 0x08))
#define DPC_STATUS_REG   (*(vu32 *)(DPC_REG_BASE + 0x0C))
#define DPC_CLOCK_REG    (*(vu32 *)(DPC_REG_BASE + 0x10))
#define DPC_BUFBUSY_REG  (*(vu32 *)(DPC_REG_BASE + 0x14))
#define DPC_PIPEBUSY_REG (*(vu32 *)(DPC_REG_BASE + 0x18))
#define DPC_TMEM_REG     (*(vu32 *)(DPC_REG_BASE + 0x1C))


/* DP Span Registers */

#define DPS_REG_BASE 0xA4200000

#define DPS_TBIST_REG        (*(vu32 *)(DPS_REG_BASE + 0x00))
#define DPS_TEST_MODE_REG    (*(vu32 *)(DPS_REG_BASE + 0x04))
#define DPS_BUFTEST_ADDR_REG (*(vu32 *)(DPS_REG_BASE + 0x08))
#define DPS_BUFTEST_DATA_REG (*(vu32 *)(DPS_REG_BASE + 0x0C))


/* Functions */

u32 osDpGetStatus(void);
void osDpSetStatus(u32 status);

#endif
