#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 5;

struct Moon {
    double have;
    double total;
    double price;
} moon[maxn];

bool cmp(Moon m1, Moon m2) { return m1.price > m2.price; }

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &moon[i].have);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &moon[i].total);
        moon[i].price = moon[i].total / moon[i].have;
    }
    sort(moon, moon + n, cmp);
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (d >= moon[i].have) {
            d -= moon[i].have;
            res += moon[i].total;
        } else if (d == 0) {
            break;
        } else {
            res += d * moon[i].price;
            break;
        }
    }
    printf("%.2lf\n", res);
    return 0;
}
