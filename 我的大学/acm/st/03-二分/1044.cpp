/*----------------------------------------------------------------
 *
 *   文件名称：1044 Shopping in Mars.cpp
 *   创建日期：2020年09月08日 ---- 14时37分
 *   题    目：PAT
 *   算    法：二分
 *   描    述：- 求子序列的和sum[j] - sum[i]
 *             - 结构体使用二分查找函数
 *             - 重载运算符
 *             - 构造结构体，存储从第一个宝石到当前宝石的所有宝石价值之和
 *             - 由于宝石价值为正整数，sum值单增
 *             - 子序列的和是sum[j] - sum[i]
 *             - 使用upper_bound查找sum[i] + M
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Chain {
    int diamond;
    int sum;
    int end;
    int lesspay;
    Chain() {}
    Chain(int _diamond, int _sum, int _end, int _lesspay): diamond(_diamond), sum(_sum), end(_end), lesspay(_lesspay) {}
    bool operator < (const Chain x) const {
        return sum < x.sum;
    }
};
vector<Chain> chain;
int N;
int M;
int minpay = 0;

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            Chain x;
            x.diamond = 0;
            x.sum = 0;
            x.end = 0;
            x.lesspay = 0;
            chain.push_back(x);
            continue;
        }
        Chain x;
        scanf("%d", &x.diamond);
        x.sum = chain[i-1].sum + x.diamond;
        x.end = 0;
        x.lesspay = 0;
        chain.push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        vector<Chain>::iterator it = upper_bound(chain.begin() + i, chain.end(), Chain(0, chain[i-1].sum + M, 0, 0));
        /*printf("%d ", (int)(it - chain.begin()));*/
        /*vector<Chain>::iterator it = upper_bound(chain.begin() + i, chain.end(), chain[i].sum + M);*/
        if ((it-1) -> sum == chain[i-1].sum + M) {
            chain[i].end = it - 1 - chain.begin();
            minpay = -1;
            printf("%d-%d\n", i, chain[i].end);
        }
        else if (it - chain.begin() <= N) {
            chain[i].lesspay = it -> sum - chain[i-1].sum;
            if (minpay != -1) {
                if (minpay == 0 || chain[i].lesspay <= minpay) {
                    minpay = chain[i].lesspay;
                    chain[i].end = it - chain.begin();
                }
            }
        }
    }
    if (minpay != -1) {
        for (int i = 0; i <= N; i++) {
            /*vector<Chain>::iterator it = upper_bound(chain.begin() + i, chain.end(), Chain(0, chain[i-1].sum + minpay, 0, 0)) - 1;*/
            /*printf("%d %d \n", i, it -> sum);*/
            /*if (it -> sum == chain[i-1].sum + minpay)*/
                /*printf("%d-%d\n", i, chain[i].end);*/
            if (chain[chain[i].end].sum - chain[i-1].sum == minpay)
                printf("%d-%d\n", i, chain[i].end);
        }
    }

    /*
     *printf("\n\n");
     *for (int i = 0; i <= N; i++) {
     *    printf("diamond = %d\n", chain[i].diamond);
     *    printf("sum     = %d\n", chain[i].sum);
     *    printf("end     = %d\n", chain[i].end);
     *    printf("lesspay = %d\n", chain[i].lesspay);
     *    printf("\n");
     *}
     */

    return 0;
}
