/*----------------------------------------------------------------
 *
 *   文件名称：C1.cpp
 *   创建日期：2020年09月20日 ---- 21时54分
 *   题    目：nowcoder
 *   算    法：递归归并
 *   描    述：题解
 *
----------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//const int mod = 1e9 + 7;
const int mod = 998244353;

const double eps = 1e-6;
const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int N = 5e3 + 5;
const ll inf = 0x3f3f3f3f;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, match[maxn];
string s;

int getv(char c) {
   return c - 'A' + 1;
}

ll solve(int l, int r) {
    ll res = 0, num = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            ll tmp = solve(i + 1, match[i] - 1);
            i = match[i] + 1;
            while (i <= r && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            i--;
            if (num != 0)
                res += num * tmp;
            else res += tmp;
                num = 0;
        }
        else {
            if (i + 1 <= r && isdigit(s[i + 1])) {
                int x = i + 1;
                while (x <= r && isdigit(s[x])) num = num * 10 + s[x] - '0', x++;
                res += num * getv(s[i]);
                i = x - 1;
                num = 0;
            }
            else res += getv(s[i]);
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
