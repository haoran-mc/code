/*----------------------------------------------------------------
 *
 *   文件名称：1016---.cpp
 *   创建日期：2020年11月01日 ---- 08时56分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
int main()
{
    char strA[10];
    char strB[10];
    int DA;
    int DB;
    char chDA;
    char chDB;
    scanf("%s", strA);
    scanf("%s", strB);
    scanf("%d", &DA);
    scanf("%d", &DB);
    chDA = (char)DA + '0';
    chDB = (char)DB + '0';
    int countA = 0;
    for (int i = 0; i < (int)strlen(strA); ++i)
        if (strA[i] == chDA)
            countA++;
    int countB = 0;
    for (int i = 0; i < (int)strlen(strB); ++i)
        if (strB[i] == chDB)
            countB++;
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
