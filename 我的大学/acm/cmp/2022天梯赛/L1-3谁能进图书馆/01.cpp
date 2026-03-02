#include <cstdio>
int main() {
    int N, C;   // No, Company
    int q1, q2;
    scanf("%d %d %d %d", &N, &C, &q1, &q2);
    if (q1 >= N && q2 >= N) {  // 两人都可以入馆
        printf("%d-Y %d-Y\n", q1, q2);
        puts("huan ying ru guan");
    }
    else if (q1 < N && q2 < N) {  // 两人都不能入馆
        printf("%d-N %d-N\n", q1, q2);
        puts("zhang da zai lai ba");
    }
    else if (q1 >= N && q1 < C && q2 < N) {   // q1 可以进入，q2 不可进入
        printf("%d-Y %d-N\n", q1, q2);
        puts("1: huan ying ru guan");
    }
    else if (q1 < N && q2 >= N && q2 < C) {  // q2 可以进入，q1 不可进入
        printf("%d-N %d-Y\n", q1, q2);
        puts("2: huan ying ru guan");
    }
    else if (q1 >= C && q2 < N) {   // q1 照顾 q2
        printf("%d-Y %d-Y\n", q1, q2);
        puts("qing 1 zhao gu hao 2");
    }
    else if (q1 < N && q2 >= C) {   // q2 照顾 q1
        printf("%d-Y %d-Y\n", q1, q2);
        puts("qing 2 zhao gu hao 1");
    }
    return 0;
}