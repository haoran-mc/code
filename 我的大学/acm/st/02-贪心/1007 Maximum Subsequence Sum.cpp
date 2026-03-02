/*----------------------------------------------------------------
 *
 *   文件名称：1007 Maximum Subsequence Sum.cpp
 *   创建日期：2020年08月27日 ---- 10时08分
 *   结束日期：2020年08月27日 ---- 10时53分
 *   题    目：Maximum Subsequence Sum
 *   算    法：贪心
 *   描    述：使用struct，每个节点存着先前一段和，如果这个和sum
 *             为正数，那么加到后一个节点中的sum，否则以从一个数
 *             开始
 *             * -4 7 -14 20 16 -3  1 -7  9  2 -10 11
 *             * -4 7 -14 20 36 33 34 27 36 38  28 39
 *   这题判断是否全是负数时，不需要定义一个flag然后循环判断，当
 *   程序中有整体循环时，在这里判断
 *
----------------------------------------------------------------*/

#include <cstdio>

struct info{
    int num;
    int sum;
    int start;
} Num[10000];

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", &Num[i].num);

    Num[0].sum   = Num[0].num;
    Num[0].start = 0;

    for (int i = 1; i < k; i++) {
        if (Num[i-1].sum > 0) {
            Num[i].sum   = Num[i-1].sum + Num[i].num;
            Num[i].start = Num[i-1].start;
        }
        else {
            Num[i].sum   = Num[i].num;
            Num[i].start = i;
        }
    }

    int max   = -1;
    int index = 0;
    for (int i = 0; i < k; i++) {
        if (Num[i].sum > max) {
            max = Num[i].sum;
            index = i;
        }
    }

    if (max == -1)
        printf("0 %d %d\n", Num[0].num, Num[k-1].num);
    else
        printf("%d %d %d\n", max, Num[Num[index].start].num, Num[index].num);
    return 0;
}
