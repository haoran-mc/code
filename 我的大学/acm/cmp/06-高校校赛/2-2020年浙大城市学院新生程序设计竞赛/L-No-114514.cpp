#include <cstdio>
const int maxn = 2e5 + 5;
#define bug printf("<------>\n");
int sequ[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &sequ[i]);
    int hate[6] = {1, 1, 4, 5, 1, 4};
    for (int i = 0; i < n-5; ++i) {
        bool flag = false;
        for (int j = 0; j < 6; ++j)
            if (sequ[i+j] != hate[j]) {
                flag = true;
                break;
            }
        if (!flag) {
            i += 5;
            sequ[i] = 5;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", sequ[i]);
    return 0;
}
