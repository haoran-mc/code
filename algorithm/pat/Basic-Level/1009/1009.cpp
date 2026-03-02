/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1009.cpp
 *   创建日期：2020年10月19日 ---- 20时32分
 *   结束日期：2020年10月19日 ---- 20时37分
 *   题    目：PAT
 *   算    法：vector
 *   描    述：有手就行
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> vec;
    string str;
    while (cin >> str)
        vec.push_back(str);

    for (auto it = vec.end() - 1; it != vec.begin(); it--)
        cout << *it << " ";

    auto it = vec.begin();
    cout << *it;
    return 0;
}
