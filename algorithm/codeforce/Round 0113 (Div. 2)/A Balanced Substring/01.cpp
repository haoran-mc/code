/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年09月08日 星期三 23时01分55秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：只要有子串 ab 或 ba 就满足了，输出它俩下标
 *
 ----------------------------------------------------------------*/

#include <cstdio>
int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int n; scanf("%d", &n);
        char str[100]; scanf("%s", str);

        bool flag = false;
        for (int i = 0; i < n - 1; ++i) 
            if (str[i] != str[i + 1]) {
                flag = true;
                printf("%d %d\n", i + 1, i + 2);
                break;
            }
        if (!flag) 
            printf("-1 -1\n");
    }
    return 0;
}
