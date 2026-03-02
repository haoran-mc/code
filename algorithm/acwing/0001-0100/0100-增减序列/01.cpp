#define bug printf("<-->\n");
#define lowbit(x) ((x) & -(x)) //lowbit(ob0010) = 2
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define NEXTLINE puts("");
#include <cstdio>
const int maxn = 1e5 + 5;
int num[maxn];
int diff[maxn];

int main() {
    int n;
    scanf("%d", &n);
    int nega = 0;
    int posi = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        if (!i)
            diff[i] = num[i];
        else
            diff[i] = num[i] - num[i-1];
        if (diff[i] >= 0)
            posi += diff[i];
        else
            nega -= diff[i];
    }
    int cnt = 0;
    cnt += _min(nega, posi);
    cnt = cnt + nega - cnt + posi - cnt;
    printf("%d\n", cnt);
    return 0;
}
