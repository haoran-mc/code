#include <cstdio>
#include <algorithm>
using namespace std;
#define NEXTLINE puts("");
const int maxn = 1e5 + 5;
struct Sect {int l, r;} sect[maxn];

bool cmp(Sect i1, Sect i2) {
    return i1.l <= i2.l;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &sect[i].l, &sect[i].r);
    sort(sect, sect + n, cmp);
    int cnt = 1;
    int r = sect[0].r;
    for (int i = 0; i < n-1; ++i) {
        if (sect[i+1].l <= r && sect[i+1].r > r)
            r = sect[i+1].r;
        if (sect[i+1].l > r) {
            r = sect[i+1].r;
            ++cnt;
        }
    }
    NEXTLINE;
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", sect[i].l, sect[i].r);
    // printf("%d\n", cnt);
    return 0;
}
