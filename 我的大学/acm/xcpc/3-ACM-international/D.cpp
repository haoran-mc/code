#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int len;
        scanf("%d", &len);
        int ans = 0;
        int num;
        for (int i = 0; i < len; i++) {
            scanf("%d", &num);
            if (num != 0)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
