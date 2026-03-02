/*----------------------------------------------------------------
 *
 *   文件名称：luogu UVA572 油田 Oil Deposits.cpp
 *   创建日期：2020年09月12日 ---- 15时38分
 *   结束日期：2020年09月12日 ---- 16时49分
 *   题    目：luogu
 *   算    法：广度优先搜索
 *   描    述：模板，和算法笔记上的一样，换个变量名就行了
 *             1. 定义一个二维字符数组gird，一个布尔型二维数组inq(in queue)
 *             2. 两个二维数组用于记录输入的油田信息和记住已通过深度优先搜索发现的油田块
 *             3. 对于每个未被inq记住的油田位置，使用广度优先搜索将它周围的油田全部记住
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 101;
struct position {
    int x;
    int y;
};
int m;
int n;
char grid[maxn][maxn];
bool inq[maxn][maxn] = {false};
int nextX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int nextY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool judge(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;

    if (grid[x][y] == '*' || inq[x][y] == true)
        return false;

    return true;
}

void BFS(int x, int y) {
    queue<position> quu;
    position pos;
    pos.x = x;
    pos.y = y;
    quu.push(pos);
    inq[x][y] = true;
    while (quu.empty() == false) {
        position top = quu.front();
        quu.pop();
        for (int i = 0; i < 8; i++) {
            int newX = top.x + nextX[i];
            int newY = top.y + nextY[i];
            if (judge(newX, newY) == true) {
                pos.x = newX;
                pos.y = newY;
                quu.push(pos);
                inq[newX][newY] = true;
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &m, &n) && (m != 0 && n != 0)) {
        int sumDeposits = 0;
        memset(inq, 0, sizeof(inq));
        for (int i = 0; i < m; i++) {
            getchar();
            for (int j = 0; j < n; j++)
                scanf("%c", &grid[i][j]);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '@' && inq[i][j] == false)
                    (sumDeposits++, BFS(i, j));

        printf("%d\n", sumDeposits);
        /*
         *for (int i = 0; i < m; i++) {
         *    for (int j = 0; j < n; j++)
         *        printf("%d ", inq[i][j]);
         *    printf("\n");
         *}
         */
    }
    return 0;
}
