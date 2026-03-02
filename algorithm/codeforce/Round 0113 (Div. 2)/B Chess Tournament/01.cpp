#include <cstdio>
#include <cstring>
const int maxn = 55;
char g[maxn][maxn];
bool used[maxn];   // 将满足条件的选手放进来
#define NEXTLINE puts("");

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        memset(g, 0, sizeof g);
        memset(used, 0, sizeof used);

        int n; scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            g[i][i] = 'X';

        char str[maxn]; scanf("%s", str);

        // 让期待为 '1' 的选手先比赛完且让其全部平局
        for (int i = 0; i < n; ++i)
            if (str[i] == '1') {
                for (int j = 0; j < n; ++j)
                    if (!g[i][j]) {
                        g[i][j] = '=';
                        g[j][i] = '=';
                    }
                used[i] = true;   // 这位选手满足期待
            }

        // 让期待为 '2' 的选手比赛，让他没比的场次中第一场胜，其余全输
        for (int i = 0; i < n; ++i) {
            if (used[i])
                for (int j = 0; j < n; ++j)
                    if (!g[i][j]) {
                        g[i][j] = '-';
                        g[j][i] = '+';
                        used[j] = true;
                    }

            if (str[i] == '2' && !used[i]) {
                // 找到第一个未进行的比赛，让他赢
                bool flag = false;
                for (int j = 0; j < n; ++j) {
                    if (!g[i][j] && !flag) {   // 第一场
                        g[i][j] = '+';
                        g[j][i] = '-';
                        flag = true;
                    }

                    if (!g[i][j] && flag) {   // 其余比赛
                        g[i][j] = '-';
                        g[j][i] = '+';
                        used[j] = true;   // 这位选手满足期待
                    }
                }
                if (!flag) {
                    printf("NO\n");
                    goto loop;
                }
                used[i] = true;   // 这位选手满足期待(这句没啥用，只是为了严谨)
            }
        }

        // 输出YES
        printf("YES\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                printf("%c", g[i][j]);
            NEXTLINE;
        }
loop: ;
    }
    return 0;
}
