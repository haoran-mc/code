/*----------------------------------------------------------------
 *
 *   文件名称：1048 find coins.cpp
 *   创建日期：2020年09月09日 ---- 10时34分
 *   结束日期：2020年09月09日 ---- 12时02分
 *   题    目：pat
 *   算    法：二分，散列，two pointers
 *   描    述：- 排序
 *             - 使用upper_bound寻找M - coins[i]
 *             - !! it - coins.begin() <= i 这种情况下就不再循环进行了
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int M;
    scanf("%d", &N);
    scanf("%d", &M);
    vector<int> coins;
    for (int i = 0; i < N; i++) {
        int coin;
        scanf("%d", &coin);
        coins.push_back(coin);
    }
    sort(coins.begin(), coins.end());
    for (int i = 0; i < N; i++) {
        auto it = upper_bound(coins.begin(), coins.end(), M - coins[i]) - 1;
        if (it - coins.begin() <= i)
            break;
        if (*it + coins[i] == M && it - coins.begin() != i) {
            printf("%d %d\n", coins[i], *it);
            exit(0);
        }
    }
    printf("No Solution\n");
    return 0;
}
