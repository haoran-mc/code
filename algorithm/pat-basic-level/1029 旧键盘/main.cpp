#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

string o, p;
map<char, int> mp;

int main() {
    cin >> o >> p;
    for (int i = 0; i < p.length(); i++) {
        mp[tolower(p[i])] = 1;
    }

    // for (auto it = mp.begin(); it != mp.end(); it++) {
    //     printf("%c", it->first, it->second);
    // }
    // printf("\n");

    for (int i = 0; i < o.length(); i++) {
        if (mp.find(tolower(o[i])) == mp.end()) {
            mp[tolower(o[i])] = 1;
            printf("%c", toupper(o[i]));
        }
    }
    printf("\n");
    return 0;
}
