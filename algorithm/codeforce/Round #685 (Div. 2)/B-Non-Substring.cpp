/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年11月21日 ---- 23时17分
 *   题    目：codeforce
 *   算    法：深度优先搜索
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int L;
int R;

// 正在匹配idx的位置，已经匹配成功了cnt
bool DFS(int idx, int cnt, string str, int &flag) {
    if (str.find(str[L+cnt], idx+1) != string::npos && flag != R-L+1 && cnt == R-L+1)
        return true;
    else if (str.find(str[L+cnt], idx+1) == string::npos)
        return false;
    else if (str.find(str[L+cnt], idx+1) != string::npos && cnt < R-L+1) {
        while (str.find(str[L+cnt], idx+1) != string::npos) {
            if (DFS((int)str.find(str[L+cnt], idx+1), cnt, str, flag))
                return true;
            else {
                idx = (int)str.find(str[L+cnt], idx+1);
                --flag;
            }
            /*
             *if ((int)str.find(str[L+cnt], idx+1) == idx+1) {
             *    ++flag;
             *    ++cnt;
             *    DFS((int)str.find(str[L+cnt], idx+1), cnt, str, flag);
             *}
             *else {
             *    ++cnt;
             *    DFS((int)str.find(str[L+cnt], idx+1), cnt, str, flag);
             *}
             */
        }
    }
    return false;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int len;
        int query;
        string str;
        cin >> len >> query;
        cin >> str;
        while (query--) {
            int flag = 0;
            cin >> L >> R;
            DFS(-1, 0, str, flag) ? printf("YES\n") : printf("NO\n");
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
