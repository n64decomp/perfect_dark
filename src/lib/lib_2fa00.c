#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_0c000.h"
#include "lib/libc/xprintf.h"
#include "data.h"
#include "types.h"

void rmonproc()
{
	// empty
}

bool rmonIsDisabled(void)
{
	return true;
}

s32 func0002fa10(void)
{
	return -1;
}

void func0002fa18(void)
{
	// empty
}

void func0002fa20(void)
{
	// empty
}

void func0002fa28(void)
{
	// empty
}

void func0002fa30(void)
{
	// empty
}

void func0002fa38(void)
{
	// empty
}

void func0002fa40(void)
{
	// empty
}

char *func0002fa48(char *dst, const char *src, size_t count);

GLOBAL_ASM(
glabel func0002fa48
/*    2fa48:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    2fa4c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    2fa50:	afb00018 */ 	sw	$s0,0x18($sp)
/*    2fa54:	00c09025 */ 	or	$s2,$a2,$zero
/*    2fa58:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    2fa5c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    2fa60:	afa40028 */ 	sw	$a0,0x28($sp)
/*    2fa64:	10c00008 */ 	beqz	$a2,.L0002fa88
/*    2fa68:	00008025 */ 	or	$s0,$zero,$zero
/*    2fa6c:	00a08825 */ 	or	$s1,$a1,$zero
/*    2fa70:	92240000 */ 	lbu	$a0,0x0($s1)
.L0002fa74:
/*    2fa74:	26100001 */ 	addiu	$s0,$s0,0x1
/*    2fa78:	0c00330d */ 	jal	crashAppendChar
/*    2fa7c:	26310001 */ 	addiu	$s1,$s1,0x1
/*    2fa80:	5612fffc */ 	bnel	$s0,$s2,.L0002fa74
/*    2fa84:	92240000 */ 	lbu	$a0,0x0($s1)
.L0002fa88:
/*    2fa88:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    2fa8c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    2fa90:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    2fa94:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    2fa98:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    2fa9c:	03e00008 */ 	jr	$ra
/*    2faa0:	24020001 */ 	addiu	$v0,$zero,0x1
);

void crashPrint(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	_Printf(func0002fa48, NULL, format, ap);
}
