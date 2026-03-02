#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int ha[255];

int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            str[i] = tolower(str[i]);
            ha[tolower(str[i])]++;
        }
    }
    int maxi = -1;
    int max_idx = -1;
    for (int i = 0; i < 255; i++) {
        if (ha[i] > maxi) {
            maxi = ha[i];
            max_idx = i;
        }
    }
    printf("%c %d\n", max_idx, maxi);
    return 0;
}
