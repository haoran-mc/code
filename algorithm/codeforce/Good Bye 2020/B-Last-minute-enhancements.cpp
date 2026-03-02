#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int minu[maxn];
set<int> st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &minu[i]);
        sort(minu, minu+n);
        ++minu[n-1];
        int cnt = 1;
        for (int i = n-2; i >= 0; --i) {
            if (minu[i+1] == minu[i])
                continue;
            ++cnt;
            if (minu[i+1] == minu[i]+1)
                continue;
            ++minu[i];
        }
        printf("%d\n", cnt);
        memset(minu, 0, sizeof(minu));
        st.clear();
    }
    return 0;
}
