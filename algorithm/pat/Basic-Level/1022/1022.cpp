/*----------------------------------------------------------------
 *
 *   文件名称：1022.cpp
 *   创建日期：2020年11月01日 ---- 23时10分
 *   结束日期：2020年11月01日 ---- 23时34分
 *   题    目：PAT
 *   算    法：进制转换
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
typedef long long ill;
string res;
int idx = 0;

void change(ill sum, int base) {
    while (sum != 0) {
        const char x = sum % base + '0';
        res.insert(idx++, &x);
        sum /= base;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ill num1;
    ill num2;
    int base;
    scanf("%lld", &num1);
    scanf("%lld", &num2);
    scanf("%d", &base);
    ill sum = num1 + num2;
    if (sum == 0) {
        printf("0\n");
        return 0;
    }
    change(sum, base);
    for (auto it = res.begin()+idx-1; it != res.begin()-1; --it)
        cout << *it;
    cout << endl;
    return 0;
}
