/*----------------------------------------------------------------
 *
 *   文件名称：1010 Radix.cpp
 *   创建日期：2020年09月07日 ---- 16时23分
 *   结束日期：2020年09月08日 ---- 14时24分
 *   题    目：PAT
 *   算    法：二分查找，进制转换
 *   描    述：- 将已知进制数放在N1，未知进制数放在N2
 *             - N1转换为10进制数
 *             - 找到未知进制数可能的进制范围
 *                 - 下界 N2中最大字符所代表的数加一
 *                 - 上界 N1转换为十进制时的数加一
 *             - 题目要求输出最小进制，判断进制为下界时N2是否等于N1
 *             - 二分法在范围[上界，下界]中找出N2=N1的进制
 *             - 进制转换时可能溢出，如果有，就返回long long 的最大值
 *                 - 已知进制的那个数不会溢出
 *                 - 未知进制的那个数可能溢出
 *   错    误：upperBound 可能超过int型范围
 *             lowerBound 就已经可以使decN1 == decN2
 *             溢出
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ill;
ill Inf = (1LL << 63) - 1;
/*const int Inf = 0x3f3f3f3f;*/
/*const ill Inf = 0x3f3f3f3f3f3f3f3e;*/
/*#define INF 0x7f7f7f7f*/

/*将进制为base1的str转化为10进制*/
ill Conversion(string str, ill base) {
    ill unit = 0;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            unit = base * unit + (str[i] - '0');
        else if (str[i] >= 'a' && str[i] <= 'z')
            unit = base * unit + (str[i] - 'a') + 10;

        if (unit < 0)
            return Inf;
    }
    return unit;
}

ill findLowerBound(string N2) {
    int len = N2.length();
    ill lowerBound = 0;
    for (int i = 0; i < len; i++)
        if (lowerBound < N2[i])
            lowerBound = N2[i];

    if (lowerBound >= '0' && lowerBound <= '9')
        return (lowerBound - '0') + 1;
    else
        return (lowerBound - 'a') + 10 + 1;
}

ill binarySearch(ill decN1, string N2, ill lowerBound, ill upperBound) {
    ill decN2 = 0;
    while (lowerBound <= upperBound) {
        ill mid = lowerBound + (upperBound - lowerBound) / 2;
        decN2 = Conversion(N2, mid);
        if (decN2 == decN1)
            return mid;
        else if (decN2 < decN1)
            lowerBound = mid + 1;
        else if (decN2 > decN1)
            upperBound = mid - 1;
    }
    return -1;
}

int main() {
    string N1;
    string N2;
    int tag;
    int radix;
    cin >> N1  >> N2;
    cin >> tag >> radix;

    if (tag == 2) {
        string temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
    }

    ill decN1 = Conversion(N1, radix);
    ill lowerBound = findLowerBound(N2);
    ill upperBound = decN1 + 1;
    if (Conversion(N2, lowerBound) == decN1) {
        printf("%lld\n", lowerBound);
        return 0;
    }
    ill ans = binarySearch(decN1, N2, lowerBound, upperBound);

    if (ans == -1)
        printf("Impossible\n");
    else
        printf("%lld\n", ans);

    return 0;
}
