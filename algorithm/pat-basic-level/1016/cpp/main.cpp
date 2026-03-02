#include <cstdio>

int main() {
    int a, da, b, db;
    scanf("%d %d %d %d", &a, &da, &b, &db);

    int cnta = 0, cntb = 0;
    while (true) {
        if (a == 0) {
            break;
        }
        int r = a % 10;
        a /= 10;
        if (r == da) {
            cnta++;
        }
    }

    while (true) {
        if (b == 0) {
            break;
        }
        int r = b % 10;
        b /= 10;
        if (r == db) {
            cntb++;
        }
    }

    int numa = 0, numb = 0;
    for (int i = 0; i < cnta; i++) {
        numa *= 10;
        numa += da;
    }
    for (int i = 0; i < cntb; i++) {
        numb *= 10;
        numb += db;
    }
    printf("%d", numa + numb);
}
