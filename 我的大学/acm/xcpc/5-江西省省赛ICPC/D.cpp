#include <cstdio>
#include <cmath>
typedef long long ill;
const int maxn = 1e7+5;
const ill mod = 9982443553;
int num[maxn];
bool hash[maxn];
void solve(int n) {
    for (int i = 0; i < n; ++i) {
        int temp = num[i];
        int cnt  = 0;
        while (temp != 0) {
            hash[temp%10] = true;
            hash[temp/10] = true;
            temp /= 10;
            cnt++;
        }
        while (cnt--) {
            hash[num[i]%(int)(pow(10, cnt))] = true;
            num[i] %= (int)(pow(10, cnt));
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        hash[num[i]] = true;
    }
    solve(n);
    ill sum = 0;
    for (int i = 0; i < maxn; ++i)
        if (!(hash[i]))
            sum += i,
            sum %= mod;
    printf("%lld\n", sum);
    return 0;
}
