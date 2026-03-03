#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        int alpha = tolower(str[i]) - 'a' + 1;
        if (alpha >= 1 && alpha <= 26)
            sum += alpha;
    }

    int cnt1 = 0, cnt0 = 0;
    while (sum) {
        if (sum % 2)
            cnt1++;
        else
            cnt0++;

        sum /= 2;
    }
    cout << cnt0 << " " << cnt1 << endl;
    return 0;
}
