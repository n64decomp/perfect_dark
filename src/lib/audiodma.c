#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/game_0b69d0.h"
#include "game/file.h"
#include "game/game_176080.h"
#include "game/options.h"
#include "bss.h"
#include "lib/audiodma.h"
#include "lib/memory.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct admaitem {
	ALLink node;
	u32 startaddr;
	u32 lastframe;
	u8 *ptr;
};

struct admastate {
	u8 initialised;
	struct admaitem *firstused;
	struct admaitem *firstfree;
	u32 unk0c;
};

u32 var8005d520 = 0;

struct admastate g_AdmaState;
struct admaitem g_AdmaItems[80];
u32 var80091f50[480];
OSMesgQueue var800926d0;
OSMesg var800926e8[80];
u32 var80092828;

void admaInit(void)
{
	osCreateMesgQueue(&var800926d0, var800926e8, 80);
}

void admaExec(void);

GLOBAL_ASM(
glabel admaExec
/*     9690:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*     9694:	3c088009 */ 	lui	$t0,%hi(g_AdmaState)
/*     9698:	25081900 */ 	addiu	$t0,$t0,%lo(g_AdmaState)
/*     969c:	afb10028 */ 	sw	$s1,0x28($sp)
/*     96a0:	8d110004 */ 	lw	$s1,0x4($t0)
/*     96a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*     96a8:	afa60048 */ 	sw	$a2,0x48($sp)
/*     96ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     96b0:	00803825 */ 	or	$a3,$a0,$zero
/*     96b4:	00008025 */ 	or	$s0,$zero,$zero
/*     96b8:	12200015 */ 	beqz	$s1,.L00009710
/*     96bc:	02203025 */ 	or	$a2,$s1,$zero
/*     96c0:	8cc20008 */ 	lw	$v0,0x8($a2)
.L000096c4:
/*     96c4:	00e57021 */ 	addu	$t6,$a3,$a1
/*     96c8:	00e2082a */ 	slt	$at,$a3,$v0
/*     96cc:	14200010 */ 	bnez	$at,.L00009710
/*     96d0:	24430400 */ 	addiu	$v1,$v0,0x400
/*     96d4:	006e082a */ 	slt	$at,$v1,$t6
/*     96d8:	1420000a */ 	bnez	$at,.L00009704
/*     96dc:	00c08025 */ 	or	$s0,$a2,$zero
/*     96e0:	8cd80010 */ 	lw	$t8,0x10($a2)
/*     96e4:	3c0f8009 */ 	lui	$t7,%hi(var80092828)
/*     96e8:	8def2828 */ 	lw	$t7,%lo(var80092828)($t7)
/*     96ec:	0307c821 */ 	addu	$t9,$t8,$a3
/*     96f0:	03222023 */ 	subu	$a0,$t9,$v0
/*     96f4:	0c012d20 */ 	jal	osVirtualToPhysical
/*     96f8:	accf000c */ 	sw	$t7,0xc($a2)
/*     96fc:	1000004d */ 	b	.L00009834
/*     9700:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00009704:
/*     9704:	8cc60000 */ 	lw	$a2,0x0($a2)
/*     9708:	54c0ffee */ 	bnezl	$a2,.L000096c4
/*     970c:	8cc20008 */ 	lw	$v0,0x8($a2)
.L00009710:
/*     9710:	8d060008 */ 	lw	$a2,0x8($t0)
/*     9714:	14c00005 */ 	bnez	$a2,.L0000972c
/*     9718:	00c02025 */ 	or	$a0,$a2,$zero
/*     971c:	0c012d20 */ 	jal	osVirtualToPhysical
/*     9720:	02202025 */ 	or	$a0,$s1,$zero
/*     9724:	10000043 */ 	b	.L00009834
/*     9728:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0000972c:
/*     972c:	8cc90000 */ 	lw	$t1,0x0($a2)
/*     9730:	afa70040 */ 	sw	$a3,0x40($sp)
/*     9734:	afa60034 */ 	sw	$a2,0x34($sp)
/*     9738:	0c00c5e9 */ 	jal	alUnlink
/*     973c:	ad090008 */ 	sw	$t1,0x8($t0)
/*     9740:	3c088009 */ 	lui	$t0,%hi(g_AdmaState)
/*     9744:	25081900 */ 	addiu	$t0,$t0,%lo(g_AdmaState)
/*     9748:	8fa60034 */ 	lw	$a2,0x34($sp)
/*     974c:	12000009 */ 	beqz	$s0,.L00009774
/*     9750:	8fa70040 */ 	lw	$a3,0x40($sp)
/*     9754:	00c02025 */ 	or	$a0,$a2,$zero
/*     9758:	02002825 */ 	or	$a1,$s0,$zero
/*     975c:	afa60034 */ 	sw	$a2,0x34($sp)
/*     9760:	0c00c5dc */ 	jal	alLink
/*     9764:	afa70040 */ 	sw	$a3,0x40($sp)
/*     9768:	8fa60034 */ 	lw	$a2,0x34($sp)
/*     976c:	1000000c */ 	b	.L000097a0
/*     9770:	8fa70040 */ 	lw	$a3,0x40($sp)
.L00009774:
/*     9774:	8d110004 */ 	lw	$s1,0x4($t0)
/*     9778:	52200007 */ 	beqzl	$s1,.L00009798
/*     977c:	ad060004 */ 	sw	$a2,0x4($t0)
/*     9780:	ad060004 */ 	sw	$a2,0x4($t0)
/*     9784:	acd10000 */ 	sw	$s1,0x0($a2)
/*     9788:	acc00004 */ 	sw	$zero,0x4($a2)
/*     978c:	10000004 */ 	b	.L000097a0
/*     9790:	ae260004 */ 	sw	$a2,0x4($s1)
/*     9794:	ad060004 */ 	sw	$a2,0x4($t0)
.L00009798:
/*     9798:	acc00000 */ 	sw	$zero,0x0($a2)
/*     979c:	acc00004 */ 	sw	$zero,0x4($a2)
.L000097a0:
/*     97a0:	30f10001 */ 	andi	$s1,$a3,0x1
/*     97a4:	00f13823 */ 	subu	$a3,$a3,$s1
/*     97a8:	acc70008 */ 	sw	$a3,0x8($a2)
/*     97ac:	3c0a8009 */ 	lui	$t2,%hi(var80092828)
/*     97b0:	8d4a2828 */ 	lw	$t2,%lo(var80092828)($t2)
/*     97b4:	8cd00010 */ 	lw	$s0,0x10($a2)
/*     97b8:	3c018000 */ 	lui	$at,0x8000
/*     97bc:	acca000c */ 	sw	$t2,0xc($a2)
/*     97c0:	afa70040 */ 	sw	$a3,0x40($sp)
/*     97c4:	00e12025 */ 	or	$a0,$a3,$at
/*     97c8:	0c013920 */ 	jal	osInvalDCache
/*     97cc:	24050400 */ 	addiu	$a1,$zero,0x400
/*     97d0:	3c038006 */ 	lui	$v1,%hi(var8005d520)
/*     97d4:	2463d520 */ 	addiu	$v1,$v1,%lo(var8005d520)
/*     97d8:	8c620000 */ 	lw	$v0,0x0($v1)
/*     97dc:	3c0c8009 */ 	lui	$t4,%hi(var80091f50)
/*     97e0:	3c0e8009 */ 	lui	$t6,%hi(var800926d0)
/*     97e4:	00025880 */ 	sll	$t3,$v0,0x2
/*     97e8:	01625823 */ 	subu	$t3,$t3,$v0
/*     97ec:	000b58c0 */ 	sll	$t3,$t3,0x3
/*     97f0:	25ce26d0 */ 	addiu	$t6,$t6,%lo(var800926d0)
/*     97f4:	258c1f50 */ 	addiu	$t4,$t4,%lo(var80091f50)
/*     97f8:	240d0400 */ 	addiu	$t5,$zero,0x400
/*     97fc:	244f0001 */ 	addiu	$t7,$v0,0x1
/*     9800:	8fa70040 */ 	lw	$a3,0x40($sp)
/*     9804:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*     9808:	afad0014 */ 	sw	$t5,0x14($sp)
/*     980c:	016c2021 */ 	addu	$a0,$t3,$t4
/*     9810:	afae0018 */ 	sw	$t6,0x18($sp)
/*     9814:	24050001 */ 	addiu	$a1,$zero,0x1
/*     9818:	00003025 */ 	or	$a2,$zero,$zero
/*     981c:	0c01394c */ 	jal	osPiStartDma
/*     9820:	afb00010 */ 	sw	$s0,0x10($sp)
/*     9824:	0c012d20 */ 	jal	osVirtualToPhysical
/*     9828:	02002025 */ 	or	$a0,$s0,$zero
/*     982c:	00511021 */ 	addu	$v0,$v0,$s1
/*     9830:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00009834:
/*     9834:	8fb00024 */ 	lw	$s0,0x24($sp)
/*     9838:	8fb10028 */ 	lw	$s1,0x28($sp)
/*     983c:	03e00008 */ 	jr	$ra
/*     9840:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

void *admaNew(struct admastate **state)
{
#if VERSION >= VERSION_PAL_FINAL
	s32 max = 80;
#else
	s32 max = IS4MB() ? 60 : 80;
#endif
	s32 i;

	if (!g_AdmaState.initialised) {
		g_AdmaState.firstfree = g_AdmaItems;

		for (i = 0; i < max - 1; i++) {
			alLink(&g_AdmaItems[i + 1].node, &g_AdmaItems[i].node);
			g_AdmaItems[i].ptr = alHeapAlloc(&g_SndHeap, 1, 1024);
		}

		g_AdmaState.initialised = true;
	}

	*state = &g_AdmaState;

	return &admaExec;
}

GLOBAL_ASM(
glabel admaClear
/*     993c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     9940:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     9944:	3c128009 */ 	lui	$s2,%hi(g_AdmaState)
/*     9948:	26521900 */ 	addiu	$s2,$s2,%lo(g_AdmaState)
/*     994c:	afb00014 */ 	sw	$s0,0x14($sp)
/*     9950:	8e500004 */ 	lw	$s0,0x4($s2)
/*     9954:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     9958:	afb30020 */ 	sw	$s3,0x20($sp)
/*     995c:	1200001c */ 	beqz	$s0,.L000099d0
/*     9960:	afb10018 */ 	sw	$s1,0x18($sp)
/*     9964:	3c138009 */ 	lui	$s3,%hi(var80092828)
/*     9968:	26732828 */ 	addiu	$s3,$s3,%lo(var80092828)
.L0000996c:
/*     996c:	8e0f000c */ 	lw	$t7,0xc($s0)
/*     9970:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*     9974:	8e020000 */ 	lw	$v0,0x0($s0)
/*     9978:	25f80001 */ 	addiu	$t8,$t7,0x1
/*     997c:	030e082b */ 	sltu	$at,$t8,$t6
/*     9980:	10200011 */ 	beqz	$at,.L000099c8
/*     9984:	00408825 */ 	or	$s1,$v0,$zero
/*     9988:	8e590004 */ 	lw	$t9,0x4($s2)
/*     998c:	16190002 */ 	bne	$s0,$t9,.L00009998
/*     9990:	00000000 */ 	nop
/*     9994:	ae420004 */ 	sw	$v0,0x4($s2)
.L00009998:
/*     9998:	0c00c5e9 */ 	jal	alUnlink
/*     999c:	02002025 */ 	or	$a0,$s0,$zero
/*     99a0:	8e450008 */ 	lw	$a1,0x8($s2)
/*     99a4:	50a00006 */ 	beqzl	$a1,.L000099c0
/*     99a8:	ae500008 */ 	sw	$s0,0x8($s2)
/*     99ac:	0c00c5dc */ 	jal	alLink
/*     99b0:	02002025 */ 	or	$a0,$s0,$zero
/*     99b4:	10000004 */ 	b	.L000099c8
/*     99b8:	00000000 */ 	nop
/*     99bc:	ae500008 */ 	sw	$s0,0x8($s2)
.L000099c0:
/*     99c0:	ae000000 */ 	sw	$zero,0x0($s0)
/*     99c4:	ae000004 */ 	sw	$zero,0x4($s0)
.L000099c8:
/*     99c8:	1620ffe8 */ 	bnez	$s1,.L0000996c
/*     99cc:	02208025 */ 	or	$s0,$s1,$zero
.L000099d0:
/*     99d0:	3c138009 */ 	lui	$s3,%hi(var80092828)
/*     99d4:	26732828 */ 	addiu	$s3,$s3,%lo(var80092828)
/*     99d8:	8e680000 */ 	lw	$t0,0x0($s3)
/*     99dc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     99e0:	3c018006 */ 	lui	$at,%hi(var8005d520)
/*     99e4:	25090001 */ 	addiu	$t1,$t0,0x1
/*     99e8:	ae690000 */ 	sw	$t1,0x0($s3)
/*     99ec:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     99f0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     99f4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     99f8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     99fc:	ac20d520 */ 	sw	$zero,%lo(var8005d520)($at)
/*     9a00:	03e00008 */ 	jr	$ra
/*     9a04:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel adma00009a08
/*     9a08:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     9a0c:	afb30020 */ 	sw	$s3,0x20($sp)
/*     9a10:	3c138006 */ 	lui	$s3,%hi(var8005d520)
/*     9a14:	2673d520 */ 	addiu	$s3,$s3,%lo(var8005d520)
/*     9a18:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*     9a1c:	afb00014 */ 	sw	$s0,0x14($sp)
/*     9a20:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     9a24:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     9a28:	afb10018 */ 	sw	$s1,0x18($sp)
/*     9a2c:	19c0000c */ 	blez	$t6,.L00009a60
/*     9a30:	00008025 */ 	or	$s0,$zero,$zero
/*     9a34:	3c118009 */ 	lui	$s1,%hi(var800926d0)
/*     9a38:	263126d0 */ 	addiu	$s1,$s1,%lo(var800926d0)
/*     9a3c:	02202025 */ 	or	$a0,$s1,$zero
.L00009a40:
/*     9a40:	00002825 */ 	or	$a1,$zero,$zero
/*     9a44:	0c0121bc */ 	jal	osRecvMesg
/*     9a48:	00003025 */ 	or	$a2,$zero,$zero
/*     9a4c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*     9a50:	26100001 */ 	addiu	$s0,$s0,0x1
/*     9a54:	020f082a */ 	slt	$at,$s0,$t7
/*     9a58:	5420fff9 */ 	bnezl	$at,.L00009a40
/*     9a5c:	02202025 */ 	or	$a0,$s1,$zero
.L00009a60:
/*     9a60:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     9a64:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     9a68:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     9a6c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     9a70:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     9a74:	03e00008 */ 	jr	$ra
/*     9a78:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
