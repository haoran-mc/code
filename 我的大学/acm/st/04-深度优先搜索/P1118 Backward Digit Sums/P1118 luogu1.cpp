/*----------------------------------------------------------------
 *
 *   文件名称：P1118 luogu1.cpp
 *   创建日期：2020年09月15日 ---- 15时58分
 *   题    目：luogu
 *   算    法：深度优先搜索
 *   描    述：洛谷题解1
 *
----------------------------------------------------------------*/

#include <cstdio>

int n;
int sum1;
bool visited[25];
int ans[25];
int triangle[25];

/* pointer 匹配到第pointer个数
 * num     第pointer个数
 * sum2    已经得到的和
 * */
bool DFS(int pointer, int num, int sum2) {
    //一旦这组数的和大于sum1，停止深搜
    if (sum2 > sum1)
        return false;

    //搜索到最后一个数
    if (pointer == n) {
        if (sum2 == sum1) {
            ans[pointer] = num;
            return true;
        }
        else
            return false;
    }

    //既没有搜索到最后一个数，也没有超过sum1
    visited[num] = true;
    //下一个
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false && DFS(pointer+1, i, sum2 + triangle[pointer] * i)) {
            ans[pointer] = num;
            return true;
        }
    }
    visited[num] = false;
    return false;
}

int main()
{
    scanf("%d%d", &n, &sum1);
    triangle[0] = triangle[n-1] = 1;
    for (int i = 1; i*2 < n; i++)
        triangle[i] = triangle[n-1-i] = (n-i) * triangle[i-1] / i;

    if (DFS(0, 0, 0) == true)
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);

    return 0;
}
