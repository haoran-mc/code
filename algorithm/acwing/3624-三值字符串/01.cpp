#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int n;
char str[maxn];
int cnt[3];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        n = strlen(str);

        memset(cnt, 0, sizeof cnt);
        int res = n + 1;
        for (int i = 0, j = 0; i < n; i++) {
            cnt[str[i] - '1']++;
            while (cnt[str[j] - '1'] > 1) 
                cnt[str[j++] - '1']--;
            if (cnt[0] && cnt[1] && cnt[2])
                res = min(res, i - j + 1);
        }

        if (res == n + 1) res = 0;
        printf("%d\n", res);
    }

    return 0;
}
