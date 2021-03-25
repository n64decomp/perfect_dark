#include <libultra_internal.h>
#include "data.h"

s32 osEPiRawWriteIo(OSPiHandle *handle, u32 devAddr, u32 data)
{
	u32 stat = IO_READ(PI_STATUS_REG);

    while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {
        stat = IO_READ(PI_STATUS_REG);
	}

    if (__osCurrentHandle[handle->domain]->type != handle->type) {
        OSPiHandle *cHandle = __osCurrentHandle[handle->domain];

        if (handle->domain == PI_DOMAIN1) {
			if (cHandle->latency != handle->latency) {
				IO_WRITE(PI_BSD_DOM1_LAT_REG, handle->latency);
			}

			if (cHandle->pageSize != handle->pageSize) {
				IO_WRITE(PI_BSD_DOM1_PGS_REG, handle->pageSize);
			}

			if (cHandle->relDuration != handle->relDuration) {
				IO_WRITE(PI_BSD_DOM1_RLS_REG, handle->relDuration);
			}

			if (cHandle->pulse != handle->pulse) {
				IO_WRITE(PI_BSD_DOM1_PWD_REG, handle->pulse);
			}
        } else {
			if (cHandle->latency != handle->latency) {
				IO_WRITE(PI_BSD_DOM2_LAT_REG, handle->latency);
			}

			if (cHandle->pageSize != handle->pageSize) {
				IO_WRITE(PI_BSD_DOM2_PGS_REG, handle->pageSize);
			}

			if (cHandle->relDuration != handle->relDuration) {
				IO_WRITE(PI_BSD_DOM2_RLS_REG, handle->relDuration);
			}

			if (cHandle->pulse != handle->pulse) {
				IO_WRITE(PI_BSD_DOM2_PWD_REG, handle->pulse);
			}
        }

		cHandle->type = handle->type;
		cHandle->latency = handle->latency;
		cHandle->pageSize = handle->pageSize;
		cHandle->relDuration = handle->relDuration;
		cHandle->pulse = handle->pulse;
	}

	IO_WRITE(handle->baseAddress | devAddr, data);
	return 0;
}
