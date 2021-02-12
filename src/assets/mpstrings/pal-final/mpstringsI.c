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
			"RepPappa:1\n",
			"RepPappa:2\n",
			"RepNorma:1\n",
			"RepNorma:2\n",
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
		"Sfida contro replicanti base con armi standard.",
		{
			"RepShock:1\n",
			"RepGuard:1\n",
			"RepShock:2\n",
			"RepGuard:2\n",
			"RepShock:3\n",
			"RepGuard:3\n",
			"RepShock:4\n",
			"RepGuard:4\n",
		},
	},
	// MPCONFIG_CHALLENGE02
	{
		"Sfida contro replicanti base con l'uso di lanciamissili.",
		{
			"RepShock:1\n",
			"RepGuard:1\n",
			"RepShock:2\n",
			"RepGuard:2\n",
			"RepShock:3\n",
			"RepGuard:3\n",
			"RepShock:4\n",
			"RepGuard:4\n",
		},
	},
	// MPCONFIG_CHALLENGE03
	{
		"Sfida contro repli- canti base con fucili d'assalto e mine a orologeria.",
		{
			"RepTecnic:1\n",
			"RepTecnic:2\n",
			"RepTecnic:3\n",
			"RepTecnic:4\n",
			"RepTecnic:5\n",
			"RepTecnic:6\n",
			"RepTecnic:7\n",
			"RepTecnic:8\n",
		},
	},
	// MPCONFIG_CHALLENGE04
	{
		"Conquista il colle contro replicanti base. Armi: tecnologia scudo e K7 Vendetta.",
		{
			"RepCI:1\n",
			"RepCI:2\n",
			"RepCI:3\n",
			"RepCI:4\n",
			"RepCI:5\n",
			"RepCI:6\n",
			"RepCI:7\n",
			"RepCI:8\n",
		},
	},
	// MPCONFIG_CHALLENGE05
	{
		"Lotta contro una squadra di replicanti base con la speciale arma Televista. ",
		{
			"RepCassan\n",
			"RepGuard:1\n",
			"RepGuard:2\n",
			"RepGuard:3\n",
			"RepGuard:4\n",
			"RepGuard:5\n",
			"RepGuard:6\n",
			"RepGuard:7\n",
		},
	},
	// MPCONFIG_CHALLENGE06
	{
		"Difendi la cartella il più a lungo possibile contro una squadra di replicanti base.",
		{
			"RepOpera:1\n",
			"RepOpera:2\n",
			"RepOpera:3\n",
			"RepOpera:4\n",
			"RepOpera:5\n",
			"RepOpera:6\n",
			"RepOpera:7\n",
			"RepOpera:8\n",
		},
	},
	// MPCONFIG_CHALLENGE07
	{
		"Conquista il colle contro replicanti esperti nel magazzino. Armi a un-colpo-e-sei-morto.",
		{
			"RepJoanna:1\n",
			"RepJoanna:2\n",
			"RepJoanna:3\n",
			"RepJoanna:4\n",
			"RepJoanna:5\n",
			"RepJoanna:6\n",
			"RepJoanna:7\n",
			"RepJoanna:8\n",
		},
	},
	// MPCONFIG_CHALLENGE08
	{
		"Conquista la cassa del nemico e difendi la tua. Se uccidi chi la porta, la cassa tornerà alla base.",
		{
			"RepCecchi:1\n",
			"RepCecchi:2\n",
			"RepCecchi:3\n",
			"RepCecchi:4\n",
			"RepCecchi:5\n",
			"RepCecchi:6\n",
			"RepCecchi:7\n",
			"RepCecchi:8\n",
		},
	},
	// MPCONFIG_CHALLENGE09
	{
		"Sfida ad un-colpo- -e-sei-morto contro replicanti esperti. Armi: TeleVista e pistola Laptop.",
		{
			"RepTrent\n",
			"RepNSA:1\n",
			"RepNSA:2\n",
			"RepNSA:3\n",
			"RepNSA:4\n",
			"RepNSA:5\n",
			"RepNSA:6\n",
			"RepNSA:7\n",
		},
	},
	// MPCONFIG_CHALLENGE10
	{
		"Lotta contro una squadra di replicanti per l'accesso al terminale con l'uso del Connettore Dati.",
		{
			"RepGuard:1\n",
			"RepSWAT:1\n",
			"RepGuard:2\n",
			"RepSWAT:2\n",
			"RepGuard:3\n",
			"RepSWAT:3\n",
			"RepGuard:4\n",
			"RepSWAT:4\n",
		},
	},
	// MPCONFIG_CHALLENGE11
	{
		"Diventa Re del Colle contro replicanti esperti! Armi: fucile a pompa e sedativo.",
		{
			"RepBlonde:1\n",
			"RepBlonde:2\n",
			"RepBlonde:3\n",
			"RepBlonde:4\n",
			"RepBlonde:5\n",
			"RepBlonde:6\n",
			"RepBlonde:7\n",
			"RepBlonde:8\n",
		},
	},
	// MPCONFIG_CHALLENGE12
	{
		"Combattimento al rallentatore allo stadio Skedar.",
		{
			"RepJoanna:1\n",
			"RepJoanna:2\n",
			"RepJoanna:3\n",
			"RepJoanna:4\n",
			"RepJoanna:5\n",
			"RepJoanna:6\n",
			"RepJoanna:7\n",
			"RepJoanna:8\n",
		},
	},
	// MPCONFIG_CHALLENGE13
	{
		"Un-colpo-e-sei-morto, G5, con sedativi.",
		{
			"RepCIA:1\n",
			"RepFBI:1\n",
			"RepCIA:2\n",
			"RepFBI:2\n",
			"RepCIA:3\n",
			"RepFBI:3\n",
			"RepCIA:4\n",
			"RepFBI:4\n",
		},
	},
	// MPCONFIG_CHALLENGE14
	{
		"Conquista la cassa nell'Area 52 mimetizzandoti.",
		{
			"RepGuard:1\n",
			"RepSoldat:1\n",
			"RepGuard:2\n",
			"RepAereo:1\n",
			"RepGuard:3\n",
			"RepSoldat:2\n",
			"RepGuard:4\n",
			"RepAereo:2\n",
		},
	},
	// MPCONFIG_CHALLENGE15
	{
		"Prendi con i Devastatori la cartella nella griglia.",
		{
			"RepLabor:1\n",
			"RepLabor:2\n",
			"RepLabor:3\n",
			"RepLabor:4\n",
			"RepLabor:5\n",
			"RepLabor:6\n",
			"RepLabor:7\n",
			"RepLabor:8\n",
		},
	},
	// MPCONFIG_CHALLENGE16
	{
		"Combattimento standard con mine di prossimità. Nessun radar disponibile.",
		{
			"RepBio:1\n",
			"RepBio:2\n",
			"RepBio:3\n",
			"RepBio:4\n",
			"RepBio:5\n",
			"RepBio:6\n",
			"RepBio:7\n",
			"RepBio:8\n",
		},
	},
	// MPCONFIG_CHALLENGE17
	{
		"Sfida 'Re del Colle' con missili filoguidati. ",
		{
			"RepDaniel\n",
			"RepCI:1\n",
			"RepCI:2\n",
			"RepCI:3\n",
			"RepCI:4\n",
			"RepCI:5\n",
			"RepCI:6\n",
			"RepCI:7\n",
		},
	},
	// MPCONFIG_CHALLENGE18
	{
		"Sfida 'Re del Colle' contro una squadra di replicanti esperti.",
		{
			"RepElvis\n",
			"RepMaian:1\n",
			"RepMaian:2\n",
			"RepMaian:3\n",
			"RepMaian:4\n",
			"RepMaian:5\n",
			"RepMaian:6\n",
			"RepMaian:7\n",
		},
	},
	// MPCONFIG_CHALLENGE19
	{
		"Combattimento accelerato contro replicanti esperti. Armi: lanciamissili e Televista.",
		{
			"RepCassan\n",
			"RepTrent\n",
			"RepCecchi:1\n",
			"RepCecchi:2\n",
			"RepCecchi:3\n",
			"RepCecchi:4\n",
			"RepCecchi:5\n",
			"RepCecchi:6\n",
		},
	},
	// MPCONFIG_CHALLENGE20
	{
		"Sfida a un-colpo-e- sei-morto con una modifica: difendi il replicante più debole della tua squadra. Armi: pistole e scudi.",
		{
			"RepPilota:1\n",
			"RepPilota:2\n",
			"RepAereo:6\n",
			"RepAereo:5\n",
			"RepAereo:4\n",
			"RepAereo:3\n",
			"RepAereo:2\n",
			"RepAereo:1\n",
		},
	},
	// MPCONFIG_CHALLENGE21
	{
		"Accedi al terminale con il Connettore Dati. Dispositivo mimetico disponibile.",
		{
			"RepJoanna\n",
			"RepNeve:1\n",
			"RepNeve:2\n",
			"RepNeve:3\n",
			"RepNeve:4\n",
			"RepNeve:5\n",
			"RepNeve:6\n",
			"RepNeve:7\n",
		},
	},
	// MPCONFIG_CHALLENGE22
	{
		"Difendi la cartella ad un-colpo-e-sei-morto. Tra le armi la balestra e il fucile da cecchino.",
		{
			"RepPresid\n",
			"RepGuard:1\n",
			"RepGuard:2\n",
			"RepGuard:3\n",
			"RepGuard:4\n",
			"RepGuard:5\n",
			"RepGuard:6\n",
			"RepGuard:7\n",
		},
	},
	// MPCONFIG_CHALLENGE23
	{
		"Combattimento al rallentatore. Armi: RCP120.",
		{
			"RepPresid\n",
			"RepUffic:1\n",
			"RepUffic:2\n",
			"RepUffic:3\n",
			"RepUffic:4\n",
			"RepUffic:5\n",
			"RepUffic:6\n",
			"RepUffic:7\n",
		},
	},
	// MPCONFIG_CHALLENGE24
	{
		"Conquista la cassa contro replicanti esperti. Armi: Gold DY357 Magnum e sedativo. ",
		{
			"RepGuard:1\n",
			"RepSoldat:1\n",
			"RepAereo:1\n",
			"RepGuard:2\n",
			"RepSoldat:2\n",
			"RepAereo:2\n",
			"RepGuard:3\n",
			"RepGuard:4\n",
		},
	},
	// MPCONFIG_CHALLENGE25
	{
		"Combattimento standard con bombe-N e dispositivi mimetici. La squadra è di replicanti esperti.",
		{
			"RepShock:1\n",
			"RepShock:2\n",
			"RepShock:3\n",
			"RepShock:4\n",
			"RepShock:5\n",
			"RepShock:6\n",
			"RepShock:7\n",
			"RepShock:8\n",
		},
	},
	// MPCONFIG_CHALLENGE26
	{
		"Sfida standard 'Re del Colle' senza scudi.",
		{
			"RepTecnic:1\n",
			"RepTecnic:2\n",
			"RepCI:1\n",
			"RepCI:2\n",
			"RepCI:3\n",
			"RepCI:4\n",
			"RepCI:5\n",
			"RepCI:6\n",
		},
	},
	// MPCONFIG_CHALLENGE27
	{
		"Gioco di hacker con lanciamissili e replicanti esperti.",
		{
			"RepCIA:1\n",
			"RepFBI:1\n",
			"RepCIA:2\n",
			"RepFBI:2\n",
			"RepCIA:3\n",
			"RepFBI:3\n",
			"RepCIA:4\n",
			"RepFBI:4\n",
		},
	},
	// MPCONFIG_CHALLENGE28
	{
		"Conquista la cassa contro avversari esperti. Scudi non disponibili.",
		{
			"RepGuard:1\n",
			"RepGuard:2\n",
			"RepGuard:3\n",
			"RepGuard:4\n",
			"RepGuard:5\n",
			"RepGuard:6\n",
			"RepGuard:7\n",
			"RepGuard:8\n",
		},
	},
	// MPCONFIG_CHALLENGE29
	{
		"Combattimento standard senza scudi. Armi: DY357 e Dragon.",
		{
			"RepOpera:1\n",
			"RepOpera:2\n",
			"RepGuard:1\n",
			"RepGuard:2\n",
			"RepGuard:3\n",
			"RepGuard:4\n",
			"RepGuard:5\n",
			"RepGuard:6\n",
		},
	},
	// MPCONFIG_CHALLENGE30
	{
		"Sfida 'Re del Colle' solo con pistole contro avversari straordinari.",
		{
			"RepBlonde:1\n",
			"RepCassan\n",
			"RepTrent\n",
			"RepBlonde:2\n",
			"RepBlonde:3\n",
			"RepJoanna:3\n",
			"RepJoanna:2\n",
			"RepJoanna:1\n",
		},
	},
};
