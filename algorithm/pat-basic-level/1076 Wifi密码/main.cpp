// 260306 14:03 Fri
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string res = "";
    for (int i = 0; i < N; i++) {
        string str;
        getline(cin, str);
        int pos = str.find("T");

        char ques = str[pos - 2];
        if (ques == 'A')
            res += '1';
        else if (ques == 'B')
            res += '2';
        else if (ques == 'C')
            res += '3';
        else if (ques == 'D')
            res += '4';
    }
    cout << res;
    return 0;
}
