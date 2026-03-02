/*----------------------------------------------------------------
 *
 *   文件名称：1007.cpp
 *   创建日期：2020年10月19日 ---- 17时19分
 *   题    目：PAT
 *   算    法：欧拉筛法
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 1e5;
int count = 1;
int prime[maxn];
bool sifter[maxn];

void primeList() {
    for (int i = 2; i <= maxn; i++) {
        if (sifter[i] == false)
            prime[count++] = i;

        for (int j = 1; j < count; j++) {
            if (i * prime[j] > maxn)
                break;

            sifter[i * prime[j]] = true;

            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    primeList();
    count = 0;
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N - 2; i++)
        if (sifter[i] == false && sifter[i+2] == false)
            count++;

    printf("%d\n", count);

    return 0;
}
