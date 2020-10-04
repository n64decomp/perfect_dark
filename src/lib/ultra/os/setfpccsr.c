#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osSetFpcCsr
/*    481e0:	4442f800 */ 	cfc1	$v0,$31
/*    481e4:	44c4f800 */ 	ctc1	$a0,$31
/*    481e8:	03e00008 */ 	jr	$ra
/*    481ec:	00000000 */ 	nop
);
