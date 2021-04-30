#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_184d0.h"
#include "data.h"
#include "types.h"

s32 g_NumGlobalAilists = 0;
s32 g_NumLvAilists = 0;
u32 var8005ef38 = 0x00000000;
u32 var8005ef3c = 0x00000000;
u32 var8005ef40 = 0x00040800;
u32 var8005ef44 = 0x00000000;
u32 var8005ef48 = 0x0c100000;
u32 var8005ef4c = 0x00000000;
u32 var8005ef50 = 0x00001400;
u32 var8005ef54 = 0x0018001c;
u32 var8005ef58 = 0x00000000;

u32 var8005ef5c = (u32)func00018680+0xef4;
u32 var8005ef60 = (u32)func00018680+0xa3c;
u32 var8005ef64 = (u32)func00018680+0x3a8;
u32 var8005ef68 = (u32)func00018680+0x990;
u32 var8005ef6c = (u32)func00018680+0xecc;
u32 var8005ef70 = (u32)func00018680+0xed4;
u32 var8005ef74 = (u32)func00018680+0xe60;
u32 var8005ef78 = (u32)func00018680+0xe24;

u32 var8005ef7c = 0x00000000;
u32 var8005ef80 = (u32)func00019be0+0x84;
u32 var8005ef84 = (u32)func00019be0+0x90;
u32 var8005ef88 = (u32)func00019be0+0xa8;
u32 var8005ef8c = (u32)func00019be0+0xcc;

u32 var8005ef90 = 0xff08ffff;
u32 var8005ef94 = 0xffffffff;
u32 var8005ef98 = 0x0c22ff44;
u32 var8005ef9c = 0x20ffffff;
u32 var8005efa0 = 0xffff04ff;
u32 var8005efa4 = 0xffffff00;
u32 var8005efa8 = 0x14000000;
u32 var8005efac = 0x00000000;
u32 var8005efb0 = 0x00000000;

#if VERSION >= VERSION_PAL_FINAL
u32 var8005efb0_2 = 0;
#endif

bool g_ModelDistanceDisabled = false;
f32 g_ModelDistanceScale = 1;
bool var8005efbc = false;
u32 var8005efc0 = 0x00000000;
bool (*var8005efc4)(struct model *model, struct modelnode *node) = NULL;

#if VERSION >= VERSION_PAL_FINAL
u32 var8005efd8_2 = 0;
#endif

void *var8005efc8 = NULL; // pointer to a function
void *var8005efcc = NULL; // pointer to a function
u32 var8005efd0 = 0x00000000;
u32 var8005efd4 = 0x00000000;
u32 var8005efd8 = 0x00000000;
u32 var8005efdc = 0x00000001;
u32 var8005efe0 = 0x00000000;
u32 var8005efe4 = 0x00000000;
u32 var8005efe8 = 0x00000000;
u32 var8005efec = 0x00000000;
u32 var8005eff0 = 0x00000000;
u32 var8005eff4 = 0x00000000;
u32 var8005eff8 = 0xffffffff;

const u32 var70054210[] = {0xbf7ffcb9};
const u32 var70054214[] = {0x3f7ffcb9};
const u32 var70054218[] = {0x40490fdb};
const u32 var7005421c[] = {0x40c90fdb};
const u32 var70054220[] = {0x3fc90fda};
const u32 var70054224[] = {0xbf7ffcb9};
const u32 var70054228[] = {0x3f7ffcb9};
const u32 var7005422c[] = {0x38c90fdb};
const u32 var70054230[] = {0x3fc90fda};
const u32 var70054234[] = {0x38490fdb};
const u32 var70054238[] = {0x3fc90fdb};
const u32 var7005423c[] = {0x46fffe00};
const u32 var70054240[] = {0x384910a4};
const u32 var70054244[] = {0x3fc90fda};
const u32 var70054248[] = {0x362edef8};
const u32 var7005424c[] = {0xb94fb7ff};
const u32 var70054250[] = {0x3c08876a};
const u32 var70054254[] = {0xbe2aaaa6};
const u32 var70054258[] = {0x3ea2f983};
const u32 var7005425c[] = {0x40490fdb};
const u32 var70054260[] = {0x330885a3};
const u32 var70054264[] = {0x362edef8};
const u32 var70054268[] = {0xb94fb7ff};
const u32 var7005426c[] = {0x3c08876a};
const u32 var70054270[] = {0xbe2aaaa6};

u8 *ailistFindById(s32 ailistid)
{
	s32 lower;
	s32 upper;
	s32 index;

	if (ailistid >= 0x401) {
		if (g_StageSetup.ailists) {
			lower = 0;
			upper = g_NumLvAilists;
			index;

			while (upper >= lower) {
				index = (lower + upper) / 2;

				if (g_StageSetup.ailists[index].id == ailistid) {
					return g_StageSetup.ailists[index].list;
				}

				if (ailistid < g_StageSetup.ailists[index].id) {
					upper = index - 1;
				} else {
					lower = index + 1;
				}
			}
		}
	} else {
		lower = 0;
		upper = g_NumGlobalAilists;
		index;

		while (upper >= lower) {
			index = (lower + upper) / 2;

			if (g_GlobalAilists[index].id == ailistid) {
				return g_GlobalAilists[index].list;
			}

			if (ailistid < g_GlobalAilists[index].id) {
				upper = index - 1;
			} else {
				lower = index + 1;
			}
		}
	}

	return NULL;
}

void objSetBlockedPathUnblocked(struct defaultobj *blocker, bool unblocked)
{
	if (blocker->hidden & OBJHFLAG_02000000) {
		struct blockedpathobj *bp = g_BlockedPaths;

		while (bp) {
			if (bp->blocker == blocker) {
				if (unblocked) {
					waypointEnableSegment(&g_StageSetup.waypoints[bp->waypoint1], &g_StageSetup.waypoints[bp->waypoint2]);
					break;
				} else {
					waypointDisableSegment(&g_StageSetup.waypoints[bp->waypoint1], &g_StageSetup.waypoints[bp->waypoint2]);
					break;
				}
			}

			bp = bp->next;
		}
	}
}

GLOBAL_ASM(
glabel func00018680
/*    18680:	27bdf800 */ 	addiu	$sp,$sp,-2048
/*    18684:	afb00780 */ 	sw	$s0,0x780($sp)
/*    18688:	afb10784 */ 	sw	$s1,0x784($sp)
/*    1868c:	afb20788 */ 	sw	$s2,0x788($sp)
/*    18690:	afb3078c */ 	sw	$s3,0x78c($sp)
/*    18694:	afb40790 */ 	sw	$s4,0x790($sp)
/*    18698:	afb50794 */ 	sw	$s5,0x794($sp)
/*    1869c:	afb60798 */ 	sw	$s6,0x798($sp)
/*    186a0:	afb7079c */ 	sw	$s7,0x79c($sp)
/*    186a4:	afbe07a0 */ 	sw	$s8,0x7a0($sp)
/*    186a8:	afbc07a4 */ 	sw	$gp,0x7a4($sp)
/*    186ac:	afbf07a8 */ 	sw	$ra,0x7a8($sp)
/*    186b0:	e7b407b0 */ 	swc1	$f20,0x7b0($sp)
/*    186b4:	e7b507b4 */ 	swc1	$f21,0x7b4($sp)
/*    186b8:	e7b607b8 */ 	swc1	$f22,0x7b8($sp)
/*    186bc:	e7b707bc */ 	swc1	$f23,0x7bc($sp)
/*    186c0:	e7b807c0 */ 	swc1	$f24,0x7c0($sp)
/*    186c4:	e7b907c4 */ 	swc1	$f25,0x7c4($sp)
/*    186c8:	e7ba07c8 */ 	swc1	$f26,0x7c8($sp)
/*    186cc:	e7bb07cc */ 	swc1	$f27,0x7cc($sp)
/*    186d0:	e7bc07d0 */ 	swc1	$f28,0x7d0($sp)
/*    186d4:	e7bd07d4 */ 	swc1	$f29,0x7d4($sp)
/*    186d8:	e7be07d8 */ 	swc1	$f30,0x7d8($sp)
/*    186dc:	e7bf07dc */ 	swc1	$f31,0x7dc($sp)
/*    186e0:	afa007f8 */ 	sw	$zero,0x7f8($sp)
/*    186e4:	3c013f80 */ 	lui	$at,0x3f80
/*    186e8:	4481f800 */ 	mtc1	$at,$f31
/*    186ec:	03a04025 */ 	or	$t0,$sp,$zero
/*    186f0:	8ca90008 */ 	lw	$t1,0x8($a1)
/*    186f4:	9529000e */ 	lhu	$t1,0xe($t1)
.L000186f8:
/*    186f8:	a5000000 */ 	sh	$zero,0x0($t0)
/*    186fc:	2529ffff */ 	addiu	$t1,$t1,-1
/*    18700:	5520fffd */ 	bnezl	$t1,.L000186f8
/*    18704:	25080008 */ 	addiu	$t0,$t0,0x8
/*    18708:	00054020 */ 	add	$t0,$zero,$a1
/*    1870c:	8ca60020 */ 	lw	$a2,0x20($a1)
/*    18710:	10c000ae */ 	beqz	$a2,.L000189cc
/*    18714:	00000000 */ 	nop
/*    18718:	03a04025 */ 	or	$t0,$sp,$zero
/*    1871c:	20090000 */ 	addi	$t1,$zero,0x0
/*    18720:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    18724:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    18728:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1872c:	84cd0000 */ 	lh	$t5,0x0($a2)
/*    18730:	018d6020 */ 	add	$t4,$t4,$t5
/*    18734:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    18738:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    1873c:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    18740:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18744:	000b5880 */ 	sll	$t3,$t3,0x2
/*    18748:	018b6020 */ 	add	$t4,$t4,$t3
/*    1874c:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    18750:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    18754:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    18758:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1875c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    18760:	01ad7020 */ 	add	$t6,$t5,$t5
/*    18764:	01ae6820 */ 	add	$t5,$t5,$t6
/*    18768:	018d6020 */ 	add	$t4,$t4,$t5
/*    1876c:	858d0008 */ 	lh	$t5,0x8($t4)
/*    18770:	918c000a */ 	lbu	$t4,0xa($t4)
/*    18774:	014d5820 */ 	add	$t3,$t2,$t5
/*    18778:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    1877c:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    18780:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    18784:	114b003b */ 	beq	$t2,$t3,.L00018874
/*    18788:	20020000 */ 	addi	$v0,$zero,0x0
/*    1878c:	90ce0004 */ 	lbu	$t6,0x4($a2)
/*    18790:	000e7080 */ 	sll	$t6,$t6,0x2
/*    18794:	01ae7020 */ 	add	$t6,$t5,$t6
/*    18798:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    1879c:	0c00658d */ 	jal	func00019634
/*    187a0:	201c0000 */ 	addi	$gp,$zero,0x0
/*    187a4:	44800800 */ 	mtc1	$zero,$f1
/*    187a8:	c4c00010 */ 	lwc1	$f0,0x10($a2)
/*    187ac:	46000832 */ 	c.eq.s	$f1,$f0
/*    187b0:	45010030 */ 	bc1t	.L00018874
/*    187b4:	00000000 */ 	nop
/*    187b8:	03a04025 */ 	or	$t0,$sp,$zero
/*    187bc:	250803c0 */ 	addiu	$t0,$t0,0x3c0
/*    187c0:	8ca90008 */ 	lw	$t1,0x8($a1)
/*    187c4:	9529000e */ 	lhu	$t1,0xe($t1)
.L000187c8:
/*    187c8:	a5000000 */ 	sh	$zero,0x0($t0)
/*    187cc:	2529ffff */ 	addiu	$t1,$t1,-1
/*    187d0:	5520fffd */ 	bnezl	$t1,.L000187c8
/*    187d4:	25080008 */ 	addiu	$t0,$t0,0x8
/*    187d8:	3c014580 */ 	lui	$at,0x4580
/*    187dc:	44811000 */ 	mtc1	$at,$f2
/*    187e0:	03a04025 */ 	or	$t0,$sp,$zero
/*    187e4:	46020002 */ 	mul.s	$f0,$f0,$f2
/*    187e8:	20090000 */ 	addi	$t1,$zero,0x0
/*    187ec:	4600000d */ 	trunc.w.s	$f0,$f0
/*    187f0:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    187f4:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    187f8:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    187fc:	84cd0000 */ 	lh	$t5,0x0($a2)
/*    18800:	018d6020 */ 	add	$t4,$t4,$t5
/*    18804:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    18808:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    1880c:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    18810:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18814:	000b5880 */ 	sll	$t3,$t3,0x2
/*    18818:	018b6020 */ 	add	$t4,$t4,$t3
/*    1881c:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    18820:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    18824:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    18828:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1882c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    18830:	01ad7020 */ 	add	$t6,$t5,$t5
/*    18834:	01ae6820 */ 	add	$t5,$t5,$t6
/*    18838:	018d6020 */ 	add	$t4,$t4,$t5
/*    1883c:	858d0008 */ 	lh	$t5,0x8($t4)
/*    18840:	918c000a */ 	lbu	$t4,0xa($t4)
/*    18844:	014d5820 */ 	add	$t3,$t2,$t5
/*    18848:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    1884c:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    18850:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    18854:	114b0007 */ 	beq	$t2,$t3,.L00018874
/*    18858:	20020000 */ 	addi	$v0,$zero,0x0
/*    1885c:	90ce0005 */ 	lbu	$t6,0x5($a2)
/*    18860:	000e7080 */ 	sll	$t6,$t6,0x2
/*    18864:	01ae7020 */ 	add	$t6,$t5,$t6
/*    18868:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    1886c:	0c006637 */ 	jal	func000198dc
/*    18870:	201c0000 */ 	addi	$gp,$zero,0x0
.L00018874:
/*    18874:	44800800 */ 	mtc1	$zero,$f1
/*    18878:	c4c00054 */ 	lwc1	$f0,0x54($a2)
/*    1887c:	46010032 */ 	c.eq.s	$f0,$f1
/*    18880:	45010052 */ 	bc1t	.L000189cc
/*    18884:	e7a007e0 */ 	swc1	$f0,0x7e0($sp)
/*    18888:	03a04025 */ 	or	$t0,$sp,$zero
/*    1888c:	250803c0 */ 	addiu	$t0,$t0,0x3c0
/*    18890:	20090000 */ 	addi	$t1,$zero,0x0
/*    18894:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    18898:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    1889c:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    188a0:	84cd0002 */ 	lh	$t5,0x2($a2)
/*    188a4:	018d6020 */ 	add	$t4,$t4,$t5
/*    188a8:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    188ac:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    188b0:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    188b4:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    188b8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    188bc:	018b6020 */ 	add	$t4,$t4,$t3
/*    188c0:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    188c4:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    188c8:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    188cc:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    188d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*    188d4:	01ad7020 */ 	add	$t6,$t5,$t5
/*    188d8:	01ae6820 */ 	add	$t5,$t5,$t6
/*    188dc:	018d6020 */ 	add	$t4,$t4,$t5
/*    188e0:	858d0008 */ 	lh	$t5,0x8($t4)
/*    188e4:	918c000a */ 	lbu	$t4,0xa($t4)
/*    188e8:	014d5820 */ 	add	$t3,$t2,$t5
/*    188ec:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    188f0:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    188f4:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    188f8:	114b0034 */ 	beq	$t2,$t3,.L000189cc
/*    188fc:	20020000 */ 	addi	$v0,$zero,0x0
/*    18900:	90ce0006 */ 	lbu	$t6,0x6($a2)
/*    18904:	000e7080 */ 	sll	$t6,$t6,0x2
/*    18908:	01ae7020 */ 	add	$t6,$t5,$t6
/*    1890c:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    18910:	0c00658d */ 	jal	func00019634
/*    18914:	201c0000 */ 	addi	$gp,$zero,0x0
/*    18918:	44800800 */ 	mtc1	$zero,$f1
/*    1891c:	c4c00034 */ 	lwc1	$f0,0x34($a2)
/*    18920:	46000832 */ 	c.eq.s	$f1,$f0
/*    18924:	45010029 */ 	bc1t	.L000189cc
/*    18928:	00000000 */ 	nop
/*    1892c:	3c014580 */ 	lui	$at,0x4580
/*    18930:	44811000 */ 	mtc1	$at,$f2
/*    18934:	03a04025 */ 	or	$t0,$sp,$zero
/*    18938:	250803c0 */ 	addiu	$t0,$t0,0x3c0
/*    1893c:	46020002 */ 	mul.s	$f0,$f0,$f2
/*    18940:	20090000 */ 	addi	$t1,$zero,0x0
/*    18944:	4600000d */ 	trunc.w.s	$f0,$f0
/*    18948:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    1894c:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    18950:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18954:	84cd0002 */ 	lh	$t5,0x2($a2)
/*    18958:	018d6020 */ 	add	$t4,$t4,$t5
/*    1895c:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    18960:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    18964:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    18968:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1896c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    18970:	018b6020 */ 	add	$t4,$t4,$t3
/*    18974:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    18978:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    1897c:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    18980:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18984:	000d6880 */ 	sll	$t5,$t5,0x2
/*    18988:	01ad7020 */ 	add	$t6,$t5,$t5
/*    1898c:	01ae6820 */ 	add	$t5,$t5,$t6
/*    18990:	018d6020 */ 	add	$t4,$t4,$t5
/*    18994:	858d0008 */ 	lh	$t5,0x8($t4)
/*    18998:	918c000a */ 	lbu	$t4,0xa($t4)
/*    1899c:	014d5820 */ 	add	$t3,$t2,$t5
/*    189a0:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    189a4:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    189a8:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    189ac:	114b0007 */ 	beq	$t2,$t3,.L000189cc
/*    189b0:	20020000 */ 	addi	$v0,$zero,0x0
/*    189b4:	90ce0007 */ 	lbu	$t6,0x7($a2)
/*    189b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    189bc:	01ae7020 */ 	add	$t6,$t5,$t6
/*    189c0:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    189c4:	0c006637 */ 	jal	func000198dc
/*    189c8:	201c0000 */ 	addi	$gp,$zero,0x0
.L000189cc:
/*    189cc:	8ca70008 */ 	lw	$a3,0x8($a1)
/*    189d0:	8cfc0000 */ 	lw	$gp,0x0($a3)
/*    189d4:	8cf60004 */ 	lw	$s6,0x4($a3)
/*    189d8:	03a0b825 */ 	or	$s7,$sp,$zero
/*    189dc:	138002fa */ 	beqz	$gp,.L000195c8
/*    189e0:	24420001 */ 	addiu	$v0,$v0,0x1
.L000189e4:
/*    189e4:	3c098006 */ 	lui	$t1,%hi(var8005ef40)
/*    189e8:	2529ef40 */ 	addiu	$t1,$t1,%lo(var8005ef40)
/*    189ec:	97880000 */ 	lhu	$t0,0x0($gp)
/*    189f0:	310800ff */ 	andi	$t0,$t0,0xff
/*    189f4:	01094020 */ 	add	$t0,$t0,$t1
/*    189f8:	3c098006 */ 	lui	$t1,%hi(var8005ef5c)
/*    189fc:	2529ef5c */ 	addiu	$t1,$t1,%lo(var8005ef5c)
/*    18a00:	91080000 */ 	lbu	$t0,0x0($t0)
/*    18a04:	01284020 */ 	add	$t0,$t1,$t0
/*    18a08:	8d090000 */ 	lw	$t1,0x0($t0)
/*    18a0c:	97880000 */ 	lhu	$t0,0x0($gp)
/*    18a10:	01200008 */ 	jr	$t1
/*    18a14:	310800ff */ 	andi	$t0,$t0,0xff
/*    18a18:	138002eb */ 	beqz	$gp,.L000195c8
/*    18a1c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    18a20:	87880000 */ 	lh	$t0,0x0($gp)
/*    18a24:	310800ff */ 	andi	$t0,$t0,0xff
/*    18a28:	afa007e4 */ 	sw	$zero,0x7e4($sp)
/*    18a2c:	10a00177 */ 	beqz	$a1,.L0001900c
/*    18a30:	8f880004 */ 	lw	$t0,0x4($gp)
/*    18a34:	10c00168 */ 	beqz	$a2,.L00018fd8
/*    18a38:	9509000c */ 	lhu	$t1,0xc($t0)
/*    18a3c:	94ca0000 */ 	lhu	$t2,0x0($a2)
/*    18a40:	4480e800 */ 	mtc1	$zero,$f29
/*    18a44:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    18a48:	461ee832 */ 	c.eq.s	$f29,$f30
/*    18a4c:	45010056 */ 	bc1t	.L00018ba8
/*    18a50:	00000000 */ 	nop
/*    18a54:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    18a58:	11400015 */ 	beqz	$t2,.L00018ab0
/*    18a5c:	00000000 */ 	nop
/*    18a60:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    18a64:	00094840 */ 	sll	$t1,$t1,0x1
/*    18a68:	01495020 */ 	add	$t2,$t2,$t1
/*    18a6c:	91490001 */ 	lbu	$t1,0x1($t2)
/*    18a70:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18a74:	02e94020 */ 	add	$t0,$s7,$t1
/*    18a78:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18a7c:	3c0a0001 */ 	lui	$t2,0x1
/*    18a80:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18a84:	15800002 */ 	bnez	$t4,.L00018a90
/*    18a88:	014c6022 */ 	sub	$t4,$t2,$t4
/*    18a8c:	200c0000 */ 	addi	$t4,$zero,0x0
.L00018a90:
/*    18a90:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18a94:	15600002 */ 	bnez	$t3,.L00018aa0
/*    18a98:	014b5822 */ 	sub	$t3,$t2,$t3
/*    18a9c:	200b0000 */ 	addi	$t3,$zero,0x0
.L00018aa0:
/*    18aa0:	316bffff */ 	andi	$t3,$t3,0xffff
/*    18aa4:	318cffff */ 	andi	$t4,$t4,0xffff
/*    18aa8:	080062b2 */ 	j	.L00018ac8
/*    18aac:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00018ab0:
/*    18ab0:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18ab4:	02e94020 */ 	add	$t0,$s7,$t1
/*    18ab8:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18abc:	950a0002 */ 	lhu	$t2,0x2($t0)
/*    18ac0:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18ac4:	950c0006 */ 	lhu	$t4,0x6($t0)
.L00018ac8:
/*    18ac8:	8f900004 */ 	lw	$s0,0x4($gp)
/*    18acc:	90d10009 */ 	lbu	$s1,0x9($a2)
/*    18ad0:	12200015 */ 	beqz	$s1,.L00018b28
/*    18ad4:	9609000c */ 	lhu	$t1,0xc($s0)
/*    18ad8:	8ed00004 */ 	lw	$s0,0x4($s6)
/*    18adc:	00094840 */ 	sll	$t1,$t1,0x1
/*    18ae0:	02098020 */ 	add	$s0,$s0,$t1
/*    18ae4:	92090001 */ 	lbu	$t1,0x1($s0)
/*    18ae8:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18aec:	02e94020 */ 	add	$t0,$s7,$t1
/*    18af0:	3c100001 */ 	lui	$s0,0x1
/*    18af4:	951403c6 */ 	lhu	$s4,0x3c6($t0)
/*    18af8:	16800002 */ 	bnez	$s4,.L00018b04
/*    18afc:	0214a022 */ 	sub	$s4,$s0,$s4
/*    18b00:	20140000 */ 	addi	$s4,$zero,0x0
.L00018b04:
/*    18b04:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    18b08:	16600002 */ 	bnez	$s3,.L00018b14
/*    18b0c:	02139822 */ 	sub	$s3,$s0,$s3
/*    18b10:	20130000 */ 	addi	$s3,$zero,0x0
.L00018b14:
/*    18b14:	3273ffff */ 	andi	$s3,$s3,0xffff
/*    18b18:	3294ffff */ 	andi	$s4,$s4,0xffff
/*    18b1c:	95100002 */ 	lhu	$s0,0x2($t0)
/*    18b20:	10000006 */ 	b	.L00018b3c
/*    18b24:	951203c2 */ 	lhu	$s2,0x3c2($t0)
.L00018b28:
/*    18b28:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18b2c:	02e94020 */ 	add	$t0,$s7,$t1
/*    18b30:	951203c2 */ 	lhu	$s2,0x3c2($t0)
/*    18b34:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    18b38:	951403c6 */ 	lhu	$s4,0x3c6($t0)
.L00018b3c:
/*    18b3c:	0c006809 */ 	jal	func0001a024
/*    18b40:	afa807e8 */ 	sw	$t0,0x7e8($sp)
/*    18b44:	0c0067cb */ 	jal	func00019f2c
/*    18b48:	00000000 */ 	nop
/*    18b4c:	46000406 */ 	mov.s	$f16,$f0
/*    18b50:	46000c46 */ 	mov.s	$f17,$f1
/*    18b54:	46001486 */ 	mov.s	$f18,$f2
/*    18b58:	46001cc6 */ 	mov.s	$f19,$f3
/*    18b5c:	02405025 */ 	or	$t2,$s2,$zero
/*    18b60:	02605825 */ 	or	$t3,$s3,$zero
/*    18b64:	0c006809 */ 	jal	func0001a024
/*    18b68:	02806025 */ 	or	$t4,$s4,$zero
/*    18b6c:	0c0067cb */ 	jal	func00019f2c
/*    18b70:	00000000 */ 	nop
/*    18b74:	0c006777 */ 	jal	func00019ddc
/*    18b78:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    18b7c:	24080001 */ 	addiu	$t0,$zero,0x1
/*    18b80:	afa807e4 */ 	sw	$t0,0x7e4($sp)
/*    18b84:	8fa807e8 */ 	lw	$t0,0x7e8($sp)
/*    18b88:	e7a007e8 */ 	swc1	$f0,0x7e8($sp)
/*    18b8c:	e7a107ec */ 	swc1	$f1,0x7ec($sp)
/*    18b90:	e7a207f0 */ 	swc1	$f2,0x7f0($sp)
/*    18b94:	e7a307f4 */ 	swc1	$f3,0x7f4($sp)
/*    18b98:	0c006844 */ 	jal	func0001a110
/*    18b9c:	00000000 */ 	nop
/*    18ba0:	0800631b */ 	j	.L00018c6c
/*    18ba4:	00000000 */ 	nop
.L00018ba8:
/*    18ba8:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    18bac:	11400015 */ 	beqz	$t2,.L00018c04
/*    18bb0:	00000000 */ 	nop
/*    18bb4:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    18bb8:	00094840 */ 	sll	$t1,$t1,0x1
/*    18bbc:	01495020 */ 	add	$t2,$t2,$t1
/*    18bc0:	91490001 */ 	lbu	$t1,0x1($t2)
/*    18bc4:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18bc8:	02e94020 */ 	add	$t0,$s7,$t1
/*    18bcc:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18bd0:	3c0a0001 */ 	lui	$t2,0x1
/*    18bd4:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18bd8:	15800002 */ 	bnez	$t4,.L00018be4
/*    18bdc:	014c6022 */ 	sub	$t4,$t2,$t4
/*    18be0:	200c0000 */ 	addi	$t4,$zero,0x0
.L00018be4:
/*    18be4:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18be8:	15600002 */ 	bnez	$t3,.L00018bf4
/*    18bec:	014b5822 */ 	sub	$t3,$t2,$t3
/*    18bf0:	200b0000 */ 	addi	$t3,$zero,0x0
.L00018bf4:
/*    18bf4:	316bffff */ 	andi	$t3,$t3,0xffff
/*    18bf8:	318cffff */ 	andi	$t4,$t4,0xffff
/*    18bfc:	10000007 */ 	b	.L00018c1c
/*    18c00:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00018c04:
/*    18c04:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18c08:	02e94020 */ 	add	$t0,$s7,$t1
/*    18c0c:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18c10:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18c14:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18c18:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00018c1c:
/*    18c1c:	33cd0001 */ 	andi	$t5,$s8,0x1
/*    18c20:	15a0000b */ 	bnez	$t5,.L00018c50
/*    18c24:	000a8020 */ 	add	$s0,$zero,$t2
/*    18c28:	44806800 */ 	mtc1	$zero,$f13
/*    18c2c:	4600fb06 */ 	mov.s	$f12,$f31
/*    18c30:	4600fc06 */ 	mov.s	$f16,$f31
/*    18c34:	4600fd06 */ 	mov.s	$f20,$f31
/*    18c38:	46006b86 */ 	mov.s	$f14,$f13
/*    18c3c:	46006bc6 */ 	mov.s	$f15,$f13
/*    18c40:	46006c46 */ 	mov.s	$f17,$f13
/*    18c44:	46006c86 */ 	mov.s	$f18,$f13
/*    18c48:	0800631b */ 	j	.L00018c6c
/*    18c4c:	46006cc6 */ 	mov.s	$f19,$f13
.L00018c50:
/*    18c50:	000a8020 */ 	add	$s0,$zero,$t2
/*    18c54:	000b8820 */ 	add	$s1,$zero,$t3
/*    18c58:	000c9020 */ 	add	$s2,$zero,$t4
/*    18c5c:	0c0067e6 */ 	jal	func00019f98
/*    18c60:	00089820 */ 	add	$s3,$zero,$t0
/*    18c64:	0c00682b */ 	jal	func0001a0ac
/*    18c68:	00134020 */ 	add	$t0,$zero,$s3
.L00018c6c:
/*    18c6c:	33ca0002 */ 	andi	$t2,$s8,0x2
/*    18c70:	11400024 */ 	beqz	$t2,.L00018d04
/*    18c74:	00000000 */ 	nop
/*    18c78:	850a01e0 */ 	lh	$t2,0x1e0($t0)
/*    18c7c:	850b01e2 */ 	lh	$t3,0x1e2($t0)
/*    18c80:	850c01e4 */ 	lh	$t4,0x1e4($t0)
/*    18c84:	8ced0000 */ 	lw	$t5,0x0($a3)
/*    18c88:	15bc000d */ 	bne	$t5,$gp,.L00018cc0
/*    18c8c:	8f880004 */ 	lw	$t0,0x4($gp)
/*    18c90:	c4c00088 */ 	lwc1	$f0,0x88($a2)
/*    18c94:	448aa800 */ 	mtc1	$t2,$f21
/*    18c98:	448bb000 */ 	mtc1	$t3,$f22
/*    18c9c:	4680ad60 */ 	cvt.s.w	$f21,$f21
/*    18ca0:	4600ad42 */ 	mul.s	$f21,$f21,$f0
/*    18ca4:	448cb800 */ 	mtc1	$t4,$f23
/*    18ca8:	4680b5a0 */ 	cvt.s.w	$f22,$f22
/*    18cac:	4600b582 */ 	mul.s	$f22,$f22,$f0
/*    18cb0:	4680bde0 */ 	cvt.s.w	$f23,$f23
/*    18cb4:	4600bdc2 */ 	mul.s	$f23,$f23,$f0
/*    18cb8:	1000001c */ 	b	.L00018d2c
/*    18cbc:	00000000 */ 	nop
.L00018cc0:
/*    18cc0:	c4c30088 */ 	lwc1	$f3,0x88($a2)
/*    18cc4:	448a0000 */ 	mtc1	$t2,$f0
/*    18cc8:	448b0800 */ 	mtc1	$t3,$f1
/*    18ccc:	46800020 */ 	cvt.s.w	$f0,$f0
/*    18cd0:	46030002 */ 	mul.s	$f0,$f0,$f3
/*    18cd4:	448c1000 */ 	mtc1	$t4,$f2
/*    18cd8:	46800860 */ 	cvt.s.w	$f1,$f1
/*    18cdc:	46030842 */ 	mul.s	$f1,$f1,$f3
/*    18ce0:	468010a0 */ 	cvt.s.w	$f2,$f2
/*    18ce4:	46031082 */ 	mul.s	$f2,$f2,$f3
/*    18ce8:	c5150000 */ 	lwc1	$f21,0x0($t0)
/*    18cec:	c5160004 */ 	lwc1	$f22,0x4($t0)
/*    18cf0:	c5170008 */ 	lwc1	$f23,0x8($t0)
/*    18cf4:	4600ad40 */ 	add.s	$f21,$f21,$f0
/*    18cf8:	4601b580 */ 	add.s	$f22,$f22,$f1
/*    18cfc:	1000000b */ 	b	.L00018d2c
/*    18d00:	4602bdc0 */ 	add.s	$f23,$f23,$f2
.L00018d04:
/*    18d04:	8cea0000 */ 	lw	$t2,0x0($a3)
/*    18d08:	138a0005 */ 	beq	$gp,$t2,.L00018d20
/*    18d0c:	8f880004 */ 	lw	$t0,0x4($gp)
/*    18d10:	c5150000 */ 	lwc1	$f21,0x0($t0)
/*    18d14:	c5160004 */ 	lwc1	$f22,0x4($t0)
/*    18d18:	0800634b */ 	j	.L00018d2c
/*    18d1c:	c5170008 */ 	lwc1	$f23,0x8($t0)
.L00018d20:
/*    18d20:	4480a800 */ 	mtc1	$zero,$f21
/*    18d24:	4480b000 */ 	mtc1	$zero,$f22
/*    18d28:	4480b800 */ 	mtc1	$zero,$f23
.L00018d2c:
/*    18d2c:	8f880008 */ 	lw	$t0,0x8($gp)
/*    18d30:	11000005 */ 	beqz	$t0,.L00018d48
/*    18d34:	00000000 */ 	nop
/*    18d38:	0c006897 */ 	jal	func0001a25c
/*    18d3c:	00000000 */ 	nop
/*    18d40:	10000002 */ 	b	.L00018d4c
/*    18d44:	00000000 */ 	nop
.L00018d48:
/*    18d48:	8c880000 */ 	lw	$t0,0x0($a0)
.L00018d4c:
/*    18d4c:	8f890004 */ 	lw	$t1,0x4($gp)
/*    18d50:	952a000e */ 	lhu	$t2,0xe($t1)
/*    18d54:	000a5180 */ 	sll	$t2,$t2,0x6
/*    18d58:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    18d5c:	0c006870 */ 	jal	func0001a1c0
/*    18d60:	012a4820 */ 	add	$t1,$t1,$t2
/*    18d64:	3c0b8006 */ 	lui	$t3,%hi(var8005efcc)
/*    18d68:	256befcc */ 	addiu	$t3,$t3,%lo(var8005efcc)
/*    18d6c:	8d6b0000 */ 	lw	$t3,0x0($t3)
/*    18d70:	11600043 */ 	beqz	$t3,.L00018e80
/*    18d74:	00000000 */ 	nop
/*    18d78:	27bdff80 */ 	addiu	$sp,$sp,-128
/*    18d7c:	afbf0000 */ 	sw	$ra,0x0($sp)
/*    18d80:	afa10004 */ 	sw	$at,0x4($sp)
/*    18d84:	afa20008 */ 	sw	$v0,0x8($sp)
/*    18d88:	afa3000c */ 	sw	$v1,0xc($sp)
/*    18d8c:	afa40010 */ 	sw	$a0,0x10($sp)
/*    18d90:	afa50014 */ 	sw	$a1,0x14($sp)
/*    18d94:	afa60018 */ 	sw	$a2,0x18($sp)
/*    18d98:	afa7001c */ 	sw	$a3,0x1c($sp)
/*    18d9c:	afa80020 */ 	sw	$t0,0x20($sp)
/*    18da0:	afa90024 */ 	sw	$t1,0x24($sp)
/*    18da4:	afaa0028 */ 	sw	$t2,0x28($sp)
/*    18da8:	afab002c */ 	sw	$t3,0x2c($sp)
/*    18dac:	afac0030 */ 	sw	$t4,0x30($sp)
/*    18db0:	afad0034 */ 	sw	$t5,0x34($sp)
/*    18db4:	afae0038 */ 	sw	$t6,0x38($sp)
/*    18db8:	afaf003c */ 	sw	$t7,0x3c($sp)
/*    18dbc:	afb00040 */ 	sw	$s0,0x40($sp)
/*    18dc0:	afb10044 */ 	sw	$s1,0x44($sp)
/*    18dc4:	afb20048 */ 	sw	$s2,0x48($sp)
/*    18dc8:	afb3004c */ 	sw	$s3,0x4c($sp)
/*    18dcc:	afb40050 */ 	sw	$s4,0x50($sp)
/*    18dd0:	afb50054 */ 	sw	$s5,0x54($sp)
/*    18dd4:	afb60058 */ 	sw	$s6,0x58($sp)
/*    18dd8:	afb7005c */ 	sw	$s7,0x5c($sp)
/*    18ddc:	afb80060 */ 	sw	$t8,0x60($sp)
/*    18de0:	afb90064 */ 	sw	$t9,0x64($sp)
/*    18de4:	afbc0070 */ 	sw	$gp,0x70($sp)
/*    18de8:	afbd0074 */ 	sw	$sp,0x74($sp)
/*    18dec:	afbe0078 */ 	sw	$s8,0x78($sp)
/*    18df0:	8f890004 */ 	lw	$t1,0x4($gp)
/*    18df4:	9524000e */ 	lhu	$a0,0xe($t1)
/*    18df8:	00045180 */ 	sll	$t2,$a0,0x6
/*    18dfc:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    18e00:	0160f809 */ 	jalr	$t3
/*    18e04:	012a2820 */ 	add	$a1,$t1,$t2
/*    18e08:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*    18e0c:	8fa10004 */ 	lw	$at,0x4($sp)
/*    18e10:	8fa20008 */ 	lw	$v0,0x8($sp)
/*    18e14:	8fa3000c */ 	lw	$v1,0xc($sp)
/*    18e18:	8fa40010 */ 	lw	$a0,0x10($sp)
/*    18e1c:	8fa50014 */ 	lw	$a1,0x14($sp)
/*    18e20:	8fa60018 */ 	lw	$a2,0x18($sp)
/*    18e24:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*    18e28:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    18e2c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    18e30:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    18e34:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    18e38:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    18e3c:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    18e40:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    18e44:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    18e48:	8fb00040 */ 	lw	$s0,0x40($sp)
/*    18e4c:	8fb10044 */ 	lw	$s1,0x44($sp)
/*    18e50:	8fb20048 */ 	lw	$s2,0x48($sp)
/*    18e54:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*    18e58:	8fb40050 */ 	lw	$s4,0x50($sp)
/*    18e5c:	8fb50054 */ 	lw	$s5,0x54($sp)
/*    18e60:	8fb60058 */ 	lw	$s6,0x58($sp)
/*    18e64:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*    18e68:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    18e6c:	8fb90064 */ 	lw	$t9,0x64($sp)
/*    18e70:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*    18e74:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*    18e78:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*    18e7c:	27bd0080 */ 	addiu	$sp,$sp,0x80
.L00018e80:
/*    18e80:	878a0000 */ 	lh	$t2,0x0($gp)
/*    18e84:	314a0100 */ 	andi	$t2,$t2,0x100
/*    18e88:	114001ba */ 	beqz	$t2,.L00019574
/*    18e8c:	00000000 */ 	nop
/*    18e90:	8fa207e4 */ 	lw	$v0,0x7e4($sp)
/*    18e94:	10400006 */ 	beqz	$v0,.L00018eb0
/*    18e98:	2508fff4 */ 	addiu	$t0,$t0,-12
/*    18e9c:	c7a007e8 */ 	lwc1	$f0,0x7e8($sp)
/*    18ea0:	c7a107ec */ 	lwc1	$f1,0x7ec($sp)
/*    18ea4:	c7a207f0 */ 	lwc1	$f2,0x7f0($sp)
/*    18ea8:	080063b3 */ 	j	.L00018ecc
/*    18eac:	c7a307f4 */ 	lwc1	$f3,0x7f4($sp)
.L00018eb0:
/*    18eb0:	00105020 */ 	add	$t2,$zero,$s0
/*    18eb4:	00115820 */ 	add	$t3,$zero,$s1
/*    18eb8:	00126020 */ 	add	$t4,$zero,$s2
/*    18ebc:	0c006809 */ 	jal	func0001a024
/*    18ec0:	00088020 */ 	add	$s0,$zero,$t0
/*    18ec4:	0c0067cb */ 	jal	func00019f2c
/*    18ec8:	00104020 */ 	add	$t0,$zero,$s0
.L00018ecc:
/*    18ecc:	3c013f00 */ 	lui	$at,0x3f00
/*    18ed0:	44814000 */ 	mtc1	$at,$f8
/*    18ed4:	44802000 */ 	mtc1	$zero,$f4
/*    18ed8:	46000186 */ 	mov.s	$f6,$f0
/*    18edc:	3c017005 */ 	lui	$at,%hi(var70054210)
/*    18ee0:	c4274210 */ 	lwc1	$f7,%lo(var70054210)($at)
/*    18ee4:	4604303c */ 	c.lt.s	$f6,$f4
/*    18ee8:	45000003 */ 	bc1f	.L00018ef8
/*    18eec:	4600f946 */ 	mov.s	$f5,$f31
/*    18ef0:	46003187 */ 	neg.s	$f6,$f6
/*    18ef4:	46002947 */ 	neg.s	$f5,$f5
.L00018ef8:
/*    18ef8:	4607303c */ 	c.lt.s	$f6,$f7
/*    18efc:	3c017005 */ 	lui	$at,%hi(var70054214)
/*    18f00:	c4274214 */ 	lwc1	$f7,%lo(var70054214)($at)
/*    18f04:	4500000c */ 	bc1f	.L00018f38
/*    18f08:	00000000 */ 	nop
/*    18f0c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*    18f10:	00000000 */ 	nop
/*    18f14:	46082902 */ 	mul.s	$f4,$f5,$f8
/*    18f18:	00000000 */ 	nop
/*    18f1c:	46080842 */ 	mul.s	$f1,$f1,$f8
/*    18f20:	00000000 */ 	nop
/*    18f24:	46081082 */ 	mul.s	$f2,$f2,$f8
/*    18f28:	00000000 */ 	nop
/*    18f2c:	460818c2 */ 	mul.s	$f3,$f3,$f8
/*    18f30:	10000020 */ 	b	.L00018fb4
/*    18f34:	46040001 */ 	sub.s	$f0,$f0,$f4
.L00018f38:
/*    18f38:	4607303e */ 	c.le.s	$f6,$f7
/*    18f3c:	45000013 */ 	bc1f	.L00018f8c
/*    18f40:	00000000 */ 	nop
/*    18f44:	0c0068b7 */ 	jal	func0001a2dc
/*    18f48:	00000000 */ 	nop
/*    18f4c:	46000446 */ 	mov.s	$f17,$f0
/*    18f50:	46083302 */ 	mul.s	$f12,$f6,$f8
/*    18f54:	00088020 */ 	add	$s0,$zero,$t0
/*    18f58:	0c0068f7 */ 	jal	sinf
/*    18f5c:	00098820 */ 	add	$s1,$zero,$t1
/*    18f60:	460018c2 */ 	mul.s	$f3,$f3,$f0
/*    18f64:	00104020 */ 	add	$t0,$zero,$s0
/*    18f68:	46001082 */ 	mul.s	$f2,$f2,$f0
/*    18f6c:	00114820 */ 	add	$t1,$zero,$s1
/*    18f70:	46000842 */ 	mul.s	$f1,$f1,$f0
/*    18f74:	00000000 */ 	nop
/*    18f78:	46002942 */ 	mul.s	$f5,$f5,$f0
/*    18f7c:	00000000 */ 	nop
/*    18f80:	46110002 */ 	mul.s	$f0,$f0,$f17
/*    18f84:	1000000b */ 	b	.L00018fb4
/*    18f88:	46050000 */ 	add.s	$f0,$f0,$f5
.L00018f8c:
/*    18f8c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*    18f90:	00000000 */ 	nop
/*    18f94:	46082902 */ 	mul.s	$f4,$f5,$f8
/*    18f98:	00000000 */ 	nop
/*    18f9c:	46080842 */ 	mul.s	$f1,$f1,$f8
/*    18fa0:	00000000 */ 	nop
/*    18fa4:	46081082 */ 	mul.s	$f2,$f2,$f8
/*    18fa8:	00000000 */ 	nop
/*    18fac:	460818c2 */ 	mul.s	$f3,$f3,$f8
/*    18fb0:	46040000 */ 	add.s	$f0,$f0,$f4
.L00018fb4:
/*    18fb4:	0c006844 */ 	jal	func0001a110
/*    18fb8:	8f890004 */ 	lw	$t1,0x4($gp)
/*    18fbc:	952a0010 */ 	lhu	$t2,0x10($t1)
/*    18fc0:	000a5180 */ 	sll	$t2,$t2,0x6
/*    18fc4:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    18fc8:	0c006870 */ 	jal	func0001a1c0
/*    18fcc:	012a4820 */ 	add	$t1,$t1,$t2
/*    18fd0:	0800655d */ 	j	.L00019574
/*    18fd4:	00000000 */ 	nop
.L00018fd8:
/*    18fd8:	44806800 */ 	mtc1	$zero,$f13
/*    18fdc:	4600fb06 */ 	mov.s	$f12,$f31
/*    18fe0:	4600fc06 */ 	mov.s	$f16,$f31
/*    18fe4:	4600fd06 */ 	mov.s	$f20,$f31
/*    18fe8:	46006b86 */ 	mov.s	$f14,$f13
/*    18fec:	46006bc6 */ 	mov.s	$f15,$f13
/*    18ff0:	46006c46 */ 	mov.s	$f17,$f13
/*    18ff4:	46006c86 */ 	mov.s	$f18,$f13
/*    18ff8:	46006cc6 */ 	mov.s	$f19,$f13
/*    18ffc:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19000:	02e94020 */ 	add	$t0,$s7,$t1
/*    19004:	0800631b */ 	j	.L00018c6c
/*    19008:	951e0000 */ 	lhu	$s8,0x0($t0)
.L0001900c:
/*    1900c:	0000000c */ 	syscall
/*    19010:	0c006897 */ 	jal	func0001a25c
/*    19014:	001c4020 */ 	add	$t0,$zero,$gp
/*    19018:	3c0a8006 */ 	lui	$t2,%hi(g_ModelDistanceDisabled)
/*    1901c:	254aefb4 */ 	addiu	$t2,$t2,%lo(g_ModelDistanceDisabled)
/*    19020:	0c006747 */ 	jal	func00019d1c
/*    19024:	8f890004 */ 	lw	$t1,0x4($gp)
/*    19028:	8d4a0000 */ 	lw	$t2,0x0($t2)
/*    1902c:	1540000e */ 	bnez	$t2,.L00019068
/*    19030:	44800000 */ 	mtc1	$zero,$f0
/*    19034:	1100000c */ 	beqz	$t0,.L00019068
/*    19038:	44800000 */ 	mtc1	$zero,$f0
/*    1903c:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    19040:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    19044:	c5000038 */ 	lwc1	$f0,0x38($t0)
/*    19048:	8d4a0284 */ 	lw	$t2,0x284($t2)
/*    1904c:	46000007 */ 	neg.s	$f0,$f0
/*    19050:	c5411774 */ 	lwc1	$f1,0x1774($t2)
/*    19054:	46010002 */ 	mul.s	$f0,$f0,$f1
/*    19058:	3c088006 */ 	lui	$t0,%hi(g_ModelDistanceScale)
/*    1905c:	2508efb8 */ 	addiu	$t0,$t0,%lo(g_ModelDistanceScale)
/*    19060:	c5010000 */ 	lwc1	$f1,0x0($t0)
/*    19064:	46010002 */ 	mul.s	$f0,$f0,$f1
.L00019068:
/*    19068:	c5210000 */ 	lwc1	$f1,0x0($t1)
/*    1906c:	c4a20014 */ 	lwc1	$f2,0x14($a1)
/*    19070:	44802000 */ 	mtc1	$zero,$f4
/*    19074:	460208c2 */ 	mul.s	$f3,$f1,$f2
/*    19078:	46040832 */ 	c.eq.s	$f1,$f4
/*    1907c:	45010004 */ 	bc1t	.L00019090
/*    19080:	c5240004 */ 	lwc1	$f4,0x4($t1)
/*    19084:	4600183c */ 	c.lt.s	$f3,$f0
/*    19088:	45000009 */ 	bc1f	.L000190b0
/*    1908c:	00000000 */ 	nop
.L00019090:
/*    19090:	460220c2 */ 	mul.s	$f3,$f4,$f2
/*    19094:	4603003e */ 	c.le.s	$f0,$f3
/*    19098:	45000005 */ 	bc1f	.L000190b0
/*    1909c:	8d290008 */ 	lw	$t1,0x8($t1)
/*    190a0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    190a4:	ac480000 */ 	sw	$t0,0x0($v0)
/*    190a8:	0800655d */ 	j	.L00019574
/*    190ac:	af890014 */ 	sw	$t1,0x14($gp)
.L000190b0:
/*    190b0:	ac400000 */ 	sw	$zero,0x0($v0)
/*    190b4:	0800655d */ 	j	.L00019574
/*    190b8:	af800014 */ 	sw	$zero,0x14($gp)
/*    190bc:	10a000f8 */ 	beqz	$a1,.L000194a0
/*    190c0:	8f880004 */ 	lw	$t0,0x4($gp)
/*    190c4:	94ca0000 */ 	lhu	$t2,0x0($a2)
/*    190c8:	10c000e8 */ 	beqz	$a2,.L0001946c
/*    190cc:	95090000 */ 	lhu	$t1,0x0($t0)
/*    190d0:	4480e800 */ 	mtc1	$zero,$f29
/*    190d4:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    190d8:	461ee832 */ 	c.eq.s	$f29,$f30
/*    190dc:	45010050 */ 	bc1t	.L00019220
/*    190e0:	00000000 */ 	nop
/*    190e4:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    190e8:	11400015 */ 	beqz	$t2,.L00019140
/*    190ec:	00000000 */ 	nop
/*    190f0:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    190f4:	00094840 */ 	sll	$t1,$t1,0x1
/*    190f8:	01495020 */ 	add	$t2,$t2,$t1
/*    190fc:	91490001 */ 	lbu	$t1,0x1($t2)
/*    19100:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19104:	02e94020 */ 	add	$t0,$s7,$t1
/*    19108:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    1910c:	3c0a0001 */ 	lui	$t2,0x1
/*    19110:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19114:	15800002 */ 	bnez	$t4,.L00019120
/*    19118:	014c6022 */ 	sub	$t4,$t2,$t4
/*    1911c:	200c0000 */ 	addi	$t4,$zero,0x0
.L00019120:
/*    19120:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19124:	15600002 */ 	bnez	$t3,.L00019130
/*    19128:	014b5822 */ 	sub	$t3,$t2,$t3
/*    1912c:	200b0000 */ 	addi	$t3,$zero,0x0
.L00019130:
/*    19130:	316bffff */ 	andi	$t3,$t3,0xffff
/*    19134:	318cffff */ 	andi	$t4,$t4,0xffff
/*    19138:	08006456 */ 	j	.L00019158
/*    1913c:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00019140:
/*    19140:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19144:	02e94020 */ 	add	$t0,$s7,$t1
/*    19148:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    1914c:	950a0002 */ 	lhu	$t2,0x2($t0)
/*    19150:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19154:	950c0006 */ 	lhu	$t4,0x6($t0)
.L00019158:
/*    19158:	8f900004 */ 	lw	$s0,0x4($gp)
/*    1915c:	90d10009 */ 	lbu	$s1,0x9($a2)
/*    19160:	12200015 */ 	beqz	$s1,.L000191b8
/*    19164:	96090000 */ 	lhu	$t1,0x0($s0)
/*    19168:	8ed00004 */ 	lw	$s0,0x4($s6)
/*    1916c:	00094840 */ 	sll	$t1,$t1,0x1
/*    19170:	02098020 */ 	add	$s0,$s0,$t1
/*    19174:	92090001 */ 	lbu	$t1,0x1($s0)
/*    19178:	000948c0 */ 	sll	$t1,$t1,0x3
/*    1917c:	02e94020 */ 	add	$t0,$s7,$t1
/*    19180:	3c100001 */ 	lui	$s0,0x1
/*    19184:	951403c6 */ 	lhu	$s4,0x3c6($t0)
/*    19188:	16800002 */ 	bnez	$s4,.L00019194
/*    1918c:	0214a022 */ 	sub	$s4,$s0,$s4
/*    19190:	20140000 */ 	addi	$s4,$zero,0x0
.L00019194:
/*    19194:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    19198:	16600002 */ 	bnez	$s3,.L000191a4
/*    1919c:	02139822 */ 	sub	$s3,$s0,$s3
/*    191a0:	20130000 */ 	addi	$s3,$zero,0x0
.L000191a4:
/*    191a4:	3273ffff */ 	andi	$s3,$s3,0xffff
/*    191a8:	3294ffff */ 	andi	$s4,$s4,0xffff
/*    191ac:	95100002 */ 	lhu	$s0,0x2($t0)
/*    191b0:	10000006 */ 	b	.L000191cc
/*    191b4:	951203c2 */ 	lhu	$s2,0x3c2($t0)
.L000191b8:
/*    191b8:	000948c0 */ 	sll	$t1,$t1,0x3
/*    191bc:	02e94020 */ 	add	$t0,$s7,$t1
/*    191c0:	951203c2 */ 	lhu	$s2,0x3c2($t0)
/*    191c4:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    191c8:	951403c6 */ 	lhu	$s4,0x3c6($t0)
.L000191cc:
/*    191cc:	0c006809 */ 	jal	func0001a024
/*    191d0:	afa807e8 */ 	sw	$t0,0x7e8($sp)
/*    191d4:	0c0067cb */ 	jal	func00019f2c
/*    191d8:	00000000 */ 	nop
/*    191dc:	46000406 */ 	mov.s	$f16,$f0
/*    191e0:	46000c46 */ 	mov.s	$f17,$f1
/*    191e4:	46001486 */ 	mov.s	$f18,$f2
/*    191e8:	46001cc6 */ 	mov.s	$f19,$f3
/*    191ec:	02405025 */ 	or	$t2,$s2,$zero
/*    191f0:	02605825 */ 	or	$t3,$s3,$zero
/*    191f4:	0c006809 */ 	jal	func0001a024
/*    191f8:	02806025 */ 	or	$t4,$s4,$zero
/*    191fc:	0c0067cb */ 	jal	func00019f2c
/*    19200:	00000000 */ 	nop
/*    19204:	0c006777 */ 	jal	func00019ddc
/*    19208:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    1920c:	8fa807e8 */ 	lw	$t0,0x7e8($sp)
/*    19210:	0c006844 */ 	jal	func0001a110
/*    19214:	00000000 */ 	nop
/*    19218:	080064aa */ 	j	.L000192a8
/*    1921c:	00000000 */ 	nop
.L00019220:
/*    19220:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    19224:	11400017 */ 	beqz	$t2,.L00019284
/*    19228:	95090000 */ 	lhu	$t1,0x0($t0)
/*    1922c:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    19230:	00094840 */ 	sll	$t1,$t1,0x1
/*    19234:	01495020 */ 	add	$t2,$t2,$t1
/*    19238:	91490001 */ 	lbu	$t1,0x1($t2)
/*    1923c:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19240:	02e94020 */ 	add	$t0,$s7,$t1
/*    19244:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    19248:	3c0a0001 */ 	lui	$t2,0x1
/*    1924c:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19250:	15800002 */ 	bnez	$t4,.L0001925c
/*    19254:	014c6022 */ 	sub	$t4,$t2,$t4
/*    19258:	200c0000 */ 	addi	$t4,$zero,0x0
.L0001925c:
/*    1925c:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19260:	15600002 */ 	bnez	$t3,.L0001926c
/*    19264:	014b5822 */ 	sub	$t3,$t2,$t3
/*    19268:	200b0000 */ 	addi	$t3,$zero,0x0
.L0001926c:
/*    1926c:	316bffff */ 	andi	$t3,$t3,0xffff
/*    19270:	318cffff */ 	andi	$t4,$t4,0xffff
/*    19274:	0c0067e6 */ 	jal	func00019f98
/*    19278:	950a0002 */ 	lhu	$t2,0x2($t0)
/*    1927c:	10000008 */ 	b	.L000192a0
/*    19280:	00000000 */ 	nop
.L00019284:
/*    19284:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19288:	02e94020 */ 	add	$t0,$s7,$t1
/*    1928c:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    19290:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19294:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19298:	0c0067e6 */ 	jal	func00019f98
/*    1929c:	950a0002 */ 	lhu	$t2,0x2($t0)
.L000192a0:
/*    192a0:	0c00682b */ 	jal	func0001a0ac
/*    192a4:	00000000 */ 	nop
.L000192a8:
/*    192a8:	0c006747 */ 	jal	func00019d1c
/*    192ac:	44800000 */ 	mtc1	$zero,$f0
/*    192b0:	460066c6 */ 	mov.s	$f27,$f12
/*    192b4:	46006f06 */ 	mov.s	$f28,$f13
/*    192b8:	46007746 */ 	mov.s	$f29,$f14
/*    192bc:	46007f86 */ 	mov.s	$f30,$f15
/*    192c0:	c4410018 */ 	lwc1	$f1,0x18($v0)
/*    192c4:	46010032 */ 	c.eq.s	$f0,$f1
/*    192c8:	4501001c */ 	bc1t	.L0001933c
/*    192cc:	c44c0014 */ 	lwc1	$f12,0x14($v0)
/*    192d0:	c443001c */ 	lwc1	$f3,0x1c($v0)
/*    192d4:	3c017005 */ 	lui	$at,%hi(var70054218)
/*    192d8:	c4244218 */ 	lwc1	$f4,%lo(var70054218)($at)
/*    192dc:	460c1941 */ 	sub.s	$f5,$f3,$f12
/*    192e0:	3c017005 */ 	lui	$at,%hi(var7005421c)
/*    192e4:	c426421c */ 	lwc1	$f6,%lo(var7005421c)($at)
/*    192e8:	4600283c */ 	c.lt.s	$f5,$f0
/*    192ec:	45000002 */ 	bc1f	.L000192f8
/*    192f0:	00000000 */ 	nop
/*    192f4:	46062940 */ 	add.s	$f5,$f5,$f6
.L000192f8:
/*    192f8:	4604283c */ 	c.lt.s	$f5,$f4
/*    192fc:	45010008 */ 	bc1t	.L00019320
/*    19300:	00000000 */ 	nop
/*    19304:	46012942 */ 	mul.s	$f5,$f5,$f1
/*    19308:	46056300 */ 	add.s	$f12,$f12,$f5
/*    1930c:	4606603e */ 	c.le.s	$f12,$f6
/*    19310:	4501000a */ 	bc1t	.L0001933c
/*    19314:	00000000 */ 	nop
/*    19318:	080064cf */ 	j	.L0001933c
/*    1931c:	46066301 */ 	sub.s	$f12,$f12,$f6
.L00019320:
/*    19320:	46053141 */ 	sub.s	$f5,$f6,$f5
/*    19324:	46012942 */ 	mul.s	$f5,$f5,$f1
/*    19328:	46056301 */ 	sub.s	$f12,$f12,$f5
/*    1932c:	4600603c */ 	c.lt.s	$f12,$f0
/*    19330:	45000002 */ 	bc1f	.L0001933c
/*    19334:	00000000 */ 	nop
/*    19338:	46066300 */ 	add.s	$f12,$f12,$f6
.L0001933c:
/*    1933c:	3c017005 */ 	lui	$at,%hi(var70054220)
/*    19340:	c4214220 */ 	lwc1	$f1,%lo(var70054220)($at)
/*    19344:	0c0068f7 */ 	jal	sinf
/*    19348:	46016040 */ 	add.s	$f1,$f12,$f1
/*    1934c:	46000b06 */ 	mov.s	$f12,$f1
/*    19350:	0c0068f7 */ 	jal	sinf
/*    19354:	46000046 */ 	mov.s	$f1,$f0
/*    19358:	46000887 */ 	neg.s	$f2,$f1
/*    1935c:	4600db06 */ 	mov.s	$f12,$f27
/*    19360:	4600e346 */ 	mov.s	$f13,$f28
/*    19364:	4600eb86 */ 	mov.s	$f14,$f29
/*    19368:	4600f3c6 */ 	mov.s	$f15,$f30
/*    1936c:	c4550008 */ 	lwc1	$f21,0x8($v0)
/*    19370:	c456000c */ 	lwc1	$f22,0xc($v0)
/*    19374:	c4570010 */ 	lwc1	$f23,0x10($v0)
/*    19378:	460c00c2 */ 	mul.s	$f3,$f0,$f12
/*    1937c:	00000000 */ 	nop
/*    19380:	460e0902 */ 	mul.s	$f4,$f1,$f14
/*    19384:	00000000 */ 	nop
/*    19388:	460f0142 */ 	mul.s	$f5,$f0,$f15
/*    1938c:	460418c0 */ 	add.s	$f3,$f3,$f4
/*    19390:	46110982 */ 	mul.s	$f6,$f1,$f17
/*    19394:	00000000 */ 	nop
/*    19398:	461201c2 */ 	mul.s	$f7,$f0,$f18
/*    1939c:	46062940 */ 	add.s	$f5,$f5,$f6
/*    193a0:	46140a02 */ 	mul.s	$f8,$f1,$f20
/*    193a4:	00000000 */ 	nop
/*    193a8:	460c1242 */ 	mul.s	$f9,$f2,$f12
/*    193ac:	460839c0 */ 	add.s	$f7,$f7,$f8
/*    193b0:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*    193b4:	00000000 */ 	nop
/*    193b8:	460f1102 */ 	mul.s	$f4,$f2,$f15
/*    193bc:	460a4b80 */ 	add.s	$f14,$f9,$f10
/*    193c0:	46110182 */ 	mul.s	$f6,$f0,$f17
/*    193c4:	00000000 */ 	nop
/*    193c8:	46121202 */ 	mul.s	$f8,$f2,$f18
/*    193cc:	46062440 */ 	add.s	$f17,$f4,$f6
/*    193d0:	46140282 */ 	mul.s	$f10,$f0,$f20
/*    193d4:	46001b06 */ 	mov.s	$f12,$f3
/*    193d8:	460a4500 */ 	add.s	$f20,$f8,$f10
/*    193dc:	46002bc6 */ 	mov.s	$f15,$f5
/*    193e0:	46003c86 */ 	mov.s	$f18,$f7
/*    193e4:	c4a00014 */ 	lwc1	$f0,0x14($a1)
/*    193e8:	4600f832 */ 	c.eq.s	$f31,$f0
/*    193ec:	45010012 */ 	bc1t	.L00019438
/*    193f0:	00000000 */ 	nop
/*    193f4:	46006302 */ 	mul.s	$f12,$f12,$f0
/*    193f8:	00000000 */ 	nop
/*    193fc:	46006b42 */ 	mul.s	$f13,$f13,$f0
/*    19400:	00000000 */ 	nop
/*    19404:	46007382 */ 	mul.s	$f14,$f14,$f0
/*    19408:	00000000 */ 	nop
/*    1940c:	46007bc2 */ 	mul.s	$f15,$f15,$f0
/*    19410:	00000000 */ 	nop
/*    19414:	46008402 */ 	mul.s	$f16,$f16,$f0
/*    19418:	00000000 */ 	nop
/*    1941c:	46008c42 */ 	mul.s	$f17,$f17,$f0
/*    19420:	00000000 */ 	nop
/*    19424:	46009482 */ 	mul.s	$f18,$f18,$f0
/*    19428:	00000000 */ 	nop
/*    1942c:	46009cc2 */ 	mul.s	$f19,$f19,$f0
/*    19430:	00000000 */ 	nop
/*    19434:	4600a502 */ 	mul.s	$f20,$f20,$f0
.L00019438:
/*    19438:	8f880008 */ 	lw	$t0,0x8($gp)
/*    1943c:	11000002 */ 	beqz	$t0,.L00019448
/*    19440:	00000000 */ 	nop
/*    19444:	0000000c */ 	syscall
.L00019448:
/*    19448:	8f890004 */ 	lw	$t1,0x4($gp)
/*    1944c:	8c880000 */ 	lw	$t0,0x0($a0)
/*    19450:	952a0002 */ 	lhu	$t2,0x2($t1)
/*    19454:	000a5180 */ 	sll	$t2,$t2,0x6
/*    19458:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1945c:	0c006870 */ 	jal	func0001a1c0
/*    19460:	012a4820 */ 	add	$t1,$t1,$t2
/*    19464:	0800655d */ 	j	.L00019574
/*    19468:	00000000 */ 	nop
.L0001946c:
/*    1946c:	44806800 */ 	mtc1	$zero,$f13
/*    19470:	4600fb06 */ 	mov.s	$f12,$f31
/*    19474:	4600fc06 */ 	mov.s	$f16,$f31
/*    19478:	4600fd06 */ 	mov.s	$f20,$f31
/*    1947c:	46006b86 */ 	mov.s	$f14,$f13
/*    19480:	46006bc6 */ 	mov.s	$f15,$f13
/*    19484:	46006c46 */ 	mov.s	$f17,$f13
/*    19488:	46006c86 */ 	mov.s	$f18,$f13
/*    1948c:	46006cc6 */ 	mov.s	$f19,$f13
/*    19490:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19494:	02e94020 */ 	add	$t0,$s7,$t1
/*    19498:	080064aa */ 	j	.L000192a8
/*    1949c:	951e0000 */ 	lhu	$s8,0x0($t0)
.L000194a0:
/*    194a0:	0000000c */ 	syscall
/*    194a4:	0c006747 */ 	jal	func00019d1c
/*    194a8:	00000000 */ 	nop
/*    194ac:	8c490000 */ 	lw	$t1,0x0($v0)
/*    194b0:	11200030 */ 	beqz	$t1,.L00019574
/*    194b4:	00000000 */ 	nop
/*    194b8:	afbd07f8 */ 	sw	$sp,0x7f8($sp)
/*    194bc:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    194c0:	1140002c */ 	beqz	$t2,.L00019574
/*    194c4:	af8a0014 */ 	sw	$t2,0x14($gp)
.L000194c8:
/*    194c8:	ad5c0008 */ 	sw	$gp,0x8($t2)
/*    194cc:	8d4a000c */ 	lw	$t2,0xc($t2)
/*    194d0:	1540fffd */ 	bnez	$t2,.L000194c8
/*    194d4:	00000000 */ 	nop
/*    194d8:	0800655d */ 	j	.L00019574
/*    194dc:	00000000 */ 	nop
/*    194e0:	8f880008 */ 	lw	$t0,0x8($gp)
/*    194e4:	15000003 */ 	bnez	$t0,.L000194f4
/*    194e8:	00000000 */ 	nop
/*    194ec:	0800653f */ 	j	.L000194fc
/*    194f0:	8c880000 */ 	lw	$t0,0x0($a0)
.L000194f4:
/*    194f4:	0c006897 */ 	jal	func0001a25c
/*    194f8:	00000000 */ 	nop
.L000194fc:
/*    194fc:	8f890004 */ 	lw	$t1,0x4($gp)
/*    19500:	44806800 */ 	mtc1	$zero,$f13
/*    19504:	4600fb06 */ 	mov.s	$f12,$f31
/*    19508:	4600fc06 */ 	mov.s	$f16,$f31
/*    1950c:	4600fd06 */ 	mov.s	$f20,$f31
/*    19510:	46006b86 */ 	mov.s	$f14,$f13
/*    19514:	46006bc6 */ 	mov.s	$f15,$f13
/*    19518:	46006c46 */ 	mov.s	$f17,$f13
/*    1951c:	46006c86 */ 	mov.s	$f18,$f13
/*    19520:	46006cc6 */ 	mov.s	$f19,$f13
/*    19524:	c5350000 */ 	lwc1	$f21,0x0($t1)
/*    19528:	c5360004 */ 	lwc1	$f22,0x4($t1)
/*    1952c:	c5370008 */ 	lwc1	$f23,0x8($t1)
/*    19530:	952a000c */ 	lhu	$t2,0xc($t1)
/*    19534:	000a5180 */ 	sll	$t2,$t2,0x6
/*    19538:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1953c:	0c006870 */ 	jal	func0001a1c0
/*    19540:	012a4820 */ 	add	$t1,$t1,$t2
/*    19544:	0800655d */ 	j	.L00019574
/*    19548:	00000000 */ 	nop
/*    1954c:	0800655d */ 	j	.L00019574
/*    19550:	00000000 */ 	nop
/*    19554:	0c006747 */ 	jal	func00019d1c
/*    19558:	8f880004 */ 	lw	$t0,0x4($gp)
/*    1955c:	8c490000 */ 	lw	$t1,0x0($v0)
/*    19560:	11200003 */ 	beqz	$t1,.L00019570
/*    19564:	8d090000 */ 	lw	$t1,0x0($t0)
/*    19568:	0800655d */ 	j	.L00019574
/*    1956c:	af890014 */ 	sw	$t1,0x14($gp)
.L00019570:
/*    19570:	af800014 */ 	sw	$zero,0x14($gp)
.L00019574:
/*    19574:	8f880014 */ 	lw	$t0,0x14($gp)
/*    19578:	11000003 */ 	beqz	$t0,.L00019588
/*    1957c:	00000000 */ 	nop
/*    19580:	08006279 */ 	j	.L000189e4
/*    19584:	0008e020 */ 	add	$gp,$zero,$t0
.L00019588:
/*    19588:	8f88000c */ 	lw	$t0,0xc($gp)
/*    1958c:	11000003 */ 	beqz	$t0,.L0001959c
/*    19590:	00000000 */ 	nop
/*    19594:	08006279 */ 	j	.L000189e4
/*    19598:	0008e020 */ 	add	$gp,$zero,$t0
.L0001959c:
/*    1959c:	8f9c0008 */ 	lw	$gp,0x8($gp)
/*    195a0:	13800009 */ 	beqz	$gp,.L000195c8
/*    195a4:	00000000 */ 	nop
/*    195a8:	97880000 */ 	lhu	$t0,0x0($gp)
/*    195ac:	310800ff */ 	andi	$t0,$t0,0xff
/*    195b0:	24010017 */ 	addiu	$at,$zero,0x17
/*    195b4:	1501fff4 */ 	bne	$t0,$at,.L00019588
/*    195b8:	00000000 */ 	nop
/*    195bc:	afa807f8 */ 	sw	$t0,0x7f8($sp)
/*    195c0:	1780fff1 */ 	bnez	$gp,.L00019588
/*    195c4:	00000000 */ 	nop
.L000195c8:
/*    195c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L000195cc:
/*    195cc:	8fb00780 */ 	lw	$s0,0x780($sp)
/*    195d0:	8fb10784 */ 	lw	$s1,0x784($sp)
/*    195d4:	8fb20788 */ 	lw	$s2,0x788($sp)
/*    195d8:	8fb3078c */ 	lw	$s3,0x78c($sp)
/*    195dc:	8fb40790 */ 	lw	$s4,0x790($sp)
/*    195e0:	8fb50794 */ 	lw	$s5,0x794($sp)
/*    195e4:	8fb60798 */ 	lw	$s6,0x798($sp)
/*    195e8:	8fb7079c */ 	lw	$s7,0x79c($sp)
/*    195ec:	8fbe07a0 */ 	lw	$s8,0x7a0($sp)
/*    195f0:	8fbc07a4 */ 	lw	$gp,0x7a4($sp)
/*    195f4:	8fbf07a8 */ 	lw	$ra,0x7a8($sp)
/*    195f8:	c7b407b0 */ 	lwc1	$f20,0x7b0($sp)
/*    195fc:	c7b507b4 */ 	lwc1	$f21,0x7b4($sp)
/*    19600:	c7b607b8 */ 	lwc1	$f22,0x7b8($sp)
/*    19604:	c7b707bc */ 	lwc1	$f23,0x7bc($sp)
/*    19608:	c7b807c0 */ 	lwc1	$f24,0x7c0($sp)
/*    1960c:	c7b907c4 */ 	lwc1	$f25,0x7c4($sp)
/*    19610:	c7ba07c8 */ 	lwc1	$f26,0x7c8($sp)
/*    19614:	c7bb07cc */ 	lwc1	$f27,0x7cc($sp)
/*    19618:	c7bc07d0 */ 	lwc1	$f28,0x7d0($sp)
/*    1961c:	c7bd07d4 */ 	lwc1	$f29,0x7d4($sp)
/*    19620:	c7be07d8 */ 	lwc1	$f30,0x7d8($sp)
/*    19624:	c7bf07dc */ 	lwc1	$f31,0x7dc($sp)
/*    19628:	03e00008 */ 	jr	$ra
/*    1962c:	27bd0800 */ 	addiu	$sp,$sp,0x800
/*    19630:	0000000c */ 	syscall
);

GLOBAL_ASM(
glabel func00019634
/*    19634:	afbf07ac */ 	sw	$ra,0x7ac($sp)
.L00019638:
/*    19638:	914f0000 */ 	lbu	$t7,0x0($t2)
/*    1963c:	254a0001 */ 	addiu	$t2,$t2,0x1
/*    19640:	a50f0000 */ 	sh	$t7,0x0($t0)
/*    19644:	3418000f */ 	ori	$t8,$zero,0x0f
/*    19648:	030f082a */ 	slt	$at,$t8,$t7
/*    1964c:	1420ffdf */ 	bnez	$at,.L000195cc
/*    19650:	20020000 */ 	addi	$v0,$zero,0x0
/*    19654:	31f80002 */ 	andi	$t8,$t7,0x2
/*    19658:	1700001c */ 	bnez	$t8,.L000196cc
/*    1965c:	20100000 */ 	addi	$s0,$zero,0x0
/*    19660:	31f80008 */ 	andi	$t8,$t7,0x8
/*    19664:	20110000 */ 	addi	$s1,$zero,0x0
/*    19668:	13000067 */ 	beqz	$t8,.L00019808
/*    1966c:	20120000 */ 	addi	$s2,$zero,0x0
/*    19670:	91420002 */ 	lbu	$v0,0x2($t2)
/*    19674:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19678:	00431020 */ 	add	$v0,$v0,$v1
/*    1967c:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19680:	00431020 */ 	add	$v0,$v0,$v1
/*    19684:	9143000b */ 	lbu	$v1,0xb($t2)
/*    19688:	00431020 */ 	add	$v0,$v0,$v1
/*    1968c:	005c082a */ 	slt	$at,$v0,$gp
/*    19690:	1420000c */ 	bnez	$at,.L000196c4
/*    19694:	005c1022 */ 	sub	$v0,$v0,$gp
/*    19698:	201e0000 */ 	addi	$s8,$zero,0x0
/*    1969c:	0002c0c2 */ 	srl	$t8,$v0,0x3
/*    196a0:	01d87020 */ 	add	$t6,$t6,$t8
/*    196a4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    196a8:	00581022 */ 	sub	$v0,$v0,$t8
/*    196ac:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    196b0:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    196b4:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    196b8:	0382e022 */ 	sub	$gp,$gp,$v0
/*    196bc:	08006602 */ 	j	.L00019808
/*    196c0:	214a000c */ 	addi	$t2,$t2,0xc
.L000196c4:
/*    196c4:	08006602 */ 	j	.L00019808
/*    196c8:	214a000c */ 	addi	$t2,$t2,0xc
.L000196cc:
/*    196cc:	0c0066f8 */ 	jal	func00019be0
/*    196d0:	91430002 */ 	lbu	$v1,0x2($t2)
/*    196d4:	00028020 */ 	add	$s0,$zero,$v0
/*    196d8:	91430002 */ 	lbu	$v1,0x2($t2)
/*    196dc:	24130010 */ 	addiu	$s3,$zero,0x10
/*    196e0:	0073082a */ 	slt	$at,$v1,$s3
/*    196e4:	1020000c */ 	beqz	$at,.L00019718
/*    196e8:	24130001 */ 	addiu	$s3,$zero,0x1
/*    196ec:	2462ffff */ 	addiu	$v0,$v1,-1
/*    196f0:	00539804 */ 	sllv	$s3,$s3,$v0
/*    196f4:	0213a024 */ 	and	$s4,$s0,$s3
/*    196f8:	12800007 */ 	beqz	$s4,.L00019718
/*    196fc:	24140010 */ 	addiu	$s4,$zero,0x10
/*    19700:	0283a022 */ 	sub	$s4,$s4,$v1
/*    19704:	24020001 */ 	addiu	$v0,$zero,0x1
/*    19708:	02821004 */ 	sllv	$v0,$v0,$s4
/*    1970c:	2442ffff */ 	addiu	$v0,$v0,-1
/*    19710:	00621004 */ 	sllv	$v0,$v0,$v1
/*    19714:	02028025 */ 	or	$s0,$s0,$v0
.L00019718:
/*    19718:	91530000 */ 	lbu	$s3,0x0($t2)
/*    1971c:	00139a00 */ 	sll	$s3,$s3,0x8
/*    19720:	91540001 */ 	lbu	$s4,0x1($t2)
/*    19724:	02749821 */ 	addu	$s3,$s3,$s4
/*    19728:	02138021 */ 	addu	$s0,$s0,$s3
/*    1972c:	3210ffff */ 	andi	$s0,$s0,0xffff
/*    19730:	0c0066f8 */ 	jal	func00019be0
/*    19734:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19738:	00028820 */ 	add	$s1,$zero,$v0
/*    1973c:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19740:	24130010 */ 	addiu	$s3,$zero,0x10
/*    19744:	0073082a */ 	slt	$at,$v1,$s3
/*    19748:	1020000c */ 	beqz	$at,.L0001977c
/*    1974c:	24130001 */ 	addiu	$s3,$zero,0x1
/*    19750:	2462ffff */ 	addiu	$v0,$v1,-1
/*    19754:	00539804 */ 	sllv	$s3,$s3,$v0
/*    19758:	0233a024 */ 	and	$s4,$s1,$s3
/*    1975c:	12800007 */ 	beqz	$s4,.L0001977c
/*    19760:	24140010 */ 	addiu	$s4,$zero,0x10
/*    19764:	0283a022 */ 	sub	$s4,$s4,$v1
/*    19768:	24020001 */ 	addiu	$v0,$zero,0x1
/*    1976c:	02821004 */ 	sllv	$v0,$v0,$s4
/*    19770:	2442ffff */ 	addiu	$v0,$v0,-1
/*    19774:	00621004 */ 	sllv	$v0,$v0,$v1
/*    19778:	02228825 */ 	or	$s1,$s1,$v0
.L0001977c:
/*    1977c:	91530003 */ 	lbu	$s3,0x3($t2)
/*    19780:	00139a00 */ 	sll	$s3,$s3,0x8
/*    19784:	91540004 */ 	lbu	$s4,0x4($t2)
/*    19788:	02749821 */ 	addu	$s3,$s3,$s4
/*    1978c:	02338821 */ 	addu	$s1,$s1,$s3
/*    19790:	3231ffff */ 	andi	$s1,$s1,0xffff
/*    19794:	0c0066f8 */ 	jal	func00019be0
/*    19798:	91430008 */ 	lbu	$v1,0x8($t2)
/*    1979c:	00029020 */ 	add	$s2,$zero,$v0
/*    197a0:	91430008 */ 	lbu	$v1,0x8($t2)
/*    197a4:	24130010 */ 	addiu	$s3,$zero,0x10
/*    197a8:	0073082a */ 	slt	$at,$v1,$s3
/*    197ac:	1020000c */ 	beqz	$at,.L000197e0
/*    197b0:	24130001 */ 	addiu	$s3,$zero,0x1
/*    197b4:	2462ffff */ 	addiu	$v0,$v1,-1
/*    197b8:	00539804 */ 	sllv	$s3,$s3,$v0
/*    197bc:	0253a024 */ 	and	$s4,$s2,$s3
/*    197c0:	12800007 */ 	beqz	$s4,.L000197e0
/*    197c4:	24140010 */ 	addiu	$s4,$zero,0x10
/*    197c8:	0283a022 */ 	sub	$s4,$s4,$v1
/*    197cc:	24020001 */ 	addiu	$v0,$zero,0x1
/*    197d0:	02821004 */ 	sllv	$v0,$v0,$s4
/*    197d4:	2442ffff */ 	addiu	$v0,$v0,-1
/*    197d8:	00621004 */ 	sllv	$v0,$v0,$v1
/*    197dc:	02429025 */ 	or	$s2,$s2,$v0
.L000197e0:
/*    197e0:	91530006 */ 	lbu	$s3,0x6($t2)
/*    197e4:	00139a00 */ 	sll	$s3,$s3,0x8
/*    197e8:	91540007 */ 	lbu	$s4,0x7($t2)
/*    197ec:	02749821 */ 	addu	$s3,$s3,$s4
/*    197f0:	02539021 */ 	addu	$s2,$s2,$s3
/*    197f4:	3252ffff */ 	andi	$s2,$s2,0xffff
/*    197f8:	214a0009 */ 	addi	$t2,$t2,0x9
/*    197fc:	a51001e0 */ 	sh	$s0,0x1e0($t0)
/*    19800:	a51101e2 */ 	sh	$s1,0x1e2($t0)
/*    19804:	a51201e4 */ 	sh	$s2,0x1e4($t0)
.L00019808:
/*    19808:	31f80001 */ 	andi	$t8,$t7,0x1
/*    1980c:	17000004 */ 	bnez	$t8,.L00019820
/*    19810:	20100000 */ 	addi	$s0,$zero,0x0
/*    19814:	20110000 */ 	addi	$s1,$zero,0x0
/*    19818:	0800662d */ 	j	.L000198b4
/*    1981c:	20120000 */ 	addi	$s2,$zero,0x0
.L00019820:
/*    19820:	0c0066f8 */ 	jal	func00019be0
/*    19824:	91430002 */ 	lbu	$v1,0x2($t2)
/*    19828:	00028020 */ 	add	$s0,$zero,$v0
/*    1982c:	91430000 */ 	lbu	$v1,0x0($t2)
/*    19830:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19834:	91420001 */ 	lbu	$v0,0x1($t2)
/*    19838:	00621821 */ 	addu	$v1,$v1,$v0
/*    1983c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19840:	02038021 */ 	addu	$s0,$s0,$v1
/*    19844:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19848:	00508004 */ 	sllv	$s0,$s0,$v0
/*    1984c:	3210ffff */ 	andi	$s0,$s0,0xffff
/*    19850:	0c0066f8 */ 	jal	func00019be0
/*    19854:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19858:	00028820 */ 	add	$s1,$zero,$v0
/*    1985c:	91430003 */ 	lbu	$v1,0x3($t2)
/*    19860:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19864:	91420004 */ 	lbu	$v0,0x4($t2)
/*    19868:	00621821 */ 	addu	$v1,$v1,$v0
/*    1986c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19870:	02238821 */ 	addu	$s1,$s1,$v1
/*    19874:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19878:	00518804 */ 	sllv	$s1,$s1,$v0
/*    1987c:	3231ffff */ 	andi	$s1,$s1,0xffff
/*    19880:	0c0066f8 */ 	jal	func00019be0
/*    19884:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19888:	00029020 */ 	add	$s2,$zero,$v0
/*    1988c:	91430006 */ 	lbu	$v1,0x6($t2)
/*    19890:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19894:	91420007 */ 	lbu	$v0,0x7($t2)
/*    19898:	00621821 */ 	addu	$v1,$v1,$v0
/*    1989c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    198a0:	02439021 */ 	addu	$s2,$s2,$v1
/*    198a4:	004c1022 */ 	sub	$v0,$v0,$t4
/*    198a8:	00529004 */ 	sllv	$s2,$s2,$v0
/*    198ac:	3252ffff */ 	andi	$s2,$s2,0xffff
/*    198b0:	214a0009 */ 	addi	$t2,$t2,0x9
.L000198b4:
/*    198b4:	a5100002 */ 	sh	$s0,0x2($t0)
/*    198b8:	a5110004 */ 	sh	$s1,0x4($t0)
/*    198bc:	a5120006 */ 	sh	$s2,0x6($t0)
/*    198c0:	21080008 */ 	addi	$t0,$t0,0x8
/*    198c4:	014b082a */ 	slt	$at,$t2,$t3
/*    198c8:	1420ff5b */ 	bnez	$at,.L00019638
/*    198cc:	00000000 */ 	nop
/*    198d0:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    198d4:	03e00008 */ 	jr	$ra
/*    198d8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func000198dc
/*    198dc:	afbf07ac */ 	sw	$ra,0x7ac($sp)
.L000198e0:
/*    198e0:	914f0000 */ 	lbu	$t7,0x0($t2)
/*    198e4:	214a0001 */ 	addi	$t2,$t2,0x1
/*    198e8:	3418000f */ 	ori	$t8,$zero,0x0f
/*    198ec:	030f082a */ 	slt	$at,$t8,$t7
/*    198f0:	1420ff36 */ 	bnez	$at,.L000195cc
/*    198f4:	20020000 */ 	addi	$v0,$zero,0x0
/*    198f8:	31f80002 */ 	andi	$t8,$t7,0x2
/*    198fc:	1700001c */ 	bnez	$t8,.L00019970
/*    19900:	20100000 */ 	addi	$s0,$zero,0x0
/*    19904:	31f80008 */ 	andi	$t8,$t7,0x8
/*    19908:	20110000 */ 	addi	$s1,$zero,0x0
/*    1990c:	1300002a */ 	beqz	$t8,.L000199b8
/*    19910:	20120000 */ 	addi	$s2,$zero,0x0
/*    19914:	91420002 */ 	lbu	$v0,0x2($t2)
/*    19918:	91430005 */ 	lbu	$v1,0x5($t2)
/*    1991c:	00431020 */ 	add	$v0,$v0,$v1
/*    19920:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19924:	00431020 */ 	add	$v0,$v0,$v1
/*    19928:	9143000b */ 	lbu	$v1,0xb($t2)
/*    1992c:	00431020 */ 	add	$v0,$v0,$v1
/*    19930:	005c082a */ 	slt	$at,$v0,$gp
/*    19934:	1420000c */ 	bnez	$at,.L00019968
/*    19938:	005c1022 */ 	sub	$v0,$v0,$gp
/*    1993c:	201e0000 */ 	addi	$s8,$zero,0x0
/*    19940:	0002c0c2 */ 	srl	$t8,$v0,0x3
/*    19944:	01d87020 */ 	add	$t6,$t6,$t8
/*    19948:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    1994c:	00581022 */ 	sub	$v0,$v0,$t8
/*    19950:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    19954:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    19958:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    1995c:	0382e022 */ 	sub	$gp,$gp,$v0
/*    19960:	0800666e */ 	j	.L000199b8
/*    19964:	214a000c */ 	addi	$t2,$t2,0xc
.L00019968:
/*    19968:	0800666e */ 	j	.L000199b8
/*    1996c:	214a000c */ 	addi	$t2,$t2,0xc
.L00019970:
/*    19970:	91420002 */ 	lbu	$v0,0x2($t2)
/*    19974:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19978:	00431020 */ 	add	$v0,$v0,$v1
/*    1997c:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19980:	00431020 */ 	add	$v0,$v0,$v1
/*    19984:	005c082a */ 	slt	$at,$v0,$gp
/*    19988:	1420000a */ 	bnez	$at,.L000199b4
/*    1998c:	005c1022 */ 	sub	$v0,$v0,$gp
/*    19990:	201e0000 */ 	addi	$s8,$zero,0x0
/*    19994:	0002c0c2 */ 	srl	$t8,$v0,0x3
/*    19998:	01d87020 */ 	add	$t6,$t6,$t8
/*    1999c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    199a0:	00581022 */ 	sub	$v0,$v0,$t8
/*    199a4:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    199a8:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    199ac:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    199b0:	0382e022 */ 	sub	$gp,$gp,$v0
.L000199b4:
/*    199b4:	214a0009 */ 	addi	$t2,$t2,0x9
.L000199b8:
/*    199b8:	31f80001 */ 	andi	$t8,$t7,0x1
/*    199bc:	17000004 */ 	bnez	$t8,.L000199d0
/*    199c0:	20100000 */ 	addi	$s0,$zero,0x0
/*    199c4:	20110000 */ 	addi	$s1,$zero,0x0
/*    199c8:	08006699 */ 	j	.L00019a64
/*    199cc:	20120000 */ 	addi	$s2,$zero,0x0
.L000199d0:
/*    199d0:	0c0066f8 */ 	jal	func00019be0
/*    199d4:	91430002 */ 	lbu	$v1,0x2($t2)
/*    199d8:	00028020 */ 	add	$s0,$zero,$v0
/*    199dc:	91430000 */ 	lbu	$v1,0x0($t2)
/*    199e0:	00031a00 */ 	sll	$v1,$v1,0x8
/*    199e4:	91420001 */ 	lbu	$v0,0x1($t2)
/*    199e8:	00621821 */ 	addu	$v1,$v1,$v0
/*    199ec:	24020010 */ 	addiu	$v0,$zero,0x10
/*    199f0:	02038021 */ 	addu	$s0,$s0,$v1
/*    199f4:	004c1022 */ 	sub	$v0,$v0,$t4
/*    199f8:	00508004 */ 	sllv	$s0,$s0,$v0
/*    199fc:	3210ffff */ 	andi	$s0,$s0,0xffff
/*    19a00:	0c0066f8 */ 	jal	func00019be0
/*    19a04:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19a08:	00028820 */ 	add	$s1,$zero,$v0
/*    19a0c:	91430003 */ 	lbu	$v1,0x3($t2)
/*    19a10:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19a14:	91420004 */ 	lbu	$v0,0x4($t2)
/*    19a18:	00621821 */ 	addu	$v1,$v1,$v0
/*    19a1c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19a20:	02238821 */ 	addu	$s1,$s1,$v1
/*    19a24:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19a28:	00518804 */ 	sllv	$s1,$s1,$v0
/*    19a2c:	3231ffff */ 	andi	$s1,$s1,0xffff
/*    19a30:	0c0066f8 */ 	jal	func00019be0
/*    19a34:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19a38:	00029020 */ 	add	$s2,$zero,$v0
/*    19a3c:	91430006 */ 	lbu	$v1,0x6($t2)
/*    19a40:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19a44:	91420007 */ 	lbu	$v0,0x7($t2)
/*    19a48:	00621821 */ 	addu	$v1,$v1,$v0
/*    19a4c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19a50:	02439021 */ 	addu	$s2,$s2,$v1
/*    19a54:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19a58:	00529004 */ 	sllv	$s2,$s2,$v0
/*    19a5c:	3252ffff */ 	andi	$s2,$s2,0xffff
/*    19a60:	214a0009 */ 	addi	$t2,$t2,0x9
.L00019a64:
/*    19a64:	44130000 */ 	mfc1	$s3,$f0
/*    19a68:	3c030001 */ 	lui	$v1,0x1
/*    19a6c:	95140002 */ 	lhu	$s4,0x2($t0)
/*    19a70:	0214a822 */ 	sub	$s5,$s0,$s4
/*    19a74:	06a10002 */ 	bgez	$s5,.L00019a80
/*    19a78:	00000000 */ 	nop
/*    19a7c:	02a3a820 */ 	add	$s5,$s5,$v1
.L00019a80:
/*    19a80:	34018000 */ 	dli	$at,0x8000
/*    19a84:	02a1082a */ 	slt	$at,$s5,$at
/*    19a88:	1020000c */ 	beqz	$at,.L00019abc
/*    19a8c:	00000000 */ 	nop
/*    19a90:	02b30019 */ 	multu	$s5,$s3
/*    19a94:	0000a812 */ 	mflo	$s5
/*    19a98:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19a9c:	02958020 */ 	add	$s0,$s4,$s5
/*    19aa0:	3c010001 */ 	lui	$at,0x1
/*    19aa4:	0201082a */ 	slt	$at,$s0,$at
/*    19aa8:	1420000c */ 	bnez	$at,.L00019adc
/*    19aac:	00000000 */ 	nop
/*    19ab0:	3c140001 */ 	lui	$s4,0x1
/*    19ab4:	080066b7 */ 	j	.L00019adc
/*    19ab8:	02148022 */ 	sub	$s0,$s0,$s4
.L00019abc:
/*    19abc:	0075a822 */ 	sub	$s5,$v1,$s5
/*    19ac0:	02b30019 */ 	multu	$s5,$s3
/*    19ac4:	0000a812 */ 	mflo	$s5
/*    19ac8:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19acc:	02958022 */ 	sub	$s0,$s4,$s5
/*    19ad0:	06010002 */ 	bgez	$s0,.L00019adc
/*    19ad4:	00000000 */ 	nop
/*    19ad8:	02038020 */ 	add	$s0,$s0,$v1
.L00019adc:
/*    19adc:	95140004 */ 	lhu	$s4,0x4($t0)
/*    19ae0:	0234a822 */ 	sub	$s5,$s1,$s4
/*    19ae4:	06a10002 */ 	bgez	$s5,.L00019af0
/*    19ae8:	00000000 */ 	nop
/*    19aec:	02a3a820 */ 	add	$s5,$s5,$v1
.L00019af0:
/*    19af0:	34018000 */ 	dli	$at,0x8000
/*    19af4:	02a1082a */ 	slt	$at,$s5,$at
/*    19af8:	1020000b */ 	beqz	$at,.L00019b28
/*    19afc:	00000000 */ 	nop
/*    19b00:	02b30019 */ 	multu	$s5,$s3
/*    19b04:	0000a812 */ 	mflo	$s5
/*    19b08:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19b0c:	02958820 */ 	add	$s1,$s4,$s5
/*    19b10:	3c010001 */ 	lui	$at,0x1
/*    19b14:	0221082a */ 	slt	$at,$s1,$at
/*    19b18:	1420000b */ 	bnez	$at,.L00019b48
/*    19b1c:	00000000 */ 	nop
/*    19b20:	080066d2 */ 	j	.L00019b48
/*    19b24:	02238822 */ 	sub	$s1,$s1,$v1
.L00019b28:
/*    19b28:	0075a822 */ 	sub	$s5,$v1,$s5
/*    19b2c:	02b30019 */ 	multu	$s5,$s3
/*    19b30:	0000a812 */ 	mflo	$s5
/*    19b34:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19b38:	02958822 */ 	sub	$s1,$s4,$s5
/*    19b3c:	06210002 */ 	bgez	$s1,.L00019b48
/*    19b40:	00000000 */ 	nop
/*    19b44:	02238820 */ 	add	$s1,$s1,$v1
.L00019b48:
/*    19b48:	95140006 */ 	lhu	$s4,0x6($t0)
/*    19b4c:	0254a822 */ 	sub	$s5,$s2,$s4
/*    19b50:	06a10002 */ 	bgez	$s5,.L00019b5c
/*    19b54:	00000000 */ 	nop
/*    19b58:	02a3a820 */ 	add	$s5,$s5,$v1
.L00019b5c:
/*    19b5c:	34018000 */ 	dli	$at,0x8000
/*    19b60:	02a1082a */ 	slt	$at,$s5,$at
/*    19b64:	1020000b */ 	beqz	$at,.L00019b94
/*    19b68:	00000000 */ 	nop
/*    19b6c:	02b30019 */ 	multu	$s5,$s3
/*    19b70:	0000a812 */ 	mflo	$s5
/*    19b74:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19b78:	02959020 */ 	add	$s2,$s4,$s5
/*    19b7c:	3c010001 */ 	lui	$at,0x1
/*    19b80:	0241082a */ 	slt	$at,$s2,$at
/*    19b84:	1420000c */ 	bnez	$at,.L00019bb8
/*    19b88:	00000000 */ 	nop
/*    19b8c:	080066ee */ 	j	.L00019bb8
/*    19b90:	02439022 */ 	sub	$s2,$s2,$v1
.L00019b94:
/*    19b94:	0075a822 */ 	sub	$s5,$v1,$s5
/*    19b98:	02b30019 */ 	multu	$s5,$s3
/*    19b9c:	0000a812 */ 	mflo	$s5
/*    19ba0:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19ba4:	02959022 */ 	sub	$s2,$s4,$s5
/*    19ba8:	06410003 */ 	bgez	$s2,.L00019bb8
/*    19bac:	00000000 */ 	nop
/*    19bb0:	3c140001 */ 	lui	$s4,0x1
/*    19bb4:	02549020 */ 	add	$s2,$s2,$s4
.L00019bb8:
/*    19bb8:	a5100002 */ 	sh	$s0,0x2($t0)
/*    19bbc:	a5110004 */ 	sh	$s1,0x4($t0)
/*    19bc0:	a5120006 */ 	sh	$s2,0x6($t0)
/*    19bc4:	21080008 */ 	addi	$t0,$t0,0x8
/*    19bc8:	014b082a */ 	slt	$at,$t2,$t3
/*    19bcc:	1420ff44 */ 	bnez	$at,.L000198e0
/*    19bd0:	00000000 */ 	nop
/*    19bd4:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    19bd8:	03e00008 */ 	jr	$ra
/*    19bdc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00019be0
/*    19be0:	1060004c */ 	beqz	$v1,.L00019d14
/*    19be4:	20020000 */ 	addi	$v0,$zero,0x0
.L00019be8:
/*    19be8:	0383082a */ 	slt	$at,$gp,$v1
/*    19bec:	10200041 */ 	beqz	$at,.L00019cf4
/*    19bf0:	00000000 */ 	nop
/*    19bf4:	007c1822 */ 	sub	$v1,$v1,$gp
/*    19bf8:	20160001 */ 	addi	$s6,$zero,0x1
/*    19bfc:	0396b004 */ 	sllv	$s6,$s6,$gp
/*    19c00:	22d6ffff */ 	addi	$s6,$s6,-1
/*    19c04:	03d6b024 */ 	and	$s6,$s8,$s6
/*    19c08:	0076b004 */ 	sllv	$s6,$s6,$v1
/*    19c0c:	00561025 */ 	or	$v0,$v0,$s6
/*    19c10:	016eb022 */ 	sub	$s6,$t3,$t6
/*    19c14:	2ac10004 */ 	slti	$at,$s6,0x4
/*    19c18:	14200002 */ 	bnez	$at,.L00019c24
/*    19c1c:	00000000 */ 	nop
/*    19c20:	24160004 */ 	addiu	$s6,$zero,0x4
.L00019c24:
/*    19c24:	31de0003 */ 	andi	$s8,$t6,0x3
/*    19c28:	27defffc */ 	addiu	$s8,$s8,-4
/*    19c2c:	001ef022 */ 	neg	$s8,$s8
/*    19c30:	13c00005 */ 	beqz	$s8,.L00019c48
/*    19c34:	00000000 */ 	nop
/*    19c38:	03d6082a */ 	slt	$at,$s8,$s6
/*    19c3c:	10200002 */ 	beqz	$at,.L00019c48
/*    19c40:	00000000 */ 	nop
/*    19c44:	03c0b025 */ 	or	$s6,$s8,$zero
.L00019c48:
/*    19c48:	3c1e8006 */ 	lui	$s8,%hi(var8005ef7c)
/*    19c4c:	27deef7c */ 	addiu	$s8,$s8,%lo(var8005ef7c)
/*    19c50:	0016b080 */ 	sll	$s6,$s6,0x2
/*    19c54:	03d6b020 */ 	add	$s6,$s8,$s6
/*    19c58:	8ed60000 */ 	lw	$s6,0x0($s6)
/*    19c5c:	02c00008 */ 	jr	$s6
/*    19c60:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    19c64:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    19c68:	080066fa */ 	j	.L00019be8
/*    19c6c:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    19c70:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19c74:	91d60001 */ 	lbu	$s6,0x1($t6)
/*    19c78:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19c7c:	25ce0002 */ 	addiu	$t6,$t6,0x2
/*    19c80:	080066fa */ 	j	.L00019be8
/*    19c84:	241c0010 */ 	addiu	$gp,$zero,0x10
/*    19c88:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19c8c:	91d60001 */ 	lbu	$s6,0x1($t6)
/*    19c90:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19c94:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19c98:	91d60002 */ 	lbu	$s6,0x2($t6)
/*    19c9c:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19ca0:	25ce0003 */ 	addiu	$t6,$t6,0x3
/*    19ca4:	080066fa */ 	j	.L00019be8
/*    19ca8:	241c0018 */ 	addiu	$gp,$zero,0x18
/*    19cac:	31d60003 */ 	andi	$s6,$t6,0x3
/*    19cb0:	12c0000c */ 	beqz	$s6,.L00019ce4
/*    19cb4:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19cb8:	91d60001 */ 	lbu	$s6,0x1($t6)
/*    19cbc:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19cc0:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19cc4:	91d60002 */ 	lbu	$s6,0x2($t6)
/*    19cc8:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19ccc:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19cd0:	91d60003 */ 	lbu	$s6,0x3($t6)
/*    19cd4:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19cd8:	25ce0004 */ 	addiu	$t6,$t6,0x4
/*    19cdc:	080066fa */ 	j	.L00019be8
/*    19ce0:	241c0020 */ 	addiu	$gp,$zero,0x20
.L00019ce4:
/*    19ce4:	8dde0000 */ 	lw	$s8,0x0($t6)
/*    19ce8:	25ce0004 */ 	addiu	$t6,$t6,0x4
/*    19cec:	080066fa */ 	j	.L00019be8
/*    19cf0:	241c0020 */ 	addiu	$gp,$zero,0x20
.L00019cf4:
/*    19cf4:	10600007 */ 	beqz	$v1,.L00019d14
/*    19cf8:	0383e022 */ 	sub	$gp,$gp,$v1
/*    19cfc:	039eb007 */ 	srav	$s6,$s8,$gp
/*    19d00:	20170001 */ 	addi	$s7,$zero,0x1
/*    19d04:	0077b804 */ 	sllv	$s7,$s7,$v1
/*    19d08:	22f7ffff */ 	addi	$s7,$s7,-1
/*    19d0c:	02d7b024 */ 	and	$s6,$s6,$s7
/*    19d10:	00561025 */ 	or	$v0,$v0,$s6
.L00019d14:
/*    19d14:	03e00008 */ 	jr	$ra
/*    19d18:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00019d1c
/*    19d1c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    19d20:	afbc0000 */ 	sw	$gp,0x0($sp)
/*    19d24:	afa80004 */ 	sw	$t0,0x4($sp)
/*    19d28:	afa90008 */ 	sw	$t1,0x8($sp)
/*    19d2c:	afaa000c */ 	sw	$t2,0xc($sp)
/*    19d30:	afab0010 */ 	sw	$t3,0x10($sp)
/*    19d34:	afac0014 */ 	sw	$t4,0x14($sp)
/*    19d38:	afbf0018 */ 	sw	$ra,0x18($sp)
/*    19d3c:	8f8c0004 */ 	lw	$t4,0x4($gp)
/*    19d40:	3c0a8006 */ 	lui	$t2,%hi(var8005ef90)
/*    19d44:	254aef90 */ 	addiu	$t2,$t2,%lo(var8005ef90)
/*    19d48:	97890000 */ 	lhu	$t1,0x0($gp)
/*    19d4c:	312900ff */ 	andi	$t1,$t1,0xff
/*    19d50:	00004025 */ 	or	$t0,$zero,$zero
/*    19d54:	2921001a */ 	slti	$at,$t1,0x1a
/*    19d58:	10200007 */ 	beqz	$at,.L00019d78
/*    19d5c:	8cab0010 */ 	lw	$t3,0x10($a1)
/*    19d60:	01495020 */ 	add	$t2,$t2,$t1
/*    19d64:	914a0000 */ 	lbu	$t2,0x0($t2)
/*    19d68:	240100ff */ 	addiu	$at,$zero,0xff
/*    19d6c:	11410002 */ 	beq	$t2,$at,.L00019d78
/*    19d70:	018a5020 */ 	add	$t2,$t4,$t2
/*    19d74:	95480000 */ 	lhu	$t0,0x0($t2)
.L00019d78:
/*    19d78:	8fa90818 */ 	lw	$t1,0x818($sp)
/*    19d7c:	1120000c */ 	beqz	$t1,.L00019db0
/*    19d80:	00000000 */ 	nop
.L00019d84:
/*    19d84:	8f890008 */ 	lw	$t1,0x8($gp)
/*    19d88:	11200009 */ 	beqz	$t1,.L00019db0
/*    19d8c:	0120e025 */ 	or	$gp,$t1,$zero
/*    19d90:	97890000 */ 	lhu	$t1,0x0($gp)
/*    19d94:	312900ff */ 	andi	$t1,$t1,0xff
/*    19d98:	24010017 */ 	addiu	$at,$zero,0x17
/*    19d9c:	1521fff9 */ 	bne	$t1,$at,.L00019d84
/*    19da0:	00000000 */ 	nop
/*    19da4:	0c006747 */ 	jal	func00019d1c
/*    19da8:	00000000 */ 	nop
/*    19dac:	8c4b0004 */ 	lw	$t3,0x4($v0)
.L00019db0:
/*    19db0:	00084080 */ 	sll	$t0,$t0,0x2
/*    19db4:	01681020 */ 	add	$v0,$t3,$t0
/*    19db8:	8fbc0000 */ 	lw	$gp,0x0($sp)
/*    19dbc:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    19dc0:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    19dc4:	8faa000c */ 	lw	$t2,0xc($sp)
/*    19dc8:	8fab0010 */ 	lw	$t3,0x10($sp)
/*    19dcc:	8fac0014 */ 	lw	$t4,0x14($sp)
/*    19dd0:	8fbf0018 */ 	lw	$ra,0x18($sp)
/*    19dd4:	03e00008 */ 	jr	$ra
/*    19dd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel modelGetNodeRwData
/*    1aeac:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    1aeb0:	afa80000 */ 	sw	$t0,0x0($sp)
/*    1aeb4:	afa90004 */ 	sw	$t1,0x4($sp)
/*    1aeb8:	afab0008 */ 	sw	$t3,0x8($sp)
/*    1aebc:	afbf000c */ 	sw	$ra,0xc($sp)
/*    1aec0:	8cac0004 */ 	lw	$t4,0x4($a1)
/*    1aec4:	3c0a8006 */ 	lui	$t2,0x8006
/*    1aec8:	254a1360 */ 	addiu	$t2,$t2,0x1360
/*    1aecc:	94a90000 */ 	lhu	$t1,0x0($a1)
/*    1aed0:	312900ff */ 	andi	$t1,$t1,0xff
/*    1aed4:	00004025 */ 	or	$t0,$zero,$zero
/*    1aed8:	2921001a */ 	slti	$at,$t1,0x1a
/*    1aedc:	10200007 */ 	beqz	$at,.NB0001aefc
/*    1aee0:	8c8b0010 */ 	lw	$t3,0x10($a0)
/*    1aee4:	01495020 */ 	add	$t2,$t2,$t1
/*    1aee8:	914a0000 */ 	lbu	$t2,0x0($t2)
/*    1aeec:	240100ff */ 	addiu	$at,$zero,0xff
/*    1aef0:	11410002 */ 	beq	$t2,$at,.NB0001aefc
/*    1aef4:	018a5020 */ 	add	$t2,$t4,$t2
/*    1aef8:	95480000 */ 	lhu	$t0,0x0($t2)
.NB0001aefc:
/*    1aefc:	90890000 */ 	lbu	$t1,0x0($a0)
/*    1af00:	1120000c */ 	beqz	$t1,.NB0001af34
/*    1af04:	00000000 */ 	sll	$zero,$zero,0x0
.NB0001af08:
/*    1af08:	8ca90008 */ 	lw	$t1,0x8($a1)
/*    1af0c:	11200009 */ 	beqz	$t1,.NB0001af34
/*    1af10:	01202825 */ 	or	$a1,$t1,$zero
/*    1af14:	94a90000 */ 	lhu	$t1,0x0($a1)
/*    1af18:	312900ff */ 	andi	$t1,$t1,0xff
/*    1af1c:	24010017 */ 	addiu	$at,$zero,0x17
/*    1af20:	1521fff9 */ 	bne	$t1,$at,.NB0001af08
/*    1af24:	00000000 */ 	sll	$zero,$zero,0x0
/*    1af28:	0c006bab */ 	jal	modelGetNodeRwData
/*    1af2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    1af30:	8c4b0004 */ 	lw	$t3,0x4($v0)
.NB0001af34:
/*    1af34:	00084080 */ 	sll	$t0,$t0,0x2
/*    1af38:	01681020 */ 	add	$v0,$t3,$t0
/*    1af3c:	8fa80000 */ 	lw	$t0,0x0($sp)
/*    1af40:	8fa90004 */ 	lw	$t1,0x4($sp)
/*    1af44:	8fab0008 */ 	lw	$t3,0x8($sp)
/*    1af48:	8fbf000c */ 	lw	$ra,0xc($sp)
/*    1af4c:	03e00008 */ 	jr	$ra
/*    1af50:	27bd0010 */ 	addiu	$sp,$sp,0x10
);
#endif

GLOBAL_ASM(
glabel func00019ddc
/*    19ddc:	afbf07ac */ 	sw	$ra,0x7ac($sp)
.L00019de0:
/*    19de0:	46008142 */ 	mul.s	$f5,$f16,$f0
/*    19de4:	44802000 */ 	mtc1	$zero,$f4
/*    19de8:	46018982 */ 	mul.s	$f6,$f17,$f1
/*    19dec:	00000000 */ 	nop
/*    19df0:	460291c2 */ 	mul.s	$f7,$f18,$f2
/*    19df4:	46062980 */ 	add.s	$f6,$f5,$f6
/*    19df8:	46039942 */ 	mul.s	$f5,$f19,$f3
/*    19dfc:	46073180 */ 	add.s	$f6,$f6,$f7
/*    19e00:	46053180 */ 	add.s	$f6,$f6,$f5
/*    19e04:	4604303c */ 	c.lt.s	$f6,$f4
/*    19e08:	45020006 */ 	bc1fl	.L00019e24
/*    19e0c:	00000000 */ 	nop
/*    19e10:	46000007 */ 	neg.s	$f0,$f0
/*    19e14:	46000847 */ 	neg.s	$f1,$f1
/*    19e18:	46001087 */ 	neg.s	$f2,$f2
/*    19e1c:	08006778 */ 	j	.L00019de0
/*    19e20:	460018c7 */ 	neg.s	$f3,$f3
.L00019e24:
/*    19e24:	3c017005 */ 	lui	$at,%hi(var70054224)
/*    19e28:	c4274224 */ 	lwc1	$f7,%lo(var70054224)($at)
/*    19e2c:	4607303c */ 	c.lt.s	$f6,$f7
/*    19e30:	45020013 */ 	bc1fl	.L00019e80
/*    19e34:	00000000 */ 	nop
/*    19e38:	4610f182 */ 	mul.s	$f6,$f30,$f16
/*    19e3c:	461e2941 */ 	sub.s	$f5,$f5,$f30
/*    19e40:	460029c2 */ 	mul.s	$f7,$f5,$f0
/*    19e44:	46063801 */ 	sub.s	$f0,$f7,$f6
/*    19e48:	4611f182 */ 	mul.s	$f6,$f30,$f17
/*    19e4c:	00000000 */ 	nop
/*    19e50:	460129c2 */ 	mul.s	$f7,$f5,$f1
/*    19e54:	00000000 */ 	nop
/*    19e58:	4612f202 */ 	mul.s	$f8,$f30,$f18
/*    19e5c:	46063841 */ 	sub.s	$f1,$f7,$f6
/*    19e60:	46022a42 */ 	mul.s	$f9,$f5,$f2
/*    19e64:	00000000 */ 	nop
/*    19e68:	4613f182 */ 	mul.s	$f6,$f30,$f19
/*    19e6c:	46084881 */ 	sub.s	$f2,$f9,$f8
/*    19e70:	460329c2 */ 	mul.s	$f7,$f5,$f3
/*    19e74:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    19e78:	03e00008 */ 	jr	$ra
/*    19e7c:	46063881 */ 	sub.s	$f2,$f7,$f6
.L00019e80:
/*    19e80:	3c017005 */ 	lui	$at,%hi(var70054228)
/*    19e84:	c4274228 */ 	lwc1	$f7,%lo(var70054228)($at)
/*    19e88:	4607303e */ 	c.le.s	$f6,$f7
/*    19e8c:	45000024 */ 	bc1f	.L00019f20
/*    19e90:	00000000 */ 	nop
/*    19e94:	0c0068b7 */ 	jal	func0001a2dc
/*    19e98:	00000000 */ 	nop
/*    19e9c:	46000506 */ 	mov.s	$f20,$f0
/*    19ea0:	0c0068f7 */ 	jal	sinf
/*    19ea4:	46003b06 */ 	mov.s	$f12,$f7
/*    19ea8:	4600fb06 */ 	mov.s	$f12,$f31
/*    19eac:	461e6301 */ 	sub.s	$f12,$f12,$f30
/*    19eb0:	46076302 */ 	mul.s	$f12,$f12,$f7
/*    19eb4:	0c0068f7 */ 	jal	sinf
/*    19eb8:	46000546 */ 	mov.s	$f21,$f0
/*    19ebc:	461e3b02 */ 	mul.s	$f12,$f7,$f30
/*    19ec0:	0c0068f7 */ 	jal	sinf
/*    19ec4:	46000586 */ 	mov.s	$f22,$f0
/*    19ec8:	4615b143 */ 	div.s	$f5,$f22,$f21
/*    19ecc:	00000000 */ 	nop
/*    19ed0:	46150783 */ 	div.s	$f30,$f0,$f21
/*    19ed4:	4600a006 */ 	mov.s	$f0,$f20
.L00019ed8:
/*    19ed8:	46102982 */ 	mul.s	$f6,$f5,$f16
/*    19edc:	00000000 */ 	nop
/*    19ee0:	4600f1c2 */ 	mul.s	$f7,$f30,$f0
/*    19ee4:	00000000 */ 	nop
/*    19ee8:	46112a02 */ 	mul.s	$f8,$f5,$f17
/*    19eec:	46073000 */ 	add.s	$f0,$f6,$f7
/*    19ef0:	4601f242 */ 	mul.s	$f9,$f30,$f1
/*    19ef4:	00000000 */ 	nop
/*    19ef8:	46122982 */ 	mul.s	$f6,$f5,$f18
/*    19efc:	46094040 */ 	add.s	$f1,$f8,$f9
/*    19f00:	4602f1c2 */ 	mul.s	$f7,$f30,$f2
/*    19f04:	00000000 */ 	nop
/*    19f08:	46132a02 */ 	mul.s	$f8,$f5,$f19
/*    19f0c:	46073080 */ 	add.s	$f2,$f6,$f7
/*    19f10:	4603f242 */ 	mul.s	$f9,$f30,$f3
/*    19f14:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    19f18:	03e00008 */ 	jr	$ra
/*    19f1c:	460940c0 */ 	add.s	$f3,$f8,$f9
.L00019f20:
/*    19f20:	4600f946 */ 	mov.s	$f5,$f31
/*    19f24:	080067b6 */ 	j	.L00019ed8
/*    19f28:	461e2941 */ 	sub.s	$f5,$f5,$f30
);

GLOBAL_ASM(
glabel func00019f2c
/*    19f2c:	46020182 */ 	mul.s	$f6,$f0,$f2
/*    19f30:	00000000 */ 	nop
/*    19f34:	460301c2 */ 	mul.s	$f7,$f0,$f3
/*    19f38:	00000000 */ 	nop
/*    19f3c:	46020a02 */ 	mul.s	$f8,$f1,$f2
/*    19f40:	00000000 */ 	nop
/*    19f44:	46030a42 */ 	mul.s	$f9,$f1,$f3
/*    19f48:	00000000 */ 	nop
/*    19f4c:	46043002 */ 	mul.s	$f0,$f6,$f4
/*    19f50:	00000000 */ 	nop
/*    19f54:	46054842 */ 	mul.s	$f1,$f9,$f5
/*    19f58:	00000000 */ 	nop
/*    19f5c:	46044082 */ 	mul.s	$f2,$f8,$f4
/*    19f60:	46010000 */ 	add.s	$f0,$f0,$f1
/*    19f64:	46053842 */ 	mul.s	$f1,$f7,$f5
/*    19f68:	00000000 */ 	nop
/*    19f6c:	460538c2 */ 	mul.s	$f3,$f7,$f5
/*    19f70:	00000000 */ 	nop
/*    19f74:	46043a82 */ 	mul.s	$f10,$f7,$f4
/*    19f78:	46011041 */ 	sub.s	$f1,$f2,$f1
/*    19f7c:	460542c2 */ 	mul.s	$f11,$f8,$f5
/*    19f80:	00000000 */ 	nop
/*    19f84:	46053682 */ 	mul.s	$f26,$f6,$f5
/*    19f88:	460b5080 */ 	add.s	$f2,$f10,$f11
/*    19f8c:	46044a82 */ 	mul.s	$f10,$f9,$f4
/*    19f90:	03e00008 */ 	jr	$ra
/*    19f94:	460ad0c1 */ 	sub.s	$f3,$f26,$f10
);

GLOBAL_ASM(
glabel func00019f98
/*    19f98:	001f6820 */ 	add	$t5,$zero,$ra
/*    19f9c:	3c017005 */ 	lui	$at,%hi(var7005422c)
/*    19fa0:	c43d422c */ 	lwc1	$f29,%lo(var7005422c)($at)
/*    19fa4:	448c4000 */ 	mtc1	$t4,$f8
/*    19fa8:	448b3800 */ 	mtc1	$t3,$f7
/*    19fac:	448a3000 */ 	mtc1	$t2,$f6
/*    19fb0:	46804220 */ 	cvt.s.w	$f8,$f8
/*    19fb4:	468039e0 */ 	cvt.s.w	$f7,$f7
/*    19fb8:	468031a0 */ 	cvt.s.w	$f6,$f6
/*    19fbc:	461d4202 */ 	mul.s	$f8,$f8,$f29
/*    19fc0:	3c017005 */ 	lui	$at,%hi(var70054230)
/*    19fc4:	c43e4230 */ 	lwc1	$f30,%lo(var70054230)($at)
/*    19fc8:	461d39c2 */ 	mul.s	$f7,$f7,$f29
/*    19fcc:	46004306 */ 	mov.s	$f12,$f8
/*    19fd0:	0c0068f7 */ 	jal	sinf
/*    19fd4:	00000000 */ 	nop
/*    19fd8:	461d3182 */ 	mul.s	$f6,$f6,$f29
/*    19fdc:	461e4300 */ 	add.s	$f12,$f8,$f30
/*    19fe0:	0c0068f7 */ 	jal	sinf
/*    19fe4:	46000146 */ 	mov.s	$f5,$f0
/*    19fe8:	46003b06 */ 	mov.s	$f12,$f7
/*    19fec:	0c0068f7 */ 	jal	sinf
/*    19ff0:	46000106 */ 	mov.s	$f4,$f0
/*    19ff4:	461e3b00 */ 	add.s	$f12,$f7,$f30
/*    19ff8:	0c0068f7 */ 	jal	sinf
/*    19ffc:	460000c6 */ 	mov.s	$f3,$f0
/*    1a000:	46003306 */ 	mov.s	$f12,$f6
/*    1a004:	0c0068f7 */ 	jal	sinf
/*    1a008:	46000086 */ 	mov.s	$f2,$f0
/*    1a00c:	461e3300 */ 	add.s	$f12,$f6,$f30
/*    1a010:	0c0068f7 */ 	jal	sinf
/*    1a014:	46000046 */ 	mov.s	$f1,$f0
/*    1a018:	000df820 */ 	add	$ra,$zero,$t5
/*    1a01c:	03e00008 */ 	jr	$ra
/*    1a020:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001a024
/*    1a024:	001f6820 */ 	add	$t5,$zero,$ra
/*    1a028:	3c017005 */ 	lui	$at,%hi(var70054234)
/*    1a02c:	c43d4234 */ 	lwc1	$f29,%lo(var70054234)($at)
/*    1a030:	448c4000 */ 	mtc1	$t4,$f8
/*    1a034:	448b3800 */ 	mtc1	$t3,$f7
/*    1a038:	448a3000 */ 	mtc1	$t2,$f6
/*    1a03c:	46804220 */ 	cvt.s.w	$f8,$f8
/*    1a040:	468039e0 */ 	cvt.s.w	$f7,$f7
/*    1a044:	468031a0 */ 	cvt.s.w	$f6,$f6
/*    1a048:	461d4202 */ 	mul.s	$f8,$f8,$f29
/*    1a04c:	3c017005 */ 	lui	$at,%hi(var70054238)
/*    1a050:	c43e4238 */ 	lwc1	$f30,%lo(var70054238)($at)
/*    1a054:	461d39c2 */ 	mul.s	$f7,$f7,$f29
/*    1a058:	0c0068f7 */ 	jal	sinf
/*    1a05c:	46004306 */ 	mov.s	$f12,$f8
/*    1a060:	461d3182 */ 	mul.s	$f6,$f6,$f29
/*    1a064:	461e4300 */ 	add.s	$f12,$f8,$f30
/*    1a068:	0c0068f7 */ 	jal	sinf
/*    1a06c:	46000146 */ 	mov.s	$f5,$f0
/*    1a070:	46003b06 */ 	mov.s	$f12,$f7
/*    1a074:	0c0068f7 */ 	jal	sinf
/*    1a078:	46000106 */ 	mov.s	$f4,$f0
/*    1a07c:	461e3b00 */ 	add.s	$f12,$f7,$f30
/*    1a080:	0c0068f7 */ 	jal	sinf
/*    1a084:	460000c6 */ 	mov.s	$f3,$f0
/*    1a088:	46003306 */ 	mov.s	$f12,$f6
/*    1a08c:	0c0068f7 */ 	jal	sinf
/*    1a090:	46000086 */ 	mov.s	$f2,$f0
/*    1a094:	461e3300 */ 	add.s	$f12,$f6,$f30
/*    1a098:	0c0068f7 */ 	jal	sinf
/*    1a09c:	46000046 */ 	mov.s	$f1,$f0
/*    1a0a0:	000df820 */ 	add	$ra,$zero,$t5
/*    1a0a4:	03e00008 */ 	jr	$ra
/*    1a0a8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0001a0ac
/*    1a0ac:	46050982 */ 	mul.s	$f6,$f1,$f5
/*    1a0b0:	00000000 */ 	nop
/*    1a0b4:	460501c2 */ 	mul.s	$f7,$f0,$f5
/*    1a0b8:	00000000 */ 	nop
/*    1a0bc:	46040a02 */ 	mul.s	$f8,$f1,$f4
/*    1a0c0:	00000000 */ 	nop
/*    1a0c4:	46040242 */ 	mul.s	$f9,$f0,$f4
/*    1a0c8:	00000000 */ 	nop
/*    1a0cc:	46041302 */ 	mul.s	$f12,$f2,$f4
/*    1a0d0:	46001b87 */ 	neg.s	$f14,$f3
/*    1a0d4:	46051342 */ 	mul.s	$f13,$f2,$f5
/*    1a0d8:	00000000 */ 	nop
/*    1a0dc:	460343c2 */ 	mul.s	$f15,$f8,$f3
/*    1a0e0:	00000000 */ 	nop
/*    1a0e4:	46033402 */ 	mul.s	$f16,$f6,$f3
/*    1a0e8:	46077bc1 */ 	sub.s	$f15,$f15,$f7
/*    1a0ec:	46020c42 */ 	mul.s	$f17,$f1,$f2
/*    1a0f0:	46098400 */ 	add.s	$f16,$f16,$f9
/*    1a0f4:	46034c82 */ 	mul.s	$f18,$f9,$f3
/*    1a0f8:	00000000 */ 	nop
/*    1a0fc:	46033cc2 */ 	mul.s	$f19,$f7,$f3
/*    1a100:	46069480 */ 	add.s	$f18,$f18,$f6
/*    1a104:	46020502 */ 	mul.s	$f20,$f0,$f2
/*    1a108:	03e00008 */ 	jr	$ra
/*    1a10c:	46089cc1 */ 	sub.s	$f19,$f19,$f8
);

GLOBAL_ASM(
glabel func0001a110
/*    1a110:	46000102 */ 	mul.s	$f4,$f0,$f0
/*    1a114:	00000000 */ 	nop
/*    1a118:	46010942 */ 	mul.s	$f5,$f1,$f1
/*    1a11c:	00000000 */ 	nop
/*    1a120:	46021182 */ 	mul.s	$f6,$f2,$f2
/*    1a124:	46052100 */ 	add.s	$f4,$f4,$f5
/*    1a128:	46031942 */ 	mul.s	$f5,$f3,$f3
/*    1a12c:	46062100 */ 	add.s	$f4,$f4,$f6
/*    1a130:	3c014000 */ 	lui	$at,0x4000
/*    1a134:	44813000 */ 	mtc1	$at,$f6
/*    1a138:	46052100 */ 	add.s	$f4,$f4,$f5
/*    1a13c:	46043103 */ 	div.s	$f4,$f6,$f4
/*    1a140:	46040942 */ 	mul.s	$f5,$f1,$f4
/*    1a144:	00000000 */ 	nop
/*    1a148:	46041182 */ 	mul.s	$f6,$f2,$f4
/*    1a14c:	00000000 */ 	nop
/*    1a150:	460419c2 */ 	mul.s	$f7,$f3,$f4
/*    1a154:	00000000 */ 	nop
/*    1a158:	46050202 */ 	mul.s	$f8,$f0,$f5
/*    1a15c:	00000000 */ 	nop
/*    1a160:	46060242 */ 	mul.s	$f9,$f0,$f6
/*    1a164:	00000000 */ 	nop
/*    1a168:	46070282 */ 	mul.s	$f10,$f0,$f7
/*    1a16c:	00000000 */ 	nop
/*    1a170:	46050ac2 */ 	mul.s	$f11,$f1,$f5
/*    1a174:	00000000 */ 	nop
/*    1a178:	46060e02 */ 	mul.s	$f24,$f1,$f6
/*    1a17c:	460bfc01 */ 	sub.s	$f16,$f31,$f11
/*    1a180:	46070e42 */ 	mul.s	$f25,$f1,$f7
/*    1a184:	460bfd01 */ 	sub.s	$f20,$f31,$f11
/*    1a188:	46061682 */ 	mul.s	$f26,$f2,$f6
/*    1a18c:	460ac340 */ 	add.s	$f13,$f24,$f10
/*    1a190:	460716c2 */ 	mul.s	$f27,$f2,$f7
/*    1a194:	461afb01 */ 	sub.s	$f12,$f31,$f26
/*    1a198:	46071f02 */ 	mul.s	$f28,$f3,$f7
/*    1a19c:	4609cb81 */ 	sub.s	$f14,$f25,$f9
/*    1a1a0:	461c6301 */ 	sub.s	$f12,$f12,$f28
/*    1a1a4:	460ac3c1 */ 	sub.s	$f15,$f24,$f10
/*    1a1a8:	461c8401 */ 	sub.s	$f16,$f16,$f28
/*    1a1ac:	4608dc40 */ 	add.s	$f17,$f27,$f8
/*    1a1b0:	4609cc80 */ 	add.s	$f18,$f25,$f9
/*    1a1b4:	4608dcc1 */ 	sub.s	$f19,$f27,$f8
/*    1a1b8:	03e00008 */ 	jr	$ra
/*    1a1bc:	461aa501 */ 	sub.s	$f20,$f20,$f26
);

GLOBAL_ASM(
glabel func0001a1c0
/*    1a1c0:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0001a1c4:
/*    1a1c4:	c5000000 */ 	lwc1	$f0,0x0($t0)
/*    1a1c8:	25080004 */ 	addiu	$t0,$t0,0x4
/*    1a1cc:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*    1a1d0:	c501000c */ 	lwc1	$f1,0xc($t0)
/*    1a1d4:	c502001c */ 	lwc1	$f2,0x1c($t0)
/*    1a1d8:	460d0942 */ 	mul.s	$f5,$f1,$f13
/*    1a1dc:	c503002c */ 	lwc1	$f3,0x2c($t0)
/*    1a1e0:	460e1182 */ 	mul.s	$f6,$f2,$f14
/*    1a1e4:	460521c0 */ 	add.s	$f7,$f4,$f5
/*    1a1e8:	460f0202 */ 	mul.s	$f8,$f0,$f15
/*    1a1ec:	460639c0 */ 	add.s	$f7,$f7,$f6
/*    1a1f0:	46100a42 */ 	mul.s	$f9,$f1,$f16
/*    1a1f4:	e5270000 */ 	swc1	$f7,0x0($t1)
/*    1a1f8:	46111282 */ 	mul.s	$f10,$f2,$f17
/*    1a1fc:	460942c0 */ 	add.s	$f11,$f8,$f9
/*    1a200:	46120102 */ 	mul.s	$f4,$f0,$f18
/*    1a204:	460a5ac0 */ 	add.s	$f11,$f11,$f10
/*    1a208:	46130942 */ 	mul.s	$f5,$f1,$f19
/*    1a20c:	e52b0010 */ 	swc1	$f11,0x10($t1)
/*    1a210:	46141182 */ 	mul.s	$f6,$f2,$f20
/*    1a214:	460521c0 */ 	add.s	$f7,$f4,$f5
/*    1a218:	46150202 */ 	mul.s	$f8,$f0,$f21
/*    1a21c:	460639c0 */ 	add.s	$f7,$f7,$f6
/*    1a220:	46160a42 */ 	mul.s	$f9,$f1,$f22
/*    1a224:	e5270020 */ 	swc1	$f7,0x20($t1)
/*    1a228:	46171282 */ 	mul.s	$f10,$f2,$f23
/*    1a22c:	46094200 */ 	add.s	$f8,$f8,$f9
/*    1a230:	46035280 */ 	add.s	$f10,$f10,$f3
/*    1a234:	254affff */ 	addiu	$t2,$t2,-1
/*    1a238:	460a4280 */ 	add.s	$f10,$f8,$f10
/*    1a23c:	25290004 */ 	addiu	$t1,$t1,0x4
/*    1a240:	1540ffe0 */ 	bnez	$t2,.L0001a1c4
/*    1a244:	e52a002c */ 	swc1	$f10,0x2c($t1)
/*    1a248:	ad200000 */ 	sw	$zero,0x0($t1)
/*    1a24c:	ad200010 */ 	sw	$zero,0x10($t1)
/*    1a250:	ad200020 */ 	sw	$zero,0x20($t1)
/*    1a254:	03e00008 */ 	jr	$ra
/*    1a258:	e53f0030 */ 	swc1	$f31,0x30($t1)
);

GLOBAL_ASM(
glabel func0001a25c
.L0001a25c:
/*    1a25c:	85090000 */ 	lh	$t1,0x0($t0)
/*    1a260:	312900ff */ 	andi	$t1,$t1,0xff
/*    1a264:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    1a268:	152a0007 */ 	bne	$t1,$t2,.L0001a288
/*    1a26c:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    1a270:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    1a274:	954a0002 */ 	lhu	$t2,0x2($t2)
/*    1a278:	000a5180 */ 	sll	$t2,$t2,0x6
/*    1a27c:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1a280:	03e00008 */ 	jr	$ra
/*    1a284:	012a4020 */ 	add	$t0,$t1,$t2
.L0001a288:
/*    1a288:	152a0007 */ 	bne	$t1,$t2,.L0001a2a8
/*    1a28c:	240a0015 */ 	addiu	$t2,$zero,0x15
/*    1a290:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    1a294:	954a000e */ 	lhu	$t2,0xe($t2)
/*    1a298:	000a5180 */ 	sll	$t2,$t2,0x6
/*    1a29c:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1a2a0:	03e00008 */ 	jr	$ra
/*    1a2a4:	012a4020 */ 	add	$t0,$t1,$t2
.L0001a2a8:
/*    1a2a8:	152a0007 */ 	bne	$t1,$t2,.L0001a2c8
/*    1a2ac:	00000000 */ 	nop
/*    1a2b0:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    1a2b4:	954a000c */ 	lhu	$t2,0xc($t2)
/*    1a2b8:	000a5180 */ 	sll	$t2,$t2,0x6
/*    1a2bc:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1a2c0:	03e00008 */ 	jr	$ra
/*    1a2c4:	012a4020 */ 	add	$t0,$t1,$t2
.L0001a2c8:
/*    1a2c8:	8d080008 */ 	lw	$t0,0x8($t0)
/*    1a2cc:	1500ffe3 */ 	bnez	$t0,.L0001a25c
/*    1a2d0:	00000000 */ 	nop
/*    1a2d4:	03e00008 */ 	jr	$ra
/*    1a2d8:	00004020 */ 	add	$t0,$zero,$zero
);

GLOBAL_ASM(
glabel func0001a2dc
/*    1a2dc:	3c017005 */ 	lui	$at,%hi(var7005423c)
/*    1a2e0:	c427423c */ 	lwc1	$f7,%lo(var7005423c)($at)
/*    1a2e4:	460731c2 */ 	mul.s	$f7,$f6,$f7
/*    1a2e8:	460039cd */ 	trunc.w.s	$f7,$f7
/*    1a2ec:	440a3800 */ 	mfc1	$t2,$f7
/*    1a2f0:	00000000 */ 	nop
/*    1a2f4:	29417fff */ 	slti	$at,$t2,0x7fff
/*    1a2f8:	14200003 */ 	bnez	$at,.L0001a308
/*    1a2fc:	00000000 */ 	nop
/*    1a300:	10000005 */ 	b	.L0001a318
/*    1a304:	240a7fff */ 	addiu	$t2,$zero,0x7fff
.L0001a308:
/*    1a308:	29418001 */ 	slti	$at,$t2,-32767
/*    1a30c:	10200002 */ 	beqz	$at,.L0001a318
/*    1a310:	00000000 */ 	nop
/*    1a314:	240a8001 */ 	addiu	$t2,$zero,-32767
.L0001a318:
/*    1a318:	05410002 */ 	bgez	$t2,.L0001a324
/*    1a31c:	000a5820 */ 	add	$t3,$zero,$t2
/*    1a320:	000b5822 */ 	neg	$t3,$t3
.L0001a324:
/*    1a324:	29617fe0 */ 	slti	$at,$t3,0x7fe0
/*    1a328:	14200007 */ 	bnez	$at,.L0001a348
/*    1a32c:	00000000 */ 	nop
/*    1a330:	3c0c8007 */ 	lui	$t4,%hi(var8006af8c)
/*    1a334:	258caf8c */ 	addiu	$t4,$t4,%lo(var8006af8c)
/*    1a338:	216b8020 */ 	addi	$t3,$t3,-32736
/*    1a33c:	240d0003 */ 	addiu	$t5,$zero,0x3
/*    1a340:	1000000e */ 	b	.L0001a37c
/*    1a344:	240e0007 */ 	addiu	$t6,$zero,0x7
.L0001a348:
/*    1a348:	29617800 */ 	slti	$at,$t3,0x7800
/*    1a34c:	14200007 */ 	bnez	$at,.L0001a36c
/*    1a350:	00000000 */ 	nop
/*    1a354:	3c0c8007 */ 	lui	$t4,%hi(var8006af0c)
/*    1a358:	258caf0c */ 	addiu	$t4,$t4,%lo(var8006af0c)
/*    1a35c:	216b8800 */ 	addi	$t3,$t3,-30720
/*    1a360:	240d0005 */ 	addiu	$t5,$zero,0x5
/*    1a364:	10000005 */ 	b	.L0001a37c
/*    1a368:	240e001f */ 	addiu	$t6,$zero,0x1f
.L0001a36c:
/*    1a36c:	3c0c8007 */ 	lui	$t4,%hi(var8006ae90)
/*    1a370:	258cae90 */ 	addiu	$t4,$t4,%lo(var8006ae90)
/*    1a374:	240d0009 */ 	addiu	$t5,$zero,0x9
/*    1a378:	240e01ff */ 	addiu	$t6,$zero,0x1ff
.L0001a37c:
/*    1a37c:	01ab8007 */ 	srav	$s0,$t3,$t5
/*    1a380:	00108040 */ 	sll	$s0,$s0,0x1
/*    1a384:	01906020 */ 	add	$t4,$t4,$s0
/*    1a388:	95910000 */ 	lhu	$s1,0x0($t4)
/*    1a38c:	95920002 */ 	lhu	$s2,0x2($t4)
/*    1a390:	02329822 */ 	sub	$s3,$s1,$s2
/*    1a394:	016ea024 */ 	and	$s4,$t3,$t6
/*    1a398:	02740019 */ 	multu	$s3,$s4
/*    1a39c:	00009812 */ 	mflo	$s3
/*    1a3a0:	01b39807 */ 	srav	$s3,$s3,$t5
/*    1a3a4:	02335822 */ 	sub	$t3,$s1,$s3
/*    1a3a8:	05410002 */ 	bgez	$t2,.L0001a3b4
/*    1a3ac:	340affff */ 	dli	$t2,0xffff
/*    1a3b0:	014b5822 */ 	sub	$t3,$t2,$t3
.L0001a3b4:
/*    1a3b4:	448b4000 */ 	mtc1	$t3,$f8
/*    1a3b8:	3c017005 */ 	lui	$at,%hi(var70054240)
/*    1a3bc:	c4274240 */ 	lwc1	$f7,%lo(var70054240)($at)
/*    1a3c0:	46804220 */ 	cvt.s.w	$f8,$f8
/*    1a3c4:	460741c2 */ 	mul.s	$f7,$f8,$f7
/*    1a3c8:	03e00008 */ 	jr	$ra
/*    1a3cc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel cosf
/*    1a3d0:	3c017005 */ 	lui	$at,%hi(var70054244)
/*    1a3d4:	c42d4244 */ 	lwc1	$f13,%lo(var70054244)($at)
/*    1a3d8:	460d6300 */ 	add.s	$f12,$f12,$f13
);

GLOBAL_ASM(
glabel sinf
/*    1a3dc:	44086000 */ 	mfc1	$t0,$f12
/*    1a3e0:	00000000 */ 	nop
/*    1a3e4:	00084583 */ 	sra	$t0,$t0,0x16
/*    1a3e8:	310801ff */ 	andi	$t0,$t0,0x1ff
/*    1a3ec:	290100ff */ 	slti	$at,$t0,0xff
/*    1a3f0:	10200018 */ 	beqz	$at,.L0001a454
/*    1a3f4:	00000000 */ 	nop
/*    1a3f8:	290100e6 */ 	slti	$at,$t0,0xe6
/*    1a3fc:	1420003c */ 	bnez	$at,.L0001a4f0
/*    1a400:	46006006 */ 	mov.s	$f0,$f12
/*    1a404:	460c6382 */ 	mul.s	$f14,$f12,$f12
/*    1a408:	3c017005 */ 	lui	$at,%hi(var70054248)
/*    1a40c:	c42f4248 */ 	lwc1	$f15,%lo(var70054248)($at)
/*    1a410:	3c017005 */ 	lui	$at,%hi(var7005424c)
/*    1a414:	c42d424c */ 	lwc1	$f13,%lo(var7005424c)($at)
/*    1a418:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a41c:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a420:	3c017005 */ 	lui	$at,%hi(var70054250)
/*    1a424:	c42d4250 */ 	lwc1	$f13,%lo(var70054250)($at)
/*    1a428:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a42c:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a430:	3c017005 */ 	lui	$at,%hi(var70054254)
/*    1a434:	c42d4254 */ 	lwc1	$f13,%lo(var70054254)($at)
/*    1a438:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a43c:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a440:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a444:	00000000 */ 	nop
/*    1a448:	460c7bc2 */ 	mul.s	$f15,$f15,$f12
/*    1a44c:	03e00008 */ 	jr	$ra
/*    1a450:	460c7800 */ 	add.s	$f0,$f15,$f12
.L0001a454:
/*    1a454:	29010136 */ 	slti	$at,$t0,0x136
/*    1a458:	50200025 */ 	beqzl	$at,.L0001a4f0
/*    1a45c:	44800000 */ 	mtc1	$zero,$f0
/*    1a460:	3c017005 */ 	lui	$at,%hi(var70054258)
/*    1a464:	c42e4258 */ 	lwc1	$f14,%lo(var70054258)($at)
/*    1a468:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*    1a46c:	4600738c */ 	round.w.s	$f14,$f14
/*    1a470:	44097000 */ 	mfc1	$t1,$f14
/*    1a474:	468073a0 */ 	cvt.s.w	$f14,$f14
/*    1a478:	3c017005 */ 	lui	$at,%hi(var7005425c)
/*    1a47c:	c42f425c */ 	lwc1	$f15,%lo(var7005425c)($at)
/*    1a480:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a484:	460f6301 */ 	sub.s	$f12,$f12,$f15
/*    1a488:	3c017005 */ 	lui	$at,%hi(var70054260)
/*    1a48c:	c42f4260 */ 	lwc1	$f15,%lo(var70054260)($at)
/*    1a490:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a494:	460f6301 */ 	sub.s	$f12,$f12,$f15
/*    1a498:	3c017005 */ 	lui	$at,%hi(var70054264)
/*    1a49c:	c42f4264 */ 	lwc1	$f15,%lo(var70054264)($at)
/*    1a4a0:	460c6382 */ 	mul.s	$f14,$f12,$f12
/*    1a4a4:	3c017005 */ 	lui	$at,%hi(var70054268)
/*    1a4a8:	c42d4268 */ 	lwc1	$f13,%lo(var70054268)($at)
/*    1a4ac:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4b0:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a4b4:	3c017005 */ 	lui	$at,%hi(var7005426c)
/*    1a4b8:	c42d426c */ 	lwc1	$f13,%lo(var7005426c)($at)
/*    1a4bc:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4c0:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a4c4:	3c017005 */ 	lui	$at,%hi(var70054270)
/*    1a4c8:	c42d4270 */ 	lwc1	$f13,%lo(var70054270)($at)
/*    1a4cc:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4d0:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a4d4:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4d8:	00000000 */ 	nop
/*    1a4dc:	460c7bc2 */ 	mul.s	$f15,$f15,$f12
/*    1a4e0:	31290001 */ 	andi	$t1,$t1,0x1
/*    1a4e4:	460c7800 */ 	add.s	$f0,$f15,$f12
/*    1a4e8:	55200001 */ 	bnezl	$t1,.L0001a4f0
/*    1a4ec:	46000007 */ 	neg.s	$f0,$f0
.L0001a4f0:
/*    1a4f0:	03e00008 */ 	jr	$ra
/*    1a4f4:	00000000 */ 	nop
);
