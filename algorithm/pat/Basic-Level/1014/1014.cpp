/*----------------------------------------------------------------
 *
 *   文件名称：1014.cpp
 *   创建日期：2020年10月20日 ---- 15时20分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void outputDay(int n) {
    if (n == 1) {
        printf("MON ");
        return ;
    }
    else if (n == 2) {
        printf("TUE ");
        return ;
    }
    else if (n == 3) {
        printf("WED ");
        return ;
    }
    else if (n == 4) {
        printf("THU ");
        return ;
    }
    else if (n == 5) {
        printf("FRI ");
        return ;
    }
    else if (n == 6) {
        printf("SAT ");
        return ;
    }
    else if (n == 7) {
        printf("SUN ");
        return ;
    }
}

int main()
{

    string str1;
    string str2;
    string str3;
    string str4;
    cin >> str1;
    cin >> str2;
    cin >> str3;
    cin >> str4;
    int Day;
    int Hour;
    int minute;
    bool flag = false;
    for (int i = 0; i < min((int)str1.length(), (int)str2.length()); i++) {
        if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G' && flag == false) {
            Day = str1[i] - 'A' + 1;
            flag = true;
            i++;
        }
        if (str1[i] == str2[i] && ((str1[i] <= 'N' && str1[i] >= 'A') || (str1[i] <= '9' && str1[i] >= '0')) && flag == true) {
            if (str1[i] <= '9' && str1[i] >= '0')
                Hour = str1[i] - '0';
            else
                Hour = str1[i] - 'A' + 10;
            break;
        }
    }
    for (int i = 0; i < min((int)str3.length(), (int)str4.length()); i++)
        if (str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z'))) {
            minute = i;
            break;
        }

    outputDay(Day);
    printf("%02d:", Hour);
    printf("%02d\n", minute);
    return 0;
}
