#include <ultra64.h>

GLOBAL_ASM(
glabel memcpy
/*    4a5e0:	00801025 */ 	or	$v0,$a0,$zero
/*    4a5e4:	10c00007 */ 	beqz	$a2,.L0004a604
/*    4a5e8:	00a01825 */ 	or	$v1,$a1,$zero
.L0004a5ec:
/*    4a5ec:	906e0000 */ 	lbu	$t6,0x0($v1)
/*    4a5f0:	24c6ffff */ 	addiu	$a2,$a2,-1
/*    4a5f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4a5f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4a5fc:	14c0fffb */ 	bnez	$a2,.L0004a5ec
/*    4a600:	a04effff */ 	sb	$t6,-0x1($v0)
.L0004a604:
/*    4a604:	03e00008 */ 	jr	$ra
/*    4a608:	00801025 */ 	or	$v0,$a0,$zero
);

size_t strlen(const char *s)
{
	const char *sc = s;

	while (*sc) {
		sc++;
	}

	return sc - s;
}

char *strchr(const char *s, int c)
{
	const char ch = c;

	while (*s != ch) {
		if (*s == 0) {
			return NULL;
		}

		s++;
	}

	return (char *)s;
}
