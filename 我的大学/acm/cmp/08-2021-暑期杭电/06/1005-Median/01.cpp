#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
#define bug printf("<-->\n");
#define NEXTLINE puts("");
int ha[maxn];
int qa[maxn], qb[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        memset(ha, 0, sizeof ha);
        int hha = 0, tta = 0;
        int hhb = 0, ttb = 0;
        int n, m; 
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int b; scanf("%d", &b);
            ha[b] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (ha[i])
                qb[ttb++] = i;
            else
                qa[tta++] = i;
        }
        while (1) {
            if (hha >= tta) {    // 如果非b元素弹出完，一定可以
                printf("YES\n");
                break;
            }
            if (hhb >= ttb && hha < tta) {   // b中元素弹出完，而非b元素还有，失败
                printf("NO\n");
                break;
            }
            if (qa[hha] > qb[hhb]) {   // 上面判断条件筛选，队列一定不空
                hha++;
                hhb++;
            }
            else if (qa[hha] < qb[hhb]) {   // 如果最前面的b元素还有a元素
                int cnt = 0;   // 记录有几个
                bool flag = true;
                while (qa[hha] < qb[hhb] && hha < tta) {   // 一直弹
                    cnt++;
                    hha++;
                }
                ++hhb;
                while (cnt--) {
                    if (hha >= tta) {
                        flag = false;
                        break;
                    }
                    ++hha;
                }
                if (hha < tta)
                    ++hha;
                if (!flag) {
                    printf("NO\n");
                    break;
                }
            }
        }
    }
    return 0;
}
