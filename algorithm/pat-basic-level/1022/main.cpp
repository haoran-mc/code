#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    int c = a + b;

    if (c == 0) {
        printf("0\n");
        return 0;
    }

    int idx = 0;
    int res[35];
    memset(res, 0, sizeof(res));

    while (true) {
        if (c == 0) {
            break;
        }
        res[idx++] = c % d;
        c /= d;
    }

    reverse(res, res + idx);
    for (int i = 0; i < idx; i++) {
        printf("%d", res[i]);
    }
    printf("\n");

    return 0;
}
