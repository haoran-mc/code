#include <cstdio>

int main() {
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);
    int num;
    scanf("%d", &num);

    int w[3];
    for (int i = 0; i < 3; i++) {
        w[i] = num % 10;
        num /= 10;
    }

    for (int i = 2; i >= 0; i--) {
        if (w[i] == 0) {
            continue;
        }
        for (int j = 0; j < w[i]; j++) {
            if (i == 2) {
                printf("B");
            } else if (i == 1) {
                printf("S");
            } else if (i == 0) {
                printf("%d", j+1);
            }
        }
    }

    return 0;
}
