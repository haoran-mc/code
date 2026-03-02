#include <cstdio>
#include <cstdlib>
#include <cstring>
int arr[10] = {6, 3, 8, 2, 5, 1, 7, 4, 9, 0};
int n = 10;
int seek = 5;

struct Info {
    char ch;
    int cnt;
};

typedef struct node {
    Info data;
    struct node* left;
    struct node* right;
} Node;

typedef struct {
    Node* root;
} Tree;

/*二叉搜索树结点的插入*/
void treeInsert(Tree* tree, char ch) {
    Node* node = (Node *)malloc(sizeof(Node));
    node -> data.ch = ch;
    node -> left  = NULL;
    node -> right = NULL;
    if (tree -> root == NULL) {
        tree -> root = node;
        tree -> root -> data.cnt = 1;
    }
    else {
        Node* temp = tree -> root;
        while (temp != NULL) {
            if (ch == temp -> data.ch) {
                temp -> data.cnt++;
                return ;
            }
            else if (ch < temp -> data.ch) {
                if (temp -> left == NULL) {
                    temp -> left = node;
                    temp -> left -> data.cnt = 1;
                    return ;
                }
                else
                    temp = temp -> left;
            }
            else if (ch > temp -> data.ch) {
                if (temp -> right == NULL) {
                    temp -> right = node;
                    temp -> right -> data.cnt = 1;
                    return ;
                }
                else
                    temp = temp -> right;
            }
        }
    }
}

/*先序遍历*/
void preorder(Node* node) {
    if (node != NULL) {
        printf("%c %d\n", node -> data.ch, node -> data.cnt);
        preorder(node -> left );
        preorder(node -> right);
    }
}

int main() {
    char str[100] = "The last ship sailed towards the distant horizon";
    Tree tree;
    tree.root = NULL;
    for (int i = 0; i < (int)strlen(str); i++)
        treeInsert(&tree, str[i]);
    preorder(tree.root);
    return 0;
}
