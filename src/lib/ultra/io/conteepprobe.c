#include <libultra_internal.h>
#include "data.h"

s32 osEepromProbe(OSMesgQueue *mq)
{
	s32 ret;
	u16 type;
	OSContStatus sdata;

	ret = 0;

	__osSiGetAccess();

	ret = __osEepStatus(mq, &sdata);
	type = sdata.type & (CONT_EEPROM | CONT_EEP16K);

	if (ret != 0) {
		ret = 0;
	} else {
		switch (type) {
		case CONT_EEPROM:
			ret = EEPROM_TYPE_4K;
			break;
		case CONT_EEPROM | CONT_EEP16K:
			ret = EEPROM_TYPE_16K;
			break;
		default:
			ret = 0;
			break;
		}
	}

	__osSiRelAccess();

	return ret;
}
