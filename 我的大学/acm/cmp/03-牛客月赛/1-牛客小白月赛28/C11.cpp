/*----------------------------------------------------------------
 *
 *   文件名称：C1.cpp
 *   创建日期：2020年09月20日 ---- 21时54分
 *   题    目：nowcoder
 *   算    法：递归归并
 *   描    述：题解
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

typedef long long ill;
const int maxn = 1e6 + 10;
int n;
int match[maxn];
string s;

int getv(char c) {
   return c - 'A' + 1;
}

ill solve(int left, int right) {
    ill res = 0, num = 0;
    for (int i = left; i <= right; i++) {
        if (s[i] == '(') {
            ill tmp = solve(i + 1, match[i] - 1);
            i = match[i] + 1;
            while (i <= right && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            i--;
            if (num != 0)
                res += num * tmp;
            else
                res += tmp;
            num = 0;
        }
        else {
            if (i + 1 <= right && isdigit(s[i + 1])) {
                int x = i + 1;
                while (x <= right && isdigit(s[x])) {
                    num = num * 10 + s[x] - '0';
                    x++;
                }
                res += num * getv(s[i]);
                i = x - 1;
                num = 0;
            }
            else
                res += getv(s[i]);
        }
    }
    return res;
}

int main()
{
    cin >> s;
    n = s.length();
    s = '.' + s;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            match[st.top()] = i;
            st.pop();
        }
    }
    cout << solve(1, n);
    return 0;
}
