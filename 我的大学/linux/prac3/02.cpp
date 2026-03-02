#include <time.h>
#include <stdio.h>
typedef long long ll;

ll mktime_second(ll year0, ll mon0, ll day, ll hour, ll min, ll sec) {
    ll leap_years = 0, days = 0, seconds = 0, resultValue = 0;
    ll year = year0 - 1 ;
    ll TIME_ZONE = 8;//用于表示当前时区，=8表示北京时区东八区，单位小时，因为比本初子午线时间快8个小时
    const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int isleapyear = 0;

    leap_years = year/4 - year/100;//计算普通闰年
    leap_years += year/400;//加上世纪闰年
    days = year * 365 + leap_years;

    //今年是否是闰年
    if((year0%4 == 0 && year0 % 100!=0) || year0%400==0) 
        isleapyear = 1;//今年是闰年
    //按平年计算，到上个月为止总共度过的天数
    for(int i=0;i<mon0 - 1;i++) 
        days += month_days[i];
    if(mon0 >2) 
        days +=isleapyear;//2月份闰年要按29天计算
    days= days + day - 1;

    seconds = (hour) * 60 * 60 + (min) * 60 + sec;
    resultValue = (days - 719162) * 24 * 60 * 60;
    resultValue += seconds;
    resultValue -= ((ll)TIME_ZONE)*60*60;

    return resultValue;
}

int main() {
    time_t tt_;
    struct tm *tm_ ;
    time(&tt_);               //获取秒数
    tm_ = localtime(&tt_);    //将秒数转换为本地时间（北京时间）

    printf("当前时间：%d年%d月%d日 %02d:%02d:%02d\n", 1900 + tm_->tm_year, tm_->tm_mon + 1, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);

    printf("格林威治时间：%lld\n", mktime_second(1900 + tm_->tm_year, tm_->tm_mon + 1, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec));
    return 0;
}
