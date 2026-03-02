#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
bool digits[10];
map<LL, int> mp;

void digit(LL n) {
    while (n) {
        ++mp[n % 10];
        n /= 10;
    }
}

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
        LL n;
        cin >> n;
        while (n) {
            mp.clear();
            digit(n);
            bool flag = false;
            for (auto it = mp.begin(); it != mp.end(); ++it)
                if (it -> first)
                    if (n % it -> first) {
                        flag = true;
                        break;
                    }
            if (!flag) {
                printf("%lld\n", n);
                break;
            }
            ++n;
        }
    }
    return 0;
}
