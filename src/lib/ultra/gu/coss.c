#include "guint.h"

signed short coss(unsigned short x)
{
	return sins((unsigned short) (x + 0x4000));
}
