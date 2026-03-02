#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 2 * 6e4 + 5;
#define NEXTLINE puts("");
int primes[maxn], cnt;
bool sifter[maxn];   // false为素数
int powers[maxn];

void get_primes(int n) {
    for (int i = 2; i < n; ++i) {
        if (!sifter[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            sifter[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

// 得到n的阶乘有多少个素因子p
int get(int n, int p) {
    int s = 0;
    while (n) {
        s += n / p;
        n /= p;
    }
    return s;
}

void multi(vector<int> &vec, int b) {
    int t = 0;  // 上一位的进位
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = vec[i] * b + t;
        t = vec[i] / 10;
        vec[i] %= 10;
    }
    while (t) {
        vec.push_back(t % 10);
        t /= 10;
    }
}

void out(vector<int> vec) {
    for (int i = vec.size() - 1; i >= 0; --i)
        printf("%d", vec[i]);
    NEXTLINE
}

int main() {
    int n; scanf("%d", &n);
    get_primes(2 * n);

    for (int i = 0; i < cnt; ++i) {
        int p = primes[i];
        // get函数用于得到n!有多少个素因子p
        powers[p] = get(n * 2, p) - get(n, p) * 2;
    }

    int k = n + 1;
    for (int i = 0; i < cnt && primes[i] <= k; ++i) {
        int p = primes[i], s = 0;
        while (k % p == 0) {
            s++;
            k /= p;
        }
        powers[p] -= s;
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 2; i <= n * 2; ++i)
        for (int j = 0; j < powers[i]; ++j)
            multi(res, i);   // 高精度乘法，高精度数res乘上一个数i

    out(res);
    return 0;
}
