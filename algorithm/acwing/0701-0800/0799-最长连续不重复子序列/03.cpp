#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int h[maxn];  //以后就用h函数代表hash了
int I[maxn];  //以后就用I函数代表数组了

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &I[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        h[I[i]]++;
        while (h[I[i]] > 1) {
            h[I[j]]--;
            ++j;
        }
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);
    return 0;
}
