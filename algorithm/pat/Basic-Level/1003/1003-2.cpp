/*----------------------------------------------------------------
 *
 *   文件名称：1003-2.cpp
 *   创建日期：2020年10月15日 ---- 16时30分
 *   题    目：PAT
 *   算    法：string
 *   描    述：看了一眼题解，字符串不仅只能包含PAT这三种字符
 *             而且要求P前面的A的数量乘以PT中间的A的数量等于T后面A的数量
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        string str;
        string strPAT = "PAT";
        cin >> str;
        int flag = 0;
        if (str.find('P') == string::npos || str.find('A') == string::npos || str.find('T') == string::npos) {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < (int)str.length(); i++)
            if (strPAT.find(str[i]) == string::npos)
                flag = 1;

        if (flag == 1) {
            printf("NO\n");
            continue;
        }
        int Asum1 = (int)str.find('P');
        int Asum2 = (int)str.find('T', Asum1) - Asum1 - 1;
        int Asum3 = (int)str.length() - Asum2 - Asum1 - 2;
        //printf("%d %d %d \n", Asum1, Asum2, Asum3);
        if (Asum1 * Asum2 == Asum3)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

