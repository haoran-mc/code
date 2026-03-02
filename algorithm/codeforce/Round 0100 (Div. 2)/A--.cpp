#include <cstdio>
#include <algorithm>
using namespace std;
#define bug printf("<------>\n");
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int mons[3];
        for (int i = 0; i < 3; ++i) {
            scanf("%d", &mons[i]);
        }
        sort(mons, mons+3);
        int dem = mons[2] - mons[0];
        dem += mons[1] - mons[0];
        if (dem % 6 != 0 && dem % 6 != 3) {
            printf("NO\n");
            continue;
        }
        if (dem % 6 == 3) {
            dem -= 3;
            --mons[0];
            --mons[0];
        }
        mons[0] -= dem / 6;
        if (mons[0] < 0) {
            printf("NO\n");
            continue;
        }
        if (mons[0] % 3 == 0) {
            printf("YES\n");
            continue;
        }
        else{
            printf("NO\n");
            continue;
        }
        if (mons[0] % 3 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
