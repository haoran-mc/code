/*----------------------------------------------------------------
 *   
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月25日 星期三 00时02分45秒
 *   结束日期：2021年08月25日 星期三 00时02分46秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define NEXTLINE puts("");

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int a, b;
        scanf("%d %d", &a, &b);
        int n = a + b;
        if (n & 1) {
            int less = abs(max(a, b) - (n / 2 + 1));
            int more = n - (max(a, b) - (n / 2 + 1));
            int m = more - less + 1;
            printf("%d\n", m);
            for (int i = less; i <= more; ++i)
                printf("%d ", i);
            NEXTLINE;
        }
        else {
            int less = max(a, b) - n / 2;
            int more = n - (max(a, b) - n / 2);
            int m = (more - less) / 2 + 1;
            printf("%d\n", m);
            for (int i = less; i <= more; i += 2)
                printf("%d ", i);
            NEXTLINE;
        }
    }
    return 0;
}
