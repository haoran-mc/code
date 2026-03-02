#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define NEXTLINE cout << "\n";
namespace GenHelper {
    unsigned z1, z2, z3, z4, b, u;
    unsigned get() {
        b  = ((z1 << 6)^z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18)^b;
        b  = ((z2 << 2)^z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2)^b;
        b  = ((z3 << 13)^z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7)^b;
        b  = ((z4 << 3)^z4)>>12;
        z4 = ((z4 & 4294967168U) << 13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
        while (!u)
            u = get();
        bool res = u & 1;
        u >>= 1;
        return res;
    }
    void srand(int x) {
        z1 = x;
        z2 = (~x)^0x233333333U;
        z3 = x^0x1234598766U;
        z4 = (~x) + 51;
        u = 0;
    }
}

using namespace GenHelper;
bool edge[8005][8005];
int sumi[8005][8005], sumj[8005][8005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, seed;
    cin >> n >> seed;
    srand(seed);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            edge[j][i] = edge[i][j] = read();
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
                if (sumj[c-1][c] - sumj[b][c]) {  // 第c列的总黑色格子
                    cnt += (sumj[c-1][c] - sumj[b][c]) * (sumi[b][c] - 1);
                }
                else
                    continue;
                /*
                 * if (sumj[b][c] <= 1)  // 说明这一列在i行之前只有它这一块黑色格子，那么不可能有edge[a][c]是黑色的
                 *     continue;
                 * else {  // 说明这一列之前还有黑色格子，那就有机会
                 *     for (int i = 0; i < b; ++i) {
                 *         if (edge[i][c]) {   // 找到了这块黑色的
                 *             cnt += (sumi[i][c] - 1);
                 *             cout << b << " " << c << " " << i << " " << c << " " << sumi[i][c] - 1 << "\n";
                 *             NEXTLINE 
                 *         }
                 *     }
                 * }
                 */
            }
            else {   // 如果这里是白色的
                if ((c - sumj[c-1][c]) - (b + 1 - sumj[b][c])) {  // 这一列下面还有多少块白色格子
                    cnt += ((c - sumj[c-1][c]) - (b + 1 - sumj[b][c])) * (c - (b + 1) - sumi[b][c]);
                }
                else
                    continue;
                /*
                 * if ((b - sumj[b][c] + 1) <= 1)   // 说明这一列在b行之前只有它这一块白色格子，那么不可能有edge[a][c]是白色的
                 *     continue;
                 * else {
                 *     for (int i = 0; i < b; ++i) {
                 *         if (!edge[i][c]) {
                 *             cnt += (c - b + 1 - sumi[i][c]);
                 *         }
                 *     }
                 * }
                 */
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
