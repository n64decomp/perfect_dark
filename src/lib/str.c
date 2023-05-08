#include <ultra64.h>
#include "types.h"

char *strcpy(char *dst, const char *src)
{
	char *ptr = dst;
	char c;

	*ptr = c = *src;
	ptr++;
	src++;

	while (c != '\0') {
		*ptr = c = *src;
		ptr++;
		src++;
	}

	return dst;
}

char *strncpy(char *dst, const char *src, s32 len)
{
	char *ptr = dst;
	char c;

	*ptr = c = *src;
	ptr++;
	src++;

	while (c != '\0') {
		len--;

		if (len == 0) {
			break;
		}

		*ptr = c = *src;
		ptr++;
		src++;
	}

	while (len--) {
		*ptr = '\0';
		ptr++;
	}

	return dst;
}

char *strcat(char *dst, const char *src)
{
	char *ptr = dst;
	char c;

	while (*ptr != '\0') {
		ptr++;
	}

	*ptr = c = *src;
	ptr++;
	src++;

	while (c != '\0') {
		*ptr = c = *src;
		ptr++;
		src++;
	}

	return dst;
}

s32 strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2) {
		if (*s1 < *s2) {
			return -1;
		} else {
			return 1;
		}
	}

	if (*s1 == '\0') {
		return 0;
	}

	return strcmp(s1 + 1, s2 + 1);
}

s32 strncmp(const char *s1, const char *s2, s32 len)
{
	if (len == 0) {
		return 0;
	}

	len--;

	if (*s1 != *s2) {
		if (*s1 < *s2) {
			return -1;
		} else {
			return 1;
		}
	}

	if (*s1 == '\0') {
		return 0;
	}

	return strncmp(s1 + 1, s2 + 1, len);
}
