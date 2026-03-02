#include <cstdio>
#include <cstring>
typedef unsigned long long ull;
const int maxn = 1e7 + 5;
int P = 131;   // P进制数，虽然没写Q = 2^64，但是ull溢出隐藏了这一步
char text[maxn];
char str[maxn];

ull ha[maxn], p[maxn];   // 发现公式中需要乘一个p的一个指数，所以用一个数组预处理

ull get(int l, int r) {
    return ha[r] - ha[l - 1] * p[r - l + 1];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", text + 1);
        p[0] = 1;
        for (int i = 1; i <= strlen(text + 1); ++i) {
            p[i] = p[i-1] * P;
            ha[i] = ha[i-1] * P + text[i];
        }
        int m; scanf("%d", &m);
        while (m--) {
            scanf("%s", str + 1);
            ull res = 0;
            for (int i = 1; i <= strlen(str + 1); ++i)
                res = res * P + str[i];
            int f = 1;
            int cnt = 0;
            for (int i = 1; i <= strlen(text + 1) - strlen(str + 1) + 1; i += f) {
                f = 1;
                if (get(i, i + strlen(str + 1) - 1) == res) {
                    f = strlen(str + 1);
                    ++cnt;
                }
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}
