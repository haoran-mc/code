#include <cstdio>
int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int res = 0;
    if (B > A) {
        B -= A;
        res += A;
        A = 0;
    }
    else {
        A -= B;
        res += B;
        B = 0;
    }
    if (C > A) {
        C -= A;
        res += A;
        A = 0;
    }
    else {
        A -= C;
        res += C;
        C = 0;
    }
    res += C / 2;
    printf("%d\n", res);
    return 0;
}
