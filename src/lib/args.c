#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/str.h"
#include "lib/rmon.h"
#include "string.h"
#include "data.h"
#include "types.h"

u32 g_ArgBuffer[30];

s32 argc = 1;

char *argv[17] = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

/**
 * Split the given string into words and populate the argv array.
 */
char *arg_parse_string(char *str)
{
	argv[0] = "";
	argc = 1;

	while (*str != '\0') {
		while (*str == ' ') {
			*str = '\0';
			str++;
		}

		argv[argc] = str;
		argc++;

		while (*str > ' ') {
			*str++;
		}
	}

	return str;
}

void arg_set_string(char *string)
{
	strcpy((char *) g_ArgBuffer, string);
	arg_parse_string((char *) g_ArgBuffer);
}

bool args_parse_debug_args(void)
{
	u32 devaddr;
	u32 stack;
	s32 i;
	bool ret = false;

	devaddr = 0x1ffff00;

	if (rmon_is_disabled()) {
		g_ArgBuffer[0] = 0;
	} else {
		for (i = 0; i < ARRAYCOUNT(g_ArgBuffer); i++) {
			osPiReadIo(devaddr, &g_ArgBuffer[i]);
			devaddr += 4;
		}
	}

	arg_parse_string((char *) g_ArgBuffer);

	// I'm guessing the -d stands for debug. If set at boot, the main thread
	// stops itself immediately after creating the rmon thread.
	if (arg_find_by_prefix(1, "-d")) {
		ret = true;
	}

	if (arg_find_by_prefix(1, "-s")) {
		g_SndDisabled = true;
	}

#if VERSION < VERSION_JPN_FINAL
	if (arg_find_by_prefix(1, "-j")) {
		g_Jpn = true;
	}
#endif

	return ret;
}

/**
 * Find a program argument based on its prefix and occurrence of that prefix,
 * and return a pointer to whatever comes after the prefix.
 *
 * Typically called with arguments such as 1, "-hard". In this example, if the
 * argument "-hard2" exists then it would return a pointer to "2".
 */
char *arg_find_by_prefix(s32 occurrence, char *str)
{
	s32 len = strlen(str);
	s32 i;

	for (i = 1; i < argc; i++) {
		if (strncmp(str, argv[i], len) == 0) {
			occurrence--;

			if (occurrence == 0) {
				return &argv[i][len];
			}
		}
	}

	return NULL;
}

void arg_get_level(s32 *stagenum)
{
	char *ptr = arg_find_by_prefix(1, "-level_");

	if (ptr) {
		*stagenum = ptr[0] * 10 + ptr[1] - 528;
	}
}
