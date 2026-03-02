#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int ping;
        int pong;
        scanf("%d", &ping);
        scanf("%d", &pong);
        if (ping == pong)
            printf("%d %d\n", ping - 1, pong);
        else if (ping < pong)
            printf("%d %d\n", ping - 1, pong);
        else if (ping > pong)
            printf("%d %d\n", ping - 1, pong);
    }
    return 0;
}
