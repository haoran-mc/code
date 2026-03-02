#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 1e2;
const int mod  = 1e9 + 7;

vector<LL> primeFactor;
LL chan() {
    LL res = 0;
    for (int i = 0; i < (int)primeFactor.size(); ++i) {
        res = res * 10 + primeFactor[i];
        res %= mod;
    }
    return res;
}

LL PrimeFactor(LL num) {
    primeFactor.clear();
    for (LL i = 2; pow(i, 2) <= num; ++i)
        while (!(num % i)) {
            num /= i;
            primeFactor.push_back(i);
        }
    if (num > 1)
        primeFactor.push_back(num);
    return chan();
}

int main() {
    LL num;
    scanf("%lld", &num);
    LL res = 0;
    for (int i = 2; i <= num; ++i) {
        res += PrimeFactor(i);
        res %= mod;
    }
    printf("%lld\n", res);
    return 0;
}
