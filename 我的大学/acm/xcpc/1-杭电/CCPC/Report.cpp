/*----------------------------------------------------------------
 *
 *   文件名称：Report.cpp
 *   创建日期：2020年09月20日 ---- 12时16分
 *   题    目：poj
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
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        n--;
        int x;
        scanf("%d", &x);
        int flag = x;
        string ans = "YES";
        while (n--) {
            scanf("%d", &x);
            if (flag != x && ans == "YES")
                flag = x;
            else if (flag == x)
                ans = "NO";
        }
        cout << ans << endl;
    }
    return 0;
}

