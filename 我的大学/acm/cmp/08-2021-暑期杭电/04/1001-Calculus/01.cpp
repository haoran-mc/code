#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main() {
    int t; cin >> t;
    while (t --) {
        string str; cin >> str;
        ll cnt[10];   // cnt数组记录系数
        /**
         * cnt[0]: 常数C
         * cnt[1]: C/x
         * cnt[2]: Csinx
         * cnt[3]: Ccosx
         * cnt[4]: C / sinx
         * cnt[5]: C / cosx
         * cnt[6]: Cx
         * cnt[7]: C^x
         */
        memset(cnt, 0, sizeof cnt);
        int len = str.length();
        ll i = 0, C = 0;
        while (i < len) {
            C = 0;
            while (i < len && (str[i] >= '0' && str[i] <= '9')) {
                C = C * 10 + str[i] - '0';
                ++ i;
            }
            if (i >= len) 
                cnt[0] += C;
            else if (str[i] == '+') {
                cnt[0] += C;
                ++ i;
            }
            else if (str[i] == '/') {
                ++i;
                if (str[i] == 'x') {
                    cnt[1] += C;
                    i += 2;
                }
                else if (str[i] == 's') {
                    cnt[4] += C;
                    i += 5;
                }
                else if (str[i] == 'c') {
                    cnt[5] += C;
                    i += 5;
                }
            }
            else if (str[i] == 's') {
                cnt[2] += C;
                i += 5;
            }
            else if (str[i] == 'c') {
                cnt[3] += C;
                i += 5;
            }
            else if (str[i] == 'x') {
                cnt[6] += C;
                i += 2;
            }
            else if (str[i] == '^') {
                cnt[7] += C;
                i += 3;
            }
        }
        if (cnt[0] || cnt[1] || cnt[2] || cnt[3] || cnt[4] || cnt[5] || cnt[6] || cnt[7])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
