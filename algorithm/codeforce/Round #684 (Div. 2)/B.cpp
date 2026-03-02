/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年11月17日 ---- 23时24分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#define bug printf("******\n");
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
        int median;
        int num;
        int sum = 0;
        for (int i = 1; i <= n * k; ++i, ++median) {
            scanf("%d", &num);
            if (i % n == 1)
                median = 1;
            if ((n & 1) && (median == n / 2 + 1)) {
                sum += num;
                printf("num = %d\n", num);
            }
            else if ((!(n & 1)) && (median == n / 2))
                sum += num;
        }
        printf("%d\n", sum);
    }
    return 0;
}
