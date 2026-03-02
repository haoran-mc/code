#include <cstdio>
#define NEXTLINE puts("");

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        printf("0 ");
        int res = 0;
        for (int i = n - 1; i > 0; --i) {
            res += i;
            printf("%d ", res);
        }
        NEXTLINE;
    }
    return 0;
}
