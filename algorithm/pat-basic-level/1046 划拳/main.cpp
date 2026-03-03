#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0;
    while (n--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int res = a1 + b1;
        if ((a2 == res && b2 == res) || (a2 != res && b2 != res)) {
            continue;
        }
        if (a2 == res) {
            b++;
        }
        if (b2 == res) {
            a++;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
