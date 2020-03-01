#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004b170
/*    4b170:	10c0001a */ 	beqz	$a2,.L0004b1dc
/*    4b174:	00a03825 */ 	or	$a3,$a1,$zero
/*    4b178:	10850018 */ 	beq	$a0,$a1,.L0004b1dc
/*    4b17c:	00a4082a */ 	slt	$at,$a1,$a0
/*    4b180:	54200008 */ 	bnezl	$at,.L0004b1a4
/*    4b184:	28c10010 */ 	slti	$at,$a2,0x10
/*    4b188:	00861020 */ 	add	$v0,$a0,$a2
/*    4b18c:	00a2082a */ 	slt	$at,$a1,$v0
/*    4b190:	50200004 */ 	beqzl	$at,.L0004b1a4
/*    4b194:	28c10010 */ 	slti	$at,$a2,0x10
/*    4b198:	1000005b */ 	beqz	$zero,.L0004b308
/*    4b19c:	28c10010 */ 	slti	$at,$a2,0x10
/*    4b1a0:	28c10010 */ 	slti	$at,$a2,0x10
.L0004b1a4:
/*    4b1a4:	14200005 */ 	bnez	$at,.L0004b1bc
/*    4b1a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b1ac:	30820003 */ 	andi	$v0,$a0,0x3
/*    4b1b0:	30a30003 */ 	andi	$v1,$a1,0x3
/*    4b1b4:	1043000b */ 	beq	$v0,$v1,.L0004b1e4
/*    4b1b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0004b1bc:
/*    4b1bc:	10c00007 */ 	beqz	$a2,.L0004b1dc
/*    4b1c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b1c4:	00861821 */ 	addu	$v1,$a0,$a2
.L0004b1c8:
/*    4b1c8:	80820000 */ 	lb	$v0,0x0($a0)
/*    4b1cc:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4b1d0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4b1d4:	1483fffc */ 	bne	$a0,$v1,.L0004b1c8
/*    4b1d8:	a0a2ffff */ 	sb	$v0,-0x1($a1)
.L0004b1dc:
/*    4b1dc:	03e00008 */ 	jr	$ra
/*    4b1e0:	00e01025 */ 	or	$v0,$a3,$zero
.L0004b1e4:
/*    4b1e4:	10400018 */ 	beqz	$v0,.L0004b248
/*    4b1e8:	24010001 */ 	addiu	$at,$zero,0x1
/*    4b1ec:	1041000f */ 	beq	$v0,$at,.L0004b22c
/*    4b1f0:	24010002 */ 	addiu	$at,$zero,0x2
/*    4b1f4:	50410008 */ 	beql	$v0,$at,.L0004b218
/*    4b1f8:	84820000 */ 	lh	$v0,0x0($a0)
/*    4b1fc:	80820000 */ 	lb	$v0,0x0($a0)
/*    4b200:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4b204:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4b208:	24c6ffff */ 	addiu	$a2,$a2,-1
/*    4b20c:	1000000e */ 	beqz	$zero,.L0004b248
/*    4b210:	a0a2ffff */ 	sb	$v0,-0x1($a1)
/*    4b214:	84820000 */ 	lh	$v0,0x0($a0)
.L0004b218:
/*    4b218:	24840002 */ 	addiu	$a0,$a0,0x2
/*    4b21c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*    4b220:	24c6fffe */ 	addiu	$a2,$a2,-2
/*    4b224:	10000008 */ 	beqz	$zero,.L0004b248
/*    4b228:	a4a2fffe */ 	sh	$v0,-0x2($a1)
.L0004b22c:
/*    4b22c:	80820000 */ 	lb	$v0,0x0($a0)
/*    4b230:	84830001 */ 	lh	$v1,0x1($a0)
/*    4b234:	24840003 */ 	addiu	$a0,$a0,0x3
/*    4b238:	24a50003 */ 	addiu	$a1,$a1,0x3
/*    4b23c:	24c6fffd */ 	addiu	$a2,$a2,-3
/*    4b240:	a0a2fffd */ 	sb	$v0,-0x3($a1)
/*    4b244:	a4a3fffe */ 	sh	$v1,-0x2($a1)
.L0004b248:
/*    4b248:	28c10020 */ 	slti	$at,$a2,0x20
/*    4b24c:	54200016 */ 	bnezl	$at,.L0004b2a8
/*    4b250:	28c10010 */ 	slti	$at,$a2,0x10
/*    4b254:	8c820000 */ 	lw	$v0,0x0($a0)
/*    4b258:	8c830004 */ 	lw	$v1,0x4($a0)
/*    4b25c:	8c880008 */ 	lw	$t0,0x8($a0)
/*    4b260:	8c89000c */ 	lw	$t1,0xc($a0)
/*    4b264:	8c8a0010 */ 	lw	$t2,0x10($a0)
/*    4b268:	8c8b0014 */ 	lw	$t3,0x14($a0)
/*    4b26c:	8c8c0018 */ 	lw	$t4,0x18($a0)
/*    4b270:	8c8d001c */ 	lw	$t5,0x1c($a0)
/*    4b274:	24840020 */ 	addiu	$a0,$a0,0x20
/*    4b278:	24a50020 */ 	addiu	$a1,$a1,0x20
/*    4b27c:	24c6ffe0 */ 	addiu	$a2,$a2,-32
/*    4b280:	aca2ffe0 */ 	sw	$v0,-0x20($a1)
/*    4b284:	aca3ffe4 */ 	sw	$v1,-0x1c($a1)
/*    4b288:	aca8ffe8 */ 	sw	$t0,-0x18($a1)
/*    4b28c:	aca9ffec */ 	sw	$t1,-0x14($a1)
/*    4b290:	acaafff0 */ 	sw	$t2,-0x10($a1)
/*    4b294:	acabfff4 */ 	sw	$t3,-0xc($a1)
/*    4b298:	acacfff8 */ 	sw	$t4,-0x8($a1)
/*    4b29c:	1000ffea */ 	beqz	$zero,.L0004b248
/*    4b2a0:	acadfffc */ 	sw	$t5,-0x4($a1)
.L0004b2a4:
/*    4b2a4:	28c10010 */ 	slti	$at,$a2,0x10
.L0004b2a8:
/*    4b2a8:	5420000e */ 	bnezl	$at,.L0004b2e4
/*    4b2ac:	28c10004 */ 	slti	$at,$a2,0x4
/*    4b2b0:	8c820000 */ 	lw	$v0,0x0($a0)
/*    4b2b4:	8c830004 */ 	lw	$v1,0x4($a0)
/*    4b2b8:	8c880008 */ 	lw	$t0,0x8($a0)
/*    4b2bc:	8c89000c */ 	lw	$t1,0xc($a0)
/*    4b2c0:	24840010 */ 	addiu	$a0,$a0,0x10
/*    4b2c4:	24a50010 */ 	addiu	$a1,$a1,0x10
/*    4b2c8:	24c6fff0 */ 	addiu	$a2,$a2,-16
/*    4b2cc:	aca2fff0 */ 	sw	$v0,-0x10($a1)
/*    4b2d0:	aca3fff4 */ 	sw	$v1,-0xc($a1)
/*    4b2d4:	aca8fff8 */ 	sw	$t0,-0x8($a1)
/*    4b2d8:	1000fff2 */ 	beqz	$zero,.L0004b2a4
/*    4b2dc:	aca9fffc */ 	sw	$t1,-0x4($a1)
.L0004b2e0:
/*    4b2e0:	28c10004 */ 	slti	$at,$a2,0x4
.L0004b2e4:
/*    4b2e4:	1420ffb5 */ 	bnez	$at,.L0004b1bc
/*    4b2e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b2ec:	8c820000 */ 	lw	$v0,0x0($a0)
/*    4b2f0:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4b2f4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    4b2f8:	24c6fffc */ 	addiu	$a2,$a2,-4
/*    4b2fc:	1000fff8 */ 	beqz	$zero,.L0004b2e0
/*    4b300:	aca2fffc */ 	sw	$v0,-0x4($a1)
/*    4b304:	28c10010 */ 	slti	$at,$a2,0x10
.L0004b308:
/*    4b308:	00862020 */ 	add	$a0,$a0,$a2
/*    4b30c:	14200005 */ 	bnez	$at,.L0004b324
/*    4b310:	00a62820 */ 	add	$a1,$a1,$a2
/*    4b314:	30820003 */ 	andi	$v0,$a0,0x3
/*    4b318:	30a30003 */ 	andi	$v1,$a1,0x3
/*    4b31c:	1043000d */ 	beq	$v0,$v1,.L0004b354
/*    4b320:	00000000 */ 	sll	$zero,$zero,0x0
.L0004b324:
/*    4b324:	10c0ffad */ 	beqz	$a2,.L0004b1dc
/*    4b328:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b32c:	2484ffff */ 	addiu	$a0,$a0,-1
/*    4b330:	24a5ffff */ 	addiu	$a1,$a1,-1
/*    4b334:	00861823 */ 	subu	$v1,$a0,$a2
.L0004b338:
/*    4b338:	80820000 */ 	lb	$v0,0x0($a0)
/*    4b33c:	2484ffff */ 	addiu	$a0,$a0,-1
/*    4b340:	24a5ffff */ 	addiu	$a1,$a1,-1
/*    4b344:	1483fffc */ 	bne	$a0,$v1,.L0004b338
/*    4b348:	a0a20001 */ 	sb	$v0,0x1($a1)
/*    4b34c:	03e00008 */ 	jr	$ra
/*    4b350:	00e01025 */ 	or	$v0,$a3,$zero
.L0004b354:
/*    4b354:	10400018 */ 	beqz	$v0,.L0004b3b8
/*    4b358:	24010003 */ 	addiu	$at,$zero,0x3
/*    4b35c:	1041000f */ 	beq	$v0,$at,.L0004b39c
/*    4b360:	24010002 */ 	addiu	$at,$zero,0x2
/*    4b364:	50410008 */ 	beql	$v0,$at,.L0004b388
/*    4b368:	8482fffe */ 	lh	$v0,-0x2($a0)
/*    4b36c:	8082ffff */ 	lb	$v0,-0x1($a0)
/*    4b370:	2484ffff */ 	addiu	$a0,$a0,-1
/*    4b374:	24a5ffff */ 	addiu	$a1,$a1,-1
/*    4b378:	24c6ffff */ 	addiu	$a2,$a2,-1
/*    4b37c:	1000000e */ 	beqz	$zero,.L0004b3b8
/*    4b380:	a0a20000 */ 	sb	$v0,0x0($a1)
/*    4b384:	8482fffe */ 	lh	$v0,-0x2($a0)
.L0004b388:
/*    4b388:	2484fffe */ 	addiu	$a0,$a0,-2
/*    4b38c:	24a5fffe */ 	addiu	$a1,$a1,-2
/*    4b390:	24c6fffe */ 	addiu	$a2,$a2,-2
/*    4b394:	10000008 */ 	beqz	$zero,.L0004b3b8
/*    4b398:	a4a20000 */ 	sh	$v0,0x0($a1)
.L0004b39c:
/*    4b39c:	8082ffff */ 	lb	$v0,-0x1($a0)
/*    4b3a0:	8483fffd */ 	lh	$v1,-0x3($a0)
/*    4b3a4:	2484fffd */ 	addiu	$a0,$a0,-3
/*    4b3a8:	24a5fffd */ 	addiu	$a1,$a1,-3
/*    4b3ac:	24c6fffd */ 	addiu	$a2,$a2,-3
/*    4b3b0:	a0a20002 */ 	sb	$v0,0x2($a1)
/*    4b3b4:	a4a30000 */ 	sh	$v1,0x0($a1)
.L0004b3b8:
/*    4b3b8:	28c10020 */ 	slti	$at,$a2,0x20
/*    4b3bc:	54200016 */ 	bnezl	$at,.L0004b418
/*    4b3c0:	28c10010 */ 	slti	$at,$a2,0x10
/*    4b3c4:	8c82fffc */ 	lw	$v0,-0x4($a0)
/*    4b3c8:	8c83fff8 */ 	lw	$v1,-0x8($a0)
/*    4b3cc:	8c88fff4 */ 	lw	$t0,-0xc($a0)
/*    4b3d0:	8c89fff0 */ 	lw	$t1,-0x10($a0)
/*    4b3d4:	8c8affec */ 	lw	$t2,-0x14($a0)
/*    4b3d8:	8c8bffe8 */ 	lw	$t3,-0x18($a0)
/*    4b3dc:	8c8cffe4 */ 	lw	$t4,-0x1c($a0)
/*    4b3e0:	8c8dffe0 */ 	lw	$t5,-0x20($a0)
/*    4b3e4:	2484ffe0 */ 	addiu	$a0,$a0,-32
/*    4b3e8:	24a5ffe0 */ 	addiu	$a1,$a1,-32
/*    4b3ec:	24c6ffe0 */ 	addiu	$a2,$a2,-32
/*    4b3f0:	aca2001c */ 	sw	$v0,0x1c($a1)
/*    4b3f4:	aca30018 */ 	sw	$v1,0x18($a1)
/*    4b3f8:	aca80014 */ 	sw	$t0,0x14($a1)
/*    4b3fc:	aca90010 */ 	sw	$t1,0x10($a1)
/*    4b400:	acaa000c */ 	sw	$t2,0xc($a1)
/*    4b404:	acab0008 */ 	sw	$t3,0x8($a1)
/*    4b408:	acac0004 */ 	sw	$t4,0x4($a1)
/*    4b40c:	1000ffea */ 	beqz	$zero,.L0004b3b8
/*    4b410:	acad0000 */ 	sw	$t5,0x0($a1)
.L0004b414:
/*    4b414:	28c10010 */ 	slti	$at,$a2,0x10
.L0004b418:
/*    4b418:	5420000e */ 	bnezl	$at,.L0004b454
/*    4b41c:	28c10004 */ 	slti	$at,$a2,0x4
/*    4b420:	8c82fffc */ 	lw	$v0,-0x4($a0)
/*    4b424:	8c83fff8 */ 	lw	$v1,-0x8($a0)
/*    4b428:	8c88fff4 */ 	lw	$t0,-0xc($a0)
/*    4b42c:	8c89fff0 */ 	lw	$t1,-0x10($a0)
/*    4b430:	2484fff0 */ 	addiu	$a0,$a0,-16
/*    4b434:	24a5fff0 */ 	addiu	$a1,$a1,-16
/*    4b438:	24c6fff0 */ 	addiu	$a2,$a2,-16
/*    4b43c:	aca2000c */ 	sw	$v0,0xc($a1)
/*    4b440:	aca30008 */ 	sw	$v1,0x8($a1)
/*    4b444:	aca80004 */ 	sw	$t0,0x4($a1)
/*    4b448:	1000fff2 */ 	beqz	$zero,.L0004b414
/*    4b44c:	aca90000 */ 	sw	$t1,0x0($a1)
.L0004b450:
/*    4b450:	28c10004 */ 	slti	$at,$a2,0x4
.L0004b454:
/*    4b454:	1420ffb3 */ 	bnez	$at,.L0004b324
/*    4b458:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b45c:	8c82fffc */ 	lw	$v0,-0x4($a0)
/*    4b460:	2484fffc */ 	addiu	$a0,$a0,-4
/*    4b464:	24a5fffc */ 	addiu	$a1,$a1,-4
/*    4b468:	24c6fffc */ 	addiu	$a2,$a2,-4
/*    4b46c:	1000fff8 */ 	beqz	$zero,.L0004b450
/*    4b470:	aca20000 */ 	sw	$v0,0x0($a1)
/*    4b474:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b478:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b47c:	00000000 */ 	sll	$zero,$zero,0x0
);