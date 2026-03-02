#include <cstdio>
#include <cstdlib>
#include <ctime>
int p, q, h, g, y;

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

void init_param() {
    p = 7879;
    q = 101;
    h = 3;
    g = binpow(h, (p-1)/q, p);
}

struct Message {
    int m;
    int r;
    int s;
};

class Sender {
    private:
        int x;   // 私钥
        int m;   // 信息
    public:
        void getInfo();   // 获取信息
        Message send();   // 将信息封装成一个 Message，然后发送
};

void Sender::getInfo() {
    puts("input the message you will send:");
    scanf("%d", &this->m);
}

Message Sender::send() {
    Message M;
    M.m = this->m;

    // this->x = rand() % (q - 1) + 1;   // 选择一个随机值 x, 0 < x < q
    this->x = 75;                   // 私钥 x
    y = binpow(g, this->x, p);      // 公钥 y
    printf("\nx: %d\t\ty: %d\n", x, y);

    srand((int)(time(NULL)));
    // int k = rand() % (q - 1) + 1;   // 选择一个随机值 k, 0 < k < q
    int k = 50;

    M.r = binpow(g, k, p) % q;                       // r
    M.s = (inv(k, q) * (M.m + this->x * M.r)) % q;   // s

    return M;
}

void output(Message M, int w, int u1, int u2, int v) {
    printf("p: %d\t\tq: %d\t\th: %d\t\tg: %d\n", p, q, h, g);
    printf("M: %d\t\tr: %d\t\ts: %d\n", M.m, M.r, M.s);
    printf("w: %d\t\tu1: %d\t\tu2: %d\t\tv: %d\n\n", w, u1, u2, v);
}

class Receiver {
    public:
        bool receive(Message M);
};

bool Receiver::receive(Message M) {
    if ((0 < M.r && M.r < q) && (0 < M.s && M.s < q)) {
        int w = inv(M.s, q) % q;
        int u1 = (M.m * w) % q;
        int u2 = (M.r * w) % q;
        int v = (binpow(g, u1, p) * binpow(y, u2, p) % p) % q;

        output(M, w, u1, u2, v);
        return v == M.r ? true : false;
    }
    else {
        return false;
    }
}

int main() {
    init_param();   // 获取必要参数
    Sender sender;       // 发送对象
    Receiver receiver;   // 接收对象

    sender.getInfo();    // 发送信息

    bool is_valid = receiver.receive(sender.send());   // 发送与验证

    if (is_valid) {
        puts("Authentication is successful");
    }
    else {
        puts("Validation fails");
    }
    return 0;
}
