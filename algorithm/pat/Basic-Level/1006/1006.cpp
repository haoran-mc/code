/*----------------------------------------------------------------
 *
 *   文件名称：1006.cpp
 *   创建日期：2020年10月16日 ---- 14时36分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void outputHundred(int n) {
    while (n--)
        printf("B");
}

void outputTen(int n) {
    while (n--)
        printf("S");
}

void outputBits(int n) {
    for (int i = 0; i < n; i++)
        printf("%d", i + 1);
}

int main()
{
    string input;
    cin >> input;
    if (input.length() == 1)
        outputBits(input[0] - '0');

    else if (input.length() == 2) {
        outputTen(input[0] - '0');
        outputBits(input[1] - '0');
    }

    else if (input.length() == 3) {
        outputHundred(input[0] - '0');
        outputTen(input[1] - '0');
        outputBits(input[2] - '0');
    }

    return 0;
}
