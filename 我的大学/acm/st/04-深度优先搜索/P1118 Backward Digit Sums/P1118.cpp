/*----------------------------------------------------------------
 *
 *   文件名称：P1118.cpp
 *   创建日期：2020年09月15日 ---- 17时22分
 *   题    目：luogu
 *   算    法：STL
 *   描    述：这个sort函数震惊到我了
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int A, int B) {
    return A > B;
}

int main()
{
    int n;
    int sum1;
    scanf("%d", &n);
    scanf("%d", &sum1);

    int triangle[12];
    triangle[0] = triangle[n - 1] = 1;
    for (int i = 1; 2 * i <= n; i++)
        triangle[i] = triangle[n-i-1] = (n - i) * triangle[i-1] / i;

    int num[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int sum2;
    do {
        sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum2 += triangle[i] * num[i];
            if (sum2 > sum1) {
                //这tm太强了
                sort(num + i, num + n, cmp);
                break;
            }
            if (i == n - 1 && sum2 == sum1) {
                for (int i = 0; i < n; i++)
                    printf("%d ", num[i]);
                return 0;
            }
        }
    } while(next_permutation(num, num + n) != false);

    return 0;
}
