#include <ultra64.h>
#include "types.h"

void strcpy(char *dst, const char *src)
{
	char c;

	do {
		*dst = c = *src;
		dst++;
		src++;
	} while (c != '\0');
}

void strncpy(char *dst, const char *src, s32 len)
{
	char c;

	do {
		*dst = c = *src;
		dst++;
		src++;
	} while (c != '\0' && len-- > 0);
}

void strcat(char *dst, const char *src)
{
	char c;

	while (*dst != '\0') {
		dst++;
	}

	do {
		*dst = c = *src;
		dst++;
		src++;
	} while (c != '\0');
}

s32 strcmp(const char *s1, const char *s2)
{
	while (true) {
		if (*s1 != *s2) {
			return 1;
		}

		if (*s1 == '\0') {
			return 0;
		}

		s1++;
		s2++;
	}
}
