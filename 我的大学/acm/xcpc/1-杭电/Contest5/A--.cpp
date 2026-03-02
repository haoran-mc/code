#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ill;
ill mod = 998244353;
ill numerator[6000001];
ill denominator[6000001];

ill binaryPow (ill base, ill expo, ill mod) {
    if (expo < 0)
        return 0;

    ill ans = 1;
    base %= mod;

    while (expo) {
        if (expo & 1)
            ans = (ans * base) % mod;

        expo >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}

int main(){
    ill p, q;
	q = 0;
	p = 1;

	for(ill i = 1; i <= 6000000; i++) {
		q = (q * (i * i % mod) + p % mod) % mod;
		p = (p * (i * i % mod)) % mod;
		numerator[i] = p;
		denominator[i] = q;
	}

    int T;
	scanf("%d", &T);
    ill n;
	while(T--) {
		scanf("%lld", &n);
		p = numerator[n];
		q = denominator[n];
		q = 3 * q % mod;
		p = p * n % mod;
		printf("%lld\n", ((q % mod) * (binaryPow(p, mod - 2, mod) % mod)) % mod);
	}
	return 0;
}
