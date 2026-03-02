#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
char sequ[maxn];
int ha[maxn][maxn];

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        memset(ha, 0, sizeof ha);
        int n; scanf("%d", &n);
        scanf("%s", sequ);
        int idxl = 0, idxr = 0;
        ha[idxl][idxr]++;
        for (int i = 0; i < n; ++i) {
            if (sequ[i]  == 'L')
                ha[--
        }
    }
    return 0;
}
