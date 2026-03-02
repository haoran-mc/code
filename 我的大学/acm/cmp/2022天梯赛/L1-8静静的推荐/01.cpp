#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
pair<int, bool> pa[maxn];
int score[maxn], idx = 0;

int main() {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        int sc1, sc2;
        scanf("%d %d", &sc1, &sc2);
        if (sc1 >= 175 && sc2 >= s) {  // 一定受到推荐
            res ++ ;
        }
        else if (sc1 >= 175)   // 可能受到推荐
            score[idx ++ ] = sc1;
    }
    sort(score, score + idx);
    for (int i = 0; i < idx; i ++ ) {
        pa[i].first = score[i];
        pa[i].second = false;    // 还未受到邀请
    }
    while (k -- ) {
        int la = -1;   // 上次被推荐的人分数
        for (int i = 0; i < idx; i ++ ) {
            // 当前批次还未开始推荐，这位同学没有受到推荐
            if (la == -1 && pa[i].second == false) {
                res ++ ;
                pa[i].second = true;
                la = pa[i].first;
            }
            else if (pa[i].second == false) {
                if (pa[i].first != la) {
                    pa[i].second = true;
                    res ++ ;
                    la = pa[i].first;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}