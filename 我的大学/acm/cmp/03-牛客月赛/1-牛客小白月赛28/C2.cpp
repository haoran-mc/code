/*----------------------------------------------------------------
 *
 *   文件名称：C2.cpp
 *   创建日期：2020年09月21日 ---- 21时57分
 *   题    目：nowcoder
 *   算    法：归并
 *   描    述：自己写一遍题解
 *             1. ascii码转换
 *             2. 判断是否为十进制数字
 *             3. 判断一个字符串中十进制数字有几位
 *             4. 堆栈括号匹配
 *             5. 递归
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <stack>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5 + 1;
typedef long long ill;
int match[maxn];
string s;

int ascii(char ch) {
    return ch - 'A' + 1;
}

ill bracket(int left, int right) {
    ill res = 0;
    ill behindNum = 0;
    for (int i = left; i < right; i++) {
        if (s[i] == '(') {
            ill tmp = bracket(i + 1, match[i]);
            i = match[i] + 1;
            while (i < right && isdigit(s[i])) {
                behindNum = behindNum * 10 + s[i] - '0';
                i++;
            }
            i--;
            if (behindNum != 0)
                res += behindNum * tmp;
            else
                res += tmp;
            behindNum = 0;
        }
        else {
            if (i + 1 < right && isdigit(s[i + 1])) {
                int x = i + 1;
                while (x < right && isdigit(s[x])) {
                    behindNum = behindNum * 10 + s[x] - '0';
                    x++;
                }
                res += behindNum * ascii(s[i]);
                i = x - 1;
                behindNum = 0;
            }
            else
                res += ascii(s[i]);
        }
    }
    return res;
}

int main()
{
    cin >> s;
    int n = s.length();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            match[st.top()] = i;
            st.pop();
        }
    }
    printf("%lld\n", bracket(0, n));
    return 0;
}
