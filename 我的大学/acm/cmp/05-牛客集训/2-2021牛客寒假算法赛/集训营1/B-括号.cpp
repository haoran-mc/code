#include <cstdio>
#include <cmath>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf(")");
        return 0;
    }
    int L = (int)sqrt(n);
    int R = L;
    int p = n - L * L;
    while (p >= L) {
        ++R;
        p = n - L * R;
    }
    int t = n - L * R;
    if (L == 1) {
        t = 1e9;
        R = n;
    }
    for (int i = 0; i < L; ++i) {
        if (t && i == t)
            printf(")");
        printf("(");
    }
    for (int i = 0; i < R; ++i)
        printf(")");
    return 0;
}
