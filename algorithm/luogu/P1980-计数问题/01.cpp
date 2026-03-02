/***
 *  创建日期：2022/04/08 Fri 03:02:44
 *  题目来源：Luogu P1980 计数问题
 *  算    法：<++>
 *  描    述：<++>
 **/

#include <cstdio>
#include <cmath>
int h[10], l[10], m[10];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int tmp = n;
    for (int i = 0; tmp; i ++ ) {
        m[i] = tmp % 10;
        tmp /= 10;
        h[i] = tmp;
        if (i > 0)
            l[i] = m[i - 1] * pow(10, i - 1) + l[i - 1];
        // printf("%d %d %d %d\n", i, h[i], m[i], l[i]);
    }
    int cnt = 0;
    for (int i = 0; n; i ++ ) {
        n /= 10;
        if (m[i] < x) {
            cnt += h[i] * pow(10, i);
            printf("1: \n");
        }
        else if (m[i] == x) {
            cnt += h[i] * pow(10, i) + (l[i] + 1);
            printf("2: %d\n", cnt);
        }
        else {
            cnt += (h[i] + 1) * pow(10, i);
            printf("3: %d\n", cnt);
        }
    }
    if (!x) {
        cnt -- ;
    }
    printf("%d\n", cnt);
    return 0;
}
