#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string str;
unordered_map<char, int> mp;
const string printStr = "PATest";

int main() {
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        mp[str[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < printStr.length(); i++) {
        cnt += mp[printStr[i]];
    }
    for (int i = 0; cnt > 0; i++) {
        char ch = printStr[i];
        if (mp[ch] > 0) {
            cout << ch;
            mp[ch]--;
            cnt--;
        }
        if (i == printStr.length() - 1) {
            i = -1;
        }
    }
    cout << endl;
    return 0;
}
