#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "../fast3d/gfx_pc.h"
#include "../fast3d/gfx_sdl2.h"
#include "../fast3d/gfx_opengl.h"

static struct GfxWindowManagerAPI *wmAPI;
static struct GfxRenderingAPI *renderingAPI;

static bool initDone = false;

s32 videoInit(void)
{
	wmAPI = &gfx_sdl;
	renderingAPI = &gfx_opengl_api;
	gfx_init(wmAPI, renderingAPI, "PD", false);
	initDone = true;
	return 0;
}

void videoStartFrame(void)
{
	if (initDone) {
		gfx_start_frame();
	}
}

void videoSubmitCommands(Gfx *cmds)
{
	if (initDone) {
		gfx_run(cmds);
	}
}

void videoEndFrame(void)
{
	if (initDone) {
		gfx_end_frame();
	}
}

void videoClearScreen(void)
{
	videoStartFrame();
	// TODO: clear
	videoEndFrame();
}

void *videoGetWindowHandle(void)
{
	if (initDone && wmAPI) {
		return wmAPI->get_window_handle();
	}
	return NULL;
}
