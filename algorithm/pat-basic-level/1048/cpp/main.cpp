#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s = "0123456789JQK";

int main() {
    string a, b;
    cin >> a >> b;

    // 坑，不足的位要补 '0'
    if (a.length() > b.length()) {
        b.insert(0, a.length() - b.length(), '0');
    } else {
        a.insert(0, b.length() - a.length(), '0');
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c = "";
    for (int i = 0; i < a.length(); i++) {
        if (i % 2 == 0) { // 奇
            int res = (a[i] - '0' + b[i] - '0') % 13;
            c += s[res];
        } else { // 偶
            int res = (b[i] - '0') - (a[i] - '0');
            if (res < 0) {
                res += 10;
            }
            c += (res + '0');
        }
    }
    reverse(c.begin(), c.end());
    cout << c << endl;
    return 0;
}
