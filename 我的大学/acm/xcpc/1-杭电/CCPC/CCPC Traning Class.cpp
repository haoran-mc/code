/*----------------------------------------------------------------
 *
 *   文件名称：CCPC Traning Class.cpp
 *   创建日期：2020年09月20日 ---- 15时41分
 *   题    目：poj
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int T;
    int count = 0;
    scanf("%d", &T);
    while (T--) {
        count++;
        string str;
        cin >> str;
        map<char, int> mp;
        for (int i = 0; i < (int)str.length(); i++)
            mp[str[i]] = 0;

        for (int i = 0; i < (int)str.length(); i++)
            mp[str[i]]++;

        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
            if (it -> second > ans)
                ans = it -> second;

        printf("Case #%d: %d\n", count, ans);
    }
    return 0;
}

