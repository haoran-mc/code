/*----------------------------------------------------------------
 *
 *   文件名称：B1.cpp
 *   创建日期：2020年09月20日 ---- 21时27分
 *   题    目：nowcoder
 *   算    法：打表
 *   描    述：之前那个文件被写的乱了，新建一个
 *             还不行，太慢了，电脑吼不住
 *
----------------------------------------------------------------*/

#include <cstdio>

bool coord[100][100] = {false};
bool rem[100][100] = {false};

void buildCoord(int x, int y) {
    if (rem[x][y] == true)
        return ;

    rem[x][y] = true;
    if (x > 100 + 1 || y > 100 + 1)
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
    int t;
    scanf("%d", &t);
    buildCoord(0, 0);
    while (t--) {
        int x;
        int y;
        scanf("%d", &x);
        scanf("%d", &y);
        if (coord[x][y] == true)
            printf("yyds\n");
        else
            printf("awsl\n");
    }
    return 0;
}
