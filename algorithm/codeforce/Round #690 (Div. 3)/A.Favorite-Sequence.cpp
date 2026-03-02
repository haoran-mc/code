#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 305;
int sequ[maxn];
vector<int> vec1;
vector<int> vec2;


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", & t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &sequ[i]);
        for (int i = 0, j = n-1; i <= n/2; ++i, --j) {
            vec1.push_back(sequ[i]);
            vec2.push_back(sequ[j]);
        }
        for (int i = 0; i < n; ++i)
            i & 1 ? printf("%d ", vec2[i>>1]) : printf("%d ", vec1[i>>1]);
        printf("\n");
        vec1.clear();
        vec2.clear();
    }
    return 0;
}
