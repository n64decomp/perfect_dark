#include <ultra64.h>
#include <n_libaudio.h>
#include "constants.h"
#include "game/music.h"
#include "game/game_176080.h"
#include "game/stagemusic.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/music.h"
#include "lib/lib_39c80.h"
#include "data.h"
#include "types.h"

#define RESULT_FAIL     0
#define RESULT_OK_NEXT  1
#define RESULT_OK_BREAK 2

const u8 var70053ca0[] = {0, 0, 0, 0, 0, 5};

s32 g_MusicNextAmbientTick240 = -1;

s32 musicHandlePlayEvent(struct musicevent *event, s32 result)
{
	s32 i;
	u8 value;
	s32 j;
	s32 index;

	switch (event->tracktype) {
	case TRACKTYPE_NONE:
		osSyncPrintf("OFF");
		break;
	case TRACKTYPE_PRIMARY:
		osSyncPrintf("LEVELTUNE");
		break;
	case TRACKTYPE_NRG:
		osSyncPrintf("NRGTUNE");
		break;
	case TRACKTYPE_MENU:
		osSyncPrintf("WATCHTUNE");
		break;
	case TRACKTYPE_DEATH:
		osSyncPrintf("MPDEATHTUNE");
		break;
	case TRACKTYPE_AMBIENT:
		osSyncPrintf("AMBIENCE");
		break;
	}

	osSyncPrintf(" after %d %s\n", event->failcount, event->failcount != 1 ? "Attempts" : "Attempt");

	// Check if this tracktype is currently in use. If it is then that's
	// an error - the caller should have stopped the existing track first.
	for (i = 0; i < 3; i++) {
		if (event->tracktype == g_SeqChannels[i].tracktype && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
			value = event->tracktype == TRACKTYPE_AMBIENT ? 24 : 32;

			for (j = 0; j < 16; j++) {
				func00039e5c(g_SeqInstances[i].seqp, j, 0xff, value);
				osSyncPrintf("MUSIC(Play) : Unpaused midi channel %d for state %d\n", j, event->tracktype);
			}

			g_SeqChannels[i].keepafterfade = false;
			g_SeqChannels[i].unk0c = 0;

			event->eventtype = 0;
			result = RESULT_OK_BREAK;
			break;
		}
	}

	if (result == RESULT_FAIL) {
		// Find an unused channel
		for (i = 0; i < 3; i++) {
			/**
			 * @bug: When adding a new track, the seqp's state remains at AL_STOPPED
			 * and is only changed to AL_PLAYING once the audio thread has run.
			 * Scheduling two sequences in quick succession will cause it to choose
			 * the same sequence player if the audio thread hasn't run between
			 * the two calls and updated the state.
			 *
			 * With IDO, the compiled code is so inefficient that the audio thread
			 * is likely to run between two consecutive calls. However it does
			 * still happen occasionally. Eg. sometimes when unpausing the stage's
			 * main theme does not resume.
			 *
			 * For GCC, it's more likely to occur, so we introduce a new state:
			 * AL_STARTING. This is assigned to the sequence player in seqPlay.
			 */
			if (n_alCSPGetState(g_SeqInstances[i].seqp) == AL_STOPPED) {
				osSyncPrintf("MUSIC(Play) : Starting, Guid=%u, Midi=%d, Tune=%d\n", event->id, 0, event->tracktype);

				if (seqPlay(&g_SeqInstances[i], event->tracknum)) {
					seqSetVolume(&g_SeqInstances[i], event->volume);

					g_SeqChannels[i].tracktype = event->tracktype;
					g_SeqChannels[i].inuse = true;
					g_SeqChannels[i].keepafterfade = false;
					g_SeqChannels[i].unk0c = 0;

					osSyncPrintf("MUSIC(Play) : Done\n");

					result = RESULT_OK_BREAK;
				}
				break;
			}
		}

		if (result == RESULT_FAIL) {
			index = -1;

			for (i = 0; i < 3; i++) {
				if ((g_SeqChannels[i].tracktype == TRACKTYPE_NONE || event->tracktype == g_SeqChannels[i].tracktype)
						&& n_alCSPGetState(g_SeqInstances[i].seqp) != AL_STOPPED) {
					index = i;
					osSyncPrintf("MUSIC(Play) : About to dump the fading channel %d as a same state play request is waiting\n", index);
					break;
				}
			}

			if (index == -1) {
				if (event->failcount >= 3) {
					for (i = 0; i < 3; i++) {
						if (g_SeqChannels[i].tracktype == TRACKTYPE_AMBIENT
								&& n_alCSPGetState(g_SeqInstances[i].seqp) != AL_STOPPED) {
							index = i;
							osSyncPrintf("MUSIC(Play) : About to dump the ambience channel %d\n", index);
							osSyncPrintf("MUSIC(Play) : Reason : A play request is waiting - State = %d\n", event->tracktype);
							break;
						}
					}
				}
			}

			if (index != -1) {
				n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[index].seqp);

				g_SeqChannels[index].tracktype = TRACKTYPE_NONE;
				g_SeqChannels[index].inuse = false;
				g_SeqChannels[index].keepafterfade = false;
				g_SeqChannels[index].unk0c = 0;
			} else {
				event->failcount++;
				osSyncPrintf("MUSIC(Play) : SERIOUS -> Out of MIDI channels - Attempt = %d\n", event->failcount);

				if (event->failcount >= 6) {
					osSyncPrintf("MUSIC(Play) : SERIOUS -> Tried %d times to play tune : Giving up\n", event->failcount);
					result = RESULT_OK_BREAK;
				}
			}
		}
	}

	return result;
}

const char var70053ee0[] = "MUSIC : Fading to pause\n";
const char var70053efc[] = "Music : Update Rate = %d";
const char var70053f18[] = "MUSIC TICK : Queue size = %d\n";
const char var70053f38[] = "MUSIC : Tick -> Channel %d (State=%d) has faded to stop : Dumping\n";
const char var70053f7c[] = "MUSIC : WARNING -> Force fade termination\n";
const char var70053fa8[] = "MUSIC TICK : Job Guid = %u\n";

s32 musicHandleStopEvent(struct musicevent *event, s32 result)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		if (event->tracktype == g_SeqChannels[i].tracktype) {
			n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

			g_SeqChannels[i].tracktype = TRACKTYPE_NONE;
			g_SeqChannels[i].inuse = false;
			g_SeqChannels[i].keepafterfade = false;
			g_SeqChannels[i].unk0c = 0;

			break;
		}
	}

	return RESULT_OK_NEXT;
}

s32 musicHandleFadeEvent(struct musicevent *event, s32 result)
{
	s32 i;
	s32 j;

	for (i = 0; i < 3; i++) {
		if (event->tracktype == g_SeqChannels[i].tracktype && g_SeqChannels[i].inuse) {
			for (j = 0; j < 16; j++) {
				func00039e5c(g_SeqInstances[i].seqp, j, var70053ca0[event->tracktype], 32);
			}

			g_SeqChannels[i].inuse = event->keepafterfade;
			g_SeqChannels[i].keepafterfade = event->keepafterfade;
			g_SeqChannels[i].unk0c = g_SeqInstances[i].seqp->chanState[0].unk0d;
		}
	}

	return RESULT_OK_NEXT;
}

s32 musicHandleStopAllEvent(s32 result)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

		g_SeqChannels[i].tracktype = 0;
		g_SeqChannels[i].inuse = false;
		g_SeqChannels[i].keepafterfade = false;
		g_SeqChannels[i].unk0c = 0;
	}

	return RESULT_OK_NEXT;
}

#if VERSION >= VERSION_NTSC_1_0
s32 musicHandleSetIntervalEvent(struct musicevent *event, s32 result)
{
	g_MusicInterval240 = event->timer240;
	return RESULT_OK_NEXT;
}
#endif

#if MATCHING
#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel musicTickEvents
.late_rodata
glabel var70053fdc
.word musicTickEvents+0x324
glabel var70053fe0
.word musicTickEvents+0x338
glabel var70053fe4
.word musicTickEvents+0x34c
glabel var70053fe8
.word musicTickEvents+0x360
glabel var70053fec
.word musicTickEvents+0x370
.text
/*    1190c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    11910:	3c0e8006 */ 	lui	$t6,%hi(g_SndDisabled)
/*    11914:	8dcedda0 */ 	lw	$t6,%lo(g_SndDisabled)($t6)
/*    11918:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    1191c:	afb30020 */ 	sw	$s3,0x20($sp)
/*    11920:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    11924:	afb10018 */ 	sw	$s1,0x18($sp)
/*    11928:	15c0010f */ 	bnez	$t6,.L00011d68
/*    1192c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    11930:	3c138008 */ 	lui	$s3,%hi(g_MusicEventQueueLength)
/*    11934:	3c10800b */ 	lui	$s0,%hi(g_SeqChannels)
/*    11938:	267340c4 */ 	addiu	$s3,$s3,%lo(g_MusicEventQueueLength)
/*    1193c:	2610aa38 */ 	addiu	$s0,$s0,%lo(g_SeqChannels)
/*    11940:	00008825 */ 	or	$s1,$zero,$zero
/*    11944:	24120001 */ 	addiu	$s2,$zero,0x1
.L00011948:
/*    11948:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    1194c:	0011c140 */ 	sll	$t8,$s1,0x5
/*    11950:	0311c021 */ 	addu	$t8,$t8,$s1
/*    11954:	15e00023 */ 	bnez	$t7,.L000119e4
/*    11958:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    1195c:	3c198009 */ 	lui	$t9,%hi(g_SeqInstances)
/*    11960:	27394ed8 */ 	addiu	$t9,$t9,%lo(g_SeqInstances)
/*    11964:	03191821 */ 	addu	$v1,$t8,$t9
/*    11968:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    1196c:	0c00e344 */ 	jal	n_alCSPGetState
/*    11970:	afa30028 */ 	sw	$v1,0x28($sp)
/*    11974:	1452001b */ 	bne	$v0,$s2,.L000119e4
/*    11978:	8fa30028 */ 	lw	$v1,0x28($sp)
/*    1197c:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    11980:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*    11984:	3c0e7005 */ 	lui	$t6,%hi(var70053ca0)
/*    11988:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    1198c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    11990:	91ce3ca0 */ 	lbu	$t6,%lo(var70053ca0)($t6)
/*    11994:	9182000d */ 	lbu	$v0,0xd($t4)
/*    11998:	01c2082a */ 	slt	$at,$t6,$v0
/*    1199c:	54200009 */ 	bnezl	$at,.L000119c4
/*    119a0:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    119a4:	0c00e7dc */ 	jal	n_alSeqpStop
/*    119a8:	00000000 */ 	nop
/*    119ac:	ae000000 */ 	sw	$zero,0x0($s0)
/*    119b0:	ae000004 */ 	sw	$zero,0x4($s0)
/*    119b4:	ae000008 */ 	sw	$zero,0x8($s0)
/*    119b8:	1000000a */ 	b	.L000119e4
/*    119bc:	ae00000c */ 	sw	$zero,0xc($s0)
/*    119c0:	8e0f000c */ 	lw	$t7,0xc($s0)
.L000119c4:
/*    119c4:	544f0008 */ 	bnel	$v0,$t7,.L000119e8
/*    119c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*    119cc:	0c00e7dc */ 	jal	n_alSeqpStop
/*    119d0:	00000000 */ 	nop
/*    119d4:	ae000000 */ 	sw	$zero,0x0($s0)
/*    119d8:	ae000004 */ 	sw	$zero,0x4($s0)
/*    119dc:	ae000008 */ 	sw	$zero,0x8($s0)
/*    119e0:	ae00000c */ 	sw	$zero,0xc($s0)
.L000119e4:
/*    119e4:	26310001 */ 	addiu	$s1,$s1,0x1
.L000119e8:
/*    119e8:	2a210003 */ 	slti	$at,$s1,0x3
/*    119ec:	1420ffd6 */ 	bnez	$at,.L00011948
/*    119f0:	26100010 */ 	addiu	$s0,$s0,0x10
/*    119f4:	8e650000 */ 	lw	$a1,0x0($s3)
/*    119f8:	3c19800b */ 	lui	$t9,%hi(g_MusicEventQueue)
/*    119fc:	2739a5d8 */ 	addiu	$t9,$t9,%lo(g_MusicEventQueue)
/*    11a00:	24b1ffff */ 	addiu	$s1,$a1,-1
/*    11a04:	06200046 */ 	bltz	$s1,.L00011b20
/*    11a08:	0011c0c0 */ 	sll	$t8,$s1,0x3
/*    11a0c:	0311c023 */ 	subu	$t8,$t8,$s1
/*    11a10:	0018c080 */ 	sll	$t8,$t8,0x2
/*    11a14:	3c0a800b */ 	lui	$t2,%hi(g_MusicEventQueue)
/*    11a18:	254aa5d8 */ 	addiu	$t2,$t2,%lo(g_MusicEventQueue)
/*    11a1c:	03193021 */ 	addu	$a2,$t8,$t9
/*    11a20:	24100002 */ 	addiu	$s0,$zero,0x2
/*    11a24:	24090004 */ 	addiu	$t1,$zero,0x4
/*    11a28:	24080005 */ 	addiu	$t0,$zero,0x5
/*    11a2c:	24070003 */ 	addiu	$a3,$zero,0x3
.L00011a30:
/*    11a30:	94cc0012 */ 	lhu	$t4,0x12($a2)
/*    11a34:	550c0004 */ 	bnel	$t0,$t4,.L00011a48
/*    11a38:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*    11a3c:	10000034 */ 	b	.L00011b10
/*    11a40:	262bffff */ 	addiu	$t3,$s1,-1
/*    11a44:	8ccd0000 */ 	lw	$t5,0x0($a2)
.L00011a48:
/*    11a48:	262bffff */ 	addiu	$t3,$s1,-1
/*    11a4c:	15a00003 */ 	bnez	$t5,.L00011a5c
/*    11a50:	00000000 */ 	nop
/*    11a54:	1000002e */ 	b	.L00011b10
/*    11a58:	262bffff */ 	addiu	$t3,$s1,-1
.L00011a5c:
/*    11a5c:	0560002c */ 	bltz	$t3,.L00011b10
/*    11a60:	01601025 */ 	or	$v0,$t3,$zero
/*    11a64:	000270c0 */ 	sll	$t6,$v0,0x3
/*    11a68:	01c27023 */ 	subu	$t6,$t6,$v0
/*    11a6c:	3c0f800b */ 	lui	$t7,%hi(g_MusicEventQueue)
/*    11a70:	25efa5d8 */ 	addiu	$t7,$t7,%lo(g_MusicEventQueue)
/*    11a74:	000e7080 */ 	sll	$t6,$t6,0x2
/*    11a78:	01cf2821 */ 	addu	$a1,$t6,$t7
/*    11a7c:	94c30012 */ 	lhu	$v1,0x12($a2)
.L00011a80:
/*    11a80:	55230004 */ 	bnel	$t1,$v1,.L00011a94
/*    11a84:	94a40012 */ 	lhu	$a0,0x12($a1)
/*    11a88:	1000001d */ 	b	.L00011b00
/*    11a8c:	aca00000 */ 	sw	$zero,0x0($a1)
/*    11a90:	94a40012 */ 	lhu	$a0,0x12($a1)
.L00011a94:
/*    11a94:	5104001b */ 	beql	$t0,$a0,.L00011b04
/*    11a98:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11a9c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*    11aa0:	50400018 */ 	beqzl	$v0,.L00011b04
/*    11aa4:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11aa8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*    11aac:	57020015 */ 	bnel	$t8,$v0,.L00011b04
/*    11ab0:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11ab4:	10720009 */ 	beq	$v1,$s2,.L00011adc
/*    11ab8:	00000000 */ 	nop
/*    11abc:	10700005 */ 	beq	$v1,$s0,.L00011ad4
/*    11ac0:	00000000 */ 	nop
/*    11ac4:	1067000b */ 	beq	$v1,$a3,.L00011af4
/*    11ac8:	00000000 */ 	nop
/*    11acc:	1000000d */ 	b	.L00011b04
/*    11ad0:	24a5ffe4 */ 	addiu	$a1,$a1,-28
.L00011ad4:
/*    11ad4:	1000000a */ 	b	.L00011b00
/*    11ad8:	aca00000 */ 	sw	$zero,0x0($a1)
.L00011adc:
/*    11adc:	10920003 */ 	beq	$a0,$s2,.L00011aec
/*    11ae0:	00000000 */ 	nop
/*    11ae4:	54870007 */ 	bnel	$a0,$a3,.L00011b04
/*    11ae8:	24a5ffe4 */ 	addiu	$a1,$a1,-28
.L00011aec:
/*    11aec:	10000004 */ 	b	.L00011b00
/*    11af0:	aca00000 */ 	sw	$zero,0x0($a1)
.L00011af4:
/*    11af4:	54e40003 */ 	bnel	$a3,$a0,.L00011b04
/*    11af8:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11afc:	aca00000 */ 	sw	$zero,0x0($a1)
.L00011b00:
/*    11b00:	24a5ffe4 */ 	addiu	$a1,$a1,-28
.L00011b04:
/*    11b04:	00aa082b */ 	sltu	$at,$a1,$t2
/*    11b08:	5020ffdd */ 	beqzl	$at,.L00011a80
/*    11b0c:	94c30012 */ 	lhu	$v1,0x12($a2)
.L00011b10:
/*    11b10:	01608825 */ 	or	$s1,$t3,$zero
/*    11b14:	0561ffc6 */ 	bgez	$t3,.L00011a30
/*    11b18:	24c6ffe4 */ 	addiu	$a2,$a2,-28
/*    11b1c:	8e650000 */ 	lw	$a1,0x0($s3)
.L00011b20:
/*    11b20:	24100002 */ 	addiu	$s0,$zero,0x2
/*    11b24:	00008825 */ 	or	$s1,$zero,$zero
/*    11b28:	18a00020 */ 	blez	$a1,.L00011bac
/*    11b2c:	00001025 */ 	or	$v0,$zero,$zero
/*    11b30:	3c06800b */ 	lui	$a2,%hi(g_MusicEventQueue)
/*    11b34:	3c12800b */ 	lui	$s2,%hi(g_MusicEventQueue)
/*    11b38:	2652a5d8 */ 	addiu	$s2,$s2,%lo(g_MusicEventQueue)
/*    11b3c:	24c6a5d8 */ 	addiu	$a2,$a2,%lo(g_MusicEventQueue)
/*    11b40:	2403001c */ 	addiu	$v1,$zero,0x1c
.L00011b44:
/*    11b44:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    11b48:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11b4c:	53200015 */ 	beqzl	$t9,.L00011ba4
/*    11b50:	0225082a */ 	slt	$at,$s1,$a1
/*    11b54:	00430019 */ 	multu	$v0,$v1
/*    11b58:	8cc10000 */ 	lw	$at,0x0($a2)
/*    11b5c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    11b60:	00006012 */ 	mflo	$t4
/*    11b64:	024c6821 */ 	addu	$t5,$s2,$t4
/*    11b68:	ada10000 */ 	sw	$at,0x0($t5)
/*    11b6c:	8ccf0004 */ 	lw	$t7,0x4($a2)
/*    11b70:	adaf0004 */ 	sw	$t7,0x4($t5)
/*    11b74:	8cc10008 */ 	lw	$at,0x8($a2)
/*    11b78:	ada10008 */ 	sw	$at,0x8($t5)
/*    11b7c:	8ccf000c */ 	lw	$t7,0xc($a2)
/*    11b80:	adaf000c */ 	sw	$t7,0xc($t5)
/*    11b84:	8cc10010 */ 	lw	$at,0x10($a2)
/*    11b88:	ada10010 */ 	sw	$at,0x10($t5)
/*    11b8c:	8ccf0014 */ 	lw	$t7,0x14($a2)
/*    11b90:	adaf0014 */ 	sw	$t7,0x14($t5)
/*    11b94:	8cc10018 */ 	lw	$at,0x18($a2)
/*    11b98:	ada10018 */ 	sw	$at,0x18($t5)
/*    11b9c:	8e650000 */ 	lw	$a1,0x0($s3)
/*    11ba0:	0225082a */ 	slt	$at,$s1,$a1
.L00011ba4:
/*    11ba4:	1420ffe7 */ 	bnez	$at,.L00011b44
/*    11ba8:	24c6001c */ 	addiu	$a2,$a2,0x1c
.L00011bac:
/*    11bac:	ae620000 */ 	sw	$v0,0x0($s3)
/*    11bb0:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    11bb4:	8c6340e0 */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
/*    11bb8:	3c12800b */ 	lui	$s2,%hi(g_MusicEventQueue)
/*    11bbc:	2652a5d8 */ 	addiu	$s2,$s2,%lo(g_MusicEventQueue)
/*    11bc0:	10600006 */ 	beqz	$v1,.L00011bdc
/*    11bc4:	3c188008 */ 	lui	$t8,%hi(g_MusicSleepRemaining240)
/*    11bc8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x40)
/*    11bcc:	8f39a000 */ 	lw	$t9,%lo(g_Vars+0x40)($t9)
/*    11bd0:	8f1840e4 */ 	lw	$t8,%lo(g_MusicSleepRemaining240)($t8)
/*    11bd4:	0319082a */ 	slt	$at,$t8,$t9
/*    11bd8:	10200058 */ 	beqz	$at,.L00011d3c
.L00011bdc:
/*    11bdc:	3c018008 */ 	lui	$at,%hi(g_MusicSleepRemaining240)
/*    11be0:	ac2340e4 */ 	sw	$v1,%lo(g_MusicSleepRemaining240)($at)
/*    11be4:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*    11be8:	11800054 */ 	beqz	$t4,.L00011d3c
.L00011bec:
/*    11bec:	3c0e800b */ 	lui	$t6,%hi(g_MusicEventQueue+0x18)
/*    11bf0:	95cea5f0 */ 	lhu	$t6,%lo(g_MusicEventQueue+0x18)($t6)
/*    11bf4:	3c01800b */ 	lui	$at,%hi(g_MusicEventQueue+0x18)
/*    11bf8:	3c0f800b */ 	lui	$t7,%hi(g_MusicEventQueue+0x12)
/*    11bfc:	25cd0001 */ 	addiu	$t5,$t6,0x1
/*    11c00:	a42da5f0 */ 	sh	$t5,%lo(g_MusicEventQueue+0x18)($at)
/*    11c04:	95efa5ea */ 	lhu	$t7,%lo(g_MusicEventQueue+0x12)($t7)
/*    11c08:	00002025 */ 	or	$a0,$zero,$zero
/*    11c0c:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    11c10:	2f010005 */ 	sltiu	$at,$t8,0x5
/*    11c14:	1020001d */ 	beqz	$at,.L00011c8c
/*    11c18:	0018c080 */ 	sll	$t8,$t8,0x2
/*    11c1c:	3c017005 */ 	lui	$at,%hi(var70053fdc)
/*    11c20:	00380821 */ 	addu	$at,$at,$t8
/*    11c24:	8c383fdc */ 	lw	$t8,%lo(var70053fdc)($at)
/*    11c28:	03000008 */ 	jr	$t8
/*    11c2c:	00000000 */ 	nop
/*    11c30:	02402025 */ 	or	$a0,$s2,$zero
/*    11c34:	0c004508 */ 	jal	musicHandlePlayEvent
/*    11c38:	00002825 */ 	or	$a1,$zero,$zero
/*    11c3c:	10000013 */ 	b	.L00011c8c
/*    11c40:	00402025 */ 	or	$a0,$v0,$zero
/*    11c44:	02402025 */ 	or	$a0,$s2,$zero
/*    11c48:	0c0045c0 */ 	jal	musicHandleStopEvent
/*    11c4c:	00002825 */ 	or	$a1,$zero,$zero
/*    11c50:	1000000e */ 	b	.L00011c8c
/*    11c54:	00402025 */ 	or	$a0,$v0,$zero
/*    11c58:	02402025 */ 	or	$a0,$s2,$zero
/*    11c5c:	0c0045e0 */ 	jal	musicHandleFadeEvent
/*    11c60:	00002825 */ 	or	$a1,$zero,$zero
/*    11c64:	10000009 */ 	b	.L00011c8c
/*    11c68:	00402025 */ 	or	$a0,$v0,$zero
/*    11c6c:	0c004621 */ 	jal	musicHandleStopAllEvent
/*    11c70:	00002025 */ 	or	$a0,$zero,$zero
/*    11c74:	10000005 */ 	b	.L00011c8c
/*    11c78:	00402025 */ 	or	$a0,$v0,$zero
/*    11c7c:	02402025 */ 	or	$a0,$s2,$zero
/*    11c80:	0c00463d */ 	jal	musicHandleSetIntervalEvent
/*    11c84:	00002825 */ 	or	$a1,$zero,$zero
/*    11c88:	00402025 */ 	or	$a0,$v0,$zero
.L00011c8c:
/*    11c8c:	10800024 */ 	beqz	$a0,.L00011d20
/*    11c90:	3c06800b */ 	lui	$a2,%hi(g_MusicEventQueue)
/*    11c94:	8e790000 */ 	lw	$t9,0x0($s3)
/*    11c98:	24c6a5d8 */ 	addiu	$a2,$a2,%lo(g_MusicEventQueue)
/*    11c9c:	3c0e800b */ 	lui	$t6,%hi(g_MusicEventQueue+0x1c)
/*    11ca0:	272cffff */ 	addiu	$t4,$t9,-1
/*    11ca4:	ae6c0000 */ 	sw	$t4,0x0($s3)
/*    11ca8:	19800019 */ 	blez	$t4,.L00011d10
/*    11cac:	01802825 */ 	or	$a1,$t4,$zero
/*    11cb0:	000c68c0 */ 	sll	$t5,$t4,0x3
/*    11cb4:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    11cb8:	000d6880 */ 	sll	$t5,$t5,0x2
/*    11cbc:	25c2a5f4 */ 	addiu	$v0,$t6,%lo(g_MusicEventQueue+0x1c)
/*    11cc0:	01a21821 */ 	addu	$v1,$t5,$v0
/*    11cc4:	8c410000 */ 	lw	$at,0x0($v0)
.L00011cc8:
/*    11cc8:	2442001c */ 	addiu	$v0,$v0,0x1c
/*    11ccc:	24c6001c */ 	addiu	$a2,$a2,0x1c
/*    11cd0:	acc1ffe4 */ 	sw	$at,-0x1c($a2)
/*    11cd4:	8c58ffe8 */ 	lw	$t8,-0x18($v0)
/*    11cd8:	acd8ffe8 */ 	sw	$t8,-0x18($a2)
/*    11cdc:	8c41ffec */ 	lw	$at,-0x14($v0)
/*    11ce0:	acc1ffec */ 	sw	$at,-0x14($a2)
/*    11ce4:	8c58fff0 */ 	lw	$t8,-0x10($v0)
/*    11ce8:	acd8fff0 */ 	sw	$t8,-0x10($a2)
/*    11cec:	8c41fff4 */ 	lw	$at,-0xc($v0)
/*    11cf0:	acc1fff4 */ 	sw	$at,-0xc($a2)
/*    11cf4:	8c58fff8 */ 	lw	$t8,-0x8($v0)
/*    11cf8:	acd8fff8 */ 	sw	$t8,-0x8($a2)
/*    11cfc:	8c41fffc */ 	lw	$at,-0x4($v0)
/*    11d00:	acc1fffc */ 	sw	$at,-0x4($a2)
/*    11d04:	0043082b */ 	sltu	$at,$v0,$v1
/*    11d08:	5420ffef */ 	bnezl	$at,.L00011cc8
/*    11d0c:	8c410000 */ 	lw	$at,0x0($v0)
.L00011d10:
/*    11d10:	14900006 */ 	bne	$a0,$s0,.L00011d2c
/*    11d14:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    11d18:	10000008 */ 	b	.L00011d3c
/*    11d1c:	8c6340e0 */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
.L00011d20:
/*    11d20:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    11d24:	10000005 */ 	b	.L00011d3c
/*    11d28:	8c6340e0 */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
.L00011d2c:
/*    11d2c:	14a0ffaf */ 	bnez	$a1,.L00011bec
/*    11d30:	00000000 */ 	nop
/*    11d34:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    11d38:	8c6340e0 */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
.L00011d3c:
/*    11d3c:	10600009 */ 	beqz	$v1,.L00011d64
/*    11d40:	3c018008 */ 	lui	$at,%hi(g_MusicSleepRemaining240)
/*    11d44:	3c198008 */ 	lui	$t9,%hi(g_MusicSleepRemaining240)
/*    11d48:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x40)
/*    11d4c:	8d8ca000 */ 	lw	$t4,%lo(g_Vars+0x40)($t4)
/*    11d50:	8f3940e4 */ 	lw	$t9,%lo(g_MusicSleepRemaining240)($t9)
/*    11d54:	3c018008 */ 	lui	$at,%hi(g_MusicSleepRemaining240)
/*    11d58:	032c6823 */ 	subu	$t5,$t9,$t4
/*    11d5c:	10000002 */ 	b	.L00011d68
/*    11d60:	ac2d40e4 */ 	sw	$t5,%lo(g_MusicSleepRemaining240)($at)
.L00011d64:
/*    11d64:	ac2040e4 */ 	sw	$zero,%lo(g_MusicSleepRemaining240)($at)
.L00011d68:
/*    11d68:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    11d6c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    11d70:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    11d74:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    11d78:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    11d7c:	03e00008 */ 	jr	$ra
/*    11d80:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#else
GLOBAL_ASM(
glabel musicTickEvents
/*    11cb4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    11cb8:	3c0e8006 */ 	lui	$t6,%hi(g_SndDisabled)
/*    11cbc:	8dcef6c0 */ 	lw	$t6,%lo(g_SndDisabled)($t6)
/*    11cc0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    11cc4:	afb60030 */ 	sw	$s6,0x30($sp)
/*    11cc8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    11ccc:	afb40028 */ 	sw	$s4,0x28($sp)
/*    11cd0:	afb30024 */ 	sw	$s3,0x24($sp)
/*    11cd4:	afb20020 */ 	sw	$s2,0x20($sp)
/*    11cd8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    11cdc:	15c00106 */ 	bnez	$t6,.NB000120f8
/*    11ce0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    11ce4:	3c168008 */ 	lui	$s6,%hi(g_MusicEventQueueLength)
/*    11ce8:	3c10800b */ 	lui	$s0,%hi(g_SeqChannels)
/*    11cec:	3c157005 */ 	lui	$s5,%hi(var70053ca0)
/*    11cf0:	3c138009 */ 	lui	$s3,%hi(g_SeqInstances)
/*    11cf4:	26d66944 */ 	addiu	$s6,$s6,%lo(g_MusicEventQueueLength)
/*    11cf8:	26737e58 */ 	addiu	$s3,$s3,%lo(g_SeqInstances)
/*    11cfc:	26b553b0 */ 	addiu	$s5,$s5,%lo(var70053ca0)
/*    11d00:	2610f2e8 */ 	addiu	$s0,$s0,%lo(g_SeqChannels)
/*    11d04:	00008825 */ 	or	$s1,$zero,$zero
/*    11d08:	24140108 */ 	addiu	$s4,$zero,0x108
/*    11d0c:	24120001 */ 	addiu	$s2,$zero,0x1
.NB00011d10:
/*    11d10:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    11d14:	55e00023 */ 	bnezl	$t7,.NB00011da4
/*    11d18:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11d1c:	02340019 */ 	multu	$s1,$s4
/*    11d20:	0000c012 */ 	mflo	$t8
/*    11d24:	02781821 */ 	addu	$v1,$s3,$t8
/*    11d28:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    11d2c:	0c00e838 */ 	jal	n_alCSPGetState
/*    11d30:	afa30038 */ 	sw	$v1,0x38($sp)
/*    11d34:	1452001a */ 	bne	$v0,$s2,.NB00011da0
/*    11d38:	8fa30038 */ 	lw	$v1,0x38($sp)
/*    11d3c:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    11d40:	8e080000 */ 	lw	$t0,0x0($s0)
/*    11d44:	8c990060 */ 	lw	$t9,0x60($a0)
/*    11d48:	02a84821 */ 	addu	$t1,$s5,$t0
/*    11d4c:	912a0000 */ 	lbu	$t2,0x0($t1)
/*    11d50:	9322000d */ 	lbu	$v0,0xd($t9)
/*    11d54:	0142082a */ 	slt	$at,$t2,$v0
/*    11d58:	54200009 */ 	bnezl	$at,.NB00011d80
/*    11d5c:	8e0b000c */ 	lw	$t3,0xc($s0)
/*    11d60:	0c00ecd0 */ 	jal	n_alSeqpStop
/*    11d64:	00000000 */ 	sll	$zero,$zero,0x0
/*    11d68:	ae000000 */ 	sw	$zero,0x0($s0)
/*    11d6c:	ae000004 */ 	sw	$zero,0x4($s0)
/*    11d70:	ae000008 */ 	sw	$zero,0x8($s0)
/*    11d74:	1000000a */ 	beqz	$zero,.NB00011da0
/*    11d78:	ae00000c */ 	sw	$zero,0xc($s0)
/*    11d7c:	8e0b000c */ 	lw	$t3,0xc($s0)
.NB00011d80:
/*    11d80:	544b0008 */ 	bnel	$v0,$t3,.NB00011da4
/*    11d84:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11d88:	0c00ecd0 */ 	jal	n_alSeqpStop
/*    11d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    11d90:	ae000000 */ 	sw	$zero,0x0($s0)
/*    11d94:	ae000004 */ 	sw	$zero,0x4($s0)
/*    11d98:	ae000008 */ 	sw	$zero,0x8($s0)
/*    11d9c:	ae00000c */ 	sw	$zero,0xc($s0)
.NB00011da0:
/*    11da0:	26310001 */ 	addiu	$s1,$s1,0x1
.NB00011da4:
/*    11da4:	2a210003 */ 	slti	$at,$s1,0x3
/*    11da8:	1420ffd9 */ 	bnez	$at,.NB00011d10
/*    11dac:	26100010 */ 	addiu	$s0,$s0,0x10
/*    11db0:	8ec60000 */ 	lw	$a2,0x0($s6)
/*    11db4:	3c0d800b */ 	lui	$t5,%hi(g_MusicEventQueue)
/*    11db8:	25adee88 */ 	addiu	$t5,$t5,%lo(g_MusicEventQueue)
/*    11dbc:	24d1ffff */ 	addiu	$s1,$a2,-1
/*    11dc0:	0620003f */ 	bltz	$s1,.NB00011ec0
/*    11dc4:	001160c0 */ 	sll	$t4,$s1,0x3
/*    11dc8:	01916023 */ 	subu	$t4,$t4,$s1
/*    11dcc:	000c6080 */ 	sll	$t4,$t4,0x2
/*    11dd0:	3c06800b */ 	lui	$a2,%hi(g_MusicEventQueue)
/*    11dd4:	24c6ee88 */ 	addiu	$a2,$a2,%lo(g_MusicEventQueue)
/*    11dd8:	018d2821 */ 	addu	$a1,$t4,$t5
/*    11ddc:	24140004 */ 	addiu	$s4,$zero,0x4
/*    11de0:	24130002 */ 	addiu	$s3,$zero,0x2
/*    11de4:	24100003 */ 	addiu	$s0,$zero,0x3
.NB00011de8:
/*    11de8:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    11dec:	2627ffff */ 	addiu	$a3,$s1,-1
/*    11df0:	15c00003 */ 	bnez	$t6,.NB00011e00
/*    11df4:	00000000 */ 	sll	$zero,$zero,0x0
/*    11df8:	1000002d */ 	beqz	$zero,.NB00011eb0
/*    11dfc:	2627ffff */ 	addiu	$a3,$s1,-1
.NB00011e00:
/*    11e00:	04e0002b */ 	bltz	$a3,.NB00011eb0
/*    11e04:	00e01025 */ 	or	$v0,$a3,$zero
/*    11e08:	000278c0 */ 	sll	$t7,$v0,0x3
/*    11e0c:	01e27823 */ 	subu	$t7,$t7,$v0
/*    11e10:	3c18800b */ 	lui	$t8,%hi(g_MusicEventQueue)
/*    11e14:	2718ee88 */ 	addiu	$t8,$t8,%lo(g_MusicEventQueue)
/*    11e18:	000f7880 */ 	sll	$t7,$t7,0x2
/*    11e1c:	01f82021 */ 	addu	$a0,$t7,$t8
/*    11e20:	94a30012 */ 	lhu	$v1,0x12($a1)
.NB00011e24:
/*    11e24:	56830004 */ 	bnel	$s4,$v1,.NB00011e38
/*    11e28:	8c820000 */ 	lw	$v0,0x0($a0)
/*    11e2c:	1000001c */ 	beqz	$zero,.NB00011ea0
/*    11e30:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e34:	8c820000 */ 	lw	$v0,0x0($a0)
.NB00011e38:
/*    11e38:	5040001a */ 	beqzl	$v0,.NB00011ea4
/*    11e3c:	2484ffe4 */ 	addiu	$a0,$a0,-28
/*    11e40:	8cb90000 */ 	lw	$t9,0x0($a1)
/*    11e44:	57220017 */ 	bnel	$t9,$v0,.NB00011ea4
/*    11e48:	2484ffe4 */ 	addiu	$a0,$a0,-28
/*    11e4c:	5072000a */ 	beql	$v1,$s2,.NB00011e78
/*    11e50:	94820012 */ 	lhu	$v0,0x12($a0)
/*    11e54:	10730005 */ 	beq	$v1,$s3,.NB00011e6c
/*    11e58:	00000000 */ 	sll	$zero,$zero,0x0
/*    11e5c:	5070000d */ 	beql	$v1,$s0,.NB00011e94
/*    11e60:	94880012 */ 	lhu	$t0,0x12($a0)
/*    11e64:	1000000f */ 	beqz	$zero,.NB00011ea4
/*    11e68:	2484ffe4 */ 	addiu	$a0,$a0,-28
.NB00011e6c:
/*    11e6c:	1000000c */ 	beqz	$zero,.NB00011ea0
/*    11e70:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e74:	94820012 */ 	lhu	$v0,0x12($a0)
.NB00011e78:
/*    11e78:	10520003 */ 	beq	$v0,$s2,.NB00011e88
/*    11e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    11e80:	54500008 */ 	bnel	$v0,$s0,.NB00011ea4
/*    11e84:	2484ffe4 */ 	addiu	$a0,$a0,-28
.NB00011e88:
/*    11e88:	10000005 */ 	beqz	$zero,.NB00011ea0
/*    11e8c:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e90:	94880012 */ 	lhu	$t0,0x12($a0)
.NB00011e94:
/*    11e94:	56080003 */ 	bnel	$s0,$t0,.NB00011ea4
/*    11e98:	2484ffe4 */ 	addiu	$a0,$a0,-28
/*    11e9c:	ac800000 */ 	sw	$zero,0x0($a0)
.NB00011ea0:
/*    11ea0:	2484ffe4 */ 	addiu	$a0,$a0,-28
.NB00011ea4:
/*    11ea4:	0086082b */ 	sltu	$at,$a0,$a2
/*    11ea8:	5020ffde */ 	beqzl	$at,.NB00011e24
/*    11eac:	94a30012 */ 	lhu	$v1,0x12($a1)
.NB00011eb0:
/*    11eb0:	00e08825 */ 	or	$s1,$a3,$zero
/*    11eb4:	04e1ffcc */ 	bgez	$a3,.NB00011de8
/*    11eb8:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11ebc:	8ec60000 */ 	lw	$a2,0x0($s6)
.NB00011ec0:
/*    11ec0:	24100003 */ 	addiu	$s0,$zero,0x3
/*    11ec4:	24130002 */ 	addiu	$s3,$zero,0x2
/*    11ec8:	24140004 */ 	addiu	$s4,$zero,0x4
/*    11ecc:	00008825 */ 	or	$s1,$zero,$zero
/*    11ed0:	18c00020 */ 	blez	$a2,.NB00011f54
/*    11ed4:	00001025 */ 	or	$v0,$zero,$zero
/*    11ed8:	3c05800b */ 	lui	$a1,%hi(g_MusicEventQueue)
/*    11edc:	3c15800b */ 	lui	$s5,%hi(g_MusicEventQueue)
/*    11ee0:	26b5ee88 */ 	addiu	$s5,$s5,%lo(g_MusicEventQueue)
/*    11ee4:	24a5ee88 */ 	addiu	$a1,$a1,%lo(g_MusicEventQueue)
/*    11ee8:	2403001c */ 	addiu	$v1,$zero,0x1c
.NB00011eec:
/*    11eec:	8ca90000 */ 	lw	$t1,0x0($a1)
/*    11ef0:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11ef4:	51200015 */ 	beqzl	$t1,.NB00011f4c
/*    11ef8:	0226082a */ 	slt	$at,$s1,$a2
/*    11efc:	00430019 */ 	multu	$v0,$v1
/*    11f00:	8ca10000 */ 	lw	$at,0x0($a1)
/*    11f04:	24420001 */ 	addiu	$v0,$v0,0x1
/*    11f08:	00005012 */ 	mflo	$t2
/*    11f0c:	02aa5821 */ 	addu	$t3,$s5,$t2
/*    11f10:	ad610000 */ 	sw	$at,0x0($t3)
/*    11f14:	8cad0004 */ 	lw	$t5,0x4($a1)
/*    11f18:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*    11f1c:	8ca10008 */ 	lw	$at,0x8($a1)
/*    11f20:	ad610008 */ 	sw	$at,0x8($t3)
/*    11f24:	8cad000c */ 	lw	$t5,0xc($a1)
/*    11f28:	ad6d000c */ 	sw	$t5,0xc($t3)
/*    11f2c:	8ca10010 */ 	lw	$at,0x10($a1)
/*    11f30:	ad610010 */ 	sw	$at,0x10($t3)
/*    11f34:	8cad0014 */ 	lw	$t5,0x14($a1)
/*    11f38:	ad6d0014 */ 	sw	$t5,0x14($t3)
/*    11f3c:	8ca10018 */ 	lw	$at,0x18($a1)
/*    11f40:	ad610018 */ 	sw	$at,0x18($t3)
/*    11f44:	8ec60000 */ 	lw	$a2,0x0($s6)
/*    11f48:	0226082a */ 	slt	$at,$s1,$a2
.NB00011f4c:
/*    11f4c:	1420ffe7 */ 	bnez	$at,.NB00011eec
/*    11f50:	24a5001c */ 	addiu	$a1,$a1,0x1c
.NB00011f54:
/*    11f54:	aec20000 */ 	sw	$v0,0x0($s6)
/*    11f58:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    11f5c:	8c63695c */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
/*    11f60:	3c15800b */ 	lui	$s5,%hi(g_MusicEventQueue)
/*    11f64:	26b5ee88 */ 	addiu	$s5,$s5,%lo(g_MusicEventQueue)
/*    11f68:	10600006 */ 	beqz	$v1,.NB00011f84
/*    11f6c:	3c0e8008 */ 	lui	$t6,%hi(g_MusicSleepRemaining240)
/*    11f70:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x40)
/*    11f74:	8defe700 */ 	lw	$t7,%lo(g_Vars+0x40)($t7)
/*    11f78:	8dce6960 */ 	lw	$t6,%lo(g_MusicSleepRemaining240)($t6)
/*    11f7c:	01cf082a */ 	slt	$at,$t6,$t7
/*    11f80:	10200052 */ 	beqz	$at,.NB000120cc
.NB00011f84:
/*    11f84:	3c018008 */ 	lui	$at,%hi(g_MusicSleepRemaining240)
/*    11f88:	ac236960 */ 	sw	$v1,%lo(g_MusicSleepRemaining240)($at)
/*    11f8c:	8ed80000 */ 	lw	$t8,0x0($s6)
/*    11f90:	1300004e */ 	beqz	$t8,.NB000120cc
.NB00011f94:
/*    11f94:	3c19800b */ 	lui	$t9,%hi(g_MusicEventQueue+0x18)
/*    11f98:	9739eea0 */ 	lhu	$t9,%lo(g_MusicEventQueue+0x18)($t9)
/*    11f9c:	3c01800b */ 	lui	$at,%hi(g_MusicEventQueue+0x18)
/*    11fa0:	3c02800b */ 	lui	$v0,%hi(g_MusicEventQueue+0x12)
/*    11fa4:	27280001 */ 	addiu	$t0,$t9,0x1
/*    11fa8:	a428eea0 */ 	sh	$t0,%lo(g_MusicEventQueue+0x18)($at)
/*    11fac:	9442ee9a */ 	lhu	$v0,%lo(g_MusicEventQueue+0x12)($v0)
/*    11fb0:	00002025 */ 	or	$a0,$zero,$zero
/*    11fb4:	00002825 */ 	or	$a1,$zero,$zero
/*    11fb8:	10520009 */ 	beq	$v0,$s2,.NB00011fe0
/*    11fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*    11fc0:	1053000b */ 	beq	$v0,$s3,.NB00011ff0
/*    11fc4:	00002825 */ 	or	$a1,$zero,$zero
/*    11fc8:	1050000d */ 	beq	$v0,$s0,.NB00012000
/*    11fcc:	00002825 */ 	or	$a1,$zero,$zero
/*    11fd0:	1054000f */ 	beq	$v0,$s4,.NB00012010
/*    11fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    11fd8:	10000010 */ 	beqz	$zero,.NB0001201c
/*    11fdc:	00000000 */ 	sll	$zero,$zero,0x0
.NB00011fe0:
/*    11fe0:	0c0045f8 */ 	jal	musicHandlePlayEvent
/*    11fe4:	02a02025 */ 	or	$a0,$s5,$zero
/*    11fe8:	1000000c */ 	beqz	$zero,.NB0001201c
/*    11fec:	00402025 */ 	or	$a0,$v0,$zero
.NB00011ff0:
/*    11ff0:	0c0046b0 */ 	jal	musicHandleStopEvent
/*    11ff4:	02a02025 */ 	or	$a0,$s5,$zero
/*    11ff8:	10000008 */ 	beqz	$zero,.NB0001201c
/*    11ffc:	00402025 */ 	or	$a0,$v0,$zero
.NB00012000:
/*    12000:	0c0046d0 */ 	jal	musicHandleFadeEvent
/*    12004:	02a02025 */ 	or	$a0,$s5,$zero
/*    12008:	10000004 */ 	beqz	$zero,.NB0001201c
/*    1200c:	00402025 */ 	or	$a0,$v0,$zero
.NB00012010:
/*    12010:	0c004711 */ 	jal	musicHandleStopAllEvent
/*    12014:	00002025 */ 	or	$a0,$zero,$zero
/*    12018:	00402025 */ 	or	$a0,$v0,$zero
.NB0001201c:
/*    1201c:	10800024 */ 	beqz	$a0,.NB000120b0
/*    12020:	3c05800b */ 	lui	$a1,%hi(g_MusicEventQueue)
/*    12024:	8ec90000 */ 	lw	$t1,0x0($s6)
/*    12028:	24a5ee88 */ 	addiu	$a1,$a1,%lo(g_MusicEventQueue)
/*    1202c:	3c0c800b */ 	lui	$t4,%hi(g_MusicEventQueue+0x1c)
/*    12030:	252affff */ 	addiu	$t2,$t1,-1
/*    12034:	aeca0000 */ 	sw	$t2,0x0($s6)
/*    12038:	19400019 */ 	blez	$t2,.NB000120a0
/*    1203c:	01403025 */ 	or	$a2,$t2,$zero
/*    12040:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    12044:	016a5823 */ 	subu	$t3,$t3,$t2
/*    12048:	000b5880 */ 	sll	$t3,$t3,0x2
/*    1204c:	2582eea4 */ 	addiu	$v0,$t4,%lo(g_MusicEventQueue+0x1c)
/*    12050:	01621821 */ 	addu	$v1,$t3,$v0
/*    12054:	8c410000 */ 	lw	$at,0x0($v0)
.NB00012058:
/*    12058:	2442001c */ 	addiu	$v0,$v0,0x1c
/*    1205c:	24a5001c */ 	addiu	$a1,$a1,0x1c
/*    12060:	aca1ffe4 */ 	sw	$at,-0x1c($a1)
/*    12064:	8c4effe8 */ 	lw	$t6,-0x18($v0)
/*    12068:	acaeffe8 */ 	sw	$t6,-0x18($a1)
/*    1206c:	8c41ffec */ 	lw	$at,-0x14($v0)
/*    12070:	aca1ffec */ 	sw	$at,-0x14($a1)
/*    12074:	8c4efff0 */ 	lw	$t6,-0x10($v0)
/*    12078:	acaefff0 */ 	sw	$t6,-0x10($a1)
/*    1207c:	8c41fff4 */ 	lw	$at,-0xc($v0)
/*    12080:	aca1fff4 */ 	sw	$at,-0xc($a1)
/*    12084:	8c4efff8 */ 	lw	$t6,-0x8($v0)
/*    12088:	acaefff8 */ 	sw	$t6,-0x8($a1)
/*    1208c:	8c41fffc */ 	lw	$at,-0x4($v0)
/*    12090:	aca1fffc */ 	sw	$at,-0x4($a1)
/*    12094:	0043082b */ 	sltu	$at,$v0,$v1
/*    12098:	5420ffef */ 	bnezl	$at,.NB00012058
/*    1209c:	8c410000 */ 	lw	$at,0x0($v0)
.NB000120a0:
/*    120a0:	14930006 */ 	bne	$a0,$s3,.NB000120bc
/*    120a4:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    120a8:	10000008 */ 	beqz	$zero,.NB000120cc
/*    120ac:	8c63695c */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
.NB000120b0:
/*    120b0:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    120b4:	10000005 */ 	beqz	$zero,.NB000120cc
/*    120b8:	8c63695c */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
.NB000120bc:
/*    120bc:	14c0ffb5 */ 	bnez	$a2,.NB00011f94
/*    120c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    120c4:	3c038008 */ 	lui	$v1,%hi(g_MusicInterval240)
/*    120c8:	8c63695c */ 	lw	$v1,%lo(g_MusicInterval240)($v1)
.NB000120cc:
/*    120cc:	10600009 */ 	beqz	$v1,.NB000120f4
/*    120d0:	3c018008 */ 	lui	$at,%hi(g_MusicSleepRemaining240)
/*    120d4:	3c0f8008 */ 	lui	$t7,%hi(g_MusicSleepRemaining240)
/*    120d8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x40)
/*    120dc:	8f18e700 */ 	lw	$t8,%lo(g_Vars+0x40)($t8)
/*    120e0:	8def6960 */ 	lw	$t7,%lo(g_MusicSleepRemaining240)($t7)
/*    120e4:	3c018008 */ 	lui	$at,%hi(g_MusicSleepRemaining240)
/*    120e8:	01f8c823 */ 	subu	$t9,$t7,$t8
/*    120ec:	10000002 */ 	beqz	$zero,.NB000120f8
/*    120f0:	ac396960 */ 	sw	$t9,%lo(g_MusicSleepRemaining240)($at)
.NB000120f4:
/*    120f4:	ac206960 */ 	sw	$zero,%lo(g_MusicSleepRemaining240)($at)
.NB000120f8:
/*    120f8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    120fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    12100:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    12104:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    12108:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    1210c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    12110:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    12114:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    12118:	03e00008 */ 	jr	$ra
/*    1211c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);
#endif
#else
// Mismatch: In the "Remove the marked events" loop, goal reloads
// g_MusicEventQueueLength if the if statement passed. Suspect there's some code
// being optimised out that overwrites a1 or wrote to g_MusicEventQueueLength.
// The code below uses += 0 to get the mismatch down to one instruction,
void musicTickEvents(void)
{
	s32 i;
	s32 j;
	s32 result;
	struct musicevent *event;

	if (!g_SndDisabled) {
		if (g_MusicEventQueueLength);

		// Release channels if their track has finished fading out
		for (i = 0; i < 3; i++) {
			if (!g_SeqChannels[i].inuse && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
				if (g_SeqInstances[i].seqp->chanState[0].unk0d <= var70053ca0[g_SeqChannels[i].tracktype]) {
					n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

					g_SeqChannels[i].tracktype = TRACKTYPE_NONE;
					g_SeqChannels[i].inuse = false;
					g_SeqChannels[i].keepafterfade = false;
					g_SeqChannels[i].unk0c = 0;
				} else if (g_SeqInstances[i].seqp->chanState[0].unk0d == g_SeqChannels[i].unk0c) {
					n_alSeqpStop((N_ALSeqPlayer *)g_SeqInstances[i].seqp);

					g_SeqChannels[i].tracktype = TRACKTYPE_NONE;
					g_SeqChannels[i].inuse = false;
					g_SeqChannels[i].keepafterfade = false;
					g_SeqChannels[i].unk0c = 0;
				}
			}
		}

		// Figure out which events can be removed from the queue due to later
		// events superseding them. This loop just marks those events as
		// removable by setting their tracktype to none.
		for (i = g_MusicEventQueueLength - 1; i >= 0; i--) {
			event = &g_MusicEventQueue[i];

#if VERSION >= VERSION_NTSC_1_0
			if (event->eventtype == MUSICEVENTTYPE_SETINTERVAL) {
				continue;
			}
#endif

			if (event->tracktype == TRACKTYPE_NONE) {
				continue;
			}

			for (j = i - 1; j >= 0; j--) {
				struct musicevent *earlier = &g_MusicEventQueue[j];

				if (event->eventtype == MUSICEVENTTYPE_STOPALL) {
					earlier->tracktype = TRACKTYPE_NONE;
					continue;
				}

#if VERSION >= VERSION_NTSC_1_0
				if (earlier->eventtype == MUSICEVENTTYPE_SETINTERVAL) {
					continue;
				}
#endif

				if (earlier->tracktype == TRACKTYPE_NONE) {
					continue;
				}

				if (earlier->tracktype == event->tracktype) {
					switch (event->eventtype) {
					case MUSICEVENTTYPE_STOP:
						earlier->tracktype = TRACKTYPE_NONE;
						break;
					case MUSICEVENTTYPE_PLAY:
						switch (earlier->eventtype) {
						case MUSICEVENTTYPE_PLAY:
						case MUSICEVENTTYPE_FADE:
							earlier->tracktype = TRACKTYPE_NONE;
							break;
						}
						break;
					case MUSICEVENTTYPE_FADE:
						if (earlier->eventtype == MUSICEVENTTYPE_FADE) {
							earlier->tracktype = TRACKTYPE_NONE;
						}
						break;
					}
				}
			}
		}

		// Remove the marked events from the queue, shift the remaining
		// events forward and recount the queue length.
		for (i = 0, j = 0; i < g_MusicEventQueueLength; i++) {
			if (g_MusicEventQueue[i].tracktype) {
				g_MusicEventQueue[j] = g_MusicEventQueue[i];
				j++;

				g_MusicEventQueueLength += 0;
			}
		}

		g_MusicEventQueueLength = j;

		// Process the queue, but only on certain timer intervals,
		// or every frame if the interval timer is disabled
		event = &g_MusicEventQueue[0];

		if (g_MusicInterval240 == 0 || g_MusicSleepRemaining240 < g_Vars.diffframe240) {
			g_MusicSleepRemaining240 = g_MusicInterval240;

			while (g_MusicEventQueueLength) {
				event->numattempts++;

				result = RESULT_FAIL;

				switch (event->eventtype) {
				case MUSICEVENTTYPE_PLAY:
					result = musicHandlePlayEvent(event, result);
					break;
				case MUSICEVENTTYPE_STOP:
					result = musicHandleStopEvent(event, result);
					break;
				case MUSICEVENTTYPE_FADE:
					result = musicHandleFadeEvent(event, result);
					break;
				case MUSICEVENTTYPE_STOPALL:
					result = musicHandleStopAllEvent(result);
					break;
#if VERSION >= VERSION_NTSC_1_0
				case MUSICEVENTTYPE_SETINTERVAL:
					result = musicHandleSetIntervalEvent(event, result);
					break;
#endif
				}

				if (result);

				if (result != RESULT_FAIL) {
					// Remove the item from the queue
					g_MusicEventQueueLength--;

					for (i = 0; i < g_MusicEventQueueLength; i++) {
						g_MusicEventQueue[i] = g_MusicEventQueue[i + 1];
					}

					// Break from processing further events on this frame
					// if requested
					if (result == RESULT_OK_BREAK) {
						break;
					}
				} else {
					break;
				}
			}
		}

		if (g_MusicInterval240) {
			g_MusicSleepRemaining240 -= g_Vars.diffframe240;
		} else {
			g_MusicSleepRemaining240 = 0;
		}
	}
}
#endif

void musicTick(void)
{
	s32 i;
	bool playnrg = false;

	if (!g_SndDisabled) {
		if (g_MusicDeathTimer240 > 0
				&& (g_Vars.normmplayerisrunning
					|| (g_Vars.antiplayernum >= 0 && !g_Vars.bond->isdead)
					|| (g_Vars.coopplayernum >= 0 && (!g_Vars.bond->isdead || !g_Vars.coop->isdead)))) {
			// Someone is dying in MP, or anti is dying, or *one* person is dying in coop
			g_MusicSilenceTimer60 = 0;
			g_MusicDeathTimer240 -= g_Vars.lvupdate240;

			if (g_MusicDeathTimer240 <= 0) {
				musicEndDeath();

				// The death is complete. Are we due to start a new track?
				if (g_MpEnableMusicSwitching && g_Vars.normmplayerisrunning && g_MusicLife60 < g_MusicAge60) {
					g_MusicAge60 = 0;
					musicQueueStopEvent(TRACKTYPE_MENU);
					musicQueueStopEvent(TRACKTYPE_DEATH);
					musicQueueStopEvent(TRACKTYPE_PRIMARY);
					musicQueueStartEvent(TRACKTYPE_PRIMARY, stageGetPrimaryTrack(g_MusicStageNum), 0, musicGetVolume());
				}
			}
		} else if (g_MpEnableMusicSwitching && g_Vars.normmplayerisrunning && g_MusicLife60 < g_MusicAge60) {
			// Due to start a new track. Fade out the old one,
			// then start a 2 second timer before starting the new one.
			g_MusicAge60 = 0;
			musicQueueFadeEvent(TRACKTYPE_PRIMARY, 2, true);
			g_MusicSilenceTimer60 = TICKS(120);
		}

		if (g_MpEnableMusicSwitching && g_Vars.normmplayerisrunning) {
			g_MusicAge60 += g_Vars.diffframe60;

			// If the silence timer is set, it means we're transitioning between
			// songs in multiplayer. Tick the timer down, and when it reaches
			// zero start a new track.
			if (g_MusicSilenceTimer60 > 0) {
				g_MusicSilenceTimer60 -= g_Vars.diffframe60;

				if (g_MusicSilenceTimer60 <= 0) {
					musicQueueStopEvent(TRACKTYPE_MENU);
					musicQueueStopEvent(TRACKTYPE_DEATH);
					musicQueueStopEvent(TRACKTYPE_PRIMARY);
					musicQueueStartEvent(TRACKTYPE_PRIMARY, stageGetPrimaryTrack(g_MusicStageNum), 0, musicGetVolume());
				}
			}
		}

		// Handle stopping of NRG tune
		for (i = 0; i < 4; i++) {
			if (g_AudioXReasonsActive[i] || g_MusicXReasonMinDurations[i] > 0) {
				if (g_MusicXReasonMinDurations[i] >= g_Vars.lvupdate240) {
					g_MusicXReasonMinDurations[i] -= g_Vars.lvupdate240;
				} else {
					g_MusicXReasonMinDurations[i] = 0;
				}

				if (g_MusicXReasonMaxDurations[i] != 0) {
					if (g_MusicXReasonMaxDurations[i] >= g_Vars.lvupdate240) {
						g_MusicXReasonMaxDurations[i] -= g_Vars.lvupdate240;
					} else {
						g_MusicXReasonMaxDurations[i] = 0;
					}

					if (g_MusicXReasonMaxDurations[i] != 0) {
						if (g_AudioXReasonsActive[i] || g_MusicXReasonMinDurations[i]) {
							playnrg = true;
						}
					} else {
						g_AudioXReasonsActive[i] = 0;
					}
				}
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.lvupdate240 != 0) {
			if (g_MusicNrgIsActive) {
				if (!playnrg) {
					musicDeactivateNrg();
				}
			} else {
				if (playnrg && !g_Vars.dontplaynrg) {
					musicActivateNrg();
				}
			}
		}
#else
		if (g_Vars.lvupdate240 != 0) {
			if (musicIsTrackState(TRACKTYPE_NRG, AL_PLAYING)) {
				if (!playnrg) {
					musicDeactivateNrg();
				}
			} else {
				if (playnrg && !g_Vars.dontplaynrg) {
					musicActivateNrg();
				}
			}
		}
#endif

		// Check if the player is in an ambient room every 0.25 seconds
		if (g_Vars.lvupdate240 > g_MusicNextAmbientTick240) {
			musicTickAmbient();
			g_MusicNextAmbientTick240 = TICKS(60);
		} else {
			g_MusicNextAmbientTick240 -= g_Vars.lvupdate240;
		}

		musicTickEvents();
	}
}

bool musicIsTrackTypePlaying(s32 tracktype)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		if (tracktype == g_SeqChannels[i].tracktype && n_alCSPGetState(g_SeqInstances[i].seqp) == AL_PLAYING) {
			return true;
		}
	}

	return false;
}

#if VERSION < VERSION_NTSC_1_0
bool musicAreTracksPlaying(u8 bits)
{
	if ((bits & 0x01) && !musicIsTrackTypePlaying(TRACKTYPE_PRIMARY)) {
		return false;
	}

	if ((bits & 0x02) && !musicIsTrackTypePlaying(TRACKTYPE_NRG)) {
		return false;
	}

	if ((bits & 0x04) && !musicIsTrackTypePlaying(TRACKTYPE_MENU)) {
		return false;
	}

	if ((bits & 0x08) && !musicIsTrackTypePlaying(TRACKTYPE_DEATH)) {
		return false;
	}

	if ((bits & 0x10) && !musicIsTrackTypePlaying(TRACKTYPE_AMBIENT)) {
		return false;
	}

	return true;
}
#endif
