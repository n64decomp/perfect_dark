#include <ultra64.h>
#include "types.h"

extern u8 anim0000;
extern u8 anim0001;
extern u8 anim0002;
extern u8 anim0003;
extern u8 anim0004;
extern u8 anim0005;
extern u8 anim0006;
extern u8 anim0007;
extern u8 anim0008;
extern u8 anim0009;
extern u8 anim000a;
extern u8 anim000b;
extern u8 anim000c;
extern u8 anim000d;
extern u8 anim000e;
extern u8 anim000f;
extern u8 anim0010;
extern u8 anim0011;
extern u8 anim0012;
extern u8 anim0013;
extern u8 anim0014;
extern u8 anim0015;
extern u8 anim0016;
extern u8 anim0017;
extern u8 anim0018;
extern u8 anim0019;
extern u8 anim001a;
extern u8 anim001b;
extern u8 anim001c;
extern u8 anim001d;
extern u8 anim001e;
extern u8 anim001f;
extern u8 anim0020;
extern u8 anim0021;
extern u8 anim0022;
extern u8 anim0023;
extern u8 anim0024;
extern u8 anim0025;
extern u8 anim0026;
extern u8 anim0027;
extern u8 anim0028;
extern u8 anim0029;
extern u8 anim002a;
extern u8 anim002b;
extern u8 anim002c;
extern u8 anim002d;
extern u8 anim002e;
extern u8 anim002f;
extern u8 anim0030;
extern u8 anim0031;
extern u8 anim0032;
extern u8 anim0033;
extern u8 anim0034;
extern u8 anim0035;
extern u8 anim0036;
extern u8 anim0037;
extern u8 anim0038;
extern u8 anim0039;
extern u8 anim003a;
extern u8 anim003b;
extern u8 anim003c;
extern u8 anim003d;
extern u8 anim003e;
extern u8 anim003f;
extern u8 anim0040;
extern u8 anim0041;
extern u8 anim0042;
extern u8 anim0043;
extern u8 anim0044;
extern u8 anim0045;
extern u8 anim0046;
extern u8 anim0047;
extern u8 anim0048;
extern u8 anim0049;
extern u8 anim004a;
extern u8 anim004b;
extern u8 anim004c;
extern u8 anim004d;
extern u8 anim004e;
extern u8 anim004f;
extern u8 anim0050;
extern u8 anim0051;
extern u8 anim0052;
extern u8 anim0053;
extern u8 anim0054;
extern u8 anim0055;
extern u8 anim0056;
extern u8 anim0057;
extern u8 anim0058;
extern u8 anim0059;
extern u8 anim005a;
extern u8 anim005b;
extern u8 anim005c;
extern u8 anim005d;
extern u8 anim005e;
extern u8 anim005f;
extern u8 anim0060;
extern u8 anim0061;
extern u8 anim0062;
extern u8 anim0063;
extern u8 anim0064;
extern u8 anim0065;
extern u8 anim0066;
extern u8 anim0067;
extern u8 anim0068;
extern u8 anim0069;
extern u8 anim006a;
extern u8 anim006b;
extern u8 anim006c;
extern u8 anim006d;
extern u8 anim006e;
extern u8 anim006f;
extern u8 anim0070;
extern u8 anim0071;
extern u8 anim0072;
extern u8 anim0073;
extern u8 anim0074;
extern u8 anim0075;
extern u8 anim0076;
extern u8 anim0077;
extern u8 anim0078;
extern u8 anim0079;
extern u8 anim007a;
extern u8 anim007b;
extern u8 anim007c;
extern u8 anim007d;
extern u8 anim007e;
extern u8 anim007f;
extern u8 anim0080;
extern u8 anim0081;
extern u8 anim0082;
extern u8 anim0083;
extern u8 anim0084;
extern u8 anim0085;
extern u8 anim0086;
extern u8 anim0087;
extern u8 anim0088;
extern u8 anim0089;
extern u8 anim008a;
extern u8 anim008b;
extern u8 anim008c;
extern u8 anim008d;
extern u8 anim008e;
extern u8 anim008f;
extern u8 anim0090;
extern u8 anim0091;
extern u8 anim0092;
extern u8 anim0093;
extern u8 anim0094;
extern u8 anim0095;
extern u8 anim0096;
extern u8 anim0097;
extern u8 anim0098;
extern u8 anim0099;
extern u8 anim009a;
extern u8 anim009b;
extern u8 anim009c;
extern u8 anim009d;
extern u8 anim009e;
extern u8 anim009f;
extern u8 anim00a0;
extern u8 anim00a1;
extern u8 anim00a2;
extern u8 anim00a3;
extern u8 anim00a4;
extern u8 anim00a5;
extern u8 anim00a6;
extern u8 anim00a7;
extern u8 anim00a8;
extern u8 anim00a9;
extern u8 anim00aa;
extern u8 anim00ab;
extern u8 anim00ac;
extern u8 anim00ad;
extern u8 anim00ae;
extern u8 anim00af;
extern u8 anim00b0;
extern u8 anim00b1;
extern u8 anim00b2;
extern u8 anim00b3;
extern u8 anim00b4;
extern u8 anim00b5;
extern u8 anim00b6;
extern u8 anim00b7;
extern u8 anim00b8;
extern u8 anim00b9;
extern u8 anim00ba;
extern u8 anim00bb;
extern u8 anim00bc;
extern u8 anim00bd;
extern u8 anim00be;
extern u8 anim00bf;
extern u8 anim00c0;
extern u8 anim00c1;
extern u8 anim00c2;
extern u8 anim00c3;
extern u8 anim00c4;
extern u8 anim00c5;
extern u8 anim00c6;
extern u8 anim00c7;
extern u8 anim00c8;
extern u8 anim00c9;
extern u8 anim00ca;
extern u8 anim00cb;
extern u8 anim00cc;
extern u8 anim00cd;
extern u8 anim00ce;
extern u8 anim00cf;
extern u8 anim00d0;
extern u8 anim00d1;
extern u8 anim00d2;
extern u8 anim00d3;
extern u8 anim00d4;
extern u8 anim00d5;
extern u8 anim00d6;
extern u8 anim00d7;
extern u8 anim00d8;
extern u8 anim00d9;
extern u8 anim00da;
extern u8 anim00db;
extern u8 anim00dc;
extern u8 anim00dd;
extern u8 anim00de;
extern u8 anim00df;
extern u8 anim00e0;
extern u8 anim00e1;
extern u8 anim00e2;
extern u8 anim00e3;
extern u8 anim00e4;
extern u8 anim00e5;
extern u8 anim00e6;
extern u8 anim00e7;
extern u8 anim00e8;
extern u8 anim00e9;
extern u8 anim00ea;
extern u8 anim00eb;
extern u8 anim00ec;
extern u8 anim00ed;
extern u8 anim00ee;
extern u8 anim00ef;
extern u8 anim00f0;
extern u8 anim00f1;
extern u8 anim00f2;
extern u8 anim00f3;
extern u8 anim00f4;
extern u8 anim00f5;
extern u8 anim00f6;
extern u8 anim00f7;
extern u8 anim00f8;
extern u8 anim00f9;
extern u8 anim00fa;
extern u8 anim00fb;
extern u8 anim00fc;
extern u8 anim00fd;
extern u8 anim00fe;
extern u8 anim00ff;
extern u8 anim0100;
extern u8 anim0101;
extern u8 anim0102;
extern u8 anim0103;
extern u8 anim0104;
extern u8 anim0105;
extern u8 anim0106;
extern u8 anim0107;
extern u8 anim0108;
extern u8 anim0109;
extern u8 anim010a;
extern u8 anim010b;
extern u8 anim010c;
extern u8 anim010d;
extern u8 anim010e;
extern u8 anim010f;
extern u8 anim0110;
extern u8 anim0111;
extern u8 anim0112;
extern u8 anim0113;
extern u8 anim0114;
extern u8 anim0115;
extern u8 anim0116;
extern u8 anim0117;
extern u8 anim0118;
extern u8 anim0119;
extern u8 anim011a;
extern u8 anim011b;
extern u8 anim011c;
extern u8 anim011d;
extern u8 anim011e;
extern u8 anim011f;
extern u8 anim0120;
extern u8 anim0121;
extern u8 anim0122;
extern u8 anim0123;
extern u8 anim0124;
extern u8 anim0125;
extern u8 anim0126;
extern u8 anim0127;
extern u8 anim0128;
extern u8 anim0129;
extern u8 anim012a;
extern u8 anim012b;
extern u8 anim012c;
extern u8 anim012d;
extern u8 anim012e;
extern u8 anim012f;
extern u8 anim0130;
extern u8 anim0131;
extern u8 anim0132;
extern u8 anim0133;
extern u8 anim0134;
extern u8 anim0135;
extern u8 anim0136;
extern u8 anim0137;
extern u8 anim0138;
extern u8 anim0139;
extern u8 anim013a;
extern u8 anim013b;
extern u8 anim013c;
extern u8 anim013d;
extern u8 anim013e;
extern u8 anim013f;
extern u8 anim0140;
extern u8 anim0141;
extern u8 anim0142;
extern u8 anim0143;
extern u8 anim0144;
extern u8 anim0145;
extern u8 anim0146;
extern u8 anim0147;
extern u8 anim0148;
extern u8 anim0149;
extern u8 anim014a;
extern u8 anim014b;
extern u8 anim014c;
extern u8 anim014d;
extern u8 anim014e;
extern u8 anim014f;
extern u8 anim0150;
extern u8 anim0151;
extern u8 anim0152;
extern u8 anim0153;
extern u8 anim0154;
extern u8 anim0155;
extern u8 anim0156;
extern u8 anim0157;
extern u8 anim0158;
extern u8 anim0159;
extern u8 anim015a;
extern u8 anim015b;
extern u8 anim015c;
extern u8 anim015d;
extern u8 anim015e;
extern u8 anim015f;
extern u8 anim0160;
extern u8 anim0161;
extern u8 anim0162;
extern u8 anim0163;
extern u8 anim0164;
extern u8 anim0165;
extern u8 anim0166;
extern u8 anim0167;
extern u8 anim0168;
extern u8 anim0169;
extern u8 anim016a;
extern u8 anim016b;
extern u8 anim016c;
extern u8 anim016d;
extern u8 anim016e;
extern u8 anim016f;
extern u8 anim0170;
extern u8 anim0171;
extern u8 anim0172;
extern u8 anim0173;
extern u8 anim0174;
extern u8 anim0175;
extern u8 anim0176;
extern u8 anim0177;
extern u8 anim0178;
extern u8 anim0179;
extern u8 anim017a;
extern u8 anim017b;
extern u8 anim017c;
extern u8 anim017d;
extern u8 anim017e;
extern u8 anim017f;
extern u8 anim0180;
extern u8 anim0181;
extern u8 anim0182;
extern u8 anim0183;
extern u8 anim0184;
extern u8 anim0185;
extern u8 anim0186;
extern u8 anim0187;
extern u8 anim0188;
extern u8 anim0189;
extern u8 anim018a;
extern u8 anim018b;
extern u8 anim018c;
extern u8 anim018d;
extern u8 anim018e;
extern u8 anim018f;
extern u8 anim0190;
extern u8 anim0191;
extern u8 anim0192;
extern u8 anim0193;
extern u8 anim0194;
extern u8 anim0195;
extern u8 anim0196;
extern u8 anim0197;
extern u8 anim0198;
extern u8 anim0199;
extern u8 anim019a;
extern u8 anim019b;
extern u8 anim019c;
extern u8 anim019d;
extern u8 anim019e;
extern u8 anim019f;
extern u8 anim01a0;
extern u8 anim01a1;
extern u8 anim01a2;
extern u8 anim01a3;
extern u8 anim01a4;
extern u8 anim01a5;
extern u8 anim01a6;
extern u8 anim01a7;
extern u8 anim01a8;
extern u8 anim01a9;
extern u8 anim01aa;
extern u8 anim01ab;
extern u8 anim01ac;
extern u8 anim01ad;
extern u8 anim01ae;
extern u8 anim01af;
extern u8 anim01b0;
extern u8 anim01b1;
extern u8 anim01b2;
extern u8 anim01b3;
extern u8 anim01b4;
extern u8 anim01b5;
extern u8 anim01b6;
extern u8 anim01b7;
extern u8 anim01b8;
extern u8 anim01b9;
extern u8 anim01ba;
extern u8 anim01bb;
extern u8 anim01bc;
extern u8 anim01bd;
extern u8 anim01be;
extern u8 anim01bf;
extern u8 anim01c0;
extern u8 anim01c1;
extern u8 anim01c2;
extern u8 anim01c3;
extern u8 anim01c4;
extern u8 anim01c5;
extern u8 anim01c6;
extern u8 anim01c7;
extern u8 anim01c8;
extern u8 anim01c9;
extern u8 anim01ca;
extern u8 anim01cb;
extern u8 anim01cc;
extern u8 anim01cd;
extern u8 anim01ce;
extern u8 anim01cf;
extern u8 anim01d0;
extern u8 anim01d1;
extern u8 anim01d2;
extern u8 anim01d3;
extern u8 anim01d4;
extern u8 anim01d5;
extern u8 anim01d6;
extern u8 anim01d7;
extern u8 anim01d8;
extern u8 anim01d9;
extern u8 anim01da;
extern u8 anim01db;
extern u8 anim01dc;
extern u8 anim01dd;
extern u8 anim01de;
extern u8 anim01df;
extern u8 anim01e0;
extern u8 anim01e1;
extern u8 anim01e2;
extern u8 anim01e3;
extern u8 anim01e4;
extern u8 anim01e5;
extern u8 anim01e6;
extern u8 anim01e7;
extern u8 anim01e8;
extern u8 anim01e9;
extern u8 anim01ea;
extern u8 anim01eb;
extern u8 anim01ec;
extern u8 anim01ed;
extern u8 anim01ee;
extern u8 anim01ef;
extern u8 anim01f0;
extern u8 anim01f1;
extern u8 anim01f2;
extern u8 anim01f3;
extern u8 anim01f4;
extern u8 anim01f5;
extern u8 anim01f6;
extern u8 anim01f7;
extern u8 anim01f8;
extern u8 anim01f9;
extern u8 anim01fa;
extern u8 anim01fb;
extern u8 anim01fc;
extern u8 anim01fd;
extern u8 anim01fe;
extern u8 anim01ff;
extern u8 anim0200;
extern u8 anim0201;
extern u8 anim0202;
extern u8 anim0203;
extern u8 anim0204;
extern u8 anim0205;
extern u8 anim0206;
extern u8 anim0207;
extern u8 anim0208;
extern u8 anim0209;
extern u8 anim020a;
extern u8 anim020b;
extern u8 anim020c;
extern u8 anim020d;
extern u8 anim020e;
extern u8 anim020f;
extern u8 anim0210;
extern u8 anim0211;
extern u8 anim0212;
extern u8 anim0213;
extern u8 anim0214;
extern u8 anim0215;
extern u8 anim0216;
extern u8 anim0217;
extern u8 anim0218;
extern u8 anim0219;
extern u8 anim021a;
extern u8 anim021b;
extern u8 anim021c;
extern u8 anim021d;
extern u8 anim021e;
extern u8 anim021f;
extern u8 anim0220;
extern u8 anim0221;
extern u8 anim0222;
extern u8 anim0223;
extern u8 anim0224;
extern u8 anim0225;
extern u8 anim0226;
extern u8 anim0227;
extern u8 anim0228;
extern u8 anim0229;
extern u8 anim022a;
extern u8 anim022b;
extern u8 anim022c;
extern u8 anim022d;
extern u8 anim022e;
extern u8 anim022f;
extern u8 anim0230;
extern u8 anim0231;
extern u8 anim0232;
extern u8 anim0233;
extern u8 anim0234;
extern u8 anim0235;
extern u8 anim0236;
extern u8 anim0237;
extern u8 anim0238;
extern u8 anim0239;
extern u8 anim023a;
extern u8 anim023b;
extern u8 anim023c;
extern u8 anim023d;
extern u8 anim023e;
extern u8 anim023f;
extern u8 anim0240;
extern u8 anim0241;
extern u8 anim0242;
extern u8 anim0243;
extern u8 anim0244;
extern u8 anim0245;
extern u8 anim0246;
extern u8 anim0247;
extern u8 anim0248;
extern u8 anim0249;
extern u8 anim024a;
extern u8 anim024b;
extern u8 anim024c;
extern u8 anim024d;
extern u8 anim024e;
extern u8 anim024f;
extern u8 anim0250;
extern u8 anim0251;
extern u8 anim0252;
extern u8 anim0253;
extern u8 anim0254;
extern u8 anim0255;
extern u8 anim0256;
extern u8 anim0257;
extern u8 anim0258;
extern u8 anim0259;
extern u8 anim025a;
extern u8 anim025b;
extern u8 anim025c;
extern u8 anim025d;
extern u8 anim025e;
extern u8 anim025f;
extern u8 anim0260;
extern u8 anim0261;
extern u8 anim0262;
extern u8 anim0263;
extern u8 anim0264;
extern u8 anim0265;
extern u8 anim0266;
extern u8 anim0267;
extern u8 anim0268;
extern u8 anim0269;
extern u8 anim026a;
extern u8 anim026b;
extern u8 anim026c;
extern u8 anim026d;
extern u8 anim026e;
extern u8 anim026f;
extern u8 anim0270;
extern u8 anim0271;
extern u8 anim0272;
extern u8 anim0273;
extern u8 anim0274;
extern u8 anim0275;
extern u8 anim0276;
extern u8 anim0277;
extern u8 anim0278;
extern u8 anim0279;
extern u8 anim027a;
extern u8 anim027b;
extern u8 anim027c;
extern u8 anim027d;
extern u8 anim027e;
extern u8 anim027f;
extern u8 anim0280;
extern u8 anim0281;
extern u8 anim0282;
extern u8 anim0283;
extern u8 anim0284;
extern u8 anim0285;
extern u8 anim0286;
extern u8 anim0287;
extern u8 anim0288;
extern u8 anim0289;
extern u8 anim028a;
extern u8 anim028b;
extern u8 anim028c;
extern u8 anim028d;
extern u8 anim028e;
extern u8 anim028f;
extern u8 anim0290;
extern u8 anim0291;
extern u8 anim0292;
extern u8 anim0293;
extern u8 anim0294;
extern u8 anim0295;
extern u8 anim0296;
extern u8 anim0297;
extern u8 anim0298;
extern u8 anim0299;
extern u8 anim029a;
extern u8 anim029b;
extern u8 anim029c;
extern u8 anim029d;
extern u8 anim029e;
extern u8 anim029f;
extern u8 anim02a0;
extern u8 anim02a1;
extern u8 anim02a2;
extern u8 anim02a3;
extern u8 anim02a4;
extern u8 anim02a5;
extern u8 anim02a6;
extern u8 anim02a7;
extern u8 anim02a8;
extern u8 anim02a9;
extern u8 anim02aa;
extern u8 anim02ab;
extern u8 anim02ac;
extern u8 anim02ad;
extern u8 anim02ae;
extern u8 anim02af;
extern u8 anim02b0;
extern u8 anim02b1;
extern u8 anim02b2;
extern u8 anim02b3;
extern u8 anim02b4;
extern u8 anim02b5;
extern u8 anim02b6;
extern u8 anim02b7;
extern u8 anim02b8;
extern u8 anim02b9;
extern u8 anim02ba;
extern u8 anim02bb;
extern u8 anim02bc;
extern u8 anim02bd;
extern u8 anim02be;
extern u8 anim02bf;
extern u8 anim02c0;
extern u8 anim02c1;
extern u8 anim02c2;
extern u8 anim02c3;
extern u8 anim02c4;
extern u8 anim02c5;
extern u8 anim02c6;
extern u8 anim02c7;
extern u8 anim02c8;
extern u8 anim02c9;
extern u8 anim02ca;
extern u8 anim02cb;
extern u8 anim02cc;
extern u8 anim02cd;
extern u8 anim02ce;
extern u8 anim02cf;
extern u8 anim02d0;
extern u8 anim02d1;
extern u8 anim02d2;
extern u8 anim02d3;
extern u8 anim02d4;
extern u8 anim02d5;
extern u8 anim02d6;
extern u8 anim02d7;
extern u8 anim02d8;
extern u8 anim02d9;
extern u8 anim02da;
extern u8 anim02db;
extern u8 anim02dc;
extern u8 anim02dd;
extern u8 anim02de;
extern u8 anim02df;
extern u8 anim02e0;
extern u8 anim02e1;
extern u8 anim02e2;
extern u8 anim02e3;
extern u8 anim02e4;
extern u8 anim02e5;
extern u8 anim02e6;
extern u8 anim02e7;
extern u8 anim02e8;
extern u8 anim02e9;
extern u8 anim02ea;
extern u8 anim02eb;
extern u8 anim02ec;
extern u8 anim02ed;
extern u8 anim02ee;
extern u8 anim02ef;
extern u8 anim02f0;
extern u8 anim02f1;
extern u8 anim02f2;
extern u8 anim02f3;
extern u8 anim02f4;
extern u8 anim02f5;
extern u8 anim02f6;
extern u8 anim02f7;
extern u8 anim02f8;
extern u8 anim02f9;
extern u8 anim02fa;
extern u8 anim02fb;
extern u8 anim02fc;
extern u8 anim02fd;
extern u8 anim02fe;
extern u8 anim02ff;
extern u8 anim0300;
extern u8 anim0301;
extern u8 anim0302;
extern u8 anim0303;
extern u8 anim0304;
extern u8 anim0305;
extern u8 anim0306;
extern u8 anim0307;
extern u8 anim0308;
extern u8 anim0309;
extern u8 anim030a;
extern u8 anim030b;
extern u8 anim030c;
extern u8 anim030d;
extern u8 anim030e;
extern u8 anim030f;
extern u8 anim0310;
extern u8 anim0311;
extern u8 anim0312;
extern u8 anim0313;
extern u8 anim0314;
extern u8 anim0315;
extern u8 anim0316;
extern u8 anim0317;
extern u8 anim0318;
extern u8 anim0319;
extern u8 anim031a;
extern u8 anim031b;
extern u8 anim031c;
extern u8 anim031d;
extern u8 anim031e;
extern u8 anim031f;
extern u8 anim0320;
extern u8 anim0321;
extern u8 anim0322;
extern u8 anim0323;
extern u8 anim0324;
extern u8 anim0325;
extern u8 anim0326;
extern u8 anim0327;
extern u8 anim0328;
extern u8 anim0329;
extern u8 anim032a;
extern u8 anim032b;
extern u8 anim032c;
extern u8 anim032d;
extern u8 anim032e;
extern u8 anim032f;
extern u8 anim0330;
extern u8 anim0331;
extern u8 anim0332;
extern u8 anim0333;
extern u8 anim0334;
extern u8 anim0335;
extern u8 anim0336;
extern u8 anim0337;
extern u8 anim0338;
extern u8 anim0339;
extern u8 anim033a;
extern u8 anim033b;
extern u8 anim033c;
extern u8 anim033d;
extern u8 anim033e;
extern u8 anim033f;
extern u8 anim0340;
extern u8 anim0341;
extern u8 anim0342;
extern u8 anim0343;
extern u8 anim0344;
extern u8 anim0345;
extern u8 anim0346;
extern u8 anim0347;
extern u8 anim0348;
extern u8 anim0349;
extern u8 anim034a;
extern u8 anim034b;
extern u8 anim034c;
extern u8 anim034d;
extern u8 anim034e;
extern u8 anim034f;
extern u8 anim0350;
extern u8 anim0351;
extern u8 anim0352;
extern u8 anim0353;
extern u8 anim0354;
extern u8 anim0355;
extern u8 anim0356;
extern u8 anim0357;
extern u8 anim0358;
extern u8 anim0359;
extern u8 anim035a;
extern u8 anim035b;
extern u8 anim035c;
extern u8 anim035d;
extern u8 anim035e;
extern u8 anim035f;
extern u8 anim0360;
extern u8 anim0361;
extern u8 anim0362;
extern u8 anim0363;
extern u8 anim0364;
extern u8 anim0365;
extern u8 anim0366;
extern u8 anim0367;
extern u8 anim0368;
extern u8 anim0369;
extern u8 anim036a;
extern u8 anim036b;
extern u8 anim036c;
extern u8 anim036d;
extern u8 anim036e;
extern u8 anim036f;
extern u8 anim0370;
extern u8 anim0371;
extern u8 anim0372;
extern u8 anim0373;
extern u8 anim0374;
extern u8 anim0375;
extern u8 anim0376;
extern u8 anim0377;
extern u8 anim0378;
extern u8 anim0379;
extern u8 anim037a;
extern u8 anim037b;
extern u8 anim037c;
extern u8 anim037d;
extern u8 anim037e;
extern u8 anim037f;
extern u8 anim0380;
extern u8 anim0381;
extern u8 anim0382;
extern u8 anim0383;
extern u8 anim0384;
extern u8 anim0385;
extern u8 anim0386;
extern u8 anim0387;
extern u8 anim0388;
extern u8 anim0389;
extern u8 anim038a;
extern u8 anim038b;
extern u8 anim038c;
extern u8 anim038d;
extern u8 anim038e;
extern u8 anim038f;
extern u8 anim0390;
extern u8 anim0391;
extern u8 anim0392;
extern u8 anim0393;
extern u8 anim0394;
extern u8 anim0395;
extern u8 anim0396;
extern u8 anim0397;
extern u8 anim0398;
extern u8 anim0399;
extern u8 anim039a;
extern u8 anim039b;
extern u8 anim039c;
extern u8 anim039d;
extern u8 anim039e;
extern u8 anim039f;
extern u8 anim03a0;
extern u8 anim03a1;
extern u8 anim03a2;
extern u8 anim03a3;
extern u8 anim03a4;
extern u8 anim03a5;
extern u8 anim03a6;
extern u8 anim03a7;
extern u8 anim03a8;
extern u8 anim03a9;
extern u8 anim03aa;
extern u8 anim03ab;
extern u8 anim03ac;
extern u8 anim03ad;
extern u8 anim03ae;
extern u8 anim03af;
extern u8 anim03b0;
extern u8 anim03b1;
extern u8 anim03b2;
extern u8 anim03b3;
extern u8 anim03b4;
extern u8 anim03b5;
extern u8 anim03b6;
extern u8 anim03b7;
extern u8 anim03b8;
extern u8 anim03b9;
extern u8 anim03ba;
extern u8 anim03bb;
extern u8 anim03bc;
extern u8 anim03bd;
extern u8 anim03be;
extern u8 anim03bf;
extern u8 anim03c0;
extern u8 anim03c1;
extern u8 anim03c2;
extern u8 anim03c3;
extern u8 anim03c4;
extern u8 anim03c5;
extern u8 anim03c6;
extern u8 anim03c7;
extern u8 anim03c8;
extern u8 anim03c9;
extern u8 anim03ca;
extern u8 anim03cb;
extern u8 anim03cc;
extern u8 anim03cd;
extern u8 anim03ce;
extern u8 anim03cf;
extern u8 anim03d0;
extern u8 anim03d1;
extern u8 anim03d2;
extern u8 anim03d3;
extern u8 anim03d4;
extern u8 anim03d5;
extern u8 anim03d6;
extern u8 anim03d7;
extern u8 anim03d8;
extern u8 anim03d9;
extern u8 anim03da;
extern u8 anim03db;
extern u8 anim03dc;
extern u8 anim03dd;
extern u8 anim03de;
extern u8 anim03df;
extern u8 anim03e0;
extern u8 anim03e1;
extern u8 anim03e2;
extern u8 anim03e3;
extern u8 anim03e4;
extern u8 anim03e5;
extern u8 anim03e6;
extern u8 anim03e7;
extern u8 anim03e8;
extern u8 anim03e9;
extern u8 anim03ea;
extern u8 anim03eb;
extern u8 anim03ec;
extern u8 anim03ed;
extern u8 anim03ee;
extern u8 anim03ef;
extern u8 anim03f0;
extern u8 anim03f1;
extern u8 anim03f2;
extern u8 anim03f3;
extern u8 anim03f4;
extern u8 anim03f5;
extern u8 anim03f6;
extern u8 anim03f7;
extern u8 anim03f8;
extern u8 anim03f9;
extern u8 anim03fa;
extern u8 anim03fb;
extern u8 anim03fc;
extern u8 anim03fd;
extern u8 anim03fe;
extern u8 anim03ff;
extern u8 anim0400;
extern u8 anim0401;
extern u8 anim0402;
extern u8 anim0403;
extern u8 anim0404;
extern u8 anim0405;
extern u8 anim0406;
extern u8 anim0407;
extern u8 anim0408;
extern u8 anim0409;
extern u8 anim040a;
extern u8 anim040b;
extern u8 anim040c;
extern u8 anim040d;
extern u8 anim040e;
extern u8 anim040f;
extern u8 anim0410;
extern u8 anim0411;
extern u8 anim0412;
extern u8 anim0413;
extern u8 anim0414;
extern u8 anim0415;
extern u8 anim0416;
extern u8 anim0417;
extern u8 anim0418;
extern u8 anim0419;
extern u8 anim041a;
extern u8 anim041b;
extern u8 anim041c;
extern u8 anim041d;
extern u8 anim041e;
extern u8 anim041f;
extern u8 anim0420;
extern u8 anim0421;
extern u8 anim0422;
extern u8 anim0423;
extern u8 anim0424;
extern u8 anim0425;
extern u8 anim0426;
extern u8 anim0427;
extern u8 anim0428;
extern u8 anim0429;
extern u8 anim042a;
extern u8 anim042b;
extern u8 anim042c;
extern u8 anim042d;
extern u8 anim042e;
extern u8 anim042f;
extern u8 anim0430;
extern u8 anim0431;
extern u8 anim0432;
extern u8 anim0433;
extern u8 anim0434;
extern u8 anim0435;
extern u8 anim0436;
extern u8 anim0437;
extern u8 anim0438;
extern u8 anim0439;
extern u8 anim043a;
extern u8 anim043b;
extern u8 anim043c;
extern u8 anim043d;
extern u8 anim043e;
extern u8 anim043f;
extern u8 anim0440;
extern u8 anim0441;
extern u8 anim0442;
extern u8 anim0443;
extern u8 anim0444;
extern u8 anim0445;
extern u8 anim0446;
extern u8 anim0447;
extern u8 anim0448;
extern u8 anim0449;
extern u8 anim044a;
extern u8 anim044b;
extern u8 anim044c;
extern u8 anim044d;
extern u8 anim044e;
extern u8 anim044f;
extern u8 anim0450;
extern u8 anim0451;
extern u8 anim0452;
extern u8 anim0453;
extern u8 anim0454;
extern u8 anim0455;
extern u8 anim0456;
extern u8 anim0457;
extern u8 anim0458;
extern u8 anim0459;
extern u8 anim045a;
extern u8 anim045b;
extern u8 anim045c;
extern u8 anim045d;
extern u8 anim045e;
extern u8 anim045f;
extern u8 anim0460;
extern u8 anim0461;
extern u8 anim0462;
extern u8 anim0463;
extern u8 anim0464;
extern u8 anim0465;
extern u8 anim0466;
extern u8 anim0467;
extern u8 anim0468;
extern u8 anim0469;
extern u8 anim046a;
extern u8 anim046b;
extern u8 anim046c;
extern u8 anim046d;
extern u8 anim046e;
extern u8 anim046f;
extern u8 anim0470;
extern u8 anim0471;
extern u8 anim0472;
extern u8 anim0473;
extern u8 anim0474;
extern u8 anim0475;
extern u8 anim0476;
extern u8 anim0477;
extern u8 anim0478;
extern u8 anim0479;
extern u8 anim047a;
extern u8 anim047b;
extern u8 anim047c;
extern u8 anim047d;
extern u8 anim047e;
extern u8 anim047f;
extern u8 anim0480;
extern u8 anim0481;
extern u8 anim0482;
extern u8 anim0483;
extern u8 anim0484;
extern u8 anim0485;
extern u8 anim0486;
extern u8 anim0487;
extern u8 anim0488;
extern u8 anim0489;
extern u8 anim048a;
extern u8 anim048b;
extern u8 anim048c;
extern u8 anim048d;
extern u8 anim048e;
extern u8 anim048f;
extern u8 anim0490;
extern u8 anim0491;
extern u8 anim0492;
extern u8 anim0493;
extern u8 anim0494;
extern u8 anim0495;
extern u8 anim0496;
extern u8 anim0497;
extern u8 anim0498;
extern u8 anim0499;
extern u8 anim049a;
extern u8 anim049b;
extern u8 anim049c;
extern u8 anim049d;
extern u8 anim049e;
extern u8 anim049f;
extern u8 anim04a0;
extern u8 anim04a1;
extern u8 anim04a2;
extern u8 anim04a3;
extern u8 anim04a4;
extern u8 anim04a5;
extern u8 anim04a6;
extern u8 anim04a7;
extern u8 anim04a8;
extern u8 anim04a9;
extern u8 anim04aa;
extern u8 anim04ab;
extern u8 anim04ac;
extern u8 anim04ad;
extern u8 anim04ae;
extern u8 anim04af;
extern u8 anim04b0;
extern u8 anim04b1;
extern u8 anim04b2;
extern u8 anim04b3;
extern u8 anim04b4;
extern u8 anim04b5;
extern u8 anim04b6;

u32 num_animations = 0x04b7;

struct animationdefinition g_AnimationDefinitions[] = {
	{ 0,    0,   &anim0000, 0,   0,  0x00 },
	{ 163,  11,  &anim0001, 162, 12, 0x00 },
	{ 81,   44,  &anim0002, 162, 12, 0x00 },
	{ 90,   47,  &anim0003, 162, 12, 0x00 },
	{ 85,   44,  &anim0004, 162, 12, 0x00 },
	{ 145,  55,  &anim0005, 162, 12, 0x00 },
	{ 121,  53,  &anim0006, 162, 12, 0x00 },
	{ 121,  48,  &anim0007, 162, 12, 0x00 },
	{ 158,  49,  &anim0008, 162, 12, 0x00 },
	{ 125,  51,  &anim0009, 162, 12, 0x00 },
	{ 137,  52,  &anim000a, 162, 12, 0x00 },
	{ 184,  55,  &anim000b, 162, 12, 0x00 },
	{ 126,  55,  &anim000c, 162, 12, 0x00 },
	{ 128,  53,  &anim000d, 162, 12, 0x00 },
	{ 56,   46,  &anim000e, 162, 12, 0x00 },
	{ 93,   48,  &anim000f, 162, 12, 0x00 },
	{ 74,   49,  &anim0010, 162, 12, 0x00 },
	{ 74,   47,  &anim0011, 162, 12, 0x00 },
	{ 113,  49,  &anim0012, 162, 12, 0x00 },
	{ 143,  48,  &anim0013, 162, 12, 0x00 },
	{ 112,  48,  &anim0014, 162, 12, 0x00 },
	{ 155,  47,  &anim0015, 162, 12, 0x00 },
	{ 34,   40,  &anim0016, 162, 12, 0x01 },
	{ 135,  48,  &anim0017, 162, 12, 0x00 },
	{ 94,   40,  &anim0018, 162, 12, 0x01 },
	{ 90,   51,  &anim0019, 162, 12, 0x00 },
	{ 89,   52,  &anim001a, 162, 12, 0x00 },
	{ 33,   39,  &anim001b, 162, 12, 0x01 },
	{ 69,   52,  &anim001c, 162, 12, 0x00 },
	{ 22,   40,  &anim001d, 162, 12, 0x01 },
	{ 21,   39,  &anim001e, 162, 12, 0x01 },
	{ 108,  39,  &anim001f, 162, 12, 0x01 },
	{ 69,   55,  &anim0020, 162, 12, 0x00 },
	{ 118,  47,  &anim0021, 162, 12, 0x00 },
	{ 118,  48,  &anim0022, 162, 12, 0x00 },
	{ 86,   52,  &anim0023, 162, 12, 0x00 },
	{ 88,   51,  &anim0024, 162, 12, 0x00 },
	{ 76,   49,  &anim0025, 162, 12, 0x00 },
	{ 48,   39,  &anim0026, 162, 12, 0x00 },
	{ 114,  53,  &anim0027, 162, 12, 0x00 },
	{ 37,   35,  &anim0028, 162, 12, 0x01 },
	{ 19,   42,  &anim0029, 162, 12, 0x01 },
	{ 24,   41,  &anim002a, 162, 12, 0x01 },
	{ 35,   38,  &anim002b, 162, 12, 0x01 },
	{ 124,  47,  &anim002c, 162, 12, 0x00 },
	{ 60,   7,   &anim002d, 162, 12, 0x00 },
	{ 65,   20,  &anim002e, 162, 12, 0x01 },
	{ 150,  47,  &anim002f, 162, 12, 0x00 },
	{ 34,   37,  &anim0030, 162, 12, 0x01 },
	{ 21,   39,  &anim0031, 162, 12, 0x01 },
	{ 106,  47,  &anim0032, 162, 12, 0x00 },
	{ 0,    0,   &anim0033, 0,   0,  0x00 },
	{ 150,  61,  &anim0034, 162, 12, 0x00 },
	{ 199,  60,  &anim0035, 162, 12, 0x00 },
	{ 227,  52,  &anim0036, 162, 12, 0x00 },
	{ 180,  53,  &anim0037, 162, 12, 0x00 },
	{ 245,  65,  &anim0038, 162, 12, 0x00 },
	{ 187,  55,  &anim0039, 162, 12, 0x00 },
	{ 62,   43,  &anim003a, 162, 12, 0x00 },
	{ 57,   43,  &anim003b, 162, 12, 0x00 },
	{ 94,   50,  &anim003c, 162, 12, 0x00 },
	{ 98,   37,  &anim003d, 162, 12, 0x00 },
	{ 210,  51,  &anim003e, 162, 12, 0x00 },
	{ 447,  54,  &anim003f, 162, 12, 0x00 },
	{ 148,  42,  &anim0040, 162, 12, 0x00 },
	{ 185,  44,  &anim0041, 162, 12, 0x00 },
	{ 150,  46,  &anim0042, 162, 12, 0x00 },
	{ 125,  56,  &anim0043, 162, 12, 0x00 },
	{ 125,  42,  &anim0044, 162, 12, 0x00 },
	{ 87,   44,  &anim0045, 162, 12, 0x00 },
	{ 87,   45,  &anim0046, 162, 12, 0x00 },
	{ 160,  36,  &anim0047, 162, 12, 0x00 },
	{ 87,   49,  &anim0048, 162, 12, 0x00 },
	{ 159,  43,  &anim0049, 162, 12, 0x00 },
	{ 80,   56,  &anim004a, 162, 12, 0x00 },
	{ 170,  47,  &anim004b, 162, 12, 0x00 },
	{ 102,  47,  &anim004c, 162, 12, 0x00 },
	{ 150,  46,  &anim004d, 162, 12, 0x00 },
	{ 95,   55,  &anim004e, 162, 12, 0x00 },
	{ 154,  48,  &anim004f, 162, 12, 0x00 },
	{ 100,  49,  &anim0050, 162, 12, 0x00 },
	{ 107,  47,  &anim0051, 162, 12, 0x00 },
	{ 35,   39,  &anim0052, 162, 12, 0x01 },
	{ 35,   38,  &anim0053, 162, 12, 0x01 },
	{ 37,   39,  &anim0054, 162, 12, 0x01 },
	{ 23,   51,  &anim0055, 162, 12, 0x01 },
	{ 24,   50,  &anim0056, 162, 12, 0x01 },
	{ 24,   52,  &anim0057, 162, 12, 0x01 },
	{ 20,   42,  &anim0058, 162, 12, 0x01 },
	{ 26,   40,  &anim0059, 162, 12, 0x01 },
	{ 19,   44,  &anim005a, 162, 12, 0x01 },
	{ 70,   51,  &anim005b, 162, 12, 0x00 },
	{ 86,   40,  &anim005c, 162, 12, 0x01 },
	{ 23,   42,  &anim005d, 162, 12, 0x01 },
	{ 18,   45,  &anim005e, 162, 12, 0x01 },
	{ 26,   41,  &anim005f, 162, 12, 0x01 },
	{ 21,   40,  &anim0060, 162, 12, 0x01 },
	{ 79,   38,  &anim0061, 162, 12, 0x01 },
	{ 68,   42,  &anim0062, 162, 12, 0x01 },
	{ 66,   41,  &anim0063, 162, 12, 0x01 },
	{ 49,   46,  &anim0064, 162, 12, 0x00 },
	{ 64,   48,  &anim0065, 162, 12, 0x00 },
	{ 40,   46,  &anim0066, 162, 12, 0x00 },
	{ 36,   44,  &anim0067, 162, 12, 0x00 },
	{ 62,   53,  &anim0068, 162, 12, 0x00 },
	{ 77,   50,  &anim0069, 162, 12, 0x00 },
	{ 40,   2,   &anim006a, 162, 12, 0x01 },
	{ 35,   47,  &anim006b, 162, 12, 0x01 },
	{ 34,   45,  &anim006c, 162, 12, 0x01 },
	{ 34,   44,  &anim006d, 162, 12, 0x01 },
	{ 24,   46,  &anim006e, 162, 12, 0x01 },
	{ 26,   46,  &anim006f, 162, 12, 0x01 },
	{ 21,   49,  &anim0070, 162, 12, 0x01 },
	{ 19,   47,  &anim0071, 162, 12, 0x01 },
	{ 31,   49,  &anim0072, 162, 12, 0x01 },
	{ 22,   51,  &anim0073, 162, 12, 0x01 },
	{ 125,  55,  &anim0074, 162, 12, 0x00 },
	{ 125,  56,  &anim0075, 162, 12, 0x00 },
	{ 125,  56,  &anim0076, 162, 12, 0x00 },
	{ 119,  54,  &anim0077, 162, 12, 0x00 },
	{ 112,  56,  &anim0078, 162, 12, 0x00 },
	{ 125,  56,  &anim0079, 162, 12, 0x00 },
	{ 100,  50,  &anim007a, 162, 12, 0x00 },
	{ 120,  49,  &anim007b, 162, 12, 0x00 },
	{ 150,  49,  &anim007c, 162, 12, 0x00 },
	{ 120,  49,  &anim007d, 162, 12, 0x00 },
	{ 150,  50,  &anim007e, 162, 12, 0x00 },
	{ 150,  53,  &anim007f, 162, 12, 0x00 },
	{ 150,  59,  &anim0080, 162, 12, 0x00 },
	{ 179,  54,  &anim0081, 162, 12, 0x00 },
	{ 74,   57,  &anim0082, 162, 12, 0x00 },
	{ 85,   53,  &anim0083, 162, 12, 0x00 },
	{ 80,   62,  &anim0084, 162, 12, 0x00 },
	{ 75,   61,  &anim0085, 162, 12, 0x00 },
	{ 92,   52,  &anim0086, 162, 12, 0x00 },
	{ 62,   63,  &anim0087, 162, 12, 0x00 },
	{ 72,   59,  &anim0088, 162, 12, 0x00 },
	{ 92,   61,  &anim0089, 162, 12, 0x00 },
	{ 89,   51,  &anim008a, 162, 12, 0x00 },
	{ 100,  53,  &anim008b, 162, 12, 0x00 },
	{ 88,   55,  &anim008c, 162, 12, 0x00 },
	{ 80,   53,  &anim008d, 162, 12, 0x00 },
	{ 78,   52,  &anim008e, 162, 12, 0x00 },
	{ 52,   52,  &anim008f, 162, 12, 0x00 },
	{ 280,  50,  &anim0090, 162, 12, 0x00 },
	{ 303,  52,  &anim0091, 162, 12, 0x00 },
	{ 177,  53,  &anim0092, 162, 12, 0x00 },
	{ 26,   42,  &anim0093, 162, 12, 0x01 },
	{ 17,   53,  &anim0094, 162, 12, 0x01 },
	{ 210,  43,  &anim0095, 162, 12, 0x00 },
	{ 87,   36,  &anim0096, 162, 12, 0x00 },
	{ 87,   34,  &anim0097, 162, 12, 0x00 },
	{ 230,  44,  &anim0098, 162, 12, 0x00 },
	{ 449,  60,  &anim0099, 162, 12, 0x00 },
	{ 285,  47,  &anim009a, 162, 12, 0x00 },
	{ 137,  40,  &anim009b, 162, 12, 0x00 },
	{ 141,  37,  &anim009c, 162, 12, 0x00 },
	{ 111,  47,  &anim009d, 162, 12, 0x00 },
	{ 163,  48,  &anim009e, 162, 12, 0x00 },
	{ 138,  54,  &anim009f, 162, 12, 0x00 },
	{ 190,  40,  &anim00a0, 162, 12, 0x00 },
	{ 449,  50,  &anim00a1, 162, 12, 0x00 },
	{ 298,  55,  &anim00a2, 162, 12, 0x00 },
	{ 175,  41,  &anim00a3, 162, 12, 0x00 },
	{ 149,  50,  &anim00a4, 162, 12, 0x00 },
	{ 299,  58,  &anim00a5, 162, 12, 0x00 },
	{ 299,  61,  &anim00a6, 162, 12, 0x00 },
	{ 299,  61,  &anim00a7, 162, 12, 0x00 },
	{ 200,  60,  &anim00a8, 162, 12, 0x00 },
	{ 67,   53,  &anim00a9, 162, 12, 0x00 },
	{ 239,  55,  &anim00aa, 162, 12, 0x00 },
	{ 179,  57,  &anim00ab, 162, 12, 0x00 },
	{ 70,   37,  &anim00ac, 162, 12, 0x00 },
	{ 75,   34,  &anim00ad, 162, 12, 0x00 },
	{ 80,   36,  &anim00ae, 162, 12, 0x00 },
	{ 90,   27,  &anim00af, 162, 12, 0x00 },
	{ 81,   47,  &anim00b0, 162, 12, 0x00 },
	{ 176,  49,  &anim00b1, 162, 12, 0x00 },
	{ 68,   47,  &anim00b2, 162, 12, 0x00 },
	{ 180,  50,  &anim00b3, 162, 12, 0x00 },
	{ 85,   47,  &anim00b4, 162, 12, 0x00 },
	{ 200,  50,  &anim00b5, 162, 12, 0x00 },
	{ 85,   47,  &anim00b6, 162, 12, 0x00 },
	{ 166,  50,  &anim00b7, 162, 12, 0x00 },
	{ 110,  45,  &anim00b8, 162, 12, 0x00 },
	{ 168,  47,  &anim00b9, 162, 12, 0x00 },
	{ 67,   46,  &anim00ba, 162, 12, 0x00 },
	{ 135,  131, &anim00bb, 323, 12, 0x00 },
	{ 119,  47,  &anim00bc, 162, 12, 0x00 },
	{ 161,  50,  &anim00bd, 162, 12, 0x00 },
	{ 56,   46,  &anim00be, 162, 12, 0x00 },
	{ 185,  52,  &anim00bf, 162, 12, 0x00 },
	{ 87,   49,  &anim00c0, 372, 12, 0x01 },
	{ 78,   55,  &anim00c1, 505, 12, 0x00 },
	{ 40,   25,  &anim00c2, 487, 12, 0x00 },
	{ 0,    0,   &anim00c3, 0,   0,  0x00 },
	{ 0,    0,   &anim00c4, 0,   0,  0x00 },
	{ 440,  9,   &anim00c5, 37,  12, 0x02 },
	{ 110,  12,  &anim00c6, 95,  12, 0x02 },
	{ 544,  9,   &anim00c7, 45,  12, 0x0a },
	{ 137,  12,  &anim00c8, 95,  12, 0x02 },
	{ 830,  8,   &anim00c9, 37,  12, 0x02 },
	{ 208,  8,   &anim00ca, 95,  12, 0x02 },
	{ 178,  6,   &anim00cb, 37,  12, 0x02 },
	{ 45,   10,  &anim00cc, 95,  12, 0x02 },
	{ 258,  9,   &anim00cd, 37,  12, 0x02 },
	{ 258,  12,  &anim00ce, 95,  12, 0x02 },
	{ 421,  2,   &anim00cf, 37,  12, 0x02 },
	{ 553,  7,   &anim00d0, 37,  12, 0x02 },
	{ 349,  7,   &anim00d1, 37,  12, 0x02 },
	{ 1249, 12,  &anim00d2, 37,  12, 0x02 },
	{ 60,   31,  &anim00d3, 496, 12, 0x00 },
	{ 90,   35,  &anim00d4, 514, 12, 0x00 },
	{ 106,  8,   &anim00d5, 25,  12, 0x02 },
	{ 106,  6,   &anim00d6, 25,  12, 0x02 },
	{ 106,  7,   &anim00d7, 25,  12, 0x02 },
	{ 106,  5,   &anim00d8, 25,  12, 0x02 },
	{ 139,  7,   &anim00d9, 25,  12, 0x02 },
	{ 88,   42,  &anim00da, 162, 12, 0x00 },
	{ 139,  1,   &anim00db, 25,  12, 0x02 },
	{ 139,  7,   &anim00dc, 25,  12, 0x02 },
	{ 139,  3,   &anim00dd, 25,  12, 0x02 },
	{ 88,   9,   &anim00de, 25,  12, 0x02 },
	{ 313,  64,  &anim00df, 165, 12, 0x02 },
	{ 149,  0,   &anim00e0, 37,  12, 0x02 },
	{ 38,   9,   &anim00e1, 165, 12, 0x02 },
	{ 60,   22,  &anim00e2, 532, 12, 0x00 },
	{ 80,   27,  &anim00e3, 532, 12, 0x00 },
	{ 124,  73,  &anim00e4, 532, 12, 0x00 },
	{ 24,   11,  &anim00e5, 487, 12, 0x00 },
	{ 40,   21,  &anim00e6, 437, 12, 0x00 },
	{ 38,   16,  &anim00e7, 437, 12, 0x00 },
	{ 20,   13,  &anim00e8, 437, 12, 0x00 },
	{ 134,  70,  &anim00e9, 464, 12, 0x00 },
	{ 30,   9,   &anim00ea, 466, 12, 0x00 },
	{ 28,   8,   &anim00eb, 466, 12, 0x00 },
	{ 18,   13,  &anim00ec, 466, 12, 0x00 },
	{ 92,   66,  &anim00ed, 502, 12, 0x00 },
	{ 61,   2,   &anim00ee, 37,  12, 0x02 },
	{ 16,   5,   &anim00ef, 95,  12, 0x02 },
	{ 971,  8,   &anim00f0, 37,  12, 0x02 },
	{ 243,  63,  &anim00f1, 171, 12, 0x06 },
	{ 420,  10,  &anim00f2, 51,  12, 0x0a },
	{ 105,  60,  &anim00f3, 165, 12, 0x02 },
	{ 140,  46,  &anim00f4, 162, 12, 0x00 },
	{ 1721, 10,  &anim00f5, 37,  12, 0x02 },
	{ 431,  63,  &anim00f6, 175, 12, 0x06 },
	{ 431,  54,  &anim00f7, 175, 12, 0x06 },
	{ 92,   46,  &anim00f8, 162, 12, 0x00 },
	{ 239,  4,   &anim00f9, 37,  12, 0x02 },
	{ 120,  61,  &anim00fa, 165, 12, 0x02 },
	{ 161,  49,  &anim00fb, 162, 12, 0x00 },
	{ 145,  3,   &anim00fc, 37,  12, 0x02 },
	{ 37,   9,   &anim00fd, 95,  12, 0x02 },
	{ 37,   43,  &anim00fe, 165, 12, 0x02 },
	{ 89,   6,   &anim00ff, 37,  12, 0x02 },
	{ 23,   5,   &anim0100, 110, 12, 0x02 },
	{ 63,   45,  &anim0101, 162, 12, 0x00 },
	{ 23,   1,   &anim0102, 125, 12, 0x02 },
	{ 200,  6,   &anim0103, 37,  12, 0x02 },
	{ 50,   12,  &anim0104, 95,  12, 0x02 },
	{ 65,   10,  &anim0105, 37,  12, 0x02 },
	{ 17,   8,   &anim0106, 110, 12, 0x02 },
	{ 89,   3,   &anim0107, 37,  12, 0x02 },
	{ 23,   10,  &anim0108, 110, 12, 0x02 },
	{ 23,   59,  &anim0109, 165, 12, 0x02 },
	{ 23,   58,  &anim010a, 225, 12, 0x02 },
	{ 129,  3,   &anim010b, 37,  12, 0x02 },
	{ 33,   6,   &anim010c, 110, 12, 0x02 },
	{ 33,   12,  &anim010d, 165, 12, 0x02 },
	{ 33,   54,  &anim010e, 225, 12, 0x02 },
	{ 33,   27,  &anim010f, 125, 12, 0x02 },
	{ 33,   0,   &anim0110, 37,  12, 0x02 },
	{ 9,    0,   &anim0111, 165, 12, 0x02 },
	{ 26,   6,   &anim0112, 350, 12, 0x00 },
	{ 155,  50,  &anim0113, 162, 12, 0x00 },
	{ 52,   44,  &anim0114, 162, 12, 0x00 },
	{ 128,  75,  &anim0115, 454, 12, 0x00 },
	{ 28,   14,  &anim0116, 409, 12, 0x00 },
	{ 23,   1,   &anim0117, 125, 12, 0x02 },
	{ 33,   27,  &anim0118, 125, 12, 0x02 },
	{ 110,  9,   &anim0119, 25,  12, 0x02 },
	{ 110,  5,   &anim011a, 25,  12, 0x02 },
	{ 110,  5,   &anim011b, 25,  12, 0x02 },
	{ 137,  2,   &anim011c, 25,  12, 0x02 },
	{ 137,  6,   &anim011d, 25,  12, 0x02 },
	{ 137,  2,   &anim011e, 25,  12, 0x02 },
	{ 137,  6,   &anim011f, 25,  12, 0x02 },
	{ 137,  6,   &anim0120, 25,  12, 0x02 },
	{ 137,  6,   &anim0121, 25,  12, 0x02 },
	{ 208,  6,   &anim0122, 25,  12, 0x02 },
	{ 208,  5,   &anim0123, 25,  12, 0x02 },
	{ 208,  5,   &anim0124, 25,  12, 0x02 },
	{ 208,  5,   &anim0125, 25,  12, 0x02 },
	{ 208,  5,   &anim0126, 25,  12, 0x02 },
	{ 45,   7,   &anim0127, 25,  12, 0x02 },
	{ 45,   5,   &anim0128, 25,  12, 0x02 },
	{ 45,   5,   &anim0129, 25,  12, 0x02 },
	{ 45,   2,   &anim012a, 25,  12, 0x02 },
	{ 45,   5,   &anim012b, 25,  12, 0x02 },
	{ 65,   2,   &anim012c, 25,  12, 0x02 },
	{ 65,   2,   &anim012d, 25,  12, 0x02 },
	{ 93,   6,   &anim012e, 37,  12, 0x02 },
	{ 24,   5,   &anim012f, 110, 12, 0x02 },
	{ 135,  48,  &anim0130, 162, 12, 0x00 },
	{ 24,   11,  &anim0131, 125, 12, 0x02 },
	{ 24,   10,  &anim0132, 125, 12, 0x02 },
	{ 445,  6,   &anim0133, 37,  12, 0x02 },
	{ 112,  13,  &anim0134, 110, 12, 0x02 },
	{ 112,  44,  &anim0135, 225, 12, 0x02 },
	{ 112,  32,  &anim0136, 125, 12, 0x02 },
	{ 112,  32,  &anim0137, 125, 12, 0x02 },
	{ 1201, 12,  &anim0138, 37,  12, 0x02 },
	{ 301,  58,  &anim0139, 165, 12, 0x02 },
	{ 301,  52,  &anim013a, 165, 12, 0x02 },
	{ 68,   47,  &anim013b, 162, 12, 0x00 },
	{ 262,  50,  &anim013c, 162, 12, 0x00 },
	{ 301,  9,   &anim013d, 55,  12, 0x02 },
	{ 79,   1,   &anim013e, 52,  12, 0x01 },
	{ 97,   48,  &anim013f, 162, 12, 0x00 },
	{ 293,  8,   &anim0140, 37,  12, 0x02 },
	{ 147,  56,  &anim0141, 165, 12, 0x02 },
	{ 99,   46,  &anim0142, 162, 12, 0x00 },
	{ 345,  3,   &anim0143, 37,  12, 0x02 },
	{ 173,  53,  &anim0144, 165, 12, 0x02 },
	{ 21,   44,  &anim0145, 162, 12, 0x00 },
	{ 373,  1,   &anim0146, 37,  12, 0x02 },
	{ 187,  51,  &anim0147, 165, 12, 0x02 },
	{ 69,   49,  &anim0148, 162, 12, 0x00 },
	{ 217,  6,   &anim0149, 37,  12, 0x02 },
	{ 109,  50,  &anim014a, 165, 12, 0x02 },
	{ 109,  12,  &anim014b, 55,  12, 0x02 },
	{ 111,  4,   &anim014c, 37,  12, 0x02 },
	{ 56,   41,  &anim014d, 165, 12, 0x02 },
	{ 56,   9,   &anim014e, 55,  12, 0x02 },
	{ 365,  3,   &anim014f, 37,  12, 0x02 },
	{ 183,  37,  &anim0150, 165, 12, 0x02 },
	{ 183,  10,  &anim0151, 55,  12, 0x02 },
	{ 335,  3,   &anim0152, 37,  12, 0x02 },
	{ 168,  51,  &anim0153, 165, 12, 0x02 },
	{ 168,  5,   &anim0154, 55,  12, 0x02 },
	{ 291,  7,   &anim0155, 37,  12, 0x02 },
	{ 73,   52,  &anim0156, 165, 12, 0x02 },
	{ 2717, 10,  &anim0157, 57,  12, 0x0a },
	{ 680,  64,  &anim0158, 195, 12, 0x06 },
	{ 680,  55,  &anim0159, 195, 12, 0x06 },
	{ 680,  49,  &anim015a, 175, 12, 0x06 },
	{ 680,  51,  &anim015b, 195, 12, 0x06 },
	{ 680,  49,  &anim015c, 195, 12, 0x06 },
	{ 680,  17,  &anim015d, 70,  12, 0x02 },
	{ 680,  28,  &anim015e, 120, 12, 0x06 },
	{ 33,   5,   &anim015f, 52,  12, 0x01 },
	{ 49,   5,   &anim0160, 52,  12, 0x01 },
	{ 238,  6,   &anim0161, 125, 12, 0x03 },
	{ 238,  5,   &anim0162, 125, 12, 0x03 },
	{ 66,   8,   &anim0163, 52,  12, 0x00 },
	{ 171,  14,  &anim0164, 52,  12, 0x00 },
	{ 1025, 10,  &anim0165, 45,  12, 0x0a },
	{ 257,  57,  &anim0166, 165, 12, 0x02 },
	{ 257,  52,  &anim0167, 175, 12, 0x06 },
	{ 133,  10,  &anim0168, 25,  12, 0x02 },
	{ 94,   10,  &anim0169, 25,  12, 0x02 },
	{ 94,   9,   &anim016a, 45,  12, 0x02 },
	{ 0,    0,   &anim016b, 0,   0,  0x00 },
	{ 0,    0,   &anim016c, 0,   0,  0x00 },
	{ 0,    0,   &anim016d, 0,   0,  0x00 },
	{ 0,    0,   &anim016e, 0,   0,  0x00 },
	{ 0,    0,   &anim016f, 0,   0,  0x00 },
	{ 0,    0,   &anim0170, 0,   0,  0x00 },
	{ 1925, 13,  &anim0171, 63,  12, 0x0a },
	{ 482,  52,  &anim0172, 175, 12, 0x06 },
	{ 482,  50,  &anim0173, 175, 12, 0x06 },
	{ 482,  50,  &anim0174, 179, 12, 0x06 },
	{ 482,  46,  &anim0175, 265, 12, 0x02 },
	{ 0,    0,   &anim0176, 0,   0,  0x00 },
	{ 0,    0,   &anim0177, 0,   0,  0x00 },
	{ 691,  7,   &anim0178, 45,  12, 0x0a },
	{ 173,  49,  &anim0179, 165, 12, 0x02 },
	{ 3757, 10,  &anim017a, 51,  12, 0x0a },
	{ 940,  46,  &anim017b, 171, 12, 0x06 },
	{ 940,  54,  &anim017c, 175, 12, 0x06 },
	{ 1956, 9,   &anim017d, 51,  12, 0x0a },
	{ 489,  48,  &anim017e, 183, 12, 0x06 },
	{ 489,  51,  &anim017f, 179, 12, 0x06 },
	{ 489,  49,  &anim0180, 183, 12, 0x06 },
	{ 1901, 11,  &anim0181, 37,  12, 0x02 },
	{ 476,  45,  &anim0182, 165, 12, 0x02 },
	{ 641,  10,  &anim0183, 51,  12, 0x0a },
	{ 161,  30,  &anim0184, 171, 12, 0x06 },
	{ 161,  43,  &anim0185, 171, 12, 0x06 },
	{ 161,  51,  &anim0186, 171, 12, 0x06 },
	{ 161,  7,   &anim0187, 31,  12, 0x06 },
	{ 1001, 7,   &anim0188, 37,  12, 0x02 },
	{ 251,  48,  &anim0189, 171, 12, 0x06 },
	{ 251,  44,  &anim018a, 175, 12, 0x06 },
	{ 251,  1,   &anim018b, 25,  12, 0x02 },
	{ 3224, 8,   &anim018c, 65,  12, 0x0a },
	{ 806,  52,  &anim018d, 183, 12, 0x06 },
	{ 806,  47,  &anim018e, 175, 12, 0x06 },
	{ 806,  45,  &anim018f, 175, 12, 0x06 },
	{ 84,   46,  &anim0190, 162, 12, 0x00 },
	{ 6105, 10,  &anim0191, 59,  12, 0x0a },
	{ 1527, 53,  &anim0192, 183, 12, 0x06 },
	{ 1527, 50,  &anim0193, 179, 12, 0x06 },
	{ 1527, 49,  &anim0194, 179, 12, 0x06 },
	{ 1527, 46,  &anim0195, 179, 12, 0x06 },
	{ 2907, 11,  &anim0196, 79,  12, 0x0a },
	{ 727,  54,  &anim0197, 165, 12, 0x02 },
	{ 811,  7,   &anim0198, 37,  12, 0x02 },
	{ 203,  48,  &anim0199, 175, 12, 0x06 },
	{ 203,  48,  &anim019a, 175, 12, 0x06 },
	{ 203,  50,  &anim019b, 175, 12, 0x06 },
	{ 4334, 10,  &anim019c, 37,  12, 0x02 },
	{ 1084, 55,  &anim019d, 183, 12, 0x06 },
	{ 1084, 52,  &anim019e, 179, 12, 0x06 },
	{ 1084, 54,  &anim019f, 183, 12, 0x06 },
	{ 1084, 8,   &anim01a0, 43,  12, 0x06 },
	{ 203,  1,   &anim01a1, 31,  12, 0x06 },
	{ 244,  9,   &anim01a2, 45,  12, 0x0a },
	{ 61,   45,  &anim01a3, 165, 12, 0x02 },
	{ 3,    0,   &anim01a4, 25,  12, 0x02 },
	{ 3,    0,   &anim01a5, 25,  12, 0x02 },
	{ 3,    0,   &anim01a6, 25,  12, 0x02 },
	{ 3,    0,   &anim01a7, 25,  12, 0x02 },
	{ 3,    0,   &anim01a8, 25,  12, 0x02 },
	{ 3,    0,   &anim01a9, 25,  12, 0x02 },
	{ 3,    0,   &anim01aa, 25,  12, 0x02 },
	{ 3,    0,   &anim01ab, 265, 12, 0x02 },
	{ 109,  7,   &anim01ac, 37,  12, 0x02 },
	{ 28,   52,  &anim01ad, 375, 12, 0x02 },
	{ 28,   41,  &anim01ae, 375, 12, 0x02 },
	{ 0,    0,   &anim01af, 0,   0,  0x00 },
	{ 0,    0,   &anim01b0, 0,   0,  0x00 },
	{ 359,  6,   &anim01b1, 31,  12, 0x06 },
	{ 0,    0,   &anim01b2, 0,   0,  0x00 },
	{ 0,    0,   &anim01b3, 0,   0,  0x00 },
	{ 3,    0,   &anim01b4, 265, 12, 0x02 },
	{ 2689, 8,   &anim01b5, 45,  12, 0x0a },
	{ 673,  54,  &anim01b6, 171, 12, 0x06 },
	{ 728,  10,  &anim01b7, 37,  12, 0x02 },
	{ 182,  46,  &anim01b8, 175, 12, 0x06 },
	{ 182,  46,  &anim01b9, 171, 12, 0x06 },
	{ 182,  43,  &anim01ba, 175, 12, 0x06 },
	{ 584,  10,  &anim01bb, 51,  12, 0x0a },
	{ 146,  61,  &anim01bc, 165, 12, 0x02 },
	{ 146,  20,  &anim01bd, 256, 12, 0x06 },
	{ 359,  7,   &anim01be, 37,  12, 0x02 },
	{ 90,   43,  &anim01bf, 165, 12, 0x02 },
	{ 90,   0,   &anim01c0, 167, 12, 0x06 },
	{ 90,   25,  &anim01c1, 167, 12, 0x06 },
	{ 3601, 9,   &anim01c2, 57,  12, 0x0a },
	{ 901,  54,  &anim01c3, 179, 12, 0x06 },
	{ 901,  52,  &anim01c4, 183, 12, 0x06 },
	{ 901,  89,  &anim01c5, 389, 12, 0x06 },
	{ 3209, 9,   &anim01c6, 45,  12, 0x0a },
	{ 803,  52,  &anim01c7, 179, 12, 0x06 },
	{ 803,  50,  &anim01c8, 179, 12, 0x06 },
	{ 4,    0,   &anim01c9, 165, 12, 0x02 },
	{ 803,  4,   &anim01ca, 43,  12, 0x06 },
	{ 3581, 8,   &anim01cb, 37,  12, 0x02 },
	{ 896,  53,  &anim01cc, 179, 12, 0x06 },
	{ 896,  47,  &anim01cd, 191, 12, 0x06 },
	{ 896,  47,  &anim01ce, 183, 12, 0x06 },
	{ 896,  5,   &anim01cf, 39,  12, 0x06 },
	{ 410,  7,   &anim01d0, 37,  12, 0x02 },
	{ 103,  44,  &anim01d1, 165, 12, 0x02 },
	{ 410,  9,   &anim01d2, 37,  12, 0x02 },
	{ 103,  45,  &anim01d3, 165, 12, 0x02 },
	{ 4501, 8,   &anim01d4, 57,  12, 0x0a },
	{ 1126, 56,  &anim01d5, 187, 12, 0x06 },
	{ 1126, 52,  &anim01d6, 175, 12, 0x06 },
	{ 1125, 16,  &anim01d7, 84,  12, 0x06 },
	{ 1126, 8,   &anim01d8, 35,  12, 0x06 },
	{ 4807, 11,  &anim01d9, 45,  12, 0x0a },
	{ 1202, 108, &anim01da, 385, 12, 0x06 },
	{ 1202, 52,  &anim01db, 179, 12, 0x06 },
	{ 1202, 50,  &anim01dc, 179, 12, 0x06 },
	{ 1202, 45,  &anim01dd, 183, 12, 0x06 },
	{ 1202, 45,  &anim01de, 175, 12, 0x06 },
	{ 1202, 49,  &anim01df, 175, 12, 0x06 },
	{ 3,    0,   &anim01e0, 27,  12, 0x06 },
	{ 2127, 10,  &anim01e1, 43,  12, 0x0a },
	{ 532,  52,  &anim01e2, 175, 12, 0x06 },
	{ 532,  52,  &anim01e3, 175, 12, 0x06 },
	{ 532,  24,  &anim01e4, 220, 12, 0x06 },
	{ 4001, 11,  &anim01e5, 61,  12, 0x0a },
	{ 1001, 54,  &anim01e6, 179, 12, 0x06 },
	{ 1001, 46,  &anim01e7, 179, 12, 0x06 },
	{ 1001, 45,  &anim01e8, 175, 12, 0x06 },
	{ 1001, 46,  &anim01e9, 175, 12, 0x06 },
	{ 1001, 42,  &anim01ea, 175, 12, 0x06 },
	{ 1001, 42,  &anim01eb, 175, 12, 0x06 },
	{ 1001, 42,  &anim01ec, 175, 12, 0x06 },
	{ 1001, 11,  &anim01ed, 55,  12, 0x06 },
	{ 1001, 9,   &anim01ee, 35,  12, 0x06 },
	{ 3336, 10,  &anim01ef, 77,  12, 0x0a },
	{ 834,  54,  &anim01f0, 179, 12, 0x06 },
	{ 834,  56,  &anim01f1, 179, 12, 0x06 },
	{ 834,  2,   &anim01f2, 35,  12, 0x06 },
	{ 0,    0,   &anim01f3, 0,   0,  0x00 },
	{ 62,   53,  &anim01f4, 162, 12, 0x00 },
	{ 164,  48,  &anim01f5, 162, 12, 0x00 },
	{ 187,  52,  &anim01f6, 189, 12, 0x00 },
	{ 175,  57,  &anim01f7, 180, 12, 0x00 },
	{ 29,   39,  &anim01f8, 162, 12, 0x01 },
	{ 32,   42,  &anim01f9, 162, 12, 0x01 },
	{ 17,   43,  &anim01fa, 162, 12, 0x00 },
	{ 134,  37,  &anim01fb, 162, 12, 0x01 },
	{ 33,   44,  &anim01fc, 162, 12, 0x01 },
	{ 233,  50,  &anim01fd, 162, 12, 0x00 },
	{ 113,  47,  &anim01fe, 162, 12, 0x00 },
	{ 174,  45,  &anim01ff, 162, 12, 0x00 },
	{ 86,   45,  &anim0200, 162, 12, 0x00 },
	{ 16,   29,  &anim0201, 162, 12, 0x01 },
	{ 41,   41,  &anim0202, 162, 12, 0x00 },
	{ 50,   39,  &anim0203, 252, 12, 0x00 },
	{ 188,  44,  &anim0204, 162, 12, 0x00 },
	{ 223,  45,  &anim0205, 162, 12, 0x00 },
	{ 210,  51,  &anim0206, 162, 12, 0x00 },
	{ 291,  45,  &anim0207, 252, 12, 0x00 },
	{ 32,   39,  &anim0208, 252, 12, 0x01 },
	{ 91,   44,  &anim0209, 162, 12, 0x00 },
	{ 17,   40,  &anim020a, 162, 12, 0x01 },
	{ 2,    0,   &anim020b, 162, 12, 0x01 },
	{ 8,    0,   &anim020c, 162, 12, 0x01 },
	{ 20,   39,  &anim020d, 162, 12, 0x01 },
	{ 95,   50,  &anim020e, 162, 12, 0x00 },
	{ 35,   48,  &anim020f, 162, 12, 0x00 },
	{ 43,   50,  &anim0210, 162, 12, 0x00 },
	{ 84,   50,  &anim0211, 162, 12, 0x00 },
	{ 53,   44,  &anim0212, 162, 12, 0x00 },
	{ 57,   47,  &anim0213, 162, 12, 0x00 },
	{ 55,   46,  &anim0214, 162, 12, 0x00 },
	{ 61,   45,  &anim0215, 162, 12, 0x00 },
	{ 165,  46,  &anim0216, 162, 12, 0x00 },
	{ 163,  45,  &anim0217, 162, 12, 0x00 },
	{ 106,  44,  &anim0218, 162, 12, 0x00 },
	{ 192,  49,  &anim0219, 162, 12, 0x00 },
	{ 111,  48,  &anim021a, 162, 12, 0x00 },
	{ 87,   47,  &anim021b, 162, 12, 0x00 },
	{ 58,   46,  &anim021c, 162, 12, 0x00 },
	{ 22,   44,  &anim021d, 162, 12, 0x01 },
	{ 259,  33,  &anim021e, 162, 12, 0x01 },
	{ 259,  36,  &anim021f, 162, 12, 0x01 },
	{ 87,   56,  &anim0220, 162, 12, 0x01 },
	{ 43,   40,  &anim0221, 162, 12, 0x00 },
	{ 37,   38,  &anim0222, 162, 12, 0x00 },
	{ 58,   22,  &anim0223, 162, 12, 0x00 },
	{ 53,   18,  &anim0224, 162, 12, 0x00 },
	{ 67,   44,  &anim0225, 162, 12, 0x00 },
	{ 50,   38,  &anim0226, 162, 12, 0x01 },
	{ 45,   10,  &anim0227, 162, 12, 0x01 },
	{ 218,  53,  &anim0228, 162, 12, 0x00 },
	{ 52,   24,  &anim0229, 162, 12, 0x01 },
	{ 4,    0,   &anim022a, 162, 12, 0x00 },
	{ 185,  48,  &anim022b, 162, 12, 0x00 },
	{ 158,  49,  &anim022c, 162, 12, 0x00 },
	{ 130,  50,  &anim022d, 162, 12, 0x00 },
	{ 0,    0,   &anim022e, 0,   0,  0x00 },
	{ 237,  47,  &anim022f, 162, 12, 0x00 },
	{ 299,  47,  &anim0230, 162, 12, 0x00 },
	{ 66,   28,  &anim0231, 162, 12, 0x00 },
	{ 115,  34,  &anim0232, 162, 12, 0x00 },
	{ 83,   33,  &anim0233, 162, 12, 0x00 },
	{ 101,  37,  &anim0234, 162, 12, 0x00 },
	{ 79,   44,  &anim0235, 162, 12, 0x00 },
	{ 114,  49,  &anim0236, 162, 12, 0x00 },
	{ 479,  6,   &anim0237, 42,  12, 0x01 },
	{ 240,  6,   &anim0238, 42,  12, 0x01 },
	{ 36,   3,   &anim0239, 222, 12, 0x00 },
	{ 137,  41,  &anim023a, 162, 12, 0x00 },
	{ 141,  37,  &anim023b, 162, 12, 0x00 },
	{ 111,  42,  &anim023c, 162, 12, 0x00 },
	{ 80,   48,  &anim023d, 162, 12, 0x00 },
	{ 215,  43,  &anim023e, 162, 12, 0x00 },
	{ 123,  42,  &anim023f, 162, 12, 0x00 },
	{ 270,  47,  &anim0240, 162, 12, 0x00 },
	{ 212,  46,  &anim0241, 162, 12, 0x00 },
	{ 95,   53,  &anim0242, 162, 12, 0x00 },
	{ 116,  51,  &anim0243, 162, 12, 0x00 },
	{ 100,  53,  &anim0244, 162, 12, 0x00 },
	{ 102,  52,  &anim0245, 162, 12, 0x00 },
	{ 124,  50,  &anim0246, 162, 12, 0x00 },
	{ 36,   48,  &anim0247, 162, 12, 0x00 },
	{ 68,   48,  &anim0248, 162, 12, 0x00 },
	{ 22,   42,  &anim0249, 162, 12, 0x00 },
	{ 21,   42,  &anim024a, 162, 12, 0x00 },
	{ 35,   48,  &anim024b, 162, 12, 0x00 },
	{ 43,   50,  &anim024c, 162, 12, 0x00 },
	{ 60,   51,  &anim024d, 162, 12, 0x00 },
	{ 105,  52,  &anim024e, 162, 12, 0x00 },
	{ 157,  52,  &anim024f, 162, 12, 0x00 },
	{ 150,  53,  &anim0250, 162, 12, 0x00 },
	{ 234,  54,  &anim0251, 162, 12, 0x00 },
	{ 192,  53,  &anim0252, 162, 12, 0x00 },
	{ 58,   49,  &anim0253, 162, 12, 0x00 },
	{ 117,  53,  &anim0254, 162, 12, 0x00 },
	{ 62,   54,  &anim0255, 162, 12, 0x00 },
	{ 145,  53,  &anim0256, 162, 12, 0x00 },
	{ 101,  49,  &anim0257, 162, 12, 0x00 },
	{ 177,  53,  &anim0258, 162, 12, 0x00 },
	{ 103,  51,  &anim0259, 162, 12, 0x00 },
	{ 17,   3,   &anim025a, 222, 12, 0x00 },
	{ 148,  42,  &anim025b, 162, 12, 0x00 },
	{ 193,  47,  &anim025c, 162, 12, 0x00 },
	{ 263,  36,  &anim025d, 162, 12, 0x00 },
	{ 263,  39,  &anim025e, 162, 12, 0x00 },
	{ 104,  47,  &anim025f, 162, 12, 0x00 },
	{ 115,  47,  &anim0260, 162, 12, 0x00 },
	{ 221,  52,  &anim0261, 165, 12, 0x02 },
	{ 188,  53,  &anim0262, 165, 12, 0x02 },
	{ 188,  53,  &anim0263, 165, 12, 0x02 },
	{ 108,  45,  &anim0264, 162, 12, 0x00 },
	{ 86,   32,  &anim0265, 162, 12, 0x00 },
	{ 112,  37,  &anim0266, 162, 12, 0x00 },
	{ 188,  53,  &anim0267, 165, 12, 0x02 },
	{ 143,  50,  &anim0268, 165, 12, 0x02 },
	{ 59,   52,  &anim0269, 162, 12, 0x00 },
	{ 3,    0,   &anim026a, 162, 12, 0x00 },
	{ 57,   51,  &anim026b, 162, 12, 0x00 },
	{ 34,   46,  &anim026c, 162, 12, 0x00 },
	{ 620,  49,  &anim026d, 162, 12, 0x00 },
	{ 764,  52,  &anim026e, 162, 12, 0x00 },
	{ 73,   40,  &anim026f, 162, 12, 0x01 },
	{ 66,   39,  &anim0270, 162, 12, 0x01 },
	{ 38,   38,  &anim0271, 162, 12, 0x01 },
	{ 170,  48,  &anim0272, 162, 12, 0x00 },
	{ 365,  49,  &anim0273, 162, 12, 0x00 },
	{ 97,   53,  &anim0274, 162, 12, 0x00 },
	{ 190,  51,  &anim0275, 162, 12, 0x00 },
	{ 231,  41,  &anim0276, 162, 12, 0x00 },
	{ 390,  46,  &anim0277, 162, 12, 0x00 },
	{ 294,  36,  &anim0278, 162, 12, 0x00 },
	{ 21,   39,  &anim0279, 162, 12, 0x00 },
	{ 21,   31,  &anim027a, 162, 12, 0x00 },
	{ 36,   7,   &anim027b, 222, 12, 0x00 },
	{ 60,   53,  &anim027c, 162, 12, 0x00 },
	{ 31,   46,  &anim027d, 162, 12, 0x00 },
	{ 48,   52,  &anim027e, 162, 12, 0x00 },
	{ 69,   51,  &anim027f, 162, 12, 0x00 },
	{ 29,   41,  &anim0280, 162, 12, 0x01 },
	{ 29,   36,  &anim0281, 162, 12, 0x01 },
	{ 29,   37,  &anim0282, 162, 12, 0x01 },
	{ 29,   38,  &anim0283, 162, 12, 0x01 },
	{ 28,   44,  &anim0284, 162, 12, 0x01 },
	{ 28,   41,  &anim0285, 162, 12, 0x01 },
	{ 28,   33,  &anim0286, 162, 12, 0x01 },
	{ 28,   37,  &anim0287, 162, 12, 0x01 },
	{ 51,   44,  &anim0288, 162, 12, 0x00 },
	{ 43,   42,  &anim0289, 162, 12, 0x00 },
	{ 82,   39,  &anim028a, 162, 12, 0x00 },
	{ 0,    0,   &anim028b, 162, 12, 0x00 },
	{ 42,   35,  &anim028c, 162, 12, 0x00 },
	{ 35,   31,  &anim028d, 162, 12, 0x00 },
	{ 66,   28,  &anim028e, 162, 12, 0x00 },
	{ 0,    0,   &anim028f, 0,   0,  0x00 },
	{ 133,  41,  &anim0290, 162, 12, 0x00 },
	{ 77,   41,  &anim0291, 162, 12, 0x00 },
	{ 0,    0,   &anim0292, 162, 12, 0x00 },
	{ 0,    0,   &anim0293, 162, 12, 0x00 },
	{ 0,    0,   &anim0294, 162, 12, 0x00 },
	{ 0,    0,   &anim0295, 162, 12, 0x00 },
	{ 66,   40,  &anim0296, 162, 12, 0x00 },
	{ 140,  42,  &anim0297, 162, 12, 0x00 },
	{ 196,  38,  &anim0298, 162, 12, 0x00 },
	{ 86,   44,  &anim0299, 162, 12, 0x00 },
	{ 174,  44,  &anim029a, 162, 12, 0x00 },
	{ 12,   0,   &anim029b, 162, 12, 0x01 },
	{ 12,   0,   &anim029c, 162, 12, 0x01 },
	{ 12,   0,   &anim029d, 162, 12, 0x01 },
	{ 12,   0,   &anim029e, 162, 12, 0x01 },
	{ 0,    0,   &anim029f, 0,   0,  0x00 },
	{ 0,    0,   &anim02a0, 0,   0,  0x00 },
	{ 0,    0,   &anim02a1, 0,   0,  0x00 },
	{ 0,    0,   &anim02a2, 0,   0,  0x00 },
	{ 0,    0,   &anim02a3, 0,   0,  0x00 },
	{ 0,    0,   &anim02a4, 0,   0,  0x00 },
	{ 0,    0,   &anim02a5, 0,   0,  0x00 },
	{ 0,    0,   &anim02a6, 0,   0,  0x00 },
	{ 0,    0,   &anim02a7, 0,   0,  0x00 },
	{ 0,    0,   &anim02a8, 0,   0,  0x00 },
	{ 0,    0,   &anim02a9, 0,   0,  0x00 },
	{ 0,    0,   &anim02aa, 0,   0,  0x00 },
	{ 0,    0,   &anim02ab, 0,   0,  0x00 },
	{ 0,    0,   &anim02ac, 0,   0,  0x00 },
	{ 0,    0,   &anim02ad, 0,   0,  0x00 },
	{ 0,    0,   &anim02ae, 0,   0,  0x00 },
	{ 0,    0,   &anim02af, 0,   0,  0x00 },
	{ 0,    0,   &anim02b0, 0,   0,  0x00 },
	{ 0,    0,   &anim02b1, 0,   0,  0x00 },
	{ 0,    0,   &anim02b2, 0,   0,  0x00 },
	{ 0,    0,   &anim02b3, 0,   0,  0x00 },
	{ 0,    0,   &anim02b4, 0,   0,  0x00 },
	{ 0,    0,   &anim02b5, 0,   0,  0x00 },
	{ 0,    0,   &anim02b6, 0,   0,  0x00 },
	{ 0,    0,   &anim02b7, 0,   0,  0x00 },
	{ 0,    0,   &anim02b8, 0,   0,  0x00 },
	{ 0,    0,   &anim02b9, 0,   0,  0x00 },
	{ 0,    0,   &anim02ba, 0,   0,  0x00 },
	{ 0,    0,   &anim02bb, 0,   0,  0x00 },
	{ 3651, 11,  &anim02bc, 63,  12, 0x0a },
	{ 913,  55,  &anim02bd, 175, 12, 0x06 },
	{ 913,  52,  &anim02be, 175, 12, 0x06 },
	{ 913,  47,  &anim02bf, 179, 12, 0x06 },
	{ 913,  49,  &anim02c0, 179, 12, 0x06 },
	{ 913,  22,  &anim02c1, 279, 12, 0x06 },
	{ 803,  8,   &anim02c2, 37,  12, 0x02 },
	{ 201,  100, &anim02c3, 375, 12, 0x02 },
	{ 201,  50,  &anim02c4, 165, 12, 0x02 },
	{ 201,  9,   &anim02c5, 25,  12, 0x02 },
	{ 201,  8,   &anim02c6, 25,  12, 0x02 },
	{ 4413, 12,  &anim02c7, 51,  12, 0x0a },
	{ 1104, 54,  &anim02c8, 171, 12, 0x06 },
	{ 1104, 53,  &anim02c9, 171, 12, 0x06 },
	{ 3,    0,   &anim02ca, 25,  12, 0x02 },
	{ 3,    0,   &anim02cb, 25,  12, 0x02 },
	{ 1104, 0,   &anim02cc, 25,  12, 0x02 },
	{ 1104, 0,   &anim02cd, 25,  12, 0x02 },
	{ 2663, 8,   &anim02ce, 51,  12, 0x0a },
	{ 666,  54,  &anim02cf, 175, 12, 0x06 },
	{ 666,  50,  &anim02d0, 171, 12, 0x06 },
	{ 666,  45,  &anim02d1, 175, 12, 0x06 },
	{ 325,  8,   &anim02d2, 37,  12, 0x02 },
	{ 82,   12,  &anim02d3, 45,  12, 0x02 },
	{ 307,  8,   &anim02d4, 37,  12, 0x02 },
	{ 77,   13,  &anim02d5, 45,  12, 0x02 },
	{ 149,  11,  &anim02d6, 25,  12, 0x02 },
	{ 1611, 12,  &anim02d7, 37,  12, 0x02 },
	{ 2201, 13,  &anim02d8, 45,  12, 0x0a },
	{ 598,  55,  &anim02d9, 183, 12, 0x06 },
	{ 598,  49,  &anim02da, 175, 12, 0x06 },
	{ 551,  10,  &anim02db, 220, 12, 0x06 },
	{ 598,  14,  &anim02dc, 55,  12, 0x06 },
	{ 598,  0,   &anim02dd, 43,  12, 0x06 },
	{ 598,  4,   &anim02de, 35,  12, 0x06 },
	{ 1279, 9,   &anim02df, 37,  12, 0x02 },
	{ 320,  35,  &anim02e0, 210, 12, 0x02 },
	{ 320,  3,   &anim02e1, 25,  12, 0x02 },
	{ 1961, 12,  &anim02e2, 45,  12, 0x0a },
	{ 491,  54,  &anim02e3, 165, 12, 0x02 },
	{ 491,  55,  &anim02e4, 165, 12, 0x02 },
	{ 491,  4,   &anim02e5, 65,  12, 0x02 },
	{ 491,  2,   &anim02e6, 25,  12, 0x02 },
	{ 491,  9,   &anim02e7, 25,  12, 0x02 },
	{ 491,  9,   &anim02e8, 25,  12, 0x02 },
	{ 601,  5,   &anim02e9, 37,  12, 0x02 },
	{ 409,  8,   &anim02ea, 37,  12, 0x02 },
	{ 103,  34,  &anim02eb, 165, 12, 0x02 },
	{ 103,  39,  &anim02ec, 165, 12, 0x02 },
	{ 561,  4,   &anim02ed, 37,  12, 0x02 },
	{ 141,  90,  &anim02ee, 375, 12, 0x02 },
	{ 141,  91,  &anim02ef, 375, 12, 0x02 },
	{ 141,  91,  &anim02f0, 375, 12, 0x02 },
	{ 455,  7,   &anim02f1, 37,  12, 0x02 },
	{ 114,  37,  &anim02f2, 165, 12, 0x02 },
	{ 114,  39,  &anim02f3, 165, 12, 0x02 },
	{ 359,  5,   &anim02f4, 37,  12, 0x02 },
	{ 90,   89,  &anim02f5, 375, 12, 0x02 },
	{ 90,   90,  &anim02f6, 375, 12, 0x02 },
	{ 90,   92,  &anim02f7, 375, 12, 0x02 },
	{ 90,   91,  &anim02f8, 375, 12, 0x02 },
	{ 751,  5,   &anim02f9, 37,  12, 0x02 },
	{ 751,  33,  &anim02fa, 210, 12, 0x02 },
	{ 1231, 9,   &anim02fb, 37,  12, 0x02 },
	{ 308,  65,  &anim02fc, 375, 12, 0x02 },
	{ 308,  69,  &anim02fd, 375, 12, 0x02 },
	{ 308,  64,  &anim02fe, 375, 12, 0x02 },
	{ 308,  62,  &anim02ff, 375, 12, 0x02 },
	{ 308,  89,  &anim0300, 375, 12, 0x02 },
	{ 546,  8,   &anim0301, 37,  12, 0x02 },
	{ 137,  30,  &anim0302, 210, 12, 0x02 },
	{ 137,  51,  &anim0303, 165, 12, 0x02 },
	{ 77,   40,  &anim0304, 171, 12, 0x06 },
	{ 718,  9,   &anim0305, 45,  12, 0x0a },
	{ 180,  54,  &anim0306, 171, 12, 0x06 },
	{ 3,    0,   &anim0307, 25,  12, 0x02 },
	{ 3,    0,   &anim0308, 25,  12, 0x02 },
	{ 3,    0,   &anim0309, 25,  12, 0x02 },
	{ 3,    0,   &anim030a, 25,  12, 0x02 },
	{ 3,    0,   &anim030b, 25,  12, 0x02 },
	{ 3,    0,   &anim030c, 25,  12, 0x02 },
	{ 3,    0,   &anim030d, 25,  12, 0x02 },
	{ 180,  6,   &anim030e, 25,  12, 0x02 },
	{ 180,  29,  &anim030f, 275, 12, 0x06 },
	{ 365,  8,   &anim0310, 37,  12, 0x02 },
	{ 92,   49,  &anim0311, 165, 12, 0x02 },
	{ 92,   66,  &anim0312, 375, 12, 0x02 },
	{ 3,    0,   &anim0313, 25,  12, 0x02 },
	{ 3,    0,   &anim0314, 25,  12, 0x02 },
	{ 3,    0,   &anim0315, 25,  12, 0x02 },
	{ 3,    0,   &anim0316, 25,  12, 0x02 },
	{ 92,   8,   &anim0317, 25,  12, 0x02 },
	{ 3,    0,   &anim0318, 25,  12, 0x02 },
	{ 92,   8,   &anim0319, 25,  12, 0x02 },
	{ 1501, 13,  &anim031a, 57,  12, 0x0a },
	{ 376,  42,  &anim031b, 171, 12, 0x06 },
	{ 376,  10,  &anim031c, 31,  12, 0x06 },
	{ 0,    0,   &anim031d, 0,   0,  0x00 },
	{ 0,    0,   &anim031e, 0,   0,  0x00 },
	{ 0,    0,   &anim031f, 0,   0,  0x00 },
	{ 175,  40,  &anim0320, 372, 12, 0x01 },
	{ 115,  92,  &anim0321, 372, 12, 0x00 },
	{ 0,    0,   &anim0322, 0,   0,  0x00 },
	{ 0,    0,   &anim0323, 0,   0,  0x00 },
	{ 0,    0,   &anim0324, 0,   0,  0x00 },
	{ 0,    0,   &anim0325, 0,   0,  0x00 },
	{ 0,    0,   &anim0326, 0,   0,  0x00 },
	{ 0,    0,   &anim0327, 0,   0,  0x00 },
	{ 0,    0,   &anim0328, 0,   0,  0x00 },
	{ 140,  100, &anim0329, 372, 12, 0x01 },
	{ 100,  111, &anim032a, 372, 12, 0x01 },
	{ 150,  100, &anim032b, 372, 12, 0x00 },
	{ 90,   123, &anim032c, 372, 12, 0x00 },
	{ 87,   49,  &anim032d, 372, 12, 0x00 },
	{ 175,  40,  &anim032e, 372, 12, 0x00 },
	{ 230,  114, &anim032f, 372, 12, 0x00 },
	{ 60,   54,  &anim0330, 372, 12, 0x00 },
	{ 120,  73,  &anim0331, 372, 12, 0x00 },
	{ 480,  86,  &anim0332, 372, 12, 0x00 },
	{ 80,   79,  &anim0333, 372, 12, 0x00 },
	{ 175,  57,  &anim0334, 372, 12, 0x00 },
	{ 200,  111, &anim0335, 372, 12, 0x00 },
	{ 86,   129, &anim0336, 372, 12, 0x00 },
	{ 79,   130, &anim0337, 372, 12, 0x00 },
	{ 175,  99,  &anim0338, 372, 12, 0x00 },
	{ 80,   118, &anim0339, 372, 12, 0x00 },
	{ 80,   122, &anim033a, 372, 12, 0x00 },
	{ 80,   128, &anim033b, 372, 12, 0x00 },
	{ 80,   130, &anim033c, 372, 12, 0x00 },
	{ 110,  128, &anim033d, 372, 12, 0x00 },
	{ 100,  135, &anim033e, 372, 12, 0x00 },
	{ 50,   133, &anim033f, 372, 12, 0x00 },
	{ 100,  91,  &anim0340, 372, 12, 0x00 },
	{ 80,   123, &anim0341, 372, 12, 0x00 },
	{ 135,  101, &anim0342, 372, 12, 0x00 },
	{ 100,  96,  &anim0343, 372, 12, 0x00 },
	{ 60,   107, &anim0344, 372, 12, 0x00 },
	{ 0,    0,   &anim0345, 0,   0,  0x00 },
	{ 105,  120, &anim0346, 372, 12, 0x00 },
	{ 105,  124, &anim0347, 372, 12, 0x00 },
	{ 50,   87,  &anim0348, 372, 12, 0x00 },
	{ 50,   88,  &anim0349, 372, 12, 0x00 },
	{ 50,   95,  &anim034a, 372, 12, 0x00 },
	{ 70,   130, &anim034b, 372, 12, 0x00 },
	{ 70,   109, &anim034c, 372, 12, 0x00 },
	{ 75,   88,  &anim034d, 372, 12, 0x00 },
	{ 186,  88,  &anim034e, 372, 12, 0x00 },
	{ 92,   88,  &anim034f, 372, 12, 0x00 },
	{ 98,   78,  &anim0350, 372, 12, 0x00 },
	{ 336,  52,  &anim0351, 372, 12, 0x00 },
	{ 9,    0,   &anim0352, 372, 12, 0x00 },
	{ 0,    0,   &anim0353, 0,   0,  0x00 },
	{ 0,    0,   &anim0354, 0,   0,  0x00 },
	{ 0,    0,   &anim0355, 0,   0,  0x00 },
	{ 0,    0,   &anim0356, 0,   0,  0x00 },
	{ 0,    0,   &anim0357, 0,   0,  0x00 },
	{ 0,    0,   &anim0358, 0,   0,  0x00 },
	{ 0,    0,   &anim0359, 0,   0,  0x00 },
	{ 0,    0,   &anim035a, 0,   0,  0x00 },
	{ 0,    0,   &anim035b, 0,   0,  0x00 },
	{ 0,    0,   &anim035c, 0,   0,  0x00 },
	{ 0,    0,   &anim035d, 0,   0,  0x00 },
	{ 0,    0,   &anim035e, 0,   0,  0x00 },
	{ 0,    0,   &anim035f, 0,   0,  0x00 },
	{ 0,    0,   &anim0360, 0,   0,  0x00 },
	{ 0,    0,   &anim0361, 0,   0,  0x00 },
	{ 0,    0,   &anim0362, 0,   0,  0x00 },
	{ 0,    0,   &anim0363, 0,   0,  0x00 },
	{ 0,    0,   &anim0364, 0,   0,  0x00 },
	{ 0,    0,   &anim0365, 0,   0,  0x00 },
	{ 0,    0,   &anim0366, 0,   0,  0x00 },
	{ 0,    0,   &anim0367, 0,   0,  0x00 },
	{ 0,    0,   &anim0368, 0,   0,  0x00 },
	{ 0,    0,   &anim0369, 0,   0,  0x00 },
	{ 0,    0,   &anim036a, 0,   0,  0x00 },
	{ 0,    0,   &anim036b, 0,   0,  0x00 },
	{ 0,    0,   &anim036c, 0,   0,  0x00 },
	{ 0,    0,   &anim036d, 0,   0,  0x00 },
	{ 0,    0,   &anim036e, 0,   0,  0x00 },
	{ 0,    0,   &anim036f, 0,   0,  0x00 },
	{ 0,    0,   &anim0370, 0,   0,  0x00 },
	{ 0,    0,   &anim0371, 0,   0,  0x00 },
	{ 0,    0,   &anim0372, 0,   0,  0x00 },
	{ 0,    0,   &anim0373, 0,   0,  0x00 },
	{ 0,    0,   &anim0374, 0,   0,  0x00 },
	{ 0,    0,   &anim0375, 0,   0,  0x00 },
	{ 0,    0,   &anim0376, 0,   0,  0x00 },
	{ 0,    0,   &anim0377, 0,   0,  0x00 },
	{ 0,    0,   &anim0378, 0,   0,  0x00 },
	{ 0,    0,   &anim0379, 0,   0,  0x00 },
	{ 0,    0,   &anim037a, 0,   0,  0x00 },
	{ 0,    0,   &anim037b, 0,   0,  0x00 },
	{ 0,    0,   &anim037c, 0,   0,  0x00 },
	{ 0,    0,   &anim037d, 0,   0,  0x00 },
	{ 0,    0,   &anim037e, 0,   0,  0x00 },
	{ 0,    0,   &anim037f, 0,   0,  0x00 },
	{ 0,    0,   &anim0380, 0,   0,  0x00 },
	{ 0,    0,   &anim0381, 0,   0,  0x00 },
	{ 0,    0,   &anim0382, 0,   0,  0x00 },
	{ 0,    0,   &anim0383, 0,   0,  0x00 },
	{ 48,   75,  &anim0384, 372, 12, 0x00 },
	{ 60,   26,  &anim0385, 372, 12, 0x01 },
	{ 0,    0,   &anim0386, 0,   0,  0x00 },
	{ 0,    0,   &anim0387, 0,   0,  0x00 },
	{ 0,    0,   &anim0388, 0,   0,  0x00 },
	{ 0,    0,   &anim0389, 0,   0,  0x00 },
	{ 0,    0,   &anim038a, 0,   0,  0x00 },
	{ 136,  99,  &anim038b, 372, 12, 0x00 },
	{ 80,   93,  &anim038c, 372, 12, 0x00 },
	{ 160,  88,  &anim038d, 372, 12, 0x00 },
	{ 104,  83,  &anim038e, 372, 12, 0x00 },
	{ 80,   93,  &anim038f, 372, 12, 0x00 },
	{ 112,  96,  &anim0390, 372, 12, 0x00 },
	{ 160,  87,  &anim0391, 372, 12, 0x00 },
	{ 61,   91,  &anim0392, 372, 12, 0x01 },
	{ 59,   89,  &anim0393, 372, 12, 0x01 },
	{ 29,   88,  &anim0394, 372, 12, 0x01 },
	{ 100,  96,  &anim0395, 372, 12, 0x00 },
	{ 50,   51,  &anim0396, 162, 12, 0x00 },
	{ 75,   53,  &anim0397, 162, 12, 0x00 },
	{ 47,   51,  &anim0398, 162, 12, 0x00 },
	{ 35,   49,  &anim0399, 162, 12, 0x00 },
	{ 25,   44,  &anim039a, 162, 12, 0x00 },
	{ 19,   42,  &anim039b, 162, 12, 0x00 },
	{ 23,   43,  &anim039c, 162, 12, 0x00 },
	{ 90,   47,  &anim039d, 162, 12, 0x00 },
	{ 0,    0,   &anim039e, 0,   0,  0x00 },
	{ 0,    0,   &anim039f, 0,   0,  0x00 },
	{ 0,    0,   &anim03a0, 0,   0,  0x00 },
	{ 0,    0,   &anim03a1, 0,   0,  0x00 },
	{ 0,    0,   &anim03a2, 0,   0,  0x00 },
	{ 0,    0,   &anim03a3, 0,   0,  0x00 },
	{ 0,    0,   &anim03a4, 0,   0,  0x00 },
	{ 0,    0,   &anim03a5, 0,   0,  0x00 },
	{ 0,    0,   &anim03a6, 0,   0,  0x00 },
	{ 0,    0,   &anim03a7, 0,   0,  0x00 },
	{ 0,    0,   &anim03a8, 0,   0,  0x00 },
	{ 0,    0,   &anim03a9, 0,   0,  0x00 },
	{ 0,    0,   &anim03aa, 0,   0,  0x00 },
	{ 0,    0,   &anim03ab, 0,   0,  0x00 },
	{ 0,    0,   &anim03ac, 0,   0,  0x00 },
	{ 0,    0,   &anim03ad, 0,   0,  0x00 },
	{ 0,    0,   &anim03ae, 0,   0,  0x00 },
	{ 0,    0,   &anim03af, 0,   0,  0x00 },
	{ 0,    0,   &anim03b0, 0,   0,  0x00 },
	{ 0,    0,   &anim03b1, 0,   0,  0x00 },
	{ 0,    0,   &anim03b2, 0,   0,  0x00 },
	{ 0,    0,   &anim03b3, 0,   0,  0x00 },
	{ 0,    0,   &anim03b4, 0,   0,  0x00 },
	{ 0,    0,   &anim03b5, 0,   0,  0x00 },
	{ 0,    0,   &anim03b6, 0,   0,  0x00 },
	{ 0,    0,   &anim03b7, 0,   0,  0x00 },
	{ 0,    0,   &anim03b8, 0,   0,  0x00 },
	{ 0,    0,   &anim03b9, 0,   0,  0x00 },
	{ 0,    0,   &anim03ba, 0,   0,  0x00 },
	{ 0,    0,   &anim03bb, 0,   0,  0x00 },
	{ 0,    0,   &anim03bc, 0,   0,  0x00 },
	{ 0,    0,   &anim03bd, 0,   0,  0x00 },
	{ 0,    0,   &anim03be, 0,   0,  0x00 },
	{ 0,    0,   &anim03bf, 0,   0,  0x00 },
	{ 0,    0,   &anim03c0, 0,   0,  0x00 },
	{ 0,    0,   &anim03c1, 0,   0,  0x00 },
	{ 0,    0,   &anim03c2, 0,   0,  0x00 },
	{ 0,    0,   &anim03c3, 0,   0,  0x00 },
	{ 0,    0,   &anim03c4, 0,   0,  0x00 },
	{ 0,    0,   &anim03c5, 0,   0,  0x00 },
	{ 0,    0,   &anim03c6, 0,   0,  0x00 },
	{ 0,    0,   &anim03c7, 0,   0,  0x00 },
	{ 0,    0,   &anim03c8, 0,   0,  0x00 },
	{ 0,    0,   &anim03c9, 0,   0,  0x00 },
	{ 0,    0,   &anim03ca, 0,   0,  0x00 },
	{ 0,    0,   &anim03cb, 0,   0,  0x00 },
	{ 0,    0,   &anim03cc, 0,   0,  0x00 },
	{ 0,    0,   &anim03cd, 0,   0,  0x00 },
	{ 0,    0,   &anim03ce, 0,   0,  0x00 },
	{ 0,    0,   &anim03cf, 0,   0,  0x00 },
	{ 0,    0,   &anim03d0, 0,   0,  0x00 },
	{ 0,    0,   &anim03d1, 0,   0,  0x00 },
	{ 0,    0,   &anim03d2, 0,   0,  0x00 },
	{ 0,    0,   &anim03d3, 0,   0,  0x00 },
	{ 0,    0,   &anim03d4, 0,   0,  0x00 },
	{ 0,    0,   &anim03d5, 0,   0,  0x00 },
	{ 0,    0,   &anim03d6, 0,   0,  0x00 },
	{ 0,    0,   &anim03d7, 0,   0,  0x00 },
	{ 0,    0,   &anim03d8, 0,   0,  0x00 },
	{ 0,    0,   &anim03d9, 0,   0,  0x00 },
	{ 0,    0,   &anim03da, 0,   0,  0x00 },
	{ 0,    0,   &anim03db, 0,   0,  0x00 },
	{ 0,    0,   &anim03dc, 0,   0,  0x00 },
	{ 0,    0,   &anim03dd, 0,   0,  0x00 },
	{ 0,    0,   &anim03de, 0,   0,  0x00 },
	{ 0,    0,   &anim03df, 0,   0,  0x00 },
	{ 0,    0,   &anim03e0, 0,   0,  0x00 },
	{ 0,    0,   &anim03e1, 0,   0,  0x00 },
	{ 0,    0,   &anim03e2, 0,   0,  0x00 },
	{ 0,    0,   &anim03e3, 0,   0,  0x00 },
	{ 0,    0,   &anim03e4, 0,   0,  0x00 },
	{ 0,    0,   &anim03e5, 0,   0,  0x00 },
	{ 0,    0,   &anim03e6, 0,   0,  0x00 },
	{ 0,    0,   &anim03e7, 0,   0,  0x00 },
	{ 0,    0,   &anim03e8, 0,   0,  0x00 },
	{ 36,   8,   &anim03e9, 339, 12, 0x00 },
	{ 30,   10,  &anim03ea, 339, 12, 0x00 },
	{ 130,  60,  &anim03eb, 534, 12, 0x00 },
	{ 34,   34,  &anim03ec, 507, 12, 0x00 },
	{ 130,  53,  &anim03ed, 435, 12, 0x00 },
	{ 75,   56,  &anim03ee, 426, 12, 0x00 },
	{ 140,  58,  &anim03ef, 425, 12, 0x00 },
	{ 38,   25,  &anim03f0, 398, 12, 0x00 },
	{ 92,   18,  &anim03f1, 493, 12, 0x00 },
	{ 58,   12,  &anim03f2, 466, 12, 0x00 },
	{ 18,   16,  &anim03f3, 399, 12, 0x00 },
	{ 92,   62,  &anim03f4, 444, 12, 0x00 },
	{ 92,   19,  &anim03f5, 435, 12, 0x00 },
	{ 58,   12,  &anim03f6, 408, 12, 0x00 },
	{ 18,   21,  &anim03f7, 436, 12, 0x00 },
	{ 118,  65,  &anim03f8, 454, 12, 0x00 },
	{ 38,   20,  &anim03f9, 437, 12, 0x00 },
	{ 108,  75,  &anim03fa, 464, 12, 0x00 },
	{ 108,  79,  &anim03fb, 493, 12, 0x00 },
	{ 112,  64,  &anim03fc, 484, 12, 0x00 },
	{ 26,   33,  &anim03fd, 457, 12, 0x00 },
	{ 38,   17,  &anim03fe, 457, 12, 0x00 },
	{ 38,   9,   &anim03ff, 457, 12, 0x00 },
	{ 34,   9,   &anim0400, 527, 12, 0x00 },
	{ 208,  55,  &anim0401, 554, 12, 0x00 },
	{ 54,   6,   &anim0402, 359, 12, 0x00 },
	{ 56,   10,  &anim0403, 368, 12, 0x00 },
	{ 58,   8,   &anim0404, 368, 12, 0x00 },
	{ 48,   48,  &anim0405, 368, 12, 0x00 },
	{ 26,   17,  &anim0406, 497, 12, 0x00 },
	{ 58,   12,  &anim0407, 497, 12, 0x00 },
	{ 166,  47,  &anim0408, 524, 12, 0x00 },
	{ 92,   70,  &anim0409, 463, 12, 0x00 },
	{ 92,   18,  &anim040a, 454, 12, 0x00 },
	{ 26,   18,  &anim040b, 436, 12, 0x00 },
	{ 18,   0,   &anim040c, 438, 12, 0x00 },
	{ 45,   12,  &anim040d, 97,  12, 0x00 },
	{ 144,  47,  &anim040e, 407, 12, 0x00 },
	{ 158,  69,  &anim040f, 474, 12, 0x00 },
	{ 98,   46,  &anim0410, 453, 12, 0x00 },
	{ 58,   11,  &anim0411, 444, 12, 0x00 },
	{ 0,    0,   &anim0412, 0,   0,  0x00 },
	{ 0,    0,   &anim0413, 0,   0,  0x00 },
	{ 0,    0,   &anim0414, 0,   0,  0x00 },
	{ 128,  61,  &anim0415, 472, 12, 0x00 },
	{ 0,    0,   &anim0416, 0,   0,  0x00 },
	{ 92,   66,  &anim0417, 502, 12, 0x00 },
	{ 138,  80,  &anim0418, 502, 12, 0x00 },
	{ 134,  71,  &anim0419, 454, 12, 0x00 },
	{ 154,  75,  &anim041a, 473, 12, 0x00 },
	{ 42,   35,  &anim041b, 368, 12, 0x00 },
	{ 48,   35,  &anim041c, 359, 12, 0x00 },
	{ 258,  51,  &anim041d, 162, 12, 0x00 },
	{ 0,    0,   &anim041e, 0,   0,  0x00 },
	{ 28,   17,  &anim041f, 339, 12, 0x00 },
	{ 166,  10,  &anim0420, 524, 12, 0x00 },
	{ 144,  5,   &anim0421, 407, 12, 0x00 },
	{ 128,  25,  &anim0422, 454, 12, 0x00 },
	{ 128,  5,   &anim0423, 436, 12, 0x00 },
	{ 18,   12,  &anim0424, 437, 12, 0x00 },
	{ 38,   17,  &anim0425, 348, 12, 0x00 },
	{ 66,   46,  &anim0426, 377, 12, 0x00 },
	{ 54,   14,  &anim0427, 527, 12, 0x00 },
	{ 34,   30,  &anim0428, 527, 12, 0x00 },
	{ 178,  65,  &anim0429, 415, 12, 0x00 },
	{ 34,   23,  &anim042a, 397, 12, 0x00 },
	{ 38,   7,   &anim042b, 368, 12, 0x00 },
	{ 105,  56,  &anim042c, 426, 12, 0x00 },
	{ 18,   15,  &anim042d, 444, 12, 0x00 },
	{ 28,   28,  &anim042e, 368, 12, 0x00 },
	{ 28,   28,  &anim042f, 368, 12, 0x00 },
	{ 38,   7,   &anim0430, 358, 12, 0x00 },
	{ 28,   6,   &anim0431, 358, 12, 0x00 },
	{ 62,   17,  &anim0432, 406, 12, 0x00 },
	{ 28,   11,  &anim0433, 406, 12, 0x00 },
	{ 18,   19,  &anim0434, 415, 12, 0x00 },
	{ 14,   6,   &anim0435, 358, 12, 0x00 },
	{ 12,   6,   &anim0436, 406, 12, 0x00 },
	{ 68,   11,  &anim0437, 377, 12, 0x00 },
	{ 28,   12,  &anim0438, 377, 12, 0x00 },
	{ 28,   7,   &anim0439, 368, 12, 0x00 },
	{ 28,   7,   &anim043a, 368, 12, 0x00 },
	{ 16,   10,  &anim043b, 377, 12, 0x00 },
	{ 18,   12,  &anim043c, 448, 12, 0x00 },
	{ 18,   13,  &anim043d, 398, 12, 0x00 },
	{ 18,   16,  &anim043e, 427, 12, 0x00 },
	{ 26,   13,  &anim043f, 418, 12, 0x00 },
	{ 26,   13,  &anim0440, 409, 12, 0x00 },
	{ 0,    0,   &anim0441, 0,   0,  0x00 },
	{ 0,    0,   &anim0442, 0,   0,  0x00 },
	{ 0,    0,   &anim0443, 0,   0,  0x00 },
	{ 0,    0,   &anim0444, 0,   0,  0x00 },
	{ 0,    0,   &anim0445, 0,   0,  0x00 },
	{ 0,    0,   &anim0446, 0,   0,  0x00 },
	{ 0,    0,   &anim0447, 0,   0,  0x00 },
	{ 0,    0,   &anim0448, 0,   0,  0x00 },
	{ 0,    0,   &anim0449, 0,   0,  0x00 },
	{ 0,    0,   &anim044a, 0,   0,  0x00 },
	{ 0,    0,   &anim044b, 0,   0,  0x00 },
	{ 181,  9,   &anim044c, 37,  12, 0x02 },
	{ 46,   58,  &anim044d, 375, 12, 0x02 },
	{ 46,   6,   &anim044e, 25,  12, 0x02 },
	{ 731,  10,  &anim044f, 37,  12, 0x02 },
	{ 183,  0,   &anim0450, 375, 12, 0x02 },
	{ 183,  52,  &anim0451, 165, 12, 0x02 },
	{ 183,  0,   &anim0452, 25,  12, 0x02 },
	{ 183,  10,  &anim0453, 25,  12, 0x02 },
	{ 183,  9,   &anim0454, 25,  12, 0x02 },
	{ 183,  10,  &anim0455, 25,  12, 0x02 },
	{ 183,  10,  &anim0456, 25,  12, 0x02 },
	{ 183,  10,  &anim0457, 25,  12, 0x02 },
	{ 183,  7,   &anim0458, 25,  12, 0x02 },
	{ 46,   2,   &anim0459, 45,  12, 0x02 },
	{ 7,    1,   &anim045a, 210, 12, 0x02 },
	{ 73,   31,  &anim045b, 210, 12, 0x02 },
	{ 13,   0,   &anim045c, 195, 12, 0x02 },
	{ 701,  2,   &anim045d, 37,  12, 0x02 },
	{ 176,  0,   &anim045e, 25,  12, 0x02 },
	{ 0,    0,   &anim045f, 0,   0,  0x00 },
	{ 0,    0,   &anim0460, 0,   0,  0x00 },
	{ 500,  1,   &anim0461, 37,  12, 0x02 },
	{ 125,  2,   &anim0462, 25,  12, 0x03 },
	{ 125,  3,   &anim0463, 25,  12, 0x02 },
	{ 500,  5,   &anim0464, 37,  12, 0x02 },
	{ 125,  3,   &anim0465, 25,  12, 0x02 },
	{ 0,    0,   &anim0466, 0,   0,  0x00 },
	{ 0,    0,   &anim0467, 0,   0,  0x00 },
	{ 0,    0,   &anim0468, 0,   0,  0x00 },
	{ 0,    0,   &anim0469, 0,   0,  0x00 },
	{ 0,    0,   &anim046a, 0,   0,  0x00 },
	{ 0,    0,   &anim046b, 0,   0,  0x00 },
	{ 501,  0,   &anim046c, 37,  12, 0x02 },
	{ 126,  1,   &anim046d, 25,  12, 0x03 },
	{ 126,  3,   &anim046e, 25,  12, 0x02 },
	{ 126,  7,   &anim046f, 25,  12, 0x02 },
	{ 1041, 2,   &anim0470, 45,  12, 0x02 },
	{ 834,  54,  &anim0471, 171, 12, 0x06 },
	{ 337,  7,   &anim0472, 37,  12, 0x02 },
	{ 85,   43,  &anim0473, 165, 12, 0x02 },
	{ 361,  8,   &anim0474, 37,  12, 0x02 },
	{ 91,   24,  &anim0475, 210, 12, 0x02 },
	{ 561,  6,   &anim0476, 37,  12, 0x02 },
	{ 141,  49,  &anim0477, 165, 12, 0x02 },
	{ 141,  5,   &anim0478, 25,  12, 0x02 },
	{ 411,  7,   &anim0479, 37,  12, 0x02 },
	{ 103,  52,  &anim047a, 171, 12, 0x06 },
	{ 103,  50,  &anim047b, 175, 12, 0x06 },
	{ 441,  7,   &anim047c, 37,  12, 0x02 },
	{ 111,  45,  &anim047d, 165, 12, 0x02 },
	{ 111,  47,  &anim047e, 165, 12, 0x02 },
	{ 111,  39,  &anim047f, 165, 12, 0x02 },
	{ 277,  8,   &anim0480, 37,  12, 0x02 },
	{ 70,   40,  &anim0481, 171, 12, 0x06 },
	{ 70,   41,  &anim0482, 171, 12, 0x06 },
	{ 70,   41,  &anim0483, 165, 12, 0x02 },
	{ 301,  7,   &anim0484, 37,  12, 0x02 },
	{ 76,   42,  &anim0485, 165, 12, 0x02 },
	{ 3,    0,   &anim0486, 195, 12, 0x02 },
	{ 3,    0,   &anim0487, 165, 12, 0x02 },
	{ 221,  0,   &anim0488, 37,  12, 0x02 },
	{ 4,    0,   &anim0489, 195, 12, 0x02 },
	{ 0,    0,   &anim048a, 0,   0,  0x00 },
	{ 0,    0,   &anim048b, 0,   0,  0x00 },
	{ 0,    0,   &anim048c, 0,   0,  0x00 },
	{ 0,    0,   &anim048d, 0,   0,  0x00 },
	{ 0,    0,   &anim048e, 0,   0,  0x00 },
	{ 0,    0,   &anim048f, 0,   0,  0x00 },
	{ 0,    0,   &anim0490, 0,   0,  0x00 },
	{ 0,    0,   &anim0491, 0,   0,  0x00 },
	{ 0,    0,   &anim0492, 0,   0,  0x00 },
	{ 0,    0,   &anim0493, 0,   0,  0x00 },
	{ 0,    0,   &anim0494, 0,   0,  0x00 },
	{ 0,    0,   &anim0495, 0,   0,  0x00 },
	{ 0,    0,   &anim0496, 0,   0,  0x00 },
	{ 0,    0,   &anim0497, 0,   0,  0x00 },
	{ 0,    0,   &anim0498, 0,   0,  0x00 },
	{ 0,    0,   &anim0499, 0,   0,  0x00 },
	{ 0,    0,   &anim049a, 0,   0,  0x00 },
	{ 0,    0,   &anim049b, 0,   0,  0x00 },
	{ 0,    0,   &anim049c, 0,   0,  0x00 },
	{ 0,    0,   &anim049d, 0,   0,  0x00 },
	{ 0,    0,   &anim049e, 0,   0,  0x00 },
	{ 0,    0,   &anim049f, 0,   0,  0x00 },
	{ 0,    0,   &anim04a0, 0,   0,  0x00 },
	{ 0,    0,   &anim04a1, 0,   0,  0x00 },
	{ 0,    0,   &anim04a2, 0,   0,  0x00 },
	{ 0,    0,   &anim04a3, 0,   0,  0x00 },
	{ 0,    0,   &anim04a4, 0,   0,  0x00 },
	{ 0,    0,   &anim04a5, 0,   0,  0x00 },
	{ 0,    0,   &anim04a6, 0,   0,  0x00 },
	{ 0,    0,   &anim04a7, 0,   0,  0x00 },
	{ 0,    0,   &anim04a8, 0,   0,  0x00 },
	{ 0,    0,   &anim04a9, 0,   0,  0x00 },
	{ 0,    0,   &anim04aa, 0,   0,  0x00 },
	{ 0,    0,   &anim04ab, 0,   0,  0x00 },
	{ 0,    0,   &anim04ac, 0,   0,  0x00 },
	{ 0,    0,   &anim04ad, 0,   0,  0x00 },
	{ 0,    0,   &anim04ae, 0,   0,  0x00 },
	{ 0,    0,   &anim04af, 0,   0,  0x00 },
	{ 0,    0,   &anim04b0, 0,   0,  0x00 },
	{ 0,    0,   &anim04b1, 0,   0,  0x00 },
	{ 0,    0,   &anim04b2, 0,   0,  0x00 },
	{ 0,    0,   &anim04b3, 0,   0,  0x00 },
	{ 0,    0,   &anim04b4, 0,   0,  0x00 },
	{ 0,    0,   &anim04b5, 0,   0,  0x00 },
	{ 0,    0,   &anim04b6, 0,   0,  0x00 },
};
