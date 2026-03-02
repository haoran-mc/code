/*----------------------------------------------------------------
 *
 *   文件名称：B--.cpp
 *   创建日期：2020年11月17日 ---- 23时53分
 *   题    目：codeforce
 *   算    法：贪心
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int k;
        scanf("%d", &n);
        scanf("%d", &k);
        int median = 1;
        int sum = 0;
        int j = 1;
        for (int i = 1; i <= n * k; ++i) {
            int num;
            scanf("%d", &num);
            if (i > n*k-(n-n/2)*k) {
                if (j % (n-n/2) == 1)
                    median = 1;
                if (median == 1)
                    sum += num;
                ++median;
                ++j;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
