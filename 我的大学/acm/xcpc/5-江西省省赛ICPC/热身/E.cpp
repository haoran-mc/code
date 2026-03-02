#include <cstdio>
#include <algorithm>
using namespace std;
#define bug printf("******\n");
const int maxn = 30;
int hash[66];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int sum  = 0;        /*遍历次数*/
        int mx   = 0;        /*红包里的金币*/
        int numx = 0;        /*金币最大值*/
        int pack = 0;
        int coin = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            hash[num]++;
            sum += num;
            numx = max(numx, num);
        }
        for (int i = 1; i < sum; ++i) {
            for (int j = 1; j < numx/2+1; ++j) {
                int mn;
                mn = min(hash[j], hash[i-j]);
                pack += mn;
                hash[j]   -= mn;
                hash[i-j] -= mn;
            }

            if (pack > mx) {
                coin = i;
                mx = pack;
            }
        }
        printf("%d\n", coin);
    }
    return 0;
}
