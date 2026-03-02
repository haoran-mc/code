/***
*  创建日期：2022/04/08 Fri 02:21:56
*  题目来源：<++>
*  算    法：<++>
*  描    述：<++>
**/

#include <cstdio>

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int rem = 0, store = 0;
    for (int i = 1; i <= 12; i ++ ) {
        int overhead; scanf("%d", &overhead);
        rem += 300;
        if (rem < overhead) {
            store = -i;   // 负数
            break;
        }
        else {
            rem -= overhead;
            store += (rem / 100) * 100;
            rem %= 100;
        }
    }
    if (store < 0)
        printf("%d\n", store);
    else
        printf("%d\n", (int)(1.2 * store) + rem);
    return 0;
}
