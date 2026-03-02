#include <cstdio>

int sumDigital(int year) {
    int sum = 0;
    while (year) {
        sum += (year % 10);
        year /= 10;
    }
    return sum;
}

int main() {
//#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
//#endif
    int year;
    scanf("%d", &year);
    for (int i = year + 1; ; ++i)
        if (sumDigital(i) == sumDigital(year)) {
            printf("%d\n", i);
            break;
        }
    return 0;
}
