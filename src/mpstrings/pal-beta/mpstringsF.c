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
		"Un challenge contre des simulants de base avec armement standard.",
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
		"Un challenge contre des simulants de base avec lance-roquettes.",
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
		"Un challenge contre des simulants de base avec fusils d'assaut et mines à retardement.",
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
		"Prenez le contrôle de la zone contre uneéquipe de simulants de base. Les boucliers et le K7 Avenger sont disponibles.",
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
		"Affrontez une équipe de simulants standard dans le complexe en  utilisant le fusil FarSight.",
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
		"Gardez la valise aussi longtemps que possible en affrontant une grosse équipe de simulants de base.",
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
		"Prenez le contrôle de la zone contre uneéquipe de simulants de base dans l'entrepôt.Les armes tuent en uncoup.",
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
		"Capturez le drapeauennemi tout en protégeant le vôtre.Tuer le porteur duramène le drapeau à la base.",
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
		"Un scénario meurtrier contre des simulants experts. Les armes comprennent le FarSight et le Laptop gun.",
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
		"Affrontez une équipe de simulants pour le contrôle des boîtes. Touchez une boîte pour vous l'approprier.",
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
		"Roi de la zone contre des simulants experts. Les armes incluent le fusil à pompe et le tranquillisant.",
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
		"Combat au ralenti dans l'Arène Skedar.",
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
		"Tirs meurtriers, Touchez la Boîte, G5, avec tranquillisants.",
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
		"Capturez le drapeau dans la zone 52 avec un occulteur.",
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
		"Capturez la valise dans la Grid avec des Dévastators.",
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
		"Combat standard. Les mines de proximité sont disponibles.",
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
		"Une partie Roi de la Zone. Les missiles filoguidés sont disponibles.",
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
		"Une partie Roi de la Zone contre une équipe de simulants experts.",
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
		"Combat standard contre une escouade de simulants experts. Les armes comprennent le lance-roquettes et le FarSight.",
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
		"Combat meurtrier avec une contrainte : protéger les simulants de votre équipe. Pistolets et boucliers.",
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
		"Touchez les boîtes pour les donner à votre équipe. L'occulteur est disponible.",
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
		"Une partie Gardez la valise avec tirs meurtriers. Les armes incluent l'arbalète et le fusil sniper.",
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
		"Combat au ralenti. Le RCP120 est accessible.",
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
		"Une partie Capturez le drapeau contre une équipede simulants experts. Les armes incluent le Magnum d'Or et le tranquillisant. Pas de boucliers.",
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
		"Un combat standard avec des bombes-N et des occulteurs. Les simulants sont des experts.",
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
		"Une partie standard Roi de  la Zone, sans boucliers.",
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
		"Une partie Touchez la boîte contre de simulants experts Lance-roquettes disponible.",
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
		"une partie Capturez le drapeau contre des simulants experts. Pas de boucliers.",
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
		" Un combat standard sans boucliers. Les armes incluent le Magnum et le Dragon.",
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
		"Une partie Roi de la Zone avec des pistolets. Les simulants sont d'élite.",
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
