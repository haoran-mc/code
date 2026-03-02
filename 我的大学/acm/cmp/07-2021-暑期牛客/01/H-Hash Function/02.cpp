/*
https://ac.nowcoder.com/acm/contest/11166/H
Hash Function

题目大意
给定 n 个互不相同的数，找一个最小的模域，使得它们在这个模域下互不相同。n 500000。
考察内容
简单数论，卷积
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 5;
int n, a[maxn];
int maxi = 0;
bool used[maxn];

int solve() {
    // 结果一定不能小于等于n，也一定不会大于等于maxi
    for (int i = n; i <= maxi+1; ++ i) {
        bool flag = true;
        for (int j = 0; j < i; ++ j) {
            int k = 0;
            int cnt = 0;
            while (i*k+j <= maxi+1) {
                if (used[i*k+j])
                    cnt ++;
                k ++;
                if (cnt >= 2) {
                    flag = false;
                    break;
                }
            }
            if (cnt >= 2) {
                flag = false;
                break;
            }
        }
        if (flag) 
            return i;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
        maxi = max(a[i], maxi);
        used[a[i]] = true;
    }
    int res = solve();
    printf("%d\n", res);
    return 0;
}
