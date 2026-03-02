/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年11月21日 ---- 22时51分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int num;
        scanf("%d", &num);
        int step = 0;
        if (num == 1) {
            printf("0\n");
            continue;
        }
        if (num & 1)
            ++step, --num;
        if (num != 2)
            ++step;
        ++step;
        printf("%d\n", step);
    }
    return 0;
}
