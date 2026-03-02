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
        int pos = 0;
        // 判断^
        while (pos < (int)str.size()) {
            if (str.find("^") == string::npos)
                break;
            pos = str.find("^", pos + 1);
            if (str[pos-1] == "1" && isdigit(str[pos-2]))
        }
    }
}
