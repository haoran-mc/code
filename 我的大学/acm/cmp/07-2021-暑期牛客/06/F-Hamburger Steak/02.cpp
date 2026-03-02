#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
long long sum, maxTime;

struct Steak {
    int  id;
    long long t;
} a[maxn];

bool cmp(Steak a, Steak b) {
    return a.t > b.t;
}

struct Ans {
    int k;
    int id[3];
    long long l[3], r[3];

    void add(int _id, long long _l, long long _r) {
        ++k;
        id[k] = _id; l[k] = _l; r[k] = _r;
        if(k > 1) {
            swap(id[1], id[2]);
            swap(l[1], l[2]);
            swap(r[1], r[2]);
        }
    }
} ans[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i].t);
        a[i].id = i;
        sum += a[i].t;
        maxTime = max(maxTime, a[i].t);
    }
    sort(a + 1, a + 1 + n, cmp);
    maxTime = max(maxTime, ((sum + m - 1) / m));
    int now = 1, panId = 1;
    long long lst = maxTime;
    while(now <= n) {
        if(a[now].t <= lst) { //如果这个锅的剩余可烹饪时间可以把这个汉堡烹饪完
            ans[a[now].id].add(panId, maxTime - lst, maxTime - lst + a[now].t);
            lst -= a[now].t; // 这个锅剩余的可烹饪时间
            now++;
            if(lst == 0) {
                lst = maxTime;
                ++panId;
            }
        }
        else { // 如果不能，那就放到下一个锅内
            ans[a[now].id].add(panId, maxTime - lst, maxTime);
            a[now].t -= lst;
            panId++;
            lst = maxTime;
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", ans[i].k);
        for(int j = 1; j <= ans[i].k; ++j)
            printf("%d %lld %lld ", ans[i].id[j], ans[i].l[j], ans[i].r[j]);
        printf("\n");
    }
    return 0;
}
