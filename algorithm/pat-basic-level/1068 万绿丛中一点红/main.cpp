// 260303 14:03 Tue
// 260303 17:03 Tue
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1005;
int arr[maxn][maxn];
map<int, int> mp;

int main() {
    int N, M, tol;
    cin >> M >> N >> tol;
    for (int i = 0; i <= N + 1; i++)
        memset(arr[i], 0x3f, sizeof(arr[i]));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            mp[arr[i][j]]++;
        }

    int resi = -1, resj = -1;
    int found = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (mp[arr[i][j]] > 1)
                continue;

            int f = 0;
            if (abs(arr[i][j] - arr[i - 1][j - 1]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i - 1][j]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i - 1][j + 1]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i][j - 1]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i][j + 1]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i + 1][j - 1]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i + 1][j]) > tol)
                f++;
            if (abs(arr[i][j] - arr[i + 1][j + 1]) > tol)
                f++;

            if (f == 8 && resi == -1 && resj == -1) {
                resi = i, resj = j;
                found = 1;
                continue;
            }
            if (f == 8 && found == 1) {
                found = 2;
                break;
            }
        }

    if (found == 0) {
        cout << "Not Exist" << endl;
    } else if (found == 1) {
        printf("(%d, %d): %d\n", resj, resi, arr[resi][resj]);
    } else if (found == 2) {
        cout << "Not Unique" << endl;
    }

    return 0;
}
