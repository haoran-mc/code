/*----------------------------------------------------------------
 *   
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月12日 星期三 13时34分59秒
 *   结束日期：2021年05月12日 星期三 13时35分01秒
 *   题    目：AcWing 93 递归实现组合型枚举
 *   算    法：递归，状态压缩
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define NEXTLINE puts("");
int n, m;

void DFS(int u, int cnt, int state) {
    if (cnt + n - u < m)
        return ;
    if (cnt == m) {
        for (int i = 0; i < n; ++i)
            if (state >> i & 1)
                printf("%d ", i + 1);
        NEXTLINE;
        return ;
    }
    DFS(u + 1, cnt + 1, state | 1 << u);
    DFS(u + 1, cnt, state);
}

int main() {
    scanf("%d %d", &n, &m);
    DFS(0, 0, 0);
    return 0;
}
