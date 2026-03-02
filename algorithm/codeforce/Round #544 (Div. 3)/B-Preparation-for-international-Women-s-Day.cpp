#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
int HasH[maxn];
int main() {
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        ++HasH[num % k];
    }
    int res = 0;
    for (int i = 1; i < k; ++i)
        if (HasH[i] && HasH[k-i]) {
            int mini = min(HasH[i], HasH[k-i]);
            res += (i != k-i ? 2*mini : (mini/2)*2);
            HasH[i]   -= mini;
            HasH[k-i] -= mini;
        }
    res += ((HasH[0] / 2) * 2);
    printf("%d\n", res);
    return 0;
}
