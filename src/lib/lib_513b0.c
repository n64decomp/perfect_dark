#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_4a810.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4b5e0.h"
#include "lib/lib_4ba90.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4cde0.h"
#include "lib/lib_4d6f0.h"
#include "lib/lib_513b0.h"
#include "lib/lib_52360.h"
#include "types.h"

GLOBAL_ASM(
glabel func000513b0
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
/*    51408:	10000051 */ 	beqz	$zero,.L00051550
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
/*    514b8:	10000020 */ 	beqz	$zero,.L0005153c
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
/*    51570:	27bdff90 */ 	addiu	$sp,$sp,-112
/*    51574:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    51578:	afb00018 */ 	sw	$s0,0x18($sp)
/*    5157c:	00a08025 */ 	or	$s0,$a1,$zero
/*    51580:	afa40070 */ 	sw	$a0,0x70($sp)
/*    51584:	0c012a18 */ 	jal	__osSiGetAccess
/*    51588:	afa60078 */ 	sw	$a2,0x78($sp)
/*    5158c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*    51590:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    51594:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    51598:	0c012a29 */ 	jal	__osSiRelAccess
/*    5159c:	afa2006c */ 	sw	$v0,0x6c($sp)
/*    515a0:	8fa3006c */ 	lw	$v1,0x6c($sp)
/*    515a4:	8fae0070 */ 	lw	$t6,0x70($sp)
/*    515a8:	02002025 */ 	or	$a0,$s0,$zero
/*    515ac:	50600004 */ 	beqzl	$v1,.L000515c0
/*    515b0:	ae0e0004 */ 	sw	$t6,0x4($s0)
/*    515b4:	1000006b */ 	beqz	$zero,.L00051764
/*    515b8:	00601025 */ 	or	$v0,$v1,$zero
/*    515bc:	ae0e0004 */ 	sw	$t6,0x4($s0)
.L000515c0:
/*    515c0:	8faf0078 */ 	lw	$t7,0x78($sp)
/*    515c4:	ae000000 */ 	sw	$zero,0x0($s0)
/*    515c8:	0c0145de */ 	jal	func00051778
/*    515cc:	ae0f0008 */ 	sw	$t7,0x8($s0)
/*    515d0:	10400003 */ 	beqz	$v0,.L000515e0
/*    515d4:	02002025 */ 	or	$a0,$s0,$zero
/*    515d8:	10000063 */ 	beqz	$zero,.L00051768
/*    515dc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L000515e0:
/*    515e0:	0c013378 */ 	jal	func0004cde0
/*    515e4:	00002825 */ 	or	$a1,$zero,$zero
/*    515e8:	10400003 */ 	beqz	$v0,.L000515f8
/*    515ec:	24060001 */ 	addiu	$a2,$zero,0x1
/*    515f0:	1000005d */ 	beqz	$zero,.L00051768
/*    515f4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L000515f8:
/*    515f8:	8e040004 */ 	lw	$a0,0x4($s0)
/*    515fc:	8e050008 */ 	lw	$a1,0x8($s0)
/*    51600:	0c012e18 */ 	jal	__osContRamRead
/*    51604:	27a70048 */ 	addiu	$a3,$sp,0x48
/*    51608:	10400003 */ 	beqz	$v0,.L00051618
/*    5160c:	27a40048 */ 	addiu	$a0,$sp,0x48
/*    51610:	10000055 */ 	beqz	$zero,.L00051768
/*    51614:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00051618:
/*    51618:	27a5006a */ 	addiu	$a1,$sp,0x6a
/*    5161c:	0c013041 */ 	jal	func0004c104
/*    51620:	27a60068 */ 	addiu	$a2,$sp,0x68
/*    51624:	97b8006a */ 	lhu	$t8,0x6a($sp)
/*    51628:	97b90064 */ 	lhu	$t9,0x64($sp)
/*    5162c:	27a50048 */ 	addiu	$a1,$sp,0x48
/*    51630:	afa50044 */ 	sw	$a1,0x44($sp)
/*    51634:	17190004 */ 	bne	$t8,$t9,.L00051648
/*    51638:	97a90068 */ 	lhu	$t1,0x68($sp)
/*    5163c:	97aa0066 */ 	lhu	$t2,0x66($sp)
/*    51640:	512a000a */ 	beql	$t1,$t2,.L0005166c
/*    51644:	97ad0060 */ 	lhu	$t5,0x60($sp)
.L00051648:
/*    51648:	0c013154 */ 	jal	func0004c550
/*    5164c:	02002025 */ 	or	$a0,$s0,$zero
/*    51650:	50400006 */ 	beqzl	$v0,.L0005166c
/*    51654:	97ad0060 */ 	lhu	$t5,0x60($sp)
/*    51658:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*    5165c:	356c0004 */ 	ori	$t4,$t3,0x4
/*    51660:	10000040 */ 	beqz	$zero,.L00051764
/*    51664:	ae0c0000 */ 	sw	$t4,0x0($s0)
/*    51668:	97ad0060 */ 	lhu	$t5,0x60($sp)
.L0005166c:
/*    5166c:	27a50048 */ 	addiu	$a1,$sp,0x48
/*    51670:	02002025 */ 	or	$a0,$s0,$zero
/*    51674:	31ae0001 */ 	andi	$t6,$t5,0x1
/*    51678:	55c00016 */ 	bnezl	$t6,.L000516d4
/*    5167c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    51680:	0c013080 */ 	jal	func0004c200
/*    51684:	27a60020 */ 	addiu	$a2,$sp,0x20
/*    51688:	10400009 */ 	beqz	$v0,.L000516b0
/*    5168c:	00401825 */ 	or	$v1,$v0,$zero
/*    51690:	2401000a */ 	addiu	$at,$zero,0xa
/*    51694:	14410004 */ 	bne	$v0,$at,.L000516a8
/*    51698:	00000000 */ 	sll	$zero,$zero,0x0
/*    5169c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*    516a0:	35f80004 */ 	ori	$t8,$t7,0x4
/*    516a4:	ae180000 */ 	sw	$t8,0x0($s0)
.L000516a8:
/*    516a8:	1000002e */ 	beqz	$zero,.L00051764
/*    516ac:	00601025 */ 	or	$v0,$v1,$zero
.L000516b0:
/*    516b0:	97a90038 */ 	lhu	$t1,0x38($sp)
/*    516b4:	27b90020 */ 	addiu	$t9,$sp,0x20
/*    516b8:	afb90044 */ 	sw	$t9,0x44($sp)
/*    516bc:	312a0001 */ 	andi	$t2,$t1,0x1
/*    516c0:	55400004 */ 	bnezl	$t2,.L000516d4
/*    516c4:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    516c8:	10000026 */ 	beqz	$zero,.L00051764
/*    516cc:	2402000b */ 	addiu	$v0,$zero,0xb
/*    516d0:	8fa40044 */ 	lw	$a0,0x44($sp)
.L000516d4:
/*    516d4:	2605000c */ 	addiu	$a1,$s0,0xc
/*    516d8:	0c012c5c */ 	jal	func0004b170
/*    516dc:	24060020 */ 	addiu	$a2,$zero,0x20
/*    516e0:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    516e4:	24190010 */ 	addiu	$t9,$zero,0x10
/*    516e8:	24090008 */ 	addiu	$t1,$zero,0x8
/*    516ec:	916c001b */ 	lbu	$t4,0x1b($t3)
/*    516f0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    516f4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    516f8:	ae0c004c */ 	sw	$t4,0x4c($s0)
/*    516fc:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    51700:	24060007 */ 	addiu	$a2,$zero,0x7
/*    51704:	2607002c */ 	addiu	$a3,$s0,0x2c
/*    51708:	91ae001a */ 	lbu	$t6,0x1a($t5)
/*    5170c:	ae190050 */ 	sw	$t9,0x50($s0)
/*    51710:	ae090054 */ 	sw	$t1,0x54($s0)
/*    51714:	31c200ff */ 	andi	$v0,$t6,0xff
/*    51718:	000218c0 */ 	sll	$v1,$v0,0x3
/*    5171c:	00027840 */ 	sll	$t7,$v0,0x1
/*    51720:	24680008 */ 	addiu	$t0,$v1,0x8
/*    51724:	25f80003 */ 	addiu	$t8,$t7,0x3
/*    51728:	01035021 */ 	addu	$t2,$t0,$v1
/*    5172c:	ae180060 */ 	sw	$t8,0x60($s0)
/*    51730:	ae080058 */ 	sw	$t0,0x58($s0)
/*    51734:	ae0a005c */ 	sw	$t2,0x5c($s0)
/*    51738:	0c012e18 */ 	jal	__osContRamRead
/*    5173c:	a20e0064 */ 	sb	$t6,0x64($s0)
/*    51740:	10400003 */ 	beqz	$v0,.L00051750
/*    51744:	00000000 */ 	sll	$zero,$zero,0x0
/*    51748:	10000007 */ 	beqz	$zero,.L00051768
/*    5174c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00051750:
/*    51750:	0c0135bc */ 	jal	func0004d6f0
/*    51754:	02002025 */ 	or	$a0,$s0,$zero
/*    51758:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*    5175c:	356c0001 */ 	ori	$t4,$t3,0x1
/*    51760:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L00051764:
/*    51764:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00051768:
/*    51768:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    5176c:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*    51770:	03e00008 */ 	jr	$ra
/*    51774:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00051778
/*    51778:	27bdff68 */ 	addiu	$sp,$sp,-152
/*    5177c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    51780:	afb00020 */ 	sw	$s0,0x20($sp)
/*    51784:	00808025 */ 	or	$s0,$a0,$zero
/*    51788:	0c013378 */ 	jal	func0004cde0
/*    5178c:	00002825 */ 	or	$a1,$zero,$zero
/*    51790:	10400003 */ 	beqz	$v0,.L000517a0
/*    51794:	00003025 */ 	or	$a2,$zero,$zero
/*    51798:	10000034 */ 	beqz	$zero,.L0005186c
/*    5179c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L000517a0:
/*    517a0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    517a4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    517a8:	0c012e18 */ 	jal	__osContRamRead
/*    517ac:	27a70030 */ 	addiu	$a3,$sp,0x30
/*    517b0:	10400003 */ 	beqz	$v0,.L000517c0
/*    517b4:	27a30070 */ 	addiu	$v1,$sp,0x70
/*    517b8:	1000002c */ 	beqz	$zero,.L0005186c
/*    517bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L000517c0:
/*    517c0:	00001025 */ 	or	$v0,$zero,$zero
/*    517c4:	24040020 */ 	addiu	$a0,$zero,0x20
.L000517c8:
/*    517c8:	244e0001 */ 	addiu	$t6,$v0,0x1
/*    517cc:	244f0002 */ 	addiu	$t7,$v0,0x2
/*    517d0:	24580003 */ 	addiu	$t8,$v0,0x3
/*    517d4:	a0620000 */ 	sb	$v0,0x0($v1)
/*    517d8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    517dc:	a0780003 */ 	sb	$t8,0x3($v1)
/*    517e0:	a06f0002 */ 	sb	$t7,0x2($v1)
/*    517e4:	a06e0001 */ 	sb	$t6,0x1($v1)
/*    517e8:	1444fff7 */ 	bne	$v0,$a0,.L000517c8
/*    517ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*    517f0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    517f4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    517f8:	afa00010 */ 	sw	$zero,0x10($sp)
/*    517fc:	00003025 */ 	or	$a2,$zero,$zero
/*    51800:	0c012d84 */ 	jal	__osContRamWrite
/*    51804:	27a70070 */ 	addiu	$a3,$sp,0x70
/*    51808:	10400003 */ 	beqz	$v0,.L00051818
/*    5180c:	00003025 */ 	or	$a2,$zero,$zero
/*    51810:	10000016 */ 	beqz	$zero,.L0005186c
/*    51814:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00051818:
/*    51818:	8e040004 */ 	lw	$a0,0x4($s0)
/*    5181c:	8e050008 */ 	lw	$a1,0x8($s0)
/*    51820:	0c012e18 */ 	jal	__osContRamRead
/*    51824:	27a70050 */ 	addiu	$a3,$sp,0x50
/*    51828:	10400003 */ 	beqz	$v0,.L00051838
/*    5182c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*    51830:	1000000e */ 	beqz	$zero,.L0005186c
/*    51834:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00051838:
/*    51838:	27a50050 */ 	addiu	$a1,$sp,0x50
/*    5183c:	0c013824 */ 	jal	func0004e090
/*    51840:	24060020 */ 	addiu	$a2,$zero,0x20
/*    51844:	10400003 */ 	beqz	$v0,.L00051854
/*    51848:	00003025 */ 	or	$a2,$zero,$zero
/*    5184c:	10000006 */ 	beqz	$zero,.L00051868
/*    51850:	2402000b */ 	addiu	$v0,$zero,0xb
.L00051854:
/*    51854:	8e040004 */ 	lw	$a0,0x4($s0)
/*    51858:	8e050008 */ 	lw	$a1,0x8($s0)
/*    5185c:	afa00010 */ 	sw	$zero,0x10($sp)
/*    51860:	0c012d84 */ 	jal	__osContRamWrite
/*    51864:	27a70030 */ 	addiu	$a3,$sp,0x30
.L00051868:
/*    51868:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0005186c:
/*    5186c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    51870:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*    51874:	03e00008 */ 	jr	$ra
/*    51878:	00000000 */ 	sll	$zero,$zero,0x0
/*    5187c:	00000000 */ 	sll	$zero,$zero,0x0
);