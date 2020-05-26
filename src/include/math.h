#ifndef IN_MATH_H
#define IN_MATH_H

// @bug?
#define M_BADPI 3.141092641f
#define M_PI    3.141592741f

#define M_BADTAU (M_BADPI * 2)
#define M_TAU    (M_PI * 2)

#define DEG2RAD(deg) ((deg) * (M_BADPI / 180.0f))
#define RAD2DEG(rad) ((rad) * (180.0f / M_BADPI))

#endif
