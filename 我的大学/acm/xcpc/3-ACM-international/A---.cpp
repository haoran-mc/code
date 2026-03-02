#include <cstdio>
#include <unordered_set>
using namespace std;

const int maxn = 1e6;
const int count = 1e9;
int arr[maxn];
bool Hash[count] = {false};

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
                int ans = 0;
                for (int i = 0; i < n; i++) {
                    if (Hash[arr[i]] == false && arr[i] != 0) {
                        ans++;
                        Hash[arr[i]] = true;
                    }
                    else
                        Hash[arr[i]] = true;
                }
                printf("%d\n", ans);
                for (int i = 0; i < 1e9; i++)
                    Hash[i] = 0;
            }
        }
    }
    return 0;
}

