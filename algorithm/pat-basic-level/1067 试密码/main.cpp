// 260303 11:03 Tue
#include <iostream>
#include <string>
using namespace std;

int main() {
    string correctPass;
    int N;
    cin >> correctPass >> N;

    string str;
    int i = 0;
    cin.ignore();
    while (true) {
        getline(cin, str);

        if (str == "#")
            break;

        if (str == correctPass) {
            cout << "Welcome in" << endl;
            break;
        } else {
            cout << "Wrong password: " << str << endl;
        }

        if (++i == N) {
            cout << "Account locked" << endl;
            break;
        }
    }
    return 0;
}
