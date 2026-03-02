/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1002.cpp
 *   创建日期：2020年10月10日 ---- 21时42分
 *   结束日期：2020年10月10日 ---- 21时57分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void output(int num) {
    if (num == 0) {
        printf("ling");
        return ;
    }
    else if (num == 1) {
        printf("yi");
        return ;
    }
    else if (num == 2) {
        printf("er");
        return ;
    }
    else if (num == 3) {
        printf("san");
        return ;
    }
    else if (num == 4) {
        printf("si");
        return ;
    }
    else if (num == 5) {
        printf("wu");
        return ;
    }
    else if (num == 6) {
        printf("liu");
        return ;
    }
    else if (num == 7) {
        printf("qi");
        return ;
    }
    else if (num == 8) {
        printf("ba");
        return ;
    }
    else if (num == 9) {
        printf("jiu");
        return ;
    }
}

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < (int)str.length(); i++)
        sum += str[i] - '0';

    stack<int> stk;
    while (sum != 0) {
        stk.push(sum % 10);
        sum /= 10;
    }

    while (stk.empty() == false) {
        output(stk.top());
        stk.pop();
        if (stk.empty() == false)
            printf(" ");
    }
    return 0;
}
