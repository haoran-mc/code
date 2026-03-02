#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-6;

int dcmp(double x, double y) { // 比较两个浮点数：0 相等；-1 小于；1 大于
    if (fabs(x - y) < eps)
        return 0;
    else
        return x < y ? -1 : 1;
}

int main() {
    int N;
    double e;
    int D;
    cin >> N >> e >> D;

    int mayEmptyCnt = 0, emptyCnt = 0;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        int lowCnt = 0;
        for (int j = 0; j < K; j++) {
            double ei;
            cin >> ei;
            if (dcmp(ei, e) < 0) {
                lowCnt++;
            }
        }
        if (lowCnt > K / 2) {
            if (K > D) {
                emptyCnt++;
            } else {
                mayEmptyCnt++;
            }
        }
    }
    printf("%.1lf%% %.1lf%%\n", (double)mayEmptyCnt / N * 100, (double)emptyCnt / N * 100);
    return 0;
}
