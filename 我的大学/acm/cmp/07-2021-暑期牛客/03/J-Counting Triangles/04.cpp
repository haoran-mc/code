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

void outInfo(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j)
                cout << "  ";
            else
                cout << edge[i][j] << " ";
        }
        NEXTLINE
    }
    NEXTLINE;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, seed;
    cin >> n >> seed;
    srand(seed);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            edge[j][i] = edge[i][j] = read();

    int cnt = 0;
    for (int a = 0; a < n; ++a)
        for (int b = a + 1; b < n; ++b)
            for (int c = b + 1; c < n; ++c)
                if (edge[a][b] == edge[a][c] && edge[a][b] == edge[b][c]) {
                    // cout << a << " " << b << " " << c << "\n";
                    ++cnt;
                    continue;
                }
    // outInfo(n);
    cout << cnt << "\n";
    return 0;
}
