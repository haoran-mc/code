#include <algorithm>
#include <cstdio>
using namespace std;

int a[6];
int cnt[6];
bool a2f = true;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        int r = num % 5;

        switch (r) {
        case 0:
            if (num % 2 == 0) {
                a[1] += num;
                cnt[1]++;
            }
            break;
        case 1:
            if (a2f) {
                a[2] += num;
                a2f = false;
            } else {
                a[2] -= num;
                a2f = true;
            }
            cnt[2]++;
            break;
        case 2:
            a[3]++;
            cnt[3]++;
            break;
        case 3:
            cnt[4]++;
            a[4] += num;
            break;
        case 4:
            a[5] = max(a[5], num);
            cnt[5]++;
            break;
        }
    }
    cnt[1] > 0 ? printf("%d ", a[1]) : printf("N ");
    cnt[2] > 0 ? printf("%d ", a[2]) : printf("N ");
    cnt[3] > 0 ? printf("%d ", a[3]) : printf("N ");
    cnt[4] > 0 ? printf("%.1lf ", (double)a[4]/cnt[4]) : printf("N ");
    cnt[5] > 0 ? printf("%d", a[5]) : printf("N");
    return 0;
}
