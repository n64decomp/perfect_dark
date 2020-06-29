#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096700.h"
#include "game/game_0969d0.h"
#include "game/game_096ca0.h"
#include "game/floor.h"
#include "game/ceil.h"
#include "game/game_0b3350.h"
#include "game/game_157db0.h"
#include "game/game_166e40.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4f5e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0001a500
/*    1a500:	3c018006 */ 	lui	$at,%hi(var8005efb4)
/*    1a504:	03e00008 */ 	jr	$ra
/*    1a508:	ac24efb4 */ 	sw	$a0,%lo(var8005efb4)($at)
);

GLOBAL_ASM(
glabel func0001a50c
/*    1a50c:	3c018006 */ 	lui	$at,0x8006
/*    1a510:	03e00008 */ 	jr	$ra
/*    1a514:	e42cefb8 */ 	swc1	$f12,-0x1048($at)
);

void func0001a518(void *callback)
{
	var8005efc8 = callback;
}

GLOBAL_ASM(
glabel func0001a524
/*    1a524:	10800026 */ 	beqz	$a0,.L0001a5c0
/*    1a528:	00a03025 */ 	or	$a2,$a1,$zero
/*    1a52c:	24070015 */ 	addiu	$a3,$zero,0x15
/*    1a530:	24050002 */ 	addiu	$a1,$zero,0x2
/*    1a534:	24020001 */ 	addiu	$v0,$zero,0x1
/*    1a538:	94830000 */ 	lhu	$v1,0x0($a0)
.L0001a53c:
/*    1a53c:	306e00ff */ 	andi	$t6,$v1,0xff
/*    1a540:	51c20008 */ 	beql	$t6,$v0,.L0001a564
/*    1a544:	8c830004 */ 	lw	$v1,0x4($a0)
/*    1a548:	51c50009 */ 	beql	$t6,$a1,.L0001a570
/*    1a54c:	24010200 */ 	addiu	$at,$zero,0x200
/*    1a550:	51c70016 */ 	beql	$t6,$a3,.L0001a5ac
/*    1a554:	8c830004 */ 	lw	$v1,0x4($a0)
/*    1a558:	10000017 */ 	b	.L0001a5b8
/*    1a55c:	8c840008 */ 	lw	$a0,0x8($a0)
/*    1a560:	8c830004 */ 	lw	$v1,0x4($a0)
.L0001a564:
/*    1a564:	03e00008 */ 	jr	$ra
/*    1a568:	84620002 */ 	lh	$v0,0x2($v1)
/*    1a56c:	24010200 */ 	addiu	$at,$zero,0x200
.L0001a570:
/*    1a570:	14c10003 */ 	bne	$a2,$at,.L0001a580
/*    1a574:	8c850004 */ 	lw	$a1,0x4($a0)
/*    1a578:	10000007 */ 	b	.L0001a598
/*    1a57c:	24030002 */ 	addiu	$v1,$zero,0x2
.L0001a580:
/*    1a580:	24010100 */ 	addiu	$at,$zero,0x100
/*    1a584:	14c10003 */ 	bne	$a2,$at,.L0001a594
/*    1a588:	00001025 */ 	or	$v0,$zero,$zero
/*    1a58c:	10000001 */ 	b	.L0001a594
/*    1a590:	24020001 */ 	addiu	$v0,$zero,0x1
.L0001a594:
/*    1a594:	00401825 */ 	or	$v1,$v0,$zero
.L0001a598:
/*    1a598:	00037840 */ 	sll	$t7,$v1,0x1
/*    1a59c:	00afc021 */ 	addu	$t8,$a1,$t7
/*    1a5a0:	03e00008 */ 	jr	$ra
/*    1a5a4:	8702000e */ 	lh	$v0,0xe($t8)
/*    1a5a8:	8c830004 */ 	lw	$v1,0x4($a0)
.L0001a5ac:
/*    1a5ac:	03e00008 */ 	jr	$ra
/*    1a5b0:	8462000c */ 	lh	$v0,0xc($v1)
/*    1a5b4:	8c840008 */ 	lw	$a0,0x8($a0)
.L0001a5b8:
/*    1a5b8:	5480ffe0 */ 	bnezl	$a0,.L0001a53c
/*    1a5bc:	94830000 */ 	lhu	$v1,0x0($a0)
.L0001a5c0:
/*    1a5c0:	2402ffff */ 	addiu	$v0,$zero,-1
/*    1a5c4:	03e00008 */ 	jr	$ra
/*    1a5c8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001a5cc
/*    1a5cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1a5d0:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1a5d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1a5d8:	00a02025 */ 	or	$a0,$a1,$zero
/*    1a5dc:	0c006949 */ 	jal	func0001a524
/*    1a5e0:	00c02825 */ 	or	$a1,$a2,$zero
/*    1a5e4:	04400006 */ 	bltz	$v0,.L0001a600
/*    1a5e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1a5ec:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    1a5f0:	0002c180 */ 	sll	$t8,$v0,0x6
/*    1a5f4:	8dcf000c */ 	lw	$t7,0xc($t6)
/*    1a5f8:	10000002 */ 	b	.L0001a604
/*    1a5fc:	01f81021 */ 	addu	$v0,$t7,$t8
.L0001a600:
/*    1a600:	00001025 */ 	or	$v0,$zero,$zero
.L0001a604:
/*    1a604:	03e00008 */ 	jr	$ra
/*    1a608:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0001a60c
/*    1a60c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1a610:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1a614:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    1a618:	00003025 */ 	or	$a2,$zero,$zero
/*    1a61c:	0c006973 */ 	jal	func0001a5cc
/*    1a620:	8dc50000 */ 	lw	$a1,0x0($t6)
/*    1a624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1a628:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1a62c:	03e00008 */ 	jr	$ra
/*    1a630:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001a634
/*    1a634:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    1a638:	24040001 */ 	addiu	$a0,$zero,0x1
/*    1a63c:	24070015 */ 	addiu	$a3,$zero,0x15
/*    1a640:	8dc30000 */ 	lw	$v1,0x0($t6)
/*    1a644:	24060002 */ 	addiu	$a2,$zero,0x2
/*    1a648:	5060003b */ 	beqzl	$v1,.L0001a738
/*    1a64c:	00001025 */ 	or	$v0,$zero,$zero
/*    1a650:	94620000 */ 	lhu	$v0,0x0($v1)
.L0001a654:
/*    1a654:	304f00ff */ 	andi	$t7,$v0,0xff
/*    1a658:	51e40008 */ 	beql	$t7,$a0,.L0001a67c
/*    1a65c:	8c620004 */ 	lw	$v0,0x4($v1)
/*    1a660:	51e6000e */ 	beql	$t7,$a2,.L0001a69c
/*    1a664:	8c620004 */ 	lw	$v0,0x4($v1)
/*    1a668:	51e7001a */ 	beql	$t7,$a3,.L0001a6d4
/*    1a66c:	8c620004 */ 	lw	$v0,0x4($v1)
/*    1a670:	1000001e */ 	b	.L0001a6ec
/*    1a674:	8c620014 */ 	lw	$v0,0x14($v1)
/*    1a678:	8c620004 */ 	lw	$v0,0x4($v1)
.L0001a67c:
/*    1a67c:	84580002 */ 	lh	$t8,0x2($v0)
/*    1a680:	14b80003 */ 	bne	$a1,$t8,.L0001a690
/*    1a684:	00000000 */ 	nop
/*    1a688:	03e00008 */ 	jr	$ra
/*    1a68c:	00601025 */ 	or	$v0,$v1,$zero
.L0001a690:
/*    1a690:	10000016 */ 	b	.L0001a6ec
/*    1a694:	8c620014 */ 	lw	$v0,0x14($v1)
/*    1a698:	8c620004 */ 	lw	$v0,0x4($v1)
.L0001a69c:
/*    1a69c:	8459000e */ 	lh	$t9,0xe($v0)
/*    1a6a0:	10b90007 */ 	beq	$a1,$t9,.L0001a6c0
/*    1a6a4:	00000000 */ 	nop
/*    1a6a8:	84480010 */ 	lh	$t0,0x10($v0)
/*    1a6ac:	10a80004 */ 	beq	$a1,$t0,.L0001a6c0
/*    1a6b0:	00000000 */ 	nop
/*    1a6b4:	84490012 */ 	lh	$t1,0x12($v0)
/*    1a6b8:	14a90003 */ 	bne	$a1,$t1,.L0001a6c8
/*    1a6bc:	00000000 */ 	nop
.L0001a6c0:
/*    1a6c0:	03e00008 */ 	jr	$ra
/*    1a6c4:	00601025 */ 	or	$v0,$v1,$zero
.L0001a6c8:
/*    1a6c8:	10000008 */ 	b	.L0001a6ec
/*    1a6cc:	8c620014 */ 	lw	$v0,0x14($v1)
/*    1a6d0:	8c620004 */ 	lw	$v0,0x4($v1)
.L0001a6d4:
/*    1a6d4:	844a000c */ 	lh	$t2,0xc($v0)
/*    1a6d8:	54aa0004 */ 	bnel	$a1,$t2,.L0001a6ec
/*    1a6dc:	8c620014 */ 	lw	$v0,0x14($v1)
/*    1a6e0:	03e00008 */ 	jr	$ra
/*    1a6e4:	00601025 */ 	or	$v0,$v1,$zero
/*    1a6e8:	8c620014 */ 	lw	$v0,0x14($v1)
.L0001a6ec:
/*    1a6ec:	10400003 */ 	beqz	$v0,.L0001a6fc
/*    1a6f0:	00000000 */ 	nop
/*    1a6f4:	1000000d */ 	b	.L0001a72c
/*    1a6f8:	00401825 */ 	or	$v1,$v0,$zero
.L0001a6fc:
/*    1a6fc:	1060000b */ 	beqz	$v1,.L0001a72c
/*    1a700:	00000000 */ 	nop
.L0001a704:
/*    1a704:	50600007 */ 	beqzl	$v1,.L0001a724
/*    1a708:	8c630008 */ 	lw	$v1,0x8($v1)
/*    1a70c:	8c62000c */ 	lw	$v0,0xc($v1)
/*    1a710:	50400004 */ 	beqzl	$v0,.L0001a724
/*    1a714:	8c630008 */ 	lw	$v1,0x8($v1)
/*    1a718:	10000004 */ 	b	.L0001a72c
/*    1a71c:	00401825 */ 	or	$v1,$v0,$zero
/*    1a720:	8c630008 */ 	lw	$v1,0x8($v1)
.L0001a724:
/*    1a724:	1460fff7 */ 	bnez	$v1,.L0001a704
/*    1a728:	00000000 */ 	nop
.L0001a72c:
/*    1a72c:	5460ffc9 */ 	bnezl	$v1,.L0001a654
/*    1a730:	94620000 */ 	lhu	$v0,0x0($v1)
/*    1a734:	00001025 */ 	or	$v0,$zero,$zero
.L0001a738:
/*    1a738:	03e00008 */ 	jr	$ra
/*    1a73c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001a740
/*    1a740:	1080000e */ 	beqz	$a0,.L0001a77c
/*    1a744:	24060015 */ 	addiu	$a2,$zero,0x15
/*    1a748:	24050002 */ 	addiu	$a1,$zero,0x2
/*    1a74c:	24030001 */ 	addiu	$v1,$zero,0x1
/*    1a750:	94820000 */ 	lhu	$v0,0x0($a0)
.L0001a754:
/*    1a754:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1a758:	11c30008 */ 	beq	$t6,$v1,.L0001a77c
/*    1a75c:	00000000 */ 	nop
/*    1a760:	11c50006 */ 	beq	$t6,$a1,.L0001a77c
/*    1a764:	00000000 */ 	nop
/*    1a768:	11c60004 */ 	beq	$t6,$a2,.L0001a77c
/*    1a76c:	00000000 */ 	nop
/*    1a770:	8c840008 */ 	lw	$a0,0x8($a0)
/*    1a774:	5480fff7 */ 	bnezl	$a0,.L0001a754
/*    1a778:	94820000 */ 	lhu	$v0,0x0($a0)
.L0001a77c:
/*    1a77c:	03e00008 */ 	jr	$ra
/*    1a780:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0001a784
/*    1a784:	8c840008 */ 	lw	$a0,0x8($a0)
/*    1a788:	24060015 */ 	addiu	$a2,$zero,0x15
/*    1a78c:	24050002 */ 	addiu	$a1,$zero,0x2
/*    1a790:	1080000c */ 	beqz	$a0,.L0001a7c4
/*    1a794:	24030001 */ 	addiu	$v1,$zero,0x1
/*    1a798:	94820000 */ 	lhu	$v0,0x0($a0)
.L0001a79c:
/*    1a79c:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1a7a0:	11c30008 */ 	beq	$t6,$v1,.L0001a7c4
/*    1a7a4:	00000000 */ 	nop
/*    1a7a8:	11c50006 */ 	beq	$t6,$a1,.L0001a7c4
/*    1a7ac:	00000000 */ 	nop
/*    1a7b0:	11c60004 */ 	beq	$t6,$a2,.L0001a7c4
/*    1a7b4:	00000000 */ 	nop
/*    1a7b8:	8c840008 */ 	lw	$a0,0x8($a0)
/*    1a7bc:	5480fff7 */ 	bnezl	$a0,.L0001a79c
/*    1a7c0:	94820000 */ 	lhu	$v0,0x0($a0)
.L0001a7c4:
/*    1a7c4:	03e00008 */ 	jr	$ra
/*    1a7c8:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0001a7cc
/*    1a7cc:	8c830014 */ 	lw	$v1,0x14($a0)
/*    1a7d0:	24070015 */ 	addiu	$a3,$zero,0x15
/*    1a7d4:	24060002 */ 	addiu	$a2,$zero,0x2
/*    1a7d8:	1060001e */ 	beqz	$v1,.L0001a854
/*    1a7dc:	24050001 */ 	addiu	$a1,$zero,0x1
/*    1a7e0:	94620000 */ 	lhu	$v0,0x0($v1)
.L0001a7e4:
/*    1a7e4:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1a7e8:	11c5001a */ 	beq	$t6,$a1,.L0001a854
/*    1a7ec:	00000000 */ 	nop
/*    1a7f0:	11c60018 */ 	beq	$t6,$a2,.L0001a854
/*    1a7f4:	00000000 */ 	nop
/*    1a7f8:	11c70016 */ 	beq	$t6,$a3,.L0001a854
/*    1a7fc:	00000000 */ 	nop
/*    1a800:	8c620014 */ 	lw	$v0,0x14($v1)
/*    1a804:	10400003 */ 	beqz	$v0,.L0001a814
/*    1a808:	00000000 */ 	nop
/*    1a80c:	1000000f */ 	b	.L0001a84c
/*    1a810:	00401825 */ 	or	$v1,$v0,$zero
.L0001a814:
/*    1a814:	1060000d */ 	beqz	$v1,.L0001a84c
/*    1a818:	00000000 */ 	nop
.L0001a81c:
/*    1a81c:	54640004 */ 	bnel	$v1,$a0,.L0001a830
/*    1a820:	8c62000c */ 	lw	$v0,0xc($v1)
/*    1a824:	10000009 */ 	b	.L0001a84c
/*    1a828:	00001825 */ 	or	$v1,$zero,$zero
/*    1a82c:	8c62000c */ 	lw	$v0,0xc($v1)
.L0001a830:
/*    1a830:	50400004 */ 	beqzl	$v0,.L0001a844
/*    1a834:	8c630008 */ 	lw	$v1,0x8($v1)
/*    1a838:	10000004 */ 	b	.L0001a84c
/*    1a83c:	00401825 */ 	or	$v1,$v0,$zero
/*    1a840:	8c630008 */ 	lw	$v1,0x8($v1)
.L0001a844:
/*    1a844:	1460fff5 */ 	bnez	$v1,.L0001a81c
/*    1a848:	00000000 */ 	nop
.L0001a84c:
/*    1a84c:	5460ffe5 */ 	bnezl	$v1,.L0001a7e4
/*    1a850:	94620000 */ 	lhu	$v0,0x0($v1)
.L0001a854:
/*    1a854:	03e00008 */ 	jr	$ra
/*    1a858:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0001a85c
/*    1a85c:	1080002d */ 	beqz	$a0,.L0001a914
/*    1a860:	00801825 */ 	or	$v1,$a0,$zero
/*    1a864:	24070015 */ 	addiu	$a3,$zero,0x15
/*    1a868:	24060002 */ 	addiu	$a2,$zero,0x2
/*    1a86c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0001a870:
/*    1a870:	10640006 */ 	beq	$v1,$a0,.L0001a88c
/*    1a874:	00000000 */ 	nop
/*    1a878:	8c620014 */ 	lw	$v0,0x14($v1)
/*    1a87c:	10400003 */ 	beqz	$v0,.L0001a88c
/*    1a880:	00000000 */ 	nop
/*    1a884:	10000019 */ 	b	.L0001a8ec
/*    1a888:	00401825 */ 	or	$v1,$v0,$zero
.L0001a88c:
/*    1a88c:	10600015 */ 	beqz	$v1,.L0001a8e4
/*    1a890:	00000000 */ 	nop
.L0001a894:
/*    1a894:	5064000c */ 	beql	$v1,$a0,.L0001a8c8
/*    1a898:	8c62000c */ 	lw	$v0,0xc($v1)
/*    1a89c:	94620000 */ 	lhu	$v0,0x0($v1)
/*    1a8a0:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1a8a4:	11c50005 */ 	beq	$t6,$a1,.L0001a8bc
/*    1a8a8:	00000000 */ 	nop
/*    1a8ac:	11c60003 */ 	beq	$t6,$a2,.L0001a8bc
/*    1a8b0:	00000000 */ 	nop
/*    1a8b4:	55c70004 */ 	bnel	$t6,$a3,.L0001a8c8
/*    1a8b8:	8c62000c */ 	lw	$v0,0xc($v1)
.L0001a8bc:
/*    1a8bc:	10000009 */ 	b	.L0001a8e4
/*    1a8c0:	00001825 */ 	or	$v1,$zero,$zero
/*    1a8c4:	8c62000c */ 	lw	$v0,0xc($v1)
.L0001a8c8:
/*    1a8c8:	50400004 */ 	beqzl	$v0,.L0001a8dc
/*    1a8cc:	8c630008 */ 	lw	$v1,0x8($v1)
/*    1a8d0:	10000004 */ 	b	.L0001a8e4
/*    1a8d4:	00401825 */ 	or	$v1,$v0,$zero
/*    1a8d8:	8c630008 */ 	lw	$v1,0x8($v1)
.L0001a8dc:
/*    1a8dc:	1460ffed */ 	bnez	$v1,.L0001a894
/*    1a8e0:	00000000 */ 	nop
.L0001a8e4:
/*    1a8e4:	1060000b */ 	beqz	$v1,.L0001a914
/*    1a8e8:	00000000 */ 	nop
.L0001a8ec:
/*    1a8ec:	94620000 */ 	lhu	$v0,0x0($v1)
/*    1a8f0:	304f00ff */ 	andi	$t7,$v0,0xff
/*    1a8f4:	11e50007 */ 	beq	$t7,$a1,.L0001a914
/*    1a8f8:	00000000 */ 	nop
/*    1a8fc:	11e60005 */ 	beq	$t7,$a2,.L0001a914
/*    1a900:	00000000 */ 	nop
/*    1a904:	11e70003 */ 	beq	$t7,$a3,.L0001a914
/*    1a908:	00000000 */ 	nop
/*    1a90c:	1460ffd8 */ 	bnez	$v1,.L0001a870
/*    1a910:	00000000 */ 	nop
.L0001a914:
/*    1a914:	03e00008 */ 	jr	$ra
/*    1a918:	00601025 */ 	or	$v0,$v1,$zero
);

struct modelnode *modelGetPart(struct model08 *model08, s32 partnum)
{
	s32 upper;
	s32 lower;
	u32 i;
	s16 *partnums;

	if (model08->numparts == 0) {
		return NULL;
	}

	partnums = (s16 *)&model08->parts[model08->numparts];
	lower = 0;
	upper = model08->numparts;

	while (upper >= lower) {
		i = (lower + upper) / 2;

		if (partnum == partnums[i]) {
			return model08->parts[i];
		}

		if (partnum < partnums[i]) {
			upper = i - 1;
		} else {
			lower = i + 1;
		}
	}

	return NULL;
}

GLOBAL_ASM(
glabel func0001a9bc
/*    1a9bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1a9c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1a9c4:	0c006a47 */ 	jal	modelGetPart
/*    1a9c8:	00000000 */ 	nop
/*    1a9cc:	10400003 */ 	beqz	$v0,.L0001a9dc
/*    1a9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1a9d4:	10000002 */ 	b	.L0001a9e0
/*    1a9d8:	8c420004 */ 	lw	$v0,0x4($v0)
.L0001a9dc:
/*    1a9dc:	00001025 */ 	or	$v0,$zero,$zero
.L0001a9e0:
/*    1a9e0:	03e00008 */ 	jr	$ra
/*    1a9e4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0001a9e8
/*    1a9e8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1a9ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1a9f0:	0c006983 */ 	jal	func0001a60c
/*    1a9f4:	00000000 */ 	nop
/*    1a9f8:	10400004 */ 	beqz	$v0,.L0001aa0c
/*    1a9fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1aa00:	c4400038 */ 	lwc1	$f0,0x38($v0)
/*    1aa04:	10000003 */ 	b	.L0001aa14
/*    1aa08:	46000007 */ 	neg.s	$f0,$f0
.L0001aa0c:
/*    1aa0c:	44800000 */ 	mtc1	$zero,$f0
/*    1aa10:	00000000 */ 	nop
.L0001aa14:
/*    1aa14:	03e00008 */ 	jr	$ra
/*    1aa18:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

void *modelGetNodeData(struct model *model, struct modelnode *node)
{
	u32 index = 0;
	void **datas = model->datas;

	switch (node->type & 0xff) {
	case MODELNODETYPE_ROOT:
		index = node->data.root->index;
		break;
	case MODELNODETYPE_DISPLAYLIST:
		index = node->data.displaylist->index;
		break;
	case MODELNODETYPE_NEARFAR:
		index = node->data.nearfar->index;
		break;
	case MODELNODETYPE_PARTID:
		index = node->data.partid->index;
		break;
	case MODELNODETYPE_HAT:
		index = node->data.hat->index;
		break;
	case MODELNODETYPE_0B:
		index = node->data.unk0b->index;
		break;
	case MODELNODETYPE_GUNFIRE:
		index = node->data.gunfire->index;
		break;
	case MODELNODETYPE_HEADSPOT:
		index = node->data.headspot->index;
		break;
	}

	while (node->relation) {
		node = node->relation;

		if ((node->type & 0xff) == MODELNODETYPE_HEADSPOT) {
			struct modeldata_headspot *tmp = modelGetNodeData(model, node);
			datas = tmp->datas;
			break;
		}
	}

	return &datas[index];
}

GLOBAL_ASM(
glabel func0001ab0c
/*    1ab0c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1ab10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1ab14:	94a20000 */ 	lhu	$v0,0x0($a1)
/*    1ab18:	24010001 */ 	addiu	$at,$zero,0x1
/*    1ab1c:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1ab20:	11c1000b */ 	beq	$t6,$at,.L0001ab50
/*    1ab24:	24010002 */ 	addiu	$at,$zero,0x2
/*    1ab28:	11c10013 */ 	beq	$t6,$at,.L0001ab78
/*    1ab2c:	24010015 */ 	addiu	$at,$zero,0x15
/*    1ab30:	51c1001a */ 	beql	$t6,$at,.L0001ab9c
/*    1ab34:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    1ab38:	44800000 */ 	mtc1	$zero,$f0
/*    1ab3c:	00000000 */ 	nop
/*    1ab40:	e4c00000 */ 	swc1	$f0,0x0($a2)
/*    1ab44:	e4c00004 */ 	swc1	$f0,0x4($a2)
/*    1ab48:	1000001a */ 	b	.L0001abb4
/*    1ab4c:	e4c00008 */ 	swc1	$f0,0x8($a2)
.L0001ab50:
/*    1ab50:	0c006a87 */ 	jal	modelGetNodeData
/*    1ab54:	afa60020 */ 	sw	$a2,0x20($sp)
/*    1ab58:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    1ab5c:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*    1ab60:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*    1ab64:	c446000c */ 	lwc1	$f6,0xc($v0)
/*    1ab68:	e4c60004 */ 	swc1	$f6,0x4($a2)
/*    1ab6c:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*    1ab70:	10000010 */ 	b	.L0001abb4
/*    1ab74:	e4c80008 */ 	swc1	$f8,0x8($a2)
.L0001ab78:
/*    1ab78:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    1ab7c:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*    1ab80:	e4ca0000 */ 	swc1	$f10,0x0($a2)
/*    1ab84:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*    1ab88:	e4d00004 */ 	swc1	$f16,0x4($a2)
/*    1ab8c:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*    1ab90:	10000008 */ 	b	.L0001abb4
/*    1ab94:	e4d20008 */ 	swc1	$f18,0x8($a2)
/*    1ab98:	8ca20004 */ 	lw	$v0,0x4($a1)
.L0001ab9c:
/*    1ab9c:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*    1aba0:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*    1aba4:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*    1aba8:	e4c60004 */ 	swc1	$f6,0x4($a2)
/*    1abac:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*    1abb0:	e4c80008 */ 	swc1	$f8,0x8($a2)
.L0001abb4:
/*    1abb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1abb8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1abbc:	03e00008 */ 	jr	$ra
/*    1abc0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001abc4
/*    1abc4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1abc8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1abcc:	94a20000 */ 	lhu	$v0,0x0($a1)
/*    1abd0:	24010001 */ 	addiu	$at,$zero,0x1
/*    1abd4:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1abd8:	11c10007 */ 	beq	$t6,$at,.L0001abf8
/*    1abdc:	24010002 */ 	addiu	$at,$zero,0x2
/*    1abe0:	11c10037 */ 	beq	$t6,$at,.L0001acc0
/*    1abe4:	24010015 */ 	addiu	$at,$zero,0x15
/*    1abe8:	51c1003e */ 	beql	$t6,$at,.L0001ace4
/*    1abec:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    1abf0:	10000043 */ 	b	.L0001ad00
/*    1abf4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001abf8:
/*    1abf8:	0c006a87 */ 	jal	modelGetNodeData
/*    1abfc:	afa60030 */ 	sw	$a2,0x30($sp)
/*    1ac00:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    1ac04:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*    1ac08:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*    1ac0c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    1ac10:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    1ac14:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*    1ac18:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*    1ac1c:	46105481 */ 	sub.s	$f18,$f10,$f16
/*    1ac20:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*    1ac24:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*    1ac28:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*    1ac2c:	e4440008 */ 	swc1	$f4,0x8($v0)
/*    1ac30:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*    1ac34:	c444002c */ 	lwc1	$f4,0x2c($v0)
/*    1ac38:	e446000c */ 	swc1	$f6,0xc($v0)
/*    1ac3c:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*    1ac40:	e4480010 */ 	swc1	$f8,0x10($v0)
/*    1ac44:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    1ac48:	46105480 */ 	add.s	$f18,$f10,$f16
/*    1ac4c:	c44a0034 */ 	lwc1	$f10,0x34($v0)
/*    1ac50:	e4520024 */ 	swc1	$f18,0x24($v0)
/*    1ac54:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    1ac58:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1ac5c:	c444003c */ 	lwc1	$f4,0x3c($v0)
/*    1ac60:	e448002c */ 	swc1	$f8,0x2c($v0)
/*    1ac64:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    1ac68:	46105480 */ 	add.s	$f18,$f10,$f16
/*    1ac6c:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*    1ac70:	e4520034 */ 	swc1	$f18,0x34($v0)
/*    1ac74:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    1ac78:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1ac7c:	c4440048 */ 	lwc1	$f4,0x48($v0)
/*    1ac80:	e448003c */ 	swc1	$f8,0x3c($v0)
/*    1ac84:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    1ac88:	46105480 */ 	add.s	$f18,$f10,$f16
/*    1ac8c:	c44a004c */ 	lwc1	$f10,0x4c($v0)
/*    1ac90:	e4520040 */ 	swc1	$f18,0x40($v0)
/*    1ac94:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    1ac98:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1ac9c:	c4440054 */ 	lwc1	$f4,0x54($v0)
/*    1aca0:	e4480048 */ 	swc1	$f8,0x48($v0)
/*    1aca4:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    1aca8:	46105480 */ 	add.s	$f18,$f10,$f16
/*    1acac:	e452004c */ 	swc1	$f18,0x4c($v0)
/*    1acb0:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    1acb4:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1acb8:	10000010 */ 	b	.L0001acfc
/*    1acbc:	e4480054 */ 	swc1	$f8,0x54($v0)
.L0001acc0:
/*    1acc0:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    1acc4:	c4ca0000 */ 	lwc1	$f10,0x0($a2)
/*    1acc8:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*    1accc:	c4d00004 */ 	lwc1	$f16,0x4($a2)
/*    1acd0:	e4500004 */ 	swc1	$f16,0x4($v0)
/*    1acd4:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*    1acd8:	10000008 */ 	b	.L0001acfc
/*    1acdc:	e4520008 */ 	swc1	$f18,0x8($v0)
/*    1ace0:	8ca20004 */ 	lw	$v0,0x4($a1)
.L0001ace4:
/*    1ace4:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*    1ace8:	e4440000 */ 	swc1	$f4,0x0($v0)
/*    1acec:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*    1acf0:	e4460004 */ 	swc1	$f6,0x4($v0)
/*    1acf4:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*    1acf8:	e4480008 */ 	swc1	$f8,0x8($v0)
.L0001acfc:
/*    1acfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001ad00:
/*    1ad00:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    1ad04:	03e00008 */ 	jr	$ra
/*    1ad08:	00000000 */ 	nop
);

void func0001ad0c(struct model *model, struct coord *coord)
{
	func0001ab0c(model, model->unk08->rootnode, coord);
}

void func0001ad34(struct model *model, struct coord *coord)
{
	func0001abc4(model, model->unk08->rootnode, coord);
}

GLOBAL_ASM(
glabel func0001ad5c
/*    1ad5c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    1ad60:	44800000 */ 	mtc1	$zero,$f0
/*    1ad64:	afb20020 */ 	sw	$s2,0x20($sp)
/*    1ad68:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    1ad6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1ad70:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    1ad74:	afb60030 */ 	sw	$s6,0x30($sp)
/*    1ad78:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    1ad7c:	afb40028 */ 	sw	$s4,0x28($sp)
/*    1ad80:	afb30024 */ 	sw	$s3,0x24($sp)
/*    1ad84:	00c08025 */ 	or	$s0,$a2,$zero
/*    1ad88:	00a08825 */ 	or	$s1,$a1,$zero
/*    1ad8c:	00809025 */ 	or	$s2,$a0,$zero
/*    1ad90:	e4c00000 */ 	swc1	$f0,0x0($a2)
/*    1ad94:	e4c00004 */ 	swc1	$f0,0x4($a2)
/*    1ad98:	10a00020 */ 	beqz	$a1,.L0001ae1c
/*    1ad9c:	e4c00008 */ 	swc1	$f0,0x8($a2)
/*    1ada0:	27b6003c */ 	addiu	$s6,$sp,0x3c
/*    1ada4:	24150015 */ 	addiu	$s5,$zero,0x15
/*    1ada8:	24140002 */ 	addiu	$s4,$zero,0x2
/*    1adac:	24130001 */ 	addiu	$s3,$zero,0x1
/*    1adb0:	96220000 */ 	lhu	$v0,0x0($s1)
.L0001adb4:
/*    1adb4:	02402025 */ 	or	$a0,$s2,$zero
/*    1adb8:	02202825 */ 	or	$a1,$s1,$zero
/*    1adbc:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1adc0:	11d30005 */ 	beq	$t6,$s3,.L0001add8
/*    1adc4:	00000000 */ 	nop
/*    1adc8:	11d40003 */ 	beq	$t6,$s4,.L0001add8
/*    1adcc:	00000000 */ 	nop
/*    1add0:	55d50010 */ 	bnel	$t6,$s5,.L0001ae14
/*    1add4:	8e310008 */ 	lw	$s1,0x8($s1)
.L0001add8:
/*    1add8:	0c006ac3 */ 	jal	func0001ab0c
/*    1addc:	02c03025 */ 	or	$a2,$s6,$zero
/*    1ade0:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*    1ade4:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    1ade8:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*    1adec:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1adf0:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*    1adf4:	e6080000 */ 	swc1	$f8,0x0($s0)
/*    1adf8:	c7b00040 */ 	lwc1	$f16,0x40($sp)
/*    1adfc:	46105480 */ 	add.s	$f18,$f10,$f16
/*    1ae00:	e6120004 */ 	swc1	$f18,0x4($s0)
/*    1ae04:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*    1ae08:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1ae0c:	e6080008 */ 	swc1	$f8,0x8($s0)
/*    1ae10:	8e310008 */ 	lw	$s1,0x8($s1)
.L0001ae14:
/*    1ae14:	5620ffe7 */ 	bnezl	$s1,.L0001adb4
/*    1ae18:	96220000 */ 	lhu	$v0,0x0($s1)
.L0001ae1c:
/*    1ae1c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    1ae20:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1ae24:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    1ae28:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    1ae2c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    1ae30:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    1ae34:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    1ae38:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    1ae3c:	03e00008 */ 	jr	$ra
/*    1ae40:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0001ae44
/*    1ae44:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1ae48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1ae4c:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    1ae50:	24010001 */ 	addiu	$at,$zero,0x1
/*    1ae54:	8dc50000 */ 	lw	$a1,0x0($t6)
/*    1ae58:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    1ae5c:	31f800ff */ 	andi	$t8,$t7,0xff
/*    1ae60:	57010006 */ 	bnel	$t8,$at,.L0001ae7c
/*    1ae64:	44800000 */ 	mtc1	$zero,$f0
/*    1ae68:	0c006a87 */ 	jal	modelGetNodeData
/*    1ae6c:	00000000 */ 	nop
/*    1ae70:	10000003 */ 	b	.L0001ae80
/*    1ae74:	c4400014 */ 	lwc1	$f0,0x14($v0)
/*    1ae78:	44800000 */ 	mtc1	$zero,$f0
.L0001ae7c:
/*    1ae7c:	00000000 */ 	nop
.L0001ae80:
/*    1ae80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1ae84:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1ae88:	03e00008 */ 	jr	$ra
/*    1ae8c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001ae90
.late_rodata
glabel var700542e0
.word 0x40c907a9
glabel var700542e4
.word 0x40c907a9
.text
/*    1ae90:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1ae94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1ae98:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    1ae9c:	44857000 */ 	mtc1	$a1,$f14
/*    1aea0:	24010001 */ 	addiu	$at,$zero,0x1
/*    1aea4:	8dc50000 */ 	lw	$a1,0x0($t6)
/*    1aea8:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    1aeac:	31f800ff */ 	andi	$t8,$t7,0xff
/*    1aeb0:	57010026 */ 	bnel	$t8,$at,.L0001af4c
/*    1aeb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1aeb8:	0c006a87 */ 	jal	modelGetNodeData
/*    1aebc:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*    1aec0:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*    1aec4:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*    1aec8:	44803000 */ 	mtc1	$zero,$f6
/*    1aecc:	3c017005 */ 	lui	$at,%hi(var700542e0)
/*    1aed0:	46047001 */ 	sub.s	$f0,$f14,$f4
/*    1aed4:	4606003c */ 	c.lt.s	$f0,$f6
/*    1aed8:	00000000 */ 	nop
/*    1aedc:	45020004 */ 	bc1fl	.L0001aef0
/*    1aee0:	c4480030 */ 	lwc1	$f8,0x30($v0)
/*    1aee4:	c42c42e0 */ 	lwc1	$f12,%lo(var700542e0)($at)
/*    1aee8:	460c0000 */ 	add.s	$f0,$f0,$f12
/*    1aeec:	c4480030 */ 	lwc1	$f8,0x30($v0)
.L0001aef0:
/*    1aef0:	3c017005 */ 	lui	$at,%hi(var700542e4)
/*    1aef4:	c42c42e4 */ 	lwc1	$f12,%lo(var700542e4)($at)
/*    1aef8:	46004280 */ 	add.s	$f10,$f8,$f0
/*    1aefc:	e44a0030 */ 	swc1	$f10,0x30($v0)
/*    1af00:	c4420030 */ 	lwc1	$f2,0x30($v0)
/*    1af04:	4602603e */ 	c.le.s	$f12,$f2
/*    1af08:	00000000 */ 	nop
/*    1af0c:	45020004 */ 	bc1fl	.L0001af20
/*    1af10:	c4520020 */ 	lwc1	$f18,0x20($v0)
/*    1af14:	460c1401 */ 	sub.s	$f16,$f2,$f12
/*    1af18:	e4500030 */ 	swc1	$f16,0x30($v0)
/*    1af1c:	c4520020 */ 	lwc1	$f18,0x20($v0)
.L0001af20:
/*    1af20:	46009100 */ 	add.s	$f4,$f18,$f0
/*    1af24:	e4440020 */ 	swc1	$f4,0x20($v0)
/*    1af28:	c4420020 */ 	lwc1	$f2,0x20($v0)
/*    1af2c:	4602603e */ 	c.le.s	$f12,$f2
/*    1af30:	00000000 */ 	nop
/*    1af34:	45020004 */ 	bc1fl	.L0001af48
/*    1af38:	e44e0014 */ 	swc1	$f14,0x14($v0)
/*    1af3c:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*    1af40:	e4460020 */ 	swc1	$f6,0x20($v0)
/*    1af44:	e44e0014 */ 	swc1	$f14,0x14($v0)
.L0001af48:
/*    1af48:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001af4c:
/*    1af4c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1af50:	03e00008 */ 	jr	$ra
/*    1af54:	00000000 */ 	nop
);

void modelSetUnk14(struct model *model, f32 arg1)
{
	model->unk14 = arg1;
}

void modelSetAnimScale(struct model *model, f32 scale)
{
	if (model->anim) {
		model->anim->animscale = scale;
	}
}

f32 func0001af80(struct model *model)
{
	return model->unk08->unk10 * model->unk14;
}

GLOBAL_ASM(
glabel func0001af98
/*    1af98:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*    1af9c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    1afa0:	44866000 */ 	mtc1	$a2,$f12
/*    1afa4:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*    1afa8:	46002181 */ 	sub.s	$f6,$f4,$f0
/*    1afac:	c48e0008 */ 	lwc1	$f14,0x8($a0)
/*    1afb0:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*    1afb4:	46080280 */ 	add.s	$f10,$f0,$f8
/*    1afb8:	e48a0000 */ 	swc1	$f10,0x0($a0)
/*    1afbc:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*    1afc0:	46028481 */ 	sub.s	$f18,$f16,$f2
/*    1afc4:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*    1afc8:	46041180 */ 	add.s	$f6,$f2,$f4
/*    1afcc:	e4860004 */ 	swc1	$f6,0x4($a0)
/*    1afd0:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    1afd4:	460e4281 */ 	sub.s	$f10,$f8,$f14
/*    1afd8:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*    1afdc:	46107480 */ 	add.s	$f18,$f14,$f16
/*    1afe0:	03e00008 */ 	jr	$ra
/*    1afe4:	e4920008 */ 	swc1	$f18,0x8($a0)
);

GLOBAL_ASM(
glabel func0001afe8
.late_rodata
glabel var700542e8
.word 0x40c907a9
glabel var700542ec
.word 0x40c907a9
glabel var700542f0
.word 0x40490fdb
.text
/*    1afe8:	460c703c */ 	c.lt.s	$f14,$f12
/*    1afec:	afa60008 */ 	sw	$a2,0x8($sp)
/*    1aff0:	460c7081 */ 	sub.s	$f2,$f14,$f12
/*    1aff4:	3c017005 */ 	lui	$at,%hi(var700542e8)
/*    1aff8:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*    1affc:	45000003 */ 	bc1f	.L0001b00c
/*    1b000:	46001006 */ 	mov.s	$f0,$f2
/*    1b004:	c42e42e8 */ 	lwc1	$f14,%lo(var700542e8)($at)
/*    1b008:	460e1000 */ 	add.s	$f0,$f2,$f14
.L0001b00c:
/*    1b00c:	3c017005 */ 	lui	$at,%hi(var700542ec)
/*    1b010:	c42e42ec */ 	lwc1	$f14,%lo(var700542ec)($at)
/*    1b014:	3c017005 */ 	lui	$at,%hi(var700542f0)
/*    1b018:	c42442f0 */ 	lwc1	$f4,%lo(var700542f0)($at)
/*    1b01c:	4604003c */ 	c.lt.s	$f0,$f4
/*    1b020:	00000000 */ 	nop
/*    1b024:	4502000a */ 	bc1fl	.L0001b050
/*    1b028:	46007281 */ 	sub.s	$f10,$f14,$f0
/*    1b02c:	46060202 */ 	mul.s	$f8,$f0,$f6
/*    1b030:	46086300 */ 	add.s	$f12,$f12,$f8
/*    1b034:	460c703e */ 	c.le.s	$f14,$f12
/*    1b038:	00000000 */ 	nop
/*    1b03c:	4500000d */ 	bc1f	.L0001b074
/*    1b040:	00000000 */ 	nop
/*    1b044:	03e00008 */ 	jr	$ra
/*    1b048:	460e6001 */ 	sub.s	$f0,$f12,$f14
/*    1b04c:	46007281 */ 	sub.s	$f10,$f14,$f0
.L0001b050:
/*    1b050:	c7b00008 */ 	lwc1	$f16,0x8($sp)
/*    1b054:	44802000 */ 	mtc1	$zero,$f4
/*    1b058:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1b05c:	46126301 */ 	sub.s	$f12,$f12,$f18
/*    1b060:	4604603c */ 	c.lt.s	$f12,$f4
/*    1b064:	00000000 */ 	nop
/*    1b068:	45000002 */ 	bc1f	.L0001b074
/*    1b06c:	00000000 */ 	nop
/*    1b070:	460e6300 */ 	add.s	$f12,$f12,$f14
.L0001b074:
/*    1b074:	03e00008 */ 	jr	$ra
/*    1b078:	46006006 */ 	mov.s	$f0,$f12
);

GLOBAL_ASM(
glabel func0001b07c
/*    1b07c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1b080:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1b084:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1b088:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1b08c:	afa60028 */ 	sw	$a2,0x28($sp)
/*    1b090:	00808025 */ 	or	$s0,$a0,$zero
/*    1b094:	c4ae0000 */ 	lwc1	$f14,0x0($a1)
/*    1b098:	0c006bfa */ 	jal	func0001afe8
/*    1b09c:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*    1b0a0:	e6000000 */ 	swc1	$f0,0x0($s0)
/*    1b0a4:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    1b0a8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    1b0ac:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*    1b0b0:	0c006bfa */ 	jal	func0001afe8
/*    1b0b4:	c5ee0004 */ 	lwc1	$f14,0x4($t7)
/*    1b0b8:	e6000004 */ 	swc1	$f0,0x4($s0)
/*    1b0bc:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    1b0c0:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    1b0c4:	c60c0008 */ 	lwc1	$f12,0x8($s0)
/*    1b0c8:	0c006bfa */ 	jal	func0001afe8
/*    1b0cc:	c70e0008 */ 	lwc1	$f14,0x8($t8)
/*    1b0d0:	e6000008 */ 	swc1	$f0,0x8($s0)
/*    1b0d4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1b0d8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1b0dc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1b0e0:	03e00008 */ 	jr	$ra
/*    1b0e4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001b0e8
/*    1b0e8:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    1b0ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1b0f0:	8c880020 */ 	lw	$t0,0x20($a0)
/*    1b0f4:	510000ae */ 	beqzl	$t0,.L0001b3b0
/*    1b0f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1b0fc:	afa40048 */ 	sw	$a0,0x48($sp)
/*    1b100:	0c006a87 */ 	jal	modelGetNodeData
/*    1b104:	afa80040 */ 	sw	$t0,0x40($sp)
/*    1b108:	804e0000 */ 	lb	$t6,0x0($v0)
/*    1b10c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    1b110:	00401825 */ 	or	$v1,$v0,$zero
/*    1b114:	55c000a6 */ 	bnezl	$t6,.L0001b3b0
/*    1b118:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1b11c:	c4440034 */ 	lwc1	$f4,0x34($v0)
/*    1b120:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x4cc)
/*    1b124:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*    1b128:	c4460038 */ 	lwc1	$f6,0x38($v0)
/*    1b12c:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*    1b130:	c448003c */ 	lwc1	$f8,0x3c($v0)
/*    1b134:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*    1b138:	c44a0030 */ 	lwc1	$f10,0x30($v0)
/*    1b13c:	e44a0014 */ 	swc1	$f10,0x14($v0)
/*    1b140:	8defa48c */ 	lw	$t7,%lo(g_Vars+0x4cc)($t7)
/*    1b144:	51e00014 */ 	beqzl	$t7,.L0001b198
/*    1b148:	c5020010 */ 	lwc1	$f2,0x10($t0)
/*    1b14c:	c500001c */ 	lwc1	$f0,0x1c($t0)
/*    1b150:	44808000 */ 	mtc1	$zero,$f16
/*    1b154:	00000000 */ 	nop
/*    1b158:	4600803c */ 	c.lt.s	$f16,$f0
/*    1b15c:	00000000 */ 	nop
/*    1b160:	4502000d */ 	bc1fl	.L0001b198
/*    1b164:	c5020010 */ 	lwc1	$f2,0x10($t0)
/*    1b168:	c5120010 */ 	lwc1	$f18,0x10($t0)
/*    1b16c:	afa80040 */ 	sw	$t0,0x40($sp)
/*    1b170:	afa20044 */ 	sw	$v0,0x44($sp)
/*    1b174:	0fc25e24 */ 	jal	floorf
/*    1b178:	46009303 */ 	div.s	$f12,$f18,$f0
/*    1b17c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    1b180:	8fa30044 */ 	lw	$v1,0x44($sp)
/*    1b184:	c504001c */ 	lwc1	$f4,0x1c($t0)
/*    1b188:	46040082 */ 	mul.s	$f2,$f0,$f4
/*    1b18c:	10000003 */ 	b	.L0001b19c
/*    1b190:	44803000 */ 	mtc1	$zero,$f6
/*    1b194:	c5020010 */ 	lwc1	$f2,0x10($t0)
.L0001b198:
/*    1b198:	44803000 */ 	mtc1	$zero,$f6
.L0001b19c:
/*    1b19c:	00000000 */ 	nop
/*    1b1a0:	46061032 */ 	c.eq.s	$f2,$f6
/*    1b1a4:	00000000 */ 	nop
/*    1b1a8:	45030015 */ 	bc1tl	.L0001b200
/*    1b1ac:	85190002 */ 	lh	$t9,0x2($t0)
/*    1b1b0:	80780001 */ 	lb	$t8,0x1($v1)
/*    1b1b4:	27a40034 */ 	addiu	$a0,$sp,0x34
/*    1b1b8:	24650024 */ 	addiu	$a1,$v1,0x24
/*    1b1bc:	53000010 */ 	beqzl	$t8,.L0001b200
/*    1b1c0:	85190002 */ 	lh	$t9,0x2($t0)
/*    1b1c4:	44061000 */ 	mfc1	$a2,$f2
/*    1b1c8:	afa30044 */ 	sw	$v1,0x44($sp)
/*    1b1cc:	afa80040 */ 	sw	$t0,0x40($sp)
/*    1b1d0:	0c006be6 */ 	jal	func0001af98
/*    1b1d4:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*    1b1d8:	c7a20024 */ 	lwc1	$f2,0x24($sp)
/*    1b1dc:	8fa30044 */ 	lw	$v1,0x44($sp)
/*    1b1e0:	44061000 */ 	mfc1	$a2,$f2
/*    1b1e4:	c46c0030 */ 	lwc1	$f12,0x30($v1)
/*    1b1e8:	0c006bfa */ 	jal	func0001afe8
/*    1b1ec:	c46e0020 */ 	lwc1	$f14,0x20($v1)
/*    1b1f0:	8fa30044 */ 	lw	$v1,0x44($sp)
/*    1b1f4:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    1b1f8:	e4600014 */ 	swc1	$f0,0x14($v1)
/*    1b1fc:	85190002 */ 	lh	$t9,0x2($t0)
.L0001b200:
/*    1b200:	24650008 */ 	addiu	$a1,$v1,0x8
/*    1b204:	57200008 */ 	bnezl	$t9,.L0001b228
/*    1b208:	80690002 */ 	lb	$t1,0x2($v1)
/*    1b20c:	44804000 */ 	mtc1	$zero,$f8
/*    1b210:	c50a0054 */ 	lwc1	$f10,0x54($t0)
/*    1b214:	460a4032 */ 	c.eq.s	$f8,$f10
/*    1b218:	00000000 */ 	nop
/*    1b21c:	45030016 */ 	bc1tl	.L0001b278
/*    1b220:	8d0a0070 */ 	lw	$t2,0x70($t0)
/*    1b224:	80690002 */ 	lb	$t1,0x2($v1)
.L0001b228:
/*    1b228:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*    1b22c:	51200012 */ 	beqzl	$t1,.L0001b278
/*    1b230:	8d0a0070 */ 	lw	$t2,0x70($t0)
/*    1b234:	c5020034 */ 	lwc1	$f2,0x34($t0)
/*    1b238:	44808000 */ 	mtc1	$zero,$f16
/*    1b23c:	c4600050 */ 	lwc1	$f0,0x50($v1)
/*    1b240:	c50c0054 */ 	lwc1	$f12,0x54($t0)
/*    1b244:	46028032 */ 	c.eq.s	$f16,$f2
/*    1b248:	00000000 */ 	nop
/*    1b24c:	45030006 */ 	bc1tl	.L0001b268
/*    1b250:	46080281 */ 	sub.s	$f10,$f0,$f8
/*    1b254:	c4720044 */ 	lwc1	$f18,0x44($v1)
/*    1b258:	46009101 */ 	sub.s	$f4,$f18,$f0
/*    1b25c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*    1b260:	46060000 */ 	add.s	$f0,$f0,$f6
/*    1b264:	46080281 */ 	sub.s	$f10,$f0,$f8
.L0001b268:
/*    1b268:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*    1b26c:	46104480 */ 	add.s	$f18,$f8,$f16
/*    1b270:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*    1b274:	8d0a0070 */ 	lw	$t2,0x70($t0)
.L0001b278:
/*    1b278:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*    1b27c:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*    1b280:	5540000a */ 	bnezl	$t2,.L0001b2ac
/*    1b284:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    1b288:	e4640008 */ 	swc1	$f4,0x8($v1)
/*    1b28c:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    1b290:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*    1b294:	460a3200 */ 	add.s	$f8,$f6,$f10
/*    1b298:	e468000c */ 	swc1	$f8,0xc($v1)
/*    1b29c:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*    1b2a0:	10000042 */ 	b	.L0001b3ac
/*    1b2a4:	e4700010 */ 	swc1	$f16,0x10($v1)
/*    1b2a8:	c7a40038 */ 	lwc1	$f4,0x38($sp)
.L0001b2ac:
/*    1b2ac:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    1b2b0:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*    1b2b4:	afa30044 */ 	sw	$v1,0x44($sp)
/*    1b2b8:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*    1b2bc:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*    1b2c0:	8d190070 */ 	lw	$t9,0x70($t0)
/*    1b2c4:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    1b2c8:	27a60028 */ 	addiu	$a2,$sp,0x28
/*    1b2cc:	0320f809 */ 	jalr	$t9
/*    1b2d0:	24670004 */ 	addiu	$a3,$v1,0x4
/*    1b2d4:	10400035 */ 	beqz	$v0,.L0001b3ac
/*    1b2d8:	8fa30044 */ 	lw	$v1,0x44($sp)
/*    1b2dc:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*    1b2e0:	c4700004 */ 	lwc1	$f16,0x4($v1)
/*    1b2e4:	e46a0008 */ 	swc1	$f10,0x8($v1)
/*    1b2e8:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*    1b2ec:	46104480 */ 	add.s	$f18,$f8,$f16
/*    1b2f0:	e472000c */ 	swc1	$f18,0xc($v1)
/*    1b2f4:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*    1b2f8:	e4640010 */ 	swc1	$f4,0x10($v1)
/*    1b2fc:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*    1b300:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*    1b304:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*    1b308:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*    1b30c:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*    1b310:	46128101 */ 	sub.s	$f4,$f16,$f18
/*    1b314:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*    1b318:	e7a4003c */ 	swc1	$f4,0x3c($sp)
/*    1b31c:	c4660034 */ 	lwc1	$f6,0x34($v1)
/*    1b320:	c470003c */ 	lwc1	$f16,0x3c($v1)
/*    1b324:	806b0001 */ 	lb	$t3,0x1($v1)
/*    1b328:	46083280 */ 	add.s	$f10,$f6,$f8
/*    1b32c:	e46a0034 */ 	swc1	$f10,0x34($v1)
/*    1b330:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*    1b334:	46128100 */ 	add.s	$f4,$f16,$f18
/*    1b338:	11600009 */ 	beqz	$t3,.L0001b360
/*    1b33c:	e464003c */ 	swc1	$f4,0x3c($v1)
/*    1b340:	c4660024 */ 	lwc1	$f6,0x24($v1)
/*    1b344:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*    1b348:	c470002c */ 	lwc1	$f16,0x2c($v1)
/*    1b34c:	46083280 */ 	add.s	$f10,$f6,$f8
/*    1b350:	e46a0024 */ 	swc1	$f10,0x24($v1)
/*    1b354:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*    1b358:	46128100 */ 	add.s	$f4,$f16,$f18
/*    1b35c:	e464002c */ 	swc1	$f4,0x2c($v1)
.L0001b360:
/*    1b360:	806c0002 */ 	lb	$t4,0x2($v1)
/*    1b364:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*    1b368:	51800011 */ 	beqzl	$t4,.L0001b3b0
/*    1b36c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1b370:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*    1b374:	c4700054 */ 	lwc1	$f16,0x54($v1)
/*    1b378:	46083280 */ 	add.s	$f10,$f6,$f8
/*    1b37c:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*    1b380:	e46a004c */ 	swc1	$f10,0x4c($v1)
/*    1b384:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*    1b388:	46128100 */ 	add.s	$f4,$f16,$f18
/*    1b38c:	c4700048 */ 	lwc1	$f16,0x48($v1)
/*    1b390:	e4640054 */ 	swc1	$f4,0x54($v1)
/*    1b394:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*    1b398:	46083280 */ 	add.s	$f10,$f6,$f8
/*    1b39c:	e46a0040 */ 	swc1	$f10,0x40($v1)
/*    1b3a0:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*    1b3a4:	46128100 */ 	add.s	$f4,$f16,$f18
/*    1b3a8:	e4640048 */ 	swc1	$f4,0x48($v1)
.L0001b3ac:
/*    1b3ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001b3b0:
/*    1b3b0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    1b3b4:	03e00008 */ 	jr	$ra
/*    1b3b8:	00000000 */ 	nop
);

void func0001b3bc(struct model *model)
{
	struct modelnode *node = model->unk08->rootnode;

	if (node && (node->type & 0xff) == MODELNODETYPE_ROOT) {
		func0001b0e8(model, node);
	}
}

GLOBAL_ASM(
glabel func0001b400
/*    1b400:	27bdfd98 */ 	addiu	$sp,$sp,-616
/*    1b404:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    1b408:	afb00028 */ 	sw	$s0,0x28($sp)
/*    1b40c:	afa40268 */ 	sw	$a0,0x268($sp)
/*    1b410:	8cb00020 */ 	lw	$s0,0x20($a1)
/*    1b414:	8cc80004 */ 	lw	$t0,0x4($a2)
/*    1b418:	00a03825 */ 	or	$a3,$a1,$zero
/*    1b41c:	00a02025 */ 	or	$a0,$a1,$zero
/*    1b420:	00c02825 */ 	or	$a1,$a2,$zero
/*    1b424:	afa7026c */ 	sw	$a3,0x26c($sp)
/*    1b428:	afa60270 */ 	sw	$a2,0x270($sp)
/*    1b42c:	0c006a87 */ 	jal	modelGetNodeData
/*    1b430:	afa80260 */ 	sw	$t0,0x260($sp)
/*    1b434:	8fa7026c */ 	lw	$a3,0x26c($sp)
/*    1b438:	afa2025c */ 	sw	$v0,0x25c($sp)
/*    1b43c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    1b440:	c4e40014 */ 	lwc1	$f4,0x14($a3)
/*    1b444:	afae0254 */ 	sw	$t6,0x254($sp)
/*    1b448:	8fa80260 */ 	lw	$t0,0x260($sp)
/*    1b44c:	e7a40258 */ 	swc1	$f4,0x258($sp)
/*    1b450:	c4460014 */ 	lwc1	$f6,0x14($v0)
/*    1b454:	8fa60270 */ 	lw	$a2,0x270($sp)
/*    1b458:	8fac0268 */ 	lw	$t4,0x268($sp)
/*    1b45c:	e7a60250 */ 	swc1	$f6,0x250($sp)
/*    1b460:	85030002 */ 	lh	$v1,0x2($t0)
/*    1b464:	8cef000c */ 	lw	$t7,0xc($a3)
/*    1b468:	00e02025 */ 	or	$a0,$a3,$zero
/*    1b46c:	0003c180 */ 	sll	$t8,$v1,0x6
/*    1b470:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    1b474:	afb90244 */ 	sw	$t9,0x244($sp)
/*    1b478:	95090000 */ 	lhu	$t1,0x0($t0)
/*    1b47c:	afa90240 */ 	sw	$t1,0x240($sp)
/*    1b480:	8cea0008 */ 	lw	$t2,0x8($a3)
/*    1b484:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    1b488:	afab023c */ 	sw	$t3,0x23c($sp)
/*    1b48c:	8cc50008 */ 	lw	$a1,0x8($a2)
/*    1b490:	50a00006 */ 	beqzl	$a1,.L0001b4ac
/*    1b494:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    1b498:	0c006973 */ 	jal	func0001a5cc
/*    1b49c:	00003025 */ 	or	$a2,$zero,$zero
/*    1b4a0:	10000003 */ 	b	.L0001b4b0
/*    1b4a4:	afa2024c */ 	sw	$v0,0x24c($sp)
/*    1b4a8:	8d8d0000 */ 	lw	$t5,0x0($t4)
.L0001b4ac:
/*    1b4ac:	afad024c */ 	sw	$t5,0x24c($sp)
.L0001b4b0:
/*    1b4b0:	920e0004 */ 	lbu	$t6,0x4($s0)
/*    1b4b4:	82050008 */ 	lb	$a1,0x8($s0)
/*    1b4b8:	86070000 */ 	lh	$a3,0x0($s0)
/*    1b4bc:	27af0230 */ 	addiu	$t7,$sp,0x230
/*    1b4c0:	27b80224 */ 	addiu	$t8,$sp,0x224
/*    1b4c4:	27b90218 */ 	addiu	$t9,$sp,0x218
/*    1b4c8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*    1b4cc:	afb80018 */ 	sw	$t8,0x18($sp)
/*    1b4d0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    1b4d4:	8fa40240 */ 	lw	$a0,0x240($sp)
/*    1b4d8:	8fa6023c */ 	lw	$a2,0x23c($sp)
/*    1b4dc:	0c009014 */ 	jal	func00024050
/*    1b4e0:	afae0010 */ 	sw	$t6,0x10($sp)
/*    1b4e4:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x4cc)
/*    1b4e8:	8d29a48c */ 	lw	$t1,%lo(g_Vars+0x4cc)($t1)
/*    1b4ec:	51200010 */ 	beqzl	$t1,.L0001b530
/*    1b4f0:	c6020010 */ 	lwc1	$f2,0x10($s0)
/*    1b4f4:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*    1b4f8:	44804000 */ 	mtc1	$zero,$f8
/*    1b4fc:	00000000 */ 	nop
/*    1b500:	4600403c */ 	c.lt.s	$f8,$f0
/*    1b504:	00000000 */ 	nop
/*    1b508:	45020009 */ 	bc1fl	.L0001b530
/*    1b50c:	c6020010 */ 	lwc1	$f2,0x10($s0)
/*    1b510:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*    1b514:	0fc25e24 */ 	jal	floorf
/*    1b518:	46005303 */ 	div.s	$f12,$f10,$f0
/*    1b51c:	c610001c */ 	lwc1	$f16,0x1c($s0)
/*    1b520:	46100082 */ 	mul.s	$f2,$f0,$f16
/*    1b524:	10000003 */ 	b	.L0001b534
/*    1b528:	44809000 */ 	mtc1	$zero,$f18
/*    1b52c:	c6020010 */ 	lwc1	$f2,0x10($s0)
.L0001b530:
/*    1b530:	44809000 */ 	mtc1	$zero,$f18
.L0001b534:
/*    1b534:	8fa40240 */ 	lw	$a0,0x240($sp)
/*    1b538:	8fa6023c */ 	lw	$a2,0x23c($sp)
/*    1b53c:	46121032 */ 	c.eq.s	$f2,$f18
/*    1b540:	27ab0148 */ 	addiu	$t3,$sp,0x148
/*    1b544:	27ac013c */ 	addiu	$t4,$sp,0x13c
/*    1b548:	27ad0130 */ 	addiu	$t5,$sp,0x130
/*    1b54c:	45030011 */ 	bc1tl	.L0001b594
/*    1b550:	44802000 */ 	mtc1	$zero,$f4
/*    1b554:	920a0005 */ 	lbu	$t2,0x5($s0)
/*    1b558:	82050008 */ 	lb	$a1,0x8($s0)
/*    1b55c:	86070000 */ 	lh	$a3,0x0($s0)
/*    1b560:	e7a20154 */ 	swc1	$f2,0x154($sp)
/*    1b564:	afad001c */ 	sw	$t5,0x1c($sp)
/*    1b568:	afac0018 */ 	sw	$t4,0x18($sp)
/*    1b56c:	afab0014 */ 	sw	$t3,0x14($sp)
/*    1b570:	0c009014 */ 	jal	func00024050
/*    1b574:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    1b578:	c7a20154 */ 	lwc1	$f2,0x154($sp)
/*    1b57c:	27a40230 */ 	addiu	$a0,$sp,0x230
/*    1b580:	27a50148 */ 	addiu	$a1,$sp,0x148
/*    1b584:	44061000 */ 	mfc1	$a2,$f2
/*    1b588:	0c006c1f */ 	jal	func0001b07c
/*    1b58c:	00000000 */ 	nop
/*    1b590:	44802000 */ 	mtc1	$zero,$f4
.L0001b594:
/*    1b594:	c6060054 */ 	lwc1	$f6,0x54($s0)
/*    1b598:	8fa6023c */ 	lw	$a2,0x23c($sp)
/*    1b59c:	27af0124 */ 	addiu	$t7,$sp,0x124
/*    1b5a0:	46062032 */ 	c.eq.s	$f4,$f6
/*    1b5a4:	27b80118 */ 	addiu	$t8,$sp,0x118
/*    1b5a8:	27b9010c */ 	addiu	$t9,$sp,0x10c
/*    1b5ac:	27a40230 */ 	addiu	$a0,$sp,0x230
/*    1b5b0:	45010055 */ 	bc1t	.L0001b708
/*    1b5b4:	00000000 */ 	nop
/*    1b5b8:	920e0006 */ 	lbu	$t6,0x6($s0)
/*    1b5bc:	82050009 */ 	lb	$a1,0x9($s0)
/*    1b5c0:	86070002 */ 	lh	$a3,0x2($s0)
/*    1b5c4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*    1b5c8:	afb80018 */ 	sw	$t8,0x18($sp)
/*    1b5cc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    1b5d0:	8fa40240 */ 	lw	$a0,0x240($sp)
/*    1b5d4:	0c009014 */ 	jal	func00024050
/*    1b5d8:	afae0010 */ 	sw	$t6,0x10($sp)
/*    1b5dc:	44804000 */ 	mtc1	$zero,$f8
/*    1b5e0:	c60a0034 */ 	lwc1	$f10,0x34($s0)
/*    1b5e4:	8fa40240 */ 	lw	$a0,0x240($sp)
/*    1b5e8:	8fa6023c */ 	lw	$a2,0x23c($sp)
/*    1b5ec:	460a4032 */ 	c.eq.s	$f8,$f10
/*    1b5f0:	27aa00d0 */ 	addiu	$t2,$sp,0xd0
/*    1b5f4:	27ab00c4 */ 	addiu	$t3,$sp,0xc4
/*    1b5f8:	27ac00b8 */ 	addiu	$t4,$sp,0xb8
/*    1b5fc:	4503000e */ 	bc1tl	.L0001b638
/*    1b600:	860d0000 */ 	lh	$t5,0x0($s0)
/*    1b604:	92090007 */ 	lbu	$t1,0x7($s0)
/*    1b608:	82050009 */ 	lb	$a1,0x9($s0)
/*    1b60c:	86070002 */ 	lh	$a3,0x2($s0)
/*    1b610:	afac001c */ 	sw	$t4,0x1c($sp)
/*    1b614:	afab0018 */ 	sw	$t3,0x18($sp)
/*    1b618:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    1b61c:	0c009014 */ 	jal	func00024050
/*    1b620:	afa90010 */ 	sw	$t1,0x10($sp)
/*    1b624:	27a40124 */ 	addiu	$a0,$sp,0x124
/*    1b628:	27a500d0 */ 	addiu	$a1,$sp,0xd0
/*    1b62c:	0c006c1f */ 	jal	func0001b07c
/*    1b630:	8e060034 */ 	lw	$a2,0x34($s0)
/*    1b634:	860d0000 */ 	lh	$t5,0x0($s0)
.L0001b638:
/*    1b638:	2403000c */ 	addiu	$v1,$zero,0xc
/*    1b63c:	3c028006 */ 	lui	$v0,%hi(g_Anims)
/*    1b640:	01a30019 */ 	multu	$t5,$v1
/*    1b644:	8c42f00c */ 	lw	$v0,%lo(g_Anims)($v0)
/*    1b648:	27a40124 */ 	addiu	$a0,$sp,0x124
/*    1b64c:	00007012 */ 	mflo	$t6
/*    1b650:	004e7821 */ 	addu	$t7,$v0,$t6
/*    1b654:	91f8000b */ 	lbu	$t8,0xb($t7)
/*    1b658:	33190002 */ 	andi	$t9,$t8,0x2
/*    1b65c:	13200018 */ 	beqz	$t9,.L0001b6c0
/*    1b660:	00000000 */ 	nop
/*    1b664:	86090002 */ 	lh	$t1,0x2($s0)
/*    1b668:	8fae025c */ 	lw	$t6,0x25c($sp)
/*    1b66c:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    1b670:	01230019 */ 	multu	$t1,$v1
/*    1b674:	00005012 */ 	mflo	$t2
/*    1b678:	004a5821 */ 	addu	$t3,$v0,$t2
/*    1b67c:	916c000b */ 	lbu	$t4,0xb($t3)
/*    1b680:	318d0002 */ 	andi	$t5,$t4,0x2
/*    1b684:	15a0000e */ 	bnez	$t5,.L0001b6c0
/*    1b688:	00000000 */ 	nop
/*    1b68c:	0c0058dd */ 	jal	func00016374
/*    1b690:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*    1b694:	27a40124 */ 	addiu	$a0,$sp,0x124
/*    1b698:	0c005923 */ 	jal	func0001648c
/*    1b69c:	27a50038 */ 	addiu	$a1,$sp,0x38
/*    1b6a0:	27a40078 */ 	addiu	$a0,$sp,0x78
/*    1b6a4:	0c0056f8 */ 	jal	func00015be0
/*    1b6a8:	27a50038 */ 	addiu	$a1,$sp,0x38
/*    1b6ac:	27a40038 */ 	addiu	$a0,$sp,0x38
/*    1b6b0:	0fc25c11 */ 	jal	func0f097044
/*    1b6b4:	27a500ec */ 	addiu	$a1,$sp,0xec
/*    1b6b8:	10000004 */ 	b	.L0001b6cc
/*    1b6bc:	27a40230 */ 	addiu	$a0,$sp,0x230
.L0001b6c0:
/*    1b6c0:	0fc25b28 */ 	jal	func0f096ca0
/*    1b6c4:	27a500ec */ 	addiu	$a1,$sp,0xec
/*    1b6c8:	27a40230 */ 	addiu	$a0,$sp,0x230
.L0001b6cc:
/*    1b6cc:	0fc25b28 */ 	jal	func0f096ca0
/*    1b6d0:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*    1b6d4:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*    1b6d8:	0fc25db0 */ 	jal	func0f0976c0
/*    1b6dc:	27a500ec */ 	addiu	$a1,$sp,0xec
/*    1b6e0:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*    1b6e4:	27a500ec */ 	addiu	$a1,$sp,0xec
/*    1b6e8:	8e060054 */ 	lw	$a2,0x54($s0)
/*    1b6ec:	0fc25cae */ 	jal	func0f0972b8
/*    1b6f0:	27a700dc */ 	addiu	$a3,$sp,0xdc
/*    1b6f4:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*    1b6f8:	0fc25bb5 */ 	jal	func0f096ed4
/*    1b6fc:	27a501d8 */ 	addiu	$a1,$sp,0x1d8
/*    1b700:	10000004 */ 	b	.L0001b714
/*    1b704:	86180000 */ 	lh	$t8,0x0($s0)
.L0001b708:
/*    1b708:	0c005923 */ 	jal	func0001648c
/*    1b70c:	27a501d8 */ 	addiu	$a1,$sp,0x1d8
/*    1b710:	86180000 */ 	lh	$t8,0x0($s0)
.L0001b714:
/*    1b714:	3c0f8006 */ 	lui	$t7,%hi(g_Anims)
/*    1b718:	8deff00c */ 	lw	$t7,%lo(g_Anims)($t7)
/*    1b71c:	0018c880 */ 	sll	$t9,$t8,0x2
/*    1b720:	0338c823 */ 	subu	$t9,$t9,$t8
/*    1b724:	0019c880 */ 	sll	$t9,$t9,0x2
/*    1b728:	01f94821 */ 	addu	$t1,$t7,$t9
/*    1b72c:	912a000b */ 	lbu	$t2,0xb($t1)
/*    1b730:	8fa40254 */ 	lw	$a0,0x254($sp)
/*    1b734:	8fac025c */ 	lw	$t4,0x25c($sp)
/*    1b738:	314b0002 */ 	andi	$t3,$t2,0x2
/*    1b73c:	51600006 */ 	beqzl	$t3,.L0001b758
/*    1b740:	c5800018 */ 	lwc1	$f0,0x18($t4)
/*    1b744:	0c0059b7 */ 	jal	func000166dc
/*    1b748:	27a50198 */ 	addiu	$a1,$sp,0x198
/*    1b74c:	10000011 */ 	b	.L0001b794
/*    1b750:	27b00158 */ 	addiu	$s0,$sp,0x158
/*    1b754:	c5800018 */ 	lwc1	$f0,0x18($t4)
.L0001b758:
/*    1b758:	44808000 */ 	mtc1	$zero,$f16
/*    1b75c:	c7ac0250 */ 	lwc1	$f12,0x250($sp)
/*    1b760:	46008032 */ 	c.eq.s	$f16,$f0
/*    1b764:	00000000 */ 	nop
/*    1b768:	45030006 */ 	bc1tl	.L0001b784
/*    1b76c:	8fa40254 */ 	lw	$a0,0x254($sp)
/*    1b770:	44060000 */ 	mfc1	$a2,$f0
/*    1b774:	0c006bfa */ 	jal	func0001afe8
/*    1b778:	c58e001c */ 	lwc1	$f14,0x1c($t4)
/*    1b77c:	e7a00250 */ 	swc1	$f0,0x250($sp)
/*    1b780:	8fa40254 */ 	lw	$a0,0x254($sp)
.L0001b784:
/*    1b784:	8fa50250 */ 	lw	$a1,0x250($sp)
/*    1b788:	0c005892 */ 	jal	func00016248
/*    1b78c:	27a60198 */ 	addiu	$a2,$sp,0x198
/*    1b790:	27b00158 */ 	addiu	$s0,$sp,0x158
.L0001b794:
/*    1b794:	02003025 */ 	or	$a2,$s0,$zero
/*    1b798:	27a40198 */ 	addiu	$a0,$sp,0x198
/*    1b79c:	0c0056f9 */ 	jal	func00015be4
/*    1b7a0:	27a501d8 */ 	addiu	$a1,$sp,0x1d8
/*    1b7a4:	3c013f80 */ 	lui	$at,0x3f80
/*    1b7a8:	44812000 */ 	mtc1	$at,$f4
/*    1b7ac:	c7b20258 */ 	lwc1	$f18,0x258($sp)
/*    1b7b0:	02002825 */ 	or	$a1,$s0,$zero
/*    1b7b4:	46049032 */ 	c.eq.s	$f18,$f4
/*    1b7b8:	00000000 */ 	nop
/*    1b7bc:	45030004 */ 	bc1tl	.L0001b7d0
/*    1b7c0:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*    1b7c4:	0c0057d3 */ 	jal	func00015f4c
/*    1b7c8:	46009306 */ 	mov.s	$f12,$f18
/*    1b7cc:	8fa4024c */ 	lw	$a0,0x24c($sp)
.L0001b7d0:
/*    1b7d0:	8fa60244 */ 	lw	$a2,0x244($sp)
/*    1b7d4:	8fa50244 */ 	lw	$a1,0x244($sp)
/*    1b7d8:	10800005 */ 	beqz	$a0,.L0001b7f0
/*    1b7dc:	00000000 */ 	nop
/*    1b7e0:	0c0056f9 */ 	jal	func00015be4
/*    1b7e4:	02002825 */ 	or	$a1,$s0,$zero
/*    1b7e8:	10000004 */ 	b	.L0001b7fc
/*    1b7ec:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001b7f0:
/*    1b7f0:	0c005746 */ 	jal	func00015d18
/*    1b7f4:	02002025 */ 	or	$a0,$s0,$zero
/*    1b7f8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001b7fc:
/*    1b7fc:	8fb00028 */ 	lw	$s0,0x28($sp)
/*    1b800:	27bd0268 */ 	addiu	$sp,$sp,0x268
/*    1b804:	03e00008 */ 	jr	$ra
/*    1b808:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001b80c
.late_rodata
glabel var700542f4
.word 0x40490fdb
glabel var700542f8
.word 0x40c907a9
glabel var700542fc
.word 0x40c907a9
glabel var70054300
.word 0x40490fdb
glabel var70054304
.word 0x40c907a9
glabel var70054308
.word 0x3f63dec6
.text
/*    1b80c:	27bdff48 */ 	addiu	$sp,$sp,-184
/*    1b810:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1b814:	afa500bc */ 	sw	$a1,0xbc($sp)
/*    1b818:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*    1b81c:	94ce0000 */ 	lhu	$t6,0x0($a2)
/*    1b820:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*    1b824:	8cc20004 */ 	lw	$v0,0x4($a2)
/*    1b828:	844f000e */ 	lh	$t7,0xe($v0)
/*    1b82c:	afaf0064 */ 	sw	$t7,0x64($sp)
/*    1b830:	84580010 */ 	lh	$t8,0x10($v0)
/*    1b834:	afb80060 */ 	sw	$t8,0x60($sp)
/*    1b838:	84590012 */ 	lh	$t9,0x12($v0)
/*    1b83c:	afb9005c */ 	sw	$t9,0x5c($sp)
/*    1b840:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1b844:	afa90058 */ 	sw	$t1,0x58($sp)
/*    1b848:	8cca0008 */ 	lw	$t2,0x8($a2)
/*    1b84c:	00003025 */ 	or	$a2,$zero,$zero
/*    1b850:	11400006 */ 	beqz	$t2,.L0001b86c
/*    1b854:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    1b858:	00a02025 */ 	or	$a0,$a1,$zero
/*    1b85c:	0c006973 */ 	jal	func0001a5cc
/*    1b860:	01402825 */ 	or	$a1,$t2,$zero
/*    1b864:	10000003 */ 	b	.L0001b874
/*    1b868:	afa200ac */ 	sw	$v0,0xac($sp)
.L0001b86c:
/*    1b86c:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*    1b870:	afac00ac */ 	sw	$t4,0xac($sp)
.L0001b874:
/*    1b874:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    1b878:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    1b87c:	8fac0064 */ 	lw	$t4,0x64($sp)
/*    1b880:	11a00042 */ 	beqz	$t5,.L0001b98c
/*    1b884:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    1b888:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    1b88c:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*    1b890:	0c0059a9 */ 	jal	func000166a4
/*    1b894:	27a60068 */ 	addiu	$a2,$sp,0x68
/*    1b898:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*    1b89c:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*    1b8a0:	3c013f80 */ 	lui	$at,0x3f80
/*    1b8a4:	51c0000b */ 	beqzl	$t6,.L0001b8d4
/*    1b8a8:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    1b8ac:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*    1b8b0:	44812000 */ 	mtc1	$at,$f4
/*    1b8b4:	00000000 */ 	nop
/*    1b8b8:	460c2032 */ 	c.eq.s	$f4,$f12
/*    1b8bc:	00000000 */ 	nop
/*    1b8c0:	45030004 */ 	bc1tl	.L0001b8d4
/*    1b8c4:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    1b8c8:	0c0057c1 */ 	jal	func00015f04
/*    1b8cc:	27a50068 */ 	addiu	$a1,$sp,0x68
/*    1b8d0:	8fb800d0 */ 	lw	$t8,0xd0($sp)
.L0001b8d4:
/*    1b8d4:	3c013f80 */ 	lui	$at,0x3f80
/*    1b8d8:	44813000 */ 	mtc1	$at,$f6
/*    1b8dc:	c70c0000 */ 	lwc1	$f12,0x0($t8)
/*    1b8e0:	460c3032 */ 	c.eq.s	$f6,$f12
/*    1b8e4:	00000000 */ 	nop
/*    1b8e8:	45030004 */ 	bc1tl	.L0001b8fc
/*    1b8ec:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    1b8f0:	0c00577c */ 	jal	func00015df0
/*    1b8f4:	27a50068 */ 	addiu	$a1,$sp,0x68
/*    1b8f8:	8fb900d0 */ 	lw	$t9,0xd0($sp)
.L0001b8fc:
/*    1b8fc:	3c013f80 */ 	lui	$at,0x3f80
/*    1b900:	44814000 */ 	mtc1	$at,$f8
/*    1b904:	c72c0004 */ 	lwc1	$f12,0x4($t9)
/*    1b908:	460c4032 */ 	c.eq.s	$f8,$f12
/*    1b90c:	00000000 */ 	nop
/*    1b910:	45030004 */ 	bc1tl	.L0001b924
/*    1b914:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    1b918:	0c005793 */ 	jal	func00015e4c
/*    1b91c:	27a50068 */ 	addiu	$a1,$sp,0x68
/*    1b920:	8fa900d0 */ 	lw	$t1,0xd0($sp)
.L0001b924:
/*    1b924:	3c013f80 */ 	lui	$at,0x3f80
/*    1b928:	44815000 */ 	mtc1	$at,$f10
/*    1b92c:	c52c0008 */ 	lwc1	$f12,0x8($t1)
/*    1b930:	460c5032 */ 	c.eq.s	$f10,$f12
/*    1b934:	00000000 */ 	nop
/*    1b938:	45030004 */ 	bc1tl	.L0001b94c
/*    1b93c:	8faa0064 */ 	lw	$t2,0x64($sp)
/*    1b940:	0c0057aa */ 	jal	func00015ea8
/*    1b944:	27a50068 */ 	addiu	$a1,$sp,0x68
/*    1b948:	8faa0064 */ 	lw	$t2,0x64($sp)
.L0001b94c:
/*    1b94c:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    1b950:	8fa400ac */ 	lw	$a0,0xac($sp)
/*    1b954:	000a4180 */ 	sll	$t0,$t2,0x6
/*    1b958:	010b3021 */ 	addu	$a2,$t0,$t3
/*    1b95c:	afa6001c */ 	sw	$a2,0x1c($sp)
/*    1b960:	0c0056f9 */ 	jal	func00015be4
/*    1b964:	27a50068 */ 	addiu	$a1,$sp,0x68
/*    1b968:	3c028006 */ 	lui	$v0,%hi(var8005efcc)
/*    1b96c:	8c42efcc */ 	lw	$v0,%lo(var8005efcc)($v0)
/*    1b970:	8fa40064 */ 	lw	$a0,0x64($sp)
/*    1b974:	50400037 */ 	beqzl	$v0,.L0001ba54
/*    1b978:	8fa800b4 */ 	lw	$t0,0xb4($sp)
/*    1b97c:	0040f809 */ 	jalr	$v0
/*    1b980:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1b984:	10000033 */ 	b	.L0001ba54
/*    1b988:	8fa800b4 */ 	lw	$t0,0xb4($sp)
.L0001b98c:
/*    1b98c:	000c6980 */ 	sll	$t5,$t4,0x6
/*    1b990:	01ae3021 */ 	addu	$a2,$t5,$t6
/*    1b994:	afa6001c */ 	sw	$a2,0x1c($sp)
/*    1b998:	0c0059a9 */ 	jal	func000166a4
/*    1b99c:	8fa500c4 */ 	lw	$a1,0xc4($sp)
/*    1b9a0:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    1b9a4:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*    1b9a8:	3c013f80 */ 	lui	$at,0x3f80
/*    1b9ac:	51e0000b */ 	beqzl	$t7,.L0001b9dc
/*    1b9b0:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    1b9b4:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*    1b9b8:	44818000 */ 	mtc1	$at,$f16
/*    1b9bc:	00000000 */ 	nop
/*    1b9c0:	460c8032 */ 	c.eq.s	$f16,$f12
/*    1b9c4:	00000000 */ 	nop
/*    1b9c8:	45030004 */ 	bc1tl	.L0001b9dc
/*    1b9cc:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    1b9d0:	0c0057c1 */ 	jal	func00015f04
/*    1b9d4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1b9d8:	8fb900d0 */ 	lw	$t9,0xd0($sp)
.L0001b9dc:
/*    1b9dc:	3c013f80 */ 	lui	$at,0x3f80
/*    1b9e0:	44819000 */ 	mtc1	$at,$f18
/*    1b9e4:	c72c0000 */ 	lwc1	$f12,0x0($t9)
/*    1b9e8:	460c9032 */ 	c.eq.s	$f18,$f12
/*    1b9ec:	00000000 */ 	nop
/*    1b9f0:	45030004 */ 	bc1tl	.L0001ba04
/*    1b9f4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    1b9f8:	0c00577c */ 	jal	func00015df0
/*    1b9fc:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1ba00:	8fa900d0 */ 	lw	$t1,0xd0($sp)
.L0001ba04:
/*    1ba04:	3c013f80 */ 	lui	$at,0x3f80
/*    1ba08:	44812000 */ 	mtc1	$at,$f4
/*    1ba0c:	c52c0004 */ 	lwc1	$f12,0x4($t1)
/*    1ba10:	460c2032 */ 	c.eq.s	$f4,$f12
/*    1ba14:	00000000 */ 	nop
/*    1ba18:	45030004 */ 	bc1tl	.L0001ba2c
/*    1ba1c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    1ba20:	0c005793 */ 	jal	func00015e4c
/*    1ba24:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1ba28:	8faa00d0 */ 	lw	$t2,0xd0($sp)
.L0001ba2c:
/*    1ba2c:	3c013f80 */ 	lui	$at,0x3f80
/*    1ba30:	44813000 */ 	mtc1	$at,$f6
/*    1ba34:	c54c0008 */ 	lwc1	$f12,0x8($t2)
/*    1ba38:	460c3032 */ 	c.eq.s	$f6,$f12
/*    1ba3c:	00000000 */ 	nop
/*    1ba40:	45030004 */ 	bc1tl	.L0001ba54
/*    1ba44:	8fa800b4 */ 	lw	$t0,0xb4($sp)
/*    1ba48:	0c0057aa */ 	jal	func00015ea8
/*    1ba4c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1ba50:	8fa800b4 */ 	lw	$t0,0xb4($sp)
.L0001ba54:
/*    1ba54:	8fa400c4 */ 	lw	$a0,0xc4($sp)
/*    1ba58:	310b0100 */ 	andi	$t3,$t0,0x100
/*    1ba5c:	5160001d */ 	beqzl	$t3,.L0001bad4
/*    1ba60:	8faa00b4 */ 	lw	$t2,0xb4($sp)
/*    1ba64:	0fc25b28 */ 	jal	func0f096ca0
/*    1ba68:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*    1ba6c:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*    1ba70:	3c053f00 */ 	lui	$a1,0x3f00
/*    1ba74:	0fc25d46 */ 	jal	func0f097518
/*    1ba78:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*    1ba7c:	8fac00ac */ 	lw	$t4,0xac($sp)
/*    1ba80:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    1ba84:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    1ba88:	1180000d */ 	beqz	$t4,.L0001bac0
/*    1ba8c:	0018c980 */ 	sll	$t9,$t8,0x6
/*    1ba90:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    1ba94:	0fc25c99 */ 	jal	func0f097264
/*    1ba98:	27a60068 */ 	addiu	$a2,$sp,0x68
/*    1ba9c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    1baa0:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    1baa4:	8fa400ac */ 	lw	$a0,0xac($sp)
/*    1baa8:	000d7180 */ 	sll	$t6,$t5,0x6
/*    1baac:	27a50068 */ 	addiu	$a1,$sp,0x68
/*    1bab0:	0c0056f9 */ 	jal	func00015be4
/*    1bab4:	01cf3021 */ 	addu	$a2,$t6,$t7
/*    1bab8:	10000006 */ 	b	.L0001bad4
/*    1babc:	8faa00b4 */ 	lw	$t2,0xb4($sp)
.L0001bac0:
/*    1bac0:	8fa90058 */ 	lw	$t1,0x58($sp)
/*    1bac4:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    1bac8:	0fc25c99 */ 	jal	func0f097264
/*    1bacc:	03293021 */ 	addu	$a2,$t9,$t1
/*    1bad0:	8faa00b4 */ 	lw	$t2,0xb4($sp)
.L0001bad4:
/*    1bad4:	8fab00ac */ 	lw	$t3,0xac($sp)
/*    1bad8:	31480200 */ 	andi	$t0,$t2,0x200
/*    1badc:	5100004a */ 	beqzl	$t0,.L0001bc08
/*    1bae0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1bae4:	11600004 */ 	beqz	$t3,.L0001baf8
/*    1bae8:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    1baec:	27ac0068 */ 	addiu	$t4,$sp,0x68
/*    1baf0:	10000005 */ 	b	.L0001bb08
/*    1baf4:	afac0028 */ 	sw	$t4,0x28($sp)
.L0001baf8:
/*    1baf8:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    1bafc:	000d7180 */ 	sll	$t6,$t5,0x6
/*    1bb00:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    1bb04:	afb80028 */ 	sw	$t8,0x28($sp)
.L0001bb08:
/*    1bb08:	8fb900c4 */ 	lw	$t9,0xc4($sp)
/*    1bb0c:	3c017005 */ 	lui	$at,%hi(var700542f4)
/*    1bb10:	c42842f4 */ 	lwc1	$f8,%lo(var700542f4)($at)
/*    1bb14:	c72c0004 */ 	lwc1	$f12,0x4($t9)
/*    1bb18:	3c017005 */ 	lui	$at,0x7005
/*    1bb1c:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    1bb20:	4608603c */ 	c.lt.s	$f12,$f8
/*    1bb24:	00000000 */ 	nop
/*    1bb28:	45000007 */ 	bc1f	.L0001bb48
/*    1bb2c:	00000000 */ 	nop
/*    1bb30:	3c013f00 */ 	lui	$at,0x3f00
/*    1bb34:	44815000 */ 	mtc1	$at,$f10
/*    1bb38:	00000000 */ 	nop
/*    1bb3c:	460a6302 */ 	mul.s	$f12,$f12,$f10
/*    1bb40:	10000009 */ 	b	.L0001bb68
/*    1bb44:	00000000 */ 	nop
.L0001bb48:
/*    1bb48:	c43042f8 */ 	lwc1	$f16,0x42f8($at)
/*    1bb4c:	3c013f00 */ 	lui	$at,0x3f00
/*    1bb50:	44812000 */ 	mtc1	$at,$f4
/*    1bb54:	460c8481 */ 	sub.s	$f18,$f16,$f12
/*    1bb58:	3c017005 */ 	lui	$at,%hi(var700542fc)
/*    1bb5c:	c42842fc */ 	lwc1	$f8,%lo(var700542fc)($at)
/*    1bb60:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    1bb64:	46064301 */ 	sub.s	$f12,$f8,$f6
.L0001bb68:
/*    1bb68:	0c0058dd */ 	jal	func00016374
/*    1bb6c:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*    1bb70:	3c017005 */ 	lui	$at,%hi(var70054300)
/*    1bb74:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*    1bb78:	c42a4300 */ 	lwc1	$f10,%lo(var70054300)($at)
/*    1bb7c:	3c017005 */ 	lui	$at,%hi(var70054304)
/*    1bb80:	460c503e */ 	c.le.s	$f10,$f12
/*    1bb84:	00000000 */ 	nop
/*    1bb88:	45000003 */ 	bc1f	.L0001bb98
/*    1bb8c:	00000000 */ 	nop
/*    1bb90:	c4304304 */ 	lwc1	$f16,%lo(var70054304)($at)
/*    1bb94:	460c8301 */ 	sub.s	$f12,$f16,$f12
.L0001bb98:
/*    1bb98:	3c017005 */ 	lui	$at,%hi(var70054308)
/*    1bb9c:	c4324308 */ 	lwc1	$f18,%lo(var70054308)($at)
/*    1bba0:	3c013fc0 */ 	lui	$at,0x3fc0
/*    1bba4:	4612603c */ 	c.lt.s	$f12,$f18
/*    1bba8:	00000000 */ 	nop
/*    1bbac:	45020006 */ 	bc1fl	.L0001bbc8
/*    1bbb0:	44816000 */ 	mtc1	$at,$f12
/*    1bbb4:	0fc259c0 */ 	jal	func0f096700
/*    1bbb8:	00000000 */ 	nop
/*    1bbbc:	10000003 */ 	b	.L0001bbcc
/*    1bbc0:	46000306 */ 	mov.s	$f12,$f0
/*    1bbc4:	44816000 */ 	mtc1	$at,$f12
.L0001bbc8:
/*    1bbc8:	00000000 */ 	nop
.L0001bbcc:
/*    1bbcc:	0c0057b7 */ 	jal	func00015edc
/*    1bbd0:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    1bbd4:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    1bbd8:	0c005775 */ 	jal	func00015dd4
/*    1bbdc:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    1bbe0:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    1bbe4:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    1bbe8:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    1bbec:	11200005 */ 	beqz	$t1,.L0001bc04
/*    1bbf0:	01202025 */ 	or	$a0,$t1,$zero
/*    1bbf4:	000a4180 */ 	sll	$t0,$t2,0x6
/*    1bbf8:	010b3021 */ 	addu	$a2,$t0,$t3
/*    1bbfc:	0c0056f9 */ 	jal	func00015be4
/*    1bc00:	8fa50028 */ 	lw	$a1,0x28($sp)
.L0001bc04:
/*    1bc04:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001bc08:
/*    1bc08:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*    1bc0c:	03e00008 */ 	jr	$ra
/*    1bc10:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001bc14
.late_rodata
glabel var7005430c
.word 0x40490fdb
glabel var70054310
.word 0x40c907a9
glabel var70054314
.word 0x40c907a9
glabel var70054318
.word 0x40490fdb
glabel var7005431c
.word 0x40c907a9
glabel var70054320
.word 0x3f63dec6
.text
/*    1bc14:	27bdff58 */ 	addiu	$sp,$sp,-168
/*    1bc18:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1bc1c:	afa500ac */ 	sw	$a1,0xac($sp)
/*    1bc20:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*    1bc24:	94ce0000 */ 	lhu	$t6,0x0($a2)
/*    1bc28:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*    1bc2c:	8cc20004 */ 	lw	$v0,0x4($a2)
/*    1bc30:	844f000e */ 	lh	$t7,0xe($v0)
/*    1bc34:	afaf0054 */ 	sw	$t7,0x54($sp)
/*    1bc38:	84580010 */ 	lh	$t8,0x10($v0)
/*    1bc3c:	afb80050 */ 	sw	$t8,0x50($sp)
/*    1bc40:	84590012 */ 	lh	$t9,0x12($v0)
/*    1bc44:	afb9004c */ 	sw	$t9,0x4c($sp)
/*    1bc48:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1bc4c:	afa90048 */ 	sw	$t1,0x48($sp)
/*    1bc50:	8cca0008 */ 	lw	$t2,0x8($a2)
/*    1bc54:	00003025 */ 	or	$a2,$zero,$zero
/*    1bc58:	11400006 */ 	beqz	$t2,.L0001bc74
/*    1bc5c:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    1bc60:	00a02025 */ 	or	$a0,$a1,$zero
/*    1bc64:	0c006973 */ 	jal	func0001a5cc
/*    1bc68:	01402825 */ 	or	$a1,$t2,$zero
/*    1bc6c:	10000003 */ 	b	.L0001bc7c
/*    1bc70:	afa2009c */ 	sw	$v0,0x9c($sp)
.L0001bc74:
/*    1bc74:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*    1bc78:	afac009c */ 	sw	$t4,0x9c($sp)
.L0001bc7c:
/*    1bc7c:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    1bc80:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*    1bc84:	8fa80054 */ 	lw	$t0,0x54($sp)
/*    1bc88:	11a00034 */ 	beqz	$t5,.L0001bd5c
/*    1bc8c:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    1bc90:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*    1bc94:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*    1bc98:	0fc25c99 */ 	jal	func0f097264
/*    1bc9c:	27a60058 */ 	addiu	$a2,$sp,0x58
/*    1bca0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*    1bca4:	3c013f80 */ 	lui	$at,0x3f80
/*    1bca8:	44812000 */ 	mtc1	$at,$f4
/*    1bcac:	c5cc0000 */ 	lwc1	$f12,0x0($t6)
/*    1bcb0:	460c2032 */ 	c.eq.s	$f4,$f12
/*    1bcb4:	00000000 */ 	nop
/*    1bcb8:	45030004 */ 	bc1tl	.L0001bccc
/*    1bcbc:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*    1bcc0:	0c00577c */ 	jal	func00015df0
/*    1bcc4:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    1bcc8:	8faf00bc */ 	lw	$t7,0xbc($sp)
.L0001bccc:
/*    1bccc:	3c013f80 */ 	lui	$at,0x3f80
/*    1bcd0:	44813000 */ 	mtc1	$at,$f6
/*    1bcd4:	c5ec0004 */ 	lwc1	$f12,0x4($t7)
/*    1bcd8:	460c3032 */ 	c.eq.s	$f6,$f12
/*    1bcdc:	00000000 */ 	nop
/*    1bce0:	45030004 */ 	bc1tl	.L0001bcf4
/*    1bce4:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*    1bce8:	0c005793 */ 	jal	func00015e4c
/*    1bcec:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    1bcf0:	8fb800bc */ 	lw	$t8,0xbc($sp)
.L0001bcf4:
/*    1bcf4:	3c013f80 */ 	lui	$at,0x3f80
/*    1bcf8:	44814000 */ 	mtc1	$at,$f8
/*    1bcfc:	c70c0008 */ 	lwc1	$f12,0x8($t8)
/*    1bd00:	460c4032 */ 	c.eq.s	$f8,$f12
/*    1bd04:	00000000 */ 	nop
/*    1bd08:	45030004 */ 	bc1tl	.L0001bd1c
/*    1bd0c:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    1bd10:	0c0057aa */ 	jal	func00015ea8
/*    1bd14:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    1bd18:	8fb90054 */ 	lw	$t9,0x54($sp)
.L0001bd1c:
/*    1bd1c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*    1bd20:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    1bd24:	00194980 */ 	sll	$t1,$t9,0x6
/*    1bd28:	012a3021 */ 	addu	$a2,$t1,$t2
/*    1bd2c:	afa6001c */ 	sw	$a2,0x1c($sp)
/*    1bd30:	0c0056f9 */ 	jal	func00015be4
/*    1bd34:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    1bd38:	3c028006 */ 	lui	$v0,%hi(var8005efcc)
/*    1bd3c:	8c42efcc */ 	lw	$v0,%lo(var8005efcc)($v0)
/*    1bd40:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    1bd44:	50400029 */ 	beqzl	$v0,.L0001bdec
/*    1bd48:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*    1bd4c:	0040f809 */ 	jalr	$v0
/*    1bd50:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1bd54:	10000025 */ 	b	.L0001bdec
/*    1bd58:	8fb800a4 */ 	lw	$t8,0xa4($sp)
.L0001bd5c:
/*    1bd5c:	00085980 */ 	sll	$t3,$t0,0x6
/*    1bd60:	016c3021 */ 	addu	$a2,$t3,$t4
/*    1bd64:	afa6001c */ 	sw	$a2,0x1c($sp)
/*    1bd68:	0fc25c99 */ 	jal	func0f097264
/*    1bd6c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*    1bd70:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*    1bd74:	3c013f80 */ 	lui	$at,0x3f80
/*    1bd78:	44815000 */ 	mtc1	$at,$f10
/*    1bd7c:	c5ac0000 */ 	lwc1	$f12,0x0($t5)
/*    1bd80:	460c5032 */ 	c.eq.s	$f10,$f12
/*    1bd84:	00000000 */ 	nop
/*    1bd88:	45030004 */ 	bc1tl	.L0001bd9c
/*    1bd8c:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*    1bd90:	0c00577c */ 	jal	func00015df0
/*    1bd94:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1bd98:	8fae00bc */ 	lw	$t6,0xbc($sp)
.L0001bd9c:
/*    1bd9c:	3c013f80 */ 	lui	$at,0x3f80
/*    1bda0:	44818000 */ 	mtc1	$at,$f16
/*    1bda4:	c5cc0004 */ 	lwc1	$f12,0x4($t6)
/*    1bda8:	460c8032 */ 	c.eq.s	$f16,$f12
/*    1bdac:	00000000 */ 	nop
/*    1bdb0:	45030004 */ 	bc1tl	.L0001bdc4
/*    1bdb4:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*    1bdb8:	0c005793 */ 	jal	func00015e4c
/*    1bdbc:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1bdc0:	8faf00bc */ 	lw	$t7,0xbc($sp)
.L0001bdc4:
/*    1bdc4:	3c013f80 */ 	lui	$at,0x3f80
/*    1bdc8:	44819000 */ 	mtc1	$at,$f18
/*    1bdcc:	c5ec0008 */ 	lwc1	$f12,0x8($t7)
/*    1bdd0:	460c9032 */ 	c.eq.s	$f18,$f12
/*    1bdd4:	00000000 */ 	nop
/*    1bdd8:	45030004 */ 	bc1tl	.L0001bdec
/*    1bddc:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*    1bde0:	0c0057aa */ 	jal	func00015ea8
/*    1bde4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1bde8:	8fb800a4 */ 	lw	$t8,0xa4($sp)
.L0001bdec:
/*    1bdec:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*    1bdf0:	3c053f00 */ 	lui	$a1,0x3f00
/*    1bdf4:	33190100 */ 	andi	$t9,$t8,0x100
/*    1bdf8:	53200019 */ 	beqzl	$t9,.L0001be60
/*    1bdfc:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*    1be00:	0fc25d46 */ 	jal	func0f097518
/*    1be04:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*    1be08:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    1be0c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    1be10:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    1be14:	1120000d */ 	beqz	$t1,.L0001be4c
/*    1be18:	000c6980 */ 	sll	$t5,$t4,0x6
/*    1be1c:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*    1be20:	0fc25c99 */ 	jal	func0f097264
/*    1be24:	27a60058 */ 	addiu	$a2,$sp,0x58
/*    1be28:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    1be2c:	8fab0048 */ 	lw	$t3,0x48($sp)
/*    1be30:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    1be34:	000a4180 */ 	sll	$t0,$t2,0x6
/*    1be38:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    1be3c:	0c0056f9 */ 	jal	func00015be4
/*    1be40:	010b3021 */ 	addu	$a2,$t0,$t3
/*    1be44:	10000006 */ 	b	.L0001be60
/*    1be48:	8faf00a4 */ 	lw	$t7,0xa4($sp)
.L0001be4c:
/*    1be4c:	8fae0048 */ 	lw	$t6,0x48($sp)
/*    1be50:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*    1be54:	0fc25c99 */ 	jal	func0f097264
/*    1be58:	01ae3021 */ 	addu	$a2,$t5,$t6
/*    1be5c:	8faf00a4 */ 	lw	$t7,0xa4($sp)
.L0001be60:
/*    1be60:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    1be64:	31f80200 */ 	andi	$t8,$t7,0x200
/*    1be68:	5300004c */ 	beqzl	$t8,.L0001bf9c
/*    1be6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1be70:	13200004 */ 	beqz	$t9,.L0001be84
/*    1be74:	8faa004c */ 	lw	$t2,0x4c($sp)
/*    1be78:	27a90058 */ 	addiu	$t1,$sp,0x58
/*    1be7c:	10000005 */ 	b	.L0001be94
/*    1be80:	afa90028 */ 	sw	$t1,0x28($sp)
.L0001be84:
/*    1be84:	8fab0048 */ 	lw	$t3,0x48($sp)
/*    1be88:	000a4180 */ 	sll	$t0,$t2,0x6
/*    1be8c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    1be90:	afac0028 */ 	sw	$t4,0x28($sp)
.L0001be94:
/*    1be94:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*    1be98:	0fc25a74 */ 	jal	func0f0969d0
/*    1be9c:	c5ac0000 */ 	lwc1	$f12,0x0($t5)
/*    1bea0:	46000080 */ 	add.s	$f2,$f0,$f0
/*    1bea4:	3c017005 */ 	lui	$at,%hi(var7005430c)
/*    1bea8:	c424430c */ 	lwc1	$f4,%lo(var7005430c)($at)
/*    1beac:	3c017005 */ 	lui	$at,0x7005
/*    1beb0:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    1beb4:	4604103c */ 	c.lt.s	$f2,$f4
/*    1beb8:	00000000 */ 	nop
/*    1bebc:	45000007 */ 	bc1f	.L0001bedc
/*    1bec0:	00000000 */ 	nop
/*    1bec4:	3c013f00 */ 	lui	$at,0x3f00
/*    1bec8:	44813000 */ 	mtc1	$at,$f6
/*    1becc:	00000000 */ 	nop
/*    1bed0:	46061302 */ 	mul.s	$f12,$f2,$f6
/*    1bed4:	10000009 */ 	b	.L0001befc
/*    1bed8:	00000000 */ 	nop
.L0001bedc:
/*    1bedc:	c4284310 */ 	lwc1	$f8,0x4310($at)
/*    1bee0:	3c013f00 */ 	lui	$at,0x3f00
/*    1bee4:	44818000 */ 	mtc1	$at,$f16
/*    1bee8:	46024281 */ 	sub.s	$f10,$f8,$f2
/*    1beec:	3c017005 */ 	lui	$at,%hi(var70054314)
/*    1bef0:	c4244314 */ 	lwc1	$f4,%lo(var70054314)($at)
/*    1bef4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1bef8:	46122301 */ 	sub.s	$f12,$f4,$f18
.L0001befc:
/*    1befc:	0c0058dd */ 	jal	func00016374
/*    1bf00:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*    1bf04:	3c017005 */ 	lui	$at,%hi(var70054318)
/*    1bf08:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*    1bf0c:	c4264318 */ 	lwc1	$f6,%lo(var70054318)($at)
/*    1bf10:	3c017005 */ 	lui	$at,%hi(var7005431c)
/*    1bf14:	460c303e */ 	c.le.s	$f6,$f12
/*    1bf18:	00000000 */ 	nop
/*    1bf1c:	45000003 */ 	bc1f	.L0001bf2c
/*    1bf20:	00000000 */ 	nop
/*    1bf24:	c428431c */ 	lwc1	$f8,%lo(var7005431c)($at)
/*    1bf28:	460c4301 */ 	sub.s	$f12,$f8,$f12
.L0001bf2c:
/*    1bf2c:	3c017005 */ 	lui	$at,%hi(var70054320)
/*    1bf30:	c42a4320 */ 	lwc1	$f10,%lo(var70054320)($at)
/*    1bf34:	3c013fc0 */ 	lui	$at,0x3fc0
/*    1bf38:	460a603c */ 	c.lt.s	$f12,$f10
/*    1bf3c:	00000000 */ 	nop
/*    1bf40:	45020006 */ 	bc1fl	.L0001bf5c
/*    1bf44:	44816000 */ 	mtc1	$at,$f12
/*    1bf48:	0fc259c0 */ 	jal	func0f096700
/*    1bf4c:	00000000 */ 	nop
/*    1bf50:	10000003 */ 	b	.L0001bf60
/*    1bf54:	46000306 */ 	mov.s	$f12,$f0
/*    1bf58:	44816000 */ 	mtc1	$at,$f12
.L0001bf5c:
/*    1bf5c:	00000000 */ 	nop
.L0001bf60:
/*    1bf60:	0c0057b7 */ 	jal	func00015edc
/*    1bf64:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    1bf68:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*    1bf6c:	0c005775 */ 	jal	func00015dd4
/*    1bf70:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    1bf74:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    1bf78:	8faf004c */ 	lw	$t7,0x4c($sp)
/*    1bf7c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    1bf80:	11c00005 */ 	beqz	$t6,.L0001bf98
/*    1bf84:	01c02025 */ 	or	$a0,$t6,$zero
/*    1bf88:	000fc180 */ 	sll	$t8,$t7,0x6
/*    1bf8c:	03193021 */ 	addu	$a2,$t8,$t9
/*    1bf90:	0c0056f9 */ 	jal	func00015be4
/*    1bf94:	8fa50028 */ 	lw	$a1,0x28($sp)
.L0001bf98:
/*    1bf98:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001bf9c:
/*    1bf9c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*    1bfa0:	03e00008 */ 	jr	$ra
/*    1bfa4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001bfa8
/*    1bfa8:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*    1bfac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    1bfb0:	afb00028 */ 	sw	$s0,0x28($sp)
/*    1bfb4:	afa40160 */ 	sw	$a0,0x160($sp)
/*    1bfb8:	afa50164 */ 	sw	$a1,0x164($sp)
/*    1bfbc:	afa60168 */ 	sw	$a2,0x168($sp)
/*    1bfc0:	8ccf0004 */ 	lw	$t7,0x4($a2)
/*    1bfc4:	8fae0168 */ 	lw	$t6,0x168($sp)
/*    1bfc8:	afaf0158 */ 	sw	$t7,0x158($sp)
/*    1bfcc:	8cb00020 */ 	lw	$s0,0x20($a1)
/*    1bfd0:	52000154 */ 	beqzl	$s0,.L0001c524
/*    1bfd4:	8dc50008 */ 	lw	$a1,0x8($t6)
/*    1bfd8:	95f9000c */ 	lhu	$t9,0xc($t7)
/*    1bfdc:	3c098006 */ 	lui	$t1,%hi(g_Anims)
/*    1bfe0:	27b80144 */ 	addiu	$t8,$sp,0x144
/*    1bfe4:	afb90154 */ 	sw	$t9,0x154($sp)
/*    1bfe8:	8ca20008 */ 	lw	$v0,0x8($a1)
/*    1bfec:	3c013f80 */ 	lui	$at,0x3f80
/*    1bff0:	8c480004 */ 	lw	$t0,0x4($v0)
/*    1bff4:	afa80150 */ 	sw	$t0,0x150($sp)
/*    1bff8:	86070000 */ 	lh	$a3,0x0($s0)
/*    1bffc:	27a80138 */ 	addiu	$t0,$sp,0x138
/*    1c000:	10e0004e */ 	beqz	$a3,.L0001c13c
/*    1c004:	00075080 */ 	sll	$t2,$a3,0x2
/*    1c008:	8d29f00c */ 	lw	$t1,%lo(g_Anims)($t1)
/*    1c00c:	01475023 */ 	subu	$t2,$t2,$a3
/*    1c010:	000a5080 */ 	sll	$t2,$t2,0x2
/*    1c014:	012a5821 */ 	addu	$t3,$t1,$t2
/*    1c018:	9163000b */ 	lbu	$v1,0xb($t3)
/*    1c01c:	27a9012c */ 	addiu	$t1,$sp,0x12c
/*    1c020:	306c0002 */ 	andi	$t4,$v1,0x2
/*    1c024:	000c182b */ 	sltu	$v1,$zero,$t4
/*    1c028:	50600005 */ 	beqzl	$v1,.L0001c040
/*    1c02c:	afa30128 */ 	sw	$v1,0x128($sp)
/*    1c030:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*    1c034:	00cf1826 */ 	xor	$v1,$a2,$t7
/*    1c038:	2c630001 */ 	sltiu	$v1,$v1,0x1
/*    1c03c:	afa30128 */ 	sw	$v1,0x128($sp)
.L0001c040:
/*    1c040:	92190004 */ 	lbu	$t9,0x4($s0)
/*    1c044:	82050008 */ 	lb	$a1,0x8($s0)
/*    1c048:	afa3003c */ 	sw	$v1,0x3c($sp)
/*    1c04c:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    1c050:	afa80018 */ 	sw	$t0,0x18($sp)
/*    1c054:	afb80014 */ 	sw	$t8,0x14($sp)
/*    1c058:	8fa40154 */ 	lw	$a0,0x154($sp)
/*    1c05c:	8fa60150 */ 	lw	$a2,0x150($sp)
/*    1c060:	0c009014 */ 	jal	func00024050
/*    1c064:	afb90010 */ 	sw	$t9,0x10($sp)
/*    1c068:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x4cc)
/*    1c06c:	8d4aa48c */ 	lw	$t2,%lo(g_Vars+0x4cc)($t2)
/*    1c070:	51400010 */ 	beqzl	$t2,.L0001c0b4
/*    1c074:	44807000 */ 	mtc1	$zero,$f14
/*    1c078:	44807000 */ 	mtc1	$zero,$f14
/*    1c07c:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*    1c080:	4600703c */ 	c.lt.s	$f14,$f0
/*    1c084:	00000000 */ 	nop
/*    1c088:	4502000a */ 	bc1fl	.L0001c0b4
/*    1c08c:	44807000 */ 	mtc1	$zero,$f14
/*    1c090:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*    1c094:	0fc25e24 */ 	jal	floorf
/*    1c098:	46002303 */ 	div.s	$f12,$f4,$f0
/*    1c09c:	c606001c */ 	lwc1	$f6,0x1c($s0)
/*    1c0a0:	44807000 */ 	mtc1	$zero,$f14
/*    1c0a4:	46060082 */ 	mul.s	$f2,$f0,$f6
/*    1c0a8:	10000004 */ 	b	.L0001c0bc
/*    1c0ac:	460e1032 */ 	c.eq.s	$f2,$f14
/*    1c0b0:	44807000 */ 	mtc1	$zero,$f14
.L0001c0b4:
/*    1c0b4:	c6020010 */ 	lwc1	$f2,0x10($s0)
/*    1c0b8:	460e1032 */ 	c.eq.s	$f2,$f14
.L0001c0bc:
/*    1c0bc:	8fa40154 */ 	lw	$a0,0x154($sp)
/*    1c0c0:	8fa60150 */ 	lw	$a2,0x150($sp)
/*    1c0c4:	27ac00d4 */ 	addiu	$t4,$sp,0xd4
/*    1c0c8:	45010019 */ 	bc1t	.L0001c130
/*    1c0cc:	27ad00c8 */ 	addiu	$t5,$sp,0xc8
/*    1c0d0:	920b0005 */ 	lbu	$t3,0x5($s0)
/*    1c0d4:	82050008 */ 	lb	$a1,0x8($s0)
/*    1c0d8:	86070000 */ 	lh	$a3,0x0($s0)
/*    1c0dc:	27ae00bc */ 	addiu	$t6,$sp,0xbc
/*    1c0e0:	afae001c */ 	sw	$t6,0x1c($sp)
/*    1c0e4:	e7a200e0 */ 	swc1	$f2,0xe0($sp)
/*    1c0e8:	afad0018 */ 	sw	$t5,0x18($sp)
/*    1c0ec:	afac0014 */ 	sw	$t4,0x14($sp)
/*    1c0f0:	0c009014 */ 	jal	func00024050
/*    1c0f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*    1c0f8:	c7a200e0 */ 	lwc1	$f2,0xe0($sp)
/*    1c0fc:	27a40144 */ 	addiu	$a0,$sp,0x144
/*    1c100:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*    1c104:	44061000 */ 	mfc1	$a2,$f2
/*    1c108:	0c006c1f */ 	jal	func0001b07c
/*    1c10c:	00000000 */ 	nop
/*    1c110:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    1c114:	c7a200e0 */ 	lwc1	$f2,0xe0($sp)
/*    1c118:	27a40138 */ 	addiu	$a0,$sp,0x138
/*    1c11c:	51e00005 */ 	beqzl	$t7,.L0001c134
/*    1c120:	44807000 */ 	mtc1	$zero,$f14
/*    1c124:	44061000 */ 	mfc1	$a2,$f2
/*    1c128:	0c006be6 */ 	jal	func0001af98
/*    1c12c:	27a500c8 */ 	addiu	$a1,$sp,0xc8
.L0001c130:
/*    1c130:	44807000 */ 	mtc1	$zero,$f14
.L0001c134:
/*    1c134:	10000010 */ 	b	.L0001c178
/*    1c138:	c60a0054 */ 	lwc1	$f10,0x54($s0)
.L0001c13c:
/*    1c13c:	44800000 */ 	mtc1	$zero,$f0
/*    1c140:	44801000 */ 	mtc1	$zero,$f2
/*    1c144:	44807000 */ 	mtc1	$zero,$f14
/*    1c148:	e7a00140 */ 	swc1	$f0,0x140($sp)
/*    1c14c:	e7a0013c */ 	swc1	$f0,0x13c($sp)
/*    1c150:	e7a00138 */ 	swc1	$f0,0x138($sp)
/*    1c154:	44810000 */ 	mtc1	$at,$f0
/*    1c158:	afa00128 */ 	sw	$zero,0x128($sp)
/*    1c15c:	e7a20148 */ 	swc1	$f2,0x148($sp)
/*    1c160:	e7a20144 */ 	swc1	$f2,0x144($sp)
/*    1c164:	e7a2014c */ 	swc1	$f2,0x14c($sp)
/*    1c168:	e7a00130 */ 	swc1	$f0,0x130($sp)
/*    1c16c:	e7a0012c */ 	swc1	$f0,0x12c($sp)
/*    1c170:	e7a00134 */ 	swc1	$f0,0x134($sp)
/*    1c174:	c60a0054 */ 	lwc1	$f10,0x54($s0)
.L0001c178:
/*    1c178:	8fa40154 */ 	lw	$a0,0x154($sp)
/*    1c17c:	8fa60150 */ 	lw	$a2,0x150($sp)
/*    1c180:	460a7032 */ 	c.eq.s	$f14,$f10
/*    1c184:	27b800b0 */ 	addiu	$t8,$sp,0xb0
/*    1c188:	27a800a4 */ 	addiu	$t0,$sp,0xa4
/*    1c18c:	27a90098 */ 	addiu	$t1,$sp,0x98
/*    1c190:	4501007a */ 	bc1t	.L0001c37c
/*    1c194:	8faf0128 */ 	lw	$t7,0x128($sp)
/*    1c198:	92190006 */ 	lbu	$t9,0x6($s0)
/*    1c19c:	82050009 */ 	lb	$a1,0x9($s0)
/*    1c1a0:	86070002 */ 	lh	$a3,0x2($s0)
/*    1c1a4:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    1c1a8:	afa80018 */ 	sw	$t0,0x18($sp)
/*    1c1ac:	afb80014 */ 	sw	$t8,0x14($sp)
/*    1c1b0:	0c009014 */ 	jal	func00024050
/*    1c1b4:	afb90010 */ 	sw	$t9,0x10($sp)
/*    1c1b8:	44808000 */ 	mtc1	$zero,$f16
/*    1c1bc:	c6120034 */ 	lwc1	$f18,0x34($s0)
/*    1c1c0:	8fa40154 */ 	lw	$a0,0x154($sp)
/*    1c1c4:	8fa60150 */ 	lw	$a2,0x150($sp)
/*    1c1c8:	46128032 */ 	c.eq.s	$f16,$f18
/*    1c1cc:	27ab005c */ 	addiu	$t3,$sp,0x5c
/*    1c1d0:	27ac0050 */ 	addiu	$t4,$sp,0x50
/*    1c1d4:	27ad0044 */ 	addiu	$t5,$sp,0x44
/*    1c1d8:	4503000e */ 	bc1tl	.L0001c214
/*    1c1dc:	27a40144 */ 	addiu	$a0,$sp,0x144
/*    1c1e0:	920a0007 */ 	lbu	$t2,0x7($s0)
/*    1c1e4:	82050009 */ 	lb	$a1,0x9($s0)
/*    1c1e8:	86070002 */ 	lh	$a3,0x2($s0)
/*    1c1ec:	afad001c */ 	sw	$t5,0x1c($sp)
/*    1c1f0:	afac0018 */ 	sw	$t4,0x18($sp)
/*    1c1f4:	afab0014 */ 	sw	$t3,0x14($sp)
/*    1c1f8:	0c009014 */ 	jal	func00024050
/*    1c1fc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    1c200:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*    1c204:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*    1c208:	0c006c1f */ 	jal	func0001b07c
/*    1c20c:	8e060034 */ 	lw	$a2,0x34($s0)
/*    1c210:	27a40144 */ 	addiu	$a0,$sp,0x144
.L0001c214:
/*    1c214:	0fc25b28 */ 	jal	func0f096ca0
/*    1c218:	27a50088 */ 	addiu	$a1,$sp,0x88
/*    1c21c:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*    1c220:	0fc25b28 */ 	jal	func0f096ca0
/*    1c224:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    1c228:	27a40088 */ 	addiu	$a0,$sp,0x88
/*    1c22c:	0fc25db0 */ 	jal	func0f0976c0
/*    1c230:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    1c234:	27a70068 */ 	addiu	$a3,$sp,0x68
/*    1c238:	27a40088 */ 	addiu	$a0,$sp,0x88
/*    1c23c:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    1c240:	0fc25cae */ 	jal	func0f0972b8
/*    1c244:	8e060054 */ 	lw	$a2,0x54($s0)
/*    1c248:	44802000 */ 	mtc1	$zero,$f4
/*    1c24c:	c7a60138 */ 	lwc1	$f6,0x138($sp)
/*    1c250:	27a70068 */ 	addiu	$a3,$sp,0x68
/*    1c254:	c7aa013c */ 	lwc1	$f10,0x13c($sp)
/*    1c258:	46062032 */ 	c.eq.s	$f4,$f6
/*    1c25c:	c7a40138 */ 	lwc1	$f4,0x138($sp)
/*    1c260:	27b90138 */ 	addiu	$t9,$sp,0x138
/*    1c264:	27b8012c */ 	addiu	$t8,$sp,0x12c
/*    1c268:	4502000e */ 	bc1fl	.L0001c2a4
/*    1c26c:	c6060088 */ 	lwc1	$f6,0x88($s0)
/*    1c270:	44804000 */ 	mtc1	$zero,$f8
/*    1c274:	c7b20140 */ 	lwc1	$f18,0x140($sp)
/*    1c278:	460a4032 */ 	c.eq.s	$f8,$f10
/*    1c27c:	00000000 */ 	nop
/*    1c280:	45020008 */ 	bc1fl	.L0001c2a4
/*    1c284:	c6060088 */ 	lwc1	$f6,0x88($s0)
/*    1c288:	44808000 */ 	mtc1	$zero,$f16
/*    1c28c:	8fa80164 */ 	lw	$t0,0x164($sp)
/*    1c290:	46128032 */ 	c.eq.s	$f16,$f18
/*    1c294:	00000000 */ 	nop
/*    1c298:	45030023 */ 	bc1tl	.L0001c328
/*    1c29c:	8d090008 */ 	lw	$t1,0x8($t0)
/*    1c2a0:	c6060088 */ 	lwc1	$f6,0x88($s0)
.L0001c2a4:
/*    1c2a4:	c7aa013c */ 	lwc1	$f10,0x13c($sp)
/*    1c2a8:	8fa50164 */ 	lw	$a1,0x164($sp)
/*    1c2ac:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1c2b0:	c7a40140 */ 	lwc1	$f4,0x140($sp)
/*    1c2b4:	8fa60168 */ 	lw	$a2,0x168($sp)
/*    1c2b8:	8fa20158 */ 	lw	$v0,0x158($sp)
/*    1c2bc:	e7a80138 */ 	swc1	$f8,0x138($sp)
/*    1c2c0:	c6100088 */ 	lwc1	$f16,0x88($s0)
/*    1c2c4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1c2c8:	e7b2013c */ 	swc1	$f18,0x13c($sp)
/*    1c2cc:	c6060088 */ 	lwc1	$f6,0x88($s0)
/*    1c2d0:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    1c2d4:	e7aa0140 */ 	swc1	$f10,0x140($sp)
/*    1c2d8:	8cae0008 */ 	lw	$t6,0x8($a1)
/*    1c2dc:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    1c2e0:	50cf000b */ 	beql	$a2,$t7,.L0001c310
/*    1c2e4:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c2e8:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*    1c2ec:	46104100 */ 	add.s	$f4,$f8,$f16
/*    1c2f0:	e7a40138 */ 	swc1	$f4,0x138($sp)
/*    1c2f4:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*    1c2f8:	46069200 */ 	add.s	$f8,$f18,$f6
/*    1c2fc:	e7a8013c */ 	swc1	$f8,0x13c($sp)
/*    1c300:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*    1c304:	46105100 */ 	add.s	$f4,$f10,$f16
/*    1c308:	e7a40140 */ 	swc1	$f4,0x140($sp)
/*    1c30c:	8fa40160 */ 	lw	$a0,0x160($sp)
.L0001c310:
/*    1c310:	afb90010 */ 	sw	$t9,0x10($sp)
/*    1c314:	0c006f05 */ 	jal	func0001bc14
/*    1c318:	afb80014 */ 	sw	$t8,0x14($sp)
/*    1c31c:	100000a1 */ 	b	.L0001c5a4
/*    1c320:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1c324:	8d090008 */ 	lw	$t1,0x8($t0)
.L0001c328:
/*    1c328:	8fa60168 */ 	lw	$a2,0x168($sp)
/*    1c32c:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c330:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    1c334:	8fa50164 */ 	lw	$a1,0x164($sp)
/*    1c338:	27ad0138 */ 	addiu	$t5,$sp,0x138
/*    1c33c:	10ca000a */ 	beq	$a2,$t2,.L0001c368
/*    1c340:	27ae012c */ 	addiu	$t6,$sp,0x12c
/*    1c344:	8fab0158 */ 	lw	$t3,0x158($sp)
/*    1c348:	27ac012c */ 	addiu	$t4,$sp,0x12c
/*    1c34c:	afac0014 */ 	sw	$t4,0x14($sp)
/*    1c350:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c354:	01002825 */ 	or	$a1,$t0,$zero
/*    1c358:	0c006f05 */ 	jal	func0001bc14
/*    1c35c:	afab0010 */ 	sw	$t3,0x10($sp)
/*    1c360:	10000090 */ 	b	.L0001c5a4
/*    1c364:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001c368:
/*    1c368:	afad0010 */ 	sw	$t5,0x10($sp)
/*    1c36c:	0c006f05 */ 	jal	func0001bc14
/*    1c370:	afae0014 */ 	sw	$t6,0x14($sp)
/*    1c374:	1000008b */ 	b	.L0001c5a4
/*    1c378:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001c37c:
/*    1c37c:	11e00019 */ 	beqz	$t7,.L0001c3e4
/*    1c380:	c7b20138 */ 	lwc1	$f18,0x138($sp)
/*    1c384:	0fc57222 */ 	jal	func0f15c888
/*    1c388:	00000000 */ 	nop
/*    1c38c:	c7b20138 */ 	lwc1	$f18,0x138($sp)
/*    1c390:	c7a8013c */ 	lwc1	$f8,0x13c($sp)
/*    1c394:	c7b00140 */ 	lwc1	$f16,0x140($sp)
/*    1c398:	46009182 */ 	mul.s	$f6,$f18,$f0
/*    1c39c:	27b90138 */ 	addiu	$t9,$sp,0x138
/*    1c3a0:	24180001 */ 	addiu	$t8,$zero,0x1
/*    1c3a4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*    1c3a8:	27a9012c */ 	addiu	$t1,$sp,0x12c
/*    1c3ac:	afa90018 */ 	sw	$t1,0x18($sp)
/*    1c3b0:	46008102 */ 	mul.s	$f4,$f16,$f0
/*    1c3b4:	e7a60138 */ 	swc1	$f6,0x138($sp)
/*    1c3b8:	afb80014 */ 	sw	$t8,0x14($sp)
/*    1c3bc:	afb90010 */ 	sw	$t9,0x10($sp)
/*    1c3c0:	e7aa013c */ 	swc1	$f10,0x13c($sp)
/*    1c3c4:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c3c8:	8fa50164 */ 	lw	$a1,0x164($sp)
/*    1c3cc:	e7a40140 */ 	swc1	$f4,0x140($sp)
/*    1c3d0:	8fa60168 */ 	lw	$a2,0x168($sp)
/*    1c3d4:	0c006e03 */ 	jal	func0001b80c
/*    1c3d8:	27a70144 */ 	addiu	$a3,$sp,0x144
/*    1c3dc:	10000071 */ 	b	.L0001c5a4
/*    1c3e0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001c3e4:
/*    1c3e4:	46127032 */ 	c.eq.s	$f14,$f18
/*    1c3e8:	c7a6013c */ 	lwc1	$f6,0x13c($sp)
/*    1c3ec:	c7aa0138 */ 	lwc1	$f10,0x138($sp)
/*    1c3f0:	27a70144 */ 	addiu	$a3,$sp,0x144
/*    1c3f4:	45000009 */ 	bc1f	.L0001c41c
/*    1c3f8:	27ae0138 */ 	addiu	$t6,$sp,0x138
/*    1c3fc:	46067032 */ 	c.eq.s	$f14,$f6
/*    1c400:	c7a80140 */ 	lwc1	$f8,0x140($sp)
/*    1c404:	45020006 */ 	bc1fl	.L0001c420
/*    1c408:	c6100088 */ 	lwc1	$f16,0x88($s0)
/*    1c40c:	46087032 */ 	c.eq.s	$f14,$f8
/*    1c410:	8fb80164 */ 	lw	$t8,0x164($sp)
/*    1c414:	45030027 */ 	bc1tl	.L0001c4b4
/*    1c418:	8f090008 */ 	lw	$t1,0x8($t8)
.L0001c41c:
/*    1c41c:	c6100088 */ 	lwc1	$f16,0x88($s0)
.L0001c420:
/*    1c420:	c7b2013c */ 	lwc1	$f18,0x13c($sp)
/*    1c424:	8fa80164 */ 	lw	$t0,0x164($sp)
/*    1c428:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    1c42c:	c7aa0140 */ 	lwc1	$f10,0x140($sp)
/*    1c430:	8faa0168 */ 	lw	$t2,0x168($sp)
/*    1c434:	8fad0158 */ 	lw	$t5,0x158($sp)
/*    1c438:	27af012c */ 	addiu	$t7,$sp,0x12c
/*    1c43c:	e7a40138 */ 	swc1	$f4,0x138($sp)
/*    1c440:	c6060088 */ 	lwc1	$f6,0x88($s0)
/*    1c444:	46069202 */ 	mul.s	$f8,$f18,$f6
/*    1c448:	e7a8013c */ 	swc1	$f8,0x13c($sp)
/*    1c44c:	c6100088 */ 	lwc1	$f16,0x88($s0)
/*    1c450:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1c454:	e7b20140 */ 	swc1	$f18,0x140($sp)
/*    1c458:	8d0b0008 */ 	lw	$t3,0x8($t0)
/*    1c45c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    1c460:	514c000b */ 	beql	$t2,$t4,.L0001c490
/*    1c464:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c468:	c5a60000 */ 	lwc1	$f6,0x0($t5)
/*    1c46c:	46062280 */ 	add.s	$f10,$f4,$f6
/*    1c470:	e7aa0138 */ 	swc1	$f10,0x138($sp)
/*    1c474:	c5b00004 */ 	lwc1	$f16,0x4($t5)
/*    1c478:	46104100 */ 	add.s	$f4,$f8,$f16
/*    1c47c:	e7a4013c */ 	swc1	$f4,0x13c($sp)
/*    1c480:	c5a60008 */ 	lwc1	$f6,0x8($t5)
/*    1c484:	46069280 */ 	add.s	$f10,$f18,$f6
/*    1c488:	e7aa0140 */ 	swc1	$f10,0x140($sp)
/*    1c48c:	8fa40160 */ 	lw	$a0,0x160($sp)
.L0001c490:
/*    1c490:	8fa50164 */ 	lw	$a1,0x164($sp)
/*    1c494:	8fa60168 */ 	lw	$a2,0x168($sp)
/*    1c498:	afae0010 */ 	sw	$t6,0x10($sp)
/*    1c49c:	afa00014 */ 	sw	$zero,0x14($sp)
/*    1c4a0:	0c006e03 */ 	jal	func0001b80c
/*    1c4a4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    1c4a8:	1000003e */ 	b	.L0001c5a4
/*    1c4ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1c4b0:	8f090008 */ 	lw	$t1,0x8($t8)
.L0001c4b4:
/*    1c4b4:	8fb90168 */ 	lw	$t9,0x168($sp)
/*    1c4b8:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c4bc:	8d280000 */ 	lw	$t0,0x0($t1)
/*    1c4c0:	8fa50164 */ 	lw	$a1,0x164($sp)
/*    1c4c4:	8fa60168 */ 	lw	$a2,0x168($sp)
/*    1c4c8:	1328000d */ 	beq	$t9,$t0,.L0001c500
/*    1c4cc:	27a70144 */ 	addiu	$a3,$sp,0x144
/*    1c4d0:	8fab0158 */ 	lw	$t3,0x158($sp)
/*    1c4d4:	27aa012c */ 	addiu	$t2,$sp,0x12c
/*    1c4d8:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    1c4dc:	8fa40160 */ 	lw	$a0,0x160($sp)
/*    1c4e0:	03002825 */ 	or	$a1,$t8,$zero
/*    1c4e4:	03203025 */ 	or	$a2,$t9,$zero
/*    1c4e8:	27a70144 */ 	addiu	$a3,$sp,0x144
/*    1c4ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*    1c4f0:	0c006e03 */ 	jal	func0001b80c
/*    1c4f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*    1c4f8:	1000002a */ 	b	.L0001c5a4
/*    1c4fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001c500:
/*    1c500:	27ac0138 */ 	addiu	$t4,$sp,0x138
/*    1c504:	27ad012c */ 	addiu	$t5,$sp,0x12c
/*    1c508:	afad0018 */ 	sw	$t5,0x18($sp)
/*    1c50c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    1c510:	0c006e03 */ 	jal	func0001b80c
/*    1c514:	afa00014 */ 	sw	$zero,0x14($sp)
/*    1c518:	10000022 */ 	b	.L0001c5a4
/*    1c51c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1c520:	8dc50008 */ 	lw	$a1,0x8($t6)
.L0001c524:
/*    1c524:	8fa40164 */ 	lw	$a0,0x164($sp)
/*    1c528:	8faf0160 */ 	lw	$t7,0x160($sp)
/*    1c52c:	50a00006 */ 	beqzl	$a1,.L0001c548
/*    1c530:	8df00000 */ 	lw	$s0,0x0($t7)
/*    1c534:	0c006973 */ 	jal	func0001a5cc
/*    1c538:	00003025 */ 	or	$a2,$zero,$zero
/*    1c53c:	10000002 */ 	b	.L0001c548
/*    1c540:	00408025 */ 	or	$s0,$v0,$zero
/*    1c544:	8df00000 */ 	lw	$s0,0x0($t7)
.L0001c548:
/*    1c548:	1200000f */ 	beqz	$s0,.L0001c588
/*    1c54c:	8fa40158 */ 	lw	$a0,0x158($sp)
/*    1c550:	8fa40158 */ 	lw	$a0,0x158($sp)
/*    1c554:	0c0059b7 */ 	jal	func000166dc
/*    1c558:	27a500e8 */ 	addiu	$a1,$sp,0xe8
/*    1c55c:	8fb80158 */ 	lw	$t8,0x158($sp)
/*    1c560:	8fa90164 */ 	lw	$t1,0x164($sp)
/*    1c564:	02002025 */ 	or	$a0,$s0,$zero
/*    1c568:	8719000e */ 	lh	$t9,0xe($t8)
/*    1c56c:	8d28000c */ 	lw	$t0,0xc($t1)
/*    1c570:	27a500e8 */ 	addiu	$a1,$sp,0xe8
/*    1c574:	00195980 */ 	sll	$t3,$t9,0x6
/*    1c578:	0c0056f9 */ 	jal	func00015be4
/*    1c57c:	010b3021 */ 	addu	$a2,$t0,$t3
/*    1c580:	10000008 */ 	b	.L0001c5a4
/*    1c584:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001c588:
/*    1c588:	8fac0164 */ 	lw	$t4,0x164($sp)
/*    1c58c:	848e000e */ 	lh	$t6,0xe($a0)
/*    1c590:	8d8d000c */ 	lw	$t5,0xc($t4)
/*    1c594:	000e7980 */ 	sll	$t7,$t6,0x6
/*    1c598:	0c0059b7 */ 	jal	func000166dc
/*    1c59c:	01af2821 */ 	addu	$a1,$t5,$t7
/*    1c5a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001c5a4:
/*    1c5a4:	8fb00028 */ 	lw	$s0,0x28($sp)
/*    1c5a8:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*    1c5ac:	03e00008 */ 	jr	$ra
/*    1c5b0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c5b4
/*    1c5b4:	27bdff90 */ 	addiu	$sp,$sp,-112
/*    1c5b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1c5bc:	afa50074 */ 	sw	$a1,0x74($sp)
/*    1c5c0:	8cce0004 */ 	lw	$t6,0x4($a2)
/*    1c5c4:	afae006c */ 	sw	$t6,0x6c($sp)
/*    1c5c8:	8cc70008 */ 	lw	$a3,0x8($a2)
/*    1c5cc:	8ca8000c */ 	lw	$t0,0xc($a1)
/*    1c5d0:	00003025 */ 	or	$a2,$zero,$zero
/*    1c5d4:	10e0000a */ 	beqz	$a3,.L0001c600
/*    1c5d8:	85c3000c */ 	lh	$v1,0xc($t6)
/*    1c5dc:	00a02025 */ 	or	$a0,$a1,$zero
/*    1c5e0:	00e02825 */ 	or	$a1,$a3,$zero
/*    1c5e4:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1c5e8:	0c006973 */ 	jal	func0001a5cc
/*    1c5ec:	afa80020 */ 	sw	$t0,0x20($sp)
/*    1c5f0:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1c5f4:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    1c5f8:	10000002 */ 	b	.L0001c604
/*    1c5fc:	00403825 */ 	or	$a3,$v0,$zero
.L0001c600:
/*    1c600:	8c870000 */ 	lw	$a3,0x0($a0)
.L0001c604:
/*    1c604:	10e00010 */ 	beqz	$a3,.L0001c648
/*    1c608:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*    1c60c:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*    1c610:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    1c614:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1c618:	afa70068 */ 	sw	$a3,0x68($sp)
/*    1c61c:	0c0059b7 */ 	jal	func000166dc
/*    1c620:	afa80020 */ 	sw	$t0,0x20($sp)
/*    1c624:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1c628:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    1c62c:	8fa40068 */ 	lw	$a0,0x68($sp)
/*    1c630:	0003c980 */ 	sll	$t9,$v1,0x6
/*    1c634:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    1c638:	0c0056f9 */ 	jal	func00015be4
/*    1c63c:	03283021 */ 	addu	$a2,$t9,$t0
/*    1c640:	10000005 */ 	b	.L0001c658
/*    1c644:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001c648:
/*    1c648:	00034980 */ 	sll	$t1,$v1,0x6
/*    1c64c:	0c0059b7 */ 	jal	func000166dc
/*    1c650:	01282821 */ 	addu	$a1,$t1,$t0
/*    1c654:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001c658:
/*    1c658:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*    1c65c:	03e00008 */ 	jr	$ra
/*    1c660:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c664
/*    1c664:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    1c668:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1c66c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1c670:	afa40030 */ 	sw	$a0,0x30($sp)
/*    1c674:	8cae0004 */ 	lw	$t6,0x4($a1)
/*    1c678:	00a08025 */ 	or	$s0,$a1,$zero
/*    1c67c:	0c006a87 */ 	jal	modelGetNodeData
/*    1c680:	afae002c */ 	sw	$t6,0x2c($sp)
/*    1c684:	afa20028 */ 	sw	$v0,0x28($sp)
/*    1c688:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    1c68c:	02002825 */ 	or	$a1,$s0,$zero
/*    1c690:	0c006973 */ 	jal	func0001a5cc
/*    1c694:	00003025 */ 	or	$a2,$zero,$zero
/*    1c698:	3c0f8006 */ 	lui	$t7,%hi(var8005efb4)
/*    1c69c:	8defefb4 */ 	lw	$t7,%lo(var8005efb4)($t7)
/*    1c6a0:	00401825 */ 	or	$v1,$v0,$zero
/*    1c6a4:	55e00004 */ 	bnezl	$t7,.L0001c6b8
/*    1c6a8:	44801000 */ 	mtc1	$zero,$f2
/*    1c6ac:	14400004 */ 	bnez	$v0,.L0001c6c0
/*    1c6b0:	00000000 */ 	nop
/*    1c6b4:	44801000 */ 	mtc1	$zero,$f2
.L0001c6b8:
/*    1c6b8:	10000011 */ 	b	.L0001c700
/*    1c6bc:	8fa2002c */ 	lw	$v0,0x2c($sp)
.L0001c6c0:
/*    1c6c0:	0fc2d5ee */ 	jal	currentPlayerGetLodScaleZ
/*    1c6c4:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1c6c8:	3c018006 */ 	lui	$at,0x8006
/*    1c6cc:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1c6d0:	c42cefb8 */ 	lwc1	$f12,-0x1048($at)
/*    1c6d4:	3c013f80 */ 	lui	$at,0x3f80
/*    1c6d8:	44814000 */ 	mtc1	$at,$f8
/*    1c6dc:	c4640038 */ 	lwc1	$f4,0x38($v1)
/*    1c6e0:	460c4032 */ 	c.eq.s	$f8,$f12
/*    1c6e4:	46002187 */ 	neg.s	$f6,$f4
/*    1c6e8:	46060082 */ 	mul.s	$f2,$f0,$f6
/*    1c6ec:	45030004 */ 	bc1tl	.L0001c700
/*    1c6f0:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*    1c6f4:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*    1c6f8:	00000000 */ 	nop
/*    1c6fc:	8fa2002c */ 	lw	$v0,0x2c($sp)
.L0001c700:
/*    1c700:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    1c704:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*    1c708:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*    1c70c:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*    1c710:	4602503c */ 	c.lt.s	$f10,$f2
/*    1c714:	00000000 */ 	nop
/*    1c718:	45030008 */ 	bc1tl	.L0001c73c
/*    1c71c:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*    1c720:	44808000 */ 	mtc1	$zero,$f16
/*    1c724:	00000000 */ 	nop
/*    1c728:	46008032 */ 	c.eq.s	$f16,$f0
/*    1c72c:	00000000 */ 	nop
/*    1c730:	4502000d */ 	bc1fl	.L0001c768
/*    1c734:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    1c738:	c4520004 */ 	lwc1	$f18,0x4($v0)
.L0001c73c:
/*    1c73c:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    1c740:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*    1c744:	4604103e */ 	c.le.s	$f2,$f4
/*    1c748:	00000000 */ 	nop
/*    1c74c:	45000005 */ 	bc1f	.L0001c764
/*    1c750:	24190001 */ 	addiu	$t9,$zero,0x1
/*    1c754:	ad190000 */ 	sw	$t9,0x0($t0)
/*    1c758:	8c490008 */ 	lw	$t1,0x8($v0)
/*    1c75c:	10000004 */ 	b	.L0001c770
/*    1c760:	ae090014 */ 	sw	$t1,0x14($s0)
.L0001c764:
/*    1c764:	8faa0028 */ 	lw	$t2,0x28($sp)
.L0001c768:
/*    1c768:	ad400000 */ 	sw	$zero,0x0($t2)
/*    1c76c:	ae000014 */ 	sw	$zero,0x14($s0)
.L0001c770:
/*    1c770:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1c774:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1c778:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    1c77c:	03e00008 */ 	jr	$ra
/*    1c780:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c784
/*    1c784:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1c788:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1c78c:	8cae0004 */ 	lw	$t6,0x4($a1)
/*    1c790:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1c794:	0c006a87 */ 	jal	modelGetNodeData
/*    1c798:	afae001c */ 	sw	$t6,0x1c($sp)
/*    1c79c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*    1c7a0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    1c7a4:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    1c7a8:	51e00005 */ 	beqzl	$t7,.L0001c7c0
/*    1c7ac:	aca00014 */ 	sw	$zero,0x14($a1)
/*    1c7b0:	8f190008 */ 	lw	$t9,0x8($t8)
/*    1c7b4:	10000002 */ 	b	.L0001c7c0
/*    1c7b8:	acb90014 */ 	sw	$t9,0x14($a1)
/*    1c7bc:	aca00014 */ 	sw	$zero,0x14($a1)
.L0001c7c0:
/*    1c7c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1c7c4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1c7c8:	03e00008 */ 	jr	$ra
/*    1c7cc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c7d0
/*    1c7d0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1c7d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1c7d8:	8cae0004 */ 	lw	$t6,0x4($a1)
/*    1c7dc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1c7e0:	0c006a87 */ 	jal	modelGetNodeData
/*    1c7e4:	afae001c */ 	sw	$t6,0x1c($sp)
/*    1c7e8:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*    1c7ec:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    1c7f0:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    1c7f4:	51e00005 */ 	beqzl	$t7,.L0001c80c
/*    1c7f8:	aca00014 */ 	sw	$zero,0x14($a1)
/*    1c7fc:	8f190000 */ 	lw	$t9,0x0($t8)
/*    1c800:	10000002 */ 	b	.L0001c80c
/*    1c804:	acb90014 */ 	sw	$t9,0x14($a1)
/*    1c808:	aca00014 */ 	sw	$zero,0x14($a1)
.L0001c80c:
/*    1c80c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1c810:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1c814:	03e00008 */ 	jr	$ra
/*    1c818:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c81c
/*    1c81c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1c820:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1c824:	0c006a87 */ 	jal	modelGetNodeData
/*    1c828:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    1c82c:	8c440000 */ 	lw	$a0,0x0($v0)
/*    1c830:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1c834:	50800009 */ 	beqzl	$a0,.L0001c85c
/*    1c838:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1c83c:	8c830000 */ 	lw	$v1,0x0($a0)
/*    1c840:	10600005 */ 	beqz	$v1,.L0001c858
/*    1c844:	aca30014 */ 	sw	$v1,0x14($a1)
/*    1c848:	ac650008 */ 	sw	$a1,0x8($v1)
.L0001c84c:
/*    1c84c:	8c63000c */ 	lw	$v1,0xc($v1)
/*    1c850:	5460fffe */ 	bnezl	$v1,.L0001c84c
/*    1c854:	ac650008 */ 	sw	$a1,0x8($v1)
.L0001c858:
/*    1c858:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001c85c:
/*    1c85c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1c860:	03e00008 */ 	jr	$ra
/*    1c864:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c868
/*    1c868:	10a00004 */ 	beqz	$a1,.L0001c87c
/*    1c86c:	8c820004 */ 	lw	$v0,0x4($a0)
/*    1c870:	8c430018 */ 	lw	$v1,0x18($v0)
/*    1c874:	10000003 */ 	b	.L0001c884
/*    1c878:	8c45001c */ 	lw	$a1,0x1c($v0)
.L0001c87c:
/*    1c87c:	8c43001c */ 	lw	$v1,0x1c($v0)
/*    1c880:	8c450018 */ 	lw	$a1,0x18($v0)
.L0001c884:
/*    1c884:	10600022 */ 	beqz	$v1,.L0001c910
/*    1c888:	00000000 */ 	nop
/*    1c88c:	ac830014 */ 	sw	$v1,0x14($a0)
/*    1c890:	8c66000c */ 	lw	$a2,0xc($v1)
/*    1c894:	ac600010 */ 	sw	$zero,0x10($v1)
/*    1c898:	00601025 */ 	or	$v0,$v1,$zero
/*    1c89c:	10c0000a */ 	beqz	$a2,.L0001c8c8
/*    1c8a0:	00000000 */ 	nop
/*    1c8a4:	10a60008 */ 	beq	$a1,$a2,.L0001c8c8
/*    1c8a8:	00000000 */ 	nop
/*    1c8ac:	8c44000c */ 	lw	$a0,0xc($v0)
/*    1c8b0:	00801025 */ 	or	$v0,$a0,$zero
.L0001c8b4:
/*    1c8b4:	8c84000c */ 	lw	$a0,0xc($a0)
/*    1c8b8:	10800003 */ 	beqz	$a0,.L0001c8c8
/*    1c8bc:	00000000 */ 	nop
/*    1c8c0:	54a4fffc */ 	bnel	$a1,$a0,.L0001c8b4
/*    1c8c4:	00801025 */ 	or	$v0,$a0,$zero
.L0001c8c8:
/*    1c8c8:	10a00014 */ 	beqz	$a1,.L0001c91c
/*    1c8cc:	ac45000c */ 	sw	$a1,0xc($v0)
/*    1c8d0:	8ca4000c */ 	lw	$a0,0xc($a1)
/*    1c8d4:	aca20010 */ 	sw	$v0,0x10($a1)
/*    1c8d8:	00a01025 */ 	or	$v0,$a1,$zero
/*    1c8dc:	1080000a */ 	beqz	$a0,.L0001c908
/*    1c8e0:	00000000 */ 	nop
/*    1c8e4:	10640008 */ 	beq	$v1,$a0,.L0001c908
/*    1c8e8:	00000000 */ 	nop
/*    1c8ec:	8ca4000c */ 	lw	$a0,0xc($a1)
/*    1c8f0:	00801025 */ 	or	$v0,$a0,$zero
.L0001c8f4:
/*    1c8f4:	8c84000c */ 	lw	$a0,0xc($a0)
/*    1c8f8:	10800003 */ 	beqz	$a0,.L0001c908
/*    1c8fc:	00000000 */ 	nop
/*    1c900:	5464fffc */ 	bnel	$v1,$a0,.L0001c8f4
/*    1c904:	00801025 */ 	or	$v0,$a0,$zero
.L0001c908:
/*    1c908:	03e00008 */ 	jr	$ra
/*    1c90c:	ac40000c */ 	sw	$zero,0xc($v0)
.L0001c910:
/*    1c910:	10a00002 */ 	beqz	$a1,.L0001c91c
/*    1c914:	ac850014 */ 	sw	$a1,0x14($a0)
/*    1c918:	aca00010 */ 	sw	$zero,0x10($a1)
.L0001c91c:
/*    1c91c:	03e00008 */ 	jr	$ra
/*    1c920:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c924
/*    1c924:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1c928:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1c92c:	0c006a87 */ 	jal	modelGetNodeData
/*    1c930:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    1c934:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    1c938:	0c00721a */ 	jal	func0001c868
/*    1c93c:	8c450000 */ 	lw	$a1,0x0($v0)
/*    1c940:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1c944:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1c948:	03e00008 */ 	jr	$ra
/*    1c94c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001c950
.late_rodata
glabel var70054324
.word 0x7001cb68
glabel var70054328
.word 0x7001cb68
glabel var7005432c
.word 0x7001cba4
glabel var70054330
.word 0x7001cba4
glabel var70054334
.word 0x7001cba4
glabel var70054338
.word 0x7001cba4
glabel var7005433c
.word 0x7001cba4
glabel var70054340
.word 0x7001cb70
glabel var70054344
.word 0x7001cb84
glabel var70054348
.word 0x7001cba4
glabel var7005434c
.word 0x7001cb68
glabel var70054350
.word 0x7001cb68
glabel var70054354
.word 0x7001cb68
glabel var70054358
.word 0x7001cb68
glabel var7005435c
.word 0x7001cb68
glabel var70054360
.word 0x7001cba4
glabel var70054364
.word 0x7001cba4
glabel var70054368
.word 0x7001cba4
glabel var7005436c
.word 0x7001cba4
glabel var70054370
.word 0x7001cba4
glabel var70054374
.word 0x7001cb68
glabel var70054378
.word 0x7001cba4
glabel var7005437c
.word 0x7001cb98
glabel var70054380
.word 0x7001cba4
.text
/*    1c950:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*    1c954:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1c958:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1c95c:	afa40050 */ 	sw	$a0,0x50($sp)
/*    1c960:	8cb00004 */ 	lw	$s0,0x4($a1)
/*    1c964:	0c006a87 */ 	jal	modelGetNodeData
/*    1c968:	afa50054 */ 	sw	$a1,0x54($sp)
/*    1c96c:	afa20048 */ 	sw	$v0,0x48($sp)
/*    1c970:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    1c974:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    1c978:	0c006973 */ 	jal	func0001a5cc
/*    1c97c:	00003025 */ 	or	$a2,$zero,$zero
/*    1c980:	86030020 */ 	lh	$v1,0x20($s0)
/*    1c984:	00402025 */ 	or	$a0,$v0,$zero
/*    1c988:	24010002 */ 	addiu	$at,$zero,0x2
/*    1c98c:	1460000c */ 	bnez	$v1,.L0001c9c0
/*    1c990:	00000000 */ 	nop
/*    1c994:	c604000c */ 	lwc1	$f4,0xc($s0)
/*    1c998:	27a50038 */ 	addiu	$a1,$sp,0x38
/*    1c99c:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*    1c9a0:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*    1c9a4:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*    1c9a8:	c6080014 */ 	lwc1	$f8,0x14($s0)
/*    1c9ac:	afa40044 */ 	sw	$a0,0x44($sp)
/*    1c9b0:	0c0056c4 */ 	jal	func00015b10
/*    1c9b4:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*    1c9b8:	1000002f */ 	b	.L0001ca78
/*    1c9bc:	8fa40044 */ 	lw	$a0,0x44($sp)
.L0001c9c0:
/*    1c9c0:	5461000f */ 	bnel	$v1,$at,.L0001ca00
/*    1c9c4:	24010003 */ 	addiu	$at,$zero,0x3
/*    1c9c8:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*    1c9cc:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*    1c9d0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1c9d4:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*    1c9d8:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*    1c9dc:	c4460014 */ 	lwc1	$f6,0x14($v0)
/*    1c9e0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1c9e4:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*    1c9e8:	c4500018 */ 	lwc1	$f16,0x18($v0)
/*    1c9ec:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*    1c9f0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1c9f4:	10000020 */ 	b	.L0001ca78
/*    1c9f8:	e7b20040 */ 	swc1	$f18,0x40($sp)
/*    1c9fc:	24010003 */ 	addiu	$at,$zero,0x3
.L0001ca00:
/*    1ca00:	5461000f */ 	bnel	$v1,$at,.L0001ca40
/*    1ca04:	24010001 */ 	addiu	$at,$zero,0x1
/*    1ca08:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*    1ca0c:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*    1ca10:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1ca14:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*    1ca18:	c60a0014 */ 	lwc1	$f10,0x14($s0)
/*    1ca1c:	c4500024 */ 	lwc1	$f16,0x24($v0)
/*    1ca20:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1ca24:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*    1ca28:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*    1ca2c:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*    1ca30:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1ca34:	10000010 */ 	b	.L0001ca78
/*    1ca38:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*    1ca3c:	24010001 */ 	addiu	$at,$zero,0x1
.L0001ca40:
/*    1ca40:	5461000e */ 	bnel	$v1,$at,.L0001ca7c
/*    1ca44:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*    1ca48:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*    1ca4c:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*    1ca50:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1ca54:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*    1ca58:	c604000c */ 	lwc1	$f4,0xc($s0)
/*    1ca5c:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*    1ca60:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1ca64:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*    1ca68:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*    1ca6c:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*    1ca70:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1ca74:	e7b20040 */ 	swc1	$f18,0x40($sp)
.L0001ca78:
/*    1ca78:	c6040000 */ 	lwc1	$f4,0x0($s0)
.L0001ca7c:
/*    1ca7c:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    1ca80:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*    1ca84:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*    1ca88:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*    1ca8c:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*    1ca90:	0c0056d9 */ 	jal	func00015b64
/*    1ca94:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*    1ca98:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*    1ca9c:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*    1caa0:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    1caa4:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    1caa8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    1caac:	c7b00034 */ 	lwc1	$f16,0x34($sp)
/*    1cab0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    1cab4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1cab8:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    1cabc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    1cac0:	46048182 */ 	mul.s	$f6,$f16,$f4
/*    1cac4:	46089280 */ 	add.s	$f10,$f18,$f8
/*    1cac8:	44809000 */ 	mtc1	$zero,$f18
/*    1cacc:	460a3000 */ 	add.s	$f0,$f6,$f10
/*    1cad0:	4612003c */ 	c.lt.s	$f0,$f18
/*    1cad4:	00000000 */ 	nop
/*    1cad8:	45000003 */ 	bc1f	.L0001cae8
/*    1cadc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    1cae0:	10000002 */ 	b	.L0001caec
/*    1cae4:	adee0000 */ 	sw	$t6,0x0($t7)
.L0001cae8:
/*    1cae8:	af000000 */ 	sw	$zero,0x0($t8)
.L0001caec:
/*    1caec:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    1caf0:	0c007249 */ 	jal	func0001c924
/*    1caf4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*    1caf8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1cafc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1cb00:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*    1cb04:	03e00008 */ 	jr	$ra
/*    1cb08:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001cb0c
.late_rodata
glabel var70054384
.word 0x7001ccc0
glabel var70054388
.word 0x7001ccc0
glabel var7005438c
.word 0x7001ccc0
glabel var70054390
.word 0x7001ccc0
glabel var70054394
.word 0x7001ccc0
glabel var70054398
.word 0x7001ccc0
glabel var7005439c
.word 0x7001ccc0
glabel var700543a0
.word 0x7001cc70
glabel var700543a4
.word 0x7001cc84
glabel var700543a8
.word 0x7001ccc0
glabel var700543ac
.word 0x7001ccc0
glabel var700543b0
.word 0x7001ccc0
glabel var700543b4
.word 0x7001ccc0
glabel var700543b8
.word 0x7001ccc0
.text
/*    1cb0c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1cb10:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    1cb14:	afb30020 */ 	sw	$s3,0x20($sp)
/*    1cb18:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    1cb1c:	afb10018 */ 	sw	$s1,0x18($sp)
/*    1cb20:	afb00014 */ 	sw	$s0,0x14($sp)
/*    1cb24:	8cb00014 */ 	lw	$s0,0x14($a1)
/*    1cb28:	00809025 */ 	or	$s2,$a0,$zero
/*    1cb2c:	00a09825 */ 	or	$s3,$a1,$zero
/*    1cb30:	52000035 */ 	beqzl	$s0,.L0001cc08
/*    1cb34:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    1cb38:	96020000 */ 	lhu	$v0,0x0($s0)
.L0001cb3c:
/*    1cb3c:	24110001 */ 	addiu	$s1,$zero,0x1
/*    1cb40:	304e00ff */ 	andi	$t6,$v0,0xff
/*    1cb44:	25cfffff */ 	addiu	$t7,$t6,-1
/*    1cb48:	2de10018 */ 	sltiu	$at,$t7,0x18
/*    1cb4c:	10200015 */ 	beqz	$at,.L0001cba4
/*    1cb50:	000f7880 */ 	sll	$t7,$t7,0x2
/*    1cb54:	3c017005 */ 	lui	$at,%hi(var70054324)
/*    1cb58:	002f0821 */ 	addu	$at,$at,$t7
/*    1cb5c:	8c2f4324 */ 	lw	$t7,%lo(var70054324)($at)
/*    1cb60:	01e00008 */ 	jr	$t7
/*    1cb64:	00000000 */ 	nop
/*    1cb68:	1000000e */ 	b	.L0001cba4
/*    1cb6c:	00008825 */ 	or	$s1,$zero,$zero
/*    1cb70:	02402025 */ 	or	$a0,$s2,$zero
/*    1cb74:	0c007199 */ 	jal	func0001c664
/*    1cb78:	02002825 */ 	or	$a1,$s0,$zero
/*    1cb7c:	10000009 */ 	b	.L0001cba4
/*    1cb80:	00000000 */ 	nop
/*    1cb84:	02402025 */ 	or	$a0,$s2,$zero
/*    1cb88:	0c007254 */ 	jal	func0001c950
/*    1cb8c:	02002825 */ 	or	$a1,$s0,$zero
/*    1cb90:	10000004 */ 	b	.L0001cba4
/*    1cb94:	00000000 */ 	nop
/*    1cb98:	02402025 */ 	or	$a0,$s2,$zero
/*    1cb9c:	0c007207 */ 	jal	func0001c81c
/*    1cba0:	02002825 */ 	or	$a1,$s0,$zero
.L0001cba4:
/*    1cba4:	12200006 */ 	beqz	$s1,.L0001cbc0
/*    1cba8:	00000000 */ 	nop
/*    1cbac:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cbb0:	10400003 */ 	beqz	$v0,.L0001cbc0
/*    1cbb4:	00000000 */ 	nop
/*    1cbb8:	10000010 */ 	b	.L0001cbfc
/*    1cbbc:	00408025 */ 	or	$s0,$v0,$zero
.L0001cbc0:
/*    1cbc0:	1200000e */ 	beqz	$s0,.L0001cbfc
/*    1cbc4:	00000000 */ 	nop
/*    1cbc8:	8e630008 */ 	lw	$v1,0x8($s3)
.L0001cbcc:
/*    1cbcc:	56030004 */ 	bnel	$s0,$v1,.L0001cbe0
/*    1cbd0:	8e02000c */ 	lw	$v0,0xc($s0)
/*    1cbd4:	10000009 */ 	b	.L0001cbfc
/*    1cbd8:	00008025 */ 	or	$s0,$zero,$zero
/*    1cbdc:	8e02000c */ 	lw	$v0,0xc($s0)
.L0001cbe0:
/*    1cbe0:	50400004 */ 	beqzl	$v0,.L0001cbf4
/*    1cbe4:	8e100008 */ 	lw	$s0,0x8($s0)
/*    1cbe8:	10000004 */ 	b	.L0001cbfc
/*    1cbec:	00408025 */ 	or	$s0,$v0,$zero
/*    1cbf0:	8e100008 */ 	lw	$s0,0x8($s0)
.L0001cbf4:
/*    1cbf4:	1600fff5 */ 	bnez	$s0,.L0001cbcc
/*    1cbf8:	00000000 */ 	nop
.L0001cbfc:
/*    1cbfc:	5600ffcf */ 	bnezl	$s0,.L0001cb3c
/*    1cc00:	96020000 */ 	lhu	$v0,0x0($s0)
/*    1cc04:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0001cc08:
/*    1cc08:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    1cc0c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    1cc10:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    1cc14:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    1cc18:	03e00008 */ 	jr	$ra
/*    1cc1c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);


GLOBAL_ASM(
glabel func0001cc20
.late_rodata
glabel var700543bc
.word 0x7001ccc0
glabel var700543c0
.word 0x7001ccc0
glabel var700543c4
.word 0x7001ccc0
glabel var700543c8
.word 0x7001cc98
glabel var700543cc
.word 0x7001ccc0
glabel var700543d0
.word 0x7001ccc0
glabel var700543d4
.word 0x7001ccc0
glabel var700543d8
.word 0x7001ccc0
glabel var700543dc
.word 0x7001ccac
glabel var700543e0
.word 0x7001ccc0
.text
/*    1cc20:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1cc24:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1cc28:	afb10018 */ 	sw	$s1,0x18($sp)
/*    1cc2c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    1cc30:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    1cc34:	00808825 */ 	or	$s1,$a0,$zero
/*    1cc38:	8dd00000 */ 	lw	$s0,0x0($t6)
/*    1cc3c:	52000032 */ 	beqzl	$s0,.L0001cd08
/*    1cc40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1cc44:	96020000 */ 	lhu	$v0,0x0($s0)
.L0001cc48:
/*    1cc48:	304f00ff */ 	andi	$t7,$v0,0xff
/*    1cc4c:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    1cc50:	2f010018 */ 	sltiu	$at,$t8,0x18
/*    1cc54:	1020001a */ 	beqz	$at,.L0001ccc0
/*    1cc58:	0018c080 */ 	sll	$t8,$t8,0x2
/*    1cc5c:	3c017005 */ 	lui	$at,%hi(var70054384)
/*    1cc60:	00380821 */ 	addu	$at,$at,$t8
/*    1cc64:	8c384384 */ 	lw	$t8,%lo(var70054384)($at)
/*    1cc68:	03000008 */ 	jr	$t8
/*    1cc6c:	00000000 */ 	nop
/*    1cc70:	02202025 */ 	or	$a0,$s1,$zero
/*    1cc74:	0c007199 */ 	jal	func0001c664
/*    1cc78:	02002825 */ 	or	$a1,$s0,$zero
/*    1cc7c:	10000011 */ 	b	.L0001ccc4
/*    1cc80:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cc84:	02202025 */ 	or	$a0,$s1,$zero
/*    1cc88:	0c007254 */ 	jal	func0001c950
/*    1cc8c:	02002825 */ 	or	$a1,$s0,$zero
/*    1cc90:	1000000c */ 	b	.L0001ccc4
/*    1cc94:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cc98:	02202025 */ 	or	$a0,$s1,$zero
/*    1cc9c:	0c0071f4 */ 	jal	func0001c7d0
/*    1cca0:	02002825 */ 	or	$a1,$s0,$zero
/*    1cca4:	10000007 */ 	b	.L0001ccc4
/*    1cca8:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1ccac:	02202025 */ 	or	$a0,$s1,$zero
/*    1ccb0:	0c007207 */ 	jal	func0001c81c
/*    1ccb4:	02002825 */ 	or	$a1,$s0,$zero
/*    1ccb8:	10000002 */ 	b	.L0001ccc4
/*    1ccbc:	8e020014 */ 	lw	$v0,0x14($s0)
.L0001ccc0:
/*    1ccc0:	8e020014 */ 	lw	$v0,0x14($s0)
.L0001ccc4:
/*    1ccc4:	10400003 */ 	beqz	$v0,.L0001ccd4
/*    1ccc8:	00000000 */ 	nop
/*    1cccc:	1000000b */ 	b	.L0001ccfc
/*    1ccd0:	00408025 */ 	or	$s0,$v0,$zero
.L0001ccd4:
/*    1ccd4:	12000009 */ 	beqz	$s0,.L0001ccfc
/*    1ccd8:	00000000 */ 	nop
/*    1ccdc:	8e02000c */ 	lw	$v0,0xc($s0)
.L0001cce0:
/*    1cce0:	50400004 */ 	beqzl	$v0,.L0001ccf4
/*    1cce4:	8e100008 */ 	lw	$s0,0x8($s0)
/*    1cce8:	10000004 */ 	b	.L0001ccfc
/*    1ccec:	00408025 */ 	or	$s0,$v0,$zero
/*    1ccf0:	8e100008 */ 	lw	$s0,0x8($s0)
.L0001ccf4:
/*    1ccf4:	5600fffa */ 	bnezl	$s0,.L0001cce0
/*    1ccf8:	8e02000c */ 	lw	$v0,0xc($s0)
.L0001ccfc:
/*    1ccfc:	5600ffd2 */ 	bnezl	$s0,.L0001cc48
/*    1cd00:	96020000 */ 	lhu	$v0,0x0($s0)
/*    1cd04:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0001cd08:
/*    1cd08:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    1cd0c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    1cd10:	03e00008 */ 	jr	$ra
/*    1cd14:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0001cd18
.late_rodata
glabel var700543e4
.word 0x7001cd70
glabel var700543e8
.word 0x7001cd88
glabel var700543ec
.word 0x7001ce08
glabel var700543f0
.word 0x7001ce08
glabel var700543f4
.word 0x7001ce08
glabel var700543f8
.word 0x7001ce08
glabel var700543fc
.word 0x7001ce08
glabel var70054400
.word 0x7001cdb8
glabel var70054404
.word 0x7001cdcc
glabel var70054408
.word 0x7001ce08
glabel var7005440c
.word 0x7001ce08
glabel var70054410
.word 0x7001ce08
glabel var70054414
.word 0x7001ce08
glabel var70054418
.word 0x7001ce08
glabel var7005441c
.word 0x7001ce08
glabel var70054420
.word 0x7001ce08
glabel var70054424
.word 0x7001ce08
glabel var70054428
.word 0x7001cde0
glabel var7005442c
.word 0x7001ce08
glabel var70054430
.word 0x7001ce08
glabel var70054434
.word 0x7001cda0
glabel var70054438
.word 0x7001ce08
glabel var7005443c
.word 0x7001cdf4
glabel var70054440
.word 0x7001ce08
.text
/*    1cd18:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1cd1c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    1cd20:	afb20020 */ 	sw	$s2,0x20($sp)
/*    1cd24:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    1cd28:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1cd2c:	8cae0008 */ 	lw	$t6,0x8($a1)
/*    1cd30:	00a08825 */ 	or	$s1,$a1,$zero
/*    1cd34:	00809025 */ 	or	$s2,$a0,$zero
/*    1cd38:	8dd00000 */ 	lw	$s0,0x0($t6)
/*    1cd3c:	52000044 */ 	beqzl	$s0,.L0001ce50
/*    1cd40:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    1cd44:	96020000 */ 	lhu	$v0,0x0($s0)
.L0001cd48:
/*    1cd48:	304f00ff */ 	andi	$t7,$v0,0xff
/*    1cd4c:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    1cd50:	2f010018 */ 	sltiu	$at,$t8,0x18
/*    1cd54:	1020002c */ 	beqz	$at,.L0001ce08
/*    1cd58:	0018c080 */ 	sll	$t8,$t8,0x2
/*    1cd5c:	3c017005 */ 	lui	$at,%hi(var700543e4)
/*    1cd60:	00380821 */ 	addu	$at,$at,$t8
/*    1cd64:	8c3843e4 */ 	lw	$t8,%lo(var700543e4)($at)
/*    1cd68:	03000008 */ 	jr	$t8
/*    1cd6c:	00000000 */ 	nop
/*    1cd70:	02402025 */ 	or	$a0,$s2,$zero
/*    1cd74:	02202825 */ 	or	$a1,$s1,$zero
/*    1cd78:	0c006d00 */ 	jal	func0001b400
/*    1cd7c:	02003025 */ 	or	$a2,$s0,$zero
/*    1cd80:	10000022 */ 	b	.L0001ce0c
/*    1cd84:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cd88:	02402025 */ 	or	$a0,$s2,$zero
/*    1cd8c:	02202825 */ 	or	$a1,$s1,$zero
/*    1cd90:	0c006fea */ 	jal	func0001bfa8
/*    1cd94:	02003025 */ 	or	$a2,$s0,$zero
/*    1cd98:	1000001c */ 	b	.L0001ce0c
/*    1cd9c:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cda0:	02402025 */ 	or	$a0,$s2,$zero
/*    1cda4:	02202825 */ 	or	$a1,$s1,$zero
/*    1cda8:	0c00716d */ 	jal	func0001c5b4
/*    1cdac:	02003025 */ 	or	$a2,$s0,$zero
/*    1cdb0:	10000016 */ 	b	.L0001ce0c
/*    1cdb4:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cdb8:	02202025 */ 	or	$a0,$s1,$zero
/*    1cdbc:	0c007199 */ 	jal	func0001c664
/*    1cdc0:	02002825 */ 	or	$a1,$s0,$zero
/*    1cdc4:	10000011 */ 	b	.L0001ce0c
/*    1cdc8:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cdcc:	02202025 */ 	or	$a0,$s1,$zero
/*    1cdd0:	0c007254 */ 	jal	func0001c950
/*    1cdd4:	02002825 */ 	or	$a1,$s0,$zero
/*    1cdd8:	1000000c */ 	b	.L0001ce0c
/*    1cddc:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cde0:	02202025 */ 	or	$a0,$s1,$zero
/*    1cde4:	0c0071f4 */ 	jal	func0001c7d0
/*    1cde8:	02002825 */ 	or	$a1,$s0,$zero
/*    1cdec:	10000007 */ 	b	.L0001ce0c
/*    1cdf0:	8e020014 */ 	lw	$v0,0x14($s0)
/*    1cdf4:	02202025 */ 	or	$a0,$s1,$zero
/*    1cdf8:	0c007207 */ 	jal	func0001c81c
/*    1cdfc:	02002825 */ 	or	$a1,$s0,$zero
/*    1ce00:	10000002 */ 	b	.L0001ce0c
/*    1ce04:	8e020014 */ 	lw	$v0,0x14($s0)
.L0001ce08:
/*    1ce08:	8e020014 */ 	lw	$v0,0x14($s0)
.L0001ce0c:
/*    1ce0c:	10400003 */ 	beqz	$v0,.L0001ce1c
/*    1ce10:	00000000 */ 	nop
/*    1ce14:	1000000b */ 	b	.L0001ce44
/*    1ce18:	00408025 */ 	or	$s0,$v0,$zero
.L0001ce1c:
/*    1ce1c:	12000009 */ 	beqz	$s0,.L0001ce44
/*    1ce20:	00000000 */ 	nop
/*    1ce24:	8e02000c */ 	lw	$v0,0xc($s0)
.L0001ce28:
/*    1ce28:	50400004 */ 	beqzl	$v0,.L0001ce3c
/*    1ce2c:	8e100008 */ 	lw	$s0,0x8($s0)
/*    1ce30:	10000004 */ 	b	.L0001ce44
/*    1ce34:	00408025 */ 	or	$s0,$v0,$zero
/*    1ce38:	8e100008 */ 	lw	$s0,0x8($s0)
.L0001ce3c:
/*    1ce3c:	5600fffa */ 	bnezl	$s0,.L0001ce28
/*    1ce40:	8e02000c */ 	lw	$v0,0xc($s0)
.L0001ce44:
/*    1ce44:	5600ffc0 */ 	bnezl	$s0,.L0001cd48
/*    1ce48:	96020000 */ 	lhu	$v0,0x0($s0)
/*    1ce4c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0001ce50:
/*    1ce50:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1ce54:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    1ce58:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    1ce5c:	03e00008 */ 	jr	$ra
/*    1ce60:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0001ce64
/*    1ce64:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1ce68:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1ce6c:	8c8e0010 */ 	lw	$t6,0x10($a0)
/*    1ce70:	8cb80008 */ 	lw	$t8,0x8($a1)
/*    1ce74:	acae000c */ 	sw	$t6,0xc($a1)
/*    1ce78:	8719000e */ 	lh	$t9,0xe($t8)
/*    1ce7c:	8c8f0010 */ 	lw	$t7,0x10($a0)
/*    1ce80:	00194180 */ 	sll	$t0,$t9,0x6
/*    1ce84:	01e84821 */ 	addu	$t1,$t7,$t0
/*    1ce88:	ac890010 */ 	sw	$t1,0x10($a0)
/*    1ce8c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    1ce90:	0c0061a0 */ 	jal	func00018680
/*    1ce94:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1ce98:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    1ce9c:	14400003 */ 	bnez	$v0,.L0001ceac
/*    1cea0:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    1cea4:	0c007346 */ 	jal	func0001cd18
/*    1cea8:	00000000 */ 	nop
.L0001ceac:
/*    1ceac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1ceb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1ceb4:	03e00008 */ 	jr	$ra
/*    1ceb8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001cebc
/*    1cebc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1cec0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1cec4:	afa40028 */ 	sw	$a0,0x28($sp)
/*    1cec8:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    1cecc:	8ca30020 */ 	lw	$v1,0x20($a1)
/*    1ced0:	5060006a */ 	beqzl	$v1,.L0001d07c
/*    1ced4:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    1ced8:	84670000 */ 	lh	$a3,0x0($v1)
/*    1cedc:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    1cee0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    1cee4:	50e00065 */ 	beqzl	$a3,.L0001d07c
/*    1cee8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    1ceec:	8d0f006c */ 	lw	$t7,0x6c($t0)
/*    1cef0:	00003025 */ 	or	$a2,$zero,$zero
/*    1cef4:	11e00003 */ 	beqz	$t7,.L0001cf04
/*    1cef8:	00000000 */ 	nop
/*    1cefc:	10000001 */ 	b	.L0001cf04
/*    1cf00:	24060001 */ 	addiu	$a2,$zero,0x1
.L0001cf04:
/*    1cf04:	8d180068 */ 	lw	$t8,0x68($t0)
/*    1cf08:	00002825 */ 	or	$a1,$zero,$zero
/*    1cf0c:	13000003 */ 	beqz	$t8,.L0001cf1c
/*    1cf10:	00000000 */ 	nop
/*    1cf14:	10000001 */ 	b	.L0001cf1c
/*    1cf18:	24050001 */ 	addiu	$a1,$zero,0x1
.L0001cf1c:
/*    1cf1c:	8d190064 */ 	lw	$t9,0x64($t0)
/*    1cf20:	00002025 */ 	or	$a0,$zero,$zero
/*    1cf24:	00001025 */ 	or	$v0,$zero,$zero
/*    1cf28:	13200003 */ 	beqz	$t9,.L0001cf38
/*    1cf2c:	00000000 */ 	nop
/*    1cf30:	10000001 */ 	b	.L0001cf38
/*    1cf34:	24040001 */ 	addiu	$a0,$zero,0x1
.L0001cf38:
/*    1cf38:	8d090070 */ 	lw	$t1,0x70($t0)
/*    1cf3c:	11200003 */ 	beqz	$t1,.L0001cf4c
/*    1cf40:	00000000 */ 	nop
/*    1cf44:	10000001 */ 	b	.L0001cf4c
/*    1cf48:	24020001 */ 	addiu	$v0,$zero,0x1
.L0001cf4c:
/*    1cf4c:	00445021 */ 	addu	$t2,$v0,$a0
/*    1cf50:	01455821 */ 	addu	$t3,$t2,$a1
/*    1cf54:	01666021 */ 	addu	$t4,$t3,$a2
/*    1cf58:	29810002 */ 	slti	$at,$t4,0x2
/*    1cf5c:	54200016 */ 	bnezl	$at,.L0001cfb8
/*    1cf60:	00072400 */ 	sll	$a0,$a3,0x10
/*    1cf64:	c4640010 */ 	lwc1	$f4,0x10($v1)
/*    1cf68:	44801000 */ 	mtc1	$zero,$f2
/*    1cf6c:	3c013f00 */ 	lui	$at,0x3f00
/*    1cf70:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    1cf74:	c4660034 */ 	lwc1	$f6,0x34($v1)
/*    1cf78:	44814000 */ 	mtc1	$at,$f8
/*    1cf7c:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    1cf80:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*    1cf84:	4602003c */ 	c.lt.s	$f0,$f2
/*    1cf88:	00000000 */ 	nop
/*    1cf8c:	45020003 */ 	bc1fl	.L0001cf9c
/*    1cf90:	4600403c */ 	c.lt.s	$f8,$f0
/*    1cf94:	46000007 */ 	neg.s	$f0,$f0
/*    1cf98:	4600403c */ 	c.lt.s	$f8,$f0
.L0001cf9c:
/*    1cf9c:	00000000 */ 	nop
/*    1cfa0:	45020005 */ 	bc1fl	.L0001cfb8
/*    1cfa4:	00072400 */ 	sll	$a0,$a3,0x10
/*    1cfa8:	e4620010 */ 	swc1	$f2,0x10($v1)
/*    1cfac:	e4620034 */ 	swc1	$f2,0x34($v1)
/*    1cfb0:	84670000 */ 	lh	$a3,0x0($v1)
/*    1cfb4:	00072400 */ 	sll	$a0,$a3,0x10
.L0001cfb8:
/*    1cfb8:	00046c03 */ 	sra	$t5,$a0,0x10
/*    1cfbc:	01a02025 */ 	or	$a0,$t5,$zero
/*    1cfc0:	0c008f4e */ 	jal	func00023d38
/*    1cfc4:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1cfc8:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1cfcc:	84640000 */ 	lh	$a0,0x0($v1)
/*    1cfd0:	0c008eac */ 	jal	func00023ab0
/*    1cfd4:	84650014 */ 	lh	$a1,0x14($v1)
/*    1cfd8:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1cfdc:	44805000 */ 	mtc1	$zero,$f10
/*    1cfe0:	c4700010 */ 	lwc1	$f16,0x10($v1)
/*    1cfe4:	a0620004 */ 	sb	$v0,0x4($v1)
/*    1cfe8:	46105032 */ 	c.eq.s	$f10,$f16
/*    1cfec:	00000000 */ 	nop
/*    1cff0:	45030008 */ 	bc1tl	.L0001d014
/*    1cff4:	84640002 */ 	lh	$a0,0x2($v1)
/*    1cff8:	84640000 */ 	lh	$a0,0x0($v1)
/*    1cffc:	84650016 */ 	lh	$a1,0x16($v1)
/*    1d000:	0c008eac */ 	jal	func00023ab0
/*    1d004:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1d008:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1d00c:	a0620005 */ 	sb	$v0,0x5($v1)
/*    1d010:	84640002 */ 	lh	$a0,0x2($v1)
.L0001d014:
/*    1d014:	10800015 */ 	beqz	$a0,.L0001d06c
/*    1d018:	00000000 */ 	nop
/*    1d01c:	0c008f4e */ 	jal	func00023d38
/*    1d020:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1d024:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1d028:	84640002 */ 	lh	$a0,0x2($v1)
/*    1d02c:	0c008eac */ 	jal	func00023ab0
/*    1d030:	84650038 */ 	lh	$a1,0x38($v1)
/*    1d034:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1d038:	44809000 */ 	mtc1	$zero,$f18
/*    1d03c:	c4640034 */ 	lwc1	$f4,0x34($v1)
/*    1d040:	a0620006 */ 	sb	$v0,0x6($v1)
/*    1d044:	46049032 */ 	c.eq.s	$f18,$f4
/*    1d048:	00000000 */ 	nop
/*    1d04c:	45010007 */ 	bc1t	.L0001d06c
/*    1d050:	00000000 */ 	nop
/*    1d054:	84640002 */ 	lh	$a0,0x2($v1)
/*    1d058:	8465003a */ 	lh	$a1,0x3a($v1)
/*    1d05c:	0c008eac */ 	jal	func00023ab0
/*    1d060:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1d064:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1d068:	a0620007 */ 	sb	$v0,0x7($v1)
.L0001d06c:
/*    1d06c:	0c008f43 */ 	jal	func00023d0c
/*    1d070:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1d074:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1d078:	8fa40028 */ 	lw	$a0,0x28($sp)
.L0001d07c:
/*    1d07c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    1d080:	0c007399 */ 	jal	func0001ce64
/*    1d084:	afa30024 */ 	sw	$v1,0x24($sp)
/*    1d088:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*    1d08c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*    1d090:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*    1d094:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    1d098:	00003025 */ 	or	$a2,$zero,$zero
/*    1d09c:	11c00003 */ 	beqz	$t6,.L0001d0ac
/*    1d0a0:	00002825 */ 	or	$a1,$zero,$zero
/*    1d0a4:	10000001 */ 	b	.L0001d0ac
/*    1d0a8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0001d0ac:
/*    1d0ac:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*    1d0b0:	00002025 */ 	or	$a0,$zero,$zero
/*    1d0b4:	11e00003 */ 	beqz	$t7,.L0001d0c4
/*    1d0b8:	00000000 */ 	nop
/*    1d0bc:	10000001 */ 	b	.L0001d0c4
/*    1d0c0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0001d0c4:
/*    1d0c4:	8c580064 */ 	lw	$t8,0x64($v0)
/*    1d0c8:	13000003 */ 	beqz	$t8,.L0001d0d8
/*    1d0cc:	00000000 */ 	nop
/*    1d0d0:	10000001 */ 	b	.L0001d0d8
/*    1d0d4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0001d0d8:
/*    1d0d8:	8c590070 */ 	lw	$t9,0x70($v0)
/*    1d0dc:	00001025 */ 	or	$v0,$zero,$zero
/*    1d0e0:	13200003 */ 	beqz	$t9,.L0001d0f0
/*    1d0e4:	00000000 */ 	nop
/*    1d0e8:	10000001 */ 	b	.L0001d0f0
/*    1d0ec:	24020001 */ 	addiu	$v0,$zero,0x1
.L0001d0f0:
/*    1d0f0:	00444821 */ 	addu	$t1,$v0,$a0
/*    1d0f4:	01255021 */ 	addu	$t2,$t1,$a1
/*    1d0f8:	01465821 */ 	addu	$t3,$t2,$a2
/*    1d0fc:	29610002 */ 	slti	$at,$t3,0x2
/*    1d100:	5420000b */ 	bnezl	$at,.L0001d130
/*    1d104:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d108:	50600009 */ 	beqzl	$v1,.L0001d130
/*    1d10c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d110:	846c0000 */ 	lh	$t4,0x0($v1)
/*    1d114:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*    1d118:	51800005 */ 	beqzl	$t4,.L0001d130
/*    1d11c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d120:	e4660010 */ 	swc1	$f6,0x10($v1)
/*    1d124:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    1d128:	e4680034 */ 	swc1	$f8,0x34($v1)
/*    1d12c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001d130:
/*    1d130:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    1d134:	03e00008 */ 	jr	$ra
/*    1d138:	00000000 */ 	nop
);

u32 modelGetAnimNum(struct model *model)
{
	if (model->anim) {
		return model->anim->animnum;
	}

	return 0;
}

bool modelIsFlipped(struct model *model)
{
	if (model->anim) {
		return model->anim->flip;
	}

	return false;
}

f32 modelGetCurAnimFrame(struct model *model)
{
	if (model->anim) {
		return model->anim->frame;
	}

	return 0;
}

GLOBAL_ASM(
glabel func0001d1a0
/*    1d1a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1d1a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1d1a8:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1d1ac:	50400015 */ 	beqzl	$v0,.L0001d204
/*    1d1b0:	44800000 */ 	mtc1	$zero,$f0
/*    1d1b4:	44806000 */ 	mtc1	$zero,$f12
/*    1d1b8:	c4420018 */ 	lwc1	$f2,0x18($v0)
/*    1d1bc:	4602603e */ 	c.le.s	$f12,$f2
/*    1d1c0:	00000000 */ 	nop
/*    1d1c4:	45020004 */ 	bc1fl	.L0001d1d8
/*    1d1c8:	84440000 */ 	lh	$a0,0x0($v0)
/*    1d1cc:	1000000e */ 	b	.L0001d208
/*    1d1d0:	46001006 */ 	mov.s	$f0,$f2
/*    1d1d4:	84440000 */ 	lh	$a0,0x0($v0)
.L0001d1d8:
/*    1d1d8:	10800007 */ 	beqz	$a0,.L0001d1f8
/*    1d1dc:	00000000 */ 	nop
/*    1d1e0:	0c008dda */ 	jal	animGetNumFrames
/*    1d1e4:	00000000 */ 	nop
/*    1d1e8:	244effff */ 	addiu	$t6,$v0,-1
/*    1d1ec:	448e2000 */ 	mtc1	$t6,$f4
/*    1d1f0:	10000005 */ 	b	.L0001d208
/*    1d1f4:	46802020 */ 	cvt.s.w	$f0,$f4
.L0001d1f8:
/*    1d1f8:	10000003 */ 	b	.L0001d208
/*    1d1fc:	46006006 */ 	mov.s	$f0,$f12
/*    1d200:	44800000 */ 	mtc1	$zero,$f0
.L0001d204:
/*    1d204:	00000000 */ 	nop
.L0001d208:
/*    1d208:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d20c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1d210:	03e00008 */ 	jr	$ra
/*    1d214:	00000000 */ 	nop
);

s32 modelGetNumAnimFrames(struct model *model)
{
	if (model->anim) {
		return animGetNumFrames(modelGetAnimNum(model));
	}

	return 0;
}

f32 modelGetAnimSpeed(struct model *model)
{
	if (model->anim) {
		return model->anim->speed;
	}

	return 1;
}

GLOBAL_ASM(
glabel func0001d288
/*    1d288:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1d28c:	3c013f80 */ 	lui	$at,0x3f80
/*    1d290:	5040000c */ 	beqzl	$v0,.L0001d2c4
/*    1d294:	44810000 */ 	mtc1	$at,$f0
/*    1d298:	c442001c */ 	lwc1	$f2,0x1c($v0)
/*    1d29c:	44802000 */ 	mtc1	$zero,$f4
/*    1d2a0:	00000000 */ 	nop
/*    1d2a4:	4604103c */ 	c.lt.s	$f2,$f4
/*    1d2a8:	00000000 */ 	nop
/*    1d2ac:	45000002 */ 	bc1f	.L0001d2b8
/*    1d2b0:	00000000 */ 	nop
/*    1d2b4:	46001087 */ 	neg.s	$f2,$f2
.L0001d2b8:
/*    1d2b8:	03e00008 */ 	jr	$ra
/*    1d2bc:	46001006 */ 	mov.s	$f0,$f2
/*    1d2c0:	44810000 */ 	mtc1	$at,$f0
.L0001d2c4:
/*    1d2c4:	00000000 */ 	nop
/*    1d2c8:	03e00008 */ 	jr	$ra
/*    1d2cc:	00000000 */ 	nop
/*    1d2d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1d2d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1d2d8:	8c8e0020 */ 	lw	$t6,0x20($a0)
/*    1d2dc:	3c013f80 */ 	lui	$at,0x3f80
/*    1d2e0:	51c0000a */ 	beqzl	$t6,.L0001d30c
/*    1d2e4:	44810000 */ 	mtc1	$at,$f0
/*    1d2e8:	0c007498 */ 	jal	modelGetAnimSpeed
/*    1d2ec:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1d2f0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    1d2f4:	8c8f0020 */ 	lw	$t7,0x20($a0)
/*    1d2f8:	c5e40074 */ 	lwc1	$f4,0x74($t7)
/*    1d2fc:	46040002 */ 	mul.s	$f0,$f0,$f4
/*    1d300:	10000004 */ 	b	.L0001d314
/*    1d304:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d308:	44810000 */ 	mtc1	$at,$f0
.L0001d30c:
/*    1d30c:	00000000 */ 	nop
/*    1d310:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001d314:
/*    1d314:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1d318:	03e00008 */ 	jr	$ra
/*    1d31c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001d320
/*    1d320:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1d324:	00057400 */ 	sll	$t6,$a1,0x10
/*    1d328:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    1d32c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1d330:	44866000 */ 	mtc1	$a2,$f12
/*    1d334:	00803025 */ 	or	$a2,$a0,$zero
/*    1d338:	01e02825 */ 	or	$a1,$t7,$zero
/*    1d33c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1d340:	0481002c */ 	bgez	$a0,.L0001d3f4
/*    1d344:	afa40020 */ 	sw	$a0,0x20($sp)
/*    1d348:	3c188006 */ 	lui	$t8,%hi(var8005efbc)
/*    1d34c:	8f18efbc */ 	lw	$t8,%lo(var8005efbc)($t8)
/*    1d350:	3c198006 */ 	lui	$t9,%hi(g_Anims)
/*    1d354:	000f4080 */ 	sll	$t0,$t7,0x2
/*    1d358:	17000008 */ 	bnez	$t8,.L0001d37c
/*    1d35c:	00052400 */ 	sll	$a0,$a1,0x10
/*    1d360:	8f39f00c */ 	lw	$t9,%lo(g_Anims)($t9)
/*    1d364:	010f4023 */ 	subu	$t0,$t0,$t7
/*    1d368:	00084080 */ 	sll	$t0,$t0,0x2
/*    1d36c:	03284821 */ 	addu	$t1,$t9,$t0
/*    1d370:	912a000b */ 	lbu	$t2,0xb($t1)
/*    1d374:	314b0001 */ 	andi	$t3,$t2,0x1
/*    1d378:	1160001c */ 	beqz	$t3,.L0001d3ec
.L0001d37c:
/*    1d37c:	00046403 */ 	sra	$t4,$a0,0x10
/*    1d380:	01802025 */ 	or	$a0,$t4,$zero
/*    1d384:	a7a50026 */ 	sh	$a1,0x26($sp)
/*    1d388:	0c008dda */ 	jal	animGetNumFrames
/*    1d38c:	afa60020 */ 	sw	$a2,0x20($sp)
/*    1d390:	87a50026 */ 	lh	$a1,0x26($sp)
/*    1d394:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    1d398:	00052400 */ 	sll	$a0,$a1,0x10
/*    1d39c:	00046c03 */ 	sra	$t5,$a0,0x10
/*    1d3a0:	0c008dda */ 	jal	animGetNumFrames
/*    1d3a4:	01a02025 */ 	or	$a0,$t5,$zero
/*    1d3a8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    1d3ac:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    1d3b0:	00067823 */ 	negu	$t7,$a2
/*    1d3b4:	01e2001a */ 	div	$zero,$t7,$v0
/*    1d3b8:	0000c010 */ 	mfhi	$t8
/*    1d3bc:	01d83023 */ 	subu	$a2,$t6,$t8
/*    1d3c0:	14400002 */ 	bnez	$v0,.L0001d3cc
/*    1d3c4:	00000000 */ 	nop
/*    1d3c8:	0007000d */ 	break	0x7
.L0001d3cc:
/*    1d3cc:	2401ffff */ 	addiu	$at,$zero,-1
/*    1d3d0:	14410004 */ 	bne	$v0,$at,.L0001d3e4
/*    1d3d4:	3c018000 */ 	lui	$at,0x8000
/*    1d3d8:	15e10002 */ 	bne	$t7,$at,.L0001d3e4
/*    1d3dc:	00000000 */ 	nop
/*    1d3e0:	0006000d */ 	break	0x6
.L0001d3e4:
/*    1d3e4:	10000041 */ 	b	.L0001d4ec
/*    1d3e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001d3ec:
/*    1d3ec:	1000003e */ 	b	.L0001d4e8
/*    1d3f0:	00003025 */ 	or	$a2,$zero,$zero
.L0001d3f4:
/*    1d3f4:	44802000 */ 	mtc1	$zero,$f4
/*    1d3f8:	00052400 */ 	sll	$a0,$a1,0x10
/*    1d3fc:	00044c03 */ 	sra	$t1,$a0,0x10
/*    1d400:	460c203e */ 	c.le.s	$f4,$f12
/*    1d404:	01202025 */ 	or	$a0,$t1,$zero
/*    1d408:	4502000c */ 	bc1fl	.L0001d43c
/*    1d40c:	a7a50026 */ 	sh	$a1,0x26($sp)
/*    1d410:	4600618d */ 	trunc.w.s	$f6,$f12
/*    1d414:	44083000 */ 	mfc1	$t0,$f6
/*    1d418:	00000000 */ 	nop
/*    1d41c:	0106082a */ 	slt	$at,$t0,$a2
/*    1d420:	50200006 */ 	beqzl	$at,.L0001d43c
/*    1d424:	a7a50026 */ 	sh	$a1,0x26($sp)
/*    1d428:	0fc25e7a */ 	jal	ceil
/*    1d42c:	00000000 */ 	nop
/*    1d430:	1000002d */ 	b	.L0001d4e8
/*    1d434:	00403025 */ 	or	$a2,$v0,$zero
/*    1d438:	a7a50026 */ 	sh	$a1,0x26($sp)
.L0001d43c:
/*    1d43c:	0c008dda */ 	jal	animGetNumFrames
/*    1d440:	afa60020 */ 	sw	$a2,0x20($sp)
/*    1d444:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    1d448:	87a50026 */ 	lh	$a1,0x26($sp)
/*    1d44c:	3c0a8006 */ 	lui	$t2,%hi(var8005efbc)
/*    1d450:	00c2082a */ 	slt	$at,$a2,$v0
/*    1d454:	54200025 */ 	bnezl	$at,.L0001d4ec
/*    1d458:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d45c:	8d4aefbc */ 	lw	$t2,%lo(var8005efbc)($t2)
/*    1d460:	3c0b8006 */ 	lui	$t3,%hi(g_Anims)
/*    1d464:	00056080 */ 	sll	$t4,$a1,0x2
/*    1d468:	15400008 */ 	bnez	$t2,.L0001d48c
/*    1d46c:	00052400 */ 	sll	$a0,$a1,0x10
/*    1d470:	8d6bf00c */ 	lw	$t3,%lo(g_Anims)($t3)
/*    1d474:	01856023 */ 	subu	$t4,$t4,$a1
/*    1d478:	000c6080 */ 	sll	$t4,$t4,0x2
/*    1d47c:	016c6821 */ 	addu	$t5,$t3,$t4
/*    1d480:	91af000b */ 	lbu	$t7,0xb($t5)
/*    1d484:	31ee0001 */ 	andi	$t6,$t7,0x1
/*    1d488:	11c00012 */ 	beqz	$t6,.L0001d4d4
.L0001d48c:
/*    1d48c:	0004c403 */ 	sra	$t8,$a0,0x10
/*    1d490:	03002025 */ 	or	$a0,$t8,$zero
/*    1d494:	0c008dda */ 	jal	animGetNumFrames
/*    1d498:	afa60020 */ 	sw	$a2,0x20($sp)
/*    1d49c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    1d4a0:	00c2001a */ 	div	$zero,$a2,$v0
/*    1d4a4:	14400002 */ 	bnez	$v0,.L0001d4b0
/*    1d4a8:	00000000 */ 	nop
/*    1d4ac:	0007000d */ 	break	0x7
.L0001d4b0:
/*    1d4b0:	2401ffff */ 	addiu	$at,$zero,-1
/*    1d4b4:	14410004 */ 	bne	$v0,$at,.L0001d4c8
/*    1d4b8:	3c018000 */ 	lui	$at,0x8000
/*    1d4bc:	14c10002 */ 	bne	$a2,$at,.L0001d4c8
/*    1d4c0:	00000000 */ 	nop
/*    1d4c4:	0006000d */ 	break	0x6
.L0001d4c8:
/*    1d4c8:	00003010 */ 	mfhi	$a2
/*    1d4cc:	10000007 */ 	b	.L0001d4ec
/*    1d4d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001d4d4:
/*    1d4d4:	00052400 */ 	sll	$a0,$a1,0x10
/*    1d4d8:	0004cc03 */ 	sra	$t9,$a0,0x10
/*    1d4dc:	0c008dda */ 	jal	animGetNumFrames
/*    1d4e0:	03202025 */ 	or	$a0,$t9,$zero
/*    1d4e4:	2446ffff */ 	addiu	$a2,$v0,-1
.L0001d4e8:
/*    1d4e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001d4ec:
/*    1d4ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1d4f0:	00c01025 */ 	or	$v0,$a2,$zero
/*    1d4f4:	03e00008 */ 	jr	$ra
/*    1d4f8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001d4fc
/*    1d4fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1d500:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1d504:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1d508:	44856000 */ 	mtc1	$a1,$f12
/*    1d50c:	50400044 */ 	beqzl	$v0,.L0001d620
/*    1d510:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d514:	44802000 */ 	mtc1	$zero,$f4
/*    1d518:	00000000 */ 	nop
/*    1d51c:	460c203c */ 	c.lt.s	$f4,$f12
/*    1d520:	00000000 */ 	nop
/*    1d524:	4502003d */ 	bc1fl	.L0001d61c
/*    1d528:	a4400002 */ 	sh	$zero,0x2($v0)
/*    1d52c:	84430000 */ 	lh	$v1,0x0($v0)
/*    1d530:	5060003a */ 	beqzl	$v1,.L0001d61c
/*    1d534:	a4400002 */ 	sh	$zero,0x2($v0)
/*    1d538:	844e0002 */ 	lh	$t6,0x2($v0)
/*    1d53c:	3c013f80 */ 	lui	$at,0x3f80
/*    1d540:	51c00008 */ 	beqzl	$t6,.L0001d564
/*    1d544:	8c8f0008 */ 	lw	$t7,0x8($a0)
/*    1d548:	44813000 */ 	mtc1	$at,$f6
/*    1d54c:	c4480054 */ 	lwc1	$f8,0x54($v0)
/*    1d550:	46083032 */ 	c.eq.s	$f6,$f8
/*    1d554:	00000000 */ 	nop
/*    1d558:	45030031 */ 	bc1tl	.L0001d620
/*    1d55c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1d560:	8c8f0008 */ 	lw	$t7,0x8($a0)
.L0001d564:
/*    1d564:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*    1d568:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*    1d56c:	8de50000 */ 	lw	$a1,0x0($t7)
/*    1d570:	80590008 */ 	lb	$t9,0x8($v0)
/*    1d574:	84480014 */ 	lh	$t0,0x14($v0)
/*    1d578:	94a60000 */ 	lhu	$a2,0x0($a1)
/*    1d57c:	e44a0030 */ 	swc1	$f10,0x30($v0)
/*    1d580:	e4500034 */ 	swc1	$f16,0x34($v0)
/*    1d584:	84490016 */ 	lh	$t1,0x16($v0)
/*    1d588:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*    1d58c:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*    1d590:	c4460024 */ 	lwc1	$f6,0x24($v0)
/*    1d594:	c4480028 */ 	lwc1	$f8,0x28($v0)
/*    1d598:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*    1d59c:	c4500018 */ 	lwc1	$f16,0x18($v0)
/*    1d5a0:	24010001 */ 	addiu	$at,$zero,0x1
/*    1d5a4:	30d800ff */ 	andi	$t8,$a2,0xff
/*    1d5a8:	a4430002 */ 	sh	$v1,0x2($v0)
/*    1d5ac:	a0590009 */ 	sb	$t9,0x9($v0)
/*    1d5b0:	a4480038 */ 	sh	$t0,0x38($v0)
/*    1d5b4:	a449003a */ 	sh	$t1,0x3a($v0)
/*    1d5b8:	e4520040 */ 	swc1	$f18,0x40($v0)
/*    1d5bc:	e4440044 */ 	swc1	$f4,0x44($v0)
/*    1d5c0:	e4460048 */ 	swc1	$f6,0x48($v0)
/*    1d5c4:	e448004c */ 	swc1	$f8,0x4c($v0)
/*    1d5c8:	e44a0050 */ 	swc1	$f10,0x50($v0)
/*    1d5cc:	17010013 */ 	bne	$t8,$at,.L0001d61c
/*    1d5d0:	e450003c */ 	swc1	$f16,0x3c($v0)
/*    1d5d4:	0c006a87 */ 	jal	modelGetNodeData
/*    1d5d8:	00000000 */ 	nop
/*    1d5dc:	c4520034 */ 	lwc1	$f18,0x34($v0)
/*    1d5e0:	c4440038 */ 	lwc1	$f4,0x38($v0)
/*    1d5e4:	c446003c */ 	lwc1	$f6,0x3c($v0)
/*    1d5e8:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*    1d5ec:	c44a0028 */ 	lwc1	$f10,0x28($v0)
/*    1d5f0:	c450002c */ 	lwc1	$f16,0x2c($v0)
/*    1d5f4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    1d5f8:	a04a0002 */ 	sb	$t2,0x2($v0)
/*    1d5fc:	e452004c */ 	swc1	$f18,0x4c($v0)
/*    1d600:	e4440050 */ 	swc1	$f4,0x50($v0)
/*    1d604:	e4460054 */ 	swc1	$f6,0x54($v0)
/*    1d608:	e4480040 */ 	swc1	$f8,0x40($v0)
/*    1d60c:	e44a0044 */ 	swc1	$f10,0x44($v0)
/*    1d610:	10000002 */ 	b	.L0001d61c
/*    1d614:	e4500048 */ 	swc1	$f16,0x48($v0)
/*    1d618:	a4400002 */ 	sh	$zero,0x2($v0)
.L0001d61c:
/*    1d61c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001d620:
/*    1d620:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1d624:	03e00008 */ 	jr	$ra
/*    1d628:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001d62c
.late_rodata
glabel var70054444
.word 0x40c907a9
glabel var70054448
.word 0x40c907a9
glabel var7005444c
.word 0x40c907a9
.text
/*    1d62c:	27bdff40 */ 	addiu	$sp,$sp,-192
/*    1d630:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    1d634:	afb10028 */ 	sw	$s1,0x28($sp)
/*    1d638:	afb00024 */ 	sw	$s0,0x24($sp)
/*    1d63c:	afa500c4 */ 	sw	$a1,0xc4($sp)
/*    1d640:	8c910020 */ 	lw	$s1,0x20($a0)
/*    1d644:	44876000 */ 	mtc1	$a3,$f12
/*    1d648:	87a700c6 */ 	lh	$a3,0xc6($sp)
/*    1d64c:	5220014d */ 	beqzl	$s1,.L0001db84
/*    1d650:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1d654:	862e0000 */ 	lh	$t6,0x0($s1)
/*    1d658:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*    1d65c:	3c013f80 */ 	lui	$at,0x3f80
/*    1d660:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*    1d664:	afaf0038 */ 	sw	$t7,0x38($sp)
/*    1d668:	86380002 */ 	lh	$t8,0x2($s1)
/*    1d66c:	53000008 */ 	beqzl	$t8,.L0001d690
/*    1d670:	44805000 */ 	mtc1	$zero,$f10
/*    1d674:	44803000 */ 	mtc1	$zero,$f6
/*    1d678:	44814000 */ 	mtc1	$at,$f8
/*    1d67c:	e6240058 */ 	swc1	$f4,0x58($s1)
/*    1d680:	e626005c */ 	swc1	$f6,0x5c($s1)
/*    1d684:	10000005 */ 	b	.L0001d69c
/*    1d688:	e6280054 */ 	swc1	$f8,0x54($s1)
/*    1d68c:	44805000 */ 	mtc1	$zero,$f10
.L0001d690:
/*    1d690:	44802000 */ 	mtc1	$zero,$f4
/*    1d694:	e62a0058 */ 	swc1	$f10,0x58($s1)
/*    1d698:	e6240054 */ 	swc1	$f4,0x54($s1)
.L0001d69c:
/*    1d69c:	3c01bf80 */ 	lui	$at,0xbf80
/*    1d6a0:	44813000 */ 	mtc1	$at,$f6
/*    1d6a4:	a6270000 */ 	sh	$a3,0x0($s1)
/*    1d6a8:	a2260008 */ 	sb	$a2,0x8($s1)
/*    1d6ac:	e6260018 */ 	swc1	$f6,0x18($s1)
/*    1d6b0:	c7a800d0 */ 	lwc1	$f8,0xd0($sp)
/*    1d6b4:	44805000 */ 	mtc1	$zero,$f10
/*    1d6b8:	44056000 */ 	mfc1	$a1,$f12
/*    1d6bc:	e628001c */ 	swc1	$f8,0x1c($s1)
/*    1d6c0:	e62a0028 */ 	swc1	$f10,0x28($s1)
/*    1d6c4:	0c007806 */ 	jal	func0001e018
/*    1d6c8:	afa400c0 */ 	sw	$a0,0xc0($sp)
/*    1d6cc:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*    1d6d0:	a220000a */ 	sb	$zero,0xa($s1)
/*    1d6d4:	24010001 */ 	addiu	$at,$zero,0x1
/*    1d6d8:	8c990008 */ 	lw	$t9,0x8($a0)
/*    1d6dc:	8f250000 */ 	lw	$a1,0x0($t9)
/*    1d6e0:	94a20000 */ 	lhu	$v0,0x0($a1)
/*    1d6e4:	304800ff */ 	andi	$t0,$v0,0xff
/*    1d6e8:	55010126 */ 	bnel	$t0,$at,.L0001db84
/*    1d6ec:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1d6f0:	8ca90004 */ 	lw	$t1,0x4($a1)
/*    1d6f4:	0c006a87 */ 	jal	modelGetNodeData
/*    1d6f8:	afa900ac */ 	sw	$t1,0xac($sp)
/*    1d6fc:	8fab00c0 */ 	lw	$t3,0xc0($sp)
/*    1d700:	3c0d8006 */ 	lui	$t5,%hi(var8005efd0)
/*    1d704:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    1d708:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*    1d70c:	25adefd0 */ 	addiu	$t5,$t5,%lo(var8005efd0)
/*    1d710:	8da10000 */ 	lw	$at,0x0($t5)
/*    1d714:	27a30088 */ 	addiu	$v1,$sp,0x88
/*    1d718:	95440000 */ 	lhu	$a0,0x0($t2)
/*    1d71c:	8d860004 */ 	lw	$a2,0x4($t4)
/*    1d720:	ac610000 */ 	sw	$at,0x0($v1)
/*    1d724:	8db80004 */ 	lw	$t8,0x4($t5)
/*    1d728:	3c198006 */ 	lui	$t9,%hi(g_Anims)
/*    1d72c:	00408025 */ 	or	$s0,$v0,$zero
/*    1d730:	ac780004 */ 	sw	$t8,0x4($v1)
/*    1d734:	8da10008 */ 	lw	$at,0x8($t5)
/*    1d738:	ac610008 */ 	sw	$at,0x8($v1)
/*    1d73c:	86270000 */ 	lh	$a3,0x0($s1)
/*    1d740:	8f39f00c */ 	lw	$t9,%lo(g_Anims)($t9)
/*    1d744:	00074080 */ 	sll	$t0,$a3,0x2
/*    1d748:	01074023 */ 	subu	$t0,$t0,$a3
/*    1d74c:	00084080 */ 	sll	$t0,$t0,0x2
/*    1d750:	03284821 */ 	addu	$t1,$t9,$t0
/*    1d754:	912a000b */ 	lbu	$t2,0xb($t1)
/*    1d758:	314b0002 */ 	andi	$t3,$t2,0x2
/*    1d75c:	51600051 */ 	beqzl	$t3,.L0001d8a4
/*    1d760:	862b0016 */ 	lh	$t3,0x16($s1)
/*    1d764:	afa400a4 */ 	sw	$a0,0xa4($sp)
/*    1d768:	0fc57222 */ 	jal	func0f15c888
/*    1d76c:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*    1d770:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*    1d774:	0c008f4e */ 	jal	func00023d38
/*    1d778:	86240000 */ 	lh	$a0,0x0($s1)
/*    1d77c:	86240000 */ 	lh	$a0,0x0($s1)
/*    1d780:	0c008eac */ 	jal	func00023ab0
/*    1d784:	86250014 */ 	lh	$a1,0x14($s1)
/*    1d788:	0c008f43 */ 	jal	func00023d0c
/*    1d78c:	a3a20083 */ 	sb	$v0,0x83($sp)
/*    1d790:	82250008 */ 	lb	$a1,0x8($s1)
/*    1d794:	86270000 */ 	lh	$a3,0x0($s1)
/*    1d798:	93ac0083 */ 	lbu	$t4,0x83($sp)
/*    1d79c:	27af0074 */ 	addiu	$t7,$sp,0x74
/*    1d7a0:	27ae0088 */ 	addiu	$t6,$sp,0x88
/*    1d7a4:	27ad0068 */ 	addiu	$t5,$sp,0x68
/*    1d7a8:	afad001c */ 	sw	$t5,0x1c($sp)
/*    1d7ac:	afae0018 */ 	sw	$t6,0x18($sp)
/*    1d7b0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    1d7b4:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*    1d7b8:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    1d7bc:	0c009014 */ 	jal	func00024050
/*    1d7c0:	afac0010 */ 	sw	$t4,0x10($sp)
/*    1d7c4:	c7a00064 */ 	lwc1	$f0,0x64($sp)
/*    1d7c8:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*    1d7cc:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    1d7d0:	e6060034 */ 	swc1	$f6,0x34($s0)
/*    1d7d4:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*    1d7d8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*    1d7dc:	c6080014 */ 	lwc1	$f8,0x14($s0)
/*    1d7e0:	e60a0038 */ 	swc1	$f10,0x38($s0)
/*    1d7e4:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*    1d7e8:	e6080030 */ 	swc1	$f8,0x30($s0)
/*    1d7ec:	44805000 */ 	mtc1	$zero,$f10
/*    1d7f0:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    1d7f4:	e606003c */ 	swc1	$f6,0x3c($s0)
/*    1d7f8:	c6240010 */ 	lwc1	$f4,0x10($s1)
/*    1d7fc:	46045032 */ 	c.eq.s	$f10,$f4
/*    1d800:	00000000 */ 	nop
/*    1d804:	45000003 */ 	bc1f	.L0001d814
/*    1d808:	00000000 */ 	nop
/*    1d80c:	100000dc */ 	b	.L0001db80
/*    1d810:	a2000001 */ 	sb	$zero,0x1($s0)
.L0001d814:
/*    1d814:	0c008f4e */ 	jal	func00023d38
/*    1d818:	86240000 */ 	lh	$a0,0x0($s1)
/*    1d81c:	86240000 */ 	lh	$a0,0x0($s1)
/*    1d820:	0c008eac */ 	jal	func00023ab0
/*    1d824:	86250016 */ 	lh	$a1,0x16($s1)
/*    1d828:	0c008f43 */ 	jal	func00023d0c
/*    1d82c:	a3a20083 */ 	sb	$v0,0x83($sp)
/*    1d830:	82250008 */ 	lb	$a1,0x8($s1)
/*    1d834:	86270000 */ 	lh	$a3,0x0($s1)
/*    1d838:	93b80083 */ 	lbu	$t8,0x83($sp)
/*    1d83c:	27b90074 */ 	addiu	$t9,$sp,0x74
/*    1d840:	27a80088 */ 	addiu	$t0,$sp,0x88
/*    1d844:	27a90068 */ 	addiu	$t1,$sp,0x68
/*    1d848:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    1d84c:	afa80018 */ 	sw	$t0,0x18($sp)
/*    1d850:	afb90014 */ 	sw	$t9,0x14($sp)
/*    1d854:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*    1d858:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    1d85c:	0c009014 */ 	jal	func00024050
/*    1d860:	afb80010 */ 	sw	$t8,0x10($sp)
/*    1d864:	c7a00064 */ 	lwc1	$f0,0x64($sp)
/*    1d868:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*    1d86c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    1d870:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    1d874:	e6080024 */ 	swc1	$f8,0x24($s0)
/*    1d878:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*    1d87c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*    1d880:	c60a0014 */ 	lwc1	$f10,0x14($s0)
/*    1d884:	e6040028 */ 	swc1	$f4,0x28($s0)
/*    1d888:	c7a60090 */ 	lwc1	$f6,0x90($sp)
/*    1d88c:	a20a0001 */ 	sb	$t2,0x1($s0)
/*    1d890:	e60a0020 */ 	swc1	$f10,0x20($s0)
/*    1d894:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    1d898:	100000b9 */ 	b	.L0001db80
/*    1d89c:	e608002c */ 	swc1	$f8,0x2c($s0)
/*    1d8a0:	862b0016 */ 	lh	$t3,0x16($s1)
.L0001d8a4:
/*    1d8a4:	82250008 */ 	lb	$a1,0x8($s1)
/*    1d8a8:	afa30014 */ 	sw	$v1,0x14($sp)
/*    1d8ac:	afab0010 */ 	sw	$t3,0x10($sp)
/*    1d8b0:	822c000b */ 	lb	$t4,0xb($s1)
/*    1d8b4:	0c0092d9 */ 	jal	func00024b64
/*    1d8b8:	afac0018 */ 	sw	$t4,0x18($sp)
/*    1d8bc:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*    1d8c0:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*    1d8c4:	c6260088 */ 	lwc1	$f6,0x88($s1)
/*    1d8c8:	c5e40014 */ 	lwc1	$f4,0x14($t7)
/*    1d8cc:	3c013f80 */ 	lui	$at,0x3f80
/*    1d8d0:	44814000 */ 	mtc1	$at,$f8
/*    1d8d4:	46062082 */ 	mul.s	$f2,$f4,$f6
/*    1d8d8:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*    1d8dc:	46081032 */ 	c.eq.s	$f2,$f8
/*    1d8e0:	00000000 */ 	nop
/*    1d8e4:	4503000a */ 	bc1tl	.L0001d910
/*    1d8e8:	822e000b */ 	lb	$t6,0xb($s1)
/*    1d8ec:	46025102 */ 	mul.s	$f4,$f10,$f2
/*    1d8f0:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*    1d8f4:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*    1d8f8:	46023202 */ 	mul.s	$f8,$f6,$f2
/*    1d8fc:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*    1d900:	46025102 */ 	mul.s	$f4,$f10,$f2
/*    1d904:	e7a8008c */ 	swc1	$f8,0x8c($sp)
/*    1d908:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*    1d90c:	822e000b */ 	lb	$t6,0xb($s1)
.L0001d910:
/*    1d910:	11c00005 */ 	beqz	$t6,.L0001d928
/*    1d914:	00000000 */ 	nop
/*    1d918:	c606000c */ 	lwc1	$f6,0xc($s0)
/*    1d91c:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*    1d920:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    1d924:	e7aa008c */ 	swc1	$f10,0x8c($sp)
.L0001d928:
/*    1d928:	0c0068f4 */ 	jal	cosf
/*    1d92c:	c60c0014 */ 	lwc1	$f12,0x14($s0)
/*    1d930:	c60c0014 */ 	lwc1	$f12,0x14($s0)
/*    1d934:	0c0068f7 */ 	jal	sinf
/*    1d938:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*    1d93c:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*    1d940:	44802000 */ 	mtc1	$zero,$f4
/*    1d944:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*    1d948:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    1d94c:	46022032 */ 	c.eq.s	$f4,$f2
/*    1d950:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*    1d954:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*    1d958:	45000032 */ 	bc1f	.L0001da24
/*    1d95c:	00000000 */ 	nop
/*    1d960:	c606000c */ 	lwc1	$f6,0xc($s0)
/*    1d964:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*    1d968:	c6020008 */ 	lwc1	$f2,0x8($s0)
/*    1d96c:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*    1d970:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    1d974:	c6060014 */ 	lwc1	$f6,0x14($s0)
/*    1d978:	e6020034 */ 	swc1	$f2,0x34($s0)
/*    1d97c:	e604003c */ 	swc1	$f4,0x3c($s0)
/*    1d980:	e60a0038 */ 	swc1	$f10,0x38($s0)
/*    1d984:	e6060030 */ 	swc1	$f6,0x30($s0)
/*    1d988:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*    1d98c:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*    1d990:	46004282 */ 	mul.s	$f10,$f8,$f0
/*    1d994:	00000000 */ 	nop
/*    1d998:	46122182 */ 	mul.s	$f6,$f4,$f18
/*    1d99c:	46061180 */ 	add.s	$f6,$f2,$f6
/*    1d9a0:	46002102 */ 	mul.s	$f4,$f4,$f0
/*    1d9a4:	46065280 */ 	add.s	$f10,$f10,$f6
/*    1d9a8:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*    1d9ac:	e7aa0058 */ 	swc1	$f10,0x58($sp)
/*    1d9b0:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*    1d9b4:	c606003c */ 	lwc1	$f6,0x3c($s0)
/*    1d9b8:	46043181 */ 	sub.s	$f6,$f6,$f4
/*    1d9bc:	46124102 */ 	mul.s	$f4,$f8,$f18
/*    1d9c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1d9c4:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*    1d9c8:	e60a0024 */ 	swc1	$f10,0x24($s0)
/*    1d9cc:	c60a0018 */ 	lwc1	$f10,0x18($s0)
/*    1d9d0:	44804000 */ 	mtc1	$zero,$f8
/*    1d9d4:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*    1d9d8:	460a4032 */ 	c.eq.s	$f8,$f10
/*    1d9dc:	e6040028 */ 	swc1	$f4,0x28($s0)
/*    1d9e0:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*    1d9e4:	4500000d */ 	bc1f	.L0001da1c
/*    1d9e8:	e606002c */ 	swc1	$f6,0x2c($s0)
/*    1d9ec:	c6040030 */ 	lwc1	$f4,0x30($s0)
/*    1d9f0:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*    1d9f4:	3c017005 */ 	lui	$at,%hi(var70054444)
/*    1d9f8:	c4224444 */ 	lwc1	$f2,%lo(var70054444)($at)
/*    1d9fc:	46062000 */ 	add.s	$f0,$f4,$f6
/*    1da00:	4600103e */ 	c.le.s	$f2,$f0
/*    1da04:	e6000020 */ 	swc1	$f0,0x20($s0)
/*    1da08:	45000004 */ 	bc1f	.L0001da1c
/*    1da0c:	00000000 */ 	nop
/*    1da10:	c6080020 */ 	lwc1	$f8,0x20($s0)
/*    1da14:	46024281 */ 	sub.s	$f10,$f8,$f2
/*    1da18:	e60a0020 */ 	swc1	$f10,0x20($s0)
.L0001da1c:
/*    1da1c:	10000053 */ 	b	.L0001db6c
/*    1da20:	a20d0001 */ 	sb	$t5,0x1($s0)
.L0001da24:
/*    1da24:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    1da28:	3c013f80 */ 	lui	$at,0x3f80
/*    1da2c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1da30:	46124282 */ 	mul.s	$f10,$f8,$f18
/*    1da34:	460a3380 */ 	add.s	$f14,$f6,$f10
/*    1da38:	46122182 */ 	mul.s	$f6,$f4,$f18
/*    1da3c:	46004287 */ 	neg.s	$f10,$f8
/*    1da40:	46005102 */ 	mul.s	$f4,$f10,$f0
/*    1da44:	46043200 */ 	add.s	$f8,$f6,$f4
/*    1da48:	44813000 */ 	mtc1	$at,$f6
/*    1da4c:	00000000 */ 	nop
/*    1da50:	46023101 */ 	sub.s	$f4,$f6,$f2
/*    1da54:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*    1da58:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*    1da5c:	e7b00050 */ 	swc1	$f16,0x50($sp)
/*    1da60:	46047182 */ 	mul.s	$f6,$f14,$f4
/*    1da64:	46065100 */ 	add.s	$f4,$f10,$f6
/*    1da68:	44815000 */ 	mtc1	$at,$f10
/*    1da6c:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*    1da70:	c6260010 */ 	lwc1	$f6,0x10($s1)
/*    1da74:	46065101 */ 	sub.s	$f4,$f10,$f6
/*    1da78:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*    1da7c:	46044282 */ 	mul.s	$f10,$f8,$f4
/*    1da80:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*    1da84:	460a3200 */ 	add.s	$f8,$f6,$f10
/*    1da88:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*    1da8c:	e6040024 */ 	swc1	$f4,0x24($s0)
/*    1da90:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*    1da94:	c6080024 */ 	lwc1	$f8,0x24($s0)
/*    1da98:	e6060028 */ 	swc1	$f6,0x28($s0)
/*    1da9c:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*    1daa0:	c606000c */ 	lwc1	$f6,0xc($s0)
/*    1daa4:	460e4101 */ 	sub.s	$f4,$f8,$f14
/*    1daa8:	e60a002c */ 	swc1	$f10,0x2c($s0)
/*    1daac:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*    1dab0:	e6040034 */ 	swc1	$f4,0x34($s0)
/*    1dab4:	460a3301 */ 	sub.s	$f12,$f6,$f10
/*    1dab8:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*    1dabc:	44813000 */ 	mtc1	$at,$f6
/*    1dac0:	3c017005 */ 	lui	$at,%hi(var70054448)
/*    1dac4:	460c8201 */ 	sub.s	$f8,$f16,$f12
/*    1dac8:	46023281 */ 	sub.s	$f10,$f6,$f2
/*    1dacc:	46024102 */ 	mul.s	$f4,$f8,$f2
/*    1dad0:	460a2203 */ 	div.s	$f8,$f4,$f10
/*    1dad4:	c604002c */ 	lwc1	$f4,0x2c($s0)
/*    1dad8:	46086181 */ 	sub.s	$f6,$f12,$f8
/*    1dadc:	c60c0014 */ 	lwc1	$f12,0x14($s0)
/*    1dae0:	e6060038 */ 	swc1	$f6,0x38($s0)
/*    1dae4:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*    1dae8:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*    1daec:	44802000 */ 	mtc1	$zero,$f4
/*    1daf0:	e608003c */ 	swc1	$f8,0x3c($s0)
/*    1daf4:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*    1daf8:	46066381 */ 	sub.s	$f14,$f12,$f6
/*    1dafc:	4604703c */ 	c.lt.s	$f14,$f4
/*    1db00:	00000000 */ 	nop
/*    1db04:	45000003 */ 	bc1f	.L0001db14
/*    1db08:	00000000 */ 	nop
/*    1db0c:	c42a4448 */ 	lwc1	$f10,%lo(var70054448)($at)
/*    1db10:	460a7380 */ 	add.s	$f14,$f14,$f10
.L0001db14:
/*    1db14:	0c006bfa */ 	jal	func0001afe8
/*    1db18:	8e260010 */ 	lw	$a2,0x10($s1)
/*    1db1c:	44804000 */ 	mtc1	$zero,$f8
/*    1db20:	c6060018 */ 	lwc1	$f6,0x18($s0)
/*    1db24:	3c017005 */ 	lui	$at,%hi(var7005444c)
/*    1db28:	c422444c */ 	lwc1	$f2,%lo(var7005444c)($at)
/*    1db2c:	46064032 */ 	c.eq.s	$f8,$f6
/*    1db30:	e6000030 */ 	swc1	$f0,0x30($s0)
/*    1db34:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*    1db38:	24180001 */ 	addiu	$t8,$zero,0x1
/*    1db3c:	4502000b */ 	bc1fl	.L0001db6c
/*    1db40:	a2180001 */ 	sb	$t8,0x1($s0)
/*    1db44:	c6040030 */ 	lwc1	$f4,0x30($s0)
/*    1db48:	460a2000 */ 	add.s	$f0,$f4,$f10
/*    1db4c:	4600103e */ 	c.le.s	$f2,$f0
/*    1db50:	e6000020 */ 	swc1	$f0,0x20($s0)
/*    1db54:	45020005 */ 	bc1fl	.L0001db6c
/*    1db58:	a2180001 */ 	sb	$t8,0x1($s0)
/*    1db5c:	c6080020 */ 	lwc1	$f8,0x20($s0)
/*    1db60:	46024181 */ 	sub.s	$f6,$f8,$f2
/*    1db64:	e6060020 */ 	swc1	$f6,0x20($s0)
/*    1db68:	a2180001 */ 	sb	$t8,0x1($s0)
.L0001db6c:
/*    1db6c:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    1db70:	53200004 */ 	beqzl	$t9,.L0001db84
/*    1db74:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1db78:	c6040028 */ 	lwc1	$f4,0x28($s0)
/*    1db7c:	e6040038 */ 	swc1	$f4,0x38($s0)
.L0001db80:
/*    1db80:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001db84:
/*    1db84:	8fb00024 */ 	lw	$s0,0x24($sp)
/*    1db88:	8fb10028 */ 	lw	$s1,0x28($sp)
/*    1db8c:	03e00008 */ 	jr	$ra
/*    1db90:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel func0001db94
/*    1db94:	50800017 */ 	beqzl	$a0,.L0001dbf4
/*    1db98:	00001025 */ 	or	$v0,$zero,$zero
/*    1db9c:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1dba0:	50400014 */ 	beqzl	$v0,.L0001dbf4
/*    1dba4:	00001025 */ 	or	$v0,$zero,$zero
/*    1dba8:	844e0002 */ 	lh	$t6,0x2($v0)
/*    1dbac:	51c00011 */ 	beqzl	$t6,.L0001dbf4
/*    1dbb0:	00001025 */ 	or	$v0,$zero,$zero
/*    1dbb4:	c4400054 */ 	lwc1	$f0,0x54($v0)
/*    1dbb8:	44802000 */ 	mtc1	$zero,$f4
/*    1dbbc:	3c013f80 */ 	lui	$at,0x3f80
/*    1dbc0:	46002032 */ 	c.eq.s	$f4,$f0
/*    1dbc4:	00000000 */ 	nop
/*    1dbc8:	4503000a */ 	bc1tl	.L0001dbf4
/*    1dbcc:	00001025 */ 	or	$v0,$zero,$zero
/*    1dbd0:	44813000 */ 	mtc1	$at,$f6
/*    1dbd4:	00000000 */ 	nop
/*    1dbd8:	46003032 */ 	c.eq.s	$f6,$f0
/*    1dbdc:	00000000 */ 	nop
/*    1dbe0:	45030004 */ 	bc1tl	.L0001dbf4
/*    1dbe4:	00001025 */ 	or	$v0,$zero,$zero
/*    1dbe8:	03e00008 */ 	jr	$ra
/*    1dbec:	24020001 */ 	addiu	$v0,$zero,0x1
/*    1dbf0:	00001025 */ 	or	$v0,$zero,$zero
.L0001dbf4:
/*    1dbf4:	03e00008 */ 	jr	$ra
/*    1dbf8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001dbfc
/*    1dbfc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1dc00:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1dc04:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1dc08:	afa60028 */ 	sw	$a2,0x28($sp)
/*    1dc0c:	1080002b */ 	beqz	$a0,.L0001dcbc
/*    1dc10:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    1dc14:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1dc18:	5040001a */ 	beqzl	$v0,.L0001dc84
/*    1dc1c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    1dc20:	84430000 */ 	lh	$v1,0x0($v0)
/*    1dc24:	2405000c */ 	addiu	$a1,$zero,0xc
/*    1dc28:	50600016 */ 	beqzl	$v1,.L0001dc84
/*    1dc2c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    1dc30:	00650019 */ 	multu	$v1,$a1
/*    1dc34:	3c028006 */ 	lui	$v0,%hi(g_Anims)
/*    1dc38:	8c42f00c */ 	lw	$v0,%lo(g_Anims)($v0)
/*    1dc3c:	87a80026 */ 	lh	$t0,0x26($sp)
/*    1dc40:	00007012 */ 	mflo	$t6
/*    1dc44:	004e7821 */ 	addu	$t7,$v0,$t6
/*    1dc48:	91f8000b */ 	lbu	$t8,0xb($t7)
/*    1dc4c:	33190002 */ 	andi	$t9,$t8,0x2
/*    1dc50:	5320000c */ 	beqzl	$t9,.L0001dc84
/*    1dc54:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    1dc58:	01050019 */ 	multu	$t0,$a1
/*    1dc5c:	00004812 */ 	mflo	$t1
/*    1dc60:	00495021 */ 	addu	$t2,$v0,$t1
/*    1dc64:	914b000b */ 	lbu	$t3,0xb($t2)
/*    1dc68:	316c0002 */ 	andi	$t4,$t3,0x2
/*    1dc6c:	55800005 */ 	bnezl	$t4,.L0001dc84
/*    1dc70:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    1dc74:	44802000 */ 	mtc1	$zero,$f4
/*    1dc78:	00000000 */ 	nop
/*    1dc7c:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*    1dc80:	8fad0038 */ 	lw	$t5,0x38($sp)
.L0001dc84:
/*    1dc84:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    1dc88:	51a00005 */ 	beqzl	$t5,.L0001dca0
/*    1dc8c:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    1dc90:	0c00753f */ 	jal	func0001d4fc
/*    1dc94:	afa40020 */ 	sw	$a0,0x20($sp)
/*    1dc98:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    1dc9c:	c7a60030 */ 	lwc1	$f6,0x30($sp)
.L0001dca0:
/*    1dca0:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*    1dca4:	87a50026 */ 	lh	$a1,0x26($sp)
/*    1dca8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    1dcac:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*    1dcb0:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    1dcb4:	0c00758b */ 	jal	func0001d62c
/*    1dcb8:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0001dcbc:
/*    1dcbc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1dcc0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1dcc4:	03e00008 */ 	jr	$ra
/*    1dcc8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel modelSetAnimation
/*    1dccc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1dcd0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1dcd4:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1dcd8:	afa60028 */ 	sw	$a2,0x28($sp)
/*    1dcdc:	10800028 */ 	beqz	$a0,.L0001dd80
/*    1dce0:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    1dce4:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1dce8:	5040001a */ 	beqzl	$v0,.L0001dd54
/*    1dcec:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    1dcf0:	84430000 */ 	lh	$v1,0x0($v0)
/*    1dcf4:	2405000c */ 	addiu	$a1,$zero,0xc
/*    1dcf8:	50600016 */ 	beqzl	$v1,.L0001dd54
/*    1dcfc:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    1dd00:	00650019 */ 	multu	$v1,$a1
/*    1dd04:	3c028006 */ 	lui	$v0,%hi(g_Anims)
/*    1dd08:	8c42f00c */ 	lw	$v0,%lo(g_Anims)($v0)
/*    1dd0c:	87a80026 */ 	lh	$t0,0x26($sp)
/*    1dd10:	00007012 */ 	mflo	$t6
/*    1dd14:	004e7821 */ 	addu	$t7,$v0,$t6
/*    1dd18:	91f8000b */ 	lbu	$t8,0xb($t7)
/*    1dd1c:	33190002 */ 	andi	$t9,$t8,0x2
/*    1dd20:	5320000c */ 	beqzl	$t9,.L0001dd54
/*    1dd24:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    1dd28:	01050019 */ 	multu	$t0,$a1
/*    1dd2c:	00004812 */ 	mflo	$t1
/*    1dd30:	00495021 */ 	addu	$t2,$v0,$t1
/*    1dd34:	914b000b */ 	lbu	$t3,0xb($t2)
/*    1dd38:	316c0002 */ 	andi	$t4,$t3,0x2
/*    1dd3c:	55800005 */ 	bnezl	$t4,.L0001dd54
/*    1dd40:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    1dd44:	44802000 */ 	mtc1	$zero,$f4
/*    1dd48:	00000000 */ 	nop
/*    1dd4c:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*    1dd50:	8fa50034 */ 	lw	$a1,0x34($sp)
.L0001dd54:
/*    1dd54:	0c00753f */ 	jal	func0001d4fc
/*    1dd58:	afa40020 */ 	sw	$a0,0x20($sp)
/*    1dd5c:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    1dd60:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*    1dd64:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    1dd68:	87a50026 */ 	lh	$a1,0x26($sp)
/*    1dd6c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    1dd70:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*    1dd74:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    1dd78:	0c00758b */ 	jal	func0001d62c
/*    1dd7c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0001dd80:
/*    1dd80:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1dd84:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1dd88:	03e00008 */ 	jr	$ra
/*    1dd8c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001dd90
/*    1dd90:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1dd94:	10400013 */ 	beqz	$v0,.L0001dde4
/*    1dd98:	00000000 */ 	nop
/*    1dd9c:	8ca30020 */ 	lw	$v1,0x20($a1)
/*    1dda0:	0040c825 */ 	or	$t9,$v0,$zero
/*    1dda4:	24580084 */ 	addiu	$t8,$v0,0x84
/*    1dda8:	1060000e */ 	beqz	$v1,.L0001dde4
/*    1ddac:	00604025 */ 	or	$t0,$v1,$zero
.L0001ddb0:
/*    1ddb0:	8f210000 */ 	lw	$at,0x0($t9)
/*    1ddb4:	2739000c */ 	addiu	$t9,$t9,0xc
/*    1ddb8:	2508000c */ 	addiu	$t0,$t0,0xc
/*    1ddbc:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*    1ddc0:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*    1ddc4:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*    1ddc8:	8f21fffc */ 	lw	$at,-0x4($t9)
/*    1ddcc:	1738fff8 */ 	bne	$t9,$t8,.L0001ddb0
/*    1ddd0:	ad01fffc */ 	sw	$at,-0x4($t0)
/*    1ddd4:	8f210000 */ 	lw	$at,0x0($t9)
/*    1ddd8:	ad010000 */ 	sw	$at,0x0($t0)
/*    1dddc:	8f380004 */ 	lw	$t8,0x4($t9)
/*    1dde0:	ad180004 */ 	sw	$t8,0x4($t0)
.L0001dde4:
/*    1dde4:	03e00008 */ 	jr	$ra
/*    1dde8:	00000000 */ 	nop
);

void modelSetAnimLooping(struct model *model, f32 loopframe, f32 loopmerge)
{
	if (model->anim) {
		model->anim->looping = true;
		model->anim->loopframe = loopframe;
		model->anim->loopmerge = loopmerge;
	}
}

GLOBAL_ASM(
glabel func0001de1c
/*    1de1c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1de20:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1de24:	8c830020 */ 	lw	$v1,0x20($a0)
/*    1de28:	44856000 */ 	mtc1	$a1,$f12
/*    1de2c:	50600017 */ 	beqzl	$v1,.L0001de8c
/*    1de30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1de34:	84640000 */ 	lh	$a0,0x0($v1)
/*    1de38:	50800010 */ 	beqzl	$a0,.L0001de7c
/*    1de3c:	3c01bf80 */ 	lui	$at,0xbf80
/*    1de40:	afa3001c */ 	sw	$v1,0x1c($sp)
/*    1de44:	0c008dda */ 	jal	animGetNumFrames
/*    1de48:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*    1de4c:	244effff */ 	addiu	$t6,$v0,-1
/*    1de50:	448e2000 */ 	mtc1	$t6,$f4
/*    1de54:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*    1de58:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    1de5c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    1de60:	4606603c */ 	c.lt.s	$f12,$f6
/*    1de64:	00000000 */ 	nop
/*    1de68:	45020004 */ 	bc1fl	.L0001de7c
/*    1de6c:	3c01bf80 */ 	lui	$at,0xbf80
/*    1de70:	10000005 */ 	b	.L0001de88
/*    1de74:	e46c0018 */ 	swc1	$f12,0x18($v1)
/*    1de78:	3c01bf80 */ 	lui	$at,0xbf80
.L0001de7c:
/*    1de7c:	44814000 */ 	mtc1	$at,$f8
/*    1de80:	00000000 */ 	nop
/*    1de84:	e4680018 */ 	swc1	$f8,0x18($v1)
.L0001de88:
/*    1de88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001de8c:
/*    1de8c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1de90:	03e00008 */ 	jr	$ra
/*    1de94:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001de98
/*    1de98:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1de9c:	10400002 */ 	beqz	$v0,.L0001dea8
/*    1dea0:	00000000 */ 	nop
/*    1dea4:	ac450068 */ 	sw	$a1,0x68($v0)
.L0001dea8:
/*    1dea8:	03e00008 */ 	jr	$ra
/*    1deac:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001deb0
/*    1deb0:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1deb4:	44857000 */ 	mtc1	$a1,$f14
/*    1deb8:	44866000 */ 	mtc1	$a2,$f12
/*    1debc:	1040000f */ 	beqz	$v0,.L0001defc
/*    1dec0:	00000000 */ 	nop
/*    1dec4:	44800000 */ 	mtc1	$zero,$f0
/*    1dec8:	00000000 */ 	nop
/*    1decc:	460c003c */ 	c.lt.s	$f0,$f12
/*    1ded0:	00000000 */ 	nop
/*    1ded4:	45020008 */ 	bc1fl	.L0001def8
/*    1ded8:	e44e001c */ 	swc1	$f14,0x1c($v0)
/*    1dedc:	c444001c */ 	lwc1	$f4,0x1c($v0)
/*    1dee0:	e44c0028 */ 	swc1	$f12,0x28($v0)
/*    1dee4:	e44e0020 */ 	swc1	$f14,0x20($v0)
/*    1dee8:	e440002c */ 	swc1	$f0,0x2c($v0)
/*    1deec:	03e00008 */ 	jr	$ra
/*    1def0:	e4440024 */ 	swc1	$f4,0x24($v0)
/*    1def4:	e44e001c */ 	swc1	$f14,0x1c($v0)
.L0001def8:
/*    1def8:	e4400028 */ 	swc1	$f0,0x28($v0)
.L0001defc:
/*    1defc:	03e00008 */ 	jr	$ra
/*    1df00:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001df04
/*    1df04:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1df08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1df0c:	8c830020 */ 	lw	$v1,0x20($a0)
/*    1df10:	44856000 */ 	mtc1	$a1,$f12
/*    1df14:	44867000 */ 	mtc1	$a2,$f14
/*    1df18:	10600020 */ 	beqz	$v1,.L0001df9c
/*    1df1c:	00803825 */ 	or	$a3,$a0,$zero
/*    1df20:	c462000c */ 	lwc1	$f2,0xc($v1)
/*    1df24:	460c103e */ 	c.le.s	$f2,$f12
/*    1df28:	00000000 */ 	nop
/*    1df2c:	45020004 */ 	bc1fl	.L0001df40
/*    1df30:	84640000 */ 	lh	$a0,0x0($v1)
/*    1df34:	10000010 */ 	b	.L0001df78
/*    1df38:	46026001 */ 	sub.s	$f0,$f12,$f2
/*    1df3c:	84640000 */ 	lh	$a0,0x0($v1)
.L0001df40:
/*    1df40:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*    1df44:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*    1df48:	afa70020 */ 	sw	$a3,0x20($sp)
/*    1df4c:	0c008dda */ 	jal	animGetNumFrames
/*    1df50:	afa3001c */ 	sw	$v1,0x1c($sp)
/*    1df54:	44822000 */ 	mtc1	$v0,$f4
/*    1df58:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    1df5c:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*    1df60:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    1df64:	c468000c */ 	lwc1	$f8,0xc($v1)
/*    1df68:	8fa70020 */ 	lw	$a3,0x20($sp)
/*    1df6c:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*    1df70:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    1df74:	460c5000 */ 	add.s	$f0,$f10,$f12
.L0001df78:
/*    1df78:	46000480 */ 	add.s	$f18,$f0,$f0
/*    1df7c:	c470001c */ 	lwc1	$f16,0x1c($v1)
/*    1df80:	44067000 */ 	mfc1	$a2,$f14
/*    1df84:	00e02025 */ 	or	$a0,$a3,$zero
/*    1df88:	460e9103 */ 	div.s	$f4,$f18,$f14
/*    1df8c:	46048080 */ 	add.s	$f2,$f16,$f4
/*    1df90:	44051000 */ 	mfc1	$a1,$f2
/*    1df94:	0c0077ac */ 	jal	func0001deb0
/*    1df98:	00000000 */ 	nop
.L0001df9c:
/*    1df9c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1dfa0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1dfa4:	03e00008 */ 	jr	$ra
/*    1dfa8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001dfac
/*    1dfac:	8c820020 */ 	lw	$v0,0x20($a0)
/*    1dfb0:	44857000 */ 	mtc1	$a1,$f14
/*    1dfb4:	44866000 */ 	mtc1	$a2,$f12
/*    1dfb8:	1040000f */ 	beqz	$v0,.L0001dff8
/*    1dfbc:	00000000 */ 	nop
/*    1dfc0:	44800000 */ 	mtc1	$zero,$f0
/*    1dfc4:	00000000 */ 	nop
/*    1dfc8:	460c003c */ 	c.lt.s	$f0,$f12
/*    1dfcc:	00000000 */ 	nop
/*    1dfd0:	45020008 */ 	bc1fl	.L0001dff4
/*    1dfd4:	e44e0074 */ 	swc1	$f14,0x74($v0)
/*    1dfd8:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*    1dfdc:	e44c0080 */ 	swc1	$f12,0x80($v0)
/*    1dfe0:	e44e0078 */ 	swc1	$f14,0x78($v0)
/*    1dfe4:	e4400084 */ 	swc1	$f0,0x84($v0)
/*    1dfe8:	03e00008 */ 	jr	$ra
/*    1dfec:	e444007c */ 	swc1	$f4,0x7c($v0)
/*    1dff0:	e44e0074 */ 	swc1	$f14,0x74($v0)
.L0001dff4:
/*    1dff4:	e4400080 */ 	swc1	$f0,0x80($v0)
.L0001dff8:
/*    1dff8:	03e00008 */ 	jr	$ra
/*    1dffc:	00000000 */ 	nop
);

void modelSetAnim70(struct model *model, void *callback)
{
	if (model->anim) {
		model->anim->unk70 = callback;
	}
}

GLOBAL_ASM(
glabel func0001e018
/*    1e018:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    1e01c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1e020:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1e024:	afa50034 */ 	sw	$a1,0x34($sp)
/*    1e028:	8c900020 */ 	lw	$s0,0x20($a0)
/*    1e02c:	52000043 */ 	beqzl	$s0,.L0001e13c
/*    1e030:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1e034:	0fc25e42 */ 	jal	floor
/*    1e038:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    1e03c:	c604001c */ 	lwc1	$f4,0x1c($s0)
/*    1e040:	44803000 */ 	mtc1	$zero,$f6
/*    1e044:	00402025 */ 	or	$a0,$v0,$zero
/*    1e048:	00004025 */ 	or	$t0,$zero,$zero
/*    1e04c:	4604303e */ 	c.le.s	$f6,$f4
/*    1e050:	2447ffff */ 	addiu	$a3,$v0,-1
/*    1e054:	45000002 */ 	bc1f	.L0001e060
/*    1e058:	00000000 */ 	nop
/*    1e05c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0001e060:
/*    1e060:	11000003 */ 	beqz	$t0,.L0001e070
/*    1e064:	00000000 */ 	nop
/*    1e068:	10000001 */ 	b	.L0001e070
/*    1e06c:	24470001 */ 	addiu	$a3,$v0,0x1
.L0001e070:
/*    1e070:	86050000 */ 	lh	$a1,0x0($s0)
/*    1e074:	8e060018 */ 	lw	$a2,0x18($s0)
/*    1e078:	afa80024 */ 	sw	$t0,0x24($sp)
/*    1e07c:	afa70028 */ 	sw	$a3,0x28($sp)
/*    1e080:	0c0074c8 */ 	jal	func0001d320
/*    1e084:	afa4002c */ 	sw	$a0,0x2c($sp)
/*    1e088:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    1e08c:	a6020014 */ 	sh	$v0,0x14($s0)
/*    1e090:	86050000 */ 	lh	$a1,0x0($s0)
/*    1e094:	0c0074c8 */ 	jal	func0001d320
/*    1e098:	8e060018 */ 	lw	$a2,0x18($s0)
/*    1e09c:	8fa70028 */ 	lw	$a3,0x28($sp)
/*    1e0a0:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    1e0a4:	a6020016 */ 	sh	$v0,0x16($s0)
/*    1e0a8:	86040016 */ 	lh	$a0,0x16($s0)
/*    1e0ac:	86030014 */ 	lh	$v1,0x14($s0)
/*    1e0b0:	14830007 */ 	bne	$a0,$v1,.L0001e0d0
/*    1e0b4:	00000000 */ 	nop
/*    1e0b8:	44835000 */ 	mtc1	$v1,$f10
/*    1e0bc:	44804000 */ 	mtc1	$zero,$f8
/*    1e0c0:	46805420 */ 	cvt.s.w	$f16,$f10
/*    1e0c4:	e6080010 */ 	swc1	$f8,0x10($s0)
/*    1e0c8:	1000001b */ 	b	.L0001e138
/*    1e0cc:	e610000c */ 	swc1	$f16,0xc($s0)
.L0001e0d0:
/*    1e0d0:	1100000b */ 	beqz	$t0,.L0001e100
/*    1e0d4:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    1e0d8:	448e2000 */ 	mtc1	$t6,$f4
/*    1e0dc:	44834000 */ 	mtc1	$v1,$f8
/*    1e0e0:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*    1e0e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    1e0e8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    1e0ec:	46069001 */ 	sub.s	$f0,$f18,$f6
/*    1e0f0:	46005400 */ 	add.s	$f16,$f10,$f0
/*    1e0f4:	e6000010 */ 	swc1	$f0,0x10($s0)
/*    1e0f8:	1000000f */ 	b	.L0001e138
/*    1e0fc:	e610000c */ 	swc1	$f16,0xc($s0)
.L0001e100:
/*    1e100:	44879000 */ 	mtc1	$a3,$f18
/*    1e104:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*    1e108:	3c013f80 */ 	lui	$at,0x3f80
/*    1e10c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    1e110:	44811000 */ 	mtc1	$at,$f2
/*    1e114:	44845000 */ 	mtc1	$a0,$f10
/*    1e118:	00000000 */ 	nop
/*    1e11c:	46805420 */ 	cvt.s.w	$f16,$f10
/*    1e120:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    1e124:	46081001 */ 	sub.s	$f0,$f2,$f8
/*    1e128:	46001481 */ 	sub.s	$f18,$f2,$f0
/*    1e12c:	e6000010 */ 	swc1	$f0,0x10($s0)
/*    1e130:	46128100 */ 	add.s	$f4,$f16,$f18
/*    1e134:	e604000c */ 	swc1	$f4,0xc($s0)
.L0001e138:
/*    1e138:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0001e13c:
/*    1e13c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1e140:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    1e144:	03e00008 */ 	jr	$ra
/*    1e148:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001e14c
/*    1e14c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    1e150:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    1e154:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1e158:	afa60038 */ 	sw	$a2,0x38($sp)
/*    1e15c:	8c900020 */ 	lw	$s0,0x20($a0)
/*    1e160:	44856000 */ 	mtc1	$a1,$f12
/*    1e164:	52000049 */ 	beqzl	$s0,.L0001e28c
/*    1e168:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1e16c:	44056000 */ 	mfc1	$a1,$f12
/*    1e170:	0c007806 */ 	jal	func0001e018
/*    1e174:	00000000 */ 	nop
/*    1e178:	860e0002 */ 	lh	$t6,0x2($s0)
/*    1e17c:	51c00043 */ 	beqzl	$t6,.L0001e28c
/*    1e180:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    1e184:	0fc25e42 */ 	jal	floor
/*    1e188:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*    1e18c:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*    1e190:	44803000 */ 	mtc1	$zero,$f6
/*    1e194:	00402025 */ 	or	$a0,$v0,$zero
/*    1e198:	00004025 */ 	or	$t0,$zero,$zero
/*    1e19c:	4604303e */ 	c.le.s	$f6,$f4
/*    1e1a0:	2447ffff */ 	addiu	$a3,$v0,-1
/*    1e1a4:	45000002 */ 	bc1f	.L0001e1b0
/*    1e1a8:	00000000 */ 	nop
/*    1e1ac:	24080001 */ 	addiu	$t0,$zero,0x1
.L0001e1b0:
/*    1e1b0:	11000003 */ 	beqz	$t0,.L0001e1c0
/*    1e1b4:	00000000 */ 	nop
/*    1e1b8:	10000001 */ 	b	.L0001e1c0
/*    1e1bc:	24470001 */ 	addiu	$a3,$v0,0x1
.L0001e1c0:
/*    1e1c0:	86050002 */ 	lh	$a1,0x2($s0)
/*    1e1c4:	8e06003c */ 	lw	$a2,0x3c($s0)
/*    1e1c8:	afa80020 */ 	sw	$t0,0x20($sp)
/*    1e1cc:	afa70024 */ 	sw	$a3,0x24($sp)
/*    1e1d0:	0c0074c8 */ 	jal	func0001d320
/*    1e1d4:	afa40028 */ 	sw	$a0,0x28($sp)
/*    1e1d8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    1e1dc:	a6020038 */ 	sh	$v0,0x38($s0)
/*    1e1e0:	86050002 */ 	lh	$a1,0x2($s0)
/*    1e1e4:	0c0074c8 */ 	jal	func0001d320
/*    1e1e8:	8e06003c */ 	lw	$a2,0x3c($s0)
/*    1e1ec:	8fa70024 */ 	lw	$a3,0x24($sp)
/*    1e1f0:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    1e1f4:	a602003a */ 	sh	$v0,0x3a($s0)
/*    1e1f8:	8604003a */ 	lh	$a0,0x3a($s0)
/*    1e1fc:	86030038 */ 	lh	$v1,0x38($s0)
/*    1e200:	14830007 */ 	bne	$a0,$v1,.L0001e220
/*    1e204:	00000000 */ 	nop
/*    1e208:	44835000 */ 	mtc1	$v1,$f10
/*    1e20c:	44804000 */ 	mtc1	$zero,$f8
/*    1e210:	46805420 */ 	cvt.s.w	$f16,$f10
/*    1e214:	e6080034 */ 	swc1	$f8,0x34($s0)
/*    1e218:	1000001b */ 	b	.L0001e288
/*    1e21c:	e6100030 */ 	swc1	$f16,0x30($s0)
.L0001e220:
/*    1e220:	1100000b */ 	beqz	$t0,.L0001e250
/*    1e224:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    1e228:	448f2000 */ 	mtc1	$t7,$f4
/*    1e22c:	44834000 */ 	mtc1	$v1,$f8
/*    1e230:	c7b20038 */ 	lwc1	$f18,0x38($sp)
/*    1e234:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    1e238:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    1e23c:	46069001 */ 	sub.s	$f0,$f18,$f6
/*    1e240:	46005400 */ 	add.s	$f16,$f10,$f0
/*    1e244:	e6000034 */ 	swc1	$f0,0x34($s0)
/*    1e248:	1000000f */ 	b	.L0001e288
/*    1e24c:	e6100030 */ 	swc1	$f16,0x30($s0)
.L0001e250:
/*    1e250:	44879000 */ 	mtc1	$a3,$f18
/*    1e254:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    1e258:	3c013f80 */ 	lui	$at,0x3f80
/*    1e25c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    1e260:	44811000 */ 	mtc1	$at,$f2
/*    1e264:	44845000 */ 	mtc1	$a0,$f10
/*    1e268:	00000000 */ 	nop
/*    1e26c:	46805420 */ 	cvt.s.w	$f16,$f10
/*    1e270:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    1e274:	46081001 */ 	sub.s	$f0,$f2,$f8
/*    1e278:	46001481 */ 	sub.s	$f18,$f2,$f0
/*    1e27c:	e6000034 */ 	swc1	$f0,0x34($s0)
/*    1e280:	46128100 */ 	add.s	$f4,$f16,$f18
/*    1e284:	e6040030 */ 	swc1	$f4,0x30($s0)
.L0001e288:
/*    1e288:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0001e28c:
/*    1e28c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    1e290:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    1e294:	03e00008 */ 	jr	$ra
/*    1e298:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001e29c
/*    1e29c:	3c018006 */ 	lui	$at,%hi(var8005efdc)
/*    1e2a0:	03e00008 */ 	jr	$ra
/*    1e2a4:	ac24efdc */ 	sw	$a0,%lo(var8005efdc)($at)
);

GLOBAL_ASM(
glabel func0001e2a8
/*    1e2a8:	3c028006 */ 	lui	$v0,%hi(var8005efdc)
/*    1e2ac:	03e00008 */ 	jr	$ra
/*    1e2b0:	8c42efdc */ 	lw	$v0,%lo(var8005efdc)($v0)
);

GLOBAL_ASM(
glabel func0001e2b4
.late_rodata
glabel var70054450
.word 0x40c907a9
.text
/*    1e2b4:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*    1e2b8:	afbf006c */ 	sw	$ra,0x6c($sp)
/*    1e2bc:	afb40068 */ 	sw	$s4,0x68($sp)
/*    1e2c0:	afb30064 */ 	sw	$s3,0x64($sp)
/*    1e2c4:	afb20060 */ 	sw	$s2,0x60($sp)
/*    1e2c8:	afb1005c */ 	sw	$s1,0x5c($sp)
/*    1e2cc:	afb00058 */ 	sw	$s0,0x58($sp)
/*    1e2d0:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*    1e2d4:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*    1e2d8:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*    1e2dc:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*    1e2e0:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*    1e2e4:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*    1e2e8:	afa60138 */ 	sw	$a2,0x138($sp)
/*    1e2ec:	afa7013c */ 	sw	$a3,0x13c($sp)
/*    1e2f0:	8c910020 */ 	lw	$s1,0x20($a0)
/*    1e2f4:	4485a000 */ 	mtc1	$a1,$f20
/*    1e2f8:	00808025 */ 	or	$s0,$a0,$zero
/*    1e2fc:	522002b9 */ 	beqzl	$s1,.L0001ede4
/*    1e300:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*    1e304:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    1e308:	24010001 */ 	addiu	$at,$zero,0x1
/*    1e30c:	8dc50000 */ 	lw	$a1,0x0($t6)
/*    1e310:	94a20000 */ 	lhu	$v0,0x0($a1)
/*    1e314:	304f00ff */ 	andi	$t7,$v0,0xff
/*    1e318:	55e102ac */ 	bnel	$t7,$at,.L0001edcc
/*    1e31c:	c7b40140 */ 	lwc1	$f20,0x140($sp)
/*    1e320:	0c006a87 */ 	jal	modelGetNodeData
/*    1e324:	8cb30004 */ 	lw	$s3,0x4($a1)
/*    1e328:	80580000 */ 	lb	$t8,0x0($v0)
/*    1e32c:	00409025 */ 	or	$s2,$v0,$zero
/*    1e330:	5700029e */ 	bnezl	$t8,.L0001edac
/*    1e334:	c7b40140 */ 	lwc1	$f20,0x140($sp)
/*    1e338:	96790000 */ 	lhu	$t9,0x0($s3)
/*    1e33c:	3c0b8006 */ 	lui	$t3,%hi(var8005efe0)
/*    1e340:	256befe0 */ 	addiu	$t3,$t3,%lo(var8005efe0)
/*    1e344:	afb90118 */ 	sw	$t9,0x118($sp)
/*    1e348:	8e080008 */ 	lw	$t0,0x8($s0)
/*    1e34c:	27aa00fc */ 	addiu	$t2,$sp,0xfc
/*    1e350:	4480d000 */ 	mtc1	$zero,$f26
/*    1e354:	8d090004 */ 	lw	$t1,0x4($t0)
/*    1e358:	afa90114 */ 	sw	$t1,0x114($sp)
/*    1e35c:	c6260088 */ 	lwc1	$f6,0x88($s1)
/*    1e360:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*    1e364:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1e368:	e7a80110 */ 	swc1	$f8,0x110($sp)
/*    1e36c:	8d610000 */ 	lw	$at,0x0($t3)
/*    1e370:	8d6e0004 */ 	lw	$t6,0x4($t3)
/*    1e374:	ad410000 */ 	sw	$at,0x0($t2)
/*    1e378:	8d610008 */ 	lw	$at,0x8($t3)
/*    1e37c:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*    1e380:	ad410008 */ 	sw	$at,0x8($t2)
/*    1e384:	c44a0034 */ 	lwc1	$f10,0x34($v0)
/*    1e388:	e7aa00e0 */ 	swc1	$f10,0xe0($sp)
/*    1e38c:	c4500038 */ 	lwc1	$f16,0x38($v0)
/*    1e390:	e7b000e4 */ 	swc1	$f16,0xe4($sp)
/*    1e394:	c452003c */ 	lwc1	$f18,0x3c($v0)
/*    1e398:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*    1e39c:	e7b200e8 */ 	swc1	$f18,0xe8($sp)
/*    1e3a0:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*    1e3a4:	c45e0030 */ 	lwc1	$f30,0x30($v0)
/*    1e3a8:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*    1e3ac:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*    1e3b0:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*    1e3b4:	c448002c */ 	lwc1	$f8,0x2c($v0)
/*    1e3b8:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*    1e3bc:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*    1e3c0:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*    1e3c4:	804f0001 */ 	lb	$t7,0x1($v0)
/*    1e3c8:	afaf00c8 */ 	sw	$t7,0xc8($sp)
/*    1e3cc:	c63c001c */ 	lwc1	$f28,0x1c($s1)
/*    1e3d0:	461ae03c */ 	c.lt.s	$f28,$f26
/*    1e3d4:	00000000 */ 	nop
/*    1e3d8:	45020003 */ 	bc1fl	.L0001e3e8
/*    1e3dc:	c6200040 */ 	lwc1	$f0,0x40($s1)
/*    1e3e0:	4600e707 */ 	neg.s	$f28,$f28
/*    1e3e4:	c6200040 */ 	lwc1	$f0,0x40($s1)
.L0001e3e8:
/*    1e3e8:	461a003c */ 	c.lt.s	$f0,$f26
/*    1e3ec:	00000000 */ 	nop
/*    1e3f0:	45020003 */ 	bc1fl	.L0001e400
/*    1e3f4:	4610a03e */ 	c.le.s	$f20,$f16
/*    1e3f8:	46000007 */ 	neg.s	$f0,$f0
/*    1e3fc:	4610a03e */ 	c.le.s	$f20,$f16
.L0001e400:
/*    1e400:	0000a025 */ 	or	$s4,$zero,$zero
/*    1e404:	45000002 */ 	bc1f	.L0001e410
/*    1e408:	00000000 */ 	nop
/*    1e40c:	24140001 */ 	addiu	$s4,$zero,0x1
.L0001e410:
/*    1e410:	5280000a */ 	beqzl	$s4,.L0001e43c
/*    1e414:	4600a306 */ 	mov.s	$f12,$f20
/*    1e418:	4600a306 */ 	mov.s	$f12,$f20
/*    1e41c:	0fc25e42 */ 	jal	floor
/*    1e420:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*    1e424:	24530001 */ 	addiu	$s3,$v0,0x1
/*    1e428:	0fc25e42 */ 	jal	floor
/*    1e42c:	c7ac0138 */ 	lwc1	$f12,0x138($sp)
/*    1e430:	10000009 */ 	b	.L0001e458
/*    1e434:	00403825 */ 	or	$a3,$v0,$zero
/*    1e438:	4600a306 */ 	mov.s	$f12,$f20
.L0001e43c:
/*    1e43c:	0fc25e7a */ 	jal	ceil
/*    1e440:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*    1e444:	2453ffff */ 	addiu	$s3,$v0,-1
/*    1e448:	0fc25e7a */ 	jal	ceil
/*    1e44c:	c7ac0138 */ 	lwc1	$f12,0x138($sp)
/*    1e450:	afa200ec */ 	sw	$v0,0xec($sp)
/*    1e454:	00403825 */ 	or	$a3,$v0,$zero
.L0001e458:
/*    1e458:	86390000 */ 	lh	$t9,0x0($s1)
/*    1e45c:	3c188006 */ 	lui	$t8,%hi(g_Anims)
/*    1e460:	8f18f00c */ 	lw	$t8,%lo(g_Anims)($t8)
/*    1e464:	00194080 */ 	sll	$t0,$t9,0x2
/*    1e468:	01194023 */ 	subu	$t0,$t0,$t9
/*    1e46c:	00084080 */ 	sll	$t0,$t0,0x2
/*    1e470:	03084821 */ 	addu	$t1,$t8,$t0
/*    1e474:	912d000b */ 	lbu	$t5,0xb($t1)
/*    1e478:	3c017005 */ 	lui	$at,%hi(var70054450)
/*    1e47c:	31ac0002 */ 	andi	$t4,$t5,0x2
/*    1e480:	11800067 */ 	beqz	$t4,.L0001e620
/*    1e484:	00000000 */ 	nop
/*    1e488:	0fc57222 */ 	jal	func0f15c888
/*    1e48c:	afa700ec */ 	sw	$a3,0xec($sp)
/*    1e490:	8faa00ec */ 	lw	$t2,0xec($sp)
/*    1e494:	862b0014 */ 	lh	$t3,0x14($s1)
/*    1e498:	46000506 */ 	mov.s	$f20,$f0
/*    1e49c:	01402025 */ 	or	$a0,$t2,$zero
/*    1e4a0:	114b005d */ 	beq	$t2,$t3,.L0001e618
/*    1e4a4:	00000000 */ 	nop
/*    1e4a8:	86250000 */ 	lh	$a1,0x0($s1)
/*    1e4ac:	0c0074c8 */ 	jal	func0001d320
/*    1e4b0:	8e260018 */ 	lw	$a2,0x18($s1)
/*    1e4b4:	a6220014 */ 	sh	$v0,0x14($s1)
/*    1e4b8:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    1e4bc:	00408025 */ 	or	$s0,$v0,$zero
/*    1e4c0:	8faf00ec */ 	lw	$t7,0xec($sp)
/*    1e4c4:	11c0000b */ 	beqz	$t6,.L0001e4f4
/*    1e4c8:	00000000 */ 	nop
/*    1e4cc:	86390016 */ 	lh	$t9,0x16($s1)
/*    1e4d0:	c7b200d0 */ 	lwc1	$f18,0xd0($sp)
/*    1e4d4:	15f90007 */ 	bne	$t7,$t9,.L0001e4f4
/*    1e4d8:	00000000 */ 	nop
/*    1e4dc:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*    1e4e0:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*    1e4e4:	e7b200e0 */ 	swc1	$f18,0xe0($sp)
/*    1e4e8:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*    1e4ec:	1000001f */ 	b	.L0001e56c
/*    1e4f0:	e7a600e8 */ 	swc1	$f6,0xe8($sp)
.L0001e4f4:
/*    1e4f4:	0c008f4e */ 	jal	func00023d38
/*    1e4f8:	86240000 */ 	lh	$a0,0x0($s1)
/*    1e4fc:	86240000 */ 	lh	$a0,0x0($s1)
/*    1e500:	0c008eac */ 	jal	func00023ab0
/*    1e504:	02002825 */ 	or	$a1,$s0,$zero
/*    1e508:	0c008f43 */ 	jal	func00023d0c
/*    1e50c:	305000ff */ 	andi	$s0,$v0,0xff
/*    1e510:	82250008 */ 	lb	$a1,0x8($s1)
/*    1e514:	86270000 */ 	lh	$a3,0x0($s1)
/*    1e518:	27b800a8 */ 	addiu	$t8,$sp,0xa8
/*    1e51c:	27a800fc */ 	addiu	$t0,$sp,0xfc
/*    1e520:	27a9009c */ 	addiu	$t1,$sp,0x9c
/*    1e524:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    1e528:	afa80018 */ 	sw	$t0,0x18($sp)
/*    1e52c:	afb80014 */ 	sw	$t8,0x14($sp)
/*    1e530:	afb00010 */ 	sw	$s0,0x10($sp)
/*    1e534:	8fa40118 */ 	lw	$a0,0x118($sp)
/*    1e538:	0c009014 */ 	jal	func00024050
/*    1e53c:	8fa60114 */ 	lw	$a2,0x114($sp)
/*    1e540:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e544:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*    1e548:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e54c:	46141202 */ 	mul.s	$f8,$f2,$f20
/*    1e550:	00000000 */ 	nop
/*    1e554:	46145402 */ 	mul.s	$f16,$f10,$f20
/*    1e558:	00000000 */ 	nop
/*    1e55c:	46146482 */ 	mul.s	$f18,$f12,$f20
/*    1e560:	e7a800e0 */ 	swc1	$f8,0xe0($sp)
/*    1e564:	e7b000e4 */ 	swc1	$f16,0xe4($sp)
/*    1e568:	e7b200e8 */ 	swc1	$f18,0xe8($sp)
.L0001e56c:
/*    1e56c:	12800004 */ 	beqz	$s4,.L0001e580
/*    1e570:	8fb300ec */ 	lw	$s3,0xec($sp)
/*    1e574:	8fb300ec */ 	lw	$s3,0xec($sp)
/*    1e578:	10000002 */ 	b	.L0001e584
/*    1e57c:	26730001 */ 	addiu	$s3,$s3,0x1
.L0001e580:
/*    1e580:	2673ffff */ 	addiu	$s3,$s3,-1
.L0001e584:
/*    1e584:	02602025 */ 	or	$a0,$s3,$zero
/*    1e588:	86250000 */ 	lh	$a1,0x0($s1)
/*    1e58c:	0c0074c8 */ 	jal	func0001d320
/*    1e590:	8e260018 */ 	lw	$a2,0x18($s1)
/*    1e594:	00408025 */ 	or	$s0,$v0,$zero
/*    1e598:	a6220016 */ 	sh	$v0,0x16($s1)
/*    1e59c:	0c008f4e */ 	jal	func00023d38
/*    1e5a0:	86240000 */ 	lh	$a0,0x0($s1)
/*    1e5a4:	86240000 */ 	lh	$a0,0x0($s1)
/*    1e5a8:	0c008eac */ 	jal	func00023ab0
/*    1e5ac:	02002825 */ 	or	$a1,$s0,$zero
/*    1e5b0:	0c008f43 */ 	jal	func00023d0c
/*    1e5b4:	305000ff */ 	andi	$s0,$v0,0xff
/*    1e5b8:	82250008 */ 	lb	$a1,0x8($s1)
/*    1e5bc:	86270000 */ 	lh	$a3,0x0($s1)
/*    1e5c0:	27ad00a8 */ 	addiu	$t5,$sp,0xa8
/*    1e5c4:	27ac00fc */ 	addiu	$t4,$sp,0xfc
/*    1e5c8:	27ab009c */ 	addiu	$t3,$sp,0x9c
/*    1e5cc:	afab001c */ 	sw	$t3,0x1c($sp)
/*    1e5d0:	afac0018 */ 	sw	$t4,0x18($sp)
/*    1e5d4:	afad0014 */ 	sw	$t5,0x14($sp)
/*    1e5d8:	afb00010 */ 	sw	$s0,0x10($sp)
/*    1e5dc:	8fa40118 */ 	lw	$a0,0x118($sp)
/*    1e5e0:	0c009014 */ 	jal	func00024050
/*    1e5e4:	8fa60114 */ 	lw	$a2,0x114($sp)
/*    1e5e8:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e5ec:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*    1e5f0:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e5f4:	46141102 */ 	mul.s	$f4,$f2,$f20
/*    1e5f8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    1e5fc:	afaa00c8 */ 	sw	$t2,0xc8($sp)
/*    1e600:	46143202 */ 	mul.s	$f8,$f6,$f20
/*    1e604:	00000000 */ 	nop
/*    1e608:	46146282 */ 	mul.s	$f10,$f12,$f20
/*    1e60c:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*    1e610:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*    1e614:	e7aa00d8 */ 	swc1	$f10,0xd8($sp)
.L0001e618:
/*    1e618:	10000147 */ 	b	.L0001eb38
/*    1e61c:	8fa700ec */ 	lw	$a3,0xec($sp)
.L0001e620:
/*    1e620:	c4384450 */ 	lwc1	$f24,%lo(var70054450)($at)
.L0001e624:
/*    1e624:	12800006 */ 	beqz	$s4,.L0001e640
/*    1e628:	0267082a */ 	slt	$at,$s3,$a3
/*    1e62c:	00f3082a */ 	slt	$at,$a3,$s3
/*    1e630:	50200006 */ 	beqzl	$at,.L0001e64c
/*    1e634:	86250000 */ 	lh	$a1,0x0($s1)
/*    1e638:	10000140 */ 	b	.L0001eb3c
/*    1e63c:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
.L0001e640:
/*    1e640:	5420013e */ 	bnezl	$at,.L0001eb3c
/*    1e644:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*    1e648:	86250000 */ 	lh	$a1,0x0($s1)
.L0001e64c:
/*    1e64c:	8e260018 */ 	lw	$a2,0x18($s1)
/*    1e650:	afa700ec */ 	sw	$a3,0xec($sp)
/*    1e654:	0c0074c8 */ 	jal	func0001d320
/*    1e658:	02602025 */ 	or	$a0,$s3,$zero
/*    1e65c:	a6220014 */ 	sh	$v0,0x14($s1)
/*    1e660:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    1e664:	00408025 */ 	or	$s0,$v0,$zero
/*    1e668:	8fa40118 */ 	lw	$a0,0x118($sp)
/*    1e66c:	11c0000e */ 	beqz	$t6,.L0001e6a8
/*    1e670:	27af00fc */ 	addiu	$t7,$sp,0xfc
/*    1e674:	c7b000d0 */ 	lwc1	$f16,0xd0($sp)
/*    1e678:	c7b200d4 */ 	lwc1	$f18,0xd4($sp)
/*    1e67c:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*    1e680:	e7b000e0 */ 	swc1	$f16,0xe0($sp)
/*    1e684:	e7b200e4 */ 	swc1	$f18,0xe4($sp)
/*    1e688:	e7a400e8 */ 	swc1	$f4,0xe8($sp)
/*    1e68c:	c6460018 */ 	lwc1	$f6,0x18($s2)
/*    1e690:	4606d032 */ 	c.eq.s	$f26,$f6
/*    1e694:	00000000 */ 	nop
/*    1e698:	4500004f */ 	bc1f	.L0001e7d8
/*    1e69c:	00000000 */ 	nop
/*    1e6a0:	1000004d */ 	b	.L0001e7d8
/*    1e6a4:	c7be00cc */ 	lwc1	$f30,0xcc($sp)
.L0001e6a8:
/*    1e6a8:	82250008 */ 	lb	$a1,0x8($s1)
/*    1e6ac:	86270000 */ 	lh	$a3,0x0($s1)
/*    1e6b0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    1e6b4:	afb00010 */ 	sw	$s0,0x10($sp)
/*    1e6b8:	8239000b */ 	lb	$t9,0xb($s1)
/*    1e6bc:	8fa60114 */ 	lw	$a2,0x114($sp)
/*    1e6c0:	0c0092d9 */ 	jal	func00024b64
/*    1e6c4:	afb90018 */ 	sw	$t9,0x18($sp)
/*    1e6c8:	3c013f80 */ 	lui	$at,0x3f80
/*    1e6cc:	44815000 */ 	mtc1	$at,$f10
/*    1e6d0:	c7a80110 */ 	lwc1	$f8,0x110($sp)
/*    1e6d4:	46000586 */ 	mov.s	$f22,$f0
/*    1e6d8:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e6dc:	460a4032 */ 	c.eq.s	$f8,$f10
/*    1e6e0:	c7b00100 */ 	lwc1	$f16,0x100($sp)
/*    1e6e4:	4503000a */ 	bc1tl	.L0001e710
/*    1e6e8:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e6ec:	46081082 */ 	mul.s	$f2,$f2,$f8
/*    1e6f0:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e6f4:	46088482 */ 	mul.s	$f18,$f16,$f8
/*    1e6f8:	00000000 */ 	nop
/*    1e6fc:	46086302 */ 	mul.s	$f12,$f12,$f8
/*    1e700:	e7a200fc */ 	swc1	$f2,0xfc($sp)
/*    1e704:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*    1e708:	e7ac0104 */ 	swc1	$f12,0x104($sp)
/*    1e70c:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
.L0001e710:
/*    1e710:	16800008 */ 	bnez	$s4,.L0001e734
/*    1e714:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e718:	4600d03c */ 	c.lt.s	$f26,$f0
/*    1e71c:	46001087 */ 	neg.s	$f2,$f2
/*    1e720:	46006307 */ 	neg.s	$f12,$f12
/*    1e724:	e7a200fc */ 	swc1	$f2,0xfc($sp)
/*    1e728:	45000002 */ 	bc1f	.L0001e734
/*    1e72c:	e7ac0104 */ 	swc1	$f12,0x104($sp)
/*    1e730:	4600c581 */ 	sub.s	$f22,$f24,$f0
.L0001e734:
/*    1e734:	8238000b */ 	lb	$t8,0xb($s1)
/*    1e738:	13000005 */ 	beqz	$t8,.L0001e750
/*    1e73c:	00000000 */ 	nop
/*    1e740:	c644000c */ 	lwc1	$f4,0xc($s2)
/*    1e744:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*    1e748:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    1e74c:	e7aa0100 */ 	swc1	$f10,0x100($sp)
.L0001e750:
/*    1e750:	0c0068f4 */ 	jal	cosf
/*    1e754:	c64c0014 */ 	lwc1	$f12,0x14($s2)
/*    1e758:	46000506 */ 	mov.s	$f20,$f0
/*    1e75c:	0c0068f7 */ 	jal	sinf
/*    1e760:	c64c0014 */ 	lwc1	$f12,0x14($s2)
/*    1e764:	c7b000fc */ 	lwc1	$f16,0xfc($sp)
/*    1e768:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*    1e76c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*    1e770:	46148482 */ 	mul.s	$f18,$f16,$f20
/*    1e774:	00000000 */ 	nop
/*    1e778:	46004102 */ 	mul.s	$f4,$f8,$f0
/*    1e77c:	46049180 */ 	add.s	$f6,$f18,$f4
/*    1e780:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*    1e784:	46065480 */ 	add.s	$f18,$f10,$f6
/*    1e788:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*    1e78c:	46008287 */ 	neg.s	$f10,$f16
/*    1e790:	e7b200e0 */ 	swc1	$f18,0xe0($sp)
/*    1e794:	46005182 */ 	mul.s	$f6,$f10,$f0
/*    1e798:	c7b000e8 */ 	lwc1	$f16,0xe8($sp)
/*    1e79c:	46144482 */ 	mul.s	$f18,$f8,$f20
/*    1e7a0:	46123100 */ 	add.s	$f4,$f6,$f18
/*    1e7a4:	46048280 */ 	add.s	$f10,$f16,$f4
/*    1e7a8:	e7aa00e8 */ 	swc1	$f10,0xe8($sp)
/*    1e7ac:	c6480018 */ 	lwc1	$f8,0x18($s2)
/*    1e7b0:	4608d032 */ 	c.eq.s	$f26,$f8
/*    1e7b4:	00000000 */ 	nop
/*    1e7b8:	45000007 */ 	bc1f	.L0001e7d8
/*    1e7bc:	00000000 */ 	nop
/*    1e7c0:	4616f780 */ 	add.s	$f30,$f30,$f22
/*    1e7c4:	461ec03e */ 	c.le.s	$f24,$f30
/*    1e7c8:	00000000 */ 	nop
/*    1e7cc:	45000002 */ 	bc1f	.L0001e7d8
/*    1e7d0:	00000000 */ 	nop
/*    1e7d4:	4618f781 */ 	sub.s	$f30,$f30,$f24
.L0001e7d8:
/*    1e7d8:	52800004 */ 	beqzl	$s4,.L0001e7ec
/*    1e7dc:	2673ffff */ 	addiu	$s3,$s3,-1
/*    1e7e0:	10000002 */ 	b	.L0001e7ec
/*    1e7e4:	26730001 */ 	addiu	$s3,$s3,0x1
/*    1e7e8:	2673ffff */ 	addiu	$s3,$s3,-1
.L0001e7ec:
/*    1e7ec:	02602025 */ 	or	$a0,$s3,$zero
/*    1e7f0:	86250000 */ 	lh	$a1,0x0($s1)
/*    1e7f4:	0c0074c8 */ 	jal	func0001d320
/*    1e7f8:	8e260018 */ 	lw	$a2,0x18($s1)
/*    1e7fc:	a6220016 */ 	sh	$v0,0x16($s1)
/*    1e800:	86290016 */ 	lh	$t1,0x16($s1)
/*    1e804:	86280014 */ 	lh	$t0,0x14($s1)
/*    1e808:	8fa60114 */ 	lw	$a2,0x114($sp)
/*    1e80c:	8fa40118 */ 	lw	$a0,0x118($sp)
/*    1e810:	110900c7 */ 	beq	$t0,$t1,.L0001eb30
/*    1e814:	27ad00fc */ 	addiu	$t5,$sp,0xfc
/*    1e818:	82250008 */ 	lb	$a1,0x8($s1)
/*    1e81c:	86270000 */ 	lh	$a3,0x0($s1)
/*    1e820:	afad0014 */ 	sw	$t5,0x14($sp)
/*    1e824:	afa20010 */ 	sw	$v0,0x10($sp)
/*    1e828:	822c000b */ 	lb	$t4,0xb($s1)
/*    1e82c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    1e830:	afab00c8 */ 	sw	$t3,0xc8($sp)
/*    1e834:	0c0092d9 */ 	jal	func00024b64
/*    1e838:	afac0018 */ 	sw	$t4,0x18($sp)
/*    1e83c:	3c013f80 */ 	lui	$at,0x3f80
/*    1e840:	44819000 */ 	mtc1	$at,$f18
/*    1e844:	c7a60110 */ 	lwc1	$f6,0x110($sp)
/*    1e848:	46000586 */ 	mov.s	$f22,$f0
/*    1e84c:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e850:	46123032 */ 	c.eq.s	$f6,$f18
/*    1e854:	c7b00100 */ 	lwc1	$f16,0x100($sp)
/*    1e858:	4503000a */ 	bc1tl	.L0001e884
/*    1e85c:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e860:	46061082 */ 	mul.s	$f2,$f2,$f6
/*    1e864:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e868:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    1e86c:	00000000 */ 	nop
/*    1e870:	46066302 */ 	mul.s	$f12,$f12,$f6
/*    1e874:	e7a200fc */ 	swc1	$f2,0xfc($sp)
/*    1e878:	e7a40100 */ 	swc1	$f4,0x100($sp)
/*    1e87c:	e7ac0104 */ 	swc1	$f12,0x104($sp)
/*    1e880:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
.L0001e884:
/*    1e884:	16800008 */ 	bnez	$s4,.L0001e8a8
/*    1e888:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e88c:	4600d03c */ 	c.lt.s	$f26,$f0
/*    1e890:	46001087 */ 	neg.s	$f2,$f2
/*    1e894:	46006307 */ 	neg.s	$f12,$f12
/*    1e898:	e7a200fc */ 	swc1	$f2,0xfc($sp)
/*    1e89c:	45000002 */ 	bc1f	.L0001e8a8
/*    1e8a0:	e7ac0104 */ 	swc1	$f12,0x104($sp)
/*    1e8a4:	4600c581 */ 	sub.s	$f22,$f24,$f0
.L0001e8a8:
/*    1e8a8:	822a000b */ 	lb	$t2,0xb($s1)
/*    1e8ac:	11400003 */ 	beqz	$t2,.L0001e8bc
/*    1e8b0:	00000000 */ 	nop
/*    1e8b4:	c64a0038 */ 	lwc1	$f10,0x38($s2)
/*    1e8b8:	e7aa0100 */ 	swc1	$f10,0x100($sp)
.L0001e8bc:
/*    1e8bc:	0c0068f4 */ 	jal	cosf
/*    1e8c0:	c64c0030 */ 	lwc1	$f12,0x30($s2)
/*    1e8c4:	46000506 */ 	mov.s	$f20,$f0
/*    1e8c8:	0c0068f7 */ 	jal	sinf
/*    1e8cc:	c64c0030 */ 	lwc1	$f12,0x30($s2)
/*    1e8d0:	3c0e8006 */ 	lui	$t6,%hi(var8005efdc)
/*    1e8d4:	8dceefdc */ 	lw	$t6,%lo(var8005efdc)($t6)
/*    1e8d8:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e8dc:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e8e0:	11c00056 */ 	beqz	$t6,.L0001ea3c
/*    1e8e4:	00000000 */ 	nop
/*    1e8e8:	862f0002 */ 	lh	$t7,0x2($s1)
/*    1e8ec:	11e00053 */ 	beqz	$t7,.L0001ea3c
/*    1e8f0:	00000000 */ 	nop
/*    1e8f4:	c7ac0104 */ 	lwc1	$f12,0x104($sp)
/*    1e8f8:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*    1e8fc:	461cd03c */ 	c.lt.s	$f26,$f28
/*    1e900:	46006202 */ 	mul.s	$f8,$f12,$f0
/*    1e904:	46001107 */ 	neg.s	$f4,$f2
/*    1e908:	3c013f00 */ 	lui	$at,0x3f00
/*    1e90c:	46141482 */ 	mul.s	$f18,$f2,$f20
/*    1e910:	00000000 */ 	nop
/*    1e914:	46146402 */ 	mul.s	$f16,$f12,$f20
/*    1e918:	00000000 */ 	nop
/*    1e91c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    1e920:	46124180 */ 	add.s	$f6,$f8,$f18
/*    1e924:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*    1e928:	460a8200 */ 	add.s	$f8,$f16,$f10
/*    1e92c:	45000028 */ 	bc1f	.L0001e9d0
/*    1e930:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*    1e934:	c6260058 */ 	lwc1	$f6,0x58($s1)
/*    1e938:	c6320074 */ 	lwc1	$f18,0x74($s1)
/*    1e93c:	c6220054 */ 	lwc1	$f2,0x54($s1)
/*    1e940:	4606e102 */ 	mul.s	$f4,$f28,$f6
/*    1e944:	46049403 */ 	div.s	$f16,$f18,$f4
/*    1e948:	46101001 */ 	sub.s	$f0,$f2,$f16
/*    1e94c:	461a003c */ 	c.lt.s	$f0,$f26
/*    1e950:	00000000 */ 	nop
/*    1e954:	45020003 */ 	bc1fl	.L0001e964
/*    1e958:	46001280 */ 	add.s	$f10,$f2,$f0
/*    1e95c:	4600d006 */ 	mov.s	$f0,$f26
/*    1e960:	46001280 */ 	add.s	$f10,$f2,$f0
.L0001e964:
/*    1e964:	c6460040 */ 	lwc1	$f6,0x40($s2)
/*    1e968:	c652004c */ 	lwc1	$f18,0x4c($s2)
/*    1e96c:	44814000 */ 	mtc1	$at,$f8
/*    1e970:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*    1e974:	46123101 */ 	sub.s	$f4,$f6,$f18
/*    1e978:	46085002 */ 	mul.s	$f0,$f10,$f8
/*    1e97c:	00000000 */ 	nop
/*    1e980:	46102282 */ 	mul.s	$f10,$f4,$f16
/*    1e984:	461c5203 */ 	div.s	$f8,$f10,$f28
/*    1e988:	e7a80090 */ 	swc1	$f8,0x90($sp)
/*    1e98c:	c6520054 */ 	lwc1	$f18,0x54($s2)
/*    1e990:	c6460048 */ 	lwc1	$f6,0x48($s2)
/*    1e994:	46123101 */ 	sub.s	$f4,$f6,$f18
/*    1e998:	c7b200d0 */ 	lwc1	$f18,0xd0($sp)
/*    1e99c:	46102282 */ 	mul.s	$f10,$f4,$f16
/*    1e9a0:	46124101 */ 	sub.s	$f4,$f8,$f18
/*    1e9a4:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*    1e9a8:	46002402 */ 	mul.s	$f16,$f4,$f0
/*    1e9ac:	461c5183 */ 	div.s	$f6,$f10,$f28
/*    1e9b0:	46109280 */ 	add.s	$f10,$f18,$f16
/*    1e9b4:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*    1e9b8:	46083101 */ 	sub.s	$f4,$f6,$f8
/*    1e9bc:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*    1e9c0:	46002482 */ 	mul.s	$f18,$f4,$f0
/*    1e9c4:	46124400 */ 	add.s	$f16,$f8,$f18
/*    1e9c8:	10000011 */ 	b	.L0001ea10
/*    1e9cc:	e7b000d8 */ 	swc1	$f16,0xd8($sp)
.L0001e9d0:
/*    1e9d0:	c64a0040 */ 	lwc1	$f10,0x40($s2)
/*    1e9d4:	c646004c */ 	lwc1	$f6,0x4c($s2)
/*    1e9d8:	c6280054 */ 	lwc1	$f8,0x54($s1)
/*    1e9dc:	c7b000d0 */ 	lwc1	$f16,0xd0($sp)
/*    1e9e0:	46065101 */ 	sub.s	$f4,$f10,$f6
/*    1e9e4:	46082482 */ 	mul.s	$f18,$f4,$f8
/*    1e9e8:	46128280 */ 	add.s	$f10,$f16,$f18
/*    1e9ec:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*    1e9f0:	c6440054 */ 	lwc1	$f4,0x54($s2)
/*    1e9f4:	c6460048 */ 	lwc1	$f6,0x48($s2)
/*    1e9f8:	c6300054 */ 	lwc1	$f16,0x54($s1)
/*    1e9fc:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*    1ea00:	46043201 */ 	sub.s	$f8,$f6,$f4
/*    1ea04:	46104482 */ 	mul.s	$f18,$f8,$f16
/*    1ea08:	46125180 */ 	add.s	$f6,$f10,$f18
/*    1ea0c:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.L0001ea10:
/*    1ea10:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*    1ea14:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*    1ea18:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*    1ea1c:	c7b200e8 */ 	lwc1	$f18,0xe8($sp)
/*    1ea20:	46082400 */ 	add.s	$f16,$f4,$f8
/*    1ea24:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*    1ea28:	46125180 */ 	add.s	$f6,$f10,$f18
/*    1ea2c:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*    1ea30:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*    1ea34:	1000000f */ 	b	.L0001ea74
/*    1ea38:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.L0001ea3c:
/*    1ea3c:	46141402 */ 	mul.s	$f16,$f2,$f20
/*    1ea40:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*    1ea44:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*    1ea48:	46006482 */ 	mul.s	$f18,$f12,$f0
/*    1ea4c:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*    1ea50:	46104280 */ 	add.s	$f10,$f8,$f16
/*    1ea54:	46001402 */ 	mul.s	$f16,$f2,$f0
/*    1ea58:	c7a800e8 */ 	lwc1	$f8,0xe8($sp)
/*    1ea5c:	460a9180 */ 	add.s	$f6,$f18,$f10
/*    1ea60:	46146282 */ 	mul.s	$f10,$f12,$f20
/*    1ea64:	46104481 */ 	sub.s	$f18,$f8,$f16
/*    1ea68:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*    1ea6c:	46125180 */ 	add.s	$f6,$f10,$f18
/*    1ea70:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.L0001ea74:
/*    1ea74:	c640005c */ 	lwc1	$f0,0x5c($s2)
/*    1ea78:	4600d03c */ 	c.lt.s	$f26,$f0
/*    1ea7c:	00000000 */ 	nop
/*    1ea80:	45020020 */ 	bc1fl	.L0001eb04
/*    1ea84:	c6520018 */ 	lwc1	$f18,0x18($s2)
/*    1ea88:	461cd03c */ 	c.lt.s	$f26,$f28
/*    1ea8c:	3c013f80 */ 	lui	$at,0x3f80
/*    1ea90:	4502001c */ 	bc1fl	.L0001eb04
/*    1ea94:	c6520018 */ 	lwc1	$f18,0x18($s2)
/*    1ea98:	44812000 */ 	mtc1	$at,$f4
/*    1ea9c:	00000000 */ 	nop
/*    1eaa0:	461c2083 */ 	div.s	$f2,$f4,$f28
/*    1eaa4:	4602003c */ 	c.lt.s	$f0,$f2
/*    1eaa8:	46001306 */ 	mov.s	$f12,$f2
/*    1eaac:	45020005 */ 	bc1fl	.L0001eac4
/*    1eab0:	46020201 */ 	sub.s	$f8,$f0,$f2
/*    1eab4:	46000306 */ 	mov.s	$f12,$f0
/*    1eab8:	10000003 */ 	b	.L0001eac8
/*    1eabc:	e65a005c */ 	swc1	$f26,0x5c($s2)
/*    1eac0:	46020201 */ 	sub.s	$f8,$f0,$f2
.L0001eac4:
/*    1eac4:	e648005c */ 	swc1	$f8,0x5c($s2)
.L0001eac8:
/*    1eac8:	c6500058 */ 	lwc1	$f16,0x58($s2)
/*    1eacc:	460c8282 */ 	mul.s	$f10,$f16,$f12
/*    1ead0:	460ab580 */ 	add.s	$f22,$f22,$f10
/*    1ead4:	461ab03c */ 	c.lt.s	$f22,$f26
/*    1ead8:	00000000 */ 	nop
/*    1eadc:	45020004 */ 	bc1fl	.L0001eaf0
/*    1eae0:	4616c03e */ 	c.le.s	$f24,$f22
/*    1eae4:	10000006 */ 	b	.L0001eb00
/*    1eae8:	4618b580 */ 	add.s	$f22,$f22,$f24
/*    1eaec:	4616c03e */ 	c.le.s	$f24,$f22
.L0001eaf0:
/*    1eaf0:	00000000 */ 	nop
/*    1eaf4:	45020003 */ 	bc1fl	.L0001eb04
/*    1eaf8:	c6520018 */ 	lwc1	$f18,0x18($s2)
/*    1eafc:	4618b581 */ 	sub.s	$f22,$f22,$f24
.L0001eb00:
/*    1eb00:	c6520018 */ 	lwc1	$f18,0x18($s2)
.L0001eb04:
/*    1eb04:	4612d032 */ 	c.eq.s	$f26,$f18
/*    1eb08:	00000000 */ 	nop
/*    1eb0c:	45000008 */ 	bc1f	.L0001eb30
/*    1eb10:	00000000 */ 	nop
/*    1eb14:	4616f000 */ 	add.s	$f0,$f30,$f22
/*    1eb18:	4600c03e */ 	c.le.s	$f24,$f0
/*    1eb1c:	e7a000cc */ 	swc1	$f0,0xcc($sp)
/*    1eb20:	45000003 */ 	bc1f	.L0001eb30
/*    1eb24:	00000000 */ 	nop
/*    1eb28:	46180181 */ 	sub.s	$f6,$f0,$f24
/*    1eb2c:	e7a600cc */ 	swc1	$f6,0xcc($sp)
.L0001eb30:
/*    1eb30:	1000febc */ 	b	.L0001e624
/*    1eb34:	8fa700ec */ 	lw	$a3,0xec($sp)
.L0001eb38:
/*    1eb38:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
.L0001eb3c:
/*    1eb3c:	e6440034 */ 	swc1	$f4,0x34($s2)
/*    1eb40:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*    1eb44:	e6480038 */ 	swc1	$f8,0x38($s2)
/*    1eb48:	c7b000e8 */ 	lwc1	$f16,0xe8($sp)
/*    1eb4c:	e65e0030 */ 	swc1	$f30,0x30($s2)
/*    1eb50:	e650003c */ 	swc1	$f16,0x3c($s2)
/*    1eb54:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*    1eb58:	e64a0024 */ 	swc1	$f10,0x24($s2)
/*    1eb5c:	c7b200d4 */ 	lwc1	$f18,0xd4($sp)
/*    1eb60:	e6520028 */ 	swc1	$f18,0x28($s2)
/*    1eb64:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*    1eb68:	e646002c */ 	swc1	$f6,0x2c($s2)
/*    1eb6c:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*    1eb70:	e6440020 */ 	swc1	$f4,0x20($s2)
/*    1eb74:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    1eb78:	a2590001 */ 	sb	$t9,0x1($s2)
/*    1eb7c:	86220014 */ 	lh	$v0,0x14($s1)
/*    1eb80:	86230016 */ 	lh	$v1,0x16($s1)
/*    1eb84:	14620006 */ 	bne	$v1,$v0,.L0001eba0
/*    1eb88:	00000000 */ 	nop
/*    1eb8c:	44824000 */ 	mtc1	$v0,$f8
/*    1eb90:	e63a0010 */ 	swc1	$f26,0x10($s1)
/*    1eb94:	46804420 */ 	cvt.s.w	$f16,$f8
/*    1eb98:	10000019 */ 	b	.L0001ec00
/*    1eb9c:	e630000c */ 	swc1	$f16,0xc($s1)
.L0001eba0:
/*    1eba0:	5280000c */ 	beqzl	$s4,.L0001ebd4
/*    1eba4:	44879000 */ 	mtc1	$a3,$f18
/*    1eba8:	44879000 */ 	mtc1	$a3,$f18
/*    1ebac:	44822000 */ 	mtc1	$v0,$f4
/*    1ebb0:	c7aa0138 */ 	lwc1	$f10,0x138($sp)
/*    1ebb4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    1ebb8:	46802220 */ 	cvt.s.w	$f8,$f4
/*    1ebbc:	46065001 */ 	sub.s	$f0,$f10,$f6
/*    1ebc0:	46004400 */ 	add.s	$f16,$f8,$f0
/*    1ebc4:	e6200010 */ 	swc1	$f0,0x10($s1)
/*    1ebc8:	1000000d */ 	b	.L0001ec00
/*    1ebcc:	e630000c */ 	swc1	$f16,0xc($s1)
/*    1ebd0:	44879000 */ 	mtc1	$a3,$f18
.L0001ebd4:
/*    1ebd4:	c7a60138 */ 	lwc1	$f6,0x138($sp)
/*    1ebd8:	44832000 */ 	mtc1	$v1,$f4
/*    1ebdc:	468092a0 */ 	cvt.s.w	$f10,$f18
/*    1ebe0:	3c013f80 */ 	lui	$at,0x3f80
/*    1ebe4:	44818000 */ 	mtc1	$at,$f16
/*    1ebe8:	46802220 */ 	cvt.s.w	$f8,$f4
/*    1ebec:	46065001 */ 	sub.s	$f0,$f10,$f6
/*    1ebf0:	46008481 */ 	sub.s	$f18,$f16,$f0
/*    1ebf4:	e6200010 */ 	swc1	$f0,0x10($s1)
/*    1ebf8:	46124280 */ 	add.s	$f10,$f8,$f18
/*    1ebfc:	e62a000c */ 	swc1	$f10,0xc($s1)
.L0001ec00:
/*    1ec00:	86380002 */ 	lh	$t8,0x2($s1)
/*    1ec04:	13000066 */ 	beqz	$t8,.L0001eda0
/*    1ec08:	00000000 */ 	nop
/*    1ec0c:	86290000 */ 	lh	$t1,0x0($s1)
/*    1ec10:	3c088006 */ 	lui	$t0,%hi(g_Anims)
/*    1ec14:	8d08f00c */ 	lw	$t0,%lo(g_Anims)($t0)
/*    1ec18:	00096880 */ 	sll	$t5,$t1,0x2
/*    1ec1c:	01a96823 */ 	subu	$t5,$t5,$t1
/*    1ec20:	000d6880 */ 	sll	$t5,$t5,0x2
/*    1ec24:	010d6021 */ 	addu	$t4,$t0,$t5
/*    1ec28:	918b000b */ 	lbu	$t3,0xb($t4)
/*    1ec2c:	316a0002 */ 	andi	$t2,$t3,0x2
/*    1ec30:	1540005b */ 	bnez	$t2,.L0001eda0
/*    1ec34:	00000000 */ 	nop
/*    1ec38:	0fc25e42 */ 	jal	floor
/*    1ec3c:	c7ac013c */ 	lwc1	$f12,0x13c($sp)
/*    1ec40:	c7b40140 */ 	lwc1	$f20,0x140($sp)
/*    1ec44:	00408025 */ 	or	$s0,$v0,$zero
/*    1ec48:	0fc25e42 */ 	jal	floor
/*    1ec4c:	4600a306 */ 	mov.s	$f12,$f20
/*    1ec50:	12800004 */ 	beqz	$s4,.L0001ec64
/*    1ec54:	00409825 */ 	or	$s3,$v0,$zero
/*    1ec58:	0202082a */ 	slt	$at,$s0,$v0
/*    1ec5c:	54200006 */ 	bnezl	$at,.L0001ec78
/*    1ec60:	824e0002 */ 	lb	$t6,0x2($s2)
.L0001ec64:
/*    1ec64:	16800032 */ 	bnez	$s4,.L0001ed30
/*    1ec68:	0050082a */ 	slt	$at,$v0,$s0
/*    1ec6c:	50200031 */ 	beqzl	$at,.L0001ed34
/*    1ec70:	3c013f80 */ 	lui	$at,0x3f80
/*    1ec74:	824e0002 */ 	lb	$t6,0x2($s2)
.L0001ec78:
/*    1ec78:	02602025 */ 	or	$a0,$s3,$zero
/*    1ec7c:	51c00005 */ 	beqzl	$t6,.L0001ec94
/*    1ec80:	c6440038 */ 	lwc1	$f4,0x38($s2)
/*    1ec84:	c6460044 */ 	lwc1	$f6,0x44($s2)
/*    1ec88:	10000003 */ 	b	.L0001ec98
/*    1ec8c:	e6460050 */ 	swc1	$f6,0x50($s2)
/*    1ec90:	c6440038 */ 	lwc1	$f4,0x38($s2)
.L0001ec94:
/*    1ec94:	e6440050 */ 	swc1	$f4,0x50($s2)
.L0001ec98:
/*    1ec98:	86250002 */ 	lh	$a1,0x2($s1)
/*    1ec9c:	0c0074c8 */ 	jal	func0001d320
/*    1eca0:	8e26003c */ 	lw	$a2,0x3c($s1)
/*    1eca4:	a6220038 */ 	sh	$v0,0x38($s1)
/*    1eca8:	26640001 */ 	addiu	$a0,$s3,0x1
/*    1ecac:	86250002 */ 	lh	$a1,0x2($s1)
/*    1ecb0:	0c0074c8 */ 	jal	func0001d320
/*    1ecb4:	8e26003c */ 	lw	$a2,0x3c($s1)
/*    1ecb8:	a622003a */ 	sh	$v0,0x3a($s1)
/*    1ecbc:	82250009 */ 	lb	$a1,0x9($s1)
/*    1ecc0:	86270002 */ 	lh	$a3,0x2($s1)
/*    1ecc4:	27af00fc */ 	addiu	$t7,$sp,0xfc
/*    1ecc8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    1eccc:	afa20010 */ 	sw	$v0,0x10($sp)
/*    1ecd0:	8239000b */ 	lb	$t9,0xb($s1)
/*    1ecd4:	8fa60114 */ 	lw	$a2,0x114($sp)
/*    1ecd8:	8fa40118 */ 	lw	$a0,0x118($sp)
/*    1ecdc:	0c0092d9 */ 	jal	func00024b64
/*    1ece0:	afb90018 */ 	sw	$t9,0x18($sp)
/*    1ece4:	3c013f80 */ 	lui	$at,0x3f80
/*    1ece8:	44816000 */ 	mtc1	$at,$f12
/*    1ecec:	c7a20110 */ 	lwc1	$f2,0x110($sp)
/*    1ecf0:	c7b00100 */ 	lwc1	$f16,0x100($sp)
/*    1ecf4:	460c1032 */ 	c.eq.s	$f2,$f12
/*    1ecf8:	00000000 */ 	nop
/*    1ecfc:	45030004 */ 	bc1tl	.L0001ed10
/*    1ed00:	8238000b */ 	lb	$t8,0xb($s1)
/*    1ed04:	46028202 */ 	mul.s	$f8,$f16,$f2
/*    1ed08:	e7a80100 */ 	swc1	$f8,0x100($sp)
/*    1ed0c:	8238000b */ 	lb	$t8,0xb($s1)
.L0001ed10:
/*    1ed10:	53000004 */ 	beqzl	$t8,.L0001ed24
/*    1ed14:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*    1ed18:	c6520050 */ 	lwc1	$f18,0x50($s2)
/*    1ed1c:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*    1ed20:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
.L0001ed24:
/*    1ed24:	24090001 */ 	addiu	$t1,$zero,0x1
/*    1ed28:	a2490002 */ 	sb	$t1,0x2($s2)
/*    1ed2c:	e64a0044 */ 	swc1	$f10,0x44($s2)
.L0001ed30:
/*    1ed30:	3c013f80 */ 	lui	$at,0x3f80
.L0001ed34:
/*    1ed34:	44816000 */ 	mtc1	$at,$f12
/*    1ed38:	5280000d */ 	beqzl	$s4,.L0001ed70
/*    1ed3c:	44935000 */ 	mtc1	$s3,$f10
/*    1ed40:	44933000 */ 	mtc1	$s3,$f6
/*    1ed44:	86280038 */ 	lh	$t0,0x38($s1)
/*    1ed48:	46803120 */ 	cvt.s.w	$f4,$f6
/*    1ed4c:	44888000 */ 	mtc1	$t0,$f16
/*    1ed50:	00000000 */ 	nop
/*    1ed54:	46808220 */ 	cvt.s.w	$f8,$f16
/*    1ed58:	4604a001 */ 	sub.s	$f0,$f20,$f4
/*    1ed5c:	46004480 */ 	add.s	$f18,$f8,$f0
/*    1ed60:	e6200034 */ 	swc1	$f0,0x34($s1)
/*    1ed64:	1000001e */ 	b	.L0001ede0
/*    1ed68:	e6320030 */ 	swc1	$f18,0x30($s1)
/*    1ed6c:	44935000 */ 	mtc1	$s3,$f10
.L0001ed70:
/*    1ed70:	862d003a */ 	lh	$t5,0x3a($s1)
/*    1ed74:	468051a0 */ 	cvt.s.w	$f6,$f10
/*    1ed78:	448d8000 */ 	mtc1	$t5,$f16
/*    1ed7c:	00000000 */ 	nop
/*    1ed80:	46808220 */ 	cvt.s.w	$f8,$f16
/*    1ed84:	4606a101 */ 	sub.s	$f4,$f20,$f6
/*    1ed88:	46046001 */ 	sub.s	$f0,$f12,$f4
/*    1ed8c:	46006481 */ 	sub.s	$f18,$f12,$f0
/*    1ed90:	e6200034 */ 	swc1	$f0,0x34($s1)
/*    1ed94:	46124280 */ 	add.s	$f10,$f8,$f18
/*    1ed98:	10000011 */ 	b	.L0001ede0
/*    1ed9c:	e62a0030 */ 	swc1	$f10,0x30($s1)
.L0001eda0:
/*    1eda0:	1000000f */ 	b	.L0001ede0
/*    1eda4:	a2400002 */ 	sb	$zero,0x2($s2)
/*    1eda8:	c7b40140 */ 	lwc1	$f20,0x140($sp)
.L0001edac:
/*    1edac:	02002025 */ 	or	$a0,$s0,$zero
/*    1edb0:	8fa50138 */ 	lw	$a1,0x138($sp)
/*    1edb4:	4406a000 */ 	mfc1	$a2,$f20
/*    1edb8:	0c007853 */ 	jal	func0001e14c
/*    1edbc:	00000000 */ 	nop
/*    1edc0:	10000008 */ 	b	.L0001ede4
/*    1edc4:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*    1edc8:	c7b40140 */ 	lwc1	$f20,0x140($sp)
.L0001edcc:
/*    1edcc:	02002025 */ 	or	$a0,$s0,$zero
/*    1edd0:	8fa50138 */ 	lw	$a1,0x138($sp)
/*    1edd4:	4406a000 */ 	mfc1	$a2,$f20
/*    1edd8:	0c007853 */ 	jal	func0001e14c
/*    1eddc:	00000000 */ 	nop
.L0001ede0:
/*    1ede0:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0001ede4:
/*    1ede4:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*    1ede8:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*    1edec:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*    1edf0:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*    1edf4:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*    1edf8:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*    1edfc:	8fb00058 */ 	lw	$s0,0x58($sp)
/*    1ee00:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*    1ee04:	8fb20060 */ 	lw	$s2,0x60($sp)
/*    1ee08:	8fb30064 */ 	lw	$s3,0x64($sp)
/*    1ee0c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*    1ee10:	03e00008 */ 	jr	$ra
/*    1ee14:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0001ee18
/*    1ee18:	27bdff70 */ 	addiu	$sp,$sp,-144
/*    1ee1c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*    1ee20:	afb20058 */ 	sw	$s2,0x58($sp)
/*    1ee24:	afb10054 */ 	sw	$s1,0x54($sp)
/*    1ee28:	afb00050 */ 	sw	$s0,0x50($sp)
/*    1ee2c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*    1ee30:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*    1ee34:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*    1ee38:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*    1ee3c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*    1ee40:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*    1ee44:	afa60098 */ 	sw	$a2,0x98($sp)
/*    1ee48:	8c900020 */ 	lw	$s0,0x20($a0)
/*    1ee4c:	00a08825 */ 	or	$s1,$a1,$zero
/*    1ee50:	00809025 */ 	or	$s2,$a0,$zero
/*    1ee54:	52000124 */ 	beqzl	$s0,.L0001f2e8
/*    1ee58:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    1ee5c:	58a00122 */ 	blezl	$a1,.L0001f2e8
/*    1ee60:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    1ee64:	c610000c */ 	lwc1	$f16,0xc($s0)
/*    1ee68:	18a000fb */ 	blez	$a1,.L0001f258
/*    1ee6c:	c6120030 */ 	lwc1	$f18,0x30($s0)
/*    1ee70:	4480b000 */ 	mtc1	$zero,$f22
/*    1ee74:	00000000 */ 	nop
/*    1ee78:	c6020080 */ 	lwc1	$f2,0x80($s0)
.L0001ee7c:
/*    1ee7c:	3c013e80 */ 	lui	$at,0x3e80
/*    1ee80:	4602b03c */ 	c.lt.s	$f22,$f2
/*    1ee84:	00000000 */ 	nop
/*    1ee88:	45020016 */ 	bc1fl	.L0001eee4
/*    1ee8c:	c6040058 */ 	lwc1	$f4,0x58($s0)
/*    1ee90:	4481a000 */ 	mtc1	$at,$f20
/*    1ee94:	c6040084 */ 	lwc1	$f4,0x84($s0)
/*    1ee98:	46142180 */ 	add.s	$f6,$f4,$f20
/*    1ee9c:	e6060084 */ 	swc1	$f6,0x84($s0)
/*    1eea0:	c60c0084 */ 	lwc1	$f12,0x84($s0)
/*    1eea4:	4602603c */ 	c.lt.s	$f12,$f2
/*    1eea8:	00000000 */ 	nop
/*    1eeac:	4502000a */ 	bc1fl	.L0001eed8
/*    1eeb0:	c60a0078 */ 	lwc1	$f10,0x78($s0)
/*    1eeb4:	c600007c */ 	lwc1	$f0,0x7c($s0)
/*    1eeb8:	c6080078 */ 	lwc1	$f8,0x78($s0)
/*    1eebc:	46004281 */ 	sub.s	$f10,$f8,$f0
/*    1eec0:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*    1eec4:	46022183 */ 	div.s	$f6,$f4,$f2
/*    1eec8:	46060200 */ 	add.s	$f8,$f0,$f6
/*    1eecc:	10000004 */ 	b	.L0001eee0
/*    1eed0:	e6080074 */ 	swc1	$f8,0x74($s0)
/*    1eed4:	c60a0078 */ 	lwc1	$f10,0x78($s0)
.L0001eed8:
/*    1eed8:	e6160080 */ 	swc1	$f22,0x80($s0)
/*    1eedc:	e60a0074 */ 	swc1	$f10,0x74($s0)
.L0001eee0:
/*    1eee0:	c6040058 */ 	lwc1	$f4,0x58($s0)
.L0001eee4:
/*    1eee4:	3c013e80 */ 	lui	$at,0x3e80
/*    1eee8:	4481a000 */ 	mtc1	$at,$f20
/*    1eeec:	4604b03c */ 	c.lt.s	$f22,$f4
/*    1eef0:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1eef4:	4502001e */ 	bc1fl	.L0001ef70
/*    1eef8:	c60c0028 */ 	lwc1	$f12,0x28($s0)
/*    1eefc:	46141202 */ 	mul.s	$f8,$f2,$f20
/*    1ef00:	c606005c */ 	lwc1	$f6,0x5c($s0)
/*    1ef04:	3c013f80 */ 	lui	$at,0x3f80
/*    1ef08:	46083280 */ 	add.s	$f10,$f6,$f8
/*    1ef0c:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*    1ef10:	c60c005c */ 	lwc1	$f12,0x5c($s0)
/*    1ef14:	460cb032 */ 	c.eq.s	$f22,$f12
/*    1ef18:	00000000 */ 	nop
/*    1ef1c:	45020006 */ 	bc1fl	.L0001ef38
/*    1ef20:	c6000058 */ 	lwc1	$f0,0x58($s0)
/*    1ef24:	44812000 */ 	mtc1	$at,$f4
/*    1ef28:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1ef2c:	1000000f */ 	b	.L0001ef6c
/*    1ef30:	e6040054 */ 	swc1	$f4,0x54($s0)
/*    1ef34:	c6000058 */ 	lwc1	$f0,0x58($s0)
.L0001ef38:
/*    1ef38:	4600603c */ 	c.lt.s	$f12,$f0
/*    1ef3c:	00000000 */ 	nop
/*    1ef40:	45020007 */ 	bc1fl	.L0001ef60
/*    1ef44:	e6160058 */ 	swc1	$f22,0x58($s0)
/*    1ef48:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*    1ef4c:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1ef50:	46003203 */ 	div.s	$f8,$f6,$f0
/*    1ef54:	10000005 */ 	b	.L0001ef6c
/*    1ef58:	e6080054 */ 	swc1	$f8,0x54($s0)
/*    1ef5c:	e6160058 */ 	swc1	$f22,0x58($s0)
.L0001ef60:
/*    1ef60:	e6160054 */ 	swc1	$f22,0x54($s0)
/*    1ef64:	a6000002 */ 	sh	$zero,0x2($s0)
/*    1ef68:	c6020074 */ 	lwc1	$f2,0x74($s0)
.L0001ef6c:
/*    1ef6c:	c60c0028 */ 	lwc1	$f12,0x28($s0)
.L0001ef70:
/*    1ef70:	460cb03c */ 	c.lt.s	$f22,$f12
/*    1ef74:	00000000 */ 	nop
/*    1ef78:	45020018 */ 	bc1fl	.L0001efdc
/*    1ef7c:	c61a001c */ 	lwc1	$f26,0x1c($s0)
/*    1ef80:	46141102 */ 	mul.s	$f4,$f2,$f20
/*    1ef84:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*    1ef88:	46045180 */ 	add.s	$f6,$f10,$f4
/*    1ef8c:	e606002c */ 	swc1	$f6,0x2c($s0)
/*    1ef90:	c60e002c */ 	lwc1	$f14,0x2c($s0)
/*    1ef94:	460c703c */ 	c.lt.s	$f14,$f12
/*    1ef98:	00000000 */ 	nop
/*    1ef9c:	4502000b */ 	bc1fl	.L0001efcc
/*    1efa0:	c60a0020 */ 	lwc1	$f10,0x20($s0)
/*    1efa4:	c6000024 */ 	lwc1	$f0,0x24($s0)
/*    1efa8:	c6080020 */ 	lwc1	$f8,0x20($s0)
/*    1efac:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1efb0:	46004281 */ 	sub.s	$f10,$f8,$f0
/*    1efb4:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*    1efb8:	460c2183 */ 	div.s	$f6,$f4,$f12
/*    1efbc:	46060200 */ 	add.s	$f8,$f0,$f6
/*    1efc0:	10000005 */ 	b	.L0001efd8
/*    1efc4:	e608001c */ 	swc1	$f8,0x1c($s0)
/*    1efc8:	c60a0020 */ 	lwc1	$f10,0x20($s0)
.L0001efcc:
/*    1efcc:	e6160028 */ 	swc1	$f22,0x28($s0)
/*    1efd0:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1efd4:	e60a001c */ 	swc1	$f10,0x1c($s0)
.L0001efd8:
/*    1efd8:	c61a001c */ 	lwc1	$f26,0x1c($s0)
.L0001efdc:
/*    1efdc:	3c013e80 */ 	lui	$at,0x3e80
/*    1efe0:	44813000 */ 	mtc1	$at,$f6
/*    1efe4:	461a1102 */ 	mul.s	$f4,$f2,$f26
/*    1efe8:	860e0002 */ 	lh	$t6,0x2($s0)
/*    1efec:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    1eff0:	11c00025 */ 	beqz	$t6,.L0001f088
/*    1eff4:	46088400 */ 	add.s	$f16,$f16,$f8
/*    1eff8:	c60c004c */ 	lwc1	$f12,0x4c($s0)
/*    1effc:	3c013e80 */ 	lui	$at,0x3e80
/*    1f000:	460cb03c */ 	c.lt.s	$f22,$f12
/*    1f004:	00000000 */ 	nop
/*    1f008:	45020019 */ 	bc1fl	.L0001f070
/*    1f00c:	c6000040 */ 	lwc1	$f0,0x40($s0)
/*    1f010:	44812000 */ 	mtc1	$at,$f4
/*    1f014:	c60a0050 */ 	lwc1	$f10,0x50($s0)
/*    1f018:	46041182 */ 	mul.s	$f6,$f2,$f4
/*    1f01c:	46065200 */ 	add.s	$f8,$f10,$f6
/*    1f020:	e6080050 */ 	swc1	$f8,0x50($s0)
/*    1f024:	c60e0050 */ 	lwc1	$f14,0x50($s0)
/*    1f028:	460c703c */ 	c.lt.s	$f14,$f12
/*    1f02c:	00000000 */ 	nop
/*    1f030:	4502000b */ 	bc1fl	.L0001f060
/*    1f034:	c60a0044 */ 	lwc1	$f10,0x44($s0)
/*    1f038:	c6000048 */ 	lwc1	$f0,0x48($s0)
/*    1f03c:	c6040044 */ 	lwc1	$f4,0x44($s0)
/*    1f040:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f044:	46002281 */ 	sub.s	$f10,$f4,$f0
/*    1f048:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*    1f04c:	460c3203 */ 	div.s	$f8,$f6,$f12
/*    1f050:	46080100 */ 	add.s	$f4,$f0,$f8
/*    1f054:	10000005 */ 	b	.L0001f06c
/*    1f058:	e6040040 */ 	swc1	$f4,0x40($s0)
/*    1f05c:	c60a0044 */ 	lwc1	$f10,0x44($s0)
.L0001f060:
/*    1f060:	e616004c */ 	swc1	$f22,0x4c($s0)
/*    1f064:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f068:	e60a0040 */ 	swc1	$f10,0x40($s0)
.L0001f06c:
/*    1f06c:	c6000040 */ 	lwc1	$f0,0x40($s0)
.L0001f070:
/*    1f070:	3c013e80 */ 	lui	$at,0x3e80
/*    1f074:	44814000 */ 	mtc1	$at,$f8
/*    1f078:	46001182 */ 	mul.s	$f6,$f2,$f0
/*    1f07c:	00000000 */ 	nop
/*    1f080:	46083102 */ 	mul.s	$f4,$f6,$f8
/*    1f084:	46049480 */ 	add.s	$f18,$f18,$f4
.L0001f088:
/*    1f088:	820f000a */ 	lb	$t7,0xa($s0)
/*    1f08c:	51e00070 */ 	beqzl	$t7,.L0001f250
/*    1f090:	2631ffff */ 	addiu	$s1,$s1,-1
/*    1f094:	461ab03e */ 	c.le.s	$f22,$f26
/*    1f098:	c6180018 */ 	lwc1	$f24,0x18($s0)
/*    1f09c:	45020015 */ 	bc1fl	.L0001f0f4
/*    1f0a0:	c6140060 */ 	lwc1	$f20,0x60($s0)
/*    1f0a4:	86040000 */ 	lh	$a0,0x0($s0)
/*    1f0a8:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*    1f0ac:	0c008dda */ 	jal	animGetNumFrames
/*    1f0b0:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f0b4:	2458ffff */ 	addiu	$t8,$v0,-1
/*    1f0b8:	44985000 */ 	mtc1	$t8,$f10
/*    1f0bc:	4618b03e */ 	c.le.s	$f22,$f24
/*    1f0c0:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f0c4:	46805020 */ 	cvt.s.w	$f0,$f10
/*    1f0c8:	c7b20088 */ 	lwc1	$f18,0x88($sp)
/*    1f0cc:	c61c0060 */ 	lwc1	$f28,0x60($s0)
/*    1f0d0:	45000019 */ 	bc1f	.L0001f138
/*    1f0d4:	46000506 */ 	mov.s	$f20,$f0
/*    1f0d8:	4600c03c */ 	c.lt.s	$f24,$f0
/*    1f0dc:	00000000 */ 	nop
/*    1f0e0:	45020016 */ 	bc1fl	.L0001f13c
/*    1f0e4:	461ab03e */ 	c.le.s	$f22,$f26
/*    1f0e8:	10000013 */ 	b	.L0001f138
/*    1f0ec:	4600c506 */ 	mov.s	$f20,$f24
/*    1f0f0:	c6140060 */ 	lwc1	$f20,0x60($s0)
.L0001f0f4:
/*    1f0f4:	86040000 */ 	lh	$a0,0x0($s0)
/*    1f0f8:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*    1f0fc:	0c008dda */ 	jal	animGetNumFrames
/*    1f100:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f104:	2459ffff */ 	addiu	$t9,$v0,-1
/*    1f108:	44993000 */ 	mtc1	$t9,$f6
/*    1f10c:	4618b03e */ 	c.le.s	$f22,$f24
/*    1f110:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f114:	46803020 */ 	cvt.s.w	$f0,$f6
/*    1f118:	c7b20088 */ 	lwc1	$f18,0x88($sp)
/*    1f11c:	45000006 */ 	bc1f	.L0001f138
/*    1f120:	46000706 */ 	mov.s	$f28,$f0
/*    1f124:	4600c03c */ 	c.lt.s	$f24,$f0
/*    1f128:	00000000 */ 	nop
/*    1f12c:	45020003 */ 	bc1fl	.L0001f13c
/*    1f130:	461ab03e */ 	c.le.s	$f22,$f26
/*    1f134:	4600c706 */ 	mov.s	$f28,$f24
.L0001f138:
/*    1f138:	461ab03e */ 	c.le.s	$f22,$f26
.L0001f13c:
/*    1f13c:	00000000 */ 	nop
/*    1f140:	45020006 */ 	bc1fl	.L0001f15c
/*    1f144:	4616d03c */ 	c.lt.s	$f26,$f22
/*    1f148:	4610a03e */ 	c.le.s	$f20,$f16
/*    1f14c:	00000000 */ 	nop
/*    1f150:	4503000a */ 	bc1tl	.L0001f17c
/*    1f154:	c6080028 */ 	lwc1	$f8,0x28($s0)
/*    1f158:	4616d03c */ 	c.lt.s	$f26,$f22
.L0001f15c:
/*    1f15c:	00000000 */ 	nop
/*    1f160:	4502003b */ 	bc1fl	.L0001f250
/*    1f164:	2631ffff */ 	addiu	$s1,$s1,-1
/*    1f168:	4614803e */ 	c.le.s	$f16,$f20
/*    1f16c:	00000000 */ 	nop
/*    1f170:	45020037 */ 	bc1fl	.L0001f250
/*    1f174:	2631ffff */ 	addiu	$s1,$s1,-1
/*    1f178:	c6080028 */ 	lwc1	$f8,0x28($s0)
.L0001f17c:
/*    1f17c:	c61a0020 */ 	lwc1	$f26,0x20($s0)
/*    1f180:	c61e0024 */ 	lwc1	$f30,0x24($s0)
/*    1f184:	8fa80098 */ 	lw	$t0,0x98($sp)
/*    1f188:	e7a80064 */ 	swc1	$f8,0x64($sp)
/*    1f18c:	c604002c */ 	lwc1	$f4,0x2c($s0)
/*    1f190:	02402025 */ 	or	$a0,$s2,$zero
/*    1f194:	1100000a */ 	beqz	$t0,.L0001f1c0
/*    1f198:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*    1f19c:	8e05000c */ 	lw	$a1,0xc($s0)
/*    1f1a0:	4406a000 */ 	mfc1	$a2,$f20
/*    1f1a4:	4407b000 */ 	mfc1	$a3,$f22
/*    1f1a8:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f1ac:	e7b60010 */ 	swc1	$f22,0x10($sp)
/*    1f1b0:	0c0078ad */ 	jal	func0001e2b4
/*    1f1b4:	02402025 */ 	or	$a0,$s2,$zero
/*    1f1b8:	10000006 */ 	b	.L0001f1d4
/*    1f1bc:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
.L0001f1c0:
/*    1f1c0:	4405a000 */ 	mfc1	$a1,$f20
/*    1f1c4:	4406b000 */ 	mfc1	$a2,$f22
/*    1f1c8:	0c007853 */ 	jal	func0001e14c
/*    1f1cc:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f1d0:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
.L0001f1d4:
/*    1f1d4:	c60a001c */ 	lwc1	$f10,0x1c($s0)
/*    1f1d8:	86050000 */ 	lh	$a1,0x0($s0)
/*    1f1dc:	82060008 */ 	lb	$a2,0x8($s0)
/*    1f1e0:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    1f1e4:	c6060064 */ 	lwc1	$f6,0x64($s0)
/*    1f1e8:	4407e000 */ 	mfc1	$a3,$f28
/*    1f1ec:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f1f0:	02402025 */ 	or	$a0,$s2,$zero
/*    1f1f4:	0c007733 */ 	jal	modelSetAnimation
/*    1f1f8:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    1f1fc:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f200:	24090001 */ 	addiu	$t1,$zero,0x1
/*    1f204:	a209000a */ 	sb	$t1,0xa($s0)
/*    1f208:	e6180018 */ 	swc1	$f24,0x18($s0)
/*    1f20c:	e61a0020 */ 	swc1	$f26,0x20($s0)
/*    1f210:	e61e0024 */ 	swc1	$f30,0x24($s0)
/*    1f214:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*    1f218:	4610e280 */ 	add.s	$f10,$f28,$f16
/*    1f21c:	8e020068 */ 	lw	$v0,0x68($s0)
/*    1f220:	e6080028 */ 	swc1	$f8,0x28($s0)
/*    1f224:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*    1f228:	46008486 */ 	mov.s	$f18,$f16
/*    1f22c:	46145401 */ 	sub.s	$f16,$f10,$f20
/*    1f230:	10400006 */ 	beqz	$v0,.L0001f24c
/*    1f234:	e604002c */ 	swc1	$f4,0x2c($s0)
/*    1f238:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f23c:	0040f809 */ 	jalr	$v0
/*    1f240:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*    1f244:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f248:	c7b20088 */ 	lwc1	$f18,0x88($sp)
.L0001f24c:
/*    1f24c:	2631ffff */ 	addiu	$s1,$s1,-1
.L0001f250:
/*    1f250:	5e20ff0a */ 	bgtzl	$s1,.L0001ee7c
/*    1f254:	c6020080 */ 	lwc1	$f2,0x80($s0)
.L0001f258:
/*    1f258:	8faa0098 */ 	lw	$t2,0x98($sp)
/*    1f25c:	4480b000 */ 	mtc1	$zero,$f22
/*    1f260:	86020002 */ 	lh	$v0,0x2($s0)
/*    1f264:	11400013 */ 	beqz	$t2,.L0001f2b4
/*    1f268:	00000000 */ 	nop
/*    1f26c:	10400009 */ 	beqz	$v0,.L0001f294
/*    1f270:	c600000c */ 	lwc1	$f0,0xc($s0)
/*    1f274:	44050000 */ 	mfc1	$a1,$f0
/*    1f278:	44068000 */ 	mfc1	$a2,$f16
/*    1f27c:	8e070030 */ 	lw	$a3,0x30($s0)
/*    1f280:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*    1f284:	0c0078ad */ 	jal	func0001e2b4
/*    1f288:	02402025 */ 	or	$a0,$s2,$zero
/*    1f28c:	10000016 */ 	b	.L0001f2e8
/*    1f290:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0001f294:
/*    1f294:	44050000 */ 	mfc1	$a1,$f0
/*    1f298:	44068000 */ 	mfc1	$a2,$f16
/*    1f29c:	4407b000 */ 	mfc1	$a3,$f22
/*    1f2a0:	02402025 */ 	or	$a0,$s2,$zero
/*    1f2a4:	0c0078ad */ 	jal	func0001e2b4
/*    1f2a8:	e7b60010 */ 	swc1	$f22,0x10($sp)
/*    1f2ac:	1000000e */ 	b	.L0001f2e8
/*    1f2b0:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0001f2b4:
/*    1f2b4:	50400008 */ 	beqzl	$v0,.L0001f2d8
/*    1f2b8:	44058000 */ 	mfc1	$a1,$f16
/*    1f2bc:	44058000 */ 	mfc1	$a1,$f16
/*    1f2c0:	44069000 */ 	mfc1	$a2,$f18
/*    1f2c4:	0c007853 */ 	jal	func0001e14c
/*    1f2c8:	02402025 */ 	or	$a0,$s2,$zero
/*    1f2cc:	10000006 */ 	b	.L0001f2e8
/*    1f2d0:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    1f2d4:	44058000 */ 	mfc1	$a1,$f16
.L0001f2d8:
/*    1f2d8:	4406b000 */ 	mfc1	$a2,$f22
/*    1f2dc:	0c007853 */ 	jal	func0001e14c
/*    1f2e0:	02402025 */ 	or	$a0,$s2,$zero
/*    1f2e4:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0001f2e8:
/*    1f2e8:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*    1f2ec:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*    1f2f0:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*    1f2f4:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*    1f2f8:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*    1f2fc:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*    1f300:	8fb00050 */ 	lw	$s0,0x50($sp)
/*    1f304:	8fb10054 */ 	lw	$s1,0x54($sp)
/*    1f308:	8fb20058 */ 	lw	$s2,0x58($sp)
/*    1f30c:	03e00008 */ 	jr	$ra
/*    1f310:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0001f314
/*    1f314:	27bdff70 */ 	addiu	$sp,$sp,-144
/*    1f318:	afbf005c */ 	sw	$ra,0x5c($sp)
/*    1f31c:	afb20058 */ 	sw	$s2,0x58($sp)
/*    1f320:	afb10054 */ 	sw	$s1,0x54($sp)
/*    1f324:	afb00050 */ 	sw	$s0,0x50($sp)
/*    1f328:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*    1f32c:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*    1f330:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*    1f334:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*    1f338:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*    1f33c:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*    1f340:	afa60098 */ 	sw	$a2,0x98($sp)
/*    1f344:	8c900020 */ 	lw	$s0,0x20($a0)
/*    1f348:	00a08825 */ 	or	$s1,$a1,$zero
/*    1f34c:	00809025 */ 	or	$s2,$a0,$zero
/*    1f350:	52000118 */ 	beqzl	$s0,.L0001f7b4
/*    1f354:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    1f358:	58a00116 */ 	blezl	$a1,.L0001f7b4
/*    1f35c:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    1f360:	c610000c */ 	lwc1	$f16,0xc($s0)
/*    1f364:	18a000ef */ 	blez	$a1,.L0001f724
/*    1f368:	c6120030 */ 	lwc1	$f18,0x30($s0)
/*    1f36c:	4480b000 */ 	mtc1	$zero,$f22
/*    1f370:	00000000 */ 	nop
/*    1f374:	c6020080 */ 	lwc1	$f2,0x80($s0)
.L0001f378:
/*    1f378:	3c013f80 */ 	lui	$at,0x3f80
/*    1f37c:	4602b03c */ 	c.lt.s	$f22,$f2
/*    1f380:	00000000 */ 	nop
/*    1f384:	45020017 */ 	bc1fl	.L0001f3e4
/*    1f388:	c6060058 */ 	lwc1	$f6,0x58($s0)
/*    1f38c:	c6040084 */ 	lwc1	$f4,0x84($s0)
/*    1f390:	44813000 */ 	mtc1	$at,$f6
/*    1f394:	00000000 */ 	nop
/*    1f398:	46062200 */ 	add.s	$f8,$f4,$f6
/*    1f39c:	e6080084 */ 	swc1	$f8,0x84($s0)
/*    1f3a0:	c60c0084 */ 	lwc1	$f12,0x84($s0)
/*    1f3a4:	4602603c */ 	c.lt.s	$f12,$f2
/*    1f3a8:	00000000 */ 	nop
/*    1f3ac:	4502000a */ 	bc1fl	.L0001f3d8
/*    1f3b0:	c6040078 */ 	lwc1	$f4,0x78($s0)
/*    1f3b4:	c600007c */ 	lwc1	$f0,0x7c($s0)
/*    1f3b8:	c60a0078 */ 	lwc1	$f10,0x78($s0)
/*    1f3bc:	46005101 */ 	sub.s	$f4,$f10,$f0
/*    1f3c0:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*    1f3c4:	46023203 */ 	div.s	$f8,$f6,$f2
/*    1f3c8:	46080280 */ 	add.s	$f10,$f0,$f8
/*    1f3cc:	10000004 */ 	b	.L0001f3e0
/*    1f3d0:	e60a0074 */ 	swc1	$f10,0x74($s0)
/*    1f3d4:	c6040078 */ 	lwc1	$f4,0x78($s0)
.L0001f3d8:
/*    1f3d8:	e6160080 */ 	swc1	$f22,0x80($s0)
/*    1f3dc:	e6040074 */ 	swc1	$f4,0x74($s0)
.L0001f3e0:
/*    1f3e0:	c6060058 */ 	lwc1	$f6,0x58($s0)
.L0001f3e4:
/*    1f3e4:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f3e8:	4606b03c */ 	c.lt.s	$f22,$f6
/*    1f3ec:	00000000 */ 	nop
/*    1f3f0:	4502001d */ 	bc1fl	.L0001f468
/*    1f3f4:	c60c0028 */ 	lwc1	$f12,0x28($s0)
/*    1f3f8:	c608005c */ 	lwc1	$f8,0x5c($s0)
/*    1f3fc:	3c013f80 */ 	lui	$at,0x3f80
/*    1f400:	46024280 */ 	add.s	$f10,$f8,$f2
/*    1f404:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*    1f408:	c60c005c */ 	lwc1	$f12,0x5c($s0)
/*    1f40c:	460cb032 */ 	c.eq.s	$f22,$f12
/*    1f410:	00000000 */ 	nop
/*    1f414:	45020006 */ 	bc1fl	.L0001f430
/*    1f418:	c6000058 */ 	lwc1	$f0,0x58($s0)
/*    1f41c:	44812000 */ 	mtc1	$at,$f4
/*    1f420:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f424:	1000000f */ 	b	.L0001f464
/*    1f428:	e6040054 */ 	swc1	$f4,0x54($s0)
/*    1f42c:	c6000058 */ 	lwc1	$f0,0x58($s0)
.L0001f430:
/*    1f430:	4600603c */ 	c.lt.s	$f12,$f0
/*    1f434:	00000000 */ 	nop
/*    1f438:	45020007 */ 	bc1fl	.L0001f458
/*    1f43c:	e6160058 */ 	swc1	$f22,0x58($s0)
/*    1f440:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*    1f444:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f448:	46003203 */ 	div.s	$f8,$f6,$f0
/*    1f44c:	10000005 */ 	b	.L0001f464
/*    1f450:	e6080054 */ 	swc1	$f8,0x54($s0)
/*    1f454:	e6160058 */ 	swc1	$f22,0x58($s0)
.L0001f458:
/*    1f458:	e6160054 */ 	swc1	$f22,0x54($s0)
/*    1f45c:	a6000002 */ 	sh	$zero,0x2($s0)
/*    1f460:	c6020074 */ 	lwc1	$f2,0x74($s0)
.L0001f464:
/*    1f464:	c60c0028 */ 	lwc1	$f12,0x28($s0)
.L0001f468:
/*    1f468:	460cb03c */ 	c.lt.s	$f22,$f12
/*    1f46c:	00000000 */ 	nop
/*    1f470:	45020017 */ 	bc1fl	.L0001f4d0
/*    1f474:	c61a001c */ 	lwc1	$f26,0x1c($s0)
/*    1f478:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*    1f47c:	46025100 */ 	add.s	$f4,$f10,$f2
/*    1f480:	e604002c */ 	swc1	$f4,0x2c($s0)
/*    1f484:	c60e002c */ 	lwc1	$f14,0x2c($s0)
/*    1f488:	460c703c */ 	c.lt.s	$f14,$f12
/*    1f48c:	00000000 */ 	nop
/*    1f490:	4502000b */ 	bc1fl	.L0001f4c0
/*    1f494:	c6080020 */ 	lwc1	$f8,0x20($s0)
/*    1f498:	c6000024 */ 	lwc1	$f0,0x24($s0)
/*    1f49c:	c6060020 */ 	lwc1	$f6,0x20($s0)
/*    1f4a0:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f4a4:	46003201 */ 	sub.s	$f8,$f6,$f0
/*    1f4a8:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*    1f4ac:	460c5103 */ 	div.s	$f4,$f10,$f12
/*    1f4b0:	46040180 */ 	add.s	$f6,$f0,$f4
/*    1f4b4:	10000005 */ 	b	.L0001f4cc
/*    1f4b8:	e606001c */ 	swc1	$f6,0x1c($s0)
/*    1f4bc:	c6080020 */ 	lwc1	$f8,0x20($s0)
.L0001f4c0:
/*    1f4c0:	e6160028 */ 	swc1	$f22,0x28($s0)
/*    1f4c4:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f4c8:	e608001c */ 	swc1	$f8,0x1c($s0)
.L0001f4cc:
/*    1f4cc:	c61a001c */ 	lwc1	$f26,0x1c($s0)
.L0001f4d0:
/*    1f4d0:	860e0002 */ 	lh	$t6,0x2($s0)
/*    1f4d4:	461a1282 */ 	mul.s	$f10,$f2,$f26
/*    1f4d8:	11c0001e */ 	beqz	$t6,.L0001f554
/*    1f4dc:	460a8400 */ 	add.s	$f16,$f16,$f10
/*    1f4e0:	c60c004c */ 	lwc1	$f12,0x4c($s0)
/*    1f4e4:	460cb03c */ 	c.lt.s	$f22,$f12
/*    1f4e8:	00000000 */ 	nop
/*    1f4ec:	45020017 */ 	bc1fl	.L0001f54c
/*    1f4f0:	c6000040 */ 	lwc1	$f0,0x40($s0)
/*    1f4f4:	c6040050 */ 	lwc1	$f4,0x50($s0)
/*    1f4f8:	46022180 */ 	add.s	$f6,$f4,$f2
/*    1f4fc:	e6060050 */ 	swc1	$f6,0x50($s0)
/*    1f500:	c60e0050 */ 	lwc1	$f14,0x50($s0)
/*    1f504:	460c703c */ 	c.lt.s	$f14,$f12
/*    1f508:	00000000 */ 	nop
/*    1f50c:	4502000b */ 	bc1fl	.L0001f53c
/*    1f510:	c60a0044 */ 	lwc1	$f10,0x44($s0)
/*    1f514:	c6000048 */ 	lwc1	$f0,0x48($s0)
/*    1f518:	c6080044 */ 	lwc1	$f8,0x44($s0)
/*    1f51c:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f520:	46004281 */ 	sub.s	$f10,$f8,$f0
/*    1f524:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*    1f528:	460c2183 */ 	div.s	$f6,$f4,$f12
/*    1f52c:	46060200 */ 	add.s	$f8,$f0,$f6
/*    1f530:	10000005 */ 	b	.L0001f548
/*    1f534:	e6080040 */ 	swc1	$f8,0x40($s0)
/*    1f538:	c60a0044 */ 	lwc1	$f10,0x44($s0)
.L0001f53c:
/*    1f53c:	e616004c */ 	swc1	$f22,0x4c($s0)
/*    1f540:	c6020074 */ 	lwc1	$f2,0x74($s0)
/*    1f544:	e60a0040 */ 	swc1	$f10,0x40($s0)
.L0001f548:
/*    1f548:	c6000040 */ 	lwc1	$f0,0x40($s0)
.L0001f54c:
/*    1f54c:	46001102 */ 	mul.s	$f4,$f2,$f0
/*    1f550:	46049480 */ 	add.s	$f18,$f18,$f4
.L0001f554:
/*    1f554:	820f000a */ 	lb	$t7,0xa($s0)
/*    1f558:	51e00070 */ 	beqzl	$t7,.L0001f71c
/*    1f55c:	2631ffff */ 	addiu	$s1,$s1,-1
/*    1f560:	461ab03e */ 	c.le.s	$f22,$f26
/*    1f564:	c6180018 */ 	lwc1	$f24,0x18($s0)
/*    1f568:	45020015 */ 	bc1fl	.L0001f5c0
/*    1f56c:	c6140060 */ 	lwc1	$f20,0x60($s0)
/*    1f570:	86040000 */ 	lh	$a0,0x0($s0)
/*    1f574:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*    1f578:	0c008dda */ 	jal	animGetNumFrames
/*    1f57c:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f580:	2458ffff */ 	addiu	$t8,$v0,-1
/*    1f584:	44983000 */ 	mtc1	$t8,$f6
/*    1f588:	4618b03e */ 	c.le.s	$f22,$f24
/*    1f58c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f590:	46803020 */ 	cvt.s.w	$f0,$f6
/*    1f594:	c7b20088 */ 	lwc1	$f18,0x88($sp)
/*    1f598:	c61c0060 */ 	lwc1	$f28,0x60($s0)
/*    1f59c:	45000019 */ 	bc1f	.L0001f604
/*    1f5a0:	46000506 */ 	mov.s	$f20,$f0
/*    1f5a4:	4600c03c */ 	c.lt.s	$f24,$f0
/*    1f5a8:	00000000 */ 	nop
/*    1f5ac:	45020016 */ 	bc1fl	.L0001f608
/*    1f5b0:	461ab03e */ 	c.le.s	$f22,$f26
/*    1f5b4:	10000013 */ 	b	.L0001f604
/*    1f5b8:	4600c506 */ 	mov.s	$f20,$f24
/*    1f5bc:	c6140060 */ 	lwc1	$f20,0x60($s0)
.L0001f5c0:
/*    1f5c0:	86040000 */ 	lh	$a0,0x0($s0)
/*    1f5c4:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*    1f5c8:	0c008dda */ 	jal	animGetNumFrames
/*    1f5cc:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f5d0:	2459ffff */ 	addiu	$t9,$v0,-1
/*    1f5d4:	44994000 */ 	mtc1	$t9,$f8
/*    1f5d8:	4618b03e */ 	c.le.s	$f22,$f24
/*    1f5dc:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f5e0:	46804020 */ 	cvt.s.w	$f0,$f8
/*    1f5e4:	c7b20088 */ 	lwc1	$f18,0x88($sp)
/*    1f5e8:	45000006 */ 	bc1f	.L0001f604
/*    1f5ec:	46000706 */ 	mov.s	$f28,$f0
/*    1f5f0:	4600c03c */ 	c.lt.s	$f24,$f0
/*    1f5f4:	00000000 */ 	nop
/*    1f5f8:	45020003 */ 	bc1fl	.L0001f608
/*    1f5fc:	461ab03e */ 	c.le.s	$f22,$f26
/*    1f600:	4600c706 */ 	mov.s	$f28,$f24
.L0001f604:
/*    1f604:	461ab03e */ 	c.le.s	$f22,$f26
.L0001f608:
/*    1f608:	00000000 */ 	nop
/*    1f60c:	45020006 */ 	bc1fl	.L0001f628
/*    1f610:	4616d03c */ 	c.lt.s	$f26,$f22
/*    1f614:	4610a03e */ 	c.le.s	$f20,$f16
/*    1f618:	00000000 */ 	nop
/*    1f61c:	4503000a */ 	bc1tl	.L0001f648
/*    1f620:	c60a0028 */ 	lwc1	$f10,0x28($s0)
/*    1f624:	4616d03c */ 	c.lt.s	$f26,$f22
.L0001f628:
/*    1f628:	00000000 */ 	nop
/*    1f62c:	4502003b */ 	bc1fl	.L0001f71c
/*    1f630:	2631ffff */ 	addiu	$s1,$s1,-1
/*    1f634:	4614803e */ 	c.le.s	$f16,$f20
/*    1f638:	00000000 */ 	nop
/*    1f63c:	45020037 */ 	bc1fl	.L0001f71c
/*    1f640:	2631ffff */ 	addiu	$s1,$s1,-1
/*    1f644:	c60a0028 */ 	lwc1	$f10,0x28($s0)
.L0001f648:
/*    1f648:	c61a0020 */ 	lwc1	$f26,0x20($s0)
/*    1f64c:	c61e0024 */ 	lwc1	$f30,0x24($s0)
/*    1f650:	8fa80098 */ 	lw	$t0,0x98($sp)
/*    1f654:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*    1f658:	c604002c */ 	lwc1	$f4,0x2c($s0)
/*    1f65c:	02402025 */ 	or	$a0,$s2,$zero
/*    1f660:	1100000a */ 	beqz	$t0,.L0001f68c
/*    1f664:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*    1f668:	8e05000c */ 	lw	$a1,0xc($s0)
/*    1f66c:	4406a000 */ 	mfc1	$a2,$f20
/*    1f670:	4407b000 */ 	mfc1	$a3,$f22
/*    1f674:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f678:	e7b60010 */ 	swc1	$f22,0x10($sp)
/*    1f67c:	0c0078ad */ 	jal	func0001e2b4
/*    1f680:	02402025 */ 	or	$a0,$s2,$zero
/*    1f684:	10000006 */ 	b	.L0001f6a0
/*    1f688:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
.L0001f68c:
/*    1f68c:	4405a000 */ 	mfc1	$a1,$f20
/*    1f690:	4406b000 */ 	mfc1	$a2,$f22
/*    1f694:	0c007853 */ 	jal	func0001e14c
/*    1f698:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f69c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
.L0001f6a0:
/*    1f6a0:	c606001c */ 	lwc1	$f6,0x1c($s0)
/*    1f6a4:	86050000 */ 	lh	$a1,0x0($s0)
/*    1f6a8:	82060008 */ 	lb	$a2,0x8($s0)
/*    1f6ac:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    1f6b0:	c6080064 */ 	lwc1	$f8,0x64($s0)
/*    1f6b4:	4407e000 */ 	mfc1	$a3,$f28
/*    1f6b8:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f6bc:	02402025 */ 	or	$a0,$s2,$zero
/*    1f6c0:	0c007733 */ 	jal	modelSetAnimation
/*    1f6c4:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*    1f6c8:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f6cc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    1f6d0:	a209000a */ 	sb	$t1,0xa($s0)
/*    1f6d4:	e6180018 */ 	swc1	$f24,0x18($s0)
/*    1f6d8:	e61a0020 */ 	swc1	$f26,0x20($s0)
/*    1f6dc:	e61e0024 */ 	swc1	$f30,0x24($s0)
/*    1f6e0:	c7aa0064 */ 	lwc1	$f10,0x64($sp)
/*    1f6e4:	4610e180 */ 	add.s	$f6,$f28,$f16
/*    1f6e8:	8e020068 */ 	lw	$v0,0x68($s0)
/*    1f6ec:	e60a0028 */ 	swc1	$f10,0x28($s0)
/*    1f6f0:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*    1f6f4:	46008486 */ 	mov.s	$f18,$f16
/*    1f6f8:	46143401 */ 	sub.s	$f16,$f6,$f20
/*    1f6fc:	10400006 */ 	beqz	$v0,.L0001f718
/*    1f700:	e604002c */ 	swc1	$f4,0x2c($s0)
/*    1f704:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*    1f708:	0040f809 */ 	jalr	$v0
/*    1f70c:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*    1f710:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*    1f714:	c7b20088 */ 	lwc1	$f18,0x88($sp)
.L0001f718:
/*    1f718:	2631ffff */ 	addiu	$s1,$s1,-1
.L0001f71c:
/*    1f71c:	5e20ff16 */ 	bgtzl	$s1,.L0001f378
/*    1f720:	c6020080 */ 	lwc1	$f2,0x80($s0)
.L0001f724:
/*    1f724:	8faa0098 */ 	lw	$t2,0x98($sp)
/*    1f728:	4480b000 */ 	mtc1	$zero,$f22
/*    1f72c:	86020002 */ 	lh	$v0,0x2($s0)
/*    1f730:	11400013 */ 	beqz	$t2,.L0001f780
/*    1f734:	00000000 */ 	nop
/*    1f738:	10400009 */ 	beqz	$v0,.L0001f760
/*    1f73c:	c600000c */ 	lwc1	$f0,0xc($s0)
/*    1f740:	44050000 */ 	mfc1	$a1,$f0
/*    1f744:	44068000 */ 	mfc1	$a2,$f16
/*    1f748:	8e070030 */ 	lw	$a3,0x30($s0)
/*    1f74c:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*    1f750:	0c0078ad */ 	jal	func0001e2b4
/*    1f754:	02402025 */ 	or	$a0,$s2,$zero
/*    1f758:	10000016 */ 	b	.L0001f7b4
/*    1f75c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0001f760:
/*    1f760:	44050000 */ 	mfc1	$a1,$f0
/*    1f764:	44068000 */ 	mfc1	$a2,$f16
/*    1f768:	4407b000 */ 	mfc1	$a3,$f22
/*    1f76c:	02402025 */ 	or	$a0,$s2,$zero
/*    1f770:	0c0078ad */ 	jal	func0001e2b4
/*    1f774:	e7b60010 */ 	swc1	$f22,0x10($sp)
/*    1f778:	1000000e */ 	b	.L0001f7b4
/*    1f77c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0001f780:
/*    1f780:	50400008 */ 	beqzl	$v0,.L0001f7a4
/*    1f784:	44058000 */ 	mfc1	$a1,$f16
/*    1f788:	44058000 */ 	mfc1	$a1,$f16
/*    1f78c:	44069000 */ 	mfc1	$a2,$f18
/*    1f790:	0c007853 */ 	jal	func0001e14c
/*    1f794:	02402025 */ 	or	$a0,$s2,$zero
/*    1f798:	10000006 */ 	b	.L0001f7b4
/*    1f79c:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    1f7a0:	44058000 */ 	mfc1	$a1,$f16
.L0001f7a4:
/*    1f7a4:	4406b000 */ 	mfc1	$a2,$f22
/*    1f7a8:	0c007853 */ 	jal	func0001e14c
/*    1f7ac:	02402025 */ 	or	$a0,$s2,$zero
/*    1f7b0:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0001f7b4:
/*    1f7b4:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*    1f7b8:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*    1f7bc:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*    1f7c0:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*    1f7c4:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*    1f7c8:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*    1f7cc:	8fb00050 */ 	lw	$s0,0x50($sp)
/*    1f7d0:	8fb10054 */ 	lw	$s1,0x54($sp)
/*    1f7d4:	8fb20058 */ 	lw	$s2,0x58($sp)
/*    1f7d8:	03e00008 */ 	jr	$ra
/*    1f7dc:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0001f7e0
/*    1f7e0:	8c83000c */ 	lw	$v1,0xc($a0)
/*    1f7e4:	3c0fe700 */ 	lui	$t7,0xe700
/*    1f7e8:	3c19ba00 */ 	lui	$t9,0xba00
/*    1f7ec:	246e0008 */ 	addiu	$t6,$v1,0x8
/*    1f7f0:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    1f7f4:	ac600004 */ 	sw	$zero,0x4($v1)
/*    1f7f8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    1f7fc:	8c83000c */ 	lw	$v1,0xc($a0)
/*    1f800:	37391402 */ 	ori	$t9,$t9,0x1402
/*    1f804:	3c0db900 */ 	lui	$t5,0xb900
/*    1f808:	24780008 */ 	addiu	$t8,$v1,0x8
/*    1f80c:	ac98000c */ 	sw	$t8,0xc($a0)
/*    1f810:	ac600004 */ 	sw	$zero,0x4($v1)
/*    1f814:	ac790000 */ 	sw	$t9,0x0($v1)
/*    1f818:	8c880004 */ 	lw	$t0,0x4($a0)
/*    1f81c:	3c18fc12 */ 	lui	$t8,0xfc12
/*    1f820:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    1f824:	1100000b */ 	beqz	$t0,.L0001f854
/*    1f828:	37181824 */ 	ori	$t8,$t8,0x1824
/*    1f82c:	8c83000c */ 	lw	$v1,0xc($a0)
/*    1f830:	3c0ab900 */ 	lui	$t2,0xb900
/*    1f834:	3c0b0055 */ 	lui	$t3,0x55
/*    1f838:	24690008 */ 	addiu	$t1,$v1,0x8
/*    1f83c:	ac89000c */ 	sw	$t1,0xc($a0)
/*    1f840:	356b2078 */ 	ori	$t3,$t3,0x2078
/*    1f844:	354a031d */ 	ori	$t2,$t2,0x31d
/*    1f848:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*    1f84c:	10000008 */ 	b	.L0001f870
/*    1f850:	ac6b0004 */ 	sw	$t3,0x4($v1)
.L0001f854:
/*    1f854:	8c83000c */ 	lw	$v1,0xc($a0)
/*    1f858:	3c0e0055 */ 	lui	$t6,0x55
/*    1f85c:	35ce2048 */ 	ori	$t6,$t6,0x2048
/*    1f860:	246c0008 */ 	addiu	$t4,$v1,0x8
/*    1f864:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    1f868:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*    1f86c:	ac6d0000 */ 	sw	$t5,0x0($v1)
.L0001f870:
/*    1f870:	8c83000c */ 	lw	$v1,0xc($a0)
/*    1f874:	3c19ff33 */ 	lui	$t9,0xff33
/*    1f878:	3739ffff */ 	ori	$t9,$t9,0xffff
/*    1f87c:	246f0008 */ 	addiu	$t7,$v1,0x8
/*    1f880:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    1f884:	ac790004 */ 	sw	$t9,0x4($v1)
/*    1f888:	03e00008 */ 	jr	$ra
/*    1f88c:	ac780000 */ 	sw	$t8,0x0($v1)
);

GLOBAL_ASM(
glabel func0001f890
/*    1f890:	8c820030 */ 	lw	$v0,0x30($a0)
/*    1f894:	24010007 */ 	addiu	$at,$zero,0x7
/*    1f898:	54410057 */ 	bnel	$v0,$at,.L0001f9f8
/*    1f89c:	24010008 */ 	addiu	$at,$zero,0x8
/*    1f8a0:	50a0003f */ 	beqzl	$a1,.L0001f9a0
/*    1f8a4:	8c980004 */ 	lw	$t8,0x4($a0)
/*    1f8a8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f8ac:	3c0fe700 */ 	lui	$t7,0xe700
/*    1f8b0:	3c19ba00 */ 	lui	$t9,0xba00
/*    1f8b4:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    1f8b8:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    1f8bc:	ac400004 */ 	sw	$zero,0x4($v0)
/*    1f8c0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    1f8c4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f8c8:	37391402 */ 	ori	$t9,$t9,0x1402
/*    1f8cc:	3c080010 */ 	lui	$t0,0x10
/*    1f8d0:	24580008 */ 	addiu	$t8,$v0,0x8
/*    1f8d4:	ac98000c */ 	sw	$t8,0xc($a0)
/*    1f8d8:	ac480004 */ 	sw	$t0,0x4($v0)
/*    1f8dc:	ac590000 */ 	sw	$t9,0x0($v0)
/*    1f8e0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f8e4:	3c0af800 */ 	lui	$t2,0xf800
/*    1f8e8:	3c0dfb00 */ 	lui	$t5,0xfb00
/*    1f8ec:	24490008 */ 	addiu	$t1,$v0,0x8
/*    1f8f0:	ac89000c */ 	sw	$t1,0xc($a0)
/*    1f8f4:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    1f8f8:	8c8b0038 */ 	lw	$t3,0x38($a0)
/*    1f8fc:	3c19fc15 */ 	lui	$t9,0xfc15
/*    1f900:	3c085ffe */ 	lui	$t0,0x5ffe
/*    1f904:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    1f908:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f90c:	3508dbf8 */ 	ori	$t0,$t0,0xdbf8
/*    1f910:	37399804 */ 	ori	$t9,$t9,0x9804
/*    1f914:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    1f918:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    1f91c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    1f920:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*    1f924:	3c0bb900 */ 	lui	$t3,0xb900
/*    1f928:	356b031d */ 	ori	$t3,$t3,0x31d
/*    1f92c:	35cf00ff */ 	ori	$t7,$t6,0xff
/*    1f930:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    1f934:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f938:	3c0eb900 */ 	lui	$t6,0xb900
/*    1f93c:	35ce031d */ 	ori	$t6,$t6,0x31d
/*    1f940:	24580008 */ 	addiu	$t8,$v0,0x8
/*    1f944:	ac98000c */ 	sw	$t8,0xc($a0)
/*    1f948:	ac480004 */ 	sw	$t0,0x4($v0)
/*    1f94c:	ac590000 */ 	sw	$t9,0x0($v0)
/*    1f950:	8c890004 */ 	lw	$t1,0x4($a0)
/*    1f954:	5120000a */ 	beqzl	$t1,.L0001f980
/*    1f958:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f95c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f960:	3c0cc411 */ 	lui	$t4,0xc411
/*    1f964:	358c2078 */ 	ori	$t4,$t4,0x2078
/*    1f968:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1f96c:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1f970:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1f974:	03e00008 */ 	jr	$ra
/*    1f978:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1f97c:	8c82000c */ 	lw	$v0,0xc($a0)
.L0001f980:
/*    1f980:	3c0fc411 */ 	lui	$t7,0xc411
/*    1f984:	35ef2048 */ 	ori	$t7,$t7,0x2048
/*    1f988:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1f98c:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1f990:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    1f994:	03e00008 */ 	jr	$ra
/*    1f998:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    1f99c:	8c980004 */ 	lw	$t8,0x4($a0)
.L0001f9a0:
/*    1f9a0:	3c0bb900 */ 	lui	$t3,0xb900
/*    1f9a4:	3c08b900 */ 	lui	$t0,0xb900
/*    1f9a8:	1300000a */ 	beqz	$t8,.L0001f9d4
/*    1f9ac:	356b031d */ 	ori	$t3,$t3,0x31d
/*    1f9b0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f9b4:	3c09c410 */ 	lui	$t1,0xc410
/*    1f9b8:	352949d8 */ 	ori	$t1,$t1,0x49d8
/*    1f9bc:	24590008 */ 	addiu	$t9,$v0,0x8
/*    1f9c0:	ac99000c */ 	sw	$t9,0xc($a0)
/*    1f9c4:	3508031d */ 	ori	$t0,$t0,0x31d
/*    1f9c8:	ac480000 */ 	sw	$t0,0x0($v0)
/*    1f9cc:	03e00008 */ 	jr	$ra
/*    1f9d0:	ac490004 */ 	sw	$t1,0x4($v0)
.L0001f9d4:
/*    1f9d4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1f9d8:	3c0cc410 */ 	lui	$t4,0xc410
/*    1f9dc:	358c41c8 */ 	ori	$t4,$t4,0x41c8
/*    1f9e0:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1f9e4:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1f9e8:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1f9ec:	03e00008 */ 	jr	$ra
/*    1f9f0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1f9f4:	24010008 */ 	addiu	$at,$zero,0x8
.L0001f9f8:
/*    1f9f8:	54410040 */ 	bnel	$v0,$at,.L0001fafc
/*    1f9fc:	24010009 */ 	addiu	$at,$zero,0x9
/*    1fa00:	10a0020f */ 	beqz	$a1,.L00020240
/*    1fa04:	00000000 */ 	nop
/*    1fa08:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fa0c:	3c0ee700 */ 	lui	$t6,0xe700
/*    1fa10:	3c18ba00 */ 	lui	$t8,0xba00
/*    1fa14:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1fa18:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1fa1c:	ac400004 */ 	sw	$zero,0x4($v0)
/*    1fa20:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    1fa24:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fa28:	37181402 */ 	ori	$t8,$t8,0x1402
/*    1fa2c:	3c190010 */ 	lui	$t9,0x10
/*    1fa30:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    1fa34:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    1fa38:	ac590004 */ 	sw	$t9,0x4($v0)
/*    1fa3c:	ac580000 */ 	sw	$t8,0x0($v0)
/*    1fa40:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fa44:	3c09f800 */ 	lui	$t1,0xf800
/*    1fa48:	3c0cfb00 */ 	lui	$t4,0xfb00
/*    1fa4c:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1fa50:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1fa54:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1fa58:	8c8a0038 */ 	lw	$t2,0x38($a0)
/*    1fa5c:	3c185ffe */ 	lui	$t8,0x5ffe
/*    1fa60:	3c0ffc15 */ 	lui	$t7,0xfc15
/*    1fa64:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    1fa68:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fa6c:	35ef9a04 */ 	ori	$t7,$t7,0x9a04
/*    1fa70:	3718fff8 */ 	ori	$t8,$t8,0xfff8
/*    1fa74:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    1fa78:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    1fa7c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    1fa80:	8c8d0034 */ 	lw	$t5,0x34($a0)
/*    1fa84:	3c09b900 */ 	lui	$t1,0xb900
/*    1fa88:	3c0cb900 */ 	lui	$t4,0xb900
/*    1fa8c:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    1fa90:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fa94:	3529031d */ 	ori	$t1,$t1,0x31d
/*    1fa98:	358c031d */ 	ori	$t4,$t4,0x31d
/*    1fa9c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    1faa0:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    1faa4:	ac580004 */ 	sw	$t8,0x4($v0)
/*    1faa8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    1faac:	8c990004 */ 	lw	$t9,0x4($a0)
/*    1fab0:	5320000a */ 	beqzl	$t9,.L0001fadc
/*    1fab4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fab8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fabc:	3c0ac410 */ 	lui	$t2,0xc410
/*    1fac0:	354a49d8 */ 	ori	$t2,$t2,0x49d8
/*    1fac4:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1fac8:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1facc:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    1fad0:	03e00008 */ 	jr	$ra
/*    1fad4:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1fad8:	8c82000c */ 	lw	$v0,0xc($a0)
.L0001fadc:
/*    1fadc:	3c0dc410 */ 	lui	$t5,0xc410
/*    1fae0:	35ad41c8 */ 	ori	$t5,$t5,0x41c8
/*    1fae4:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    1fae8:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    1faec:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    1faf0:	03e00008 */ 	jr	$ra
/*    1faf4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    1faf8:	24010009 */ 	addiu	$at,$zero,0x9
.L0001fafc:
/*    1fafc:	544100ca */ 	bnel	$v0,$at,.L0001fe28
/*    1fb00:	24010004 */ 	addiu	$at,$zero,0x4
/*    1fb04:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*    1fb08:	31cf00ff */ 	andi	$t7,$t6,0xff
/*    1fb0c:	15e0005e */ 	bnez	$t7,.L0001fc88
/*    1fb10:	00000000 */ 	nop
/*    1fb14:	50a00047 */ 	beqzl	$a1,.L0001fc34
/*    1fb18:	8c8d0004 */ 	lw	$t5,0x4($a0)
/*    1fb1c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fb20:	3c19e700 */ 	lui	$t9,0xe700
/*    1fb24:	3c09ba00 */ 	lui	$t1,0xba00
/*    1fb28:	24580008 */ 	addiu	$t8,$v0,0x8
/*    1fb2c:	ac98000c */ 	sw	$t8,0xc($a0)
/*    1fb30:	ac400004 */ 	sw	$zero,0x4($v0)
/*    1fb34:	ac590000 */ 	sw	$t9,0x0($v0)
/*    1fb38:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fb3c:	35291402 */ 	ori	$t1,$t1,0x1402
/*    1fb40:	3c0a0010 */ 	lui	$t2,0x10
/*    1fb44:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1fb48:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1fb4c:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    1fb50:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1fb54:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fb58:	3c0cf800 */ 	lui	$t4,0xf800
/*    1fb5c:	2418ffff */ 	addiu	$t8,$zero,-1
/*    1fb60:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    1fb64:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    1fb68:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    1fb6c:	8c8d0038 */ 	lw	$t5,0x38($a0)
/*    1fb70:	3c0ffb00 */ 	lui	$t7,0xfb00
/*    1fb74:	3c08fa00 */ 	lui	$t0,0xfa00
/*    1fb78:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    1fb7c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fb80:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    1fb84:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    1fb88:	ac580004 */ 	sw	$t8,0x4($v0)
/*    1fb8c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    1fb90:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fb94:	3c0f1f10 */ 	lui	$t7,0x1f10
/*    1fb98:	3c0efc26 */ 	lui	$t6,0xfc26
/*    1fb9c:	24590008 */ 	addiu	$t9,$v0,0x8
/*    1fba0:	ac99000c */ 	sw	$t9,0xc($a0)
/*    1fba4:	ac480000 */ 	sw	$t0,0x0($v0)
/*    1fba8:	8c890034 */ 	lw	$t1,0x34($a0)
/*    1fbac:	35cea004 */ 	ori	$t6,$t6,0xa004
/*    1fbb0:	35ef93fb */ 	ori	$t7,$t7,0x93fb
/*    1fbb4:	00095a02 */ 	srl	$t3,$t1,0x8
/*    1fbb8:	316c00ff */ 	andi	$t4,$t3,0xff
/*    1fbbc:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1fbc0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fbc4:	3c08b900 */ 	lui	$t0,0xb900
/*    1fbc8:	3c0bb900 */ 	lui	$t3,0xb900
/*    1fbcc:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1fbd0:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1fbd4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    1fbd8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    1fbdc:	8c980004 */ 	lw	$t8,0x4($a0)
/*    1fbe0:	3508031d */ 	ori	$t0,$t0,0x31d
/*    1fbe4:	356b031d */ 	ori	$t3,$t3,0x31d
/*    1fbe8:	5300000a */ 	beqzl	$t8,.L0001fc14
/*    1fbec:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fbf0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fbf4:	3c09c411 */ 	lui	$t1,0xc411
/*    1fbf8:	35292078 */ 	ori	$t1,$t1,0x2078
/*    1fbfc:	24590008 */ 	addiu	$t9,$v0,0x8
/*    1fc00:	ac99000c */ 	sw	$t9,0xc($a0)
/*    1fc04:	ac490004 */ 	sw	$t1,0x4($v0)
/*    1fc08:	03e00008 */ 	jr	$ra
/*    1fc0c:	ac480000 */ 	sw	$t0,0x0($v0)
/*    1fc10:	8c82000c */ 	lw	$v0,0xc($a0)
.L0001fc14:
/*    1fc14:	3c0cc411 */ 	lui	$t4,0xc411
/*    1fc18:	358c2048 */ 	ori	$t4,$t4,0x2048
/*    1fc1c:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1fc20:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1fc24:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1fc28:	03e00008 */ 	jr	$ra
/*    1fc2c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1fc30:	8c8d0004 */ 	lw	$t5,0x4($a0)
.L0001fc34:
/*    1fc34:	3c08b900 */ 	lui	$t0,0xb900
/*    1fc38:	3c0fb900 */ 	lui	$t7,0xb900
/*    1fc3c:	11a0000a */ 	beqz	$t5,.L0001fc68
/*    1fc40:	3508031d */ 	ori	$t0,$t0,0x31d
/*    1fc44:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fc48:	3c18c410 */ 	lui	$t8,0xc410
/*    1fc4c:	371849d8 */ 	ori	$t8,$t8,0x49d8
/*    1fc50:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    1fc54:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    1fc58:	35ef031d */ 	ori	$t7,$t7,0x31d
/*    1fc5c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    1fc60:	03e00008 */ 	jr	$ra
/*    1fc64:	ac580004 */ 	sw	$t8,0x4($v0)
.L0001fc68:
/*    1fc68:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fc6c:	3c09c410 */ 	lui	$t1,0xc410
/*    1fc70:	352941c8 */ 	ori	$t1,$t1,0x41c8
/*    1fc74:	24590008 */ 	addiu	$t9,$v0,0x8
/*    1fc78:	ac99000c */ 	sw	$t9,0xc($a0)
/*    1fc7c:	ac490004 */ 	sw	$t1,0x4($v0)
/*    1fc80:	03e00008 */ 	jr	$ra
/*    1fc84:	ac480000 */ 	sw	$t0,0x0($v0)
.L0001fc88:
/*    1fc88:	50a0003f */ 	beqzl	$a1,.L0001fd88
/*    1fc8c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fc90:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fc94:	3c0be700 */ 	lui	$t3,0xe700
/*    1fc98:	3c0dba00 */ 	lui	$t5,0xba00
/*    1fc9c:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1fca0:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1fca4:	ac400004 */ 	sw	$zero,0x4($v0)
/*    1fca8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1fcac:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fcb0:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*    1fcb4:	3c0e0010 */ 	lui	$t6,0x10
/*    1fcb8:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    1fcbc:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    1fcc0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    1fcc4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    1fcc8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fccc:	3c18f800 */ 	lui	$t8,0xf800
/*    1fcd0:	3c09fb00 */ 	lui	$t1,0xfb00
/*    1fcd4:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    1fcd8:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    1fcdc:	ac580000 */ 	sw	$t8,0x0($v0)
/*    1fce0:	8c990038 */ 	lw	$t9,0x38($a0)
/*    1fce4:	3c0dfc26 */ 	lui	$t5,0xfc26
/*    1fce8:	3c0e1ffc */ 	lui	$t6,0x1ffc
/*    1fcec:	ac590004 */ 	sw	$t9,0x4($v0)
/*    1fcf0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fcf4:	35cefbf8 */ 	ori	$t6,$t6,0xfbf8
/*    1fcf8:	35ade804 */ 	ori	$t5,$t5,0xe804
/*    1fcfc:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1fd00:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1fd04:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1fd08:	8c8a0034 */ 	lw	$t2,0x34($a0)
/*    1fd0c:	3c19b900 */ 	lui	$t9,0xb900
/*    1fd10:	3739031d */ 	ori	$t9,$t9,0x31d
/*    1fd14:	314b00ff */ 	andi	$t3,$t2,0xff
/*    1fd18:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    1fd1c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fd20:	3c0ab900 */ 	lui	$t2,0xb900
/*    1fd24:	354a031d */ 	ori	$t2,$t2,0x31d
/*    1fd28:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    1fd2c:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    1fd30:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    1fd34:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    1fd38:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*    1fd3c:	51e0000a */ 	beqzl	$t7,.L0001fd68
/*    1fd40:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fd44:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fd48:	3c08c411 */ 	lui	$t0,0xc411
/*    1fd4c:	35083078 */ 	ori	$t0,$t0,0x3078
/*    1fd50:	24580008 */ 	addiu	$t8,$v0,0x8
/*    1fd54:	ac98000c */ 	sw	$t8,0xc($a0)
/*    1fd58:	ac480004 */ 	sw	$t0,0x4($v0)
/*    1fd5c:	03e00008 */ 	jr	$ra
/*    1fd60:	ac590000 */ 	sw	$t9,0x0($v0)
/*    1fd64:	8c82000c */ 	lw	$v0,0xc($a0)
.L0001fd68:
/*    1fd68:	3c0bc411 */ 	lui	$t3,0xc411
/*    1fd6c:	356b3048 */ 	ori	$t3,$t3,0x3048
/*    1fd70:	24490008 */ 	addiu	$t1,$v0,0x8
/*    1fd74:	ac89000c */ 	sw	$t1,0xc($a0)
/*    1fd78:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    1fd7c:	03e00008 */ 	jr	$ra
/*    1fd80:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    1fd84:	8c82000c */ 	lw	$v0,0xc($a0)
.L0001fd88:
/*    1fd88:	3c0dfa00 */ 	lui	$t5,0xfa00
/*    1fd8c:	3c09fc26 */ 	lui	$t1,0xfc26
/*    1fd90:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    1fd94:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    1fd98:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    1fd9c:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*    1fda0:	3c0a1fcc */ 	lui	$t2,0x1fcc
/*    1fda4:	354adff8 */ 	ori	$t2,$t2,0xdff8
/*    1fda8:	000ec202 */ 	srl	$t8,$t6,0x8
/*    1fdac:	331900ff */ 	andi	$t9,$t8,0xff
/*    1fdb0:	ac590004 */ 	sw	$t9,0x4($v0)
/*    1fdb4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fdb8:	3529c204 */ 	ori	$t1,$t1,0xc204
/*    1fdbc:	3c0db900 */ 	lui	$t5,0xb900
/*    1fdc0:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1fdc4:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1fdc8:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    1fdcc:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1fdd0:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*    1fdd4:	3c18b900 */ 	lui	$t8,0xb900
/*    1fdd8:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    1fddc:	11600009 */ 	beqz	$t3,.L0001fe04
/*    1fde0:	3718031d */ 	ori	$t8,$t8,0x31d
/*    1fde4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fde8:	3c0ec411 */ 	lui	$t6,0xc411
/*    1fdec:	35ce3078 */ 	ori	$t6,$t6,0x3078
/*    1fdf0:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    1fdf4:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    1fdf8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    1fdfc:	03e00008 */ 	jr	$ra
/*    1fe00:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0001fe04:
/*    1fe04:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fe08:	3c19c411 */ 	lui	$t9,0xc411
/*    1fe0c:	37393048 */ 	ori	$t9,$t9,0x3048
/*    1fe10:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    1fe14:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    1fe18:	ac590004 */ 	sw	$t9,0x4($v0)
/*    1fe1c:	03e00008 */ 	jr	$ra
/*    1fe20:	ac580000 */ 	sw	$t8,0x0($v0)
/*    1fe24:	24010004 */ 	addiu	$at,$zero,0x4
.L0001fe28:
/*    1fe28:	5441004e */ 	bnel	$v0,$at,.L0001ff64
/*    1fe2c:	24010005 */ 	addiu	$at,$zero,0x5
/*    1fe30:	50a00036 */ 	beqzl	$a1,.L0001ff0c
/*    1fe34:	8c980004 */ 	lw	$t8,0x4($a0)
/*    1fe38:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fe3c:	3c09e700 */ 	lui	$t1,0xe700
/*    1fe40:	3c0bba00 */ 	lui	$t3,0xba00
/*    1fe44:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1fe48:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1fe4c:	ac400004 */ 	sw	$zero,0x4($v0)
/*    1fe50:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1fe54:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fe58:	356b1402 */ 	ori	$t3,$t3,0x1402
/*    1fe5c:	3c0c0010 */ 	lui	$t4,0x10
/*    1fe60:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1fe64:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1fe68:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1fe6c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1fe70:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fe74:	3c0ef800 */ 	lui	$t6,0xf800
/*    1fe78:	3c081f10 */ 	lui	$t0,0x1f10
/*    1fe7c:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1fe80:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1fe84:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    1fe88:	8c8f0034 */ 	lw	$t7,0x34($a0)
/*    1fe8c:	3c19fc26 */ 	lui	$t9,0xfc26
/*    1fe90:	3739a004 */ 	ori	$t9,$t9,0xa004
/*    1fe94:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    1fe98:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fe9c:	350893ff */ 	ori	$t0,$t0,0x93ff
/*    1fea0:	3c0bb900 */ 	lui	$t3,0xb900
/*    1fea4:	24580008 */ 	addiu	$t8,$v0,0x8
/*    1fea8:	ac98000c */ 	sw	$t8,0xc($a0)
/*    1feac:	ac480004 */ 	sw	$t0,0x4($v0)
/*    1feb0:	ac590000 */ 	sw	$t9,0x0($v0)
/*    1feb4:	8c890004 */ 	lw	$t1,0x4($a0)
/*    1feb8:	3c0eb900 */ 	lui	$t6,0xb900
/*    1febc:	356b031d */ 	ori	$t3,$t3,0x31d
/*    1fec0:	11200009 */ 	beqz	$t1,.L0001fee8
/*    1fec4:	35ce031d */ 	ori	$t6,$t6,0x31d
/*    1fec8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1fecc:	3c0cc411 */ 	lui	$t4,0xc411
/*    1fed0:	358c2078 */ 	ori	$t4,$t4,0x2078
/*    1fed4:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1fed8:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1fedc:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1fee0:	03e00008 */ 	jr	$ra
/*    1fee4:	ac4b0000 */ 	sw	$t3,0x0($v0)
.L0001fee8:
/*    1fee8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1feec:	3c0fc411 */ 	lui	$t7,0xc411
/*    1fef0:	35ef2048 */ 	ori	$t7,$t7,0x2048
/*    1fef4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1fef8:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1fefc:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    1ff00:	03e00008 */ 	jr	$ra
/*    1ff04:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    1ff08:	8c980004 */ 	lw	$t8,0x4($a0)
.L0001ff0c:
/*    1ff0c:	3c0bb900 */ 	lui	$t3,0xb900
/*    1ff10:	3c08b900 */ 	lui	$t0,0xb900
/*    1ff14:	1300000a */ 	beqz	$t8,.L0001ff40
/*    1ff18:	356b031d */ 	ori	$t3,$t3,0x31d
/*    1ff1c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1ff20:	3c09c410 */ 	lui	$t1,0xc410
/*    1ff24:	352949d8 */ 	ori	$t1,$t1,0x49d8
/*    1ff28:	24590008 */ 	addiu	$t9,$v0,0x8
/*    1ff2c:	ac99000c */ 	sw	$t9,0xc($a0)
/*    1ff30:	3508031d */ 	ori	$t0,$t0,0x31d
/*    1ff34:	ac480000 */ 	sw	$t0,0x0($v0)
/*    1ff38:	03e00008 */ 	jr	$ra
/*    1ff3c:	ac490004 */ 	sw	$t1,0x4($v0)
.L0001ff40:
/*    1ff40:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1ff44:	3c0cc410 */ 	lui	$t4,0xc410
/*    1ff48:	358c41c8 */ 	ori	$t4,$t4,0x41c8
/*    1ff4c:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    1ff50:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    1ff54:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    1ff58:	03e00008 */ 	jr	$ra
/*    1ff5c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1ff60:	24010005 */ 	addiu	$at,$zero,0x5
.L0001ff64:
/*    1ff64:	14410073 */ 	bne	$v0,$at,.L00020134
/*    1ff68:	00000000 */ 	nop
/*    1ff6c:	50a0005a */ 	beqzl	$a1,.L000200d8
/*    1ff70:	8c8f0034 */ 	lw	$t7,0x34($a0)
/*    1ff74:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1ff78:	3c0ee700 */ 	lui	$t6,0xe700
/*    1ff7c:	3c18ba00 */ 	lui	$t8,0xba00
/*    1ff80:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1ff84:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1ff88:	ac400004 */ 	sw	$zero,0x4($v0)
/*    1ff8c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    1ff90:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1ff94:	37181402 */ 	ori	$t8,$t8,0x1402
/*    1ff98:	3c190010 */ 	lui	$t9,0x10
/*    1ff9c:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    1ffa0:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    1ffa4:	ac590004 */ 	sw	$t9,0x4($v0)
/*    1ffa8:	ac580000 */ 	sw	$t8,0x0($v0)
/*    1ffac:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1ffb0:	3c09f800 */ 	lui	$t1,0xf800
/*    1ffb4:	3c18fc26 */ 	lui	$t8,0xfc26
/*    1ffb8:	24480008 */ 	addiu	$t0,$v0,0x8
/*    1ffbc:	ac88000c */ 	sw	$t0,0xc($a0)
/*    1ffc0:	ac490000 */ 	sw	$t1,0x0($v0)
/*    1ffc4:	8c8a0038 */ 	lw	$t2,0x38($a0)
/*    1ffc8:	3c0efb00 */ 	lui	$t6,0xfb00
/*    1ffcc:	3718a004 */ 	ori	$t8,$t8,0xa004
/*    1ffd0:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    1ffd4:	8c8b0034 */ 	lw	$t3,0x34($a0)
/*    1ffd8:	316c00ff */ 	andi	$t4,$t3,0xff
/*    1ffdc:	298100ff */ 	slti	$at,$t4,0xff
/*    1ffe0:	1020001f */ 	beqz	$at,.L00020060
/*    1ffe4:	318f00ff */ 	andi	$t7,$t4,0xff
/*    1ffe8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    1ffec:	2401ff00 */ 	addiu	$at,$zero,-256
/*    1fff0:	01e1c025 */ 	or	$t8,$t7,$at
/*    1fff4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    1fff8:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    1fffc:	ac580004 */ 	sw	$t8,0x4($v0)
/*    20000:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20004:	8c990034 */ 	lw	$t9,0x34($a0)
/*    20008:	3c0dfc26 */ 	lui	$t5,0xfc26
/*    2000c:	3c0afc26 */ 	lui	$t2,0xfc26
/*    20010:	3328ff00 */ 	andi	$t0,$t9,0xff00
/*    20014:	1100000a */ 	beqz	$t0,.L00020040
/*    20018:	35adea04 */ 	ori	$t5,$t5,0xea04
/*    2001c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20020:	3c0b1f10 */ 	lui	$t3,0x1f10
/*    20024:	356bcfff */ 	ori	$t3,$t3,0xcfff
/*    20028:	24490008 */ 	addiu	$t1,$v0,0x8
/*    2002c:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20030:	354aea04 */ 	ori	$t2,$t2,0xea04
/*    20034:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    20038:	10000010 */ 	b	.L0002007c
/*    2003c:	ac4b0004 */ 	sw	$t3,0x4($v0)
.L00020040:
/*    20040:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20044:	3c0e1f10 */ 	lui	$t6,0x1f10
/*    20048:	35ceffff */ 	ori	$t6,$t6,0xffff
/*    2004c:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    20050:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    20054:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    20058:	10000008 */ 	b	.L0002007c
/*    2005c:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L00020060:
/*    20060:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20064:	3c191f10 */ 	lui	$t9,0x1f10
/*    20068:	373993ff */ 	ori	$t9,$t9,0x93ff
/*    2006c:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20070:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20074:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20078:	ac580000 */ 	sw	$t8,0x0($v0)
.L0002007c:
/*    2007c:	8c880004 */ 	lw	$t0,0x4($a0)
/*    20080:	3c0db900 */ 	lui	$t5,0xb900
/*    20084:	3c0ab900 */ 	lui	$t2,0xb900
/*    20088:	1100000a */ 	beqz	$t0,.L000200b4
/*    2008c:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    20090:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20094:	3c0bc410 */ 	lui	$t3,0xc410
/*    20098:	356b49d8 */ 	ori	$t3,$t3,0x49d8
/*    2009c:	24490008 */ 	addiu	$t1,$v0,0x8
/*    200a0:	ac89000c */ 	sw	$t1,0xc($a0)
/*    200a4:	354a031d */ 	ori	$t2,$t2,0x31d
/*    200a8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    200ac:	03e00008 */ 	jr	$ra
/*    200b0:	ac4b0004 */ 	sw	$t3,0x4($v0)
.L000200b4:
/*    200b4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    200b8:	3c0ec410 */ 	lui	$t6,0xc410
/*    200bc:	35ce41c8 */ 	ori	$t6,$t6,0x41c8
/*    200c0:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    200c4:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    200c8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    200cc:	03e00008 */ 	jr	$ra
/*    200d0:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    200d4:	8c8f0034 */ 	lw	$t7,0x34($a0)
.L000200d8:
/*    200d8:	3c0bfc26 */ 	lui	$t3,0xfc26
/*    200dc:	3c08fc26 */ 	lui	$t0,0xfc26
/*    200e0:	31f800ff */ 	andi	$t8,$t7,0xff
/*    200e4:	2b0100ff */ 	slti	$at,$t8,0xff
/*    200e8:	1020000a */ 	beqz	$at,.L00020114
/*    200ec:	356ba004 */ 	ori	$t3,$t3,0xa004
/*    200f0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    200f4:	3c091f10 */ 	lui	$t1,0x1f10
/*    200f8:	3529ffff */ 	ori	$t1,$t1,0xffff
/*    200fc:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20100:	ac99000c */ 	sw	$t9,0xc($a0)
/*    20104:	35089a04 */ 	ori	$t0,$t0,0x9a04
/*    20108:	ac480000 */ 	sw	$t0,0x0($v0)
/*    2010c:	03e00008 */ 	jr	$ra
/*    20110:	ac490004 */ 	sw	$t1,0x4($v0)
.L00020114:
/*    20114:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20118:	3c0c1f10 */ 	lui	$t4,0x1f10
/*    2011c:	358c93ff */ 	ori	$t4,$t4,0x93ff
/*    20120:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    20124:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    20128:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    2012c:	03e00008 */ 	jr	$ra
/*    20130:	ac4b0000 */ 	sw	$t3,0x0($v0)
.L00020134:
/*    20134:	10a0002d */ 	beqz	$a1,.L000201ec
/*    20138:	3c0ee700 */ 	lui	$t6,0xe700
/*    2013c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20140:	3c18ba00 */ 	lui	$t8,0xba00
/*    20144:	37181402 */ 	ori	$t8,$t8,0x1402
/*    20148:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    2014c:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20150:	ac400004 */ 	sw	$zero,0x4($v0)
/*    20154:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20158:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2015c:	3c190010 */ 	lui	$t9,0x10
/*    20160:	3c09fc26 */ 	lui	$t1,0xfc26
/*    20164:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20168:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    2016c:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20170:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20174:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20178:	3c0a1f10 */ 	lui	$t2,0x1f10
/*    2017c:	354a93ff */ 	ori	$t2,$t2,0x93ff
/*    20180:	24480008 */ 	addiu	$t0,$v0,0x8
/*    20184:	ac88000c */ 	sw	$t0,0xc($a0)
/*    20188:	3529a004 */ 	ori	$t1,$t1,0xa004
/*    2018c:	ac490000 */ 	sw	$t1,0x0($v0)
/*    20190:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    20194:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*    20198:	3c18b900 */ 	lui	$t8,0xb900
/*    2019c:	3c0db900 */ 	lui	$t5,0xb900
/*    201a0:	1160000a */ 	beqz	$t3,.L000201cc
/*    201a4:	3718031d */ 	ori	$t8,$t8,0x31d
/*    201a8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    201ac:	3c0e0c19 */ 	lui	$t6,0xc19
/*    201b0:	35ce2078 */ 	ori	$t6,$t6,0x2078
/*    201b4:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    201b8:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    201bc:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    201c0:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    201c4:	03e00008 */ 	jr	$ra
/*    201c8:	ac4e0004 */ 	sw	$t6,0x4($v0)
.L000201cc:
/*    201cc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    201d0:	3c190c19 */ 	lui	$t9,0xc19
/*    201d4:	37392048 */ 	ori	$t9,$t9,0x2048
/*    201d8:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    201dc:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    201e0:	ac590004 */ 	sw	$t9,0x4($v0)
/*    201e4:	03e00008 */ 	jr	$ra
/*    201e8:	ac580000 */ 	sw	$t8,0x0($v0)
.L000201ec:
/*    201ec:	8c880004 */ 	lw	$t0,0x4($a0)
/*    201f0:	3c0db900 */ 	lui	$t5,0xb900
/*    201f4:	3c0ab900 */ 	lui	$t2,0xb900
/*    201f8:	1100000a */ 	beqz	$t0,.L00020224
/*    201fc:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    20200:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20204:	3c0b0c18 */ 	lui	$t3,0xc18
/*    20208:	356b49d8 */ 	ori	$t3,$t3,0x49d8
/*    2020c:	24490008 */ 	addiu	$t1,$v0,0x8
/*    20210:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20214:	354a031d */ 	ori	$t2,$t2,0x31d
/*    20218:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    2021c:	03e00008 */ 	jr	$ra
/*    20220:	ac4b0004 */ 	sw	$t3,0x4($v0)
.L00020224:
/*    20224:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20228:	3c0e0c18 */ 	lui	$t6,0xc18
/*    2022c:	35ce41c8 */ 	ori	$t6,$t6,0x41c8
/*    20230:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    20234:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    20238:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    2023c:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L00020240:
/*    20240:	03e00008 */ 	jr	$ra
/*    20244:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00020248
/*    20248:	8c820030 */ 	lw	$v0,0x30($a0)
/*    2024c:	24010007 */ 	addiu	$at,$zero,0x7
/*    20250:	54410055 */ 	bnel	$v0,$at,.L000203a8
/*    20254:	24010008 */ 	addiu	$at,$zero,0x8
/*    20258:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2025c:	3c0fe700 */ 	lui	$t7,0xe700
/*    20260:	3c19ba00 */ 	lui	$t9,0xba00
/*    20264:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20268:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    2026c:	ac400004 */ 	sw	$zero,0x4($v0)
/*    20270:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    20274:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20278:	37391402 */ 	ori	$t9,$t9,0x1402
/*    2027c:	3c090010 */ 	lui	$t1,0x10
/*    20280:	24580008 */ 	addiu	$t8,$v0,0x8
/*    20284:	ac98000c */ 	sw	$t8,0xc($a0)
/*    20288:	ac490004 */ 	sw	$t1,0x4($v0)
/*    2028c:	ac590000 */ 	sw	$t9,0x0($v0)
/*    20290:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20294:	3c0bf800 */ 	lui	$t3,0xf800
/*    20298:	3c0efb00 */ 	lui	$t6,0xfb00
/*    2029c:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    202a0:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    202a4:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    202a8:	8c8c0038 */ 	lw	$t4,0x38($a0)
/*    202ac:	3c0a5ffe */ 	lui	$t2,0x5ffe
/*    202b0:	3c09fc15 */ 	lui	$t1,0xfc15
/*    202b4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    202b8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    202bc:	35299804 */ 	ori	$t1,$t1,0x9804
/*    202c0:	354adbf8 */ 	ori	$t2,$t2,0xdbf8
/*    202c4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    202c8:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    202cc:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    202d0:	8c8f0034 */ 	lw	$t7,0x34($a0)
/*    202d4:	35f800ff */ 	ori	$t8,$t7,0xff
/*    202d8:	ac580004 */ 	sw	$t8,0x4($v0)
/*    202dc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    202e0:	24590008 */ 	addiu	$t9,$v0,0x8
/*    202e4:	ac99000c */ 	sw	$t9,0xc($a0)
/*    202e8:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    202ec:	10a00017 */ 	beqz	$a1,.L0002034c
/*    202f0:	ac490000 */ 	sw	$t1,0x0($v0)
/*    202f4:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*    202f8:	3c18b900 */ 	lui	$t8,0xb900
/*    202fc:	3c0db900 */ 	lui	$t5,0xb900
/*    20300:	1160000a */ 	beqz	$t3,.L0002032c
/*    20304:	3718031d */ 	ori	$t8,$t8,0x31d
/*    20308:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2030c:	3c0ec411 */ 	lui	$t6,0xc411
/*    20310:	35ce2078 */ 	ori	$t6,$t6,0x2078
/*    20314:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    20318:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    2031c:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    20320:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    20324:	03e00008 */ 	jr	$ra
/*    20328:	ac4e0004 */ 	sw	$t6,0x4($v0)
.L0002032c:
/*    2032c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20330:	3c19c411 */ 	lui	$t9,0xc411
/*    20334:	37392048 */ 	ori	$t9,$t9,0x2048
/*    20338:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    2033c:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20340:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20344:	03e00008 */ 	jr	$ra
/*    20348:	ac580000 */ 	sw	$t8,0x0($v0)
.L0002034c:
/*    2034c:	8c890004 */ 	lw	$t1,0x4($a0)
/*    20350:	3c0eb900 */ 	lui	$t6,0xb900
/*    20354:	3c0bb900 */ 	lui	$t3,0xb900
/*    20358:	1120000a */ 	beqz	$t1,.L00020384
/*    2035c:	35ce031d */ 	ori	$t6,$t6,0x31d
/*    20360:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20364:	3c0cc410 */ 	lui	$t4,0xc410
/*    20368:	358c49d8 */ 	ori	$t4,$t4,0x49d8
/*    2036c:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    20370:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    20374:	356b031d */ 	ori	$t3,$t3,0x31d
/*    20378:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    2037c:	03e00008 */ 	jr	$ra
/*    20380:	ac4c0004 */ 	sw	$t4,0x4($v0)
.L00020384:
/*    20384:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20388:	3c0fc410 */ 	lui	$t7,0xc410
/*    2038c:	35ef41c8 */ 	ori	$t7,$t7,0x41c8
/*    20390:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    20394:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20398:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    2039c:	03e00008 */ 	jr	$ra
/*    203a0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    203a4:	24010008 */ 	addiu	$at,$zero,0x8
.L000203a8:
/*    203a8:	5441003e */ 	bnel	$v0,$at,.L000204a4
/*    203ac:	24010009 */ 	addiu	$at,$zero,0x9
/*    203b0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    203b4:	3c19e700 */ 	lui	$t9,0xe700
/*    203b8:	3c0aba00 */ 	lui	$t2,0xba00
/*    203bc:	24580008 */ 	addiu	$t8,$v0,0x8
/*    203c0:	ac98000c */ 	sw	$t8,0xc($a0)
/*    203c4:	ac400004 */ 	sw	$zero,0x4($v0)
/*    203c8:	ac590000 */ 	sw	$t9,0x0($v0)
/*    203cc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    203d0:	354a1402 */ 	ori	$t2,$t2,0x1402
/*    203d4:	3c0b0010 */ 	lui	$t3,0x10
/*    203d8:	24490008 */ 	addiu	$t1,$v0,0x8
/*    203dc:	ac89000c */ 	sw	$t1,0xc($a0)
/*    203e0:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    203e4:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    203e8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    203ec:	3c0df800 */ 	lui	$t5,0xf800
/*    203f0:	3c18fb00 */ 	lui	$t8,0xfb00
/*    203f4:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    203f8:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    203fc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    20400:	8c8e0038 */ 	lw	$t6,0x38($a0)
/*    20404:	3c0afc15 */ 	lui	$t2,0xfc15
/*    20408:	3c0b5ffe */ 	lui	$t3,0x5ffe
/*    2040c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    20410:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20414:	356bfff8 */ 	ori	$t3,$t3,0xfff8
/*    20418:	354a9a04 */ 	ori	$t2,$t2,0x9a04
/*    2041c:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20420:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20424:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20428:	8c990034 */ 	lw	$t9,0x34($a0)
/*    2042c:	3c0eb900 */ 	lui	$t6,0xb900
/*    20430:	35ce031d */ 	ori	$t6,$t6,0x31d
/*    20434:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20438:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2043c:	3c19b900 */ 	lui	$t9,0xb900
/*    20440:	3739031d */ 	ori	$t9,$t9,0x31d
/*    20444:	24490008 */ 	addiu	$t1,$v0,0x8
/*    20448:	ac89000c */ 	sw	$t1,0xc($a0)
/*    2044c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    20450:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    20454:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*    20458:	5180000a */ 	beqzl	$t4,.L00020484
/*    2045c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20460:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20464:	3c0fc410 */ 	lui	$t7,0xc410
/*    20468:	35ef49d8 */ 	ori	$t7,$t7,0x49d8
/*    2046c:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    20470:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20474:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    20478:	03e00008 */ 	jr	$ra
/*    2047c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20480:	8c82000c */ 	lw	$v0,0xc($a0)
.L00020484:
/*    20484:	3c09c410 */ 	lui	$t1,0xc410
/*    20488:	352941c8 */ 	ori	$t1,$t1,0x41c8
/*    2048c:	24580008 */ 	addiu	$t8,$v0,0x8
/*    20490:	ac98000c */ 	sw	$t8,0xc($a0)
/*    20494:	ac490004 */ 	sw	$t1,0x4($v0)
/*    20498:	03e00008 */ 	jr	$ra
/*    2049c:	ac590000 */ 	sw	$t9,0x0($v0)
/*    204a0:	24010009 */ 	addiu	$at,$zero,0x9
.L000204a4:
/*    204a4:	544100cf */ 	bnel	$v0,$at,.L000207e4
/*    204a8:	24010004 */ 	addiu	$at,$zero,0x4
/*    204ac:	8c8a0034 */ 	lw	$t2,0x34($a0)
/*    204b0:	314b00ff */ 	andi	$t3,$t2,0xff
/*    204b4:	55600066 */ 	bnezl	$t3,.L00020650
/*    204b8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    204bc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    204c0:	3c0de700 */ 	lui	$t5,0xe700
/*    204c4:	3c0fba00 */ 	lui	$t7,0xba00
/*    204c8:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    204cc:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    204d0:	ac400004 */ 	sw	$zero,0x4($v0)
/*    204d4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    204d8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    204dc:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*    204e0:	3c180010 */ 	lui	$t8,0x10
/*    204e4:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    204e8:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    204ec:	ac580004 */ 	sw	$t8,0x4($v0)
/*    204f0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    204f4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    204f8:	3c09f800 */ 	lui	$t1,0xf800
/*    204fc:	240dffff */ 	addiu	$t5,$zero,-1
/*    20500:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20504:	ac99000c */ 	sw	$t9,0xc($a0)
/*    20508:	ac490000 */ 	sw	$t1,0x0($v0)
/*    2050c:	8c8a0038 */ 	lw	$t2,0x38($a0)
/*    20510:	3c0cfb00 */ 	lui	$t4,0xfb00
/*    20514:	3c0ffa00 */ 	lui	$t7,0xfa00
/*    20518:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    2051c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20520:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    20524:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    20528:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    2052c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    20530:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20534:	3c0cfc26 */ 	lui	$t4,0xfc26
/*    20538:	3c0dfc26 */ 	lui	$t5,0xfc26
/*    2053c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20540:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20544:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    20548:	8c980034 */ 	lw	$t8,0x34($a0)
/*    2054c:	358ca004 */ 	ori	$t4,$t4,0xa004
/*    20550:	35ada004 */ 	ori	$t5,$t5,0xa004
/*    20554:	00184a02 */ 	srl	$t1,$t8,0x8
/*    20558:	312a00ff */ 	andi	$t2,$t1,0xff
/*    2055c:	10a0001e */ 	beqz	$a1,.L000205d8
/*    20560:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    20564:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20568:	3c0d1f10 */ 	lui	$t5,0x1f10
/*    2056c:	35ad93fb */ 	ori	$t5,$t5,0x93fb
/*    20570:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    20574:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    20578:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    2057c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    20580:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*    20584:	3c0ab900 */ 	lui	$t2,0xb900
/*    20588:	3c18b900 */ 	lui	$t8,0xb900
/*    2058c:	11c0000a */ 	beqz	$t6,.L000205b8
/*    20590:	354a031d */ 	ori	$t2,$t2,0x31d
/*    20594:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20598:	3c19c411 */ 	lui	$t9,0xc411
/*    2059c:	37392078 */ 	ori	$t9,$t9,0x2078
/*    205a0:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    205a4:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    205a8:	3718031d */ 	ori	$t8,$t8,0x31d
/*    205ac:	ac580000 */ 	sw	$t8,0x0($v0)
/*    205b0:	03e00008 */ 	jr	$ra
/*    205b4:	ac590004 */ 	sw	$t9,0x4($v0)
.L000205b8:
/*    205b8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    205bc:	3c0bc411 */ 	lui	$t3,0xc411
/*    205c0:	356b2048 */ 	ori	$t3,$t3,0x2048
/*    205c4:	24490008 */ 	addiu	$t1,$v0,0x8
/*    205c8:	ac89000c */ 	sw	$t1,0xc($a0)
/*    205cc:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    205d0:	03e00008 */ 	jr	$ra
/*    205d4:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L000205d8:
/*    205d8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    205dc:	3c0e1f10 */ 	lui	$t6,0x1f10
/*    205e0:	35ce93fb */ 	ori	$t6,$t6,0x93fb
/*    205e4:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    205e8:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    205ec:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    205f0:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    205f4:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*    205f8:	3c0bb900 */ 	lui	$t3,0xb900
/*    205fc:	3c19b900 */ 	lui	$t9,0xb900
/*    20600:	11e0000a */ 	beqz	$t7,.L0002062c
/*    20604:	356b031d */ 	ori	$t3,$t3,0x31d
/*    20608:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2060c:	3c09c410 */ 	lui	$t1,0xc410
/*    20610:	352949d8 */ 	ori	$t1,$t1,0x49d8
/*    20614:	24580008 */ 	addiu	$t8,$v0,0x8
/*    20618:	ac98000c */ 	sw	$t8,0xc($a0)
/*    2061c:	3739031d */ 	ori	$t9,$t9,0x31d
/*    20620:	ac590000 */ 	sw	$t9,0x0($v0)
/*    20624:	03e00008 */ 	jr	$ra
/*    20628:	ac490004 */ 	sw	$t1,0x4($v0)
.L0002062c:
/*    2062c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20630:	3c0cc410 */ 	lui	$t4,0xc410
/*    20634:	358c41c8 */ 	ori	$t4,$t4,0x41c8
/*    20638:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    2063c:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    20640:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    20644:	03e00008 */ 	jr	$ra
/*    20648:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    2064c:	8c82000c */ 	lw	$v0,0xc($a0)
.L00020650:
/*    20650:	3c0ee700 */ 	lui	$t6,0xe700
/*    20654:	3c18ba00 */ 	lui	$t8,0xba00
/*    20658:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    2065c:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20660:	ac400004 */ 	sw	$zero,0x4($v0)
/*    20664:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20668:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2066c:	37181402 */ 	ori	$t8,$t8,0x1402
/*    20670:	3c190010 */ 	lui	$t9,0x10
/*    20674:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20678:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    2067c:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20680:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20684:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20688:	3c0af800 */ 	lui	$t2,0xf800
/*    2068c:	3c0dfb00 */ 	lui	$t5,0xfb00
/*    20690:	24490008 */ 	addiu	$t1,$v0,0x8
/*    20694:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20698:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    2069c:	8c8b0038 */ 	lw	$t3,0x38($a0)
/*    206a0:	3c19fc26 */ 	lui	$t9,0xfc26
/*    206a4:	3739e804 */ 	ori	$t9,$t9,0xe804
/*    206a8:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    206ac:	8c82000c */ 	lw	$v0,0xc($a0)
/*    206b0:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    206b4:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    206b8:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    206bc:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*    206c0:	31cf00ff */ 	andi	$t7,$t6,0xff
/*    206c4:	10a0001e */ 	beqz	$a1,.L00020740
/*    206c8:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*    206cc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    206d0:	3c091ffc */ 	lui	$t1,0x1ffc
/*    206d4:	3529fbf8 */ 	ori	$t1,$t1,0xfbf8
/*    206d8:	24580008 */ 	addiu	$t8,$v0,0x8
/*    206dc:	ac98000c */ 	sw	$t8,0xc($a0)
/*    206e0:	ac490004 */ 	sw	$t1,0x4($v0)
/*    206e4:	ac590000 */ 	sw	$t9,0x0($v0)
/*    206e8:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*    206ec:	3c0fb900 */ 	lui	$t7,0xb900
/*    206f0:	3c0cb900 */ 	lui	$t4,0xb900
/*    206f4:	1140000a */ 	beqz	$t2,.L00020720
/*    206f8:	35ef031d */ 	ori	$t7,$t7,0x31d
/*    206fc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20700:	3c0dc411 */ 	lui	$t5,0xc411
/*    20704:	35ad3078 */ 	ori	$t5,$t5,0x3078
/*    20708:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    2070c:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    20710:	358c031d */ 	ori	$t4,$t4,0x31d
/*    20714:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    20718:	03e00008 */ 	jr	$ra
/*    2071c:	ac4d0004 */ 	sw	$t5,0x4($v0)
.L00020720:
/*    20720:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20724:	3c18c411 */ 	lui	$t8,0xc411
/*    20728:	37183048 */ 	ori	$t8,$t8,0x3048
/*    2072c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20730:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20734:	ac580004 */ 	sw	$t8,0x4($v0)
/*    20738:	03e00008 */ 	jr	$ra
/*    2073c:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L00020740:
/*    20740:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20744:	3c09fa00 */ 	lui	$t1,0xfa00
/*    20748:	3c0ffc26 */ 	lui	$t7,0xfc26
/*    2074c:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20750:	ac99000c */ 	sw	$t9,0xc($a0)
/*    20754:	ac490000 */ 	sw	$t1,0x0($v0)
/*    20758:	8c8a0034 */ 	lw	$t2,0x34($a0)
/*    2075c:	3c181fcc */ 	lui	$t8,0x1fcc
/*    20760:	3718dff8 */ 	ori	$t8,$t8,0xdff8
/*    20764:	000a6202 */ 	srl	$t4,$t2,0x8
/*    20768:	318d00ff */ 	andi	$t5,$t4,0xff
/*    2076c:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    20770:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20774:	35efc204 */ 	ori	$t7,$t7,0xc204
/*    20778:	3c0ab900 */ 	lui	$t2,0xb900
/*    2077c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20780:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20784:	ac580004 */ 	sw	$t8,0x4($v0)
/*    20788:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    2078c:	8c990004 */ 	lw	$t9,0x4($a0)
/*    20790:	3c0db900 */ 	lui	$t5,0xb900
/*    20794:	354a031d */ 	ori	$t2,$t2,0x31d
/*    20798:	13200009 */ 	beqz	$t9,.L000207c0
/*    2079c:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    207a0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    207a4:	3c0bc411 */ 	lui	$t3,0xc411
/*    207a8:	356b3078 */ 	ori	$t3,$t3,0x3078
/*    207ac:	24490008 */ 	addiu	$t1,$v0,0x8
/*    207b0:	ac89000c */ 	sw	$t1,0xc($a0)
/*    207b4:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    207b8:	03e00008 */ 	jr	$ra
/*    207bc:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L000207c0:
/*    207c0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    207c4:	3c0ec411 */ 	lui	$t6,0xc411
/*    207c8:	35ce3048 */ 	ori	$t6,$t6,0x3048
/*    207cc:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    207d0:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    207d4:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    207d8:	03e00008 */ 	jr	$ra
/*    207dc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    207e0:	24010004 */ 	addiu	$at,$zero,0x4
.L000207e4:
/*    207e4:	5441004d */ 	bnel	$v0,$at,.L0002091c
/*    207e8:	24010005 */ 	addiu	$at,$zero,0x5
/*    207ec:	8c82000c */ 	lw	$v0,0xc($a0)
/*    207f0:	3c18e700 */ 	lui	$t8,0xe700
/*    207f4:	3c09ba00 */ 	lui	$t1,0xba00
/*    207f8:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    207fc:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20800:	ac400004 */ 	sw	$zero,0x4($v0)
/*    20804:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20808:	8c82000c */ 	lw	$v0,0xc($a0)
/*    2080c:	35291402 */ 	ori	$t1,$t1,0x1402
/*    20810:	3c0a0010 */ 	lui	$t2,0x10
/*    20814:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20818:	ac99000c */ 	sw	$t9,0xc($a0)
/*    2081c:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    20820:	ac490000 */ 	sw	$t1,0x0($v0)
/*    20824:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20828:	3c0cf800 */ 	lui	$t4,0xf800
/*    2082c:	3c181f10 */ 	lui	$t8,0x1f10
/*    20830:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    20834:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    20838:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    2083c:	8c8d0034 */ 	lw	$t5,0x34($a0)
/*    20840:	3c0ffc26 */ 	lui	$t7,0xfc26
/*    20844:	35efa004 */ 	ori	$t7,$t7,0xa004
/*    20848:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    2084c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20850:	371893ff */ 	ori	$t8,$t8,0x93ff
/*    20854:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20858:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    2085c:	ac580004 */ 	sw	$t8,0x4($v0)
/*    20860:	10a00017 */ 	beqz	$a1,.L000208c0
/*    20864:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    20868:	8c990004 */ 	lw	$t9,0x4($a0)
/*    2086c:	3c0db900 */ 	lui	$t5,0xb900
/*    20870:	3c0ab900 */ 	lui	$t2,0xb900
/*    20874:	1320000a */ 	beqz	$t9,.L000208a0
/*    20878:	35ad031d */ 	ori	$t5,$t5,0x31d
/*    2087c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20880:	3c0bc411 */ 	lui	$t3,0xc411
/*    20884:	356b2078 */ 	ori	$t3,$t3,0x2078
/*    20888:	24490008 */ 	addiu	$t1,$v0,0x8
/*    2088c:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20890:	354a031d */ 	ori	$t2,$t2,0x31d
/*    20894:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    20898:	03e00008 */ 	jr	$ra
/*    2089c:	ac4b0004 */ 	sw	$t3,0x4($v0)
.L000208a0:
/*    208a0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    208a4:	3c0ec411 */ 	lui	$t6,0xc411
/*    208a8:	35ce2048 */ 	ori	$t6,$t6,0x2048
/*    208ac:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    208b0:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    208b4:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*    208b8:	03e00008 */ 	jr	$ra
/*    208bc:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L000208c0:
/*    208c0:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*    208c4:	3c0bb900 */ 	lui	$t3,0xb900
/*    208c8:	3c19b900 */ 	lui	$t9,0xb900
/*    208cc:	11e0000a */ 	beqz	$t7,.L000208f8
/*    208d0:	356b031d */ 	ori	$t3,$t3,0x31d
/*    208d4:	8c82000c */ 	lw	$v0,0xc($a0)
/*    208d8:	3c09c410 */ 	lui	$t1,0xc410
/*    208dc:	352949d8 */ 	ori	$t1,$t1,0x49d8
/*    208e0:	24580008 */ 	addiu	$t8,$v0,0x8
/*    208e4:	ac98000c */ 	sw	$t8,0xc($a0)
/*    208e8:	3739031d */ 	ori	$t9,$t9,0x31d
/*    208ec:	ac590000 */ 	sw	$t9,0x0($v0)
/*    208f0:	03e00008 */ 	jr	$ra
/*    208f4:	ac490004 */ 	sw	$t1,0x4($v0)
.L000208f8:
/*    208f8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    208fc:	3c0cc410 */ 	lui	$t4,0xc410
/*    20900:	358c41c8 */ 	ori	$t4,$t4,0x41c8
/*    20904:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    20908:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    2090c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    20910:	03e00008 */ 	jr	$ra
/*    20914:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    20918:	24010005 */ 	addiu	$at,$zero,0x5
.L0002091c:
/*    2091c:	14410064 */ 	bne	$v0,$at,.L00020ab0
/*    20920:	3c0de700 */ 	lui	$t5,0xe700
/*    20924:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20928:	3c0ee700 */ 	lui	$t6,0xe700
/*    2092c:	3c18ba00 */ 	lui	$t8,0xba00
/*    20930:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    20934:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20938:	ac400004 */ 	sw	$zero,0x4($v0)
/*    2093c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20940:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20944:	37181402 */ 	ori	$t8,$t8,0x1402
/*    20948:	3c190010 */ 	lui	$t9,0x10
/*    2094c:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20950:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20954:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20958:	ac580000 */ 	sw	$t8,0x0($v0)
/*    2095c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20960:	3c0af800 */ 	lui	$t2,0xf800
/*    20964:	3c0ffb00 */ 	lui	$t7,0xfb00
/*    20968:	24490008 */ 	addiu	$t1,$v0,0x8
/*    2096c:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20970:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    20974:	8c8b0038 */ 	lw	$t3,0x38($a0)
/*    20978:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    2097c:	8c8c0034 */ 	lw	$t4,0x34($a0)
/*    20980:	318d00ff */ 	andi	$t5,$t4,0xff
/*    20984:	29a100ff */ 	slti	$at,$t5,0xff
/*    20988:	1020002b */ 	beqz	$at,.L00020a38
/*    2098c:	3c0cfc26 */ 	lui	$t4,0xfc26
/*    20990:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20994:	31b800ff */ 	andi	$t8,$t5,0xff
/*    20998:	2401ff00 */ 	addiu	$at,$zero,-256
/*    2099c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    209a0:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    209a4:	0301c825 */ 	or	$t9,$t8,$at
/*    209a8:	ac590004 */ 	sw	$t9,0x4($v0)
/*    209ac:	10a00018 */ 	beqz	$a1,.L00020a10
/*    209b0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    209b4:	8c890034 */ 	lw	$t1,0x34($a0)
/*    209b8:	3c0ffc26 */ 	lui	$t7,0xfc26
/*    209bc:	3c0cfc26 */ 	lui	$t4,0xfc26
/*    209c0:	312aff00 */ 	andi	$t2,$t1,0xff00
/*    209c4:	1140000a */ 	beqz	$t2,.L000209f0
/*    209c8:	35efea04 */ 	ori	$t7,$t7,0xea04
/*    209cc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    209d0:	3c0d1f10 */ 	lui	$t5,0x1f10
/*    209d4:	35adcfff */ 	ori	$t5,$t5,0xcfff
/*    209d8:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    209dc:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    209e0:	358cea04 */ 	ori	$t4,$t4,0xea04
/*    209e4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    209e8:	1000001b */ 	b	.L00020a58
/*    209ec:	ac4d0004 */ 	sw	$t5,0x4($v0)
.L000209f0:
/*    209f0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    209f4:	3c181f10 */ 	lui	$t8,0x1f10
/*    209f8:	3718ffff */ 	ori	$t8,$t8,0xffff
/*    209fc:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20a00:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20a04:	ac580004 */ 	sw	$t8,0x4($v0)
/*    20a08:	10000013 */ 	b	.L00020a58
/*    20a0c:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L00020a10:
/*    20a10:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20a14:	3c09fc26 */ 	lui	$t1,0xfc26
/*    20a18:	3c0a1f10 */ 	lui	$t2,0x1f10
/*    20a1c:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20a20:	ac99000c */ 	sw	$t9,0xc($a0)
/*    20a24:	354affff */ 	ori	$t2,$t2,0xffff
/*    20a28:	35299a04 */ 	ori	$t1,$t1,0x9a04
/*    20a2c:	ac490000 */ 	sw	$t1,0x0($v0)
/*    20a30:	10000009 */ 	b	.L00020a58
/*    20a34:	ac4a0004 */ 	sw	$t2,0x4($v0)
.L00020a38:
/*    20a38:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20a3c:	3c0d1f10 */ 	lui	$t5,0x1f10
/*    20a40:	35ad93ff */ 	ori	$t5,$t5,0x93ff
/*    20a44:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    20a48:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    20a4c:	358ca004 */ 	ori	$t4,$t4,0xa004
/*    20a50:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    20a54:	ac4d0004 */ 	sw	$t5,0x4($v0)
.L00020a58:
/*    20a58:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*    20a5c:	3c0ab900 */ 	lui	$t2,0xb900
/*    20a60:	3c18b900 */ 	lui	$t8,0xb900
/*    20a64:	11c0000a */ 	beqz	$t6,.L00020a90
/*    20a68:	354a031d */ 	ori	$t2,$t2,0x31d
/*    20a6c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20a70:	3c19c410 */ 	lui	$t9,0xc410
/*    20a74:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*    20a78:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20a7c:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20a80:	3718031d */ 	ori	$t8,$t8,0x31d
/*    20a84:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20a88:	03e00008 */ 	jr	$ra
/*    20a8c:	ac590004 */ 	sw	$t9,0x4($v0)
.L00020a90:
/*    20a90:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20a94:	3c0bc410 */ 	lui	$t3,0xc410
/*    20a98:	356b41c8 */ 	ori	$t3,$t3,0x41c8
/*    20a9c:	24490008 */ 	addiu	$t1,$v0,0x8
/*    20aa0:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20aa4:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    20aa8:	03e00008 */ 	jr	$ra
/*    20aac:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L00020ab0:
/*    20ab0:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20ab4:	3c0fba00 */ 	lui	$t7,0xba00
/*    20ab8:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*    20abc:	244c0008 */ 	addiu	$t4,$v0,0x8
/*    20ac0:	ac8c000c */ 	sw	$t4,0xc($a0)
/*    20ac4:	ac400004 */ 	sw	$zero,0x4($v0)
/*    20ac8:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    20acc:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20ad0:	3c180010 */ 	lui	$t8,0x10
/*    20ad4:	3c09f800 */ 	lui	$t1,0xf800
/*    20ad8:	244e0008 */ 	addiu	$t6,$v0,0x8
/*    20adc:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20ae0:	ac580004 */ 	sw	$t8,0x4($v0)
/*    20ae4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    20ae8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20aec:	240aff00 */ 	addiu	$t2,$zero,-256
/*    20af0:	3c0d1f10 */ 	lui	$t5,0x1f10
/*    20af4:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20af8:	ac99000c */ 	sw	$t9,0xc($a0)
/*    20afc:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    20b00:	ac490000 */ 	sw	$t1,0x0($v0)
/*    20b04:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20b08:	3c0cfc26 */ 	lui	$t4,0xfc26
/*    20b0c:	358ca004 */ 	ori	$t4,$t4,0xa004
/*    20b10:	244b0008 */ 	addiu	$t3,$v0,0x8
/*    20b14:	ac8b000c */ 	sw	$t3,0xc($a0)
/*    20b18:	35ad93ff */ 	ori	$t5,$t5,0x93ff
/*    20b1c:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*    20b20:	10a00017 */ 	beqz	$a1,.L00020b80
/*    20b24:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    20b28:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*    20b2c:	3c0ab900 */ 	lui	$t2,0xb900
/*    20b30:	3c18b900 */ 	lui	$t8,0xb900
/*    20b34:	11c0000a */ 	beqz	$t6,.L00020b60
/*    20b38:	354a031d */ 	ori	$t2,$t2,0x31d
/*    20b3c:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20b40:	3c19c411 */ 	lui	$t9,0xc411
/*    20b44:	37392078 */ 	ori	$t9,$t9,0x2078
/*    20b48:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20b4c:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    20b50:	3718031d */ 	ori	$t8,$t8,0x31d
/*    20b54:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20b58:	03e00008 */ 	jr	$ra
/*    20b5c:	ac590004 */ 	sw	$t9,0x4($v0)
.L00020b60:
/*    20b60:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20b64:	3c0bc411 */ 	lui	$t3,0xc411
/*    20b68:	356b2048 */ 	ori	$t3,$t3,0x2048
/*    20b6c:	24490008 */ 	addiu	$t1,$v0,0x8
/*    20b70:	ac89000c */ 	sw	$t1,0xc($a0)
/*    20b74:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    20b78:	03e00008 */ 	jr	$ra
/*    20b7c:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L00020b80:
/*    20b80:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*    20b84:	3c19b900 */ 	lui	$t9,0xb900
/*    20b88:	3c0eb900 */ 	lui	$t6,0xb900
/*    20b8c:	1180000a */ 	beqz	$t4,.L00020bb8
/*    20b90:	3739031d */ 	ori	$t9,$t9,0x31d
/*    20b94:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20b98:	3c0fc410 */ 	lui	$t7,0xc410
/*    20b9c:	35ef49d8 */ 	ori	$t7,$t7,0x49d8
/*    20ba0:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    20ba4:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20ba8:	35ce031d */ 	ori	$t6,$t6,0x31d
/*    20bac:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20bb0:	03e00008 */ 	jr	$ra
/*    20bb4:	ac4f0004 */ 	sw	$t7,0x4($v0)
.L00020bb8:
/*    20bb8:	8c82000c */ 	lw	$v0,0xc($a0)
/*    20bbc:	3c09c410 */ 	lui	$t1,0xc410
/*    20bc0:	352941c8 */ 	ori	$t1,$t1,0x41c8
/*    20bc4:	24580008 */ 	addiu	$t8,$v0,0x8
/*    20bc8:	ac98000c */ 	sw	$t8,0xc($a0)
/*    20bcc:	ac490004 */ 	sw	$t1,0x4($v0)
/*    20bd0:	ac590000 */ 	sw	$t9,0x0($v0)
/*    20bd4:	03e00008 */ 	jr	$ra
/*    20bd8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00020bdc
/*    20bdc:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20be0:	3c0fe700 */ 	lui	$t7,0xe700
/*    20be4:	3c19ba00 */ 	lui	$t9,0xba00
/*    20be8:	246e0008 */ 	addiu	$t6,$v1,0x8
/*    20bec:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20bf0:	ac600004 */ 	sw	$zero,0x4($v1)
/*    20bf4:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    20bf8:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20bfc:	37391402 */ 	ori	$t9,$t9,0x1402
/*    20c00:	3c080010 */ 	lui	$t0,0x10
/*    20c04:	24780008 */ 	addiu	$t8,$v1,0x8
/*    20c08:	ac98000c */ 	sw	$t8,0xc($a0)
/*    20c0c:	ac680004 */ 	sw	$t0,0x4($v1)
/*    20c10:	ac790000 */ 	sw	$t9,0x0($v1)
/*    20c14:	8c890004 */ 	lw	$t1,0x4($a0)
/*    20c18:	3c19fc26 */ 	lui	$t9,0xfc26
/*    20c1c:	3c0eb900 */ 	lui	$t6,0xb900
/*    20c20:	1120000b */ 	beqz	$t1,.L00020c50
/*    20c24:	3739a004 */ 	ori	$t9,$t9,0xa004
/*    20c28:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20c2c:	3c0bb900 */ 	lui	$t3,0xb900
/*    20c30:	3c0c0c19 */ 	lui	$t4,0xc19
/*    20c34:	246a0008 */ 	addiu	$t2,$v1,0x8
/*    20c38:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    20c3c:	358c2078 */ 	ori	$t4,$t4,0x2078
/*    20c40:	356b031d */ 	ori	$t3,$t3,0x31d
/*    20c44:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*    20c48:	10000009 */ 	b	.L00020c70
/*    20c4c:	ac6c0004 */ 	sw	$t4,0x4($v1)
.L00020c50:
/*    20c50:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20c54:	3c0f0c19 */ 	lui	$t7,0xc19
/*    20c58:	35ef2048 */ 	ori	$t7,$t7,0x2048
/*    20c5c:	246d0008 */ 	addiu	$t5,$v1,0x8
/*    20c60:	ac8d000c */ 	sw	$t5,0xc($a0)
/*    20c64:	35ce031d */ 	ori	$t6,$t6,0x31d
/*    20c68:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*    20c6c:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L00020c70:
/*    20c70:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20c74:	3c081f10 */ 	lui	$t0,0x1f10
/*    20c78:	350893ff */ 	ori	$t0,$t0,0x93ff
/*    20c7c:	24780008 */ 	addiu	$t8,$v1,0x8
/*    20c80:	ac98000c */ 	sw	$t8,0xc($a0)
/*    20c84:	ac680004 */ 	sw	$t0,0x4($v1)
/*    20c88:	03e00008 */ 	jr	$ra
/*    20c8c:	ac790000 */ 	sw	$t9,0x0($v1)
);

GLOBAL_ASM(
glabel func00020c90
/*    20c90:	8c82003c */ 	lw	$v0,0x3c($a0)
/*    20c94:	24010001 */ 	addiu	$at,$zero,0x1
/*    20c98:	5441000a */ 	bnel	$v0,$at,.L00020cc4
/*    20c9c:	24010002 */ 	addiu	$at,$zero,0x2
/*    20ca0:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20ca4:	3c0fb600 */ 	lui	$t7,0xb600
/*    20ca8:	24183000 */ 	addiu	$t8,$zero,0x3000
/*    20cac:	246e0008 */ 	addiu	$t6,$v1,0x8
/*    20cb0:	ac8e000c */ 	sw	$t6,0xc($a0)
/*    20cb4:	ac780004 */ 	sw	$t8,0x4($v1)
/*    20cb8:	03e00008 */ 	jr	$ra
/*    20cbc:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    20cc0:	24010002 */ 	addiu	$at,$zero,0x2
.L00020cc4:
/*    20cc4:	5441000a */ 	bnel	$v0,$at,.L00020cf0
/*    20cc8:	24010003 */ 	addiu	$at,$zero,0x3
/*    20ccc:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20cd0:	3c08b700 */ 	lui	$t0,0xb700
/*    20cd4:	24091000 */ 	addiu	$t1,$zero,0x1000
/*    20cd8:	24790008 */ 	addiu	$t9,$v1,0x8
/*    20cdc:	ac99000c */ 	sw	$t9,0xc($a0)
/*    20ce0:	ac690004 */ 	sw	$t1,0x4($v1)
/*    20ce4:	03e00008 */ 	jr	$ra
/*    20ce8:	ac680000 */ 	sw	$t0,0x0($v1)
/*    20cec:	24010003 */ 	addiu	$at,$zero,0x3
.L00020cf0:
/*    20cf0:	14410008 */ 	bne	$v0,$at,.L00020d14
/*    20cf4:	00000000 */ 	nop
/*    20cf8:	8c83000c */ 	lw	$v1,0xc($a0)
/*    20cfc:	3c0bb700 */ 	lui	$t3,0xb700
/*    20d00:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*    20d04:	246a0008 */ 	addiu	$t2,$v1,0x8
/*    20d08:	ac8a000c */ 	sw	$t2,0xc($a0)
/*    20d0c:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*    20d10:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L00020d14:
/*    20d14:	03e00008 */ 	jr	$ra
/*    20d18:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00020d1c
/*    20d1c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    20d20:	3c028006 */ 	lui	$v0,%hi(var8005efc4)
/*    20d24:	8c42efc4 */ 	lw	$v0,%lo(var8005efc4)($v0)
/*    20d28:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    20d2c:	afb10018 */ 	sw	$s1,0x18($sp)
/*    20d30:	afb00014 */ 	sw	$s0,0x14($sp)
/*    20d34:	00808025 */ 	or	$s0,$a0,$zero
/*    20d38:	10400006 */ 	beqz	$v0,.L00020d54
/*    20d3c:	8cd10004 */ 	lw	$s1,0x4($a2)
/*    20d40:	00a02025 */ 	or	$a0,$a1,$zero
/*    20d44:	0040f809 */ 	jalr	$v0
/*    20d48:	00c02825 */ 	or	$a1,$a2,$zero
/*    20d4c:	50400074 */ 	beqzl	$v0,.L00020f20
/*    20d50:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00020d54:
/*    20d54:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*    20d58:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    20d5c:	51e00048 */ 	beqzl	$t7,.L00020e80
/*    20d60:	8e080008 */ 	lw	$t0,0x8($s0)
/*    20d64:	8e380000 */ 	lw	$t8,0x0($s1)
/*    20d68:	53000045 */ 	beqzl	$t8,.L00020e80
/*    20d6c:	8e080008 */ 	lw	$t0,0x8($s0)
/*    20d70:	8e02000c */ 	lw	$v0,0xc($s0)
/*    20d74:	3c08bc00 */ 	lui	$t0,0xbc00
/*    20d78:	35081406 */ 	ori	$t0,$t0,0x1406
/*    20d7c:	24590008 */ 	addiu	$t9,$v0,0x8
/*    20d80:	ae19000c */ 	sw	$t9,0xc($s0)
/*    20d84:	ac480000 */ 	sw	$t0,0x0($v0)
/*    20d88:	8e240008 */ 	lw	$a0,0x8($s1)
/*    20d8c:	0c012d20 */ 	jal	osVirtualToPhysical
/*    20d90:	afa20030 */ 	sw	$v0,0x30($sp)
/*    20d94:	8fa30030 */ 	lw	$v1,0x30($sp)
/*    20d98:	ac620004 */ 	sw	$v0,0x4($v1)
/*    20d9c:	8e09003c */ 	lw	$t1,0x3c($s0)
/*    20da0:	51200004 */ 	beqzl	$t1,.L00020db4
/*    20da4:	86220012 */ 	lh	$v0,0x12($s1)
/*    20da8:	0c008324 */ 	jal	func00020c90
/*    20dac:	02002025 */ 	or	$a0,$s0,$zero
/*    20db0:	86220012 */ 	lh	$v0,0x12($s1)
.L00020db4:
/*    20db4:	24010001 */ 	addiu	$at,$zero,0x1
/*    20db8:	1041000a */ 	beq	$v0,$at,.L00020de4
/*    20dbc:	24010002 */ 	addiu	$at,$zero,0x2
/*    20dc0:	10410014 */ 	beq	$v0,$at,.L00020e14
/*    20dc4:	24010003 */ 	addiu	$at,$zero,0x3
/*    20dc8:	1041000a */ 	beq	$v0,$at,.L00020df4
/*    20dcc:	02002025 */ 	or	$a0,$s0,$zero
/*    20dd0:	24010004 */ 	addiu	$at,$zero,0x4
/*    20dd4:	1041000b */ 	beq	$v0,$at,.L00020e04
/*    20dd8:	02002025 */ 	or	$a0,$s0,$zero
/*    20ddc:	10000010 */ 	b	.L00020e20
/*    20de0:	8e02000c */ 	lw	$v0,0xc($s0)
.L00020de4:
/*    20de4:	0c007df8 */ 	jal	func0001f7e0
/*    20de8:	02002025 */ 	or	$a0,$s0,$zero
/*    20dec:	1000000c */ 	b	.L00020e20
/*    20df0:	8e02000c */ 	lw	$v0,0xc($s0)
.L00020df4:
/*    20df4:	0c007e24 */ 	jal	func0001f890
/*    20df8:	24050001 */ 	addiu	$a1,$zero,0x1
/*    20dfc:	10000008 */ 	b	.L00020e20
/*    20e00:	8e02000c */ 	lw	$v0,0xc($s0)
.L00020e04:
/*    20e04:	0c008092 */ 	jal	func00020248
/*    20e08:	24050001 */ 	addiu	$a1,$zero,0x1
/*    20e0c:	10000004 */ 	b	.L00020e20
/*    20e10:	8e02000c */ 	lw	$v0,0xc($s0)
.L00020e14:
/*    20e14:	0c0082f7 */ 	jal	func00020bdc
/*    20e18:	02002025 */ 	or	$a0,$s0,$zero
/*    20e1c:	8e02000c */ 	lw	$v0,0xc($s0)
.L00020e20:
/*    20e20:	3c0b0600 */ 	lui	$t3,0x600
/*    20e24:	24010003 */ 	addiu	$at,$zero,0x3
/*    20e28:	244a0008 */ 	addiu	$t2,$v0,0x8
/*    20e2c:	ae0a000c */ 	sw	$t2,0xc($s0)
/*    20e30:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    20e34:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*    20e38:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    20e3c:	862d0012 */ 	lh	$t5,0x12($s1)
/*    20e40:	55a1000f */ 	bnel	$t5,$at,.L00020e80
/*    20e44:	8e080008 */ 	lw	$t0,0x8($s0)
/*    20e48:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*    20e4c:	02002025 */ 	or	$a0,$s0,$zero
/*    20e50:	51c0000b */ 	beqzl	$t6,.L00020e80
/*    20e54:	8e080008 */ 	lw	$t0,0x8($s0)
/*    20e58:	0c007e24 */ 	jal	func0001f890
/*    20e5c:	00002825 */ 	or	$a1,$zero,$zero
/*    20e60:	8e02000c */ 	lw	$v0,0xc($s0)
/*    20e64:	3c180600 */ 	lui	$t8,0x600
/*    20e68:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    20e6c:	ae0f000c */ 	sw	$t7,0xc($s0)
/*    20e70:	ac580000 */ 	sw	$t8,0x0($v0)
/*    20e74:	8e390004 */ 	lw	$t9,0x4($s1)
/*    20e78:	ac590004 */ 	sw	$t9,0x4($v0)
/*    20e7c:	8e080008 */ 	lw	$t0,0x8($s0)
.L00020e80:
/*    20e80:	31090002 */ 	andi	$t1,$t0,0x2
/*    20e84:	51200026 */ 	beqzl	$t1,.L00020f20
/*    20e88:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    20e8c:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*    20e90:	51400023 */ 	beqzl	$t2,.L00020f20
/*    20e94:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    20e98:	862b0012 */ 	lh	$t3,0x12($s1)
/*    20e9c:	24010004 */ 	addiu	$at,$zero,0x4
/*    20ea0:	5561001f */ 	bnel	$t3,$at,.L00020f20
/*    20ea4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    20ea8:	8e2c0004 */ 	lw	$t4,0x4($s1)
/*    20eac:	5180001c */ 	beqzl	$t4,.L00020f20
/*    20eb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    20eb4:	8e02000c */ 	lw	$v0,0xc($s0)
/*    20eb8:	3c0ebc00 */ 	lui	$t6,0xbc00
/*    20ebc:	35ce1406 */ 	ori	$t6,$t6,0x1406
/*    20ec0:	244d0008 */ 	addiu	$t5,$v0,0x8
/*    20ec4:	ae0d000c */ 	sw	$t5,0xc($s0)
/*    20ec8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    20ecc:	8e240008 */ 	lw	$a0,0x8($s1)
/*    20ed0:	0c012d20 */ 	jal	osVirtualToPhysical
/*    20ed4:	afa20024 */ 	sw	$v0,0x24($sp)
/*    20ed8:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    20edc:	ac620004 */ 	sw	$v0,0x4($v1)
/*    20ee0:	8e0f003c */ 	lw	$t7,0x3c($s0)
/*    20ee4:	51e00004 */ 	beqzl	$t7,.L00020ef8
/*    20ee8:	02002025 */ 	or	$a0,$s0,$zero
/*    20eec:	0c008324 */ 	jal	func00020c90
/*    20ef0:	02002025 */ 	or	$a0,$s0,$zero
/*    20ef4:	02002025 */ 	or	$a0,$s0,$zero
.L00020ef8:
/*    20ef8:	0c008092 */ 	jal	func00020248
/*    20efc:	00002825 */ 	or	$a1,$zero,$zero
/*    20f00:	8e02000c */ 	lw	$v0,0xc($s0)
/*    20f04:	3c190600 */ 	lui	$t9,0x600
/*    20f08:	24580008 */ 	addiu	$t8,$v0,0x8
/*    20f0c:	ae18000c */ 	sw	$t8,0xc($s0)
/*    20f10:	ac590000 */ 	sw	$t9,0x0($v0)
/*    20f14:	8e280004 */ 	lw	$t0,0x4($s1)
/*    20f18:	ac480004 */ 	sw	$t0,0x4($v0)
/*    20f1c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00020f20:
/*    20f20:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    20f24:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    20f28:	03e00008 */ 	jr	$ra
/*    20f2c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func00020f30
/*    20f30:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*    20f34:	3c028006 */ 	lui	$v0,%hi(var8005efc4)
/*    20f38:	8c42efc4 */ 	lw	$v0,%lo(var8005efc4)($v0)
/*    20f3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    20f40:	afb00018 */ 	sw	$s0,0x18($sp)
/*    20f44:	afa50054 */ 	sw	$a1,0x54($sp)
/*    20f48:	afa60058 */ 	sw	$a2,0x58($sp)
/*    20f4c:	8ccf0004 */ 	lw	$t7,0x4($a2)
/*    20f50:	00808025 */ 	or	$s0,$a0,$zero
/*    20f54:	10400006 */ 	beqz	$v0,.L00020f70
/*    20f58:	afaf004c */ 	sw	$t7,0x4c($sp)
/*    20f5c:	00a02025 */ 	or	$a0,$a1,$zero
/*    20f60:	0040f809 */ 	jalr	$v0
/*    20f64:	00c02825 */ 	or	$a1,$a2,$zero
/*    20f68:	504000b4 */ 	beqzl	$v0,.L0002123c
/*    20f6c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00020f70:
/*    20f70:	8e180008 */ 	lw	$t8,0x8($s0)
/*    20f74:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    20f78:	33190001 */ 	andi	$t9,$t8,0x1
/*    20f7c:	53200068 */ 	beqzl	$t9,.L00021120
/*    20f80:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*    20f84:	0c006a87 */ 	jal	modelGetNodeData
/*    20f88:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    20f8c:	afa20048 */ 	sw	$v0,0x48($sp)
/*    20f90:	8c480004 */ 	lw	$t0,0x4($v0)
/*    20f94:	51000062 */ 	beqzl	$t0,.L00021120
/*    20f98:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*    20f9c:	8e03000c */ 	lw	$v1,0xc($s0)
/*    20fa0:	3c0abc00 */ 	lui	$t2,0xbc00
/*    20fa4:	354a1406 */ 	ori	$t2,$t2,0x1406
/*    20fa8:	24690008 */ 	addiu	$t1,$v1,0x8
/*    20fac:	ae09000c */ 	sw	$t1,0xc($s0)
/*    20fb0:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*    20fb4:	8fab004c */ 	lw	$t3,0x4c($sp)
/*    20fb8:	8d640008 */ 	lw	$a0,0x8($t3)
/*    20fbc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    20fc0:	afa30044 */ 	sw	$v1,0x44($sp)
/*    20fc4:	8fa50044 */ 	lw	$a1,0x44($sp)
/*    20fc8:	aca20004 */ 	sw	$v0,0x4($a1)
/*    20fcc:	8e0c003c */ 	lw	$t4,0x3c($s0)
/*    20fd0:	51800004 */ 	beqzl	$t4,.L00020fe4
/*    20fd4:	8fad004c */ 	lw	$t5,0x4c($sp)
/*    20fd8:	0c008324 */ 	jal	func00020c90
/*    20fdc:	02002025 */ 	or	$a0,$s0,$zero
/*    20fe0:	8fad004c */ 	lw	$t5,0x4c($sp)
.L00020fe4:
/*    20fe4:	24010001 */ 	addiu	$at,$zero,0x1
/*    20fe8:	85a20012 */ 	lh	$v0,0x12($t5)
/*    20fec:	1041000a */ 	beq	$v0,$at,.L00021018
/*    20ff0:	24010002 */ 	addiu	$at,$zero,0x2
/*    20ff4:	10410014 */ 	beq	$v0,$at,.L00021048
/*    20ff8:	24010003 */ 	addiu	$at,$zero,0x3
/*    20ffc:	1041000a */ 	beq	$v0,$at,.L00021028
/*    21000:	02002025 */ 	or	$a0,$s0,$zero
/*    21004:	24010004 */ 	addiu	$at,$zero,0x4
/*    21008:	1041000b */ 	beq	$v0,$at,.L00021038
/*    2100c:	02002025 */ 	or	$a0,$s0,$zero
/*    21010:	10000010 */ 	b	.L00021054
/*    21014:	8e03000c */ 	lw	$v1,0xc($s0)
.L00021018:
/*    21018:	0c007df8 */ 	jal	func0001f7e0
/*    2101c:	02002025 */ 	or	$a0,$s0,$zero
/*    21020:	1000000c */ 	b	.L00021054
/*    21024:	8e03000c */ 	lw	$v1,0xc($s0)
.L00021028:
/*    21028:	0c007e24 */ 	jal	func0001f890
/*    2102c:	24050001 */ 	addiu	$a1,$zero,0x1
/*    21030:	10000008 */ 	b	.L00021054
/*    21034:	8e03000c */ 	lw	$v1,0xc($s0)
.L00021038:
/*    21038:	0c008092 */ 	jal	func00020248
/*    2103c:	24050001 */ 	addiu	$a1,$zero,0x1
/*    21040:	10000004 */ 	b	.L00021054
/*    21044:	8e03000c */ 	lw	$v1,0xc($s0)
.L00021048:
/*    21048:	0c0082f7 */ 	jal	func00020bdc
/*    2104c:	02002025 */ 	or	$a0,$s0,$zero
/*    21050:	8e03000c */ 	lw	$v1,0xc($s0)
.L00021054:
/*    21054:	3c0ebc00 */ 	lui	$t6,0xbc00
/*    21058:	35ce1006 */ 	ori	$t6,$t6,0x1006
/*    2105c:	246f0008 */ 	addiu	$t7,$v1,0x8
/*    21060:	ae0f000c */ 	sw	$t7,0xc($s0)
/*    21064:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*    21068:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    2106c:	8f040000 */ 	lw	$a0,0x0($t8)
/*    21070:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21074:	afa30040 */ 	sw	$v1,0x40($sp)
/*    21078:	8fa50040 */ 	lw	$a1,0x40($sp)
/*    2107c:	3c08bc00 */ 	lui	$t0,0xbc00
/*    21080:	35081806 */ 	ori	$t0,$t0,0x1806
/*    21084:	aca20004 */ 	sw	$v0,0x4($a1)
/*    21088:	8e03000c */ 	lw	$v1,0xc($s0)
/*    2108c:	24790008 */ 	addiu	$t9,$v1,0x8
/*    21090:	ae19000c */ 	sw	$t9,0xc($s0)
/*    21094:	ac680000 */ 	sw	$t0,0x0($v1)
/*    21098:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    2109c:	8d240008 */ 	lw	$a0,0x8($t1)
/*    210a0:	0c012d20 */ 	jal	osVirtualToPhysical
/*    210a4:	afa3003c */ 	sw	$v1,0x3c($sp)
/*    210a8:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*    210ac:	3c0b0600 */ 	lui	$t3,0x600
/*    210b0:	24010003 */ 	addiu	$at,$zero,0x3
/*    210b4:	acc20004 */ 	sw	$v0,0x4($a2)
/*    210b8:	8e03000c */ 	lw	$v1,0xc($s0)
/*    210bc:	246a0008 */ 	addiu	$t2,$v1,0x8
/*    210c0:	ae0a000c */ 	sw	$t2,0xc($s0)
/*    210c4:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*    210c8:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    210cc:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    210d0:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*    210d4:	8faf004c */ 	lw	$t7,0x4c($sp)
/*    210d8:	85ee0012 */ 	lh	$t6,0x12($t7)
/*    210dc:	55c10010 */ 	bnel	$t6,$at,.L00021120
/*    210e0:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*    210e4:	8df80004 */ 	lw	$t8,0x4($t7)
/*    210e8:	02002025 */ 	or	$a0,$s0,$zero
/*    210ec:	5300000c */ 	beqzl	$t8,.L00021120
/*    210f0:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*    210f4:	0c007e24 */ 	jal	func0001f890
/*    210f8:	00002825 */ 	or	$a1,$zero,$zero
/*    210fc:	8e03000c */ 	lw	$v1,0xc($s0)
/*    21100:	3c080600 */ 	lui	$t0,0x600
/*    21104:	24790008 */ 	addiu	$t9,$v1,0x8
/*    21108:	ae19000c */ 	sw	$t9,0xc($s0)
/*    2110c:	ac680000 */ 	sw	$t0,0x0($v1)
/*    21110:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    21114:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    21118:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*    2111c:	8e0b0008 */ 	lw	$t3,0x8($s0)
.L00021120:
/*    21120:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    21124:	316c0002 */ 	andi	$t4,$t3,0x2
/*    21128:	51800044 */ 	beqzl	$t4,.L0002123c
/*    2112c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    21130:	0c006a87 */ 	jal	modelGetNodeData
/*    21134:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    21138:	afa20030 */ 	sw	$v0,0x30($sp)
/*    2113c:	8c4d0004 */ 	lw	$t5,0x4($v0)
/*    21140:	8fae004c */ 	lw	$t6,0x4c($sp)
/*    21144:	51a0003d */ 	beqzl	$t5,.L0002123c
/*    21148:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    2114c:	85cf0012 */ 	lh	$t7,0x12($t6)
/*    21150:	24010004 */ 	addiu	$at,$zero,0x4
/*    21154:	55e10039 */ 	bnel	$t7,$at,.L0002123c
/*    21158:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    2115c:	8dd80004 */ 	lw	$t8,0x4($t6)
/*    21160:	53000036 */ 	beqzl	$t8,.L0002123c
/*    21164:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    21168:	8e03000c */ 	lw	$v1,0xc($s0)
/*    2116c:	3c08bc00 */ 	lui	$t0,0xbc00
/*    21170:	35081406 */ 	ori	$t0,$t0,0x1406
/*    21174:	24790008 */ 	addiu	$t9,$v1,0x8
/*    21178:	ae19000c */ 	sw	$t9,0xc($s0)
/*    2117c:	ac680000 */ 	sw	$t0,0x0($v1)
/*    21180:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    21184:	8d240008 */ 	lw	$a0,0x8($t1)
/*    21188:	0c012d20 */ 	jal	osVirtualToPhysical
/*    2118c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*    21190:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    21194:	aca20004 */ 	sw	$v0,0x4($a1)
/*    21198:	8e0a003c */ 	lw	$t2,0x3c($s0)
/*    2119c:	51400004 */ 	beqzl	$t2,.L000211b0
/*    211a0:	8e03000c */ 	lw	$v1,0xc($s0)
/*    211a4:	0c008324 */ 	jal	func00020c90
/*    211a8:	02002025 */ 	or	$a0,$s0,$zero
/*    211ac:	8e03000c */ 	lw	$v1,0xc($s0)
.L000211b0:
/*    211b0:	3c0cbc00 */ 	lui	$t4,0xbc00
/*    211b4:	358c1006 */ 	ori	$t4,$t4,0x1006
/*    211b8:	246b0008 */ 	addiu	$t3,$v1,0x8
/*    211bc:	ae0b000c */ 	sw	$t3,0xc($s0)
/*    211c0:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*    211c4:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    211c8:	8da40000 */ 	lw	$a0,0x0($t5)
/*    211cc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    211d0:	afa30028 */ 	sw	$v1,0x28($sp)
/*    211d4:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    211d8:	3c0ebc00 */ 	lui	$t6,0xbc00
/*    211dc:	35ce1806 */ 	ori	$t6,$t6,0x1806
/*    211e0:	aca20004 */ 	sw	$v0,0x4($a1)
/*    211e4:	8e03000c */ 	lw	$v1,0xc($s0)
/*    211e8:	246f0008 */ 	addiu	$t7,$v1,0x8
/*    211ec:	ae0f000c */ 	sw	$t7,0xc($s0)
/*    211f0:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*    211f4:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    211f8:	8f040008 */ 	lw	$a0,0x8($t8)
/*    211fc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21200:	afa30024 */ 	sw	$v1,0x24($sp)
/*    21204:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    21208:	02002025 */ 	or	$a0,$s0,$zero
/*    2120c:	00002825 */ 	or	$a1,$zero,$zero
/*    21210:	0c008092 */ 	jal	func00020248
/*    21214:	acc20004 */ 	sw	$v0,0x4($a2)
/*    21218:	8e03000c */ 	lw	$v1,0xc($s0)
/*    2121c:	3c080600 */ 	lui	$t0,0x600
/*    21220:	24790008 */ 	addiu	$t9,$v1,0x8
/*    21224:	ae19000c */ 	sw	$t9,0xc($s0)
/*    21228:	ac680000 */ 	sw	$t0,0x0($v1)
/*    2122c:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    21230:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    21234:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*    21238:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0002123c:
/*    2123c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    21240:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*    21244:	03e00008 */ 	jr	$ra
/*    21248:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002124c
/*    2124c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    21250:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    21254:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    21258:	afb70034 */ 	sw	$s7,0x34($sp)
/*    2125c:	afb60030 */ 	sw	$s6,0x30($sp)
/*    21260:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    21264:	afb40028 */ 	sw	$s4,0x28($sp)
/*    21268:	afb30024 */ 	sw	$s3,0x24($sp)
/*    2126c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    21270:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    21274:	afb00018 */ 	sw	$s0,0x18($sp)
/*    21278:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    2127c:	00809825 */ 	or	$s3,$a0,$zero
/*    21280:	31cf0002 */ 	andi	$t7,$t6,0x2
/*    21284:	51e00106 */ 	beqzl	$t7,.L000216a0
/*    21288:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    2128c:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    21290:	8c580008 */ 	lw	$t8,0x8($v0)
/*    21294:	53000102 */ 	beqzl	$t8,.L000216a0
/*    21298:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    2129c:	8c440000 */ 	lw	$a0,0x0($v0)
/*    212a0:	8c520004 */ 	lw	$s2,0x4($v0)
/*    212a4:	afa20044 */ 	sw	$v0,0x44($sp)
/*    212a8:	0004c880 */ 	sll	$t9,$a0,0x2
/*    212ac:	03202025 */ 	or	$a0,$t9,$zero
/*    212b0:	3c198006 */ 	lui	$t9,%hi(var8005efc8)
/*    212b4:	8f39efc8 */ 	lw	$t9,%lo(var8005efc8)($t9)
/*    212b8:	0320f809 */ 	jalr	$t9
/*    212bc:	00000000 */ 	nop
/*    212c0:	8e74000c */ 	lw	$s4,0xc($s3)
/*    212c4:	3c0abc00 */ 	lui	$t2,0xbc00
/*    212c8:	354a1006 */ 	ori	$t2,$t2,0x1006
/*    212cc:	26890008 */ 	addiu	$t1,$s4,0x8
/*    212d0:	ae69000c */ 	sw	$t1,0xc($s3)
/*    212d4:	00408025 */ 	or	$s0,$v0,$zero
/*    212d8:	00402025 */ 	or	$a0,$v0,$zero
/*    212dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    212e0:	ae8a0000 */ 	sw	$t2,0x0($s4)
/*    212e4:	8fa30044 */ 	lw	$v1,0x44($sp)
/*    212e8:	ae820004 */ 	sw	$v0,0x4($s4)
/*    212ec:	8e76000c */ 	lw	$s6,0xc($s3)
/*    212f0:	3c0cbc00 */ 	lui	$t4,0xbc00
/*    212f4:	358c1806 */ 	ori	$t4,$t4,0x1806
/*    212f8:	26cb0008 */ 	addiu	$t3,$s6,0x8
/*    212fc:	ae6b000c */ 	sw	$t3,0xc($s3)
/*    21300:	aecc0000 */ 	sw	$t4,0x0($s6)
/*    21304:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*    21308:	2415000c */ 	addiu	$s5,$zero,0xc
/*    2130c:	8c6d0004 */ 	lw	$t5,0x4($v1)
/*    21310:	000e7880 */ 	sll	$t7,$t6,0x2
/*    21314:	01f50019 */ 	multu	$t7,$s5
/*    21318:	0000c012 */ 	mflo	$t8
/*    2131c:	01b82021 */ 	addu	$a0,$t5,$t8
/*    21320:	24840007 */ 	addiu	$a0,$a0,0x7
/*    21324:	34990007 */ 	ori	$t9,$a0,0x7
/*    21328:	0c012d20 */ 	jal	osVirtualToPhysical
/*    2132c:	3b240007 */ 	xori	$a0,$t9,0x7
/*    21330:	aec20004 */ 	sw	$v0,0x4($s6)
/*    21334:	8e74000c */ 	lw	$s4,0xc($s3)
/*    21338:	3c0bbc00 */ 	lui	$t3,0xbc00
/*    2133c:	356b1406 */ 	ori	$t3,$t3,0x1406
/*    21340:	268a0008 */ 	addiu	$t2,$s4,0x8
/*    21344:	ae6a000c */ 	sw	$t2,0xc($s3)
/*    21348:	ae8b0000 */ 	sw	$t3,0x0($s4)
/*    2134c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    21350:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21354:	8d84000c */ 	lw	$a0,0xc($t4)
/*    21358:	8fa50044 */ 	lw	$a1,0x44($sp)
/*    2135c:	ae820004 */ 	sw	$v0,0x4($s4)
/*    21360:	8e71000c */ 	lw	$s1,0xc($s3)
/*    21364:	3c0ff800 */ 	lui	$t7,0xf800
/*    21368:	3c180600 */ 	lui	$t8,0x600
/*    2136c:	262e0008 */ 	addiu	$t6,$s1,0x8
/*    21370:	ae6e000c */ 	sw	$t6,0xc($s3)
/*    21374:	ae200004 */ 	sw	$zero,0x4($s1)
/*    21378:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*    2137c:	8e71000c */ 	lw	$s1,0xc($s3)
/*    21380:	0000b025 */ 	or	$s6,$zero,$zero
/*    21384:	241e0200 */ 	addiu	$s8,$zero,0x200
/*    21388:	262d0008 */ 	addiu	$t5,$s1,0x8
/*    2138c:	ae6d000c */ 	sw	$t5,0xc($s3)
/*    21390:	ae380000 */ 	sw	$t8,0x0($s1)
/*    21394:	8cb90008 */ 	lw	$t9,0x8($a1)
/*    21398:	241700b5 */ 	addiu	$s7,$zero,0xb5
/*    2139c:	ae390004 */ 	sw	$t9,0x4($s1)
/*    213a0:	8ca90000 */ 	lw	$t1,0x0($a1)
/*    213a4:	592000be */ 	blezl	$t1,.L000216a0
/*    213a8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L000213ac:
/*    213ac:	0c004b70 */ 	jal	random
/*    213b0:	00000000 */ 	nop
/*    213b4:	00025280 */ 	sll	$t2,$v0,0xa
/*    213b8:	3151ffff */ 	andi	$s1,$t2,0xffff
/*    213bc:	0c013ef0 */ 	jal	func0004fbc0
/*    213c0:	3144ffff */ 	andi	$a0,$t2,0xffff
/*    213c4:	00025940 */ 	sll	$t3,$v0,0x5
/*    213c8:	01770019 */ 	multu	$t3,$s7
/*    213cc:	3224ffff */ 	andi	$a0,$s1,0xffff
/*    213d0:	0000a012 */ 	mflo	$s4
/*    213d4:	00146483 */ 	sra	$t4,$s4,0x12
/*    213d8:	0c013efc */ 	jal	func0004fbf0
/*    213dc:	0180a025 */ 	or	$s4,$t4,$zero
/*    213e0:	00027140 */ 	sll	$t6,$v0,0x5
/*    213e4:	01d70019 */ 	multu	$t6,$s7
/*    213e8:	00009812 */ 	mflo	$s3
/*    213ec:	00137c83 */ 	sra	$t7,$s3,0x12
/*    213f0:	0c004b70 */ 	jal	random
/*    213f4:	01e09825 */ 	or	$s3,$t7,$zero
/*    213f8:	0c004b70 */ 	jal	random
/*    213fc:	00028fc2 */ 	srl	$s1,$v0,0x1f
/*    21400:	8a410000 */ 	lwl	$at,0x0($s2)
/*    21404:	9a410003 */ 	lwr	$at,0x3($s2)
/*    21408:	304d3fff */ 	andi	$t5,$v0,0x3fff
/*    2140c:	3c180001 */ 	lui	$t8,0x1
/*    21410:	aa010000 */ 	swl	$at,0x0($s0)
/*    21414:	ba010003 */ 	swr	$at,0x3($s0)
/*    21418:	8a490004 */ 	lwl	$t1,0x4($s2)
/*    2141c:	9a490007 */ 	lwr	$t1,0x7($s2)
/*    21420:	030d2023 */ 	subu	$a0,$t8,$t5
/*    21424:	03d44023 */ 	subu	$t0,$s8,$s4
/*    21428:	aa090004 */ 	swl	$t1,0x4($s0)
/*    2142c:	ba090007 */ 	swr	$t1,0x7($s0)
/*    21430:	8a410008 */ 	lwl	$at,0x8($s2)
/*    21434:	9a41000b */ 	lwr	$at,0xb($s2)
/*    21438:	03d33823 */ 	subu	$a3,$s8,$s3
/*    2143c:	00801825 */ 	or	$v1,$a0,$zero
/*    21440:	aa010008 */ 	swl	$at,0x8($s0)
/*    21444:	ba01000b */ 	swr	$at,0xb($s0)
/*    21448:	8a41000c */ 	lwl	$at,0xc($s2)
/*    2144c:	9a41000f */ 	lwr	$at,0xf($s2)
/*    21450:	26660200 */ 	addiu	$a2,$s3,0x200
/*    21454:	26d60001 */ 	addiu	$s6,$s6,0x1
/*    21458:	aa01000c */ 	swl	$at,0xc($s0)
/*    2145c:	ba01000f */ 	swr	$at,0xf($s0)
/*    21460:	8a4b0010 */ 	lwl	$t3,0x10($s2)
/*    21464:	9a4b0013 */ 	lwr	$t3,0x13($s2)
/*    21468:	26100030 */ 	addiu	$s0,$s0,0x30
/*    2146c:	aa0bffe0 */ 	swl	$t3,-0x20($s0)
/*    21470:	ba0bffe3 */ 	swr	$t3,-0x1d($s0)
/*    21474:	8a410014 */ 	lwl	$at,0x14($s2)
/*    21478:	9a410017 */ 	lwr	$at,0x17($s2)
/*    2147c:	aa01ffe4 */ 	swl	$at,-0x1c($s0)
/*    21480:	ba01ffe7 */ 	swr	$at,-0x19($s0)
/*    21484:	8a410018 */ 	lwl	$at,0x18($s2)
/*    21488:	9a41001b */ 	lwr	$at,0x1b($s2)
/*    2148c:	aa01ffe8 */ 	swl	$at,-0x18($s0)
/*    21490:	ba01ffeb */ 	swr	$at,-0x15($s0)
/*    21494:	8a4e001c */ 	lwl	$t6,0x1c($s2)
/*    21498:	9a4e001f */ 	lwr	$t6,0x1f($s2)
/*    2149c:	aa0effec */ 	swl	$t6,-0x14($s0)
/*    214a0:	ba0effef */ 	swr	$t6,-0x11($s0)
/*    214a4:	8a410020 */ 	lwl	$at,0x20($s2)
/*    214a8:	9a410023 */ 	lwr	$at,0x23($s2)
/*    214ac:	aa01fff0 */ 	swl	$at,-0x10($s0)
/*    214b0:	ba01fff3 */ 	swr	$at,-0xd($s0)
/*    214b4:	8a410024 */ 	lwl	$at,0x24($s2)
/*    214b8:	9a410027 */ 	lwr	$at,0x27($s2)
/*    214bc:	aa01fff4 */ 	swl	$at,-0xc($s0)
/*    214c0:	ba01fff7 */ 	swr	$at,-0x9($s0)
/*    214c4:	8a580028 */ 	lwl	$t8,0x28($s2)
/*    214c8:	9a58002b */ 	lwr	$t8,0x2b($s2)
/*    214cc:	aa18fff8 */ 	swl	$t8,-0x8($s0)
/*    214d0:	ba18fffb */ 	swr	$t8,-0x5($s0)
/*    214d4:	8a41002c */ 	lwl	$at,0x2c($s2)
/*    214d8:	9a41002f */ 	lwr	$at,0x2f($s2)
/*    214dc:	a608ffd8 */ 	sh	$t0,-0x28($s0)
/*    214e0:	a607ffda */ 	sh	$a3,-0x26($s0)
/*    214e4:	aa01fffc */ 	swl	$at,-0x4($s0)
/*    214e8:	ba01ffff */ 	swr	$at,-0x1($s0)
/*    214ec:	06210004 */ 	bgez	$s1,.L00021500
/*    214f0:	322d0003 */ 	andi	$t5,$s1,0x3
/*    214f4:	11a00002 */ 	beqz	$t5,.L00021500
/*    214f8:	00000000 */ 	nop
/*    214fc:	25adfffc */ 	addiu	$t5,$t5,-4
.L00021500:
/*    21500:	01b50019 */ 	multu	$t5,$s5
/*    21504:	0000c812 */ 	mflo	$t9
/*    21508:	02592821 */ 	addu	$a1,$s2,$t9
/*    2150c:	84a90000 */ 	lh	$t1,0x0($a1)
/*    21510:	01240019 */ 	multu	$t1,$a0
/*    21514:	26290001 */ 	addiu	$t1,$s1,0x1
/*    21518:	00005012 */ 	mflo	$t2
/*    2151c:	000a5c03 */ 	sra	$t3,$t2,0x10
/*    21520:	a60bffd0 */ 	sh	$t3,-0x30($s0)
/*    21524:	84ac0002 */ 	lh	$t4,0x2($a1)
/*    21528:	01840019 */ 	multu	$t4,$a0
/*    2152c:	26840200 */ 	addiu	$a0,$s4,0x200
/*    21530:	00007012 */ 	mflo	$t6
/*    21534:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    21538:	a60fffd2 */ 	sh	$t7,-0x2e($s0)
/*    2153c:	84b80004 */ 	lh	$t8,0x4($a1)
/*    21540:	a606ffe4 */ 	sh	$a2,-0x1c($s0)
/*    21544:	a608ffe6 */ 	sh	$t0,-0x1a($s0)
/*    21548:	03030019 */ 	multu	$t8,$v1
/*    2154c:	00006812 */ 	mflo	$t5
/*    21550:	000dcc03 */ 	sra	$t9,$t5,0x10
/*    21554:	a619ffd4 */ 	sh	$t9,-0x2c($s0)
/*    21558:	05210004 */ 	bgez	$t1,.L0002156c
/*    2155c:	312a0003 */ 	andi	$t2,$t1,0x3
/*    21560:	11400002 */ 	beqz	$t2,.L0002156c
/*    21564:	00000000 */ 	nop
/*    21568:	254afffc */ 	addiu	$t2,$t2,-4
.L0002156c:
/*    2156c:	01550019 */ 	multu	$t2,$s5
/*    21570:	00005812 */ 	mflo	$t3
/*    21574:	024b1021 */ 	addu	$v0,$s2,$t3
/*    21578:	844c0000 */ 	lh	$t4,0x0($v0)
/*    2157c:	01830019 */ 	multu	$t4,$v1
/*    21580:	262c0002 */ 	addiu	$t4,$s1,0x2
/*    21584:	00007012 */ 	mflo	$t6
/*    21588:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    2158c:	a60fffdc */ 	sh	$t7,-0x24($s0)
/*    21590:	84580002 */ 	lh	$t8,0x2($v0)
/*    21594:	03030019 */ 	multu	$t8,$v1
/*    21598:	00006812 */ 	mflo	$t5
/*    2159c:	000dcc03 */ 	sra	$t9,$t5,0x10
/*    215a0:	a619ffde */ 	sh	$t9,-0x22($s0)
/*    215a4:	84490004 */ 	lh	$t1,0x4($v0)
/*    215a8:	a604fff0 */ 	sh	$a0,-0x10($s0)
/*    215ac:	a606fff2 */ 	sh	$a2,-0xe($s0)
/*    215b0:	01230019 */ 	multu	$t1,$v1
/*    215b4:	00005012 */ 	mflo	$t2
/*    215b8:	000a5c03 */ 	sra	$t3,$t2,0x10
/*    215bc:	a60bffe0 */ 	sh	$t3,-0x20($s0)
/*    215c0:	05810004 */ 	bgez	$t4,.L000215d4
/*    215c4:	318e0003 */ 	andi	$t6,$t4,0x3
/*    215c8:	11c00002 */ 	beqz	$t6,.L000215d4
/*    215cc:	00000000 */ 	nop
/*    215d0:	25cefffc */ 	addiu	$t6,$t6,-4
.L000215d4:
/*    215d4:	01d50019 */ 	multu	$t6,$s5
/*    215d8:	00007812 */ 	mflo	$t7
/*    215dc:	024f1021 */ 	addu	$v0,$s2,$t7
/*    215e0:	84580000 */ 	lh	$t8,0x0($v0)
/*    215e4:	03030019 */ 	multu	$t8,$v1
/*    215e8:	26380003 */ 	addiu	$t8,$s1,0x3
/*    215ec:	00006812 */ 	mflo	$t5
/*    215f0:	000dcc03 */ 	sra	$t9,$t5,0x10
/*    215f4:	a619ffe8 */ 	sh	$t9,-0x18($s0)
/*    215f8:	84490002 */ 	lh	$t1,0x2($v0)
/*    215fc:	01230019 */ 	multu	$t1,$v1
/*    21600:	00005012 */ 	mflo	$t2
/*    21604:	000a5c03 */ 	sra	$t3,$t2,0x10
/*    21608:	a60bffea */ 	sh	$t3,-0x16($s0)
/*    2160c:	844c0004 */ 	lh	$t4,0x4($v0)
/*    21610:	a607fffc */ 	sh	$a3,-0x4($s0)
/*    21614:	a604fffe */ 	sh	$a0,-0x2($s0)
/*    21618:	01830019 */ 	multu	$t4,$v1
/*    2161c:	00007012 */ 	mflo	$t6
/*    21620:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    21624:	a60fffec */ 	sh	$t7,-0x14($s0)
/*    21628:	07010004 */ 	bgez	$t8,.L0002163c
/*    2162c:	330d0003 */ 	andi	$t5,$t8,0x3
/*    21630:	11a00002 */ 	beqz	$t5,.L0002163c
/*    21634:	00000000 */ 	nop
/*    21638:	25adfffc */ 	addiu	$t5,$t5,-4
.L0002163c:
/*    2163c:	01b50019 */ 	multu	$t5,$s5
/*    21640:	0000c812 */ 	mflo	$t9
/*    21644:	02591021 */ 	addu	$v0,$s2,$t9
/*    21648:	84490000 */ 	lh	$t1,0x0($v0)
/*    2164c:	26520030 */ 	addiu	$s2,$s2,0x30
/*    21650:	01230019 */ 	multu	$t1,$v1
/*    21654:	00005012 */ 	mflo	$t2
/*    21658:	000a5c03 */ 	sra	$t3,$t2,0x10
/*    2165c:	a60bfff4 */ 	sh	$t3,-0xc($s0)
/*    21660:	844c0002 */ 	lh	$t4,0x2($v0)
/*    21664:	01830019 */ 	multu	$t4,$v1
/*    21668:	00007012 */ 	mflo	$t6
/*    2166c:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    21670:	a60ffff6 */ 	sh	$t7,-0xa($s0)
/*    21674:	84580004 */ 	lh	$t8,0x4($v0)
/*    21678:	03030019 */ 	multu	$t8,$v1
/*    2167c:	00006812 */ 	mflo	$t5
/*    21680:	000dcc03 */ 	sra	$t9,$t5,0x10
/*    21684:	a619fff8 */ 	sh	$t9,-0x8($s0)
/*    21688:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    2168c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    21690:	02ca082a */ 	slt	$at,$s6,$t2
/*    21694:	1420ff45 */ 	bnez	$at,.L000213ac
/*    21698:	00000000 */ 	nop
/*    2169c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L000216a0:
/*    216a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    216a4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    216a8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    216ac:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    216b0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    216b4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    216b8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    216bc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    216c0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    216c4:	03e00008 */ 	jr	$ra
/*    216c8:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func000216cc
/*    216cc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    216d0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    216d4:	afa40028 */ 	sw	$a0,0x28($sp)
/*    216d8:	00807025 */ 	or	$t6,$a0,$zero
/*    216dc:	8dc70004 */ 	lw	$a3,0x4($t6)
/*    216e0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    216e4:	24180001 */ 	addiu	$t8,$zero,0x1
/*    216e8:	afb80014 */ 	sw	$t8,0x14($sp)
/*    216ec:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    216f0:	afa00018 */ 	sw	$zero,0x18($sp)
/*    216f4:	0fc2ce70 */ 	jal	func0f0b39c0
/*    216f8:	2484000c */ 	addiu	$a0,$a0,0xc
/*    216fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    21700:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    21704:	03e00008 */ 	jr	$ra
/*    21708:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002170c
.late_rodata
glabel var70054454
.word 0x40c907a9
.text
/*    2170c:	27bdfef0 */ 	addiu	$sp,$sp,-272
/*    21710:	afb30020 */ 	sw	$s3,0x20($sp)
/*    21714:	00809825 */ 	or	$s3,$a0,$zero
/*    21718:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    2171c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    21720:	afb10018 */ 	sw	$s1,0x18($sp)
/*    21724:	afb00014 */ 	sw	$s0,0x14($sp)
/*    21728:	afa50114 */ 	sw	$a1,0x114($sp)
/*    2172c:	00a02025 */ 	or	$a0,$a1,$zero
/*    21730:	00c08025 */ 	or	$s0,$a2,$zero
/*    21734:	8cd10004 */ 	lw	$s1,0x4($a2)
/*    21738:	0c006a87 */ 	jal	modelGetNodeData
/*    2173c:	00c02825 */ 	or	$a1,$a2,$zero
/*    21740:	3c198006 */ 	lui	$t9,%hi(var8005efec)
/*    21744:	2739efec */ 	addiu	$t9,$t9,%lo(var8005efec)
/*    21748:	8f210000 */ 	lw	$at,0x0($t9)
/*    2174c:	27ab0084 */ 	addiu	$t3,$sp,0x84
/*    21750:	8f380004 */ 	lw	$t8,0x4($t9)
/*    21754:	ad610000 */ 	sw	$at,0x0($t3)
/*    21758:	8f210008 */ 	lw	$at,0x8($t9)
/*    2175c:	3c0c8006 */ 	lui	$t4,%hi(var8005eff8)
/*    21760:	ad780004 */ 	sw	$t8,0x4($t3)
/*    21764:	ad610008 */ 	sw	$at,0x8($t3)
/*    21768:	8d8ceff8 */ 	lw	$t4,%lo(var8005eff8)($t4)
/*    2176c:	afac0080 */ 	sw	$t4,0x80($sp)
/*    21770:	8e6f0008 */ 	lw	$t7,0x8($s3)
/*    21774:	31ed0002 */ 	andi	$t5,$t7,0x2
/*    21778:	51a001d8 */ 	beqzl	$t5,.L00021edc
/*    2177c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    21780:	844e0000 */ 	lh	$t6,0x0($v0)
/*    21784:	02002025 */ 	or	$a0,$s0,$zero
/*    21788:	51c001d4 */ 	beqzl	$t6,.L00021edc
/*    2178c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    21790:	0c006949 */ 	jal	func0001a524
/*    21794:	00002825 */ 	or	$a1,$zero,$zero
/*    21798:	8fab0114 */ 	lw	$t3,0x114($sp)
/*    2179c:	0002c180 */ 	sll	$t8,$v0,0x6
/*    217a0:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*    217a4:	8d79000c */ 	lw	$t9,0xc($t3)
/*    217a8:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*    217ac:	03389021 */ 	addu	$s2,$t9,$t8
/*    217b0:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*    217b4:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*    217b8:	c6480010 */ 	lwc1	$f8,0x10($s2)
/*    217bc:	46082282 */ 	mul.s	$f10,$f4,$f8
/*    217c0:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*    217c4:	460a3100 */ 	add.s	$f4,$f6,$f10
/*    217c8:	c6460020 */ 	lwc1	$f6,0x20($s2)
/*    217cc:	46064282 */ 	mul.s	$f10,$f8,$f6
/*    217d0:	c6460030 */ 	lwc1	$f6,0x30($s2)
/*    217d4:	460a2200 */ 	add.s	$f8,$f4,$f10
/*    217d8:	46083100 */ 	add.s	$f4,$f6,$f8
/*    217dc:	46002287 */ 	neg.s	$f10,$f4
/*    217e0:	e7aa00e0 */ 	swc1	$f10,0xe0($sp)
/*    217e4:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*    217e8:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*    217ec:	46083102 */ 	mul.s	$f4,$f6,$f8
/*    217f0:	c6480014 */ 	lwc1	$f8,0x14($s2)
/*    217f4:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*    217f8:	46083182 */ 	mul.s	$f6,$f6,$f8
/*    217fc:	46062200 */ 	add.s	$f8,$f4,$f6
/*    21800:	c6460024 */ 	lwc1	$f6,0x24($s2)
/*    21804:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*    21808:	46062102 */ 	mul.s	$f4,$f4,$f6
/*    2180c:	46044180 */ 	add.s	$f6,$f8,$f4
/*    21810:	c6480034 */ 	lwc1	$f8,0x34($s2)
/*    21814:	46064100 */ 	add.s	$f4,$f8,$f6
/*    21818:	46002207 */ 	neg.s	$f8,$f4
/*    2181c:	e7a800e4 */ 	swc1	$f8,0xe4($sp)
/*    21820:	c6440008 */ 	lwc1	$f4,0x8($s2)
/*    21824:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*    21828:	46043182 */ 	mul.s	$f6,$f6,$f4
/*    2182c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*    21830:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*    21834:	c64a0018 */ 	lwc1	$f10,0x18($s2)
/*    21838:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*    2183c:	46043280 */ 	add.s	$f10,$f6,$f4
/*    21840:	c6440028 */ 	lwc1	$f4,0x28($s2)
/*    21844:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*    21848:	46043182 */ 	mul.s	$f6,$f6,$f4
/*    2184c:	46065100 */ 	add.s	$f4,$f10,$f6
/*    21850:	c64a0038 */ 	lwc1	$f10,0x38($s2)
/*    21854:	46045180 */ 	add.s	$f6,$f10,$f4
/*    21858:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*    2185c:	46003287 */ 	neg.s	$f10,$f6
/*    21860:	46042182 */ 	mul.s	$f6,$f4,$f4
/*    21864:	e7aa00e8 */ 	swc1	$f10,0xe8($sp)
/*    21868:	46084102 */ 	mul.s	$f4,$f8,$f8
/*    2186c:	46043200 */ 	add.s	$f8,$f6,$f4
/*    21870:	460a5282 */ 	mul.s	$f10,$f10,$f10
/*    21874:	0c012974 */ 	jal	sqrtf
/*    21878:	46085300 */ 	add.s	$f12,$f10,$f8
/*    2187c:	44807000 */ 	mtc1	$zero,$f14
/*    21880:	00000000 */ 	nop
/*    21884:	4600703c */ 	c.lt.s	$f14,$f0
/*    21888:	00000000 */ 	nop
/*    2188c:	45020012 */ 	bc1fl	.L000218d8
/*    21890:	8faf0114 */ 	lw	$t7,0x114($sp)
/*    21894:	8fac0114 */ 	lw	$t4,0x114($sp)
/*    21898:	3c013f80 */ 	lui	$at,0x3f80
/*    2189c:	44813000 */ 	mtc1	$at,$f6
/*    218a0:	c5840014 */ 	lwc1	$f4,0x14($t4)
/*    218a4:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*    218a8:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    218ac:	460a3083 */ 	div.s	$f2,$f6,$f10
/*    218b0:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*    218b4:	46024102 */ 	mul.s	$f4,$f8,$f2
/*    218b8:	c7a800e8 */ 	lwc1	$f8,0xe8($sp)
/*    218bc:	46023282 */ 	mul.s	$f10,$f6,$f2
/*    218c0:	e7a400e0 */ 	swc1	$f4,0xe0($sp)
/*    218c4:	46024102 */ 	mul.s	$f4,$f8,$f2
/*    218c8:	e7aa00e4 */ 	swc1	$f10,0xe4($sp)
/*    218cc:	10000009 */ 	b	.L000218f4
/*    218d0:	e7a400e8 */ 	swc1	$f4,0xe8($sp)
/*    218d4:	8faf0114 */ 	lw	$t7,0x114($sp)
.L000218d8:
/*    218d8:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
/*    218dc:	e7ae00e4 */ 	swc1	$f14,0xe4($sp)
/*    218e0:	3c013f80 */ 	lui	$at,0x3f80
/*    218e4:	44813000 */ 	mtc1	$at,$f6
/*    218e8:	c5ea0014 */ 	lwc1	$f10,0x14($t7)
/*    218ec:	460a3203 */ 	div.s	$f8,$f6,$f10
/*    218f0:	e7a800e8 */ 	swc1	$f8,0xe8($sp)
.L000218f4:
/*    218f4:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*    218f8:	c6460010 */ 	lwc1	$f6,0x10($s2)
/*    218fc:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*    21900:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    21904:	c6440014 */ 	lwc1	$f4,0x14($s2)
/*    21908:	46044182 */ 	mul.s	$f6,$f8,$f4
/*    2190c:	c6440018 */ 	lwc1	$f4,0x18($s2)
/*    21910:	46065200 */ 	add.s	$f8,$f10,$f6
/*    21914:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*    21918:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*    2191c:	0fc25a74 */ 	jal	func0f0969d0
/*    21920:	46083300 */ 	add.s	$f12,$f6,$f8
/*    21924:	e7a000ec */ 	swc1	$f0,0xec($sp)
/*    21928:	0c0068f7 */ 	jal	sinf
/*    2192c:	46000306 */ 	mov.s	$f12,$f0
/*    21930:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*    21934:	c64a0020 */ 	lwc1	$f10,0x20($s2)
/*    21938:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*    2193c:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*    21940:	c6440024 */ 	lwc1	$f4,0x24($s2)
/*    21944:	46044282 */ 	mul.s	$f10,$f8,$f4
/*    21948:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*    2194c:	460a3200 */ 	add.s	$f8,$f6,$f10
/*    21950:	c6460028 */ 	lwc1	$f6,0x28($s2)
/*    21954:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    21958:	460a4100 */ 	add.s	$f4,$f8,$f10
/*    2195c:	46002187 */ 	neg.s	$f6,$f4
/*    21960:	0fc25a74 */ 	jal	func0f0969d0
/*    21964:	46003303 */ 	div.s	$f12,$f6,$f0
/*    21968:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*    2196c:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*    21970:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*    21974:	46000306 */ 	mov.s	$f12,$f0
/*    21978:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    2197c:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*    21980:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    21984:	c6480008 */ 	lwc1	$f8,0x8($s2)
/*    21988:	460a2180 */ 	add.s	$f6,$f4,$f10
/*    2198c:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*    21990:	46044282 */ 	mul.s	$f10,$f8,$f4
/*    21994:	44804000 */ 	mtc1	$zero,$f8
/*    21998:	46065080 */ 	add.s	$f2,$f10,$f6
/*    2199c:	46001087 */ 	neg.s	$f2,$f2
/*    219a0:	4608103c */ 	c.lt.s	$f2,$f8
/*    219a4:	00000000 */ 	nop
/*    219a8:	45000003 */ 	bc1f	.L000219b8
/*    219ac:	3c017005 */ 	lui	$at,%hi(var70054454)
/*    219b0:	c4244454 */ 	lwc1	$f4,%lo(var70054454)($at)
/*    219b4:	46002301 */ 	sub.s	$f12,$f4,$f0
.L000219b8:
/*    219b8:	0c0068f4 */ 	jal	cosf
/*    219bc:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*    219c0:	c7ac00f0 */ 	lwc1	$f12,0xf0($sp)
/*    219c4:	0c0068f7 */ 	jal	sinf
/*    219c8:	e7a000dc */ 	swc1	$f0,0xdc($sp)
/*    219cc:	e7a000d8 */ 	swc1	$f0,0xd8($sp)
/*    219d0:	0c0068f4 */ 	jal	cosf
/*    219d4:	c7ac00ec */ 	lwc1	$f12,0xec($sp)
/*    219d8:	e7a000d4 */ 	swc1	$f0,0xd4($sp)
/*    219dc:	0c0068f7 */ 	jal	sinf
/*    219e0:	c7ac00ec */ 	lwc1	$f12,0xec($sp)
/*    219e4:	0c004b70 */ 	jal	random
/*    219e8:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
/*    219ec:	304d007f */ 	andi	$t5,$v0,0x7f
/*    219f0:	448d5000 */ 	mtc1	$t5,$f10
/*    219f4:	3c013f00 */ 	lui	$at,0x3f00
/*    219f8:	44810000 */ 	mtc1	$at,$f0
/*    219fc:	c7ae00dc */ 	lwc1	$f14,0xdc($sp)
/*    21a00:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*    21a04:	c7b200d4 */ 	lwc1	$f18,0xd4($sp)
/*    21a08:	05a10005 */ 	bgez	$t5,.L00021a20
/*    21a0c:	468051a0 */ 	cvt.s.w	$f6,$f10
/*    21a10:	3c014f80 */ 	lui	$at,0x4f80
/*    21a14:	44814000 */ 	mtc1	$at,$f8
/*    21a18:	00000000 */ 	nop
/*    21a1c:	46083180 */ 	add.s	$f6,$f6,$f8
.L00021a20:
/*    21a20:	3c013b80 */ 	lui	$at,0x3b80
/*    21a24:	44812000 */ 	mtc1	$at,$f4
/*    21a28:	3c013f40 */ 	lui	$at,0x3f40
/*    21a2c:	44814000 */ 	mtc1	$at,$f8
/*    21a30:	46043282 */ 	mul.s	$f10,$f6,$f4
/*    21a34:	c626000c */ 	lwc1	$f6,0xc($s1)
/*    21a38:	3c198006 */ 	lui	$t9,%hi(var8005efc8)
/*    21a3c:	8f39efc8 */ 	lw	$t9,%lo(var8005efc8)($t9)
/*    21a40:	24040004 */ 	addiu	$a0,$zero,0x4
/*    21a44:	46085080 */ 	add.s	$f2,$f10,$f8
/*    21a48:	46023102 */ 	mul.s	$f4,$f6,$f2
/*    21a4c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*    21a50:	c62a0010 */ 	lwc1	$f10,0x10($s1)
/*    21a54:	46025202 */ 	mul.s	$f8,$f10,$f2
/*    21a58:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*    21a5c:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*    21a60:	c6260014 */ 	lwc1	$f6,0x14($s1)
/*    21a64:	46023102 */ 	mul.s	$f4,$f6,$f2
/*    21a68:	00000000 */ 	nop
/*    21a6c:	460e5202 */ 	mul.s	$f8,$f10,$f14
/*    21a70:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*    21a74:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*    21a78:	46004182 */ 	mul.s	$f6,$f8,$f0
/*    21a7c:	00000000 */ 	nop
/*    21a80:	46102202 */ 	mul.s	$f8,$f4,$f16
/*    21a84:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*    21a88:	46004182 */ 	mul.s	$f6,$f8,$f0
/*    21a8c:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*    21a90:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*    21a94:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*    21a98:	46064202 */ 	mul.s	$f8,$f8,$f6
/*    21a9c:	00000000 */ 	nop
/*    21aa0:	46004302 */ 	mul.s	$f12,$f8,$f0
/*    21aa4:	00000000 */ 	nop
/*    21aa8:	46125182 */ 	mul.s	$f6,$f10,$f18
/*    21aac:	00000000 */ 	nop
/*    21ab0:	46103202 */ 	mul.s	$f8,$f6,$f16
/*    21ab4:	00000000 */ 	nop
/*    21ab8:	46004182 */ 	mul.s	$f6,$f8,$f0
/*    21abc:	00000000 */ 	nop
/*    21ac0:	46122202 */ 	mul.s	$f8,$f4,$f18
/*    21ac4:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*    21ac8:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*    21acc:	00000000 */ 	nop
/*    21ad0:	46003102 */ 	mul.s	$f4,$f6,$f0
/*    21ad4:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*    21ad8:	46005182 */ 	mul.s	$f6,$f10,$f0
/*    21adc:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*    21ae0:	46064101 */ 	sub.s	$f4,$f8,$f6
/*    21ae4:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*    21ae8:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*    21aec:	e7aa0094 */ 	swc1	$f10,0x94($sp)
/*    21af0:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*    21af4:	e7ac00c4 */ 	swc1	$f12,0xc4($sp)
/*    21af8:	0320f809 */ 	jalr	$t9
/*    21afc:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*    21b00:	00408025 */ 	or	$s0,$v0,$zero
/*    21b04:	0fc59e73 */ 	jal	func0f1679cc
/*    21b08:	24040001 */ 	addiu	$a0,$zero,0x1
/*    21b0c:	27a30084 */ 	addiu	$v1,$sp,0x84
/*    21b10:	afa20078 */ 	sw	$v0,0x78($sp)
/*    21b14:	8c610000 */ 	lw	$at,0x0($v1)
/*    21b18:	c7ac00c4 */ 	lwc1	$f12,0xc4($sp)
/*    21b1c:	aa010000 */ 	swl	$at,0x0($s0)
/*    21b20:	ba010003 */ 	swr	$at,0x3($s0)
/*    21b24:	8c780004 */ 	lw	$t8,0x4($v1)
/*    21b28:	aa180004 */ 	swl	$t8,0x4($s0)
/*    21b2c:	ba180007 */ 	swr	$t8,0x7($s0)
/*    21b30:	8c610008 */ 	lw	$at,0x8($v1)
/*    21b34:	aa010008 */ 	swl	$at,0x8($s0)
/*    21b38:	ba01000b */ 	swr	$at,0xb($s0)
/*    21b3c:	8c610000 */ 	lw	$at,0x0($v1)
/*    21b40:	aa01000c */ 	swl	$at,0xc($s0)
/*    21b44:	ba01000f */ 	swr	$at,0xf($s0)
/*    21b48:	8c6d0004 */ 	lw	$t5,0x4($v1)
/*    21b4c:	aa0d0010 */ 	swl	$t5,0x10($s0)
/*    21b50:	ba0d0013 */ 	swr	$t5,0x13($s0)
/*    21b54:	8c610008 */ 	lw	$at,0x8($v1)
/*    21b58:	27ad0080 */ 	addiu	$t5,$sp,0x80
/*    21b5c:	aa010014 */ 	swl	$at,0x14($s0)
/*    21b60:	ba010017 */ 	swr	$at,0x17($s0)
/*    21b64:	8c610000 */ 	lw	$at,0x0($v1)
/*    21b68:	aa010018 */ 	swl	$at,0x18($s0)
/*    21b6c:	ba01001b */ 	swr	$at,0x1b($s0)
/*    21b70:	8c6e0004 */ 	lw	$t6,0x4($v1)
/*    21b74:	aa0e001c */ 	swl	$t6,0x1c($s0)
/*    21b78:	ba0e001f */ 	swr	$t6,0x1f($s0)
/*    21b7c:	8c610008 */ 	lw	$at,0x8($v1)
/*    21b80:	aa010020 */ 	swl	$at,0x20($s0)
/*    21b84:	ba010023 */ 	swr	$at,0x23($s0)
/*    21b88:	8c610000 */ 	lw	$at,0x0($v1)
/*    21b8c:	aa010024 */ 	swl	$at,0x24($s0)
/*    21b90:	ba010027 */ 	swr	$at,0x27($s0)
/*    21b94:	8c6c0004 */ 	lw	$t4,0x4($v1)
/*    21b98:	aa0c0028 */ 	swl	$t4,0x28($s0)
/*    21b9c:	ba0c002b */ 	swr	$t4,0x2b($s0)
/*    21ba0:	8c610008 */ 	lw	$at,0x8($v1)
/*    21ba4:	aa01002c */ 	swl	$at,0x2c($s0)
/*    21ba8:	ba01002f */ 	swr	$at,0x2f($s0)
/*    21bac:	8da10000 */ 	lw	$at,0x0($t5)
/*    21bb0:	ac410000 */ 	sw	$at,0x0($v0)
/*    21bb4:	c7a000cc */ 	lwc1	$f0,0xcc($sp)
/*    21bb8:	c7a60090 */ 	lwc1	$f6,0x90($sp)
/*    21bbc:	c7ae00c0 */ 	lwc1	$f14,0xc0($sp)
/*    21bc0:	46000007 */ 	neg.s	$f0,$f0
/*    21bc4:	46003100 */ 	add.s	$f4,$f6,$f0
/*    21bc8:	46007387 */ 	neg.s	$f14,$f14
/*    21bcc:	460e2280 */ 	add.s	$f10,$f4,$f14
/*    21bd0:	4600520d */ 	trunc.w.s	$f8,$f10
/*    21bd4:	44184000 */ 	mfc1	$t8,$f8
/*    21bd8:	00000000 */ 	nop
/*    21bdc:	a6180000 */ 	sh	$t8,0x0($s0)
/*    21be0:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*    21be4:	460c3101 */ 	sub.s	$f4,$f6,$f12
/*    21be8:	4600228d */ 	trunc.w.s	$f10,$f4
/*    21bec:	44195000 */ 	mfc1	$t9,$f10
/*    21bf0:	00000000 */ 	nop
/*    21bf4:	a6190002 */ 	sh	$t9,0x2($s0)
/*    21bf8:	c7a200c8 */ 	lwc1	$f2,0xc8($sp)
/*    21bfc:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*    21c00:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*    21c04:	46001087 */ 	neg.s	$f2,$f2
/*    21c08:	46024181 */ 	sub.s	$f6,$f8,$f2
/*    21c0c:	46008407 */ 	neg.s	$f16,$f16
/*    21c10:	46103100 */ 	add.s	$f4,$f6,$f16
/*    21c14:	4600228d */ 	trunc.w.s	$f10,$f4
/*    21c18:	440d5000 */ 	mfc1	$t5,$f10
/*    21c1c:	00000000 */ 	nop
/*    21c20:	a60d0004 */ 	sh	$t5,0x4($s0)
/*    21c24:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*    21c28:	46004180 */ 	add.s	$f6,$f8,$f0
/*    21c2c:	460e3101 */ 	sub.s	$f4,$f6,$f14
/*    21c30:	4600228d */ 	trunc.w.s	$f10,$f4
/*    21c34:	440f5000 */ 	mfc1	$t7,$f10
/*    21c38:	00000000 */ 	nop
/*    21c3c:	a60f000c */ 	sh	$t7,0xc($s0)
/*    21c40:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*    21c44:	460c4180 */ 	add.s	$f6,$f8,$f12
/*    21c48:	4600310d */ 	trunc.w.s	$f4,$f6
/*    21c4c:	440c2000 */ 	mfc1	$t4,$f4
/*    21c50:	00000000 */ 	nop
/*    21c54:	a60c000e */ 	sh	$t4,0xe($s0)
/*    21c58:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*    21c5c:	46025201 */ 	sub.s	$f8,$f10,$f2
/*    21c60:	46104181 */ 	sub.s	$f6,$f8,$f16
/*    21c64:	4600310d */ 	trunc.w.s	$f4,$f6
/*    21c68:	440b2000 */ 	mfc1	$t3,$f4
/*    21c6c:	00000000 */ 	nop
/*    21c70:	a60b0010 */ 	sh	$t3,0x10($s0)
/*    21c74:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*    21c78:	3c0bbc00 */ 	lui	$t3,0xbc00
/*    21c7c:	356b1406 */ 	ori	$t3,$t3,0x1406
/*    21c80:	46005201 */ 	sub.s	$f8,$f10,$f0
/*    21c84:	460e4181 */ 	sub.s	$f6,$f8,$f14
/*    21c88:	4600310d */ 	trunc.w.s	$f4,$f6
/*    21c8c:	440e2000 */ 	mfc1	$t6,$f4
/*    21c90:	00000000 */ 	nop
/*    21c94:	a60e0018 */ 	sh	$t6,0x18($s0)
/*    21c98:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
/*    21c9c:	460c5200 */ 	add.s	$f8,$f10,$f12
/*    21ca0:	4600418d */ 	trunc.w.s	$f6,$f8
/*    21ca4:	44183000 */ 	mfc1	$t8,$f6
/*    21ca8:	00000000 */ 	nop
/*    21cac:	a618001a */ 	sh	$t8,0x1a($s0)
/*    21cb0:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*    21cb4:	46022280 */ 	add.s	$f10,$f4,$f2
/*    21cb8:	46105201 */ 	sub.s	$f8,$f10,$f16
/*    21cbc:	4600418d */ 	trunc.w.s	$f6,$f8
/*    21cc0:	44193000 */ 	mfc1	$t9,$f6
/*    21cc4:	00000000 */ 	nop
/*    21cc8:	a619001c */ 	sh	$t9,0x1c($s0)
/*    21ccc:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*    21cd0:	46002281 */ 	sub.s	$f10,$f4,$f0
/*    21cd4:	460e5200 */ 	add.s	$f8,$f10,$f14
/*    21cd8:	4600418d */ 	trunc.w.s	$f6,$f8
/*    21cdc:	440d3000 */ 	mfc1	$t5,$f6
/*    21ce0:	00000000 */ 	nop
/*    21ce4:	a60d0024 */ 	sh	$t5,0x24($s0)
/*    21ce8:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*    21cec:	460c2281 */ 	sub.s	$f10,$f4,$f12
/*    21cf0:	4600520d */ 	trunc.w.s	$f8,$f10
/*    21cf4:	440f4000 */ 	mfc1	$t7,$f8
/*    21cf8:	00000000 */ 	nop
/*    21cfc:	a60f0026 */ 	sh	$t7,0x26($s0)
/*    21d00:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*    21d04:	46023100 */ 	add.s	$f4,$f6,$f2
/*    21d08:	46102280 */ 	add.s	$f10,$f4,$f16
/*    21d0c:	4600520d */ 	trunc.w.s	$f8,$f10
/*    21d10:	440c4000 */ 	mfc1	$t4,$f8
/*    21d14:	00000000 */ 	nop
/*    21d18:	a60c0028 */ 	sh	$t4,0x28($s0)
/*    21d1c:	8e63000c */ 	lw	$v1,0xc($s3)
/*    21d20:	24790008 */ 	addiu	$t9,$v1,0x8
/*    21d24:	ae79000c */ 	sw	$t9,0xc($s3)
/*    21d28:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*    21d2c:	8e240024 */ 	lw	$a0,0x24($s1)
/*    21d30:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21d34:	afa30068 */ 	sw	$v1,0x68($sp)
/*    21d38:	8fa50068 */ 	lw	$a1,0x68($sp)
/*    21d3c:	02602025 */ 	or	$a0,$s3,$zero
/*    21d40:	aca20004 */ 	sw	$v0,0x4($a1)
/*    21d44:	8e230018 */ 	lw	$v1,0x18($s1)
/*    21d48:	00002825 */ 	or	$a1,$zero,$zero
/*    21d4c:	10600036 */ 	beqz	$v1,.L00021e28
/*    21d50:	00000000 */ 	nop
/*    21d54:	0c004b70 */ 	jal	random
/*    21d58:	00608825 */ 	or	$s1,$v1,$zero
/*    21d5c:	00026a80 */ 	sll	$t5,$v0,0xa
/*    21d60:	a7ad0062 */ 	sh	$t5,0x62($sp)
/*    21d64:	0c013ef0 */ 	jal	func0004fbc0
/*    21d68:	31a4ffff */ 	andi	$a0,$t5,0xffff
/*    21d6c:	922e0004 */ 	lbu	$t6,0x4($s1)
/*    21d70:	97a40062 */ 	lhu	$a0,0x62($sp)
/*    21d74:	004e0019 */ 	multu	$v0,$t6
/*    21d78:	00004012 */ 	mflo	$t0
/*    21d7c:	00087880 */ 	sll	$t7,$t0,0x2
/*    21d80:	01e87823 */ 	subu	$t7,$t7,$t0
/*    21d84:	000f7880 */ 	sll	$t7,$t7,0x2
/*    21d88:	01e87823 */ 	subu	$t7,$t7,$t0
/*    21d8c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    21d90:	01e87821 */ 	addu	$t7,$t7,$t0
/*    21d94:	000f7880 */ 	sll	$t7,$t7,0x2
/*    21d98:	01e87821 */ 	addu	$t7,$t7,$t0
/*    21d9c:	000fc483 */ 	sra	$t8,$t7,0x12
/*    21da0:	0c013efc */ 	jal	func0004fbf0
/*    21da4:	afb8005c */ 	sw	$t8,0x5c($sp)
/*    21da8:	92240004 */ 	lbu	$a0,0x4($s1)
/*    21dac:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    21db0:	00440019 */ 	multu	$v0,$a0
/*    21db4:	00041900 */ 	sll	$v1,$a0,0x4
/*    21db8:	00683023 */ 	subu	$a2,$v1,$t0
/*    21dbc:	a6060008 */ 	sh	$a2,0x8($s0)
/*    21dc0:	a6060016 */ 	sh	$a2,0x16($s0)
/*    21dc4:	00685021 */ 	addu	$t2,$v1,$t0
/*    21dc8:	a60a0020 */ 	sh	$t2,0x20($s0)
/*    21dcc:	a60a002e */ 	sh	$t2,0x2e($s0)
/*    21dd0:	24060004 */ 	addiu	$a2,$zero,0x4
/*    21dd4:	02602025 */ 	or	$a0,$s3,$zero
/*    21dd8:	00002812 */ 	mflo	$a1
/*    21ddc:	00056080 */ 	sll	$t4,$a1,0x2
/*    21de0:	01856023 */ 	subu	$t4,$t4,$a1
/*    21de4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    21de8:	01856023 */ 	subu	$t4,$t4,$a1
/*    21dec:	000c6080 */ 	sll	$t4,$t4,0x2
/*    21df0:	01856021 */ 	addu	$t4,$t4,$a1
/*    21df4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    21df8:	01856021 */ 	addu	$t4,$t4,$a1
/*    21dfc:	000ccc83 */ 	sra	$t9,$t4,0x12
/*    21e00:	00794823 */ 	subu	$t1,$v1,$t9
/*    21e04:	00793821 */ 	addu	$a3,$v1,$t9
/*    21e08:	a609000a */ 	sh	$t1,0xa($s0)
/*    21e0c:	a6070014 */ 	sh	$a3,0x14($s0)
/*    21e10:	a6070022 */ 	sh	$a3,0x22($s0)
/*    21e14:	a609002c */ 	sh	$t1,0x2c($s0)
/*    21e18:	0c0085b3 */ 	jal	func000216cc
/*    21e1c:	02202825 */ 	or	$a1,$s1,$zero
/*    21e20:	10000004 */ 	b	.L00021e34
/*    21e24:	8e63000c */ 	lw	$v1,0xc($s3)
.L00021e28:
/*    21e28:	0c0085b3 */ 	jal	func000216cc
/*    21e2c:	24060001 */ 	addiu	$a2,$zero,0x1
/*    21e30:	8e63000c */ 	lw	$v1,0xc($s3)
.L00021e34:
/*    21e34:	3c0db700 */ 	lui	$t5,0xb700
/*    21e38:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*    21e3c:	246b0008 */ 	addiu	$t3,$v1,0x8
/*    21e40:	ae6b000c */ 	sw	$t3,0xc($s3)
/*    21e44:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*    21e48:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*    21e4c:	8e71000c */ 	lw	$s1,0xc($s3)
/*    21e50:	3c180102 */ 	lui	$t8,0x102
/*    21e54:	37180040 */ 	ori	$t8,$t8,0x40
/*    21e58:	262f0008 */ 	addiu	$t7,$s1,0x8
/*    21e5c:	ae6f000c */ 	sw	$t7,0xc($s3)
/*    21e60:	02402025 */ 	or	$a0,$s2,$zero
/*    21e64:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21e68:	ae380000 */ 	sw	$t8,0x0($s1)
/*    21e6c:	ae220004 */ 	sw	$v0,0x4($s1)
/*    21e70:	8e72000c */ 	lw	$s2,0xc($s3)
/*    21e74:	3c190700 */ 	lui	$t9,0x700
/*    21e78:	37390004 */ 	ori	$t9,$t9,0x4
/*    21e7c:	264c0008 */ 	addiu	$t4,$s2,0x8
/*    21e80:	ae6c000c */ 	sw	$t4,0xc($s3)
/*    21e84:	ae590000 */ 	sw	$t9,0x0($s2)
/*    21e88:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21e8c:	8fa40078 */ 	lw	$a0,0x78($sp)
/*    21e90:	ae420004 */ 	sw	$v0,0x4($s2)
/*    21e94:	8e71000c */ 	lw	$s1,0xc($s3)
/*    21e98:	3c0d0430 */ 	lui	$t5,0x430
/*    21e9c:	35ad0030 */ 	ori	$t5,$t5,0x30
/*    21ea0:	262b0008 */ 	addiu	$t3,$s1,0x8
/*    21ea4:	ae6b000c */ 	sw	$t3,0xc($s3)
/*    21ea8:	02002025 */ 	or	$a0,$s0,$zero
/*    21eac:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21eb0:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*    21eb4:	ae220004 */ 	sw	$v0,0x4($s1)
/*    21eb8:	8e63000c */ 	lw	$v1,0xc($s3)
/*    21ebc:	3c0fb100 */ 	lui	$t7,0xb100
/*    21ec0:	35ef0002 */ 	ori	$t7,$t7,0x2
/*    21ec4:	246e0008 */ 	addiu	$t6,$v1,0x8
/*    21ec8:	ae6e000c */ 	sw	$t6,0xc($s3)
/*    21ecc:	24183210 */ 	addiu	$t8,$zero,0x3210
/*    21ed0:	ac780004 */ 	sw	$t8,0x4($v1)
/*    21ed4:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    21ed8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00021edc:
/*    21edc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    21ee0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    21ee4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    21ee8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    21eec:	03e00008 */ 	jr	$ra
/*    21ef0:	27bd0110 */ 	addiu	$sp,$sp,0x110
);

GLOBAL_ASM(
glabel func00021ef4
.late_rodata
glabel var70054458
.word 0x7002209c
glabel var7005445c
.word 0x7002209c
glabel var70054460
.word 0x7002209c
glabel var70054464
.word 0x70022058
glabel var70054468
.word 0x7002209c
glabel var7005446c
.word 0x7002209c
glabel var70054470
.word 0x7002209c
glabel var70054474
.word 0x70021f78
glabel var70054478
.word 0x7002202c
glabel var7005447c
.word 0x7002209c
glabel var70054480
.word 0x7002209c
glabel var70054484
.word 0x70022040
glabel var70054488
.word 0x7002209c
glabel var7005448c
.word 0x7002209c
glabel var70054490
.word 0x7002209c
glabel var70054494
.word 0x7002209c
glabel var70054498
.word 0x7002209c
glabel var7005449c
.word 0x70021f78
glabel var700544a0
.word 0x7002209c
glabel var700544a4
.word 0x7002209c
glabel var700544a8
.word 0x7002209c
glabel var700544ac
.word 0x70022088
glabel var700544b0
.word 0x70021ff0
glabel var700544b4
.word 0x70022070
.text
/*    21ef4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    21ef8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    21efc:	afb30020 */ 	sw	$s3,0x20($sp)
/*    21f00:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    21f04:	afb10018 */ 	sw	$s1,0x18($sp)
/*    21f08:	afb00014 */ 	sw	$s0,0x14($sp)
/*    21f0c:	8cae0008 */ 	lw	$t6,0x8($a1)
/*    21f10:	8c82000c */ 	lw	$v0,0xc($a0)
/*    21f14:	3c18bc00 */ 	lui	$t8,0xbc00
/*    21f18:	8dd00000 */ 	lw	$s0,0x0($t6)
/*    21f1c:	244f0008 */ 	addiu	$t7,$v0,0x8
/*    21f20:	ac8f000c */ 	sw	$t7,0xc($a0)
/*    21f24:	37180c06 */ 	ori	$t8,$t8,0xc06
/*    21f28:	00809825 */ 	or	$s3,$a0,$zero
/*    21f2c:	ac580000 */ 	sw	$t8,0x0($v0)
/*    21f30:	00a09025 */ 	or	$s2,$a1,$zero
/*    21f34:	8ca4000c */ 	lw	$a0,0xc($a1)
/*    21f38:	0c012d20 */ 	jal	osVirtualToPhysical
/*    21f3c:	00408825 */ 	or	$s1,$v0,$zero
/*    21f40:	12000067 */ 	beqz	$s0,.L000220e0
/*    21f44:	ae220004 */ 	sw	$v0,0x4($s1)
/*    21f48:	96030000 */ 	lhu	$v1,0x0($s0)
.L00021f4c:
/*    21f4c:	307900ff */ 	andi	$t9,$v1,0xff
/*    21f50:	2728ffff */ 	addiu	$t0,$t9,-1
/*    21f54:	2d010018 */ 	sltiu	$at,$t0,0x18
/*    21f58:	10200050 */ 	beqz	$at,.L0002209c
/*    21f5c:	03201825 */ 	or	$v1,$t9,$zero
/*    21f60:	00084080 */ 	sll	$t0,$t0,0x2
/*    21f64:	3c017005 */ 	lui	$at,%hi(var70054458)
/*    21f68:	00280821 */ 	addu	$at,$at,$t0
/*    21f6c:	8c284458 */ 	lw	$t0,%lo(var70054458)($at)
/*    21f70:	01000008 */ 	jr	$t0
/*    21f74:	00000000 */ 	nop
/*    21f78:	8e110004 */ 	lw	$s1,0x4($s0)
/*    21f7c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*    21f80:	02402025 */ 	or	$a0,$s2,$zero
/*    21f84:	0c006a87 */ 	jal	modelGetNodeData
/*    21f88:	02002825 */ 	or	$a1,$s0,$zero
/*    21f8c:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*    21f90:	24010008 */ 	addiu	$at,$zero,0x8
/*    21f94:	10610005 */ 	beq	$v1,$at,.L00021fac
/*    21f98:	24010012 */ 	addiu	$at,$zero,0x12
/*    21f9c:	5061000c */ 	beql	$v1,$at,.L00021fd0
/*    21fa0:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*    21fa4:	10000010 */ 	b	.L00021fe8
/*    21fa8:	00000000 */ 	nop
.L00021fac:
/*    21fac:	8c490000 */ 	lw	$t1,0x0($v0)
/*    21fb0:	11200004 */ 	beqz	$t1,.L00021fc4
/*    21fb4:	00000000 */ 	nop
/*    21fb8:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*    21fbc:	1000000a */ 	b	.L00021fe8
/*    21fc0:	ae0a0014 */ 	sw	$t2,0x14($s0)
.L00021fc4:
/*    21fc4:	10000008 */ 	b	.L00021fe8
/*    21fc8:	ae000014 */ 	sw	$zero,0x14($s0)
/*    21fcc:	8c4b0000 */ 	lw	$t3,0x0($v0)
.L00021fd0:
/*    21fd0:	51600005 */ 	beqzl	$t3,.L00021fe8
/*    21fd4:	ae000014 */ 	sw	$zero,0x14($s0)
/*    21fd8:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*    21fdc:	10000002 */ 	b	.L00021fe8
/*    21fe0:	ae0c0014 */ 	sw	$t4,0x14($s0)
/*    21fe4:	ae000014 */ 	sw	$zero,0x14($s0)
.L00021fe8:
/*    21fe8:	1000002d */ 	b	.L000220a0
/*    21fec:	8e020014 */ 	lw	$v0,0x14($s0)
/*    21ff0:	02402025 */ 	or	$a0,$s2,$zero
/*    21ff4:	0c006a87 */ 	jal	modelGetNodeData
/*    21ff8:	02002825 */ 	or	$a1,$s0,$zero
/*    21ffc:	8c440000 */ 	lw	$a0,0x0($v0)
/*    22000:	10800008 */ 	beqz	$a0,.L00022024
/*    22004:	00000000 */ 	nop
/*    22008:	8c830000 */ 	lw	$v1,0x0($a0)
/*    2200c:	10600005 */ 	beqz	$v1,.L00022024
/*    22010:	ae030014 */ 	sw	$v1,0x14($s0)
/*    22014:	ac700008 */ 	sw	$s0,0x8($v1)
.L00022018:
/*    22018:	8c63000c */ 	lw	$v1,0xc($v1)
/*    2201c:	5460fffe */ 	bnezl	$v1,.L00022018
/*    22020:	ac700008 */ 	sw	$s0,0x8($v1)
.L00022024:
/*    22024:	1000001e */ 	b	.L000220a0
/*    22028:	8e020014 */ 	lw	$v0,0x14($s0)
/*    2202c:	02402025 */ 	or	$a0,$s2,$zero
/*    22030:	0c007249 */ 	jal	func0001c924
/*    22034:	02002825 */ 	or	$a1,$s0,$zero
/*    22038:	10000019 */ 	b	.L000220a0
/*    2203c:	8e020014 */ 	lw	$v0,0x14($s0)
/*    22040:	02602025 */ 	or	$a0,$s3,$zero
/*    22044:	02402825 */ 	or	$a1,$s2,$zero
/*    22048:	0c0085c3 */ 	jal	func0002170c
/*    2204c:	02003025 */ 	or	$a2,$s0,$zero
/*    22050:	10000013 */ 	b	.L000220a0
/*    22054:	8e020014 */ 	lw	$v0,0x14($s0)
/*    22058:	02602025 */ 	or	$a0,$s3,$zero
/*    2205c:	02402825 */ 	or	$a1,$s2,$zero
/*    22060:	0c008347 */ 	jal	func00020d1c
/*    22064:	02003025 */ 	or	$a2,$s0,$zero
/*    22068:	1000000d */ 	b	.L000220a0
/*    2206c:	8e020014 */ 	lw	$v0,0x14($s0)
/*    22070:	02602025 */ 	or	$a0,$s3,$zero
/*    22074:	02402825 */ 	or	$a1,$s2,$zero
/*    22078:	0c0083cc */ 	jal	func00020f30
/*    2207c:	02003025 */ 	or	$a2,$s0,$zero
/*    22080:	10000007 */ 	b	.L000220a0
/*    22084:	8e020014 */ 	lw	$v0,0x14($s0)
/*    22088:	02602025 */ 	or	$a0,$s3,$zero
/*    2208c:	0c008493 */ 	jal	func0002124c
/*    22090:	02002825 */ 	or	$a1,$s0,$zero
/*    22094:	10000002 */ 	b	.L000220a0
/*    22098:	8e020014 */ 	lw	$v0,0x14($s0)
.L0002209c:
/*    2209c:	8e020014 */ 	lw	$v0,0x14($s0)
.L000220a0:
/*    220a0:	10400003 */ 	beqz	$v0,.L000220b0
/*    220a4:	00000000 */ 	nop
/*    220a8:	1000000b */ 	b	.L000220d8
/*    220ac:	00408025 */ 	or	$s0,$v0,$zero
.L000220b0:
/*    220b0:	12000009 */ 	beqz	$s0,.L000220d8
/*    220b4:	00000000 */ 	nop
/*    220b8:	8e02000c */ 	lw	$v0,0xc($s0)
.L000220bc:
/*    220bc:	50400004 */ 	beqzl	$v0,.L000220d0
/*    220c0:	8e100008 */ 	lw	$s0,0x8($s0)
/*    220c4:	10000004 */ 	b	.L000220d8
/*    220c8:	00408025 */ 	or	$s0,$v0,$zero
/*    220cc:	8e100008 */ 	lw	$s0,0x8($s0)
.L000220d0:
/*    220d0:	5600fffa */ 	bnezl	$s0,.L000220bc
/*    220d4:	8e02000c */ 	lw	$v0,0xc($s0)
.L000220d8:
/*    220d8:	5600ff9c */ 	bnezl	$s0,.L00021f4c
/*    220dc:	96030000 */ 	lhu	$v1,0x0($s0)
.L000220e0:
/*    220e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    220e4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    220e8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    220ec:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    220f0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    220f4:	03e00008 */ 	jr	$ra
/*    220f8:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func000220fc
/*    220fc:	3c018006 */ 	lui	$at,0x8006
/*    22100:	c424efc0 */ 	lwc1	$f4,-0x1040($at)
/*    22104:	44803000 */ 	mtc1	$zero,$f6
/*    22108:	c480000c */ 	lwc1	$f0,0xc($a0)
/*    2210c:	c4820010 */ 	lwc1	$f2,0x10($a0)
/*    22110:	46043032 */ 	c.eq.s	$f6,$f4
/*    22114:	c48c0014 */ 	lwc1	$f12,0x14($a0)
/*    22118:	c4900018 */ 	lwc1	$f16,0x18($a0)
/*    2211c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*    22120:	c48e0004 */ 	lwc1	$f14,0x4($a0)
/*    22124:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*    22128:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*    2212c:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*    22130:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*    22134:	e7ac0054 */ 	swc1	$f12,0x54($sp)
/*    22138:	4501000b */ 	bc1t	.L00022168
/*    2213c:	e7b00050 */ 	swc1	$f16,0x50($sp)
/*    22140:	46040001 */ 	sub.s	$f0,$f0,$f4
/*    22144:	46041080 */ 	add.s	$f2,$f2,$f4
/*    22148:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*    2214c:	46046301 */ 	sub.s	$f12,$f12,$f4
/*    22150:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*    22154:	46048400 */ 	add.s	$f16,$f16,$f4
/*    22158:	e7ac0054 */ 	swc1	$f12,0x54($sp)
/*    2215c:	46047381 */ 	sub.s	$f14,$f14,$f4
/*    22160:	e7b00050 */ 	swc1	$f16,0x50($sp)
/*    22164:	46049480 */ 	add.s	$f18,$f18,$f4
.L00022168:
/*    22168:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*    2216c:	46000202 */ 	mul.s	$f8,$f0,$f0
/*    22170:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*    22174:	c4a20004 */ 	lwc1	$f2,0x4($a1)
/*    22178:	46021282 */ 	mul.s	$f10,$f2,$f2
/*    2217c:	e7aa00c8 */ 	swc1	$f10,0xc8($sp)
/*    22180:	c4ac0008 */ 	lwc1	$f12,0x8($a1)
/*    22184:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*    22188:	e7a600c4 */ 	swc1	$f6,0xc4($sp)
/*    2218c:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*    22190:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*    22194:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*    22198:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    2219c:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*    221a0:	c7a60010 */ 	lwc1	$f6,0x10($sp)
/*    221a4:	e7aa000c */ 	swc1	$f10,0xc($sp)
/*    221a8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*    221ac:	c7a8000c */ 	lwc1	$f8,0xc($sp)
/*    221b0:	46081282 */ 	mul.s	$f10,$f2,$f8
/*    221b4:	c7a80014 */ 	lwc1	$f8,0x14($sp)
/*    221b8:	460a2180 */ 	add.s	$f6,$f4,$f10
/*    221bc:	460c4102 */ 	mul.s	$f4,$f8,$f12
/*    221c0:	46062280 */ 	add.s	$f10,$f4,$f6
/*    221c4:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*    221c8:	c4a40038 */ 	lwc1	$f4,0x38($a1)
/*    221cc:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*    221d0:	46044181 */ 	sub.s	$f6,$f8,$f4
/*    221d4:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*    221d8:	c4a40030 */ 	lwc1	$f4,0x30($a1)
/*    221dc:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*    221e0:	46044181 */ 	sub.s	$f6,$f8,$f4
/*    221e4:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    221e8:	c4a40034 */ 	lwc1	$f4,0x34($a1)
/*    221ec:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*    221f0:	46044181 */ 	sub.s	$f6,$f8,$f4
/*    221f4:	c7a80004 */ 	lwc1	$f8,0x4($sp)
/*    221f8:	e7a60000 */ 	swc1	$f6,0x0($sp)
/*    221fc:	46080102 */ 	mul.s	$f4,$f0,$f8
/*    22200:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*    22204:	46061202 */ 	mul.s	$f8,$f2,$f6
/*    22208:	44801000 */ 	mtc1	$zero,$f2
/*    2220c:	00000000 */ 	nop
/*    22210:	4602503c */ 	c.lt.s	$f10,$f2
/*    22214:	46082180 */ 	add.s	$f6,$f4,$f8
/*    22218:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    2221c:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    22220:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*    22224:	46064400 */ 	add.s	$f16,$f8,$f6
/*    22228:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*    2222c:	46082180 */ 	add.s	$f6,$f4,$f8
/*    22230:	c7a400c4 */ 	lwc1	$f4,0xc4($sp)
/*    22234:	46043000 */ 	add.s	$f0,$f6,$f4
/*    22238:	46000007 */ 	neg.s	$f0,$f0
/*    2223c:	46120202 */ 	mul.s	$f8,$f0,$f18
/*    22240:	46088180 */ 	add.s	$f6,$f16,$f8
/*    22244:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*    22248:	46003107 */ 	neg.s	$f4,$f6
/*    2224c:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*    22250:	c7ac00ac */ 	lwc1	$f12,0xac($sp)
/*    22254:	46088400 */ 	add.s	$f16,$f16,$f8
/*    22258:	45000006 */ 	bc1f	.L00022274
/*    2225c:	46008407 */ 	neg.s	$f16,$f16
/*    22260:	46005187 */ 	neg.s	$f6,$f10
/*    22264:	46006307 */ 	neg.s	$f12,$f12
/*    22268:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*    2226c:	46008407 */ 	neg.s	$f16,$f16
/*    22270:	e7ac00ac */ 	swc1	$f12,0xac($sp)
.L00022274:
/*    22274:	4602803c */ 	c.lt.s	$f16,$f2
/*    22278:	c7ac00ac */ 	lwc1	$f12,0xac($sp)
/*    2227c:	45020008 */ 	bc1fl	.L000222a0
/*    22280:	4610603c */ 	c.lt.s	$f12,$f16
/*    22284:	4602603c */ 	c.lt.s	$f12,$f2
/*    22288:	00000000 */ 	nop
/*    2228c:	45020004 */ 	bc1fl	.L000222a0
/*    22290:	4610603c */ 	c.lt.s	$f12,$f16
/*    22294:	100000cd */ 	b	.L000225cc
/*    22298:	00001025 */ 	or	$v0,$zero,$zero
/*    2229c:	4610603c */ 	c.lt.s	$f12,$f16
.L000222a0:
/*    222a0:	e7ac00ac */ 	swc1	$f12,0xac($sp)
/*    222a4:	45020005 */ 	bc1fl	.L000222bc
/*    222a8:	c4a00010 */ 	lwc1	$f0,0x10($a1)
/*    222ac:	46008006 */ 	mov.s	$f0,$f16
/*    222b0:	46006406 */ 	mov.s	$f16,$f12
/*    222b4:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*    222b8:	c4a00010 */ 	lwc1	$f0,0x10($a1)
.L000222bc:
/*    222bc:	c7a60010 */ 	lwc1	$f6,0x10($sp)
/*    222c0:	46000102 */ 	mul.s	$f4,$f0,$f0
/*    222c4:	e7a400a0 */ 	swc1	$f4,0xa0($sp)
/*    222c8:	c4a20014 */ 	lwc1	$f2,0x14($a1)
/*    222cc:	46021202 */ 	mul.s	$f8,$f2,$f2
/*    222d0:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*    222d4:	c4ac0018 */ 	lwc1	$f12,0x18($a1)
/*    222d8:	c7a8000c */ 	lwc1	$f8,0xc($sp)
/*    222dc:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*    222e0:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*    222e4:	46060102 */ 	mul.s	$f4,$f0,$f6
/*    222e8:	00000000 */ 	nop
/*    222ec:	46081282 */ 	mul.s	$f10,$f2,$f8
/*    222f0:	c7a80014 */ 	lwc1	$f8,0x14($sp)
/*    222f4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*    222f8:	460c4102 */ 	mul.s	$f4,$f8,$f12
/*    222fc:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    22300:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*    22304:	46062480 */ 	add.s	$f18,$f4,$f6
/*    22308:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    2230c:	46041182 */ 	mul.s	$f6,$f2,$f4
/*    22310:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    22314:	46064280 */ 	add.s	$f10,$f8,$f6
/*    22318:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    2231c:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*    22320:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*    22324:	44806000 */ 	mtc1	$zero,$f12
/*    22328:	460a4380 */ 	add.s	$f14,$f8,$f10
/*    2232c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*    22330:	46043200 */ 	add.s	$f8,$f6,$f4
/*    22334:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*    22338:	460a4000 */ 	add.s	$f0,$f8,$f10
/*    2233c:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*    22340:	46000007 */ 	neg.s	$f0,$f0
/*    22344:	46060102 */ 	mul.s	$f4,$f0,$f6
/*    22348:	44803000 */ 	mtc1	$zero,$f6
/*    2234c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*    22350:	4606903c */ 	c.lt.s	$f18,$f6
/*    22354:	46047080 */ 	add.s	$f2,$f14,$f4
/*    22358:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*    2235c:	460a7380 */ 	add.s	$f14,$f14,$f10
/*    22360:	46001087 */ 	neg.s	$f2,$f2
/*    22364:	45000004 */ 	bc1f	.L00022378
/*    22368:	46007387 */ 	neg.s	$f14,$f14
/*    2236c:	46009487 */ 	neg.s	$f18,$f18
/*    22370:	46007387 */ 	neg.s	$f14,$f14
/*    22374:	46001087 */ 	neg.s	$f2,$f2
.L00022378:
/*    22378:	460c703c */ 	c.lt.s	$f14,$f12
/*    2237c:	00000000 */ 	nop
/*    22380:	45020008 */ 	bc1fl	.L000223a4
/*    22384:	460e103c */ 	c.lt.s	$f2,$f14
/*    22388:	460c103c */ 	c.lt.s	$f2,$f12
/*    2238c:	00000000 */ 	nop
/*    22390:	45020004 */ 	bc1fl	.L000223a4
/*    22394:	460e103c */ 	c.lt.s	$f2,$f14
/*    22398:	1000008c */ 	b	.L000225cc
/*    2239c:	00001025 */ 	or	$v0,$zero,$zero
/*    223a0:	460e103c */ 	c.lt.s	$f2,$f14
.L000223a4:
/*    223a4:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*    223a8:	45000004 */ 	bc1f	.L000223bc
/*    223ac:	00000000 */ 	nop
/*    223b0:	46007006 */ 	mov.s	$f0,$f14
/*    223b4:	46001386 */ 	mov.s	$f14,$f2
/*    223b8:	46000086 */ 	mov.s	$f2,$f0
.L000223bc:
/*    223bc:	46047302 */ 	mul.s	$f12,$f14,$f4
/*    223c0:	00000000 */ 	nop
/*    223c4:	46128002 */ 	mul.s	$f0,$f16,$f18
/*    223c8:	4600603c */ 	c.lt.s	$f12,$f0
/*    223cc:	00000000 */ 	nop
/*    223d0:	4500000f */ 	bc1f	.L00022410
/*    223d4:	00000000 */ 	nop
/*    223d8:	46041302 */ 	mul.s	$f12,$f2,$f4
/*    223dc:	46002386 */ 	mov.s	$f14,$f4
/*    223e0:	4600603c */ 	c.lt.s	$f12,$f0
/*    223e4:	00000000 */ 	nop
/*    223e8:	45020004 */ 	bc1fl	.L000223fc
/*    223ec:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*    223f0:	10000076 */ 	b	.L000225cc
/*    223f4:	00001025 */ 	or	$v0,$zero,$zero
/*    223f8:	c7a800ac */ 	lwc1	$f8,0xac($sp)
.L000223fc:
/*    223fc:	e7b00074 */ 	swc1	$f16,0x74($sp)
/*    22400:	e7ae0070 */ 	swc1	$f14,0x70($sp)
/*    22404:	46124002 */ 	mul.s	$f0,$f8,$f18
/*    22408:	1000000e */ 	b	.L00022444
/*    2240c:	460c003c */ 	c.lt.s	$f0,$f12
.L00022410:
/*    22410:	46125002 */ 	mul.s	$f0,$f10,$f18
/*    22414:	460c003c */ 	c.lt.s	$f0,$f12
/*    22418:	00000000 */ 	nop
/*    2241c:	45020004 */ 	bc1fl	.L00022430
/*    22420:	e7ae0074 */ 	swc1	$f14,0x74($sp)
/*    22424:	10000069 */ 	b	.L000225cc
/*    22428:	00001025 */ 	or	$v0,$zero,$zero
/*    2242c:	e7ae0074 */ 	swc1	$f14,0x74($sp)
.L00022430:
/*    22430:	c7ae00b4 */ 	lwc1	$f14,0xb4($sp)
/*    22434:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*    22438:	460e1302 */ 	mul.s	$f12,$f2,$f14
/*    2243c:	00000000 */ 	nop
/*    22440:	460c003c */ 	c.lt.s	$f0,$f12
.L00022444:
/*    22444:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*    22448:	45020005 */ 	bc1fl	.L00022460
/*    2244c:	e7a2006c */ 	swc1	$f2,0x6c($sp)
/*    22450:	e7a4006c */ 	swc1	$f4,0x6c($sp)
/*    22454:	10000003 */ 	b	.L00022464
/*    22458:	e7ae0068 */ 	swc1	$f14,0x68($sp)
/*    2245c:	e7a2006c */ 	swc1	$f2,0x6c($sp)
.L00022460:
/*    22460:	e7b20068 */ 	swc1	$f18,0x68($sp)
.L00022464:
/*    22464:	c4a00020 */ 	lwc1	$f0,0x20($a1)
/*    22468:	c4a20024 */ 	lwc1	$f2,0x24($a1)
/*    2246c:	c7a60010 */ 	lwc1	$f6,0x10($sp)
/*    22470:	46000482 */ 	mul.s	$f18,$f0,$f0
/*    22474:	00000000 */ 	nop
/*    22478:	46021202 */ 	mul.s	$f8,$f2,$f2
/*    2247c:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*    22480:	c4ac0028 */ 	lwc1	$f12,0x28($a1)
/*    22484:	c7a8000c */ 	lwc1	$f8,0xc($sp)
/*    22488:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*    2248c:	e7aa003c */ 	swc1	$f10,0x3c($sp)
/*    22490:	46060102 */ 	mul.s	$f4,$f0,$f6
/*    22494:	00000000 */ 	nop
/*    22498:	46081282 */ 	mul.s	$f10,$f2,$f8
/*    2249c:	c7a80014 */ 	lwc1	$f8,0x14($sp)
/*    224a0:	460a2180 */ 	add.s	$f6,$f4,$f10
/*    224a4:	460c4102 */ 	mul.s	$f4,$f8,$f12
/*    224a8:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    224ac:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*    224b0:	46062400 */ 	add.s	$f16,$f4,$f6
/*    224b4:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    224b8:	46041182 */ 	mul.s	$f6,$f2,$f4
/*    224bc:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    224c0:	46064280 */ 	add.s	$f10,$f8,$f6
/*    224c4:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    224c8:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    224cc:	46069100 */ 	add.s	$f4,$f18,$f6
/*    224d0:	460a4380 */ 	add.s	$f14,$f8,$f10
/*    224d4:	c7a8003c */ 	lwc1	$f8,0x3c($sp)
/*    224d8:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    224dc:	46082000 */ 	add.s	$f0,$f4,$f8
/*    224e0:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*    224e4:	46000007 */ 	neg.s	$f0,$f0
/*    224e8:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*    224ec:	44805000 */ 	mtc1	$zero,$f10
/*    224f0:	46040202 */ 	mul.s	$f8,$f0,$f4
/*    224f4:	460a803c */ 	c.lt.s	$f16,$f10
/*    224f8:	46067080 */ 	add.s	$f2,$f14,$f6
/*    224fc:	44803000 */ 	mtc1	$zero,$f6
/*    22500:	46087380 */ 	add.s	$f14,$f14,$f8
/*    22504:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*    22508:	46001087 */ 	neg.s	$f2,$f2
/*    2250c:	45000004 */ 	bc1f	.L00022520
/*    22510:	46007387 */ 	neg.s	$f14,$f14
/*    22514:	46008407 */ 	neg.s	$f16,$f16
/*    22518:	46007387 */ 	neg.s	$f14,$f14
/*    2251c:	46001087 */ 	neg.s	$f2,$f2
.L00022520:
/*    22520:	4606703c */ 	c.lt.s	$f14,$f6
/*    22524:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*    22528:	4502000a */ 	bc1fl	.L00022554
/*    2252c:	460e103c */ 	c.lt.s	$f2,$f14
/*    22530:	44802000 */ 	mtc1	$zero,$f4
/*    22534:	00000000 */ 	nop
/*    22538:	4604103c */ 	c.lt.s	$f2,$f4
/*    2253c:	00000000 */ 	nop
/*    22540:	45020004 */ 	bc1fl	.L00022554
/*    22544:	460e103c */ 	c.lt.s	$f2,$f14
/*    22548:	10000020 */ 	b	.L000225cc
/*    2254c:	00001025 */ 	or	$v0,$zero,$zero
/*    22550:	460e103c */ 	c.lt.s	$f2,$f14
.L00022554:
/*    22554:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*    22558:	45000004 */ 	bc1f	.L0002256c
/*    2255c:	00000000 */ 	nop
/*    22560:	46007006 */ 	mov.s	$f0,$f14
/*    22564:	46001386 */ 	mov.s	$f14,$f2
/*    22568:	46000086 */ 	mov.s	$f2,$f0
.L0002256c:
/*    2256c:	46104002 */ 	mul.s	$f0,$f8,$f16
/*    22570:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*    22574:	460c7282 */ 	mul.s	$f10,$f14,$f12
/*    22578:	460a003c */ 	c.lt.s	$f0,$f10
/*    2257c:	00000000 */ 	nop
/*    22580:	4500000a */ 	bc1f	.L000225ac
/*    22584:	00000000 */ 	nop
/*    22588:	46103102 */ 	mul.s	$f4,$f6,$f16
/*    2258c:	00000000 */ 	nop
/*    22590:	46087282 */ 	mul.s	$f10,$f14,$f8
/*    22594:	460a203c */ 	c.lt.s	$f4,$f10
/*    22598:	00000000 */ 	nop
/*    2259c:	4500000a */ 	bc1f	.L000225c8
/*    225a0:	00000000 */ 	nop
/*    225a4:	10000009 */ 	b	.L000225cc
/*    225a8:	00001025 */ 	or	$v0,$zero,$zero
.L000225ac:
/*    225ac:	460c1182 */ 	mul.s	$f6,$f2,$f12
/*    225b0:	4600303c */ 	c.lt.s	$f6,$f0
/*    225b4:	00000000 */ 	nop
/*    225b8:	45020004 */ 	bc1fl	.L000225cc
/*    225bc:	24020001 */ 	addiu	$v0,$zero,0x1
/*    225c0:	10000002 */ 	b	.L000225cc
/*    225c4:	00001025 */ 	or	$v0,$zero,$zero
.L000225c8:
/*    225c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L000225cc:
/*    225cc:	03e00008 */ 	jr	$ra
/*    225d0:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

GLOBAL_ASM(
glabel func000225d4
.late_rodata
glabel var700544b8
.word 0x7002277c
glabel var700544bc
.word 0x7002277c
glabel var700544c0
.word 0x7002277c
glabel var700544c4
.word 0x7002277c
glabel var700544c8
.word 0x7002277c
glabel var700544cc
.word 0x7002277c
glabel var700544d0
.word 0x7002277c
glabel var700544d4
.word 0x700226e8
glabel var700544d8
.word 0x7002277c
glabel var700544dc
.word 0x700226a0
glabel var700544e0
.word 0x7002277c
glabel var700544e4
.word 0x7002277c
glabel var700544e8
.word 0x7002277c
glabel var700544ec
.word 0x7002277c
glabel var700544f0
.word 0x7002277c
glabel var700544f4
.word 0x7002277c
glabel var700544f8
.word 0x7002277c
glabel var700544fc
.word 0x70022718
glabel var70054500
.word 0x7002277c
glabel var70054504
.word 0x7002277c
glabel var70054508
.word 0x7002277c
glabel var7005450c
.word 0x7002277c
glabel var70054510
.word 0x70022748
glabel var70054514
.word 0x7002277c
.text
/*    225d4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    225d8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    225dc:	afb30020 */ 	sw	$s3,0x20($sp)
/*    225e0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    225e4:	afb10018 */ 	sw	$s1,0x18($sp)
/*    225e8:	afb00014 */ 	sw	$s0,0x14($sp)
/*    225ec:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    225f0:	afa60030 */ 	sw	$a2,0x30($sp)
/*    225f4:	afa70034 */ 	sw	$a3,0x34($sp)
/*    225f8:	8ce20000 */ 	lw	$v0,0x0($a3)
/*    225fc:	00809025 */ 	or	$s2,$a0,$zero
/*    22600:	24130001 */ 	addiu	$s3,$zero,0x1
/*    22604:	10400003 */ 	beqz	$v0,.L00022614
/*    22608:	00408025 */ 	or	$s0,$v0,$zero
/*    2260c:	10000003 */ 	b	.L0002261c
/*    22610:	ace00000 */ 	sw	$zero,0x0($a3)
.L00022614:
/*    22614:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*    22618:	8df00000 */ 	lw	$s0,0x0($t7)
.L0002261c:
/*    2261c:	5200005a */ 	beqzl	$s0,.L00022788
/*    22620:	00001025 */ 	or	$v0,$zero,$zero
.L00022624:
/*    22624:	12600006 */ 	beqz	$s3,.L00022640
/*    22628:	00000000 */ 	nop
/*    2262c:	8e020014 */ 	lw	$v0,0x14($s0)
/*    22630:	10400003 */ 	beqz	$v0,.L00022640
/*    22634:	00000000 */ 	nop
/*    22638:	1000000d */ 	b	.L00022670
/*    2263c:	00408025 */ 	or	$s0,$v0,$zero
.L00022640:
/*    22640:	12000009 */ 	beqz	$s0,.L00022668
/*    22644:	00000000 */ 	nop
/*    22648:	8e02000c */ 	lw	$v0,0xc($s0)
.L0002264c:
/*    2264c:	50400004 */ 	beqzl	$v0,.L00022660
/*    22650:	8e100008 */ 	lw	$s0,0x8($s0)
/*    22654:	10000004 */ 	b	.L00022668
/*    22658:	00408025 */ 	or	$s0,$v0,$zero
/*    2265c:	8e100008 */ 	lw	$s0,0x8($s0)
.L00022660:
/*    22660:	5600fffa */ 	bnezl	$s0,.L0002264c
/*    22664:	8e02000c */ 	lw	$v0,0xc($s0)
.L00022668:
/*    22668:	52000047 */ 	beqzl	$s0,.L00022788
/*    2266c:	00001025 */ 	or	$v0,$zero,$zero
.L00022670:
/*    22670:	96020000 */ 	lhu	$v0,0x0($s0)
/*    22674:	24130001 */ 	addiu	$s3,$zero,0x1
/*    22678:	305800ff */ 	andi	$t8,$v0,0xff
/*    2267c:	2719ffff */ 	addiu	$t9,$t8,-1
/*    22680:	2f210018 */ 	sltiu	$at,$t9,0x18
/*    22684:	1020003d */ 	beqz	$at,.L0002277c
/*    22688:	0019c880 */ 	sll	$t9,$t9,0x2
/*    2268c:	3c017005 */ 	lui	$at,%hi(var700544b8)
/*    22690:	00390821 */ 	addu	$at,$at,$t9
/*    22694:	8c3944b8 */ 	lw	$t9,%lo(var700544b8)($at)
/*    22698:	03200008 */ 	jr	$t9
/*    2269c:	00000000 */ 	nop
/*    226a0:	8e110004 */ 	lw	$s1,0x4($s0)
/*    226a4:	02402025 */ 	or	$a0,$s2,$zero
/*    226a8:	02002825 */ 	or	$a1,$s0,$zero
/*    226ac:	0c006973 */ 	jal	func0001a5cc
/*    226b0:	00003025 */ 	or	$a2,$zero,$zero
/*    226b4:	02202025 */ 	or	$a0,$s1,$zero
/*    226b8:	00402825 */ 	or	$a1,$v0,$zero
/*    226bc:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    226c0:	0c00883f */ 	jal	func000220fc
/*    226c4:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    226c8:	10400005 */ 	beqz	$v0,.L000226e0
/*    226cc:	00000000 */ 	nop
/*    226d0:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    226d4:	ad100000 */ 	sw	$s0,0x0($t0)
/*    226d8:	1000002b */ 	b	.L00022788
/*    226dc:	8e220000 */ 	lw	$v0,0x0($s1)
.L000226e0:
/*    226e0:	10000026 */ 	b	.L0002277c
/*    226e4:	00009825 */ 	or	$s3,$zero,$zero
/*    226e8:	8e110004 */ 	lw	$s1,0x4($s0)
/*    226ec:	02402025 */ 	or	$a0,$s2,$zero
/*    226f0:	0c006a87 */ 	jal	modelGetNodeData
/*    226f4:	02002825 */ 	or	$a1,$s0,$zero
/*    226f8:	8c490000 */ 	lw	$t1,0x0($v0)
/*    226fc:	11200004 */ 	beqz	$t1,.L00022710
/*    22700:	00000000 */ 	nop
/*    22704:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*    22708:	1000001c */ 	b	.L0002277c
/*    2270c:	ae0a0014 */ 	sw	$t2,0x14($s0)
.L00022710:
/*    22710:	1000001a */ 	b	.L0002277c
/*    22714:	ae000014 */ 	sw	$zero,0x14($s0)
/*    22718:	8e110004 */ 	lw	$s1,0x4($s0)
/*    2271c:	02402025 */ 	or	$a0,$s2,$zero
/*    22720:	0c006a87 */ 	jal	modelGetNodeData
/*    22724:	02002825 */ 	or	$a1,$s0,$zero
/*    22728:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*    2272c:	11600004 */ 	beqz	$t3,.L00022740
/*    22730:	00000000 */ 	nop
/*    22734:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*    22738:	10000010 */ 	b	.L0002277c
/*    2273c:	ae0c0014 */ 	sw	$t4,0x14($s0)
.L00022740:
/*    22740:	1000000e */ 	b	.L0002277c
/*    22744:	ae000014 */ 	sw	$zero,0x14($s0)
/*    22748:	02402025 */ 	or	$a0,$s2,$zero
/*    2274c:	0c006a87 */ 	jal	modelGetNodeData
/*    22750:	02002825 */ 	or	$a1,$s0,$zero
/*    22754:	8c440000 */ 	lw	$a0,0x0($v0)
/*    22758:	10800008 */ 	beqz	$a0,.L0002277c
/*    2275c:	00000000 */ 	nop
/*    22760:	8c830000 */ 	lw	$v1,0x0($a0)
/*    22764:	10600005 */ 	beqz	$v1,.L0002277c
/*    22768:	ae030014 */ 	sw	$v1,0x14($s0)
/*    2276c:	ac700008 */ 	sw	$s0,0x8($v1)
.L00022770:
/*    22770:	8c63000c */ 	lw	$v1,0xc($v1)
/*    22774:	5460fffe */ 	bnezl	$v1,.L00022770
/*    22778:	ac700008 */ 	sw	$s0,0x8($v1)
.L0002277c:
/*    2277c:	1600ffa9 */ 	bnez	$s0,.L00022624
/*    22780:	00000000 */ 	nop
/*    22784:	00001025 */ 	or	$v0,$zero,$zero
.L00022788:
/*    22788:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    2278c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    22790:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    22794:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    22798:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    2279c:	03e00008 */ 	jr	$ra
/*    227a0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func000227a4
.late_rodata
glabel var70054518
.word 0x70022840
glabel var7005451c
.word 0x70022848
glabel var70054520
.word 0x700229d8
glabel var70054524
.word 0x70022850
glabel var70054528
.word 0x700229d8
glabel var7005452c
.word 0x700229d8
glabel var70054530
.word 0x700229d8
glabel var70054534
.word 0x70022898
glabel var70054538
.word 0x700228e0
glabel var7005453c
.word 0x700229d8
glabel var70054540
.word 0x70022934
glabel var70054544
.word 0x70022958
glabel var70054548
.word 0x7002297c
glabel var7005454c
.word 0x700229d8
glabel var70054550
.word 0x700229d8
glabel var70054554
.word 0x700229d8
glabel var70054558
.word 0x70022914
glabel var7005455c
.word 0x700228c0
glabel var70054560
.word 0x700229d8
glabel var70054564
.word 0x700229d8
glabel var70054568
.word 0x700229d8
glabel var7005456c
.word 0x700229b4
glabel var70054570
.word 0x700229d8
glabel var70054574
.word 0x70022874
.text
/*    227a4:	1080009d */ 	beqz	$a0,.L00022a1c
/*    227a8:	00000000 */ 	nop
/*    227ac:	94820000 */ 	lhu	$v0,0x0($a0)
.L000227b0:
/*    227b0:	8c830004 */ 	lw	$v1,0x4($a0)
/*    227b4:	00c57823 */ 	subu	$t7,$a2,$a1
/*    227b8:	304e00ff */ 	andi	$t6,$v0,0xff
/*    227bc:	10600003 */ 	beqz	$v1,.L000227cc
/*    227c0:	01c01025 */ 	or	$v0,$t6,$zero
/*    227c4:	006fc021 */ 	addu	$t8,$v1,$t7
/*    227c8:	ac980004 */ 	sw	$t8,0x4($a0)
.L000227cc:
/*    227cc:	8c830008 */ 	lw	$v1,0x8($a0)
/*    227d0:	244fffff */ 	addiu	$t7,$v0,-1
/*    227d4:	00c5c823 */ 	subu	$t9,$a2,$a1
/*    227d8:	10600003 */ 	beqz	$v1,.L000227e8
/*    227dc:	2de10018 */ 	sltiu	$at,$t7,0x18
/*    227e0:	00794021 */ 	addu	$t0,$v1,$t9
/*    227e4:	ac880008 */ 	sw	$t0,0x8($a0)
.L000227e8:
/*    227e8:	8c83000c */ 	lw	$v1,0xc($a0)
/*    227ec:	00c54823 */ 	subu	$t1,$a2,$a1
/*    227f0:	00c55823 */ 	subu	$t3,$a2,$a1
/*    227f4:	10600002 */ 	beqz	$v1,.L00022800
/*    227f8:	00695021 */ 	addu	$t2,$v1,$t1
/*    227fc:	ac8a000c */ 	sw	$t2,0xc($a0)
.L00022800:
/*    22800:	8c830010 */ 	lw	$v1,0x10($a0)
/*    22804:	00c56823 */ 	subu	$t5,$a2,$a1
/*    22808:	000f7880 */ 	sll	$t7,$t7,0x2
/*    2280c:	10600002 */ 	beqz	$v1,.L00022818
/*    22810:	006b6021 */ 	addu	$t4,$v1,$t3
/*    22814:	ac8c0010 */ 	sw	$t4,0x10($a0)
.L00022818:
/*    22818:	8c830014 */ 	lw	$v1,0x14($a0)
/*    2281c:	10600002 */ 	beqz	$v1,.L00022828
/*    22820:	006d7021 */ 	addu	$t6,$v1,$t5
/*    22824:	ac8e0014 */ 	sw	$t6,0x14($a0)
.L00022828:
/*    22828:	1020006b */ 	beqz	$at,.L000229d8
/*    2282c:	3c017005 */ 	lui	$at,%hi(var70054518)
/*    22830:	002f0821 */ 	addu	$at,$at,$t7
/*    22834:	8c2f4518 */ 	lw	$t7,%lo(var70054518)($at)
/*    22838:	01e00008 */ 	jr	$t7
/*    2283c:	00000000 */ 	nop
/*    22840:	10000066 */ 	b	.L000229dc
/*    22844:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22848:	10000064 */ 	b	.L000229dc
/*    2284c:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22850:	8c820004 */ 	lw	$v0,0x4($a0)
/*    22854:	00c5c023 */ 	subu	$t8,$a2,$a1
/*    22858:	8c43000c */ 	lw	$v1,0xc($v0)
/*    2285c:	10600002 */ 	beqz	$v1,.L00022868
/*    22860:	0078c821 */ 	addu	$t9,$v1,$t8
/*    22864:	ac59000c */ 	sw	$t9,0xc($v0)
.L00022868:
/*    22868:	ac460008 */ 	sw	$a2,0x8($v0)
/*    2286c:	1000005b */ 	b	.L000229dc
/*    22870:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22874:	8c820004 */ 	lw	$v0,0x4($a0)
/*    22878:	00c54023 */ 	subu	$t0,$a2,$a1
/*    2287c:	8c43000c */ 	lw	$v1,0xc($v0)
/*    22880:	10600002 */ 	beqz	$v1,.L0002288c
/*    22884:	00684821 */ 	addu	$t1,$v1,$t0
/*    22888:	ac49000c */ 	sw	$t1,0xc($v0)
.L0002288c:
/*    2288c:	ac460008 */ 	sw	$a2,0x8($v0)
/*    22890:	10000052 */ 	b	.L000229dc
/*    22894:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22898:	8c820004 */ 	lw	$v0,0x4($a0)
/*    2289c:	00c55023 */ 	subu	$t2,$a2,$a1
/*    228a0:	8c470008 */ 	lw	$a3,0x8($v0)
/*    228a4:	10e00003 */ 	beqz	$a3,.L000228b4
/*    228a8:	00ea5821 */ 	addu	$t3,$a3,$t2
/*    228ac:	ac4b0008 */ 	sw	$t3,0x8($v0)
/*    228b0:	01603825 */ 	or	$a3,$t3,$zero
.L000228b4:
/*    228b4:	ac870014 */ 	sw	$a3,0x14($a0)
/*    228b8:	10000048 */ 	b	.L000229dc
/*    228bc:	00e01825 */ 	or	$v1,$a3,$zero
/*    228c0:	8c820004 */ 	lw	$v0,0x4($a0)
/*    228c4:	00c56023 */ 	subu	$t4,$a2,$a1
/*    228c8:	8c430000 */ 	lw	$v1,0x0($v0)
/*    228cc:	10600002 */ 	beqz	$v1,.L000228d8
/*    228d0:	006c6821 */ 	addu	$t5,$v1,$t4
/*    228d4:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L000228d8:
/*    228d8:	10000040 */ 	b	.L000229dc
/*    228dc:	8c830014 */ 	lw	$v1,0x14($a0)
/*    228e0:	8c820004 */ 	lw	$v0,0x4($a0)
/*    228e4:	00c57023 */ 	subu	$t6,$a2,$a1
/*    228e8:	00c5c023 */ 	subu	$t8,$a2,$a1
/*    228ec:	8c430018 */ 	lw	$v1,0x18($v0)
/*    228f0:	10600002 */ 	beqz	$v1,.L000228fc
/*    228f4:	006e7821 */ 	addu	$t7,$v1,$t6
/*    228f8:	ac4f0018 */ 	sw	$t7,0x18($v0)
.L000228fc:
/*    228fc:	8c43001c */ 	lw	$v1,0x1c($v0)
/*    22900:	10600002 */ 	beqz	$v1,.L0002290c
/*    22904:	0078c821 */ 	addu	$t9,$v1,$t8
/*    22908:	ac59001c */ 	sw	$t9,0x1c($v0)
.L0002290c:
/*    2290c:	10000033 */ 	b	.L000229dc
/*    22910:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22914:	8c820004 */ 	lw	$v0,0x4($a0)
/*    22918:	00c54023 */ 	subu	$t0,$a2,$a1
/*    2291c:	8c430014 */ 	lw	$v1,0x14($v0)
/*    22920:	10600002 */ 	beqz	$v1,.L0002292c
/*    22924:	00684821 */ 	addu	$t1,$v1,$t0
/*    22928:	ac490014 */ 	sw	$t1,0x14($v0)
.L0002292c:
/*    2292c:	1000002b */ 	b	.L000229dc
/*    22930:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22934:	8c820004 */ 	lw	$v0,0x4($a0)
/*    22938:	00c55023 */ 	subu	$t2,$a2,$a1
/*    2293c:	8c43003c */ 	lw	$v1,0x3c($v0)
/*    22940:	10600002 */ 	beqz	$v1,.L0002294c
/*    22944:	006a5821 */ 	addu	$t3,$v1,$t2
/*    22948:	ac4b003c */ 	sw	$t3,0x3c($v0)
.L0002294c:
/*    2294c:	ac460048 */ 	sw	$a2,0x48($v0)
/*    22950:	10000022 */ 	b	.L000229dc
/*    22954:	8c830014 */ 	lw	$v1,0x14($a0)
/*    22958:	8c820004 */ 	lw	$v0,0x4($a0)
/*    2295c:	00c56023 */ 	subu	$t4,$a2,$a1
/*    22960:	8c430018 */ 	lw	$v1,0x18($v0)
/*    22964:	10600002 */ 	beqz	$v1,.L00022970
/*    22968:	006c6821 */ 	addu	$t5,$v1,$t4
/*    2296c:	ac4d0018 */ 	sw	$t5,0x18($v0)
.L00022970:
/*    22970:	ac460024 */ 	sw	$a2,0x24($v0)
/*    22974:	10000019 */ 	b	.L000229dc
/*    22978:	8c830014 */ 	lw	$v1,0x14($a0)
/*    2297c:	8c820004 */ 	lw	$v0,0x4($a0)
/*    22980:	00c57023 */ 	subu	$t6,$a2,$a1
/*    22984:	00c5c023 */ 	subu	$t8,$a2,$a1
/*    22988:	8c430010 */ 	lw	$v1,0x10($v0)
/*    2298c:	10600002 */ 	beqz	$v1,.L00022998
/*    22990:	006e7821 */ 	addu	$t7,$v1,$t6
/*    22994:	ac4f0010 */ 	sw	$t7,0x10($v0)
.L00022998:
/*    22998:	8c430014 */ 	lw	$v1,0x14($v0)
/*    2299c:	10600002 */ 	beqz	$v1,.L000229a8
/*    229a0:	0078c821 */ 	addu	$t9,$v1,$t8
/*    229a4:	ac590014 */ 	sw	$t9,0x14($v0)
.L000229a8:
/*    229a8:	ac46001c */ 	sw	$a2,0x1c($v0)
/*    229ac:	1000000b */ 	b	.L000229dc
/*    229b0:	8c830014 */ 	lw	$v1,0x14($a0)
/*    229b4:	8c820004 */ 	lw	$v0,0x4($a0)
/*    229b8:	00c54023 */ 	subu	$t0,$a2,$a1
/*    229bc:	8c430004 */ 	lw	$v1,0x4($v0)
/*    229c0:	10600002 */ 	beqz	$v1,.L000229cc
/*    229c4:	00684821 */ 	addu	$t1,$v1,$t0
/*    229c8:	ac490004 */ 	sw	$t1,0x4($v0)
.L000229cc:
/*    229cc:	ac46000c */ 	sw	$a2,0xc($v0)
/*    229d0:	10000002 */ 	b	.L000229dc
/*    229d4:	8c830014 */ 	lw	$v1,0x14($a0)
.L000229d8:
/*    229d8:	8c830014 */ 	lw	$v1,0x14($a0)
.L000229dc:
/*    229dc:	10600003 */ 	beqz	$v1,.L000229ec
/*    229e0:	00000000 */ 	nop
/*    229e4:	1000000b */ 	b	.L00022a14
/*    229e8:	00602025 */ 	or	$a0,$v1,$zero
.L000229ec:
/*    229ec:	10800009 */ 	beqz	$a0,.L00022a14
/*    229f0:	00000000 */ 	nop
/*    229f4:	8c83000c */ 	lw	$v1,0xc($a0)
.L000229f8:
/*    229f8:	50600004 */ 	beqzl	$v1,.L00022a0c
/*    229fc:	8c840008 */ 	lw	$a0,0x8($a0)
/*    22a00:	10000004 */ 	b	.L00022a14
/*    22a04:	00602025 */ 	or	$a0,$v1,$zero
/*    22a08:	8c840008 */ 	lw	$a0,0x8($a0)
.L00022a0c:
/*    22a0c:	5480fffa */ 	bnezl	$a0,.L000229f8
/*    22a10:	8c83000c */ 	lw	$v1,0xc($a0)
.L00022a14:
/*    22a14:	5480ff66 */ 	bnezl	$a0,.L000227b0
/*    22a18:	94820000 */ 	lhu	$v0,0x0($a0)
.L00022a1c:
/*    22a1c:	03e00008 */ 	jr	$ra
/*    22a20:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00022a24
/*    22a24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    22a28:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    22a2c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    22a30:	8c820000 */ 	lw	$v0,0x0($a0)
/*    22a34:	00808025 */ 	or	$s0,$a0,$zero
/*    22a38:	00c03825 */ 	or	$a3,$a2,$zero
/*    22a3c:	10400003 */ 	beqz	$v0,.L00022a4c
/*    22a40:	00c57023 */ 	subu	$t6,$a2,$a1
/*    22a44:	004e7821 */ 	addu	$t7,$v0,$t6
/*    22a48:	ac8f0000 */ 	sw	$t7,0x0($a0)
.L00022a4c:
/*    22a4c:	8e020008 */ 	lw	$v0,0x8($s0)
/*    22a50:	00e5c023 */ 	subu	$t8,$a3,$a1
/*    22a54:	00e57023 */ 	subu	$t6,$a3,$a1
/*    22a58:	10400002 */ 	beqz	$v0,.L00022a64
/*    22a5c:	0058c821 */ 	addu	$t9,$v0,$t8
/*    22a60:	ae190008 */ 	sw	$t9,0x8($s0)
.L00022a64:
/*    22a64:	8e020018 */ 	lw	$v0,0x18($s0)
/*    22a68:	00003025 */ 	or	$a2,$zero,$zero
/*    22a6c:	10400002 */ 	beqz	$v0,.L00022a78
/*    22a70:	004e7821 */ 	addu	$t7,$v0,$t6
/*    22a74:	ae0f0018 */ 	sw	$t7,0x18($s0)
.L00022a78:
/*    22a78:	8604000c */ 	lh	$a0,0xc($s0)
/*    22a7c:	00004825 */ 	or	$t1,$zero,$zero
/*    22a80:	5880000e */ 	blezl	$a0,.L00022abc
/*    22a84:	8e040000 */ 	lw	$a0,0x0($s0)
.L00022a88:
/*    22a88:	8e180008 */ 	lw	$t8,0x8($s0)
/*    22a8c:	00e5c823 */ 	subu	$t9,$a3,$a1
/*    22a90:	25290001 */ 	addiu	$t1,$t1,0x1
/*    22a94:	03061821 */ 	addu	$v1,$t8,$a2
/*    22a98:	8c620000 */ 	lw	$v0,0x0($v1)
/*    22a9c:	10400003 */ 	beqz	$v0,.L00022aac
/*    22aa0:	00597021 */ 	addu	$t6,$v0,$t9
/*    22aa4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*    22aa8:	8604000c */ 	lh	$a0,0xc($s0)
.L00022aac:
/*    22aac:	0124082a */ 	slt	$at,$t1,$a0
/*    22ab0:	1420fff5 */ 	bnez	$at,.L00022a88
/*    22ab4:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    22ab8:	8e040000 */ 	lw	$a0,0x0($s0)
.L00022abc:
/*    22abc:	0c0089e9 */ 	jal	func000227a4
/*    22ac0:	00e03025 */ 	or	$a2,$a3,$zero
/*    22ac4:	8604000c */ 	lh	$a0,0xc($s0)
/*    22ac8:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*    22acc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    22ad0:	0004c080 */ 	sll	$t8,$a0,0x2
/*    22ad4:	1080001f */ 	beqz	$a0,.L00022b54
/*    22ad8:	01f86021 */ 	addu	$t4,$t7,$t8
/*    22adc:	248affff */ 	addiu	$t2,$a0,-1
/*    22ae0:	00005825 */ 	or	$t3,$zero,$zero
.L00022ae4:
/*    22ae4:	19400019 */ 	blez	$t2,.L00022b4c
/*    22ae8:	00004825 */ 	or	$t1,$zero,$zero
/*    22aec:	01801025 */ 	or	$v0,$t4,$zero
.L00022af0:
/*    22af0:	84470002 */ 	lh	$a3,0x2($v0)
/*    22af4:	84480000 */ 	lh	$t0,0x0($v0)
/*    22af8:	00e8082a */ 	slt	$at,$a3,$t0
/*    22afc:	50200010 */ 	beqzl	$at,.L00022b40
/*    22b00:	25290001 */ 	addiu	$t1,$t1,0x1
/*    22b04:	a4470000 */ 	sh	$a3,0x0($v0)
/*    22b08:	a4480002 */ 	sh	$t0,0x2($v0)
/*    22b0c:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*    22b10:	00093080 */ 	sll	$a2,$t1,0x2
/*    22b14:	01a05825 */ 	or	$t3,$t5,$zero
/*    22b18:	01c61821 */ 	addu	$v1,$t6,$a2
/*    22b1c:	8c6f0004 */ 	lw	$t7,0x4($v1)
/*    22b20:	8c650000 */ 	lw	$a1,0x0($v1)
/*    22b24:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    22b28:	8e180008 */ 	lw	$t8,0x8($s0)
/*    22b2c:	0306c821 */ 	addu	$t9,$t8,$a2
/*    22b30:	af250004 */ 	sw	$a1,0x4($t9)
/*    22b34:	860a000c */ 	lh	$t2,0xc($s0)
/*    22b38:	254affff */ 	addiu	$t2,$t2,-1
/*    22b3c:	25290001 */ 	addiu	$t1,$t1,0x1
.L00022b40:
/*    22b40:	012a082a */ 	slt	$at,$t1,$t2
/*    22b44:	1420ffea */ 	bnez	$at,.L00022af0
/*    22b48:	24420002 */ 	addiu	$v0,$v0,0x2
.L00022b4c:
/*    22b4c:	516dffe5 */ 	beql	$t3,$t5,.L00022ae4
/*    22b50:	00005825 */ 	or	$t3,$zero,$zero
.L00022b54:
/*    22b54:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    22b58:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    22b5c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    22b60:	03e00008 */ 	jr	$ra
/*    22b64:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00022b68
.late_rodata
glabel var70054578
.word 0x70022bb8
glabel var7005457c
.word 0x70022cb0
glabel var70054580
.word 0x70022cb0
glabel var70054584
.word 0x70022cb0
glabel var70054588
.word 0x70022cb0
glabel var7005458c
.word 0x70022cb0
glabel var70054590
.word 0x70022cb0
glabel var70054594
.word 0x70022bd4
glabel var70054598
.word 0x70022c34
glabel var7005459c
.word 0x70022cb0
glabel var700545a0
.word 0x70022c5c
glabel var700545a4
.word 0x70022c78
glabel var700545a8
.word 0x70022cb0
glabel var700545ac
.word 0x70022cb0
glabel var700545b0
.word 0x70022cb0
glabel var700545b4
.word 0x70022cb0
glabel var700545b8
.word 0x70022cb0
glabel var700545bc
.word 0x70022bf4
glabel var700545c0
.word 0x70022cb0
glabel var700545c4
.word 0x70022cb0
glabel var700545c8
.word 0x70022cb0
glabel var700545cc
.word 0x70022cb0
glabel var700545d0
.word 0x70022c14
glabel var700545d4
.word 0x70022c94
.text
/*    22b68:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    22b6c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    22b70:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    22b74:	afb00018 */ 	sw	$s0,0x18($sp)
/*    22b78:	00809025 */ 	or	$s2,$a0,$zero
/*    22b7c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    22b80:	00008825 */ 	or	$s1,$zero,$zero
/*    22b84:	10800060 */ 	beqz	$a0,.L00022d08
/*    22b88:	00808025 */ 	or	$s0,$a0,$zero
/*    22b8c:	96020000 */ 	lhu	$v0,0x0($s0)
.L00022b90:
/*    22b90:	304e00ff */ 	andi	$t6,$v0,0xff
/*    22b94:	25cfffff */ 	addiu	$t7,$t6,-1
/*    22b98:	2de10018 */ 	sltiu	$at,$t7,0x18
/*    22b9c:	10200044 */ 	beqz	$at,.L00022cb0
/*    22ba0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    22ba4:	3c017005 */ 	lui	$at,%hi(var70054578)
/*    22ba8:	002f0821 */ 	addu	$at,$at,$t7
/*    22bac:	8c2f4578 */ 	lw	$t7,%lo(var70054578)($at)
/*    22bb0:	01e00008 */ 	jr	$t7
/*    22bb4:	00000000 */ 	nop
/*    22bb8:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22bbc:	a4510008 */ 	sh	$s1,0x8($v0)
/*    22bc0:	26310018 */ 	addiu	$s1,$s1,0x18
/*    22bc4:	3238ffff */ 	andi	$t8,$s1,0xffff
/*    22bc8:	03008825 */ 	or	$s1,$t8,$zero
/*    22bcc:	10000039 */ 	b	.L00022cb4
/*    22bd0:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22bd4:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22bd8:	a451000c */ 	sh	$s1,0xc($v0)
/*    22bdc:	8c430008 */ 	lw	$v1,0x8($v0)
/*    22be0:	26310001 */ 	addiu	$s1,$s1,0x1
/*    22be4:	3239ffff */ 	andi	$t9,$s1,0xffff
/*    22be8:	03208825 */ 	or	$s1,$t9,$zero
/*    22bec:	10000031 */ 	b	.L00022cb4
/*    22bf0:	ae030014 */ 	sw	$v1,0x14($s0)
/*    22bf4:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22bf8:	a4510004 */ 	sh	$s1,0x4($v0)
/*    22bfc:	8c430000 */ 	lw	$v1,0x0($v0)
/*    22c00:	26310001 */ 	addiu	$s1,$s1,0x1
/*    22c04:	3229ffff */ 	andi	$t1,$s1,0xffff
/*    22c08:	01208825 */ 	or	$s1,$t1,$zero
/*    22c0c:	10000029 */ 	b	.L00022cb4
/*    22c10:	ae030014 */ 	sw	$v1,0x14($s0)
/*    22c14:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22c18:	00001825 */ 	or	$v1,$zero,$zero
/*    22c1c:	a4510000 */ 	sh	$s1,0x0($v0)
/*    22c20:	26310002 */ 	addiu	$s1,$s1,0x2
/*    22c24:	322bffff */ 	andi	$t3,$s1,0xffff
/*    22c28:	01608825 */ 	or	$s1,$t3,$zero
/*    22c2c:	10000021 */ 	b	.L00022cb4
/*    22c30:	ae000014 */ 	sw	$zero,0x14($s0)
/*    22c34:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22c38:	02002025 */ 	or	$a0,$s0,$zero
/*    22c3c:	00002825 */ 	or	$a1,$zero,$zero
/*    22c40:	a4510022 */ 	sh	$s1,0x22($v0)
/*    22c44:	26310001 */ 	addiu	$s1,$s1,0x1
/*    22c48:	322cffff */ 	andi	$t4,$s1,0xffff
/*    22c4c:	0c00721a */ 	jal	func0001c868
/*    22c50:	01808825 */ 	or	$s1,$t4,$zero
/*    22c54:	10000017 */ 	b	.L00022cb4
/*    22c58:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22c5c:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22c60:	a4510044 */ 	sh	$s1,0x44($v0)
/*    22c64:	26310001 */ 	addiu	$s1,$s1,0x1
/*    22c68:	322dffff */ 	andi	$t5,$s1,0xffff
/*    22c6c:	01a08825 */ 	or	$s1,$t5,$zero
/*    22c70:	10000010 */ 	b	.L00022cb4
/*    22c74:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22c78:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22c7c:	a4510020 */ 	sh	$s1,0x20($v0)
/*    22c80:	26310001 */ 	addiu	$s1,$s1,0x1
/*    22c84:	322effff */ 	andi	$t6,$s1,0xffff
/*    22c88:	01c08825 */ 	or	$s1,$t6,$zero
/*    22c8c:	10000009 */ 	b	.L00022cb4
/*    22c90:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22c94:	8e020004 */ 	lw	$v0,0x4($s0)
/*    22c98:	a4510014 */ 	sh	$s1,0x14($v0)
/*    22c9c:	26310003 */ 	addiu	$s1,$s1,0x3
/*    22ca0:	322fffff */ 	andi	$t7,$s1,0xffff
/*    22ca4:	01e08825 */ 	or	$s1,$t7,$zero
/*    22ca8:	10000002 */ 	b	.L00022cb4
/*    22cac:	8e030014 */ 	lw	$v1,0x14($s0)
.L00022cb0:
/*    22cb0:	8e030014 */ 	lw	$v1,0x14($s0)
.L00022cb4:
/*    22cb4:	10600003 */ 	beqz	$v1,.L00022cc4
/*    22cb8:	00000000 */ 	nop
/*    22cbc:	10000010 */ 	b	.L00022d00
/*    22cc0:	00608025 */ 	or	$s0,$v1,$zero
.L00022cc4:
/*    22cc4:	1200000e */ 	beqz	$s0,.L00022d00
/*    22cc8:	00000000 */ 	nop
/*    22ccc:	8e430008 */ 	lw	$v1,0x8($s2)
.L00022cd0:
/*    22cd0:	56030004 */ 	bnel	$s0,$v1,.L00022ce4
/*    22cd4:	8e02000c */ 	lw	$v0,0xc($s0)
/*    22cd8:	10000009 */ 	b	.L00022d00
/*    22cdc:	00008025 */ 	or	$s0,$zero,$zero
/*    22ce0:	8e02000c */ 	lw	$v0,0xc($s0)
.L00022ce4:
/*    22ce4:	50400004 */ 	beqzl	$v0,.L00022cf8
/*    22ce8:	8e100008 */ 	lw	$s0,0x8($s0)
/*    22cec:	10000004 */ 	b	.L00022d00
/*    22cf0:	00408025 */ 	or	$s0,$v0,$zero
/*    22cf4:	8e100008 */ 	lw	$s0,0x8($s0)
.L00022cf8:
/*    22cf8:	1600fff5 */ 	bnez	$s0,.L00022cd0
/*    22cfc:	00000000 */ 	nop
.L00022d00:
/*    22d00:	5600ffa3 */ 	bnezl	$s0,.L00022b90
/*    22d04:	96020000 */ 	lhu	$v0,0x0($s0)
.L00022d08:
/*    22d08:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    22d0c:	02201025 */ 	or	$v0,$s1,$zero
/*    22d10:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    22d14:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    22d18:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    22d1c:	03e00008 */ 	jr	$ra
/*    22d20:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func00022d24
/*    22d24:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    22d28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    22d2c:	afa40018 */ 	sw	$a0,0x18($sp)
/*    22d30:	0c008ada */ 	jal	func00022b68
/*    22d34:	8c840000 */ 	lw	$a0,0x0($a0)
/*    22d38:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    22d3c:	a5e20014 */ 	sh	$v0,0x14($t7)
/*    22d40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    22d44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    22d48:	03e00008 */ 	jr	$ra
/*    22d4c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00022d50
.late_rodata
glabel var700545d8
.word 0x70022db0
glabel var700545dc
.word 0x70022f2c
glabel var700545e0
.word 0x70022f2c
glabel var700545e4
.word 0x70022f2c
glabel var700545e8
.word 0x70022f2c
glabel var700545ec
.word 0x70022f2c
glabel var700545f0
.word 0x70022f2c
glabel var700545f4
.word 0x70022e28
glabel var700545f8
.word 0x70022e88
glabel var700545fc
.word 0x70022f2c
glabel var70054600
.word 0x70022eac
glabel var70054604
.word 0x70022ec4
glabel var70054608
.word 0x70022f2c
glabel var7005460c
.word 0x70022f2c
glabel var70054610
.word 0x70022f2c
glabel var70054614
.word 0x70022f2c
glabel var70054618
.word 0x70022f2c
glabel var7005461c
.word 0x70022e48
glabel var70054620
.word 0x70022f2c
glabel var70054624
.word 0x70022f2c
glabel var70054628
.word 0x70022f2c
glabel var7005462c
.word 0x70022f2c
glabel var70054630
.word 0x70022e6c
glabel var70054634
.word 0x70022edc
.text
/*    22d50:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    22d54:	afb30028 */ 	sw	$s3,0x28($sp)
/*    22d58:	afb20024 */ 	sw	$s2,0x24($sp)
/*    22d5c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*    22d60:	00809025 */ 	or	$s2,$a0,$zero
/*    22d64:	00a09825 */ 	or	$s3,$a1,$zero
/*    22d68:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    22d6c:	afb10020 */ 	sw	$s1,0x20($sp)
/*    22d70:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*    22d74:	10a00083 */ 	beqz	$a1,.L00022f84
/*    22d78:	00a08025 */ 	or	$s0,$a1,$zero
/*    22d7c:	4480a000 */ 	mtc1	$zero,$f20
/*    22d80:	00000000 */ 	nop
/*    22d84:	96020000 */ 	lhu	$v0,0x0($s0)
.L00022d88:
/*    22d88:	304e00ff */ 	andi	$t6,$v0,0xff
/*    22d8c:	25cfffff */ 	addiu	$t7,$t6,-1
/*    22d90:	2de10018 */ 	sltiu	$at,$t7,0x18
/*    22d94:	10200065 */ 	beqz	$at,.L00022f2c
/*    22d98:	000f7880 */ 	sll	$t7,$t7,0x2
/*    22d9c:	3c017005 */ 	lui	$at,%hi(var700545d8)
/*    22da0:	002f0821 */ 	addu	$at,$at,$t7
/*    22da4:	8c2f45d8 */ 	lw	$t7,%lo(var700545d8)($at)
/*    22da8:	01e00008 */ 	jr	$t7
/*    22dac:	00000000 */ 	nop
/*    22db0:	02402025 */ 	or	$a0,$s2,$zero
/*    22db4:	0c006a87 */ 	jal	modelGetNodeData
/*    22db8:	02002825 */ 	or	$a1,$s0,$zero
/*    22dbc:	a0400000 */ 	sb	$zero,0x0($v0)
/*    22dc0:	e4540004 */ 	swc1	$f20,0x4($v0)
/*    22dc4:	e4540008 */ 	swc1	$f20,0x8($v0)
/*    22dc8:	e454000c */ 	swc1	$f20,0xc($v0)
/*    22dcc:	e4540010 */ 	swc1	$f20,0x10($v0)
/*    22dd0:	e4540014 */ 	swc1	$f20,0x14($v0)
/*    22dd4:	e4540018 */ 	swc1	$f20,0x18($v0)
/*    22dd8:	e454001c */ 	swc1	$f20,0x1c($v0)
/*    22ddc:	a0400001 */ 	sb	$zero,0x1($v0)
/*    22de0:	e4540034 */ 	swc1	$f20,0x34($v0)
/*    22de4:	e4540038 */ 	swc1	$f20,0x38($v0)
/*    22de8:	e454003c */ 	swc1	$f20,0x3c($v0)
/*    22dec:	e4540030 */ 	swc1	$f20,0x30($v0)
/*    22df0:	e4540024 */ 	swc1	$f20,0x24($v0)
/*    22df4:	e4540028 */ 	swc1	$f20,0x28($v0)
/*    22df8:	e454002c */ 	swc1	$f20,0x2c($v0)
/*    22dfc:	e4540020 */ 	swc1	$f20,0x20($v0)
/*    22e00:	a0400002 */ 	sb	$zero,0x2($v0)
/*    22e04:	e454004c */ 	swc1	$f20,0x4c($v0)
/*    22e08:	e4540050 */ 	swc1	$f20,0x50($v0)
/*    22e0c:	e4540054 */ 	swc1	$f20,0x54($v0)
/*    22e10:	e4540040 */ 	swc1	$f20,0x40($v0)
/*    22e14:	e4540044 */ 	swc1	$f20,0x44($v0)
/*    22e18:	e4540048 */ 	swc1	$f20,0x48($v0)
/*    22e1c:	e454005c */ 	swc1	$f20,0x5c($v0)
/*    22e20:	10000043 */ 	b	.L00022f30
/*    22e24:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22e28:	8e110004 */ 	lw	$s1,0x4($s0)
/*    22e2c:	02402025 */ 	or	$a0,$s2,$zero
/*    22e30:	0c006a87 */ 	jal	modelGetNodeData
/*    22e34:	02002825 */ 	or	$a1,$s0,$zero
/*    22e38:	ac400000 */ 	sw	$zero,0x0($v0)
/*    22e3c:	8e230008 */ 	lw	$v1,0x8($s1)
/*    22e40:	1000003b */ 	b	.L00022f30
/*    22e44:	ae030014 */ 	sw	$v1,0x14($s0)
/*    22e48:	8e110004 */ 	lw	$s1,0x4($s0)
/*    22e4c:	02402025 */ 	or	$a0,$s2,$zero
/*    22e50:	0c006a87 */ 	jal	modelGetNodeData
/*    22e54:	02002825 */ 	or	$a1,$s0,$zero
/*    22e58:	24190001 */ 	addiu	$t9,$zero,0x1
/*    22e5c:	ac590000 */ 	sw	$t9,0x0($v0)
/*    22e60:	8e230000 */ 	lw	$v1,0x0($s1)
/*    22e64:	10000032 */ 	b	.L00022f30
/*    22e68:	ae030014 */ 	sw	$v1,0x14($s0)
/*    22e6c:	02402025 */ 	or	$a0,$s2,$zero
/*    22e70:	0c006a87 */ 	jal	modelGetNodeData
/*    22e74:	02002825 */ 	or	$a1,$s0,$zero
/*    22e78:	ac400000 */ 	sw	$zero,0x0($v0)
/*    22e7c:	ac400004 */ 	sw	$zero,0x4($v0)
/*    22e80:	1000002b */ 	b	.L00022f30
/*    22e84:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22e88:	02402025 */ 	or	$a0,$s2,$zero
/*    22e8c:	0c006a87 */ 	jal	modelGetNodeData
/*    22e90:	02002825 */ 	or	$a1,$s0,$zero
/*    22e94:	ac400000 */ 	sw	$zero,0x0($v0)
/*    22e98:	02402025 */ 	or	$a0,$s2,$zero
/*    22e9c:	0c007249 */ 	jal	func0001c924
/*    22ea0:	02002825 */ 	or	$a1,$s0,$zero
/*    22ea4:	10000022 */ 	b	.L00022f30
/*    22ea8:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22eac:	02402025 */ 	or	$a0,$s2,$zero
/*    22eb0:	0c006a87 */ 	jal	modelGetNodeData
/*    22eb4:	02002825 */ 	or	$a1,$s0,$zero
/*    22eb8:	a4400000 */ 	sh	$zero,0x0($v0)
/*    22ebc:	1000001c */ 	b	.L00022f30
/*    22ec0:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22ec4:	02402025 */ 	or	$a0,$s2,$zero
/*    22ec8:	0c006a87 */ 	jal	modelGetNodeData
/*    22ecc:	02002825 */ 	or	$a1,$s0,$zero
/*    22ed0:	a4400000 */ 	sh	$zero,0x0($v0)
/*    22ed4:	10000016 */ 	b	.L00022f30
/*    22ed8:	8e030014 */ 	lw	$v1,0x14($s0)
/*    22edc:	8e110004 */ 	lw	$s1,0x4($s0)
/*    22ee0:	02402025 */ 	or	$a0,$s2,$zero
/*    22ee4:	0c006a87 */ 	jal	modelGetNodeData
/*    22ee8:	02002825 */ 	or	$a1,$s0,$zero
/*    22eec:	8e29000c */ 	lw	$t1,0xc($s1)
/*    22ef0:	ac490000 */ 	sw	$t1,0x0($v0)
/*    22ef4:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*    22ef8:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*    22efc:	862c0010 */ 	lh	$t4,0x10($s1)
/*    22f00:	8e2b000c */ 	lw	$t3,0xc($s1)
/*    22f04:	000c6880 */ 	sll	$t5,$t4,0x2
/*    22f08:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    22f0c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    22f10:	016d7021 */ 	addu	$t6,$t3,$t5
/*    22f14:	25cf0007 */ 	addiu	$t7,$t6,0x7
/*    22f18:	35f80007 */ 	ori	$t8,$t7,0x7
/*    22f1c:	3b190007 */ 	xori	$t9,$t8,0x7
/*    22f20:	ac590008 */ 	sw	$t9,0x8($v0)
/*    22f24:	10000002 */ 	b	.L00022f30
/*    22f28:	8e030014 */ 	lw	$v1,0x14($s0)
.L00022f2c:
/*    22f2c:	8e030014 */ 	lw	$v1,0x14($s0)
.L00022f30:
/*    22f30:	10600003 */ 	beqz	$v1,.L00022f40
/*    22f34:	00000000 */ 	nop
/*    22f38:	10000010 */ 	b	.L00022f7c
/*    22f3c:	00608025 */ 	or	$s0,$v1,$zero
.L00022f40:
/*    22f40:	1200000e */ 	beqz	$s0,.L00022f7c
/*    22f44:	00000000 */ 	nop
/*    22f48:	8e630008 */ 	lw	$v1,0x8($s3)
.L00022f4c:
/*    22f4c:	56030004 */ 	bnel	$s0,$v1,.L00022f60
/*    22f50:	8e02000c */ 	lw	$v0,0xc($s0)
/*    22f54:	10000009 */ 	b	.L00022f7c
/*    22f58:	00008025 */ 	or	$s0,$zero,$zero
/*    22f5c:	8e02000c */ 	lw	$v0,0xc($s0)
.L00022f60:
/*    22f60:	50400004 */ 	beqzl	$v0,.L00022f74
/*    22f64:	8e100008 */ 	lw	$s0,0x8($s0)
/*    22f68:	10000004 */ 	b	.L00022f7c
/*    22f6c:	00408025 */ 	or	$s0,$v0,$zero
/*    22f70:	8e100008 */ 	lw	$s0,0x8($s0)
.L00022f74:
/*    22f74:	1600fff5 */ 	bnez	$s0,.L00022f4c
/*    22f78:	00000000 */ 	nop
.L00022f7c:
/*    22f7c:	5600ff82 */ 	bnezl	$s0,.L00022d88
/*    22f80:	96020000 */ 	lhu	$v0,0x0($s0)
.L00022f84:
/*    22f84:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    22f88:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*    22f8c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*    22f90:	8fb10020 */ 	lw	$s1,0x20($sp)
/*    22f94:	8fb20024 */ 	lw	$s2,0x24($sp)
/*    22f98:	8fb30028 */ 	lw	$s3,0x28($sp)
/*    22f9c:	03e00008 */ 	jr	$ra
/*    22fa0:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func00022fa4
/*    22fa4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    22fa8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    22fac:	afb10018 */ 	sw	$s1,0x18($sp)
/*    22fb0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    22fb4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    22fb8:	3c013f80 */ 	lui	$at,0x3f80
/*    22fbc:	44812000 */ 	mtc1	$at,$f4
/*    22fc0:	240effff */ 	addiu	$t6,$zero,-1
/*    22fc4:	a0800000 */ 	sb	$zero,0x0($a0)
/*    22fc8:	ac850008 */ 	sw	$a1,0x8($a0)
/*    22fcc:	ac860010 */ 	sw	$a2,0x10($a0)
/*    22fd0:	a48e0002 */ 	sh	$t6,0x2($a0)
/*    22fd4:	ac800018 */ 	sw	$zero,0x18($a0)
/*    22fd8:	ac80001c */ 	sw	$zero,0x1c($a0)
/*    22fdc:	e4840014 */ 	swc1	$f4,0x14($a0)
/*    22fe0:	8ca20000 */ 	lw	$v0,0x0($a1)
/*    22fe4:	00a08825 */ 	or	$s1,$a1,$zero
/*    22fe8:	00808025 */ 	or	$s0,$a0,$zero
/*    22fec:	1040001f */ 	beqz	$v0,.L0002306c
/*    22ff0:	24050017 */ 	addiu	$a1,$zero,0x17
/*    22ff4:	94430000 */ 	lhu	$v1,0x0($v0)
.L00022ff8:
/*    22ff8:	306f00ff */ 	andi	$t7,$v1,0xff
/*    22ffc:	55e50005 */ 	bnel	$t7,$a1,.L00023014
/*    23000:	8c430014 */ 	lw	$v1,0x14($v0)
/*    23004:	92180000 */ 	lbu	$t8,0x0($s0)
/*    23008:	37190001 */ 	ori	$t9,$t8,0x1
/*    2300c:	a2190000 */ 	sb	$t9,0x0($s0)
/*    23010:	8c430014 */ 	lw	$v1,0x14($v0)
.L00023014:
/*    23014:	10600003 */ 	beqz	$v1,.L00023024
/*    23018:	00000000 */ 	nop
/*    2301c:	10000011 */ 	b	.L00023064
/*    23020:	00601025 */ 	or	$v0,$v1,$zero
.L00023024:
/*    23024:	1040000f */ 	beqz	$v0,.L00023064
/*    23028:	00000000 */ 	nop
/*    2302c:	8e280000 */ 	lw	$t0,0x0($s1)
/*    23030:	8d040008 */ 	lw	$a0,0x8($t0)
.L00023034:
/*    23034:	54440004 */ 	bnel	$v0,$a0,.L00023048
/*    23038:	8c43000c */ 	lw	$v1,0xc($v0)
/*    2303c:	10000009 */ 	b	.L00023064
/*    23040:	00001025 */ 	or	$v0,$zero,$zero
/*    23044:	8c43000c */ 	lw	$v1,0xc($v0)
.L00023048:
/*    23048:	50600004 */ 	beqzl	$v1,.L0002305c
/*    2304c:	8c420008 */ 	lw	$v0,0x8($v0)
/*    23050:	10000004 */ 	b	.L00023064
/*    23054:	00601025 */ 	or	$v0,$v1,$zero
/*    23058:	8c420008 */ 	lw	$v0,0x8($v0)
.L0002305c:
/*    2305c:	1440fff5 */ 	bnez	$v0,.L00023034
/*    23060:	00000000 */ 	nop
.L00023064:
/*    23064:	5440ffe4 */ 	bnezl	$v0,.L00022ff8
/*    23068:	94430000 */ 	lhu	$v1,0x0($v0)
.L0002306c:
/*    2306c:	10c00003 */ 	beqz	$a2,.L0002307c
/*    23070:	02002025 */ 	or	$a0,$s0,$zero
/*    23074:	0c008b54 */ 	jal	func00022d50
/*    23078:	8e250000 */ 	lw	$a1,0x0($s1)
.L0002307c:
/*    2307c:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    23080:	51200003 */ 	beqzl	$t1,.L00023090
/*    23084:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    23088:	ae000020 */ 	sw	$zero,0x20($s0)
/*    2308c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00023090:
/*    23090:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    23094:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    23098:	03e00008 */ 	jr	$ra
/*    2309c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func000230a0
/*    230a0:	44800000 */ 	mtc1	$zero,$f0
/*    230a4:	3c01bf80 */ 	lui	$at,0xbf80
/*    230a8:	44811000 */ 	mtc1	$at,$f2
/*    230ac:	3c013f80 */ 	lui	$at,0x3f80
/*    230b0:	44816000 */ 	mtc1	$at,$f12
/*    230b4:	a4800000 */ 	sh	$zero,0x0($a0)
/*    230b8:	a4800002 */ 	sh	$zero,0x2($a0)
/*    230bc:	a080000a */ 	sb	$zero,0xa($a0)
/*    230c0:	ac800068 */ 	sw	$zero,0x68($a0)
/*    230c4:	ac80006c */ 	sw	$zero,0x6c($a0)
/*    230c8:	ac800070 */ 	sw	$zero,0x70($a0)
/*    230cc:	a080000b */ 	sb	$zero,0xb($a0)
/*    230d0:	e4800010 */ 	swc1	$f0,0x10($a0)
/*    230d4:	e4800028 */ 	swc1	$f0,0x28($a0)
/*    230d8:	e4800034 */ 	swc1	$f0,0x34($a0)
/*    230dc:	e480004c */ 	swc1	$f0,0x4c($a0)
/*    230e0:	e4800054 */ 	swc1	$f0,0x54($a0)
/*    230e4:	e4800058 */ 	swc1	$f0,0x58($a0)
/*    230e8:	e4800080 */ 	swc1	$f0,0x80($a0)
/*    230ec:	e4820018 */ 	swc1	$f2,0x18($a0)
/*    230f0:	e482003c */ 	swc1	$f2,0x3c($a0)
/*    230f4:	e48c001c */ 	swc1	$f12,0x1c($a0)
/*    230f8:	e48c0040 */ 	swc1	$f12,0x40($a0)
/*    230fc:	e48c0074 */ 	swc1	$f12,0x74($a0)
/*    23100:	03e00008 */ 	jr	$ra
/*    23104:	e48c0088 */ 	swc1	$f12,0x88($a0)
);

GLOBAL_ASM(
glabel func00023108
/*    23108:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    2310c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    23110:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    23114:	afa40018 */ 	sw	$a0,0x18($sp)
/*    23118:	afa70024 */ 	sw	$a3,0x24($sp)
/*    2311c:	00c02825 */ 	or	$a1,$a2,$zero
/*    23120:	0c006a87 */ 	jal	modelGetNodeData
/*    23124:	afa60020 */ 	sw	$a2,0x20($sp)
/*    23128:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    2312c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    23130:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*    23134:	ac450000 */ 	sw	$a1,0x0($v0)
/*    23138:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    2313c:	84f80014 */ 	lh	$t8,0x14($a3)
/*    23140:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*    23144:	0018c880 */ 	sll	$t9,$t8,0x2
/*    23148:	01f94021 */ 	addu	$t0,$t7,$t9
/*    2314c:	ac480004 */ 	sw	$t0,0x4($v0)
/*    23150:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    23154:	acc30014 */ 	sw	$v1,0x14($a2)
/*    23158:	10600006 */ 	beqz	$v1,.L00023174
/*    2315c:	00602025 */ 	or	$a0,$v1,$zero
/*    23160:	ac660008 */ 	sw	$a2,0x8($v1)
.L00023164:
/*    23164:	8c63000c */ 	lw	$v1,0xc($v1)
/*    23168:	5460fffe */ 	bnezl	$v1,.L00023164
/*    2316c:	ac660008 */ 	sw	$a2,0x8($v1)
/*    23170:	8cc40014 */ 	lw	$a0,0x14($a2)
.L00023174:
/*    23174:	0c008ada */ 	jal	func00022b68
/*    23178:	00000000 */ 	nop
/*    2317c:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*    23180:	84ea0014 */ 	lh	$t2,0x14($a3)
/*    23184:	01425821 */ 	addu	$t3,$t2,$v0
/*    23188:	a4eb0014 */ 	sh	$t3,0x14($a3)
/*    2318c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    23190:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    23194:	03e00008 */ 	jr	$ra
/*    23198:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002319c
.late_rodata
glabel var70054638
.word 0x70023200
glabel var7005463c
.word 0x700232a4
glabel var70054640
.word 0x700232a4
glabel var70054644
.word 0x700232a4
glabel var70054648
.word 0x70023278
glabel var7005464c
.word 0x70023298
glabel var70054650
.word 0x700232a4
glabel var70054654
.word 0x700232a4
glabel var70054658
.word 0x700232a4
glabel var7005465c
.word 0x700232a4
glabel var70054660
.word 0x700232a4
glabel var70054664
.word 0x700232a4
glabel var70054668
.word 0x700232a4
glabel var7005466c
.word 0x700232a4
glabel var70054670
.word 0x70023288
glabel var70054674
.word 0x700232a4
glabel var70054678
.word 0x700232a4
glabel var7005467c
.word 0x700232a4
glabel var70054680
.word 0x70023260
glabel var70054684
.word 0x700232a4
glabel var70054688
.word 0x70023230
glabel var7005468c
.word 0x00000000
.text
/*    2319c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    231a0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    231a4:	afb30020 */ 	sw	$s3,0x20($sp)
/*    231a8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    231ac:	afb10018 */ 	sw	$s1,0x18($sp)
/*    231b0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    231b4:	8cb00000 */ 	lw	$s0,0x0($a1)
/*    231b8:	00a09025 */ 	or	$s2,$a1,$zero
/*    231bc:	00c09825 */ 	or	$s3,$a2,$zero
/*    231c0:	16000002 */ 	bnez	$s0,.L000231cc
/*    231c4:	00008825 */ 	or	$s1,$zero,$zero
/*    231c8:	8c900000 */ 	lw	$s0,0x0($a0)
.L000231cc:
/*    231cc:	52000049 */ 	beqzl	$s0,.L000232f4
/*    231d0:	ae710000 */ 	sw	$s1,0x0($s3)
/*    231d4:	96020000 */ 	lhu	$v0,0x0($s0)
.L000231d8:
/*    231d8:	304e00ff */ 	andi	$t6,$v0,0xff
/*    231dc:	25cffffc */ 	addiu	$t7,$t6,-4
/*    231e0:	2de10015 */ 	sltiu	$at,$t7,0x15
/*    231e4:	1020002f */ 	beqz	$at,.L000232a4
/*    231e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    231ec:	3c017005 */ 	lui	$at,%hi(var70054638)
/*    231f0:	002f0821 */ 	addu	$at,$at,$t7
/*    231f4:	8c2f4638 */ 	lw	$t7,%lo(var70054638)($at)
/*    231f8:	01e00008 */ 	jr	$t7
/*    231fc:	00000000 */ 	nop
/*    23200:	8e580000 */ 	lw	$t8,0x0($s2)
/*    23204:	8e020004 */ 	lw	$v0,0x4($s0)
/*    23208:	52180004 */ 	beql	$s0,$t8,.L0002321c
/*    2320c:	8c430004 */ 	lw	$v1,0x4($v0)
/*    23210:	10000024 */ 	b	.L000232a4
/*    23214:	8c510000 */ 	lw	$s1,0x0($v0)
/*    23218:	8c430004 */ 	lw	$v1,0x4($v0)
.L0002321c:
/*    2321c:	8e790000 */ 	lw	$t9,0x0($s3)
/*    23220:	10790020 */ 	beq	$v1,$t9,.L000232a4
/*    23224:	00000000 */ 	nop
/*    23228:	1000001e */ 	b	.L000232a4
/*    2322c:	00608825 */ 	or	$s1,$v1,$zero
/*    23230:	8e480000 */ 	lw	$t0,0x0($s2)
/*    23234:	8e020004 */ 	lw	$v0,0x4($s0)
/*    23238:	52080004 */ 	beql	$s0,$t0,.L0002324c
/*    2323c:	8c430004 */ 	lw	$v1,0x4($v0)
/*    23240:	10000018 */ 	b	.L000232a4
/*    23244:	8c510000 */ 	lw	$s1,0x0($v0)
/*    23248:	8c430004 */ 	lw	$v1,0x4($v0)
.L0002324c:
/*    2324c:	8e690000 */ 	lw	$t1,0x0($s3)
/*    23250:	10690014 */ 	beq	$v1,$t1,.L000232a4
/*    23254:	00000000 */ 	nop
/*    23258:	10000012 */ 	b	.L000232a4
/*    2325c:	00608825 */ 	or	$s1,$v1,$zero
/*    23260:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*    23264:	8e020004 */ 	lw	$v0,0x4($s0)
/*    23268:	120a000e */ 	beq	$s0,$t2,.L000232a4
/*    2326c:	00000000 */ 	nop
/*    23270:	1000000c */ 	b	.L000232a4
/*    23274:	8c510008 */ 	lw	$s1,0x8($v0)
/*    23278:	8e020004 */ 	lw	$v0,0x4($s0)
/*    2327c:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*    23280:	10000008 */ 	b	.L000232a4
/*    23284:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*    23288:	8e020004 */ 	lw	$v0,0x4($s0)
/*    2328c:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*    23290:	10000004 */ 	b	.L000232a4
/*    23294:	ae0c0014 */ 	sw	$t4,0x14($s0)
/*    23298:	02002025 */ 	or	$a0,$s0,$zero
/*    2329c:	0c00721a */ 	jal	func0001c868
/*    232a0:	24050001 */ 	addiu	$a1,$zero,0x1
.L000232a4:
/*    232a4:	56200013 */ 	bnezl	$s1,.L000232f4
/*    232a8:	ae710000 */ 	sw	$s1,0x0($s3)
/*    232ac:	8e020014 */ 	lw	$v0,0x14($s0)
/*    232b0:	10400003 */ 	beqz	$v0,.L000232c0
/*    232b4:	00000000 */ 	nop
/*    232b8:	1000000b */ 	b	.L000232e8
/*    232bc:	00408025 */ 	or	$s0,$v0,$zero
.L000232c0:
/*    232c0:	12000009 */ 	beqz	$s0,.L000232e8
/*    232c4:	00000000 */ 	nop
/*    232c8:	8e02000c */ 	lw	$v0,0xc($s0)
.L000232cc:
/*    232cc:	50400004 */ 	beqzl	$v0,.L000232e0
/*    232d0:	8e100008 */ 	lw	$s0,0x8($s0)
/*    232d4:	10000004 */ 	b	.L000232e8
/*    232d8:	00408025 */ 	or	$s0,$v0,$zero
/*    232dc:	8e100008 */ 	lw	$s0,0x8($s0)
.L000232e0:
/*    232e0:	5600fffa */ 	bnezl	$s0,.L000232cc
/*    232e4:	8e02000c */ 	lw	$v0,0xc($s0)
.L000232e8:
/*    232e8:	5600ffbb */ 	bnezl	$s0,.L000231d8
/*    232ec:	96020000 */ 	lhu	$v0,0x0($s0)
/*    232f0:	ae710000 */ 	sw	$s1,0x0($s3)
.L000232f4:
/*    232f4:	ae500000 */ 	sw	$s0,0x0($s2)
/*    232f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    232fc:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    23300:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    23304:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    23308:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    2330c:	03e00008 */ 	jr	$ra
/*    23310:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func00023314
/*    23314:	afa40000 */ 	sw	$a0,0x0($sp)
/*    23318:	94a20000 */ 	lhu	$v0,0x0($a1)
/*    2331c:	24010004 */ 	addiu	$at,$zero,0x4
/*    23320:	304e00ff */ 	andi	$t6,$v0,0xff
/*    23324:	11c10007 */ 	beq	$t6,$at,.L00023344
/*    23328:	24010016 */ 	addiu	$at,$zero,0x16
/*    2332c:	11c1001b */ 	beq	$t6,$at,.L0002339c
/*    23330:	24010018 */ 	addiu	$at,$zero,0x18
/*    23334:	51c1000f */ 	beql	$t6,$at,.L00023374
/*    23338:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    2333c:	03e00008 */ 	jr	$ra
/*    23340:	00000000 */ 	nop
.L00023344:
/*    23344:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    23348:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*    2334c:	54cf0004 */ 	bnel	$a2,$t7,.L00023360
/*    23350:	8c580004 */ 	lw	$t8,0x4($v0)
/*    23354:	03e00008 */ 	jr	$ra
/*    23358:	ac470000 */ 	sw	$a3,0x0($v0)
/*    2335c:	8c580004 */ 	lw	$t8,0x4($v0)
.L00023360:
/*    23360:	14d80013 */ 	bne	$a2,$t8,.L000233b0
/*    23364:	00000000 */ 	nop
/*    23368:	03e00008 */ 	jr	$ra
/*    2336c:	ac470004 */ 	sw	$a3,0x4($v0)
/*    23370:	8ca20004 */ 	lw	$v0,0x4($a1)
.L00023374:
/*    23374:	8c590000 */ 	lw	$t9,0x0($v0)
/*    23378:	54d90004 */ 	bnel	$a2,$t9,.L0002338c
/*    2337c:	8c480004 */ 	lw	$t0,0x4($v0)
/*    23380:	03e00008 */ 	jr	$ra
/*    23384:	ac470000 */ 	sw	$a3,0x0($v0)
/*    23388:	8c480004 */ 	lw	$t0,0x4($v0)
.L0002338c:
/*    2338c:	14c80008 */ 	bne	$a2,$t0,.L000233b0
/*    23390:	00000000 */ 	nop
/*    23394:	03e00008 */ 	jr	$ra
/*    23398:	ac470004 */ 	sw	$a3,0x4($v0)
.L0002339c:
/*    2339c:	8ca20004 */ 	lw	$v0,0x4($a1)
/*    233a0:	8c490008 */ 	lw	$t1,0x8($v0)
/*    233a4:	14c90002 */ 	bne	$a2,$t1,.L000233b0
/*    233a8:	00000000 */ 	nop
/*    233ac:	ac470008 */ 	sw	$a3,0x8($v0)
.L000233b0:
/*    233b0:	03e00008 */ 	jr	$ra
/*    233b4:	00000000 */ 	nop
/*    233b8:	00000000 */ 	nop
/*    233bc:	00000000 */ 	nop
);
