// 260306 14:03 Fri
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int f(int a, int b) {
    // a / b 取四舍五入
    double res = double(a) / b;
    int x = (int)(res * 10) % 10;
    if (x <= 4) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    int N, M; // 组数、满分
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int G2;
        cin >> G2;

        vector<int> vec;
        for (int j = 0; j < N - 1; j++) {
            int score;
            cin >> score;
            if (score >= 0 && score <= M)
                vec.push_back(score);
        }
        sort(vec.begin(), vec.end());

        int sum_score = 0;
        for (auto it = vec.begin() + 1; it != vec.end() - 1; it++) {
            sum_score += *it;
            // printf("%d ", *it);
        }
        // int G1 = f(sum_score, vec.size() - 2);
        int G1 = sum_score / (vec.size() - 2);

        printf("%d\n", f(G1 + G2, 2));
    }
    return 0;
}
