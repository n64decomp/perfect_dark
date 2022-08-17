//
// Chicago
//

#include "stagesetup.h"

s32 intro[];
u32 props[];
struct path paths[];
struct ailist ailists[];

struct stagesetup setup = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	ailists,
	NULL,
};

char *text_stagename = "S T .  P E T E R S B U R G\n";
char *text_briefing1 = "use the stolen tank to chase the car containing natalya. you are up against a time limit.\n";
char *text_briefing2 = "\n";
char *text_briefing3 = "\n";
char *text_briefing4 = "\n";
char *text_objective1 = "\n\n\n";
char *text_objective2 = "\n\n\n";
char *text_objective3 = "\n";

u32 props[] = {
	briefing(0, 0x0020)
	briefing(1, 0x0024)
	briefing(2, 0x0028)
	briefing(3, 0x002c)
	briefing(4, 0x0030)

	beginobjective(0, 0x0034, (DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD))
	endobjective

	beginobjective(1, 0x0038, (DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD))
	endobjective

	beginobjective(2, 0x003c, (DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD))
	endobjective
	endprops
};

s32 intro[] = {
	intro_weapon(WEAPON_PP9I, -1)
	ammo(AMMOTYPE_PISTOL, 100)
	outfit(OUTFIT_DEFAULT)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};
