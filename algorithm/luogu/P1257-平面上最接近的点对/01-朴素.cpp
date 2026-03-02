/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：01-朴素.cpp
 *   创建日期：2021年04月22日 ---- 17时03分
 *   结束日期：2021年04月22日 ---- 17时04分
 *   题    目：luogu P1257 平面上最接近点对
 *   算    法：<++>
 *   描    述：点的个数较少，可以暴力
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxp = 1e4 + 5;
const int inf  = 0x3f3f3f3f;
double mini = (double)inf;

struct Point {double x, y;} point[maxp];
double dis(Point p1, Point p2) {return hypot(p1.x-p2.x, p1.y-p2.y);}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf %lf", &point[i].x, &point[i].y);
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            mini = min(mini, dis(point[i], point[j]));
    printf("%.4f\n", mini);
    return 0;
}
