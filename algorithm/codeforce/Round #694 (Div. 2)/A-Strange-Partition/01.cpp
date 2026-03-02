/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年04月28日 ---- 21时18分
 *   题    目：cf
 *   算    法：贪心
 *   描    述：ceil的参数是double，需要强制类型转换
 *
 ----------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define bug printf("<-->\n");
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define int long long
const int maxn = 1e5;
// const int maxp = 1010;    //点的数量
// const int inf = 0x3f3f3f3f;
// const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const double pi = acos(-1.0);
const double eps = 1e-6;
const double gold = (1 + sqrt(5)) / 2; //黄金分割 = 1.61803398...
priority_queue<int, vector<int>, less<int>> pqu_int; /*默认是less，即数字大的优先级高*/
int arr[maxn];

inline int sigma(char c) {return c - 'a';};

inline int sgn(double x) { //判断x是否等于0
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

inline int dcmp(double x, double y) { //比较两个浮点数：0 相等；-1 小于；1 大于
    if (fabs(x - y) < eps) return 0;
    else return x < y ? -1 : 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    bool operator == (const Point _point) {return sgn(x - _point.x) == 0 && sgn(y - _point.y) == 0;}
};

inline double dis(Point p1, Point p2) {return hypot(p1.x-p2.x, p1.y-p2.y);}

void solve() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, x;
        scanf("%lld %lld", &n, &x);
        int maxi = 0;
        int mini = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
            mini += arr[i];
            maxi += (int)ceil((double)arr[i] / (double)x);
        }
        mini = (int)ceil((double)mini / (double)x);
        printf("%lld %lld\n", mini, maxi);
    }
}

signed main() {
// int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    solve();
    return ~~(0-0);
}
