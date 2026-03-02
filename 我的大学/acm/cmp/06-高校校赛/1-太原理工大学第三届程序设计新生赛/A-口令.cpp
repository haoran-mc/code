#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string str;
    string key = " txdy!";
    getline(cin, str);
    str += key;
    cout << str << endl;
    return 0;
}
