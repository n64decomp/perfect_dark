#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

const char lower[] = "0123456789abcdefghijklmnopqrstuvwxyz";
const char upper[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *baseEncode(u64 value, char *buffer, u32 base, bool uppercase)
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

GLOBAL_ASM(
glabel base000138e0
/*    138e0:	afa40000 */ 	sw	$a0,0x0($sp)
/*    138e4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    138e8:	afa60008 */ 	sw	$a2,0x8($sp)
/*    138ec:	03e00008 */ 	jr	$ra
/*    138f0:	00001025 */ 	or	$v0,$zero,$zero
);
