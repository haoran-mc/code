#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
    int* arr = (int *)malloc(sizeof(int) * 10);
    printf("input 10 numbers:");
    int maxi = -INF, mini = INF;
    for (int i = 0; i < 10; i ++ ) {
        scanf("%d", &arr[i]);
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    printf("%d %d\n", maxi, mini);
    return 0;
}
