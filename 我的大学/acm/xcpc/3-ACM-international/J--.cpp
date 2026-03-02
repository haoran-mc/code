#include <cstdio>

const int maxn = 1e4 + 1;
int Hash[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            Hash[num]++;
        }
        int ans = 0;
        for (int i = 0; i < maxn - 1; i++)
            if (Hash[i] + Hash[i + 1] > ans)
                ans = Hash[i] + Hash[i + 1];

        printf("%d\n", ans);
        for (int i = 0; i < maxn; i++)
            Hash[i] = 0;
    }
    return 0;
}
