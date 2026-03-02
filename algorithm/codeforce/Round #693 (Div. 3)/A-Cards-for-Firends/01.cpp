#include <cstdio>
#define bug printf("<-->\n");
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", w, stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int w, h, n;
        scanf("%d %d %d", &w, &h, &n);
        int i, j;
        i = j = 1;
        while (!(w % 2)) {
            w /= 2;
            i *= 2;
        }
        while (!(h % 2)) {
            h /= 2;
            j *= 2;
        }
        printf(i * j >= n ? "YES\n" : "NO\n");

    }
    return 0;
}
