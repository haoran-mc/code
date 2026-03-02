#include <cstdio>
#include <unordered_set>
using namespace std;

const int maxn = 1e5 + 1;
const int count = 1e9 + 1;
int arr[maxn];
int Hash[count];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int opre;
        scanf("%d", &n);
        scanf("%d", &opre);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            Hash[arr[i]]++;
        }

        while (opre--) {
            int judge;
            scanf("%d", &judge);
            if (judge == 1) {
                int p;
                int v;
                scanf("%d", &p);
                scanf("%d", &v);
                Hash[arr[p-1]]--;
                arr[p-1] = v;
                Hash[v]++;
            }
            else {
                int ans = 0;;
                for (int i = 1; i < count; i++)
                    if (Hash[i] > 0)
                        ans++;

                printf("%d\n", ans);
            }
        }
        for (int i = 0; i < count; i++)
            Hash[i] = 0;
    }
    return 0;
}
