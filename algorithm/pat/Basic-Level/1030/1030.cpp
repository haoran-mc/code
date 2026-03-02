#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int q;
    scanf("%d", &n);
    scanf("%d", &q);
    vector<int> sequ;
    while (n--) {
        int num;
        scanf("%d", &num);
        sequ.push_back(num);
    }
    sort(sequ.begin(), sequ.end());
    int ans = 1;
    for (int i = 0; i < (int)sequ.size(); i++) {
        auto it = upper_bound(sequ.begin() + i, sequ.end(), (long long)q * sequ[i]);
        ans = max(ans, (int)(it - sequ.begin() - i));
    }
    printf("%d\n", ans);
    return 0;
}
