/*----------------------------------------------------------------
 *
 *   文件名称：C--.cpp
 *   创建日期：2020年10月31日 ---- 16时14分
 *   题    目：codeforce
 *   算    法：逆元，组合数，阶乘，二分查找，快速幂
 *   描    述：1. 使用二分查找找到给定位置的过程中需要记录所有mid中有多少
 *                位置是大于给定位置的，有多少是小于给定位置的
 *             2. 记录到的大于给定位置的位置数cnt_big，所有大于给定位置的位置can_big
 *             3. 记录到的小于给定位置的位置数cnt_less，所有小于给定位置的位置can_less
 *             4. A_{can_big}^{cnt_big} * A_{can_less}^{cnt_less} * (n-1-cnt_big-cnt_less)!
 *             5. 即C_{can_big}^{cnt_big} * (cnt_big)! * A_{can_less}^{cnt_less} * (cnt_less)! * (n-1-cnt_big-cnt_less)!
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

void binarySearch (int n, int x_position, int &cnt_big, int &cnt_less) {
    int left = 0;
    int right = n;
    /*
     *int mid = left + ((right - left) << 1);
     *while (mid != x_position) {
     *    if (mid < x_position) {
     *        left = mid + 1;
     *        cnt_less++;
     *    }
     *    else if(mid > x_position) {
     *        right = mid;
     *        cnt_big++;
     *    }
     *    mid = left + ((right - left) << 1);
     *}
     */
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (mid <= x_position) {
            if (mid != x_position)
                cnt_less++;
            left = mid + 1;
        }
        else if(mid > x_position) {
            right = mid;
            cnt_big++;
        }
    }
}

int binaryPow(int base, int expo) {
    int res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1LL * res * base) % mod;

        base = (1LL * base * base) % mod;
        expo >>= 1;
    }
    return res;
}

int C(int n, int k, const vector<long long> &fact, const vector<long long> &inv) {
    if (k > n)
        return 0;
    int multiply = (1LL * fact[n] * inv[k]) % mod;
    multiply = (1LL * multiply * inv[n-k]) % mod;
    return multiply;
}

int main() {
    int n;
    int x;
    int x_position;
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &x_position);
    vector<long long> fact(n + 1, 1LL);
    vector<long long> inv(n + 1, 1LL);
    inv[1] = 1;
    for (int i = 2; i < n+1; ++i) {
        fact[i] = fact[i-1] * i % mod;
        //inv[i]  = binaryPow(fact[i], mod-2);
        inv[i] = (mod - mod/i) % mod * inv[mod%i] % mod;
    }

    int cnt_big = 0;
    int cnt_less = 0;
    binarySearch(n, x_position, cnt_big, cnt_less);

    int other = (n - cnt_less - cnt_big - 1);
    int can_big = n - x;
    int can_less = x - 1;

    int countLess = C(can_less, cnt_less, fact, inv);
    int countBig = C(can_big, cnt_big, fact, inv);

    countBig = (1LL * countBig * fact[cnt_big]) % mod;
    countLess = (1LL * countLess * fact[cnt_less]) % mod;

    int multiply = (1LL * countBig * countLess) % mod;
    multiply = (1LL * multiply * fact[other]) % mod;

    long long res = multiply % mod;
    printf("%lld\n", res);

    return 0;
}
