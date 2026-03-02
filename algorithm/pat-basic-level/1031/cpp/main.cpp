#include <cstdio>
#include <cstring>

int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
    int n;
    scanf("%d", &n);

    bool f = false;

    while (n--) {
        char str[50];
        scanf("%s", str);

        int sum = 0;
        for (int i = 0; i < (int)strlen(str) - 1; i++) {
            sum += (str[i] - '0') * w[i];
        }

        int z = sum % 11;

        if (str[strlen(str) - 1] != m[z]) {
            f = true;
            printf("%s", str);
            if (n != 0) {
                printf("\n");
            }
        }
    }

    if (!f) {
        printf("All passed");
    }
    return 0;
}
