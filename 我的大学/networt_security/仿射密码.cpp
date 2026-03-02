#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

const int N = 26;    // 字母字符的个数 26
const int MOD = N;   // 字符个数

int a, b;

void init_param() {
    srand((int)(time(NULL)));
    a = 7;
    b = rand() % (N - 1) + 1;   // b \in [1, N)
}

// 快速幂，快速求幂函数
int binpow(int base, int expo, int MOD) {
    long long res = 1;
    while (expo) {
        if (expo & 1)
            res = (1LL * res * base) % MOD;
        base = (1LL * base * base) % MOD;
        expo >>= 1;
    }
    return res;
}

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 在 mod MOD 的意义下，a 的逆元
int inv(int a, int MOD) {
    int x, y;
    int gcd = exgcd(a, MOD, x, y);
    gcd += 1;
    return (x % MOD + MOD) % MOD;
}

void encode(char chs[]) {
    int len = strlen(chs);
    for (int i = 0; i < len; i++ ) {
        chs[i] = chs[i] - 'a';
        chs[i] = (a * (int)chs[i] + b) % MOD;
    }
}

void decode(char chs[]) {
    int len = strlen(chs);
    for (int i = 0; i < len; i++ ) {
        chs[i] = ((inv(a, MOD) % MOD) * (((int)chs[i] - b + MOD) % MOD)) % MOD + 'a';
    }
}

int main() {
    init_param();

    printf("input a string: ");
    char str[50];   // 输入一串长度不超过 50 的字符信息，仅接受字母字符
    scanf("%s", str);

    encode(str);
    printf("encode: %s\n", str);

    decode(str);
    printf("decode: %s\n", str);
    return 0;
}
