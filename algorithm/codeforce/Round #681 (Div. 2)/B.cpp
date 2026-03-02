/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年11月02日 ---- 23时19分
 *   题    目：codeforce
 *   算    法：贪心
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
#define bug printf("******\n");
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
        while(true) {
            if (mine.find('0', pos1+1) == string::npos)
                break;
            int pos0 = mine.find('0', pos1+1);

            if (mine.find('1', pos0+1) == string::npos)
                break;
            pos1 = mine.find('1', pos0+1);

            if ((pos1 - pos0) * B > A)
                vec.push_back(inf);
            else
                vec.push_back(pos1 - pos0);
        }
        auto it0 = vec.begin();
        auto it1 = vec.begin();
        while (it1 != vec.end()) {
            if (*it1 == inf && it1+1 != vec.end())
                coin += A;
            else if (*it1 == inf && it1+1 == vec.end())
                coin += 2*A;
            else {
                while (*it1 != inf) {
                    if (it1 == vec.end())
                        break;
                    ++it1;
                }
                if ((it1 - it0) & 1) {
                    while (it0 < it1) {
                        coin += (*it0) * B;
                        coin += A;
                        it0  += 2;
                    }
                }
                else {
                    auto it9 = it0;
                    auto it8 = it0;
                    int maxpay = 0;
                    while (it9 != it1) {
                        if (*it9 > maxpay) {
                            maxpay = *it9;
                            it8 = it9;
                        }
                        ++it9;
                    }
                    if ((it8 - it0) & 1) {
                        while (it0 <it1) {
                            if (it0 + 1 == it8)
                                ++it0;
                            coin += (*it0) * B;
                            coin += A;
                            it0  += 2;
                        }
                    }
                    else {
                        --it8;
                        while (it0 <it1) {
                            if (it0 + 1 == it8)
                                ++it0;
                            coin += (*it0) * B;
                            coin += A;
                            it0  += 2;
                        }
                    }
                    /*
                     *if (*it0 < *(it1-1)) {
                     *    while (it0 < it1-1) {
                     *        coin += (*it0) * B;
                     *        coin += A;
                     *        it0  += 2;
                     *    }
                     *    coin += A;
                     *}
                     *else {
                     *    it0 += 1;
                     *    while (it0 < it1) {
                     *        coin += (*it0) * B;
                     *        coin += A;
                     *        ito  += 2;
                     *    }
                     *}
                     */
                }
            }
            it0 = it1;
            ++it1;
        }
        printf("%d\n", coin);
    }
    return 0;
}
