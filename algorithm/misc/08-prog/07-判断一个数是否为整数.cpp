#include <cstdio>
const double eps = 1e-8;

int main() {
    double x;
    scanf("%lf", &x);
    if ((double)x - (int)x < eps)
        printf("%.6f is a positive number!\n", x);
    else
        printf("%.6f is not a positive number!\n", x);
    return 0;
}
