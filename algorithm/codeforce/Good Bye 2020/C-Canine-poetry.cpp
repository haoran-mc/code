#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int mod = '9';

vector<int> radius, let;
string expa_str;
void Manacher(const string &str, int &pos, int &max_len) {
    int orig_len = str.length();
    int expa_len = (orig_len + 1) << 1;
    max_len  = 0;
    radius.resize(expa_len + 1);
    expa_str.resize(expa_len + 1);
    //@#0#1#2#3#4#5#6#7#8#9#$
    expa_str[0] = '@';
    expa_str[1] = '#';
    expa_str[expa_len] = '$';
    for (int i = 1; i <= orig_len; ++i) {
        expa_str[i << 1] = str[i-1];
        expa_str[i << 1 | 1] = '#';
    }
    radius[1] = 1;
    for (int max_R = 0, center = 0, i = 2; i < expa_len; ++i) {
        radius[i] = i < max_R ? min(max_R-i, radius[2*center-i]) : 1;
        while (expa_str[i-radius[i]] == expa_str[i+radius[i]])
            ++radius[i];
        if (radius[i] + i > max_R) {
            max_R = radius[i] + i;
            center = i;
        }
        if (radius[i]-1 > max_len) {
            max_len = radius[i]-1;
            pos     = (center - radius[i] + 1) << 1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        char ch = '0';
        int cnt = 0;
        for (int i = 0; i < (int)str.length()-1; ++i)
            if (str[i] == str[i+1]) {
                str[i] = (ch % mod);
                (++ch) %= mod;
                ++cnt;
            }
        cout << str << " ";
        int max_len;
        int pos;
        Manacher(str, pos, max_len);
        cout << pos << " " << max_len << endl;
        /*
         *while (max_len != 1) {
         *    if (max_len & 1)
         *        str[pos + (max_len/2-2)] = (ch % mod);
         *    else
         *        str[pos + (max_len/2-1)] = (ch % mod);
         *    ch %= mod;
         *    ++cnt;
         *    cout << str << " ";
         *    //Manacher(str, pos, max_len);
         *}
         */
        printf("%d\n", cnt);
    }
    return 0;
}
