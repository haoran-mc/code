/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年11月06日 ---- 20时14分
 *   题    目：newcoder
 *   算    法：贪心
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 2e6+1;
int arr[2][maxn];
int main()
{
    /*
     *freopen("in.txt", "r", stdin);
     *freopen("out.txt", "w", stdout);
     */
    int n;
    int k;
    int q;
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[0][i]);
        if (i == 0)
            arr[1][i] = 1;
        else if (arr[0][i] == arr[0][i-1])
            arr[1][i] = arr[1][i-1];
        else if (arr[0][i] != arr[0][i-1])
            arr[1][i] = arr[1][i-1] + 1;
    }
    while (q--) {
        int L;
        int R;
        scanf("%d", &L);
        scanf("%d", &R);
        /*
         *printf("%d ", R);
         *printf("%d ", L);
         *printf("%d ", arr[1][R]);
         *printf("%d ", arr[1][L]);
         *printf("%d ", arr[1][R]-arr[1][L]+1);
         */
        if (arr[1][R] - arr[1][L] + 1 >= k)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
