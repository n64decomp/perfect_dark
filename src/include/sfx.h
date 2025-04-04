/**
 * Sound effect references are implemented using a 16-bit bitfield.
 *
 * The most significant bit determines whether this sfx reference is mapped in
 * a config table in snd.c. If it is, the structure of the bitfield is:
 *
 *     1iiiiiii iiiiiiii
 *
 * ...where 1 means it's mapped, and i is the index into the config table.
 *
 * For a sound effect without a config mapping the structure is:
 *
 *     0uummsss ssssssss
 *
 * Where:
 * - 0 means it's not mapped.
 * - u is unknown.
 * - m means it's an MP3 file, and the value of m determines
 *     its priority (lower value has higher priority).
 * - s is the sound effect index if it's not an MP3 file,
 *     or the file number if it is an MP3 file.
 */

/**
 * There are 1545 (0x609) sound effects in the bank.
 */
enum sfxnum {
	SFXNUM_0000,
	SFXNUM_0001_LAUNCH_ROCKET,
	SFXNUM_0002_EQUIP_HORIZONSCANNER,
	SFXNUM_0003,
	SFXNUM_0004,
	SFXNUM_0005,
	SFXNUM_0006,
	SFXNUM_0007,
	SFXNUM_0008,
	SFXNUM_0009,
	SFXNUM_000A,
	SFXNUM_000B,
	SFXNUM_000C,
	SFXNUM_000D_F_ARGH,
	SFXNUM_000E_F_ARGH,
	SFXNUM_000F_F_ARGH,
	SFXNUM_0010_BOTTLE_BREAK,
	SFXNUM_0011,
	SFXNUM_0012,
	SFXNUM_0013,
	SFXNUM_0014,
	SFXNUM_0015,
	SFXNUM_0016,
	SFXNUM_0017,
	SFXNUM_0018,
	SFXNUM_0019,
	SFXNUM_001A,
	SFXNUM_001B,
	SFXNUM_001C,
	SFXNUM_001D,
	SFXNUM_001E,
	SFXNUM_001F,
	SFXNUM_0020,
	SFXNUM_0021,
	SFXNUM_0022,
	SFXNUM_0023,
	SFXNUM_0024,
	SFXNUM_0025,
	SFXNUM_0026,
	SFXNUM_0027,
	SFXNUM_0028,
	SFXNUM_0029,
	SFXNUM_002A,
	SFXNUM_002B_MENU_CANCEL,
	SFXNUM_002C,
	SFXNUM_002D,
	SFXNUM_002E,
	SFXNUM_002F,
	SFXNUM_0030,
	SFXNUM_0031,
	SFXNUM_0032,
	SFXNUM_0033,
	SFXNUM_0034,
	SFXNUM_0035,
	SFXNUM_0036,
	SFXNUM_0037,
	SFXNUM_0038,
	SFXNUM_0039,
	SFXNUM_003A,
	SFXNUM_003B,
	SFXNUM_003C,
	SFXNUM_003D,
	SFXNUM_003E_HUDMSG,
	SFXNUM_003F,
	SFXNUM_0040,
	SFXNUM_0041,
	SFXNUM_0042,
	SFXNUM_0043,
	SFXNUM_0044,
	SFXNUM_0045,
	SFXNUM_0046,
	SFXNUM_0047,
	SFXNUM_0048,
	SFXNUM_0049,
	SFXNUM_004A,
	SFXNUM_004B,
	SFXNUM_004C,
	SFXNUM_004D,
	SFXNUM_004E,
	SFXNUM_004F,
	SFXNUM_0050,
	SFXNUM_0051,
	SFXNUM_0052_REGEN,
	SFXNUM_0053,
	SFXNUM_0054,
	SFXNUM_0055,
	SFXNUM_0056,
	SFXNUM_0057,
	SFXNUM_0058,
	SFXNUM_0059,
	SFXNUM_005A,
	SFXNUM_005B_CLOAK_ON,
	SFXNUM_005C_CLOAK_OFF,
	SFXNUM_005D,
	SFXNUM_005E,
	SFXNUM_005F,
	SFXNUM_0060,
	SFXNUM_0061,
	SFXNUM_0062,
	SFXNUM_0063,
	SFXNUM_0064_SHIELD_DAMAGE,
	SFXNUM_0065_LASER_STREAM,
	SFXNUM_0066,
	SFXNUM_0067,
	SFXNUM_0068,
	SFXNUM_0069,
	SFXNUM_006A,
	SFXNUM_006B,
	SFXNUM_006C,
	SFXNUM_006D,
	SFXNUM_006E,
	SFXNUM_006F,
	SFXNUM_0070,
	SFXNUM_0071,
	SFXNUM_0072,
	SFXNUM_0073,
	SFXNUM_0074,
	SFXNUM_0075,
	SFXNUM_0076,
	SFXNUM_0077,
	SFXNUM_0078,
	SFXNUM_0079,
	SFXNUM_007A,
	SFXNUM_007B,
	SFXNUM_007C,
	SFXNUM_007D,
	SFXNUM_007E,
	SFXNUM_007F,
	SFXNUM_0080,
	SFXNUM_0081,
	SFXNUM_0082,
	SFXNUM_0083,
	SFXNUM_0084,
	SFXNUM_0085,
	SFXNUM_0086_M_ARGH,
	SFXNUM_0087_M_ARGH,
	SFXNUM_0088_M_ARGH,
	SFXNUM_0089_M_ARGH,
	SFXNUM_008A_M_ARGH,
	SFXNUM_008B_M_ARGH,
	SFXNUM_008C_M_ARGH,
	SFXNUM_008D_M_ARGH,
	SFXNUM_008E_M_ARGH,
	SFXNUM_008F_M_ARGH,
	SFXNUM_0090_M_ARGH,
	SFXNUM_0091_M_ARGH,
	SFXNUM_0092_M_ARGH,
	SFXNUM_0093_M_ARGH,
	SFXNUM_0094_M_ARGH,
	SFXNUM_0095_M_ARGH,
	SFXNUM_0096_M_ARGH,
	SFXNUM_0097_M_ARGH,
	SFXNUM_0098_M_ARGH,
	SFXNUM_0099_M_ARGH,
	SFXNUM_009A_M_ARGH,
	SFXNUM_009B_M_ARGH,
	SFXNUM_009C_M_ARGH,
	SFXNUM_009D_M_ARGH,
	SFXNUM_009E_M_ARGH,
	SFXNUM_009F,
	SFXNUM_00A0,
	SFXNUM_00A1_ALARM_AIRBASE,
	SFXNUM_00A2_ALARM_2,
	SFXNUM_00A3_ALARM_DEFAULT,
	SFXNUM_00A4,
	SFXNUM_00A5,
	SFXNUM_00A6,
	SFXNUM_00A7,
	SFXNUM_00A8,
	SFXNUM_00A9,
	SFXNUM_00AA,
	SFXNUM_00AB,
	SFXNUM_00AC,
	SFXNUM_00AD,
	SFXNUM_00AE,
	SFXNUM_00AF,
	SFXNUM_00B0,
	SFXNUM_00B1,
	SFXNUM_00B2,
	SFXNUM_00B3,
	SFXNUM_00B4,
	SFXNUM_00B5,
	SFXNUM_00B6,
	SFXNUM_00B7,
	SFXNUM_00B8,
	SFXNUM_00B9,
	SFXNUM_00BA_PRESS_SWITCH,
	SFXNUM_00BB,
	SFXNUM_00BC,
	SFXNUM_00BD,
	SFXNUM_00BE,
	SFXNUM_00BF,
	SFXNUM_00C0,
	SFXNUM_00C1,
	SFXNUM_00C2,
	SFXNUM_00C3,
	SFXNUM_00C4,
	SFXNUM_00C5,
	SFXNUM_00C6,
	SFXNUM_00C7,
	SFXNUM_00C8,
	SFXNUM_00C9,
	SFXNUM_00CA,
	SFXNUM_00CB,
	SFXNUM_00CC,
	SFXNUM_00CD,
	SFXNUM_00CE,
	SFXNUM_00CF,
	SFXNUM_00D0,
	SFXNUM_00D1,
	SFXNUM_00D2,
	SFXNUM_00D3,
	SFXNUM_00D4,
	SFXNUM_00D5,
	SFXNUM_00D6,
	SFXNUM_00D7,
	SFXNUM_00D8,
	SFXNUM_00D9,
	SFXNUM_00DA,
	SFXNUM_00DB,
	SFXNUM_00DC,
	SFXNUM_00DD,
	SFXNUM_00DE,
	SFXNUM_00DF,
	SFXNUM_00E0,
	SFXNUM_00E1,
	SFXNUM_00E2,
	SFXNUM_00E3,
	SFXNUM_00E4,
	SFXNUM_00E5_PICKUP_KEYCARD,
	SFXNUM_00E6,
	SFXNUM_00E7,
	SFXNUM_00E8_PICKUP_GUN,
	SFXNUM_00E9_PICKUP_KNIFE,
	SFXNUM_00EA_PICKUP_AMMO,
	SFXNUM_00EB_PICKUP_MINE,
	SFXNUM_00EC,
	SFXNUM_00ED,
	SFXNUM_00EE,
	SFXNUM_00EF,
	SFXNUM_00F0,
	SFXNUM_00F1,
	SFXNUM_00F2_PICKUP_LASER,
	SFXNUM_00F3,
	SFXNUM_00F4,
	SFXNUM_00F5_BIKE_TAKEOFF,
	SFXNUM_00F6,
	SFXNUM_00F7,
	SFXNUM_00F8,
	SFXNUM_00F9,
	SFXNUM_00FA,
	SFXNUM_00FB,
	SFXNUM_00FC,
	SFXNUM_00FD,
	SFXNUM_00FE,
	SFXNUM_00FF,
	SFXNUM_0100,
	SFXNUM_0101,
	SFXNUM_0102,
	SFXNUM_0103,
	SFXNUM_0104,
	SFXNUM_0105,
	SFXNUM_0106,
	SFXNUM_0107,
	SFXNUM_0108,
	SFXNUM_0109,
	SFXNUM_010A,
	SFXNUM_010B,
	SFXNUM_010C,
	SFXNUM_010D,
	SFXNUM_010E,
	SFXNUM_010F,
	SFXNUM_0110,
	SFXNUM_0111,
	SFXNUM_0112,
	SFXNUM_0113,
	SFXNUM_0114,
	SFXNUM_0115,
	SFXNUM_0116,
	SFXNUM_0117,
	SFXNUM_0118,
	SFXNUM_0119,
	SFXNUM_011A,
	SFXNUM_011B,
	SFXNUM_011C,
	SFXNUM_011D,
	SFXNUM_011E,
	SFXNUM_011F,
	SFXNUM_0120,
	SFXNUM_0121,
	SFXNUM_0122,
	SFXNUM_0123,
	SFXNUM_0124,
	SFXNUM_0125,
	SFXNUM_0126,
	SFXNUM_0127,
	SFXNUM_0128,
	SFXNUM_0129,
	SFXNUM_012A,
	SFXNUM_012B,
	SFXNUM_012C,
	SFXNUM_012D,
	SFXNUM_012E,
	SFXNUM_012F,
	SFXNUM_0130,
	SFXNUM_0131,
	SFXNUM_0132,
	SFXNUM_0133,
	SFXNUM_0134,
	SFXNUM_0135,
	SFXNUM_0136,
	SFXNUM_0137,
	SFXNUM_0138,
	SFXNUM_0139,
	SFXNUM_013A,
	SFXNUM_013B,
	SFXNUM_013C,
	SFXNUM_013D,
	SFXNUM_013E,
	SFXNUM_013F,
	SFXNUM_0140,
	SFXNUM_0141,
	SFXNUM_0142,
	SFXNUM_0143,
	SFXNUM_0144,
	SFXNUM_0145,
	SFXNUM_0146,
	SFXNUM_0147,
	SFXNUM_0148,
	SFXNUM_0149,
	SFXNUM_014A,
	SFXNUM_014B,
	SFXNUM_014C,
	SFXNUM_014D,
	SFXNUM_014E,
	SFXNUM_014F,
	SFXNUM_0150,
	SFXNUM_0151,
	SFXNUM_0152,
	SFXNUM_0153,
	SFXNUM_0154,
	SFXNUM_0155,
	SFXNUM_0156,
	SFXNUM_0157,
	SFXNUM_0158,
	SFXNUM_0159,
	SFXNUM_015A,
	SFXNUM_015B,
	SFXNUM_015C,
	SFXNUM_015D,
	SFXNUM_015E,
	SFXNUM_015F,
	SFXNUM_0160,
	SFXNUM_0161,
	SFXNUM_0162,
	SFXNUM_0163,
	SFXNUM_0164,
	SFXNUM_0165,
	SFXNUM_0166,
	SFXNUM_0167,
	SFXNUM_0168,
	SFXNUM_0169,
	SFXNUM_016A,
	SFXNUM_016B,
	SFXNUM_016C,
	SFXNUM_016D,
	SFXNUM_016E,
	SFXNUM_016F,
	SFXNUM_0170,
	SFXNUM_0171,
	SFXNUM_0172,
	SFXNUM_0173,
	SFXNUM_0174,
	SFXNUM_0175,
	SFXNUM_0176,
	SFXNUM_0177,
	SFXNUM_0178,
	SFXNUM_0179,
	SFXNUM_017A,
	SFXNUM_017B,
	SFXNUM_017C,
	SFXNUM_017D,
	SFXNUM_017E,
	SFXNUM_017F,
	SFXNUM_0180,
	SFXNUM_0181,
	SFXNUM_0182,
	SFXNUM_0183,
	SFXNUM_0184,
	SFXNUM_0185,
	SFXNUM_0186,
	SFXNUM_0187,
	SFXNUM_0188,
	SFXNUM_0189,
	SFXNUM_018A,
	SFXNUM_018B,
	SFXNUM_018C,
	SFXNUM_018D,
	SFXNUM_018E,
	SFXNUM_018F,
	SFXNUM_0190,
	SFXNUM_0191,
	SFXNUM_0192,
	SFXNUM_0193,
	SFXNUM_0194,
	SFXNUM_0195,
	SFXNUM_0196,
	SFXNUM_0197,
	SFXNUM_0198,
	SFXNUM_0199,
	SFXNUM_019A,
	SFXNUM_019B,
	SFXNUM_019C,
	SFXNUM_019D,
	SFXNUM_019E,
	SFXNUM_019F,
	SFXNUM_01A0,
	SFXNUM_01A1,
	SFXNUM_01A2,
	SFXNUM_01A3,
	SFXNUM_01A4,
	SFXNUM_01A5,
	SFXNUM_01A6,
	SFXNUM_01A7,
	SFXNUM_01A8,
	SFXNUM_01A9,
	SFXNUM_01AA,
	SFXNUM_01AB,
	SFXNUM_01AC,
	SFXNUM_01AD,
	SFXNUM_01AE,
	SFXNUM_01AF,
	SFXNUM_01B0,
	SFXNUM_01B1,
	SFXNUM_01B2,
	SFXNUM_01B3,
	SFXNUM_01B4_BIKE_ENGINE,
	SFXNUM_01B5,
	SFXNUM_01B6,
	SFXNUM_01B7,
	SFXNUM_01B8,
	SFXNUM_01B9,
	SFXNUM_01BA,
	SFXNUM_01BB,
	SFXNUM_01BC,
	SFXNUM_01BD_EYESPY_RUNNING,
	SFXNUM_01BE,
	SFXNUM_01BF,
	SFXNUM_01C0,
	SFXNUM_01C1,
	SFXNUM_01C2,
	SFXNUM_01C3,
	SFXNUM_01C4,
	SFXNUM_01C5,
	SFXNUM_01C6,
	SFXNUM_01C7,
	SFXNUM_01C8_SLAYER_BEEP,
	SFXNUM_01C9,
	SFXNUM_01CA,
	SFXNUM_01CB,
	SFXNUM_01CC,
	SFXNUM_01CD_PICKUP_SHIELD,
	SFXNUM_01CE,
	SFXNUM_01CF,
	SFXNUM_01D0,
	SFXNUM_01D1,
	SFXNUM_01D2_M_HUH,
	SFXNUM_01D3_M_WHA,
	SFXNUM_01D4,
	SFXNUM_01D5_INVEST_LIFT_ARRIVE,
	SFXNUM_01D6,
	SFXNUM_01D7,
	SFXNUM_01D8_RELOAD_REMOVE,
	SFXNUM_01D9_RELOAD_INSERT,
	SFXNUM_01DA_RELOAD_DROP,
	SFXNUM_01DB_RELOAD_RACK,
	SFXNUM_01DC,
	SFXNUM_01DD,
	SFXNUM_01DE,
	SFXNUM_01DF,
	SFXNUM_01E0,
	SFXNUM_01E1,
	SFXNUM_01E2,
	SFXNUM_01E3,
	SFXNUM_01E4,
	SFXNUM_01E5,
	SFXNUM_01E6,
	SFXNUM_01E7,
	SFXNUM_01E8,
	SFXNUM_01E9,
	SFXNUM_01EA,
	SFXNUM_01EB,
	SFXNUM_01EC,
	SFXNUM_01ED,
	SFXNUM_01EE,
	SFXNUM_01EF,
	SFXNUM_01F0,
	SFXNUM_01F1,
	SFXNUM_01F2,
	SFXNUM_01F3,
	SFXNUM_01F4,
	SFXNUM_01F5,
	SFXNUM_01F6,
	SFXNUM_01F7,
	SFXNUM_01F8,
	SFXNUM_01F9,
	SFXNUM_01FA,
	SFXNUM_01FB,
	SFXNUM_01FC,
	SFXNUM_01FD,
	SFXNUM_01FE,
	SFXNUM_01FF,
	SFXNUM_0200,
	SFXNUM_0201,
	SFXNUM_0202,
	SFXNUM_0203,
	SFXNUM_0204,
	SFXNUM_0205,
	SFXNUM_0206,
	SFXNUM_0207,
	SFXNUM_0208,
	SFXNUM_0209,
	SFXNUM_020A,
	SFXNUM_020B,
	SFXNUM_020C,
	SFXNUM_020D,
	SFXNUM_020E,
	SFXNUM_020F,
	SFXNUM_0210,
	SFXNUM_0211,
	SFXNUM_0212,
	SFXNUM_0213,
	SFXNUM_0214,
	SFXNUM_0215,
	SFXNUM_0216,
	SFXNUM_0217,
	SFXNUM_0218,
	SFXNUM_0219,
	SFXNUM_021A,
	SFXNUM_021B,
	SFXNUM_021C,
	SFXNUM_021D,
	SFXNUM_021E,
	SFXNUM_021F,
	SFXNUM_0220,
	SFXNUM_0221,
	SFXNUM_0222,
	SFXNUM_0223,
	SFXNUM_0224,
	SFXNUM_0225,
	SFXNUM_0226,
	SFXNUM_0227,
	SFXNUM_0228,
	SFXNUM_0229,
	SFXNUM_022A,
	SFXNUM_022B,
	SFXNUM_022C,
	SFXNUM_022D,
	SFXNUM_022E,
	SFXNUM_022F,
	SFXNUM_0230,
	SFXNUM_0231,
	SFXNUM_0232,
	SFXNUM_0233,
	SFXNUM_0234,
	SFXNUM_0235,
	SFXNUM_0236,
	SFXNUM_0237,
	SFXNUM_0238,
	SFXNUM_0239,
	SFXNUM_023A,
	SFXNUM_023B,
	SFXNUM_023C,
	SFXNUM_023D_DRC_COME_ON,
	SFXNUM_023E_DRC_TAKING_YOUR_TIME,
	SFXNUM_023F_DRC_WHAT,
	SFXNUM_0240_DRC_ARGH,
	SFXNUM_0241,
	SFXNUM_0242,
	SFXNUM_0243_DRC_OH_CRIKEY,
	SFXNUM_0244_DRC_GOODNESS_GRACIOUS,
	SFXNUM_0245_DRC_DONT_THEY_KNOW,
	SFXNUM_0246_DRC_STOP_THAT,
	SFXNUM_0247_DRC_GET_OUT_OF_HERE,
	SFXNUM_0248_DRC_KNOW_WHAT_YOURE_DOING,
	SFXNUM_0249_DRC_BEEN_HERE_BEFORE,
	SFXNUM_024A_DRC_THEYRE_SHOOTING,
	SFXNUM_024B_DRC_GOING_TO_THE_HELIPAD,
	SFXNUM_024C_DRC_ARGH,
	SFXNUM_024D_DRC_SYSTEMS_FAILURE,
	SFXNUM_024E_DRC_YOU_GO_ON,
	SFXNUM_024F_DRC_I_CANT_MAKE_IT,
	SFXNUM_0250_DRC_ARGH,
	SFXNUM_0251_DRC_ARGH,
	SFXNUM_0252_DRC_QUITE_ENOUGH,
	SFXNUM_0253,
	SFXNUM_0254,
	SFXNUM_0255,
	SFXNUM_0256_DRC_IM_DYING,
	SFXNUM_0257_DRC_GOODBYE,
	SFXNUM_0258_DRC_YOU_WERE_SUPPOSED,
	SFXNUM_0259_DRC_ARGH,
	SFXNUM_025A_DRC_ARGH,
	SFXNUM_025B_M0_WHAT_THE,
	SFXNUM_025C_M0_WHO_THE,
	SFXNUM_025D,
	SFXNUM_025E_M0_MEDIC,
	SFXNUM_025F_M0_OW,
	SFXNUM_0260_M0_YOU_SHOT_ME,
	SFXNUM_0261_M0_IM_HIT,
	SFXNUM_0262_M0_IM_TAKING_FIRE,
	SFXNUM_0263_M0_TAKING_DAMAGE,
	SFXNUM_0264_M0_HEY_YOU,
	SFXNUM_0265_M0_INTRUDER_ALERT,
	SFXNUM_0266_M0_GOT_A_CONTACT,
	SFXNUM_0267_M0_HOLYSH,
	SFXNUM_0268_M0_WHAT_THE_HELL,
	SFXNUM_0269,
	SFXNUM_026A,
	SFXNUM_026B_M0_HEAR_THAT,
	SFXNUM_026C_M0_WHATS_THAT_NOISE,
	SFXNUM_026D_M0_HEARD_A_NOISE,
	SFXNUM_026E_M0_ARE_YOU_OKAY,
	SFXNUM_026F_M0_GOT_A_MAN_DOWN,
	SFXNUM_0270_M0_HES_BOUGHT_IT,
	SFXNUM_0271,
	SFXNUM_0272_M0_INTRUDER_ALERT2,
	SFXNUM_0273_M0_WEVE_GOT_TROUBLE,
	SFXNUM_0274_M0_WEVE_GOT_PROBLEMS,
	SFXNUM_0275_M0_I_SEE_HER,
	SFXNUM_0276_M_DID_YOU_SEE_THAT,
	SFXNUM_0277_M0_THERE_SHE_IS,
	SFXNUM_0278_M0_THERE_MOVEMENT,
	SFXNUM_0279,
	SFXNUM_027A,
	SFXNUM_027B_M0_CLEAR_SHOT,
	SFXNUM_027C_M0_SHES_MINE,
	SFXNUM_027D_M0_OPEN_FIRE,
	SFXNUM_027E_M0_WIPE_HER_OUT,
	SFXNUM_027F_M0_WASTE_HER,
	SFXNUM_0280_M0_GIVE_IT_UP,
	SFXNUM_0281_M0_SURRENDER_NOW,
	SFXNUM_0282_M0_TAKE_THAT,
	SFXNUM_0283,
	SFXNUM_0284,
	SFXNUM_0285,
	SFXNUM_0286_M0_DAMN_IT_MISSED,
	SFXNUM_0287_M0_HOW_DID_I_MISS,
	SFXNUM_0288_M0_GOD_SAKES_SOMEONE_HIT_HER,
	SFXNUM_0289_M0_SHES_A_TRICKY_ONE,
	SFXNUM_028A_M0_COVER_ME,
	SFXNUM_028B_M0_WATCH_MY_BACK,
	SFXNUM_028C_M0_TAKE_COVER,
	SFXNUM_028D_M0_TAKE_COVER,
	SFXNUM_028E_M0_ILL_COVER_YOU,
	SFXNUM_028F_M0_GET_DOWN,
	SFXNUM_0290_M0_GO_TO_PLAN_B,
	SFXNUM_0291_M0_GET_THE_HELL_OUT_OF_HERE,
	SFXNUM_0292_M0_RETREAT,
	SFXNUM_0293_M0_CATCH,
	SFXNUM_0294_M0_EVERYBODY_DOWN,
	SFXNUM_0295,
	SFXNUM_0296,
	SFXNUM_0297_M0_FALL_BACK,
	SFXNUM_0298_M0_EVERYONE_BACK_OFF,
	SFXNUM_0299_M0_WITHDRAW,
	SFXNUM_029A_M0_FLANK_THE_TARGET,
	SFXNUM_029B_M0_LETS_SPLIT_UP,
	SFXNUM_029C_M0_SURROUND_HER,
	SFXNUM_029D_M0_GRENADE,
	SFXNUM_029E,
	SFXNUM_029F_M_YOU_BITCH,
	SFXNUM_02A0,
	SFXNUM_02A1_M_OH_MY_GOD,
	SFXNUM_02A2_M0_SHE_GOT_ME,
	SFXNUM_02A3_M0_GRAB_A_BODY_BAG,
	SFXNUM_02A4_M0_ONE_FOR_THE_MORGUE,
	SFXNUM_02A5_M0_REST_IN_PEACE,
	SFXNUM_02A6_M_TARGET_ELIMINATED,
	SFXNUM_02A7_M0_DONT_SHOOT_ME,
	SFXNUM_02A8_M0_I_GIVE_UP,
	SFXNUM_02A9_M0_YOU_WIN_I_SURRENDER,
	SFXNUM_02AA_JO_ARGH,
	SFXNUM_02AB_JO_ARGH,
	SFXNUM_02AC_JO_ARGH,
	SFXNUM_02AD_JO_ARGH,
	SFXNUM_02AE_JO_ARGH,
	SFXNUM_02AF_JO_ARGH,
	SFXNUM_02B0_JO_ARGH,
	SFXNUM_02B1_JO_ARGH,
	SFXNUM_02B2_JO_ARGH,
	SFXNUM_02B3_JO_ARGH,
	SFXNUM_02B4,
	SFXNUM_02B5,
	SFXNUM_02B6,
	SFXNUM_02B7,
	SFXNUM_02B8,
	SFXNUM_02B9,
	SFXNUM_02BA,
	SFXNUM_02BB,
	SFXNUM_02BC,
	SFXNUM_02BD,
	SFXNUM_02BE,
	SFXNUM_02BF,
	SFXNUM_02C0,
	SFXNUM_02C1,
	SFXNUM_02C2,
	SFXNUM_02C3,
	SFXNUM_02C4,
	SFXNUM_02C5,
	SFXNUM_02C6,
	SFXNUM_02C7,
	SFXNUM_02C8,
	SFXNUM_02C9,
	SFXNUM_02CA,
	SFXNUM_02CB,
	SFXNUM_02CC,
	SFXNUM_02CD,
	SFXNUM_02CE,
	SFXNUM_02CF,
	SFXNUM_02D0,
	SFXNUM_02D1,
	SFXNUM_02D2,
	SFXNUM_02D3,
	SFXNUM_02D4,
	SFXNUM_02D5,
	SFXNUM_02D6,
	SFXNUM_02D7,
	SFXNUM_02D8,
	SFXNUM_02D9,
	SFXNUM_02DA,
	SFXNUM_02DB,
	SFXNUM_02DC,
	SFXNUM_02DD,
	SFXNUM_02DE,
	SFXNUM_02DF,
	SFXNUM_02E0,
	SFXNUM_02E1,
	SFXNUM_02E2,
	SFXNUM_02E3,
	SFXNUM_02E4,
	SFXNUM_02E5,
	SFXNUM_02E6,
	SFXNUM_02E7,
	SFXNUM_02E8,
	SFXNUM_02E9,
	SFXNUM_02EA,
	SFXNUM_02EB,
	SFXNUM_02EC,
	SFXNUM_02ED,
	SFXNUM_02EE,
	SFXNUM_02EF,
	SFXNUM_02F0,
	SFXNUM_02F1,
	SFXNUM_02F2,
	SFXNUM_02F3,
	SFXNUM_02F4,
	SFXNUM_02F5,
	SFXNUM_02F6,
	SFXNUM_02F7,
	SFXNUM_02F8,
	SFXNUM_02F9,
	SFXNUM_02FA,
	SFXNUM_02FB,
	SFXNUM_02FC,
	SFXNUM_02FD_M_HOLY,
	SFXNUM_02FE_M_WHAT_THE_HELL,
	SFXNUM_02FF_M1_WHA,
	SFXNUM_0300_M_OH_MY_GOD,
	SFXNUM_0301_M1_IM_HIT_IM_HIT,
	SFXNUM_0302_M1_IM_BLEEDING,
	SFXNUM_0303_M_OH_GOD_IM_HIT,
	SFXNUM_0304_M1_HELP_ME_OUT,
	SFXNUM_0305_M1_IM_IN_TROUBLE,
	SFXNUM_0306_M1_COME_HERE,
	SFXNUM_0307_M1_THERES_SOMEONE_HERE,
	SFXNUM_0308_M1_GET_HER,
	SFXNUM_0309_M1_WHOA,
	SFXNUM_030A_M_MY_GOD,
	SFXNUM_030B_M1_IS_THAT_A_BULLET,
	SFXNUM_030C,
	SFXNUM_030D,
	SFXNUM_030E_M1_THAT_SOUNDED_LIKE,
	SFXNUM_030F_M1_GUNFIRE,
	SFXNUM_0310_M1_SOMEONES_SHOOTING,
	SFXNUM_0311_M_ARE_YOU_OKAY,
	SFXNUM_0312_M_YOURE_BLEEDING,
	SFXNUM_0313_M_NOOO,
	SFXNUM_0314_M_OH_GOD_HES_DEAD,
	SFXNUM_0315,
	SFXNUM_0316_M1_HES_GONE,
	SFXNUM_0317,
	SFXNUM_0318_M_YOU_MURDERER,
	SFXNUM_0319,
	SFXNUM_031A,
	SFXNUM_031B,
	SFXNUM_031C_M1_M2_LOOK_OUT_SHES_COMING,
	SFXNUM_031D_M1_M2_TAKE_COVER,
	SFXNUM_031E_M1_M2_LOOK_OUT_LOOK_OUT,
	SFXNUM_031F_M1_OVER_THERE,
	SFXNUM_0320_M1_HALT,
	SFXNUM_0321_M1_FREEZE,
	SFXNUM_0322_M1_LAST_MISTAKE,
	SFXNUM_0323_M1_WHAT_ARE_YOU_WAITING_FOR,
	SFXNUM_0324_M1_BRING_IT_ON,
	SFXNUM_0325_M1_TAKE_HER_DOWN,
	SFXNUM_0326_M1_EVERYBODY_GET_HER,
	SFXNUM_0327_M1_ATTACK,
	SFXNUM_0328,
	SFXNUM_0329_M1_YEAH_BABY,
	SFXNUM_032A,
	SFXNUM_032B,
	SFXNUM_032C,
	SFXNUM_032D,
	SFXNUM_032E_M_BLOODY_STUPID_GUN,
	SFXNUM_032F_M1_MY_GUN_ITS_USELESS,
	SFXNUM_0330_M_DAMN_IT,
	SFXNUM_0331_M1_STOP_DODGING,
	SFXNUM_0332_M1_SOMEONE_HIT_HER,
	SFXNUM_0333_M_DAMN_SHES_GOOD,
	SFXNUM_0334_M_COVER_MY_ASS,
	SFXNUM_0335_M1_COVER_ME_NOW,
	SFXNUM_0336_M1_IM_GOING_FOR_COVER,
	SFXNUM_0337_M1_GO_FOR_IT,
	SFXNUM_0338_M1_GO_GO_GO,
	SFXNUM_0339_M1_RUN,
	SFXNUM_033A_M1_SHES_TOO_GOOD_RUN,
	SFXNUM_033B_M1_GET_SOME_BACKUP,
	SFXNUM_033C_M1_EVACUATE_THE_AREA,
	SFXNUM_033D_M1_CATCH_THIS,
	SFXNUM_033E_M_TIME_TO_DIE,
	SFXNUM_033F_M1_HERE_KEEP_IT,
	SFXNUM_0340,
	SFXNUM_0341,
	SFXNUM_0342_M1_GRENADE,
	SFXNUM_0343_M1_WITHDRAW,
	SFXNUM_0344_M1_FALL_BACK,
	SFXNUM_0345_M1_EVERYONE_GET_BACK,
	SFXNUM_0346_M1_SURROUND_HER,
	SFXNUM_0347_M1_SPREAD_OUT,
	SFXNUM_0348_M1_SPLIT_UP,
	SFXNUM_0349_M1_PLEASE_DONT,
	SFXNUM_034A_M1_DONT_SHOOT,
	SFXNUM_034B_M1_IM_ONLY_DOING_MY_JOB,
	SFXNUM_034C_M_WAIL,
	SFXNUM_034D_M1_WHY_ME,
	SFXNUM_034E_M1_CHOKING,
	SFXNUM_034F,
	SFXNUM_0350,
	SFXNUM_0351_M_NOOO,
	SFXNUM_0352,
	SFXNUM_0353,
	SFXNUM_0354,
	SFXNUM_0355_M1_OUTSTANDING,
	SFXNUM_0356_M1_IM_JUST_TOO_GOOD,
	SFXNUM_0357_M1_YEEHAH_GOT_ONE,
	SFXNUM_0358,
	SFXNUM_0359,
	SFXNUM_035A_M1_ANOTHER_ONE_BITES_THE_DUST,
	SFXNUM_035B_M0_M1_LOOK_OUT_LOOK_OUT,
	SFXNUM_035C_M0_M1_ITS_A_GRENADE,
	SFXNUM_035D_M0_M1_CLEAR_THE_AREA,
	SFXNUM_035E,
	SFXNUM_035F,
	SFXNUM_0360,
	SFXNUM_0361,
	SFXNUM_0362,
	SFXNUM_0363,
	SFXNUM_0364,
	SFXNUM_0365,
	SFXNUM_0366,
	SFXNUM_0367,
	SFXNUM_0368,
	SFXNUM_0369,
	SFXNUM_036A,
	SFXNUM_036B,
	SFXNUM_036C,
	SFXNUM_036D,
	SFXNUM_036E,
	SFXNUM_036F,
	SFXNUM_0370,
	SFXNUM_0371,
	SFXNUM_0372,
	SFXNUM_0373,
	SFXNUM_0374,
	SFXNUM_0375,
	SFXNUM_0376,
	SFXNUM_0377,
	SFXNUM_0378,
	SFXNUM_0379,
	SFXNUM_037A,
	SFXNUM_037B_F_HEY,
	SFXNUM_037C_F_HUH,
	SFXNUM_037D,
	SFXNUM_037E_F_IM_WOUNDED,
	SFXNUM_037F_F_HELP_ME_OUT,
	SFXNUM_0380_F_IM_IN_TROUBLE,
	SFXNUM_0381_F_GET_HER,
	SFXNUM_0382_F_HEY_YOU_COME_HERE,
	SFXNUM_0383,
	SFXNUM_0384_F_TARGET_ATTACKING,
	SFXNUM_0385_F_UNDER_FIRE,
	SFXNUM_0386,
	SFXNUM_0387_F_WERE_UNDER_FIRE,
	SFXNUM_0388,
	SFXNUM_0389_F,
	SFXNUM_038A_F_SOMEONES_SHOOTING,
	SFXNUM_038B,
	SFXNUM_038C,
	SFXNUM_038D_F_UNIT_DOWN,
	SFXNUM_038E,
	SFXNUM_038F,
	SFXNUM_0390,
	SFXNUM_0391,
	SFXNUM_0392,
	SFXNUM_0393,
	SFXNUM_0394,
	SFXNUM_0395,
	SFXNUM_0396_F_COME_ON,
	SFXNUM_0397,
	SFXNUM_0398_F_EVERYONE_GET_HER,
	SFXNUM_0399_F_ATTACK,
	SFXNUM_039A_F_DID_THAT_HURT,
	SFXNUM_039B_F_YOU_WANT_SOME_MORE,
	SFXNUM_039C,
	SFXNUM_039D,
	SFXNUM_039E,
	SFXNUM_039F_F_THIS_GUNS_USELESS,
	SFXNUM_03A0,
	SFXNUM_03A1_F_STAND_STILL,
	SFXNUM_03A2_F_SOMEONE_HIT_HER,
	SFXNUM_03A3_F_DAMN_SHES_GOOD,
	SFXNUM_03A4_F_COVER_ME,
	SFXNUM_03A5,
	SFXNUM_03A6_F_TAKE_COVER,
	SFXNUM_03A7_F_GO_FOR_IT,
	SFXNUM_03A8,
	SFXNUM_03A9_F_RUN,
	SFXNUM_03AA_F_GET_REINFORCEMENTS,
	SFXNUM_03AB_F_EVACUATE_THE_AREA,
	SFXNUM_03AC_F_RETREAT,
	SFXNUM_03AD_F_CATCH_THIS,
	SFXNUM_03AE_F_TIME_TO_DIE,
	SFXNUM_03AF,
	SFXNUM_03B0_F_WITHDRAW,
	SFXNUM_03B1_F_FALL_BACK,
	SFXNUM_03B2,
	SFXNUM_03B3_F_SPREAD_OUT,
	SFXNUM_03B4_F_SPLIT_UP,
	SFXNUM_03B5_F_PLEASE_DONT,
	SFXNUM_03B6_F_DONT_SHOOT,
	SFXNUM_03B7_F_WHY_ME,
	SFXNUM_03B8_F_NOO,
	SFXNUM_03B9_F_MY_GOD,
	SFXNUM_03BA,
	SFXNUM_03BB,
	SFXNUM_03BC_F_GET_A_CLEANER,
	SFXNUM_03BD,
	SFXNUM_03BE_F_IM_JUST_TOO_GOOD,
	SFXNUM_03BF,
	SFXNUM_03C0_F_SUCH_A_WASTE,
	SFXNUM_03C1_F_LOOK_OUT,
	SFXNUM_03C2_F_ITS_A_GRENADE,
	SFXNUM_03C3,
	SFXNUM_03C4_M2_HOW_THE,
	SFXNUM_03C5_M2_HEY,
	SFXNUM_03C6_M2_STOP,
	SFXNUM_03C7_M_GEEZ_THAT_HURT,
	SFXNUM_03C8_M2_WHY_YOU,
	SFXNUM_03C9,
	SFXNUM_03CA,
	SFXNUM_03CB,
	SFXNUM_03CC,
	SFXNUM_03CD_M2_IM_INJURED,
	SFXNUM_03CE_M2_IM_HIT_IM_HIT,
	SFXNUM_03CF_M_DAMN_IT_IM_TAKING_FIRE,
	SFXNUM_03D0_M2_TARGET_SIGHTED,
	SFXNUM_03D1_M2_COME_ON_MAN,
	SFXNUM_03D2_M_GOD_DAMN_IT,
	SFXNUM_03D3_M2_THAT_WAS_CLOSE,
	SFXNUM_03D4_M_HOLY_MOLY,
	SFXNUM_03D5_M2_AY_CARAMBA,
	SFXNUM_03D6_M2_LISTEN_GUNSHOTS,
	SFXNUM_03D7_M2_SOMEONES_NEARBY,
	SFXNUM_03D8,
	SFXNUM_03D9_M2_BODY_COUNTS_TOO_HIGH,
	SFXNUM_03DA_M2_I_NEVER_LIKED_HIM_ANYWAY,
	SFXNUM_03DB_M2_THAT_WAS_MY_BEST_FRIEND,
	SFXNUM_03DC_M_YOU_KILLED_MY_BUDDY,
	SFXNUM_03DD,
	SFXNUM_03DE,
	SFXNUM_03DF,
	SFXNUM_03E0,
	SFXNUM_03E1_M2_WATCH_OUT,
	SFXNUM_03E2_M2_HELP_ME_OUT,
	SFXNUM_03E3_M2_WEVE_GOT_AN_INTRUDER,
	SFXNUM_03E4_M2_GET_HER,
	SFXNUM_03E5_M2_THERE_ATTACK,
	SFXNUM_03E6_M2_HEY_YOU_STOP,
	SFXNUM_03E7_M2_COME_ON_MAN2,
	SFXNUM_03E8_M2_DIE,
	SFXNUM_03E9_M2_TAKE_THIS,
	SFXNUM_03EA_M2_MOVE_IN,
	SFXNUM_03EB_M2_YOURE_OUT_OF_YOUR_LEAGUE,
	SFXNUM_03EC_M2_LET_HER_HAVE_IT,
	SFXNUM_03ED_M2_SURRENDER_OR_DIE,
	SFXNUM_03EE_M2_I_HAVE_YOU_NOW,
	SFXNUM_03EF_M2_YOU_WANT_BEAT_ME,
	SFXNUM_03F0,
	SFXNUM_03F1,
	SFXNUM_03F2,
	SFXNUM_03F3_M_DANG_MISSED_AGAIN,
	SFXNUM_03F4_M2_I_DONT_BELIEVE_IT,
	SFXNUM_03F5_M_DAMN_YOU,
	SFXNUM_03F6_M_HELL_SHES_GOOD,
	SFXNUM_03F7_M2_STOP_MOVING,
	SFXNUM_03F8_M2_NO_ESCAPE_FOR_YOU,
	SFXNUM_03F9_M2_HELP_ME_OUT_HERE,
	SFXNUM_03FA_M2_HEY_DISTRACT_HER,
	SFXNUM_03FB_M2_KEEP_HER_OCCUPIED,
	SFXNUM_03FC_M2_MOVE_IT_MOVE_IT,
	SFXNUM_03FD_M2_GET_TO_COVER_NOW,
	SFXNUM_03FE_M2_RUN_FOR_IT,
	SFXNUM_03FF_M2_RETREAT,
	SFXNUM_0400_M_LETS_GET_THE_HELL_OUT_OF_HERE,
	SFXNUM_0401_M2_GET_BACK_GET_BACK,
	SFXNUM_0402,
	SFXNUM_0403_M2_FIRE_IN_THE_HOLE,
	SFXNUM_0404,
	SFXNUM_0405_M2_HERES_A_LITTLE_PRESENT_FOR_YA,
	SFXNUM_0406,
	SFXNUM_0407_M2_TRY_THIS_FOR_SIZE,
	SFXNUM_0408_M2_GET_OUT_OF_THE_WAY,
	SFXNUM_0409_M2_FALL_BACK,
	SFXNUM_040A_M2_MOVE_OUT,
	SFXNUM_040B_M2_TEAM_UP_GUYS,
	SFXNUM_040C_M2_COME_ON_AROUND_THE_SIDE,
	SFXNUM_040D_M2_SCATTER,
	SFXNUM_040E_M2_I_DONT_LIKE_THIS_ANY_MORE,
	SFXNUM_040F_M2_DONT_HURT_ME,
	SFXNUM_0410_M2_YOU_WIN_I_GIVE_UP,
	SFXNUM_0411_M_NOOO,
	SFXNUM_0412_M_YOU_GOT_ME,
	SFXNUM_0413_M_GOD_DAMN_IT,
	SFXNUM_0414_M_OH_GOD_IM_DYING,
	SFXNUM_0415_M2_I_DONT_WANT_TO_DIE,
	SFXNUM_0416,
	SFXNUM_0417_M2_ITS_ALL_OVER_FOR_THIS_ONE,
	SFXNUM_0418,
	SFXNUM_0419_M_THATS_A_CONFIRMED_KILL,
	SFXNUM_041A,
	SFXNUM_041B_M2_IM_THE_MAN,
	SFXNUM_041C_M2_BOY_THAT_WAS_CLOSE,
	SFXNUM_041D_M2_DID_YOU_SEE_THAT,
	SFXNUM_041E,
	SFXNUM_041F,
	SFXNUM_0420_M2_GET_BACK_QUICK,
	SFXNUM_0421_M2_WERE_GONNA_DIE,
	SFXNUM_0422_M_GOD_RUN,
	SFXNUM_0423,
	SFXNUM_0424,
	SFXNUM_0425,
	SFXNUM_0426,
	SFXNUM_0427,
	SFXNUM_0428,
	SFXNUM_0429,
	SFXNUM_042A,
	SFXNUM_042B_DOOR,
	SFXNUM_042C_DOOR,
	SFXNUM_042D,
	SFXNUM_042E_DISGUISE_ON,
	SFXNUM_042F,
	SFXNUM_0430,
	SFXNUM_0431,
	SFXNUM_0432,
	SFXNUM_0433_RELOAD_FARSIGHT,
	SFXNUM_0434,
	SFXNUM_0435,
	SFXNUM_0436,
	SFXNUM_0437,
	SFXNUM_0438,
	SFXNUM_0439,
	SFXNUM_043A,
	SFXNUM_043B,
	SFXNUM_043C,
	SFXNUM_043D,
	SFXNUM_043E_MENU_SUBFOCUS,
	SFXNUM_043F,
	SFXNUM_0440,
	SFXNUM_0441_MENU_FOCUS,
	SFXNUM_0442,
	SFXNUM_0443_CIV_OH_MY_GOD,
	SFXNUM_0444_CIV_THERES_A_MANIAC,
	SFXNUM_0445_CIV_RUN_GET_AWAY_FROM_THE_PSYCHO,
	SFXNUM_0446_CIV_GREETINGS_CITIZEN,
	SFXNUM_0447_CIV_HOWS_IT_GOING,
	SFXNUM_0448_CIV_GUNS_DONT_SCARE_ME,
	SFXNUM_0449_CIV_KEEP_AWAY_FROM_THIS_CAR,
	SFXNUM_044A_CIV_HEY_I_SAW_THAT,
	SFXNUM_044B_FBI_WE_HAVE_AN_INTRUDER,
	SFXNUM_044C,
	SFXNUM_044D,
	SFXNUM_044E_M_WHAT_THE_HELL_WAS_THAT,
	SFXNUM_044F_M_WHAT_A_MESS,
	SFXNUM_0450_M_I_NEVER_LIKED_THAT_ROBOT_ANYWAY,
	SFXNUM_0451_M_THE_BOSS_AINT_GONNA_BE_PLEASED,
	SFXNUM_0452_M_WE_COULD_ALWAYS_GET_ANOTHER_ONE,
	SFXNUM_0453,
	SFXNUM_0454,
	SFXNUM_0455_ALARM_CHICAGO,
	SFXNUM_0456,
	SFXNUM_0457,
	SFXNUM_0458,
	SFXNUM_0459_FBI_CODE_2_SITUATION,
	SFXNUM_045A_FBI_REQUEST_BACKUP_IMMEDIATELY,
	SFXNUM_045B,
	SFXNUM_045C,
	SFXNUM_045D_CIV_TAKE_IT_EASY,
	SFXNUM_045E_CIV_I_DONT_WANT_ANY_TROUBLE,
	SFXNUM_045F_CIV_QUICK_DOWN_THERE,
	SFXNUM_0460,
	SFXNUM_0461_CIV_HEY_SUGAR_WANNA_PARTY,
	SFXNUM_0462,
	SFXNUM_0463_CIV_TAKE_THE_WALLET,
	SFXNUM_0464_CIV_JUST_YOU_TRY_IT_MISSY,
	SFXNUM_0465_CIV_HEY_BABY,
	SFXNUM_0466_CIV_WHISTLE,
	SFXNUM_0467_CIV_SECURITY_SECURITY_SHES_OVER_THERE,
	SFXNUM_0468_CIV_GET_ME_OUT_OF_HERE,
	SFXNUM_0469_M_THE_DOORS_ARE_CLOSED,
	SFXNUM_046A_ROBOT_RADIO1,
	SFXNUM_046B_ROBOT_RADIO2,
	SFXNUM_046C_ROBOT_RADIO3,
	SFXNUM_046D,
	SFXNUM_046E_JO_JUMPING,
	SFXNUM_046F_JO_LANDING,
	SFXNUM_0470,
	SFXNUM_0471,
	SFXNUM_0472,
	SFXNUM_0473,
	SFXNUM_0474,
	SFXNUM_0475,
	SFXNUM_0476_JO_PANTING,
	SFXNUM_0477,
	SFXNUM_0478,
	SFXNUM_0479,
	SFXNUM_047A,
	SFXNUM_047B,
	SFXNUM_047C,
	SFXNUM_047D,
	SFXNUM_047E,
	SFXNUM_047F,
	SFXNUM_0480,
	SFXNUM_0481,
	SFXNUM_0482,
	SFXNUM_0483,
	SFXNUM_0484,
	SFXNUM_0485,
	SFXNUM_0486,
	SFXNUM_0487,
	SFXNUM_0488,
	SFXNUM_0489,
	SFXNUM_048A,
	SFXNUM_048B,
	SFXNUM_048C,
	SFXNUM_048D,
	SFXNUM_048E,
	SFXNUM_048F,
	SFXNUM_0490,
	SFXNUM_0491,
	SFXNUM_0492,
	SFXNUM_0493,
	SFXNUM_0494,
	SFXNUM_0495,
	SFXNUM_0496,
	SFXNUM_0497,
	SFXNUM_0498,
	SFXNUM_0499,
	SFXNUM_049A,
	SFXNUM_049B,
	SFXNUM_049C,
	SFXNUM_049D,
	SFXNUM_049E,
	SFXNUM_049F,
	SFXNUM_04A0,
	SFXNUM_04A1,
	SFXNUM_04A2,
	SFXNUM_04A3,
	SFXNUM_04A4,
	SFXNUM_04A5,
	SFXNUM_04A6,
	SFXNUM_04A7,
	SFXNUM_04A8,
	SFXNUM_04A9,
	SFXNUM_04AA,
	SFXNUM_04AB,
	SFXNUM_04AC_ALARM_INFILTRATION,
	SFXNUM_04AD,
	SFXNUM_04AE,
	SFXNUM_04AF,
	SFXNUM_04B0,
	SFXNUM_04B1,
	SFXNUM_04B2,
	SFXNUM_04B3,
	SFXNUM_04B4,
	SFXNUM_04B5,
	SFXNUM_04B6,
	SFXNUM_04B7,
	SFXNUM_04B8,
	SFXNUM_04B9,
	SFXNUM_04BA,
	SFXNUM_04BB,
	SFXNUM_04BC,
	SFXNUM_04BD,
	SFXNUM_04BE,
	SFXNUM_04BF,
	SFXNUM_04C0,
	SFXNUM_04C1,
	SFXNUM_04C2,
	SFXNUM_04C3_F_MY_EYES,
	SFXNUM_04C4,
	SFXNUM_04C5,
	SFXNUM_04C6_M0_MY_GUN,
	SFXNUM_04C7_M0_TRIGGER_THE_ALARM,
	SFXNUM_04C8_M_WHAT_THE_HELL,
	SFXNUM_04C9_M0_HELLO_THERE,
	SFXNUM_04CA_M0_WHATS_THIS,
	SFXNUM_04CB_M0_IM_SURE_I_HEARD_A_NOISE,
	SFXNUM_04CC_M0_HEARING_THINGS,
	SFXNUM_04CD_M_GEEZ,
	SFXNUM_04CE_M1_WARN_THE_OTHERS,
	SFXNUM_04CF_M1_WHAT_IS_IT,
	SFXNUM_04D0_M1_HOW_DID_THAT_GET_HERE,
	SFXNUM_04D1_M1_DONT_TOUCH_IT,
	SFXNUM_04D2_M1_I_CANT_SEE_ANYBODY,
	SFXNUM_04D3_M1_THERES_NO_ONE_HERE,
	SFXNUM_04D4_M2_ACTIVATE_THE_ALARM,
	SFXNUM_04D5_M2_IS_IT_DANGEROUS,
	SFXNUM_04D6_M2_DONT_MOVE,
	SFXNUM_04D7_M2_STAY_BACK,
	SFXNUM_04D8_M2_I_BET_THIS_IS_ANOTHER_DRILL,
	SFXNUM_04D9_M2_ANOTHER_FALSE_ALARM,
	SFXNUM_04DA,
	SFXNUM_04DB,
	SFXNUM_04DC,
	SFXNUM_04DD,
	SFXNUM_04DE,
	SFXNUM_04DF,
	SFXNUM_04E0,
	SFXNUM_04E1,
	SFXNUM_04E2,
	SFXNUM_04E3,
	SFXNUM_04E4,
	SFXNUM_04E5,
	SFXNUM_04E6,
	SFXNUM_04E7,
	SFXNUM_04E8,
	SFXNUM_04E9,
	SFXNUM_04EA,
	SFXNUM_04EB,
	SFXNUM_04EC,
	SFXNUM_04ED,
	SFXNUM_04EE,
	SFXNUM_04EF,
	SFXNUM_04F0,
	SFXNUM_04F1,
	SFXNUM_04F2,
	SFXNUM_04F3,
	SFXNUM_04F4,
	SFXNUM_04F5,
	SFXNUM_04F6,
	SFXNUM_04F7,
	SFXNUM_04F8,
	SFXNUM_04F9,
	SFXNUM_04FA,
	SFXNUM_04FB_RELOAD,
	SFXNUM_04FC,
	SFXNUM_04FD,
	SFXNUM_04FE,
	SFXNUM_04FF_CAMSPY_SHUTTER,
	SFXNUM_0500,
	SFXNUM_0501,
	SFXNUM_0502,
	SFXNUM_0503,
	SFXNUM_0504,
	SFXNUM_0505,
	SFXNUM_0506,
	SFXNUM_0507,
	SFXNUM_0508,
	SFXNUM_0509,
	SFXNUM_050A,
	SFXNUM_050B,
	SFXNUM_050C,
	SFXNUM_050D,
	SFXNUM_050E,
	SFXNUM_050F,
	SFXNUM_0510,
	SFXNUM_0511,
	SFXNUM_0512,
	SFXNUM_0513,
	SFXNUM_0514,
	SFXNUM_0515_SECURE_THE_PERIMETER,
	SFXNUM_0516_WHOEVER_SHE_IS_GET_HER,
	SFXNUM_0517,
	SFXNUM_0518,
	SFXNUM_0519,
	SFXNUM_051A,
	SFXNUM_051B_ELVIS_INTERGALACTIC_PEACE,
	SFXNUM_051C_ELVIS_EAT_HOT_LEAD_WEIRDOS,
	SFXNUM_051D_ELVIS_KISS_MY_ALIEN_BUTT,
	SFXNUM_051E_ELVIS_ILL_KICK_YOUR_ASS,
	SFXNUM_051F_ELVIS_FOR_YOUR_OWN_GOOD,
	SFXNUM_0520_ELVIS_YOU_DARE_SHOOT_AT_ME,
	SFXNUM_0521_ELVIS_DONT_MESS_WITH_THE_MAIAN,
	SFXNUM_0522_ELVIS_IM_BAD,
	SFXNUM_0523_ELVIS_ALL_GOING_WRONG,
	SFXNUM_0524_ELVIS_WATCH_THE_SUIT,
	SFXNUM_0525_ELVIS_HEHE,
	SFXNUM_0526,
	SFXNUM_0527,
	SFXNUM_0528,
	SFXNUM_0529_SKEDAR_ROAR,
	SFXNUM_052A_SKEDAR_ROAR,
	SFXNUM_052B_SKEDAR_ROAR,
	SFXNUM_052C_SKEDAR_ROAR,
	SFXNUM_052D_SKEDAR_ROAR,
	SFXNUM_052E_SKEDAR_ROAR,
	SFXNUM_052F_SKEDAR_ROAR,
	SFXNUM_0530_SKEDAR_ROAR,
	SFXNUM_0531_SKEDAR_ROAR,
	SFXNUM_0532_SKEDAR_ROAR,
	SFXNUM_0533_SKEDAR_ROAR,
	SFXNUM_0534_SKEDAR_ROAR,
	SFXNUM_0535_SKEDAR_ROAR,
	SFXNUM_0536_SKEDAR_ROAR,
	SFXNUM_0537_SKEDAR_ROAR,
	SFXNUM_0538_SKEDAR_ROAR,
	SFXNUM_0539_SKEDAR_ROAR,
	SFXNUM_053A_SKEDAR_ROAR,
	SFXNUM_053B,
	SFXNUM_053C,
	SFXNUM_053D,
	SFXNUM_053E,
	SFXNUM_053F,
	SFXNUM_0540,
	SFXNUM_0541,
	SFXNUM_0542,
	SFXNUM_0543,
	SFXNUM_0544,
	SFXNUM_0545,
	SFXNUM_0546,
	SFXNUM_0547,
	SFXNUM_0548,
	SFXNUM_0549,
	SFXNUM_054A,
	SFXNUM_054B,
	SFXNUM_054C,
	SFXNUM_054D,
	SFXNUM_054E,
	SFXNUM_054F,
	SFXNUM_0550,
	SFXNUM_0551,
	SFXNUM_0552,
	SFXNUM_0553,
	SFXNUM_0554,
	SFXNUM_0555,
	SFXNUM_0556,
	SFXNUM_0557,
	SFXNUM_0558,
	SFXNUM_0559,
	SFXNUM_055A,
	SFXNUM_055B,
	SFXNUM_055C,
	SFXNUM_055D,
	SFXNUM_055E,
	SFXNUM_055F,
	SFXNUM_0560,
	SFXNUM_0561,
	SFXNUM_0562,
	SFXNUM_0563,
	SFXNUM_0564,
	SFXNUM_0565,
	SFXNUM_0566,
	SFXNUM_0567,
	SFXNUM_0568,
	SFXNUM_0569,
	SFXNUM_056A,
	SFXNUM_056B,
	SFXNUM_056C,
	SFXNUM_056D,
	SFXNUM_056E,
	SFXNUM_056F,
	SFXNUM_0570,
	SFXNUM_0571,
	SFXNUM_0572,
	SFXNUM_0573,
	SFXNUM_0574,
	SFXNUM_0575,
	SFXNUM_0576,
	SFXNUM_0577,
	SFXNUM_0578,
	SFXNUM_0579,
	SFXNUM_057A,
	SFXNUM_057B,
	SFXNUM_057C,
	SFXNUM_057D,
	SFXNUM_057E,
	SFXNUM_057F,
	SFXNUM_0580,
	SFXNUM_0581,
	SFXNUM_0582,
	SFXNUM_0583,
	SFXNUM_0584,
	SFXNUM_0585,
	SFXNUM_0586,
	SFXNUM_0587,
	SFXNUM_0588,
	SFXNUM_0589,
	SFXNUM_058A,
	SFXNUM_058B,
	SFXNUM_058C,
	SFXNUM_058D,
	SFXNUM_058E,
	SFXNUM_058F,
	SFXNUM_0590,
	SFXNUM_0591,
	SFXNUM_0592,
	SFXNUM_0593,
	SFXNUM_0594,
	SFXNUM_0595,
	SFXNUM_0596,
	SFXNUM_0597,
	SFXNUM_0598,
	SFXNUM_0599,
	SFXNUM_059A,
	SFXNUM_059B,
	SFXNUM_059C,
	SFXNUM_059D_INFIL_STATIC_SHORT,
	SFXNUM_059E_INFIL_STATIC_MEDIUM,
	SFXNUM_059F_INFIL_STATIC_LONG,
	SFXNUM_05A0,
	SFXNUM_05A1,
	SFXNUM_05A2,
	SFXNUM_05A3,
	SFXNUM_05A4,
	SFXNUM_05A5,
	SFXNUM_05A6,
	SFXNUM_05A7,
	SFXNUM_05A8,
	SFXNUM_05A9,
	SFXNUM_05AA,
	SFXNUM_05AB_COUGH,
	SFXNUM_05AC_COUGH,
	SFXNUM_05AD_COUGH,
	SFXNUM_05AE_COUGH,
	SFXNUM_05AF_COUGH,
	SFXNUM_05B0_COUGH,
	SFXNUM_05B1_GURGLE,
	SFXNUM_05B2_GURGLE,
	SFXNUM_05B3,
	SFXNUM_05B4,
	SFXNUM_05B5,
	SFXNUM_05B6_JO_LANDING,
	SFXNUM_05B7_JO_LANDING,
	SFXNUM_05B8_MP_SCOREPOINT,
	SFXNUM_05B9_MP_HILLENTERED,
	SFXNUM_05BA,
	SFXNUM_05BB_MENU_SWIPE,
	SFXNUM_05BC_MENU_OPENDIALOG,
	SFXNUM_05BD,
	SFXNUM_05BE_SHOULD_HAVE_COME_HERE_GIRL,
	SFXNUM_05BF_WERE_TAKING_OVER,
	SFXNUM_05C0,
	SFXNUM_05C1,
	SFXNUM_05C2_ALARM_ATTACKSHIP,
	SFXNUM_05C3,
	SFXNUM_05C4,
	SFXNUM_05C5,
	SFXNUM_05C6,
	SFXNUM_05C7,
	SFXNUM_05C8_HEARTBEAT,
	SFXNUM_05C9_JO_BOOST_ACTIVATE,
	SFXNUM_05CA,
	SFXNUM_05CB,
	SFXNUM_05CC,
	SFXNUM_05CD,
	SFXNUM_05CE,
	SFXNUM_05CF,
	SFXNUM_05D0,
	SFXNUM_05D1,
	SFXNUM_05D2,
	SFXNUM_05D3,
	SFXNUM_05D4_FR_ALARM,
	SFXNUM_05D5_FR_LIGHTSON,
	SFXNUM_05D6_FR_LIGHTSOFF,
	SFXNUM_05D7,
	SFXNUM_05D8_WOOD_BREAK,
	SFXNUM_05D9_FR_CONVEYER,
	SFXNUM_05DA_FR_CONVEYER_STOP,
	SFXNUM_05DB_TRAINING_FAIL,
	SFXNUM_05DC_TRAINING_COMPLETE,
	SFXNUM_05DD_MENU_SELECT,
	SFXNUM_05DE,
	SFXNUM_05DF_MAIAN_ARGH,
	SFXNUM_05E0_MAIAN_ARGH,
	SFXNUM_05E1_MAIAN_ARGH,
	SFXNUM_05E2_MAIAN,
	SFXNUM_05E3_MAIAN,
	SFXNUM_05E4_MAIAN,
	SFXNUM_05E5_MAIAN,
	SFXNUM_05E6_MAIAN,
	SFXNUM_05E7_MAIAN,
	SFXNUM_05E8,
	SFXNUM_05E9,
	SFXNUM_05EA,
	SFXNUM_05EB,
	SFXNUM_05EC,
	SFXNUM_05ED,
	SFXNUM_05EE,
	SFXNUM_05EF,
	SFXNUM_05F0,
	SFXNUM_05F1,
	SFXNUM_05F2,
	SFXNUM_05F3,
	SFXNUM_05F4,
	SFXNUM_05F5,
	SFXNUM_05F6,
	SFXNUM_05F7,
	SFXNUM_05F8,
	SFXNUM_05F9,
	SFXNUM_05FA,
	SFXNUM_05FB,
	SFXNUM_05FC,
	SFXNUM_05FD,
	SFXNUM_05FE,
	SFXNUM_05FF,
	SFXNUM_0600,
	SFXNUM_0601,
	SFXNUM_0602,
	SFXNUM_0603,
	SFXNUM_0604,
	SFXNUM_0605,
	SFXNUM_0606,
	SFXNUM_0607,
	SFXNUM_0608_NOSEDIVE,
	SFXNUM_0609_UFOHUM,
	SFXNUM_END
};

/**
 * These SFX values are remapped using a table in snd.c
 */
enum sfxmap {
	SFXMAP_8000 = 0x8000,
	SFXMAP_8001_DOOR,
	SFXMAP_8002_DOOR,
	SFXMAP_8003_DOOR,
	SFXMAP_8004_DOOR,
	SFXMAP_8005_DOOR,
	SFXMAP_8006_DOOR,
	SFXMAP_8007_DOOR,
	SFXMAP_8008_DOOR,
	SFXMAP_8009_8009,
	SFXMAP_800A_DOOR,
	SFXMAP_800B_DOOR,
	SFXMAP_800C_DOOR,
	SFXMAP_800D_DOOR,
	SFXMAP_800E_DOOR,
	SFXMAP_800F_DOOR,
	SFXMAP_8010_DOOR,
	SFXMAP_8011_DOOR,
	SFXMAP_8012_DOOR,
	SFXMAP_8013_DOOR,
	SFXMAP_8014_DOOR,
	SFXMAP_8015_DOOR,
	SFXMAP_8016_DOOR,
	SFXMAP_8017_DOOR,
	SFXMAP_8018_DOOR,
	SFXMAP_8019_DOOR,
	SFXMAP_801A_DOOR,
	SFXMAP_801B_DOOR,
	SFXMAP_801C_DOOR,
	SFXMAP_801D_DOOR,
	SFXMAP_801E_DOOR,
	SFXMAP_801F_DOOR,
	SFXMAP_8020_DOOR,
	SFXMAP_8021_DOOR,
	SFXMAP_8022_DOOR,
	SFXMAP_8023,
	SFXMAP_8024,
	SFXMAP_8025,
	SFXMAP_8026_DOOR,
	SFXMAP_8027_DOOR,
	SFXMAP_8028_CARR_HELLO_JOANNA,
	SFXMAP_8029,
	SFXMAP_802A,
	SFXMAP_802B_CIFEM_HI_THERE,
	SFXMAP_802C_GRIMSHAW_WELCOME,
	SFXMAP_802D_GRIMSHAW_HI_THERE,
	SFXMAP_802E_GRIMSHAW_UMM_ERR_HI,
	SFXMAP_802F_HOLO_HI,
	SFXMAP_8030_HANGAR_WHAT_DO_YOU_WANT,
	SFXMAP_8031_FOSTER_STAR_AGENT,
	SFXMAP_8032_CIM_HEY_THERE,
	SFXMAP_8033_CIM_HI,
	SFXMAP_8034_CIM_HOWS_IT_GOING,
	SFXMAP_8035_CIFEM_HELLO,
	SFXMAP_8036_CIFEM_HI_JO,
	SFXMAP_8037_CIFEM_HOWS_IT_GOING,
	SFXMAP_8038,
	SFXMAP_8039,
	SFXMAP_803A,
	SFXMAP_803B,
	SFXMAP_803C,
	SFXMAP_803D,
	SFXMAP_803E,
	SFXMAP_803F,
	SFXMAP_8040_MENU_ERROR,
	SFXMAP_8041,
	SFXMAP_8042,
	SFXMAP_8043,
	SFXMAP_8044,
	SFXMAP_8045,
	SFXMAP_8046,
	SFXMAP_8047,
	SFXMAP_8048,
	SFXMAP_8049,
	SFXMAP_804A,
	SFXMAP_804B,
	SFXMAP_804C,
	SFXMAP_804D,
	SFXMAP_804E,
	SFXMAP_804F_RELOAD_DEFAULT,
	SFXMAP_8050,
	SFXMAP_8051,
	SFXMAP_8052_FIREEMPTY,
	SFXMAP_8053_LAUNCH_ROCKET,
	SFXMAP_8054,
	SFXMAP_8055_FIRE_SHOTGUN,
	SFXMAP_8056,
	SFXMAP_8057_DRUGSPY_FIREDART,
	SFXMAP_8058,
	SFXMAP_8059,
	SFXMAP_805A,
	SFXMAP_805B,
	SFXMAP_805C,
	SFXMAP_805D,
	SFXMAP_805E,
	SFXMAP_805F,
	SFXMAP_8060,
	SFXMAP_8061,
	SFXMAP_8062,
	SFXMAP_8063,
	SFXMAP_8064,
	SFXMAP_8065_MAULER_CHARGE,
	SFXMAP_8066,
	SFXMAP_8067,
	SFXMAP_8068_SLAYER_WHIR,
	SFXMAP_8069,
	SFXMAP_806A,
	SFXMAP_806B,
	SFXMAP_806C,
	SFXMAP_806D,
	SFXMAP_806E,
	SFXMAP_806F,
	SFXMAP_8070,
	SFXMAP_8071,
	SFXMAP_8072,
	SFXMAP_8073,
	SFXMAP_8074,
	SFXMAP_8075,
	SFXMAP_8076_HIT_CHR,
	SFXMAP_8077_HIT_GLASS,
	SFXMAP_8078_GLASS_SHATTER,
	SFXMAP_8079_HIT_METAL,
	SFXMAP_807A,
	SFXMAP_807B_HIT_METAL,
	SFXMAP_807C_HATHIT,
	SFXMAP_807D_HIT_SNOW,
	SFXMAP_807E_HIT_WOOD,
	SFXMAP_807F_HIT_WOOD,
	SFXMAP_8080_HIT_WATER,
	SFXMAP_8081_HIT_MUD,
	SFXMAP_8082_HIT_MUD,
	SFXMAP_8083_HIT_MUD,
	SFXMAP_8084_HIT_DIRT,
	SFXMAP_8085_HIT_DIRT,
	SFXMAP_8086_HIT_TILE,
	SFXMAP_8087_HIT_STONE,
	SFXMAP_8088_HIT_STONE,
	SFXMAP_8089_HIT_METALOBJ,
	SFXMAP_808A_HIT_METALOBJ,
	SFXMAP_808B,
	SFXMAP_808C_EYESPYHIT,
	SFXMAP_808D_THUD,
	SFXMAP_808E_THUD,
	SFXMAP_808F_THUD,
	SFXMAP_8090_THUD,
	SFXMAP_8091_THUD,
	SFXMAP_8092_THUD,
	SFXMAP_8093_THUD,
	SFXMAP_8094_THUD,
	SFXMAP_8095_THUD,
	SFXMAP_8096_THUD,
	SFXMAP_8097_THUD,
	SFXMAP_8098_EXPLOSION,
	SFXMAP_8099,
	SFXMAP_809A_EXPLOSION,
	SFXMAP_809B,
	SFXMAP_809C,
	SFXMAP_809D,
	SFXMAP_809E,
	SFXMAP_809F,
	SFXMAP_80A0,
	SFXMAP_80A1,
	SFXMAP_80A2,
	SFXMAP_80A3,
	SFXMAP_80A4,
	SFXMAP_80A5,
	SFXMAP_80A6,
	SFXMAP_80A7,
	SFXMAP_80A8,
	SFXMAP_80A9_THROW,
	SFXMAP_80AA,
	SFXMAP_80AB_DETONATE,
	SFXMAP_80AC_DOOR,
	SFXMAP_80AD_DOOR,
	SFXMAP_80AE_DOOR,
	SFXMAP_80AF_BIKE_PULSE,
	SFXMAP_80B0,
	SFXMAP_80B1,
	SFXMAP_80B2,
	SFXMAP_80B3,
	SFXMAP_80B4,
	SFXMAP_80B5,
	SFXMAP_80B6,
	SFXMAP_80B7,
	SFXMAP_80B8,
	SFXMAP_80B9_THUNDER,
	SFXMAP_80BA_THUNDER,
	SFXMAP_80BB_THUNDER,
	SFXMAP_80BC_THUNDER,
	SFXMAP_80BD_THUNDER,
	SFXMAP_80BE_THUNDER,
	SFXMAP_80BF_LIGHTNING,
	SFXMAP_80C0_LIGHTNING,
	SFXMAP_80C1_LIGHTNING,
	SFXMAP_80C2_LIGHTNING,
	SFXMAP_80C3_LIGHTNING,
	SFXMAP_80C4_FOOTSTEP,
	SFXMAP_80C5_FOOTSTEP,
	SFXMAP_80C6_FOOTSTEP,
	SFXMAP_80C7_FOOTSTEP,
	SFXMAP_80C8_FOOTSTEP,
	SFXMAP_80C9_FOOTSTEP,
	SFXMAP_80CA_FOOTSTEP,
	SFXMAP_80CB_FOOTSTEP,
	SFXMAP_80CC_FOOTSTEP,
	SFXMAP_80CD_FOOTSTEP,
	SFXMAP_80CE_FOOTSTEP,
	SFXMAP_80CF_FOOTSTEP,
	SFXMAP_80D0_FOOTSTEP,
	SFXMAP_80D1_FOOTSTEP,
	SFXMAP_80D2_FOOTSTEP,
	SFXMAP_80D3_FOOTSTEP,
	SFXMAP_80D4_FOOTSTEP,
	SFXMAP_80D5_FOOTSTEP,
	SFXMAP_80D6_FOOTSTEP,
	SFXMAP_80D7_FOOTSTEP,
	SFXMAP_80D8_FOOTSTEP,
	SFXMAP_80D9_FOOTSTEP,
	SFXMAP_80DA_FOOTSTEP,
	SFXMAP_80DB_FOOTSTEP,
	SFXMAP_80DC_FOOTSTEP,
	SFXMAP_80DD_FOOTSTEP,
	SFXMAP_80DE_FOOTSTEP,
	SFXMAP_80DF_FOOTSTEP,
	SFXMAP_80E0_FOOTSTEP,
	SFXMAP_80E1_FOOTSTEP,
	SFXMAP_80E2_FOOTSTEP,
	SFXMAP_80E3_FOOTSTEP,
	SFXMAP_80E4_FOOTSTEP,
	SFXMAP_80E5_FOOTSTEP,
	SFXMAP_80E6_FOOTSTEP,
	SFXMAP_80E7_FOOTSTEP,
	SFXMAP_80E8_FOOTSTEP,
	SFXMAP_80E9_FOOTSTEP,
	SFXMAP_80EA_FOOTSTEP,
	SFXMAP_80EB_FOOTSTEP,
	SFXMAP_80EC_FOOTSTEP,
	SFXMAP_80ED_FOOTSTEP,
	SFXMAP_80EE_FOOTSTEP,
	SFXMAP_80EF_FOOTSTEP,
	SFXMAP_80F0_FOOTSTEP,
	SFXMAP_80F1_FOOTSTEP,
	SFXMAP_80F2_FOOTSTEP,
	SFXMAP_80F3_FOOTSTEP,
	SFXMAP_80F4_FOOTSTEP,
	SFXMAP_80F5_FOOTSTEP,
	SFXMAP_80F6,
#if VERSION >= VERSION_NTSC_1_0
	SFXMAP_80F7_M0_HOLY_SHH,
#endif
	SFXMAP_80F8_M0_WHAT_THE_HELL,
	SFXMAP_80F9_M0_DAMN_IT_MISSED,
	SFXMAP_80FA_M0_GODS_SAKE_SOMEONE_HIT_HER,
	SFXMAP_80FB_M0_GET_THE_HELL_OUT_OF_HERE,
	SFXMAP_80FC_M0_YOU_BITCH,
	SFXMAP_80FD_M0_OH_MY_GOD,
	SFXMAP_80FE,
	SFXMAP_80FF,
	SFXMAP_8100,
	SFXMAP_8101,
	SFXMAP_8102,
	SFXMAP_8103_SCI_WHO_THE_HELL_ARE_YOU,
	SFXMAP_8104,
	SFXMAP_8105,
	SFXMAP_8106,
	SFXMAP_8107,
	SFXMAP_8108,
	SFXMAP_8109,
	SFXMAP_810A,
	SFXMAP_810B,
	SFXMAP_810C_SHIP_HUM,
	SFXMAP_810D,
	SFXMAP_810E,
	SFXMAP_810F,
	SFXMAP_8110,
	SFXMAP_8111,
	SFXMAP_8112,
	SFXMAP_8113,
	SFXMAP_8114,
	SFXMAP_8115,
	SFXMAP_8116,
	SFXMAP_8117,
	SFXMAP_8118_TYPING,
	SFXMAP_8119,
	SFXMAP_811A,
	SFXMAP_811B,
	SFXMAP_811C,
	SFXMAP_811D,
	SFXMAP_811E,
	SFXMAP_811F,
	SFXMAP_8120,
	SFXMAP_8121,
	SFXMAP_8122,
	SFXMAP_8123,
	SFXMAP_8124_M1_HOLY,
	SFXMAP_8125_M1_WHAT_THE_HELL,
	SFXMAP_8126_M1_OH_MY_GOD,
	SFXMAP_8127_M1_OH_GOD_IM_HIT,
	SFXMAP_8128_M1_MY_GOD,
	SFXMAP_8129_M1_NOOO,
#if VERSION >= VERSION_NTSC_1_0
	SFXMAP_812A_M1_OH_GOD_HES_DEAD,
#endif
	SFXMAP_812B_M1_BLOODY_STUPID_GUN,
	SFXMAP_812C_M1_DAMN_IT,
	SFXMAP_812D_M1_DAMN_SHES_GOOD,
	SFXMAP_812E_M1_COVER_MY_ASS,
	SFXMAP_812F_M1_SCREAM,
#if VERSION >= VERSION_NTSC_1_0
	// Might be SFXMAP_812F_M1_SCREAM that's actually being added here
	SFXMAP_8130_F_DAMN_SHES_GOOD,
#endif
	SFXMAP_8131_F_MY_GOD,
	SFXMAP_8132_M2_GEEZ_THAT_HURT,
	SFXMAP_8133_M2_DAMN_IT_IM_TAKING_FIRE,
	SFXMAP_8134_M2_GOD_DAMN_IT,
	SFXMAP_8135_M2_HOLY_MOLY,
	SFXMAP_8136_M2_DAMN_MISSED_AGAIN,
	SFXMAP_8137_M2_DAMN_YOU,
	SFXMAP_8138_M2_HELL_SHES_GOOD,
	SFXMAP_8139_M2_LETS_GET_THE_HELL_OUT_OF_HERE,
	SFXMAP_813A_M2_NOOO,
#if VERSION >= VERSION_NTSC_1_0
	SFXMAP_813B,
#endif
	SFXMAP_813C_M2_OH_GOD_IM_DYING,
	SFXMAP_813D_M2_GOD_RUN,
	SFXMAP_813E,
	SFXMAP_813F,
	SFXMAP_8140,
	SFXMAP_8141,
	SFXMAP_8142,
	SFXMAP_8143,
	SFXMAP_8144,
	SFXMAP_8145,
	SFXMAP_8146,
	SFXMAP_8147,
	SFXMAP_8148,
	SFXMAP_8149,
	SFXMAP_814A_CIV_OH_MY_GOD,
	SFXMAP_814B,
	SFXMAP_814C,
#if VERSION >= VERSION_NTSC_1_0
	SFXMAP_814D,
	SFXMAP_814E,
	SFXMAP_814F,
#endif
	SFXMAP_8150,
	SFXMAP_8151,
	SFXMAP_8152,
	SFXMAP_8153,
	SFXMAP_8154,
	SFXMAP_8155,
	SFXMAP_8156,
	SFXMAP_8157,
	SFXMAP_8158,
	SFXMAP_8159,
	SFXMAP_815A,
	SFXMAP_815B,
	SFXMAP_815C,
	SFXMAP_815D_M0_HOWS_THINGS,
	SFXMAP_815E_M0_HEY_THERE,
	SFXMAP_815F_M0_HI_HOW_ARE_YOU,
	SFXMAP_8160,
	SFXMAP_8161,
	SFXMAP_8162,
	SFXMAP_8163_M1_HI_THERE,
	SFXMAP_8164_M1_HOWS_THINGS,
	SFXMAP_8165_M2_HELLO,
	SFXMAP_8166_M2_HEY_WHATS_UP,
	SFXMAP_8167_M0_WHAT_THE_HELL,
	SFXMAP_8168_M1_M2_GEEZ,
	SFXMAP_8169,
	SFXMAP_816A,
	SFXMAP_816B_DOOR,
	SFXMAP_816C_DOOR,
	SFXMAP_816D_DOOR,
	SFXMAP_816E,
	SFXMAP_816F,
	SFXMAP_8170,
	SFXMAP_8171,
	SFXMAP_8172,
	SFXMAP_8173,
	SFXMAP_8174,
	SFXMAP_8175,
	SFXMAP_8176,
	SFXMAP_8177,
	SFXMAP_8178,
	SFXMAP_8179,
	SFXMAP_817A,
	SFXMAP_817B,
	SFXMAP_817C,
	SFXMAP_817D,
	SFXMAP_817E,
	SFXMAP_817F,
	SFXMAP_8180,
	SFXMAP_8181,
	SFXMAP_8182,
	SFXMAP_8183,
	SFXMAP_8184,
	SFXMAP_8185,
	SFXMAP_8186,
	SFXMAP_8187_FOOTSTEP,
	SFXMAP_8188_FOOTSTEP,
	SFXMAP_8189_FOOTSTEP,
	SFXMAP_818A_FOOTSTEP,
	SFXMAP_818B_FOOTSTEP,
	SFXMAP_818C_FOOTSTEP,
	SFXMAP_818D_FOOTSTEP,
	SFXMAP_818E_FOOTSTEP,
	SFXMAP_818F_FOOTSTEP,
	SFXMAP_8190_FOOTSTEP,
	SFXMAP_8191_FOOTSTEP,
	SFXMAP_8192_FOOTSTEP,
	SFXMAP_8193,
	SFXMAP_8194,
	SFXMAP_8195,
	SFXMAP_8196,
	SFXMAP_8197,
	SFXMAP_8198,
	SFXMAP_8199,
	SFXMAP_819A,
	SFXMAP_819B,
	SFXMAP_819C,
	SFXMAP_819D,
	SFXMAP_819E,
	SFXMAP_819F,
	SFXMAP_81A0,
	SFXMAP_81A1,
	SFXMAP_81A2,
	SFXMAP_81A3,
	SFXMAP_81A4,
	SFXMAP_81A5,
	SFXMAP_81A6,
	SFXMAP_81A7,
	SFXMAP_81A8_DOOR,
	SFXMAP_81A9,
	SFXMAP_81AA_DOOR,
	SFXMAP_81AB_DOOR,
	SFXMAP_81AC,
	SFXMAP_81AD_DOOR,
	SFXMAP_81AE_DOOR,
	SFXMAP_81AF_DOOR,
	SFXMAP_81B0_DOOR,
	SFXMAP_81B1_DOOR,
	SFXMAP_81B2_DOOR,
	SFXMAP_81B3_DOOR,
	SFXMAP_81B4_DOOR,
	SFXMAP_81B5_DOOR,
	SFXMAP_81B6_DOOR,
	SFXMAP_81B7_DOOR,
	SFXMAP_81B8_DOOR,
	SFXMAP_81B9,
	SFXMAP_81BA,
	SFXMAP_81BB,
	SFXMAP_END
};

#define _MP3_ACK(file)  (0x4000 | file)
#define _MP3_ACKW(file) (0x2000 | file)
#define _MP3_LO(file)   (0x1800 | file)
#define _MP3_MED(file)  (0x1000 | file)
#define _MP3_HI(file)   (0x0800 | file)

#define MP3(file)         _MP3_MED(file)
#define MP3_LO(file)      _MP3_LO(file)
#define MP3_HI(file)      _MP3_HI(file)
#define MP3_ACK(file)     _MP3_MED(_MP3_ACK(file))
#define MP3_ACKW(file)    _MP3_MED(_MP3_ACKW(file))
#define MP3_LO_ACK(file)  _MP3_LO(_MP3_ACK(file))
#define MP3_LO_ACKW(file) _MP3_LO(_MP3_ACKW(file))
#define MP3_HI_ACK(file)  _MP3_HI(_MP3_ACK(file))
#define MP3_HI_ACKW(file) _MP3_HI(_MP3_ACKW(file))
#define MP3_ZZ(file)      _MP3_MED(_MP3_ACK(_MP3_ACKW(file)))
#define MP3_LO_ZZ(file)   _MP3_LO(_MP3_ACK(_MP3_ACKW(file)))
#define MP3_HI_ZZ(file)   _MP3_HI(_MP3_ACK(_MP3_ACKW(file)))
