#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    long double res = 0.0, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        // 应该用乘法，不应该用加法
        res += num * (i + 1) * (n - i);
    }
    printf("%.2Lf", res);
    return 0;
}
