#include <ultra64.h>
#include "lib/entry.h"
#include "lib/init.h"
#include "lib/reset.h"
#include "lib/segments.h"
#include "constants.h"
#include "game/game_0e0770.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/lib_074f0.h"
#include "lib/lib_09660.h"
#include "lib/lib_0c000.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_13710.h"
#include "lib/lib_13750.h"
#include "lib/lib_2fa00.h"
#include "lib/lib_48150.h"
#include "data.h"
#include "types.h"

OSThread g_RmonThread;
OSThread g_IdleThread;
OSThread g_MainThread;
u32 var8008d900;
u32 var8008d904;
u32 var8008d908;
u32 var8008d90c;
u32 var8008d910;
u32 var8008d914;
u32 var8008d918;
u32 var8008d91c;
u32 var8008d920;
u32 var8008d924;
u32 var8008d928;
u32 var8008d92c;
u32 var8008d930;
u32 var8008d934;
u32 var8008d938;
u32 var8008d93c;
u32 var8008d940;
u32 var8008d944;
u32 var8008d948;
u32 var8008d94c;
u32 var8008d950;
u32 var8008d954;
u32 var8008d958;
u32 var8008d95c;
u32 var8008d960;
u32 var8008d964;
u32 var8008d968;
u32 var8008d96c;
u32 var8008d970;
u32 var8008d974;
u32 var8008d978;
u32 var8008d97c;
u32 var8008d980;
u32 var8008d984;
u32 var8008d988;
u32 var8008d98c;
u32 var8008d990;
u32 var8008d994;
u32 var8008d998;
u32 var8008d99c;
u32 var8008d9a0;
u32 var8008d9a4;
u32 var8008d9a8;
u32 var8008d9ac;
u32 var8008d9b0;
u32 var8008d9b4;
u32 var8008d9b8;
u32 var8008d9bc;
u32 var8008d9c0;
u32 var8008d9c4;
u32 var8008d9c8;
u32 var8008d9cc;
u32 var8008d9d0;
u32 var8008d9d4;
u32 var8008d9d8;
u32 var8008d9dc;
u32 var8008d9e0;
u32 var8008d9e4;
u32 var8008d9e8;
u32 var8008d9ec;
u32 var8008d9f0;
u32 var8008d9f4;
u32 var8008d9f8;
u32 var8008d9fc;
u32 var8008da00;
u32 var8008da04;
u32 var8008da08;
u32 var8008da0c;
u32 var8008da10;
u32 var8008da14;
u32 var8008da18;
u32 var8008da1c;
u32 var8008da20;
u32 var8008da24;
u32 var8008da28;
u32 var8008da2c;
u32 var8008da30;
u32 var8008da34;
u32 var8008da38;
u32 var8008da3c;
u32 var8008da40;
u32 var8008da44;
u32 var8008da48;
u32 var8008da4c;
u32 var8008da50;
u32 var8008da54;
u32 var8008da58;
u32 var8008da5c;
u32 var8008da60;
u32 var8008da64;
u32 var8008da68;
u32 var8008da6c;
u32 var8008da70;
u32 var8008da74;
u32 var8008da78;
u32 var8008da7c;
u32 var8008da80;
u32 var8008da84;
u32 var8008da88;
u32 var8008da8c;
u32 var8008da90;
u32 var8008da94;
u32 var8008da98;
u32 var8008da9c;
u32 var8008daa0;
u32 var8008daa4;
u32 var8008daa8;
u32 var8008daac;
u32 var8008dab0;
u32 var8008dab4;
u32 var8008dab8;
u32 var8008dabc;
u32 var8008dac0;
u32 var8008dac4;
u32 var8008dac8;
u32 var8008dacc;
u32 var8008dad0;
u32 var8008dad4;
u32 var8008dad8;
u32 var8008dadc;
u32 var8008dae0;
u32 var8008dae4;
u32 var8008dae8;
u32 var8008daec;
u32 var8008daf0;
u32 var8008daf4;
u32 var8008daf8;
u32 var8008dafc;
u32 var8008db00;
u32 var8008db04;
u32 var8008db08;
u32 var8008db0c;
u32 var8008db10;
u32 var8008db14;
u32 var8008db18;
u32 var8008db1c;
u32 var8008db20;
u32 var8008db24;
u32 var8008db28;
u32 var8008db2c;
OSMesgQueue var8008db30;
OSMesg var8008db48;
u32 var8008db4c;
u32 var8008db50;
u32 var8008db54;
u32 var8008db58;
u32 var8008db5c;
u32 var8008db60;
u32 var8008db64;
u32 var8008db68;
u32 var8008db6c;
u32 var8008db70;
u32 var8008db74;
u32 var8008db78;
u32 var8008db7c;
u32 var8008db80;
u32 var8008db84;
u32 var8008db88;
u32 var8008db8c;
u32 var8008db90;
u32 var8008db94;
u32 var8008db98;
u32 var8008db9c;
u32 var8008dba0;
u32 var8008dba4;
u32 var8008dba8;
u32 var8008dbac;
u32 var8008dbb0;
u32 var8008dbb4;
u32 var8008dbb8;
u32 var8008dbbc;
u32 var8008dbc0;
u32 var8008dbc4;
OSMesgQueue *g_SchedCmdQ;
u32 var8008dbcc;
OSSched g_SchedThread;
OSScClient var8008dca8;
u32 var8008dcb0;
u32 g_OsMemSize;

u32 var8005ce00 = 0;
u32 var8005ce04 = 0;
u32 var8005ce08 = 0;
u32 var8005ce0c = 0;
u8 *g_StackStartAddrs[7] = {0};
u8 *g_StackEndAddrs[7] = {0};
u8 *g_StackAllocatedPos = (u8 *)0x80400000;
u32 var8005ce4c = 0x00000002;
u32 var8005ce50 = 0x10000000;

extern u8 *_bootSegmentStart;
extern u8 *_datazipSegmentRomStart;
extern u8 *_datazipSegmentRomEnd;
extern u8 *_dataSegmentStart;
extern u8 *_inflateSegmentRomStart;
extern u8 *_inflateSegmentRomEnd;
extern u32 var803f50b8;
extern u32 vara00002e8;
extern u16 varbc000c02;
extern u16 *var800902e4;
extern s16 var800902e8;

#if VERSION >= VERSION_NTSC_1_0
s32 osGetMemSize(void)
{
	return g_OsMemSize;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel init
/*     16cc:	3c0e8000 */ 	lui	$t6,0x8000
/*     16d0:	8dce030c */ 	lw	$t6,0x30c($t6)
/*     16d4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     16d8:	24010001 */ 	addiu	$at,$zero,0x1
/*     16dc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     16e0:	15c10007 */ 	bne	$t6,$at,.L00001700
/*     16e4:	afb00020 */ 	sw	$s0,0x20($sp)
/*     16e8:	3c0f803f */ 	lui	$t7,0x803f
/*     16ec:	8df850b8 */ 	lw	$t8,0x50b8($t7)
/*     16f0:	3c028009 */ 	lui	$v0,%hi(g_OsMemSize)
/*     16f4:	2442dcb4 */ 	addiu	$v0,$v0,%lo(g_OsMemSize)
/*     16f8:	10000008 */ 	b	.L0000171c
/*     16fc:	ac580000 */ 	sw	$t8,0x0($v0)
.L00001700:
/*     1700:	3c198000 */ 	lui	$t9,0x8000
/*     1704:	8f390318 */ 	lw	$t9,0x318($t9)
/*     1708:	3c028009 */ 	lui	$v0,%hi(g_OsMemSize)
/*     170c:	2442dcb4 */ 	addiu	$v0,$v0,%lo(g_OsMemSize)
/*     1710:	3c0a803f */ 	lui	$t2,0x803f
/*     1714:	ac590000 */ 	sw	$t9,0x0($v0)
/*     1718:	ad5950b8 */ 	sw	$t9,0x50b8($t2)
.L0000171c:
/*     171c:	3c040004 */ 	lui	$a0,%hi(_datazipSegmentRomStart)
/*     1720:	3c0b0005 */ 	lui	$t3,%hi(_datazipSegmentRomEnd)
/*     1724:	3c0c0005 */ 	lui	$t4,%hi(_inflateSegmentRomEnd)
/*     1728:	3c0d0005 */ 	lui	$t5,%hi(_inflateSegmentRomStart)
/*     172c:	25ade850 */ 	addiu	$t5,$t5,%lo(_inflateSegmentRomStart)
/*     1730:	258cfc40 */ 	addiu	$t4,$t4,%lo(_inflateSegmentRomEnd)
/*     1734:	256be850 */ 	addiu	$t3,$t3,%lo(_datazipSegmentRomEnd)
/*     1738:	24849850 */ 	addiu	$a0,$a0,%lo(_datazipSegmentRomStart)
/*     173c:	01644023 */ 	subu	$t0,$t3,$a0
/*     1740:	018d7023 */ 	subu	$t6,$t4,$t5
/*     1744:	010e1821 */ 	addu	$v1,$t0,$t6
/*     1748:	2462ffff */ 	addiu	$v0,$v1,-1
/*     174c:	0440000b */ 	bltz	$v0,.L0000177c
/*     1750:	3c057000 */ 	lui	$a1,%hi(boot)
/*     1754:	3c017000 */ 	lui	$at,0x7000
/*     1758:	3c0f7020 */ 	lui	$t7,0x7020
/*     175c:	01e88023 */ 	subu	$s0,$t7,$t0
/*     1760:	00811825 */ 	or	$v1,$a0,$at
.L00001764:
/*     1764:	0062c021 */ 	addu	$t8,$v1,$v0
/*     1768:	93190000 */ 	lbu	$t9,0x0($t8)
/*     176c:	02024821 */ 	addu	$t1,$s0,$v0
/*     1770:	2442ffff */ 	addiu	$v0,$v0,-1
/*     1774:	0441fffb */ 	bgez	$v0,.L00001764
/*     1778:	a1390000 */ 	sb	$t9,0x0($t1)
.L0000177c:
/*     177c:	24a51050 */ 	addiu	$a1,$a1,%lo(boot)
/*     1780:	3c07702c */ 	lui	$a3,0x702c
/*     1784:	3c0a7020 */ 	lui	$t2,0x7020
/*     1788:	01488023 */ 	subu	$s0,$t2,$t0
/*     178c:	34e793e0 */ 	ori	$a3,$a3,0x93e0
/*     1790:	24a52000 */ 	addiu	$a1,$a1,0x2000
/*     1794:	00002025 */ 	or	$a0,$zero,$zero
/*     1798:	3c037028 */ 	lui	$v1,0x7028
.L0000179c:
/*     179c:	00a45821 */ 	addu	$t3,$a1,$a0
/*     17a0:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     17a4:	24630004 */ 	addiu	$v1,$v1,0x4
/*     17a8:	0067082b */ 	sltu	$at,$v1,$a3
/*     17ac:	24840004 */ 	addiu	$a0,$a0,0x4
/*     17b0:	1420fffa */ 	bnez	$at,.L0000179c
/*     17b4:	ac6cfffc */ 	sw	$t4,-0x4($v1)
/*     17b8:	3c047028 */ 	lui	$a0,0x7028
/*     17bc:	0c0005ab */ 	jal	bootInflate
/*     17c0:	3c068030 */ 	lui	$a2,0x8030
/*     17c4:	3c058006 */ 	lui	$a1,%hi(_dataSegmentStart)
/*     17c8:	24a59fe0 */ 	addiu	$a1,$a1,%lo(_dataSegmentStart)
/*     17cc:	02002025 */ 	or	$a0,$s0,$zero
/*     17d0:	0c0005ab */ 	jal	bootInflate
/*     17d4:	3c068030 */ 	lui	$a2,0x8030
/*     17d8:	3c0da000 */ 	lui	$t5,0xa000
/*     17dc:	8dae02e8 */ 	lw	$t6,0x2e8($t5)
/*     17e0:	3c01c86e */ 	lui	$at,0xc86e
/*     17e4:	34212000 */ 	ori	$at,$at,0x2000
/*     17e8:	11c10003 */ 	beq	$t6,$at,.L000017f8
/*     17ec:	24040001 */ 	addiu	$a0,$zero,0x1
.L000017f0:
/*     17f0:	1000ffff */ 	b	.L000017f0
/*     17f4:	00000000 */ 	nop
.L000017f8:
/*     17f8:	0c00058d */ 	jal	bootUnmapTLBRange
/*     17fc:	2405001f */ 	addiu	$a1,$zero,0x1f
/*     1800:	3c048006 */ 	lui	$a0,%hi(g_StackStartAddrs)
/*     1804:	3c038006 */ 	lui	$v1,%hi(g_StackEndAddrs)
/*     1808:	3c028006 */ 	lui	$v0,%hi(g_StackAllocatedPos)
/*     180c:	2442ce48 */ 	addiu	$v0,$v0,%lo(g_StackAllocatedPos)
/*     1810:	2463ce2c */ 	addiu	$v1,$v1,%lo(g_StackEndAddrs)
/*     1814:	2484ce10 */ 	addiu	$a0,$a0,%lo(g_StackStartAddrs)
.L00001818:
/*     1818:	24630004 */ 	addiu	$v1,$v1,0x4
/*     181c:	24840004 */ 	addiu	$a0,$a0,0x4
/*     1820:	ac80fffc */ 	sw	$zero,-0x4($a0)
/*     1824:	1462fffc */ 	bne	$v1,$v0,.L00001818
/*     1828:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*     182c:	0c0016d8 */ 	jal	osInitialize
/*     1830:	00000000 */ 	nop
/*     1834:	0c012048 */ 	jal	osWritebackDCacheAll
/*     1838:	00000000 */ 	nop
/*     183c:	3c048000 */ 	lui	$a0,0x8000
/*     1840:	0c012054 */ 	jal	osInvalICache
/*     1844:	24054000 */ 	addiu	$a1,$zero,0x4000
/*     1848:	0c012074 */ 	jal	__osGetFpcCsr
/*     184c:	00000000 */ 	nop
/*     1850:	0c012078 */ 	jal	__osSetFpcCsr
/*     1854:	34440e80 */ 	ori	$a0,$v0,0xe80
/*     1858:	24040003 */ 	addiu	$a0,$zero,0x3
/*     185c:	0c00062b */ 	jal	allocateStack
/*     1860:	34059800 */ 	dli	$a1,0x9800
/*     1864:	3c108009 */ 	lui	$s0,%hi(g_MainThread)
/*     1868:	2610d6d0 */ 	addiu	$s0,$s0,%lo(g_MainThread)
/*     186c:	3c067000 */ 	lui	$a2,%hi(mainproc)
/*     1870:	2409000a */ 	addiu	$t1,$zero,0xa
/*     1874:	afa90014 */ 	sw	$t1,0x14($sp)
/*     1878:	24c61aa4 */ 	addiu	$a2,$a2,%lo(mainproc)
/*     187c:	02002025 */ 	or	$a0,$s0,$zero
/*     1880:	24050003 */ 	addiu	$a1,$zero,0x3
/*     1884:	00003825 */ 	or	$a3,$zero,$zero
/*     1888:	0c000fb8 */ 	jal	osCreateThread
/*     188c:	afa20010 */ 	sw	$v0,0x10($sp)
/*     1890:	0c01207c */ 	jal	osStartThread
/*     1894:	02002025 */ 	or	$a0,$s0,$zero
/*     1898:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     189c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     18a0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*     18a4:	03e00008 */ 	jr	$ra
/*     18a8:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel init
/*     1720:	3c040003 */ 	lui	$a0,0x3
/*     1724:	3c0e0004 */ 	lui	$t6,0x4
/*     1728:	3c0f0004 */ 	lui	$t7,0x4
/*     172c:	3c180004 */ 	lui	$t8,0x4
/*     1730:	27182850 */ 	addiu	$t8,$t8,0x2850
/*     1734:	25ef3c40 */ 	addiu	$t7,$t7,0x3c40
/*     1738:	25ce2850 */ 	addiu	$t6,$t6,0x2850
/*     173c:	24840850 */ 	addiu	$a0,$a0,0x850
/*     1740:	01c44023 */ 	subu	$t0,$t6,$a0
/*     1744:	01f8c823 */ 	subu	$t9,$t7,$t8
/*     1748:	01191821 */ 	addu	$v1,$t0,$t9
/*     174c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     1750:	2462ffff */ 	addiu	$v0,$v1,-1
/*     1754:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     1758:	0440000b */ 	bltz	$v0,.L00001788
/*     175c:	afb00020 */ 	sw	$s0,0x20($sp)
/*     1760:	3c017000 */ 	lui	$at,0x7000
/*     1764:	3c097020 */ 	lui	$t1,0x7020
/*     1768:	01288023 */ 	subu	$s0,$t1,$t0
/*     176c:	00811825 */ 	or	$v1,$a0,$at
.L00001770:
/*     1770:	00625021 */ 	addu	$t2,$v1,$v0
/*     1774:	914b0000 */ 	lbu	$t3,0x0($t2)
/*     1778:	02026021 */ 	addu	$t4,$s0,$v0
/*     177c:	2442ffff */ 	addiu	$v0,$v0,-1
/*     1780:	0441fffb */ 	bgez	$v0,.L00001770
/*     1784:	a18b0000 */ 	sb	$t3,0x0($t4)
.L00001788:
/*     1788:	3c057000 */ 	lui	$a1,0x7000
/*     178c:	24a51050 */ 	addiu	$a1,$a1,0x1050
/*     1790:	3c0d7020 */ 	lui	$t5,0x7020
/*     1794:	3c07702c */ 	lui	$a3,0x702c
/*     1798:	34e793e0 */ 	ori	$a3,$a3,0x93e0
/*     179c:	01a88023 */ 	subu	$s0,$t5,$t0
/*     17a0:	24a52000 */ 	addiu	$a1,$a1,0x2000
/*     17a4:	00002025 */ 	move	$a0,$zero
/*     17a8:	3c037028 */ 	lui	$v1,0x7028
.L000017ac:
/*     17ac:	00a47021 */ 	addu	$t6,$a1,$a0
/*     17b0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*     17b4:	24630004 */ 	addiu	$v1,$v1,0x4
/*     17b8:	0067082b */ 	sltu	$at,$v1,$a3
/*     17bc:	24840004 */ 	addiu	$a0,$a0,0x4
/*     17c0:	1420fffa */ 	bnez	$at,.L000017ac
/*     17c4:	ac6ffffc */ 	sw	$t7,-0x4($v1)
/*     17c8:	3c047028 */ 	lui	$a0,0x7028
/*     17cc:	0c0005c3 */ 	jal	0x170c
/*     17d0:	3c068030 */ 	lui	$a2,0x8030
/*     17d4:	3c058006 */ 	lui	$a1,0x8006
/*     17d8:	24a5b760 */ 	addiu	$a1,$a1,-18592
/*     17dc:	02002025 */ 	move	$a0,$s0
/*     17e0:	0c0005c3 */ 	jal	0x170c
/*     17e4:	3c068030 */ 	lui	$a2,0x8030
/*     17e8:	24040001 */ 	li	$a0,0x1
/*     17ec:	0c00059c */ 	jal	segGetDataStart
/*     17f0:	2405001f */ 	li	$a1,0x1f
/*     17f4:	3c048006 */ 	lui	$a0,0x8006
/*     17f8:	3c038006 */ 	lui	$v1,0x8006
/*     17fc:	3c028006 */ 	lui	$v0,0x8006
/*     1800:	2442e5c8 */ 	addiu	$v0,$v0,-6712
/*     1804:	2463e5ac */ 	addiu	$v1,$v1,-6740
/*     1808:	2484e590 */ 	addiu	$a0,$a0,-6768
.L0000180c:
/*     180c:	24630004 */ 	addiu	$v1,$v1,0x4
/*     1810:	24840004 */ 	addiu	$a0,$a0,0x4
/*     1814:	ac80fffc */ 	sw	$zero,-0x4($a0)
/*     1818:	1462fffc */ 	bne	$v1,$v0,.L0000180c
/*     181c:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*     1820:	0c001728 */ 	jal	0x5ca0
/*     1824:	00000000 */ 	nop
/*     1828:	0c01253c */ 	jal	0x494f0
/*     182c:	00000000 */ 	nop
/*     1830:	3c048000 */ 	lui	$a0,0x8000
/*     1834:	0c012548 */ 	jal	osEPiRawStartDma
/*     1838:	24054000 */ 	li	$a1,0x4000
/*     183c:	0c012568 */ 	jal	0x495a0
/*     1840:	00000000 */ 	nop
/*     1844:	0c01256c */ 	jal	__osDisableInt
/*     1848:	34440e80 */ 	ori	$a0,$v0,0xe80
/*     184c:	3c03bc00 */ 	lui	$v1,0xbc00
/*     1850:	34630c02 */ 	ori	$v1,$v1,0xc02
/*     1854:	3c018009 */ 	lui	$at,0x8009
/*     1858:	ac2302e4 */ 	sw	$v1,0x2e4($at)
/*     185c:	3c018009 */ 	lui	$at,0x8009
/*     1860:	240a4040 */ 	li	$t2,0x4040
/*     1864:	a42a02e8 */ 	sh	$t2,0x2e8($at)
/*     1868:	240b4040 */ 	li	$t3,0x4040
/*     186c:	a46b0000 */ 	sh	$t3,0x0($v1)
/*     1870:	24040003 */ 	li	$a0,0x3
/*     1874:	0c000631 */ 	jal	0x18c4
/*     1878:	34059800 */ 	li	$a1,0x9800
/*     187c:	3c108009 */ 	lui	$s0,0x8009
/*     1880:	2610fd00 */ 	addiu	$s0,$s0,-768
/*     1884:	3c067000 */ 	lui	$a2,0x7000
/*     1888:	240c000a */ 	li	$t4,0xa
/*     188c:	afac0014 */ 	sw	$t4,0x14($sp)
/*     1890:	24c61b04 */ 	addiu	$a2,$a2,0x1b04
/*     1894:	02002025 */ 	move	$a0,$s0
/*     1898:	24050003 */ 	li	$a1,0x3
/*     189c:	00003825 */ 	move	$a3,$zero
/*     18a0:	0c00107c */ 	jal	0x41f0
/*     18a4:	afa20010 */ 	sw	$v0,0x10($sp)
/*     18a8:	0c012570 */ 	jal	0x495c0
/*     18ac:	02002025 */ 	move	$a0,$s0
/*     18b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     18b4:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     18b8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*     18bc:	03e00008 */ 	jr	$ra
/*     18c0:	00000000 */ 	nop
);
#endif

/**
 * Prepares the inflate, .data and lib segments, then creates and starts the
 * main thread.
 *
 * This function relies on the fact that the N64 BIOS loads the first 1MB of ROM
 * data into memory at power on. The inflate, .data and lib segments are already
 * in RAM thanks to this but need to be relocated, and .data and lib need to be
 * unzipped too.
 */
// Mismatch: Goal uses s0 for dst in some places.
// Also uses way less stack somehow.
//void init(void)
//{
//	u32 datacomplen;
//	u32 inflatelen;
//	u32 src;
//	u32 dst;
//	u32 i;
//	s32 j;
//
//#if VERSION >= VERSION_NTSC_1_0
//	if (osResetType == RESET_TYPE_NMI) {
//		g_OsMemSize = var803f50b8;
//	} else {
//		g_OsMemSize = osMemSize;
//		var803f50b8 = g_OsMemSize;
//	}
//#endif
//
//	// Copy compressed .data and inflate segments
//	// .data is copied to 0x701eb000 - 0x70200000
//	// inflate is copied to 0x70200000 - 0x702013f0
//	src = (u32)&_datazipSegmentRomStart | 0x70000000;
//	datacomplen = (u32)&_datazipSegmentRomEnd - (u32)&_datazipSegmentRomStart;
//	inflatelen = (u32)&_inflateSegmentRomEnd - (u32)&_inflateSegmentRomStart;
//	dst = 0x70200000 - datacomplen;
//
//	for (j = datacomplen + inflatelen - 1; j >= 0; j--) {
//		((u8 *)dst)[j] = ((u8 *)src)[j];
//	}
//
//	// Copy compressed lib segment to 0x70280000.
//	// It's assumed that lib is placed immediately after boot in the ROM and
//	// that boot's length is 0x2000.
//	// It's also assumed that lib's compressed length is less than 0x124f8
//	// words. This is fine, as it's about half that.
//	src = 0;
//	src += (u32)&_bootSegmentStart;
//	src += 0x2000;
//	dst = 0x70280000;
//
//	for (i = 0; i < 0x124f8; i++) {
//		((u32 *)dst)[i] = ((u32 *)src)[i];
//	}
//
//	// Inflate lib
//	bootInflate(dst, src, 0x80300000);
//
//	// Inflate .data
//	bootInflate(0x70200000 - datacomplen, &_dataSegmentStart, 0x80300000);
//
//#if VERSION >= VERSION_NTSC_1_0
//#if PIRACYCHECKS
//	if (vara00002e8 != 0xc86e2000) {
//		while (1);
//	}
//#endif
//#endif
//
//	bootUnmapTLBRange(1, 31);
//
//	// Clear the stack allocation pointers
//	for (i = 0; i < ARRAYCOUNT(g_StackStartAddrs); i++) {
//		g_StackStartAddrs[i] = NULL;
//		g_StackEndAddrs[i] = NULL;
//	}
//
//	osInitialize();
//	osWritebackDCacheAll();
//	osInvalICache((void *) 0x80000000, 0x4000);
//	__osSetFpcCsr(__osGetFpcCsr() | 0xe80);
//
//#if VERSION == VERSION_NTSC_BETA
//	var800902e4 = &varbc000c02;
//	var800902e8 = 0x4040;
//	varbc000c02 = 0x4040;
//#endif
//
//	// Create and start the main thread
//	osCreateThread(&g_MainThread, THREAD_MAIN, mainproc, NULL, allocateStack(THREAD_MAIN, STACKSIZE_MAIN), THREADPRI_MAIN);
//	osStartThread(&g_MainThread);
//}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel allocateStack
/*     18ac:	3c098006 */ 	lui	$t1,%hi(g_StackAllocatedPos)
/*     18b0:	2529ce48 */ 	addiu	$t1,$t1,%lo(g_StackAllocatedPos)
/*     18b4:	8d230000 */ 	lw	$v1,0x0($t1)
/*     18b8:	00041080 */ 	sll	$v0,$a0,0x2
/*     18bc:	3c018006 */ 	lui	$at,%hi(g_StackEndAddrs)
/*     18c0:	00220821 */ 	addu	$at,$at,$v0
/*     18c4:	ac23ce2c */ 	sw	$v1,%lo(g_StackEndAddrs)($at)
/*     18c8:	2401fff0 */ 	addiu	$at,$zero,-16
/*     18cc:	24a5000f */ 	addiu	$a1,$a1,0xf
/*     18d0:	00a17024 */ 	and	$t6,$a1,$at
/*     18d4:	3c018006 */ 	lui	$at,%hi(g_StackStartAddrs)
/*     18d8:	006e7823 */ 	subu	$t7,$v1,$t6
/*     18dc:	ad2f0000 */ 	sw	$t7,0x0($t1)
/*     18e0:	00220821 */ 	addu	$at,$at,$v0
/*     18e4:	01c02825 */ 	or	$a1,$t6,$zero
/*     18e8:	ac2fce10 */ 	sw	$t7,%lo(g_StackStartAddrs)($at)
/*     18ec:	01e01825 */ 	or	$v1,$t7,$zero
/*     18f0:	19c0000d */ 	blez	$t6,.L00001928
/*     18f4:	00004025 */ 	or	$t0,$zero,$zero
/*     18f8:	3083000f */ 	andi	$v1,$a0,0xf
/*     18fc:	2418000f */ 	addiu	$t8,$zero,0xf
/*     1900:	0303c823 */ 	subu	$t9,$t8,$v1
/*     1904:	00195100 */ 	sll	$t2,$t9,0x4
/*     1908:	01433025 */ 	or	$a2,$t2,$v1
/*     190c:	01e01025 */ 	or	$v0,$t7,$zero
.L00001910:
/*     1910:	25080001 */ 	addiu	$t0,$t0,0x1
/*     1914:	24420001 */ 	addiu	$v0,$v0,0x1
/*     1918:	1505fffd */ 	bne	$t0,$a1,.L00001910
/*     191c:	a046ffff */ 	sb	$a2,-0x1($v0)
/*     1920:	3c038006 */ 	lui	$v1,%hi(g_StackAllocatedPos)
/*     1924:	8c63ce48 */ 	lw	$v1,%lo(g_StackAllocatedPos)($v1)
.L00001928:
/*     1928:	00651021 */ 	addu	$v0,$v1,$a1
/*     192c:	03e00008 */ 	jr	$ra
/*     1930:	2442fff8 */ 	addiu	$v0,$v0,-8
);

/**
 * Allocate stack space for the given thread ID.
 *
 * Each allocation is aligned to 16 bytes.
 *
 * Allocations start from the end of onboard memory (0x80400000) and are
 * allocated right to left.
 *
 * The returned address leaves 8 bytes free on the right side of the stack,
 * presumably for identification purposes. So the actual stack space available
 * can be 8 bytes above or below what was requested.
 *
 * The stack is initialised with the thread's ID. This makes it easier to
 * identify in memory and detect when a stack overflow has occurred.
 */
// Mismatch:
// i is stored in a3 but should be t0
// The value written to ptr[i] is stored in t0 but should be a2
//void *allocateStack(s32 threadid, s32 size)
//{
//	u8 *ptr8;
//	u32 *ptr32;
//	s32 i;
//	s32 j;
//
//	g_StackEndAddrs[threadid] = g_StackAllocatedPos;
//	size = (size + 0xf) & 0xfffffff0;
//
//	g_StackAllocatedPos -= size;
//	g_StackStartAddrs[threadid] = g_StackAllocatedPos;
//
//	ptr8 = g_StackStartAddrs[threadid];
//
//	for (i = 0; i < size; i++) {
//		ptr8[i] = ((0xf - (threadid & 0xf)) << 4) | (threadid & 0xf);
//	}
//
//#if VERSION == VERSION_NTSC_BETA
//	// Mark the first 8 words specially
//	ptr32 = (u32 *)g_StackStartAddrs[threadid];
//
//	for (j = 0; j < 8; j++) {
//		*ptr32 = 0xdeadbabe;
//		ptr32++;
//	}
//#endif
//
//	return g_StackAllocatedPos + size - 8;
//}
#else
GLOBAL_ASM(
glabel allocateStack
/*     18c4:	3c0a8006 */ 	lui	$t2,0x8006
/*     18c8:	254ae5c8 */ 	addiu	$t2,$t2,-6712
/*     18cc:	8d430000 */ 	lw	$v1,0x0($t2)
/*     18d0:	00041080 */ 	sll	$v0,$a0,0x2
/*     18d4:	3c018006 */ 	lui	$at,0x8006
/*     18d8:	00220821 */ 	addu	$at,$at,$v0
/*     18dc:	ac23e5ac */ 	sw	$v1,-0x1a54($at)
/*     18e0:	2401fff0 */ 	li	$at,-16
/*     18e4:	24a5000f */ 	addiu	$a1,$a1,0xf
/*     18e8:	3c188006 */ 	lui	$t8,0x8006
/*     18ec:	00a17024 */ 	and	$t6,$a1,$at
/*     18f0:	2718e590 */ 	addiu	$t8,$t8,-6768
/*     18f4:	00583821 */ 	addu	$a3,$v0,$t8
/*     18f8:	006e7823 */ 	subu	$t7,$v1,$t6
/*     18fc:	01c02825 */ 	move	$a1,$t6
/*     1900:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*     1904:	acef0000 */ 	sw	$t7,0x0($a3)
/*     1908:	19c0000b */ 	blez	$t6,.L00001938
/*     190c:	00004825 */ 	move	$t1,$zero
/*     1910:	3083000f */ 	andi	$v1,$a0,0xf
/*     1914:	2419000f */ 	li	$t9,0xf
/*     1918:	03235823 */ 	subu	$t3,$t9,$v1
/*     191c:	000b6100 */ 	sll	$t4,$t3,0x4
/*     1920:	01833025 */ 	or	$a2,$t4,$v1
/*     1924:	01e01025 */ 	move	$v0,$t7
.L00001928:
/*     1928:	25290001 */ 	addiu	$t1,$t1,0x1
/*     192c:	24420001 */ 	addiu	$v0,$v0,0x1
/*     1930:	1525fffd */ 	bne	$t1,$a1,.L00001928
/*     1934:	a046ffff */ 	sb	$a2,-0x1($v0)
.L00001938:
/*     1938:	3c04dead */ 	lui	$a0,0xdead
/*     193c:	8ce20000 */ 	lw	$v0,0x0($a3)
/*     1940:	3484babe */ 	ori	$a0,$a0,0xbabe
/*     1944:	00001825 */ 	move	$v1,$zero
/*     1948:	24060008 */ 	li	$a2,0x8
.L0000194c:
/*     194c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     1950:	ac440000 */ 	sw	$a0,0x0($v0)
/*     1954:	1466fffd */ 	bne	$v1,$a2,.L0000194c
/*     1958:	24420004 */ 	addiu	$v0,$v0,0x4
/*     195c:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*     1960:	01a51021 */ 	addu	$v0,$t5,$a1
/*     1964:	03e00008 */ 	jr	$ra
/*     1968:	2442fff8 */ 	addiu	$v0,$v0,-8
);
#endif

#if VERSION == VERSION_NTSC_BETA
s32 osGetMemSize(void)
{
	return g_OsMemSize;
}
#endif

void idleproc(void *data)
{
	while (true);
}

void idleCreateThread(void)
{
	osCreateThread(&g_IdleThread, THREAD_IDLE, idleproc, NULL, allocateStack(THREAD_IDLE, STACKSIZE_IDLE), THREADPRI_IDLE);
	osStartThread(&g_IdleThread);
}

void rmonCreateThread(void)
{
	osCreateThread(&g_RmonThread, THREAD_RMON, rmonproc, NULL, allocateStack(THREAD_RMON, STACKSIZE_RMON), THREADPRI_RMON);
	osStartThread(&g_RmonThread);
}

void schedCreateThread(void)
{
	osCreateMesgQueue(&var8008db30, &var8008db48, 32);

	if (osTvType == OS_TV_MPAL) {
		osCreateScheduler(&g_SchedThread, &var8008d900, OS_VI_MPAL_LAN1, 1);
	} else {
		osCreateScheduler(&g_SchedThread, &var8008d900, OS_VI_NTSC_LAN1, 1);
	}

	osScAddClient(&g_SchedThread, &var8008dca8, &var8008db30, 0);
	g_SchedCmdQ = osScGetCmdQ(&g_SchedThread);
}

void mainproc(void *arg)
{
	idleCreateThread();
	func00013750();
	func00013710();
	rmonCreateThread();

	if (argsParseDebugArgs()) {
		osStopThread(NULL);
	}

	osSetThreadPri(0, THREADPRI_MAIN);
	schedCreateThread();
	mainEntry();
}

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00001b70nb
/*     1b70:	3c048006 */ 	lui	$a0,0x8006
/*     1b74:	3c068006 */ 	lui	$a2,0x8006
/*     1b78:	24c6e5ac */ 	addiu	$a2,$a2,-6740
/*     1b7c:	2484e590 */ 	addiu	$a0,$a0,-6768
/*     1b80:	00001025 */ 	move	$v0,$zero
/*     1b84:	240a0007 */ 	li	$t2,0x7
/*     1b88:	2409000f */ 	li	$t1,0xf
.L00001b8c:
/*     1b8c:	8c830000 */ 	lw	$v1,0x0($a0)
/*     1b90:	24840004 */ 	addiu	$a0,$a0,0x4
/*     1b94:	8cc50000 */ 	lw	$a1,0x0($a2)
/*     1b98:	10600011 */ 	beqz	$v1,.L00001be0
/*     1b9c:	3047000f */ 	andi	$a3,$v0,0xf
/*     1ba0:	90780020 */ 	lbu	$t8,0x20($v1)
/*     1ba4:	01277023 */ 	subu	$t6,$t1,$a3
/*     1ba8:	000e7900 */ 	sll	$t7,$t6,0x4
/*     1bac:	01e74025 */ 	or	$t0,$t7,$a3
/*     1bb0:	1518000b */ 	bne	$t0,$t8,.L00001be0
/*     1bb4:	24630020 */ 	addiu	$v1,$v1,0x20
/*     1bb8:	0065082b */ 	sltu	$at,$v1,$a1
/*     1bbc:	50200009 */ 	beqzl	$at,.L00001be4
/*     1bc0:	24420001 */ 	addiu	$v0,$v0,0x1
/*     1bc4:	90790001 */ 	lbu	$t9,0x1($v1)
.L00001bc8:
/*     1bc8:	24630001 */ 	addiu	$v1,$v1,0x1
/*     1bcc:	0065082b */ 	sltu	$at,$v1,$a1
/*     1bd0:	55190004 */ 	bnel	$t0,$t9,.L00001be4
/*     1bd4:	24420001 */ 	addiu	$v0,$v0,0x1
/*     1bd8:	5420fffb */ 	bnezl	$at,.L00001bc8
/*     1bdc:	90790001 */ 	lbu	$t9,0x1($v1)
.L00001be0:
/*     1be0:	24420001 */ 	addiu	$v0,$v0,0x1
.L00001be4:
/*     1be4:	144affe9 */ 	bne	$v0,$t2,.L00001b8c
/*     1be8:	24c60004 */ 	addiu	$a2,$a2,0x4
/*     1bec:	03e00008 */ 	jr	$ra
/*     1bf0:	00000000 */ 	nop
);
#endif

#if VERSION == VERSION_NTSC_BETA
GLOBAL_ASM(
glabel func00001bf4nb
/*     1bf4:	27bdff28 */ 	addiu	$sp,$sp,-216
/*     1bf8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     1bfc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     1c00:	afb40028 */ 	sw	$s4,0x28($sp)
/*     1c04:	afb70034 */ 	sw	$s7,0x34($sp)
/*     1c08:	afb60030 */ 	sw	$s6,0x30($sp)
/*     1c0c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     1c10:	afb20020 */ 	sw	$s2,0x20($sp)
/*     1c14:	3c14dead */ 	lui	$s4,0xdead
/*     1c18:	3c157005 */ 	lui	$s5,0x7005
/*     1c1c:	3c1e8006 */ 	lui	$s8,0x8006
/*     1c20:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     1c24:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     1c28:	afb00018 */ 	sw	$s0,0x18($sp)
/*     1c2c:	27dee590 */ 	addiu	$s8,$s8,-6768
/*     1c30:	26b539b0 */ 	addiu	$s5,$s5,0x39b0
/*     1c34:	3694babe */ 	ori	$s4,$s4,0xbabe
/*     1c38:	27b2004c */ 	addiu	$s2,$sp,0x4c
/*     1c3c:	00009825 */ 	move	$s3,$zero
/*     1c40:	24160045 */ 	li	$s6,0x45
/*     1c44:	24170008 */ 	li	$s7,0x8
.L00001c48:
/*     1c48:	8fc20000 */ 	lw	$v0,0x0($s8)
/*     1c4c:	00008825 */ 	move	$s1,$zero
/*     1c50:	10400010 */ 	beqz	$v0,.L00001c94
/*     1c54:	00408025 */ 	move	$s0,$v0
.L00001c58:
/*     1c58:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*     1c5c:	528e000b */ 	beql	$s4,$t6,.L00001c8c
/*     1c60:	26310001 */ 	addiu	$s1,$s1,0x1
/*     1c64:	0c0006dc */ 	jal	0x1b70
/*     1c68:	00000000 */ 	nop
/*     1c6c:	02402025 */ 	move	$a0,$s2
/*     1c70:	02a02825 */ 	move	$a1,$s5
/*     1c74:	0c004fc1 */ 	jal	0x13f04
/*     1c78:	02603025 */ 	move	$a2,$s3
/*     1c7c:	0c003074 */ 	jal	0xc1d0
/*     1c80:	02402025 */ 	move	$a0,$s2
/*     1c84:	a0160000 */ 	sb	$s6,0x0($zero)
/*     1c88:	26310001 */ 	addiu	$s1,$s1,0x1
.L00001c8c:
/*     1c8c:	1637fff2 */ 	bne	$s1,$s7,.L00001c58
/*     1c90:	26100004 */ 	addiu	$s0,$s0,0x4
.L00001c94:
/*     1c94:	26730001 */ 	addiu	$s3,$s3,0x1
/*     1c98:	24010007 */ 	li	$at,0x7
/*     1c9c:	1661ffea */ 	bne	$s3,$at,.L00001c48
/*     1ca0:	27de0004 */ 	addiu	$s8,$s8,0x4
/*     1ca4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     1ca8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     1cac:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     1cb0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     1cb4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     1cb8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     1cbc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     1cc0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     1cc4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     1cc8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     1ccc:	03e00008 */ 	jr	$ra
/*     1cd0:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#endif
