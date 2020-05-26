#ifndef _IN_UTIL_H
#define _IN_UTIL_H

#define mkshort(val) ((val) >> 8) & 0xff, (val) & 0xff
#define mkword(val) ((val) >> 24) & 0xff, ((val) >> 16) & 0xff, ((val) >> 8) & 0xff, (val) & 0xff

#endif
