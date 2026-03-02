#include <cstdio>
const int maxn = 1e5 + 5;
int ha[105];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);
        ha[score]++;
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int score;
        scanf("%d", &score);

        if (i == k-1) {
            printf("%d\n", ha[score]);
        } else {
            printf("%d ", ha[score]);
        }

    }
    return 0;
}
