#include <cstdio>
int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a + b;
    int res = 1;
    for (int i = 1; i <= c; i ++ )
        res *= i;
    printf("%d\n", res);
    return 0;
}