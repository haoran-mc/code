#include <cctype>
#include <iostream>
using namespace std;

int main() {
    string str1, str2;

    // cin >> str1 >> str2;
    getline(cin, str1); // 有坑：可能会遇到第一行是空行，键盘没有坏的情况
    getline(cin, str2);

    for (int i = 0; i < str2.length(); i++) {
        if (str1.find('+') != string::npos) {
            if (isupper(str2[i])) {
                continue;
            }
        }
        if (str1.find(toupper(str2[i])) == string::npos) {
            cout << str2[i];
        }
    }
    cout << endl;
    return 0;
}
