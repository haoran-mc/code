#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int arr1[maxn];
int arr2[maxn];
map<double, int> mp;

template<typename T>
T Gcd(T num1, T num2) {
    return !num2 ? num1 : Gcd(num2, num1 % num2);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr1[i]);
    int res1 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr2[i]);
        if (arr1[i]) {
            int gcd = Gcd(abs(arr1[i]), abs(arr2[i]));
            arr1[i] /= gcd;
            arr2[i] /= gcd;
            ++mp[(double)arr2[i]/(double)arr1[i]];
        }
        if (!arr1[i] && !arr2[i])
            ++res1;
    }
    int res = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        res = max(res, it -> second);
    }
    //res = max(res, res1);
    res += res1;
    printf("%d\n", res);
    return 0;
}
