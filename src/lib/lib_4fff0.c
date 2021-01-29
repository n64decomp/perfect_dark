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
#include "types.h"

GLOBAL_ASM(
glabel func0004fff0
/*    4fff0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4fff4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4fff8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4fffc:	afa60020 */ 	sw	$a2,0x20($sp)
/*    50000:	afa70024 */ 	sw	$a3,0x24($sp)
/*    50004:	0c012918 */ 	jal	guMtxIdentF
/*    50008:	afa40018 */ 	sw	$a0,0x18($sp)
/*    5000c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    50010:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*    50014:	e4840030 */ 	swc1	$f4,0x30($a0)
/*    50018:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    5001c:	e4860034 */ 	swc1	$f6,0x34($a0)
/*    50020:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    50024:	e4880038 */ 	swc1	$f8,0x38($a0)
/*    50028:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    5002c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    50030:	03e00008 */ 	jr	$ra
/*    50034:	00000000 */ 	nop
/*    50038:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    5003c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    50040:	afa40068 */ 	sw	$a0,0x68($sp)
/*    50044:	afa5006c */ 	sw	$a1,0x6c($sp)
/*    50048:	afa60070 */ 	sw	$a2,0x70($sp)
/*    5004c:	afa70074 */ 	sw	$a3,0x74($sp)
/*    50050:	0c012918 */ 	jal	guMtxIdentF
/*    50054:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    50058:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*    5005c:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    50060:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*    50064:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    50068:	8fa50068 */ 	lw	$a1,0x68($sp)
/*    5006c:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*    50070:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*    50074:	0c0128d8 */ 	jal	guMtxF2L
/*    50078:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*    5007c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50080:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    50084:	03e00008 */ 	jr	$ra
/*    50088:	00000000 */ 	nop
/*    5008c:	00000000 */ 	nop
);