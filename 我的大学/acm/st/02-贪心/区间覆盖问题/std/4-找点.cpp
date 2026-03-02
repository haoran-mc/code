#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct section {
    int left;
    int right;
} sect[maxn];

bool cmp(section sect1, section sect2) {
    return sect1.left == sect2.left ? sect1.right < sect2.right : sect1.left < sect2.left;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &sect[i].left, &sect[i].right);
        sort(sect, sect + n, cmp);
        int max_right = sect[0].right;
        int cnt = 1;
        int cul = 0;
        while (max_right < sect[n-1].right) {
            if (sect[cul+1].left > max_right)
                ++cnt;
            max_right = sect[cul+1].right;
            ++cul;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
