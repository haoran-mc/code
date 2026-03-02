#include <cstdio>
int main() {
    double val;
    double per;
    double div;
    scanf("%lf", &val);
    scanf("%lf", &per);
    scanf("%lf", &div);
    double lim;
    if (per)
        lim = 1.26 * val;
    else
        lim = 2.45 * val;
    printf("%.2f ", lim);
    if (lim < div)
        printf("^_^");
    else
        printf("T_T");
    return 0;
}
