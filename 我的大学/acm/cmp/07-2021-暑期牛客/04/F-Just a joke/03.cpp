#include <cstdio>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
    }
    printf(!((n + m) % 2) ? "Bob\n" : "Alice\n");
    return 0;
}
