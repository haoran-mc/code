#include <cstdio>
#include <algorithm>
using namespace std;

struct Fraction {
    int up;
    int down;
};

int gcd(int m, int n) {
    int temp;
    //无论m>n还是m<n;可以交换
    while(n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

//分数的化简
//1. 如果分母为负数，分子分母化为相反数
//2. 分子为零，规定分母变为1
//3. 分子分母没有除了1以外的公约数
Fraction simplify(Fraction result) {
    if (result.down < 0) {
        result.up   = - result.up;
        result.down = - result.down;
    }

    if (result.up == 0)
        result.down = 1;

    else {
        int divisor  = gcd(abs(result.up), abs(result.down));
        result.up   /= divisor;
        result.down /= divisor;
    }

    return result;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up   = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return simplify(result);
}

Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up   = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return simplify(result);
}

Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up   = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return result;
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up   = f1.up * f2.down;
    result.down = f1.down * f2.down;
    return simplify(result);
}

void showResult(Fraction r) {
    r = simplify(r);
    if (r.down == 1)
        printf("%d\n", r.up);

    else if (abs(r.up) > r.down)
        printf("%d %d/%d\n", r.up / r.down, abs(r.up) % r.down, r.down);

    else
        printf("%d/%d\n", r.up, r.down);
}

int main() {
    Fraction f1;
    Fraction f2;
    scanf("%d %d", &f1.up, &f1.down);
    //scanf("%d %d", &f2.up, &f2.down);
    showResult(f1);
    //showResult(f2);
    return 0;
}
