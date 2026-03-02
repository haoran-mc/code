#include <cstdio>
#include <unordered_set>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            st.insert(num);
        }
        int ans = 0;
        for (auto it = st.begin(); it != st.end(); it++) {
            if (st.find(*it + 1) != st.end())
                ans++;
            //if (st.find(*it - 1) != st.end())
                //ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
