/*----------------------------------------------------------------
 *
 *   文件名称：A---.cpp
 *   创建日期：2020年10月30日 ---- 22时53分
 *   题    目：codeforce
 *   算    法：没有算法
 *   描    述：当pack < left时，需要 |--------+----+----+
 *                                          pack  left  right
 *             right - left < pack / 2
 *             left mod pack > pack / 2
 *             right mod pack < pack
 *
 *             当pack > left && pack < right时，不可能
 *
 *             当pack > right时，pack == right + 1时，最有可能满足条件
 *             这时需要2 * pack > right
 *
 *             以上第一条分析时不对，是right与left控制pack，而不是pack控制left与right
 *             所以正确的分析应该是left与right已知了，这种情况下pack最适合的位置就是在right+1
 *
----------------------------------------------------------------*/

//<++>

#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int left;
        int right;
        scanf("%d", &left);
        scanf("%d", &right);
        if (2 * left > right)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
