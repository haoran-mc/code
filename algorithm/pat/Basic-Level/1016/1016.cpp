/*----------------------------------------------------------------
 *
 *   文件名称：1016.cpp
 *   创建日期：2020年11月01日 ---- 08时20分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
typedef long long ill;
int main()
{
    ill A;
    ill B;
    int DA;
    int DB;
    scanf("%lld", &A);
    scanf("%d", &DA);
    scanf("%lld", &B);
    scanf("%d", &DB);
    //int tempA = DA;
    //int tempB = DB;
    int countA = 0;
    int countB = 0;
    while (A /= 10)
        if (A % 10 == DA)
            countA++;

    while (B /= 10)
        if (B % 10 == DB)
            countB++;

    while (--countA)
        DA = 10 * DA + DA;

    while (--countB)
        DB = 10 * DB + DB;

    printf("%d\n", DA + DB);
    return 0;
}
