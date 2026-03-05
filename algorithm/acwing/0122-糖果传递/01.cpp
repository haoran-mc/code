/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年06月02日 星期三 17时14分21秒
 *   题    目：AcWing 0122 糖果传递
 *   算    法：推公式
 *   描    述：视频代码
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int n;
ll I[maxn];

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &I[i]);
        sum += I[i];
    }
    int avg = sum / n;
    for (int i = n; i > 1; --i)
        I[i] = avg - I[i] + I[i + 1];
    I[1] = 0;
    sort(I + 1, I + n + 1);
    ll res = 0;

    for (int i = 1; i <= n; ++i)
        res += abs(I[i] - I[(n + 1) / 2]);

    printf("%lld\n", res);
    return 0;
}
