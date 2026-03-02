/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年11月20日 ---- 19时49分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <bits/stdc++.h>
// #include <cstdio>
// #include <cassert>
// #include <algorithm>
using namespace std;
#define bug printf("******\n");

template<typename T>
T _gcd(T num1, T num2) {
    return !num2 ? num1 : _gcd(num2, num1 % num2);
}

int GCD(int n, int a[]) {
    int Min = _gcd(a[1], a[2]);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            Min = min(Min, _gcd(a[i], a[j]));
    return Min;
}

int _GCD(int n, int a[]) {
    int Min = _gcd(a[1], a[2]);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            int temp = Min;
            Min = min(Min, _gcd(a[i], a[j]));
            if (_gcd(temp, _gcd(a[i], a[j])) != Min)
                return 0;
        }
    return Min;
}

int main()
{
    int arr[4] = {0, 8, 12, 15};
    printf("3\n");
    while (GCD(3, arr) == _GCD(3, arr))
        ++arr[3];

    for (int k = 1; k <= 3; ++k)
        printf("%d ", arr[k]);
    //printf("\n%d\n", GCD(3, arr));
    //printf("%d\n", _GCD(3, arr));
    return 0;
}
