#include <ultratypes.h>
#include "stdarg.h"
#include "string.h"

int _Printf(char *(*prout)(char *, const char *, size_t), char *dst, const char *fmt, va_list args);

static char *proutSprintf(char *dst, const char *src, size_t count)
{
	return (char *) memcpy((u8 *) dst, (u8 *) src, count) + count;
}

/**
 * Note: A match has only been found for this function if it returns void
 * rather than the written length. However, there is code elsewhere in the game
 * that reads sprintf's return value. ans is left in v0 so it happens to work
 * correctly. Either the decompilation is accurate and the calling code uses an
 * incorrect declaration for sprintf, or the decompilation is inaccurate and
 * it actually returns ans.
 *
 * Also note this file is using an incorrect declaration for _Printf.
 * _Printf returns an int, not a char.
 */
int sprintf(char *dst, const char *fmt, ...)
{
	int ans;
	va_list ap;

	va_start(ap, fmt);
	ans = _Printf(proutSprintf, dst, fmt, ap);

	if (ans >= 0) {
		dst[ans] = '\0';
	}

	va_end(ap);

	return ans;
}
