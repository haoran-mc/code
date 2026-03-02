#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;
string str1[50000];
string str2[50000];
int c1 = -1, c2 = -1;

void bubbleSort(string str[], int n) {
    for (int i = 0; i < n; ++ i)
        for (int j = n - 1; j > i; -- j)
            if (str[j] < str[j - 1])
                swap(str[j - 1], str[j]);
}

void quickSort(string str[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1;
    string x = str[(l + r) >> 1];   // 哨兵
    while (i < j) {
        do i ++ ; while (str[i] < x);
        do j -- ; while (str[j] > x);
        if (i < j) swap(str[i], str[j]);
    }
    quickSort(str, l, j);
    quickSort(str, j + 1, r);
}

void gettimeofday() {
    if (c1 == -1) {
        c1 = clock();
    } else if (c2 == -1) {
        c2 = clock();
        printf("time: %f\n", (double)(c2 - c1) / CLOCKS_PER_SEC);
    } else {
        c1 = c2;
        c2 = clock();
        printf("time: %f\n", (double)(c2 - c1) / CLOCKS_PER_SEC);
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    for (int i = 0; i < 10000; i ++ ) {
        cin >> str1[i];
        str2[i] = str1[i];
    }
    gettimeofday();
    quickSort(str1, 0, 49999);
    gettimeofday();
    bubbleSort(str2, 50000);
    gettimeofday();
    return 0;
}
