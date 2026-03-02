#include <cstdio>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a, b;
        for (int i = 0; i < n-1; ++i)
            scanf("%d %d", &a, &b);
        if (n == 1)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
