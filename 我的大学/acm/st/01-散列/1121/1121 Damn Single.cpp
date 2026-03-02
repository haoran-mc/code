/*----------------------------------------------------------------
 *
 *   文件名称：1121 Damn Single.cpp
 *   创建日期：2020年08月22日 ---- 11时08分
 *   题    目：Damn Single
 *   算    法：散列
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct Couple {
    int couple1;
    int couple2;
};
const int N = 1e6;
int hash[N];
int cnt = 0;
int single[N];
int unknow[N];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        Couple couple;
        scanf("%d %d", &couple.couple1, &couple.couple2);
        hash[couple.couple1] = couple.couple2;
        hash[couple.couple2] = couple.couple1;
    }

    int m;
    int num1;
    int num2 = -1;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &num1);
        if (num1 == num2)
            continue;

        if (hash[num1] == 0)
            single[++cnt] = num1;
        else {
            hash[num1] = 0;
            hash[hash[num1]] = 0;
            num2 = hash[num1];
        }
    }

    printf("%d\n", cnt);
    sort(single, single+cnt+1);
    for (int i = 1; i <= cnt; i++) {
        if (i == cnt)
            printf("%d\n", single[i]);
        else
            printf("%d ", single[i]);
    }
    return 0;
}

