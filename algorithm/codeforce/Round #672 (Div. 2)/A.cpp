/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年09月24日 ---- 22时46分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 5e4;
int arr[maxn];

int bubbleSort(int n, int condition) {
    int count = 0;
    for (int i = n-1; i > 0; i--) {
        bool flag = true;
        for (int j = 1; j <= i; j++) {    //*
            if (arr[j-1] > arr[j]) {
                arr[j-1] += arr[j];
                arr[j]    = arr[j-1] - arr[j];
                arr[j-1] -= arr[j];
                count++;
                flag = false;
            }
            if (count == condition + 1)
                break;
        }
        if (flag == true || count == condition + 1)
            break;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int condition = n / 2 * (n - 1) - 1;
        int count = bubbleSort(n, condition);
        if (count <= condition)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
