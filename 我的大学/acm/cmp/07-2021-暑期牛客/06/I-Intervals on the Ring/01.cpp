#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 2010;
pair<int, int> a[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d %d", &a[i].first, a[i].second);
        sort(a, a + m);
        printf("%d\n", m);
        for (int i = 0; i < m; ++i)
            printf("%d %d\n", a[i].first, a[(m + i - 1) % m].second);
    }
    return 0;
}

