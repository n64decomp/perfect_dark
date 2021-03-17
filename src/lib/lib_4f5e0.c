#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "lib/lib_4f5e0.h"
#include "lib/lib_51d50.h"
#include "data.h"
#include "types.h"

u32 var8009c970;
u32 var8009c974;
u32 var8009c978;
u32 var8009c97c;
u32 var8009c980;
u32 var8009c984;
u32 var8009c988;
u32 var8009c98c;
u32 var8009c990;
u32 var8009c994;
u32 var8009c998;
u32 var8009c99c;
u32 var8009c9a0;
u32 var8009c9a4;
u32 var8009c9a8;
u32 var8009c9ac;
u32 var8009c9b0;
u32 var8009c9b4;
u32 var8009c9b8;
u32 var8009c9bc;
u32 var8009c9c0;
u32 var8009c9c4;
u32 var8009c9c8;
u32 var8009c9cc;
u32 var8009c9d0;
u32 var8009c9d4;
u32 var8009c9d8;
u32 var8009c9dc;
u32 var8009c9e0;
u32 var8009c9e4;
u32 var8009c9e8;
u32 var8009c9ec;
u32 var8009c9f0;
u32 var8009c9f4;
u32 var8009c9f8;
u32 var8009c9fc;
u32 var8009ca00;
u32 var8009ca04;
u32 var8009ca08;
u32 var8009ca0c;
u32 var8009ca10;
u32 var8009ca14;
u32 var8009ca18;
u32 var8009ca1c;
u32 var8009ca20;
u32 var8009ca24;
u32 var8009ca28;
u32 var8009ca2c;
u32 var8009ca30;
u32 var8009ca34;
u32 var8009ca38;
u32 var8009ca3c;
u32 var8009ca40;
u32 var8009ca44;
u32 var8009ca48;
u32 var8009ca4c;
u32 var8009ca50;
u32 var8009ca54;
u32 var8009ca58;
u32 var8009ca5c;
u32 var8009ca60;
u32 var8009ca64;
u32 var8009ca68;
u32 var8009ca6c;
u32 var8009ca70;
u32 var8009ca74;
u32 var8009ca78;
u32 var8009ca7c;

u32 var800609f0 = 0x00000032;
u32 var800609f4 = 0x00640096;
u32 var800609f8 = 0x00c900fb;
u32 var800609fc = 0x012d0160;
u32 var80060a00 = 0x019201c4;
u32 var80060a04 = 0x01f70229;
u32 var80060a08 = 0x025b028e;
u32 var80060a0c = 0x02c002f2;
u32 var80060a10 = 0x03240357;
u32 var80060a14 = 0x038903bb;
u32 var80060a18 = 0x03ee0420;
u32 var80060a1c = 0x04520484;
u32 var80060a20 = 0x04b704e9;
u32 var80060a24 = 0x051b054e;
u32 var80060a28 = 0x058005b2;
u32 var80060a2c = 0x05e40617;
u32 var80060a30 = 0x0649067b;
u32 var80060a34 = 0x06ad06e0;
u32 var80060a38 = 0x07120744;
u32 var80060a3c = 0x077607a9;
u32 var80060a40 = 0x07db080d;
u32 var80060a44 = 0x083f0871;
u32 var80060a48 = 0x08a408d6;
u32 var80060a4c = 0x0908093a;
u32 var80060a50 = 0x096c099f;
u32 var80060a54 = 0x09d10a03;
u32 var80060a58 = 0x0a350a67;
u32 var80060a5c = 0x0a990acb;
u32 var80060a60 = 0x0afe0b30;
u32 var80060a64 = 0x0b620b94;
u32 var80060a68 = 0x0bc60bf8;
u32 var80060a6c = 0x0c2a0c5c;
u32 var80060a70 = 0x0c8e0cc0;
u32 var80060a74 = 0x0cf20d25;
u32 var80060a78 = 0x0d570d89;
u32 var80060a7c = 0x0dbb0ded;
u32 var80060a80 = 0x0e1f0e51;
u32 var80060a84 = 0x0e830eb5;
u32 var80060a88 = 0x0ee70f19;
u32 var80060a8c = 0x0f4b0f7c;
u32 var80060a90 = 0x0fae0fe0;
u32 var80060a94 = 0x10121044;
u32 var80060a98 = 0x107610a8;
u32 var80060a9c = 0x10da110c;
u32 var80060aa0 = 0x113e116f;
u32 var80060aa4 = 0x11a111d3;
u32 var80060aa8 = 0x12051237;
u32 var80060aac = 0x1269129a;
u32 var80060ab0 = 0x12cc12fe;
u32 var80060ab4 = 0x13301361;
u32 var80060ab8 = 0x139313c5;
u32 var80060abc = 0x13f61428;
u32 var80060ac0 = 0x145a148c;
u32 var80060ac4 = 0x14bd14ef;
u32 var80060ac8 = 0x15201552;
u32 var80060acc = 0x158415b5;
u32 var80060ad0 = 0x15e71618;
u32 var80060ad4 = 0x164a167b;
u32 var80060ad8 = 0x16ad16df;
u32 var80060adc = 0x17101741;
u32 var80060ae0 = 0x177317a4;
u32 var80060ae4 = 0x17d61807;
u32 var80060ae8 = 0x1839186a;
u32 var80060aec = 0x189b18cd;
u32 var80060af0 = 0x18fe1930;
u32 var80060af4 = 0x19611992;
u32 var80060af8 = 0x19c319f5;
u32 var80060afc = 0x1a261a57;
u32 var80060b00 = 0x1a881aba;
u32 var80060b04 = 0x1aeb1b1c;
u32 var80060b08 = 0x1b4d1b7e;
u32 var80060b0c = 0x1baf1be1;
u32 var80060b10 = 0x1c121c43;
u32 var80060b14 = 0x1c741ca5;
u32 var80060b18 = 0x1cd61d07;
u32 var80060b1c = 0x1d381d69;
u32 var80060b20 = 0x1d9a1dcb;
u32 var80060b24 = 0x1dfc1e2d;
u32 var80060b28 = 0x1e5d1e8e;
u32 var80060b2c = 0x1ebf1ef0;
u32 var80060b30 = 0x1f211f52;
u32 var80060b34 = 0x1f821fb3;
u32 var80060b38 = 0x1fe42015;
u32 var80060b3c = 0x20452076;
u32 var80060b40 = 0x20a720d7;
u32 var80060b44 = 0x21082139;
u32 var80060b48 = 0x2169219a;
u32 var80060b4c = 0x21ca21fb;
u32 var80060b50 = 0x222b225c;
u32 var80060b54 = 0x228c22bd;
u32 var80060b58 = 0x22ed231d;
u32 var80060b5c = 0x234e237e;
u32 var80060b60 = 0x23ae23df;
u32 var80060b64 = 0x240f243f;
u32 var80060b68 = 0x247024a0;
u32 var80060b6c = 0x24d02500;
u32 var80060b70 = 0x25302560;
u32 var80060b74 = 0x259125c1;
u32 var80060b78 = 0x25f12621;
u32 var80060b7c = 0x26512681;
u32 var80060b80 = 0x26b126e1;
u32 var80060b84 = 0x27112740;
u32 var80060b88 = 0x277027a0;
u32 var80060b8c = 0x27d02800;
u32 var80060b90 = 0x2830285f;
u32 var80060b94 = 0x288f28bf;
u32 var80060b98 = 0x28ee291e;
u32 var80060b9c = 0x294e297d;
u32 var80060ba0 = 0x29ad29dd;
u32 var80060ba4 = 0x2a0c2a3c;
u32 var80060ba8 = 0x2a6b2a9b;
u32 var80060bac = 0x2aca2af9;
u32 var80060bb0 = 0x2b292b58;
u32 var80060bb4 = 0x2b872bb7;
u32 var80060bb8 = 0x2be62c15;
u32 var80060bbc = 0x2c442c74;
u32 var80060bc0 = 0x2ca32cd2;
u32 var80060bc4 = 0x2d012d30;
u32 var80060bc8 = 0x2d5f2d8e;
u32 var80060bcc = 0x2dbd2dec;
u32 var80060bd0 = 0x2e1b2e4a;
u32 var80060bd4 = 0x2e792ea8;
u32 var80060bd8 = 0x2ed72f06;
u32 var80060bdc = 0x2f342f63;
u32 var80060be0 = 0x2f922fc0;
u32 var80060be4 = 0x2fef301e;
u32 var80060be8 = 0x304c307b;
u32 var80060bec = 0x30a930d8;
u32 var80060bf0 = 0x31073135;
u32 var80060bf4 = 0x31633192;
u32 var80060bf8 = 0x31c031ef;
u32 var80060bfc = 0x321d324b;
u32 var80060c00 = 0x327932a8;
u32 var80060c04 = 0x32d63304;
u32 var80060c08 = 0x33323360;
u32 var80060c0c = 0x338e33bc;
u32 var80060c10 = 0x33ea3418;
u32 var80060c14 = 0x34463474;
u32 var80060c18 = 0x34a234d0;
u32 var80060c1c = 0x34fe352b;
u32 var80060c20 = 0x35593587;
u32 var80060c24 = 0x35b535e2;
u32 var80060c28 = 0x3610363d;
u32 var80060c2c = 0x366b3698;
u32 var80060c30 = 0x36c636f3;
u32 var80060c34 = 0x3721374e;
u32 var80060c38 = 0x377c37a9;
u32 var80060c3c = 0x37d63803;
u32 var80060c40 = 0x3831385e;
u32 var80060c44 = 0x388b38b8;
u32 var80060c48 = 0x38e53912;
u32 var80060c4c = 0x393f396c;
u32 var80060c50 = 0x399939c6;
u32 var80060c54 = 0x39f33a20;
u32 var80060c58 = 0x3a4d3a79;
u32 var80060c5c = 0x3aa63ad3;
u32 var80060c60 = 0x3b003b2c;
u32 var80060c64 = 0x3b593b85;
u32 var80060c68 = 0x3bb23bde;
u32 var80060c6c = 0x3c0b3c37;
u32 var80060c70 = 0x3c643c90;
u32 var80060c74 = 0x3cbc3ce9;
u32 var80060c78 = 0x3d153d41;
u32 var80060c7c = 0x3d6d3d99;
u32 var80060c80 = 0x3dc53df1;
u32 var80060c84 = 0x3e1d3e49;
u32 var80060c88 = 0x3e753ea1;
u32 var80060c8c = 0x3ecd3ef9;
u32 var80060c90 = 0x3f253f50;
u32 var80060c94 = 0x3f7c3fa8;
u32 var80060c98 = 0x3fd33fff;
u32 var80060c9c = 0x402b4056;
u32 var80060ca0 = 0x408240ad;
u32 var80060ca4 = 0x40d84104;
u32 var80060ca8 = 0x412f415a;
u32 var80060cac = 0x418641b1;
u32 var80060cb0 = 0x41dc4207;
u32 var80060cb4 = 0x4232425d;
u32 var80060cb8 = 0x428842b3;
u32 var80060cbc = 0x42de4309;
u32 var80060cc0 = 0x4334435f;
u32 var80060cc4 = 0x438943b4;
u32 var80060cc8 = 0x43df4409;
u32 var80060ccc = 0x4434445f;
u32 var80060cd0 = 0x448944b4;
u32 var80060cd4 = 0x44de4508;
u32 var80060cd8 = 0x4533455d;
u32 var80060cdc = 0x458745b1;
u32 var80060ce0 = 0x45dc4606;
u32 var80060ce4 = 0x4630465a;
u32 var80060ce8 = 0x468446ae;
u32 var80060cec = 0x46d84702;
u32 var80060cf0 = 0x472c4755;
u32 var80060cf4 = 0x477f47a9;
u32 var80060cf8 = 0x47d247fc;
u32 var80060cfc = 0x4826484f;
u32 var80060d00 = 0x487948a2;
u32 var80060d04 = 0x48cc48f5;
u32 var80060d08 = 0x491e4948;
u32 var80060d0c = 0x4971499a;
u32 var80060d10 = 0x49c349ec;
u32 var80060d14 = 0x4a154a3e;
u32 var80060d18 = 0x4a674a90;
u32 var80060d1c = 0x4ab94ae2;
u32 var80060d20 = 0x4b0b4b33;
u32 var80060d24 = 0x4b5c4b85;
u32 var80060d28 = 0x4bad4bd6;
u32 var80060d2c = 0x4bfe4c27;
u32 var80060d30 = 0x4c4f4c78;
u32 var80060d34 = 0x4ca04cc8;
u32 var80060d38 = 0x4cf04d19;
u32 var80060d3c = 0x4d414d69;
u32 var80060d40 = 0x4d914db9;
u32 var80060d44 = 0x4de14e09;
u32 var80060d48 = 0x4e314e58;
u32 var80060d4c = 0x4e804ea8;
u32 var80060d50 = 0x4ed04ef7;
u32 var80060d54 = 0x4f1f4f46;
u32 var80060d58 = 0x4f6e4f95;
u32 var80060d5c = 0x4fbd4fe4;
u32 var80060d60 = 0x500b5032;
u32 var80060d64 = 0x505a5081;
u32 var80060d68 = 0x50a850cf;
u32 var80060d6c = 0x50f6511d;
u32 var80060d70 = 0x5144516b;
u32 var80060d74 = 0x519151b8;
u32 var80060d78 = 0x51df5205;
u32 var80060d7c = 0x522c5253;
u32 var80060d80 = 0x527952a0;
u32 var80060d84 = 0x52c652ec;
u32 var80060d88 = 0x53135339;
u32 var80060d8c = 0x535f5385;
u32 var80060d90 = 0x53ab53d1;
u32 var80060d94 = 0x53f7541d;
u32 var80060d98 = 0x54435469;
u32 var80060d9c = 0x548f54b5;
u32 var80060da0 = 0x54da5500;
u32 var80060da4 = 0x5525554b;
u32 var80060da8 = 0x55715596;
u32 var80060dac = 0x55bb55e1;
u32 var80060db0 = 0x5606562b;
u32 var80060db4 = 0x56505675;
u32 var80060db8 = 0x569b56c0;
u32 var80060dbc = 0x56e55709;
u32 var80060dc0 = 0x572e5753;
u32 var80060dc4 = 0x5778579d;
u32 var80060dc8 = 0x57c157e6;
u32 var80060dcc = 0x580a582f;
u32 var80060dd0 = 0x58535878;
u32 var80060dd4 = 0x589c58c0;
u32 var80060dd8 = 0x58e55909;
u32 var80060ddc = 0x592d5951;
u32 var80060de0 = 0x59755999;
u32 var80060de4 = 0x59bd59e1;
u32 var80060de8 = 0x5a045a28;
u32 var80060dec = 0x5a4c5a6f;
u32 var80060df0 = 0x5a935ab7;
u32 var80060df4 = 0x5ada5afd;
u32 var80060df8 = 0x5b215b44;
u32 var80060dfc = 0x5b675b8b;
u32 var80060e00 = 0x5bae5bd1;
u32 var80060e04 = 0x5bf45c17;
u32 var80060e08 = 0x5c3a5c5d;
u32 var80060e0c = 0x5c7f5ca2;
u32 var80060e10 = 0x5cc55ce7;
u32 var80060e14 = 0x5d0a5d2d;
u32 var80060e18 = 0x5d4f5d71;
u32 var80060e1c = 0x5d945db6;
u32 var80060e20 = 0x5dd85dfa;
u32 var80060e24 = 0x5e1d5e3f;
u32 var80060e28 = 0x5e615e83;
u32 var80060e2c = 0x5ea55ec6;
u32 var80060e30 = 0x5ee85f0a;
u32 var80060e34 = 0x5f2c5f4d;
u32 var80060e38 = 0x5f6f5f90;
u32 var80060e3c = 0x5fb25fd3;
u32 var80060e40 = 0x5ff46016;
u32 var80060e44 = 0x60376058;
u32 var80060e48 = 0x6079609a;
u32 var80060e4c = 0x60bb60dc;
u32 var80060e50 = 0x60fd611e;
u32 var80060e54 = 0x613e615f;
u32 var80060e58 = 0x618061a0;
u32 var80060e5c = 0x61c161e1;
u32 var80060e60 = 0x62026222;
u32 var80060e64 = 0x62426263;
u32 var80060e68 = 0x628362a3;
u32 var80060e6c = 0x62c362e3;
u32 var80060e70 = 0x63036323;
u32 var80060e74 = 0x63426362;
u32 var80060e78 = 0x638263a1;
u32 var80060e7c = 0x63c163e0;
u32 var80060e80 = 0x6400641f;
u32 var80060e84 = 0x643f645e;
u32 var80060e88 = 0x647d649c;
u32 var80060e8c = 0x64bb64da;
u32 var80060e90 = 0x64f96518;
u32 var80060e94 = 0x65376556;
u32 var80060e98 = 0x65746593;
u32 var80060e9c = 0x65b265d0;
u32 var80060ea0 = 0x65ef660d;
u32 var80060ea4 = 0x662b664a;
u32 var80060ea8 = 0x66686686;
u32 var80060eac = 0x66a466c2;
u32 var80060eb0 = 0x66e066fe;
u32 var80060eb4 = 0x671c673a;
u32 var80060eb8 = 0x67576775;
u32 var80060ebc = 0x679267b0;
u32 var80060ec0 = 0x67cd67eb;
u32 var80060ec4 = 0x68086825;
u32 var80060ec8 = 0x68436860;
u32 var80060ecc = 0x687d689a;
u32 var80060ed0 = 0x68b768d4;
u32 var80060ed4 = 0x68f1690d;
u32 var80060ed8 = 0x692a6947;
u32 var80060edc = 0x69636980;
u32 var80060ee0 = 0x699c69b9;
u32 var80060ee4 = 0x69d569f1;
u32 var80060ee8 = 0x6a0e6a2a;
u32 var80060eec = 0x6a466a62;
u32 var80060ef0 = 0x6a7e6a9a;
u32 var80060ef4 = 0x6ab56ad1;
u32 var80060ef8 = 0x6aed6b08;
u32 var80060efc = 0x6b246b40;
u32 var80060f00 = 0x6b5b6b76;
u32 var80060f04 = 0x6b926bad;
u32 var80060f08 = 0x6bc86be3;
u32 var80060f0c = 0x6bfe6c19;
u32 var80060f10 = 0x6c346c4f;
u32 var80060f14 = 0x6c6a6c84;
u32 var80060f18 = 0x6c9f6cba;
u32 var80060f1c = 0x6cd46cef;
u32 var80060f20 = 0x6d096d23;
u32 var80060f24 = 0x6d3e6d58;
u32 var80060f28 = 0x6d726d8c;
u32 var80060f2c = 0x6da66dc0;
u32 var80060f30 = 0x6dda6df3;
u32 var80060f34 = 0x6e0d6e27;
u32 var80060f38 = 0x6e406e5a;
u32 var80060f3c = 0x6e736e8d;
u32 var80060f40 = 0x6ea66ebf;
u32 var80060f44 = 0x6ed96ef2;
u32 var80060f48 = 0x6f0b6f24;
u32 var80060f4c = 0x6f3d6f55;
u32 var80060f50 = 0x6f6e6f87;
u32 var80060f54 = 0x6fa06fb8;
u32 var80060f58 = 0x6fd16fe9;
u32 var80060f5c = 0x7002701a;
u32 var80060f60 = 0x7032704a;
u32 var80060f64 = 0x7062707a;
u32 var80060f68 = 0x709270aa;
u32 var80060f6c = 0x70c270da;
u32 var80060f70 = 0x70f27109;
u32 var80060f74 = 0x71217138;
u32 var80060f78 = 0x71507167;
u32 var80060f7c = 0x717e7196;
u32 var80060f80 = 0x71ad71c4;
u32 var80060f84 = 0x71db71f2;
u32 var80060f88 = 0x72097220;
u32 var80060f8c = 0x7236724d;
u32 var80060f90 = 0x7264727a;
u32 var80060f94 = 0x729172a7;
u32 var80060f98 = 0x72bd72d4;
u32 var80060f9c = 0x72ea7300;
u32 var80060fa0 = 0x7316732c;
u32 var80060fa4 = 0x73427358;
u32 var80060fa8 = 0x736e7383;
u32 var80060fac = 0x739973ae;
u32 var80060fb0 = 0x73c473d9;
u32 var80060fb4 = 0x73ef7404;
u32 var80060fb8 = 0x7419742e;
u32 var80060fbc = 0x74437458;
u32 var80060fc0 = 0x746d7482;
u32 var80060fc4 = 0x749774ac;
u32 var80060fc8 = 0x74c074d5;
u32 var80060fcc = 0x74ea74fe;
u32 var80060fd0 = 0x75127527;
u32 var80060fd4 = 0x753b754f;
u32 var80060fd8 = 0x75637577;
u32 var80060fdc = 0x758b759f;
u32 var80060fe0 = 0x75b375c7;
u32 var80060fe4 = 0x75da75ee;
u32 var80060fe8 = 0x76017615;
u32 var80060fec = 0x7628763b;
u32 var80060ff0 = 0x764f7662;
u32 var80060ff4 = 0x76757688;
u32 var80060ff8 = 0x769b76ae;
u32 var80060ffc = 0x76c176d3;
u32 var80061000 = 0x76e676f9;
u32 var80061004 = 0x770b771e;
u32 var80061008 = 0x77307742;
u32 var8006100c = 0x77547767;
u32 var80061010 = 0x7779778b;
u32 var80061014 = 0x779d77af;
u32 var80061018 = 0x77c077d2;
u32 var8006101c = 0x77e477f5;
u32 var80061020 = 0x78077818;
u32 var80061024 = 0x782a783b;
u32 var80061028 = 0x784c785d;
u32 var8006102c = 0x786e787f;
u32 var80061030 = 0x789078a1;
u32 var80061034 = 0x78b278c3;
u32 var80061038 = 0x78d378e4;
u32 var8006103c = 0x78f47905;
u32 var80061040 = 0x79157925;
u32 var80061044 = 0x79367946;
u32 var80061048 = 0x79567966;
u32 var8006104c = 0x79767985;
u32 var80061050 = 0x799579a5;
u32 var80061054 = 0x79b579c4;
u32 var80061058 = 0x79d479e3;
u32 var8006105c = 0x79f27a02;
u32 var80061060 = 0x7a117a20;
u32 var80061064 = 0x7a2f7a3e;
u32 var80061068 = 0x7a4d7a5b;
u32 var8006106c = 0x7a6a7a79;
u32 var80061070 = 0x7a877a96;
u32 var80061074 = 0x7aa47ab3;
u32 var80061078 = 0x7ac17acf;
u32 var8006107c = 0x7add7aeb;
u32 var80061080 = 0x7af97b07;
u32 var80061084 = 0x7b157b23;
u32 var80061088 = 0x7b317b3e;
u32 var8006108c = 0x7b4c7b59;
u32 var80061090 = 0x7b677b74;
u32 var80061094 = 0x7b817b8e;
u32 var80061098 = 0x7b9b7ba8;
u32 var8006109c = 0x7bb57bc2;
u32 var800610a0 = 0x7bcf7bdc;
u32 var800610a4 = 0x7be87bf5;
u32 var800610a8 = 0x7c027c0e;
u32 var800610ac = 0x7c1a7c27;
u32 var800610b0 = 0x7c337c3f;
u32 var800610b4 = 0x7c4b7c57;
u32 var800610b8 = 0x7c637c6f;
u32 var800610bc = 0x7c7a7c86;
u32 var800610c0 = 0x7c927c9d;
u32 var800610c4 = 0x7ca97cb4;
u32 var800610c8 = 0x7cbf7ccb;
u32 var800610cc = 0x7cd67ce1;
u32 var800610d0 = 0x7cec7cf7;
u32 var800610d4 = 0x7d027d0c;
u32 var800610d8 = 0x7d177d22;
u32 var800610dc = 0x7d2c7d37;
u32 var800610e0 = 0x7d417d4b;
u32 var800610e4 = 0x7d567d60;
u32 var800610e8 = 0x7d6a7d74;
u32 var800610ec = 0x7d7e7d88;
u32 var800610f0 = 0x7d917d9b;
u32 var800610f4 = 0x7da57dae;
u32 var800610f8 = 0x7db87dc1;
u32 var800610fc = 0x7dcb7dd4;
u32 var80061100 = 0x7ddd7de6;
u32 var80061104 = 0x7def7df8;
u32 var80061108 = 0x7e017e0a;
u32 var8006110c = 0x7e137e1b;
u32 var80061110 = 0x7e247e2c;
u32 var80061114 = 0x7e357e3d;
u32 var80061118 = 0x7e457e4d;
u32 var8006111c = 0x7e567e5e;
u32 var80061120 = 0x7e667e6d;
u32 var80061124 = 0x7e757e7d;
u32 var80061128 = 0x7e857e8c;
u32 var8006112c = 0x7e947e9b;
u32 var80061130 = 0x7ea37eaa;
u32 var80061134 = 0x7eb17eb8;
u32 var80061138 = 0x7ebf7ec6;
u32 var8006113c = 0x7ecd7ed4;
u32 var80061140 = 0x7edb7ee1;
u32 var80061144 = 0x7ee87eee;
u32 var80061148 = 0x7ef57efb;
u32 var8006114c = 0x7f017f08;
u32 var80061150 = 0x7f0e7f14;
u32 var80061154 = 0x7f1a7f20;
u32 var80061158 = 0x7f257f2b;
u32 var8006115c = 0x7f317f36;
u32 var80061160 = 0x7f3c7f41;
u32 var80061164 = 0x7f477f4c;
u32 var80061168 = 0x7f517f56;
u32 var8006116c = 0x7f5b7f60;
u32 var80061170 = 0x7f657f6a;
u32 var80061174 = 0x7f6f7f74;
u32 var80061178 = 0x7f787f7d;
u32 var8006117c = 0x7f817f85;
u32 var80061180 = 0x7f8a7f8e;
u32 var80061184 = 0x7f927f96;
u32 var80061188 = 0x7f9a7f9e;
u32 var8006118c = 0x7fa27fa6;
u32 var80061190 = 0x7fa97fad;
u32 var80061194 = 0x7fb07fb4;
u32 var80061198 = 0x7fb77fba;
u32 var8006119c = 0x7fbe7fc1;
u32 var800611a0 = 0x7fc47fc7;
u32 var800611a4 = 0x7fca7fcc;
u32 var800611a8 = 0x7fcf7fd2;
u32 var800611ac = 0x7fd47fd7;
u32 var800611b0 = 0x7fd97fdc;
u32 var800611b4 = 0x7fde7fe0;
u32 var800611b8 = 0x7fe27fe4;
u32 var800611bc = 0x7fe67fe8;
u32 var800611c0 = 0x7fea7fec;
u32 var800611c4 = 0x7fed7fef;
u32 var800611c8 = 0x7ff17ff2;
u32 var800611cc = 0x7ff37ff5;
u32 var800611d0 = 0x7ff67ff7;
u32 var800611d4 = 0x7ff87ff9;
u32 var800611d8 = 0x7ffa7ffb;
u32 var800611dc = 0x7ffb7ffc;
u32 var800611e0 = 0x7ffd7ffd;
u32 var800611e4 = 0x7ffe7ffe;
u32 var800611e8 = 0x7ffe7ffe;
u32 var800611ec = 0x7ffe7fff;

const u32 var70059fd0[] = {0x3c8efa35};

GLOBAL_ASM(
glabel func0004f5e0
/*    4f5e0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4f5e4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f5e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f5ec:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*    4f5f0:	8c990000 */ 	lw	$t9,0x0($a0)
/*    4f5f4:	3c18800a */ 	lui	$t8,%hi(var8009c970)
/*    4f5f8:	2718c970 */ 	addiu	$t8,$t8,%lo(var8009c970)
/*    4f5fc:	000e7980 */ 	sll	$t7,$t6,0x6
/*    4f600:	33290008 */ 	andi	$t1,$t9,0x8
/*    4f604:	00808025 */ 	or	$s0,$a0,$zero
/*    4f608:	00a03825 */ 	or	$a3,$a1,$zero
/*    4f60c:	15200003 */ 	bnez	$t1,.L0004f61c
/*    4f610:	01f84021 */ 	addu	$t0,$t7,$t8
/*    4f614:	10000047 */ 	b	.L0004f734
/*    4f618:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004f61c:
/*    4f61c:	afa70034 */ 	sw	$a3,0x34($sp)
/*    4f620:	0c012a18 */ 	jal	__osSiGetAccess
/*    4f624:	afa80024 */ 	sw	$t0,0x24($sp)
/*    4f628:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*    4f62c:	3c06800a */ 	lui	$a2,%hi(var8009c970)
/*    4f630:	24c6c970 */ 	addiu	$a2,$a2,%lo(var8009c970)
/*    4f634:	000b6180 */ 	sll	$t4,$t3,0x6
/*    4f638:	00cc6821 */ 	addu	$t5,$a2,$t4
/*    4f63c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4f640:	adaa003c */ 	sw	$t2,0x3c($t5)
/*    4f644:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    4f648:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*    4f64c:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    4f650:	00001825 */ 	or	$v1,$zero,$zero
/*    4f654:	010e4021 */ 	addu	$t0,$t0,$t6
/*    4f658:	01001025 */ 	or	$v0,$t0,$zero
/*    4f65c:	24040020 */ 	addiu	$a0,$zero,0x20
.L0004f660:
/*    4f660:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4f664:	a0470007 */ 	sb	$a3,0x7($v0)
/*    4f668:	a0470008 */ 	sb	$a3,0x8($v0)
/*    4f66c:	a0470009 */ 	sb	$a3,0x9($v0)
/*    4f670:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4f674:	1464fffa */ 	bne	$v1,$a0,.L0004f660
/*    4f678:	a0470002 */ 	sb	$a3,0x2($v0)
/*    4f67c:	240f00fe */ 	addiu	$t7,$zero,0xfe
/*    4f680:	3c01800a */ 	lui	$at,%hi(__osContLastCmd)
/*    4f684:	a02fc820 */ 	sb	$t7,%lo(__osContLastCmd)($at)
/*    4f688:	8e180008 */ 	lw	$t8,0x8($s0)
/*    4f68c:	afa80024 */ 	sw	$t0,0x24($sp)
/*    4f690:	afa70034 */ 	sw	$a3,0x34($sp)
/*    4f694:	0018c980 */ 	sll	$t9,$t8,0x6
/*    4f698:	00d92821 */ 	addu	$a1,$a2,$t9
/*    4f69c:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4f6a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4f6a4:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4f6a8:	00002825 */ 	or	$a1,$zero,$zero
/*    4f6ac:	0c0121bc */ 	jal	osRecvMesg
/*    4f6b0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4f6b4:	8e090008 */ 	lw	$t1,0x8($s0)
/*    4f6b8:	3c0c800a */ 	lui	$t4,%hi(var8009c970)
/*    4f6bc:	258cc970 */ 	addiu	$t4,$t4,%lo(var8009c970)
/*    4f6c0:	00095980 */ 	sll	$t3,$t1,0x6
/*    4f6c4:	016c2821 */ 	addu	$a1,$t3,$t4
/*    4f6c8:	0c012a34 */ 	jal	__osSiRawStartDma
/*    4f6cc:	00002025 */ 	or	$a0,$zero,$zero
/*    4f6d0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4f6d4:	00002825 */ 	or	$a1,$zero,$zero
/*    4f6d8:	0c0121bc */ 	jal	osRecvMesg
/*    4f6dc:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4f6e0:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    4f6e4:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    4f6e8:	91100002 */ 	lbu	$s0,0x2($t0)
/*    4f6ec:	320a00c0 */ 	andi	$t2,$s0,0xc0
/*    4f6f0:	1540000d */ 	bnez	$t2,.L0004f728
/*    4f6f4:	01408025 */ 	or	$s0,$t2,$zero
/*    4f6f8:	54e00007 */ 	bnezl	$a3,.L0004f718
/*    4f6fc:	910e0026 */ 	lbu	$t6,0x26($t0)
/*    4f700:	910d0026 */ 	lbu	$t5,0x26($t0)
/*    4f704:	11a00008 */ 	beqz	$t5,.L0004f728
/*    4f708:	00000000 */ 	nop
/*    4f70c:	10000006 */ 	b	.L0004f728
/*    4f710:	24100004 */ 	addiu	$s0,$zero,0x4
/*    4f714:	910e0026 */ 	lbu	$t6,0x26($t0)
.L0004f718:
/*    4f718:	240100eb */ 	addiu	$at,$zero,0xeb
/*    4f71c:	11c10002 */ 	beq	$t6,$at,.L0004f728
/*    4f720:	00000000 */ 	nop
/*    4f724:	24100004 */ 	addiu	$s0,$zero,0x4
.L0004f728:
/*    4f728:	0c012a29 */ 	jal	__osSiRelAccess
/*    4f72c:	00000000 */ 	nop
/*    4f730:	02001025 */ 	or	$v0,$s0,$zero
.L0004f734:
/*    4f734:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4f738:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4f73c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4f740:	03e00008 */ 	jr	$ra
/*    4f744:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004f748
/*    4f748:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*    4f74c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4f750:	00803025 */ 	or	$a2,$a0,$zero
/*    4f754:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    4f758:	240f0023 */ 	addiu	$t7,$zero,0x23
/*    4f75c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4f760:	24190003 */ 	addiu	$t9,$zero,0x3
/*    4f764:	240800c0 */ 	addiu	$t0,$zero,0xc0
/*    4f768:	a3ae0024 */ 	sb	$t6,0x24($sp)
/*    4f76c:	a3af0025 */ 	sb	$t7,0x25($sp)
/*    4f770:	a3b80026 */ 	sb	$t8,0x26($sp)
/*    4f774:	a3b90027 */ 	sb	$t9,0x27($sp)
/*    4f778:	a3a80028 */ 	sb	$t0,0x28($sp)
/*    4f77c:	afa60050 */ 	sw	$a2,0x50($sp)
/*    4f780:	24040600 */ 	addiu	$a0,$zero,0x600
/*    4f784:	0c014754 */ 	jal	__osContAddressCrc
/*    4f788:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    4f78c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*    4f790:	3449c000 */ 	ori	$t1,$v0,0xc000
/*    4f794:	a3a90029 */ 	sb	$t1,0x29($sp)
/*    4f798:	10c00012 */ 	beqz	$a2,.L0004f7e4
/*    4f79c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*    4f7a0:	18c00010 */ 	blez	$a2,.L0004f7e4
/*    4f7a4:	00001025 */ 	or	$v0,$zero,$zero
/*    4f7a8:	30c50003 */ 	andi	$a1,$a2,0x3
/*    4f7ac:	10a00006 */ 	beqz	$a1,.L0004f7c8
/*    4f7b0:	00a02025 */ 	or	$a0,$a1,$zero
.L0004f7b4:
/*    4f7b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4f7b8:	a0600000 */ 	sb	$zero,0x0($v1)
/*    4f7bc:	1482fffd */ 	bne	$a0,$v0,.L0004f7b4
/*    4f7c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4f7c4:	10460007 */ 	beq	$v0,$a2,.L0004f7e4
.L0004f7c8:
/*    4f7c8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4f7cc:	a0600001 */ 	sb	$zero,0x1($v1)
/*    4f7d0:	a0600002 */ 	sb	$zero,0x2($v1)
/*    4f7d4:	a0600003 */ 	sb	$zero,0x3($v1)
/*    4f7d8:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4f7dc:	1446fffa */ 	bne	$v0,$a2,.L0004f7c8
/*    4f7e0:	a060fffc */ 	sb	$zero,-0x4($v1)
.L0004f7e4:
/*    4f7e4:	27aa0024 */ 	addiu	$t2,$sp,0x24
/*    4f7e8:	254c0024 */ 	addiu	$t4,$t2,0x24
/*    4f7ec:	00606825 */ 	or	$t5,$v1,$zero
.L0004f7f0:
/*    4f7f0:	8d410000 */ 	lw	$at,0x0($t2)
/*    4f7f4:	254a000c */ 	addiu	$t2,$t2,0xc
/*    4f7f8:	25ad000c */ 	addiu	$t5,$t5,0xc
/*    4f7fc:	a9a1fff4 */ 	swl	$at,-0xc($t5)
/*    4f800:	b9a1fff7 */ 	swr	$at,-0x9($t5)
/*    4f804:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*    4f808:	a9a1fff8 */ 	swl	$at,-0x8($t5)
/*    4f80c:	b9a1fffb */ 	swr	$at,-0x5($t5)
/*    4f810:	8d41fffc */ 	lw	$at,-0x4($t2)
/*    4f814:	a9a1fffc */ 	swl	$at,-0x4($t5)
/*    4f818:	154cfff5 */ 	bne	$t2,$t4,.L0004f7f0
/*    4f81c:	b9a1ffff */ 	swr	$at,-0x1($t5)
/*    4f820:	91410000 */ 	lbu	$at,0x0($t2)
/*    4f824:	240e00fe */ 	addiu	$t6,$zero,0xfe
/*    4f828:	24630027 */ 	addiu	$v1,$v1,0x27
/*    4f82c:	a1a10000 */ 	sb	$at,0x0($t5)
/*    4f830:	914c0001 */ 	lbu	$t4,0x1($t2)
/*    4f834:	a1ac0001 */ 	sb	$t4,0x1($t5)
/*    4f838:	91410002 */ 	lbu	$at,0x2($t2)
/*    4f83c:	a1a10002 */ 	sb	$at,0x2($t5)
/*    4f840:	a06e0000 */ 	sb	$t6,0x0($v1)
/*    4f844:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4f848:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*    4f84c:	03e00008 */ 	jr	$ra
/*    4f850:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004f854
/*    4f854:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    4f858:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f85c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f860:	afa40048 */ 	sw	$a0,0x48($sp)
/*    4f864:	afa60050 */ 	sw	$a2,0x50($sp)
/*    4f868:	aca40004 */ 	sw	$a0,0x4($a1)
/*    4f86c:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    4f870:	241800ff */ 	addiu	$t8,$zero,0xff
/*    4f874:	00a08025 */ 	or	$s0,$a1,$zero
/*    4f878:	a0b80065 */ 	sb	$t8,0x65($a1)
/*    4f87c:	aca00000 */ 	sw	$zero,0x0($a1)
/*    4f880:	00a02025 */ 	or	$a0,$a1,$zero
/*    4f884:	acaf0008 */ 	sw	$t7,0x8($a1)
/*    4f888:	0c013378 */ 	jal	__osPfsSelectBank
/*    4f88c:	240500fe */ 	addiu	$a1,$zero,0xfe
/*    4f890:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f894:	14410005 */ 	bne	$v0,$at,.L0004f8ac
/*    4f898:	00401825 */ 	or	$v1,$v0,$zero
/*    4f89c:	02002025 */ 	or	$a0,$s0,$zero
/*    4f8a0:	0c013378 */ 	jal	__osPfsSelectBank
/*    4f8a4:	24050080 */ 	addiu	$a1,$zero,0x80
/*    4f8a8:	00401825 */ 	or	$v1,$v0,$zero
.L0004f8ac:
/*    4f8ac:	10400003 */ 	beqz	$v0,.L0004f8bc
/*    4f8b0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    4f8b4:	10000039 */ 	b	.L0004f99c
/*    4f8b8:	00601025 */ 	or	$v0,$v1,$zero
.L0004f8bc:
/*    4f8bc:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    4f8c0:	24060400 */ 	addiu	$a2,$zero,0x400
/*    4f8c4:	0c012e18 */ 	jal	__osContRamRead
/*    4f8c8:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    4f8cc:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f8d0:	14410002 */ 	bne	$v0,$at,.L0004f8dc
/*    4f8d4:	00401825 */ 	or	$v1,$v0,$zero
/*    4f8d8:	24030004 */ 	addiu	$v1,$zero,0x4
.L0004f8dc:
/*    4f8dc:	10600003 */ 	beqz	$v1,.L0004f8ec
/*    4f8e0:	93b90043 */ 	lbu	$t9,0x43($sp)
/*    4f8e4:	1000002d */ 	b	.L0004f99c
/*    4f8e8:	00601025 */ 	or	$v0,$v1,$zero
.L0004f8ec:
/*    4f8ec:	240100fe */ 	addiu	$at,$zero,0xfe
/*    4f8f0:	17210003 */ 	bne	$t9,$at,.L0004f900
/*    4f8f4:	02002025 */ 	or	$a0,$s0,$zero
/*    4f8f8:	10000028 */ 	b	.L0004f99c
/*    4f8fc:	2402000b */ 	addiu	$v0,$zero,0xb
.L0004f900:
/*    4f900:	0c013378 */ 	jal	__osPfsSelectBank
/*    4f904:	24050080 */ 	addiu	$a1,$zero,0x80
/*    4f908:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f90c:	14410002 */ 	bne	$v0,$at,.L0004f918
/*    4f910:	00401825 */ 	or	$v1,$v0,$zero
/*    4f914:	24030004 */ 	addiu	$v1,$zero,0x4
.L0004f918:
/*    4f918:	10600003 */ 	beqz	$v1,.L0004f928
/*    4f91c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    4f920:	1000001e */ 	b	.L0004f99c
/*    4f924:	00601025 */ 	or	$v0,$v1,$zero
.L0004f928:
/*    4f928:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    4f92c:	24060400 */ 	addiu	$a2,$zero,0x400
/*    4f930:	0c012e18 */ 	jal	__osContRamRead
/*    4f934:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    4f938:	24010002 */ 	addiu	$at,$zero,0x2
/*    4f93c:	14410002 */ 	bne	$v0,$at,.L0004f948
/*    4f940:	00401825 */ 	or	$v1,$v0,$zero
/*    4f944:	24030004 */ 	addiu	$v1,$zero,0x4
.L0004f948:
/*    4f948:	10600003 */ 	beqz	$v1,.L0004f958
/*    4f94c:	93a80043 */ 	lbu	$t0,0x43($sp)
/*    4f950:	10000012 */ 	b	.L0004f99c
/*    4f954:	00601025 */ 	or	$v0,$v1,$zero
.L0004f958:
/*    4f958:	24010080 */ 	addiu	$at,$zero,0x80
/*    4f95c:	51010004 */ 	beql	$t0,$at,.L0004f970
/*    4f960:	8e090000 */ 	lw	$t1,0x0($s0)
/*    4f964:	1000000d */ 	b	.L0004f99c
/*    4f968:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4f96c:	8e090000 */ 	lw	$t1,0x0($s0)
.L0004f970:
/*    4f970:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    4f974:	3c0d800a */ 	lui	$t5,%hi(var8009c970)
/*    4f978:	312a0008 */ 	andi	$t2,$t1,0x8
/*    4f97c:	15400004 */ 	bnez	$t2,.L0004f990
/*    4f980:	00046180 */ 	sll	$t4,$a0,0x6
/*    4f984:	25adc970 */ 	addiu	$t5,$t5,%lo(var8009c970)
/*    4f988:	0c013dd2 */ 	jal	func0004f748
/*    4f98c:	018d2821 */ 	addu	$a1,$t4,$t5
.L0004f990:
/*    4f990:	240e0008 */ 	addiu	$t6,$zero,0x8
/*    4f994:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*    4f998:	00001025 */ 	or	$v0,$zero,$zero
.L0004f99c:
/*    4f99c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4f9a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4f9a4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    4f9a8:	03e00008 */ 	jr	$ra
/*    4f9ac:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004f9b0
/*    4f9b0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4f9b4:	3c017006 */ 	lui	$at,%hi(var70059fd0)
/*    4f9b8:	c4249fd0 */ 	lwc1	$f4,%lo(var70059fd0)($at)
/*    4f9bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f9c0:	00808025 */ 	or	$s0,$a0,$zero
/*    4f9c4:	3c01800a */ 	lui	$at,%hi(var8009ca70)
/*    4f9c8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f9cc:	afa50034 */ 	sw	$a1,0x34($sp)
/*    4f9d0:	afa60038 */ 	sw	$a2,0x38($sp)
/*    4f9d4:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    4f9d8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*    4f9dc:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*    4f9e0:	27a40038 */ 	addiu	$a0,$sp,0x38
/*    4f9e4:	0c0011e4 */ 	jal	guNormalize
/*    4f9e8:	e424ca70 */ 	swc1	$f4,%lo(var8009ca70)($at)
/*    4f9ec:	3c01800a */ 	lui	$at,%hi(var8009ca70)
/*    4f9f0:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    4f9f4:	c426ca70 */ 	lwc1	$f6,%lo(var8009ca70)($at)
/*    4f9f8:	46066302 */ 	mul.s	$f12,$f12,$f6
/*    4f9fc:	0c0068f7 */ 	jal	sinf
/*    4fa00:	e7ac0034 */ 	swc1	$f12,0x34($sp)
/*    4fa04:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    4fa08:	0c0068f4 */ 	jal	cosf
/*    4fa0c:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*    4fa10:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*    4fa14:	c7b20040 */ 	lwc1	$f18,0x40($sp)
/*    4fa18:	e7a00028 */ 	swc1	$f0,0x28($sp)
/*    4fa1c:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*    4fa20:	00000000 */ 	nop
/*    4fa24:	46129282 */ 	mul.s	$f10,$f18,$f18
/*    4fa28:	0c012974 */ 	jal	sqrtf
/*    4fa2c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    4fa30:	02002025 */ 	or	$a0,$s0,$zero
/*    4fa34:	0c012918 */ 	jal	guMtxIdentF
/*    4fa38:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*    4fa3c:	44806000 */ 	mtc1	$zero,$f12
/*    4fa40:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*    4fa44:	c7a20028 */ 	lwc1	$f2,0x28($sp)
/*    4fa48:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*    4fa4c:	460c7032 */ 	c.eq.s	$f14,$f12
/*    4fa50:	3c013f80 */ 	lui	$at,0x3f80
/*    4fa54:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fa58:	45030041 */ 	bc1tl	.L0004fb60
/*    4fa5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4fa60:	44812000 */ 	mtc1	$at,$f4
/*    4fa64:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    4fa68:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*    4fa6c:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    4fa70:	460e2003 */ 	div.s	$f0,$f4,$f14
/*    4fa74:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    4fa78:	46003207 */ 	neg.s	$f8,$f6
/*    4fa7c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*    4fa80:	46045181 */ 	sub.s	$f6,$f10,$f4
/*    4fa84:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    4fa88:	e6080000 */ 	swc1	$f8,0x0($s0)
/*    4fa8c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*    4fa90:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    4fa94:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*    4fa98:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*    4fa9c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    4faa0:	00000000 */ 	nop
/*    4faa4:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    4faa8:	46082181 */ 	sub.s	$f6,$f4,$f8
/*    4faac:	46003282 */ 	mul.s	$f10,$f6,$f0
/*    4fab0:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*    4fab4:	460e8182 */ 	mul.s	$f6,$f16,$f14
/*    4fab8:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    4fabc:	e60c0030 */ 	swc1	$f12,0x30($s0)
/*    4fac0:	460e1282 */ 	mul.s	$f10,$f2,$f14
/*    4fac4:	46002207 */ 	neg.s	$f8,$f4
/*    4fac8:	e6080020 */ 	swc1	$f8,0x20($s0)
/*    4facc:	e6060004 */ 	swc1	$f6,0x4($s0)
/*    4fad0:	e60a0014 */ 	swc1	$f10,0x14($s0)
/*    4fad4:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    4fad8:	e60c0034 */ 	swc1	$f12,0x34($s0)
/*    4fadc:	46002207 */ 	neg.s	$f8,$f4
/*    4fae0:	e6080024 */ 	swc1	$f8,0x24($s0)
/*    4fae4:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fae8:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    4faec:	46068282 */ 	mul.s	$f10,$f16,$f6
/*    4faf0:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    4faf4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*    4faf8:	00000000 */ 	nop
/*    4fafc:	46061282 */ 	mul.s	$f10,$f2,$f6
/*    4fb00:	46085101 */ 	sub.s	$f4,$f10,$f8
/*    4fb04:	46008287 */ 	neg.s	$f10,$f16
/*    4fb08:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    4fb0c:	e6060008 */ 	swc1	$f6,0x8($s0)
/*    4fb10:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*    4fb14:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fb18:	46085102 */ 	mul.s	$f4,$f10,$f8
/*    4fb1c:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*    4fb20:	46061282 */ 	mul.s	$f10,$f2,$f6
/*    4fb24:	00000000 */ 	nop
/*    4fb28:	46085182 */ 	mul.s	$f6,$f10,$f8
/*    4fb2c:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    4fb30:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    4fb34:	44815000 */ 	mtc1	$at,$f10
/*    4fb38:	e6080018 */ 	swc1	$f8,0x18($s0)
/*    4fb3c:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    4fb40:	e60c0038 */ 	swc1	$f12,0x38($s0)
/*    4fb44:	e60c000c */ 	swc1	$f12,0xc($s0)
/*    4fb48:	46002187 */ 	neg.s	$f6,$f4
/*    4fb4c:	e60c001c */ 	swc1	$f12,0x1c($s0)
/*    4fb50:	e6060028 */ 	swc1	$f6,0x28($s0)
/*    4fb54:	e60c002c */ 	swc1	$f12,0x2c($s0)
/*    4fb58:	e60a003c */ 	swc1	$f10,0x3c($s0)
/*    4fb5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004fb60:
/*    4fb60:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4fb64:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4fb68:	03e00008 */ 	jr	$ra
/*    4fb6c:	00000000 */ 	nop
/*    4fb70:	44856000 */ 	mtc1	$a1,$f12
/*    4fb74:	44867000 */ 	mtc1	$a2,$f14
/*    4fb78:	44878000 */ 	mtc1	$a3,$f16
/*    4fb7c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    4fb80:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*    4fb84:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4fb88:	afa40060 */ 	sw	$a0,0x60($sp)
/*    4fb8c:	44056000 */ 	mfc1	$a1,$f12
/*    4fb90:	44067000 */ 	mfc1	$a2,$f14
/*    4fb94:	44078000 */ 	mfc1	$a3,$f16
/*    4fb98:	27a40020 */ 	addiu	$a0,$sp,0x20
/*    4fb9c:	0c013e6c */ 	jal	func0004f9b0
/*    4fba0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4fba4:	27a40020 */ 	addiu	$a0,$sp,0x20
/*    4fba8:	0c0128d8 */ 	jal	guMtxF2L
/*    4fbac:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    4fbb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4fbb4:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    4fbb8:	03e00008 */ 	jr	$ra
/*    4fbbc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004fbc0
/*    4fbc0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4fbc4:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4fbc8:	00802825 */ 	or	$a1,$a0,$zero
/*    4fbcc:	24a44000 */ 	addiu	$a0,$a1,0x4000
/*    4fbd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4fbd4:	308effff */ 	andi	$t6,$a0,0xffff
/*    4fbd8:	0c013efc */ 	jal	func0004fbf0
/*    4fbdc:	01c02025 */ 	or	$a0,$t6,$zero
/*    4fbe0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4fbe4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4fbe8:	03e00008 */ 	jr	$ra
/*    4fbec:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004fbf0
/*    4fbf0:	308effff */ 	andi	$t6,$a0,0xffff
/*    4fbf4:	000e7902 */ 	srl	$t7,$t6,0x4
/*    4fbf8:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    4fbfc:	33190400 */ 	andi	$t9,$t8,0x400
/*    4fc00:	afa40000 */ 	sw	$a0,0x0($sp)
/*    4fc04:	13200008 */ 	beqz	$t9,.L0004fc28
/*    4fc08:	03001025 */ 	or	$v0,$t8,$zero
/*    4fc0c:	330803ff */ 	andi	$t0,$t8,0x3ff
/*    4fc10:	00084840 */ 	sll	$t1,$t0,0x1
/*    4fc14:	00095023 */ 	negu	$t2,$t1
/*    4fc18:	3c038006 */ 	lui	$v1,%hi(var800611ec+0x2)
/*    4fc1c:	006a1821 */ 	addu	$v1,$v1,$t2
/*    4fc20:	10000006 */ 	b	.L0004fc3c
/*    4fc24:	846311ee */ 	lh	$v1,%lo(var800611ec+0x2)($v1)
.L0004fc28:
/*    4fc28:	304b03ff */ 	andi	$t3,$v0,0x3ff
/*    4fc2c:	000b6040 */ 	sll	$t4,$t3,0x1
/*    4fc30:	3c038006 */ 	lui	$v1,%hi(var800609f0)
/*    4fc34:	006c1821 */ 	addu	$v1,$v1,$t4
/*    4fc38:	846309f0 */ 	lh	$v1,%lo(var800609f0)($v1)
.L0004fc3c:
/*    4fc3c:	304d0800 */ 	andi	$t5,$v0,0x800
/*    4fc40:	11a00005 */ 	beqz	$t5,.L0004fc58
/*    4fc44:	00601025 */ 	or	$v0,$v1,$zero
/*    4fc48:	00031023 */ 	negu	$v0,$v1
/*    4fc4c:	00027400 */ 	sll	$t6,$v0,0x10
/*    4fc50:	03e00008 */ 	jr	$ra
/*    4fc54:	000e1403 */ 	sra	$v0,$t6,0x10
.L0004fc58:
/*    4fc58:	03e00008 */ 	jr	$ra
/*    4fc5c:	00000000 */ 	nop
);
