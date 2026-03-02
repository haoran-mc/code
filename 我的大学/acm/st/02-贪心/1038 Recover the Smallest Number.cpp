/*----------------------------------------------------------------
 *
 *   文件名称：1038 Recover the Smallest Number.cpp
 *   创建日期：2020年08月28日 ---- 11时41分
 *   结束日期：2020年08月28日 ---- 15时05分
 *   题    目：Recover the Smallest Number
 *   算    法：贪心
 *   描    述：cmp函数是关键，这谁想得到呀
 *
----------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string A, string B) {
    return A+B < B+A;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<string> segment;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        segment.push_back(str);
    }
    sort(segment.begin(), segment.end(), cmp);
    /*
     *for (int i = 0; i < (int)segment.size()-1; i++) {
     *    if (segment[i+1].find(segment[i]) != string::npos) {
     *        for (int i = segment[i].size(); i < (int)segment[i+1].size(); i++) {
     *            if (i == (int)segment[i+1].size()-1 || segment[i+1][segment[i+1].size()-1] == segment[i][segment[i].size() -1]) {
     *                segment[i] += segment[i+1];
     *                segment.erase(segment.begin() + i + 1);
     *                break;
     *            }
     *        }
     *    }
     *}
     */
    for (int i = 1; i < n; i++)
        segment[0] += segment[i];

    int flag = 0;
    for (int i = 0; i < (int)segment[0].length(); i++) {
        if (segment[0][i] == '0' && flag == 0)
            continue;
        else {
            flag = 1;
            printf("%c", segment[0][i]);
        }
    }

    if (flag == 0)
        printf("0");

    return 0;
}

/*
 *    #include <iostream>
 *    #include <string>
 *    #include <algorithm>
 *    using namespace std;
 *    const int maxn = 10010;
 *    string str[maxn];
 *
 *    bool cmp(string a, string b) {
 *        return a+b < b+a;
 *    }
 *
 *    int main()
 *    {
 *        int n;
 *        cin >> n;
 *        for (int i = 0; i < n; i++)
 *            cin >> str[i];
 *        sort(str, str+n, cmp);
 *        string ans;
 *        for (int i = 0; i < n; i++)
 *            ans += str[i];
 *        while (ans.size() !=  0 && ans[0] == '0')
 *            ans.erase(ans.begin());
 *        if (ans.size() == 0)
 *            cout << 0;
 *        else
 *            cout << ans;
 *        return 0;
 *    }
 */


