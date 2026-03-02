#include <cstdio>
const int maxn = 10;   // 限定最多 10 个矩阵
int p[maxn], m[maxn][maxn];

int main() {
    int n; scanf("%d", &n);

    for (int i = 0; i < n+1; ++ i)
        scanf("%d", &p[i]);   // 矩阵的维度

    for (int i = 2; i <= n; ++ i) {
        for (int j = 0; j <= n-i; ++ j) {
            int r = j + i - 1;
            m[j][r] = m[j + 1][r] + p[j] * p[j + 1] * p[r + 1];   // m[i][j]初值
            // 求最小值
            for (int k = j + 1; k < r; ++ k) {
                m[j][r] = min(m[j][r], m[j][k] + m[k + 1][r] + p[j] * p[k + 1] * p[r + 1]);
            }
        }
    }
    printf("%d\n", m[0][n - 1]);
    return 0;
}
