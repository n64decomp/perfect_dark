#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <PR/ultratypes.h>
#include "system.h"

static u64 startTick = 0;
static u64 tickFreq = 0;

static void sysInitTicks(void)
{
	tickFreq = SDL_GetPerformanceFrequency();
	startTick = SDL_GetPerformanceCounter();
}

u64 sysGetTicks(void)
{
	if (tickFreq == 0) {
		sysInitTicks();
	}
	return (SDL_GetPerformanceCounter() - startTick);
}

u64 sysGetTicksPerSecond(void)
{
	if (tickFreq == 0) {
		sysInitTicks();
	}
	return tickFreq;
}

void sysFatalError(const char *fmt, ...)
{
	char errmsg[2048] = { 0 };

	va_list ap;
	va_start(ap, fmt);
	vsnprintf(errmsg, sizeof(errmsg), fmt, ap);
	va_end(ap);

	fprintf(stderr, "FATAL ERROR: %s\n", errmsg);
	fflush(stderr);

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal error", errmsg, NULL);
	exit(1);
}

void sysGetExecutablePath(char *outPath, const u32 outLen)
{
	// try asking SDL
	char *sdlPath = SDL_GetBasePath();
	if (sdlPath && *sdlPath) {
		// -1 to trim trailing slash
		const u32 len = strlen(sdlPath) - 1;
		if (len < outLen) {
			memcpy(outPath, sdlPath, len);
			outPath[len] = '\0';
		}
	} else if (outLen > 1) {
		// give up, use working directory instead
		outPath[0] = '.';
		outPath[1] = '\0';
	}
	SDL_free(sdlPath);
}
