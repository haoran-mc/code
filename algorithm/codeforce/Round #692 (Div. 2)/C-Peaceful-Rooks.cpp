/*----------------------------------------------------------------
 *
 *   文件名称：C-Peaceful-Rooks.cpp
 *   创建日期：2020年12月21日 ---- 00时49分
 *   题    目：codeforces
 *   算    法：并查集、但我是map，投机取巧
 *   描    述：找环
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <map>
using namespace std;
#define bug printf("<------>\n");
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        map<int, int> mp;
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            mp[x] = y;
        }

        map<int, int> cpy = mp;
        int res = m;
        /*printf("res = %d\n", res);*/
        for (auto it = mp.begin(); it != mp.end();)
            if (it -> first == it -> second) {
                mp.erase(it++);
                res--;
            }
            else
                ++it;
        /*printf("res = %d\n", res);*/

        /*
         *auto it = mp.begin();
         *int x = it -> first;
         *int y = it -> second;
         *bool flag = false;
         *int rem = x;
         *for (int i = 0; i <= m; ++i) {
         *    if (mp.find(x) == mp.end()) {
         *        flag = true;
         *        break;
         *    }
         *    x = mp[x];
         *}
         */

        while (true) {
            /*printf("res = %d\n", res);*/
            if (mp.begin() == mp.end())
                break;
            auto it = mp.begin();
            int x = it -> first;
            int rem = it -> second;
            while (true) {
                if (mp.find(x) == mp.end()/* || mp[x] == rem*/) {
                    /*printf("x = %d\n", x);*/
                    /*printf("cpy = %d\n", cpy[x]);*/
                    if (cpy[x] == rem)
                        ++res;
                    break;
                }
                int tem = mp[x];
                mp.erase(x);
                x = tem;
            }
        }
        printf("%d\n", res);
        /*flag ? printf("%d\n", res) : printf("%d\n", ++res);*/
    }
    return 0;
}
