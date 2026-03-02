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
        int monster[3];
        for (int i = 0; i < 3; ++i) {
            scanf("%d", &monster[i]);
        }
        sort(monster, monster+3);
        int dem = monster[2] - monster[0];
        dem += monster[1] - monster[0];
        if (dem % 6 != 3 && dem % 6 != 0)
            printf("NO\n");
        else if (dem % 6 == 3) {
            if ((monster[0] - 1) % 3 == 2)
                printf("YES\n");
        }
        else {
            if (dem != 0 && monster[0] % 3 == 1)
                printf("YES\n");
            else if (dem == 0 && monster[0] % 3 == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
