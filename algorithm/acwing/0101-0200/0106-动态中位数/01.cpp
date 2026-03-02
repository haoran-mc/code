#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define NEXTLINE puts("");

int main() {
    int t, m, n;
    scanf("%d", &t);
    while (t--) {
        priority_queue<int> hE;//q为大根堆
        priority_queue<int, vector<int>, greater<int>> he;//p为小根堆
        scanf("%d %d", &m, &n);
        printf("%d %d\n", m, (n + 1) / 2);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int _;
            scanf("%d", &_);
            he.push(_);
            if (hE.size() && hE.top() > he.top()) {
                int a = he.top(),
                    b = hE.top();
                he.pop(), hE.pop();
                he.push(b), hE.push(a);
            }
            if (he.size() > hE.size() + 1) {
                hE.push(he.top());
                he.pop();
            }
            if (i & 1)//奇数
                printf("%d%c", he.top(), ++cnt % 10 == 0 ? '\n' : ' ');//每10个数换一行
        }
        if (cnt % 10)
            NEXTLINE
    }
    return 0;
}
