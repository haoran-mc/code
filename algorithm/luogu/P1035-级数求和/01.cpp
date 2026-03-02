/***
*  创建日期：2022/04/08 Fri 03:00:04
*  题目来源：<++>
*  算    法：<++>
*  描    述：<++>
**/

#include <cstdio>

int main() {
    int k; scanf("%d", &k);
    int n = 1;
    double S = 1.0;
    while (S <= k) {
        n ++ ;
        S += (1.0 / n);
    }
    printf("%d\n", n);
    return 0;
}
