#include <cstdio>
#include <set>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 500;
map<string, int> mp;   // 将课程名对应为输入时的i
int f[55][105];   // f[i][j]表示课程i，在分数为j时最少花费的天数
int dp[505][5];   // dp[i][j]表示花费i天，挂了j课得到的分数
int mx[52][505];  // mx[j][k]表示花费k天，挂了j课时得到的最多分数

/**
 * t                     t组数据(t <= 10)
 * n                     这学期学了多少门课程(n <= 50)
 * course1, course2, course3, ..., coursen
 * m                     资料(m <= 15000)
 * course score day      每份资料对应的课程，提高的分数，花费的天数
 * course score day
 * course score day
 * course score day
 * course score day
 * course score day
 * t p                   复习的天数，允许挂科数(t <= 500, p <= 3)
 */

struct Node {
    int x, y;
};

vector<Node> vec[maxn];

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string course;
        for (int i = 1; i <= n; ++i) {
            cin >> course;
            mp[course] = i;
        }

        int m; cin >> m;
        for(int i = 1; i <= m; ++i) {
            cin >> course;
            int id = mp[course];
            int score, day;
            cin >> score >> day;
            vec[id].push_back(Node{score, day});  // id代表一门课，这门课的资料
        }
        int t, p;   // 复习的天数与最多挂几科
        cin >> t >> p;

        memset(f, 0x3f, sizeof f);
        memset(dp, -0x3f, sizeof dp);
        memset(mx, 0, sizeof mx);
        for (int i = 1; i <= n; ++i) {
            f[i][0] = 0;
            for (int j = 0; j < vec[i].size(); ++j)  // 第i门课的资料
                for (int k = 100; k >= vec[i][j].x; --k)
                    f[i][k] = min(f[i][k], f[i][k - vec[i][j].x] + vec[i][j].y);

            for (int k = 1; k <= 100; ++k)
                if (f[i][k] <= 500)
                    mx[i][f[i][k]] = max(mx[i][f[i][k]], k);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = t; j >= 1; --j) {
                for (int k = p; k > 0; --k)
                    dp[j][k] = dp[j][k-1];

                dp[j][0] = -1e9;
                for (int k = 0; k <= p; ++k)
                    for (int l = 1; l <= f[i][100] && l <= j; ++l) {
                        if (mx[i][l] >= 60)
                            dp[j][k] = max(dp[j-l][k] + mx[i][l], dp[j][k]);
                        else if (k)
                            dp[j][k] = max(dp[j-l][k-1] + mx[i][l], dp[j][k]);
                    }
            }
            dp[0][0] = -1e9;
        }
        int res = -1;
        for (int i = 1; i <= t; ++i) 
            for (int j = 0; j <= p; ++j)
                res = max(res, dp[i][j]);

        cout << res << endl;
        mp.clear();
        for (int i = 1; i <= n; ++i)
            vec[i].clear();
    }
    return 0;
}
