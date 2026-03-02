#include <iostream>
#include <algorithm>
using namespace std;
struct stick {
    int x, y;
};
stick st[5005], st0[5005];
int cmp(stick a, stick b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y)) ? 1 : 0;
}
int main()
{
    int n, i = -1, j, m = 1;
    cin >> n;
    while (++i < n)
        cin >> st[i].x >> st[i].y;
    sort(st, st+n, cmp);
    for (i = 0; ++i < n;) {
        for (j = 0; ++j <= m;)
            if (st[i].x >= st0[j].x && st[i].y >= st0[j].y) {
                st0[j] = st[i];
                break;
            }
        if (j > m)
            st0[++m].x = st[i].x,
            st0[m].y = st[i].y;
    }
    cout << m;
}
