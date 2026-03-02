#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 40;
#define bug printf("<--->\n");
vector<long long> fact(maxn+1, 1LL);
int main() {
    for (int i = 1; i < maxn; ++i)
        fact[i] = (fact[i-1] * i) % 1000000000000;
    for (int i = 1; i < maxn; ++i) {
        while (!(fact[i] % 10))
            fact[i] /= 10;
        printf("i = %02d    fact[%02d] = %lld\n", i, i, fact[i] % 10);
    }
    return 0;
}
