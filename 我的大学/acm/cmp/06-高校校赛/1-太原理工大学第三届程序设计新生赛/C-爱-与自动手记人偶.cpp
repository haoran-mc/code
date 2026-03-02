#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
const int maxn = 1e5 + 5;
#define bug cout << "<----->\n";
string room[105];
string word[maxn];
struct Pos {
    int x;
    int y;
    Pos() {}
    Pos(int _x, int _y): x(_x), y(_y) {}
};
map<char, Pos> mp;
bool flag;

bool change(int i, int j) {
    if (word[i][j] <= 'z' && word[i][j] >= 'a' && flag) {
        flag = false;
        return true;
    }
    else if (word[i][j] <= 'Z' && word[i][j] >= 'A' && !flag) {
        flag = true;
        return true;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            Pos pos(i, j);
            mp[ch] = pos;
        }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> word[i];
        word[i].insert(0, "-");
    }
    int x = 1;
    int y = 1;
    int res = 0;
    flag = false;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j < (int)word[i].size(); ++j) {
            if (change(i, j)) {
                res += (abs(x - mp['@'].x) + abs(y - mp['@'].y));
                x = mp['@'].x;
                y = mp['@'].y;
            }
            if (word[i][j] <= 'Z' && word[i][j] >= 'A')
                word[i][j] += 32;
            res += (abs(x - mp[word[i][j]].x) + abs(y - mp[word[i][j]].y));
            x = mp[word[i][j]].x;
            y = mp[word[i][j]].y;
        }
        if (i != t) {
            res += (abs(x - mp['#'].x) + abs(y - mp['#'].y));
            x = mp['#'].x;
            y = mp['#'].y;
        }
    }
    cout << res << endl;
    return 0;
}
