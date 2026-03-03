#include <cstdio>

int main() {
    int n;
    char ch;
    scanf("%d %c", &n, &ch);

    // 第一行
    for (int i = 0; i < n; i++)
        printf("%c", ch);
    printf("\n");

    // 有多少行？
    int col = n / 2;
    if (n % 2 == 1) {
        col++;
    }

    for (int i = 0; i < col - 2; i++) {
        printf("%c", ch);
        for (int j = 0; j < n - 2; j++)
            printf(" ");
        printf("%c\n", ch);
    }

    for (int i = 0; i < n; i++)
        printf("%c", ch);
    printf("\n");
    return 0;
}
