// 260306 15:03 Fri
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool judge(string str) {
    for (int i = 0; i < str.length() / 2; i++)
        if (str[i] != str[str.length() - i - 1])
            return false;
    return true;
}

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string add(string a, string b) {
    string res = a;
    int cf = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int num = (a[i] - '0') + (b[i] - '0') + cf;
        cf = num / 10;
        // res.insert(0, 1, num % 10 + '0');
        res[i] = num % 10 + '0';
    }
    if (cf > 0)
        res.insert(0, 1, cf + '0');
    return res;
}

int main() {
    string str;
    cin >> str;

    if (str == rev(str)) {
        cout << str << " is a palindromic number.";
        return 0;
    }

    bool isPalindromicNumber = false;
    for (int i = 0; i < 10; i++) {
        string a = str;
        str = add(a, rev(a));
        cout << a << " + " << rev(a) << " = " << str << endl;
        if (str == rev(str)) {
            cout << str << " is a palindromic number.";
            return 0;
        }
    }
    cout << "Not found in 10 iterations.";
    return 0;
}
