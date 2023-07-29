#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <PR/ultratypes.h>

u8 g_CrashHasMessage = 0;
s32 g_CrashEnabled = 0;

static char crashMsg[1024];

void crashCreateThread(void)
{
	// TODO: install a crash handler of some sort
}

void crashSetMessage(char *string)
{
	strncpy(crashMsg, string, sizeof(crashMsg) - 1);
	fprintf(stderr, "crashSetMessage: %s\n", crashMsg);
	g_CrashHasMessage = 1;
}

void crashReset(void)
{
	crashMsg[0] = 0;
	g_CrashHasMessage = 0;
}

void crashAppendChar(char c)
{
	g_CrashHasMessage = 1;
	for (u32 i = 0; i < sizeof(crashMsg) - 1; ++i) {
		if (crashMsg[i] == '\0') {
			crashMsg[i] = c;
			crashMsg[i + 1] = '\0';
			break;
		}
	}
}
