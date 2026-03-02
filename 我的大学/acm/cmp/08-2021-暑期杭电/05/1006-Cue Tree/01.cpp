#include <cstdio>
using namespace std;

int cal(int l, int r) {
    // cout << l << " " << r << '\n';
    int res = 1;
    if (l == r)
        return res;
    if (r - l == 1)
        res += 2;
    else {
        int B = l + (r - l + 1) / 3 - 1;
        int C = (B + r) / 2;
        res += cal(l, B);
        res += cal(B + 1, C);
        res += cal(C + 1, r);
    }
    return res;
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int m;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &m);
        printf("%d\n", cal(1, m));
    }
    return 0;
}
