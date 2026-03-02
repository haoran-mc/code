#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int sequ[maxn];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &sequ[i]);
    int res = 0;
    int j = 0;
    for (int i = 1; i < n; ) {
        j = i;
        while (sequ[j-1] != sequ[j])
            ++j;
        res = max(res, j - i);
        while (sequ[j] == sequ[j+1])
            ++j;
        i = j + 1;
    }
    printf("%d\n", res);
    return 0;
}
