#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
struct info {
    int x;
    int r;
    int left;
    int right;
} water[maxn];

bool cmp(info water1, info water2) {
    return water1.left == water2.left ? water1.right < water2.right : water1.left < water2.left;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int w;
        int h;
        scanf("%d", &n);
        scanf("%d", &w);
        scanf("%d", &h);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &water[i].x, &water[i].r);
            double len = water[i].r * water[i].r - h * h / 4;
            if (len <= 0)
                continue;
            len = sqrt(len);
            water[i].left  = water[i].x - len;
            water[i].right = water[i].x - len;
        }
        sort(water, water + n, cmp);
        if (water[0].left > 0) {
            printf("0");
            break;
        }
        int cul = 0;
        int max_right = 0;
        bool flag;
        int cnt = 0;
        while (max_right < w) {
            flag = false;
            int i = cul + 1;
            while (water[i].left <= max_right)
                ++i,
                flag = true;
            cul = --i;
            max_right = water[cul].right;
            if (!flag) break;
            ++cnt;
        }
        flag ? printf("%d\n", cnt) : printf("0\n");
    }
    return 0;
}
