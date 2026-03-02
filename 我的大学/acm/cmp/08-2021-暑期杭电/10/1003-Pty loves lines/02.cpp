#include <cstdio>
#include <cstring>
#define NEXTLINE puts("");
#define bug printf("<-->\n");
const int maxn = 1e6;
bool ha[maxn];
int n;

void solve(int x) {
    int res = 0;
    res += (x - 1) * ((n - 1) - (x - 1));
    for (int i = x - 1; i > 0; -- i) {
        res += i;
        ha[res] = true;;
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        memset(ha, 0, sizeof ha);
        scanf("%d", &n);
        printf("0 ");
        for (int i = n; i >= 0; --i)
            solve(i);
        for (int i = 0; i < n * (n - 1) / 2 + 5; ++i)
            if (ha[i])
                printf("%d ", i);
        NEXTLINE;
    }
    return 0;
}
