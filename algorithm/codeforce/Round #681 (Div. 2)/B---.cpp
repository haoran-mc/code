/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：B---.cpp
 *   创建日期：2020年11月03日 ---- 14时10分
 *   结束日期：2020年11月03日 ---- 14时18分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：昨天刚结束就想到直接处理这个数组就行，不需要还判断奇偶数
 *             TMD! 果不其然
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int A;
        int B;
        scanf("%d", &A);
        scanf("%d", &B);
        string mine;
        int coin = 0;
        cin >> mine;
        vector<int> vec;
        if (mine.find('1') == string::npos) {
            printf("0\n");
            continue;
        }
        int pos1 = mine.find('1');
        int sum0 = 0;
        int sum1 = 0;
        while(true) {
            if (mine.find('0', pos1+1) == string::npos)
                break;
            int pos0 = mine.find('0', pos1+1);

            if (mine.find('1', pos0+1) == string::npos)
                break;
            pos1 = mine.find('1', pos0+1);

            if ((pos1 - pos0) * B > A) {
                vec.push_back(0);
                ++sum0;
            }
            else {
                vec.push_back(pos1 - pos0);
                sum1 += pos1 - pos0;
            }
        }
        coin = sum1 * B + (sum0 + 1) * A;
        printf("%d\n", coin);
    }
    return 0;
}
