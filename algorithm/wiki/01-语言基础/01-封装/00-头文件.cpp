#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
#define lowbit(x) ((x) & ‐(x)) // lowbit(ob0100) = 4 9 #define _max(a, b) (a > b ? a : b)
#define NEXTLINE puts("");
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
const int INF = 0x3f3f3f3f;             // int 类型最大值
const ll INF_LL = 0x3f3f3f3f3f3f3f3fLL; // long long 类型最大值
// 上右 下左 上左 上右 下右 下左
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const double PI = acos(-1.0);
const double eps = 1e-6;
const double gold = (1 + sqrt(5)) / 2;                              // 黄金分割 = 1.61803398...
const int FACT[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; // 0~9的阶乘打表
priority_queue<int, vector<int>> he;                                // 默认是less，即数字大的优先级高
priority_queue<int, vector<int>, greater<int>> hE;                  // 数字小的优先级高

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b, int c) { // 三个数的最小公倍数
    int m1 = a / gcd(a, b) * b;
    int m2 = b / gcd(b, c) * c;
    return m1 / gcd(m1, m2) * m2;
}

void clear(queue<int> &q) { // 清空队列
    queue<int> empty;
    swap(empty, q);
}

int sigma(char c) { return c - 'a'; }; // 字符转换为对应的字母下标，常用于 Trie 树的子节点索引

string trim(string s, char c = ' ') {
    s.erase(0, s.find_first_not_of(c)); // 去前缀
    s.erase(s.find_last_not_of(c) + 1); // 去后缀
    return s;
}

int sgn(double x) { // 判断x是否等于0
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}

int dcmp(double x, double y) { // 比较两个浮点数：0 相等；-1 小于；1 大于
    if (fabs(x - y) < eps)
        return 0;
    else
        return x < y ? -1 : 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator==(const Point _point) { return sgn(x - _point.x) == 0 && sgn(y - _point.y) == 0; }
};

// 欧几里得距离、直线距离
double dis(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

template <typename T>
T Smax(T x) { return x; }
template <typename T, typename... Args>
T Smax(T a, Args... args) {
    return _max(a, Smax(args...));
}

template <typename T>
T Smin(T x) { return x; }
template <typename T, typename... Args>
T Smin(T a, Args... args) {
    return _min(a, Smin(args...));
}

void solve() {
    ; //<++>
}

int main() {
    // signed main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    solve();
    return 0;
}
