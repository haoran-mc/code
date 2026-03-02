#include <cstdio>
#include <cmath>
const double eps = 1e-6;
#define bug printf("<------>\n");
double a;
double b;
double c;
double d;

void solve() {
    int flag = 0;
    for (double i = -100; i <= 100 && flag != 3; i += 0.0001)
        if (fabs(a*pow(i, 3) + b*pow(i, 2) + c*i + d) <= eps)
            ++flag == 3 ? printf("%.2f", i) : printf("%.2f ", i);
}

int main() {
//#ifndef ONLINE_JUDGE
	//freopen("simple.in","r",stdin);
	//freopen("simple.out","w",stdout);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//#endif
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);
    solve();
    return 0;
}
