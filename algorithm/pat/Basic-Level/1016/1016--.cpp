/*----------------------------------------------------------------
 *
 *   文件名称：1016--.cpp
 *   创建日期：2020年11月01日 ---- 08时29分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string strA;
    string strB;
    int DA;
    int DB;
    char chDA;
    char chDB;
    cin >> strA >> DA >> strB >> DB;
    chDA = char(DA + '0');
    chDB = char(DB + '0');
    int pos = 0;
    int countA = 0;
    int countB = 0;
    while (strA.find(chDA, pos) != string::npos) {
        pos = strA.find(chDA, pos + 1);
        countA++;
    }
    pos = 0;
    while (strB.find(chDB, pos) != string::npos) {
        pos = strB.find(chDB, pos + 1);
        countB++;
    }
    int tempA = DA;
    int tempB = DB;
    while (--countA) {
        DA *= 10;
        DA += tempA;
    }
    while (--countB) {
        DB *= 10;
        DB += tempB;
    }
    printf("%d\n", DA + DB);
    return 0;
}
