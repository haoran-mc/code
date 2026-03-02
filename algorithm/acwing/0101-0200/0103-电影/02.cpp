#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a, b, c;
vector<int> alls;
const int maxn = 2e5 + 5;
int h[3 * maxn];
#define bug printf("<-->\n");

int find(int x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}

/*
 * a中存储的是各个科学家会的语言[1, 1e9]
 * b中存储的是电影中的语音语言[1, 1e9]
 * c中存储的是电影中的字幕语言[1, 1e9]
 * alls中存储的上述三者的所有语言，并且排序，去重，alls只用于离散化(也就是find函数)，不用于其他
 * 这样我们就把这些电影语言给离散化了
 */
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int _;
        scanf("%d", &_);
        a.push_back(_);
        alls.push_back(_);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int _;
        scanf("%d", &_);
        b.push_back(_);
        alls.push_back(_);
    }
    for (int i = 0; i < m; ++i) {
        int _;
        scanf("%d", &_);
        c.push_back(_);
        alls.push_back(_);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (int i = 0; i < a.size(); ++i)
        h[find(a[i])]++;

    int res = 0;
    int max_b = 0, max_c = 0;
    for (int i = 0; i < m; ++i) {
        int cnt_b = h[find(b[i])];
        int cnt_c = h[find(c[i])];
        if (cnt_b > max_b || (cnt_b == max_b && cnt_c > max_c)) {
            res = i + 1;
            max_b = cnt_b;
            max_c = cnt_c;
        }
    }
    printf("%d\n", res);
    return 0;
}
