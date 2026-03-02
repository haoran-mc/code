/***
*  创建日期：2022/04/08 Fri 02:11:55
*  题目来源：<++>
*  算    法：<++>
*  描    述：<++>
**/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int a[3], b[3], c[3];
    for (int i = 0; i < 3; i ++ ) {
        scanf("%d %d", &a[i], &b[i]);
        c[i] = n / a[i];
        if (n % a[i])
            c[i] ++ ;
        c[i] = c[i] * b[i];
    }
    sort(c, c + 3);
    printf("%d\n", c[0]);
    return 0;
}
