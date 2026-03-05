/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年07月29日 星期四 00时24分27秒
 *   题    目：AcWing 0829 模拟队列
 *   算    法：队列
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int q[maxn], hh = -1, tt;  // 队头与队尾都默认是0

// 插入：q[tt++] = x;
// 弹出：++hh;

int main() {
    int t; scanf("%d", &t);
    char op[10];
    while (t--) {
        scanf("%s", &op);
        if (!strcmp(op, "push")) {
            int x; scanf("%d", &x);
            q[tt++] = x;
        }
        else if (!strcmp(op, "pop")) {
            ++hh;
        }
        else if (!strcmp(op, "empty")) {
            printf(hh == tt - 1 ? "YES\n" : "NO\n");
        }
        else if (!strcmp(op, "query")) {
            printf("%d\n", q[hh+1]);
        }
    }
    return 0;
}
