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

bool rmon_is_disabled(void)
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

void rmon0002fa30(s32 *arg0, s32 arg1)
{
	if (arg0);
	if (arg1);
}

void rmon0002fa38(u32 arg0)
{
	if (arg0);
}

void rmon0002fa40(void)
{
	// empty
}

char *rmon_prout(char *dst, const char *src, size_t count)
{
	s32 i = 0;

	while (i != count) {
		crash_append_char(src[i++]);
	}

	return (char *) 1;
}

void rmon_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	_Printf(rmon_prout, NULL, format, ap);
}
