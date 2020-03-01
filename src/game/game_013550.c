#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f013550
/*  f013550:	3c0e8009 */ 	lui	$t6,0x8009
/*  f013554:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f013558:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f01355c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f013560:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013564:	150e0005 */ 	bne	$t0,$t6,.L0f01357c
/*  f013568:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f01356c:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f013570:	25ad9fc0 */ 	addiu	$t5,$t5,%lo(g_Vars)
/*  f013574:	10000044 */ 	beqz	$zero,.L0f013688
/*  f013578:	00003025 */ 	or	$a2,$zero,$zero
.L0f01357c:
/*  f01357c:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f013580:	25ad9fc0 */ 	addiu	$t5,$t5,%lo(g_Vars)
/*  f013584:	8daf0298 */ 	lw	$t7,0x298($t5)
/*  f013588:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01358c:	05e30005 */ 	bgezl	$t7,.L0f0135a4
/*  f013590:	8db9006c */ 	lw	$t9,0x6c($t5)
/*  f013594:	8db8029c */ 	lw	$t8,0x29c($t5)
/*  f013598:	07020020 */ 	bltzl	$t8,.L0f01361c
/*  f01359c:	8db8006c */ 	lw	$t8,0x6c($t5)
/*  f0135a0:	8db9006c */ 	lw	$t9,0x6c($t5)
.L0f0135a4:
/*  f0135a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0135a8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0135ac:	13200003 */ 	beqz	$t9,.L0f0135bc
/*  f0135b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0135b4:	10000001 */ 	beqz	$zero,.L0f0135bc
/*  f0135b8:	01002825 */ 	or	$a1,$t0,$zero
.L0f0135bc:
/*  f0135bc:	8dae0068 */ 	lw	$t6,0x68($t5)
/*  f0135c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0135c4:	11c00003 */ 	beqz	$t6,.L0f0135d4
/*  f0135c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0135cc:	10000001 */ 	beqz	$zero,.L0f0135d4
/*  f0135d0:	01002025 */ 	or	$a0,$t0,$zero
.L0f0135d4:
/*  f0135d4:	8daf0064 */ 	lw	$t7,0x64($t5)
/*  f0135d8:	11e00003 */ 	beqz	$t7,.L0f0135e8
/*  f0135dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0135e0:	10000001 */ 	beqz	$zero,.L0f0135e8
/*  f0135e4:	01001825 */ 	or	$v1,$t0,$zero
.L0f0135e8:
/*  f0135e8:	8db80070 */ 	lw	$t8,0x70($t5)
/*  f0135ec:	13000003 */ 	beqz	$t8,.L0f0135fc
/*  f0135f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0135f4:	10000001 */ 	beqz	$zero,.L0f0135fc
/*  f0135f8:	01001025 */ 	or	$v0,$t0,$zero
.L0f0135fc:
/*  f0135fc:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f013600:	03247021 */ 	addu	$t6,$t9,$a0
/*  f013604:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f013608:	55e10004 */ 	bnel	$t7,$at,.L0f01361c
/*  f01360c:	8db8006c */ 	lw	$t8,0x6c($t5)
/*  f013610:	1000001d */ 	beqz	$zero,.L0f013688
/*  f013614:	01003025 */ 	or	$a2,$t0,$zero
/*  f013618:	8db8006c */ 	lw	$t8,0x6c($t5)
.L0f01361c:
/*  f01361c:	8da20068 */ 	lw	$v0,0x68($t5)
/*  f013620:	8da30064 */ 	lw	$v1,0x64($t5)
/*  f013624:	13000003 */ 	beqz	$t8,.L0f013634
/*  f013628:	8da70070 */ 	lw	$a3,0x70($t5)
/*  f01362c:	10000002 */ 	beqz	$zero,.L0f013638
/*  f013630:	01002825 */ 	or	$a1,$t0,$zero
.L0f013634:
/*  f013634:	00002825 */ 	or	$a1,$zero,$zero
.L0f013638:
/*  f013638:	10400003 */ 	beqz	$v0,.L0f013648
/*  f01363c:	00002025 */ 	or	$a0,$zero,$zero
/*  f013640:	10000001 */ 	beqz	$zero,.L0f013648
/*  f013644:	01002025 */ 	or	$a0,$t0,$zero
.L0f013648:
/*  f013648:	10600003 */ 	beqz	$v1,.L0f013658
/*  f01364c:	00001025 */ 	or	$v0,$zero,$zero
/*  f013650:	10000002 */ 	beqz	$zero,.L0f01365c
/*  f013654:	01001825 */ 	or	$v1,$t0,$zero
.L0f013658:
/*  f013658:	00001825 */ 	or	$v1,$zero,$zero
.L0f01365c:
/*  f01365c:	10e00003 */ 	beqz	$a3,.L0f01366c
/*  f013660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013664:	10000001 */ 	beqz	$zero,.L0f01366c
/*  f013668:	01001025 */ 	or	$v0,$t0,$zero
.L0f01366c:
/*  f01366c:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f013670:	03247021 */ 	addu	$t6,$t9,$a0
/*  f013674:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f013678:	29e10002 */ 	slti	$at,$t7,0x2
/*  f01367c:	14200002 */ 	bnez	$at,.L0f013688
/*  f013680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013684:	00003025 */ 	or	$a2,$zero,$zero
.L0f013688:
/*  f013688:	10c00008 */ 	beqz	$a2,.L0f0136ac
/*  f01368c:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f013690:	10c80022 */ 	beq	$a2,$t0,.L0f01371c
/*  f013694:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f013698:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01369c:	10c1003c */ 	beq	$a2,$at,.L0f013790
/*  f0136a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0136a4:	1000003a */ 	beqz	$zero,.L0f013790
/*  f0136a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0136ac:
/*  f0136ac:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f0136b0:	24180050 */ 	addiu	$t8,$zero,0x50
/*  f0136b4:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f0136b8:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0136bc:	3c01800a */ 	lui	$at,0x800a
/*  f0136c0:	ac39cc5c */ 	sw	$t9,-0x33a4($at)
/*  f0136c4:	3c01800a */ 	lui	$at,0x800a
/*  f0136c8:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f0136cc:	ac2ecc60 */ 	sw	$t6,-0x33a0($at)
/*  f0136d0:	3c01800a */ 	lui	$at,0x800a
/*  f0136d4:	ac28cc64 */ 	sw	$t0,-0x339c($at)
/*  f0136d8:	3c01800a */ 	lui	$at,0x800a
/*  f0136dc:	240f0019 */ 	addiu	$t7,$zero,0x19
/*  f0136e0:	ac2fcc68 */ 	sw	$t7,-0x3398($at)
/*  f0136e4:	3c01800a */ 	lui	$at,0x800a
/*  f0136e8:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0136ec:	ac38cc6c */ 	sw	$t8,-0x3394($at)
/*  f0136f0:	3c01800a */ 	lui	$at,0x800a
/*  f0136f4:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f0136f8:	ac39cc70 */ 	sw	$t9,-0x3390($at)
/*  f0136fc:	3c01800a */ 	lui	$at,0x800a
/*  f013700:	240e000f */ 	addiu	$t6,$zero,0xf
/*  f013704:	ac2ecc74 */ 	sw	$t6,-0x338c($at)
/*  f013708:	3c017f1b */ 	lui	$at,%hi(var7f1a8290)
/*  f01370c:	c4248290 */ 	lwc1	$f4,%lo(var7f1a8290)($at)
/*  f013710:	3c01800a */ 	lui	$at,0x800a
/*  f013714:	1000003b */ 	beqz	$zero,.L0f013804
/*  f013718:	e424cc78 */ 	swc1	$f4,-0x3388($at)
.L0f01371c:
/*  f01371c:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f013720:	240f00c8 */ 	addiu	$t7,$zero,0xc8
/*  f013724:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f013728:	24180019 */ 	addiu	$t8,$zero,0x19
/*  f01372c:	3c01800a */ 	lui	$at,0x800a
/*  f013730:	ac38cc5c */ 	sw	$t8,-0x33a4($at)
/*  f013734:	3c01800a */ 	lui	$at,0x800a
/*  f013738:	24190064 */ 	addiu	$t9,$zero,0x64
/*  f01373c:	ac39cc60 */ 	sw	$t9,-0x33a0($at)
/*  f013740:	3c01800a */ 	lui	$at,0x800a
/*  f013744:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f013748:	ac2ecc64 */ 	sw	$t6,-0x339c($at)
/*  f01374c:	3c01800a */ 	lui	$at,0x800a
/*  f013750:	240f0028 */ 	addiu	$t7,$zero,0x28
/*  f013754:	ac2fcc68 */ 	sw	$t7,-0x3398($at)
/*  f013758:	3c01800a */ 	lui	$at,0x800a
/*  f01375c:	24180050 */ 	addiu	$t8,$zero,0x50
/*  f013760:	ac38cc6c */ 	sw	$t8,-0x3394($at)
/*  f013764:	3c01800a */ 	lui	$at,0x800a
/*  f013768:	24190014 */ 	addiu	$t9,$zero,0x14
/*  f01376c:	ac39cc70 */ 	sw	$t9,-0x3390($at)
/*  f013770:	3c01800a */ 	lui	$at,0x800a
/*  f013774:	240e001e */ 	addiu	$t6,$zero,0x1e
/*  f013778:	ac2ecc74 */ 	sw	$t6,-0x338c($at)
/*  f01377c:	3c017f1b */ 	lui	$at,%hi(var7f1a8294)
/*  f013780:	c4268294 */ 	lwc1	$f6,%lo(var7f1a8294)($at)
/*  f013784:	3c01800a */ 	lui	$at,0x800a
/*  f013788:	1000001e */ 	beqz	$zero,.L0f013804
/*  f01378c:	e426cc78 */ 	swc1	$f6,-0x3388($at)
.L0f013790:
/*  f013790:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f013794:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f013798:	240f0168 */ 	addiu	$t7,$zero,0x168
/*  f01379c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0137a0:	24180032 */ 	addiu	$t8,$zero,0x32
/*  f0137a4:	3c01800a */ 	lui	$at,0x800a
/*  f0137a8:	ac38cc5c */ 	sw	$t8,-0x33a4($at)
/*  f0137ac:	3c01800a */ 	lui	$at,0x800a
/*  f0137b0:	24190078 */ 	addiu	$t9,$zero,0x78
/*  f0137b4:	ac39cc60 */ 	sw	$t9,-0x33a0($at)
/*  f0137b8:	3c01800a */ 	lui	$at,0x800a
/*  f0137bc:	240e000a */ 	addiu	$t6,$zero,0xa
/*  f0137c0:	ac2ecc64 */ 	sw	$t6,-0x339c($at)
/*  f0137c4:	3c01800a */ 	lui	$at,0x800a
/*  f0137c8:	240f003c */ 	addiu	$t7,$zero,0x3c
/*  f0137cc:	ac2fcc68 */ 	sw	$t7,-0x3398($at)
/*  f0137d0:	3c01800a */ 	lui	$at,0x800a
/*  f0137d4:	241800b4 */ 	addiu	$t8,$zero,0xb4
/*  f0137d8:	ac38cc6c */ 	sw	$t8,-0x3394($at)
/*  f0137dc:	3c01800a */ 	lui	$at,0x800a
/*  f0137e0:	24190019 */ 	addiu	$t9,$zero,0x19
/*  f0137e4:	ac39cc70 */ 	sw	$t9,-0x3390($at)
/*  f0137e8:	3c01800a */ 	lui	$at,0x800a
/*  f0137ec:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f0137f0:	ac2ecc74 */ 	sw	$t6,-0x338c($at)
/*  f0137f4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0137f8:	44814000 */ 	mtc1	$at,$f8
/*  f0137fc:	3c01800a */ 	lui	$at,0x800a
/*  f013800:	e428cc78 */ 	swc1	$f8,-0x3388($at)
.L0f013804:
/*  f013804:	3c0c800a */ 	lui	$t4,%hi(var8009cc40)
/*  f013808:	258ccc40 */ 	addiu	$t4,$t4,%lo(var8009cc40)
/*  f01380c:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f013810:	3c01800a */ 	lui	$at,0x800a
/*  f013814:	3c0a800a */ 	lui	$t2,%hi(var8009cc4c)
/*  f013818:	ac20cc48 */ 	sw	$zero,-0x33b8($at)
/*  f01381c:	254acc4c */ 	addiu	$t2,$t2,%lo(var8009cc4c)
/*  f013820:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f013824:	3c01800a */ 	lui	$at,0x800a
/*  f013828:	ac20cc50 */ 	sw	$zero,-0x33b0($at)
/*  f01382c:	3c01800a */ 	lui	$at,0x800a
/*  f013830:	ac20cc54 */ 	sw	$zero,-0x33ac($at)
/*  f013834:	3c01800a */ 	lui	$at,0x800a
/*  f013838:	ac20cc58 */ 	sw	$zero,-0x33a8($at)
/*  f01383c:	8daf04b4 */ 	lw	$t7,0x4b4($t5)
/*  f013840:	3c04800a */ 	lui	$a0,%hi(var800a41b0)
/*  f013844:	248441b0 */ 	addiu	$a0,$a0,%lo(var800a41b0)
/*  f013848:	29e1005a */ 	slti	$at,$t7,0x5a
/*  f01384c:	54200003 */ 	bnezl	$at,.L0f01385c
/*  f013850:	8d660000 */ 	lw	$a2,0x0($t3)
/*  f013854:	ad600000 */ 	sw	$zero,0x0($t3)
/*  f013858:	8d660000 */ 	lw	$a2,0x0($t3)
.L0f01385c:
/*  f01385c:	54c00004 */ 	bnezl	$a2,.L0f013870
/*  f013860:	8da302bc */ 	lw	$v1,0x2bc($t5)
/*  f013864:	1000005e */ 	beqz	$zero,.L0f0139e0
/*  f013868:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f01386c:	8da302bc */ 	lw	$v1,0x2bc($t5)
.L0f013870:
/*  f013870:	00061140 */ 	sll	$v0,$a2,0x5
/*  f013874:	00461023 */ 	subu	$v0,$v0,$a2
/*  f013878:	2407fff0 */ 	addiu	$a3,$zero,-16
/*  f01387c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f013880:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f013884:	2442000f */ 	addiu	$v0,$v0,0xf
/*  f013888:	2703000f */ 	addiu	$v1,$t8,0xf
/*  f01388c:	00471024 */ 	and	$v0,$v0,$a3
/*  f013890:	00671824 */ 	and	$v1,$v1,$a3
/*  f013894:	00432021 */ 	addu	$a0,$v0,$v1
/*  f013898:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f01389c:	0c0048f2 */ 	jal	malloc
/*  f0138a0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0138a4:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0138a8:	3c04800a */ 	lui	$a0,%hi(var800a41b0)
/*  f0138ac:	3c08800a */ 	lui	$t0,%hi(var800a41b4)
/*  f0138b0:	3c0c800a */ 	lui	$t4,%hi(var8009cc40)
/*  f0138b4:	258ccc40 */ 	addiu	$t4,$t4,%lo(var8009cc40)
/*  f0138b8:	250841b4 */ 	addiu	$t0,$t0,%lo(var800a41b4)
/*  f0138bc:	248441b0 */ 	addiu	$a0,$a0,%lo(var800a41b0)
/*  f0138c0:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0138c4:	3c0b800a */ 	lui	$t3,%hi(var8009cc44)
/*  f0138c8:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f0138cc:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0138d0:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f0138d4:	3c01800a */ 	lui	$at,0x800a
/*  f0138d8:	256bcc44 */ 	addiu	$t3,$t3,%lo(var8009cc44)
/*  f0138dc:	ac2041b8 */ 	sw	$zero,0x41b8($at)
/*  f0138e0:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0138e4:	3c0a800a */ 	lui	$t2,%hi(var8009cc4c)
/*  f0138e8:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f0138ec:	25ad9fc0 */ 	addiu	$t5,$t5,%lo(g_Vars)
/*  f0138f0:	254acc4c */ 	addiu	$t2,$t2,%lo(var8009cc4c)
/*  f0138f4:	19c0002e */ 	blez	$t6,.L0f0139b0
/*  f0138f8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0138fc:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f013900:	00001825 */ 	or	$v1,$zero,$zero
/*  f013904:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f013908:
/*  f013908:	00e37821 */ 	addu	$t7,$a3,$v1
/*  f01390c:	a1e0006d */ 	sb	$zero,0x6d($t7)
/*  f013910:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f013914:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f013918:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f01391c:	a320006e */ 	sb	$zero,0x6e($t9)
/*  f013920:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f013924:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f013928:	8c450070 */ 	lw	$a1,0x70($v0)
/*  f01392c:	00057902 */ 	srl	$t7,$a1,0x4
/*  f013930:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f013934:	0305c826 */ 	xor	$t9,$t8,$a1
/*  f013938:	ac590070 */ 	sw	$t9,0x70($v0)
/*  f01393c:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f013940:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f013944:	904f006f */ 	lbu	$t7,0x6f($v0)
/*  f013948:	31f8ff7f */ 	andi	$t8,$t7,0xff7f
/*  f01394c:	a058006f */ 	sb	$t8,0x6f($v0)
/*  f013950:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f013954:	03237021 */ 	addu	$t6,$t9,$v1
/*  f013958:	a5c90068 */ 	sh	$t1,0x68($t6)
/*  f01395c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f013960:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f013964:	af00005c */ 	sw	$zero,0x5c($t8)
/*  f013968:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f01396c:	03237021 */ 	addu	$t6,$t9,$v1
/*  f013970:	adc00060 */ 	sw	$zero,0x60($t6)
/*  f013974:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f013978:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f01397c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f013980:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f013984:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f013988:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f01398c:	adf90074 */ 	sw	$t9,0x74($t7)
/*  f013990:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f013994:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f013998:	00ce082a */ 	slt	$at,$a2,$t6
/*  f01399c:	0067c021 */ 	addu	$t8,$v1,$a3
/*  f0139a0:	2463007c */ 	addiu	$v1,$v1,0x7c
/*  f0139a4:	1420ffd8 */ 	bnez	$at,.L0f013908
/*  f0139a8:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f0139ac:	00003025 */ 	or	$a2,$zero,$zero
.L0f0139b0:
/*  f0139b0:	8db902bc */ 	lw	$t9,0x2bc($t5)
/*  f0139b4:	1b20000a */ 	blez	$t9,.L0f0139e0
/*  f0139b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0139bc:	8d8f0000 */ 	lw	$t7,0x0($t4)
.L0f0139c0:
/*  f0139c0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0139c4:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f0139c8:	a7000000 */ 	sh	$zero,0x0($t8)
/*  f0139cc:	8dae02bc */ 	lw	$t6,0x2bc($t5)
/*  f0139d0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0139d4:	00ce082a */ 	slt	$at,$a2,$t6
/*  f0139d8:	5420fff9 */ 	bnezl	$at,.L0f0139c0
/*  f0139dc:	8d8f0000 */ 	lw	$t7,0x0($t4)
.L0f0139e0:
/*  f0139e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0139e4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0139e8:	03e00008 */ 	jr	$ra
/*  f0139ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0139f0
/*  f0139f0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0139f4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0139f8:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f0139fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013a00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013a04:	11c00003 */ 	beqz	$t6,.L0f013a14
/*  f013a08:	3c06800a */ 	lui	$a2,%hi(var800a45c0)
/*  f013a0c:	10000002 */ 	beqz	$zero,.L0f013a18
/*  f013a10:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f013a14:
/*  f013a14:	00003825 */ 	or	$a3,$zero,$zero
.L0f013a18:
/*  f013a18:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f013a1c:	24c645c0 */ 	addiu	$a2,$a2,%lo(var800a45c0)
/*  f013a20:	240b00c8 */ 	addiu	$t3,$zero,0xc8
/*  f013a24:	11e00003 */ 	beqz	$t7,.L0f013a34
/*  f013a28:	3c0d8009 */ 	lui	$t5,0x8009
/*  f013a2c:	10000002 */ 	beqz	$zero,.L0f013a38
/*  f013a30:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f013a34:
/*  f013a34:	00001825 */ 	or	$v1,$zero,$zero
.L0f013a38:
/*  f013a38:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f013a3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f013a40:	00001025 */ 	or	$v0,$zero,$zero
/*  f013a44:	13000003 */ 	beqz	$t8,.L0f013a54
/*  f013a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a4c:	10000001 */ 	beqz	$zero,.L0f013a54
/*  f013a50:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f013a54:
/*  f013a54:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f013a58:	13200003 */ 	beqz	$t9,.L0f013a68
/*  f013a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a60:	10000001 */ 	beqz	$zero,.L0f013a68
/*  f013a64:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f013a68:
/*  f013a68:	00444021 */ 	addu	$t0,$v0,$a0
/*  f013a6c:	01034821 */ 	addu	$t1,$t0,$v1
/*  f013a70:	01275021 */ 	addu	$t2,$t1,$a3
/*  f013a74:	016a001a */ 	div	$zero,$t3,$t2
/*  f013a78:	15400002 */ 	bnez	$t2,.L0f013a84
/*  f013a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a80:	0007000d */ 	break	0x7
.L0f013a84:
/*  f013a84:	2401ffff */ 	addiu	$at,$zero,-1
/*  f013a88:	15410004 */ 	bne	$t2,$at,.L0f013a9c
/*  f013a8c:	3c018000 */ 	lui	$at,0x8000
/*  f013a90:	15610002 */ 	bne	$t3,$at,.L0f013a9c
/*  f013a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013a98:	0006000d */ 	break	0x6
.L0f013a9c:
/*  f013a9c:	00006012 */ 	mflo	$t4
/*  f013aa0:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f013aa4:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f013aa8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f013aac:	01807025 */ 	or	$t6,$t4,$zero
/*  f013ab0:	15a10006 */ 	bne	$t5,$at,.L0f013acc
/*  f013ab4:	3c04800a */ 	lui	$a0,%hi(var800a45c4)
/*  f013ab8:	05c10003 */ 	bgez	$t6,.L0f013ac8
/*  f013abc:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f013ac0:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f013ac4:	00017843 */ 	sra	$t7,$at,0x1
.L0f013ac8:
/*  f013ac8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f013acc:
/*  f013acc:	8cb804b4 */ 	lw	$t8,0x4b4($a1)
/*  f013ad0:	248445c4 */ 	addiu	$a0,$a0,%lo(var800a45c4)
/*  f013ad4:	2b01005a */ 	slti	$at,$t8,0x5a
/*  f013ad8:	54200003 */ 	bnezl	$at,.L0f013ae8
/*  f013adc:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f013ae0:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f013ae4:	8cc20000 */ 	lw	$v0,0x0($a2)
.L0f013ae8:
/*  f013ae8:	54400004 */ 	bnezl	$v0,.L0f013afc
/*  f013aec:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f013af0:	1000001e */ 	beqz	$zero,.L0f013b6c
/*  f013af4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f013af8:	000220c0 */ 	sll	$a0,$v0,0x3
.L0f013afc:
/*  f013afc:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013b00:	00042080 */ 	sll	$a0,$a0,0x2
/*  f013b04:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013b08:	00042080 */ 	sll	$a0,$a0,0x2
/*  f013b0c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013b10:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f013b14:	0081c824 */ 	and	$t9,$a0,$at
/*  f013b18:	03202025 */ 	or	$a0,$t9,$zero
/*  f013b1c:	0c0048f2 */ 	jal	malloc
/*  f013b20:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013b24:	3c06800a */ 	lui	$a2,%hi(var800a45c0)
/*  f013b28:	24c645c0 */ 	addiu	$a2,$a2,%lo(var800a45c0)
/*  f013b2c:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f013b30:	3c04800a */ 	lui	$a0,%hi(var800a45c4)
/*  f013b34:	248445c4 */ 	addiu	$a0,$a0,%lo(var800a45c4)
/*  f013b38:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f013b3c:	1900000b */ 	blez	$t0,.L0f013b6c
/*  f013b40:	00001825 */ 	or	$v1,$zero,$zero
/*  f013b44:	00001025 */ 	or	$v0,$zero,$zero
/*  f013b48:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f013b4c:
/*  f013b4c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f013b50:	01225821 */ 	addu	$t3,$t1,$v0
/*  f013b54:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f013b58:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f013b5c:	2442006c */ 	addiu	$v0,$v0,0x6c
/*  f013b60:	006a082a */ 	slt	$at,$v1,$t2
/*  f013b64:	5420fff9 */ 	bnezl	$at,.L0f013b4c
/*  f013b68:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f013b6c:
/*  f013b6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013b70:	3c018008 */ 	lui	$at,0x8008
/*  f013b74:	ac20fa80 */ 	sw	$zero,-0x580($at)
/*  f013b78:	03e00008 */ 	jr	$ra
/*  f013b7c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f013b80
/*  f013b80:	3c02800b */ 	lui	$v0,%hi(var800aabc8)
/*  f013b84:	3c01800b */ 	lui	$at,0x800b
/*  f013b88:	2442abc8 */ 	addiu	$v0,$v0,%lo(var800aabc8)
/*  f013b8c:	ac20b538 */ 	sw	$zero,-0x4ac8($at)
/*  f013b90:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f013b94:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f013b98:	03e00008 */ 	jr	$ra
/*  f013b9c:	ac40000c */ 	sw	$zero,0xc($v0)
);

GLOBAL_ASM(
glabel func0f013ba0
/*  f013ba0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f013ba4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f013ba8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f013bac:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f013bb0:	3c128008 */ 	lui	$s2,%hi(var8007e3d0)
/*  f013bb4:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f013bb8:	3c158008 */ 	lui	$s5,%hi(var8007e4a0)
/*  f013bbc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f013bc0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f013bc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f013bc8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f013bcc:	26b5e4a0 */ 	addiu	$s5,$s5,%lo(var8007e4a0)
/*  f013bd0:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f013bd4:	2652e3d0 */ 	addiu	$s2,$s2,%lo(var8007e3d0)
.L0f013bd8:
/*  f013bd8:	8e8e006c */ 	lw	$t6,0x6c($s4)
/*  f013bdc:	8e820068 */ 	lw	$v0,0x68($s4)
/*  f013be0:	8e840064 */ 	lw	$a0,0x64($s4)
/*  f013be4:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f013be8:	11c00003 */ 	beqz	$t6,.L0f013bf8
/*  f013bec:	00008025 */ 	or	$s0,$zero,$zero
/*  f013bf0:	10000002 */ 	beqz	$zero,.L0f013bfc
/*  f013bf4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f013bf8:
/*  f013bf8:	00002825 */ 	or	$a1,$zero,$zero
.L0f013bfc:
/*  f013bfc:	10400003 */ 	beqz	$v0,.L0f013c0c
/*  f013c00:	00001825 */ 	or	$v1,$zero,$zero
/*  f013c04:	10000001 */ 	beqz	$zero,.L0f013c0c
/*  f013c08:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f013c0c:
/*  f013c0c:	10800003 */ 	beqz	$a0,.L0f013c1c
/*  f013c10:	00001025 */ 	or	$v0,$zero,$zero
/*  f013c14:	10000002 */ 	beqz	$zero,.L0f013c20
/*  f013c18:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f013c1c:
/*  f013c1c:	00002025 */ 	or	$a0,$zero,$zero
.L0f013c20:
/*  f013c20:	10c00003 */ 	beqz	$a2,.L0f013c30
/*  f013c24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013c28:	10000001 */ 	beqz	$zero,.L0f013c30
/*  f013c2c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f013c30:
/*  f013c30:	00447821 */ 	addu	$t7,$v0,$a0
/*  f013c34:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f013c38:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f013c3c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f013c40:	14200004 */ 	bnez	$at,.L0f013c54
/*  f013c44:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013c48:	8e530008 */ 	lw	$s3,0x8($s2)
/*  f013c4c:	1000000a */ 	beqz	$zero,.L0f013c78
/*  f013c50:	8e51000c */ 	lw	$s1,0xc($s2)
.L0f013c54:
/*  f013c54:	8e8804b4 */ 	lw	$t0,0x4b4($s4)
/*  f013c58:	2901005a */ 	slti	$at,$t0,0x5a
/*  f013c5c:	54200005 */ 	bnezl	$at,.L0f013c74
/*  f013c60:	8e530000 */ 	lw	$s3,0x0($s2)
/*  f013c64:	8e530010 */ 	lw	$s3,0x10($s2)
/*  f013c68:	10000003 */ 	beqz	$zero,.L0f013c78
/*  f013c6c:	8e510014 */ 	lw	$s1,0x14($s2)
/*  f013c70:	8e530000 */ 	lw	$s3,0x0($s2)
.L0f013c74:
/*  f013c74:	8e510004 */ 	lw	$s1,0x4($s2)
.L0f013c78:
/*  f013c78:	1a200004 */ 	blez	$s1,.L0f013c8c
/*  f013c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013c80:	0c0048f2 */ 	jal	malloc
/*  f013c84:	00112100 */ 	sll	$a0,$s1,0x4
/*  f013c88:	ae420024 */ 	sw	$v0,0x24($s2)
.L0f013c8c:
/*  f013c8c:	1a200007 */ 	blez	$s1,.L0f013cac
/*  f013c90:	00001025 */ 	or	$v0,$zero,$zero
.L0f013c94:
/*  f013c94:	8e490024 */ 	lw	$t1,0x24($s2)
/*  f013c98:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f013c9c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f013ca0:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f013ca4:	1611fffb */ 	bne	$s0,$s1,.L0f013c94
/*  f013ca8:	a540000e */ 	sh	$zero,0xe($t2)
.L0f013cac:
/*  f013cac:	26520034 */ 	addiu	$s2,$s2,0x34
/*  f013cb0:	ae51fffc */ 	sw	$s1,-0x4($s2)
/*  f013cb4:	ae53fff4 */ 	sw	$s3,-0xc($s2)
/*  f013cb8:	1655ffc7 */ 	bne	$s2,$s5,.L0f013bd8
/*  f013cbc:	ae53fff8 */ 	sw	$s3,-0x8($s2)
/*  f013cc0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f013cc4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f013cc8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f013ccc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f013cd0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f013cd4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f013cd8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f013cdc:	03e00008 */ 	jr	$ra
/*  f013ce0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f013ce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013cec:	00000000 */ 	sll	$zero,$zero,0x0
);
