#include <cstdio>
double n;

double q(double a) {
    return a * a* a ;
}

int main() {
    scanf("%lf", &n);
    double l = -10000, r = 10000;
    while(r-l >= 1e-7){
        double mid = (l+r)/2;
        if (q(mid) >= n) 
            r = mid;
        else 
            l = mid;
    }
    printf("%.6f\n", l);
    return 0;
}
