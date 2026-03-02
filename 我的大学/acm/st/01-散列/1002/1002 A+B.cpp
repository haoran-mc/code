/*----------------------------------------------------------------
 *
 *   文件名称：1002 A+B.cpp
 *   创建日期：2020年08月10日
 *   题    目：A+B
 *   描    述：使用map没有求得结果，使用数组直接定址法。
 *   疑    问：搞不懂，为什么输出需要倒序输出，而且只需要一位小数就可以了
 *
----------------------------------------------------------------*/

#include <cstdio>

const int N = 1001;
double A[N];
double B[N];
double C[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int nk; double Ak;
        scanf("%d", &nk);
        scanf("%lf", &Ak);
        A[nk] = Ak;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int nk; double Bk;
        scanf("%d", &nk);
        scanf("%lf", &Bk);
        B[nk] = Bk;
    }

    int sum = 0;
    for (int i = 0; i <= 1000; i++) {
        C[i] = A[i] + B[i];

        if (C[i])
            sum++;
    }
    printf("%d", sum);
    for (int i = 1000; i >= 0; i--) {
        if (C[i])
            printf(" %d %.1f", i, C[i]);
    }
    return 0;
}

