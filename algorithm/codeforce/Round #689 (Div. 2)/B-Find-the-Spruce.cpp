#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 505;
string str[maxn];
int n;
int m;
int mem[maxn][maxn];

bool judge(int k_, int i_, int j_) {
    if (k_ >= n || i_ < 0 || j_ >= m)
        return false;
    bool flag = false;
    for (int i = i_; i <= j_ && !flag; ++i)
        if (str[k_][i] == '.')
            flag = true;
    return flag ? false : true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d", &m);
        int res = 0;
        for (int i = 0; i < n; ++i)
            cin >> str[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                /*if (str[i][j] == '*')*/
                    /*++res;*/
                int k_;
                int i_;
                int j_;
                if (i) {
                    // 因为没有用fill将mem记忆数组赋初值1，所以在这里全部加一
                    k_ = i + mem[i-1][j] - 1;
                    i_ = j - mem[i-1][j] + 1;
                    j_ = j + mem[i-1][j] - 1;
                    res += (mem[i-1][j] - 1);
                }
                if (!i) {
                    k_ = i;
                    i_ = j;
                    j_ = j;
                }
                while (judge(k_, i_, j_))
                    ++k_,
                    ++j_,
                    --i_,
                    ++res;
                mem[i][j] = k_ - i;
            }
        printf("%d\n", res);
    }
    return 0;
}
