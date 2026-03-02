#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

template<typename T>
T Gcd(T num1, T num2) {
    return !num2 ? num1 : Gcd(num2, num1 % num2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int maxidx = 0;
        double maxi = -inf;
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
            if ((1.0 * a * i + b) / (double)pow(2, i) > maxi) {
                maxi = (1.0 * a * i + b) / (double)pow(2, i);
                maxidx = i;
            }
        int num = a * maxidx + b;
        int dnm = pow(2, maxidx);
        int tem = num;
        num /= Gcd(abs(tem), abs(dnm));
        dnm /= Gcd(abs(tem), abs(dnm));
        if (num * dnm < 0)
            num = -abs(num),
            dnm = abs(dnm);
        dnm == 1 ? printf("%d\n", num) : printf("%d/%d\n", num, dnm);
    }
    return 0;
}
