/*----------------------------------------------------------------
 *
 *   文件名称：B2.cpp
 *   创建日期：2020年09月20日 ---- 21时40分
 *   题    目：nowcoder
 *   算    法：打表后总结
 *   描    述：打表后观察规律
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        int y;
        scanf("%d", &x);
        scanf("%d", &y);
        if (abs(x - y) % 3 != 0)
            printf("yyds\n");
        else
            printf("awsl\n");
    }
    return 0;
}
