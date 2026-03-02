// 没有通过测试，考虑复杂了，不需要输出 node[i].prev，每次把当前 node 的地址输出两遍就行，"%d\n%d"

#include <cstdio>
const int maxn = 1e6 + 5;

struct {
    int value;
    int prev;
    int next;
} node[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int start_node, n, k;
    scanf("%d %d %d", &start_node, &n, &k);

    for (int i = 0; i < n; i++) {
        int addr, v, next;
        scanf("%d %d %d", &addr, &v, &next);
        node[addr].value = v;
        node[addr].next = next;
    }

    // 赋值 node[i].prev
    int last_addr = start_node;
    int curr_addr = start_node;
    while (true) {
        if (curr_addr == -1) {
            break;
        }
        node[curr_addr].prev = last_addr;
        last_addr = curr_addr;
        curr_addr = node[curr_addr].next;
    }

    // 两个指针，快指针、慢指针
    // 让 fast 先走 k-1 步，然后输出从 fast 到 slow 的 k 个
    int fast_p = start_node;
    int slow_p = start_node;
    while (true) {
        int step = 1;
        while (true) {
            if (fast_p == -1 || step == k) {
                break;
            }
            fast_p = node[fast_p].next;
            step++;
        }

        int curr_p = fast_p;
        if (step == k) { // 够 k 个
            // 从 fast_p 打印到 slow_p
            for (int i = 0; i < k; i++) {
                if (i == k - 1 && node[fast_p].next != -1) {
                    printf("%05d %d %05d\n", curr_p, node[curr_p].value, node[fast_p].next);
                } else if (i == k - 1 && node[fast_p].next == -1) {
                    printf("%05d %d -1\n", curr_p, node[curr_p].value);
                } else {
                    printf("%05d %d %05d\n", curr_p, node[curr_p].value, node[curr_p].prev);
                }
                curr_p = node[curr_p].prev;
            }
            if (node[fast_p].next == -1) {
                break;
            }
        } else { // 不够 k 个
            while (true) {
                if (node[slow_p].next == -1) {
                    printf("%05d %d -1\n", slow_p, node[slow_p].value);
                    break;
                }
                printf("%05d %d %05d\n", slow_p, node[slow_p].value, node[slow_p].next);
                slow_p = node[slow_p].next;
            }
            break;
        }

        slow_p = fast_p = node[fast_p].next;
    }

    return 0;
}
