#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
char str[maxn];
int cnt[3];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int len = strlen(str);
        int res = len + 1;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0, j = 0; i < len; ++i) {
            cnt[str[i] - '1'] ++ ;
            while (cnt[str[j] - '1'] > 1)
                cnt[str[j++] - '1']--;
            if (cnt[0] && cnt[1] && cnt[2])
                res = min(res, i - j + 1);
        }
        if (res == len + 1)
            res = 0;
        printf("%d\n", res);
    }
    return 0;
}
