/*----------------------------------------------------------------
 *
 *   文件名称：02.cpp
 *   创建日期：2021年06月04日 星期五 11时00分39秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：视频代码
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 2500 + 5;
PII cows[maxn];

int main() {
    int C, L; scanf("%d %d", &C, &L);
    for (int i = 0; i < C; ++i)
        scanf("%d %d", &cows[i].first, &cows[i].second);

    sort(cows, cows + C);
    map<int, int> spfs;
    for (int i = 0; i < L; ++i) {
        int spf, cover;
        scanf("%d %d", &spf, &cover);
        spfs[spf] += cover;
    }

    int res = 0;
    spfs[0] = spfs[1001] = C;
    for (int i = C - 1; i >= 0; --i) {
        auto cow = cows[i];
        auto it = spfs.upper_bound(cow.second);
        --it;
        if (it -> first >= cow.first && it -> first <= cow.second) {
            ++res;
            if ( -- it -> second == 0)
                spfs.erase(it);
        }
    }
    printf("%d\n", res);
    return 0;
}
