#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int odd  = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        num & 1 ? ++odd : ++even;
    }
    int flag = 1;
    while (odd + even > 1) {
        if (flag & 1) {
            ++flag;
            if (even)
                --even;
            else
                --odd;
        }
        else {
            ++flag;
            if (odd >= 2)
                odd -= 2, ++even;
            else if (odd == 1)
                --odd;
            else
                break;
        }
    }
    if (!odd) printf("NiuMei\n");
    else printf("NiuNiu\n");
    return 0;
}
