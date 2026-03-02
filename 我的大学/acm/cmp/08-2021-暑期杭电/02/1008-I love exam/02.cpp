#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int maxn = 15000 + 5;
struct Info {
    int x;     // 这份资料能提供的分数
    int y;     // 这份资料需要复习的天数
    double w;  // 这份资料的权重
};

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
        map<string, Info> mp1;   // 存储的是这份资料的信息
        map<string, double> mp2; // 存储的是这份资料的权重
        for (int i = 0; i < n; ++i) {
            string course;
            cin >> course;
            mp1[course] = {0, 0, 0};
            mp2[course] = 0.0;
        }
        
        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            string course;
            int x, y;
            cin >> course >> x >> y;
            mp1[course]
        }
    }
    return 0;
}
