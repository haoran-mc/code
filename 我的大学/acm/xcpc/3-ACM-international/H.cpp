#include <cstdio>
#include <cmath>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int area;
        scanf("%d", &area);
        printf("%d\n", (int)sqrt(area/6.0));
    }
    return 0;
}
