#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if ((n * m - 1) % 2 == 0)
        puts("NO");
    else
        puts("YES");
    return 0;
}

