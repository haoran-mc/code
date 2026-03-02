#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 55;
int pos[maxn];
set<int> st;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &pos[i]);
        sort(pos, pos + n);
        for (int i = 0; i < n-1; ++i)
            for (int j = i+1; j < n; ++j)
                st.insert(pos[j] - pos[i]);
        printf("%d\n", (int)st.size());
        st.clear();
    }
    return 0;
}
