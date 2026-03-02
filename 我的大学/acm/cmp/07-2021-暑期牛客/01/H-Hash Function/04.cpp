#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;
typedef complex<double> CP;
const int maxn = 1<<21;
const double Pi = acos(-1);
const int offset = 5e5 + 5;
CP x1[maxn], x2[maxn];
bool used[maxn];

void FFT(CP *x,int maxn,int inv) {
    int bit = 1,m;
    CP stand,now,temp;
    while((1<<bit) < maxn) ++bit;
    for (int i = 0; i < maxn; ++i) {
        m = 0;
        for (int j = 0; j < bit; ++j)
            if(i & (1<<j)) m |= (1<<(bit-j-1));
        if(i < m) swap(x[m],x[i]);
    }
    for (int len = 2; len <= maxn; len <<= 1) {
        m = len >> 1;
        stand = CP(cos(2*Pi/len),inv*sin(2*Pi/len));
        for (CP *p = x; p != x+maxn; p += len) {
            now = CP(1,0);
            for (int i = 0; i < m; ++i,now*=stand) {
                temp = now * p[i+m];
                p[i+m] = p[i] - temp;
                p[i] = p[i] + temp;
            }
        }
    }
    if(inv == -1)
        for (int i = 0; i < maxn; ++i)
            x[i].real(x[i].real()/maxn);
}

bool judge(int x) {
    for (int i = x; i <= offset; i += x)
        if (used[i]) 
            return false;
    return true;
}

int main() {
    int n; scanf("%d",&n);
    int len1 = 0, len2 = 0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d",&x);
        x1[x].real(1);
        x2[offset - x].real(1); // 负数做偏移
        len1 = max(len1, x);
        len2 = max(len2, offset - x);
    }
    int len = 1;
    while (len < len1 * 2 || len < len2 * 2)
        len <<= 1;
    FFT(x1, len, 1); FFT(x2, len, 1);
    for (int i = 0; i < len; ++i)
        x1[i] *= x2[i];
    FFT(x1, len, -1);
    for (int i = 0; i < len; ++i) 
        if ((int)(x1[i].real() + 0.5) > 0)
            used[abs(i - offset)] = 1;
    for (int i = n; i < offset+1; ++i)
        if (judge(i)) {
            printf("%d\n",i);
            break;
        }
    return 0;
}
