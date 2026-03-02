#include <stdio.h>

const double eps = 1e-5;

double sqrt() {
    double left  = 1;
    double right = 2;
    double mid;
    while (right - left > eps) {
        mid = (left + right) / 2;
        if (mid * mid > 2)
            right = mid;

        else
            left  = mid;
    }

    return mid;
}

int main() {
    printf("%f\n", sqrt());
    return 0;
}
