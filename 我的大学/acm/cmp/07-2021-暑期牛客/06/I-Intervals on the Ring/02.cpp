#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 2010;
pair<int, int> in[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d %d", &in[i].first, &in[i].second);
        sort(in, in + m);
        printf("%d\n", m);
        for (int i = 0; i < m; ++i)
            printf("%d %d\n", in[i].first, in[(m + i - 1) % m].second);
    }
    return 0;
}

