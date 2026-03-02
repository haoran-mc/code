#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1005;
struct Pos {
    double left;
    double right;
} pos[maxn];

bool cmp(Pos pos1, Pos pos2) {
    return pos1.left < pos2.left;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    int d;
    int t = 0;
    while (scanf("%d %d", &n, &d) && (n | d)) {
        int res = 1;
        int cul = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            int y;
            scanf("%d", &x);
            scanf("%d", &y);
            if (d < y) {
                res = -1;
                continue;
            }
            pos[cul].left = 1.0*x - sqrt(1.0*d*d - 1.0*y*y);
            pos[cul++].right = 1.0*x + sqrt(1.0*d*d - 1.0*y*y);
        }
        sort(pos, pos + n, cmp);
        double max_right = pos[0].right;
        for (int i = 0; i < n-1 && res != -1; ++i) {
            if (pos[i+1].left > max_right)
                ++res,
                max_right = pos[i+1].right;
            else if (pos[i+1].right < max_right)
                max_right = pos[i+1].right;
        }
        printf("Case %d: %d\n", ++t, res);
    }
    return 0;
}
