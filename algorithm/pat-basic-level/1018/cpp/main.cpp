#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

struct {
    int succ;
    int fail;
    int equal;
    int h[128];
} a, b;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char x, y;
        scanf("%c %c", &x, &y);
        printf("%c %c\n", x, y);
        getchar();
        if (x == y) {
            a.equal++;
            b.equal++;
        } else if (x == 'C') {
            if (y == 'J') {
                a.succ++;
                a.h['C']++;
                b.fail++;
            } else if (y == 'B') {
                b.succ++;
                b.h['B']++;
                a.fail++;
            }
        } else if (x == 'J') {
            if (y == 'B') {
                a.succ++;
                a.h['J']++;
                b.fail++;
            } else if (y == 'C') {
                b.succ++;
                b.h['C']++;
                a.fail++;
            }
        } else if (x == 'B') {
            if (y == 'C') {
                a.succ++;
                a.h['B']++;
                b.fail++;
            } else if (y == 'J') {
                b.succ++;
                b.h['J']++;
                a.fail++;
            }
        }
    }

    printf("%d %d %d\n", a.succ, a.equal, a.fail);
    printf("%d %d %d\n", b.succ, b.equal, b.fail);

    // B C J
    int amax = max(a.h['B'], max(a.h['C'], a.h['J']));
    int bmax = max(b.h['B'], max(b.h['C'], b.h['J']));
    if (a.h['B'] == amax) {
        printf("%c ", 'B');
    } else if (a.h['C'] == amax) {
        printf("%c ", 'C');
    } else {
        printf("%c ", 'J');
    }
    if (b.h['B'] == bmax) {
        printf("%c\n", 'B');
    } else if (b.h['C'] == bmax) {
        printf("%c\n", 'C');
    } else {
        printf("%c\n", 'J');
    }
    return 0;
}
