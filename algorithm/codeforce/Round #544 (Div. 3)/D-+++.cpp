#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];
map<pair<int, int>, int> mp;

template<typename T>
T Gcd(T num1, T num2) {
    return !num2 ? num1 : Gcd(num2, num1 % num2);
}

pair<int, int> norm(int num1, int num2) {
    int gcd = Gcd(abs(num1), abs(num2));
    num1 /= gcd;
    num2 /= gcd;
    if (num1 < 0)
        num1 = -num1,
        num2 = -num2;
    /*printf("%d %d\n", num1, num2);*/
    return make_pair(num1, num2);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        /*要顾全大局，虽然当b[i]为0时当d为0时会有C为0，但是可能只有一个b[i] == 0，却有100个1/3*/
        /*而a[i]与b[i]都为0时有d == 3使得1/3能满足c == 0，而且0/0满足*/
        if (a[i] == 0) {
            if (b[i] == 0)
                ++cnt;
        }
        else {
            /*pair pir;*/
            pair<int, int> pr;
            pr = norm(a[i], b[i]);
            ++mp[pr];
            res = max(res, mp[pr]);
        }
    }
    printf("%d\n", cnt + res);
    return 0;
}
