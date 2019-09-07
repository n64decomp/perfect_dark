#ifndef _ULTRA64_EEPROM_H_
#define _ULTRA64_EEPROM_H_

typedef struct
{
    u16 unk00;
    u16 unk01;
} OSEepromUnknownStruct0;

/* Functions */

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes);
s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes);
s32 osEepromWrite(OSMesgQueue *mq, u8 address, u8 *buffer);
s32 osEepromRead(OSMesgQueue *mq, u8 address, u8 *buffer);
s32 osEepromProbe(OSMesgQueue *mq);

#endif
