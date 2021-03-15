#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_0c000.h"
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

s32 func0002fa10(void)
{
	return -1;
}

void func0002fa18(void)
{
	// empty
}

void func0002fa20(void)
{
	// empty
}

void func0002fa28(void)
{
	// empty
}

void func0002fa30(void)
{
	// empty
}

void func0002fa38(void)
{
	// empty
}

void func0002fa40(void)
{
	// empty
}

char *crashProut(char *dst, const char *src, size_t count)
{
	s32 i = 0;

	while (i != count) {
		crashAppendChar(src[i++]);
	}

	return (char *) 1;
}

void crashPrint(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	_Printf(crashProut, NULL, format, ap);
}
