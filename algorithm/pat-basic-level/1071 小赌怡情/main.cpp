// 260305 08:57 Thu
// 260305 09:06 Thu
#include <iostream>
using namespace std;

int main() {
    int T, K;
    cin >> T >> K;
    while (K--) {
        int n1, b, t, n2;
        cin >> n1 >> b >> t >> n2;
        if (T < t) {
            cout << "Not enough tokens.  Total = " << T << "." << endl;
            continue;
        }
        if (b == 0 && n2 < n1 || b == 1 && n2 > n1) { // 赢
            T += t;
            cout << "Win " << t << "!  Total = " << T << "." << endl;
        } else { // 输
            T -= t;
            cout << "Lose " << t << ".  Total = " << T << "." << endl;
            if (T == 0) {
                cout << "Game Over." << endl;
                break;
            }
        }
    }
    return 0;
}
