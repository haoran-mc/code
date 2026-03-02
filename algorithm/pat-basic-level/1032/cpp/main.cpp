#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 1e5 + 5;

map<int, int> mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int id, score;
        scanf("%d %d", &id, &score);
        mp[id] += score;
    }

    int max_id = 0, max_score = -1;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > max_score) {
            max_id = max(max_id, it->first);
            max_score = max(max_score, it->second);
        }
    }
    printf("%d %d\n", max_id, max_score);
    return 0;
}
