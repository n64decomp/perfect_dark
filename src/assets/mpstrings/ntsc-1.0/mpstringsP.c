#include <ultra64.h>
#include "constants.h"
#include "types.h"

static struct mpstrings strings[] = {
	// MPCONFIG_TEMPLE
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_PISTOLS
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_FARSIGHT
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_DRUGGUN
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_SLAYER
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_CLOAKING
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_SLOWMO
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_NOSHIELD
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_BRIEFCASE
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_SKEDARKING
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_FLAGS
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_SIMULANTS
	{
		"",
		{
			"MeatSim:1\n",
			"MeatSim:2\n",
			"NormalSim:1\n",
			"NormalSim:2\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_AUTOMATICS
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_ROCKETS
	{
		"",
		{
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
			"\n",
		},
	},
	// MPCONFIG_CHALLENGE01
	{
		"A challenge against basic simulants using standard weaponry.",
		{
			"ShockSim:1\n",
			"GuardSim:1\n",
			"ShockSim:2\n",
			"GuardSim:2\n",
			"ShockSim:3\n",
			"GuardSim:3\n",
			"ShockSim:4\n",
			"GuardSim:4\n",
		},
	},
	// MPCONFIG_CHALLENGE02
	{
		"A challenge against basic simulants which includes the use of rocket launchers.",
		{
			"ShockSim:1\n",
			"GuardSim:1\n",
			"ShockSim:2\n",
			"GuardSim:2\n",
			"ShockSim:3\n",
			"GuardSim:3\n",
			"ShockSim:4\n",
			"GuardSim:4\n",
		},
	},
	// MPCONFIG_CHALLENGE03
	{
		"A challenge against basic simulants which includes assault rifles and timed mines.",
		{
			"TechSim:1\n",
			"TechSim:2\n",
			"TechSim:3\n",
			"TechSim:4\n",
			"TechSim:5\n",
			"TechSim:6\n",
			"TechSim:7\n",
			"TechSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE04
	{
		"Take control of the hill against a team of standard simulants. Shield technology is available, as well as the K7 Avenger.",
		{
			"CISim:1\n",
			"CISim:2\n",
			"CISim:3\n",
			"CISim:4\n",
			"CISim:5\n",
			"CISim:6\n",
			"CISim:7\n",
			"CISim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE05
	{
		"Combat a team of standard simulants using the specialized FarSight weapon in the Complex.",
		{
			"CassSim\n",
			"GuardSim:1\n",
			"GuardSim:2\n",
			"GuardSim:3\n",
			"GuardSim:4\n",
			"GuardSim:5\n",
			"GuardSim:6\n",
			"GuardSim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE06
	{
		"Hold the briefcase for as long as possible against a large team of basic simulants.",
		{
			"WorkSim:1\n",
			"WorkSim:2\n",
			"WorkSim:3\n",
			"WorkSim:4\n",
			"WorkSim:5\n",
			"WorkSim:6\n",
			"WorkSim:7\n",
			"WorkSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE07
	{
		"Take control of the hill against a team of advanced simulants in the Warehouse. All weapons kill with only one hit.",
		{
			"JoSim:1\n",
			"JoSim:2\n",
			"JoSim:3\n",
			"JoSim:4\n",
			"JoSim:5\n",
			"JoSim:6\n",
			"JoSim:7\n",
			"JoSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE08
	{
		"Capture the enemy's flag while defending your own. Killing the flag carrier means the flag returns to the base.",
		{
			"SnipeSim:1\n",
			"SnipeSim:2\n",
			"SnipeSim:3\n",
			"SnipeSim:4\n",
			"SnipeSim:5\n",
			"SnipeSim:6\n",
			"SnipeSim:7\n",
			"SnipeSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE09
	{
		"A one-hit-kill scenario against expert simulants. Weapons  the FarSight and the laptop gun.",
		{
			"TrentSim\n",
			"NSASim:1\n",
			"NSASim:2\n",
			"NSASim:3\n",
			"NSASim:4\n",
			"NSASim:5\n",
			"NSASim:6\n",
			"NSASim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE10
	{
		"Fight against a team of simulants for control of the boxes. Touch a box to claim it for your team.",
		{
			"GuardSim:1\n",
			"SWATSim:1\n",
			"GuardSim:2\n",
			"SWATSim:2\n",
			"GuardSim:3\n",
			"SWATSim:3\n",
			"GuardSim:4\n",
			"SWATSim:4\n",
		},
	},
	// MPCONFIG_CHALLENGE11
	{
		"King of the hill  against expert simulants. Weapons  the shotgun and tranquilizer.",
		{
			"BlondeSim:1\n",
			"BlondeSim:2\n",
			"BlondeSim:3\n",
			"BlondeSim:4\n",
			"BlondeSim:5\n",
			"BlondeSim:6\n",
			"BlondeSim:7\n",
			"BlondeSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE12
	{
		"Slow-motion combat in the Skedar arena.",
		{
			"JoSim:1\n",
			"JoSim:2\n",
			"JoSim:3\n",
			"JoSim:4\n",
			"JoSim:5\n",
			"JoSim:6\n",
			"JoSim:7\n",
			"JoSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE13
	{
		"One-hit kills, touch that box, G5, with tranquilizers.",
		{
			"CIASim:1\n",
			"FBISim:1\n",
			"CIASim:2\n",
			"FBISim:2\n",
			"CIASim:3\n",
			"FBISim:3\n",
			"CIASim:4\n",
			"FBISim:4\n",
		},
	},
	// MPCONFIG_CHALLENGE14
	{
		"Capture the flag in Area 52 with cloaking.",
		{
			"GuardSim:1\n",
			"TroopSim:1\n",
			"GuardSim:2\n",
			"AirSim:1\n",
			"GuardSim:3\n",
			"TroopSim:2\n",
			"GuardSim:4\n",
			"AirSim:2\n",
		},
	},
	// MPCONFIG_CHALLENGE15
	{
		"Capture the briefcase in the Grid with devastators.",
		{
			"LabSim:1\n",
			"LabSim:2\n",
			"LabSim:3\n",
			"LabSim:4\n",
			"LabSim:5\n",
			"LabSim:6\n",
			"LabSim:7\n",
			"LabSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE16
	{
		"Standard combat. Weapons  proximity mines.",
		{
			"BioSim:1\n",
			"BioSim:2\n",
			"BioSim:3\n",
			"BioSim:4\n",
			"BioSim:5\n",
			"BioSim:6\n",
			"BioSim:7\n",
			"BioSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE17
	{
		"A king of the hill game. Weapons  fly-by-wire missiles.",
		{
			"DanSim\n",
			"CISim:1\n",
			"CISim:2\n",
			"CISim:3\n",
			"CISim:4\n",
			"CISim:5\n",
			"CISim:6\n",
			"CISim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE18
	{
		"A king of the hill game against a team of expert simulants.",
		{
			"ElvisSim\n",
			"MaianSim:1\n",
			"MaianSim:2\n",
			"MaianSim:3\n",
			"MaianSim:4\n",
			"MaianSim:5\n",
			"MaianSim:6\n",
			"MaianSim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE19
	{
		"Standard combat against a squad of expert simulants. Weapons  the rocket launcher and the FarSight.",
		{
			"CassSim\n",
			"TrentSim\n",
			"SnipeSim:1\n",
			"SnipeSim:2\n",
			"SnipeSim:3\n",
			"SnipeSim:4\n",
			"SnipeSim:5\n",
			"SnipeSim:6\n",
		},
	},
	// MPCONFIG_CHALLENGE20
	{
		"One-hit kill combat with a twist - protect the weaker simulants on your team. Pistols and shields.",
		{
			"PilotSim:1\n",
			"PilotSim:2\n",
			"AirSim:6\n",
			"AirSim:5\n",
			"AirSim:4\n",
			"AirSim:3\n",
			"AirSim:2\n",
			"AirSim:1\n",
		},
	},
	// MPCONFIG_CHALLENGE21
	{
		"Touch the boxes to claim them for your side. The Cloaking Device is available.",
		{
			"JoSim\n",
			"SnowSim:1\n",
			"SnowSim:2\n",
			"SnowSim:3\n",
			"SnowSim:4\n",
			"SnowSim:5\n",
			"SnowSim:6\n",
			"SnowSim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE22
	{
		"A hold the briefcase game with one-hit kills. Weapons  the crossbow and the sniper rifle.",
		{
			"PresSim\n",
			"GuardSim:1\n",
			"GuardSim:2\n",
			"GuardSim:3\n",
			"GuardSim:4\n",
			"GuardSim:5\n",
			"GuardSim:6\n",
			"GuardSim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE23
	{
		"Combat in slow motion. Weapons  the RCP120.",
		{
			"CloneSim\n",
			"StripeSim:1\n",
			"StripeSim:2\n",
			"StripeSim:3\n",
			"StripeSim:4\n",
			"StripeSim:5\n",
			"StripeSim:6\n",
			"StripeSim:7\n",
		},
	},
	// MPCONFIG_CHALLENGE24
	{
		"Capture the flag game against a team of expert simulants. Weapons  the Gold DY357 Magnum and the tranquilizer. No shields.",
		{
			"GuardSim:1\n",
			"TroopSim:1\n",
			"AirSim:1\n",
			"GuardSim:2\n",
			"TroopSim:2\n",
			"AirSim:2\n",
			"GuardSim:3\n",
			"GuardSim:4\n",
		},
	},
	// MPCONFIG_CHALLENGE25
	{
		"A standard combat game with N-Bombs and Cloaking Devices. The simulant team is composed of experts.",
		{
			"ShockSim:1\n",
			"ShockSim:2\n",
			"ShockSim:3\n",
			"ShockSim:4\n",
			"ShockSim:5\n",
			"ShockSim:6\n",
			"ShockSim:7\n",
			"ShockSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE26
	{
		"A standard king of the hill game with no shields.",
		{
			"TechSim:1\n",
			"TechSim:2\n",
			"CISim:1\n",
			"CISim:2\n",
			"CISim:3\n",
			"CISim:4\n",
			"CISim:5\n",
			"CISim:6\n",
		},
	},
	// MPCONFIG_CHALLENGE27
	{
		"A touch the box game featuring rocket launchers and expert opponents.",
		{
			"CIASim:1\n",
			"FBISim:1\n",
			"CIASim:2\n",
			"FBISim:2\n",
			"CIASim:3\n",
			"FBISim:3\n",
			"CIASim:4\n",
			"FBISim:4\n",
		},
	},
	// MPCONFIG_CHALLENGE28
	{
		"A capture the flag game with no shields and expert opponents.",
		{
			"GuardSim:1\n",
			"GuardSim:2\n",
			"GuardSim:3\n",
			"GuardSim:4\n",
			"GuardSim:5\n",
			"GuardSim:6\n",
			"GuardSim:7\n",
			"GuardSim:8\n",
		},
	},
	// MPCONFIG_CHALLENGE29
	{
		"Standard combat with no shields available. Weapons  the DY357 and the Dragon.",
		{
			"WorkSim:1\n",
			"WorkSim:2\n",
			"GuardSim:1\n",
			"GuardSim:2\n",
			"GuardSim:3\n",
			"GuardSim:4\n",
			"GuardSim:5\n",
			"GuardSim:6\n",
		},
	},
	// MPCONFIG_CHALLENGE30
	{
		"A pistols only king of the hill game against elite opposition.",
		{
			"BlondeSim:1\n",
			"CassSim\n",
			"TrentSim\n",
			"BlondeSim:2\n",
			"BlondeSim:3\n",
			"JoSim:3\n",
			"JoSim:2\n",
			"JoSim:1\n",
		},
	},
};
