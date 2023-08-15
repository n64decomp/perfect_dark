#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include "config.h"
#include "video.h"

#include "../fast3d/gfx_api.h"
#include "../fast3d/gfx_sdl.h"
#include "../fast3d/gfx_opengl.h"

static struct GfxWindowManagerAPI *wmAPI;
static struct GfxRenderingAPI *renderingAPI;

static bool initDone = false;

static u32 dlcount = 0;
static u32 frames = 0;
static u32 framesPerSec = 0;
static double startTime, endTime, fpsTime;

s32 videoInit(void)
{
	wmAPI = &gfx_sdl;
	renderingAPI = &gfx_opengl_api;
	gfx_current_native_viewport.width = 320;
	gfx_current_native_viewport.height = 240;

	const s32 w = configGetInt("Video.DefaultWidth", 640);
	const s32 h = configGetInt("Video.DefaultHeight", 480);
	const bool fs = configGetInt("Video.DefaultFullscreen", false);

	gfx_init(wmAPI, renderingAPI, "PD", fs, w, h, 100, 100);

	wmAPI->set_swap_interval(configGetInt("Video.VSync", 1));
	wmAPI->set_target_fps(configGetInt("Video.FramerateLimit", 0)); // disabled because vsync is on

	initDone = true;
	return 0;
}

void videoStartFrame(void)
{
	if (initDone) {
		startTime = wmAPI->get_time();
		gfx_start_frame();
	}
}

void videoSubmitCommands(Gfx *cmds)
{
	if (initDone) {
		gfx_run(cmds);
		++dlcount;
	}
}

void videoEndFrame(void)
{
	if (!initDone) {
		return;
	}

	gfx_end_frame();

	endTime = wmAPI->get_time();

	++frames;
	++framesPerSec;

	if (endTime >= fpsTime) {
		char tmp[128];
		snprintf(tmp, sizeof(tmp), "fps %3u frt %lf frm %u", framesPerSec, endTime - startTime, frames);
		wmAPI->set_window_title(tmp);
		framesPerSec = 0;
		fpsTime = endTime + 1.0;
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
	if (initDone) {
		return wmAPI->get_window_handle();
	}
	return NULL;
}

void videoUpdateNativeResolution(const int w, const int h)
{
	gfx_current_native_viewport.width = w;
	gfx_current_native_viewport.height = h;
}

s32 videoGetWidth(void)
{
	return gfx_current_dimensions.width;
}

s32 videoGetHeight(void)
{
	return gfx_current_dimensions.height;
}

f32 videoGetAspect(void)
{
	return gfx_current_dimensions.aspect_ratio;
}

void videoResetTextureCache(void)
{
	gfx_texture_cache_clear();
}
