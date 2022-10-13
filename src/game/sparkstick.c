#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void sparksTick(void)
{
	struct sparkgroup *group;
	struct sparktype *type;
	struct spark *spark;
	s32 next;
	s32 i;
	s32 j;
	s32 k;

	if (g_SparksAreActive) {
		g_SparksAreActive = false;
		group = &g_SparkGroups[0];

		// Iterate spark groups
		for (i = 0; i != 10; i++) {
			type = &g_SparkTypes[group->type];

			if (group->age >= type->maxage) {
				group->age = 0;
			} else if (group->age) {
				if (g_SparksAreActive == false) {
					g_SparksAreActive = true;
				}

				// Iterate the lvupdate multiplier
				for (j = 0; j < g_Vars.lvupdate60; j++) {
					group->age++;
					next = group->startindex;
					spark = &g_Sparks[next];

					// Iterate sparks in this group
					for (k = 0; k < group->numsparks; k++) {
						// Update this spark if active
						if (spark->ttl) {
							spark->speed.x -= spark->speed.x * type->decel;
							spark->speed.y = (spark->speed.y - spark->speed.y * type->decel) - type->weight;
							spark->speed.z -= spark->speed.z * type->decel;

							if (spark->speed.y == 0.0f) {
								spark->speed.y = -0.0001f;
							}

							spark->pos.x += spark->speed.x;
							spark->pos.y += spark->speed.y;
							spark->pos.z += spark->speed.z;

							spark->ttl--;
						}

						// If reached the end of the array, jump back to start
						next++;

						if (next == ARRAYCOUNT(g_Sparks)) {
							// @dangerous: `next` is not reset here, so this
							// condition will only pass once per group.
							// If a group contains more than 100 sparks, it
							// could cause spark to overflow the array and write
							// over whatever's after it. This doesn't happen
							// because no group has more than 100 sparks.
							spark = &g_Sparks[0];
						} else {
							spark++;
						}
					}
				}
			}

			group++;
		}
	}
}
