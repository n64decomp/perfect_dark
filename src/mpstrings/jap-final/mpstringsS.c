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
			"SimMFácil:1\n",
			"SimMFácil:2\n",
			"SimNormal:1\n",
			"SimNormal:2\n",
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
		"Desafío contra simulantes básicos que usan armamento estándar.",
		{
			"SimShock:1\n",
			"SimGuarda:1\n",
			"SimShock:2\n",
			"SimGuarda:2\n",
			"SimShock:3\n",
			"SimGuarda:3\n",
			"SimShock:4\n",
			"SimGuarda:4\n",
		},
	},
	// MPCONFIG_CHALLENGE02
	{
		"Desafío contra simulantes básicos que incluye el uso de Lanzacohetes.",
		{
			"SimShock:1\n",
			"SimGuarda:1\n",
			"SimShock:2\n",
			"SimGuarda:2\n",
			"SimShock:3\n",
			"SimGuarda:3\n",
			"SimShock:4\n",
			"SimGuarda:4\n",
		},
	},
	// MPCONFIG_CHALLENGE03
	{
		"Desafío contra simulantes básicos que incluye el uso de Rifles y Minas de Tiempo.",
		{
			"SimTécnico:1\n",
			"SimTécnico:2\n",
			"SimTécnico:3\n",
			"SimTécnico:4\n",
			"SimTécnico:5\n",
			"SimTécnico:6\n",
			"SimTécnico:7\n",
			"SimTécnico:8\n",
		},
	},
	// MPCONFIG_CHALLENGE04
	{
		"Toma el control de la colina contra simulantes estándar. El escudo y el Vengador K7 están disponibles.",
		{
			"SimIC:1\n",
			"SimIC:2\n",
			"SimIC:3\n",
			"SimIC:4\n",
			"SimIC:5\n",
			"SimIC:6\n",
			"SimIC:7\n",
			"SimIC:8\n",
		},
	},
	// MPCONFIG_CHALLENGE05
	{
		"Combate contra un equipo de simulantes estándar usando la especializada arma llamada FarSight en el Complejo.",
		{
			"SimCass\n",
			"SimGuarda:1\n",
			"SimGuarda:2\n",
			"SimGuarda:3\n",
			"SimGuarda:4\n",
			"SimGuarda:5\n",
			"SimGuarda:6\n",
			"SimGuarda:7\n",
		},
	},
	// MPCONFIG_CHALLENGE06
	{
		"Conserva el maletín tanto como sea posible contra un gran grupo de simulantes básicos.",
		{
			"SimTrabaj:1\n",
			"SimTrabaj:2\n",
			"SimTrabaj:3\n",
			"SimTrabaj:4\n",
			"SimTrabaj:5\n",
			"SimTrabaj:6\n",
			"SimTrabaj:7\n",
			"SimTrabaj:8\n",
		},
	},
	// MPCONFIG_CHALLENGE07
	{
		"Toma el control de la colina contra simulantes avanzados en el Almacén. Todas las armas matan de un toque.",
		{
			"SimJoanna:1\n",
			"SimJoanna:2\n",
			"SimJoanna:3\n",
			"SimJoanna:4\n",
			"SimJoanna:5\n",
			"SimJoanna:6\n",
			"SimJoanna:7\n",
			"SimJoanna:8\n",
		},
	},
	// MPCONFIG_CHALLENGE08
	{
		"Captura el maletín del enemigo mientras defiendes el tuyo. Matar al portador hace que éste vuelva a la base.",
		{
			"SimDisparo:1\n",
			"SimDisparo:2\n",
			"SimDisparo:3\n",
			"SimDisparo:4\n",
			"SimDisparo:5\n",
			"SimDisparo:6\n",
			"SimDisparo:7\n",
			"SimDisparo:8\n",
		},
	},
	// MPCONFIG_CHALLENGE09
	{
		"Un escenario de muerte de un tiro contra simulantes expertos. Las armas incluyen la FarSight y el Arma PC.",
		{
			"SimTrent\n",
			"SimANS:1\n",
			"SimANS:2\n",
			"SimANS:3\n",
			"SimANS:4\n",
			"SimANS:5\n",
			"SimANS:6\n",
			"SimANS:7\n",
		},
	},
	// MPCONFIG_CHALLENGE10
	{
		"Lucha contra un equipo de simulantes para tomar control de la terminal con el Conector de Datos.",
		{
			"SimGuarda:1\n",
			"SimSWAT:1\n",
			"SimGuarda:2\n",
			"SimSWAT:2\n",
			"SimGuarda:3\n",
			"SimSWAT:3\n",
			"SimGuarda:4\n",
			"SimSWAT:4\n",
		},
	},
	// MPCONFIG_CHALLENGE11
	{
		"Rey de la Colina contra simulantes expertos. Las armas incluyen la Escopeta y el Tranquilizante.",
		{
			"SimBlonde:1\n",
			"SimBlonde:2\n",
			"SimBlonde:3\n",
			"SimBlonde:4\n",
			"SimBlonde:5\n",
			"SimBlonde:6\n",
			"SimBlonde:7\n",
			"SimBlonde:8\n",
		},
	},
	// MPCONFIG_CHALLENGE12
	{
		"Combate a Cámara Lenta en la arena Skedar.",
		{
			"SimJoanna:1\n",
			"SimJoanna:2\n",
			"SimJoanna:3\n",
			"SimJoanna:4\n",
			"SimJoanna:5\n",
			"SimJoanna:6\n",
			"SimJoanna:7\n",
			"SimJoanna:8\n",
		},
	},
	// MPCONFIG_CHALLENGE13
	{
		"Un toque mata, G5, con tranquilizantes.",
		{
			"SimCIA:1\n",
			"SimFBI:1\n",
			"SimCIA:2\n",
			"SimFBI:2\n",
			"SimCIA:3\n",
			"SimFBI:3\n",
			"SimCIA:4\n",
			"SimFBI:4\n",
		},
	},
	// MPCONFIG_CHALLENGE14
	{
		"Captura el maletín en el Área 52 con ocultación.",
		{
			"SimGuarda:1\n",
			"SimSoldado:1\n",
			"SimGuarda:2\n",
			"SimAéreo:1\n",
			"SimGuarda:3\n",
			"SimSoldado:2\n",
			"SimGuarda:4\n",
			"SimAéreo:2\n",
		},
	},
	// MPCONFIG_CHALLENGE15
	{
		"Mantén el maletín en la Reja con devastadores.",
		{
			"SimLab:1\n",
			"SimLab:2\n",
			"SimLab:3\n",
			"SimLab:4\n",
			"SimLab:5\n",
			"SimLab:6\n",
			"SimLab:7\n",
			"SimLab:8\n",
		},
	},
	// MPCONFIG_CHALLENGE16
	{
		"Combate Estándar. El armamento incluye Minas de Proximidad. No hay radar en este desafío.",
		{
			"SimBio:1\n",
			"SimBio:2\n",
			"SimBio:3\n",
			"SimBio:4\n",
			"SimBio:5\n",
			"SimBio:6\n",
			"SimBio:7\n",
			"SimBio:8\n",
		},
	},
	// MPCONFIG_CHALLENGE17
	{
		"Un juego del Rey de la Colina. Las armas incluyen Misiles Teledirigidos.",
		{
			"SimDan\n",
			"SimIC:1\n",
			"SimIC:2\n",
			"SimIC:3\n",
			"SimIC:4\n",
			"SimIC:5\n",
			"SimIC:6\n",
			"SimIC:7\n",
		},
	},
	// MPCONFIG_CHALLENGE18
	{
		"Un juego del Rey de la Colina contra un equipo de expertos simulantes.",
		{
			"SimElvis\n",
			"SimMaian:1\n",
			"SimMaian:2\n",
			"SimMaian:3\n",
			"SimMaian:4\n",
			"SimMaian:5\n",
			"SimMaian:6\n",
			"SimMaian:7\n",
		},
	},
	// MPCONFIG_CHALLENGE19
	{
		"Combate rápido contra simulantes expertos. Las armas incluyen el Lanzacohetes y la FarSight.",
		{
			"SimCass\n",
			"SimTrent\n",
			"SimDisparo:1\n",
			"SimDisparo:2\n",
			"SimDisparo:3\n",
			"SimDisparo:4\n",
			"SimDisparo:5\n",
			"SimDisparo:6\n",
		},
	},
	// MPCONFIG_CHALLENGE20
	{
		"Combate de un toque con trampa: debes proteger a los simulantes débiles de tu equipo. Pistolas y escudos.",
		{
			"SimPiloto:1\n",
			"SimPiloto:2\n",
			"SimAéreo:6\n",
			"SimAéreo:5\n",
			"SimAéreo:4\n",
			"SimAéreo:3\n",
			"SimAéreo:2\n",
			"SimAéreo:1\n",
		},
	},
	// MPCONFIG_CHALLENGE21
	{
		"Entra en la terminal con el Conector de Datos. El Dispositivo de Ocultación está disponible.",
		{
			"SimJoanna\n",
			"SimNieve:1\n",
			"SimNieve:2\n",
			"SimNieve:3\n",
			"SimNieve:4\n",
			"SimNieve:5\n",
			"SimNieve:6\n",
			"SimNieve:7\n",
		},
	},
	// MPCONFIG_CHALLENGE22
	{
		"Debes preservar el maletín con tiros de un toque mata. Las armas incluyen la Ballesta y el Rifle Francotirador.",
		{
			"SimPresi\n",
			"SimGuarda:1\n",
			"SimGuarda:2\n",
			"SimGuarda:3\n",
			"SimGuarda:4\n",
			"SimGuarda:5\n",
			"SimGuarda:6\n",
			"SimGuarda:7\n",
		},
	},
	// MPCONFIG_CHALLENGE23
	{
		"Combate a cámara lenta. Las armas incluyen el RCP120.",
		{
			"SimClon\n",
			"SimRayas:1\n",
			"SimRayas:2\n",
			"SimRayas:3\n",
			"SimRayas:4\n",
			"SimRayas:5\n",
			"SimRayas:6\n",
			"SimRayas:7\n",
		},
	},
	// MPCONFIG_CHALLENGE24
	{
		"Captura el maletín contra s. expertos. Las armas incluyen la Magnum DY357 y los Tranquilizantes. Sin escudos.",
		{
			"SimGuarda:1\n",
			"SimSoldado:1\n",
			"SimAéreo:1\n",
			"SimGuarda:2\n",
			"SimSoldado:2\n",
			"SimAéreo:2\n",
			"SimGuarda:3\n",
			"SimGuarda:4\n",
		},
	},
	// MPCONFIG_CHALLENGE25
	{
		"Combate estándar con Bombas-N y Dispositivos de Ocultación. El equipo de simulantes es experto.",
		{
			"SimShock:1\n",
			"SimShock:2\n",
			"SimShock:3\n",
			"SimShock:4\n",
			"SimShock:5\n",
			"SimShock:6\n",
			"SimShock:7\n",
			"SimShock:8\n",
		},
	},
	// MPCONFIG_CHALLENGE26
	{
		"Un juego estándar de Rey de la Colina sin escudos.",
		{
			"SimTécnico:1\n",
			"SimTécnico:2\n",
			"SimIC:1\n",
			"SimIC:2\n",
			"SimIC:3\n",
			"SimIC:4\n",
			"SimIC:5\n",
			"SimIC:6\n",
		},
	},
	// MPCONFIG_CHALLENGE27
	{
		"Un juego de 'hackear' con Lanzacohetes y oponentes expertos.",
		{
			"SimCIA:1\n",
			"SimFBI:1\n",
			"SimCIA:2\n",
			"SimFBI:2\n",
			"SimCIA:3\n",
			"SimFBI:3\n",
			"SimCIA:4\n",
			"SimFBI:4\n",
		},
	},
	// MPCONFIG_CHALLENGE28
	{
		"Un juego de capturar maletín sin escudos y con expertos oponentes.",
		{
			"SimGuarda:1\n",
			"SimGuarda:2\n",
			"SimGuarda:3\n",
			"SimGuarda:4\n",
			"SimGuarda:5\n",
			"SimGuarda:6\n",
			"SimGuarda:7\n",
			"SimGuarda:8\n",
		},
	},
	// MPCONFIG_CHALLENGE29
	{
		"Combate estándar sin escudos disponibles. Las armas incluyen la DY357 y el Dragón.",
		{
			"SimTrabajo:1\n",
			"SimTrabajo:2\n",
			"SimGuarda:1\n",
			"SimGuarda:2\n",
			"SimGuarda:3\n",
			"SimGuarda:4\n",
			"SimGuarda:5\n",
			"SimGuarda:6\n",
		},
	},
	// MPCONFIG_CHALLENGE30
	{
		"Un juego de Rey de la Colina con pistolas contra oposición de élite.",
		{
			"SimBlonde:1\n",
			"SimCass\n",
			"SimTrent\n",
			"SimBlonde:2\n",
			"SimBlonde:3\n",
			"SimJoanna:3\n",
			"SimJoanna:2\n",
			"SimJoanna:1\n",
		},
	},
};
