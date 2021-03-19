#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osSyncPutChars
/*     4100:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     4104:	93a30034 */ 	lbu	$v1,0x34($sp)
/*     4108:	0004c080 */ 	sll	$t8,$a0,0x2
/*     410c:	30aa0003 */ 	andi	$t2,$a1,0x3
/*     4110:	3079ff03 */ 	andi	$t9,$v1,0xff03
/*     4114:	03194025 */ 	or	$t0,$t8,$t9
/*     4118:	310bfffc */ 	andi	$t3,$t0,0xfffc
/*     411c:	014b6025 */ 	or	$t4,$t2,$t3
/*     4120:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     4124:	afb00018 */ 	sw	$s0,0x18($sp)
/*     4128:	a3ac0034 */ 	sb	$t4,0x34($sp)
/*     412c:	18a00009 */ 	blez	$a1,.NB00004154
/*     4130:	00001025 */ 	or	$v0,$zero,$zero
/*     4134:	27a30034 */ 	addiu	$v1,$sp,0x34
/*     4138:	00c02025 */ 	or	$a0,$a2,$zero
.NB0000413c:
/*     413c:	908d0000 */ 	lbu	$t5,0x0($a0)
/*     4140:	24420001 */ 	addiu	$v0,$v0,0x1
/*     4144:	24630001 */ 	addiu	$v1,$v1,0x1
/*     4148:	24840001 */ 	addiu	$a0,$a0,0x1
/*     414c:	1445fffb */ 	bne	$v0,$a1,.NB0000413c
/*     4150:	a06d0000 */ 	sb	$t5,0x0($v1)
.NB00004154:
/*     4154:	3c108006 */ 	lui	$s0,0x8006
/*     4158:	2610e6e4 */ 	addiu	$s0,$s0,-6428
/*     415c:	0c012dcc */ 	jal	0x4b730
/*     4160:	02002025 */ 	or	$a0,$s0,$zero
/*     4164:	14400005 */ 	bnez	$v0,.NB0000417c
/*     4168:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000416c:
/*     416c:	0c012dcc */ 	jal	0x4b730
/*     4170:	02002025 */ 	or	$a0,$s0,$zero
/*     4174:	1040fffd */ 	beqz	$v0,.NB0000416c
/*     4178:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000417c:
/*     417c:	0c012a60 */ 	jal	0x4a980
/*     4180:	00000000 */ 	sll	$zero,$zero,0x0
/*     4184:	afa2002c */ 	sw	$v0,0x2c($sp)
/*     4188:	27ae0034 */ 	addiu	$t6,$sp,0x34
/*     418c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*     4190:	3c18c000 */ 	lui	$t8,0xc000
/*     4194:	0c012de4 */ 	jal	0x4b790
/*     4198:	af0f0000 */ 	sw	$t7,0x0($t8)
/*     419c:	30592000 */ 	andi	$t9,$v0,0x2000
/*     41a0:	57200007 */ 	bnezl	$t9,.NB000041c0
/*     41a4:	3c09c000 */ 	lui	$t1,0xc000
.NB000041a8:
/*     41a8:	0c012de4 */ 	jal	0x4b790
/*     41ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     41b0:	30482000 */ 	andi	$t0,$v0,0x2000
/*     41b4:	1100fffc */ 	beqz	$t0,.NB000041a8
/*     41b8:	00000000 */ 	sll	$zero,$zero,0x0
/*     41bc:	3c09c000 */ 	lui	$t1,0xc000
.NB000041c0:
/*     41c0:	ad20000c */ 	sw	$zero,0xc($t1)
/*     41c4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*     41c8:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*     41cc:	254b0001 */ 	addiu	$t3,$t2,0x1
/*     41d0:	0c012a7c */ 	jal	0x4a9f0
/*     41d4:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*     41d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     41dc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     41e0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*     41e4:	03e00008 */ 	jr	$ra
/*     41e8:	00000000 */ 	sll	$zero,$zero,0x0
);
