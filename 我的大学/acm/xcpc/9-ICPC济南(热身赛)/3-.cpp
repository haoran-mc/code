#include <cstdio>
const int maxn = 4005;

int main() {
    int n;
    scanf("%d", &n);
    int res = 0;
    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
        int A, B;
        scanf("%d %d", &A, &B);
        if (A < avg) {
            if (B < avg) {
                if (B < A) {
                    avg = (double)(avg * i + B) / (double)(i + 1);
                    ++res;
                }
                if (B >= A) {
                    avg = (double)(avg * i + A) / (double)(i + 1);
                    ++res;
                }
            }
            else {
            }
        }
    }
    return 0;
}
