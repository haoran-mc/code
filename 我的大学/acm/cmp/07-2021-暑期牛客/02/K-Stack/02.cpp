#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int num[maxn];
int a[maxn], b[maxn];
#define NEXTLINE puts("");

struct Info {
    int p;
    int x;
} info[maxn];

bool cmp(Info info1, Info info2) {
    return info1.p > info2.p;
}

void init(int len) {
    for (int i = 1; i <= len; ++i)
        num[i] = i;
}

int quickSort(int l, int r, int k) {
    if (l >= r) {
        int res = num[l];
        num[l] = 0x3f3f3f3f;
        return res;
    }

    int i = l - 1, j = r + 1, x = num[l + r >> 1];
    while (i < j) {
        do i ++ ; while (num[i] < x);
        do j -- ; while (num[j] > x);
        if (i < j) swap(num[i], num[j]);
    }

    if (j - l + 1 >= k) 
        return quickSort(l, j, k);
    else 
        return quickSort(j + 1, r, k - (j - l + 1));
}

int main() {
    freopen("in.txt", "r", stdin);
    int len, t; scanf("%d %d", &len, &t);
    init(len);
    int idx = 1;
    while (t--) {
        int p, x;
        scanf("%d %d", &p, &x);
        info[idx++] = {p, x};
    }
    sort(info + 1, info + idx, cmp);
    for (int i = 1; i < idx; ++i) {
        // 在a数组的第info[i].p的位置放上第(info[i].x)大的数
        // printf("在a数组的第%d的位置上放上第%d大的数: ", info[i].p, info[i].x);
        a[info[i].p] = quickSort(1, len, info[i].x);
        // printf("a[%d] = %d, 第%d大的数是%d\n", info[i].p, a[info[i].p], info[i].x, a[info[i].p]);
        /*
         * for (int i = 1; i <= len; ++i)
         *     printf("%d ", num[i]);
         * NEXTLINE;
         */
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (a[i])
                break;
            if (num[j] == INF)
                continue;
            a[i] = num[j];
            printf("<-->%d %d\n", i, a[i]);
            num[j] = INF;
            break;
        }
    }
    for (int i = 1; i <= len; ++i) 
        printf("%d ", a[i]);
    NEXTLINE
    return 0;
}
