#include <stdio.h>

// 第一个大于val的位置
int lower_bound(int num[], int left, int right, int val) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;

        if (num[mid] >= val)
            right = mid;

        else
            left  = mid + 1;
    }

    return left;
}

int main() {
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", lower_bound(num, 0, 9, 5));
    return 0;
}
