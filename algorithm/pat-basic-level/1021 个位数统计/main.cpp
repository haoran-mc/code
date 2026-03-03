#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 1000 + 5;
char str[maxn];
map<char, int> mp;

int main() {
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        mp[str[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        printf("%c:%d\n", it->first, it->second);
    }
    return 0;
}
