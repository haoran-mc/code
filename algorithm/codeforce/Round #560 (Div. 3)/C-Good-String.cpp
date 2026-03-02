#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int len;
    string str;
    cin >> len >> str;
    str.insert(0, "@");
    int res = 0;
    for (int i = 2; i < (int)str.length(); i += 2)
        while (str[i] == str[i-1]) {
            /*cout << str << endl;*/
            ++res,
            str.erase(i, 1);
            /*cout << str << endl;*/
        }
    /*if (str.length() == 2)*/
        /*cout << res << endl;*/
    if (!(str.length() & 1)) {
        ++res;
        str.erase(str.length() - 1, 1);
    }
    if (str.length() == 2)
        cout << res << endl;
    else {
        str = str.substr(1, str.length());
        cout << res << endl << str;
    }
    return 0;
}
