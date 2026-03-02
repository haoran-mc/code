/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月11日 ---- 10时16分
 *   题    目：AcWing 998 起床困难综合症
 *   算    法：二进制
 *   描    述：里面只涉及了二进制的操作，而or, xor, and这些操作不会进位
 *          所以只需要考虑每个位就行了
 *          循环遍历位时需要从高位到低位，假设如果不限制m，能够得到的
 *          最大的初始数是1010101，如今限制了m = 65
 *          从高位开始就是，先加上一个64，然后最后加上一个1
 *          如果从低位开始，1 + 4 + 16 = 21，这样是错误的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <utility>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
pair<string, int> op[maxn];

//用参数的第bit位进行n此运算
int calc(int bit, int now) {
    for (int i = 0; i < n; ++i) {
        int x = op[i].second >> bit & 1;
        if (op[i].first == "AND")
            now &= x;
        else if (op[i].first == "OR")
            now |= x;
        else
            now ^= x;
    }
    return now;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string str;
        int x;
        cin >> str >> x;
        op[i] = make_pair(str, x);
    }
    //val是初始的伤害，res是最终能造成的伤害
    int val = 0, res = 0;
    for (int bit = 29; bit >= 0; --bit) { //m < 1e9，所以位数不超过30
        int res0 = calc(bit, 0); //如果第bit位是0，最终的结果是res0
        int res1 = calc(bit, 1); //如果第bit位是1，最终的结果是res1
        if (val + (1 << bit) <= m && res0 < res1)
            val += 1 << bit, res += res1 << bit;
        else
            res += res0 << bit;
    }
    cout << res << endl;
    return 0;
}
