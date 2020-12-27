#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/chr/chr.h"
#include "game/game_129210.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_126b0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_1a500.h"
#include "types.h"

/**
 * Search all props and their model data for something, and replace it with
 * something else.
 */
void func0f129210(void *find, void *replacement)
{
	u32 stack;
	struct prop *prop = g_Vars.unk00033c;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;
			struct model *model = obj->model;
			struct model08 *filedata = model->unk08;
			struct modelnode *node = filedata->rootnode;
			struct modelnode_displaylist *data;

			while (node) {
				switch (node->type & 0xff) {
				case MODELNODETYPE_DISPLAYLIST:
					data = &node->data->displaylist;

					if (model->datas[data->index] == find) {
						model->datas[data->index] = replacement;
					}
					break;
				case MODELNODETYPE_NEARFAR:
					func0001c784(obj->model, node);
					break;
				case MODELNODETYPE_PARTID:
					func0001c7d0(obj->model, node);
					break;
				case MODELNODETYPE_HEADSPOT:
					func0001c81c(obj->model, node);
					break;
				}

				if (node->child) {
					node = node->child;
				} else {
					while (node) {
						if (node->next) {
							node = node->next;
							break;
						}

						node = node->parent;
					}
				}
			}
		}

		prop = prop->next;
	}
}

void func0f12939c(void)
{
	s32 i;
	s32 j;

	if (var8007e3d0[1].val2 < var8007e3d0[1].val1 >> 2) {
		for (i = 0; i < var8007e3d0[1].numallocated - 1; i++) {
			if (var8007e3d0[1].unk24[i].unk0e > 0) {
				for (j = i + 1; j < var8007e3d0[1].numallocated; j++) {
					if (var8007e3d0[1].unk24[j].unk0e > 0
							&& var8007e3d0[1].unk24[i].unk04 == var8007e3d0[1].unk24[j].unk04
							&& var8007e3d0[1].unk24[i].unk08 == var8007e3d0[1].unk24[j].unk08) {
						s32 size = ALIGN16(var8007e3d0[1].unk24[j].unk0c * 0x0c);
						func0f129210(var8007e3d0[1].unk24[j].unk00, var8007e3d0[1].unk24[i].unk00);
						var8007e3d0[1].unk24[i].unk0e += var8007e3d0[1].unk24[j].unk0e;
						func00012cb4(var8007e3d0[1].unk24[j].unk00, size);
						var8007e3d0[1].unk24[j].unk0e = 0;
						var8007e3d0[1].val2 += var8007e3d0[1].unk24[j].unk0c;
					}
				}
			}
		}
	}

	if (var8007e3d0[1].val2 < var8007e3d0[1].val1 >> 2) {
		func0f091030();
	}
}

GLOBAL_ASM(
glabel func0f12955c
/*  f12955c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f129560:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f129564:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f129568:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f12956c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f129570:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f129574:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f129578:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f12957c:	00809025 */ 	or	$s2,$a0,$zero
/*  f129580:	00c09825 */ 	or	$s3,$a2,$zero
/*  f129584:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f129588:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f12958c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f129590:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f129594:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f129598:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f12959c:	16ae0003 */ 	bne	$s5,$t6,.L0f1295ac
/*  f1295a0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1295a4:	10000090 */ 	b	.L0f1297e8
/*  f1295a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1295ac:
/*  f1295ac:	00057880 */ 	sll	$t7,$a1,0x2
/*  f1295b0:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f1295b4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1295b8:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f1295bc:	3c188008 */ 	lui	$t8,%hi(var8007e3d0)
/*  f1295c0:	2718e3d0 */ 	addiu	$t8,$t8,%lo(var8007e3d0)
/*  f1295c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1295c8:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f1295cc:	8e39002c */ 	lw	$t9,0x2c($s1)
/*  f1295d0:	0332082a */ 	slt	$at,$t9,$s2
/*  f1295d4:	1420002f */ 	bnez	$at,.L0f129694
/*  f1295d8:	00000000 */ 	nop
/*  f1295dc:	8e220030 */ 	lw	$v0,0x30($s1)
/*  f1295e0:	00122080 */ 	sll	$a0,$s2,0x2
/*  f1295e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1295e8:	1840002a */ 	blez	$v0,.L0f129694
/*  f1295ec:	00922023 */ 	subu	$a0,$a0,$s2
/*  f1295f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1295f4:	8e230024 */ 	lw	$v1,0x24($s1)
.L0f1295f8:
/*  f1295f8:	8468000e */ 	lh	$t0,0xe($v1)
/*  f1295fc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f129600:	00a2082a */ 	slt	$at,$a1,$v0
/*  f129604:	15000021 */ 	bnez	$t0,.L0f12968c
/*  f129608:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f12960c:	00042080 */ 	sll	$a0,$a0,0x2
/*  f129610:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f129614:	3489000f */ 	ori	$t1,$a0,0xf
/*  f129618:	0c004aac */ 	jal	func00012ab0
/*  f12961c:	3924000f */ 	xori	$a0,$t1,0xf
/*  f129620:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f129624:	01706021 */ 	addu	$t4,$t3,$s0
/*  f129628:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f12962c:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f129630:	01b01821 */ 	addu	$v1,$t5,$s0
/*  f129634:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f129638:	11c00012 */ 	beqz	$t6,.L0f129684
/*  f12963c:	00000000 */ 	nop
/*  f129640:	a472000c */ 	sh	$s2,0xc($v1)
/*  f129644:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f129648:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f12964c:	a715000e */ 	sh	$s5,0xe($t8)
/*  f129650:	8e390024 */ 	lw	$t9,0x24($s1)
/*  f129654:	03304021 */ 	addu	$t0,$t9,$s0
/*  f129658:	ad130004 */ 	sw	$s3,0x4($t0)
/*  f12965c:	8e290024 */ 	lw	$t1,0x24($s1)
/*  f129660:	01305021 */ 	addu	$t2,$t1,$s0
/*  f129664:	ad540008 */ 	sw	$s4,0x8($t2)
/*  f129668:	8e2b002c */ 	lw	$t3,0x2c($s1)
/*  f12966c:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f129670:	01726023 */ 	subu	$t4,$t3,$s2
/*  f129674:	ae2c002c */ 	sw	$t4,0x2c($s1)
/*  f129678:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f12967c:	1000005a */ 	b	.L0f1297e8
/*  f129680:	8dc20000 */ 	lw	$v0,0x0($t6)
.L0f129684:
/*  f129684:	10000058 */ 	b	.L0f1297e8
/*  f129688:	00001025 */ 	or	$v0,$zero,$zero
.L0f12968c:
/*  f12968c:	1420ffda */ 	bnez	$at,.L0f1295f8
/*  f129690:	26100010 */ 	addiu	$s0,$s0,0x10
.L0f129694:
/*  f129694:	0fc07934 */ 	jal	getNumChrs
/*  f129698:	00002825 */ 	or	$a1,$zero,$zero
/*  f12969c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1296a0:	18400039 */ 	blez	$v0,.L0f129788
/*  f1296a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1296a8:	0002b0c0 */ 	sll	$s6,$v0,0x3
/*  f1296ac:	02c2b023 */ 	subu	$s6,$s6,$v0
/*  f1296b0:	0016b080 */ 	sll	$s6,$s6,0x2
/*  f1296b4:	02c2b023 */ 	subu	$s6,$s6,$v0
/*  f1296b8:	0016b080 */ 	sll	$s6,$s6,0x2
/*  f1296bc:	02c2b021 */ 	addu	$s6,$s6,$v0
/*  f1296c0:	3c178006 */ 	lui	$s7,%hi(g_ChrsA)
/*  f1296c4:	26f72988 */ 	addiu	$s7,$s7,%lo(g_ChrsA)
/*  f1296c8:	0016b0c0 */ 	sll	$s6,$s6,0x3
/*  f1296cc:	00009825 */ 	or	$s3,$zero,$zero
/*  f1296d0:	241e0005 */ 	addiu	$s8,$zero,0x5
/*  f1296d4:	27b40054 */ 	addiu	$s4,$sp,0x54
/*  f1296d8:	8eef0000 */ 	lw	$t7,0x0($s7)
.L0f1296dc:
/*  f1296dc:	026f8021 */ 	addu	$s0,$s3,$t7
/*  f1296e0:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f1296e4:	53000025 */ 	beqzl	$t8,.L0f12977c
/*  f1296e8:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f1296ec:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f1296f0:	50400022 */ 	beqzl	$v0,.L0f12977c
/*  f1296f4:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f1296f8:	90590001 */ 	lbu	$t9,0x1($v0)
/*  f1296fc:	33280080 */ 	andi	$t0,$t9,0x80
/*  f129700:	5500001e */ 	bnezl	$t0,.L0f12977c
/*  f129704:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f129708:	82090007 */ 	lb	$t1,0x7($s0)
/*  f12970c:	57c9001b */ 	bnel	$s8,$t1,.L0f12977c
/*  f129710:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f129714:	8e0a0030 */ 	lw	$t2,0x30($s0)
/*  f129718:	2a410006 */ 	slti	$at,$s2,0x6
/*  f12971c:	55400017 */ 	bnezl	$t2,.L0f12977c
/*  f129720:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f129724:	10200005 */ 	beqz	$at,.L0f12973c
/*  f129728:	00125880 */ 	sll	$t3,$s2,0x2
/*  f12972c:	028b6021 */ 	addu	$t4,$s4,$t3
/*  f129730:	ad900000 */ 	sw	$s0,0x0($t4)
/*  f129734:	10000010 */ 	b	.L0f129778
/*  f129738:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f12973c:
/*  f12973c:	0c004b70 */ 	jal	random
/*  f129740:	00000000 */ 	nop
/*  f129744:	0052001b */ 	divu	$zero,$v0,$s2
/*  f129748:	00001810 */ 	mfhi	$v1
/*  f12974c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f129750:	16400002 */ 	bnez	$s2,.L0f12975c
/*  f129754:	00000000 */ 	nop
/*  f129758:	0007000d */ 	break	0x7
.L0f12975c:
/*  f12975c:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f129760:	00608825 */ 	or	$s1,$v1,$zero
/*  f129764:	0fc0f341 */ 	jal	chrEnableReap
/*  f129768:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f12976c:	00117880 */ 	sll	$t7,$s1,0x2
/*  f129770:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f129774:	af100000 */ 	sw	$s0,0x0($t8)
.L0f129778:
/*  f129778:	26730368 */ 	addiu	$s3,$s3,0x368
.L0f12977c:
/*  f12977c:	0276082a */ 	slt	$at,$s3,$s6
/*  f129780:	5420ffd6 */ 	bnezl	$at,.L0f1296dc
/*  f129784:	8eef0000 */ 	lw	$t7,0x0($s7)
.L0f129788:
/*  f129788:	00128843 */ 	sra	$s1,$s2,0x1
/*  f12978c:	12200015 */ 	beqz	$s1,.L0f1297e4
/*  f129790:	27b40054 */ 	addiu	$s4,$sp,0x54
.L0f129794:
/*  f129794:	0c004b70 */ 	jal	random
/*  f129798:	00000000 */ 	nop
/*  f12979c:	0052001b */ 	divu	$zero,$v0,$s2
/*  f1297a0:	00001810 */ 	mfhi	$v1
/*  f1297a4:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1297a8:	02994021 */ 	addu	$t0,$s4,$t9
/*  f1297ac:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f1297b0:	16400002 */ 	bnez	$s2,.L0f1297bc
/*  f1297b4:	00000000 */ 	nop
/*  f1297b8:	0007000d */ 	break	0x7
.L0f1297bc:
/*  f1297bc:	00602825 */ 	or	$a1,$v1,$zero
/*  f1297c0:	11200006 */ 	beqz	$t1,.L0f1297dc
/*  f1297c4:	00035080 */ 	sll	$t2,$v1,0x2
/*  f1297c8:	028a8021 */ 	addu	$s0,$s4,$t2
/*  f1297cc:	0fc0f341 */ 	jal	chrEnableReap
/*  f1297d0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1297d4:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f1297d8:	2631ffff */ 	addiu	$s1,$s1,-1
.L0f1297dc:
/*  f1297dc:	1620ffed */ 	bnez	$s1,.L0f129794
/*  f1297e0:	00000000 */ 	nop
.L0f1297e4:
/*  f1297e4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1297e8:
/*  f1297e8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1297ec:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1297f0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1297f4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1297f8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1297fc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f129800:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f129804:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f129808:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f12980c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f129810:	03e00008 */ 	jr	$ra
/*  f129814:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

void func0f129818(s32 arg0, void *arg1)
{
	s32 i;

	for (i = 0; i < var8007e3d0[arg0].numallocated; i++) {
		if (var8007e3d0[arg0].unk24[i].unk0e > 0 && arg1 == var8007e3d0[arg0].unk24[i].unk00) {
			var8007e3d0[arg0].unk24[i].unk0e--;

			if (var8007e3d0[arg0].unk24[i].unk0e) {
				return;
			}

			func00012cb4(var8007e3d0[arg0].unk24[i].unk00, ALIGN16(var8007e3d0[arg0].unk24[i].unk0c * 0xc));

			var8007e3d0[arg0].val2 += var8007e3d0[arg0].unk24[i].unk0c;
			return;
		}
	}
}
