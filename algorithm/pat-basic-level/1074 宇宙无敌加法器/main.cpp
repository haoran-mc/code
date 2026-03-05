// 260305 11:03 Thu
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string base, a, b;
    cin >> base >> a >> b;

    string s1(base.length() - a.length(), '0');
    a = s1 + a;
    string s2(base.length() - b.length(), '0');
    b = s2 + b;

    // 进位加法
    vector<int> res;
    int carry = 0;
    for (int i = base.size() - 1; i >= 0; i--) {
        int base_int = base[i] == '0' ? 10 : (base[i] - '0');
        int num = (a[i] - '0') + (b[i] - '0') + carry;
        res.push_back(num % base_int);
        carry = num / base_int;
    }

    if (carry != 0)
        res.push_back(1);

    reverse(res.begin(), res.end());

    int flag = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] != 0 || flag == 1) {
            flag = 1;
            cout << res[i];
        }
    }
    if (flag == 0) {
        cout << 0;
    }

    return 0;
}
