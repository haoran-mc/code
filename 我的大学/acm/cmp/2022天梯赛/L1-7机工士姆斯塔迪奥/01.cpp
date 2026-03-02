#include <cstdio>
#include <unordered_set>
using namespace std;

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    unordered_set<int> col, row;
    while (q -- ) {
        int t, c;
        scanf("%d %d", &t, &c);
        if (t == 0)
            row.insert(c);
        else
            col.insert(c);
    }
    printf("%d\n", n * m - row.size() * m - col.size() * n + row.size() * col.size());
    return 0;
}