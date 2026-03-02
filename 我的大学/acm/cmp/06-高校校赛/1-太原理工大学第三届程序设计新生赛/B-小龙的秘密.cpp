#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
#define bug cout << "<------>\n";
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string str1;
    string str2;
    cin >> str1 >> str2;
    map<char, int> mp1;
    map<char, int> mp2;
    for (int i = 0; i < (int)str1.length(); ++i)
        ++mp1[str1[i]];
    for (int i = 0; i < (int)str2.length(); ++i)
        ++mp2[str2[i]];
    bool flag = false;
    if (mp1.size() != mp2.size())
        flag = true;
    for (auto it = mp1.begin(); it != mp1.end() && !flag; ++it) {
        if (mp2.find(it -> first) == mp2.end()) {
            flag = true;
            break;
        }
        if (mp1[it -> first] != mp2[it -> first]) {
            flag = true;
            break;
        }
    }
    cout << (!flag ? "^_^" : "-_-#") << endl;
    return 0;
}
