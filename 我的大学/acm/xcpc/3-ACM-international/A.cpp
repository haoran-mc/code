#include <cstdio>
#include <unordered_set>
using namespace std;

const int maxn = 1e6;
int arr[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int opre;
        scanf("%d", &n);
        scanf("%d", &opre);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        while (opre--) {
            int judge;
            scanf("%d", &judge);
            if (judge == 1) {
                int p;
                int v;
                scanf("%d", &p);
                scanf("%d", &v);
                arr[p - 1] = v;
            }
            else {
                unordered_set<int> st;
                for (int i = 0; i < n; i++)
                    if (arr[i] != 0)
                        st.insert(arr[i]);
                printf("%d\n", (int)st.size());
            }
        }
    }
    return 0;
}
