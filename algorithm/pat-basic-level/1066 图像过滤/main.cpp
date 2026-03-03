// 260303 09:03 Tue
#include <iostream>
using namespace std;

int main() {
    int N, M, A, B, x;
    cin >> N >> M >> A >> B >> x;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            if (j != 0)
                printf(" ");
            if (a >= A && a <= B) {
                printf("%03d", x);
            } else {
                printf("%03d", a);
            }
        }
        printf("\n");
    }
    return 0;
}
