/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1037 Magic Coupon.cpp
 *   创建日期：2020年08月28日 ---- 11时00分
 *   结束日期：2020年08月28日 ---- 11时29分
 *   题    目：Magic Coupon
 *   算    法：贪心
 *   描    述：分为正负数
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int A, int B) {
    return A > B;
}

int main() {
    int Nc;
    scanf("%d", &Nc);
    vector<int> coupon;
    for (int i = 0; i < Nc; i++) {
        int x;
        scanf("%d", &x);
        coupon.push_back(x);
    }

    int Np;
    scanf("%d", &Np);
    vector<int> product;
    for (int i = 0; i < Np; i++) {
        int x;
        scanf("%d", &x);
        product.push_back(x);
    }

    sort(coupon.begin(),  coupon.end(),  cmp);
    sort(product.begin(), product.end(), cmp);
    int back = 0;
    for (auto it1 = coupon.begin(), it2 = product.begin(); ; it1++, it2++) {
        if (*it1 > 0 && *it2 > 0)
            back += (*it1) * (*it2);
        else
            break;
    }

    for (auto it1 = coupon.end()-1, it2 = product.end()-1; ; it1--, it2--) {
        if (*it1 < 0 && *it2 < 0)
            back += (*it1) * (*it2);
        else
            break;
    }

    printf("%d\n", back);
    return 0;
}

