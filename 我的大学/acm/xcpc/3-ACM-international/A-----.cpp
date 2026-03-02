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
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        bool flag = false;
        int record;
        while (oper--) {
            int judge;
            scanf("%d", &judge);
            if (judge == 1) {
                int p;
                int v;
                scanf("%d", &p);
                scanf("%d", &v);
                arr[p-1] = v;
                flag = false;
            }
            else if (judge == 2 && flag == false) {
                map<int, int> mp;
                for (int i = 0; i < n; i++)
                    if (arr[i] != 0)
                        mp[arr[i]]++;

                printf("%d\n", (int)mp.size());
                record = (int)mp.size();
                flag = true;
            }
            else if (judge == 2 && flag == true) {
                printf("%d\n", record);
            }
        }
    }
    return 0;
}
