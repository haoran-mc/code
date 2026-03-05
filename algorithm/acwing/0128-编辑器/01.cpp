#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int stkl[maxn], stkr[maxn], tl, tr;
int preS[maxn], maxi[maxn];  // 前缀和与前缀和的最大值

void push_left(int x) {
    stkl[++tl] = x;
    preS[tl] = preS[tl-1] + x;
    maxi[tl] = max(maxi[tl - 1], preS[tl]);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        maxi[0] = -INF;
        char str[2]; scanf("%s", str);
        if (*str == 'I') {
            int x; scanf("%d", &x);
            push_left(x);
        }
        else if (*str == 'D') {
            if (tl)
                tl--;
        }
        else if (*str == 'L') {
            if (tl)
                stkr[++tr] = stkl[tl--];
        }
        else if (*str == 'R') {
            if (tr)
                push_left(stkr[tr--]);
        }
        else if (*str == 'Q') {
            int k; scanf("%d", &k);
            printf("%d\n", maxi[k]);
        }
    }
    return 0;
}
