#include <ultra64.h>
#include "data.h"

__OSViContext *__osViGetCurrentContext(void)
{
	return __osViCurr;
}
