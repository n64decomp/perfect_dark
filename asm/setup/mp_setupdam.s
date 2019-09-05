#
# Pelagic II
#

.set HEADERLEN, 0x48
.include "asm/include/setup.inc"

props:
	endprops

intro:
	endintro

paths:
	endpaths

functions:
	endfunctions

.align 4

text_stagename:
	.ascii "B Y E L O M O R Y E  D A M\n"
	.byte  0x00

	.align 2

text_briefing1:
	.ascii "mi6 has confirmed the existence of a secret chemical warfare facility at the arkhangelsk dam, ussr. its heavily guarded location and workings are a cause for major concern. nerve gas produced there has been turning up in the hands of hostile regimes around the world and deals with international terrorists have been rumoured. this facility should be destroyed without prejudice.\n"
	.byte  0x00

	.align 2

text_briefing2:
	.ascii "the area around the dam is well defended against a full scale military attack but they won't be expecting a lone agent. i've looked at the recon reports and decided that the easiest way to gain entrance to the weapons factory will be to bungee jump down the face of the dam. safe and simple. just throw yourself off the top and remember to look before you leap old chap.\n"
	.byte  0x00

	.align 2

text_briefing3:
	.ascii "information concerning shipping and contacts is stored on a computer system in a secret ops room within the dam.with this covert modem connected to their satellite link we can intercept this data when a backup is carried out.\n"
	.byte  0x00

	.align 2

text_briefing4:
	.ascii "hardly a lover's leap, james. be careful though, i hate to think of you falling for anyone else.\n"
	.byte  0x00

	.align 2

text_objective1:
	.ascii "neutralize all alarms\n"
	.byte  0x00

	.align 2

text_objective2:
	.ascii "install covert modem\n"
	.byte  0x00

	.align 2

text_objective3:
	.ascii "intercept data backup\n"
	.byte  0x00

	.align 2

text_objective4:
	.ascii "bungee jump from platform\n"
	.byte  0x00

	.align 2

text_objective5:
	.ascii "Byelomorye Dam, Archangel, USSR\n"
	.byte  0x00

	.align 2

.align 4
