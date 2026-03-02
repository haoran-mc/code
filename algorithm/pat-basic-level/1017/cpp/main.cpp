#include <cstdio>
#include <cstring>
const int maxn = 1000 + 5;

int main() {
    char a[maxn];
    int b;
    scanf("%s %d", a, &b);

    char quotient[maxn];
    int remainder;

    if (strlen(a) == 1 && a[0] - '0' < b) {
        printf("0 %d", a[0] - '0');
        return 0;
    }

    int q = 0; // quotient
    int idx = 0;
    for (int i = 0; i < strlen(a); i++) {
        q = q * 10 + (a[i] - '0');
        int res = q / b;
        if (!(i == 0 && res == 0)) {
            quotient[idx] = res + '0';
            idx++;
        }
        q %= b;
    }
    quotient[idx] = '\0';
    remainder = q;
    printf("%s %d\n", quotient, remainder);
    return 0;
}
