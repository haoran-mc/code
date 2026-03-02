#include <cstdio>
const int maxn = 1e5 + 5;
int t[maxn];   // 煎汉堡牛排需要的时间

struct Res {
    int k;
    int id;
    int l1, r1;
    int l2, r2;
};

Res res[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    return 0;
}
