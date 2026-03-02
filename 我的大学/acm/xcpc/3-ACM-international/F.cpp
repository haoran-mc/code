#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int group;
        int sum;
        scanf("%d", &group);
        scanf("%d", &sum);
        struct Times {
            int hour;
            int minu;
        }times;
        times.hour = 0;
        times.minu = 0;
        while (group--) {
            int hour1;
            int hour2;
            int minu1;
            int minu2;
            scanf("%d:%d", &hour1, &minu1);
            scanf("%d:%d", &hour2, &minu2);
            if (minu2 < minu1) {
                minu2 += 60;
                hour2 -= 1;
            }
            minu1 = minu2 - minu1;
            hour1 = hour2 - hour1;
            times.hour += hour1;
            times.minu += minu1;
        }
        times.hour += times.minu / 60;
        //printf("%d %d\n", times.hour, times.minu);
        if (times.hour >= sum)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
