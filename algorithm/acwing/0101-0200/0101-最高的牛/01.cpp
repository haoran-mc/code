#include <cstdio>
#include <utility>
#include <map>
using namespace std;
const int maxn = 1e4 + 5;
int diff[maxn];
map<pair<int, int>, bool> mp;

int main() {
    freopen("in.txt", "r", stdin);
    //一共有N头牛，最高的是第P头，高H，下面有M组能互相看见的牛
    int N, P, H, M;
    scanf("%d %d %d %d", &N, &P, &H, &M);
    for (int i = 0; i < M; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        if (mp[make_pair(l, r)])
            continue;
        mp[make_pair(l, r)] = true;
        if (l >= r - 1)
            continue;
        --diff[l + 1];
        ++diff[r];
    }
    int idx = diff[P-1];
    diff[0] -= idx;
    for (int i = 1; i < N; ++i)
        diff[i] = diff[i] + diff[i-1] - idx;
    for (int i = 0; i < N; ++i)
        printf("%d\n", H + diff[i]);
    return 0;
}
