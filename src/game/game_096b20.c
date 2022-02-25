#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/game_096b20.h"
#include "types.h"

void func0f096b20(struct coord *arg0, struct coord *arg1, f32 standfrac, struct coord *vel)
{
	vel->x = (arg1->x - arg0->x) * standfrac + arg0->x;
	vel->y = (arg1->y - arg0->y) * standfrac + arg0->y;
	vel->z = (arg1->z - arg0->z) * standfrac + arg0->z;
}

void func0f096b70(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, f32 arg4, struct coord *arg5)
{
	f32 stack;
	f32 mult0;
	f32 mult1;
	f32 mult2;
	f32 mult3;

	f32 squared = arg4 * arg4;
	f32 cubed = arg4 * arg4 * arg4;

	mult0 = squared - 0.5f * (arg4 + cubed);
	mult1 = 1.5f * cubed - 2.5f * squared + 1.0f;
	mult2 = -1.5f * cubed + 2.0f * squared + 0.5f * arg4;
	mult3 = 0.5f * (cubed - squared);

	arg5->x = mult0 * arg0->f[0] + mult1 * arg1->f[0] + mult2 * arg2->f[0] + mult3 * arg3->f[0];
	arg5->y = mult0 * arg0->f[1] + mult1 * arg1->f[1] + mult2 * arg2->f[1] + mult3 * arg3->f[1];
	arg5->z = mult0 * arg0->f[2] + mult1 * arg1->f[2] + mult2 * arg2->f[2] + mult3 * arg3->f[2];
}
