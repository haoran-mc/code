#include <cstdio>
const int maxn = 1e5+5;
int permu[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        int order = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &permu[i]);
            if (i && permu[i] == i+1)
                ++order;
            else if (i)
                order = 0;
        }
        int disorder = n - order;
        /*printf("%d\n", disorder);*/
        double mult = 1;
        for (int i = 0; i < m; ++i) {
            int cnt;
            double prob;
            scanf("%d", &cnt);
            scanf("%lf", &prob);
            if (cnt >= disorder)
                mult *= (1 - prob);
        }
        if (disorder == 0) {
            printf("1.000000\n");
            continue;
        }
        printf("%f\n", 1 - mult);
    }
    return 0;
}
