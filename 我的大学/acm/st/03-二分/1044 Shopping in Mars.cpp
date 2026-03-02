/*----------------------------------------------------------------
 *
 *   文件名称：1044 Shopping in Mars.cpp
 *   创建日期：2020年09月08日 ---- 14时37分
 *   题    目：PAT
 *   算    法：二分
 *   描    述：推倒重来
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;

struct Chain {
    int diamond;
    int sum;
    int end;
};
vector<Chain> chain;
int N;
int M;

int binarySearch(int i) {
    int left  = i;
    int right = N;

    if (chain[i].diamond == M)
        return i;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int ans = chain[mid].sum - chain[i-1].sum;
        if (ans == M)
            return mid;
        else if (ans < M)
            left  = mid + 1;
        else if (ans > M)
            right = mid - 1;
    }
    return -1;
}

void fillEnd() {
    chain[0].end = -1;
    for (int i = 0; i < N; i++) {
        if (chain[i].sum == M)
            chain[0].end = i;
    }

    for (int i = 1; i < N; i++) {
        int end = binarySearch(i);
        chain[i].end = end;
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < N; i++) {
        Chain x;
        scanf("%d", &x.diamond);

        if (i == 0)
            x.sum = x.diamond;
        else
            x.sum = chain[i-1].sum + x.diamond;

        x.end = 0;
        chain.push_back(x);
    }

    fillEnd();
    for (int i = 0; i < N; i++)
        if (chain[i].end != -1)
            printf("%d-%d\n", i+1, chain[i].end+1);


        printf("\n\n");
    for (int i = 0; i < N; i++) {
        printf("diamond = %d\n", chain[i].diamond);
        printf("sum     = %d\n", chain[i].sum);
        printf("end     = %d\n", chain[i].end);
        printf("\n");
    }


    return 0;
}
