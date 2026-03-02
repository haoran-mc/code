#include <cstdio>
#include <map>
using namespace std;
const int maxn = 1e5 + 1;
int arr[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int oper;
        scanf("%d", &n);
        scanf("%d", &oper);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            mp[arr[i]]++;
        }

        while (oper--) {
            int judge;
            scanf("%d", &judge);
            if (judge == 1) {
                int p;
                int v;
                scanf("%d", &p);
                scanf("%d", &v);
                if (mp.find(arr[p-1]) != mp.end()) {
                    mp[arr[p-1]]--;
                    if (mp[arr[p-1]] == 0)
                        mp.erase(arr[p-1]);
                }
                arr[p-1] = v;
                mp[v]++;
            }
            else {
                if (mp.find(0) != mp.end())
                    printf("%d\n", (int)mp.size() - 1);
                else
                    printf("%d\n", (int)mp.size());
            }
        }
        mp.clear();
    }
    return 0;
}

