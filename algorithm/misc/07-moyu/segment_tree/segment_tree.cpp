//线段树

#include<iostream>
using namespace std;

#define MAX_LEN 1000    //线段树的最大存储空间

void build_tree(int arr[], int tree[], int node, int start, int end) {
//线段数越往上的结点，所包含的范围越大，第一个结点是原数组所有元素总和
//当到达线段树末尾时，包含数组元素最少，仅有一个
//只有一种情况下可以直接赋值：当 start == end 时，也就是到达线段树末端
//此处是一个数组元素的和，也就是他自己，赋值 tree[node] == arr[start]
    if(start == end) {
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
//一种情况可以赋值，当使用 mid 不断寻找找到线段树末端，更改此处的值
//其他情况皆用递归
    if(start == end) {
        arr[idx] = val;
        tree[node] = val;
    }
    else {
        int mid = (start + end) / 2;
        int left_node  = 2 * node + 1;
        int right_node = 2 * node + 2;

        if(idx <= mid) {
            update_tree(arr, tree, left_node, start, mid, idx, val);
        }
        else {
            update_tree(arr, tree, right_node, mid+1, end, idx, val);
        }

        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R) {
//同样使用 mid ，一次递归便更新 start 或 end ，与目标范围（L，R）比较
//1. 当 start 与 end 的范围完全在目标范围中，直接返回 tree[node]
//2. 当
    cout<<"start = "<<start<<endl;
    cout<<"end   = "<<end<<endl<<endl;

    if(R < start || L > end) {
        return 0;
    }
    else if(L <= start && R >= end) {
        return tree[node];
    }
    else if(start == end) {
        return tree[node];
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
    int arr[] = {1, 3, 5, 7, 9, 11};
    int tree[MAX_LEN] = {0};
    int size = 6;

    build_tree(arr, tree, 0, 0, size-1);
    for(int i=0; i <= 2*size+2; i++) {
        cout<<"tree["<<i<<"] = "<<tree[i]<<endl;
    }

    cout<<endl;
    update_tree(arr, tree, 0, 0, size-1, 4, 6);
    for(int i=0; i <= 2*size+2; i++) {
        cout<<"tree["<<i<<"] = "<<tree[i]<<endl;
    }

    cout<<endl;
    int s = query_tree(arr, tree, 0, 0, size-1, 2, 5);
    cout<<s<<endl;

    return 0;
}