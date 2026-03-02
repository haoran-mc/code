#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            for (int k = j; k < n; ++k)
                if ((ll)a[i] * (ll)a[j] == (ll)a[k]) {
                    if (i == j) {
                        if (k == i)   // a[i] = a[j] = a[k] = 1;
                            cnt += 6;
                        else if (k != i && a[k] == 1)
                            cnt += 3;
                        else 
                            cnt += 1;
                    }
                    else if (i != j) {
                        if (k == j && 
                    }
                }
    printf("%d\n", cnt);
    return 0;
}
