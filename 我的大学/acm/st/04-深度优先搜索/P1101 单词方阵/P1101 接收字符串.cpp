/*----------------------------------------------------------------
 *
 *   文件名称：luogu P1101 单词方阵.cpp
 *   创建日期：2020年09月13日 ---- 16时22分
 *   结束日期：2020年09月14日 ---- 14时54分
 *   题    目：luogu
 *   算    法：深度优先搜索
 *   描    述：不是单个字符接收，而是接收字符串
 *             1. 在整个输入中找'y'
 *                 1. 如果找到，在它周围找'i'
 *                     1. 如果找到，进入DFS
 *                     2. 如果没找到，继续在输入中找'y'
 *                 2. 如果没找到，继续在输入中找'y'
 *             2. DFS需要的参数有
 *                 1. nowX当前位置横坐标
 *                 2. nowY当前位置纵坐标
 *                 3. 已匹配到的位置pointer
 *                 4. 字串的方向
 *             3. DFS中如果所有字符都匹配，就使用布尔型二维数组find记住这些位置
 *             4. 遍历find数组，将input中与true相对应的位置原样输出
 *             5. 将input中与false相对应的位置输出'*'
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 101;
char key[] = "yizhong";
char input[maxn][maxn];
bool find[maxn][maxn] = {false};
int nextX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int nextY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int n;

void DFS(int nowX, int nowY, int pointer, int dir) {
    if (pointer > 6) {
        nowX -= 7 * nextX[dir];
        nowY -= 7 * nextY[dir];
        for (int i = 0; i < 7; i++) {
            find[nowX][nowY] = true;
            nowX += nextX[dir];
            nowY += nextY[dir];
        }
    }
    else {
        nowX += nextX[dir];
        nowY += nextY[dir];
        pointer++;
        if (pointer == 7 || input[nowX][nowY] == key[pointer]) {
            DFS(nowX, nowY, pointer, dir);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", input[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (input[i][j] == 'y')
                for (int dir = 0; dir < 8; dir++)
                    if (input[i + nextX[dir]][j + nextY[dir]] == 'i')
                        DFS(i, j, 0, dir);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (find[i][j] == true)
                printf("%c", input[i][j]);
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}
