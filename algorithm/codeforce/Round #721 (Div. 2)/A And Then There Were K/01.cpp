#include <cstdio>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int res = n;
        while (res != 0)
            res &= (--n);
        printf("%d\n", n);
    }
    return 0;
}
