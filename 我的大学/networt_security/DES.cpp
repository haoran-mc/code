#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long ll;

// IP table
int IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7};

// IP reverse
int IP_reverse[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25};

// extension table
int ext[48] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1};

// PC1 compress permutation
int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4};

// key shift
int keyoffset[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

// PC2 compress permutation
int PC2[48] = {
    14, 17, 11, 24, 1, 5,
    3, 88, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32};

// 8 s-boxes
int s_box[8][4][16] = {
    {/*S1*/
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
    {/*S2*/
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
    {/*S3*/
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
    {/*S4*/
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
    {/*S5*/
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
    {/*S6*/
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
    {/*S7*/
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
    {/*S8*/
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

// p_box
int p_box[32] = {
    16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25};



// 0x635C3BB517813826
int cleartext[64] = {
    0, 1, 1, 0, 0, 0, 1, 1,
    0, 1, 0, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 0, 1, 1,
    1, 0, 1, 1, 0, 1, 0, 1,
    0, 0, 0, 1, 0, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 1, 0,};

// 0xcafababedeadbeaf
int key[64] = {
    1, 1, 0, 0, 1, 0, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 0,
    1, 0, 1, 1, 1, 0, 1, 0,
    1, 0, 1, 1, 1, 1, 1, 0,
    1, 1, 0, 1, 1, 1, 1, 0,
    1, 0, 1, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 1, 1, 1, 0,
    1, 0, 1, 0, 1, 1, 1, 1,};

ll reverse(ll x, int len) {
    for (int i = 0; i < len / 2; i ++ ) {
        int l = len - 1 - i;
        int r = i;

        ll l_val = (x >> l) & 1;
        ll r_val = (x >> r) & 1;

        x &= ~(1LL << l);
        x &= ~(1LL << r);

        x |= r_val << l;
        x |= l_val << r;
    }
    return x;
}

void output_binary(ll x) {
    // x = reverse(x, 64);
    for (int i = 0; i < 64; i ++ ) {
        if ((i + 1) % 8 == 0)
            printf("%lld\n", (x >> i) & 1);
        // printf("(%d):%lld\n", i, (x >> i) & 1);
        else
            printf("%lld ", (x >> i) & 1);
    }
    puts("");
}

void output_hex(ll x) {
    // x = reverse(x, 64);
    printf("0x");
    for (int i = 0; i < 16; i ++ ) {
        ll t = reverse(x - (x >> 4 << 4), 4);
        x >>= 4;
        if (t < 10)
            printf("%d", (int)t);
        else
            printf("%c", (int)t - 10 + 'a');
    }
    puts("\n");
}

// 将 x 二进制表示的第 i 位更改为 y 二进制表示的第 j 位
void exbit(ll &x, int i, ll y, int j, int len) {
    // 1. 将 x 的第 i 位赋值 0
    // 2. 获取 y 的 第 j 位与 x 的第 i 位进行 | 操作
    i = len - 1 - i;
    j = len - 1 - j;
    x &= ~(1LL << i);
    x |= ((y >> j) & 1) << i;
}

/*initial permutation*/
ll initial_permutation(ll plain) {
    ll ipm = 0;
    for (int i = 0; i < 64; i ++ ) {
        exbit(ipm, i, plain, IP[i] - 1, 64);
    }
    return ipm;
}

void leftRotate(ll &x, int off) {
    // 镜像
    for (int i = 0; i < off; i ++ ) {
        x <<= 1;
        ll s = (x >> 28) & 1;
        x &= ~(1LL << 28);
        x |= s;
    }
}

void keygen(ll subkey[], ll key) {
    ll tmp_key = 0;   // 经 PC1 置换得到的子密钥

    // PC1 舍弃校验位
    for (int i = 0; i < 56; i ++ ) {
        exbit(tmp_key, i, key, PC1[i] - 1, 56);
    }

    ll l = tmp_key >> 28;         // left  C0
    ll r = tmp_key - (l << 28);   // right D0

    // key shift
    for (int i = 0; i < 16; i ++ ) {
        leftRotate(l, keyoffset[i]);
        leftRotate(r, keyoffset[i]);

        tmp_key = (l << 28) | r;

        // PC2
        ll tmp_subkey = 0;
        for (int i = 0; i < 48; i ++ ) {
            exbit(tmp_subkey, i, tmp_key, PC2[i] - 1, 48);
        }
        subkey[i] = tmp_subkey;
    }
}

ll Expand(ll r) {
    ll t;
    for (int i = 0; i < 48; i ++ ) {
        exbit(t, i, r, ext[i] - 1, 48);
    }
    return t;
}

ll S(ll r) {
    ll t[8] = {0}, s[8] = {0};
    // 把 r 分成 8 份，每份 6 bits
    for (int i = 0; i < 8; i ++ ) {
        s[i] = r - (r >> 6 << 6);
        r >>= 6;

        int row = (s[i] >> 5 << 1) | (s[i] & 1);
        int col = (s[i] & (~(1LL << 6))) >> 1;
        t[i] = s_box[i][row][col];
    }
    for (int i = 7; i >= 0; i -- ) {
        r = (r << 4) + t[i];
    }
    return r;
}

ll P(ll r) {
    ll t;
    for (int i = 0; i < 32; i ++ ) {
        exbit(t, i, r, p_box[i] - 1, 32);
    }
    return t;
}

ll T_iteration(ll itm, ll subkey) {
    ll l = itm >> 32;
    ll r = itm - (l << 32);
    ll last_r = r;

    r = Expand(r);    // Expand
    r = r ^ subkey;   // xor
    r = S(r);         // S
    r = P(r);         // P

    r = l ^ r;
    l = last_r;

    itm = (l << 32) | r;

    return itm;
}

/*final permutation*/
ll final_permutation(ll itm) {
    ll cipher;
    for (int i = 0; i < 64; i ++ ) {
        exbit(cipher, i, itm, IP_reverse[i] - 1, 64);
    }
    return cipher;
}

ll DES(ll plain, ll key, const char* method) {
    // plain = reverse(plain, 64);
    // key = reverse(key, 64);
    if (strcmp(method, "encrypt") == 0) {
        ll ipm = initial_permutation(plain);   // 初始置换 ip message
        // puts("initial permutation: ");
        // output_binary(ipm);

        ll subkey[16];
        keygen(subkey, key);   // 获取 16 个子密钥

        ll itm = ipm;   // itreation message
        for (int i = 0; i < 16; i ++ ) {    // 16 轮迭代
            itm = T_iteration(itm, subkey[i]);
        }

        ll cipher = final_permutation(itm);
        return cipher;
    } else if (strcmp(method, "decrypt") == 0) {
        ll ipm = initial_permutation(plain);   // 初始置换 ip message

        ll subkey[16];
        keygen(subkey, key);   // 获取 16 个子密钥

        ll itm = ipm;   // itreation message
        for (int i = 0; i < 16; i ++ ) {    // 16 轮迭代
            itm = T_iteration(itm, subkey[15 - i]);
        }

        ll cipher = final_permutation(itm);
        return cipher;
    } else {
        puts("wrong method!");
        return 0;
    }
}

int main() {
    // freopen("out.txt", "w", stdout);

    // output_binary(0x11aabbccddeeff01);
    // output_hex(0x11aabbccddeeff01);

    printf("明文：");
    printf("0x11aabbccddeeff01\n\n");

    ll cipher = DES(0x11aabbccddeeff01, 0xcafababedeadbeaf, "encrypt"); // 0x2973a7e54ec730a3
    // output_binary(cipher);
    printf("密文：");
    output_hex(cipher);

    ll text   = reverse(DES(cipher, 0xcafababedeadbeaf, "decrypt"), 64); // 0x635C3BB517813826
    // output_binary(text);
    printf("明文：");
    printf("0x11aabbccddeeff01\n\n");

    return 0;
}
