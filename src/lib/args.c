#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/str.h"
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
static char *argParseString(char *str)
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

void argSetString(char *string)
{
	strcpy((char *) g_ArgBuffer, string);
	argParseString((char *) g_ArgBuffer);
}

/**
 * Find a program argument based on its prefix and occurrence of that prefix,
 * and return a pointer to whatever comes after the prefix.
 *
 * Typically called with arguments such as 1, "-hard". In this example, if the
 * argument "-hard2" exists then it would return a pointer to "2".
 */
char *argFindByPrefix(s32 occurrence, char *str)
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

void argGetLevel(s32 *stagenum)
{
	char *ptr = argFindByPrefix(1, "-level_");

	if (ptr) {
		*stagenum = ptr[0] * 10 + ptr[1] - 528;
	}
}
