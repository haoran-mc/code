#include <cstdio>
using namespace std;

#define ill long long
const int N = 6e6 + 5;
const ill mod = 998244353;
int inv[N],sum[N];

int main() {
	inv[0] = 1;
    inv[1] = 1;

    for (int i = 2; i < N; i++)
        inv[i] = -mod / i * inv[mod % i] % mod + mod;

    for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + 1ll * inv[i] * inv[i] % mod;
		if (sum[i] >= mod)
            sum[i] -= mod;
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		ill ans = 3ll * sum[n] * inv[n] % mod;
		printf("%lld\n",ans);
	}
}

