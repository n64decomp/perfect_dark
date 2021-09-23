#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4e090.h"
#include "lib/lib_52360.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel osGbpakReadWrite
/*    513b0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    513b4:	afb10020 */ 	sw	$s1,0x20($sp)
/*    513b8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    513bc:	afb50030 */ 	sw	$s5,0x30($sp)
/*    513c0:	afb4002c */ 	sw	$s4,0x2c($sp)
/*    513c4:	afb30028 */ 	sw	$s3,0x28($sp)
/*    513c8:	afb20024 */ 	sw	$s2,0x24($sp)
/*    513cc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*    513d0:	afa50044 */ 	sw	$a1,0x44($sp)
/*    513d4:	afa60048 */ 	sw	$a2,0x48($sp)
/*    513d8:	908e0064 */ 	lbu	$t6,0x64($a0)
/*    513dc:	30d1ffff */ 	andi	$s1,$a2,0xffff
/*    513e0:	00111383 */ 	sra	$v0,$s1,0xe
/*    513e4:	305500ff */ 	andi	$s5,$v0,0xff
/*    513e8:	00809025 */ 	or	$s2,$a0,$zero
/*    513ec:	00e0a025 */ 	or	$s4,$a3,$zero
/*    513f0:	11d50007 */ 	beq	$t6,$s5,.L00051410
/*    513f4:	305300ff */ 	andi	$s3,$v0,0xff
/*    513f8:	0c0148d8 */ 	jal	func00052360
/*    513fc:	32a500ff */ 	andi	$a1,$s5,0xff
/*    51400:	10400003 */ 	beqz	$v0,.L00051410
/*    51404:	afa20038 */ 	sw	$v0,0x38($sp)
/*    51408:	10000051 */ 	b	.L00051550
/*    5140c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L00051410:
/*    51410:	97a20052 */ 	lhu	$v0,0x52($sp)
/*    51414:	97a90046 */ 	lhu	$t1,0x46($sp)
/*    51418:	3630c000 */ 	ori	$s0,$s1,0xc000
/*    5141c:	00027943 */ 	sra	$t7,$v0,0x5
/*    51420:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    51424:	0010c943 */ 	sra	$t9,$s0,0x5
/*    51428:	24010001 */ 	addiu	$at,$zero,0x1
/*    5142c:	8fa30038 */ 	lw	$v1,0x38($sp)
/*    51430:	03001025 */ 	or	$v0,$t8,$zero
/*    51434:	15210022 */ 	bne	$t1,$at,.L000514c0
/*    51438:	3330ffff */ 	andi	$s0,$t9,0xffff
/*    5143c:	00008825 */ 	or	$s1,$zero,$zero
/*    51440:	1b00003d */ 	blez	$t8,.L00051538
/*    51444:	0300a825 */ 	or	$s5,$t8,$zero
.L00051448:
/*    51448:	8e440004 */ 	lw	$a0,0x4($s2)
/*    5144c:	8e450008 */ 	lw	$a1,0x8($s2)
/*    51450:	afa00010 */ 	sw	$zero,0x10($sp)
/*    51454:	3206ffff */ 	andi	$a2,$s0,0xffff
/*    51458:	0c012d84 */ 	jal	__osContRamWrite
/*    5145c:	02803825 */ 	or	$a3,$s4,$zero
/*    51460:	14400035 */ 	bnez	$v0,.L00051538
/*    51464:	00401825 */ 	or	$v1,$v0,$zero
/*    51468:	26100001 */ 	addiu	$s0,$s0,0x1
/*    5146c:	320affff */ 	andi	$t2,$s0,0xffff
/*    51470:	29410800 */ 	slti	$at,$t2,0x800
/*    51474:	1420000d */ 	bnez	$at,.L000514ac
/*    51478:	01408025 */ 	or	$s0,$t2,$zero
/*    5147c:	26abffff */ 	addiu	$t3,$s5,-1
/*    51480:	022b082a */ 	slt	$at,$s1,$t3
/*    51484:	10200009 */ 	beqz	$at,.L000514ac
/*    51488:	02402025 */ 	or	$a0,$s2,$zero
/*    5148c:	26730001 */ 	addiu	$s3,$s3,0x1
/*    51490:	326c00ff */ 	andi	$t4,$s3,0xff
/*    51494:	01809825 */ 	or	$s3,$t4,$zero
/*    51498:	0c0148d8 */ 	jal	func00052360
/*    5149c:	318500ff */ 	andi	$a1,$t4,0xff
/*    514a0:	14400025 */ 	bnez	$v0,.L00051538
/*    514a4:	00401825 */ 	or	$v1,$v0,$zero
/*    514a8:	24100600 */ 	addiu	$s0,$zero,0x600
.L000514ac:
/*    514ac:	26310001 */ 	addiu	$s1,$s1,0x1
/*    514b0:	1635ffe5 */ 	bne	$s1,$s5,.L00051448
/*    514b4:	26940020 */ 	addiu	$s4,$s4,0x20
/*    514b8:	10000020 */ 	b	.L0005153c
/*    514bc:	24010002 */ 	addiu	$at,$zero,0x2
.L000514c0:
/*    514c0:	00008825 */ 	or	$s1,$zero,$zero
/*    514c4:	1840001c */ 	blez	$v0,.L00051538
/*    514c8:	0040a825 */ 	or	$s5,$v0,$zero
.L000514cc:
/*    514cc:	8e440004 */ 	lw	$a0,0x4($s2)
/*    514d0:	8e450008 */ 	lw	$a1,0x8($s2)
/*    514d4:	3206ffff */ 	andi	$a2,$s0,0xffff
/*    514d8:	0c012e18 */ 	jal	__osContRamRead
/*    514dc:	02803825 */ 	or	$a3,$s4,$zero
/*    514e0:	14400015 */ 	bnez	$v0,.L00051538
/*    514e4:	00401825 */ 	or	$v1,$v0,$zero
/*    514e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*    514ec:	320dffff */ 	andi	$t5,$s0,0xffff
/*    514f0:	29a10800 */ 	slti	$at,$t5,0x800
/*    514f4:	1420000d */ 	bnez	$at,.L0005152c
/*    514f8:	01a08025 */ 	or	$s0,$t5,$zero
/*    514fc:	26aeffff */ 	addiu	$t6,$s5,-1
/*    51500:	022e082a */ 	slt	$at,$s1,$t6
/*    51504:	10200009 */ 	beqz	$at,.L0005152c
/*    51508:	02402025 */ 	or	$a0,$s2,$zero
/*    5150c:	26730001 */ 	addiu	$s3,$s3,0x1
/*    51510:	326f00ff */ 	andi	$t7,$s3,0xff
/*    51514:	01e09825 */ 	or	$s3,$t7,$zero
/*    51518:	0c0148d8 */ 	jal	func00052360
/*    5151c:	31e500ff */ 	andi	$a1,$t7,0xff
/*    51520:	14400005 */ 	bnez	$v0,.L00051538
/*    51524:	00401825 */ 	or	$v1,$v0,$zero
/*    51528:	24100600 */ 	addiu	$s0,$zero,0x600
.L0005152c:
/*    5152c:	26310001 */ 	addiu	$s1,$s1,0x1
/*    51530:	1635ffe6 */ 	bne	$s1,$s5,.L000514cc
/*    51534:	26940020 */ 	addiu	$s4,$s4,0x20
.L00051538:
/*    51538:	24010002 */ 	addiu	$at,$zero,0x2
.L0005153c:
/*    5153c:	54610003 */ 	bnel	$v1,$at,.L0005154c
/*    51540:	00601025 */ 	or	$v0,$v1,$zero
/*    51544:	24030004 */ 	addiu	$v1,$zero,0x4
/*    51548:	00601025 */ 	or	$v0,$v1,$zero
.L0005154c:
/*    5154c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L00051550:
/*    51550:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*    51554:	8fb10020 */ 	lw	$s1,0x20($sp)
/*    51558:	8fb20024 */ 	lw	$s2,0x24($sp)
/*    5155c:	8fb30028 */ 	lw	$s3,0x28($sp)
/*    51560:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*    51564:	8fb50030 */ 	lw	$s5,0x30($sp)
/*    51568:	03e00008 */ 	jr	$ra
/*    5156c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
