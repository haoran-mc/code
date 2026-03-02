#include <bitset>
#include <string>
#include <iostream>
using namespace std;

// 64位密钥
bitset<64> key;
// 存放16轮子密钥
bitset<48> subkey[16];

// 初始置换表
int IP[] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};
// 逆初始置换表
int IP_1[] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};

// E盒置换表
int E[] = {
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};

// S盒代换表
int S[8][4][16] = {
    {
        { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7 },
        { 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8 },
        { 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0 },
        { 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 }
    },
    {
        { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10 },
        { 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5 },
        { 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15 },
        { 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 }
    },
    {
        { 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8 },
        { 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1 },
        { 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7 },
        { 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 }
    },
    {
        { 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15 },
        { 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9 },
        { 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4 },
        { 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 }
    },
    {
        { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9 },
        { 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6 },
        { 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14 },
        { 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 }
    },
    {
        { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11 },
        { 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8 },
        { 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6 },
        { 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 }
    },
    {
        { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1 },
        { 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6 },
        { 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2 },
        { 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 }
    },
    {
        { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7 },
        { 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2 },
        { 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8 },
        { 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 }
    }
};

// P盒置换表
int P[32] = {
    16,7,20,21,
    29,12,28,17,
    1,15,23,26,
    5,18,31,10,
    2,8,24,14,
    32,27,3,9,
    19,13,30,6,
    22,11,4,25
};

// 密钥置换选择表,64位变56位
int PC_1[56] = {
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
};
// 密钥置换选择表,56位变48位
int PC_2[48] = {
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
};
//密钥位移次数
int shift[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

// 将char字符数组转为二进制
bitset<64> charTobitset(const char s[8]){
    bitset<64> bits;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; j++)
            bits[7*(i+1) - j + i] = (s[i] >> j) & 1;
    }

    return bits;
}
// 将二进制转为string数组
string bitsetTochar(bitset<64> b) {
    bitset<8> temp;
    char ch[9];
    for (int i = 0, j = 0; i < 64; i++) {
        temp[i % 8] = b[i];
        if ((i + 1) % 8 == 0) {
            ch[j] = char(temp[7] + temp[6] * 2 + temp[5] * 4
                    + temp[4] * 8 + temp[3] * 16 + temp[2] * 32
                    + temp[1] * 64 + temp[0] * 128);
            j++;
        }
    }
    ch[8] = '\0';
    return string(ch);
}


// 轮函数F
bitset<32> F(bitset<32> LR, bitset<48> K) {
    // 扩展置换E，将32位输入变成48位输出
    bitset<48> LR48;
    for (int i = 0; i < 48; i++) {
        LR48[i] = LR[E[i] - 1];
    }
    // 密钥加，异或
    LR48 = LR48 ^ K;
    // 密钥加非线性代换（S盒），48位输入变32位输出
    bitset<32> LR32;
    for (int i = 0, j = 0; i <48; i += 6, j += 4) {
        int row = LR48[i] * 2 + LR48[i + 5];//行
        int col = LR48[i + 1] * 8 + LR48[i + 2] * 4
            + LR48[i + 3] * 2 + LR48[i + 4];//列
        int num = S[i / 6][row][col];
        // 这里比较神奇，数据是倒过来的
        bitset<4> temp(num);
        LR32[j] = temp[3];
        LR32[j + 1] = temp[2];
        LR32[j + 2] = temp[1];
        LR32[j + 3] = temp[0];
    }
    // 线性置换（P盒）
    bitset<32> newLR32;
    for (int i = 0; i < 32; i++) {
        newLR32[i] = LR32[P[i] - 1];
    }

    return newLR32;
}


// 循环左移
bitset<28> Left(bitset<28> LR, int step) {
    bitset<28> newLR;
    for (int i = 0; i < 28; i++) {
        newLR[i] = LR[(i + step) % 28];
    }
    return newLR;
}
// 生成16个子密钥
void GenerateSubkeys() {
    // 56位有效密钥
    int i, j;
    bitset<56> newkey;
    for (i = 0; i < 56; i++) {
        newkey[i] = key[PC_1[i] - 1];
    }
    // 分成2个28位数据
    bitset<28> L;
    bitset<28> R;
    for (i = 0; i < 28; i++) {
        L[i] = newkey[i];
        R[i] = newkey[i + 28];
    }
    // 循环左移生成子密钥
    for (i = 0; i < 16; i++) {
        L = Left(L, shift[i]);
        R = Left(R, shift[i]);
        for (j = 0; j < 28; j++) {
            newkey[j] = L[j];
            newkey[j + 28] = R[j];
        }
        for (j = 0; j < 48; j++) {
            subkey[i][j] = newkey[PC_2[j] - 1];
        }
    }
}


// DES加密算法,64位明文转64位密文
bitset<64> des(bitset<64>& plain) {
    // 初始置换
    int i;
    bitset<64> newplain;
    for (i = 0; i < 64; i++) {
        newplain[i] = plain[IP[i] - 1];
    }
    // 分成左右两组
    bitset<32> L;
    bitset<32> R;
    for (i = 0; i < 32; i++) {
        L[i] = newplain[i];
        R[i] = newplain[i + 32];
    }
    // 16轮迭代
    bitset<32> newL;
    for (i = 0; i < 16; i++) {
        newL = R;
        R = L ^ F(R, subkey[i]);
        L = newL;
    }
    // 合并成一组
    bitset<64> encrypt;
    for (i = 0; i < 32; i++) {
        encrypt[i] = R[i];
        encrypt[i + 32] = L[i];
    }
    // 逆初始置换
    bitset<64> encryption;
    for (i = 0; i < 64; i++) {
        encryption[i] = encrypt[IP_1[i] - 1];
    }

    return encryption;
}

// DES解密算法,64位密文转64位明文
bitset<64> re_des(bitset<64>& encription) {
    // 初始置换
    int i;
    bitset<64> newencription;
    for (i = 0; i < 64; i++) {
        newencription[i] = encription[IP[i] - 1];
    }
    // 分成左右两组
    bitset<32> L;
    bitset<32> R;
    for (i = 0; i < 32; i++) {
        L[i] = newencription[i];
        R[i] = newencription[i + 32];
    }
    // 16轮迭代
    bitset<32> newL;
    for (i = 15; i >= 0; i--) {
        newL = R;
        R = L ^ F(R, subkey[i]);
        L = newL;
    }
    // 合并成一组
    bitset<64> replain;
    for (i = 0; i < 32; i++) {
        replain[i] = R[i];
        replain[i + 32] = L[i];
    }
    // 逆初始置换
    bitset<64> plain;
    for (i = 0; i < 64; i++) {
        plain[i] = replain[IP_1[i] - 1];
    }

    return plain;
}

// 比较加密后串位的不同
int compare(bitset<64>a, bitset<64>b) {
    int i, j;
    for (i = 0, j = 0; i < 64; i++) {
        if (a[i] != b[i])
            j++;
    }
    return j;
}

void output_hex(bitset<64> x) {
    printf("0x");
    int t = 0;
    for (int i = 0; i <= 64; i ++ ) {
        int j = i % 4;
        if (i != 0 && i % 4 == 0) {
            if (t < 10)
                printf("%d", t);
            else
                printf("%c", t - 10 + 'a');
            t = 0;
            if (i == 64)
                break;
        }
        t += x[i] << (3 - j);
    }
    puts("");
}

int main() {
    freopen("out1.txt", "w", stdout);
    string s = "ckjckjck";
    string k = "87876565";

    bitset<64> plain = charTobitset(s.c_str());
    key = charTobitset(k.c_str());

    long long t_ = 0x11aabbccddeeff01;
    long long k_ = 0xcafababedeadbeaf;

    for (int i = 0; i < 64; i ++ ) {
        plain[63 - i] = (t_ >> 1) & 1;
        t_ >>= 1;
    }

    for (int i = 0; i < 64; i ++ ) {
        if ((i + 1) % 8 == 0)
            cout << plain[i] << endl;
        else
            cout << plain[i];
    }

    cout << endl;

    for (int i = 0; i < 64; i ++ ) {
        key[63 - i] = (k_ >> 1) & 1;
        k_ >>= 1;
    }

    for (int i = 0; i < 64; i ++ ) {
        if ((i + 1) % 8 == 0)
            cout << plain[i] << endl;
        else
            cout << plain[i];
    }

    cout << endl;

    for (int i = 0; i < 64; i ++ ) {
        if ((i + 1) % 8 == 0)
            cout << key[i] << endl;
        else
            cout << key[i];
    }

    puts("plain: ");
    output_hex(plain);
    puts("key: ");
    output_hex(key);

    for (int i = 0; i < 64; i ++ )
        cout << plain[i];
    cout << endl;
    for (int i = 0; i < 64; i ++ )
        cout << key[i];
    cout << endl;

    GenerateSubkeys();
    bitset<64> encription = des(plain);
    bitset<64> message = re_des(encription);

    cout << "明文：" << s << endl;
    cout << "明文二进制：" << plain << endl;

    cout << "密钥：" << k << endl;
    cout << "密钥二进制：" << key << endl;

    cout << "加密后结果：" << encription << endl;

    cout << "解密后明文：" << message << endl;

    output_hex(message);

    cout << "解密后明文：" << bitsetTochar(message) << endl;
    return 0;
}
