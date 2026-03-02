/*----------------------------------------------------------------
 *
 *   文件名称：1003.cpp
 *   创建日期：2020年10月10日 ---- 22时00分
 *   结束日期：2020年10月10日 ---- 22时07分
 *   题    目：PAT
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
    int n;
    cin >> n;
    while (n--) {
        string str;
        string strPAT = "PAT";
        cin >> str;
        int flag = 0;
        for (int i = 0; i < (int)str.length(); i++) {
            if (strPAT.find(str[i]) == string::npos) {
                flag = -1;
                printf("NO\n");
                break;
            }
        }
        if (flag == -1)
            continue;

        if (str.find('P') != string::npos)
            flag++;
        if (str.find('A') != string::npos)
            flag++;
        if (str.find('T') != string::npos)
            flag++;

        if (flag == 3)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
