#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_44f60.h"
#include "lib/lib_45ed0.h"
#include "lib/lib_461c0.h"
#include "lib/lib_46650.h"
#include "lib/lib_47550.h"
#include "lib/libc/ll.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

u32 var8009c400;
u32 var8009c404;
u32 var8009c408;
u32 var8009c40c;
u32 var8009c410;
u32 var8009c414;
u32 var8009c418;
u32 var8009c41c;
u32 var8009c420;
u32 var8009c424;
u32 var8009c428;
u32 var8009c42c;
u32 var8009c430;
u32 var8009c434;
u32 var8009c438;
u32 var8009c43c;
u32 var8009c440;
u32 var8009c444;
u32 var8009c448;
u32 var8009c44c;
u32 var8009c450;
u32 var8009c454;
u32 var8009c458;
u32 var8009c45c;
u32 var8009c460;
u32 var8009c464;
u32 var8009c468;
u32 var8009c46c;
u32 var8009c470;
u32 var8009c474;
u32 var8009c478;
u32 var8009c47c;
u32 var8009c480;
u32 var8009c484;
u32 var8009c488;
u32 var8009c48c;
u32 var8009c490;
u32 var8009c494;
u32 var8009c498;
u32 var8009c49c;
u32 var8009c4a0;
u32 var8009c4a4;
u32 var8009c4a8;
u32 var8009c4ac;
u32 var8009c4b0;
u32 var8009c4b4;
u32 var8009c4b8;
u32 var8009c4bc;
u32 var8009c4c0;
u32 var8009c4c4;
u32 var8009c4c8;
u32 var8009c4cc;
u32 var8009c4d0;
u32 var8009c4d4;
u32 var8009c4d8;
u32 var8009c4dc;
u32 var8009c4e0;
u32 var8009c4e4;
u32 var8009c4e8;
u32 var8009c4ec;
u32 var8009c4f0;
u32 var8009c4f4;
u32 var8009c4f8;
u32 var8009c4fc;
u32 var8009c500;
u32 var8009c504;
u32 var8009c508;
u32 var8009c50c;
u32 var8009c510;
u32 var8009c514;
u32 var8009c518;
u32 var8009c51c;
u32 var8009c520;
u32 var8009c524;
u32 var8009c528;
u32 var8009c52c;
u32 var8009c530;
u32 var8009c534;
u32 var8009c538;
u32 var8009c53c;
u32 var8009c540;
u32 var8009c544;
u32 var8009c548;
u32 var8009c54c;
u32 var8009c550;
u32 var8009c554;
u32 var8009c558;
u32 var8009c55c;
u32 var8009c560;
u32 var8009c564;
u32 var8009c568;
u32 var8009c56c;
u32 var8009c570;
u32 var8009c574;
u32 var8009c578;
u32 var8009c57c;
u32 var8009c580;
u32 var8009c584;
u32 var8009c588;
u32 var8009c58c;
u32 var8009c590;
u32 var8009c594;
u32 var8009c598;
u32 var8009c59c;
u32 var8009c5a0;
u32 var8009c5a4;
u32 var8009c5a8;
u32 var8009c5ac;
u32 var8009c5b0;
u32 var8009c5b4;
u32 var8009c5b8;
u32 var8009c5bc;
u32 var8009c5c0;
u32 var8009c5c4;
u32 var8009c5c8;
u32 var8009c5cc;
u32 var8009c5d0;
u32 var8009c5d4;
u32 var8009c5d8;
u32 var8009c5dc;
u32 var8009c5e0;
u32 var8009c5e4;
u32 var8009c5e8;
u32 var8009c5ec;
u32 var8009c5f0;
u32 var8009c5f4;
u32 var8009c5f8;
u32 var8009c5fc;
u32 var8009c600;
u32 var8009c604;
u32 var8009c608;
u32 var8009c60c;
u32 var8009c610;
u32 var8009c614;
u32 var8009c618;
u32 var8009c61c;
u32 var8009c620;
u32 var8009c624;
u32 var8009c628;
u32 var8009c62c;
u32 var8009c630;
u32 var8009c634;
u32 var8009c638;
u32 var8009c63c;
u32 var8009c640;
u32 var8009c644;
u32 var8009c648;
u32 var8009c64c;
u32 var8009c650;
u32 var8009c654;
u32 var8009c658;
u32 var8009c65c;
u32 var8009c660;
u32 var8009c664;
u32 var8009c668;
u32 var8009c66c;
u32 var8009c670;
u32 var8009c674;
u32 var8009c678;
u32 var8009c67c;
u32 var8009c680;
u32 var8009c684;
u32 var8009c688;
u32 var8009c68c;
u32 var8009c690;
u32 var8009c694;
u32 var8009c698;
u32 var8009c69c;
u32 var8009c6a0;
u32 var8009c6a4;
u32 var8009c6a8;
u32 var8009c6ac;
u32 var8009c6b0;
u32 var8009c6b4;
u32 var8009c6b8;
u32 var8009c6bc;
u32 var8009c6c0;
u32 var8009c6c4;
u32 var8009c6c8;
u32 var8009c6cc;
u32 var8009c6d0;
u32 var8009c6d4;
u32 var8009c6d8;
u32 var8009c6dc;

u32 var8005f570 = 0x7fff7ffc;
u32 var8005f574 = 0x7ff57fe8;
u32 var8005f578 = 0x7fd77fc0;
u32 var8005f57c = 0x7fa57f84;
u32 var8005f580 = 0x7f5f7f34;
u32 var8005f584 = 0x7f057ed0;
u32 var8005f588 = 0x7e977e58;
u32 var8005f58c = 0x7e157dcd;
u32 var8005f590 = 0x7d7f7d2d;
u32 var8005f594 = 0x7cd67c7a;
u32 var8005f598 = 0x7c1a7bb4;
u32 var8005f59c = 0x7b497ada;
u32 var8005f5a0 = 0x7a6679ed;
u32 var8005f5a4 = 0x796f78ed;
u32 var8005f5a8 = 0x786677da;
u32 var8005f5ac = 0x774976b4;
u32 var8005f5b0 = 0x761a757b;
u32 var8005f5b4 = 0x74d87430;
u32 var8005f5b8 = 0x738472d3;
u32 var8005f5bc = 0x721e7164;
u32 var8005f5c0 = 0x70a66fe3;
u32 var8005f5c4 = 0x6f1c6e51;
u32 var8005f5c8 = 0x6d816cad;
u32 var8005f5cc = 0x6bd56af9;
u32 var8005f5d0 = 0x6a186933;
u32 var8005f5d4 = 0x684a675d;
u32 var8005f5d8 = 0x666c6577;
u32 var8005f5dc = 0x647e6381;
u32 var8005f5e0 = 0x6280617c;
u32 var8005f5e4 = 0x60735f67;
u32 var8005f5e8 = 0x5e575d43;
u32 var8005f5ec = 0x5c2c5b11;
u32 var8005f5f0 = 0x59f258d0;
u32 var8005f5f4 = 0x57aa5681;
u32 var8005f5f8 = 0x55555425;
u32 var8005f5fc = 0x52f251bc;
u32 var8005f600 = 0x50824f46;
u32 var8005f604 = 0x4e064cc3;
u32 var8005f608 = 0x4b7d4a35;
u32 var8005f60c = 0x48e9479b;
u32 var8005f610 = 0x464944f5;
u32 var8005f614 = 0x439e4245;
u32 var8005f618 = 0x40e93f8a;
u32 var8005f61c = 0x3e293cc6;
u32 var8005f620 = 0x3b6039f8;
u32 var8005f624 = 0x388d3721;
u32 var8005f628 = 0x35b23441;
u32 var8005f62c = 0x32ce3159;
u32 var8005f630 = 0x2fe22e69;
u32 var8005f634 = 0x2cef2b72;
u32 var8005f638 = 0x29f42875;
u32 var8005f63c = 0x26f32570;
u32 var8005f640 = 0x23ec2266;
u32 var8005f644 = 0x20df1f57;
u32 var8005f648 = 0x1dce1c43;
u32 var8005f64c = 0x1ab7192a;
u32 var8005f650 = 0x179c160e;
u32 var8005f654 = 0x147e12ed;
u32 var8005f658 = 0x115c0fca;
u32 var8005f65c = 0x0e380ca5;
u32 var8005f660 = 0x0b11097d;
u32 var8005f664 = 0x07e90654;
u32 var8005f668 = 0x04c0032a;
u32 var8005f66c = 0x01950000;
u32 var8005f670 = 0x00000000;
u32 var8005f674 = (u32) &var70054b40;
u32 var8005f678 = (u32) &var70054b68;
u32 var8005f67c = (u32) &var70054bb8;
u32 var8005f680 = (u32) &var70054c08;
u32 var8005f684 = (u32) &var70054c08;
u32 var8005f688 = (u32) &var70054c90;
u32 var8005f68c = (u32) &var70054d18;
u32 var8005f690 = (u32) &var70054e40;
u32 var8005f694 = (u32) &var70054f68;
u32 var8005f698 = (u32) &var70055090;
u32 var8005f69c = (u32) &var70055298;
u32 var8005f6a0 = (u32) &var700554a0;
u32 var8005f6a4 = (u32) &var700556a8;
u32 var8005f6a8 = (u32) &var70055eb0;
u32 var8005f6ac = (u32) &var70055eb0;
u32 var8005f6b0 = (u32) &var700566b8;
u32 var8005f6b4 = (u32) &var700566b8;
u32 var8005f6b8 = (u32) &var700566b8;
u32 var8005f6bc = (u32) &var700566b8;
u32 var8005f6c0 = (u32) &var700566b8;
u32 var8005f6c4 = (u32) &var700566b8;
u32 var8005f6c8 = (u32) &var700566b8;
u32 var8005f6cc = (u32) &var700566b8;
u32 var8005f6d0 = (u32) &var70056ec0;
u32 var8005f6d4 = (u32) &var70056ec0;
u32 var8005f6d8 = (u32) &var70056ec0;
u32 var8005f6dc = (u32) &var70056ec0;
u32 var8005f6e0 = (u32) &var70056ec0;
u32 var8005f6e4 = (u32) &var70056ec0;
u32 var8005f6e8 = (u32) &var70056ec0;
u32 var8005f6ec = (u32) &var70056ec0;
u32 var8005f6f0 = (u32) &var700576c8;
u32 var8005f6f4 = (u32) &var70057750;
u32 var8005f6f8 = 0x00000000;
u32 var8005f6fc = 0x00000000;

#if VERSION >= VERSION_PAL_FINAL
const u32 var70054af0[] = {0x7003e8f8};
const u32 var70054af4[] = {0x7003e9d0};
const u32 var70054af8[] = {0x7003e9d0};
const u32 var70054afc[] = {0x7003e9d0};
const u32 var70054b00[] = {0x7003e9d0};
const u32 var70054b04[] = {0x7003e990};
const u32 var70054b08[] = {0x7003e9d0};
const u32 var70054b0c[] = {0x7003e924};
const u32 var70054b10[] = {0x7003e95c};
const u32 var70054b14[] = {0x7003e9d0};
const u32 var70054b18[] = {0x7003e9d0};
const u32 var70054b1c[] = {0x7003e52c};
const u32 var70054b20[] = {0x7003e52c};
const u32 var70054b24[] = {0x7003e2b8};
const u32 var70054b28[] = {0x7003e870};
const u32 var70054b2c[] = {0x7003e8c0};
const u32 var70054b30[] = {0x7003e52c};
#else
const u32 var70054af0[] = {0x7003eff8};
const u32 var70054af4[] = {0x7003f0d0};
const u32 var70054af8[] = {0x7003f0d0};
const u32 var70054afc[] = {0x7003f0d0};
const u32 var70054b00[] = {0x7003f0d0};
const u32 var70054b04[] = {0x7003f090};
const u32 var70054b08[] = {0x7003f0d0};
const u32 var70054b0c[] = {0x7003f024};
const u32 var70054b10[] = {0x7003f05c};
const u32 var70054b14[] = {0x7003f0d0};
const u32 var70054b18[] = {0x7003f0d0};
const u32 var70054b1c[] = {0x7003ec2c};
const u32 var70054b20[] = {0x7003ec2c};
const u32 var70054b24[] = {0x7003e9b8};
const u32 var70054b28[] = {0x7003ef70};
const u32 var70054b2c[] = {0x7003efc0};
const u32 var70054b30[] = {0x7003ec2c};
#endif

const u32 var70054b34[] = {0x477fff00};
const u32 var70054b38[] = {0x00000000};
const u32 var70054b3c[] = {0x00000000};

const u32 var70054b40[] = {0x00000100};
const u32 var70054b44[] = {0x00000001};
const u32 var70054b48[] = {0x00010300};
const u32 var70054b4c[] = {0x00000004};
const u32 var70054b50[] = {0x01000200};
const u32 var70054b54[] = {0x00000002};
const u32 var70054b58[] = {0x01010300};
const u32 var70054b5c[] = {0x00000000};
const u32 var70054b60[] = {0x64646400};
const u32 var70054b64[] = {0x00000000};
const u32 var70054b68[] = {0x00000100};
const u32 var70054b6c[] = {0x00000001};
const u32 var70054b70[] = {0x00010300};
const u32 var70054b74[] = {0x00000002};
const u32 var70054b78[] = {0x00020600};
const u32 var70054b7c[] = {0x00000020};
const u32 var70054b80[] = {0x01000300};
const u32 var70054b84[] = {0x00000006};
const u32 var70054b88[] = {0x01010300};
const u32 var70054b8c[] = {0x00000004};
const u32 var70054b90[] = {0x01020500};
const u32 var70054b94[] = {0x00000010};
const u32 var70054b98[] = {0x02000500};
const u32 var70054b9c[] = {0x00000018};
const u32 var70054ba0[] = {0x02010500};
const u32 var70054ba4[] = {0x00000008};
const u32 var70054ba8[] = {0x02020600};
const u32 var70054bac[] = {0x00000000};
const u32 var70054bb0[] = {0x64646400};
const u32 var70054bb4[] = {0x00000000};
const u32 var70054bb8[] = {0x00000200};
const u32 var70054bbc[] = {0x00000003};
const u32 var70054bc0[] = {0x00010200};
const u32 var70054bc4[] = {0x00000001};
const u32 var70054bc8[] = {0x00020600};
const u32 var70054bcc[] = {0x00000020};
const u32 var70054bd0[] = {0x01000300};
const u32 var70054bd4[] = {0x00000004};
const u32 var70054bd8[] = {0x01010200};
const u32 var70054bdc[] = {0x00000002};
const u32 var70054be0[] = {0x01020500};
const u32 var70054be4[] = {0x00000010};
const u32 var70054be8[] = {0x02000500};
const u32 var70054bec[] = {0x00000018};
const u32 var70054bf0[] = {0x02010500};
const u32 var70054bf4[] = {0x00000008};
const u32 var70054bf8[] = {0x02020600};
const u32 var70054bfc[] = {0x00000000};
const u32 var70054c00[] = {0x64646400};
const u32 var70054c04[] = {0x00000000};
const u32 var70054c08[] = {0x00000100};
const u32 var70054c0c[] = {0x00000001};
const u32 var70054c10[] = {0x00010300};
const u32 var70054c14[] = {0x00000002};
const u32 var70054c18[] = {0x00020600};
const u32 var70054c1c[] = {0x00000018};
const u32 var70054c20[] = {0x00030700};
const u32 var70054c24[] = {0x00000050};
const u32 var70054c28[] = {0x01000300};
const u32 var70054c2c[] = {0x00000006};
const u32 var70054c30[] = {0x01010300};
const u32 var70054c34[] = {0x00000004};
const u32 var70054c38[] = {0x01020600};
const u32 var70054c3c[] = {0x00000008};
const u32 var70054c40[] = {0x01030700};
const u32 var70054c44[] = {0x00000010};
const u32 var70054c48[] = {0x02000600};
const u32 var70054c4c[] = {0x00000038};
const u32 var70054c50[] = {0x02010600};
const u32 var70054c54[] = {0x00000028};
const u32 var70054c58[] = {0x02020700};
const u32 var70054c5c[] = {0x00000070};
const u32 var70054c60[] = {0x02030800};
const u32 var70054c64[] = {0x00000080};
const u32 var70054c68[] = {0x03000700};
const u32 var70054c6c[] = {0x00000030};
const u32 var70054c70[] = {0x03010600};
const u32 var70054c74[] = {0x00000020};
const u32 var70054c78[] = {0x03020700};
const u32 var70054c7c[] = {0x00000040};
const u32 var70054c80[] = {0x03030800};
const u32 var70054c84[] = {0x00000000};
const u32 var70054c88[] = {0x64646400};
const u32 var70054c8c[] = {0x00000000};
const u32 var70054c90[] = {0x00000300};
const u32 var70054c94[] = {0x00000007};
const u32 var70054c98[] = {0x00010300};
const u32 var70054c9c[] = {0x00000006};
const u32 var70054ca0[] = {0x00020500};
const u32 var70054ca4[] = {0x00000014};
const u32 var70054ca8[] = {0x00030700};
const u32 var70054cac[] = {0x00000040};
const u32 var70054cb0[] = {0x01000300};
const u32 var70054cb4[] = {0x00000003};
const u32 var70054cb8[] = {0x01010200};
const u32 var70054cbc[] = {0x00000001};
const u32 var70054cc0[] = {0x01020400};
const u32 var70054cc4[] = {0x0000000c};
const u32 var70054cc8[] = {0x01030500};
const u32 var70054ccc[] = {0x00000008};
const u32 var70054cd0[] = {0x02000400};
const u32 var70054cd4[] = {0x0000000a};
const u32 var70054cd8[] = {0x02010400};
const u32 var70054cdc[] = {0x00000002};
const u32 var70054ce0[] = {0x02020500};
const u32 var70054ce4[] = {0x00000004};
const u32 var70054ce8[] = {0x02030600};
const u32 var70054cec[] = {0x00000020};
const u32 var70054cf0[] = {0x03000600};
const u32 var70054cf4[] = {0x00000030};
const u32 var70054cf8[] = {0x03010500};
const u32 var70054cfc[] = {0x00000018};
const u32 var70054d00[] = {0x03020600};
const u32 var70054d04[] = {0x00000010};
const u32 var70054d08[] = {0x03030700};
const u32 var70054d0c[] = {0x00000000};
const u32 var70054d10[] = {0x64646400};
const u32 var70054d14[] = {0x00000000};
const u32 var70054d18[] = {0x00000100};
const u32 var70054d1c[] = {0x00000001};
const u32 var70054d20[] = {0x00010300};
const u32 var70054d24[] = {0x00000002};
const u32 var70054d28[] = {0x00020600};
const u32 var70054d2c[] = {0x00000014};
const u32 var70054d30[] = {0x00030800};
const u32 var70054d34[] = {0x000000c8};
const u32 var70054d38[] = {0x00040800};
const u32 var70054d3c[] = {0x00000008};
const u32 var70054d40[] = {0x00050900};
const u32 var70054d44[] = {0x000000a0};
const u32 var70054d48[] = {0x01000300};
const u32 var70054d4c[] = {0x00000006};
const u32 var70054d50[] = {0x01010400};
const u32 var70054d54[] = {0x0000000c};
const u32 var70054d58[] = {0x01020600};
const u32 var70054d5c[] = {0x00000038};
const u32 var70054d60[] = {0x01030700};
const u32 var70054d64[] = {0x00000028};
const u32 var70054d68[] = {0x01040700};
const u32 var70054d6c[] = {0x00000050};
const u32 var70054d70[] = {0x01050800};
const u32 var70054d74[] = {0x000000c0};
const u32 var70054d78[] = {0x02000600};
const u32 var70054d7c[] = {0x00000034};
const u32 var70054d80[] = {0x02010500};
const u32 var70054d84[] = {0x00000004};
const u32 var70054d88[] = {0x02020700};
const u32 var70054d8c[] = {0x00000058};
const u32 var70054d90[] = {0x02030800};
const u32 var70054d94[] = {0x00000088};
const u32 var70054d98[] = {0x02040800};
const u32 var70054d9c[] = {0x00000010};
const u32 var70054da0[] = {0x02050900};
const u32 var70054da4[] = {0x00000040};
const u32 var70054da8[] = {0x03000700};
const u32 var70054dac[] = {0x00000018};
const u32 var70054db0[] = {0x03010700};
const u32 var70054db4[] = {0x00000068};
const u32 var70054db8[] = {0x03020800};
const u32 var70054dbc[] = {0x00000048};
const u32 var70054dc0[] = {0x03030900};
const u32 var70054dc4[] = {0x000001e0};
const u32 var70054dc8[] = {0x03040900};
const u32 var70054dcc[] = {0x000001a0};
const u32 var70054dd0[] = {0x03050900};
const u32 var70054dd4[] = {0x00000080};
const u32 var70054dd8[] = {0x04000700};
const u32 var70054ddc[] = {0x00000070};
const u32 var70054de0[] = {0x04010700};
const u32 var70054de4[] = {0x00000030};
const u32 var70054de8[] = {0x04020800};
const u32 var70054dec[] = {0x00000090};
const u32 var70054df0[] = {0x04030900};
const u32 var70054df4[] = {0x000000e0};
const u32 var70054df8[] = {0x04040900};
const u32 var70054dfc[] = {0x00000180};
const u32 var70054e00[] = {0x04050a00};
const u32 var70054e04[] = {0x00000200};
const u32 var70054e08[] = {0x05000800};
const u32 var70054e0c[] = {0x00000060};
const u32 var70054e10[] = {0x05010800};
const u32 var70054e14[] = {0x00000020};
const u32 var70054e18[] = {0x05020900};
const u32 var70054e1c[] = {0x00000140};
const u32 var70054e20[] = {0x05030a00};
const u32 var70054e24[] = {0x00000300};
const u32 var70054e28[] = {0x05040a00};
const u32 var70054e2c[] = {0x00000100};
const u32 var70054e30[] = {0x05050a00};
const u32 var70054e34[] = {0x00000000};
const u32 var70054e38[] = {0x64646400};
const u32 var70054e3c[] = {0x00000000};
const u32 var70054e40[] = {0x00000200};
const u32 var70054e44[] = {0x00000003};
const u32 var70054e48[] = {0x00010300};
const u32 var70054e4c[] = {0x00000001};
const u32 var70054e50[] = {0x00020600};
const u32 var70054e54[] = {0x00000018};
const u32 var70054e58[] = {0x00030800};
const u32 var70054e5c[] = {0x00000048};
const u32 var70054e60[] = {0x00040800};
const u32 var70054e64[] = {0x00000030};
const u32 var70054e68[] = {0x00050900};
const u32 var70054e6c[] = {0x00000140};
const u32 var70054e70[] = {0x01000300};
const u32 var70054e74[] = {0x00000005};
const u32 var70054e78[] = {0x01010200};
const u32 var70054e7c[] = {0x00000002};
const u32 var70054e80[] = {0x01020400};
const u32 var70054e84[] = {0x00000004};
const u32 var70054e88[] = {0x01030800};
const u32 var70054e8c[] = {0x00000008};
const u32 var70054e90[] = {0x01040800};
const u32 var70054e94[] = {0x00000090};
const u32 var70054e98[] = {0x01050800};
const u32 var70054e9c[] = {0x000000c0};
const u32 var70054ea0[] = {0x02000600};
const u32 var70054ea4[] = {0x00000038};
const u32 var70054ea8[] = {0x02010400};
const u32 var70054eac[] = {0x0000000c};
const u32 var70054eb0[] = {0x02020600};
const u32 var70054eb4[] = {0x00000028};
const u32 var70054eb8[] = {0x02030800};
const u32 var70054ebc[] = {0x00000070};
const u32 var70054ec0[] = {0x02040800};
const u32 var70054ec4[] = {0x000000e0};
const u32 var70054ec8[] = {0x02050900};
const u32 var70054ecc[] = {0x00000180};
const u32 var70054ed0[] = {0x03000800};
const u32 var70054ed4[] = {0x000000c8};
const u32 var70054ed8[] = {0x03010800};
const u32 var70054edc[] = {0x00000088};
const u32 var70054ee0[] = {0x03020800};
const u32 var70054ee4[] = {0x000000f0};
const u32 var70054ee8[] = {0x03030900};
const u32 var70054eec[] = {0x00000160};
const u32 var70054ef0[] = {0x03040900};
const u32 var70054ef4[] = {0x000000a0};
const u32 var70054ef8[] = {0x03050a00};
const u32 var70054efc[] = {0x00000080};
const u32 var70054f00[] = {0x04000800};
const u32 var70054f04[] = {0x000000b0};
const u32 var70054f08[] = {0x04010700};
const u32 var70054f0c[] = {0x00000050};
const u32 var70054f10[] = {0x04020800};
const u32 var70054f14[] = {0x00000010};
const u32 var70054f18[] = {0x04030900};
const u32 var70054f1c[] = {0x000001a0};
const u32 var70054f20[] = {0x04040a00};
const u32 var70054f24[] = {0x00000280};
const u32 var70054f28[] = {0x04050a00};
const u32 var70054f2c[] = {0x00000200};
const u32 var70054f30[] = {0x05000900};
const u32 var70054f34[] = {0x00000060};
const u32 var70054f38[] = {0x05010800};
const u32 var70054f3c[] = {0x00000020};
const u32 var70054f40[] = {0x05020900};
const u32 var70054f44[] = {0x00000040};
const u32 var70054f48[] = {0x05030900};
const u32 var70054f4c[] = {0x00000100};
const u32 var70054f50[] = {0x05040b00};
const u32 var70054f54[] = {0x00000400};
const u32 var70054f58[] = {0x05050b00};
const u32 var70054f5c[] = {0x00000000};
const u32 var70054f60[] = {0x64646400};
const u32 var70054f64[] = {0x00000000};
const u32 var70054f68[] = {0x00000300};
const u32 var70054f6c[] = {0x00000007};
const u32 var70054f70[] = {0x00010300};
const u32 var70054f74[] = {0x00000005};
const u32 var70054f78[] = {0x00020500};
const u32 var70054f7c[] = {0x00000012};
const u32 var70054f80[] = {0x00030600};
const u32 var70054f84[] = {0x0000001c};
const u32 var70054f88[] = {0x00040800};
const u32 var70054f8c[] = {0x000000f0};
const u32 var70054f90[] = {0x00050900};
const u32 var70054f94[] = {0x000001c0};
const u32 var70054f98[] = {0x01000300};
const u32 var70054f9c[] = {0x00000003};
const u32 var70054fa0[] = {0x01010300};
const u32 var70054fa4[] = {0x00000001};
const u32 var70054fa8[] = {0x01020400};
const u32 var70054fac[] = {0x0000000a};
const u32 var70054fb0[] = {0x01030500};
const u32 var70054fb4[] = {0x00000014};
const u32 var70054fb8[] = {0x01040600};
const u32 var70054fbc[] = {0x00000018};
const u32 var70054fc0[] = {0x01050800};
const u32 var70054fc4[] = {0x000000e0};
const u32 var70054fc8[] = {0x02000400};
const u32 var70054fcc[] = {0x0000000e};
const u32 var70054fd0[] = {0x02010400};
const u32 var70054fd4[] = {0x00000006};
const u32 var70054fd8[] = {0x02020500};
const u32 var70054fdc[] = {0x00000002};
const u32 var70054fe0[] = {0x02030600};
const u32 var70054fe4[] = {0x00000004};
const u32 var70054fe8[] = {0x02040700};
const u32 var70054fec[] = {0x00000008};
const u32 var70054ff0[] = {0x02050800};
const u32 var70054ff4[] = {0x000000a0};
const u32 var70054ff8[] = {0x03000600};
const u32 var70054ffc[] = {0x0000003c};
const u32 var70055000[] = {0x03010500};
const u32 var70055004[] = {0x0000000c};
const u32 var70055008[] = {0x03020600};
const u32 var7005500c[] = {0x00000024};
const u32 var70055010[] = {0x03030700};
const u32 var70055014[] = {0x00000028};
const u32 var70055018[] = {0x03040700};
const u32 var7005501c[] = {0x00000050};
const u32 var70055020[] = {0x03050800};
const u32 var70055024[] = {0x00000080};
const u32 var70055028[] = {0x04000700};
const u32 var7005502c[] = {0x00000068};
const u32 var70055030[] = {0x04010600};
const u32 var70055034[] = {0x00000038};
const u32 var70055038[] = {0x04020700};
const u32 var7005503c[] = {0x00000048};
const u32 var70055040[] = {0x04030700};
const u32 var70055044[] = {0x00000030};
const u32 var70055048[] = {0x04040800};
const u32 var7005504c[] = {0x00000020};
const u32 var70055050[] = {0x04050900};
const u32 var70055054[] = {0x00000100};
const u32 var70055058[] = {0x05000800};
const u32 var7005505c[] = {0x00000070};
const u32 var70055060[] = {0x05010700};
const u32 var70055064[] = {0x00000010};
const u32 var70055068[] = {0x05020800};
const u32 var7005506c[] = {0x00000060};
const u32 var70055070[] = {0x05030800};
const u32 var70055074[] = {0x00000040};
const u32 var70055078[] = {0x05040900};
const u32 var7005507c[] = {0x000000c0};
const u32 var70055080[] = {0x05050900};
const u32 var70055084[] = {0x00000000};
const u32 var70055088[] = {0x64646400};
const u32 var7005508c[] = {0x00000000};
const u32 var70055090[] = {0x00000100};
const u32 var70055094[] = {0x00000001};
const u32 var70055098[] = {0x00010300};
const u32 var7005509c[] = {0x00000002};
const u32 var700550a0[] = {0x00020600};
const u32 var700550a4[] = {0x00000014};
const u32 var700550a8[] = {0x00030800};
const u32 var700550ac[] = {0x000000e8};
const u32 var700550b0[] = {0x00040900};
const u32 var700550b4[] = {0x00000188};
const u32 var700550b8[] = {0x00050900};
const u32 var700550bc[] = {0x000000f0};
const u32 var700550c0[] = {0x00060900};
const u32 var700550c4[] = {0x00000060};
const u32 var700550c8[] = {0x00070a00};
const u32 var700550cc[] = {0x00000220};
const u32 var700550d0[] = {0x01000300};
const u32 var700550d4[] = {0x00000006};
const u32 var700550d8[] = {0x01010400};
const u32 var700550dc[] = {0x0000000c};
const u32 var700550e0[] = {0x01020600};
const u32 var700550e4[] = {0x00000004};
const u32 var700550e8[] = {0x01030700};
const u32 var700550ec[] = {0x00000018};
const u32 var700550f0[] = {0x01040800};
const u32 var700550f4[] = {0x00000048};
const u32 var700550f8[] = {0x01050900};
const u32 var700550fc[] = {0x00000150};
const u32 var70055100[] = {0x01060800};
const u32 var70055104[] = {0x00000030};
const u32 var70055108[] = {0x01070800};
const u32 var7005510c[] = {0x000000e0};
const u32 var70055110[] = {0x02000600};
const u32 var70055114[] = {0x00000034};
const u32 var70055118[] = {0x02010600};
const u32 var7005511c[] = {0x00000024};
const u32 var70055120[] = {0x02020700};
const u32 var70055124[] = {0x00000078};
const u32 var70055128[] = {0x02030800};
const u32 var7005512c[] = {0x000000a8};
const u32 var70055130[] = {0x02040900};
const u32 var70055134[] = {0x00000008};
const u32 var70055138[] = {0x02050a00};
const u32 var7005513c[] = {0x00000050};
const u32 var70055140[] = {0x02060900};
const u32 var70055144[] = {0x00000190};
const u32 var70055148[] = {0x02070900};
const u32 var7005514c[] = {0x000000c0};
const u32 var70055150[] = {0x03000700};
const u32 var70055154[] = {0x00000038};
const u32 var70055158[] = {0x03010700};
const u32 var7005515c[] = {0x00000058};
const u32 var70055160[] = {0x03020800};
const u32 var70055164[] = {0x00000068};
const u32 var70055168[] = {0x03030900};
const u32 var7005516c[] = {0x00000088};
const u32 var70055170[] = {0x03040a00};
const u32 var70055174[] = {0x000001d0};
const u32 var70055178[] = {0x03050a00};
const u32 var7005517c[] = {0x000003a0};
const u32 var70055180[] = {0x03060900};
const u32 var70055184[] = {0x00000090};
const u32 var70055188[] = {0x03070a00};
const u32 var7005518c[] = {0x00000380};
const u32 var70055190[] = {0x04000800};
const u32 var70055194[] = {0x00000028};
const u32 var70055198[] = {0x04010800};
const u32 var7005519c[] = {0x000000c8};
const u32 var700551a0[] = {0x04020900};
const u32 var700551a4[] = {0x00000108};
const u32 var700551a8[] = {0x04030a00};
const u32 var700551ac[] = {0x000003d0};
const u32 var700551b0[] = {0x04040a00};
const u32 var700551b4[] = {0x00000360};
const u32 var700551b8[] = {0x04050a00};
const u32 var700551bc[] = {0x000001a0};
const u32 var700551c0[] = {0x04060a00};
const u32 var700551c4[] = {0x00000240};
const u32 var700551c8[] = {0x04070a00};
const u32 var700551cc[] = {0x00000300};
const u32 var700551d0[] = {0x05000900};
const u32 var700551d4[] = {0x000001f0};
const u32 var700551d8[] = {0x05010900};
const u32 var700551dc[] = {0x000000d0};
const u32 var700551e0[] = {0x05020a00};
const u32 var700551e4[] = {0x00000250};
const u32 var700551e8[] = {0x05030a00};
const u32 var700551ec[] = {0x00000160};
const u32 var700551f0[] = {0x05040b00};
const u32 var700551f4[] = {0x00000540};
const u32 var700551f8[] = {0x05050b00};
const u32 var700551fc[] = {0x00000140};
const u32 var70055200[] = {0x05060a00};
const u32 var70055204[] = {0x00000280};
const u32 var70055208[] = {0x05070b00};
const u32 var7005520c[] = {0x00000600};
const u32 var70055210[] = {0x06000800};
const u32 var70055214[] = {0x00000070};
const u32 var70055218[] = {0x06010800};
const u32 var7005521c[] = {0x000000b0};
const u32 var70055220[] = {0x06020900};
const u32 var70055224[] = {0x000000a0};
const u32 var70055228[] = {0x06030a00};
const u32 var7005522c[] = {0x00000340};
const u32 var70055230[] = {0x06040a00};
const u32 var70055234[] = {0x00000020};
const u32 var70055238[] = {0x06050a00};
const u32 var7005523c[] = {0x00000180};
const u32 var70055240[] = {0x06060b00};
const u32 var70055244[] = {0x00000500};
const u32 var70055248[] = {0x06070b00};
const u32 var7005524c[] = {0x00000400};
const u32 var70055250[] = {0x07000900};
const u32 var70055254[] = {0x00000120};
const u32 var70055258[] = {0x07010800};
const u32 var7005525c[] = {0x00000010};
const u32 var70055260[] = {0x07020900};
const u32 var70055264[] = {0x000001c0};
const u32 var70055268[] = {0x07030a00};
const u32 var7005526c[] = {0x00000040};
const u32 var70055270[] = {0x07040a00};
const u32 var70055274[] = {0x00000080};
const u32 var70055278[] = {0x07050b00};
const u32 var7005527c[] = {0x00000100};
const u32 var70055280[] = {0x07060b00};
const u32 var70055284[] = {0x00000200};
const u32 var70055288[] = {0x07070b00};
const u32 var7005528c[] = {0x00000000};
const u32 var70055290[] = {0x64646400};
const u32 var70055294[] = {0x00000000};
const u32 var70055298[] = {0x00000200};
const u32 var7005529c[] = {0x00000003};
const u32 var700552a0[] = {0x00010300};
const u32 var700552a4[] = {0x00000001};
const u32 var700552a8[] = {0x00020500};
const u32 var700552ac[] = {0x0000000a};
const u32 var700552b0[] = {0x00030700};
const u32 var700552b4[] = {0x0000000c};
const u32 var700552b8[] = {0x00040800};
const u32 var700552bc[] = {0x00000044};
const u32 var700552c0[] = {0x00050900};
const u32 var700552c4[] = {0x00000108};
const u32 var700552c8[] = {0x00060800};
const u32 var700552cc[] = {0x000000a8};
const u32 var700552d0[] = {0x00070900};
const u32 var700552d4[] = {0x000001e0};
const u32 var700552d8[] = {0x01000300};
const u32 var700552dc[] = {0x00000005};
const u32 var700552e0[] = {0x01010300};
const u32 var700552e4[] = {0x00000006};
const u32 var700552e8[] = {0x01020400};
const u32 var700552ec[] = {0x00000002};
const u32 var700552f0[] = {0x01030600};
const u32 var700552f4[] = {0x00000014};
const u32 var700552f8[] = {0x01040800};
const u32 var700552fc[] = {0x00000004};
const u32 var70055300[] = {0x01050800};
const u32 var70055304[] = {0x00000088};
const u32 var70055308[] = {0x01060700};
const u32 var7005530c[] = {0x00000068};
const u32 var70055310[] = {0x01070800};
const u32 var70055314[] = {0x00000050};
const u32 var70055318[] = {0x02000500};
const u32 var7005531c[] = {0x0000001a};
const u32 var70055320[] = {0x02010500};
const u32 var70055324[] = {0x0000001c};
const u32 var70055328[] = {0x02020600};
const u32 var7005532c[] = {0x0000002c};
const u32 var70055330[] = {0x02030700};
const u32 var70055334[] = {0x00000024};
const u32 var70055338[] = {0x02040800};
const u32 var7005533c[] = {0x00000078};
const u32 var70055340[] = {0x02050900};
const u32 var70055344[] = {0x000001f0};
const u32 var70055348[] = {0x02060800};
const u32 var7005534c[] = {0x00000028};
const u32 var70055350[] = {0x02070800};
const u32 var70055354[] = {0x000000a0};
const u32 var70055358[] = {0x03000700};
const u32 var7005535c[] = {0x0000004c};
const u32 var70055360[] = {0x03010600};
const u32 var70055364[] = {0x00000034};
const u32 var70055368[] = {0x03020700};
const u32 var7005536c[] = {0x00000064};
const u32 var70055370[] = {0x03030900};
const u32 var70055374[] = {0x000001b8};
const u32 var70055378[] = {0x03040800};
const u32 var7005537c[] = {0x000000d8};
const u32 var70055380[] = {0x03050a00};
const u32 var70055384[] = {0x00000120};
const u32 var70055388[] = {0x03060800};
const u32 var7005538c[] = {0x00000030};
const u32 var70055390[] = {0x03070900};
const u32 var70055394[] = {0x00000140};
const u32 var70055398[] = {0x04000800};
const u32 var7005539c[] = {0x000000c4};
const u32 var700553a0[] = {0x04010800};
const u32 var700553a4[] = {0x00000084};
const u32 var700553a8[] = {0x04020800};
const u32 var700553ac[] = {0x000000f8};
const u32 var700553b0[] = {0x04030900};
const u32 var700553b4[] = {0x000000b8};
const u32 var700553b8[] = {0x04040900};
const u32 var700553bc[] = {0x000000f0};
const u32 var700553c0[] = {0x04050a00};
const u32 var700553c4[] = {0x00000020};
const u32 var700553c8[] = {0x04060900};
const u32 var700553cc[] = {0x000001c0};
const u32 var700553d0[] = {0x04070a00};
const u32 var700553d4[] = {0x00000280};
const u32 var700553d8[] = {0x05000800};
const u32 var700553dc[] = {0x00000038};
const u32 var700553e0[] = {0x05010800};
const u32 var700553e4[] = {0x00000058};
const u32 var700553e8[] = {0x05020900};
const u32 var700553ec[] = {0x00000008};
const u32 var700553f0[] = {0x05030a00};
const u32 var700553f4[] = {0x00000320};
const u32 var700553f8[] = {0x05040a00};
const u32 var700553fc[] = {0x00000220};
const u32 var70055400[] = {0x05050b00};
const u32 var70055404[] = {0x00000780};
const u32 var70055408[] = {0x05060a00};
const u32 var7005540c[] = {0x00000040};
const u32 var70055410[] = {0x05070b00};
const u32 var70055414[] = {0x00000380};
const u32 var70055418[] = {0x06000800};
const u32 var7005541c[] = {0x00000070};
const u32 var70055420[] = {0x06010700};
const u32 var70055424[] = {0x00000018};
const u32 var70055428[] = {0x06020700};
const u32 var7005542c[] = {0x00000048};
const u32 var70055430[] = {0x06030800};
const u32 var70055434[] = {0x000000b0};
const u32 var70055438[] = {0x06040900};
const u32 var7005543c[] = {0x000000e0};
const u32 var70055440[] = {0x06050a00};
const u32 var70055444[] = {0x00000240};
const u32 var70055448[] = {0x06060a00};
const u32 var7005544c[] = {0x00000080};
const u32 var70055450[] = {0x06070a00};
const u32 var70055454[] = {0x00000200};
const u32 var70055458[] = {0x07000800};
const u32 var7005545c[] = {0x000000d0};
const u32 var70055460[] = {0x07010700};
const u32 var70055464[] = {0x00000010};
const u32 var70055468[] = {0x07020800};
const u32 var7005546c[] = {0x00000060};
const u32 var70055470[] = {0x07030900};
const u32 var70055474[] = {0x000000c0};
const u32 var70055478[] = {0x07040a00};
const u32 var7005547c[] = {0x00000180};
const u32 var70055480[] = {0x07050a00};
const u32 var70055484[] = {0x00000300};
const u32 var70055488[] = {0x07060a00};
const u32 var7005548c[] = {0x00000100};
const u32 var70055490[] = {0x07070a00};
const u32 var70055494[] = {0x00000000};
const u32 var70055498[] = {0x64646400};
const u32 var7005549c[] = {0x00000000};
const u32 var700554a0[] = {0x00000400};
const u32 var700554a4[] = {0x00000009};
const u32 var700554a8[] = {0x00010300};
const u32 var700554ac[] = {0x00000003};
const u32 var700554b0[] = {0x00020500};
const u32 var700554b4[] = {0x00000001};
const u32 var700554b8[] = {0x00030700};
const u32 var700554bc[] = {0x00000042};
const u32 var700554c0[] = {0x00040800};
const u32 var700554c4[] = {0x00000094};
const u32 var700554c8[] = {0x00050900};
const u32 var700554cc[] = {0x000001c8};
const u32 var700554d0[] = {0x00060900};
const u32 var700554d4[] = {0x000000c8};
const u32 var700554d8[] = {0x00070900};
const u32 var700554dc[] = {0x000000b0};
const u32 var700554e0[] = {0x01000300};
const u32 var700554e4[] = {0x00000007};
const u32 var700554e8[] = {0x01010300};
const u32 var700554ec[] = {0x00000005};
const u32 var700554f0[] = {0x01020400};
const u32 var700554f4[] = {0x00000006};
const u32 var700554f8[] = {0x01030500};
const u32 var700554fc[] = {0x00000012};
const u32 var70055500[] = {0x01040700};
const u32 var70055504[] = {0x00000074};
const u32 var70055508[] = {0x01050700};
const u32 var7005550c[] = {0x00000004};
const u32 var70055510[] = {0x01060800};
const u32 var70055514[] = {0x00000058};
const u32 var70055518[] = {0x01070800};
const u32 var7005551c[] = {0x000000d0};
const u32 var70055520[] = {0x02000500};
const u32 var70055524[] = {0x00000011};
const u32 var70055528[] = {0x02010400};
const u32 var7005552c[] = {0x0000000e};
const u32 var70055530[] = {0x02020500};
const u32 var70055534[] = {0x0000001a};
const u32 var70055538[] = {0x02030600};
const u32 var7005553c[] = {0x0000001c};
const u32 var70055540[] = {0x02040700};
const u32 var70055544[] = {0x00000054};
const u32 var70055548[] = {0x02050800};
const u32 var7005554c[] = {0x00000078};
const u32 var70055550[] = {0x02060700};
const u32 var70055554[] = {0x00000028};
const u32 var70055558[] = {0x02070800};
const u32 var7005555c[] = {0x000000e0};
const u32 var70055560[] = {0x03000600};
const u32 var70055564[] = {0x00000022};
const u32 var70055568[] = {0x03010500};
const u32 var7005556c[] = {0x0000000a};
const u32 var70055570[] = {0x03020600};
const u32 var70055574[] = {0x0000003c};
const u32 var70055578[] = {0x03030600};
const u32 var7005557c[] = {0x0000000c};
const u32 var70055580[] = {0x03040700};
const u32 var70055584[] = {0x00000024};
const u32 var70055588[] = {0x03050800};
const u32 var7005558c[] = {0x00000038};
const u32 var70055590[] = {0x03060800};
const u32 var70055594[] = {0x00000070};
const u32 var70055598[] = {0x03070800};
const u32 var7005559c[] = {0x000000a0};
const u32 var700555a0[] = {0x04000700};
const u32 var700555a4[] = {0x00000002};
const u32 var700555a8[] = {0x04010600};
const u32 var700555ac[] = {0x0000002c};
const u32 var700555b0[] = {0x04020700};
const u32 var700555b4[] = {0x00000034};
const u32 var700555b8[] = {0x04030700};
const u32 var700555bc[] = {0x00000064};
const u32 var700555c0[] = {0x04040800};
const u32 var700555c4[] = {0x00000048};
const u32 var700555c8[] = {0x04050800};
const u32 var700555cc[] = {0x00000008};
const u32 var700555d0[] = {0x04060800};
const u32 var700555d4[] = {0x00000090};
const u32 var700555d8[] = {0x04070900};
const u32 var700555dc[] = {0x00000140};
const u32 var700555e0[] = {0x05000800};
const u32 var700555e4[] = {0x00000014};
const u32 var700555e8[] = {0x05010700};
const u32 var700555ec[] = {0x00000044};
const u32 var700555f0[] = {0x05020800};
const u32 var700555f4[] = {0x000000f8};
const u32 var700555f8[] = {0x05030800};
const u32 var700555fc[] = {0x000000b8};
const u32 var70055600[] = {0x05040800};
const u32 var70055604[] = {0x00000088};
const u32 var70055608[] = {0x05050900};
const u32 var7005560c[] = {0x00000160};
const u32 var70055610[] = {0x05060800};
const u32 var70055614[] = {0x00000020};
const u32 var70055618[] = {0x05070900};
const u32 var7005561c[] = {0x00000080};
const u32 var70055620[] = {0x06000800};
const u32 var70055624[] = {0x000000d8};
const u32 var70055628[] = {0x06010700};
const u32 var7005562c[] = {0x00000018};
const u32 var70055630[] = {0x06020700};
const u32 var70055634[] = {0x00000068};
const u32 var70055638[] = {0x06030800};
const u32 var7005563c[] = {0x000000f0};
const u32 var70055640[] = {0x06040800};
const u32 var70055644[] = {0x00000050};
const u32 var70055648[] = {0x06050900};
const u32 var7005564c[] = {0x000001c0};
const u32 var70055650[] = {0x06060900};
const u32 var70055654[] = {0x00000040};
const u32 var70055658[] = {0x06070a00};
const u32 var7005565c[] = {0x00000200};
const u32 var70055660[] = {0x07000900};
const u32 var70055664[] = {0x000001b0};
const u32 var70055668[] = {0x07010800};
const u32 var7005566c[] = {0x00000030};
const u32 var70055670[] = {0x07020800};
const u32 var70055674[] = {0x00000010};
const u32 var70055678[] = {0x07030900};
const u32 var7005567c[] = {0x00000060};
const u32 var70055680[] = {0x07040900};
const u32 var70055684[] = {0x000000c0};
const u32 var70055688[] = {0x07050900};
const u32 var7005568c[] = {0x00000180};
const u32 var70055690[] = {0x07060900};
const u32 var70055694[] = {0x00000100};
const u32 var70055698[] = {0x07070a00};
const u32 var7005569c[] = {0x00000000};
const u32 var700556a0[] = {0x64646400};
const u32 var700556a4[] = {0x00000000};
const u32 var700556a8[] = {0x00000100};
const u32 var700556ac[] = {0x00000001};
const u32 var700556b0[] = {0x00010400};
const u32 var700556b4[] = {0x0000000a};
const u32 var700556b8[] = {0x00020600};
const u32 var700556bc[] = {0x0000001c};
const u32 var700556c0[] = {0x00030700};
const u32 var700556c4[] = {0x00000054};
const u32 var700556c8[] = {0x00040800};
const u32 var700556cc[] = {0x00000044};
const u32 var700556d0[] = {0x00050900};
const u32 var700556d4[] = {0x00000198};
const u32 var700556d8[] = {0x00060900};
const u32 var700556dc[] = {0x000000e8};
const u32 var700556e0[] = {0x00070a00};
const u32 var700556e4[] = {0x00000388};
const u32 var700556e8[] = {0x00080900};
const u32 var700556ec[] = {0x000000a8};
const u32 var700556f0[] = {0x00090a00};
const u32 var700556f4[] = {0x000000b0};
const u32 var700556f8[] = {0x000a0b00};
const u32 var700556fc[] = {0x00000110};
const u32 var70055700[] = {0x000b0b00};
const u32 var70055704[] = {0x00000160};
const u32 var70055708[] = {0x000c0c00};
const u32 var7005570c[] = {0x00000c20};
const u32 var70055710[] = {0x000d0c00};
const u32 var70055714[] = {0x00000340};
const u32 var70055718[] = {0x000e0d00};
const u32 var7005571c[] = {0x00001a80};
const u32 var70055720[] = {0x000f0d00};
const u32 var70055724[] = {0x00001900};
const u32 var70055728[] = {0x01000300};
const u32 var7005572c[] = {0x00000006};
const u32 var70055730[] = {0x01010400};
const u32 var70055734[] = {0x00000002};
const u32 var70055738[] = {0x01020600};
const u32 var7005573c[] = {0x0000000c};
const u32 var70055740[] = {0x01030700};
const u32 var70055744[] = {0x00000064};
const u32 var70055748[] = {0x01040800};
const u32 var7005574c[] = {0x000000f8};
const u32 var70055750[] = {0x01050800};
const u32 var70055754[] = {0x00000058};
const u32 var70055758[] = {0x01060900};
const u32 var7005575c[] = {0x00000068};
const u32 var70055760[] = {0x01070900};
const u32 var70055764[] = {0x00000108};
const u32 var70055768[] = {0x01080900};
const u32 var7005576c[] = {0x000001f0};
const u32 var70055770[] = {0x01090900};
const u32 var70055774[] = {0x00000030};
const u32 var70055778[] = {0x010a0a00};
const u32 var7005577c[] = {0x00000010};
const u32 var70055780[] = {0x010b0a00};
const u32 var70055784[] = {0x00000060};
const u32 var70055788[] = {0x010c0b00};
const u32 var7005578c[] = {0x000007c0};
const u32 var70055790[] = {0x010d0c00};
const u32 var70055794[] = {0x00000c40};
const u32 var70055798[] = {0x010e0c00};
const u32 var7005579c[] = {0x00000680};
const u32 var700557a0[] = {0x010f0c00};
const u32 var700557a4[] = {0x00000700};
const u32 var700557a8[] = {0x02000600};
const u32 var700557ac[] = {0x0000003c};
const u32 var700557b0[] = {0x02010600};
const u32 var700557b4[] = {0x0000002c};
const u32 var700557b8[] = {0x02020700};
const u32 var700557bc[] = {0x00000074};
const u32 var700557c0[] = {0x02030800};
const u32 var700557c4[] = {0x00000024};
const u32 var700557c8[] = {0x02040900};
const u32 var700557cc[] = {0x000001b8};
const u32 var700557d0[] = {0x02050900};
const u32 var700557d4[] = {0x00000118};
const u32 var700557d8[] = {0x02060a00};
const u32 var700557dc[] = {0x000002c8};
const u32 var700557e0[] = {0x02070a00};
const u32 var700557e4[] = {0x00000208};
const u32 var700557e8[] = {0x02080900};
const u32 var700557ec[] = {0x00000170};
const u32 var700557f0[] = {0x02090a00};
const u32 var700557f4[] = {0x00000050};
const u32 var700557f8[] = {0x020a0a00};
const u32 var700557fc[] = {0x000001e0};
const u32 var70055800[] = {0x020b0b00};
const u32 var70055804[] = {0x000000a0};
const u32 var70055808[] = {0x020c0b00};
const u32 var7005580c[] = {0x000006c0};
const u32 var70055810[] = {0x020d0c00};
const u32 var70055814[] = {0x00000840};
const u32 var70055818[] = {0x020e0d00};
const u32 var7005581c[] = {0x00000a80};
const u32 var70055820[] = {0x020f0d00};
const u32 var70055824[] = {0x00000100};
const u32 var70055828[] = {0x03000700};
const u32 var7005582c[] = {0x00000034};
const u32 var70055830[] = {0x03010700};
const u32 var70055834[] = {0x00000014};
const u32 var70055838[] = {0x03020800};
const u32 var7005583c[] = {0x000000a4};
const u32 var70055840[] = {0x03030900};
const u32 var70055844[] = {0x00000178};
const u32 var70055848[] = {0x03040900};
const u32 var7005584c[] = {0x00000038};
const u32 var70055850[] = {0x03050a00};
const u32 var70055854[] = {0x000003c8};
const u32 var70055858[] = {0x03060a00};
const u32 var7005585c[] = {0x00000248};
const u32 var70055860[] = {0x03070a00};
const u32 var70055864[] = {0x00000008};
const u32 var70055868[] = {0x03080a00};
const u32 var7005586c[] = {0x00000350};
const u32 var70055870[] = {0x03090b00};
const u32 var70055874[] = {0x00000190};
const u32 var70055878[] = {0x030a0b00};
const u32 var7005587c[] = {0x000000e0};
const u32 var70055880[] = {0x030b0b00};
const u32 var70055884[] = {0x00000520};
const u32 var70055888[] = {0x030c0b00};
const u32 var7005588c[] = {0x000002c0};
const u32 var70055890[] = {0x030d0c00};
const u32 var70055894[] = {0x00000f80};
const u32 var70055898[] = {0x030e0d00};
const u32 var7005589c[] = {0x00001300};
const u32 var700558a0[] = {0x030f0d00};
const u32 var700558a4[] = {0x00000e00};
const u32 var700558a8[] = {0x04000800};
const u32 var700558ac[] = {0x000000c4};
const u32 var700558b0[] = {0x04010700};
const u32 var700558b4[] = {0x00000004};
const u32 var700558b8[] = {0x04020900};
const u32 var700558bc[] = {0x00000078};
const u32 var700558c0[] = {0x04030900};
const u32 var700558c4[] = {0x00000138};
const u32 var700558c8[] = {0x04040a00};
const u32 var700558cc[] = {0x00000218};
const u32 var700558d0[] = {0x04050a00};
const u32 var700558d4[] = {0x00000348};
const u32 var700558d8[] = {0x04060b00};
const u32 var700558dc[] = {0x00000270};
const u32 var700558e0[] = {0x04070b00};
const u32 var700558e4[] = {0x000006d0};
const u32 var700558e8[] = {0x04080a00};
const u32 var700558ec[] = {0x000001b0};
const u32 var700558f0[] = {0x04090b00};
const u32 var700558f4[] = {0x00000490};
const u32 var700558f8[] = {0x040a0b00};
const u32 var700558fc[] = {0x00000760};
const u32 var70055900[] = {0x040b0c00};
const u32 var70055904[] = {0x00000940};
const u32 var70055908[] = {0x040c0c00};
const u32 var7005590c[] = {0x000000c0};
const u32 var70055910[] = {0x040d0d00};
const u32 var70055914[] = {0x00001580};
const u32 var70055918[] = {0x040e0d00};
const u32 var7005591c[] = {0x00001d00};
const u32 var70055920[] = {0x040f0e00};
const u32 var70055924[] = {0x00000600};
const u32 var70055928[] = {0x05000900};
const u32 var7005592c[] = {0x000000b8};
const u32 var70055930[] = {0x05010800};
const u32 var70055934[] = {0x000000d8};
const u32 var70055938[] = {0x05020900};
const u32 var7005593c[] = {0x00000098};
const u32 var70055940[] = {0x05030a00};
const u32 var70055944[] = {0x00000018};
const u32 var70055948[] = {0x05040a00};
const u32 var7005594c[] = {0x000000c8};
const u32 var70055950[] = {0x05050a00};
const u32 var70055954[] = {0x00000188};
const u32 var70055958[] = {0x05060b00};
const u32 var7005595c[] = {0x000005d0};
const u32 var70055960[] = {0x05070b00};
const u32 var70055964[] = {0x00000150};
const u32 var70055968[] = {0x05080b00};
const u32 var7005596c[] = {0x00000590};
const u32 var70055970[] = {0x05090b00};
const u32 var70055974[] = {0x000002e0};
const u32 var70055978[] = {0x050a0c00};
const u32 var7005597c[] = {0x00000f20};
const u32 var70055980[] = {0x050b0b00};
const u32 var70055984[] = {0x000005c0};
const u32 var70055988[] = {0x050c0d00};
const u32 var7005598c[] = {0x00000a40};
const u32 var70055990[] = {0x050d0d00};
const u32 var70055994[] = {0x00001180};
const u32 var70055998[] = {0x050e0e00};
const u32 var7005599c[] = {0x00002500};
const u32 var700559a0[] = {0x050f0e00};
const u32 var700559a4[] = {0x00002200};
const u32 var700559a8[] = {0x06000900};
const u32 var700559ac[] = {0x000001e8};
const u32 var700559b0[] = {0x06010900};
const u32 var700559b4[] = {0x00000168};
const u32 var700559b8[] = {0x06020a00};
const u32 var700559bc[] = {0x000001c8};
const u32 var700559c0[] = {0x06030a00};
const u32 var700559c4[] = {0x00000148};
const u32 var700559c8[] = {0x06040b00};
const u32 var700559cc[] = {0x00000670};
const u32 var700559d0[] = {0x06050b00};
const u32 var700559d4[] = {0x000003d0};
const u32 var700559d8[] = {0x06060b00};
const u32 var700559dc[] = {0x000002d0};
const u32 var700559e0[] = {0x06070b00};
const u32 var700559e4[] = {0x00000790};
const u32 var700559e8[] = {0x06080b00};
const u32 var700559ec[] = {0x00000510};
const u32 var700559f0[] = {0x06090c00};
const u32 var700559f4[] = {0x00000ca0};
const u32 var700559f8[] = {0x060a0c00};
const u32 var700559fc[] = {0x00000e20};
const u32 var70055a00[] = {0x060b0c00};
const u32 var70055a04[] = {0x000004c0};
const u32 var70055a08[] = {0x060c0d00};
const u32 var70055a0c[] = {0x00001b80};
const u32 var70055a10[] = {0x060d0d00};
const u32 var70055a14[] = {0x00000c80};
const u32 var70055a18[] = {0x060e0e00};
const u32 var70055a1c[] = {0x00000900};
const u32 var70055a20[] = {0x060f0e00};
const u32 var70055a24[] = {0x00003c00};
const u32 var70055a28[] = {0x07000a00};
const u32 var70055a2c[] = {0x00000048};
const u32 var70055a30[] = {0x07010900};
const u32 var70055a34[] = {0x00000088};
const u32 var70055a38[] = {0x07020a00};
const u32 var70055a3c[] = {0x00000070};
const u32 var70055a40[] = {0x07030b00};
const u32 var70055a44[] = {0x000007d0};
const u32 var70055a48[] = {0x07040b00};
const u32 var70055a4c[] = {0x000001d0};
const u32 var70055a50[] = {0x07050b00};
const u32 var70055a54[] = {0x00000550};
const u32 var70055a58[] = {0x07060c00};
const u32 var70055a5c[] = {0x00000da0};
const u32 var70055a60[] = {0x07070c00};
const u32 var70055a64[] = {0x000005a0};
const u32 var70055a68[] = {0x07080c00};
const u32 var70055a6c[] = {0x000006a0};
const u32 var70055a70[] = {0x07090c00};
const u32 var70055a74[] = {0x00000920};
const u32 var70055a78[] = {0x070a0d00};
const u32 var70055a7c[] = {0x00001640};
const u32 var70055a80[] = {0x070b0d00};
const u32 var70055a84[] = {0x00001040};
const u32 var70055a88[] = {0x070c0d00};
const u32 var70055a8c[] = {0x00001980};
const u32 var70055a90[] = {0x070d0e00};
const u32 var70055a94[] = {0x00000d00};
const u32 var70055a98[] = {0x070e1000};
const u32 var70055a9c[] = {0x0000d400};
const u32 var70055aa0[] = {0x070f1000};
const u32 var70055aa4[] = {0x00005400};
const u32 var70055aa8[] = {0x08000900};
const u32 var70055aac[] = {0x000001a8};
const u32 var70055ab0[] = {0x08010800};
const u32 var70055ab4[] = {0x00000028};
const u32 var70055ab8[] = {0x08020900};
const u32 var70055abc[] = {0x000000f0};
const u32 var70055ac0[] = {0x08030a00};
const u32 var70055ac4[] = {0x000000d0};
const u32 var70055ac8[] = {0x08040a00};
const u32 var70055acc[] = {0x000003b0};
const u32 var70055ad0[] = {0x08050b00};
const u32 var70055ad4[] = {0x00000390};
const u32 var70055ad8[] = {0x08060b00};
const u32 var70055adc[] = {0x00000090};
const u32 var70055ae0[] = {0x08070c00};
const u32 var70055ae4[] = {0x00000ea0};
const u32 var70055ae8[] = {0x08080c00};
const u32 var70055aec[] = {0x00000720};
const u32 var70055af0[] = {0x08090c00};
const u32 var70055af4[] = {0x00000bc0};
const u32 var70055af8[] = {0x080a0c00};
const u32 var70055afc[] = {0x00000740};
const u32 var70055b00[] = {0x080b0d00};
const u32 var70055b04[] = {0x00000d80};
const u32 var70055b08[] = {0x080c0d00};
const u32 var70055b0c[] = {0x00001480};
const u32 var70055b10[] = {0x080d0e00};
const u32 var70055b14[] = {0x00001e00};
const u32 var70055b18[] = {0x080e0f00};
const u32 var70055b1c[] = {0x00001400};
const u32 var70055b20[] = {0x080f0f00};
const u32 var70055b24[] = {0x00000400};
const u32 var70055b28[] = {0x09000a00};
const u32 var70055b2c[] = {0x000002b0};
const u32 var70055b30[] = {0x09010900};
const u32 var70055b34[] = {0x00000130};
const u32 var70055b38[] = {0x09020a00};
const u32 var70055b3c[] = {0x00000250};
const u32 var70055b40[] = {0x09030a00};
const u32 var70055b44[] = {0x00000290};
const u32 var70055b48[] = {0x09040b00};
const u32 var70055b4c[] = {0x000001a0};
const u32 var70055b50[] = {0x09050b00};
const u32 var70055b54[] = {0x000006e0};
const u32 var70055b58[] = {0x09060b00};
const u32 var70055b5c[] = {0x00000360};
const u32 var70055b60[] = {0x09070d00};
const u32 var70055b64[] = {0x00001140};
const u32 var70055b68[] = {0x09080c00};
const u32 var70055b6c[] = {0x00000420};
const u32 var70055b70[] = {0x09090d00};
const u32 var70055b74[] = {0x00000640};
const u32 var70055b78[] = {0x090a0d00};
const u32 var70055b7c[] = {0x00001380};
const u32 var70055b80[] = {0x090b0e00};
const u32 var70055b84[] = {0x00001b00};
const u32 var70055b88[] = {0x090c0e00};
const u32 var70055b8c[] = {0x00002900};
const u32 var70055b90[] = {0x090d0e00};
const u32 var70055b94[] = {0x00001200};
const u32 var70055b98[] = {0x090e1000};
const u32 var70055b9c[] = {0x0000e400};
const u32 var70055ba0[] = {0x090f0f00};
const u32 var70055ba4[] = {0x00006800};
const u32 var70055ba8[] = {0x0a000a00};
const u32 var70055bac[] = {0x00000310};
const u32 var70055bb0[] = {0x0a010a00};
const u32 var70055bb4[] = {0x00000210};
const u32 var70055bb8[] = {0x0a020a00};
const u32 var70055bbc[] = {0x000003e0};
const u32 var70055bc0[] = {0x0a030b00};
const u32 var70055bc4[] = {0x000004e0};
const u32 var70055bc8[] = {0x0a040b00};
const u32 var70055bcc[] = {0x000002a0};
const u32 var70055bd0[] = {0x0a050c00};
const u32 var70055bd4[] = {0x000004a0};
const u32 var70055bd8[] = {0x0a060c00};
const u32 var70055bdc[] = {0x00000120};
const u32 var70055be0[] = {0x0a070d00};
const u32 var70055be4[] = {0x00000140};
const u32 var70055be8[] = {0x0a080c00};
const u32 var70055bec[] = {0x00000f40};
const u32 var70055bf0[] = {0x0a090d00};
const u32 var70055bf4[] = {0x00000b80};
const u32 var70055bf8[] = {0x0a0a0e00};
const u32 var70055bfc[] = {0x00003b00};
const u32 var70055c00[] = {0x0a0b0d00};
const u32 var70055c04[] = {0x00001500};
const u32 var70055c08[] = {0x0a0c0e00};
const u32 var70055c0c[] = {0x00001a00};
const u32 var70055c10[] = {0x0a0d0f00};
const u32 var70055c14[] = {0x00002c00};
const u32 var70055c18[] = {0x0a0e1000};
const u32 var70055c1c[] = {0x00006400};
const u32 var70055c20[] = {0x0a0f1100};
const u32 var70055c24[] = {0x0000d000};
const u32 var70055c28[] = {0x0b000b00};
const u32 var70055c2c[] = {0x00000560};
const u32 var70055c30[] = {0x0b010a00};
const u32 var70055c34[] = {0x00000260};
const u32 var70055c38[] = {0x0b020a00};
const u32 var70055c3c[] = {0x000003a0};
const u32 var70055c40[] = {0x0b030b00};
const u32 var70055c44[] = {0x00000320};
const u32 var70055c48[] = {0x0b040c00};
const u32 var70055c4c[] = {0x00000620};
const u32 var70055c50[] = {0x0b050c00};
const u32 var70055c54[] = {0x000003c0};
const u32 var70055c58[] = {0x0b060c00};
const u32 var70055c5c[] = {0x00000cc0};
const u32 var70055c60[] = {0x0b070c00};
const u32 var70055c64[] = {0x00000240};
const u32 var70055c68[] = {0x0b080d00};
const u32 var70055c6c[] = {0x00001d80};
const u32 var70055c70[] = {0x0b090d00};
const u32 var70055c74[] = {0x00000b00};
const u32 var70055c78[] = {0x0b0a0d00};
const u32 var70055c7c[] = {0x00000880};
const u32 var70055c80[] = {0x0b0b0e00};
const u32 var70055c84[] = {0x00003a00};
const u32 var70055c88[] = {0x0b0c0f00};
const u32 var70055c8c[] = {0x00006c00};
const u32 var70055c90[] = {0x0b0d0f00};
const u32 var70055c94[] = {0x00003800};
const u32 var70055c98[] = {0x0b0e0f00};
const u32 var70055c9c[] = {0x00004800};
const u32 var70055ca0[] = {0x0b0f1000};
const u32 var70055ca4[] = {0x0000e000};
const u32 var70055ca8[] = {0x0c000b00};
const u32 var70055cac[] = {0x00000220};
const u32 var70055cb0[] = {0x0c010b00};
const u32 var70055cb4[] = {0x00000020};
const u32 var70055cb8[] = {0x0c020b00};
const u32 var70055cbc[] = {0x000001c0};
const u32 var70055cc0[] = {0x0c030c00};
const u32 var70055cc4[] = {0x00000e40};
const u32 var70055cc8[] = {0x0c040c00};
const u32 var70055ccc[] = {0x000008c0};
const u32 var70055cd0[] = {0x0c050d00};
const u32 var70055cd4[] = {0x00001a40};
const u32 var70055cd8[] = {0x0c060c00};
const u32 var70055cdc[] = {0x00000780};
const u32 var70055ce0[] = {0x0c070d00};
const u32 var70055ce4[] = {0x00000580};
const u32 var70055ce8[] = {0x0c080e00};
const u32 var70055cec[] = {0x00000300};
const u32 var70055cf0[] = {0x0c090e00};
const u32 var70055cf4[] = {0x00000500};
const u32 var70055cf8[] = {0x0c0a0f00};
const u32 var70055cfc[] = {0x00001600};
const u32 var70055d00[] = {0x0c0b0f00};
const u32 var70055d04[] = {0x00001c00};
const u32 var70055d08[] = {0x0c0c0f00};
const u32 var70055d0c[] = {0x00002400};
const u32 var70055d10[] = {0x0c0d1000};
const u32 var70055d14[] = {0x00008800};
const u32 var70055d18[] = {0x0c0e1000};
const u32 var70055d1c[] = {0x00009000};
const u32 var70055d20[] = {0x0c0f1000};
const u32 var70055d24[] = {0x0000a000};
const u32 var70055d28[] = {0x0d000c00};
const u32 var70055d2c[] = {0x00000b40};
const u32 var70055d30[] = {0x0d010b00};
const u32 var70055d34[] = {0x00000540};
const u32 var70055d38[] = {0x0d020c00};
const u32 var70055d3c[] = {0x00000440};
const u32 var70055d40[] = {0x0d030d00};
const u32 var70055d44[] = {0x00000040};
const u32 var70055d48[] = {0x0d040d00};
const u32 var70055d4c[] = {0x00000380};
const u32 var70055d50[] = {0x0d050d00};
const u32 var70055d54[] = {0x00000980};
const u32 var70055d58[] = {0x0d060e00};
const u32 var70055d5c[] = {0x00002300};
const u32 var70055d60[] = {0x0d070e00};
const u32 var70055d64[] = {0x00002d00};
const u32 var70055d68[] = {0x0d080e00};
const u32 var70055d6c[] = {0x00003e00};
const u32 var70055d70[] = {0x0d090e00};
const u32 var70055d74[] = {0x00003200};
const u32 var70055d78[] = {0x0d0a0e00};
const u32 var70055d7c[] = {0x00000c00};
const u32 var70055d80[] = {0x0d0b0f00};
const u32 var70055d84[] = {0x00007800};
const u32 var70055d88[] = {0x0d0c1000};
const u32 var70055d8c[] = {0x00005000};
const u32 var70055d90[] = {0x0d0d0f00};
const u32 var70055d94[] = {0x00007000};
const u32 var70055d98[] = {0x0d0e1000};
const u32 var70055d9c[] = {0x00006000};
const u32 var70055da0[] = {0x0d0f1000};
const u32 var70055da4[] = {0x0000c000};
const u32 var70055da8[] = {0x0e000d00};
const u32 var70055dac[] = {0x00000180};
const u32 var70055db0[] = {0x0e010c00};
const u32 var70055db4[] = {0x00000e80};
const u32 var70055db8[] = {0x0e020c00};
const u32 var70055dbc[] = {0x00000280};
const u32 var70055dc0[] = {0x0e030d00};
const u32 var70055dc4[] = {0x00001c80};
const u32 var70055dc8[] = {0x0e040d00};
const u32 var70055dcc[] = {0x00000480};
const u32 var70055dd0[] = {0x0e050d00};
const u32 var70055dd4[] = {0x00001880};
const u32 var70055dd8[] = {0x0e060f00};
const u32 var70055ddc[] = {0x00005600};
const u32 var70055de0[] = {0x0e070e00};
const u32 var70055de4[] = {0x00002a00};
const u32 var70055de8[] = {0x0e080e00};
const u32 var70055dec[] = {0x00000200};
const u32 var70055df0[] = {0x0e091100};
const u32 var70055df4[] = {0x0001d000};
const u32 var70055df8[] = {0x0e0a0f00};
const u32 var70055dfc[] = {0x00005800};
const u32 var70055e00[] = {0x0e0b0f00};
const u32 var70055e04[] = {0x00002800};
const u32 var70055e08[] = {0x0e0c0f00};
const u32 var70055e0c[] = {0x00003000};
const u32 var70055e10[] = {0x0e0d1100};
const u32 var70055e14[] = {0x00010000};
const u32 var70055e18[] = {0x0e0e1000};
const u32 var70055e1c[] = {0x00002000};
const u32 var70055e20[] = {0x0e0f1000};
const u32 var70055e24[] = {0x00004000};
const u32 var70055e28[] = {0x0f000c00};
const u32 var70055e2c[] = {0x00000080};
const u32 var70055e30[] = {0x0f010c00};
const u32 var70055e34[] = {0x00000f00};
const u32 var70055e38[] = {0x0f020d00};
const u32 var70055e3c[] = {0x00001100};
const u32 var70055e40[] = {0x0f030e00};
const u32 var70055e44[] = {0x00003600};
const u32 var70055e48[] = {0x0f040e00};
const u32 var70055e4c[] = {0x00002600};
const u32 var70055e50[] = {0x0f050e00};
const u32 var70055e54[] = {0x00000a00};
const u32 var70055e58[] = {0x0f060f00};
const u32 var70055e5c[] = {0x00005c00};
const u32 var70055e60[] = {0x0f070e00};
const u32 var70055e64[] = {0x00003400};
const u32 var70055e68[] = {0x0f080f00};
const u32 var70055e6c[] = {0x00004400};
const u32 var70055e70[] = {0x0f090f00};
const u32 var70055e74[] = {0x00001800};
const u32 var70055e78[] = {0x0f0a1000};
const u32 var70055e7c[] = {0x00000800};
const u32 var70055e80[] = {0x0f0b1000};
const u32 var70055e84[] = {0x00001000};
const u32 var70055e88[] = {0x0f0c1300};
const u32 var70055e8c[] = {0x00040000};
const u32 var70055e90[] = {0x0f0d1200};
const u32 var70055e94[] = {0x00020000};
const u32 var70055e98[] = {0x0f0e1300};
const u32 var70055e9c[] = {0x00000000};
const u32 var70055ea0[] = {0x0f0f1000};
const u32 var70055ea4[] = {0x00008000};
const u32 var70055ea8[] = {0x64646400};
const u32 var70055eac[] = {0x00000000};
const u32 var70055eb0[] = {0x00000300};
const u32 var70055eb4[] = {0x00000007};
const u32 var70055eb8[] = {0x00010400};
const u32 var70055ebc[] = {0x00000003};
const u32 var70055ec0[] = {0x00020500};
const u32 var70055ec4[] = {0x00000009};
const u32 var70055ec8[] = {0x00030700};
const u32 var70055ecc[] = {0x00000056};
const u32 var70055ed0[] = {0x00040700};
const u32 var70055ed4[] = {0x0000007a};
const u32 var70055ed8[] = {0x00050800};
const u32 var70055edc[] = {0x00000032};
const u32 var70055ee0[] = {0x00060900};
const u32 var70055ee4[] = {0x0000007c};
const u32 var70055ee8[] = {0x00070900};
const u32 var70055eec[] = {0x0000006c};
const u32 var70055ef0[] = {0x00080900};
const u32 var70055ef4[] = {0x00000134};
const u32 var70055ef8[] = {0x00090a00};
const u32 var70055efc[] = {0x00000378};
const u32 var70055f00[] = {0x000a0a00};
const u32 var70055f04[] = {0x000000d8};
const u32 var70055f08[] = {0x000b0b00};
const u32 var70055f0c[] = {0x00000770};
const u32 var70055f10[] = {0x000c0b00};
const u32 var70055f14[] = {0x000006b0};
const u32 var70055f18[] = {0x000d0b00};
const u32 var70055f1c[] = {0x00000450};
const u32 var70055f20[] = {0x000e0c00};
const u32 var70055f24[] = {0x000005e0};
const u32 var70055f28[] = {0x000f0d00};
const u32 var70055f2c[] = {0x00001f80};
const u32 var70055f30[] = {0x01000400};
const u32 var70055f34[] = {0x0000000b};
const u32 var70055f38[] = {0x01010300};
const u32 var70055f3c[] = {0x00000005};
const u32 var70055f40[] = {0x01020500};
const u32 var70055f44[] = {0x00000001};
const u32 var70055f48[] = {0x01030600};
const u32 var70055f4c[] = {0x00000036};
const u32 var70055f50[] = {0x01040700};
const u32 var70055f54[] = {0x0000003a};
const u32 var70055f58[] = {0x01050700};
const u32 var70055f5c[] = {0x00000012};
const u32 var70055f60[] = {0x01060800};
const u32 var70055f64[] = {0x000000bc};
const u32 var70055f68[] = {0x01070800};
const u32 var70055f6c[] = {0x000000cc};
const u32 var70055f70[] = {0x01080800};
const u32 var70055f74[] = {0x00000054};
const u32 var70055f78[] = {0x01090900};
const u32 var70055f7c[] = {0x000000c4};
const u32 var70055f80[] = {0x010a0900};
const u32 var70055f84[] = {0x00000058};
const u32 var70055f88[] = {0x010b0a00};
const u32 var70055f8c[] = {0x00000328};
const u32 var70055f90[] = {0x010c0a00};
const u32 var70055f94[] = {0x00000208};
const u32 var70055f98[] = {0x010d0a00};
const u32 var70055f9c[] = {0x00000250};
const u32 var70055fa0[] = {0x010e0b00};
const u32 var70055fa4[] = {0x000006e0};
const u32 var70055fa8[] = {0x010f0b00};
const u32 var70055fac[] = {0x00000120};
const u32 var70055fb0[] = {0x02000500};
const u32 var70055fb4[] = {0x00000019};
const u32 var70055fb8[] = {0x02010500};
const u32 var70055fbc[] = {0x00000011};
const u32 var70055fc0[] = {0x02020500};
const u32 var70055fc4[] = {0x0000001e};
const u32 var70055fc8[] = {0x02030600};
const u32 var70055fcc[] = {0x00000006};
const u32 var70055fd0[] = {0x02040700};
const u32 var70055fd4[] = {0x0000004a};
const u32 var70055fd8[] = {0x02050700};
const u32 var70055fdc[] = {0x00000022};
const u32 var70055fe0[] = {0x02060800};
const u32 var70055fe4[] = {0x000000dc};
const u32 var70055fe8[] = {0x02070800};
const u32 var70055fec[] = {0x0000000c};
const u32 var70055ff0[] = {0x02080800};
const u32 var70055ff4[] = {0x00000014};
const u32 var70055ff8[] = {0x02090900};
const u32 var70055ffc[] = {0x00000004};
const u32 var70056000[] = {0x020a0900};
const u32 var70056004[] = {0x00000098};
const u32 var70056008[] = {0x020b0a00};
const u32 var7005600c[] = {0x000001c8};
const u32 var70056010[] = {0x020c0a00};
const u32 var70056014[] = {0x000001f0};
const u32 var70056018[] = {0x020d0b00};
const u32 var7005601c[] = {0x00000050};
const u32 var70056020[] = {0x020e0b00};
const u32 var70056024[] = {0x000000e0};
const u32 var70056028[] = {0x020f0b00};
const u32 var7005602c[] = {0x00000420};
const u32 var70056030[] = {0x03000600};
const u32 var70056034[] = {0x0000002e};
const u32 var70056038[] = {0x03010600};
const u32 var7005603c[] = {0x0000000e};
const u32 var70056040[] = {0x03020600};
const u32 var70056044[] = {0x00000026};
const u32 var70056048[] = {0x03030700};
const u32 var7005604c[] = {0x0000006a};
const u32 var70056050[] = {0x03040700};
const u32 var70056054[] = {0x00000072};
const u32 var70056058[] = {0x03050800};
const u32 var7005605c[] = {0x000000fc};
const u32 var70056060[] = {0x03060800};
const u32 var70056064[] = {0x000000ec};
const u32 var70056068[] = {0x03070900};
const u32 var7005606c[] = {0x00000174};
const u32 var70056070[] = {0x03080900};
const u32 var70056074[] = {0x00000064};
const u32 var70056078[] = {0x03090900};
const u32 var7005607c[] = {0x000001b8};
const u32 var70056080[] = {0x030a0a00};
const u32 var70056084[] = {0x000002e8};
const u32 var70056088[] = {0x030b0a00};
const u32 var7005608c[] = {0x00000048};
const u32 var70056090[] = {0x030c0a00};
const u32 var70056094[] = {0x000001b0};
const u32 var70056098[] = {0x030d0b00};
const u32 var7005609c[] = {0x00000690};
const u32 var700560a0[] = {0x030e0b00};
const u32 var700560a4[] = {0x00000260};
const u32 var700560a8[] = {0x030f0b00};
const u32 var700560ac[] = {0x000005c0};
const u32 var700560b0[] = {0x04000700};
const u32 var700560b4[] = {0x00000016};
const u32 var700560b8[] = {0x04010600};
const u32 var700560bc[] = {0x0000001a};
const u32 var700560c0[] = {0x04020700};
const u32 var700560c4[] = {0x0000002a};
const u32 var700560c8[] = {0x04030700};
const u32 var700560cc[] = {0x0000000a};
const u32 var700560d0[] = {0x04040800};
const u32 var700560d4[] = {0x000000c2};
const u32 var700560d8[] = {0x04050800};
const u32 var700560dc[] = {0x0000009c};
const u32 var700560e0[] = {0x04060900};
const u32 var700560e4[] = {0x000001f4};
const u32 var700560e8[] = {0x04070900};
const u32 var700560ec[] = {0x000001e4};
const u32 var700560f0[] = {0x04080900};
const u32 var700560f4[] = {0x00000024};
const u32 var700560f8[] = {0x04090900};
const u32 var700560fc[] = {0x00000138};
const u32 var70056100[] = {0x040a0a00};
const u32 var70056104[] = {0x00000268};
const u32 var70056108[] = {0x040b0a00};
const u32 var7005610c[] = {0x00000288};
const u32 var70056110[] = {0x040c0a00};
const u32 var70056114[] = {0x00000230};
const u32 var70056118[] = {0x040d0b00};
const u32 var7005611c[] = {0x00000210};
const u32 var70056120[] = {0x040e0b00};
const u32 var70056124[] = {0x000003a0};
const u32 var70056128[] = {0x040f0b00};
const u32 var7005612c[] = {0x000006c0};
const u32 var70056130[] = {0x05000800};
const u32 var70056134[] = {0x000000b2};
const u32 var70056138[] = {0x05010700};
const u32 var7005613c[] = {0x00000052};
const u32 var70056140[] = {0x05020700};
const u32 var70056144[] = {0x00000062};
const u32 var70056148[] = {0x05030800};
const u32 var7005614c[] = {0x00000042};
const u32 var70056150[] = {0x05040800};
const u32 var70056154[] = {0x0000005c};
const u32 var70056158[] = {0x05050800};
const u32 var7005615c[] = {0x0000002c};
const u32 var70056160[] = {0x05060900};
const u32 var70056164[] = {0x000001b4};
const u32 var70056168[] = {0x05070900};
const u32 var7005616c[] = {0x000000a4};
const u32 var70056170[] = {0x05080900};
const u32 var70056174[] = {0x000000f8};
const u32 var70056178[] = {0x05090900};
const u32 var7005617c[] = {0x00000018};
const u32 var70056180[] = {0x050a0a00};
const u32 var70056184[] = {0x000003c8};
const u32 var70056188[] = {0x050b0a00};
const u32 var7005618c[] = {0x000003f0};
const u32 var70056190[] = {0x050c0b00};
const u32 var70056194[] = {0x000002d0};
const u32 var70056198[] = {0x050d0b00};
const u32 var7005619c[] = {0x000003e0};
const u32 var700561a0[] = {0x050e0b00};
const u32 var700561a4[] = {0x000000a0};
const u32 var700561a8[] = {0x050f0c00};
const u32 var700561ac[] = {0x00000640};
const u32 var700561b0[] = {0x06000900};
const u32 var700561b4[] = {0x0000017c};
const u32 var700561b8[] = {0x06010700};
const u32 var700561bc[] = {0x00000002};
const u32 var700561c0[] = {0x06020800};
const u32 var700561c4[] = {0x0000003c};
const u32 var700561c8[] = {0x06030800};
const u32 var700561cc[] = {0x0000001c};
const u32 var700561d0[] = {0x06040800};
const u32 var700561d4[] = {0x0000004c};
const u32 var700561d8[] = {0x06050900};
const u32 var700561dc[] = {0x00000074};
const u32 var700561e0[] = {0x06060900};
const u32 var700561e4[] = {0x000000e4};
const u32 var700561e8[] = {0x06070900};
const u32 var700561ec[] = {0x00000104};
const u32 var700561f0[] = {0x06080900};
const u32 var700561f4[] = {0x000001d8};
const u32 var700561f8[] = {0x06090a00};
const u32 var700561fc[] = {0x000003a8};
const u32 var70056200[] = {0x060a0a00};
const u32 var70056204[] = {0x00000388};
const u32 var70056208[] = {0x060b0a00};
const u32 var7005620c[] = {0x00000330};
const u32 var70056210[] = {0x060c0b00};
const u32 var70056214[] = {0x00000490};
const u32 var70056218[] = {0x060d0b00};
const u32 var7005621c[] = {0x00000660};
const u32 var70056220[] = {0x060e0c00};
const u32 var70056224[] = {0x00000620};
const u32 var70056228[] = {0x060f0c00};
const u32 var7005622c[] = {0x00000780};
const u32 var70056230[] = {0x07000900};
const u32 var70056234[] = {0x0000016c};
const u32 var70056238[] = {0x07010800};
const u32 var7005623c[] = {0x000000ac};
const u32 var70056240[] = {0x07020800};
const u32 var70056244[] = {0x0000008c};
const u32 var70056248[] = {0x07030900};
const u32 var7005624c[] = {0x000000f4};
const u32 var70056250[] = {0x07040900};
const u32 var70056254[] = {0x00000034};
const u32 var70056258[] = {0x07050900};
const u32 var7005625c[] = {0x000001a4};
const u32 var70056260[] = {0x07060900};
const u32 var70056264[] = {0x00000084};
const u32 var70056268[] = {0x07070a00};
const u32 var7005626c[] = {0x00000178};
const u32 var70056270[] = {0x07080a00};
const u32 var70056274[] = {0x00000368};
const u32 var70056278[] = {0x07090a00};
const u32 var7005627c[] = {0x00000248};
const u32 var70056280[] = {0x070a0a00};
const u32 var70056284[] = {0x00000070};
const u32 var70056288[] = {0x070b0a00};
const u32 var7005628c[] = {0x00000150};
const u32 var70056290[] = {0x070c0b00};
const u32 var70056294[] = {0x00000010};
const u32 var70056298[] = {0x070d0b00};
const u32 var7005629c[] = {0x000001a0};
const u32 var700562a0[] = {0x070e0b00};
const u32 var700562a4[] = {0x00000540};
const u32 var700562a8[] = {0x070f0c00};
const u32 var700562ac[] = {0x00000980};
const u32 var700562b0[] = {0x08000900};
const u32 var700562b4[] = {0x000000b4};
const u32 var700562b8[] = {0x08010800};
const u32 var700562bc[] = {0x000000d4};
const u32 var700562c0[] = {0x08020800};
const u32 var700562c4[] = {0x00000094};
const u32 var700562c8[] = {0x08030900};
const u32 var700562cc[] = {0x00000164};
const u32 var700562d0[] = {0x08040900};
const u32 var700562d4[] = {0x00000124};
const u32 var700562d8[] = {0x08050900};
const u32 var700562dc[] = {0x000001f8};
const u32 var700562e0[] = {0x08060900};
const u32 var700562e4[] = {0x00000038};
const u32 var700562e8[] = {0x08070a00};
const u32 var700562ec[] = {0x000000e8};
const u32 var700562f0[] = {0x08080a00};
const u32 var700562f4[] = {0x000002c8};
const u32 var700562f8[] = {0x08090a00};
const u32 var700562fc[] = {0x00000108};
const u32 var70056300[] = {0x080a0a00};
const u32 var70056304[] = {0x000003d0};
const u32 var70056308[] = {0x080b0b00};
const u32 var7005630c[] = {0x00000610};
const u32 var70056310[] = {0x080c0b00};
const u32 var70056314[] = {0x00000060};
const u32 var70056318[] = {0x080d0c00};
const u32 var7005631c[] = {0x00000ac0};
const u32 var70056320[] = {0x080e0c00};
const u32 var70056324[] = {0x00000240};
const u32 var70056328[] = {0x080f0c00};
const u32 var7005632c[] = {0x00000280};
const u32 var70056330[] = {0x09000900};
const u32 var70056334[] = {0x000001c4};
const u32 var70056338[] = {0x09010800};
const u32 var7005633c[] = {0x00000044};
const u32 var70056340[] = {0x09020900};
const u32 var70056344[] = {0x00000184};
const u32 var70056348[] = {0x09030900};
const u32 var7005634c[] = {0x00000078};
const u32 var70056350[] = {0x09040900};
const u32 var70056354[] = {0x000000b8};
const u32 var70056358[] = {0x09050900};
const u32 var7005635c[] = {0x00000118};
const u32 var70056360[] = {0x09060a00};
const u32 var70056364[] = {0x00000068};
const u32 var70056368[] = {0x09070a00};
const u32 var7005636c[] = {0x000000c8};
const u32 var70056370[] = {0x09080a00};
const u32 var70056374[] = {0x00000308};
const u32 var70056378[] = {0x09090b00};
const u32 var7005637c[] = {0x000002b0};
const u32 var70056380[] = {0x090a0b00};
const u32 var70056384[] = {0x00000710};
const u32 var70056388[] = {0x090b0b00};
const u32 var7005638c[] = {0x00000360};
const u32 var70056390[] = {0x090c0b00};
const u32 var70056394[] = {0x00000320};
const u32 var70056398[] = {0x090d0c00};
const u32 var7005639c[] = {0x00000e40};
const u32 var700563a0[] = {0x090e0c00};
const u32 var700563a4[] = {0x00000e80};
const u32 var700563a8[] = {0x090f0c00};
const u32 var700563ac[] = {0x00000f00};
const u32 var700563b0[] = {0x0a000a00};
const u32 var700563b4[] = {0x000002d8};
const u32 var700563b8[] = {0x0a010900};
const u32 var700563bc[] = {0x00000158};
const u32 var700563c0[] = {0x0a020900};
const u32 var700563c4[] = {0x00000198};
const u32 var700563c8[] = {0x0a030900};
const u32 var700563cc[] = {0x000001e8};
const u32 var700563d0[] = {0x0a040a00};
const u32 var700563d4[] = {0x00000168};
const u32 var700563d8[] = {0x0a050a00};
const u32 var700563dc[] = {0x00000128};
const u32 var700563e0[] = {0x0a060a00};
const u32 var700563e4[] = {0x00000170};
const u32 var700563e8[] = {0x0a070a00};
const u32 var700563ec[] = {0x00000270};
const u32 var700563f0[] = {0x0a080a00};
const u32 var700563f4[] = {0x00000030};
const u32 var700563f8[] = {0x0a090b00};
const u32 var700563fc[] = {0x00000090};
const u32 var70056400[] = {0x0a0a0b00};
const u32 var70056404[] = {0x000004e0};
const u32 var70056408[] = {0x0a0b0b00};
const u32 var7005640c[] = {0x000004a0};
const u32 var70056410[] = {0x0a0c0b00};
const u32 var70056414[] = {0x00000740};
const u32 var70056418[] = {0x0a0d0c00};
const u32 var7005641c[] = {0x00000d80};
const u32 var70056420[] = {0x0a0e0d00};
const u32 var70056424[] = {0x00000f80};
const u32 var70056428[] = {0x0a0f0c00};
const u32 var7005642c[] = {0x00000900};
const u32 var70056430[] = {0x0b000a00};
const u32 var70056434[] = {0x000001a8};
const u32 var70056438[] = {0x0b010900};
const u32 var7005643c[] = {0x000000a8};
const u32 var70056440[] = {0x0b020900};
const u32 var70056444[] = {0x00000028};
const u32 var70056448[] = {0x0b030900};
const u32 var7005644c[] = {0x00000148};
const u32 var70056450[] = {0x0b040a00};
const u32 var70056454[] = {0x00000188};
const u32 var70056458[] = {0x0b050a00};
const u32 var7005645c[] = {0x00000008};
const u32 var70056460[] = {0x0b060a00};
const u32 var70056464[] = {0x000000b0};
const u32 var70056468[] = {0x0b070a00};
const u32 var7005646c[] = {0x00000350};
const u32 var70056470[] = {0x0b080b00};
const u32 var70056474[] = {0x00000310};
const u32 var70056478[] = {0x0b090b00};
const u32 var7005647c[] = {0x00000760};
const u32 var70056480[] = {0x0b0a0b00};
const u32 var70056484[] = {0x000002a0};
const u32 var70056488[] = {0x0b0b0b00};
const u32 var7005648c[] = {0x000004c0};
const u32 var70056490[] = {0x0b0c0c00};
const u32 var70056494[] = {0x00000b80};
const u32 var70056498[] = {0x0b0d0c00};
const u32 var7005649c[] = {0x00000480};
const u32 var700564a0[] = {0x0b0e0c00};
const u32 var700564a4[] = {0x00000d00};
const u32 var700564a8[] = {0x0b0f0d00};
const u32 var700564ac[] = {0x00001a00};
const u32 var700564b0[] = {0x0c000b00};
const u32 var700564b4[] = {0x00000370};
const u32 var700564b8[] = {0x0c010a00};
const u32 var700564bc[] = {0x00000088};
const u32 var700564c0[] = {0x0c020900};
const u32 var700564c4[] = {0x000000f0};
const u32 var700564c8[] = {0x0c030a00};
const u32 var700564cc[] = {0x000003b0};
const u32 var700564d0[] = {0x0c040a00};
const u32 var700564d4[] = {0x00000130};
const u32 var700564d8[] = {0x0c050a00};
const u32 var700564dc[] = {0x000001d0};
const u32 var700564e0[] = {0x0c060b00};
const u32 var700564e4[] = {0x00000290};
const u32 var700564e8[] = {0x0c070b00};
const u32 var700564ec[] = {0x00000410};
const u32 var700564f0[] = {0x0c080b00};
const u32 var700564f4[] = {0x00000460};
const u32 var700564f8[] = {0x0c090b00};
const u32 var700564fc[] = {0x00000720};
const u32 var70056500[] = {0x0c0a0b00};
const u32 var70056504[] = {0x000000c0};
const u32 var70056508[] = {0x0c0b0b00};
const u32 var7005650c[] = {0x00000040};
const u32 var70056510[] = {0x0c0c0c00};
const u32 var70056514[] = {0x00000680};
const u32 var70056518[] = {0x0c0d0c00};
const u32 var7005651c[] = {0x00000b00};
const u32 var70056520[] = {0x0c0e0d00};
const u32 var70056524[] = {0x00000e00};
const u32 var70056528[] = {0x0c0f0d00};
const u32 var7005652c[] = {0x00001c00};
const u32 var70056530[] = {0x0d000b00};
const u32 var70056534[] = {0x000006d0};
const u32 var70056538[] = {0x0d010a00};
const u32 var7005653c[] = {0x000000d0};
const u32 var70056540[] = {0x0d020a00};
const u32 var70056544[] = {0x00000390};
const u32 var70056548[] = {0x0d030a00};
const u32 var7005654c[] = {0x00000190};
const u32 var70056550[] = {0x0d040a00};
const u32 var70056554[] = {0x00000110};
const u32 var70056558[] = {0x0d050b00};
const u32 var7005655c[] = {0x000007e0};
const u32 var70056560[] = {0x0d060b00};
const u32 var70056564[] = {0x00000160};
const u32 var70056568[] = {0x0d070b00};
const u32 var7005656c[] = {0x000005a0};
const u32 var70056570[] = {0x0d080b00};
const u32 var70056574[] = {0x000007c0};
const u32 var70056578[] = {0x0d090c00};
const u32 var7005657c[] = {0x000002c0};
const u32 var70056580[] = {0x0d0a0c00};
const u32 var70056584[] = {0x00000380};
const u32 var70056588[] = {0x0d0b0c00};
const u32 var7005658c[] = {0x00000c80};
const u32 var70056590[] = {0x0d0c0c00};
const u32 var70056594[] = {0x00000700};
const u32 var70056598[] = {0x0d0d0c00};
const u32 var7005659c[] = {0x00000100};
const u32 var700565a0[] = {0x0d0e0d00};
const u32 var700565a4[] = {0x00001200};
const u32 var700565a8[] = {0x0d0f0d00};
const u32 var700565ac[] = {0x00001800};
const u32 var700565b0[] = {0x0e000c00};
const u32 var700565b4[] = {0x00000de0};
const u32 var700565b8[] = {0x0e010b00};
const u32 var700565bc[] = {0x000001e0};
const u32 var700565c0[] = {0x0e020b00};
const u32 var700565c4[] = {0x000002e0};
const u32 var700565c8[] = {0x0e030b00};
const u32 var700565cc[] = {0x00000560};
const u32 var700565d0[] = {0x0e040b00};
const u32 var700565d4[] = {0x000007a0};
const u32 var700565d8[] = {0x0e050b00};
const u32 var700565dc[] = {0x000006a0};
const u32 var700565e0[] = {0x0e060b00};
const u32 var700565e4[] = {0x00000020};
const u32 var700565e8[] = {0x0e070b00};
const u32 var700565ec[] = {0x00000340};
const u32 var700565f0[] = {0x0e080c00};
const u32 var700565f4[] = {0x00000a40};
const u32 var700565f8[] = {0x0e090c00};
const u32 var700565fc[] = {0x00000180};
const u32 var70056600[] = {0x0e0a0c00};
const u32 var70056604[] = {0x00000880};
const u32 var70056608[] = {0x0e0b0c00};
const u32 var7005660c[] = {0x00000300};
const u32 var70056610[] = {0x0e0c0d00};
const u32 var70056614[] = {0x00001e00};
const u32 var70056618[] = {0x0e0d0d00};
const u32 var7005661c[] = {0x00000a00};
const u32 var70056620[] = {0x0e0e0c00};
const u32 var70056624[] = {0x00000400};
const u32 var70056628[] = {0x0e0f0d00};
const u32 var7005662c[] = {0x00001000};
const u32 var70056630[] = {0x0f000c00};
const u32 var70056634[] = {0x00000e20};
const u32 var70056638[] = {0x0f010b00};
const u32 var7005663c[] = {0x00000520};
const u32 var70056640[] = {0x0f020b00};
const u32 var70056644[] = {0x00000220};
const u32 var70056648[] = {0x0f030b00};
const u32 var7005664c[] = {0x000003c0};
const u32 var70056650[] = {0x0f040b00};
const u32 var70056654[] = {0x000001c0};
const u32 var70056658[] = {0x0f050b00};
const u32 var7005665c[] = {0x00000140};
const u32 var70056660[] = {0x0f060b00};
const u32 var70056664[] = {0x00000440};
const u32 var70056668[] = {0x0f070c00};
const u32 var7005666c[] = {0x00000580};
const u32 var70056670[] = {0x0f080c00};
const u32 var70056674[] = {0x00000a80};
const u32 var70056678[] = {0x0f090c00};
const u32 var7005667c[] = {0x00000080};
const u32 var70056680[] = {0x0f0a0c00};
const u32 var70056684[] = {0x00000500};
const u32 var70056688[] = {0x0f0b0c00};
const u32 var7005668c[] = {0x00000600};
const u32 var70056690[] = {0x0f0c0d00};
const u32 var70056694[] = {0x00000200};
const u32 var70056698[] = {0x0f0d0d00};
const u32 var7005669c[] = {0x00000c00};
const u32 var700566a0[] = {0x0f0e0d00};
const u32 var700566a4[] = {0x00000800};
const u32 var700566a8[] = {0x0f0f0d00};
const u32 var700566ac[] = {0x00000000};
const u32 var700566b0[] = {0x64646400};
const u32 var700566b4[] = {0x00000000};
const u32 var700566b8[] = {0x00000100};
const u32 var700566bc[] = {0x00000001};
const u32 var700566c0[] = {0x00010400};
const u32 var700566c4[] = {0x0000000a};
const u32 var700566c8[] = {0x00020600};
const u32 var700566cc[] = {0x0000001c};
const u32 var700566d0[] = {0x00030800};
const u32 var700566d4[] = {0x00000034};
const u32 var700566d8[] = {0x00040900};
const u32 var700566dc[] = {0x000000a4};
const u32 var700566e0[] = {0x00050900};
const u32 var700566e4[] = {0x000001f8};
const u32 var700566e8[] = {0x00060a00};
const u32 var700566ec[] = {0x000001d8};
const u32 var700566f0[] = {0x00070a00};
const u32 var700566f4[] = {0x000002e8};
const u32 var700566f8[] = {0x00080b00};
const u32 var700566fc[] = {0x000001a8};
const u32 var70056700[] = {0x00090b00};
const u32 var70056704[] = {0x00000548};
const u32 var70056708[] = {0x000a0b00};
const u32 var7005670c[] = {0x00000288};
const u32 var70056710[] = {0x000b0c00};
const u32 var70056714[] = {0x000004f0};
const u32 var70056718[] = {0x000c0c00};
const u32 var7005671c[] = {0x00000870};
const u32 var70056720[] = {0x000d0c00};
const u32 var70056724[] = {0x00000c30};
const u32 var70056728[] = {0x000e0d00};
const u32 var7005672c[] = {0x000003d0};
const u32 var70056730[] = {0x000f0900};
const u32 var70056734[] = {0x00000110};
const u32 var70056738[] = {0x01000300};
const u32 var7005673c[] = {0x00000006};
const u32 var70056740[] = {0x01010400};
const u32 var70056744[] = {0x00000002};
const u32 var70056748[] = {0x01020600};
const u32 var7005674c[] = {0x0000000c};
const u32 var70056750[] = {0x01030700};
const u32 var70056754[] = {0x00000014};
const u32 var70056758[] = {0x01040800};
const u32 var7005675c[] = {0x000000c4};
const u32 var70056760[] = {0x01050900};
const u32 var70056764[] = {0x000000f8};
const u32 var70056768[] = {0x01060900};
const u32 var7005676c[] = {0x00000158};
const u32 var70056770[] = {0x01070900};
const u32 var70056774[] = {0x000001e8};
const u32 var70056778[] = {0x01080a00};
const u32 var7005677c[] = {0x00000328};
const u32 var70056780[] = {0x01090a00};
const u32 var70056784[] = {0x00000348};
const u32 var70056788[] = {0x010a0a00};
const u32 var7005678c[] = {0x00000088};
const u32 var70056790[] = {0x010b0b00};
const u32 var70056794[] = {0x00000770};
const u32 var70056798[] = {0x010c0c00};
const u32 var7005679c[] = {0x00000930};
const u32 var700567a0[] = {0x010d0b00};
const u32 var700567a4[] = {0x000006b0};
const u32 var700567a8[] = {0x010e0c00};
const u32 var700567ac[] = {0x00000f30};
const u32 var700567b0[] = {0x010f0800};
const u32 var700567b4[] = {0x00000090};
const u32 var700567b8[] = {0x02000600};
const u32 var700567bc[] = {0x0000003c};
const u32 var700567c0[] = {0x02010600};
const u32 var700567c4[] = {0x0000002c};
const u32 var700567c8[] = {0x02020700};
const u32 var700567cc[] = {0x00000074};
const u32 var700567d0[] = {0x02030800};
const u32 var700567d4[] = {0x00000064};
const u32 var700567d8[] = {0x02040900};
const u32 var700567dc[] = {0x00000184};
const u32 var700567e0[] = {0x02050900};
const u32 var700567e4[] = {0x000000b8};
const u32 var700567e8[] = {0x02060a00};
const u32 var700567ec[] = {0x00000398};
const u32 var700567f0[] = {0x02070a00};
const u32 var700567f4[] = {0x00000168};
const u32 var700567f8[] = {0x02080b00};
const u32 var700567fc[] = {0x00000428};
const u32 var70056800[] = {0x02090a00};
const u32 var70056804[] = {0x00000048};
const u32 var70056808[] = {0x020a0b00};
const u32 var7005680c[] = {0x000007f0};
const u32 var70056810[] = {0x020b0b00};
const u32 var70056814[] = {0x00000570};
const u32 var70056818[] = {0x020c0b00};
const u32 var7005681c[] = {0x000003b0};
const u32 var70056820[] = {0x020d0c00};
const u32 var70056824[] = {0x000008b0};
const u32 var70056828[] = {0x020e0c00};
const u32 var7005682c[] = {0x00000730};
const u32 var70056830[] = {0x020f0900};
const u32 var70056834[] = {0x00000010};
const u32 var70056838[] = {0x03000800};
const u32 var7005683c[] = {0x000000b4};
const u32 var70056840[] = {0x03010700};
const u32 var70056844[] = {0x00000054};
const u32 var70056848[] = {0x03020800};
const u32 var7005684c[] = {0x000000e4};
const u32 var70056850[] = {0x03030900};
const u32 var70056854[] = {0x00000144};
const u32 var70056858[] = {0x03040900};
const u32 var7005685c[] = {0x00000004};
const u32 var70056860[] = {0x03050a00};
const u32 var70056864[] = {0x00000138};
const u32 var70056868[] = {0x03060a00};
const u32 var7005686c[] = {0x00000318};
const u32 var70056870[] = {0x03070a00};
const u32 var70056874[] = {0x000003a8};
const u32 var70056878[] = {0x03080b00};
const u32 var7005687c[] = {0x000003c8};
const u32 var70056880[] = {0x03090b00};
const u32 var70056884[] = {0x00000188};
const u32 var70056888[] = {0x030a0c00};
const u32 var7005688c[] = {0x000003f0};
const u32 var70056890[] = {0x030b0c00};
const u32 var70056894[] = {0x000002b0};
const u32 var70056898[] = {0x030c0c00};
const u32 var7005689c[] = {0x00000e30};
const u32 var700568a0[] = {0x030d0d00};
const u32 var700568a4[] = {0x00001830};
const u32 var700568a8[] = {0x030e0d00};
const u32 var700568ac[] = {0x000016d0};
const u32 var700568b0[] = {0x030f0a00};
const u32 var700568b4[] = {0x00000160};
const u32 var700568b8[] = {0x04000900};
const u32 var700568bc[] = {0x000001a4};
const u32 var700568c0[] = {0x04010800};
const u32 var700568c4[] = {0x00000024};
const u32 var700568c8[] = {0x04020900};
const u32 var700568cc[] = {0x00000044};
const u32 var700568d0[] = {0x04030900};
const u32 var700568d4[] = {0x00000104};
const u32 var700568d8[] = {0x04040a00};
const u32 var700568dc[] = {0x00000338};
const u32 var700568e0[] = {0x04050a00};
const u32 var700568e4[] = {0x00000298};
const u32 var700568e8[] = {0x04060b00};
const u32 var700568ec[] = {0x00000668};
const u32 var700568f0[] = {0x04070b00};
const u32 var700568f4[] = {0x00000128};
const u32 var700568f8[] = {0x04080b00};
const u32 var700568fc[] = {0x000006c8};
const u32 var70056900[] = {0x04090c00};
const u32 var70056904[] = {0x00000108};
const u32 var70056908[] = {0x040a0c00};
const u32 var7005690c[] = {0x000006f0};
const u32 var70056910[] = {0x040b0c00};
const u32 var70056914[] = {0x00000470};
const u32 var70056918[] = {0x040c0d00};
const u32 var7005691c[] = {0x00001a30};
const u32 var70056920[] = {0x040d0d00};
const u32 var70056924[] = {0x00000fd0};
const u32 var70056928[] = {0x040e0d00};
const u32 var7005692c[] = {0x00000ad0};
const u32 var70056930[] = {0x040f0900};
const u32 var70056934[] = {0x00000120};
const u32 var70056938[] = {0x05000900};
const u32 var7005693c[] = {0x00000084};
const u32 var70056940[] = {0x05010800};
const u32 var70056944[] = {0x00000078};
const u32 var70056948[] = {0x05020900};
const u32 var7005694c[] = {0x000001b8};
const u32 var70056950[] = {0x05030900};
const u32 var70056954[] = {0x00000038};
const u32 var70056958[] = {0x05040a00};
const u32 var7005695c[] = {0x00000198};
const u32 var70056960[] = {0x05050b00};
const u32 var70056964[] = {0x000004e8};
const u32 var70056968[] = {0x05060b00};
const u32 var7005696c[] = {0x000005a8};
const u32 var70056970[] = {0x05070c00};
const u32 var70056974[] = {0x00000908};
const u32 var70056978[] = {0x05080b00};
const u32 var7005697c[] = {0x00000388};
const u32 var70056980[] = {0x05090c00};
const u32 var70056984[] = {0x00000bf0};
const u32 var70056988[] = {0x050a0c00};
const u32 var7005698c[] = {0x00000170};
const u32 var70056990[] = {0x050b0d00};
const u32 var70056994[] = {0x00000130};
const u32 var70056998[] = {0x050c0d00};
const u32 var7005699c[] = {0x00000430};
const u32 var700569a0[] = {0x050d0d00};
const u32 var700569a4[] = {0x00000bd0};
const u32 var700569a8[] = {0x050e0e00};
const u32 var700569ac[] = {0x00002f60};
const u32 var700569b0[] = {0x050f0a00};
const u32 var700569b4[] = {0x00000020};
const u32 var700569b8[] = {0x06000a00};
const u32 var700569bc[] = {0x000003d8};
const u32 var700569c0[] = {0x06010900};
const u32 var700569c4[] = {0x000000d8};
const u32 var700569c8[] = {0x06020900};
const u32 var700569cc[] = {0x00000058};
const u32 var700569d0[] = {0x06030a00};
const u32 var700569d4[] = {0x00000098};
const u32 var700569d8[] = {0x06040b00};
const u32 var700569dc[] = {0x000000e8};
const u32 var700569e0[] = {0x06050b00};
const u32 var700569e4[] = {0x00000268};
const u32 var700569e8[] = {0x06060b00};
const u32 var700569ec[] = {0x00000028};
const u32 var700569f0[] = {0x06070b00};
const u32 var700569f4[] = {0x00000508};
const u32 var700569f8[] = {0x06080c00};
const u32 var700569fc[] = {0x00000808};
const u32 var70056a00[] = {0x06090c00};
const u32 var70056a04[] = {0x000002f0};
const u32 var70056a08[] = {0x060a0c00};
const u32 var70056a0c[] = {0x00000270};
const u32 var70056a10[] = {0x060b0c00};
const u32 var70056a14[] = {0x000009b0};
const u32 var70056a18[] = {0x060c0d00};
const u32 var70056a1c[] = {0x00001030};
const u32 var70056a20[] = {0x060d0d00};
const u32 var70056a24[] = {0x00000ed0};
const u32 var70056a28[] = {0x060e0e00};
const u32 var70056a2c[] = {0x000034d0};
const u32 var70056a30[] = {0x060f0a00};
const u32 var70056a34[] = {0x00000140};
const u32 var70056a38[] = {0x07000a00};
const u32 var70056a3c[] = {0x00000118};
const u32 var70056a40[] = {0x07010900};
const u32 var70056a44[] = {0x00000018};
const u32 var70056a48[] = {0x07020a00};
const u32 var70056a4c[] = {0x00000368};
const u32 var70056a50[] = {0x07030a00};
const u32 var70056a54[] = {0x00000068};
const u32 var70056a58[] = {0x07040b00};
const u32 var70056a5c[] = {0x00000528};
const u32 var70056a60[] = {0x07050b00};
const u32 var70056a64[] = {0x000005c8};
const u32 var70056a68[] = {0x07060b00};
const u32 var70056a6c[] = {0x00000148};
const u32 var70056a70[] = {0x07070c00};
const u32 var70056a74[] = {0x00000a08};
const u32 var70056a78[] = {0x07080c00};
const u32 var70056a7c[] = {0x000001f0};
const u32 var70056a80[] = {0x07090d00};
const u32 var70056a84[] = {0x00001d30};
const u32 var70056a88[] = {0x070a0d00};
const u32 var70056a8c[] = {0x00001630};
const u32 var70056a90[] = {0x070b0d00};
const u32 var70056a94[] = {0x000005d0};
const u32 var70056a98[] = {0x070c0d00};
const u32 var70056a9c[] = {0x000007d0};
const u32 var70056aa0[] = {0x070d0f00};
const u32 var70056aa4[] = {0x00004f60};
const u32 var70056aa8[] = {0x070e0f00};
const u32 var70056aac[] = {0x00001760};
const u32 var70056ab0[] = {0x070f0a00};
const u32 var70056ab4[] = {0x00000040};
const u32 var70056ab8[] = {0x08000a00};
const u32 var70056abc[] = {0x000002a8};
const u32 var70056ac0[] = {0x08010a00};
const u32 var70056ac4[] = {0x000000a8};
const u32 var70056ac8[] = {0x08020a00};
const u32 var70056acc[] = {0x00000228};
const u32 var70056ad0[] = {0x08030b00};
const u32 var70056ad4[] = {0x000007c8};
const u32 var70056ad8[] = {0x08040b00};
const u32 var70056adc[] = {0x000001c8};
const u32 var70056ae0[] = {0x08050b00};
const u32 var70056ae4[] = {0x00000788};
const u32 var70056ae8[] = {0x08060c00};
const u32 var70056aec[] = {0x00000208};
const u32 var70056af0[] = {0x08070c00};
const u32 var70056af4[] = {0x000009f0};
const u32 var70056af8[] = {0x08080d00};
const u32 var70056afc[] = {0x00001ab0};
const u32 var70056b00[] = {0x08090d00};
const u32 var70056b04[] = {0x00001130};
const u32 var70056b08[] = {0x080a0d00};
const u32 var70056b0c[] = {0x00000230};
const u32 var70056b10[] = {0x080b0d00};
const u32 var70056b14[] = {0x00001fd0};
const u32 var70056b18[] = {0x080c0e00};
const u32 var70056b1c[] = {0x00003ad0};
const u32 var70056b20[] = {0x080d0e00};
const u32 var70056b24[] = {0x000024d0};
const u32 var70056b28[] = {0x080e0e00};
const u32 var70056b2c[] = {0x000008d0};
const u32 var70056b30[] = {0x080f0a00};
const u32 var70056b34[] = {0x00000380};
const u32 var70056b38[] = {0x09000b00};
const u32 var70056b3c[] = {0x000002c8};
const u32 var70056b40[] = {0x09010a00};
const u32 var70056b44[] = {0x000000c8};
const u32 var70056b48[] = {0x09020a00};
const u32 var70056b4c[] = {0x00000248};
const u32 var70056b50[] = {0x09030b00};
const u32 var70056b54[] = {0x00000588};
const u32 var70056b58[] = {0x09040b00};
const u32 var70056b5c[] = {0x00000608};
const u32 var70056b60[] = {0x09050c00};
const u32 var70056b64[] = {0x00000008};
const u32 var70056b68[] = {0x09060c00};
const u32 var70056b6c[] = {0x00000af0};
const u32 var70056b70[] = {0x09070d00};
const u32 var70056b74[] = {0x00000ab0};
const u32 var70056b78[] = {0x09080d00};
const u32 var70056b7c[] = {0x00000d30};
const u32 var70056b80[] = {0x09090d00};
const u32 var70056b84[] = {0x00000a30};
const u32 var70056b88[] = {0x090a0d00};
const u32 var70056b8c[] = {0x00000030};
const u32 var70056b90[] = {0x090b0e00};
const u32 var70056b94[] = {0x00003ed0};
const u32 var70056b98[] = {0x090c0d00};
const u32 var70056b9c[] = {0x00001cd0};
const u32 var70056ba0[] = {0x090d0e00};
const u32 var70056ba4[] = {0x000018d0};
const u32 var70056ba8[] = {0x090e0d00};
const u32 var70056bac[] = {0x000000d0};
const u32 var70056bb0[] = {0x090f0b00};
const u32 var70056bb4[] = {0x00000680};
const u32 var70056bb8[] = {0x0a000b00};
const u32 var70056bbc[] = {0x00000688};
const u32 var70056bc0[] = {0x0a010b00};
const u32 var70056bc4[] = {0x00000408};
const u32 var70056bc8[] = {0x0a020a00};
const u32 var70056bcc[] = {0x00000308};
const u32 var70056bd0[] = {0x0a030b00};
const u32 var70056bd4[] = {0x000005f0};
const u32 var70056bd8[] = {0x0a040c00};
const u32 var70056bdc[] = {0x00000ef0};
const u32 var70056be0[] = {0x0a050c00};
const u32 var70056be4[] = {0x00000970};
const u32 var70056be8[] = {0x0a060c00};
const u32 var70056bec[] = {0x00000a70};
const u32 var70056bf0[] = {0x0a070c00};
const u32 var70056bf4[] = {0x00000db0};
const u32 var70056bf8[] = {0x0a080d00};
const u32 var70056bfc[] = {0x00001230};
const u32 var70056c00[] = {0x0a090e00};
const u32 var70056c04[] = {0x000039d0};
const u32 var70056c08[] = {0x0a0a0e00};
const u32 var70056c0c[] = {0x000021d0};
const u32 var70056c10[] = {0x0a0b0e00};
const u32 var70056c14[] = {0x000002d0};
const u32 var70056c18[] = {0x0a0c0f00};
const u32 var70056c1c[] = {0x00005760};
const u32 var70056c20[] = {0x0a0d0f00};
const u32 var70056c24[] = {0x00002760};
const u32 var70056c28[] = {0x0a0e0e00};
const u32 var70056c2c[] = {0x00003b60};
const u32 var70056c30[] = {0x0a0f0a00};
const u32 var70056c34[] = {0x00000080};
const u32 var70056c38[] = {0x0b000c00};
const u32 var70056c3c[] = {0x00000cf0};
const u32 var70056c40[] = {0x0b010b00};
const u32 var70056c44[] = {0x000000f0};
const u32 var70056c48[] = {0x0b020b00};
const u32 var70056c4c[] = {0x00000370};
const u32 var70056c50[] = {0x0b030b00};
const u32 var70056c54[] = {0x00000670};
const u32 var70056c58[] = {0x0b040c00};
const u32 var70056c5c[] = {0x00000c70};
const u32 var70056c60[] = {0x0b050c00};
const u32 var70056c64[] = {0x00000fb0};
const u32 var70056c68[] = {0x0b060d00};
const u32 var70056c6c[] = {0x00000630};
const u32 var70056c70[] = {0x0b070e00};
const u32 var70056c74[] = {0x000015d0};
const u32 var70056c78[] = {0x0b080e00};
const u32 var70056c7c[] = {0x000019d0};
const u32 var70056c80[] = {0x0b090e00};
const u32 var70056c84[] = {0x000001d0};
const u32 var70056c88[] = {0x0b0a0e00};
const u32 var70056c8c[] = {0x000022d0};
const u32 var70056c90[] = {0x0b0b0e00};
const u32 var70056c94[] = {0x000004d0};
const u32 var70056c98[] = {0x0b0c0e00};
const u32 var70056c9c[] = {0x000010d0};
const u32 var70056ca0[] = {0x0b0d0d00};
const u32 var70056ca4[] = {0x00001f60};
const u32 var70056ca8[] = {0x0b0e0e00};
const u32 var70056cac[] = {0x00000b60};
const u32 var70056cb0[] = {0x0b0f0b00};
const u32 var70056cb4[] = {0x00000300};
const u32 var70056cb8[] = {0x0c000c00};
const u32 var70056cbc[] = {0x00000530};
const u32 var70056cc0[] = {0x0c010c00};
const u32 var70056cc4[] = {0x00000070};
const u32 var70056cc8[] = {0x0c020c00};
const u32 var70056ccc[] = {0x000007b0};
const u32 var70056cd0[] = {0x0c030c00};
const u32 var70056cd4[] = {0x000005b0};
const u32 var70056cd8[] = {0x0c040c00};
const u32 var70056cdc[] = {0x000001b0};
const u32 var70056ce0[] = {0x0c050d00};
const u32 var70056ce4[] = {0x00001430};
const u32 var70056ce8[] = {0x0c060d00};
const u32 var70056cec[] = {0x00000830};
const u32 var70056cf0[] = {0x0c070d00};
const u32 var70056cf4[] = {0x000017d0};
const u32 var70056cf8[] = {0x0c080d00};
const u32 var70056cfc[] = {0x000006d0};
const u32 var70056d00[] = {0x0c090f00};
const u32 var70056d04[] = {0x00000f60};
const u32 var70056d08[] = {0x0c0a0e00};
const u32 var70056d0c[] = {0x00003760};
const u32 var70056d10[] = {0x0c0b0e00};
const u32 var70056d14[] = {0x000030d0};
const u32 var70056d18[] = {0x0c0c0e00};
const u32 var70056d1c[] = {0x00000760};
const u32 var70056d20[] = {0x0c0d0e00};
const u32 var70056d24[] = {0x00002b60};
const u32 var70056d28[] = {0x0c0e1000};
const u32 var70056d2c[] = {0x00000360};
const u32 var70056d30[] = {0x0c0f0b00};
const u32 var70056d34[] = {0x00000100};
const u32 var70056d38[] = {0x0d000e00};
const u32 var70056d3c[] = {0x000035d0};
const u32 var70056d40[] = {0x0d010c00};
const u32 var70056d44[] = {0x00000cb0};
const u32 var70056d48[] = {0x0d020c00};
const u32 var70056d4c[] = {0x000004b0};
const u32 var70056d50[] = {0x0d030c00};
const u32 var70056d54[] = {0x000000b0};
const u32 var70056d58[] = {0x0d040d00};
const u32 var70056d5c[] = {0x000009d0};
const u32 var70056d60[] = {0x0d050d00};
const u32 var70056d64[] = {0x00001bd0};
const u32 var70056d68[] = {0x0d060e00};
const u32 var70056d6c[] = {0x00001ed0};
const u32 var70056d70[] = {0x0d070e00};
const u32 var70056d74[] = {0x000032d0};
const u32 var70056d78[] = {0x0d080e00};
const u32 var70056d7c[] = {0x000014d0};
const u32 var70056d80[] = {0x0d091000};
const u32 var70056d84[] = {0x0000e360};
const u32 var70056d88[] = {0x0d0a0f00};
const u32 var70056d8c[] = {0x00006760};
const u32 var70056d90[] = {0x0d0b0f00};
const u32 var70056d94[] = {0x00005b60};
const u32 var70056d98[] = {0x0d0c0f00};
const u32 var70056d9c[] = {0x00001b60};
const u32 var70056da0[] = {0x0d0d1100};
const u32 var70056da4[] = {0x00018360};
const u32 var70056da8[] = {0x0d0e0f00};
const u32 var70056dac[] = {0x00004360};
const u32 var70056db0[] = {0x0d0f0b00};
const u32 var70056db4[] = {0x00000200};
const u32 var70056db8[] = {0x0e000d00};
const u32 var70056dbc[] = {0x000013d0};
const u32 var70056dc0[] = {0x0e010d00};
const u32 var70056dc4[] = {0x000011d0};
const u32 var70056dc8[] = {0x0e020b00};
const u32 var70056dcc[] = {0x00000330};
const u32 var70056dd0[] = {0x0e030c00};
const u32 var70056dd4[] = {0x00000dd0};
const u32 var70056dd8[] = {0x0e040e00};
const u32 var70056ddc[] = {0x00001ad0};
const u32 var70056de0[] = {0x0e050e00};
const u32 var70056de4[] = {0x000012d0};
const u32 var70056de8[] = {0x0e060d00};
const u32 var70056dec[] = {0x00000cd0};
const u32 var70056df0[] = {0x0e070e00};
const u32 var70056df4[] = {0x000038d0};
const u32 var70056df8[] = {0x0e080e00};
const u32 var70056dfc[] = {0x000028d0};
const u32 var70056e00[] = {0x0e090f00};
const u32 var70056e04[] = {0x00002360};
const u32 var70056e08[] = {0x0e0a1000};
const u32 var70056e0c[] = {0x00006360};
const u32 var70056e10[] = {0x0e0b0f00};
const u32 var70056e14[] = {0x00007360};
const u32 var70056e18[] = {0x0e0c1100};
const u32 var70056e1c[] = {0x00008360};
const u32 var70056e20[] = {0x0e0d0f00};
const u32 var70056e24[] = {0x00003360};
const u32 var70056e28[] = {0x0e0e0e00};
const u32 var70056e2c[] = {0x00001360};
const u32 var70056e30[] = {0x0e0f0b00};
const u32 var70056e34[] = {0x00000000};
const u32 var70056e38[] = {0x0f000900};
const u32 var70056e3c[] = {0x00000060};
const u32 var70056e40[] = {0x0f010800};
const u32 var70056e44[] = {0x00000050};
const u32 var70056e48[] = {0x0f020800};
const u32 var70056e4c[] = {0x000000e0};
const u32 var70056e50[] = {0x0f030900};
const u32 var70056e54[] = {0x000001a0};
const u32 var70056e58[] = {0x0f040900};
const u32 var70056e5c[] = {0x000000a0};
const u32 var70056e60[] = {0x0f050a00};
const u32 var70056e64[] = {0x00000220};
const u32 var70056e68[] = {0x0f060a00};
const u32 var70056e6c[] = {0x00000340};
const u32 var70056e70[] = {0x0f070a00};
const u32 var70056e74[] = {0x00000240};
const u32 var70056e78[] = {0x0f080b00};
const u32 var70056e7c[] = {0x00000580};
const u32 var70056e80[] = {0x0f090b00};
const u32 var70056e84[] = {0x00000180};
const u32 var70056e88[] = {0x0f0a0b00};
const u32 var70056e8c[] = {0x00000280};
const u32 var70056e90[] = {0x0f0b0b00};
const u32 var70056e94[] = {0x00000700};
const u32 var70056e98[] = {0x0f0c0b00};
const u32 var70056e9c[] = {0x00000500};
const u32 var70056ea0[] = {0x0f0d0b00};
const u32 var70056ea4[] = {0x00000600};
const u32 var70056ea8[] = {0x0f0e0b00};
const u32 var70056eac[] = {0x00000400};
const u32 var70056eb0[] = {0x0f0f0800};
const u32 var70056eb4[] = {0x000000c0};
const u32 var70056eb8[] = {0x64646400};
const u32 var70056ebc[] = {0x00000000};
const u32 var70056ec0[] = {0x00000400};
const u32 var70056ec4[] = {0x0000000f};
const u32 var70056ec8[] = {0x00010400};
const u32 var70056ecc[] = {0x0000000b};
const u32 var70056ed0[] = {0x00020600};
const u32 var70056ed4[] = {0x0000001d};
const u32 var70056ed8[] = {0x00030700};
const u32 var70056edc[] = {0x00000005};
const u32 var70056ee0[] = {0x00040800};
const u32 var70056ee4[] = {0x00000049};
const u32 var70056ee8[] = {0x00050900};
const u32 var70056eec[] = {0x000000c1};
const u32 var70056ef0[] = {0x00060900};
const u32 var70056ef4[] = {0x0000003e};
const u32 var70056ef8[] = {0x00070a00};
const u32 var70056efc[] = {0x00000136};
const u32 var70056f00[] = {0x00080a00};
const u32 var70056f04[] = {0x00000156};
const u32 var70056f08[] = {0x00090b00};
const u32 var70056f0c[] = {0x000005ca};
const u32 var70056f10[] = {0x000a0b00};
const u32 var70056f14[] = {0x0000058a};
const u32 var70056f18[] = {0x000b0b00};
const u32 var70056f1c[] = {0x0000048a};
const u32 var70056f20[] = {0x000c0b00};
const u32 var70056f24[] = {0x000005b2};
const u32 var70056f28[] = {0x000d0b00};
const u32 var70056f2c[] = {0x00000502};
const u32 var70056f30[] = {0x000e0c00};
const u32 var70056f34[] = {0x00000102};
const u32 var70056f38[] = {0x000f0900};
const u32 var70056f3c[] = {0x00000034};
const u32 var70056f40[] = {0x01000400};
const u32 var70056f44[] = {0x00000007};
const u32 var70056f48[] = {0x01010400};
const u32 var70056f4c[] = {0x00000003};
const u32 var70056f50[] = {0x01020500};
const u32 var70056f54[] = {0x00000015};
const u32 var70056f58[] = {0x01030600};
const u32 var70056f5c[] = {0x00000019};
const u32 var70056f60[] = {0x01040700};
const u32 var70056f64[] = {0x00000071};
const u32 var70056f68[] = {0x01050800};
const u32 var70056f6c[] = {0x00000041};
const u32 var70056f70[] = {0x01060800};
const u32 var70056f74[] = {0x0000005e};
const u32 var70056f78[] = {0x01070900};
const u32 var70056f7c[] = {0x00000036};
const u32 var70056f80[] = {0x01080900};
const u32 var70056f84[] = {0x00000116};
const u32 var70056f88[] = {0x01090900};
const u32 var70056f8c[] = {0x000000c6};
const u32 var70056f90[] = {0x010a0a00};
const u32 var70056f94[] = {0x0000038a};
const u32 var70056f98[] = {0x010b0a00};
const u32 var70056f9c[] = {0x0000026a};
const u32 var70056fa0[] = {0x010c0a00};
const u32 var70056fa4[] = {0x000003f2};
const u32 var70056fa8[] = {0x010d0a00};
const u32 var70056fac[] = {0x00000252};
const u32 var70056fb0[] = {0x010e0a00};
const u32 var70056fb4[] = {0x000003a2};
const u32 var70056fb8[] = {0x010f0800};
const u32 var70056fbc[] = {0x00000054};
const u32 var70056fc0[] = {0x02000600};
const u32 var70056fc4[] = {0x0000003d};
const u32 var70056fc8[] = {0x02010500};
const u32 var70056fcc[] = {0x0000000d};
const u32 var70056fd0[] = {0x02020600};
const u32 var70056fd4[] = {0x00000025};
const u32 var70056fd8[] = {0x02030700};
const u32 var70056fdc[] = {0x00000029};
const u32 var70056fe0[] = {0x02040700};
const u32 var70056fe4[] = {0x00000011};
const u32 var70056fe8[] = {0x02050800};
const u32 var70056fec[] = {0x00000001};
const u32 var70056ff0[] = {0x02060800};
const u32 var70056ff4[] = {0x0000001e};
const u32 var70056ff8[] = {0x02070900};
const u32 var70056ffc[] = {0x00000176};
const u32 var70057000[] = {0x02080900};
const u32 var70057004[] = {0x000001e6};
const u32 var70057008[] = {0x02090900};
const u32 var7005700c[] = {0x00000086};
const u32 var70057010[] = {0x020a0900};
const u32 var70057014[] = {0x000000da};
const u32 var70057018[] = {0x020b0a00};
const u32 var7005701c[] = {0x000000aa};
const u32 var70057020[] = {0x020c0a00};
const u32 var70057024[] = {0x00000372};
const u32 var70057028[] = {0x020d0a00};
const u32 var7005702c[] = {0x00000392};
const u32 var70057030[] = {0x020e0b00};
const u32 var70057034[] = {0x000005c2};
const u32 var70057038[] = {0x020f0700};
const u32 var7005703c[] = {0x00000024};
const u32 var70057040[] = {0x03000700};
const u32 var70057044[] = {0x00000045};
const u32 var70057048[] = {0x03010600};
const u32 var7005704c[] = {0x00000039};
const u32 var70057050[] = {0x03020700};
const u32 var70057054[] = {0x00000069};
const u32 var70057058[] = {0x03030700};
const u32 var7005705c[] = {0x00000031};
const u32 var70057060[] = {0x03040800};
const u32 var70057064[] = {0x00000061};
const u32 var70057068[] = {0x03050800};
const u32 var7005706c[] = {0x000000be};
const u32 var70057070[] = {0x03060800};
const u32 var70057074[] = {0x0000002e};
const u32 var70057078[] = {0x03070900};
const u32 var7005707c[] = {0x00000076};
const u32 var70057080[] = {0x03080900};
const u32 var70057084[] = {0x00000066};
const u32 var70057088[] = {0x03090900};
const u32 var7005708c[] = {0x000000fa};
const u32 var70057090[] = {0x030a0900};
const u32 var70057094[] = {0x0000009a};
const u32 var70057098[] = {0x030b0a00};
const u32 var7005709c[] = {0x0000028a};
const u32 var700570a0[] = {0x030c0a00};
const u32 var700570a4[] = {0x000003b2};
const u32 var700570a8[] = {0x030d0a00};
const u32 var700570ac[] = {0x00000292};
const u32 var700570b0[] = {0x030e0a00};
const u32 var700570b4[] = {0x000003c2};
const u32 var700570b8[] = {0x030f0700};
const u32 var700570bc[] = {0x00000004};
const u32 var700570c0[] = {0x04000800};
const u32 var700570c4[] = {0x000000c9};
const u32 var700570c8[] = {0x04010700};
const u32 var700570cc[] = {0x00000009};
const u32 var700570d0[] = {0x04020700};
const u32 var700570d4[] = {0x00000051};
const u32 var700570d8[] = {0x04030800};
const u32 var700570dc[] = {0x000000e1};
const u32 var700570e0[] = {0x04040800};
const u32 var700570e4[] = {0x000000fe};
const u32 var700570e8[] = {0x04050800};
const u32 var700570ec[] = {0x0000006e};
const u32 var700570f0[] = {0x04060800};
const u32 var700570f4[] = {0x0000000e};
const u32 var700570f8[] = {0x04070900};
const u32 var700570fc[] = {0x00000096};
const u32 var70057100[] = {0x04080900};
const u32 var70057104[] = {0x00000026};
const u32 var70057108[] = {0x04090900};
const u32 var7005710c[] = {0x0000007a};
const u32 var70057110[] = {0x040a0a00};
const u32 var70057114[] = {0x0000001a};
const u32 var70057118[] = {0x040b0a00};
const u32 var7005711c[] = {0x0000030a};
const u32 var70057120[] = {0x040c0a00};
const u32 var70057124[] = {0x00000132};
const u32 var70057128[] = {0x040d0a00};
const u32 var7005712c[] = {0x000002e2};
const u32 var70057130[] = {0x040e0b00};
const u32 var70057134[] = {0x000001c2};
const u32 var70057138[] = {0x040f0700};
const u32 var7005713c[] = {0x00000038};
const u32 var70057140[] = {0x05000900};
const u32 var70057144[] = {0x000001c1};
const u32 var70057148[] = {0x05010700};
const u32 var7005714c[] = {0x00000021};
const u32 var70057150[] = {0x05020800};
const u32 var70057154[] = {0x00000081};
const u32 var70057158[] = {0x05030800};
const u32 var7005715c[] = {0x0000007e};
const u32 var70057160[] = {0x05040800};
const u32 var70057164[] = {0x000000ee};
const u32 var70057168[] = {0x05050800};
const u32 var7005716c[] = {0x0000004e};
const u32 var70057170[] = {0x05060900};
const u32 var70057174[] = {0x000000d6};
const u32 var70057178[] = {0x05070900};
const u32 var7005717c[] = {0x000000a6};
const u32 var70057180[] = {0x05080900};
const u32 var70057184[] = {0x00000006};
const u32 var70057188[] = {0x05090900};
const u32 var7005718c[] = {0x0000005a};
const u32 var70057190[] = {0x050a0a00};
const u32 var70057194[] = {0x000002aa};
const u32 var70057198[] = {0x050b0a00};
const u32 var7005719c[] = {0x000002f2};
const u32 var700571a0[] = {0x050c0a00};
const u32 var700571a4[] = {0x000002d2};
const u32 var700571a8[] = {0x050d0a00};
const u32 var700571ac[] = {0x00000262};
const u32 var700571b0[] = {0x050e0a00};
const u32 var700571b4[] = {0x00000182};
const u32 var700571b8[] = {0x050f0700};
const u32 var700571bc[] = {0x00000018};
const u32 var700571c0[] = {0x06000900};
const u32 var700571c4[] = {0x0000013e};
const u32 var700571c8[] = {0x06010800};
const u32 var700571cc[] = {0x000000de};
const u32 var700571d0[] = {0x06020800};
const u32 var700571d4[] = {0x0000009e};
const u32 var700571d8[] = {0x06030800};
const u32 var700571dc[] = {0x000000ae};
const u32 var700571e0[] = {0x06040800};
const u32 var700571e4[] = {0x0000008e};
const u32 var700571e8[] = {0x06050900};
const u32 var700571ec[] = {0x000001d6};
const u32 var700571f0[] = {0x06060900};
const u32 var700571f4[] = {0x000000e6};
const u32 var700571f8[] = {0x06070900};
const u32 var700571fc[] = {0x00000186};
const u32 var70057200[] = {0x06080900};
const u32 var70057204[] = {0x0000013a};
const u32 var70057208[] = {0x06090a00};
const u32 var7005720c[] = {0x0000036a};
const u32 var70057210[] = {0x060a0a00};
const u32 var70057214[] = {0x0000014a};
const u32 var70057218[] = {0x060b0a00};
const u32 var7005721c[] = {0x000000b2};
const u32 var70057220[] = {0x060c0a00};
const u32 var70057224[] = {0x00000312};
const u32 var70057228[] = {0x060d0a00};
const u32 var7005722c[] = {0x00000022};
const u32 var70057230[] = {0x060e0b00};
const u32 var70057234[] = {0x00000082};
const u32 var70057238[] = {0x060f0700};
const u32 var7005723c[] = {0x00000028};
const u32 var70057240[] = {0x07000a00};
const u32 var70057244[] = {0x00000336};
const u32 var70057248[] = {0x07010800};
const u32 var7005724c[] = {0x000000ce};
const u32 var70057250[] = {0x07020800};
const u32 var70057254[] = {0x000000f6};
const u32 var70057258[] = {0x07030800};
const u32 var7005725c[] = {0x000000b6};
const u32 var70057260[] = {0x07040900};
const u32 var70057264[] = {0x00000196};
const u32 var70057268[] = {0x07050900};
const u32 var7005726c[] = {0x000001a6};
const u32 var70057270[] = {0x07060900};
const u32 var70057274[] = {0x00000046};
const u32 var70057278[] = {0x07070900};
const u32 var7005727c[] = {0x000001ba};
const u32 var70057280[] = {0x07080a00};
const u32 var70057284[] = {0x0000021a};
const u32 var70057288[] = {0x07090a00};
const u32 var7005728c[] = {0x000000ca};
const u32 var70057290[] = {0x070a0a00};
const u32 var70057294[] = {0x00000272};
const u32 var70057298[] = {0x070b0a00};
const u32 var7005729c[] = {0x00000152};
const u32 var700572a0[] = {0x070c0a00};
const u32 var700572a4[] = {0x00000362};
const u32 var700572a8[] = {0x070d0b00};
const u32 var700572ac[] = {0x00000642};
const u32 var700572b0[] = {0x070e0b00};
const u32 var700572b4[] = {0x000005f4};
const u32 var700572b8[] = {0x070f0800};
const u32 var700572bc[] = {0x00000088};
const u32 var700572c0[] = {0x08000a00};
const u32 var700572c4[] = {0x00000356};
const u32 var700572c8[] = {0x08010900};
const u32 var700572cc[] = {0x00000056};
const u32 var700572d0[] = {0x08020900};
const u32 var700572d4[] = {0x00000016};
const u32 var700572d8[] = {0x08030900};
const u32 var700572dc[] = {0x00000166};
const u32 var700572e0[] = {0x08040900};
const u32 var700572e4[] = {0x00000126};
const u32 var700572e8[] = {0x08050900};
const u32 var700572ec[] = {0x00000106};
const u32 var700572f0[] = {0x08060900};
const u32 var700572f4[] = {0x000000ba};
const u32 var700572f8[] = {0x08070900};
const u32 var700572fc[] = {0x0000011a};
const u32 var70057300[] = {0x08080900};
const u32 var70057304[] = {0x0000012a};
const u32 var70057308[] = {0x08090a00};
const u32 var7005730c[] = {0x0000000a};
const u32 var70057310[] = {0x080a0a00};
const u32 var70057314[] = {0x000003d2};
const u32 var70057318[] = {0x080b0a00};
const u32 var7005731c[] = {0x000001e2};
const u32 var70057320[] = {0x080c0a00};
const u32 var70057324[] = {0x000000c2};
const u32 var70057328[] = {0x080d0b00};
const u32 var7005732c[] = {0x00000202};
const u32 var70057330[] = {0x080e0b00};
const u32 var70057334[] = {0x000004f4};
const u32 var70057338[] = {0x080f0800};
const u32 var7005733c[] = {0x00000008};
const u32 var70057340[] = {0x09000a00};
const u32 var70057344[] = {0x000003ca};
const u32 var70057348[] = {0x09010900};
const u32 var7005734c[] = {0x000001c6};
const u32 var70057350[] = {0x09020900};
const u32 var70057354[] = {0x00000146};
const u32 var70057358[] = {0x09030900};
const u32 var7005735c[] = {0x000001fa};
const u32 var70057360[] = {0x09040900};
const u32 var70057364[] = {0x0000017a};
const u32 var70057368[] = {0x09050900};
const u32 var7005736c[] = {0x0000015a};
const u32 var70057370[] = {0x09060900};
const u32 var70057374[] = {0x000000ea};
const u32 var70057378[] = {0x09070a00};
const u32 var7005737c[] = {0x000002ca};
const u32 var70057380[] = {0x09080a00};
const u32 var70057384[] = {0x0000020a};
const u32 var70057388[] = {0x09090a00};
const u32 var7005738c[] = {0x00000232};
const u32 var70057390[] = {0x090a0a00};
const u32 var70057394[] = {0x00000212};
const u32 var70057398[] = {0x090b0a00};
const u32 var7005739c[] = {0x00000322};
const u32 var700573a0[] = {0x090c0b00};
const u32 var700573a4[] = {0x00000482};
const u32 var700573a8[] = {0x090d0b00};
const u32 var700573ac[] = {0x000006f4};
const u32 var700573b0[] = {0x090e0b00};
const u32 var700573b4[] = {0x00000674};
const u32 var700573b8[] = {0x090f0800};
const u32 var700573bc[] = {0x000000d0};
const u32 var700573c0[] = {0x0a000b00};
const u32 var700573c4[] = {0x000001ca};
const u32 var700573c8[] = {0x0a010900};
const u32 var700573cc[] = {0x0000003a};
const u32 var700573d0[] = {0x0a020900};
const u32 var700573d4[] = {0x000001da};
const u32 var700573d8[] = {0x0a030900};
const u32 var700573dc[] = {0x0000019a};
const u32 var700573e0[] = {0x0a040900};
const u32 var700573e4[] = {0x000001ea};
const u32 var700573e8[] = {0x0a050a00};
const u32 var700573ec[] = {0x0000006a};
const u32 var700573f0[] = {0x0a060a00};
const u32 var700573f4[] = {0x0000034a};
const u32 var700573f8[] = {0x0a070a00};
const u32 var700573fc[] = {0x00000172};
const u32 var70057400[] = {0x0a080a00};
const u32 var70057404[] = {0x00000032};
const u32 var70057408[] = {0x0a090a00};
const u32 var7005740c[] = {0x00000112};
const u32 var70057410[] = {0x0a0a0a00};
const u32 var70057414[] = {0x000002a2};
const u32 var70057418[] = {0x0a0b0b00};
const u32 var7005741c[] = {0x00000242};
const u32 var70057420[] = {0x0a0c0b00};
const u32 var70057424[] = {0x000007f4};
const u32 var70057428[] = {0x0a0d0b00};
const u32 var7005742c[] = {0x00000574};
const u32 var70057430[] = {0x0a0e0b00};
const u32 var70057434[] = {0x000003b4};
const u32 var70057438[] = {0x0a0f0800};
const u32 var7005743c[] = {0x00000050};
const u32 var70057440[] = {0x0b000b00};
const u32 var70057444[] = {0x0000018a};
const u32 var70057448[] = {0x0b010a00};
const u32 var7005744c[] = {0x0000016a};
const u32 var70057450[] = {0x0b020900};
const u32 var70057454[] = {0x000001aa};
const u32 var70057458[] = {0x0b030900};
const u32 var7005745c[] = {0x0000002a};
const u32 var70057460[] = {0x0b040900};
const u32 var70057464[] = {0x0000004a};
const u32 var70057468[] = {0x0b050a00};
const u32 var7005746c[] = {0x000001f2};
const u32 var70057470[] = {0x0b060a00};
const u32 var70057474[] = {0x000002b2};
const u32 var70057478[] = {0x0b070a00};
const u32 var7005747c[] = {0x00000352};
const u32 var70057480[] = {0x0b080a00};
const u32 var70057484[] = {0x000003e2};
const u32 var70057488[] = {0x0b090a00};
const u32 var7005748c[] = {0x000000a2};
const u32 var70057490[] = {0x0b0a0a00};
const u32 var70057494[] = {0x00000382};
const u32 var70057498[] = {0x0b0b0b00};
const u32 var7005749c[] = {0x00000402};
const u32 var700574a0[] = {0x0b0c0b00};
const u32 var700574a4[] = {0x00000774};
const u32 var700574a8[] = {0x0b0d0b00};
const u32 var700574ac[] = {0x00000074};
const u32 var700574b0[] = {0x0b0e0b00};
const u32 var700574b4[] = {0x000002b4};
const u32 var700574b8[] = {0x0b0f0800};
const u32 var700574bc[] = {0x00000060};
const u32 var700574c0[] = {0x0c000b00};
const u32 var700574c4[] = {0x0000008a};
const u32 var700574c8[] = {0x0c010a00};
const u32 var700574cc[] = {0x0000010a};
const u32 var700574d0[] = {0x0c020a00};
const u32 var700574d4[] = {0x000000f2};
const u32 var700574d8[] = {0x0c030a00};
const u32 var700574dc[] = {0x00000072};
const u32 var700574e0[] = {0x0c040a00};
const u32 var700574e4[] = {0x00000332};
const u32 var700574e8[] = {0x0c050a00};
const u32 var700574ec[] = {0x000001d2};
const u32 var700574f0[] = {0x0c060a00};
const u32 var700574f4[] = {0x00000092};
const u32 var700574f8[] = {0x0c070a00};
const u32 var700574fc[] = {0x000000e2};
const u32 var70057500[] = {0x0c080a00};
const u32 var70057504[] = {0x000002c2};
const u32 var70057508[] = {0x0c090a00};
const u32 var7005750c[] = {0x00000282};
const u32 var70057510[] = {0x0c0a0b00};
const u32 var70057514[] = {0x00000002};
const u32 var70057518[] = {0x0c0b0b00};
const u32 var7005751c[] = {0x000000f4};
const u32 var70057520[] = {0x0c0c0b00};
const u32 var70057524[] = {0x00000274};
const u32 var70057528[] = {0x0c0d0b00};
const u32 var7005752c[] = {0x000001b4};
const u32 var70057530[] = {0x0c0e0b00};
const u32 var70057534[] = {0x00000734};
const u32 var70057538[] = {0x0c0f0800};
const u32 var7005753c[] = {0x00000020};
const u32 var70057540[] = {0x0d000b00};
const u32 var70057544[] = {0x000001b2};
const u32 var70057548[] = {0x0d010a00};
const u32 var7005754c[] = {0x000000d2};
const u32 var70057550[] = {0x0d020a00};
const u32 var70057554[] = {0x00000052};
const u32 var70057558[] = {0x0d030a00};
const u32 var7005755c[] = {0x00000192};
const u32 var70057560[] = {0x0d040a00};
const u32 var70057564[] = {0x00000012};
const u32 var70057568[] = {0x0d050a00};
const u32 var7005756c[] = {0x00000162};
const u32 var70057570[] = {0x0d060a00};
const u32 var70057574[] = {0x00000222};
const u32 var70057578[] = {0x0d070a00};
const u32 var7005757c[] = {0x00000142};
const u32 var70057580[] = {0x0d080b00};
const u32 var70057584[] = {0x00000602};
const u32 var70057588[] = {0x0d090b00};
const u32 var7005758c[] = {0x000001f4};
const u32 var70057590[] = {0x0d0a0b00};
const u32 var70057594[] = {0x00000374};
const u32 var70057598[] = {0x0d0b0b00};
const u32 var7005759c[] = {0x00000474};
const u32 var700575a0[] = {0x0d0c0b00};
const u32 var700575a4[] = {0x000005b4};
const u32 var700575a8[] = {0x0d0d0b00};
const u32 var700575ac[] = {0x000004b4};
const u32 var700575b0[] = {0x0d0e0b00};
const u32 var700575b4[] = {0x00000534};
const u32 var700575b8[] = {0x0d0f0800};
const u32 var700575bc[] = {0x00000040};
const u32 var700575c0[] = {0x0e000c00};
const u32 var700575c4[] = {0x00000902};
const u32 var700575c8[] = {0x0e010a00};
const u32 var700575cc[] = {0x00000062};
const u32 var700575d0[] = {0x0e020a00};
const u32 var700575d4[] = {0x000001a2};
const u32 var700575d8[] = {0x0e030a00};
const u32 var700575dc[] = {0x00000122};
const u32 var700575e0[] = {0x0e040a00};
const u32 var700575e4[] = {0x00000342};
const u32 var700575e8[] = {0x0e050a00};
const u32 var700575ec[] = {0x00000042};
const u32 var700575f0[] = {0x0e060a00};
const u32 var700575f4[] = {0x00000302};
const u32 var700575f8[] = {0x0e070b00};
const u32 var700575fc[] = {0x000003f4};
const u32 var70057600[] = {0x0e080b00};
const u32 var70057604[] = {0x000002f4};
const u32 var70057608[] = {0x0e090b00};
const u32 var7005760c[] = {0x00000174};
const u32 var70057610[] = {0x0e0a0b00};
const u32 var70057614[] = {0x000007b4};
const u32 var70057618[] = {0x0e0b0b00};
const u32 var7005761c[] = {0x000006b4};
const u32 var70057620[] = {0x0e0c0b00};
const u32 var70057624[] = {0x000000b4};
const u32 var70057628[] = {0x0e0d0b00};
const u32 var7005762c[] = {0x00000334};
const u32 var70057630[] = {0x0e0e0b00};
const u32 var70057634[] = {0x00000134};
const u32 var70057638[] = {0x0e0f0800};
const u32 var7005763c[] = {0x00000000};
const u32 var70057640[] = {0x0f000800};
const u32 var70057644[] = {0x000000d4};
const u32 var70057648[] = {0x0f010700};
const u32 var7005764c[] = {0x00000014};
const u32 var70057650[] = {0x0f020700};
const u32 var70057654[] = {0x00000064};
const u32 var70057658[] = {0x0f030700};
const u32 var7005765c[] = {0x00000044};
const u32 var70057660[] = {0x0f040700};
const u32 var70057664[] = {0x00000078};
const u32 var70057668[] = {0x0f050700};
const u32 var7005766c[] = {0x00000058};
const u32 var70057670[] = {0x0f060700};
const u32 var70057674[] = {0x00000068};
const u32 var70057678[] = {0x0f070700};
const u32 var7005767c[] = {0x00000048};
const u32 var70057680[] = {0x0f080700};
const u32 var70057684[] = {0x00000070};
const u32 var70057688[] = {0x0f090700};
const u32 var7005768c[] = {0x00000030};
const u32 var70057690[] = {0x0f0a0700};
const u32 var70057694[] = {0x00000010};
const u32 var70057698[] = {0x0f0b0800};
const u32 var7005769c[] = {0x000000e0};
const u32 var700576a0[] = {0x0f0c0800};
const u32 var700576a4[] = {0x000000a0};
const u32 var700576a8[] = {0x0f0d0800};
const u32 var700576ac[] = {0x000000c0};
const u32 var700576b0[] = {0x0f0e0800};
const u32 var700576b4[] = {0x00000080};
const u32 var700576b8[] = {0x0f0f0400};
const u32 var700576bc[] = {0x0000000c};
const u32 var700576c0[] = {0x64646400};
const u32 var700576c4[] = {0x00000000};
const u32 var700576c8[] = {0x00000100};
const u32 var700576cc[] = {0x00000001};
const u32 var700576d0[] = {0x01010400};
const u32 var700576d4[] = {0x0000000a};
const u32 var700576d8[] = {0x02020400};
const u32 var700576dc[] = {0x00000002};
const u32 var700576e0[] = {0x03030500};
const u32 var700576e4[] = {0x00000014};
const u32 var700576e8[] = {0x04040400};
const u32 var700576ec[] = {0x00000006};
const u32 var700576f0[] = {0x05050600};
const u32 var700576f4[] = {0x00000028};
const u32 var700576f8[] = {0x06060500};
const u32 var700576fc[] = {0x00000004};
const u32 var70057700[] = {0x07070600};
const u32 var70057704[] = {0x00000008};
const u32 var70057708[] = {0x08080400};
const u32 var7005770c[] = {0x0000000e};
const u32 var70057710[] = {0x09090500};
const u32 var70057714[] = {0x00000018};
const u32 var70057718[] = {0x0a0a0500};
const u32 var7005771c[] = {0x0000000c};
const u32 var70057720[] = {0x0b0b0600};
const u32 var70057724[] = {0x00000000};
const u32 var70057728[] = {0x0c0c0500};
const u32 var7005772c[] = {0x0000001c};
const u32 var70057730[] = {0x0d0d0600};
const u32 var70057734[] = {0x00000010};
const u32 var70057738[] = {0x0e0e0600};
const u32 var7005773c[] = {0x00000030};
const u32 var70057740[] = {0x0f0f0600};
const u32 var70057744[] = {0x00000020};
const u32 var70057748[] = {0x64646400};
const u32 var7005774c[] = {0x00000000};
const u32 var70057750[] = {0x00000400};
const u32 var70057754[] = {0x0000000f};
const u32 var70057758[] = {0x01010400};
const u32 var7005775c[] = {0x00000007};
const u32 var70057760[] = {0x02020400};
const u32 var70057764[] = {0x0000000b};
const u32 var70057768[] = {0x03030400};
const u32 var7005776c[] = {0x00000003};
const u32 var70057770[] = {0x04040400};
const u32 var70057774[] = {0x0000000d};
const u32 var70057778[] = {0x05050400};
const u32 var7005777c[] = {0x00000005};
const u32 var70057780[] = {0x06060400};
const u32 var70057784[] = {0x00000009};
const u32 var70057788[] = {0x07070400};
const u32 var7005778c[] = {0x00000001};
const u32 var70057790[] = {0x08080400};
const u32 var70057794[] = {0x0000000e};
const u32 var70057798[] = {0x09090400};
const u32 var7005779c[] = {0x00000006};
const u32 var700577a0[] = {0x0a0a0400};
const u32 var700577a4[] = {0x0000000a};
const u32 var700577a8[] = {0x0b0b0400};
const u32 var700577ac[] = {0x00000002};
const u32 var700577b0[] = {0x0c0c0400};
const u32 var700577b4[] = {0x0000000c};
const u32 var700577b8[] = {0x0d0d0400};
const u32 var700577bc[] = {0x00000004};
const u32 var700577c0[] = {0x0e0e0400};
const u32 var700577c4[] = {0x00000008};
const u32 var700577c8[] = {0x0f0f0400};
const u32 var700577cc[] = {0x00000000};
const u32 var700577d0[] = {0x64646400};
const u32 var700577d4[] = {0x00000000};
const u32 var700577d8[] = {0x00000000};
const u32 var700577dc[] = {0x00000000};
const u32 var700577e0[] = {0x00000000};
const u32 var700577e4[] = {0x00000000};
const u32 var700577e8[] = {0x00000000};
const u32 var700577ec[] = {0x00000000};
const u32 var700577f0[] = {0x00000000};
const u32 var700577f4[] = {0x00000000};
const u32 var700577f8[] = {0x00000000};
const u32 var700577fc[] = {0x00000000};
const u32 var70057800[] = {0x00000000};
const u32 var70057804[] = {0x00000000};
const u32 var70057808[] = {0x00000000};
const u32 var7005780c[] = {0x00000000};
const u32 var70057810[] = {0x00000000};
const u32 var70057814[] = {0x00000000};
const u32 var70057818[] = {0x00000001};
const u32 var7005781c[] = {0x00000002};
const u32 var70057820[] = {0x00000003};
const u32 var70057824[] = {0x00000004};
const u32 var70057828[] = {0x00000006};
const u32 var7005782c[] = {0x00000008};
const u32 var70057830[] = {0x0000000a};
const u32 var70057834[] = {0x0000000d};
const u32 var70057838[] = {0x00000004};
const u32 var7005783c[] = {0x00000005};
const u32 var70057840[] = {0x00000006};
const u32 var70057844[] = {0x00000007};
const u32 var70057848[] = {0x00000008};
const u32 var7005784c[] = {0x00000009};
const u32 var70057850[] = {0x0000000b};
const u32 var70057854[] = {0x0000000d};
const u32 var70057858[] = {0xffffffff};
const u32 var7005785c[] = {0xffffffff};
const u32 var70057860[] = {0x0005000b};
const u32 var70057864[] = {0x00110017};
const u32 var70057868[] = {0x001d0023};
const u32 var7005786c[] = {0x002b0035};
const u32 var70057870[] = {0x0041004f};
const u32 var70057874[] = {0x005f0073};
const u32 var70057878[] = {0x008b00a7};
const u32 var7005787c[] = {0x00c700ed};
const u32 var70057880[] = {0x011b014f};
const u32 var70057884[] = {0x018b01cf};
const u32 var70057888[] = {0x0209023f};
const u32 var7005788c[] = {0x0005000b};
const u32 var70057890[] = {0x00110017};
const u32 var70057894[] = {0x001d0023};
const u32 var70057898[] = {0x002b0035};
const u32 var7005789c[] = {0x0041004f};
const u32 var700578a0[] = {0x005f0071};
const u32 var700578a4[] = {0x008700a1};
const u32 var700578a8[] = {0x00c100e7};
const u32 var700578ac[] = {0x0115014b};
const u32 var700578b0[] = {0x018901cf};
const u32 var700578b4[] = {0x021b023f};
const u32 var700578b8[] = {0x0005000b};
const u32 var700578bc[] = {0x00110017};
const u32 var700578c0[] = {0x001d0023};
const u32 var700578c4[] = {0x002b0035};
const u32 var700578c8[] = {0x0041004f};
const u32 var700578cc[] = {0x005f0073};
const u32 var700578d0[] = {0x008b00a7};
const u32 var700578d4[] = {0x00c700ed};
const u32 var700578d8[] = {0x011b014f};
const u32 var700578dc[] = {0x018b01cf};
const u32 var700578e0[] = {0x0209023f};
const u32 var700578e4[] = {0x00030007};
const u32 var700578e8[] = {0x000b000f};
const u32 var700578ec[] = {0x00130017};
const u32 var700578f0[] = {0x001d0023};
const u32 var700578f4[] = {0x002b0033};
const u32 var700578f8[] = {0x003d0049};
const u32 var700578fc[] = {0x0059006d};
const u32 var70057900[] = {0x008500a1};
const u32 var70057904[] = {0x00c300ed};
const u32 var70057908[] = {0x011f0155};
const u32 var7005790c[] = {0x01a1023f};
const u32 var70057910[] = {0x00030007};
const u32 var70057914[] = {0x000b000f};
const u32 var70057918[] = {0x00130017};
const u32 var7005791c[] = {0x001d0023};
const u32 var70057920[] = {0x00290031};
const u32 var70057924[] = {0x003b0047};
const u32 var70057928[] = {0x00570069};
const u32 var7005792c[] = {0x007f009b};
const u32 var70057930[] = {0x00bd00e5};
const u32 var70057934[] = {0x01130149};
const u32 var70057938[] = {0x017f023f};
const u32 var7005793c[] = {0x00030007};
const u32 var70057940[] = {0x000b000f};
const u32 var70057944[] = {0x00130017};
const u32 var70057948[] = {0x001d0023};
const u32 var7005794c[] = {0x002b0035};
const u32 var70057950[] = {0x00410051};
const u32 var70057954[] = {0x0065007d};
const u32 var70057958[] = {0x009b00c1};
const u32 var7005795c[] = {0x00ef0127};
const u32 var70057960[] = {0x016b01bf};
const u32 var70057964[] = {0x0225023f};
const u32 var70057968[] = {0x03070b11};
const u32 var7005796c[] = {0x171f2937};
const u32 var70057970[] = {0x496383ad};
const u32 var70057974[] = {0xbf03070b};
const u32 var70057978[] = {0x1119232f};
const u32 var7005797c[] = {0x3d4f6787};
const u32 var70057980[] = {0xb3bf0307};
const u32 var70057984[] = {0x0b111923};
const u32 var70057988[] = {0x2f3d4f67};
const u32 var7005798c[] = {0x85adbf03};
const u32 var70057990[] = {0x070b0f15};
const u32 var70057994[] = {0x1d273341};
const u32 var70057998[] = {0x536987bf};
const u32 var7005799c[] = {0x03070b0f};
const u32 var700579a0[] = {0x151b2531};
const u32 var700579a4[] = {0x3f4f637d};
const u32 var700579a8[] = {0xbf03070b};
const u32 var700579ac[] = {0x0f151d29};
const u32 var700579b0[] = {0x394d6789};
const u32 var700579b4[] = {0xb3bf0000};
const u32 var700579b8[] = {0x00000006};
const u32 var700579bc[] = {0x000c0012};
const u32 var700579c0[] = {0x0018001e};
const u32 var700579c4[] = {0x0024002c};
const u32 var700579c8[] = {0x00360042};
const u32 var700579cc[] = {0x00500060};
const u32 var700579d0[] = {0x0074008c};
const u32 var700579d4[] = {0x00a800c8};
const u32 var700579d8[] = {0x00ee011c};
const u32 var700579dc[] = {0x0150018c};
const u32 var700579e0[] = {0x01d0020a};
const u32 var700579e4[] = {0x02400000};
const u32 var700579e8[] = {0x00040008};
const u32 var700579ec[] = {0x000c0012};
const u32 var700579f0[] = {0x00180020};
const u32 var700579f4[] = {0x002a0038};
const u32 var700579f8[] = {0x004a0064};
const u32 var700579fc[] = {0x008400ae};
const u32 var70057a00[] = {0x00c00000};
const u32 var70057a04[] = {0x0006000c};
const u32 var70057a08[] = {0x00120018};
const u32 var70057a0c[] = {0x001e0024};
const u32 var70057a10[] = {0x002c0036};
const u32 var70057a14[] = {0x00420050};
const u32 var70057a18[] = {0x00600072};
const u32 var70057a1c[] = {0x008800a2};
const u32 var70057a20[] = {0x00c200e8};
const u32 var70057a24[] = {0x0116014a};
const u32 var70057a28[] = {0x018a01d0};
const u32 var70057a2c[] = {0x021c0240};
const u32 var70057a30[] = {0x00000004};
const u32 var70057a34[] = {0x0008000c};
const u32 var70057a38[] = {0x0012001a};
const u32 var70057a3c[] = {0x00240030};
const u32 var70057a40[] = {0x003e0050};
const u32 var70057a44[] = {0x00680088};
const u32 var70057a48[] = {0x00b400c0};
const u32 var70057a4c[] = {0x00000006};
const u32 var70057a50[] = {0x000c0012};
const u32 var70057a54[] = {0x0018001e};
const u32 var70057a58[] = {0x0024002c};
const u32 var70057a5c[] = {0x00360042};
const u32 var70057a60[] = {0x00500060};
const u32 var70057a64[] = {0x0074008c};
const u32 var70057a68[] = {0x00a800c8};
const u32 var70057a6c[] = {0x00ee011c};
const u32 var70057a70[] = {0x0150018c};
const u32 var70057a74[] = {0x01d0020a};
const u32 var70057a78[] = {0x02400000};
const u32 var70057a7c[] = {0x00040008};
const u32 var70057a80[] = {0x000c0012};
const u32 var70057a84[] = {0x001a0024};
const u32 var70057a88[] = {0x0030003e};
const u32 var70057a8c[] = {0x00500068};
const u32 var70057a90[] = {0x008600ae};
const u32 var70057a94[] = {0x00c00000};
const u32 var70057a98[] = {0x00040008};
const u32 var70057a9c[] = {0x000c0010};
const u32 var70057aa0[] = {0x00140018};
const u32 var70057aa4[] = {0x001e0024};
const u32 var70057aa8[] = {0x002c0034};
const u32 var70057aac[] = {0x003e004a};
const u32 var70057ab0[] = {0x005a006e};
const u32 var70057ab4[] = {0x008600a2};
const u32 var70057ab8[] = {0x00c400ee};
const u32 var70057abc[] = {0x01200156};
const u32 var70057ac0[] = {0x01a20240};
const u32 var70057ac4[] = {0x00000004};
const u32 var70057ac8[] = {0x0008000c};
const u32 var70057acc[] = {0x00100016};
const u32 var70057ad0[] = {0x001e0028};
const u32 var70057ad4[] = {0x00340042};
const u32 var70057ad8[] = {0x0054006a};
const u32 var70057adc[] = {0x008800c0};
const u32 var70057ae0[] = {0x00000004};
const u32 var70057ae4[] = {0x0008000c};
const u32 var70057ae8[] = {0x00100014};
const u32 var70057aec[] = {0x0018001e};
const u32 var70057af0[] = {0x0024002a};
const u32 var70057af4[] = {0x0032003c};
const u32 var70057af8[] = {0x00480058};
const u32 var70057afc[] = {0x006a0080};
const u32 var70057b00[] = {0x009c00be};
const u32 var70057b04[] = {0x00e60114};
const u32 var70057b08[] = {0x014a0180};
const u32 var70057b0c[] = {0x02400000};
const u32 var70057b10[] = {0x00040008};
const u32 var70057b14[] = {0x000c0010};
const u32 var70057b18[] = {0x0016001c};
const u32 var70057b1c[] = {0x00260032};
const u32 var70057b20[] = {0x00400050};
const u32 var70057b24[] = {0x0064007e};
const u32 var70057b28[] = {0x00c00000};
const u32 var70057b2c[] = {0x00040008};
const u32 var70057b30[] = {0x000c0010};
const u32 var70057b34[] = {0x00140018};
const u32 var70057b38[] = {0x001e0024};
const u32 var70057b3c[] = {0x002c0036};
const u32 var70057b40[] = {0x00420052};
const u32 var70057b44[] = {0x0066007e};
const u32 var70057b48[] = {0x009c00c2};
const u32 var70057b4c[] = {0x00f00128};
const u32 var70057b50[] = {0x016c01c0};
const u32 var70057b54[] = {0x02260240};
const u32 var70057b58[] = {0x00000004};
const u32 var70057b5c[] = {0x0008000c};
const u32 var70057b60[] = {0x00100016};
const u32 var70057b64[] = {0x001e002a};
const u32 var70057b68[] = {0x003a004e};
const u32 var70057b6c[] = {0x0068008a};
const u32 var70057b70[] = {0x00b400c0};
const u32 var70057b74[] = {0x00060b10};
const u32 var70057b78[] = {0x1500060c};
const u32 var70057b7c[] = {0x00000000};
const u32 var70057b80[] = {0x03010101};
const u32 var70057b84[] = {0x02020203};
const u32 var70057b88[] = {0x03030404};
const u32 var70057b8c[] = {0x00010203};
const u32 var70057b90[] = {0x00010203};
const u32 var70057b94[] = {0x01020301};
const u32 var70057b98[] = {0x02030203};
const u32 var70057b9c[] = {0x00000001};
const u32 var70057ba0[] = {0x00020003};
const u32 var70057ba4[] = {0x00060007};
const u32 var70057ba8[] = {0x00080009};
const u32 var70057bac[] = {0x000c000d};
const u32 var70057bb0[] = {0x000e000f};
const u32 var70057bb4[] = {0x00040005};
const u32 var70057bb8[] = {0x00120013};
const u32 var70057bbc[] = {0x000a000b};
const u32 var70057bc0[] = {0x00180019};
const u32 var70057bc4[] = {0x00100011};
const u32 var70057bc8[] = {0x001e001f};
const u32 var70057bcc[] = {0x00140015};
const u32 var70057bd0[] = {0x00160017};
const u32 var70057bd4[] = {0x001a001b};
const u32 var70057bd8[] = {0x001c001d};
const u32 var70057bdc[] = {0x00200021};
const u32 var70057be0[] = {0x00220023};
const u32 var70057be4[] = {0x00240025};
const u32 var70057be8[] = {0x00260027};
const u32 var70057bec[] = {0x00280029};
const u32 var70057bf0[] = {0x002a002b};
const u32 var70057bf4[] = {0x002c002d};
const u32 var70057bf8[] = {0x002e002f};
const u32 var70057bfc[] = {0x00300031};
const u32 var70057c00[] = {0x00320033};
const u32 var70057c04[] = {0x00340035};
const u32 var70057c08[] = {0x00360037};
const u32 var70057c0c[] = {0x00380039};
const u32 var70057c10[] = {0x003a003b};
const u32 var70057c14[] = {0x003c003d};
const u32 var70057c18[] = {0x003e003f};
const u32 var70057c1c[] = {0x00400041};
const u32 var70057c20[] = {0x00420043};
const u32 var70057c24[] = {0x00440045};
const u32 var70057c28[] = {0x00460047};
const u32 var70057c2c[] = {0x00480049};
const u32 var70057c30[] = {0x004a004b};
const u32 var70057c34[] = {0x004c004d};
const u32 var70057c38[] = {0x005a005b};
const u32 var70057c3c[] = {0x004e004f};
const u32 var70057c40[] = {0x00500051};
const u32 var70057c44[] = {0x00520053};
const u32 var70057c48[] = {0x00600061};
const u32 var70057c4c[] = {0x00540055};
const u32 var70057c50[] = {0x00560057};
const u32 var70057c54[] = {0x00580059};
const u32 var70057c58[] = {0x00660067};
const u32 var70057c5c[] = {0x005c005d};
const u32 var70057c60[] = {0x005e005f};
const u32 var70057c64[] = {0x006c006d};
const u32 var70057c68[] = {0x006e006f};
const u32 var70057c6c[] = {0x00700071};
const u32 var70057c70[] = {0x00620063};
const u32 var70057c74[] = {0x00640065};
const u32 var70057c78[] = {0x00720073};
const u32 var70057c7c[] = {0x00740075};
const u32 var70057c80[] = {0x00760077};
const u32 var70057c84[] = {0x00680069};
const u32 var70057c88[] = {0x006a006b};
const u32 var70057c8c[] = {0x00780079};
const u32 var70057c90[] = {0x007a007b};
const u32 var70057c94[] = {0x007c007d};
const u32 var70057c98[] = {0x007e007f};
const u32 var70057c9c[] = {0x00800081};
const u32 var70057ca0[] = {0x00820083};
const u32 var70057ca4[] = {0x00900091};
const u32 var70057ca8[] = {0x00920093};
const u32 var70057cac[] = {0x00940095};
const u32 var70057cb0[] = {0x00a200a3};
const u32 var70057cb4[] = {0x00840085};
const u32 var70057cb8[] = {0x00860087};
const u32 var70057cbc[] = {0x00880089};
const u32 var70057cc0[] = {0x00960097};
const u32 var70057cc4[] = {0x00980099};
const u32 var70057cc8[] = {0x009a009b};
const u32 var70057ccc[] = {0x00a800a9};
const u32 var70057cd0[] = {0x008a008b};
const u32 var70057cd4[] = {0x008c008d};
const u32 var70057cd8[] = {0x008e008f};
const u32 var70057cdc[] = {0x009c009d};
const u32 var70057ce0[] = {0x009e009f};
const u32 var70057ce4[] = {0x00a000a1};
const u32 var70057ce8[] = {0x00ae00af};
const u32 var70057cec[] = {0x00a400a5};
const u32 var70057cf0[] = {0x00a600a7};
const u32 var70057cf4[] = {0x00b400b5};
const u32 var70057cf8[] = {0x00b600b7};
const u32 var70057cfc[] = {0x00b800b9};
const u32 var70057d00[] = {0x00c600c7};
const u32 var70057d04[] = {0x00c800c9};
const u32 var70057d08[] = {0x00ca00cb};
const u32 var70057d0c[] = {0x00d800d9};
const u32 var70057d10[] = {0x00aa00ab};
const u32 var70057d14[] = {0x00ac00ad};
const u32 var70057d18[] = {0x00ba00bb};
const u32 var70057d1c[] = {0x00bc00bd};
const u32 var70057d20[] = {0x00be00bf};
const u32 var70057d24[] = {0x00cc00cd};
const u32 var70057d28[] = {0x00ce00cf};
const u32 var70057d2c[] = {0x00d000d1};
const u32 var70057d30[] = {0x00de00df};
const u32 var70057d34[] = {0x00b000b1};
const u32 var70057d38[] = {0x00b200b3};
const u32 var70057d3c[] = {0x00c000c1};
const u32 var70057d40[] = {0x00c200c3};
const u32 var70057d44[] = {0x00c400c5};
const u32 var70057d48[] = {0x00d200d3};
const u32 var70057d4c[] = {0x00d400d5};
const u32 var70057d50[] = {0x00d600d7};
const u32 var70057d54[] = {0x00e400e5};
const u32 var70057d58[] = {0x00da00db};
const u32 var70057d5c[] = {0x00dc00dd};
const u32 var70057d60[] = {0x00ea00eb};
const u32 var70057d64[] = {0x00ec00ed};
const u32 var70057d68[] = {0x00ee00ef};
const u32 var70057d6c[] = {0x00fc00fd};
const u32 var70057d70[] = {0x00fe00ff};
const u32 var70057d74[] = {0x01000101};
const u32 var70057d78[] = {0x010e010f};
const u32 var70057d7c[] = {0x01100111};
const u32 var70057d80[] = {0x01120113};
const u32 var70057d84[] = {0x01200121};
const u32 var70057d88[] = {0x01220123};
const u32 var70057d8c[] = {0x00e000e1};
const u32 var70057d90[] = {0x00e200e3};
const u32 var70057d94[] = {0x00f000f1};
const u32 var70057d98[] = {0x00f200f3};
const u32 var70057d9c[] = {0x00f400f5};
const u32 var70057da0[] = {0x01020103};
const u32 var70057da4[] = {0x01040105};
const u32 var70057da8[] = {0x01060107};
const u32 var70057dac[] = {0x01140115};
const u32 var70057db0[] = {0x01160117};
const u32 var70057db4[] = {0x01180119};
const u32 var70057db8[] = {0x01260127};
const u32 var70057dbc[] = {0x01280129};
const u32 var70057dc0[] = {0x00e600e7};
const u32 var70057dc4[] = {0x00e800e9};
const u32 var70057dc8[] = {0x00f600f7};
const u32 var70057dcc[] = {0x00f800f9};
const u32 var70057dd0[] = {0x00fa00fb};
const u32 var70057dd4[] = {0x01080109};
const u32 var70057dd8[] = {0x010a010b};
const u32 var70057ddc[] = {0x010c010d};
const u32 var70057de0[] = {0x011a011b};
const u32 var70057de4[] = {0x011c011d};
const u32 var70057de8[] = {0x011e011f};
const u32 var70057dec[] = {0x012c012d};
const u32 var70057df0[] = {0x012e012f};
const u32 var70057df4[] = {0x01240125};
const u32 var70057df8[] = {0x01320133};
const u32 var70057dfc[] = {0x01340135};
const u32 var70057e00[] = {0x01360137};
const u32 var70057e04[] = {0x01440145};
const u32 var70057e08[] = {0x01460147};
const u32 var70057e0c[] = {0x01480149};
const u32 var70057e10[] = {0x01560157};
const u32 var70057e14[] = {0x01580159};
const u32 var70057e18[] = {0x015a015b};
const u32 var70057e1c[] = {0x01680169};
const u32 var70057e20[] = {0x016a016b};
const u32 var70057e24[] = {0x016c016d};
const u32 var70057e28[] = {0x017a017b};
const u32 var70057e2c[] = {0x017c017d};
const u32 var70057e30[] = {0x017e017f};
const u32 var70057e34[] = {0x012a012b};
const u32 var70057e38[] = {0x01380139};
const u32 var70057e3c[] = {0x013a013b};
const u32 var70057e40[] = {0x013c013d};
const u32 var70057e44[] = {0x014a014b};
const u32 var70057e48[] = {0x014c014d};
const u32 var70057e4c[] = {0x014e014f};
const u32 var70057e50[] = {0x015c015d};
const u32 var70057e54[] = {0x015e015f};
const u32 var70057e58[] = {0x01600161};
const u32 var70057e5c[] = {0x016e016f};
const u32 var70057e60[] = {0x01700171};
const u32 var70057e64[] = {0x01720173};
const u32 var70057e68[] = {0x01800181};
const u32 var70057e6c[] = {0x01820183};
const u32 var70057e70[] = {0x01840185};
const u32 var70057e74[] = {0x01300131};
const u32 var70057e78[] = {0x013e013f};
const u32 var70057e7c[] = {0x01400141};
const u32 var70057e80[] = {0x01420143};
const u32 var70057e84[] = {0x01500151};
const u32 var70057e88[] = {0x01520153};
const u32 var70057e8c[] = {0x01540155};
const u32 var70057e90[] = {0x01620163};
const u32 var70057e94[] = {0x01640165};
const u32 var70057e98[] = {0x01660167};
const u32 var70057e9c[] = {0x01740175};
const u32 var70057ea0[] = {0x01760177};
const u32 var70057ea4[] = {0x01780179};
const u32 var70057ea8[] = {0x01860187};
const u32 var70057eac[] = {0x01880189};
const u32 var70057eb0[] = {0x018a018b};
const u32 var70057eb4[] = {0x018c018d};
const u32 var70057eb8[] = {0x018e018f};
const u32 var70057ebc[] = {0x01900191};
const u32 var70057ec0[] = {0x019e019f};
const u32 var70057ec4[] = {0x01a001a1};
const u32 var70057ec8[] = {0x01a201a3};
const u32 var70057ecc[] = {0x01b001b1};
const u32 var70057ed0[] = {0x01b201b3};
const u32 var70057ed4[] = {0x01b401b5};
const u32 var70057ed8[] = {0x01c201c3};
const u32 var70057edc[] = {0x01c401c5};
const u32 var70057ee0[] = {0x01c601c7};
const u32 var70057ee4[] = {0x01d401d5};
const u32 var70057ee8[] = {0x01d601d7};
const u32 var70057eec[] = {0x01d801d9};
const u32 var70057ef0[] = {0x01e601e7};
const u32 var70057ef4[] = {0x01e801e9};
const u32 var70057ef8[] = {0x01ea01eb};
const u32 var70057efc[] = {0x01f801f9};
const u32 var70057f00[] = {0x01fa01fb};
const u32 var70057f04[] = {0x01fc01fd};
const u32 var70057f08[] = {0x01920193};
const u32 var70057f0c[] = {0x01940195};
const u32 var70057f10[] = {0x01960197};
const u32 var70057f14[] = {0x01a401a5};
const u32 var70057f18[] = {0x01a601a7};
const u32 var70057f1c[] = {0x01a801a9};
const u32 var70057f20[] = {0x01b601b7};
const u32 var70057f24[] = {0x01b801b9};
const u32 var70057f28[] = {0x01ba01bb};
const u32 var70057f2c[] = {0x01c801c9};
const u32 var70057f30[] = {0x01ca01cb};
const u32 var70057f34[] = {0x01cc01cd};
const u32 var70057f38[] = {0x01da01db};
const u32 var70057f3c[] = {0x01dc01dd};
const u32 var70057f40[] = {0x01de01df};
const u32 var70057f44[] = {0x01ec01ed};
const u32 var70057f48[] = {0x01ee01ef};
const u32 var70057f4c[] = {0x01f001f1};
const u32 var70057f50[] = {0x01fe01ff};
const u32 var70057f54[] = {0x02000201};
const u32 var70057f58[] = {0x02020203};
const u32 var70057f5c[] = {0x01980199};
const u32 var70057f60[] = {0x019a019b};
const u32 var70057f64[] = {0x019c019d};
const u32 var70057f68[] = {0x01aa01ab};
const u32 var70057f6c[] = {0x01ac01ad};
const u32 var70057f70[] = {0x01ae01af};
const u32 var70057f74[] = {0x01bc01bd};
const u32 var70057f78[] = {0x01be01bf};
const u32 var70057f7c[] = {0x01c001c1};
const u32 var70057f80[] = {0x01ce01cf};
const u32 var70057f84[] = {0x01d001d1};
const u32 var70057f88[] = {0x01d201d3};
const u32 var70057f8c[] = {0x01e001e1};
const u32 var70057f90[] = {0x01e201e3};
const u32 var70057f94[] = {0x01e401e5};
const u32 var70057f98[] = {0x01f201f3};
const u32 var70057f9c[] = {0x01f401f5};
const u32 var70057fa0[] = {0x01f601f7};
const u32 var70057fa4[] = {0x02040205};
const u32 var70057fa8[] = {0x02060207};
const u32 var70057fac[] = {0x02080209};
const u32 var70057fb0[] = {0x020a020b};
const u32 var70057fb4[] = {0x020c020d};
const u32 var70057fb8[] = {0x020e020f};
const u32 var70057fbc[] = {0x021c021d};
const u32 var70057fc0[] = {0x021e021f};
const u32 var70057fc4[] = {0x02200221};
const u32 var70057fc8[] = {0x022e022f};
const u32 var70057fcc[] = {0x02300231};
const u32 var70057fd0[] = {0x02320233};
const u32 var70057fd4[] = {0x02100211};
const u32 var70057fd8[] = {0x02120213};
const u32 var70057fdc[] = {0x02140215};
const u32 var70057fe0[] = {0x02220223};
const u32 var70057fe4[] = {0x02240225};
const u32 var70057fe8[] = {0x02260227};
const u32 var70057fec[] = {0x02340235};
const u32 var70057ff0[] = {0x02360237};
const u32 var70057ff4[] = {0x02380239};
const u32 var70057ff8[] = {0x02160217};
const u32 var70057ffc[] = {0x02180219};
const u32 var70058000[] = {0x021a021b};
const u32 var70058004[] = {0x02280229};
const u32 var70058008[] = {0x022a022b};
const u32 var7005800c[] = {0x022c022d};
const u32 var70058010[] = {0x023a023b};
const u32 var70058014[] = {0x023c023d};
const u32 var70058018[] = {0x023e023f};
const u32 var7005801c[] = {0x00000001};
const u32 var70058020[] = {0x00020003};
const u32 var70058024[] = {0x00060007};
const u32 var70058028[] = {0x00080009};
const u32 var7005802c[] = {0x000c000d};
const u32 var70058030[] = {0x000e000f};
const u32 var70058034[] = {0x00040005};
const u32 var70058038[] = {0x00120013};
const u32 var7005803c[] = {0x000a000b};
const u32 var70058040[] = {0x00180019};
const u32 var70058044[] = {0x00100011};
const u32 var70058048[] = {0x001e001f};
const u32 var7005804c[] = {0x00140015};
const u32 var70058050[] = {0x00160017};
const u32 var70058054[] = {0x001a001b};
const u32 var70058058[] = {0x001c001d};
const u32 var7005805c[] = {0x00200021};
const u32 var70058060[] = {0x00220023};
const u32 var70058064[] = {0x00240025};
const u32 var70058068[] = {0x00260027};
const u32 var7005806c[] = {0x00280029};
const u32 var70058070[] = {0x002a002b};
const u32 var70058074[] = {0x002c002d};
const u32 var70058078[] = {0x002e002f};
const u32 var7005807c[] = {0x00300031};
const u32 var70058080[] = {0x00320033};
const u32 var70058084[] = {0x00340035};
const u32 var70058088[] = {0x00360037};
const u32 var7005808c[] = {0x00380039};
const u32 var70058090[] = {0x003a003b};
const u32 var70058094[] = {0x00480049};
const u32 var70058098[] = {0x003c003d};
const u32 var7005809c[] = {0x003e003f};
const u32 var700580a0[] = {0x00400041};
const u32 var700580a4[] = {0x004e004f};
const u32 var700580a8[] = {0x00420043};
const u32 var700580ac[] = {0x00440045};
const u32 var700580b0[] = {0x00460047};
const u32 var700580b4[] = {0x00540055};
const u32 var700580b8[] = {0x004a004b};
const u32 var700580bc[] = {0x004c004d};
const u32 var700580c0[] = {0x005a005b};
const u32 var700580c4[] = {0x005c005d};
const u32 var700580c8[] = {0x005e005f};
const u32 var700580cc[] = {0x00500051};
const u32 var700580d0[] = {0x00520053};
const u32 var700580d4[] = {0x00600061};
const u32 var700580d8[] = {0x00620063};
const u32 var700580dc[] = {0x00640065};
const u32 var700580e0[] = {0x00560057};
const u32 var700580e4[] = {0x00580059};
const u32 var700580e8[] = {0x00660067};
const u32 var700580ec[] = {0x00680069};
const u32 var700580f0[] = {0x006a006b};
const u32 var700580f4[] = {0x006c006d};
const u32 var700580f8[] = {0x006e006f};
const u32 var700580fc[] = {0x00700071};
const u32 var70058100[] = {0x007e007f};
const u32 var70058104[] = {0x00800081};
const u32 var70058108[] = {0x00820083};
const u32 var7005810c[] = {0x00720073};
const u32 var70058110[] = {0x00740075};
const u32 var70058114[] = {0x00760077};
const u32 var70058118[] = {0x00840085};
const u32 var7005811c[] = {0x00860087};
const u32 var70058120[] = {0x00880089};
const u32 var70058124[] = {0x00780079};
const u32 var70058128[] = {0x007a007b};
const u32 var7005812c[] = {0x007c007d};
const u32 var70058130[] = {0x008a008b};
const u32 var70058134[] = {0x008c008d};
const u32 var70058138[] = {0x008e008f};
const u32 var7005813c[] = {0x00900091};
const u32 var70058140[] = {0x00920093};
const u32 var70058144[] = {0x00940095};
const u32 var70058148[] = {0x00a200a3};
const u32 var7005814c[] = {0x00a400a5};
const u32 var70058150[] = {0x00a600a7};
const u32 var70058154[] = {0x00b400b5};
const u32 var70058158[] = {0x00960097};
const u32 var7005815c[] = {0x00980099};
const u32 var70058160[] = {0x009a009b};
const u32 var70058164[] = {0x00a800a9};
const u32 var70058168[] = {0x00aa00ab};
const u32 var7005816c[] = {0x00ac00ad};
const u32 var70058170[] = {0x00ba00bb};
const u32 var70058174[] = {0x009c009d};
const u32 var70058178[] = {0x009e009f};
const u32 var7005817c[] = {0x00a000a1};
const u32 var70058180[] = {0x00ae00af};
const u32 var70058184[] = {0x00b000b1};
const u32 var70058188[] = {0x00b200b3};
const u32 var7005818c[] = {0x00c000c1};
const u32 var70058190[] = {0x00b600b7};
const u32 var70058194[] = {0x00b800b9};
const u32 var70058198[] = {0x00c600c7};
const u32 var7005819c[] = {0x00c800c9};
const u32 var700581a0[] = {0x00ca00cb};
const u32 var700581a4[] = {0x00d800d9};
const u32 var700581a8[] = {0x00da00db};
const u32 var700581ac[] = {0x00dc00dd};
const u32 var700581b0[] = {0x00ea00eb};
const u32 var700581b4[] = {0x00bc00bd};
const u32 var700581b8[] = {0x00be00bf};
const u32 var700581bc[] = {0x00cc00cd};
const u32 var700581c0[] = {0x00ce00cf};
const u32 var700581c4[] = {0x00d000d1};
const u32 var700581c8[] = {0x00de00df};
const u32 var700581cc[] = {0x00e000e1};
const u32 var700581d0[] = {0x00e200e3};
const u32 var700581d4[] = {0x00f000f1};
const u32 var700581d8[] = {0x00c200c3};
const u32 var700581dc[] = {0x00c400c5};
const u32 var700581e0[] = {0x00d200d3};
const u32 var700581e4[] = {0x00d400d5};
const u32 var700581e8[] = {0x00d600d7};
const u32 var700581ec[] = {0x00e400e5};
const u32 var700581f0[] = {0x00e600e7};
const u32 var700581f4[] = {0x00e800e9};
const u32 var700581f8[] = {0x00f600f7};
const u32 var700581fc[] = {0x00ec00ed};
const u32 var70058200[] = {0x00ee00ef};
const u32 var70058204[] = {0x00fc00fd};
const u32 var70058208[] = {0x00fe00ff};
const u32 var7005820c[] = {0x01000101};
const u32 var70058210[] = {0x010e010f};
const u32 var70058214[] = {0x01100111};
const u32 var70058218[] = {0x01120113};
const u32 var7005821c[] = {0x01200121};
const u32 var70058220[] = {0x01220123};
const u32 var70058224[] = {0x01240125};
const u32 var70058228[] = {0x01320133};
const u32 var7005822c[] = {0x00f200f3};
const u32 var70058230[] = {0x00f400f5};
const u32 var70058234[] = {0x01020103};
const u32 var70058238[] = {0x01040105};
const u32 var7005823c[] = {0x01060107};
const u32 var70058240[] = {0x01140115};
const u32 var70058244[] = {0x01160117};
const u32 var70058248[] = {0x01180119};
const u32 var7005824c[] = {0x01260127};
const u32 var70058250[] = {0x01280129};
const u32 var70058254[] = {0x012a012b};
const u32 var70058258[] = {0x01380139};
const u32 var7005825c[] = {0x00f800f9};
const u32 var70058260[] = {0x00fa00fb};
const u32 var70058264[] = {0x01080109};
const u32 var70058268[] = {0x010a010b};
const u32 var7005826c[] = {0x010c010d};
const u32 var70058270[] = {0x011a011b};
const u32 var70058274[] = {0x011c011d};
const u32 var70058278[] = {0x011e011f};
const u32 var7005827c[] = {0x012c012d};
const u32 var70058280[] = {0x012e012f};
const u32 var70058284[] = {0x01300131};
const u32 var70058288[] = {0x013e013f};
const u32 var7005828c[] = {0x01340135};
const u32 var70058290[] = {0x01360137};
const u32 var70058294[] = {0x01440145};
const u32 var70058298[] = {0x01460147};
const u32 var7005829c[] = {0x01480149};
const u32 var700582a0[] = {0x01560157};
const u32 var700582a4[] = {0x01580159};
const u32 var700582a8[] = {0x015a015b};
const u32 var700582ac[] = {0x01680169};
const u32 var700582b0[] = {0x016a016b};
const u32 var700582b4[] = {0x016c016d};
const u32 var700582b8[] = {0x017a017b};
const u32 var700582bc[] = {0x017c017d};
const u32 var700582c0[] = {0x017e017f};
const u32 var700582c4[] = {0x018c018d};
const u32 var700582c8[] = {0x018e018f};
const u32 var700582cc[] = {0x013a013b};
const u32 var700582d0[] = {0x013c013d};
const u32 var700582d4[] = {0x014a014b};
const u32 var700582d8[] = {0x014c014d};
const u32 var700582dc[] = {0x014e014f};
const u32 var700582e0[] = {0x015c015d};
const u32 var700582e4[] = {0x015e015f};
const u32 var700582e8[] = {0x01600161};
const u32 var700582ec[] = {0x016e016f};
const u32 var700582f0[] = {0x01700171};
const u32 var700582f4[] = {0x01720173};
const u32 var700582f8[] = {0x01800181};
const u32 var700582fc[] = {0x01820183};
const u32 var70058300[] = {0x01840185};
const u32 var70058304[] = {0x01920193};
const u32 var70058308[] = {0x01940195};
const u32 var7005830c[] = {0x01400141};
const u32 var70058310[] = {0x01420143};
const u32 var70058314[] = {0x01500151};
const u32 var70058318[] = {0x01520153};
const u32 var7005831c[] = {0x01540155};
const u32 var70058320[] = {0x01620163};
const u32 var70058324[] = {0x01640165};
const u32 var70058328[] = {0x01660167};
const u32 var7005832c[] = {0x01740175};
const u32 var70058330[] = {0x01760177};
const u32 var70058334[] = {0x01780179};
const u32 var70058338[] = {0x01860187};
const u32 var7005833c[] = {0x01880189};
const u32 var70058340[] = {0x018a018b};
const u32 var70058344[] = {0x01980199};
const u32 var70058348[] = {0x019a019b};
const u32 var7005834c[] = {0x01900191};
const u32 var70058350[] = {0x019e019f};
const u32 var70058354[] = {0x01a001a1};
const u32 var70058358[] = {0x01a201a3};
const u32 var7005835c[] = {0x01b001b1};
const u32 var70058360[] = {0x01b201b3};
const u32 var70058364[] = {0x01b401b5};
const u32 var70058368[] = {0x01c201c3};
const u32 var7005836c[] = {0x01c401c5};
const u32 var70058370[] = {0x01c601c7};
const u32 var70058374[] = {0x01d401d5};
const u32 var70058378[] = {0x01d601d7};
const u32 var7005837c[] = {0x01d801d9};
const u32 var70058380[] = {0x01e601e7};
const u32 var70058384[] = {0x01e801e9};
const u32 var70058388[] = {0x01ea01eb};
const u32 var7005838c[] = {0x01f801f9};
const u32 var70058390[] = {0x01fa01fb};
const u32 var70058394[] = {0x01fc01fd};
const u32 var70058398[] = {0x020a020b};
const u32 var7005839c[] = {0x020c020d};
const u32 var700583a0[] = {0x020e020f};
const u32 var700583a4[] = {0x01960197};
const u32 var700583a8[] = {0x01a401a5};
const u32 var700583ac[] = {0x01a601a7};
const u32 var700583b0[] = {0x01a801a9};
const u32 var700583b4[] = {0x01b601b7};
const u32 var700583b8[] = {0x01b801b9};
const u32 var700583bc[] = {0x01ba01bb};
const u32 var700583c0[] = {0x01c801c9};
const u32 var700583c4[] = {0x01ca01cb};
const u32 var700583c8[] = {0x01cc01cd};
const u32 var700583cc[] = {0x01da01db};
const u32 var700583d0[] = {0x01dc01dd};
const u32 var700583d4[] = {0x01de01df};
const u32 var700583d8[] = {0x01ec01ed};
const u32 var700583dc[] = {0x01ee01ef};
const u32 var700583e0[] = {0x01f001f1};
const u32 var700583e4[] = {0x01fe01ff};
const u32 var700583e8[] = {0x02000201};
const u32 var700583ec[] = {0x02020203};
const u32 var700583f0[] = {0x02100211};
const u32 var700583f4[] = {0x02120213};
const u32 var700583f8[] = {0x02140215};
const u32 var700583fc[] = {0x019c019d};
const u32 var70058400[] = {0x01aa01ab};
const u32 var70058404[] = {0x01ac01ad};
const u32 var70058408[] = {0x01ae01af};
const u32 var7005840c[] = {0x01bc01bd};
const u32 var70058410[] = {0x01be01bf};
const u32 var70058414[] = {0x01c001c1};
const u32 var70058418[] = {0x01ce01cf};
const u32 var7005841c[] = {0x01d001d1};
const u32 var70058420[] = {0x01d201d3};
const u32 var70058424[] = {0x01e001e1};
const u32 var70058428[] = {0x01e201e3};
const u32 var7005842c[] = {0x01e401e5};
const u32 var70058430[] = {0x01f201f3};
const u32 var70058434[] = {0x01f401f5};
const u32 var70058438[] = {0x01f601f7};
const u32 var7005843c[] = {0x02040205};
const u32 var70058440[] = {0x02060207};
const u32 var70058444[] = {0x02080209};
const u32 var70058448[] = {0x02160217};
const u32 var7005844c[] = {0x02180219};
const u32 var70058450[] = {0x021a021b};
const u32 var70058454[] = {0x021c021d};
const u32 var70058458[] = {0x021e021f};
const u32 var7005845c[] = {0x02200221};
const u32 var70058460[] = {0x022e022f};
const u32 var70058464[] = {0x02300231};
const u32 var70058468[] = {0x02320233};
const u32 var7005846c[] = {0x02220223};
const u32 var70058470[] = {0x02240225};
const u32 var70058474[] = {0x02260227};
const u32 var70058478[] = {0x02340235};
const u32 var7005847c[] = {0x02360237};
const u32 var70058480[] = {0x02380239};
const u32 var70058484[] = {0x02280229};
const u32 var70058488[] = {0x022a022b};
const u32 var7005848c[] = {0x022c022d};
const u32 var70058490[] = {0x023a023b};
const u32 var70058494[] = {0x023c023d};
const u32 var70058498[] = {0x023e023f};
const u32 var7005849c[] = {0x00000001};
const u32 var700584a0[] = {0x00020003};
const u32 var700584a4[] = {0x00060007};
const u32 var700584a8[] = {0x00080009};
const u32 var700584ac[] = {0x000c000d};
const u32 var700584b0[] = {0x000e000f};
const u32 var700584b4[] = {0x00040005};
const u32 var700584b8[] = {0x00120013};
const u32 var700584bc[] = {0x000a000b};
const u32 var700584c0[] = {0x00180019};
const u32 var700584c4[] = {0x00100011};
const u32 var700584c8[] = {0x001e001f};
const u32 var700584cc[] = {0x00140015};
const u32 var700584d0[] = {0x00160017};
const u32 var700584d4[] = {0x001a001b};
const u32 var700584d8[] = {0x001c001d};
const u32 var700584dc[] = {0x00200021};
const u32 var700584e0[] = {0x00220023};
const u32 var700584e4[] = {0x00240025};
const u32 var700584e8[] = {0x00260027};
const u32 var700584ec[] = {0x00280029};
const u32 var700584f0[] = {0x002a002b};
const u32 var700584f4[] = {0x002c002d};
const u32 var700584f8[] = {0x002e002f};
const u32 var700584fc[] = {0x00300031};
const u32 var70058500[] = {0x00320033};
const u32 var70058504[] = {0x00340035};
const u32 var70058508[] = {0x00360037};
const u32 var7005850c[] = {0x00380039};
const u32 var70058510[] = {0x003a003b};
const u32 var70058514[] = {0x00480049};
const u32 var70058518[] = {0x003c003d};
const u32 var7005851c[] = {0x003e003f};
const u32 var70058520[] = {0x00400041};
const u32 var70058524[] = {0x004e004f};
const u32 var70058528[] = {0x00420043};
const u32 var7005852c[] = {0x00440045};
const u32 var70058530[] = {0x00460047};
const u32 var70058534[] = {0x00540055};
const u32 var70058538[] = {0x004a004b};
const u32 var7005853c[] = {0x004c004d};
const u32 var70058540[] = {0x005a005b};
const u32 var70058544[] = {0x005c005d};
const u32 var70058548[] = {0x005e005f};
const u32 var7005854c[] = {0x00500051};
const u32 var70058550[] = {0x00520053};
const u32 var70058554[] = {0x00600061};
const u32 var70058558[] = {0x00620063};
const u32 var7005855c[] = {0x00640065};
const u32 var70058560[] = {0x00560057};
const u32 var70058564[] = {0x00580059};
const u32 var70058568[] = {0x00660067};
const u32 var7005856c[] = {0x00680069};
const u32 var70058570[] = {0x006a006b};
const u32 var70058574[] = {0x006c006d};
const u32 var70058578[] = {0x006e006f};
const u32 var7005857c[] = {0x00700071};
const u32 var70058580[] = {0x007e007f};
const u32 var70058584[] = {0x00800081};
const u32 var70058588[] = {0x00820083};
const u32 var7005858c[] = {0x00720073};
const u32 var70058590[] = {0x00740075};
const u32 var70058594[] = {0x00760077};
const u32 var70058598[] = {0x00840085};
const u32 var7005859c[] = {0x00860087};
const u32 var700585a0[] = {0x00880089};
const u32 var700585a4[] = {0x00780079};
const u32 var700585a8[] = {0x007a007b};
const u32 var700585ac[] = {0x007c007d};
const u32 var700585b0[] = {0x008a008b};
const u32 var700585b4[] = {0x008c008d};
const u32 var700585b8[] = {0x008e008f};
const u32 var700585bc[] = {0x00900091};
const u32 var700585c0[] = {0x00920093};
const u32 var700585c4[] = {0x00940095};
const u32 var700585c8[] = {0x00a200a3};
const u32 var700585cc[] = {0x00a400a5};
const u32 var700585d0[] = {0x00a600a7};
const u32 var700585d4[] = {0x00b400b5};
const u32 var700585d8[] = {0x00960097};
const u32 var700585dc[] = {0x00980099};
const u32 var700585e0[] = {0x009a009b};
const u32 var700585e4[] = {0x00a800a9};
const u32 var700585e8[] = {0x00aa00ab};
const u32 var700585ec[] = {0x00ac00ad};
const u32 var700585f0[] = {0x00ba00bb};
const u32 var700585f4[] = {0x009c009d};
const u32 var700585f8[] = {0x009e009f};
const u32 var700585fc[] = {0x00a000a1};
const u32 var70058600[] = {0x00ae00af};
const u32 var70058604[] = {0x00b000b1};
const u32 var70058608[] = {0x00b200b3};
const u32 var7005860c[] = {0x00c000c1};
const u32 var70058610[] = {0x00b600b7};
const u32 var70058614[] = {0x00b800b9};
const u32 var70058618[] = {0x00c600c7};
const u32 var7005861c[] = {0x00c800c9};
const u32 var70058620[] = {0x00ca00cb};
const u32 var70058624[] = {0x00d800d9};
const u32 var70058628[] = {0x00da00db};
const u32 var7005862c[] = {0x00dc00dd};
const u32 var70058630[] = {0x00ea00eb};
const u32 var70058634[] = {0x00bc00bd};
const u32 var70058638[] = {0x00be00bf};
const u32 var7005863c[] = {0x00cc00cd};
const u32 var70058640[] = {0x00ce00cf};
const u32 var70058644[] = {0x00d000d1};
const u32 var70058648[] = {0x00de00df};
const u32 var7005864c[] = {0x00e000e1};
const u32 var70058650[] = {0x00e200e3};
const u32 var70058654[] = {0x00f000f1};
const u32 var70058658[] = {0x00c200c3};
const u32 var7005865c[] = {0x00c400c5};
const u32 var70058660[] = {0x00d200d3};
const u32 var70058664[] = {0x00d400d5};
const u32 var70058668[] = {0x00d600d7};
const u32 var7005866c[] = {0x00e400e5};
const u32 var70058670[] = {0x00e600e7};
const u32 var70058674[] = {0x00e800e9};
const u32 var70058678[] = {0x00f600f7};
const u32 var7005867c[] = {0x00ec00ed};
const u32 var70058680[] = {0x00ee00ef};
const u32 var70058684[] = {0x00fc00fd};
const u32 var70058688[] = {0x00fe00ff};
const u32 var7005868c[] = {0x01000101};
const u32 var70058690[] = {0x010e010f};
const u32 var70058694[] = {0x01100111};
const u32 var70058698[] = {0x01120113};
const u32 var7005869c[] = {0x01200121};
const u32 var700586a0[] = {0x01220123};
const u32 var700586a4[] = {0x01240125};
const u32 var700586a8[] = {0x01320133};
const u32 var700586ac[] = {0x00f200f3};
const u32 var700586b0[] = {0x00f400f5};
const u32 var700586b4[] = {0x01020103};
const u32 var700586b8[] = {0x01040105};
const u32 var700586bc[] = {0x01060107};
const u32 var700586c0[] = {0x01140115};
const u32 var700586c4[] = {0x01160117};
const u32 var700586c8[] = {0x01180119};
const u32 var700586cc[] = {0x01260127};
const u32 var700586d0[] = {0x01280129};
const u32 var700586d4[] = {0x012a012b};
const u32 var700586d8[] = {0x01380139};
const u32 var700586dc[] = {0x00f800f9};
const u32 var700586e0[] = {0x00fa00fb};
const u32 var700586e4[] = {0x01080109};
const u32 var700586e8[] = {0x010a010b};
const u32 var700586ec[] = {0x010c010d};
const u32 var700586f0[] = {0x011a011b};
const u32 var700586f4[] = {0x011c011d};
const u32 var700586f8[] = {0x011e011f};
const u32 var700586fc[] = {0x012c012d};
const u32 var70058700[] = {0x012e012f};
const u32 var70058704[] = {0x01300131};
const u32 var70058708[] = {0x013e013f};
const u32 var7005870c[] = {0x01340135};
const u32 var70058710[] = {0x01360137};
const u32 var70058714[] = {0x01440145};
const u32 var70058718[] = {0x01460147};
const u32 var7005871c[] = {0x01480149};
const u32 var70058720[] = {0x01560157};
const u32 var70058724[] = {0x01580159};
const u32 var70058728[] = {0x015a015b};
const u32 var7005872c[] = {0x01680169};
const u32 var70058730[] = {0x016a016b};
const u32 var70058734[] = {0x016c016d};
const u32 var70058738[] = {0x017a017b};
const u32 var7005873c[] = {0x017c017d};
const u32 var70058740[] = {0x017e017f};
const u32 var70058744[] = {0x018c018d};
const u32 var70058748[] = {0x013a013b};
const u32 var7005874c[] = {0x013c013d};
const u32 var70058750[] = {0x014a014b};
const u32 var70058754[] = {0x014c014d};
const u32 var70058758[] = {0x014e014f};
const u32 var7005875c[] = {0x015c015d};
const u32 var70058760[] = {0x015e015f};
const u32 var70058764[] = {0x01600161};
const u32 var70058768[] = {0x016e016f};
const u32 var7005876c[] = {0x01700171};
const u32 var70058770[] = {0x01720173};
const u32 var70058774[] = {0x01800181};
const u32 var70058778[] = {0x01820183};
const u32 var7005877c[] = {0x01840185};
const u32 var70058780[] = {0x01920193};
const u32 var70058784[] = {0x01400141};
const u32 var70058788[] = {0x01420143};
const u32 var7005878c[] = {0x01500151};
const u32 var70058790[] = {0x01520153};
const u32 var70058794[] = {0x01540155};
const u32 var70058798[] = {0x01620163};
const u32 var7005879c[] = {0x01640165};
const u32 var700587a0[] = {0x01660167};
const u32 var700587a4[] = {0x01740175};
const u32 var700587a8[] = {0x01760177};
const u32 var700587ac[] = {0x01780179};
const u32 var700587b0[] = {0x01860187};
const u32 var700587b4[] = {0x01880189};
const u32 var700587b8[] = {0x018a018b};
const u32 var700587bc[] = {0x01980199};
const u32 var700587c0[] = {0x018e018f};
const u32 var700587c4[] = {0x01900191};
const u32 var700587c8[] = {0x019e019f};
const u32 var700587cc[] = {0x01a001a1};
const u32 var700587d0[] = {0x01a201a3};
const u32 var700587d4[] = {0x01b001b1};
const u32 var700587d8[] = {0x01b201b3};
const u32 var700587dc[] = {0x01b401b5};
const u32 var700587e0[] = {0x01c201c3};
const u32 var700587e4[] = {0x01c401c5};
const u32 var700587e8[] = {0x01c601c7};
const u32 var700587ec[] = {0x01d401d5};
const u32 var700587f0[] = {0x01d601d7};
const u32 var700587f4[] = {0x01d801d9};
const u32 var700587f8[] = {0x01e601e7};
const u32 var700587fc[] = {0x01e801e9};
const u32 var70058800[] = {0x01ea01eb};
const u32 var70058804[] = {0x01f801f9};
const u32 var70058808[] = {0x01fa01fb};
const u32 var7005880c[] = {0x01fc01fd};
const u32 var70058810[] = {0x01940195};
const u32 var70058814[] = {0x01960197};
const u32 var70058818[] = {0x01a401a5};
const u32 var7005881c[] = {0x01a601a7};
const u32 var70058820[] = {0x01a801a9};
const u32 var70058824[] = {0x01b601b7};
const u32 var70058828[] = {0x01b801b9};
const u32 var7005882c[] = {0x01ba01bb};
const u32 var70058830[] = {0x01c801c9};
const u32 var70058834[] = {0x01ca01cb};
const u32 var70058838[] = {0x01cc01cd};
const u32 var7005883c[] = {0x01da01db};
const u32 var70058840[] = {0x01dc01dd};
const u32 var70058844[] = {0x01de01df};
const u32 var70058848[] = {0x01ec01ed};
const u32 var7005884c[] = {0x01ee01ef};
const u32 var70058850[] = {0x01f001f1};
const u32 var70058854[] = {0x01fe01ff};
const u32 var70058858[] = {0x02000201};
const u32 var7005885c[] = {0x02020203};
const u32 var70058860[] = {0x019a019b};
const u32 var70058864[] = {0x019c019d};
const u32 var70058868[] = {0x01aa01ab};
const u32 var7005886c[] = {0x01ac01ad};
const u32 var70058870[] = {0x01ae01af};
const u32 var70058874[] = {0x01bc01bd};
const u32 var70058878[] = {0x01be01bf};
const u32 var7005887c[] = {0x01c001c1};
const u32 var70058880[] = {0x01ce01cf};
const u32 var70058884[] = {0x01d001d1};
const u32 var70058888[] = {0x01d201d3};
const u32 var7005888c[] = {0x01e001e1};
const u32 var70058890[] = {0x01e201e3};
const u32 var70058894[] = {0x01e401e5};
const u32 var70058898[] = {0x01f201f3};
const u32 var7005889c[] = {0x01f401f5};
const u32 var700588a0[] = {0x01f601f7};
const u32 var700588a4[] = {0x02040205};
const u32 var700588a8[] = {0x02060207};
const u32 var700588ac[] = {0x02080209};
const u32 var700588b0[] = {0x020a020b};
const u32 var700588b4[] = {0x020c020d};
const u32 var700588b8[] = {0x020e020f};
const u32 var700588bc[] = {0x021c021d};
const u32 var700588c0[] = {0x021e021f};
const u32 var700588c4[] = {0x02200221};
const u32 var700588c8[] = {0x022e022f};
const u32 var700588cc[] = {0x02300231};
const u32 var700588d0[] = {0x02320233};
const u32 var700588d4[] = {0x02100211};
const u32 var700588d8[] = {0x02120213};
const u32 var700588dc[] = {0x02140215};
const u32 var700588e0[] = {0x02220223};
const u32 var700588e4[] = {0x02240225};
const u32 var700588e8[] = {0x02260227};
const u32 var700588ec[] = {0x02340235};
const u32 var700588f0[] = {0x02360237};
const u32 var700588f4[] = {0x02380239};
const u32 var700588f8[] = {0x02160217};
const u32 var700588fc[] = {0x02180219};
const u32 var70058900[] = {0x021a021b};
const u32 var70058904[] = {0x02280229};
const u32 var70058908[] = {0x022a022b};
const u32 var7005890c[] = {0x022c022d};
const u32 var70058910[] = {0x023a023b};
const u32 var70058914[] = {0x023c023d};
const u32 var70058918[] = {0x023e023f};
const u32 var7005891c[] = {0x00000001};
const u32 var70058920[] = {0x00020003};
const u32 var70058924[] = {0x00060007};
const u32 var70058928[] = {0x00080009};
const u32 var7005892c[] = {0x000c000d};
const u32 var70058930[] = {0x000e000f};
const u32 var70058934[] = {0x00040005};
const u32 var70058938[] = {0x00120013};
const u32 var7005893c[] = {0x000a000b};
const u32 var70058940[] = {0x00180019};
const u32 var70058944[] = {0x00100011};
const u32 var70058948[] = {0x001e001f};
const u32 var7005894c[] = {0x00140015};
const u32 var70058950[] = {0x00160017};
const u32 var70058954[] = {0x001a001b};
const u32 var70058958[] = {0x001c001d};
const u32 var7005895c[] = {0x00200021};
const u32 var70058960[] = {0x00220023};
const u32 var70058964[] = {0x00240025};
const u32 var70058968[] = {0x00260027};
const u32 var7005896c[] = {0x002a002b};
const u32 var70058970[] = {0x002c002d};
const u32 var70058974[] = {0x00300031};
const u32 var70058978[] = {0x00320033};
const u32 var7005897c[] = {0x00280029};
const u32 var70058980[] = {0x00360037};
const u32 var70058984[] = {0x00380039};
const u32 var70058988[] = {0x002e002f};
const u32 var7005898c[] = {0x003c003d};
const u32 var70058990[] = {0x003e003f};
const u32 var70058994[] = {0x00340035};
const u32 var70058998[] = {0x00420043};
const u32 var7005899c[] = {0x00440045};
const u32 var700589a0[] = {0x003a003b};
const u32 var700589a4[] = {0x00480049};
const u32 var700589a8[] = {0x004a004b};
const u32 var700589ac[] = {0x004c004d};
const u32 var700589b0[] = {0x00400041};
const u32 var700589b4[] = {0x004e004f};
const u32 var700589b8[] = {0x00500051};
const u32 var700589bc[] = {0x00520053};
const u32 var700589c0[] = {0x00460047};
const u32 var700589c4[] = {0x00540055};
const u32 var700589c8[] = {0x00560057};
const u32 var700589cc[] = {0x00580059};
const u32 var700589d0[] = {0x005a005b};
const u32 var700589d4[] = {0x005c005d};
const u32 var700589d8[] = {0x005e005f};
const u32 var700589dc[] = {0x006c006d};
const u32 var700589e0[] = {0x006e006f};
const u32 var700589e4[] = {0x00600061};
const u32 var700589e8[] = {0x00620063};
const u32 var700589ec[] = {0x00640065};
const u32 var700589f0[] = {0x00720073};
const u32 var700589f4[] = {0x00740075};
const u32 var700589f8[] = {0x00660067};
const u32 var700589fc[] = {0x00680069};
const u32 var70058a00[] = {0x006a006b};
const u32 var70058a04[] = {0x00780079};
const u32 var70058a08[] = {0x007a007b};
const u32 var70058a0c[] = {0x00700071};
const u32 var70058a10[] = {0x007e007f};
const u32 var70058a14[] = {0x00800081};
const u32 var70058a18[] = {0x00820083};
const u32 var70058a1c[] = {0x00900091};
const u32 var70058a20[] = {0x00920093};
const u32 var70058a24[] = {0x00760077};
const u32 var70058a28[] = {0x00840085};
const u32 var70058a2c[] = {0x00860087};
const u32 var70058a30[] = {0x00880089};
const u32 var70058a34[] = {0x00960097};
const u32 var70058a38[] = {0x00980099};
const u32 var70058a3c[] = {0x007c007d};
const u32 var70058a40[] = {0x008a008b};
const u32 var70058a44[] = {0x008c008d};
const u32 var70058a48[] = {0x008e008f};
const u32 var70058a4c[] = {0x009c009d};
const u32 var70058a50[] = {0x009e009f};
const u32 var70058a54[] = {0x00940095};
const u32 var70058a58[] = {0x00a200a3};
const u32 var70058a5c[] = {0x00a400a5};
const u32 var70058a60[] = {0x00a600a7};
const u32 var70058a64[] = {0x00b400b5};
const u32 var70058a68[] = {0x00b600b7};
const u32 var70058a6c[] = {0x00b800b9};
const u32 var70058a70[] = {0x009a009b};
const u32 var70058a74[] = {0x00a800a9};
const u32 var70058a78[] = {0x00aa00ab};
const u32 var70058a7c[] = {0x00ac00ad};
const u32 var70058a80[] = {0x00ba00bb};
const u32 var70058a84[] = {0x00bc00bd};
const u32 var70058a88[] = {0x00be00bf};
const u32 var70058a8c[] = {0x00a000a1};
const u32 var70058a90[] = {0x00ae00af};
const u32 var70058a94[] = {0x00b000b1};
const u32 var70058a98[] = {0x00b200b3};
const u32 var70058a9c[] = {0x00c000c1};
const u32 var70058aa0[] = {0x00c200c3};
const u32 var70058aa4[] = {0x00c400c5};
const u32 var70058aa8[] = {0x00c600c7};
const u32 var70058aac[] = {0x00c800c9};
const u32 var70058ab0[] = {0x00ca00cb};
const u32 var70058ab4[] = {0x00d800d9};
const u32 var70058ab8[] = {0x00da00db};
const u32 var70058abc[] = {0x00dc00dd};
const u32 var70058ac0[] = {0x00ea00eb};
const u32 var70058ac4[] = {0x00ec00ed};
const u32 var70058ac8[] = {0x00ee00ef};
const u32 var70058acc[] = {0x00cc00cd};
const u32 var70058ad0[] = {0x00ce00cf};
const u32 var70058ad4[] = {0x00d000d1};
const u32 var70058ad8[] = {0x00de00df};
const u32 var70058adc[] = {0x00e000e1};
const u32 var70058ae0[] = {0x00e200e3};
const u32 var70058ae4[] = {0x00f000f1};
const u32 var70058ae8[] = {0x00f200f3};
const u32 var70058aec[] = {0x00f400f5};
const u32 var70058af0[] = {0x00d200d3};
const u32 var70058af4[] = {0x00d400d5};
const u32 var70058af8[] = {0x00d600d7};
const u32 var70058afc[] = {0x00e400e5};
const u32 var70058b00[] = {0x00e600e7};
const u32 var70058b04[] = {0x00e800e9};
const u32 var70058b08[] = {0x00f600f7};
const u32 var70058b0c[] = {0x00f800f9};
const u32 var70058b10[] = {0x00fa00fb};
const u32 var70058b14[] = {0x00fc00fd};
const u32 var70058b18[] = {0x00fe00ff};
const u32 var70058b1c[] = {0x01000101};
const u32 var70058b20[] = {0x010e010f};
const u32 var70058b24[] = {0x01100111};
const u32 var70058b28[] = {0x01120113};
const u32 var70058b2c[] = {0x01200121};
const u32 var70058b30[] = {0x01220123};
const u32 var70058b34[] = {0x01240125};
const u32 var70058b38[] = {0x01320133};
const u32 var70058b3c[] = {0x01340135};
const u32 var70058b40[] = {0x01020103};
const u32 var70058b44[] = {0x01040105};
const u32 var70058b48[] = {0x01060107};
const u32 var70058b4c[] = {0x01140115};
const u32 var70058b50[] = {0x01160117};
const u32 var70058b54[] = {0x01180119};
const u32 var70058b58[] = {0x01260127};
const u32 var70058b5c[] = {0x01280129};
const u32 var70058b60[] = {0x012a012b};
const u32 var70058b64[] = {0x01380139};
const u32 var70058b68[] = {0x013a013b};
const u32 var70058b6c[] = {0x01080109};
const u32 var70058b70[] = {0x010a010b};
const u32 var70058b74[] = {0x010c010d};
const u32 var70058b78[] = {0x011a011b};
const u32 var70058b7c[] = {0x011c011d};
const u32 var70058b80[] = {0x011e011f};
const u32 var70058b84[] = {0x012c012d};
const u32 var70058b88[] = {0x012e012f};
const u32 var70058b8c[] = {0x01300131};
const u32 var70058b90[] = {0x013e013f};
const u32 var70058b94[] = {0x01400141};
const u32 var70058b98[] = {0x01360137};
const u32 var70058b9c[] = {0x01440145};
const u32 var70058ba0[] = {0x01460147};
const u32 var70058ba4[] = {0x01480149};
const u32 var70058ba8[] = {0x01560157};
const u32 var70058bac[] = {0x01580159};
const u32 var70058bb0[] = {0x015a015b};
const u32 var70058bb4[] = {0x01680169};
const u32 var70058bb8[] = {0x016a016b};
const u32 var70058bbc[] = {0x016c016d};
const u32 var70058bc0[] = {0x017a017b};
const u32 var70058bc4[] = {0x017c017d};
const u32 var70058bc8[] = {0x017e017f};
const u32 var70058bcc[] = {0x018c018d};
const u32 var70058bd0[] = {0x018e018f};
const u32 var70058bd4[] = {0x013c013d};
const u32 var70058bd8[] = {0x014a014b};
const u32 var70058bdc[] = {0x014c014d};
const u32 var70058be0[] = {0x014e014f};
const u32 var70058be4[] = {0x015c015d};
const u32 var70058be8[] = {0x015e015f};
const u32 var70058bec[] = {0x01600161};
const u32 var70058bf0[] = {0x016e016f};
const u32 var70058bf4[] = {0x01700171};
const u32 var70058bf8[] = {0x01720173};
const u32 var70058bfc[] = {0x01800181};
const u32 var70058c00[] = {0x01820183};
const u32 var70058c04[] = {0x01840185};
const u32 var70058c08[] = {0x01920193};
const u32 var70058c0c[] = {0x01940195};
const u32 var70058c10[] = {0x01420143};
const u32 var70058c14[] = {0x01500151};
const u32 var70058c18[] = {0x01520153};
const u32 var70058c1c[] = {0x01540155};
const u32 var70058c20[] = {0x01620163};
const u32 var70058c24[] = {0x01640165};
const u32 var70058c28[] = {0x01660167};
const u32 var70058c2c[] = {0x01740175};
const u32 var70058c30[] = {0x01760177};
const u32 var70058c34[] = {0x01780179};
const u32 var70058c38[] = {0x01860187};
const u32 var70058c3c[] = {0x01880189};
const u32 var70058c40[] = {0x018a018b};
const u32 var70058c44[] = {0x01980199};
const u32 var70058c48[] = {0x019a019b};
const u32 var70058c4c[] = {0x01900191};
const u32 var70058c50[] = {0x019e019f};
const u32 var70058c54[] = {0x01a001a1};
const u32 var70058c58[] = {0x01a201a3};
const u32 var70058c5c[] = {0x01b001b1};
const u32 var70058c60[] = {0x01b201b3};
const u32 var70058c64[] = {0x01b401b5};
const u32 var70058c68[] = {0x01c201c3};
const u32 var70058c6c[] = {0x01c401c5};
const u32 var70058c70[] = {0x01c601c7};
const u32 var70058c74[] = {0x01d401d5};
const u32 var70058c78[] = {0x01d601d7};
const u32 var70058c7c[] = {0x01d801d9};
const u32 var70058c80[] = {0x01e601e7};
const u32 var70058c84[] = {0x01e801e9};
const u32 var70058c88[] = {0x01ea01eb};
const u32 var70058c8c[] = {0x01f801f9};
const u32 var70058c90[] = {0x01fa01fb};
const u32 var70058c94[] = {0x01fc01fd};
const u32 var70058c98[] = {0x020a020b};
const u32 var70058c9c[] = {0x020c020d};
const u32 var70058ca0[] = {0x020e020f};
const u32 var70058ca4[] = {0x021c021d};
const u32 var70058ca8[] = {0x021e021f};
const u32 var70058cac[] = {0x02200221};
const u32 var70058cb0[] = {0x022e022f};
const u32 var70058cb4[] = {0x02300231};
const u32 var70058cb8[] = {0x02320233};
const u32 var70058cbc[] = {0x01960197};
const u32 var70058cc0[] = {0x01a401a5};
const u32 var70058cc4[] = {0x01a601a7};
const u32 var70058cc8[] = {0x01a801a9};
const u32 var70058ccc[] = {0x01b601b7};
const u32 var70058cd0[] = {0x01b801b9};
const u32 var70058cd4[] = {0x01ba01bb};
const u32 var70058cd8[] = {0x01c801c9};
const u32 var70058cdc[] = {0x01ca01cb};
const u32 var70058ce0[] = {0x01cc01cd};
const u32 var70058ce4[] = {0x01da01db};
const u32 var70058ce8[] = {0x01dc01dd};
const u32 var70058cec[] = {0x01de01df};
const u32 var70058cf0[] = {0x01ec01ed};
const u32 var70058cf4[] = {0x01ee01ef};
const u32 var70058cf8[] = {0x01f001f1};
const u32 var70058cfc[] = {0x01fe01ff};
const u32 var70058d00[] = {0x02000201};
const u32 var70058d04[] = {0x02020203};
const u32 var70058d08[] = {0x02100211};
const u32 var70058d0c[] = {0x02120213};
const u32 var70058d10[] = {0x02140215};
const u32 var70058d14[] = {0x02220223};
const u32 var70058d18[] = {0x02240225};
const u32 var70058d1c[] = {0x02260227};
const u32 var70058d20[] = {0x02340235};
const u32 var70058d24[] = {0x02360237};
const u32 var70058d28[] = {0x02380239};
const u32 var70058d2c[] = {0x019c019d};
const u32 var70058d30[] = {0x01aa01ab};
const u32 var70058d34[] = {0x01ac01ad};
const u32 var70058d38[] = {0x01ae01af};
const u32 var70058d3c[] = {0x01bc01bd};
const u32 var70058d40[] = {0x01be01bf};
const u32 var70058d44[] = {0x01c001c1};
const u32 var70058d48[] = {0x01ce01cf};
const u32 var70058d4c[] = {0x01d001d1};
const u32 var70058d50[] = {0x01d201d3};
const u32 var70058d54[] = {0x01e001e1};
const u32 var70058d58[] = {0x01e201e3};
const u32 var70058d5c[] = {0x01e401e5};
const u32 var70058d60[] = {0x01f201f3};
const u32 var70058d64[] = {0x01f401f5};
const u32 var70058d68[] = {0x01f601f7};
const u32 var70058d6c[] = {0x02040205};
const u32 var70058d70[] = {0x02060207};
const u32 var70058d74[] = {0x02080209};
const u32 var70058d78[] = {0x02160217};
const u32 var70058d7c[] = {0x02180219};
const u32 var70058d80[] = {0x021a021b};
const u32 var70058d84[] = {0x02280229};
const u32 var70058d88[] = {0x022a022b};
const u32 var70058d8c[] = {0x022c022d};
const u32 var70058d90[] = {0x023a023b};
const u32 var70058d94[] = {0x023c023d};
const u32 var70058d98[] = {0x023e023f};
const u32 var70058d9c[] = {0x00000001};
const u32 var70058da0[] = {0x00020003};
const u32 var70058da4[] = {0x00060007};
const u32 var70058da8[] = {0x00080009};
const u32 var70058dac[] = {0x000c000d};
const u32 var70058db0[] = {0x000e000f};
const u32 var70058db4[] = {0x00040005};
const u32 var70058db8[] = {0x00120013};
const u32 var70058dbc[] = {0x000a000b};
const u32 var70058dc0[] = {0x00180019};
const u32 var70058dc4[] = {0x00100011};
const u32 var70058dc8[] = {0x001e001f};
const u32 var70058dcc[] = {0x00140015};
const u32 var70058dd0[] = {0x00160017};
const u32 var70058dd4[] = {0x001a001b};
const u32 var70058dd8[] = {0x001c001d};
const u32 var70058ddc[] = {0x00200021};
const u32 var70058de0[] = {0x00220023};
const u32 var70058de4[] = {0x00240025};
const u32 var70058de8[] = {0x00260027};
const u32 var70058dec[] = {0x002a002b};
const u32 var70058df0[] = {0x002c002d};
const u32 var70058df4[] = {0x00300031};
const u32 var70058df8[] = {0x00320033};
const u32 var70058dfc[] = {0x00280029};
const u32 var70058e00[] = {0x00360037};
const u32 var70058e04[] = {0x00380039};
const u32 var70058e08[] = {0x002e002f};
const u32 var70058e0c[] = {0x003c003d};
const u32 var70058e10[] = {0x003e003f};
const u32 var70058e14[] = {0x00340035};
const u32 var70058e18[] = {0x00420043};
const u32 var70058e1c[] = {0x00440045};
const u32 var70058e20[] = {0x003a003b};
const u32 var70058e24[] = {0x00480049};
const u32 var70058e28[] = {0x004a004b};
const u32 var70058e2c[] = {0x00400041};
const u32 var70058e30[] = {0x004e004f};
const u32 var70058e34[] = {0x00500051};
const u32 var70058e38[] = {0x00460047};
const u32 var70058e3c[] = {0x00540055};
const u32 var70058e40[] = {0x00560057};
const u32 var70058e44[] = {0x004c004d};
const u32 var70058e48[] = {0x005a005b};
const u32 var70058e4c[] = {0x005c005d};
const u32 var70058e50[] = {0x005e005f};
const u32 var70058e54[] = {0x006c006d};
const u32 var70058e58[] = {0x00520053};
const u32 var70058e5c[] = {0x00600061};
const u32 var70058e60[] = {0x00620063};
const u32 var70058e64[] = {0x00640065};
const u32 var70058e68[] = {0x00720073};
const u32 var70058e6c[] = {0x00580059};
const u32 var70058e70[] = {0x00660067};
const u32 var70058e74[] = {0x00680069};
const u32 var70058e78[] = {0x006a006b};
const u32 var70058e7c[] = {0x00780079};
const u32 var70058e80[] = {0x006e006f};
const u32 var70058e84[] = {0x00700071};
const u32 var70058e88[] = {0x007e007f};
const u32 var70058e8c[] = {0x00800081};
const u32 var70058e90[] = {0x00820083};
const u32 var70058e94[] = {0x00900091};
const u32 var70058e98[] = {0x00740075};
const u32 var70058e9c[] = {0x00760077};
const u32 var70058ea0[] = {0x00840085};
const u32 var70058ea4[] = {0x00860087};
const u32 var70058ea8[] = {0x00880089};
const u32 var70058eac[] = {0x00960097};
const u32 var70058eb0[] = {0x007a007b};
const u32 var70058eb4[] = {0x007c007d};
const u32 var70058eb8[] = {0x008a008b};
const u32 var70058ebc[] = {0x008c008d};
const u32 var70058ec0[] = {0x008e008f};
const u32 var70058ec4[] = {0x009c009d};
const u32 var70058ec8[] = {0x00920093};
const u32 var70058ecc[] = {0x00940095};
const u32 var70058ed0[] = {0x00a200a3};
const u32 var70058ed4[] = {0x00a400a5};
const u32 var70058ed8[] = {0x00a600a7};
const u32 var70058edc[] = {0x00b400b5};
const u32 var70058ee0[] = {0x00b600b7};
const u32 var70058ee4[] = {0x00980099};
const u32 var70058ee8[] = {0x009a009b};
const u32 var70058eec[] = {0x00a800a9};
const u32 var70058ef0[] = {0x00aa00ab};
const u32 var70058ef4[] = {0x00ac00ad};
const u32 var70058ef8[] = {0x00ba00bb};
const u32 var70058efc[] = {0x00bc00bd};
const u32 var70058f00[] = {0x009e009f};
const u32 var70058f04[] = {0x00a000a1};
const u32 var70058f08[] = {0x00ae00af};
const u32 var70058f0c[] = {0x00b000b1};
const u32 var70058f10[] = {0x00b200b3};
const u32 var70058f14[] = {0x00c000c1};
const u32 var70058f18[] = {0x00c200c3};
const u32 var70058f1c[] = {0x00b800b9};
const u32 var70058f20[] = {0x00c600c7};
const u32 var70058f24[] = {0x00c800c9};
const u32 var70058f28[] = {0x00ca00cb};
const u32 var70058f2c[] = {0x00d800d9};
const u32 var70058f30[] = {0x00da00db};
const u32 var70058f34[] = {0x00dc00dd};
const u32 var70058f38[] = {0x00ea00eb};
const u32 var70058f3c[] = {0x00be00bf};
const u32 var70058f40[] = {0x00cc00cd};
const u32 var70058f44[] = {0x00ce00cf};
const u32 var70058f48[] = {0x00d000d1};
const u32 var70058f4c[] = {0x00de00df};
const u32 var70058f50[] = {0x00e000e1};
const u32 var70058f54[] = {0x00e200e3};
const u32 var70058f58[] = {0x00f000f1};
const u32 var70058f5c[] = {0x00c400c5};
const u32 var70058f60[] = {0x00d200d3};
const u32 var70058f64[] = {0x00d400d5};
const u32 var70058f68[] = {0x00d600d7};
const u32 var70058f6c[] = {0x00e400e5};
const u32 var70058f70[] = {0x00e600e7};
const u32 var70058f74[] = {0x00e800e9};
const u32 var70058f78[] = {0x00f600f7};
const u32 var70058f7c[] = {0x00ec00ed};
const u32 var70058f80[] = {0x00ee00ef};
const u32 var70058f84[] = {0x00fc00fd};
const u32 var70058f88[] = {0x00fe00ff};
const u32 var70058f8c[] = {0x01000101};
const u32 var70058f90[] = {0x010e010f};
const u32 var70058f94[] = {0x01100111};
const u32 var70058f98[] = {0x01120113};
const u32 var70058f9c[] = {0x01200121};
const u32 var70058fa0[] = {0x01220123};
const u32 var70058fa4[] = {0x00f200f3};
const u32 var70058fa8[] = {0x00f400f5};
const u32 var70058fac[] = {0x01020103};
const u32 var70058fb0[] = {0x01040105};
const u32 var70058fb4[] = {0x01060107};
const u32 var70058fb8[] = {0x01140115};
const u32 var70058fbc[] = {0x01160117};
const u32 var70058fc0[] = {0x01180119};
const u32 var70058fc4[] = {0x01260127};
const u32 var70058fc8[] = {0x01280129};
const u32 var70058fcc[] = {0x00f800f9};
const u32 var70058fd0[] = {0x00fa00fb};
const u32 var70058fd4[] = {0x01080109};
const u32 var70058fd8[] = {0x010a010b};
const u32 var70058fdc[] = {0x010c010d};
const u32 var70058fe0[] = {0x011a011b};
const u32 var70058fe4[] = {0x011c011d};
const u32 var70058fe8[] = {0x011e011f};
const u32 var70058fec[] = {0x012c012d};
const u32 var70058ff0[] = {0x012e012f};
const u32 var70058ff4[] = {0x01240125};
const u32 var70058ff8[] = {0x01320133};
const u32 var70058ffc[] = {0x01340135};
const u32 var70059000[] = {0x01360137};
const u32 var70059004[] = {0x01440145};
const u32 var70059008[] = {0x01460147};
const u32 var7005900c[] = {0x01480149};
const u32 var70059010[] = {0x01560157};
const u32 var70059014[] = {0x01580159};
const u32 var70059018[] = {0x015a015b};
const u32 var7005901c[] = {0x01680169};
const u32 var70059020[] = {0x016a016b};
const u32 var70059024[] = {0x016c016d};
const u32 var70059028[] = {0x012a012b};
const u32 var7005902c[] = {0x01380139};
const u32 var70059030[] = {0x013a013b};
const u32 var70059034[] = {0x013c013d};
const u32 var70059038[] = {0x014a014b};
const u32 var7005903c[] = {0x014c014d};
const u32 var70059040[] = {0x014e014f};
const u32 var70059044[] = {0x015c015d};
const u32 var70059048[] = {0x015e015f};
const u32 var7005904c[] = {0x01600161};
const u32 var70059050[] = {0x016e016f};
const u32 var70059054[] = {0x01700171};
const u32 var70059058[] = {0x01720173};
const u32 var7005905c[] = {0x01300131};
const u32 var70059060[] = {0x013e013f};
const u32 var70059064[] = {0x01400141};
const u32 var70059068[] = {0x01420143};
const u32 var7005906c[] = {0x01500151};
const u32 var70059070[] = {0x01520153};
const u32 var70059074[] = {0x01540155};
const u32 var70059078[] = {0x01620163};
const u32 var7005907c[] = {0x01640165};
const u32 var70059080[] = {0x01660167};
const u32 var70059084[] = {0x01740175};
const u32 var70059088[] = {0x01760177};
const u32 var7005908c[] = {0x01780179};
const u32 var70059090[] = {0x017a017b};
const u32 var70059094[] = {0x017c017d};
const u32 var70059098[] = {0x017e017f};
const u32 var7005909c[] = {0x018c018d};
const u32 var700590a0[] = {0x018e018f};
const u32 var700590a4[] = {0x01900191};
const u32 var700590a8[] = {0x019e019f};
const u32 var700590ac[] = {0x01a001a1};
const u32 var700590b0[] = {0x01a201a3};
const u32 var700590b4[] = {0x01b001b1};
const u32 var700590b8[] = {0x01b201b3};
const u32 var700590bc[] = {0x01b401b5};
const u32 var700590c0[] = {0x01c201c3};
const u32 var700590c4[] = {0x01c401c5};
const u32 var700590c8[] = {0x01c601c7};
const u32 var700590cc[] = {0x01d401d5};
const u32 var700590d0[] = {0x01d601d7};
const u32 var700590d4[] = {0x01d801d9};
const u32 var700590d8[] = {0x01e601e7};
const u32 var700590dc[] = {0x01e801e9};
const u32 var700590e0[] = {0x01ea01eb};
const u32 var700590e4[] = {0x01f801f9};
const u32 var700590e8[] = {0x01fa01fb};
const u32 var700590ec[] = {0x01fc01fd};
const u32 var700590f0[] = {0x020a020b};
const u32 var700590f4[] = {0x020c020d};
const u32 var700590f8[] = {0x020e020f};
const u32 var700590fc[] = {0x021c021d};
const u32 var70059100[] = {0x021e021f};
const u32 var70059104[] = {0x02200221};
const u32 var70059108[] = {0x022e022f};
const u32 var7005910c[] = {0x02300231};
const u32 var70059110[] = {0x02320233};
const u32 var70059114[] = {0x01800181};
const u32 var70059118[] = {0x01820183};
const u32 var7005911c[] = {0x01840185};
const u32 var70059120[] = {0x01920193};
const u32 var70059124[] = {0x01940195};
const u32 var70059128[] = {0x01960197};
const u32 var7005912c[] = {0x01a401a5};
const u32 var70059130[] = {0x01a601a7};
const u32 var70059134[] = {0x01a801a9};
const u32 var70059138[] = {0x01b601b7};
const u32 var7005913c[] = {0x01b801b9};
const u32 var70059140[] = {0x01ba01bb};
const u32 var70059144[] = {0x01c801c9};
const u32 var70059148[] = {0x01ca01cb};
const u32 var7005914c[] = {0x01cc01cd};
const u32 var70059150[] = {0x01da01db};
const u32 var70059154[] = {0x01dc01dd};
const u32 var70059158[] = {0x01de01df};
const u32 var7005915c[] = {0x01ec01ed};
const u32 var70059160[] = {0x01ee01ef};
const u32 var70059164[] = {0x01f001f1};
const u32 var70059168[] = {0x01fe01ff};
const u32 var7005916c[] = {0x02000201};
const u32 var70059170[] = {0x02020203};
const u32 var70059174[] = {0x02100211};
const u32 var70059178[] = {0x02120213};
const u32 var7005917c[] = {0x02140215};
const u32 var70059180[] = {0x02220223};
const u32 var70059184[] = {0x02240225};
const u32 var70059188[] = {0x02260227};
const u32 var7005918c[] = {0x02340235};
const u32 var70059190[] = {0x02360237};
const u32 var70059194[] = {0x02380239};
const u32 var70059198[] = {0x01860187};
const u32 var7005919c[] = {0x01880189};
const u32 var700591a0[] = {0x018a018b};
const u32 var700591a4[] = {0x01980199};
const u32 var700591a8[] = {0x019a019b};
const u32 var700591ac[] = {0x019c019d};
const u32 var700591b0[] = {0x01aa01ab};
const u32 var700591b4[] = {0x01ac01ad};
const u32 var700591b8[] = {0x01ae01af};
const u32 var700591bc[] = {0x01bc01bd};
const u32 var700591c0[] = {0x01be01bf};
const u32 var700591c4[] = {0x01c001c1};
const u32 var700591c8[] = {0x01ce01cf};
const u32 var700591cc[] = {0x01d001d1};
const u32 var700591d0[] = {0x01d201d3};
const u32 var700591d4[] = {0x01e001e1};
const u32 var700591d8[] = {0x01e201e3};
const u32 var700591dc[] = {0x01e401e5};
const u32 var700591e0[] = {0x01f201f3};
const u32 var700591e4[] = {0x01f401f5};
const u32 var700591e8[] = {0x01f601f7};
const u32 var700591ec[] = {0x02040205};
const u32 var700591f0[] = {0x02060207};
const u32 var700591f4[] = {0x02080209};
const u32 var700591f8[] = {0x02160217};
const u32 var700591fc[] = {0x02180219};
const u32 var70059200[] = {0x021a021b};
const u32 var70059204[] = {0x02280229};
const u32 var70059208[] = {0x022a022b};
const u32 var7005920c[] = {0x022c022d};
const u32 var70059210[] = {0x023a023b};
const u32 var70059214[] = {0x023c023d};
const u32 var70059218[] = {0x023e023f};
const u32 var7005921c[] = {0x00000001};
const u32 var70059220[] = {0x00020003};
const u32 var70059224[] = {0x00060007};
const u32 var70059228[] = {0x00080009};
const u32 var7005922c[] = {0x000c000d};
const u32 var70059230[] = {0x000e000f};
const u32 var70059234[] = {0x00040005};
const u32 var70059238[] = {0x00120013};
const u32 var7005923c[] = {0x000a000b};
const u32 var70059240[] = {0x00180019};
const u32 var70059244[] = {0x00100011};
const u32 var70059248[] = {0x001e001f};
const u32 var7005924c[] = {0x00140015};
const u32 var70059250[] = {0x00160017};
const u32 var70059254[] = {0x001a001b};
const u32 var70059258[] = {0x001c001d};
const u32 var7005925c[] = {0x00200021};
const u32 var70059260[] = {0x00220023};
const u32 var70059264[] = {0x00240025};
const u32 var70059268[] = {0x00260027};
const u32 var7005926c[] = {0x002a002b};
const u32 var70059270[] = {0x002c002d};
const u32 var70059274[] = {0x00300031};
const u32 var70059278[] = {0x00320033};
const u32 var7005927c[] = {0x00280029};
const u32 var70059280[] = {0x00360037};
const u32 var70059284[] = {0x00380039};
const u32 var70059288[] = {0x002e002f};
const u32 var7005928c[] = {0x003c003d};
const u32 var70059290[] = {0x003e003f};
const u32 var70059294[] = {0x00340035};
const u32 var70059298[] = {0x00420043};
const u32 var7005929c[] = {0x00440045};
const u32 var700592a0[] = {0x003a003b};
const u32 var700592a4[] = {0x00480049};
const u32 var700592a8[] = {0x004a004b};
const u32 var700592ac[] = {0x004c004d};
const u32 var700592b0[] = {0x00400041};
const u32 var700592b4[] = {0x004e004f};
const u32 var700592b8[] = {0x00500051};
const u32 var700592bc[] = {0x00520053};
const u32 var700592c0[] = {0x00460047};
const u32 var700592c4[] = {0x00540055};
const u32 var700592c8[] = {0x00560057};
const u32 var700592cc[] = {0x00580059};
const u32 var700592d0[] = {0x005a005b};
const u32 var700592d4[] = {0x005c005d};
const u32 var700592d8[] = {0x005e005f};
const u32 var700592dc[] = {0x006c006d};
const u32 var700592e0[] = {0x006e006f};
const u32 var700592e4[] = {0x00700071};
const u32 var700592e8[] = {0x00600061};
const u32 var700592ec[] = {0x00620063};
const u32 var700592f0[] = {0x00640065};
const u32 var700592f4[] = {0x00720073};
const u32 var700592f8[] = {0x00740075};
const u32 var700592fc[] = {0x00760077};
const u32 var70059300[] = {0x00660067};
const u32 var70059304[] = {0x00680069};
const u32 var70059308[] = {0x006a006b};
const u32 var7005930c[] = {0x00780079};
const u32 var70059310[] = {0x007a007b};
const u32 var70059314[] = {0x007c007d};
const u32 var70059318[] = {0x007e007f};
const u32 var7005931c[] = {0x00800081};
const u32 var70059320[] = {0x00820083};
const u32 var70059324[] = {0x00900091};
const u32 var70059328[] = {0x00920093};
const u32 var7005932c[] = {0x00940095};
const u32 var70059330[] = {0x00a200a3};
const u32 var70059334[] = {0x00a400a5};
const u32 var70059338[] = {0x00840085};
const u32 var7005933c[] = {0x00860087};
const u32 var70059340[] = {0x00880089};
const u32 var70059344[] = {0x00960097};
const u32 var70059348[] = {0x00980099};
const u32 var7005934c[] = {0x009a009b};
const u32 var70059350[] = {0x00a800a9};
const u32 var70059354[] = {0x00aa00ab};
const u32 var70059358[] = {0x008a008b};
const u32 var7005935c[] = {0x008c008d};
const u32 var70059360[] = {0x008e008f};
const u32 var70059364[] = {0x009c009d};
const u32 var70059368[] = {0x009e009f};
const u32 var7005936c[] = {0x00a000a1};
const u32 var70059370[] = {0x00ae00af};
const u32 var70059374[] = {0x00b000b1};
const u32 var70059378[] = {0x00a600a7};
const u32 var7005937c[] = {0x00b400b5};
const u32 var70059380[] = {0x00b600b7};
const u32 var70059384[] = {0x00b800b9};
const u32 var70059388[] = {0x00c600c7};
const u32 var7005938c[] = {0x00c800c9};
const u32 var70059390[] = {0x00ca00cb};
const u32 var70059394[] = {0x00d800d9};
const u32 var70059398[] = {0x00da00db};
const u32 var7005939c[] = {0x00dc00dd};
const u32 var700593a0[] = {0x00ac00ad};
const u32 var700593a4[] = {0x00ba00bb};
const u32 var700593a8[] = {0x00bc00bd};
const u32 var700593ac[] = {0x00be00bf};
const u32 var700593b0[] = {0x00cc00cd};
const u32 var700593b4[] = {0x00ce00cf};
const u32 var700593b8[] = {0x00d000d1};
const u32 var700593bc[] = {0x00de00df};
const u32 var700593c0[] = {0x00e000e1};
const u32 var700593c4[] = {0x00e200e3};
const u32 var700593c8[] = {0x00b200b3};
const u32 var700593cc[] = {0x00c000c1};
const u32 var700593d0[] = {0x00c200c3};
const u32 var700593d4[] = {0x00c400c5};
const u32 var700593d8[] = {0x00d200d3};
const u32 var700593dc[] = {0x00d400d5};
const u32 var700593e0[] = {0x00d600d7};
const u32 var700593e4[] = {0x00e400e5};
const u32 var700593e8[] = {0x00e600e7};
const u32 var700593ec[] = {0x00e800e9};
const u32 var700593f0[] = {0x00ea00eb};
const u32 var700593f4[] = {0x00ec00ed};
const u32 var700593f8[] = {0x00ee00ef};
const u32 var700593fc[] = {0x00fc00fd};
const u32 var70059400[] = {0x00fe00ff};
const u32 var70059404[] = {0x01000101};
const u32 var70059408[] = {0x010e010f};
const u32 var7005940c[] = {0x01100111};
const u32 var70059410[] = {0x01120113};
const u32 var70059414[] = {0x01200121};
const u32 var70059418[] = {0x01220123};
const u32 var7005941c[] = {0x01240125};
const u32 var70059420[] = {0x01320133};
const u32 var70059424[] = {0x00f000f1};
const u32 var70059428[] = {0x00f200f3};
const u32 var7005942c[] = {0x00f400f5};
const u32 var70059430[] = {0x01020103};
const u32 var70059434[] = {0x01040105};
const u32 var70059438[] = {0x01060107};
const u32 var7005943c[] = {0x01140115};
const u32 var70059440[] = {0x01160117};
const u32 var70059444[] = {0x01180119};
const u32 var70059448[] = {0x01260127};
const u32 var7005944c[] = {0x01280129};
const u32 var70059450[] = {0x012a012b};
const u32 var70059454[] = {0x01380139};
const u32 var70059458[] = {0x00f600f7};
const u32 var7005945c[] = {0x00f800f9};
const u32 var70059460[] = {0x00fa00fb};
const u32 var70059464[] = {0x01080109};
const u32 var70059468[] = {0x010a010b};
const u32 var7005946c[] = {0x010c010d};
const u32 var70059470[] = {0x011a011b};
const u32 var70059474[] = {0x011c011d};
const u32 var70059478[] = {0x011e011f};
const u32 var7005947c[] = {0x012c012d};
const u32 var70059480[] = {0x012e012f};
const u32 var70059484[] = {0x01300131};
const u32 var70059488[] = {0x013e013f};
const u32 var7005948c[] = {0x01340135};
const u32 var70059490[] = {0x01360137};
const u32 var70059494[] = {0x01440145};
const u32 var70059498[] = {0x01460147};
const u32 var7005949c[] = {0x01480149};
const u32 var700594a0[] = {0x01560157};
const u32 var700594a4[] = {0x01580159};
const u32 var700594a8[] = {0x015a015b};
const u32 var700594ac[] = {0x01680169};
const u32 var700594b0[] = {0x016a016b};
const u32 var700594b4[] = {0x016c016d};
const u32 var700594b8[] = {0x017a017b};
const u32 var700594bc[] = {0x017c017d};
const u32 var700594c0[] = {0x017e017f};
const u32 var700594c4[] = {0x018c018d};
const u32 var700594c8[] = {0x018e018f};
const u32 var700594cc[] = {0x01900191};
const u32 var700594d0[] = {0x013a013b};
const u32 var700594d4[] = {0x013c013d};
const u32 var700594d8[] = {0x014a014b};
const u32 var700594dc[] = {0x014c014d};
const u32 var700594e0[] = {0x014e014f};
const u32 var700594e4[] = {0x015c015d};
const u32 var700594e8[] = {0x015e015f};
const u32 var700594ec[] = {0x01600161};
const u32 var700594f0[] = {0x016e016f};
const u32 var700594f4[] = {0x01700171};
const u32 var700594f8[] = {0x01720173};
const u32 var700594fc[] = {0x01800181};
const u32 var70059500[] = {0x01820183};
const u32 var70059504[] = {0x01840185};
const u32 var70059508[] = {0x01920193};
const u32 var7005950c[] = {0x01940195};
const u32 var70059510[] = {0x01960197};
const u32 var70059514[] = {0x01400141};
const u32 var70059518[] = {0x01420143};
const u32 var7005951c[] = {0x01500151};
const u32 var70059520[] = {0x01520153};
const u32 var70059524[] = {0x01540155};
const u32 var70059528[] = {0x01620163};
const u32 var7005952c[] = {0x01640165};
const u32 var70059530[] = {0x01660167};
const u32 var70059534[] = {0x01740175};
const u32 var70059538[] = {0x01760177};
const u32 var7005953c[] = {0x01780179};
const u32 var70059540[] = {0x01860187};
const u32 var70059544[] = {0x01880189};
const u32 var70059548[] = {0x018a018b};
const u32 var7005954c[] = {0x01980199};
const u32 var70059550[] = {0x019a019b};
const u32 var70059554[] = {0x019c019d};
const u32 var70059558[] = {0x019e019f};
const u32 var7005955c[] = {0x01a001a1};
const u32 var70059560[] = {0x01a201a3};
const u32 var70059564[] = {0x01b001b1};
const u32 var70059568[] = {0x01b201b3};
const u32 var7005956c[] = {0x01b401b5};
const u32 var70059570[] = {0x01c201c3};
const u32 var70059574[] = {0x01c401c5};
const u32 var70059578[] = {0x01c601c7};
const u32 var7005957c[] = {0x01d401d5};
const u32 var70059580[] = {0x01d601d7};
const u32 var70059584[] = {0x01d801d9};
const u32 var70059588[] = {0x01e601e7};
const u32 var7005958c[] = {0x01e801e9};
const u32 var70059590[] = {0x01ea01eb};
const u32 var70059594[] = {0x01f801f9};
const u32 var70059598[] = {0x01fa01fb};
const u32 var7005959c[] = {0x01fc01fd};
const u32 var700595a0[] = {0x020a020b};
const u32 var700595a4[] = {0x020c020d};
const u32 var700595a8[] = {0x020e020f};
const u32 var700595ac[] = {0x01a401a5};
const u32 var700595b0[] = {0x01a601a7};
const u32 var700595b4[] = {0x01a801a9};
const u32 var700595b8[] = {0x01b601b7};
const u32 var700595bc[] = {0x01b801b9};
const u32 var700595c0[] = {0x01ba01bb};
const u32 var700595c4[] = {0x01c801c9};
const u32 var700595c8[] = {0x01ca01cb};
const u32 var700595cc[] = {0x01cc01cd};
const u32 var700595d0[] = {0x01da01db};
const u32 var700595d4[] = {0x01dc01dd};
const u32 var700595d8[] = {0x01de01df};
const u32 var700595dc[] = {0x01ec01ed};
const u32 var700595e0[] = {0x01ee01ef};
const u32 var700595e4[] = {0x01f001f1};
const u32 var700595e8[] = {0x01fe01ff};
const u32 var700595ec[] = {0x02000201};
const u32 var700595f0[] = {0x02020203};
const u32 var700595f4[] = {0x02100211};
const u32 var700595f8[] = {0x02120213};
const u32 var700595fc[] = {0x02140215};
const u32 var70059600[] = {0x01aa01ab};
const u32 var70059604[] = {0x01ac01ad};
const u32 var70059608[] = {0x01ae01af};
const u32 var7005960c[] = {0x01bc01bd};
const u32 var70059610[] = {0x01be01bf};
const u32 var70059614[] = {0x01c001c1};
const u32 var70059618[] = {0x01ce01cf};
const u32 var7005961c[] = {0x01d001d1};
const u32 var70059620[] = {0x01d201d3};
const u32 var70059624[] = {0x01e001e1};
const u32 var70059628[] = {0x01e201e3};
const u32 var7005962c[] = {0x01e401e5};
const u32 var70059630[] = {0x01f201f3};
const u32 var70059634[] = {0x01f401f5};
const u32 var70059638[] = {0x01f601f7};
const u32 var7005963c[] = {0x02040205};
const u32 var70059640[] = {0x02060207};
const u32 var70059644[] = {0x02080209};
const u32 var70059648[] = {0x02160217};
const u32 var7005964c[] = {0x02180219};
const u32 var70059650[] = {0x021a021b};
const u32 var70059654[] = {0x021c021d};
const u32 var70059658[] = {0x021e021f};
const u32 var7005965c[] = {0x02200221};
const u32 var70059660[] = {0x022e022f};
const u32 var70059664[] = {0x02300231};
const u32 var70059668[] = {0x02320233};
const u32 var7005966c[] = {0x02220223};
const u32 var70059670[] = {0x02240225};
const u32 var70059674[] = {0x02260227};
const u32 var70059678[] = {0x02340235};
const u32 var7005967c[] = {0x02360237};
const u32 var70059680[] = {0x02380239};
const u32 var70059684[] = {0x02280229};
const u32 var70059688[] = {0x022a022b};
const u32 var7005968c[] = {0x022c022d};
const u32 var70059690[] = {0x023a023b};
const u32 var70059694[] = {0x023c023d};
const u32 var70059698[] = {0x023e023f};
const u32 var7005969c[] = {0xbf03b5fe};
const u32 var700596a0[] = {0xbef186da};
const u32 var700596a4[] = {0xbea07302};
const u32 var700596a8[] = {0xbe3a4774};
const u32 var700596ac[] = {0xbdc1b01d};
const u32 var700596b0[] = {0xbd27cb87};
const u32 var700596b4[] = {0xbc68a11d};
const u32 var700596b8[] = {0xbb727b46};
const u32 var700596bc[] = {0x3f5b84a8};
const u32 var700596c0[] = {0x3f61b9d8};
const u32 var700596c4[] = {0x3f731add};
const u32 var700596c8[] = {0x3f7bba81};
const u32 var700596cc[] = {0x3f7eda41};
const u32 var700596d0[] = {0x3f7fc8fd};
const u32 var700596d4[] = {0x3f7ff965};
const u32 var700596d8[] = {0x3f7fff8d};
const u32 var700596dc[] = {0x00000000};
const u32 var700596e0[] = {0x00001f40};
const u32 var700596e4[] = {0x00003e80};
const u32 var700596e8[] = {0x00005dc0};
const u32 var700596ec[] = {0x00007d00};
const u32 var700596f0[] = {0x00009c40};
const u32 var700596f4[] = {0x0000bb80};
const u32 var700596f8[] = {0x0000dac0};
const u32 var700596fc[] = {0x0000fa00};
const u32 var70059700[] = {0x00013880};
const u32 var70059704[] = {0x00017700};
const u32 var70059708[] = {0x0001b580};
const u32 var7005970c[] = {0x0001f400};
const u32 var70059710[] = {0x00023280};
const u32 var70059714[] = {0x00027100};
const u32 var70059718[] = {0x00000000};
const u32 var7005971c[] = {0x00007d00};
const u32 var70059720[] = {0x00009c40};
const u32 var70059724[] = {0x0000bb80};
const u32 var70059728[] = {0x0000dac0};
const u32 var7005972c[] = {0x0000fa00};
const u32 var70059730[] = {0x00013880};
const u32 var70059734[] = {0x00017700};
const u32 var70059738[] = {0x0001b580};
const u32 var7005973c[] = {0x0001f400};
const u32 var70059740[] = {0x00027100};
const u32 var70059744[] = {0x0002ee00};
const u32 var70059748[] = {0x00036b00};
const u32 var7005974c[] = {0x0003e800};
const u32 var70059750[] = {0x0004e200};
const u32 var70059754[] = {0x00005622};
const u32 var70059758[] = {0x00005dc0};
const u32 var7005975c[] = {0x00003e80};
const u32 var70059760[] = {0x00005622};
const u32 var70059764[] = {0x0000ac44};
const u32 var70059768[] = {0x0000bb80};
const u32 var7005976c[] = {0x00007d00};
const u32 var70059770[] = {0x0000ac44};
const u32 var70059774[] = {0xbd03ba34};
const u32 var70059778[] = {0x3dd41398};
const u32 var7005977c[] = {0xbe3aec8d};
const u32 var70059780[] = {0x3e8890b4};
const u32 var70059784[] = {0xbeb50508};
const u32 var70059788[] = {0x3ee17918};
const u32 var7005978c[] = {0xbf0649c3};
const u32 var70059790[] = {0x3f1a8273};
const u32 var70059794[] = {0xbf2cc954};
const u32 var70059798[] = {0x3f3c902e};
const u32 var7005979c[] = {0xbf495c64};
const u32 var700597a0[] = {0x3f52ca58};
const u32 var700597a4[] = {0xbf5890a3};
const u32 var700597a8[] = {0x3f5a8284};
const u32 var700597ac[] = {0xbf5890a3};
const u32 var700597b0[] = {0x3f52ca47};
const u32 var700597b4[] = {0xbf495c64};
const u32 var700597b8[] = {0x3f3c902e};
const u32 var700597bc[] = {0xbf2cc954};
const u32 var700597c0[] = {0x3f1a8273};
const u32 var700597c4[] = {0xbf0649d4};
const u32 var700597c8[] = {0x3ee1793a};
const u32 var700597cc[] = {0xbeb504e6};
const u32 var700597d0[] = {0x3e8890b4};
const u32 var700597d4[] = {0xbe3aecd0};
const u32 var700597d8[] = {0x3dd41398};
const u32 var700597dc[] = {0xbd03ba34};
const u32 var700597e0[] = {0xbcf168f9};
const u32 var700597e4[] = {0x3da2bb66};
const u32 var700597e8[] = {0xbdee2b06};
const u32 var700597ec[] = {0x3e0e2ef5};
const u32 var700597f0[] = {0xbe15f5f1};
const u32 var700597f4[] = {0x3e0e2ef5};
const u32 var700597f8[] = {0xbdee2b06};
const u32 var700597fc[] = {0x3da2bb66};
const u32 var70059800[] = {0xbcf168f9};
const u32 var70059804[] = {0xbd03ba34};
const u32 var70059808[] = {0x3dd41398};
const u32 var7005980c[] = {0xbe3aec8d};
const u32 var70059810[] = {0x3e8890b4};
const u32 var70059814[] = {0xbeb50508};
const u32 var70059818[] = {0x3ee17918};
const u32 var7005981c[] = {0xbf0649c3};
const u32 var70059820[] = {0x3f1a8273};
const u32 var70059824[] = {0xbf2cc954};
const u32 var70059828[] = {0x3f3c902e};
const u32 var7005982c[] = {0xbf495c64};
const u32 var70059830[] = {0x3f52ca58};
const u32 var70059834[] = {0xbf5890a3};
const u32 var70059838[] = {0x3f5a8284};
const u32 var7005983c[] = {0xbf5890a3};
const u32 var70059840[] = {0x3f52ca47};
const u32 var70059844[] = {0xbf495c64};
const u32 var70059848[] = {0x3f3c902e};
const u32 var7005984c[] = {0xbf2cf377};
const u32 var70059850[] = {0x3f1bd7c3};
const u32 var70059854[] = {0xbf098c7e};
const u32 var70059858[] = {0x3eec6a5d};
const u32 var7005985c[] = {0xbec3ef07};
const u32 var70059860[] = {0x3e99f623};
const u32 var70059864[] = {0xbe5bbcf5};
const u32 var70059868[] = {0x3df6f7e4};
const u32 var7005986c[] = {0xbd0dbf05};
const u32 var70059870[] = {0xbcd987c6};
const u32 var70059874[] = {0x3d4c985f};
const u32 var70059878[] = {0xbce76ea4};
const u32 var7005987c[] = {0x00000000};
const u32 var70059880[] = {0x00000000};
const u32 var70059884[] = {0x00000000};
const u32 var70059888[] = {0x00000000};
const u32 var7005988c[] = {0x00000000};
const u32 var70059890[] = {0x00000000};
const u32 var70059894[] = {0xbdd41398};
const u32 var70059898[] = {0x3eb50508};
const u32 var7005989c[] = {0xbf1a8273};
const u32 var700598a0[] = {0x3f495c64};
const u32 var700598a4[] = {0xbf5a8284};
const u32 var700598a8[] = {0x3f495c64};
const u32 var700598ac[] = {0xbf1a8273};
const u32 var700598b0[] = {0x3eb504e6};
const u32 var700598b4[] = {0xbdd41398};
const u32 var700598b8[] = {0xbda2bb66};
const u32 var700598bc[] = {0x3e15f5f1};
const u32 var700598c0[] = {0xbda2bb66};
const u32 var700598c4[] = {0x00000000};
const u32 var700598c8[] = {0x00000000};
const u32 var700598cc[] = {0x00000000};
const u32 var700598d0[] = {0x00000000};
const u32 var700598d4[] = {0x00000000};
const u32 var700598d8[] = {0x00000000};
const u32 var700598dc[] = {0x00000000};
const u32 var700598e0[] = {0x00000000};
const u32 var700598e4[] = {0x00000000};
const u32 var700598e8[] = {0x00000000};
const u32 var700598ec[] = {0x00000000};
const u32 var700598f0[] = {0x00000000};
const u32 var700598f4[] = {0x00000000};
const u32 var700598f8[] = {0x00000000};
const u32 var700598fc[] = {0x00000000};
const u32 var70059900[] = {0x00000000};
const u32 var70059904[] = {0x00000000};
const u32 var70059908[] = {0x00000000};
const u32 var7005990c[] = {0x00000000};
const u32 var70059910[] = {0x00000000};
const u32 var70059914[] = {0x00000000};
const u32 var70059918[] = {0x00000000};
const u32 var7005991c[] = {0x00000000};
const u32 var70059920[] = {0x00000000};
const u32 var70059924[] = {0x00000000};
const u32 var70059928[] = {0x00000000};
const u32 var7005992c[] = {0x00000000};
const u32 var70059930[] = {0x00000000};
const u32 var70059934[] = {0x00000000};
const u32 var70059938[] = {0x00000000};
const u32 var7005993c[] = {0xbe027d89};
const u32 var70059940[] = {0x3ec24207};
const u32 var70059944[] = {0xbf1bb1d1};
const u32 var70059948[] = {0x3f4ae7b4};
const u32 var7005994c[] = {0xbf6a7d67};
const u32 var70059950[] = {0x3f77cb2e};
const u32 var70059954[] = {0xbf7426cc};
const u32 var70059958[] = {0x3f6c8366};
const u32 var7005995c[] = {0xbf631327};
const u32 var70059960[] = {0x3f57e879};
const u32 var70059964[] = {0xbf4b192f};
const u32 var70059968[] = {0x3f3cbe2f};
const u32 var7005996c[] = {0xbf2cc954};
const u32 var70059970[] = {0x3f1a8273};
const u32 var70059974[] = {0xbf0649d4};
const u32 var70059978[] = {0x3ee1793a};
const u32 var7005997c[] = {0xbeb504e6};
const u32 var70059980[] = {0x3e8890b4};
const u32 var70059984[] = {0xbe3aecd0};
const u32 var70059988[] = {0x3dd41398};
const u32 var7005998c[] = {0xbd03ba34};
const u32 var70059990[] = {0xbcf168f9};
const u32 var70059994[] = {0x3da2bb66};
const u32 var70059998[] = {0xbdee2b06};
const u32 var7005999c[] = {0x3e0e2ef5};
const u32 var700599a0[] = {0xbe15f5f1};
const u32 var700599a4[] = {0x3e0e2ef5};
const u32 var700599a8[] = {0xbdee2b06};
const u32 var700599ac[] = {0x3da2bb66};
const u32 var700599b0[] = {0xbcf168f9};
const u32 var700599b4[] = {0xbe327e95};
const u32 var700599b8[] = {0xbf0483ed};
const u32 var700599bc[] = {0xbf586174};
const u32 var700599c0[] = {0xbf92d5e9};
const u32 var700599c4[] = {0xbfb504f7};
const u32 var700599c8[] = {0xbfd1b3f2};
const u32 var700599cc[] = {0xbfe803cd};
const u32 var700599d0[] = {0xbff746ed};
const u32 var700599d4[] = {0xbfff069a};
const u32 var700599d8[] = {0x3e327e95};
const u32 var700599dc[] = {0x3f0483ed};
const u32 var700599e0[] = {0x3f586174};
const u32 var700599e4[] = {0x3f92d5e9};
const u32 var700599e8[] = {0x3fb504f7};
const u32 var700599ec[] = {0x3fd1b3f2};
const u32 var700599f0[] = {0x3fe803cd};
const u32 var700599f4[] = {0x3ff746ed};
const u32 var700599f8[] = {0x3fff069a};
const u32 var700599fc[] = {0xbe327e95};
const u32 var70059a00[] = {0xbf0483ed};
const u32 var70059a04[] = {0xbf586174};
const u32 var70059a08[] = {0xbf92d5e9};
const u32 var70059a0c[] = {0xbfb504f7};
const u32 var70059a10[] = {0xbfd1b3f2};
const u32 var70059a14[] = {0xbfe803cd};
const u32 var70059a18[] = {0xbff746ed};
const u32 var70059a1c[] = {0xbfff069a};
const u32 var70059a20[] = {0x3e327e95};
const u32 var70059a24[] = {0x3f0483ed};
const u32 var70059a28[] = {0x3f586174};
const u32 var70059a2c[] = {0x3f92d5e9};
const u32 var70059a30[] = {0x3fb504f7};
const u32 var70059a34[] = {0x3fd1b3f2};
const u32 var70059a38[] = {0x3fe803cd};
const u32 var70059a3c[] = {0x3ff746ed};
const u32 var70059a40[] = {0x3fff069a};
const u32 var70059a44[] = {0xbf0483ed};
const u32 var70059a48[] = {0xbfb504d5};
const u32 var70059a4c[] = {0xbff746dc};
const u32 var70059a50[] = {0x3f0483ed};
const u32 var70059a54[] = {0x3fb504d5};
const u32 var70059a58[] = {0x3ff746dc};
const u32 var70059a5c[] = {0x00000000};
const u32 var70059a60[] = {0x00000000};
const u32 var70059a64[] = {0x00000000};
const u32 var70059a68[] = {0x00000000};
const u32 var70059a6c[] = {0x00000000};
const u32 var70059a70[] = {0x00000000};
const u32 var70059a74[] = {0x00000000};
const u32 var70059a78[] = {0x00000000};
const u32 var70059a7c[] = {0x00000000};
const u32 var70059a80[] = {0x00000000};
const u32 var70059a84[] = {0x00000000};
const u32 var70059a88[] = {0x00000000};
const u32 var70059a8c[] = {0xbe327e95};
const u32 var70059a90[] = {0xbf0483ed};
const u32 var70059a94[] = {0xbf586174};
const u32 var70059a98[] = {0xbf92d5e9};
const u32 var70059a9c[] = {0xbfb504f7};
const u32 var70059aa0[] = {0xbfd1b3f2};
const u32 var70059aa4[] = {0xbfe803cd};
const u32 var70059aa8[] = {0xbff746ed};
const u32 var70059aac[] = {0xbfff069a};
const u32 var70059ab0[] = {0x3e327e95};
const u32 var70059ab4[] = {0x3f0483ed};
const u32 var70059ab8[] = {0x3f586174};
const u32 var70059abc[] = {0x3f92d5e9};
const u32 var70059ac0[] = {0x3fb504f7};
const u32 var70059ac4[] = {0x3fd1b3f2};
const u32 var70059ac8[] = {0x3fe803cd};
const u32 var70059acc[] = {0x3ff746ed};
const u32 var70059ad0[] = {0x3fff069a};
const u32 var70059ad4[] = {0x80402010};
const u32 var70059ad8[] = {0x08040201};
const u32 var70059adc[] = {0x00000000};
const u32 var70059ae0[] = {0x00000000};
const u32 var70059ae4[] = {0x00000000};
const u32 var70059ae8[] = {0x00000000};
const u32 var70059aec[] = {0x00000000};
const u32 var70059af0[] = {0x00000000};
const u32 var70059af4[] = {0x00000000};
const u32 var70059af8[] = {0x00000000};
const u32 var70059afc[] = {0x00000000};
const u32 var70059b00[] = {0x00000000};
const u32 var70059b04[] = {0x00000000};
const u32 var70059b08[] = {0x00000001};
const u32 var70059b0c[] = {0x00000001};
const u32 var70059b10[] = {0x00000001};
const u32 var70059b14[] = {0x00000001};
const u32 var70059b18[] = {0x00000002};
const u32 var70059b1c[] = {0x00000002};
const u32 var70059b20[] = {0x00000003};
const u32 var70059b24[] = {0x00000003};
const u32 var70059b28[] = {0x00000003};
const u32 var70059b2c[] = {0x00000002};
const u32 var70059b30[] = {0x00000000};
const u32 var70059b34[] = {0x00000006};
const u32 var70059b38[] = {0x00000005};
const u32 var70059b3c[] = {0x00000005};
const u32 var70059b40[] = {0x00000005};
const u32 var70059b44[] = {0x00000009};
const u32 var70059b48[] = {0x00000009};
const u32 var70059b4c[] = {0x00000009};
const u32 var70059b50[] = {0x00000009};
const u32 var70059b54[] = {0x00000006};
const u32 var70059b58[] = {0x00000009};
const u32 var70059b5c[] = {0x00000009};
const u32 var70059b60[] = {0x00000009};
const u32 var70059b64[] = {0x00000006};
const u32 var70059b68[] = {0x00000005};
const u32 var70059b6c[] = {0x00000007};
const u32 var70059b70[] = {0x00000003};
const u32 var70059b74[] = {0x00000009};
const u32 var70059b78[] = {0x00000009};
const u32 var70059b7c[] = {0x0000000c};
const u32 var70059b80[] = {0x00000006};
const u32 var70059b84[] = {0x00000006};
const u32 var70059b88[] = {0x00000009};
const u32 var70059b8c[] = {0x0000000c};
const u32 var70059b90[] = {0x00000006};
const u32 var70059b94[] = {0x0000000b};
const u32 var70059b98[] = {0x0000000a};
const u32 var70059b9c[] = {0x00000000};
const u32 var70059ba0[] = {0x00000000};
const u32 var70059ba4[] = {0x00000012};
const u32 var70059ba8[] = {0x00000012};
const u32 var70059bac[] = {0x00000000};
const u32 var70059bb0[] = {0x00000000};
const u32 var70059bb4[] = {0x0000000f};
const u32 var70059bb8[] = {0x00000012};
const u32 var70059bbc[] = {0x00000000};
const u32 var70059bc0[] = {0x00000000};
const u32 var70059bc4[] = {0x00000007};
const u32 var70059bc8[] = {0x00000007};
const u32 var70059bcc[] = {0x00000007};
const u32 var70059bd0[] = {0x00000000};
const u32 var70059bd4[] = {0x0000000c};
const u32 var70059bd8[] = {0x0000000c};
const u32 var70059bdc[] = {0x0000000c};
const u32 var70059be0[] = {0x00000000};
const u32 var70059be4[] = {0x00000006};
const u32 var70059be8[] = {0x0000000f};
const u32 var70059bec[] = {0x0000000c};
const u32 var70059bf0[] = {0x00000000};
const u32 var70059bf4[] = {0x00000006};
const u32 var70059bf8[] = {0x00000006};
const u32 var70059bfc[] = {0x00000006};
const u32 var70059c00[] = {0x00000003};
const u32 var70059c04[] = {0x0000000c};
const u32 var70059c08[] = {0x00000009};
const u32 var70059c0c[] = {0x00000009};
const u32 var70059c10[] = {0x00000006};
const u32 var70059c14[] = {0x00000006};
const u32 var70059c18[] = {0x0000000c};
const u32 var70059c1c[] = {0x00000009};
const u32 var70059c20[] = {0x00000006};
const u32 var70059c24[] = {0x00000008};
const u32 var70059c28[] = {0x00000008};
const u32 var70059c2c[] = {0x00000005};
const u32 var70059c30[] = {0x00000000};
const u32 var70059c34[] = {0x0000000f};
const u32 var70059c38[] = {0x0000000c};
const u32 var70059c3c[] = {0x00000009};
const u32 var70059c40[] = {0x00000000};
const u32 var70059c44[] = {0x00000006};
const u32 var70059c48[] = {0x00000012};
const u32 var70059c4c[] = {0x00000009};
const u32 var70059c50[] = {0x00000000};
const u32 var70059c54[] = {0x3db2b8c2};
const u32 var70059c58[] = {0x3db2b8c2};
const u32 var70059c5c[] = {0x3e860a92};
const u32 var70059c60[] = {0x3e860a92};
const u32 var70059c64[] = {0x3db2b8c2};
const u32 var70059c68[] = {0x3faaaaab};
const u32 var70059c6c[] = {0x00000000};
const u32 var70059c70[] = {0x46d10600};
const u32 var70059c74[] = {0x00000000};
const u32 var70059c78[] = {0x00000000};
const u32 var70059c7c[] = {0x00000000};
const u32 var70059c80[] = {0x46d10600};
const u32 var70059c84[] = {0x45f15800};
const u32 var70059c88[] = {0x45f15800};
const u32 var70059c8c[] = {0x00000000};
const u32 var70059c90[] = {0x3ff08fb2};
const u32 var70059c94[] = {0x3fc41b7d};
const u32 var70059c98[] = {0x3eb1d0d4};
const u32 var70059c9c[] = {0xbeb1d0d4};
const u32 var70059ca0[] = {0xbff08fb2};
const u32 var70059ca4[] = {0x3fc41b7d};
const u32 var70059ca8[] = {0xbfc41b7d};
const u32 var70059cac[] = {0x3eb1d0d4};
const u32 var70059cb0[] = {0xbff08fb2};
const u32 var70059cb4[] = {0x3fddb3d7};
const u32 var70059cb8[] = {0x3ffc1c5c};
const u32 var70059cbc[] = {0x3fa48dbb};
const u32 var70059cc0[] = {0x3f2f1d44};
const u32 var70059cc4[] = {0x3fa48dbb};
const u32 var70059cc8[] = {0xbf2f1d44};
const u32 var70059ccc[] = {0x3ffc1c5c};
const u32 var70059cd0[] = {0x3f2f1d44};
const u32 var70059cd4[] = {0x3ffc1c5c};
const u32 var70059cd8[] = {0xbfa48dbb};
const u32 var70059cdc[] = {0x3fddb3d7};
const u32 var70059ce0[] = {0x3ff08fb2};
const u32 var70059ce4[] = {0x3fc41b7d};
const u32 var70059ce8[] = {0x3eb1d0d4};
const u32 var70059cec[] = {0xbeb1d0d4};
const u32 var70059cf0[] = {0xbff08fb2};
const u32 var70059cf4[] = {0x3fc41b7d};
const u32 var70059cf8[] = {0xbfc41b7d};
const u32 var70059cfc[] = {0x3eb1d0d4};
const u32 var70059d00[] = {0xbff08fb2};
const u32 var70059d04[] = {0x3fddb3d7};
const u32 var70059d08[] = {0x3ffc1c5c};
const u32 var70059d0c[] = {0x3fa48dbb};
const u32 var70059d10[] = {0x3f2f1d44};
const u32 var70059d14[] = {0x3fa48dbb};
const u32 var70059d18[] = {0xbf2f1d44};
const u32 var70059d1c[] = {0x3ffc1c5c};
const u32 var70059d20[] = {0x3f2f1d44};
const u32 var70059d24[] = {0x3ffc1c5c};
const u32 var70059d28[] = {0xbfa48dbb};
const u32 var70059d2c[] = {0x3fddb3d7};
const u32 var70059d30[] = {0x3f007d2b};
const u32 var70059d34[] = {0xbe801f38};
const u32 var70059d38[] = {0xc0b76799};
const u32 var70059d3c[] = {0x3f0483ee};
const u32 var70059d40[] = {0xbe811ac1};
const u32 var70059d44[] = {0xbff5295a};
const u32 var70059d48[] = {0x3f0d3b7d};
const u32 var70059d4c[] = {0xbe831b97};
const u32 var70059d50[] = {0xbf93d8e5};
const u32 var70059d54[] = {0x3f1c4257};
const u32 var70059d58[] = {0xbe863634};
const u32 var70059d5c[] = {0xbf54d526};
const u32 var70059d60[] = {0x3f5f2944};
const u32 var70059d64[] = {0xbe904e0d};
const u32 var70059d68[] = {0xbf0a9a83};
const u32 var70059d6c[] = {0x3f976fd9};
const u32 var70059d70[] = {0xbe97c4a9};
const u32 var70059d74[] = {0xbeee3a75};
const u32 var70059d78[] = {0x3ff746ea};
const u32 var70059d7c[] = {0xbea15729};
const u32 var70059d80[] = {0xbed24353};
const u32 var70059d84[] = {0x40b79454};
const u32 var70059d88[] = {0xbead9c9b};
const u32 var70059d8c[] = {0xbebd76c6};
const u32 var70059d90[] = {0x3f3504f3};
const u32 var70059d94[] = {0xbf0a8bd4};
const u32 var70059d98[] = {0xbfa73d75};
const u32 var70059d9c[] = {0x3f5db3d7};
const u32 var70059da0[] = {0x3f5db3d7};
const u32 var70059da4[] = {0x3ff746ea};
const u32 var70059da8[] = {0x3f3504f3};
const u32 var70059dac[] = {0x3f0483ee};
const u32 var70059db0[] = {0x3f011ac1};
const u32 var70059db4[] = {0x3f0a8bd4};
const u32 var70059db8[] = {0x3f215729};
const u32 var70059dbc[] = {0x3f524353};
const u32 var70059dc0[] = {0x3fa73d75};
const u32 var70059dc4[] = {0x4075295a};
const u32 var70059dc8[] = {0xbf4b1934};
const u32 var70059dcc[] = {0xbf1bd7ca};
const u32 var70059dd0[] = {0xbf6c835e};
const u32 var70059dd4[] = {0xbec3ef15};
const u32 var70059dd8[] = {0xbf7dcf55};
const u32 var70059ddc[] = {0xbe05a8a8};
const u32 var70059de0[] = {0x3ec3ef15};
const u32 var70059de4[] = {0x3f1bd7ca};
const u32 var70059de8[] = {0xbf4b1934};
const u32 var70059dec[] = {0xbf6c835e};
const u32 var70059df0[] = {0xbf7dcf55};
const u32 var70059df4[] = {0x3e05a8a8};
const u32 var70059df8[] = {0x00000000};
const u32 var70059dfc[] = {0x00000000};
const u32 var70059e00[] = {0x3fffffd6};
const u32 var70059e04[] = {0x0e94ee39};
const u32 var70059e08[] = {0x3ffffeb0};
const u32 var70059e0c[] = {0x00000000};
const u32 var70059e10[] = {0x3f317218};
const u32 var70059e14[] = {0x7f7fffff};
const u32 var70059e18[] = {0x3f317218};
const u32 var70059e1c[] = {0x00000000};
const u32 var70059e20[] = {0x3f317218};
const u32 var70059e24[] = {0x3f317218};
const u32 var70059e28[] = {0x00000000};
const u32 var70059e2c[] = {0x00000000};
const u32 var70059e30[] = {0x05550556};
const u32 var70059e34[] = {0x0559055a};
const u32 var70059e38[] = {0x05650566};
const u32 var70059e3c[] = {0x0569056a};
const u32 var70059e40[] = {0x05950596};
const u32 var70059e44[] = {0x0599059a};
const u32 var70059e48[] = {0x05a505a6};
const u32 var70059e4c[] = {0x05a905aa};
const u32 var70059e50[] = {0x06550656};
const u32 var70059e54[] = {0x0659065a};
const u32 var70059e58[] = {0x06650666};
const u32 var70059e5c[] = {0x0669066a};
const u32 var70059e60[] = {0x06950696};
const u32 var70059e64[] = {0x0699069a};
const u32 var70059e68[] = {0x06a506a6};
const u32 var70059e6c[] = {0x06a906aa};
const u32 var70059e70[] = {0x09550956};
const u32 var70059e74[] = {0x0959095a};
const u32 var70059e78[] = {0x09650966};
const u32 var70059e7c[] = {0x0969096a};
const u32 var70059e80[] = {0x09950996};
const u32 var70059e84[] = {0x0999099a};
const u32 var70059e88[] = {0x09a509a6};
const u32 var70059e8c[] = {0x09a909aa};
const u32 var70059e90[] = {0x0a550a56};
const u32 var70059e94[] = {0x0a590a5a};
const u32 var70059e98[] = {0x0a650a66};
const u32 var70059e9c[] = {0x0a690a6a};
const u32 var70059ea0[] = {0x0a950a96};
const u32 var70059ea4[] = {0x0a990a9a};
const u32 var70059ea8[] = {0x0aa50aa6};
const u32 var70059eac[] = {0x0aa90aaa};

#if VERSION >= VERSION_PAL_FINAL
const u32 var70059eb0[] = {0x70049a7c};
const u32 var70059eb4[] = {0x70049994};
const u32 var70059eb8[] = {0x700499c8};
const u32 var70059ebc[] = {0x70049a98};
const u32 var70059ec0[] = {0x70049a98};
const u32 var70059ec4[] = {0x700499fc};
const u32 var70059ec8[] = {0x70049a3c};
#else
const u32 var70059eb0[] = {0x7004a17c};
const u32 var70059eb4[] = {0x7004a094};
const u32 var70059eb8[] = {0x7004a0c8};
const u32 var70059ebc[] = {0x7004a198};
const u32 var70059ec0[] = {0x7004a198};
const u32 var70059ec4[] = {0x7004a0fc};
const u32 var70059ec8[] = {0x7004a13c};
#endif

const u32 var70059ecc[] = {0x00000000};

const u32 var70059ed0[] = {0x686c4c00};
const u32 var70059ed4[] = {0x202b2d23};
const u32 var70059ed8[] = {0x30000000};
const u32 var70059edc[] = {0x00000001};
const u32 var70059ee0[] = {0x00000002};
const u32 var70059ee4[] = {0x00000004};
const u32 var70059ee8[] = {0x00000008};
const u32 var70059eec[] = {0x00000010};
const u32 var70059ef0[] = {0x00000000};

#if VERSION >= VERSION_PAL_FINAL
const u32 var70059ef4[] = {0x7004e2f8};
const u32 var70059ef8[] = {0x7004e5d8};
const u32 var70059efc[] = {0x7004e2f8};
const u32 var70059f00[] = {0x7004e5d8};
const u32 var70059f04[] = {0x7004e5d8};
const u32 var70059f08[] = {0x7004e5d8};
const u32 var70059f0c[] = {0x7004e5d8};
const u32 var70059f10[] = {0x7004e5d8};
const u32 var70059f14[] = {0x7004e5d8};
const u32 var70059f18[] = {0x7004e5d8};
const u32 var70059f1c[] = {0x7004e5d8};
const u32 var70059f20[] = {0x7004e5d8};
const u32 var70059f24[] = {0x7004e5d8};
const u32 var70059f28[] = {0x7004e5d8};
const u32 var70059f2c[] = {0x7004e5d8};
const u32 var70059f30[] = {0x7004e5d8};
const u32 var70059f34[] = {0x7004e5d8};
const u32 var70059f38[] = {0x7004e5d8};
const u32 var70059f3c[] = {0x7004e5d8};
const u32 var70059f40[] = {0x7004e1a8};
const u32 var70059f44[] = {0x7004e5d8};
const u32 var70059f48[] = {0x7004e5d8};
const u32 var70059f4c[] = {0x7004e5d8};
const u32 var70059f50[] = {0x7004e5d8};
const u32 var70059f54[] = {0x7004e5d8};
const u32 var70059f58[] = {0x7004e5d8};
const u32 var70059f5c[] = {0x7004e5d8};
const u32 var70059f60[] = {0x7004e5d8};
const u32 var70059f64[] = {0x7004e5d8};
const u32 var70059f68[] = {0x7004e5d8};
const u32 var70059f6c[] = {0x7004e000};
const u32 var70059f70[] = {0x7004e038};
const u32 var70059f74[] = {0x7004e2f8};
const u32 var70059f78[] = {0x7004e2f8};
const u32 var70059f7c[] = {0x7004e2f8};
const u32 var70059f80[] = {0x7004e5d8};
const u32 var70059f84[] = {0x7004e038};
const u32 var70059f88[] = {0x7004e5d8};
const u32 var70059f8c[] = {0x7004e5d8};
const u32 var70059f90[] = {0x7004e5d8};
const u32 var70059f94[] = {0x7004e5d8};
const u32 var70059f98[] = {0x7004e45c};
const u32 var70059f9c[] = {0x7004e1a8};
const u32 var70059fa0[] = {0x7004e52c};
const u32 var70059fa4[] = {0x7004e5d8};
const u32 var70059fa8[] = {0x7004e5d8};
const u32 var70059fac[] = {0x7004e574};
const u32 var70059fb0[] = {0x7004e5d8};
const u32 var70059fb4[] = {0x7004e1a8};
const u32 var70059fb8[] = {0x7004e5d8};
const u32 var70059fbc[] = {0x7004e5d8};
const u32 var70059fc0[] = {0x7004e1a8};
#else
const u32 var70059ef4[] = {0x7004e9f8};
const u32 var70059ef8[] = {0x7004ecd8};
const u32 var70059efc[] = {0x7004e9f8};
const u32 var70059f00[] = {0x7004ecd8};
const u32 var70059f04[] = {0x7004ecd8};
const u32 var70059f08[] = {0x7004ecd8};
const u32 var70059f0c[] = {0x7004ecd8};
const u32 var70059f10[] = {0x7004ecd8};
const u32 var70059f14[] = {0x7004ecd8};
const u32 var70059f18[] = {0x7004ecd8};
const u32 var70059f1c[] = {0x7004ecd8};
const u32 var70059f20[] = {0x7004ecd8};
const u32 var70059f24[] = {0x7004ecd8};
const u32 var70059f28[] = {0x7004ecd8};
const u32 var70059f2c[] = {0x7004ecd8};
const u32 var70059f30[] = {0x7004ecd8};
const u32 var70059f34[] = {0x7004ecd8};
const u32 var70059f38[] = {0x7004ecd8};
const u32 var70059f3c[] = {0x7004ecd8};
const u32 var70059f40[] = {0x7004e8a8};
const u32 var70059f44[] = {0x7004ecd8};
const u32 var70059f48[] = {0x7004ecd8};
const u32 var70059f4c[] = {0x7004ecd8};
const u32 var70059f50[] = {0x7004ecd8};
const u32 var70059f54[] = {0x7004ecd8};
const u32 var70059f58[] = {0x7004ecd8};
const u32 var70059f5c[] = {0x7004ecd8};
const u32 var70059f60[] = {0x7004ecd8};
const u32 var70059f64[] = {0x7004ecd8};
const u32 var70059f68[] = {0x7004ecd8};
const u32 var70059f6c[] = {0x7004e700};
const u32 var70059f70[] = {0x7004e738};
const u32 var70059f74[] = {0x7004e9f8};
const u32 var70059f78[] = {0x7004e9f8};
const u32 var70059f7c[] = {0x7004e9f8};
const u32 var70059f80[] = {0x7004ecd8};
const u32 var70059f84[] = {0x7004e738};
const u32 var70059f88[] = {0x7004ecd8};
const u32 var70059f8c[] = {0x7004ecd8};
const u32 var70059f90[] = {0x7004ecd8};
const u32 var70059f94[] = {0x7004ecd8};
const u32 var70059f98[] = {0x7004eb5c};
const u32 var70059f9c[] = {0x7004e8a8};
const u32 var70059fa0[] = {0x7004ec2c};
const u32 var70059fa4[] = {0x7004ecd8};
const u32 var70059fa8[] = {0x7004ecd8};
const u32 var70059fac[] = {0x7004ec74};
const u32 var70059fb0[] = {0x7004ecd8};
const u32 var70059fb4[] = {0x7004e8a8};
const u32 var70059fb8[] = {0x7004ecd8};
const u32 var70059fbc[] = {0x7004ecd8};
const u32 var70059fc0[] = {0x7004e8a8};
#endif

const u32 var70059fc4[] = {0x00000000};
const u32 var70059fc8[] = {0x00000000};
const u32 var70059fcc[] = {0x00000000};

const u32 var70059fd0[] = {0x3c8efa35};
const u32 var70059fd4[] = {0x00000000};
const u32 var70059fd8[] = {0x00000000};
const u32 var70059fdc[] = {0x00000000};

GLOBAL_ASM(
glabel func0003e730
/*    3e730:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3e734:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e738:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3e73c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3e740:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3e744:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3e748:	11e0001f */ 	beqz	$t7,.L0003e7c8
/*    3e74c:	00000000 */ 	nop
/*    3e750:	0c00c541 */ 	jal	func00031504
/*    3e754:	00000000 */ 	nop
/*    3e758:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3e75c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e760:	17000003 */ 	bnez	$t8,.L0003e770
/*    3e764:	00000000 */ 	nop
/*    3e768:	10000019 */ 	b	.L0003e7d0
/*    3e76c:	00000000 */ 	nop
.L0003e770:
/*    3e770:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e774:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3e778:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3e77c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3e780:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3e784:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3e788:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3e78c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3e790:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3e794:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3e798:	240e0011 */ 	addiu	$t6,$zero,0x11
/*    3e79c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3e7a0:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3e7a4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3e7a8:	af38000c */ 	sw	$t8,0xc($t9)
/*    3e7ac:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3e7b0:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3e7b4:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3e7b8:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3e7bc:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3e7c0:	0c00fc79 */ 	jal	func0003f1e4
/*    3e7c4:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003e7c8:
/*    3e7c8:	10000001 */ 	b	.L0003e7d0
/*    3e7cc:	00000000 */ 	nop
.L0003e7d0:
/*    3e7d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e7d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3e7d8:	03e00008 */ 	jr	$ra
/*    3e7dc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003e7e0
/*    3e7e0:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    3e7e4:	240effff */ 	addiu	$t6,$zero,-1
/*    3e7e8:	afae0008 */ 	sw	$t6,0x8($sp)
/*    3e7ec:	8c8f0010 */ 	lw	$t7,0x10($a0)
/*    3e7f0:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    3e7f4:	8c980004 */ 	lw	$t8,0x4($a0)
/*    3e7f8:	17000003 */ 	bnez	$t8,.L0003e808
/*    3e7fc:	00000000 */ 	nop
/*    3e800:	1000002c */ 	b	.L0003e8b4
/*    3e804:	00001025 */ 	or	$v0,$zero,$zero
.L0003e808:
/*    3e808:	afa0000c */ 	sw	$zero,0xc($sp)
.L0003e80c:
/*    3e80c:	8c990004 */ 	lw	$t9,0x4($a0)
/*    3e810:	8fa8000c */ 	lw	$t0,0xc($sp)
/*    3e814:	01194806 */ 	srlv	$t1,$t9,$t0
/*    3e818:	312a0001 */ 	andi	$t2,$t1,0x1
/*    3e81c:	11400019 */ 	beqz	$t2,.L0003e884
/*    3e820:	00000000 */ 	nop
/*    3e824:	8c8b0014 */ 	lw	$t3,0x14($a0)
/*    3e828:	11600009 */ 	beqz	$t3,.L0003e850
/*    3e82c:	00000000 */ 	nop
/*    3e830:	8fac000c */ 	lw	$t4,0xc($sp)
/*    3e834:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e838:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3e83c:	008d7021 */ 	addu	$t6,$a0,$t5
/*    3e840:	8dcf00b8 */ 	lw	$t7,0xb8($t6)
/*    3e844:	008d4021 */ 	addu	$t0,$a0,$t5
/*    3e848:	01f8c823 */ 	subu	$t9,$t7,$t8
/*    3e84c:	ad1900b8 */ 	sw	$t9,0xb8($t0)
.L0003e850:
/*    3e850:	8fa9000c */ 	lw	$t1,0xc($sp)
/*    3e854:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    3e858:	00095080 */ 	sll	$t2,$t1,0x2
/*    3e85c:	008a5821 */ 	addu	$t3,$a0,$t2
/*    3e860:	8d6c00b8 */ 	lw	$t4,0xb8($t3)
/*    3e864:	018e082b */ 	sltu	$at,$t4,$t6
/*    3e868:	10200006 */ 	beqz	$at,.L0003e884
/*    3e86c:	00000000 */ 	nop
/*    3e870:	8faf000c */ 	lw	$t7,0xc($sp)
/*    3e874:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3e878:	00986821 */ 	addu	$t5,$a0,$t8
/*    3e87c:	8db900b8 */ 	lw	$t9,0xb8($t5)
/*    3e880:	afb90008 */ 	sw	$t9,0x8($sp)
.L0003e884:
/*    3e884:	8fa8000c */ 	lw	$t0,0xc($sp)
/*    3e888:	25090001 */ 	addiu	$t1,$t0,0x1
/*    3e88c:	2d210010 */ 	sltiu	$at,$t1,0x10
/*    3e890:	1420ffde */ 	bnez	$at,.L0003e80c
/*    3e894:	afa9000c */ 	sw	$t1,0xc($sp)
/*    3e898:	ac800014 */ 	sw	$zero,0x14($a0)
/*    3e89c:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    3e8a0:	acaa0000 */ 	sw	$t2,0x0($a1)
/*    3e8a4:	10000003 */ 	b	.L0003e8b4
/*    3e8a8:	24020001 */ 	addiu	$v0,$zero,0x1
/*    3e8ac:	10000001 */ 	b	.L0003e8b4
/*    3e8b0:	00000000 */ 	nop
.L0003e8b4:
/*    3e8b4:	03e00008 */ 	jr	$ra
/*    3e8b8:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*    3e8bc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003e8c0
/*    3e8c0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    3e8c4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3e8c8:	afa40058 */ 	sw	$a0,0x58($sp)
/*    3e8cc:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    3e8d0:	afa60060 */ 	sw	$a2,0x60($sp)
/*    3e8d4:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    3e8d8:	afae0054 */ 	sw	$t6,0x54($sp)
/*    3e8dc:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    3e8e0:	afaf0050 */ 	sw	$t7,0x50($sp)
/*    3e8e4:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3e8e8:	afb80044 */ 	sw	$t8,0x44($sp)
/*    3e8ec:	a7a0003e */ 	sh	$zero,0x3e($sp)
/*    3e8f0:	241900b8 */ 	addiu	$t9,$zero,0xb8
/*    3e8f4:	afb90030 */ 	sw	$t9,0x30($sp)
/*    3e8f8:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*    3e8fc:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3e900:	8d09007c */ 	lw	$t1,0x7c($t0)
/*    3e904:	1120021e */ 	beqz	$t1,.L0003f180
/*    3e908:	00000000 */ 	nop
.L0003e90c:
/*    3e90c:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    3e910:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    3e914:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3e918:	8d6c007c */ 	lw	$t4,0x7c($t3)
/*    3e91c:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    3e920:	afad0044 */ 	sw	$t5,0x44($sp)
/*    3e924:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    3e928:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    3e92c:	240100b8 */ 	addiu	$at,$zero,0xb8
/*    3e930:	01cfc023 */ 	subu	$t8,$t6,$t7
/*    3e934:	271900b7 */ 	addiu	$t9,$t8,0xb7
/*    3e938:	0321001a */ 	div	$zero,$t9,$at
/*    3e93c:	00004012 */ 	mflo	$t0
/*    3e940:	00084880 */ 	sll	$t1,$t0,0x2
/*    3e944:	01284823 */ 	subu	$t1,$t1,$t0
/*    3e948:	000948c0 */ 	sll	$t1,$t1,0x3
/*    3e94c:	01284823 */ 	subu	$t1,$t1,$t0
/*    3e950:	000948c0 */ 	sll	$t1,$t1,0x3
/*    3e954:	afa90040 */ 	sw	$t1,0x40($sp)
/*    3e958:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3e95c:	15400003 */ 	bnez	$t2,.L0003e96c
/*    3e960:	00000000 */ 	nop
/*    3e964:	8fab0048 */ 	lw	$t3,0x48($sp)
/*    3e968:	afab0044 */ 	sw	$t3,0x44($sp)
.L0003e96c:
/*    3e96c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    3e970:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    3e974:	01ac082a */ 	slt	$at,$t5,$t4
/*    3e978:	10200003 */ 	beqz	$at,.L0003e988
/*    3e97c:	00000000 */ 	nop
/*    3e980:	100001ff */ 	b	.L0003f180
/*    3e984:	00000000 */ 	nop
.L0003e988:
/*    3e988:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3e98c:	8dcf007c */ 	lw	$t7,0x7c($t6)
/*    3e990:	95f80008 */ 	lhu	$t8,0x8($t7)
/*    3e994:	2f010011 */ 	sltiu	$at,$t8,0x11
/*    3e998:	102001cd */ 	beqz	$at,.L0003f0d0
/*    3e99c:	00000000 */ 	nop
/*    3e9a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3e9a4:	3c017005 */ 	lui	$at,%hi(var70054af0)
/*    3e9a8:	00380821 */ 	addu	$at,$at,$t8
/*    3e9ac:	8c384af0 */ 	lw	$t8,%lo(var70054af0)($at)
/*    3e9b0:	03000008 */ 	jr	$t8
/*    3e9b4:	00000000 */ 	nop
/*    3e9b8:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3e9bc:	8f28007c */ 	lw	$t0,0x7c($t9)
/*    3e9c0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*    3e9c4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3e9c8:	852a000a */ 	lh	$t2,0xa($t1)
/*    3e9cc:	11400004 */ 	beqz	$t2,.L0003e9e0
/*    3e9d0:	00000000 */ 	nop
/*    3e9d4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3e9d8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    3e9dc:	ad8b0048 */ 	sw	$t3,0x48($t4)
.L0003e9e0:
/*    3e9e0:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3e9e4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3e9e8:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3e9ec:	0c011582 */ 	jal	func00045608
/*    3e9f0:	8da60020 */ 	lw	$a2,0x20($t5)
/*    3e9f4:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3e9f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3e9fc:	adee0084 */ 	sw	$t6,0x84($t7)
/*    3ea00:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ea04:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3ea08:	af380078 */ 	sw	$t8,0x78($t9)
/*    3ea0c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ea10:	ad000070 */ 	sw	$zero,0x70($t0)
/*    3ea14:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3ea18:	240100b8 */ 	addiu	$at,$zero,0xb8
/*    3ea1c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ea20:	8d2a001c */ 	lw	$t2,0x1c($t1)
/*    3ea24:	254b00b7 */ 	addiu	$t3,$t2,0xb7
/*    3ea28:	0161001a */ 	div	$zero,$t3,$at
/*    3ea2c:	00006012 */ 	mflo	$t4
/*    3ea30:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3ea34:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3ea38:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    3ea3c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3ea40:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    3ea44:	adcd0074 */ 	sw	$t5,0x74($t6)
/*    3ea48:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3ea4c:	85f80010 */ 	lh	$t8,0x10($t7)
/*    3ea50:	0318c821 */ 	addu	$t9,$t8,$t8
/*    3ea54:	07210003 */ 	bgez	$t9,.L0003ea64
/*    3ea58:	00194043 */ 	sra	$t0,$t9,0x1
/*    3ea5c:	27210001 */ 	addiu	$at,$t9,0x1
/*    3ea60:	00014043 */ 	sra	$t0,$at,0x1
.L0003ea64:
/*    3ea64:	afa80028 */ 	sw	$t0,0x28($sp)
/*    3ea68:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    3ea6c:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ea70:	a549005a */ 	sh	$t1,0x5a($t2)
/*    3ea74:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ea78:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ea7c:	916c0012 */ 	lbu	$t4,0x12($t3)
/*    3ea80:	a5ac0058 */ 	sh	$t4,0x58($t5)
/*    3ea84:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3ea88:	3c088006 */ 	lui	$t0,%hi(var8005f570)
/*    3ea8c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ea90:	91cf0013 */ 	lbu	$t7,0x13($t6)
/*    3ea94:	31f8007f */ 	andi	$t8,$t7,0x7f
/*    3ea98:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3ea9c:	01194021 */ 	addu	$t0,$t0,$t9
/*    3eaa0:	8508f570 */ 	lh	$t0,%lo(var8005f570)($t0)
/*    3eaa4:	000f51c3 */ 	sra	$t2,$t7,0x7
/*    3eaa8:	3109fffe */ 	andi	$t1,$t0,0xfffe
/*    3eaac:	012a5825 */ 	or	$t3,$t1,$t2
/*    3eab0:	a58b0060 */ 	sh	$t3,0x60($t4)
/*    3eab4:	3c0d800a */ 	lui	$t5,%hi(var8009c340)
/*    3eab8:	91adc340 */ 	lbu	$t5,%lo(var8009c340)($t5)
/*    3eabc:	15a00005 */ 	bnez	$t5,.L0003ead4
/*    3eac0:	00000000 */ 	nop
/*    3eac4:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3eac8:	85d80060 */ 	lh	$t8,0x60($t6)
/*    3eacc:	3319fffe */ 	andi	$t9,$t8,0xfffe
/*    3ead0:	a5d90060 */ 	sh	$t9,0x60($t6)
.L0003ead4:
/*    3ead4:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3ead8:	3c0c8006 */ 	lui	$t4,%hi(var8005f66c+0x2)
/*    3eadc:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3eae0:	910f0013 */ 	lbu	$t7,0x13($t0)
/*    3eae4:	31e9007f */ 	andi	$t1,$t7,0x7f
/*    3eae8:	00095023 */ 	negu	$t2,$t1
/*    3eaec:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3eaf0:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3eaf4:	858cf66e */ 	lh	$t4,%lo(var8005f66c+0x2)($t4)
/*    3eaf8:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*    3eafc:	a70d0062 */ 	sh	$t5,0x62($t8)
/*    3eb00:	3c19800a */ 	lui	$t9,%hi(var8009c340+0x2)
/*    3eb04:	9339c342 */ 	lbu	$t9,%lo(var8009c340+0x2)($t9)
/*    3eb08:	13200007 */ 	beqz	$t9,.L0003eb28
/*    3eb0c:	00000000 */ 	nop
/*    3eb10:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3eb14:	85c80058 */ 	lh	$t0,0x58($t6)
/*    3eb18:	00087843 */ 	sra	$t7,$t0,0x1
/*    3eb1c:	25e90020 */ 	addiu	$t1,$t7,0x20
/*    3eb20:	10000008 */ 	b	.L0003eb44
/*    3eb24:	a5c90058 */ 	sh	$t1,0x58($t6)
.L0003eb28:
/*    3eb28:	3c0a800a */ 	lui	$t2,%hi(var8009c340+0x1)
/*    3eb2c:	914ac341 */ 	lbu	$t2,%lo(var8009c340+0x1)($t2)
/*    3eb30:	11400004 */ 	beqz	$t2,.L0003eb44
/*    3eb34:	00000000 */ 	nop
/*    3eb38:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3eb3c:	240b0040 */ 	addiu	$t3,$zero,0x40
/*    3eb40:	a58b0058 */ 	sh	$t3,0x58($t4)
.L0003eb44:
/*    3eb44:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3eb48:	8db8001c */ 	lw	$t8,0x1c($t5)
/*    3eb4c:	13000008 */ 	beqz	$t8,.L0003eb70
/*    3eb50:	00000000 */ 	nop
/*    3eb54:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eb58:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3eb5c:	a519005c */ 	sh	$t9,0x5c($t0)
/*    3eb60:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3eb64:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    3eb68:	10000018 */ 	b	.L0003ebcc
/*    3eb6c:	a52f005e */ 	sh	$t7,0x5e($t1)
.L0003eb70:
/*    3eb70:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3eb74:	3c0c8006 */ 	lui	$t4,%hi(var8005f570)
/*    3eb78:	85ca0058 */ 	lh	$t2,0x58($t6)
/*    3eb7c:	85cd005a */ 	lh	$t5,0x5a($t6)
/*    3eb80:	000a5840 */ 	sll	$t3,$t2,0x1
/*    3eb84:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3eb88:	858cf570 */ 	lh	$t4,%lo(var8005f570)($t4)
/*    3eb8c:	018d0019 */ 	multu	$t4,$t5
/*    3eb90:	0000c012 */ 	mflo	$t8
/*    3eb94:	0018cbc3 */ 	sra	$t9,$t8,0xf
/*    3eb98:	a5d9005c */ 	sh	$t9,0x5c($t6)
/*    3eb9c:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eba0:	3c0b8006 */ 	lui	$t3,%hi(var8005f66c+0x2)
/*    3eba4:	850f0058 */ 	lh	$t7,0x58($t0)
/*    3eba8:	850c005a */ 	lh	$t4,0x5a($t0)
/*    3ebac:	000f4823 */ 	negu	$t1,$t7
/*    3ebb0:	00095040 */ 	sll	$t2,$t1,0x1
/*    3ebb4:	016a5821 */ 	addu	$t3,$t3,$t2
/*    3ebb8:	856bf66e */ 	lh	$t3,%lo(var8005f66c+0x2)($t3)
/*    3ebbc:	016c0019 */ 	multu	$t3,$t4
/*    3ebc0:	00006812 */ 	mflo	$t5
/*    3ebc4:	000dc3c3 */ 	sra	$t8,$t5,0xf
/*    3ebc8:	a518005e */ 	sh	$t8,0x5e($t0)
.L0003ebcc:
/*    3ebcc:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3ebd0:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ebd4:	c724000c */ 	lwc1	$f4,0xc($t9)
/*    3ebd8:	e5c40044 */ 	swc1	$f4,0x44($t6)
/*    3ebdc:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    3ebe0:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ebe4:	91e90015 */ 	lbu	$t1,0x15($t7)
/*    3ebe8:	a5490092 */ 	sh	$t1,0x92($t2)
/*    3ebec:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ebf0:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ebf4:	c5660018 */ 	lwc1	$f6,0x18($t3)
/*    3ebf8:	4600320d */ 	trunc.w.s	$f8,$f6
/*    3ebfc:	440d4000 */ 	mfc1	$t5,$f8
/*    3ec00:	00000000 */ 	nop
/*    3ec04:	a70d0090 */ 	sh	$t5,0x90($t8)
/*    3ec08:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ec0c:	24080001 */ 	addiu	$t0,$zero,0x1
/*    3ec10:	af2800b8 */ 	sw	$t0,0xb8($t9)
/*    3ec14:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3ec18:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3ec1c:	91cf0014 */ 	lbu	$t7,0x14($t6)
/*    3ec20:	a12f008c */ 	sb	$t7,0x8c($t1)
/*    3ec24:	1000013a */ 	b	.L0003f110
/*    3ec28:	00000000 */ 	nop
/*    3ec2c:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3ec30:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3ec34:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3ec38:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3ec3c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3ec40:	0c00fcca */ 	jal	func0003f328
/*    3ec44:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3ec48:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3ec4c:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ec50:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*    3ec54:	8d6d0074 */ 	lw	$t5,0x74($t3)
/*    3ec58:	018d082a */ 	slt	$at,$t4,$t5
/*    3ec5c:	14200022 */ 	bnez	$at,.L0003ece8
/*    3ec60:	00000000 */ 	nop
/*    3ec64:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ec68:	3c0e8006 */ 	lui	$t6,%hi(var8005f570)
/*    3ec6c:	87080058 */ 	lh	$t0,0x58($t8)
/*    3ec70:	870f005a */ 	lh	$t7,0x5a($t8)
/*    3ec74:	0008c840 */ 	sll	$t9,$t0,0x1
/*    3ec78:	01d97021 */ 	addu	$t6,$t6,$t9
/*    3ec7c:	85cef570 */ 	lh	$t6,%lo(var8005f570)($t6)
/*    3ec80:	01cf0019 */ 	multu	$t6,$t7
/*    3ec84:	00004812 */ 	mflo	$t1
/*    3ec88:	000953c3 */ 	sra	$t2,$t1,0xf
/*    3ec8c:	a70a0068 */ 	sh	$t2,0x68($t8)
/*    3ec90:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ec94:	3c198006 */ 	lui	$t9,%hi(var8005f66c+0x2)
/*    3ec98:	856c0058 */ 	lh	$t4,0x58($t3)
/*    3ec9c:	856e005a */ 	lh	$t6,0x5a($t3)
/*    3eca0:	000c6823 */ 	negu	$t5,$t4
/*    3eca4:	000d4040 */ 	sll	$t0,$t5,0x1
/*    3eca8:	0328c821 */ 	addu	$t9,$t9,$t0
/*    3ecac:	8739f66e */ 	lh	$t9,%lo(var8005f66c+0x2)($t9)
/*    3ecb0:	032e0019 */ 	multu	$t9,$t6
/*    3ecb4:	00007812 */ 	mflo	$t7
/*    3ecb8:	000f4bc3 */ 	sra	$t1,$t7,0xf
/*    3ecbc:	a569006e */ 	sh	$t1,0x6e($t3)
/*    3ecc0:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ecc4:	8d580074 */ 	lw	$t8,0x74($t2)
/*    3ecc8:	ad580070 */ 	sw	$t8,0x70($t2)
/*    3eccc:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ecd0:	858d0068 */ 	lh	$t5,0x68($t4)
/*    3ecd4:	a58d005c */ 	sh	$t5,0x5c($t4)
/*    3ecd8:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ecdc:	8519006e */ 	lh	$t9,0x6e($t0)
/*    3ece0:	10000011 */ 	b	.L0003ed28
/*    3ece4:	a519005e */ 	sh	$t9,0x5e($t0)
.L0003ece8:
/*    3ece8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ecec:	85c4005c */ 	lh	$a0,0x5c($t6)
/*    3ecf0:	8dc50070 */ 	lw	$a1,0x70($t6)
/*    3ecf4:	85c60066 */ 	lh	$a2,0x66($t6)
/*    3ecf8:	0c00fe07 */ 	jal	func0003f81c
/*    3ecfc:	95c70064 */ 	lhu	$a3,0x64($t6)
/*    3ed00:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3ed04:	a5e2005c */ 	sh	$v0,0x5c($t7)
/*    3ed08:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3ed0c:	8524005e */ 	lh	$a0,0x5e($t1)
/*    3ed10:	8d250070 */ 	lw	$a1,0x70($t1)
/*    3ed14:	8526006c */ 	lh	$a2,0x6c($t1)
/*    3ed18:	0c00fe07 */ 	jal	func0003f81c
/*    3ed1c:	9527006a */ 	lhu	$a3,0x6a($t1)
/*    3ed20:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3ed24:	a562005e */ 	sh	$v0,0x5e($t3)
.L0003ed28:
/*    3ed28:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3ed2c:	870a005c */ 	lh	$t2,0x5c($t8)
/*    3ed30:	15400004 */ 	bnez	$t2,.L0003ed44
/*    3ed34:	00000000 */ 	nop
/*    3ed38:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ed3c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    3ed40:	a58d005c */ 	sh	$t5,0x5c($t4)
.L0003ed44:
/*    3ed44:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ed48:	8728005e */ 	lh	$t0,0x5e($t9)
/*    3ed4c:	15000004 */ 	bnez	$t0,.L0003ed60
/*    3ed50:	00000000 */ 	nop
/*    3ed54:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3ed58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3ed5c:	a5ee005e */ 	sh	$t6,0x5e($t7)
.L0003ed60:
/*    3ed60:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3ed64:	2401000c */ 	addiu	$at,$zero,0xc
/*    3ed68:	8d2b007c */ 	lw	$t3,0x7c($t1)
/*    3ed6c:	85780008 */ 	lh	$t8,0x8($t3)
/*    3ed70:	17010018 */ 	bne	$t8,$at,.L0003edd4
/*    3ed74:	00000000 */ 	nop
/*    3ed78:	3c0a800a */ 	lui	$t2,%hi(var8009c340+0x2)
/*    3ed7c:	914ac342 */ 	lbu	$t2,%lo(var8009c340+0x2)($t2)
/*    3ed80:	11400008 */ 	beqz	$t2,.L0003eda4
/*    3ed84:	00000000 */ 	nop
/*    3ed88:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ed8c:	8dac007c */ 	lw	$t4,0x7c($t5)
/*    3ed90:	8599000e */ 	lh	$t9,0xe($t4)
/*    3ed94:	00194043 */ 	sra	$t0,$t9,0x1
/*    3ed98:	250e0020 */ 	addiu	$t6,$t0,0x20
/*    3ed9c:	1000000d */ 	b	.L0003edd4
/*    3eda0:	a5ae0058 */ 	sh	$t6,0x58($t5)
.L0003eda4:
/*    3eda4:	3c0f800a */ 	lui	$t7,%hi(var8009c340+0x1)
/*    3eda8:	91efc341 */ 	lbu	$t7,%lo(var8009c340+0x1)($t7)
/*    3edac:	11e00005 */ 	beqz	$t7,.L0003edc4
/*    3edb0:	00000000 */ 	nop
/*    3edb4:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3edb8:	24090040 */ 	addiu	$t1,$zero,0x40
/*    3edbc:	10000005 */ 	b	.L0003edd4
/*    3edc0:	a5690058 */ 	sh	$t1,0x58($t3)
.L0003edc4:
/*    3edc4:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3edc8:	8f0a007c */ 	lw	$t2,0x7c($t8)
/*    3edcc:	8d4c000c */ 	lw	$t4,0xc($t2)
/*    3edd0:	a70c0058 */ 	sh	$t4,0x58($t8)
.L0003edd4:
/*    3edd4:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3edd8:	2401000b */ 	addiu	$at,$zero,0xb
/*    3eddc:	8f28007c */ 	lw	$t0,0x7c($t9)
/*    3ede0:	850e0008 */ 	lh	$t6,0x8($t0)
/*    3ede4:	15c1001e */ 	bne	$t6,$at,.L0003ee60
/*    3ede8:	00000000 */ 	nop
/*    3edec:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3edf0:	ada00070 */ 	sw	$zero,0x70($t5)
/*    3edf4:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3edf8:	8de9007c */ 	lw	$t1,0x7c($t7)
/*    3edfc:	8d2b000c */ 	lw	$t3,0xc($t1)
/*    3ee00:	afab0038 */ 	sw	$t3,0x38($sp)
/*    3ee04:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    3ee08:	014a6021 */ 	addu	$t4,$t2,$t2
/*    3ee0c:	05810003 */ 	bgez	$t4,.L0003ee1c
/*    3ee10:	000cc043 */ 	sra	$t8,$t4,0x1
/*    3ee14:	25810001 */ 	addiu	$at,$t4,0x1
/*    3ee18:	0001c043 */ 	sra	$t8,$at,0x1
.L0003ee1c:
/*    3ee1c:	afb80038 */ 	sw	$t8,0x38($sp)
/*    3ee20:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    3ee24:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ee28:	a519005a */ 	sh	$t9,0x5a($t0)
/*    3ee2c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ee30:	240100b8 */ 	addiu	$at,$zero,0xb8
/*    3ee34:	8dcd007c */ 	lw	$t5,0x7c($t6)
/*    3ee38:	8daf0010 */ 	lw	$t7,0x10($t5)
/*    3ee3c:	25e900b7 */ 	addiu	$t1,$t7,0xb7
/*    3ee40:	0121001a */ 	div	$zero,$t1,$at
/*    3ee44:	00005812 */ 	mflo	$t3
/*    3ee48:	000b5080 */ 	sll	$t2,$t3,0x2
/*    3ee4c:	014b5023 */ 	subu	$t2,$t2,$t3
/*    3ee50:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    3ee54:	014b5023 */ 	subu	$t2,$t2,$t3
/*    3ee58:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    3ee5c:	adca0074 */ 	sw	$t2,0x74($t6)
.L0003ee60:
/*    3ee60:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3ee64:	24010010 */ 	addiu	$at,$zero,0x10
/*    3ee68:	8d98007c */ 	lw	$t8,0x7c($t4)
/*    3ee6c:	87190008 */ 	lh	$t9,0x8($t8)
/*    3ee70:	1721003a */ 	bne	$t9,$at,.L0003ef5c
/*    3ee74:	00000000 */ 	nop
/*    3ee78:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3ee7c:	8d0a007c */ 	lw	$t2,0x7c($t0)
/*    3ee80:	850d0060 */ 	lh	$t5,0x60($t0)
/*    3ee84:	850f0062 */ 	lh	$t7,0x62($t0)
/*    3ee88:	8d4e000c */ 	lw	$t6,0xc($t2)
/*    3ee8c:	01af4826 */ 	xor	$t1,$t5,$t7
/*    3ee90:	25cc0001 */ 	addiu	$t4,$t6,0x1
/*    3ee94:	000cc1c3 */ 	sra	$t8,$t4,0x7
/*    3ee98:	312b0001 */ 	andi	$t3,$t1,0x1
/*    3ee9c:	0178c826 */ 	xor	$t9,$t3,$t8
/*    3eea0:	13200013 */ 	beqz	$t9,.L0003eef0
/*    3eea4:	00000000 */ 	nop
/*    3eea8:	3c0d800a */ 	lui	$t5,%hi(var8009c340)
/*    3eeac:	91adc340 */ 	lbu	$t5,%lo(var8009c340)($t5)
/*    3eeb0:	11a0000f */ 	beqz	$t5,.L0003eef0
/*    3eeb4:	00000000 */ 	nop
/*    3eeb8:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3eebc:	85e90058 */ 	lh	$t1,0x58($t7)
/*    3eec0:	29210041 */ 	slti	$at,$t1,0x41
/*    3eec4:	14200006 */ 	bnez	$at,.L0003eee0
/*    3eec8:	00000000 */ 	nop
/*    3eecc:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3eed0:	850a0060 */ 	lh	$t2,0x60($t0)
/*    3eed4:	394e0001 */ 	xori	$t6,$t2,0x1
/*    3eed8:	10000005 */ 	b	.L0003eef0
/*    3eedc:	a50e0060 */ 	sh	$t6,0x60($t0)
.L0003eee0:
/*    3eee0:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    3eee4:	858b0062 */ 	lh	$t3,0x62($t4)
/*    3eee8:	39780001 */ 	xori	$t8,$t3,0x1
/*    3eeec:	a5980062 */ 	sh	$t8,0x62($t4)
.L0003eef0:
/*    3eef0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3eef4:	3c0e8006 */ 	lui	$t6,%hi(var8005f570)
/*    3eef8:	8f2d007c */ 	lw	$t5,0x7c($t9)
/*    3eefc:	872b0060 */ 	lh	$t3,0x60($t9)
/*    3ef00:	8daf000c */ 	lw	$t7,0xc($t5)
/*    3ef04:	31780001 */ 	andi	$t8,$t3,0x1
/*    3ef08:	31e9007f */ 	andi	$t1,$t7,0x7f
/*    3ef0c:	00095040 */ 	sll	$t2,$t1,0x1
/*    3ef10:	01ca7021 */ 	addu	$t6,$t6,$t2
/*    3ef14:	85cef570 */ 	lh	$t6,%lo(var8005f570)($t6)
/*    3ef18:	31c8fffe */ 	andi	$t0,$t6,0xfffe
/*    3ef1c:	01186025 */ 	or	$t4,$t0,$t8
/*    3ef20:	a72c0060 */ 	sh	$t4,0x60($t9)
/*    3ef24:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3ef28:	3c088006 */ 	lui	$t0,%hi(var8005f66c+0x2)
/*    3ef2c:	8daf007c */ 	lw	$t7,0x7c($t5)
/*    3ef30:	85ac0062 */ 	lh	$t4,0x62($t5)
/*    3ef34:	8de9000c */ 	lw	$t1,0xc($t7)
/*    3ef38:	31990001 */ 	andi	$t9,$t4,0x1
/*    3ef3c:	312a007f */ 	andi	$t2,$t1,0x7f
/*    3ef40:	000a7023 */ 	negu	$t6,$t2
/*    3ef44:	000e5840 */ 	sll	$t3,$t6,0x1
/*    3ef48:	010b4021 */ 	addu	$t0,$t0,$t3
/*    3ef4c:	8508f66e */ 	lh	$t0,%lo(var8005f66c+0x2)($t0)
/*    3ef50:	3118fffe */ 	andi	$t8,$t0,0xfffe
/*    3ef54:	03197825 */ 	or	$t7,$t8,$t9
/*    3ef58:	a5af0062 */ 	sh	$t7,0x62($t5)
.L0003ef5c:
/*    3ef5c:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3ef60:	24090001 */ 	addiu	$t1,$zero,0x1
/*    3ef64:	ad490078 */ 	sw	$t1,0x78($t2)
/*    3ef68:	10000069 */ 	b	.L0003f110
/*    3ef6c:	00000000 */ 	nop
/*    3ef70:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3ef74:	8dcb007c */ 	lw	$t3,0x7c($t6)
/*    3ef78:	afab0024 */ 	sw	$t3,0x24($sp)
/*    3ef7c:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3ef80:	850c000a */ 	lh	$t4,0xa($t0)
/*    3ef84:	11800004 */ 	beqz	$t4,.L0003ef98
/*    3ef88:	00000000 */ 	nop
/*    3ef8c:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3ef90:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3ef94:	af380048 */ 	sw	$t8,0x48($t9)
.L0003ef98:
/*    3ef98:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3ef9c:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3efa0:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3efa4:	0c011582 */ 	jal	func00045608
/*    3efa8:	8de6000c */ 	lw	$a2,0xc($t7)
/*    3efac:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    3efb0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    3efb4:	ad2d0084 */ 	sw	$t5,0x84($t1)
/*    3efb8:	10000055 */ 	b	.L0003f110
/*    3efbc:	00000000 */ 	nop
/*    3efc0:	8faa0054 */ 	lw	$t2,0x54($sp)
/*    3efc4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3efc8:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3efcc:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3efd0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3efd4:	0c00fcca */ 	jal	func0003f328
/*    3efd8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    3efdc:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3efe0:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3efe4:	24050004 */ 	addiu	$a1,$zero,0x4
/*    3efe8:	0c00fc79 */ 	jal	func0003f1e4
/*    3efec:	00003025 */ 	or	$a2,$zero,$zero
/*    3eff0:	10000047 */ 	b	.L0003f110
/*    3eff4:	00000000 */ 	nop
/*    3eff8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3effc:	8dcb007c */ 	lw	$t3,0x7c($t6)
/*    3f000:	afab0020 */ 	sw	$t3,0x20($sp)
/*    3f004:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3f008:	8d0c000c */ 	lw	$t4,0xc($t0)
/*    3f00c:	ad800088 */ 	sw	$zero,0x88($t4)
/*    3f010:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3f014:	0c00c57d */ 	jal	func000315f4
/*    3f018:	8f04000c */ 	lw	$a0,0xc($t8)
/*    3f01c:	1000003c */ 	b	.L0003f110
/*    3f020:	00000000 */ 	nop
/*    3f024:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    3f028:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f02c:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f030:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f034:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f038:	0c00fcca */ 	jal	func0003f328
/*    3f03c:	afb90010 */ 	sw	$t9,0x10($sp)
/*    3f040:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f044:	8faf0050 */ 	lw	$t7,0x50($sp)
/*    3f048:	8ded007c */ 	lw	$t5,0x7c($t7)
/*    3f04c:	c5aa000c */ 	lwc1	$f10,0xc($t5)
/*    3f050:	e5ea0044 */ 	swc1	$f10,0x44($t7)
/*    3f054:	1000002e */ 	b	.L0003f110
/*    3f058:	00000000 */ 	nop
/*    3f05c:	8fa90054 */ 	lw	$t1,0x54($sp)
/*    3f060:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f064:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f068:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f06c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f070:	0c00fcca */ 	jal	func0003f328
/*    3f074:	afa90010 */ 	sw	$t1,0x10($sp)
/*    3f078:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f07c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    3f080:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    3f084:	adca0048 */ 	sw	$t2,0x48($t6)
/*    3f088:	10000021 */ 	b	.L0003f110
/*    3f08c:	00000000 */ 	nop
/*    3f090:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    3f094:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f098:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f09c:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f0a0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f0a4:	0c00fcca */ 	jal	func0003f328
/*    3f0a8:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3f0ac:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f0b0:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3f0b4:	24050005 */ 	addiu	$a1,$zero,0x5
/*    3f0b8:	8d0c007c */ 	lw	$t4,0x7c($t0)
/*    3f0bc:	01002025 */ 	or	$a0,$t0,$zero
/*    3f0c0:	0c011582 */ 	jal	func00045608
/*    3f0c4:	8d86000c */ 	lw	$a2,0xc($t4)
/*    3f0c8:	10000011 */ 	b	.L0003f110
/*    3f0cc:	00000000 */ 	nop
.L0003f0d0:
/*    3f0d0:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    3f0d4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f0d8:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f0dc:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f0e0:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    3f0e4:	0c00fcca */ 	jal	func0003f328
/*    3f0e8:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3f0ec:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f0f0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3f0f4:	8f2d007c */ 	lw	$t5,0x7c($t9)
/*    3f0f8:	03202025 */ 	or	$a0,$t9,$zero
/*    3f0fc:	85a50008 */ 	lh	$a1,0x8($t5)
/*    3f100:	0c00fc79 */ 	jal	func0003f1e4
/*    3f104:	8da6000c */ 	lw	$a2,0xc($t5)
/*    3f108:	10000001 */ 	b	.L0003f110
/*    3f10c:	00000000 */ 	nop
.L0003f110:
/*    3f110:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    3f114:	87af003e */ 	lh	$t7,0x3e($sp)
/*    3f118:	00095040 */ 	sll	$t2,$t1,0x1
/*    3f11c:	01ea7021 */ 	addu	$t6,$t7,$t2
/*    3f120:	a7ae003e */ 	sh	$t6,0x3e($sp)
/*    3f124:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3f128:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    3f12c:	01686023 */ 	subu	$t4,$t3,$t0
/*    3f130:	afac0030 */ 	sw	$t4,0x30($sp)
/*    3f134:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    3f138:	8f19007c */ 	lw	$t9,0x7c($t8)
/*    3f13c:	afb90034 */ 	sw	$t9,0x34($sp)
/*    3f140:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3f144:	8da9007c */ 	lw	$t1,0x7c($t5)
/*    3f148:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*    3f14c:	adaf007c */ 	sw	$t7,0x7c($t5)
/*    3f150:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    3f154:	8d4e007c */ 	lw	$t6,0x7c($t2)
/*    3f158:	15c00003 */ 	bnez	$t6,.L0003f168
/*    3f15c:	00000000 */ 	nop
/*    3f160:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    3f164:	ad600080 */ 	sw	$zero,0x80($t3)
.L0003f168:
/*    3f168:	0c00c559 */ 	jal	func00031564
/*    3f16c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    3f170:	8fa80050 */ 	lw	$t0,0x50($sp)
/*    3f174:	8d0c007c */ 	lw	$t4,0x7c($t0)
/*    3f178:	1580fde4 */ 	bnez	$t4,.L0003e90c
/*    3f17c:	00000000 */ 	nop
.L0003f180:
/*    3f180:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    3f184:	8fa40050 */ 	lw	$a0,0x50($sp)
/*    3f188:	27a5004e */ 	addiu	$a1,$sp,0x4e
/*    3f18c:	27a6003e */ 	addiu	$a2,$sp,0x3e
/*    3f190:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    3f194:	0c00fcca */ 	jal	func0003f328
/*    3f198:	afb80010 */ 	sw	$t8,0x10($sp)
/*    3f19c:	afa20054 */ 	sw	$v0,0x54($sp)
/*    3f1a0:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    3f1a4:	8f290070 */ 	lw	$t1,0x70($t9)
/*    3f1a8:	8f2f0074 */ 	lw	$t7,0x74($t9)
/*    3f1ac:	01e9082a */ 	slt	$at,$t7,$t1
/*    3f1b0:	10200004 */ 	beqz	$at,.L0003f1c4
/*    3f1b4:	00000000 */ 	nop
/*    3f1b8:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    3f1bc:	8daa0074 */ 	lw	$t2,0x74($t5)
/*    3f1c0:	adaa0070 */ 	sw	$t2,0x70($t5)
.L0003f1c4:
/*    3f1c4:	10000003 */ 	b	.L0003f1d4
/*    3f1c8:	8fa20054 */ 	lw	$v0,0x54($sp)
/*    3f1cc:	10000001 */ 	b	.L0003f1d4
/*    3f1d0:	00000000 */ 	nop
.L0003f1d4:
/*    3f1d4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3f1d8:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    3f1dc:	03e00008 */ 	jr	$ra
/*    3f1e0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003f1e4
/*    3f1e4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3f1e8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3f1ec:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3f1f0:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3f1f4:	afa60030 */ 	sw	$a2,0x30($sp)
/*    3f1f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*    3f1fc:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3f200:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3f204:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*    3f208:	24010003 */ 	addiu	$at,$zero,0x3
/*    3f20c:	12010009 */ 	beq	$s0,$at,.L0003f234
/*    3f210:	00000000 */ 	nop
/*    3f214:	24010004 */ 	addiu	$at,$zero,0x4
/*    3f218:	12010017 */ 	beq	$s0,$at,.L0003f278
/*    3f21c:	00000000 */ 	nop
/*    3f220:	24010009 */ 	addiu	$at,$zero,0x9
/*    3f224:	1201002c */ 	beq	$s0,$at,.L0003f2d8
/*    3f228:	00000000 */ 	nop
/*    3f22c:	1000002f */ 	b	.L0003f2ec
/*    3f230:	00000000 */ 	nop
.L0003f234:
/*    3f234:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3f238:	8df80080 */ 	lw	$t8,0x80($t7)
/*    3f23c:	13000006 */ 	beqz	$t8,.L0003f258
/*    3f240:	00000000 */ 	nop
/*    3f244:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3f248:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    3f24c:	8d090080 */ 	lw	$t1,0x80($t0)
/*    3f250:	10000004 */ 	b	.L0003f264
/*    3f254:	ad390000 */ 	sw	$t9,0x0($t1)
.L0003f258:
/*    3f258:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    3f25c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3f260:	ad6a007c */ 	sw	$t2,0x7c($t3)
.L0003f264:
/*    3f264:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f268:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3f26c:	adac0080 */ 	sw	$t4,0x80($t5)
/*    3f270:	10000024 */ 	b	.L0003f304
/*    3f274:	00000000 */ 	nop
.L0003f278:
/*    3f278:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3f27c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3f280:	adee0078 */ 	sw	$t6,0x78($t7)
/*    3f284:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3f288:	af000084 */ 	sw	$zero,0x84($t8)
/*    3f28c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3f290:	24080001 */ 	addiu	$t0,$zero,0x1
/*    3f294:	a728005a */ 	sh	$t0,0x5a($t9)
/*    3f298:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3f29c:	ad200074 */ 	sw	$zero,0x74($t1)
/*    3f2a0:	44802000 */ 	mtc1	$zero,$f4
/*    3f2a4:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3f2a8:	e544004c */ 	swc1	$f4,0x4c($t2)
/*    3f2ac:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3f2b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    3f2b4:	ad8b0050 */ 	sw	$t3,0x50($t4)
/*    3f2b8:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3f2bc:	ada00048 */ 	sw	$zero,0x48($t5)
/*    3f2c0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3f2c4:	24050004 */ 	addiu	$a1,$zero,0x4
/*    3f2c8:	0c01176a */ 	jal	func00045da8
/*    3f2cc:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    3f2d0:	1000000c */ 	b	.L0003f304
/*    3f2d4:	00000000 */ 	nop
.L0003f2d8:
/*    3f2d8:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3f2dc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3f2e0:	adee0084 */ 	sw	$t6,0x84($t7)
/*    3f2e4:	10000007 */ 	b	.L0003f304
/*    3f2e8:	00000000 */ 	nop
.L0003f2ec:
/*    3f2ec:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3f2f0:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    3f2f4:	0c01176a */ 	jal	func00045da8
/*    3f2f8:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    3f2fc:	10000001 */ 	b	.L0003f304
/*    3f300:	00000000 */ 	nop
.L0003f304:
/*    3f304:	10000003 */ 	b	.L0003f314
/*    3f308:	00001025 */ 	or	$v0,$zero,$zero
/*    3f30c:	10000001 */ 	b	.L0003f314
/*    3f310:	00000000 */ 	nop
.L0003f314:
/*    3f314:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    3f318:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    3f31c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3f320:	03e00008 */ 	jr	$ra
/*    3f324:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003f328
/*    3f328:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    3f32c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3f330:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3f334:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    3f338:	afa60040 */ 	sw	$a2,0x40($sp)
/*    3f33c:	afa70044 */ 	sw	$a3,0x44($sp)
/*    3f340:	8fae0048 */ 	lw	$t6,0x48($sp)
/*    3f344:	afae0034 */ 	sw	$t6,0x34($sp)
/*    3f348:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3f34c:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    3f350:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    3f354:	24010001 */ 	addiu	$at,$zero,0x1
/*    3f358:	8f190084 */ 	lw	$t9,0x84($t8)
/*    3f35c:	17210004 */ 	bne	$t9,$at,.L0003f370
/*    3f360:	00000000 */ 	nop
/*    3f364:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    3f368:	15000003 */ 	bnez	$t0,.L0003f378
/*    3f36c:	00000000 */ 	nop
.L0003f370:
/*    3f370:	100000a2 */ 	b	.L0003f5fc
/*    3f374:	8fa20034 */ 	lw	$v0,0x34($sp)
.L0003f378:
/*    3f378:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    3f37c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    3f380:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    3f384:	0c0116ac */ 	jal	func00045ab0
/*    3f388:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    3f38c:	afa20034 */ 	sw	$v0,0x34($sp)
/*    3f390:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f394:	8d2a0078 */ 	lw	$t2,0x78($t1)
/*    3f398:	11400080 */ 	beqz	$t2,.L0003f59c
/*    3f39c:	00000000 */ 	nop
/*    3f3a0:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3f3a4:	ad600078 */ 	sw	$zero,0x78($t3)
/*    3f3a8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f3ac:	3c0f8006 */ 	lui	$t7,%hi(var8005f570)
/*    3f3b0:	858d0058 */ 	lh	$t5,0x58($t4)
/*    3f3b4:	8598005a */ 	lh	$t8,0x5a($t4)
/*    3f3b8:	000d7040 */ 	sll	$t6,$t5,0x1
/*    3f3bc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    3f3c0:	85eff570 */ 	lh	$t7,%lo(var8005f570)($t7)
/*    3f3c4:	01f80019 */ 	multu	$t7,$t8
/*    3f3c8:	0000c812 */ 	mflo	$t9
/*    3f3cc:	001943c3 */ 	sra	$t0,$t9,0xf
/*    3f3d0:	a5880068 */ 	sh	$t0,0x68($t4)
/*    3f3d4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f3d8:	852a005c */ 	lh	$t2,0x5c($t1)
/*    3f3dc:	852b0068 */ 	lh	$t3,0x68($t1)
/*    3f3e0:	8d260074 */ 	lw	$a2,0x74($t1)
/*    3f3e4:	448a2000 */ 	mtc1	$t2,$f4
/*    3f3e8:	448b3000 */ 	mtc1	$t3,$f6
/*    3f3ec:	25270064 */ 	addiu	$a3,$t1,0x64
/*    3f3f0:	46802320 */ 	cvt.s.w	$f12,$f4
/*    3f3f4:	0c00fd83 */ 	jal	func0003f60c
/*    3f3f8:	468033a0 */ 	cvt.s.w	$f14,$f6
/*    3f3fc:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    3f400:	a5a20066 */ 	sh	$v0,0x66($t5)
/*    3f404:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    3f408:	3c088006 */ 	lui	$t0,%hi(var8005f66c+0x2)
/*    3f40c:	85cf0058 */ 	lh	$t7,0x58($t6)
/*    3f410:	85cc005a */ 	lh	$t4,0x5a($t6)
/*    3f414:	000fc023 */ 	negu	$t8,$t7
/*    3f418:	0018c840 */ 	sll	$t9,$t8,0x1
/*    3f41c:	01194021 */ 	addu	$t0,$t0,$t9
/*    3f420:	8508f66e */ 	lh	$t0,%lo(var8005f66c+0x2)($t0)
/*    3f424:	010c0019 */ 	multu	$t0,$t4
/*    3f428:	00005012 */ 	mflo	$t2
/*    3f42c:	000a5bc3 */ 	sra	$t3,$t2,0xf
/*    3f430:	a5cb006e */ 	sh	$t3,0x6e($t6)
/*    3f434:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f438:	852d005e */ 	lh	$t5,0x5e($t1)
/*    3f43c:	852f006e */ 	lh	$t7,0x6e($t1)
/*    3f440:	8d260074 */ 	lw	$a2,0x74($t1)
/*    3f444:	448d4000 */ 	mtc1	$t5,$f8
/*    3f448:	448f5000 */ 	mtc1	$t7,$f10
/*    3f44c:	2527006a */ 	addiu	$a3,$t1,0x6a
/*    3f450:	46804320 */ 	cvt.s.w	$f12,$f8
/*    3f454:	0c00fd83 */ 	jal	func0003f60c
/*    3f458:	468053a0 */ 	cvt.s.w	$f14,$f10
/*    3f45c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    3f460:	a702006c */ 	sh	$v0,0x6c($t8)
/*    3f464:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    3f468:	27280008 */ 	addiu	$t0,$t9,0x8
/*    3f46c:	afa80034 */ 	sw	$t0,0x34($sp)
/*    3f470:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    3f474:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f478:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    3f47c:	3c010906 */ 	lui	$at,0x906
/*    3f480:	858a005c */ 	lh	$t2,0x5c($t4)
/*    3f484:	314bffff */ 	andi	$t3,$t2,0xffff
/*    3f488:	01617025 */ 	or	$t6,$t3,$at
/*    3f48c:	adae0000 */ 	sw	$t6,0x0($t5)
/*    3f490:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3f494:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3f498:	85e90060 */ 	lh	$t1,0x60($t7)
/*    3f49c:	85e80062 */ 	lh	$t0,0x62($t7)
/*    3f4a0:	3138ffff */ 	andi	$t8,$t1,0xffff
/*    3f4a4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*    3f4a8:	310cffff */ 	andi	$t4,$t0,0xffff
/*    3f4ac:	032c5025 */ 	or	$t2,$t9,$t4
/*    3f4b0:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*    3f4b4:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    3f4b8:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*    3f4bc:	afad0034 */ 	sw	$t5,0x34($sp)
/*    3f4c0:	afae0028 */ 	sw	$t6,0x28($sp)
/*    3f4c4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f4c8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3f4cc:	3c010904 */ 	lui	$at,0x904
/*    3f4d0:	8538006e */ 	lh	$t8,0x6e($t1)
/*    3f4d4:	330fffff */ 	andi	$t7,$t8,0xffff
/*    3f4d8:	01e14025 */ 	or	$t0,$t7,$at
/*    3f4dc:	af280000 */ 	sw	$t0,0x0($t9)
/*    3f4e0:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3f4e4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3f4e8:	858a006c */ 	lh	$t2,0x6c($t4)
/*    3f4ec:	958d006a */ 	lhu	$t5,0x6a($t4)
/*    3f4f0:	314bffff */ 	andi	$t3,$t2,0xffff
/*    3f4f4:	000b7400 */ 	sll	$t6,$t3,0x10
/*    3f4f8:	31a9ffff */ 	andi	$t1,$t5,0xffff
/*    3f4fc:	01c9c025 */ 	or	$t8,$t6,$t1
/*    3f500:	adf80004 */ 	sw	$t8,0x4($t7)
/*    3f504:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    3f508:	25190008 */ 	addiu	$t9,$t0,0x8
/*    3f50c:	afb90034 */ 	sw	$t9,0x34($sp)
/*    3f510:	afa80024 */ 	sw	$t0,0x24($sp)
/*    3f514:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    3f518:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3f51c:	3c010900 */ 	lui	$at,0x900
/*    3f520:	854b0068 */ 	lh	$t3,0x68($t2)
/*    3f524:	316cffff */ 	andi	$t4,$t3,0xffff
/*    3f528:	01816825 */ 	or	$t5,$t4,$at
/*    3f52c:	adcd0000 */ 	sw	$t5,0x0($t6)
/*    3f530:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3f534:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3f538:	85380066 */ 	lh	$t8,0x66($t1)
/*    3f53c:	95390064 */ 	lhu	$t9,0x64($t1)
/*    3f540:	330fffff */ 	andi	$t7,$t8,0xffff
/*    3f544:	000f4400 */ 	sll	$t0,$t7,0x10
/*    3f548:	332affff */ 	andi	$t2,$t9,0xffff
/*    3f54c:	010a5825 */ 	or	$t3,$t0,$t2
/*    3f550:	ad8b0004 */ 	sw	$t3,0x4($t4)
/*    3f554:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    3f558:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*    3f55c:	afae0034 */ 	sw	$t6,0x34($sp)
/*    3f560:	afad0020 */ 	sw	$t5,0x20($sp)
/*    3f564:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    3f568:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3f56c:	3c010301 */ 	lui	$at,0x301
/*    3f570:	870f005e */ 	lh	$t7,0x5e($t8)
/*    3f574:	31e9ffff */ 	andi	$t1,$t7,0xffff
/*    3f578:	0121c825 */ 	or	$t9,$t1,$at
/*    3f57c:	ad190000 */ 	sw	$t9,0x0($t0)
/*    3f580:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    3f584:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3f588:	8d440054 */ 	lw	$a0,0x54($t2)
/*    3f58c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3f590:	ad620004 */ 	sw	$v0,0x4($t3)
/*    3f594:	1000000d */ 	b	.L0003f5cc
/*    3f598:	00000000 */ 	nop
.L0003f59c:
/*    3f59c:	8fac0034 */ 	lw	$t4,0x34($sp)
/*    3f5a0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    3f5a4:	afad0034 */ 	sw	$t5,0x34($sp)
/*    3f5a8:	afac001c */ 	sw	$t4,0x1c($sp)
/*    3f5ac:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3f5b0:	3c0e0300 */ 	lui	$t6,0x300
/*    3f5b4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*    3f5b8:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3f5bc:	0c012d20 */ 	jal	osVirtualToPhysical
/*    3f5c0:	8de40054 */ 	lw	$a0,0x54($t7)
/*    3f5c4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3f5c8:	ad220004 */ 	sw	$v0,0x4($t1)
.L0003f5cc:
/*    3f5cc:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    3f5d0:	87280000 */ 	lh	$t0,0x0($t9)
/*    3f5d4:	250a0170 */ 	addiu	$t2,$t0,0x170
/*    3f5d8:	a72a0000 */ 	sh	$t2,0x0($t9)
/*    3f5dc:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3f5e0:	8d6c0070 */ 	lw	$t4,0x70($t3)
/*    3f5e4:	258d00b8 */ 	addiu	$t5,$t4,0xb8
/*    3f5e8:	ad6d0070 */ 	sw	$t5,0x70($t3)
/*    3f5ec:	10000003 */ 	b	.L0003f5fc
/*    3f5f0:	8fa20034 */ 	lw	$v0,0x34($sp)
/*    3f5f4:	10000001 */ 	b	.L0003f5fc
/*    3f5f8:	00000000 */ 	nop
.L0003f5fc:
/*    3f5fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3f600:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    3f604:	03e00008 */ 	jr	$ra
/*    3f608:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003f60c
/*    3f60c:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    3f610:	14c0000e */ 	bnez	$a2,.L0003f64c
/*    3f614:	00000000 */ 	nop
/*    3f618:	460e603e */ 	c.le.s	$f12,$f14
/*    3f61c:	00000000 */ 	nop
/*    3f620:	45000007 */ 	bc1f	.L0003f640
/*    3f624:	00000000 */ 	nop
/*    3f628:	340effff */ 	dli	$t6,0xffff
/*    3f62c:	a4ee0000 */ 	sh	$t6,0x0($a3)
/*    3f630:	10000078 */ 	b	.L0003f814
/*    3f634:	24027fff */ 	addiu	$v0,$zero,0x7fff
/*    3f638:	10000004 */ 	b	.L0003f64c
/*    3f63c:	00000000 */ 	nop
.L0003f640:
/*    3f640:	a4e00000 */ 	sh	$zero,0x0($a3)
/*    3f644:	10000073 */ 	b	.L0003f814
/*    3f648:	24028000 */ 	addiu	$v0,$zero,-32768
.L0003f64c:
/*    3f64c:	44863000 */ 	mtc1	$a2,$f6
/*    3f650:	3c013f80 */ 	lui	$at,0x3f80
/*    3f654:	44812000 */ 	mtc1	$at,$f4
/*    3f658:	46803220 */ 	cvt.s.w	$f8,$f6
/*    3f65c:	46082283 */ 	div.s	$f10,$f4,$f8
/*    3f660:	e7aa0008 */ 	swc1	$f10,0x8($sp)
/*    3f664:	3c013f80 */ 	lui	$at,0x3f80
/*    3f668:	44818000 */ 	mtc1	$at,$f16
/*    3f66c:	00000000 */ 	nop
/*    3f670:	4610703c */ 	c.lt.s	$f14,$f16
/*    3f674:	00000000 */ 	nop
/*    3f678:	45000004 */ 	bc1f	.L0003f68c
/*    3f67c:	00000000 */ 	nop
/*    3f680:	3c013f80 */ 	lui	$at,0x3f80
/*    3f684:	44817000 */ 	mtc1	$at,$f14
/*    3f688:	00000000 */ 	nop
.L0003f68c:
/*    3f68c:	44809000 */ 	mtc1	$zero,$f18
/*    3f690:	00000000 */ 	nop
/*    3f694:	4612603e */ 	c.le.s	$f12,$f18
/*    3f698:	00000000 */ 	nop
/*    3f69c:	45000004 */ 	bc1f	.L0003f6b0
/*    3f6a0:	00000000 */ 	nop
/*    3f6a4:	3c013f80 */ 	lui	$at,0x3f80
/*    3f6a8:	44816000 */ 	mtc1	$at,$f12
/*    3f6ac:	00000000 */ 	nop
.L0003f6b0:
/*    3f6b0:	460c7181 */ 	sub.s	$f6,$f14,$f12
/*    3f6b4:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    3f6b8:	3c014100 */ 	lui	$at,0x4100
/*    3f6bc:	44815000 */ 	mtc1	$at,$f10
/*    3f6c0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    3f6c4:	00000000 */ 	nop
/*    3f6c8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    3f6cc:	e7b00004 */ 	swc1	$f16,0x4($sp)
/*    3f6d0:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    3f6d4:	4600918d */ 	trunc.w.s	$f6,$f18
/*    3f6d8:	44183000 */ 	mfc1	$t8,$f6
/*    3f6dc:	00000000 */ 	nop
/*    3f6e0:	a7b8000e */ 	sh	$t8,0xe($sp)
/*    3f6e4:	87b9000e */ 	lh	$t9,0xe($sp)
/*    3f6e8:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3f6ec:	44994000 */ 	mtc1	$t9,$f8
/*    3f6f0:	00000000 */ 	nop
/*    3f6f4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    3f6f8:	460a2401 */ 	sub.s	$f16,$f4,$f10
/*    3f6fc:	e7b00000 */ 	swc1	$f16,0x0($sp)
/*    3f700:	87a8000e */ 	lh	$t0,0xe($sp)
/*    3f704:	2509ffff */ 	addiu	$t1,$t0,-1
/*    3f708:	a7a9000e */ 	sh	$t1,0xe($sp)
/*    3f70c:	3c013f80 */ 	lui	$at,0x3f80
/*    3f710:	44813000 */ 	mtc1	$at,$f6
/*    3f714:	c7b20000 */ 	lwc1	$f18,0x0($sp)
/*    3f718:	46069200 */ 	add.s	$f8,$f18,$f6
/*    3f71c:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    3f720:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    3f724:	4600228d */ 	trunc.w.s	$f10,$f4
/*    3f728:	440b5000 */ 	mfc1	$t3,$f10
/*    3f72c:	00000000 */ 	nop
/*    3f730:	a7ab000c */ 	sh	$t3,0xc($sp)
/*    3f734:	87ac000e */ 	lh	$t4,0xe($sp)
/*    3f738:	87ad000c */ 	lh	$t5,0xc($sp)
/*    3f73c:	018d7021 */ 	addu	$t6,$t4,$t5
/*    3f740:	a7ae000e */ 	sh	$t6,0xe($sp)
/*    3f744:	87af000c */ 	lh	$t7,0xc($sp)
/*    3f748:	c7b00000 */ 	lwc1	$f16,0x0($sp)
/*    3f74c:	448f9000 */ 	mtc1	$t7,$f18
/*    3f750:	00000000 */ 	nop
/*    3f754:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    3f758:	46068201 */ 	sub.s	$f8,$f16,$f6
/*    3f75c:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    3f760:	3c017005 */ 	lui	$at,%hi(var70054b34)
/*    3f764:	c4244b34 */ 	lwc1	$f4,%lo(var70054b34)($at)
/*    3f768:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    3f76c:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3f770:	460a2482 */ 	mul.s	$f18,$f4,$f10
/*    3f774:	4458f800 */ 	cfc1	$t8,$31
/*    3f778:	44d9f800 */ 	ctc1	$t9,$31
/*    3f77c:	00000000 */ 	nop
/*    3f780:	46009424 */ 	cvt.w.s	$f16,$f18
/*    3f784:	4459f800 */ 	cfc1	$t9,$31
/*    3f788:	00000000 */ 	nop
/*    3f78c:	33210004 */ 	andi	$at,$t9,0x4
/*    3f790:	33390078 */ 	andi	$t9,$t9,0x78
/*    3f794:	13200014 */ 	beqz	$t9,.L0003f7e8
/*    3f798:	00000000 */ 	nop
/*    3f79c:	3c014f00 */ 	lui	$at,0x4f00
/*    3f7a0:	44818000 */ 	mtc1	$at,$f16
/*    3f7a4:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3f7a8:	46109401 */ 	sub.s	$f16,$f18,$f16
/*    3f7ac:	44d9f800 */ 	ctc1	$t9,$31
/*    3f7b0:	00000000 */ 	nop
/*    3f7b4:	46008424 */ 	cvt.w.s	$f16,$f16
/*    3f7b8:	4459f800 */ 	cfc1	$t9,$31
/*    3f7bc:	00000000 */ 	nop
/*    3f7c0:	33210004 */ 	andi	$at,$t9,0x4
/*    3f7c4:	33390078 */ 	andi	$t9,$t9,0x78
/*    3f7c8:	17200005 */ 	bnez	$t9,.L0003f7e0
/*    3f7cc:	00000000 */ 	nop
/*    3f7d0:	44198000 */ 	mfc1	$t9,$f16
/*    3f7d4:	3c018000 */ 	lui	$at,0x8000
/*    3f7d8:	10000007 */ 	b	.L0003f7f8
/*    3f7dc:	0321c825 */ 	or	$t9,$t9,$at
.L0003f7e0:
/*    3f7e0:	10000005 */ 	b	.L0003f7f8
/*    3f7e4:	2419ffff */ 	addiu	$t9,$zero,-1
.L0003f7e8:
/*    3f7e8:	44198000 */ 	mfc1	$t9,$f16
/*    3f7ec:	00000000 */ 	nop
/*    3f7f0:	0720fffb */ 	bltz	$t9,.L0003f7e0
/*    3f7f4:	00000000 */ 	nop
.L0003f7f8:
/*    3f7f8:	44d8f800 */ 	ctc1	$t8,$31
/*    3f7fc:	a4f90000 */ 	sh	$t9,0x0($a3)
/*    3f800:	00000000 */ 	nop
/*    3f804:	10000003 */ 	b	.L0003f814
/*    3f808:	87a2000e */ 	lh	$v0,0xe($sp)
/*    3f80c:	10000001 */ 	b	.L0003f814
/*    3f810:	00000000 */ 	nop
.L0003f814:
/*    3f814:	03e00008 */ 	jr	$ra
/*    3f818:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func0003f81c
/*    3f81c:	00042400 */ 	sll	$a0,$a0,0x10
/*    3f820:	00063400 */ 	sll	$a2,$a2,0x10
/*    3f824:	00063403 */ 	sra	$a2,$a2,0x10
/*    3f828:	00042403 */ 	sra	$a0,$a0,0x10
/*    3f82c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3f830:	30e7ffff */ 	andi	$a3,$a3,0xffff
/*    3f834:	000528c3 */ 	sra	$a1,$a1,0x3
/*    3f838:	14a00003 */ 	bnez	$a1,.L0003f848
/*    3f83c:	00000000 */ 	nop
/*    3f840:	10000015 */ 	b	.L0003f898
/*    3f844:	00801025 */ 	or	$v0,$a0,$zero
.L0003f848:
/*    3f848:	00e50019 */ 	multu	$a3,$a1
/*    3f84c:	00007012 */ 	mflo	$t6
/*    3f850:	afae0004 */ 	sw	$t6,0x4($sp)
/*    3f854:	00000000 */ 	nop
/*    3f858:	8faf0004 */ 	lw	$t7,0x4($sp)
/*    3f85c:	000fc403 */ 	sra	$t8,$t7,0x10
/*    3f860:	afb80004 */ 	sw	$t8,0x4($sp)
/*    3f864:	00c50019 */ 	multu	$a2,$a1
/*    3f868:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    3f86c:	00004012 */ 	mflo	$t0
/*    3f870:	03284821 */ 	addu	$t1,$t9,$t0
/*    3f874:	afa90004 */ 	sw	$t1,0x4($sp)
/*    3f878:	8faa0004 */ 	lw	$t2,0x4($sp)
/*    3f87c:	008a2021 */ 	addu	$a0,$a0,$t2
/*    3f880:	00042400 */ 	sll	$a0,$a0,0x10
/*    3f884:	00042403 */ 	sra	$a0,$a0,0x10
/*    3f888:	10000003 */ 	b	.L0003f898
/*    3f88c:	00801025 */ 	or	$v0,$a0,$zero
/*    3f890:	10000001 */ 	b	.L0003f898
/*    3f894:	00000000 */ 	nop
.L0003f898:
/*    3f898:	03e00008 */ 	jr	$ra
/*    3f89c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003f8a0
/*    3f8a0:	27bdfd90 */ 	addiu	$sp,$sp,-624
/*    3f8a4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    3f8a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*    3f8ac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3f8b0:	afae0260 */ 	sw	$t6,0x260($sp)
/*    3f8b4:	3c187006 */ 	lui	$t8,%hi(var70059ad4)
/*    3f8b8:	27189ad4 */ 	addiu	$t8,$t8,%lo(var70059ad4)
/*    3f8bc:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3f8c0:	8f190004 */ 	lw	$t9,0x4($t8)
/*    3f8c4:	27af0248 */ 	addiu	$t7,$sp,0x248
/*    3f8c8:	ade80000 */ 	sw	$t0,0x0($t7)
/*    3f8cc:	adf90004 */ 	sw	$t9,0x4($t7)
/*    3f8d0:	afa00234 */ 	sw	$zero,0x234($sp)
/*    3f8d4:	afa0026c */ 	sw	$zero,0x26c($sp)
.L0003f8d8:
/*    3f8d8:	8fa9026c */ 	lw	$t1,0x26c($sp)
/*    3f8dc:	3c013f00 */ 	lui	$at,0x3f00
/*    3f8e0:	44814000 */ 	mtc1	$at,$f8
/*    3f8e4:	44892000 */ 	mtc1	$t1,$f4
/*    3f8e8:	3c017006 */ 	lui	$at,%hi(var70059c54)
/*    3f8ec:	c4309c54 */ 	lwc1	$f16,%lo(var70059c54)($at)
/*    3f8f0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3f8f4:	46083280 */ 	add.s	$f10,$f6,$f8
/*    3f8f8:	46105302 */ 	mul.s	$f12,$f10,$f16
/*    3f8fc:	0c0068f7 */ 	jal	sinf
/*    3f900:	00000000 */ 	nop
/*    3f904:	8faa026c */ 	lw	$t2,0x26c($sp)
/*    3f908:	3c01800a */ 	lui	$at,%hi(var8009c400)
/*    3f90c:	000a5880 */ 	sll	$t3,$t2,0x2
/*    3f910:	002b0821 */ 	addu	$at,$at,$t3
/*    3f914:	e420c400 */ 	swc1	$f0,%lo(var8009c400)($at)
/*    3f918:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    3f91c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    3f920:	29a10024 */ 	slti	$at,$t5,0x24
/*    3f924:	1420ffec */ 	bnez	$at,.L0003f8d8
/*    3f928:	afad026c */ 	sw	$t5,0x26c($sp)
/*    3f92c:	afa0026c */ 	sw	$zero,0x26c($sp)
.L0003f930:
/*    3f930:	8fae026c */ 	lw	$t6,0x26c($sp)
/*    3f934:	3c013f00 */ 	lui	$at,0x3f00
/*    3f938:	44813000 */ 	mtc1	$at,$f6
/*    3f93c:	448e9000 */ 	mtc1	$t6,$f18
/*    3f940:	3c017006 */ 	lui	$at,%hi(var70059c58)
/*    3f944:	c42a9c58 */ 	lwc1	$f10,%lo(var70059c58)($at)
/*    3f948:	46809120 */ 	cvt.s.w	$f4,$f18
/*    3f94c:	46062200 */ 	add.s	$f8,$f4,$f6
/*    3f950:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*    3f954:	0c0068f7 */ 	jal	sinf
/*    3f958:	00000000 */ 	nop
/*    3f95c:	8faf026c */ 	lw	$t7,0x26c($sp)
/*    3f960:	3c01800a */ 	lui	$at,%hi(var8009c490)
/*    3f964:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3f968:	00380821 */ 	addu	$at,$at,$t8
/*    3f96c:	e420c490 */ 	swc1	$f0,%lo(var8009c490)($at)
/*    3f970:	8fb9026c */ 	lw	$t9,0x26c($sp)
/*    3f974:	27280001 */ 	addiu	$t0,$t9,0x1
/*    3f978:	29010012 */ 	slti	$at,$t0,0x12
/*    3f97c:	1420ffec */ 	bnez	$at,.L0003f930
/*    3f980:	afa8026c */ 	sw	$t0,0x26c($sp)
/*    3f984:	24090012 */ 	addiu	$t1,$zero,0x12
/*    3f988:	afa9026c */ 	sw	$t1,0x26c($sp)
.L0003f98c:
/*    3f98c:	8faa026c */ 	lw	$t2,0x26c($sp)
/*    3f990:	3c013f80 */ 	lui	$at,0x3f80
/*    3f994:	44818000 */ 	mtc1	$at,$f16
/*    3f998:	3c01800a */ 	lui	$at,%hi(var8009c490)
/*    3f99c:	000a5880 */ 	sll	$t3,$t2,0x2
/*    3f9a0:	002b0821 */ 	addu	$at,$at,$t3
/*    3f9a4:	e430c490 */ 	swc1	$f16,%lo(var8009c490)($at)
/*    3f9a8:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    3f9ac:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    3f9b0:	29a10018 */ 	slti	$at,$t5,0x18
/*    3f9b4:	1420fff5 */ 	bnez	$at,.L0003f98c
/*    3f9b8:	afad026c */ 	sw	$t5,0x26c($sp)
/*    3f9bc:	240e0018 */ 	addiu	$t6,$zero,0x18
/*    3f9c0:	afae026c */ 	sw	$t6,0x26c($sp)
.L0003f9c4:
/*    3f9c4:	8faf026c */ 	lw	$t7,0x26c($sp)
/*    3f9c8:	3c013f00 */ 	lui	$at,0x3f00
/*    3f9cc:	44813000 */ 	mtc1	$at,$f6
/*    3f9d0:	448f9000 */ 	mtc1	$t7,$f18
/*    3f9d4:	3c014190 */ 	lui	$at,0x4190
/*    3f9d8:	44815000 */ 	mtc1	$at,$f10
/*    3f9dc:	46809120 */ 	cvt.s.w	$f4,$f18
/*    3f9e0:	3c017006 */ 	lui	$at,%hi(var70059c5c)
/*    3f9e4:	c4329c5c */ 	lwc1	$f18,%lo(var70059c5c)($at)
/*    3f9e8:	46062200 */ 	add.s	$f8,$f4,$f6
/*    3f9ec:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*    3f9f0:	46128302 */ 	mul.s	$f12,$f16,$f18
/*    3f9f4:	0c0068f7 */ 	jal	sinf
/*    3f9f8:	00000000 */ 	nop
/*    3f9fc:	8fb8026c */ 	lw	$t8,0x26c($sp)
/*    3fa00:	3c01800a */ 	lui	$at,%hi(var8009c490)
/*    3fa04:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3fa08:	00390821 */ 	addu	$at,$at,$t9
/*    3fa0c:	e420c490 */ 	swc1	$f0,%lo(var8009c490)($at)
/*    3fa10:	8fa8026c */ 	lw	$t0,0x26c($sp)
/*    3fa14:	25090001 */ 	addiu	$t1,$t0,0x1
/*    3fa18:	2921001e */ 	slti	$at,$t1,0x1e
/*    3fa1c:	1420ffe9 */ 	bnez	$at,.L0003f9c4
/*    3fa20:	afa9026c */ 	sw	$t1,0x26c($sp)
/*    3fa24:	240a001e */ 	addiu	$t2,$zero,0x1e
/*    3fa28:	afaa026c */ 	sw	$t2,0x26c($sp)
.L0003fa2c:
/*    3fa2c:	8fab026c */ 	lw	$t3,0x26c($sp)
/*    3fa30:	44802000 */ 	mtc1	$zero,$f4
/*    3fa34:	3c01800a */ 	lui	$at,%hi(var8009c490)
/*    3fa38:	000b6080 */ 	sll	$t4,$t3,0x2
/*    3fa3c:	002c0821 */ 	addu	$at,$at,$t4
/*    3fa40:	e424c490 */ 	swc1	$f4,%lo(var8009c490)($at)
/*    3fa44:	8fad026c */ 	lw	$t5,0x26c($sp)
/*    3fa48:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    3fa4c:	29c10024 */ 	slti	$at,$t6,0x24
/*    3fa50:	1420fff6 */ 	bnez	$at,.L0003fa2c
/*    3fa54:	afae026c */ 	sw	$t6,0x26c($sp)
/*    3fa58:	afa0026c */ 	sw	$zero,0x26c($sp)
.L0003fa5c:
/*    3fa5c:	8faf026c */ 	lw	$t7,0x26c($sp)
/*    3fa60:	44803000 */ 	mtc1	$zero,$f6
/*    3fa64:	3c01800a */ 	lui	$at,%hi(var8009c5b0)
/*    3fa68:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3fa6c:	00380821 */ 	addu	$at,$at,$t8
/*    3fa70:	e426c5b0 */ 	swc1	$f6,%lo(var8009c5b0)($at)
/*    3fa74:	8fb9026c */ 	lw	$t9,0x26c($sp)
/*    3fa78:	27280001 */ 	addiu	$t0,$t9,0x1
/*    3fa7c:	29010006 */ 	slti	$at,$t0,0x6
/*    3fa80:	1420fff6 */ 	bnez	$at,.L0003fa5c
/*    3fa84:	afa8026c */ 	sw	$t0,0x26c($sp)
/*    3fa88:	24090006 */ 	addiu	$t1,$zero,0x6
/*    3fa8c:	afa9026c */ 	sw	$t1,0x26c($sp)
.L0003fa90:
/*    3fa90:	8faa026c */ 	lw	$t2,0x26c($sp)
/*    3fa94:	3c013f00 */ 	lui	$at,0x3f00
/*    3fa98:	44818000 */ 	mtc1	$at,$f16
/*    3fa9c:	448a4000 */ 	mtc1	$t2,$f8
/*    3faa0:	3c0140c0 */ 	lui	$at,0x40c0
/*    3faa4:	44812000 */ 	mtc1	$at,$f4
/*    3faa8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    3faac:	3c017006 */ 	lui	$at,%hi(var70059c60)
/*    3fab0:	c4289c60 */ 	lwc1	$f8,%lo(var70059c60)($at)
/*    3fab4:	46105480 */ 	add.s	$f18,$f10,$f16
/*    3fab8:	46049181 */ 	sub.s	$f6,$f18,$f4
/*    3fabc:	46083302 */ 	mul.s	$f12,$f6,$f8
/*    3fac0:	0c0068f7 */ 	jal	sinf
/*    3fac4:	00000000 */ 	nop
/*    3fac8:	8fab026c */ 	lw	$t3,0x26c($sp)
/*    3facc:	3c01800a */ 	lui	$at,%hi(var8009c5b0)
/*    3fad0:	000b6080 */ 	sll	$t4,$t3,0x2
/*    3fad4:	002c0821 */ 	addu	$at,$at,$t4
/*    3fad8:	e420c5b0 */ 	swc1	$f0,%lo(var8009c5b0)($at)
/*    3fadc:	8fad026c */ 	lw	$t5,0x26c($sp)
/*    3fae0:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    3fae4:	29c1000c */ 	slti	$at,$t6,0xc
/*    3fae8:	1420ffe9 */ 	bnez	$at,.L0003fa90
/*    3faec:	afae026c */ 	sw	$t6,0x26c($sp)
/*    3faf0:	240f000c */ 	addiu	$t7,$zero,0xc
/*    3faf4:	afaf026c */ 	sw	$t7,0x26c($sp)
.L0003faf8:
/*    3faf8:	8fb8026c */ 	lw	$t8,0x26c($sp)
/*    3fafc:	3c013f80 */ 	lui	$at,0x3f80
/*    3fb00:	44815000 */ 	mtc1	$at,$f10
/*    3fb04:	3c01800a */ 	lui	$at,%hi(var8009c5b0)
/*    3fb08:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3fb0c:	00390821 */ 	addu	$at,$at,$t9
/*    3fb10:	e42ac5b0 */ 	swc1	$f10,%lo(var8009c5b0)($at)
/*    3fb14:	8fa8026c */ 	lw	$t0,0x26c($sp)
/*    3fb18:	25090001 */ 	addiu	$t1,$t0,0x1
/*    3fb1c:	29210012 */ 	slti	$at,$t1,0x12
/*    3fb20:	1420fff5 */ 	bnez	$at,.L0003faf8
/*    3fb24:	afa9026c */ 	sw	$t1,0x26c($sp)
/*    3fb28:	240a0012 */ 	addiu	$t2,$zero,0x12
/*    3fb2c:	afaa026c */ 	sw	$t2,0x26c($sp)
.L0003fb30:
/*    3fb30:	8fab026c */ 	lw	$t3,0x26c($sp)
/*    3fb34:	3c013f00 */ 	lui	$at,0x3f00
/*    3fb38:	44812000 */ 	mtc1	$at,$f4
/*    3fb3c:	448b8000 */ 	mtc1	$t3,$f16
/*    3fb40:	3c017006 */ 	lui	$at,%hi(var70059c64)
/*    3fb44:	c4289c64 */ 	lwc1	$f8,%lo(var70059c64)($at)
/*    3fb48:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    3fb4c:	46049180 */ 	add.s	$f6,$f18,$f4
/*    3fb50:	46083302 */ 	mul.s	$f12,$f6,$f8
/*    3fb54:	0c0068f7 */ 	jal	sinf
/*    3fb58:	00000000 */ 	nop
/*    3fb5c:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    3fb60:	3c01800a */ 	lui	$at,%hi(var8009c5b0)
/*    3fb64:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3fb68:	002d0821 */ 	addu	$at,$at,$t5
/*    3fb6c:	e420c5b0 */ 	swc1	$f0,%lo(var8009c5b0)($at)
/*    3fb70:	8fae026c */ 	lw	$t6,0x26c($sp)
/*    3fb74:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    3fb78:	29e10024 */ 	slti	$at,$t7,0x24
/*    3fb7c:	1420ffec */ 	bnez	$at,.L0003fb30
/*    3fb80:	afaf026c */ 	sw	$t7,0x26c($sp)
/*    3fb84:	3c18800a */ 	lui	$t8,%hi(var8009c640)
/*    3fb88:	8f18c640 */ 	lw	$t8,%lo(var8009c640)($t8)
/*    3fb8c:	17000003 */ 	bnez	$t8,.L0003fb9c
/*    3fb90:	00000000 */ 	nop
/*    3fb94:	1000016e */ 	b	.L00040150
/*    3fb98:	00001025 */ 	or	$v0,$zero,$zero
.L0003fb9c:
/*    3fb9c:	3c04800a */ 	lui	$a0,%hi(var8009c640)
/*    3fba0:	8c84c640 */ 	lw	$a0,%lo(var8009c640)($a0)
/*    3fba4:	0c012c30 */ 	jal	bzero
/*    3fba8:	3405a410 */ 	dli	$a1,0xa410
/*    3fbac:	afa00264 */ 	sw	$zero,0x264($sp)
.L0003fbb0:
/*    3fbb0:	8fb90264 */ 	lw	$t9,0x264($sp)
/*    3fbb4:	3c098006 */ 	lui	$t1,%hi(var8005f670)
/*    3fbb8:	00194080 */ 	sll	$t0,$t9,0x2
/*    3fbbc:	01284821 */ 	addu	$t1,$t1,$t0
/*    3fbc0:	8d29f670 */ 	lw	$t1,%lo(var8005f670)($t1)
/*    3fbc4:	afa90254 */ 	sw	$t1,0x254($sp)
/*    3fbc8:	8faa0254 */ 	lw	$t2,0x254($sp)
/*    3fbcc:	15400008 */ 	bnez	$t2,.L0003fbf0
/*    3fbd0:	00000000 */ 	nop
/*    3fbd4:	8fab0264 */ 	lw	$t3,0x264($sp)
/*    3fbd8:	3c01800a */ 	lui	$at,%hi(var8009c650)
/*    3fbdc:	000b6080 */ 	sll	$t4,$t3,0x2
/*    3fbe0:	002c0821 */ 	addu	$at,$at,$t4
/*    3fbe4:	ac20c650 */ 	sw	$zero,%lo(var8009c650)($at)
/*    3fbe8:	1000010e */ 	b	.L00040024
/*    3fbec:	00000000 */ 	nop
.L0003fbf0:
/*    3fbf0:	8fad0234 */ 	lw	$t5,0x234($sp)
/*    3fbf4:	8fb90264 */ 	lw	$t9,0x264($sp)
/*    3fbf8:	3c0f800a */ 	lui	$t7,%hi(var8009c640)
/*    3fbfc:	8defc640 */ 	lw	$t7,%lo(var8009c640)($t7)
/*    3fc00:	3c01800a */ 	lui	$at,%hi(var8009c650)
/*    3fc04:	000d7080 */ 	sll	$t6,$t5,0x2
/*    3fc08:	00194080 */ 	sll	$t0,$t9,0x2
/*    3fc0c:	00280821 */ 	addu	$at,$at,$t0
/*    3fc10:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    3fc14:	ac38c650 */ 	sw	$t8,%lo(var8009c650)($at)
/*    3fc18:	8fa90264 */ 	lw	$t1,0x264($sp)
/*    3fc1c:	3c0b800a */ 	lui	$t3,%hi(var8009c650)
/*    3fc20:	00095080 */ 	sll	$t2,$t1,0x2
/*    3fc24:	016a5821 */ 	addu	$t3,$t3,$t2
/*    3fc28:	8d6bc650 */ 	lw	$t3,%lo(var8009c650)($t3)
/*    3fc2c:	afab0250 */ 	sw	$t3,0x250($sp)
/*    3fc30:	afa00268 */ 	sw	$zero,0x268($sp)
.L0003fc34:
/*    3fc34:	8fae0268 */ 	lw	$t6,0x268($sp)
/*    3fc38:	8fad0250 */ 	lw	$t5,0x250($sp)
/*    3fc3c:	240cffff */ 	addiu	$t4,$zero,-1
/*    3fc40:	000e7880 */ 	sll	$t7,$t6,0x2
/*    3fc44:	01afc821 */ 	addu	$t9,$t5,$t7
/*    3fc48:	a32c0002 */ 	sb	$t4,0x2($t9)
/*    3fc4c:	8fa90268 */ 	lw	$t1,0x268($sp)
/*    3fc50:	8fa80250 */ 	lw	$t0,0x250($sp)
/*    3fc54:	2418ffff */ 	addiu	$t8,$zero,-1
/*    3fc58:	00095080 */ 	sll	$t2,$t1,0x2
/*    3fc5c:	010a5821 */ 	addu	$t3,$t0,$t2
/*    3fc60:	a1780003 */ 	sb	$t8,0x3($t3)
/*    3fc64:	8fae0268 */ 	lw	$t6,0x268($sp)
/*    3fc68:	25cd0001 */ 	addiu	$t5,$t6,0x1
/*    3fc6c:	29a12904 */ 	slti	$at,$t5,0x2904
/*    3fc70:	1420fff0 */ 	bnez	$at,.L0003fc34
/*    3fc74:	afad0268 */ 	sw	$t5,0x268($sp)
/*    3fc78:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    3fc7c:	afaf0230 */ 	sw	$t7,0x230($sp)
/*    3fc80:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    3fc84:	afac0228 */ 	sw	$t4,0x228($sp)
/*    3fc88:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    3fc8c:	0c012c30 */ 	jal	bzero
/*    3fc90:	24050200 */ 	addiu	$a1,$zero,0x200
/*    3fc94:	24190001 */ 	addiu	$t9,$zero,0x1
/*    3fc98:	afb90260 */ 	sw	$t9,0x260($sp)
/*    3fc9c:	8fa90228 */ 	lw	$t1,0x228($sp)
/*    3fca0:	1120006c */ 	beqz	$t1,.L0003fe54
/*    3fca4:	00000000 */ 	nop
.L0003fca8:
/*    3fca8:	afa00228 */ 	sw	$zero,0x228($sp)
/*    3fcac:	8fa80264 */ 	lw	$t0,0x264($sp)
/*    3fcb0:	3c188006 */ 	lui	$t8,%hi(var8005f670)
/*    3fcb4:	afa0022c */ 	sw	$zero,0x22c($sp)
/*    3fcb8:	00085080 */ 	sll	$t2,$t0,0x2
/*    3fcbc:	030ac021 */ 	addu	$t8,$t8,$t2
/*    3fcc0:	8f18f670 */ 	lw	$t8,%lo(var8005f670)($t8)
/*    3fcc4:	24010064 */ 	addiu	$at,$zero,0x64
/*    3fcc8:	afb80254 */ 	sw	$t8,0x254($sp)
/*    3fccc:	930b0000 */ 	lbu	$t3,0x0($t8)
/*    3fcd0:	1161005a */ 	beq	$t3,$at,.L0003fe3c
/*    3fcd4:	00000000 */ 	nop
.L0003fcd8:
/*    3fcd8:	8fae022c */ 	lw	$t6,0x22c($sp)
/*    3fcdc:	000e6840 */ 	sll	$t5,$t6,0x1
/*    3fce0:	03ad7821 */ 	addu	$t7,$sp,$t5
/*    3fce4:	85ef0028 */ 	lh	$t7,0x28($t7)
/*    3fce8:	afaf025c */ 	sw	$t7,0x25c($sp)
/*    3fcec:	8fb90254 */ 	lw	$t9,0x254($sp)
/*    3fcf0:	8fac0230 */ 	lw	$t4,0x230($sp)
/*    3fcf4:	93290002 */ 	lbu	$t1,0x2($t9)
/*    3fcf8:	012c082a */ 	slt	$at,$t1,$t4
/*    3fcfc:	14200045 */ 	bnez	$at,.L0003fe14
/*    3fd00:	00000000 */ 	nop
/*    3fd04:	8fa80254 */ 	lw	$t0,0x254($sp)
/*    3fd08:	8fb80230 */ 	lw	$t8,0x230($sp)
/*    3fd0c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3fd10:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    3fd14:	270b001f */ 	addiu	$t3,$t8,0x1f
/*    3fd18:	016e6804 */ 	sllv	$t5,$t6,$t3
/*    3fd1c:	014d7824 */ 	and	$t7,$t2,$t5
/*    3fd20:	11e00003 */ 	beqz	$t7,.L0003fd30
/*    3fd24:	00000000 */ 	nop
/*    3fd28:	10000002 */ 	b	.L0003fd34
/*    3fd2c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0003fd30:
/*    3fd30:	00008025 */ 	or	$s0,$zero,$zero
.L0003fd34:
/*    3fd34:	8fac025c */ 	lw	$t4,0x25c($sp)
/*    3fd38:	8fb90250 */ 	lw	$t9,0x250($sp)
/*    3fd3c:	000c4880 */ 	sll	$t1,$t4,0x2
/*    3fd40:	03294021 */ 	addu	$t0,$t9,$t1
/*    3fd44:	0110c021 */ 	addu	$t8,$t0,$s0
/*    3fd48:	afb80258 */ 	sw	$t8,0x258($sp)
/*    3fd4c:	8fae0258 */ 	lw	$t6,0x258($sp)
/*    3fd50:	91cb0000 */ 	lbu	$t3,0x0($t6)
/*    3fd54:	1160000a */ 	beqz	$t3,.L0003fd80
/*    3fd58:	00000000 */ 	nop
/*    3fd5c:	8faf022c */ 	lw	$t7,0x22c($sp)
/*    3fd60:	8faa0258 */ 	lw	$t2,0x258($sp)
/*    3fd64:	000f6040 */ 	sll	$t4,$t7,0x1
/*    3fd68:	03acc821 */ 	addu	$t9,$sp,$t4
/*    3fd6c:	87390028 */ 	lh	$t9,0x28($t9)
/*    3fd70:	914d0000 */ 	lbu	$t5,0x0($t2)
/*    3fd74:	01b94821 */ 	addu	$t1,$t5,$t9
/*    3fd78:	1000000a */ 	b	.L0003fda4
/*    3fd7c:	afa9025c */ 	sw	$t1,0x25c($sp)
.L0003fd80:
/*    3fd80:	8fa80260 */ 	lw	$t0,0x260($sp)
/*    3fd84:	8fb8025c */ 	lw	$t8,0x25c($sp)
/*    3fd88:	8fab0258 */ 	lw	$t3,0x258($sp)
/*    3fd8c:	01187023 */ 	subu	$t6,$t0,$t8
/*    3fd90:	a16e0000 */ 	sb	$t6,0x0($t3)
/*    3fd94:	8faa0260 */ 	lw	$t2,0x260($sp)
/*    3fd98:	254f0001 */ 	addiu	$t7,$t2,0x1
/*    3fd9c:	afaf0260 */ 	sw	$t7,0x260($sp)
/*    3fda0:	afaa025c */ 	sw	$t2,0x25c($sp)
.L0003fda4:
/*    3fda4:	8fac0254 */ 	lw	$t4,0x254($sp)
/*    3fda8:	8fb90230 */ 	lw	$t9,0x230($sp)
/*    3fdac:	918d0002 */ 	lbu	$t5,0x2($t4)
/*    3fdb0:	15b90010 */ 	bne	$t5,$t9,.L0003fdf4
/*    3fdb4:	00000000 */ 	nop
/*    3fdb8:	8fa90254 */ 	lw	$t1,0x254($sp)
/*    3fdbc:	8fae025c */ 	lw	$t6,0x25c($sp)
/*    3fdc0:	8fb80250 */ 	lw	$t8,0x250($sp)
/*    3fdc4:	91280000 */ 	lbu	$t0,0x0($t1)
/*    3fdc8:	000e5880 */ 	sll	$t3,$t6,0x2
/*    3fdcc:	030b5021 */ 	addu	$t2,$t8,$t3
/*    3fdd0:	a1480002 */ 	sb	$t0,0x2($t2)
/*    3fdd4:	8faf0254 */ 	lw	$t7,0x254($sp)
/*    3fdd8:	8fb9025c */ 	lw	$t9,0x25c($sp)
/*    3fddc:	8fad0250 */ 	lw	$t5,0x250($sp)
/*    3fde0:	91ec0001 */ 	lbu	$t4,0x1($t7)
/*    3fde4:	00194880 */ 	sll	$t1,$t9,0x2
/*    3fde8:	01a97021 */ 	addu	$t6,$t5,$t1
/*    3fdec:	10000004 */ 	b	.L0003fe00
/*    3fdf0:	a1cc0003 */ 	sb	$t4,0x3($t6)
.L0003fdf4:
/*    3fdf4:	8fb80228 */ 	lw	$t8,0x228($sp)
/*    3fdf8:	270b0001 */ 	addiu	$t3,$t8,0x1
/*    3fdfc:	afab0228 */ 	sw	$t3,0x228($sp)
.L0003fe00:
/*    3fe00:	8faa022c */ 	lw	$t2,0x22c($sp)
/*    3fe04:	8fa8025c */ 	lw	$t0,0x25c($sp)
/*    3fe08:	000a7840 */ 	sll	$t7,$t2,0x1
/*    3fe0c:	03afc821 */ 	addu	$t9,$sp,$t7
/*    3fe10:	a7280028 */ 	sh	$t0,0x28($t9)
.L0003fe14:
/*    3fe14:	8fad0254 */ 	lw	$t5,0x254($sp)
/*    3fe18:	8fac022c */ 	lw	$t4,0x22c($sp)
/*    3fe1c:	24010064 */ 	addiu	$at,$zero,0x64
/*    3fe20:	25a90008 */ 	addiu	$t1,$t5,0x8
/*    3fe24:	258e0001 */ 	addiu	$t6,$t4,0x1
/*    3fe28:	afae022c */ 	sw	$t6,0x22c($sp)
/*    3fe2c:	afa90254 */ 	sw	$t1,0x254($sp)
/*    3fe30:	91380000 */ 	lbu	$t8,0x0($t1)
/*    3fe34:	1701ffa8 */ 	bne	$t8,$at,.L0003fcd8
/*    3fe38:	00000000 */ 	nop
.L0003fe3c:
/*    3fe3c:	8fab0230 */ 	lw	$t3,0x230($sp)
/*    3fe40:	256a0001 */ 	addiu	$t2,$t3,0x1
/*    3fe44:	afaa0230 */ 	sw	$t2,0x230($sp)
/*    3fe48:	8fa80228 */ 	lw	$t0,0x228($sp)
/*    3fe4c:	1500ff96 */ 	bnez	$t0,.L0003fca8
/*    3fe50:	00000000 */ 	nop
.L0003fe54:
/*    3fe54:	8faf0234 */ 	lw	$t7,0x234($sp)
/*    3fe58:	8fb90260 */ 	lw	$t9,0x260($sp)
/*    3fe5c:	01f96821 */ 	addu	$t5,$t7,$t9
/*    3fe60:	afad0234 */ 	sw	$t5,0x234($sp)
/*    3fe64:	8fac0264 */ 	lw	$t4,0x264($sp)
/*    3fe68:	3c098006 */ 	lui	$t1,%hi(var8005f670)
/*    3fe6c:	24010064 */ 	addiu	$at,$zero,0x64
/*    3fe70:	000c7080 */ 	sll	$t6,$t4,0x2
/*    3fe74:	012e4821 */ 	addu	$t1,$t1,$t6
/*    3fe78:	8d29f670 */ 	lw	$t1,%lo(var8005f670)($t1)
/*    3fe7c:	afa90254 */ 	sw	$t1,0x254($sp)
/*    3fe80:	91380000 */ 	lbu	$t8,0x0($t1)
/*    3fe84:	13010067 */ 	beq	$t8,$at,.L00040024
/*    3fe88:	00000000 */ 	nop
.L0003fe8c:
/*    3fe8c:	8fab0254 */ 	lw	$t3,0x254($sp)
/*    3fe90:	916a0002 */ 	lbu	$t2,0x2($t3)
/*    3fe94:	29410008 */ 	slti	$at,$t2,0x8
/*    3fe98:	10200003 */ 	beqz	$at,.L0003fea8
/*    3fe9c:	00000000 */ 	nop
/*    3fea0:	10000003 */ 	b	.L0003feb0
/*    3fea4:	afaa0244 */ 	sw	$t2,0x244($sp)
.L0003fea8:
/*    3fea8:	24080008 */ 	addiu	$t0,$zero,0x8
/*    3feac:	afa80244 */ 	sw	$t0,0x244($sp)
.L0003feb0:
/*    3feb0:	a3a00243 */ 	sb	$zero,0x243($sp)
/*    3feb4:	8faf0244 */ 	lw	$t7,0x244($sp)
/*    3feb8:	afa0026c */ 	sw	$zero,0x26c($sp)
/*    3febc:	19e00015 */ 	blez	$t7,.L0003ff14
/*    3fec0:	00000000 */ 	nop
.L0003fec4:
/*    3fec4:	8fb90254 */ 	lw	$t9,0x254($sp)
/*    3fec8:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    3fecc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3fed0:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*    3fed4:	018e4804 */ 	sllv	$t1,$t6,$t4
/*    3fed8:	01a9c024 */ 	and	$t8,$t5,$t1
/*    3fedc:	13000007 */ 	beqz	$t8,.L0003fefc
/*    3fee0:	00000000 */ 	nop
/*    3fee4:	8faa026c */ 	lw	$t2,0x26c($sp)
/*    3fee8:	93ab0243 */ 	lbu	$t3,0x243($sp)
/*    3feec:	03aa4021 */ 	addu	$t0,$sp,$t2
/*    3fef0:	91080248 */ 	lbu	$t0,0x248($t0)
/*    3fef4:	01687825 */ 	or	$t7,$t3,$t0
/*    3fef8:	a3af0243 */ 	sb	$t7,0x243($sp)
.L0003fefc:
/*    3fefc:	8fb9026c */ 	lw	$t9,0x26c($sp)
/*    3ff00:	8fac0244 */ 	lw	$t4,0x244($sp)
/*    3ff04:	272e0001 */ 	addiu	$t6,$t9,0x1
/*    3ff08:	01cc082a */ 	slt	$at,$t6,$t4
/*    3ff0c:	1420ffed */ 	bnez	$at,.L0003fec4
/*    3ff10:	afae026c */ 	sw	$t6,0x26c($sp)
.L0003ff14:
/*    3ff14:	8fad0254 */ 	lw	$t5,0x254($sp)
/*    3ff18:	91a90002 */ 	lbu	$t1,0x2($t5)
/*    3ff1c:	29210009 */ 	slti	$at,$t1,0x9
/*    3ff20:	1420000b */ 	bnez	$at,.L0003ff50
/*    3ff24:	00000000 */ 	nop
/*    3ff28:	8fb80264 */ 	lw	$t8,0x264($sp)
/*    3ff2c:	93ab0243 */ 	lbu	$t3,0x243($sp)
/*    3ff30:	3c0f8006 */ 	lui	$t7,%hi(var8005f6fc)
/*    3ff34:	8deff6fc */ 	lw	$t7,%lo(var8005f6fc)($t7)
/*    3ff38:	00185200 */ 	sll	$t2,$t8,0x8
/*    3ff3c:	014b4021 */ 	addu	$t0,$t2,$t3
/*    3ff40:	01e8c821 */ 	addu	$t9,$t7,$t0
/*    3ff44:	a3200000 */ 	sb	$zero,0x0($t9)
/*    3ff48:	1000002f */ 	b	.L00040008
/*    3ff4c:	00000000 */ 	nop
.L0003ff50:
/*    3ff50:	8fae0244 */ 	lw	$t6,0x244($sp)
/*    3ff54:	240c0100 */ 	addiu	$t4,$zero,0x100
/*    3ff58:	01cc6807 */ 	srav	$t5,$t4,$t6
/*    3ff5c:	afad023c */ 	sw	$t5,0x23c($sp)
/*    3ff60:	8fa90254 */ 	lw	$t1,0x254($sp)
/*    3ff64:	91380001 */ 	lbu	$t8,0x1($t1)
/*    3ff68:	912b0000 */ 	lbu	$t3,0x0($t1)
/*    3ff6c:	00185100 */ 	sll	$t2,$t8,0x4
/*    3ff70:	014b7825 */ 	or	$t7,$t2,$t3
/*    3ff74:	afaf0238 */ 	sw	$t7,0x238($sp)
/*    3ff78:	8fa8023c */ 	lw	$t0,0x23c($sp)
/*    3ff7c:	afa0026c */ 	sw	$zero,0x26c($sp)
/*    3ff80:	19000021 */ 	blez	$t0,.L00040008
/*    3ff84:	00000000 */ 	nop
.L0003ff88:
/*    3ff88:	93b90243 */ 	lbu	$t9,0x243($sp)
/*    3ff8c:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    3ff90:	032c7025 */ 	or	$t6,$t9,$t4
/*    3ff94:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3ff98:	93b80243 */ 	lbu	$t8,0x243($sp)
/*    3ff9c:	8fa9026c */ 	lw	$t1,0x26c($sp)
/*    3ffa0:	8fab0264 */ 	lw	$t3,0x264($sp)
/*    3ffa4:	3c198006 */ 	lui	$t9,%hi(var8005f6f8)
/*    3ffa8:	8f39f6f8 */ 	lw	$t9,%lo(var8005f6f8)($t9)
/*    3ffac:	8fad0238 */ 	lw	$t5,0x238($sp)
/*    3ffb0:	03095025 */ 	or	$t2,$t8,$t1
/*    3ffb4:	000b7a00 */ 	sll	$t7,$t3,0x8
/*    3ffb8:	01ea4021 */ 	addu	$t0,$t7,$t2
/*    3ffbc:	03286021 */ 	addu	$t4,$t9,$t0
/*    3ffc0:	a18d0000 */ 	sb	$t5,0x0($t4)
/*    3ffc4:	93b80243 */ 	lbu	$t8,0x243($sp)
/*    3ffc8:	8fa9026c */ 	lw	$t1,0x26c($sp)
/*    3ffcc:	8faf0264 */ 	lw	$t7,0x264($sp)
/*    3ffd0:	3c088006 */ 	lui	$t0,%hi(var8005f6fc)
/*    3ffd4:	8d08f6fc */ 	lw	$t0,%lo(var8005f6fc)($t0)
/*    3ffd8:	8fae0244 */ 	lw	$t6,0x244($sp)
/*    3ffdc:	03095825 */ 	or	$t3,$t8,$t1
/*    3ffe0:	000f5200 */ 	sll	$t2,$t7,0x8
/*    3ffe4:	014bc821 */ 	addu	$t9,$t2,$t3
/*    3ffe8:	01196821 */ 	addu	$t5,$t0,$t9
/*    3ffec:	a1ae0000 */ 	sb	$t6,0x0($t5)
/*    3fff0:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    3fff4:	8fa9023c */ 	lw	$t1,0x23c($sp)
/*    3fff8:	25980001 */ 	addiu	$t8,$t4,0x1
/*    3fffc:	0309082a */ 	slt	$at,$t8,$t1
/*    40000:	1420ffe1 */ 	bnez	$at,.L0003ff88
/*    40004:	afb8026c */ 	sw	$t8,0x26c($sp)
.L00040008:
/*    40008:	8faf0254 */ 	lw	$t7,0x254($sp)
/*    4000c:	24010064 */ 	addiu	$at,$zero,0x64
/*    40010:	25ea0008 */ 	addiu	$t2,$t7,0x8
/*    40014:	afaa0254 */ 	sw	$t2,0x254($sp)
/*    40018:	914b0000 */ 	lbu	$t3,0x0($t2)
/*    4001c:	1561ff9b */ 	bne	$t3,$at,.L0003fe8c
/*    40020:	00000000 */ 	nop
.L00040024:
/*    40024:	8fa80264 */ 	lw	$t0,0x264($sp)
/*    40028:	25190001 */ 	addiu	$t9,$t0,0x1
/*    4002c:	2b210022 */ 	slti	$at,$t9,0x22
/*    40030:	1420fedf */ 	bnez	$at,.L0003fbb0
/*    40034:	afb90264 */ 	sw	$t9,0x264($sp)
/*    40038:	3c0e800a */ 	lui	$t6,%hi(var8009c644)
/*    4003c:	8dcec644 */ 	lw	$t6,%lo(var8009c644)($t6)
/*    40040:	3c01800a */ 	lui	$at,%hi(var8009c648)
/*    40044:	ac2ec648 */ 	sw	$t6,%lo(var8009c648)($at)
/*    40048:	3c0d800a */ 	lui	$t5,%hi(var8009c648)
/*    4004c:	8dadc648 */ 	lw	$t5,%lo(var8009c648)($t5)
/*    40050:	15a00003 */ 	bnez	$t5,.L00040060
/*    40054:	00000000 */ 	nop
/*    40058:	1000003d */ 	b	.L00040150
/*    4005c:	00001025 */ 	or	$v0,$zero,$zero
.L00040060:
/*    40060:	afa0026c */ 	sw	$zero,0x26c($sp)
.L00040064:
/*    40064:	8fac026c */ 	lw	$t4,0x26c($sp)
/*    40068:	3c017006 */ 	lui	$at,%hi(var70059c68)
/*    4006c:	c42e9c68 */ 	lwc1	$f14,%lo(var70059c68)($at)
/*    40070:	448c5000 */ 	mtc1	$t4,$f10
/*    40074:	0c0117b4 */ 	jal	func00045ed0
/*    40078:	46805320 */ 	cvt.s.w	$f12,$f10
/*    4007c:	8fa9026c */ 	lw	$t1,0x26c($sp)
/*    40080:	3c18800a */ 	lui	$t8,%hi(var8009c648)
/*    40084:	8f18c648 */ 	lw	$t8,%lo(var8009c648)($t8)
/*    40088:	00097880 */ 	sll	$t7,$t1,0x2
/*    4008c:	030f5021 */ 	addu	$t2,$t8,$t7
/*    40090:	e5400000 */ 	swc1	$f0,0x0($t2)
/*    40094:	8fab026c */ 	lw	$t3,0x26c($sp)
/*    40098:	25680001 */ 	addiu	$t0,$t3,0x1
/*    4009c:	29012000 */ 	slti	$at,$t0,0x2000
/*    400a0:	1420fff0 */ 	bnez	$at,.L00040064
/*    400a4:	afa8026c */ 	sw	$t0,0x26c($sp)
/*    400a8:	afa0026c */ 	sw	$zero,0x26c($sp)
.L000400ac:
/*    400ac:	8fb9026c */ 	lw	$t9,0x26c($sp)
/*    400b0:	3c014000 */ 	lui	$at,0x4000
/*    400b4:	44816000 */ 	mtc1	$at,$f12
/*    400b8:	44998000 */ 	mtc1	$t9,$f16
/*    400bc:	3c01bf00 */ 	lui	$at,0xbf00
/*    400c0:	44812000 */ 	mtc1	$at,$f4
/*    400c4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    400c8:	46049382 */ 	mul.s	$f14,$f18,$f4
/*    400cc:	0c0117b4 */ 	jal	func00045ed0
/*    400d0:	00000000 */ 	nop
/*    400d4:	8fad026c */ 	lw	$t5,0x26c($sp)
/*    400d8:	3c0e800a */ 	lui	$t6,%hi(var8009c6d8)
/*    400dc:	8dcec6d8 */ 	lw	$t6,%lo(var8009c6d8)($t6)
/*    400e0:	000d6080 */ 	sll	$t4,$t5,0x2
/*    400e4:	01cc4821 */ 	addu	$t1,$t6,$t4
/*    400e8:	e5200000 */ 	swc1	$f0,0x0($t1)
/*    400ec:	8fb8026c */ 	lw	$t8,0x26c($sp)
/*    400f0:	3c014000 */ 	lui	$at,0x4000
/*    400f4:	44816000 */ 	mtc1	$at,$f12
/*    400f8:	44983000 */ 	mtc1	$t8,$f6
/*    400fc:	3c01c000 */ 	lui	$at,0xc000
/*    40100:	44815000 */ 	mtc1	$at,$f10
/*    40104:	46803220 */ 	cvt.s.w	$f8,$f6
/*    40108:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*    4010c:	0c0117b4 */ 	jal	func00045ed0
/*    40110:	00000000 */ 	nop
/*    40114:	8faa026c */ 	lw	$t2,0x26c($sp)
/*    40118:	3c0f800a */ 	lui	$t7,%hi(var8009c6dc)
/*    4011c:	8defc6dc */ 	lw	$t7,%lo(var8009c6dc)($t7)
/*    40120:	000a5880 */ 	sll	$t3,$t2,0x2
/*    40124:	01eb4021 */ 	addu	$t0,$t7,$t3
/*    40128:	e5000000 */ 	swc1	$f0,0x0($t0)
/*    4012c:	8fb9026c */ 	lw	$t9,0x26c($sp)
/*    40130:	272d0001 */ 	addiu	$t5,$t9,0x1
/*    40134:	29a10100 */ 	slti	$at,$t5,0x100
/*    40138:	1420ffdc */ 	bnez	$at,.L000400ac
/*    4013c:	afad026c */ 	sw	$t5,0x26c($sp)
/*    40140:	10000003 */ 	b	.L00040150
/*    40144:	24020001 */ 	addiu	$v0,$zero,0x1
/*    40148:	10000001 */ 	b	.L00040150
/*    4014c:	00000000 */ 	nop
.L00040150:
/*    40150:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    40154:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    40158:	27bd0270 */ 	addiu	$sp,$sp,0x270
/*    4015c:	03e00008 */ 	jr	$ra
/*    40160:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00040164
/*    40164:	27bdfe40 */ 	addiu	$sp,$sp,-448
/*    40168:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4016c:	afa401c0 */ 	sw	$a0,0x1c0($sp)
/*    40170:	afa501c4 */ 	sw	$a1,0x1c4($sp)
/*    40174:	afa601c8 */ 	sw	$a2,0x1c8($sp)
/*    40178:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4017c:	3c0f7006 */ 	lui	$t7,%hi(var70059adc)
/*    40180:	25ef9adc */ 	addiu	$t7,$t7,%lo(var70059adc)
/*    40184:	25e80054 */ 	addiu	$t0,$t7,0x54
/*    40188:	27ae0158 */ 	addiu	$t6,$sp,0x158
.L0004018c:
/*    4018c:	8df90000 */ 	lw	$t9,0x0($t7)
/*    40190:	25ef000c */ 	addiu	$t7,$t7,0xc
/*    40194:	25ce000c */ 	addiu	$t6,$t6,0xc
/*    40198:	add9fff4 */ 	sw	$t9,-0xc($t6)
/*    4019c:	8df8fff8 */ 	lw	$t8,-0x8($t7)
/*    401a0:	add8fff8 */ 	sw	$t8,-0x8($t6)
/*    401a4:	8df9fffc */ 	lw	$t9,-0x4($t7)
/*    401a8:	15e8fff8 */ 	bne	$t7,$t0,.L0004018c
/*    401ac:	add9fffc */ 	sw	$t9,-0x4($t6)
/*    401b0:	8df90000 */ 	lw	$t9,0x0($t7)
/*    401b4:	add90000 */ 	sw	$t9,0x0($t6)
/*    401b8:	8fa901c0 */ 	lw	$t1,0x1c0($sp)
/*    401bc:	8d2b3ba4 */ 	lw	$t3,0x3ba4($t1)
/*    401c0:	8d2a3bb4 */ 	lw	$t2,0x3bb4($t1)
/*    401c4:	000b6080 */ 	sll	$t4,$t3,0x2
/*    401c8:	018b6023 */ 	subu	$t4,$t4,$t3
/*    401cc:	014c6821 */ 	addu	$t5,$t2,$t4
/*    401d0:	afad01bc */ 	sw	$t5,0x1bc($sp)
/*    401d4:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*    401d8:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*    401dc:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*    401e0:	000f7080 */ 	sll	$t6,$t7,0x2
/*    401e4:	010ec021 */ 	addu	$t8,$t0,$t6
/*    401e8:	00194880 */ 	sll	$t1,$t9,0x2
/*    401ec:	03095821 */ 	addu	$t3,$t8,$t1
/*    401f0:	8d6a3c98 */ 	lw	$t2,0x3c98($t3)
/*    401f4:	11400033 */ 	beqz	$t2,.L000402c4
/*    401f8:	00000000 */ 	nop
/*    401fc:	8d6c3ca0 */ 	lw	$t4,0x3ca0($t3)
/*    40200:	24010002 */ 	addiu	$at,$zero,0x2
/*    40204:	1581002f */ 	bne	$t4,$at,.L000402c4
/*    40208:	00000000 */ 	nop
/*    4020c:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*    40210:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*    40214:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*    40218:	000f4080 */ 	sll	$t0,$t7,0x2
/*    4021c:	01a87021 */ 	addu	$t6,$t5,$t0
/*    40220:	0019c080 */ 	sll	$t8,$t9,0x2
/*    40224:	01d84821 */ 	addu	$t1,$t6,$t8
/*    40228:	8d2a3ca8 */ 	lw	$t2,0x3ca8($t1)
/*    4022c:	1140000c */ 	beqz	$t2,.L00040260
/*    40230:	00000000 */ 	nop
/*    40234:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*    40238:	3c0f7005 */ 	lui	$t7,%hi(var700579b8+0x2)
/*    4023c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    40240:	018b6021 */ 	addu	$t4,$t4,$t3
/*    40244:	000c6080 */ 	sll	$t4,$t4,0x2
/*    40248:	018b6021 */ 	addu	$t4,$t4,$t3
/*    4024c:	000c6040 */ 	sll	$t4,$t4,0x1
/*    40250:	01ec7821 */ 	addu	$t7,$t7,$t4
/*    40254:	85ef79ba */ 	lh	$t7,%lo(var700579b8+0x2)($t7)
/*    40258:	10000018 */ 	b	.L000402bc
/*    4025c:	afaf01b8 */ 	sw	$t7,0x1b8($sp)
.L00040260:
/*    40260:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*    40264:	3c197005 */ 	lui	$t9,%hi(var700579e8)
/*    40268:	000d40c0 */ 	sll	$t0,$t5,0x3
/*    4026c:	010d4021 */ 	addu	$t0,$t0,$t5
/*    40270:	00084080 */ 	sll	$t0,$t0,0x2
/*    40274:	010d4021 */ 	addu	$t0,$t0,$t5
/*    40278:	00084040 */ 	sll	$t0,$t0,0x1
/*    4027c:	0328c821 */ 	addu	$t9,$t9,$t0
/*    40280:	873979e8 */ 	lh	$t9,%lo(var700579e8)($t9)
/*    40284:	00197080 */ 	sll	$t6,$t9,0x2
/*    40288:	01d97023 */ 	subu	$t6,$t6,$t9
/*    4028c:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*    40290:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*    40294:	3c0a7005 */ 	lui	$t2,%hi(var700579e8)
/*    40298:	001848c0 */ 	sll	$t1,$t8,0x3
/*    4029c:	01384821 */ 	addu	$t1,$t1,$t8
/*    402a0:	00094880 */ 	sll	$t1,$t1,0x2
/*    402a4:	01384821 */ 	addu	$t1,$t1,$t8
/*    402a8:	00094840 */ 	sll	$t1,$t1,0x1
/*    402ac:	01495021 */ 	addu	$t2,$t2,$t1
/*    402b0:	854a79e8 */ 	lh	$t2,%lo(var700579e8)($t2)
/*    402b4:	afaa01b0 */ 	sw	$t2,0x1b0($sp)
/*    402b8:	afa001b4 */ 	sw	$zero,0x1b4($sp)
.L000402bc:
/*    402bc:	1000000b */ 	b	.L000402ec
/*    402c0:	00000000 */ 	nop
.L000402c4:
/*    402c4:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*    402c8:	3c0f7005 */ 	lui	$t7,%hi(var700579b8+0x2)
/*    402cc:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    402d0:	018b6021 */ 	addu	$t4,$t4,$t3
/*    402d4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    402d8:	018b6021 */ 	addu	$t4,$t4,$t3
/*    402dc:	000c6040 */ 	sll	$t4,$t4,0x1
/*    402e0:	01ec7821 */ 	addu	$t7,$t7,$t4
/*    402e4:	85ef79ba */ 	lh	$t7,%lo(var700579b8+0x2)($t7)
/*    402e8:	afaf01b8 */ 	sw	$t7,0x1b8($sp)
.L000402ec:
/*    402ec:	8fa801c4 */ 	lw	$t0,0x1c4($sp)
/*    402f0:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*    402f4:	8fb801c8 */ 	lw	$t8,0x1c8($sp)
/*    402f8:	0008c880 */ 	sll	$t9,$t0,0x2
/*    402fc:	01b97021 */ 	addu	$t6,$t5,$t9
/*    40300:	00184880 */ 	sll	$t1,$t8,0x2
/*    40304:	01c95021 */ 	addu	$t2,$t6,$t1
/*    40308:	8d4b3c88 */ 	lw	$t3,0x3c88($t2)
/*    4030c:	3c014000 */ 	lui	$at,0x4000
/*    40310:	44816000 */ 	mtc1	$at,$f12
/*    40314:	448b2000 */ 	mtc1	$t3,$f4
/*    40318:	3c014352 */ 	lui	$at,0x4352
/*    4031c:	44814000 */ 	mtc1	$at,$f8
/*    40320:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    40324:	3c013e80 */ 	lui	$at,0x3e80
/*    40328:	44818000 */ 	mtc1	$at,$f16
/*    4032c:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    40330:	46105382 */ 	mul.s	$f14,$f10,$f16
/*    40334:	0c0117b4 */ 	jal	func00045ed0
/*    40338:	00000000 */ 	nop
/*    4033c:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*    40340:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*    40344:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*    40348:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*    4034c:	000f4080 */ 	sll	$t0,$t7,0x2
/*    40350:	01886821 */ 	addu	$t5,$t4,$t0
/*    40354:	0019c080 */ 	sll	$t8,$t9,0x2
/*    40358:	01b87021 */ 	addu	$t6,$t5,$t8
/*    4035c:	8dc93cf8 */ 	lw	$t1,0x3cf8($t6)
/*    40360:	afa90054 */ 	sw	$t1,0x54($sp)
/*    40364:	afa0005c */ 	sw	$zero,0x5c($sp)
.L00040368:
/*    40368:	8fab01c4 */ 	lw	$t3,0x1c4($sp)
/*    4036c:	8faa01c0 */ 	lw	$t2,0x1c0($sp)
/*    40370:	8fa801c8 */ 	lw	$t0,0x1c8($sp)
/*    40374:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    40378:	000b7880 */ 	sll	$t7,$t3,0x2
/*    4037c:	014f6021 */ 	addu	$t4,$t2,$t7
/*    40380:	0008c880 */ 	sll	$t9,$t0,0x2
/*    40384:	000e4880 */ 	sll	$t1,$t6,0x2
/*    40388:	03a97821 */ 	addu	$t7,$sp,$t1
/*    4038c:	01996821 */ 	addu	$t5,$t4,$t9
/*    40390:	8db83cf0 */ 	lw	$t8,0x3cf0($t5)
/*    40394:	8def0158 */ 	lw	$t7,0x158($t7)
/*    40398:	000bc940 */ 	sll	$t9,$t3,0x5
/*    4039c:	032bc823 */ 	subu	$t9,$t9,$t3
/*    403a0:	01f80019 */ 	multu	$t7,$t8
/*    403a4:	00087140 */ 	sll	$t6,$t0,0x5
/*    403a8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    403ac:	01c87023 */ 	subu	$t6,$t6,$t0
/*    403b0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    403b4:	01596821 */ 	addu	$t5,$t2,$t9
/*    403b8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    403bc:	01e9c021 */ 	addu	$t8,$t7,$t1
/*    403c0:	8f0b3d08 */ 	lw	$t3,0x3d08($t8)
/*    403c4:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    403c8:	00006012 */ 	mflo	$t4
/*    403cc:	018b5021 */ 	addu	$t2,$t4,$t3
/*    403d0:	27280001 */ 	addiu	$t0,$t9,0x1
/*    403d4:	01480019 */ 	multu	$t2,$t0
/*    403d8:	00006812 */ 	mflo	$t5
/*    403dc:	afad004c */ 	sw	$t5,0x4c($sp)
/*    403e0:	00000000 */ 	nop
/*    403e4:	8faf004c */ 	lw	$t7,0x4c($sp)
/*    403e8:	3c0e800a */ 	lui	$t6,%hi(var8009c6d8)
/*    403ec:	8dcec6d8 */ 	lw	$t6,%lo(var8009c6d8)($t6)
/*    403f0:	000f4880 */ 	sll	$t1,$t7,0x2
/*    403f4:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*    403f8:	01c9c021 */ 	addu	$t8,$t6,$t1
/*    403fc:	c7120000 */ 	lwc1	$f18,0x0($t8)
/*    40400:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    40404:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    40408:	000c5880 */ 	sll	$t3,$t4,0x2
/*    4040c:	03abc821 */ 	addu	$t9,$sp,$t3
/*    40410:	e7260100 */ 	swc1	$f6,0x100($t9)
/*    40414:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    40418:	25480001 */ 	addiu	$t0,$t2,0x1
/*    4041c:	29010016 */ 	slti	$at,$t0,0x16
/*    40420:	1420ffd1 */ 	bnez	$at,.L00040368
/*    40424:	afa8005c */ 	sw	$t0,0x5c($sp)
/*    40428:	afa00058 */ 	sw	$zero,0x58($sp)
.L0004042c:
/*    4042c:	afa0005c */ 	sw	$zero,0x5c($sp)
.L00040430:
/*    40430:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*    40434:	8fb801c8 */ 	lw	$t8,0x1c8($sp)
/*    40438:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*    4043c:	000f7080 */ 	sll	$t6,$t7,0x2
/*    40440:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    40444:	01cf7023 */ 	subu	$t6,$t6,$t7
/*    40448:	00186080 */ 	sll	$t4,$t8,0x2
/*    4044c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40450:	01986023 */ 	subu	$t4,$t4,$t8
/*    40454:	000c6080 */ 	sll	$t4,$t4,0x2
/*    40458:	01ae4821 */ 	addu	$t1,$t5,$t6
/*    4045c:	012c5821 */ 	addu	$t3,$t1,$t4
/*    40460:	00195080 */ 	sll	$t2,$t9,0x2
/*    40464:	016a4021 */ 	addu	$t0,$t3,$t2
/*    40468:	8d0f3cc8 */ 	lw	$t7,0x3cc8($t0)
/*    4046c:	afaf0050 */ 	sw	$t7,0x50($sp)
/*    40470:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*    40474:	8faa0058 */ 	lw	$t2,0x58($sp)
/*    40478:	8fac01c8 */ 	lw	$t4,0x1c8($sp)
/*    4047c:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*    40480:	000ec140 */ 	sll	$t8,$t6,0x5
/*    40484:	030ec023 */ 	subu	$t8,$t8,$t6
/*    40488:	000a4080 */ 	sll	$t0,$t2,0x2
/*    4048c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    40490:	010a4023 */ 	subu	$t0,$t0,$t2
/*    40494:	000cc940 */ 	sll	$t9,$t4,0x5
/*    40498:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    4049c:	00084080 */ 	sll	$t0,$t0,0x2
/*    404a0:	032cc823 */ 	subu	$t9,$t9,$t4
/*    404a4:	01b84821 */ 	addu	$t1,$t5,$t8
/*    404a8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    404ac:	010a4021 */ 	addu	$t0,$t0,$t2
/*    404b0:	00084080 */ 	sll	$t0,$t0,0x2
/*    404b4:	01395821 */ 	addu	$t3,$t1,$t9
/*    404b8:	01687821 */ 	addu	$t7,$t3,$t0
/*    404bc:	000e6880 */ 	sll	$t5,$t6,0x2
/*    404c0:	8fa90054 */ 	lw	$t1,0x54($sp)
/*    404c4:	01edc021 */ 	addu	$t8,$t7,$t5
/*    404c8:	8f0c3d64 */ 	lw	$t4,0x3d64($t8)
/*    404cc:	25390001 */ 	addiu	$t9,$t1,0x1
/*    404d0:	01990019 */ 	multu	$t4,$t9
/*    404d4:	00005012 */ 	mflo	$t2
/*    404d8:	afaa004c */ 	sw	$t2,0x4c($sp)
/*    404dc:	00000000 */ 	nop
/*    404e0:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    404e4:	3c0d800a */ 	lui	$t5,%hi(var8009c6dc)
/*    404e8:	8dadc6dc */ 	lw	$t5,%lo(var8009c6dc)($t5)
/*    404ec:	00184880 */ 	sll	$t1,$t8,0x2
/*    404f0:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*    404f4:	01a96021 */ 	addu	$t4,$t5,$t1
/*    404f8:	c58a0000 */ 	lwc1	$f10,0x0($t4)
/*    404fc:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*    40500:	3c0b800a */ 	lui	$t3,%hi(var8009c6d8)
/*    40504:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*    40508:	8d6bc6d8 */ 	lw	$t3,%lo(var8009c6d8)($t3)
/*    4050c:	00087080 */ 	sll	$t6,$t0,0x2
/*    40510:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    40514:	016e7821 */ 	addu	$t7,$t3,$t6
/*    40518:	c5e80000 */ 	lwc1	$f8,0x0($t7)
/*    4051c:	00195080 */ 	sll	$t2,$t9,0x2
/*    40520:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    40524:	46124102 */ 	mul.s	$f4,$f8,$f18
/*    40528:	01595023 */ 	subu	$t2,$t2,$t9
/*    4052c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    40530:	01595021 */ 	addu	$t2,$t2,$t9
/*    40534:	000a5080 */ 	sll	$t2,$t2,0x2
/*    40538:	00085880 */ 	sll	$t3,$t0,0x2
/*    4053c:	014b7021 */ 	addu	$t6,$t2,$t3
/*    40540:	03ae7821 */ 	addu	$t7,$sp,$t6
/*    40544:	e5e40064 */ 	swc1	$f4,0x64($t7)
/*    40548:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    4054c:	270d0001 */ 	addiu	$t5,$t8,0x1
/*    40550:	29a1000d */ 	slti	$at,$t5,0xd
/*    40554:	1420ffb6 */ 	bnez	$at,.L00040430
/*    40558:	afad005c */ 	sw	$t5,0x5c($sp)
/*    4055c:	8fa90058 */ 	lw	$t1,0x58($sp)
/*    40560:	252c0001 */ 	addiu	$t4,$t1,0x1
/*    40564:	29810003 */ 	slti	$at,$t4,0x3
/*    40568:	1420ffb0 */ 	bnez	$at,.L0004042c
/*    4056c:	afac0058 */ 	sw	$t4,0x58($sp)
/*    40570:	afa0005c */ 	sw	$zero,0x5c($sp)
/*    40574:	afa00048 */ 	sw	$zero,0x48($sp)
/*    40578:	8fa801c8 */ 	lw	$t0,0x1c8($sp)
/*    4057c:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*    40580:	00085080 */ 	sll	$t2,$t0,0x2
/*    40584:	032a5821 */ 	addu	$t3,$t9,$t2
/*    40588:	8d6e465c */ 	lw	$t6,0x465c($t3)
/*    4058c:	afae0044 */ 	sw	$t6,0x44($sp)
/*    40590:	8fb801c8 */ 	lw	$t8,0x1c8($sp)
/*    40594:	8faf01c0 */ 	lw	$t7,0x1c0($sp)
/*    40598:	001868c0 */ 	sll	$t5,$t8,0x3
/*    4059c:	01b86821 */ 	addu	$t5,$t5,$t8
/*    405a0:	000d6a00 */ 	sll	$t5,$t5,0x8
/*    405a4:	01ed4821 */ 	addu	$t1,$t7,$t5
/*    405a8:	252c4664 */ 	addiu	$t4,$t1,0x4664
/*    405ac:	afac0040 */ 	sw	$t4,0x40($sp)
/*    405b0:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*    405b4:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*    405b8:	001950c0 */ 	sll	$t2,$t9,0x3
/*    405bc:	01595021 */ 	addu	$t2,$t2,$t9
/*    405c0:	000a5140 */ 	sll	$t2,$t2,0x5
/*    405c4:	01595021 */ 	addu	$t2,$t2,$t9
/*    405c8:	000a5080 */ 	sll	$t2,$t2,0x2
/*    405cc:	010a5821 */ 	addu	$t3,$t0,$t2
/*    405d0:	256e3f94 */ 	addiu	$t6,$t3,0x3f94
/*    405d4:	afae003c */ 	sw	$t6,0x3c($sp)
/*    405d8:	8faf01c8 */ 	lw	$t7,0x1c8($sp)
/*    405dc:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*    405e0:	000f68c0 */ 	sll	$t5,$t7,0x3
/*    405e4:	01af6821 */ 	addu	$t5,$t5,$t7
/*    405e8:	000d6940 */ 	sll	$t5,$t5,0x5
/*    405ec:	01af6821 */ 	addu	$t5,$t5,$t7
/*    405f0:	000d6840 */ 	sll	$t5,$t5,0x1
/*    405f4:	030d4821 */ 	addu	$t1,$t8,$t5
/*    405f8:	252c4418 */ 	addiu	$t4,$t1,0x4418
/*    405fc:	afac0038 */ 	sw	$t4,0x38($sp)
/*    40600:	8fa801c4 */ 	lw	$t0,0x1c4($sp)
/*    40604:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*    40608:	8fae01c8 */ 	lw	$t6,0x1c8($sp)
/*    4060c:	00085080 */ 	sll	$t2,$t0,0x2
/*    40610:	032a5821 */ 	addu	$t3,$t9,$t2
/*    40614:	000e7880 */ 	sll	$t7,$t6,0x2
/*    40618:	016fc021 */ 	addu	$t8,$t3,$t7
/*    4061c:	8f103ca0 */ 	lw	$s0,0x3ca0($t8)
/*    40620:	3a100002 */ 	xori	$s0,$s0,0x2
/*    40624:	2e100001 */ 	sltiu	$s0,$s0,0x1
/*    40628:	12000003 */ 	beqz	$s0,.L00040638
/*    4062c:	00000000 */ 	nop
/*    40630:	8f103ca8 */ 	lw	$s0,0x3ca8($t8)
/*    40634:	2e100001 */ 	sltiu	$s0,$s0,0x1
.L00040638:
/*    40638:	afb00034 */ 	sw	$s0,0x34($sp)
/*    4063c:	8fa901c4 */ 	lw	$t1,0x1c4($sp)
/*    40640:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*    40644:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*    40648:	00096080 */ 	sll	$t4,$t1,0x2
/*    4064c:	01ac4021 */ 	addu	$t0,$t5,$t4
/*    40650:	00195080 */ 	sll	$t2,$t9,0x2
/*    40654:	010a7021 */ 	addu	$t6,$t0,$t2
/*    40658:	8dd03ca0 */ 	lw	$s0,0x3ca0($t6)
/*    4065c:	3a100002 */ 	xori	$s0,$s0,0x2
/*    40660:	2e100001 */ 	sltiu	$s0,$s0,0x1
/*    40664:	12000003 */ 	beqz	$s0,.L00040674
/*    40668:	00000000 */ 	nop
/*    4066c:	8dd03ca8 */ 	lw	$s0,0x3ca8($t6)
/*    40670:	0010802b */ 	sltu	$s0,$zero,$s0
.L00040674:
/*    40674:	afb00030 */ 	sw	$s0,0x30($sp)
/*    40678:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*    4067c:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*    40680:	8fad01c8 */ 	lw	$t5,0x1c8($sp)
/*    40684:	000fc080 */ 	sll	$t8,$t7,0x2
/*    40688:	01784821 */ 	addu	$t1,$t3,$t8
/*    4068c:	000d6080 */ 	sll	$t4,$t5,0x2
/*    40690:	012cc821 */ 	addu	$t9,$t1,$t4
/*    40694:	8f283c98 */ 	lw	$t0,0x3c98($t9)
/*    40698:	afa8002c */ 	sw	$t0,0x2c($sp)
/*    4069c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*    406a0:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    406a4:	014e082a */ 	slt	$at,$t2,$t6
/*    406a8:	102001a9 */ 	beqz	$at,.L00040d50
/*    406ac:	00000000 */ 	nop
.L000406b0:
/*    406b0:	8faf01b8 */ 	lw	$t7,0x1b8($sp)
/*    406b4:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    406b8:	016f082a */ 	slt	$at,$t3,$t7
/*    406bc:	10200003 */ 	beqz	$at,.L000406cc
/*    406c0:	00000000 */ 	nop
/*    406c4:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    406c8:	afb801b8 */ 	sw	$t8,0x1b8($sp)
.L000406cc:
/*    406cc:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    406d0:	11a0001f */ 	beqz	$t5,.L00040750
/*    406d4:	00000000 */ 	nop
/*    406d8:	8fa90034 */ 	lw	$t1,0x34($sp)
/*    406dc:	15200008 */ 	bnez	$t1,.L00040700
/*    406e0:	00000000 */ 	nop
/*    406e4:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    406e8:	11800019 */ 	beqz	$t4,.L00040750
/*    406ec:	00000000 */ 	nop
/*    406f0:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    406f4:	2b210024 */ 	slti	$at,$t9,0x24
/*    406f8:	14200015 */ 	bnez	$at,.L00040750
/*    406fc:	00000000 */ 	nop
.L00040700:
/*    40700:	8fa80048 */ 	lw	$t0,0x48($sp)
/*    40704:	8faa01b4 */ 	lw	$t2,0x1b4($sp)
/*    40708:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*    4070c:	010a7023 */ 	subu	$t6,$t0,$t2
/*    40710:	01cf001a */ 	div	$zero,$t6,$t7
/*    40714:	00005812 */ 	mflo	$t3
/*    40718:	afab0058 */ 	sw	$t3,0x58($sp)
/*    4071c:	15e00002 */ 	bnez	$t7,.L00040728
/*    40720:	00000000 */ 	nop
/*    40724:	0007000d */ 	break	0x7
.L00040728:
/*    40728:	2401ffff */ 	addiu	$at,$zero,-1
/*    4072c:	15e10004 */ 	bne	$t7,$at,.L00040740
/*    40730:	3c018000 */ 	lui	$at,0x8000
/*    40734:	15c10002 */ 	bne	$t6,$at,.L00040740
/*    40738:	00000000 */ 	nop
/*    4073c:	0006000d */ 	break	0x6
.L00040740:
/*    40740:	8fb801b4 */ 	lw	$t8,0x1b4($sp)
/*    40744:	8fad01b0 */ 	lw	$t5,0x1b0($sp)
/*    40748:	030d4821 */ 	addu	$t1,$t8,$t5
/*    4074c:	afa90028 */ 	sw	$t1,0x28($sp)
.L00040750:
/*    40750:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    40754:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*    40758:	0199082a */ 	slt	$at,$t4,$t9
/*    4075c:	1020008f */ 	beqz	$at,.L0004099c
/*    40760:	00000000 */ 	nop
.L00040764:
/*    40764:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    40768:	11000054 */ 	beqz	$t0,.L000408bc
/*    4076c:	00000000 */ 	nop
/*    40770:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    40774:	15400008 */ 	bnez	$t2,.L00040798
/*    40778:	00000000 */ 	nop
/*    4077c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    40780:	11c0004e */ 	beqz	$t6,.L000408bc
/*    40784:	00000000 */ 	nop
/*    40788:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    4078c:	29e10024 */ 	slti	$at,$t7,0x24
/*    40790:	1420004a */ 	bnez	$at,.L000408bc
/*    40794:	00000000 */ 	nop
.L00040798:
/*    40798:	8fab0048 */ 	lw	$t3,0x48($sp)
/*    4079c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    407a0:	0178082a */ 	slt	$at,$t3,$t8
/*    407a4:	14200008 */ 	bnez	$at,.L000407c8
/*    407a8:	00000000 */ 	nop
/*    407ac:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    407b0:	8fa901b0 */ 	lw	$t1,0x1b0($sp)
/*    407b4:	01a96021 */ 	addu	$t4,$t5,$t1
/*    407b8:	afac0028 */ 	sw	$t4,0x28($sp)
/*    407bc:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    407c0:	27280001 */ 	addiu	$t0,$t9,0x1
/*    407c4:	afa80058 */ 	sw	$t0,0x58($sp)
.L000407c8:
/*    407c8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*    407cc:	27af0064 */ 	addiu	$t7,$sp,0x64
/*    407d0:	000a7080 */ 	sll	$t6,$t2,0x2
/*    407d4:	01ca7023 */ 	subu	$t6,$t6,$t2
/*    407d8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    407dc:	01ca7021 */ 	addu	$t6,$t6,$t2
/*    407e0:	000e7080 */ 	sll	$t6,$t6,0x2
/*    407e4:	01cf5821 */ 	addu	$t3,$t6,$t7
/*    407e8:	afab0024 */ 	sw	$t3,0x24($sp)
/*    407ec:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    407f0:	93100000 */ 	lbu	$s0,0x0($t8)
/*    407f4:	270d0001 */ 	addiu	$t5,$t8,0x1
/*    407f8:	afad0038 */ 	sw	$t5,0x38($sp)
/*    407fc:	12000018 */ 	beqz	$s0,.L00040860
/*    40800:	00000000 */ 	nop
/*    40804:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    40808:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    4080c:	3c0a800a */ 	lui	$t2,%hi(var8009c648)
/*    40810:	85cf0000 */ 	lh	$t7,0x0($t6)
/*    40814:	8d4ac648 */ 	lw	$t2,%lo(var8009c648)($t2)
/*    40818:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    4081c:	000cc880 */ 	sll	$t9,$t4,0x2
/*    40820:	000f5880 */ 	sll	$t3,$t7,0x2
/*    40824:	014bc021 */ 	addu	$t8,$t2,$t3
/*    40828:	01394021 */ 	addu	$t0,$t1,$t9
/*    4082c:	c5060000 */ 	lwc1	$f6,0x0($t0)
/*    40830:	c7100000 */ 	lwc1	$f16,0x0($t8)
/*    40834:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    40838:	46103282 */ 	mul.s	$f10,$f6,$f16
/*    4083c:	46005207 */ 	neg.s	$f8,$f10
/*    40840:	e5a80000 */ 	swc1	$f8,0x0($t5)
/*    40844:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    40848:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    4084c:	27280002 */ 	addiu	$t0,$t9,0x2
/*    40850:	25890004 */ 	addiu	$t1,$t4,0x4
/*    40854:	afa90040 */ 	sw	$t1,0x40($sp)
/*    40858:	10000016 */ 	b	.L000408b4
/*    4085c:	afa8003c */ 	sw	$t0,0x3c($sp)
.L00040860:
/*    40860:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    40864:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    40868:	3c18800a */ 	lui	$t8,%hi(var8009c648)
/*    4086c:	85ac0000 */ 	lh	$t4,0x0($t5)
/*    40870:	8f18c648 */ 	lw	$t8,%lo(var8009c648)($t8)
/*    40874:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    40878:	000f5080 */ 	sll	$t2,$t7,0x2
/*    4087c:	000c4880 */ 	sll	$t1,$t4,0x2
/*    40880:	0309c821 */ 	addu	$t9,$t8,$t1
/*    40884:	01ca5821 */ 	addu	$t3,$t6,$t2
/*    40888:	c5720000 */ 	lwc1	$f18,0x0($t3)
/*    4088c:	c7240000 */ 	lwc1	$f4,0x0($t9)
/*    40890:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    40894:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    40898:	e5060000 */ 	swc1	$f6,0x0($t0)
/*    4089c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    408a0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    408a4:	254b0002 */ 	addiu	$t3,$t2,0x2
/*    408a8:	25ee0004 */ 	addiu	$t6,$t7,0x4
/*    408ac:	afae0040 */ 	sw	$t6,0x40($sp)
/*    408b0:	afab003c */ 	sw	$t3,0x3c($sp)
.L000408b4:
/*    408b4:	10000031 */ 	b	.L0004097c
/*    408b8:	00000000 */ 	nop
.L000408bc:
/*    408bc:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    408c0:	91b00000 */ 	lbu	$s0,0x0($t5)
/*    408c4:	25ac0001 */ 	addiu	$t4,$t5,0x1
/*    408c8:	afac0038 */ 	sw	$t4,0x38($sp)
/*    408cc:	12000017 */ 	beqz	$s0,.L0004092c
/*    408d0:	00000000 */ 	nop
/*    408d4:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    408d8:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    408dc:	3c18800a */ 	lui	$t8,%hi(var8009c648)
/*    408e0:	85390000 */ 	lh	$t9,0x0($t1)
/*    408e4:	8f18c648 */ 	lw	$t8,%lo(var8009c648)($t8)
/*    408e8:	000e5080 */ 	sll	$t2,$t6,0x2
/*    408ec:	00194080 */ 	sll	$t0,$t9,0x2
/*    408f0:	03aa5821 */ 	addu	$t3,$sp,$t2
/*    408f4:	03087821 */ 	addu	$t7,$t8,$t0
/*    408f8:	c5f00000 */ 	lwc1	$f16,0x0($t7)
/*    408fc:	c56a0100 */ 	lwc1	$f10,0x100($t3)
/*    40900:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    40904:	46105202 */ 	mul.s	$f8,$f10,$f16
/*    40908:	46004487 */ 	neg.s	$f18,$f8
/*    4090c:	e5b20000 */ 	swc1	$f18,0x0($t5)
/*    40910:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    40914:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    40918:	27380002 */ 	addiu	$t8,$t9,0x2
/*    4091c:	25890004 */ 	addiu	$t1,$t4,0x4
/*    40920:	afa90040 */ 	sw	$t1,0x40($sp)
/*    40924:	10000015 */ 	b	.L0004097c
/*    40928:	afb8003c */ 	sw	$t8,0x3c($sp)
.L0004092c:
/*    4092c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    40930:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    40934:	3c08800a */ 	lui	$t0,%hi(var8009c648)
/*    40938:	85ee0000 */ 	lh	$t6,0x0($t7)
/*    4093c:	8d08c648 */ 	lw	$t0,%lo(var8009c648)($t0)
/*    40940:	000d6080 */ 	sll	$t4,$t5,0x2
/*    40944:	000e5080 */ 	sll	$t2,$t6,0x2
/*    40948:	03ac4821 */ 	addu	$t1,$sp,$t4
/*    4094c:	010a5821 */ 	addu	$t3,$t0,$t2
/*    40950:	c5640000 */ 	lwc1	$f4,0x0($t3)
/*    40954:	c5260100 */ 	lwc1	$f6,0x100($t1)
/*    40958:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    4095c:	46043282 */ 	mul.s	$f10,$f6,$f4
/*    40960:	e72a0000 */ 	swc1	$f10,0x0($t9)
/*    40964:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    40968:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    4096c:	25c80002 */ 	addiu	$t0,$t6,0x2
/*    40970:	270f0004 */ 	addiu	$t7,$t8,0x4
/*    40974:	afaf0040 */ 	sw	$t7,0x40($sp)
/*    40978:	afa8003c */ 	sw	$t0,0x3c($sp)
.L0004097c:
/*    4097c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*    40980:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    40984:	afab0048 */ 	sw	$t3,0x48($sp)
/*    40988:	8fad0048 */ 	lw	$t5,0x48($sp)
/*    4098c:	8fac01b8 */ 	lw	$t4,0x1b8($sp)
/*    40990:	01ac082a */ 	slt	$at,$t5,$t4
/*    40994:	1420ff73 */ 	bnez	$at,.L00040764
/*    40998:	00000000 */ 	nop
.L0004099c:
/*    4099c:	8fb901c4 */ 	lw	$t9,0x1c4($sp)
/*    409a0:	8fa901c0 */ 	lw	$t1,0x1c0($sp)
/*    409a4:	8fae01c8 */ 	lw	$t6,0x1c8($sp)
/*    409a8:	0019c080 */ 	sll	$t8,$t9,0x2
/*    409ac:	01387821 */ 	addu	$t7,$t1,$t8
/*    409b0:	000e4080 */ 	sll	$t0,$t6,0x2
/*    409b4:	01e85021 */ 	addu	$t2,$t7,$t0
/*    409b8:	8d4b3c98 */ 	lw	$t3,0x3c98($t2)
/*    409bc:	116000d0 */ 	beqz	$t3,.L00040d00
/*    409c0:	00000000 */ 	nop
/*    409c4:	8d4d3ca0 */ 	lw	$t5,0x3ca0($t2)
/*    409c8:	24010002 */ 	addiu	$at,$zero,0x2
/*    409cc:	15a100cc */ 	bne	$t5,$at,.L00040d00
/*    409d0:	00000000 */ 	nop
/*    409d4:	8fb901c4 */ 	lw	$t9,0x1c4($sp)
/*    409d8:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*    409dc:	8fae01c8 */ 	lw	$t6,0x1c8($sp)
/*    409e0:	00194880 */ 	sll	$t1,$t9,0x2
/*    409e4:	0189c021 */ 	addu	$t8,$t4,$t1
/*    409e8:	000e7880 */ 	sll	$t7,$t6,0x2
/*    409ec:	030f4021 */ 	addu	$t0,$t8,$t7
/*    409f0:	8d0b3ca8 */ 	lw	$t3,0x3ca8($t0)
/*    409f4:	1160008e */ 	beqz	$t3,.L00040c30
/*    409f8:	00000000 */ 	nop
/*    409fc:	8faa01bc */ 	lw	$t2,0x1bc($sp)
/*    40a00:	3c197005 */ 	lui	$t9,%hi(var700579c8)
/*    40a04:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    40a08:	000a68c0 */ 	sll	$t5,$t2,0x3
/*    40a0c:	01aa6821 */ 	addu	$t5,$t5,$t2
/*    40a10:	000d6880 */ 	sll	$t5,$t5,0x2
/*    40a14:	01aa6821 */ 	addu	$t5,$t5,$t2
/*    40a18:	000d6840 */ 	sll	$t5,$t5,0x1
/*    40a1c:	032dc821 */ 	addu	$t9,$t9,$t5
/*    40a20:	873979c8 */ 	lh	$t9,%lo(var700579c8)($t9)
/*    40a24:	172c0031 */ 	bne	$t9,$t4,.L00040aec
/*    40a28:	00000000 */ 	nop
/*    40a2c:	8fa901bc */ 	lw	$t1,0x1bc($sp)
/*    40a30:	3c187005 */ 	lui	$t8,%hi(var700579ec+0x2)
/*    40a34:	000970c0 */ 	sll	$t6,$t1,0x3
/*    40a38:	01c97021 */ 	addu	$t6,$t6,$t1
/*    40a3c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40a40:	01c97021 */ 	addu	$t6,$t6,$t1
/*    40a44:	000e7040 */ 	sll	$t6,$t6,0x1
/*    40a48:	030ec021 */ 	addu	$t8,$t8,$t6
/*    40a4c:	871879ee */ 	lh	$t8,%lo(var700579ec+0x2)($t8)
/*    40a50:	00187880 */ 	sll	$t7,$t8,0x2
/*    40a54:	01f87823 */ 	subu	$t7,$t7,$t8
/*    40a58:	afaf01b8 */ 	sw	$t7,0x1b8($sp)
/*    40a5c:	24080003 */ 	addiu	$t0,$zero,0x3
/*    40a60:	afa8005c */ 	sw	$t0,0x5c($sp)
/*    40a64:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*    40a68:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    40a6c:	3c097005 */ 	lui	$t1,%hi(var700579b8)
/*    40a70:	000b50c0 */ 	sll	$t2,$t3,0x3
/*    40a74:	014b5021 */ 	addu	$t2,$t2,$t3
/*    40a78:	000a5080 */ 	sll	$t2,$t2,0x2
/*    40a7c:	014b5021 */ 	addu	$t2,$t2,$t3
/*    40a80:	000a5040 */ 	sll	$t2,$t2,0x1
/*    40a84:	000dc840 */ 	sll	$t9,$t5,0x1
/*    40a88:	252979b8 */ 	addiu	$t1,$t1,%lo(var700579b8)
/*    40a8c:	01596021 */ 	addu	$t4,$t2,$t9
/*    40a90:	01597821 */ 	addu	$t7,$t2,$t9
/*    40a94:	01e94021 */ 	addu	$t0,$t7,$t1
/*    40a98:	01897021 */ 	addu	$t6,$t4,$t1
/*    40a9c:	85d80030 */ 	lh	$t8,0x30($t6)
/*    40aa0:	850b002e */ 	lh	$t3,0x2e($t0)
/*    40aa4:	030b6823 */ 	subu	$t5,$t8,$t3
/*    40aa8:	afad01b0 */ 	sw	$t5,0x1b0($sp)
/*    40aac:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*    40ab0:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    40ab4:	3c097005 */ 	lui	$t1,%hi(var700579e4+0x2)
/*    40ab8:	000c70c0 */ 	sll	$t6,$t4,0x3
/*    40abc:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    40ac0:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40ac4:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    40ac8:	000e7040 */ 	sll	$t6,$t6,0x1
/*    40acc:	000ac840 */ 	sll	$t9,$t2,0x1
/*    40ad0:	01d97821 */ 	addu	$t7,$t6,$t9
/*    40ad4:	012f4821 */ 	addu	$t1,$t1,$t7
/*    40ad8:	852979e6 */ 	lh	$t1,%lo(var700579e4+0x2)($t1)
/*    40adc:	00094080 */ 	sll	$t0,$t1,0x2
/*    40ae0:	01094023 */ 	subu	$t0,$t0,$t1
/*    40ae4:	10000050 */ 	b	.L00040c28
/*    40ae8:	afa801b4 */ 	sw	$t0,0x1b4($sp)
.L00040aec:
/*    40aec:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*    40af0:	3c0c7005 */ 	lui	$t4,%hi(var700579c8)
/*    40af4:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    40af8:	000b68c0 */ 	sll	$t5,$t3,0x3
/*    40afc:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    40b00:	000d6880 */ 	sll	$t5,$t5,0x2
/*    40b04:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    40b08:	000d6840 */ 	sll	$t5,$t5,0x1
/*    40b0c:	018d6021 */ 	addu	$t4,$t4,$t5
/*    40b10:	858c79c8 */ 	lh	$t4,%lo(var700579c8)($t4)
/*    40b14:	030c082a */ 	slt	$at,$t8,$t4
/*    40b18:	10200011 */ 	beqz	$at,.L00040b60
/*    40b1c:	00000000 */ 	nop
/*    40b20:	8faa01bc */ 	lw	$t2,0x1bc($sp)
/*    40b24:	8fb0005c */ 	lw	$s0,0x5c($sp)
/*    40b28:	3c097005 */ 	lui	$t1,%hi(var700579b8+0x2)
/*    40b2c:	000a70c0 */ 	sll	$t6,$t2,0x3
/*    40b30:	01ca7021 */ 	addu	$t6,$t6,$t2
/*    40b34:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40b38:	01ca7021 */ 	addu	$t6,$t6,$t2
/*    40b3c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    40b40:	0010c840 */ 	sll	$t9,$s0,0x1
/*    40b44:	000e7040 */ 	sll	$t6,$t6,0x1
/*    40b48:	01d97821 */ 	addu	$t7,$t6,$t9
/*    40b4c:	012f4821 */ 	addu	$t1,$t1,$t7
/*    40b50:	852979ba */ 	lh	$t1,%lo(var700579b8+0x2)($t1)
/*    40b54:	afb0005c */ 	sw	$s0,0x5c($sp)
/*    40b58:	10000033 */ 	b	.L00040c28
/*    40b5c:	afa901b8 */ 	sw	$t1,0x1b8($sp)
.L00040b60:
/*    40b60:	8fa801bc */ 	lw	$t0,0x1bc($sp)
/*    40b64:	8fb0005c */ 	lw	$s0,0x5c($sp)
/*    40b68:	3c0c7005 */ 	lui	$t4,%hi(var700579e8)
/*    40b6c:	000858c0 */ 	sll	$t3,$t0,0x3
/*    40b70:	01685821 */ 	addu	$t3,$t3,$t0
/*    40b74:	000b5880 */ 	sll	$t3,$t3,0x2
/*    40b78:	01685821 */ 	addu	$t3,$t3,$t0
/*    40b7c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    40b80:	00106840 */ 	sll	$t5,$s0,0x1
/*    40b84:	000b5840 */ 	sll	$t3,$t3,0x1
/*    40b88:	016dc021 */ 	addu	$t8,$t3,$t5
/*    40b8c:	01986021 */ 	addu	$t4,$t4,$t8
/*    40b90:	858c79e8 */ 	lh	$t4,%lo(var700579e8)($t4)
/*    40b94:	afb0005c */ 	sw	$s0,0x5c($sp)
/*    40b98:	000c5080 */ 	sll	$t2,$t4,0x2
/*    40b9c:	014c5023 */ 	subu	$t2,$t2,$t4
/*    40ba0:	afaa01b8 */ 	sw	$t2,0x1b8($sp)
/*    40ba4:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*    40ba8:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    40bac:	3c0b7005 */ 	lui	$t3,%hi(var700579b8)
/*    40bb0:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*    40bb4:	032ec821 */ 	addu	$t9,$t9,$t6
/*    40bb8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    40bbc:	032ec821 */ 	addu	$t9,$t9,$t6
/*    40bc0:	0019c840 */ 	sll	$t9,$t9,0x1
/*    40bc4:	000f4840 */ 	sll	$t1,$t7,0x1
/*    40bc8:	256b79b8 */ 	addiu	$t3,$t3,%lo(var700579b8)
/*    40bcc:	03294021 */ 	addu	$t0,$t9,$t1
/*    40bd0:	03296021 */ 	addu	$t4,$t9,$t1
/*    40bd4:	018b5021 */ 	addu	$t2,$t4,$t3
/*    40bd8:	010b6821 */ 	addu	$t5,$t0,$t3
/*    40bdc:	85b80030 */ 	lh	$t8,0x30($t5)
/*    40be0:	854e002e */ 	lh	$t6,0x2e($t2)
/*    40be4:	030e7823 */ 	subu	$t7,$t8,$t6
/*    40be8:	afaf01b0 */ 	sw	$t7,0x1b0($sp)
/*    40bec:	8fa801bc */ 	lw	$t0,0x1bc($sp)
/*    40bf0:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    40bf4:	3c0b7005 */ 	lui	$t3,%hi(var700579e4+0x2)
/*    40bf8:	000868c0 */ 	sll	$t5,$t0,0x3
/*    40bfc:	01a86821 */ 	addu	$t5,$t5,$t0
/*    40c00:	000d6880 */ 	sll	$t5,$t5,0x2
/*    40c04:	01a86821 */ 	addu	$t5,$t5,$t0
/*    40c08:	000d6840 */ 	sll	$t5,$t5,0x1
/*    40c0c:	00194840 */ 	sll	$t1,$t9,0x1
/*    40c10:	01a96021 */ 	addu	$t4,$t5,$t1
/*    40c14:	016c5821 */ 	addu	$t3,$t3,$t4
/*    40c18:	856b79e6 */ 	lh	$t3,%lo(var700579e4+0x2)($t3)
/*    40c1c:	000b5080 */ 	sll	$t2,$t3,0x2
/*    40c20:	014b5023 */ 	subu	$t2,$t2,$t3
/*    40c24:	afaa01b4 */ 	sw	$t2,0x1b4($sp)
.L00040c28:
/*    40c28:	10000033 */ 	b	.L00040cf8
/*    40c2c:	00000000 */ 	nop
.L00040c30:
/*    40c30:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*    40c34:	8fb0005c */ 	lw	$s0,0x5c($sp)
/*    40c38:	3c197005 */ 	lui	$t9,%hi(var700579e8)
/*    40c3c:	001870c0 */ 	sll	$t6,$t8,0x3
/*    40c40:	01d87021 */ 	addu	$t6,$t6,$t8
/*    40c44:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40c48:	01d87021 */ 	addu	$t6,$t6,$t8
/*    40c4c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    40c50:	00107840 */ 	sll	$t7,$s0,0x1
/*    40c54:	000e7040 */ 	sll	$t6,$t6,0x1
/*    40c58:	01cf4021 */ 	addu	$t0,$t6,$t7
/*    40c5c:	0328c821 */ 	addu	$t9,$t9,$t0
/*    40c60:	873979e8 */ 	lh	$t9,%lo(var700579e8)($t9)
/*    40c64:	afb0005c */ 	sw	$s0,0x5c($sp)
/*    40c68:	00196880 */ 	sll	$t5,$t9,0x2
/*    40c6c:	01b96823 */ 	subu	$t5,$t5,$t9
/*    40c70:	afad01b8 */ 	sw	$t5,0x1b8($sp)
/*    40c74:	8fa901bc */ 	lw	$t1,0x1bc($sp)
/*    40c78:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    40c7c:	3c0e7005 */ 	lui	$t6,%hi(var700579b8)
/*    40c80:	000960c0 */ 	sll	$t4,$t1,0x3
/*    40c84:	01896021 */ 	addu	$t4,$t4,$t1
/*    40c88:	000c6080 */ 	sll	$t4,$t4,0x2
/*    40c8c:	01896021 */ 	addu	$t4,$t4,$t1
/*    40c90:	000c6040 */ 	sll	$t4,$t4,0x1
/*    40c94:	000b5040 */ 	sll	$t2,$t3,0x1
/*    40c98:	25ce79b8 */ 	addiu	$t6,$t6,%lo(var700579b8)
/*    40c9c:	018ac021 */ 	addu	$t8,$t4,$t2
/*    40ca0:	018ac821 */ 	addu	$t9,$t4,$t2
/*    40ca4:	032e6821 */ 	addu	$t5,$t9,$t6
/*    40ca8:	030e7821 */ 	addu	$t7,$t8,$t6
/*    40cac:	85e80030 */ 	lh	$t0,0x30($t7)
/*    40cb0:	85a9002e */ 	lh	$t1,0x2e($t5)
/*    40cb4:	01095823 */ 	subu	$t3,$t0,$t1
/*    40cb8:	afab01b0 */ 	sw	$t3,0x1b0($sp)
/*    40cbc:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*    40cc0:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    40cc4:	3c0e7005 */ 	lui	$t6,%hi(var700579e4+0x2)
/*    40cc8:	001878c0 */ 	sll	$t7,$t8,0x3
/*    40ccc:	01f87821 */ 	addu	$t7,$t7,$t8
/*    40cd0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    40cd4:	01f87821 */ 	addu	$t7,$t7,$t8
/*    40cd8:	000f7840 */ 	sll	$t7,$t7,0x1
/*    40cdc:	000c5040 */ 	sll	$t2,$t4,0x1
/*    40ce0:	01eac821 */ 	addu	$t9,$t7,$t2
/*    40ce4:	01d97021 */ 	addu	$t6,$t6,$t9
/*    40ce8:	85ce79e6 */ 	lh	$t6,%lo(var700579e4+0x2)($t6)
/*    40cec:	000e6880 */ 	sll	$t5,$t6,0x2
/*    40cf0:	01ae6823 */ 	subu	$t5,$t5,$t6
/*    40cf4:	afad01b4 */ 	sw	$t5,0x1b4($sp)
.L00040cf8:
/*    40cf8:	10000010 */ 	b	.L00040d3c
/*    40cfc:	00000000 */ 	nop
.L00040d00:
/*    40d00:	8fa801bc */ 	lw	$t0,0x1bc($sp)
/*    40d04:	8fb0005c */ 	lw	$s0,0x5c($sp)
/*    40d08:	3c0c7005 */ 	lui	$t4,%hi(var700579b8+0x2)
/*    40d0c:	000848c0 */ 	sll	$t1,$t0,0x3
/*    40d10:	01284821 */ 	addu	$t1,$t1,$t0
/*    40d14:	00094880 */ 	sll	$t1,$t1,0x2
/*    40d18:	01284821 */ 	addu	$t1,$t1,$t0
/*    40d1c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    40d20:	00105840 */ 	sll	$t3,$s0,0x1
/*    40d24:	00094840 */ 	sll	$t1,$t1,0x1
/*    40d28:	012bc021 */ 	addu	$t8,$t1,$t3
/*    40d2c:	01986021 */ 	addu	$t4,$t4,$t8
/*    40d30:	858c79ba */ 	lh	$t4,%lo(var700579b8+0x2)($t4)
/*    40d34:	afb0005c */ 	sw	$s0,0x5c($sp)
/*    40d38:	afac01b8 */ 	sw	$t4,0x1b8($sp)
.L00040d3c:
/*    40d3c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    40d40:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    40d44:	01ea082a */ 	slt	$at,$t7,$t2
/*    40d48:	1420fe59 */ 	bnez	$at,.L000406b0
/*    40d4c:	00000000 */ 	nop
.L00040d50:
/*    40d50:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    40d54:	2b210240 */ 	slti	$at,$t9,0x240
/*    40d58:	1020000b */ 	beqz	$at,.L00040d88
/*    40d5c:	00000000 */ 	nop
/*    40d60:	8fad01c8 */ 	lw	$t5,0x1c8($sp)
/*    40d64:	8fae01c0 */ 	lw	$t6,0x1c0($sp)
/*    40d68:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    40d6c:	000d4080 */ 	sll	$t0,$t5,0x2
/*    40d70:	01c84821 */ 	addu	$t1,$t6,$t0
/*    40d74:	8d254660 */ 	lw	$a1,0x4660($t1)
/*    40d78:	0c012c30 */ 	jal	bzero
/*    40d7c:	00052880 */ 	sll	$a1,$a1,0x2
/*    40d80:	10000005 */ 	b	.L00040d98
/*    40d84:	24020001 */ 	addiu	$v0,$zero,0x1
.L00040d88:
/*    40d88:	10000003 */ 	b	.L00040d98
/*    40d8c:	24020001 */ 	addiu	$v0,$zero,0x1
/*    40d90:	10000001 */ 	b	.L00040d98
/*    40d94:	00000000 */ 	nop
.L00040d98:
/*    40d98:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    40d9c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    40da0:	27bd01c0 */ 	addiu	$sp,$sp,0x1c0
/*    40da4:	03e00008 */ 	jr	$ra
/*    40da8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00040dac
/*    40dac:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    40db0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    40db4:	afa40038 */ 	sw	$a0,0x38($sp)
/*    40db8:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    40dbc:	afa60040 */ 	sw	$a2,0x40($sp)
/*    40dc0:	afb10018 */ 	sw	$s1,0x18($sp)
/*    40dc4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    40dc8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    40dcc:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    40dd0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    40dd4:	000fc080 */ 	sll	$t8,$t7,0x2
/*    40dd8:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    40ddc:	00084880 */ 	sll	$t1,$t0,0x2
/*    40de0:	03295021 */ 	addu	$t2,$t9,$t1
/*    40de4:	8d4b3c98 */ 	lw	$t3,0x3c98($t2)
/*    40de8:	1160015c */ 	beqz	$t3,.L0004135c
/*    40dec:	00000000 */ 	nop
/*    40df0:	8d4c3ca0 */ 	lw	$t4,0x3ca0($t2)
/*    40df4:	24010002 */ 	addiu	$at,$zero,0x2
/*    40df8:	15810158 */ 	bne	$t4,$at,.L0004135c
/*    40dfc:	00000000 */ 	nop
/*    40e00:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    40e04:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    40e08:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    40e0c:	000f7080 */ 	sll	$t6,$t7,0x2
/*    40e10:	01aec021 */ 	addu	$t8,$t5,$t6
/*    40e14:	0008c880 */ 	sll	$t9,$t0,0x2
/*    40e18:	03194821 */ 	addu	$t1,$t8,$t9
/*    40e1c:	8d2b3ca8 */ 	lw	$t3,0x3ca8($t1)
/*    40e20:	116000cf */ 	beqz	$t3,.L00041160
/*    40e24:	00000000 */ 	nop
/*    40e28:	afa00030 */ 	sw	$zero,0x30($sp)
.L00040e2c:
/*    40e2c:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    40e30:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    40e34:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    40e38:	000c7880 */ 	sll	$t7,$t4,0x2
/*    40e3c:	014f6821 */ 	addu	$t5,$t2,$t7
/*    40e40:	000e4080 */ 	sll	$t0,$t6,0x2
/*    40e44:	01a8c021 */ 	addu	$t8,$t5,$t0
/*    40e48:	8f193c90 */ 	lw	$t9,0x3c90($t8)
/*    40e4c:	3c097005 */ 	lui	$t1,%hi(var70057b7c)
/*    40e50:	01394821 */ 	addu	$t1,$t1,$t9
/*    40e54:	91297b7c */ 	lbu	$t1,%lo(var70057b7c)($t1)
/*    40e58:	11200015 */ 	beqz	$t1,.L00040eb0
/*    40e5c:	00000000 */ 	nop
/*    40e60:	2544001c */ 	addiu	$a0,$t2,0x1c
/*    40e64:	25452020 */ 	addiu	$a1,$t2,0x2020
/*    40e68:	0c0118b1 */ 	jal	func000462c4
/*    40e6c:	01203025 */ 	or	$a2,$t1,$zero
/*    40e70:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    40e74:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    40e78:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    40e7c:	000c7940 */ 	sll	$t7,$t4,0x5
/*    40e80:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    40e84:	01ec7823 */ 	subu	$t7,$t7,$t4
/*    40e88:	000d4140 */ 	sll	$t0,$t5,0x5
/*    40e8c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    40e90:	010d4023 */ 	subu	$t0,$t0,$t5
/*    40e94:	000840c0 */ 	sll	$t0,$t0,0x3
/*    40e98:	016f7021 */ 	addu	$t6,$t3,$t7
/*    40e9c:	01c8c021 */ 	addu	$t8,$t6,$t0
/*    40ea0:	00195080 */ 	sll	$t2,$t9,0x2
/*    40ea4:	030a4821 */ 	addu	$t1,$t8,$t2
/*    40ea8:	10000010 */ 	b	.L00040eec
/*    40eac:	ad223d08 */ 	sw	$v0,0x3d08($t1)
.L00040eb0:
/*    40eb0:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    40eb4:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    40eb8:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    40ebc:	000b7940 */ 	sll	$t7,$t3,0x5
/*    40ec0:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    40ec4:	01eb7823 */ 	subu	$t7,$t7,$t3
/*    40ec8:	000e4140 */ 	sll	$t0,$t6,0x5
/*    40ecc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    40ed0:	010e4023 */ 	subu	$t0,$t0,$t6
/*    40ed4:	000840c0 */ 	sll	$t0,$t0,0x3
/*    40ed8:	018f6821 */ 	addu	$t5,$t4,$t7
/*    40edc:	01a8c821 */ 	addu	$t9,$t5,$t0
/*    40ee0:	00185080 */ 	sll	$t2,$t8,0x2
/*    40ee4:	032a4821 */ 	addu	$t1,$t9,$t2
/*    40ee8:	ad203d08 */ 	sw	$zero,0x3d08($t1)
.L00040eec:
/*    40eec:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    40ef0:	256c0001 */ 	addiu	$t4,$t3,0x1
/*    40ef4:	29810008 */ 	slti	$at,$t4,0x8
/*    40ef8:	1420ffcc */ 	bnez	$at,.L00040e2c
/*    40efc:	afac0030 */ 	sw	$t4,0x30($sp)
/*    40f00:	240f0003 */ 	addiu	$t7,$zero,0x3
/*    40f04:	afaf0030 */ 	sw	$t7,0x30($sp)
.L00040f08:
/*    40f08:	afa0002c */ 	sw	$zero,0x2c($sp)
.L00040f0c:
/*    40f0c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    40f10:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    40f14:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    40f18:	000d4080 */ 	sll	$t0,$t5,0x2
/*    40f1c:	01c8c021 */ 	addu	$t8,$t6,$t0
/*    40f20:	00195080 */ 	sll	$t2,$t9,0x2
/*    40f24:	030a4821 */ 	addu	$t1,$t8,$t2
/*    40f28:	8d2b3c90 */ 	lw	$t3,0x3c90($t1)
/*    40f2c:	3c0c7005 */ 	lui	$t4,%hi(var70057b7c)
/*    40f30:	018b6021 */ 	addu	$t4,$t4,$t3
/*    40f34:	918c7b7c */ 	lbu	$t4,%lo(var70057b7c)($t4)
/*    40f38:	1180001c */ 	beqz	$t4,.L00040fac
/*    40f3c:	00000000 */ 	nop
/*    40f40:	25c4001c */ 	addiu	$a0,$t6,0x1c
/*    40f44:	25c52020 */ 	addiu	$a1,$t6,0x2020
/*    40f48:	0c0118b1 */ 	jal	func000462c4
/*    40f4c:	01803025 */ 	or	$a2,$t4,$zero
/*    40f50:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    40f54:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    40f58:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    40f5c:	000d4140 */ 	sll	$t0,$t5,0x5
/*    40f60:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    40f64:	010d4023 */ 	subu	$t0,$t0,$t5
/*    40f68:	000b7080 */ 	sll	$t6,$t3,0x2
/*    40f6c:	01cb7023 */ 	subu	$t6,$t6,$t3
/*    40f70:	00185140 */ 	sll	$t2,$t8,0x5
/*    40f74:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    40f78:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40f7c:	000840c0 */ 	sll	$t0,$t0,0x3
/*    40f80:	01585023 */ 	subu	$t2,$t2,$t8
/*    40f84:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    40f88:	01cb7021 */ 	addu	$t6,$t6,$t3
/*    40f8c:	01e8c821 */ 	addu	$t9,$t7,$t0
/*    40f90:	032a4821 */ 	addu	$t1,$t9,$t2
/*    40f94:	000e7080 */ 	sll	$t6,$t6,0x2
/*    40f98:	012e6021 */ 	addu	$t4,$t1,$t6
/*    40f9c:	000d7880 */ 	sll	$t7,$t5,0x2
/*    40fa0:	018f4021 */ 	addu	$t0,$t4,$t7
/*    40fa4:	10000017 */ 	b	.L00041004
/*    40fa8:	ad023d64 */ 	sw	$v0,0x3d64($t0)
.L00040fac:
/*    40fac:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    40fb0:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    40fb4:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    40fb8:	00195140 */ 	sll	$t2,$t9,0x5
/*    40fbc:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    40fc0:	01595023 */ 	subu	$t2,$t2,$t9
/*    40fc4:	000c7880 */ 	sll	$t7,$t4,0x2
/*    40fc8:	01ec7823 */ 	subu	$t7,$t7,$t4
/*    40fcc:	00097140 */ 	sll	$t6,$t1,0x5
/*    40fd0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    40fd4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    40fd8:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    40fdc:	01c97023 */ 	subu	$t6,$t6,$t1
/*    40fe0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    40fe4:	01ec7821 */ 	addu	$t7,$t7,$t4
/*    40fe8:	030a5821 */ 	addu	$t3,$t8,$t2
/*    40fec:	016e6821 */ 	addu	$t5,$t3,$t6
/*    40ff0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    40ff4:	01af4021 */ 	addu	$t0,$t5,$t7
/*    40ff8:	0019c080 */ 	sll	$t8,$t9,0x2
/*    40ffc:	01185021 */ 	addu	$t2,$t0,$t8
/*    41000:	ad403d64 */ 	sw	$zero,0x3d64($t2)
.L00041004:
/*    41004:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    41008:	252b0001 */ 	addiu	$t3,$t1,0x1
/*    4100c:	29610003 */ 	slti	$at,$t3,0x3
/*    41010:	1420ffbe */ 	bnez	$at,.L00040f0c
/*    41014:	afab002c */ 	sw	$t3,0x2c($sp)
/*    41018:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    4101c:	25cc0001 */ 	addiu	$t4,$t6,0x1
/*    41020:	29810006 */ 	slti	$at,$t4,0x6
/*    41024:	1420ffb8 */ 	bnez	$at,.L00040f08
/*    41028:	afac0030 */ 	sw	$t4,0x30($sp)
/*    4102c:	240d0006 */ 	addiu	$t5,$zero,0x6
/*    41030:	afad0030 */ 	sw	$t5,0x30($sp)
.L00041034:
/*    41034:	afa0002c */ 	sw	$zero,0x2c($sp)
.L00041038:
/*    41038:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    4103c:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    41040:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    41044:	00194080 */ 	sll	$t0,$t9,0x2
/*    41048:	01e8c021 */ 	addu	$t8,$t7,$t0
/*    4104c:	000a4880 */ 	sll	$t1,$t2,0x2
/*    41050:	03095821 */ 	addu	$t3,$t8,$t1
/*    41054:	8d6e3c90 */ 	lw	$t6,0x3c90($t3)
/*    41058:	3c0c7005 */ 	lui	$t4,%hi(var70057b8c)
/*    4105c:	018e6021 */ 	addu	$t4,$t4,$t6
/*    41060:	918c7b8c */ 	lbu	$t4,%lo(var70057b8c)($t4)
/*    41064:	1180001c */ 	beqz	$t4,.L000410d8
/*    41068:	00000000 */ 	nop
/*    4106c:	25e4001c */ 	addiu	$a0,$t7,0x1c
/*    41070:	25e52020 */ 	addiu	$a1,$t7,0x2020
/*    41074:	0c0118b1 */ 	jal	func000462c4
/*    41078:	01803025 */ 	or	$a2,$t4,$zero
/*    4107c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    41080:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    41084:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    41088:	00194140 */ 	sll	$t0,$t9,0x5
/*    4108c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    41090:	01194023 */ 	subu	$t0,$t0,$t9
/*    41094:	000e7880 */ 	sll	$t7,$t6,0x2
/*    41098:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    4109c:	00184940 */ 	sll	$t1,$t8,0x5
/*    410a0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    410a4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    410a8:	000840c0 */ 	sll	$t0,$t0,0x3
/*    410ac:	01384823 */ 	subu	$t1,$t1,$t8
/*    410b0:	000948c0 */ 	sll	$t1,$t1,0x3
/*    410b4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    410b8:	01a85021 */ 	addu	$t2,$t5,$t0
/*    410bc:	01495821 */ 	addu	$t3,$t2,$t1
/*    410c0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    410c4:	016f6021 */ 	addu	$t4,$t3,$t7
/*    410c8:	00196880 */ 	sll	$t5,$t9,0x2
/*    410cc:	018d4021 */ 	addu	$t0,$t4,$t5
/*    410d0:	10000017 */ 	b	.L00041130
/*    410d4:	ad023d64 */ 	sw	$v0,0x3d64($t0)
.L000410d8:
/*    410d8:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    410dc:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    410e0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    410e4:	000a4940 */ 	sll	$t1,$t2,0x5
/*    410e8:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    410ec:	012a4823 */ 	subu	$t1,$t1,$t2
/*    410f0:	000c6880 */ 	sll	$t5,$t4,0x2
/*    410f4:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    410f8:	000b7940 */ 	sll	$t7,$t3,0x5
/*    410fc:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    41100:	000d6880 */ 	sll	$t5,$t5,0x2
/*    41104:	000948c0 */ 	sll	$t1,$t1,0x3
/*    41108:	01eb7823 */ 	subu	$t7,$t7,$t3
/*    4110c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    41110:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    41114:	03097021 */ 	addu	$t6,$t8,$t1
/*    41118:	01cfc821 */ 	addu	$t9,$t6,$t7
/*    4111c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    41120:	032d4021 */ 	addu	$t0,$t9,$t5
/*    41124:	000ac080 */ 	sll	$t8,$t2,0x2
/*    41128:	01184821 */ 	addu	$t1,$t0,$t8
/*    4112c:	ad203d64 */ 	sw	$zero,0x3d64($t1)
.L00041130:
/*    41130:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    41134:	256e0001 */ 	addiu	$t6,$t3,0x1
/*    41138:	29c10003 */ 	slti	$at,$t6,0x3
/*    4113c:	1420ffbe */ 	bnez	$at,.L00041038
/*    41140:	afae002c */ 	sw	$t6,0x2c($sp)
/*    41144:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    41148:	25ec0001 */ 	addiu	$t4,$t7,0x1
/*    4114c:	2981000c */ 	slti	$at,$t4,0xc
/*    41150:	1420ffb8 */ 	bnez	$at,.L00041034
/*    41154:	afac0030 */ 	sw	$t4,0x30($sp)
/*    41158:	10000065 */ 	b	.L000412f0
/*    4115c:	00000000 */ 	nop
.L00041160:
/*    41160:	afa00034 */ 	sw	$zero,0x34($sp)
.L00041164:
/*    41164:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    41168:	3c0d7005 */ 	lui	$t5,%hi(var70057b74)
/*    4116c:	25ad7b74 */ 	addiu	$t5,$t5,%lo(var70057b74)
/*    41170:	032d5021 */ 	addu	$t2,$t9,$t5
/*    41174:	91480005 */ 	lbu	$t0,0x5($t2)
/*    41178:	afa80030 */ 	sw	$t0,0x30($sp)
/*    4117c:	91580006 */ 	lbu	$t8,0x6($t2)
/*    41180:	0118082a */ 	slt	$at,$t0,$t8
/*    41184:	10200055 */ 	beqz	$at,.L000412dc
/*    41188:	00000000 */ 	nop
.L0004118c:
/*    4118c:	afa0002c */ 	sw	$zero,0x2c($sp)
.L00041190:
/*    41190:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    41194:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    41198:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    4119c:	000b7080 */ 	sll	$t6,$t3,0x2
/*    411a0:	012e7821 */ 	addu	$t7,$t1,$t6
/*    411a4:	000cc880 */ 	sll	$t9,$t4,0x2
/*    411a8:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    411ac:	01f96821 */ 	addu	$t5,$t7,$t9
/*    411b0:	8daa3c90 */ 	lw	$t2,0x3c90($t5)
/*    411b4:	3c0e7005 */ 	lui	$t6,%hi(var70057b7c)
/*    411b8:	0008c100 */ 	sll	$t8,$t0,0x4
/*    411bc:	25ce7b7c */ 	addiu	$t6,$t6,%lo(var70057b7c)
/*    411c0:	030a5821 */ 	addu	$t3,$t8,$t2
/*    411c4:	016e6021 */ 	addu	$t4,$t3,$t6
/*    411c8:	918f0000 */ 	lbu	$t7,0x0($t4)
/*    411cc:	11e0001e */ 	beqz	$t7,.L00041248
/*    411d0:	00000000 */ 	nop
/*    411d4:	030ac821 */ 	addu	$t9,$t8,$t2
/*    411d8:	032e6821 */ 	addu	$t5,$t9,$t6
/*    411dc:	91a60000 */ 	lbu	$a2,0x0($t5)
/*    411e0:	2524001c */ 	addiu	$a0,$t1,0x1c
/*    411e4:	0c0118b1 */ 	jal	func000462c4
/*    411e8:	25252020 */ 	addiu	$a1,$t1,0x2020
/*    411ec:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    411f0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    411f4:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    411f8:	000b6140 */ 	sll	$t4,$t3,0x5
/*    411fc:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    41200:	018b6023 */ 	subu	$t4,$t4,$t3
/*    41204:	00197080 */ 	sll	$t6,$t9,0x2
/*    41208:	01d97023 */ 	subu	$t6,$t6,$t9
/*    4120c:	0009c140 */ 	sll	$t8,$t1,0x5
/*    41210:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    41214:	000e7080 */ 	sll	$t6,$t6,0x2
/*    41218:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    4121c:	0309c023 */ 	subu	$t8,$t8,$t1
/*    41220:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    41224:	01d97021 */ 	addu	$t6,$t6,$t9
/*    41228:	010c7821 */ 	addu	$t7,$t0,$t4
/*    4122c:	01f85021 */ 	addu	$t2,$t7,$t8
/*    41230:	000e7080 */ 	sll	$t6,$t6,0x2
/*    41234:	014e6821 */ 	addu	$t5,$t2,$t6
/*    41238:	000b4080 */ 	sll	$t0,$t3,0x2
/*    4123c:	01a86021 */ 	addu	$t4,$t5,$t0
/*    41240:	10000017 */ 	b	.L000412a0
/*    41244:	ad823d64 */ 	sw	$v0,0x3d64($t4)
.L00041248:
/*    41248:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    4124c:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    41250:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    41254:	000fc140 */ 	sll	$t8,$t7,0x5
/*    41258:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    4125c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    41260:	000d4080 */ 	sll	$t0,$t5,0x2
/*    41264:	010d4023 */ 	subu	$t0,$t0,$t5
/*    41268:	000a7140 */ 	sll	$t6,$t2,0x5
/*    4126c:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    41270:	00084080 */ 	sll	$t0,$t0,0x2
/*    41274:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    41278:	01ca7023 */ 	subu	$t6,$t6,$t2
/*    4127c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    41280:	010d4021 */ 	addu	$t0,$t0,$t5
/*    41284:	0138c821 */ 	addu	$t9,$t1,$t8
/*    41288:	032e5821 */ 	addu	$t3,$t9,$t6
/*    4128c:	00084080 */ 	sll	$t0,$t0,0x2
/*    41290:	01686021 */ 	addu	$t4,$t3,$t0
/*    41294:	000f4880 */ 	sll	$t1,$t7,0x2
/*    41298:	0189c021 */ 	addu	$t8,$t4,$t1
/*    4129c:	af003d64 */ 	sw	$zero,0x3d64($t8)
.L000412a0:
/*    412a0:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    412a4:	25590001 */ 	addiu	$t9,$t2,0x1
/*    412a8:	2b210003 */ 	slti	$at,$t9,0x3
/*    412ac:	1420ffb8 */ 	bnez	$at,.L00041190
/*    412b0:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    412b4:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    412b8:	3c087005 */ 	lui	$t0,%hi(var70057b78+0x2)
/*    412bc:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    412c0:	010b4021 */ 	addu	$t0,$t0,$t3
/*    412c4:	91087b7a */ 	lbu	$t0,%lo(var70057b78+0x2)($t0)
/*    412c8:	25cd0001 */ 	addiu	$t5,$t6,0x1
/*    412cc:	afad0030 */ 	sw	$t5,0x30($sp)
/*    412d0:	01a8082a */ 	slt	$at,$t5,$t0
/*    412d4:	1420ffad */ 	bnez	$at,.L0004118c
/*    412d8:	00000000 */ 	nop
.L000412dc:
/*    412dc:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    412e0:	25ec0001 */ 	addiu	$t4,$t7,0x1
/*    412e4:	29810002 */ 	slti	$at,$t4,0x2
/*    412e8:	1420ff9e */ 	bnez	$at,.L00041164
/*    412ec:	afac0034 */ 	sw	$t4,0x34($sp)
.L000412f0:
/*    412f0:	afa0002c */ 	sw	$zero,0x2c($sp)
.L000412f4:
/*    412f4:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    412f8:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    412fc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    41300:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    41304:	00185140 */ 	sll	$t2,$t8,0x5
/*    41308:	00087880 */ 	sll	$t7,$t0,0x2
/*    4130c:	01585023 */ 	subu	$t2,$t2,$t8
/*    41310:	01e87823 */ 	subu	$t7,$t7,$t0
/*    41314:	000e5940 */ 	sll	$t3,$t6,0x5
/*    41318:	000f7880 */ 	sll	$t7,$t7,0x2
/*    4131c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    41320:	016e5823 */ 	subu	$t3,$t3,$t6
/*    41324:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    41328:	01e87821 */ 	addu	$t7,$t7,$t0
/*    4132c:	012ac821 */ 	addu	$t9,$t1,$t2
/*    41330:	032b6821 */ 	addu	$t5,$t9,$t3
/*    41334:	000f7880 */ 	sll	$t7,$t7,0x2
/*    41338:	01af6021 */ 	addu	$t4,$t5,$t7
/*    4133c:	ad803d94 */ 	sw	$zero,0x3d94($t4)
/*    41340:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    41344:	27090001 */ 	addiu	$t1,$t8,0x1
/*    41348:	29210003 */ 	slti	$at,$t1,0x3
/*    4134c:	1420ffe9 */ 	bnez	$at,.L000412f4
/*    41350:	afa9002c */ 	sw	$t1,0x2c($sp)
/*    41354:	100000a1 */ 	b	.L000415dc
/*    41358:	00000000 */ 	nop
.L0004135c:
/*    4135c:	afa00034 */ 	sw	$zero,0x34($sp)
.L00041360:
/*    41360:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    41364:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    41368:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    4136c:	000ec9c0 */ 	sll	$t9,$t6,0x7
/*    41370:	01595821 */ 	addu	$t3,$t2,$t9
/*    41374:	00086880 */ 	sll	$t5,$t0,0x2
/*    41378:	016d7821 */ 	addu	$t7,$t3,$t5
/*    4137c:	8dec3bf8 */ 	lw	$t4,0x3bf8($t7)
/*    41380:	11800004 */ 	beqz	$t4,.L00041394
/*    41384:	00000000 */ 	nop
/*    41388:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    4138c:	17000063 */ 	bnez	$t8,.L0004151c
/*    41390:	00000000 */ 	nop
.L00041394:
/*    41394:	8fa90034 */ 	lw	$t1,0x34($sp)
/*    41398:	3c0e7005 */ 	lui	$t6,%hi(var70057b74)
/*    4139c:	25ce7b74 */ 	addiu	$t6,$t6,%lo(var70057b74)
/*    413a0:	012e5021 */ 	addu	$t2,$t1,$t6
/*    413a4:	91590000 */ 	lbu	$t9,0x0($t2)
/*    413a8:	afb90030 */ 	sw	$t9,0x30($sp)
/*    413ac:	91480001 */ 	lbu	$t0,0x1($t2)
/*    413b0:	0328082a */ 	slt	$at,$t9,$t0
/*    413b4:	10200057 */ 	beqz	$at,.L00041514
/*    413b8:	00000000 */ 	nop
.L000413bc:
/*    413bc:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    413c0:	29610002 */ 	slti	$at,$t3,0x2
/*    413c4:	10200003 */ 	beqz	$at,.L000413d4
/*    413c8:	00000000 */ 	nop
/*    413cc:	10000002 */ 	b	.L000413d8
/*    413d0:	00008025 */ 	or	$s0,$zero,$zero
.L000413d4:
/*    413d4:	24100001 */ 	addiu	$s0,$zero,0x1
.L000413d8:
/*    413d8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    413dc:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    413e0:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    413e4:	000f6080 */ 	sll	$t4,$t7,0x2
/*    413e8:	01acc021 */ 	addu	$t8,$t5,$t4
/*    413ec:	00097080 */ 	sll	$t6,$t1,0x2
/*    413f0:	030e5021 */ 	addu	$t2,$t8,$t6
/*    413f4:	8d593c90 */ 	lw	$t9,0x3c90($t2)
/*    413f8:	00104100 */ 	sll	$t0,$s0,0x4
/*    413fc:	3c0f7005 */ 	lui	$t7,%hi(var70057b7c)
/*    41400:	01195821 */ 	addu	$t3,$t0,$t9
/*    41404:	01eb7821 */ 	addu	$t7,$t7,$t3
/*    41408:	91ef7b7c */ 	lbu	$t7,%lo(var70057b7c)($t7)
/*    4140c:	11e00028 */ 	beqz	$t7,.L000414b0
/*    41410:	00000000 */ 	nop
/*    41414:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    41418:	29a10002 */ 	slti	$at,$t5,0x2
/*    4141c:	10200003 */ 	beqz	$at,.L0004142c
/*    41420:	00000000 */ 	nop
/*    41424:	10000002 */ 	b	.L00041430
/*    41428:	00008825 */ 	or	$s1,$zero,$zero
.L0004142c:
/*    4142c:	24110001 */ 	addiu	$s1,$zero,0x1
.L00041430:
/*    41430:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    41434:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    41438:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    4143c:	0009c080 */ 	sll	$t8,$t1,0x2
/*    41440:	01987021 */ 	addu	$t6,$t4,$t8
/*    41444:	000a4080 */ 	sll	$t0,$t2,0x2
/*    41448:	01c8c821 */ 	addu	$t9,$t6,$t0
/*    4144c:	8f2b3c90 */ 	lw	$t3,0x3c90($t9)
/*    41450:	00117900 */ 	sll	$t7,$s1,0x4
/*    41454:	3c067005 */ 	lui	$a2,%hi(var70057b7c)
/*    41458:	01eb6821 */ 	addu	$t5,$t7,$t3
/*    4145c:	00cd3021 */ 	addu	$a2,$a2,$t5
/*    41460:	90c67b7c */ 	lbu	$a2,%lo(var70057b7c)($a2)
/*    41464:	2584001c */ 	addiu	$a0,$t4,0x1c
/*    41468:	0c0118b1 */ 	jal	func000462c4
/*    4146c:	25852020 */ 	addiu	$a1,$t4,0x2020
/*    41470:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    41474:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    41478:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    4147c:	000cc140 */ 	sll	$t8,$t4,0x5
/*    41480:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    41484:	030cc023 */ 	subu	$t8,$t8,$t4
/*    41488:	000e4140 */ 	sll	$t0,$t6,0x5
/*    4148c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    41490:	010e4023 */ 	subu	$t0,$t0,$t6
/*    41494:	000840c0 */ 	sll	$t0,$t0,0x3
/*    41498:	01385021 */ 	addu	$t2,$t1,$t8
/*    4149c:	0148c821 */ 	addu	$t9,$t2,$t0
/*    414a0:	000f5880 */ 	sll	$t3,$t7,0x2
/*    414a4:	032b6821 */ 	addu	$t5,$t9,$t3
/*    414a8:	10000010 */ 	b	.L000414ec
/*    414ac:	ada23d08 */ 	sw	$v0,0x3d08($t5)
.L000414b0:
/*    414b0:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    414b4:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    414b8:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    414bc:	0009c140 */ 	sll	$t8,$t1,0x5
/*    414c0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    414c4:	0309c023 */ 	subu	$t8,$t8,$t1
/*    414c8:	000a4140 */ 	sll	$t0,$t2,0x5
/*    414cc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    414d0:	010a4023 */ 	subu	$t0,$t0,$t2
/*    414d4:	000840c0 */ 	sll	$t0,$t0,0x3
/*    414d8:	01987021 */ 	addu	$t6,$t4,$t8
/*    414dc:	01c87821 */ 	addu	$t7,$t6,$t0
/*    414e0:	00195880 */ 	sll	$t3,$t9,0x2
/*    414e4:	01eb6821 */ 	addu	$t5,$t7,$t3
/*    414e8:	ada03d08 */ 	sw	$zero,0x3d08($t5)
.L000414ec:
/*    414ec:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    414f0:	3c0a7005 */ 	lui	$t2,%hi(var70057b74+0x1)
/*    414f4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    414f8:	01585021 */ 	addu	$t2,$t2,$t8
/*    414fc:	914a7b75 */ 	lbu	$t2,%lo(var70057b74+0x1)($t2)
/*    41500:	252c0001 */ 	addiu	$t4,$t1,0x1
/*    41504:	afac0030 */ 	sw	$t4,0x30($sp)
/*    41508:	018a082a */ 	slt	$at,$t4,$t2
/*    4150c:	1420ffab */ 	bnez	$at,.L000413bc
/*    41510:	00000000 */ 	nop
.L00041514:
/*    41514:	10000020 */ 	b	.L00041598
/*    41518:	00000000 */ 	nop
.L0004151c:
/*    4151c:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    41520:	3c087005 */ 	lui	$t0,%hi(var70057b74)
/*    41524:	25087b74 */ 	addiu	$t0,$t0,%lo(var70057b74)
/*    41528:	01c8c821 */ 	addu	$t9,$t6,$t0
/*    4152c:	932f0000 */ 	lbu	$t7,0x0($t9)
/*    41530:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    41534:	932b0001 */ 	lbu	$t3,0x1($t9)
/*    41538:	01eb082a */ 	slt	$at,$t7,$t3
/*    4153c:	10200016 */ 	beqz	$at,.L00041598
/*    41540:	00000000 */ 	nop
.L00041544:
/*    41544:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    41548:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    4154c:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    41550:	0009c140 */ 	sll	$t8,$t1,0x5
/*    41554:	0309c023 */ 	subu	$t8,$t8,$t1
/*    41558:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    4155c:	01b86021 */ 	addu	$t4,$t5,$t8
/*    41560:	000a7080 */ 	sll	$t6,$t2,0x2
/*    41564:	018e4021 */ 	addu	$t0,$t4,$t6
/*    41568:	8d193d08 */ 	lw	$t9,0x3d08($t0)
/*    4156c:	ad193e00 */ 	sw	$t9,0x3e00($t0)
/*    41570:	8fa90034 */ 	lw	$t1,0x34($sp)
/*    41574:	3c0d7005 */ 	lui	$t5,%hi(var70057b74+0x1)
/*    41578:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    4157c:	01a96821 */ 	addu	$t5,$t5,$t1
/*    41580:	91ad7b75 */ 	lbu	$t5,%lo(var70057b74+0x1)($t5)
/*    41584:	25eb0001 */ 	addiu	$t3,$t7,0x1
/*    41588:	afab0030 */ 	sw	$t3,0x30($sp)
/*    4158c:	016d082a */ 	slt	$at,$t3,$t5
/*    41590:	1420ffec */ 	bnez	$at,.L00041544
/*    41594:	00000000 */ 	nop
.L00041598:
/*    41598:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    4159c:	270a0001 */ 	addiu	$t2,$t8,0x1
/*    415a0:	29410004 */ 	slti	$at,$t2,0x4
/*    415a4:	1420ff6e */ 	bnez	$at,.L00041360
/*    415a8:	afaa0034 */ 	sw	$t2,0x34($sp)
/*    415ac:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    415b0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    415b4:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    415b8:	000ec940 */ 	sll	$t9,$t6,0x5
/*    415bc:	032ec823 */ 	subu	$t9,$t9,$t6
/*    415c0:	000f4940 */ 	sll	$t1,$t7,0x5
/*    415c4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    415c8:	012f4823 */ 	subu	$t1,$t1,$t7
/*    415cc:	000948c0 */ 	sll	$t1,$t1,0x3
/*    415d0:	01994021 */ 	addu	$t0,$t4,$t9
/*    415d4:	01095821 */ 	addu	$t3,$t0,$t1
/*    415d8:	ad603d60 */ 	sw	$zero,0x3d60($t3)
.L000415dc:
/*    415dc:	10000003 */ 	b	.L000415ec
/*    415e0:	24020001 */ 	addiu	$v0,$zero,0x1
/*    415e4:	10000001 */ 	b	.L000415ec
/*    415e8:	00000000 */ 	nop
.L000415ec:
/*    415ec:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    415f0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    415f4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    415f8:	03e00008 */ 	jr	$ra
/*    415fc:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func00041600
/*    41600:	27bdfe70 */ 	addiu	$sp,$sp,-400
/*    41604:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    41608:	afa40190 */ 	sw	$a0,0x190($sp)
/*    4160c:	afa50194 */ 	sw	$a1,0x194($sp)
/*    41610:	afa60198 */ 	sw	$a2,0x198($sp)
/*    41614:	3c0f7006 */ 	lui	$t7,%hi(var70059b34)
/*    41618:	25ef9b34 */ 	addiu	$t7,$t7,%lo(var70059b34)
/*    4161c:	25e80120 */ 	addiu	$t0,$t7,0x120
/*    41620:	27ae0070 */ 	addiu	$t6,$sp,0x70
.L00041624:
/*    41624:	8df90000 */ 	lw	$t9,0x0($t7)
/*    41628:	25ef000c */ 	addiu	$t7,$t7,0xc
/*    4162c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*    41630:	add9fff4 */ 	sw	$t9,-0xc($t6)
/*    41634:	8df8fff8 */ 	lw	$t8,-0x8($t7)
/*    41638:	add8fff8 */ 	sw	$t8,-0x8($t6)
/*    4163c:	8df9fffc */ 	lw	$t9,-0x4($t7)
/*    41640:	15e8fff8 */ 	bne	$t7,$t0,.L00041624
/*    41644:	add9fffc */ 	sw	$t9,-0x4($t6)
/*    41648:	8faa0198 */ 	lw	$t2,0x198($sp)
/*    4164c:	8fa90190 */ 	lw	$t1,0x190($sp)
/*    41650:	000a5880 */ 	sll	$t3,$t2,0x2
/*    41654:	012b6021 */ 	addu	$t4,$t1,$t3
/*    41658:	8d8d3c90 */ 	lw	$t5,0x3c90($t4)
/*    4165c:	afad005c */ 	sw	$t5,0x5c($sp)
/*    41660:	8faf0198 */ 	lw	$t7,0x198($sp)
/*    41664:	8fa80190 */ 	lw	$t0,0x190($sp)
/*    41668:	000f7080 */ 	sll	$t6,$t7,0x2
/*    4166c:	010ec021 */ 	addu	$t8,$t0,$t6
/*    41670:	27193cf0 */ 	addiu	$t9,$t8,0x3cf0
/*    41674:	afb90058 */ 	sw	$t9,0x58($sp)
/*    41678:	8fa90198 */ 	lw	$t1,0x198($sp)
/*    4167c:	8faa0190 */ 	lw	$t2,0x190($sp)
/*    41680:	00095880 */ 	sll	$t3,$t1,0x2
/*    41684:	014b6021 */ 	addu	$t4,$t2,$t3
/*    41688:	8d8d3ca8 */ 	lw	$t5,0x3ca8($t4)
/*    4168c:	afad0054 */ 	sw	$t5,0x54($sp)
/*    41690:	8fa80198 */ 	lw	$t0,0x198($sp)
/*    41694:	8faf0190 */ 	lw	$t7,0x190($sp)
/*    41698:	00087080 */ 	sll	$t6,$t0,0x2
/*    4169c:	01eec021 */ 	addu	$t8,$t7,$t6
/*    416a0:	8f193ca0 */ 	lw	$t9,0x3ca0($t8)
/*    416a4:	afb90050 */ 	sw	$t9,0x50($sp)
/*    416a8:	8faa0198 */ 	lw	$t2,0x198($sp)
/*    416ac:	8fa90190 */ 	lw	$t1,0x190($sp)
/*    416b0:	000a5880 */ 	sll	$t3,$t2,0x2
/*    416b4:	012b6021 */ 	addu	$t4,$t1,$t3
/*    416b8:	8d8d3c98 */ 	lw	$t5,0x3c98($t4)
/*    416bc:	afad004c */ 	sw	$t5,0x4c($sp)
/*    416c0:	8fa80190 */ 	lw	$t0,0x190($sp)
/*    416c4:	24010001 */ 	addiu	$at,$zero,0x1
/*    416c8:	8d0f3bc4 */ 	lw	$t7,0x3bc4($t0)
/*    416cc:	11e10004 */ 	beq	$t7,$at,.L000416e0
/*    416d0:	00000000 */ 	nop
/*    416d4:	24010003 */ 	addiu	$at,$zero,0x3
/*    416d8:	15e10005 */ 	bne	$t7,$at,.L000416f0
/*    416dc:	00000000 */ 	nop
.L000416e0:
/*    416e0:	8fae0198 */ 	lw	$t6,0x198($sp)
/*    416e4:	24010001 */ 	addiu	$at,$zero,0x1
/*    416e8:	11c10074 */ 	beq	$t6,$at,.L000418bc
/*    416ec:	00000000 */ 	nop
.L000416f0:
/*    416f0:	afa00048 */ 	sw	$zero,0x48($sp)
/*    416f4:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    416f8:	2b010190 */ 	slti	$at,$t8,0x190
/*    416fc:	10200026 */ 	beqz	$at,.L00041798
/*    41700:	00000000 */ 	nop
/*    41704:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    41708:	24010005 */ 	addiu	$at,$zero,0x5
/*    4170c:	27ab0060 */ 	addiu	$t3,$sp,0x60
/*    41710:	00195103 */ 	sra	$t2,$t9,0x4
/*    41714:	0141001a */ 	div	$zero,$t2,$at
/*    41718:	00004812 */ 	mflo	$t1
/*    4171c:	ad690000 */ 	sw	$t1,0x0($t3)
/*    41720:	00000000 */ 	nop
/*    41724:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    41728:	24010005 */ 	addiu	$at,$zero,0x5
/*    4172c:	27af0060 */ 	addiu	$t7,$sp,0x60
/*    41730:	000c6903 */ 	sra	$t5,$t4,0x4
/*    41734:	01a1001a */ 	div	$zero,$t5,$at
/*    41738:	00004010 */ 	mfhi	$t0
/*    4173c:	ade80004 */ 	sw	$t0,0x4($t7)
/*    41740:	00000000 */ 	nop
/*    41744:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    41748:	27aa0060 */ 	addiu	$t2,$sp,0x60
/*    4174c:	05c10004 */ 	bgez	$t6,.L00041760
/*    41750:	31d8000f */ 	andi	$t8,$t6,0xf
/*    41754:	13000002 */ 	beqz	$t8,.L00041760
/*    41758:	00000000 */ 	nop
/*    4175c:	2718fff0 */ 	addiu	$t8,$t8,-16
.L00041760:
/*    41760:	0018c883 */ 	sra	$t9,$t8,0x2
/*    41764:	ad590008 */ 	sw	$t9,0x8($t2)
/*    41768:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    4176c:	27ac0060 */ 	addiu	$t4,$sp,0x60
/*    41770:	05210004 */ 	bgez	$t1,.L00041784
/*    41774:	312b0003 */ 	andi	$t3,$t1,0x3
/*    41778:	11600002 */ 	beqz	$t3,.L00041784
/*    4177c:	00000000 */ 	nop
/*    41780:	256bfffc */ 	addiu	$t3,$t3,-4
.L00041784:
/*    41784:	ad8b000c */ 	sw	$t3,0xc($t4)
/*    41788:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    4178c:	ada00000 */ 	sw	$zero,0x0($t5)
/*    41790:	1000004a */ 	b	.L000418bc
/*    41794:	afa00044 */ 	sw	$zero,0x44($sp)
.L00041798:
/*    41798:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    4179c:	29010190 */ 	slti	$at,$t0,0x190
/*    417a0:	14200026 */ 	bnez	$at,.L0004183c
/*    417a4:	00000000 */ 	nop
/*    417a8:	290101f4 */ 	slti	$at,$t0,0x1f4
/*    417ac:	10200023 */ 	beqz	$at,.L0004183c
/*    417b0:	00000000 */ 	nop
/*    417b4:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    417b8:	24010005 */ 	addiu	$at,$zero,0x5
/*    417bc:	27aa0060 */ 	addiu	$t2,$sp,0x60
/*    417c0:	25eefe70 */ 	addiu	$t6,$t7,-400
/*    417c4:	000ec083 */ 	sra	$t8,$t6,0x2
/*    417c8:	0301001a */ 	div	$zero,$t8,$at
/*    417cc:	0000c812 */ 	mflo	$t9
/*    417d0:	ad590000 */ 	sw	$t9,0x0($t2)
/*    417d4:	00000000 */ 	nop
/*    417d8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    417dc:	24010005 */ 	addiu	$at,$zero,0x5
/*    417e0:	27a80060 */ 	addiu	$t0,$sp,0x60
/*    417e4:	252bfe70 */ 	addiu	$t3,$t1,-400
/*    417e8:	000b6083 */ 	sra	$t4,$t3,0x2
/*    417ec:	0181001a */ 	div	$zero,$t4,$at
/*    417f0:	00006810 */ 	mfhi	$t5
/*    417f4:	ad0d0004 */ 	sw	$t5,0x4($t0)
/*    417f8:	00000000 */ 	nop
/*    417fc:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    41800:	27b90060 */ 	addiu	$t9,$sp,0x60
/*    41804:	25eefe70 */ 	addiu	$t6,$t7,-400
/*    41808:	05c10004 */ 	bgez	$t6,.L0004181c
/*    4180c:	31d80003 */ 	andi	$t8,$t6,0x3
/*    41810:	13000002 */ 	beqz	$t8,.L0004181c
/*    41814:	00000000 */ 	nop
/*    41818:	2718fffc */ 	addiu	$t8,$t8,-4
.L0004181c:
/*    4181c:	af380008 */ 	sw	$t8,0x8($t9)
/*    41820:	27aa0060 */ 	addiu	$t2,$sp,0x60
/*    41824:	ad40000c */ 	sw	$zero,0xc($t2)
/*    41828:	8fa90058 */ 	lw	$t1,0x58($sp)
/*    4182c:	ad200000 */ 	sw	$zero,0x0($t1)
/*    41830:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    41834:	10000021 */ 	b	.L000418bc
/*    41838:	afab0044 */ 	sw	$t3,0x44($sp)
.L0004183c:
/*    4183c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    41840:	298101f4 */ 	slti	$at,$t4,0x1f4
/*    41844:	1420001d */ 	bnez	$at,.L000418bc
/*    41848:	00000000 */ 	nop
/*    4184c:	29810200 */ 	slti	$at,$t4,0x200
/*    41850:	1020001a */ 	beqz	$at,.L000418bc
/*    41854:	00000000 */ 	nop
/*    41858:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    4185c:	24010003 */ 	addiu	$at,$zero,0x3
/*    41860:	27ae0060 */ 	addiu	$t6,$sp,0x60
/*    41864:	25a8fe0c */ 	addiu	$t0,$t5,-500
/*    41868:	0101001a */ 	div	$zero,$t0,$at
/*    4186c:	00007812 */ 	mflo	$t7
/*    41870:	adcf0000 */ 	sw	$t7,0x0($t6)
/*    41874:	00000000 */ 	nop
/*    41878:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    4187c:	24010003 */ 	addiu	$at,$zero,0x3
/*    41880:	27a90060 */ 	addiu	$t1,$sp,0x60
/*    41884:	2719fe0c */ 	addiu	$t9,$t8,-500
/*    41888:	0321001a */ 	div	$zero,$t9,$at
/*    4188c:	00005010 */ 	mfhi	$t2
/*    41890:	ad2a0004 */ 	sw	$t2,0x4($t1)
/*    41894:	00000000 */ 	nop
/*    41898:	27ab0060 */ 	addiu	$t3,$sp,0x60
/*    4189c:	ad600008 */ 	sw	$zero,0x8($t3)
/*    418a0:	27ac0060 */ 	addiu	$t4,$sp,0x60
/*    418a4:	ad80000c */ 	sw	$zero,0xc($t4)
/*    418a8:	8fa80058 */ 	lw	$t0,0x58($sp)
/*    418ac:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    418b0:	ad0d0000 */ 	sw	$t5,0x0($t0)
/*    418b4:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    418b8:	afaf0044 */ 	sw	$t7,0x44($sp)
.L000418bc:
/*    418bc:	8fae0190 */ 	lw	$t6,0x190($sp)
/*    418c0:	24010001 */ 	addiu	$at,$zero,0x1
/*    418c4:	8dd83bc4 */ 	lw	$t8,0x3bc4($t6)
/*    418c8:	13010004 */ 	beq	$t8,$at,.L000418dc
/*    418cc:	00000000 */ 	nop
/*    418d0:	24010003 */ 	addiu	$at,$zero,0x3
/*    418d4:	17010083 */ 	bne	$t8,$at,.L00041ae4
/*    418d8:	00000000 */ 	nop
.L000418dc:
/*    418dc:	8fb90198 */ 	lw	$t9,0x198($sp)
/*    418e0:	24010001 */ 	addiu	$at,$zero,0x1
/*    418e4:	1721007f */ 	bne	$t9,$at,.L00041ae4
/*    418e8:	00000000 */ 	nop
/*    418ec:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    418f0:	8fab0190 */ 	lw	$t3,0x190($sp)
/*    418f4:	05410004 */ 	bgez	$t2,.L00041908
/*    418f8:	31490001 */ 	andi	$t1,$t2,0x1
/*    418fc:	11200002 */ 	beqz	$t1,.L00041908
/*    41900:	00000000 */ 	nop
/*    41904:	2529fffe */ 	addiu	$t1,$t1,-2
.L00041908:
/*    41908:	ad693ef8 */ 	sw	$t1,0x3ef8($t3)
/*    4190c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    41910:	000c6843 */ 	sra	$t5,$t4,0x1
/*    41914:	afad0038 */ 	sw	$t5,0x38($sp)
/*    41918:	24080001 */ 	addiu	$t0,$zero,0x1
/*    4191c:	afa80048 */ 	sw	$t0,0x48($sp)
/*    41920:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    41924:	29e100b4 */ 	slti	$at,$t7,0xb4
/*    41928:	10200024 */ 	beqz	$at,.L000419bc
/*    4192c:	00000000 */ 	nop
/*    41930:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    41934:	24010024 */ 	addiu	$at,$zero,0x24
/*    41938:	27b90060 */ 	addiu	$t9,$sp,0x60
/*    4193c:	01c1001a */ 	div	$zero,$t6,$at
/*    41940:	0000c012 */ 	mflo	$t8
/*    41944:	af380000 */ 	sw	$t8,0x0($t9)
/*    41948:	00000000 */ 	nop
/*    4194c:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    41950:	24010024 */ 	addiu	$at,$zero,0x24
/*    41954:	27ac0060 */ 	addiu	$t4,$sp,0x60
/*    41958:	0141001a */ 	div	$zero,$t2,$at
/*    4195c:	00004810 */ 	mfhi	$t1
/*    41960:	24010006 */ 	addiu	$at,$zero,0x6
/*    41964:	00000000 */ 	nop
/*    41968:	0121001a */ 	div	$zero,$t1,$at
/*    4196c:	00005812 */ 	mflo	$t3
/*    41970:	ad8b0004 */ 	sw	$t3,0x4($t4)
/*    41974:	00000000 */ 	nop
/*    41978:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    4197c:	24010024 */ 	addiu	$at,$zero,0x24
/*    41980:	27ae0060 */ 	addiu	$t6,$sp,0x60
/*    41984:	01a1001a */ 	div	$zero,$t5,$at
/*    41988:	00004010 */ 	mfhi	$t0
/*    4198c:	24010006 */ 	addiu	$at,$zero,0x6
/*    41990:	00000000 */ 	nop
/*    41994:	0101001a */ 	div	$zero,$t0,$at
/*    41998:	00007810 */ 	mfhi	$t7
/*    4199c:	adcf0008 */ 	sw	$t7,0x8($t6)
/*    419a0:	00000000 */ 	nop
/*    419a4:	27b80060 */ 	addiu	$t8,$sp,0x60
/*    419a8:	af00000c */ 	sw	$zero,0xc($t8)
/*    419ac:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    419b0:	af200000 */ 	sw	$zero,0x0($t9)
/*    419b4:	1000004b */ 	b	.L00041ae4
/*    419b8:	afa00044 */ 	sw	$zero,0x44($sp)
.L000419bc:
/*    419bc:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    419c0:	294100b4 */ 	slti	$at,$t2,0xb4
/*    419c4:	14200028 */ 	bnez	$at,.L00041a68
/*    419c8:	00000000 */ 	nop
/*    419cc:	294100f4 */ 	slti	$at,$t2,0xf4
/*    419d0:	10200025 */ 	beqz	$at,.L00041a68
/*    419d4:	00000000 */ 	nop
/*    419d8:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    419dc:	27a80060 */ 	addiu	$t0,$sp,0x60
/*    419e0:	252bff4c */ 	addiu	$t3,$t1,-180
/*    419e4:	05610004 */ 	bgez	$t3,.L000419f8
/*    419e8:	316c003f */ 	andi	$t4,$t3,0x3f
/*    419ec:	11800002 */ 	beqz	$t4,.L000419f8
/*    419f0:	00000000 */ 	nop
/*    419f4:	258cffc0 */ 	addiu	$t4,$t4,-64
.L000419f8:
/*    419f8:	000c6903 */ 	sra	$t5,$t4,0x4
/*    419fc:	ad0d0000 */ 	sw	$t5,0x0($t0)
/*    41a00:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    41a04:	27aa0060 */ 	addiu	$t2,$sp,0x60
/*    41a08:	25eeff4c */ 	addiu	$t6,$t7,-180
/*    41a0c:	05c10004 */ 	bgez	$t6,.L00041a20
/*    41a10:	31d8000f */ 	andi	$t8,$t6,0xf
/*    41a14:	13000002 */ 	beqz	$t8,.L00041a20
/*    41a18:	00000000 */ 	nop
/*    41a1c:	2718fff0 */ 	addiu	$t8,$t8,-16
.L00041a20:
/*    41a20:	0018c883 */ 	sra	$t9,$t8,0x2
/*    41a24:	ad590004 */ 	sw	$t9,0x4($t2)
/*    41a28:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    41a2c:	27ad0060 */ 	addiu	$t5,$sp,0x60
/*    41a30:	252bff4c */ 	addiu	$t3,$t1,-180
/*    41a34:	05610004 */ 	bgez	$t3,.L00041a48
/*    41a38:	316c0003 */ 	andi	$t4,$t3,0x3
/*    41a3c:	11800002 */ 	beqz	$t4,.L00041a48
/*    41a40:	00000000 */ 	nop
/*    41a44:	258cfffc */ 	addiu	$t4,$t4,-4
.L00041a48:
/*    41a48:	adac0008 */ 	sw	$t4,0x8($t5)
/*    41a4c:	27a80060 */ 	addiu	$t0,$sp,0x60
/*    41a50:	ad00000c */ 	sw	$zero,0xc($t0)
/*    41a54:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    41a58:	ade00000 */ 	sw	$zero,0x0($t7)
/*    41a5c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    41a60:	10000020 */ 	b	.L00041ae4
/*    41a64:	afae0044 */ 	sw	$t6,0x44($sp)
.L00041a68:
/*    41a68:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    41a6c:	2b0100f4 */ 	slti	$at,$t8,0xf4
/*    41a70:	1420001c */ 	bnez	$at,.L00041ae4
/*    41a74:	00000000 */ 	nop
/*    41a78:	2b0100ff */ 	slti	$at,$t8,0xff
/*    41a7c:	10200019 */ 	beqz	$at,.L00041ae4
/*    41a80:	00000000 */ 	nop
/*    41a84:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    41a88:	24010003 */ 	addiu	$at,$zero,0x3
/*    41a8c:	27ab0060 */ 	addiu	$t3,$sp,0x60
/*    41a90:	272aff0c */ 	addiu	$t2,$t9,-244
/*    41a94:	0141001a */ 	div	$zero,$t2,$at
/*    41a98:	00004812 */ 	mflo	$t1
/*    41a9c:	ad690000 */ 	sw	$t1,0x0($t3)
/*    41aa0:	00000000 */ 	nop
/*    41aa4:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    41aa8:	24010003 */ 	addiu	$at,$zero,0x3
/*    41aac:	27af0060 */ 	addiu	$t7,$sp,0x60
/*    41ab0:	258dff0c */ 	addiu	$t5,$t4,-244
/*    41ab4:	01a1001a */ 	div	$zero,$t5,$at
/*    41ab8:	00004010 */ 	mfhi	$t0
/*    41abc:	ade80004 */ 	sw	$t0,0x4($t7)
/*    41ac0:	00000000 */ 	nop
/*    41ac4:	27ae0060 */ 	addiu	$t6,$sp,0x60
/*    41ac8:	adc00008 */ 	sw	$zero,0x8($t6)
/*    41acc:	27b80060 */ 	addiu	$t8,$sp,0x60
/*    41ad0:	af00000c */ 	sw	$zero,0xc($t8)
/*    41ad4:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    41ad8:	af200000 */ 	sw	$zero,0x0($t9)
/*    41adc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    41ae0:	afaa0044 */ 	sw	$t2,0x44($sp)
.L00041ae4:
/*    41ae4:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    41ae8:	11200019 */ 	beqz	$t1,.L00041b50
/*    41aec:	00000000 */ 	nop
/*    41af0:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    41af4:	24010002 */ 	addiu	$at,$zero,0x2
/*    41af8:	15610015 */ 	bne	$t3,$at,.L00041b50
/*    41afc:	00000000 */ 	nop
/*    41b00:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    41b04:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    41b08:	8fb80054 */ 	lw	$t8,0x54($sp)
/*    41b0c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*    41b10:	00087880 */ 	sll	$t7,$t0,0x2
/*    41b14:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    41b18:	01e87823 */ 	subu	$t7,$t7,$t0
/*    41b1c:	000f7900 */ 	sll	$t7,$t7,0x4
/*    41b20:	000d6900 */ 	sll	$t5,$t5,0x4
/*    41b24:	01af7021 */ 	addu	$t6,$t5,$t7
/*    41b28:	0018c900 */ 	sll	$t9,$t8,0x4
/*    41b2c:	01d95021 */ 	addu	$t2,$t6,$t9
/*    41b30:	25490010 */ 	addiu	$t1,$t2,0x10
/*    41b34:	27ab0070 */ 	addiu	$t3,$sp,0x70
/*    41b38:	012b2021 */ 	addu	$a0,$t1,$t3
/*    41b3c:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    41b40:	0c012c5c */ 	jal	func0004b170
/*    41b44:	24060010 */ 	addiu	$a2,$zero,0x10
/*    41b48:	1000000f */ 	b	.L00041b88
/*    41b4c:	00000000 */ 	nop
.L00041b50:
/*    41b50:	8fac0048 */ 	lw	$t4,0x48($sp)
/*    41b54:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    41b58:	27ae0070 */ 	addiu	$t6,$sp,0x70
/*    41b5c:	000c40c0 */ 	sll	$t0,$t4,0x3
/*    41b60:	000d7880 */ 	sll	$t7,$t5,0x2
/*    41b64:	010c4021 */ 	addu	$t0,$t0,$t4
/*    41b68:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    41b6c:	000f7900 */ 	sll	$t7,$t7,0x4
/*    41b70:	00084100 */ 	sll	$t0,$t0,0x4
/*    41b74:	010fc021 */ 	addu	$t8,$t0,$t7
/*    41b78:	030e2021 */ 	addu	$a0,$t8,$t6
/*    41b7c:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    41b80:	0c012c5c */ 	jal	func0004b170
/*    41b84:	24060010 */ 	addiu	$a2,$zero,0x10
.L00041b88:
/*    41b88:	afa00024 */ 	sw	$zero,0x24($sp)
/*    41b8c:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*    41b90:	13200007 */ 	beqz	$t9,.L00041bb0
/*    41b94:	00000000 */ 	nop
/*    41b98:	13200051 */ 	beqz	$t9,.L00041ce0
/*    41b9c:	00000000 */ 	nop
/*    41ba0:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    41ba4:	24010002 */ 	addiu	$at,$zero,0x2
/*    41ba8:	1141004d */ 	beq	$t2,$at,.L00041ce0
/*    41bac:	00000000 */ 	nop
.L00041bb0:
/*    41bb0:	afa00040 */ 	sw	$zero,0x40($sp)
.L00041bb4:
/*    41bb4:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    41bb8:	00095880 */ 	sll	$t3,$t1,0x2
/*    41bbc:	03ab6021 */ 	addu	$t4,$sp,$t3
/*    41bc0:	8d8c0060 */ 	lw	$t4,0x60($t4)
/*    41bc4:	afac0020 */ 	sw	$t4,0x20($sp)
/*    41bc8:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    41bcc:	24080001 */ 	addiu	$t0,$zero,0x1
/*    41bd0:	01a87804 */ 	sllv	$t7,$t0,$t5
/*    41bd4:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    41bd8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*    41bdc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    41be0:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    41be4:	000ec880 */ 	sll	$t9,$t6,0x2
/*    41be8:	03b95021 */ 	addu	$t2,$sp,$t9
/*    41bec:	8d4a0028 */ 	lw	$t2,0x28($t2)
/*    41bf0:	19400034 */ 	blez	$t2,.L00041cc4
/*    41bf4:	00000000 */ 	nop
.L00041bf8:
/*    41bf8:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    41bfc:	11200011 */ 	beqz	$t1,.L00041c44
/*    41c00:	00000000 */ 	nop
/*    41c04:	8fab0190 */ 	lw	$t3,0x190($sp)
/*    41c08:	01203025 */ 	or	$a2,$t1,$zero
/*    41c0c:	2564001c */ 	addiu	$a0,$t3,0x1c
/*    41c10:	0c0118b1 */ 	jal	func000462c4
/*    41c14:	25652020 */ 	addiu	$a1,$t3,0x2020
/*    41c18:	8fa80198 */ 	lw	$t0,0x198($sp)
/*    41c1c:	8fac0190 */ 	lw	$t4,0x190($sp)
/*    41c20:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    41c24:	00086940 */ 	sll	$t5,$t0,0x5
/*    41c28:	01a86823 */ 	subu	$t5,$t5,$t0
/*    41c2c:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    41c30:	018d7821 */ 	addu	$t7,$t4,$t5
/*    41c34:	00187080 */ 	sll	$t6,$t8,0x2
/*    41c38:	01eec821 */ 	addu	$t9,$t7,$t6
/*    41c3c:	1000000b */ 	b	.L00041c6c
/*    41c40:	af223d08 */ 	sw	$v0,0x3d08($t9)
.L00041c44:
/*    41c44:	8fab0198 */ 	lw	$t3,0x198($sp)
/*    41c48:	8faa0190 */ 	lw	$t2,0x190($sp)
/*    41c4c:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    41c50:	000b4940 */ 	sll	$t1,$t3,0x5
/*    41c54:	012b4823 */ 	subu	$t1,$t1,$t3
/*    41c58:	000948c0 */ 	sll	$t1,$t1,0x3
/*    41c5c:	01494021 */ 	addu	$t0,$t2,$t1
/*    41c60:	000c6880 */ 	sll	$t5,$t4,0x2
/*    41c64:	010dc021 */ 	addu	$t8,$t0,$t5
/*    41c68:	af003d08 */ 	sw	$zero,0x3d08($t8)
.L00041c6c:
/*    41c6c:	8faf0198 */ 	lw	$t7,0x198($sp)
/*    41c70:	11e00007 */ 	beqz	$t7,.L00041c90
/*    41c74:	00000000 */ 	nop
/*    41c78:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    41c7c:	8fb90190 */ 	lw	$t9,0x190($sp)
/*    41c80:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    41c84:	000b5080 */ 	sll	$t2,$t3,0x2
/*    41c88:	032a4821 */ 	addu	$t1,$t9,$t2
/*    41c8c:	ad2e3efc */ 	sw	$t6,0x3efc($t1)
.L00041c90:
/*    41c90:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    41c94:	25880001 */ 	addiu	$t0,$t4,0x1
/*    41c98:	afa80024 */ 	sw	$t0,0x24($sp)
/*    41c9c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    41ca0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    41ca4:	25b80001 */ 	addiu	$t8,$t5,0x1
/*    41ca8:	000f5880 */ 	sll	$t3,$t7,0x2
/*    41cac:	03abc821 */ 	addu	$t9,$sp,$t3
/*    41cb0:	afb8003c */ 	sw	$t8,0x3c($sp)
/*    41cb4:	8f390028 */ 	lw	$t9,0x28($t9)
/*    41cb8:	0319082a */ 	slt	$at,$t8,$t9
/*    41cbc:	1420ffce */ 	bnez	$at,.L00041bf8
/*    41cc0:	00000000 */ 	nop
.L00041cc4:
/*    41cc4:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    41cc8:	254e0001 */ 	addiu	$t6,$t2,0x1
/*    41ccc:	29c10004 */ 	slti	$at,$t6,0x4
/*    41cd0:	1420ffb8 */ 	bnez	$at,.L00041bb4
/*    41cd4:	afae0040 */ 	sw	$t6,0x40($sp)
/*    41cd8:	1000014f */ 	b	.L00042218
/*    41cdc:	00000000 */ 	nop
.L00041ce0:
/*    41ce0:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    41ce4:	24010002 */ 	addiu	$at,$zero,0x2
/*    41ce8:	1521014b */ 	bne	$t1,$at,.L00042218
/*    41cec:	00000000 */ 	nop
/*    41cf0:	8fac0054 */ 	lw	$t4,0x54($sp)
/*    41cf4:	15800087 */ 	bnez	$t4,.L00041f14
/*    41cf8:	00000000 */ 	nop
/*    41cfc:	afa00040 */ 	sw	$zero,0x40($sp)
.L00041d00:
/*    41d00:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    41d04:	00086880 */ 	sll	$t5,$t0,0x2
/*    41d08:	03ad7821 */ 	addu	$t7,$sp,$t5
/*    41d0c:	8def0060 */ 	lw	$t7,0x60($t7)
/*    41d10:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    41d14:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    41d18:	24180001 */ 	addiu	$t8,$zero,0x1
/*    41d1c:	0178c804 */ 	sllv	$t9,$t8,$t3
/*    41d20:	272affff */ 	addiu	$t2,$t9,-1
/*    41d24:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    41d28:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    41d2c:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    41d30:	000e4880 */ 	sll	$t1,$t6,0x2
/*    41d34:	03a96021 */ 	addu	$t4,$sp,$t1
/*    41d38:	8d8c0028 */ 	lw	$t4,0x28($t4)
/*    41d3c:	1980006e */ 	blez	$t4,.L00041ef8
/*    41d40:	00000000 */ 	nop
.L00041d44:
/*    41d44:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    41d48:	11000011 */ 	beqz	$t0,.L00041d90
/*    41d4c:	00000000 */ 	nop
/*    41d50:	8fad0190 */ 	lw	$t5,0x190($sp)
/*    41d54:	01003025 */ 	or	$a2,$t0,$zero
/*    41d58:	25a4001c */ 	addiu	$a0,$t5,0x1c
/*    41d5c:	0c0118b1 */ 	jal	func000462c4
/*    41d60:	25a52020 */ 	addiu	$a1,$t5,0x2020
/*    41d64:	8fb80198 */ 	lw	$t8,0x198($sp)
/*    41d68:	8faf0190 */ 	lw	$t7,0x190($sp)
/*    41d6c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    41d70:	00185940 */ 	sll	$t3,$t8,0x5
/*    41d74:	01785823 */ 	subu	$t3,$t3,$t8
/*    41d78:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    41d7c:	01ebc821 */ 	addu	$t9,$t7,$t3
/*    41d80:	000a7080 */ 	sll	$t6,$t2,0x2
/*    41d84:	032e4821 */ 	addu	$t1,$t9,$t6
/*    41d88:	1000000b */ 	b	.L00041db8
/*    41d8c:	ad223d64 */ 	sw	$v0,0x3d64($t1)
.L00041d90:
/*    41d90:	8fad0198 */ 	lw	$t5,0x198($sp)
/*    41d94:	8fac0190 */ 	lw	$t4,0x190($sp)
/*    41d98:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    41d9c:	000d4140 */ 	sll	$t0,$t5,0x5
/*    41da0:	010d4023 */ 	subu	$t0,$t0,$t5
/*    41da4:	000840c0 */ 	sll	$t0,$t0,0x3
/*    41da8:	0188c021 */ 	addu	$t8,$t4,$t0
/*    41dac:	000f5880 */ 	sll	$t3,$t7,0x2
/*    41db0:	030b5021 */ 	addu	$t2,$t8,$t3
/*    41db4:	ad403d64 */ 	sw	$zero,0x3d64($t2)
.L00041db8:
/*    41db8:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    41dbc:	13200011 */ 	beqz	$t9,.L00041e04
/*    41dc0:	00000000 */ 	nop
/*    41dc4:	8fae0190 */ 	lw	$t6,0x190($sp)
/*    41dc8:	03203025 */ 	or	$a2,$t9,$zero
/*    41dcc:	25c4001c */ 	addiu	$a0,$t6,0x1c
/*    41dd0:	0c0118b1 */ 	jal	func000462c4
/*    41dd4:	25c52020 */ 	addiu	$a1,$t6,0x2020
/*    41dd8:	8fad0198 */ 	lw	$t5,0x198($sp)
/*    41ddc:	8fa90190 */ 	lw	$t1,0x190($sp)
/*    41de0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    41de4:	000d6140 */ 	sll	$t4,$t5,0x5
/*    41de8:	018d6023 */ 	subu	$t4,$t4,$t5
/*    41dec:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    41df0:	012c4021 */ 	addu	$t0,$t1,$t4
/*    41df4:	000fc080 */ 	sll	$t8,$t7,0x2
/*    41df8:	01185821 */ 	addu	$t3,$t0,$t8
/*    41dfc:	1000000b */ 	b	.L00041e2c
/*    41e00:	ad623d98 */ 	sw	$v0,0x3d98($t3)
.L00041e04:
/*    41e04:	8fae0198 */ 	lw	$t6,0x198($sp)
/*    41e08:	8faa0190 */ 	lw	$t2,0x190($sp)
/*    41e0c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    41e10:	000ec940 */ 	sll	$t9,$t6,0x5
/*    41e14:	032ec823 */ 	subu	$t9,$t9,$t6
/*    41e18:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    41e1c:	01596821 */ 	addu	$t5,$t2,$t9
/*    41e20:	00096080 */ 	sll	$t4,$t1,0x2
/*    41e24:	01ac7821 */ 	addu	$t7,$t5,$t4
/*    41e28:	ade03d98 */ 	sw	$zero,0x3d98($t7)
.L00041e2c:
/*    41e2c:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    41e30:	11000011 */ 	beqz	$t0,.L00041e78
/*    41e34:	00000000 */ 	nop
/*    41e38:	8fb80190 */ 	lw	$t8,0x190($sp)
/*    41e3c:	01003025 */ 	or	$a2,$t0,$zero
/*    41e40:	2704001c */ 	addiu	$a0,$t8,0x1c
/*    41e44:	0c0118b1 */ 	jal	func000462c4
/*    41e48:	27052020 */ 	addiu	$a1,$t8,0x2020
/*    41e4c:	8fae0198 */ 	lw	$t6,0x198($sp)
/*    41e50:	8fab0190 */ 	lw	$t3,0x190($sp)
/*    41e54:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    41e58:	000e5140 */ 	sll	$t2,$t6,0x5
/*    41e5c:	014e5023 */ 	subu	$t2,$t2,$t6
/*    41e60:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    41e64:	016ac821 */ 	addu	$t9,$t3,$t2
/*    41e68:	00096880 */ 	sll	$t5,$t1,0x2
/*    41e6c:	032d6021 */ 	addu	$t4,$t9,$t5
/*    41e70:	1000000b */ 	b	.L00041ea0
/*    41e74:	ad823dcc */ 	sw	$v0,0x3dcc($t4)
.L00041e78:
/*    41e78:	8fb80198 */ 	lw	$t8,0x198($sp)
/*    41e7c:	8faf0190 */ 	lw	$t7,0x190($sp)
/*    41e80:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    41e84:	00184140 */ 	sll	$t0,$t8,0x5
/*    41e88:	01184023 */ 	subu	$t0,$t0,$t8
/*    41e8c:	000840c0 */ 	sll	$t0,$t0,0x3
/*    41e90:	01e87021 */ 	addu	$t6,$t7,$t0
/*    41e94:	000b5080 */ 	sll	$t2,$t3,0x2
/*    41e98:	01ca4821 */ 	addu	$t1,$t6,$t2
/*    41e9c:	ad203dcc */ 	sw	$zero,0x3dcc($t1)
.L00041ea0:
/*    41ea0:	8fb90198 */ 	lw	$t9,0x198($sp)
/*    41ea4:	13200007 */ 	beqz	$t9,.L00041ec4
/*    41ea8:	00000000 */ 	nop
/*    41eac:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    41eb0:	8fac0190 */ 	lw	$t4,0x190($sp)
/*    41eb4:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    41eb8:	00187880 */ 	sll	$t7,$t8,0x2
/*    41ebc:	018f4021 */ 	addu	$t0,$t4,$t7
/*    41ec0:	ad0d3f14 */ 	sw	$t5,0x3f14($t0)
.L00041ec4:
/*    41ec4:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    41ec8:	256e0001 */ 	addiu	$t6,$t3,0x1
/*    41ecc:	afae0024 */ 	sw	$t6,0x24($sp)
/*    41ed0:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    41ed4:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    41ed8:	25490003 */ 	addiu	$t1,$t2,0x3
/*    41edc:	0019c080 */ 	sll	$t8,$t9,0x2
/*    41ee0:	03b86021 */ 	addu	$t4,$sp,$t8
/*    41ee4:	afa9003c */ 	sw	$t1,0x3c($sp)
/*    41ee8:	8d8c0028 */ 	lw	$t4,0x28($t4)
/*    41eec:	012c082a */ 	slt	$at,$t1,$t4
/*    41ef0:	1420ff94 */ 	bnez	$at,.L00041d44
/*    41ef4:	00000000 */ 	nop
.L00041ef8:
/*    41ef8:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    41efc:	25ed0001 */ 	addiu	$t5,$t7,0x1
/*    41f00:	29a10004 */ 	slti	$at,$t5,0x4
/*    41f04:	1420ff7e */ 	bnez	$at,.L00041d00
/*    41f08:	afad0040 */ 	sw	$t5,0x40($sp)
/*    41f0c:	100000c2 */ 	b	.L00042218
/*    41f10:	00000000 */ 	nop
.L00041f14:
/*    41f14:	27a80060 */ 	addiu	$t0,$sp,0x60
/*    41f18:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*    41f1c:	afab0020 */ 	sw	$t3,0x20($sp)
/*    41f20:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    41f24:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    41f28:	01cac804 */ 	sllv	$t9,$t2,$t6
/*    41f2c:	2738ffff */ 	addiu	$t8,$t9,-1
/*    41f30:	afb8001c */ 	sw	$t8,0x1c($sp)
/*    41f34:	afa0003c */ 	sw	$zero,0x3c($sp)
.L00041f38:
/*    41f38:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    41f3c:	11200011 */ 	beqz	$t1,.L00041f84
/*    41f40:	00000000 */ 	nop
/*    41f44:	8fac0190 */ 	lw	$t4,0x190($sp)
/*    41f48:	01203025 */ 	or	$a2,$t1,$zero
/*    41f4c:	2584001c */ 	addiu	$a0,$t4,0x1c
/*    41f50:	0c0118b1 */ 	jal	func000462c4
/*    41f54:	25852020 */ 	addiu	$a1,$t4,0x2020
/*    41f58:	8fad0198 */ 	lw	$t5,0x198($sp)
/*    41f5c:	8faf0190 */ 	lw	$t7,0x190($sp)
/*    41f60:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    41f64:	000d4140 */ 	sll	$t0,$t5,0x5
/*    41f68:	010d4023 */ 	subu	$t0,$t0,$t5
/*    41f6c:	000840c0 */ 	sll	$t0,$t0,0x3
/*    41f70:	01e85821 */ 	addu	$t3,$t7,$t0
/*    41f74:	000a7080 */ 	sll	$t6,$t2,0x2
/*    41f78:	016ec821 */ 	addu	$t9,$t3,$t6
/*    41f7c:	1000000b */ 	b	.L00041fac
/*    41f80:	af223d08 */ 	sw	$v0,0x3d08($t9)
.L00041f84:
/*    41f84:	8fac0198 */ 	lw	$t4,0x198($sp)
/*    41f88:	8fb80190 */ 	lw	$t8,0x190($sp)
/*    41f8c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    41f90:	000c4940 */ 	sll	$t1,$t4,0x5
/*    41f94:	012c4823 */ 	subu	$t1,$t1,$t4
/*    41f98:	000948c0 */ 	sll	$t1,$t1,0x3
/*    41f9c:	03096821 */ 	addu	$t5,$t8,$t1
/*    41fa0:	000f4080 */ 	sll	$t0,$t7,0x2
/*    41fa4:	01a85021 */ 	addu	$t2,$t5,$t0
/*    41fa8:	ad403d08 */ 	sw	$zero,0x3d08($t2)
.L00041fac:
/*    41fac:	8fab0198 */ 	lw	$t3,0x198($sp)
/*    41fb0:	11600007 */ 	beqz	$t3,.L00041fd0
/*    41fb4:	00000000 */ 	nop
/*    41fb8:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    41fbc:	8fb90190 */ 	lw	$t9,0x190($sp)
/*    41fc0:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    41fc4:	000cc080 */ 	sll	$t8,$t4,0x2
/*    41fc8:	03384821 */ 	addu	$t1,$t9,$t8
/*    41fcc:	ad2e3efc */ 	sw	$t6,0x3efc($t1)
.L00041fd0:
/*    41fd0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    41fd4:	25ed0001 */ 	addiu	$t5,$t7,0x1
/*    41fd8:	afad0024 */ 	sw	$t5,0x24($sp)
/*    41fdc:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    41fe0:	250a0001 */ 	addiu	$t2,$t0,0x1
/*    41fe4:	29410006 */ 	slti	$at,$t2,0x6
/*    41fe8:	1420ffd3 */ 	bnez	$at,.L00041f38
/*    41fec:	afaa003c */ 	sw	$t2,0x3c($sp)
/*    41ff0:	27ab0028 */ 	addiu	$t3,$sp,0x28
/*    41ff4:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    41ff8:	2599fffa */ 	addiu	$t9,$t4,-6
/*    41ffc:	ad790000 */ 	sw	$t9,0x0($t3)
/*    42000:	24180003 */ 	addiu	$t8,$zero,0x3
/*    42004:	afb80024 */ 	sw	$t8,0x24($sp)
/*    42008:	afa00040 */ 	sw	$zero,0x40($sp)
.L0004200c:
/*    4200c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    42010:	000e4880 */ 	sll	$t1,$t6,0x2
/*    42014:	03a97821 */ 	addu	$t7,$sp,$t1
/*    42018:	8def0060 */ 	lw	$t7,0x60($t7)
/*    4201c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    42020:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    42024:	24080001 */ 	addiu	$t0,$zero,0x1
/*    42028:	01a85004 */ 	sllv	$t2,$t0,$t5
/*    4202c:	254cffff */ 	addiu	$t4,$t2,-1
/*    42030:	afac001c */ 	sw	$t4,0x1c($sp)
/*    42034:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    42038:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    4203c:	00195880 */ 	sll	$t3,$t9,0x2
/*    42040:	03abc021 */ 	addu	$t8,$sp,$t3
/*    42044:	8f180028 */ 	lw	$t8,0x28($t8)
/*    42048:	1b00006e */ 	blez	$t8,.L00042204
/*    4204c:	00000000 */ 	nop
.L00042050:
/*    42050:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    42054:	11c00011 */ 	beqz	$t6,.L0004209c
/*    42058:	00000000 */ 	nop
/*    4205c:	8fa90190 */ 	lw	$t1,0x190($sp)
/*    42060:	01c03025 */ 	or	$a2,$t6,$zero
/*    42064:	2524001c */ 	addiu	$a0,$t1,0x1c
/*    42068:	0c0118b1 */ 	jal	func000462c4
/*    4206c:	25252020 */ 	addiu	$a1,$t1,0x2020
/*    42070:	8fa80198 */ 	lw	$t0,0x198($sp)
/*    42074:	8faf0190 */ 	lw	$t7,0x190($sp)
/*    42078:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    4207c:	00086940 */ 	sll	$t5,$t0,0x5
/*    42080:	01a86823 */ 	subu	$t5,$t5,$t0
/*    42084:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    42088:	01ed5021 */ 	addu	$t2,$t7,$t5
/*    4208c:	000cc880 */ 	sll	$t9,$t4,0x2
/*    42090:	01595821 */ 	addu	$t3,$t2,$t9
/*    42094:	1000000b */ 	b	.L000420c4
/*    42098:	ad623d64 */ 	sw	$v0,0x3d64($t3)
.L0004209c:
/*    4209c:	8fa90198 */ 	lw	$t1,0x198($sp)
/*    420a0:	8fb80190 */ 	lw	$t8,0x190($sp)
/*    420a4:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    420a8:	00097140 */ 	sll	$t6,$t1,0x5
/*    420ac:	01c97023 */ 	subu	$t6,$t6,$t1
/*    420b0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    420b4:	030e4021 */ 	addu	$t0,$t8,$t6
/*    420b8:	000f6880 */ 	sll	$t5,$t7,0x2
/*    420bc:	010d6021 */ 	addu	$t4,$t0,$t5
/*    420c0:	ad803d64 */ 	sw	$zero,0x3d64($t4)
.L000420c4:
/*    420c4:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    420c8:	11400011 */ 	beqz	$t2,.L00042110
/*    420cc:	00000000 */ 	nop
/*    420d0:	8fb90190 */ 	lw	$t9,0x190($sp)
/*    420d4:	01403025 */ 	or	$a2,$t2,$zero
/*    420d8:	2724001c */ 	addiu	$a0,$t9,0x1c
/*    420dc:	0c0118b1 */ 	jal	func000462c4
/*    420e0:	27252020 */ 	addiu	$a1,$t9,0x2020
/*    420e4:	8fa90198 */ 	lw	$t1,0x198($sp)
/*    420e8:	8fab0190 */ 	lw	$t3,0x190($sp)
/*    420ec:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    420f0:	0009c140 */ 	sll	$t8,$t1,0x5
/*    420f4:	0309c023 */ 	subu	$t8,$t8,$t1
/*    420f8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    420fc:	01787021 */ 	addu	$t6,$t3,$t8
/*    42100:	000f4080 */ 	sll	$t0,$t7,0x2
/*    42104:	01c86821 */ 	addu	$t5,$t6,$t0
/*    42108:	1000000b */ 	b	.L00042138
/*    4210c:	ada23d98 */ 	sw	$v0,0x3d98($t5)
.L00042110:
/*    42110:	8fb90198 */ 	lw	$t9,0x198($sp)
/*    42114:	8fac0190 */ 	lw	$t4,0x190($sp)
/*    42118:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    4211c:	00195140 */ 	sll	$t2,$t9,0x5
/*    42120:	01595023 */ 	subu	$t2,$t2,$t9
/*    42124:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    42128:	018a4821 */ 	addu	$t1,$t4,$t2
/*    4212c:	000bc080 */ 	sll	$t8,$t3,0x2
/*    42130:	01387821 */ 	addu	$t7,$t1,$t8
/*    42134:	ade03d98 */ 	sw	$zero,0x3d98($t7)
.L00042138:
/*    42138:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    4213c:	11c00011 */ 	beqz	$t6,.L00042184
/*    42140:	00000000 */ 	nop
/*    42144:	8fa80190 */ 	lw	$t0,0x190($sp)
/*    42148:	01c03025 */ 	or	$a2,$t6,$zero
/*    4214c:	2504001c */ 	addiu	$a0,$t0,0x1c
/*    42150:	0c0118b1 */ 	jal	func000462c4
/*    42154:	25052020 */ 	addiu	$a1,$t0,0x2020
/*    42158:	8fb90198 */ 	lw	$t9,0x198($sp)
/*    4215c:	8fad0190 */ 	lw	$t5,0x190($sp)
/*    42160:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    42164:	00196140 */ 	sll	$t4,$t9,0x5
/*    42168:	01996023 */ 	subu	$t4,$t4,$t9
/*    4216c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    42170:	01ac5021 */ 	addu	$t2,$t5,$t4
/*    42174:	000b4880 */ 	sll	$t1,$t3,0x2
/*    42178:	0149c021 */ 	addu	$t8,$t2,$t1
/*    4217c:	1000000b */ 	b	.L000421ac
/*    42180:	af023dcc */ 	sw	$v0,0x3dcc($t8)
.L00042184:
/*    42184:	8fa80198 */ 	lw	$t0,0x198($sp)
/*    42188:	8faf0190 */ 	lw	$t7,0x190($sp)
/*    4218c:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    42190:	00087140 */ 	sll	$t6,$t0,0x5
/*    42194:	01c87023 */ 	subu	$t6,$t6,$t0
/*    42198:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    4219c:	01eec821 */ 	addu	$t9,$t7,$t6
/*    421a0:	000d6080 */ 	sll	$t4,$t5,0x2
/*    421a4:	032c5821 */ 	addu	$t3,$t9,$t4
/*    421a8:	ad603dcc */ 	sw	$zero,0x3dcc($t3)
.L000421ac:
/*    421ac:	8faa0198 */ 	lw	$t2,0x198($sp)
/*    421b0:	11400007 */ 	beqz	$t2,.L000421d0
/*    421b4:	00000000 */ 	nop
/*    421b8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    421bc:	8fb80190 */ 	lw	$t8,0x190($sp)
/*    421c0:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    421c4:	00087880 */ 	sll	$t7,$t0,0x2
/*    421c8:	030f7021 */ 	addu	$t6,$t8,$t7
/*    421cc:	adc93f14 */ 	sw	$t1,0x3f14($t6)
.L000421d0:
/*    421d0:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    421d4:	25b90001 */ 	addiu	$t9,$t5,0x1
/*    421d8:	afb90024 */ 	sw	$t9,0x24($sp)
/*    421dc:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    421e0:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    421e4:	258b0003 */ 	addiu	$t3,$t4,0x3
/*    421e8:	000a4080 */ 	sll	$t0,$t2,0x2
/*    421ec:	03a8c021 */ 	addu	$t8,$sp,$t0
/*    421f0:	afab003c */ 	sw	$t3,0x3c($sp)
/*    421f4:	8f180028 */ 	lw	$t8,0x28($t8)
/*    421f8:	0178082a */ 	slt	$at,$t3,$t8
/*    421fc:	1420ff94 */ 	bnez	$at,.L00042050
/*    42200:	00000000 */ 	nop
.L00042204:
/*    42204:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    42208:	25e90001 */ 	addiu	$t1,$t7,0x1
/*    4220c:	29210004 */ 	slti	$at,$t1,0x4
/*    42210:	1420ff7e */ 	bnez	$at,.L0004200c
/*    42214:	afa90040 */ 	sw	$t1,0x40($sp)
.L00042218:
/*    42218:	10000003 */ 	b	.L00042228
/*    4221c:	24020001 */ 	addiu	$v0,$zero,0x1
/*    42220:	10000001 */ 	b	.L00042228
/*    42224:	00000000 */ 	nop
.L00042228:
/*    42228:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4222c:	27bd0190 */ 	addiu	$sp,$sp,0x190
/*    42230:	03e00008 */ 	jr	$ra
/*    42234:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00042238
/*    42238:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    4223c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    42240:	afa40068 */ 	sw	$a0,0x68($sp)
/*    42244:	afa5006c */ 	sw	$a1,0x6c($sp)
/*    42248:	afa60070 */ 	sw	$a2,0x70($sp)
/*    4224c:	8fae0068 */ 	lw	$t6,0x68($sp)
/*    42250:	8dcf2020 */ 	lw	$t7,0x2020($t6)
/*    42254:	afaf0064 */ 	sw	$t7,0x64($sp)
/*    42258:	8fb80068 */ 	lw	$t8,0x68($sp)
/*    4225c:	8f193ba4 */ 	lw	$t9,0x3ba4($t8)
/*    42260:	13200007 */ 	beqz	$t9,.L00042280
/*    42264:	00000000 */ 	nop
/*    42268:	8fa40068 */ 	lw	$a0,0x68($sp)
/*    4226c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*    42270:	0c01036b */ 	jal	func00040dac
/*    42274:	8fa60070 */ 	lw	$a2,0x70($sp)
/*    42278:	10000005 */ 	b	.L00042290
/*    4227c:	00000000 */ 	nop
.L00042280:
/*    42280:	8fa40068 */ 	lw	$a0,0x68($sp)
/*    42284:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*    42288:	0c010580 */ 	jal	func00041600
/*    4228c:	8fa60070 */ 	lw	$a2,0x70($sp)
.L00042290:
/*    42290:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*    42294:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    42298:	8fac0070 */ 	lw	$t4,0x70($sp)
/*    4229c:	00095080 */ 	sll	$t2,$t1,0x2
/*    422a0:	010a5821 */ 	addu	$t3,$t0,$t2
/*    422a4:	000c6880 */ 	sll	$t5,$t4,0x2
/*    422a8:	016d7021 */ 	addu	$t6,$t3,$t5
/*    422ac:	8dcf3c80 */ 	lw	$t7,0x3c80($t6)
/*    422b0:	000fc040 */ 	sll	$t8,$t7,0x1
/*    422b4:	afb80060 */ 	sw	$t8,0x60($sp)
/*    422b8:	8fb90068 */ 	lw	$t9,0x68($sp)
/*    422bc:	3c0d7005 */ 	lui	$t5,%hi(var70057860)
/*    422c0:	25ad7860 */ 	addiu	$t5,$t5,%lo(var70057860)
/*    422c4:	8f2a3bb4 */ 	lw	$t2,0x3bb4($t9)
/*    422c8:	8f293ba4 */ 	lw	$t1,0x3ba4($t9)
/*    422cc:	000a6080 */ 	sll	$t4,$t2,0x2
/*    422d0:	018a6023 */ 	subu	$t4,$t4,$t2
/*    422d4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    422d8:	00094140 */ 	sll	$t0,$t1,0x5
/*    422dc:	018a6023 */ 	subu	$t4,$t4,$t2
/*    422e0:	01094021 */ 	addu	$t0,$t0,$t1
/*    422e4:	00084080 */ 	sll	$t0,$t0,0x2
/*    422e8:	000c6080 */ 	sll	$t4,$t4,0x2
/*    422ec:	010c5821 */ 	addu	$t3,$t0,$t4
/*    422f0:	016d7021 */ 	addu	$t6,$t3,$t5
/*    422f4:	afae0050 */ 	sw	$t6,0x50($sp)
/*    422f8:	8faf0068 */ 	lw	$t7,0x68($sp)
/*    422fc:	3c0c7005 */ 	lui	$t4,%hi(var70057968)
/*    42300:	258c7968 */ 	addiu	$t4,$t4,%lo(var70057968)
/*    42304:	8df83ba4 */ 	lw	$t8,0x3ba4($t7)
/*    42308:	8df93bb4 */ 	lw	$t9,0x3bb4($t7)
/*    4230c:	00184880 */ 	sll	$t1,$t8,0x2
/*    42310:	00195080 */ 	sll	$t2,$t9,0x2
/*    42314:	01384821 */ 	addu	$t1,$t1,$t8
/*    42318:	01595023 */ 	subu	$t2,$t2,$t9
/*    4231c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    42320:	000948c0 */ 	sll	$t1,$t1,0x3
/*    42324:	01384823 */ 	subu	$t1,$t1,$t8
/*    42328:	01595021 */ 	addu	$t2,$t2,$t9
/*    4232c:	012a4021 */ 	addu	$t0,$t1,$t2
/*    42330:	010c5821 */ 	addu	$t3,$t0,$t4
/*    42334:	afab004c */ 	sw	$t3,0x4c($sp)
/*    42338:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    4233c:	8fad0068 */ 	lw	$t5,0x68($sp)
/*    42340:	8fb90070 */ 	lw	$t9,0x70($sp)
/*    42344:	000ec080 */ 	sll	$t8,$t6,0x2
/*    42348:	01b87821 */ 	addu	$t7,$t5,$t8
/*    4234c:	00194880 */ 	sll	$t1,$t9,0x2
/*    42350:	01e95021 */ 	addu	$t2,$t7,$t1
/*    42354:	8d483c98 */ 	lw	$t0,0x3c98($t2)
/*    42358:	1500003c */ 	bnez	$t0,.L0004244c
/*    4235c:	00000000 */ 	nop
/*    42360:	8d4c3ca0 */ 	lw	$t4,0x3ca0($t2)
/*    42364:	15800039 */ 	bnez	$t4,.L0004244c
/*    42368:	00000000 */ 	nop
/*    4236c:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    42370:	8fab0068 */ 	lw	$t3,0x68($sp)
/*    42374:	8fb90070 */ 	lw	$t9,0x70($sp)
/*    42378:	000e6880 */ 	sll	$t5,$t6,0x2
/*    4237c:	016dc021 */ 	addu	$t8,$t3,$t5
/*    42380:	00197880 */ 	sll	$t7,$t9,0x2
/*    42384:	030f4821 */ 	addu	$t1,$t8,$t7
/*    42388:	8d283ce0 */ 	lw	$t0,0x3ce0($t1)
/*    4238c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    42390:	27b90054 */ 	addiu	$t9,$sp,0x54
/*    42394:	00085040 */ 	sll	$t2,$t0,0x1
/*    42398:	018a7021 */ 	addu	$t6,$t4,$t2
/*    4239c:	85cb0000 */ 	lh	$t3,0x0($t6)
/*    423a0:	256d0001 */ 	addiu	$t5,$t3,0x1
/*    423a4:	af2d0000 */ 	sw	$t5,0x0($t9)
/*    423a8:	27b80054 */ 	addiu	$t8,$sp,0x54
/*    423ac:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*    423b0:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    423b4:	012f082a */ 	slt	$at,$t1,$t7
/*    423b8:	10200008 */ 	beqz	$at,.L000423dc
/*    423bc:	00000000 */ 	nop
/*    423c0:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    423c4:	27ac0054 */ 	addiu	$t4,$sp,0x54
/*    423c8:	27aa0054 */ 	addiu	$t2,$sp,0x54
/*    423cc:	ad880004 */ 	sw	$t0,0x4($t4)
/*    423d0:	8d4e0004 */ 	lw	$t6,0x4($t2)
/*    423d4:	1000001b */ 	b	.L00042444
/*    423d8:	ad4e0000 */ 	sw	$t6,0x0($t2)
.L000423dc:
/*    423dc:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    423e0:	8fab0068 */ 	lw	$t3,0x68($sp)
/*    423e4:	8faf0070 */ 	lw	$t7,0x70($sp)
/*    423e8:	000dc880 */ 	sll	$t9,$t5,0x2
/*    423ec:	0179c021 */ 	addu	$t8,$t3,$t9
/*    423f0:	000f4880 */ 	sll	$t1,$t7,0x2
/*    423f4:	03094021 */ 	addu	$t0,$t8,$t1
/*    423f8:	8d0c3ce8 */ 	lw	$t4,0x3ce8($t0)
/*    423fc:	8d0e3ce0 */ 	lw	$t6,0x3ce0($t0)
/*    42400:	8fab0050 */ 	lw	$t3,0x50($sp)
/*    42404:	27a90054 */ 	addiu	$t1,$sp,0x54
/*    42408:	018e5021 */ 	addu	$t2,$t4,$t6
/*    4240c:	000a6840 */ 	sll	$t5,$t2,0x1
/*    42410:	016dc821 */ 	addu	$t9,$t3,$t5
/*    42414:	872f0002 */ 	lh	$t7,0x2($t9)
/*    42418:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    4241c:	ad380004 */ 	sw	$t8,0x4($t1)
/*    42420:	27a80054 */ 	addiu	$t0,$sp,0x54
/*    42424:	8d0c0004 */ 	lw	$t4,0x4($t0)
/*    42428:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    4242c:	01cc082a */ 	slt	$at,$t6,$t4
/*    42430:	10200004 */ 	beqz	$at,.L00042444
/*    42434:	00000000 */ 	nop
/*    42438:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    4243c:	27ab0054 */ 	addiu	$t3,$sp,0x54
/*    42440:	ad6a0004 */ 	sw	$t2,0x4($t3)
.L00042444:
/*    42444:	10000028 */ 	b	.L000424e8
/*    42448:	00000000 */ 	nop
.L0004244c:
/*    4244c:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*    42450:	8fad0068 */ 	lw	$t5,0x68($sp)
/*    42454:	8fa90070 */ 	lw	$t1,0x70($sp)
/*    42458:	00197880 */ 	sll	$t7,$t9,0x2
/*    4245c:	01afc021 */ 	addu	$t8,$t5,$t7
/*    42460:	00094080 */ 	sll	$t0,$t1,0x2
/*    42464:	03086021 */ 	addu	$t4,$t8,$t0
/*    42468:	8d8e3ca0 */ 	lw	$t6,0x3ca0($t4)
/*    4246c:	24010002 */ 	addiu	$at,$zero,0x2
/*    42470:	15c1000c */ 	bne	$t6,$at,.L000424a4
/*    42474:	00000000 */ 	nop
/*    42478:	8d8a3ca8 */ 	lw	$t2,0x3ca8($t4)
/*    4247c:	15400009 */ 	bnez	$t2,.L000424a4
/*    42480:	00000000 */ 	nop
/*    42484:	8fab004c */ 	lw	$t3,0x4c($sp)
/*    42488:	27a90054 */ 	addiu	$t1,$sp,0x54
/*    4248c:	91790002 */ 	lbu	$t9,0x2($t3)
/*    42490:	00196880 */ 	sll	$t5,$t9,0x2
/*    42494:	01b96823 */ 	subu	$t5,$t5,$t9
/*    42498:	25af0003 */ 	addiu	$t7,$t5,0x3
/*    4249c:	10000006 */ 	b	.L000424b8
/*    424a0:	ad2f0000 */ 	sw	$t7,0x0($t1)
.L000424a4:
/*    424a4:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    424a8:	27ac0054 */ 	addiu	$t4,$sp,0x54
/*    424ac:	8708000e */ 	lh	$t0,0xe($t8)
/*    424b0:	250e0001 */ 	addiu	$t6,$t0,0x1
/*    424b4:	ad8e0000 */ 	sw	$t6,0x0($t4)
.L000424b8:
/*    424b8:	27aa0054 */ 	addiu	$t2,$sp,0x54
/*    424bc:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    424c0:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    424c4:	032b082a */ 	slt	$at,$t9,$t3
/*    424c8:	10200004 */ 	beqz	$at,.L000424dc
/*    424cc:	00000000 */ 	nop
/*    424d0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    424d4:	27af0054 */ 	addiu	$t7,$sp,0x54
/*    424d8:	aded0000 */ 	sw	$t5,0x0($t7)
.L000424dc:
/*    424dc:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    424e0:	27b80054 */ 	addiu	$t8,$sp,0x54
/*    424e4:	af090004 */ 	sw	$t1,0x4($t8)
.L000424e8:
/*    424e8:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    424ec:	27ae0054 */ 	addiu	$t6,$sp,0x54
/*    424f0:	adc80008 */ 	sw	$t0,0x8($t6)
/*    424f4:	afa00048 */ 	sw	$zero,0x48($sp)
/*    424f8:	8faa0070 */ 	lw	$t2,0x70($sp)
/*    424fc:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    42500:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    42504:	016a5821 */ 	addu	$t3,$t3,$t2
/*    42508:	000b5940 */ 	sll	$t3,$t3,0x5
/*    4250c:	016a5821 */ 	addu	$t3,$t3,$t2
/*    42510:	000b5880 */ 	sll	$t3,$t3,0x2
/*    42514:	018bc821 */ 	addu	$t9,$t4,$t3
/*    42518:	272d3f94 */ 	addiu	$t5,$t9,0x3f94
/*    4251c:	afad0044 */ 	sw	$t5,0x44($sp)
/*    42520:	8fa90070 */ 	lw	$t1,0x70($sp)
/*    42524:	8faf0068 */ 	lw	$t7,0x68($sp)
/*    42528:	0009c0c0 */ 	sll	$t8,$t1,0x3
/*    4252c:	0309c021 */ 	addu	$t8,$t8,$t1
/*    42530:	0018c140 */ 	sll	$t8,$t8,0x5
/*    42534:	0309c021 */ 	addu	$t8,$t8,$t1
/*    42538:	0018c040 */ 	sll	$t8,$t8,0x1
/*    4253c:	01f84021 */ 	addu	$t0,$t7,$t8
/*    42540:	250e4418 */ 	addiu	$t6,$t0,0x4418
/*    42544:	afae0040 */ 	sw	$t6,0x40($sp)
/*    42548:	afa0003c */ 	sw	$zero,0x3c($sp)
.L0004254c:
/*    4254c:	8fac006c */ 	lw	$t4,0x6c($sp)
/*    42550:	8fad0070 */ 	lw	$t5,0x70($sp)
/*    42554:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    42558:	000c5880 */ 	sll	$t3,$t4,0x2
/*    4255c:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    42560:	016c5823 */ 	subu	$t3,$t3,$t4
/*    42564:	000d4880 */ 	sll	$t1,$t5,0x2
/*    42568:	000b5880 */ 	sll	$t3,$t3,0x2
/*    4256c:	012d4823 */ 	subu	$t1,$t1,$t5
/*    42570:	00094880 */ 	sll	$t1,$t1,0x2
/*    42574:	014bc821 */ 	addu	$t9,$t2,$t3
/*    42578:	03297821 */ 	addu	$t7,$t9,$t1
/*    4257c:	00184080 */ 	sll	$t0,$t8,0x2
/*    42580:	01e87021 */ 	addu	$t6,$t7,$t0
/*    42584:	8dcc3cb0 */ 	lw	$t4,0x3cb0($t6)
/*    42588:	afac0038 */ 	sw	$t4,0x38($sp)
/*    4258c:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    42590:	3c0d7005 */ 	lui	$t5,%hi(var700577d8)
/*    42594:	000a5880 */ 	sll	$t3,$t2,0x2
/*    42598:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    4259c:	8dad77d8 */ 	lw	$t5,%lo(var700577d8)($t5)
/*    425a0:	afad0034 */ 	sw	$t5,0x34($sp)
/*    425a4:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    425a8:	00194880 */ 	sll	$t1,$t9,0x2
/*    425ac:	03a9c021 */ 	addu	$t8,$sp,$t1
/*    425b0:	8f180054 */ 	lw	$t8,0x54($t8)
/*    425b4:	afb80030 */ 	sw	$t8,0x30($sp)
/*    425b8:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    425bc:	3c0e800a */ 	lui	$t6,%hi(var8009c650)
/*    425c0:	000f4080 */ 	sll	$t0,$t7,0x2
/*    425c4:	01c87021 */ 	addu	$t6,$t6,$t0
/*    425c8:	8dcec650 */ 	lw	$t6,%lo(var8009c650)($t6)
/*    425cc:	15c00015 */ 	bnez	$t6,.L00042624
/*    425d0:	00000000 */ 	nop
/*    425d4:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    425d8:	8faa0048 */ 	lw	$t2,0x48($sp)
/*    425dc:	018a5823 */ 	subu	$t3,$t4,$t2
/*    425e0:	afab002c */ 	sw	$t3,0x2c($sp)
/*    425e4:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    425e8:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    425ec:	0c012c30 */ 	jal	bzero
/*    425f0:	00052840 */ 	sll	$a1,$a1,0x1
/*    425f4:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    425f8:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    425fc:	00194840 */ 	sll	$t1,$t9,0x1
/*    42600:	01a9c021 */ 	addu	$t8,$t5,$t1
/*    42604:	afb80044 */ 	sw	$t8,0x44($sp)
/*    42608:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    4260c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    42610:	01e87021 */ 	addu	$t6,$t7,$t0
/*    42614:	afae0040 */ 	sw	$t6,0x40($sp)
/*    42618:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    4261c:	10000010 */ 	b	.L00042660
/*    42620:	afac0048 */ 	sw	$t4,0x48($sp)
.L00042624:
/*    42624:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    42628:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    4262c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    42630:	27ad0044 */ 	addiu	$t5,$sp,0x44
/*    42634:	27a90040 */ 	addiu	$t1,$sp,0x40
/*    42638:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    4263c:	afad0018 */ 	sw	$t5,0x18($sp)
/*    42640:	8fa60038 */ 	lw	$a2,0x38($sp)
/*    42644:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    42648:	2544001c */ 	addiu	$a0,$t2,0x1c
/*    4264c:	25452020 */ 	addiu	$a1,$t2,0x2020
/*    42650:	afab0010 */ 	sw	$t3,0x10($sp)
/*    42654:	0c0118be */ 	jal	func000462f8
/*    42658:	afb90014 */ 	sw	$t9,0x14($sp)
/*    4265c:	afa20048 */ 	sw	$v0,0x48($sp)
.L00042660:
/*    42660:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    42664:	270f0001 */ 	addiu	$t7,$t8,0x1
/*    42668:	29e10003 */ 	slti	$at,$t7,0x3
/*    4266c:	1420ffb7 */ 	bnez	$at,.L0004254c
/*    42670:	afaf003c */ 	sw	$t7,0x3c($sp)
/*    42674:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    42678:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    4267c:	8fab0070 */ 	lw	$t3,0x70($sp)
/*    42680:	000e6080 */ 	sll	$t4,$t6,0x2
/*    42684:	010c5021 */ 	addu	$t2,$t0,$t4
/*    42688:	000bc880 */ 	sll	$t9,$t3,0x2
/*    4268c:	01596821 */ 	addu	$t5,$t2,$t9
/*    42690:	8da93d00 */ 	lw	$t1,0x3d00($t5)
/*    42694:	25380020 */ 	addiu	$t8,$t1,0x20
/*    42698:	afb80038 */ 	sw	$t8,0x38($sp)
/*    4269c:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    426a0:	8faf0068 */ 	lw	$t7,0x68($sp)
/*    426a4:	8fab0070 */ 	lw	$t3,0x70($sp)
/*    426a8:	000e4080 */ 	sll	$t0,$t6,0x2
/*    426ac:	01e86021 */ 	addu	$t4,$t7,$t0
/*    426b0:	000b5080 */ 	sll	$t2,$t3,0x2
/*    426b4:	018ac821 */ 	addu	$t9,$t4,$t2
/*    426b8:	8f2d3c78 */ 	lw	$t5,0x3c78($t9)
/*    426bc:	8fa90064 */ 	lw	$t1,0x64($sp)
/*    426c0:	01a9c021 */ 	addu	$t8,$t5,$t1
/*    426c4:	afb80028 */ 	sw	$t8,0x28($sp)
/*    426c8:	8fae0068 */ 	lw	$t6,0x68($sp)
/*    426cc:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    426d0:	27a80044 */ 	addiu	$t0,$sp,0x44
/*    426d4:	27ab0040 */ 	addiu	$t3,$sp,0x40
/*    426d8:	afab0018 */ 	sw	$t3,0x18($sp)
/*    426dc:	afa80014 */ 	sw	$t0,0x14($sp)
/*    426e0:	8fa60038 */ 	lw	$a2,0x38($sp)
/*    426e4:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    426e8:	25c4001c */ 	addiu	$a0,$t6,0x1c
/*    426ec:	25c52020 */ 	addiu	$a1,$t6,0x2020
/*    426f0:	0c01192a */ 	jal	func000464a8
/*    426f4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    426f8:	afa20048 */ 	sw	$v0,0x48($sp)
/*    426fc:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    42700:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    42704:	ad4c2020 */ 	sw	$t4,0x2020($t2)
/*    42708:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    4270c:	2b210241 */ 	slti	$at,$t9,0x241
/*    42710:	14200008 */ 	bnez	$at,.L00042734
/*    42714:	00000000 */ 	nop
/*    42718:	8fb80070 */ 	lw	$t8,0x70($sp)
/*    4271c:	8fa90068 */ 	lw	$t1,0x68($sp)
/*    42720:	240d0240 */ 	addiu	$t5,$zero,0x240
/*    42724:	00187080 */ 	sll	$t6,$t8,0x2
/*    42728:	012e7821 */ 	addu	$t7,$t1,$t6
/*    4272c:	10000007 */ 	b	.L0004274c
/*    42730:	aded465c */ 	sw	$t5,0x465c($t7)
.L00042734:
/*    42734:	8fac0070 */ 	lw	$t4,0x70($sp)
/*    42738:	8fab0068 */ 	lw	$t3,0x68($sp)
/*    4273c:	8fa80048 */ 	lw	$t0,0x48($sp)
/*    42740:	000c5080 */ 	sll	$t2,$t4,0x2
/*    42744:	016ac821 */ 	addu	$t9,$t3,$t2
/*    42748:	af28465c */ 	sw	$t0,0x465c($t9)
.L0004274c:
/*    4274c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    42750:	2b010240 */ 	slti	$at,$t8,0x240
/*    42754:	10200013 */ 	beqz	$at,.L000427a4
/*    42758:	00000000 */ 	nop
/*    4275c:	8fac0070 */ 	lw	$t4,0x70($sp)
/*    42760:	8fa90048 */ 	lw	$t1,0x48($sp)
/*    42764:	8faf0068 */ 	lw	$t7,0x68($sp)
/*    42768:	240e0240 */ 	addiu	$t6,$zero,0x240
/*    4276c:	000c5880 */ 	sll	$t3,$t4,0x2
/*    42770:	01c96823 */ 	subu	$t5,$t6,$t1
/*    42774:	01eb5021 */ 	addu	$t2,$t7,$t3
/*    42778:	ad4d4660 */ 	sw	$t5,0x4660($t2)
/*    4277c:	8fb90070 */ 	lw	$t9,0x70($sp)
/*    42780:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    42784:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    42788:	0019c080 */ 	sll	$t8,$t9,0x2
/*    4278c:	01187021 */ 	addu	$t6,$t0,$t8
/*    42790:	8dc54660 */ 	lw	$a1,0x4660($t6)
/*    42794:	0c012c30 */ 	jal	bzero
/*    42798:	00052840 */ 	sll	$a1,$a1,0x1
/*    4279c:	10000006 */ 	b	.L000427b8
/*    427a0:	00000000 */ 	nop
.L000427a4:
/*    427a4:	8fac0070 */ 	lw	$t4,0x70($sp)
/*    427a8:	8fa90068 */ 	lw	$t1,0x68($sp)
/*    427ac:	000c7880 */ 	sll	$t7,$t4,0x2
/*    427b0:	012f5821 */ 	addu	$t3,$t1,$t7
/*    427b4:	ad604660 */ 	sw	$zero,0x4660($t3)
.L000427b8:
/*    427b8:	10000003 */ 	b	.L000427c8
/*    427bc:	24020001 */ 	addiu	$v0,$zero,0x1
/*    427c0:	10000001 */ 	b	.L000427c8
/*    427c4:	00000000 */ 	nop
.L000427c8:
/*    427c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    427cc:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    427d0:	03e00008 */ 	jr	$ra
/*    427d4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func000427d8
/*    427d8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    427dc:	8c8e3ba4 */ 	lw	$t6,0x3ba4($a0)
/*    427e0:	8c983bb4 */ 	lw	$t8,0x3bb4($a0)
/*    427e4:	3c097005 */ 	lui	$t1,%hi(var70057b9c)
/*    427e8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*    427ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    427f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    427f4:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*    427f8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    427fc:	0338c821 */ 	addu	$t9,$t9,$t8
/*    42800:	0019c9c0 */ 	sll	$t9,$t9,0x7
/*    42804:	000f79c0 */ 	sll	$t7,$t7,0x7
/*    42808:	01f94021 */ 	addu	$t0,$t7,$t9
/*    4280c:	25297b9c */ 	addiu	$t1,$t1,%lo(var70057b9c)
/*    42810:	01095021 */ 	addu	$t2,$t0,$t1
/*    42814:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    42818:	248b4f64 */ 	addiu	$t3,$a0,0x4f64
/*    4281c:	afab0010 */ 	sw	$t3,0x10($sp)
/*    42820:	248c4664 */ 	addiu	$t4,$a0,0x4664
/*    42824:	afac000c */ 	sw	$t4,0xc($sp)
/*    42828:	afa00008 */ 	sw	$zero,0x8($sp)
/*    4282c:	00056880 */ 	sll	$t5,$a1,0x2
/*    42830:	008d7021 */ 	addu	$t6,$a0,$t5
/*    42834:	8dd83c98 */ 	lw	$t8,0x3c98($t6)
/*    42838:	1300003b */ 	beqz	$t8,.L00042928
/*    4283c:	00000000 */ 	nop
/*    42840:	00057880 */ 	sll	$t7,$a1,0x2
/*    42844:	008fc821 */ 	addu	$t9,$a0,$t7
/*    42848:	8f283ca0 */ 	lw	$t0,0x3ca0($t9)
/*    4284c:	24010002 */ 	addiu	$at,$zero,0x2
/*    42850:	15010035 */ 	bne	$t0,$at,.L00042928
/*    42854:	00000000 */ 	nop
/*    42858:	00054880 */ 	sll	$t1,$a1,0x2
/*    4285c:	00895021 */ 	addu	$t2,$a0,$t1
/*    42860:	8d4b3ca8 */ 	lw	$t3,0x3ca8($t2)
/*    42864:	11600015 */ 	beqz	$t3,.L000428bc
/*    42868:	00000000 */ 	nop
/*    4286c:	8fac0008 */ 	lw	$t4,0x8($sp)
/*    42870:	29860024 */ 	slti	$a2,$t4,0x24
/*    42874:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    42878:	10c00010 */ 	beqz	$a2,.L000428bc
/*    4287c:	afad0008 */ 	sw	$t5,0x8($sp)
.L00042880:
/*    42880:	8fae000c */ 	lw	$t6,0xc($sp)
/*    42884:	8fb80010 */ 	lw	$t8,0x10($sp)
/*    42888:	c5c40000 */ 	lwc1	$f4,0x0($t6)
/*    4288c:	e7040000 */ 	swc1	$f4,0x0($t8)
/*    42890:	8fa8000c */ 	lw	$t0,0xc($sp)
/*    42894:	8faf0010 */ 	lw	$t7,0x10($sp)
/*    42898:	25090004 */ 	addiu	$t1,$t0,0x4
/*    4289c:	25f90004 */ 	addiu	$t9,$t7,0x4
/*    428a0:	afb90010 */ 	sw	$t9,0x10($sp)
/*    428a4:	afa9000c */ 	sw	$t1,0xc($sp)
/*    428a8:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    428ac:	29460024 */ 	slti	$a2,$t2,0x24
/*    428b0:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    428b4:	14c0fff2 */ 	bnez	$a2,.L00042880
/*    428b8:	afab0008 */ 	sw	$t3,0x8($sp)
.L000428bc:
/*    428bc:	8fac0008 */ 	lw	$t4,0x8($sp)
/*    428c0:	29810240 */ 	slti	$at,$t4,0x240
/*    428c4:	10200016 */ 	beqz	$at,.L00042920
/*    428c8:	00000000 */ 	nop
.L000428cc:
/*    428cc:	8fb80008 */ 	lw	$t8,0x8($sp)
/*    428d0:	8fae0014 */ 	lw	$t6,0x14($sp)
/*    428d4:	8fad000c */ 	lw	$t5,0xc($sp)
/*    428d8:	00187840 */ 	sll	$t7,$t8,0x1
/*    428dc:	01cfc821 */ 	addu	$t9,$t6,$t7
/*    428e0:	87280000 */ 	lh	$t0,0x0($t9)
/*    428e4:	8faa0010 */ 	lw	$t2,0x10($sp)
/*    428e8:	c5a60000 */ 	lwc1	$f6,0x0($t5)
/*    428ec:	00084880 */ 	sll	$t1,$t0,0x2
/*    428f0:	01495821 */ 	addu	$t3,$t2,$t1
/*    428f4:	e5660000 */ 	swc1	$f6,0x0($t3)
/*    428f8:	8fb8000c */ 	lw	$t8,0xc($sp)
/*    428fc:	8fac0008 */ 	lw	$t4,0x8($sp)
/*    42900:	270e0004 */ 	addiu	$t6,$t8,0x4
/*    42904:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    42908:	afad0008 */ 	sw	$t5,0x8($sp)
/*    4290c:	afae000c */ 	sw	$t6,0xc($sp)
/*    42910:	8faf0008 */ 	lw	$t7,0x8($sp)
/*    42914:	29e10240 */ 	slti	$at,$t7,0x240
/*    42918:	1420ffec */ 	bnez	$at,.L000428cc
/*    4291c:	00000000 */ 	nop
.L00042920:
/*    42920:	10000015 */ 	b	.L00042978
/*    42924:	00000000 */ 	nop
.L00042928:
/*    42928:	8fb90008 */ 	lw	$t9,0x8($sp)
/*    4292c:	2b260240 */ 	slti	$a2,$t9,0x240
/*    42930:	27280001 */ 	addiu	$t0,$t9,0x1
/*    42934:	10c00010 */ 	beqz	$a2,.L00042978
/*    42938:	afa80008 */ 	sw	$t0,0x8($sp)
.L0004293c:
/*    4293c:	8faa000c */ 	lw	$t2,0xc($sp)
/*    42940:	8fa90010 */ 	lw	$t1,0x10($sp)
/*    42944:	c5480000 */ 	lwc1	$f8,0x0($t2)
/*    42948:	e5280000 */ 	swc1	$f8,0x0($t1)
/*    4294c:	8fad000c */ 	lw	$t5,0xc($sp)
/*    42950:	8fab0010 */ 	lw	$t3,0x10($sp)
/*    42954:	25b80004 */ 	addiu	$t8,$t5,0x4
/*    42958:	256c0004 */ 	addiu	$t4,$t3,0x4
/*    4295c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    42960:	afb8000c */ 	sw	$t8,0xc($sp)
/*    42964:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    42968:	29c60240 */ 	slti	$a2,$t6,0x240
/*    4296c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    42970:	14c0fff2 */ 	bnez	$a2,.L0004293c
/*    42974:	afaf0008 */ 	sw	$t7,0x8($sp)
.L00042978:
/*    42978:	10000003 */ 	b	.L00042988
/*    4297c:	24020001 */ 	addiu	$v0,$zero,0x1
/*    42980:	10000001 */ 	b	.L00042988
/*    42984:	00000000 */ 	nop
.L00042988:
/*    42988:	03e00008 */ 	jr	$ra
/*    4298c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func00042990
/*    42990:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    42994:	00057080 */ 	sll	$t6,$a1,0x2
/*    42998:	008e7821 */ 	addu	$t7,$a0,$t6
/*    4299c:	0006c080 */ 	sll	$t8,$a2,0x2
/*    429a0:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    429a4:	8f283c98 */ 	lw	$t0,0x3c98($t9)
/*    429a8:	1100000b */ 	beqz	$t0,.L000429d8
/*    429ac:	00000000 */ 	nop
/*    429b0:	00054880 */ 	sll	$t1,$a1,0x2
/*    429b4:	00895021 */ 	addu	$t2,$a0,$t1
/*    429b8:	00065880 */ 	sll	$t3,$a2,0x2
/*    429bc:	014b6021 */ 	addu	$t4,$t2,$t3
/*    429c0:	8d8d3ca0 */ 	lw	$t5,0x3ca0($t4)
/*    429c4:	24010002 */ 	addiu	$at,$zero,0x2
/*    429c8:	15a10003 */ 	bne	$t5,$at,.L000429d8
/*    429cc:	00000000 */ 	nop
/*    429d0:	10000117 */ 	b	.L00042e30
/*    429d4:	24020001 */ 	addiu	$v0,$zero,0x1
.L000429d8:
/*    429d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    429dc:	afae000c */ 	sw	$t6,0xc($sp)
.L000429e0:
/*    429e0:	8fb9000c */ 	lw	$t9,0xc($sp)
/*    429e4:	000678c0 */ 	sll	$t7,$a2,0x3
/*    429e8:	01e67821 */ 	addu	$t7,$t7,$a2
/*    429ec:	001940c0 */ 	sll	$t0,$t9,0x3
/*    429f0:	000f7a00 */ 	sll	$t7,$t7,0x8
/*    429f4:	01194021 */ 	addu	$t0,$t0,$t9
/*    429f8:	000840c0 */ 	sll	$t0,$t0,0x3
/*    429fc:	008fc021 */ 	addu	$t8,$a0,$t7
/*    42a00:	03084821 */ 	addu	$t1,$t8,$t0
/*    42a04:	252a4f64 */ 	addiu	$t2,$t1,0x4f64
/*    42a08:	afaa0008 */ 	sw	$t2,0x8($sp)
/*    42a0c:	8fab0008 */ 	lw	$t3,0x8($sp)
/*    42a10:	c5640000 */ 	lwc1	$f4,0x0($t3)
/*    42a14:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*    42a18:	8fac0008 */ 	lw	$t4,0x8($sp)
/*    42a1c:	c586fffc */ 	lwc1	$f6,-0x4($t4)
/*    42a20:	e7a60000 */ 	swc1	$f6,0x0($sp)
/*    42a24:	3c0d7006 */ 	lui	$t5,%hi(var700596bc)
/*    42a28:	25ad96bc */ 	addiu	$t5,$t5,%lo(var700596bc)
/*    42a2c:	c5aa0000 */ 	lwc1	$f10,0x0($t5)
/*    42a30:	c7a80000 */ 	lwc1	$f8,0x0($sp)
/*    42a34:	3c0e7006 */ 	lui	$t6,%hi(var7005969c)
/*    42a38:	25ce969c */ 	addiu	$t6,$t6,%lo(var7005969c)
/*    42a3c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    42a40:	c5d20000 */ 	lwc1	$f18,0x0($t6)
/*    42a44:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    42a48:	8faf0008 */ 	lw	$t7,0x8($sp)
/*    42a4c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    42a50:	46068201 */ 	sub.s	$f8,$f16,$f6
/*    42a54:	e5e8fffc */ 	swc1	$f8,-0x4($t7)
/*    42a58:	3c197006 */ 	lui	$t9,%hi(var7005969c)
/*    42a5c:	2739969c */ 	addiu	$t9,$t9,%lo(var7005969c)
/*    42a60:	c72a0000 */ 	lwc1	$f10,0x0($t9)
/*    42a64:	c7b20000 */ 	lwc1	$f18,0x0($sp)
/*    42a68:	3c187006 */ 	lui	$t8,%hi(var700596bc)
/*    42a6c:	271896bc */ 	addiu	$t8,$t8,%lo(var700596bc)
/*    42a70:	46125102 */ 	mul.s	$f4,$f10,$f18
/*    42a74:	c7060000 */ 	lwc1	$f6,0x0($t8)
/*    42a78:	c7b00004 */ 	lwc1	$f16,0x4($sp)
/*    42a7c:	8fa80008 */ 	lw	$t0,0x8($sp)
/*    42a80:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    42a84:	46082280 */ 	add.s	$f10,$f4,$f8
/*    42a88:	e50a0000 */ 	swc1	$f10,0x0($t0)
/*    42a8c:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    42a90:	c5320004 */ 	lwc1	$f18,0x4($t1)
/*    42a94:	e7b20004 */ 	swc1	$f18,0x4($sp)
/*    42a98:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    42a9c:	c550fff8 */ 	lwc1	$f16,-0x8($t2)
/*    42aa0:	e7b00000 */ 	swc1	$f16,0x0($sp)
/*    42aa4:	3c0b7006 */ 	lui	$t3,%hi(var700596bc)
/*    42aa8:	256b96bc */ 	addiu	$t3,$t3,%lo(var700596bc)
/*    42aac:	c5640004 */ 	lwc1	$f4,0x4($t3)
/*    42ab0:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*    42ab4:	3c0c7006 */ 	lui	$t4,%hi(var7005969c)
/*    42ab8:	258c969c */ 	addiu	$t4,$t4,%lo(var7005969c)
/*    42abc:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    42ac0:	c58a0004 */ 	lwc1	$f10,0x4($t4)
/*    42ac4:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    42ac8:	8fad0008 */ 	lw	$t5,0x8($sp)
/*    42acc:	46125402 */ 	mul.s	$f16,$f10,$f18
/*    42ad0:	46104181 */ 	sub.s	$f6,$f8,$f16
/*    42ad4:	e5a6fff8 */ 	swc1	$f6,-0x8($t5)
/*    42ad8:	3c0e7006 */ 	lui	$t6,%hi(var7005969c)
/*    42adc:	25ce969c */ 	addiu	$t6,$t6,%lo(var7005969c)
/*    42ae0:	c5c40004 */ 	lwc1	$f4,0x4($t6)
/*    42ae4:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    42ae8:	3c0f7006 */ 	lui	$t7,%hi(var700596bc)
/*    42aec:	25ef96bc */ 	addiu	$t7,$t7,%lo(var700596bc)
/*    42af0:	460a2482 */ 	mul.s	$f18,$f4,$f10
/*    42af4:	c5f00004 */ 	lwc1	$f16,0x4($t7)
/*    42af8:	c7a80004 */ 	lwc1	$f8,0x4($sp)
/*    42afc:	8fb90008 */ 	lw	$t9,0x8($sp)
/*    42b00:	46104182 */ 	mul.s	$f6,$f8,$f16
/*    42b04:	46069100 */ 	add.s	$f4,$f18,$f6
/*    42b08:	e7240004 */ 	swc1	$f4,0x4($t9)
/*    42b0c:	8fb80008 */ 	lw	$t8,0x8($sp)
/*    42b10:	c70a0008 */ 	lwc1	$f10,0x8($t8)
/*    42b14:	e7aa0004 */ 	swc1	$f10,0x4($sp)
/*    42b18:	8fa80008 */ 	lw	$t0,0x8($sp)
/*    42b1c:	c508fff4 */ 	lwc1	$f8,-0xc($t0)
/*    42b20:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    42b24:	3c097006 */ 	lui	$t1,%hi(var700596bc)
/*    42b28:	252996bc */ 	addiu	$t1,$t1,%lo(var700596bc)
/*    42b2c:	c5320008 */ 	lwc1	$f18,0x8($t1)
/*    42b30:	c7b00000 */ 	lwc1	$f16,0x0($sp)
/*    42b34:	3c0a7006 */ 	lui	$t2,%hi(var7005969c)
/*    42b38:	254a969c */ 	addiu	$t2,$t2,%lo(var7005969c)
/*    42b3c:	46128182 */ 	mul.s	$f6,$f16,$f18
/*    42b40:	c5440008 */ 	lwc1	$f4,0x8($t2)
/*    42b44:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    42b48:	8fab0008 */ 	lw	$t3,0x8($sp)
/*    42b4c:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*    42b50:	46083401 */ 	sub.s	$f16,$f6,$f8
/*    42b54:	e570fff4 */ 	swc1	$f16,-0xc($t3)
/*    42b58:	3c0c7006 */ 	lui	$t4,%hi(var7005969c)
/*    42b5c:	258c969c */ 	addiu	$t4,$t4,%lo(var7005969c)
/*    42b60:	c5920008 */ 	lwc1	$f18,0x8($t4)
/*    42b64:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    42b68:	3c0d7006 */ 	lui	$t5,%hi(var700596bc)
/*    42b6c:	25ad96bc */ 	addiu	$t5,$t5,%lo(var700596bc)
/*    42b70:	46049282 */ 	mul.s	$f10,$f18,$f4
/*    42b74:	c5a80008 */ 	lwc1	$f8,0x8($t5)
/*    42b78:	c7a60004 */ 	lwc1	$f6,0x4($sp)
/*    42b7c:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    42b80:	46083402 */ 	mul.s	$f16,$f6,$f8
/*    42b84:	46105480 */ 	add.s	$f18,$f10,$f16
/*    42b88:	e5d20008 */ 	swc1	$f18,0x8($t6)
/*    42b8c:	8faf0008 */ 	lw	$t7,0x8($sp)
/*    42b90:	c5e4000c */ 	lwc1	$f4,0xc($t7)
/*    42b94:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*    42b98:	8fb90008 */ 	lw	$t9,0x8($sp)
/*    42b9c:	c726fff0 */ 	lwc1	$f6,-0x10($t9)
/*    42ba0:	e7a60000 */ 	swc1	$f6,0x0($sp)
/*    42ba4:	3c187006 */ 	lui	$t8,%hi(var700596bc)
/*    42ba8:	271896bc */ 	addiu	$t8,$t8,%lo(var700596bc)
/*    42bac:	c70a000c */ 	lwc1	$f10,0xc($t8)
/*    42bb0:	c7a80000 */ 	lwc1	$f8,0x0($sp)
/*    42bb4:	3c087006 */ 	lui	$t0,%hi(var7005969c)
/*    42bb8:	2508969c */ 	addiu	$t0,$t0,%lo(var7005969c)
/*    42bbc:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    42bc0:	c512000c */ 	lwc1	$f18,0xc($t0)
/*    42bc4:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    42bc8:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    42bcc:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    42bd0:	46068201 */ 	sub.s	$f8,$f16,$f6
/*    42bd4:	e528fff0 */ 	swc1	$f8,-0x10($t1)
/*    42bd8:	3c0a7006 */ 	lui	$t2,%hi(var7005969c)
/*    42bdc:	254a969c */ 	addiu	$t2,$t2,%lo(var7005969c)
/*    42be0:	c54a000c */ 	lwc1	$f10,0xc($t2)
/*    42be4:	c7b20000 */ 	lwc1	$f18,0x0($sp)
/*    42be8:	3c0b7006 */ 	lui	$t3,%hi(var700596bc)
/*    42bec:	256b96bc */ 	addiu	$t3,$t3,%lo(var700596bc)
/*    42bf0:	46125102 */ 	mul.s	$f4,$f10,$f18
/*    42bf4:	c566000c */ 	lwc1	$f6,0xc($t3)
/*    42bf8:	c7b00004 */ 	lwc1	$f16,0x4($sp)
/*    42bfc:	8fac0008 */ 	lw	$t4,0x8($sp)
/*    42c00:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    42c04:	46082280 */ 	add.s	$f10,$f4,$f8
/*    42c08:	e58a000c */ 	swc1	$f10,0xc($t4)
/*    42c0c:	8fad0008 */ 	lw	$t5,0x8($sp)
/*    42c10:	c5b20010 */ 	lwc1	$f18,0x10($t5)
/*    42c14:	e7b20004 */ 	swc1	$f18,0x4($sp)
/*    42c18:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    42c1c:	c5d0ffec */ 	lwc1	$f16,-0x14($t6)
/*    42c20:	e7b00000 */ 	swc1	$f16,0x0($sp)
/*    42c24:	3c0f7006 */ 	lui	$t7,%hi(var700596bc)
/*    42c28:	25ef96bc */ 	addiu	$t7,$t7,%lo(var700596bc)
/*    42c2c:	c5e40010 */ 	lwc1	$f4,0x10($t7)
/*    42c30:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*    42c34:	3c197006 */ 	lui	$t9,%hi(var7005969c)
/*    42c38:	2739969c */ 	addiu	$t9,$t9,%lo(var7005969c)
/*    42c3c:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    42c40:	c72a0010 */ 	lwc1	$f10,0x10($t9)
/*    42c44:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    42c48:	8fb80008 */ 	lw	$t8,0x8($sp)
/*    42c4c:	46125402 */ 	mul.s	$f16,$f10,$f18
/*    42c50:	46104181 */ 	sub.s	$f6,$f8,$f16
/*    42c54:	e706ffec */ 	swc1	$f6,-0x14($t8)
/*    42c58:	3c087006 */ 	lui	$t0,%hi(var7005969c)
/*    42c5c:	2508969c */ 	addiu	$t0,$t0,%lo(var7005969c)
/*    42c60:	c5040010 */ 	lwc1	$f4,0x10($t0)
/*    42c64:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    42c68:	3c097006 */ 	lui	$t1,%hi(var700596bc)
/*    42c6c:	252996bc */ 	addiu	$t1,$t1,%lo(var700596bc)
/*    42c70:	460a2482 */ 	mul.s	$f18,$f4,$f10
/*    42c74:	c5300010 */ 	lwc1	$f16,0x10($t1)
/*    42c78:	c7a80004 */ 	lwc1	$f8,0x4($sp)
/*    42c7c:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    42c80:	46104182 */ 	mul.s	$f6,$f8,$f16
/*    42c84:	46069100 */ 	add.s	$f4,$f18,$f6
/*    42c88:	e5440010 */ 	swc1	$f4,0x10($t2)
/*    42c8c:	8fab0008 */ 	lw	$t3,0x8($sp)
/*    42c90:	c56a0014 */ 	lwc1	$f10,0x14($t3)
/*    42c94:	e7aa0004 */ 	swc1	$f10,0x4($sp)
/*    42c98:	8fac0008 */ 	lw	$t4,0x8($sp)
/*    42c9c:	c588ffe8 */ 	lwc1	$f8,-0x18($t4)
/*    42ca0:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    42ca4:	3c0d7006 */ 	lui	$t5,%hi(var700596bc)
/*    42ca8:	25ad96bc */ 	addiu	$t5,$t5,%lo(var700596bc)
/*    42cac:	c5b20014 */ 	lwc1	$f18,0x14($t5)
/*    42cb0:	c7b00000 */ 	lwc1	$f16,0x0($sp)
/*    42cb4:	3c0e7006 */ 	lui	$t6,%hi(var7005969c)
/*    42cb8:	25ce969c */ 	addiu	$t6,$t6,%lo(var7005969c)
/*    42cbc:	46128182 */ 	mul.s	$f6,$f16,$f18
/*    42cc0:	c5c40014 */ 	lwc1	$f4,0x14($t6)
/*    42cc4:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    42cc8:	8faf0008 */ 	lw	$t7,0x8($sp)
/*    42ccc:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*    42cd0:	46083401 */ 	sub.s	$f16,$f6,$f8
/*    42cd4:	e5f0ffe8 */ 	swc1	$f16,-0x18($t7)
/*    42cd8:	3c197006 */ 	lui	$t9,%hi(var7005969c)
/*    42cdc:	2739969c */ 	addiu	$t9,$t9,%lo(var7005969c)
/*    42ce0:	c7320014 */ 	lwc1	$f18,0x14($t9)
/*    42ce4:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    42ce8:	3c187006 */ 	lui	$t8,%hi(var700596bc)
/*    42cec:	271896bc */ 	addiu	$t8,$t8,%lo(var700596bc)
/*    42cf0:	46049282 */ 	mul.s	$f10,$f18,$f4
/*    42cf4:	c7080014 */ 	lwc1	$f8,0x14($t8)
/*    42cf8:	c7a60004 */ 	lwc1	$f6,0x4($sp)
/*    42cfc:	8fa80008 */ 	lw	$t0,0x8($sp)
/*    42d00:	46083402 */ 	mul.s	$f16,$f6,$f8
/*    42d04:	46105480 */ 	add.s	$f18,$f10,$f16
/*    42d08:	e5120014 */ 	swc1	$f18,0x14($t0)
/*    42d0c:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    42d10:	c5240018 */ 	lwc1	$f4,0x18($t1)
/*    42d14:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*    42d18:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    42d1c:	c546ffe4 */ 	lwc1	$f6,-0x1c($t2)
/*    42d20:	e7a60000 */ 	swc1	$f6,0x0($sp)
/*    42d24:	3c0b7006 */ 	lui	$t3,%hi(var700596bc)
/*    42d28:	256b96bc */ 	addiu	$t3,$t3,%lo(var700596bc)
/*    42d2c:	c56a0018 */ 	lwc1	$f10,0x18($t3)
/*    42d30:	c7a80000 */ 	lwc1	$f8,0x0($sp)
/*    42d34:	3c0c7006 */ 	lui	$t4,%hi(var7005969c)
/*    42d38:	258c969c */ 	addiu	$t4,$t4,%lo(var7005969c)
/*    42d3c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    42d40:	c5920018 */ 	lwc1	$f18,0x18($t4)
/*    42d44:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    42d48:	8fad0008 */ 	lw	$t5,0x8($sp)
/*    42d4c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    42d50:	46068201 */ 	sub.s	$f8,$f16,$f6
/*    42d54:	e5a8ffe4 */ 	swc1	$f8,-0x1c($t5)
/*    42d58:	3c0e7006 */ 	lui	$t6,%hi(var7005969c)
/*    42d5c:	25ce969c */ 	addiu	$t6,$t6,%lo(var7005969c)
/*    42d60:	c5ca0018 */ 	lwc1	$f10,0x18($t6)
/*    42d64:	c7b20000 */ 	lwc1	$f18,0x0($sp)
/*    42d68:	3c0f7006 */ 	lui	$t7,%hi(var700596bc)
/*    42d6c:	25ef96bc */ 	addiu	$t7,$t7,%lo(var700596bc)
/*    42d70:	46125102 */ 	mul.s	$f4,$f10,$f18
/*    42d74:	c5e60018 */ 	lwc1	$f6,0x18($t7)
/*    42d78:	c7b00004 */ 	lwc1	$f16,0x4($sp)
/*    42d7c:	8fb90008 */ 	lw	$t9,0x8($sp)
/*    42d80:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    42d84:	46082280 */ 	add.s	$f10,$f4,$f8
/*    42d88:	e72a0018 */ 	swc1	$f10,0x18($t9)
/*    42d8c:	8fb80008 */ 	lw	$t8,0x8($sp)
/*    42d90:	c712001c */ 	lwc1	$f18,0x1c($t8)
/*    42d94:	e7b20004 */ 	swc1	$f18,0x4($sp)
/*    42d98:	8fa80008 */ 	lw	$t0,0x8($sp)
/*    42d9c:	c510ffe0 */ 	lwc1	$f16,-0x20($t0)
/*    42da0:	e7b00000 */ 	swc1	$f16,0x0($sp)
/*    42da4:	3c097006 */ 	lui	$t1,%hi(var700596bc)
/*    42da8:	252996bc */ 	addiu	$t1,$t1,%lo(var700596bc)
/*    42dac:	c524001c */ 	lwc1	$f4,0x1c($t1)
/*    42db0:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*    42db4:	3c0a7006 */ 	lui	$t2,%hi(var7005969c)
/*    42db8:	254a969c */ 	addiu	$t2,$t2,%lo(var7005969c)
/*    42dbc:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    42dc0:	c54a001c */ 	lwc1	$f10,0x1c($t2)
/*    42dc4:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    42dc8:	8fab0008 */ 	lw	$t3,0x8($sp)
/*    42dcc:	46125402 */ 	mul.s	$f16,$f10,$f18
/*    42dd0:	46104181 */ 	sub.s	$f6,$f8,$f16
/*    42dd4:	e566ffe0 */ 	swc1	$f6,-0x20($t3)
/*    42dd8:	3c0c7006 */ 	lui	$t4,%hi(var7005969c)
/*    42ddc:	258c969c */ 	addiu	$t4,$t4,%lo(var7005969c)
/*    42de0:	c584001c */ 	lwc1	$f4,0x1c($t4)
/*    42de4:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    42de8:	3c0d7006 */ 	lui	$t5,%hi(var700596bc)
/*    42dec:	25ad96bc */ 	addiu	$t5,$t5,%lo(var700596bc)
/*    42df0:	460a2482 */ 	mul.s	$f18,$f4,$f10
/*    42df4:	c5b0001c */ 	lwc1	$f16,0x1c($t5)
/*    42df8:	c7a80004 */ 	lwc1	$f8,0x4($sp)
/*    42dfc:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    42e00:	46104182 */ 	mul.s	$f6,$f8,$f16
/*    42e04:	46069100 */ 	add.s	$f4,$f18,$f6
/*    42e08:	e5c4001c */ 	swc1	$f4,0x1c($t6)
/*    42e0c:	8faf000c */ 	lw	$t7,0xc($sp)
/*    42e10:	25f90001 */ 	addiu	$t9,$t7,0x1
/*    42e14:	2b210020 */ 	slti	$at,$t9,0x20
/*    42e18:	1420fef1 */ 	bnez	$at,.L000429e0
/*    42e1c:	afb9000c */ 	sw	$t9,0xc($sp)
/*    42e20:	10000003 */ 	b	.L00042e30
/*    42e24:	24020001 */ 	addiu	$v0,$zero,0x1
/*    42e28:	10000001 */ 	b	.L00042e30
/*    42e2c:	00000000 */ 	nop
.L00042e30:
/*    42e30:	03e00008 */ 	jr	$ra
/*    42e34:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func00042e38
/*    42e38:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    42e3c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    42e40:	afa40038 */ 	sw	$a0,0x38($sp)
/*    42e44:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    42e48:	8dcf3ba4 */ 	lw	$t7,0x3ba4($t6)
/*    42e4c:	11e0000e */ 	beqz	$t7,.L00042e88
/*    42e50:	00000000 */ 	nop
/*    42e54:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    42e58:	24010003 */ 	addiu	$at,$zero,0x3
/*    42e5c:	8f193bc0 */ 	lw	$t9,0x3bc0($t8)
/*    42e60:	17210004 */ 	bne	$t9,$at,.L00042e74
/*    42e64:	00000000 */ 	nop
/*    42e68:	24080011 */ 	addiu	$t0,$zero,0x11
/*    42e6c:	10000004 */ 	b	.L00042e80
/*    42e70:	af08206c */ 	sw	$t0,0x206c($t8)
.L00042e74:
/*    42e74:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    42e78:	24090020 */ 	addiu	$t1,$zero,0x20
/*    42e7c:	ad49206c */ 	sw	$t1,0x206c($t2)
.L00042e80:
/*    42e80:	1000000c */ 	b	.L00042eb4
/*    42e84:	00000000 */ 	nop
.L00042e88:
/*    42e88:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    42e8c:	24010003 */ 	addiu	$at,$zero,0x3
/*    42e90:	8d6c3bc0 */ 	lw	$t4,0x3bc0($t3)
/*    42e94:	15810004 */ 	bne	$t4,$at,.L00042ea8
/*    42e98:	00000000 */ 	nop
/*    42e9c:	240d0009 */ 	addiu	$t5,$zero,0x9
/*    42ea0:	10000004 */ 	b	.L00042eb4
/*    42ea4:	ad6d206c */ 	sw	$t5,0x206c($t3)
.L00042ea8:
/*    42ea8:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    42eac:	240e0011 */ 	addiu	$t6,$zero,0x11
/*    42eb0:	adee206c */ 	sw	$t6,0x206c($t7)
.L00042eb4:
/*    42eb4:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    42eb8:	2407ffff */ 	addiu	$a3,$zero,-1
/*    42ebc:	8f282068 */ 	lw	$t0,0x2068($t9)
/*    42ec0:	8f240000 */ 	lw	$a0,0x0($t9)
/*    42ec4:	8f26206c */ 	lw	$a2,0x206c($t9)
/*    42ec8:	03282821 */ 	addu	$a1,$t9,$t0
/*    42ecc:	8f390004 */ 	lw	$t9,0x4($t9)
/*    42ed0:	24a52024 */ 	addiu	$a1,$a1,0x2024
/*    42ed4:	0320f809 */ 	jalr	$t9
/*    42ed8:	00000000 */ 	nop
/*    42edc:	afa20034 */ 	sw	$v0,0x34($sp)
/*    42ee0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    42ee4:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    42ee8:	8f09206c */ 	lw	$t1,0x206c($t8)
/*    42eec:	112a0003 */ 	beq	$t1,$t2,.L00042efc
/*    42ef0:	00000000 */ 	nop
/*    42ef4:	10000205 */ 	b	.L0004370c
/*    42ef8:	00001025 */ 	or	$v0,$zero,$zero
.L00042efc:
/*    42efc:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    42f00:	8d8d0018 */ 	lw	$t5,0x18($t4)
/*    42f04:	8d8b206c */ 	lw	$t3,0x206c($t4)
/*    42f08:	01ab7021 */ 	addu	$t6,$t5,$t3
/*    42f0c:	ad8e0018 */ 	sw	$t6,0x18($t4)
/*    42f10:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    42f14:	24010003 */ 	addiu	$at,$zero,0x3
/*    42f18:	8de83bc0 */ 	lw	$t0,0x3bc0($t7)
/*    42f1c:	15010004 */ 	bne	$t0,$at,.L00042f30
/*    42f20:	00000000 */ 	nop
/*    42f24:	24190001 */ 	addiu	$t9,$zero,0x1
/*    42f28:	10000004 */ 	b	.L00042f3c
/*    42f2c:	adf93f8c */ 	sw	$t9,0x3f8c($t7)
.L00042f30:
/*    42f30:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    42f34:	24180002 */ 	addiu	$t8,$zero,0x2
/*    42f38:	ad383f8c */ 	sw	$t8,0x3f8c($t1)
.L00042f3c:
/*    42f3c:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    42f40:	8d4d3ba4 */ 	lw	$t5,0x3ba4($t2)
/*    42f44:	11a00004 */ 	beqz	$t5,.L00042f58
/*    42f48:	00000000 */ 	nop
/*    42f4c:	240b0002 */ 	addiu	$t3,$zero,0x2
/*    42f50:	10000004 */ 	b	.L00042f64
/*    42f54:	ad4b3f90 */ 	sw	$t3,0x3f90($t2)
.L00042f58:
/*    42f58:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    42f5c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    42f60:	ad8e3f90 */ 	sw	$t6,0x3f90($t4)
.L00042f64:
/*    42f64:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    42f68:	8d193ba4 */ 	lw	$t9,0x3ba4($t0)
/*    42f6c:	1320001a */ 	beqz	$t9,.L00042fd8
/*    42f70:	00000000 */ 	nop
/*    42f74:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    42f78:	24060009 */ 	addiu	$a2,$zero,0x9
/*    42f7c:	25e42024 */ 	addiu	$a0,$t7,0x2024
/*    42f80:	0c0118b1 */ 	jal	func000462c4
/*    42f84:	25e52064 */ 	addiu	$a1,$t7,0x2064
/*    42f88:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    42f8c:	af023bf4 */ 	sw	$v0,0x3bf4($t8)
/*    42f90:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    42f94:	24010001 */ 	addiu	$at,$zero,0x1
/*    42f98:	8d2d3f8c */ 	lw	$t5,0x3f8c($t1)
/*    42f9c:	15a10007 */ 	bne	$t5,$at,.L00042fbc
/*    42fa0:	00000000 */ 	nop
/*    42fa4:	25242024 */ 	addiu	$a0,$t1,0x2024
/*    42fa8:	25252064 */ 	addiu	$a1,$t1,0x2064
/*    42fac:	0c0118b1 */ 	jal	func000462c4
/*    42fb0:	24060005 */ 	addiu	$a2,$zero,0x5
/*    42fb4:	10000006 */ 	b	.L00042fd0
/*    42fb8:	00000000 */ 	nop
.L00042fbc:
/*    42fbc:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    42fc0:	24060003 */ 	addiu	$a2,$zero,0x3
/*    42fc4:	25642024 */ 	addiu	$a0,$t3,0x2024
/*    42fc8:	0c0118b1 */ 	jal	func000462c4
/*    42fcc:	25652064 */ 	addiu	$a1,$t3,0x2064
.L00042fd0:
/*    42fd0:	10000018 */ 	b	.L00043034
/*    42fd4:	00000000 */ 	nop
.L00042fd8:
/*    42fd8:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    42fdc:	24060008 */ 	addiu	$a2,$zero,0x8
/*    42fe0:	25442024 */ 	addiu	$a0,$t2,0x2024
/*    42fe4:	0c0118b1 */ 	jal	func000462c4
/*    42fe8:	25452064 */ 	addiu	$a1,$t2,0x2064
/*    42fec:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    42ff0:	adc23bf4 */ 	sw	$v0,0x3bf4($t6)
/*    42ff4:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    42ff8:	24010001 */ 	addiu	$at,$zero,0x1
/*    42ffc:	8d883f8c */ 	lw	$t0,0x3f8c($t4)
/*    43000:	15010007 */ 	bne	$t0,$at,.L00043020
/*    43004:	00000000 */ 	nop
/*    43008:	25842024 */ 	addiu	$a0,$t4,0x2024
/*    4300c:	25852064 */ 	addiu	$a1,$t4,0x2064
/*    43010:	0c0118b1 */ 	jal	func000462c4
/*    43014:	24060001 */ 	addiu	$a2,$zero,0x1
/*    43018:	10000006 */ 	b	.L00043034
/*    4301c:	00000000 */ 	nop
.L00043020:
/*    43020:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    43024:	24060002 */ 	addiu	$a2,$zero,0x2
/*    43028:	27242024 */ 	addiu	$a0,$t9,0x2024
/*    4302c:	0c0118b1 */ 	jal	func000462c4
/*    43030:	27252064 */ 	addiu	$a1,$t9,0x2064
.L00043034:
/*    43034:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    43038:	8df83ba4 */ 	lw	$t8,0x3ba4($t7)
/*    4303c:	13000021 */ 	beqz	$t8,.L000430c4
/*    43040:	00000000 */ 	nop
/*    43044:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    43048:	afa00030 */ 	sw	$zero,0x30($sp)
/*    4304c:	8da93f8c */ 	lw	$t1,0x3f8c($t5)
/*    43050:	1920001c */ 	blez	$t1,.L000430c4
/*    43054:	00000000 */ 	nop
.L00043058:
/*    43058:	afa0002c */ 	sw	$zero,0x2c($sp)
.L0004305c:
/*    4305c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    43060:	24060001 */ 	addiu	$a2,$zero,0x1
/*    43064:	25642024 */ 	addiu	$a0,$t3,0x2024
/*    43068:	0c0118b1 */ 	jal	func000462c4
/*    4306c:	25652064 */ 	addiu	$a1,$t3,0x2064
/*    43070:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    43074:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    43078:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    4307c:	000e41c0 */ 	sll	$t0,$t6,0x7
/*    43080:	01486021 */ 	addu	$t4,$t2,$t0
/*    43084:	00197880 */ 	sll	$t7,$t9,0x2
/*    43088:	018fc021 */ 	addu	$t8,$t4,$t7
/*    4308c:	af023bf8 */ 	sw	$v0,0x3bf8($t8)
/*    43090:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    43094:	25a90001 */ 	addiu	$t1,$t5,0x1
/*    43098:	29210004 */ 	slti	$at,$t1,0x4
/*    4309c:	1420ffef */ 	bnez	$at,.L0004305c
/*    430a0:	afa9002c */ 	sw	$t1,0x2c($sp)
/*    430a4:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    430a8:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    430ac:	256e0001 */ 	addiu	$t6,$t3,0x1
/*    430b0:	afae0030 */ 	sw	$t6,0x30($sp)
/*    430b4:	8d483f8c */ 	lw	$t0,0x3f8c($t2)
/*    430b8:	01c8082a */ 	slt	$at,$t6,$t0
/*    430bc:	1420ffe6 */ 	bnez	$at,.L00043058
/*    430c0:	00000000 */ 	nop
.L000430c4:
/*    430c4:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    430c8:	8f2c3ba4 */ 	lw	$t4,0x3ba4($t9)
/*    430cc:	11800004 */ 	beqz	$t4,.L000430e0
/*    430d0:	00000000 */ 	nop
/*    430d4:	240f0004 */ 	addiu	$t7,$zero,0x4
/*    430d8:	10000003 */ 	b	.L000430e8
/*    430dc:	afaf0028 */ 	sw	$t7,0x28($sp)
.L000430e0:
/*    430e0:	24180009 */ 	addiu	$t8,$zero,0x9
/*    430e4:	afb80028 */ 	sw	$t8,0x28($sp)
.L000430e8:
/*    430e8:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    430ec:	afa00024 */ 	sw	$zero,0x24($sp)
/*    430f0:	8da93f90 */ 	lw	$t1,0x3f90($t5)
/*    430f4:	19200138 */ 	blez	$t1,.L000435d8
/*    430f8:	00000000 */ 	nop
.L000430fc:
/*    430fc:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    43100:	afa00030 */ 	sw	$zero,0x30($sp)
/*    43104:	8d6a3f8c */ 	lw	$t2,0x3f8c($t3)
/*    43108:	1940012b */ 	blez	$t2,.L000435b8
/*    4310c:	00000000 */ 	nop
.L00043110:
/*    43110:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    43114:	2406000c */ 	addiu	$a2,$zero,0xc
/*    43118:	25c42024 */ 	addiu	$a0,$t6,0x2024
/*    4311c:	0c0118b1 */ 	jal	func000462c4
/*    43120:	25c52064 */ 	addiu	$a1,$t6,0x2064
/*    43124:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    43128:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    4312c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    43130:	00196080 */ 	sll	$t4,$t9,0x2
/*    43134:	010c7821 */ 	addu	$t7,$t0,$t4
/*    43138:	00186880 */ 	sll	$t5,$t8,0x2
/*    4313c:	01ed4821 */ 	addu	$t1,$t7,$t5
/*    43140:	ad223c78 */ 	sw	$v0,0x3c78($t1)
/*    43144:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    43148:	24060009 */ 	addiu	$a2,$zero,0x9
/*    4314c:	25642024 */ 	addiu	$a0,$t3,0x2024
/*    43150:	0c0118b1 */ 	jal	func000462c4
/*    43154:	25652064 */ 	addiu	$a1,$t3,0x2064
/*    43158:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    4315c:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    43160:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    43164:	000ec880 */ 	sll	$t9,$t6,0x2
/*    43168:	01594021 */ 	addu	$t0,$t2,$t9
/*    4316c:	000cc080 */ 	sll	$t8,$t4,0x2
/*    43170:	01187821 */ 	addu	$t7,$t0,$t8
/*    43174:	ade23c80 */ 	sw	$v0,0x3c80($t7)
/*    43178:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    4317c:	24060008 */ 	addiu	$a2,$zero,0x8
/*    43180:	25a42024 */ 	addiu	$a0,$t5,0x2024
/*    43184:	0c0118b1 */ 	jal	func000462c4
/*    43188:	25a52064 */ 	addiu	$a1,$t5,0x2064
/*    4318c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    43190:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    43194:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    43198:	000b7080 */ 	sll	$t6,$t3,0x2
/*    4319c:	012e5021 */ 	addu	$t2,$t1,$t6
/*    431a0:	00196080 */ 	sll	$t4,$t9,0x2
/*    431a4:	014c4021 */ 	addu	$t0,$t2,$t4
/*    431a8:	ad023c88 */ 	sw	$v0,0x3c88($t0)
/*    431ac:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    431b0:	1300000f */ 	beqz	$t8,.L000431f0
/*    431b4:	00000000 */ 	nop
/*    431b8:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    431bc:	03003025 */ 	or	$a2,$t8,$zero
/*    431c0:	25e42024 */ 	addiu	$a0,$t7,0x2024
/*    431c4:	0c0118b1 */ 	jal	func000462c4
/*    431c8:	25e52064 */ 	addiu	$a1,$t7,0x2064
/*    431cc:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    431d0:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    431d4:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    431d8:	000b4880 */ 	sll	$t1,$t3,0x2
/*    431dc:	01a97021 */ 	addu	$t6,$t5,$t1
/*    431e0:	00195080 */ 	sll	$t2,$t9,0x2
/*    431e4:	01ca6021 */ 	addu	$t4,$t6,$t2
/*    431e8:	10000009 */ 	b	.L00043210
/*    431ec:	ad823c90 */ 	sw	$v0,0x3c90($t4)
.L000431f0:
/*    431f0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    431f4:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    431f8:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    431fc:	000fc080 */ 	sll	$t8,$t7,0x2
/*    43200:	01185821 */ 	addu	$t3,$t0,$t8
/*    43204:	000d4880 */ 	sll	$t1,$t5,0x2
/*    43208:	0169c821 */ 	addu	$t9,$t3,$t1
/*    4320c:	af203c90 */ 	sw	$zero,0x3c90($t9)
.L00043210:
/*    43210:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    43214:	24060001 */ 	addiu	$a2,$zero,0x1
/*    43218:	25c42024 */ 	addiu	$a0,$t6,0x2024
/*    4321c:	0c0118b1 */ 	jal	func000462c4
/*    43220:	25c52064 */ 	addiu	$a1,$t6,0x2064
/*    43224:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    43228:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    4322c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    43230:	000c7880 */ 	sll	$t7,$t4,0x2
/*    43234:	014f4021 */ 	addu	$t0,$t2,$t7
/*    43238:	00186880 */ 	sll	$t5,$t8,0x2
/*    4323c:	010d5821 */ 	addu	$t3,$t0,$t5
/*    43240:	ad623c98 */ 	sw	$v0,0x3c98($t3)
/*    43244:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    43248:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    4324c:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    43250:	00197080 */ 	sll	$t6,$t9,0x2
/*    43254:	012e6021 */ 	addu	$t4,$t1,$t6
/*    43258:	000a7880 */ 	sll	$t7,$t2,0x2
/*    4325c:	018fc021 */ 	addu	$t8,$t4,$t7
/*    43260:	8f083c98 */ 	lw	$t0,0x3c98($t8)
/*    43264:	1100005d */ 	beqz	$t0,.L000433dc
/*    43268:	00000000 */ 	nop
/*    4326c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    43270:	24060002 */ 	addiu	$a2,$zero,0x2
/*    43274:	25a42024 */ 	addiu	$a0,$t5,0x2024
/*    43278:	0c0118b1 */ 	jal	func000462c4
/*    4327c:	25a52064 */ 	addiu	$a1,$t5,0x2064
/*    43280:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    43284:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    43288:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    4328c:	00194880 */ 	sll	$t1,$t9,0x2
/*    43290:	01697021 */ 	addu	$t6,$t3,$t1
/*    43294:	000a6080 */ 	sll	$t4,$t2,0x2
/*    43298:	01cc7821 */ 	addu	$t7,$t6,$t4
/*    4329c:	ade23ca0 */ 	sw	$v0,0x3ca0($t7)
/*    432a0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    432a4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    432a8:	27042024 */ 	addiu	$a0,$t8,0x2024
/*    432ac:	0c0118b1 */ 	jal	func000462c4
/*    432b0:	27052064 */ 	addiu	$a1,$t8,0x2064
/*    432b4:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    432b8:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    432bc:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    432c0:	000dc880 */ 	sll	$t9,$t5,0x2
/*    432c4:	01195821 */ 	addu	$t3,$t0,$t9
/*    432c8:	00095080 */ 	sll	$t2,$t1,0x2
/*    432cc:	016a7021 */ 	addu	$t6,$t3,$t2
/*    432d0:	adc23ca8 */ 	sw	$v0,0x3ca8($t6)
/*    432d4:	afa00020 */ 	sw	$zero,0x20($sp)
.L000432d8:
/*    432d8:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    432dc:	24060005 */ 	addiu	$a2,$zero,0x5
/*    432e0:	25842024 */ 	addiu	$a0,$t4,0x2024
/*    432e4:	0c0118b1 */ 	jal	func000462c4
/*    432e8:	25852064 */ 	addiu	$a1,$t4,0x2064
/*    432ec:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    432f0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    432f4:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    432f8:	00186880 */ 	sll	$t5,$t8,0x2
/*    432fc:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    43300:	01b86823 */ 	subu	$t5,$t5,$t8
/*    43304:	00194880 */ 	sll	$t1,$t9,0x2
/*    43308:	000d6880 */ 	sll	$t5,$t5,0x2
/*    4330c:	01394823 */ 	subu	$t1,$t1,$t9
/*    43310:	00094880 */ 	sll	$t1,$t1,0x2
/*    43314:	01ed4021 */ 	addu	$t0,$t7,$t5
/*    43318:	01095821 */ 	addu	$t3,$t0,$t1
/*    4331c:	000a7080 */ 	sll	$t6,$t2,0x2
/*    43320:	016e6021 */ 	addu	$t4,$t3,$t6
/*    43324:	ad823cb0 */ 	sw	$v0,0x3cb0($t4)
/*    43328:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    4332c:	270f0001 */ 	addiu	$t7,$t8,0x1
/*    43330:	29e10002 */ 	slti	$at,$t7,0x2
/*    43334:	1420ffe8 */ 	bnez	$at,.L000432d8
/*    43338:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    4333c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    43340:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    43344:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    43348:	00194080 */ 	sll	$t0,$t9,0x2
/*    4334c:	01194023 */ 	subu	$t0,$t0,$t9
/*    43350:	000a5880 */ 	sll	$t3,$t2,0x2
/*    43354:	00084080 */ 	sll	$t0,$t0,0x2
/*    43358:	016a5823 */ 	subu	$t3,$t3,$t2
/*    4335c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    43360:	01a84821 */ 	addu	$t1,$t5,$t0
/*    43364:	012b7021 */ 	addu	$t6,$t1,$t3
/*    43368:	adc03cb8 */ 	sw	$zero,0x3cb8($t6)
/*    4336c:	afa0001c */ 	sw	$zero,0x1c($sp)
.L00043370:
/*    43370:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    43374:	24060003 */ 	addiu	$a2,$zero,0x3
/*    43378:	25842024 */ 	addiu	$a0,$t4,0x2024
/*    4337c:	0c0118b1 */ 	jal	func000462c4
/*    43380:	25852064 */ 	addiu	$a1,$t4,0x2064
/*    43384:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    43388:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    4338c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    43390:	000fc880 */ 	sll	$t9,$t7,0x2
/*    43394:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    43398:	032fc823 */ 	subu	$t9,$t9,$t7
/*    4339c:	00085080 */ 	sll	$t2,$t0,0x2
/*    433a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    433a4:	01485023 */ 	subu	$t2,$t2,$t0
/*    433a8:	000a5080 */ 	sll	$t2,$t2,0x2
/*    433ac:	03196821 */ 	addu	$t5,$t8,$t9
/*    433b0:	01aa4821 */ 	addu	$t1,$t5,$t2
/*    433b4:	000b7080 */ 	sll	$t6,$t3,0x2
/*    433b8:	012e6021 */ 	addu	$t4,$t1,$t6
/*    433bc:	ad823cc8 */ 	sw	$v0,0x3cc8($t4)
/*    433c0:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    433c4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    433c8:	2b010003 */ 	slti	$at,$t8,0x3
/*    433cc:	1420ffe8 */ 	bnez	$at,.L00043370
/*    433d0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*    433d4:	10000045 */ 	b	.L000434ec
/*    433d8:	00000000 */ 	nop
.L000433dc:
/*    433dc:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    433e0:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    433e4:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    433e8:	00086880 */ 	sll	$t5,$t0,0x2
/*    433ec:	032d5021 */ 	addu	$t2,$t9,$t5
/*    433f0:	000b4880 */ 	sll	$t1,$t3,0x2
/*    433f4:	01497021 */ 	addu	$t6,$t2,$t1
/*    433f8:	adc03ca0 */ 	sw	$zero,0x3ca0($t6)
/*    433fc:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    43400:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    43404:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    43408:	000fc080 */ 	sll	$t8,$t7,0x2
/*    4340c:	01984021 */ 	addu	$t0,$t4,$t8
/*    43410:	00196880 */ 	sll	$t5,$t9,0x2
/*    43414:	010d5821 */ 	addu	$t3,$t0,$t5
/*    43418:	ad603ca8 */ 	sw	$zero,0x3ca8($t3)
/*    4341c:	afa00020 */ 	sw	$zero,0x20($sp)
.L00043420:
/*    43420:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    43424:	24060005 */ 	addiu	$a2,$zero,0x5
/*    43428:	25442024 */ 	addiu	$a0,$t2,0x2024
/*    4342c:	0c0118b1 */ 	jal	func000462c4
/*    43430:	25452064 */ 	addiu	$a1,$t2,0x2064
/*    43434:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    43438:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    4343c:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    43440:	000e7880 */ 	sll	$t7,$t6,0x2
/*    43444:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    43448:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    4344c:	0018c880 */ 	sll	$t9,$t8,0x2
/*    43450:	000f7880 */ 	sll	$t7,$t7,0x2
/*    43454:	0338c823 */ 	subu	$t9,$t9,$t8
/*    43458:	0019c880 */ 	sll	$t9,$t9,0x2
/*    4345c:	012f6021 */ 	addu	$t4,$t1,$t7
/*    43460:	01994021 */ 	addu	$t0,$t4,$t9
/*    43464:	000d5880 */ 	sll	$t3,$t5,0x2
/*    43468:	010b5021 */ 	addu	$t2,$t0,$t3
/*    4346c:	ad423cb0 */ 	sw	$v0,0x3cb0($t2)
/*    43470:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    43474:	25c90001 */ 	addiu	$t1,$t6,0x1
/*    43478:	29210003 */ 	slti	$at,$t1,0x3
/*    4347c:	1420ffe8 */ 	bnez	$at,.L00043420
/*    43480:	afa90020 */ 	sw	$t1,0x20($sp)
/*    43484:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    43488:	24060004 */ 	addiu	$a2,$zero,0x4
/*    4348c:	25e42024 */ 	addiu	$a0,$t7,0x2024
/*    43490:	0c0118b1 */ 	jal	func000462c4
/*    43494:	25e52064 */ 	addiu	$a1,$t7,0x2064
/*    43498:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    4349c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    434a0:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    434a4:	000cc880 */ 	sll	$t9,$t4,0x2
/*    434a8:	03196821 */ 	addu	$t5,$t8,$t9
/*    434ac:	00085880 */ 	sll	$t3,$t0,0x2
/*    434b0:	01ab5021 */ 	addu	$t2,$t5,$t3
/*    434b4:	ad423ce0 */ 	sw	$v0,0x3ce0($t2)
/*    434b8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    434bc:	24060003 */ 	addiu	$a2,$zero,0x3
/*    434c0:	25c42024 */ 	addiu	$a0,$t6,0x2024
/*    434c4:	0c0118b1 */ 	jal	func000462c4
/*    434c8:	25c52064 */ 	addiu	$a1,$t6,0x2064
/*    434cc:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    434d0:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    434d4:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    434d8:	000f6080 */ 	sll	$t4,$t7,0x2
/*    434dc:	012cc021 */ 	addu	$t8,$t1,$t4
/*    434e0:	00194080 */ 	sll	$t0,$t9,0x2
/*    434e4:	03086821 */ 	addu	$t5,$t8,$t0
/*    434e8:	ada23ce8 */ 	sw	$v0,0x3ce8($t5)
.L000434ec:
/*    434ec:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    434f0:	8d6a3ba4 */ 	lw	$t2,0x3ba4($t3)
/*    434f4:	1140000e */ 	beqz	$t2,.L00043530
/*    434f8:	00000000 */ 	nop
/*    434fc:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    43500:	24060001 */ 	addiu	$a2,$zero,0x1
/*    43504:	25c42024 */ 	addiu	$a0,$t6,0x2024
/*    43508:	0c0118b1 */ 	jal	func000462c4
/*    4350c:	25c52064 */ 	addiu	$a1,$t6,0x2064
/*    43510:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    43514:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    43518:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    4351c:	00096080 */ 	sll	$t4,$t1,0x2
/*    43520:	01ecc821 */ 	addu	$t9,$t7,$t4
/*    43524:	00184080 */ 	sll	$t0,$t8,0x2
/*    43528:	03286821 */ 	addu	$t5,$t9,$t0
/*    4352c:	ada23cf0 */ 	sw	$v0,0x3cf0($t5)
.L00043530:
/*    43530:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    43534:	24060001 */ 	addiu	$a2,$zero,0x1
/*    43538:	25642024 */ 	addiu	$a0,$t3,0x2024
/*    4353c:	0c0118b1 */ 	jal	func000462c4
/*    43540:	25652064 */ 	addiu	$a1,$t3,0x2064
/*    43544:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    43548:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    4354c:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    43550:	000e4880 */ 	sll	$t1,$t6,0x2
/*    43554:	01497821 */ 	addu	$t7,$t2,$t1
/*    43558:	000cc080 */ 	sll	$t8,$t4,0x2
/*    4355c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    43560:	af223cf8 */ 	sw	$v0,0x3cf8($t9)
/*    43564:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    43568:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4356c:	25042024 */ 	addiu	$a0,$t0,0x2024
/*    43570:	0c0118b1 */ 	jal	func000462c4
/*    43574:	25052064 */ 	addiu	$a1,$t0,0x2064
/*    43578:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    4357c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    43580:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    43584:	000b7080 */ 	sll	$t6,$t3,0x2
/*    43588:	01ae5021 */ 	addu	$t2,$t5,$t6
/*    4358c:	00096080 */ 	sll	$t4,$t1,0x2
/*    43590:	014c7821 */ 	addu	$t7,$t2,$t4
/*    43594:	ade23d00 */ 	sw	$v0,0x3d00($t7)
/*    43598:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    4359c:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    435a0:	27190001 */ 	addiu	$t9,$t8,0x1
/*    435a4:	afb90030 */ 	sw	$t9,0x30($sp)
/*    435a8:	8d0b3f8c */ 	lw	$t3,0x3f8c($t0)
/*    435ac:	032b082a */ 	slt	$at,$t9,$t3
/*    435b0:	1420fed7 */ 	bnez	$at,.L00043110
/*    435b4:	00000000 */ 	nop
.L000435b8:
/*    435b8:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    435bc:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    435c0:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    435c4:	afae0024 */ 	sw	$t6,0x24($sp)
/*    435c8:	8d2a3f90 */ 	lw	$t2,0x3f90($t1)
/*    435cc:	01ca082a */ 	slt	$at,$t6,$t2
/*    435d0:	1420feca */ 	bnez	$at,.L000430fc
/*    435d4:	00000000 */ 	nop
.L000435d8:
/*    435d8:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    435dc:	3c0d7006 */ 	lui	$t5,%hi(var700596dc)
/*    435e0:	8d8f3ba4 */ 	lw	$t7,0x3ba4($t4)
/*    435e4:	8d883bb0 */ 	lw	$t0,0x3bb0($t4)
/*    435e8:	000fc100 */ 	sll	$t8,$t7,0x4
/*    435ec:	030fc023 */ 	subu	$t8,$t8,$t7
/*    435f0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    435f4:	0008c880 */ 	sll	$t9,$t0,0x2
/*    435f8:	03195821 */ 	addu	$t3,$t8,$t9
/*    435fc:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    43600:	8dad96dc */ 	lw	$t5,%lo(var700596dc)($t5)
/*    43604:	ad8d3f7c */ 	sw	$t5,0x3f7c($t4)
/*    43608:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    4360c:	3c197006 */ 	lui	$t9,%hi(var70059754)
/*    43610:	8d2e3ba4 */ 	lw	$t6,0x3ba4($t1)
/*    43614:	8d2f3bb4 */ 	lw	$t7,0x3bb4($t1)
/*    43618:	000e5100 */ 	sll	$t2,$t6,0x4
/*    4361c:	000f4080 */ 	sll	$t0,$t7,0x2
/*    43620:	0148c021 */ 	addu	$t8,$t2,$t0
/*    43624:	0338c821 */ 	addu	$t9,$t9,$t8
/*    43628:	8f399754 */ 	lw	$t9,%lo(var70059754)($t9)
/*    4362c:	ad393f80 */ 	sw	$t9,0x3f80($t1)
/*    43630:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    43634:	8d6d3ba4 */ 	lw	$t5,0x3ba4($t3)
/*    43638:	11a00015 */ 	beqz	$t5,.L00043690
/*    4363c:	00000000 */ 	nop
/*    43640:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    43644:	8d8e3f7c */ 	lw	$t6,0x3f7c($t4)
/*    43648:	8d8a3f80 */ 	lw	$t2,0x3f80($t4)
/*    4364c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*    43650:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    43654:	000f7900 */ 	sll	$t7,$t7,0x4
/*    43658:	01ea001a */ 	div	$zero,$t7,$t2
/*    4365c:	00004012 */ 	mflo	$t0
/*    43660:	ad883f84 */ 	sw	$t0,0x3f84($t4)
/*    43664:	15400002 */ 	bnez	$t2,.L00043670
/*    43668:	00000000 */ 	nop
/*    4366c:	0007000d */ 	break	0x7
.L00043670:
/*    43670:	2401ffff */ 	addiu	$at,$zero,-1
/*    43674:	15410004 */ 	bne	$t2,$at,.L00043688
/*    43678:	3c018000 */ 	lui	$at,0x8000
/*    4367c:	15e10002 */ 	bne	$t7,$at,.L00043688
/*    43680:	00000000 */ 	nop
/*    43684:	0006000d */ 	break	0x6
.L00043688:
/*    43688:	10000013 */ 	b	.L000436d8
/*    4368c:	00000000 */ 	nop
.L00043690:
/*    43690:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    43694:	8f193f7c */ 	lw	$t9,0x3f7c($t8)
/*    43698:	8f0b3f80 */ 	lw	$t3,0x3f80($t8)
/*    4369c:	001948c0 */ 	sll	$t1,$t9,0x3
/*    436a0:	01394821 */ 	addu	$t1,$t1,$t9
/*    436a4:	000948c0 */ 	sll	$t1,$t1,0x3
/*    436a8:	012b001a */ 	div	$zero,$t1,$t3
/*    436ac:	00006812 */ 	mflo	$t5
/*    436b0:	af0d3f84 */ 	sw	$t5,0x3f84($t8)
/*    436b4:	15600002 */ 	bnez	$t3,.L000436c0
/*    436b8:	00000000 */ 	nop
/*    436bc:	0007000d */ 	break	0x7
.L000436c0:
/*    436c0:	2401ffff */ 	addiu	$at,$zero,-1
/*    436c4:	15610004 */ 	bne	$t3,$at,.L000436d8
/*    436c8:	3c018000 */ 	lui	$at,0x8000
/*    436cc:	15210002 */ 	bne	$t1,$at,.L000436d8
/*    436d0:	00000000 */ 	nop
/*    436d4:	0006000d */ 	break	0x6
.L000436d8:
/*    436d8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    436dc:	8dcf3f84 */ 	lw	$t7,0x3f84($t6)
/*    436e0:	8dca3bb8 */ 	lw	$t2,0x3bb8($t6)
/*    436e4:	8dcc2068 */ 	lw	$t4,0x2068($t6)
/*    436e8:	8dd9206c */ 	lw	$t9,0x206c($t6)
/*    436ec:	01ea4021 */ 	addu	$t0,$t7,$t2
/*    436f0:	01994821 */ 	addu	$t1,$t4,$t9
/*    436f4:	01095823 */ 	subu	$t3,$t0,$t1
/*    436f8:	adcb3f88 */ 	sw	$t3,0x3f88($t6)
/*    436fc:	10000003 */ 	b	.L0004370c
/*    43700:	24020001 */ 	addiu	$v0,$zero,0x1
/*    43704:	10000001 */ 	b	.L0004370c
/*    43708:	00000000 */ 	nop
.L0004370c:
/*    4370c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    43710:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    43714:	03e00008 */ 	jr	$ra
/*    43718:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004371c
/*    4371c:	27bdf6a8 */ 	addiu	$sp,$sp,-2392
/*    43720:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    43724:	afa40958 */ 	sw	$a0,0x958($sp)
/*    43728:	afa00950 */ 	sw	$zero,0x950($sp)
/*    4372c:	8fae0958 */ 	lw	$t6,0x958($sp)
/*    43730:	8dcf3ba0 */ 	lw	$t7,0x3ba0($t6)
/*    43734:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*    43738:	030fc021 */ 	addu	$t8,$t8,$t7
/*    4373c:	0018c100 */ 	sll	$t8,$t8,0x4
/*    43740:	030fc021 */ 	addu	$t8,$t8,$t7
/*    43744:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    43748:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    4374c:	27282070 */ 	addiu	$t0,$t9,0x2070
/*    43750:	afa80934 */ 	sw	$t0,0x934($sp)
/*    43754:	0c010f74 */ 	jal	func00043dd0
/*    43758:	8fa40958 */ 	lw	$a0,0x958($sp)
/*    4375c:	afa20954 */ 	sw	$v0,0x954($sp)
/*    43760:	8fa90954 */ 	lw	$t1,0x954($sp)
/*    43764:	2401ffff */ 	addiu	$at,$zero,-1
/*    43768:	15210003 */ 	bne	$t1,$at,.L00043778
/*    4376c:	00000000 */ 	nop
/*    43770:	10000192 */ 	b	.L00043dbc
/*    43774:	00001025 */ 	or	$v0,$zero,$zero
.L00043778:
/*    43778:	8fab0958 */ 	lw	$t3,0x958($sp)
/*    4377c:	8faa0954 */ 	lw	$t2,0x954($sp)
/*    43780:	8d6c3bf4 */ 	lw	$t4,0x3bf4($t3)
/*    43784:	014c6823 */ 	subu	$t5,$t2,$t4
/*    43788:	000d78c0 */ 	sll	$t7,$t5,0x3
/*    4378c:	ad6f2020 */ 	sw	$t7,0x2020($t3)
/*    43790:	8fae0958 */ 	lw	$t6,0x958($sp)
/*    43794:	8dd82020 */ 	lw	$t8,0x2020($t6)
/*    43798:	07010003 */ 	bgez	$t8,.L000437a8
/*    4379c:	00000000 */ 	nop
/*    437a0:	10000186 */ 	b	.L00043dbc
/*    437a4:	24020001 */ 	addiu	$v0,$zero,0x1
.L000437a8:
/*    437a8:	8fb90958 */ 	lw	$t9,0x958($sp)
/*    437ac:	afa0094c */ 	sw	$zero,0x94c($sp)
/*    437b0:	8f283f8c */ 	lw	$t0,0x3f8c($t9)
/*    437b4:	19000011 */ 	blez	$t0,.L000437fc
/*    437b8:	00000000 */ 	nop
.L000437bc:
/*    437bc:	8fa40958 */ 	lw	$a0,0x958($sp)
/*    437c0:	8fa50950 */ 	lw	$a1,0x950($sp)
/*    437c4:	0c01088e */ 	jal	func00042238
/*    437c8:	8fa6094c */ 	lw	$a2,0x94c($sp)
/*    437cc:	8fa40958 */ 	lw	$a0,0x958($sp)
/*    437d0:	8fa50950 */ 	lw	$a1,0x950($sp)
/*    437d4:	0c010059 */ 	jal	func00040164
/*    437d8:	8fa6094c */ 	lw	$a2,0x94c($sp)
/*    437dc:	8fa9094c */ 	lw	$t1,0x94c($sp)
/*    437e0:	8fac0958 */ 	lw	$t4,0x958($sp)
/*    437e4:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    437e8:	afaa094c */ 	sw	$t2,0x94c($sp)
/*    437ec:	8d8d3f8c */ 	lw	$t5,0x3f8c($t4)
/*    437f0:	014d082a */ 	slt	$at,$t2,$t5
/*    437f4:	1420fff1 */ 	bnez	$at,.L000437bc
/*    437f8:	00000000 */ 	nop
.L000437fc:
/*    437fc:	8fa40958 */ 	lw	$a0,0x958($sp)
/*    43800:	0c0109f6 */ 	jal	func000427d8
/*    43804:	8fa50950 */ 	lw	$a1,0x950($sp)
/*    43808:	8fab0950 */ 	lw	$t3,0x950($sp)
/*    4380c:	8faf0958 */ 	lw	$t7,0x958($sp)
/*    43810:	000b7080 */ 	sll	$t6,$t3,0x2
/*    43814:	01eec021 */ 	addu	$t8,$t7,$t6
/*    43818:	8f193c98 */ 	lw	$t9,0x3c98($t8)
/*    4381c:	13200008 */ 	beqz	$t9,.L00043840
/*    43820:	00000000 */ 	nop
/*    43824:	8f083ca0 */ 	lw	$t0,0x3ca0($t8)
/*    43828:	24010002 */ 	addiu	$at,$zero,0x2
/*    4382c:	15010004 */ 	bne	$t0,$at,.L00043840
/*    43830:	00000000 */ 	nop
/*    43834:	24090020 */ 	addiu	$t1,$zero,0x20
/*    43838:	1000000b */ 	b	.L00043868
/*    4383c:	afa90948 */ 	sw	$t1,0x948($sp)
.L00043840:
/*    43840:	8fac0958 */ 	lw	$t4,0x958($sp)
/*    43844:	24010012 */ 	addiu	$at,$zero,0x12
/*    43848:	8d8a465c */ 	lw	$t2,0x465c($t4)
/*    4384c:	254dffff */ 	addiu	$t5,$t2,-1
/*    43850:	01a1001a */ 	div	$zero,$t5,$at
/*    43854:	00005812 */ 	mflo	$t3
/*    43858:	256f0001 */ 	addiu	$t7,$t3,0x1
/*    4385c:	afaf0944 */ 	sw	$t7,0x944($sp)
/*    43860:	8fae0944 */ 	lw	$t6,0x944($sp)
/*    43864:	afae0948 */ 	sw	$t6,0x948($sp)
.L00043868:
/*    43868:	8fb90958 */ 	lw	$t9,0x958($sp)
/*    4386c:	afa0094c */ 	sw	$zero,0x94c($sp)
/*    43870:	8f383f8c */ 	lw	$t8,0x3f8c($t9)
/*    43874:	1b00014d */ 	blez	$t8,.L00043dac
/*    43878:	00000000 */ 	nop
.L0004387c:
/*    4387c:	8fa40958 */ 	lw	$a0,0x958($sp)
/*    43880:	8fa50950 */ 	lw	$a1,0x950($sp)
/*    43884:	0c010a64 */ 	jal	func00042990
/*    43888:	8fa6094c */ 	lw	$a2,0x94c($sp)
/*    4388c:	8fa90950 */ 	lw	$t1,0x950($sp)
/*    43890:	8fa80958 */ 	lw	$t0,0x958($sp)
/*    43894:	8fad094c */ 	lw	$t5,0x94c($sp)
/*    43898:	00096080 */ 	sll	$t4,$t1,0x2
/*    4389c:	010c5021 */ 	addu	$t2,$t0,$t4
/*    438a0:	000d5880 */ 	sll	$t3,$t5,0x2
/*    438a4:	014b7821 */ 	addu	$t7,$t2,$t3
/*    438a8:	8dee3c98 */ 	lw	$t6,0x3c98($t7)
/*    438ac:	11c0000a */ 	beqz	$t6,.L000438d8
/*    438b0:	00000000 */ 	nop
/*    438b4:	8df93ca0 */ 	lw	$t9,0x3ca0($t7)
/*    438b8:	24010002 */ 	addiu	$at,$zero,0x2
/*    438bc:	17210006 */ 	bne	$t9,$at,.L000438d8
/*    438c0:	00000000 */ 	nop
/*    438c4:	8df83ca8 */ 	lw	$t8,0x3ca8($t7)
/*    438c8:	13000003 */ 	beqz	$t8,.L000438d8
/*    438cc:	00000000 */ 	nop
/*    438d0:	10000016 */ 	b	.L0004392c
/*    438d4:	afa00940 */ 	sw	$zero,0x940($sp)
.L000438d8:
/*    438d8:	8fa80950 */ 	lw	$t0,0x950($sp)
/*    438dc:	8fa90958 */ 	lw	$t1,0x958($sp)
/*    438e0:	8faa094c */ 	lw	$t2,0x94c($sp)
/*    438e4:	00086080 */ 	sll	$t4,$t0,0x2
/*    438e8:	012c6821 */ 	addu	$t5,$t1,$t4
/*    438ec:	000a5880 */ 	sll	$t3,$t2,0x2
/*    438f0:	01ab7021 */ 	addu	$t6,$t5,$t3
/*    438f4:	8dd93c98 */ 	lw	$t9,0x3c98($t6)
/*    438f8:	17200003 */ 	bnez	$t9,.L00043908
/*    438fc:	00000000 */ 	nop
/*    43900:	1000000a */ 	b	.L0004392c
/*    43904:	afa00940 */ 	sw	$zero,0x940($sp)
.L00043908:
/*    43908:	8fb80950 */ 	lw	$t8,0x950($sp)
/*    4390c:	8faf0958 */ 	lw	$t7,0x958($sp)
/*    43910:	8fac094c */ 	lw	$t4,0x94c($sp)
/*    43914:	00184080 */ 	sll	$t0,$t8,0x2
/*    43918:	01e84821 */ 	addu	$t1,$t7,$t0
/*    4391c:	000c5080 */ 	sll	$t2,$t4,0x2
/*    43920:	012a6821 */ 	addu	$t5,$t1,$t2
/*    43924:	8dab3ca0 */ 	lw	$t3,0x3ca0($t5)
/*    43928:	afab0940 */ 	sw	$t3,0x940($sp)
.L0004392c:
/*    4392c:	8fae0940 */ 	lw	$t6,0x940($sp)
/*    43930:	24010002 */ 	addiu	$at,$zero,0x2
/*    43934:	15c1001a */ 	bne	$t6,$at,.L000439a0
/*    43938:	00000000 */ 	nop
/*    4393c:	afa0093c */ 	sw	$zero,0x93c($sp)
.L00043940:
/*    43940:	8fb8094c */ 	lw	$t8,0x94c($sp)
/*    43944:	8fac093c */ 	lw	$t4,0x93c($sp)
/*    43948:	8fb90958 */ 	lw	$t9,0x958($sp)
/*    4394c:	001878c0 */ 	sll	$t7,$t8,0x3
/*    43950:	01f87821 */ 	addu	$t7,$t7,$t8
/*    43954:	000c48c0 */ 	sll	$t1,$t4,0x3
/*    43958:	000f7a00 */ 	sll	$t7,$t7,0x8
/*    4395c:	012c4821 */ 	addu	$t1,$t1,$t4
/*    43960:	000948c0 */ 	sll	$t1,$t1,0x3
/*    43964:	032f4021 */ 	addu	$t0,$t9,$t7
/*    43968:	01095021 */ 	addu	$t2,$t0,$t1
/*    4396c:	27ad0034 */ 	addiu	$t5,$sp,0x34
/*    43970:	012d3021 */ 	addu	$a2,$t1,$t5
/*    43974:	25444f64 */ 	addiu	$a0,$t2,0x4f64
/*    43978:	25476a64 */ 	addiu	$a3,$t2,0x6a64
/*    4397c:	0c011d54 */ 	jal	func00047550
/*    43980:	01802825 */ 	or	$a1,$t4,$zero
/*    43984:	8fab093c */ 	lw	$t3,0x93c($sp)
/*    43988:	256e0001 */ 	addiu	$t6,$t3,0x1
/*    4398c:	29c10002 */ 	slti	$at,$t6,0x2
/*    43990:	1420ffeb */ 	bnez	$at,.L00043940
/*    43994:	afae093c */ 	sw	$t6,0x93c($sp)
/*    43998:	10000020 */ 	b	.L00043a1c
/*    4399c:	00000000 */ 	nop
.L000439a0:
/*    439a0:	afa0093c */ 	sw	$zero,0x93c($sp)
.L000439a4:
/*    439a4:	8fb9094c */ 	lw	$t9,0x94c($sp)
/*    439a8:	8fac093c */ 	lw	$t4,0x93c($sp)
/*    439ac:	8fab0940 */ 	lw	$t3,0x940($sp)
/*    439b0:	8fb80958 */ 	lw	$t8,0x958($sp)
/*    439b4:	001978c0 */ 	sll	$t7,$t9,0x3
/*    439b8:	01f97821 */ 	addu	$t7,$t7,$t9
/*    439bc:	000f7a00 */ 	sll	$t7,$t7,0x8
/*    439c0:	000c48c0 */ 	sll	$t1,$t4,0x3
/*    439c4:	000b70c0 */ 	sll	$t6,$t3,0x3
/*    439c8:	3c19800a */ 	lui	$t9,%hi(var8009c400)
/*    439cc:	012c4821 */ 	addu	$t1,$t1,$t4
/*    439d0:	01cb7021 */ 	addu	$t6,$t6,$t3
/*    439d4:	030f4021 */ 	addu	$t0,$t8,$t7
/*    439d8:	000e7100 */ 	sll	$t6,$t6,0x4
/*    439dc:	000948c0 */ 	sll	$t1,$t1,0x3
/*    439e0:	2739c400 */ 	addiu	$t9,$t9,%lo(var8009c400)
/*    439e4:	01d9c021 */ 	addu	$t8,$t6,$t9
/*    439e8:	01096821 */ 	addu	$t5,$t0,$t1
/*    439ec:	27aa0034 */ 	addiu	$t2,$sp,0x34
/*    439f0:	012a3021 */ 	addu	$a2,$t1,$t2
/*    439f4:	25a44f64 */ 	addiu	$a0,$t5,0x4f64
/*    439f8:	25a76a64 */ 	addiu	$a3,$t5,0x6a64
/*    439fc:	afb80010 */ 	sw	$t8,0x10($sp)
/*    43a00:	0c011994 */ 	jal	func00046650
/*    43a04:	01802825 */ 	or	$a1,$t4,$zero
/*    43a08:	8faf093c */ 	lw	$t7,0x93c($sp)
/*    43a0c:	25e80001 */ 	addiu	$t0,$t7,0x1
/*    43a10:	29010002 */ 	slti	$at,$t0,0x2
/*    43a14:	1420ffe3 */ 	bnez	$at,.L000439a4
/*    43a18:	afa8093c */ 	sw	$t0,0x93c($sp)
.L00043a1c:
/*    43a1c:	8fa90950 */ 	lw	$t1,0x950($sp)
/*    43a20:	8fac0958 */ 	lw	$t4,0x958($sp)
/*    43a24:	8fab094c */ 	lw	$t3,0x94c($sp)
/*    43a28:	00095080 */ 	sll	$t2,$t1,0x2
/*    43a2c:	018a6821 */ 	addu	$t5,$t4,$t2
/*    43a30:	000b7080 */ 	sll	$t6,$t3,0x2
/*    43a34:	01aec821 */ 	addu	$t9,$t5,$t6
/*    43a38:	8f383c98 */ 	lw	$t8,0x3c98($t9)
/*    43a3c:	1300000a */ 	beqz	$t8,.L00043a68
/*    43a40:	00000000 */ 	nop
/*    43a44:	8f2f3ca0 */ 	lw	$t7,0x3ca0($t9)
/*    43a48:	24010002 */ 	addiu	$at,$zero,0x2
/*    43a4c:	15e10006 */ 	bne	$t7,$at,.L00043a68
/*    43a50:	00000000 */ 	nop
/*    43a54:	8f283ca8 */ 	lw	$t0,0x3ca8($t9)
/*    43a58:	11000003 */ 	beqz	$t0,.L00043a68
/*    43a5c:	00000000 */ 	nop
/*    43a60:	24090002 */ 	addiu	$t1,$zero,0x2
/*    43a64:	afa90940 */ 	sw	$t1,0x940($sp)
.L00043a68:
/*    43a68:	8fac0940 */ 	lw	$t4,0x940($sp)
/*    43a6c:	24010002 */ 	addiu	$at,$zero,0x2
/*    43a70:	15810020 */ 	bne	$t4,$at,.L00043af4
/*    43a74:	00000000 */ 	nop
/*    43a78:	8fab0948 */ 	lw	$t3,0x948($sp)
/*    43a7c:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    43a80:	afaa093c */ 	sw	$t2,0x93c($sp)
/*    43a84:	29610003 */ 	slti	$at,$t3,0x3
/*    43a88:	14200018 */ 	bnez	$at,.L00043aec
/*    43a8c:	00000000 */ 	nop
.L00043a90:
/*    43a90:	8fae094c */ 	lw	$t6,0x94c($sp)
/*    43a94:	8fb9093c */ 	lw	$t9,0x93c($sp)
/*    43a98:	8fad0958 */ 	lw	$t5,0x958($sp)
/*    43a9c:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*    43aa0:	030ec021 */ 	addu	$t8,$t8,$t6
/*    43aa4:	001940c0 */ 	sll	$t0,$t9,0x3
/*    43aa8:	0018c200 */ 	sll	$t8,$t8,0x8
/*    43aac:	01194021 */ 	addu	$t0,$t0,$t9
/*    43ab0:	000840c0 */ 	sll	$t0,$t0,0x3
/*    43ab4:	01b87821 */ 	addu	$t7,$t5,$t8
/*    43ab8:	01e84821 */ 	addu	$t1,$t7,$t0
/*    43abc:	27ac0034 */ 	addiu	$t4,$sp,0x34
/*    43ac0:	010c3021 */ 	addu	$a2,$t0,$t4
/*    43ac4:	25244f64 */ 	addiu	$a0,$t1,0x4f64
/*    43ac8:	25276a64 */ 	addiu	$a3,$t1,0x6a64
/*    43acc:	0c011d54 */ 	jal	func00047550
/*    43ad0:	03202825 */ 	or	$a1,$t9,$zero
/*    43ad4:	8faa093c */ 	lw	$t2,0x93c($sp)
/*    43ad8:	8fae0948 */ 	lw	$t6,0x948($sp)
/*    43adc:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    43ae0:	016e082a */ 	slt	$at,$t3,$t6
/*    43ae4:	1420ffea */ 	bnez	$at,.L00043a90
/*    43ae8:	afab093c */ 	sw	$t3,0x93c($sp)
.L00043aec:
/*    43aec:	10000026 */ 	b	.L00043b88
/*    43af0:	00000000 */ 	nop
.L00043af4:
/*    43af4:	8fb80948 */ 	lw	$t8,0x948($sp)
/*    43af8:	240d0002 */ 	addiu	$t5,$zero,0x2
/*    43afc:	afad093c */ 	sw	$t5,0x93c($sp)
/*    43b00:	2b010003 */ 	slti	$at,$t8,0x3
/*    43b04:	14200020 */ 	bnez	$at,.L00043b88
/*    43b08:	00000000 */ 	nop
.L00043b0c:
/*    43b0c:	8fb9094c */ 	lw	$t9,0x94c($sp)
/*    43b10:	8fa9093c */ 	lw	$t1,0x93c($sp)
/*    43b14:	8fad0940 */ 	lw	$t5,0x940($sp)
/*    43b18:	8faf0958 */ 	lw	$t7,0x958($sp)
/*    43b1c:	001940c0 */ 	sll	$t0,$t9,0x3
/*    43b20:	01194021 */ 	addu	$t0,$t0,$t9
/*    43b24:	00084200 */ 	sll	$t0,$t0,0x8
/*    43b28:	000950c0 */ 	sll	$t2,$t1,0x3
/*    43b2c:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*    43b30:	3c19800a */ 	lui	$t9,%hi(var8009c400)
/*    43b34:	01495021 */ 	addu	$t2,$t2,$t1
/*    43b38:	030dc021 */ 	addu	$t8,$t8,$t5
/*    43b3c:	01e86021 */ 	addu	$t4,$t7,$t0
/*    43b40:	0018c100 */ 	sll	$t8,$t8,0x4
/*    43b44:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    43b48:	2739c400 */ 	addiu	$t9,$t9,%lo(var8009c400)
/*    43b4c:	03197821 */ 	addu	$t7,$t8,$t9
/*    43b50:	018a5821 */ 	addu	$t3,$t4,$t2
/*    43b54:	27ae0034 */ 	addiu	$t6,$sp,0x34
/*    43b58:	014e3021 */ 	addu	$a2,$t2,$t6
/*    43b5c:	25644f64 */ 	addiu	$a0,$t3,0x4f64
/*    43b60:	25676a64 */ 	addiu	$a3,$t3,0x6a64
/*    43b64:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    43b68:	0c011994 */ 	jal	func00046650
/*    43b6c:	01202825 */ 	or	$a1,$t1,$zero
/*    43b70:	8fa8093c */ 	lw	$t0,0x93c($sp)
/*    43b74:	8fa90948 */ 	lw	$t1,0x948($sp)
/*    43b78:	250c0001 */ 	addiu	$t4,$t0,0x1
/*    43b7c:	0189082a */ 	slt	$at,$t4,$t1
/*    43b80:	1420ffe2 */ 	bnez	$at,.L00043b0c
/*    43b84:	afac093c */ 	sw	$t4,0x93c($sp)
.L00043b88:
/*    43b88:	8faa093c */ 	lw	$t2,0x93c($sp)
/*    43b8c:	29410020 */ 	slti	$at,$t2,0x20
/*    43b90:	10200026 */ 	beqz	$at,.L00043c2c
/*    43b94:	00000000 */ 	nop
.L00043b98:
/*    43b98:	8fab094c */ 	lw	$t3,0x94c($sp)
/*    43b9c:	8fb9093c */ 	lw	$t9,0x93c($sp)
/*    43ba0:	8fae0958 */ 	lw	$t6,0x958($sp)
/*    43ba4:	000b68c0 */ 	sll	$t5,$t3,0x3
/*    43ba8:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    43bac:	001978c0 */ 	sll	$t7,$t9,0x3
/*    43bb0:	000d6a00 */ 	sll	$t5,$t5,0x8
/*    43bb4:	01f97821 */ 	addu	$t7,$t7,$t9
/*    43bb8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    43bbc:	01cdc021 */ 	addu	$t8,$t6,$t5
/*    43bc0:	030f2021 */ 	addu	$a0,$t8,$t7
/*    43bc4:	27a80034 */ 	addiu	$t0,$sp,0x34
/*    43bc8:	01e82821 */ 	addu	$a1,$t7,$t0
/*    43bcc:	24846a64 */ 	addiu	$a0,$a0,0x6a64
/*    43bd0:	0c012c5c */ 	jal	func0004b170
/*    43bd4:	24060048 */ 	addiu	$a2,$zero,0x48
/*    43bd8:	8fa9094c */ 	lw	$t1,0x94c($sp)
/*    43bdc:	8fae093c */ 	lw	$t6,0x93c($sp)
/*    43be0:	8fac0958 */ 	lw	$t4,0x958($sp)
/*    43be4:	000950c0 */ 	sll	$t2,$t1,0x3
/*    43be8:	01495021 */ 	addu	$t2,$t2,$t1
/*    43bec:	000e68c0 */ 	sll	$t5,$t6,0x3
/*    43bf0:	000a5200 */ 	sll	$t2,$t2,0x8
/*    43bf4:	01ae6821 */ 	addu	$t5,$t5,$t6
/*    43bf8:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    43bfc:	018a5821 */ 	addu	$t3,$t4,$t2
/*    43c00:	016d2021 */ 	addu	$a0,$t3,$t5
/*    43c04:	24846a64 */ 	addiu	$a0,$a0,0x6a64
/*    43c08:	0c012c30 */ 	jal	bzero
/*    43c0c:	24050048 */ 	addiu	$a1,$zero,0x48
/*    43c10:	8fb9093c */ 	lw	$t9,0x93c($sp)
/*    43c14:	27380001 */ 	addiu	$t8,$t9,0x1
/*    43c18:	afb8093c */ 	sw	$t8,0x93c($sp)
/*    43c1c:	8faf093c */ 	lw	$t7,0x93c($sp)
/*    43c20:	29e10020 */ 	slti	$at,$t7,0x20
/*    43c24:	1420ffdc */ 	bnez	$at,.L00043b98
/*    43c28:	00000000 */ 	nop
.L00043c2c:
/*    43c2c:	3c014780 */ 	lui	$at,0x4780
/*    43c30:	44812000 */ 	mtc1	$at,$f4
/*    43c34:	00000000 */ 	nop
/*    43c38:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*    43c3c:	3c013f80 */ 	lui	$at,0x3f80
/*    43c40:	44813000 */ 	mtc1	$at,$f6
/*    43c44:	00000000 */ 	nop
/*    43c48:	e7a60028 */ 	swc1	$f6,0x28($sp)
/*    43c4c:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*    43c50:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*    43c54:	3c014180 */ 	lui	$at,0x4180
/*    43c58:	44819000 */ 	mtc1	$at,$f18
/*    43c5c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    43c60:	00000000 */ 	nop
/*    43c64:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    43c68:	4600218d */ 	trunc.w.s	$f6,$f4
/*    43c6c:	44093000 */ 	mfc1	$t1,$f6
/*    43c70:	00000000 */ 	nop
/*    43c74:	afa90020 */ 	sw	$t1,0x20($sp)
/*    43c78:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    43c7c:	8fae0934 */ 	lw	$t6,0x934($sp)
/*    43c80:	000c5403 */ 	sra	$t2,$t4,0x10
/*    43c84:	a5ca0000 */ 	sh	$t2,0x0($t6)
/*    43c88:	8fab0934 */ 	lw	$t3,0x934($sp)
/*    43c8c:	256d0002 */ 	addiu	$t5,$t3,0x2
/*    43c90:	afad0934 */ 	sw	$t5,0x934($sp)
/*    43c94:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    43c98:	8faf0934 */ 	lw	$t7,0x934($sp)
/*    43c9c:	3338ffff */ 	andi	$t8,$t9,0xffff
/*    43ca0:	a5f80000 */ 	sh	$t8,0x0($t7)
/*    43ca4:	8fa80934 */ 	lw	$t0,0x934($sp)
/*    43ca8:	25090002 */ 	addiu	$t1,$t0,0x2
/*    43cac:	afa90934 */ 	sw	$t1,0x934($sp)
/*    43cb0:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    43cb4:	000c5023 */ 	negu	$t2,$t4
/*    43cb8:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    43cbc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    43cc0:	8fad0934 */ 	lw	$t5,0x934($sp)
/*    43cc4:	000e5c03 */ 	sra	$t3,$t6,0x10
/*    43cc8:	a5ab0000 */ 	sh	$t3,0x0($t5)
/*    43ccc:	8fb90934 */ 	lw	$t9,0x934($sp)
/*    43cd0:	27380002 */ 	addiu	$t8,$t9,0x2
/*    43cd4:	afb80934 */ 	sw	$t8,0x934($sp)
/*    43cd8:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    43cdc:	8fa90934 */ 	lw	$t1,0x934($sp)
/*    43ce0:	31e8ffff */ 	andi	$t0,$t7,0xffff
/*    43ce4:	a5280000 */ 	sh	$t0,0x0($t1)
/*    43ce8:	8fac0934 */ 	lw	$t4,0x934($sp)
/*    43cec:	258a0002 */ 	addiu	$t2,$t4,0x2
/*    43cf0:	afaa0934 */ 	sw	$t2,0x934($sp)
/*    43cf4:	3c014500 */ 	lui	$at,0x4500
/*    43cf8:	44814000 */ 	mtc1	$at,$f8
/*    43cfc:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*    43d00:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    43d04:	e7b0002c */ 	swc1	$f16,0x2c($sp)
/*    43d08:	afa00938 */ 	sw	$zero,0x938($sp)
.L00043d0c:
/*    43d0c:	afa0093c */ 	sw	$zero,0x93c($sp)
.L00043d10:
/*    43d10:	8fae093c */ 	lw	$t6,0x93c($sp)
/*    43d14:	8fad0938 */ 	lw	$t5,0x938($sp)
/*    43d18:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*    43d1c:	000e58c0 */ 	sll	$t3,$t6,0x3
/*    43d20:	016e5821 */ 	addu	$t3,$t3,$t6
/*    43d24:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    43d28:	000dc880 */ 	sll	$t9,$t5,0x2
/*    43d2c:	0179c021 */ 	addu	$t8,$t3,$t9
/*    43d30:	03b87821 */ 	addu	$t7,$sp,$t8
/*    43d34:	c5f20034 */ 	lwc1	$f18,0x34($t7)
/*    43d38:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    43d3c:	4600320d */ 	trunc.w.s	$f8,$f6
/*    43d40:	44094000 */ 	mfc1	$t1,$f8
/*    43d44:	00000000 */ 	nop
/*    43d48:	afa90024 */ 	sw	$t1,0x24($sp)
/*    43d4c:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    43d50:	8faa0934 */ 	lw	$t2,0x934($sp)
/*    43d54:	a54c0000 */ 	sh	$t4,0x0($t2)
/*    43d58:	8fae0934 */ 	lw	$t6,0x934($sp)
/*    43d5c:	25cd0002 */ 	addiu	$t5,$t6,0x2
/*    43d60:	afad0934 */ 	sw	$t5,0x934($sp)
/*    43d64:	8fab093c */ 	lw	$t3,0x93c($sp)
/*    43d68:	25790001 */ 	addiu	$t9,$t3,0x1
/*    43d6c:	2b210020 */ 	slti	$at,$t9,0x20
/*    43d70:	1420ffe7 */ 	bnez	$at,.L00043d10
/*    43d74:	afb9093c */ 	sw	$t9,0x93c($sp)
/*    43d78:	8fb80938 */ 	lw	$t8,0x938($sp)
/*    43d7c:	270f0001 */ 	addiu	$t7,$t8,0x1
/*    43d80:	29e10012 */ 	slti	$at,$t7,0x12
/*    43d84:	1420ffe1 */ 	bnez	$at,.L00043d0c
/*    43d88:	afaf0938 */ 	sw	$t7,0x938($sp)
/*    43d8c:	8fa8094c */ 	lw	$t0,0x94c($sp)
/*    43d90:	8fac0958 */ 	lw	$t4,0x958($sp)
/*    43d94:	25090001 */ 	addiu	$t1,$t0,0x1
/*    43d98:	afa9094c */ 	sw	$t1,0x94c($sp)
/*    43d9c:	8d8a3f8c */ 	lw	$t2,0x3f8c($t4)
/*    43da0:	012a082a */ 	slt	$at,$t1,$t2
/*    43da4:	1420feb5 */ 	bnez	$at,.L0004387c
/*    43da8:	00000000 */ 	nop
.L00043dac:
/*    43dac:	10000003 */ 	b	.L00043dbc
/*    43db0:	24020001 */ 	addiu	$v0,$zero,0x1
/*    43db4:	10000001 */ 	b	.L00043dbc
/*    43db8:	00000000 */ 	nop
.L00043dbc:
/*    43dbc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    43dc0:	27bd0958 */ 	addiu	$sp,$sp,0x958
/*    43dc4:	03e00008 */ 	jr	$ra
/*    43dc8:	00000000 */ 	nop
/*    43dcc:	00000000 */ 	nop
);
