/*----------------------------------------------------------------
 *
 *   文件名称：B-牛牛和牛可乐的赌约2.cpp
 *   创建日期：2020年09月19日 ---- 21时22分
 *   题    目：nowcoder
 *   算    法：打表
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

bool coord[100][100] = {false};
bool rem[100][100] = {false};

void buildCoord(int x, int y) {
/*
 *    if (rem[x][y] == true)
 *        return ;
 *    rem[x][y] = true;
 *
 *    [>if (x < 0 || y < 0 || x > 1e9 + 1 || y > 1e9 + 1)<]
 *    if (x < 0 || y < 0 || x > 30 + 1 || y > 30 + 1)
 *        return ;
 *
 *    if (x + 1 < 30 + 1)
 *        coord[x + 1][y] = true;
 *    if (x + 2 < 30 + 1)
 *        coord[x + 2][y] = true;
 *    if (y + 1 < 30 + 1)
 *        coord[x][y + 1] = true;
 *    if (y + 2 < 30 + 1)
 *        coord[x][y + 2] = true;
 *
 *    buildCoord(x + 1, y);
 *    buildCoord(x + 2, y);
 *    buildCoord(x, y + 1);
 *    buildCoord(x, y + 2);
 */
    if (rem[x][y] == true)
        return ;
    rem[x][y] = true;

    if (x > 30 + 1 || y > 30 + 1)
        return ;

    coord[x + 1][y] = true;
    coord[x + 2][y] = true;
    coord[x][y + 1] = true;
    coord[x][y + 2] = true;
    buildCoord(x + 3, y);
    buildCoord(x, y + 3);
    buildCoord(x + 1, y + 1);
}

int main()
{
    buildCoord(0, 0);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            printf("%d ", coord[i][j]);
        }
        printf("\n");
    }

    return 0;
}
