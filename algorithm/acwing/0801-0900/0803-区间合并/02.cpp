/*----------------------------------------------------------------
 *
 *   文件名称：02.cpp
 *   创建日期：2021年06月01日 星期二 15时22分04秒
 *   题    目：AcWing 0803 区间合并
 *   算    法：贪心
 *   描    述：视频
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 1e5 + 5;
int n;
vector<PII> segs;  //pair在C++中优先以左端点排序
// segment, section,

void merge(vector<PII> &segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs) { 
        if (ed < seg.first) {
            if (st != -2e9)
                res.push_back({st, ed});
            st = seg.first,
               ed = seg.second;
        }
        else
            ed = max(ed, seg.second);
    }

    if (st != -2e9)
        res.push_back({st, ed});
    segs = res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);
    printf("%d\n", (int)segs.size());
    return 0;
}
