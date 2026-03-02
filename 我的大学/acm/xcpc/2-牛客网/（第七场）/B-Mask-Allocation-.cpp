#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> ans;

void dfs(int n, int m) {
    if (m == 0)
        return ;

    for (int i = 0; i < (n / m) * m; i++)
        ans.push_back(m);

    dfs(max((n % m), m), min((n % m), m));
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        ans.clear();
        int n;
        int m;
        scanf("%d%d", &n, &m);

        if (n < m)
            swap(n, m);

        dfs (max(n, m), min(n, m));
        printf("%d\n", ans.size());

        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);

    }
    printf("\n");
    return 0;
}
