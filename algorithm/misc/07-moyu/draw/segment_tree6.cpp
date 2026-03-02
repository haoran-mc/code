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
}

void query_tree(int arr[], int tree[], int node, int start, int end, int L, int R) {

}

int main()
{
        int arr[] = {1, 3, 5, 7, 9, 11};
        int tree[MAX_LEN] = {0};
        int size = 6;


        return 0;
}
