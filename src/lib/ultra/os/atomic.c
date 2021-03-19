#include <libultra_internal.h>
#include "data.h"

int __osAtomicDec(unsigned int *p)
{
	u32 mask;
	int result;

	mask = __osDisableInt();

	if (*p) {
		(*p)--;
		result = 1;
	} else {
		result = 0;
	}

	__osRestoreInt(mask);

	return result;
}
