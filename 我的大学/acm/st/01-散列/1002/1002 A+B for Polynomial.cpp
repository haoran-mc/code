/*----------------------------------------------------------------
 *
 *   文件名称：1002 A+B for Polynomial.cpp
 *   创建日期：2020年08月10日
 *   题    目：A+B for Polynamials
 *   描    述：散列，使用map会对元素排序，不能按输入的倒叙输出
 *             失败
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, double> mp;
    int n;
    int k;
    double kn;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        scanf("%lf", &kn);
        mp[k] = kn;
    }

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        scanf("%lf", &kn);
        if (mp[k])
            mp[k] += kn;
        else
            mp[k] = kn;
    }

    printf("%lld", mp.size());
    for (unordered_map<int, double>::iterator it = mp.begin(); it != mp.end(); it++)
        printf(" %d %.1f", it -> first, it -> second);

    return 0;
}

