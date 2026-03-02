#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 605;
double radiux[maxn];
#define bug printf("<------>\n");

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &radiux[i]);
            radiux[i] = radiux[i] * radiux[i] - 1;
            if (radiux[i] <= 0)
                continue;
            radiux[i] = 2 * sqrt(radiux[i]);
        }
        sort(radiux, radiux + n);
        int cnt = 0;
        int i = 0;
        double len = 20;
        while (len > 0) {
            len -= radiux[n-1-i];
            ++i;
            ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
