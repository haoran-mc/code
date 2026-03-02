/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年04月01日 ---- 17时08分
 *   题    目：poj3250 bad hair day
 *   算    法：单调栈
 *   描    述：如果来了一个个高的，那就--top直到前面那个是比自己高
 *      一点的(top代表的是当前的能够被几只牛看得见)，因为夹在他们
 *      之间的那群牛往后都看不见新加入的了，如果来了一只个矮的，那就
 *      ++top，表示这个新牛能够被++top只牛看得见
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 80005;
int stk[maxn];
int top;

int main() {
    int n;
    scanf("%d", &n);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int high;
        scanf("%d", &high);
        while (top > 0 && high >= stk[top-1])
            --top;
        res += top;
        stk[top++] = high;
    }
    printf("%lld\n", res);
    return 0;
}
