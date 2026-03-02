#include <iostream>
using namespace std;
#define maxn 50
int nums[maxn][maxn];
bool flag[maxn][maxn];
void reserve(int n){
    int i = 0, j = 0;
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    int turn = 0;
    for (int m = 1; m <= n * n; m++) {
        if (i >= n || j >= n || i < 0 || j < 0 || flag[i][j] == true) {
            i -= x[turn], j -= y[turn];
            if (turn == 3)
            turn = -1;
            turn += 1;
            m--;
        }
        nums[i][j] = m;
        flag[i][j] = true;
        i += x[turn], j = j + y[turn];
    }
}
int main()
{
    int n[maxn], k = 0;
    do {
        scanf("%d", &n[k]);
    } while (n[k++] != 0);
    for (k = 0; n[k] != 0; k++) {
        if (!n[k])
            break;
        reserve(n[k]);
        for (int i = 0; i < n[k]; i++) {
            for (int j = 0; j < n[k]; j++) {
                flag[i][j] = false;
                if (n[k] < 10)
                    printf("%2d", nums[i][j]);
                else if (n[k] < 32)
                    printf("%3d", nums[i][j]);
                else
                    printf("%4d", nums[i][j]);
                if (j != n[k] - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
