#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

const char lower[] = "0123456789abcdefghijklmnopqrstuvwxyz";
const char upper[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *base_encode(u64 value, char *buffer, u32 base, bool uppercase)
{
	const char *digits = uppercase ? upper : lower;
	char *ptr = buffer;

	while (value > 0) {
		ptr--;
		*ptr = digits[value % base];
		value /= base;
	}

	return ptr;
}

s32 base000138e0(u32 arg0, u32 arg1, u32 arg2)
{
	return 0;
}
