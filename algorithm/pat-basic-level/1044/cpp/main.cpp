#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp{
    {"tret", 0},
    {"jan", 1},
    {"feb", 2},
    {"mar", 3},
    {"apr", 4},
    {"may", 5},
    {"jun", 6},
    {"jly", 7},
    {"aug", 8},
    {"sep", 9},
    {"oct", 10},
    {"nov", 11},
    {"dec", 12},
    {"tam", 13},
    {"hel", 13 * 2},
    {"maa", 13 * 3},
    {"huh", 13 * 4},
    {"tou", 13 * 5},
    {"kes", 13 * 6},
    {"hei", 13 * 7},
    {"elo", 13 * 8},
    {"syy", 13 * 9},
    {"lok", 13 * 10},
    {"mer", 13 * 11},
    {"jou", 13 * 12},
};

// 29 -> hel mar
string digitToAlpha(string str) {
    int num = stoi(str);
    int a = num / 13 * 13;
    int b = num % 13;
    string stra, strb;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == a) {
            stra = it->first;
        }
        if (it->second == b) {
            strb = it->first;
        }
    }
    // 这题不是进制，是加法，b == 0 时不打印 strb
    if (a == 0 && b == 0) {
        return strb;
    } else if (a == 0 && b != 0) {
        return strb;
    } else if (a != 0 && b == 0) {
        return stra;
    } else {
        return stra + " " + strb;
    }
}

// hel mar -> 29
int alphaToDigit(string str) {
    size_t blankStrPos = str.find(" ");
    int res;
    if (blankStrPos != string::npos) {
        string stra, strb;
        stra = str.substr(0, blankStrPos);
        strb = str.substr(blankStrPos + 1, str.length());
        res = mp[stra] + mp[strb];
    } else {
        res = mp[str];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        // cout << "-- " << str << endl;
        if (isdigit(str[0])) {
            cout << digitToAlpha(str) << endl;
        } else {
            cout << alphaToDigit(str) << endl;
        }
    }
    return 0;
}
