#include <cstdio>
#include <map>
#include <vector>
using namespace std;
map<int, int> mp;
const int maxn = 2e5 + 5;
int lan[maxn], sum[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int lan;
        scanf("%d", &lan);
        mp[lan]++;
    }
    int N_lan = 0;
    for (auto it : mp) {
        lan[N_lan++] = it.first;
        sum[N_lan-1] = it.second;
    }
    int m;
    scanf("%d", &m);
    int res_most = 0, res_more = 0, res;
    while (m--) {
        int voice, title;
        scanf("%d %d", voice, title);
        int idx_most = find(voice);
        int idx_more = find(title);
        int most = sum[idx_most];
        int more = sum[idx_more];
        if (most > 
    }
    return 0;
}
