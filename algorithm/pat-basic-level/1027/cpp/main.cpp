#include <cstdio>

int main() {
    int n;
    char ch;
    scanf("%d %c", &n, &ch);

    int sum = -1;
    int max_col = 0;
    int reminder = 0;
    for (int i = 1;; i += 2) {
        sum += 2 * i;
        if (sum > n) {
            break;
        }
        max_col = i;
        reminder = n - sum;
    }

    // max_col -> 1
    for (int i = 0; i < (max_col + 1) / 2; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < max_col - 2 * i; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    for (int i = (max_col + 1) / 2 - 2; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < max_col - 2 * i; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    printf("%d\n", reminder);
    return 0;
}
