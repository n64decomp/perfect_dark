#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "types.h"

GLOBAL_ASM(
glabel func0000bfb0
/*     bfb0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     bfb4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     bfb8:	0c003000 */ 	jal	rmonCreateThread
/*     bfbc:	00000000 */ 	nop
/*     bfc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     bfc4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     bfc8:	03e00008 */ 	jr	$ra
/*     bfcc:	00000000 */ 	nop
);

void func0000bfd0(char *arg0, char *arg1, s32 arg2)
{
	func0002faa4("ASSERTION : %s, %d: (\"%s\")\n", arg1, arg2, arg0);
}
