/*----------------------------------------------------------------
 *
 *   文件名称：Express Mail Taking.cpp
 *   创建日期：2020年09月20日 ---- 13时21分
 *   题    目：poj
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ill;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        int m;
        int k;
        scanf("%d", &n);
        scanf("%d", &m);
        scanf("%d", &k);
        ill minDis = 0;;
        vector<int> vec;
        while (m--) {
            int mail;
            scanf("%d", &mail);
            vec.push_back(mail);
        }
        sort(vec.begin(), vec.end());

        minDis += 2 * (k - 1);
        for (auto it = vec.begin() + 1; it != vec.end(); it++)
            minDis += 2 * abs(*it - k);

        if (vec[0] > k)
            minDis += 2 * (vec[0] - k);

        printf("%lld\n", minDis);
    }
    return 0;
}

