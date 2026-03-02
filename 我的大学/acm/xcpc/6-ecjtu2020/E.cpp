#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> vec;
int main()
{
    int n;
    int m;
    while (scanf("%d%d", &n, &m) != EOF) {
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;

            for (int j = 0; j < (int)str.length(); ++j)
                if (str[j] > 'z' || str[j] < 'a')
                    flag = true;

            vec.push_back(str);
        }
        for (int i = 0; i < n-1; ++i) {
            if (vec[i] > vec[i+1]) {
                flag = true;
                break;
            }
            else
                continue;
        }
        if (!flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
