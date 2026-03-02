#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string str;
        cin >> n >> str;
        reverse(str.begin(), str.end());
        int pare = 0;
        for (int i = 0; i < n; ++i)
            if (str[i] == ')')
                ++pare;
            else
                break;
        pare > n - pare ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}
