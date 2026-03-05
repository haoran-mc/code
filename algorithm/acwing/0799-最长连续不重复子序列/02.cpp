/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年05月31日 星期一 18时42分43秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：视频
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int sequ[maxn];
int haxh[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &sequ[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        ++haxh[sequ[i]];
        while (haxh[sequ[i]] > 1) {
            --haxh[sequ[i]];
            ++j;
        }
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);
    return 0;
}
