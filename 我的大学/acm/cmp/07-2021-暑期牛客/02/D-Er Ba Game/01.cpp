#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int a1, b1, a2, b2;
        scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
        if (a1 > b1) swap(a1, b1);
        if (a2 > b2) swap(a2, b2);
        if (a1 == a2 && b1 == b2) {
            printf("tie\n");
            continue;
        }
        else if ((a1 == 2 && b1 == 8) || (a2 == 2 && b2 == 8)) {
            if (a1 == 2 && b1 == 8) {
                printf("first\n");
                continue;
            }
            else {
                printf("second\n");
            }
        }
        else if ((a1 == b1) || (a2 == b2)) {
            if ((a1 == b1) && (a2 == b2)) {
                if (a1 > a2) {
                    printf("first\n");
                    continue;
                }
                else if (a1 < a2) {
                    printf("second\n");
                    continue;
                }
                else {
                    printf("tie\n");
                    continue;
                }
            }
            else if (a1 == b1) {
                printf("first\n");
                continue;
            }
            else {
                printf("second\n");
                continue;
            }
        }
        else if ((a1 + b1) % 10 > (a2 + b2) % 10) {
            printf("first\n");
            continue;
        }
        else if ((a1 + b1) % 10 < (a2 + b2) % 10) {
            printf("second\n");
            continue;
        }
        else if ((a1 + b1) % 10 == (a2 + b2) % 10) {
            if (b1 > b2) {
                printf("first\n");
                continue;
            }
            else if (b1 < b2) {
                printf("second\n");
                continue;
            }
            else {
                printf("tie\n");
                continue;
            }
        }
    }
    return 0;
}
