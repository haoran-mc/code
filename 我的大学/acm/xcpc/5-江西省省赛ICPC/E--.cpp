#include <cstdio>
#include <cstring>
#define bug printf("******\n");
const int maxn = 1e6+5;
int hash[21];
int color[maxn];
bool judge() {
    for (int i = 0; i < 21; ++i)
        if (hash[i])
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &color[i]);
    int sum0 = 0;
    int sum1 = 0;
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            if (hash[color[i]]) {
                hash[color[i]] = 0;
                if (judge())
                    sum0++;
            }
            else
                hash[color[i]]++;
        }
    }
    sum0 = (sum0 * (sum0 - 1) / 2) + sum0;
    memset(hash, 0, sizeof(hash));
    for (int i = 1; i < n; i++) {
        if (hash[color[i]]) {
            hash[color[i]] = 0;
            if (judge())
                sum1++;
        }
        else
            hash[color[i]]++;
    }
    sum1 = (sum1 * (sum1 - 1) / 2) + sum1;
    int sum = sum0 + sum1;
    printf("%d\n", sum);
    return 0;
}
