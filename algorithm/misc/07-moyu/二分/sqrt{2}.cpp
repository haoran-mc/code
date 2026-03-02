#include <cstdio>
const double eps = 1e-5;

int main() {
    double left  = 1;
    double right = 2;
    double mid;
    while (right - left > eps) {
        mid = (right + left) / 2;
        if (mid * mid < 2)
            left = mid;
        else
            right = mid;
    }
    printf("%f\n", mid);
    return 0;
}
