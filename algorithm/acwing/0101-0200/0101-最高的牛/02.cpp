#include <cstdio>
#include <utility>
#include <set>
using namespace std;
const int maxn = 1e4 + 5;
int height[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    int N, P, H, M;
    scanf("%d %d %d %d", &N, &P, &H, &M);
    height[1] = H;  //这样意味着整个数组都是H
    set<pair<int, int>> st;
    for (int i = 0, l, r; i < M; ++i) {
        scanf("%d %d", &l, &r);
        if (l > r)
            swap(l, r);
        if (!st.count({l, r})) {
            st.insert({l, r});
            --height[l + 1], ++height[r];
        }
    }
    for (int i = 1; i <= N; ++i) {
        height[i] += height[i-1];
        printf("%d\n", height[i]);
    }
    return 0;
}
