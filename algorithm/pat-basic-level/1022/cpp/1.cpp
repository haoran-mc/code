#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string res;
int idx = 0;

int main() {
    int num1, num2;
    int base;
    scanf("%d %d %d", &num1, &num2, &base);

    int sum = num1 + num2;
    if (sum == 0) {
        printf("0\n");
        return 0;
    }

    while (sum != 0) {
        const char x = sum % base + '0';
        printf("%d %c\n", sum, x);
        res.insert(idx++, &x);
        sum /= base;
    }
    for (auto it = res.begin() + idx - 1; it != res.begin() - 1; --it)
        cout << *it;
    cout << endl;
    return 0;
}
