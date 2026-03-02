/*----------------------------------------------------------------
 *
 *   文件名称：B.cpp
 *   创建日期：2020年10月24日 ---- 22时27分
 *   结束日期：2020年10月24日 ---- 23时27分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5;
const int n    = 100;
int square[n][n];
int prime[maxn];
bool sifter[maxn];
int seek = 0;

void primeList() {
    for (int i = 2; i < maxn; i++) {
        if (sifter[i] == false)
            prime[seek++] = i;

        for (int j = 0; j < seek; j++) {
            if (i * prime[j] > maxn)
                break;

            sifter[i * prime[j]] = true;

            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    primeList();
    while (t--) {
        int size;
        scanf("%d", &size);
        for (int i = 0; i < size-1; i++)
            for (int j = 0; j < size-1; j++)
                square[i][j] = 1;

        //找到最后一列的大多数元素
        int sumPrime = size - 1;
        for (int j = 0; j < seek; j++) {
            if (prime[j] > sumPrime && sifter[prime[j] - sumPrime] == true) {
                sumPrime = prime[j];
                break;
            }
        }
        sumPrime -= size - 1;
        //最后一列
        for (int i = 0; i < size-1; i++)
            square[i][size-1] = sumPrime;

        //最后一行
        for (int i = 0; i < size-1; i++)
            square[size-1][i] = sumPrime;

        sumPrime *= (size-1);
        for (int j = 0; j < seek; j++) {
            if (prime[j] > sumPrime && sifter[prime[j] - sumPrime] == true) {
                sumPrime = prime[j];
                break;
            }
        }
        sumPrime -= (size-1) * square[0][size-1];
        square[size-1][size-1] = sumPrime;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", square[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
