/*----------------------------------------------------------------
 *
 *   文件名称：1027.cpp
 *   创建日期：2020年11月07日 ---- 17时02分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
int rows(int n) {
    int row = 1;
    while (row*(2*row-1)+row-1 <= n)
        ++row;
    return --row;
}
int main()
{
    int num;
    char ch;
    scanf("%d", &num);
    getchar();
    scanf("%c", &ch);
    int row = rows(num);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < i; ++j)
            printf(" ");
        for (int j = 0; j < 2*row-1-2*i; ++j)
            printf("%c", ch);
        printf("\n");
    }
    for (int i = 0; i < row-1; ++i) {
        for (int j = 0; j < row-i-2; ++j)
            printf(" ");
        for (int j = 0; j < 2*(i+1)+1; ++j)
            printf("%c", ch);
        printf("\n");
    }
    //if (num-row*(2*row-1)-row+1)
        printf("%d\n", num-row*(2*row-1)-row+1);
    return 0;
}
