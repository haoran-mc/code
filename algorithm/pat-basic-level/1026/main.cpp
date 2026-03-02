#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    double c = double(b - a) / 100;

    int hh = c / 3600;
    c = c - hh * 3600;

    int mm = c / 60;
    c = c - mm * 60;

    int ss = int(c);
    c = c - ss;
    if (c >= 0.5) {
        ss++;
    }
    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
