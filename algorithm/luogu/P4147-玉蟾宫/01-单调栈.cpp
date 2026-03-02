/*----------------------------------------------------------------
 *   
 *   文件名称：01-单调栈.cpp
 *   创建日期：2021年08月03日 星期二 01时45分34秒
 *   题    目：<++>
 *   算    法：单调栈
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using std::max;
const int maxn = 1e3 + 5;
#define bug printf("<-->\n");
#define NEXTLINE puts("");
int n, m;

int stk[maxn];
int pos[maxn][maxn];
int res;

void Monotonous(int i) {
    int tt = 0;
    int width[maxn];
    for (int j = 0; j <= m; ++j) {
        if (pos[i][j] >= stk[tt]) {
            stk[++tt] = pos[i][j];
            width[tt] = 1;
        }
        else {
            int cnt = 0;
            while (tt && stk[tt] > pos[i][j]) {
                cnt += width[tt];
                res = max(res, cnt * stk[tt]);
                tt--;
            }
            stk[++tt] = pos[i][j];
            width[tt] = cnt + 1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch = ' ';
            while (ch == ' ' || ch == '\n')
                scanf("%c", &ch);

            if (ch == 'F' && i)
                pos[i][j] = pos[i-1][j] + 1;
            else if (ch == 'F')
                pos[i][j] = 1;
        }
        pos[i][m] = 0;  // 单调栈要最后都pop出来
    }

    /**
     * 对于最后一行，不就是这样一个直方图吗
     *
     *             __ __ __
     *            |  |  |  |
     *            |  |  |  |
     *    __ __ __|  |  |  |
     *   |  |  |  |  |  |  |
     *   |__|__|__|__|__|__|
     */
    for (int i = 0; i < n; ++i)
        Monotonous(i);
    printf("%d\n", res * 3);
    return 0;
}
