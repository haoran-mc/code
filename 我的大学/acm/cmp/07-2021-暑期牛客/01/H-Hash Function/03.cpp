#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1 << 21;
const double PI = acos(-1.0);
#define bug printf("<-->");
#define NEXTLINE puts("");
int offset = 5e5 + 5;   // 偏移量
int used[maxn];

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

bool judge(int x) {
    for (int i = x; i <= offset; i += x)
        if (used[i])
            return false;
    return true;
}

int main() {
    int n; scanf("%d", &n);
    int len1 = 0, len2 = 0;
    Complex x1[maxn], x2[maxn];   // 存储两个多项式的系数，幂由低到高
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        x1[x].real(1);
        x2[offset - x].real(1);
        len1 = max(len1, x);
        len2 = max(len2, offset - x);
    }
    int len = 1;
    while (len < len1 * 2 || len < len2 * 2)
        len <<= 1;
    fft.init(len);   // 初始化\omega
    fft.dft(x1, len); fft.dft(x2, len);
    for (int i = 0; i < len; ++i)
        x1[i] = x1[i] * x2[i];
    fft.idft(x1, len);
    // 这里很巧妙
    for (int i = 0; i < len; ++i)
        if ((int)(x1[i].real() + 0.5))
            used[abs(i - offset)] = 1;
    for (int i = n; i < offset+1; ++i)
        if (judge(i)) {
            printf("%d\n",i);
            break;
        }
    return 0;
}
