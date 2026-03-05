/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年06月01日 星期二 16时56分54秒
 *   题    目：AcWing 0759 格子染色
 *   算    法：区间合并，离散化
 *   描    述：题解
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;
ll cnt;

struct Node {
    int k, l, r;
    bool operator < (const Node& w) const {
        if (k != w.k) 
            return k < w.k;
        else if (l != w.l) 
            return l < w.l;
        else 
            return r < w.r;
    }
};

vector<Node> cols, rows;

void merge(vector<Node>& segs) {
    sort(segs.begin(), segs.end());
    vector<Node> res;
    int st = -2e9, ed = -2e9, k = -2e9;
    for (auto seg : segs) {
        if (seg.k == k) {
            if (ed < seg.l) {
                if (st != -2e9) {
                    res.push_back({k, st, ed});
                    cnt += ed - st + 1;
                }
                st = seg.l, ed = seg.r;
            }
            else
                ed = max(ed, seg.r);
        }
        else {
            if(st != -2e9) {
                res.push_back({k, st, ed});
                cnt += ed - st + 1;
            }
            k = seg.k, st = seg.l, ed = seg.r;
        }
    }

    if (st != -2e9) {
        res.push_back({k, st, ed});
        cnt += ed - st + 1;
    }
    segs = res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 == x2)
            cols.push_back({x1, min(y1, y2), max(y1, y2)});
        else
            rows.push_back({y1, min(x1, x2), max(x1, x2)});
    }

    merge(rows), merge(cols);

    for (auto row : rows)
        for (auto col : cols)
            if (row.k >= col.l && row.k <= col.r && row.r >= col.k  && row.l <= col.k)
                --cnt;

    printf("%lld\n", cnt);
    return 0;
}
