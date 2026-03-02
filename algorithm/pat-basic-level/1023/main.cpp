#include <cstdio>
int num[10];

int main() {
    bool f = false;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
        if (!f) {
            if (i != 0 && num[i] != 0) {
                f = true;
                printf("%d", i);
                num[i]--;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < num[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
