/*----------------------------------------------------------------
 *   
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：01.cpp
 *   创建日期：2021年07月31日 星期六 19时43分55秒
 *   结束日期：2021年07月31日 星期六 19时51分43秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 1e5 + 5;
int a[maxn];
int preS[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        preS[i] = preS[i-1] + a[i];
    int cnt = 0;
    /*
     * for (int i = 1; i <= n; ++i)
     *     printf("%d ", preS[i]);
     * NEXTLINE 
     */
    for (int i = 1; i < n; ++i) 
        if (preS[i] == preS[n] - preS[i]) 
            cnt++;
    printf("%d\n", cnt);
    return 0;
}
