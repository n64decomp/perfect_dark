#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/game_1531a0.h"
#include "lib/profile.h"
#include "lib/vi.h"
#include "types.h"

u32 g_ProfileAudStart;
u32 g_ProfileAudCycles;
u32 g_ProfileGfxCycles;

extern OSThread g_SchedThread;

static u32 profileReadCounters(void)
{
	u32 buf = IO_READ(DPC_BUFBUSY_REG);
	u32 tmm = IO_READ(DPC_TMEM_REG);
	u32 bus = IO_READ(DPC_PIPEBUSY_REG);
	u32 max;

	max = buf > tmm ? buf : tmm;
	max = bus > max ? bus : max;

	return max;
}

void profileGetCounters(u32 counters[5])
{
	s32 i;

	OSPri prevpri = osGetThreadPri(0);
	osSetThreadPri(0, THREADPRI_SCHED + 1);

	// RSP
	counters[0] = g_ProfileAudCycles;

	// RDP
	counters[1] = g_ProfileGfxCycles;

	// Audio thread
	counters[2] = g_AudioManager.thread.cycles_saved;
	g_AudioManager.thread.cycles_saved = 0;

	// Main thread
	counters[3] = g_MainThread.cycles_saved + (osGetCount() - g_MainThread.cycles_at_dispatch);
	g_MainThread.cycles_saved = 0;
	g_MainThread.cycles_at_dispatch = osGetCount();

	// Scheduler thread
	counters[4] = g_SchedThread.cycles_saved;
	g_SchedThread.cycles_saved = 0;

	osSetThreadPri(0, prevpri);
}

void profileHandleRspEvent(s32 event)
{
	switch (event) {
	case RSPEVENT_AUD_START:
		g_ProfileAudStart = osGetCount();
		break;
	case RSPEVENT_AUD_FINISH:
		g_ProfileAudCycles = osGetCount() - g_ProfileAudStart;
		break;
	case RSPEVENT_GFX_START:
		osDpSetStatus(DPC_CLR_CMD_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_TMEM_CTR);
		break;
	case RSPEVENT_GFX_FINISH:
		g_ProfileGfxCycles = profileReadCounters();
		break;
	}
}

#ifdef PROFILING

#define NUM_SAMPLES 32

// [x][x][0] is the current ticks tally (for multiple start + stops within one frame)
// [x][x][1] is the start time
u32 g_ProfileMarkers[NUM_SAMPLES][NUM_PROFILEMARKERS][2];
s32 g_ProfileIndex = 0;
struct profileslot *g_ProfileCurrentSlot;

struct profileslot {
	char *file;
	s32 line;
	s32 ticks;
	s32 startticks;
	s32 numiterations;
	struct profileslot *parent;
	bool recursion;
};

struct profileslot g_ProfileSlots[30];

void profileReset(void)
{
	s32 i;

	g_ProfileIndex++;
	WRAP(g_ProfileIndex, NUM_SAMPLES);

	for (i = 0; i < NUM_PROFILEMARKERS; i++) {
		g_ProfileMarkers[g_ProfileIndex][i][0] = 0;
		g_ProfileMarkers[g_ProfileIndex][i][1] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_ProfileSlots); i++) {
		g_ProfileSlots[i].file = NULL;
		g_ProfileSlots[i].parent = NULL;
	}

	g_ProfileCurrentSlot = NULL;
}

void profileStartDynamic(char *file, s32 line)
{
	s32 i;
	struct profileslot *emptyslot = NULL;
	struct profileslot *slot = NULL;

	for (i = 0; i < ARRAYCOUNT(g_ProfileSlots); i++) {
		if (!emptyslot && g_ProfileSlots[i].file == NULL) {
			emptyslot = &g_ProfileSlots[i];
		} else if (g_ProfileSlots[i].file == file && g_ProfileSlots[i].line == line) {
			slot = &g_ProfileSlots[i];
			break;
		}
	}

	if (slot) {
		// Another iteration on an existing slot
		if (slot->startticks) {
			slot->recursion = true;
		} else {
			slot->numiterations++;
			slot->startticks = __osRunningThread->cycles_saved + (osGetCount() - __osRunningThread->cycles_at_dispatch);
		}

		g_ProfileCurrentSlot = slot;
	} else if (emptyslot) {
		// New slot
		slot = emptyslot;

		slot->file = file;
		slot->line = line;
		slot->parent = g_ProfileCurrentSlot;
		slot->ticks = 0;
		slot->numiterations = 1;
		slot->recursion = false;
		slot->startticks = __osRunningThread->cycles_saved + (osGetCount() - __osRunningThread->cycles_at_dispatch);

		g_ProfileCurrentSlot = slot;
	}
}

void profileEndDynamic(char *file, s32 line)
{
	u32 now = __osRunningThread->cycles_saved + (osGetCount() - __osRunningThread->cycles_at_dispatch);
	s32 i;
	struct profileslot *slot = NULL;

	for (i = 0; i < ARRAYCOUNT(g_ProfileSlots); i++) {
		if (g_ProfileSlots[i].file == file && g_ProfileSlots[i].line == line) {
			slot = &g_ProfileSlots[i];
			break;
		}
	}

	if (slot) {
		slot->ticks += now - slot->startticks;
		slot->startticks = 0;

		g_ProfileCurrentSlot = slot->parent;
	}
}

void profileStart(s32 marker)
{
	g_ProfileMarkers[g_ProfileIndex][marker][1] = __osRunningThread->cycles_saved + (osGetCount() - __osRunningThread->cycles_at_dispatch);
}

void profileEnd(s32 marker)
{
	u32 now = __osRunningThread->cycles_saved + (osGetCount() - __osRunningThread->cycles_at_dispatch);
	g_ProfileMarkers[g_ProfileIndex][marker][0] += now - g_ProfileMarkers[g_ProfileIndex][marker][1];
}

Gfx *profileRenderCpuLine(Gfx *gdl, s32 x, s32 *y, char *label, s32 marker)
{
	char buffer[64];
	u32 ticks = 0;
	s32 percent;
	u32 colour;
	u32 microseconds;
	s32 textwidth;
	s32 textheight;
	s32 x2;
	s32 i;

	for (i = 0; i < NUM_SAMPLES; i++) {
		ticks += g_ProfileMarkers[i][marker][0];
	}

	ticks /= NUM_SAMPLES;

	percent = 100 * ticks / (OS_CPU_COUNTER / 60);
	microseconds = OS_CYCLES_TO_USEC(ticks);

	if (percent >= 100) {
		colour = 0xff0000a0;
	} else if (percent >= 80) {
		colour = 0xffff00a0;
	} else {
		colour = 0x00ff00a0;
	}

	x2 = x;
	gdl = textRender(gdl, &x2, y, label, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

	sprintf(buffer, "%d", microseconds);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

	x2 = x + 100 - textwidth;
	gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

	sprintf(buffer, "%d%%\n", percent);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

	x2 = x + 130 - textwidth;
	gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

	return gdl;
}

Gfx *profileRender(Gfx *gdl)
{
	if (g_FontHandelGothicXs) {
		s32 x = 10;
		s32 y = 10;

		gdl = text0f153628(gdl);
		gdl = profileRenderCpuLine(gdl, x, &y, "CPU", PROFILEMARKER_CPU);
		gdl = profileRenderCpuLine(gdl, x, &y, " audio", PROFILEMARKER_AUDIO);
		gdl = profileRenderCpuLine(gdl, x, &y, " lvTick", PROFILEMARKER_LVTICK);
		gdl = profileRenderCpuLine(gdl, x, &y, "  hudmsgs   ", PROFILEMARKER_LVT_HUDMSGS   );
		gdl = profileRenderCpuLine(gdl, x, &y, "  vtxstore  ", PROFILEMARKER_LVT_VTXSTORE  );
		gdl = profileRenderCpuLine(gdl, x, &y, "  casings   ", PROFILEMARKER_LVT_CASINGS   );
		gdl = profileRenderCpuLine(gdl, x, &y, "  shards    ", PROFILEMARKER_LVT_SHARDS    );
		gdl = profileRenderCpuLine(gdl, x, &y, "  sparks    ", PROFILEMARKER_LVT_SPARKS    );
		gdl = profileRenderCpuLine(gdl, x, &y, "  wallhits  ", PROFILEMARKER_LVT_WALLHITS  );
		gdl = profileRenderCpuLine(gdl, x, &y, "  splats    ", PROFILEMARKER_LVT_SPLATS    );
		gdl = profileRenderCpuLine(gdl, x, &y, "  weather   ", PROFILEMARKER_LVT_WEATHER   );
		gdl = profileRenderCpuLine(gdl, x, &y, "  nbombs    ", PROFILEMARKER_LVT_NBOMBS    );
		gdl = profileRenderCpuLine(gdl, x, &y, "  miscsfx   ", PROFILEMARKER_LVT_MISCSFX   );
		gdl = profileRenderCpuLine(gdl, x, &y, "  snd       ", PROFILEMARKER_LVT_SND       );
		gdl = profileRenderCpuLine(gdl, x, &y, "  pak       ", PROFILEMARKER_LVT_PAK       );
		gdl = profileRenderCpuLine(gdl, x, &y, "  lighting  ", PROFILEMARKER_LVT_LIGHTING  );
		gdl = profileRenderCpuLine(gdl, x, &y, "  modelmgr  ", PROFILEMARKER_LVT_MODELMGR  );
		gdl = profileRenderCpuLine(gdl, x, &y, "  boltbeams ", PROFILEMARKER_LVT_BOLTBEAMS );
		gdl = profileRenderCpuLine(gdl, x, &y, "  activemenu", PROFILEMARKER_LVT_ACTIVEMENU);
		gdl = profileRenderCpuLine(gdl, x, &y, "  menu      ", PROFILEMARKER_LVT_MENU      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  scenario  ", PROFILEMARKER_LVT_SCENARIO  );
		gdl = profileRenderCpuLine(gdl, x, &y, "  props     ", PROFILEMARKER_LVT_PROPS     );
		gdl = profileRenderCpuLine(gdl, x, &y, "  music     ", PROFILEMARKER_LVT_MUSIC     );
		gdl = profileRenderCpuLine(gdl, x, &y, "  padeffects", PROFILEMARKER_LVT_PADEFFECTS);
		gdl = profileRenderCpuLine(gdl, x, &y, " lvTickPlayers", PROFILEMARKER_LVTICKPLAYERS);

		x = 170;
		y = 10;

		gdl = profileRenderCpuLine(gdl, x, &y, " lvRender", PROFILEMARKER_LVRENDER);
		gdl = profileRenderCpuLine(gdl, x, &y, "  prepare     ", PROFILEMARKER_LVR_PREPARE     );
		gdl = profileRenderCpuLine(gdl, x, &y, "  bondgun     ", PROFILEMARKER_LVR_BONDGUN     );
		gdl = profileRenderCpuLine(gdl, x, &y, "  sky1        ", PROFILEMARKER_LVR_SKY1        );
		gdl = profileRenderCpuLine(gdl, x, &y, "  bgtick      ", PROFILEMARKER_LVR_BGTICK      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  lights      ", PROFILEMARKER_LVR_LIGHTS      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  props       ", PROFILEMARKER_LVR_PROPS       );
		gdl = profileRenderCpuLine(gdl, x, &y, "  scenariochr ", PROFILEMARKER_LVR_SCENARIOCHR );
		gdl = profileRenderCpuLine(gdl, x, &y, "  propssort   ", PROFILEMARKER_LVR_PROPSSORT   );
		gdl = profileRenderCpuLine(gdl, x, &y, "  autoaim     ", PROFILEMARKER_LVR_AUTOAIM     );
		gdl = profileRenderCpuLine(gdl, x, &y, "  hands       ", PROFILEMARKER_LVR_HANDS       );
		gdl = profileRenderCpuLine(gdl, x, &y, "  lookingat   ", PROFILEMARKER_LVR_LOOKINGAT   );
		gdl = profileRenderCpuLine(gdl, x, &y, "  trackedprops", PROFILEMARKER_LVR_TRACKEDPROPS);
		gdl = profileRenderCpuLine(gdl, x, &y, "  pickup      ", PROFILEMARKER_LVR_PICKUP      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  bg          ", PROFILEMARKER_LVR_BG          );
		gdl = profileRenderCpuLine(gdl, x, &y, "  beams       ", PROFILEMARKER_LVR_BEAMS       );
		gdl = profileRenderCpuLine(gdl, x, &y, "  shards      ", PROFILEMARKER_LVR_SHARDS      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  sparks      ", PROFILEMARKER_LVR_SPARKS      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  weather     ", PROFILEMARKER_LVR_WEATHER     );
		gdl = profileRenderCpuLine(gdl, x, &y, "  nbombs      ", PROFILEMARKER_LVR_NBOMBS      );
		gdl = profileRenderCpuLine(gdl, x, &y, "  hud         ", PROFILEMARKER_LVR_HUD         );
		gdl = profileRenderCpuLine(gdl, x, &y, "  scenario    ", PROFILEMARKER_LVR_SCENARIO    );
		gdl = profileRenderCpuLine(gdl, x, &y, "  fade        ", PROFILEMARKER_LVR_FADE        );
		gdl = profileRenderCpuLine(gdl, x, &y, "  sky2        ", PROFILEMARKER_LVR_SKY2        );
		gdl = profileRenderCpuLine(gdl, x, &y, "  activemenu  ", PROFILEMARKER_LVR_ACTIVEMENU  );
		gdl = profileRenderCpuLine(gdl, x, &y, "  menu        ", PROFILEMARKER_LVR_MENU        );
		gdl = profileRenderCpuLine(gdl, x, &y, "  artifacts   ", PROFILEMARKER_LVR_ARTIFACTS   );
		gdl = profileRenderCpuLine(gdl, x, &y, "tmp", PROFILEMARKER_TMP);
		gdl = text0f153780(gdl);
	}

	return gdl;
}

Gfx *profileRenderDynamicSlot(Gfx *gdl, s32 x, s32 *y, s32 index)
{
	char buffer[64];
	struct profileslot *slot = &g_ProfileSlots[index];
	s32 childticks = 0;
	s32 textwidth;
	s32 textheight;
	s32 x2 = x;
	s32 i;

	if (slot->recursion) {
		sprintf(buffer, "%s:%d  *RECURSION*\n", slot->file, slot->line);
		gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
	} else {
		// Render this slot
		sprintf(buffer, "%s:%d", slot->file, slot->line);
		gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

		sprintf(buffer, "%dus", (u32) OS_CYCLES_TO_USEC(slot->ticks));
		textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x2 = 160 - textwidth;
		gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

		sprintf(buffer, "%d\n", slot->numiterations);
		x2 = 170;
		gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

		// Render child slots
		for (i = 0; i < ARRAYCOUNT(g_ProfileSlots); i++) {
			if (g_ProfileSlots[i].file && g_ProfileSlots[i].parent == slot) {
				gdl = profileRenderDynamicSlot(gdl, x + 5, y, i);
				childticks += g_ProfileSlots[i].ticks;
			}
		}

		// Render child "other" slot
		if (childticks > 0) {
			x2 = x + 5;
			gdl = textRender(gdl, &x2, y, "other", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

			sprintf(buffer, "%dus\n", (u32) OS_CYCLES_TO_USEC(slot->ticks - childticks));
			textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

			x2 = 160 - textwidth;
			gdl = textRender(gdl, &x2, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		}
	}

	return gdl;
}

Gfx *profileRenderDynamic(Gfx *gdl)
{
	if (g_FontHandelGothicXs) {
		s32 x = 10;
		s32 y = 10;
		s32 i;

		gdl = text0f153628(gdl);

		for (i = 0; i < ARRAYCOUNT(g_ProfileSlots); i++) {
			if (g_ProfileSlots[i].file && g_ProfileSlots[i].parent == NULL) {
				gdl = profileRenderDynamicSlot(gdl, x, &y, i);
			}
		}

		gdl = text0f153780(gdl);
	}

	return gdl;
}
#endif
