#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "library/library.h"

const u32 var7f1a78d0[] = {0x3dcccccd};
const u32 var7f1a78d4[] = {0x3e4ccccd};
const u32 var7f1a78d8[] = {0x00000000};
const u32 var7f1a78dc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f000870
/*  f000870:	03e00008 */ 	jr	$ra
/*  f000874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f000878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00087c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f000880
/*  f000880:	3c017f1a */ 	lui	$at,%hi(var7f1a78d0)
/*  f000884:	c42078d0 */ 	lwc1	$f0,%lo(var7f1a78d0)($at)
/*  f000888:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00088c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f000890:	3c04800a */ 	lui	$a0,%hi(var800a3448)
/*  f000894:	44050000 */ 	mfc1	$a1,$f0
/*  f000898:	44060000 */ 	mfc1	$a2,$f0
/*  f00089c:	44070000 */ 	mfc1	$a3,$f0
/*  f0008a0:	0c014039 */ 	jal	func000500e4
/*  f0008a4:	24843448 */ 	addiu	$a0,$a0,%lo(var800a3448)
/*  f0008a8:	3c017f1a */ 	lui	$at,%hi(var7f1a78d4)
/*  f0008ac:	c42078d4 */ 	lwc1	$f0,%lo(var7f1a78d4)($at)
/*  f0008b0:	3c04800a */ 	lui	$a0,%hi(var800a3488)
/*  f0008b4:	24843488 */ 	addiu	$a0,$a0,%lo(var800a3488)
/*  f0008b8:	44050000 */ 	mfc1	$a1,$f0
/*  f0008bc:	44060000 */ 	mfc1	$a2,$f0
/*  f0008c0:	44070000 */ 	mfc1	$a3,$f0
/*  f0008c4:	0c014039 */ 	jal	func000500e4
/*  f0008c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0008cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0008d0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0008d4:	03e00008 */ 	jr	$ra
/*  f0008d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0008dc:	00000000 */ 	sll	$zero,$zero,0x0
);
