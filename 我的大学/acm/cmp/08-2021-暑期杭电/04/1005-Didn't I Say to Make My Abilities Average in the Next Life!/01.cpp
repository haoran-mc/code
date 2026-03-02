#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define bug cout << "<-->\n";

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if (str.find("sin") != string::npos || str.find("cos") != string::npos) {
            cout << "NO\n";
            continue;
        }
        if (str.find("^") != string::npos) {
            int pos = str.find("^");
            if (str[pos-1] != "0" && str[pos-1] != 1)
                cout << "NO\n";
            continue;
        }
        int pos = 0;
        bool flag = false;
        while (pos < (int)str.size()) {
            if (str.find("x", pos) == string::npos)
                break;
            pos = str.find("x", pos + 1);
            if (isdigit(str[pos-1])) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
        // cout << flag ? "NO\n" : "YES\n";
    }
    return 0;
}
