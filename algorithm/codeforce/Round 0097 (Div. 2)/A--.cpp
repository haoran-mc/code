/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年10月27日 ---- 23时26分
 *   题    目：codeforce
 *   算    法：
 *   描    述：
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ill;

ill getgcd(ill left, ill right) {
    ill temp;
    while (right != 0) {
        temp  = right;
        right = left % right;
        left  = temp;
    }
    return left;
}

ill getlcm(ill left, ill right) {
    return left * right / getgcd(left, right);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ill left;
        ill right;
        scanf("%lld", &left);
        scanf("%lld", &right);
        if (left == 1) {
            printf("NO\n");
            continue;
        }
        //ill lcm = getlcm(left, right);
        /*
         *for (ill i = 2; i <= lcm; ++i) {
         *    if ((left % i) * 2 >= i && (right % i) * 2 >= i) {
         *        flag = true;
         *        break;
         *    }
         *}
         */
        bool outflag = false;
        int maxcan = 2 * min(left, right);
        for (ill i = 2; i <= maxcan; ++i) {
            bool flag = false;
            for (ill j = left; j <= right; ++j) {
                if ((j % i) * 2 < i)
                    flag = true;
            }
            if (flag == false) {
                printf("YES\n");
                outflag = true;
                break;
            }
        }

        if (outflag == false)
            printf("NO\n");
    }
    return 0;
}
