/*----------------------------------------------------------------
 *
 *   文件名称：1018.cpp
 *   创建日期：2020年11月01日 ---- 10时12分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：艹，服了，一次没赢需要输出B
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define bug printf("******\n");

struct compete {
    int win;
    int tie;
    int fail;
    map<char, int> mp;
}info[2];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; ++i) {
        char ch0;
        char ch1;
        scanf("%c %c", &ch0, &ch1);
        //printf("ch0 = %c\nch1 = %c\n", ch0, ch1);
        if (ch0 == 'B') {
            if (ch1 == 'B') {
                info[0].tie++;
                info[1].tie++;
            }
            else if (ch1 == 'C') {
                info[0].win++;
                info[0].mp['B']++;
                info[1].fail++;
            }
            else if (ch1 == 'J') {
                info[0].fail++;
                info[1].win++;
                info[1].mp['J']++;
            }
        }
        else if (ch0 == 'J') {
            if (ch1 == 'J') {
                info[0].tie++;
                info[1].tie++;
            }
            else if (ch1 == 'B') {
                info[0].win++;
                info[0].mp['J']++;
                info[1].fail++;
            }
            else if (ch1 == 'C') {
                info[0].fail++;
                info[1].win++;
                info[1].mp['C']++;
            }
        }
        else if (ch0 == 'C') {
            if (ch1 == 'C') {
                info[0].tie++;
                info[1].tie++;
            }
            else if (ch1 == 'J') {
                info[0].win++;
                info[0].mp['C']++;
                info[1].fail++;
            }
            else if (ch1 == 'B') {
                info[0].fail++;
                info[1].win++;
                info[1].mp['B']++;
            }
        }
        getchar();
        //printf("info[0].tie = %d\n", info[0].tie);
        //printf("info[1].tie = %d\n", info[1].tie);
    }
    printf("%d %d %d\n", info[0].win, info[0].tie, info[0].fail);
    printf("%d %d %d\n", info[1].win, info[1].tie, info[1].fail);
    char ch0 = 'B';
    int max0 = -1;
    for (auto it = info[0].mp.begin(); it != info[0].mp.end(); ++it) {
        if (it -> second > max0) {
            max0 = it -> second;
            ch0 = it -> first;
        }
        else if (it -> second == max0)
            if (it -> first < ch0)
                ch0 = it -> first;
    }
    char ch1 = 'B';
    int max1 = -1;
    for (auto it = info[1].mp.begin(); it != info[1].mp.end(); ++it) {
        if (it -> second > max1) {
            max1 = it -> second;
            ch1 = it -> first;
        }
        else if (it -> second == max1)
            if (it -> first < ch1)
                ch1 = it -> first;
    }
    printf("%c %c\n", ch0, ch1);
    return 0;
}
