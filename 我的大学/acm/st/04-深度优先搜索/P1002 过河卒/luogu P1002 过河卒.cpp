/*----------------------------------------------------------------
 *
 *   文件名称：luogu P1002 过河卒.cpp
 *   创建日期：2020年09月13日 ---- 15时01分
 *   结束日期：2020年09月13日 ---- 15时53分
 *   题    目：luogu
 *   算    法：深度优先搜索
 *   描    述：超时，没有优化
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 21;
/*int coord[maxn][maxn];*/
int m;
int n;
int horseX;
int horseY;
int controlX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int controlY[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int route = 0;

bool control(int x, int y) {
    if (x == horseX && y == horseY)
        return true;

    int flag = 0;
    for (int i = 0; i < 8; i++)
        if (x == horseX + controlX[i] && y == horseY + controlY[i])
            flag = 1;

    if (flag == 1)
        return true;

    return false;
}

bool judge(int x, int y) {
    if (x < 0 || x > m || y < 0 || y > n)
        return false;

    if (control(x, y) == true)
        return false;

    return true;
}

void DFS(int nowX, int nowY) {
    if (judge(nowX, nowY) == false)
        return ;

    if (nowX == m && nowY == n) {
        route++;
        return ;
    }

    DFS(nowX + 1, nowY);
    DFS(nowX, nowY + 1);
}

int main()
{
    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &horseX);
    scanf("%d", &horseY);
    DFS(0, 0);
    printf("%d\n", route);
    return 0;
}
