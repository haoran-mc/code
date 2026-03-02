/*----------------------------------------------------------------
 *
 *   文件名称：A冒泡排序.cpp
 *   创建日期：2020年09月24日 ---- 23时07分
 *   题    目：<++>
 *   算    法：冒泡排序
 *   描    述：A题需要知道剪枝的冒泡排序
 *
----------------------------------------------------------------*/

#include <cstdio>

void bubbleSort(int arr[], int n) {
    int count = 0;
    int condition = (n * (n - 1) / 2);
    for (int i = n-1; i > 0; i--) {
        bool flag = true;
        for (int j = 1; j < i; j++) {
            if (arr[j-1] > arr[j]) {
                arr[j-1] += arr[j];
                arr[j]    = arr[j-1] - arr[j];
                arr[j-1] -= arr[j];
                count++;
                flag = false;
            }
            if (flag == true || count == condition + 1)
                break;
        }
    }
    if (count <= condition)
        printf("YES\n");
    else
        printf("NO\n");
}

