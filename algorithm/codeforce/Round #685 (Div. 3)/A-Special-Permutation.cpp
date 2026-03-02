/*----------------------------------------------------------------
 *
 *   文件名称：A-Special-Permutation.cpp
 *   创建日期：2020年11月24日 ---- 22时52分
 *   题    目：codeforce
 *   算    法：没有
 *   描    述：就是最后输出1就是了
 *
----------------------------------------------------------------*/

#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n-1; ++i)
            printf("%d ", i+2);
        printf("1\n");
    }
    return 0;
}
