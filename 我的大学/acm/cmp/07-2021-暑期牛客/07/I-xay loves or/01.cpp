#include <cstdio>
#include <cmath>
typedef long long ll;
#define bug printf("<-->\n");

int main() {
    int x, s;
    scanf("%d %d", &x, &s);

    // 首先判断是否有y满足x|y = z
    int idx = 0;
    bool flag = false;
    while (x) {
        if ((x >> idx) & 1 && !((s >> idx) & 1)) {
            flag = true;
            break;
        }
        x -= (1 << idx);
        ++idx;
    }
    if (flag) {
        printf("0\n");
        return 0;
    }

    int cnt = 0;
    idx = 0;
    // 计算z中1的个数
    while (s) {
        if ((s >> idx) & 1) {
            cnt++;
        }
        s -= (1 << idx);
        idx++;
    }
    printf("%lld\n", (ll)pow(2.0, (ll)cnt));
    return 0;
}
