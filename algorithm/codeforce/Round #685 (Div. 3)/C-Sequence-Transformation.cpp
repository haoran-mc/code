/*----------------------------------------------------------------
 *
 *   文件名称：C-Sequence-Transformation.cpp
 *   创建日期：2020年11月24日 ---- 23时20分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 2e5;
const int inf = 0x3f3f3f3f;
#define bug printf("<------>\n");
int sequ[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(sequ, 0, sizeof(sequ));
        int n;
        scanf("%d", &n);
        int minr = inf;
        int maxr = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &sequ[i]);
            minr = std::min(minr, sequ[i]);
            maxr = std::max(maxr, sequ[i]);
        }
        int mincnt = inf;
        for (int i = minr; i <= maxr; ++i) {
            int cnt = 0;
            ++cnt;
            if (sequ[0] == i)
                --cnt;
            if (sequ[n-1] == i)
                --cnt;
            for (int j = 0; j < n; ++j) {
                if (sequ[j] == i) {
                    ++cnt;
                    while (sequ[j] == i)
                        ++j;
                    --j;
                }
            }
            mincnt = std::min(mincnt, cnt);
        }
        printf("%d\n", mincnt);
    }
    return 0;
}
