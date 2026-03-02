/*----------------------------------------------------------------
 *
 *   文件名称：1031.cpp
 *   创建日期：2020年11月08日 ---- 14时52分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int weigth[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
struct identity {
    string iden;
    bool x;
}num[100];
bool check(int num, char ch) {
    int arr[11] = {1, 0, 'X'-'0', 9, 8, 7, 6, 5, 4, 3, 2};
    if (arr[num] == ch - '0')
        return true;
    else
        return false;
}
bool judge(string str) {
    int sum = 0;
    for (int i = 0; i < 17; ++i) {
        if (str[i] <= '9' && str[i] >= '0')
            sum += (str[i]-'0') * weigth[i];
        else
            return false;
    }

    sum %= 11;
    if (check(sum, str[17]))
        return true;
    else
        return false;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        cin >> num[i].iden;

    for (int i = 0; i < t; ++i) {
        if (judge(num[i].iden))
            num[i].x = true;
        else
            num[i].x = false;
    }
    bool flag = false;
    for (int i = 0; i < t; ++i) {
        if (!(num[i].x)) {
            cout << num[i].iden << endl;
            flag = true;
        }
    }
    if (flag == false)
        printf("All passed\n");

    return 0;
}
