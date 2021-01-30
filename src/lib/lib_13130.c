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
#include "lib/lib_0bfb0.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var70054010[] = "s1";
const char var70054014[] = "str.c";
const char var7005401c[] = "s2";
const char var70054020[] = "str.c";
const char var70054028[] = "";
const char var7005402c[] = "";

GLOBAL_ASM(
glabel strcpy
/*    13130:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13134:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13138:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1313c:	14800009 */ 	bnez	$a0,.L00013164
/*    13140:	00a03825 */ 	or	$a3,$a1,$zero
/*    13144:	3c047005 */ 	lui	$a0,%hi(var70054010)
/*    13148:	3c057005 */ 	lui	$a1,%hi(var70054014)
/*    1314c:	24a54014 */ 	addiu	$a1,$a1,%lo(var70054014)
/*    13150:	24844010 */ 	addiu	$a0,$a0,%lo(var70054010)
/*    13154:	2406002c */ 	addiu	$a2,$zero,0x2c
/*    13158:	0c002ff4 */ 	jal	func0000bfd0
/*    1315c:	afa7001c */ 	sw	$a3,0x1c($sp)
/*    13160:	8fa7001c */ 	lw	$a3,0x1c($sp)
.L00013164:
/*    13164:	14e00008 */ 	bnez	$a3,.L00013188
/*    13168:	3c047005 */ 	lui	$a0,%hi(var7005401c)
/*    1316c:	3c057005 */ 	lui	$a1,%hi(var70054020)
/*    13170:	24a54020 */ 	addiu	$a1,$a1,%lo(var70054020)
/*    13174:	2484401c */ 	addiu	$a0,$a0,%lo(var7005401c)
/*    13178:	2406002d */ 	addiu	$a2,$zero,0x2d
/*    1317c:	0c002ff4 */ 	jal	func0000bfd0
/*    13180:	afa7001c */ 	sw	$a3,0x1c($sp)
/*    13184:	8fa7001c */ 	lw	$a3,0x1c($sp)
.L00013188:
/*    13188:	90e20000 */ 	lbu	$v0,0x0($a3)
/*    1318c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    13190:	24e70001 */ 	addiu	$a3,$a3,0x1
/*    13194:	a1e20000 */ 	sb	$v0,0x0($t7)
/*    13198:	10400006 */ 	beqz	$v0,.L000131b4
/*    1319c:	25e30001 */ 	addiu	$v1,$t7,0x1
.L000131a0:
/*    131a0:	90e20000 */ 	lbu	$v0,0x0($a3)
/*    131a4:	24630001 */ 	addiu	$v1,$v1,0x1
/*    131a8:	24e70001 */ 	addiu	$a3,$a3,0x1
/*    131ac:	1440fffc */ 	bnez	$v0,.L000131a0
/*    131b0:	a062ffff */ 	sb	$v0,-0x1($v1)
.L000131b4:
/*    131b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    131b8:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    131bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    131c0:	03e00008 */ 	jr	$ra
/*    131c4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel strncpy
/*    131c8:	90a20000 */ 	lbu	$v0,0x0($a1)
/*    131cc:	24830001 */ 	addiu	$v1,$a0,0x1
/*    131d0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    131d4:	10400009 */ 	beqz	$v0,.L000131fc
/*    131d8:	a0820000 */ 	sb	$v0,0x0($a0)
.L000131dc:
/*    131dc:	24c6ffff */ 	addiu	$a2,$a2,-1
/*    131e0:	50c00007 */ 	beqzl	$a2,.L00013200
/*    131e4:	00c01025 */ 	or	$v0,$a2,$zero
/*    131e8:	90a20000 */ 	lbu	$v0,0x0($a1)
/*    131ec:	24630001 */ 	addiu	$v1,$v1,0x1
/*    131f0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    131f4:	1440fff9 */ 	bnez	$v0,.L000131dc
/*    131f8:	a062ffff */ 	sb	$v0,-0x1($v1)
.L000131fc:
/*    131fc:	00c01025 */ 	or	$v0,$a2,$zero
.L00013200:
/*    13200:	10c00006 */ 	beqz	$a2,.L0001321c
/*    13204:	24c6ffff */ 	addiu	$a2,$a2,-1
.L00013208:
/*    13208:	00c01025 */ 	or	$v0,$a2,$zero
/*    1320c:	a0600000 */ 	sb	$zero,0x0($v1)
/*    13210:	24630001 */ 	addiu	$v1,$v1,0x1
/*    13214:	14c0fffc */ 	bnez	$a2,.L00013208
/*    13218:	24c6ffff */ 	addiu	$a2,$a2,-1
.L0001321c:
/*    1321c:	03e00008 */ 	jr	$ra
/*    13220:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel strcat
/*    13224:	908e0000 */ 	lbu	$t6,0x0($a0)
/*    13228:	00801025 */ 	or	$v0,$a0,$zero
/*    1322c:	51c00006 */ 	beqzl	$t6,.L00013248
/*    13230:	90a30000 */ 	lbu	$v1,0x0($a1)
/*    13234:	904f0001 */ 	lbu	$t7,0x1($v0)
.L00013238:
/*    13238:	24420001 */ 	addiu	$v0,$v0,0x1
/*    1323c:	55e0fffe */ 	bnezl	$t7,.L00013238
/*    13240:	904f0001 */ 	lbu	$t7,0x1($v0)
/*    13244:	90a30000 */ 	lbu	$v1,0x0($a1)
.L00013248:
/*    13248:	24420001 */ 	addiu	$v0,$v0,0x1
/*    1324c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    13250:	10600006 */ 	beqz	$v1,.L0001326c
/*    13254:	a043ffff */ 	sb	$v1,-0x1($v0)
.L00013258:
/*    13258:	90a30000 */ 	lbu	$v1,0x0($a1)
/*    1325c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    13260:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    13264:	1460fffc */ 	bnez	$v1,.L00013258
/*    13268:	a043ffff */ 	sb	$v1,-0x1($v0)
.L0001326c:
/*    1326c:	03e00008 */ 	jr	$ra
/*    13270:	00801025 */ 	or	$v0,$a0,$zero
);

s32 strcmp(char *s1, char *s2)
{
	if (*s1 != *s2) {
		if (*s1 < *s2) {
			return -1;
		} else {
			return 1;
		}
	}

	if (*s1 == '\0') {
		return 0;
	}

	return strcmp(s1 + 1, s2 + 1);
}

s32 strncmp(char *s1, char *s2, s32 len)
{
	if (len == 0) {
		return 0;
	}

	len--;

	if (*s1 != *s2) {
		if (*s1 < *s2) {
			return -1;
		} else {
			return 1;
		}
	}

	if (*s1 == '\0') {
		return 0;
	}

	return strncmp(s1 + 1, s2 + 1, len);
}

char toupper(char c)
{
	if (c >= 'a' && c <= 'z') {
		return c - 0x20;
	}

	return c;
}

s32 isdigit(char c)
{
	return c >= '0' && c <= '9';
}

s32 isalpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

s32 isspace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v';
}

GLOBAL_ASM(
glabel func00013408
/*    13408:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    1340c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    13410:	00c09825 */ 	or	$s3,$a2,$zero
/*    13414:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    13418:	afb40028 */ 	sw	$s4,0x28($sp)
/*    1341c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    13420:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    13424:	afb00018 */ 	sw	$s0,0x18($sp)
/*    13428:	afa50064 */ 	sw	$a1,0x64($sp)
/*    1342c:	04c00006 */ 	bltz	$a2,.L00013448
/*    13430:	00803825 */ 	or	$a3,$a0,$zero
/*    13434:	24010001 */ 	addiu	$at,$zero,0x1
/*    13438:	10c10003 */ 	beq	$a2,$at,.L00013448
/*    1343c:	28c10025 */ 	slti	$at,$a2,0x25
/*    13440:	54200003 */ 	bnezl	$at,.L00013450
/*    13444:	90e40000 */ 	lbu	$a0,0x0($a3)
.L00013448:
/*    13448:	2413000a */ 	addiu	$s3,$zero,0xa
/*    1344c:	90e40000 */ 	lbu	$a0,0x0($a3)
.L00013450:
/*    13450:	00e09025 */ 	or	$s2,$a3,$zero
/*    13454:	0c004ced */ 	jal	isspace
/*    13458:	afa70060 */ 	sw	$a3,0x60($sp)
/*    1345c:	50400007 */ 	beqzl	$v0,.L0001347c
/*    13460:	92420000 */ 	lbu	$v0,0x0($s2)
/*    13464:	26520001 */ 	addiu	$s2,$s2,0x1
.L00013468:
/*    13468:	0c004ced */ 	jal	isspace
/*    1346c:	92440000 */ 	lbu	$a0,0x0($s2)
/*    13470:	5440fffd */ 	bnezl	$v0,.L00013468
/*    13474:	26520001 */ 	addiu	$s2,$s2,0x1
/*    13478:	92420000 */ 	lbu	$v0,0x0($s2)
.L0001347c:
/*    1347c:	2401002d */ 	addiu	$at,$zero,0x2d
/*    13480:	50400075 */ 	beqzl	$v0,.L00013658
/*    13484:	8fa20064 */ 	lw	$v0,0x64($sp)
/*    13488:	14410004 */ 	bne	$v0,$at,.L0001349c
/*    1348c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    13490:	afae005c */ 	sw	$t6,0x5c($sp)
/*    13494:	10000008 */ 	b	.L000134b8
/*    13498:	26520001 */ 	addiu	$s2,$s2,0x1
.L0001349c:
/*    1349c:	2401002b */ 	addiu	$at,$zero,0x2b
/*    134a0:	54410005 */ 	bnel	$v0,$at,.L000134b8
/*    134a4:	afa0005c */ 	sw	$zero,0x5c($sp)
/*    134a8:	afa0005c */ 	sw	$zero,0x5c($sp)
/*    134ac:	10000002 */ 	b	.L000134b8
/*    134b0:	26520001 */ 	addiu	$s2,$s2,0x1
/*    134b4:	afa0005c */ 	sw	$zero,0x5c($sp)
.L000134b8:
/*    134b8:	24010010 */ 	addiu	$at,$zero,0x10
/*    134bc:	1661000b */ 	bne	$s3,$at,.L000134ec
/*    134c0:	00000000 */ 	nop
/*    134c4:	924f0000 */ 	lbu	$t7,0x0($s2)
/*    134c8:	24010030 */ 	addiu	$at,$zero,0x30
/*    134cc:	15e10007 */ 	bne	$t7,$at,.L000134ec
/*    134d0:	00000000 */ 	nop
/*    134d4:	0c004cc8 */ 	jal	toupper
/*    134d8:	92440001 */ 	lbu	$a0,0x1($s2)
/*    134dc:	24010058 */ 	addiu	$at,$zero,0x58
/*    134e0:	14410002 */ 	bne	$v0,$at,.L000134ec
/*    134e4:	00000000 */ 	nop
/*    134e8:	26520002 */ 	addiu	$s2,$s2,0x2
.L000134ec:
/*    134ec:	1660000e */ 	bnez	$s3,.L00013528
/*    134f0:	92420000 */ 	lbu	$v0,0x0($s2)
/*    134f4:	24010030 */ 	addiu	$at,$zero,0x30
/*    134f8:	1441000b */ 	bne	$v0,$at,.L00013528
/*    134fc:	2413000a */ 	addiu	$s3,$zero,0xa
/*    13500:	0c004cc8 */ 	jal	toupper
/*    13504:	92440001 */ 	lbu	$a0,0x1($s2)
/*    13508:	24010058 */ 	addiu	$at,$zero,0x58
/*    1350c:	14410004 */ 	bne	$v0,$at,.L00013520
/*    13510:	24130008 */ 	addiu	$s3,$zero,0x8
/*    13514:	26520002 */ 	addiu	$s2,$s2,0x2
/*    13518:	10000001 */ 	b	.L00013520
/*    1351c:	24130010 */ 	addiu	$s3,$zero,0x10
.L00013520:
/*    13520:	10000001 */ 	b	.L00013528
/*    13524:	92420000 */ 	lbu	$v0,0x0($s2)
.L00013528:
/*    13528:	305000ff */ 	andi	$s0,$v0,0xff
/*    1352c:	afb20044 */ 	sw	$s2,0x44($sp)
/*    13530:	afa00040 */ 	sw	$zero,0x40($sp)
/*    13534:	00008825 */ 	or	$s1,$zero,$zero
/*    13538:	12000033 */ 	beqz	$s0,.L00013608
/*    1353c:	02001825 */ 	or	$v1,$s0,$zero
/*    13540:	2414ffff */ 	addiu	$s4,$zero,-1
.L00013544:
/*    13544:	320400ff */ 	andi	$a0,$s0,0xff
/*    13548:	0c004cd6 */ 	jal	isdigit
/*    1354c:	afa30034 */ 	sw	$v1,0x34($sp)
/*    13550:	10400005 */ 	beqz	$v0,.L00013568
/*    13554:	8fa30034 */ 	lw	$v1,0x34($sp)
/*    13558:	2470ffd0 */ 	addiu	$s0,$v1,-48
/*    1355c:	321800ff */ 	andi	$t8,$s0,0xff
/*    13560:	1000000a */ 	b	.L0001358c
/*    13564:	03008025 */ 	or	$s0,$t8,$zero
.L00013568:
/*    13568:	0c004cde */ 	jal	isalpha
/*    1356c:	320400ff */ 	andi	$a0,$s0,0xff
/*    13570:	50400026 */ 	beqzl	$v0,.L0001360c
/*    13574:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    13578:	0c004cc8 */ 	jal	toupper
/*    1357c:	320400ff */ 	andi	$a0,$s0,0xff
/*    13580:	2450ffc9 */ 	addiu	$s0,$v0,-55
/*    13584:	321900ff */ 	andi	$t9,$s0,0xff
/*    13588:	03208025 */ 	or	$s0,$t9,$zero
.L0001358c:
/*    1358c:	0213082a */ 	slt	$at,$s0,$s3
/*    13590:	1020001d */ 	beqz	$at,.L00013608
/*    13594:	24090001 */ 	addiu	$t1,$zero,0x1
/*    13598:	0293001b */ 	divu	$zero,$s4,$s3
/*    1359c:	00001012 */ 	mflo	$v0
/*    135a0:	0051082b */ 	sltu	$at,$v0,$s1
/*    135a4:	16600002 */ 	bnez	$s3,.L000135b0
/*    135a8:	00000000 */ 	nop
/*    135ac:	0007000d */ 	break	0x7
.L000135b0:
/*    135b0:	1420000b */ 	bnez	$at,.L000135e0
/*    135b4:	00000000 */ 	nop
/*    135b8:	1622000b */ 	bne	$s1,$v0,.L000135e8
/*    135bc:	00000000 */ 	nop
/*    135c0:	0293001b */ 	divu	$zero,$s4,$s3
/*    135c4:	00004010 */ 	mfhi	$t0
/*    135c8:	0110082b */ 	sltu	$at,$t0,$s0
/*    135cc:	16600002 */ 	bnez	$s3,.L000135d8
/*    135d0:	00000000 */ 	nop
/*    135d4:	0007000d */ 	break	0x7
.L000135d8:
/*    135d8:	10200003 */ 	beqz	$at,.L000135e8
/*    135dc:	00000000 */ 	nop
.L000135e0:
/*    135e0:	10000005 */ 	b	.L000135f8
/*    135e4:	afa90040 */ 	sw	$t1,0x40($sp)
.L000135e8:
/*    135e8:	02330019 */ 	multu	$s1,$s3
/*    135ec:	00008812 */ 	mflo	$s1
/*    135f0:	02308821 */ 	addu	$s1,$s1,$s0
/*    135f4:	00000000 */ 	nop
.L000135f8:
/*    135f8:	92500001 */ 	lbu	$s0,0x1($s2)
/*    135fc:	26520001 */ 	addiu	$s2,$s2,0x1
/*    13600:	1600ffd0 */ 	bnez	$s0,.L00013544
/*    13604:	02001825 */ 	or	$v1,$s0,$zero
.L00013608:
/*    13608:	8faa0044 */ 	lw	$t2,0x44($sp)
.L0001360c:
/*    1360c:	8fa20064 */ 	lw	$v0,0x64($sp)
/*    13610:	524a0011 */ 	beql	$s2,$t2,.L00013658
/*    13614:	8fa20064 */ 	lw	$v0,0x64($sp)
/*    13618:	50400003 */ 	beqzl	$v0,.L00013628
/*    1361c:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    13620:	ac520000 */ 	sw	$s2,0x0($v0)
/*    13624:	8fab0040 */ 	lw	$t3,0x40($sp)
.L00013628:
/*    13628:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    1362c:	11600003 */ 	beqz	$t3,.L0001363c
/*    13630:	00000000 */ 	nop
/*    13634:	1000000d */ 	b	.L0001366c
/*    13638:	2402ffff */ 	addiu	$v0,$zero,-1
.L0001363c:
/*    1363c:	11800003 */ 	beqz	$t4,.L0001364c
/*    13640:	02201825 */ 	or	$v1,$s1,$zero
/*    13644:	10000009 */ 	b	.L0001366c
/*    13648:	00111023 */ 	negu	$v0,$s1
.L0001364c:
/*    1364c:	10000007 */ 	b	.L0001366c
/*    13650:	00601025 */ 	or	$v0,$v1,$zero
/*    13654:	8fa20064 */ 	lw	$v0,0x64($sp)
.L00013658:
/*    13658:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    1365c:	50400003 */ 	beqzl	$v0,.L0001366c
/*    13660:	00001025 */ 	or	$v0,$zero,$zero
/*    13664:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    13668:	00001025 */ 	or	$v0,$zero,$zero
.L0001366c:
/*    1366c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    13670:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    13674:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    13678:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    1367c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    13680:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    13684:	03e00008 */ 	jr	$ra
/*    13688:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    1368c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel proutSprintf
/*    13690:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13694:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13698:	0c012978 */ 	jal	memcpy
/*    1369c:	afa60020 */ 	sw	$a2,0x20($sp)
/*    136a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    136a4:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    136a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    136ac:	03e00008 */ 	jr	$ra
/*    136b0:	004e1021 */ 	addu	$v0,$v0,$t6
);

GLOBAL_ASM(
glabel sprintf
/*    136b4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    136b8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    136bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    136c0:	afa50024 */ 	sw	$a1,0x24($sp)
/*    136c4:	afa60028 */ 	sw	$a2,0x28($sp)
/*    136c8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    136cc:	3c047001 */ 	lui	$a0,%hi(proutSprintf)
/*    136d0:	24843690 */ 	addiu	$a0,$a0,%lo(proutSprintf)
/*    136d4:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    136d8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    136dc:	0c013b40 */ 	jal	_Printf
/*    136e0:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    136e4:	04400004 */ 	bltz	$v0,.L000136f8
/*    136e8:	00401825 */ 	or	$v1,$v0,$zero
/*    136ec:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    136f0:	01c27821 */ 	addu	$t7,$t6,$v0
/*    136f4:	a1e00000 */ 	sb	$zero,0x0($t7)
.L000136f8:
/*    136f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    136fc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    13700:	03e00008 */ 	jr	$ra
/*    13704:	00000000 */ 	nop
/*    13708:	00000000 */ 	nop
/*    1370c:	00000000 */ 	nop
);
