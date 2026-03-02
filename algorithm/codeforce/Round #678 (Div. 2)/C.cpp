/*----------------------------------------------------------------
 *
 *   文件名称：C.cpp
 *   创建日期：2020年10月24日 ---- 23时27分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
typedef long long ill;
const ill mod = 1e9 + 7;
int main()
{
    ill n;
    ill x;
    ill pos;
    scanf("%lld", &n);
    scanf("%lld", &x);
    scanf("%lld", &pos);
    ill mul = 1;
    for (ill i = 1; i < n; i++) {
        mul *= i;
        mul %= mod;
    }
    printf("%lld\n", mul);
    return 0;
}
