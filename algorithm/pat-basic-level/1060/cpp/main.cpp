// 260227 17:02 Fri
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e5;
int arr[maxn];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int E = 0;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i + 1] > N - i - 1) {
            // 有 N-i-1 天超过了 N-i-1 公里
            E = max(E, N - i - 1);
            break;
        }
    }
    if (arr[0] > N)
        cout << N;
    else
        cout << E;
    return 0;
}
