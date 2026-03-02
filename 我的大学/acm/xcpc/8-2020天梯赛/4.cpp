#include <cstdio>
const int maxn = 1005;
double arr[maxn];
int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i]);
        sum += (1.0 / arr[i]);
    }
    printf("%.2f", 1.0/(sum/(double)n));
    return 0;
}
