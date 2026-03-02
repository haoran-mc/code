#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        LL maxi = 0;
        LL sum  = 0;
        for(int i = 0; i < n; ++i) {
            LL toy;
            scanf("%lld", &toy);
            sum += toy;
            maxi = max(maxi, toy);
        }
        LL need = max(maxi, (sum+n-2) / (n-1));
        printf("%lld\n", need * (n-1) - sum);
    }
    return 0;
}
