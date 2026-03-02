#include <cstdio>
int arr[10] = {4, 9, 6, 1, 8, 0, 3, 7, 2, 5};
int num[10];
int n = 10;
int reg[10];

void init() {
    for (int i = 0; i < n; ++i)
        num[i] = arr[i];
}

/*冒泡排序*/
void bubbleSort() {
    for (int i = 0; i < n-1; ++i)
        for (int j = n-1; j > i; --j)
            if (num[j] < num[j-1]) {
                num[j] += num[j-1];
                num[j-1] = num[j] - num[j-1];
                num[j] -= num[j-1];
            }
}

/*选择排序*/
void selectSort() {
    int minNum;
    int index;
    bool flag;

    for (int i = 0; i < n; ++i) {
        flag   = false;
        minNum = num[i];
        index  = i;
        for (int j = i; j < n; ++j)
            if (num[j] < minNum) {
                flag   = 1;
                minNum = num[j];
                index  = j;
            }
        if (flag) {
            num[i] += num[index];
            num[index] = num[i] - num[index];
            num[i] -= num[index];
        }
    }
}

/*插入排序*/
void insertSort() {
    int insertNum;
    for (int i = 0; i < n; ++i) {
        insertNum = num[i];
        int j;
        for (j = i; insertNum < num[j-1]; --j)
            num[j] = num[j-1];
        num[j] = insertNum;
    }
}

/*归并排序*/
void mergeSort(int start = 0, int end = n-1) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    mergeSort(start1, end1);
    mergeSort(start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = num[start1] <= num[start2] ? num[start1++] : num[start2++];
    while (start1 <= end1)
        reg[k++] = num[start1++];
    while (start2 <= end2)
        reg[k++] = num[start2++];
    for (k = start; k <= end; k++)
        num[k] = reg[k];
}

void output() {
    for (int i = 0; i < n; ++i)
        printf("%d ", num[i]);
    printf("\n");
}

int main() {
    init();
    bubbleSort();
    output();

    init();
    selectSort();
    output();

    init();
    insertSort();
    output();

    init();
    mergeSort();
    output();
    return 0;
}
