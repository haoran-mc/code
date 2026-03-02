#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
string str;
int main()
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        cin >> str;
        int bin[n];
        int res = 0;
        for (int j = 0; j < n; ++j)
            str[j] == 'n' ? bin[j] = 1 : bin[j] = 0;
        for (int j = 0; j < n; ++j)
            res += bin[j] * pow(2, n-j-1);
        printf("%d\n", res+1);
    }
    return 0;
}
