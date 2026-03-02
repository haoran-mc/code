/*----------------------------------------------------------------
 *
 *   文件名称：1084 Broken Keyboard.cpp
 *   创建日期：2020年08月24日 ---- 18时08分
 *   结束日期：2020年08月25日 ---- 08时08分
 *   题    目：Broken Keyboard
 *   算    法：散列
 *   描    述：转换大小写，复制粘贴别忘了改
 *             unordered_map会改变顺序
 *
----------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, bool> ump;

int main()
{
    string str1;
    cin >> str1;
    for (int i = 0; i < (int)str1.length(); i++) {
        if (str1[i] <= 'z' && str1[i] >= 'a')
            str1[i] -= 32;
        ump[str1[i]] = false;
    }

    string str2;
    cin >> str2;
    for (int i = 0; i < (int)str2.length(); i++) {
        if (str2[i] <= 'z' && str2[i] >= 'a')
            str2[i] -= 32;
        ump[str2[i]] = true;
    }

    for (int i = 0; i < (int)str1.length(); i++) {
        if (ump[str1[i]] == false) {
            ump[str1[i]] = true;
            printf("%c", str1[i]);
        }
    }

    return 0;
}

