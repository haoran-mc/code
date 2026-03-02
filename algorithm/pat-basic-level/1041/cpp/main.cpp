#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
unordered_map<int, pair<string, int>> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        int a, b;
        cin >> str >> a >> b;
        mp.insert(make_pair(a, make_pair(str, b)));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (mp.find(a) != mp.end()) {
            cout << mp[a].first << " " << mp[a].second << endl;
        }
    }
    return 0;
}
