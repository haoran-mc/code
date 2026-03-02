#include <cstdio>
#include <cmath>

int main() {
    double r, a, b, h;
    scanf("%lf %lf %lf %lf", &r, &a, &b, &h);
    double c = sqrt(pow((a/2) - (b/2), 2) + pow(h, 2));
    double sinb = (a/2 - b/2) / c;
    double cosb = h / c;
    double h1 = r * sinb;
    double len = r * cosb;
    double h2 = ((len - b/2) / (a/2 - b/2)) * h;
    double res = h1 + h2;
    if (2 * r <= b) {
        printf("Drop\n");
    }
    else {
        printf("Stuck\n");
        printf("%.9lf\n", res);
    }
    return 0;
}
