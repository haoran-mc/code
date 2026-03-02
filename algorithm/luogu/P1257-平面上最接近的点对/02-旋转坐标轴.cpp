/*----------------------------------------------------------------
 *
 *   文件名称：02-旋转坐标轴.cpp
 *   创建日期：2021年04月22日 ---- 17时05分
 *   题    目：luogu P1257 平面上最接近点对
 *   算    法：左边旋转
 *      x' = x * cos(t) - y * sin(t);
 *      y' = y * sin(t) + y * cos(t);
 *   描    述：由于答案中的最接近的两个点肯定不会离得太远，所以只
 *      取每个点向后的5个点来计算答案
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
const int inf  = 0x3f3f3f3f;
#define bug printf("<-->\n");
double res = (double)inf;
double x, y, newx, newy;

struct Point{
    double x;
    double y;
    double newx;
    double newy;
} point[maxn];

bool cmp(const Point &p1, const Point &p2) {return p1.newx < p2.newx;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &x, &y);
        newx = x*cos(1) - y*sin(1);
        newy = x*sin(1) + y*cos(1);
        point[i].newx = newx;
        point[i].newy = newy;
        point[i].x = x;
        point[i].y = y;
    }
    sort(point, point+n, cmp);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= 5; ++j) {
            x = point[i].x;
            y = point[i].y;
            newx = point[i+j].x;
            newy = point[i+j].y;
            // res = min(res, hypot(fabs(x-newx), fabs(y-newy)));
            res = min(res, hypot((x-newx), (y-newy)));
        }
    printf("%.4lf\n", res);
}
