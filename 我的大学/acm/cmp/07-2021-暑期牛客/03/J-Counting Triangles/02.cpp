#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define NEXTLINE cout << "\n";

bool edge[8005][8005];
int sumi[8005][8005], sumj[8005][8005];

int main() {
    int n = 5;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            edge[j][i] = edge[i][j] = 1;
            /**
             * sumi[i][j]代表的是在i这一行，在j列之前有多少黑色格子
             * sumj[i][j]代表的是在j这一列，在i行之前有多少黑色格子
             */
            sumi[i][j] = sumi[i][j-1] + edge[i][j];
            sumj[i][j] = sumj[i-1][j] + edge[i][j];
        }

    int cnt = 0;
    for (int b = 1; b < n; ++b) {
        for (int c = b + 1; c < n; ++c) {
            if (edge[b][c]) {   // 如果这里是黑色的
                if (sumj[b][c] <= 1)  // 说明这一列在i行之前只有它这一块黑色格子，那么不可能有edge[a][c]是黑色的
                    continue;
                else {  // 说明这一列之前还有黑色格子，那就有机会
                    for (int i = 0; i < b; ++i) {
                        if (edge[i][c]) {   // 找到了这块黑色的
                            cnt += (sumi[i][c] - 1);
                            cout << b << " " << c << " " << i << " " << c << " " << sumi[i][c] - 1 << "\n";
                        }
                    }
                }
            }
            else {   // 如果这里是白色的
                if ((b - sumj[b][c] + 1) <= 1)   // 说明这一列在b行之前只有它这一块白色格子，那么不可能有edge[a][c]是白色的
                    continue;
                else {
                    for (int i = 0; i < b; ++i) {
                        if (!edge[i][c]) {
                            cnt += (c - b + 1 - sumi[i][c]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << edge[i][j] << " ";
        NEXTLINE
    }
    NEXTLINE
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << sumi[i][j] << " ";
            NEXTLINE
        }
    NEXTLINE
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << sumj[i][j] << " ";
            NEXTLINE
        }
    /*
     * int cnt = 0;
     * for (int a = 0; a < n; ++a)
     *     for (int b = a + 1; b < n; ++b)
     *         for (int c = b + 1; c < n; ++c)
     *             if (edge[a][b] == edge[a][c] && edge[a][b] == edge[b][c])
     *                 ++cnt;
     */
    cout << cnt << "\n";
    return 0;
}
