#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int maxn = 15000 + 5;
struct Info {
    string Name;
    int x;   // 这份资料能提供的分数
    int y;   // 这份资料需要复习的天数
    double w;   // 这份资料的权重
} info[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<string, make_pair(int, int)> mp1;
        for (int i = 0; i < n; ++i) {
            string name; cin >> name;
            mp1[name] = {0, 0};
        }

        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> info[i].Name >> info[i].x >> info[i].y;
            info[i].w = (double)info[i].x / (double)info[i].y;
            mp1[info[i].Name].first  += info[i].x;
            mp1[info[i].Name].second += info[i].y;
        }

        map<string, double> mp2;
        for (auto it = mp1.begin(); it != mp1.end(); ++it) 
            mp2[it.first] = (double)it.second.first / (double)it.second.second;

        for (auto it = mp2.end(); it != mp2.begin(); --it) {
            name = it.begin();
        }
    }
    return 0;
}
