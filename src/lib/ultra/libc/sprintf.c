#include <ultra64.h>

char *proutSprintf(char *dst, const char *src, size_t count)
{
    return (char *)memcpy((u8 *)dst, (u8 *)src, count) + count;
}

GLOBAL_ASM(
glabel sprintf
/*    136b4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    136b8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    136bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    136c0:	afa50024 */ 	sw	$a1,0x24($sp)
/*    136c4:	afa60028 */ 	sw	$a2,0x28($sp)
/*    136c8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    136cc:	3c047001 */ 	lui	$a0,%hi(proutSprintf)
/*    136d0:	24843690 */ 	addiu	$a0,$a0,%lo(proutSprintf)
/*    136d4:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    136d8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    136dc:	0c013b40 */ 	jal	_Printf
/*    136e0:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    136e4:	04400004 */ 	bltz	$v0,.L000136f8
/*    136e8:	00401825 */ 	or	$v1,$v0,$zero
/*    136ec:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    136f0:	01c27821 */ 	addu	$t7,$t6,$v0
/*    136f4:	a1e00000 */ 	sb	$zero,0x0($t7)
.L000136f8:
/*    136f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    136fc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    13700:	03e00008 */ 	jr	$ra
/*    13704:	00000000 */ 	nop
/*    13708:	00000000 */ 	nop
/*    1370c:	00000000 */ 	nop
);

// Mismatch:
// Goal takes v0 from _Printf and copies it to v1 but leaves v0 unmodified.
// The below copies v0 to v1 then back to v0 for the return.
//int sprintf(char *dst, const char *fmt, ...)
//{
//	int ans;
//	va_list ap;
//
//	va_start(ap, fmt);
//	ans = _Printf(proutSprintf, dst, fmt, ap);
//
//	if (ans >= 0) {
//		dst[ans] = 0;
//	}
//
//	return ans;
//}
