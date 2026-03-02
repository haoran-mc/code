#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[5];
    memset(arr, 0, sizeof(arr)); // 清空

    while (true) {
        for (int i = 0; n != 0; i++) {
            arr[i] = n % 10;
            n /= 10;
        }

        sort(arr, arr + 4);
        int small = 0;
        for (int i = 0; i < 4; i++) {
            small *= 10;
            small += arr[i];
        }

        reverse(arr, arr + 4);
        int big = 0;
        for (int i = 0; i < 4; i++) {
            big *= 10;
            big += arr[i];
        }

        n = big - small;
        printf("%04d - %04d = %04d\n", big, small, n);
        if (n == 0 || n == 6174) {
            break;
        }
    }
    return 0;
}
