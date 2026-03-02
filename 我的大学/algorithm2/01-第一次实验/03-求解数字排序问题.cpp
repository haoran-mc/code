#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
unordered_map<int, int> mp;

struct Nums {
    int i1, i2;
} nums[maxn];

bool cmp(Nums n1, Nums n2) {
    return n1.i2 == n2.i2 ? n1.i1 < n2.i1 : n1.i2 > n2.i2;
}

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        int num; scanf("%d", &num);
        mp[num] ++ ;
    }
    int cnt = 0;
    for (auto i : mp) {
        nums[cnt].i1 = i.first;
        nums[cnt].i2 = i.second;
        cnt ++ ;
    }
    sort(nums, nums + cnt, cmp);
    for (int i = 0; i < cnt; i ++ )
        printf("%d %d\n", nums[i].i1, nums[i].i2);
    return 0;
}
