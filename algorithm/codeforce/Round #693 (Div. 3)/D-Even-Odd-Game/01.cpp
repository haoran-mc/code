/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年04月28日 ---- 15时21分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：想复杂了，其实就是没想到，应该对全局排序
 *
 ----------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define bug printf("<-->\n");
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
// #define int long long
// signed main()
int maxn = 2e5 + 5;
// const int maxp = 1010;    //点的数量
// const int inf = 0x3f3f3f3f;
// const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const double pi = acos(-1.0);
const double eps = 1e-6;
const double gold = (1 + sqrt(5)) / 2; //黄金分割 = 1.61803398...
priority_queue<int> pqu_odd;
priority_queue<int> pqu_even;

inline int idx(char c) {return c - 'a';};

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
    scanf("%d", &t);
    while (t--) {
        int n, Alice, Bob;
        Alice = Bob = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if (a % 2)
                pqu_odd.push(a);
            else
                pqu_even.push(a);
        }
        for (int i = 1; i <= n; ++i) {
            if (i % 2) { //Alice
                if (!pqu_odd.empty() && !pqu_even.empty()) {
                    if (pqu_odd.top() > pqu_even.top())
                        pqu_odd.pop();
                    else {
                        Alice += pqu_even.top();
                        pqu_even.pop();
                    }
                }
                else if (!pqu_odd.empty() && pqu_even.empty())
                    pqu_odd.pop();
                else if (pqu_odd.empty() && !pqu_even.empty()) {
                    Alice += pqu_even.top();
                    pqu_even.pop();
                }
            }
            else { //Bob
                if (!pqu_odd.empty() && !pqu_even.empty()) {
                    if (pqu_odd.top() < pqu_even.top())
                        pqu_even.pop();
                    else {
                        Bob += pqu_odd.top();
                        pqu_odd.pop();
                    }
                }
                else if (!pqu_odd.empty() && pqu_even.empty()) {
                    Bob += pqu_odd.top();
                    pqu_odd.pop();
                }
                else if (pqu_odd.empty() && !pqu_even.empty())
                    pqu_even.pop();
            }
        }
        if (Alice > Bob)
            printf("Alice\n");
        else if (Alice == Bob)
            printf("Tie\n");
        else
            printf("Bob\n");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    solve();
    return ~~(0-0);
}
