#include <cstdio>
const int maxn = 100 + 5;
int arr[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    m %= n; // 循环 n 次等于不循环
    int idx[maxn];
    for (int i = 0; i < n; i++) {
        // 值arr[i]的新坐标：(i+m)%n
        idx[(i + m) % n] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", idx[i]);
        else
            printf("%d", idx[i]);
    }
    return 0;
}
