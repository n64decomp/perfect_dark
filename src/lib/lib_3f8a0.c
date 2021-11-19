#include <ultra64.h>
#include "constants.h"
#include "lib/lib_3e8c0.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_45ed0.h"
#include "lib/lib_461c0.h"
#include "lib/lib_46650.h"
#include "lib/lib_47550.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

#define CHANNELMODE_STEREO      0
#define CHANNELMODE_JOINTSTEREO 1
#define CHANNELMODE_DUALMONO    2
#define CHANNELMODE_SINGLEMONO  3

#define VERSION_2 0x0
#define VERSION_1 0x1

f32 sine_block[4][36];
struct mp3decfourbytes *var8009c640;
f32 *var8009c644;
f32 *var8009c648;

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

struct mp3decthing *var8005f670[] = {
	NULL,
	(struct mp3decthing *)var70054b40,
	(struct mp3decthing *)var70054b68,
	(struct mp3decthing *)var70054bb8,
	(struct mp3decthing *)var70054c08,
	(struct mp3decthing *)var70054c08,
	(struct mp3decthing *)var70054c90,
	(struct mp3decthing *)var70054d18,
	(struct mp3decthing *)var70054e40,
	(struct mp3decthing *)var70054f68,
	(struct mp3decthing *)var70055090,
	(struct mp3decthing *)var70055298,
	(struct mp3decthing *)var700554a0,
	(struct mp3decthing *)var700556a8,
	(struct mp3decthing *)var70055eb0,
	(struct mp3decthing *)var70055eb0,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var700566b8,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var70056ec0,
	(struct mp3decthing *)var700576c8,
	(struct mp3decthing *)var70057750,
};

u8 *var8005f6f8 = NULL;
u8 *var8005f6fc = NULL;

const s32 var700577d8[34] = {
	0,  0,  0,  0,  0, 0, 0, 0, 0, 0,
	0,  0,  0,  0,  0, 0, 1, 2, 3, 4,
	6,  8,  10, 13, 4, 5, 6, 7, 8, 9,
	11, 13, -1, -1,
};

const s16 var70057860[2][3][22] = {
	{
		{ 5, 11, 17, 23, 29, 35, 43, 53, 65, 79, 95, 115, 139, 167, 199, 237, 283, 335, 395, 463, 521, 575 },
		{ 5, 11, 17, 23, 29, 35, 43, 53, 65, 79, 95, 113, 135, 161, 193, 231, 277, 331, 393, 463, 539, 575 },
		{ 5, 11, 17, 23, 29, 35, 43, 53, 65, 79, 95, 115, 139, 167, 199, 237, 283, 335, 395, 463, 521, 575 },
	}, {
		{ 3, 7,  11, 15, 19, 23, 29, 35, 43, 51, 61, 73,  89,  109, 133, 161, 195, 237, 287, 341, 417, 575 },
		{ 3, 7,  11, 15, 19, 23, 29, 35, 41, 49, 59, 71,  87,  105, 127, 155, 189, 229, 275, 329, 383, 575 },
		{ 3, 7,  11, 15, 19, 23, 29, 35, 43, 53, 65, 81,  101, 125, 155, 193, 239, 295, 363, 447, 549, 575 },
	},
};

const u8 var70057968[2][3][13] = {
	{
		{ 3, 7, 11, 17, 23, 31, 41, 55, 73, 99,  131, 173, 191 },
		{ 3, 7, 11, 17, 25, 35, 47, 61, 79, 103, 135, 179, 191 },
		{ 3, 7, 11, 17, 25, 35, 47, 61, 79, 103, 133, 173, 191 },
	}, {
		{ 3, 7, 11, 15, 21, 29, 39, 51, 65, 83,  105, 135, 191 },
		{ 3, 7, 11, 15, 21, 27, 37, 49, 63, 79,  99,  125, 191 },
		{ 3, 7, 11, 15, 21, 29, 41, 57, 77, 103, 137, 179, 191 },
	},
};

struct mp3decthing2 {
	s16 unk00[23];
	s16 unk2e[14];
};

const struct mp3decthing2 var700579b8[6] = {
	{ { 0, 6, 12, 18, 24, 30, 36, 44, 54, 66, 80, 96, 116, 140, 168, 200, 238, 284, 336, 396, 464, 522, 576 }, { 0, 4, 8, 12, 18, 24, 32, 42, 56, 74, 100, 132, 174, 192 } },
	{ { 0, 6, 12, 18, 24, 30, 36, 44, 54, 66, 80, 96, 114, 136, 162, 194, 232, 278, 330, 394, 464, 540, 576 }, { 0, 4, 8, 12, 18, 26, 36, 48, 62, 80, 104, 136, 180, 192 } },
	{ { 0, 6, 12, 18, 24, 30, 36, 44, 54, 66, 80, 96, 116, 140, 168, 200, 238, 284, 336, 396, 464, 522, 576 }, { 0, 4, 8, 12, 18, 26, 36, 48, 62, 80, 104, 134, 174, 192 } },
	{ { 0, 4, 8,  12, 16, 20, 24, 30, 36, 44, 52, 62, 74,  90,  110, 134, 162, 196, 238, 288, 342, 418, 576 }, { 0, 4, 8, 12, 16, 22, 30, 40, 52, 66, 84,  106, 136, 192 } },
	{ { 0, 4, 8,  12, 16, 20, 24, 30, 36, 42, 50, 60, 72,  88,  106, 128, 156, 190, 230, 276, 330, 384, 576 }, { 0, 4, 8, 12, 16, 22, 28, 38, 50, 64, 80,  100, 126, 192 } },
	{ { 0, 4, 8,  12, 16, 20, 24, 30, 36, 44, 54, 66, 82,  102, 126, 156, 194, 240, 296, 364, 448, 550, 576 }, { 0, 4, 8, 12, 16, 22, 30, 42, 58, 78, 104, 138, 180, 192 } },
};

const u8 var70057b74[] = { 0, 6, 11, 16, 21, 0, 6, 12 };

const u8 var70057b7c[2][16] = {
	{ 0, 0, 0, 0, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4 },
	{ 0, 1, 2, 3, 0, 1, 2, 3, 1, 2, 3, 1, 2, 3, 2, 3 },
};

const s16 var70057b9c[2][3][576] = {
	{
		{
			0,   1,   2,   3,   6,   7,   8,   9,   12,  13,  14,  15,  4,   5,   18,  19,
			10,  11,  24,  25,  16,  17,  30,  31,  20,  21,  22,  23,  26,  27,  28,  29,
			32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,
			48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,
			64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  90,  91,
			78,  79,  80,  81,  82,  83,  96,  97,  84,  85,  86,  87,  88,  89,  102, 103,
			92,  93,  94,  95,  108, 109, 110, 111, 112, 113, 98,  99,  100, 101, 114, 115,
			116, 117, 118, 119, 104, 105, 106, 107, 120, 121, 122, 123, 124, 125, 126, 127,
			128, 129, 130, 131, 144, 145, 146, 147, 148, 149, 162, 163, 132, 133, 134, 135,
			136, 137, 150, 151, 152, 153, 154, 155, 168, 169, 138, 139, 140, 141, 142, 143,
			156, 157, 158, 159, 160, 161, 174, 175, 164, 165, 166, 167, 180, 181, 182, 183,
			184, 185, 198, 199, 200, 201, 202, 203, 216, 217, 170, 171, 172, 173, 186, 187,
			188, 189, 190, 191, 204, 205, 206, 207, 208, 209, 222, 223, 176, 177, 178, 179,
			192, 193, 194, 195, 196, 197, 210, 211, 212, 213, 214, 215, 228, 229, 218, 219,
			220, 221, 234, 235, 236, 237, 238, 239, 252, 253, 254, 255, 256, 257, 270, 271,
			272, 273, 274, 275, 288, 289, 290, 291, 224, 225, 226, 227, 240, 241, 242, 243,
			244, 245, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 294, 295,
			296, 297, 230, 231, 232, 233, 246, 247, 248, 249, 250, 251, 264, 265, 266, 267,
			268, 269, 282, 283, 284, 285, 286, 287, 300, 301, 302, 303, 292, 293, 306, 307,
			308, 309, 310, 311, 324, 325, 326, 327, 328, 329, 342, 343, 344, 345, 346, 347,
			360, 361, 362, 363, 364, 365, 378, 379, 380, 381, 382, 383, 298, 299, 312, 313,
			314, 315, 316, 317, 330, 331, 332, 333, 334, 335, 348, 349, 350, 351, 352, 353,
			366, 367, 368, 369, 370, 371, 384, 385, 386, 387, 388, 389, 304, 305, 318, 319,
			320, 321, 322, 323, 336, 337, 338, 339, 340, 341, 354, 355, 356, 357, 358, 359,
			372, 373, 374, 375, 376, 377, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
			400, 401, 414, 415, 416, 417, 418, 419, 432, 433, 434, 435, 436, 437, 450, 451,
			452, 453, 454, 455, 468, 469, 470, 471, 472, 473, 486, 487, 488, 489, 490, 491,
			504, 505, 506, 507, 508, 509, 402, 403, 404, 405, 406, 407, 420, 421, 422, 423,
			424, 425, 438, 439, 440, 441, 442, 443, 456, 457, 458, 459, 460, 461, 474, 475,
			476, 477, 478, 479, 492, 493, 494, 495, 496, 497, 510, 511, 512, 513, 514, 515,
			408, 409, 410, 411, 412, 413, 426, 427, 428, 429, 430, 431, 444, 445, 446, 447,
			448, 449, 462, 463, 464, 465, 466, 467, 480, 481, 482, 483, 484, 485, 498, 499,
			500, 501, 502, 503, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527,
			540, 541, 542, 543, 544, 545, 558, 559, 560, 561, 562, 563, 528, 529, 530, 531,
			532, 533, 546, 547, 548, 549, 550, 551, 564, 565, 566, 567, 568, 569, 534, 535,
			536, 537, 538, 539, 552, 553, 554, 555, 556, 557, 570, 571, 572, 573, 574, 575,
		}, {
			0,   1,   2,   3,   6,   7,   8,   9,   12,  13,  14,  15,  4,   5,   18,  19,
			10,  11,  24,  25,  16,  17,  30,  31,  20,  21,  22,  23,  26,  27,  28,  29,
			32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,
			48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  72,  73,  60,  61,
			62,  63,  64,  65,  78,  79,  66,  67,  68,  69,  70,  71,  84,  85,  74,  75,
			76,  77,  90,  91,  92,  93,  94,  95,  80,  81,  82,  83,  96,  97,  98,  99,
			100, 101, 86,  87,  88,  89,  102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
			112, 113, 126, 127, 128, 129, 130, 131, 114, 115, 116, 117, 118, 119, 132, 133,
			134, 135, 136, 137, 120, 121, 122, 123, 124, 125, 138, 139, 140, 141, 142, 143,
			144, 145, 146, 147, 148, 149, 162, 163, 164, 165, 166, 167, 180, 181, 150, 151,
			152, 153, 154, 155, 168, 169, 170, 171, 172, 173, 186, 187, 156, 157, 158, 159,
			160, 161, 174, 175, 176, 177, 178, 179, 192, 193, 182, 183, 184, 185, 198, 199,
			200, 201, 202, 203, 216, 217, 218, 219, 220, 221, 234, 235, 188, 189, 190, 191,
			204, 205, 206, 207, 208, 209, 222, 223, 224, 225, 226, 227, 240, 241, 194, 195,
			196, 197, 210, 211, 212, 213, 214, 215, 228, 229, 230, 231, 232, 233, 246, 247,
			236, 237, 238, 239, 252, 253, 254, 255, 256, 257, 270, 271, 272, 273, 274, 275,
			288, 289, 290, 291, 292, 293, 306, 307, 242, 243, 244, 245, 258, 259, 260, 261,
			262, 263, 276, 277, 278, 279, 280, 281, 294, 295, 296, 297, 298, 299, 312, 313,
			248, 249, 250, 251, 264, 265, 266, 267, 268, 269, 282, 283, 284, 285, 286, 287,
			300, 301, 302, 303, 304, 305, 318, 319, 308, 309, 310, 311, 324, 325, 326, 327,
			328, 329, 342, 343, 344, 345, 346, 347, 360, 361, 362, 363, 364, 365, 378, 379,
			380, 381, 382, 383, 396, 397, 398, 399, 314, 315, 316, 317, 330, 331, 332, 333,
			334, 335, 348, 349, 350, 351, 352, 353, 366, 367, 368, 369, 370, 371, 384, 385,
			386, 387, 388, 389, 402, 403, 404, 405, 320, 321, 322, 323, 336, 337, 338, 339,
			340, 341, 354, 355, 356, 357, 358, 359, 372, 373, 374, 375, 376, 377, 390, 391,
			392, 393, 394, 395, 408, 409, 410, 411, 400, 401, 414, 415, 416, 417, 418, 419,
			432, 433, 434, 435, 436, 437, 450, 451, 452, 453, 454, 455, 468, 469, 470, 471,
			472, 473, 486, 487, 488, 489, 490, 491, 504, 505, 506, 507, 508, 509, 522, 523,
			524, 525, 526, 527, 406, 407, 420, 421, 422, 423, 424, 425, 438, 439, 440, 441,
			442, 443, 456, 457, 458, 459, 460, 461, 474, 475, 476, 477, 478, 479, 492, 493,
			494, 495, 496, 497, 510, 511, 512, 513, 514, 515, 528, 529, 530, 531, 532, 533,
			412, 413, 426, 427, 428, 429, 430, 431, 444, 445, 446, 447, 448, 449, 462, 463,
			464, 465, 466, 467, 480, 481, 482, 483, 484, 485, 498, 499, 500, 501, 502, 503,
			516, 517, 518, 519, 520, 521, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543,
			544, 545, 558, 559, 560, 561, 562, 563, 546, 547, 548, 549, 550, 551, 564, 565,
			566, 567, 568, 569, 552, 553, 554, 555, 556, 557, 570, 571, 572, 573, 574, 575,
		}, {
			0,   1,   2,   3,   6,   7,   8,   9,   12,  13,  14,  15,  4,   5,   18,  19,
			10,  11,  24,  25,  16,  17,  30,  31,  20,  21,  22,  23,  26,  27,  28,  29,
			32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,
			48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  72,  73,  60,  61,
			62,  63,  64,  65,  78,  79,  66,  67,  68,  69,  70,  71,  84,  85,  74,  75,
			76,  77,  90,  91,  92,  93,  94,  95,  80,  81,  82,  83,  96,  97,  98,  99,
			100, 101, 86,  87,  88,  89,  102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
			112, 113, 126, 127, 128, 129, 130, 131, 114, 115, 116, 117, 118, 119, 132, 133,
			134, 135, 136, 137, 120, 121, 122, 123, 124, 125, 138, 139, 140, 141, 142, 143,
			144, 145, 146, 147, 148, 149, 162, 163, 164, 165, 166, 167, 180, 181, 150, 151,
			152, 153, 154, 155, 168, 169, 170, 171, 172, 173, 186, 187, 156, 157, 158, 159,
			160, 161, 174, 175, 176, 177, 178, 179, 192, 193, 182, 183, 184, 185, 198, 199,
			200, 201, 202, 203, 216, 217, 218, 219, 220, 221, 234, 235, 188, 189, 190, 191,
			204, 205, 206, 207, 208, 209, 222, 223, 224, 225, 226, 227, 240, 241, 194, 195,
			196, 197, 210, 211, 212, 213, 214, 215, 228, 229, 230, 231, 232, 233, 246, 247,
			236, 237, 238, 239, 252, 253, 254, 255, 256, 257, 270, 271, 272, 273, 274, 275,
			288, 289, 290, 291, 292, 293, 306, 307, 242, 243, 244, 245, 258, 259, 260, 261,
			262, 263, 276, 277, 278, 279, 280, 281, 294, 295, 296, 297, 298, 299, 312, 313,
			248, 249, 250, 251, 264, 265, 266, 267, 268, 269, 282, 283, 284, 285, 286, 287,
			300, 301, 302, 303, 304, 305, 318, 319, 308, 309, 310, 311, 324, 325, 326, 327,
			328, 329, 342, 343, 344, 345, 346, 347, 360, 361, 362, 363, 364, 365, 378, 379,
			380, 381, 382, 383, 396, 397, 314, 315, 316, 317, 330, 331, 332, 333, 334, 335,
			348, 349, 350, 351, 352, 353, 366, 367, 368, 369, 370, 371, 384, 385, 386, 387,
			388, 389, 402, 403, 320, 321, 322, 323, 336, 337, 338, 339, 340, 341, 354, 355,
			356, 357, 358, 359, 372, 373, 374, 375, 376, 377, 390, 391, 392, 393, 394, 395,
			408, 409, 398, 399, 400, 401, 414, 415, 416, 417, 418, 419, 432, 433, 434, 435,
			436, 437, 450, 451, 452, 453, 454, 455, 468, 469, 470, 471, 472, 473, 486, 487,
			488, 489, 490, 491, 504, 505, 506, 507, 508, 509, 404, 405, 406, 407, 420, 421,
			422, 423, 424, 425, 438, 439, 440, 441, 442, 443, 456, 457, 458, 459, 460, 461,
			474, 475, 476, 477, 478, 479, 492, 493, 494, 495, 496, 497, 510, 511, 512, 513,
			514, 515, 410, 411, 412, 413, 426, 427, 428, 429, 430, 431, 444, 445, 446, 447,
			448, 449, 462, 463, 464, 465, 466, 467, 480, 481, 482, 483, 484, 485, 498, 499,
			500, 501, 502, 503, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527,
			540, 541, 542, 543, 544, 545, 558, 559, 560, 561, 562, 563, 528, 529, 530, 531,
			532, 533, 546, 547, 548, 549, 550, 551, 564, 565, 566, 567, 568, 569, 534, 535,
			536, 537, 538, 539, 552, 553, 554, 555, 556, 557, 570, 571, 572, 573, 574, 575,
		},
	}, {
		{
			0,   1,   2,   3,   6,   7,   8,   9,   12,  13,  14,  15,  4,   5,   18,  19,
			10,  11,  24,  25,  16,  17,  30,  31,  20,  21,  22,  23,  26,  27,  28,  29,
			32,  33,  34,  35,  36,  37,  38,  39,  42,  43,  44,  45,  48,  49,  50,  51,
			40,  41,  54,  55,  56,  57,  46,  47,  60,  61,  62,  63,  52,  53,  66,  67,
			68,  69,  58,  59,  72,  73,  74,  75,  76,  77,  64,  65,  78,  79,  80,  81,
			82,  83,  70,  71,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,
			108, 109, 110, 111, 96,  97,  98,  99,  100, 101, 114, 115, 116, 117, 102, 103,
			104, 105, 106, 107, 120, 121, 122, 123, 112, 113, 126, 127, 128, 129, 130, 131,
			144, 145, 146, 147, 118, 119, 132, 133, 134, 135, 136, 137, 150, 151, 152, 153,
			124, 125, 138, 139, 140, 141, 142, 143, 156, 157, 158, 159, 148, 149, 162, 163,
			164, 165, 166, 167, 180, 181, 182, 183, 184, 185, 154, 155, 168, 169, 170, 171,
			172, 173, 186, 187, 188, 189, 190, 191, 160, 161, 174, 175, 176, 177, 178, 179,
			192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 216, 217, 218, 219,
			220, 221, 234, 235, 236, 237, 238, 239, 204, 205, 206, 207, 208, 209, 222, 223,
			224, 225, 226, 227, 240, 241, 242, 243, 244, 245, 210, 211, 212, 213, 214, 215,
			228, 229, 230, 231, 232, 233, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255,
			256, 257, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291, 292, 293, 306, 307,
			308, 309, 258, 259, 260, 261, 262, 263, 276, 277, 278, 279, 280, 281, 294, 295,
			296, 297, 298, 299, 312, 313, 314, 315, 264, 265, 266, 267, 268, 269, 282, 283,
			284, 285, 286, 287, 300, 301, 302, 303, 304, 305, 318, 319, 320, 321, 310, 311,
			324, 325, 326, 327, 328, 329, 342, 343, 344, 345, 346, 347, 360, 361, 362, 363,
			364, 365, 378, 379, 380, 381, 382, 383, 396, 397, 398, 399, 316, 317, 330, 331,
			332, 333, 334, 335, 348, 349, 350, 351, 352, 353, 366, 367, 368, 369, 370, 371,
			384, 385, 386, 387, 388, 389, 402, 403, 404, 405, 322, 323, 336, 337, 338, 339,
			340, 341, 354, 355, 356, 357, 358, 359, 372, 373, 374, 375, 376, 377, 390, 391,
			392, 393, 394, 395, 408, 409, 410, 411, 400, 401, 414, 415, 416, 417, 418, 419,
			432, 433, 434, 435, 436, 437, 450, 451, 452, 453, 454, 455, 468, 469, 470, 471,
			472, 473, 486, 487, 488, 489, 490, 491, 504, 505, 506, 507, 508, 509, 522, 523,
			524, 525, 526, 527, 540, 541, 542, 543, 544, 545, 558, 559, 560, 561, 562, 563,
			406, 407, 420, 421, 422, 423, 424, 425, 438, 439, 440, 441, 442, 443, 456, 457,
			458, 459, 460, 461, 474, 475, 476, 477, 478, 479, 492, 493, 494, 495, 496, 497,
			510, 511, 512, 513, 514, 515, 528, 529, 530, 531, 532, 533, 546, 547, 548, 549,
			550, 551, 564, 565, 566, 567, 568, 569, 412, 413, 426, 427, 428, 429, 430, 431,
			444, 445, 446, 447, 448, 449, 462, 463, 464, 465, 466, 467, 480, 481, 482, 483,
			484, 485, 498, 499, 500, 501, 502, 503, 516, 517, 518, 519, 520, 521, 534, 535,
			536, 537, 538, 539, 552, 553, 554, 555, 556, 557, 570, 571, 572, 573, 574, 575,
		}, {
			0,   1,   2,   3,   6,   7,   8,   9,   12,  13,  14,  15,  4,   5,   18,  19,
			10,  11,  24,  25,  16,  17,  30,  31,  20,  21,  22,  23,  26,  27,  28,  29,
			32,  33,  34,  35,  36,  37,  38,  39,  42,  43,  44,  45,  48,  49,  50,  51,
			40,  41,  54,  55,  56,  57,  46,  47,  60,  61,  62,  63,  52,  53,  66,  67,
			68,  69,  58,  59,  72,  73,  74,  75,  64,  65,  78,  79,  80,  81,  70,  71,
			84,  85,  86,  87,  76,  77,  90,  91,  92,  93,  94,  95,  108, 109, 82,  83,
			96,  97,  98,  99,  100, 101, 114, 115, 88,  89,  102, 103, 104, 105, 106, 107,
			120, 121, 110, 111, 112, 113, 126, 127, 128, 129, 130, 131, 144, 145, 116, 117,
			118, 119, 132, 133, 134, 135, 136, 137, 150, 151, 122, 123, 124, 125, 138, 139,
			140, 141, 142, 143, 156, 157, 146, 147, 148, 149, 162, 163, 164, 165, 166, 167,
			180, 181, 182, 183, 152, 153, 154, 155, 168, 169, 170, 171, 172, 173, 186, 187,
			188, 189, 158, 159, 160, 161, 174, 175, 176, 177, 178, 179, 192, 193, 194, 195,
			184, 185, 198, 199, 200, 201, 202, 203, 216, 217, 218, 219, 220, 221, 234, 235,
			190, 191, 204, 205, 206, 207, 208, 209, 222, 223, 224, 225, 226, 227, 240, 241,
			196, 197, 210, 211, 212, 213, 214, 215, 228, 229, 230, 231, 232, 233, 246, 247,
			236, 237, 238, 239, 252, 253, 254, 255, 256, 257, 270, 271, 272, 273, 274, 275,
			288, 289, 290, 291, 242, 243, 244, 245, 258, 259, 260, 261, 262, 263, 276, 277,
			278, 279, 280, 281, 294, 295, 296, 297, 248, 249, 250, 251, 264, 265, 266, 267,
			268, 269, 282, 283, 284, 285, 286, 287, 300, 301, 302, 303, 292, 293, 306, 307,
			308, 309, 310, 311, 324, 325, 326, 327, 328, 329, 342, 343, 344, 345, 346, 347,
			360, 361, 362, 363, 364, 365, 298, 299, 312, 313, 314, 315, 316, 317, 330, 331,
			332, 333, 334, 335, 348, 349, 350, 351, 352, 353, 366, 367, 368, 369, 370, 371,
			304, 305, 318, 319, 320, 321, 322, 323, 336, 337, 338, 339, 340, 341, 354, 355,
			356, 357, 358, 359, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383,
			396, 397, 398, 399, 400, 401, 414, 415, 416, 417, 418, 419, 432, 433, 434, 435,
			436, 437, 450, 451, 452, 453, 454, 455, 468, 469, 470, 471, 472, 473, 486, 487,
			488, 489, 490, 491, 504, 505, 506, 507, 508, 509, 522, 523, 524, 525, 526, 527,
			540, 541, 542, 543, 544, 545, 558, 559, 560, 561, 562, 563, 384, 385, 386, 387,
			388, 389, 402, 403, 404, 405, 406, 407, 420, 421, 422, 423, 424, 425, 438, 439,
			440, 441, 442, 443, 456, 457, 458, 459, 460, 461, 474, 475, 476, 477, 478, 479,
			492, 493, 494, 495, 496, 497, 510, 511, 512, 513, 514, 515, 528, 529, 530, 531,
			532, 533, 546, 547, 548, 549, 550, 551, 564, 565, 566, 567, 568, 569, 390, 391,
			392, 393, 394, 395, 408, 409, 410, 411, 412, 413, 426, 427, 428, 429, 430, 431,
			444, 445, 446, 447, 448, 449, 462, 463, 464, 465, 466, 467, 480, 481, 482, 483,
			484, 485, 498, 499, 500, 501, 502, 503, 516, 517, 518, 519, 520, 521, 534, 535,
			536, 537, 538, 539, 552, 553, 554, 555, 556, 557, 570, 571, 572, 573, 574, 575,
		}, {
			0,   1,   2,   3,   6,   7,   8,   9,   12,  13,  14,  15,  4,   5,   18,  19,
			10,  11,  24,  25,  16,  17,  30,  31,  20,  21,  22,  23,  26,  27,  28,  29,
			32,  33,  34,  35,  36,  37,  38,  39,  42,  43,  44,  45,  48,  49,  50,  51,
			40,  41,  54,  55,  56,  57,  46,  47,  60,  61,  62,  63,  52,  53,  66,  67,
			68,  69,  58,  59,  72,  73,  74,  75,  76,  77,  64,  65,  78,  79,  80,  81,
			82,  83,  70,  71,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,
			108, 109, 110, 111, 112, 113, 96,  97,  98,  99,  100, 101, 114, 115, 116, 117,
			118, 119, 102, 103, 104, 105, 106, 107, 120, 121, 122, 123, 124, 125, 126, 127,
			128, 129, 130, 131, 144, 145, 146, 147, 148, 149, 162, 163, 164, 165, 132, 133,
			134, 135, 136, 137, 150, 151, 152, 153, 154, 155, 168, 169, 170, 171, 138, 139,
			140, 141, 142, 143, 156, 157, 158, 159, 160, 161, 174, 175, 176, 177, 166, 167,
			180, 181, 182, 183, 184, 185, 198, 199, 200, 201, 202, 203, 216, 217, 218, 219,
			220, 221, 172, 173, 186, 187, 188, 189, 190, 191, 204, 205, 206, 207, 208, 209,
			222, 223, 224, 225, 226, 227, 178, 179, 192, 193, 194, 195, 196, 197, 210, 211,
			212, 213, 214, 215, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
			252, 253, 254, 255, 256, 257, 270, 271, 272, 273, 274, 275, 288, 289, 290, 291,
			292, 293, 306, 307, 240, 241, 242, 243, 244, 245, 258, 259, 260, 261, 262, 263,
			276, 277, 278, 279, 280, 281, 294, 295, 296, 297, 298, 299, 312, 313, 246, 247,
			248, 249, 250, 251, 264, 265, 266, 267, 268, 269, 282, 283, 284, 285, 286, 287,
			300, 301, 302, 303, 304, 305, 318, 319, 308, 309, 310, 311, 324, 325, 326, 327,
			328, 329, 342, 343, 344, 345, 346, 347, 360, 361, 362, 363, 364, 365, 378, 379,
			380, 381, 382, 383, 396, 397, 398, 399, 400, 401, 314, 315, 316, 317, 330, 331,
			332, 333, 334, 335, 348, 349, 350, 351, 352, 353, 366, 367, 368, 369, 370, 371,
			384, 385, 386, 387, 388, 389, 402, 403, 404, 405, 406, 407, 320, 321, 322, 323,
			336, 337, 338, 339, 340, 341, 354, 355, 356, 357, 358, 359, 372, 373, 374, 375,
			376, 377, 390, 391, 392, 393, 394, 395, 408, 409, 410, 411, 412, 413, 414, 415,
			416, 417, 418, 419, 432, 433, 434, 435, 436, 437, 450, 451, 452, 453, 454, 455,
			468, 469, 470, 471, 472, 473, 486, 487, 488, 489, 490, 491, 504, 505, 506, 507,
			508, 509, 522, 523, 524, 525, 526, 527, 420, 421, 422, 423, 424, 425, 438, 439,
			440, 441, 442, 443, 456, 457, 458, 459, 460, 461, 474, 475, 476, 477, 478, 479,
			492, 493, 494, 495, 496, 497, 510, 511, 512, 513, 514, 515, 528, 529, 530, 531,
			532, 533, 426, 427, 428, 429, 430, 431, 444, 445, 446, 447, 448, 449, 462, 463,
			464, 465, 466, 467, 480, 481, 482, 483, 484, 485, 498, 499, 500, 501, 502, 503,
			516, 517, 518, 519, 520, 521, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543,
			544, 545, 558, 559, 560, 561, 562, 563, 546, 547, 548, 549, 550, 551, 564, 565,
			566, 567, 568, 569, 552, 553, 554, 555, 556, 557, 570, 571, 572, 573, 574, 575,
		},
	},
};

const f32 var7005969c[] = {
	-0.51449573040009,
	-0.47173196077347,
	-0.31337743997574,
	-0.18191319704056,
	-0.094574190676212,
	-0.040965583175421,
	-0.01419856864959,
	-0.0036999746225774,
};

const f32 var700596bc[] = {
	0.85749292373657,
	0.88174200057983,
	0.94962865114212,
	0.9833145737648,
	0.99551779031754,
	0.99916058778763,
	0.99989920854568,
	0.99999314546585,
};

const u32 var700596dc[2][15] = {
	{ 0, 8000,  16000, 24000, 32000, 40000, 48000, 56000, 64000,  80000,  96000,  112000, 128000, 144000, 160000 },
	{ 0, 32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000, 192000, 224000, 256000, 320000 },
};

const u32 var70059754[2][4] = {
	{ 22050, 24000, 16000, 22050 },
	{ 44100, 48000, 32000, 44100 },
};

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

extern struct mp3decfourbytes *var8009c650[];
extern f32 *var8009c6d8;
extern f32 *var8009c6dc;

bool func0003f8a0(void)
{
	s32 i;
	s32 sp268;
	s32 sp264;
	s32 sp260 = 1;
	s32 sp25c;
	u8 *sp258;
	struct mp3decthing *sp254;
	struct mp3decfourbytes *sp250;
	const u8 sp248[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
	s32 sp244;
	u8 sp243;
	s32 sp23c;
	s32 sp238;
	s32 sp234;
	s32 sp230;
	s32 sp22c;
	s32 sp228;
	s16 sp28[256];
	s32 sp24;

	sp234 = 0;

	for (i = 0; i < 36; i++) {
		sine_block[0][i] = sinf((i + 0.5f) * 0.087266460061073f);
	}

	for (i = 0; i < 18; i++) {
		sine_block[1][i] = sinf((i + 0.5f) * 0.087266460061073f);
	}

	for (i = 18; i < 24; i++) {
		sine_block[1][i] = 1.0f;
	}

	for (i = 24; i < 30; i++) {
		sine_block[1][i] = sinf((i + 0.5f - 18.0f) * 0.26179939508438f);
	}

	for (i = 30; i < 36; i++) {
		sine_block[1][i] = 0.0f;
	}

	for (i = 0; i < 6; i++) {
		sine_block[3][i] = 0.0f;
	}

	for (i = 6; i < 12; i++) {
		sine_block[3][i] = sinf((i + 0.5f - 6.0f) * 0.26179939508438f);
	}

	for (i = 12; i < 18; i++) {
		sine_block[3][i] = 1.0f;
	}

	for (i = 18; i < 36; i++) {
		sine_block[3][i] = sinf((i + 0.5f) * 0.087266460061073f);
	}

	if (var8009c640 == NULL) {
		return false;
	}

	bzero(var8009c640, 10500 * sizeof(struct mp3decfourbytes));

	for (sp264 = 0; sp264 < 34; sp264++) {
		sp254 = var8005f670[sp264];

		if (sp254 == NULL) {
			var8009c650[sp264] = NULL;
			continue;
		}

		var8009c650[sp264] = &var8009c640[sp234];

		sp250 = var8009c650[sp264];

		for (sp268 = 0; sp268 < 10500; sp268++) {
			sp250[sp268].unk02 = -1;
			sp250[sp268].unk03 = -1;
		}

		sp230 = 1;
		sp228 = 1;
		bzero(sp28, sizeof(sp28));
		sp260 = 1;

		while (sp228) {
			sp228 = 0;

			for (sp22c = 0, sp254 = var8005f670[sp264]; sp254->unk00 != 100; sp254++, sp22c++) {
				sp25c = sp28[sp22c];

				if (sp230 <= sp254->unk02) {
					sp258 = &sp250[sp25c].bytes[sp254->unk04 & 1 << (sp230 + 31) ? 1 : 0];

					if (*sp258) {
						sp25c = sp28[sp22c] + *sp258;
					} else {
						*sp258 = sp260 - sp25c;
						sp25c = sp260++;
					}

					if (sp254->unk02 == sp230) {
						sp250[sp25c].unk02 = sp254->unk00;
						sp250[sp25c].unk03 = sp254->unk01;
					} else {
						sp228++;
					}

					sp28[sp22c] = sp25c;
				}
			}

			sp230++;
		}

		sp234 += sp260;

		for (sp254 = var8005f670[sp264]; sp254->unk00 != 100; sp254++) {
			sp244 = sp254->unk02 < 8 ? sp254->unk02 : 8;
			sp243 = 0;

			for (i = 0; i < sp244; i++) {
				if (sp254->unk04 & (1 << i)) {
					sp243 |= sp248[i];
				}
			}

			if (sp254->unk02 >= 9) {
				var8005f6fc[sp264 * 256 + sp243] = 0;
				continue;
			}

			sp23c = 256 >> sp244;
			sp238 = (sp254->unk01 * 16) | sp254->unk00;

			for (i = 0; i < sp23c; i++) {
				sp24 = sp243 | i;
				var8005f6f8[((sp264 * 256) + (sp243 | i))] = sp238;
				var8005f6fc[((sp264 * 256) + (sp243 | i))] = sp244;
			}
		}
	}

	var8009c648 = var8009c644;

	if (var8009c648 == NULL) {
		return false;
	}

	for (i = 0; i < 8192; i++) {
		var8009c648[i] = func00045ed0(i, 1.3333333730698f);
	}

	for (i = 0; i < 256; i++) {
		var8009c6d8[i] = func00045ed0(2.0f, i * -0.5f);
		var8009c6dc[i] = func00045ed0(2.0f, i * -2.0f);
	}

	return true;
}

bool func00040164(struct asistream *stream, u32 gr, u32 ch)
{
	s32 sp1bc;
	s32 sp1b8;
	s32 sp1b4;
	s32 sp1b0;

	const s32 sp158[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 2, 2, 3, 3, 3, 2, 0,
	};

	f32 sp100[22];
	f32 sp64[3][13];
	f32 sp60;
	s32 sp5c;
	s32 sp58;
	s32 sp54;
	s32 sp50;
	s32 sp4c;
	s32 sp48;
	s32 sp44;
	f32 *sp40;
	s16 *sp3c;
	u8 *sp38;
	s32 sp34;
	s32 sp30;
	s32 sp2c;
	s32 sp28;
	f32 *sp24;

	sp1bc = stream->samplerateindex + stream->version * 3;

	if (stream->window_switching[gr][ch] && stream->block_type[gr][ch] == 2) {
		if (stream->mixed_block_flag[gr][ch]) {
			sp1b8 = var700579b8[sp1bc].unk00[1];
		} else {
			sp1b8 = var700579b8[sp1bc].unk2e[1] * 3;
			sp1b0 = var700579b8[sp1bc].unk2e[1];
			sp1b4 = 0;
		}
	} else {
		sp1b8 = var700579b8[sp1bc].unk00[1];
	}

	sp60 = func00045ed0(2, (stream->global_gain[gr][ch] - 210.0f) * 0.25f);
	sp54 = stream->scalefac_scale[gr][ch];

	for (sp5c = 0; sp5c < 22; sp5c++) {
		sp4c = (*(u32 *)(stream->scalefac_l + gr * 0xf8 + ch * 0xf8 + sp5c * 4) + stream->preflag[gr][ch] * *(s32 *)((u32)sp158 + sp5c * 4)) * (sp54 + 1);
		sp100[sp5c] = var8009c6d8[sp4c] * sp60;
	}

	for (sp58 = 0; sp58 < 3; sp58++) {
		for (sp5c = 0; sp5c < 13; sp5c++) {
			sp50 = stream->subblock_gain[gr][ch][sp58];
			sp4c = (*(u32 *)(stream->scalefac_s + gr * 0xf8 + ch * 0xf8 + sp58 * 0x34 + sp5c * 4) * (sp54 + 1));
			sp64[sp58][sp5c] = sp60 * var8009c6dc[sp50] * var8009c6d8[sp4c];
		}
	}

	sp5c = 0;
	sp48 = 0;
	sp44 = stream->unk465c[ch];
	sp40 = stream->unk4664[ch][0].unk00;
	sp3c = stream->unk3f94[ch];
	sp38 = stream->unk4418[ch];
	sp34 = stream->block_type[gr][ch] == 2 && stream->mixed_block_flag[gr][ch] == 0;
	sp30 = stream->block_type[gr][ch] == 2 && stream->mixed_block_flag[gr][ch] != 0;
	sp2c = stream->window_switching[gr][ch];

	while (sp48 < sp44) {
		if (sp1b8 > sp44) {
			sp1b8 = sp44;
		}

		if (sp2c) {
			if (sp34 || (sp30 && sp48 >= 36)) {
				sp58 = (sp48 - sp1b4) / sp1b0;
				sp28 = sp1b4 + sp1b0;
			}
		}

		while (sp48 < sp1b8) {
			if (sp2c && (sp34 || (sp30 && sp48 >= 36))) {
				if (sp48 >= sp28) {
					sp28 += sp1b0;
					sp58++;
				}

				sp24 = sp64[sp58];

				if (*sp38++) {
					*sp40++ = -(var8009c648[*sp3c++] * sp24[sp5c]);
				} else {
					*sp40++ = var8009c648[*sp3c++] * sp24[sp5c];
				}
			} else {
				if (*sp38++) {
					*sp40++ = -(var8009c648[*sp3c++] * sp100[sp5c]);
				} else {
					*sp40++ = var8009c648[*sp3c++] * sp100[sp5c];
				}
			}

			sp48++;
		}

		if (stream->window_switching[gr][ch] && stream->block_type[gr][ch] == 2) {
			if (stream->mixed_block_flag[gr][ch]) {
				if (var700579b8[sp1bc].unk00[8] == sp48) {
					sp1b8 = var700579b8[sp1bc].unk2e[4] * 3;
					sp5c = 3;
					sp1b0 = var700579b8[sp1bc].unk2e[sp5c + 1] - var700579b8[sp1bc].unk2e[sp5c];
					sp1b4 = var700579b8[sp1bc].unk2e[sp5c] * 3;
				} else if (sp48 < var700579b8[sp1bc].unk00[8]) {
					sp1b8 = var700579b8[sp1bc].unk00[++sp5c + 1];
				} else {
					sp1b8 = var700579b8[sp1bc].unk2e[++sp5c + 1] * 3;
					sp1b0 = var700579b8[sp1bc].unk2e[sp5c + 1] - var700579b8[sp1bc].unk2e[sp5c];
					sp1b4 = var700579b8[sp1bc].unk2e[sp5c] * 3;
				}
			} else {
				sp1b8 = var700579b8[sp1bc].unk2e[++sp5c + 1] * 3;
				sp1b0 = var700579b8[sp1bc].unk2e[sp5c + 1] - var700579b8[sp1bc].unk2e[sp5c];
				sp1b4 = var700579b8[sp1bc].unk2e[sp5c] * 3;
			}
		} else {
			sp1b8 = var700579b8[sp1bc].unk00[++sp5c + 1];
		}
	}

	if (sp48 < 576) {
		bzero(sp40, stream->unk4660[ch] * 4);
		return true;
	}

	return true;
}

bool mp3decUnpackScaleFac(struct asistream *stream, u32 gr, u32 ch)
{
	s32 i;
	s32 sfb;
	s32 window;

	if (stream->window_switching[gr][ch] != 0 && stream->block_type[gr][ch] == 2) {
		if (stream->mixed_block_flag[gr][ch] != 0) {
			for (sfb = 0; sfb < 8; sfb++) {
				*(u32 *)(stream->scalefac_l + gr * 0xf8 + ch * 0xf8 + sfb * 4) =
					var70057b7c[0][stream->scalefac_compress[gr][ch]]
					? mp3decGetBits(stream->unk1c, &stream->unk2020, var70057b7c[0][stream->scalefac_compress[gr][ch]])
					: 0;
			}

			for (sfb = 3; sfb < 6; sfb++) {
				for (window = 0; window < 3; window++) {
					*(u32 *)(stream->scalefac_s + gr * 0xf8 + ch * 0xf8 + window * 0x34 + sfb * 4) =
						var70057b7c[0][stream->scalefac_compress[gr][ch]]
						? mp3decGetBits(stream->unk1c, &stream->unk2020, var70057b7c[0][stream->scalefac_compress[gr][ch]])
						: 0;
				}
			}

			for (sfb = 6; sfb < 12; sfb++) {
				for (window = 0; window < 3; window++) {
					*(u32 *)(stream->scalefac_s + gr * 0xf8 + ch * 0xf8 + window * 0x34 + sfb * 4) =
						var70057b7c[1][stream->scalefac_compress[gr][ch]]
						? mp3decGetBits(stream->unk1c, &stream->unk2020, var70057b7c[1][stream->scalefac_compress[gr][ch]])
						: 0;
				}
			}
		} else {
			for (i = 0; i < 2; i++) {
				for (sfb = var70057b74[5 + i]; sfb < var70057b74[6 + i]; sfb++) {
					for (window = 0; window < 3; window++) {
						*(u32 *)(stream->scalefac_s + gr * 0xf8 + ch * 0xf8 + window * 0x34 + sfb * 4) =
							var70057b7c[i][stream->scalefac_compress[gr][ch]]
							? mp3decGetBits(stream->unk1c, &stream->unk2020, var70057b7c[i][stream->scalefac_compress[gr][ch]])
							: 0;
					}
				}
			}
		}

		for (window = 0; window < 3; window++) {
			*(u32 *)(stream->unk3d94 + gr * 0xf8 + ch * 0xf8 + window * 0x34) = 0;
		}
	} else {
		for (i = 0; i < 4; i++) {
			// This is overflowing scfsi? Unless ch is only ever 0
			if (stream->scfsi[ch][i] == 0 || gr == 0) {
				for (sfb = var70057b74[i]; sfb < var70057b74[i + 1]; sfb++) {
					*(u32 *)(stream->scalefac_l + gr * 0xf8 + ch * 0xf8 + sfb * 4) =
						var70057b7c[i < 2 ? 0 : 1][stream->scalefac_compress[gr][ch]]
						? mp3decGetBits(stream->unk1c, &stream->unk2020, var70057b7c[i < 2 ? 0 : 1][stream->scalefac_compress[gr][ch]])
						: 0;
				}
			} else {
				for (sfb = var70057b74[i]; sfb < var70057b74[1 + i]; sfb++) {
					*(u32 *)(stream->unk3e00 + ch * 0xf8 + sfb * 4) = *(u32 *)(stream->scalefac_l + ch * 0xf8 + sfb * 4);
				}
			}
		}

		*(u32 *)(stream->unk3d60 + gr * 0xf8 + ch * 0xf8) = 0;
	}

	return true;
}

bool func00041600(struct asistream *stream, u32 gr, u32 ch)
{
	const s32 sp70[2][3][3][4] = {
		{
			{ { 6,  5,  5,  5 }, { 9,  9,  9,  9 }, { 6,  9,  9,  9 } },
			{ { 6,  5,  7,  3 }, { 9,  9,  12, 6 }, { 6,  9,  12, 6 } },
			{ { 11, 10, 0,  0 }, { 18, 18, 0,  0 }, { 15, 18, 0,  0 } },
		}, {
			{ { 7,  7,  7,  0 }, { 12, 12, 12, 0 }, { 6,  15, 12, 0 } },
			{ { 6,  6,  6,  3 }, { 12, 9,  9,  6 }, { 6,  12, 9,  6 } },
			{ { 8,  8,  5,  0 }, { 15, 12, 9,  0 }, { 6,  18, 9,  0 } },
		},
	};

	s32 sp60[4];
	s32 sp5c;
	u32 *sp58;
	s32 sp54;
	s32 sp50;
	s32 sp4c;
	s32 sp48;
	s32 sp44;
	s32 i;
	s32 j;
	s32 sp38;
	s32 sp28[4];
	s32 sp24;
	s32 sp20;
	s32 sp1c;

	sp5c = stream->scalefac_compress[0][ch];
	sp58 = &stream->preflag[0][ch];
	sp54 = stream->mixed_block_flag[0][ch];
	sp50 = stream->block_type[0][ch];
	sp4c = stream->window_switching[0][ch];

	if ((stream->unk3bc4 != 1 && stream->unk3bc4 != 3) || ch != 1) {
		sp48 = 0;

		if (sp5c < 400) {
			sp60[0] = (sp5c >> 4) / 5;
			sp60[1] = (sp5c >> 4) % 5;
			sp60[2] = (sp5c % 16) >> 2;
			sp60[3] = sp5c % 4;
			*sp58 = 0;
			sp44 = 0;
		} else if (sp5c >= 400 && sp5c < 500) {
			sp60[0] = ((sp5c - 400) >> 2) / 5;
			sp60[1] = ((sp5c - 400) >> 2) % 5;
			sp60[2] = (sp5c - 400) % 4;
			sp60[3] = 0;
			*sp58 = 0;
			sp44 = 1;
		} else if (sp5c >= 500 && sp5c < 512) {
			sp60[0] = (sp5c - 500) / 3;
			sp60[1] = (sp5c - 500) % 3;
			sp60[2] = 0;
			sp60[3] = 0;
			*sp58 = 1;
			sp44 = 2;
		}
	}

	if (stream->unk3bc4 == 1 || stream->unk3bc4 == 3) {
		if (ch == 1) {
			stream->unk3ef8 = sp5c % 2;
			sp38 = sp5c >> 1;
			sp48 = 1;

			if (sp38 < 180) {
				sp60[0] = sp38 / 36;
				sp60[1] = (sp38 % 36) / 6;
				sp60[2] = (sp38 % 36) % 6;
				sp60[3] = 0;
				*sp58 = 0;
				sp44 = 0;
			} else if (sp38 >= 180 && sp38 < 244) {
				sp60[0] = ((sp38 - 180) % 64) >> 4;
				sp60[1] = ((sp38 - 180) % 16) >> 2;
				sp60[2] = (sp38 - 180) % 4;
				sp60[3] = 0;
				*sp58 = 0;
				sp44 = 1;
			} else if (sp38 >= 244 && sp38 < 255) {
				sp60[0] = (sp38 - 244) / 3;
				sp60[1] = (sp38 - 244) % 3;
				sp60[2] = 0;
				sp60[3] = 0;
				*sp58 = 0;
				sp44 = 2;
			}
		}
	}

	if (sp4c && sp50 == 2) {
		bcopy(sp70[sp48][sp44][sp54 + 1], sp28, 0x10);
	} else {
		bcopy(sp70[sp48][sp44][0], sp28, 0x10);
	}

	sp24 = 0;

	if (!sp4c || (sp4c && sp50 != 2)) {
		for (i = 0; i < 4; i++) {
			sp20 = sp60[i];
			sp1c = (1 << sp20) - 1;

			for (j = 0; j < sp28[i]; j++) {
				*(u32 *)(stream->scalefac_l + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;

				if (ch != 0) {
					stream->unk3efc[sp24] = sp1c;
				}

				sp24++;
			}
		}
	} else if (sp50 == 2) {
		if (sp54 == 0) {
			for (i = 0; i < 4; i++) {
				sp20 = sp60[i];
				sp1c = (1 << sp20) - 1;

				for (j = 0; j < sp28[i]; j += 3) {
					*(u32 *)(stream->scalefac_s + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;
					*(u32 *)(stream->unk3d98 + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;
					*(u32 *)(stream->unk3dcc + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;

					if (ch != 0) {
						stream->unk3f14[sp24] = sp1c;
					}

					sp24++;
				}
			}
		} else {
			sp20 = sp60[0];
			sp1c = (1 << sp20) - 1;

			for (j = 0; j < 6; j++) {
				*(u32 *)(stream->scalefac_l + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;

				if (ch != 0) {
					stream->unk3efc[sp24] = sp1c;
				}

				sp24++;
			}

			sp28[0] -= 6;
			sp24 = 3;

			for (i = 0; i < 4; i++) {
				sp20 = sp60[i];
				sp1c = (1 << sp20) - 1;

				for (j = 0; j < sp28[i]; j += 3) {
					*(u32 *)(stream->scalefac_s + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;
					*(u32 *)(stream->unk3d98 + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;
					*(u32 *)(stream->unk3dcc + ch * 0xf8 + sp24 * 4) = sp20 ? mp3decGetBits(stream->unk1c, &stream->unk2020, sp20) : 0;

					if (ch != 0) {
						stream->unk3f14[sp24] = sp1c;
					}

					sp24++;
				}
			}
		}
	}

	return true;
}

bool func00042238(struct asistream *stream, u32 gr, u32 ch)
{
	s32 sp64 = stream->unk2020;
	s32 sp60;
	s32 sp54[3];
	const s16 *sp50;
	const u8 *sp4c;
	s32 sp48;
	s16 *sp44;
	u8 *sp40;
	s32 i;
	u32 sp38;
	s32 sp34;
	s32 sp30;
	s32 sp2c;
	s32 sp28;

	if (stream->version != VERSION_2) {
		mp3decUnpackScaleFac(stream, gr, ch);
	} else {
		func00041600(stream, gr, ch);
	}

	sp60 = stream->big_value[gr][ch] * 2;
	sp50 = var70057860[stream->version][stream->samplerateindex];
	sp4c = var70057968[stream->version][stream->samplerateindex];

	if (stream->window_switching[gr][ch] == 0 && stream->block_type[gr][ch] == 0) {
		sp54[0] = sp50[stream->region0_count[gr][ch]] + 1;

		if (sp54[0] > sp60) {
			sp54[0] = sp54[1] = sp60;
		} else {
			sp54[1] = sp50[stream->region0_count[gr][ch] + stream->region1_count[gr][ch] + 1] + 1;

			if (sp54[1] > sp60) {
				sp54[1] = sp60;
			}
		}
	} else {
		if (stream->block_type[gr][ch] == 2 && stream->mixed_block_flag[gr][ch] == 0) {
			sp54[0] = sp4c[2] * 3 + 3;
		} else {
			sp54[0] = sp50[7] + 1;
		}

		if (sp54[0] > sp60) {
			sp54[0] = sp60;
		}

		sp54[1] = sp60;
	}

	sp54[2] = sp60;
	sp48 = 0;
	sp44 = stream->unk3f94[ch];
	sp40 = stream->unk4418[ch];

	for (i = 0; i < 3; i++) {
		sp38 = stream->table_select[gr][ch][i];
		sp34 = var700577d8[sp38];
		sp30 = sp54[i];

		if (var8009c650[sp38] == NULL) {
			sp2c = sp30 - sp48;

			bzero(sp44, sp2c * 2);

			sp44 += sp2c;
			sp40 += sp2c;
			sp48 = sp30;
		} else {
			sp48 = func000462f8(stream->unk1c, &stream->unk2020, sp38, sp48, sp34, sp30, &sp44, &sp40);
		}
	}

	sp38 = stream->count1table_select[gr][ch] + 32;
	sp28 = stream->part2_3_length[gr][ch] + sp64;
	sp48 = func000464a8(stream->unk1c, &stream->unk2020, sp38, sp48, sp28, &sp44, &sp40);
	stream->unk2020 = sp28;

	if (sp48 > 576) {
		stream->unk465c[ch] = 576;
	} else {
		stream->unk465c[ch] = sp48;
	}

	if (sp48 < 576) {
		stream->unk4660[ch] = 576 - sp48;
		bzero(sp44, stream->unk4660[ch] * 2);
	} else {
		stream->unk4660[ch] = 0;
	}

	return true;
}

bool func000427d8(struct asistream *stream, u32 gr)
{
	const s16 *sp14 = var70057b9c[stream->version][stream->samplerateindex];
	f32 *sp10 = stream->unk4f64[0][0].unk00;
	f32 *sp0c = stream->unk4664[0][0].unk00;
	s32 i = 0;

	if (stream->window_switching[gr][0] && stream->window_switching[gr][2] == 2) {
		if (stream->window_switching[gr][4]) {
			while (i++ < 36) {
				*(sp10++) = *(sp0c++);
			}
		}

		while (i < 576) {
			sp10[sp14[i++]] = *(sp0c++);
		}
	} else {
		while (i++ < 576) {
			*(sp10++) = *(sp0c++);
		}
	}

	return true;
}

bool mp3decReduceAliases(struct asistream *stream, u32 gr, u32 ch)
{
	s32 i;

	if (stream->window_switching[gr][ch] && stream->block_type[gr][ch] == 2) {
		return true;
	}

	for (i = 1; i < 32; i++) {
		struct asistream_4f64 *sp08 = &stream->unk4f64[ch][i];
		f32 sp04;
		f32 sp00;

		sp04 = sp08->unk00[0];
		sp00 = sp08->unk00[-1];
		sp08->unk00[-1] = sp00 * var700596bc[0] - var7005969c[0] * sp04;
		sp08->unk00[0] = sp04 * var700596bc[0] + var7005969c[0] * sp00;

		sp04 = sp08->unk00[1];
		sp00 = sp08->unk00[-2];
		sp08->unk00[-2] = sp00 * var700596bc[1] - var7005969c[1] * sp04;
		sp08->unk00[1] = sp04 * var700596bc[1] + var7005969c[1] * sp00;

		sp04 = sp08->unk00[2];
		sp00 = sp08->unk00[-3];
		sp08->unk00[-3] = sp00 * var700596bc[2] - var7005969c[2] * sp04;
		sp08->unk00[2] = sp04 * var700596bc[2] + var7005969c[2] * sp00;

		sp04 = sp08->unk00[3];
		sp00 = sp08->unk00[-4];
		sp08->unk00[-4] = sp00 * var700596bc[3] - var7005969c[3] * sp04;
		sp08->unk00[3] = sp04 * var700596bc[3] + var7005969c[3] * sp00;

		sp04 = sp08->unk00[4];
		sp00 = sp08->unk00[-5];
		sp08->unk00[-5] = sp00 * var700596bc[4] - var7005969c[4] * sp04;
		sp08->unk00[4] = sp04 * var700596bc[4] + var7005969c[4] * sp00;

		sp04 = sp08->unk00[5];
		sp00 = sp08->unk00[-6];
		sp08->unk00[-6] = sp00 * var700596bc[5] - var7005969c[5] * sp04;
		sp08->unk00[5] = sp04 * var700596bc[5] + var7005969c[5] * sp00;

		sp04 = sp08->unk00[6];
		sp00 = sp08->unk00[-7];
		sp08->unk00[-7] = sp00 * var700596bc[6] - var7005969c[6] * sp04;
		sp08->unk00[6] = sp04 * var700596bc[6] + var7005969c[6] * sp00;

		sp04 = sp08->unk00[7];
		sp00 = sp08->unk00[-8];
		sp08->unk00[-8] = sp00 * var700596bc[7] - var7005969c[7] * sp04;
		sp08->unk00[7] = sp04 * var700596bc[7] + var7005969c[7] * sp00;
	}

	return true;
}

bool mp3decSetSideInfo(struct asistream *stream)
{
	s32 sp34;
	s32 ch;
	s32 scfsi_band;
	s32 sp28;
	s32 gr;
	s32 region;
	s32 window;

	if (stream->version != VERSION_2) {
		stream->unk206c = stream->channelmode == CHANNELMODE_SINGLEMONO ? 17 : 32;
	} else {
		stream->unk206c = stream->channelmode == CHANNELMODE_SINGLEMONO ? 9 : 17;
	}

	sp34 = stream->unk04(stream->unk00, &stream->buffer[stream->unk2068], stream->unk206c, -1);

	if (stream->unk206c != sp34) {
		return false;
	}

	stream->unk18 += stream->unk206c;

	stream->numchannels = stream->channelmode == CHANNELMODE_SINGLEMONO ? 1 : 2;
	stream->numgranules = stream->version != VERSION_2 ? 2 : 1;

	if (stream->version != VERSION_2) {
		stream->main_data_begin = mp3decGetBits(stream->buffer, &stream->count, 9);

		// skip private bits
		stream->numchannels == 1
			? mp3decGetBits(stream->buffer, &stream->count, 5)
			: mp3decGetBits(stream->buffer, &stream->count, 3);
	} else {
		stream->main_data_begin = mp3decGetBits(stream->buffer, &stream->count, 8);

		stream->numchannels == 1
			? mp3decGetBits(stream->buffer, &stream->count, 1)
			: mp3decGetBits(stream->buffer, &stream->count, 2);
	}

	if (stream->version != VERSION_2) {
		for (ch = 0; ch < stream->numchannels; ch++) {
			for (scfsi_band = 0; scfsi_band < 4; scfsi_band++) {
				stream->scfsi[ch][scfsi_band] = mp3decGetBits(stream->buffer, &stream->count, 1);
			}
		}
	}

	if (stream->version != VERSION_2) {
		sp28 = 4;
	} else {
		sp28 = 9;
	}

	for (gr = 0; gr < stream->numgranules; gr++) {
		for (ch = 0; ch < stream->numchannels; ch++) {
			stream->part2_3_length[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 12);
			stream->big_value[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 9);
			stream->global_gain[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 8);
			stream->scalefac_compress[gr][ch] = sp28 ? mp3decGetBits(stream->buffer, &stream->count, sp28) : 0;
			stream->window_switching[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 1);

			if (stream->window_switching[gr][ch]) {
				stream->block_type[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 2);
				stream->mixed_block_flag[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 1);

				for (region = 0; region < 2; region++) {
					stream->table_select[gr][ch][region] = mp3decGetBits(stream->buffer, &stream->count, 5);
				}

				stream->table_select[gr][ch][2] = 0;

				for (window = 0; window < 3; window++) {
					stream->subblock_gain[gr][ch][window] = mp3decGetBits(stream->buffer, &stream->count, 3);
				}
			} else {
				stream->block_type[gr][ch] = 0;
				stream->mixed_block_flag[gr][ch] = false;

				for (region = 0; region < 3; region++) {
					stream->table_select[gr][ch][region] = mp3decGetBits(stream->buffer, &stream->count, 5);
				}

				stream->region0_count[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 4);
				stream->region1_count[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 3);
			}

			if (stream->version != VERSION_2) {
				stream->preflag[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 1);
			}

			stream->scalefac_scale[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 1);
			stream->count1table_select[gr][ch] = mp3decGetBits(stream->buffer, &stream->count, 1);
		}
	}

	stream->unk3f7c = var700596dc[stream->version][stream->bitrateindex];
	stream->unk3f80 = var70059754[stream->version][stream->samplerateindex];

	if (stream->version != VERSION_2) {
		stream->unk3f84 = stream->unk3f7c * 144 / stream->unk3f80;
	} else {
		stream->unk3f84 = stream->unk3f7c * 72 / stream->unk3f80;
	}

	stream->unk3f88 = (stream->unk3f84 + stream->haspadding) - (stream->unk2068 + stream->unk206c);

	return true;
}

bool mp3decDecodeFrame(struct asistream *stream)
{
	s32 sp954;
	s32 gr = 0;
	s32 ch;
	s32 sp948;
	s32 sp944;
	s32 sp940;
	s32 i;
	s32 j;
	u16 *sp934;
	struct asistream_4f64 sp34[32];
	f32 sp30;
	f32 sp2c;
	f32 sp28;
	s32 sp24;
	s32 sp20;

	sp934 = stream->unk2070[stream->unk3ba0].unk00;
	sp954 = func00043dd0(stream);

	if (sp954 == -1) {
		return false;
	}

	stream->unk2020 = (sp954 - stream->main_data_begin) * 8;

	if (stream->unk2020 < 0) {
		return true;
	}

	for (ch = 0; ch < stream->numchannels; ch++) {
		func00042238(stream, gr, ch);
		func00040164(stream, gr, ch);
	}

	func000427d8(stream, gr);

	if (stream->window_switching[gr][0] != 0 && stream->block_type[gr][0] == 2) {
		sp948 = 32;
	} else {
		sp944 = (stream->unk465c[0] - 1) / 18 + 1;
		sp948 = sp944;
	}

	for (ch = 0; ch < stream->numchannels; ch++) {
		mp3decReduceAliases(stream, gr, ch);

		if (stream->window_switching[gr][ch] != 0
				&& stream->block_type[gr][ch] == 2
				&& stream->mixed_block_flag[gr][ch] != 0) {
			sp940 = 0;
		} else if (stream->window_switching[gr][ch] == 0) {
			sp940 = 0;
		} else {
			sp940 = stream->block_type[gr][ch];
		}

		if (sp940 == 2) {
			for (i = 0; i < 2; i++) {
				func00047550(&stream->unk4f64[ch][i], i, &sp34[i], &stream->unk6a64[ch][i]);
			}
		} else {
			for (i = 0; i < 2; i++) {
				func00046650(&stream->unk4f64[ch][i], i, &sp34[i], &stream->unk6a64[ch][i], sine_block[sp940]);
			}
		}

		if (stream->window_switching[gr][ch]
					&& stream->block_type[gr][ch] == 2
					&& stream->mixed_block_flag[gr][ch]) {
			sp940 = 2;
		}

		if (sp940 == 2) {
			for (i = 2; i < sp948; i++) {
				func00047550(&stream->unk4f64[ch][i], i, &sp34[i], &stream->unk6a64[ch][i]);
			}
		} else {
			for (i = 2; i < sp948; i++) {
				func00046650(&stream->unk4f64[ch][i], i, &sp34[i], &stream->unk6a64[ch][i], sine_block[sp940]);
			}
		}

		while (i < 32) {
			bcopy(&stream->unk6a64[ch][i], &sp34[i], sizeof(struct asistream_4f64));
			bzero(&stream->unk6a64[ch][i], sizeof(struct asistream_4f64));
			i++;
		}

		sp30 = 65536;
		sp28 = 1;
		sp20 = sp30 * sp28 * 16;
		*sp934 = sp20 >> 16;
		sp934++;

		*sp934 = sp20 & 0xffff;
		sp934++;

		sp20 = -sp20;
		*sp934 = sp20 >> 16;
		sp934++;

		*sp934 = sp20 & 0xffff;
		sp934++;

		sp2c = 2048 / sp28;

		for (j = 0; j < 18; j++) {
			for (i = 0; i < 32; i++) {
				sp24 = sp34[i].unk00[j] * sp2c;
				*sp934 = sp24;
				sp934++;
			}
		}
	}

	return true;
}
