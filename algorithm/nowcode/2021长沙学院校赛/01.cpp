#include <cstdio>
#include <cmath>
#include <complex>
#include <cstring>
using namespace std;

typedef complex<double> CP;
const int maxn = 1<<18;
const double Pi = acos(-1.0);
int ilen = 0;
int a[maxn], b[maxn];

void FFT(CP *x,int n,double inv) {
    int bit = 0,t;
    while((1<<bit) < n) ++bit;
    for (int i = 0; i < n; ++i) {
        t = 0;
        for (int j = 0; j < bit; ++j)
            if(i & (1<<j)) t |= (1 << (bit-j-1));
        if (i < t) swap(x[i],x[t]);
    }
    CP stand,now,a;
    for (int ilen = 2; ilen <= n; ilen <<= 1) {
        stand = CP( cos(2*Pi/ilen),inv*sin(2*Pi/ilen) );
        t = (ilen >> 1);
        for (CP *p = x; p != x+n; p += ilen) {
            now = CP(1.0,0);
            for (int i = 0; i < t; ++i,now *= stand) {
                a = now * p[i+t];
                p[i+t] = p[i] - a;
                p[i] = p[i] + a;
            }
        }
    }
}

bool judge(int _) {
    for (int i = 2; i <= sqrt(_); ++i)
        if (!(_ % i))
            return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n, m;
        scanf("%d %d", &n, &m);
        int len1 = 0, len2 = 0;
        for (int i = 0; i < n; ++i) {
            int _; scanf("%d", &_);
            a[_] ++;
            len1 = max(len1, _);
        }
        for (int i = 0; i < m; ++i) {
            int _; scanf("%d", &_);
            b[_] ++;
            len2 = max(len2, _);
        }
        len1 ++, len2 ++;
        int len = 1;
        while (len < len1 * 2 || len < len2 * 2)
            len <<= 1;
        CP x1[len], x2[len];

        for (int i = 0; i < len; ++i) {
            x1[i].real(0.0); x1[i].imag(0.0);
            x2[i].real(0.0); x2[i].imag(0.0);
        }
        for (int i = 0; i < len; ++i) {
            x1[i].real(a[i]*1.0);
            x2[i].real(b[i]*1.0);
        }
        FFT(x1, len, 1.0); FFT(x2, len, 1.0);
        for (int i = 0; i < len; ++i)
            x1[i] *= x2[i];
        FFT(x1, len, -1.0);

        long long cnt = 0;
        for (int i = 2; i < len; ++i)
            if (judge(i))
                cnt += floor(x1[i].real() / len + 0.5);

        printf("%lld\n", cnt);
    }
    return 0;
}
