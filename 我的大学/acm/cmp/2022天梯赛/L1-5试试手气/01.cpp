#include <cstdio>
int fi[10], cur[10];
int main() {
    for (int i = 0; i < 6; i ++ )
        scanf("%d", &fi[i]);
    int n; scanf("%d", &n);
    n -- ;   // 下一次
    for (int i = 0; i < 6; i ++ ) {
        cur[i] = 6;
        if (cur[i] == fi[i])
            cur[i] -- ;
    }
    while (n -- ) {
        for (int i = 0; i < 6; i ++ ) {
            cur[i] -- ;
            if (cur[i] == fi[i])
                cur[i] -- ;
        }
    }
    for (int i = 0; i < 6; i ++ )
        i == 5 ? printf("%d\n", cur[i]) : printf("%d ", cur[i]);
    return 0;
}