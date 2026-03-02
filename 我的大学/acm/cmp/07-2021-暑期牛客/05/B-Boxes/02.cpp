#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 7;
double a[maxn], preS, res;

bool cmp(double x, double y) {
    return x < y;
}

int main() {
    int n; double C;
    scanf("%d %lf", &n, &C);
    res = C;
    for(int i = 1; i <= n; ++i)
        scanf("%lf", &a[i]);
    sort(a + 1, a + 1 + n,cmp);
    for(int i = 1; i <= n; ++i) {
        res += preS * pow(0.5, n - i + 1);
        preS += a[i];
    }
    res = min(res, preS);
    printf("%.7f", res);
    return 0;
}
