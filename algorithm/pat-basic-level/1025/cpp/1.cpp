#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 5;

struct Node {
    int v;
    int next;
} node[maxn];

struct List {
    int addr;
    int v;
} list[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int start_node, n, k;
    scanf("%d %d %d", &start_node, &n, &k);
    for (int i = 0; i < n; i++) {
        int addr, v, next;
        scanf("%d %d %d", &addr, &v, &next);
        node[addr].v = v;
        node[addr].next = next;
    }

    bool first = true;

    int p = start_node;
    while (true) {
        int idx = 0, step;
        for (step = 0; step < k; step++) {
            if (p == -1) {
                break;
            }
            list[idx].addr = p;
            list[idx].v = node[p].v;
            idx++;
            p = node[p].next;
        }

        if (step == k) { // 足够 k 个
            reverse(list, list + k);
            for (int i = 0; i < k; i++) {
                if (first) {
                    printf("%05d %d ", list[i].addr, list[i].v);
                    first = false;
                } else {
                    printf("%05d\n%05d %d ", list[i].addr, list[i].addr, list[i].v);
                }
            }
            if (p == -1) {
                break;
            }
        } else { // 不足 k 个
            for (int i = 0; i < idx; i++) {
                if (first) {
                    printf("%05d %d ", list[i].addr, list[i].v);
                    first = false;
                } else {
                    printf("%05d\n%05d %d ", list[i].addr, list[i].addr, list[i].v);
                }
            }
            break;
        }
    }
    printf("-1\n");
    return 0;
}
