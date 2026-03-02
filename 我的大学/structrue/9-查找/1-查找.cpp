#include <cstdio>
#include <cstdlib>
int arr[10] = {6, 3, 8, 2, 5, 1, 7, 4, 9, 0};
int n = 10;
int seek = 5;
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;
typedef struct {
    Node* root;
} Tree;

/*冒泡排序*/
void bubbleSort() {
    for (int i = 0; i < n-1; ++i)
        for (int j = n-1; j > i; --j)
            if (arr[j] < arr[j-1]) {
                arr[j] += arr[j-1];
                arr[j-1] = arr[j] - arr[j-1];
                arr[j] -= arr[j-1];
            }
}

/*折半查找*/
int binSearch(int left, int right) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == seek)
            return mid;
        else {
            if (arr[mid] > seek)
                right = mid - 1;
            else
                left  = mid + 1;
        }
    }
    return -1;
}

/*二叉搜索树结点的插入*/
void treeInsert(Tree* tree, int val) {
    Node* node = (Node *)malloc(sizeof(Node));
    node -> data  = val;
    node -> left  = NULL;
    node -> right = NULL;
    if (tree -> root == NULL)
        tree -> root = node;
    else {
        Node* temp = tree -> root;
        while (temp != NULL) {
            if (val < temp -> data) {
                if (temp -> left == NULL) {
                    temp -> left = node;
                    return ;
                }
                else
                    temp = temp -> left;
            }
            else {
                if (temp -> right == NULL) {
                    temp -> right = node;
                    return ;
                }
                else
                    temp = temp -> right;
            }
        }
    }
}

/*二叉搜索树的查找*/
void treeSearch(Node* root) {
    if (root == NULL) {
        printf("search failed\n");
        return ;
    }
    if (seek == root -> data)
        printf("I can find it!\n");
    else if (seek < root -> data)
        treeSearch(root -> left);
    else
        treeSearch(root -> right);
}

int main() {
    /*顺序查找*/
    for (int i = 0; i < n; ++i)
        if (arr[i] == seek)
            printf("I can find it!\n");

    bubbleSort();
    int pos = binSearch(0, n);
    if (pos == -1)
        printf("I cannot find it!\n");
    else
        printf("I find it at the position: %d\n", pos + 1);

    int num[10] = {6, 3, 8, 2, 5, 1, 7, 4, 9, 0};
    Tree tree;
    tree.root = NULL;
    for (int i = 0; i < 10; i++)
        treeInsert(&tree, num[i]);
    treeSearch(tree.root);
    return 0;
}
