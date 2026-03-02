/*----------------------------------------------------------------
 *
 *   文件名称：A-solution.cpp
 *   创建日期：2020年09月29日 ---- 19时49分
 *   题    目：codeforces
 *   算    法：no
 *   描    述：只有当输入中的所有数都不相等且逆序排列时才会输出"NO"
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>

int arr[100000];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(arr, 0, n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        bool flag = false;
        for (int i = 0; i < n-1; i++)
            if (arr[i + 1] >= arr[i])
                flag = true;
        if (flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
