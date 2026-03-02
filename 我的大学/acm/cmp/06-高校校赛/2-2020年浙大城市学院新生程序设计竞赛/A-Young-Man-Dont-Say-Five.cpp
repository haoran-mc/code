#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string str;
    cin >> str;
    int pos = str.find("5");
    while (pos != (int)string::npos) {
        str.replace(pos, 1, "*");
        pos = str.find("5", pos+0);
    }
    cout << str << endl;
    return 0;
}
