#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int sum = n;
    char str1[105];
    char str2[105];
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%c", &str1[i]);
    }
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%c", &str2[i]);
    }
    for (int i = 0; i < n; ++i)
        if (str1[i] == str2[i])
            ++sum;
    printf("%d %d\n", sum, 0);
    return 0;
}
