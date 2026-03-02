/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年09月25日 ---- 00时03分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 1e5;
int arr[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int count = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if ((arr[i] & arr[j]) >= (arr[i] ^ arr[j]))
                    count++;
        printf("%d\n", count);
    }
    return 0;
}
