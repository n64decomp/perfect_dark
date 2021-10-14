#include <ultra64.h>
#include <stdarg.h>
#include "constants.h"
#include "bss.h"
#include "lib/crash.h"
#include "lib/libc/xprintf.h"
#include "data.h"
#include "types.h"

void rmonproc()
{
	// empty
}

bool rmonIsDisabled(void)
{
	return true;
}

s32 rmon0002fa10(void)
{
	return -1;
}

void rmon0002fa18(void)
{
	// empty
}

void rmon0002fa20(void)
{
	// empty
}

void rmon0002fa28(void)
{
	// empty
}

void rmon0002fa30(void)
{
	// empty
}

void rmon0002fa38(void)
{
	// empty
}

void rmon0002fa40(void)
{
	// empty
}

char *rmonProut(char *dst, const char *src, size_t count)
{
	s32 i = 0;

	while (i != count) {
		crashAppendChar(src[i++]);
	}

	return (char *) 1;
}

void rmonPrint(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	_Printf(rmonProut, NULL, format, ap);
}
