/***
*  创建日期：2022/04/08 Fri 02:06:24
*  题目来源：Luogu P1421 小玉买文具
*  算    法：<++>
*  描    述：<++>
**/

#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a * 10 + b;
    printf("%d\n", c / 19);
    return 0;
}
