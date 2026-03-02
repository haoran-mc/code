/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月08日 星期日 20时57分52秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：自己写的，第一次没成功
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <map>
using namespace std;
const int maxn = 5e4 + 5;
int fa[maxn];
map<int, int> mp;

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    int cnt = 0;
    while (k--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (x > n || y > n) {
            cnt++;
            continue;
        }
        if (op == 1) {
            if (find(x) != x && find(y) != y && find(x) != find(y))
                cnt++;
            else {
                if (find(x))
                    fa[y] = find(x);
                else if (find(y))
                    fa[x] = find(y);
            }
        }
        else if (op == 2) {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx == rooty) {
                cnt++;
                continue;
            }
            if (mp.find(rootx) == mp.end() && mp.find(rooty) == mp.end())
                mp[rootx] = rooty;
            else if (mp.find(rootx) == mp.end() && mp.find(rooty) != mp.end()) {
                if (mp[rooty] == rootx || mp[rooty] == rooty) {
                    cnt++;
                    continue;
                }
                mp[rootx] = rooty;
            }
            else if (mp.find(rootx) != mp.end() && mp.find(rooty) == mp.end()) {
                if (mp[rootx] == rootx) {
                    cnt++;
                    continue;
                }
                mp[rootx] = rooty;
            }
            else if (mp.find(rootx) != mp.end() && mp.find(rooty) != mp.end()) {
                if (mp[rootx] != rooty || mp[rooty] == rootx) {
                    cnt++;
                    continue;
                }
                mp[rootx] = rooty;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
