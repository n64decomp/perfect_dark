#ifndef _ULTRA64_TLB_H_
#define _ULTRA64_TLB_H_

/* Types */

typedef u32 OSPageMask;
/* OSPageMask Valid Values */
#define OS_PM_4K   0x0000000
#define OS_PM_16K  0x0006000
#define OS_PM_64K  0x001e000
#define OS_PM_256K 0x007e000
#define OS_PM_1M   0x01fe000
#define OS_PM_4M   0x07fe000
#define OS_PM_16M  0x1ffe000

/* Functions */

void osMapTLB(s32 index, OSPageMask pm, void *vaddr, u32 evenpaddr, 
    u32 oddpaddr, s32 asid);
void osMapTLBRdb(void);
void osUnmapTLB(s32 index);
void osUnmapTLBAll(void);
void osSetTLBASID(s32 asid);

#endif
