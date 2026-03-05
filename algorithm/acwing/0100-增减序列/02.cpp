/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年05月24日 星期一 22时03分56秒
 *   题    目：AcWing 100 增减序列
 *   算    法：差分
 *   描    述：后面一个输出有点难想
 *           0 0 0 1 0 0 1 0 1 1 0 1 0
 *           3 3 3 4 4 4 5 5 6 7 7 8 8 
 *           这样就有6种选择，3, 4, 5, 6, 7, 8
 *           比差分中的1的个数多一个
 *
 ----------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define bug printf("<-->\n");
#define lowbit(x) ((x) & -(x)) //lowbit(ob0010) = 2
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define NEXTLINE puts("");
// #define int long long
// const int maxn = <++>;
// const int maxp = 1010;    //点的数量
// const int inf = 0x3f3f3f3f;
// const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const double pi = acos(-1.0);
const double eps = 1e-6;
const double gold = (1 + sqrt(5)) / 2; //黄金分割 = 1.61803398...
priority_queue<int, vector<int>, less<int>> pqu_int; /*默认是less，即数字大的优先级高*/

void clear(queue<int>& q) {
    queue<int> empty;
    swap(empty, q);
}

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

const int maxn = 1e5 + 5;
int diff[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &diff[i]);
    for (int i = n-1; i >= 1; --i)
        diff[i] = diff[i] - diff[i-1];

    ll pos = 0, neg = 0;
    for (int i = 1; i < n; ++i)
        if (diff[i] > 0)
            pos += diff[i];
        else
            neg -= diff[i];

    printf("%lld\n", _min(neg, pos) + abs(neg - pos));
    printf("%lld\n", abs(neg - pos) + 1);
}

int main() {
// signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    solve();
    return ~~(0-0);
}
