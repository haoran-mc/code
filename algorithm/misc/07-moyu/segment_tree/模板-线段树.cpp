#include <cstdio>
const int maxn = 1e3 + 5;
int arr[] = {1, 3, 5, 7, 9, 11};
int tree[maxn] = {0};
int n = 6;

void bulid_tree(int node, int start, int end) {
    if (start == end)
        tree[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;
        bulid_tree(left_node,  start, mid);
        bulid_tree(right_node, mid+1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    }
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx >= start && idx <= mid)
            update_tree(left_node, start, mid, idx, val);
        else
            update_tree(right_node, mid+1, end, idx, val);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query_tree(int node, int start, int end, int L, int R) {
    printf("start = %d\n", start);
    printf("end   = %d\n", end);
    printf("\n");

    if (R < start || L > end)
        return 0;
    else if (L <= start && end <= R)
        return tree[node];
    else if (start == end)
        return tree[node];
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left  = query_tree(left_node,  start, mid, L, R);
        int sum_right = query_tree(right_node, mid+1, end, L, R);
        return sum_left + sum_right;
    }
}

void output() {
    for (int i = 0; i < 2*n+2; ++i)
        printf("tree[%d] = %d\n", i, tree[i]);
    printf("\n");
}

int main() {
    bulid_tree(0, 0, n-1);
    output();

    update_tree(0, 0, n-1, 4, 6);
    output();

    int res = query_tree(0, 0, n-1, 2, 5);
    printf("res = %d\n", res);
    return 0;
}
