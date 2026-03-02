#include <cstdio>
const int maxn = 1000001;
int N, K;
int arr[maxn];
int quu[maxn];
int idx[maxn];
int res[maxn];

void getMins() {
    int head = 1; //初始化tail < head表示为空列
    int tail = 0;
    for (int i = 1; i < K; ++i) { //初始化单调队列
        while (tail >= head && quu[tail] >= arr[i])
            tail--;
        quu[++tail] = arr[i];        //记录可能的答案值
        idx[tail] = i;    //记录额外需要判断的信息
    }
    for (int i = K; i <= N; ++i) {
        while (tail >= head && quu[tail] >= arr[i])
            tail--; //不符合条件出列
        quu[++tail] = arr[i];
        idx[tail] = i;
        while (idx[head] <= i-K)
            head++;
        res[i-K] = quu[head];    //res从下标0开始记录
    }
}

void getMaxs() {
    int head = 1;
    int tail = 0;
    for (int i = 1; i < K; ++i) { //初始化单调队列
        while (tail >= head && quu[tail] <= arr[i])
            tail--;
        quu[++tail] = arr[i];
        idx[tail] = i;
    }
    for (int i = K; i <= N; ++i) {
        while (tail >= head && quu[tail] <= arr[i])
            tail--; //不符合条件出列
        quu[++tail] = arr[i];
        idx[tail] = i;
        while (idx[head] <= i-K)
            head++;
        res[i-K] = quu[head];    //res从下标0开始记录
    }
}

int main() {
    while (~scanf("%d %d", &N, &K)) {
        for (int i = 1; i <= N; ++i)
            scanf("%d", &arr[i]);
        getMins();
        for (int i = 0; i <= N-K; ++i)
            printf("%d ", res[i]);
        putchar('\n');
        getMaxs();
        for (int i = 0; i <= N-K; ++i)
            printf("%d ", res[i]);
        putchar('\n');
    }
    return 0;
}
