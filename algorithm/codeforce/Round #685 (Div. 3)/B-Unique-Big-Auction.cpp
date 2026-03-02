/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：B-Unique-Big-Auction.cpp
 *   创建日期：2020年11月24日 ---- 23时01分
 *   题    目：codeforce
 *   算    法：散列
 *   描    述：就散列
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 2e5+1;
#define bug printf("<------>\n");
int arr[maxn];
int hash[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(hash, 0, sizeof(hash));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        for (int i = 0; i < n; ++i) {
            if (hash[arr[i]])
                hash[arr[i]] = -2;
            else
                hash[arr[i]] = i+1;
        }
        bool flag = false;
        for (int i = 1; i < maxn && !flag; ++i)
            if (hash[i] && hash[i] != -2) {
                flag = true;
                printf("%d\n", hash[i]);
            }
        if (!flag) printf("-1\n");
    }
    return 0;
}
