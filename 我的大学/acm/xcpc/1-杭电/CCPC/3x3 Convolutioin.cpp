/*----------------------------------------------------------------
 *
 *   文件名称：3x3 Convolutioin.cpp
 *   创建日期：2020年09月20日 ---- 14时04分
 *   题    目：poj
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ill;
int A[51][51];
int K1[4][4];
ill C[51][51];
double K2[4][4];

bool judge(int n) {
    bool flag = true;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (!(i == 0 && j == 0))
                if (K1[i][j] != 0)
                    flag = false;

    return flag;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        /*输入A*/
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &A[i][j]);

        /*输入K'*/
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                scanf("%d", &K1[i][j]);

        if (K1[1][1] == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("0 ");
                }
                printf("\n");
            }
        }
        else if (judge(n) == true) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", A[i][j]);
                }
                printf("\n");
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("0 ");
                }
                printf("\n");
            }
        }
/*
 *        [>K'总和<]
 *        int sum = 0;
 *        for (int i = 1; i <= 3; i++)
 *            for (int j = 1; j <= 3; j++)
 *                sum += K1[i][j];
 *
 *        [>求出K<]
 *        for (int i = 1; i <= 3; i++)
 *            for (int j = 1; j <= 3; j++)
 *                K2[i][j] = (double)K1[i][j] / (double)sum;
 *
 *        [>求出C1<]
 *        for (int x = 1; x <= n; x++)
 *            for (int y = 1; y <= n; y++)
 *                for (int i = 1; i <= min(n-x+1, 3); i++)
 *                    for (int j = 1; j <= min(n-y+1, 3); j++)
 *                        C[x][y] += A[x+i-1][y+j-1] * K2[i][j];
 */

        /*
         *for (int i = 1; i <= 3; i++) {
         *    for (int j = 1; j <= 3; j++) {
         *        printf("%d ", K1[i][j]);
         *    }
         *    printf("\n");
         *}
         *for (int i = 1; i <= 3; i++) {
         *    for (int j = 1; j <= 3; j++) {
         *        printf("%lf ", K2[i][j]);
         *    }
         *    printf("\n");
         *}
         *[>输出C1<]
         *for (int i = 1; i <= n; i++) {
         *    for (int j = 1; j <= n; j++) {
         *        printf("%lld ", C[i][j]);
         *    }
         *    printf("\n");
         *}
         */
    }
    return 0;
}
