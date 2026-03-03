#include <cstdio>

int main() {
    // Galleon.Sickle.Knut
    int g1, s1, k1;
    int g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);

    int cnt1 = g1 * 17 * 29 + s1 * 29 + k1;
    int cnt2 = g2 * 17 * 29 + s2 * 29 + k2;

    int g3, s3, k3;
    if (cnt1 > cnt2) {
        // 负

        if (k1 < k2) {
            s1--;
            k1 += 29;
        }
        k3 = k1 - k2;

        if (s1 < s2) {
            g1--;
            s1 += 17;
        }
        s3 = s1 - s2;

        g3 = g1 - g2;
        printf("-%d.%d.%d\n", g3, s3, k3);
    } else {

        if (k2 < k1) {
            s2--;
            k2 += 29;
        }
        k3 = k2 - k1;

        if (s2 < s1) {
            g2--;
            s2 += 17;
        }
        s3 = s2 - s1;

        g3 = g2 - g1;
        printf("%d.%d.%d\n", g3, s3, k3);
    }
    return 0;
}
