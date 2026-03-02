#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        string str;
        int n;
        int k;
        scanf("%d", &n);
        scanf("%d", &k);
        string abc = "abc";
        for (int i = 0; i < n-k+1;) {
            str += abc;
            i += 3;
            int m = i;
            while (m-- > n-k+1)
                str.erase(str.end()-1);
        }
        for (int i = 0; i < k-1; ++i)
            str.insert(0, "a");
        cout << str << endl;
    }
    return 0;
}
