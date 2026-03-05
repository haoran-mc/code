#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
unordered_map<int, int> unmp;

int turn(int state, int p) {
    state ^= (1 << p);
    if (p % 5)        state ^= (1 << (p - 1));  //如果存在十字架的左侧，turn
    if (p >= 5)       state ^= (1 << (p - 5));  //如果p >= 5，一定存在十字架上面一行，turn
    if ((p % 5) < 4)  state ^= (1 << (p + 1));  //如果存在十字架的右侧，turn
    if (p < 20)       state ^= (1 << (p + 5));  //如果p < 20，一定存在十字架下面一行，turn
    return state;
}

void BFS() {
    queue<int> quu;
    int now = (1 << 25) - 1;
    unmp[now] = 1;
    quu.push(now);
    while (!quu.empty()) {
        int top = quu.front();
        quu.pop();
        if (unmp[top] == 7) //超过6步
            break;
        for (int i = 0; i < 25; ++i) {
            now = turn(top, i);
            if (!unmp.count(now)) { //count :: 统计容器中等于now的个数
                unmp[now] = unmp[top] + 1;
                quu.push(now);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    BFS();
    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        for (int i = 0; i < 25; ++i) {
            char ch;
            cin >> ch;
            sum += ((ch - '0') << i);
        }
        cout << unmp[sum] - 1 << endl;
    }
    return 0;
}
