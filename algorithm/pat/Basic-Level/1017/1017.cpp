/*----------------------------------------------------------------
 *
 *   文件名称：1017.cpp
 *   创建日期：2020年11月01日 ---- 09时28分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define bug printf("******\n");
int main()
{
    //freopen("in.txt", "r", stdin);
    string strA;
    int B;
    cin >> strA >> B;
    char ch;
    int x = 0;
    if (strA.length() == 1 && strA[0]-'0' < B) {
        printf("0 %c\n", strA[0]);
        return 0;
    }
    for (int i = 0; i < (int)strA.length(); ++i) {
        ch = strA[i];
        ch -= '0';
        x = 10 * x + ch;
        if (!(x < B && i == 0))
            printf("%d", x/B);
        x %= B;
    }
    printf(" %d\n", x);
    return 0;
}
