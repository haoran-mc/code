/*----------------------------------------------------------------
 *
 *   文件名称：02.cpp
 *   创建日期：2021年08月04日 星期三 23时32分19秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：csdn上的题解
 *
 ----------------------------------------------------------------*/

#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 500 + 5;
const int ImaxnF = 1e9;

struct Node {
    int x, y;
};

int f[maxn][maxn];
int dp[maxn][maxn][maxn];
map<string, int> mp;

void solve() {
    vector<Node> vec[55];
    mp.clear();
    memset(f, -ImaxnF, sizeof f);
    memset(dp, -ImaxnF, sizeof dp);
    int n; cin >> n;
    string score;
    for (int i = 1; i <= n; i++) {
        cin >> score;
        mp[score] = i;
    }

    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        Node z;
        cin >> score >> z.x >> z.y;
        vec[mp[score]].emplace_back(z);
    }
    int t, p;
    cin >> t >> p;
    for (int i = 1; i <= n; i++)
        f[i][0] = 0; //第i门课, 花费j天

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < vec[i].size(); j++)
            for (int k = t; k >= vec[i][j].y; k--)
                f[i][k] = min(100, max(f[i][k], f[i][k - vec[i][j].y] + vec[i][j].x));

    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) // 第几门课
        for (int j = 0; j <= t; j++) // 需要几天
            for (int k = 0; k <= p; k++) // 挂几门课
                for (int z = 0; z <= j; z++) {   // 当前课学几天
                    if (f[i][z] < 60 && k != 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - z][k - 1] + f[i][z]);
                    else if (f[i][z] >= 60)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - z][k] + f[i][z]);
                }

    int res = -1;
    for (int i = 0; i <= p; i++) 
        res = max(res, dp[n][t][i]);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
