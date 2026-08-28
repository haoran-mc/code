// 260306 14:03 Fri
// 260306 15:21 Fri
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string C(string s) {
    string res;
    int i = 0, j = 0;
    // 双指针，j 前 i 后
    while (i < s.length()) {
        // j 往前走，找到第一个不同的字符
        while (true) {
            j++;
            if (j >= s.length() || s[j] != s[j - 1])
                break;
        }
        if (j - i > 1) {
            res += to_string(j - i);
            res += s[i];
        } else {
            res += s[i];
        }
        i = j;
    }
    return res;
}

string D(string s) {
    string res;
    int i = 0, j = 0;
    // 双指针，j 前 i 后
    while (i < s.length()) {
        if (s[i] - '0' > 0 && s[i] - '0' <= 9) { // 找到了数字
            while (true) {                       // j 找第一个非数字
                j++;
                if (s[j] - '0' < 0 || s[j] - '0' > 9)
                    break;
            }
            // 112a....
            // i..j
            string n_str = s.substr(i, j);
            int n = atoi(n_str.c_str());
            res.append(n, s[j]);
        } else {
            res += s[i];
        }
        j++;
        i = j;
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin.ignore();
    getline(cin, s2);

    if (s1[0] == 'C') {
        cout << C(s2);
    } else {
        cout << D(s2);
    }
    return 0;
}
