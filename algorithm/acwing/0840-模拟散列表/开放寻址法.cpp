/*----------------------------------------------------------------
 *
 *   文件名称：开放寻址法.cpp
 *   创建日期：2021年08月10日 星期二 23时32分33秒
 *   题    目：AcWing 0840 模拟散列表
 *   算    法：哈希
 *   描    述：I: 插入一个值x，Q: 查询一个值x是否存在
 *      一个经验值，这样的冲突会少
 *      如果题目数据范围在1e5，那么开放寻址法开的数组在2e5 ~ 3e5左右
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int N = 200003;   // 这是大于2e5的最小的质数，写个循环找一下就可以
const int null = 0x3f3f3f3f;
int ha[N];

int find(int x) {
    int k = (x % N + N) % N;
    while (ha[k] != null && ha[k] != x) {
        k ++;
        if (k == N)
            k = 0;
    }
    return k;   // 如果x在哈希表中，k是x的下标；如果x不在哈希表中，k是x可以插入的位置
}

int main() {
    int n; scanf("%d", &n);
    memset(ha, 0x3f, sizeof ha);
    while (n --) {
        char op[2];
        int x;
        scanf("%s %d", op, &x);
        int k = find(x);
        if (*op == 'I')
            ha[k] = x;
        else {
            if (ha[k] != null)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
