// #include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string name, brith;
        cin >> name >> brith;
        if (brith > "2014/09/06" || brith < "1814/09/06") {
            continue;
        }
        mp[brith] = name; // map 自动排序
        cnt++;
    }
    if (!mp.empty()) {
        cout << cnt << " " << mp.begin()->second << " " << (--mp.end())->second << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
