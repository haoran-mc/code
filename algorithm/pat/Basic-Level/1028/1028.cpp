/*----------------------------------------------------------------
 *
 *   文件名称：1028.cpp
 *   创建日期：2020年11月08日 ---- 08时00分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
struct info {
    string name;
    string birth;
    bool flag;
}peop[maxn];
bool cmp(info peop1, info peop2) {
    if (peop1.birth != peop2.birth)
        return peop1.birth < peop2.birth;
    else
        return peop1.name < peop2.name;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int cont = 0;
    for (int i = 0; i < n; ++i) {
        cin >> peop[i].name;
        cin >> peop[i].birth;
        if (peop[i].birth > "2014/09/06" || peop[i].birth < "1814/09/06") {
            peop[i].flag = true;
            ++cont;
        }
    }
    cout << n-cont;
    if (n-cont < 1)
        return 0;

    sort(peop, peop+n, cmp);
    for (int i = 0 ; i < n; ++i) {
        if (peop[i].birth >= "1814/09/06") {
            cout << " " << peop[i].name << " ";
            break;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (peop[i].birth <= "2014/09/06") {
            cout << peop[i].name;
            break;
        }
    }
    return 0;
}
