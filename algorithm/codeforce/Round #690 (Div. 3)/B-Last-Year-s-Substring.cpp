#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //ios::sync_with_stdio(false);
    //cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string str;
        cin >> n >> str;
        if (str.length() < 4) {
            cout << "NO" << endl;
            continue;
        }
        if (str.substr(0, 4) == "2020" || str.substr(n-4, 4) == "2020")
            cout << "YES" << endl;
        else if (str.substr(0, 1) == "2" && str.substr(n-3, 3) == "020")
            cout << "YES" << endl;
        else if (str.substr(0, 2) == "20" && str.substr(n-2, 2) == "20")
            cout << "YES" << endl;
        else if (str.substr(0, 3) == "202" && str.substr(n-1, 1) == "0")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
