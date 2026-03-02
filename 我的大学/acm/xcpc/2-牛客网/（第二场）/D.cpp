#include<cstdio>
int main()
{
    int hour1, minutes1, sec1;
    int hour2, minutes2, sec2;
    scanf("%d:%d:%d", &hour1, &minutes1, &sec1);
    scanf("%d:%d:%d", &hour2, &minutes2, &sec2);
    int time1 = 3600 * hour1 + 60 * minutes1 + sec1;
    int time2 = 3600 * hour2 + 60 * minutes2 + sec2;
    if(time1 > time2){
        printf("%d", time1 - time2);
    }
    else {
        printf("%d", time2 - time1);
    }
    return 0;
}