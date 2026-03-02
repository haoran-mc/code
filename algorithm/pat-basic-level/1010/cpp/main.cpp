#include <cstdio>
const int maxn = 2000 + 5;
int a[maxn], b[maxn];

int main() {
    int cnt = 0;

    while (scanf("%d %d", &a[cnt], &b[cnt]) != EOF) {
        cnt++;
    }

    if (cnt == 1) {
        printf("0 0");
        return 0;
    }

    if (b[cnt - 1] == 0)
        cnt--;

    for (int i = 0; i < cnt; i++) {
        if (i != cnt - 1)
            printf("%d %d ", a[i] * b[i], b[i] - 1);
        else
            printf("%d %d", a[i] * b[i], b[i] - 1);
    }

    return 0;
}
