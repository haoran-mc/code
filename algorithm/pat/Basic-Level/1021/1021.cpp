/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1021.cpp
 *   创建日期：2020年11月01日 ---- 22时55分
 *   结束日期：2020年11月01日 ---- 23时00分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

map<char, int> mp;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string str;
    cin >> str;
    for (int i = 0; i < (int)str.length(); ++i)
        mp[str[i]]++;
    for (auto it = mp.begin(); it != mp.end(); ++it)
        printf("%c:%d\n", it -> first, it -> second);
    return 0;
}
