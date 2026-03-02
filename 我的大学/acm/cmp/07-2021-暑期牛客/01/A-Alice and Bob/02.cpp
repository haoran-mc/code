/*----------------------------------------------------------------
 *
 *   文件名称：03.cpp
 *   创建日期：2021年07月18日 星期日 23时45分07秒
 *   题    目：<++>
 *   算    法：暴力，实际上需要使用sg函数
 *   描    述：奇怪了，把上面的这个四层放在一个init函数中，然后调用
 *      竟然会超时
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 5e3 + 5;
bool used[maxn][maxn];  // [0][0]是后手胜，为false

int main() {
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j) {
            if (!used[i][j]) {   // 如果后手胜，枚举前一步的状态，标记为先手胜
                for (int k = 1; i + k < maxn; ++k)
                    for (int s = 0; s * k + j < maxn; ++s)
                        used[i + k][s * k + j] = true;

                for (int k = 1; j + k < maxn; ++k)
                    for (int s = 0; s * k + i < maxn; ++s)
                        used[i + s * k][j + k] = true;
            }
        }

    int t; scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (used[n][m])
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
