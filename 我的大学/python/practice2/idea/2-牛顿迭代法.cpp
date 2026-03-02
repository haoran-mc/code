#include <cstdio>
const double eps = 1e-6;

double mySqrt(double base) {
    double x = 1.0;
    while(x*x-base < -eps || x*x-base > eps)
        x = (x + base/x) / 2.0;

    return x;
}

int main()
{
    printf("%f\n", mySqrt(82.0));
    return 0;
}
