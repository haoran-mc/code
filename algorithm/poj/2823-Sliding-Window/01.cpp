#include <cstdio>
const int maxn = 1e6 + 5;
int arr[maxn];
int quu[maxn];
int n, k;

void getMin() {
    int head = 0;
    int tail = 0;
    for (int i = 0; i < k; ++i) {
        while (tail >= head && arr[i] <= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
    }
    printf("%d", arr[quu[head]]);
    for (int i = k; i < n; ++i) {
        while (tail >= head && arr[i] <= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
        while (tail >= head && quu[head] <= i - k)
            ++head;
        printf(" %d", arr[quu[head]]);
    }
    printf("\n");
}

void getMax() {
    int head = 0;
    int tail = 0;
    for (int i = 0; i < k; ++i) {
        while (tail >= head && arr[i] >= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
    }
    printf("%d", arr[quu[head]]);
    for (int i = k; i < n; ++i) {
        while (tail >= head && arr[i] >= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
        while (tail >= head && quu[head] <= i - k)
            ++head;
        printf(" %d", arr[quu[head]]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    getMin();
    getMax();
    return 0;
}
