#include <cstdio>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define bug printf("<------>\n");
int arr[35];

bool DFS(int idx, int sum, int n, int k, unordered_set<ll> &unst) {
    unst.insert(sum);
    if (sum == k)
        return true;
    //if (sum > k)
        //return false;
    if (idx >= n)
        return false;
    if (DFS(idx+1, sum+arr[idx], n, k, unst))
        return true;
    if (DFS(idx+1, sum, n, k, unst))
        return true;
    return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    if (k == 0) {
        unordered_set<ll> unst;
        for (int i = 0; i < n; ++i)
            unst.insert(arr[i]);
        for (auto it = unst.begin(); it != unst.end(); ++it)
            if (unst.find(-*it) != unst.end()) {
                printf("Yes\n");
                return 0;
            }
        printf("No\n");
    }
    else if (n <= 15) {
        unordered_set<ll> unst;
        DFS(0, 0, n, k, unst) ? printf("Yes\n") : printf("No\n");
    }
    else {
        unordered_set<ll> unst1;
        unordered_set<ll> unst2;
        if (DFS(0, 0, 15, k, unst1)) {
            printf("Yes\n");
            return 0;
        }
        else if (DFS(15, 0, n, k, unst2)) {
            printf("Yes\n");
            return 0;
        }
        else {
            for (auto it = unst1.begin(); it != unst1.end(); ++it)
                if (unst2.find(k - *it) != unst2.end()) {
                    printf("Yes\n");
                    return 0;
                }
            printf("No\n");
        }
    }
    return 0;
}
