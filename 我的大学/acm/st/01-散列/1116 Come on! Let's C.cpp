/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1116 Come on! Let's C.cpp
 *   创建日期：2020年08月21日 ---- 09时08分
 *   结束日期：2020年08月21日 ---- 23时08分
 *   题    目：Come on! Let's C
 *   算    法：散列
 *   描    述：公布排名，寻找排名
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>

const int N = 1e5 + 2;
int count = 1;
int rank[N];
int prime[N];
bool sifter[N] = {0};

void primeNum() {
    for (int i = 2; i < N; i++) {
        if (sifter[i] == false)
            prime[count++] = i;

        for (int j = 1; j < count; j++) {
            if (i * prime[j] <= N)
                sifter[i * prime[j]] = true;
            else
                break;

            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    int count = 0;
    int rank_n;
    int rank_k;
    int ID;
    scanf("%d", &rank_n);
    while (rank_n--) {
        count++;
        scanf("%d", &ID);
        rank[ID] = count;
    }

    scanf("%d", &rank_k);
    primeNum();
    while (rank_k--) {
        scanf("%d", &ID);
        if (rank[ID] == -1)
            printf("%04d: Checked\n", ID);

        else if (rank[ID] == 0)
            printf("%04d: Are you kidding?\n", ID);

        else if (rank[ID] == 1) {
            printf("%04d: Mystery Award\n", ID);
            rank[ID] = -1;
        }

        else if (sifter[rank[ID]] == 0) {
            printf("%04d: Minion\n", ID);
            rank[ID] = -1;
        }

        else {
            printf("%04d: Chocolate\n", ID);
            rank[ID] = -1;
        }
    }

    return 0;
}

