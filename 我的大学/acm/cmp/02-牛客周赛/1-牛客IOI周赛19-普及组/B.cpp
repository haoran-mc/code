/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：B.cpp
 *   创建日期：2020年10月04日 ---- 19时35分
 *   结束日期：2020年10月04日 ---- 20时17分
 *   题    目：nowcoder
 *   算    法：贪心，散列
 *   描    述：a[i] = a[1] + 1 + 2 + 3 + ... + (i - 1)
 *                  = a[1] + (i - 1) * i / 2
 *             判断每个数，对它来说a[1]应该是多少
 *             循环找到最优的a[1]的数目，n - sum(a[1])
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <map>
using namespace std;

typedef long long ill;
const int maxn = 1e6 + 1;
struct Sequ{
    ill num;
    ill A1;
}sequ[maxn];
map<int, int> mp;

int main()
{
    ill n;
    scanf("%lld", &n);
    for (int i = 1; i < n + 1; i++)
        scanf("%lld", &sequ[i].num);

    for (int i = 2; i < n + 1; i++)
        sequ[i].A1 = sequ[i].num - (i - 1) * i / 2;

    for (int i = 2; i < n + 1; i++) {
        auto it = mp.find(sequ[i].A1);

        if (it == mp.end())
            mp[sequ[i].A1] = 1;

        else if (it != mp.end())
            mp[sequ[i].A1]++;
    }

    int maxSum = 0;
    int maxA1  = 0;
    bool flag = false;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it -> second == maxSum && it -> first == sequ[1].A1) {
            flag   = true;
            maxA1  = it -> first;
            maxSum = it -> second;
        }
        if (it -> second > maxSum) {
            flag   = false;
            maxA1  = it -> first;
            maxSum = it -> second;
        }
    }

    if (flag == false && maxA1 == sequ[1].num)
        maxSum++;

    printf("%lld\n", n - maxSum);
    return 0;
}
