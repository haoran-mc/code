#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define bug cout << "<------>\n";
int main() {
    string str;
    cin >> str;
    long long bits = (int)str.length();
    if (bits == 1) {
        cout << "0" << endl;
        return 0;
    }
    if (bits & 1) {
        --bits;
        bits /= 2;
        while (bits--)
            cout << "9";
        cout << endl;
        return 0;
    }
    else {
        bits /= 2;
        string sub1 = str.substr(0, bits);
        string sub2 = str.substr(bits, bits);
        if (sub2 >= sub1)
            cout << sub1 << endl;
        else {
            for (int i = bits - 1; i > 0; --i) {
                if (sub1[i] == '0')
                    sub1[i] = '9';
                else {
                    --sub1[i];
                    break;
                }
            }
            cout << sub1 << endl;
        }
    }
    return 0;
}
