#include <ultra64.h>
#include "constants.h"
#include "data.h"
#include "types.h"

static struct mpstrings strings[] = {
	// MPCONFIG_TEMPLE
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_PISTOLS
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_FARSIGHT
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_DRUGGUN
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_SLAYER
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CLOAKING
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_SLOWMO
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_NOSHIELD
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_BRIEFCASE
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_SKEDARKING
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_FLAGS
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_SIMULANTS
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_AUTOMATICS
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_ROCKETS
	{
		"",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE01
	{
		"A challenge against basic simulants using standard weaponry.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE02
	{
		"A challenge against basic simulants which includes the use of rocket launchers.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE03
	{
		"A challenge against basic simulants which includes assault rifles and timed mines.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE04
	{
		"Take control of the hill against a team of standard simulants. Shield technology is available as well as the K7 Avenger.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE05
	{
		"Combat a team of standard simulants using the specialised FarSight weapon in the Complex.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE06
	{
		"Hold the briefcase for as long as possible against a large team of basic simulants.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE07
	{
		"Take control of the hill against a team of advanced simulants in the warehouse. All weapons kill with only one hit.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE08
	{
		"Capture the flag in the Skedar arena with the SuperDragon.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE09
	{
		"One hit kills in the ravine with the farsight.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE10
	{
		"Touch that box in the complex.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE11
	{
		"King of the hill in the temple with drug guns.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE12
	{
		"Slow mo combat in skedar arena.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE13
	{
		"1 hit kills, touch that box, g5, with drug guns.",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE14
	{
		"Capture the flag in area 52 with cloaking.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE15
	{
		"Capture the briefcase in the matrix with devastators.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE16
	{
		"This is a description of challenge 16.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE17
	{
		"This is a description of challenge 17.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE18
	{
		"This is a description of challenge 18.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE19
	{
		"This is a description of challenge 19.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE20
	{
		"This is a description of challenge 20.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE21
	{
		"This is a description of challenge 21.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE22
	{
		"This is a description of challenge 22.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE23
	{
		"This is a description of challenge 23.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE24
	{
		"This is a description of challenge 24.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE25
	{
		"This is a description of challenge 25.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE26
	{
		"This is a description of challenge 26.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE27
	{
		"This is a description of challenge 27.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE28
	{
		"This is a description of challenge 28.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE29
	{
		"This is a description of challenge 29.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
	// MPCONFIG_CHALLENGE30
	{
		"This is a description of challenge 30.\n",
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
		},
	},
};
