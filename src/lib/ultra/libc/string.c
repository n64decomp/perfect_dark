#include <ultra64.h>

void *memcpy(void *s1, const void *s2, size_t n)
{
	char *su1 = (char *)s1;
	const char *su2 = (const char *)s2;

	while (n > 0) {
		*su1++ = *su2++;
		n--;
	}

	return (void *)s1;
}

size_t strlen(const char *s)
{
	const char *sc = s;

	while (*sc) {
		sc++;
	}

	return sc - s;
}

char *strchr(const char *s, int c)
{
	const char ch = c;

	while (*s != ch) {
		if (*s == 0) {
			return NULL;
		}

		s++;
	}

	return (char *)s;
}

#ifdef __GNUC__
/**
 * When compiling with gcc it replaces some loops with a call to memset,
 * which means memset must be included in the project.
 */
void *memset(void *str, s32 c, size_t n)
{
	u8* m1 = (u8*) str;
	u32 i;

	for (i = 0; i < n; i++) {
		m1[i] = c;
	}

	return str;
}
#endif
