#include <cstdio>
int n, m;
const int maxn = 1e6 + 5;
int suger[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &suger[i]);
    for (int i = 1; i <= m; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        if (suger[ver1] > suger[ver2])
            suger[ver2] = suger[ver1];
        else
            suger[ver1] = suger[ver2];
    }
    int purchase = 0;
    for (int i = 1; i <= n; ++i) {
        purchase += suger[i];
    }
    printf("%d\n", purchase);
    return 0;
}
