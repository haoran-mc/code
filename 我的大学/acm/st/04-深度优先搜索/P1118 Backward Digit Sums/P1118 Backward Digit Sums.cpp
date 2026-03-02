/*----------------------------------------------------------------
 *
 *   文件名称：P1118 Backward Digit Sums.cpp
 *   创建日期：2020年09月14日 ---- 15时58分
 *   结束日期：2020年09月15日 ---- 17时22分
 *   题    目：luogu
 *   算    法：深度优先搜索
 *   描    述：我也写一遍题解中那种算法
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 12;
int n;
int sum1;
int triangle[maxn];
bool hashTable[maxn] = {false};
int ans[maxn];

bool DFS(int index, int num, int sum2) {
    if (sum2 > sum1)
        return false;

    if (index == n) {
        if (sum2 == sum1) {
            ans[index] = num;
            return true;
        }
        else
            return false;
    }

    hashTable[num] = true;
    for (int i = 1; i <= n; i++) {
        if (hashTable[i] == false && DFS(index + 1, i, sum2 + triangle[index] * i) == true) {
            ans[index] = num;
            return true;
        }
    }
    hashTable[num] = false;
    return false;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &sum1);
    triangle[0] = triangle[n - 1] = 1;
    for (int i = 1; 2 * i < n; i++)
        triangle[i] = triangle[n-i-1] = (n-i) * triangle[i-1] / i;

    if (DFS(0, 0, 0) == true)
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);

    return 0;
}
