#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int flag[maxn];

int main() {
    int n;
    cin >> n;
    int arr[maxn];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 正向一遍
    int maxnum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxnum) {
            flag[i]++; // 表示第 i 位数满足正向的主元
            maxnum = arr[i];
        }
    }
    // 反向一遍
    int minnum = INF;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < minnum) {
            flag[i]++;
            minnum = arr[i];
        }
    }

    priority_queue<int, vector<int>, greater<int>> pqu; // 小顶堆
    for (int i = 0; i < n; i++) {
        if (flag[i] == 2) {
            pqu.push(arr[i]);
        }
    }
    cout << pqu.size() << endl;
    while (!pqu.empty()) {
        int num = pqu.top();
        pqu.pop();
        cout << num;
        if (!pqu.empty()) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
