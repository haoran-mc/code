/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年10月27日 ---- 23时26分
 *   题    目：codeforce
 *   算    法：最小公倍数
 *   描    述：在[0, lcm]的区间里，是否存在
 *             [nx1-x/2, nx1]与[nx2-x/2, nx2]有重合区间
 *             如果有，说明YES，否则NO
 *             \\错了错了，开辟的数组空间太大，编译不成功
 *
----------------------------------------------------------------*/

#include <cstdio>

typedef long long ill;
const int maxn = 1e9+1;
bool leftList[maxn];
bool rightList[maxn];

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
        ill lcm = getlcm(left, right);
        for (ill i = 0; i <= lcm; ++i) {
            if (left & 1 && i % left > left/2)
                leftList[i] = true;
            else if ((left & 1) != 1 && i % left >= left/2)
                leftList[i] = true;
        }
        for (ill i = 0; i <= lcm; ++i) {
            if (right & 1 && i % right > right/2)
                rightList[i] = true;
            else if ((right & 1) != 1 && i % right >= right/2)
                rightList[i] = true;
        }
        bool flag = false;
        for (ill i = 0; i <= lcm; ++i) {
            if (rightList[i] == true && leftList[i] == true) {
                flag = true;
                break;
            }
        }
        if (flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
