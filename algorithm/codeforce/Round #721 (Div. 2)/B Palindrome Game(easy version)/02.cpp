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
        auto it1 = str.begin();
        auto it2 = str.end() - 1;
        int cnt = 0;
        while (it1++ < it2--)
            if (*it1 != *it2)
                ++cnt;
        if (cnt)
            cout << "ALICE" << endl;
        else {
            int pos_0 = str.find('0');
            if (pos_0 == (int)(str.end() - str.begin()) / 2)
                cout << "BOB" << endl;
            else if (str.length() % 2 && str[(int)(str.end() - str.begin())/2] != '0')
                cout << "BOB" << endl;
            else if (str.length() % 2 && str[(int)(str.end() - str.begin())/2] == '0' && str.find(str.find('0') + 1) != string::npos)
                cout << "ALICE" << endl;
            else
                cout << "BOB" << endl;
        }
        // cout << (cnt != 1 ? "BOB" : "ALICE") << endl;
    }
    return 0;
}
