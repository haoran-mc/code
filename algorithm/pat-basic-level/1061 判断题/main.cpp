// 260302 14:03 Mon
#include <iostream>

using namespace std;
const int maxn = 105;
int score[maxn];
int ans[maxn];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> score[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> ans[i];
    }
    for (int i = 0; i < N; i++) {
        int res_score = 0;
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            if (a == ans[j]) {
                res_score += score[j];
            }
        }
        cout << res_score << endl;
    }
    return 0;
}
