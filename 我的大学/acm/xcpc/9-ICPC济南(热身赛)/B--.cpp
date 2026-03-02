#include <cstdio>
int a[100005];
int hsah[200005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j) {
            if (hsah[a[i] ^ a[j]]){
                printf("Yes\n");
                return 0;
            }
            hsah[a[i] ^ a[j]]++;
        }
    printf("No\n");
    return 0;
}
