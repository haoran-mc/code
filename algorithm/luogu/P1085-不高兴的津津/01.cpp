/***
*  创建日期：2022/04/08 Fri 02:44:34
*  题目来源：Luogu P1085 不高兴的津津
*  算    法：<++>
*  描    述：<++>
**/

#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
PII nofun[7];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p2.first)
        return true;
    else if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    for (int i = 1; i <= 7; i ++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        nofun[i - 1].first = a + b;
        nofun[i - 1].second = i;
    }
    sort(nofun, nofun + 7, cmp);
    if (nofun[0].first > 8)
        printf("%d\n", nofun[0].second);
    else
        puts("0");
    return 0;
}
