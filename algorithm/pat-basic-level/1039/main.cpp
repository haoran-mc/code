#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
const int maxn = 1000 + 5;
char str1[maxn], str2[maxn];
unordered_map<char, int> umap;

int main() {
    scanf("%s", str1);
    scanf("%s", str2);

    for (int i = 0; i < strlen(str1); i++) {
        umap[str1[i]]++;
    }

    for (int i = 0; i < strlen(str2); i++) {
        umap[str2[i]]--;
    }

    int a = 0, b = 0;
    for (unordered_map<char, int>::iterator it = umap.begin(); it != umap.end(); it++) {
        if (it->second > 0) {
            a += it->second;
        } else {
            b -= it->second;
        }
    }

    if (b > 0) {
        printf("No %d\n", b);
    } else {
        printf("Yes %d\n", a);
    }
    return 0;
}
