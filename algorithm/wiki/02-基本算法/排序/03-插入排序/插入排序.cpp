

// 2021年08月08日 星期日 23时51分03秒
// 如果 num[i] 比前面一位小，就让前面的数往后移，直到找到 num[i] 应该在的位置

#include <stdio.h>
int num[] = {9, 7, 8, 6, 5, 4, 3, 2, 1, 0};
int n = 10;

void insertSort() {
    for (int i = 1; i < n; i++) {
        int insertNum = num[i];

        int j = i - 1;
        for (; j >= 0; j--) {
            if (num[j] > insertNum) {
                num[j + 1] = num[j];
            } else {
                break;
            }
        }
        num[j + 1] = insertNum;
    }
}

void insertSort1() {
    int insertNum;

    for (int i = 0; i < n; i++) {
        insertNum = num[i];
        int j;
        for (j = i; insertNum < num[j - 1]; j--) {
            num[j] = num[j - 1];
        }
        num[j] = insertNum;
    }
}

void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    insertSort();
    for (int i = 0; i < n; i++)
        printf("%d ", num[i]);

    printf("\n");
    return 0;
}
