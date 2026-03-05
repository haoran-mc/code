#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll cnt;
const int INF = 0x3f3f3f3f;

struct Segs {
    //k: 存储的是当前是第几列，如果是行，就是第几行
    int k, l, r;
    bool operator < (const Segs &seg) const {
        if (k != seg.k)
            return k < seg.k;
        else if (l != seg.l)
            return l < seg.l;
        else
            return r < seg.r;
    }
};

vector<Segs> rows, cols;

void merge(vector<Segs> &segs) {
    sort(segs.begin(), segs.end());
    vector<Segs> res;
    segs.push_back({INF, INF});
    int k = segs[0].k,
        st = segs[0].l,
        ed = segs[0].r;
    for (auto seg : segs) {
        if (seg.k > k || ed < seg.l) {
            res.push_back({k, st, ed});
            cnt += ed - st + 1;
            k = seg.k, st = seg.l, ed = seg.r;
        }
        else
            ed = max(ed, seg.r);
    }
    segs = res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 == x2)
            rows.push_back({x1, min(y1, y2), max(y1, y2)});
        else
            cols.push_back({y1, min(x1, x2), max(x1, x2)});
    }

    merge(rows), merge(cols);

    for (auto row : rows)
        for (auto col : cols)
            if ((row.k >= col.l && row.k <= col.r) && (col.k >= row.l && col.k <= row.r))
                --cnt;
    printf("%lld\n", cnt);
    return 0;
}
