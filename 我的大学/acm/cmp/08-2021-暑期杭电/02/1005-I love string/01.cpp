#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int len; cin >> len;
        string str;
        cin >> str;
        long long cnt = 1LL;
        for (int i = 1; i < len; ++i) {
            if (str[i] == str[i-1]) {
                cnt *= 2;
                cnt %= mod;
            }
            else
                break;
        }
        cout << cnt % mod << endl;
    }
    return 0;
}
