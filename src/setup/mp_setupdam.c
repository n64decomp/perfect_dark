//
// Pelagic II
//

#include "../include/setup.h"

u8 intro[];
u8 props[];
struct aipaths paths[];
struct ailists functions[];

void *setup[] = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	functions,
	NULL,
};

char *text_stagename = "B Y E L O M O R Y E  D A M\n";
char *text_briefing1 = "mi6 has confirmed the existence of a secret chemical warfare facility at the arkhangelsk dam, ussr. its heavily guarded location and workings are a cause for major concern. nerve gas produced there has been turning up in the hands of hostile regimes around the world and deals with international terrorists have been rumoured. this facility should be destroyed without prejudice.\n";
char *text_briefing2 = "the area around the dam is well defended against a full scale military attack but they won't be expecting a lone agent. i've looked at the recon reports and decided that the easiest way to gain entrance to the weapons factory will be to bungee jump down the face of the dam. safe and simple. just throw yourself off the top and remember to look before you leap old chap.\n";
char *text_briefing3 = "information concerning shipping and contacts is stored on a computer system in a secret ops room within the dam.with this covert modem connected to their satellite link we can intercept this data when a backup is carried out.\n";
char *text_briefing4 = "hardly a lover's leap, james. be careful though, i hate to think of you falling for anyone else.\n";
char *text_objective1 = "neutralize all alarms\n";
char *text_objective2 = "install covert modem\n";
char *text_objective3 = "intercept data backup\n";
char *text_objective4 = "bungee jump from platform\n";
char *text_objective5 = "Byelomorye Dam, Archangel, USSR\n";

u8 props[] = {
	endprops
};

u8 intro[] = {
	endintro
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

struct ailists functions[] = {
	{ NULL, 0 },
};
