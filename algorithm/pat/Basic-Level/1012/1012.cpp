/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1012.cpp
 *   创建日期：2020年10月19日 ---- 23时57分
 *   结束日期：2020年10月20日 ---- 00时10分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    int sum0 = 0;
    int sum1 = 0;
    int flag1 = 0;
    bool flag = false;
    int num2 = 0;
    int sum3 = 0;
    int num3 = 0;
    int max4 = -1;
    while (N--) {
        int num;
        scanf("%d", &num);
        switch(num % 5) {
            case 0:
                if (num % 2 == 0)
                    sum0 += num;
                break;
            case 1:
                flag = true;
                if (flag1 == 0) {
                    sum1 += num;
                    flag1 = 1;
                    break;
                }
                else {
                    sum1 -= num;
                    flag1 = 0;
                    break;
                }
            case 2:
                num2++;
                break;
            case 3:
                sum3 += num;
                num3++;
                break;
            case 4:
                if (num > max4)
                    max4 = num;
                break;
        }
    }
    if (sum0 == 0)
        printf("N ");
    else
        printf("%d ", sum0);

    if (flag == false)
        printf("N ");
    else
        printf("%d ", sum1);

    if (num2 == 0)
        printf("N ");
    else
        printf("%d ", num2);

    if (num3 == 0)
        printf("N ");
    else
        printf("%.1f ", (double)sum3 / (double)num3);

    if (max4 == -1)
        printf("N");
    else
        printf("%d", max4);

    return 0;
}
