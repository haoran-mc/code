#include <cstdio>

int binarySearch(int num[], int n, int val) {
    int left  = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (left == right)
            return mid - 1;
        else if (num[mid] <= val)
            left = mid + 1;
        else if (num[mid] > val)
            right = mid - 1;
    }
    return -1;
}

int main() {
    int num[] = {0, 1, 1, 1, 1, 1, 2};
    int val = 1;
    printf("%d\n", binarySearch(num, 7, val));
    return 0;
}
