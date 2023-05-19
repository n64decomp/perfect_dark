#include "guint.h"

signed int coss(unsigned int x)
{
	return sins((unsigned int) (x + 0x4000));
}
