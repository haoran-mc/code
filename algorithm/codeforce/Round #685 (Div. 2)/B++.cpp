/*----------------------------------------------------------------
 *
 *   文件名称：B++.cpp
 *   创建日期：2020年11月22日 ---- 15时44分
 *   题    目：codeforces
 *   算    法：没有算法
 *   描    述：只需要考虑最两端字符就行了
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int size;
        int query;
        cin >> size >> query;
        string str;
        cin >> str;
        while (query--) {
            int L;
            int R;
            cin >> L >> R;
            //auto it0 = str.begin();
            auto it1 = str.find(str[L-1]);
            auto it2 = str.find(str[R-1], R);
            //cout << "substr = " << str.substr(L-1, R-L+1) << endl;
            //printf("it1 = %d ", (int)it1);
            //printf("it2 = %d\n", (int)it2);
            //printf("L   = %d ", L);
            //printf("R   = %d\n", R);
            if ((int)it1 == L-1 && it2 == string::npos)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    solve();
    return 0;
}
