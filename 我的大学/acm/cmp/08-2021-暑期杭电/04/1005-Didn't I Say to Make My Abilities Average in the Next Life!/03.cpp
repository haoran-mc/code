#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define bug cout << "<-->\n";
string str;
typedef long long ll;

ll coe(int pos) {
    ll x = 0;
    pos++;
    while (isdigit(str[pos]))
        x = x * 10 + str[pos++] - '0';
    return x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> str;
        int pos = 0;
        ll csin = 0, _sin = 0;   // 存储系数
        ll ccos = 0, _cos = 0;   // 存储系数
        ll cx = 0, c_x = 0;      // 存储系数
        while (pos < (int)str.size()) {   // sinx
            pos = str.find("sinx", pos + 1);
            if (pos == string::npos)
                break;
            if (!isdigit(str[pos-1]))
                continue;
            int tmp = pos;
            while (tmp--)
                if (!isdigit(str[tmp]))
                    break;
            csin += coe(tmp);
        }
        pos = 0;
        while (pos < (int)str.size()) {   // cosx
            pos = str.find("cosx", pos + 1);
            if (pos == string::npos)
                break;
            if (!isdigit(str[pos-1]))
                continue;
            int tmp = pos;
            while (tmp--)
                if (!isdigit(str[tmp]))
                    break;
            ccos += coe(tmp);
        }
        while (pos < (int)str.size()) {   // sinx
            pos = str.find("/sinx", pos + 1);
            if (pos == string::npos)
                break;
            int tmp = pos;
            while (tmp--)
                if (!isdigit(str[tmp]))
                    break;
            _sin += coe(tmp);
        }
        pos = 0;
        while (pos < (int)str.size()) {   // _cosx
            pos = str.find("/cosx", pos + 1);
            if (pos == string::npos)
                break;
            int tmp = pos;
            while (tmp--)
                if (!isdigit(str[tmp]))
                    break;
            _cos += coe(tmp);
        }
        pos = 0;
        while (pos < (int)str.size()) {   // cx
            pos = str.find("x", pos + 1);
            if (pos == string::npos)
                break;
            if (!isdigit(str[pos-1]))
                continue;
            int tmp = pos;
            while (tmp--)
                if (!isdigit(str[tmp]))
                    break;
            cx += coe(tmp);
        }
        pos = 0;
        bool flag = false;
        while (pos < (int)str.size()) {   // c^x
            pos = str.find("^", pos + 1);
            if (pos == string::npos)
                break;
            int tmp = pos;
            while (tmp--)
                if (!isdigit(str[tmp]))
                    break;
            c_x = coe(tmp);
            if (!(c_x == 1 || c_x == 0)) {
                flag = true;
                break;
            }
        }
        cout << csin << " " << ccos << " " << _cos << " " << _sin << " " << cx << " " << c_x;
        if (csin != 0 || ccos != 0 || _cos != 0 || _sin != 0 || cx != 0 || flag)
            cout << "NO\n";
        else 
            cout << "YES\n";
    }
    return 0;
}
