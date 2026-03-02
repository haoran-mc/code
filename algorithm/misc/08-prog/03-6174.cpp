#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b; //当 a > b 时将a放在前面
}

void to_array(int n, int num[]) {
    for (int i = 0; i < 4; i++) {
        num[i] = n % 10;
        n /= 10;
    }
}

int to_number(int num[]) {
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum = 10 * sum + num[i];

    return sum;
}

int main() {
    int n;
    int maxi;
    int mini;
    scanf("%d", &n);
    int num[5];

    while (1) {
        to_array(n, num);
        sort(num, num + 4);
        mini = to_number(num);

        sort(num, num + 4, cmp);
        maxi = to_number(num);

        n = maxi - mini;
        printf("%04d - %04d = %04d\n", maxi, mini, n);

        if (n == 0 || n == 6174)
            break;
    }
    return 0;
}
