#include <cstdio>
int main() {
    int hour1;
    int minu1;
    int hour2;
    int minu2;
    scanf("%d:%d", &hour1, &minu1);
    scanf("%d:%d", &hour2, &minu2);
    int minu = (minu1+minu2) / 2;
    int hour = (hour1+hour2) / 2;
    if ((hour2 - hour1) & 1)
        minu += 30;
    if (minu >= 60)
        minu -= 60,
        hour += 1;
    printf("%02d:", hour);
    printf("%02d\n", minu);
    return 0;
}
