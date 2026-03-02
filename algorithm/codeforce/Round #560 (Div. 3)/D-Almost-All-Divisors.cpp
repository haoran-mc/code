#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long maxn = 1e6 + 5;
typedef long long LL;
typedef unsigned long long uLL;
uLL divi[maxn];
bool hach[maxn];
#define bug printf("<------>\n");

bool judge(long long x) {
    for (long long i = 2; i < x; ++i) {
        /*mini = mini < i ? mini : i;*/
        if (!(x % i) && !hach[i])
            return false;
    }
    return true;
}

/*template<typename uLL>*/
uLL Gcd(uLL num1, uLL num2) {
    return !num2 ? num1 : Gcd(num2, num1 % num2);
}

bool judge1(uLL x) {
    for (uLL i = 2; i * i <= x; ++i) {
        /*mini = mini < i ? mini : i;*/
        if (!(x % i) && !hach[i])
            return false;
        if (!(x % i) && i != x/i && !(hach[x/i]))
            return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(hach, 0, sizeof(hach));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &divi[i]);
            hach[divi[i]] = true;
        }
        sort(divi, divi + n);
        bool flag = true;
        uLL x = divi[0] * divi[n-1];
        for(long long i=1,j=n-2;i<=j;i++,j--){
            if(divi[i]*divi[j]!=x) {
                flag = false;
                break;
            }
        }
        if (flag == false)
            bug
        for (int i = 0; i < n; ++i)
            printf("%lld ", divi[i]);
        int k = 0;
        uLL lcm = divi[0];
        uLL mini = lcm;
        /*while (!divi[k++] && k <= n);*/
        /*long long lcm = divi[--k];*/
        /*mini = lcm;*/
        k = n;
        while (k--)
            if (divi[k])
                for (int j = 0; j < k; ++j)
                    if (divi[j])
                        if (!(divi[k] % divi[j]))
                            divi[j] = 0;
        /*printf("%d\n", lcm);*/
        for (int i = 0; i < n; ++i)
            if (divi[i])
                /*lcm = lcm * divi[i] / __gcd(lcm, divi[i]);*/
                /*if (Gcd(lcm, divi[i]))*/
                lcm = (divi[i] / Gcd(lcm, divi[i])) * lcm;
        /*printf("mini = %lld\n", mini);*/
        /*printf("lcm  = %lld\n", lcm);*/
        /*printf("res  = %lld\n", lcm * mini);*/
        if (!judge1(lcm))
            printf("-1\n");
        else {
            if (lcm < maxn && hach[lcm])
                printf("%lld\n", mini * lcm);
            else
                printf("%lld\n", lcm);
        }
    }
    return 0;
}
