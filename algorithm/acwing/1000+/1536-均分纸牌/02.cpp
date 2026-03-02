/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年06月02日 星期三 10时40分19秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：虽说是用前缀和做的，但本质还是检查当前卡牌是否为平均数
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 100 + 5;
int card[maxn], preS[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &card[i]);
        preS[i] = preS[i-1] + card[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (preS[i] != preS[n] / n * i) { 
            ++res;
        }
    printf("%d\n", res);
    return 0;
}
