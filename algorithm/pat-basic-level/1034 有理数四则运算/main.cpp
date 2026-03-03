#include <cmath>
#include <cstdio>
using namespace std; // 有坑：必须要使用 std 命名空间，否则下面的 abs 调用的是 cstdlib 里的 abs
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void p(ll a, ll b) {
    if (a == 0) {
        printf("0");
        return;
    }
    if (b == 0) {
        printf("Inf");
        return;
    }

    bool nega = false;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        nega = true;
        printf("(-");
    }

    a = abs(a);
    b = abs(b);
    ll a3 = a / b;
    a = a - a3 * b;

    // 约分 4/6
    if (a != 0 && b != 0) {
        ll r = gcd(a, b);
        a /= r;
        b /= r;
    }

    if (a3 != 0) {
        printf("%lld", a3);
    }

    if (a3 != 0 && a != 0) {
        printf(" ");
    }

    if (a != 0) {
        printf("%lld/%lld", a, b);
    }

    if (nega) {
        printf(")");
    }
}

int main() {
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

    p(a, b);
    printf(" + ");
    p(c, d);
    printf(" = ");
    p((a * d) + (b * c), b * d);
    printf("\n");

    p(a, b);
    printf(" - ");
    p(c, d);
    printf(" = ");
    p((a * d) - (b * c), b * d);
    printf("\n");

    p(a, b);
    printf(" * ");
    p(c, d);
    printf(" = ");
    p(a * c, b * d);
    printf("\n");

    p(a, b);
    printf(" / ");
    p(c, d);
    printf(" = ");
    p(a * d, b * c);

    return 0;
}
