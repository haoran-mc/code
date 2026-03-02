// 260302 15:03 Mon
#include <algorithm>
// #include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// 求三个数的最小公倍数
int lcm(int a, int b, int c) {
    int m1 = a / gcd(a, b) * b;
    int m2 = b / gcd(b, c) * c;
    return m1 / gcd(m1, m2) * m2;
}

int main() {
    int N1, M1, N2, M2, K;
    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
    if (N1 * M2 > N2 * M1) {
        swap(N1, N2);
        swap(M1, M2);
    }

    // 分母最小公倍数
    int M_lcm = lcm(M1, M2, K); // 这里不可以使用 lcm(M1, M2, gcd(M1, M2))，因为 gcd(M1, M2) 不一定是 K 的倍数

    // 整理成同分母
    int N1_ = M_lcm / M1 * N1;
    int N2_ = M_lcm / M2 * N2;

    bool isFirst = true;

    for (int i = N1_ + 1; i < N2_; i++) {
        // i / M_lcm
        int k = gcd(i, M_lcm);

        if (M_lcm / k == K) {
            if (isFirst) {
                printf("%d/%d", i / k, K);
                isFirst = false;
            } else {
                printf(" %d/%d", i / k, K);
            }
        }
    }
    printf("\n");

    return 0;
}
