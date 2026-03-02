#include <cstdio>
#include <cmath>
const double eps = 1e-8;

inline int dcmp(double x, double y) { //比较两个浮点数：0 相等；-1 小于；1 大于
    if (fabs(x - y) < eps) return 0;
    else return x < y ? -1 : 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        double p, q;
        scanf("%lf %lf", &p, &q);
        if (dcmp(p, q) <= 0)
            printf("N0 M0R3 BL4CK 1CE TEA!\n");
        else
            printf("ENJ0Y YOURS3LF!\n");
    }
    return 0;
}
