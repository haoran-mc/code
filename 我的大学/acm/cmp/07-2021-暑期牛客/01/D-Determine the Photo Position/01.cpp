#include <iostream>
#include <string>
using namespace std;
string str;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int res = 0;
    for (int i = 0; i < n; ++i)  {
        cin >> str;
        int cnt = 0;
        for (int j = 0; j < n; ++j)  {
            if (str[j] == '0') 
                ++cnt;
            else if (str[j] == '1') {
                if (cnt >= m) 
                    res += (cnt - m + 1);
                cnt = 0;
            }
            if (str[j] == '0' && j == n-1) 
                if (cnt >= m) 
                    res += (cnt - m + 1);
        }
    }
    cin >> str;
    printf("%d\n", res);
    return 0;
}
