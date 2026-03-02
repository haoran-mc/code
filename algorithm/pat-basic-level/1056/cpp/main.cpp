#include <iostream>
using namespace std;
const int maxn = 15;
int arr[maxn];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            sum += arr[i] * 10 + arr[j];
            sum += arr[j] * 10 + arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}
