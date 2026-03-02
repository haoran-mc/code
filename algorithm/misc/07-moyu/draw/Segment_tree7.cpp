#include<iostream>
using namespace std;

#define MAX_LEN 1000

void build_tree(int arr[], int tree[], int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    }
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;
        
        build_tree(arr, tree, left_node,  start, mid);
        build_tree(arr, tree, right_node, mid+1, end);

        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        arr[idx] = val;
    }
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;

        if (idx <= mid) {
            update_tree(arr, tree, left_node,  start, mid, idx, val);
        }
        else {
            update_tree(arr, tree, right_node, mid+1, end, idx, val);
        }

        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R) {
    printf("start = %d\n", start);
    printf("end   = %d\n", end);
    printf("\n");

    if (start == end) {
        return tree[node];
    }
    else if (L <= start && end <= R) {
        return tree[node];
    }
    else if (end < L || start > R) {
        return 0;
    }
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;

        int sum_left  = query_tree(arr, tree, left_node,  start, mid, L, R);
        int sum_right = query_tree(arr, tree, right_node, mid+1, end, L, R);

        return sum_left + sum_right;
    }
}

int main()
{
    int tree[MAX_LEN] = {0};
    int size = 6;
    int arr[] = {1, 3, 5, 7, 9, 11};

    build_tree(arr, tree, 0, 0, size-1);
    for (int i = 0; i <= 2*size+2; i++) {
        printf("tree[%d] = %d\n", i, tree[i]);
    }
    
    printf("\n");
    update_tree(arr, tree, 0, 0, size-1, 4, 6);
    for (int i = 0; i <= 2*size+2; i++) {
        printf("tree[%d] = %d\n", i, tree[i]);
    }

    printf("\n");
    int s = query_tree(arr, tree, 0, 0, size-1, 2, 5);
    printf("query( 2, 5 ) = %d\n", s);

    return 0;
}
