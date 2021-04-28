#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/chr/chr.h"
#include "game/game_129210.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/lib_126b0.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

const char var7f1b5230[] = "VTXSTORE : vtxfixrefs -> Start - p1=%x, p2=%x\n";
const char var7f1b5260[] = "vtxfixrefs : Part=%x -- Mapping ptr %x -> %x\n";
const char var7f1b5290[] = "VTXSTORE : vtxfixrefs -> End - Done=%d\n";
const char var7f1b52b8[] = "vtxstorecheck : memaFree -> %u bytes at Ptr=%x(%x)\n";
const char var7f1b52ec[] = "vtxstorecheck : At block 1 %d -> Ref1=%x, Ref2=%x\n";
const char var7f1b5320[] = "vtxstorecheck : At block 2 %d -> Ref1=%x, Ref2=%x\n";
const char var7f1b5354[] = "vtx buffer low, need to delete objects\n";
const char var7f1b537c[] = "getfreevertices : %d of type %d -> ref1=%x, ref2=%x\n";
const char var7f1b53b4[] = "vtxstore: 1st mema alloc of %u bytes\n";

#if VERSION < VERSION_NTSC_1_0
const char var7f1af8ecnb[] = "vtxstore: Trying to free %d from mema (bgRooms)\n";
#endif

const char var7f1b53dc[] = "getfreevertices : Return ptr = %x\n";
const char var7f1b5400[] = "vtxstore: Out of mema (returning NULL)\n";
const char var7f1b5428[] = "vtxstore: GROSS! CorspeCount > MAX_CORPSES corpses! Freeing corpse %x\n";
const char var7f1b5470[] = "vtxstore:  CorpseCount %d, Trying to free %d\n";
const char var7f1b54a0[] = "vtxstore: Freeing corpse %x\n";
const char var7f1b54c0[] = "vtxstore: Out of vertices type %d wanted %d free %d (returning NULL)\n";
const char var7f1b5508[] = "vtxstore: freevertices type %d, list %x\n";
const char var7f1b5534[] = "freevertices: address not found in array %x\n";

struct var8007e3d0 var8007e3d0[] = {
	{ 3000, 120, 3000, 80, 0, 0, 500,  20, 12, 0, 0, 0, 0 },
	{ 1500, 40,  500,  20, 0, 0, 500,  20, 12, 0, 0, 0, 0 },
	{ 6000, 120, 6000, 80, 0, 0, 1000, 20, 4,  0, 0, 0, 0 },
	{ 1500, 40,  500,  20, 0, 0, 500,  20, 4,  0, 0, 0, 0 },
};

/**
 * Search all props and their model data for something, and replace it with
 * something else.
 */
void func0f129210(union modelrwdata *find, union modelrwdata *replacement)
{
	u32 stack;
	struct prop *prop = g_Vars.list1head;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;
			struct model *model = obj->model;
			struct modelfiledata *filedata = model->filedata;
			struct modelnode *node = filedata->rootnode;
			struct modelrodata_displaylist *rodata;

			while (node) {
				switch (node->type & 0xff) {
				case MODELNODETYPE_DISPLAYLIST:
					rodata = &node->rodata->displaylist;

					if (model->rwdatas[rodata->rwdataindex] == find) {
						model->rwdatas[rodata->rwdataindex] = replacement;
					}
					break;
				case MODELNODETYPE_NEARFAR:
					func0001c784(obj->model, node);
					break;
				case MODELNODETYPE_PARTID:
					func0001c7d0(obj->model, node);
					break;
				case MODELNODETYPE_HEADSPOT:
					modelAttachHead(obj->model, node);
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

#if VERSION >= VERSION_NTSC_1_0
void *func0f12955c(s32 count, s32 index, s32 arg2, s32 arg3)
{
	s32 i;
	s32 numchrs;
	s32 tally;
	s32 rand;
	u32 stack;
	struct chrdata *chrs[6];

	if (IS4MB()) {
		return NULL;
	}

	if (count <= var8007e3d0[index].val2) {
		for (i = 0; i < var8007e3d0[index].numallocated; i++) {
			if (var8007e3d0[index].unk24[i].unk0e == 0) {
				var8007e3d0[index].unk24[i].unk00 = func00012ab0(ALIGN16(count * 0xc));

				if (var8007e3d0[index].unk24[i].unk00) {
					var8007e3d0[index].unk24[i].unk0c = count;
					var8007e3d0[index].unk24[i].unk0e = 1;
					var8007e3d0[index].unk24[i].unk04 = arg2;
					var8007e3d0[index].unk24[i].unk08 = arg3;
					var8007e3d0[index].val2 -= count;

					return var8007e3d0[index].unk24[i].unk00;
				}

				return NULL;
			}
		}
	}

	// Build an array of all corpses. If the array becomes full then enable
	// reaping on a random corpse and replace its entry in the array.
	// So at the end, we'll have an array of up to six unreapable corpses and
	// all other corpses will be flagged for reaping.
	numchrs = getNumChrSlots();
	tally = 0;

	for (i = 0; i < numchrs; i++) {
		struct chrdata *chr = &g_ChrSlots[i];

		if (chr->model
				&& chr->prop
				&& (chr->prop->flags & PROPFLAG_80) == 0
				&& chr->actiontype == ACT_DEAD
				&& chr->act_dead.allowreap == false) {
			if (tally < 6) {
				chrs[tally] = chr;
				tally++;
			} else {
				rand = random() % tally;
				chrEnableReap(chrs[rand]);
				chrs[rand] = chr;
			}
		}
	}

	// Enable reaping on half the remaining corpses.
	// I'm reusing the rand and i variables here in order to get a match.
	// The original code likely didn't reuse them.
	rand = tally >> 1;

	while (rand) {
		i = random() % tally;

		if (chrs[i]) {
			chrEnableReap(chrs[i]);
			chrs[i] = NULL;
			rand--;
		}
	}

	return NULL;
}
#else
GLOBAL_ASM(
glabel func0f12955c
/*  f12419c:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1241a0:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f1241a4:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f1241a8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1241ac:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f1241b0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1241b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1241b8:	25ef0c30 */ 	addiu	$t7,$t7,0xc30
/*  f1241bc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1241c0:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f1241c4:	8e38002c */ 	lw	$t8,0x2c($s1)
/*  f1241c8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1241cc:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1241d0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1241d4:	0304082a */ 	slt	$at,$t8,$a0
/*  f1241d8:	00809825 */ 	or	$s3,$a0,$zero
/*  f1241dc:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f1241e0:	00e0a825 */ 	or	$s5,$a3,$zero
/*  f1241e4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1241e8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f1241ec:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1241f0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1241f4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1241f8:	1420003e */ 	bnez	$at,.NB0f1242f4
/*  f1241fc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f124200:	8e220030 */ 	lw	$v0,0x30($s1)
/*  f124204:	00139080 */ 	sll	$s2,$s3,0x2
/*  f124208:	00002825 */ 	or	$a1,$zero,$zero
/*  f12420c:	18400039 */ 	blez	$v0,.NB0f1242f4
/*  f124210:	02539023 */ 	subu	$s2,$s2,$s3
/*  f124214:	00008025 */ 	or	$s0,$zero,$zero
/*  f124218:	8e230024 */ 	lw	$v1,0x24($s1)
.NB0f12421c:
/*  f12421c:	8479000e */ 	lh	$t9,0xe($v1)
/*  f124220:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f124224:	00a2082a */ 	slt	$at,$a1,$v0
/*  f124228:	17200030 */ 	bnez	$t9,.NB0f1242ec
/*  f12422c:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f124230:	00129080 */ 	sll	$s2,$s2,0x2
/*  f124234:	2652000f */ 	addiu	$s2,$s2,0xf
/*  f124238:	3648000f */ 	ori	$t0,$s2,0xf
/*  f12423c:	3904000f */ 	xori	$a0,$t0,0xf
/*  f124240:	0c004cc9 */ 	jal	func00012ab0
/*  f124244:	00809025 */ 	or	$s2,$a0,$zero
/*  f124248:	8e2a0024 */ 	lw	$t2,0x24($s1)
/*  f12424c:	00002825 */ 	or	$a1,$zero,$zero
/*  f124250:	01505821 */ 	addu	$t3,$t2,$s0
/*  f124254:	ad620000 */ 	sw	$v0,0x0($t3)
/*  f124258:	8e2c0024 */ 	lw	$t4,0x24($s1)
/*  f12425c:	01901821 */ 	addu	$v1,$t4,$s0
/*  f124260:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f124264:	1480000b */ 	bnez	$a0,.NB0f124294
/*  f124268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12426c:	0fc5636f */ 	jal	func0f15e5b8
/*  f124270:	02402025 */ 	or	$a0,$s2,$zero
/*  f124274:	0c004cc9 */ 	jal	func00012ab0
/*  f124278:	02402025 */ 	or	$a0,$s2,$zero
/*  f12427c:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f124280:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f124284:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f124288:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f12428c:	01f01821 */ 	addu	$v1,$t7,$s0
/*  f124290:	8c640000 */ 	lw	$a0,0x0($v1)
.NB0f124294:
/*  f124294:	10800013 */ 	beqz	$a0,.NB0f1242e4
/*  f124298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12429c:	a473000c */ 	sh	$s3,0xc($v1)
/*  f1242a0:	8e390024 */ 	lw	$t9,0x24($s1)
/*  f1242a4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1242a8:	03304021 */ 	addu	$t0,$t9,$s0
/*  f1242ac:	a518000e */ 	sh	$t8,0xe($t0)
/*  f1242b0:	8e290024 */ 	lw	$t1,0x24($s1)
/*  f1242b4:	01305021 */ 	addu	$t2,$t1,$s0
/*  f1242b8:	ad540004 */ 	sw	$s4,0x4($t2)
/*  f1242bc:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f1242c0:	01706021 */ 	addu	$t4,$t3,$s0
/*  f1242c4:	ad950008 */ 	sw	$s5,0x8($t4)
/*  f1242c8:	8e2d002c */ 	lw	$t5,0x2c($s1)
/*  f1242cc:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f1242d0:	01b37023 */ 	subu	$t6,$t5,$s3
/*  f1242d4:	ae2e002c */ 	sw	$t6,0x2c($s1)
/*  f1242d8:	01f0c821 */ 	addu	$t9,$t7,$s0
/*  f1242dc:	1000005a */ 	beqz	$zero,.NB0f124448
/*  f1242e0:	8f220000 */ 	lw	$v0,0x0($t9)
.NB0f1242e4:
/*  f1242e4:	10000058 */ 	beqz	$zero,.NB0f124448
/*  f1242e8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1242ec:
/*  f1242ec:	1420ffcb */ 	bnez	$at,.NB0f12421c
/*  f1242f0:	26100010 */ 	addiu	$s0,$s0,0x10
.NB0f1242f4:
/*  f1242f4:	0fc0786c */ 	jal	getNumChrSlots
/*  f1242f8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1242fc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f124300:	18400039 */ 	blez	$v0,.NB0f1243e8
/*  f124304:	00009025 */ 	or	$s2,$zero,$zero
/*  f124308:	0002b0c0 */ 	sll	$s6,$v0,0x3
/*  f12430c:	02c2b023 */ 	subu	$s6,$s6,$v0
/*  f124310:	0016b080 */ 	sll	$s6,$s6,0x2
/*  f124314:	02c2b023 */ 	subu	$s6,$s6,$v0
/*  f124318:	0016b080 */ 	sll	$s6,$s6,0x2
/*  f12431c:	02c2b021 */ 	addu	$s6,$s6,$v0
/*  f124320:	3c178006 */ 	lui	$s7,0x8006
/*  f124324:	26f74e98 */ 	addiu	$s7,$s7,0x4e98
/*  f124328:	0016b0c0 */ 	sll	$s6,$s6,0x3
/*  f12432c:	00009825 */ 	or	$s3,$zero,$zero
/*  f124330:	241e0005 */ 	addiu	$s8,$zero,0x5
/*  f124334:	27b4005c */ 	addiu	$s4,$sp,0x5c
/*  f124338:	8ef80000 */ 	lw	$t8,0x0($s7)
.NB0f12433c:
/*  f12433c:	02788021 */ 	addu	$s0,$s3,$t8
/*  f124340:	8e080020 */ 	lw	$t0,0x20($s0)
/*  f124344:	51000025 */ 	beqzl	$t0,.NB0f1243dc
/*  f124348:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f12434c:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f124350:	50400022 */ 	beqzl	$v0,.NB0f1243dc
/*  f124354:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f124358:	90490001 */ 	lbu	$t1,0x1($v0)
/*  f12435c:	312a0080 */ 	andi	$t2,$t1,0x80
/*  f124360:	5540001e */ 	bnezl	$t2,.NB0f1243dc
/*  f124364:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f124368:	820b0007 */ 	lb	$t3,0x7($s0)
/*  f12436c:	57cb001b */ 	bnel	$s8,$t3,.NB0f1243dc
/*  f124370:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f124374:	8e0c0030 */ 	lw	$t4,0x30($s0)
/*  f124378:	2a410006 */ 	slti	$at,$s2,0x6
/*  f12437c:	55800017 */ 	bnezl	$t4,.NB0f1243dc
/*  f124380:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f124384:	10200005 */ 	beqz	$at,.NB0f12439c
/*  f124388:	00126880 */ 	sll	$t5,$s2,0x2
/*  f12438c:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f124390:	add00000 */ 	sw	$s0,0x0($t6)
/*  f124394:	10000010 */ 	beqz	$zero,.NB0f1243d8
/*  f124398:	26520001 */ 	addiu	$s2,$s2,0x1
.NB0f12439c:
/*  f12439c:	0c004d84 */ 	jal	random
/*  f1243a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1243a4:	0052001b */ 	divu	$zero,$v0,$s2
/*  f1243a8:	00001810 */ 	mfhi	$v1
/*  f1243ac:	00037880 */ 	sll	$t7,$v1,0x2
/*  f1243b0:	16400002 */ 	bnez	$s2,.NB0f1243bc
/*  f1243b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1243b8:	0007000d */ 	break	0x7
.NB0f1243bc:
/*  f1243bc:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f1243c0:	00608825 */ 	or	$s1,$v1,$zero
/*  f1243c4:	0fc0f140 */ 	jal	chrEnableReap
/*  f1243c8:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f1243cc:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f1243d0:	02984021 */ 	addu	$t0,$s4,$t8
/*  f1243d4:	ad100000 */ 	sw	$s0,0x0($t0)
.NB0f1243d8:
/*  f1243d8:	26730368 */ 	addiu	$s3,$s3,0x368
.NB0f1243dc:
/*  f1243dc:	0276082a */ 	slt	$at,$s3,$s6
/*  f1243e0:	5420ffd6 */ 	bnezl	$at,.NB0f12433c
/*  f1243e4:	8ef80000 */ 	lw	$t8,0x0($s7)
.NB0f1243e8:
/*  f1243e8:	00128843 */ 	sra	$s1,$s2,0x1
/*  f1243ec:	12200015 */ 	beqz	$s1,.NB0f124444
/*  f1243f0:	27b4005c */ 	addiu	$s4,$sp,0x5c
.NB0f1243f4:
/*  f1243f4:	0c004d84 */ 	jal	random
/*  f1243f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1243fc:	0052001b */ 	divu	$zero,$v0,$s2
/*  f124400:	00001810 */ 	mfhi	$v1
/*  f124404:	00034880 */ 	sll	$t1,$v1,0x2
/*  f124408:	02895021 */ 	addu	$t2,$s4,$t1
/*  f12440c:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f124410:	16400002 */ 	bnez	$s2,.NB0f12441c
/*  f124414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f124418:	0007000d */ 	break	0x7
.NB0f12441c:
/*  f12441c:	00602825 */ 	or	$a1,$v1,$zero
/*  f124420:	11600006 */ 	beqz	$t3,.NB0f12443c
/*  f124424:	00036080 */ 	sll	$t4,$v1,0x2
/*  f124428:	028c8021 */ 	addu	$s0,$s4,$t4
/*  f12442c:	0fc0f140 */ 	jal	chrEnableReap
/*  f124430:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f124434:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f124438:	2631ffff */ 	addiu	$s1,$s1,-1
.NB0f12443c:
/*  f12443c:	1620ffed */ 	bnez	$s1,.NB0f1243f4
/*  f124440:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f124444:
/*  f124444:	00001025 */ 	or	$v0,$zero,$zero
.NB0f124448:
/*  f124448:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f12444c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f124450:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f124454:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f124458:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f12445c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f124460:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f124464:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f124468:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f12446c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f124470:	03e00008 */ 	jr	$ra
/*  f124474:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#endif

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
