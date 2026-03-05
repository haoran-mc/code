#include <cstdio>
#include <utility>
#include <algorithm>
// #include <map>
using namespace std;
const int maxn = 2500 + 5;
PII cows[maxn];

int main() {
    int C, L; scanf("%d %d", &C, &L);
    for (int i = 0; i < C; ++i)
        scanf("%d %d", &cows[i].first, &cows[i].second);
    sort(cows, cows + n);
    map<PII> spfs;
    for (int i = 0; i < n; ++i) {
        int spf, cover;
        scanf("%d %d", &spf, &cover);
        spfs[spf] += cover;
    }
    int res = 0;
    for (int i = 0; i < C; ++i) {
        auto it = spfs.lower_bound(cows[i].first);
        if (it -> first <= cows[i].second && it -> second)
            ++res;
        if (-- it -> 
    }
    return 0;
}
