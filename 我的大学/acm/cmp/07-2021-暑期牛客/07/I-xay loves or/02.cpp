#include <cstdio>
typedef long long ll;

int main() {
    ll x, s;
    scanf("%lld %lld", &x, &s);
    int idx = 0;
    ll cnt = 1LL;
    bool flag = false;
    // 还需要判断s是什么鬼
    while (x || s) {
        if (((x >> idx) & 1) && ((s >> idx) & 1))
            cnt *= 2LL;
        else if (!((x >> idx) & 1) && ((s >> idx) & 1))
            flag = true;
        else if (((x >> idx) & 1) && !((s >> idx) & 1)) {
            printf("0\n");
            return 0;
        }
        if ((x >> idx) & 1)
            x -= (1 << idx);
        if ((s >> idx) & 1)
            s -= (1 << idx);
        idx++;
    }
    if (!flag)
        cnt--;
    printf("%lld\n", cnt);
    return 0;
}
