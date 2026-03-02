#include <cstdio>
//判断是否是闰年
//普通闰年:公历年份是4的倍数，且不是100的倍数为普通闰年
//世纪闰年:公历年份是整百数的，且是400的倍数是世纪闰年
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year;
    scanf("%d", &year);
    printf("%d\n", isLeap(year));
    return 0;
}
