/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月14日 星期五 02时39分28秒
 *   题    目：AcWing 95 费解的开关
 *   算    法：递推
 *   描    述：yxc
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
#define NEXTLINE puts("");
char g[10][10];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};

void turn(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int nowX = x + dx[i];
        int nowY = y + dy[i];
        if (nowX < 5 && nowX >= 0 && nowY < 5 && nowY >= 0)
            g[nowX][nowY] ^= 1;
    }
}

int work() {
    int res = inf;
    for (int k = 0; k < 1 << 5; ++k) { //枚举第一行的所有状态
        int op = 0;
        char backup[10][10];
        memcpy(backup, g, sizeof g);
        /*
         * 根据枚举的第一行的状态，去按开关
         * 这里的k是按第一行，并不是说第一行是0我就按或者第一行是1我就不按
         */
        for (int j = 0; j < 5; ++j)
            if (k >> j & 1) {
                ++op;
                turn(0, j);
            }
        for (int i = 0; i < 4; ++i) //遍历前n-1行，是0我就按下一行，让这个0变为1
            for (int j = 0; j < 5; ++j)
                if (g[i][j] == '0') {
                    ++op;
                    turn(i + 1, j);
                }
        bool is_successful = true;
        for (int j = 0; j < 5; ++j) //判断最后一行是否全1，如果是，说明当前方案可行，否则不可行
            if (g[4][j] == '0') {
                is_successful = false;
                break;
            }
        if (is_successful)
            res = min(res, op);
        memcpy(g, backup, sizeof backup);
    }
    if (res > 6)
        res = -1;
    return res;
    }

    int main() {
#ifndef ONLINE_JUDGE
        // freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
#endif
        int t;
        scanf("%d", &t);
        while (t--) {
            for (int i = 0; i < 5; ++i)
                scanf("%s", g[i]);
            printf("%d\n", work());
        }
        return 0;
    }
