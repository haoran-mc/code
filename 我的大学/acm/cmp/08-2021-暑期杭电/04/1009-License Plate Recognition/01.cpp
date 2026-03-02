#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int dirx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
#define bug cout << "<-->\n";
// int dirx[4] = {-1, 0, 1, 0};
// int diry[4] = {0, -1, 0, 1};
bool used[35][105];
const int INF = 0x3f3f3f3f;
int mini = INF, maxi = 0;
string str[30];
struct Node {
    int mini;
    int maxi;
} node[7];

vector<pair<int, int>> vec;

bool judge(int x, int y) {
    if (x < 0 || x >= 30 || y < 0 || y >= 100)
        return false;
    return true;
}

void DFS(int nowX, int nowY) {
    if (nowY < mini)
        mini = nowY;
    if (nowY > maxi)
        maxi = nowY;
    used[nowX][nowY] = true;
    for (int i = 0; i < 8; ++i)
        if (str[nowX+dirx[i]][nowY+diry[i]] == '#' && judge(nowX+dirx[i], nowY+diry[i]) && !used[nowX+dirx[i]][nowY+diry[i]])
            DFS(nowX+dirx[i], nowY+diry[i]);
    return ;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t; cin >> t;
    int cnt = 0;
    while (t--) {
        memset(used, 0, sizeof used);
        for (int i = 0; i < 30; ++i)
            cin >> str[i];
        cout << "Case #" << ++cnt << ":\n";
        for (int j = 0; j < 100; ++j)
            for (int i = 0; i < 30; ++i) {
                mini = INF, maxi = 0;
                if (str[i][j] == '#' && !used[i][j]) {
                    DFS(i, j);
                    vec.push_back({mini+1, maxi+1});
                }
            }
        int size = vec.size() - 7;
        int l = INF, r = 0;
        for (int i = 0; i <= size; ++i) {
            l = min(l, vec[i].first);
            r = max(r, vec[i].second);
        }
        cout << l << " " << r << endl;
        for (int i = size + 1; i < (int)vec.size(); ++i)
            cout << vec[i].first << " " << vec[i].second << endl;
        vec.clear();
    }
    return 0;
}
