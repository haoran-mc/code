/*----------------------------------------------------------------
 *
 *   文件名称：luogu P1101 单词方阵.cpp
 *   创建日期：2020年09月13日 ---- 16时22分
 *   题    目：luogu
 *   算    法：深度优先搜索
 *   描    述：CSDN代码
 *
----------------------------------------------------------------*/

#include <cstdio>

char keyword[] = "yizhong";
char square[101][101]; //输入数组
char book[101][101];    //记录变化的数组
int drive[8][2]={{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};//八方向数组
int n;
struct road {    //记录路径的结构体
    int x;
    int y;
} way[7];

//dir是方向，搜索的方向，x，y是开始搜索的坐标，state当前搜索到了第几个字母
void dfs(int x, int y, int state ,int dir) {
   if (state > 6)
       for(int i = 0; i < 7; i++)  //如果搜索完了，说明所求的就是想要的
           book[way[i].x][way[i].y] = 1; //记录路径

   else if (state <= 6) {
       int dx = x + drive[dir][0];
       int dy = y + drive[dir][1];

       //如果state等于6，说明已经搜索完了
       if (state == 6 || square[dx][dy] == keyword[state+1]) {
           way[state].x = x;    //记录路径
           way[state].y = y;
           dfs(dx, dy, state + 1, dir);  //搜索下个节点，如果修改了state的值下面，如state++，下面就要加一行state--，以达到回溯的目的，这里偷懒了，就直接state+1了
       }
   }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < n; j++)
            scanf("%c", &square[i][j]);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (square[i][j] == 'y')
               for (int k = 0; k < 8; k++)
                   if (square[i+drive[k][0]][j+drive[k][1]] == 'i')
                       dfs(i, j, 0, k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(book[i][j])
                printf("%c", square[i][j]);
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

