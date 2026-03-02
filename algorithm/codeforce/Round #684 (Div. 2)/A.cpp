/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年11月17日 ---- 22时46分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int c0;
        int c1;
        int h;
        scanf("%d", &n);
        scanf("%d", &c0);
        scanf("%d", &c1);
        scanf("%d", &h);
        string str;
        cin >> str;
        int cont0 = 0;
        int cont1 = 0;
        for (int i = 0; i < (int)str.length(); ++i) {
            if (str[i] == '0')
                ++cont0;
            else
                ++cont1;
        }
        if (((c0 <= c1) && (c0 + h >= c1)) || ((c1 <= c0) && (c1 + h >= c0)))
            printf("%d\n", c0 * cont0 + c1 * cont1);
        else if ((c0 < c1) && (c0 + h < c1))
            printf("%d\n", c0 * cont0 + (h + c0) * cont1);
        else if ((c1 < c0) && (c1 + h < c0))
            printf("%d\n", c1 * cont1 + (h + c1) * cont0);
    }
    return 0;
}
