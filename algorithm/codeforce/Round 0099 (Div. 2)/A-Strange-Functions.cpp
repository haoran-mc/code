#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        string str;
        cin >> str;
        printf("%d\n", (int)str.length());
    }
    return 0;
}
