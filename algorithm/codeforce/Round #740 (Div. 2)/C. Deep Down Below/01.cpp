#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
#define bug printf("<-->\n");

struct Info {
    int power;
    int len;
    int idx;
    inline bool operator < (const Info x) {
        return power < x.power;
    }
} info[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int k; scanf("%d", &k);
            int maxi = 0;
            for (int j = 0; j < k; ++j) {
                int _; scanf("%d", &_);
                if (_ + 1 - j > maxi) {
                    maxi = max(_ + 1 - j, maxi);
                    info[i].power = maxi;
                    info[i].len = k;
                    info[i].idx = j;
                }
            }
        }
        sort(info, info + n);   // 按最低power值对山洞排序
        int idx = 0;   // 从0号山洞开始(也就是power最低的那个
        long long power = info[0].power + info[0].len;
        for (int i = 1; i < n; ++i) {
            while (power + info[i].idx <= info[i].power) {  // 从idx号山洞开始，不能通过第i个山洞
                power = power - info[idx].power + info[idx + 1].power;
                idx ++;
                printf("%d\n", i);
            }
            power += info[i].len;
        }
        printf("%d\n", info[idx].power);
    }
    return 0;
}
