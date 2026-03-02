#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a1, b1, a2, b2;
    a1 = r1 * cos(p1);
    b1 = r1 * sin(p1);
    a2 = r2 * cos(p2);
    b2 = r2 * sin(p2);
    double a, b;
    a = a1 * a2 - b1 * b2;
    b = a1 * b2 + a2 * b1;

    if (a < 0 && a > -0.01)
        a = 0;
    if (b < 0 && b > -0.01)
        b = 0;

    if (b < 0) {
        printf("%.2lf%.2lfi\n", a, b);
    } else {
        printf("%.2lf+%.2lfi\n", a, b);
    }
    return 0;
}
