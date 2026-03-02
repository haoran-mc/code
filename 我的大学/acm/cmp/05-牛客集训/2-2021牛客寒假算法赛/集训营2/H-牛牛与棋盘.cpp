#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    n /= 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("01");
        printf("\n");
        for (int j = 0; j < n; ++j)
            printf("10");
        printf("\n");
    }
    return 0;
}
