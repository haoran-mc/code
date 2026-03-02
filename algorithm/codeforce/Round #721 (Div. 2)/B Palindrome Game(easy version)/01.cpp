#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        string str;
        cin >> n >> str;
        if (str.find('0') == string::npos) {
            cout << "DRAW" << endl;
            continue;
        }
        if (str == "0") {
            cout << "BOB" << endl;
            continue;
        }
        auto it1 = str.begin();
        auto it2 = str.end() - 1;
        int cnt = 0;
        while (it1++ < it2--)
            if (*it1 != *it2)
                ++cnt;
        cout << (cnt != 1 ? "BOB" : "ALICE") << endl;
    }
    return 0;
}
