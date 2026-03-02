#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
LL box[maxn << 1];

int main() {
    int t;
	scanf("%d", &t);
	while(t--) {
        int n;
		LL sum = 0, maxi = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &box[i]);
			maxi = max(maxi, box[i]);
			sum += box[i];
		}
		LL tmp = ceil(sum*1.0 / (n-1));
		LL k = max(maxi, tmp);
		LL ans = k*(n-1) - sum;
		printf("%lld\n", ans);
	}
    return 0;
}
