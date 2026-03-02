#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 15000 + 5;
struct Info {
    int x;     // 这份资料能提供的分数
    int y;     // 这份资料需要复习的天数
    double w;  // 这份资料的权重
};

struct Mp3 {   // 后面使用sort来对各个课程按权重排序
    string course;
    double weight;
} mp3[maxn];

bool cmp1(Mp3 _1, Mp3 _2) {
    return _1.weight > _2.weight;
}

bool cmp2(Info _1, Info _2) {
    return _1.w > _2.w;
}

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
        map<string, vector<Info>> mp1;   // 存储的是这份门课程所有资料的信息，与权重
        map<string, Info> mp2; // 存储的是这门课程的权重
        for (int i = 0; i < n; ++i) {
            string course;
            cin >> course;
        }

        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            string course;
            int x, y;
            cin >> course >> x >> y;
            mp1[course].push_back({x, y, (double)x / (double)y});
            mp2[course].x += x;
            mp2[course].y += y;
        }
        int courseNum = (int)mp2.size();
        int idx = 0;
        for (auto it = mp2.begin(); it != mp2.end(); ++it) {
            it->second.w = (double)it->second.x / (double)it->second.y;
            mp3[idx].course = it->first;
            mp3[idx++].weight = it->second.w;
        }
        sort(mp3, mp3+courseNum, cmp1);

        /**
         * 1. 找到了按权重排序的各课程顺序mp3
         */

        for (auto it = mp1.begin(); it != mp1.end(); ++it) {
            it - mp1.begin();
        }
    }
    return 0;
}
