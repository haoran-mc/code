/*----------------------------------------------------------------
 *
 *   文件名称：1013.cpp
 *   创建日期：2020年10月20日 ---- 00时11分
 *   结束日期：2020年10月20日 ---- 15时20分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>

const int maxn = 1e6;
int count = 1;
int prime[maxn];
bool sifter[maxn];

void primeList() {
    for (int i = 2; i < maxn; i++) {
        if (sifter[i] == false)
            prime[count++] = i;

        for (int j = 1; j < count; j++) {
            if (i * prime[j] > maxn)
                break;

            sifter[i * prime[j]] = true;

            //i > count，且prime数组里存的就是i，i > prime[j]
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    primeList();
    int M;
    int N;
    scanf("%d", &M);
    scanf("%d", &N);
    count = 1;
    for (int i = M; i <= N; i++, count++) {
        if (count % 10 == 0 || i == N)
            printf("%d\n", prime[i]);
        else
            printf("%d ", prime[i]);
    }
    return 0;
}
