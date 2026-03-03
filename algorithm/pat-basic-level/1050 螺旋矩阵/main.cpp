#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1e4 + 5;
int arr[maxn];
int g[maxn][maxn];
// 右、下、左、上
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    reverse(arr, arr + N);

    int n = 0, m = 0;
    for (int i = sqrt(N); i > 0; i--) {
        if (N % i == 0) {
            n = i;
            m = N / i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = -1;
        }
    }
    int d = 0; // 0, 1, 2, 3
    int x = 0, y = 0, idx = 0;
    while (true) {
        // cout << x << " " << y << endl;
        // 当前步
        g[x][y] = arr[idx];
        idx++;

        if (idx == N) { // 填完，终步条件
            break;
        }

        // 下一步
        int nextx = x + dx[d];
        int nexty = y + dy[d];
        if (g[nextx][nexty] == -1) {
            x = nextx;
            y = nexty;
        } else {
            d = (d + 1) % 4;
            x = x + dx[d];
            y = y + dy[d];
        }
    }
    // 先输出行，再输出列
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << g[i][j];
            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
