/*----------------------------------------------------------------
 *
 *   文件名称：1009 Product of Polynomials.cpp
 *   创建日期：2020年08月24日 ---- 17时08分
 *   结束日期：2020年08月24日 ---- 18时08分
 *   题    目：Product of Polynomials
 *   算    法：散列
 *   描    述：输入：2 1 2.4 0 3.2
 *                   2 2 1.5 1 0.5
 *             (2.4x + 3.2)(1.5x^2 + 0.5x) = 3.6x^3 + 6.0x^2 + 1.6x
 *             输出：3 3 3.6 2 6.0 1 1.6
 *
----------------------------------------------------------------*/

#include <cstdio>

double polyA[1001];
double polyB[1001];
double polyC[2001];

int main()
{
    int k;
    scanf("%d", &k);
    while (k--) {
        int x;
        scanf("%d", &x);
        scanf("%lf", &polyA[x]);
    }

    scanf("%d", &k);
    while (k--) {
        int x;
        scanf("%d", &x);
        scanf("%lf", &polyB[x]);
    }

    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            if (polyA[i] != 0 && polyB[j] != 0)
                polyC[i + j] += polyA[i] * polyB[j];

    int cnt = 0;
    for (int i = 2001; i >= 0; i--)
        if (polyC[i] != 0)
            cnt++;

    printf("%d", cnt);
    for (int i = 2001; i >= 0; i--)
        if (polyC[i] != 0)
            printf(" %d %.1f", i, polyC[i]);

    printf("\n");
    return 0;
}
