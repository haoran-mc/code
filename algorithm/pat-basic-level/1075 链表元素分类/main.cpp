// 260305 15:19 Thu
// 260305 15:50 Thu
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
pair<int, int> list[maxn];

int main() {
    int firstNodeAddr, N, K;
    cin >> firstNodeAddr >> N >> K;
    for (int i = 0; i < N; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        list[addr] = {data, next};
    }

    vector<pair<int, int>> vec[3];

    int pos = firstNodeAddr;
    while (pos != -1) {
        int val = list[pos].first;
        if (val < 0) {
            vec[0].push_back({pos, val});
        } else if (val <= K) {
            vec[1].push_back({pos, val});
        } else {
            vec[2].push_back({pos, val});
        }
        pos = list[pos].second; // next
    }

    bool isFirst = true;

    for (int i = 0; i < 3; i++) {
        for (auto it = vec[i].begin(); it != vec[i].end(); it++) {
            if (isFirst) {
                isFirst = false;
                printf("%05d %d", (*it).first, (*it).second);
            } else {
                printf(" %05d\n%05d %d", (*it).first, (*it).first, (*it).second);
            }
        }
    }

    printf(" -1\n");
    return 0;
}
