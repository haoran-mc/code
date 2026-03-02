#include <stdio.h>
#include <math.h>

const double PI  = acos(-1.0);
const double eps = 1e-5;

double calculate_r(double R, double h) {
    double angle = 2 * acos((R - h) / R);
    double L  = 2 * sqrt(R * R - (R - h) * (R - h));
    double s1 = angle * R * R / 2 - L * (R - h) / 2;
    double s2 = PI * R * R / 2;
    return s1 / s2;
}

double find_h(double R, double r) {
    double left  = 0;
    double right = R;
    double mid;

    while (right - left > eps) {
        mid = (left + right) / 2;
        if (calculate_r(R, mid) < r)
            left = mid;
        else
            right = mid;
    }
    return mid;
}

int main() {
    double R = 10;
    double r = 0.5;
    double h = find_h(R, r);
    printf("%.4f\n", h);
    return 0;
}
