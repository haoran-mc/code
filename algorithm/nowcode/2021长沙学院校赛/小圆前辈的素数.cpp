/*----------------------------------------------------------------
 *   
 *   文件名称：小圆前辈的素数.cpp
 *   创建日期：2021年07月23日 星期五 12时03分57秒
 *   题    目：<++>
 *   算    法：fft
 *   描    述：结果可能是long long
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = (1 << 18) + 5;   // 切记，这个是2的一个指数
const double PI = acos(-1.0);
int a[maxn], b[maxn];
#define bug printf("<-->");
#define NEXTLINE puts("");
long long res[maxn];   // 用不用这个存无所谓，存一下吧，和开头的系数也是数组统一

struct Complex {
    double r, i;   // 一定注意，使用%f输出
    Complex() {}
    Complex(double _r, double _i) : r (_r), i (_i) {}
    inline void real(const double& x) {r = x;}
    inline double real() {return r;}
    inline Complex operator + (const Complex& rhs) const {
        return Complex (r + rhs.r, i + rhs.i) ;
    }
    inline Complex operator - (const Complex& rhs) const {
        return Complex (r - rhs.r, i - rhs.i);
    }
    inline Complex operator * (const Complex& rhs) const {
        return Complex (r*rhs.r - i*rhs.i, r*rhs.i + i*rhs.r);
    }
    inline void operator /= (const double& x) {
        r /= x, i /= x ;
    }
    inline void operator *= (const Complex& rhs) {
        *this = Complex (r*rhs.r - i*rhs.i, r*rhs.i + i*rhs.r);
    }
    inline void operator += (const Complex& rhs) {
        r += rhs.r, i += rhs.i;
    }
    inline Complex conj() {    // 共轭复数
        return Complex (r, -i) ;
    }
};

struct FastFourierTransform {
    // 自己封装的复数类
    Complex omega[maxn], omegaInverse[maxn];

    void init(const int& n) {
        for (int i = 0; i < n; ++i) {
            omega[i] = Complex(cos(2*PI / n*i), sin(2*PI / n*i));
            omegaInverse[i] = omega[i].conj();
        }
    }

    void transform(Complex *a, const int& n, const Complex* omega) {
        for (int i = 0, j = 0; i < n; ++i) {
            if (i > j)
                swap(a[i], a[j]);
            for (int l = n >> 1; (j ^= l) < l; l >>= 1);
        }

        for (int l = 2; l <= n; l <<= 1) {
            int m = l / 2;
            for (Complex *p = a; p != a + n; p += l)
                for (int i = 0; i < m; ++i) {
                    Complex t = omega[n / l * i] * p [m + i];
                    p[m + i] = p[i] - t;
                    p[i] += t;
                }
        }
    }

    // 由系数表达式离散为点值表达式
    void dft(Complex *a, const int& n) {
        transform(a, n, omega);
    }

    // 由点值表达式转化为系数表达式
    void idft(Complex *a, const int& n) {
        transform(a, n, omegaInverse);
        for (int i = 0; i < n; ++i)
            a[i] /= n;
    }
} fft;

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
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        int n, m;
        scanf("%d %d", &n, &m);
        int len1 = 0, len2 = 0;
        for (int i = 0; i < n; ++i) {
            int _; scanf("%d", &_);
            a[_]++;
            len1 = max(len1, _);
        }
        for (int i = 0; i < m; ++i) {
            int _; scanf("%d", &_);
            b[_]++;
            len2 = max(len2, _);
        }
        len1 ++, len2 ++;
        int len = 1;
        while (len < len1 * 2 || len < len2 * 2)
            len <<= 1;
        fft.init(len);   // 初始化\omega
        Complex x1[maxn], x2[maxn];   // 存储两个多项式的系数，幂由低到高

        for (int i = 0; i < len; ++i) {
            x1[i].r = 0.0; x1[i].i = 0.0;
            x2[i].r = 0.0; x2[i].i = 0.0;
        }

        for (int i = 0; i < len; ++i) {
            x1[i].r = 1.0 * a[i]; x1[i].i = 0.0;
            x2[i].r = 1.0 * b[i]; x2[i].i = 0.0;
        }
        fft.dft(x1, len); fft.dft(x2, len);
        for (int i = 0; i < len; ++i)
            x1[i] = x1[i] * x2[i];
        fft.idft(x1, len);
        memset(res, 0, sizeof res);
        for (int i = 0; i < len; ++i)
            res[i] = (long long)(x1[i].r + 0.5);   // 我也不知道为什么+0.5，但不加好像就错了

        long long cnt = 0;
        for (int i = 2; i < len; ++i)
            if (judge(i))
                cnt += res[i];

        printf("%lld\n", cnt);
    }
    return 0;
}
