#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
char str[maxn];
int front_p[maxn], behind_a[maxn];
int mod = 1000000007;

int main() {
    scanf("%s", str);
    int p_cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'P') {
            p_cnt++;
        } else if (str[i] == 'A') {
            front_p[i] = p_cnt;
        }
    }
    int a_cnt = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == 'T') {
            a_cnt++;
        } else if (str[i] == 'A') {
            behind_a[i] = a_cnt;
        }
    }
    long long res = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'A') {
            res += (front_p[i] * behind_a[i]) % mod;
            res %= mod;
        }
    }
    printf("%lld", res);
    return 0;
}
